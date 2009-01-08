/* sysipaq.c                      Copyright (C) 1989-2008 Codemist Ltd */

/*
 * System specific code. My objective is that this will subsume and replace
 * all the other files that I have or had called sysxxx.c, sysyyy.c etc.
 *
 * System-specific code for use with the "fwin" window interface code.
 * This is expected to be buildable on Windows via mingw32, on
 * both 32 and 64-bit variants of Linux, and (I hope) on Macintosh
 * system X (at least if an X server is made available to it). I thus
 * at least hope that I can use it as a generic uniform body of code.
 * The system will also build as a terminal-mode program as well as
 * a windowed one.
 *
 * I will use "autoconf" and all that stuff with a view to making
 * this code build on a wide range of systems via the usual
 *    ./configure ; make
 * sequence. This (obviously) involves a Unix-like build environment
 * but mingw/msys provides that for Windows.
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


/* Signature: 278b2cbe 21-Jul-2008 */

#include "headers.h"

/*
 * WIN32               all Windows platforms that I support
 * <else>              Unix-like
 *
 *    popen(cmd, dir)  vs   _popen(cms, dir)
 *    pclose(stream)   vs   _pclose(stream)
 *    fileno(file)     vs   _fileno(file)
 *    struct stat      vs   struct _stat
 *    stat             vs   _stat
 *    ftruncate(file)  vs   chsize(file)
 *    S_IFMT __S_IFMT       to go with stat
 *    S_IFDIR __S_IFDIR
 *    DO_NOT_USE_GETUID     is getuid available
 *    UNIX_TIMES            how can I read the clock
 *    UTIME_TIME_T          struct utimbuf
 */



#ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif

#ifdef HAVE_DIRENT_H
#include <dirent.h>
#endif

#ifdef WIN32
#include <windows.h>
#endif

/*
 * Jollies re GC statistics...
 */
 
static char time_string[32], space_string[32];

void report_time(int32_t t, int32_t gct)
{
    sprintf(time_string, "%ld.%.2ld+%ld.%.2ld secs  ",
        t/100L, t%100L, gct/100L, gct%100L);
    if ((window_heading & 1) == 0) fwin_report_left(time_string);
}

void report_space(int n, double percent)
{
    sprintf(space_string, "[GC %d]:%.2f%%", n, percent);
    if ((window_heading & 4) == 0) fwin_report_right(space_string);
}

void flush_screen()
{
    fwin_ensure_screen();
}

void pause_for_user()
{
}

int wimpget(char *buf)
{
    int c, n=0;
    ensure_screen();
    while (n < 255)
    {   c = ce_readch();
        if (c == (0x1f & 'C') ||           /* ^C - quiet : quit      */
            c == (0x1f & 'G')) return 0;   /* ^G - noisy : interrupt */
        if (c == EOF) c = 0x1f & 'D';
        buf[n++] = (char)c;
        if (c == '\n' || c == (0x1f & 'D')) break;
    };
    return n;
}

FILE *my_popen(char *command, char *direction)
{
    return NULL;
}

int my_pipe_putc(int c, FILE *f)
{
    return putc(c, f);
}

int my_pipe_flush(FILE *f)
{
    return fflush(f);
}

void my_pclose(FILE *stream)
{
}


/*
 * Map file-names to expand references to shell variables etc.
 * and to provide portability of names across operating systems.
 */


