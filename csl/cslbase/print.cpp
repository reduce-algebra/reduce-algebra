//  print.cpp                              Copyright (C) 1990-2022 Codemist

//
// Printing, plus some file-related operations.
//

/**************************************************************************
 * Copyright (C) 2022, Codemist.                         A C Norman       *
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

#include "headers.h"

#ifdef SOCKETS
#include "sockhdr.h"
#endif

void debugprint(const char *s, LispObject a)
{   std::printf("%s", s);
    debugprint(a);
}

void debugprint(const char *s)
{   std::printf("%s", s);
    std::fflush(stdout);
}

void debugprint1(LispObject a, int depth)
{   if (depth < 0)
    {   std::printf("...");
    }
    else if (a==nil)
    {   std::printf("nil");
    }
    else if (is_fixnum(a))
    {   std::printf("%" PRId64, (int64_t)int_of_fixnum(a));
    }
    else if (is_cons(a))
    {   const char *sep = "(";
        while (is_cons(a) && depth > 0)
        {   depth--;
            std::printf("%s", sep);
            debugprint1(car(a), depth-1);
            a = cdr(a);
            sep = " ";
        }
        if (a != nil)
        {   if (depth > 0)
            {   std::printf(" . ");
                debugprint1(a, depth-1);
            }
        }
        std::printf(")");
    }
    else if (is_symbol(a))
    {   LispObject pn = qpname(a);
        if (is_string(pn))
        {   unsigned int len = static_cast<unsigned int>(
                length_of_byteheader(vechdr(pn)));
            if (CELL<len && len < 64)
                std::printf("%.*s", static_cast<int>(len-CELL), &celt(pn, 0));
            else std::printf("<symbol with pname hdr %p>",
                                 reinterpret_cast<void *>(
                                     static_cast<Header>(vechdr(pn))));
        }
        else std::printf("<symbol with odd pname>");
    }
    else if (is_vector(a) && type_of_vector(a) == TYPE_SIMPLE_VEC)
    {   size_t len = cells_in_vector(a);
        const char *sep = "[";
        for (size_t i=0; i<len; i++)
        {   std::printf("%s", sep);
            debugprint1(elt(a, i), depth-1);
            sep = " ";
        }
        std::printf("]");
    }
    else
    {   std::printf("@%p@", reinterpret_cast<void *>(a));
    }
}

void debugprint(LispObject a, int depth)
{   std::printf("%p: ", reinterpret_cast<void *>(a));
    debugprint1(a, depth);
    std::printf("\n");
    std::fflush(stdout);
}

// At present CSL is single threaded - at least as regards file IO - and
// using the unlocked versions of putc and getc can be a MAJOR saving.
// I put these macros here not in soem header to try to keep me reminded
// that if threads ever happened I would need to do my own buffering.

#ifdef HAVE_GETC_UNLOCKED
#define GETC(x) getc_unlocked((FILE *)(x))
#else
#ifdef HAVE__GETC_NOLOCK
#define GETC(x) _getc_nolock((FILE *)(x))
#else
#define GETC(x) getc((FILE *)(x))
#endif
#endif

#ifdef HAVE_PUTC_UNLOCKED
#define PUTC(x, y) putc_unlocked((x), (FILE *)(y))
#else
#ifdef HAVE__PUTC_NOLOCK
#define PUTC(x, y) _putc_nolock((x), (FILE *)(y))
#else
#define PUTC(x, y) putc((x), (FILE *)(y))
#endif
#endif

std::FILE *spool_file = nullptr;
char spool_file_name[128];

int32_t terminal_column = 0;

int32_t terminal_line_length = (int32_t)0x80000000;

#define default_terminal_line_length fwin_linelength

// The next line is a clue to the unsafe nature of a Standard C library!
// I want to implement "printf-like" functions of my own, but need to
// process the characters others than via a normal (FILE *) object. So I
// use vsprintf etc to place stuff in a buffer from where I can pass it on.
// however usage such as
//   my_magic_printf("%s", ...)
// can oh so easily generate unbounded amounts of stuff to overflow any
// buffer I have. I allow space for VPRINTF_CHUNK chars so demand
// discipline of myself in all uses...
//
// The 1999 C standard introduced vsnprintf and solves this worry!
#define VPRINTF_CHUNK 2048

void ensure_screen()
{   fwin_ensure_screen();
    if (spool_file != nullptr) std::fflush(spool_file);
}

void term_printf(const char *fmt, ...)
{   std::va_list a;
    char print_temp[VPRINTF_CHUNK], *p;
    int n;
    va_start(a, fmt);
    n = std::vsprintf(print_temp, fmt, a);
    p = print_temp;
    while (n-- > 0) char_to_terminal(*p++, 0);
    va_end(a);
}

void stdout_printf(const char *fmt, ...)
{   std::va_list a;
    char print_temp[VPRINTF_CHUNK], *p;
    int n;
    LispObject stream = qvalue(standard_output);
    if (!is_stream(stream)) stream = qvalue(terminal_io);
    if (!is_stream(stream)) stream = lisp_terminal_io;
    va_start(a, fmt);
    n = std::vsprintf(print_temp, fmt, a);
    p = print_temp;
    while (n-- > 0) putc_stream(*p++, stream);
    va_end(a);
}

void err_printf(const char *fmt, ...)
{   std::va_list a;
    char print_temp[VPRINTF_CHUNK], *p;
    int n;
    LispObject stream = qvalue(error_output);
    if (!is_stream(stream)) stream = qvalue(terminal_io);
    if (!is_stream(stream)) stream = lisp_terminal_io;
    va_start(a, fmt);
    n = std::vsprintf(print_temp, fmt, a);
    p = print_temp;
    while (n-- > 0) putc_stream(*p++, stream);
    va_end(a);
}

void debug_printf(const char *fmt, ...)
{   std::va_list a;
    char print_temp[VPRINTF_CHUNK], *p;
    int n;
    LispObject stream = qvalue(debug_io);
    if (!is_stream(stream)) stream = qvalue(terminal_io);
    if (!is_stream(stream)) stream = lisp_terminal_io;
    va_start(a, fmt);
    n = std::vsprintf(print_temp, fmt, a);
    p = print_temp;
    while (n-- > 0) putc_stream(*p++, stream);
    va_end(a);
}

void trace_printf(const char *fmt, ...)
{   std::va_list a;
    char print_temp[VPRINTF_CHUNK], *p;
    int n;
    LispObject stream = qvalue(trace_output);
    if (!is_stream(stream)) stream = qvalue(terminal_io);
    if (!is_stream(stream)) stream = lisp_terminal_io;
    va_start(a, fmt);
    n = std::vsprintf(print_temp, fmt, a);
    p = print_temp;
    while (n-- > 0) putc_stream(*p++, stream);
    va_end(a);
}

LispObject Ltyo(LispObject env, LispObject a)
{
// Print a character given its character code.  NOTE that in earlier
// versions of CSL this always printed to the standard output regardless
// of what output stream was selected. Such a curious behaviour was
// provided for use when magic characters sent to the standard output had
// odd behaviour (eg caused graphics effects).  Now tyo is a more
// sensible function for use across all systems. To be generous it
// accepts either a character or a numeric code.
    int c;
    LispObject stream = qvalue(standard_output);
    if (a == CHAR_EOF || a == fixnum_of_int(-1)) return onevalue(a);
    else if (is_char(a)) c = static_cast<int>(code_of_char(a));
    else if (is_fixnum(a)) c = static_cast<int>(int_of_fixnum(a));
    else return aerror1("tyo", a);
    THREADID;
    Save save(THREADARG a);
    if (!is_stream(stream)) stream = qvalue(terminal_io);
    if (!is_stream(stream)) stream = lisp_terminal_io;
    putc_stream(c, stream);
    save.restore(a);
    return onevalue(a);
}

int char_to_illegal(int, LispObject f)
{   return aerror1("Attempt to write to an input stream or one that has been closed",
            stream_type(f));
    return 1;
}

int char_from_illegal(LispObject f)
{   return aerror1("Attempt to read from an output stream or one that has been closed",
            stream_type(f));
    return EOF;
}

int32_t write_action_illegal(int32_t op, LispObject f)
{   if (op == WRITE_GET_INFO+WRITE_IS_CONSOLE) return 0;
    if (op != WRITE_CLOSE)
        return aerror1("Illegal operation on stream",
                cons_no_gc(fixnum_of_int(op >> 8), stream_type(f)));
    return 0;
}

int32_t write_action_file(int32_t op, LispObject f)
{   int32_t w;
    switch (op & 0xf0000000)
    {   case WRITE_CLOSE:
            if ((std::FILE *)stream_file(f) == nullptr) op = 0;
            else op = std::fclose(stream_file(f));
            set_stream_write_fn(f, char_to_illegal);
            set_stream_write_other(f, write_action_illegal);
            set_stream_read_fn(f, char_from_illegal);
            set_stream_read_other(f, read_action_illegal);
            set_stream_file(f, nullptr);
            return op;
        case WRITE_FLUSH:
            return std::fflush(stream_file(f));
        case WRITE_SET_LINELENGTH_DEFAULT:
            op = 80;  // drop through
        case WRITE_SET_LINELENGTH:
            w = stream_line_length(f);
            stream_line_length(f) = op & 0x07ffffff;
            return w;
        case WRITE_SET_COLUMN:
            w = stream_char_pos(f);
            stream_char_pos(f) = op & 0x07ffffff;
            return w;
        case WRITE_GET_INFO:
            switch (op & 0xff)
            {   case WRITE_GET_LINE_LENGTH: return stream_line_length(f);
                case WRITE_GET_COLUMN:      return stream_char_pos(f);
                case WRITE_IS_CONSOLE:      return 0;
                default:return 0;
            }
        default:
            return 0;
    }
}

int32_t write_action_pipe(int32_t op, LispObject f)
{   int32_t w;
    if (op < 0) return -1;
    else switch (op & 0xf0000000)
        {   case WRITE_CLOSE:
                my_pclose(stream_file(f));
                set_stream_write_fn(f, char_to_illegal);
                set_stream_write_other(f, write_action_illegal);
                set_stream_file(f, nullptr);
                return 0;
            case WRITE_FLUSH:
                return my_pipe_flush(stream_file(f));
            case WRITE_SET_LINELENGTH_DEFAULT:
                op = 80;  // drop through
            case WRITE_SET_LINELENGTH:
                w = stream_line_length(f);
                stream_line_length(f) = op & 0x07ffffff;
                return w;
            case WRITE_SET_COLUMN:
                w = stream_char_pos(f);
                stream_char_pos(f) = op & 0x07ffffff;
                return w;
            case WRITE_GET_INFO:
                switch (op & 0xff)
                {   case WRITE_GET_LINE_LENGTH: return stream_line_length(f);
                    case WRITE_GET_COLUMN:      return stream_char_pos(f);
                    case WRITE_IS_CONSOLE:      return 0;
                    default:return 0;
                }
            default:
                return 0;
        }
}

int32_t write_action_terminal(int32_t op, LispObject)
{   int32_t w;
    if (op < 0) return -1;
    else switch (op & 0xf0000000)
        {   case WRITE_CLOSE:
                return 0;   // I will never close the terminal stream
            case WRITE_FLUSH:
                ensure_screen();
                return 0;
            case WRITE_SET_LINELENGTH_DEFAULT:
                w = terminal_line_length;
                terminal_line_length = 0x80000000;
                return w;
            case WRITE_SET_LINELENGTH:
                w = terminal_line_length;
                terminal_line_length = op & 0x07ffffff;
                return w;
            case WRITE_SET_COLUMN:
                w = terminal_column;
                terminal_column = op & 0x07ffffff;
                return w;
            case WRITE_GET_INFO:
                switch (op & 0xff)
                {   case WRITE_GET_LINE_LENGTH: w = terminal_line_length;
                        if (w == (int32_t)0x80000000)
                            w = default_terminal_line_length;
                        return w;
                    case WRITE_GET_COLUMN:      return terminal_column;
                    case WRITE_IS_CONSOLE:      return 1;
                    default:return 0;
                }
            default:
                return 0;
        }
}


#if defined HAVE_LIBFOX || defined HAVE_LIBWX

int32_t write_action_math(int32_t op, LispObject)
{   if (op < 0) return -1;
    else switch (op & 0xf0000000)
        {   case WRITE_CLOSE:
                return 0;   // I will never close the math stream
            case WRITE_FLUSH:   // not flushed using the normal protocol
                return 0;
            case WRITE_SET_LINELENGTH_DEFAULT:
                return 0x07ffffff;  // essentially unlimited linelength
            case WRITE_SET_LINELENGTH:
                return 0x07ffffff;
            case WRITE_SET_COLUMN:      // operation not really supported
                return 0;
            case WRITE_GET_INFO:
                switch (op & 0xff)
                {   case WRITE_GET_LINE_LENGTH: return 0x07ffffff;
                    case WRITE_GET_COLUMN:      return 0;
                    case WRITE_IS_CONSOLE:      return 1;
                    default:return 0;
                }
            default:
                return 0;
        }
}

int32_t write_action_spool(int32_t op, LispObject)
{   int32_t w;
    if (op < 0) return -1;
    else switch (op & 0xf0000000)
        {   case WRITE_CLOSE:
                return 0;   // I will never close the spool stream this way
            case WRITE_FLUSH:
                if (spool_file != nullptr) std::fflush(spool_file);
                return 0;
// In many respects this behaves just like terminal output.
            case WRITE_SET_LINELENGTH_DEFAULT:
                w = terminal_line_length;
                terminal_line_length = 0x80000000;
                return w;
            case WRITE_SET_LINELENGTH:
                w = terminal_line_length;
                terminal_line_length = op & 0x07ffffff;
                return w;
            case WRITE_SET_COLUMN:
                w = terminal_column;
                terminal_column = op & 0x07ffffff;
                return w;
            case WRITE_GET_INFO:
                switch (op & 0xff)
                {   case WRITE_GET_LINE_LENGTH: w = terminal_line_length;
                        if (w == (int32_t)0x80000000)
                            w = default_terminal_line_length;
                        return w;
                    case WRITE_GET_COLUMN:      return terminal_column;
                    case WRITE_IS_CONSOLE:      return 1;
                    default:return 0;
                }
            default:
                return 0;
        }
}

#endif

int32_t write_action_list(int32_t op, LispObject f)
{   int32_t w;
    if (op < 0) return -1;
    else switch (op & 0xf0000000)
        {   case WRITE_CLOSE:
                set_stream_write_fn(f, char_to_illegal);
                set_stream_write_other(f, write_action_illegal);
                set_stream_file(f, nullptr);
                return 0;
            case WRITE_FLUSH:
                return 0;
            case WRITE_SET_LINELENGTH_DEFAULT:
            case WRITE_SET_LINELENGTH:
                return 0x03ffffff;
            case WRITE_SET_COLUMN:
                w = stream_char_pos(f);
                stream_char_pos(f) = op & 0x07ffffff;
                return w;
            case WRITE_GET_INFO:
                switch (op & 0xff)
                {   case WRITE_GET_LINE_LENGTH: return 0x03ffffff;
                    case WRITE_GET_COLUMN:      return stream_char_pos(f);
                    case WRITE_IS_CONSOLE:      return 0;
                    default:return 0;
                }
            default:
                return 0;
        }
}

LispObject Lstreamp(LispObject env, LispObject a)
{   return onevalue(Lispify_predicate(is_stream(a)));
}

LispObject Lis_console(LispObject env, LispObject a)
{   int r1, r2;
    if (!is_stream(a)) return onevalue(nil);
    r1 = other_write_action(WRITE_GET_INFO+WRITE_IS_CONSOLE, a);
    r2 = other_read_action(READ_IS_CONSOLE, a);
    return onevalue(Lispify_predicate(r1 || r2));
}

LispObject make_stream_handle()
{   LispObject w = get_basic_vector(TAG_VECTOR, TYPE_STREAM, STREAM_SIZE);
    errexit();
    stream_type(w) = nil;
    stream_write_data(w) = nil;
    stream_read_data(w) = nil;
    set_stream_file(w, 0);
    set_stream_write_fn(w, char_to_illegal);
    set_stream_write_other(w, write_action_illegal);
    stream_line_length(w) = 80;
    stream_byte_pos(w) = 0;
    stream_char_pos(w) = 0;
    set_stream_read_fn(w, char_from_illegal);
    set_stream_read_other(w, read_action_illegal);
    stream_pushed_char(w) = NOT_CHAR;
    stream_spare(w) = 0;  // Not used at present
    return w;
}

LispObject Lmake_broadcast_stream_4up(LispObject env,
    LispObject a1, LispObject a2, LispObject a3, LispObject a4up)
{   THREADID;
    Save save(THREADARG a1, a2);
    if (a3 != SPID_NOARG) a4up = cons(a3, a4up);
    errexit();
    save.restore(a1, a2);
    if (a2 != SPID_NOARG) a4up = cons(a2, a4up);
    errexit();
    save.restore(a1, a2);
    if (a1 != SPID_NOARG) a4up = cons(a1, a4up);
    errexit();
    Save save1(THREADARG a4up);
    LispObject w = make_stream_handle();
    errexit();
    save1.restore(a4up);
    set_stream_write_fn(w, char_to_broadcast);
    set_stream_write_other(w, write_action_broadcast);
    stream_write_data(w) = a4up;
    return onevalue(w);
}

LispObject Lmake_broadcast_stream_0(LispObject env)
{   return Lmake_broadcast_stream_4up(env, SPID_NOARG, SPID_NOARG, SPID_NOARG, nil);
}

LispObject Lmake_broadcast_stream_1(LispObject env, LispObject a)
{   return Lmake_broadcast_stream_4up(env, a, SPID_NOARG, SPID_NOARG, nil);
}

LispObject Lmake_broadcast_stream_2(LispObject env, LispObject a,
                                    LispObject b)
{   return Lmake_broadcast_stream_4up(env, a, b, SPID_NOARG, nil);
}

LispObject Lmake_broadcast_stream_3(LispObject env, LispObject a,
                                    LispObject b, LispObject c)
{   return Lmake_broadcast_stream_4up(env, a, b, c, nil);
}

LispObject Lmake_concatenated_stream_4up(LispObject env,
    LispObject a1, LispObject a2, LispObject a3, LispObject a4up)
{   THREADID;
    Save save(THREADARG a1, a2);
    if (a3 != SPID_NOARG) a4up = cons(a3, a4up);
    errexit();
    save.restore(a1, a2);
    if (a2 != SPID_NOARG) a4up = cons(a2, a4up);
    errexit();
    save.restore(a1, a2);
    if (a1 != SPID_NOARG) a4up = cons(a1, a4up);
    errexit();
    Save save1(THREADARG a4up);
    LispObject w = make_stream_handle();
    errexit();
    save1.restore(a4up);
    set_stream_read_fn(w, char_from_concatenated);
    set_stream_read_other(w, read_action_concatenated);
    stream_read_data(w) = a4up;
    return onevalue(w);
}

LispObject Lmake_concatenated_stream_0(LispObject env)
{   return Lmake_concatenated_stream_4up(env, SPID_NOARG, SPID_NOARG, SPID_NOARG, nil);
}

LispObject Lmake_concatenated_stream_1(LispObject env, LispObject a)
{   return Lmake_concatenated_stream_4up(env, a, SPID_NOARG, SPID_NOARG, nil);
}

LispObject Lmake_concatenated_stream_2(LispObject env, LispObject a,
                                       LispObject b)
{   return Lmake_concatenated_stream_4up(env, a, b, SPID_NOARG, nil);
}

LispObject Lmake_concatenated_stream_3(LispObject env, LispObject a,
                                       LispObject b, LispObject c)
{   return Lmake_concatenated_stream_4up(env, a, b, c, nil);
}

LispObject Lmake_synonym_stream(LispObject env, LispObject a)
{   LispObject w;
    if (!is_symbol(a)) return aerror1("make-synonym-stream", a);
    THREADID;
    Save save(THREADARG a);
    w = make_stream_handle();
    errexit();
    save.restore(a);
    set_stream_write_fn(w, char_to_synonym);
    set_stream_write_other(w, write_action_synonym);
    stream_write_data(w) = a;
    set_stream_read_fn(w, char_from_synonym);
    set_stream_read_other(w, read_action_synonym);
    stream_read_data(w) = a;
    return onevalue(w);
}

LispObject Lmake_two_way_stream(LispObject env, LispObject a,
                                LispObject b)
{   LispObject w;
    if (!is_symbol(a)) return aerror1("make-two-way-stream", a);
    if (!is_symbol(b)) return aerror1("make-two-way-stream", b);
    THREADID;
    Save save(THREADARG a, b);
    w = make_stream_handle();
    errexit();
    save.restore(a, b);
    set_stream_write_fn(w, char_to_synonym);
    set_stream_write_other(w, write_action_synonym);
    stream_write_data(w) = b;
    set_stream_read_fn(w, char_from_synonym);
    set_stream_read_other(w, read_action_synonym);
    stream_read_data(w) = a;
    return onevalue(w);
}

LispObject Lmake_echo_stream(LispObject env, LispObject a,
                             LispObject b)
{   LispObject w;
    if (!is_symbol(a)) return aerror1("make-echo-stream", a);
    if (!is_symbol(b)) return aerror1("make-echo-stream", b);
    THREADID;
    Save save(THREADARG a, b);
    w = make_stream_handle();
    errexit();
    save.restore(a, b);
    set_stream_write_fn(w, char_to_synonym);
    set_stream_write_other(w, write_action_synonym);
    stream_write_data(w) = b;
    set_stream_read_fn(w, char_from_echo);
    set_stream_read_other(w, read_action_synonym);
    stream_read_data(w) = a;
    return onevalue(w);
}


// string input streams are not implemented yet, but I can read from a
// list so all I would need to do would be to use explodec to turn the
// string into a list of characters and then I have at least all the
// basic mechanisms necessary.

LispObject Lmake_string_input_stream_4up(LispObject env,
    LispObject a1, LispObject a2, LispObject a3, LispObject a4up)
{   return aerror("make-string-input-stream");
}

LispObject Lmake_string_input_stream_0(LispObject env)
{   return Lmake_string_input_stream_4up(env, SPID_NOARG, SPID_NOARG, SPID_NOARG, nil);
}

LispObject Lmake_string_input_stream_1(LispObject env, LispObject a)
{   return Lmake_string_input_stream_4up(env, a, SPID_NOARG, SPID_NOARG, nil);
}

LispObject Lmake_string_input_stream_2(LispObject env, LispObject a,
                                       LispObject b)
{   return Lmake_string_input_stream_4up(env, a, b, SPID_NOARG, nil);
}

LispObject Lmake_string_input_stream_3(LispObject env, LispObject a,
                                       LispObject b, LispObject c)
{   return Lmake_string_input_stream_4up(env, a, b, c, nil);
}

LispObject Lmake_string_output_stream(LispObject env)
{   LispObject w;
    w = make_stream_handle();
    errexit();
    set_stream_write_fn(w, code_to_list);
    set_stream_write_other(w, write_action_list);
    return onevalue(w);
}

LispObject Lget_output_stream_string(LispObject env, LispObject a)
{   LispObject w;
    int32_t n, k;
    if (!is_stream(a)) return aerror1("get-output-stream-string", a);
    w = stream_write_data(a);
    n = stream_byte_pos(a);
    stream_write_data(a) = nil;
    stream_char_pos(a) = stream_byte_pos(a) = 0;
    THREADID;
    Save save(THREADARG w);
    a = get_basic_vector(TAG_VECTOR, TYPE_STRING_4, CELL+n);
    errexit();
    save.restore(w);
    k = (n + 3) & ~(int32_t)7;
    *(int32_t *)(reinterpret_cast<char *>(a) + k + 4 - TAG_VECTOR) = 0;
    if (k != 0) *(int32_t *)(reinterpret_cast<char *>
                                 (a) + k - TAG_VECTOR) = 0;
    while (n > 0)
    {   n--;
// /* The list can now contain big characters that need to re-expand to
// utf-8 form here.
        celt(a, n) = int_of_fixnum(car(w));
        w = cdr(w);
    }
    return a;
}

// (make-function-stream 'fn) makes a stream where output just passes
// characters to the given function.

LispObject Lmake_function_stream(LispObject env, LispObject a)
{   LispObject w;
    if (!is_symbol(a)) return aerror1("make-function-stream", a);
    THREADID;
    Save save(THREADARG a);
    w = make_stream_handle();
    errexit();
    save.restore(a);
    set_stream_write_fn(w, char_to_function);
    set_stream_write_other(w, write_action_list);
    stream_write_data(w) = a;
    return onevalue(w);
}

static int io_kilo = 0;

int char_to_terminal(int c, LispObject)
{   if (++io_kilo >= 1024)
    {   io_kilo = 0;
        io_now++;
    }
    if (c == '\n' || c == '\f') terminal_column = 0;
    else if (c == '\b') terminal_column--;
    else if (c == '\t') terminal_column = (terminal_column + 8) & ~7;
    else if ((c & 0xc0) == 0x80) /* do nothing */;
    else terminal_column++;
    if (spool_file != nullptr)
    {   PUTC(c, spool_file);
#ifdef DEBUG
        std::fflush(spool_file);
#endif
    }
    if (procedural_output != nullptr) return (*procedural_output)(c);
#ifdef WITH_GUI
// "alternative_stdout" is only relevant if there may be a GUI.
    if (alternative_stdout != nullptr)
    {   PUTC(c, alternative_stdout);
        return 0;
    }
#endif // WITH_GUI
    fwin_putchar(c);
    return 0;   // indicate success
}

#if defined HAVE_LIBFOX || defined HAVE_LIBWX

static int math_buffer_size, math_buffer_p;
static char *math_buffer = nullptr;

