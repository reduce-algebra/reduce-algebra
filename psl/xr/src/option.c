
/*
   Module to create and deal with popup Options box.
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

void OptHistLengthCommand();
void OptTogglePaging();
void OptToggleGreek();
void OptToggleMonoRv();
void OptToggleGraphics();
void OptToggleBracketMatch();
void OptToggleForceBrackets();
void OptPrintScreen();
void OptFontSelection();

Pixmap        followOnArrow;

static Widget        optionButton;
static Dimension     maxStripWidth;
static Widget        options;
static Widget        optionBox;
static Widget        optTitleLabel;
static Widget        optMessageLabel;
static Widget        optOkButton;
static Widget        optHistLengthSubPopUp;
static Widget        optHistLengthDialog;
static Widget        optHistLengthDialogYesButton;
static Widget        optHistLengthDialogNoButton;
static Widget        referenceWidget;

static Boolean       relativeFN;
static OptToggleSet  optToggleButtons[NO_OF_TOGGLES];
static OptToggleDesc optToggleNames[] = {
  {
    "optHistLengthCommand",
     OptHistLengthCommand,
/*
  }, {
    "optTogglePaging",
     OptTogglePaging,
*/
  }, {
    "optToggleGreek",
     OptToggleGreek,
  }, {
    "optToggleMonoRv",
     OptToggleMonoRv,
  }, {
    "optToggleGraphics",
     OptToggleGraphics,
  }, {
    "optToggleBracketMatch",
     OptToggleBracketMatch,
  }, {
    "optToggleForceBrackets",
     OptToggleForceBrackets,
  }, {
    "optFontSelection",
     OptFontSelection,
  },
};

typedef enum {
  optHistLengthCommandN = 0,
/*  optTogglePagingN, */
  optToggleGreekN,
  optToggleMonoRvN,
  optToggleGraphicsN,
  optToggleBracketMatchN,
  optToggleForceBracketsN,
  optFontSelectionN
  } OptButtonNumber;



void SetOptionButtonFonts(fontStructp)
  XFontStruct *fontStructp;
{
  Arg arg;
  int i;

  XtSetArg(arg, XtNfont, fontStructp);

  XtSetValues(                 optionButton, &arg, 1);
  XtSetValues(                optTitleLabel, &arg, 1);
  XtSetValues(              optMessageLabel, &arg, 1);
  XtSetValues(                  optOkButton, &arg, 1);
  XtSetValues( optHistLengthDialogYesButton, &arg, 1);
  XtSetValues(  optHistLengthDialogNoButton, &arg, 1);

  XRedSizeLabelForLabel(optionButton,NULL,NULL);

  for (i = 0; i < NO_OF_TOGGLES; i++) {
    XtSetValues( optToggleButtons[i].label,  &arg, 1);
    XtSetValues( optToggleButtons[i].toggle, &arg, 1);
  }

  SetFileButtonFonts(fontStructp);
}


void SizeOptionButtonsSuitably(wdp, thp)
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

  XRedSizeLabelForLabel(optMessageLabel,&wd,NULL);
  if (wd > maxStripWidth) maxStripWidth = wd;

  i = 0; XtSetArg(arg[i], XtNwidth,  maxStripWidth); i++;
  XtSetValues(optTitleLabel,         arg, i);
  XtSetValues(optMessageLabel,       arg, i);
  XtSetValues(optOkButton,           arg, i);

  i = 0; XtSetArg(arg[i], XtNheight,      &h1); i++;
         XtSetArg(arg[i], XtNborderWidth, &h2); i++;
  XtGetValues(optMessageLabel,       arg, i);

  i = 0; XtSetArg(arg[i], XtNvSpace, &bh); i++;
  XtGetValues(optionBox,             arg, i);

  th = 3 * h1 + 6 * h2 + 4 * bh;

  for (j = 0; j < NO_OF_TOGGLES; j++) {

    XRedSizeLabelForLabel(optToggleButtons[j].toggle,&wd,NULL);

    XtSetArg(arg[0], XtNwidth, maxStripWidth - wd - 14);
    XtSetValues(optToggleButtons[j].label,  arg, 1);

    i = 0; XtSetArg(arg[i], XtNheight,       &h1); i++;
           XtSetArg(arg[i], XtNborderWidth,  &h2); i++;
    XtGetValues(optToggleButtons[j].label,  arg, i);

    th = th + 2 * h2 + h1 + bh + TOGGLE_VERT_DIST + 4;
    i = 0; XtSetArg(arg[i], XtNborderWidth,  &h2); i++;
    XtGetValues(optToggleButtons[j].form,   arg, i);

    th = th + 2 * h2 + 1;
  }

  wd = ((bh > 5) ? 2*bh : 10) + maxStripWidth;

  if (wdp != NULL) *wdp = wd;
  if (thp != NULL) *thp = th;
}