char *look_in_lisp_variable(char *o, int prefix)
{
    Lisp_Object nil, var;
/*
 * I will start by tagging a '$' (or whatever) on in front of the
 * parameter name.
 */
    o[0] = (char)prefix;
    var = make_undefined_symbol(o);
    nil = C_nil;
/*
 * make_undefined_symbol() could fail either if we had utterly run out
 * of memory or if somebody generated an interrupt (eg ^C) around now. Ugh.
 */
    if (exception_pending())
    {   flip_exception();
        return NULL;
    }
/*
 * If the variable $name was undefined then I use an empty replacement
 * text for it. Otherwise I need to look harder at its value.
 */
    if (qvalue(var) == unset_var) return o;
    else
    {   Header h;
        intptr_t len;
        var = qvalue(var);
/*
 * Mostly I expect that the value will be a string or symbol.
 */
#ifdef COMMON
        if (complex_stringp(var))
        {   var = simplify_string(var);
            nil = C_nil;
            if (exception_pending())
            {   flip_exception();
                return NULL;
            }
        }
#endif /* COMMON */
        if (symbolp(var))
        {   var = get_pname(var);
            nil = C_nil;
            if (exception_pending())
            {   flip_exception();
                return NULL;
            }
            h = vechdr(var);
        }
        else if (!is_vector(var) ||
                 type_of_header(h = vechdr(var)) != TYPE_STRING)
            return NULL;
        len = length_of_header(h) - CELL;
/*
 * Copy the characters from the string or from the name of the variable
 * into the file-name buffer. There could at present be a crash here
 * if the expansion was very very long and overflowed my buffer. Tough
 * luck for now - people doing that (maybe) get what they (maybe) deserve.
 */
        memcpy(o, (char *)var + (CELL - TAG_VECTOR), (size_t)len);
        o = o + len;
        return o;
    }
}


#ifdef UNIX_TIMES
/*
 * This is a BSD-style clock facility, possibly giving a resolution of
 * only 1/100 second.  I believe that Portable Standard Lisp typically
 * reports user time, which is why I do this.  A further nasty here
 * is that I am probably compiling this file in ANSI mode, and on
 * at least some computers this makes #include <sys/times.h> fairly
 * ineffective (ugh), so I declare all the structures and functions I
 * want directly (ugh ugh) and hope they are as needed.  Consider this
 * when you port to a new machine.
 */

clock_t read_clock(void)
{
    struct my_tms {
        clock_t tms_utime;
        clock_t tms_stime;
        clock_t tms_cutime;
        clock_t tms_cstime;
        } tmsbuf;
    clock_t w1, w2, w3;
    extern void times(/*struct my_tms * */);
    times(&tmsbuf);
    w1 = tmsbuf.tms_utime;   /* User time in UNIX_TIMES ticks */
    w2 = CLOCKS_PER_SEC;
    w3 = UNIX_TIMES;
    return (clock_t)((double)w1 * ((double)w2/(double)w3));
}

#else

clock_t read_clock()
{
    return clock();
}

#endif

int batchp()
{
    return !isatty(fileno(stdin));
}

/*
 * The next procedure is responsible for establishing information about
 * where the main checkpoint image should be recovered from, and where
 * and fasl files should come from.
 */
char *find_image_directory(int argc, char *argv[])
{
    int n = strlen(programName) + strlen(programDir) + 6;
    char *w = (char *)(*malloc_hook)(n);
    strcpy(w, programDir);
    n = strlen(programDir);
    w[n] = '/';                 /* Should be '\\' for Windows? */
    strcpy(&w[n+1], programName);
    n += strlen(programName) + 1;
    strcpy(&w[n], ".img");
    return w;
}

/*
 * The following function controls memory allocation policy
 */

int32_t ok_to_grab_memory(int32_t current)
{
#ifdef COMMON
    return current;
#else
    return 3*current + 2;
#endif
}

time_t MS_CDECL time(time_t *x)
{
    time_t r = 0;
    if (x != NULL) *x = r;
    return r;
}

clock_t MS_CDECL clock()
{
    return 0;
}

const char *fwin_full_program_name = (const char *)"./csl.exe";
const char *programName            = (const char *)"csl.exe";
const char *programDir             = (const char *)".";

void fwin_restore()
{
}

void fwin_putchar(int c)
{
/*
 * Despite using termed during keyboard input I will just use the
 * ordinary C stream functions for normal output. Provided I do an
 * fflush(stdout) before requesting input I should be OK.
 */
    char s[2];
    s[0] = c;
    s[1] = 0;
    ce_print(s);
}

void fwin_puts(const char *s)
{
    ce_print(s);
}


void MS_CDECL fwin_printf(const char *fmt, ...)
{
    va_list a;
    char s[200];
    va_start(a, fmt);
    vsprintf(s, fmt, a);
    va_end(a);
    ce_print(s);
}

