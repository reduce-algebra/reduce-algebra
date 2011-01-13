/* wxpsl.cpp                                Copyright (C) Codemist Ltd 2011 */

/*
 * This code borrows from the redfront package by Dolzmann and Sturm,
 * but rather than using readline and their character based interface
 * it uses (wx)fwin to provide a windowed and unicode-friendly terminal.
 */


/**************************************************************************
 * Copyright (C) 2011, Codemist Ltd.                     A C Norman       *
 *      parts of the code Copyright Andreas Dolzmann and Thomas Sturm     *
 *      with earlier development by Chris Cannam and Winfried Neun.       *
 *                                                                        *
 * Redistribution and use in source and binary forms, with or without     *
 * modification, are permitted provided that the following conditions are *
 * met:                                                                   *
 *                                                                        *
 *     * Redistributions of source code must retain the relevant          *
 *       copyright notice, this list of conditions and the following      *
 *       disclaimer.                                                      *
 *     * Redistributions in binary form must reproduce the above          *
 *       copyright notice, this list of conditions and the following      *
 *       disclaimer in the documentation and/or other materials provided  *
 *       with the distribution.                                           *
 *                                                                        *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS    *
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT      *
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS      *
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE         *
 * COPYRIGHT OWNERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,   *
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,   *
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS  *
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND *
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR  *
 * TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF     *
 * THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH   *
 * DAMAGE.                                                                *
 *************************************************************************/

/* Signature: 181d6b0c 13-Jan-2011 */


//
// See the file "fwindemo.c" for a smaller example of how to use fwin. This
// code builds on that so that instead of having a minimal echo program
// run under fwin I launch all of PSL.
//

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#ifdef WIN32
#include <windows.h>
#endif

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <errno.h>
#include <ctype.h>
#include <string.h>
#include <libgen.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <signal.h>

#if defined HAVE_WAIT_H
#include <wait.h>
#elif defined HAVE_SYS_WAIT_H
#include <sys/wait.h>
#endif


#include "wxfwin.h"

#define LONGEST_LEGAL_FILENAME 1024

#ifdef WIN32
#define DIRCHAR '\\'
#define EXEEXT  ".exe"
#else
#define DIRCHAR '/'
#define EXEEXT  ""
#endif

static char bpsl_binary[LONGEST_LEGAL_FILENAME];
static char reduce_image[LONGEST_LEGAL_FILENAME];
static char memory_control[LONGEST_LEGAL_FILENAME];

