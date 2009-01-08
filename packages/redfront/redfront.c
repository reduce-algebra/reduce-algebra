/* ------------------------------------------------------------------
	$Id: redfront.c,v 1.10 2006/12/20 11:55:09 sturm Exp $
	------------------------------------------------------------------
	Copyright (c) 1999 Andreas Dolzmann and Thomas Sturm
	------------------------------------------------------------------
	$Log: redfront.c,v $
	Revision 1.10  2006/12/20 11:55:09  sturm
	Switched to ANSI C.Some procedures were encapsulated with #ifdef RBPSL.Such case distinctions have been moved inside the proceduresto support parsing in Eclipse.
	
	Revision 1.9  2006/06/04 17:30:19  sturm
	--with-reduce-binary now builds correctly. In that case there is always
	REDUCEROOT used, and $reduce is neither checked nor set.
	
	Revision 1.8  2006/06/03 11:31:29  sturm
	Adapted to the CSL development system.
	Before I had wrong ideas about image model vs. csl.
	
	Revision 1.7  2006/05/17 18:15:43  sturm
	Check for using_history in linreadline first.
	This is essential at least on MacOS X.
	
	Revision 1.6  2004/09/23 09:55:49  sturm
	Fixed debugging output.
	Solaris Compilation.
	This is used for static binaries shipped with REDUCE 3.8.
	
	Revision 1.5  2004/09/02 13:55:44  sturm
	Moved evaluation of $reduce to redfront.c.
	Added evaluation of $reduce also for redfront root.
	
	Revision 1.4  2004/09/02 12:05:02  dolzmann
	Updated of usage.
	
	Revision 1.3  2004/09/02 11:48:58  dolzmann
	Added options -h. Renamed option -c to -b.
	
	Revision 1.2  2004/09/02 10:13:57  dolzmann
	redfront now uses getopt.
	Added new option -c for version without colors.
	Allows option -m for memory size.
	
	Revision 1.1  1999/09/20 13:37:52  sturm
	Private autoconf-based REDFRONT development branch by A. Dolzmann
	and T. Sturm.
	Initial check-in.
	
	------------------------------------------------------------------ */

#include "redfront.h"

/* Exportable variables */

int reduceProcessID;

int color=1; 
char *memory;

char *lisp;
char *redimg;
char *redfrontroot;

/* Sockets for communication with Reduce; obtained from socketpair(),
   so check your implementation! */
int MeToReduce[2],ReduceToMe[2];

#ifdef DEBUG
int debug = 1;
#else
int debug = 0;
#endif

void init_history(void);
void init_sockets(void);
void parse_args(int,char **);
char *parse_memarg(char *,char *);
void print_usage(char *);
void print_help(char *);
void process_pathes(void);
void textcolor(int);
void textcolor1(int,int,int);

int main(int argc,char **argv,char **envp) {
  parse_args(argc,argv);

  process_pathes();

  (void)setsid();  /* become leader of a new process group */

  init_history();

  init_sockets();

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

void init_history(void) {
#ifdef HAVE_HISTORY
  char *hname;

  using_history();

  hname = (char *)malloc(strlen(getenv("HOME"))+strlen("/.reduce_history")+1);
  sprintf(hname,"%s/.reduce_history",getenv("HOME"));
  read_history(hname);
#endif
}

void init_sockets(void) {
  if (socketpair(AF_UNIX, SOCK_STREAM, 0, MeToReduce) < 0) {
    perror("cannot open socket");
    red_kill();
    exit(-1);
  }
  if (socketpair(AF_UNIX, SOCK_STREAM, 0, ReduceToMe) < 0) {
    perror("cannot open socket");
    red_kill();
    exit(-1);
  }
}

void parse_args(int argc,char **argv) {
  int c;
  extern char *optarg;
  extern int optind;

  int errflg=0;
  
  while ((c = getopt(argc, argv, "bhm:")) != EOF)
    switch (c) {
    case 'h':
      print_help(argv[0]);
      exit(1);
      break;
    case 'b':
      color=!color;
      break;
#ifdef RBPSL
    case 'm':
      memory = optarg;
      break;
#endif
    case '?':
      errflg++;
    }

#ifdef RBPSL
  if (optind == argc - 1) {
    memory = argv[optind];
  }
#endif
    
  if (errflg) {
    print_usage(argv[0]);
    exit (2);
  }

#ifdef RBPSL
  memory = parse_memarg(memory==NULL ? MEMORY : memory,argv[0]);
#endif

  return;
}

char *parse_memarg(char *argstr,char *name) {
/* Only used for PSL (#ifdef RBPSL) */
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
#ifdef RBPSL
  (void)fprintf(stderr,"usage: %s [-bh] [[-m] NUMBER[kKmM]]\n",name);
 #else
  (void)fprintf(stderr,"usage: %s [-bh]\n",name);
 #endif
}

void print_help(char name[]) {
#ifdef RBPSL
  print_usage(name);
  fprintf(stderr,"       -b\t\tblack and white mode\n");
  fprintf(stderr,"       -h\t\tthis help message\n");
  fprintf(stderr,"       -m NUMBER\theap size in bytes\n"); 
  fprintf(stderr,"       -m NUMBERk\theap size in kilobytes\n");
  fprintf(stderr,"       -m NUMBERm\theap size in megabytes\n");  
  fprintf(stderr,"Example: %s -m 128m  # this is default\n",name);
#else
  print_usage(name);
  fprintf(stderr,"       -b\t\tblack and white mode\n");
  fprintf(stderr,"       -h\t\tthis help message\n");
#endif
}

void process_pathes(void) {
  char *reduce;

#ifdef REDUCE

  redfrontroot = REDFRONTROOT;

#else

  reduce = getenv("reduce");

  if (reduce == NULL) {
/*    setenv("reduce",REDUCEROOT,0); */
    reduce = (char *)malloc((6+1+strlen(REDUCEROOT)+1)*sizeof(char));
    sprintf(reduce,"reduce=%s",REDUCEROOT);
    putenv(reduce);
#ifdef BPSL
    lisp = BPSL;
#elif defined CSL
    lisp = CSL;
#endif
    redimg = REDIMG;
    redfrontroot = REDFRONTROOT;
  } else {
#ifdef RBPSL
    lisp = (char *)malloc((strlen(reduce)+strlen(RBPSL)+2)*sizeof(char));
    sprintf(lisp,"%s/%s",reduce,RBPSL);
#elif defined RCSL
    lisp = (char *)malloc((strlen(reduce)+strlen(RCSL)+2)*sizeof(char));
    sprintf(lisp,"%s/%s",reduce,RCSL);
#endif
    redimg = (char *)malloc((strlen(reduce)+strlen(RREDIMG)+2)*sizeof(char));
    sprintf(redimg,"%s/%s",reduce,RREDIMG);

    redfrontroot = (char *)malloc((strlen(reduce)+strlen(RREDFRONTROOT)+2)*
				  sizeof(char));
    sprintf(redfrontroot,"%s/%s",reduce,RREDFRONTROOT);
  }
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

