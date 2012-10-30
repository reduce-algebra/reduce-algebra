
/*
   Module to create and deal with popup File box.
   The framework of this module is just a modified
   version of that in option.c; note that the code
   to implement a simple popup filename-asking box
   (without menu) is still in option.c

   Planned selections: Load Package
                       Load Single Binary Module
                       Read File (ie. read it as if user types it to xr)
		       Log To File
		       Print

   I need a friendly and easy to use file selection
   box arrangement.  See fchoose.c.
*/


#include "xreduce.h"
#include "main.h"
#include "widgets.h"
#include "xredplus.h"
#include "rarrow.xbm"
#include "message.h"
#include "font.h"
#include "help.h"
#include "input.h"
#include "manager.h"
#include "printer.h"
#include "verbal.h"
#include "option.h"
#include "fchoose.h"

#define LOG_PATH      ".:$HOME:/tmp:$reduce"
#define MODULE_PATH   ".:$HOME"
#define READ_PATH     ".:$HOME:$reduce"
#define PACKAGE_PATH    "$HOME/.xrpackages|$reduce/xr/doc/packages|\
$reduce/xr/packages|$reduce/xr/bin/packages|$reduce/xr/src/packages|\
$reduce/packages|$reduce/.xrpackages"

#define NO_OF_TOGGLES    6
#define TOGGLE_VERT_DIST 4

#ifndef PATH_MAX
#define PATH_MAX 512
#endif

#ifndef NAME_MAX
#define NAME_MAX 512
#endif

void FileLoadPackage();
void FileLoadModule();
void FileReadFile();
void FileReadQFile();
void FileToggleLogging();
void FilePrintScreen();
void FileOkButton();

static Widget        fileButton;
static Dimension     maxStripWidth;
static Widget        files;
static Widget        fileBox;
static Widget        fileTitleLabel;
static Widget        fileMessageLabel;
static Widget        fileOkButton;
static Widget        referenceWidget;
static char        * tempFilename;
static char        * logFilename;
static FILE        * logFileFptr = NULL;
static Boolean       relativeFN;
static OptToggleSet  fileToggleButtons[NO_OF_TOGGLES];
static OptToggleDesc fileToggleNames[] = {
  {
    "fileLoadPackage",
     FileLoadPackage,
  }, {
    "fileLoadModule",
     FileLoadModule,
  }, {
    "fileReadFile",
     FileReadFile,
  }, {
    "fileReadQFile",
     FileReadQFile,
  }, {
    "fileToggleLogging",
     FileToggleLogging,
  }, {
    "filePrintScreen",
     FilePrintScreen,
  },
};

typedef enum {
  fileLoadPackageN = 0,
  fileLoadModuleN,
  fileReadFileN,
  fileReadQFileN,
  fileToggleLoggingN,
  filePrintScreenN
  } FileButtonNumber;



void SetFileButtonFonts(fontStructp)
  XFontStruct *fontStructp;
{
  Arg arg;
  int i;

  XtSetArg(arg, XtNfont, fontStructp);

  XtSetValues(                    fileButton, &arg, 1);
  XtSetValues(                fileTitleLabel, &arg, 1);
  XtSetValues(              fileMessageLabel, &arg, 1);
  XtSetValues(                  fileOkButton, &arg, 1);

  XRedSizeLabelForLabel(fileButton,NULL,NULL);

  for (i = 0; i < NO_OF_TOGGLES; i++) {
    XtSetValues( fileToggleButtons[i].label,  &arg, 1);
    XtSetValues( fileToggleButtons[i].toggle, &arg, 1);
  }
}


