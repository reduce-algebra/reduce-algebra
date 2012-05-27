/*  syscsl.h                      Copyright (C) 1992-2008 Codemist Ltd */

/*
 * This file should contain a list of all the functions in CSL that have
 * to be provided on a per-host basis.
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


/* Signature: 00c63f80 19-Jul-2009 */


#ifndef header_syscsl_h
#define header_syscsl_h 1

#ifdef __cplusplus
extern "C" {
#endif

/*
 * I provide a hook so that memory allocation can be passed not to the
 * usual C library malloc() function but to some other system-specific code.
 * This is achieved by putting the actual function that is to be called in
 * a variable. Ditto for free(). I have static initialisation that causes
 * use of the ordinary C library and so anybody who needs an alternative
 * must reset the pointers VERY early on.
 */

typedef void *malloc_function(size_t);

extern malloc_function *malloc_hook;

typedef void *realloc_function(void *, size_t);

extern realloc_function *realloc_hook;

typedef void free_function(void *);

extern free_function *free_hook;

/*
 * find_image_directory is handed the information that main() sees when
 * the application is started up, and it returns a string (in freshly
 * malloc'd space) that is the default name for the checkpoint image file
 * to be used for this run.
 */

extern char *find_image_directory(int argc, char *argv[]);

/*
 * process_file_name expands the old name into filename.
 */

extern void process_file_name(char *filename, char *old, size_t n);

/*
 * open_file accepts a vector of characters (old) and looks at the first
 * (n) of them.  This is taken as a CSL filename - it is subject (possibly)
 * to adjustments, the expanded name is copied to the array (filename) and an
 * attempt is made to open a file.  (mode) is a string (like "r", "w" or "r+b")
 * suitable for handing to the C "fopen" function to specify a mode, and
 * if (old_file) is non-NULL we should do an freopen() rather than fopen().
 * The main intent in filename conversion as supported here is to allow
 * users on all machines to use Unix-like file-names to at least some
 * minimal extent, so names like "subdir/file.lsp" should be allowed, even
 * if in native mode the computer used uses some quite different way of
 * specifying sub-directories and file-extensions.
 * If the first attempt to open a file with "w" mode fails I may try to
 * create any necessary directories on the way to it...
 */

extern FILE *open_file(char *filename, char *old, size_t n,
                       char *mode, FILE *old_file);

/*
 * find if a file exists, and if it does return (as 24 chars) the
 * change time for it.  See open_file re args.
 */

extern CSLbool file_exists(char *filename, char *old, size_t n, char *tt);

/*
 * The interfaces to create_directory and delete_file are similar
 * to that for open_file. They do what their names suggest! They return
 * zero on success, and non-zero on failure. Each does file-name
 * conversion so that Unix-style names can be used even with Windows.
 */

extern int create_directory(char *filename, char *old, size_t n);

extern int delete_file(char *filename, char *old, size_t n);

extern int rename_file(char *from_name, char *from_old, size_t from_size,
                       char *to_name,   char *to_old,   size_t to_size);

/*
 * The interfaces to file_readable and file_writable are also similar
 * to that for open_file.  They return 1 if their argument can be opened
 * for reading or writing respectively, and 0 otherwise.
 * WELL at present they test of the OWNER of the file could access it in
 * the specified manner...
 * directoryp tests whether its argument is a directory.
 */

extern int file_readable(char *filename, char *old, size_t n);

extern int file_writeable(char *filename, char *old, size_t n);

extern int file_executable(char *filename, char *old, size_t n);

extern int directoryp(char *filename, char *old, size_t n);

/*
 * file_length returns the length of its argument (a file) in bytes.
 */
extern long file_length(char *filename, char *old, size_t n);

/*
 * current_directory() places the name of the current directory in the buffer
 * which has the indicated size, and returns 0 for failure or otherwise
 * the length of data written.
 */
extern int current_directory(char *name, int len);

/*
 * The next three are much-like the same... On some operating systems
 * they will be pretty meaningless!
 */
extern int get_current_directory(char *name, int len);
extern int get_home_directory(char *name, int len);
extern int get_users_home_directory(char *name, int len);

/* returns NULL for OK or an error string */
extern char *change_directory(char *filename, char *old, size_t n);

/*
 * get_truename attempts to get a canonical name for a file or directory.
 * It returns a string. If unable to do anything useful it can just
 * return a copy of its input, but the result is expected to be a
 * freshly allocated block of memory and should be handed to free() after
 * it has been used. This interface using malloc() should be changed at
 * some stage so that the caller passes down a buffer for the result to
 * be placed in (what is arg1 for anyway).
 * This comment also needs to be expanded to explain in a little more detail
 * what a "canonical" name for a file or directory is - eg whether the
 * intent is to allow wildcard inputs or whether this function is
 * expected to convert from a relative file-name into a fully rooted one.
 *
 * It normally returns the "true name" but return NULL in error cases
 * and in that case leave filename an error string.
 */
extern char *get_truename(char *filename, char *old, size_t n);

#ifdef NAG_VERSION

/*
 * list_directory_members allocates (using malloc) both a vector
 * (of type char **) and a load of strings to go in there, and updates
 * filelist to point at it. The caller must free() the space at some
 * later stage.
 */

extern int list_directory_members(char *filename, char *old, char **filelist[],
                                  size_t n);

#else

/*
 * list_directory_members calls the given callback function handing it
 * the name of each file in given directory.
 */

typedef void directory_callback(char *, int, long int);

extern void list_directory_members(char *filename, char *old,
                                  size_t n, directory_callback *fn);

#endif

/*
 * (f) is an open file - truncate it at position (where).
 */
extern int truncate_file(FILE *f, long int where);

/*
 * If I am to process directories I need a set of routines that will
 * scan sub-directories for me. The specification I want is:
 *       int scan_directory(const char *dir,
 *                    void (*proc)(const char *name, int why, long int size));
 *
 * This is called with a file- or directory-name as its first argument
 * and a function as its second.
 * It calls the function for every directory and every file that can be found
 * rooted from the given place.  If the file to scan is specified as NULL
 * the current directory is processed.
 * When a simple file is found the procedure is called with the name of the
 * file, why=0, and the length (in bytes) of the file.  For a directory
 * the function is called with why=1, then the contents of the directory are
 * processed. For directories the size information will be 0.  There is no
 * guarantee of useful behaviour if some of the files to be scanned are
 * flagged as  "invisible" or "not readable" or if they are otherwise special.
 * The value returned is the number of characters that should be removed
 * the start of file-names returned to get rid of any initial directory
 * specified.  If dir is passed as NULL this will be zero and names will
 * come back plain, otherwise it will be 1+strlen(dir)
 */

extern void set_hostcase(int a);

#define SCAN_FILE       0
#define SCAN_STARTDIR   1
#define SCAN_ENDDIR     2

extern void scan_directory(const char *dir,
                           void (*proc)(const char *name, int why, long int size));

/*
 * When scan_directory calls the procedure it has been passed, it will have
 * set scan_leafstart to the offset in the passed filename where the
 * original directory ended and the new information starts. Thus if the
 * input string was (say) "/usr/users/acn/xxx" and some particular sub-file
 * was reported as "/usr/users/acn/xxx/subdir/subfile.ext" then
 * (name+scan_leafstart) gives the relative name "subdir/subfile.ext".
 */

extern int scan_leafstart;

/*
 * scan_files() is just like scan_directory() excepr that it does not
 * recurse into sub-directories.
 */

extern void scan_files(const char *dir,
                       void (*proc)(const char *name, int why, long int size));

extern void unpack_date(unsigned long int r,
                        int *year, int *mon, int *day,
                        int *hour, int *min, int *sec);

extern unsigned long int pack_date(int year, int mon, int day,
                                   int hour, int min, int sec);

typedef struct date_and_type
{
    unsigned long int date;
    unsigned long int type;
} date_and_type;

/* Reinstate date and filetype... */

extern void set_filedate(char *name, unsigned long int datestamp,
                                     unsigned long int ftype);

extern void put_fileinfo(date_and_type *p, char *name);

/*
 * my_getenv() is much like the ANSI getenv(), but exists because
 * it may be useful to perform mappings on the character string given
 * (e.g. to fold case) before calling the built-in getenv().
 */
extern char *my_getenv(char *s);

/*
 * my_system is just like the ANSI function system() - done this way to
 * allow for machines where this is not available or where more work is
 * needed.
 */

extern int my_system(char *s);

#if defined HAVE_POPEN || defined HAVE_FWIN
/*
 * my_popen() and my_pclose() are intended to be just like the Unix
 * popen() and pclose functions.
 */
extern FILE *my_popen(char *command_name, char *direction);
extern void my_pclose(FILE *stream);
#endif

#ifdef HAVE_FWIN
/*
 * For some systems I send characters to a pipe (possibly
 * only used to support the gnuplot package) through a separate
 * special function as documented here.
 */
extern int my_pipe_putc(int c, FILE *f);
extern int my_pipe_flush(FILE *f);

#else
#  define my_pipe_putc(c, f) putc(c, f)
#  define my_pipe_flush(f)   fflush(f)
#endif

/*
 * batchp() should return true if stdin is NOT from an interactive
 * terminal.
 */
extern int batchp(void);

/*
 * Ideally I will want the clock to report "user time" to me rather than
 * "elapsed time", since that will make recording benchmark info easier.
 */
extern clock_t read_clock(void);

#ifdef SHOW_COUNTS_AVAILABLE
/*
 * show_counts() can be called via mapstore(), and would be expected to
 * display some information relating to how many times each chunk of
 * C code has been executed - possibly only when the C coded parts of CSL have
 * been compiled with some special profile option.  write_profile is
 * similar in style, but sends output to a file.  If you do not have
 * statistics gathering facilities you do not need these implemented.
 */
extern void show_counts(void);
extern void write_profile(char *filename);

#endif

/*
 * Imultiply and Idivide are things that you may want to re-implement in
 * machine code - if so here are their signatures, and you should #define
 * IMULTIPLY/IDIVIDE in machine.h to say what you have done.  See arithXX.c
 * for the portable versions.
 */

#ifdef _MSC_VER
/*
 * Apologies here: For Microsoft VC++ I need to define these as __stdcall
 * (and certainly NOT as __fastcall) because Microsoft potentially change
 * which registers are used with __fastcall from release to release of
 * their compiler.
 */

#ifdef IMULTIPLY
extern uint32_t __stdcall Imultiply(uint32_t *rlow, uint32_t a,
                                      uint32_t b, uint32_t c);
#endif
#ifdef IDIVIDE
extern uint32_t __stdcall Idivide(uint32_t *qp, uint32_t a,
                                    uint32_t b, uint32_t c);
extern uint32_t __stdcall Idiv10_9(uint32_t *qp, uint32_t a, uint32_t b);
#endif

#else

#ifdef IMULTIPLY
extern uint32_t Imultiply(uint32_t *rlow, uint32_t a,
                            uint32_t b, uint32_t c);
#endif
#ifdef IDIVIDE
extern uint32_t Idivide(uint32_t *qp, uint32_t a,
                          uint32_t b, uint32_t c);
extern uint32_t Idiv10_9(uint32_t *qp, uint32_t a, uint32_t b);
#endif

#endif

/*
 * When the garbage collector observes that memory is tight it can attempt
 * to allocate more by going back to malloc(). This function is called with
 * an argument that indicates how many pages are in use at present, and it
 * is expected to return an indication of how many more might be worth
 * allocating. See the code in gc.c for details of usage.
 */
extern int32_t ok_to_grab_memory(int32_t current_pages);

/*
 * The following returns the number of processor cores that may be available.
 * If that information is not available it will return 1.
 */

extern int number_of_processors();

#ifdef WINDOW_SYSTEM
/*
 * The next represents the only way in which characters will be
 * sent to the screen - in the case of WINDOW_SYSTEM it write to the
 * screen.  Possibly this is more complicated than just writing to stdout.
 */
extern void putc_stdout(int c);
/*
 * flush_screen() tries to make sure that the display is up to date.
 */
extern void flush_screen(void);
/*
 * I may want to redirect stdout to a file, in which case the following
 * is the handle that I will use.  See "--" decoding in csl.c
 */
extern FILE *alternative_stdout;
/*
 * Ditto reading from stdin.  Reads chars into buffer, returns count.
 */
extern int wimpget(char *buf);
/*
 * I set this when wimpget sees an EOF.
 */
extern int terminal_eof_seen;
/*
 * The next two call-backs tell the window manager how much time has
 * been spent and how many garbage collections have been done.
 */
extern void report_time(int32_t t, int32_t gct);
extern void report_space(int gccount, double percent);
/*
 * pause_for_user() gets called right at the end to give a chance for the
 * system to delay before closing the main output window.
 */
extern void pause_for_user(void);
#endif

#ifdef __cplusplus
}
#endif

#endif /* header_syscsl_h */

/* end of syscsl.h */


