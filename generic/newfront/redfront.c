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
#include "findself.h"

/* Exportable variables */

int reduceProcessID;

HANDLE_T MeToReduce[2];
HANDLE_T ReduceToMe[2];

#ifdef NATIVE_WINDOWS

int redread(HANDLE_T h, void *buffer, int len)
{   DWORD res;
    ReadFile(h, buffer, len, &res, NULL);
    return res;
}

int redwrite(HANDLE_T h, void *buffer, int len)
{   DWORD res;
    WriteFile(h, buffer, len, &res, NULL);
    return res;
}

void redclose(HANDLE_T h)
{   CloseHandle(h);
}

/*
 * This does broadly what the Unis-style "pipe()" call does and sets up
 * an array with entries that are the two ends of a new pipe.
 */

int pipe(HANDLE_T *r)
{  SECURITY_ATTRIBUTES sec;
   sec.nLength = sizeof(sec);
   sec.lpSecurityDescriptor = NULL;
   sec.bInheritHandle = TRUE;
   if (CreatePipe(&r[0], &r[1], &sec, 0) == 0) return -1;
   else return 0;
}

#else /* not NATIVE_WINDOWS */

int redread(HANDLE_T h, void *buffer, int len)
{   return read(h, buffer, len);
}

int redwrite(HANDLE_T h, void *buffer, int len)
{   return write(h, buffer, len);
}

void redclose(HANDLE_T h)
{   close(h);
}

#endif

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

  find_program_directory(argv[0]);
#ifdef DEBUG
  printf("fullProgramName = <%s>\n", fullProgramName);
  printf("programName = <%s>\n", programName);
  printf("programDir = <%s>\n", programDir);
  printf("programNameDotCom = %d\n", programNameDotCom);
#endif

  parse_args(argc,argv);

  deb_init();

  print_banner(verbose);

  line_init();

  line_init_history();

  init_channels();

  /* I am preparing the argument for the child's execv() here, because malloc()
     after fork() might be problematic. */
  nargv = create_call(argc,argv);
/*
 * Native Windows does not provide a nice easy version of "fork", but here
 * the child process will do little more than use execv to launch Reduce
 * as a sub-process. It does so keeping stdin and stdout links so that the
 * sub-process is accessible via a pipe. With windows this all has to be
 * different code!
 */
#ifdef NATIVE_WINDOWS

  child(nargv); // Creates child process that runs Reduce, with pipes
                // to connect it to this process.
  free(nargv);
  parent();  

#else

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
#endif

  return -1;
}


void parse_args(int argc,char **argv) {
  int c;
//  extern char *optarg;
//  extern int optind;
  const char *os;
  int errflg=0;

#ifdef PSL
  os = "bc:huvVm:";
#else
  os = "bc:huvV";
#endif
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

  if (strcmp(argv[optind - 1],"--") == 0)
  { // <options> + "--"
    xargstart = optind;
  }
#ifdef PSL
  else if (memory == NULL && optind == argc - 1)
  { // <options> + <memarg>
    memory = argv[optind];
    xargstart = argc;
  }
  else if (memory == NULL &&
	   optind < argc - 1 && strcmp(argv[optind + 1],"--") == 0)
  { // <options> + <memarg> + "--"
    memory = argv[optind];
    xargstart = optind + 2;
  }
#endif
  else if (optind == argc)
  { // <options>
    xargstart = argc;
  }
  else
  { print_usage(argv[0]);
    rf_exit(2);
  }

#ifdef PSL
  memory = parse_memarg(memory==NULL ? "0" : memory,argv[0]);
#endif
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
#ifdef PSL
  fprintf(stderr,
          "usage: %s [-bhuvV] [-c COLORSPEC] [[-m] NUMBER[kKmM]]\n",name);
#else
  fprintf(stderr,"usage: %s [-bhuvV] [-c COLORSPEC]\n",name);
#endif
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
#ifdef PSL
  fprintf(stderr,"       -m NUMBER [kKmM]\t\
memory allocation in Bytes [KB|MB]\n");
#endif
  fprintf(stderr,"       -u\t\tuse unicode characters\n");
  fprintf(stderr,"       -v, -V\t\tverbose\n\n");

  fprintf(stderr,"Examples: %s -uv\n",name);
#ifdef PSL
  fprintf(stderr,"          %s -c xxxxxxbxexgx -m 96m.\n\n",name);
#else
  fprintf(stderr,"          %s -c xxxxxxbxexgx -v\n\n",name);
#endif
  fprintf(stderr,"Use TAB for completion of filenames and Reduce switches.\n");
  fprintf(stderr,"There is a manpage available.\n");
}

void print_banner(int vb) {
  textcolor(redfrontcolor);

  if (vb) {
    printf("%s %s/%d, built %s ...\n",
	   PACKAGE_NAME,
	   PACKAGE_VERSION,
	   2*USE_PIPES,
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
  if (color) {
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
  if (color) {
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
  char *reducename;
  int tempfd;
  int i,j,xa0;

  deb_fprintf(stderr,"entering create_call\n");

  nargv = (char **)malloc((argc - xargstart + 6)*sizeof(char *));

#ifdef PSL
   reducename = (char *)malloc(strlen(programDir) + 16);
   sprintf(reducename, "%s/redpsl", programDir);
#ifdef NATIVE_WINDOWS
   strcat(reducename, ".bat");
#endif

  if ((tempfd = open(reducename,O_RDONLY)) == -1) {  /* Does not check x */
    char errstr[1024];
    sprintf(errstr,"cannot open PSL executable (%s)", reducename);
    perror(errstr);
    rf_exit(-1);
  } else
    close(tempfd);

/*
 * If I launch psl using the "redpsl" script than that will cope with
 * selecting a default memory - so if none is specified by the user
 * of rfpsl I do not have anything to do here.
 */
  j = 0;
  nargv[j++] = reducename;
  if (memory != NULL &&
      strcmp(memory, "0") != 0)  /* Actually I think this just becomes
                                    a regular extra argument */
  { nargv[j++] = "-td";
    nargv[j++] = memory;
  }
  for (i = xargstart; i < argc; i++)
    nargv[j++] = argv[i];
  nargv[j] = (char *)0;


#else  /* Now the CSL version */

   reducename = (char *)malloc(strlen(programDir) + 16);
   sprintf(reducename, "%s/redcsl", programDir);
#ifdef NATIVE_WINDOWS
   strcat(reducename, ".bat");
#endif

  if ((tempfd = open(reducename,O_RDONLY)) == -1)
  {  char errstr[1024];
     sprintf(errstr,"cannot open CSL executable (%s)", reducename);
     perror(errstr);
    rf_exit(-1);
  }
  else close(tempfd);

  j = 0;
  nargv[j++] = reducename;
  nargv[j++] = "-w";
  nargv[j++] = "-b";
  if (verbose)           /* This could perhaps be a simple general case arg */
    nargv[j++] = "-V";
  for (i = xargstart; i < argc; i++)
    nargv[j++] = argv[i];
  nargv[j] = (char *)0;

#endif

  for (i = 0; nargv[i] != (char *)0; i++)
    deb_fprintf(stderr,"argv[%d]=%s\n",i,nargv[i]);

  deb_fprintf(stderr,"leaving create_call\n");

  return nargv;
}

/* end of redfront.c */
