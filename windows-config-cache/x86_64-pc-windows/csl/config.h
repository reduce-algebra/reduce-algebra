/* config.h.  Generated from config.h.in by configure.  */
/* config.h.in.  Generated from configure.ac by autoheader.  */

/* Work on a transition to use of arithlib.hpp for bignums */
/* #undef ARITHLIB */

/* disable parallel Karatsuba */
/* #undef AVOID_KARATSUBA_THREADS */

/* disable input local editing */
/* #undef AVOID_TERMINAL_THREADS */

/* Architecture this is built to run on */
#define BUILTFOR "x86_64-pc-windows"

/* Define to 1 if the 'closedir' function returns void instead of int. */
/* #undef CLOSEDIR_VOID */

/* new GC is now always used! */
#define CONSERVATIVE 1

/* Collect counts of multiplication */
/* #undef COUNT_MULTIPLICATION */

/* True to tell sources that this build is part of CSL */
#define CSL 1

/* True if this is with no GUI and aimed at embedded use */
/* #undef EMBEDDED */

/* For use by developers */
/* #undef EXPERIMENT */

/* Show down garbage collection dramatically */
/* #undef EXTREME_DEBUG */

/* "std::filesystem not available" */
/* #undef FILESYSTEM_NOT_USABLE */

/* Define to 1 if you have the <arpa/inet.h> header file. */
/* #undef HAVE_ARPA_INET_H */

/* Define to 1 if you have the 'atexit' function. */
#define HAVE_ATEXIT 1

/* Define to 1 if you have the 'at_quick_exit' function. */
/* #undef HAVE_AT_QUICK_EXIT */

/* bit_cast<T>() available */
#define HAVE_BITCAST 1

/* Define to 1 if you have the 'cfmakeraw' function. */
/* #undef HAVE_CFMAKERAW */

/* Define to 1 if you have the 'clock_gettime' function. */
#define HAVE_CLOCK_GETTIME 1

/* Define to 1 if you have the <complex.h> header file. */
#define HAVE_COMPLEX_H 1

/* Correct Rounding maths library should be used */
#define HAVE_CRLIBM 1

/* Define to 1 if you have the 'csqrt' function. */
#define HAVE_CSQRT 1

/* Define to 1 if you have the <cstdio> header file. */
#define HAVE_CSTDIO 1

/* Define to 1 if you have the <curses.h> header file. */
/* #undef HAVE_CURSES_H */

/* define if the compiler supports basic C++11 syntax */
/* #undef HAVE_CXX11 */

/* define if the compiler supports basic C++14 syntax */
/* #undef HAVE_CXX14 */

/* define if the compiler supports basic C++17 syntax */
/* #undef HAVE_CXX17 */

/* define if the compiler supports basic C++20 syntax */
#define HAVE_CXX20 1

/* Define to 1 if you have the declaration of 'RLIM_SAVED_CUR', and to 0 if
   you don't. */
/* #undef HAVE_DECL_RLIM_SAVED_CUR */

/* Define to 1 if you have the declaration of 'RLIM_SAVED_MAX', and to 0 if
   you don't. */
/* #undef HAVE_DECL_RLIM_SAVED_MAX */

/* Define to 1 if you have the <dirent.h> header file, and it defines 'DIR'.
   */
#define HAVE_DIRENT_H 1

/* Define to 1 if you have the <dlfcn.h> header file. */
/* #undef HAVE_DLFCN_H */

/* Define to 1 if you don't have 'vprintf' but do have '_doprnt.' */
/* #undef HAVE_DOPRNT */

/* Define to 1 if you have the <fcntl.h> header file. */
#define HAVE_FCNTL_H 1

/* Define to 1 if you have the <float.h> header file. */
#define HAVE_FLOAT_H 1

/* Define to 1 if you have the 'fork' function. */
/* #undef HAVE_FORK */

/* Define to 1 if you have the 'ftruncate' function. */
#define HAVE_FTRUNCATE 1

/* Define to 1 if you have the 'getcwd' function. */
#define HAVE_GETCWD 1

/* Define to 1 if you have the 'getc_unlocked' function. */
/* #undef HAVE_GETC_UNLOCKED */

/* Define to 1 if you have the 'gethostbyaddr' function. */
/* #undef HAVE_GETHOSTBYADDR */

/* Define to 1 if you have the 'gethostbyname' function. */
/* #undef HAVE_GETHOSTBYNAME */

