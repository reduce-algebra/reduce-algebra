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

/* Exportable variables */

int reduceProcessID;

int MeToReduce[2];
int ReduceToMe[2];

#ifdef DEBUG
int debug = 1;
#else
int debug = 0;
#endif

int verbose = 0;
int unicode = 0;
int color = 1; 
char *memory;

void init_channels(void);
void parse_args(int,char **);
char *parse_memarg(char *,char *);
void print_usage(char *);
void print_help(char *);
void textcolor(int);
void textcolor1(int,int,int);

int main(int argc,char **argv,char **envp) {
  parse_args(argc,argv);

  (void)setsid();  /* become leader of a new process group */

  init_history();

  init_channels();

  if ((reduceProcessID = fork())) {  /* I am not the child */

    if (reduceProcessID < 0) {  /* Failure */
      perror("cannot fork()");
      exit(-1);
    }

#ifdef DEBUG
    if (debug) {
      textcolor(DEBUGCOLOR);
      fprintf(stderr,"parent: process alive - fork()=%d\n",reduceProcessID);
      textcolor(NORMALCOLOR);
      fflush(stderr);
    }
#endif
    parent();
    
  } else {  /* I am the child */

#ifdef DEBUG
    if (debug) {
      textcolor(DEBUGCOLOR);
      fprintf(stderr,"child: process alive - fork()=%d\n",reduceProcessID);
      textcolor(NORMALCOLOR);
      fflush(stderr);
    }
#endif
    child(argc,argv,envp);
  }
  
  return -1;
}

void init_channels(void) {
  if (USE_PIPES) {
    if (pipe(MeToReduce) < 0) {
      perror("failed to create pipe MeToReduce\n");
      red_kill();
      exit(-1);
    }
    if (pipe(ReduceToMe) < 0) {
      perror("failed to create pipe ReduceToMe\n");
      red_kill();
      exit(-1);
    }
  } else {
    if (socketpair(AF_UNIX, SOCK_STREAM, 0, MeToReduce) < 0) {
      perror("cannot open socket MeToReduce");
      red_kill();
      exit(-1);
    }
    if (socketpair(AF_UNIX, SOCK_STREAM, 0, ReduceToMe) < 0) {
      perror("cannot open socket ReduceToMe");
      red_kill();
      exit(-1);
    }
  }
}

void parse_args(int argc,char **argv) {
  int c;
  extern char *optarg;
  extern int optind;

  int errflg=0;
  
  while ((c = getopt(argc, argv, "bhuvVm:")) != EOF)
    switch (c) {
    case 'h':
      print_help(argv[0]);
      exit(1);
      break;
    case 'b':
      color = !color;
      break;
    case 'u':
      unicode = 1;
      break;
    case 'v':
    case 'V':
      verbose = 1;
      break;
#ifdef BPSL
    case 'm':
      memory = optarg;
      break;
#endif
    case '?':
      errflg++;
    }

#ifdef BPSL
  if (optind == argc - 1) {
    memory = argv[optind];
  }
#endif
    
  if (errflg) {
    print_usage(argv[0]);
    exit (2);
  }

#ifdef BPSL
  memory = parse_memarg(memory==NULL ? MEMORY : memory,argv[0]);
#endif

  return;
}

char *parse_memarg(char *argstr,char *name) {
/* Only used for PSL (#ifdef BPSL) */
  char *nargv2;
  char lchar;
  
  lchar = tolower(argstr[strlen(argstr)-1]);

  if (isdigit(lchar)) 
    return argstr;

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
  print_usage(name);
  exit(1);
}

void print_usage(char name[]) {
#ifdef BPSL
  (void)fprintf(stderr,"usage: %s [-bhvV] [[-m] NUMBER[kKmM]]\n",name);
 #else
  (void)fprintf(stderr,"usage: %s [-bhvV]\n",name);
 #endif
}

void print_help(char name[]) {
#ifdef BPSL
  print_usage(name);
  fprintf(stderr,"       -b\t\tblack and white mode\n");
  fprintf(stderr,"       -h\t\tthis help message\n");
  fprintf(stderr,"       -m NUMBER\theap size in bytes\n"); 
  fprintf(stderr,"       -m NUMBERk\theap size in kilobytes\n");
  fprintf(stderr,"       -m NUMBERm\theap size in megabytes\n");  
  fprintf(stderr,"       -u\t\tuse unicode characters (experimental)\n");
  fprintf(stderr,"       -v, -V\t\tverbose\n");
  fprintf(stderr,"Example: %s -m 128m  # this is default\n",name);
#else
  print_usage(name);
  fprintf(stderr,"       -b\t\tblack and white mode\n");
  fprintf(stderr,"       -h\t\tthis help message\n");
  fprintf(stderr,"       -u\t\tuse unicode characters (experimental)\n");
  fprintf(stderr,"       -v, -V\t\tverbose\n");
#endif
}

void textcolor(int fg) {
  textcolor1(0,fg,9);
}

void textcolor1(int attr, int fg, int bg) {	
  if (color && HAVE_COLOR) {
    char command[13];
    
    /* Command is the control command to the terminal */
    sprintf(command, "%c[%d;%d;%dm", 0x1B, attr, fg + 30, bg + 40);
    printf("%s", command);
    fflush(stdout);
#ifdef DEBUG
    if (debug) {
      fprintf(stderr,"%s", command);
      fflush(stderr);
    }
#endif
  }
}