int char_to_math(int c, LispObject stream)
{   if (++io_kilo >= 1024)
    {   io_kilo = 0;
        io_now++;
    }
    if (math_buffer == nullptr)
    {   math_buffer_size = 500;
// I think that I fail to delete this when the program terminates.
        math_buffer = new (std::nothrow) char[math_buffer_size];
        math_buffer_p = 0;
        if (math_buffer == nullptr) return 1; // failed
    }
    if (math_buffer_p == math_buffer_size-1)
    {   math_buffer_size += 500; // Grow the buffer
        char *bigger = new (std::nothrow) char[math_buffer_size];
        if (bigger == nullptr) return 1;
        std::memcpy(bigger, math_buffer, math_buffer_size-500);
        delete [] math_buffer;
        math_buffer = bigger;
// If I fail to extend the buffer then I will lose some initial part of
// my output. Ugh! But (provided the memory situation improves!) things will
// correct themselves when I next try to display a smaller expression.
    }
    math_buffer[math_buffer_p++] = c;
    math_buffer[math_buffer_p] = 0;
    return 0;
}

int char_to_spool(int c, LispObject stream)
{   if (spool_file == nullptr) return 1;
    if (c == '\n' || c == '\f') terminal_column = 0;
    else if (c == '\t') terminal_column = (terminal_column + 8) & ~7;
    else if ((c & 0xc0) == 0x80) /* do nothing */ ;
    else terminal_column++;
    PUTC(c, spool_file);
    return 0;
}

#endif

// Note that characters come through this interface as a sequence of
// bytes, with ones whose code is over 0x7f sent as a sequence using utf-8.
int char_to_file(int c, LispObject stream)
{   if (++io_kilo >= 1024)
    {   io_kilo = 0;
        io_now++;
    }
    if (c == '\n' || c == '\f')
        stream_char_pos(stream) = stream_byte_pos(stream) = 0;
    else if (c == '\t')
    {   stream_char_pos(stream) = (static_cast<int>(stream_char_pos(
                                       stream)) + 8) & ~7;
        stream_byte_pos(stream)++;
    }
    else if ((c & 0xc0) == 0x80) stream_byte_pos(stream)++;
    else
    {   stream_byte_pos(stream)++;
        stream_char_pos(stream)++;
    }
    PUTC(c, stream_file(stream));
    return 0;   // indicate success
}

int char_to_synonym(int c, LispObject f)
{   f = qvalue(stream_write_data(f));
    if (!is_stream(f)) return 1;
    return putc_stream(c, f);
}

int char_to_function(int c, LispObject f)
{   f = stream_write_data(f);  // name of the function to call
    (*qfn1(f))(qenv(f), pack_char(0, c & 0xff));
    return 0;    // return 0 for success
}

int char_to_broadcast(int c, LispObject f)
{   LispObject l = stream_write_data(f);
    int r = 0;
    THREADID;
    while (consp(l))
    {   f = car(l);
        l = cdr(l);
        if (!is_symbol(f)) continue;
        f = qvalue(f);
        if (!is_stream(f)) continue;
        Save save(THREADARG l);
        r = r | putc_stream(c, f);
        save.restore(l);
    }
    return r;
}

int32_t write_action_synonym(int32_t c, LispObject f)
{   int r;
    LispObject f1 = qvalue(stream_write_data(f));
    if (!is_stream(f1))
        return aerror1("attempt to act on",
                cons_no_gc(fixnum_of_int(c >> 8), f));
    r = other_write_action(c, f1);
    if (c == WRITE_CLOSE)
    {   set_stream_write_fn(f, char_to_illegal);
        set_stream_write_other(f, write_action_illegal);
        set_stream_file(f, nullptr);
    }
    return r;
}

int32_t write_action_broadcast(int32_t c, LispObject f)
{   int r = 0, r1;
    LispObject l = stream_write_data(f), f1;
    THREADID;
    while (consp(l))
    {   f1 = car(l);
        l = cdr(l);
        if (!is_symbol(f1)) continue;
        f1 = qvalue(f1);
        if (!is_stream(f1)) continue;
        Save save(THREADARG l, f);
        r1 = other_write_action(c, f1);
        save.restore(l, f);
        if (r == 0) r = r1;
    }
    if (c == WRITE_CLOSE)
    {   set_stream_write_fn(f, char_to_illegal);
        set_stream_write_other(f, write_action_illegal);
        set_stream_file(f, nullptr);
    }
    return r;
}

int char_to_pipeout(int c, LispObject stream)
{   if (++io_kilo >= 1024)
    {   io_kilo = 0;
        io_now++;
    }
    if (c == '\n' || c == '\f')
        stream_byte_pos(stream) = stream_char_pos(stream) = 0;
    else if (c == '\t')
    {   stream_byte_pos(stream)++;
        stream_char_pos(stream) = (static_cast<int>(stream_char_pos(
                                       stream)) + 8) & ~7;
    }
    else if ((c & 0xc0) == 0x80) stream_byte_pos(stream)++;
    else
    {   stream_byte_pos(stream)++;
        stream_char_pos(stream)++;
    }
    my_pipe_putc(c, stream_file(stream));
    return 0;   // indicate success
}

int char_from_pipe(LispObject stream)
{   int ch = stream_pushed_char(stream);
    if (ch == NOT_CHAR)
    {   if (++io_kilo >= 1024)
        {   io_kilo = 0;
            io_now++;
        }
        ch = GETC(stream_file(stream));
        if (ch == EOF
            //    || ch == CTRL_D
           ) return EOF;
    }
    else stream_pushed_char(stream) = NOT_CHAR;
    return ch;
}

int32_t read_action_pipe(int32_t op, LispObject f)
{   if (op < -1) return 1;
    else if (op <= 0xffff) return (stream_pushed_char(f) = op);
    else switch (op)
        {   case READ_CLOSE:
                if ((std::FILE *)stream_file(f) == nullptr) op = 0;
                else my_pclose(stream_file(f));
                set_stream_read_fn(f, char_from_illegal);
                set_stream_read_other(f, read_action_illegal);
                set_stream_file(f, nullptr);
                return 0;
            case READ_FLUSH:
                stream_pushed_char(f) = NOT_CHAR;
                return 0;
            case READ_TELL:
                return -1;
            case READ_IS_CONSOLE:
                return 0;
            default:
                return 0;
        }
}

const char *get_string_data(LispObject name, const char *why,
                            size_t &len)
{   Header h;
#ifdef COMMON
    if (complex_stringp(name))
    {   name = simplify_string(name);
        if (exceptionPending()) return nullptr;
        h = vechdr(name);
    }
    else
#endif
        if (symbolp(name))
        {   name = get_pname(name);
            h = vechdr(name);
        }
        else if (!is_vector(name))
            return reinterpret_cast<const char *>(aerror1(why, name));
        else if (!is_string_header(h = vechdr(name)))
            return reinterpret_cast<const char *>(aerror1(why, name));
    len = length_of_byteheader(h) - CELL;
    return reinterpret_cast<const char *>(&celt(name, 0));
}

static LispObject Lfiledate(LispObject env, LispObject name)
{   char filename[LONGEST_LEGAL_FILENAME], tt[32];
    size_t len = 0;
    const char *w;
    std::memset(filename, 0, sizeof(filename));
    w = get_string_data(name, "filep", len);
    if (len >= sizeof(filename)) len = sizeof(filename);
    if (!file_exists(filename, w,
                     static_cast<size_t>(len), tt)) return onevalue(nil);
    tt[24] = 0;
    return onevalue(make_string(tt));
}

static LispObject Lfilep(LispObject env, LispObject name)
{   name = Lfiledate(env, name);
    if (name != nil) name = lisp_true;
    return onevalue(name);
}

LispObject Ltmpnam1(LispObject env, LispObject extn)
// Returns a string that is suitable for use as the name of a temporary
// file and that has the given extension. Note that this is generally NOT
// a fully secure thing to use, since after tmpnam() has generated the
// name but before you get around to doing anything with the file
// somebody else may do something that interferes.
{   const char *suffix;
    const char *suffix1;
    size_t suffixlen = 0;
    LispObject r;
    suffix = get_string_data(extn, "tmpnam", suffixlen);
    suffix1 = CSLtmpnam(suffix, suffixlen);
    if (suffix1 == nullptr) return onevalue(nil);
    r = make_string(suffix1);
    return onevalue(r);
}

LispObject Ltmpnam(LispObject env)
// Returns a string that is suitable for use as the name of a temporary
// file. Note that this is generally NOT a comfortable thing to use,
// since after tmpnam() has generated the name but before you get around
// to doing anything with the file somebody else may do something that
// interferes. As a result some C compilers issue a warning when they
// see use of tmpnam() at all...  Here the potential security issues are
// just left for the user to think about! Well because the messages from
// the GNU linker have been causing grief to some users, and because in their
// arrogance the developers of that linker do not provide a way to switch
// the messages off, and furher because I have legacy needs where the
// risks associated with race conditions and really not a worry, I implement
// my own approximation to tmpnam. My version may well be even less
// respectable than the standard one, but using it avoids linker messages
// that are clearly intended to be useful but which are in fact a nuisance.
{   return onevalue(make_string(CSLtmpnam("tmp", 3)));
}

LispObject Ltmpdir(LispObject env)
// Returns a string that is suitable for use as the name of a directory
// to hold temporary files. Does not have a trailing "/", so will be
// "/tmp" on Unix and something like "c:\xxx\yyy" on Windows. On Cygwin
// it is in "mixed" mode, so the dircetory is indicated with "x:" but "/"
// rather than "\" is used as the path separator.
{   return onevalue(make_string(CSLtmpdir()));
}

#ifdef DEBUG
std::FILE *myopen(const char *f, const char *m)
{   std::FILE *s = std::fopen(f, m);
    trace_printf("fopen(%s, %s) = %p\n", f, m, s);
    return s;
}
#define fopen(a, b) myopen(a, b)
#endif

// The Common Lisp keywords for OPEN are a horrid mess. I arrange to decode
// the syntax of the keywords in a Lisp-coded wrapper function, and in that
// code I will also fill in default values for any that needs same. I then
// pack all the information into a single integer, which has several
// sub-fields
//
// x x xx xxx 00   direction PROBE
// x x xx xxx 01             INPUT
// x x xx xxx 10             OUTPUT
// x x xx xxx 11             IO
//
// x x xx 000 xx   if-exists NIL
// x x xx 001 xx             overwrite
// x x xx 010 xx             append
// x x xx 011 xx             rename
// x x xx 100 xx             error
// x x xx 101 xx             (new-version)
// x x xx 110 xx             (supersede)
// x x xx 111 xx             (rename-and-delete)
//
// x x 00 xxx xx   if-does-not-exist NIL
// x x 01 xxx xx                     create
// x x 10 xxx xx                     error
//
// x 0 xx xxx xx   regular text file
// x 1 xx xxx xx   open for binary access
//
// 0 x xx xxx xx   regular file
// 1 x xx xxx xx   open as a pipe

#define DIRECTION_MASK               0x3
#define DIRECTION_PROBE              0x0
#define DIRECTION_INPUT              0x1
#define DIRECTION_OUTPUT             0x2
#define DIRECTION_IO                 0x3
#define IF_EXISTS_MASK               0x1c
#define IF_EXISTS_NIL                0x00
#define IF_EXISTS_OVERWRITE          0x04
#define IF_EXISTS_APPEND             0x08
#define IF_EXISTS_RENAME             0x0c
#define IF_EXISTS_ERROR              0x10
#define IF_EXISTS_NEW_VERSION        0x14
#define IF_EXISTS_SUPERSEDE          0x18
#define IF_EXISTS_RENAME_AND_DELETE  0x1c
#define IF_MISSING_MASK              0x60
#define IF_MISSING_NIL               0x00
#define IF_MISSING_CREATE            0x20
#define IF_MISSING_ERROR             0x40
#define OPEN_BINARY                  0x80
#define OPEN_PIPE                    0x100

LispObject Lopen(LispObject env, LispObject name, LispObject dir)
{   std::FILE *file;
    LispObject r;
    char filename[LONGEST_LEGAL_FILENAME], fn1[LONGEST_LEGAL_FILENAME];
    size_t len = 0;
    const char *w;
    int d;
    std::memset(filename, 0, sizeof(filename));
    std::memset(fn1, 0, sizeof(fn1));
    if (!is_fixnum(dir)) return aerror1("open", dir);
    d = static_cast<int>(int_of_fixnum(dir));
#ifdef DEBUG_OPENING_FILES
    trace_printf("Open file:");
    switch (d & DIRECTION_MASK)
    {   case DIRECTION_PROBE: trace_printf(" probe");  break;
        case DIRECTION_INPUT: trace_printf(" input");  break;
        case DIRECTION_OUTPUT:trace_printf(" output"); break;
        case DIRECTION_IO:    trace_printf(" io");     break;
    }
    switch (d & IF_EXISTS_MASK)
    {   case IF_EXISTS_NIL:                trace_printf(" if-exists-nil");
            break;
        case IF_EXISTS_OVERWRITE:
            trace_printf(" if-exists-overwrite"); break;
        case IF_EXISTS_APPEND:             trace_printf(" if-exists-append");
            break;
        case IF_EXISTS_RENAME:             trace_printf(" if-exists-rename");
            break;
        case IF_EXISTS_ERROR:              trace_printf(" if-exists-error");
            break;
        case IF_EXISTS_NEW_VERSION:
            trace_printf(" if-exists-new-version"); break;
        case IF_EXISTS_SUPERSEDE:
            trace_printf(" if-exists-supersede"); break;
        case IF_EXISTS_RENAME_AND_DELETE:  trace_printf(" if-exists-r-and-d");
            break;
    }
    switch (d & IF_MISSING_MASK)
    {   case IF_MISSING_NIL:
            trace_printf(" if-missing-nil"); break;
        case IF_MISSING_CREATE:
            trace_printf(" if-missing-create"); break;
        case IF_MISSING_ERROR:              trace_printf(" if-missing-error");
            break;
    }
    if (d & OPEN_BINARY) trace_printf(" binary");
    if (d & OPEN_PIPE) trace_printf(" pipe");
    trace_printf("\n");
#endif

    w = get_string_data(name, "open", len);
    if (len >= sizeof(filename)) len = sizeof(filename);

    file = nullptr;
    switch (d & (DIRECTION_MASK | OPEN_PIPE))
    {   case DIRECTION_PROBE:      // probe file - can not be used with pipes
            file = open_file(filename, w, static_cast<size_t>(len), "r", nullptr);
            if (file == nullptr)
            {   switch (d & IF_MISSING_MASK)
                {   case IF_MISSING_NIL:
                        return onevalue(nil);
                    case IF_MISSING_ERROR:
                        error(1, err_open_failed, name);
                    case IF_MISSING_CREATE:
// I thing that people who go (open xxx :direction :probe
//                                      :if-does-not-exist :create)
// are to be considered unduly enthusiastic, but I will still try to do what
// they tell me to!
                        file = open_file(filename, w, static_cast<size_t>(len), "w", nullptr);
                        if (file == nullptr) error(1, err_open_failed, name);
                        std::fclose(file);
                        file = nullptr;
                }
            }
            else
            {   std::fclose(file);
                file = nullptr;
            }
            break;        // Must then create a no-direction stream

        case DIRECTION_INPUT:
            file = open_file(filename, w, static_cast<size_t>(len),
                             (d & OPEN_BINARY ? "rb" : "r"),
                             nullptr);
            if (file == nullptr)
            {   switch (d & IF_MISSING_MASK)
                {   case IF_MISSING_NIL:
                        return onevalue(nil);
                    case IF_MISSING_ERROR:
                        error(1, err_open_failed, name);
                    case IF_MISSING_CREATE:
                        file = open_file(filename, w,
                                         static_cast<size_t>(len), "w", nullptr);
                        if (file == nullptr) error(1, err_open_failed, name);
                        std::fclose(file);
// I use fopen(xx,"w") to create the file, then close it again and re-open
// for input, so that concurrent tasks can see the file now existing but
// only open for reading. If opening the file I just created fails I will
// give up.
                        file = open_file(filename, w, static_cast<size_t>(len),
                                         (d & OPEN_BINARY ? "rb" : "r"),
                                         nullptr);
                        if (file == nullptr) error(1, err_open_failed, name);
                        break;

                }
            }
            report_file(filename);
            break;  // if-exists ignored when opening for input

        case DIRECTION_OUTPUT:
        case DIRECTION_IO:
// I will start by trying to open the file to see if it exists. By using
// mode "r+" I will only open it if I am able to obtain write-access, and
// in some cases I will then be able to make use of the file. The fact that
// it will have been opened for IO not just output will not harm me.
            file = open_file(filename, w, static_cast<size_t>(len),
                             (d & OPEN_BINARY ? "r+b" : "r+"),
                             nullptr);
            if (file == nullptr) switch (d & IF_MISSING_MASK)
                {   case IF_MISSING_NIL:
                        return onevalue(nil);
                    case IF_MISSING_ERROR:
                        error(1, err_open_failed, name);
                    case IF_MISSING_CREATE:
                        break;          // usual case for output and IO files
                }
            else switch (d & IF_EXISTS_MASK)
                {   case IF_EXISTS_NIL:
                        std::fclose(file);
                        return onevalue(nil);
                    case IF_EXISTS_RENAME:
// When I open a file with :if-exists :rename I will always rename to
// a fixed target, "oldfile.bak". If the rename fails I will not worry too
// much. I imagine some people would rather that the name I renamed to was
// based on the original file-name, but that seems excessive to me. And I
// would have little sympathy for users who relied on it!
                        std::fclose(file);
                        file = nullptr;
                        rename_file(filename, w, static_cast<size_t>(len),
                                    fn1, "oldfile.bak", 11);
                        break;
                    case IF_EXISTS_ERROR:
                        std::fclose(file);
                        error(1, err_open_failed, name);
// Working through the standard C library the ideas of :new-version,
// :supersede and :rename-and-delete seem rather odd, so I will just treat
// them all as :new-version.
                    case IF_EXISTS_SUPERSEDE:
                    case IF_EXISTS_RENAME_AND_DELETE:
                    case IF_EXISTS_NEW_VERSION:
                        std::fclose(file);
                        delete_file(filename, w, static_cast<size_t>(len));
                        file = nullptr;
                        break;
                    case IF_EXISTS_OVERWRITE:
                        break;
                    case IF_EXISTS_APPEND:
                        std::fseek(file, 0L, SEEK_END);
                        break;
                }
            if (file == nullptr)
            {   file = open_file(filename, w,
                                 static_cast<size_t>(len),
                                 (d & OPEN_BINARY ? "w+b" : "w+"),
                                 nullptr);
                if (file == nullptr) error(1, err_open_failed, name);
            }
            break;


        case DIRECTION_OUTPUT | OPEN_PIPE:
            std::memcpy(filename, w, static_cast<size_t>(len));
            filename[len] = 0;
            file = my_popen(filename, "w");
            if (file == nullptr) error(1, err_pipe_failed, name);
            break;

        case DIRECTION_INPUT | OPEN_PIPE:
            std::memcpy(filename, w, static_cast<size_t>(len));
            filename[len] = 0;
            file = my_popen(filename, "r");
            if (file == nullptr) error(1, err_pipe_failed, name);
            break;

        case DIRECTION_IO | OPEN_PIPE:
            return aerror("reading and writing from pipes is not supported in CSL\n");
    }

    {   THREADID;
        Save save(THREADARG name);
        r = make_stream_handle();
        errexit();
        save.restore(name);
    }
    stream_type(r) = name;
    set_stream_file(r, file);
    switch (d & (DIRECTION_MASK | OPEN_PIPE))
    {   case DIRECTION_INPUT | OPEN_PIPE:
            set_stream_read_fn(r, char_from_pipe);
            set_stream_read_other(r, read_action_pipe);
            break;
        case DIRECTION_INPUT:
            set_stream_read_fn(r, char_from_file);
            set_stream_read_other(r, read_action_file);
            break;
        case DIRECTION_OUTPUT | OPEN_PIPE:
            set_stream_write_fn(r, char_to_pipeout);
            set_stream_write_other(r, write_action_pipe);
            break;
        case DIRECTION_OUTPUT:
            set_stream_write_fn(r, char_to_file);
            set_stream_write_other(r, write_action_file);
            set_stream_read_other(r, read_action_output_file);
            break;
        case DIRECTION_IO:
            set_stream_read_fn(r, char_from_file);
            set_stream_read_other(r, read_action_output_file);
            set_stream_write_fn(r, char_to_file);
            set_stream_write_other(r, write_action_file);
            break;
    }
    return onevalue(r);
}

LispObject Lwrs(LispObject env, LispObject a)
{   LispObject old = qvalue(standard_output);
    if (a == nil) a = qvalue(terminal_io);
    if (a == old) return onevalue(old);
    else if (!is_stream(a)) return aerror1("wrs", a);
    else if ((character_stream_writer *)stream_write_fn(
                 a) == char_to_illegal)
#ifdef COMMON
        a = qvalue(terminal_io);
#else
        return aerror("wrs (closed or input file)"); // closed file or input file
#endif
    setvalue(standard_output, a);
    return onevalue(old);
}

LispObject Lclose(LispObject env, LispObject a)
{
// I will not allow anybody to close the terminal streams
    if (a == nil ||
        a == lisp_terminal_io) return onevalue(nil);
    else if (!is_stream(a)) return aerror1("close", a);
    if (a == qvalue(standard_input))
        setvalue(standard_input, lisp_terminal_io);
    else if (a == qvalue(standard_output))
        setvalue(standard_output, lisp_terminal_io);
    other_read_action(READ_CLOSE, a);
    other_write_action(WRITE_CLOSE, a);
#ifdef COMMON
    return onevalue(lisp_true);
#else
    return onevalue(nil);
#endif
}

#if defined HAVE_LIBFOX
namespace FX
{
extern void *text;
}
#define GUI_TEST FX::text
#endif
#if defined HAVE_LIBWX
extern void *panel;
#define GUI_TEST panel
#endif

LispObject Lmath_display(LispObject env, LispObject a)
{
// In all cases where maths display is not supported (ie if output is
// not directly to a window that has been built with SHOWMATH
// option) this returns nil and does not do anything at all exciting. If there
// is the possibility of maths output the cases supported here are:
// nil  ) Enquire if maths display is available, return T if so;
// or 0 )
// 1      Enquire if a spool file is present;
// 2      Clear out maths display buffer ready to start a new line;
// 3      Indicate that local maths buffer is now complete and pass
//        its contents (which may be several lines) to the front end
//        display engine.
#if defined HAVE_LIBFOX || defined HAVE_LIBWX
    if (a == nil || a == fixnum_of_int(0)) // test if showmath available
    {
// Disable maths specials if output is NOT to the terminal. Observe that often
// standard_output will be a synonym for direct terminal access.
        LispObject std = qvalue(standard_output);
// GUI_TEST is the FXTerminal object, or corresponding wxWidgets object.
// If it is nullptr that means that I had selected non-windowed mode....
        if (GUI_TEST == nullptr) return onevalue(nil);
// With CSL I have all these curious ways of ending up with standard output
// redirected to elsewhere! In any such case I want this code to report "not
// directly to a maths-aware window".
        if (alternative_stdout != nullptr ||
            procedural_output != nullptr) return onevalue(nil);
// I allow for synonym streams (which are probably only used in Common Lisp
// mode). I do NOT allow for broadcast streams. I then check if the current
// output stream would end up executing char_to_terminal to write a character.
        while ((character_stream_writer *)stream_write_fn(
                   std) == char_to_synonym)
            std = stream_write_data(std);
        if ((character_stream_writer *)stream_write_fn(std) !=
            char_to_terminal) return onevalue(nil);
// Now I believe I am attached to a screen that can display maths.
        return onevalue(lisp_true);
    }
    else if (a == fixnum_of_int(1))        // test if spool file in use
    {
// Note that I let this say TRUE if a spool file is in use regardless
// of whether maths display is to be used...
        if (spool_file == nullptr) return onevalue(nil);
        else return onevalue(lisp_true);
    }
    else if (a == fixnum_of_int(2))        // clear out local buffer
    {   math_buffer_p = 0;
        if (math_buffer != nullptr) math_buffer[0] = 0;
        return onevalue(lisp_true);
    }
    else if (a == fixnum_of_int(3))        // display local buffer
    {   if (math_buffer == nullptr ||
            math_buffer[0]==0) return onevalue(nil);
        fwin_showmath(math_buffer);
        math_buffer_p = 0;
        math_buffer[0] = 0;
        return onevalue(lisp_true);
    }
    else
#endif
        return onevalue(nil);             // bad arg, but just return nil
}

LispObject Ltruename(LispObject env, LispObject name)
{   char filename[LONGEST_LEGAL_FILENAME];
    LispObject truename;
    size_t len = 0;
    const char *w = get_string_data(name, "truename", len);
    char *w1;
    std::memset(filename, 0, sizeof(filename));
    if (len >= sizeof(filename)) len = sizeof(filename);

    w1 = get_truename(filename,w,len);
    if (w1 == nullptr) return aerror0(filename);

    truename = make_string(w1);
    std::free(w1);

    return onevalue(truename);
}

LispObject Lcreate_directory(LispObject env, LispObject name)
{   char filename[LONGEST_LEGAL_FILENAME];
    size_t len = 0;
    const char *w;
    std::memset(filename, 0, sizeof(filename));
    if (name == unset_var) return onevalue(nil);
    w = get_string_data(name, "create-directory", len);
    if (len >= sizeof(filename)) len = sizeof(filename);
    len = create_directory(filename, w, static_cast<size_t>(len));
    return onevalue(Lispify_predicate(len == 0));
}

LispObject Lfile_readable(LispObject env, LispObject name)
{   char filename[LONGEST_LEGAL_FILENAME];
    size_t len = 0;
    const char *w = get_string_data(name, "file-readable", len);
    std::memset(filename, 0, sizeof(filename));
    if (len >= sizeof(filename)) len = sizeof(filename);

    len = file_readable(filename, w, static_cast<size_t>(len));
    return onevalue(Lispify_predicate(len));
}

