/*  print.c                           Copyright (C) 1990-99 Codemist Ltd */

/*
 * Printing, plus some file-related operations.
 */

/* Signature: 4785387f 07-Mar-2000 */

#include <stdarg.h>
#include <string.h>
#include <ctype.h>

#include "machine.h"
#include "tags.h"
#include "cslerror.h"
#include "externs.h"
#include "read.h"
#include "stream.h"
#include "arith.h"
#include "entries.h"
#ifdef COMMON
#include "clsyms.h"
#endif
#ifdef TIMEOUT
#include "timeout.h"
#endif

#ifdef SOCKETS
#include "sockhdr.h"
#endif

#ifdef CWIN
#include "cwin.h"
#endif

FILE *spool_file = NULL;
char spool_file_name[32];

int32 terminal_column = 0;

int32 terminal_line_length = (int32)0x80000000;

#ifdef CWIN
#define default_terminal_line_length cwin_linelength
#else
#define default_terminal_line_length 80
#endif

#define VPRINTF_CHUNK 256

#ifdef BUFFERED_STDOUT

static int print_buffn = 0;
#define PRINT_BUFSIZE 8000
static char print_buffer[PRINT_BUFSIZE+VPRINTF_CHUNK];

clock_t last_flush = 0;

void ensure_screen()
{
/*
 * Some of what is going on here is that I arrange to discount time spent
 * actually writing characters to the screen.
 */
#ifdef SOCKETS
    if (socket_server != 0) flush_socket();
#endif
    if (print_buffn != 0)
    {   push_clock();
/*
 * Time spend writing to the screen is explicitly discounted from measurements
 * of time spent in CSL...
 */
#ifdef WINDOW_SYSTEM
        {
#ifdef CWIN
            print_buffer[print_buffn] = 0;
            cwin_puts(print_buffer);
#else
            int i;
            for (i=0; i<print_buffn; i++)
                putc_stdout(print_buffer[i]);
#endif
            flush_screen();
        }
#else
        fwrite(print_buffer, 1, print_buffn, stdout);
        fflush(stdout); fflush(stderr);
#endif
        print_buffn = 0;
        pop_clock();
        last_flush = base_time;
    }
    else last_flush = read_clock();
}

#else

void ensure_screen()
{
#ifdef SOCKETS
    if (socket_server != 0) flush_socket();
#endif
    fflush(stdout);
}


#endif

void MS_CDECL term_printf(char *fmt, ...)
{
    va_list a;
    char print_temp[VPRINTF_CHUNK], *p;
    int n;
    va_start(a, fmt);
    n = vsprintf(print_temp, fmt, a);
    p = print_temp;
    while (n-- > 0) char_to_terminal(*p++, 0);
    va_end(a);
}

void MS_CDECL stdout_printf(char *fmt, ...)
{
    va_list a;
    char print_temp[VPRINTF_CHUNK], *p;
    int n;
    nil_as_base
    Lisp_Object stream = qvalue(standard_output);
    if (!is_stream(stream)) stream = qvalue(terminal_io);
    if (!is_stream(stream)) stream = lisp_terminal_io;
    va_start(a, fmt);
    n = vsprintf(print_temp, fmt, a);
    p = print_temp;
    while (n-- > 0) putc_stream(*p++, stream);
    va_end(a);
}

void MS_CDECL err_printf(char *fmt, ...)
{
    va_list a;
    char print_temp[VPRINTF_CHUNK], *p;
    int n;
    nil_as_base
    Lisp_Object stream = qvalue(error_output);
    if (!is_stream(stream)) stream = qvalue(terminal_io);
    if (!is_stream(stream)) stream = lisp_terminal_io;
    va_start(a, fmt);
    n = vsprintf(print_temp, fmt, a);
    p = print_temp;
    while (n-- > 0) putc_stream(*p++, stream);
    va_end(a);
}

void MS_CDECL debug_printf(char *fmt, ...)
{
    va_list a;
    char print_temp[VPRINTF_CHUNK], *p;
    int n;
    nil_as_base
    Lisp_Object stream = qvalue(debug_io);
    if (!is_stream(stream)) stream = qvalue(terminal_io);
    if (!is_stream(stream)) stream = lisp_terminal_io;
    va_start(a, fmt);
    n = vsprintf(print_temp, fmt, a);
    p = print_temp;
    while (n-- > 0) putc_stream(*p++, stream);
    va_end(a);
}

void MS_CDECL trace_printf(char *fmt, ...)
{
    va_list a;
    char print_temp[VPRINTF_CHUNK], *p;
    int n;
    nil_as_base
    Lisp_Object stream = qvalue(trace_output);
    if (!is_stream(stream)) stream = qvalue(terminal_io);
    if (!is_stream(stream)) stream = lisp_terminal_io;
    va_start(a, fmt);
    n = vsprintf(print_temp, fmt, a);
    p = print_temp;
    while (n-- > 0) putc_stream(*p++, stream);
    va_end(a);
}

Lisp_Object Ltyo(Lisp_Object nil, Lisp_Object a)
{
/*
 * Print a character given its character code.  NOTE that in earlier
 * versions of CSL this always printed to the standard output regardless
 * of what output stream was selected. Such a curious behaviour was
 * provided for use when magic characters sent to the standard output had
 * odd behaviour (eg caused graphics effects).  Now tyo is a more
 * sensible function for use across all systems. To be generous it
 * accepts either a character or a numeric code.
 */
    int c;
    Lisp_Object stream = qvalue(standard_output);
    CSL_IGNORE(nil);
    if (a == CHAR_EOF) return onevalue(a);
    else if (is_char(a)) c = (int)code_of_char(a);
    else if (is_fixnum(a)) c = (int)int_of_fixnum(a);
    else return aerror1("tyo", a);
    push(a);
    if (!is_stream(stream)) stream = qvalue(terminal_io);
    if (!is_stream(stream)) stream = lisp_terminal_io;
    putc_stream(c, stream);
    pop(a);
    errexit();
    return onevalue(a);
}

int char_to_illegal(int c, Lisp_Object f)
{
    Lisp_Object nil = C_nil;
    CSL_IGNORE(c);
    CSL_IGNORE(f);
    if (exception_pending()) return 1;
    aerror1("Attempt to write to an input stream or one that has been closed",
            stream_type(f));
    return 1;
}

int char_from_illegal(Lisp_Object f)
{
    Lisp_Object nil = C_nil;
    CSL_IGNORE(f);
    if (exception_pending()) return EOF;
    aerror1("Attempt to read from an output stream or one that has been closed",
            stream_type(f));
    return EOF;
}

int32 write_action_illegal(int32 op, Lisp_Object f)
{
    CSL_IGNORE(f);
    if (op == WRITE_GET_INFO+WRITE_IS_CONSOLE) return 0;
    if (op != WRITE_CLOSE)
        aerror1("Illegal operation on stream",
                cons_no_gc(fixnum_of_int(op >> 8), stream_type(f)));
    return 0;
}

int32 write_action_file(int32 op, Lisp_Object f)
{
    int32 w;
    switch (op & 0xf0000000)
    {
case WRITE_CLOSE:
        if (stream_file(f) == NULL) op = 0;
        else op = fclose(stream_file(f));
        set_stream_write_fn(f, char_to_illegal);
        set_stream_write_other(f, write_action_illegal);
        set_stream_read_fn(f, char_from_illegal);
        set_stream_read_other(f, read_action_illegal);
        set_stream_file(f, NULL);
        return op;
case WRITE_FLUSH:
        return fflush(stream_file(f));
case WRITE_SET_LINELENGTH_DEFAULT:
        op = 80;  /* drop through */
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
        {
    case WRITE_GET_LINE_LENGTH: return stream_line_length(f);
    case WRITE_GET_COLUMN:      return stream_char_pos(f);
    case WRITE_IS_CONSOLE:      return 0;
    default:return 0;
        }
default:
        return 0;
    }
}

#ifdef PIPES

int32 write_action_pipe(int32 op, Lisp_Object f)
{
    int32 w;
    if (op < 0) return -1;
    else switch (op & 0xf0000000)
    {
case WRITE_CLOSE:
        my_pclose(stream_file(f));
        set_stream_write_fn(f, char_to_illegal);
        set_stream_write_other(f, write_action_illegal);
        set_stream_file(f, NULL);
        return 0;
case WRITE_FLUSH:
        return my_pipe_flush(stream_file(f));
case WRITE_SET_LINELENGTH_DEFAULT:
        op = 80;  /* drop through */
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
        {
    case WRITE_GET_LINE_LENGTH: return stream_line_length(f);
    case WRITE_GET_COLUMN:      return stream_char_pos(f);
    case WRITE_IS_CONSOLE:      return 0;
    default:return 0;
        }
default:
        return 0;
    }
}

#else

int32 write_action_pipe(int32 op, Lisp_Object f)
{
    CSL_IGNORE(op); CSL_IGNORE(f);
    return -1;
}

#endif

