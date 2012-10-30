/*

  A VERY simple C interface to REDUCE

  derived  from the XR interface by Chris Cannam

  Winfried Neun   ZIB

*/

#include <stdio.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <fcntl.h>
#include <sys/ioctl.h>

#define XR_tidy { if (!quietMode) \
		    fprintf(stderr,"XR: Tidying up and leaving.\n"); \
	          fflush(stderr); red_kill(); }

#include <signal.h>

#ifndef PATH_MAX
#define PATH_MAX 512
#endif

/* Exportable variables */

char        * reduceInputBuffer;	 /* For user's input to Reduce   */
char        reduceOutputBuffer[20480];   /* For Reduce's replies         */
char        * reduceOutputPoint;
int           reduceOutputRemaining;
int           reduceCommandStart;        /* Indices into the             */
int           reduceCommandEnd;          /*         reduceInputBuffer    */
unsigned long reduceHistoryNumber;       /* Counts lines, not inputs     */
int           reduceProcessID;
int           myProcessID;
int           MeToReduce[2],             /* Sockets for communication    */
              ReduceToMe[2],             /* with Reduce; obtained from   */
              ReduceErrs[2];             /* socketpair(), so check your  */
				         /* implementation!              */
int       waitingToInterleave;       /* if input is in middle of str */
int       quietMode     = 0;

extern int errno;


/* red_warn() Send warning message to stderr, and continue.
*/

void red_warn(msg)
  char *msg;
{
  fprintf(stderr,"\nXR: %s\n",msg);
  fflush(stderr);
}



/* These functions try to kill the Reduce process, as nicely as possible. */

int red_kill_sub(sg)
  int sg;
{
  int rv;

  rv = kill(reduceProcessID, sg);

  if (sg == SIGTERM) kill(0, SIGHUP);
  if (sg == SIGKILL) kill(0, SIGTERM);

  return rv;
}

void red_kill_sub2()
{
  fflush(stderr);
  signal(SIGTERM, SIG_IGN);
  kill(0,SIGTERM);
  sleep(1);
}

void red_felt_hup()
{ if (!quietMode) fprintf(stderr,"[click] "); }

void red_felt_term()
{ if (!quietMode) fprintf(stderr,"[kerblam] "); }

void removeSignalHandlers()
{
  signal(SIGQUIT, SIG_DFL);
  signal(SIGHUP,  SIG_DFL);
  signal(SIGILL,  SIG_DFL);

#ifndef LINUX
  signal(SIGBUS,  SIG_DFL);
#endif

  signal(SIGSEGV, SIG_DFL);
  signal(SIGPIPE, SIG_DFL);
  signal(SIGCHLD, SIG_DFL);
  signal(SIGTERM, SIG_DFL);
}

