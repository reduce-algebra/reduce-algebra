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