int32 write_action_terminal(int32 op, Lisp_Object dummy)
{
    int32 w;
    CSL_IGNORE(dummy);
    if (op < 0) return -1;
    else switch (op & 0xf0000000)
    {
case WRITE_CLOSE:
        return 0;   /* I will never close the terminal stream */
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
        {
    case WRITE_GET_LINE_LENGTH: w = terminal_line_length;
                                if (w == 0x80000000)
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

int32 write_action_list(int32 op, Lisp_Object f)
{
    int32 w;
    if (op < 0) return -1;
    else switch (op & 0xf0000000)
    {
case WRITE_CLOSE:
        set_stream_write_fn(f, char_to_illegal);
        set_stream_write_other(f, write_action_illegal);
        set_stream_file(f, NULL);
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
        {
    case WRITE_GET_LINE_LENGTH: return 0x03ffffff;
    case WRITE_GET_COLUMN:      return stream_char_pos(f);
    case WRITE_IS_CONSOLE:      return 0;
    default:return 0;
        }
default:
        return 0;
    }
}

Lisp_Object Lstreamp(Lisp_Object nil, Lisp_Object a)
{
    return onevalue(Lispify_predicate(is_stream(a)));
}

Lisp_Object Lis_console(Lisp_Object nil, Lisp_Object a)
{
    int r1, r2;
    if (!is_stream(a)) return onevalue(nil);
    r1 = other_write_action(WRITE_GET_INFO+WRITE_IS_CONSOLE, a);
    r2 = other_read_action(READ_IS_CONSOLE, a);
    return onevalue(Lispify_predicate(r1 || r2));
}

Lisp_Object make_stream_handle()
{
    Lisp_Object w = getvector(TAG_VECTOR, TYPE_STREAM, STREAM_SIZE), nil;
    errexit();
    stream_type(w) = nil;
    stream_write_data(w) = nil;
    stream_read_data(w) = nil;
    set_stream_file(w, 0);
    set_stream_write_fn(w, char_to_illegal);
    set_stream_write_other(w, write_action_illegal);
    stream_line_length(w) = 80;
    stream_char_pos(w) = 0;
    set_stream_read_fn(w, char_from_illegal);
    set_stream_read_other(w, read_action_illegal);
    stream_pushed_char(w) = NOT_CHAR;
    return w;
}

#ifdef COMMON

Lisp_Object MS_CDECL Lmake_broadcast_stream_n(Lisp_Object nil, int nargs, ...)
{
    Lisp_Object r = nil, w, w1;
    va_list a;
    va_start(a, nargs);
    push_args(a, nargs);
    while (nargs > 1)
    {   pop2(w, w1);
        nargs-=2;
        r = list2star(w1, w, r);
        errexitn(nargs);
    }
    while (nargs > 0)
    {   pop(w);
        nargs--;
        r = cons(w, r);
        errexitn(nargs);
    }
    push(r);
    w = make_stream_handle();
    pop(r);
    errexit();
    set_stream_write_fn(w, char_to_broadcast);
    set_stream_write_other(w, write_action_broadcast);
    stream_write_data(w) = r;
    return onevalue(w);
}

Lisp_Object Lmake_broadcast_stream_1(Lisp_Object nil, Lisp_Object a)
{
    return Lmake_broadcast_stream_n(nil, 1, a);
}

Lisp_Object Lmake_broadcast_stream_2(Lisp_Object nil, Lisp_Object a, Lisp_Object b)
{
    return Lmake_broadcast_stream_n(nil, 2, a, b);
}

Lisp_Object MS_CDECL Lmake_concatenated_stream_n(Lisp_Object nil, int nargs, ...)
{
    Lisp_Object r = nil, w, w1;
    va_list a;
    va_start(a, nargs);
    push_args(a, nargs);
    while (nargs > 1)
    {   pop2(w, w1);
        nargs-=2;
        r = list2star(w1, w, r);
        errexitn(nargs);
    }
    while (nargs > 0)
    {   pop(w);
        nargs--;
        r = cons(w, r);
        errexitn(nargs);
    }
    push(r);
    w = make_stream_handle();
    pop(r);
    errexit();
    set_stream_read_fn(w, char_from_concatenated);
    set_stream_read_other(w, read_action_concatenated);
    stream_read_data(w) = r;
    return onevalue(w);
}

Lisp_Object Lmake_concatenated_stream_1(Lisp_Object nil, Lisp_Object a)
{
    return Lmake_concatenated_stream_n(nil, 1, a);
}

Lisp_Object Lmake_concatenated_stream_2(Lisp_Object nil, Lisp_Object a, Lisp_Object b)
{
    return Lmake_concatenated_stream_n(nil, 2, a, b);
}

Lisp_Object Lmake_synonym_stream(Lisp_Object nil, Lisp_Object a)
{
    Lisp_Object w;
    if (!is_symbol(a)) return aerror1("make-synonym-stream", a);
    push(a);
    w = make_stream_handle();
    pop(a);
    errexit();
    set_stream_write_fn(w, char_to_synonym);
    set_stream_write_other(w, write_action_synonym);
    stream_write_data(w) = a;
    set_stream_read_fn(w, char_from_synonym);
    set_stream_read_other(w, read_action_synonym);
    stream_read_data(w) = a;
    return onevalue(w);
}

Lisp_Object Lmake_two_way_stream(Lisp_Object nil, Lisp_Object a, Lisp_Object b)
{
    Lisp_Object w;
    if (!is_symbol(a)) return aerror1("make-two-way-stream", a);
    if (!is_symbol(b)) return aerror1("make-two-way-stream", b);
    push2(a, b);
    w = make_stream_handle();
    pop2(b, a);
    errexit();
    set_stream_write_fn(w, char_to_synonym);
    set_stream_write_other(w, write_action_synonym);
    stream_write_data(w) = b;
    set_stream_read_fn(w, char_from_synonym);
    set_stream_read_other(w, read_action_synonym);
    stream_read_data(w) = a;
    return onevalue(w);
}

Lisp_Object Lmake_echo_stream(Lisp_Object nil, Lisp_Object a, Lisp_Object b)
{
    Lisp_Object w;
    if (!is_symbol(a)) return aerror1("make-echo-stream", a);
    if (!is_symbol(b)) return aerror1("make-echo-stream", b);
    push2(a, b);
    w = make_stream_handle();
    pop2(b, a);
    errexit();
    set_stream_write_fn(w, char_to_synonym);
    set_stream_write_other(w, write_action_synonym);
    stream_write_data(w) = b;
    set_stream_read_fn(w, char_from_echo);
    set_stream_read_other(w, read_action_synonym);
    stream_read_data(w) = a;
    return onevalue(w);
}

Lisp_Object MS_CDECL Lmake_string_input_stream_n(Lisp_Object nil, int nargs, ...)
{
    CSL_IGNORE(nil); CSL_IGNORE(nargs);
    return aerror("make-string-input-stream");
}

Lisp_Object Lmake_string_input_stream_1(Lisp_Object nil, Lisp_Object a)
{
    return Lmake_string_input_stream_n(nil, 1, a);
}

Lisp_Object Lmake_string_input_stream_2(Lisp_Object nil, Lisp_Object a, Lisp_Object b)
{
    return Lmake_string_input_stream_n(nil, 2, a, b);
}

Lisp_Object MS_CDECL Lmake_string_output_stream(Lisp_Object nil, int nargs, ...)
{
    Lisp_Object w;
    argcheck(nargs, 0, "make-string-output-stream");
    w = make_stream_handle();
    errexit();
    set_stream_write_fn(w, code_to_list);
    set_stream_write_other(w, write_action_list);
    return onevalue(w);
}

Lisp_Object Lget_output_stream_string(Lisp_Object nil, Lisp_Object a)
{
    Lisp_Object w;
    int32 n, k;
    if (!is_stream(a)) return aerror1("get-output-stream-string", a);
    w = stream_write_data(a);
    n = stream_char_pos(a);
    stream_write_data(a) = nil;
    stream_char_pos(a) = 0;
    push(w);
    a = getvector(TAG_VECTOR, TYPE_STRING, n+4);
    pop(w);
    errexit();
    k = (n + 3) & ~(int32)7;
    *(int32 *)((char *)a + k + 4 - TAG_VECTOR) = 0;
    if (k != 0) *(int32 *)((char *)a + k - TAG_VECTOR) = 0;
    while (n > 0)
    {   n--;
        celt(a, n) = int_of_fixnum(qcar(w));
        w = qcdr(w);
    }
    return a;
}

#endif /* COMMON */

/*
 * (make-function-stream 'fn) makes a stream where output just passes
 * characters to the given function.
 */

Lisp_Object Lmake_function_stream(Lisp_Object nil, Lisp_Object a)
{
    Lisp_Object w;
    if (!is_symbol(a)) return aerror1("make-function-stream", a);
    push(a);
    w = make_stream_handle();
    pop(a);
    errexit();
    set_stream_write_fn(w, char_to_function);
    set_stream_write_other(w, write_action_list);
    stream_write_data(w) = a;
    return onevalue(w);
}

int char_to_terminal(int c, Lisp_Object dummy)
{
    CSL_IGNORE(dummy);
    if (c == '\n' || c == '\f') terminal_column = 0;
    else terminal_column++;
    if (spool_file != NULL)
    {   putc(c, spool_file);
#ifdef DEBUG
        fflush(spool_file);
#endif
    }
    if (procedural_output != NULL) return (*procedural_output)(c);
#ifdef WINDOW_SYSTEM
    if (alternative_stdout != NULL)
    {   putc(c, alternative_stdout);
        return 0;
    }
#endif
#ifdef BUFFERED_STDOUT
    print_buffer[print_buffn++] = c;
    if (print_buffn > PRINT_BUFSIZE) ensure_screen();
#else
/*
 * Note that if I have a windowed system then BUFFERED_STDOUT will always
 * be set, so the case here is JUST for when I have direct output to the
 * ordinary stdout file, with no Lisp-level buffering.
 */
    putchar(c);
#endif
    return 0;   /* indicate success */
}

int char_to_file(int c, Lisp_Object stream)
{
    if (c == '\n' || c == '\f') stream_char_pos(stream) = 0;
    else stream_char_pos(stream)++;
    putc(c, stream_file(stream));
    return 0;   /* indicate success */
}

int char_to_synonym(int c, Lisp_Object f)
{
    f = qvalue(stream_write_data(f));
    if (!is_stream(f)) return 1;
    return putc_stream(c, f);
}

int char_to_function(int c, Lisp_Object f)
{
    Lisp_Object nil = C_nil;
    f = stream_write_data(f);  /* name of the function to call */
    (*qfn1(f))(qenv(f), pack_char(0, 0, c & 0xff));
    errexit();
    return 0;    /* return 0 for success */
}

int char_to_broadcast(int c, Lisp_Object f)
{
    Lisp_Object l = stream_write_data(f);
    int r = 0;
    Lisp_Object nil = C_nil;
    while (consp(l))
    {   f = qcar(l);
        l = qcdr(l);
        if (!is_symbol(f)) continue;
        f = qvalue(f);
        if (!is_stream(f)) continue;
        push(l);
        r = r | putc_stream(c, f);
        pop(l);
        errexit();
    }
    return r;
}

int32 write_action_synonym(int32 c, Lisp_Object f)
{
    int r;
    Lisp_Object f1 = qvalue(stream_write_data(f));
    if (!is_stream(f1))
        return aerror1("attempt to act on",
                        cons_no_gc(fixnum_of_int(c >> 8), f));
    r = other_write_action(c, f1);
    if (c == WRITE_CLOSE)
    {   set_stream_write_fn(f, char_to_illegal);
        set_stream_write_other(f, write_action_illegal);
        set_stream_file(f, NULL);
    }
    return r;
}

int32 write_action_broadcast(int32 c, Lisp_Object f)
{
    int r = 0, r1;
    Lisp_Object l = stream_write_data(f), f1;
    Lisp_Object nil = C_nil;
    while (consp(l))
    {   f1 = qcar(l);
        l = qcdr(l);
        if (!is_symbol(f1)) continue;
        f1 = qvalue(f1);
        if (!is_stream(f1)) continue;
        push2(l, f);
        r1 = other_write_action(c, f1);
        pop2(f, l);
        errexit();
        if (r == 0) r = r1;
    }
    if (c == WRITE_CLOSE)
    {   set_stream_write_fn(f, char_to_illegal);
        set_stream_write_other(f, write_action_illegal);
        set_stream_file(f, NULL);
    }
    return r;
}

#ifdef PIPES

int char_to_pipeout(int c, Lisp_Object stream)
{
    if (c == '\n' || c == '\f') stream_char_pos(stream) = 0;
    else stream_char_pos(stream)++;
    my_pipe_putc(c, stream_file(stream));
    return 0;   /* indicate success */
}

#else

int char_to_pipeout(int c, Lisp_Object stream)
{
    return char_to_illegal(c, stream);
}

#endif

char *get_string_data(Lisp_Object name, char *why, int32 *len)
{
    Lisp_Object nil = C_nil;
    Header h;
#ifdef COMMON
    if (complex_stringp(name))
    {   name = simplify_string(name);
        nil = C_nil;
        if (exception_pending()) return NULL;
        h = vechdr(name);
    }
    else
#endif
    if (symbolp(name))
    {   name = get_pname(name);
        nil = C_nil;
        if (exception_pending()) return NULL;
        h = vechdr(name);
    }
    else if (!(is_vector(name)))
    {   aerror1(why, name);
        return NULL;
    }
    else if (type_of_header(h = vechdr(name)) != TYPE_STRING)
    {   aerror1(why, name);
        return NULL;
    }
    *len = length_of_header(h) - 4;
    return &celt(name, 0);
}

static Lisp_Object Lfiledate(Lisp_Object nil, Lisp_Object name)
{
    char filename[LONGEST_LEGAL_FILENAME], tt[32];
    int32 len;
    char *w = get_string_data(name, "filep", &len);
    errexit();
    if (len >= sizeof(filename)) len = sizeof(filename);
    if (!file_exists(filename, w,
                     (size_t)len, tt)) return onevalue(nil);
    tt[24] = 0;
    name = make_string(tt);
    errexit();
    return onevalue(name);
}

static Lisp_Object Lfilep(Lisp_Object nil, Lisp_Object name)
{
    name = Lfiledate(nil, name);
    errexit();
    if (name != nil) name = lisp_true;
    return onevalue(name);
}

Lisp_Object MS_CDECL Ltmpnam(Lisp_Object nil, int nargs, ...)
/*
 * Returns a string that is suitable for use as the name of a temporary
 * file.
 */
{
    char *s;
    Lisp_Object r;
    argcheck(nargs, 0, "tmpnam");
    s = tmpnam(NULL);
    if (s == NULL) return onevalue(nil);  /* Sorry - can't do it */
    r = make_string(s);
    errexit();
    return onevalue(r);
}

#ifdef _DEBUG
FILE *myopen(char *f, char *m)
{
    FILE *s = fopen(f, m);
    trace_printf("fopen(%s, %s) = %p\n", f, m, s);
    return s;
}
#define fopen(a, b) myopen(a, b)
#endif

/*
 * The Common Lisp keywords for OPEN are a horrid mess. I arrange to decode
 * the syntax of the keywords in a Lisp-coded wrapper function, and in that
 * code I will also fill in default values for any that needs same. I then
 * pack all the information into a single integer, which has several
 * sub-fields
 *
 * x x xx xxx 00   direction PROBE
 * x x xx xxx 01             INPUT
 * x x xx xxx 10             OUTPUT
 * x x xx xxx 11             IO
 *
 * x x xx 000 xx   if-exists NIL
 * x x xx 001 xx             overwrite
 * x x xx 010 xx             append
 * x x xx 011 xx             rename
 * x x xx 100 xx             error
 * x x xx 101 xx             (new-version)
 * x x xx 110 xx             (supersede)
 * x x xx 111 xx             (rename-and-delete)
 *
 * x x 00 xxx xx   if-does-not-exist NIL
 * x x 01 xxx xx                     create
 * x x 10 xxx xx                     error
 *
 * x 0 xx xxx xx   regular text file
 * x 1 xx xxx xx   open for binary access
 *
 * 0 x xx xxx xx   regular file
 * 1 x xx xxx xx   open as a pipe
 */

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

Lisp_Object Lopen(Lisp_Object nil, Lisp_Object name, Lisp_Object dir)
{
    FILE *file;
    Lisp_Object r;
    char filename[LONGEST_LEGAL_FILENAME], fn1[LONGEST_LEGAL_FILENAME];
    int32 len;
    char *w;
    int d;
#ifdef PIPES
    CSLbool pipep = NO;
#endif
    if (!is_fixnum(dir)) return aerror1("open", dir);
    d = (int)int_of_fixnum(dir);

#ifdef SOCKETS
/*
 * If I am working as a socket server I will prohibit operations that
 * could (easily) corrupt the local machine. Here I prevent anybody from
 * opening files for output. I also prevent use of pipes.
 */
    if (socket_server != 0 &&
        ((d & DIRECTION_MASK) == DIRECTION_OUTPUT ||
         (d & DIRECTION_MASK) == DIRECTION_IO ||
         (d & OPEN_PIPE) != 0))
        return aerror1("open invalid in server mode", dir);
#endif

#ifdef DEBUG_OPENING_FILES
    trace_printf("Open file:");
    switch (d & DIRECTION_MASK)
    {
case DIRECTION_PROBE: trace_printf(" probe");  break;
case DIRECTION_INPUT: trace_printf(" input");  break;
case DIRECTION_OUTPUT:trace_printf(" output"); break;
case DIRECTION_IO:    trace_printf(" io");     break;
    }
    switch (d & IF_EXISTS_MASK)
    {
case IF_EXISTS_NIL:                trace_printf(" if-exists-nil"); break;
case IF_EXISTS_OVERWRITE:          trace_printf(" if-exists-overwrite"); break;
case IF_EXISTS_APPEND:             trace_printf(" if-exists-append"); break;
case IF_EXISTS_RENAME:             trace_printf(" if-exists-rename"); break;
case IF_EXISTS_ERROR:              trace_printf(" if-exists-error"); break;
case IF_EXISTS_NEW_VERSION:        trace_printf(" if-exists-new-version"); break;
case IF_EXISTS_SUPERSEDE:          trace_printf(" if-exists-supersede"); break;
case IF_EXISTS_RENAME_AND_DELETE:  trace_printf(" if-exists-r-and-d"); break;
    }
    switch (d & IF_MISSING_MASK)
    {
case IF_MISSING_NIL:                trace_printf(" if-missing-nil"); break;
case IF_MISSING_CREATE:             trace_printf(" if-missing-create"); break;
case IF_MISSING_ERROR:              trace_printf(" if-missing-error"); break;
    }
    if (d & OPEN_BINARY) trace_printf(" binary");
    if (d & OPEN_PIPE) trace_printf(" pipe");
    trace_printf("\n");
#endif

    w = get_string_data(name, "open", &len);
    errexit();
    if (len >= sizeof(filename)) len = sizeof(filename);

    switch (d & (DIRECTION_MASK | OPEN_PIPE))
    {
case DIRECTION_PROBE:      /* probe file - can not be used with pipes */
        file = open_file(filename, w, (size_t)len, "r", NULL);
        if (file == NULL)
        {   switch (d & IF_MISSING_MASK)
            {
        case IF_MISSING_NIL:
                return onevalue(nil);
        case IF_MISSING_ERROR:
                return error(1, err_open_failed, name);
        case IF_MISSING_CREATE:
/*
 * I thing that people who go (open xxx :direction :probe
 *                                      :if-does-not-exist :create)
 * are to be considered unduly enthusiastic, but I will still try to do what
 * they tell me to!
 */
                file = open_file(filename, w, (size_t)len, "w", NULL);
                if (file == NULL) return error(1, err_open_failed, name);
                fclose(file);
                file = NULL;
            }
        }
        else
        {   fclose(file);
            file = NULL;
        }
        break;        /* Must then create a no-direction stream */

case DIRECTION_INPUT:
        file = open_file(filename, w, (size_t)len,
#ifdef NO_BINARY_OPEN
                         "r",
#else
                         (d & OPEN_BINARY ? "rb" : "r"),
#endif
                         NULL);
        if (file == NULL)
        {   switch (d & IF_MISSING_MASK)
            {
        case IF_MISSING_NIL:
                return onevalue(nil);
        case IF_MISSING_ERROR:
                return error(1, err_open_failed, name);
        case IF_MISSING_CREATE:
                file = open_file(filename, w,
                                 (size_t)len, "w", NULL);
                if (file == NULL) return error(1, err_open_failed, name);
                fclose(file);
/*
 * I use fopen(xx,"w") to create the file, then close it again and re-open
 * for input, so that concurrent tasks can see the file now existing but
 * only open for reading. If opening the file I just created fails I will
 * give up.
 */
                file = open_file(filename, w, (size_t)len,
#ifdef NO_BINARY_OPEN
                                 "r",
#else
                                 (d & OPEN_BINARY ? "rb" : "r"),
#endif
                                 NULL);
                if (file == NULL) return error(1, err_open_failed, name);
                break;

            }
        }
        break;  /* if-exists ignored when opening for input */

case DIRECTION_OUTPUT:
case DIRECTION_IO:
/*
 * I will start by trying to open the file to see if it exists. By using
 * mode "r+" I will only open it if I am able to obtain write-access, and
 * in some cases I will then be able to make use of the file. The fact that
 * it will have been opened for IO not just output will not harm me.
 */
        file = open_file(filename, w, (size_t)len,
#ifdef NO_BINARY_OPEN
                         "r+",
#else
                         (d & OPEN_BINARY ? "r+b" : "r+"),
#endif
                         NULL);
        if (file == NULL) switch (d & IF_MISSING_MASK)
        {
    case IF_MISSING_NIL:
            return onevalue(nil);
    case IF_MISSING_ERROR:
            return error(1, err_open_failed, name);
    case IF_MISSING_CREATE:
            break;          /* usual case for output and IO files */
        }
        else switch (d & IF_EXISTS_MASK)
        {
    case IF_EXISTS_NIL:
            fclose(file);
            return onevalue(nil);
    case IF_EXISTS_RENAME:
/*
 * When I open a file with :if-exists :rename I will always rename to
 * a fixed target, "oldfile.bak". If the rename fails I will not worry too
 * much. I imagine some people would rather that the name I renamed to was
 * based on the original file-name, but that seems excessive to me. And I
 * would have little sympathy for users who relied on it!
 */
            fclose(file);
            file = NULL;
            rename_file(filename, w, (size_t)len,
                        fn1, "oldfile.bak", 11);
            break;
    case IF_EXISTS_ERROR:
            fclose(file);
            return error(1, err_open_failed, name);
/*
 * Working through the standard C library the ideas of :new-version,
 * :supersede and :rename-and-delete seem rather odd, so I will just treat
 * them all as :new-version.
 */
    case IF_EXISTS_SUPERSEDE:
    case IF_EXISTS_RENAME_AND_DELETE:
    case IF_EXISTS_NEW_VERSION:
            fclose(file);
            delete_file(filename, w, (size_t)len);
            file = NULL;
            break;
    case IF_EXISTS_OVERWRITE:
            break;
    case IF_EXISTS_APPEND:
            fseek(file, 0L, SEEK_END);
            break;
        }
        if (file == NULL)
        {   file = open_file(filename, w,
                             (size_t)len,
#ifdef NO_BINARY_OPEN
                             "w+",
#else
                             (d & OPEN_BINARY ? "w+b" : "w+"),
#endif
                             NULL);
            if (file == NULL) return error(1, err_open_failed, name);
        }
        break;


case DIRECTION_OUTPUT | OPEN_PIPE:
#ifdef PIPES
        pipep = YES;
        memcpy(filename, w, (size_t)len);
        filename[len] = 0;
#ifdef PIPES_SOMETIMES
        if (!pipes_today) file = NULL;
        else
#endif
            file = my_popen(filename, "w");
        if (file == NULL) return error(1, err_pipe_failed, name);
        break;
#else
        return aerror("pipes not available with this version of CSL");
#endif

case DIRECTION_INPUT | OPEN_PIPE:
case DIRECTION_IO | OPEN_PIPE:
        return aerror("reading from pipes is not supported in CCL\n");
    }


    push(name);
    r = make_stream_handle();
    pop(name);
    errexit();
    stream_type(r) = name;
    set_stream_file(r, file);
    switch (d & (DIRECTION_MASK | OPEN_PIPE))
    {
case DIRECTION_INPUT:
        set_stream_read_fn(r, char_from_file);
        set_stream_read_other(r, read_action_file);
        break;
#ifdef PIPES
case DIRECTION_OUTPUT | OPEN_PIPE:
        set_stream_write_fn(r, char_to_pipeout);
        set_stream_write_other(r, write_action_pipe);
        break;
#endif
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

Lisp_Object Lwrs(Lisp_Object nil, Lisp_Object a)
{
    Lisp_Object old = qvalue(standard_output);
    if (a == nil) a = qvalue(terminal_io);
    if (a == old) return onevalue(old);
    else if (!is_stream(a)) return aerror1("wrs", a);
    else if (stream_write_fn(a) == char_to_illegal)
#ifdef COMMON
        a = qvalue(terminal_io);
#else
        return aerror("wrs (closed or input file)"); /* closed file or input file */
#endif
    qvalue(standard_output) = a;
    return onevalue(old);
}

Lisp_Object Lclose(Lisp_Object nil, Lisp_Object a)
{
/*
 * I will not allow anybody to close the terminal streams
 */
    if (a == nil ||
        a == lisp_terminal_io) return onevalue(nil);
    else if (!is_stream(a)) return aerror1("close", a);
    if (a == qvalue(standard_input))
        qvalue(standard_input) = lisp_terminal_io;
    else if (a == qvalue(standard_output))
        qvalue(standard_output) = lisp_terminal_io;
    other_read_action(READ_CLOSE, a);
    other_write_action(WRITE_CLOSE, a);
#ifdef COMMON
    return onevalue(lisp_true);
#else
    return onevalue(nil);
#endif
}

Lisp_Object Ltruename(Lisp_Object nil, Lisp_Object name)
{
    char filename[LONGEST_LEGAL_FILENAME];
    Lisp_Object truename;
    int32 len;
    char *w = get_string_data(name, "truename", &len);
    errexit();
    if (len >= sizeof(filename)) len = sizeof(filename);

    w = get_truename(filename,w,len);

    truename = make_string(w);
    free(w);
    errexit();

    return onevalue(truename);
}

Lisp_Object Lcreate_directory(Lisp_Object nil, Lisp_Object name)
{
    char filename[LONGEST_LEGAL_FILENAME];
    int32 len;
    char *w = get_string_data(name, "create-directory", &len);
    errexit();
    if (len >= sizeof(filename)) len = sizeof(filename);
#ifdef SOCKETS
    if (socket_server != 0) return aerror("create-directory");
#endif

    len = create_directory(filename, w, (size_t)len);
    return onevalue(Lispify_predicate(len == 0));
}

Lisp_Object Lfile_readable(Lisp_Object nil, Lisp_Object name)
{
    char filename[LONGEST_LEGAL_FILENAME];
    int32 len;
    char *w = get_string_data(name, "file-readable", &len);
    errexit();
    if (len >= sizeof(filename)) len = sizeof(filename);

    len = file_readable(filename, w, (size_t)len);
    return onevalue(Lispify_predicate(len));
}

Lisp_Object Lchange_directory(Lisp_Object nil, Lisp_Object name)
{
    char filename[LONGEST_LEGAL_FILENAME];
    int32 len;
    char *w = get_string_data(name, "change-directory", &len);
    errexit();
    if (len >= sizeof(filename)) len = sizeof(filename);
/*
 * At present I will permit change-directory in server mode.
 */

    len = change_directory(filename, w, (size_t)len);
    return onevalue(Lispify_predicate(len == 0));
}

Lisp_Object Lfile_writeable(Lisp_Object nil, Lisp_Object name)
{
    char filename[LONGEST_LEGAL_FILENAME];
    int32 len;
    char *w;

    /* First check whether file exists */
    if (Lfilep(nil,name) == nil) return nil;

    w = get_string_data(name, "file-writable", &len);
    errexit();
    if (len >= sizeof(filename)) len = sizeof(filename);

    len = file_writeable(filename, w, (size_t)len);
    return onevalue(Lispify_predicate(len));
}

Lisp_Object Ldelete_file(Lisp_Object nil, Lisp_Object name)
{
    char filename[LONGEST_LEGAL_FILENAME];
    int32 len;
    char *w = get_string_data(name, "delete-file", &len);
    errexit();
    if (len >= sizeof(filename)) len = sizeof(filename);
#ifdef SOCKETS
    if (socket_server != 0) return aerror("delete-file");
#endif

    len = delete_file(filename, w, (size_t)len);
    return onevalue(Lispify_predicate(len == 0));
}

Lisp_Object Ldirectoryp(Lisp_Object nil, Lisp_Object name)
{
    char filename[LONGEST_LEGAL_FILENAME];
    int32 len;
    char *w = get_string_data(name, "directoryp", &len);
    errexit();
    if (len >= sizeof(filename)) len = sizeof(filename);

    len = directoryp(filename, w, (size_t)len);
    return onevalue(Lispify_predicate(len));
}


Lisp_Object MS_CDECL Lget_current_directory(Lisp_Object nil, int nargs, ...)
{
    char filename[LONGEST_LEGAL_FILENAME];
    int len;
    Lisp_Object w;
    argcheck(nargs, 0, "get-current-directory");
    len = get_current_directory(filename, LONGEST_LEGAL_FILENAME);
    if (len == 0) return onevalue(nil);
    w = make_string(filename);
    errexit();
    return onevalue(w);
}

Lisp_Object MS_CDECL Luser_homedir_pathname(Lisp_Object nil, int32 nargs, ...)
{
    char home[LONGEST_LEGAL_FILENAME];
    int len;
    Lisp_Object w;
    argcheck(nargs, 0, "user-homedir-pathname")
    len = get_home_directory(home, LONGEST_LEGAL_FILENAME);
    if (len == 0) return onevalue(nil);
    w = make_string(home);
    errexit();
    return onevalue(w);
}

Lisp_Object MS_CDECL Lget_lisp_directory(Lisp_Object nil, int nargs, ...)
{
    char filename[LONGEST_LEGAL_FILENAME];
    int len;
    Lisp_Object w;
    argcheck(nargs, 0, "get-lisp-directory");
    strcpy(filename, standard_directory);
    len = strlen(filename);
    while (len-- > 0 &&
           filename[len] != '/' &&
           filename[len] != '\\');
    if (len == 0) return onevalue(nil);
    filename[len] = 0;
    w = make_string(filename);
    errexit();
    return onevalue(w);
}

Lisp_Object Lrename_file(Lisp_Object nil, Lisp_Object from, Lisp_Object to)
{
    char from_name[LONGEST_LEGAL_FILENAME], to_name[LONGEST_LEGAL_FILENAME];
    int32 from_len, to_len;
    char *from_w, *to_w;
#ifdef SOCKETS
    if (socket_server != 0) return aerror("rename-file");
#endif
    push(to);
    from_w = get_string_data(from, "rename-file", &from_len);
    pop(to);
    errexit();
    if (from_len >= sizeof(from_name)) from_len = sizeof(from_name);
    from = (Lisp_Object)(from_w + TAG_VECTOR - 4);

    push(from);
    to_w = get_string_data(to, "rename-file", &to_len);
    pop(from);
    from_w = &celt(from, 0);
    errexit();
    if (to_len >= sizeof(to_name)) to_len = sizeof(to_name);

    to_len = rename_file(from_name, from_w, (size_t)from_len,
                         to_name, to_w, (size_t)to_len);
    return onevalue(Lispify_predicate(to_len == 0));
}

/*
 * This function is a call-back from the file-scanning routine.
 */

static void make_dir_list(char *name, int why, long int size)
{
    Lisp_Object nil = C_nil, w;
    CSL_IGNORE(why);
    CSL_IGNORE(size);
    errexitv();
    if (scan_leafstart >= (int)strlen(name)) return;
    w = make_string(name+scan_leafstart);
    errexitv();
    w = cons(w, stack[0]);
    errexitv();
    stack[0] = w;
}

Lisp_Object Llist_directory(Lisp_Object nil, Lisp_Object name)
{
    Lisp_Object result;
    char filename[LONGEST_LEGAL_FILENAME];
    int32 len;
    char *w = get_string_data(name, "list-directory", &len);
    errexit();
    if (len >= sizeof(filename)) len = sizeof(filename);
    push(nil);
    list_directory_members(filename, w,
                           (size_t)len, make_dir_list);
    pop(result);
    errexit();
    result = nreverse(result);
    errexit();
    return onevalue(result);
}


/*****************************************************************************/
/*      Printing.                                                            */
/*****************************************************************************/

int escaped_printing;

#define escape_yes          0x0001    /* make output re-readable  */

#define escape_fold_down    0x0002    /* force lower case output  */
#define escape_fold_up      0x0004    /* FORCE UPPER CASE OUTPUT  */
#define escape_capitalize   0x0008    /* Force Capitalisation (!) */

#define escape_binary       0x0010    /* print format for numbers */
#define escape_octal        0x0020    /* (including bignums)      */
#define escape_hex          0x0040
#define escape_nolinebreak  0x0080    /* use infinite line-length */
#define escape_hexwidth     0x3f00    /* 6 bits to specify width of hex/bin */
#define escape_width(n)     (((n) & escape_hexwidth) >> 8)
#define escape_checksum     0x4000    /* doing a checksum operation */

static void outprefix(CSLbool blankp, int32 len)
/*
 * This function takes most of the responsibility for splitting lines.
 * when called we are about to print an item with (len) characters.
 * If blankp is true we need to display a blank or newline before
 * the item.
 */
{
    nil_as_base
    int32 line_length =
        other_write_action(WRITE_GET_INFO+WRITE_GET_LINE_LENGTH,
                           active_stream);
    int32 column =
        other_write_action(WRITE_GET_INFO+WRITE_GET_COLUMN,
                           active_stream);
    if (column+len > line_length &&
        (escaped_printing & escape_nolinebreak) == 0)
        putc_stream('\n', active_stream);
    else if (blankp) putc_stream(' ', active_stream);
}

static Lisp_Object Lprint_precision(Lisp_Object nil, Lisp_Object a)
{
    int32 old = print_precision;
    if (a == nil) return onevalue(fixnum_of_int(old));
    if (!is_fixnum(a)) return aerror1("print-precision", a);
    print_precision = int_of_fixnum(a);
    if (print_precision > 16)
        print_precision = 15;
    return onevalue(fixnum_of_int(old));
}

static void prin_buf(char *buf, int blankp)
{
    Lisp_Object nil = C_nil;
    int len = strlen(buf), i;
    outprefix(blankp, len);
    for (i=0; i<len; i++)
    {   putc_stream(*buf++, active_stream);
        errexitv();
    }
}

static int32 local_gensym_count;

void internal_prin(Lisp_Object u, int blankp)
{
    Lisp_Object w, nil = C_nil;
    int32 len, k;
    char my_buff[68];
#ifdef COMMON
    int bl = blankp & 2;
/*
 * There is a fairly shameless FUDGE here. When I come to need to print
 * the package part of a symbol as in ppp:xxx (or even |)p(|::|.| if I
 * have names with silly characters in them) I will have a STRING that is the
 * name of the relevant package, but I want it displayed as if it was an
 * identifier. I achieve this by setting the "2" bit in blankp (which is
 * otherwise a simple boolean), and when this is detected I go and join the
 * code for printing symbols. But in that case I MUST have been passed
 * a (simple) string, or else things can collapse utterly.
 */
    blankp &= 1;
    if (bl != 0)
    {   w = u;
        push(u);
        goto tag_symbol;
    }
restart:
#endif
#ifdef SOFTWARE_TICKS
    if (--countdown < 0) deal_with_tick();
#endif
    errexitv();
    if (stack >= stacklimit)
    {   u = reclaim(u, "stack", GC_STACK, 0);
        errexitv();
    }
    switch ((int)u & TAG_BITS)
    {
case TAG_CONS:
#ifdef COMMON
        if (u == nil)           /* BEWARE - nil is tagged as a cons cell */
        {   outprefix(blankp, 3);
            putc_stream('N', active_stream);
            putc_stream('I', active_stream);
            putc_stream('L', active_stream);
            return;
        }
#endif
        if (u == 0) u = nil; /* Bug security here */
        push(u);
        outprefix(blankp, 1);
        putc_stream('(', active_stream);
        errexitvn(1);
        internal_prin(qcar(stack[0]), 0);
        errexitvn(1);
        w = stack[0];
        while (is_cons(w = qcdr(w)))
        {
#ifdef COMMON
            if (w == nil) break;    /* Again BEWARE the tag code of NIL */
#endif
            stack[0] = w;
            internal_prin(qcar(stack[0]), 1);
            errexitvn(1);
            w = stack[0];
        }
        if (w != nil)
        {   stack[0] = w;
            outprefix(YES, 1);
            putc_stream('.', active_stream);
            errexitvn(1);
            internal_prin(stack[0], 1);
        }
        popv(1);
        outprefix(NO, 1);
        putc_stream(')', active_stream);
        return;

#ifdef COMMON
case TAG_SFLOAT:
        {   Float_union uu;
            uu.i = u - TAG_SFLOAT;
            sprintf(my_buff, "%#.6g", (double)uu.f);
        }
        goto float_print_tidyup;
#endif

case TAG_FIXNUM:
        if (escaped_printing & escape_hex)
        {   int32 v = int_of_fixnum(u);
            int width = escape_width(escaped_printing);
            int32 mask;
/*
 * The printing style adopted here for negative numbers follows that used in
 * the big number printing code.  A prefix "~" stands for an infinite initial
 * string of 'f' digits, and what follows will be exactly one 'f' (just to
 * remind you) and then the remaining hex digits.  E.g. -2 should display
 * as ~fe.  Note that any fixnum will start off with 0xf in the top 4 of
 * 32 bits.  If an explicit width had been specified then I want that many
 * charcters to be displayed, with full leading zeros etc. A width is taken as
 * minimum number of chars to be displayed, so a width of zero (or in fact 1)
 * would have the effect of no constraint. The width-specification field
 * only allows for the range 0 to 63, and that is just as well since I put
 * characters in a buffer (my_buff) which would almost fill up at the
 * widest...
 */
            len = 0;
            if (v < 0)
            {   mask = 0x0f000000;
                my_buff[len++] = '~';
                width--;
                while ((v & mask) == mask && mask != 0)
                {   v = v ^ (mask << 4);
                    mask = mask >> 4;
                }
                k = 'f';
            }
            else k = '0';
            mask = 0xf;
            while ((v & mask) != v)
            {   width--;
                mask = (mask<<4) | 0xf;
            }
            while (--width > 0) my_buff[len++] = k;
            sprintf(&my_buff[len], "%lx", (long)v);
        }
        else if (escaped_printing & escape_octal)
        {   int32 v = int_of_fixnum(u);
            int width = escape_width(escaped_printing);
            int32 mask;
            len = 0;
            if (v < 0)
            {   mask = 0x38000000;
                my_buff[len++] = '~';
                width--;
                while ((v & mask) == mask && mask != 0)
                {   v = v ^ (mask << 3);
                    mask = mask >> 3;
                }
                k = '7';
            }
            else k = '0';
            mask = 0x7;
            while ((v & mask) != v)
            {   width--;
                mask = (mask<<3) | 0x7;
            }
            while (--width > 0) my_buff[len++] = k;
            sprintf(&my_buff[len], "%lo", (long)v);
        }
        else if (escaped_printing & escape_binary)
        {   int32 v = int_of_fixnum(u);
/*          int width = escape_width(escaped_printing); */
            unsigned32 mask = 0x40000000;
            len = 0;
            if (v < 0)
            {   while ((v & mask) == mask && mask != 0)
                {   v = v ^ (mask << 1);
                    mask = mask >> 1;
                }
                my_buff[len++] = '~';
                k = '1';
            }
            else k = '0';
/*
 * Width specifier not processed here (yet), sorry.
 */
            mask = 0x80000000;
            while ((v & mask) == 0 && mask != 1) mask = mask >> 1;
            while (mask != 0)
            {   my_buff[len++] = (v & mask) ? '1' : '0';
                mask = mask >> 1;
            }
            my_buff[len] = 0;
        }
        else
            sprintf(my_buff, "%ld", (long)int_of_fixnum(u));
        break;

case TAG_ODDS:
        if (is_bps(u))
        {   Header h = *(Header *)(data_of_bps(u) - 4);
            len = length_of_header(h);
            push(u);
            outprefix(blankp, 3+2*(len-4));
            putc_stream('#', active_stream); putc_stream('[', active_stream);
            for (k = 0; k < len-4; k++)
            {   int ch = ((char *)data_of_bps(stack[0]))[k];
                static char *hexdig = "0123456789abcdef";
/*
 * Code vectors are not ever going to be re-readable (huh - I suppose there
 * is no big reason why they should not be!) so I split them across multiple
 * lines if that seems useful.  Anyway a reader for them could understand to
 * expect that.
 */
                outprefix(NO, 2);
#ifdef DEMO_MODE
                putc_stream('?', active_stream);
                putc_stream('?', active_stream);
#else
                putc_stream(hexdig[(ch >> 4) & 0xf], active_stream);
                putc_stream(hexdig[ch & 0xf], active_stream);
#endif
            }
            popv(1);
            putc_stream(']', active_stream);
            return;
        }
/*
 * A SPID is an object used internally by CSL in various places, and the
 * rules of the system are that it ought never to be visible to the user.
 * I print it here in case it arises because of a bug, or while I am testing.
 */
        else if (is_spid(u))
        {   switch (u & 0xffff)
            {
/*
 * The decoding of readable names for SPIDs here is somewhat over the top
 * except while somebdy is hard at work debugging....
 */
        case SPID_NIL:     strcpy(my_buff, "SPID_NIL");     break;
        case SPID_FBIND:   strcpy(my_buff, "SPID_FBIND");   break;
        case SPID_CATCH:   strcpy(my_buff, "SPID_CATCH");   break;
        case SPID_PROTECT: strcpy(my_buff, "SPID_PROTECT"); break;
        case SPID_NOARG:   strcpy(my_buff, "SPID_NOARG");   break;
        case SPID_HASH0:   strcpy(my_buff, "SPID_HASH0");   break;
        case SPID_HASH1:   strcpy(my_buff, "SPID_HASH1");   break;
        case SPID_GCMARK:  strcpy(my_buff, "SPID_GCMARK");  break;
        case SPID_NOINPUT: strcpy(my_buff, "SPID_NOINPUT"); break;
        case SPID_ERROR:   strcpy(my_buff, "SPID_ERROR");   break;
        case SPID_PVBIND:  strcpy(my_buff, "SPID_PVBIND");  break;
        case SPID_NOPROP:  strcpy(my_buff, "SPID_NOPROP");  break;
        case SPID_LIBRARY: u = (u >> 20) & 0xfff;
/*
 * When I print the name of a library I will truncate the displayed name
 * to 30 characters. This is somewhat arbitrary (but MUST relate to the
 * size of my_buff), but will tend to keep output more compact.
 */
                           sprintf(my_buff, "#{%.30s}", fasl_paths[u]);
                           break;
        default:           sprintf(my_buff, "SPID_%lx",
                                   (long)((u >> 8) & 0x00ffffff));
                           break;
            }
            len = strlen(my_buff);
            outprefix(blankp, len);
            for (k=0; k<len; k++) putc_stream(my_buff[k], active_stream);
            return;
        }
/*
 * Assume if is a CHAR here
 */
        outprefix(blankp, escaped_printing & escape_yes ? 3 : 1);
        if (u != CHAR_EOF)
/* I know that a char is immediate data and so does not need GC protection */
        {   if (escaped_printing & escape_yes)
                putc_stream('#', active_stream), putc_stream('\\', active_stream);
            putc_stream((int)code_of_char(u), active_stream);
        }
        return;

case TAG_VECTOR:
        {   Header h = vechdr(u);
            len = length_of_header(h) - 4;  /* counts in bytes */
            push(u);
#ifdef COMMON
            print_non_simple_string:
#endif
            switch (type_of_header(h))
            {
    case TYPE_STRING:
                {   int32 slen = 0;
                    if (escaped_printing & escape_yes)
                    {   for (k = 0; k < len; k++)
                        {   int ch = celt(stack[0], k);
                            if (ch == '"') slen += 2;
#ifdef COMMON
                            else if (ch == '\\') slen += 2;
#endif
                            else if (iscntrl(ch)) slen += 3;
                            else slen += 1;
                        }
                        slen += 2;
                    }
                    else slen = len;
                    outprefix(blankp, slen);
/*
 * I will write out the fast, easy, common case here
 */
                    if (!(escaped_printing &
                             (escape_yes | escape_fold_down |
                              escape_fold_up | escape_capitalize)))
                    {   for (k = 0; k < len; k++)
                        {   int ch = celt(stack[0], k);
                            putc_stream(ch, active_stream);
                        }
                    }
                    else
                    {   if (escaped_printing & escape_yes) putc_stream('"', active_stream);
                        for (k = 0; k < len; k++)
                        {   int ch = celt(stack[0], k);
                            static char *hexdig = "0123456789abcdef";
#ifdef COMMON
                            if ((escaped_printing & escape_yes) &&
                                 (ch == '"' || ch == '\\'))
                            {   putc_stream('\\', active_stream);
                                putc_stream(ch, active_stream);
                            }
#else
                            if ((escaped_printing & escape_yes) && ch == '"')
                            {   putc_stream('"', active_stream);
                                putc_stream('"', active_stream);
                            }
#endif
                            else if (iscntrl(ch))
                            {   putc_stream('\\', active_stream);
                                putc_stream(hexdig[(ch >> 4) & 0xf], active_stream);
                                putc_stream(hexdig[ch & 0xf], active_stream);
                            }
                            else
                            {
                                if (escaped_printing & escape_fold_down)
                                    ch = tolower(ch);
                                else if (escaped_printing & escape_fold_up)
                                    ch = toupper(ch);
/* Just For Now I Will Not Implement The Option To Capitalize Things */
                                putc_stream(ch, active_stream);
                            }
                        }
                    }
                    popv(1);
                    if (escaped_printing & escape_yes) putc_stream('"', active_stream);
                }
                return;

    case TYPE_SP:
                pop(u);
                sprintf(my_buff, "#<closure: %.8lx>",
                                 (long)(unsigned32)elt(u, 0));
                goto print_my_buff;

#ifdef COMMON
    case TYPE_BITVEC1:  bl = 1; break;
    case TYPE_BITVEC2:  bl = 2; break;
    case TYPE_BITVEC3:  bl = 3; break;
    case TYPE_BITVEC4:  bl = 4; break;
    case TYPE_BITVEC5:  bl = 5; break;
    case TYPE_BITVEC6:  bl = 6; break;
    case TYPE_BITVEC7:  bl = 7; break;
    case TYPE_BITVEC8:  bl = 8; break;
#endif

#ifndef COMMON
    case TYPE_STRUCTURE:
        pop(u);
        sprintf(my_buff, "[e-vector:%.8lx]", (long)(unsigned32)u);
        goto print_my_buff;

#else
    case TYPE_STRUCTURE:
        if (elt(stack[0], 0) == package_symbol)
        {   outprefix(blankp, 3);
            putc_stream('#', active_stream); putc_stream('P', active_stream); putc_stream(':', active_stream);
            pop(u);
            u = elt(u, 8);  /* The name of the package */
            blankp = 0;
            goto restart;
        }
        /* Drop through */
#endif
    case TYPE_ARRAY:
#ifdef COMMON
        {   Lisp_Object dims = elt(stack[0], 1);
/*
 * I suppose that really I need to deal with non-simple bitvectors too.
 * And generally get Common Lisp style array printing "right".
 */
            if (consp(dims) && !consp(qcdr(dims)) &&
                elt(stack[0], 0) == string_char_sym)
            {   len = int_of_fixnum(qcar(dims));
                dims = elt(stack[0], 5);   /* Fill pointer */
                if (is_fixnum(dims)) len = int_of_fixnum(dims);
                stack[0] = elt(stack[0], 2);
/*
 * The demand here is that the object within the non-simple-string was
 * a simple string, so I can restart printing to deal with it. This will
 * not support strings that were over-large so got represented in
 * chunks. Tough luck about that for now!
 */
                h = TYPE_STRING;
                goto print_non_simple_string;
            }
        }
        /* Drop through */
#endif
    case TYPE_SIMPLE_VEC:
    case TYPE_HASH:
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
                putc_stream('#', active_stream); putc_stream('S', active_stream); putc_stream('(', active_stream);
            }
            else if (type_of_header(h) == TYPE_HASH)
            {   outprefix(blankp, 3);
                putc_stream('#', active_stream); putc_stream('H', active_stream); putc_stream('(', active_stream);
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
            for (k=0; k<len; k+=4)
            {   Lisp_Object vv = *(Lisp_Object *)
                                ((char *)stack[0] + (4 - TAG_VECTOR) + k);
                internal_prin(vv, (k != 0) ? 1 : 0);
                errexitvn(1);
            }
            popv(1);
            outprefix(NO, 1);
#ifndef COMMON
            if (type_of_header(h) == TYPE_SIMPLE_VEC) putc_stream(']', active_stream);
            else
#endif
            putc_stream(')', active_stream);
            return;
        }
    case TYPE_MIXED1:   /* An experimental addition to CSL */
    case TYPE_MIXED2:
    case TYPE_MIXED3:
    case TYPE_STREAM:
        {   outprefix(blankp, 3);
            putc_stream('#', active_stream);
            if (type_of_header(h) == TYPE_STREAM) putc_stream('F', active_stream);
            else if (type_of_header(h) == TYPE_MIXED1) putc_stream('1', active_stream);
            else if (type_of_header(h) == TYPE_MIXED2) putc_stream('2', active_stream);
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
            {   internal_prin(elt(stack[0], 0), 0);
                errexitvn(1);
                outprefix(NO, 1);
                internal_prin(elt(stack[0], 1), 1);
                errexitvn(1);
                outprefix(NO, 1);
                internal_prin(elt(stack[0], 2), 1);
                errexitvn(1);
            }
            for (k=12; k<len; k+=4)
            {   sprintf(my_buff, "%.8lx", (long)*(Lisp_Object *)
                                ((char *)stack[0] + (4 - TAG_VECTOR) + k));
                prin_buf(my_buff, YES);
            }
            popv(1);
            outprefix(NO, 1);
            putc_stream(']', active_stream);
            return;
        }

    case TYPE_VEC8:
             outprefix(blankp, 4);
             putc_stream('#', active_stream); putc_stream('V', active_stream);
             putc_stream('8', active_stream); putc_stream('(', active_stream);
             for (k=0; k<len; k++)
             {   sprintf(my_buff, "%d", scelt(stack[0], k));
                 prin_buf(my_buff, k != 0);
             }
             outprefix(NO, 1);
             putc_stream(')', active_stream);
             popv(1);
             return;
    case TYPE_VEC16:
             outprefix(blankp, 5);
             putc_stream('#', active_stream); putc_stream('V', active_stream);
             putc_stream('1', active_stream); putc_stream('6', active_stream); putc_stream('(', active_stream);
             len = len >> 1;
             for (k=0; k<len; k++)
             {   sprintf(my_buff, "%d", helt(stack[0], k));
                 prin_buf(my_buff, k != 0);
             }
             outprefix(NO, 1);
             putc_stream(')', active_stream);
             popv(1);
             return;
    case TYPE_VEC32:
             outprefix(blankp, 5);
             putc_stream('#', active_stream); putc_stream('V', active_stream);
             putc_stream('3', active_stream); putc_stream('2', active_stream); putc_stream('(', active_stream);
             len = len >> 2;
             for (k=0; k<len; k++)
             {   sprintf(my_buff, "%d", ielt(stack[0], k));
                 prin_buf(my_buff, k != 0);
             }
             outprefix(NO, 1);
             putc_stream(')', active_stream);
             popv(1);
             return;
    case TYPE_FLOAT32:
             outprefix(blankp, 4);
             putc_stream('#', active_stream); putc_stream('F', active_stream);
             putc_stream('S', active_stream); putc_stream('(', active_stream);
             len = len >> 2;
             for (k=0; k<len; k++)
             {   sprintf(my_buff, "%#.7g", (double)felt(stack[0], k));
                 prin_buf(my_buff, k != 0);
             }
             outprefix(NO, 1);
             putc_stream(')', active_stream);
             popv(1);
             return;
    case TYPE_FLOAT64:
             outprefix(blankp, 4);
             putc_stream('#', active_stream); putc_stream('F', active_stream);
             putc_stream('D', active_stream); putc_stream('(', active_stream);
             len = (len-4) >> 3;
/* I will not worry about print-precision bugs here... */
             for (k=0; k<len; k++)
             {   sprintf(my_buff, "%#.*g",
                     (int)print_precision, delt(stack[0], k));
                 prin_buf(my_buff, k != 0);
             }
             outprefix(NO, 1);
             putc_stream(')', active_stream);
             popv(1);
             return;
    default: goto error_case;
            }
#ifdef COMMON
/* Here for bit-vectors */
            outprefix(blankp, 2+8*(len-1)+bl);
            putc_stream('#', active_stream), putc_stream('*', active_stream);
            {   int z, q;
                for (k = 0; k < len-1; k++)
                {   z = ucelt(stack[0], k);
                    for (q=0; q<8; q++)
                    {   if (z & 1) putc_stream('1', active_stream);
                        else putc_stream('0', active_stream);
                        z >>= 1;
                    }
                }
                if (len != 0)   /* Empty bitvec */
                {   z = ucelt(stack[0], len-1);
                    for (q=0; q<bl; q++)
                    {   if (z & 1) putc_stream('1', active_stream);
                        else putc_stream('0', active_stream);
                        z >>= 1;
                    }
                }
            }
            popv(1);
            return;
#endif
        }

#ifdef VERY_CAUTIOUS
/*
 * It seems probable that I could never get here, but this "return" is
 * just in case, as a safety measure.
 */
        popv(1);
        return;
#endif

case TAG_SYMBOL:
        push(u);
/*
 * When computing checksums with the "md5" function I count gensyms as being
 * purely local to the current expression. The strange effect is that
 *   (md5 (gensym))
 * always gives the same result, even though the gensyms involved are
 * different. But it is REASONABLE compatible with a view that I am forming
 * a digest of a printed representation and is needed if digests are to
 * be acceptably consistent across lisp images.
 */
        if (escaped_printing & escape_checksum)
        {   if ((qheader(u) & (SYM_CODEPTR+SYM_ANY_GENSYM)) == SYM_ANY_GENSYM)
            {   Lisp_Object al = stream_write_data(active_stream);
                while (al != nil &&
                       qcar(qcar(al)) != u) al = qcdr(al);
                pop(u);
                if (al == nil)
                {   al = acons(u, fixnum_of_int(local_gensym_count),
                               stream_write_data(active_stream));
                    local_gensym_count++;
                    if (exception_pending()) return;
                    stream_write_data(active_stream) = al;
                }
                al = qcdr(qcar(al));
                sprintf(my_buff, "#G%lx", (long)int_of_fixnum(al));
                break;
            }
        }
        w = get_pname(u);    /* allocates name for gensym if needbe */
        u = stack[0];
#ifdef COMMON
tag_symbol:
#endif
        nil = C_nil;
        if (!exception_pending())
        {   Header h = vechdr(w);
            int32 slen = 0;
            int raised = 0;
#ifdef COMMON
            int pkgid = 0;  /* No package marker needed */
/*
 *  0    no package marker needed
 *  1    display as #:xxx      (ie as a gensym)
 *  2    display as :xxx       (ie in keyword package)
 *  3    display as ppp:xxx    (external in its home package)
 *  4    display as ppp::xxx   (internal in its home package)
 */
            if (escaped_printing & escape_yes)
            {   if (!is_symbol(u)) pkgid = 0;  /* Support for a HACK */
                else if (qpackage(u) == nil) pkgid = 1; /* gensym */
                else if (qpackage(u) == qvalue(keyword_package)) pkgid = 2;
                else if (qpackage(u) == CP) pkgid = 0; /* home is current */
                else
                {   pkgid = 3;
                    k = packflags_(CP);
                    if (k != 0 && k <= SYM_IN_PKG_COUNT)
                    {   k = ((int32)1) << (k+SYM_IN_PKG_SHIFT-1);
                        if (k & qheader(u)) pkgid = 0;
                    }
                    else k = 0;
                    if (pkgid != 0)
                    {   push(w);
                        w = Lfind_symbol_1(nil, w);
                        nil = C_nil;
                        if (exception_pending())
                        {   popv(2);
                            return;
                        }
                        u = stack[-1];
                        if (mv_2 != nil && w == u)
                        {   pkgid = 0;
/*
 * Here I update the cache it that keeps telling me that the symbol is
 * is "available" in the package that is current at present. I guess that
 * I need to clear this bit if I unintern or otherwise mess around with
 * package structures.
 */
                            qheader(u) |= k;
                        }
                        else if (qheader(u) & SYM_EXTERN_IN_HOME) pkgid = 3;
                        else pkgid = 4;
                        pop(w);
                    }
                }
            }
#endif
            len = length_of_header(h);  /* counts in bytes */
/*
 * When I come to print things I will assume that I want them re-readable
 * with values of !*raise and !*lower as in effect when the printing took
 * place, and insert escape characters accordingly.  I optimise the case
 * of printing without any effects...
 */
            if (!(escaped_printing &
                  (escape_yes | escape_fold_down |
                   escape_fold_up | escape_capitalize)))
            {   stack[0] = w;
                len -= 4;
#ifdef COMMON
                switch (pkgid)
                {
            case 1: outprefix(blankp, len+2);
                    putc_stream('#', active_stream);
                    putc_stream(':', active_stream);
                    break;
            case 2: outprefix(blankp, len+1);
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
                outprefix(blankp, len);
#endif
                for (k = 0; k < len; k++)
                {   int ch = celt(stack[0], k);
                    putc_stream(ch, active_stream);
                }
            }
            else
            {   int extralen = 0;
                if (qvalue(lower_symbol) != nil) raised = -1;
                else if (qvalue(raise_symbol) != nil) raised = 1;
                stack[0] = w;
                len -= 4;
/* A really horrid case here - digits are special at the start of names! */
                if (len > 0)
                {   int ch = celt(stack[0], 0);
                    if (escaped_printing & escape_yes &&
                        (isdigit(ch)
#ifdef COMMON
                         || (ch=='.')
#else
                         || (ch=='_')
#endif
                         )) extralen++;
                }
                for (k = 0; k < len; k++)
                {   int ch = celt(stack[0], k);
                    if (escaped_printing & escape_yes &&
                        !(escaped_printing &
                          (escape_fold_down |
                           escape_fold_up |
                           escape_capitalize)) &&
#ifdef COMMON
                        (ch=='.' || ch=='\\' || ch=='|') ||
#endif
                        (!is_constituent(ch) ||
#ifdef COMMON
                         (ch=='.' || ch=='\\' || ch=='|' || ch==':') ||
#endif
                         (raised < 0 && isupper(ch)) ||
                         (raised > 0 && islower(ch)))) extralen++;
                    slen++;
                }
#ifdef COMMON
/*
 * The |xxx| notation is where the "2" here comes from, but that does not
 * make full allowance for names with '\\' in them. Tough!
 */
                if (extralen != 0) extralen = 2;
                switch (pkgid)
                {
            case 1: outprefix(blankp, slen+extralen+2);
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
                if (len > 0)
                {   int ch = celt(stack[0], 0);
#ifdef COMMON
                    if (ch == '\\' || ch=='|')
                        putc_stream(ESCAPE_CHAR, active_stream);
#else
                    if (!is_constituent(ch) ||
                        isdigit(ch) ||
                        (ch == '_') ||
                        (!(escaped_printing &
                            (escape_fold_down | escape_fold_up |
                             escape_capitalize)) &&
                         ((raised < 0 && isupper(ch)) ||
                          (raised > 0 && islower(ch)))))
                        putc_stream(ESCAPE_CHAR, active_stream);
#endif
                    if (escaped_printing & escape_fold_down)
                        ch = tolower(ch);
                    else if (escaped_printing & escape_fold_up)
                        ch = toupper(ch);
                    putc_stream(ch, active_stream);
                }
                for (k = 1; k < len; k++)
                {   int ch = celt(stack[0], k);
#ifdef COMMON
                    if (ch == '\\' || ch=='|')
                        putc_stream(ESCAPE_CHAR, active_stream);
#else
                    if (!(escaped_printing &
                          (escape_fold_down | escape_fold_up |
                           escape_capitalize)) &&
                        (!is_constituent(ch) ||
                         (raised < 0 && isupper(ch)) ||
                         (raised > 0 && islower(ch))))
                        putc_stream(ESCAPE_CHAR, active_stream);
#endif
                    if (escaped_printing & escape_fold_down)
                        ch = tolower(ch);
                    else if (escaped_printing & escape_fold_up)
                        ch = toupper(ch);
                    putc_stream(ch, active_stream);
                }
#ifdef COMMON
                if (extralen != 0) putc_stream('|', active_stream);
#endif
            }
        }
        popv(1);
        return;

case TAG_BOXFLOAT:
        switch (type_of_header(flthdr(u)))
        {
#ifdef COMMON
    case TYPE_SINGLE_FLOAT:
            sprintf(my_buff, "%#.7g", (double)single_float_val(u));
            break;
#endif
    case TYPE_DOUBLE_FLOAT:
/*
 * Hexadecimal printing of floating point numbers is only provided for
 * here to help with nasty low-level debugging.  The output will not be
 * directly re-readable.  It is only provided for the (default) double-
 * precision numbers.  Use (prinhex ..) to activate it.
 */
            if (escaped_printing & escape_hex)
            {   unsigned32 *p = (unsigned32 *)((char *)u + 1);
                int q = current_fp_rep & FP_WORD_ORDER;
                sprintf(my_buff, "{%.8lx/%.8lx:%#.8g}",
                                  (long)(unsigned32)p[1-q],
                                  (long)(unsigned32)p[q],
                                  double_float_val(u));
            }
            else if (escaped_printing & escape_octal)
            {   unsigned32 *p = (unsigned32 *)((char *)u + 1);
                int q = current_fp_rep & FP_WORD_ORDER;
                sprintf(my_buff, "{%.11lo/%.11lo:%#.8g}",
                                  (long)p[1-q], (long)p[q],
                                  double_float_val(u));
            }
            else
#if defined __WATCOMC__
            {   double d = double_float_val(u);
/*
 * version 10.0a of Watcom C (which I was using in April 1995) had a bug
 * whereby the specified precision is handled incorrectly.
 * Version 10.5 seems to have a different but also dubious behaviour!
 * The following code uses simpler formats to try to avoid trouble. It
 * MIGHT make sense to enable if for all systems not just Watcom, if I
 * ever see precision problems elsewhere... Note however that there are
 * delicacies here with numbers like 0.0001 which do not have exact (binary
 * floating point) representations but are boundary cases for print-format
 * selection. I am bound to get numbers very close to such boundaries
 * "wrong" at times here. To be more precise, values just less than the
 * above will be displayed using E format and values just greater using F
 * format, despite the numeric display not being able to show any
 * difference in the value.
 * An alternative approach would be for me to convert the number to decimal
 * at as high a precision as possible and then do the formatting for myself
 * based on the character-string so generated. That seems too much effort for
 * now, and also raises difficulties of double-rounding...
 */
                double ad = 10000.0*(d < 0.0 ? -d : d);
                double xx = 1.0;
                for (k=-4; k<=(int)print_precision && xx<=ad; k++) xx *= 10.0;
                if (k==-4 || k>(int)print_precision)
                    sprintf(my_buff, "%#.*e", (int)print_precision-1, d);
                else sprintf(my_buff, "%#.*f", (int)print_precision-k, d);
            }
#else
                 sprintf(my_buff, "%#.*g", (int)print_precision,
                                  double_float_val(u));
#endif
            break;
#ifdef COMMON
    case TYPE_LONG_FLOAT:
            sprintf(my_buff, "%#.17g", (double)long_float_val(u));
            break;
#endif
    default:
            sprintf(my_buff, "?%.8lx?", (long)(unsigned32)u);
            break;
        }
/*
 * I want to trim off trailing zeros, but ensure I leave a digit after the
 * decimal point. Things are made more complicated by the presence of an
 * exponent.  Note that the '#' in the format conversions should mean that
 * I ALWAYS have a '.' in the number that has been printed.  However on some
 * systems this proves not to be the case - in particular IEEE infinities
 * (and maybe NaNs?) get displayed without a '.' in some environments where
 * they are supported.  I also see that some C libraries in some of the cases
 * I generate above dump out nonsense like 0.0e+000 with unreasonably wide
 * exponents, so I will try to rationalise that sort of mess too.
 */
#ifdef COMMON
float_print_tidyup:
#endif
        {   int i = 0, j, c;
            while ((c = my_buff[i]) != 0 && c != '.') i++;
            if (c == 0) break; /* No '.' found, so leave unaltered */
            j = i+1;
/* Find the end of the fraction (= end of number or start of exponent) */
            while ((c = my_buff[j]) != 'e' && c != 0) j++;
            if (c == 'e')
            {   /* check for leading zeros in an exponent component */
                while (my_buff[j+1] == '+' || my_buff[j+1] == '0')
                {   int m = j+1;
                    for (;;)
                    {   if ((my_buff[m] = my_buff[m+1]) == 0) break;
                        m++;
                    }
                }
                if (my_buff[j+1] == '-')  /* kill leading zeros after '-' */
                {   while (my_buff[j+2] == '0')
                    {   int m = j+2;
                        for (;;)
                        {   if ((my_buff[m] = my_buff[m+1]) == 0) break;
                            m++;
                        }
                    }
                    if (my_buff[j+2] == 0) my_buff[j+1] = 0;
                }
                if (my_buff[j+1] == 0) my_buff[j] = 0; /* "e" now at end? */
            }
            k = j - 1;
            if (k == i) /* no digits after the '.' - push in a '0' */
            {   int l = j;
                while (my_buff[l] != 0) l++;
                while (l >= j)
                {   my_buff[l+1] = my_buff[l];
                    l--;
                }
                my_buff[j++] = '0';
            }
            else
/* Scan back past any trailing zeroes */
            {   i++;
                while (k > i && my_buff[k] == '0') k--;
/* Copy data down to strip out the unnecessary '0' characters */
                if (k != j-1)
                {   k++;
                    while ((my_buff[k++] = my_buff[j++]) != 0) /* nothing */ ;
                }
            }
        }
/*
 * For my purposes I do not want to see "-0.0" - it causes muddle and loses
 * portability. I know that losing the information hereremoves a facility
 * from people but it also removes pain from naive users!
 */
        if (strcmp(my_buff, "-0.0") == 0) strcpy(my_buff, "0.0");
        break;

case TAG_NUMBERS:
        if (is_bignum(u))
        {
            if (escaped_printing & escape_hex)
                print_bighexoctbin(u, 16, escape_width(escaped_printing),
                    blankp, escaped_printing & escape_nolinebreak);
            else if (escaped_printing & escape_octal)
                print_bighexoctbin(u, 8, escape_width(escaped_printing),
                    blankp, escaped_printing & escape_nolinebreak);
            else if (escaped_printing & escape_binary)
                print_bighexoctbin(u, 2, escape_width(escaped_printing),
                    blankp, escaped_printing & escape_nolinebreak);
            else
                print_bignum(u, blankp, escaped_printing & escape_nolinebreak);
            return;
        }
#ifdef COMMON
        else if (is_ratio(u))
        {   push(u);
/*
 * Here I have a line-break problem --- I do not measure the size of the
 * denominator, and hence may well split a line between numerator and
 * denominator.  This would be HORRID. I guess that the correct recipe will
 * involve measuring the size of the denominator first... Let's not bother
 * just at the moment.
 */
            internal_prin(numerator(stack[0]), blankp);
            outprefix(NO, 1);
            putc_stream('/', active_stream);
            pop(u);
            internal_prin(denominator(u), 0);
            return;
        }
        else if (is_complex(u))
        {   push(u);
            outprefix(blankp, 3);
            putc_stream('#', active_stream), putc_stream('C', active_stream); putc_stream('(', active_stream);
            nil = C_nil;
            if (exception_pending()) { popv(1); return; }
            internal_prin(real_part(stack[0]), 0);
            pop(u);
            internal_prin(imag_part(u), 1);
            outprefix(NO, 1);
            putc_stream(')', active_stream);
            return;
        }
#endif
        /* Else drop through to treat as an error */
default:
error_case:
        sprintf(my_buff, "?%.8lx?", (long)(unsigned32)u);
        break;
    }
print_my_buff:
    {   char *p = my_buff;
        int ch;
        outprefix(blankp, strlen(my_buff));
        while ((ch = *p++) != 0) putc_stream(ch, active_stream);
    }
    return;
}

Lisp_Object prin(Lisp_Object u)
{
    nil_as_base
    escaped_printing = escape_yes;
    push(u);
    active_stream = qvalue(standard_output);
    if (!is_stream(active_stream)) active_stream = qvalue(terminal_io);
    if (!is_stream(active_stream)) active_stream = lisp_terminal_io;
    internal_prin(u, 0);
    pop(u);
    return u;
}

void prin_to_terminal(Lisp_Object u)
{
    Lisp_Object nil = C_nil;
    escaped_printing = escape_yes;
    active_stream = qvalue(terminal_io);
    if (!is_stream(active_stream)) active_stream = lisp_terminal_io;
    internal_prin(u, 0);
    ignore_exception();
    ensure_screen();
/*
 * The various "prin_to_xxx()" functions here are generally used (only) for
 * diagnostic printing. So to try to keep interaction as smooth as possible
 * in such cases I arrange that the operating system (eg window manager) will
 * be polled rather soon...
 */
#ifdef SOFTWARE_TICKS
    if (countdown > 5) countdown = 5;
#endif
}

void prin_to_stdout(Lisp_Object u)
{
    Lisp_Object nil = C_nil;
    escaped_printing = escape_yes;
    active_stream = qvalue(standard_output);
    if (!is_stream(active_stream)) active_stream = lisp_standard_output;
    internal_prin(u, 0);
    ignore_exception();
    ensure_screen();
#ifdef SOFTWARE_TICKS
    if (countdown > 5) countdown = 5;
#endif
}

void prin_to_error(Lisp_Object u)
{
    Lisp_Object nil = C_nil;
    escaped_printing = escape_yes;
    active_stream = qvalue(error_output);
    if (!is_stream(active_stream)) active_stream = lisp_error_output;
    internal_prin(u, 0);
    ignore_exception();
    ensure_screen();
#ifdef SOFTWARE_TICKS
    if (countdown > 5) countdown = 5;
#endif
}

void prin_to_trace(Lisp_Object u)
{
    Lisp_Object nil = C_nil;
    escaped_printing = escape_yes;
    active_stream = qvalue(trace_output);
    if (!is_stream(active_stream)) active_stream = lisp_trace_output;
    internal_prin(u, 0);
    ignore_exception();
    ensure_screen();
#ifdef SOFTWARE_TICKS
    if (countdown > 5) countdown = 5;
#endif
}

void prin_to_debug(Lisp_Object u)
{
    Lisp_Object nil = C_nil;
    escaped_printing = escape_yes;
    active_stream = qvalue(debug_io);
    if (!is_stream(active_stream)) active_stream = lisp_debug_io;
    internal_prin(u, 0);
    ignore_exception();
    ensure_screen();
#ifdef SOFTWARE_TICKS
    if (countdown > 5) countdown = 5;
#endif
}

void prin_to_query(Lisp_Object u)
{
    Lisp_Object nil = C_nil;
    escaped_printing = escape_yes;
    active_stream = qvalue(query_io);
    if (!is_stream(active_stream)) active_stream = lisp_query_io;
    internal_prin(u, 0);
    ignore_exception();
    ensure_screen();
#ifdef SOFTWARE_TICKS
    if (countdown > 5) countdown = 5;
#endif
}

void loop_print_stdout(Lisp_Object o)
{
    Lisp_Object nil = C_nil;
    int32 sx = exit_reason;
    one_args *f;
    Lisp_Object lp = qvalue(traceprint_symbol);
    if (lp == nil || lp == unset_var) lp = prinl_symbol;
    if (!is_symbol(lp) ||
        (f = qfn1(lp)) == undefined1) prin_to_stdout(o);
    else
    {   CSLbool bad = NO;
        Lisp_Object env = qenv(lp);
        push2(lp, env);
        ifn1(lp) = (int32)undefined1;  /* To avoid recursion if it fails */
        qenv(lp) = lp;                 /* make it an undefined function  */
        (*f)(env, o);
        nil = C_nil;
        if (exception_pending()) flip_exception(), bad = YES;
        pop2(env, lp);
        if (!bad) ifn1(lp) = (int32)f, qenv(lp) = env; /* Restore if OK */
    }
    exit_reason = sx;
}

void loop_print_error(Lisp_Object o)
{
    nil_as_base
    Lisp_Object w = qvalue(standard_output);
    push(w);
    if (is_stream(qvalue(error_output)))
        qvalue(standard_output) = qvalue(error_output);
    loop_print_stdout(o);
    pop(w);
    qvalue(standard_output) = w;
#ifdef COMMON
/*
 * This is to help me debug in the face of low level system crashes
 */
    if (spool_file) fflush(spool_file);
#endif
}

void loop_print_trace(Lisp_Object o)
{
    nil_as_base
    Lisp_Object w = qvalue(standard_output);
    push(w);
    if (is_stream(qvalue(trace_output)))
        qvalue(standard_output) = qvalue(trace_output);
    loop_print_stdout(o);
    pop(w);
    qvalue(standard_output) = w;
#ifdef COMMON
/*
 * This is to help me debug in the face of low level system crashes
 */
    if (spool_file) fflush(spool_file);
#endif
}

void loop_print_debug(Lisp_Object o)
{
    nil_as_base
    Lisp_Object w = qvalue(standard_output);
    push(w);
    if (is_stream(qvalue(debug_io)))
        qvalue(standard_output) = qvalue(debug_io);
    loop_print_stdout(o);
    pop(w);
    qvalue(standard_output) = w;
}

void loop_print_query(Lisp_Object o)
{
    nil_as_base
    Lisp_Object w = qvalue(standard_output);
    push(w);
    if (is_stream(qvalue(query_io)))
        qvalue(standard_output) = qvalue(query_io);
    loop_print_stdout(o);
    pop(w);
    qvalue(standard_output) = w;
}

void loop_print_terminal(Lisp_Object o)
{
    nil_as_base
    Lisp_Object w = qvalue(standard_output);
    push(w);
    if (is_stream(qvalue(terminal_io)))
        qvalue(standard_output) = qvalue(terminal_io);
    loop_print_stdout(o);
    pop(w);
    qvalue(standard_output) = w;
}

static Lisp_Object prinhex(Lisp_Object u, int n)
{
    nil_as_base
    escaped_printing = escape_yes+escape_hex+((n & 0x3f)<<8);
    push(u);
    active_stream = qvalue(standard_output);
    if (!is_stream(active_stream)) active_stream = qvalue(terminal_io);
    if (!is_stream(active_stream)) active_stream = lisp_terminal_io;
    internal_prin(u, 0);
    pop(u);
    return u;
}

static Lisp_Object prinoctal(Lisp_Object u, int n)
{
    nil_as_base
    escaped_printing = escape_yes+escape_octal+((n & 0x3f)<<8);
    push(u);
    active_stream = qvalue(standard_output);
    if (!is_stream(active_stream)) active_stream = qvalue(terminal_io);
    if (!is_stream(active_stream)) active_stream = lisp_terminal_io;
    internal_prin(u, 0);
    pop(u);
    return u;
}

static Lisp_Object prinbinary(Lisp_Object u, int n)
{
    nil_as_base
    escaped_printing = escape_yes+escape_binary+((n & 0x3f)<<8);
    push(u);
    active_stream = qvalue(standard_output);
    if (!is_stream(active_stream)) active_stream = qvalue(terminal_io);
    if (!is_stream(active_stream)) active_stream = lisp_terminal_io;
    internal_prin(u, 0);
    pop(u);
    return u;
}

Lisp_Object princ(Lisp_Object u)
{
    nil_as_base
    escaped_printing = 0;
    push(u);
    active_stream = qvalue(standard_output);
    if (!is_stream(active_stream)) active_stream = qvalue(terminal_io);
    if (!is_stream(active_stream)) active_stream = lisp_terminal_io;
    internal_prin(u, 0);
    pop(u);
    return u;
}

Lisp_Object print(Lisp_Object u)
{
    nil_as_base
    Lisp_Object stream = qvalue(standard_output);
    push(u);
    escaped_printing = escape_yes;
    if (!is_stream(stream)) stream = qvalue(terminal_io);
    if (!is_stream(stream)) stream = lisp_terminal_io;
    active_stream = stream;
    putc_stream('\n', stream);
    internal_prin(u, 0);
    pop(u);
    return u;
}

Lisp_Object printc(Lisp_Object u)
{
    nil_as_base
    Lisp_Object stream = qvalue(standard_output);
    push(u);
    escaped_printing = 0;
    if (!is_stream(stream)) stream = qvalue(terminal_io);
    if (!is_stream(stream)) stream = lisp_terminal_io;
    active_stream = stream;
    putc_stream('\n', stream);
    internal_prin(u, 0);
    pop(u);
    return u;
}

void freshline_trace(void)
{
    nil_as_base
    if (other_write_action(WRITE_GET_INFO+WRITE_GET_COLUMN,
                           qvalue(trace_output)) != 0)
        putc_stream('\n', qvalue(trace_output));

}

void freshline_debug(void)
{
    nil_as_base
    if (other_write_action(WRITE_GET_INFO+WRITE_GET_COLUMN,
                           qvalue(debug_io)) != 0)
        putc_stream('\n', qvalue(debug_io));

}

int char_to_list(int c, Lisp_Object f)
{
    Lisp_Object k, nil = C_nil;
/*
 * return at once if a previous call raised an exception
 */
    if (exception_pending()) return 1;
    k = elt(charvec, c & 0xff);
    if (k == nil)
    {   celt(boffo, 0) = c;
        push(f);
/*
 * It could very well be that in Common Lisp I ought to generate a list of
 * character objects here. As it is I hand back symbols, but I do take care
 * that they are in the LISP package.
 */
        k = iintern(boffo, 1, lisp_package, 0);
        pop(f);
        nil = C_nil;
        if (exception_pending()) return 1;
        elt(charvec, c & 0xff) = k;
    }
    push(f);
    k = cons(k, stream_write_data(f));
    pop(f);
    nil = C_nil;
    if (!exception_pending())
    {   stream_write_data(f) = k;
        return 0;
    }
    else return 1;
}

static Lisp_Object explode(Lisp_Object u)
{
    Lisp_Object nil = C_nil;
    stream_write_data(lisp_work_stream) = nil;
    set_stream_write_fn(lisp_work_stream, char_to_list);
    set_stream_write_other(lisp_work_stream, write_action_list);
    active_stream = lisp_work_stream;
    internal_prin(u, 0);
    errexit();
    u = stream_write_data(lisp_work_stream);
    stream_write_data(lisp_work_stream) = nil;
    return nreverse(u);
}

static unsigned char checksum_buffer[64];
static int checksum_count;

int char_to_checksum(int c, Lisp_Object f)
{
    Lisp_Object nil = C_nil;
/*
 * return at once if a previous call raised an exception
 */
    if (exception_pending()) return 1;
    checksum_buffer[checksum_count++] = c;
    if (checksum_count == sizeof(checksum_buffer))
    {   MD5_Update(checksum_buffer, sizeof(checksum_buffer));
        checksum_count = 0;
    }
    return 0;
}

void checksum(Lisp_Object u)
{
    Lisp_Object nil = C_nil;
    escaped_printing = escape_yes+escape_nolinebreak+escape_checksum;
    set_stream_write_fn(lisp_work_stream, char_to_checksum);
    set_stream_write_other(lisp_work_stream, write_action_list); /* sic */
    active_stream = lisp_work_stream;
    MD5_Init();
    local_gensym_count = checksum_count = 0;
    internal_prin(u, 0);
    if (exception_pending()) return;
    stream_write_data(lisp_work_stream) = nil;
    if (checksum_count != 0)
        MD5_Update(checksum_buffer, checksum_count);
}

int code_to_list(int c, Lisp_Object f)
{
    Lisp_Object k, nil = C_nil;
/*
 * return at once if a previous call raised an exception
 */
    if (exception_pending()) return 1;
    k = fixnum_of_int((int32)c);
    push(f);
    k = cons(k, stream_write_data(f));
    pop(f);
    nil = C_nil;
    if (!exception_pending())
    {   stream_write_data(f) = k;
        stream_char_pos(f)++;
        return 0;
    }
    else return 1;
}

static Lisp_Object exploden(Lisp_Object u)
{
    Lisp_Object nil = C_nil;
    stream_write_data(lisp_work_stream) = nil;
    set_stream_write_fn(lisp_work_stream, code_to_list);
    set_stream_write_other(lisp_work_stream, write_action_list);
    active_stream = lisp_work_stream;
    internal_prin(u, 0);
    errexit();
    u = stream_write_data(lisp_work_stream);
    stream_write_data(lisp_work_stream) = nil;
    return nreverse(u);
}

/*
 * To cope with the needs of windowed implementations I am (unilaterally)
 * altering the specification of the LINELENGTH function that I implement.
 * The new rules are:
 *    (linelength nil)    returns current width, always an integer
 *    (linelength n)      sets new with to n, returns old
 *    (linelength T)      sets new width to default for current stream,
 *                        and returns old.
 * the "old" value returned in the last two cases will often be the current
 * linelength as returnd by (linelength nil), but it CAN be the value T.
 * On some windowed systems after (linelength T) the value of (linelength nil)
 * will track changes that the user makes by re-sizing the main output
 * window on their screen. The linelength function inspects and sets
 * information for the current standard output stream, and separate
 * record is kept of the linelength associated with each stream.
 */

Lisp_Object Llinelength(Lisp_Object nil, Lisp_Object a)
{
    int32 oll;
    Lisp_Object stream = qvalue(standard_output);
    if (!is_stream(stream)) stream = qvalue(terminal_io);
    if (!is_stream(stream)) stream = lisp_terminal_io;
    if (a == nil)
        oll = other_write_action(WRITE_GET_INFO+WRITE_GET_LINE_LENGTH, stream);
    else if (a == lisp_true)
        oll = other_write_action(WRITE_SET_LINELENGTH_DEFAULT, stream);
    else if (!is_fixnum(a)) return aerror1("linelength", a);
    else
    {   oll = int_of_fixnum(a);
        if (oll < 10) oll = 10;
        oll = other_write_action(WRITE_SET_LINELENGTH | oll, stream);
    }
    if (oll == 0x80000000) return onevalue(lisp_true);
    else return onevalue(fixnum_of_int(oll));
}

static Lisp_Object MS_CDECL Llinelength0(Lisp_Object nil, int nargs, ...)
{
    argcheck(nargs, 0, "linelength");
    return Llinelength(nil, nil);
}

Lisp_Object Lprin(Lisp_Object nil, Lisp_Object a)
{
    push(a);
    escaped_printing = escape_yes;
    active_stream = qvalue(standard_output);
    if (!is_stream(active_stream)) active_stream = qvalue(terminal_io);
    if (!is_stream(active_stream)) active_stream = lisp_terminal_io;
    internal_prin(a, 0);
    pop(a);
    errexit();
    return onevalue(a);
}

static Lisp_Object Lprinhex(Lisp_Object nil, Lisp_Object a)
{
    push(a);
    prinhex(a, 0);
    pop(a);
    errexit();
    return onevalue(a);
}

static Lisp_Object Lprinoctal(Lisp_Object nil, Lisp_Object a)
{
    push(a);
    prinoctal(a, 0);
    pop(a);
    errexit();
    return onevalue(a);
}

static Lisp_Object Lprinbinary(Lisp_Object nil, Lisp_Object a)
{
    push(a);
    prinbinary(a, 0);
    pop(a);
    errexit();
    return onevalue(a);
}

static Lisp_Object Lprinhex2(Lisp_Object nil, Lisp_Object a, Lisp_Object b)
{
    if (!is_fixnum(b)) return aerror1("prinhex", b);
    push(a);
    prinhex(a, int_of_fixnum(b));
    pop(a);
    errexit();
    return onevalue(a);
}

static Lisp_Object Lprinoctal2(Lisp_Object nil, Lisp_Object a, Lisp_Object b)
{
    if (!is_fixnum(b)) return aerror1("prinoctal", b);
    push(a);
    prinoctal(a, int_of_fixnum(b));
    pop(a);
    errexit();
    return onevalue(a);
}

static Lisp_Object Lprinbinary2(Lisp_Object nil, Lisp_Object a, Lisp_Object b)
{
    if (!is_fixnum(b)) return aerror1("prinbinary", b);
    push(a);
    prinbinary(a, int_of_fixnum(b));
    pop(a);
    errexit();
    return onevalue(a);
}

Lisp_Object MS_CDECL Lposn(Lisp_Object nil, int nargs, ...)
{
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "posn");
    return onevalue(fixnum_of_int((int32)
        other_write_action(WRITE_GET_INFO+WRITE_GET_COLUMN,
                           qvalue(standard_output))));
}

Lisp_Object Lposn_1(Lisp_Object nil, Lisp_Object stream)
{
    CSL_IGNORE(nil);
    if (!is_stream(stream)) stream = qvalue(terminal_io);
    if (!is_stream(stream)) stream = lisp_terminal_io;
    return onevalue(fixnum_of_int((int32)
        other_write_action(WRITE_GET_INFO+WRITE_GET_COLUMN, stream)));
}

Lisp_Object MS_CDECL Llposn(Lisp_Object nil, int nargs, ...)
{
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "lposn");
    return onevalue(fixnum_of_int(0));
}

Lisp_Object Lpagelength(Lisp_Object nil, Lisp_Object a)
{
    CSL_IGNORE(nil);
    return onevalue(a);
}

Lisp_Object Lprinc_upcase(Lisp_Object nil, Lisp_Object a)
{
    CSL_IGNORE(nil);
    push(a);
    escaped_printing = escape_fold_up;
    active_stream = qvalue(standard_output);
    if (!is_stream(active_stream)) active_stream = qvalue(terminal_io);
    if (!is_stream(active_stream)) active_stream = lisp_terminal_io;
    internal_prin(a, 0);
    pop(a);
    errexit();
    return onevalue(a);
}

Lisp_Object Lprinc_downcase(Lisp_Object nil, Lisp_Object a)
{
    CSL_IGNORE(nil);
    push(a);
    escaped_printing = escape_fold_down;
    active_stream = qvalue(standard_output);
    if (!is_stream(active_stream)) active_stream = qvalue(terminal_io);
    if (!is_stream(active_stream)) active_stream = lisp_terminal_io;
    internal_prin(a, 0);
    pop(a);
    errexit();
    return onevalue(a);
}

Lisp_Object Lprinc(Lisp_Object nil, Lisp_Object a)
{
    CSL_IGNORE(nil);
    push(a);
    escaped_printing = 0;
    active_stream = qvalue(standard_output);
    if (!is_stream(active_stream)) active_stream = qvalue(terminal_io);
    if (!is_stream(active_stream)) active_stream = lisp_terminal_io;
    internal_prin(a, 0);
    pop(a);
    errexit();
    return onevalue(a);
}

Lisp_Object Lprin2a(Lisp_Object nil, Lisp_Object a)
{
    CSL_IGNORE(nil);
    push(a);
    escaped_printing = escape_nolinebreak;
    active_stream = qvalue(standard_output);
    if (!is_stream(active_stream)) active_stream = qvalue(terminal_io);
    if (!is_stream(active_stream)) active_stream = lisp_terminal_io;
    internal_prin(a, 0);
    pop(a);
    errexit();
    return onevalue(a);
}

char memory_print_buffer[32];

int count_character(int c, Lisp_Object f)
{
    int n = stream_char_pos(f);
    if (n < 31)
    {   memory_print_buffer[n] = c;
        memory_print_buffer[n+1] = 0;
    }
    stream_char_pos(f) = n+1;
    return 0;   /* indicate success */
}

Lisp_Object Llengthc(Lisp_Object nil, Lisp_Object a)
{
    CSL_IGNORE(nil);
    escaped_printing = escape_nolinebreak;
    set_stream_write_fn(lisp_work_stream, count_character);
    memory_print_buffer[0] = 0;
    set_stream_write_other(lisp_work_stream, write_action_list);
    stream_char_pos(lisp_work_stream) = 0;
    active_stream = lisp_work_stream;
    internal_prin(a, 0);
    errexit();
    return onevalue(fixnum_of_int(stream_char_pos(lisp_work_stream)));
}


Lisp_Object Lprint(Lisp_Object nil, Lisp_Object a)
{
    Lisp_Object stream = qvalue(standard_output);
    if (!is_stream(stream)) stream = qvalue(terminal_io);
    if (!is_stream(stream)) stream = lisp_terminal_io;
    push(a);
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
    pop(a);
    errexit();
    return onevalue(a);
}

Lisp_Object Lprintc(Lisp_Object nil, Lisp_Object a)
{
    Lisp_Object stream = qvalue(standard_output);
    CSL_IGNORE(nil);
    if (!is_stream(stream)) stream = qvalue(terminal_io);
    if (!is_stream(stream)) stream = lisp_terminal_io;
    push(a);
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
    pop(a);
    errexit();
    return onevalue(a);
}

Lisp_Object MS_CDECL Lterpri(Lisp_Object nil, int nargs, ...)
{
    Lisp_Object stream = qvalue(standard_output);
    argcheck(nargs, 0, "terpri");
    if (!is_stream(stream)) stream = qvalue(terminal_io);
    if (!is_stream(stream)) stream = lisp_terminal_io;
    putc_stream('\n', stream);
    return onevalue(nil);
}

Lisp_Object MS_CDECL Lflush(Lisp_Object nil, int nargs, ...)
{
    Lisp_Object stream = qvalue(standard_output);
#ifdef COMMON
    argcheck(nargs, 0, "finish-output");
#else
    argcheck(nargs, 0, "flush");
#endif
    if (!is_stream(stream)) stream = qvalue(terminal_io);
    if (!is_stream(stream)) stream = lisp_terminal_io;
    other_write_action(WRITE_FLUSH, stream);
    return onevalue(nil);
}

Lisp_Object Lflush1(Lisp_Object nil, Lisp_Object stream)
{
    if (!is_stream(stream)) stream = qvalue(terminal_io);
    if (!is_stream(stream)) stream = lisp_terminal_io;
    other_write_action(WRITE_FLUSH, stream);
    return onevalue(nil);
}

Lisp_Object Lttab(Lisp_Object nil, Lisp_Object a)
{
    int32 n;
    Lisp_Object stream = qvalue(standard_output);
    if (!is_fixnum(a)) return aerror1("ttab", a);
    n = int_of_fixnum(a);
    if (!is_stream(stream)) stream = qvalue(terminal_io);
    if (!is_stream(stream)) stream = lisp_terminal_io;
    active_stream = stream;
    while (other_write_action(WRITE_GET_INFO+WRITE_GET_COLUMN, stream) < n)
        putc_stream(' ', active_stream);
    return onevalue(nil);
}

Lisp_Object Lxtab(Lisp_Object nil, Lisp_Object a)
{
    int32 n;
    Lisp_Object stream = qvalue(standard_output);
    if (!is_fixnum(a)) return aerror1("xtab", a);
    n = int_of_fixnum(a);
    if (!is_stream(stream)) stream = qvalue(terminal_io);
    if (!is_stream(stream)) stream = lisp_terminal_io;
    active_stream = stream;
    while (n-- > 0) putc_stream(' ', active_stream);
    return onevalue(nil);
}

Lisp_Object MS_CDECL Leject(Lisp_Object nil, int nargs, ...)
{
    Lisp_Object stream = qvalue(standard_output);
    argcheck(nargs, 0, "eject");
    if (!is_stream(stream)) stream = qvalue(terminal_io);
    if (!is_stream(stream)) stream = lisp_terminal_io;
    putc_stream('\f', stream);
    return onevalue(nil);
}

Lisp_Object Lexplode(Lisp_Object nil, Lisp_Object a)
{
    escaped_printing = escape_yes+escape_nolinebreak;
    a = explode(a);
    errexit();
    return onevalue(a);
}

Lisp_Object Lexplodehex(Lisp_Object nil, Lisp_Object a)
{
    escaped_printing = escape_yes+escape_hex+escape_nolinebreak;
    a = explode(a);
    errexit();
    return onevalue(a);
}

Lisp_Object Lexplodeoctal(Lisp_Object nil, Lisp_Object a)
{
    escaped_printing = escape_yes+escape_octal+escape_nolinebreak;
    a = explode(a);
    errexit();
    return onevalue(a);
}

Lisp_Object Lexplodebinary(Lisp_Object nil, Lisp_Object a)
{
    escaped_printing = escape_yes+escape_binary+escape_nolinebreak;
    a = explode(a);
    errexit();
    return onevalue(a);
}

Lisp_Object Lexplodec(Lisp_Object nil, Lisp_Object a)
{
    escaped_printing = escape_nolinebreak;
    a = explode(a);
    errexit();
    return onevalue(a);
}

Lisp_Object Lexplode2lc(Lisp_Object nil, Lisp_Object a)
{
    escaped_printing = escape_fold_down+escape_nolinebreak;
    a = explode(a);
    errexit();
    return onevalue(a);
}

Lisp_Object Lexplode2uc(Lisp_Object nil, Lisp_Object a)
{
    escaped_printing = escape_fold_up+escape_nolinebreak;
    a = explode(a);
    errexit();
    return onevalue(a);
}

Lisp_Object Lexploden(Lisp_Object nil, Lisp_Object a)
{
    escaped_printing = escape_yes+escape_nolinebreak;
    a = exploden(a);
    errexit();
    return onevalue(a);
}

Lisp_Object Lexplodecn(Lisp_Object nil, Lisp_Object a)
{
    escaped_printing = escape_nolinebreak;
    a = exploden(a);
    errexit();
    return onevalue(a);
}

Lisp_Object Lexplode2lcn(Lisp_Object nil, Lisp_Object a)
{
    escaped_printing = escape_fold_down+escape_nolinebreak;
    a = exploden(a);
    errexit();
    return onevalue(a);
}

Lisp_Object Lexplode2ucn(Lisp_Object nil, Lisp_Object a)
{
    escaped_printing = escape_fold_up+escape_nolinebreak;
    a = exploden(a);
    errexit();
    return onevalue(a);
}

/*
 * Now a bunch of binary file access code, as required for the RAND simulation
 * package.  Note that these are NOT smoothly integrated with the use of
 * variables like *standard-output* to hold file handles, but I will leave them
 * pending until other things are more stable... or until they are needed!
 */

static FILE *binary_outfile, *binary_infile;

static FILE *binary_open(Lisp_Object nil, Lisp_Object name, char *dir, char *e)
{
    FILE *file;
    char filename[LONGEST_LEGAL_FILENAME];
    int32 len;
    char *w = get_string_data(name, e, &len);
    nil = C_nil;
    if (exception_pending()) return NULL;
    if (len >= sizeof(filename)) len = sizeof(filename);
    file = open_file(filename, w,
                     (size_t)len, dir, NULL);
    if (file == NULL)
    {   error(1, err_open_failed, name);
        return NULL;
    }
    return file;
}

static Lisp_Object Lbinary_open_output(Lisp_Object nil, Lisp_Object name)
{
#ifdef SOCKETS
    if (socket_server != 0) return aerror("binary-open-output");
#endif
    binary_outfile = binary_open(nil, name, "wb", "binary_open_output");
    errexit();
    return onevalue(nil);
}

int binary_outchar(int c, Lisp_Object dummy)
{
    CSL_IGNORE(dummy);
    if (binary_outfile == NULL) return 1;
    putc(c, binary_outfile);
    return 0;   /* indicate success */
}

static Lisp_Object Lbinary_prin1(Lisp_Object nil, Lisp_Object a)
{
    push(a);
    escaped_printing = escape_yes;
    set_stream_write_fn(lisp_work_stream, binary_outchar);
    set_stream_write_other(lisp_work_stream, write_action_file);
    set_stream_file(lisp_work_stream, binary_outfile);
    active_stream = lisp_work_stream;
    internal_prin(a, 0);
    pop(a);
    errexit();
    return onevalue(a);
}

static Lisp_Object Lbinary_princ(Lisp_Object nil, Lisp_Object a)
{
    CSL_IGNORE(nil);
    escaped_printing = 0;
    push(a);
    set_stream_write_fn(lisp_work_stream, binary_outchar);
    set_stream_write_other(lisp_work_stream, write_action_file);
    set_stream_file(lisp_work_stream, binary_outfile);
    active_stream = lisp_work_stream;
    internal_prin(a, 0);
    pop(a);
    return a;
}

static Lisp_Object Lbinary_prinbyte(Lisp_Object nil, Lisp_Object a)
{
    int x;
    if (binary_outfile == NULL) return onevalue(nil);
    if (!is_fixnum(a)) return aerror1("binary_prinbyte", a);
    x = (int)int_of_fixnum(a);
    putc(x, binary_outfile);
    return onevalue(nil);
}

static Lisp_Object Lbinary_prin2(Lisp_Object nil, Lisp_Object a)
{
    unsigned32 x;
    if (binary_outfile == NULL) return onevalue(nil);
    if (!is_fixnum(a)) return aerror1("binary_prin2", a);
    x = int_of_fixnum(a);
    putc((int)(x >> 8), binary_outfile);
    putc((int)x, binary_outfile);
    return onevalue(nil);
}

static Lisp_Object Lbinary_prin3(Lisp_Object nil, Lisp_Object a)
{
    unsigned32 x;
    if (binary_outfile == NULL) return onevalue(nil);
    if (!is_fixnum(a)) return aerror1("binary_prin3", a);
    x = int_of_fixnum(a);
    putc((int)(x >> 16), binary_outfile);
    putc((int)(x >> 8), binary_outfile);
    putc((int)x, binary_outfile);
    return onevalue(nil);
}

static Lisp_Object Lbinary_prinfloat(Lisp_Object nil, Lisp_Object a)
{
    unsigned32 *w, x;
    if (binary_outfile == NULL) return onevalue(nil);
    if (!is_float(a)) return aerror1("binary_prinfloat", a);
    w = (unsigned32 *)&double_float_val(a);
    x = w[0];
    putc((int)(x >> 24), binary_outfile);
    putc((int)(x >> 16), binary_outfile);
    putc((int)(x >> 8), binary_outfile);
    putc((int)x, binary_outfile);
    x = w[1];
    putc((int)(x >> 24), binary_outfile);
    putc((int)(x >> 16), binary_outfile);
    putc((int)(x >> 8), binary_outfile);
    putc((int)x, binary_outfile);
    return onevalue(nil);
}

static Lisp_Object MS_CDECL Lbinary_terpri(Lisp_Object nil, int nargs, ...)
{
    argcheck(nargs, 0, "binary_terpri");
    if (binary_outfile != NULL) putc('\n', binary_outfile);
    return onevalue(nil);
}

static Lisp_Object MS_CDECL Lbinary_close_output(Lisp_Object nil, int nargs, ...)
{
    argcheck(nargs, 0, "binary-close-output");
    if (binary_outfile != NULL)
    {   fclose(binary_outfile);
        binary_outfile = NULL;
    }
    return onevalue(nil);
}

static Lisp_Object Lbinary_open_input(Lisp_Object nil, Lisp_Object name)
{
    Lisp_Object r;
    FILE *fh = binary_open(nil, name, "rb", "binary_open_input");
    errexit();
    r = make_stream_handle();
    errexit();
    set_stream_read_fn(r, char_from_file);
    set_stream_read_other(r, read_action_file);
    set_stream_file(r, fh);
    return onevalue(r);
}

static Lisp_Object Lbinary_select_input(Lisp_Object nil, Lisp_Object a)
{
    if (!is_stream(a) ||
        stream_file(a) == NULL ||
        stream_write_fn(a) != 0)
        return aerror1("binary_select_input", a); /* closed file or output file */
    binary_infile = stream_file(a);
    return onevalue(nil);
}

static Lisp_Object MS_CDECL Lbinary_readbyte(Lisp_Object nil, int nargs, ...)
{
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "binary-readbyte");
    if (binary_infile == NULL) return onevalue(fixnum_of_int(-1));
    return onevalue(fixnum_of_int((int32)getc(binary_infile) & 0xff));
}

static Lisp_Object MS_CDECL Lbinary_read2(Lisp_Object nil, int nargs, ...)
{
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "binary-read2");
    if (binary_infile == NULL) return onevalue(fixnum_of_int(-1));
    {   int32 c1 = (int32)getc(binary_infile) & 0xff;
        int32 c2 = (int32)getc(binary_infile) & 0xff;
        return onevalue(fixnum_of_int((c1<<8) | c2));
    }
}

static Lisp_Object MS_CDECL Lbinary_read3(Lisp_Object nil, int nargs, ...)
{
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "binary-read3");
    if (binary_infile == NULL) return onevalue(fixnum_of_int(-1));
    {   int32 c1 = (int32)getc(binary_infile) & 0xff;
        int32 c2 = (int32)getc(binary_infile) & 0xff;
        int32 c3 = (int32)getc(binary_infile) & 0xff;
        return onevalue(fixnum_of_int((c1<<16) | (c2<<8) | c3));
    }
}

static Lisp_Object MS_CDECL Lbinary_read4(Lisp_Object nil, int nargs, ...)
{
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "binary-read4");
    if (binary_infile == NULL) return onevalue(fixnum_of_int(-1));
    {   int32 c1 = (int32)getc(binary_infile) & 0xff;
        int32 c2 = (int32)getc(binary_infile) & 0xff;
        int32 c3 = (int32)getc(binary_infile) & 0xff;
        int32 c4 = (int32)getc(binary_infile) & 0xff;
        int32 r = (c1 << 24) | (c2 << 16) | (c3 << 8) | c4;
        return onevalue(fixnum_of_int(r));
    }
}