LispObject Lchange_directory(LispObject env, LispObject name)
{   char filename[LONGEST_LEGAL_FILENAME];
    size_t len = 0;
    const char *err;
    const char *w;
    std::memset(filename, 0, sizeof(filename));
    if (name == unset_var) return onevalue(nil);
    w = get_string_data(name, "change-directory", len);
    if (len >= sizeof(filename)) len = sizeof(filename);
    err = change_directory(filename, w, static_cast<size_t>(len));
    if (err != nullptr) return aerror0(err);
    return onevalue(Lispify_predicate(err == nullptr));
}

LispObject Lfile_writeable(LispObject env, LispObject name)
{   char filename[LONGEST_LEGAL_FILENAME];
    size_t len = 0;
    const char *w;
    std::memset(filename, 0, sizeof(filename));

    // First check whether file exists
    if (Lfilep(env,name) == nil) return nil;

    w = get_string_data(name, "file-writable", len);
    if (len >= sizeof(filename)) len = sizeof(filename);

    len = file_writeable(filename, w, static_cast<size_t>(len));
    return onevalue(Lispify_predicate(len));
}

LispObject Ldelete_file(LispObject env, LispObject name)
{   char filename[LONGEST_LEGAL_FILENAME];
    size_t len = 0;
    const char *w;
    std::memset(filename, 0, sizeof(filename));
    if (name == unset_var) return onevalue(nil);
    w = get_string_data(name, "delete-file", len);
    if (len >= sizeof(filename)) len = sizeof(filename);
    len = delete_file(filename, w, static_cast<size_t>(len));
    return onevalue(Lispify_predicate(len == 0));
}

LispObject Ldelete_wildcard(LispObject env, LispObject name)
{   char filename[LONGEST_LEGAL_FILENAME];
    size_t len = 0;
    const char *w;
    std::memset(filename, 0, sizeof(filename));
    if (name == unset_var) return onevalue(nil);
    w = get_string_data(name, "delete-wildcard", len);
    if (len >= sizeof(filename)) len = sizeof(filename);
    len = delete_wildcard(filename, w, static_cast<size_t>(len));
    return onevalue(Lispify_predicate(len == 0));
}

// Returns the length of a file in bytes
LispObject Lfile_length(LispObject env, LispObject name)
{   char filename[LONGEST_LEGAL_FILENAME];
    size_t len = 0;
    int64_t size;
    const char *w = get_string_data(name, "file-length", len);
    std::memset(filename, 0, sizeof(filename));
    if (len >= sizeof(filename)) len = sizeof(filename);
    size = file_length(filename, w, static_cast<size_t>(len));
    if (size < 0) return nil;
    else return make_lisp_integer64((int64_t)size);
}

LispObject Ldirectoryp(LispObject env, LispObject name)
{   char filename[LONGEST_LEGAL_FILENAME];
    size_t len = 0;
    const char *w = get_string_data(name, "directoryp", len);
    std::memset(filename, 0, sizeof(filename));
    if (len >= sizeof(filename)) len = sizeof(filename);
    len = directoryp(filename, w, static_cast<size_t>(len));
    return onevalue(Lispify_predicate(len));
}


LispObject Lget_current_directory(LispObject env)
{   char filename[LONGEST_LEGAL_FILENAME];
    int len;
    std::memset(filename, 0, sizeof(filename));
    len = get_current_directory(filename, LONGEST_LEGAL_FILENAME);
    if (len == 0) return onevalue(nil);
    return onevalue(make_string(filename));
}

LispObject Luser_homedir_pathname(LispObject env)
{   char home[LONGEST_LEGAL_FILENAME];
    int len;
    std::memset(home, 0, sizeof(home));
    len = get_home_directory(home, LONGEST_LEGAL_FILENAME);
    if (len == 0) return onevalue(nil);
    return onevalue(make_string(home));
}

LispObject Lget_lisp_directory(LispObject env)
{   char filename[LONGEST_LEGAL_FILENAME];
    int len;
    std::memset(filename, 0, sizeof(filename));
    std::strcpy(filename, standard_directory);
    len = std::strlen(filename);
    while (len-- > 0 &&
           filename[len] != '/' &&
           filename[len] != '\\');
    if (len == 0) return onevalue(nil);
    filename[len] = 0;
    return onevalue(make_string(filename));
}

LispObject Lfind_gnuplot(LispObject env)
{   char filename[LONGEST_LEGAL_FILENAME];
    char *s;
    find_gnuplot(filename);
    s = filename;
// Because the path will be used in a command I will put quote marks
// around it so that embedded whitespace does not cause a calamity.
    while (*s != 0) s++;
    *s++ = '"';
    *s = 0;
    while (s != filename)
    {   *(s+1) = *s;
        s--;
    }
    s[1] = s[0];
    s[0] = '"';
    return onevalue(make_string(filename));
}

LispObject Lgetpid(LispObject env)
{
#ifdef WIN32
    return onevalue(fixnum_of_int(windowsGetPid()));
#else
    return onevalue(fixnum_of_int(getpid()));
#endif
}

LispObject Lrename_file(LispObject env, LispObject from,
                        LispObject to)
{   char from_name[LONGEST_LEGAL_FILENAME],
    to_name[LONGEST_LEGAL_FILENAME];
    size_t from_len = 0, to_len = 0;
    const char *from_w, *to_w;
    std::memset(from_name, 0, sizeof(from_name));
    std::memset(to_name, 0, sizeof(to_name));
    if (from == unset_var) return onevalue(nil);
    if (to == unset_var) return onevalue(nil);
    THREADID;
    {   Save save(THREADARG to);
        from_w = get_string_data(from, "rename-file", from_len);
        save.restore(to);
    }
    if (from_len >= sizeof(from_name)) from_len = sizeof(from_name);
    from = reinterpret_cast<LispObject>(from_w + TAG_VECTOR - CELL);

    {   Save save(THREADARG from);
        to_w = get_string_data(to, "rename-file", to_len);
        save.restore(from);
    }
    from_w = reinterpret_cast<const char *>(&celt(from, 0));
    if (to_len >= sizeof(to_name)) to_len = sizeof(to_name);

    to_len = rename_file(from_name, from_w, static_cast<size_t>(from_len),
                         to_name, to_w, static_cast<size_t>(to_len));
    return onevalue(Lispify_predicate(to_len == 0));
}

// This function is a call-back from the file-scanning routine.

static void make_dir_list(string name, string leafname, int why, long int size)
{   LispObject w = make_string(leafname.c_str());
    THREADID;
    w = cons(w, *stack);
    *stack = w;
}

LispObject Llist_directory(LispObject env, LispObject name)
{   LispObject result;
    char filename[LONGEST_LEGAL_FILENAME];
    size_t len = 0;
    const char *w = get_string_data(name, "list-directory", len);
    std::memset(filename, 0, sizeof(filename));
    if (len >= sizeof(filename)) len = sizeof(filename);
    THREADID;
    *++stack = nil;
    list_directory_members(&filename[0], w, len, make_dir_list);
    result = *stack--;
    return onevalue(nreverse(result));
}


/*****************************************************************************/
//      Printing.
/*****************************************************************************/

int escaped_printing;

// I should make WRS save tmprint_flag so that it always refers to
// a setting of the stream currently in use, ie active_stream. That should
// not be hard but I will do it later. @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
int tmprint_flag = 0;

static void outprefix(bool blankp, int32_t len)
// This function takes most of the responsibility for splitting lines.
// when called we are about to print an item with (len) characters.
// If blankp is true we need to display a blank or newline before
// the item.
{   int32_t line_length =
        other_write_action(WRITE_GET_INFO+WRITE_GET_LINE_LENGTH,
                           active_stream);
    int32_t column =
        other_write_action(WRITE_GET_INFO+WRITE_GET_COLUMN,
                           active_stream);
    if (blankp) len++;
    if (column+len > line_length &&
        (escaped_printing & escape_nolinebreak) == 0 &&
        !tmprint_flag)
        putc_stream('\n', active_stream);
    else if (blankp) putc_stream(' ', active_stream);
}

static LispObject Lprint_precision(LispObject env, LispObject a)
{   int32_t old = print_precision;
    if (a == nil) return onevalue(fixnum_of_int(old));
    if (!is_fixnum(a)) return aerror1("print-precision", a);
    print_precision = int_of_fixnum(a);
    if (print_precision > 36) print_precision = 36;
    else if (print_precision < 1) print_precision = 15;
    return onevalue(fixnum_of_int(old));
}

static LispObject Lget_precision(LispObject env)
{   return onevalue(fixnum_of_int(print_precision));
}

static void prin_buf(char *buf, int blankp)
{   int len = std::strlen(buf), i;
    outprefix(blankp, len);
    for (i=0; i<len; i++)
    {   putc_stream(*buf++, active_stream);
    }
}

// I want the floating point print style that I use to match the
// one used by PSL rather carefully. So here is some code so that
// everything I do about it is in one place.


// Two crummy little functions to delete and insert chars from strings.

static void char_del(char *s)
{   while (*s != 0)
    {   *s = *(s+1);
        s++;
    }
}

static void char_ins(char *s, int c)
{   char *p = s;
    while (*p != 0) p++;
    while (p != s)
    {   *(p+1) = *p;
        p--;
    }
    *(s+1) = *s;
    *s = c;
//  printf("After char_ins \"%s\"\n", s);
}

static void fp_sprint(char *buff, double x, int prec, int xmark)
{
// Note that I am assuming IEEE arithmetic here so the tricks that I use
// to detect -0.0, NaN and infinities ought to be OK. Just remember that
// -0.0 is equal to 0.0 and not less than it, so the simple test
// "x < 0.0" will not pick up the case of -0.0.
    if (x == 0.0)
    {   if (xmark != 'e')
        {   if (1.0/x < 0.0) std::sprintf(buff, "-0.0%c+00", xmark);
            else std::sprintf(buff, "0.0%c+00", xmark);
        }
        else if (1.0/x < 0.0) std::strcpy(buff, "-0.0");
        else std::strcpy(buff, "0.0");
        return;
    }
    if (x != x)
    {   std::strcpy(buff,
                    "NaN"); // The length of the NaN will not be visible
        return;
    }
    if (x == 2.0*x)
    {   if (x < 0.0) std::strcpy(buff,
                                     "minusinf"); // Length of infinity not shown.
        else std::strcpy(buff, "inf");
        return;
    }
// Limit the precision used for printing based on the type of float involved.
    switch (xmark)
    {   case 's': case 'S':
            if (prec > 7) prec = 7;
            break;
        case 'f': case 'F':
            if (prec > 8) prec = 8;
            break;
        default:
            if (prec > 17) prec = 17;
    }
    if (x < 0.0)
    {   *buff++ = '-';
        x = -x;
    }
// Now I just have strictly positive values to worry about
    std::sprintf(buff, "%.*g", prec, x);
// I will allow for pathologically bad versions of sprintf...
    if (*buff == '+') char_del(buff);      // Explicit "+" not wanted
    if (*buff == '.') char_ins(buff, '0'); // turn .nn to 0.nn
    else if (*buff == 'e')                 // turn Ennn to 0.0Ennn
    {   char_ins(buff, '0');
        char_ins(buff, '.');
        char_ins(buff, '0');
    }
// I now have at lesst one digit before any "." or "E"
    while (*buff != 0 && *buff != '.' && *buff != 'e') buff++;
    if (*buff == 'e') *buff = xmark;    // force style of exponent mark
    if (*buff == 0 || *buff == xmark)   // ddd to ddd.0
    {   char_ins(buff, '0');            // and dddEnnn to ddd.0Ennn
        char_ins(buff, '.');
    }
// I now have a "." in there
    while (*buff != 0 && *buff != 'e' && *buff != xmark) buff++;
    if (*(buff-1) == '.') char_ins(buff++, '0');// ddd. to ddd.0
    while (*(buff-1) == '0' &&                  // ddd.nnn0 to ddd.nnn
           *(buff-2) != '.') char_del(--buff);
    if (*buff == 0)
    {   if (xmark != 'e')
        {   *buff++ = xmark;
            *buff++ = '+';
            *buff++ = '0';
            *buff++ = '0';
            *buff = 0;
        }
        return; // no E present. Add exponent mark if not default type
    }
    if (xmark != 'e') *buff = xmark;
    buff++;
// At this stage I am looking at the exponent part
    if (*buff == 0) std::strcpy(buff, "+00");
    else if (std::isdigit(static_cast<unsigned char>(*buff)))
        char_ins(buff, '+');
// Exponent should now start with explicit + or - sign
    buff++;
// Force exponent to have at least 2 digits
    if (*(buff+1) == 0) char_ins(buff, '0');
// Three-digit exponent with leading zero gets trimmed here
    else if (*buff == '0' && *(buff+2) != 0) char_del(buff);
}

#ifdef HAVE_SOFTFLOAT
static void fp_sprint128(char *buff, float128_t x, int prec,
                         int xchar)
{   if (f128M_eq(&x, &f128_0))
    {   if (f128M_negative(&x)) std::strcpy(buff, "-0.0L+00");
        else std::strcpy(buff, "0.0L+00");
        return;
    }
    if (f128M_nan(&x))
    {   std::strcpy(buff, "NaN");
        return;
    }
    if (f128M_infinite(&x))
    {   if (f128M_negative(&x)) std::strcpy(buff, "minusinf");
        else std::strcpy(buff, "inf");
        return;
    }
    if (f128M_negative(&x))
    {   *buff++ = '-';
        f128M_negate(&x);
    }
    if (prec > 36) prec = 36;
    f128M_sprint_G(buff, 0, prec, &x);
//  printf("Raw printing gives \"%s\"\n", buff);
//
// I rather hope that my own print routine is not degenerate so some of
// these fix-ups are not necessary, but I will leave them in just to be
// really safe.
    if (*buff == '+') char_del(buff);      // Explicit "+" not wanted
    if (*buff == '.') char_ins(buff, '0'); // turn .nn to 0.nn
// Common Lisp can use "l" or "L" as the exponent marker in a long float,
// so in the processing here I will detect "l" just in case at a later
// stage I move to adopting that as a print convention.
#define exponent_mark(c) ((c)=='e' || (c)=='l')
    else if (exponent_mark(*buff))                 // turn Ennn to 0.0Ennn
    {   *buff = 'L';
        char_ins(buff, '0');
        char_ins(buff, '.');
        char_ins(buff, '0');
    }
    while (*buff != 0 && *buff != '.' && !exponent_mark(*buff)) buff++;
    if (*buff == 0 || exponent_mark(*buff))     // ddd to ddd.0
    {   char_ins(buff, '0');            // and dddEnnn to ddd.0Ennn
        char_ins(buff, '.');
    }
    while (*buff != 0 && !exponent_mark(*buff)) buff++;
    if (*(buff-1) == '.') char_ins(buff++, '0');// ddd. to ddd.0
    while (*(buff-1) == '0' &&                  // ddd.nnn0 to ddd.nnn
           *(buff-2) != '.') char_del(--buff);
    if (*buff == 0)
    {   *buff++ = 'L';
        *buff++ = '+';
        *buff++ = '0';
        *buff++ = '0';
        *buff = 0;
        return; // no exponent mark present
    }
    *buff = 'L';
    buff++;
    if (*buff == 0) std::strcpy(buff, "+00");
    else if (std::isdigit(static_cast<unsigned char>(*buff)))
        char_ins(buff, '+');
    buff++;
    if (*(buff+1) == 0) char_ins(buff, '0');
    else if (*buff == '0' && *(buff+2) != 0) char_del(buff);
}
#endif // HAVE_SOFTFLOAT

static int32_t local_gensym_count;

// This checks if the sequence in the string starting at offset k is
// of the form "WORD;" where WORD is made up of just alphanumerics.
static int maybemagic(LispObject v, int k, int len)
{   while (k<len)
    {   int c = celt(v, k) & 0xff;
        if (c == ';') return 1;
        else if ((c & 0x80) != 0 ||
                 !std::isalnum(c)) return 0;
        k++;
    }
    return 0;
}

static const char *hexdig = "0123456789abcdef";

static void putc_utf8(int n)
{   n &= 0x001fffff;
    if (n <= 0x7f)
    {   putc_stream(n, active_stream);
        return;
    }
    else if (n <= 0x7ff)
    {   putc_stream(0xc0 + (n>>6), active_stream);
        putc_stream(0x80 + (n & 0x3f), active_stream);
    }
    else if (n <= 0xffff)
    {   putc_stream(0xe0 + (n>>12), active_stream);
        putc_stream(0x80 + ((n>>6) & 0x3f), active_stream);
        putc_stream(0x80 + (n & 0x3f), active_stream);
    }
    else
    {   putc_stream(0xf0 + (n>>16), active_stream);
        putc_stream(0x80 + ((n>>12) & 0x3f), active_stream);
        putc_stream(0x80 + ((n>>6) & 0x3f), active_stream);
        putc_stream(0x80 + (n & 0x3f), active_stream);
    }
}

