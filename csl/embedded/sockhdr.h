/*  sockhdr.h                        Copyright (C) 1997-2008 Codemist Ltd */

/*
 * pull in headers suitable for socket-related code.
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


/* Signature: 5cef0ec1 24-May-2008 */

#ifndef UNDER_CE
#include <errno.h>
#endif

#ifdef WIN32
#include <winsock.h>
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