void SizeFileButtonsSuitably(wdp, thp)
  Dimension *wdp;
  Dimension *thp;
{
  Arg       arg[4];
  int       i;
  int       j;
  Dimension wd;
  Dimension h1;
  Dimension h2;
  Dimension bh;
  Dimension th;

  XRedSizeLabelForLabel(fileMessageLabel,&wd,NULL);
  if (wd > maxStripWidth) maxStripWidth = wd;

  i = 0; XtSetArg(arg[i], XtNwidth,  maxStripWidth); i++;
  XtSetValues(fileTitleLabel,         arg, i);
  XtSetValues(fileMessageLabel,       arg, i);
  XtSetValues(fileOkButton,           arg, i);

  i = 0; XtSetArg(arg[i], XtNheight,      &h1); i++;
         XtSetArg(arg[i], XtNborderWidth, &h2); i++;
  XtGetValues(fileTitleLabel,         arg, i);

  i = 0; XtSetArg(arg[i], XtNvSpace, &bh); i++;
  XtGetValues(fileBox,                arg, i);

  th = 3 * h1 + 6 * h2 + 4 * bh;

  for (j = 0; j < NO_OF_TOGGLES; j++) {

    XRedSizeLabelForLabel(fileToggleButtons[j].toggle,&wd,NULL);

    XtSetArg(arg[0], XtNwidth, maxStripWidth - wd - 14);
    XtSetValues(fileToggleButtons[j].label,  arg, 1);

    i = 0; XtSetArg(arg[i], XtNheight,       &h1); i++;
           XtSetArg(arg[i], XtNborderWidth,  &h2); i++;
    XtGetValues(fileToggleButtons[j].label,  arg, i);

    th = th + 2 * h2 + h1 + bh + TOGGLE_VERT_DIST + 4;
    i = 0; XtSetArg(arg[i], XtNborderWidth,  &h2); i++;
    XtGetValues(fileToggleButtons[j].form,   arg, i);

    th = th + 2 * h2 + 1;
  }

  wd = ((bh > 5) ? 2*bh : 10) + maxStripWidth;

  if (wdp != NULL) *wdp = wd;
  if (thp != NULL) *thp = th;
}


/*ARGSUSED*/
void FileButton(w, popup, call_data)
  Widget  w;
  Widget  popup;
  caddr_t call_data;
{
  Arg       arg[4];
  int       i;
  Dimension wd;
  Dimension th;
  Position  x;
  Position  y;
  Atom      wmPrtcls[2];

  SizeFileButtonsSuitably(&wd,&th);
  XRedTranslateCoords(referenceWidget, 65, 65, &x, &y, wd, th);
  XtRealizeWidget(popup);

  i = 0; XtSetArg(arg[i], XtNwidth,  wd); i++;
         XtSetArg(arg[i], XtNheight, th); i++;
  XtSetValues(fileBox,   arg, i);
  XtSetValues(popup,     arg, i);

  i = 0; XtSetArg(arg[i], XtNx, x); i++;
         XtSetArg(arg[i], XtNy, y); i++;
  XtSetValues(popup, arg, i);

  XtPopup(popup, XtGrabNone);
  XRaiseWindow(XtDisplay(popup), XtWindow(popup));

  wmPrtcls[0] =
    XInternAtom(XtDisplay(popup), "WM_DELETE_WINDOW", False);
  wmPrtcls[1] =
    XInternAtom(XtDisplay(popup), "WM_SAVE_YOURSELF", False);

  XtOverrideTranslations
    (popup,
     XtParseTranslationTable("<Message>WM_PROTOCOLS: reduce-file-done()"));

  XSetWMProtocols(XtDisplay(popup), XtWindow(popup), wmPrtcls, 2);
}


void FileInstateDatum(toggleSet, datum)
  Widget toggleSet;
  char * datum;
{
  Arg arg[3];
  int i;

  i = 0; XtSetArg(arg[i], XtNlabel, datum); i++;
  XtSetValues(toggleSet, arg, i);
}


void FileInstateBooleanValue(toggleSetN, datum)
  FileButtonNumber toggleSetN;
  Boolean          datum;
{
  Arg arg[3];
  int i;

  i = 0; XtSetArg(arg[i], XtNstate, datum); i++;
  XtSetValues(fileToggleButtons[toggleSetN].toggle, arg, i);

  FileInstateDatum(fileToggleButtons[toggleSetN].toggle, datum? "Yes":" No ");
}


/*
void doNotSetLogging()
{
  XtSetSensitive(fileBox, True);
}


void setLogging(successFlag)
  Boolean successFlag;
{
  if (successFlag) {

    app_data.logToFile = True;
    FileInstateBooleanValue(fileToggleLoggingN, True);

    XtFree(app_data.logFile);
    app_data.logFile = XtNewString(logFilename);

    XtSetSensitive(fileBox, True);
  }
}
*/



