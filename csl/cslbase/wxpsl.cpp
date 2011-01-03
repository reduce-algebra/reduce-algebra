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

/* Signature: 712f356a 28-Feb-2010 */


/*
 * See the file "fwindemo.c" for a smaller example of how to use fwin. This
 * code builds on that so that instead of having a minimal echo program
 * run under fwin I launch all of PSL.
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#ifdef WIN32
#define USE_PIPES 1
#endif

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <errno.h>
#include <ctype.h>
#include <string.h>
#include <libgen.h>
#include <sys/types.h>
#ifndef USE_PIPES
#include <sys/socket.h>
#include <sys/ioctl.h>
#endif
#include <fcntl.h>
#include <unistd.h>
#include <signal.h>

#if defined HAVE_WAIT_H
#include <wait.h>
#elif defined HAVE_SYS_WAIT_H
#include <sys/wait.h>
#endif


#include "wxfwin.h"

int fwin_main(int argc, char **argv)
{
    char line[1000];
    fwin_printf("Type lines. Type \"quit\" to exit\n");
    fwin_ensure_screen();
    for (;;)
    {   int i = 0, c;
        while ((c = fwin_getchar()) != EOF && c != '\n')
        {   if (i < (int)sizeof(line)-10) line[i++] = c;
        }
        line[i] = 0;
        fwin_printf("Line was <%s>\n", line);
        if (c == EOF || strcmp(line, "quit") == 0) break;
    }
    fwin_printf("Done\n");
    /* fwin_exit(0); */
    return 0;
}

/*
 * The following starts up fwin and in due course runs fwin_main
 * within the console window that it creates.
 */

int main(int argc, char *argv[])
{
    return fwin_startup(argc, argv, fwin_main);
}

/*
 * End of the generic part.
 */





struct strbuf {
  char c;
  struct strbuf *next,*prev;
};

struct oStrl {
  char *thisone;
  struct oStrl* next;
};

typedef struct oStrl *strl;

int vbprintf(const char *,...);
void rf_exit(int);

void parent(void);
void send_reduce(char *);

void child(int,char **,char **);

char *line_read(char *);
char *line_quit(const char *);
void line_cleanup_after_signal(void);

void sig_sigInt(int);
void sig_installHandlers(void);
void sig_removeHandlers(void);
void sig_killChild(void);

struct strbuf *addchar(char,struct strbuf *);
struct strbuf *remtail(struct strbuf *,struct strbuf *);
void prtbuf(struct strbuf *);
strl strl_cadd(strl,char *);
strl strl_delete(strl);

int deb_fprintf(FILE *,const char *,...);

/* Exportable variables */

int reduceProcessID;

int MeToReduce[2];
int ReduceToMe[2];

int verbose = 0;
const char *memory=NULL;
int xargstart;

void parse_args(int,char **);
void init_channels(void);
int parse_colarg(char *);
char *parse_memarg(char *,char *);
void print_usage(char *);
void print_help(char *);
int vbprintf(const char *,...);
void rf_exit(int);
#define SYSMAXBUFFER 198

#define READING_OUTPUT 1
#define READING_PROMPT 2
#define FINISHED 0

extern int debug;
extern int verbose;

void parent(void);
void atoploop(void);
char *load_package(const char *);
void read_until_first_prompt(char *);
char *read_valid_line(char *);
int is_too_long(const char *);
int badline(const char *);
void send_reduce(char *);
void read_until_prompt(char *);










int wxpsl_main(int argc,char **argv,char **envp)
{
    parse_args(argc,argv);
    init_channels();

#if OLD
    if ((reduceProcessID = fork()) = 0)
    {   /* I am the parent */
        if (reduceProcessID < 0)  /* Failure */
        {   perror("cannot fork()");
            rf_exit(-1);
        }
        FWIN_LOG("parent: process alive - fork()=%d\n",reduceProcessID);
        parent();
    }
    else
    {  /* I am the child */
        FWIN_LOG("child: process alive - fork()=%d\n",reduceProcessID);
        child(argc,argv,envp);
    }
#endif

  return -1;
}

