
/*
   Module to handle managing output widgets: when to place them,
   when not to place them, &c.  Mainly used in paging mode.

   Note that other modules (verbal and xredtech) are responsible
   for creating the widgets and maintaining most of the history
   list; this module only handles the "managed" field in the
   history list structure, and the Xt management of the widgets.

   Chris Cannam, Feb 1993
*/

#include "xreduce.h"
#include "main.h"
#include "widgets.h"
#include "xredplus.h"
#include "output.h"
#include "verbal.h"

			   /* All heights in pixels.                         */

Dimension placedHeight;	   /* Height (up to a maximum of singleScreenHeight) */
			   /* to which widgets have been made (not managed); */
			   /* not really of concern to this module, but kept */
			   /* here 'cos it seemed like a good place          */

Dimension screenHeight;	   /* Height tolerable before screen is full. Used   */
			   /* by this and other modules; should be changed   */
			   /* when the output pane is resized                */

static Dimension h;	   /* Height (up to singleScreenHeight) to which     */
			   /* widgets have been managed.  Maintained & used  */
			   /* only by this module.                           */

static int prevHeight;
static int prevtLen;	   /* Used to determine whether the last widget, if  */
			   /* it's a Verbal widget, has changed size (in     */
			   /* which case it'll want remanaging.)             */

static Dimension sinceMW;
static Boolean   managementWaiting;
static Boolean   outputPaused;

static Cursor    normalCursor;
static Cursor    prevCursor;
       Cursor    watchCursor;
       Cursor    moreCursor;

void ManageSomeHistList(); /* Function external code should call after       */
			   /* creating a new widget (or some new widgets)    */



Widget CreateWidget(name, widget_class, parent, args, num_args)
  String      name;
  WidgetClass widget_class;
  Widget      parent;
  ArgList     args;
  Cardinal    num_args;
{
  if (app_data.pageMode) {

    return XtCreateWidget(name, widget_class, parent, args, num_args);

  } else {

    return XtCreateManagedWidget(name, widget_class, parent, args, num_args);
  }
}



Boolean InitiallyManaged()
{
  return (!(app_data.pageMode));
}



void DisplayWatchCursor()
{
  Arg    arg;
  Cursor tempCursor;

  XtSetArg(arg, XtNcursor, &tempCursor);
  XtGetValues(inputPane, &arg, 1);

  if (tempCursor != moreCursor) {

    XtSetArg(arg, XtNcursor, watchCursor);
    XtSetValues(inputPane, &arg, 1);
    XSync(XtDisplay(inputPane), False);
  }
  prevCursor = watchCursor;
}



void UndisplayWatchCursor()
{
  Arg arg;
  Cursor tempCursor;

  XtSetArg(arg, XtNcursor, &tempCursor);
  XtGetValues(inputPane, &arg, 1);

  if (tempCursor != moreCursor) {

    XtSetArg(arg, XtNcursor, normalCursor);
    XtSetValues(inputPane, &arg, 1);
    XSync(XtDisplay(inputPane), False);
  }
  prevCursor = normalCursor;
}



void DisplayMoreCursor(storeFlag)
  Boolean storeFlag;
{
  Arg    arg;
  Cursor tempCursor;

  if (storeFlag) {

    XtSetArg(arg, XtNcursor, &tempCursor);
    XtGetValues(inputPane, &arg, 1);

    if (tempCursor != moreCursor) prevCursor = tempCursor;
  }

  XtSetArg(arg, XtNcursor, moreCursor);
  XtSetValues(inputPane, &arg, 1);

  XSync(XtDisplay(inputPane), False);
}



void UndisplayMoreCursor()
{
  Arg arg;

  XtSetArg(arg, XtNcursor, prevCursor);
  XtSetValues(inputPane, &arg, 1);

  XSync(XtDisplay(inputPane), False);
}



/* For this function we assume the more cursor has already been removed */

/*ARGSUSED*/
void StepButton(client_data)
  caddr_t client_data;
{
  Arg arg;

  if (managementWaiting) {

    sinceMW = 0;
    h       = 0;
    managementWaiting = False;

    if (outputPaused) {

      outputPaused = False;
      RestartReduceOutput();
    }
  }

  XtSetArg(arg, XtNheight, &screenHeight);
  XtGetValues(outputPane, &arg, 1);
  ManageSomeHistList();
}



/*ARGSUSED*/
void StepButtonAction(w,event)
  Widget w;
  XButtonEvent *event;
{
  if (managementWaiting) {
    UndisplayMoreCursor();
    XtAppAddTimeOut(app_ctxt, 50, StepButton, 0);
  }
}



void RaisePlacedHeight(n)
  int n;
{
  placedHeight += n;

  if (managementWaiting) {

    if (!outputPaused && (sinceMW += n) > screenHeight) {

      outputPaused = True;
      UnHandleReduceOutput();
    }
  } else sinceMW = 0;
}



/* Should be called ONLY when the endOfHistory item is known to be Verbal */

