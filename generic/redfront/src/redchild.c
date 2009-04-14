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

extern int MeToReduce[];
extern int ReduceToMe[];

extern int debug;
extern int verbose;
extern char *memory;

extern int redfrontcolor;
extern int normalcolor;
extern int promptcolor;
extern int inputcolor;
extern int outputcolor;
extern int debugcolor;

void child(int,char **,char **);
void create_call(int,char **,char **);

void child(int argc,char *argv[],char *envp[]) {
  char *nargv[5];

  setsid();

  sig_removeHandlers();

  signal(SIGTSTP,SIG_IGN);

  close(MeToReduce[1]);
  close(ReduceToMe[0]);

  deb_fprintf(stderr,"child: MeToReduce[0]= %d, ReduceToMe[1] = %d\n",
	   MeToReduce[0], ReduceToMe[1]);

  dup2(MeToReduce[0],STDIN_FILENO);
  dup2(ReduceToMe[1],STDOUT_FILENO);

  close(MeToReduce[0]);
  close(ReduceToMe[1]);
  
  create_call(argc,argv,nargv);
  
  deb_fprintf(stderr,"child: right before execv()\n");
  
  execv(nargv[0],nargv);

  {
    char errstr[1024];
    sprintf(errstr,"cannot execv() %s",nargv[0]);
    perror(errstr); 
  }
  rf_exit(-1);
}

void create_call(int argc,char *argv[],char *nargv[]) {
    int tempfd;

    deb_fprintf(stderr,"child: entering create_call\n");

#ifdef BPSL

    if ((tempfd = open(BPSL,O_RDONLY)) == -1) {  /* Does not check x */
      char errstr[1024];
      sprintf(errstr,"cannot open %s",BPSL);
      perror(errstr);
      rf_exit(-1);
    } else
      close(tempfd);

    if ((tempfd = open(REDIMG,O_RDONLY)) == -1) {
      char errstr[1024];
      sprintf(errstr,"cannot open %s",REDIMG);
      perror(errstr);
      rf_exit(-1);
    } else
      close(tempfd);

    nargv[0] = BPSL;
    nargv[1] = "-td";
    nargv[2] = memory;
    nargv[3] = "-f";
    nargv[4] = REDIMG;
    nargv[5] = (char *)0;
   
#elif defined REDUCE

    if ((tempfd = open(REDUCE,O_RDONLY)) == -1) {  /* Does not check x */
      char errstr[1024];
      sprintf(errstr,"cannot open %s",REDUCE);
      perror(errstr);
      rf_exit(-1);
    } else
      close(tempfd);

    nargv[0] = REDUCE;
    nargv[1] = "-w";
    nargv[2] = "-b";
    nargv[3] = verbose ? "-V" : (char *)0;
    nargv[4] = (char *)0;
    
#endif

    deb_fprintf(stderr,"child: argv[0]=%s\n",nargv[0]);
    deb_fprintf(stderr,"child: argv[1]=%s\n",nargv[1]);
    deb_fprintf(stderr,"child: argv[2]=%s\n",nargv[2]);
    deb_fprintf(stderr,"child: argv[3]=%s\n",nargv[3]);
    deb_fprintf(stderr,"child: argv[4]=%s\n",nargv[4]);

    deb_fprintf(stderr,"child: leaving create_call\n");
}
