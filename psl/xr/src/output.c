
/*
   Reduce output handling module.
*/

#include "xreduce.h"		/* constants, app-defaults etc */
#include "main.h"		/* import the global variables */
#include "widgets.h"
#include "verbal.h"
#include "xredplus.h"
#include "message.h"
#include "manager.h"
#include "file.h"

#define firstPromptChar   '1'
#define secondPromptChar  ':'
#define promptBeginEscape 0x1
#define promptEndEscape   0x2	/* was '`' */
#define yespStartEscape   0x3
#define initialBadPrompts  1

static XtInputId readerId;
static Widget    referenceWidget;
static Boolean   streamReadOn    = False;
static Boolean   handleOutput    = True;
Boolean          preCmdFlag      = False; /* Should I call something before */
void           (*preCmd)()       = NULL;  /* next prompt?   If so, what fn? */
int              promptPresent   = 0;
static int       promptPast      = 0;
static int       promptFuture    = 0;
static int       promptSpace     = 0;
static int       stillBadPrompts = initialBadPrompts;
                                /* Yeeurrch. See below for use */



/*
   GetReduceOutput():

   Gets something from the Reduce socket, deals with mode-changing characters
   and prompts, and sends it on to a display function.

   We have a complicated way of dealing with prompts.  The xreduce.red file
   that should have been read into Reduce at startup should set things up so
   that every prompt is preceded by a special character (promptBeginEscape,
   normally id 1) and succeeded by a different special character
   (promptEndEscape, normally id 96 or ASCII backquote).  When the backquote
   is encountered, InterleaveInput is called to place the user's next input
   line on the output at the prompt.  Naturally if things should get out of
   sync for any reason, there will be quite a bit of trouble.  If things all
   go horribly wrong and the user accidentally manages to produce one of the
   special characters at the wrong moment, there is some hope: a prompt is
   only registered if the end escape occurs within eight characters of the
   begin escape.
*/