LispObject internal_prin(LispObject uu, int blankp)
{   LispObject w;
    size_t len, lenchars, k;
    char my_buff[128];
    int bl = blankp & 2;
    THREADID;
    RealSave save(THREADARG uu);
    LispObject &u = save.val(1);
#ifdef COMMON
// There is a fairly shameless FUDGE here. When I come to need to print
// the package part of a symbol as in ppp:xxx (or even |)p(|::|.| if I
// have names with silly characters in them) I will have a STRING that is the
// name of the relevant package, but I want it displayed as if it was an
// identifier. I achieve this by setting the "2" bit in blankp (which is
// otherwise a simple boolean), and when this is detected I go and join the
// code for printing symbols. But in that case I MUST have been passed
// a (simple) string, or else things can collapse utterly.
    blankp &= 1;
    if (bl != 0)
    {   w = u;
        goto tag_symbol;
    }
restart:
#endif
    if (reinterpret_cast<uintptr_t>(stack) >= stackLimit)
        respond_to_stack_event();
    switch (static_cast<int>(u) & TAG_BITS)
    {   case TAG_CONS:
#ifdef COMMON
            if (u == nil)           // BEWARE - nil is tagged as a cons cell
            {   outprefix(blankp, 3);
                putc_stream('N', active_stream);
                putc_stream('I', active_stream);
                putc_stream('L', active_stream);
                return;
            }
#endif
            if (u == 0)
            {   outprefix(blankp, 2);
                putc_stream('?', active_stream);
                putc_stream('?', active_stream);
                return nil;
            }
            outprefix(blankp, 1);
            putc_stream('(', active_stream);
            internal_prin(car(u), 0);
            w = u;
            while (is_cons(w = cdr(w)) && w != 0)
            {
#ifdef COMMON
                if (w == nil) break;    // Again BEWARE the tag code of NIL
#endif
                u = w;
                internal_prin(car(w), 1);
                w = u;
            }
            if (w != nil)
            {   u = w;
                outprefix(true, 1);
                putc_stream('.', active_stream);
                internal_prin(u, 1);
            }
            outprefix(false, 1);
            putc_stream(')', active_stream);
            return nil;

        case TAG_FIXNUM:
// The tag bits for a short float match those for a fixnum if I just look
// at the low 3 bits. Yuk - that means I need an extra test here.
            if (is_sfloat(u))
            {   Float_union uu;
// The following passes the correct value for either 28 or 32-bit floats.
                int xmark = 's';
                if (SIXTY_FOUR_BIT)
                {   uu.i = (int32_t)((int64_t)u>>32);
                    if ((u & XTAG_FLOAT32) != 0) xmark = 'f';
                }
                else uu.i = u - XTAG_SFLOAT;
                if (escaped_printing & escape_hex)
                {   std::sprintf(my_buff, "%.8x%c", uu.i, xmark);
                    goto float_print_tidyup;
                }
                else if (escaped_printing & escape_octal)
                {   std::sprintf(my_buff, "%.11o%c", uu.i, xmark);
                    goto float_print_tidyup;
                }
                else if (escaped_printing & escape_binary)
                {   char *cp = my_buff;
                    for (int b=31; b>=0; b--)
                        *cp++ = '0' + ((uu.i >> b) & 1);
                    *cp++ = xmark;
                    *cp = 0;
                    goto float_print_tidyup;
                }

                fp_sprint(my_buff, static_cast<double>(uu.f), print_precision, xmark);
                goto float_print_tidyup;
            }
            if (escaped_printing & escape_hex)
            {   intptr_t v = int_of_fixnum(u);
                int width = escape_width(escaped_printing);
                uintptr_t mask;
// The printing style adopted here for negative numbers follows that used in
// the big number printing code.  A prefix "~" stands for an infinite initial
// string of 'f' digits, and what follows will be exactly one 'f' (just to
// remind you) and then the remaining hex digits.  E.g. -2 should display
//1;5q as ~fe.  Note that any fixnum will start off with 0xf in the top 4 of
// 32 bits.  If an explicit width had been specified then I want that many
// charcters to be displayed, with full leading zeros etc. A width is taken as
// minimum number of chars to be displayed, so a width of zero (or in fact 1)
// would have the effect of no constraint. The width-specification field
// only allows for the range 0 to 63, and that is just as well since I put
// characters in a buffer (my_buff) which would almost fill up at the
// widest...
                len = 0;
                if (v < 0)
                {   mask = ((uintptr_t)0xf)<<(8*sizeof(intptr_t)-4);
                    my_buff[len++] = '~';
                    width--;
                    while (((uintptr_t)v & mask) == mask && mask != 0)
                    {   v = v ^ (mask << 4);
                        mask = mask >> 4;
                    }
                    k = 'f';
                }
                else k = '0';
                mask = 0xf;
                while (((uintptr_t)v & mask) != (uintptr_t)v)
                {   width--;
                    mask = (mask<<4) | 0xf;
                }
                while (--width > 0) my_buff[len++] = static_cast<char>(k);
                std::sprintf(&my_buff[len], "%" PRIx64,
                    static_cast<int64_t>(v));
            }
            else if (escaped_printing & escape_octal)
            {   intptr_t v = int_of_fixnum(u);
                int width = escape_width(escaped_printing);
                uintptr_t mask;
                len = 0;
                if (v < 0)
                {   int sh = 8*sizeof(intptr_t)-3;
                    sh = (sh/3)*3;
                    mask = ((uintptr_t)0x7)<<sh;
                    my_buff[len++] = '~';
                    width--;
                    while (((uintptr_t)v & mask) == mask && mask != 0)
                    {   v = v ^ (mask << 3);
                        mask = mask >> 3;
                    }
                    k = '7';
                }
                else k = '0';
                mask = 0x7;
                while (((uintptr_t)v & mask) != (uintptr_t)v)
                {   width--;
                    mask = (mask<<3) | 0x7;
                }
                while (--width > 0) my_buff[len++] = static_cast<char>(k);
                std::sprintf(&my_buff[len], "%" PRIo64,
                    static_cast<int64_t>(v));
            }
            else if (escaped_printing & escape_binary)
            {   intptr_t v = int_of_fixnum(u);
//          int width = escape_width(escaped_printing);
                uint64_t mask = ((uint64_t)1)<<(8*sizeof(intptr_t)-1);
                len = 0;
                if (v < 0)
                {   while (((uintptr_t)v & mask) == mask && mask != 0)
                    {   v = v ^ (mask << 1);
                        mask = mask >> 1;
                    }
                    my_buff[len++] = '~';
                    k = '1';
                }
                else k = '0';
// /* Width specifier not processed here (yet), sorry.
                mask = ((uintptr_t)1)<<(8*sizeof(intptr_t)-1);
                while (((uintptr_t)v & mask) == 0 && mask != 1) mask = mask >> 1;
                while (mask != 0)
                {   my_buff[len++] = ((uintptr_t)v & mask) ? '1' : '0';
                    mask = mask >> 1;
                }
                my_buff[len] = 0;
            }
            else
                std::sprintf(my_buff, "%" PRId64,
                    static_cast<int64_t>(int_of_fixnum(u)));
            break;

        case TAG_HDR_IMMED:
// A SPID is an object used internally by CSL in various places, and the
// rules of the system are that it ought never to be visible to the user.
// I print it here in case it arises because of a bug, or while I am testing.
// For instance if I display the internal components of a hash table or
// values passed around when optional arguments are being handled some of
// these may arise.
            if (is_spid(u))
            {   switch (u & 0xffff)
                {
// The decoding of readable names for SPIDs here is somewhat over the top
// except while somebdy is hard at work debugging....
                    case SPID_NIL:     std::strcpy(my_buff, "SPID_NIL");     break;
                    case SPID_FBIND:   std::strcpy(my_buff, "SPID_FBIND");   break;
                    case SPID_CATCH:   std::strcpy(my_buff, "SPID_CATCH");   break;
                    case SPID_PROTECT: std::strcpy(my_buff, "SPID_PROTECT"); break;
                    case SPID_NOARG:   std::strcpy(my_buff, "SPID_NOARG");   break;
// SPID_HASHEMPTY and SPID_HASHTOMB should only appear within hash tables,
// and I do not expect to be able to re-read those. I will use concise
// representations for them.
                    case SPID_HASHEMPTY:std::strcpy(my_buff, "~"); break;
                    case SPID_HASHTOMB:std::strcpy(my_buff, "+"); break;
                    case SPID_GCMARK:  std::strcpy(my_buff, "SPID_GCMARK");  break;
                    case SPID_NOINPUT: std::strcpy(my_buff, "SPID_NOINPUT"); break;
                    case SPID_ERROR: u = (u >> 20) & 0xfff;
                        std::sprintf(my_buff, "SPID_ERROR_%x",
                            static_cast<int>(u));
                        break;
                    case SPID_PVBIND:  std::strcpy(my_buff, "SPID_PVBIND");  break;
                    case SPID_NOPROP:  std::strcpy(my_buff, "SPID_NOPROP");  break;
                    case SPID_LIBRARY: u = (u >> 20) & 0xfff;
// When I print the name of a library I will truncate the displayed name
// to 124 characters. This is somewhat arbitrary (but MUST relate to the
// size of my_buff), but will tend to keep output more compact.
                        if (fasl_files[u].name == nullptr)
                            std::sprintf(my_buff, "#{%.124s}", "*unknown*");
                        else std::sprintf(my_buff, "#{%.124s}",
                                          fasl_files[u].name);
                        break;
                    default:
                        std::sprintf(my_buff, "SPID_%lx",
                            static_cast<long>((u >> 8) & 0x00ffffff));
                        break;
                }
                len = std::strlen(my_buff);
                outprefix(blankp, len);
                for (k=0; k<len; k++) putc_stream(my_buff[k], active_stream);
                return nil;
            }
// Assume if is a CHAR here. I may need to think hard about Unicode and utf8
// here...
            outprefix(blankp, escaped_printing & escape_yes ? 3 : 1);
            if (u != CHAR_EOF)
// I know that a char is immediate data and so does not need GC protection
            {   if (escaped_printing & escape_yes)
                    putc_stream('#', active_stream), putc_stream('\\', active_stream);
                putc_stream(static_cast<int>(code_of_char(u)), active_stream);
            }
            return nil;

        case TAG_VECTOR:
        {   Header h = vechdr(u);
            len = length_of_header(h) - CELL;  // counts in bytes
#ifdef COMMON
        print_non_simple_string:
#endif
            my_assert(len >= 0 && len < CSL_PAGE_SIZE);
            switch (type_of_header(h))
            {   case TYPE_BPS_1:
                case TYPE_BPS_2:
                case TYPE_BPS_3:
                case TYPE_BPS_4:
                    len = length_of_byteheader(h) - CELL;
                    my_assert(len >= 0 && len < CSL_PAGE_SIZE);
                    outprefix(blankp, 3+2*len);
// At some stage I should look at all the special notations that use "#"
// and ensure that none clash. Well here we go...
//   #Gnnn            gensym    I note that no HTML5 entity names would clash!
//   #<               closures etc
//   #[xxx]           odds
//   #{...}           SPID_LIBRARY
//   #\dd             character
//   #P:              structure
//   #S(              another variant on structure
//   #H(              hash table
//   #(               simple vector
//   #F[              stream
//   #1[              mixed1
//   #2[              mixed2
//   #3[              mixed3
//   #V8(             vec of bytes
//   #V16(            vec of shorts
//   #V32(            vec of 32-bit ints
//   #FS(             vec of floats
//   #FD(             vec of double
//   #*               bit-vector
//   #:               package info
//   #C(              complex num
//   #word;           )
//   #Udigits;        ) extended input symbol
//   #hexdigs;        )
//   #Xhexdigs;       )
                    putc_stream('#', active_stream);
                    putc_stream('[', active_stream);
                    for (k = 0; k < len; k++)
                    {   int ch = celt(u, k);
// Code vectors are not ever going to be re-readable (huh - I suppose there
// is no big reason why they should not be!) so I split them across multiple
// lines if that seems useful.  Anyway a reader for them could understand to
// expect that.
                        outprefix(false, 2);
                        putc_stream(hexdig[(ch >> 4) & 0xf], active_stream);
                        putc_stream(hexdig[ch & 0xf], active_stream);
                    }
                    putc_stream(']', active_stream);
                    return nil;

                case TYPE_STRING_1:
                case TYPE_STRING_2:
                case TYPE_STRING_3:
                case TYPE_STRING_4:
                    len = length_of_byteheader(h) - CELL;
                    my_assert(len >= 0 && len < CSL_PAGE_SIZE);
                    {   int32_t slen = 0;
// /*
// Getting the width of strings that contain tabs correct here is
// something I have not yet attempted - the width to be accumulated in
// slen has to depend on the column at which printing is to start
// (including allowance for any pending blank that may be needed).
// And while I consider this, what about a string that contains
// a newline character?
                        if (escaped_printing & escape_yes)
                        {   for (k = 0; k < len; k++)
                            {   int ch = celt(u, k) & 0xff;
// See later for an explanation of the extra lengths indicated here...
// but in short they are for #xxxx; and #xxxxxx;
// Under cygwin (and potentially on other platforms in certain locales)
// case folding can change the number of utf-bytes or hex characters
// needed to specify a character. To avoid potential pain I will
// always display using at least 4 hex digits.
                                if ((ch & 0xc0) == 0x80) /* nothing */;
                                else if ((ch & 0xe0) == 0xc0) slen += 6;
                                else if ((ch & 0xf0) == 0xe0) slen += 6;
                                else if ((ch & 0x80) == 0x80) slen += 8;
                                else if (ch == '"') slen += 2;
                                else if (ch == '#' &&
                                         maybemagic(u, k+1, len))
                                    slen += 6;  // render as #hash;WORD;
#ifdef COMMON
                                else if (ch == '\\') slen += 2;
// I now guard this with "#ifdef COMMON". It is associated with displaying
// control characters within strings as escapes, as in a newline within a
// string being printed as \0a. Unless the code that reads strings back in
// understands the same conventions this is a mistake, and the Standard Lisp
// reader (and the reader in Reduce) do not... However Reduce does now
// understand things like #NewLine; and #0a; so I should use that notation!
// Any character in the range u+00 to u+1f can be rendered as #xx;
                                else if (std::iscntrl(ch)) slen += 3;
#else
                                else if (ch <= 0x1f) slen += 4;
#endif
                                else slen += 1;
                            }
                            slen += 2;
                        }
                        else
                        {   for (k=0; k < len; k++)
                                if ((celt(u, k) & 0xc0) != 0x80) slen++;
                        }
                        outprefix(blankp, slen);
// I will write out the fast, easy, common case here, ie "princ" where
// I do not have to do anything special with odd characters.
                        if (!(escaped_printing &
                              (escape_yes | escape_fold_down |
                               escape_fold_up | escape_capitalize)))
                        {   for (k = 0; k < len; k++)
                            {   int ch = celt(u, k);
                                putc_stream(ch, active_stream);
                            }
                        }
                        else
                        {   if (escaped_printing & escape_yes)
                                putc_stream('"', active_stream);
                            for (k = 0; k < len; k++)
                            {   int ch = celt(u, k) & 0xff;
#ifdef COMMON
// In Common Lisp mode I do something special with '"' and '\', and
// any control characters get mapped onto an escape sequence.
                                const char *hexdig = "0123456789abcdef";
                                if ((escaped_printing & escape_yes) &&
                                    (ch == '"' || ch == '\\'))
                                {   putc_stream('\\', active_stream);
                                    putc_stream(ch, active_stream);
                                }
                                else if (ch <= 0xff && std::iscntrl(ch))
                                {   putc_stream('\\', active_stream);
                                    putc_stream(hexdig[(ch >> 4) & 0xf], active_stream);
                                    putc_stream(hexdig[ch & 0xf], active_stream);
                                }
#else
// In Standard Lisp mode when I get a '"'  I print two doublequote. And that
// will be the only special case! Well no - I will print control characters
// in the form #xx; in escaped mode.
                                if ((escaped_printing & escape_yes) && ch == '"')
                                {   putc_stream('"', active_stream);
                                    putc_stream('"', active_stream);
                                }
#endif
// If a string contains text like "...#WORD;..." where WORD could possibly
// be something decoded specially on re-input then the output here will
// be rendered as "...#hash;WORD;..." which will defeat the #-introduced
// sequence from being treated as something that represents an extended
// character.
                                else if (ch == '#' &&
                                         maybemagic(u, k+1, len))
                                {   putc_stream('#', active_stream);
                                    putc_stream('h', active_stream);
                                    putc_stream('a', active_stream);
                                    putc_stream('s', active_stream);
                                    putc_stream('h', active_stream);
                                    putc_stream(';', active_stream);
                                }
// The first byte of any multi-byte utf-8 sequence will be a code that is
// at least 0xc0. In such cases I will represent the wide character as
// one of #xxx;, #xxxx; or #xxxxxx; depending on how many bytes were used.
// in some cases that will leave a leading zero in the representation. Or
// if I am not displaying with escape_yes I just need to case fold it.
// Well if I am doing an EXPLODE then this adjustment is not called for.
                                else if (ch >= 0xc0)
                                {   int32_t n = 0;
                                    if ((ch & 0xe0) == 0xc0) // 2 byte
                                    {   n = ch & 0x1f;
                                        k++;
                                        ch = celt(u, k);
                                        n = (n << 6) | (ch & 0x3f);
// There is a portability issue here. ON some platforms (and perhaps with
// some locales set) you may find (for instance) case conversion between
// small; and large Greek letters (as in the TeX notation \gamma vd \Gamma),
// while in others only basic Latin characters will get case converted. This
// effect may show up in the utf8-in-list regression test.
                                        if (escaped_printing & escape_fold_down)
                                            n = std::towlower(n);
                                        else if (escaped_printing & escape_fold_up)
                                            n = std::towupper(n);
                                        if ((escaped_printing & escape_yes) &&
                                            !(escaped_printing & escape_exploding))
                                        {   putc_stream('#', active_stream);
// This first digit is very often redundant here
                                            putc_stream(hexdig[(n>>12)&0xf], active_stream);
                                            putc_stream(hexdig[(n>>8)&0xf], active_stream);
                                            putc_stream(hexdig[(n>>4)&0xf], active_stream);
                                            putc_stream(hexdig[n&0xf], active_stream);
                                            putc_stream(';', active_stream);
                                        }
                                        else putc_utf8(n);
                                    }
                                    else if ((ch & 0xf0) == 0xe0) // 3 byte
                                    {   n = ch & 0x0f;
                                        k++;
                                        ch = celt(u, k);
                                        n = (n << 6) | (ch & 0x3f);
                                        k++;
                                        ch = celt(u, k);
                                        n = (n << 6) | (ch & 0x3f);
                                        if (escaped_printing & escape_fold_down)
                                            n = std::towlower(n);
                                        else if (escaped_printing & escape_fold_up)
                                            n = std::towupper(n);
                                        if ((escaped_printing & escape_yes) &&
                                            !(escaped_printing & escape_exploding))
                                        {   putc_stream('#', active_stream);
                                            putc_stream(hexdig[(n>>12)&0xf], active_stream);
                                            putc_stream(hexdig[(n>>8)&0xf], active_stream);
                                            putc_stream(hexdig[(n>>4)&0xf], active_stream);
                                            putc_stream(hexdig[n&0xf], active_stream);
                                            putc_stream(';', active_stream);
                                        }
                                        else putc_utf8(n);
                                    }
                                    else // assume 4 byte
                                    {   n = ch & 0x07;
                                        k++;
                                        ch = celt(u, k);
                                        n = (n << 6) | (ch & 0x3f);
                                        k++;
                                        ch = celt(u, k);
                                        n = (n << 6) | (ch & 0x3f);
                                        k++;
                                        ch = celt(u, k);
                                        n = (n << 6) | (ch & 0x3f);
// When case folding if the code-point is beyond U+ffff and I am on a machine
// where sizeof(wchar_t) is 2 (eg Windows) I will not case fold. Gosh that
// seems an obscure situation!
                                        if (sizeof(wchar_t) == 4 || n < 0x10000)
                                        {   if (escaped_printing & escape_fold_down)
                                                n = std::towlower(n);
                                            else if (escaped_printing & escape_fold_up)
                                                n = std::towupper(n);
                                        }
                                        if ((escaped_printing & escape_yes) &&
                                            !(escaped_printing & escape_exploding))
                                        {   putc_stream('#', active_stream);
                                            putc_stream(hexdig[(n>>20)&0xf], active_stream);
                                            putc_stream(hexdig[(n>>16)&0xf], active_stream);
                                            putc_stream(hexdig[(n>>12)&0xf], active_stream);
                                            putc_stream(hexdig[(n>>8)&0xf], active_stream);
                                            putc_stream(hexdig[(n>>4)&0xf], active_stream);
                                            putc_stream(hexdig[n&0xf], active_stream);
                                            putc_stream(';', active_stream);
                                        }
                                        else putc_utf8(n);
                                    }
                                }
                                else
// Here I have a character in the range u+0000 to u+007f.
                                {   if (escaped_printing & escape_fold_down)
                                        ch = std::tolower(ch);
                                    else if (escaped_printing & escape_fold_up)
                                        ch = std::toupper(ch);
// Just For Now I Will Not Implement The Option To Capitalize Things
                                    putc_stream(ch, active_stream);
                                }
                            }
                        }
                        if (escaped_printing & escape_yes)
                            putc_stream('"', active_stream);
                    }
                    return nil;

                case TYPE_SP:
                    std::sprintf(my_buff, "#<closure: %p>",
                                 reinterpret_cast<void *>(static_cast<LispObject>(elt(u, 0))));
                    goto print_my_buff;

#if 0
                case TYPE_MAPLEREF:
#endif
                case TYPE_FOREIGN:
                case TYPE_ENCAPSULATE:
                    std::sprintf(my_buff, "#<encapsulated pointer: %p>",
                                 *(void **)&elt(u, 0));
                    goto print_my_buff;

                case TYPE_BITVEC_1:   bl = 1; break;
                case TYPE_BITVEC_2:   bl = 2; break;
                case TYPE_BITVEC_3:   bl = 3; break;
                case TYPE_BITVEC_4:   bl = 4; break;
                case TYPE_BITVEC_5:   bl = 5; break;
                case TYPE_BITVEC_6:   bl = 6; break;
                case TYPE_BITVEC_7:   bl = 7; break;
                case TYPE_BITVEC_8:   bl = 8; break;
                case TYPE_BITVEC_9:   bl = 9; break;
                case TYPE_BITVEC_10:  bl = 10; break;
                case TYPE_BITVEC_11:  bl = 11; break;
                case TYPE_BITVEC_12:  bl = 12; break;
                case TYPE_BITVEC_13:  bl = 13; break;
                case TYPE_BITVEC_14:  bl = 14; break;
                case TYPE_BITVEC_15:  bl = 15; break;
                case TYPE_BITVEC_16:  bl = 16; break;
                case TYPE_BITVEC_17:  bl = 17; break;
                case TYPE_BITVEC_18:  bl = 18; break;
                case TYPE_BITVEC_19:  bl = 19; break;
                case TYPE_BITVEC_20:  bl = 20; break;
                case TYPE_BITVEC_21:  bl = 21; break;
                case TYPE_BITVEC_22:  bl = 22; break;
                case TYPE_BITVEC_23:  bl = 23; break;
                case TYPE_BITVEC_24:  bl = 24; break;
                case TYPE_BITVEC_25:  bl = 25; break;
                case TYPE_BITVEC_26:  bl = 26; break;
                case TYPE_BITVEC_27:  bl = 27; break;
                case TYPE_BITVEC_28:  bl = 28; break;
                case TYPE_BITVEC_29:  bl = 29; break;
                case TYPE_BITVEC_30:  bl = 30; break;
                case TYPE_BITVEC_31:  bl = 31; break;
                case TYPE_BITVEC_32:  bl = 32; break;
#ifdef COMMON
                case TYPE_STRUCTURE:
                    if (elt(u, 0) == package_symbol)
                    {   outprefix(blankp, 3);
                        putc_stream('#', active_stream);
                        putc_stream('P', active_stream);
                        putc_stream(':', active_stream);
                        u = elt(u, 8);  // The name of the package
                        blankp = 0;
                        goto restart;
                    }
                    // Drop through
#else
                case TYPE_STRUCTURE:
                    std::sprintf(my_buff, "[e-vector:%.8lx]",
                                 static_cast<long>(static_cast<uint32_t>(u)));
                    goto print_my_buff;

#endif
                case TYPE_ARRAY:
#ifdef COMMON
                {   LispObject dims = elt(u, 1);
// I suppose that really I need to deal with non-simple bitvectors too.
// And generally get Common Lisp style array printing "right".
                    if (consp(dims) && !consp(cdr(dims)) &&
                        elt(u, 0) == string_char_sym)
                    {   len = int_of_fixnum(car(dims));
                        dims = elt(u, 5);   // Fill pointer
                        if (is_fixnum(dims)) len = int_of_fixnum(dims);
                        u = elt(u, 2);
// The demand here is that the object within the non-simple-string was
// a simple string, so I can restart printing to deal with it. This will
// not support strings that were over-large so got represented in
// chunks. Tough luck about that for now!
                        h = TYPE_STRING_1;
                        goto print_non_simple_string;
                    }
                }
                    // Drop through
#endif
                case TYPE_SIMPLE_VEC:
                case TYPE_OBJECT:
//              case TYPE_OLDHASH:
                case TYPE_HASH:
                case TYPE_HASHX:
                case TYPE_INDEXVEC:
                {
#ifndef COMMON
                    if (type_of_header(h) == TYPE_SIMPLE_VEC)
                    {   outprefix(blankp, 1);
                        putc_stream('[', active_stream);
                    }
                    else
#endif
                        if (type_of_header(h) == TYPE_STRUCTURE)
                        {   outprefix(blankp, 3);
                            putc_stream('#', active_stream); putc_stream('S', active_stream);
                            putc_stream('(', active_stream);
                        }
                        else if (// type_of_header(h) == TYPE_OLDHASH ||
                            type_of_header(h) == TYPE_HASH ||
                            type_of_header(h) == TYPE_HASHX)
                        {   int ch = 'H';
                            if (type_of_header(h) == TYPE_HASH) ch = 'H';
                            else if (type_of_header(h) == TYPE_HASHX) ch = 'h';
                            outprefix(blankp, 3);
                            putc_stream('#', active_stream); putc_stream(ch, active_stream);
                            putc_stream('(', active_stream);
                        }
                        else if (type_of_header(h) == TYPE_OBJECT)
                        {   outprefix(blankp, 3);
                            putc_stream('#', active_stream); putc_stream('O', active_stream);
                            putc_stream('(', active_stream);
                        }
                        else
                        {   outprefix(blankp, 2);
                            putc_stream('#', active_stream); putc_stream('(', active_stream);
                        }
#ifdef COMMON
                    if (qvalue(print_array_sym) == nil)
                    {   putc_stream('.', active_stream);
                        putc_stream('.', active_stream);
                        putc_stream('.', active_stream);
                    }
                    else
#endif
                        for (k=0; k<len; k+=CELL)
                        {   LispObject vv = *reinterpret_cast<LispObject *>(
                                                (reinterpret_cast<char *>(u) +
                                                 (CELL - TAG_VECTOR) + k));
                            internal_prin(vv, (k != 0) ? 1 : 0);
                        }
                    outprefix(false, 1);
#ifndef COMMON
                    if (type_of_header(h) == TYPE_SIMPLE_VEC) putc_stream(']',
                                active_stream);
                    else
#endif
                        putc_stream(')', active_stream);
                    return nil;
                }
                case TYPE_MIXED1:   // An experimental addition to CSL
                case TYPE_MIXED2:
                case TYPE_MIXED3:
                case TYPE_STREAM:
                {   outprefix(blankp, 3);
                    putc_stream('#', active_stream);
                    if (type_of_header(h) == TYPE_STREAM)
                        putc_stream('F', active_stream);
                    else if (type_of_header(h) == TYPE_MIXED1)
                        putc_stream('1', active_stream);
                    else if (type_of_header(h) == TYPE_MIXED2)
                        putc_stream('2', active_stream);
                    else putc_stream('3', active_stream);
                    putc_stream('[', active_stream);
#ifdef COMMON
                    if (qvalue(print_array_sym) == nil)
                    {   putc_stream('.', active_stream);
                        putc_stream('.', active_stream);
                        putc_stream('.', active_stream);
                    }
                    else
#endif
                    {   internal_prin(elt(u, 0), 0);
                        outprefix(false, 1);
                        internal_prin(elt(u, 1), 1);
                        outprefix(false, 1);
                        internal_prin(elt(u, 2), 1);
                    }
                    for (k=3*CELL; k<len; k+=CELL)
                    {   std::sprintf(my_buff, "%.8lx",
                                     static_cast<long>(
                                         *reinterpret_cast<LispObject *>(
                                             reinterpret_cast<char *>(u) +
                                             (CELL - TAG_VECTOR) + k)));
                        prin_buf(my_buff, true);
                    }
                    outprefix(false, 1);
                    putc_stream(']', active_stream);
                    return nil;
                }

                case TYPE_VEC8_1:
                case TYPE_VEC8_2:
                case TYPE_VEC8_3:
                case TYPE_VEC8_4:
                    outprefix(blankp, 4);
                    putc_stream('#', active_stream); putc_stream('V', active_stream);
                    putc_stream('8', active_stream); putc_stream('(', active_stream);
                    for (k=0; k<len; k++)
                    {   std::sprintf(my_buff, "%d", static_cast<int>(scelt(u, k)));
                        prin_buf(my_buff, k != 0);
                    }
                    outprefix(false, 1);
                    putc_stream(')', active_stream);
                    return nil;
                case TYPE_VEC16_1:
                case TYPE_VEC16_2:
                    len = length_of_hwordheader(h);
                    my_assert(len < CSL_PAGE_SIZE/2);
                    outprefix(blankp, 5);
                    putc_stream('#', active_stream); putc_stream('V', active_stream);
                    putc_stream('1', active_stream); putc_stream('6', active_stream);
                    putc_stream('(', active_stream);
                    for (k=0; k<len; k++)
                    {   std::sprintf(my_buff, "%d", static_cast<int>(helt(u, k)));
                        prin_buf(my_buff, k != 0);
                    }
                    outprefix(false, 1);
                    putc_stream(')', active_stream);
                    return nil;
                case TYPE_VEC32:
                    outprefix(blankp, 5);
                    putc_stream('#', active_stream); putc_stream('V', active_stream);
                    putc_stream('3', active_stream); putc_stream('2', active_stream);
                    putc_stream('(', active_stream);
                    len = len >> 2;
                    for (k=0; k<len; k++)
                    {   std::sprintf(my_buff, "%ld", static_cast<long>(ielt32(u,
                                     k)));
                        prin_buf(my_buff, k != 0);
                    }
                    outprefix(false, 1);
                    putc_stream(')', active_stream);
                    return nil;
                case TYPE_VECFLOAT32:
                    outprefix(blankp, 4);
                    putc_stream('#', active_stream); putc_stream('F', active_stream);
                    putc_stream('S', active_stream); putc_stream('(', active_stream);
                    len = len >> 2;
                    for (k=0; k<len; k++)
                    {   fp_sprint(my_buff, static_cast<double>(felt(u, k)),
                                  print_precision, 'f');
                        prin_buf(my_buff, k != 0);
                    }
                    outprefix(false, 1);
                    putc_stream(')', active_stream);
                    return nil;
                case TYPE_VECFLOAT64:
                    outprefix(blankp, 4);
                    putc_stream('#', active_stream); putc_stream('F', active_stream);
                    putc_stream('D', active_stream); putc_stream('(', active_stream);
                    len = (len-CELL)/8;
                    for (k=0; k<len; k++)
                    {   fp_sprint(my_buff, delt(u, k),
                                  print_precision, 'e');
                        prin_buf(my_buff, k != 0);
                    }
                    outprefix(false, 1);
                    putc_stream(')', active_stream);
                    return nil;
                default:goto error_case;
            }
// Here for bit-vectors
            outprefix(blankp, 2+8*(len-1)+bl);
            putc_stream('#', active_stream), putc_stream('*', active_stream);
            {   int z, q;
                for (k = 0; k < len-1; k++)
                {   z = ucelt(u, k);
                    for (q=0; q<8; q++)
                    {   if (z & 1) putc_stream('1', active_stream);
                        else putc_stream('0', active_stream);
                        z >>= 1;
                    }
                }
                if (len != 0)   // Empty bitvec
                {   z = ucelt(u, len-1);
                    for (q=0; q<bl; q++)
                    {   if (z & 1) putc_stream('1', active_stream);
                        else putc_stream('0', active_stream);
                        z >>= 1;
                    }
                }
            }
            return nil;
        }

// It seems probable that I could never get here, but this "return" is
// just in case, as a safety measure.
        return nil;

        case TAG_SYMBOL:
// When computing checksums with the "md5" function I count gensyms as being
// purely local to the current expression. The strange effect is that
//   (md5 (gensym))
// always gives the same result, even though the gensyms involved are
// different. But it is REASONABLY compatible with a view that I am forming
// a digest of a printed representation and is needed if digests are to
// be acceptably consistent across lisp images.
            if (escaped_printing & escape_checksum)
            {   if ((qheader(u) & (SYM_CODEPTR+SYM_ANY_GENSYM)) ==
                    SYM_ANY_GENSYM)
                {   LispObject al = stream_write_data(active_stream);
                    while (al != nil &&
                           car(car(al)) != u) al = cdr(al);
                    if (al == nil)
                    {   al = acons(u, fixnum_of_int(local_gensym_count),
                                   stream_write_data(active_stream));
                        local_gensym_count++;
                        stream_write_data(active_stream) = al;
                    }
                    al = cdr(car(al));
                    std::sprintf(my_buff, "#G%lx", static_cast<long>(int_of_fixnum(al)));
                    break;
                }
            }
            w = get_pname(u);    // allocates name for gensym if needbe
#ifdef COMMON
        tag_symbol:
#endif
            {   Header h = vechdr(w);
                int32_t slen = 0;
                int raised = 0;
#ifdef COMMON
                int pkgid = 0;  // No package marker needed
//  0    no package marker needed
//  1    display as #:xxx      (ie as a gensym)
//  2    display as :xxx       (ie in keyword package)
//  3    display as ppp:xxx    (external in its home package)
//  4    display as ppp::xxx   (internal in its home package)
                if (escaped_printing & escape_yes)
                {   if (!is_symbol(u)) pkgid = 0;  // Support for a HACK
                    else if (qpackage(u) == nil) pkgid = 1; // gensym
                    else if (qpackage(u) == qvalue(keyword_package)) pkgid = 2;
                    else if (qpackage(u) == CP) pkgid = 0; // home is current
                    else
                    {   pkgid = 3;
                        k = packflags_(CP);
                        if (k != 0 && k <= SYM_IN_PKG_COUNT)
                        {   k = ((int32_t)1) << (k+SYM_IN_PKG_SHIFT-1);
                            if (k & qheader(u)) pkgid = 0;
                        }
                        else k = 0;
                        if (pkgid != 0)
                        {   RealSave save1(THREADARG w);
                            w = Lfind_symbol_1(env, w);
                            errexit();
                            if (mv_2 != nil && w == u)
                            {   pkgid = 0;
// Here I update the cache it that keeps telling me that the symbol is
// is "available" in the package that is current at present. I guess that
// I need to clear this bit if I unintern or otherwise mess around with
// package structures.
                                qheader(u) |= k;
                            }
                            else if (qheader(u) & SYM_EXTERN_IN_HOME) pkgid = 3;
                            else pkgid = 4;
                            save1.restore(w);
                        }
                    }
                }
#endif
                len = length_of_byteheader(h);  // counts in bytes
                my_assert(len>=CELL && len < CSL_PAGE_SIZE);
                lenchars = 0;
// Now see how many characters that is, allowing for utf-8 encoding
                for (k=0; k<(len-CELL); k++)
                    if ((celt(w, k) & 0xc0) != 0x80) lenchars++;
// When I come to print things I will assume that I want them re-readable
// with values of !*raise and !*lower as in effect when the printing took
// place, and insert escape characters accordingly.  I optimise the case
// of printing without any effects...
                if (!(escaped_printing &
                      (escape_yes | escape_fold_down |
                       escape_fold_up | escape_capitalize)))
                {   u = w;
                    len -= CELL;
#ifdef COMMON
                    switch (pkgid)
                    {   case 1: outprefix(blankp, lenchars+2);
                            putc_stream('#', active_stream);
                            putc_stream(':', active_stream);
                            break;
                        case 2: outprefix(blankp, lenchars+1);
                            putc_stream(':', active_stream);
                            break;
                        case 3:
                        case 4:
// The issue of line breaks is maybe horrid here! I probably need to
// assess the print width of both the package name and the basic
// part of the name somewhere around here.
                            internal_prin(packname_(qpackage(u)), blankp | 2);
                            putc_stream(':', active_stream);
                            if (pkgid == 4) putc_stream(':', active_stream);
                            break;
                        default:outprefix(blankp, lenchars);
                            break;
                    }
#else
                    outprefix(blankp, lenchars);
#endif
                    for (k = 0; k < len; k++)
                    {   int ch = ucelt(u, k);
// Specially for the benefit of "tmprint.red" I arrange to switch off
// line-wrapping if I have a "\x02" character but switch it back on after
// "\x05". I should probably also restore things to a normal state on any
// exception/backtrace.
                        if (ch == 2) tmprint_flag = 1;
// The next is pretty much a horrible fudge, but I believe that people
// might only be using prin2 on an end-of-file character by accident and
// my internal representation is not a valid utf-8 packing of a codepoint
// in the Unicode range, so putting a textual form that people might
// at least recognise is perhaps kinder.
                        if (ch == 0xf7 &&
                            ucelt(u, k+1) == 0xbf &&
                            ucelt(u, k+2) == 0xbf &&
                            ucelt(u, k+3) == 0xbf)
                        {   putc_stream('$', active_stream);
                            putc_stream('E', active_stream);
                            putc_stream('O', active_stream);
                            putc_stream('F', active_stream);
                            putc_stream('$', active_stream);
                            k += 3;
                        }
                        else
                            putc_stream(ch, active_stream);
                        if (ch == 5) tmprint_flag = 0;
                    }
                }
                else
// Now I have prin1 rather than prin2, or prin2 but with case folding.
// thus the fun really begins.
                {   int extralen = 0;
                    if (qvalue(lower_symbol) != nil) raised = -1;
                    else if (qvalue(raise_symbol) != nil) raised = 1;
                    u = w;
                    len -= CELL;
// A horrid case here - digits are special at the start of names so need
// escaping with a "!" there even though they do not within the body of the
// symbol. In Stanndard Lisp the same is true for "_" and in Common Lisp
// for ".".
                    if (len > 0)
                    {   int ch = celt(u, 0);
                        if (escaped_printing & escape_yes &&
                            (std::isdigit(static_cast<unsigned char>(ch))
#ifdef COMMON
                             || (ch=='.')
#else
                             || (ch=='_')
#endif
                            )) extralen++;
                    }
// /*
// Again here I should perhaps take a view about linelength and
// symbols with tabs in their names... At present I do not. Anyway I need a
// first scan of the material to assess how many character positions will
// be needed when I print it.
                    for (k = 0; k < len; k++)
                    {   int ch = celt(u, k);
// If I have escape_yes set then I will map multibyte sequences onto
// #xxxx; or #xxxxxx; using 5 or 7 extra characters. If the only reason
// I am here is because of case folding I will leave extended characters
// alone.
                        if ((ch & 0xc0) == 0x80) continue;
                        else if ((ch & 0xe0) == 0xc0 &&
                                 (escaped_printing & escape_yes)) slen += 5, extralen++;
                        else if ((ch & 0xf0) == 0xe0 &&
                                 (escaped_printing & escape_yes)) slen += 5, extralen++;
                        else if ((ch & 0x80) != 0 &&
                                 (escaped_printing & escape_yes)) slen += 7, extralen++;
                        else if ((escaped_printing & escape_yes) &&
                                 !(escaped_printing &
                                   (escape_fold_down |
                                    escape_fold_up |
                                    escape_capitalize)) &&
#ifdef COMMON
                                 (ch=='.' || ch=='\\' || ch=='|') ||
#endif
// Here ch is certain to be in the range u+0000 to u+007f. Since I am
// rendering all characters over u+007f as escape sequences and all have an
// escape character prefix already there is no extra work needed to cover
// case folding for any of them. Whew. Well that depends on it being the case
// that case folding never moves something from the up to u+ffff up to
// the u+10000 and above range (or vice versa).
                                 (!is_constituent(ch) ||
#ifdef COMMON
                                  (ch=='.' || ch=='\\' || ch=='|' || ch==':') ||
#endif
                                  (raised < 0 && std::isupper(static_cast<unsigned char>(ch))) ||
                                  (raised > 0 &&
                                   std::islower(static_cast<unsigned char>(ch))))) extralen++;
                        slen++;
                    }
#ifdef COMMON
// The |xxx| notation is where the "2" here comes from, but that does not
// make full allowance for names with '\\' in them. Tough! But view that
// as yet another place where the code could need upgrading.
//
// here slen is the number of characters that will be used to display the
// printname itself, extralen is the number of "!" characters that Standard
// Lisp mode would use. If extralen is non zero I will need to use "|"
// notation here in Common Lisp mode.
                    if (extralen != 0) extralen = 2;
                    switch (pkgid)
                    {   case 1: outprefix(blankp, slen+extralen+2);
                            putc_stream('#', active_stream);
                            putc_stream(':', active_stream);
                            break;
                        case 2: outprefix(blankp, slen+extralen+1);
                            putc_stream(':', active_stream);
                            break;
                        case 3:
                        case 4: internal_prin(packname_(qpackage(u)), blankp | 2);
                            putc_stream(':', active_stream);
                            if (pkgid == 4) putc_stream(':', active_stream);
                            break;
                        default:outprefix(blankp, len);
                            break;
                    }
#else
                    outprefix(blankp, slen+extralen);
#endif
#ifdef COMMON
                    if (extralen != 0) putc_stream('|', active_stream);
#endif
// I need to deal with the first character of the name specially... but
// only if it is one of the magic characters that needs special escaping at
// the start of a name but not otherwise! So I will detect such cases and
// if necessary emit a "!" then the normal loop will do eveything else
// happily. Note that in Common Lisp mode there are no special cases here
// if I am going to display exotic names enclosed in vertical bars.
// I am glad that none of "_" and "0" to "9" impact on case folding or
// utf-8 encoding!
#ifndef COMMON
                    if (len > 0)
                    {   int ch = celt(u, 0);
                        if (ch == '_' ||
                            (ch >= '0' && ch <= '9'))
                            putc_stream(ESCAPE_CHAR, active_stream);
                    }
#endif
// Now display the characters that make up the name.
                    for (k = 0; k < len; k++)
                    {   int ch = ucelt(u, k);
#ifdef COMMON
                        if (ch == '\\' || ch=='|')
                            putc_stream(ESCAPE_CHAR, active_stream);
#else
// If I am case folding then I hope I am not also putting in escape
// marks. Well at present I will NEVER combine escape_fold_xxx with
// escape_yes, so I am safe here!
                        if (!(escaped_printing &
                              (escape_fold_down | escape_fold_up |
                               escape_capitalize)) &&
                            (ch > 0x7f ||
                             !is_constituent(ch) ||
                             (raised < 0 && std::isupper(static_cast<unsigned char>(ch))) ||
                             (raised > 0 && std::islower(static_cast<unsigned char>(ch)))))
                            putc_stream(ESCAPE_CHAR, active_stream);
#endif
// If I am case-folding I may need to extract an utf-8 multi-byte
// sequence, case fold and then display it. And since I am doing
// prin1 then if I am not exploding I need to display multi-byte
// objects as escape sequences using "#".
                        if (ch >= 0xc0)
                        {   int32_t n = 0;
                            if ((ch & 0xe0) == 0xc0) // 2 byte
                            {   n = ch & 0x1f;
                                k++;
                                ch = celt(u, k);
                                n = (n << 6) | (ch & 0x3f);
                                if (escaped_printing & escape_fold_down)
                                    n = std::towlower(n);
                                else if (escaped_printing & escape_fold_up)
                                    n = std::towupper(n);
                                if ((escaped_printing & escape_yes) &&
                                    !(escaped_printing & escape_exploding))
                                {   putc_stream('#', active_stream);
// This first digit is very often redundant here
                                    putc_stream(hexdig[(n>>12)&0xf], active_stream);
                                    putc_stream(hexdig[(n>>8)&0xf], active_stream);
                                    putc_stream(hexdig[(n>>4)&0xf], active_stream);
                                    putc_stream(hexdig[n&0xf], active_stream);
                                    putc_stream(';', active_stream);
                                }
                                else putc_utf8(n);
                            }
                            else if ((ch & 0xf0) == 0xe0) // 3 byte
                            {   n = ch & 0x0f;
                                k++;
                                ch = celt(u, k);
                                n = (n << 6) | (ch & 0x3f);
                                k++;
                                ch = celt(u, k);
                                n = (n << 6) | (ch & 0x3f);
                                if (escaped_printing & escape_fold_down)
                                    n = std::towlower(n);
                                else if (escaped_printing & escape_fold_up)
                                    n = std::towupper(n);
                                if ((escaped_printing & escape_yes) &&
                                    !(escaped_printing & escape_exploding))
                                {   putc_stream('#', active_stream);
                                    putc_stream(hexdig[(n>>12)&0xf], active_stream);
                                    putc_stream(hexdig[(n>>8)&0xf], active_stream);
                                    putc_stream(hexdig[(n>>4)&0xf], active_stream);
                                    putc_stream(hexdig[n&0xf], active_stream);
                                    putc_stream(';', active_stream);
                                }
                                else putc_utf8(n);
                            }
                            else // assume 4 byte
                            {   n = ch & 0x07;
                                k++;
                                ch = celt(u, k);
                                n = (n << 6) | (ch & 0x3f);
                                k++;
                                ch = celt(u, k);
                                n = (n << 6) | (ch & 0x3f);
                                k++;
                                ch = celt(u, k);
                                n = (n << 6) | (ch & 0x3f);
// When case folding if the code-point is beyond U+ffff and I am on a machine
// where sizeof(wchar_t) is 2 (eg Windows) I will not case fold. Gosh that
// seems an obscure situation!
                                if (sizeof(wchar_t) == 4 || n < 0x10000)
                                {   if (escaped_printing & escape_fold_down)
                                        n = std::towlower(n);
                                    else if (escaped_printing & escape_fold_up)
                                        n = std::towupper(n);
                                }
                                if ((escaped_printing & escape_yes) &&
                                    !(escaped_printing & escape_exploding))
                                {   putc_stream('#', active_stream);
                                    putc_stream(hexdig[(n>>20)&0xf], active_stream);
                                    putc_stream(hexdig[(n>>16)&0xf], active_stream);
                                    putc_stream(hexdig[(n>>12)&0xf], active_stream);
                                    putc_stream(hexdig[(n>>8)&0xf], active_stream);
                                    putc_stream(hexdig[(n>>4)&0xf], active_stream);
                                    putc_stream(hexdig[n&0xf], active_stream);
                                    putc_stream(';', active_stream);
                                }
                                else putc_utf8(n);
                            }
                        }
                        else
                        {   if (escaped_printing & escape_fold_down)
                                ch = std::tolower(ch);
                            else if (escaped_printing & escape_fold_up)
                                ch = std::toupper(ch);
                            putc_stream(ch, active_stream);
                        }
                    }
#ifdef COMMON
                    if (extralen != 0) putc_stream('|', active_stream);
#endif
                }
            }
            return nil;

        case TAG_BOXFLOAT:
            switch (type_of_header(flthdr(u)))
            {   case TYPE_SINGLE_FLOAT:
// The casts to "uint32_t *" here break the strict aliasing rules. If I was
// more cautious I would use a union, which (I believe) would cause gcc (at
// least) to guarantee to treat me kindly despite this. But even with that
// I would be relying on behaviour not blessed by the current C++ standards.
                    if (escaped_printing & escape_checksum)
                    {   int32_t v = intfloat32_t_val(u);
                        std::sprintf(my_buff, "@F%.8x", v);
                    }
                    else if (escaped_printing & escape_hex)
                    {   uint32_t *p = (uint32_t *)&single_float_val(u);
                        std::sprintf(my_buff, "{%.8" PRIx32 ":%#.8g}",
                                     p[0], static_cast<double>(single_float_val(u)));
                    }
                    else if (escaped_printing & escape_octal)
                    {   uint32_t *p = (uint32_t *)&double_float_val(u);
                        std::sprintf(my_buff, "{%.11" PRIo32 ":%#.8g}",
                                     p[0], static_cast<double>(single_float_val(u)));
                    }
                    else fp_sprint(my_buff,
                                       static_cast<double>(single_float_val(u)), print_precision, 'f');
                    break;
                case TYPE_DOUBLE_FLOAT:
// Hexadecimal printing of floating point numbers is only provided for
// here to help with nasty low-level debugging.  The output will not be
// directly re-readable.
                    if (escaped_printing & escape_checksum)
                    {   int64_t v = intfloat64_t_val(u);
                        std::sprintf(my_buff, "@F%.8" PRIx64, v);
                    }
                    else if (escaped_printing & escape_hex)
                    {   uint32_t *p = (uint32_t *)&double_float_val(u);
                        std::sprintf(my_buff,
                                     "{%.8" PRIx32 "/%.8" PRIx32 ":%#.15g}",
#ifdef LITTLEENDIAN
                                     p[1], p[0], static_cast<double>(double_float_val(u)));
#else
                                     p[0], p[1], static_cast<double>(double_float_val(u)));
#endif
                    }
                    else if (escaped_printing & escape_octal)
                    {   uint32_t *p = (uint32_t *)&double_float_val(u);
                        std::sprintf(my_buff, "{%.11" PRIo32 "/%.11" PRIo32 ":%#.8g}",
#ifdef LITTLEENDIAN
                                     p[1], p[0], static_cast<double>(double_float_val(u)));
#else
                                     p[0], p[1], static_cast<double>(double_float_val(u)));
#endif
                    }
                    else fp_sprint(my_buff, double_float_val(u),
                                       print_precision, 'e');
                    break;
#ifdef HAVE_SOFTFLOAT
                case TYPE_LONG_FLOAT:
                    if (escaped_printing & escape_checksum)
                    {   int64_t v0 = intfloat128_t_val0(u);
                        int64_t v1 = intfloat128_t_val1(u);
#ifdef LITTLEENDIAN
                        std::sprintf(my_buff, "@F%.8" PRIx64 "/%" PRIx64, v1, v0);
#else
                        std::sprintf(my_buff, "@F%.8" PRIx64 "/%" PRIx64, v0, v1);
#endif
                    }
                    else if (escaped_printing & escape_hex)
                    {   uint32_t *p = (uint32_t *)&long_float_val(u);
                        char *o = my_buff;
#ifdef LITTLEENDIAN
                        o += std::sprintf(o, "{%.8" PRIx32, p[3]);
                        o += std::sprintf(o, "/%.8" PRIx32, p[2]);
                        o += std::sprintf(o, "/%.8" PRIx32, p[1]);
                        o += std::sprintf(o, "/%.8" PRIx32, p[0]);
#else
                        o += std::sprintf(o, "{%.8" PRIx32, p[0]);
                        o += std::sprintf(o, "/%.8" PRIx32, p[1]);
                        o += std::sprintf(o, "/%.8" PRIx32, p[2]);
                        o += std::sprintf(o, "/%.8" PRIx32, p[3]);
#endif
                        *o++ = ':';
                        o += f128M_sprint_G(o, 0, 34,
                                            reinterpret_cast<float128_t *>(
                                                &long_float_val(u)));
                        *o++ = '}';
                        *o = 0;
                    }
                    else if (escaped_printing & escape_octal)
                    {   uint32_t *p = (uint32_t *)&long_float_val(u);
                        char *o = my_buff;
#ifdef LITTLEENDIAN
                        o += std::sprintf(o, "{%.11" PRIo32, p[3]);
                        o += std::sprintf(o, "/%.11" PRIo32, p[2]);
                        o += std::sprintf(o, "/%.11" PRIo32, p[1]);
                        o += std::sprintf(o, "/%.11" PRIo32, p[0]);
#else
                        o += std::sprintf(o, "{%.11" PRIo32, p[0]);
                        o += std::sprintf(o, "/%.11" PRIo32, p[1]);
                        o += std::sprintf(o, "/%.11" PRIo32, p[2]);
                        o += std::sprintf(o, "/%.11" PRIo32, p[3]);
#endif
                        *o++ = ':';
                        o += f128M_sprint_G(o, 0, 34,
                                            reinterpret_cast<float128_t *>(
                                                &long_float_val(u)));
                        *o++ = '}';
                        *o = 0;
                    }
// I use an upper case "L" as an exponent marker in "long floats" because
// a lower case "l" looks too much like a "1" (ell vs one).
                    else fp_sprint128(my_buff, long_float_val(u),
                                          print_precision, 'L');
                    break;
#endif // HAVE_SOFTFLOAT
                default:
                    std::sprintf(my_buff, "?%p?", reinterpret_cast<void *>(u));
                    break;
            }
        float_print_tidyup:   // label to join in from short float printing
            break;

        case TAG_NUMBERS:
            if (is_bignum(u))
            {   if (escaped_printing & escape_hex)
                    print_bighexoctbin(u, 16, escape_width(escaped_printing),
                                       blankp,
                                       (escaped_printing & escape_nolinebreak) || tmprint_flag);
                else if (escaped_printing & escape_octal)
                    print_bighexoctbin(u, 8, escape_width(escaped_printing),
                                       blankp,
                                       (escaped_printing & escape_nolinebreak) || tmprint_flag);
                else if (escaped_printing & escape_binary)
                    print_bighexoctbin(u, 2, escape_width(escaped_printing),
                                       blankp,
                                       (escaped_printing & escape_nolinebreak) || tmprint_flag);
                else
                    print_bignum(u, blankp,
                                 (escaped_printing & escape_nolinebreak) || tmprint_flag);
                return nil;
            }