void fwin_vfprintf(const char *fmt, va_list a)
{
    char s[200];
    vsprintf(s, fmt, a);
    ce_print(s);
}

void fwin_ensure_screen()
{
}

void fwin_report_left(const char *s)
{
}

void fwin_report_mid(const char *s)
{
}

void fwin_report_right(const char *s)
{
}

void fwin_set_prompt(const char *s)
{
}

void fwin_menus(char **modules, char **switches)
{
}

void fwin_refresh_switches(char **switches, char **packages)
{
}

void fwin_set_help_file(const char *key, const char *path)
{
}

void fwin_acknowledge_tick()
{
}

int fwin_windowmode()
{
    return 0;
}

/*
 * The following four strings may be updated (but PLEASE keep within the
 * length limit) to make the display in the "ABOUT" box reflect your
 * particular application.
 */
char about_box_title[32] = "About Reduce";
char about_box_description[32] = "Version ???";
char about_box_rights_1[32] = "A C Hearn";
char about_box_rights_2[32] = "Codemist Ltd";
char about_box_rights_3[32] = "Ipaq version March 2005";

int get_current_directory(char *s, int n)
{
    strcpy(s, ".");
    return 1;
}

int get_home_directory(char *s, int n)
{
    strcpy(s, ".");
    return 1;
}

int get_users_home_directory(char *s, int n)
{
    strcpy(s, ".");
    return 1;
}

char *ctime(const time_t *t)
{
    return "<today's date>";
}