static Lisp_Object MS_CDECL Lbinary_readfloat(Lisp_Object nil, int nargs, ...)
{
    Lisp_Object r = make_boxfloat(0.0, TYPE_DOUBLE_FLOAT);
    unsigned32 w;
    errexit();
    argcheck(nargs, 0, "binary-readfloat");
    if (binary_infile == NULL) return onevalue(r);
    w = (int32)getc(binary_infile) & 0xff;
    w = (w<<8) | ((int32)getc(binary_infile) & 0xff);
    w = (w<<8) | ((int32)getc(binary_infile) & 0xff);
    w = (w<<8) | ((int32)getc(binary_infile) & 0xff);
    ((unsigned32 *)&double_float_val(r))[0] = w;
    w = (int32)getc(binary_infile) & 0xff;
    w = (w<<8) | ((int32)getc(binary_infile) & 0xff);
    w = (w<<8) | ((int32)getc(binary_infile) & 0xff);
    w = (w<<8) | ((int32)getc(binary_infile) & 0xff);
    ((unsigned32 *)&double_float_val(r))[1] = w;
    return onevalue(r);
}

static Lisp_Object MS_CDECL Lbinary_close_input(Lisp_Object nil, int nargs, ...)
{
    argcheck(nargs, 0, "binary-close-input");
    if (binary_infile != NULL)
    {   fclose(binary_infile);
        binary_infile = NULL;
    }
    return onevalue(nil);
}

