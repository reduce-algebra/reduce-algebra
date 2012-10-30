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
	          fflush(stderr);}

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

int main(argc,argv,envp)
  int    argc;
  char **argv;
  char **envp;
{
  char        redFullName[PATH_MAX];
  char        red_image_name [PATH_MAX];
  char bufferlein [20];
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

printf("Channels %d %d %d %d\n",MeToReduce[0],MeToReduce[1],
          ReduceToMe[0], ReduceToMe[1]);

    if (pid = fork()) {

      if (pid < 0) { perror("XR");
		fprintf(stderr,"XR: Could not fork() Reduce process\n");
		exit(-1); }

      reduceProcessID = pid;
          myProcessID = ppid;

      setlinebuf(stdout);

sleep (1);
   sprintf(bufferlein,"  %d, %d\n",pid,ppid);
  for(i=3;i<9;i++) 
   write(i,bufferlein,20);
   printf("%s\n",bufferlein);


    while (1) {

/* This is the silly little top loop */

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
    
    } else { 	/* Just to make sure! */

      sprintf(redFullName,"/home/cons/form");

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
      argv[1] = "-pipe";
//      argv[1] = "/home/conns/form.in.frm";
      argv[3] = 0;
      argv[2] = "4,6,3,5";
//      sprintf(red_image_name,"%s/reduce.img",getenv("reduce"));
      argv[4] = "";
printf("Channels %d %d %d %d\n",MeToReduce[0],MeToReduce[1],
          ReduceToMe[0], ReduceToMe[1]);

      execve(redFullName, argv, envp);

      printf("XR: Could not execve()\n");
      perror("XR"); 
      fflush(stderr);
      sleep(1);
      exit(-1);
    }
}
