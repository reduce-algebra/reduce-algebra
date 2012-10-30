
/*
   Module to create and deal with popup New help box.
*/


#include "xreduce.h"
#include "main.h"
#include "widgets.h"
#include "xredplus.h"
#include "rarrow.xbm"
#include "message.h"
#include "font.h"
#include "input.h"
#include "manager.h"
#include "printer.h"
#include "verbal.h"
#include "file.h"

#define NO_OF_TOGGLES    7	/* was 8 with Page Mode */
#define TOGGLE_VERT_DIST 4

void nhelpHistLengthCommand();
void nhelpTogglePaging();
void nhelpToggleGraphics();
void nhelpToggleBracketMatch();
void nhelpToggleForceBrackets();
void nhelpPrintScreen();
void nhelpFontSelection();

extern Boolean helpInstalled;
extern char *helpRout ;
extern long TOCNode;
extern long topNode ;
extern long actNode ;

extern FILE * helpFile;
extern FILE * helpSFil;

Pixmap        followOnArrow;

/*static Widget        nhelpionButton;
*/
static Dimension     maxStripWidth;
static Widget        nhelpions;
static Widget        nhelpionBox;
static Widget        nhelpTitleLabel;
static Widget        nhelpMessageLabel;
static Widget        nhelpOkButton;
static Widget        nhelpExcalcLabel [20];
char ExcalcLabels [30][50];
char Excalctypes  [20][20];
char Excalcfiles  [30][50];
static Widget        nhelpHistLengthSubPopUp;
static Widget        nhelpHistLengthDialog;
static Widget        referenceWidget;

static Boolean       relativeFN;
static nhelpToggleSet  nhelpToggleButtons[NO_OF_TOGGLES];

typedef enum {
  nhelpHistLengthCommandN = 0,
/*  nhelpTogglePagingN, */
  nhelpToggleGreekN,
  nhelpToggleMonoRvN,
  nhelpToggleGraphicsN,
  nhelpToggleBracketMatchN,
  nhelpToggleForceBracketsN,
  nhelpFontSelectionN
  } nhelpButtonNumber;



void SetnhelpionButtonFonts(fontStructp)
  XFontStruct *fontStructp;
{
  Arg arg;
  int i;

  XtSetArg(arg, XtNfont, fontStructp);

/*  XtSetValues(                 nhelpionButton, &arg, 1);
*/
  XtSetValues(                nhelpTitleLabel, &arg, 1);
  XtSetValues(              nhelpMessageLabel, &arg, 1);
  XtSetValues(                  nhelpOkButton, &arg, 1);

/*  XRedSizeLabelForLabel(nhelpionButton,NULL,NULL);
*/

  for (i = 0; i < NO_OF_TOGGLES; i++) {
    XtSetValues( nhelpToggleButtons[i].label,  &arg, 1);
    XtSetValues( nhelpToggleButtons[i].toggle, &arg, 1);
  }

  SetFileButtonFonts(fontStructp);
}


void SizenhelpionButtonsSuitably(wdp, thp)
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

  XRedSizeLabelForLabel(nhelpMessageLabel,&wd,NULL);
  if (wd > maxStripWidth) maxStripWidth = wd;

  i = 0; XtSetArg(arg[i], XtNwidth,  maxStripWidth); i++;
  XtSetValues(nhelpTitleLabel,         arg, i);
  XtSetValues(nhelpMessageLabel,       arg, i);
  XtSetValues(nhelpOkButton,  arg, i);
  for (j=0;j<9;j++) XtSetValues(nhelpExcalcLabel[j],     arg, i);

  i = 0; XtSetArg(arg[i], XtNheight,      &h1); i++;
         XtSetArg(arg[i], XtNborderWidth, &h2); i++;
  XtGetValues(nhelpMessageLabel,       arg, i);

  i = 0; XtSetArg(arg[i], XtNvSpace, &bh); i++;
  XtGetValues(nhelpionBox,             arg, i);

  th = 3 * h1 + 6 * h2 + 4 * bh;

  wd = ((bh > 5) ? 2*bh : 10) + maxStripWidth;

  if (wdp != NULL) *wdp = wd;
  if (thp != NULL) *thp = th;
}

/*ARGSUSED*/
void newhelpbox(w,client_data, call_data)
  Widget w;
  caddr_t client_data,
          call_data;
{
void NhelpionButton();
NhelpionButton(w, nhelpions,  call_data);
}


/*ARGSUSED*/
void NhelpionButton(w, popup, call_data)
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

  SizenhelpionButtonsSuitably(&wd,&th);
  XRedTranslateCoords(referenceWidget, 50, 50, &x, &y, wd, th);

  XtRealizeWidget(popup);

  i = 0; XtSetArg(arg[i], XtNwidth,  wd); i++;
         XtSetArg(arg[i], XtNheight, 4*th); i++; /* length of newhelpbox */
  XtSetValues(nhelpionBox, arg, i);
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
     XtParseTranslationTable("<Message>WM_PROTOCOLS: reduce-nhelpion-done()"));

  XSetWMProtocols(XtDisplay(popup), XtWindow(popup), wmPrtcls, 2);
}