/*
 * (open-library "file" dirn) opens a new library (for use with the
 * fasl mechanism etc). If dirn=nil (or not specified) the library is
 * opened for input only. If dirn is non-nil an attempt is made to open
 * the library so that it can be updated, and if it does not exist to start
 * with it is created. The resulting handle can be passed to close-library
 * or used in the variables input-libraries or output-library.
 */

static Lisp_Object Lopen_library(Lisp_Object nil, Lisp_Object file,
                                                  Lisp_Object dirn)
{
    char filename[LONGEST_LEGAL_FILENAME];
    int32 len;
    CSLbool forinput = (dirn==nil);
    int i;
    char *w = get_string_data(file, "open-library", &len);
    errexit();
    if (len >= sizeof(filename)) len = sizeof(filename)-1;
    memcpy(filename, w, len);
    filename[len] = 0;
    for (i=0; i<number_of_fasl_paths; i++)
    {   if (fasl_files[i] == NULL) goto found;
    }
    if (number_of_fasl_paths>=MAX_FASL_PATHS-1)
        return aerror("open-library (too many open libraries)");
    number_of_fasl_paths++;
found:
    fasl_files[i] = open_pds(filename, forinput);
/*
 * allocating space using malloc() here is dodgy, because the matching
 * place in close-library does not do a corresponding free() operation.
 */
    w = (char *)malloc(strlen(filename)+1);
    if (w == NULL) w = "Unknown file";
    else strcpy(w, filename);
    fasl_paths[i] = w;
    return onevalue(SPID_LIBRARY + (((int32)i)<<20));
}

