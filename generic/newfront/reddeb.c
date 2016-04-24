/* ---------------------------------------------------------------------
   $Id$
   ---------------------------------------------------------------------
   (c) 1999-2009 A. Dolzmann and T. Sturm, 1999-2014 T. Sturm
   ---------------------------------------------------------------------
   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions
   are met:
  
      * Redistributions of source code must retain the relevant
        copyright notice, this list of conditions and the following
        disclaimer.
      * Redistributions in binary form must reproduce the above
        copyright notice, this list of conditions and the following
        disclaimer in the documentation and/or other materials provided
        with the distribution.
  
   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
   "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
   A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
   OWNERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
   SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
   LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
   DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
   THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
   (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
   OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#include "redfront.h"

#ifdef DEBUG

/*
 * This has been changed to use Windows or POSIX mutexes rather than
 * some Sys V features...
 */

#ifdef WIN32

#include <windows.h>

// On Windows I can use CRITICAL_SECTIONs rather than real mutexes, and the
// performance difference is quite substantial when contention is reasonably
// low. The key issue is that a CRITICAL_SECTION does its initial checks in
// user-mode and only upgrades to kernel mode in the complicated cases. A
// side effect of this is that all use of one of these locks must occur
// within a single process, while more general mutexes support use even
// when multiple processes are present.

// I will not destroy mutexes at the end of a run - they can be cleaned up
// as the application exits.

CRITICAL_SECTION logmutex;

#define CREATELOGMUTEX     InitializeCriticalSection(&logmutex)
#define LOCKLOGMUTEX       EnterCriticalSection(&logmutex)
#define UNLOCKLOGMUTEX     LeaveCriticalSection(&logmutex)

#else

#include <pthread.h>
#include <unistd.h>

pthread_mutex_t logmutex = PTHREAD_MUTEX_INITIALIZER;

// Using Posix threads I initialise the mutexes statically.

#define CREATELOGMUTEX     // Nothing
#define LOCKLOGMUTEX       if (pthread_mutex_lock(&logmutex) != 0) \
                           { fprintf(stderr, "locking failed\n"); exit(1); }
#define UNLOCKLOGMUTEX     if (pthread_mutex_unlock(&logmutex) != 0) \
                           { fprintf(stderr, "locking failed\n"); exit(1); }


#endif



int debug = 1;

extern int redfrontcolor;
extern int normalcolor;
extern int promptcolor;
extern int inputcolor;
extern int outputcolor;
extern int debugcolor;

void deb_init(void);
int deb_mutex(int op);
int deb_fprintf(FILE *,const char *msg,...);
void deb_cleanup(void);

void deb_init(void) {
  CREATELOGMUTEX;
  deb_fprintf(stderr,"deb: created mutex\n");
}

int deb_fprintf(FILE *file,const char *msg,...) {
  int ecode=0;
  int oldcolor;
  va_list ap;

  va_start(ap,msg);
  if (debug && file) {
    LOCKLOGMUTEX;
    oldcolor = textcolor(debugcolor);
    ecode = vfprintf(file,msg,ap);
    textcolor(oldcolor);
    fflush(file);
    UNLOCKLOGMUTEX;
  }
  va_end(ap);

  return ecode;
}

void deb_cleanup() {
}

#else

int debug = 0;

void deb_init(void) {
}

int deb_fprintf(FILE *file,const char *msg,...) {
  return 0;
}

void deb_cleanup() {
}

#endif

/* end of reddeb.c */
