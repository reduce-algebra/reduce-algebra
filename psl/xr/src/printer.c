
/*
   printer.c

   Module concerning sending output to a printer, or to a file for later
   editing or printing.  I'd propose that the protocol be as follows, at
   least for the first attempt:

   o  When the Print button on the Option box is pressed, pop up a small box
      with an editable filename, initially chosed uniquely, a printer name,
      presumably defaulting to "" (possibly a resource?), an editable history
      number, originally chosen to be the previous prompt number, toggle
      buttons for "PostScript", "LaTeX" and "Plain Text", and
      command buttons for "Print" and "Write to File".  These should do the
      following:

      o  Filename box:  Choose a filename to send to.  If "Print" is used,
         this filename is ignored.

      o  Printer box:  Choose a printer to send to.  If "Write to File" is
         used, it should be ignored.

      o  History number:  Choose the prompt number from which output should
         be printed.  It'd be nice also to have the prompt number where it
	 should stop printing.

      o  PostScript:  Select PS format.  Methinks I'd better go and look
         up some things about PostScript before I try this one.   Obviously,
	 PS can be sent either to a file or to the printer.  There will be
	 buttons to choose paper size for PostScript.

      o  LaTeX:  Select LaTeX format.  This should work for file only.
         Should it be encapsulated as a complete document?  Probably.

      o  Plain Text:  To file or printer.

      o  Print:  Sends the selected output to the selected printer.  Possibly
         I should include a "List Printer Queue" button, but I think that may
	 be a bit advanced for the moment.  (Just a tad...)

      o  Write to File:  Sends the printable output to the selected file.
         Should overwrite, not append; hence, the default filename should be
	 rechosen every time the Print box is called up.

   o  Oh yes, and there should probably also be a label for information and
      whatnot, and a Cancel button.

   Chris Cannam, Berlin, April 1993
*/


#include "xreduce.h"
#include "main.h"
#include "option.h"
#include "widgets.h"
#include "output.h"
#include "input.h"
#include "xredplus.h"
#include "fancy.h"

#define WIDGET(q,z,k,v) { q = XtCreateManagedWidget((z),(k),(v),NULL,0); }
#define BEGARG          { Arg arg;
#define SETARG(q,z,k)   { XtSetArg(arg,(z), (k)); XtSetValues((q),&arg,1); }
#define GETARG(q,z,k)   { XtSetArg(arg,(z),&(k)); XtGetValues((q),&arg,1); }
#define FINARG          }

#define promptBeginEscape 0x1
#define promptEndEscape   0x2

typedef enum {
  PrintPlainTextN = 0,
  PrintPostScriptN,
  PrintLaTeXN
} PrintType;

typedef enum {
  PaperA4PortraitN = 0,
  PaperA4LandscapeN,
  PaperLetterPortraitN,
  PaperLetterLandscapeN
} PaperType;

static Dimension printWd = 500;
static Dimension printHt = 300;
static PrintType printType;
static PaperType paperType;
static Boolean   useFile;
static Boolean   printBoxInstalled = False;
static FILE     *sendFile;
static FILE     *tempFile;
static char     *fileName;
static char     *tempFileName;
static char      printerName[256];
static int       promptNo;
static int       endPrmNo;
static int       paperWd;
static int       paperHt;
static int       pointSz = 12;
static int       spacing = 2;
static int       currSX;
static int       currSY;
static int       pageCount;
static int       paperSize[4][2] = {
  { 595, 842, },		/* A4 Portrait [x first, then y] */
  { 842, 595, },		/* A4 Landscape  [units: points] */
  { 612, 792, },		/* Letter size Portrait          */
  { 792, 612, },		/* Letter size Landscape         */
};

static Widget printShell;
static Widget printBox;
static Widget printLabel;
static Widget printTextsBox;
static Widget printFileLabel;
static Widget printFilenameBox;
static Widget printFilename;
static Widget printPrinterLabel;
static Widget printPrinterNameBox;
static Widget printPrinterName;
static Widget printHistoryLabel;
static Widget printHistoryNumberBox;
static Widget printHistoryNumber;
static Widget printHistEndLabel;
static Widget printHistEndNumberBox;
static Widget printHistEndNumber;
static Widget printToggleBox;
static Widget printPostScript;
static Widget printLaTeX;
static Widget printPlainText;
static Widget printFile;
static Widget printPrinter;
static Widget printSizeBox;
static Widget printSizeA4;
static Widget printSizeLetter;
static Widget printSizePortrait;
static Widget printSizeLandscape;
static Widget printSizeSize;
static Widget printSizeSpace;
static Widget printQueryShell;
static Widget printQueryDialog;
static Widget printQueryApply;
static Widget printQueryCancel;
static Widget printCommandBox;
static Widget printOK;
static Widget printCancel;
static Widget referenceWidget;

void PrintCancel();
void PrintPlainText();
void PrintPostScript();
void PrintLaTeX();
int  PixelsToPointsX();
int  PixelsToPointsY();


void PrintMessage(btxt, stxt)
  char *btxt;
  char *stxt;
{
  Arg       arg[2];
  char     *ntxt;
  Dimension bHt;

  XtSetArg(arg[0], XtNheight, &bHt);
  XtGetValues(printLabel, arg, 1);

  if (stxt == NULL) ntxt = XtNewString(btxt);
  else {
    ntxt = (char *)XtMalloc(strlen(btxt) + 102);
    sprintf(ntxt, btxt, stxt);
  }

  XtSetArg(arg[1], XtNlabel,  ntxt);
  XtSetArg(arg[0], XtNheight, bHt);
  XtSetValues(printLabel, arg, 2);
  XtFree(ntxt);
}


void PrintSigChld()
{
  /* All is probably well.  Chances are lpr has run and finished, though */
  /* it's possible that it aborted.  Let's not worry about that.         */

  signal(SIGCHLD, ReduceSigChld);
  signal(SIGPIPE, ReduceSigPipe);
}


void PrintSigPipe()
{
  /* Now this is not such good news.  There's presumably a problem here; */
  /* for now I'll just assume that lpr sent something about it to stderr */

  signal(SIGCHLD, ReduceSigChld);
  signal(SIGPIPE, ReduceSigPipe);
}


void PrintPrint()
{
  char *cmd;

  preCmdFlag = False;
  preCmd     = NULL;
  if (!useFile) {
    signal(SIGCHLD, PrintSigChld);  /* when lpr inevitably dies             */
    signal(SIGPIPE, PrintSigPipe);  /* tho' it may get a pipe problem first */
  }

  /* Now try to open the output file or pipe */

  if (useFile) {

    if ((sendFile = fopen(fileName,"w")) == NULL) {
      PrintMessage("Cannot open file \"%s\"", fileName);
      XtSetSensitive(printOK,     True);
      XtSetSensitive(printCancel, True);
      return;
    }
  } else {

    if (strlen(printerName) > 0) {

      cmd = (char *)XtMalloc(strlen(printerName) + 10);
      sprintf(cmd, "lpr -P%s", printerName);
      if ((sendFile = popen(cmd,"w")) == NULL) {

	PrintMessage("Cannot open pipe to \"%s\"", cmd);
	XtFree(cmd);
	XtSetSensitive(printOK,     True);
	XtSetSensitive(printCancel, True);
	return;
      } else XtFree(cmd);
    } else {

      if ((sendFile = popen("lpr","w")) == NULL) {
	PrintMessage("Cannot open pipe to \"lpr\"",NULL);
	XtSetSensitive(printOK,     True);
	XtSetSensitive(printCancel, True);
	return;
      }
    }
  }

  if ((tempFile = fopen(tempFileName, "r")) == NULL) {
    PrintMessage("Bad temp file \"%s\", giving up", tempFileName);
    XtSetSensitive(printOK,     True);
    XtSetSensitive(printCancel, True);
    return;
  }

  rewind(tempFile);

  switch(printType) {

  case PrintPlainTextN:  PrintPlainText();  break;
  case PrintPostScriptN: PrintPostScript(); break;
  case PrintLaTeXN:      PrintLaTeX();      break;
  }

  fclose(sendFile);
  fclose(tempFile);
  unlink(tempFileName); 
  XtSetSensitive(printOK,     True);
  XtSetSensitive(printCancel, True);
  PrintCancel();
  return;
}