#ifdef ARITHLIB
            if (is_new_bignum(u))
            {   if (escaped_printing & escape_hex)
                    print_newbighexoctbin(u, 16, escape_width(escaped_printing),
                                          blankp,
                                          (escaped_printing & escape_nolinebreak) || tmprint_flag);
                else if (escaped_printing & escape_octal)
                    print_newbighexoctbin(u, 8, escape_width(escaped_printing),
                                          blankp,
                                          (escaped_printing & escape_nolinebreak) || tmprint_flag);
                else if (escaped_printing & escape_binary)
                    print_newbighexoctbin(u, 2, escape_width(escaped_printing),
                                          blankp,
                                          (escaped_printing & escape_nolinebreak) || tmprint_flag);
                else
                    print_newbignum(u, blankp,
                                    (escaped_printing & escape_nolinebreak) || tmprint_flag);
                return nil;
            }
#endif
            else if (is_ratio(u))
            {
// Here I have a line-break problem --- I do not measure the size of the
// denominator, and hence may well split a line between numerator and
// denominator.  This would be HORRID. I guess that the correct recipe will
// involve measuring the size of the denominator first... Let's not bother
// just at the moment.
                internal_prin(numerator(u), blankp);
                outprefix(false, 1);
                putc_stream('/', active_stream);
                internal_prin(denominator(u), 0);
                return nil;
            }
            else if (is_complex(u))
            {   outprefix(blankp, 3);
                putc_stream('#', active_stream), putc_stream('C', active_stream);
                putc_stream('(', active_stream);
                internal_prin(real_part(u), 0);
                internal_prin(imag_part(u), 1);
                outprefix(false, 1);
                putc_stream(')', active_stream);
                return nil;
            }
        // Else drop through to treat as an error
        default:
        error_case:
            std::sprintf(my_buff, "?%p?", reinterpret_cast<void *>(u));
            break;
    }
print_my_buff:
    {   const char *p = my_buff;
        int ch;
        outprefix(blankp, std::strlen(my_buff));
        while ((ch = *p++) != 0) putc_stream(ch, active_stream);
    }
    return nil;
}

LispObject prin(LispObject u)
{   escaped_printing = escape_yes;
    THREADID;
    Save save(THREADARG u);
    active_stream = qvalue(standard_output);
    if (!is_stream(active_stream)) active_stream = qvalue(terminal_io);
    if (!is_stream(active_stream)) active_stream = lisp_terminal_io;
    internal_prin(u, 0);
    save.restore(u);
    return u;
}

LispObject prin_to_terminal(LispObject u)
{   escaped_printing = escape_yes;
    active_stream = qvalue(terminal_io);
    if (!is_stream(active_stream)) active_stream = lisp_terminal_io;
    THREADID;
    ignore_error(internal_prin(u, 0));
    ensure_screen();
    return nil;
}

LispObject prin_to_stdout(LispObject u)
{   escaped_printing = escape_yes;
    active_stream = qvalue(standard_output);
    if (!is_stream(active_stream)) active_stream = lisp_standard_output;
    THREADID;
    ignore_error(internal_prin(u, 0));
    ensure_screen();
    return nil;
}

LispObject prin_to_error(LispObject u)
{   escaped_printing = escape_yes;
    active_stream = qvalue(error_output);
    if (!is_stream(active_stream)) active_stream = lisp_error_output;
    THREADID;
    ignore_error(internal_prin(u, 0));
    ensure_screen();
    return nil;
}

LispObject prin_to_trace(LispObject u)
{   escaped_printing = escape_yes;
    active_stream = qvalue(trace_output);
    if (!is_stream(active_stream)) active_stream = lisp_trace_output;
    THREADID;
    ignore_error(internal_prin(u, 0));
    ensure_screen();
    return nil;
}

// This is JUST for debugging. It prints a message then something (using
// radix 16), then a newline.
LispObject prinhex_to_trace(const char *msg, LispObject u)
{   int32_t c = other_write_action(WRITE_GET_INFO+WRITE_GET_COLUMN,
                                   qvalue(standard_output));
    escaped_printing = escape_yes+escape_hex;
    active_stream = qvalue(trace_output);
    if (!is_stream(active_stream)) active_stream = lisp_trace_output;
    if (c != 0) putc_stream('\n', active_stream);
    trace_printf("## %s: ", msg);
    THREADID;
    ignore_error(internal_prin(u, escape_yes+escape_hex));
    putc_stream('\n', active_stream);
    ensure_screen();
    return nil;
}

LispObject prin_to_debug(LispObject u)
{   escaped_printing = escape_yes;
    active_stream = qvalue(debug_io);
    if (!is_stream(active_stream)) active_stream = lisp_debug_io;
    THREADID;
    ignore_error(internal_prin(u, 0));
    ensure_screen();
    return nil;
}

LispObject prin_to_query(LispObject u)
{   escaped_printing = escape_yes;
    active_stream = qvalue(query_io);
    if (!is_stream(active_stream)) active_stream = lisp_query_io;
    THREADID;
    ignore_error(internal_prin(u, 0));
    ensure_screen();
    return nil;
}

LispObject loop_print_stdout(LispObject o)
{   int32_t sx = exit_reason;
    one_arg *f;
    LispObject lp = qvalue(traceprint_symbol);
    if (lp == nil || lp == unset_var) lp = prinl_symbol;
// There is a potential delicacy around here if and when prinl gets compiled
// into C. At the very start of a run when CSL does a cold start it could
// have a definition but its vector-of-literals might not have been loaded.
// If it gets called at that stage there could be a disaster, So as a small
// amount of extra protection only relevant to me when I build initial images
// based on a cold-start I will try to avoid calling it then and fall back
// to using the simpler version of prin.
    if (!is_symbol(lp) ||
        (f = qfn1(lp)) == undefined_1 ||
        (f != bytecoded_1 && !is_vector(qenv(lp)))) prin_to_stdout(o);
    else (*f)(lp, o);
    exit_reason = sx;
    return nil;
}

LispObject loop_print_error(LispObject o)
{   LispObject w = qvalue(standard_output);
    THREADID;
    Save save(THREADARG w);
    if (is_stream(qvalue(error_output)))
        setvalue(standard_output, qvalue(error_output));
    loop_print_stdout(o);
    save.restore(w);
    setvalue(standard_output, w);
#ifdef COMMON
// This is to help me debug in the face of low level system crashes
    if (spool_file) std::fflush(spool_file);
#endif
    return nil;
}