void parse_args(int argc,char **argv) {
  int c;
  extern char *optarg;
  extern int optind;
  const char *os;
  int errflg=0;

  os = ":hvVm:";

  while ((c = getopt(argc, argv, os)) != EOF)
    switch (c) {
    case 'h':
      print_help(argv[0]);
      rf_exit(1);
      break;
    case 'v':
    case 'V':
      verbose = 1;
      break;
    case 'm':
      memory = optarg;
      break;
    case '?':
      errflg++;
    }

  if (errflg) {
    print_usage(argv[0]);
    rf_exit(2);
  }

  if (strcmp(argv[optind - 1],"--") == 0) {
    // <options> + "--"
    xargstart = optind;
  } else if (memory == NULL && optind == argc - 1) {
    // <options> + <memarg>
    memory = argv[optind];
    xargstart = argc;
  } else if (memory == NULL &&
	   optind < argc - 1 && strcmp(argv[optind + 1],"--") == 0) {
    // <options> + <memarg> + "--"
    memory = argv[optind];
    xargstart = optind + 2;
  } else if (optind == argc) {
    // <options>
    xargstart = argc;
  } else {
    print_usage(argv[0]);
    rf_exit(2);
  }

}

char *parse_memarg(char *argstr,char *name) {
  char *nargv2;
  char lchar;
  int i;

  i = strlen(argstr) - 1;
  lchar = tolower(argstr[i]);
  if (!isdigit(lchar) && lchar != 'm' && lchar != 'k') {
    print_usage(name);
    rf_exit(1);
  }
  i--;

  for (; i >= 0; i--)
    if (!isdigit(argstr[i])) {
      print_usage(name);
      rf_exit(1);
    }

  if (lchar == 'm' ) {
    nargv2 = (char *)malloc(strlen(argstr)-1+6+1);
    strncpy(nargv2,argstr,strlen(argstr)-1);
    nargv2[strlen(argstr)-1] = '\0';
    sprintf(nargv2,"%s000000",nargv2);
    return nargv2;
  }

  if (lchar == 'k' ) {
    nargv2 = (char *)malloc(strlen(argstr)-1+3+1);
    strncpy(nargv2,argstr,strlen(argstr)-1);
    nargv2[strlen(argstr)-1] = '\0';
    sprintf(nargv2,"%s000",nargv2);
    return nargv2;
  }

  return argstr;
}

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

void init_channels(void) {
#if 0
#ifdef USE_PIPES
    if (pipe(MeToReduce) < 0) {
      perror("failed to create pipe MeToReduce\n");
      sig_killChild();
      rf_exit(-1);
    }
    if (pipe(ReduceToMe) < 0) {
      perror("failed to create pipe ReduceToMe\n");
      sig_killChild();
      rf_exit(-1);
    }
#else
    if (socketpair(AF_UNIX, SOCK_STREAM, 0, MeToReduce) < 0) {
      perror("cannot open socket MeToReduce");
      sig_killChild();
      rf_exit(-1);
    }
    if (socketpair(AF_UNIX, SOCK_STREAM, 0, ReduceToMe) < 0) {
      perror("cannot open socket ReduceToMe");
      sig_killChild();
      rf_exit(-1);
    }
  }
#endif
#endif
}

int vbprintf(const char *msg,...) {
  int ecode=0;
  va_list ap;

  if (!verbose)
    return 0;

  va_start(ap,msg);
  ecode = vprintf(msg,ap);
  va_end(ap);

  return ecode;
}

void rf_exit(int ecode) {
  exit(ecode);
}

void parent(void) {
  sig_installHandlers();

#ifdef HAVE_SETLINEBUF
  setlinebuf(stdout);
#endif

  close(MeToReduce[0]);
  close(ReduceToMe[1]);

  FWIN_LOG("child: MeToReduce[1]= %d, ReduceToMe[0] = %d\n",
	   MeToReduce[1], ReduceToMe[0]);

  atoploop();
}