void red_kill()
{
  int status;
  int count = 0;

  removeSignalHandlers();
  signal(SIGHUP,  red_felt_hup);
  signal(SIGTERM, red_felt_term);

  if (red_kill_sub(SIGHUP) != 0 && errno == ESRCH) {
    if (!quietMode) fprintf(stderr,"\nXR: No Reduce process\n");
    red_kill_sub2(); return;
  }

  if (!quietMode)
    fprintf(stderr,"\nXR: Sending Hangup signal to Reduce process\n");
  fflush(stderr);

  do {
#ifdef WAIT_PID
    if (waitpid(reduceProcessID, (int *)&status, WNOHANG) ==
	reduceProcessID && (WIFEXITED(status) || WIFSIGNALED(status))) {
#else
#ifdef WAIT_THREE
    if (wait3((union wait *)&status,WNOHANG,NULL) ==
	reduceProcessID && (WIFEXITED(status) || WIFSIGNALED(status))) {
#else
    if (wait4(reduceProcessID,(union wait *)&status,WNOHANG,NULL) ==
	reduceProcessID && (WIFEXITED(status) || WIFSIGNALED(status))) {
#endif
#endif
      if (!quietMode)
	fprintf(stderr,"%sXR: Reduce has hung up\n",count ? "\n":"");
      red_kill_sub2(); return;
    }
    sleep(1);
    if (!quietMode)
      fprintf(stderr,"%s[waiting]%s",count ? "":"XR: ",count-3 ?" ":"\n");
    fflush(stderr);
  } while (++count < 4);

  count = 0;
  if (red_kill_sub(SIGTERM) != 0 && errno == ESRCH) {
    if (!quietMode) fprintf(stderr,"XR: Reduce has hung up\n");
    red_kill_sub2(); return;
  }
  if (!quietMode)
    fprintf(stderr,"XR: Sending Terminate signal to Reduce process\n");
  fflush(stderr);

  do {
#ifdef WAIT_PID
    if (waitpid(reduceProcessID, (int *)&status, WNOHANG) ==
	reduceProcessID && (WIFEXITED(status) || WIFSIGNALED(status))) {
#else
#ifdef WAIT_THREE
    if (wait3((union wait *)&status,WNOHANG,NULL) ==
	reduceProcessID && (WIFEXITED(status) || WIFSIGNALED(status))) {
#else
    if (wait4(reduceProcessID,(union wait *)&status,WNOHANG,NULL) ==
	reduceProcessID && (WIFEXITED(status) || WIFSIGNALED(status))) {
#endif
#endif
      if (!quietMode)
	fprintf(stderr,"%sXR: Reduce terminated\n",count ? "\n":"");
      red_kill_sub2(); return;
    }
    sleep(1);
    if (!quietMode)
      fprintf(stderr,"%s[waiting]%s",count ? "":"XR: ",count-3 ?" ":"\n");
    fflush(stderr);
  } while (++count < 4);

  if (red_kill_sub(SIGKILL) != 0 && errno == ESRCH) {
    if (!quietMode)
      fprintf(stderr,"XR: Reduce has finally been terminated\n");
    red_kill_sub2(); return;
  }
  if (!quietMode)
    fprintf(stderr,"XR: Sending Kill signal to Reduce process\n");
  red_kill_sub2();

  wait(0);
  if (!quietMode)
    fprintf(stderr,"XR: That troublesome Reduce has finally gone\n");
  return;
}


/*
   red_err():

   Send error to stderr and quit.  Attempts to kill off Reduce
   process before exiting.  This is the standard error routine.
*/

void red_err(msg)
  char *msg;
{
  fprintf(stderr,"\nXR Error: %s\n",msg);
  XR_tidy;
  exit(1);
}


char *EnsureFilename(ofn)
  char *ofn;
{
  int         i;
  char       *rev;
  char       *nfn;

  nfn = (char *)malloc(strlen(ofn) + 200);

  for (i = 0; ofn[i]; ++i)
    if (!strncmp(ofn + i, "$reduce", 7)) {
      if (i > 0) strncpy(nfn, ofn, i);
      if ((rev = (char *) getenv("reduce")) == (char *) NULL)
	red_err("Couldn't get value of environment variable $reduce");
      strcpy(nfn + i, rev);
      strcpy(nfn + i + strlen(rev), ofn + i + 7);
      return nfn;
    }

  strcpy(nfn, ofn);

   return nfn;
}

/*
   Signal handlers.  Generally dedicated to catching the Reduce child
   process, slicing it into little pieces and fleeing for one's life.
*/

void ReduceSigQuit()
{
  if (quietMode) fprintf(stderr,"\nXR: Quit Signal\n");
  else           fprintf(stderr,"\nCaught a Quit signal\n");
  XR_tidy; exit(0);
}


void ReduceSigHup()
{
  if (quietMode) fprintf(stderr,"\nXR: Hangup Signal\n");
  else           fprintf(stderr,"\nCaught a Hangup signal\n");
  XR_tidy; exit(0);
}

void ReduceSigIll()
{
  if (quietMode) fprintf(stderr,"\nXR: Illegal Instruction\n");
  else           fprintf(stderr,
	    "\nIllegal Instruction signal caught: this shouldn't happen.\n");
  XR_tidy; exit(-1);
}

void ReduceSigBus()
{
  if (quietMode) fprintf(stderr,"\nXR: Bus Error\n");
  else           fprintf(stderr,
	    "\nBus Error signal caught: this shouldn't happen.\n");
  XR_tidy; exit(-1);
}

void ReduceSigSegV()
{
  if (quietMode) fprintf(stderr,"\nXR: Segmentation Violation\n");
  else           fprintf(stderr,
	   "\nSegmentation Violation signal caught: this shouldn't happen.\n");
  XR_tidy; exit(-1);
}

void ReduceSigPipe()
{
  if (quietMode) fprintf(stderr,"\nXR: Pipe Error\n");
  else {         fprintf(stderr,
			 "\nPipe signal caught: Reduce is in trouble.  ");
                 fprintf(stderr,
			 "This should probably not happen.\n");
  }
  XR_tidy; exit(-1);
}


/* ARGSUSED */
void ReduceSigChldAux(stP, id)
  caddr_t       stP;
{
  if (!quietMode) {
    fprintf(stderr,
	    "\nReduce process exited, status %d; tidying up and leaving.\n",
	    WEXITSTATUS(*((int *)stP)));
  }
  fflush(stderr);
  removeSignalHandlers();
  signal(SIGTERM, SIG_IGN);
  kill(0,SIGTERM);
  sleep(1);
  kill(reduceProcessID,SIGKILL);
  wait(0);
  exit(0);
}


void ReduceSigChld()
{
  int *stP;

  stP = (int *)malloc(sizeof(int));
#ifdef WAIT_PID
  if (waitpid(reduceProcessID, (int *)stP, WNOHANG) ==
      reduceProcessID && WIFEXITED(*stP))
#else
#ifdef WAIT_THREE
  if (wait3((union wait *)stP, WNOHANG, NULL) ==
      reduceProcessID && WIFEXITED(*stP))
#else
  if (wait4(reduceProcessID, (union wait *)stP, WNOHANG, NULL) ==
      reduceProcessID && WIFEXITED(*stP))

#endif
#endif
  fprintf(stderr," Reduce has hung up\n");
  exit(0);

}

void ReduceSigTerm()
{
  if (quietMode)
    fprintf(stderr, "\nXR: Terminate Signal\n");
  else {
    fprintf(stderr, "\nCaught a Terminate signal.");
    fprintf(stderr, "\nAre the initialisation files properly installed?");
    fprintf(stderr, "\nIs there enough memory?  Enough processes?\n");
  }
  XR_tidy; exit(0);
}

void installSignalHandlers()
{
  signal(SIGQUIT, ReduceSigQuit);
  signal(SIGHUP,  ReduceSigHup);
  signal(SIGILL,  ReduceSigIll);

#ifndef LINUX
  signal(SIGBUS,  ReduceSigBus);
#endif

  signal(SIGSEGV, ReduceSigSegV);
  signal(SIGPIPE, ReduceSigPipe);
  signal(SIGCHLD, ReduceSigChld);
  signal(SIGTERM, ReduceSigTerm);
}

int main(argc,argv,envp)
  int    argc;
  char **argv;
  char **envp;
{
  char        redFullName[PATH_MAX];
  char        red_image_name [PATH_MAX];
  int          i;
  int          pid;
  int          ppid = getpid();
  int          plen;
  int          nlen,ii;
  int          tempfd;
  char         ch;

  /* The very first thing to do is to get a new process group.  This is */
  /* because when XReduce exits, it tries to kill the whole group; this */
  /* is rather nasty if it's been started from a window manager or stng */

  /* Let us not care about the return value -- it should only ever fail */
  /* if we're already the process group leader, in which case we don't  */
  /* mind, and if something else happens it's not the end of the world: */
  /* this call shouldn't make any difference to anything else anyway.   */

  (void)setsid();

  if (socketpair(AF_UNIX, SOCK_STREAM, 0, MeToReduce) < 0)
    { perror("XR"); red_err("Couldn't open socket to Reduce process"); }
  if (socketpair(AF_UNIX, SOCK_STREAM, 0, ReduceToMe) < 0)
    { perror("XR"); red_err("Couldn't open socket from Reduce process"); }
  if (socketpair(AF_UNIX, SOCK_STREAM, 0, ReduceErrs) < 0)
    { perror("XR"); red_err("Couldn't open socket for Reduce process"); }

    if (pid = fork()) {

      if (pid < 0) { perror("XR");
		fprintf(stderr,"XR: Could not fork() Reduce process\n");
		exit(-1); }

      reduceProcessID = pid;
          myProcessID = ppid;

      installSignalHandlers();
      setlinebuf(stdout);

    while (1) {

* This is the silly little top loop */

      if(ioctl(0,FIONREAD,&nlen) !=0) perror ("ioctl ??"); 
          for (ii=0;ii<nlen;ii++) { ch = getc(stdin);
				   write(MeToReduce[1],&ch,1); }
      if(ioctl(ReduceToMe[0],FIONREAD,&nlen) !=0) perror ("ioctl to me??");
	  if (nlen > 0)
               {if ((plen = read(ReduceToMe[0], reduceOutputBuffer,
                       20480)) < 0) { printf ("Is nix da %d \n",plen);}
               else { for (ii=0;ii<nlen;ii++)
			 {putc(reduceOutputBuffer[ii],stdout);}
			fflush(stdout);} }
            else { sleep (1);};

              }
      ;
    
    } else { removeSignalHandlers();	/* Just to make sure! */

      sprintf(redFullName,"%s/psl/bpsl",getenv("reduce"));

      if ((tempfd = open(redFullName, O_RDONLY)) == -1) 

	{fprintf(stderr,"XR: No Reduce binary \"%s\"\n", redFullName);
	if (!quietMode)
	  fprintf(stderr,"XR: Initialisation file is probably wrong\n");
        }

      else close(tempfd);

      close(MeToReduce[1]  );
      dup2 (MeToReduce[0],0);
      close(ReduceToMe[0]  );
      dup2 (ReduceToMe[1],1);

      close(ReduceErrs[0]  );
      dup2 (ReduceErrs[1],2);

      argv[0] = redFullName;
      argv[1] = "-td";
      argv[2] = "8000000";
      argv[3] = "-f";
      sprintf(red_image_name,"%s/reduce.img",getenv("reduce"));
      argv[4] = red_image_name;

      execve(redFullName, argv, envp);

      fprintf(stderr, "XR: Could not execve()\n");
      perror("XR"); 
      fflush(stderr);
      sleep(1);
      exit(-1);
    }
}