static Lisp_Object Lopen_library_1(Lisp_Object nil, Lisp_Object file)
{
    return Lopen_library(nil, file, nil);
}

static Lisp_Object Lclose_library(Lisp_Object nil, Lisp_Object lib)
{
    if (!is_library(lib)) return aerror1("close-library", lib);
    finished_with(library_number(lib));
    return onevalue(nil);
}

static Lisp_Object Llibrary_name(Lisp_Object nil, Lisp_Object lib)
{
    Lisp_Object a;
    if (!is_library(lib)) return aerror1("library-name", lib);
    a = make_string(fasl_paths[library_number(lib)]);
    errexit();
    return onevalue(a);
}

#ifdef CJAVA

extern void process_java_file(FILE *file);

static Lisp_Object Ljava(Lisp_Object nil, Lisp_Object name)
{
    char filename[LONGEST_LEGAL_FILENAME];
    int32 len;
    FILE *file;
    char *w = get_string_data(name, "java", &len);
    nil = C_nil;
    if (exception_pending()) return nil;
    if (len >= sizeof(filename)) len = sizeof(filename);
    file = open_file(filename, w, (size_t)len, "rb", NULL);
    if (file == NULL)
    {   error(1, err_open_failed, name);
        return NULL;
    }
    process_java_file(file);
    fclose(file);
    return onevalue(nil);
}