void atoploop(void) {
  char der_prompt[50],old_prompt[50];
  char *line = (char *)NULL;


  read_until_first_prompt(der_prompt);

  FWIN_LOG("parent: read first prompt\n");

  while (1) {

    signal(SIGINT,SIG_IGN);

    line = read_valid_line(der_prompt);

#if 0
    signal(SIGINT,sig_sigInt);
#endif

    send_reduce(line);

    strcpy(old_prompt,der_prompt);

    read_until_prompt(der_prompt);

  }
}

char *load_package(const char *package) {
  char *cmd;
  int len;

  len = strlen(package)+strlen("load_package $");
  cmd = (char *)malloc(len + 1);
  sprintf(cmd,"load_package %s$",package);
  send_reduce(cmd);

  FWIN_LOG("parent: sending %s\n",cmd);

  return cmd;
}

void read_until_first_prompt(char der_prompt[]) {
  int status=READING_OUTPUT;
  char buffer[1000];
  int ncharread;
  int ii;
  int pii=0;
  char ch;
  struct strbuf *b=(struct strbuf *)0,*t=(struct strbuf *)0;


  while(status != FINISHED) {
    ncharread = read(ReduceToMe[0],buffer,1000);
    for (ii=0; ii < ncharread; ii++) {
      ch = buffer[ii];
      if (ch == (char) 0x01 ) {
	status = READING_PROMPT;
	pii = 0;
      } else if (ch == (char) 0x02) {
	status = FINISHED;
      }
      if (status == READING_OUTPUT) {
	b = addchar(ch,b);
      } else if (status == READING_PROMPT) {
	if ((int) ch > 31) {
	  der_prompt[pii++] = ch;
	  t = addchar(ch,t);
	}
      } else {	/* (status == FINISHED) */
	der_prompt[pii] = 0x00;
      }
    }
  }
  b = remtail(t,b);
  prtbuf(b);
  fflush(stdout);
}

char *read_valid_line(char der_prompt[]) {
  char orig_prompt[50];
  char *line;

  strcpy(orig_prompt,der_prompt);

  line = line_read(der_prompt);

  if (line)
    while (is_too_long(line)) {
      line = line_read(der_prompt);
    }
  else {
    if (strcmp(orig_prompt,"?") == 0) {
      line = line_quit("n");
    } else if (orig_prompt[strlen(orig_prompt) - 2] == '>') {
      line = line_quit("q");
    } else if (orig_prompt[strlen(orig_prompt) - 2] == ':') {
      line = line_quit("quit;");
    } else if (orig_prompt[strlen(orig_prompt) - 2] == '*') {
      line = line_quit("quit;");
    } else {
      line = line_quit("");
    }
  }

  strcpy(der_prompt,orig_prompt);

  return line;
}

int is_too_long(const char line[]) {
  if (badline(line)) {
    printf("redfront: overlong input line\n");
    return 1;
  }
  return 0;
}

int badline(const char line[]) {
  int i=0,n=0;

  while (n <= SYSMAXBUFFER && line[i]) {
    if (line[i] == 0x0a)
      n = 0;
    i++;
    n++;
  }
  return (n > SYSMAXBUFFER);
}


void send_reduce(char line[]) {
  char dummy_prompt[50];
  char ch;
  int ii;

  FWIN_LOG("parent: entering send_reduce() ... line=%s\n",line);

  if (line == (char *)NULL) {
    ch=0x04;
    write(MeToReduce[1],&ch,1);
    ch = 0x0a;
    write(MeToReduce[1],&ch,1);
  } else {
    for (ii=0; line[ii] != 0; ii++) {
      ch = line[ii] & 0x7f;
      write(MeToReduce[1],&ch,1);
      if (ch == 0x0a) {
	strcpy(dummy_prompt,"dummy_prompt");
	read_until_prompt(dummy_prompt);
      }
    }
    ch = 0x0a;
    write(MeToReduce[1],&ch,1);
  }

  FWIN_LOG("parent: ... leaving send_reduce()\n");
}

