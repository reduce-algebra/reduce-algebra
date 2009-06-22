// This is a rather small sample X program that is here
// just to let me verify that I can compile something. When I
// was first writing it I looked on the web and in the X11 documentation
// and the most helpful code snippet I found was on www.rosettacode.org.
// The code here may have moved on far enough that it is not merely a copy
// of what I found there, but I will still express my thanks here!

// I think that "Hello World" scale programs perhaps berely need explicit
// licenses, since their contents are so much defined by the requirement of
// functionality. however anything I have put here I make available to others
// under the modified BSD license.

//                                         Arthur Norman, April 2009


#include <stdio.h>

#ifdef HAVE_CONFIG_H
#include "config.h"
#else
#error This file needs "config.h"
#endif


#include "libwindow.h"

int main(int argc, char *argv[])
{
    showwindow();
    return 0;
}


/*
 * The bit that follows is to check that the headers and functions I
 * expected to find were in fact found!
 */

#ifdef WIN32

#ifndef HAVE_ATEXIT
#error expected to have HAVE_ATEXIT
#endif

#ifndef HAVE_DIRENT_H
#error expected to have HAVE_DIRENT_H
#endif

#ifndef HAVE_DLFCN_H
#error expected to have HAVE_DLFCN_H
#endif

#ifndef HAVE_FCNTL_H
#error expected to have HAVE_FCNTL_H
#endif

#ifndef HAVE_FLOAT_H
#error expected to have HAVE_FLOAT_H
#endif

#ifndef HAVE_FTRUNCATE
#error expected to have HAVE_FTRUNCATE
#endif

#ifndef HAVE_GETCWD
#error expected to have HAVE_GETCWD
#endif

#ifndef HAVE_INT16_T
#error expected to have HAVE_INT16_T
#endif

#ifndef HAVE_INT32_T
#error expected to have HAVE_INT32_T
#endif

#ifndef HAVE_INT64_T
#error expected to have HAVE_INT64_T
#endif

#ifndef HAVE_INT8_T
#error expected to have HAVE_INT8_T
#endif

#ifndef HAVE_INTPTR_T
#error expected to have HAVE_INTPTR_T
#endif

#ifndef HAVE_INTTYPES_H
#error expected to have HAVE_INTTYPES_H
#endif

#ifndef HAVE_LIBPTHREAD
#error expected to have HAVE_LIBPTHREAD
#endif

#ifndef HAVE_LSTAT_EMPTY_STRING_BUG
#error expected to have HAVE_LSTAT_EMPTY_STRING_BUG
#endif

#ifndef HAVE_MALLOC_H
#error expected to have HAVE_MALLOC_H
#endif

#ifndef HAVE_MEMMOVE
#error expected to have HAVE_MEMMOVE
#endif

#ifndef HAVE_MEMORY_H
#error expected to have HAVE_MEMORY_H
#endif

#ifndef HAVE_MEMSET
#error expected to have HAVE_MEMSET
#endif

#ifndef HAVE_MKDIR
#error expected to have HAVE_MKDIR
#endif

#ifndef HAVE_POPEN
#error expected to have HAVE_POPEN
#endif

#ifndef HAVE_POW
#error expected to have HAVE_POW
#endif

#ifndef HAVE_RMDIR
#error expected to have HAVE_RMDIR
#endif

#ifndef HAVE_SIGNAL_H
#error expected to have HAVE_SIGNAL_H
#endif

#ifndef HAVE_SQRT
#error expected to have HAVE_SQRT
#endif

#ifndef HAVE_STDDEF_H
#error expected to have HAVE_STDDEF_H
#endif

#ifndef HAVE_STDINT_H
#error expected to have HAVE_STDINT_H
#endif

#ifndef HAVE_STDLIB_H
#error expected to have HAVE_STDLIB_H
#endif

#ifndef HAVE_STRCHR
#error expected to have HAVE_STRCHR
#endif

#ifndef HAVE_STRDUP
#error expected to have HAVE_STRDUP
#endif

#ifndef HAVE_STRINGS_H
#error expected to have HAVE_STRINGS_H
#endif

#ifndef HAVE_STRING_H
#error expected to have HAVE_STRING_H
#endif

#ifndef HAVE_STRRCHR
#error expected to have HAVE_STRRCHR
#endif

#ifndef HAVE_STRSTR
#error expected to have HAVE_STRSTR
#endif

#ifndef HAVE_SYS_PARAM_H
#error expected to have HAVE_SYS_PARAM_H
#endif