/*ARGSUSED*/
void OptionButton(w, popup, call_data)
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

  SizeOptionButtonsSuitably(&wd,&th);
  XRedTranslateCoords(referenceWidget, 50, 50, &x, &y, wd, th);
  XtRealizeWidget(popup);

  i = 0; XtSetArg(arg[i], XtNwidth,  wd); i++;
         XtSetArg(arg[i], XtNheight, th); i++;
  XtSetValues(optionBox, arg, i);
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
     XtParseTranslationTable("<Message>WM_PROTOCOLS: reduce-option-done()"));

  XSetWMProtocols(XtDisplay(popup), XtWindow(popup), wmPrtcls, 2);
}


void InstateDatum(toggleSet, datum)
  Widget toggleSet;
  char * datum;
{
  Arg arg[3];
  int i;

  i = 0; XtSetArg(arg[i], XtNlabel, datum); i++;
  XtSetValues(toggleSet, arg, i);
}


void InstateBooleanValue(toggleSetN, datum)
  OptButtonNumber toggleSetN;
  Boolean         datum;
{
  Arg arg[3];
  int i;

  i = 0; XtSetArg(arg[i], XtNstate, datum); i++;
  XtSetValues( optToggleButtons[(int)toggleSetN].toggle, arg, i);
  InstateDatum(optToggleButtons[(int)toggleSetN].toggle, datum ? "Yes":" No ");
}


/*ARGSUSED*/
void OptHistLengthOK(w, dialog, m)
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
    InstateDatum(optToggleButtons[(int)optHistLengthCommandN].toggle,
		 newLengthText);

    XtSetSensitive(w, False);
    XtPopdown(optHistLengthSubPopUp);
    XtSetSensitive(w, True);
    XtSetSensitive(optionBox, True);
/*    XtUnrealizeWidget(optHistLengthSubPopUp); */
  }
}


/*ARGSUSED*/
void OptHistLengthCancel(w, dialog, m)
  Widget  w;
  Widget  dialog;
  caddr_t m;
{
  XtSetSensitive(w, False);
  XtPopdown(optHistLengthSubPopUp);
  XtSetSensitive(w, True);
  XtSetSensitive(optionBox, True);
/*  XtUnrealizeWidget(optHistLengthSubPopUp); */
}


/*ARGSUSED*/
void OptHistLengthCommand(w, n, m)
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
  XtSetValues(optHistLengthDialog, arg, i);

  XRedTranslateCoords(w, 15, 12, &x, &y, 200, 200);
  i = 0; XtSetArg(arg[i], XtNx,                                 x); i++;
         XtSetArg(arg[i], XtNy,                                 y); i++;
  XtSetValues(optHistLengthSubPopUp, arg, i);

  XtRealizeWidget(optHistLengthSubPopUp);

  if ((label = XtNameToWidget(optHistLengthDialog, "label")) == NULL)
       label = optHistLengthDialogNoButton;

  XRedSizeLabelForLabel(label,                       NULL, NULL);
  XRedSizeLabelForLabel(optHistLengthDialogNoButton, NULL, NULL);

  XtSetSensitive(optionBox, False);
  XtPopup(optHistLengthSubPopUp, XtGrabNonexclusive);
  XRaiseWindow(XtDisplay(optHistLengthSubPopUp),
	       XtWindow(optHistLengthSubPopUp));
}