void PrintShowCurrent()
{
  Arg   arg[2];
  char *fnm;

  if (fileName)    XtFree(fileName);
  XtSetArg(arg[0], XtNstring, &fnm);

  XtGetValues(printFilename,      arg, 1);
  fileName = XtNewString(fnm);

  XtGetValues(printPrinterName,   arg, 1);
  strcpy(printerName, fnm);

  XtGetValues(printHistoryNumber, arg, 1);
  promptNo = atoi(fnm);

  XtGetValues(printHistEndNumber, arg, 1);
  endPrmNo = atoi(fnm);

  fnm = (char *)XtMalloc(20);
  sprintf(fnm, "Points: %d", pointSz);
  XtSetArg(arg[0], XtNlabel, fnm);
  XtSetValues(printSizeSize, arg, 1);

  sprintf(fnm, "Spacing: %d", spacing);
  XtSetArg(arg[0], XtNlabel, fnm);
  XtSetValues(printSizeSpace, arg, 1);
  XtFree(fnm);

  XtSetArg(arg[0], XtNstate, False);
  XtSetArg(arg[1], XtNstate,  True);

  XtSetSensitive(printFilename,  True);
  XtSetSensitive(printFileLabel, True);
  XtSetSensitive(printFile,      True);
  XtSetSensitive(printPrinter,   True);
  XtSetSensitive(printOK,        True);
  XtSetSensitive(printCancel,    True);

  switch(printType) {

  case PrintPlainTextN:

    XtSetValues(printPlainText,       arg+1, 1);
    XtSetValues(printPostScript,      arg+0, 1);
    XtSetValues(printLaTeX,           arg+0, 1);
    XtSetSensitive(printSizeBox,      False);
    XtSetSensitive(printPrinterLabel, True);
    XtSetSensitive(printPrinterName,  True);

    break;

  case PrintPostScriptN:

    XtSetValues(printPostScript,      arg+1, 1);
    XtSetValues(printPlainText,       arg+0, 1);
    XtSetValues(printLaTeX,           arg+0, 1);
    XtSetSensitive(printSizeBox,      True);
    XtSetSensitive(printPrinterLabel, True);
    XtSetSensitive(printPrinterName,  True);

    break;

  case PrintLaTeXN:

    XtSetValues(printLaTeX,           arg+1, 1);
    XtSetValues(printPlainText,       arg+0, 1);
    XtSetValues(printPostScript,      arg+0, 1);
    XtSetSensitive(printSizeBox,      False);
    XtSetSensitive(printPrinterLabel, False);
    XtSetSensitive(printPrinterName,  False);
    XtSetSensitive(printPrinter,      False);

    break;
  }

  if (printType != PrintPostScriptN) {

    XtSetValues(printSizeA4,        arg+0, 1);
    XtSetValues(printSizeLetter,    arg+0, 1);
    XtSetValues(printSizePortrait,  arg+0, 1);
    XtSetValues(printSizeLandscape, arg+0, 1);

  } else {

    switch(paperType) {

    case PaperA4PortraitN:

      XtSetValues(printSizeA4,        arg+1, 1);
      XtSetValues(printSizePortrait,  arg+1, 1);
      XtSetValues(printSizeLetter,    arg+0, 1);
      XtSetValues(printSizeLandscape, arg+0, 1);

      break;

    case PaperA4LandscapeN:

      XtSetValues(printSizeA4,        arg+1, 1);
      XtSetValues(printSizeLandscape, arg+1, 1);
      XtSetValues(printSizeLetter,    arg+0, 1);
      XtSetValues(printSizePortrait,  arg+0, 1);

      break;

    case PaperLetterPortraitN:

      XtSetValues(printSizeLetter,    arg+1, 1);
      XtSetValues(printSizePortrait,  arg+1, 1);
      XtSetValues(printSizeA4,        arg+0, 1);
      XtSetValues(printSizeLandscape, arg+0, 1);

      break;

    case PaperLetterLandscapeN:

      XtSetValues(printSizeLetter,    arg+1, 1);
      XtSetValues(printSizeLandscape, arg+1, 1);
      XtSetValues(printSizeA4,        arg+0, 1);
      XtSetValues(printSizePortrait,  arg+0, 1);

      break;
    }
  }

  paperWd = paperSize[(int)paperType][0];
  paperHt = paperSize[(int)paperType][1];
  
  if (useFile) {

    XtSetValues(printFile,    arg+1, 1);
    XtSetValues(printPrinter, arg+0, 1);

    XtSetSensitive(printPrinterLabel, False);
    XtSetSensitive(printPrinterName,  False);

  } else {

    XtSetValues(printPrinter, arg+1, 1);
    XtSetValues(printFile,    arg+0, 1);

    XtSetSensitive(printFileLabel, False);
    XtSetSensitive(printFilename,  False);
  }
}



/*ARGSUSED*/
void PrintPostScriptC(w, clientD, callD)
  Widget w;
  caddr_t clientD, callD;
{
  printType = PrintPostScriptN;
  PrintShowCurrent();
}


/*ARGSUSED*/
void PrintLaTeXC(w, clientD, callD)
  Widget w;
  caddr_t clientD, callD;
{
  printType = PrintLaTeXN;
  useFile   = True;
  PrintShowCurrent();
}


/*ARGSUSED*/
void PrintPlainTextC(w, clientD, callD)
  Widget w;
  caddr_t clientD, callD;
{
  printType = PrintPlainTextN;
  PrintShowCurrent();
}


/*ARGSUSED*/
void PrintFileC(w, clientD, callD)
  Widget  w;
  caddr_t clientD, callD;
{
  useFile = ((printType == PrintPlainTextN) ||
	     (printType == PrintPostScriptN));

  PrintShowCurrent();
}


/*ARGSUSED*/
void PrintPrinterC(w, clientD, callD)
  Widget w;
  caddr_t clientD, callD;
{
  useFile = False;
  PrintShowCurrent();
}


/*ARGSUSED*/
void PrintSizeA4C(w, clientD, callD)
  Widget w;
  caddr_t clientD, callD;
{
  paperType =
    (paperType == PaperA4PortraitN || paperType == PaperLetterPortraitN) ?
      PaperA4PortraitN : PaperA4LandscapeN;
  PrintShowCurrent();
}


/*ARGSUSED*/
void PrintSizeLetterC(w, clientD, callD)
  Widget w;
  caddr_t clientD, callD;
{
  paperType =
    (paperType == PaperA4PortraitN || paperType == PaperLetterPortraitN) ?
      PaperLetterPortraitN : PaperLetterLandscapeN;
  PrintShowCurrent();
}


/*ARGSUSED*/
void PrintSizePortraitC(w, clientD, callD)
  Widget w;
  caddr_t clientD, callD;
{
  paperType = 
    (paperType == PaperA4PortraitN || paperType == PaperA4LandscapeN) ?
      PaperA4PortraitN : PaperLetterPortraitN;
  PrintShowCurrent();
}


/*ARGSUSED*/
void PrintSizeLandscapeC(w, clientD, callD)
  Widget w;
  caddr_t clientD, callD;
{
  paperType = 
    (paperType == PaperA4PortraitN || paperType == PaperA4LandscapeN) ?
      PaperA4LandscapeN : PaperLetterLandscapeN;
  PrintShowCurrent();
}