#ifndef HAVE_SYS_STAT_H
#error expected to have HAVE_SYS_STAT_H
#endif

#ifndef HAVE_SYS_TIME_H
#error expected to have HAVE_SYS_TIME_H
#endif

#ifndef HAVE_SYS_TYPES_H
#error expected to have HAVE_SYS_TYPES_H
#endif

#ifndef HAVE_UINT16_T
#error expected to have HAVE_UINT16_T
#endif

#ifndef HAVE_UINT32_T
#error expected to have HAVE_UINT32_T
#endif

#ifndef HAVE_UINT64_T
#error expected to have HAVE_UINT64_T
#endif

#ifndef HAVE_UINT8_T
#error expected to have HAVE_UINT8_T
#endif

#ifndef HAVE_UINTPTR_T
#error expected to have HAVE_UINTPTR_T
#endif

#ifndef HAVE_UNISTD_H
#error expected to have HAVE_UNISTD_H
#endif

#ifndef HAVE_UTIME
#error expected to have HAVE_UTIME
#endif

#ifndef HAVE_UTIME_H
#error expected to have HAVE_UTIME_H
#endif

#ifndef HAVE_UTIME_NULL
#error expected to have HAVE_UTIME_NULL
#endif

#ifndef HAVE_VPRINTF
#error expected to have HAVE_VPRINTF
#endif

#ifndef HAVE_VSNPRINTF
#error expected to have HAVE_VSNPRINTF
#endif

#ifndef HAVE__BOOL
#error expected to have HAVE__BOOL
#endif

#ifndef RETSIGTYPE
#error expected to have RETSIGTYPE
#endif

#ifndef SIZEOF_INT
#error expected to have SIZEOF_INT
#endif

#ifndef SIZEOF_LONG
#error expected to have SIZEOF_LONG
#endif

#ifndef SIZEOF_LONG_LONG
#error expected to have SIZEOF_LONG_LONG
#endif

#ifndef SIZEOF_SHORT_INT
#error expected to have SIZEOF_SHORT_INT
#endif

#ifndef SIZEOF_VOID_P
#error expected to have SIZEOF_VOID_P
#endif

#ifndef X86
#error expected to have X86
#endif

#else  /* WIN32 vs X11 */

#ifndef HAVE_ARPA_INET_H
#error expected to have HAVE_ARPA_INET_H
#endif

#ifndef HAVE_ATEXIT
#error expected to have HAVE_ATEXIT
#endif

#ifndef HAVE_DIRENT_H
#error expected to have HAVE_DIRENT_H
#endif

#ifndef HAVE_DLFCN_H
#error expected to have HAVE_DLFCN_H
#endif

#ifndef HAVE_FCNTL_H
#error expected to have HAVE_FCNTL_H
#endif

#ifndef HAVE_FLOAT_H
#error expected to have HAVE_FLOAT_H
#endif

#ifndef HAVE_FORK
#error expected to have HAVE_FORK
#endif

#ifndef HAVE_FTRUNCATE
#error expected to have HAVE_FTRUNCATE
#endif

#ifndef HAVE_GETCWD
#error expected to have HAVE_GETCWD
#endif

#ifndef HAVE_GETHOSTBYADDR
#error expected to have HAVE_GETHOSTBYADDR
#endif

#ifndef HAVE_GETHOSTBYNAME
#error expected to have HAVE_GETHOSTBYNAME
#endif

#ifndef HAVE_INET_NTOA
#error expected to have HAVE_INET_NTOA
#endif

#ifndef HAVE_INT16_T
#error expected to have HAVE_INT16_T
#endif

#ifndef HAVE_INT32_T
#error expected to have HAVE_INT32_T
#endif

#ifndef HAVE_INT64_T
#error expected to have HAVE_INT64_T
#endif

#ifndef HAVE_INT8_T
#error expected to have HAVE_INT8_T
#endif

#ifndef HAVE_INTPTR_T
#error expected to have HAVE_INTPTR_T
#endif

#ifndef HAVE_LIBPTHREAD
#error expected to have HAVE_LIBPTHREAD
#endif

#ifndef HAVE_LIBXFT
#error expected to have HAVE_LIBXFT
#endif

#ifndef HAVE_MEMMOVE
#error expected to have HAVE_MEMMOVE
#endif

#ifndef HAVE_MEMSET
#error expected to have HAVE_MEMSET
#endif

