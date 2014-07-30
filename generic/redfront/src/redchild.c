/* ---------------------------------------------------------------------
   $Id$
   ---------------------------------------------------------------------
   (c) 1999-2008 A. Dolzmann and T. Sturm, 1999-2014 T. Sturm
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

void child(char**);
void child_signalHandlers(void);

void child(char *nargv[]) {

  setsid();

  child_signalHandlers();

  close(MeToReduce[1]);
  close(ReduceToMe[0]);

  deb_fprintf(stderr,"child: MeToReduce[0]= %d, ReduceToMe[1] = %d\n",
	      MeToReduce[0], ReduceToMe[1]);

  dup2(MeToReduce[0],STDIN_FILENO);
  dup2(ReduceToMe[1],STDOUT_FILENO);

  close(MeToReduce[0]);
  close(ReduceToMe[1]);

  deb_fprintf(stderr,"child: right before execv()\n");

  execv(nargv[0],nargv);

  {
    char errstr[1024];
    sprintf(errstr,"cannot execv() %s",nargv[0]);
    perror(errstr);
  }
  rf_exit(-1);
}

void child_signalHandlers(void) {
  signal(SIGQUIT,SIG_DFL);
  signal(SIGHUP,SIG_DFL);
  signal(SIGINT,SIG_DFL);
  signal(SIGILL,SIG_DFL);
  signal(SIGTSTP,SIG_IGN);
#ifndef LINUX
  signal(SIGBUS,SIG_DFL);
#endif
  signal(SIGSEGV,SIG_DFL);
  signal(SIGPIPE,SIG_DFL);
  signal(SIGCHLD,SIG_DFL);
  signal(SIGTERM,SIG_DFL);
}