/* Define to 1 if you have the 'getrlimit' function. */
/* #undef HAVE_GETRLIMIT */

/* Define to 1 if you have the 'gettimeofday' function. */
#define HAVE_GETTIMEOFDAY 1

/* Define to 1 if you have the 'inet_ntoa' function. */
/* #undef HAVE_INET_NTOA */

/* Define to 1 if the system has the type 'int128_t'. */
/* #undef HAVE_INT128_T */

/* Define to 1 if you have the <inttypes.h> header file. */
#define HAVE_INTTYPES_H 1

/* Define to 1 if you have the 'fontconfig' library (-lfontconfig). */
/* #undef HAVE_LIBFONTCONFIG */

/* Fox library present */
#define HAVE_LIBFOX 1

/* wxWidgets library will be used */
/* #undef HAVE_LIBWX */

/* True Xft is available */
/* #undef HAVE_LIBXFT */

/* Define to 1 if 'lstat' has the bug that it succeeds when given the
   zero-length file name argument. */
#define HAVE_LSTAT_EMPTY_STRING_BUG 1

/* Define to 1 if you have the <malloc.h> header file. */
#define HAVE_MALLOC_H 1

/* Define to 1 if you have the 'memmove' function. */
#define HAVE_MEMMOVE 1

/* Define to 1 if you have the <memory.h> header file. */
#define HAVE_MEMORY_H 1

/* Define to 1 if you have the 'memset' function. */
#define HAVE_MEMSET 1

/* Define to 1 if you have the 'mkdir' function. */
#define HAVE_MKDIR 1

/* Define to 1 if you have the <ncurses.h> header file. */
/* #undef HAVE_NCURSES_H */

/* Define to 1 if you have the <ncurses/term.h> header file. */
/* #undef HAVE_NCURSES_TERM_H */

/* Define to 1 if you have the <ndir.h> header file, and it defines 'DIR'. */
/* #undef HAVE_NDIR_H */

/* Define to 1 if you have the <netdb.h> header file. */
/* #undef HAVE_NETDB_H */

/* Define to 1 if you have the <netinet/in.h> header file. */
/* #undef HAVE_NETINET_IN_H */

/* Define to 1 if you have the 'popen' function. */
#define HAVE_POPEN 1

/* Define to 1 if you have the 'pow' function. */
#define HAVE_POW 1

/* Define to 1 if you have the 'putc_unlocked' function. */
/* #undef HAVE_PUTC_UNLOCKED */

/* Define to 1 if you have the 'quick_exit' function. */
/* #undef HAVE_QUICK_EXIT */

/* Define to 1 if you have the 'rmdir' function. */
#define HAVE_RMDIR 1

/* Define to 1 if you have the <sched.h> header file. */
#define HAVE_SCHED_H 1

/* Define to 1 if you have the <setjmp.h> header file. */
#define HAVE_SETJMP_H 1

/* Define to 1 if you have the 'shmat' function. */
/* #undef HAVE_SHMAT */

/* Define to 1 if you have the 'shmctl' function. */
/* #undef HAVE_SHMCTL */

/* Define to 1 if you have the 'shmdt' function. */
/* #undef HAVE_SHMDT */

/* Define to 1 if you have the 'shmget' function. */
/* #undef HAVE_SHMGET */

/* Define to 1 if you have the 'sigaction' function. */
/* #undef HAVE_SIGACTION */

/* Define to 1 if you have the 'sigaltstack' function. */
/* #undef HAVE_SIGALTSTACK */

/* Define to 1 if you have the 'siglongjmp' function. */
/* #undef HAVE_SIGLONGJMP */

/* Define to 1 if you have the <signal.h> header file. */
#define HAVE_SIGNAL_H 1

/* Define to 1 if you have the 'signbit' function. */
#define HAVE_SIGNBIT 1

/* Define to 1 if you have the 'socket' function. */
/* #undef HAVE_SOCKET */

/* support for 128-bit long double/float128_t */
#define HAVE_SOFTFLOAT 1

/* Define to 1 if you have the 'sqrt' function. */
#define HAVE_SQRT 1

/* Define to 1 if 'stat' has the bug that it succeeds when given the
   zero-length file name argument. */
/* #undef HAVE_STAT_EMPTY_STRING_BUG */

