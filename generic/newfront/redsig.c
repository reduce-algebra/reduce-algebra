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

#define CSL_SIGINT_MSG "+++ Type C to continue, A to abort, X to exit: "


extern int reduceProcessID;

extern int verbose;

extern int redfrontcolor;
extern int normalcolor;
extern int promptcolor;
extern int inputcolor;
extern int outputcolor;
extern int debugcolor;

RETSIGTYPE sig_sigGen(int);
void sig_killChild(void);
RETSIGTYPE sig_sigInt(int);
#ifdef NATIVE_WINDOWS
void sig_skipUntilString(HANDLE,const char *);
#else
void sig_skipUntilString(int,const char *);
#endif
RETSIGTYPE sig_sigChld(int);
RETSIGTYPE sig_sigTstp(int);
void sig_installHandlers(void);
sig_t sig_signal(int, sig_t);
const char *sig_identify(int);

RETSIGTYPE sig_sigGen(int arg) {
  deb_fprintf(stderr,"sig_sigGen(%d)\n",arg);
  sig_killChild();
  line_end();
  switch (arg) {
#ifndef NATIVE_WINDOWS
  case SIGQUIT:
  case SIGHUP:
#endif
  case SIGTERM:
    if (verbose) {
      textcolor(redfrontcolor);
      printf("REDFRONT normally exiting on signal %d (%s)\n",arg,sig_identify(arg));
    }
    rf_exit(0);
  default:
    if (verbose) {
      textcolor(redfrontcolor);
      printf("***** REDFRONT exiting on unexpected signal %d (%s)\n",
	     arg,sig_identify(arg));
    }
    rf_exit(-1);
  }
}

void sig_killChild(void) {
#ifndef NATIVE_WINDOWS
  signal(SIGCHLD,SIG_IGN);
#endif
#ifdef NATIVE_WINDOWS
//  kill(reduceProcessID,SIGTERM);
  printf("\n+++ NEED TO KILL CHILD PROCESS HERE +++\n"); /* @@@ */
#else
  kill(reduceProcessID,SIGTERM);
#endif
}

RETSIGTYPE sig_sigInt(int arg) {
#ifdef NATIVE_WINDOWS
  DWORD ret;
#else
  ssize_t ret; 
#endif
  deb_fprintf(stderr,"sig_sigInt(%d)\n",arg);
#ifdef NATIVE_WINDOWS
//  kill(reduceProcessID,SIGINT);
  printf("\n+++ NEED TO RELAY SIGINT CHILD PROCESS HERE +++\n"); /* @@@ */
#else
  kill(reduceProcessID,SIGINT);
#endif
#ifdef CSL
  sig_skipUntilString(ReduceToMe[0],CSL_SIGINT_MSG);
  ret = redwrite(MeToReduce[1],"a\n",2);
  printf("\n");
#endif /* CSL */
}

#ifdef NATIVE_WINDOWS
void sig_skipUntilString(HANDLE handle,const char string[]) {
#else
void sig_skipUntilString(int handle,const char string[]) {
#endif
  char *buffer;
  int len;
  int i;
#ifdef NATIVE_WINDOWS
  DWORD ret;
#else
  ssize_t ret;
#endif

  len = strlen(string);
  buffer = malloc(len * sizeof(char) + 1);
  ret = redread(handle,buffer,len);

  while (ret >= 0 && strcmp(buffer,string) != 0) {
    deb_fprintf(stderr,"sig_skipUntilString(): buffer=|%s|\n",buffer);
    for (i=0; i < len-1; i++)
      buffer[i] = buffer[i+1];
    ret = redread(handle,buffer+len-1, 1);
  }
  free(buffer);
}

RETSIGTYPE sig_sigChld(int arg) {
  deb_fprintf(stderr,"sig_sigChld(): Reduce process terminated\n");
  line_end_history();
  line_end();
  if (verbose) {
    textcolor(redfrontcolor);
    printf("Redfront normally exiting on signal %d (%s).\n",arg,sig_identify(arg));
  }
  rf_exit(0);
}

RETSIGTYPE sig_sigTstp(int arg) {
  resetcolor();
#ifndef NATIVE_WINDOWS
/*
 * The i686-w64-mingw32 subsystem does not provide SIGSTOP so if I want to
 * support that functionality more work will be needed.
 */
  kill(0,SIGSTOP);
#endif
}

void sig_installHandlers(void) {
#ifndef NATIVE_WINDOWS
  sig_signal(SIGQUIT,sig_sigGen);
  sig_signal(SIGQUIT,sig_sigGen);
  sig_signal(SIGHUP,sig_sigGen);
#endif
#ifdef PSL
  sig_signal(SIGINT,sig_sigGen);
#else
  sig_signal(SIGINT,SIG_IGN);
#endif
  sig_signal(SIGILL,sig_sigGen);
#ifndef NATIVE_WINDOWS
  sig_signal(SIGTSTP,sig_sigTstp);
#ifndef LINUX
  sig_signal(SIGBUS,sig_sigGen);
#endif
#endif
  sig_signal(SIGSEGV,sig_sigGen);
#ifndef NATIVE_WINDOWS
  sig_signal(SIGPIPE,sig_sigGen);
  sig_signal(SIGCHLD,sig_sigChld);
#endif
  sig_signal(SIGTERM,sig_sigGen);
}

sig_t sig_signal(int sig, sig_t func) {
  sig_t s;

  s = signal(sig, func);
  if (s == SIG_ERR) {
    perror(NULL);
    rf_exit(-1);
  }
  return s;
}

const char *sig_identify(int signo) {
  /* The list of signals is taken from the sigaction man page: "The following is
     a list of all signals with names as in the include file <signal.h> */
  switch(signo) {
  case SIGINT:    return "SIGINT";
  case SIGILL:    return "SIGILL";
  case SIGABRT:   return "SIGABRT";
#ifdef SIGEMT
  case SIGEMT:    return "SIGEMT";
#endif
  case SIGFPE:    return "SIGFPE";
  case SIGSEGV:   return "SIGSEGV";
  case SIGTERM:   return "SIGTERM";
#ifdef SIGINFO
  case SIGINFO:   return "SIGINFO";
#endif
#ifndef NATIVE_WINDOWS
  case SIGHUP:    return "SIGHUP";
  case SIGQUIT:   return "SIGQUIT";
  case SIGTRAP:   return "SIGTRAP";
  case SIGKILL:   return "SIGKILL";
  case SIGBUS:    return "SIGBUS";
  case SIGSYS:    return "SIGSYS";
  case SIGPIPE:   return "SIGPIPE";
  case SIGALRM:   return "SIGALRM";
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
  case SIGUSR1:   return "SIGUSR1";
  case SIGUSR2:   return "SIGUSR2";
#endif
  }
  return "unknown signal";
}

/* end of redsig.c */