#endif

#ifdef SOCKETS

/*
 * If a Winsock function fails it leaves an error code that
 * WSAGetLastError() can retrieve. This function converts the numeric
 * codes to some printable text. Still cryptic, but maybe better than
 * the raw numbers!
 */

static char error_name[32];

char *WSAErrName(int i)
{
    switch (i)
    {
default:                 sprintf(error_name, "Socket error %d", i);
                         return error_name;

#ifdef ms_windows

case WSAEINTR:           return "WSAEINTR";
case WSAEBADF:           return "WSAEBADF";
case WSAEACCES:          return "WSAEACCES";
#ifdef WSAEDISCON
case WSAEDISCON:         return "WSAEDISCON";
#endif
case WSAEFAULT:          return "WSAEFAULT";
case WSAEINVAL:          return "WSAEINVAL";
case WSAEMFILE:          return "WSAEMFILE";
case WSAEWOULDBLOCK:     return "WSAEWOULDBLOCK";
case WSAEINPROGRESS:     return "WSAEINPROGRESS";
case WSAEALREADY:        return "WSAEALREADY";
case WSAENOTSOCK:        return "WSAENOTSOCK";
case WSAEDESTADDRREQ:    return "WSAEDESTADDRREQ";
case WSAEMSGSIZE:        return "WSAEMSGSIZE";
case WSAEPROTOTYPE:      return "WSAEPROTOTYPE";
case WSAENOPROTOOPT:     return "WSAENOPROTOOPT";
case WSAEPROTONOSUPPORT: return "WSAEPROTONOSUPPORT";
case WSAESOCKTNOSUPPORT: return "WSAESOCKTNOSUPPORT";
case WSAEOPNOTSUPP:      return "WSAEOPNOTSUPP";
case WSAEPFNOSUPPORT:    return "WSAEPFNOSUPPORT";
case WSAEAFNOSUPPORT:    return "WSAEAFNOSUPPORT";
case WSAEADDRINUSE:      return "WSAEADDRINUSE";
case WSAEADDRNOTAVAIL:   return "WSAEADDRNOTAVAIL";
case WSAENETDOWN:        return "WSAENETDOWN";
case WSAENETUNREACH:     return "WSAENETUNREACH";
case WSAENETRESET:       return "WSAENETRESET";
case WSAECONNABORTED:    return "WSAECONNABORTED";
case WSAECONNRESET:      return "WSAECONNRESET";
case WSAENOBUFS:         return "WSAENOBUFS";
case WSAEISCONN:         return "WSAEISCONN";
case WSAENOTCONN:        return "WSAENOTCONN";
case WSAESHUTDOWN:       return "WSAESHUTDOWN";
case WSAETOOMANYREFS:    return "WSAETOOMANYREFS";
case WSAETIMEDOUT:       return "WSAETIMEDOUT";
case WSAECONNREFUSED:    return "WSAECONNREFUSED";
case WSAELOOP:           return "WSAELOOP";
case WSAENAMETOOLONG:    return "WSAENAMETOOLONG";
case WSAEHOSTDOWN:       return "WSAEHOSTDOWN";
case WSAEHOSTUNREACH:    return "WSAEHOSTUNREACH";
case WSASYSNOTREADY:     return "WSASYSNOTREADY";
case WSAVERNOTSUPPORTED: return "WSAVERNOTSUPPORTED";
case WSANOTINITIALISED:  return "WSANOTINITIALISED";
case WSAHOST_NOT_FOUND:  return "WSAHOST_NOT_FOUND";
case WSATRY_AGAIN:       return "WSATRY_AGAIN";
case WSANO_RECOVERY:     return "WSANO_RECOVERY";
case WSANO_DATA:         return "WSANO_DATA";

#else

/*
 * When I run under Unix I display both the Unix and Windows form of the
 * error code.  I guess that shows you which of those platforms is the one
 * I am doing initial development on!
 */
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
/*
 * Duplicated EINTR, at least on Linux.
 */
case NO_DATA:            return "WSANO_DATA/NO_DATA";
#endif

#endif

    }
}