#ifndef HAVE_MKDIR
#error expected to have HAVE_MKDIR
#endif

#ifndef HAVE_NETDB_H
#error expected to have HAVE_NETDB_H
#endif

#ifndef HAVE_NETINET_IN_H
#error expected to have HAVE_NETINET_IN_H
#endif

#ifndef HAVE_POPEN
#error expected to have HAVE_POPEN
#endif

#ifndef HAVE_RMDIR
#error expected to have HAVE_RMDIR
#endif

#ifndef HAVE_SIGNAL_H
#error expected to have HAVE_SIGNAL_H
#endif

#ifndef HAVE_SOCKET
#error expected to have HAVE_SOCKET
#endif

#ifndef HAVE_SOCKLEN_T
#error expected to have HAVE_SOCKLEN_T
#endif

#ifndef HAVE_STDDEF_H
#error expected to have HAVE_STDDEF_H
#endif

#ifndef HAVE_STDINT_H
#error expected to have HAVE_STDINT_H
#endif

#ifndef HAVE_STDLIB_H
#error expected to have HAVE_STDLIB_H
#endif

#ifndef HAVE_STRCHR
#error expected to have HAVE_STRCHR
#endif

#ifndef HAVE_STRDUP
#error expected to have HAVE_STRDUP
#endif

#ifndef HAVE_STRRCHR
#error expected to have HAVE_STRRCHR
#endif

#ifndef HAVE_STRSTR
#error expected to have HAVE_STRSTR
#endif

#ifndef HAVE_SYS_IOCTL_H
#error expected to have HAVE_SYS_IOCTL_H
#endif

#ifndef HAVE_SYS_PARAM_H
#error expected to have HAVE_SYS_PARAM_H
#endif

#ifndef HAVE_SYS_SOCKET_H
#error expected to have HAVE_SYS_SOCKET_H
#endif

#ifndef HAVE_SYS_STAT_H
#error expected to have HAVE_SYS_STAT_H
#endif

#ifndef HAVE_SYS_TIMES_H
#error expected to have HAVE_SYS_TIMES_H
#endif

#ifndef HAVE_SYS_TIME_H
#error expected to have HAVE_SYS_TIME_H
#endif

#ifndef HAVE_SYS_TYPES_H
#error expected to have HAVE_SYS_TYPES_H
#endif

#ifndef HAVE_SYS_WAIT_H
#error expected to have HAVE_SYS_WAIT_H
#endif

#ifndef HAVE_TERMIOS_H
#error expected to have HAVE_TERMIOS_H
#endif

#ifndef HAVE_TGETENT
#error expected to have HAVE_TGETENT
#endif

#ifndef HAVE_TPUTS
#error expected to have HAVE_TPUTS
#endif

#ifndef HAVE_UINT16_T
#error expected to have HAVE_UINT16_T
#endif

#ifndef HAVE_UINT32_T
#error expected to have HAVE_UINT32_T
#endif

#ifndef HAVE_UINT64_T
#error expected to have HAVE_UINT64_T
#endif

#ifndef HAVE_UINT8_T
#error expected to have HAVE_UINT8_T
#endif

#ifndef HAVE_UINTPTR_T
#error expected to have HAVE_UINTPTR_T
#endif

#ifndef HAVE_UNISTD_H
#error expected to have HAVE_UNISTD_H
#endif

#ifndef HAVE_UTIME
#error expected to have HAVE_UTIME
#endif

#ifndef HAVE_UTIME_H
#error expected to have HAVE_UTIME_H
#endif

#ifndef HAVE_VPRINTF
#error expected to have HAVE_VPRINTF
#endif

#ifndef HAVE_VSNPRINTF
#error expected to have HAVE_VSNPRINTF
#endif

#ifndef HAVE_WAIT
#error expected to have HAVE_WAIT
#endif

#ifndef HAVE_WAITPID
#error expected to have HAVE_WAITPID
#endif

#ifndef SIZEOF_INT
#error expected to have SIZEOF_INT
#endif

#ifndef SIZEOF_LONG
#error expected to have SIZEOF_LONG
#endif

#ifndef SIZEOF_LONG_LONG
#error expected to have SIZEOF_LONG_LONG
#endif

#ifndef SIZEOF_SHORT_INT
#error expected to have SIZEOF_SHORT_INT
#endif

#ifndef SIZEOF_VOID_P
#error expected to have SIZEOF_VOID_P
#endif

#endif /* X11 */

/* end of sample code. */

