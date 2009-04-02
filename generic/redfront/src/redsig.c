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

RETSIGTYPE ReduceSigGen(int);
RETSIGTYPE ReduceSigInt(int);
RETSIGTYPE ReduceSigChld(int);
void installSignalHandlers(void);
void removeSignalHandlers(void);
void red_kill(void);
const char *sig_identify(int);
void red_felt_hup(int);
void red_felt_term(int);
int red_kill_sub(int);
void red_kill_sub2(void);
pid_t redfront_waitpid(int,int *);

RETSIGTYPE ReduceSigGen(int arg) {
#ifdef DEBUG
  if (debug) {
    textcolor(debugcolor);
    fprintf(stderr,"ReduceSigGen(%d)\n",arg);
    textcolor(normalcolor);
  }
#endif
  fflush(stderr);
  red_kill();
  textcolor(redfrontcolor);
  printf("REDFRONT exiting on signal %d (%s)\n",arg,sig_identify(arg));
  //  textcolor(normalcolor);  /* might not match, but black is better than red */
  line_end();
  resetcolor();
  switch (arg) {
  case SIGQUIT:
  case SIGHUP:
  case SIGTERM:
  case SIGINT:
    exit(0);
  default:
    exit(-1);
  }
}

RETSIGTYPE ReduceSigInt(int arg) {
  /* Only used for CSL */
  int ncharread;
  char buffer[1];
  int flags;

#ifdef DEBUG
  if (debug) {
    textcolor(debugcolor);
    fprintf(stderr,"ReduceSigInt(%d)\n",arg);
    textcolor(normalcolor);
  }
#endif
  kill(reduceProcessID,SIGINT);
  read(ReduceToMe[0],buffer,1);
  flags = fcntl(ReduceToMe[0],F_GETFL);
  fcntl(ReduceToMe[0],F_SETFL,flags|O_NONBLOCK);
  do {
    ncharread = read(ReduceToMe[0],buffer,1);
  } while (ncharread != -1);
  fcntl(ReduceToMe[0],F_SETFL,flags&~O_NONBLOCK);
  textcolor(normalcolor);
  write(MeToReduce[1],"a\n",2);
}

RETSIGTYPE ReduceSigChld(int arg) {
  int *stP;
  
  stP = (int *)malloc(sizeof(int));
  
  removeSignalHandlers();

#ifdef DEBUG
  if (debug) {
    textcolor(debugcolor);
    fprintf(stderr,"Reduce process terminated\n");
    textcolor(normalcolor);
  }
#endif

  line_end_history();

  line_end();

  resetcolor();

  exit(0);
}

RETSIGTYPE ReduceSigTstp(int arg) {
  resetcolor();
  kill(0,SIGSTOP);
}

void installSignalHandlers(void) {
  signal(SIGQUIT,ReduceSigGen);
  signal(SIGHUP,ReduceSigGen);
#ifdef BPSL
  signal(SIGINT,ReduceSigGen);
#else
  signal(SIGINT,SIG_IGN);
#endif
  signal(SIGILL,ReduceSigGen);
  signal(SIGTSTP,ReduceSigTstp);
#ifndef LINUX
  signal(SIGBUS,ReduceSigGen);
#endif
  signal(SIGSEGV,ReduceSigGen);
  signal(SIGPIPE,ReduceSigGen);
  signal(SIGCHLD,ReduceSigChld);
  signal(SIGTERM,ReduceSigGen);
}

void removeSignalHandlers(void) {
  signal(SIGQUIT,SIG_DFL);
  signal(SIGHUP,SIG_DFL);
  signal(SIGILL,SIG_DFL);
#ifndef LINUX
  signal(SIGBUS,SIG_DFL);
#endif
  signal(SIGSEGV,SIG_DFL);
  signal(SIGPIPE,SIG_DFL);
  signal(SIGCHLD,SIG_DFL);
  signal(SIGTERM,SIG_DFL);
}

void red_kill(void) {
  kill(reduceProcessID,SIGTERM);
}

const char *sig_identify(int signo) {
  switch(signo) {
  case SIGFPE:    return "SIGFPE";
  case SIGSTOP:   return "SIGSTOP";
  case SIGHUP:    return "SIGHUP";
  case SIGINT:    return "SIGINT";
  case SIGQUIT:   return "SIGQUIT";
  case SIGILL:    return "SIGILL";
  case SIGTRAP:   return "SIGTRAP";
  case SIGABRT:   return "SIGABRT";
  case SIGBUS:    return "SIGBUS";
  case SIGSYS:    return "SIGSYS";
  case SIGCONT:   return "SIGCONT";
  case SIGUSR1:   return "SIGUSR1";
  case SIGUSR2:   return "SIGUSR2";
  case SIGSEGV:   return "SIGSEGV";
  case SIGPIPE:   return "SIGPIPE";
  case SIGALRM:   return "SIGALRM";
  case SIGTERM:   return "SIGTERM";
  case SIGCHLD:   return "SIGCHLD";
  case SIGIO:     return "SIGIO";
  case SIGKILL:   return "SIGKILL";
  case SIGTSTP:   return "SIGTSTP";
  case SIGTTIN:   return "SIGTTIN";
  case SIGTTOU:   return "SIGTTOU";
  case SIGURG:    return "SIGURG";
  case SIGXCPU:   return "SIGXCPU";
  case SIGXFSZ:   return "SIGXFSZ";
  case SIGVTALRM: return "SIGVTALRM";
  case SIGPROF:   return "SIGPROF";
  case SIGWINCH:  return "SIGWINCH";
  }
  return NULL;
}