/*ARGSUSED*/
void PrintQueryCancel(w, clientD, callD)
  Widget w;
  caddr_t clientD, callD;
{
  XtSetSensitive(printQueryCancel, False);
  XtPopdown(printQueryShell);
  XtSetSensitive(printQueryCancel, True);

  if (XtIsSensitive(printSizeSize)) XtSetSensitive(printSizeSpace, True);
  else                              XtSetSensitive(printSizeSize,  True);

  XtUnrealizeWidget(printQueryShell);
  XRaiseWindow(XtDisplay(printShell), XtWindow(printShell));
  PrintShowCurrent();
} 


/*ARGSUSED*/
void PrintQueryApply(w, clientD, callD)
  Widget w;
  caddr_t clientD, callD;
{
  Arg     arg;
  int     min, max;
  int     result;
  char    complain[20];
  Boolean space;

  result = atoi(XawDialogGetValueString(printQueryDialog));
   space = XtIsSensitive(printSizeSize);
     max = space ? 5 : 100;
     min = space ? 1 : 5;

  if (result < min || result > max) {

    sprintf(complain, "%s is %d",
	    (result < min) ? "Minimum" : "Maximum",
	    (result < min) ?  min : max);

    XtSetArg(arg, XtNlabel, complain);
    XtSetValues(printQueryDialog, &arg, 1);
    XBell(XtDisplay(w), 80);

  } else {

    if (space) spacing = result;
    else       pointSz = result;

    XtSetSensitive(printQueryApply, False);
    XtPopdown(printQueryShell);
    XtSetSensitive(printQueryApply, True);

    if (space) XtSetSensitive(printSizeSpace, True);
    else       XtSetSensitive(printSizeSize,  True);

    XtUnrealizeWidget(printQueryShell);
    XRaiseWindow(XtDisplay(printShell), XtWindow(printShell));
    PrintShowCurrent();
  }
}   


/*ARGSUSED*/
void PrintSizeSizeC(w, clientD, callD)
  Widget  w;
  caddr_t clientD, callD;
{
  Position x;
  Position y;

  BEGARG;

  SETARG(printQueryDialog, XtNlabel, "Point size:");
  SETARG(printQueryDialog, XtNvalue,            "");

  XRedTranslateCoords(printSizeSize, 15, 12, &x, &y, 200, 200);

  SETARG(printQueryShell, XtNx, x);
  SETARG(printQueryShell, XtNy, y);

  XtRealizeWidget(printQueryShell);

  FINARG;

  XtSetSensitive(printSizeSize, False);
  XtPopup(printQueryShell, XtGrabNonexclusive);
  XRaiseWindow(XtDisplay(printQueryShell), XtWindow(printQueryShell));
}


/*ARGSUSED*/
void PrintSizeSpaceC(w, clientD, callD)
  Widget  w;
  caddr_t clientD, callD;
{
  Position x;
  Position y;

  BEGARG;

  SETARG(printQueryDialog, XtNlabel, "Line spacing:");
  SETARG(printQueryDialog, XtNvalue,              "");

  XRedTranslateCoords(printSizeSpace, 15, 12, &x, &y, 200, 200);

  SETARG(printQueryShell, XtNx, x);
  SETARG(printQueryShell, XtNy, y);

  XtRealizeWidget(printQueryShell);

  FINARG;

  XtSetSensitive(printSizeSpace, False);
  XtPopup(printQueryShell, XtGrabNonexclusive);
  XRaiseWindow(XtDisplay(printQueryShell), XtWindow(printQueryShell));
}



/*
   Procedure for printing:

   1.  Check that the temporary file and either the print file or the lpr
       pipe, whichever is appropriate, can be opened; open the latter.  If
       the temporary file exists, truncate it cruelly.

   2.  Send a request to Reduce, as an Urgent Input, for the text to be
       printed.  The Reduce function which supplies this should take
       arguments for the beginning prompt number, end prompt number,
       whether or not to use LaTeX format (the only format for which
       LaTeX will not be needed is Plain Text), and the name of the file
       to put things into.  Note that some flag will have to be set in
       order to tell the Output module to hand control to the Printer
       module's print function as soon as Reduce sends another prompt
       (when it will have finished the business in hand).

   3.  Reduce should now send the requested information to the temporary
       file, without intervention, and then close the file.  Control should
       then go to the print function, which should...

   4.  Go through the temporary file, taking the contents and formatting
       them.  There probably ought to be codes to distinguish between
       prompts (with input) and output text, though it should be possible
       without.  For the PostScript format, there'll have to be
       quite a bit of interaction with the XRedTech module.

   5.  Remember to delete the temporary file afterwards, and close the
       print file or lpr pipe.
*/

/*ARGSUSED*/
void PrintOK(w, clientD, callD)
  Widget  w;
  caddr_t clientD, callD;
{
  char *cmd;
  int   length;

  PrintShowCurrent();
  XtSetSensitive(printOK,     False);
  XtSetSensitive(printCancel, False); 

  /* First test the start prompt number for range */

  if (promptNo < 1 || (promptPresent > 0 && promptNo > promptPresent)) {

    PrintMessage("Start Prompt Nr must be between 1 and %d",
		 (char *)promptPresent);
    XtSetSensitive(printOK,     True);
    XtSetSensitive(printCancel, True);
    return;
  }

  /* Then the end prompt number */

  if (endPrmNo < promptNo || (promptPresent > 0 && endPrmNo > promptPresent)) {

    char filler[20];
    sprintf(filler, "%d and %d", promptNo, promptPresent);
    PrintMessage("End Prompt Nr must be between %s", filler);
    XtSetSensitive(printOK,     True);
    XtSetSensitive(printCancel, True);
    return;
  }

  /* Now check that the temporary file can be opened, by trying to open it */

  if ((tempFile = fopen(tempFileName,"w")) == NULL) {

    PrintMessage("Bad temp file \"%s\", using cwd", tempFileName);
    sleep(1);
    free(tempFileName);
    tempFileName = tempnam(".", ".xred");

    if ((tempFile = fopen(tempFileName,"w")) == NULL) {
      PrintMessage("Bad temp file \"%s\", giving up", tempFileName);
      XtSetSensitive(printOK,     True);
      XtSetSensitive(printCancel, True);
      return;
    }
  }

  fclose(tempFile);
  unlink(tempFileName);		/* We were just testing; REDUCE will */
				/* do the actual writing bit         */

  if (printType == PrintPostScriptN)
    length = (paperWd - 144) / (1 + PixelsToPointsX(font_width[0]));
  else length = 80;

  /* Send an urgent request to REDUCE for the printing information */

  cmd = (char *)XtMalloc(100 + strlen(tempFileName));
  sprintf(cmd, "lisp x!-pr!!(%d,%d,%s,\"%s\",%d)$  %% XR Printer Command\n",
	  promptNo, endPrmNo, printType == PrintPlainTextN ? "nil" : "t",
	  tempFileName, length);
  PlaceUrgentItemOnPending(cmd, "[ Processing Print Command ]\n");
  XtFree(cmd);

  /* And place XReduce in Printer mode, so that at the next prompt, control */
  /* should be passed back to this module before anything else is done      */

  preCmdFlag = True;
  preCmd     = PrintPrint;
  PlaceItemOnPending("\n",1);
  GetReduceOutput(0, ReduceToMe, NULL);
  return;
}


/*ARGSUSED*/
void PrintCancel(w, clientD, callD)
  Widget  w;
  caddr_t clientD, callD;
{
  XtPopdown(printShell);
  XtDestroyWidget(printShell);

  printBoxInstalled = False;

  return;
}


