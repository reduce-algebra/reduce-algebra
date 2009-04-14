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

int verbose = 0;
int unicode = 0;
int color = 1; 
char *memory;

#define DEFAULT_REDFRONTCOLOR MAGENTA /* REDFRONT output */
#define DEFAULT_NORMALCOLOR BLACK     /* REDUCE terminal output */
#define DEFAULT_PROMPTCOLOR BLACK     /* REDUCE prompt */
#define DEFAULT_INPUTCOLOR RED        /* REDUCE input line */
#define DEFAULT_OUTPUTCOLOR BLUE      /* REDUCE mathprint output */
#define DEFAULT_DEBUGCOLOR CYAN       /* REDFRONT DEBUG output" */

int redfrontcolor = DEFAULT_REDFRONTCOLOR; /* REDFRONT output */
int normalcolor = DEFAULT_NORMALCOLOR;   /* REDUCE terminal output */
int promptcolor = DEFAULT_PROMPTCOLOR;   /* REDUCE prompt */
int inputcolor = DEFAULT_INPUTCOLOR;    /* REDUCE input line */
int outputcolor = DEFAULT_OUTPUTCOLOR;   /* REDUCE mathprint output */
int debugcolor = DEFAULT_DEBUGCOLOR;    /* REDFRONT DEBUG output */

void parse_args(int,char **);
void init_channels(void);
void print_banner(int);
int parse_colarg(char *);
int map_colour(int);
char *parse_memarg(char *,char *);
void print_usage(char *);
void print_help(char *);
int textcolor(int);
void textcolor1(int,int,int);
void stextcolor1(char *,int,int,int);
void resetcolor(void);

int main(int argc,char **argv,char **envp) {

  deb_init();

  parse_args(argc,argv);

  print_banner(verbose);

  line_init();

  line_init_history();

  init_channels();

  if ((reduceProcessID = fork())) {  /* I am not the child */

    if (reduceProcessID < 0) {  /* Failure */
      perror("cannot fork()");
      rf_exit(-1);
    }

    deb_fprintf(stderr,"parent: process alive - fork()=%d\n",reduceProcessID);

    parent();
    
  } else {  /* I am the child */

    deb_fprintf(stderr,"child: process alive - fork()=%d\n",reduceProcessID);
    
    child(argc,argv,envp);
  }
  
  return -1;
}

void parse_args(int argc,char **argv) {
  int c;
  extern char *optarg;
  extern int optind;

#ifdef BPSL
  const char *os="bc:huvVm:";
#else
  const char *os="bc:huvV";
#endif

  int errflg=0;
  
  while ((c = getopt(argc, argv, os)) != EOF)
    switch (c) {
    case 'h':
      print_help(argv[0]);
      rf_exit(1);
      break;
    case 'b':
      color = 0;
      break;
    case 'c':
      errflg += parse_colarg(optarg);
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
    rf_exit (2);
  }

#ifdef BPSL
  memory = parse_memarg(memory==NULL ? MEMORY : memory,argv[0]);
#endif
}

int parse_colarg(char *s) {
  int c;
      
  c = map_colour(*s++);
  outputcolor = (c<0) ? DEFAULT_OUTPUTCOLOR : c;
  if (*s == 0) return 0;

  c = map_colour(*s++);
  inputcolor = (c<0) ? DEFAULT_INPUTCOLOR : c;
  if (*s == 0) return 0;

  c = map_colour(*s++);
  promptcolor = (c<0) ? DEFAULT_PROMPTCOLOR : c;
  if (*s == 0) return 0;

  c = map_colour(*s++);
  normalcolor = (c<0) ? DEFAULT_NORMALCOLOR : c;
  if (*s == 0) return 0;

  c = map_colour(*s++);
  redfrontcolor = (c<0) ? DEFAULT_REDFRONTCOLOR : c;
  if (*s == 0) return 0;

  c = map_colour(*s++);
  debugcolor = (c<0) ? DEFAULT_DEBUGCOLOR : c;
  if (*s == 0) return 0;

  return 1;
}