void process_file_name(char *filename, char *old, size_t n)
/*
 * This procedure maps filenames by expanding some environment
 * variables.  It is very thoroughly system specific, which is why it
 * is in this file.  See also LONGEST_LEGAL_FILENAME in "tags.h" for a
 * limit on the permitted size of an expanded filename.
 * The input (old) is not necessarily properly terminated as a C string,
 * so n says how many characters to inspect.  Build a converted name
 * in filename.
 * At present the expansions I allow are:
 *
 *    $xxx   (terminated by '.', '/' or '\' with at least one char x)
 *    ${xxx} (self-terminating)
 *           First check for a Lisp variable $xxx. If this is set (and is
 *           a string or a symbol) then its value is used. If not then
 *           next inspect the environment variable xxx and dump its
 *           value into the output.  If the variable is unset then a check
 *           is made for the value of a global lisp variable called @xxx,
 *           and if that exists and is a string or symbol it is used.
 *           If @xxx is undefined a null string is inserted.
 *           If one of the variables is defined but has an improper value
 *           then the whole file-translation fails.
 *           The use of two Lisp variables makes it possible to control
 *           precedence between these and shell variables.
 *
 *    ~      ) followed by '.', '/' or '\'
 *    ~xxx   )
 *           On Unix these try to find home directories using
 *           getpwuid(getuid()) for '~' and getpwnam() for ~xxx.
 *           If that fails ~ expands into nothing at all.
 *           This syntax is only recognised at the very start of a file-name.
 *           For systems other than Unix this syntax will not be useful and
 *           should be avoided, however as an experimental place-holder I
 *           may do things with environment variables called HOME etc.
 * 
 * 
 * I convert file-names of the form aaa/bbb/ccc.ddd into something
 * acceptable to the system being used, even though this may result in
 * some native file titles that include '/' characters becoming unavailable.
 * The reasoning here is that scripts and programs can then use Unix-like
 * names and non-Unix hosts will treat them forgivingly.
 *
 *
 */
{
    int i;
    int c;
    char *o;
    if (n == 0)
    {   *filename = 0;
        return;    /* deem zero-length name to be illegal */
    }
    o = filename;
    c = *old;
/*
 * First I deal with a leading "~"
 */
    if (c == '~')
    {   old++;
        n--;
        while (n != 0)
        {   c = *old;
            if (c == '.' || c == '/' || c == '\\') break;
            old++;
            n--;
            *o++ = (char)c;
        }
        *o = 0;
/*
 * actually deciding what the home directory is is passed down to a
 * system-specific call, but it is not to be relied upon especially
 * on personal computers.
 */
        if (o == filename)  /* '~' on its own */
        {   get_home_directory(filename, LONGEST_LEGAL_FILENAME);
            o = filename + strlen(filename);
        }
        else
        {   get_users_home_directory(filename, LONGEST_LEGAL_FILENAME);
            o = filename + strlen(filename);
        }
    }
/*
 * Having copies a user-name across (if there was one) I now copy the
 * rest of the file-name, expanding $xxx and ${xxx} as necessary.
 */
    while (n != 0)
    {   c = *old++;
        n--;
/*
 * If I find a "$" that is either at the end of the file-name or that is
 * immediately followed by ".", "/" or "\" then I will not use it for
 * parameter expansion. This at least gives me some help with the RISCOS
 * file-name $.abc.def where the "$" is used to indicate the root of the
 * current disc.
 */
        if (c == '$' && n != 0 &&
            (c = *old) != '.' && c != '/' && c != '\\')
        {   char *p = o;
            const char *w;
/*
 * I collect the name of the parameter at the end of my file-name buffer,
 * but will over-write it later on when I actually do the expansion.
 */
            if (c == '{')
            {   old++;
                n--;
                while (n != 0)
                {   c = *old++;
                    n--;
                    if (c == '}') break;
                    *p++ = (char)c;
                }
            }
            else
            {   while (n != 0)
                {   c = *old;
                    if (c == '.' || c == '/' || c == '\\') break;
                    old++;
                    n--;
                    *p++ = (char)c;
                }
            }
            *p = 0;
            i = strlen(o) + 2;
            while (i-- != 0) o[i] = o[i-1];
#ifdef CSL
            if ((p = look_in_lisp_variable(o, '$')) != NULL &&
                p != o) o = p;
            else 
#endif
            if ((w = my_getenv(o+1)) != NULL)    /* Shell variable? */
            {   strcpy(o, w);
                o = o + strlen(o);
            }
#ifdef CSL
            else if ((p = look_in_lisp_variable(o, '@')) != NULL)
                o = p;
#endif
            else
            {   *filename = 0;  /* return reporting failure */
                return;
            }
        }
        else *o++ = (char)c;
    }
    *o = 0;


#ifdef WIN32
/*
 * Now the filename has had $ and ~ prefix things expanded - I "just"
 * need to deal with sub-directory representation issues. Specifically I need
 * to map "/" separators into "\" so that if a user presents a file
 * name such as aaa/bbb/ccc.d it gets passed to the operating system
 * as aaa\bbb\ccc.d
 * Note that I enable this code under the heading MS_DOS but really it
 * means any file-system (eg Windows too) that uses "\" as its main
 * directory separator character.
 * As of September 2004 I will also map an intial sequence
 *         /cygdrive/x/
 * onto    x:\
 */

    if (strncmp(filename, "/cygdrive/", 10) == 0 &&
                filename[11] == '/')
    {   char *p = filename+2, *tail = filename+11;
        filename[0] = filename[10];
        filename[1] = ':';
        while (*tail != 0) *p++ = *tail++;
        *p = 0;
    }
/*
 * I map "/" characters in MSDOS filenames into "\" so that users
 * can give file names with Unix-like slashes as separators if they want.
 * People who WANT to use filenames with '/' in them will be hurt.
 */
    {   int j;
        char *tail = filename;
        while ((j = *tail) != 0)
        {   if (j == '/') *tail = '\\';
            tail++;
        }
/*
 * stat and friends do not like directories referred to as "\foo\", so check
 * for a trailing slash, being careful to respect directories with names
 * like "\" and "a:\".
 */
       j = strlen(filename);
       if (j > 0 && j != 1 && !(j == 3 && *(filename+1) == ':'))
       {
           if ( (*(tail - 1) == '\\')) *(tail - 1) = 0;
       }
    }
#endif /* WIN32 */
}

