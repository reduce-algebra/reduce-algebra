/* ---------------------------------------------------------------------
   $Id$
   ---------------------------------------------------------------------
   Copyright (c) 1999-2009 Andreas Dolzmann and Thomas Sturm
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

#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/stat.h>

#define LOCK -1
#define UNLOCK 1
#define PERM 0666
#define KEY 471142L

static struct sembuf semaphore;
static int semid;

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
  semid = semget(KEY,0,IPC_PRIVATE);
  if (semid < 0) {
    umask(0);
    semid = semget(KEY,1,IPC_CREAT|IPC_EXCL|PERM);
    if (semid < 0) {
      fprintf(stderr,"deb: cannot create semaphore\n");
      resetcolor();
      exit(-1);
    }
    semctl(semid,0,SETVAL,1);
  }
  dbprintf(stderr,"deb: created semaphore %d\n",semid);
}

int deb_mutex(int op) {
   semaphore.sem_op = op;
   semaphore.sem_flg = SEM_UNDO;
   if(semop(semid,&semaphore,1) == -1) {
      perror("semop");
      rf_exit(EXIT_FAILURE);
   }
   return 1;
}

int deb_fprintf(FILE *file,const char *msg,...) {
  int ecode=0;
  int oldcolor;
  va_list ap;

  va_start(ap,msg);
  if (debug && file) {
    mutex(LOCK);
    oldcolor = textcolor(debugcolor);
    ecode = vfprintf(stdout,msg,ap);
    textcolor(oldcolor);
    mutex(UNLOCK);
  }
  va_end(ap);
  fflush(stderr);

  return ecode;
}

void deb_cleanup() {
  dbprintf(stderr,"deb: about to delete semaphore %d\n",semid);
  semctl(semid,0,IPC_RMID,0);
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
