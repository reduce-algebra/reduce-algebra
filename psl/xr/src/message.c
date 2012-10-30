
/*
   Module to produce popup shells with queries in them.
   Used for such things as `declare SDKJGH operator?'
   messages.  Includes buttons for yes and no, which send
   (respectively) "Y\n" and "N\n" to Reduce.
*/


#include "xreduce.h"
#include "main.h"		/* for MeToReduce, mainly   */
#include "widgets.h"		/* for maxWidth             */
#include "file.h"		/* for writeToLogFile       */


void          (* gotMessageHook)() = NULL;
Boolean          sendAnswersToReduce;
Boolean          messageAnswer;
static Widget    question;
static Widget    messageBox;
static Widget    messageLabel;
static Widget    yesButton;
static Widget    noButton;
static Widget    referenceWidget;
static int       opx;
static int       opy;
static char    * text;
static int       textLength;



void RestorePointer()
{
  Window    discard1;
  Window    discard2;
  unsigned  keys;
  int       npx;
  int       npy;
  int       owx;
  int       owy;

  if (opx >= 0 && opy >= 0) {

    if (XQueryPointer(XtDisplay(referenceWidget),
	              RootWindowOfScreen(XtScreen(referenceWidget)),
		      &discard1, &discard2,
		      &npx, &npy,
		      &owx, &owy, &keys))

      XWarpPointer(XtDisplay(referenceWidget),
		   RootWindowOfScreen(XtScreen(referenceWidget)),
		   RootWindowOfScreen(XtScreen(referenceWidget)), npx, npy,
		   DisplayWidth (XtDisplay(referenceWidget),
				 DefaultScreen(XtDisplay(referenceWidget))),
		   DisplayHeight(XtDisplay(referenceWidget),
				 DefaultScreen(XtDisplay(referenceWidget))),
                   opx, opy);

    opx = opy = -1;
  }
}


/*ARGSUSED*/
void YesButton(w, popup, call_data)
  Widget w;
  Widget popup;
  caddr_t call_data;
{
  char yesyesyes[3];
  XtSetSensitive(yesButton, False);

  if (sendAnswersToReduce) {

    yesyesyes[0] = 'Y';
    yesyesyes[1] = '\n';
    yesyesyes[2] = 0x0;
 
    write (MeToReduce[1], yesyesyes, 2);
    if (app_data.logToFile) WriteToLogFile(yesyesyes, 2);

  } else {

    messageAnswer       = True;
    sendAnswersToReduce = True;
  }

  XtPopdown(question);
  XtSetSensitive(yesButton, True);
  XtUnrealizeWidget(question);
  XtSetKeyboardFocus(referenceWidget, referenceWidget);

  if (app_data.pointerJump) RestorePointer();

  if (gotMessageHook != NULL) {

    gotMessageHook();
    gotMessageHook = NULL;
  }
}


/*ARGSUSED*/
void MessageYesAction(w, a, b, c)
  Widget  w;
  XEvent *a;
  caddr_t b;
  caddr_t c;
{
  YesButton(w, NULL, NULL);
}



/*ARGSUSED*/
void NoButton(w, popup, call_data)
  Widget w;
  Widget popup;
  caddr_t call_data;
{
  char nonono[3];
  XtSetSensitive(noButton, False);

  if (sendAnswersToReduce) {

    nonono[0] = 'N';
    nonono[1] = '\n';
    nonono[2] = 0x0;

    write (MeToReduce[1], nonono, 2);
    if (app_data.logToFile) WriteToLogFile(nonono, 2);

  } else {

    messageAnswer       = False;
    sendAnswersToReduce = True;
  }

  XtPopdown(question);
  XtSetSensitive(noButton, True);
  XtUnrealizeWidget(question);
  XtSetKeyboardFocus(referenceWidget, referenceWidget);

  if (app_data.pointerJump) RestorePointer();

  if (gotMessageHook != NULL) {

    gotMessageHook();
    gotMessageHook = NULL;
  }
}