/* Code from here on is not used anymore for now. */

void wnf_red_kill(void) {
  int status;
  int count = 0;

  removeSignalHandlers();
  signal(SIGHUP,red_felt_hup);
  signal(SIGTERM,red_felt_term);

#ifdef DEBUG
  if (debug) {
    textcolor(debugcolor);
    fprintf(stderr,"\nredfront: Sending Hangup signal to Reduce process\n");
    textcolor(normalcolor);
    fflush(stderr);
  }
#endif

  if (red_kill_sub(SIGHUP) != 0 && errno == ESRCH) {
#ifdef DEBUG
    if (debug) {
      textcolor(debugcolor);
      fprintf(stderr,"\nredfront: No Reduce process\n");
      textcolor(normalcolor);
    }
#endif
    red_kill_sub2();
    return;
  }

  do {
    if (redfront_waitpid(reduceProcessID,&status) == reduceProcessID &&
	(WIFEXITED(status) || WIFSIGNALED(status))) {
#ifdef DEBUG
      if (debug) {
	textcolor(debugcolor);
	fprintf(stderr,"%sredfront: Reduce has hung up\n",count ? "\n" : "");
	textcolor(normalcolor);
      }
#endif
      red_kill_sub2();
      return;
    }

    sleep(1);

#ifdef DEBUG
    if (debug) {
      textcolor(debugcolor);
      fprintf(stderr,
	      "%s[waiting]%s",count ? "" : "redfront: ",count-3 ? " " : "\n");
      textcolor(normalcolor);
      fflush(stderr);
    }
#endif

  } while (++count < 4);

#ifdef DEBUG
  if (debug) {
    textcolor(debugcolor);
    fprintf(stderr,
	    "redfront: sending SIGTERM to Reduce (%d)\n",reduceProcessID);
    textcolor(normalcolor);
    fflush(stderr);
  }
#endif
  
  count = 0;
  if (red_kill_sub(SIGTERM) != 0 && errno == ESRCH) {
#ifdef DEBUG
    if (debug) {
      textcolor(debugcolor);
      fprintf(stderr,"redfront: Reduce has hung up\n");
      textcolor(normalcolor);
    }
#endif
    red_kill_sub2();
    return;
  }

  do {
    if (redfront_waitpid(reduceProcessID,&status) == reduceProcessID &&
	(WIFEXITED(status) || WIFSIGNALED(status))) {
#ifdef DEBUG
      if (debug) {
	textcolor(debugcolor);
	fprintf(stderr,"%sredfront: Reduce terminated\n",count ? "\n":"");
	textcolor(normalcolor);
      }
#endif
      red_kill_sub2();
      return;
    }
    sleep(1);
#ifdef DEBUG
    if (debug) {
      textcolor(debugcolor);
      fprintf(stderr,"%s[waiting]%s",count ? "":"XR: ",count-3 ?" ":"\n");
      textcolor(normalcolor);
      fflush(stderr);
    }
#endif
  } while (++count < 4);

#ifdef DEBUG
  if (debug) {
    textcolor(debugcolor);
    fprintf(stderr,"redfront: Sending Kill signal to Reduce process\n");
    textcolor(normalcolor);
    fflush(stderr);
  }
#endif

  if (red_kill_sub(SIGKILL) != 0 && errno == ESRCH) {
#ifdef DEBUG
    if (debug) {
      textcolor(normalcolor);
      fprintf(stderr,"redfront: Reduce has finally been terminated\n");
      textcolor(normalcolor);
    }
#endif
    red_kill_sub2();
    return;
  }

  red_kill_sub2();

  wait(0);

#ifdef DEBUG
  if (debug) {
    textcolor(debugcolor);
    fprintf(stderr,"redfront: That troublesome Reduce has finally gone\n");
    textcolor(normalcolor);
  }
#endif

  return;
}

void red_felt_hup(int arg) { 
#ifdef DEBUG
  if (debug) { 
    textcolor(debugcolor);
    fprintf(stderr,"[click] ");
    textcolor(normalcolor);
  }
#endif
}

void red_felt_term(int arg) {
#ifdef DEBUG
  if (debug) { 
    textcolor(debugcolor);
    fprintf(stderr,"[kerblam] ");
    textcolor(normalcolor);
  }
#endif
}

/* These functions try to kill the Reduce process, as nicely as possible. */

int red_kill_sub(int sg) {
  int rv;
  
  rv = kill(reduceProcessID, sg);
  
  if (sg == SIGTERM)
    kill(0, SIGHUP);

  if (sg == SIGKILL)
    kill(0, SIGTERM);

  return rv;
}

void red_kill_sub2(void) {
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