void read_until_prompt(char der_prompt[]){
  int status=READING_OUTPUT;
  char buffer[1000];
  int ncharread;
  int ii;
  int pii=0;
  char ch;

  FWIN_LOG("parent: entering read_until_prompt() ... der_prompt=%s\n",
	   der_prompt);

  while(status != FINISHED) {
    ncharread = read(ReduceToMe[0],buffer,1000);
    for (ii=0; ii < ncharread; ii++) {
      ch = buffer[ii];
      if (ch == (char) 0x01) {
	status = READING_PROMPT;
	pii = 0;
      } else if (ch == (char) 0x02) {
	status = FINISHED;
      }
      if (status == READING_OUTPUT) {
	printf("%c",ch);
      } else if (status == READING_PROMPT) {
	if ((int) ch > 31)
	  der_prompt[pii++] = ch;
      } else {	/* (status == FINISHED) */
	der_prompt[pii] = 0x00;
      }
    }
    fflush(stdout);
  }

  FWIN_LOG("parent: ... leaving read_until_prompt()\n");
}


#define BPSL   "psl_surrogate"
#define REDIMG "psl_image_surrogate"

void create_call(int argc,char **argv,char **nargv)
{
    int tempfd;
    int i;

    FWIN_LOG("child: entering create_call\n");

    if ((tempfd = open(BPSL,O_RDONLY)) == -1)
    {  /* Does not check x */
        char errstr[1024];
        sprintf(errstr,"cannot open %s",BPSL);
        perror(errstr);
        rf_exit(-1);
    }
    else close(tempfd);

    if ((tempfd = open(REDIMG,O_RDONLY)) == -1)
    {   char errstr[1024];
        sprintf(errstr,"cannot open %s",REDIMG);
        perror(errstr);
        rf_exit(-1);
    }
    else close(tempfd);

    if (strcmp(memory,"0") == 0)
    {   char *sixtyfour;
        int i;
        /* malloc one more in case the name of bpsl is only 1 char: */
        sixtyfour = (char *)malloc((strlen(BPSL)+1+1)*sizeof(char));
        strcpy(sixtyfour,BPSL);
        i = strlen(BPSL);
        while (sixtyfour[i-1] != '/')
	i--;
        sixtyfour[i++] = '6';
        sixtyfour[i++] = '4';
        sixtyfour[i] = (char)0;
        FWIN_LOG("child: checking for %s ... ",sixtyfour);
        if ((tempfd = open(sixtyfour,O_RDONLY)) != -1)
        {   close(tempfd);
	    FWIN_LOG("positive\n");
	    memory = "2000";
        }
        else
        {   FWIN_LOG("negative\n");
	    memory = "16000000";
        }
    }

    nargv[0] = (char *)BPSL;
    nargv[1] = (char *)"-td";
    nargv[2] = (char *)memory;
    nargv[3] = (char *)"-f";
    nargv[4] = (char *)REDIMG;
    for (i = xargstart; i < argc; i++)
        nargv[i - xargstart + 5] = argv[i];
    nargv[argc - xargstart + 5] = (char *)0;

    for (i = 0; i <= argc - xargstart + 5; i++)
        FWIN_LOG("child: argv[%d]=%s\n",i,nargv[i]);

    FWIN_LOG("child: leaving create_call\n");
}

void child(int argc,char *argv[],char *envp[])
{
  char ** nargv;

  nargv = (char **)malloc((argc - xargstart + 6)*sizeof(char *));

#if 0
  setsid();
#endif

  sig_removeHandlers();

#ifdef SIGTSTP
  signal(SIGTSTP,SIG_IGN);
#endif

  close(MeToReduce[1]);
  close(ReduceToMe[0]);

  FWIN_LOG("child: MeToReduce[0]= %d, ReduceToMe[1] = %d\n",
	      MeToReduce[0], ReduceToMe[1]);

  dup2(MeToReduce[0],STDIN_FILENO);
  dup2(ReduceToMe[1],STDOUT_FILENO);

  close(MeToReduce[0]);
  close(ReduceToMe[1]);

  create_call(argc,argv,nargv);

  FWIN_LOG("child: right before execv()\n");

  execv(nargv[0],nargv);

  {
    char errstr[1024];
    sprintf(errstr,"cannot execv() %s",nargv[0]);
    perror(errstr);
  }
  rf_exit(-1);
}