LispObject loop_print_trace(LispObject o)
{   THREADID;
    STACK_SANITY;
    LispObject w = qvalue(standard_output);
    Save save(THREADARG w);
    if (is_stream(qvalue(trace_output)))
        setvalue(standard_output, qvalue(trace_output));
    loop_print_stdout(o);
    save.restore(w);
    setvalue(standard_output, w);
#ifdef COMMON
// This is to help me debug in the face of low level system crashes
    if (spool_file) std::fflush(spool_file);
#endif
    return nil;
}

LispObject loop_print_debug(LispObject o)
{   LispObject w = qvalue(standard_output);
    THREADID;
    Save save(THREADARG w);
    if (is_stream(qvalue(debug_io)))
        setvalue(standard_output, qvalue(debug_io));
    loop_print_stdout(o);
    save.restore(w);
    setvalue(standard_output, w);
    return nil;
}

LispObject loop_print_query(LispObject o)
{   LispObject w = qvalue(standard_output);
    THREADID;
    Save save(THREADARG w);
    if (is_stream(qvalue(query_io)))
        setvalue(standard_output, qvalue(query_io));
    loop_print_stdout(o);
    save.restore(w);
    setvalue(standard_output, w);
    return nil;
}

LispObject loop_print_terminal(LispObject o)
{   LispObject w = qvalue(standard_output);
    THREADID;
    Save save(THREADARG w);
    if (is_stream(qvalue(terminal_io)))
        setvalue(standard_output, qvalue(terminal_io));
    loop_print_stdout(o);
    save.restore(w);
    setvalue(standard_output, w);
    return nil;
}

LispObject prinraw(LispObject u)
{   Header h;
    size_t len;
    char b[40], *p;
    THREADID;
    Save save(THREADARG u);
    active_stream = qvalue(standard_output);
    if (!is_stream(active_stream)) active_stream = qvalue(terminal_io);
    if (!is_stream(active_stream)) active_stream = lisp_terminal_io;
    if (is_fixnum(u))
    {
// The following line wants to print a long-long 64-bit value but the
// format specifier %.16llx is not universally available, so I use two 32-bit
// chunks.
        unsigned long long w = static_cast<unsigned long long>(u);
        unsigned long long hi = w >> 32, lo = w;
        std::sprintf(b, "%.8x%.8x", static_cast<int>(hi),
                     static_cast<int>(lo));
        for (p=b; *p!=0; p++) putc_stream(*p, active_stream);
    }
    if (is_numbers(u) && type_of_header(h = numhdr(u)) == TYPE_BIGNUM)
    {   len = length_of_header(h);
        my_assert(len>=CELL && len < CSL_PAGE_SIZE);
        for (size_t i=CELL; i<len; i+=4)
        {   std::sprintf(b, "%.8x ", (uint32_t)bignum_digits(u)[(i-CELL)/4]);
            for (p=b; *p!=0; p++) putc_stream(*p, active_stream);
        }
    }
#ifdef ARITHLIB
    else if (is_numbers(u) && type_of_header(h) == TYPE_NEW_BIGNUM)
    {   len = length_of_header(h);
        my_assert(len>=8 && len < CSL_PAGE_SIZE);
        for (size_t i=8; i<len; i+=8)
        {   std::sprintf(b, "%.16" PRIx64 " ",
                         *(uint64_t *)(reinterpret_cast<char *>(u) - TAG_NUMBERS + i));
            for (p=b; *p!=0; p++) putc_stream(*p, active_stream);
        }
    }
#endif // ARITHLIB
    else
    {   for (size_t i=0; i<11; i++)
            putc_stream("<NotNumber>"[i], active_stream);
    }
    save.restore(u);
    return u;
}

static LispObject prinhex(LispObject u, int n)
{   escaped_printing = escape_yes+escape_hex+((n & 0x3f)<<8);
    THREADID;
    Save save(THREADARG u);
    active_stream = qvalue(standard_output);
    if (!is_stream(active_stream)) active_stream = qvalue(terminal_io);
    if (!is_stream(active_stream)) active_stream = lisp_terminal_io;
    internal_prin(u, 0);
    save.restore(u);
    return u;
}

static LispObject prinoctal(LispObject u, int n)
{   escaped_printing = escape_yes+escape_octal+((n & 0x3f)<<8);
    THREADID;
    Save save(THREADARG u);
    active_stream = qvalue(standard_output);
    if (!is_stream(active_stream)) active_stream = qvalue(terminal_io);
    if (!is_stream(active_stream)) active_stream = lisp_terminal_io;
    internal_prin(u, 0);
    save.restore(u);
    return u;
}

static LispObject prinbinary(LispObject u, int n)
{   escaped_printing = escape_yes+escape_binary+((n & 0x3f)<<8);
    THREADID;
    Save save(THREADARG u);
    active_stream = qvalue(standard_output);
    if (!is_stream(active_stream)) active_stream = qvalue(terminal_io);
    if (!is_stream(active_stream)) active_stream = lisp_terminal_io;
    internal_prin(u, 0);
    save.restore(u);
    return u;
}

LispObject princ(LispObject u)
{   escaped_printing = 0;
    THREADID;
    Save save(THREADARG u);
    active_stream = qvalue(standard_output);
    if (!is_stream(active_stream)) active_stream = qvalue(terminal_io);
    if (!is_stream(active_stream)) active_stream = lisp_terminal_io;
    internal_prin(u, 0);
    save.restore(u);
    return u;
}

LispObject print(LispObject u)
{   LispObject stream = qvalue(standard_output);
    THREADID;
    Save save(THREADARG u);
    escaped_printing = escape_yes;
    if (!is_stream(stream)) stream = qvalue(terminal_io);
    if (!is_stream(stream)) stream = lisp_terminal_io;
    active_stream = stream;
    putc_stream('\n', stream);
    internal_prin(u, 0);
    save.restore(u);
    return u;
}

LispObject printc(LispObject u)
{   LispObject stream = qvalue(standard_output);
    THREADID;
    Save save(THREADARG u);
    escaped_printing = 0;
    if (!is_stream(stream)) stream = qvalue(terminal_io);
    if (!is_stream(stream)) stream = lisp_terminal_io;
    active_stream = stream;
    putc_stream('\n', stream);
    internal_prin(u, 0);
    save.restore(u);
    return u;
}

LispObject freshline_stdout()
{   LispObject stream = qvalue(standard_output);
    if (!is_stream(stream)) stream = qvalue(terminal_io);
    if (!is_stream(stream)) stream = lisp_terminal_io;
    if (other_write_action(WRITE_GET_INFO+WRITE_GET_COLUMN,
                           stream) != 0)
        putc_stream('\n', stream);
    return nil;
}


LispObject freshline_trace()
{   if (other_write_action(WRITE_GET_INFO+WRITE_GET_COLUMN,
                           qvalue(trace_output)) != 0)
        putc_stream('\n', qvalue(trace_output));
    return nil;
}

LispObject freshline_debug()
{   if (other_write_action(WRITE_GET_INFO+WRITE_GET_COLUMN,
                           qvalue(debug_io)) != 0)
        putc_stream('\n', qvalue(debug_io));
    return nil;
}

static int char_to_list_state = 0;

int char_to_list(int c, LispObject f)
{   LispObject k;
    THREADID;
// Codes that are large have to be converted back into utf-8 form.
// Characters in the range 0 to u+00ff are kept cached in a vector
// so that lookup is especially fast. Beyond that involves checking the
// oblist and (if necessary) creating a fresh symbol.
    c &= 0xff;
    if (c <= 0x7f);  // Simple character
    else if ((c & 0xc0) == 0x80) // Continuation byte
    {   char_to_list_state = (char_to_list_state << 6) | (c & 0x3f);
        if (char_to_list_state >= 0) return 0;
        c = char_to_list_state & 0x001fffff;
    }
    else if ((c & 0xe0) == 0xc0)
    {   char_to_list_state = (0x80000000u >> 6) + (c & 0x1f);
        return 0;
    }
    else if ((c & 0xf0) == 0xe0)
    {   char_to_list_state = (0x80000000u >> 12) + (c & 0x0f);
        return 0;
    }
    else
    {   char_to_list_state = (0x80000000u >> 18) + (c & 0x07);
        return 0;
    }
    if (c > 0xff)
    {   int len;
        if (c <= 0x7ff)
        {   celt(boffo, 0) = 0xc0 + (c >> 6);
            celt(boffo, 1) = 0x80 + (c & 0x3f);
            len = 2;
        }
        else if (c <= 0xffff)
        {   celt(boffo, 0) = 0xe0 + (c >> 12);
            celt(boffo, 1) = 0x80 + ((c >> 6) & 0x3f);
            celt(boffo, 2) = 0x80 + (c & 0x3f);
            len = 3;
        }
        else
        {   celt(boffo, 0) = 0xf0 + (c >> 18);
            celt(boffo, 1) = 0x80 + ((c >> 12) & 0x3f);
            celt(boffo, 2) = 0x80 + ((c >> 6) & 0x3f);
            celt(boffo, 3) = 0x80 + (c & 0x3f);
            len = 4;
        }
        {   Save save(THREADARG f);
            k = iintern(boffo, len, lisp_package, 0);
            save.restore(f);
        }
    }
    else
    {   k = elt(charvec, c);
        if (k == nil)
        {   int len;
            if (c <= 0x7f)
            {   celt(boffo, 0) = static_cast<char>(c);
                len = 1;
            }
            else
            {   celt(boffo, 0) = 0xc0 + (c>>6);
                celt(boffo, 1) = 0x80 + (c & 0x3f);
                len = 2;
            }
            {   Save save(THREADARG f);
// It could very well be that in Common Lisp I ought to generate a list of
// character objects here. As it is I hand back symbols, but I do take care
// that they are in the LISP package.
                k = iintern(boffo, len, lisp_package, 0);
                save.restore(f);
            }
            elt(charvec, c & 0xff) = k;
        }
    }
    {   Save save(THREADARG f);
        k = cons(k, stream_write_data(f));
        save.restore(f);
    }
    stream_write_data(f) = k;
    return 0;
}

static LispObject explode(LispObject u)
{   stream_write_data(lisp_work_stream) = nil;
    set_stream_write_fn(lisp_work_stream, char_to_list);
    set_stream_write_other(lisp_work_stream, write_action_list);
    active_stream = lisp_work_stream;
    internal_prin(u, 0);
    u = stream_write_data(lisp_work_stream);
    stream_write_data(lisp_work_stream) = nil;
    return nreverse(u);
}

static unsigned char checksum_buffer[64];
static int checksum_count;

int char_to_checksum(int c, LispObject)
{   checksum_buffer[checksum_count++] = static_cast<unsigned char>(c);
    if (checksum_count == sizeof(checksum_buffer))
    {   CSL_MD5_Update(checksum_buffer, sizeof(checksum_buffer));
        checksum_count = 0;
    }
    return 0;
}

void checksum(LispObject u)
{   escaped_printing = escape_yes+escape_nolinebreak+escape_checksum;
    set_stream_write_fn(lisp_work_stream, char_to_checksum);
    set_stream_write_other(lisp_work_stream, write_action_list); // sic
    active_stream = lisp_work_stream;
    CSL_MD5_Init();
    local_gensym_count = checksum_count = 0;
    internal_prin(u, 0);
    stream_write_data(lisp_work_stream) = nil;
    if (checksum_count != 0) CSL_MD5_Update(checksum_buffer, checksum_count);
}

// code_to_list is used by exploden and explodecn. Also by
// make-string-output-stream. I want it to collect a list of codes
// not bytes, but by the time I get here things have been utf-8 encoded,
// so I need to unwind that. Ugh.

static int32_t code_to_list_state = 0;

int code_to_list(int c, LispObject f)
{   LispObject k;
    stream_byte_pos(f)++;
    c &= 0xff;
    if (c <= 0x7f) k = c;  // Simple character
    else if ((c & 0xc0) == 0x80) // Continuation byte
    {   code_to_list_state = (code_to_list_state << 6) | (c & 0x3f);
        if (code_to_list_state >= 0) return 0;
        k = code_to_list_state & 0x001fffff;
    }
    else if ((c & 0xe0) == 0xc0)
    {   code_to_list_state = (0x80000000u >> 6) + (c & 0x1f);
        return 0;
    }
    else if ((c & 0xf0) == 0xe0)
    {   code_to_list_state = (0x80000000u >> 12) + (c & 0x0f);
        return 0;
    }
    else
    {   code_to_list_state = (0x80000000u >> 18) + (c & 0x07);
        return 0;
    }
    THREADID;
    {   Save save(THREADARG f);
        k = cons(fixnum_of_int(k), stream_write_data(f));
        save.restore(f);
    }
    stream_write_data(f) = k;
// In this case the "position" must not pay attention to
// tabs or newlines.
    stream_char_pos(f)++;
    return 0;
}

static LispObject exploden(LispObject u)
{   stream_write_data(lisp_work_stream) = nil;
    set_stream_write_fn(lisp_work_stream, code_to_list);
    set_stream_write_other(lisp_work_stream, write_action_list);
    active_stream = lisp_work_stream;
    internal_prin(u, 0);
    u = stream_write_data(lisp_work_stream);
    stream_write_data(lisp_work_stream) = nil;
    return nreverse(u);
}

// To cope with the needs of windowed implementations I am (unilaterally)
// altering the specification of the LINELENGTH function that I implement.
// The new rules are:
//    (linelength nil)    returns current width, always an integer
//    (linelength n)      sets new with to n, returns old
//    (linelength T)      sets new width to default for current stream,
//                        and returns old.
// the "old" value returned in the last two cases will often be the current
// linelength as returnd by (linelength nil), but it CAN be the value T.
// On some windowed systems after (linelength T) the value of (linelength nil)
// will track changes that the user makes by re-sizing the main output
// window on their screen. The linelength function inspects and sets
// information for the current standard output stream, and separate
// record is kept of the linelength associated with each stream.

LispObject Llinelength(LispObject env, LispObject a)
{   int32_t oll;
    LispObject stream = qvalue(standard_output);
    if (!is_stream(stream)) stream = qvalue(terminal_io);
    if (!is_stream(stream)) stream = lisp_terminal_io;
    if (a == nil)
        oll = other_write_action(WRITE_GET_INFO+WRITE_GET_LINE_LENGTH,
                                 stream);
    else if (a == lisp_true)
        oll = other_write_action(WRITE_SET_LINELENGTH_DEFAULT, stream);
    else if (!is_fixnum(a)) return aerror1("linelength", a);
    else
    {   oll = int_of_fixnum(a);
        if (oll < 10) oll = 10;
        oll = other_write_action(WRITE_SET_LINELENGTH | oll, stream);
    }
    if (oll == (int32_t)0x80000000) return onevalue(lisp_true);
    else return onevalue(fixnum_of_int(oll));
}

static LispObject Llinelength0(LispObject env)
{   return Llinelength(env, nil);
}

static void internal_check(LispObject original_a, LispObject a,
                           int depth, uint64_t path)
{   if (!is_cons(a)) return;
    if ((a & 0x7ffffff0) == 0)
    {   std::printf("Zero cons pointer at depth %d\n", depth);
        std::printf("Original a = %" PRIx64 " path = %" PRIx64 "\n",
                    static_cast<int64_t>(original_a), path);
        my_abort();
    }
    internal_check(original_a, car(a), depth+1, path<<1);
    internal_check(original_a, cdr(a), depth+1, (path<<1)+1);
}

LispObject Lcheck_list(LispObject env, LispObject a)
{   THREADID;
    Save save(THREADARG a);
    internal_check(a, a, 0, 0);
    save.restore(a);
    return onevalue(a);
}

LispObject Lprin(LispObject env, LispObject a)
{   THREADID;
    Save save(THREADARG a);
    escaped_printing = escape_yes;
    active_stream = qvalue(standard_output);
    if (!is_stream(active_stream)) active_stream = qvalue(terminal_io);
    if (!is_stream(active_stream)) active_stream = lisp_terminal_io;
    internal_prin(a, 0);
    save.restore(a);
    if (io_limit >= 0 && io_now > io_limit) resource_exceeded();
    return onevalue(a);
}

static LispObject Lprinraw(LispObject env, LispObject a)
{   THREADID;
    Save save(THREADARG a);
    prinraw(a);
    save.restore(a);
    if (io_limit >= 0 && io_now > io_limit) resource_exceeded();
    return onevalue(a);
}

static LispObject Lprinhex(LispObject env, LispObject a)
{   THREADID;
    Save save(THREADARG a);
    prinhex(a, 0);
    save.restore(a);
    if (io_limit >= 0 && io_now > io_limit) resource_exceeded();
    return onevalue(a);
}

static LispObject Lprinoctal(LispObject env, LispObject a)
{   THREADID;
    Save save(THREADARG a);
    prinoctal(a, 0);
    save.restore(a);
    if (io_limit >= 0 && io_now > io_limit) resource_exceeded();
    return onevalue(a);
}

static LispObject Lprinbinary(LispObject env, LispObject a)
{   THREADID;
    Save save(THREADARG a);
    prinbinary(a, 0);
    save.restore(a);
    if (io_limit >= 0 && io_now > io_limit) resource_exceeded();
    return onevalue(a);
}

static LispObject Lprinhex2(LispObject env, LispObject a,
                            LispObject b)
{   if (!is_fixnum(b)) return aerror1("prinhex", b);
    THREADID;
    Save save(THREADARG a);
    prinhex(a, int_of_fixnum(b));
    save.restore(a);
    if (io_limit >= 0 && io_now > io_limit) resource_exceeded();
    return onevalue(a);
}

static LispObject Lprinoctal2(LispObject env, LispObject a,
                              LispObject b)
{   if (!is_fixnum(b)) return aerror1("prinoctal", b);
    THREADID;
    Save save(THREADARG a);
    prinoctal(a, int_of_fixnum(b));
    save.restore(a);
    if (io_limit >= 0 && io_now > io_limit) resource_exceeded();
    return onevalue(a);
}

static LispObject Lprinbinary2(LispObject env, LispObject a,
                               LispObject b)
{   if (!is_fixnum(b)) return aerror1("prinbinary", b);
    THREADID;
    Save save(THREADARG a);
    prinbinary(a, int_of_fixnum(b));
    save.restore(a);
    if (io_limit >= 0 && io_now > io_limit) resource_exceeded();
    return onevalue(a);
}

LispObject Lposn(LispObject)
{   if (standard_output == nil) return fixnum_of_int(0);
    return onevalue(
        fixnum_of_int(
            other_write_action(WRITE_GET_INFO+WRITE_GET_COLUMN,
                qvalue(standard_output))));
}

LispObject Lposn_1(LispObject, LispObject stream)
{   if (!is_stream(stream)) stream = qvalue(terminal_io);
    if (!is_stream(stream)) stream = lisp_terminal_io;
    return onevalue(fixnum_of_int(
        other_write_action(WRITE_GET_INFO+WRITE_GET_COLUMN, stream)));
}

LispObject Llposn(LispObject)
{   return onevalue(fixnum_of_int(0));
}

// This does not do anything!
LispObject Lpagelength(LispObject, LispObject a)
{   return onevalue(a);
}

LispObject Lprinc_upcase(LispObject env, LispObject a)
{   THREADID;
    Save save(THREADARG a);
    escaped_printing = escape_fold_up;
    active_stream = qvalue(standard_output);
    if (!is_stream(active_stream)) active_stream = qvalue(terminal_io);
    if (!is_stream(active_stream)) active_stream = lisp_terminal_io;
    internal_prin(a, 0);
    save.restore(a);
    if (io_limit >= 0 && io_now > io_limit) resource_exceeded();
    return onevalue(a);
}

LispObject Lprinc_downcase(LispObject env, LispObject a)
{   THREADID;
    Save save(THREADARG a);
    escaped_printing = escape_fold_down;
    active_stream = qvalue(standard_output);
    if (!is_stream(active_stream)) active_stream = qvalue(terminal_io);
    if (!is_stream(active_stream)) active_stream = lisp_terminal_io;
    internal_prin(a, 0);
    save.restore(a);
    if (io_limit >= 0 && io_now > io_limit) resource_exceeded();
    return onevalue(a);
}

LispObject Lprinc(LispObject env, LispObject a)
{   THREADID;
    Save save(THREADARG a);
    escaped_printing = 0;
    active_stream = qvalue(standard_output);
    if (!is_stream(active_stream)) active_stream = qvalue(terminal_io);
    if (!is_stream(active_stream)) active_stream = lisp_terminal_io;
    internal_prin(a, 0);
    save.restore(a);
    if (io_limit >= 0 && io_now > io_limit) resource_exceeded();
    return onevalue(a);
}

LispObject Lprin2a(LispObject env, LispObject a)
{   THREADID;
    Save save(THREADARG a);
    escaped_printing = escape_nolinebreak;
    active_stream = qvalue(standard_output);
    if (!is_stream(active_stream)) active_stream = qvalue(terminal_io);
    if (!is_stream(active_stream)) active_stream = lisp_terminal_io;
    internal_prin(a, 0);
    save.restore(a);
    if (io_limit >= 0 && io_now > io_limit) resource_exceeded();
    return onevalue(a);
}

char memory_print_buffer[MAX_PROMPT_LENGTH];

int count_character(int c, LispObject f)
{   int n = stream_byte_pos(f);
// In bad cases the memory_print_buffer will expire part way through
// a multi-byte character. I will tidy that up somewhere else!
    if (n < MAX_PROMPT_LENGTH-1)
    {   memory_print_buffer[n] = static_cast<char>(c);
        memory_print_buffer[n+1] = 0;
    }
    stream_byte_pos(f) = n+1;
    if ((c & 0xc0) != 0x80) stream_char_pos(f)++;
    return 0;   // indicate success
}

LispObject Llengthc(LispObject env, LispObject a)
{
// This counts a TAB as having width 1. It counts the number of bytes
// used to print the argument.
    escaped_printing = escape_nolinebreak;
    set_stream_write_fn(lisp_work_stream, count_character);
    memory_print_buffer[0] = 0;
    set_stream_write_other(lisp_work_stream, write_action_list);
    stream_byte_pos(lisp_work_stream) = 0;
    stream_char_pos(lisp_work_stream) = 0;
    active_stream = lisp_work_stream;
    internal_prin(a, 0);
    return onevalue(fixnum_of_int(stream_byte_pos(lisp_work_stream)));
}


LispObject Lwidelengthc(LispObject env, LispObject a)
{
// Like lengthc but counts characters (by ignoring bytes that
//& are 10xxxxxx in binary).
    escaped_printing = escape_nolinebreak;
    set_stream_write_fn(lisp_work_stream, count_character);
    memory_print_buffer[0] = 0;
    set_stream_write_other(lisp_work_stream, write_action_list);
    stream_byte_pos(lisp_work_stream) = 0;
    stream_char_pos(lisp_work_stream) = 0;
    active_stream = lisp_work_stream;
    internal_prin(a, 0);
    return onevalue(fixnum_of_int(stream_char_pos(lisp_work_stream)));
}


LispObject Ldebug_print(LispObject env, LispObject a)
{   LispObject stream = qvalue(standard_output);
    Header h;
    size_t i, len;
    const char *p;
    if (!is_stream(stream)) stream = qvalue(terminal_io);
    if (!is_stream(stream)) stream = lisp_terminal_io;
    if (symbolp(a)) a = get_pname(a);
    if (!is_vector(a)) return Lprint(env, a);
    h = vechdr(a);
    if (!is_string_header(h)) return Lprint(env, a);
    len = length_of_byteheader(h) - CELL;
    my_assert(len < CSL_PAGE_SIZE);
    p = reinterpret_cast<const char *>(&celt(a, 0));
    THREADID;
    for (i=0; i<len; i++)
    {   Save save(THREADARG a);
        putc_stream(p[i], stream);
        save.restore(a);
        p = (const char  *)&celt(a, 0);
    }
    {   Save save(THREADARG a);
        putc_stream(':', stream);
        save.restore(a);
    }
    p = reinterpret_cast<const char *>(&celt(a, 0));
    for (; i<doubleword_align_up(len+CELL)-CELL; i++)
    {   int c = p[i] & 0xff;
        Save save(THREADARG a);
        if (c >= 0x80)
        {   putc_stream('+', stream);
            c &= 0x7f;
        }
        if (c < 0x20)
        {   putc_stream('^', stream);
            c += 0x40;
        }
        putc_stream(c, stream);
        save.restore(a);
        p = reinterpret_cast<const char *>(&celt(a, 0));
    }
    putc_stream('\n', stream);
    return onevalue(nil);
}

LispObject Lprint(LispObject env, LispObject a)
{   LispObject stream = qvalue(standard_output);
    if (!is_stream(stream)) stream = qvalue(terminal_io);
    if (!is_stream(stream)) stream = lisp_terminal_io;
    THREADID;
    Save save(THREADARG a);
#ifdef COMMON
    escaped_printing = escape_yes;
    active_stream = stream;
    putc_stream('\n', stream);
    internal_prin(a, 0);
#else
    escaped_printing = escape_yes;
    active_stream = stream;
    internal_prin(a, 0);
    putc_stream('\n', active_stream);
#endif
    save.restore(a);
    if (io_limit >= 0 && io_now > io_limit) resource_exceeded();
    return onevalue(a);
}

LispObject Lprintc(LispObject env, LispObject a)
{   LispObject stream = qvalue(standard_output);
    if (!is_stream(stream)) stream = qvalue(terminal_io);
    if (!is_stream(stream)) stream = lisp_terminal_io;
    THREADID;
    Save save(THREADARG a);
#ifdef COMMON
    escaped_printing = 0;
    active_stream = stream;
    putc_stream('\n', stream);
    internal_prin(a, 0);
#else
    escaped_printing = 0;
    active_stream = stream;
    internal_prin(a, 0);
    putc_stream('\n', active_stream);
#endif
    save.restore(a);
    if (io_limit >= 0 && io_now > io_limit) resource_exceeded();
    return onevalue(a);
}

