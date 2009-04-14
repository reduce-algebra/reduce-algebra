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

#define CSL_SIGINT_MSG "+++ Type C to continue, A to abort, X to exit: "

extern int reduceProcessID;

extern int MeToReduce[];
extern int ReduceToMe[];

extern int debug;

extern int redfrontcolor;
extern int normalcolor;
extern int promptcolor;
extern int inputcolor;
extern int outputcolor;
extern int debugcolor;

RETSIGTYPE sig_sigGen(int);
void sig_killChild(void);
RETSIGTYPE sig_sigInt(int);
void sig_skipUntilString(int,const char *);
RETSIGTYPE sig_sigChld(int);
RETSIGTYPE sig_sigTstp(int);
void sig_installHandlers(void);
void sig_removeHandlers(void);
const char *sig_identify(int);

RETSIGTYPE sig_sigGen(int arg) {
  deb_fprintf(stderr,"sig_sigGen(%d)\n",arg);
  sig_killChild();
  line_end();
  switch (arg) {
  case SIGQUIT:
  case SIGHUP:
  case SIGTERM:
    textcolor(redfrontcolor);
    printf("REDFRONT normally exiting on signal %d (%s)\n",arg,sig_identify(arg));
    rf_exit(0);
  default:
    textcolor(redfrontcolor);
    printf("***** REDFRONT exiting on unexpected signal %d (%s)\n",
	   arg,sig_identify(arg));
    rf_exit(-1);
  }
}

void sig_killChild(void) {
  signal(SIGCHLD,SIG_IGN);
  kill(reduceProcessID,SIGTERM);
}

RETSIGTYPE sig_sigInt(int arg) {
  /* Only used for CSL */

  deb_fprintf(stderr,"sig_sigInt(%d)\n",arg);
  kill(reduceProcessID,SIGINT);
  sig_skipUntilString(ReduceToMe[0],CSL_SIGINT_MSG);
  write(MeToReduce[1],"a\n",2);
  printf("\n");
}

void sig_skipUntilString(int handle,const char string[]) {
  char *buffer;
  int len;
  int i;

  len = strlen(string);
  buffer = malloc(len * sizeof(char) + 1);
  read(handle,buffer,len);

  while (strcmp(buffer,string) != 0) {
    deb_fprintf(stderr,"sig_skipUntilString(): buffer=|%s|\n",buffer);
    for (i=0; i < len-1; i++)
      buffer[i] = buffer[i+1];
    read(handle,buffer+len-1,1);
  }
  free(buffer);
}

RETSIGTYPE sig_sigChld(int arg) {
  
  deb_fprintf(stderr,"sig_sigChld(): Reduce process terminated\n");

  line_end_history();

  line_end();

  textcolor(redfrontcolor);

  printf("REDFRONT normally exiting on signal %d (%s)\n",arg,sig_identify(arg));

  resetcolor();

  rf_exit(0);
}

RETSIGTYPE sig_sigTstp(int arg) {
  resetcolor();
  kill(0,SIGSTOP);
}

void sig_installHandlers(void) {
  signal(SIGQUIT,sig_sigGen);
  signal(SIGHUP,sig_sigGen);
#ifdef BPSL
  signal(SIGINT,sig_sigGen);
#else
  signal(SIGINT,SIG_IGN);
#endif
  signal(SIGILL,sig_sigGen);
  signal(SIGTSTP,sig_sigTstp);
#ifndef LINUX
  signal(SIGBUS,sig_sigGen);
#endif
  signal(SIGSEGV,sig_sigGen);
  signal(SIGPIPE,sig_sigGen);
  signal(SIGCHLD,sig_sigChld);
  signal(SIGTERM,sig_sigGen);
}

void sig_removeHandlers(void) {
  signal(SIGQUIT,SIG_DFL);
  signal(SIGHUP,SIG_DFL);
  signal(SIGINT,SIG_DFL);
  signal(SIGILL,SIG_DFL);
  signal(SIGTSTP,SIG_DFL);
#ifndef LINUX
  signal(SIGBUS,SIG_DFL);
#endif
  signal(SIGSEGV,SIG_DFL);
  signal(SIGPIPE,SIG_DFL);
  signal(SIGCHLD,SIG_DFL);
  signal(SIGTERM,SIG_DFL);
}