void initialisePrinter(parent)
  Widget parent;
{
  char *fnm;

  referenceWidget = parent;
  printType       = PrintPlainTextN;
  paperType       = PaperA4PortraitN;
  useFile         = False;
  fnm             = (char *)getenv("HOME");
  tempFileName    = tempnam(fnm, ".xred");
  printerName[0]  = 0;

  if (!fileName) fileName = XtNewString("printout");
}


void PrintInstall(parent)
  Widget parent;
{
  int            dir;
  int            asc;
  int            dsc;
  int            fnlWd;
  int            prlWd;
  int            pplWd;
  int            pelWd;
  int            txtHt;
  Arg            arg[2];
  char           pst[9];
  char          *txt;
  char          *fnm;
  Position       x;
  Position       y;
  Dimension      iSp;
  Dimension      lWd;
  Dimension      lHt;
  Dimension      bHt;
  XCharStruct    info;

  if (!printBoxInstalled) {

    fnm        = (char *)getenv("HOME");
    fileName   = tempnam(fnm, "xrout");
    promptNo   = (promptPresent > 1 ? promptPresent - 1 :
		  promptPresent < 1 ? promptPresent + 1 : promptPresent);
    endPrmNo   = promptNo;
    printShell = XtCreatePopupShell("print options",
				    transientShellWidgetClass,
				    parent, NULL, 0);
    printQueryShell = XtCreatePopupShell("print question",
					 transientShellWidgetClass,
					 printShell, NULL, 0);

    WIDGET(printBox,             "printBox",
	   boxWidgetClass,        printShell);
    WIDGET(printLabel,           "printLabel",
	   labelWidgetClass,      printBox);
    WIDGET(printTextsBox,        "printTextsBox",
	   boxWidgetClass,        printBox);
    WIDGET(printPrinterLabel,    "printPrinterLabel",
	   labelWidgetClass,      printTextsBox);
    WIDGET(printPrinterNameBox,  "printPrinterNameBox",
	   boxWidgetClass,        printTextsBox);
    WIDGET(printPrinterName,     "printPrinterName",
	   asciiTextWidgetClass,  printPrinterNameBox);
    WIDGET(printFileLabel,       "printFileLabel",
	   labelWidgetClass,      printTextsBox);
    WIDGET(printFilenameBox,     "printFilenameBox",
	   boxWidgetClass,        printTextsBox);
    WIDGET(printFilename,        "printFilename",
	   asciiTextWidgetClass,  printFilenameBox);
    WIDGET(printHistoryLabel,    "printHistoryLabel",
	   labelWidgetClass,      printTextsBox);
    WIDGET(printHistoryNumberBox,"printHistoryNumberBox",
	   boxWidgetClass,        printTextsBox);
    WIDGET(printHistoryNumber,   "printHistoryNumber",
	   asciiTextWidgetClass,  printHistoryNumberBox);
    WIDGET(printHistEndLabel,    "printHistEndLabel",
	   labelWidgetClass,      printTextsBox);
    WIDGET(printHistEndNumberBox,"printHistEndNumberBox",
	   boxWidgetClass,        printTextsBox);
    WIDGET(printHistEndNumber,   "printHistEndNumber",
	   asciiTextWidgetClass,  printHistEndNumberBox);
    WIDGET(printToggleBox,       "printToggleBox",
	   formWidgetClass,       printBox);
    WIDGET(printPostScript,      "printPostScript",
	   toggleWidgetClass,     printToggleBox);
    WIDGET(printLaTeX,           "printLaTeX",
	   toggleWidgetClass,     printToggleBox);
    WIDGET(printPlainText,       "printPlainText",
	   toggleWidgetClass,     printToggleBox);
    WIDGET(printPrinter,         "printPrinter",
	   toggleWidgetClass,     printToggleBox);
    WIDGET(printFile,            "printFile",
	   toggleWidgetClass,     printToggleBox);
    WIDGET(printSizeBox,         "printSizeBox",
	   formWidgetClass,       printBox);
    WIDGET(printSizeA4,          "printSizeA4",
	   toggleWidgetClass,     printSizeBox);
    WIDGET(printSizeLetter,      "printSizeLetter",
	   toggleWidgetClass,     printSizeBox);
    WIDGET(printSizePortrait,    "printSizePortrait",
	   toggleWidgetClass,     printSizeBox);
    WIDGET(printSizeLandscape,   "printSizeLandscape",
	   toggleWidgetClass,     printSizeBox);
    WIDGET(printSizeSize,        "printSizeSize",
	   commandWidgetClass,    printSizeBox);
    WIDGET(printSizeSpace,       "printSizeSpace",
	   commandWidgetClass,    printSizeBox);
    WIDGET(printCommandBox,      "printCommandBox",
	   formWidgetClass,       printBox);
    WIDGET(printOK,              "printOK",
	   commandWidgetClass,    printCommandBox);
    WIDGET(printCancel,          "printCancel",
	   commandWidgetClass,    printCommandBox);
    WIDGET(printQueryDialog,     "printQueryDialog",
	   dialogWidgetClass,     printQueryShell);
    WIDGET(printQueryApply,      "printQueryApply",
	   commandWidgetClass,    printQueryDialog);
    WIDGET(printQueryCancel,     "printQueryCancel",
	   commandWidgetClass,    printQueryDialog);

    sprintf(pst, "%d", promptNo);

    XtSetArg(arg[0], XtNstring,                pst);
    XtSetArg(arg[1], XtNinsertPosition, strlen(pst));
    XtSetValues(printHistoryNumber, arg, 2);
    
    XtSetArg(arg[0], XtNstring,                pst);
    XtSetArg(arg[1], XtNinsertPosition, strlen(pst));
    XtSetValues(printHistEndNumber, arg, 2);
    
    XtSetArg(arg[0], XtNstring,                   fileName );
    XtSetArg(arg[1], XtNinsertPosition, strlen   (fileName));
    XtSetValues(printFilename,      arg, 2);

    XtSetArg(arg[0], XtNstring,                printerName );
    XtSetArg(arg[1], XtNinsertPosition, strlen(printerName));
    XtSetValues(printPrinterName,   arg, 2);

    BEGARG;

    GETARG(printBox,           XtNhSpace,      iSp);
    lWd =  printWd - 2*iSp - 3;
    bHt = (printHt - 9*iSp) / 8;
    lHt =      bHt - 2*iSp;

    txt = "{(|MW]0";
    XTextExtents(buttonFont, txt, strlen(txt), &dir, &asc, &dsc, &info);
    txtHt = (int)(asc + dsc);

    SETARG(printLabel,         XtNlabel,      "Choose Print Options");
    SETARG(printTextsBox,      XtNfromVert,    printLabel);
    SETARG(printTextsBox,      XtNborderWidth, 1);
    
    txt = "File Name:";
    XTextExtents(buttonFont, txt, strlen(txt), &dir, &asc, &dsc, &info);
    fnlWd = (int)(info.width) + 2*iSp;
 
    SETARG(printFileLabel,     XtNlabel,       txt);
    SETARG(printFileLabel,     XtNborderWidth, 0);
    SETARG(printFilename,      XtNeditType,    XawtextEdit);
    SETARG(printFilename,      XtNfromHoriz,   printFileLabel);
    SETARG(printFilename,      XtNborderWidth, 0);

    txt = "Printer Name:";
    XTextExtents(buttonFont, txt, strlen(txt), &dir, &asc, &dsc, &info);
    prlWd = (int)(info.width) + 2*iSp;

    SETARG(printPrinterLabel,  XtNlabel,       txt);
    SETARG(printPrinterLabel,  XtNborderWidth, 0);
    SETARG(printPrinterName,   XtNeditType,    XawtextEdit);
    SETARG(printPrinterName,   XtNfromHoriz,   printPrinterLabel);
    SETARG(printPrinterName,   XtNborderWidth, 0);

    txt = "Print From Prompt Number:";
    XTextExtents(buttonFont, txt, strlen(txt), &dir, &asc, &dsc, &info);
    pplWd = (int)(info.width) + 2*iSp;

    SETARG(printHistoryLabel,  XtNlabel,       txt);
    SETARG(printHistoryLabel,  XtNborderWidth, 0);
    SETARG(printHistoryNumber, XtNeditType,    XawtextEdit);
    SETARG(printHistoryNumber, XtNfromHoriz,   printHistoryLabel);
    SETARG(printHistoryNumber, XtNborderWidth, 0);

    txt = "Print To Prompt Number:";
    XTextExtents(buttonFont, txt, strlen(txt), &dir, &asc, &dsc, &info);
    pelWd = (int)(info.width) + 2*iSp;

    SETARG(printHistEndLabel,  XtNlabel,       txt);
    SETARG(printHistEndLabel,  XtNborderWidth, 0);
    SETARG(printHistEndNumber, XtNeditType,    XawtextEdit);
    SETARG(printHistEndNumber, XtNfromHoriz,   printHistEndLabel);
    SETARG(printHistEndNumber, XtNborderWidth, 0);
    SETARG(printToggleBox,     XtNfromVert,    printTextsBox);
    SETARG(printToggleBox,     XtNborderWidth, 1);
    SETARG(printPlainText,     XtNlabel,      "Text");
    SETARG(printPlainText,     XtNradioGroup,  printPlainText);
    SETARG(printPlainText,     XtNstate,       True);
    SETARG(printPostScript,    XtNlabel,      "PostScript");
    SETARG(printPostScript,    XtNstate,       False);
    SETARG(printPostScript,    XtNradioGroup,  printPlainText);
    SETARG(printPostScript,    XtNfromHoriz,   printPlainText);
    SETARG(printLaTeX,         XtNlabel,      "LaTeX");
    SETARG(printLaTeX,         XtNradioGroup,  printPlainText);
    SETARG(printLaTeX,         XtNfromHoriz,   printPostScript);
    SETARG(printLaTeX,         XtNstate,       False);
    SETARG(printPrinter,       XtNfromHoriz,   printLaTeX);
    SETARG(printPrinter,       XtNlabel,      "Printer");
    SETARG(printPrinter,       XtNstate,       True);
    SETARG(printFile,          XtNlabel,      "File");
    SETARG(printFile,          XtNfromHoriz,   printPrinter);
    SETARG(printFile,          XtNradioGroup,  printPrinter);
    SETARG(printFile,          XtNstate,       False);
    SETARG(printSizeBox,       XtNfromVert,    printToggleBox);
    SETARG(printSizeBox,       XtNborderWidth, 1);
    SETARG(printSizePortrait,  XtNlabel,      "Portrait");
    SETARG(printSizePortrait,  XtNstate,       False);
    SETARG(printSizeLandscape, XtNlabel,      "Landscape");
    SETARG(printSizeLandscape, XtNfromHoriz,   printSizePortrait);
    SETARG(printSizeLandscape, XtNradioGroup,  printSizePortrait);
    SETARG(printSizeLandscape, XtNstate,       False);
    SETARG(printSizeA4,        XtNlabel,      "A4");
    SETARG(printSizeA4,        XtNstate,       False);
    SETARG(printSizeA4,        XtNfromHoriz,   printSizeLandscape);
    SETARG(printSizeLetter,    XtNlabel,      "Letter");
    SETARG(printSizeLetter,    XtNradioGroup,  printSizeA4);
    SETARG(printSizeLetter,    XtNstate,       False);
    SETARG(printSizeLetter,    XtNfromHoriz,   printSizeA4);
    SETARG(printSizeSize,      XtNfromHoriz,   printSizeLetter);
    SETARG(printSizeSpace,     XtNfromHoriz,   printSizeSize);
    SETARG(printCommandBox,    XtNfromVert,    printSizeBox);
    SETARG(printQueryApply,    XtNlabel,      "Apply");
    SETARG(printQueryCancel,   XtNlabel,      "Cancel");
    SETARG(printOK,            XtNlabel,      "OK");
    SETARG(printCancel,        XtNlabel,      "Cancel");
    SETARG(printCancel,        XtNfromHoriz,   printOK);
    SETARG(printLabel,         XtNfont,        buttonFont);
    SETARG(printFileLabel,     XtNfont,        buttonFont);
    SETARG(printFilename,      XtNfont,        buttonFont);
    SETARG(printPrinterLabel,  XtNfont,        buttonFont);
    SETARG(printPrinterName,   XtNfont,        buttonFont);
    SETARG(printHistoryLabel,  XtNfont,        buttonFont);
    SETARG(printHistoryNumber, XtNfont,        buttonFont);
    SETARG(printHistEndLabel,  XtNfont,        buttonFont);
    SETARG(printHistEndNumber, XtNfont,        buttonFont);
    SETARG(printPostScript,    XtNfont,        buttonFont);
    SETARG(printLaTeX,         XtNfont,        buttonFont);
    SETARG(printPlainText,     XtNfont,        buttonFont);
    SETARG(printFile,          XtNfont,        buttonFont);
    SETARG(printPrinter,       XtNfont,        buttonFont);
    SETARG(printSizeA4,        XtNfont,        buttonFont);
    SETARG(printSizeLetter,    XtNfont,        buttonFont);
    SETARG(printSizePortrait,  XtNfont,        buttonFont);
    SETARG(printSizeLandscape, XtNfont,        buttonFont);
    SETARG(printSizeSize,      XtNfont,        buttonFont);
    SETARG(printSizeSpace,     XtNfont,        buttonFont);
    SETARG(printOK,            XtNfont,        buttonFont);
    SETARG(printCancel,        XtNfont,        buttonFont);
    SETARG(printFilename,      XtNresize,      XawtextResizeWidth);
    SETARG(printPrinterName,   XtNresize,      XawtextResizeWidth);
    SETARG(printHistoryNumber, XtNresize,      XawtextResizeWidth);
    SETARG(printHistEndNumber, XtNresize,      XawtextResizeWidth);
    
    PrintShowCurrent();
    XRedTranslateCoords(parent, 50, 70, &x, &y, printWd, printHt);
    
    SETARG(printShell,         XtNx,           x);
    SETARG(printShell,         XtNy,           y);
    SETARG(printShell,         XtNwidth,       printWd);
    SETARG(printShell,         XtNheight,      printHt - 8);
    SETARG(printBox,           XtNwidth,       printWd);
    SETARG(printBox,           XtNheight,      printHt - 8);
    SETARG(printBox,           XtNhSpace,      iSp);

    SETARG(printTextsBox,         XtNborderWidth,   1);
    SETARG(printFilenameBox,      XtNborderWidth,   0);
    SETARG(printPrinterNameBox,   XtNborderWidth,   0);
    SETARG(printHistoryNumberBox, XtNborderWidth,   0);
    SETARG(printHistEndNumberBox, XtNborderWidth,   0);
    SETARG(printPlainText,        XtNborderWidth,   0);
    SETARG(printPostScript,       XtNborderWidth,   0);
    SETARG(printLaTeX,            XtNborderWidth,   0);
    SETARG(printPrinter,          XtNborderWidth,   0);
    SETARG(printFile,             XtNborderWidth,   0);
    SETARG(printSizeA4,           XtNborderWidth,   0);
    SETARG(printSizeLetter,       XtNborderWidth,   0);
    SETARG(printSizePortrait,     XtNborderWidth,   0);
    SETARG(printSizeLandscape,    XtNborderWidth,   0);
    SETARG(printSizeSize,         XtNborderWidth,   0);
    SETARG(printSizeSpace,        XtNborderWidth,   0);
    SETARG(printSizeSpace,        XtNhorizDistance, 2);
    SETARG(printOK,               XtNborderWidth,   0);
    SETARG(printCancel,           XtNborderWidth,   0);
    SETARG(printFilenameBox,      XtNvSpace, (lHt - txtHt)/2 - 1);
    SETARG(printPrinterNameBox,   XtNvSpace, (lHt - txtHt)/2 - 1);
    SETARG(printHistoryNumberBox, XtNvSpace, (lHt - txtHt)/2 - 1);
    SETARG(printHistEndNumberBox, XtNvSpace, (lHt - txtHt)/2 - 1);

    SETARG(printLabel,         XtNwidth,       lWd);
    SETARG(printLabel,         XtNheight,      bHt);
    SETARG(printFileLabel,     XtNheight,      lHt);
    SETARG(printFilename,      XtNheight,    txtHt + 4);
    SETARG(printFileLabel,     XtNwidth,     fnlWd);
    SETARG(printFilename,      XtNwidth,      (lWd - 5*iSp) - fnlWd - 2);
    SETARG(printPrinterLabel,  XtNheight,      lHt);
    SETARG(printPrinterName,   XtNheight,    txtHt + 4);
    SETARG(printPrinterLabel,  XtNwidth,     prlWd);
    SETARG(printPrinterName,   XtNwidth,      (lWd - 5*iSp) - prlWd - 2);
    SETARG(printHistoryLabel,  XtNheight,      lHt);
    SETARG(printHistoryNumber, XtNheight,    txtHt + 4);
    SETARG(printHistoryLabel,  XtNwidth,     pplWd);
    SETARG(printHistoryNumber, XtNwidth,      (lWd - 5*iSp) - pplWd - 2);
    SETARG(printHistEndLabel,  XtNheight,      lHt);
    SETARG(printHistEndNumber, XtNheight,    txtHt + 4);
    SETARG(printHistEndLabel,  XtNwidth,     pelWd);
    SETARG(printHistEndNumber, XtNwidth,      (lWd - 5*iSp) - pplWd - 2);
    SETARG(printTextsBox,      XtNheight,    4*lHt + 6*iSp + 2);
    SETARG(printTextsBox,      XtNwidth,       lWd);

    XtRealizeWidget(printShell);

    SETARG(printPlainText,     XtNheight,      lHt);
    SETARG(printPostScript,    XtNheight,      lHt);
    SETARG(printLaTeX,         XtNheight,      lHt);
    SETARG(printFile,          XtNheight,      lHt);
    SETARG(printPrinter,       XtNheight,      lHt);
    SETARG(printToggleBox,     XtNheight,      bHt);
    SETARG(printToggleBox,     XtNwidth,       lWd);
    SETARG(printSizeBox,       XtNheight,      bHt);
    SETARG(printSizeBox,       XtNwidth,       lWd);
    SETARG(printOK,            XtNheight,      lHt);
    SETARG(printCancel,        XtNheight,      lHt);
    SETARG(printCommandBox,    XtNheight,      bHt);
    SETARG(printCommandBox,    XtNwidth,       lWd);

    SETARG(printShell,         XtNx,           x);
    SETARG(printShell,         XtNy,           y);
    SETARG(printShell,         XtNwidth,       printWd);
    SETARG(printShell,         XtNheight,      printHt - 8);
    SETARG(printBox,           XtNwidth,       printWd);
    SETARG(printBox,           XtNheight,      printHt - 8);
    
    FINARG;

    XtAddCallback(printPostScript,    XtNcallback, PrintPostScriptC,    0);
    XtAddCallback(printLaTeX,         XtNcallback, PrintLaTeXC,         0);
    XtAddCallback(printPlainText,     XtNcallback, PrintPlainTextC,     0);
    XtAddCallback(printFile,          XtNcallback, PrintFileC,          0);
    XtAddCallback(printPrinter,       XtNcallback, PrintPrinterC,       0);
    XtAddCallback(printSizeA4,        XtNcallback, PrintSizeA4C,        0);
    XtAddCallback(printSizeLetter,    XtNcallback, PrintSizeLetterC,    0);
    XtAddCallback(printSizePortrait,  XtNcallback, PrintSizePortraitC,  0);
    XtAddCallback(printSizeLandscape, XtNcallback, PrintSizeLandscapeC, 0);
    XtAddCallback(printSizeSize,      XtNcallback, PrintSizeSizeC,      0);
    XtAddCallback(printSizeSpace,     XtNcallback, PrintSizeSpaceC,     0);
    XtAddCallback(printQueryApply,    XtNcallback, PrintQueryApply,     0);
    XtAddCallback(printQueryCancel,   XtNcallback, PrintQueryCancel,    0);
    XtAddCallback(printOK,            XtNcallback, PrintOK,             0);
    XtAddCallback(printCancel,        XtNcallback, PrintCancel,         0);

    XtPopup(printShell, XtGrabNone);
    printBoxInstalled = True;
  }

  XRaiseWindow(XtDisplay(printShell), XtWindow(printShell));
}