int fwin_main(int argc, char **argv)
{
    int memory = 0;
    int i = strlen(programDir), j;
    for (j=0; j<3; j++)
    {   i--;
        while (i > 0 && (programDir[i] != '/' && programDir[i] != '\\')) i--;
    }
    sprintf(bpsl_binary, "%.*s%cpslbuild%c%s%cpsl%cbpsl%s",
        i, programDir, DIRCHAR, DIRCHAR, PSLBUILD, DIRCHAR, DIRCHAR, EXEEXT);
    sprintf(reduce_image, "%.*s%cpslbuild%c%s%cred%creduce.img",
        i, programDir, DIRCHAR, DIRCHAR, PSLBUILD, DIRCHAR, DIRCHAR);
    sprintf(memory_control, "%.*s%cpslbuild%c%s%cpsl%c64",
        i, programDir, DIRCHAR, DIRCHAR, PSLBUILD, DIRCHAR, DIRCHAR);
    FWIN_LOG("bin: %s\n", bpsl_binary);
    FWIN_LOG("img: %s\n", reduce_image);
    FWIN_LOG("64:  %s\n", memory_control);
    {
// Here I need to check if a file called "64" is present. I do not
// care at all about access rights or its contents, just whether it
// exists!
        struct stat file_info;
        if (stat(bpsl_binary, &file_info) != 0 ||
            (file_info.st_mode & S_IXUSR) != S_IXUSR ||
            stat(reduce_image, &file_info) != 0 ||
            (file_info.st_mode & S_IRUSR) != S_IRUSR)
        {   fwin_printf("bpsl executable or reduce image not available\n");
            fwin_exit(EXIT_FAILURE);
        }
// If the user gave an explicit memory option that should override the
// default I set up here.
        if (stat(memory_control, &file_info) == 0) // file "64" was present
            strcpy(memory_control, "2000");
        else strcpy(memory_control, "16000000");
    }

#ifdef WIN32
// in case I get to send things to the console I will try setting that
// to process UTF8.
    int oldCP = GetConsoleOutputCP();
    SetConsoleOutputCP(CP_UTF8);
    fwin_printf("old = %d u-umlaut = \xc3\xbc \n", oldCP);
    fwin_ensure_screen();
// The procedures used here are documented on Microsoft's web-site, and
// the code I include here is closely based on their sample that shows how
// to create a process with pipes attached to its standard streams.
    HANDLE g_hChildStd_IN_Rd = NULL;
    HANDLE g_hChildStd_IN_Wr = NULL;
    HANDLE g_hChildStd_OUT_Rd = NULL;
    HANDLE g_hChildStd_OUT_Wr = NULL;
    SECURITY_ATTRIBUTES saAttr;
// Set the bInheritHandle flag so pipe handles are inherited.
    saAttr.nLength = sizeof(SECURITY_ATTRIBUTES);
    saAttr.bInheritHandle = TRUE;
    saAttr.lpSecurityDescriptor = NULL;
// Create a pipe for the child process's STDOUT.

    if (!CreatePipe(&g_hChildStd_OUT_Rd, &g_hChildStd_OUT_Wr, &saAttr, 0))
    {   fwin_printf("Failed to create STDOUT pipe\n");
        fwin_exit(EXIT_FAILURE);
    }
// Ensure the read handle to the pipe for STDOUT is not inherited.
    if (!SetHandleInformation(g_hChildStd_OUT_Rd, HANDLE_FLAG_INHERIT, 0))
    {   fwin_printf("Failed to set handle info in STDOUT handle\n");
        fwin_exit(EXIT_FAILURE);
    }
// Create a pipe for the child process's STDIN.
    if (!CreatePipe(&g_hChildStd_IN_Rd, &g_hChildStd_IN_Wr, &saAttr, 0))
    {   fwin_printf("Failed to create STDIN pipe\n");
        fwin_exit(EXIT_FAILURE);
    }
// Ensure the write handle to the pipe for STDIN is not inherited.
    if (!SetHandleInformation(g_hChildStd_IN_Wr, HANDLE_FLAG_INHERIT, 0))
    {   fwin_printf("Failed to set handle info in STDIN handle\n");
        fwin_exit(EXIT_FAILURE);
    }

// Create a child process that uses the previously created pipes for STDIN and STDOUT.
//
// With Windows I will always create the sub-process via a command line
// and it will split that up into individual arguments when it is ready to.
//
    char *cmdLine = (char *)malloc(strlen(bpsl_binary) +
                                   strlen(reduce_image) +
                                   strlen(memory_control) + 16);
    if (cmdLine  == NULL)
    {   fwin_printf("failed to allocate space for command line\n");
        fwin_exit(EXIT_FAILURE);
    }
    sprintf(cmdLine, "\"%s\" -td %s -f \"%s\"",
            bpsl_binary, memory_control, reduce_image);
    PROCESS_INFORMATION piProcInfo;
    STARTUPINFO siStartInfo;
    BOOL bSuccess = FALSE;

// Set up members of the PROCESS_INFORMATION structure.
    ZeroMemory(&piProcInfo, sizeof(PROCESS_INFORMATION));

// Set up members of the STARTUPINFO structure.
// This structure specifies the STDIN and STDOUT handles for redirection.

    ZeroMemory(&siStartInfo, sizeof(STARTUPINFO));
    siStartInfo.cb = sizeof(STARTUPINFO);
// Note that I could get back stderr and stout as separate channels.
    siStartInfo.hStdError  = g_hChildStd_OUT_Wr;
    siStartInfo.hStdOutput = g_hChildStd_OUT_Wr;
    siStartInfo.hStdInput  = g_hChildStd_IN_Rd;
    siStartInfo.dwFlags |= STARTF_USESTDHANDLES;

// Create the child process.
    bSuccess = CreateProcess(NULL, // application name
        cmdLine,       // command line
        NULL,          // process security attributes
        NULL,          // primary thread security attributes
        TRUE,          // handles are inherited
        0,             // creation flags
        NULL,          // use parent's environment
        NULL,          // use parent's current directory
        &siStartInfo,  // STARTUPINFO pointer
        &piProcInfo);  // receives PROCESS_INFORMATION

// If an error occurs, exit the application.
    if (!bSuccess)
    {   fwin_printf("Failed to create child process\n");
        fwin_exit(EXIT_FAILURE);
    }
    // Close handles to the child process and its primary thread.
    // Some applications might keep these handles to monitor the status
    // of the child process, for example.

//    CloseHandle(piProcInfo.hProcess);
//    CloseHandle(piProcInfo.hThread);




#else
    int MeToReduce[2];
    if (pipe(MeToReduce) < 0)
    {   fwin_printf("failed to create pipe MeToReduce\n");
        fwin_exit(EXIT_FAILURE);
    }

    int ReduceToMe[2];
    if (pipe(ReduceToMe) < 0)
    {   fwin_printf("failed to create pipe ReduceToMe\n");
        fwin_exit(EXIT_FAILURE);
    }

    int reduceProcessId;
    if ((reduceProcessId = fork()) < 0) // Failure
    {   fwin_printf("cannot fork()");
        fwin_exit(EXIT_FAILURE);
    }
    else if (reduceProcessId == 0)      // Child process
    {   char **nargv = (char **)malloc(6*sizeof(char *));
        setsid();
//      sig_removeHandlers();     // I will think about handlers later on.
//      signal(SIGTSTP,SIG_IGN);
// Re-plumb the pipes to link to stdin & stdout.
        close(MeToReduce[1]);
        close(ReduceToMe[0]);
        FWIN_LOG("child: MeToReduce[0]= %d, ReduceToMe[1] = %d\n",
	                 MeToReduce[0], ReduceToMe[1]);
        dup2(MeToReduce[0],STDIN_FILENO);
        dup2(ReduceToMe[1],STDOUT_FILENO);
//      dup2(ReduceToMe[1],STDERR_FILENO);    // ??????
        close(MeToReduce[0]);
        close(ReduceToMe[1]);

        FWIN_LOG("child: entering create_call\n");

        nargv[0] = bpsl_binary;
        nargv[1] = (char *)"-td";
        nargv[2] = memory_control;
        nargv[3] = (char *)"-f";
        nargv[4] = reduce_image;
        nargv[5] = NULL;
//    for (i = xargstart; i < argc; i++)
//        nargv[i - xargstart + 5] = argv[i];
//    nargv[argc - xargstart + 5] = (char *)0;

        for (i = 0; i <= 5; i++)
            FWIN_LOG("child: argv[%d]=%s\n",i,nargv[i]);
        FWIN_LOG("child: right before execv()\n");
        execv(nargv[0], nargv);
        fwin_printf("Unable to perform execv(%s)\n", bpsl_binary);
        fwin_exit(EXIT_FAILURE);
    }
#endif // Win32 vs Unix/Linux/MacOSX child processing

// I am now in the parent... I need to read from the relevant handle
// and display stuff from it to the screen.

#ifdef WIN32
    DWORD n;
    const char *loader = "load_package redfront,utf8$\n";
    if (WriteFile(g_hChildStd_IN_Wr, loader, strlen(loader), &n, NULL) == 0)
    {   fwin_printf("Unable to send to child process\n");
        fwin_exit(EXIT_FAILURE);
    }

#define BUFSIZE 256
    for (;;)
    {   char buf[BUFSIZE], prompt[80];
        int prevc = 0, c, j = 0, k;
// At present I do not recover well when the child process terminates - the
// call to ReadFile here can merely hang. That is BAD.
        if (ReadFile(g_hChildStd_OUT_Rd, buf, BUFSIZE, &n, NULL) == 0 ||
            n == 0) break;
        while (j<(int)n && (c = buf[j++]) != 0x01)
        {   if (c == 0x0d) fwin_putchar('\n');
            else if (c == 0x0a)
            {   if (prevc != 0x0d) fwin_putchar('\n');
            }
// Characters 3 and 4 are used by redfront but I believe I can
// safely discard them here.
            else if (c != 0x03 && c != 0x04) fwin_putchar(c);
            prevc = c;
        }
        if (c == 0x01)
        {   k = 0;
// There is a messy issue in that the 0x02 may be in the NEXT buffer-full
// of stuff. I will ignore that issue just for now.
            while (j<(int)n && (c = buf[j++]) != 0x02)
                prompt[k++] = c;
            prompt[k] = 0;
            fwin_set_prompt(prompt);
// Just after a prompt there ought not to be anything else in the buffer, so I
// can re-use it.
            k = 0;
            while ((c = fwin_getchar()) != '\n' && c != EOF)
                if (k < BUFSIZE-1) buf[k++] = c;
            buf[k] = 0;
            FWIN_LOG("Sending line <%s>\n", buf);
            buf[k++] = 0x0a;  // send a newline too
            if (WriteFile(g_hChildStd_IN_Wr, buf, k, &n, NULL) == 0)
            {   fwin_printf("Unable to send to child process\n");
                fwin_exit(EXIT_FAILURE);
            }
        }
    }

#else


    const char *loader = "load_package redfront,utf8$\n";
// Note that this initial command to load the UTF8 package will have
// a prompt before it, but that will be a plain undecorated prompt
// that will not be noticed as anything special by the code here.
    write(MeToReduce[1], loader, strlen(loader));

#define BUFSIZE 256
    for (;;)
    {   char buf[BUFSIZE], prompt[80];
        int n, prevc = 0, c, j = 0, k;
        n = read(ReduceToMe[0], buf, BUFSIZE);
        while (j<(int)n && (c = (buf[j++] & 0xff)) != 0x01)
        {
            FWIN_LOG("see char %.2x\n", c);
            if (c == 0x0d) fwin_putchar('\n');
            else if (c == 0x0a)
            {   if (prevc != 0x0d) fwin_putchar('\n');
            }
// Characters 3 and 4 are used by redfront but I believe I can
// safely discard them here.
            else if (c != 0x03 && c != 0x04) fwin_putchar(c);
            prevc = c;
        }
        if (c == 0x01)
        {   k = 0;
// There is a messy issue in that the 0x02 may be in the NEXT buffer-full
// of stuff. I will ignore that issue just for now.
            while (j<(int)n && (c = buf[j++]) != 0x02)
                prompt[k++] = c;
            prompt[k] = 0;
            FWIN_LOG("Prompt observed to be <%s>\n", prompt);
            fwin_set_prompt(prompt);
// Just after a prompt there ought not to be anything else in the buffer, so I
// can re-use it.
            k = 0;
            FWIN_LOG("About to read a line\n");
            while ((c = fwin_getchar()) != '\n' && c != EOF && c != '?')
            {   FWIN_LOG("char = %.2x\n", c);
                if (k < BUFSIZE-1) buf[k++] = c;
            }
            buf[k] = 0;
            FWIN_LOG("Sending line <%s>\n", buf);
            buf[k++] = '\n';  // send a newline too
            write(MeToReduce[1], buf, k);
        }
    }

#endif

    fwin_printf("Done\n");
    return 0;
}

