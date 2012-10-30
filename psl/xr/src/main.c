
/*
   XReduce: An X Interface for REDUCE.

   Chris Cannam and Herbert Melenk, ZIB Berlin, 1992-93.

   Please send bug reports, complaints or congratulations
   to Winfried Neun, neun@sc.ZIB-Berlin.DE, or Herbert
   Melenk, melenk@sc.ZIB-Berlin.DE .

   Note that the name XReduce has been suppressed in this
   release (Help! Help! I'm being suppressed!) so as not
   to imply that this program is an integral part of the
   REDUCE package.  It isn't: it's an extra, developed at
   and supplied by ZIB Berlin, and some legitimate dist-
   ributions of REDUCE for X-capable machines may very
   well omit this program.  We are therefore calling it
   XR instead, and hoping nobody's used the name before.
   It's not a particularly pretty name, but then neither
   is XReduce.

   Main module, central nerve bit; really just does some
   setting-up and housekeeping, including signal handlers,
   error handling and reports, and option parsing.
*/


#include "xreduce.h"		/* Also includes X headers and xredres.h */
#include "verbal.h"		/* Deals with outputting textual history */
#include "xredplus.h"		/* Deals with outputting graphics        */
#include "input.h"		/* Deals with parsing user input         */
#include "output.h"		/* Deals with parsing output from Reduce */
#include "widgets.h"		/* Deals with installing widget tree     */
#include "message.h"		/* Deals with popup yes-no questions     */
#include "option.h"		/* Deals with the options menu           */
#include "font.h"
#include "xredrres.h"
#include "fallback.h"
#include "help.h"
#include "xreduce.xbm"		/* The icon image: most important        */

#define XR_tidy { if (!quietMode) \
		    fprintf(stderr,"XR: Tidying up and leaving.\n"); \
	          fflush(stderr); red_kill(); }

#include <signal.h>

#ifndef PATH_MAX
#define PATH_MAX 512
#endif

/* Exportable variables */

char        * reduceInputBuffer;	 /* For user's input to Reduce   */
char        * reduceOutputBuffer;        /* For Reduce's replies         */
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
Boolean       waitingToInterleave;       /* if input is in middle of str */
Boolean       writeHelpIx   = False;
Boolean       quietMode     = False;

EltType       historyMode;       /* Currently in text or graphical mode? */
HistList    * reduceHistory;     /* The list of Reduce output widgets    */
HistList    * endOfHistory;      /* Pointer to last item in linked list  */
HistList    * endOfManaged;      /* Last visible item, bottom of screen  */

PendingInputList *pendingInput;
PendingInputList *lastInput;

AppData           app_data;      /* App-defaults: see xredres.h          */
XtAppContext      app_ctxt = NULL;
static Atom       wmPrtcls[2];



/*
   red_warn()

   Send warning message to stderr, and continue.
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
  if (app_ctxt) XtDestroyApplicationContext(app_ctxt);
  exit(1);
}


/*
   red_Xnf_err(): Handler for not-immediately-fatal X errors.
*/

int red_Xnf_err(display, event)
  Display     *display;
  XErrorEvent *event;
{
  char  buffer[500];
  char *dispname;

  XGetErrorText(display, event->error_code, buffer, 500);
  dispname = XDisplayName(NULL);

  if (quietMode) {

    fprintf(stderr, "XR: X Warning: %s\n", buffer);

  } else {

    fprintf(stderr, "XR: X Warning: %s on display `%s'\n", buffer, dispname);
    fprintf(stderr,
	    "      [ serial number: 0x%08x ]  [ major op code: 0x%08x ]\n",
	    event->serial, event->request_code);
    fprintf(stderr,
	    "      [ resource iden: 0x%08x ]  [ minor op code: 0x%08x ]\n",
	    event->resourceid, event->minor_code);
  }
  return 0;
}



/*
   red_XIO_err(): Handler for fatal X I/O errors.
*/

