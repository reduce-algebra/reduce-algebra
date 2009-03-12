/* ------------------------------------------------------------------
   $Id: redchild.c,v 1.10 2006/12/20 11:51:50 sturm Exp $
   ------------------------------------------------------------------
   Copyright (c) 1999 Andreas Dolzmann and Thomas Sturm
   ------------------------------------------------------------------
   $Log: redchild.c,v $
   Revision 1.10  2006/12/20 11:51:50  sturm
   Switched to ANSI C.

   Revision 1.9  2006/06/19 15:04:07  sturm
   Switching to NORMALCOLOR was missing after some debug outputs.

   Revision 1.8  2006/06/05 06:54:21  sturm
   There was a bpsl instead of lisp left in create_call.

   Revision 1.7  2006/06/03 11:31:29  sturm
   Adapted to the CSL development system.
   Before I had wrong ideas about image model vs. csl.

   Revision 1.6  2004/09/23 09:55:49  sturm
   Fixed debugging output.
   Solaris Compilation.
   This is used for static binaries shipped with REDUCE 3.8.

   Revision 1.5  2004/09/02 13:55:44  sturm
   Moved evaluation of $reduce to redfront.c.
   Added evaluation of $reduce also for redfront root.

   Revision 1.4  2004/09/02 10:13:57  dolzmann
   redfront now uses getopt.
   Added new option -c for version without colors.
   Allows option -m for memory size.

   Revision 1.3  2004/09/02 09:26:54  sturm
   Fixed setenv of $reduce.

   Revision 1.2  2004/09/02 08:53:42  sturm
   Improved color handling.
   Added support for $reduce.
   This is supposed to work with PSL-based REDUCE.

   Revision 1.1  1999/09/20 13:37:52  sturm
   Private autoconf-based REDFRONT development branch by A. Dolzmann
   and T. Sturm.
   Initial check-in.

   ------------------------------------------------------------------ */

#include "redfront.h"

extern int MeToReduce[],ReduceToMe[],debug;

extern char *memory;

extern char *lisp;
extern char *redimg;

void create_call(int,char **,char **);

void child(int argc,char *argv[],char *envp[]) {
  char *nargv[5];

  removeSignalHandlers();  /* Just to make sure! */

  dup2(MeToReduce[0],STDIN_FILENO);
  dup2(ReduceToMe[1],STDOUT_FILENO);

  create_call(argc,argv,nargv);
  
#ifdef DEBUG
  if (debug) {
    textcolor(DEBUGCOLOR);
    fprintf(stderr,"child: right before execv()\n");
    textcolor(NORMALCOLOR);
    fflush(stderr);
  }
#endif
  
  execv(nargv[0],nargv);

  {
    char errstr[1024];
    sprintf(errstr,"cannot execv() %s",nargv[0]);
    perror(errstr); 
  }
  exit(-1);
}

void create_call(int argc,char *argv[],char *nargv[]) {
    int tempfd;

#ifdef DEBUG
    if (debug) {
      textcolor(DEBUGCOLOR);
      fprintf(stderr,"child: entering create_call\n");
      textcolor(NORMALCOLOR);
      fflush(stderr);
    }
#endif

#ifdef RBPSL

    if ((tempfd = open(lisp,O_RDONLY)) == -1) {  /* Does not check x */
      char errstr[1024];
      sprintf(errstr,"cannot open %s",lisp);
      perror(errstr);
      exit(-1);
    } else
      close(tempfd);

    if ((tempfd = open(redimg,O_RDONLY)) == -1) {
      char errstr[1024];
      sprintf(errstr,"cannot open %s",redimg);
      perror(errstr);
      exit(-1);
    } else
      close(tempfd);

    nargv[0] = lisp;

    nargv[1] = "-td";

    nargv[2] = memory;
    
    nargv[3] = "-f";

    nargv[4] = redimg;

    nargv[5] = (char *)0;
    
#ifdef DEBUG
    if (debug) {
      textcolor(DEBUGCOLOR);
      fprintf(stderr,"child: argv[0]=%s\n",nargv[0]);
      fprintf(stderr,"child: argv[1]=%s\n",nargv[1]);
      fprintf(stderr,"child: argv[2]=%s\n",nargv[2]);
      fprintf(stderr,"child: argv[3]=%s\n",nargv[3]);
      fprintf(stderr,"child: argv[4]=%s\n",nargv[4]);
      textcolor(NORMALCOLOR);
      fflush(stderr);
    }
#endif

#elif defined RCSL

    if ((tempfd = open(lisp,O_RDONLY)) == -1) {  /* Does not check x */
      char errstr[1024];
      sprintf(errstr,"cannot open %s",lisp);
      perror(errstr);
      exit(-1);
    } else
      close(tempfd);

    if ((tempfd = open(redimg,O_RDONLY)) == -1) {
      char errstr[1024];
      sprintf(errstr,"cannot open %s",redimg);
      perror(errstr);
      exit(-1);
    } else
      close(tempfd);

    nargv[0] = lisp;
    
    nargv[1] = "-b";

    nargv[2] = "-o";

    nargv[3] = redimg;

    nargv[4] = (char *)0;
    
#ifdef DEBUG
    if (debug) {
      textcolor(DEBUGCOLOR);
      fprintf(stderr,"child: argv[0]=%s\n",nargv[0]);
      fprintf(stderr,"child: argv[1]=%s\n",nargv[1]);
      fprintf(stderr,"child: argv[2]=%s\n",nargv[2]);
      fprintf(stderr,"child: argv[2]=%s\n",nargv[3]);
      textcolor(NORMALCOLOR);
      fflush(stderr);
    }
#endif

#else
    
    if ((tempfd = open(REDUCE,O_RDONLY)) == -1) {
      char errstr[1024];
      sprintf(errstr,"cannot open %s",REDUCE);
      perror(errstr);
      exit(-1);
    }
    else
      close(tempfd);
    
    nargv[0] = REDUCE;

    nargv[1] = (char *)0;

#ifdef DEBUG
    if (debug) {
      textcolor(DEBUGCOLOR);
      fprintf(stderr,"\nExecuting Reduce binary: %s\n",nargv[0]);
      textcolor(NORMALCOLOR);
      fflush(stderr);
    }
#endif

#endif

#ifdef DEBUG
    if (debug) {
      textcolor(DEBUGCOLOR);
      fprintf(stderr,"child: leaving create_call\n");
      textcolor(NORMALCOLOR);
      fflush(stderr);
    }
#endif
}
