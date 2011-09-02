/*  sockhdr.h                        Copyright (C) 1997-2007 Codemist Ltd */

/*
 * pull in headers suitable for socket-related code.
 */


/*
 * This code may be used and modified, and redistributed in binary
 * or source form, subject to the "CCL Public License", which should
 * accompany it. This license is a variant on the BSD license, and thus
 * permits use of code derived from this in either open and commercial
 * projects: but it does require that updates to this code be made
 * available back to the originators of the package.
 * Before merging other code in with this or linking this code
 * with other packages or libraries please check that the license terms
 * of the other material are compatible with those of this.
 */


/* Signature: 6556ae22 10-Aug-2008 */

#ifndef UNDER_CE
#include <errno.h>
#endif

#ifdef WIN32
/* #include <winsock.h> */
#include <winsock2.h>
#else
#define unix_posix 1        /* Assume all non-windows systems are Unix! */
/*
 * There may well be terrible delicacies re different variants on Unix. I
 * have (initially) tested this using Solaris and Linux. As I find
 * trouble in other cases I guess I can make the autoconf checks more and
 * more elaborate...
 */
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/time.h>
#include <fcntl.h>
#define WSAGetLastError()   errno  /* retrieve error code   */
#define WSACleanup()               /* tidy up at end of day */
#define closesocket(a)      close(a)
#define SOCKET              int
#define SOCKET_ERROR        (-1)
#ifndef INADDR_NONE
#  define INADDR_NONE       0xffffffff
#endif
#endif

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
extern int ensure_sockets_ready(void);

/* End of sockhdr.h */