/* ARGSUSED */
int red_XIO_err(display)
  Display *display;
{
  if (quietMode) fprintf(stderr,"XR: X server connection lost\n");
  else fprintf(stderr,
       "XR: my relationship with the X server has been cruelly severed\n");
  red_kill(); exit(1);
}



/*
   red_Xt_err(): Handler for fatal Xt errors.
*/

void red_Xt_err(msg)
  char *msg;
{
  fprintf(stderr,"XR: X Toolkit Fatal Error: %s\n", msg);
  red_err("Sorry, I can't cope");
}



char *EnsureFilename(ofn)
  char *ofn;
{
  int         i;
  char       *rev;
  char       *nfn;
  struct stat bf;

  nfn = (char *)XtMalloc(strlen(ofn) + 200);

  for (i = 0; ofn[i]; ++i)
    if (!strncmp(ofn + i, "$reduce", 7)) {
      if (i > 0) strncpy(nfn, ofn, i);
      if ((rev = getenv("reduce")) == NULL)
	red_err("Couldn't get value of environment variable $reduce");
      strcpy(nfn + i, rev);
      strcpy(nfn + i + strlen(rev), ofn + i + 7);
      return nfn;
    }

  strcpy(nfn, ofn);

  if (stat(nfn, &bf)) { XtFree(nfn); return NULL; }
  else return nfn;
}



/*
   initialiseXReduce():

   Set up things like the output-history and input-pending lists; also 
   tell Reduce to read in the initialisation file (so that XReduce can
   handle prompts and suchlike).
*/

/*ARGSUSED*/
void initialiseXReduce(refW)
  Widget refW;
{
  char *initCommand;
  char *initFile;
  int   tempfd;
  int   i;

  reduceOutputBuffer
    = (char     *)XtMalloc(app_data.outputBufferSize + 1);
  initCommand
    = (char     *)XtMalloc(PATH_MAX + strlen(app_data.reduceInitFile));
  reduceHistory
    = (HistList *)XtMalloc(sizeof(HistList));

  reduceHistory         = CreateNewVerbal();
  endOfHistory          = reduceHistory;
  endOfManaged          = reduceHistory;
  reduceOutputPoint     = reduceOutputBuffer;
  reduceOutputRemaining = 0;
  linesInInputHistory   = 0;
  inputFromChar         = -1L;
  pendingInput          = NULL;
  lastInput             = NULL;
  waitingToInterleave   = False;

  for (i = 0; i < app_data.historyPaneHeight / verbalHeight - 2; ++i)
    AddTextToVerbal(reduceHistory, "\n", True);

  if (!(initFile = EnsureFilename(app_data.reduceInitFile)) ||
      ((tempfd = open(initFile, O_RDONLY)) == -1)) {
    fprintf(stderr,"Could not open Reduce init file \"%s\"\n",
	    app_data.reduceInitFile);
    red_err("Can't start up Reduce");
  }
  else close(tempfd);

  sprintf(initCommand, "in \"%s\"$\n", initFile);
  write(MeToReduce[1], initCommand, strlen(initCommand));
  XtFree(initCommand);
  XtFree((char *)initFile);
}