void FileSetupLogData()
{
  char  *tempName;
  void (*prevSigHandler)();

  if (app_data.logFile == NULL || !strcmp(app_data.logFile,"/dev/null")) {

    prevSigHandler = signal(SIGCHLD, SIG_DFL);

    if (!(logFilename = (char *)getenv("HOME")) &&
	!(logFilename = (char *)getcwd(NULL, NAME_MAX))) logFilename = NULL;

    if (tempName = tempnam(logFilename,"xred")) {

      logFilename = (char *)XtMalloc(NAME_MAX);
      strcpy(logFilename, tempName);

    } else {

      logFilename = (char *)XtMalloc(NAME_MAX);
      logFilename[0] = 0x0;
    }

    app_data.logFile = XtNewString(logFilename);
    signal(SIGCHLD, prevSigHandler);

  } else {

    logFilename = (char *)XtMalloc(NAME_MAX);
    strcpy(logFilename, app_data.logFile);
  }

  if (app_data.logToFile)
    if (!(logFileFptr = fopen(app_data.logFile, "w")))
      app_data.logToFile = False;
}


void WriteToLogFile(text, len)
  char *text;
  int   len;
{
  if (logFileFptr) {

    /* wn char *nt;

    nt = XtMalloc(len + 1);
    strncpy(nt, text, len);
    fputs(nt, logFileFptr);
  */
    fwrite (text,1,len,logFileFptr);
  }
}


void CloseLogFile()
{
  if (app_data.logToFile) {

    app_data.logToFile = False;
    if (logFileFptr) {
      fclose(logFileFptr);
      logFileFptr = NULL;
    }
  }
}


void FileToggleLoggingAux(name, fptr)
  char *name;
  FILE *fptr;
{
  if (!name || !fptr) return;

  if (logFilename) XtFree(logFilename);

  logFilename = XtNewString(name);
  logFileFptr = fptr;

  app_data.logToFile = True;
  FileInstateBooleanValue(fileToggleLoggingN, True);

  XtFree(app_data.logFile);
  app_data.logFile = XtNewString(logFilename);
}


/*ARGSUSED*/
void FileToggleLogging(w, label, m)
  Widget  w;
  Widget  label;
  caddr_t m;
{
  if (app_data.logToFile) {

    FileInstateBooleanValue(fileToggleLoggingN, False);
    CloseLogFile();

  } else {

    FileSetFonts(fileBox, buttonFont, helpXmplFont);
    FileGetFilename(fileBox, "Select file or enter filename for log...",
		    "Sorry, I can't find a directory to use for logfile",
		    LOG_PATH, "w", "xrout", True, True,
		    FileToggleLoggingAux);
  }
}



/* ARGSUSED */
void FilePrintScreen(w, n, m)
  Widget  w;
  caddr_t n, m;
{
  PrintInstall(fileBox);
}


/* ARGSUSED */
void FileLoadPackageAux(name, fptr)
  char   *name;
  caddr_t fptr;
{
  char *hcmd;
  char *ocmd;

  FileOkButton(fileOkButton, files, 0);
  if (!name) return;

  hcmd = (char *)XtMalloc(25 + strlen(name));
  ocmd = (char *)XtMalloc(25 + strlen(name));
  sprintf(hcmd, "load_package %s;\n", name);
  sprintf(ocmd, "[ Loading \"%s\" . . . ]", name);
  PlaceUrgentItemOnPending(hcmd, ocmd);
  XtFree(hcmd);
  XtFree(ocmd);

  PlaceItemOnPending("\n",1);
  GetReduceOutput(0, ReduceToMe, NULL);
  return;
}


void FileLoadPackage(w, n, m)
  Widget  w;
  caddr_t n, m;
{
  FileSetFonts(fileBox, buttonFont, helpXmplFont);
  FileGetFilename(fileBox, "Please choose a package to load...",
		  "Sorry, I can't get a list of packages",
		  PACKAGE_PATH, "r", NULL, False, False,
		  FileLoadPackageAux);
}



/* ARGSUSED */
void FileLoadModuleAux(name, fptr)
  char   *name;
  caddr_t fptr;
{
  char *hcmd;
  char *ocmd;
  int   len;

  FileOkButton(fileOkButton, files, 0);
  if (!name) return;

  if ((len = strlen(name)) > 2 && !strcmp(name + len - 2, ".b"))
    name[len -= 2] = 0;

  hcmd = (char *)XtMalloc(15 + len);
  ocmd = (char *)XtMalloc(25 + len);
  sprintf(hcmd, "load \"%s\";\n", name);
  sprintf(ocmd, "[ Loading \"%s\" . . . ]", name);
  PlaceUrgentItemOnPending(hcmd, ocmd);
  XtFree(hcmd);
  XtFree(ocmd);

  PlaceItemOnPending("\n",1);
  GetReduceOutput(0, ReduceToMe, NULL);
  return;
}


