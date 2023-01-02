//  syscsl.h                               Copyright (C) 1992-2023 Codemist

//
// This file should contain a list of all the functions in CSL that have
// to be provided on a per-host basis.
//


/**************************************************************************
 * Copyright (C) 2023, Codemist.                         A C Norman       *
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


#ifndef header_syscsl_h
#define header_syscsl_h 1

//
// find_image_directory is handed the information that main() sees when
// the application is started up, and it returns a string (in freshly
// allocated space) that is the default name for the checkpoint image file
// to be used for this run.
//

extern const char *find_image_directory(int argc, const char *argv[]);

//
// process_file_name expands the old name into filename. Its job is to
// turn the sorts of names that CSL accepts into things suitable to
// pass down to C++. It can expand an initial "$xxx" based on the value of
// and environent variable called "xxx" or a Lisp variable called "$xxx" or
// "@xxx". It knowsn about paths liuke "~/xxx" and expands the "~" to the
// users home directory. On or for cygwin it may do things with an initial
// "/cygpath/X/" in its input.
//

extern void process_file_name(char *filename, const char *old,
                              size_t n);

//
// open_file accepts a vector of characters (old) and looks at the first
// (n) of them.  This is taken as a CSL filename - it is subject (possibly)
// to adjustments, the expanded name is copied to the array (filename) and an
// attempt is made to open a file.  (mode) is a string (like "r", "w" or
// "r+b") suitable for handing to the C "fopen" function to specify a mode,
// and if (old_file) is not nullptr we should do an freopen() rather than
// fopen().
// The main intent in filename conversion as supported here is to allow
// users on all machines to use Unix-like file-names to at least some
// minimal extent, so names like "subdir/file.lsp" should be allowed, even
// if in native mode the computer used uses some quite different way of
// specifying sub-directories and file-extensions.
// If the first attempt to open a file with "w" mode fails I may try to
// create any necessary directories on the way to it...
//

extern std::FILE *open_file(char *filename, const char *old, size_t n,
                            const char *mode, std::FILE *old_file);

//
// find if a file exists, and if it does return (as 24 chars) the
// change time for it.  See open_file re args.
//

extern bool file_exists(char *filename, const char *old, size_t n,
                        char *tt);

//
// The interfaces to create_directory and delete_file are similar
// to that for open_file. They do what their names suggest! They return
// zero on success, and non-zero on failure. Each does file-name
// conversion so that Unix-style names can be used even with Windows.
// delete_wildcard "globs" its argument and deletes all files that
// match... but I would not at present give any guarantees about how it
// behaves if the argument indicates directories etc, eg case like
//    "./top*/*mid*/*lower.x"
// make me feel queasy! Giving a simple file name with a wildcard
// such as "tempfile*.log" should be safe!
//

extern int create_directory(char *filename, const char *old,
                            size_t n);

extern int delete_file(char *filename, const char *old, size_t n);

extern int delete_wildcard(char *filename, const char *old, size_t n);

extern int rename_file(char *from_name, const char *from_old,
                       size_t from_size,
                       char *to_name, const char *to_old, size_t to_size);

//
// The interfaces to file_readable and file_writable are also similar
// to that for open_file.  They return 1 if their argument can be opened
// for reading or writing respectively, and 0 otherwise.
// WELL at present they test of the OWNER of the file could access it in
// the specified manner...
// directoryp tests whether its argument is a directory.
//

extern bool file_readable(char *filename, const char *old, size_t n);

extern bool file_writeable(char *filename, const char *old, size_t n);

extern bool file_executable(char *filename, const char *old,
                            size_t n);

extern bool directoryp(char *filename, const char *old, size_t n);

//
// file_length returns the length of its argument (a file) in bytes.
//
extern int64_t file_length(char *filename, const char *old, size_t n);

//
// current_directory() places the name of the current directory in the buffer
// which has the indicated size, and returns 0 for failure or otherwise
// the length of data written.
//
extern int current_directory(char *name, int len);

//
// The next three are much-like the same... On some operating systems
// they will be pretty meaningless!
//
extern int get_current_directory(char *name, size_t len);
extern int get_home_directory(char *name, size_t len);
extern int get_users_home_directory(char *name, size_t len);

//
// Just for Reduce, find_gnuplot fills in the command to launch gnuplot
// into the character array it is given. On Windows this may end up
// something like "c:\Program Files (x86)\...\wgnuplot.exe" while on
// other systems it could be either a fully rooted path of just "gnuplot".
//
extern int find_gnuplot(char *name);

// returns nullptr for OK or an error string
extern char *change_directory(char *filename, const char *old,
                              size_t n);

//
// get_truename attempts to get a canonical name for a file or directory.
// It returns a string. If unable to do anything useful it can just
// return a copy of its input, but the result is expected to be a
// freshly allocated block of memory and should be handed to "delete" after
// it has been used. This interface using "new" should be changed at
// some stage so that the caller passes down a buffer for the result to
// be placed in (what is arg1 for anyway).
// This comment also needs to be expanded to explain in a little more detail
// what a "canonical" name for a file or directory is - eg whether the
// intent is to allow wildcard inputs or whether this function is
// expected to convert from a relative file-name into a fully rooted one.
//
// It normally returns the "true name" but return nullptr in error cases
// and in that case leave filename an error string.
//
extern char *get_truename(char *filename, const char *old, size_t n);

// list_directory_members calls the given callback function handing it
// the name of each file in given directory.

typedef void filescan_function(string name, string leafname,
                               int why, long int size);

extern void list_directory_members(char *filename, const char *old,
                                   size_t n, filescan_function *fn);

//
// (f) is an open file - truncate it at position (where).
//
extern int truncate_file(std::FILE *f, long int where);

//
// If I am to process directories I need a set of routines that will
// scan sub-directories for me. The specification I want is:
//       void scan_directory(string dir, filescan_function *proc);
//
// This is called with a file- or directory-name as its first argument
// and a function as its second.
// It calls the function for every directory and every file that can be found
// rooted from the given place.
// When a simple file is found the procedure is called with the name of the
// file, why=0, and the length (in bytes) of the file.  For a directory
// the function is called with why=1.
// There is no guarantee of useful behaviour if some of the files to be
// scanned are flagged as  "invisible" or "not readable" or if they are
// otherwise special. Files are not processed in alphabetic order based
// on their full name (ie if the input argument is "ddd" then the "full
// name of some file could be "ddd/subdir/somefile.ext".
//

extern void set_hostcase(int a);

#define SCAN_FILE       0
#define SCAN_DIR        1

extern void scan_directory(string dir, filescan_function *proc);

//
// scan_files() is just like scan_directory() excepr that it does not
// recurse into sub-directories.
//

extern void scan_files(string dir, filescan_function *proc);

extern void unpack_date(unsigned long int r,
                        int *year, int *mon, int *day,
                        int *hour, int *min, int *sec);

extern unsigned long int pack_date(int year, int mon, int day,
                                   int hour, int min, int sec);

//
// my_getenv() is much like the ANSI getenv(), but exists because
// it may be useful to perform mappings on the character string given
// (e.g. to fold case) before calling the built-in getenv().
//
extern const char *my_getenv(const char *s);

//
// my_system is just like the ANSI function system() - done this way to
// allow for machines where this is not available or where more work is
// needed.
//

extern int my_system(const char *s);

//
// my_popen() and my_pclose() are intended to be just like the Unix
// popen() and pclose functions.
//
extern std::FILE *my_popen(const char *command_name,
                           const char *direction);
extern void my_pclose(std::FILE *stream);

//
// For some systems I send characters to a pipe (possibly
// only used to support the gnuplot package) through a separate
// special function as documented here.
//
extern int my_pipe_putc(int c, std::FILE *f);
extern int my_pipe_flush(std::FILE *f);

//
// batchp() should return true if stdin is NOT from an interactive
// terminal.
//
extern int batchp(void);

//
// Ideally I will want the clock to report "user time" to me rather than
// "elapsed time", since that will make recording benchmark info easier.
//
extern uint64_t read_clock(void);

#ifdef SHOW_COUNTS_AVAILABLE
//
// show_counts() can be called via mapstore(), and would be expected to
// display some information relating to how many times each chunk of
// C code has been executed - possibly only when the C coded parts of CSL have
// been compiled with some special profile option.  write_profile is
// similar in style, but sends output to a file.  If you do not have
// statistics gathering facilities you do not need these implemented.
//
extern void show_counts(void);
extern void write_profile(const char *filename);

#endif // SHOW_COUNTS_AVAILABLE

extern uint32_t Imultiply(uint32_t *rlow, uint32_t a,
                          uint32_t b, uint32_t c);
extern uint32_t Idivide(uint32_t *qp, uint32_t a,
                        uint32_t b, uint32_t c);
extern uint32_t Idiv10_9(uint32_t *qp, uint32_t a, uint32_t b);

//
// When the garbage collector observes that memory is tight it can attempt
// to allocate more by going back to "new". This function is called with
// an argument that indicates how many pages are in use at present, and it
// is expected to return an indication of how many more might be worth
// allocating. See the code in csl[new]gc.c for details of usage.
//
extern int32_t ok_to_grab_memory(int32_t current_pages);

//
// The following returns the number of processor cores that may be available.
// If that information is not available it will return 1. The information is
// a "hint" not definitive!
//
extern unsigned int number_of_processors();

//
// The next represents the only way in which characters will be
// sent to the screen - in the case of WITHOUT_GUI it probably does
// just write to stdout, but if !WITHOUT_GUI there may be a GUI active
// and it may be writing to the screen, with whatever extra complication
// that entails.
//
extern void putc_stdout(int c);
//
// flush_screen() tries to make sure that the display is up to date.
//
extern void flush_screen(void);
//
// I may want to redirect stdout to a file, in which case the following
// is the handle that I will use.  See "--" decoding in csl.c
//
extern std::FILE *alternative_stdout;
//
// Ditto reading from stdin.  Reads chars into buffer, returns count.
//
extern int wimpget(char *buf);
//
// I set this when wimpget sees an EOF.
//
extern int terminal_eof_seen;
//
// The next two call-backs tell the window manager how much time has
// been spent and how many garbage collections have been done.
//
extern void report_time(int32_t t, int32_t gct);
extern void report_space(uint64_t gccount, double percent,
                         double mbytes);

// These can be used (without 100% reliability!) to check if memory
// addresses are proper. They are only for use in desparate debugging
// situations where some invalid data might arise where a pointer is
// expected and by using these the issue can be detected early and
// the debugging information available may therefore be nicer that that
// which would have been encountered if the wild pseudo-pointer had been
// left and only detected when dereferenced.

extern bool valid_address(void *p);
extern bool valid_address(uintptr_t p);

#endif // header_syscsl_h

// end of syscsl.h
