/* ------------------------------------------------------------------
   $Id: redsig.c,v 1.7 2006/12/20 12:02:01 sturm Exp $
   ------------------------------------------------------------------
   Copyright (c) 1999 Andreas Dolzmann and Thomas Sturm
   ------------------------------------------------------------------
   $Log: redsig.c,v $
   Revision 1.7  2006/12/20 12:02:01  sturm
   Swiched to ANSI C.Do not use most of Winfried's (still present) process termination code anymore.Both CSL and PSL redfront immediately terminate on C-c now.

   Revision 1.6  2006/05/19 08:44:16  sturm
   Explicit newline for EOF exit and SIGQUIT.

   Revision 1.5  2006/05/19 06:28:38  sturm
   Do not terminate redfront via SIGALRM anymore.
   When killed by an external signal (e.g. SIGQUIT=C-\), set terminal color
   to NORMALCOLOR (=black).

   Revision 1.4  2006/05/18 03:05:57  sturm
   Carefully check for HAVE_UNION_WAIT.

   Revision 1.3  2006/05/17 18:15:43  sturm
   Check for using_history in linreadline first.
   This is essential at least on MacOS X.

   Revision 1.2  2004/09/23 09:55:49  sturm
   Fixed debugging output.
   Solaris Compilation.
   This is used for static binaries shipped with REDUCE 3.8.

   Revision 1.1  1999/09/20 13:37:53  sturm
   Private autoconf-based REDFRONT development branch by A. Dolzmann
   and T. Sturm.
   Initial check-in.

   ------------------------------------------------------------------ */

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
  rl_cleanup_after_signal();
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
/*  write(MeToReduce[1],"a\n",2); */
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
  stifle_history(HISTFILESIZE);
  write_history(tmp_char);
#endif

  /* TS does not believe that this did any good: */
  
  /* kill(getpid(),SIGALRM); // Have to kill ourselves to reset e.g. readline */
  /* Instead I use the following: */
  
  rl_cleanup_after_signal();
  /* This also avoids the Alarm Clock message, which irritated some customers. */

  exit(0);
}

void installSignalHandlers(void) {
  signal(SIGQUIT,ReduceSigGen);
  signal(SIGHUP,ReduceSigGen);
#ifdef RBPSL
  signal(SIGINT,ReduceSigGen);
#else
  signal(SIGINT,ReduceSigGen); /* signal(SIGINT,ReduceSigInt); */
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