/*ARGSUSED*/
/*
void OptTogglePaging(w, n, m)
  Widget w;
  caddr_t n, m;
{
  app_data.pageMode = !(app_data.pageMode);
  if (!app_data.pageMode) SwitchPageModeBackOff();
  InstateBooleanValue(optTogglePagingN, app_data.pageMode);
}
*/


/*ARGSUSED*/
void OptToggleGreek(w, n, m)
  Widget  w;
  caddr_t n, m;
{
  app_data.useGreekFont = !(app_data.useGreekFont);
  setupGraphics(referenceWidget);

  InstateBooleanValue(optToggleGreekN, app_data.useGreekFont);
}


/*ARGSUSED*/
void OptToggleMonoRv(w, n, m)
  Widget  w;
  caddr_t n, m;
{
  app_data.reverseGraph = !(app_data.reverseGraph);
  setupGraphics(referenceWidget);

  InstateBooleanValue(optToggleMonoRvN, app_data.reverseGraph);
}


/*ARGSUSED*/
void OptToggleGraphics(w, n, m)
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
  InstateBooleanValue(optToggleGraphicsN, app_data.useGraphics);
}


/*ARGSUSED*/
void OptToggleBracketMatch(w, n, m)
  Widget  w;
  caddr_t n, m;
{
  app_data.matchBrackets = !(app_data.matchBrackets);
  InstateBooleanValue(optToggleBracketMatchN, app_data.matchBrackets);
}


/*ARGSUSED*/
void OptToggleForceBrackets(w, n, m)
  Widget  w;
  caddr_t n, m;
{
  app_data.forceBracketMatch = !(app_data.forceBracketMatch);
  InstateBooleanValue(optToggleForceBracketsN, app_data.forceBracketMatch);
}


/* ARGSUSED */
void OptPrintScreen(w, n, m)
  Widget  w;
  caddr_t n, m;
{
  PrintInstall(optionBox);
}


/*ARGSUSED*/
void OptFontSelection(w, n, m)
  Widget  w;
  caddr_t n, m;
{
  if (fontSelectorActive)
    XBell(XtDisplay(referenceWidget), 50);
  else installFontSelector();

}


/*ARGSUSED*/
void OptOkButton(w, popup, m)
  Widget  w;
  Widget  popup;
  caddr_t m;
{
  XtSetSensitive(w, False);
  XtPopdown(popup);
  XtSetSensitive(w, True);
  /* XtUnrealizeWidget(popup); */
}


/* ARGSUSED */
void OptOkButtonAction(w, event)
  Widget        w;
  XButtonEvent *event;
{
  OptOkButton(optOkButton, options, 0);
}



void OptToggleCallback(w, n, m)
  Widget  w;
  Widget  n;
  caddr_t m;
{
  int i = 0;

  XtSetSensitive(w, False);
  while (i < NO_OF_TOGGLES && w != optToggleButtons[i].toggle) ++i;
  if    (i < NO_OF_TOGGLES) optToggleButtons[i].callback(w, n, m);
  XtSetSensitive(w, True);
}