int ensure_sockets_ready()
{
    if (!sockets_ready)
    {
#ifdef ms_windows
/*
 * Under Windows the socket stuff is not automatically active, so some
 * system calls have to be made at the start of a run. I demand a
 * Winsock 1.1, and fail if that is not available.
 */
        WSADATA wsadata;
        int i = WSAStartup(MAKEWORD(1,1), &wsadata);
        if (i) return i;   /* Failed to start winsock for some reason */;
        if (LOBYTE(wsadata.wVersion) != 1 ||
            HIBYTE(wsadata.wVersion) != 1)
        {   WSACleanup();
            return 1;      /* Version 1.1 of winsock needed */
        }
#endif
        sockets_ready = 1;
    }
    return 0;
}

#define SOCKET_BUFFER_SIZE 256

/*
 * A stream attached to a socket is represented by putting the socket handle
 * into the field that would otherwise hold a FILE. The stream_read_data
 * field then holds a string. The first 4 characters of this contain
 * two packed integers saying how much buffered data is available,
 * and then there is just a chunk of buffered text.
 */

int char_from_socket(Lisp_Object stream)
{
    nil_as_base
    int ch = stream_pushed_char(stream);
    if (ch == NOT_CHAR)
    {   Lisp_Object w = stream_read_data(stream);
        int32 sb_data = elt(w, 0);
        int sb_start = sb_data & 0xffff, sb_end = (sb_data >> 16) & 0xffff;
        if (sb_start != sb_end) ch = celt(w, sb_start++);
        else
        {   ch = recv((SOCKET)stream_file(stream),
                      &celt(w, 4), SOCKET_BUFFER_SIZE, 0);
            if (ch == 0) return EOF;
            if (ch == SOCKET_ERROR)
            {   err_printf("socket read error (%s)\n",
                           WSAErrName(WSAGetLastError()));
                return EOF;
            }
            sb_start = 5;
            sb_end = ch + 4;
            ch = celt(w, 4);
        }
        sb_data = sb_start | (sb_end << 16);
        elt(w, 0) = sb_data;
        return ch;
    }
    else stream_pushed_char(stream) = NOT_CHAR;
    return ch;
}

/*
 * Seek and tell will be just quiet no-ops on socket streams.
 */

int32 read_action_socket(int32 op, Lisp_Object f)
{
    if (op < -1) return 0;
    else if (op <= 0xff) return (stream_pushed_char(f) = op);
    else switch (op)
    {
case READ_CLOSE:
        if (stream_file(f) == NULL) op = 0;
        else op = closesocket((SOCKET)stream_file(f));
        set_stream_read_fn(f, char_from_illegal);
        set_stream_read_other(f, read_action_illegal);
        set_stream_file(f, NULL);
        stream_read_data(f) = C_nil;
        return op;
case READ_FLUSH:
        stream_pushed_char(f) = NOT_CHAR;
        return 0;
default:
        return 0;
    }
}


int fetch_response(char *buffer, Lisp_Object r)
{
    int i;
    for (i = 0; i < LONGEST_LEGAL_FILENAME; i++)
    {   int ch = char_from_socket(r);
        if (ch == EOF) return 1;
        buffer[i] = ch;
        if (ch == 0x0a)
        {   buffer[i] = 0;
/*
 * The keys returned at the start of a response line are supposed to be
 * case insensitive, so I fold things to lower case right here.
 */
            for (i=0; buffer[i]!=0 && buffer[i]!=' '; i++)
                buffer[i] = tolower(buffer[i]);
            return 0;
        }
    }
    return 1; /* fail if response was over-long */
}