//
// The following starts up fwin and in due course runs fwin_main
// within the console window that it creates.
//

int main(int argc, char *argv[])
{
    return fwin_startup(argc, argv, fwin_main);
}

//
// End of the generic part.
//



// What follows is residual stuff left over from looking at redfront.



void print_usage(char name[]) {
    fprintf(stderr,
	    "usage: %s [-bhuvV] [[-m] NUMBER[kKmM]]\n",name);
}

void print_help(char name[]) {

  fprintf(stderr,"A REDUCE frontend using fwin\n\n");

  print_usage(name);

  fprintf(stderr,"       -h\t\tthis help message\n");
  fprintf(stderr,"       -m NUMBER [kKmM]\tmemory allocation in Bytes [KB|MB]\n");
  fprintf(stderr,"       -v, -V\t\tverbose\n\n");

  fprintf(stderr,"Examples: %s -v\n",name);
  fprintf(stderr,"          %s -m 96m.\n\n",name);
}



void sig_killChild(void) {
#ifdef SIGCHLD
  signal(SIGCHLD,SIG_IGN);
#endif
#if 0
  kill(reduceProcessId,SIGTERM);
#endif
}



void sig_sigGen(int arg) {
  FWIN_LOG("sig_sigGen(%d)\n",arg);
  sig_killChild();
  switch (arg) {
#ifdef SIGQUIT
  case SIGQUIT:
#endif
#ifdef SIGHUP
  case SIGHUP:
#endif
#ifdef SIGTERM
  case SIGTERM:
#endif

//    if (verbose) {
//      printf("REDFRONT normally exiting on signal %d (%s)\n",arg,sig_identify(arg));
//    }
    exit(0);
  default:
//    if (verbose) {
//      printf("***** REDFRONT exiting on unexpected signal %d (%s)\n",
//	     arg,sig_identify(arg));
//    }
    exit(EXIT_FAILURE);
  }
}