void installIcon(topLevel)
  Widget topLevel;
{
  Pixmap iconPixmap;
  Arg    arg;

  iconPixmap =
    XCreateBitmapFromData
      (XtDisplay(topLevel), RootWindowOfScreen(XtScreen(topLevel)),
       xreduce_bits, xreduce_width, xreduce_height);

  XtSetArg(arg, XtNiconPixmap, iconPixmap);
  XtSetValues(topLevel, &arg, 1);
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
  XtIntervalId *id;
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

  stP = (int *)XtMalloc(sizeof(int));
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

    if (WEXITSTATUS(*stP) == 0)
      XtAppAddTimeOut(app_ctxt,  500L, ReduceSigChldAux, stP);
    else
      XtAppAddTimeOut(app_ctxt, 5000L, ReduceSigChldAux, stP);
  else XtFree((char *)stP);
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



void ParseDefaultReduceArgs(argcP,argvP)
  int    *argcP;
  char ***argvP;
{
  char **argvSpare;
  int    i;
  int    j;
  int    k = 1;

  if (!(app_data.reduceOptions)) return;

  for (i = 1, j = 0; app_data.reduceOptions[j];
            ++j) if (app_data.reduceOptions[j] == ' ') ++i;

  if (j == 0) return;

  argvSpare    = (char **)XtMalloc((*argcP + i + 1) * sizeof(char *));
  argvSpare[0] = (*argvP)[0];

  for (i = 0, j = 0; app_data.reduceOptions[j];
            ++j) if (app_data.reduceOptions[j] == ' ' && j > i) {
      argvSpare[k] = (char *)XtMalloc((j - i + 1) * sizeof(char));
      strncpy(argvSpare[k], app_data.reduceOptions + i, (size_t)(j - i));
      argvSpare[k][j - i] = 0; i = j + 1; ++ k;
    };

  if (j > i) {
    argvSpare[k] = (char *)XtMalloc((j - i + 1) * sizeof(char));
    strncpy(argvSpare[k], app_data.reduceOptions + i, (size_t)(j - i));
    argvSpare[k][j - i] = 0; ++ k;
  }

  for (i = 1; i < *argcP; ++i, ++k) argvSpare[k] = (*argvP)[i];

   argvSpare[k] = NULL;
  *argvP        = argvSpare;
  *argcP        = k;
}



/*
   clueless-request@xreduce.rand.org
*/

void ComplainAboutSyntax(argc,argv)
  int    argc;
  char **argv;
{
  int     i;
  int     copyBack = 0;
  Boolean cont = False;
  Boolean talk = True;

  for (i = 1; i < argc; i++) {

    argv[i - copyBack] = argv[i];

    if (strcmp(argv[i], "-quiet") == 0) {
      cont = True;
      talk = False;
      copyBack ++;
    }
    else if (strcmp(argv[i], "-continue") == 0) {
      cont = True;
      talk = True;
      copyBack ++;
    }
    else if (strcmp(argv[i], "-despair")  == 0) {
      cont = False;
      talk = True;
      copyBack ++;
    }
    else if (strcmp(argv[i], "-writehelpix") == 0) {
      cont = True;
      talk = False;
      writeHelpIx = True;
      copyBack ++;
    }
    else if (strcmp(argv[i], "-query") == 0 ||
	     strcmp(argv[i], "-q")     == 0 ||
	     strcmp(argv[i], "-?")     == 0) {

      fprintf(stderr,
	      "\nXR accepts all of the standard X Toolkit\n");
      fprintf(stderr,
	      "options, as well as the following:\n\n");
      fprintf(stderr,
	      "Option         Description                                ");
      fprintf(stderr, "X Resource\n");
      fprintf(stderr,
	      "------         -----------                                ");
      fprintf(stderr, "----------\n");
      fprintf(stderr,
	      "-rpath         Absolute path of dir of Reduce executable  ");
      fprintf(stderr, "reducePath\n");
      fprintf(stderr,
	      "-rname         Filename of Reduce executable              ");
      fprintf(stderr, "reduceName\n");
      fprintf(stderr,
	      "-rimage        Absolute pathname of Reduce image file     ");
      fprintf(stderr, "reduceImageFile\n");
      fprintf(stderr,
	      "-rinitfile     Absolute pathname of Reduce startup file   ");
      fprintf(stderr, "reduceInitFile\n");
      fprintf(stderr,
	      "-rhelpfile     Absolute pathname of Reduce Help Info file ");
      fprintf(stderr, "reduceHelpFile\n");
      fprintf(stderr,
	      "-inputpanefn   Font for use in the active input text pane ");
      fprintf(stderr, "inputPaneFont\n");
      fprintf(stderr,
	      "-inputhistfn   Font for use in the input history pane     ");
      fprintf(stderr, "inputHistoryFont\n");
      fprintf(stderr,
	      "-buttonfn      Font for the option buttons                ");
      fprintf(stderr, "optionButtonFont\n");
      fprintf(stderr,
	      "-outputtextfn  Font for textual output                    ");
      fprintf(stderr, "outputTextFont\n");
      fprintf(stderr,
	      "-asciifn       Font for ASCII in graphical output         ");
      fprintf(stderr, "normalAsciiFont\n");
      fprintf(stderr,
	      "-smallasciifn  Font for exponent-size ASCII               ");
      fprintf(stderr, "smallAsciiFont\n");
      fprintf(stderr,
	      "-greekfn       Font for Greek characters                  ");
      fprintf(stderr, "normalGreekFont\n");
      fprintf(stderr,
	      "-smallgreekfn  Font for exponent-size Greek characters    ");
      fprintf(stderr, "smallGreekFont\n");
      fprintf(stderr,
	      "-usegreek      Use the specified Greek font    [default]  ");
      fprintf(stderr, "useGreekFont\n");
      fprintf(stderr,
	      "-usenogreek    Print full names of Greek chars, in Ascii  ");
      fprintf(stderr, "useGreekFont\n");
      fprintf(stderr,
	      "-symfn         Font for mathematical symbols              ");
      fprintf(stderr, "normalSymbolFont\n");
      fprintf(stderr,
	      "-smallsymfn    Font for exponent-size maths symbols       ");
      fprintf(stderr, "smallSymbolFont\n");
      fprintf(stderr,
	      "-verbfn        Font for verbatim text in output and help  ");
      fprintf(stderr, "verbatimFont\n");
      fprintf(stderr,
	      "-usesymbol     Use the specified Symbol font   [default]  ");
      fprintf(stderr, "useSymbolFont\n");
      fprintf(stderr,
	      "-usenosymbol   Draw all mathematical symbols by hand      ");
      fprintf(stderr, "useSymbolFont\n");
      fprintf(stderr,
	      "-helptextfn    Font for normal text in help window        ");
      fprintf(stderr, "helpTextFont\n");
      fprintf(stderr,
	      "-helpxreffn    Font for help cross-reference highlights   ");
      fprintf(stderr, "helpXrefFont\n");
      fprintf(stderr,
	      "-helptitlefn   Font for titles in help text window        ");
      fprintf(stderr, "helpTitleFont\n");
      fprintf(stderr,
	      "-pstextfn      Font for text in PostScript printer output ");
      fprintf(stderr, "psTextFont\n");
      fprintf(stderr,
	      "-pssymbolfn    Font for Greek and symbols in PostScript   ");
      fprintf(stderr, "psSymbolFont\n");
      fprintf(stderr,
	      "-psasciifn     Font for ASCII in graphical PostScript     ");
      fprintf(stderr, "psAsciiFont\n");
      fprintf(stderr,
	      "-iheight       Height of input history pane, in pixels    ");
      fprintf(stderr, "inputPaneHeight\n");
      fprintf(stderr,
	      "-oheight       Height of output history pane, in pixels   ");
      fprintf(stderr, "historyPaneHeight\n");
      fprintf(stderr,
	      "-fheight       Height of font selection popup, in pixels  ");
      fprintf(stderr, "fontSelectorHeight\n");
      fprintf(stderr,
	      "-fwidth        Width of font selection popup, in pixels   ");
      fprintf(stderr, "fontSelectorWidth\n");
      fprintf(stderr,
	      "-graphspace    Gap between graphic output lines, pixels   ");
      fprintf(stderr, "graphicalLineSpace\n");
      fprintf(stderr,
	      "-history       Number of lines of scrollable output       ");
      fprintf(stderr, "reduceHistoryMax\n");
      fprintf(stderr,
	      "-hexcess       Number of extra lines between deletions    ");
      fprintf(stderr, "reduceHistoryExcess\n");
      fprintf(stderr,
	      "-linelength    Number of characters per line of text      ");
      fprintf(stderr, "widthInColumns\n");
      fprintf(stderr,
	      "-ibuf          Size of buffer for user input              ");
      fprintf(stderr, "inputBufferSize\n");
      fprintf(stderr,
	      "-obuf          Size of Reduce -> XR buffer                ");
      fprintf(stderr, "outputBufferSize\n");
      fprintf(stderr,
	      "-ondelay       Time (ms) during which output updated      ");
      fprintf(stderr, "outputOnDelay\n");
      fprintf(stderr,
	      "-offdelay      Time (ms) between output updates           ");
      fprintf(stderr, "outputOffDelay\n");
      fprintf(stderr,
	      "-reverse       Use reverse video for formula graphics     ");
      fprintf(stderr, "reverseGraph\n");
      fprintf(stderr,
	      "-forward       Do not use reverse video        [default]  ");
      fprintf(stderr, "reverseGraph\n");
      fprintf(stderr,
	      "-bmatch        Beep for unmatched brackets     [default]  ");
      fprintf(stderr, "matchBrackets\n");
      fprintf(stderr,
	      "-bnomatch      Let users type whatever rubbish they like  ");
      fprintf(stderr, "matchBrackets\n");
      fprintf(stderr,
	      "-bforcematch   Stop unmatched brackets from being typed   ");
      fprintf(stderr, "forceBracketMatch\n");
      fprintf(stderr,
	      "-bnoforcematch Allow typing unmatched brackets [default]  ");
      fprintf(stderr, "forceBracketMatch\n");
      fprintf(stderr,
	      "-bflashtime    Time (ms) to highlight a matching bracket  ");
      fprintf(stderr, "bracketFlashTime\n");
      fprintf(stderr,
	      "-mclicktime    Time (ms) to allow for button double-click ");
      fprintf(stderr, "multiClickTime\n");
      fprintf(stderr,
	      "-pagemode      Wait for response whenever screen fills    ");
      fprintf(stderr, "pageMode\n");
      fprintf(stderr,
	      "-nopagemode    Scroll on, ignoring overflow    [default]  ");
      fprintf(stderr, "pageMode\n");
      fprintf(stderr,
	      "-pointerjump   Warp pointer to default choices [default]  ");
      fprintf(stderr, "pointerJump\n");
      fprintf(stderr,
	      "-nopointerjump Don't warp pointer to default choices      ");
      fprintf(stderr, "pointerJump\n");
      fprintf(stderr,
	      "-scalefns      Allow scaling scalable fonts    [default]  ");
      fprintf(stderr, "scaleFonts\n");
      fprintf(stderr,
	      "-noscalefns    Prevent scaling (eg if server can't do it) ");
      fprintf(stderr, "scaleFonts\n");
      fprintf(stderr,
	      "-texfns        Allow use of TeX PCF fonts      [default]  ");
      fprintf(stderr, "ignoreTeXFonts\n");
      fprintf(stderr,
	      "-notexfns      Filter out PCF fonts in font selector      ");
      fprintf(stderr, "ignoreTeXFonts\n");
      fprintf(stderr,
	      "-log           Log session to a file                      ");
      fprintf(stderr, "logToFile\n");
      fprintf(stderr,
	      "-nolog         Do not log the session          [default]  ");
      fprintf(stderr, "logToFile\n");
      fprintf(stderr,
	      "-logfile       Pathname of file to which to log session   ");
      fprintf(stderr, "logFile\n");
      fprintf(stderr,
	      "-writehelpix   Make and write help index file, then exit  \n");
      fprintf(stderr,
	      "-quiet         Keep quiet (no inessential warnings); shut \n");
      fprintf(stderr,
	      "               up about unrecognised command line options \n");
      fprintf(stderr,
	      "-continue      Complain, but continue anyway\n");
      fprintf(stderr,
	      "-despair       Complain and give up            [default]  ");
      fprintf(stderr,
	      "\n-query, -q, -? Just display this table, then exit\n");
      fprintf(stderr,
	      "\nThese options take one argument, except -usegreek, ");
      fprintf(stderr,
	      "-usenogreek,\n-usesymbol, -usenosymbol, -reverse, -forward, ");
      fprintf(stderr,
	      "-usesetclear, -usecopy,\n-bmatch, ");
      fprintf(stderr,
	      "-bnomatch, -bforcematch, -bnoforcematch, -pagemode, ");
      fprintf(stderr,
	      "-nopagemode,\n-scalefns, -noscalefns, -texfns, -notexfns,");
      fprintf(stderr,
	      "-log, -nolog, -writehelpix,\n-quiet, -continue, -despair and ");
      fprintf(stderr,
	      "-query, which take none.\n");
      fprintf(stderr,
	     "\nFor further details, please consult the XR manual.\n\n");
      fflush(stderr);
      exit(0);
    }
  }

  argc -= copyBack;

  if (talk) {

    fprintf(stderr, "\nXR: Unknown command line option %s.  For a long\n",
	    argv[1]);
    fprintf(stderr, "list of recognised options, type xreduce -query.\n\n");

    if (cont) {

      fprintf(stderr, "I am continuing anyway, and passing the following\n");
      fprintf(stderr, "arguments to Reduce: ");

      for (i = 1; i < argc; i++)
	fprintf(stderr, " %s", argv[i]);

      fprintf(stderr,"\n");
    }
    fflush(stderr);

  } else quietMode = True;

  if (!cont) exit(1);
}


void ApplyColourFallbacks(display)
  Display *display;
{
  int                i;
  XColor             col;
  Colormap  cmap;
  String            *fallbacks;
  XrmDatabase        dispbase;

  dispbase = XtDatabase(display);

  /* Find out which set of fallbacks we should be using for this    */
  /* screen; note that greyscale screens may end up being assigned  */
  /* colour fallbacks which may be difficult to read.  Running with */
  /* -fg black -bg white is generally all right on such displays.   */

  if (DefaultDepth(display, 0) < 2) fallbacks = FallbackMono;
  else {

    cmap = XCreateColormap(display, RootWindow(display, 0),
			   DefaultVisual(display, 0), AllocNone);

    /* Do we understand the natty modern "rgb:xxxx/xxxx/xxxx" syntax? */

    if (XParseColor(display, cmap, "rgb:1234/1234/1234", &col))
      fallbacks = FallbackColour;
    else {

      /* No?  What about the old #xxxxxx RGB syntax? */

      if (XParseColor(display, cmap, "#AABBCC", &col))
	fallbacks = FallbackOldColour;
      else {

	if (!quietMode)
	  fprintf(stderr,"XR: Server won't parse colour names, using mono\n");
	fallbacks = FallbackMono;
      }
    }

    XFreeColormap(display, cmap);
  }

  for (i = 0; Fallbacks[i]; ++i) XrmPutLineResource(&dispbase, Fallbacks[i]);
  for (i = 0; fallbacks[i]; ++i) XrmPutLineResource(&dispbase, fallbacks[i]);
}



int main(argc,argv,envp)
  int    argc;
  char **argv;
  char **envp;
{
  Widget       topLevel;	                    /* The whole caboodle */
  Display     *display;
  char        *redFullName;
  char        *rP;
  char        *rN;
  char        *title;
  int          i;
  int          pid;
  int          ppid = getpid();
  int          plen;
  int          nlen;
  int          tempfd;
  Arg          arg;
  String      *fallbacks;
  XrmDatabase  dispbase;
  XWMHints   * xwmhints;

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

  XtToolkitInitialize();
  app_ctxt = XtCreateApplicationContext();
  if (!(display = XtOpenDisplay(app_ctxt, NULL, "xr", "XR", XReduceOptions,
				XtNumber(XReduceOptions), &argc, argv)))
    red_err("Couldn't open display");


  ApplyColourFallbacks(display);
  topLevel = XtAppCreateShell("xr", "XR", applicationShellWidgetClass,
			      display, NULL, 0);
  XtGetApplicationResources(topLevel, &app_data, resources,
			    XtNumber(resources), NULL, 0);

  if (argc > 1) ComplainAboutSyntax(argc, argv);
  ParseDefaultReduceArgs(&argc,&argv);

  if (app_data.foundDefaults == False) {
    fprintf(stderr,"XR:  Cannot find X defaults file\n");
    fflush(stderr);
    exit(1);
  }

  if (writeHelpIx) {

    int    ext;
    char * hF;

    HelpInitialise(topLevel, 500, 600, "XR Help", NULL);
    HelpButton(0, 1, 0);
    ext = HelpWriteIndexFile();
    HelpCloseHelpFile();

    XtFree(hF);

    fprintf(stderr,"\nXR exiting.\n");
    exit(ext);

  } else {

#ifdef EXPLICIT_EDITRES
    XtAddEventHandler(topLevel, (EventMask) 0, True,
		      _XEditResCheckMessages,
		      NULL);
#endif

    if (pid = fork()) {

      if (pid < 0) {

	perror("XR");
	fprintf(stderr,"XR: Could not fork() Reduce process\n");
	exit(-1);
      }

      reduceProcessID = pid;
          myProcessID = ppid;

      installSignalHandlers();

      reduceCommandStart  =
      reduceCommandEnd    =
      reduceHistoryNumber = 0;
      historyMode         = ReduceVerbal;

      XSetErrorHandler(red_Xnf_err);
      XSetIOErrorHandler(red_XIO_err);
      XtAppSetErrorHandler(app_ctxt, red_Xt_err);

#ifdef HAVE_GETHOSTNAME

      title = (char *)XtMalloc(200);
      strcpy(title, "XR: An X Interface for REDUCE  [");
      plen = strlen(title);
      if (gethostname(title + plen, 199 - plen)) {
	title[plen - 2] = 0;
      } else {
	title[plen = strlen(title)] = ']';
	title[plen + 1] = 0;
      }

#else

      title = (char *)XtMalloc(200);
      strcpy(title, "XR: An X Interface for REDUCE");

#endif

      XtSetArg(arg, XtNtitle, title);
      XtSetValues(topLevel, &arg, 1);

      installIcon       (topLevel);
      createWidgets     (topLevel); 
      initialiseXReduce (topLevel);
      XtRealizeWidget   (topLevel);
      initialiseFontSel (topLevel);
      setupGraphics     (topLevel);
      setupMessages     (topLevel);
      initialiseOutput  (topLevel);
      initialisePrinter (topLevel);
      xwmhints = XGetWMHints(XtDisplay(topLevel), XtWindow(topLevel));
      xwmhints->input = True;
      xwmhints->flags = (xwmhints->flags | InputHint);
      XSetWMHints(XtDisplay(topLevel), XtWindow(topLevel),xwmhints);
      XSetInputFocus(XtDisplay(topLevel), XtWindow(topLevel),RevertToParent,
           CurrentTime);

      HelpInitialise      (topLevel, 500, 600, "XR Help", GuessHelpContext);
      HelpSetTextFont     (app_data.helpTextFont     );
      HelpSetXrefFont     (app_data.helpXrefFont     );
      HelpSetButtonFont   (app_data.optionButtonFont );
      HelpSetVerbatimFont (app_data.verbatimFont     );
      HelpSetTitleFont    (app_data.helpTitleFont    );

      wmPrtcls[0] =
	XInternAtom(XtDisplay(topLevel), "WM_DELETE_WINDOW", False);
      wmPrtcls[1] =
	XInternAtom(XtDisplay(topLevel), "WM_SAVE_YOURSELF", False);
      XtOverrideTranslations
	(topLevel,
	 XtParseTranslationTable("<Message>WM_PROTOCOLS: reduce-quit()"));
      XSetWMProtocols(XtDisplay(topLevel), XtWindow(topLevel), wmPrtcls, 2);

      XtAppMainLoop     (app_ctxt);
      red_err("XtAppMainLoop failed");
      exit(-1);
    
    } else {

      removeSignalHandlers();	/* Just to make sure! */

      if (!(rP = EnsureFilename(app_data.reducePath))) {

	app_data.reduceName = XtNewString("reduce");
	if (!(app_data.reducePath = EnsureFilename("$reduce"))) {

	  fprintf(stderr,"XR: Could not open directory \"%s\"\n",
		  app_data.reducePath);
	  if (!quietMode)
	    fprintf(stderr,"XR: Initialisation file is probably wrong\n");
	  sleep(1); exit(1);
	}
      }

      plen = strlen(rP);
      nlen = strlen(rN = XtNewString(app_data.reduceName));

      redFullName = (char *)XtMalloc(plen + nlen + 2);
      strcpy(redFullName,            rP);
      strcpy(redFullName + plen + 1, rN);
      redFullName[plen] = '/';

      XtFree(rP);
      XtFree(rN);

      if ((tempfd = open(redFullName, O_RDONLY)) == -1) {

	fprintf(stderr,"XR: No Reduce binary \"%s\"\n", redFullName);
	if (!quietMode)
	  fprintf(stderr,"XR: Initialisation file is probably wrong\n");

	if (strcmp(app_data.reduceName, "reduce")) {

	  XtFree(redFullName);
	  if  (!(redFullName = EnsureFilename("$reduce/reduce")) ||
	       ((tempfd = open(redFullName, O_RDONLY)) == -1)) {
	    sleep(1); exit(1);
	  } else close(tempfd);
	  if  (!quietMode)
	    fprintf(stderr,"XR: Using \"%s\" instead\n", redFullName);
	}
      }
      else close(tempfd);

      if ((app_data.reduceImageFile) &&
	  (app_data.reduceImageFile[0])) {

	char **sargv;
	int    i;

	sargv  = (char **)XtCalloc(argc + 3, sizeof(char *));
	for (i = 0; i < argc; ++i) sargv[i] = argv[i];
	sargv[ i   ] = XtNewString("-f");
	sargv[ i+1 ] = EnsureFilename(app_data.reduceImageFile);
	sargv[ i+2 ] = NULL;
	argv = sargv;

	if (!argv[i+1]) {
	  fprintf(stderr,"XR: No Reduce image \"%s\"\n",
		  app_data.reduceImageFile);
	  if (!quietMode)
	    fprintf(stderr,"XR: Initialisation file is probably wrong\n");
	  sleep(1); exit(1);
	}

	if (!quietMode) {
	  fprintf(stderr, "\nUsing %s as Lisp executable\n", redFullName);
	  fprintf(stderr,   "Using %s as Reduce image\n", argv[i+1]);
	}
	fflush(stderr);

      } else {

	if (!quietMode) {
	  fprintf(stderr, "\nUsing %s as Reduce executable\n", redFullName);
	}
	fflush(stderr);
      }

      close(MeToReduce[1]  );
      dup2 (MeToReduce[0],0);
      close(ReduceToMe[0]  );
      dup2 (ReduceToMe[1],1);
      close(ReduceErrs[0]  );
      dup2 (ReduceErrs[1],2);

      argv[0] = app_data.reduceName;
      execve(redFullName, argv, envp);

      fprintf(stderr, "XR: Could not execve()\n");
      perror("XR"); 
      fflush(stderr);
      sleep(1);
      exit(-1);
    }
  }
}