/*ARGSUSED*/
void nhelpHistLengthOK(w, dialog, m)
  Widget  w;
  Widget  dialog;
  caddr_t m;
{
  Arg  arg[3];
  int  i;
  int  newHistLength;
  char newLengthText[20];
  char complaint[50];

  newHistLength = atoi(XawDialogGetValueString(dialog));

  if (newHistLength < REDUCE_HISTORY_MIN_MAX ||
      newHistLength > REDUCE_HISTORY_MAX_MAX) {

    if (newHistLength < REDUCE_HISTORY_MIN_MAX)
      sprintf(complaint, "Minimum is %d", REDUCE_HISTORY_MIN_MAX);
    else
      sprintf(complaint, "Maximum is %d", REDUCE_HISTORY_MAX_MAX);

    i = 0; XtSetArg(arg[i], XtNlabel, complaint); i++;
    XtSetValues(dialog, arg, i);

    XBell(XtDisplay(referenceWidget),80);

  } else {

    app_data.reduceHistoryMax = newHistLength;

    sprintf(newLengthText,"%d",newHistLength);

    XtSetSensitive(w, False);
    XtPopdown(nhelpHistLengthSubPopUp);
    XtSetSensitive(w, True);
    XtSetSensitive(nhelpionBox, True);
    XtUnrealizeWidget(nhelpHistLengthSubPopUp);
  }
}


/*ARGSUSED*/
void nhelpHistLengthCancel(w, dialog, m)
  Widget  w;
  Widget  dialog;
  caddr_t m;
{
  XtSetSensitive(w, False);
  XtPopdown(nhelpHistLengthSubPopUp);
  XtSetSensitive(w, True);
  XtSetSensitive(nhelpionBox, True);
  XtUnrealizeWidget(nhelpHistLengthSubPopUp);
}


/*ARGSUSED*/
void nhelpHistLengthCommand(w, n, m)
  Widget  w;
  caddr_t n, m;
{
  Widget    label;
  Position  x;
  Position  y;
  Arg       arg[5];
  int       i;

  i = 0; XtSetArg(arg[i], XtNlabel, "Number of lines on history:"); i++;
         XtSetArg(arg[i], XtNvalue,                            ""); i++;
  XtSetValues(nhelpHistLengthDialog, arg, i);

  XRedTranslateCoords(w, 15, 12, &x, &y, 200, 200);
  i = 0; XtSetArg(arg[i], XtNx,                                 x); i++;
         XtSetArg(arg[i], XtNy,                                 y); i++;
  XtSetValues(nhelpHistLengthSubPopUp, arg, i);

  XtRealizeWidget(nhelpHistLengthSubPopUp);

  XRedSizeLabelForLabel(label,                       NULL, NULL);

  XtSetSensitive(nhelpionBox, False);
  XtPopup(nhelpHistLengthSubPopUp, XtGrabNonexclusive);
  XRaiseWindow(XtDisplay(nhelpHistLengthSubPopUp),
	       XtWindow(nhelpHistLengthSubPopUp));
}



/*ARGSUSED*/
void nhelpToggleGraphics(w, n, m)
  Widget  w;
  caddr_t n, m;
{
  if (app_data.useGraphics) {
    VerbalVerbatim(True);
    PlaceUrgentItemOnPending("lisp x!-g!-n!!()$  %% XR Graphic Command\n",
			     "[ Graphics switched OFF ]\n");
  } else {
    VerbalVerbatim(False);
    PlaceUrgentItemOnPending("lisp x!-g!-y!!()$  %% XR Graphic Command\n",
			     "[ Graphics switched ON ]\n");
  }

  app_data.useGraphics = !(app_data.useGraphics);
}


/*ARGSUSED*/
void nhelpToggleBracketMatch(w, n, m)
  Widget  w;
  caddr_t n, m;
{
  app_data.matchBrackets = !(app_data.matchBrackets);
}


/*ARGSUSED*/
void nhelpToggleForceBrackets(w, n, m)
  Widget  w;
  caddr_t n, m;
{
  app_data.forceBracketMatch = !(app_data.forceBracketMatch);
}


/* ARGSUSED */
void nhelpPrintScreen(w, n, m)
  Widget  w;
  caddr_t n, m;
{
  PrintInstall(nhelpionBox);
}


/*ARGSUSED*/
void nhelpFontSelection(w, n, m)
  Widget  w;
  caddr_t n, m;
{
  if (fontSelectorActive)
    XBell(XtDisplay(referenceWidget), 50);
  else installFontSelector();

}