void FileLoadModule(w, n, m)
  Widget  w;
  caddr_t n, m;
{
  FileSetFonts(fileBox, buttonFont, helpXmplFont);
  FileGetFilename(fileBox, "Please choose a package file to load...",
		  "Sorry, I can't get a list of files",
		  MODULE_PATH, "r", NULL, True, False,
		  FileLoadModuleAux);
}


/* ARGSUSED */
void FileReadFileAux(name, fptr)
  char   *name;
  caddr_t fptr;
{
  char *hcmd;
  char *ocmd;

  FileOkButton(fileOkButton, files, 0);
  if (!name) return;

  hcmd = (char *)XtMalloc(15 + strlen(name));
  ocmd = (char *)XtMalloc(25 + strlen(name));
  sprintf(hcmd, "in \"%s\";\n", name);
  sprintf(ocmd, "[ Reading \"%s\" . . . ]", name);
  PlaceUrgentItemOnPending(hcmd, ocmd);
  XtFree(hcmd);
  XtFree(ocmd);

  PlaceItemOnPending("\n",1);
  GetReduceOutput(0, ReduceToMe, NULL);
  return;
}


void FileReadFile(w, n, m)
  Widget  w;
  caddr_t n, m;
{
  FileSetFonts(fileBox, buttonFont, helpXmplFont);
  FileGetFilename(fileBox, "Please choose a file to read noisily...",
		  "Sorry, I can't get a list of files",
		  READ_PATH, "r", NULL, True, False, FileReadFileAux);
}


/* ARGSUSED */
void FileReadQFileAux(name, fptr)
  char   *name;
  caddr_t fptr;
{
  char *hcmd;
  char *ocmd;

  FileOkButton(fileOkButton, files, 0);
  if (!name) return;

  hcmd = (char *)XtMalloc(15 + strlen(name));
  ocmd = (char *)XtMalloc(35 + strlen(name));
  sprintf(hcmd, "in \"%s\"$\n", name);
  sprintf(ocmd, "[ Reading \"%s\" quietly . . . ]", name);
  PlaceUrgentItemOnPending(hcmd, ocmd);
  XtFree(hcmd);
  XtFree(ocmd);

  PlaceItemOnPending("\n",1);
  GetReduceOutput(0, ReduceToMe, NULL);
  return;
}


void FileReadQFile(w, n, m)
  Widget  w;
  caddr_t n, m;
{
  FileSetFonts(fileBox, buttonFont, helpXmplFont);
  FileGetFilename(fileBox, "Please choose a file to read quietly...",
		  "Sorry, I can't get a list of files",
		  READ_PATH, "r", NULL, True, False, FileReadQFileAux);
}



/*ARGSUSED*/
void FileOkButton(w, popup, m)
  Widget  w;
  Widget  popup;
  caddr_t m;
{
  XtSetSensitive(w, False);
  XtPopdown(popup);
  XtSetSensitive(w, True);
/* Chris was soll das?   XtUnrealizeWidget(popup); */
}


void FileOkButtonAction(w, event)
  Widget        w;
  XButtonEvent *event;
{
  FileAbandon();
  FileOkButton(fileOkButton, files, 0);
}



void FileToggleCallback(w, n, m)
  Widget  w;
  Widget  n;
  caddr_t m;
{
  int i = 0;

  XtSetSensitive(w, False);
  while (i < NO_OF_TOGGLES && w != fileToggleButtons[i].toggle) ++i;
  if    (i < NO_OF_TOGGLES) fileToggleButtons[i].callback(w, n, m);
  XtSetSensitive(w, True);
}