static Lisp_Object Lopen_url(Lisp_Object nil, Lisp_Object url)
{
    char filename[LONGEST_LEGAL_FILENAME],
         filename1[LONGEST_LEGAL_FILENAME], *p;
    char *user, *pass, *proto, *hostaddr, *port, *path;
    int  nuser, npass, nproto, nhostaddr, nport, npath;
    int32 len;
    struct hostent *host;
    long int hostnum;
    SOCKET s;
    int i, retcode, retry_count=0;
    Lisp_Object r;
    char *w = get_string_data(url, "open-url", &len);
    errexit();

start_again:

    if (len >= sizeof(filename)) len = sizeof(filename)-1;
    memcpy(filename, w, len);
    filename[len] = 0;
    trace_printf("OPEN_URL(%s)\n", filename);
/*
 * I want to parse the URL. I leave the result as a collection of
 * pointers (usually to the start of text within the URL itself, but
 * sometimes elsewhere, together with lengths of the substrings as found.
 */
    user = pass = proto = hostaddr = port = path = " ";
    nuser = npass = nproto = nhostaddr = nport = npath = 0;
    p = filename;
/*
 * If the start of the URL is of the form "xyz:" with xyz alphanumeric
 * then that is a protocol name, and I will force it into lower case.
 */
    for (i=0; i<len; i++)
        if (!isalnum(p[i])) break;
    if (p[i] == ':')
    {   proto = p;
        nproto = i;   /* Could still be zero! */
        p += i+1;
        len -= i+1;
        for (i=0; i<nproto; i++) proto[i] = tolower(proto[i]);
        trace_printf("Protocol found as <%.*s>\n", nproto, proto);
    }
/*
 * After any protocol specification I may have a host name, introduced
 * by "//".
 */
    if (p[0] == '/' && p[1] == '/')
    {   p += 2;
        len -= 2;
/*
 * If the URL (sans protocol) contains a "@" then I will take it to be
 * in the form
 *      user:password@hostaddr/...
 * and will split the user bit off. This will be particularly used in the
 * case of FTP requests. The password will be allowed to contain ":" and
 * "@" characters. Furthermore I will also allow the password to be
 * enclosed in quote marks ("), although since I scan for the "@" from
 * the right and for the ":" from the left these are not needed at all,
 * so if I notice them here all I have to do is to discard them!
 */
        for (i=len-1; i>=0; i--)
            if (p[i] == '@') break;
        if (i >= 0)
        {   user = p;
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
/*
 * Now what is left is a host, port number and path, written as
 *     hostaddr:port/... but note that the "/" should be treated as
 * part of the path-name.
 */
        hostaddr = p;
        for (;;)
        {   switch (hostaddr[nhostaddr])
            {
        default:
                nhostaddr++;
                continue;
        case '/':
                p += nhostaddr;
                len -= nhostaddr;
                break;
        case 0: len = 0;
                break;
        case ':':        /* port number given */
                port = hostaddr+nhostaddr+1;
                for (;;)
                {   switch (port[nport])
                    {
                default:
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
    if (npath == 0) path = "/", npath = 1;  /* Default path */
/*
 * If a protocol was not explicitly given I will try to deduce one from the
 * start of the name of the hostaddr. Failing that I will just use a default.
 */
    if (nproto == 0)
    {   if (strncmp(hostaddr, "www.", 4) == 0 ||
            strncmp(hostaddr, "wwwcgi.", 7) == 0)
        {   proto = "http";
            nproto = 4;
        }
        else
        {   proto = "ftp";
            nproto = 3;
        }
    }
/*
 * If the user gave an explicit port number I will try to use it. If the
 * port was not numeric I ignore it and drop down to trying to use
 * a default port based on the selected protocol.
 */
    if (nport != 0)
    {   int w;
        memcpy(filename1, port, nport);
        filename1[nport] = 0;
        if (sscanf(filename1, "%d", &w) == 1) nport = w;
        else nport = 0;
    }
    if (nport == 0)
    {   if (nproto == 3 && memcmp(proto, "ftp", 3) == 0) nport = 21;
        else if (nproto == 6 && memcmp(proto, "gopher", 6) == 0) nport = 70;
        else if (nproto == 6 && memcmp(proto, "telnet", 6) == 0) nport = 23;
        else if (nproto == 4 && memcmp(proto, "wais", 4) == 0) nport = 210;
        else if (nproto == 4 && memcmp(proto, "http", 4) == 0) nport = 80;
        else return aerror("Unknown protocol");
    }
/*
 * If no host-name was given then the object concerned is on the
 * local machine. This is a funny case maybe, but I will just chain
 * through and open it as an ordinary file (without regard to
 * protocol etc).
 */
    if (nhostaddr == 0)
    {   FILE *file = open_file(filename1, path, (size_t)npath, "r", NULL);
        if (file == NULL) return onevalue(nil);
        push(url);
        r = make_stream_handle();
        pop(url);
        errexit();
        stream_type(r) = url;
        set_stream_file(r, file);
        set_stream_read_fn(r, char_from_file);
        set_stream_read_other(r, read_action_file);
        return onevalue(r);
    }
    if (nproto == 3 && strcmp(proto, "ftp") == 0 && nuser == 0)
    {   user = "anonymous";
        nuser = strlen(user);
        if (npass == 0)
        {   pass = "acn1@cam.ac.uk";
            npass = strlen(pass);
        }
    }
    trace_printf(
        "User <%.*s> Pass <%.*s> Proto <%.*s>\n"
        "Host <%.*s> Port <%d> Path <%.*s>\n",
        nuser, user, npass, pass, nproto, proto,
        nhostaddr, hostaddr, nport, npath, path);
    if (ensure_sockets_ready() != 0) return nil;
    memcpy(filename1, hostaddr, nhostaddr);
    filename1[nhostaddr] = 0;
/* I try to accept either "." form or named host specifications */
    hostnum = inet_addr(filename1);
    if (hostnum == INADDR_NONE)
    {   host = gethostbyname(filename1);
        if (host != NULL)
            hostnum = ((struct in_addr *)host->h_addr)->s_addr;
    }
    if (hostnum == INADDR_NONE)
    {   err_printf("Host not found (%s)\n", WSAErrName(WSAGetLastError()));
        return onevalue(nil);
    }
    else
    {   err_printf("Host number %d.%d.%d.%d\n",
            hostnum & 0xff,
            (hostnum>>8) & 0xff,
            (hostnum>>16) & 0xff,
            (hostnum>>24) & 0xff);
    }
    s = socket(PF_INET, SOCK_STREAM, 0);  /* Make a new socket */
    {   struct sockaddr_in sin;
        memset(&sin, 0, sizeof(sin));
        sin.sin_family = AF_INET;
        sin.sin_port = htons(nport);
        sin.sin_addr.s_addr = hostnum;
        trace_printf("Contacting %.*s...\n", nhostaddr, hostaddr);
        ensure_screen();
        if (connect(s, (struct sockaddr *)&sin, sizeof(sin)) == SOCKET_ERROR)
        {   err_printf("connect failed %s\n", WSAErrName(WSAGetLastError()));
            closesocket(s);
            return onevalue(nil);
        }
        trace_printf("Connection created\n");
    }
    sprintf(filename1, "GET %.*s HTTP/1.0\x0d\x0a\x0d\x0a", npath, path);

/* MD addition from webcore.c*/
    i = strlen(filename1);
/*
 * Certainly if the Web server I am accessing is the one that comes as
 * standard with Windows NT I need to reassure it that I want the document
 * returned to me WHATEVER its media type is. If I do not add in the
 * line "Accept: *//*" the GET request will only allow me to fetch simple
 * text (?)
 * Note that above I write "*//*" where I only really mean a single "/"
 * but where C comment conventions intrude!
 */
    sprintf(&filename1[i], "Accept: */*\x0d\x0a\x0d\x0a");

    /* err_printf("About to send <%s>\n", filename1); */
    if (send(s, filename1, strlen(filename1), 0) == SOCKET_ERROR)
    {   err_printf("Send error (%s)\n", WSAErrName(WSAGetLastError()));
        closesocket(s);
        return onevalue(nil);
    }

    push(url);
    r = make_stream_handle();
    pop(url);
    errexit();
    stream_type(r) = url;
    push(r);
    url = getvector(TAG_VECTOR, TYPE_STRING, SOCKET_BUFFER_SIZE+8);
    pop(r);
    errexit();
    elt(url, 0) = 0;
    stream_read_data(r) = url;
    set_stream_file(r, (FILE *)s);
    set_stream_read_fn(r, char_from_socket);
    set_stream_read_other(r, read_action_socket);

/*
   Now fetch the status line.
*/
    if (fetch_response(filename1, r))
    {   err_printf("Error fetching status line from the server\n");
        Lclose(nil,r);
        return onevalue(nil);
    }

/*
 * I check if the first line returned is in the form "HTTP/n.n nnn " and if
 * it is not I assume that I have reached an HTTP/0.9 server and all the
 * text that comes back will be the body.
 */
    {   int major, minor;
/*
 * I will not worry much about just which version of HTTP the system reports
 * that it is using, provided it says something! I expect to see the return
 * code as a three digit number. I verify that it is in the range 0 to 999 but
 * do not check for (and thus reject) illegal responses such as 0000200.
 */
        if (sscanf(filename1,"http/%d.%d %d", &major, &minor, &retcode) != 3 ||
            retcode < 0 || retcode > 999)
        {   err_printf("Bad protocol specification returned\n");
            Lclose(nil,r);
            return onevalue(nil);
        }
    }
/*
 * In this code I treat all unexpected responses as errors and I do not
 * attempt to continue. This is sometimes going to be overly pessimistic
 * and RFC1945 tells me that I should treat unidentified codes as the
 * n00 variant thereupon.
 */
    switch (retcode)
    {
  default:retcode = 0;
          break;
  case 200:
          break;   /* A success code for GET requests */
  case 301:        /* Redirection request */
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
          while (memcmp(filename1, "location: ", 10) != 0);
          if (retcode == 0) break;
/*
 * At present I take a somewhat simplistic view of redirection, and just
 * look for the first alternative URL and start my entire unpicking
 * process afresh from there.
 */
          for (i = 10; filename1[i] == ' '; i++);
          w = &filename1[i];
          while (filename1[i]!=' ' && filename1[i]!=0) i++;
          filename1[i] = 0;
          len = strlen(w);
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
    {   Lclose(nil,r);
        return onevalue(nil);
    }

/*
   Skip further information returned by the server until a line containing
   just the end-of-line marker is fetched
*/
    do
    {   for (i = 0; i < LONGEST_LEGAL_FILENAME; i++)
        {   int ch = char_from_socket(r);
            if (ch == EOF)
            {   err_printf("Error fetching additional info from the server\n");
                Lclose(nil,r);
                return onevalue(nil);
            }
            if (ch == 0x0a) break;
        }
    } while (i > 1);


    return onevalue(r);

}

#endif

int window_heading = 0;

Lisp_Object Lwindow_heading2(Lisp_Object nil, Lisp_Object a, Lisp_Object b)
{
#ifdef CWIN
    int32 n, bit;
    char *s, txt[32];
    if (is_fixnum(b)) n = int_of_fixnum(b);
    else b = 2;
    if (is_vector(a) && type_of_header(vechdr(a)) == TYPE_STRING)
    {   int32 l = length_of_header(vechdr(a));
        if (l > 30) l = 30;
        memcpy(txt, &celt(a, 0), l);
        txt[l] = 0;
        s = txt;
    }
    else if (b == 2) s = "";
    else s = NULL;
    switch (n)
    {
case 0: cwin_report_left(s);  bit = 1; break;
case 1: cwin_report_mid(s);   bit = 2; break;
default:cwin_report_right(s); bit = 4; break;
    }
    if (s == NULL || *s == 0) window_heading &= ~bit;
    else window_heading |= bit;
#endif
    return onevalue(nil);
}

Lisp_Object Lwindow_heading1(Lisp_Object nil, Lisp_Object a)
{
    return Lwindow_heading2(nil, a, nil);
}

setup_type const print_setup[] =
{
#ifdef CJAVA
    {"java",                    Ljava, too_many_1, wrong_no_1},
#endif
#ifdef SOCKETS
    {"open-url",                Lopen_url, too_many_1, wrong_no_1},
#endif
    {"window-heading",          Lwindow_heading1, Lwindow_heading2, wrong_no_1},
    {"eject",                   wrong_no_na, wrong_no_nb, Leject},
    {"filep",                   Lfilep, too_many_1, wrong_no_1},
    {"filedate",                Lfiledate, too_many_1, wrong_no_1},
    {"flush",                   Lflush1, wrong_no_nb, Lflush},
    {"streamp",                 Lstreamp, too_many_1, wrong_no_1},
    {"is-console",              Lis_console, too_many_1, wrong_no_1},
    {"lengthc",                 Llengthc, too_many_1, wrong_no_1},
    {"linelength",              Llinelength, too_many_1, Llinelength0},
    {"lposn",                   wrong_no_na, wrong_no_nb, Llposn},
    {"~open",                   too_few_2, Lopen, wrong_no_2},
    {"open-library",            Lopen_library_1, Lopen_library, wrong_no_2},
    {"close-library",           Lclose_library, too_many_1, wrong_no_1},
    {"library-name",            Llibrary_name, too_many_1, wrong_no_1},
    {"create-directory",        Lcreate_directory, too_many_1, wrong_no_1},
    {"delete-file",             Ldelete_file, too_many_1, wrong_no_1},
    {"rename-file",             too_few_2, Lrename_file, wrong_no_2},
    {"file-readablep",          Lfile_readable, too_many_1, wrong_no_1},
    {"file-writeablep",         Lfile_writeable, too_many_1, wrong_no_1},
    {"directoryp",              Ldirectoryp, too_many_1, wrong_no_1},
#ifdef COMMON
    {"truename",                Ltruename, too_many_1, wrong_no_1},
#endif
    {"list-directory",          Llist_directory, too_many_1, wrong_no_1},
    {"chdir",                   Lchange_directory, too_many_1, wrong_no_1},
    {"make-function-stream",    Lmake_function_stream, too_many_1, wrong_no_1},
    {"get-current-directory",   wrong_no_na, wrong_no_nb, Lget_current_directory},
    {"user-homedir-pathname",	wrong_no_na, wrong_no_nb, Luser_homedir_pathname},
    {"get-lisp-directory",      wrong_no_na, wrong_no_nb, Lget_lisp_directory},
    {"pagelength",              Lpagelength, too_many_1, wrong_no_1},
    {"posn",                    Lposn_1, wrong_no_nb, Lposn},
    {"spaces",                  Lxtab, too_many_1, wrong_no_1},
    {"terpri",                  wrong_no_na, wrong_no_nb, Lterpri},
    {"tmpnam",                  wrong_no_na, wrong_no_nb, Ltmpnam},
    {"ttab",                    Lttab, too_many_1, wrong_no_1},
    {"wrs",                     Lwrs, too_many_1, wrong_no_1},
    {"xtab",                    Lxtab, too_many_1, wrong_no_1},
    {"princ-upcase",            Lprinc_upcase, too_many_1, wrong_no_1},
    {"princ-downcase",          Lprinc_downcase, too_many_1, wrong_no_1},
    {"binary_open_output",      Lbinary_open_output, too_many_1, wrong_no_1},
    {"binary_prin1",            Lbinary_prin1, too_many_1, wrong_no_1},
    {"binary_princ",            Lbinary_princ, too_many_1, wrong_no_1},
    {"binary_prinbyte",         Lbinary_prinbyte, too_many_1, wrong_no_1},
    {"binary_prin2",            Lbinary_prin2, too_many_1, wrong_no_1},
    {"binary_prin3",            Lbinary_prin3, too_many_1, wrong_no_1},
    {"binary_prinfloat",        Lbinary_prinfloat, too_many_1, wrong_no_1},
    {"binary_terpri",           wrong_no_na, wrong_no_nb, Lbinary_terpri},
    {"binary_close_output",     wrong_no_na, wrong_no_nb, Lbinary_close_output},
    {"binary_open_input",       Lbinary_open_input, too_many_1, wrong_no_1},
    {"binary_select_input",     Lbinary_select_input, too_many_1, wrong_no_1},
    {"binary_readbyte",         wrong_no_na, wrong_no_nb, Lbinary_readbyte},
    {"binary_read2",            wrong_no_na, wrong_no_nb, Lbinary_read2},
    {"binary_read3",            wrong_no_na, wrong_no_nb, Lbinary_read3},
    {"binary_read4",            wrong_no_na, wrong_no_nb, Lbinary_read4},
    {"binary_readfloat",        wrong_no_na, wrong_no_nb, Lbinary_readfloat},
    {"binary_close_input",      wrong_no_na, wrong_no_nb, Lbinary_close_input},
    {"prinhex",                 Lprinhex, Lprinhex2, wrong_no_1},
    {"prinoctal",               Lprinoctal, Lprinoctal2, wrong_no_1},
    {"prinbinary",              Lprinbinary, Lprinbinary2, wrong_no_1},
#ifdef COMMON
    {"charpos",                 Lposn_1, wrong_no_nb, Lposn},
    {"finish-output",           Lflush1, wrong_no_nb, Lflush},
    {"make-synonym-stream",     Lmake_synonym_stream, too_many_1, wrong_no_1},
    {"make-broadcast-stream",   Lmake_broadcast_stream_1, Lmake_broadcast_stream_2, Lmake_broadcast_stream_n},
    {"make-concatenated-stream",Lmake_concatenated_stream_1, Lmake_concatenated_stream_2, Lmake_concatenated_stream_n},
    {"make-two-way-stream",     too_few_2, Lmake_two_way_stream, wrong_no_2},
    {"make-echo-stream",        too_few_2, Lmake_echo_stream, wrong_no_2},
    {"make-string-input-stream",Lmake_string_input_stream_1, Lmake_string_input_stream_2, Lmake_string_input_stream_n},
    {"make-string-output-stream",wrong_no_na, wrong_no_nb, Lmake_string_output_stream},
    {"get-output-stream-string",Lget_output_stream_string, too_many_1, wrong_no_1},
    {"close",                   Lclose, too_many_1, wrong_no_1},
    {"~tyo",                    Ltyo, too_many_1, wrong_no_1},
/* At least as a temporary measure I provide these in COMMON mode too */
    {"explode",                 Lexplode, too_many_1, wrong_no_1},
    {"explodec",                Lexplodec, too_many_1, wrong_no_1},
    {"explode2",                Lexplodec, too_many_1, wrong_no_1},
    {"explode2lc",              Lexplode2lc, too_many_1, wrong_no_1},
    {"exploden",                Lexploden, too_many_1, wrong_no_1},
    {"explodecn",               Lexplodecn, too_many_1, wrong_no_1},
    {"explode2n",               Lexplodecn, too_many_1, wrong_no_1},
    {"explode2lcn",             Lexplode2lcn, too_many_1, wrong_no_1},
    {"explodehex",              Lexplodehex, too_many_1, wrong_no_1},
    {"explodeoctal",            Lexplodeoctal, too_many_1, wrong_no_1},
    {"explodebinary",           Lexplodebinary, too_many_1, wrong_no_1},
    {"prin",                    Lprin, too_many_1, wrong_no_1},
    {"prin1",                   Lprin, too_many_1, wrong_no_1},
    {"princ",                   Lprinc, too_many_1, wrong_no_1},
    {"prin2",                   Lprinc, too_many_1, wrong_no_1},
    {"prin2a",                  Lprin2a, too_many_1, wrong_no_1},
    {"print",                   Lprint, too_many_1, wrong_no_1},
    {"printc",                  Lprintc, too_many_1, wrong_no_1},
    {"set-print-precision",     Lprint_precision, too_many_1, wrong_no_1},
#else
    {"close",                   Lclose, too_many_1, wrong_no_1},
    {"explode",                 Lexplode, too_many_1, wrong_no_1},
    {"explodec",                Lexplodec, too_many_1, wrong_no_1},
    {"explode2",                Lexplodec, too_many_1, wrong_no_1},
    {"explode2lc",              Lexplode2lc, too_many_1, wrong_no_1},
    {"explode2uc",              Lexplode2uc, too_many_1, wrong_no_1},
    {"exploden",                Lexploden, too_many_1, wrong_no_1},
    {"explodecn",               Lexplodecn, too_many_1, wrong_no_1},
    {"explode2n",               Lexplodecn, too_many_1, wrong_no_1},
    {"explode2lcn",             Lexplode2lcn, too_many_1, wrong_no_1},
    {"explode2ucn",             Lexplode2ucn, too_many_1, wrong_no_1},
    {"explodehex",              Lexplodehex, too_many_1, wrong_no_1},
    {"explodeoctal",            Lexplodeoctal, too_many_1, wrong_no_1},
    {"explodebinary",           Lexplodebinary, too_many_1, wrong_no_1},
    {"prin",                    Lprin, too_many_1, wrong_no_1},
    {"prin1",                   Lprin, too_many_1, wrong_no_1},
    {"princ",                   Lprinc, too_many_1, wrong_no_1},
    {"prin2",                   Lprinc, too_many_1, wrong_no_1},
    {"prin2a",                  Lprin2a, too_many_1, wrong_no_1},
    {"print",                   Lprint, too_many_1, wrong_no_1},
    {"printc",                  Lprintc, too_many_1, wrong_no_1},
    {"set-print-precision",     Lprint_precision, too_many_1, wrong_no_1},
    {"tyo",                     Ltyo, too_many_1, wrong_no_1},
#endif
    {NULL,                      0, 0, 0}
};

/* end of print.c */

