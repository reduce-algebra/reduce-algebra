/*  sys.h                       Copyright (C) 1992 Codemist Ltd */

/* Signature: 25331224 07-Mar-2000 */

/*
 * This file should contain a list of all the functions in CSL that have
 * to be provided on a per-host basis.
 */

#ifndef header_sys_h
#define header_sys_h 1

#ifdef __cplusplus
extern "C" {
#endif

/*
 * find_image_directory is handed the information that main() sees when
 * the application is started up, and it returns a string (in freshly
 * malloc'd space) that is the default name for the checkpoint image file
 * to be used for this run.
 */

extern char *find_image_directory(int argc, char *argv[]);

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
 * for reading or writing respectively, and 0 otherwise.  directoryp tests
 * whether its argument is a directory.
 */

extern int file_readable(char *filename, char *old, size_t n);

extern int file_writeable(char *filename, char *old, size_t n);

extern int directoryp(char *filename, char *old, size_t n);

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

extern int change_directory(char *filename, char *old, size_t n);

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
 *       int scan_directory(char *dir,
 *                    void (*proc)(char *name, int why, int32 size));
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

#define SCAN_FILE       0
#define SCAN_STARTDIR   1
#define SCAN_ENDDIR     2

extern void scan_directory(char *dir,
                           void (*proc)(char *name, int why, long int size));

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

extern void scan_files(char *dir,
                       void (*proc)(char *name, int why, long int size));

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

#ifdef PIPES
/*
 * my_popen() and my_pclose() are intended to be just like the Unix
 * popen() and pclose functions.
 */
extern FILE *my_popen(char *command_name, char *direction);
extern void my_pclose(FILE *stream);
#endif

#ifdef SIMULATED_PIPES
/*
 * For RISCOS (at least) I send characters to a pipe (possibly
 * only used to support the gnuplot package) through a separate
 * special function as documented here.
 */
extern int my_pipe_putc(int c, FILE *f);
extern int my_pipe_flush(FILE *f);

#else
#  define my_pipe_putc(c, f) putc(c, f)
#  define my_pipe_flush(f)   fflush(f)
#endif


#ifdef PIPES_SOMETIMES
/*
 * If I have an operating system where the presence of pipes is
 * conditional, this variable is used to keep track.
 */
extern int pipes_today;
#endif

/*
 * batchp() should return true if stdin is NOT from an interactive
 * terminal.
 */
extern int batchp(void);

#ifdef UNIX_TIMES
/*
 * The intent here is that if UNIX_TIMES is set then the CPU times
 * reported to the user will be "user time" and will not include
 * "system time", as in using the Unix "times" facility.  If UNIX_TIMES
 * is not defined no special code in sysxxx.c is needed.
 */
extern clock_t read_clock(void);

#else
#  define read_clock() clock()
#endif

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
extern unsigned32 __stdcall Imultiply(unsigned32 *rlow, unsigned32 a,
                                      unsigned32 b, unsigned32 c);
#endif
#ifdef IDIVIDE
extern unsigned32 __stdcall Idivide(unsigned32 *qp, unsigned32 a,
                                    unsigned32 b, unsigned32 c);
extern unsigned32 __stdcall Idiv10_9(unsigned32 *qp, unsigned32 a, unsigned32 b);
#endif

#else

#ifdef IMULTIPLY
extern unsigned32 Imultiply(unsigned32 *rlow, unsigned32 a,
                            unsigned32 b, unsigned32 c);
#endif
#ifdef IDIVIDE
extern unsigned32 Idivide(unsigned32 *qp, unsigned32 a,
                          unsigned32 b, unsigned32 c);
extern unsigned32 Idiv10_9(unsigned32 *qp, unsigned32 a, unsigned32 b);
#endif

#endif
#ifdef TICK_STREAM
/*
 * add_ticker() starts a steady(-ish) stream of clock pulses going,
 * and causes (indirectly) accept_tick() to be called in a regular basis.
 * These are used to help me with interfaces to window systems, and to
 * make responses to keyboard interrupts more friendly and reliable.
 */
extern void add_ticker(void);
/*
 * remove_ticker() switches tick-events off.  Best if it is legal to
 * call remove_ticker even if ticks are not active.
 */
extern void MS_CDECL remove_ticker(void);

extern void accept_tick(void);

#endif

#ifdef POLL_FOR_ATTN
/*
 * Used by MSDOS system to check if ^C has been pressed - see gc.c
 * and read.c for the only calls.  Arg decides if it waits until some
 * input is ready.
 */
extern void poll_for_attn(void);

#endif

/*
 * When the garbage collector observes that memory is tight it can attempt
 * to allocate more by going back to malloc(). This function is called with
 * an argument that indicates how many pages are in use at present, and it
 * is expected to return an indication of how many more might be worth
 * allocating. See the code in gc.c for details of usage.
 */
int32 ok_to_grab_memory(int32 current_pages);

#ifdef WINDOW_SYSTEM
/*
 * start_up_window_manager is called after command-line options have been
 * decoded - and hence after any flags that might influence the character
 * of windowed use of the system have been set.
 */
extern void start_up_window_manager(int use_wimp);
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
 * The next two call-backs tell the window manager how much time has
 * been spent and how many garbage collections have been done.
 */
extern void report_time(int32 t, int32 gct);
extern void report_space(int gccount, double percent);
/*
 * pause_for_user() gets called right at the end to give a chance for the
 * system to delay before closing the main output window.
 */
extern void pause_for_user(void);
#endif

#ifdef WINDOWS_NT
/*
 * Am I in Win32S rather than full Win32?
 * The values I will use will be
 *     0     Windows NT
 *     1     win32s on top of Windows 3.x
 *     2     Windows 95
 */
extern int win32s;
#endif

#ifdef __cplusplus
}
#endif

#endif /* header_sys_h */

/* end of sys.h */