/*ARGSUSED*/
void NhelpOkButton(w, popup, m)
  Widget  w;
  Widget  popup;
  caddr_t m;
{
  XtSetSensitive(w, False);
  XtPopdown(popup);
  XtSetSensitive(w, True);
  XtUnrealizeWidget(popup);
}


/* ARGSUSED */
void nhelpOkButtonAction(w, event)
  Widget        w;
  XButtonEvent *event;
{
  NhelpOkButton(nhelpOkButton, nhelpions, 0);
}

static int nhelpselected = -1;

/*ARGSUSED*/
void Nhelppressed(w, popup, m)
  Widget  w;
  int popup;
  caddr_t m;
{
  char dirfile[255];
  char dirfile1[255];
  XtSetSensitive(w, False);
  if (nhelpselected != popup) { helpInstalled = False;
				TOCNode = -1;
				topNode = -1;
				actNode = -1;
				helpRout = NULL;
				HelpCloseHelpFile();
   if (helpSFil) { fclose (helpSFil); helpSFil = NULL;};
   if (helpFile) { fclose (helpFile); helpFile = NULL;}};
  nhelpselected = popup;

  if (popup == 0) { sprintf(dirfile,"%s/help/redref.info",
			getenv("reduce"));
		    HelpSetHelpFile(dirfile);
                    HelpInstallHelp(); }
    else  { sprintf(dirfile,"%s/%s",getenv("reduce"),Excalcfiles[popup]);
	    if (strncmp(Excalctypes[popup],"h",1) == 0)
		{HelpSetHelpFile(dirfile); HelpInstallHelp(); }
	    else { sprintf(dirfile1,"xterm -e more %s &",dirfile);
		   system(dirfile1);
           };    };
  
  XtSetSensitive(w, True);
}


void createnhelpionMenu(topLevel,parent)
  Widget topLevel;
  Widget parent;
{
  Arg       arg[4];
  int       i,j;
  char      datumSpace[20];
  char    * datum;

  readexcalc();

/*  nhelpionButton           = XtCreateManagedWidget("",
						 commandWidgetClass,
						 parent,
						 NULL, 0);
*/
  nhelpions                = XtCreatePopupShell("Help Menu",
						 transientShellWidgetClass,
						 parent,/* nhelpionButton,*/
						 NULL, 0);

  nhelpionBox              = XtCreateManagedWidget("nhelpionBox",
						 boxWidgetClass,
						 nhelpions,
						 NULL, 0);

  nhelpTitleLabel          = XtCreateManagedWidget("nhelpTitleLabel",
						 labelWidgetClass,
						 nhelpionBox,
						 NULL, 0);

  nhelpMessageLabel        = XtCreateManagedWidget("nhelpMessageLabel",
						 labelWidgetClass,
						 nhelpionBox,
						 NULL, 0);
  for (i=0;i<9;i++)
  nhelpExcalcLabel [i]     = XtCreateManagedWidget(ExcalcLabels[i],
                                                 commandWidgetClass,
                                                 nhelpionBox,
                                                 NULL, 0);

  /*
  i = 0; XtSetArg(arg[i], XtNwidth, &maxStripWidth); i++;
  XtGetValues(nhelpMessageLabel, arg, i);
  */


  i = 0; XtSetArg(arg[i], XtNfont, buttonFont); i++;
/*  XtSetValues(nhelpionButton, arg, i);*/
  XtSetValues(nhelpMessageLabel, arg, i);
  XtSetValues(nhelpTitleLabel, arg, i);
  for (j=0;j<9;j++) XtSetValues(nhelpExcalcLabel[j], arg, i);

  nhelpOkButton            = XtCreateManagedWidget("nhelpOkButton",
                                                       commandWidgetClass,
                                                       nhelpionBox,
                                                       arg, i);

  XtAddCallback( nhelpOkButton, XtNcallback,  NhelpOkButton, nhelpions );
  for (i=0;i<9;i++)
  XtAddCallback( nhelpExcalcLabel[i] , XtNcallback, Nhelppressed, i);

  referenceWidget = topLevel;
}

char Excalcdummy  [30][30];

readexcalc()
{ int i;
  char dirfile[255];
  FILE * helpdir;

  sprintf(dirfile,"%s/help/helpdir.info",getenv("reduce"));
  helpdir = fopen(dirfile,"r");
  if(helpdir == (FILE*) NULL) { perror(dirfile); return (0);};
  for (i=0;i<12;i++) {
		fscanf(helpdir,"%s%s%s%s\n",&Excalctypes[i][0],
		&ExcalcLabels[i][0],&Excalcdummy[i][0],
		&Excalcfiles[i][0]);
		}
fclose (helpdir);
}