/*ARGSUSED*/
void MessageNoAction(w, a, b, c)
  Widget  w;
  XEvent *a;
  caddr_t b;
  caddr_t c;
{
  NoButton(w, NULL, NULL);
}


void MessageInterruptAction(w, a, b, c)
  Widget  w;
  XEvent *a;
  caddr_t b;
  caddr_t c;
{
  XtPopdown(question);
  XtUnrealizeWidget(question);
  XtSetKeyboardFocus(referenceWidget, referenceWidget);
  if (app_data.pointerJump) RestorePointer();
  gotMessageHook = NULL;
  IntButton(w, 1, 0);
}


void PlaceSomeMessage(parent, desc, wrtFlag, priorityFlag, deft)
  Widget  parent;
  char   *desc;
  Boolean wrtFlag;
  Boolean priorityFlag;
  Boolean deft;
{
  Arg       arg[5];
  int       i;
  Dimension w;
  Dimension h1;
  Dimension h2;
  Dimension w1;
  Dimension w2;
  Dimension width;
  Dimension height;
  Dimension dw;
  Dimension dh;
  Position  x;
  Position  y;
  Widget    defaultButton;
  Window    discard1;
  Window    discard2;
  unsigned  keys;
  int       px;
  int       py;
  int       owx;
  int       owy;
  int       descLength;
  char    * tempString1;
  char    * tempString2;

  referenceWidget = parent;

  if (priorityFlag) {

    tempString1 = text;
    text        = desc;

  } else {
  
    tempString1 = (char *)XtMalloc(textLength +
				   (descLength = strlen(desc)) + 1);

    strncpy(tempString1, text, textLength);
    strncpy(tempString1 + textLength, desc, descLength);
    tempString1[textLength + descLength] = 0x0;
    tempString2 = text;
    text        = tempString1;
    if (tempString2 != NULL) XtFree(tempString2);
    textLength  = textLength + descLength;
  }

  if (wrtFlag == True) {

    XtUnmanageChild(messageLabel);
    XtUnmanageChild(yesButton);
    XtUnmanageChild(noButton);

    i = 0; XtSetArg( arg[i], XtNlabel,   text   ); i++;
    XtSetValues(messageLabel,    arg, i);

    defaultButton = deft ? yesButton : noButton;

    i = 0; XtSetArg( arg[i], XtNheight, &height ); i++;
           XtSetArg( arg[i], XtNwidth,  &width  ); i++;
    XtGetValues(parent, arg, i);

    i = 0; XtSetArg( arg[i], XtNheight, &h1     ); i++;
    XtGetValues(messageLabel,    arg, i);
    i = 0; XtSetArg( arg[i], XtNheight, &h2     ); i++;
    XtGetValues(yesButton,       arg, i);
    i = 0; XtSetArg( arg[i], XtNwidth,  &w1     ); i++;
    XtGetValues(noButton,        arg, i);
    i = 0; XtSetArg( arg[i], XtNwidth,  &w2     ); i++;
    XtGetValues(yesButton,       arg, i);
    i = 0; XtSetArg( arg[i], XtNwidth,  &w      ); i++;
    XtGetValues(messageLabel,    arg, i);

    if ((w1 + w2) > w)
      w = w1 + w2 + 6;
    w   = w  + 10;
    h1  = h1 + 16;

    XRedTranslateCoords(parent,
			(Position) (width  / 2 - w / 2),
			(Position) (height / 2 - (h1+h2) / 2),
			&x, &y, w, h1+h2);

    i = 0; XtSetArg( arg[i], XtNx, x); i++;
           XtSetArg( arg[i], XtNy, y); i++;
    XtSetValues(question,         arg, i);

    XtRealizeWidget(question);

    i = 0; XtSetArg( arg[i], XtNwidth,  w     ); i++;
           XtSetArg( arg[i], XtNheight, h1+h2 ); i++;
    XtSetValues(messageBox, arg, i);
    XtSetValues(question, arg, i);

    XtManageChild(messageLabel);
    XtManageChild(yesButton);
    XtManageChild(noButton);

    XtPopup(question, XtGrabNonexclusive);

    XtOverrideTranslations(messageBox,
      XtParseTranslationTable(          " <Key>y: message-yes() \n\
        <Key>Escape: message-no() \n      <Key>n: message-no()  \n\
                                      Ctrl<Key>C: message-interrupt()"));

    XtOverrideTranslations(yesButton,
      XtParseTranslationTable(          " <Key>y: message-yes() \n\
        <Key>Return: message-yes() \n     <Key>n: message-no()  \n\
        <Key>Escape: message-no()  \n Ctrl<Key>C: message-interrupt()"));

    XtOverrideTranslations(noButton,
      XtParseTranslationTable(         " <Key>y: message-yes() \n\
        <Key>Return: message-no() \n     <Key>n: message-no()  \n\
        <Key>Escape: message-no() \n Ctrl<Key>C: message-interrupt()"));

    XtSetKeyboardFocus(referenceWidget, messageBox);

    opx = opy = -1;

    if (app_data.pointerJump) {

      i = 0; XtSetArg( arg[i], XtNheight, &dh ); i++;
             XtSetArg( arg[i], XtNwidth,  &dw ); i++;
             XtSetArg( arg[i], XtNx,       &x ); i++;
             XtSetArg( arg[i], XtNy,       &y ); i++;
      XtGetValues(defaultButton, arg, i);

      if (XTranslateCoordinates(XtDisplay(parent),
				XtWindow(messageBox),
				RootWindowOfScreen(XtScreen(parent)),
				x + dw / 2,
				y + dh / 2 + app_data.kludgeTitleHeight,
				&px, &py, &discard1) &&

	  XQueryPointer(XtDisplay(parent),
	                RootWindowOfScreen(XtScreen(parent)),
		        &discard1, &discard2,
		        &opx, &opy,
		        &owx, &owy, &keys))

        XWarpPointer(XtDisplay(parent),
		     RootWindowOfScreen(XtScreen(parent)),
		     RootWindowOfScreen(XtScreen(parent)), opx, opy,
		     DisplayWidth (XtDisplay(parent),
				   DefaultScreen(XtDisplay(parent))),
		     DisplayHeight(XtDisplay(parent),
				   DefaultScreen(XtDisplay(parent))), px, py);
    }

    if (priorityFlag) {

      text = tempString1;

    } else {

      if (text != NULL) {
	XtFree(text);
	text = NULL;
      }
      textLength = 0;
    }
  }
}



void setupMessages(topLevel)
  Widget topLevel;
{
  Arg arg[5];
  int i;

  i = 0; XtSetArg(arg[i], XtNfont, buttonFont); i++;

  question     = XtCreatePopupShell("question",
				    transientShellWidgetClass,
				    topLevel,
				    NULL, 0);

  messageBox   = XtCreateManagedWidget("messageBox",
				       boxWidgetClass,
				       question,
				       NULL, 0);

  messageLabel = XtCreateManagedWidget("messageLabel",
				       labelWidgetClass,
				       messageBox,
				       arg, i);

  yesButton    = XtCreateManagedWidget("yesButton",
				       commandWidgetClass,
				       messageBox,
				       arg, i);

  noButton     = XtCreateManagedWidget("noButton",
				       commandWidgetClass,
				       messageBox,
				       arg, i);

  XtAddCallback( yesButton, XtNcallback, YesButton, messageBox);
  XtAddCallback(  noButton, XtNcallback,  NoButton, messageBox);

  sendAnswersToReduce = True;
  referenceWidget     = topLevel;
  textLength          = 0;
  text                = NULL;
}