/* Define to 1 if you have the <stddef.h> header file. */
#define HAVE_STDDEF_H 1

/* Define to 1 if you have the <stdint.h> header file. */
#define HAVE_STDINT_H 1

/* Define to 1 if you have the <stdio.h> header file. */
#define HAVE_STDIO_H 1

/* Define to 1 if you have the <stdlib.h> header file. */
#define HAVE_STDLIB_H 1

/* Define to 1 if you have the 'strchr' function. */
#define HAVE_STRCHR 1

/* Define to 1 if you have the 'strdup' function. */
#define HAVE_STRDUP 1

/* Define to 1 if you have the <strings.h> header file. */
#define HAVE_STRINGS_H 1

/* Define to 1 if you have the <string.h> header file. */
#define HAVE_STRING_H 1

/* Define to 1 if you have the 'strrchr' function. */
#define HAVE_STRRCHR 1

/* Define to 1 if you have the 'strstr' function. */
#define HAVE_STRSTR 1

/* Define to 1 if you have the <syscall.h> header file. */
/* #undef HAVE_SYSCALL_H */

/* Define to 1 if you have the 'sysctlbyname' function. */
/* #undef HAVE_SYSCTLBYNAME */

/* Define to 1 if you have the <sys/dir.h> header file, and it defines 'DIR'.
   */
/* #undef HAVE_SYS_DIR_H */

/* Define to 1 if you have the <sys/ioctl.h> header file. */
/* #undef HAVE_SYS_IOCTL_H */

/* Define to 1 if you have the <sys/ipc.h> header file. */
/* #undef HAVE_SYS_IPC_H */

/* Define to 1 if you have the <sys/ndir.h> header file, and it defines 'DIR'.
   */
/* #undef HAVE_SYS_NDIR_H */

/* Define to 1 if you have the <sys/param.h> header file. */
#define HAVE_SYS_PARAM_H 1

/* Define to 1 if you have the <sys/resource.h> header file. */
/* #undef HAVE_SYS_RESOURCE_H */

/* Define to 1 if you have the <sys/shm.h> header file. */
/* #undef HAVE_SYS_SHM_H */

/* Define to 1 if you have the <sys/socket.h> header file. */
/* #undef HAVE_SYS_SOCKET_H */

/* Define to 1 if you have the <sys/stat.h> header file. */
#define HAVE_SYS_STAT_H 1

/* Define to 1 if you have the <sys/sysctl.h> header file. */
/* #undef HAVE_SYS_SYSCTL_H */

/* Define to 1 if you have the <sys/times.h> header file. */
/* #undef HAVE_SYS_TIMES_H */

/* Define to 1 if you have the <sys/time.h> header file. */
#define HAVE_SYS_TIME_H 1

/* Define to 1 if you have the <sys/types.h> header file. */
#define HAVE_SYS_TYPES_H 1

/* Define to 1 if you have the <sys/wait.h> header file. */
/* #undef HAVE_SYS_WAIT_H */

/* Define to 1 if you have the <termios.h> header file. */
/* #undef HAVE_TERMIOS_H */

/* Define to 1 if you have the <term.h> header file. */
/* #undef HAVE_TERM_H */

/* Define to 1 if you have the 'tgetent' function. */
/* #undef HAVE_TGETENT */

/* Define to 1 if you have the 'times' function. */
/* #undef HAVE_TIMES */

/* std::timespec present */
#define HAVE_TIMESPEC 1

/* Define to 1 if you have the <time.h> header file. */
#define HAVE_TIME_H 1

/* Define to 1 if you have the 'tputs' function. */
/* #undef HAVE_TPUTS */

/* Define to 1 if the system has the type 'uint128_t'. */
/* #undef HAVE_UINT128_T */

/* Define to 1 if you have the <unistd.h> header file. */
#define HAVE_UNISTD_H 1

/* Define to 1 if the system has the type 'unsigned __int128'. */
#define HAVE_UNSIGNED___INT128 1

/* Define to 1 if you have the 'utime' function. */
#define HAVE_UTIME 1

/* Define to 1 if you have the <utime.h> header file. */
#define HAVE_UTIME_H 1

/* Define to 1 if 'utime(file, NULL)' sets file's timestamp to the present. */
#define HAVE_UTIME_NULL 1

/* Define to 1 if you have the 'vprintf' function. */
#define HAVE_VPRINTF 1