void FreeManager()
{
  if (!managementWaiting) {

    endOfHistory->height = verbalHeight * 2;
    ManageSomeHistList();
    placedHeight = verbalHeight * 2;
  }
}


void ManageOne(advanceFlag)
  Boolean advanceFlag;
{
  if (!(endOfManaged->managed)) {

    if ((endOfManaged->histNo - reduceHistory->histNo) >
	(app_data.reduceHistoryMax + app_data.reduceHistoryExcess))
      reduceHistory = ClipFromHistList(reduceHistory, endOfManaged);
{
  HistList *hl;
  for (hl = reduceHistory; hl; hl = hl->next)
{ printf("Punkt1 %x %d %d\n", hl, hl->width,hl->height);
}}


    XtManageChild(endOfManaged->widget);
    endOfManaged->managed = True;

  } else {

    if ((endOfManaged->histNo - reduceHistory->histNo) >
	(app_data.reduceHistoryMax + app_data.reduceHistoryExcess))
      reduceHistory = ClipFromHistList(reduceHistory, endOfManaged);
{
  HistList *hl;
  for (hl = reduceHistory; hl; hl = hl->next)
{ printf("Punkt2 %x %d %d\n", hl, hl->width,hl->height);
}}
  }

  if (advanceFlag) endOfManaged = endOfManaged->next;
}



void SwitchPageModeBackOff()
{
  HistList *tempM;

  app_data.pageMode = False;

  for (tempM = endOfManaged; endOfManaged;
       tempM = endOfManaged, endOfManaged = endOfManaged->next)

    if (!(endOfManaged->managed)) {
      XtManageChild(endOfManaged->widget);
      endOfManaged->managed = True;
    }

  endOfManaged = tempM;

  if ((reduceHistoryNumber - reduceHistory->histNo) >
      (app_data.reduceHistoryMax + app_data.reduceHistoryExcess))
    reduceHistory = ClipFromHistList(reduceHistory, endOfManaged);
{
  HistList *hl;
  for (hl = reduceHistory; hl; hl = hl->next)
{ printf("Punkt3 %x %d %d\n", hl, hl->width,hl->height);
}}


  UndisplayMoreCursor();
  StepButton(inputPane, 0, 0);
  ManageSomeHistList();
}



void ManageSomeHistList()
{
  HistList *ptr;
  Dimension bh;

  if (!(app_data.pageMode)) {

    while (endOfManaged->next) {

      if (!(endOfManaged->managed)) ManageOne(True);
      else endOfManaged = endOfManaged->next;
    }

    if ((endOfManaged->histNo - reduceHistory->histNo) >
	(app_data.reduceHistoryMax + app_data.reduceHistoryExcess))
      reduceHistory = ClipFromHistList(reduceHistory, endOfManaged);
{
  HistList *hl;
  for (hl = reduceHistory; hl; hl = hl->next)
{ printf("Punkt4 %x %d %d\n", hl, hl->width,hl->height);
}}


    SetOutputToBottom();
    return;
  }

  bh = h;
  while (endOfManaged->next && endOfManaged->managed)
    endOfManaged = endOfManaged->next;

  if (managementWaiting) {
    DisplayMoreCursor(False);
    return;
  }

  if (endOfManaged->managed) {

    if (endOfManaged->flavour    == ReduceVerbal &&
	endOfManaged->textLength >  prevtLen     &&
	(int)bh                  >= prevHeight) {

      h -= prevHeight;
      h += endOfManaged->height;

      ManageOne(False);

      prevtLen   = endOfManaged->textLength;
      prevHeight = endOfManaged->height;

      SetOutputToBottom();
      return;

    } else {

      SetOutputToBottom();
      return;
    }
  }

  if (bh == 0 && endOfManaged->height >= screenHeight) {

    bh += endOfManaged->height;
    ManageOne(True);
    managementWaiting = True;
    DisplayMoreCursor(True);

  } else {

    ptr = endOfManaged;

    while (ptr && (((int)bh + ptr->height) < screenHeight)) {

      bh += ptr->height;
      ptr = ptr->next;
    }

    while (endOfManaged       != ptr &&
	   endOfManaged->next != ptr)    ManageOne(True);
    if    (endOfManaged              &&
	   endOfManaged->next == ptr)    ManageOne(False);

    if (ptr || ((int)bh + verbalHeight > screenHeight)) {

      managementWaiting = True;
      DisplayMoreCursor(True);

    } else UndisplayMoreCursor();
  }

  h = bh;

  SetOutputToBottom();
}



void installManager(parent)	/* Call after containing widgets realized  */
  Widget parent;		/* and history list created.  Pretty late. */
{				/* Parent should probably be titleBar      */
  int     i;
  Arg     arg[2];

   moreCursor  = XCreateFontCursor(XtDisplay(parent),XC_hand1);
  watchCursor  = XCreateFontCursor(XtDisplay(parent),XC_watch);

  screenHeight = app_data.historyPaneHeight;

  i = 0; XtSetArg(arg[i], XtNcursor, &prevCursor); i++;
  XtGetValues(inputPane, arg, i);
  normalCursor = prevCursor;
}