LispObject Lterpri(LispObject env)
{   LispObject stream = qvalue(standard_output);
    if (!is_stream(stream)) stream = qvalue(terminal_io);
    if (!is_stream(stream)) stream = lisp_terminal_io;
    putc_stream('\n', stream);
    if (io_limit >= 0 && io_now > io_limit) resource_exceeded();
    return onevalue(nil);
}

LispObject Lflush(LispObject env)
{   LispObject stream = qvalue(standard_output);
    if (!is_stream(stream)) stream = qvalue(terminal_io);
    if (!is_stream(stream)) stream = lisp_terminal_io;
    other_write_action(WRITE_FLUSH, stream);
    return onevalue(nil);
}

LispObject Lflush1(LispObject env, LispObject stream)
{   if (!is_stream(stream)) stream = qvalue(terminal_io);
    if (!is_stream(stream)) stream = lisp_terminal_io;
    other_write_action(WRITE_FLUSH, stream);
    return onevalue(nil);
}

LispObject Lttab(LispObject env, LispObject a)
{   int32_t n;
    LispObject stream = qvalue(standard_output);
    if (!is_fixnum(a)) return aerror1("ttab", a);
    n = int_of_fixnum(a);
    if (!is_stream(stream)) stream = qvalue(terminal_io);
    if (!is_stream(stream)) stream = lisp_terminal_io;
    active_stream = stream;
    while (other_write_action(WRITE_GET_INFO+WRITE_GET_COLUMN,
                              stream) < n)
        putc_stream(' ', active_stream);
    if (io_limit >= 0 && io_now > io_limit) resource_exceeded();
    return onevalue(nil);
}

LispObject Lxtab(LispObject env, LispObject a)
{   int32_t n;
    LispObject stream = qvalue(standard_output);
    if (!is_fixnum(a)) return aerror1("xtab", a);
    n = int_of_fixnum(a);
    if (!is_stream(stream)) stream = qvalue(terminal_io);
    if (!is_stream(stream)) stream = lisp_terminal_io;
    active_stream = stream;
    while (n-- > 0) putc_stream(' ', active_stream);
    if (io_limit >= 0 && io_now > io_limit) resource_exceeded();
    return onevalue(nil);
}

LispObject Leject(LispObject env)
{   LispObject stream = qvalue(standard_output);
    if (!is_stream(stream)) stream = qvalue(terminal_io);
    if (!is_stream(stream)) stream = lisp_terminal_io;
    putc_stream('\f', stream);
    if (io_limit >= 0 && io_now > io_limit) resource_exceeded();
    return onevalue(nil);
}

// I am going to take special action on exploding just a fixnum because
// I believe that parts of Reduce do that especially often.

LispObject Lexplode(LispObject env, LispObject a)
{   if (is_fixnum(a))
    {   intptr_t n = int_of_fixnum(a);
        bool sign;
        if (n < 0)
        {   n = -n;
            sign = true;
        }
        else sign = false;
        unsigned char buffer[32];
        int k = 0;
        while (n >= 10)
        {   buffer[k++] = '0' + n%10;
            n = n/10;
        }
        buffer[k++] = '0' + n;
        if (sign) buffer[k++] = '-';
        LispObject r = nil;
        for (int i=0; i<k; i++)
            r = cons(char_to_id(buffer[i]), r);
        return onevalue(r);
    }
    escaped_printing = escape_yes+escape_nolinebreak+escape_exploding;
    return onevalue(explode(a));
}

LispObject Lexplodehex(LispObject env, LispObject a)
{   escaped_printing = escape_yes+escape_hex+escape_nolinebreak
                       +escape_exploding;
    return onevalue(explode(a));
}

LispObject Lexplodeoctal(LispObject env, LispObject a)
{   escaped_printing = escape_yes+escape_octal+escape_nolinebreak
                       +escape_exploding;
    return onevalue(explode(a));
}

LispObject Lexplodebinary(LispObject env, LispObject a)
{   escaped_printing = escape_yes+escape_binary+escape_nolinebreak
                       +escape_exploding;
    return onevalue(explode(a));
}

LispObject Lexplodec(LispObject env, LispObject a)
{   if (is_fixnum(a))
    {   intptr_t n = int_of_fixnum(a);
        bool sign;
        if (n < 0)
        {   n = -n;
            sign = true;
        }
        else sign = false;
        unsigned char buffer[32];
        int k = 0;
        while (n >= 10)
        {   buffer[k++] = '0' + n%10;
            n = n/10;
        }
        buffer[k++] = '0' + n;
        if (sign) buffer[k++] = '-';
        LispObject r = nil;
        for (int i=0; i<k; i++)
            r = cons(char_to_id(buffer[i]), r);
        return onevalue(r);
    }
    escaped_printing = escape_nolinebreak+escape_exploding;
    return onevalue(explode(a));
}

LispObject Lexplode2lc(LispObject env, LispObject a)
{   escaped_printing = escape_fold_down+escape_nolinebreak
                       +escape_exploding;
    return onevalue(explode(a));
}

LispObject Lexplode2uc(LispObject env, LispObject a)
{   escaped_printing = escape_fold_up+escape_nolinebreak
                       +escape_exploding;
    return onevalue(explode(a));
}

LispObject Lexploden(LispObject env, LispObject a)
{   escaped_printing = escape_yes+escape_nolinebreak+escape_exploding;
    return onevalue(exploden(a));
}

LispObject Lexplodecn(LispObject env, LispObject a)
{   escaped_printing = escape_nolinebreak+escape_exploding;
    return onevalue(exploden(a));
}

LispObject Lexplode2lcn(LispObject env, LispObject a)
{   escaped_printing = escape_fold_down+escape_nolinebreak
                       +escape_exploding;
    return onevalue(exploden(a));
}

LispObject Lexplode2ucn(LispObject env, LispObject a)
{   escaped_printing = escape_fold_up+escape_nolinebreak
                       +escape_exploding;
    return onevalue(exploden(a));
}

// Now a bunch of binary file access code, as required for the RAND simulation
// package.  Note that these are NOT smoothly integrated with the use of
// variables like *standard-output* to hold file handles, but I will leave them
// pending until other things are more stable... or until they are needed!

static std::FILE *binary_outfile, *binary_infile;

static std::FILE *binary_open(LispObject env, LispObject name,
                              const char *dir, const char *e)
{   std::FILE *file;
    char filename[LONGEST_LEGAL_FILENAME];
    size_t len = 0;
    const char *w = get_string_data(name, e, len);
    std::memset(filename, 0, sizeof(filename));
    if (len >= sizeof(filename)) len = sizeof(filename);
    file = open_file(filename, w,
                     static_cast<size_t>(len), dir, nullptr);
    if (file == nullptr)
    {   error(1, err_open_failed, name);
        return nullptr;
    }
    return file;
}

static LispObject Lbinary_open_output(LispObject env, LispObject name)
{   binary_outfile = binary_open(env, name, "wb",
                                 "binary_open_output");
    return onevalue(nil);
}

int binary_outchar(int c, LispObject)
{   if (binary_outfile == nullptr) return 1;
    PUTC(c, binary_outfile);
    if (io_limit >= 0 && io_now > io_limit) resource_exceeded();
    return 0;   // indicate success
}

static LispObject Lbinary_prin1(LispObject env, LispObject a)
{   THREADID;
    Save save(THREADARG a);
    escaped_printing = escape_yes;
    set_stream_write_fn(lisp_work_stream, binary_outchar);
    set_stream_write_other(lisp_work_stream, write_action_file);
    set_stream_file(lisp_work_stream, binary_outfile);
    active_stream = lisp_work_stream;
    internal_prin(a, 0);
    save.restore(a);
    if (io_limit >= 0 && io_now > io_limit) resource_exceeded();
    return onevalue(a);
}

static LispObject Lbinary_princ(LispObject, LispObject a)
{   escaped_printing = 0;
    THREADID;
    Save save(THREADARG a);
    set_stream_write_fn(lisp_work_stream, binary_outchar);
    set_stream_write_other(lisp_work_stream, write_action_file);
    set_stream_file(lisp_work_stream, binary_outfile);
    active_stream = lisp_work_stream;
    internal_prin(a, 0);
    save.restore(a);
    if (io_limit >= 0 && io_now > io_limit) resource_exceeded();
    return onevalue(a);
}

static LispObject Lbinary_prinbyte(LispObject env, LispObject a)
{   int x;
    if (binary_outfile == nullptr) return onevalue(nil);
    if (!is_fixnum(a)) return aerror1("binary_prinbyte", a);
    x = static_cast<int>(int_of_fixnum(a));
    PUTC(x, binary_outfile);
    if (io_limit >= 0 && io_now > io_limit) resource_exceeded();
    return onevalue(nil);
}

static LispObject Lbinary_prin2(LispObject env, LispObject a)
{   uint32_t x;
    if (binary_outfile == nullptr) return onevalue(nil);
    if (!is_fixnum(a)) return aerror1("binary_prin2", a);
    x = int_of_fixnum(a);
    PUTC(static_cast<int>(x >> 8), binary_outfile);
    PUTC(static_cast<int>(x), binary_outfile);
    if (io_limit >= 0 && io_now > io_limit) resource_exceeded();
    return onevalue(nil);
}

static LispObject Lbinary_prin3(LispObject env, LispObject a)
{   uint32_t x;
    if (binary_outfile == nullptr) return onevalue(nil);
    if (!is_fixnum(a)) return aerror1("binary_prin3", a);
    x = int_of_fixnum(a);
    PUTC(static_cast<int>(x >> 16), binary_outfile);
    PUTC(static_cast<int>(x >> 8), binary_outfile);
    PUTC(static_cast<int>(x), binary_outfile);
    if (io_limit >= 0 && io_now > io_limit) resource_exceeded();
    return onevalue(nil);
}

static LispObject Lbinary_prinfloat(LispObject env, LispObject a)
{   uint32_t *w, x;
    if (binary_outfile == nullptr) return onevalue(nil);
    if (!is_float(a)) return aerror1("binary_prinfloat", a);
    w = (uint32_t *)&double_float_val(a);
    x = w[0];
    PUTC(static_cast<int>(x >> 24), binary_outfile);
    PUTC(static_cast<int>(x >> 16), binary_outfile);
    PUTC(static_cast<int>(x >> 8), binary_outfile);
    PUTC(static_cast<int>(x), binary_outfile);
    x = w[1];
    PUTC(static_cast<int>(x >> 24), binary_outfile);
    PUTC(static_cast<int>(x >> 16), binary_outfile);
    PUTC(static_cast<int>(x >> 8), binary_outfile);
    PUTC(static_cast<int>(x), binary_outfile);
    if (io_limit >= 0 && io_now > io_limit) resource_exceeded();
    return onevalue(nil);
}

static LispObject Lbinary_terpri(LispObject env)
{   if (binary_outfile != nullptr) PUTC('\n', binary_outfile);
    if (io_limit >= 0 && io_now > io_limit) resource_exceeded();
    return onevalue(nil);
}

static LispObject Lbinary_close_output(LispObject env)
{   if (binary_outfile != nullptr)
    {   std::fclose(binary_outfile);
        binary_outfile = nullptr;
    }
    return onevalue(nil);
}

static LispObject Lbinary_open_input(LispObject env, LispObject name)
{   LispObject r;
    std::FILE *fh = binary_open(env, name, "rb", "binary_open_input");
    r = make_stream_handle();
    errexit();
    set_stream_read_fn(r, char_from_file);
    set_stream_read_other(r, read_action_file);
    set_stream_file(r, fh);
    return onevalue(r);
}

static LispObject Lbinary_select_input(LispObject env, LispObject a)
{   if (!is_stream(a) ||
        (std::FILE *)stream_file(a) == nullptr ||
        (character_stream_writer *)stream_write_fn(a) != 0)
        return aerror1("binary-select-input", a); // closed file or output file

    binary_infile = stream_file(a);
    return onevalue(nil);
}

static LispObject Lbinary_readbyte(LispObject)
{   if (binary_infile == nullptr) return onevalue(fixnum_of_int(-1));
    if (++io_kilo >= 1024)
    {   io_kilo = 0;
        io_now++;
    }
    return onevalue(fixnum_of_int((int32_t)GETC(binary_infile) & 0xff));
}

static LispObject Lbinary_read2(LispObject)
{   if (binary_infile == nullptr) return onevalue(fixnum_of_int(-1));
    {   int32_t c1 = (int32_t)GETC(binary_infile) & 0xff;
        int32_t c2 = (int32_t)GETC(binary_infile) & 0xff;
        ++io_kilo;
        if (++io_kilo >= 1024)
        {   io_kilo = 0;
            io_now++;
        }
        return onevalue(fixnum_of_int((c1<<8) | c2));
    }
}

static LispObject Lbinary_read3(LispObject)
{   if (binary_infile == nullptr) return onevalue(fixnum_of_int(-1));
    {   int32_t c1 = (int32_t)GETC(binary_infile) & 0xff;
        int32_t c2 = (int32_t)GETC(binary_infile) & 0xff;
        int32_t c3 = (int32_t)GETC(binary_infile) & 0xff;
        io_kilo += 2;
        if (++io_kilo >= 1024)
        {   io_kilo = 0;
            io_now++;
        }
        return onevalue(fixnum_of_int((c1<<16) | (c2<<8) | c3));
    }
}

static LispObject Lbinary_read4(LispObject)
{   if (binary_infile == nullptr) return onevalue(fixnum_of_int(-1));
    {   int32_t c1 = (int32_t)GETC(binary_infile) & 0xff;
        int32_t c2 = (int32_t)GETC(binary_infile) & 0xff;
        int32_t c3 = (int32_t)GETC(binary_infile) & 0xff;
        int32_t c4 = (int32_t)GETC(binary_infile) & 0xff;
        int32_t r = (c1 << 24) | (c2 << 16) | (c3 << 8) | c4;
        io_kilo += 3;
        if (++io_kilo >= 1024)
        {   io_kilo = 0;
            io_now++;
        }
        return onevalue(fixnum_of_int(r));
    }
}

static LispObject Lbinary_readfloat(LispObject env)
{   LispObject r = make_boxfloat(0.0, TYPE_DOUBLE_FLOAT);
    uint32_t w;
    if (binary_infile == nullptr) return onevalue(r);
// Note that the code here treats the float as binary data so infinities and
// NaNs are never anything special.
    w = (int32_t)GETC(binary_infile) & 0xff;
    w = (w<<8) | ((int32_t)GETC(binary_infile) & 0xff);
    w = (w<<8) | ((int32_t)GETC(binary_infile) & 0xff);
    w = (w<<8) | ((int32_t)GETC(binary_infile) & 0xff);
    ((uint32_t *)&double_float_val(r))[0] = w;
    w = (int32_t)GETC(binary_infile) & 0xff;
    w = (w<<8) | ((int32_t)GETC(binary_infile) & 0xff);
    w = (w<<8) | ((int32_t)GETC(binary_infile) & 0xff);
    w = (w<<8) | ((int32_t)GETC(binary_infile) & 0xff);
    ((uint32_t *)&double_float_val(r))[1] = w;
    io_kilo += 7;
    if (++io_kilo >= 1024)
    {   io_kilo = 0;
        io_now++;
    }
    return onevalue(r);
}

static LispObject Lbinary_close_input(LispObject env)
{   if (binary_infile != nullptr)
    {   std::fclose(binary_infile);
        binary_infile = nullptr;
    }
    return onevalue(nil);
}

// (open-library "file" dirn) opens a new library (for use with the
// fasl mechanism etc). If dirn=nil (or not specified) the library is
// opened for input only. If dirn is non-nil an attempt is made to open
// the library so that it can be updated, and if it does not exist to start
// with it is created. The resulting handle can be passed to close-library
// or used in the variables input-libraries or output-library.

std::vector<faslFileRecord> fasl_files;

static LispObject Lopen_library(LispObject env, LispObject file,
                                LispObject dirn)
{   char filename[LONGEST_LEGAL_FILENAME];
    size_t len = 0;
    bool forinput = (dirn==nil);
    size_t i;
    const char *w = get_string_data(file, "open-library", len);
    char *w1;
    std::memset(filename, 0, sizeof(filename));
    if (len >= sizeof(filename)) len = sizeof(filename)-1;
    std::memcpy(filename, w, len);
    filename[len] = 0;
// If one of the libraries I had opened earlier has now been closed there
// may be an empty slot in fasl_files[], and so I will scan and look for
// that and if I find such then I will use it.
    for (i=0; i<fasl_files.size(); i++)
    {   if (!fasl_files[i].inUse) goto found;
    }
// If not I append a new slot on the end of the std::vector. By using
// std::vector I can at least pretend that there is no limit to the number of
// libraries that I can have open at once. However the cost of that is that
// it can need to allocate memory and that allocation may fail. If it does
// that will be abruptly fatal.
    fasl_files.push_back(faslFileRecord(nullptr, !forinput));
    i = fasl_files.size()-1;
found:
    fasl_files[i].inUse = true;
    w1 = new (std::nothrow) char[std::strlen(filename)+1];
    if (w1 != nullptr) std::strcpy(w1, filename);
// The name field contains either nullptr or a newly allocated C string.
    fasl_files[i].name = w1;
    fasl_files[i].dir = open_pds(filename,
                                 forinput ? PDS_INPUT : PDS_OUTPUT);
    fasl_files[i].isOutput = !forinput;
    return onevalue(SPID_LIBRARY + (((int32_t)i)<<20));
}

static LispObject Lopen_library_1(LispObject env, LispObject file)
{   return Lopen_library(env, file, nil);
}

static LispObject Lclose_library(LispObject env, LispObject lib)
{   if (!is_library(lib)) return aerror1("close-library", lib);
    finished_with(library_number(lib));
    return onevalue(nil);
}

static LispObject Llibrary_name(LispObject env, LispObject lib)
{   LispObject a;
    if (!is_library(lib)) return aerror1("library-name", lib);
    const char *s = fasl_files[library_number(lib)].name;
    if (s == nullptr) s = "*unknown*";
    a = make_string(s);
    return onevalue(a);
}

#ifdef SOCKETS

// If a Winsock function fails it leaves an error code that
// WSAGetLastError() can retrieve. This function converts the numeric
// codes to some printable text. Still cryptic, but maybe better than
// the raw numbers!

#ifndef WIN32

static char error_name[32];const char *WSAErrName(int i)
{   switch (i)
    {   default:                 std::sprintf(error_name,
                                              "Socket error %d", i);
                                 return error_name;
// When I run under Unix I display both the Unix and Windows form of the
// error code.  I guess that shows you which of those platforms is the one
// I am doing initial development on!
        case EINTR:              return "WSAEINTR/EINTR";
        case EBADF:              return "WSAEBADF/EBADF";
        case EACCES:             return "WSAEACCES/EACCES";
        case EFAULT:             return "WSAEFAULT/EFAULT";
        case EINVAL:             return "WSAEINVAL/EINVAL";
        case EMFILE:             return "WSAEMFILE/EMFILE";
        case EWOULDBLOCK:        return "WSAEWOULDBLOCK/EWOULDBLOCK";
        case EINPROGRESS:        return "WSAEINPROGRESS/EINPROGRESS";
        case EALREADY:           return "WSAEALREADY/EALREADY";
        case ENOTSOCK:           return "WSAENOTSOCK/ENOTSOCK";
        case EDESTADDRREQ:       return "WSAEDESTADDRREQ/EDESTADDRREQ";
        case EMSGSIZE:           return "WSAEMSGSIZE/EMSGSIZE";
        case EPROTOTYPE:         return "WSAEPROTOTYPE/EPROTOTYPE";
        case ENOPROTOOPT:        return "WSAENOPROTOOPT/ENOPROTOOPT";
        case EPROTONOSUPPORT:    return "WSAEPROTONOSUPPORT/EPROTONOSUPPORT";
        case ESOCKTNOSUPPORT:    return "WSAESOCKTNOSUPPORT/ESOCKTNOSUPPORT";
        case EOPNOTSUPP:         return "WSAEOPNOTSUPP/EOPNOTSUPP";
        case EPFNOSUPPORT:       return "WSAEPFNOSUPPORT/EPFNOSUPPORT";
        case EAFNOSUPPORT:       return "WSAEAFNOSUPPORT/EAFNOSUPPORT";
        case EADDRINUSE:         return "WSAEADDRINUSE/EADDRINUSE";
        case EADDRNOTAVAIL:      return "WSAEADDRNOTAVAIL/EADDRNOTAVAIL";
        case ENETDOWN:           return "WSAENETDOWN/ENETDOWN";
        case ENETUNREACH:        return "WSAENETUNREACH/ENETUNREACH";
        case ENETRESET:          return "WSAENETRESET/ENETRESET";
        case ECONNABORTED:       return "WSAECONNABORTED/ECONNABORTED";
        case ECONNRESET:         return "WSAECONNRESET/ECONNRESET";
        case ENOBUFS:            return "WSAENOBUFS/ENOBUFS";
        case EISCONN:            return "WSAEISCONN/EISCONN";
        case ENOTCONN:           return "WSAENOTCONN/ENOTCONN";
        case ESHUTDOWN:          return "WSAESHUTDOWN/ESHUTDOWN";
        case ETOOMANYREFS:       return "WSAETOOMANYREFS/ETOOMANYREFS";
        case ETIMEDOUT:          return "WSAETIMEDOUT/ETIMEDOUT";
        case ECONNREFUSED:       return "WSAECONNREFUSED/ECONNREFUSED";
        case ELOOP:              return "WSAELOOP/ELOOP";
        case ENAMETOOLONG:       return "WSAENAMETOOLONG/ENAMETOOLONG";
        case EHOSTDOWN:          return "WSAEHOSTDOWN/EHOSTDOWN";
        case EHOSTUNREACH:       return "WSAEHOSTUNREACH/EHOSTUNREACH";
        case HOST_NOT_FOUND:     return "WSAHOST_NOT_FOUND/HOST_NOT_FOUND";
        case TRY_AGAIN:          return "WSATRY_AGAIN/TRY_AGAIN";
        case NO_RECOVERY:        return "WSANO_RECOVERY/NO_RECOVERY";
#ifdef never
// Duplicated EINTR, at least on Linux.
        case NO_DATA:            return "WSANO_DATA/NO_DATA";
#endif
    }
}

#endif // WIN32


bool sockets_ready = false;

int ensure_sockets_ready()
{   if (!sockets_ready)
    {
#ifdef WIN32
        if (windowsPrepareSockets() != 0) return 1;
#endif
        sockets_ready = true;
    }
    return 0;
}

#define SOCKET_BUFFER_SIZE 256

// A stream attached to a socket is represented by putting the socket handle
// into the field that would otherwise hold a FILE. The stream_read_data
// field then holds a string. The first 4 characters of this contain
// two packed integers saying how much buffered data is available,
// and then there is just a chunk of buffered text.

int char_from_socket(LispObject stream)
{   int ch = stream_pushed_char(stream);
    if (ch == NOT_CHAR)
    {   LispObject w = stream_read_data(stream);
        int32_t sb_data = ielt32(w, 0);
        int sb_start = sb_data & 0xffff, sb_end = (sb_data >> 16) & 0xffff;
// Note use of ucelt in the next line even if char is a signed type. This
// is because getc() etc are expected to return an UNSIGNED char cast to
// an int.
        if (sb_start != sb_end) ch = ucelt(w, sb_start++);
        else
        {   ch = recv((SOCKET)(intptr_t)(std::FILE *)stream_file(stream),
                      reinterpret_cast<char *>(&celt(w, 4)), SOCKET_BUFFER_SIZE, 0);
            if (ch == 0) return EOF;
            if (ch == SOCKET_ERROR)
            {   err_printf("socket read error (%s)\n",
                           WSAErrName(WSAGetLastError()));
                return EOF;
            }
            sb_start = 5;
            sb_end = ch + 4;
            ch = ucelt(w, 4);
        }
        sb_data = sb_start | (sb_end << 16);
        ielt32(w, 0) = sb_data;
        return ch;
    }
    else stream_pushed_char(stream) = NOT_CHAR;
    return ch;
}

// Seek and tell will be just quiet no-ops on socket streams.

int32_t read_action_socket(int32_t op, LispObject f)
{   if (op < -1) return 0;
    else if (op <= 0xff) return (stream_pushed_char(f) = op);
    else switch (op)
        {   case READ_CLOSE:
                if ((std::FILE *)stream_file(f) == nullptr) op = 0;
                else
#ifdef SOCKETS
                    op = closesocket(
                             (SOCKET)(intptr_t)(std::FILE *)stream_file(f));
#else
                    op = 0;
#endif
                set_stream_read_fn(f, char_from_illegal);
                set_stream_read_other(f, read_action_illegal);
                set_stream_file(f, nullptr);
                stream_read_data(f) = nil;
                return op;
            case READ_FLUSH:
                stream_pushed_char(f) = NOT_CHAR;
                return 0;
            default:
                return 0;
        }
}


int fetch_response(char *buffer, LispObject r)
{   size_t i;
    for (i = 0; i<LONGEST_LEGAL_FILENAME; i++)
    {   int ch = char_from_socket(r);
        if (ch == EOF) return 1;
        buffer[i] = static_cast<char>(ch);
        if (ch == 0x0a)
        {   buffer[i] = 0;
// The keys returned at the start of a response line are supposed to be
// case insensitive, so I fold things to lower case right here.
            for (i=0; buffer[i]!=0 && buffer[i]!=' '; i++)
                buffer[i] = static_cast<char>(std::tolower(static_cast<unsigned char>
                                              (buffer[i])));
            return 0;
        }
    }
    return 1; // fail if response was over-long
}