const char *sig_identify(int signo) {
  /* The list of signals is taken from the sigaction man page: "The
     following is a list of all signals with names as in the include
     file <signal.h> */
  switch(signo) {
  case SIGHUP:    return "SIGHUP";
  case SIGINT:    return "SIGINT";
  case SIGQUIT:   return "SIGQUIT";
  case SIGILL:    return "SIGILL";
  case SIGTRAP:   return "SIGTRAP";
  case SIGABRT:   return "SIGABRT";
  case SIGEMT:    return "SIGEMT";
  case SIGFPE:    return "SIGFPE";
  case SIGKILL:   return "SIGKILL";
  case SIGBUS:    return "SIGBUS";
  case SIGSEGV:   return "SIGSEGV";
  case SIGSYS:    return "SIGSYS";
  case SIGPIPE:   return "SIGPIPE";
  case SIGALRM:   return "SIGALRM";
  case SIGTERM:   return "SIGTERM";
  case SIGURG:    return "SIGURG";
  case SIGSTOP:   return "SIGSTOP";
  case SIGTSTP:   return "SIGTSTP";
  case SIGCONT:   return "SIGCONT";
  case SIGCHLD:   return "SIGCHLD";
  case SIGTTIN:   return "SIGTTIN";
  case SIGTTOU:   return "SIGTTOU";
  case SIGIO:     return "SIGIO";
  case SIGXCPU:   return "SIGXCPU";
  case SIGXFSZ:   return "SIGXFSZ";
  case SIGVTALRM: return "SIGVTALRM";
  case SIGPROF:   return "SIGPROF";
  case SIGWINCH:  return "SIGWINCH";
  case SIGINFO:   return "SIGINFO";
  case SIGUSR1:   return "SIGUSR1";
  case SIGUSR2:   return "SIGUSR2";
  }
  return "unknown signal";
}

/* Code from here on is not used anymore for now. */

void red_felt_hup(int);
void red_felt_term(int);
int sig_killChild_sub(int);
void sig_killChild_sub2(void);
pid_t redfront_waitpid(int,int *);

void wnf_sig_killChild(void) {
  int status;
  int count = 0;

  sig_removeHandlers();
  signal(SIGHUP,red_felt_hup);
  signal(SIGTERM,red_felt_term);

  deb_fprintf(stderr,"\nredfront: Sending Hangup signal to Reduce process\n");

  if (sig_killChild_sub(SIGHUP) != 0 && errno == ESRCH) {
    deb_fprintf(stderr,"\nredfront: No Reduce process\n");
    sig_killChild_sub2();
    return;
  }

  do {
    if (redfront_waitpid(reduceProcessID,&status) == reduceProcessID &&
	(WIFEXITED(status) || WIFSIGNALED(status))) {
      deb_fprintf(stderr,"%sredfront: Reduce has hung up\n",count ? "\n" : "");
      sig_killChild_sub2();
      return;
    }

    sleep(1);

    deb_fprintf(stderr,
	     "%s[waiting]%s",count ? "" : "redfront: ",count-3 ? " " : "\n");

  } while (++count < 4);

  deb_fprintf(stderr,
	   "redfront: sending SIGTERM to Reduce (%d)\n",reduceProcessID);
  
  count = 0;
  if (sig_killChild_sub(SIGTERM) != 0 && errno == ESRCH) {
    deb_fprintf(stderr,"redfront: Reduce has hung up\n");
    sig_killChild_sub2();
    return;
  }

  do {
    if (redfront_waitpid(reduceProcessID,&status) == reduceProcessID &&
	(WIFEXITED(status) || WIFSIGNALED(status))) {
      deb_fprintf(stderr,"%sredfront: Reduce terminated\n",count ? "\n":"");
      sig_killChild_sub2();
      return;
    }
    sleep(1);
    deb_fprintf(stderr,"%s[waiting]%s",count ? "":"XR: ",count-3 ?" ":"\n");
  } while (++count < 4);

  deb_fprintf(stderr,"redfront: Sending Kill signal to Reduce process\n");

  if (sig_killChild_sub(SIGKILL) != 0 && errno == ESRCH) {
    deb_fprintf(stderr,"redfront: Reduce has finally been terminated\n");
    sig_killChild_sub2();
    return;
  }

  sig_killChild_sub2();

  wait(0);

  deb_fprintf(stderr,"redfront: That troublesome Reduce has finally gone\n");

  return;
}

void red_felt_hup(int arg) { 
  deb_fprintf(stderr,"[click] ");
}

void red_felt_term(int arg) {
  deb_fprintf(stderr,"[kerblam] ");
}

/* These functions try to kill the Reduce process, as nicely as possible. */

int sig_killChild_sub(int sg) {
  int rv;
  
  rv = kill(reduceProcessID, sg);
  
  if (sg == SIGTERM)
    kill(0, SIGHUP);

  if (sg == SIGKILL)
    kill(0, SIGTERM);

  return rv;
}

void sig_killChild_sub2(void) {
  fflush(stderr);
  signal(SIGTERM,SIG_IGN);
  kill(0,SIGTERM);
  sleep(1);
}

pid_t redfront_waitpid(int pid,int *status) {
#if defined HAVE_WAIT4
#if defined HAVE_UNION_WAIT
  return wait4(reduceProcessID,(union wait *)status,WNOHANG,NULL);
#else
  return wait4(reduceProcessID,status,WNOHANG,NULL);
#endif
#elif defined HAVE_WAITPID
  return waitpid(pid,status,WNOHANG);
#elif defined HAVE_WAIT3
#if defined HAVE_UNION_WAIT
  return wait3((union wait *)status,WNOHANG,NULL);
#else
  return wait3(status,WNOHANG,NULL);
#endif
#endif
}
