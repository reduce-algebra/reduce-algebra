/* ---------------------------------------------------------------------
   $Id$
   ---------------------------------------------------------------------
   (c) 1999-2009 A. Dolzmann and T. Sturm, 1999-2014 T. Sturm
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

int dist=0;

int reduceProcessID;

int MeToReduce[2];
int ReduceToMe[2];

int verbose = 0;
int unicode = 0;
int color = 1;
char *memory=NULL;
int xargstart;

#define DEFAULT_REDFRONTCOLOR MAGENTA /* REDFRONT output */
#define DEFAULT_NORMALCOLOR USER      /* REDUCE terminal output */
#define DEFAULT_PROMPTCOLOR BLACK     /* REDUCE prompt */
#define DEFAULT_INPUTCOLOR RED	      /* REDUCE input line */
#define DEFAULT_OUTPUTCOLOR BLUE      /* REDUCE mathprint output */
#define DEFAULT_DEBUGCOLOR CYAN	      /* REDFRONT DEBUG output" */

int redfrontcolor = DEFAULT_REDFRONTCOLOR; /* REDFRONT output */
int normalcolor = DEFAULT_NORMALCOLOR;	   /* REDUCE terminal output */
int promptcolor = DEFAULT_PROMPTCOLOR;	   /* REDUCE prompt */
int inputcolor = DEFAULT_INPUTCOLOR;	   /* REDUCE input line */
int outputcolor = DEFAULT_OUTPUTCOLOR;	   /* REDUCE mathprint output */
int debugcolor = DEFAULT_DEBUGCOLOR;	   /* REDFRONT DEBUG output */

int det_dist(char *);
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
int vbprintf(const char *,...);
void rf_exit(int);
char **create_call(int, char **);

int main(int argc,char **argv,char **envp) {
  char **nargv;

  dist = det_dist(argv[0]);

  parse_args(argc,argv);

  deb_init();

  print_banner(verbose);

  line_init();

  line_init_history();

  init_channels();

  /* I am preparing the argument for the child's execv() here, because malloc()
     after fork() might be problematic. */
  nargv = create_call(argc,argv);

  if ((reduceProcessID = fork())) {  /* I am not the child */

    if (reduceProcessID < 0) {  /* Failure */
      perror("cannot fork()");
      rf_exit(-1);
    }

    deb_fprintf(stderr,"parent: process alive - fork()=%d\n",reduceProcessID);

    free(nargv);

    parent();

  } else {  /* I am the child */

    deb_fprintf(stderr,"child: process alive - fork()=%d\n",reduceProcessID);

    child(nargv);
  }

  return -1;
}

int det_dist(char *argv0) {
  char *fn,*bn;
  int dist = -1;
  char d[1024] = "";

  fn = (char *)malloc((strlen(argv0)+1)*sizeof(char));
  strcpy(fn,argv0);
  bn = basename(fn);
  if (strcmp(bn,"rfpsl") == 0)
    dist = PSL;
  else if (strcmp(bn,"rfcsl") == 0)
    dist = CSL;
  else if (strcmp(bn,"rfbcsl") == 0)
    dist = BCSL;
  else {
    printf("Select distribution [bcsl/csl/psl] ");
    scanf("%s",d);
    if (strcmp(d,"bcsl") == 0)
      dist = BCSL;
    else if (strcmp(d,"csl") == 0)
      dist = CSL;
    else if (strcmp(d,"psl") == 0)
      dist = PSL;
  }
  free(fn);
  if (dist == -1)
    exit(-1);
  return dist;
}

void parse_args(int argc,char **argv) {
  int c;
  extern char *optarg;
  extern int optind;
  const char *os;
  int errflg=0;

  os = (dist == PSL) ? "bc:huvVm:" : "bc:huvV";

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
  } else if (dist == PSL && memory == NULL && optind == argc - 1) {
    // <options> + <memarg>
    memory = argv[optind];
    xargstart = argc;
  } else if (dist == PSL && memory == NULL &&
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

  if (dist == PSL) {
    memory = parse_memarg(memory==NULL ? MEMORY : memory,argv[0]);
  }
}

int parse_colarg(char *s) {
  /* Parse the parameter of -c as a string similar to LSCOLORS
     documented in the ls manpage. The order is redfrontcolor,
     normalcolor, promptcolor, inputcolor, outputcolor, debugcolor. The
     default choice corresponds to "fxxxxxbxexgx". At present,
     background specifications are ignored and upper case (bold face) is
     mapped to lower case. */
  int c;

  c = map_colour(*s++);
  redfrontcolor = (c<0) ? DEFAULT_REDFRONTCOLOR : c;
  if (*s == 0) return 0;

  s++;
  if (*s == 0) return 0;

  c = map_colour(*s++);
  normalcolor = (c<0) ? DEFAULT_NORMALCOLOR : c;
  if (*s == 0) return 0;

  s++;
  if (*s == 0) return 0;

  c = map_colour(*s++);
  promptcolor = (c<0) ? DEFAULT_PROMPTCOLOR : c;
  if (*s == 0) return 0;

  s++;
  if (*s == 0) return 0;

  c = map_colour(*s++);
  inputcolor = (c<0) ? DEFAULT_INPUTCOLOR : c;
  if (*s == 0) return 0;

  s++;
  if (*s == 0) return 0;

  c = map_colour(*s++);
  outputcolor = (c<0) ? DEFAULT_OUTPUTCOLOR : c;
  if (*s == 0) return 0;

  s++;
  if (*s == 0) return 0;

  c = map_colour(*s++);
  debugcolor = (c<0) ? DEFAULT_DEBUGCOLOR : c;
  if (*s == 0) return 0;

  s++;
  if (*s == 0) return 0;

  return 1;
}