static LispObject Lopen_url(LispObject env, LispObject url)
{   char filename[LONGEST_LEGAL_FILENAME],
    filename1[LONGEST_LEGAL_FILENAME], *p;
    const char *user, *pass, *proto, *hostaddr, *port, *path;
    size_t  nuser, npass, nproto, nhostaddr, nport, npath;
    size_t len = 0;
    struct hostent *host;
    unsigned long int hostnum;
    SOCKET s;
    size_t i;
    int retcode, retry_count=0;
    LispObject r;
    const char *w = get_string_data(url, "open-url", len);
    std::memset(filename, 0, sizeof(filename));
    std::memset(filename1, 0, sizeof(filename1));

start_again:

    if (len >= sizeof(filename)) len = sizeof(filename)-1;
    std::memcpy(filename, w, len);
    filename[len] = 0;
// I want to parse the URL. I leave the result as a collection of
// pointers (usually to the start of text within the URL itself, but
// sometimes elsewhere, together with lengths of the substrings as found.
    user = pass = proto = hostaddr = port = path = " ";
    nuser = npass = nproto = nhostaddr = nport = npath = 0;
    p = filename;
// If the start of the URL is of the form "xyz:" with xyz alphanumeric
// then that is a protocol name, and I will force it into lower case.
    for (i=0; i<len; i++)
        if (!std::isalnum(static_cast<unsigned char>(p[i]))) break;
    if (p[i] == ':')
    {   char *oldp = p;
        proto = p;
        nproto = i;   // Could still be zero!
        p += i+1;
        len -= i+1;
        for (i=0; i<nproto; i++)
            oldp[i] = static_cast<char>(std::tolower(static_cast<unsigned char>
                                        (oldp[i])));
    }
// After any protocol specification I may have a host name, introduced
// by "//".
    if (p[0] == '/' && p[1] == '/')
    {   p += 2;
        len -= 2;
// If the URL (sans protocol) contains a "@" then I will take it to be
// in the form
//      user:password@hostaddr/...
// and will split the user bit off. This will be particularly used in the
// case of FTP requests. The password will be allowed to contain ":" and
// "@" characters. Furthermore I will also allow the password to be
// enclosed in quote marks ("), although since I scan for the "@" from
// the right and for the ":" from the left these are not needed at all,
// so if I notice them here all I have to do is to discard them!
        for (i=len; i>0; i--)
            if (p[i-1] == '@') break;
        if (i > 0)
        {   i--;
            user = p;
            p += i+1;
            len -= i+1;
            while (user[nuser] != ':' && user[nuser] != '@') nuser++;
            if (user[nuser] == ':')
            {   pass = user+nuser+1;
                npass = i - nuser - 1;
                if (pass[0] == '"' && pass[npass-1] == '"')
                    pass++, npass -= 2;
            }
        }
// Now what is left is a host, port number and path, written as
//     hostaddr:port/... but note that the "/" should be treated as
// part of the path-name.
        hostaddr = p;
        for (;;)
        {   switch (hostaddr[nhostaddr])
        {       default:
                    nhostaddr++;
                    continue;
                case '/':
                    p += nhostaddr;
                    len -= nhostaddr;
                    break;
                case 0: len = 0;
                    break;
                case ':':        // port number given
                    port = hostaddr+nhostaddr+1;
                    for (;;)
                    {   switch (port[nport])
                    {       default:
                                nport++;
                                continue;
                            case '/':
                                p += nhostaddr + nport + 1;
                                len -= nhostaddr + nport + 1;
                                break;
                            case 0: len = 0;
                                break;
                        }
                        break;
                    }
                    break;
            }
            break;
        }
    }
    path = p;
    npath = len;
    if (npath == 0) path = "/", npath = 1;  // Default path
// If a protocol was not explicitly given I will try to deduce one from the
// start of the name of the hostaddr. Failing that I will just use a default.
    if (nproto == 0)
    {   if (std::strncmp(hostaddr, "www.", 4) == 0 ||
            std::strncmp(hostaddr, "wwwcgi.", 7) == 0)
        {   proto = "http";
            nproto = 4;
        }
        else
        {   proto = "ftp";
            nproto = 3;
        }
    }
// If the user gave an explicit port number I will try to use it. If the
// port was not numeric I ignore it and drop down to trying to use
// a default port based on the selected protocol.
    if (nport != 0)
    {   int w;
        std::memcpy(filename1, port, nport);
        filename1[nport] = 0;
        if (std::sscanf(filename1, "%d", &w) == 1) nport = w;
        else nport = 0;
    }
    if (nport == 0)
    {   if (nproto == 3 && std::memcmp(proto, "ftp", 3) == 0) nport = 21;
        else if (nproto == 4 &&
                 std::memcmp(proto, "http", 4) == 0) nport = 80;
// Elsewhere I have code that can call on an external "scp" program to support
// a secure-fetch scheme, but I will NOT include that here.
        else return aerror("Unknown protocol");
    }
// If no host-name was given then the object concerned is on the
// local machine. This is a funny case maybe, but I will just chain
// through and open it as an ordinary file (without regard to
// protocol etc).
    if (nhostaddr == 0)
    {   std::FILE *file = open_file(filename1, path, static_cast<size_t>(npath), "r",
                                    nullptr);
        if (file == nullptr) return onevalue(nil);
        {   THREADID;
            Save save(THREADARG url);
            r = make_stream_handle();
            errexit();
            save.restore(url);
        }
        stream_type(r) = url;
        set_stream_file(r, file);
        set_stream_read_fn(r, char_from_file);
        set_stream_read_other(r, read_action_file);
        return onevalue(r);
    }
    if (nproto == 3 && std::strcmp(proto, "ftp") == 0 && nuser == 0)
    {   user = "anonymous";
        nuser = std::strlen(user);
        if (npass == 0)
        {   pass = "acn1@cam.ac.uk";
            npass = std::strlen(pass);
        }
    }
#ifdef DEBUG
// The trace print here is not needed in the long term but certainly
// helps while I am doing initial tests.
    trace_printf(
        "User <%.*s> Pass <%.*s> Proto <%.*s>\n"
        "Host <%.*s> Port <%d> Path <%.*s>\n",
        nuser, user, npass, pass, nproto, proto,
        nhostaddr, hostaddr, nport, npath, path);
#endif
    if (ensure_sockets_ready() != 0) return nil;
    std::memcpy(filename1, hostaddr, nhostaddr);
    filename1[nhostaddr] = 0;
// I try to accept either "." form or named host specifications
    hostnum = inet_addr(filename1);
    if (hostnum == INADDR_NONE)
    {   host = gethostbyname(filename1);
        if (host != nullptr)
            hostnum = ((struct in_addr *)host->h_addr)->s_addr;
    }
    if (hostnum == INADDR_NONE)
    {   err_printf("Host not found (%s)\n",
                   WSAErrName(WSAGetLastError()));
        return onevalue(nil);
    }
    s = socket(PF_INET, SOCK_STREAM, 0);  // Make a new socket
    {   struct sockaddr_in sockin;
        std::memset(&sockin, 0, sizeof(sockin));
        sockin.sin_family = AF_INET;
        sockin.sin_port = htons(nport);
        sockin.sin_addr.s_addr = hostnum;
// Because there can be quite tedious delays in network fetches I will
// log that I am trying to make contact.
        trace_printf("Contacting %.*s...\n", nhostaddr, hostaddr);
        ensure_screen();
        if (connect(s, (struct sockaddr *)&sockin,
                    sizeof(sockin)) == SOCKET_ERROR)
        {   err_printf("connect failed %s\n", WSAErrName(WSAGetLastError()));
            closesocket(s);
            return onevalue(nil);
        }
        trace_printf("Connection created\n");
    }
    std::sprintf(filename1, "GET %.*s HTTP/1.0\x0d\x0a\x0d\x0a",
                 static_cast<int>(npath), path);

// MD addition from webcore.c
    i = std::strlen(filename1);
// Certainly if the Web server I am accessing is the one that comes as
// standard with Windows NT I need to reassure it that I want the document
// returned to me WHATEVER its media type is. If I do not add in the
// line "Accept: *|*" the GET request will only allow me to fetch simple
// text (?)
// Note that above I write "*|*" where I only really mean a "/" in the
// middle but where C comment conventions intrude!
    std::sprintf(&filename1[i], "Accept: */*\x0d\x0a\x0d\x0a");

    if (send(s, filename1, std::strlen(filename1), 0) == SOCKET_ERROR)
    {   err_printf("Send error (%s)\n", WSAErrName(WSAGetLastError()));
        closesocket(s);
        return onevalue(nil);
    }

    {   THREADID;
        Save save(THREADARG url);
        r = make_stream_handle();
        errexit();
        save.restore(url);
    }
    stream_type(r) = url;
    {   THREADID;
        Save save(THREADARG r);
        url = get_basic_vector(TAG_VECTOR, TYPE_STRING_4,
                               CELL+4+SOCKET_BUFFER_SIZE);
        errexit();
        save.restore(r);
    }
    ielt32(url, 0) = 0;
    stream_read_data(r) = url;
    set_stream_file(r, (std::FILE *)(intptr_t)s);
    set_stream_read_fn(r, char_from_socket);
    set_stream_read_other(r, read_action_socket);

// Now fetch the status line.
    if (fetch_response(filename1, r))
    {   err_printf("Error fetching status line from the server\n");
        Lclose(env,r);
        return onevalue(nil);
    }

// I check if the first line returned is in the form "HTTP/n.n nnn " and if
// it is not I assume that I have reached an HTTP/0.9 server and all the
// text that comes back will be the body.
    {   int major, minor;
// I will not worry much about just which version of HTTP the system reports
// that it is using, provided it says something! I expect to see the return
// code as a three digit number. I verify that it is in the range 0 to 999 but
// do not check for (and thus reject) illegal responses such as 0000200.
        if (std::sscanf(filename1,
                        "http/%d.%d %d", &major, &minor, &retcode) != 3 ||
            retcode < 0 || retcode > 999)
        {   err_printf("Bad protocol specification returned\n");
            err_printf(filename1); // So I can see what did come back
            Lclose(env,r);
            return onevalue(nil);
        }
    }
// In this code I treat all unexpected responses as errors and I do not
// attempt to continue. This is sometimes going to be overly pessimistic
// and RFC1945 tells me that I should treat unidentified codes as the
// n00 variant thereupon.
    switch (retcode)
{       default:retcode = 0;
            break;
        case 200:
            break;   // A success code for GET requests
        case 301:        // Redirection request
        case 302:
            do
            {   if (fetch_response(filename1, r))
                {   err_printf("Unexpected response from the server\n");
                    retcode = 0;
                    break;
                }
                if (filename1[0] == 0)
                {   err_printf("Document has moved, but I can not trace it\n");
                    retcode = 0;
                    break;
                }
            }
            while (std::memcmp(filename1, "location: ", 10) != 0);
            if (retcode == 0) break;
// At present I take a somewhat simplistic view of redirection, and just
// look for the first alternative URL and start my entire unpicking
// process afresh from there.
            for (i = 10; filename1[i] == ' '; i++);
            w = &filename1[i];
            while (filename1[i]!=' ' && filename1[i]!=0) i++;
            filename1[i] = 0;
            len = std::strlen(w);
            closesocket(s);
            if (++retry_count > 5)
            {   err_printf("Apparent loop in redirection information\n");
                retcode = 0;
                break;
            }
            goto start_again;
            break;
        case 401:
            err_printf("Authorisation required for this access\n");
            retcode = 0;
            break;
        case 404:
            err_printf("Object not found\n");
            retcode = 0;
            break;
    }

    if (retcode == 0)
    {   Lclose(env,r);
        return onevalue(nil);
    }

// Skip further information returned by the server until a line containing
// just the end-of-line marker is fetched
    do
    {   for (i = 0; i < LONGEST_LEGAL_FILENAME; i++)
        {   int ch = char_from_socket(r);
            if (ch == EOF)
            {   err_printf("Error fetching additional info from the server\n");
                Lclose(env,r);
                return onevalue(nil);
            }
            if (ch == 0x0a) break;
        }
    }
    while (i > 1);

    return onevalue(r);
}

#endif // SOCKETS

int window_heading = 0;

char saveright[32];

LispObject Lwindow_heading2(LispObject env, LispObject a,
                            LispObject b)
{
#ifndef EMBEDDED
    int32_t n, bit;
    const char *s;
    char txt[32];
    txt[0] = 0;
    if (is_fixnum(b)) n = int_of_fixnum(b);
    else n = 2;  // default to setting the right section
    if (is_vector(a) && is_string(a))
    {   int32_t l = length_of_byteheader(vechdr(a)) - CELL;
        if (l > 30) l = 30;
        std::memcpy(txt, &celt(a, 0), l);
        txt[l] = 0;
        s = txt;
    }
    else if (b == 2) s = "";
    else s = nullptr;
    switch (n)
    {   case 0: fwin_report_left(s);  bit = 1; break;
        case 1: fwin_report_mid(s);   bit = 2; break;
        default:
#ifdef WITH_GUI
            if (alternative_stdout != nullptr)
            {   if (std::strcmp(txt, saveright) != 0 && s != nullptr)
                {   std::fprintf(stderr, "Info: %s\n", txt);
#ifdef __CYGWIN__
                    std::putc('\r', stderr);
#endif
                    std::fflush(stderr);
                }
                std::strcpy(saveright, txt);
            }
#else
            if (std::strcmp(txt, saveright) != 0 && s != nullptr)
            {   std::fprintf(stderr, "Info: %s\n", txt);
#ifdef __CYGWIN__
                std::putc('\r', stderr);
#endif
                std::fflush(stderr);
            }
            std::strcpy(saveright, txt);
#endif // WITH_GUI
            fwin_report_right(s); bit = 4; break;
    }
    if (s == nullptr || *s == 0) window_heading &= ~bit;
    else window_heading |= bit;
#endif // !EMBEDDED
    return onevalue(nil);
}

LispObject Lwindow_heading1(LispObject env, LispObject a)
{   return Lwindow_heading2(env, a, nil);
}

/////////////////////////////////////////////////////////////////////

// This is simplified printing and sends its output to stdout. It is ONLY
// intended for use while debugging. I will use if when printing trace
// and backtrace output..
// I want it to be able to cope with looped up structures so I will use
// and EQ-keyed hash table to detect places where the structure is
// reentrant.
// I will also implement a scheme that lets me limit the output from each
// printed expression to a certain number of lines of output...

static int simple_column = 0;

void simple_lineend(int n)
{   if (simple_column + n > 70)
    {   std::printf("\n");
        simple_column = n;
    }
    else simple_column += n;
}

void simple_prin1(LispObject x)
{   char buffer[40];
    if (x == nil)
    {   simple_lineend(3);
        std::printf("nil");
        return;
    }
    if (x == 0)
    {   simple_lineend(3);
        std::printf("@0@");
        return;
    }
    if (is_forward(x))
    {   std::printf("Forward_%" PRIx64, static_cast<uint64_t>(x));
        return;
    }
    if (is_cons(x))
    {   int len = 0;
        const char *sep = "(";
        while (consp(x))
        {   simple_lineend(1);
            std::printf("%s", sep);
            sep = " ";
            simple_prin1(car(x));
            x = cdr(x);
            if (len++ > 20)
            {   std::printf(" ...!...");
                x = nil;
            }
        }
        if (x != nil)
        {   simple_lineend(3);
            std::printf(" . ");
            simple_prin1(x);
        }
        simple_lineend(3);
        std::printf(")");
        return;
    }
    else if (is_fixnum(x))
    {   int k = std::sprintf(buffer, "%" PRId64,
                             (int64_t)int_of_fixnum(x));
        simple_lineend(k);
        std::printf("%s", buffer);
        return;
    }
    else if (is_symbol(x))
    {   size_t len;
        x = qpname(x);
        len = length_of_byteheader(vechdr(x)) - CELL;
        if (len > 80) len = 80;
        simple_lineend(len);
        std::printf("%.*s", static_cast<int>(len),
                     reinterpret_cast<const char *>(&celt(x, 0)));
    }
    else if (is_vector(x))
    {   size_t i, len;
        if (is_string(x))
        {   len = length_of_byteheader(vechdr(x)) - CELL;
            if (len > 80) len = 80;
            simple_lineend(len+2);
            std::printf("\"%.*s\"", static_cast<int>(len),
                         reinterpret_cast<const char *>(&celt(x, 0)));
            return;
        }
        else if (vector_holds_binary(vechdr(x)) &&
                 vector_i8(vechdr(x)))
        {   len = length_of_byteheader(vechdr(x)) - CELL;
            std::printf("<Header is %" PRIx64 ">",
                         static_cast<uint64_t>(vechdr(x)));
            if (len > 80) len = 80;
            simple_lineend(2*len+3);
            std::printf("#8[");
            for (size_t i=0; i<len; i++)
            {   simple_lineend(2);
                std::printf("%.2x", celt(x, i) & 0xff);
            }
            std::printf("]");
            return;
        }
        len = (int64_t)(length_of_header(vechdr(x))/CELL - 1);
        int nn = std::sprintf(buffer, "[%" PRId64 ":", (int64_t)len);
        if (len > 20) len = 20;
        simple_lineend(nn);
        std::printf("%s", buffer);
        for (i=0; i<len; i++)
        {   simple_lineend(1);
            std::printf(" ");
            if (i > 2 && is_mixed_header(vechdr(x)))
            {   nn = std::sprintf(buffer, "%" PRIx64, (uint64_t)elt(x, i));
                simple_lineend(nn);
                std::printf("%s", buffer);
            }
            else simple_prin1(elt(x, i));
        }
        simple_lineend(1);
        std::printf("]");
        return;
    }
    else if (is_numbers(x) && is_bignum(x))
    {   size_t len = (length_of_header(numhdr(x))-CELL)/4;
        size_t i;
        int clen;
        for (i=len; i>0; i--)
        {   int32_t d = bignum_digits(x)[i-1];
// I will print bignums in a manner that shows the 31-bit digits that they
// are made up from.
            if (i == len) clen = std::sprintf(buffer, "@#%d", d);
            else clen = std::sprintf(buffer, ":%u", d);
            simple_lineend(clen);
            std::printf("%s", buffer);
        }
        return;
    }
    else
    {   char buffer[32];
// This default case includes bignums, and I am not keen on needing
// to render them here! But it certainly looks ugly when they get
// displayed as @xxxxx@ with the xxxxx being a bunch of hex digits giving
// the memory address the data lies at!
        int clen = std::sprintf(buffer, "@%" PRIx64 "@", (int64_t)x);
        simple_lineend(clen);
        std::printf("%s", buffer);
        return;
    }
}

void simple_prin1(atomic<LispObject> &x)
{   simple_prin1(static_cast<LispObject>(x));
}

void simple_print(LispObject x)
{   simple_prin1(x);
    std::printf("\n");
    simple_column = 0;
}

void simple_print(atomic<LispObject> &x)
{   simple_print(static_cast<LispObject>(x));
}

void simple_msg(const char *s, LispObject x)
{   std::printf("%s", s);
    simple_print(x);
    std::printf("\n");
}

setup_type const print_setup[] =
{
#ifdef SOCKETS
    DEF_1("open-url",             Lopen_url),
#endif
    DEF_1("check-list",           Lcheck_list),
    {"window-heading",            G0Wother, Lwindow_heading1, Lwindow_heading2, G3Wother, G4Wother},
    DEF_0("eject",                Leject),
    DEF_1("filep",                Lfilep),
    DEF_1("filedate",             Lfiledate),
    {"flush",                     Lflush, Lflush1, G2Wother, G3Wother, G4Wother},
    DEF_1("streamp",              Lstreamp),
    DEF_1("is-console",           Lis_console),
    DEF_1("lengthc",              Llengthc),
    DEF_1("widelengthc",          Lwidelengthc),
    {"linelength",                Llinelength0, Llinelength, G2Wother, G3Wother, G4Wother},
    DEF_0("lposn",                Llposn),
    DEF_2("internal-open",        Lopen),
    {"open-library",              G0Wother, Lopen_library_1, Lopen_library, G3W2, G4W2},
    DEF_1("close-library",        Lclose_library),
    DEF_1("library-name",         Llibrary_name),
    DEF_1("create-directory",     Lcreate_directory),
    DEF_1("delete-file",          Ldelete_file),
    DEF_1("delete-wildcard",      Ldelete_wildcard),
    DEF_2("rename-file",          Lrename_file),
    DEF_1("file-readablep",       Lfile_readable),
    DEF_1("file-writeablep",      Lfile_writeable),
    DEF_1("directoryp",           Ldirectoryp),
    DEF_1("file-length",          Lfile_length),
    DEF_1("truename",             Ltruename),
    DEF_1("list-directory",       Llist_directory),
    DEF_1("chdir",                Lchange_directory),
    DEF_1("make-function-stream", Lmake_function_stream),
    DEF_0("make-string-output-stream", Lmake_string_output_stream),
    DEF_1("get-output-stream-string",  Lget_output_stream_string),
    DEF_0("get-current-directory",     Lget_current_directory),
    DEF_0("user-homedir-pathname",     Luser_homedir_pathname),
    DEF_0("get-lisp-directory",   Lget_lisp_directory),
    DEF_0("find-gnuplot",         Lfind_gnuplot),
    DEF_0("getpid",               Lgetpid),
    DEF_1("pagelength",           Lpagelength),
    {"posn",                      Lposn, Lposn_1, G2Wother, G3Wother, G4Wother},
    DEF_1("spaces",               Lxtab),
    DEF_0("terpri",               Lterpri),
    DEF_0("tmpdir",               Ltmpdir),
    {"tmpnam",                    Ltmpnam, Ltmpnam1, G2Wother, G3Wother, G4Wother},
    DEF_1("ttab",                 Lttab),
    DEF_1("wrs",                  Lwrs),
    DEF_1("xtab",                 Lxtab),
    DEF_1("princ-upcase",         Lprinc_upcase),
    DEF_1("princ-downcase",       Lprinc_downcase),
    DEF_1("binary_open_output",   Lbinary_open_output),
    DEF_1("binary_prin1",         Lbinary_prin1),
    DEF_1("binary_princ",         Lbinary_princ),
    DEF_1("binary_prinbyte",      Lbinary_prinbyte),
    DEF_1("binary_prin2",         Lbinary_prin2),
    DEF_1("binary_prin3",         Lbinary_prin3),
    DEF_1("binary_prinfloat",     Lbinary_prinfloat),
    DEF_0("binary_terpri",        Lbinary_terpri),
    DEF_0("binary_close_output",  Lbinary_close_output),
    DEF_1("binary_open_input",    Lbinary_open_input),
    DEF_1("binary_select_input",  Lbinary_select_input),
    DEF_0("binary_readbyte",      Lbinary_readbyte),
    DEF_0("binary_read2",         Lbinary_read2),
    DEF_0("binary_read3",         Lbinary_read3),
    DEF_0("binary_read4",         Lbinary_read4),
    DEF_0("binary_readfloat",     Lbinary_readfloat),
    DEF_0("binary_close_input",   Lbinary_close_input),
    DEF_1("prinraw",              Lprinraw),
    {"prinhex",                   G0Wother, Lprinhex, Lprinhex2, G3Wother, G4Wother},
    {"prinoctal",                 G0Wother, Lprinoctal, Lprinoctal2, G3Wother, G4Wother},
    {"prinbinary",                G0Wother, Lprinbinary, Lprinbinary2, G3Wother, G4Wother},
    DEF_1("math-display",         Lmath_display),
    DEF_1("debug-print",          Ldebug_print),
    DEF_1("set-print-precision",  Lprint_precision),
    DEF_1("setprintprecision",    Lprint_precision),
    DEF_0("getprintprecision",    Lget_precision),
    DEF_1("close",                Lclose),
    DEF_1("explode",              Lexplode),
    DEF_1("explodec",             Lexplodec),
    DEF_1("explode2",             Lexplodec),
    DEF_1("explode2lc",           Lexplode2lc),
    DEF_1("explode2uc",           Lexplode2uc),
    DEF_1("exploden",             Lexploden),
    DEF_1("explodecn",            Lexplodecn),
    DEF_1("explode2n",            Lexplodecn),
    DEF_1("explode2lcn",          Lexplode2lcn),
    DEF_1("explode2ucn",          Lexplode2ucn),
    DEF_1("explodehex",           Lexplodehex),
    DEF_1("explodeoctal",         Lexplodeoctal),
    DEF_1("explodebinary",        Lexplodebinary),
    DEF_1("prin",                 Lprin),
    DEF_1("prin1",                Lprin),
    DEF_1("princ",                Lprinc),
    DEF_1("prin2",                Lprinc),
    DEF_1("prin2a",               Lprin2a),
    DEF_1("print",                Lprint),
    DEF_1("printc",               Lprintc),
    DEF_1("tyo",                  Ltyo),
// The next few are Common Lisp-isms but I will stick them in here anyway.
    {"charpos",                   Lposn, Lposn_1, G2Wother, G3Wother, G4Wother},
    {"finish-output",             Lflush, Lflush1, G2Wother, G3Wother, G4Wother},
    DEF_1("make-synonym-stream",  Lmake_synonym_stream),
    {"make-broadcast-stream",     Lmake_broadcast_stream_0, Lmake_broadcast_stream_1, Lmake_broadcast_stream_2, Lmake_broadcast_stream_3, Lmake_broadcast_stream_4up},
    {"make-concatenated-stream",  Lmake_concatenated_stream_0, Lmake_concatenated_stream_1, Lmake_concatenated_stream_2, Lmake_concatenated_stream_3, Lmake_concatenated_stream_4up},
    DEF_2("make-two-way-stream",  Lmake_two_way_stream),
    DEF_2("make-echo-stream",     Lmake_echo_stream),
    {"make-string-input-stream",  Lmake_string_input_stream_0, Lmake_string_input_stream_1, Lmake_string_input_stream_2, Lmake_string_input_stream_3, Lmake_string_input_stream_4up},
    DEF_1("~tyo",                 Ltyo),
    {nullptr,                     nullptr, nullptr, nullptr, nullptr, nullptr}
};

// end of print.cpp