/*
   Now here are the actual printing routines.  (Safely stashed away at
   the end of the file.)  The routine for Plain Text is trivial; that for
   LaTeX slightly less so; that for PostScript
   is quite complicated.  The PostScript printing code needs to rewrite
   many of the routines in xredtech.c to format for PS rather than X.
   Routines appear here in order of difficulty.

   Perhaps this would be easier in NeWS?  ...then we could tell everyone
   to use OpenWindows, and they could all have lots of fun.
*/


void PrintPlainText()
{
  int c;

  while ((c = getc(tempFile)) != EOF)
    if (c > 31 || c == END_OF_LINE) putc(c, sendFile);

  return;
}


void PrintLaTeXSymbol()
{
  int   n = 0;
  char  c;
  char *wrd;

  while ((c = getc(tempFile)) != EOF && c != '}')
    if (isdigit(c)) n = 10*n + c-'0';

  switch(n) {

  case 182: wrd = "\\delta";          break;   /* See RLisp for commentary */
  case 198: wrd = "\\emptyset";       break;
  case 216: wrd = "\\neg";            break;
  case 163: wrd = "\\leq";            break;
  case 179: wrd = "\\geq";            break;
  case 185: wrd = "\\not=";           break;
  case 199: wrd = "\\cap";            break;
  case 200: wrd = "\\cup";            break;
  case 206: wrd = "\\in";             break;
  case 217: wrd = "\\wedge";          break;
  case 218: wrd = "\\vee";            break;
  case 239: wrd = "\\mid";            break;
  case 222: wrd = "\\Longrightarrow"; break;
  case 71:  wrd = "\\Gamma";          break;
  case 34:  wrd = "\\forall";         break;
  default:  wrd = "[symbol]\\relax";  break;
  }

  fprintf(sendFile, "xred\n%s ", wrd);
}


