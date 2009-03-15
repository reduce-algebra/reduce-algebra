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

extern int debug,reduceProcessID,MeToReduce[];

RETSIGTYPE ReduceSigGen(int);
RETSIGTYPE ReduceSigInt(int);
RETSIGTYPE ReduceSigChld(int);
void installSignalHandlers(void);
void removeSignalHandlers(void);
void red_kill(void);
void red_felt_hup(int);
void red_felt_term(int);
int red_kill_sub(int);
void red_kill_sub2(void);
pid_t redfront_waitpid(int,int *);

/* Signal handlers. Generally dedicated to catching the Reduce child
   process, slicing it into little pieces and fleeing for one's life. */

RETSIGTYPE ReduceSigGen(int arg) {
#ifdef DEBUG
  if (debug) {
    textcolor(DEBUGCOLOR);
    fprintf(stderr,"ReduceSigGen(%d)\n",arg);
    textcolor(NORMALCOLOR);
  }
#endif
  fflush(stderr);
  red_kill();
  textcolor(NORMALCOLOR);  /* might not match, but black is better than red */
  printf("\n");
  redline_cleanup_after_signal();
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

  if (debug) {
    textcolor(DEBUGCOLOR);
    fprintf(stderr,"ReduceSigInt(%d)\n",arg);
    textcolor(NORMALCOLOR);
  }

  write(MeToReduce[1],"a\n",2);
}

RETSIGTYPE ReduceSigChld(int arg) {
  int *stP;
  char tmp_char [100];
  
  stP = (int *)malloc(sizeof(int));
  
  removeSignalHandlers();

#ifdef DEBUG
  if (debug) {
    textcolor(DEBUGCOLOR);
    fprintf(stderr,"Reduce process terminated\n");
    textcolor(NORMALCOLOR);
  }
#endif

#ifdef HAVE_HISTORY
  sprintf(tmp_char,"%s/.reduce_history",getenv("HOME"));
  redline_stifle_history(HISTFILESIZE);
  redline_write_history(tmp_char);
#endif

  /* TS does not believe that this did any good: */
  
  /* kill(getpid(),SIGALRM); // Have to kill ourselves to reset e.g. readline */
  /* Instead I use the following: */
  
  redline_cleanup_after_signal();
  /* This also avoids the Alarm Clock message, which irritated some customers. */

  exit(0);
}

void installSignalHandlers(void) {
  signal(SIGQUIT,ReduceSigGen);
  signal(SIGHUP,ReduceSigGen);
#ifdef BPSL
  signal(SIGINT,ReduceSigGen);
#else
  signal(SIGINT,ReduceSigInt);
#endif
  signal(SIGILL,ReduceSigGen);
  signal(SIGSTOP,SIG_DFL);
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

/* Code from here on is not used anymore for now. */

void wnf_red_kill(void) {
  int status;
  int count = 0;

  removeSignalHandlers();
  signal(SIGHUP,red_felt_hup);
  signal(SIGTERM,red_felt_term);

#ifdef DEBUG
  if (debug) {
    textcolor(DEBUGCOLOR);
    fprintf(stderr,"\nredfront: Sending Hangup signal to Reduce process\n");
    textcolor(NORMALCOLOR);
    fflush(stderr);
  }
#endif

  if (red_kill_sub(SIGHUP) != 0 && errno == ESRCH) {
#ifdef DEBUG
    if (debug) {
      textcolor(DEBUGCOLOR);
      fprintf(stderr,"\nredfront: No Reduce process\n");
      textcolor(NORMALCOLOR);
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
	textcolor(DEBUGCOLOR);
	fprintf(stderr,"%sredfront: Reduce has hung up\n",count ? "\n" : "");
	textcolor(NORMALCOLOR);
      }
#endif
      red_kill_sub2();
      return;
    }

    sleep(1);

#ifdef DEBUG
    if (debug) {
      textcolor(DEBUGCOLOR);
      fprintf(stderr,
	      "%s[waiting]%s",count ? "" : "redfront: ",count-3 ? " " : "\n");
      textcolor(NORMALCOLOR);
      fflush(stderr);
    }
#endif

  } while (++count < 4);

#ifdef DEBUG
  if (debug) {
    textcolor(DEBUGCOLOR);
    fprintf(stderr,
	    "redfront: sending SIGTERM to Reduce (%d)\n",reduceProcessID);
    textcolor(NORMALCOLOR);
    fflush(stderr);
  }
#endif
  
  count = 0;
  if (red_kill_sub(SIGTERM) != 0 && errno == ESRCH) {
#ifdef DEBUG
    if (debug) {
      textcolor(DEBUGCOLOR);
      fprintf(stderr,"redfront: Reduce has hung up\n");
      textcolor(NORMALCOLOR);
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
	textcolor(DEBUGCOLOR);
	fprintf(stderr,"%sredfront: Reduce terminated\n",count ? "\n":"");
	textcolor(NORMALCOLOR);
      }
#endif
      red_kill_sub2();
      return;
    }
    sleep(1);
#ifdef DEBUG
    if (debug) {
      textcolor(DEBUGCOLOR);
      fprintf(stderr,"%s[waiting]%s",count ? "":"XR: ",count-3 ?" ":"\n");
      textcolor(NORMALCOLOR);
      fflush(stderr);
    }
#endif
  } while (++count < 4);

#ifdef DEBUG
  if (debug) {
    textcolor(DEBUGCOLOR);
    fprintf(stderr,"redfront: Sending Kill signal to Reduce process\n");
    textcolor(NORMALCOLOR);
    fflush(stderr);
  }
#endif

  if (red_kill_sub(SIGKILL) != 0 && errno == ESRCH) {
#ifdef DEBUG
    if (debug) {
      textcolor(NORMALCOLOR);
      fprintf(stderr,"redfront: Reduce has finally been terminated\n");
      textcolor(NORMALCOLOR);
    }
#endif
    red_kill_sub2();
    return;
  }

  red_kill_sub2();

  wait(0);

#ifdef DEBUG
  if (debug) {
    textcolor(DEBUGCOLOR);
    fprintf(stderr,"redfront: That troublesome Reduce has finally gone\n");
    textcolor(NORMALCOLOR);
  }
#endif

  return;
}

void red_felt_hup(int arg) { 
#ifdef DEBUG
  if (debug) { 
    textcolor(DEBUGCOLOR);
    fprintf(stderr,"[click] ");
    textcolor(NORMALCOLOR);
  }
#endif
}

void red_felt_term(int arg) {
#ifdef DEBUG
  if (debug) { 
    textcolor(DEBUGCOLOR);
    fprintf(stderr,"[kerblam] ");
    textcolor(NORMALCOLOR);
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