OptToggleSet MakeToggleSet(name, parent, callback, datum)
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
		OptToggleCallback, newToggleSet.label);

  i = 0; XtSetArg(arg[i], XtNlabel,                    "  "); i++;
         XtSetArg(arg[i], XtNfromHoriz,  newToggleSet.label); i++;
         XtSetArg(arg[i], XtNvertDistance, TOGGLE_VERT_DIST); i++;
         XtSetArg(arg[i], XtNborderWidth,                 0); i++;
         XtSetArg(arg[i], XtNfont,               buttonFont); i++;
  XtSetValues(newToggleSet.toggle, arg, i);

  if (datum != NULL) {

    InstateDatum(newToggleSet.toggle, datum);
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



void createOptionMenu(topLevel,parent)
  Widget topLevel;
  Widget parent;
{
  Arg       arg[4];
  int       i;
  char      datumSpace[20];
  char    * datum;

  optionButton           = XtCreateManagedWidget("optionButton",
						 commandWidgetClass,
						 parent,
						 NULL, 0);

  options                =    XtCreatePopupShell("options",
						 transientShellWidgetClass,
						 optionButton,
						 NULL, 0);

  optionBox              = XtCreateManagedWidget("optionBox",
						 boxWidgetClass,
						 options,
						 NULL, 0);

  optTitleLabel          = XtCreateManagedWidget("optTitleLabel",
						 labelWidgetClass,
						 optionBox,
						 NULL, 0);

  optMessageLabel        = XtCreateManagedWidget("optMessageLabel",
						 labelWidgetClass,
						 optionBox,
						 NULL, 0);

  /*
  i = 0; XtSetArg(arg[i], XtNwidth, &maxStripWidth); i++;
  XtGetValues(optMessageLabel, arg, i);
  */

  for (i = 0; i < NO_OF_TOGGLES; i++) {
    if (i == (int)optHistLengthCommandN) {

      sprintf(datumSpace,"%d",app_data.reduceHistoryMax);
      datum = datumSpace;

    } else datum = NULL;

    optToggleButtons[i] = MakeToggleSet(optToggleNames[i].name,
					optionBox,
					optToggleNames[i].callback,
					datum);
  }

  i = 0; XtSetArg(arg[i], XtNfont, buttonFont); i++;
  XtSetValues(optionButton, arg, i);

  optOkButton                  = XtCreateManagedWidget("optOkButton",
						       commandWidgetClass,
						       optionBox,
						       arg, i);

  optHistLengthSubPopUp =
    XtCreatePopupShell("subPopUp",
		       transientShellWidgetClass,
		       optToggleButtons[(int)optHistLengthCommandN].toggle,
		       NULL, 0);

  optHistLengthDialog          = XtCreateManagedWidget("optHistLengthDialog",
						       dialogWidgetClass,
						       optHistLengthSubPopUp,
						       NULL, 0);

  optHistLengthDialogYesButton = XtCreateManagedWidget("yesButton",
						       commandWidgetClass,
						       optHistLengthDialog,
						       arg, i);

  optHistLengthDialogNoButton  = XtCreateManagedWidget("noButton",
						       commandWidgetClass,
						       optHistLengthDialog,
						       arg, i);

  XtAddCallback(optHistLengthDialogYesButton, XtNcallback,
		OptHistLengthOK,     optHistLengthDialog);
  XtAddCallback(optHistLengthDialogNoButton,  XtNcallback,
		OptHistLengthCancel, optHistLengthDialog);

  i = 0; XtSetArg(arg[i], XtNfont, buttonFont); i++;
  XtSetValues(optTitleLabel,   arg, i);
  XtSetValues(optMessageLabel, arg, i);
  XtSetValues(optOkButton,     arg, i);

  followOnArrow = XCreateBitmapFromData(XtDisplay(topLevel),
					RootWindowOfScreen(XtScreen(topLevel)),
					rarrow_bits,
					rarrow_width, rarrow_height);

  i = 0; XtSetArg(arg[i], XtNbitmap, followOnArrow); i++;
  XtSetValues(optToggleButtons[(int)optFontSelectionN].toggle, arg, i);

/*  InstateBooleanValue(optTogglePagingN,        app_data.pageMode); */
  InstateBooleanValue(optToggleGreekN,         app_data.useGreekFont);
  InstateBooleanValue(optToggleMonoRvN,        app_data.reverseGraph);
  InstateBooleanValue(optToggleBracketMatchN,  app_data.matchBrackets);
  InstateBooleanValue(optToggleForceBracketsN, app_data.forceBracketMatch);
  InstateBooleanValue(optToggleGraphicsN,      True);

  XtAddCallback( optionButton, XtNcallback, OptionButton, options );
  XtAddCallback(  optOkButton, XtNcallback,  OptOkButton, options );

  referenceWidget = topLevel;
}