OptToggleSet FileMakeToggleSet(name, parent, callback, datum)
  char         * name;
  Widget         parent;
  XtCallbackProc callback;
  char         * datum;
{
  Arg          arg[5];
  OptToggleSet newToggleSet;
  Dimension    wd;
  Dimension    wdt;
  int          i;
  int          nLen;
  char       * boxName;
  char       * toggleName;

  nLen = strlen(name);

     boxName = (char *)XtMalloc(nLen + 2);
  toggleName = (char *)XtMalloc(nLen + 2);

  strcpy(    boxName, name );
  strcpy( toggleName, name );

     boxName[ nLen     ] = 'B';
     boxName[ nLen + 1 ] = 0x0;
  toggleName[ nLen     ] = 'T';
  toggleName[ nLen + 1 ] = 0x0;

  newToggleSet.form     = XtCreateManagedWidget(boxName,
						formWidgetClass,
						parent,
						NULL, 0);

  newToggleSet.label    = XtCreateManagedWidget(name,
						labelWidgetClass,
						newToggleSet.form,
						NULL, 0);

  newToggleSet.toggle   = XtCreateManagedWidget(toggleName,
						commandWidgetClass,
						newToggleSet.form,
						NULL, 0);

  newToggleSet.callback = callback;

  XtAddCallback(newToggleSet.toggle, XtNcallback,
		FileToggleCallback, newToggleSet.label);

  i = 0; XtSetArg(arg[i], XtNlabel,                    "  "); i++;
         XtSetArg(arg[i], XtNfromHoriz,  newToggleSet.label); i++;
         XtSetArg(arg[i], XtNvertDistance, TOGGLE_VERT_DIST); i++;
         XtSetArg(arg[i], XtNborderWidth,                 0); i++;
         XtSetArg(arg[i], XtNfont,               buttonFont); i++;
  XtSetValues(newToggleSet.toggle, arg, i);

  if (datum != NULL) {

    FileInstateDatum(newToggleSet.toggle, datum);
  }

  i = 0; XtSetArg(arg[i], XtNwidth,                    &wd); i++;
  XtGetValues(newToggleSet.label,  arg, i); wdt  = wd;
  XtGetValues(newToggleSet.toggle, arg, i); wdt += wd;

  i = 0; XtSetArg(arg[i], XtNjustify,         XtJustifyLeft); i++;
         XtSetArg(arg[i], XtNvertDistance, TOGGLE_VERT_DIST); i++;
         XtSetArg(arg[i], XtNborderWidth,                 0); i++;
         XtSetArg(arg[i], XtNfont,               buttonFont); i++;
  XtSetValues(newToggleSet.label,  arg, i);

  if ((wdt + 10) > maxStripWidth) maxStripWidth = wdt + 10;

  XtFree(    boxName );
  XtFree( toggleName );

  return newToggleSet;
}



void createFileMenu(topLevel,parent)
  Widget topLevel;
  Widget parent;
{
  Arg       arg[4];
  int       i;
  char      datumSpace[20];
  char    * datum;

  fileButton           = XtCreateManagedWidget("fileButton",
					       commandWidgetClass,
					       parent,
					       NULL, 0);
  
  files                =    XtCreatePopupShell("files",
					       transientShellWidgetClass,
					       fileButton,
					       NULL, 0);

  fileBox              = XtCreateManagedWidget("fileBox",
					       boxWidgetClass,
					       files,
					       NULL, 0);

  fileTitleLabel       = XtCreateManagedWidget("fileTitleLabel",
					       labelWidgetClass,
					       fileBox,
					       NULL, 0);

  fileMessageLabel     = XtCreateManagedWidget("fileMessageLabel",
					       labelWidgetClass,
					       fileBox,
					       NULL, 0);

  i = 0; XtSetArg(arg[i], XtNwidth, &maxStripWidth); i++;
  XtGetValues(fileMessageLabel, arg, i);

  for (i = 0; i < NO_OF_TOGGLES; i++) {

    fileToggleButtons[i] = FileMakeToggleSet(fileToggleNames[i].name,
					     fileBox,
					     fileToggleNames[i].callback,
					     NULL);
  }

  i = 0; XtSetArg(arg[i], XtNfont, buttonFont); i++;
  XtSetValues(fileButton, arg, i);

  fileOkButton         = XtCreateManagedWidget("fileOkButton",
					       commandWidgetClass,
					       fileBox,
					       arg, i);
  FileSetupLogData();

  i = 0; XtSetArg(arg[i], XtNfont, buttonFont); i++;
  XtSetValues(fileTitleLabel,   arg, i);
  XtSetValues(fileMessageLabel, arg, i);
  XtSetValues(fileOkButton,     arg, i);

  i = 0; XtSetArg(arg[i], XtNbitmap, followOnArrow); i++;
  XtSetValues(fileToggleButtons[fileLoadPackageN].toggle, arg, i);
  XtSetValues(fileToggleButtons[fileLoadModuleN].toggle,  arg, i);
  XtSetValues(fileToggleButtons[fileReadFileN].toggle,    arg, i);
  XtSetValues(fileToggleButtons[fileReadQFileN].toggle,   arg, i);
  XtSetValues(fileToggleButtons[filePrintScreenN].toggle, arg, i);
  FileInstateBooleanValue(fileToggleLoggingN, app_data.logToFile);

  XtAddCallback(   fileButton, XtNcallback,   FileButton, files );
  XtAddCallback( fileOkButton, XtNcallback, FileOkButton, files );

  referenceWidget = topLevel;
}

