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

void child(char**);
void child_signalHandlers(void);

#ifdef NATIVE_WINDOWS

void child(char *nargv[]) {
/*
 * Windows imposes a limit of 32768 characters in a command line, which is
 * why I can support this size here.
 */
  char command_line[32768];
  int nc = 0;
  char **p = nargv, *a;
#define CC(x) if (nc < 32767) command_line[nc++] = (x)
/*
 * I reconstruct a command line to pass down, and while I do so I need to
 * cope with the quotation rules that seems to apply when I call CreateProcess
 * and expect the line at the other end to be handled by a proepr Windows
 * process. Three rules apply:
 * (1) The whole argument is enclosed in double quotes;
 * (2) If a double quote mark appears within the argument it must
 *     have a backslash placed ahead of it;
 * (3) If a backslash would be the very last character of the
 *     argument it must be doubled.
 * I truncate my command line at 32768 characters, which is the Windows
 * limit.
 */
  while ((a = *p++) != NULL)
  {  int c;
printf("next arg is %s\n", a);
     CC('"');
     while ((c = *a++) != 0)
     {   if (c == '"') CC('\\');
         CC(c);
     }
     if (command_line[nc-1] == '\\') CC('\\');
     CC('"');
     if (*p != NULL) CC(' ');
  }
  command_line[nc] = 0;
  deb_fprintf(stderr,"reconstructed command line <%s>\n", command_line);

  child_signalHandlers();

  deb_fprintf(stderr,"child: MeToReduce[0]= %p, ReduceToMe[1] = %p\n",
	      (void *)MeToReduce[0], (void *)ReduceToMe[1]);

  deb_fprintf(stderr,"child: right before execv()\n");

  STARTUPINFO startupinfo;
  PROCESS_INFORMATION process_info; 
  memset(&startupinfo, 0, sizeof(startupinfo));
  memset(&process_info, 0, sizeof(process_info));
  startupinfo.cb = sizeof(startupinfo);
  startupinfo.hStdInput = MeToReduce[0];
  startupinfo.hStdOutput = ReduceToMe[1];
  startupinfo.hStdError = ReduceToMe[1];
  startupinfo.dwFlags = STARTF_USESTDHANDLES;
  int r = CreateProcess(
    NULL,           /* First word on command line used instead. */
    command_line,   /* Note how carefully I quoted things! */
    NULL,           /* ProcessAttributes - use defaults. */
    NULL,           /* ThreadAttributes - use defaults. */
    TRUE,           /* InheritHandles */
    CREATE_NEW_PROCESS_GROUP, /* Keep Reduce sepaarte from redfront */
    NULL,           /* Environment: use environment from caller. */
    NULL,           /* Current Directory: use one that caller has.  */
    &startupinfo,   /* Passes down handles */
    &process_info); /* Receives info about the created process */

// process_info.hProcess should be the handle of the created process.

}

#else /* NATIVE_WINDOWS */

void child(char *nargv[]) {

  setsid();

  child_signalHandlers();

  redclose(MeToReduce[1]);
  redclose(ReduceToMe[0]);

  deb_fprintf(stderr,"child: MeToReduce[0]= %d, ReduceToMe[1] = %d\n",
	      MeToReduce[0], ReduceToMe[1]);

  dup2(MeToReduce[0],STDIN_FILENO);
  dup2(ReduceToMe[1],STDOUT_FILENO);

  redclose(MeToReduce[0]);
  redclose(ReduceToMe[1]);

  deb_fprintf(stderr,"child: right before execv()\n");

  execv(nargv[0],nargv);

  {
    char errstr[1024];
    sprintf(errstr,"cannot execv() %s",nargv[0]);
    perror(errstr);
  }
  rf_exit(-1);
}

#endif /* NATIVE_WINDOWS */

void child_signalHandlers(void) {
/*
 * Some of these signals may not be supported on some platforms. I have
 * replaced tests that indicated which were believed present on Windows
 * and LINUX with more generic tests... clumsier but more generic I hope.
 */
#ifdef SIGQUIT
  signal(SIGQUIT,SIG_DFL);
#endif
#ifdef SIGHUP
  signal(SIGHUP,SIG_DFL);
#endif
#ifdef SIGTSTP
  signal(SIGTSTP,SIG_IGN);
#endif
#ifdef SIGPIPE
  signal(SIGPIPE,SIG_DFL);
#endif
#ifdef SIGCHLD
  signal(SIGCHLD,SIG_DFL);
#endif
#ifdef SIGBUS
  signal(SIGBUS,SIG_DFL);
#endif
  signal(SIGINT,SIG_DFL);
  signal(SIGILL,SIG_DFL);
  signal(SIGSEGV,SIG_DFL);
  signal(SIGTERM,SIG_DFL);
}
/* end of redchild.c */