int map_colour(int ch) {
  switch (ch) {
  case 'a': case 'A': return BLACK;
  case 'b': case 'B': return RED;
  case 'c': case 'C': return GREEN;
  case 'd': case 'D': return YELLOW;
  case 'e': case 'E': return BLUE;
  case 'f': case 'F': return MAGENTA;
  case 'g': case 'G': return CYAN;
  case 'h': case 'H': return WHITE;
  case 'x':           return USER;
  default:            return -1;
  }
}

char *parse_memarg(char *argstr,char *name) {
  /* Only used for PSL */
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
  if (dist == PSL)
    fprintf(stderr,
	    "usage: %s [-bhuvV] [-c COLORSPEC] [[-m] NUMBER[kKmM]]\n",name);
  else
    fprintf(stderr,"usage: %s [-bhuvV] [-c COLORSPEC]\n",name);
}

void print_help(char name[]) {
  int w=color;

  color = 0;
  print_banner(1);
  color=w;

  fprintf(stderr,"A REDUCE frontend\n\n");

  print_usage(name);

  fprintf(stderr,"       -b\t\t\
black and white mode, i.e. do not use ANSI colors\n");
  fprintf(stderr,"       -c COLORSPEC\t\
specify colors for redfront output, normal output,\n");
  fprintf(stderr,"         \t\t\
prompt, input, math output, debug output. The default\n");
  fprintf(stderr,"         \t\t\
is fxxxxxbxexgx - see LSCOLORS in the ls manpage for\n");
  fprintf(stderr,"         \t\tdetails\n");
  fprintf(stderr,"       -h\t\tthis help message\n");
  if (dist == PSL)
    fprintf(stderr,"       -m NUMBER [kKmM]\t\
memory allocation in Bytes [KB|MB]\n");
  fprintf(stderr,"       -u\t\tuse unicode characters\n");
  fprintf(stderr,"       -v, -V\t\tverbose\n\n");

  fprintf(stderr,"Examples: %s -uv\n",name);
  if (dist == PSL)
    fprintf(stderr,"          %s -c xxxxxxbxexgx -m 96m.\n\n",name);
  else
    fprintf(stderr,"          %s -c xxxxxxbxexgx -v\n\n",name);
  fprintf(stderr,"Use TAB for completion of filenames and Reduce switches.\n");
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
    //    if (unicode) printf("%c%c",0xC2,0xA9); else printf("(C)");
    printf("(C)");
    printf(" 1999-2008 A. Dolzmann, 1999-2014 T. Sturm\n");
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
  if (fg == 9)
    resetcolor();
  else
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

int vbprintf(const char *msg,...) {
  int ecode=0;
  int oldcolor;
  va_list ap;

  if (!verbose)
    return 0;

  va_start(ap,msg);
  oldcolor = textcolor(redfrontcolor);
  ecode = vprintf(msg,ap);
  textcolor(oldcolor);
  va_end(ap);

  return ecode;
}

void rf_exit(int ecode) {
  deb_cleanup();
  resetcolor();
  exit(ecode);
}

char **create_call(int argc,char *argv[]) {
  char **nargv;
  int tempfd;
  int i,xa0;

  deb_fprintf(stderr,"entering create_call\n");

  nargv = (char **)malloc((argc - xargstart + 6)*sizeof(char *));

  if (dist == PSL) {
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

    if (strcmp(memory,"0") == 0) {
      char *sixtyfour;
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
      deb_fprintf(stderr,"checking for %s ... ",sixtyfour);
      if ((tempfd = open(sixtyfour,O_RDONLY)) != -1) {
	close(tempfd);
	deb_fprintf(stderr,"positive\n");
	memory = "2000";
      } else {
	deb_fprintf(stderr,"negative\n");
	memory = "16000000";
      }
    }

    nargv[0] = BPSL;
    nargv[1] = "-td";
    nargv[2] = memory;
    nargv[3] = "-f";
    nargv[4] = REDIMG;
    for (i = xargstart; i < argc; i++)
      nargv[i - xargstart + 5] = argv[i];
    nargv[argc - xargstart + 5] = (char *)0;
  } else {  // dist == BCSL || dist == BCSL
    if ((tempfd = open(dist == BCSL ? BOOTSTRAPREDUCE : REDUCE,O_RDONLY)) == -1) {  /* Does not check x */
      char errstr[1024];
      sprintf(errstr,"cannot open %s",dist == BCSL ? BOOTSTRAPREDUCE : REDUCE);
      perror(errstr);
      rf_exit(-1);
    } else
      close(tempfd);

    nargv[0] = dist == BCSL ? BOOTSTRAPREDUCE : REDUCE;
    nargv[1] = "-w";
    nargv[2] = "-b";
    if (verbose) {
      nargv[3] = "-V";
      xa0 = 4;
    } else
      xa0 = 3;
    for (i = xargstart; i < argc; i++)
      nargv[i - xargstart + xa0] = argv[i];
    for (i = xa0; i <= 5; i++)
      nargv[argc - xargstart + i] = (char *)0;
  }

  for (i = 0; i <= argc - xargstart + 5; i++)
    deb_fprintf(stderr,"argv[%d]=%s\n",i,nargv[i]);

  deb_fprintf(stderr,"leaving create_call\n");

  return nargv;
}