void sig_skipUntilString(int handle,const char string[]) {
  char *buffer;
  int len;
  int i;

  len = strlen(string);
  buffer = (char *)malloc(len * sizeof(char) + 1);
  read(handle,buffer,len);

  while (strcmp(buffer,string) != 0) {
    FWIN_LOG("sig_skipUntilString(): buffer=|%s|\n",buffer);
    for (i=0; i < len-1; i++)
      buffer[i] = buffer[i+1];
    read(handle,buffer+len-1,1);
  }
  free(buffer);
}

void sig_sigChld(int arg) {
  FWIN_LOG("sig_sigChld(): Reduce process terminated\n");
//  if (verbose) {
//    printf("REDFRONT normally exiting on signal %d (%s)\n",arg,sig_identify(arg));
//  }
  exit(0);
}

void sig_sigTstp(int arg) {
#ifdef SIGSTOP
// Not having SIGSTOP looks bad!
  kill(0,SIGSTOP);
#endif
}

void sig_installHandlers(void) {
#ifdef SIGQUIT
  signal(SIGQUIT,sig_sigGen);
#endif
#ifdef SIGHUP
  signal(SIGHUP,sig_sigGen);
#endif
#ifdef SIGINT
  signal(SIGINT, sig_sigGen);
#endif
#ifdef SIGILL
  signal(SIGILL,sig_sigGen);
#endif
#ifdef SIGTSTP
  signal(SIGTSTP,sig_sigTstp);
#endif
#ifdef SIGBUS
  signal(SIGBUS,sig_sigGen);
#endif
#ifdef SIGSEGV
  signal(SIGSEGV,sig_sigGen);
#endif
#ifdef SIGPIPE
  signal(SIGPIPE,sig_sigGen);
#endif
#ifdef SIGCHLD
  signal(SIGCHLD,sig_sigChld);
#endif
#ifdef SIGTERM
  signal(SIGTERM,sig_sigGen);
#endif
}