void PrintLaTeX()
{
  int  c;
  int  md = 0;
  char b4[5];

  b4[0] = b4[1] = b4[2] = b4[3] = b4[5] = 0;

  fprintf(sendFile, "%%  REDUCE session transcription\n");
  fprintf(sendFile, "%%  Produced in LaTeX form by XR, C Cannam 1993\n");
  fprintf(sendFile, "\n\\documentstyle{article}\n\\begin{document}\n\n");
  fprintf(sendFile, "\\newenvironment{xreduce}%%\n");
  fprintf(sendFile, "  {\\begin{displaymath}%%\n");
  fprintf(sendFile, "      \\everymath={\\displaystyle}%%\n");
  fprintf(sendFile, "      \\renewcommand{\\arraystretch}{1.5}%%\n");
  fprintf(sendFile, "      \\begin{array}{l}}%%\n");
  fprintf(sendFile, "  {\\end{array}\\end{displaymath}}\n");
  fprintf(sendFile, "\\let\\symbxred=\\relax\n\n");
  fprintf(sendFile, "{\\it $\\bullet$ XR session, \\today}\n\n");

  while ((c = getc(tempFile)) != EOF) {

    switch(c) {

    case promptBeginEscape:

      if   (md != 1) {
	if (md == 2) fprintf(sendFile, "\\end{xreduce}\n");
	fprintf(sendFile, "\\begin{verbatim}\n\n");
	md = 1;
      }
      break;

    case promptEndEscape:

      if   (md != 2) {
	if (md == 1) fprintf(sendFile, "\\end{verbatim}\n");
	fprintf(sendFile, "\\begin{xreduce}\n");
	md = 2;
      }
      break;

    case REDUCE_TEX_OFF:
      
      fprintf(sendFile,"\\\\\n");
      break;

    case '{':

      if (!strncasecmp(b4,"\\symb",5)) {
	PrintLaTeXSymbol();
	break;
      }

    default:

      if (c > 31 || (c == END_OF_LINE && md == 1)) putc(c, sendFile);
    }

    b4[0] = b4[1];
    b4[1] = b4[2];
    b4[2] = b4[3];
    b4[3] = b4[4];
    b4[4] = (char)c;
  }

  if (md == 1) fprintf(sendFile, "\\end{verbatim}\n");
  if (md == 2) fprintf(sendFile, "\\end{xreduce}\n");
  fprintf(sendFile, "\\end{document}\n");

  return;
}


