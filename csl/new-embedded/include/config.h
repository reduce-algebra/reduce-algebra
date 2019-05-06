/*
 * This file STARTED LIFE as the output from an autoconf build, but has now
 * been manually adjusted to reflect a conservative, limited and I hope
 * portable configuration.
 * I have removed traces of things that I hope not to need to worry about
 * ever!
 */


/* True to tell sources that this build is part of CSL */
#define CSL 1

/* Define to 1 if you have the <dirent.h> header file, and it defines `DIR'.
   */
#define HAVE_DIRENT_H 1

/* Correct Rounding maths library should be used */
// #define HAVE_CRLIBM 1

#if defined __linux__ || defined __APPLE__ || defined __CYGWIN32__|| defined __CYGWIN__
#define HAVE_UNISTD_H 1
#define HAVE_UTIME_H
#define HAVE_UTIME
#endif

/* True if we will use the FWIN terminal code */
#define HAVE_FWIN 1

/* Define to 1 if the system has the type `int16_t'. */
#define HAVE_INT16_T 1

/* Define to 1 if the system has the type `int32_t'. */
#define HAVE_INT32_T 1

/* Define to 1 if the system has the type `int64_t'. */
#define HAVE_INT64_T 1

/* Define to 1 if the system has the type `int8_t'. */
#define HAVE_INT8_T 1

/* Define to 1 if the system has the type `intptr_t'. */
#define HAVE_INTPTR_T 1

/* Define to 1 if you have the <inttypes.h> header file. */
#define HAVE_INTTYPES_H 1

#define HAVE_SIGACTION

#define HAVE_STDINT_H 1

/* Define to 1 if the system has the type `uint16_t'. */
#define HAVE_UINT16_T 1

/* Define to 1 if the system has the type `uint32_t'. */
#define HAVE_UINT32_T 1

/* Define to 1 if the system has the type `uint64_t'. */
#define HAVE_UINT64_T 1

/* Define to 1 if the system has the type `uint8_t'. */
#define HAVE_UINT8_T 1

/* Define to 1 if the system has the type `uintptr_t'. */
#define HAVE_UINTPTR_T 1

// Well here are some constraints on the support for arithmetic!

#define SIGNED_SHIFTS_ARE_ARITHMETIC 1
#define HAVE_UNSIGNED___INT128 1
#define HAVE___INT128 1

/* System identification for internal use */
#define BUILTFOR "generic"

/* Name of CPU */
#define HOST_CPU "generic"

/* Name of Operating System */
#define HOST_OS "generic"

/* Name of vendor */
#define HOST_VENDOR "generic"

/* Name of package */
#define PACKAGE "csl"

/* Version identification */
#define VERSION "7.0-embedded"

/* Define to the address where bug reports for this package should be sent. */
#define PACKAGE_BUGREPORT ""

/* Define to the full name of this package. */
#define PACKAGE_NAME "CSL"