FILE *open_file(char *filename, char *old, size_t n,
                char *mode, FILE *old_file)
{
/*
 * mode is something like "r" or "w" or "rb", as needed by fopen(),
 * and old_file is NULL normally, but can be a (FILE *) to indicate
 * the use of freopen rather than fopen.
 */
    FILE *ff;
    process_file_name(filename, old, n);
ce_print("Filename given as: "); ce_print(old);
ce_print("\nConverted to: "); ce_print(filename);
ce_print("\n");
    if (*filename == 0) return NULL;
#ifdef NO_BINARY_FOPEN
/*
 * On some Unix implementations (I mean DECs version on its MIPS workstations
 * and on the microvax I tried) the library does not support "rb" and "wb"
 * modes, so I work around that here.  Explicit selection of binary file
 * access will be needed on some non-Unix operating systems, but should
 * never be relevant under Unix, hence my choice of a flag for the conditional
 * compilation here.
 */
    if (mode[0] == 'w')
    {   if (mode[1] == '+') mode = "w+";
        else mode = "w";
    }
    else if (mode[1] == '+') mode = "r+";
    else mode = "r";    /* That ought to patch it up */
#endif

    if (old_file == NULL) ff = fopen(filename, mode);
    else 
    {   fclose(old_file);
        ff = fopen(filename, mode);
    }
/*
 * In suitable cases when the first attempt to open the file fails I
 * will try creating any necessary directories and then try again.
 */
    if (ff==NULL && *mode=='w')
    {   char *p = filename;
        while (*p != 0)
        {   int ch = *p;
            if (ch == '/' || ch == '\\')
            {   *p = 0;
                // Cmkdir(filename);  CAN NOT DO THIS YET
                *p = ch;
            }
            p++;
        }
        if (old_file == NULL) ff = fopen(filename, mode);
        else
        {   fclose(old_file);
            ff = fopen(filename, mode);
        }
    }
    return ff;
}

int fwin_linelength = 67;

int fwin_pause_at_end = 0;

void abort()
{
    exit(1);
}

int isatty(int n)
{
    return 0;
}

long file_length(char *filename, char *old, size_t n)
{
    return 0;
}

int file_readable(char *filename, char *old, size_t n)
{
    FILE *ff;
    process_file_name(filename, old, n);
    ff = fopen(filename, "r");
    if (ff == NULL) return 0;
    fclose(ff);
    return 1;
}

int file_writeable(char *filename, char *old, size_t n)
{
    process_file_name(filename, old, n);
    return 1;
}

int directoryp(char *filename, char *old, size_t n)
{
    process_file_name(filename, old, n);
    return 0;
}

char *get_truename(char *filename, char *old, size_t n)
{
    process_file_name(filename, old, n);
    return filename;
}

extern CSLbool file_exists(char *filename, char *old, size_t n, char *tt)
{
    FILE *ff;
    process_file_name(filename, old, n);
    ff = fopen(filename, "r");
    if (ff == NULL) return 0;
    fclose(ff);
    strcpy(tt, "Today");
    return 1;
}

extern char *change_directory(char *filename, char *old, size_t n)
{
    return "change_directory not implemented";
}

/*
 * The interfaces to create_directory and delete_file are similar
 * to that for open_file. They do what their names suggest! They return
 * zero on success, and non-zero on failure. Each does file-name
 * conversion so that Unix-style names can be used even with Windows.
 */

extern int create_directory(char *filename, char *old, size_t n)
{
   return 0;
}

extern int delete_file(char *filename, char *old, size_t n)
{
    return 0;
}

extern int rename_file(char *from_name, char *from_old, size_t from_size,
                       char *to_name,   char *to_old,   size_t to_size)
{
    return 0;
}

int truncate_file(FILE *f, long int where)
{
    return 0;
}

char *tmpnam()
{
    return "tempfile.tmp";
}

char *my_getenv(char *s)
{
    return NULL;
}

int my_system(char *s)
{
    return 0;
}

/*
 * list_directory_members calls the given callback function handing it
 * the name of each file in given directory.
 */

typedef void directory_callback(char *, int, long int);

extern void list_directory_members(char *filename, char *old,
                                  size_t n, directory_callback *fn)
{
    return;
}

int scan_leafstart = 0;

/* end of sysipaq.c */