/* Define to 1 if you have the 'vsnprintf' function. */
#define HAVE_VSNPRINTF 1

/* Define to 1 if you have the 'wait' function. */
/* #undef HAVE_WAIT */

/* Define to 1 if you have the 'waitpid' function. */
/* #undef HAVE_WAITPID */

/* Define to 1 if you have the <zlib.h> header file. */
#define HAVE_ZLIB_H 1

/* Define to 1 if you have the '_Exit' function. */
#define HAVE__EXIT 1

/* Define to 1 if you have the '_getc_nolock' function. */
#define HAVE__GETC_NOLOCK 1

/* Define to 1 if you have the '_putc_nolock' function. */
#define HAVE__PUTC_NOLOCK 1

/* Define to 1 if the compiler support __builtin_clz. */
#define HAVE___BUILTIN_CLZ 1

/* Define to 1 if the compiler support __builtin_ctz. */
#define HAVE___BUILTIN_CTZ 1

/* Define to 1 if the system has the type '__int128'. */
#define HAVE___INT128 1

/* Name of CPU */
#define HOST_CPU "x86_64"

/* Name of Operating System */
#define HOST_OS "mingw32"

/* Name of vendor */
#define HOST_VENDOR "w64"

/* Define to 1 if 'lstat' dereferences a symlink specified with a trailing
   slash. */
/* #undef LSTAT_FOLLOWS_SLASHED_SYMLINK */

/* Define to the sub-directory where libtool stores uninstalled libraries. */
#define LT_OBJDIR ".libs/"

/* True if we are running on Macintosh */
/* #undef MACINTOSH */

/* Apple MacOS frameworks available */
/* #undef MAC_FRAMEWORK */

/* Smaller pages for the heap */
/* #undef MINIPAGE */

/* Avoid use of thread_local and other thread support */
#define NO_THREADS 1

/* Avoid use of catch and throw */
/* #undef NO_THROW */

/* Name of package */
#define PACKAGE "reduce"

/* Define to the address where bug reports for this package should be sent. */
#define PACKAGE_BUGREPORT ""

/* Define to the full name of this package. */
#define PACKAGE_NAME "REDUCE"

/* Define to the full name and version of this package. */
#define PACKAGE_STRING "REDUCE 9.01"

/* Define to the one symbol short name of this package. */
#define PACKAGE_TARNAME "reduce"

/* Define to the home page for this package. */
#define PACKAGE_URL ""

/* Define to the version of this package. */
#define PACKAGE_VERSION "9.01"

/* Show where a matching PSL might live */
#define PSLBUILD ""

/* True if we are running on RAW Cygwin */
/* #undef RAW_CYGWIN */

/* Not guaranteed by ANSI spec */
#define SIGNED_SHIFTS_ARE_ARITHMETIC 1

/* The size of 'wchar_t', as computed by sizeof. */
#define SIZEOF_WCHAR_T 2

/* True if we are running on Solaris */
/* #undef SOLARIS */

/* Define to 1 if the 'S_IS*' macros in <sys/stat.h> do not work properly. */
/* #undef STAT_MACROS_BROKEN */

/* Define to 1 if all of the C89 standard headers exist (not just the ones
   required in a freestanding environment). This macro is provided for
   backward compatibility; new code need not use it. */
#define STDC_HEADERS 1

/* For use by developers */
/* #undef TEST */

/* Define to 1 if your <sys/time.h> declares 'struct tm'. */
/* #undef TM_IN_SYS_TIME */

/* True if EQUAL should be profiled */
/* #undef TRACED_EQUAL */

/* True if we are running on Unix, Linux, BSD etc */
/* #undef UNIX */

/* Version number of package */
#define VERSION "9.01"

/* True if we are running on Windows */
#define WIN32 1

/* True if we are running on Windows (64 bit) */
#define WIN64 1

/* True for a (potentially) Windowed system */
#define WINDOW_SYSTEM 1

/* remove the foreign function support */
/* #undef WITHOUT_FFI */

/* Not even an attempt at support for GUI */
/* #undef WITHOUT_GUI */

/* True if Intel or AMD (64-bit only these days) */
#define X86 1

/* Define to empty if 'const' does not conform to ANSI C. */
/* #undef const */

/* Define to empty if the keyword 'volatile' does not work. Warning: valid
   code using 'volatile' can become incorrect without. Disable with care. */
/* #undef volatile */