void sig_removeHandlers(void) {
#ifdef SIGQUIT
  signal(SIGQUIT,SIG_DFL);
#endif
#ifdef SIGHUP
  signal(SIGHUP,SIG_DFL);
#endif
#ifdef SIGINT
  signal(SIGINT,SIG_DFL);
#endif
#ifdef SIGILL
  signal(SIGILL,SIG_DFL);
#endif
#ifdef SIGTSTP
  signal(SIGTSTP,SIG_DFL);
#endif
#ifdef SIGBUS
  signal(SIGBUS,SIG_DFL);
#endif
#ifdef SIGSEGV
  signal(SIGSEGV,SIG_DFL);
#endif
#ifdef SIGPIPE
  signal(SIGPIPE,SIG_DFL);
#endif
#ifdef SIGCHLD
  signal(SIGCHLD,SIG_DFL);
#endif
#ifdef SIGTERM
  signal(SIGTERM,SIG_DFL);
#endif
}

const char *sig_identify(int signo) {
// The list of signals is taken from the sigaction man page: "The
// following is a list of all signals with names as in the include
// file <signal.h>
  switch(signo) {
#ifdef SIGHUP
  case SIGHUP:    return "SIGHUP";
#endif
#ifdef SIGINT
  case SIGINT:    return "SIGINT";
#endif
#ifdef SIGQUIT
  case SIGQUIT:   return "SIGQUIT";
#endif
#ifdef SIGILL
  case SIGILL:    return "SIGILL";
#endif
#ifdef SIGTRAP
  case SIGTRAP:   return "SIGTRAP";
#endif
#ifdef SIGABRT
  case SIGABRT:   return "SIGABRT";
#endif
#ifdef SIGEMT
  case SIGEMT:    return "SIGEMT";
#endif
#ifdef SIGFPE
  case SIGFPE:    return "SIGFPE";
#endif
#ifdef SIGKILL
  case SIGKILL:   return "SIGKILL";
#endif
#ifdef SIGBUS
  case SIGBUS:    return "SIGBUS";
#endif
#ifdef SIGSEGV
  case SIGSEGV:   return "SIGSEGV";
#endif
#ifdef SIGSYS
  case SIGSYS:    return "SIGSYS";
#endif
#ifdef SIGPIPE
  case SIGPIPE:   return "SIGPIPE";
#endif
#ifdef SIGALRM
  case SIGALRM:   return "SIGALRM";
#endif
#ifdef SIGTERM
  case SIGTERM:   return "SIGTERM";
#endif
#ifdef SIGURG
  case SIGURG:    return "SIGURG";
#endif
#ifdef SIGSTOP
  case SIGSTOP:   return "SIGSTOP";
#endif
#ifdef SIGTSTP
  case SIGTSTP:   return "SIGTSTP";
#endif
#ifdef SIGCONT
  case SIGCONT:   return "SIGCONT";
#endif
#ifdef SIGCHLD
  case SIGCHLD:   return "SIGCHLD";
#endif
#ifdef SIGTTIN
  case SIGTTIN:   return "SIGTTIN";
#endif
#ifdef SIGTTOU
  case SIGTTOU:   return "SIGTTOU";
#endif
#ifdef SIGIO
  case SIGIO:     return "SIGIO";
#endif
#ifdef SIGXCPU
  case SIGXCPU:   return "SIGXCPU";
#endif
#ifdef SIGXFSZ
  case SIGXFSZ:   return "SIGXFSZ";
#endif
#ifdef SIGVTALAM
  case SIGVTALRM: return "SIGVTALRM";
#endif
#ifdef SIGPROF
  case SIGPROF:   return "SIGPROF";
#endif
#ifdef SIGWINCH
  case SIGWINCH:  return "SIGWINCH";
#endif
#ifdef SIGINFO
  case SIGINFO:   return "SIGINFO";
#endif
#ifdef SIGUSR1
  case SIGUSR1:   return "SIGUSR1";
#endif
#ifdef SIGUSR2
  case SIGUSR2:   return "SIGUSR2";
#endif
  }
  return "unknown signal";
}


// end of wxpsl.cpp
