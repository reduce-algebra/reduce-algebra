// stream.h                              Copyright (C) Codemist, 1995-2025
//
// Header defining the structure of stream objects in CSL, and also
// the format for "library" files used with the fast-load mechanism.
//


/**************************************************************************
 * Copyright (C) 2025, Codemist.                         A C Norman       *
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
#define NOT_CHAR1       0x60000000   // used with the fork scheme.

extern int char_to_terminal(int c, LispObject f);
extern int char_to_file(int c, LispObject f);
extern int char_to_pipeout(int c, LispObject f);
extern int char_to_synonym(int c, LispObject f);
extern int char_to_broadcast(int c, LispObject f);
extern int char_to_illegal(int c, LispObject f);
extern int char_to_list(int c, LispObject f);
extern int code_to_list(int c, LispObject f);
extern int char_to_nowhere(int c, LispObject f);
extern int count_character(int c, LispObject f);
extern int binary_outchar(int c, LispObject f);
extern int char_to_function(int c, LispObject f);
extern int char_to_fork(int c, LispObject f);

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
extern int32_t write_action_fork(int32_t c, LispObject f);

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
extern int char_from_fork(LispObject f);

extern int32_t read_action_terminal(int32_t c, LispObject f);
extern int32_t read_action_file(int32_t c, LispObject f);
extern int32_t read_action_pipe(int32_t op, LispObject f);
extern int32_t read_action_output_file(int32_t c, LispObject f);
extern int32_t read_action_synonym(int32_t c, LispObject f);
extern int32_t read_action_concatenated(int32_t c, LispObject f);
extern int32_t read_action_echo(int32_t c, LispObject f);
extern int32_t read_action_twoway(int32_t c, LispObject f);
extern int32_t read_action_illegal(int32_t c, LispObject f);
extern int32_t read_action_list(int32_t c, LispObject f);
extern int32_t read_action_vector(int32_t c, LispObject f);
extern int32_t read_action_fork(int32_t c, LispObject f);

#define MAX_PROMPT_LENGTH 80
extern char memory_print_buffer[MAX_PROMPT_LENGTH];

//
// The following typedef shows the expected layout of a Lisp_STREAM object,
// but it is not used directly because I need to insist that each field is
// exactly CELL wide. Thus when I access things that contain pointers I
// will perform horrible casts. This was at one time essential if I was to
// be able to host this system on certain 64-bit systems.
//
//  typedef struct Lisp_Stream
//  {
//      Header h;                               0
//      LispObject type;                     0  1*CELL  )
//      LispObject write_data;               1  2*CELL  ) Lisp items
//      LispObject read_data;                2  3*CELL  )
//
//      FILE *file;                          3  4*CELL    + read-fd
//      intptr_t extra;                      4  5*CELL    + write-fd
//      character_stream_writer *write_fn;   5  6*CELL
//      other_stream_op *write_other_fn;     6  7*CELL
//      intptr_t line_length;                7  8*CELL    + PID
//      intptr_t byte_pos;                   8  9*CELL
//      intptr_t char_pos;                   8  10*CELL
//      character_stream_reader *read_fn;   10  11*CELL
//      other_stream_op *read_other_fn;     11  12*CELL
//      intptr_t pushed_char;               12  13*CELL
//  } Lisp_STREAM;
//

#define STREAM_SIZE           (14*CELL)

inline LispObject &stream_type(LispObject v)
{   return basic_elt(v, 0);
}
inline LispObject &stream_write_data(LispObject v)
{   return basic_elt(v, 1);
}
inline LispObject &stream_read_data(LispObject v)
{   return basic_elt(v, 2);
}

// All the rest of the components of a stream object are not altered by
// the garbage collector.

inline std::FILE *& stream_file(LispObject v)
{   return (std::FILE *&)basic_elt(v, 3);
}
inline intptr_t& stream_extra(LispObject v)
{   return (intptr_t&)basic_elt(v, 4);
}
inline character_stream_writer *& stream_write_fn(LispObject v)
{   return (character_stream_writer *&)basic_elt(v, 5);
}
inline other_stream_op *& stream_write_other(LispObject v)
{   return (other_stream_op *&)basic_elt(v,6);
}
inline LispObject &stream_line_length(LispObject v)
{   return basic_elt(v, 7);
}
inline LispObject &stream_byte_pos(LispObject v)
{   return basic_elt(v, 8);
}
inline LispObject &stream_char_pos(LispObject v)
{   return basic_elt(v, 9);
}
inline character_stream_reader *& stream_read_fn(LispObject v)
{   return (character_stream_reader *&)basic_elt(v, 10);
}
inline other_stream_op *& stream_read_other(LispObject v)
{   return (other_stream_op *&)basic_elt(v,11);
}
inline LispObject &stream_pushed_char(LispObject v)
{   return basic_elt(v, 12);
}

// Now for forks.cpp I re-use some of the fields with different types.
// Provided setting and reading of the data is done consistently this
// should be OK. The read and write file desctiptors can live in
// stream_read_data and stream_write_data but packed as fixnums, and
// the pid can go in stream_extra.

inline int stream_read_fd(LispObject v)
{   return int_of_fixnum(stream_read_data(v));
}
inline int stream_write_fd(LispObject v)
{   return int_of_fixnum(stream_write_data(v));
}
inline intptr_t& stream_pid(LispObject v)
{   return stream_extra(v);
}
inline void set_stream_read_fd(LispObject v, int fd)
{   stream_read_data(v) = fixnum_of_int(fd);
}
inline void set_stream_write_fd(LispObject v, int fd)
{   stream_write_data(v) = fixnum_of_int(fd);
}

#define STREAM_HEADER (TAG_HDR_IMMED + TYPE_STREAM + (STREAM_SIZE<<(Tw+5)))
#define STREAM_FLAG_PIPE       1

inline bool is_stream(LispObject v)
{   if (is_vector(v)) my_assert(!is_forward(vechdr(v)),
                                "forwarding ptr in stream"); // @@@
    return (is_vector(v) && vechdr(v) == STREAM_HEADER);
}

inline int putc_stream(int c, LispObject f)
{   character_stream_writer *fn = stream_write_fn(f);
#ifdef DEBUG
    //if (c == '\n') pid_printf("\n{\\n:%" PRIxPTR "}", f); // @@@
    //else if (c == '\r') pid_printf("\n{\\r:%" PRIxPTR "}", f); // @@@
    //else if (c == 0x1b) pid_printf("\n{\\e:%" PRIxPTR "}", f); // @@@
    //else pid_printf("\n{%c:%" PRIxPTR "}", c, f); // @@@
#endif
    return (*fn)(c & 0xff, f);
}

inline int getc_stream(LispObject f)
{   character_stream_reader *fn = stream_read_fn(f);
    int c = (*fn)(f);
#ifdef DEBUG
    //if (c == '\n') pid_printf("\n[\\n:%" PRIxPTR "]", f); // @@@
    //else if (c == '\r') pid_printf("\n[\\r:%" PRIxPTR "]", f); // @@@
    //else if (c == 0x1b) pid_printf("\n[\\e:%" PRIxPTR "]", f); // @@@
    //else pid_printf("\n[%c:%" PRIxPTR "]", c, f); // @@@
#endif
    return c;
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
// an operand. Well note I am only using the low 32 bits of a word because
// I developed this on 32-bit machines. The consequence is that linelengths
// had better not go beyond several million.
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
// not need additional data passed. Observe that this means that seeks are
// limited to be within the first 2GBytes of a file - again this is because
// of 32-bit history!
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

// For debugging etc...

inline const char* streamop(uintptr_t x)
{
         if (x==(uintptr_t)char_to_terminal)         return "char_to_terminal";
    else if (x==(uintptr_t)char_to_file)             return "char_to_file";
    else if (x==(uintptr_t)char_to_pipeout)          return "char_to_pipeout";
    else if (x==(uintptr_t)char_to_synonym)          return "char_to_synonym";
    else if (x==(uintptr_t)char_to_broadcast)        return "char_to_broadcast";
    else if (x==(uintptr_t)char_to_illegal)          return "char_to_illegal";
    else if (x==(uintptr_t)char_to_list)             return "char_to_list";
    else if (x==(uintptr_t)code_to_list)             return "code_to_list";
    else if (x==(uintptr_t)char_to_nowhere)          return "char_to_nowhere";
    else if (x==(uintptr_t)char_to_fork)             return "char_to_fork";
    else if (x==(uintptr_t)count_character)          return "count_character";
    else if (x==(uintptr_t)binary_outchar)           return "binary_outchar";
    else if (x==(uintptr_t)char_to_function)         return "char_to_function";
#if defined HAVE_LIBFOX || defined HAVE_LIBWX
    else if (x==(uintptr_t)char_to_math)             return "char_to_math";
    else if (x==(uintptr_t)char_to_spool)            return "char_to_spool";
#endif
    else if (x==(uintptr_t)write_action_terminal)    return "write_action_terminal";
    else if (x==(uintptr_t)write_action_file)        return "write_action_file";
    else if (x==(uintptr_t)write_action_pipe)        return "write_action_pipe";
    else if (x==(uintptr_t)write_action_synonym)     return "write_action_synonym";
    else if (x==(uintptr_t)write_action_broadcast)   return "write_action_broadcast";
//  else if (x==(uintptr_t)write_action_twoway)      return "write_action_twoway";
    else if (x==(uintptr_t)write_action_illegal)     return "write_action_illegal";
    else if (x==(uintptr_t)write_action_list)        return "write_action_list";
    else if (x==(uintptr_t)write_action_fork)        return "write_action_fork";
#if defined HAVE_LIBFOX || defined HAVE_LIBWX
    else if (x==(uintptr_t)write_action_math)        return "write_action_math";
    else if (x==(uintptr_t)write_action_spool)       return "write_action_spool";
#endif
    else if (x==(uintptr_t)char_from_terminal)       return "char_from_terminal";
    else if (x==(uintptr_t)char_from_file)           return "char_from_file";
    else if (x==(uintptr_t)char_from_pipe)           return "char_from_pipe";
    else if (x==(uintptr_t)char_from_synonym)        return "char_from_synonym";
    else if (x==(uintptr_t)char_from_concatenated)   return "char_from_concatenated";
    else if (x==(uintptr_t)char_from_echo)           return "char_from_echo";
    else if (x==(uintptr_t)char_from_illegal)        return "char_from_illegal";
    else if (x==(uintptr_t)char_from_list)           return "char_from_list";
    else if (x==(uintptr_t)char_from_vector)         return "char_from_vector";
    else if (x==(uintptr_t)char_from_fork)           return "char_from_fork";
    else if (x==(uintptr_t)read_action_terminal)     return "read_action_terminal";
    else if (x==(uintptr_t)read_action_file)         return "read_action_file";
    else if (x==(uintptr_t)read_action_output_file)  return "read_action_output_file";
    else if (x==(uintptr_t)read_action_synonym)      return "read_action_synonym";
    else if (x==(uintptr_t)read_action_concatenated) return "read_action_concatenated";
//  else if (x==(uintptr_t)read_action_echo)         return "read_action_echo";
//  else if (x==(uintptr_t)read_action_twoway)       return "read_action_twoway";
    else if (x==(uintptr_t)read_action_illegal)      return "read_action_illegal";
    else if (x==(uintptr_t)read_action_list)         return "read_action_list";
    else if (x==(uintptr_t)read_action_vector)       return "read_action_vector";
    else if (x==(uintptr_t)read_action_fork)         return "read_action_fork";
    else return "unknown";
}

#endif // header_stream_h

// end of stream.h