int PixelsToPointsX(pix)
  int pix;
{
  /* Try assuming font_height[0] == 12 points (yeah, ugly, unwise, wrong) */

  unsigned long pt;

  pt = (((unsigned long)(pix<0 ? -pix:pix)) *
	 (unsigned long)pointSz) / font_height[0];
  if (pix < 0) return -(int)pt; else return (int)pt;
}


int PixelsToPointsY(pix)
  int pix;
{
  unsigned long pt;

  pt = (((unsigned long)(pix<0 ? -pix:pix)) *
	 (unsigned long)pointSz) / font_height[0];
  pt = (((unsigned long)(spacing*2+2)) * pt) / 8;
  if (pix < 0) return -(int)pt; else return (int)pt;
}


Boolean PixelsToPagePoints(pix, piy, ptxp, ptyp)
  int  pix;
  int  piy;
  int *ptxp;
  int *ptyp;
{
  /* We have pix and piy, pixel x and y values (x across from left, y down) */
  /* from an original offset of currSX and currSY pixels from the top-left  */
  /* of the printing page.  We need to compute point x and y values for the */
  /* given point, from the bottom-left of the page.  Return True if this is */
  /* actually on the page, and False if not.  For the moment let us assume  */
  /* an inch margin left and right, and also an inch top and bottom.        */

  int ptx;
  int pty;

  ptx = 72 + PixelsToPointsX(currSX + pix);
  pty = paperHt - (72 + PixelsToPointsY(currSY + piy));

  if (ptxp) *ptxp = ptx;
  if (ptyp) *ptyp = pty;

  return !(ptx < 72 || ptx > paperWd-72 ||
	   pty < 72 || pty > paperHt-72);
}


Boolean ShowPage(ptxp, ptyp, sq)
  int *ptxp;
  int *ptyp;
  Boolean sq;
{
  int ptx;
  int pty;

  currSY = currSX = 0;
  PixelsToPagePoints(0, 0, &ptx, &pty);
  if (sq) fprintf(sendFile, "\ngrestore");
  fprintf(sendFile, "\nshowpage\n%%%%Page: %d %d\n", pageCount+1, pageCount+2);
  if (paperType == PaperA4LandscapeN ||
      paperType == PaperLetterLandscapeN)
    fprintf(sendFile, "%d 0 translate 90 rotate\n", paperHt);
  pageCount ++;

  if (ptxp) *ptxp = ptx;
  if (ptyp) *ptyp = pty;

  return False;
}


Boolean SystemToSendFile(cmd)
  char *cmd;
{
  char sysstr[256];

  sprintf(sysstr, "%s >> %s", cmd, fileName);

  fclose(sendFile);
  if (system(sysstr)) {
    if ((sendFile = fopen(fileName, "a")) == NULL) {
      fprintf(stderr,"Closed file \"%s\" and couldn't reopen\n", fileName);
      return False;
    } else fprintf(sendFile, "(none)\n", cmd);
  } else {
    if ((sendFile = fopen(fileName, "a")) == NULL) {
      fprintf(stderr,"Closed file \"%s\" and couldn't reopen\n", fileName);
      return False;
    }
  }

  return True;
}