int map_colour(int ch) {
  switch (ch) {
  case 'k': case 'K':
  case 'B':           return BLACK;
  case 'r': case 'R': return RED;
  case 'g': case 'G': return GREEN;
  case 'y': case 'Y': return YELLOW;
  case 'b':           return BLUE;
  case 'm': case 'M': return MAGENTA;
  case 'c': case 'C': return CYAN;
  case 'w': case 'W': return WHITE;
  default:            return -1;
  }
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
  resetcolor();
  rf_exit(1);
  return NULL;  // ... to make the compiler happy
}

void print_usage(char name[]) {
#ifdef BPSL
  (void)fprintf(stderr,
		"usage: %s [-bhvV] [-c COLORSPEC] [[-m] NUMBER[kKmM]]\n",name);
 #else
  (void)fprintf(stderr,"usage: %s [-bhvV] [-c COLORSPEC]\n",name);
 #endif
}

void print_help(char name[]) {
  int w=color;
  
  color = 0;
  print_banner(1);
  color=w;

  fprintf(stderr,"A REDUCE frontend\n\n");
  
  print_usage(name);

  fprintf(stderr,"       -b\t\tblack and white mode\n");
  fprintf(stderr,"       -c COLORSPEC\tspecify colors for input, output, prompt\n");
  fprintf(stderr,"       -h\t\tthis help message\n");
#ifdef BPSL
  fprintf(stderr,"       -m NUMBER\theap size in bytes\n"); 
  fprintf(stderr,"       -m NUMBERk\theap size in kilobytes\n");
  fprintf(stderr,"       -m NUMBERm\theap size in megabytes\n");  
#endif
  fprintf(stderr,"       -u\t\tuse unicode characters (experimental)\n");
  fprintf(stderr,"       -v, -V\t\tverbose\n\n");

  fprintf(stderr,"Examples: %s -u\n",name);
#ifdef BPSL
  fprintf(stderr,"          %s -c rKbMgC -m 96m -v.\n\n",name);
#else
  fprintf(stderr,"          %s -c rKMKbC -v\n\n",name); 
#endif

  fprintf(stderr,"There is a manpage available.\n");
}

void print_banner(int vb) {
  textcolor(redfrontcolor);
	
  if (vb) {
    int ur=0;
#ifdef USE_READLINE
    ur=1;
#endif
    printf("%s %s/%d, built %s ...\n",
	   PACKAGE_NAME,
	   PACKAGE_VERSION,
	   4*ur + 2*USE_PIPES + STATIC,
	   BUILDTIME);
    if (unicode) printf("%c%c",0xC2,0xA9); else printf("(C)");
    printf(" 1999-2008 A. Dolzmann, 1999-2009 T. Sturm\n");
    printf("Based on earlier projects by C. Cannam and W. Neun\n");
    printf("Reports bugs to <%s>\n\n",PACKAGE_BUGREPORT);
  } else {
    printf("%s %s, built %s ...\n",PACKAGE_NAME,PACKAGE_VERSION,BUILDTIME);
  }
  textcolor(normalcolor);
}

void init_channels(void) {
  if (USE_PIPES) {
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
  } else {
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
}

int textcolor(int fg) {
  static int currentcolor=DEFAULT_REDFRONTCOLOR;
  int oldcolor;

  oldcolor = currentcolor;
  currentcolor = fg;
  textcolor1(0,fg,9);
  return oldcolor;
}

void textcolor1(int attr, int fg, int bg) {	
  if (color && HAVE_COLOR) {
    char command[13];
    
    stextcolor1(command,attr,fg,bg);
    printf("%s", command);
    fflush(stdout);
  }
}

void stextcolor1(char command[],int attr,int fg,int bg) {
  sprintf(command,"%c[%d;%d;%dm", 0x1B, attr, fg + 30, bg + 40);
}

void resetcolor(void) {
  if (color && HAVE_COLOR) {
    printf("%c[0m",0x1B);
    fflush(stdout);
  }
}

void rf_exit(int ecode) {
  deb_cleanup();
  resetcolor();
  exit(ecode);
}