char *line_read(char *prompt) {
  static char *line=NULL;
  if (line) 
    free(line);
#if 0
  line = readline(prompt);
#endif
  return line;
}

char *line_quit(const char *quit)
{
    static char *line=NULL;
    if (line != NULL) free(line);
    line = (char *)malloc((strlen(quit) + 2)* sizeof(char));
    sprintf(line,"%s\n",quit);
    printf("%s",line);
    return line;
}


void sig_sigGen(int);
void sig_killChild(void);
void sig_skipUntilString(int,const char *);
void sig_sigChld(int);
void sig_sigTstp(int);
void sig_installHandlers(void);
void sig_removeHandlers(void);
const char *sig_identify(int);

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
    if (verbose) {
      printf("REDFRONT normally exiting on signal %d (%s)\n",arg,sig_identify(arg));
    }
    rf_exit(0);
  default:
    if (verbose) {
      printf("***** REDFRONT exiting on unexpected signal %d (%s)\n",
	     arg,sig_identify(arg));
    }
    rf_exit(-1);
  }
}

void sig_killChild(void) {
#ifdef SIGCHLD
  signal(SIGCHLD,SIG_IGN);
#endif
#if 0
  kill(reduceProcessID,SIGTERM);
#endif
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
  if (verbose) {
    printf("REDFRONT normally exiting on signal %d (%s)\n",arg,sig_identify(arg));
  }
  rf_exit(0);
}

void sig_sigTstp(int arg) {
#ifdef SIGSTOP
/* Not having SIGSTOP looks bad! */
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
  /* The list of signals is taken from the sigaction man page: "The
     following is a list of all signals with names as in the include
     file <signal.h> */
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



int debug = 0;

int deb_fprintf(FILE *file,const char *msg,...) {
  return 0;
}


int bufmatch(struct strbuf *,struct strbuf *);

struct strbuf *addchar(char c,struct strbuf *b) {
  struct strbuf *newbuf;

  newbuf = (struct strbuf *)malloc(sizeof(struct strbuf));
  newbuf->c = c;
  newbuf->next = (struct strbuf *)0;
  newbuf->prev = b;
  if (b)
    b->next = newbuf;
  return newbuf;
}

void prtbuf(struct strbuf *b) {
  struct strbuf *scan,*old;

  if (!b)
    return;

  scan = b;
  while (scan->prev)
    scan = scan->prev;

  while (scan) {
    printf("%c",scan->c);
    old = scan;
    scan = scan->next;
    free(old);
  }
}

struct strbuf *remtail(struct strbuf *t,struct strbuf *b) {
  while (!bufmatch(t,b))
    b = b->prev;

  while (t) {
    t = t->prev;
    b = b-> prev;
    free(b->next);
  }

  b->next = (struct strbuf *)0;

  return b;
}

int bufmatch(struct strbuf *t,struct strbuf *b) {
  while (t) {
    if (t->c != b->c)
      return 0;
    t = t->prev;
    b = b->prev;
  }
  return 1;
}

strl strl_new(char *that,strl next) {
  strl sl;
  char *thisone=NULL;

  sl = (strl)malloc(sizeof(struct oStrl));
  if (that) {
    thisone = (char *)malloc((strlen(that)+1)*sizeof(char));
    strcpy(thisone,that);
  }
  sl->thisone = thisone;
  sl->next = next;
  return sl;
};

strl strl_cadd(strl sl,char *entry) {
  strl scsl,newbuf;

  if (!sl) {
    newbuf = strl_new(entry,NULL);
    return newbuf;
  }

  for (scsl = sl; scsl->next; scsl = scsl->next)
    if (strcmp(scsl->thisone,entry) == 0)
      return sl;

  if (strcmp(scsl->thisone,entry) != 0) {
    newbuf = strl_new(entry,NULL);
    scsl->next = newbuf;
  }

  return sl;
}

strl strl_delete(strl sl) {
  strl old;

  while (sl) {
    old = sl;
    sl = sl->next;
    free(old->thisone);
    free(old);
  }
  return NULL;
}

/* end of wxpsl.cpp */