void PrintPostScript()
{
  int     i;
  int     ptx;
  int     pty;
  int     sqw = 0;
  int     c   = 0;
  char    desc[REDUCE_OUTPUT_BUFFER_LENGTH];
  Boolean begun;
  Boolean squashed;

  currSX    = 0;
  currSY    = 0;
  pageCount = 0;
  squashed  = False;

  fprintf(sendFile, "%%!PS-Adobe-1.0\n");
  fprintf(sendFile, "%%%%Title: REDUCE Session Transcription\n");
  fprintf(sendFile, "%%%%Creator: XR X Interface to REDUCE, C Cannam 1993\n");
  if (useFile) {
    fprintf(sendFile, "%%%%For: ");
    if (!SystemToSendFile("whoami")) return;
    fprintf(sendFile, "%%%%CreationDate: ");
    if (!SystemToSendFile("date")) return;
  }
  fprintf(sendFile, "%%%%Pages: (atend)\n");
  fprintf(sendFile, "%%%%DocumentFonts: %s %s %s\n",
	  app_data.psTextFont, app_data.psSymbolFont, app_data.psAsciiFont);

  fprintf(sendFile, "%%%%EndComments\n");
  fprintf(sendFile,
	  "/C  { /%s findfont %d scalefont setfont } def\n",
	  app_data.psTextFont, (pointSz * 11) / 13);
  fprintf(sendFile,
	  "/S0 { /%s findfont %d scalefont setfont } def\n",
	  app_data.psSymbolFont, pointSz);
  fprintf(sendFile,
	  "/S1 { /%s findfont %d scalefont setfont } def\n",
	  app_data.psSymbolFont, (pointSz * 3) / 4);
  fprintf(sendFile,
	  "/T0 { /%s findfont %d scalefont setfont } def\n",
	  app_data.psAsciiFont, pointSz);
  fprintf(sendFile,
	  "/T1 { /%s findfont %d scalefont setfont } def\n",
	  app_data.psAsciiFont, (pointSz * 3) / 4);
  fprintf(sendFile, "/M  { moveto } def\n/W  { show   } def\n");
  fprintf(sendFile, "/BL { newpath %f setlinewidth } def\n",
	  (float)0.025 * (float)pointSz);
  fprintf(sendFile, "/EL { lineto stroke } def\n");
  fprintf(sendFile, "%%%%EndProlog\n");
  fprintf(sendFile, "%%%%Page: 0 1\n\n");

  if (paperType == PaperA4LandscapeN ||
      paperType == PaperLetterLandscapeN)
    fprintf(sendFile, "%d 0 translate 90 rotate\n", paperHt);

  /* Currently this will clear out the fancy_lines array, and mess up   */
  /* any graphics currently being drawn for XReduce -- of course, there */
  /* shouldn't really _be_ any graphics being drawn at this point       */

  if (graphIndex > 0) for (i = 0; i < graphIndex; i++) XtFree(fancy_lines[i]);
  graphIndex = 0;

  PostScriptMode = True;

 loop:

  currSX = 0;
  begun  = False;

  if (!PixelsToPagePoints(0, 0, &ptx, &pty))
    { squashed = ShowPage(&ptx, &pty, squashed); goto loop; }

  while ((c = getc(tempFile)) != EOF && c != REDUCE_TEX_ON) {

    if (c > 31) {

      if (!begun) {

	if (squashed) { fprintf(sendFile, "grestore");
			squashed = False; sqw = 0; }

	fprintf(sendFile, "\nC %d %d M (", ptx, pty);
	begun = True;                     /* Make new input string       */
      }

      if (c == '(' || c == ')') putc('\\', sendFile);
      putc(c, sendFile);                  /*  Place char in input string */
    }

    else if (c == END_OF_LINE) {          /* Show string, CR, new string */

      currSX  = 0;
      currSY += (font_height[0]*22)/16;   /* Guess at the height in pixs */

      if (!PixelsToPagePoints(0, 0, &ptx, &pty)) {
				                 /* Will it fit?         */
				                 /* No - write and show  */
	if (begun) fprintf(sendFile, ") W\n");
	squashed = ShowPage(&ptx, &pty, squashed);
	fprintf(sendFile, "C %d %d M %s", ptx, pty, begun ? "(" : "\n");

      } else if (begun) fprintf(sendFile, ")\nW C %d %d M (", ptx, pty);
    }
  }

  if (begun) fprintf(sendFile, ")\nW ");     /* End the input string */

  while (c != EOF && c != REDUCE_TEX_OFF) {

    for (i = 0;
	 i < REDUCE_OUTPUT_BUFFER_LENGTH && c != EOF && c != REDUCE_TEX_OFF;) {
      c = getc(tempFile);
      if (c > 31) desc[i++] = c;
    }
    desc[i] = 0;
    if (i > 0) fancy_lines[graphIndex++] = XtNewString(desc);
  }

  fancy_lines[graphIndex] = NULL;

  if (graphIndex > 0) {

    fancy_decode();

    if (PixelsToPointsY(currSY + fancy_yrange) > (paperHt - 144) && currSY > 0)
      squashed = ShowPage(&ptx, &pty, squashed);

    /* If the output is too wide for the page, squash the bugger */
    /* (There's nowt like a good bloody mangling to improve yer  */
    /* PostScript, as me old ma always used ter say)             */

    if (PixelsToPointsX(currSX + fancy_xrange) > (paperWd - 144) &&
	currSX + fancy_xrange > sqw) {

      if (squashed) fprintf(sendFile, "grestore ");

      fprintf(sendFile, "gsave %f 1 scale\n",
	      ((float)(paperWd - 144)) /
	      ((float)(PixelsToPointsX(sqw = currSX + fancy_xrange))));

      squashed = True;
    } /* else
      squashed = False; */

    xOffset = fancy_tab * font_width[0];
    yOffset = 0;
    fancy_draw();

    currSY += fancy_yrange;
    for (i = 0; i < graphIndex; ++i) XtFree(fancy_lines[i]);
    graphIndex = 0;
  }

  if (c != EOF) goto loop;

  squashed = ShowPage(&ptx, &pty, squashed);

  fprintf(sendFile, "%%%%Trailer\n");
  fprintf(sendFile, "%%%%Pages: %d\n", pageCount);
  fprintf(sendFile,
	  "%%%% End. That's it. Done. Finished. And good riddance.\n");
  PostScriptMode = False;
  return;
}


void GoToPix(x, y)
{
  int ptx;
  int pty;

  PixelsToPagePoints(x + xOffset, y + yOffset, &ptx, &pty);
  fprintf(sendFile, "%d %d M ", ptx, pty);
}


void PSDrawMath(x, y, c, ffont)
  int    x;
  int    y;
  char * c;
  int    ffont;
{
  int asc;
  int desc;
  int pt;
  int sz;

  switch(*c) {

  case 'I':

    sz = ffont == 0 ? pointSz : (pointSz * 3) /4;
    QueryCharDimensions(243,ffont,2,&asc,&desc,NULL,NULL,True);

    fprintf(sendFile, "/Symbol findfont %d scalefont setfont\n",
	    pt = PixelsToPointsY(asc + desc));

    GoToPix(x, y + asc);
    fprintf(sendFile, "gsave %f 1 scale ", (float)sz / (float)pt);
    fprintf(sendFile, "(\\363)\nW grestore\n");

    GoToPix(x, y + asc + asc + desc);
    fprintf(sendFile, "gsave %f 1 scale ", (float)sz / (float)pt);
    fprintf(sendFile, "(\\365)\nW grestore\n");

    break;

  case 'S':

    QueryCharDimensions(229,ffont,2,&asc,&desc,NULL,NULL,True);
    GoToPix(x, y + asc);
    fprintf(sendFile, "S%d (\\345)\nW ", ffont);
    break;

  default: break;
  }
}


void PSDrawString(x, y, c, len, charset, ffont)
  int    x;
  int    y;
  char * c;
  int    len;
  int    charset;
  int    ffont;
{
  int    asc;
  static char str[REDUCE_OUTPUT_BUFFER_LENGTH];
  int    i, j, k;

  for (i = j = 0; i < len; ++i) {

    if (!isascii(c[i])) {

      k = c[i] < 0 ? c[i] + 256 : c[i];

      str[j++] = '\\';
      str[j++] =  k / 64      + '0';
      str[j++] = (k % 64) / 8 + '0';
      str[j++] = (k % 64) % 8 + '0';

    } else {

      if (c[i] == '(' || c[i] == ')') str[j++] = '\\';
      str[j++] = c[i];
    }
  } str[len = j] = 0;

  switch(charset) {

  case 2:

    PSDrawMath(x, y, str, ffont);
    break;

  case 1:

    /* Note assume ascent of Greek characters is the same as that of Roman */
    /* ones, so that the baselines line up.  This is also done in xredtech */

    /* Note also expect silly output if the Greek font isn't being used on */
    /* the X server (it will give huge answers for widths of Greek chars)  */

    QueryCharDimensions(*str,ffont,0,&asc,NULL,NULL,NULL,False);
    GoToPix(x, y + asc);
    fprintf(sendFile, "S%d (%s)\nW ", ffont, str);
    break;

  case 0:

    QueryCharDimensions(*str,ffont,charset,&asc,NULL,NULL,NULL,False);
    GoToPix(x, y + asc);
    fprintf(sendFile, "T%d (%s)\nW ", ffont, str);
    break;

  default: break;
  }
}


void PSDrawLine(x0, y0, x1, y1)
  int x0;
  int y0;
  int x1;
  int y1;
{
  int ptx;
  int pty;

  PixelsToPagePoints(x1 + xOffset, y1 + yOffset, &ptx, &pty); 

  fprintf(sendFile, "BL ");
  GoToPix(x0, y0);
  fprintf(sendFile, "%d %d EL\n", ptx, pty);

  return;
}


void PSDrawBrack(x, y0, y1, c, ffont)
  int  x;
  int  y0;
  int  y1;
  char c;
  int  ffont;
{
  int asc;
  int desc;
  int wd;
  int pt;

  QueryCharDimensions(c,ffont,2,&asc,&desc,&wd,NULL,False);

  if (c == '{' ||
      c == '(' ||
      c == '[')
    x = x + font_width[0] - wd;

  GoToPix(x, y0 + ((y1-y0)*asc)/(asc+desc) - ((y1-y0)/(2*(asc+desc))));
  fprintf(sendFile, "/Symbol findfont %d scalefont setfont\n",
	  pt = PixelsToPointsY(y1-y0));
  fprintf(sendFile, "gsave %f 1 scale (%s%c)\nW grestore\n",
	  (float)pointSz / (float)pt, (c == '(' || c == ')') ? "\\" : "", c);

  return;
}