/*ARGSUSED*/
void GetReduceOutput(client_data,fid,id)
  caddr_t    client_data;
  int       *fid;
  XtInputId *id;
{ 
  int  nbytes;
  int  offset;
  int  copycount;

  SetOutputToBottom();
  if (waitingToInterleave)
    if (waitingToInterleave = InterleaveInput()) return;

  if (reduceOutputBuffer == reduceOutputPoint) {
    if ((nbytes = read(*fid,
		       reduceOutputBuffer,
		       app_data.outputBufferSize - 2)) < 0)
      
      red_err("Reduce output stream has ended.");

  } else nbytes = reduceOutputRemaining;

  printf("nbytes= %d\n",nbytes);


  if (app_data.logToFile) WriteToLogFile(reduceOutputBuffer,nbytes);

  if (nbytes) {

    offset    = 0;
    copycount = 0;
    reduceOutputPoint[nbytes] = 0x0;   /* Make sure it's a good string */ 
   
    while (offset <= nbytes) {          /* Trace down the string        */
      
      switch(reduceOutputPoint[offset]) {

      case END_OF_LINE:
	switch(historyMode) {
	case ReduceVerbal:
	  if (offset > 0 &&
	      reduceOutputPoint[offset-1] == END_OF_LINE)
	    reduceOutputPoint[offset-1] = ' ';
	  break;
	default:
	  break;
	}
	break;

      case yespStartEscape:
	reduceOutputPoint[offset] = 0x0;
	switch(historyMode) {
	case ReduceVerbal:
	  PlaceSomeLines(reduceOutputPoint + copycount);
	  historyMode = ReduceMessage;
	  break;
	case ReduceGraphical:
	  PlaceSomeGraphics(reduceOutputPoint + copycount, True, True);
	  historyMode = ReduceMessage;
	  break;
	case ReduceMessage:
	  PlaceSomeMessage(referenceWidget, reduceOutputPoint + copycount,
			   False, False, True);
	  break;
	}
	copycount = offset + 1;
	break;

      case firstPromptChar:
	if ((stillBadPrompts) &&        /* Yes indeed.  How elegant     */
	    (offset < nbytes) &&
	    (reduceOutputPoint[offset+1] == secondPromptChar)) {
	  if (stillBadPrompts == initialBadPrompts) {
	     reduceOutputPoint[offset] = 0x0;
	     PlaceSomeLines(reduceOutputPoint + copycount);
	  }
	  offset ++;
	  stillBadPrompts --;
	  copycount = offset + 2;
	}
	break;
	
      case REDUCE_TEX_ON:	              /* Found a mode change?  */
	reduceOutputPoint[offset] = 0x0;      /* Display string so far */
	switch(historyMode) {
	case ReduceVerbal:
	  if (offset < 2 ||
	      reduceOutputPoint[offset-1] != END_OF_LINE ||
	      reduceOutputPoint[offset-2] != 0x0)
	    PlaceSomeLines(reduceOutputPoint + copycount);
	  historyMode = ReduceGraphical;
	  break;
	case ReduceMessage:
	  PlaceSomeMessage(referenceWidget, reduceOutputPoint + copycount,
			   True, False, True);
	  historyMode = ReduceGraphical;
	  break;
	case ReduceGraphical:
	  PlaceSomeGraphics(reduceOutputPoint + copycount, False, False);
	  break;
	}
	copycount = offset + 1;
	break;

      case REDUCE_TEX_OFF:
	reduceOutputPoint[offset] = 0x0;
	switch(historyMode) {
	case ReduceVerbal:
	  PlaceSomeLines(reduceOutputPoint + copycount);
	  break;
	case ReduceMessage:
	  PlaceSomeMessage(referenceWidget, reduceOutputPoint + copycount,
			   True, False, True);
	  break;
	case ReduceGraphical:
	  if (offset < nbytes &&
	      reduceOutputPoint[offset + 1] == END_OF_LINE)
	    offset ++;
	  if (offset < nbytes &&
	      reduceOutputPoint[offset + 1] == REDUCE_TEX_ON)
	    PlaceSomeGraphics(reduceOutputPoint + copycount, True, False);
	  else
	    PlaceSomeGraphics(reduceOutputPoint + copycount, True, True);
	  historyMode = ReduceVerbal;
	  break;
	}
	copycount = offset + 1;
	break;

      case promptBeginEscape:	      /* A prompt is about to begin... */
	if (preCmdFlag && preCmd) preCmd(); /* Any custom preprompt fn */
	reduceOutputPoint[offset] = 0x0;
	promptFuture = atoi(reduceOutputPoint+offset+1);
				      /* Get the number of this prompt */ 
	switch(historyMode) {
	case ReduceVerbal:
	  PlaceSomeLines(reduceOutputPoint + copycount);
	  promptSpace = 8;
	  break;
	case ReduceMessage:
	  PlaceSomeMessage(referenceWidget, reduceOutputPoint + copycount,
			   False, False, True);
	  promptSpace = 16;
	  break;
	case ReduceGraphical:
	  PlaceSomeGraphics(reduceOutputPoint + copycount, True, True);
	  historyMode = ReduceVerbal;
	  promptSpace = 8;
	  break;
	}
	copycount = offset + 1;
	break;
	
      case promptEndEscape:	   /* Reduce sends this after a prompt */
	if (promptSpace > 0) {	/* Check it's a prompt, not accidental */
	  UndisplayWatchCursor();
	  reduceOutputPoint[offset] = 0x0;    /* Display string so far */
	  promptSpace   = 0;
	  promptPast    = promptPresent;
	  promptPresent = promptFuture;
	  PlacePromptMarker(promptPast != promptPresent);
	  switch(historyMode) {
	  case ReduceVerbal:
	    PlaceSomeLines(reduceOutputPoint + copycount);
	    PlaceSomeLines(" ");
	    waitingToInterleave     = InterleaveInput();
	    if (waitingToInterleave) {
	      reduceOutputPoint     = reduceOutputPoint + offset + 1;
	      reduceOutputRemaining = nbytes - offset - 1;
	      if (app_data.pageMode) FreeManager();
	      return;
	    }
	    break;
	  case ReduceMessage:
	    PlaceSomeMessage(referenceWidget, reduceOutputPoint + offset,
			     True, False, True);
				/* No more; just display */
	    historyMode = ReduceVerbal;
	    break;
	  case ReduceGraphical:
	    PlaceSomeGraphics(reduceOutputPoint + copycount, False, False);
	    break;
	  }
	  copycount = offset + 1;
	  break;
	}
	
      case 0x0:		       /* NULL might not mean end of string */
	switch(historyMode) {
	case ReduceVerbal:
	  PlaceSomeLines(reduceOutputPoint + copycount);
	  break;
	case ReduceMessage:
	  PlaceSomeMessage(referenceWidget, reduceOutputPoint + copycount,
			   False, False, True);
	  break;
	case ReduceGraphical:
	  PlaceSomeGraphics(reduceOutputPoint + copycount, False, False);
	  break;
	}
	if (offset < nbytes) copycount = offset + 1;
	break;
      }

      offset ++;
      if (promptSpace > 0) promptSpace --;
    }
  }
  reduceOutputPoint = reduceOutputBuffer;
}



/*ARGSUSED*/
void HandleReduceErrorStream(client_data, fid, id)
  caddr_t    client_data;
  int       *fid;
  XtInputId *id;
{
  char tempbuffer[256];
  int  nbytes;
  int  i;

  if ((nbytes = read(*fid, tempbuffer, 255)) <= 0) return;

  tempbuffer[nbytes] = 0;
  fprintf(stderr,"XR: [ child err ] ");

  for (i = 0; tempbuffer[i]; ++i) {

    if (tempbuffer[i] == END_OF_LINE && tempbuffer[i+1])
      fprintf(stderr,"\nXR: [ continued ] ");

    else putc(tempbuffer[i], stderr);
  }
}


/*ARGSUSED*/
void HandleReduceOutputStream(client_data)
  caddr_t client_data;
{
  if (!handleOutput) streamReadOn = True;

  switch (streamReadOn) {

  case True:
    streamReadOn = False;
    XtRemoveInput(readerId);

    if (handleOutput)
      XtAppAddTimeOut(app_ctxt,
		      app_data.outputOffDelay,
		      HandleReduceOutputStream, 0);
    break;
      
  case False:
    streamReadOn = True;
    readerId = XtAppAddInput(app_ctxt,
			     ReduceToMe[0],
			     (XtPointer)XtInputReadMask,
			     GetReduceOutput, 0);
    if (handleOutput)
      XtAppAddTimeOut(app_ctxt,
		      app_data.outputOnDelay,
		      HandleReduceOutputStream, 0);
    break;
  }
}



void RestartReduceOutput()
{
  handleOutput = True;
  HandleReduceOutputStream(0);
}


void UnHandleReduceOutput()
{
  handleOutput = False;
}


void initialiseOutput(topLevel)
  Widget topLevel;
{
  referenceWidget = topLevel;
}

