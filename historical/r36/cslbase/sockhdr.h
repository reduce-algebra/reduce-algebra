/*  sockhdr.h                        Copyright (C) 1997 Codemist Ltd */


/*
 * pull in headers suitable for socket-related code.
 */

/* Signature: 07f55060 06-Sep-1997 */

#ifdef __WATCOMC__
/*
 * Use of Watcom C++: please compile in Windows NT/95 mode.
 *               wcl386 -bt=nt webget.c
 */
#  include <conio.h>
#  define ms_windows 1
#endif

#ifdef _MSC_VER
/*
 * Use of Microsoft Visual C++ version 5.0
 */
#  define ms_windows 1
#endif

#ifdef GCC386
/*
 * At present GCC for DOS (the D J Delorie port) does not seem to have
 * socket support in its libraries (very reasonably) so I can not support
 * this code with it. But I want to be able to compile this file as part of
 * larger programs, so I can arrange to build a dummy version that always
 * reports failure to access any net resources!
 */
#  define NOT_SUPPORTED 1
typedef int SOCKET;
#else

#ifdef GCCWIN
/*
 * Use of Cygnus GCC for Win32. I have not yet managed to make this work
 * since both the Windows API headers and the relevant library stubs are
 * still in the process of emerging (Nov 1996), but it seems probable that
 * sometime during 1997 this will become a viable possibility, and anybody
 * who is keen to experiment is encouaged to do so (and report their
 * experiences back to me).
 */
#  define ms_windows 1
#include <netdb.h>
#include <mywinsock.h>
#else

#ifdef ms_windows
#include <winsock.h>
#else
#define unix_posix 1        /* Assume all non-windows systems are Unix! */
/*
 * There may well be terrible delicacies re different variants on Unix. I
 * have (initially) tested this using Solaris and Linux.
 */
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/time.h>
#include <errno.h>
#include <fcntl.h>
#define WSAGetLastError()   errno  /* retrieve error code   */
#define WSACleanup()               /* tidy up at end of day */
#define closesocket(a)      close(a)
#define SOCKET              int
#define SOCKET_ERROR        (-1)
#ifndef INADDR_NONE
#  define INADDR_NONE       0xffffffff
#endif
#ifdef unix_posix
#include <termios.h>        /* So I can do non-echo terminal input */
#endif
#endif
#endif
#endif

#define standard_ftp_port       21
#define standard_gopher_port    70
#define standard_telnet_port    23
#define standard_wais_port      210
#define standard_http_port      80
#define standard_local_port     (-1)

#define default_csl_server_port 1206
#define MAX_USERS                 10  /* approx concurrent remote users */
#define REMOTE_STORE            8000  /* Allow 8 Mbytes per remote user */
#define MAX_CPU_TIME             300  /* Approx CPU limit (seconds) */
#define MAX_ELAPSED_TIME          45  /* Approx elapsed time limit (mins) */

extern clock_t cpu_timeout;
extern time_t  elapsed_timeout;

/*
 * Now some declarations for my own variables and functions.
 */

#ifndef header_tags_h
/*
 * If used as part of the CSL Lisp system header_tags_h will already
 * be defined, and the type Lisp_Object will exist. Otherwise I should
 * define it here.
 */
typedef int Lisp_Object;
#endif

#define PERMITTED_BACKLOG 5

extern int sockets_ready;
extern SOCKET socket_server;
extern char *WSAErrName(int i);
extern int ensure_sockets_ready();

/* End of sockhdr.h */

