
/*
   Widget tree creation and callback module.
*/

#include "xreduce.h"		 /* Includes all X stuff plus xredres.h   */
#include "main.h"		 /* Various odds and ends                 */
#include "input.h"		 /* Needed to provide action for text wid */
#include "output.h"		 /* And this for XtAppAddInput routine    */
#include "option.h"		 /* Good question; I'll think about it    */
#include "font.h"		 /* For font loading fn and cleaning up   */
#include "message.h"             /* For message button action functions   */
#include "help.h"
#include "manager.h"
#include "file.h"

Widget        inputPane;
Widget        inputHistory;	 /* To allow appending of commands &c.    */
Widget        outputHistory;     /* In order to allow quick new children  */
Widget        outputPane;        /* To reposition viewport easily         */
static Widget buttonBox;
static Widget quitButton;
static Widget intButton;
static Widget nhelpButton;
static Widget infoLabel;
/* static Widget helpButton; */
Dimension     maxWidth;	         /* Standard width of verbal widgets      */
Dimension     verbalHeight;      /* Height of one line of verbal text     */
XFontStruct * verbalFont;        /* Font to be used for all verbal output */
XFontStruct * buttonFont;	 /* Font to be used for option buttons    */
XFontStruct * inputPaneFont;	 /* Font for the active input pane widget */
XFontStruct * inputHistoryFont;	 /* Font for the input history widget     */

static Cursor  skullCursor;	 /* For the Quit button                   */
static void  (*presig)();
static Boolean intDisabled = False;


/* Attempt to ensure that labels are always big enough to contain their */
/* contents completely.  I bet you any money it doesn't work.           */

void XRedSizeLabelForLabel(w,wdP,htP)
  Widget       w;
  Dimension   *wdP;	        /* returns width,  may be NULL */
  Dimension   *htP;		/* returns height, may be NULL */
{
  int          i;
  Dimension    hgp;
  Dimension    wgp;
  int          dir;
  int          asc;
  int          dsc;
  Arg          arg[4];
  char        *text;
  XFontStruct *font;
  XCharStruct  info;

  XtSetArg(arg[0], XtNinternalWidth,  &wgp);
  XtSetArg(arg[1], XtNinternalHeight, &hgp);
  XtSetArg(arg[2], XtNlabel,         &text);
  XtSetArg(arg[3], XtNfont,          &font);
  XtGetValues(w, arg, 4);

  if (text && *text) {

    for (i = 0; text[i] && isspace(text[i]); ++i);

    if (text[i]) {

      XTextExtents(font, text, strlen(text), &dir, &asc, &dsc, &info);

      XtSetArg(arg[0], XtNwidth,  info.width + 2*wgp);
      XtSetArg(arg[1], XtNheight, asc + dsc  + 2*hgp);
      XtSetValues(w, arg, 2);

      if (wdP) *wdP = (Dimension)(info.width + 2*wgp);
      if (htP) *htP = (Dimension)(asc + dsc  + 2*hgp);

      return;
    }
  }

  if (wdP) {

    XtSetArg(arg[0], XtNwidth, &wgp);
    XtGetValues(w, arg, 1);
    *wdP = (Dimension)wgp;
  }

  if (htP) {

    XtSetArg(arg[0], XtNheight, &hgp);
    XtGetValues(w, arg, 1);
    *htP = (Dimension)hgp;
  }

  return;
}


/* Function to behave similarly to XtTranslateCoords, only it's given the  */
/* size of the window being placed at the time and ensures that the window */
/* will fit on the screen                                                  */

void XRedTranslateCoords(w, x, y, rxr, ryr, wd, ht)
  Widget    w;
  Position  x, y;
  Position *rxr, *ryr;
  Dimension wd, ht;
{
  Position rxxr, ryyr;
  Dimension swd, sht;

  XtTranslateCoords(w, x, y, &rxxr, &ryyr);

  swd = DisplayWidth(  XtDisplay(w), DefaultScreen(XtDisplay(w)) );
  sht = DisplayHeight( XtDisplay(w), DefaultScreen(XtDisplay(w)) );

  if (rxxr + wd > swd) rxxr = swd - wd;
  if (ryyr + ht > sht) ryyr = sht - ht;
  if (rxxr < 0) rxxr = 0;
  if (ryyr < 0) ryyr = 0;

  if (rxr) *rxr = rxxr;
  if (ryr) *ryr = ryyr;
}


void SetOutputToBottom()
{

#ifdef HAVE_VIEWPORT_SET_FUNCTIONS

  Arg       arg;
  Dimension vh;
  Dimension bh;

  XtSetArg(arg, XtNheight,   &vh);
  XtGetValues(outputPane,    &arg, 1);
  XtSetArg(arg, XtNheight,   &bh);
  XtGetValues(outputHistory, &arg, 1);

  XawViewportSetCoordinates(outputPane, 0,
			    (bh > vh) ? (bh - vh) : 0);
  printf("SetOutputToBottom HAVE_VIEWPORT_SET_FUNCTIONS\n");
#else

  Arg       arg;
  Dimension vh;
  Dimension bh;
  Position  y;

  XtSetArg(arg, XtNheight,   &vh);
  XtGetValues(outputPane,    &arg, 1);
  XtSetArg(arg, XtNheight,   &bh);
  XtGetValues(outputHistory, &arg, 1);

  y = (bh > vh) ? (bh - vh) : 0;

  printf("SetOutputToBottom not HAVE_VIEWPORT_SET_FUNCTIONS %d %d\n",
  y,XtMoveWidget(outputHistory, 0, (Position) (- y)));

#endif
}


void SetButtonFonts(fontStructp)
  XFontStruct *fontStructp;
{
  Arg arg;

  XtSetArg(arg, XtNfont, fontStructp);
  XtSetValues(   quitButton, &arg, 1);
  XtSetValues(    intButton, &arg, 1);
/*  XtSetValues(   helpButton, &arg, 1); */
  XtSetValues(    infoLabel, &arg, 1);
  XtSetValues(  nhelpButton, &arg, 1);
  XRedSizeLabelForLabel( quitButton, NULL, NULL );
  XRedSizeLabelForLabel(  intButton, NULL, NULL );
/*  XRedSizeLabelForLabel( helpButton, NULL, NULL ); */
  XRedSizeLabelForLabel( infoLabel , NULL, NULL );
  XRedSizeLabelForLabel(nhelpButton, NULL, NULL );

}


void QuitButtonAux()
{
  if (messageAnswer) {

    if (app_data.logToFile) CloseLogFile();
    if (fontSelectorActive) FontDoneButtonAction(NULL,0);
    HelpCloseHelpFile();
    removeSignalHandlers();
    red_kill();
    exit(0);
  }
}


/*ARGSUSED*/
void QuitButton(w,client_data,call_data)
  Widget  w;
  caddr_t client_data,
          call_data;
{
  sendAnswersToReduce = False;
  gotMessageHook      = QuitButtonAux;

  PlaceSomeMessage(buttonBox,
		   "Are you sure you want to quit this Reduce session?",
		   True, True, False);
}


/*ARGSUSED*/
void QuitButtonAction(w,event)
  Widget w;
  XButtonEvent *event;
{
  QuitButton(w,0,0);
}



void IntButtonSub()
{
  Arg    arg;
  Cursor c;

  signal(SIGINT, presig);

  XtSetArg(arg, XtNcursor, &c);
  XtGetValues(inputPane, &arg, 1);

  waitingToInterleave = InterleaveInput();
  GetReduceOutput(0, ReduceToMe, NULL);
}
  

/*ARGSUSED*/
void IntButtonRelease(client_data, id)
  caddr_t      client_data;
  XtIntervalId id;
{
  XtSetSensitive(intButton, True);
  intDisabled = False;
}



/*ARGSUSED*/
void IntButton(w,client_data,call_data)
  Widget w;
  caddr_t client_data,
          call_data;
{
  if (promptPresent >= 1 && !intDisabled) {

    PlaceUrgentItemOnPending(";", "[ Interrupt ] ");
    PlaceItemOnPending("\n",1);

    intDisabled = True;
    XtSetSensitive(intButton, False);
    XtAppAddTimeOut(app_ctxt, 1500, IntButtonRelease, 0);

    presig = signal(SIGINT, IntButtonSub);
    kill(0, SIGINT);
  }
}


/*ARGSUSED*/
void IntButtonAction(w,event)
  Widget w;
  XButtonEvent *event;
{
  IntButton(w,0,0);
}



/*ARGSUSED*/
void HelpButton(w,client_data, call_data)
  Widget w;
  caddr_t client_data,
          call_data;
{
  char *vF;
  char *hF;

  if (!HelpGetHelpFile() ||
      (app_data.reduceHelpFile &&
       strcmp(HelpGetHelpFile(), app_data.reduceHelpFile))) {

    if (app_data.reduceHelpFile && strlen(app_data.reduceHelpFile) > 0 &&
	(hF = EnsureFilename(app_data.reduceHelpFile))) {

      HelpSetHelpFile(hF);
      XtFree(hF);

    } else {

      if (app_data.reduceHelpFile && strlen(app_data.reduceHelpFile) > 0 &&
	  !quietMode) {

	fprintf(stderr,"XR: Can't open help file \"%s\"\n",
		app_data.reduceHelpFile);
	fprintf(stderr,"XR: Using default help file path instead\n");
      }

      /* Nasty rush-job way of implementing a file path */

      if ( (vF = EnsureFilename("$reduce")) &&
	  ((hF = EnsureFilename("$reduce/xr/doc/redhelp.info")) ||
	   (hF = EnsureFilename("$reduce/help/redhelp.info"))   ||
	   (hF = EnsureFilename("$reduce/redhelp.info")))) {

	HelpSetHelpFile(hF);
	XtFree(hF);
      }
    }
  }

  HelpSetTopic(NULL);
  if (!client_data) HelpInstallHelp();
}

/*ARGSUSED*/
void nHelpButton(w,client_data, call_data)
  Widget w;
  caddr_t client_data,
          call_data;
{
newhelpbox(w,client_data, call_data);
}



/*ARGSUSED*/
void nHelpButtonAction(w,event)
  Widget w;
  XButtonEvent *event;
{
  /* nHelpButton(w,0,0);
  */ printf(" NEw help !! Action \n");
}

/*ARGSUSED*/
void HelpButtonAction(w,event)
  Widget w;
  XButtonEvent *event;
{
  HelpButton(w,0,0);
}


/* ARGSUSED */
void HelpContextualAction(w,event)
  Widget w;
  XButtonEvent *event;
{
  HelpButton(w,0,0);
  HelpContextHelpAction(w,event);
}


void SetGenericVerbalSize(font)
  XFontStruct *font;
{
  int         dir;
  int         i;
  int         asc;
  int         desc;
  char       *text;
  Arg         arg;
  Dimension   mw;
  XCharStruct info;

  text = (char *)XtMalloc(1 + app_data.widthInColumns);

  for (i  = 0; i < app_data.widthInColumns; ++i) text[i] = 'W';
  text[i] = 0;

  XTextExtents(font, text, app_data.widthInColumns, &dir, &asc, &desc, &info);

  XtFree(text);
  XtSetArg(arg, XtNwidth, &mw);
  XtGetValues(outputPane, &arg, 1);

  maxWidth     = info.width + 20;
  verbalHeight = asc + desc;

  if (mw > maxWidth) maxWidth = mw;
}



void createWidgets(topLevel)
  Widget topLevel;
{
  Widget wholeThing,
         outerBox,
         titleBar,
         infoBox;            /* Also lots of others, declared globally */

  Arg   arg[10];
  int   i;

  static XtActionsRec xreduceActions[] = {
    {"process-input",          ProcessInput},
    {"copy-down",              CopyDown},
    {"bracket-match",          BracketMatch},
    {"bracket-demo",           BracketDemonstrateMatch},
    {"bracket-complete",       BracketComplete},
    {"handle-up-arrow",        HandleUpArrow},
    {"handle-down-arrow",      HandleDownArrow},
    {"reduce-quit",            QuitButtonAction},
    {"reduce-interrupt",       IntButtonAction},
/*    {"reduce-help",            HelpButtonAction},
*/
    {"reduce-font-done",       FontDoneButtonAction},
    {"reduce-help-done",       HelpDoneButtonAction},
    {"reduce-help-contextual", HelpContextualAction},
    {"reduce-option-done",     OptOkButtonAction},
    {"reduce-option-done",     OptOkButtonAction},
    {"reduce-nhelpion-done",   OptOkButtonAction},
    {"reduce-file-done",       FileOkButtonAction},
    {"step-button",            StepButtonAction},
    {"message-yes",            MessageYesAction},
    {"message-no",             MessageNoAction},
    {"message-interrupt",      MessageInterruptAction},
  };

  outerBox      = XtCreateManagedWidget("outerBox",
					formWidgetClass,
					topLevel,
					NULL, 0);

  wholeThing    = XtCreateManagedWidget("wholeThing",
					panedWidgetClass,
					outerBox,
					NULL, 0);

  titleBar      = XtCreateManagedWidget("titleBar",
					boxWidgetClass,
					wholeThing,
					NULL, 0);

  buttonBox     = XtCreateManagedWidget("buttonBox",
					formWidgetClass,
					titleBar,
					NULL, 0);
  
  quitButton    = XtCreateManagedWidget("quitButton",
					commandWidgetClass,
					buttonBox,
					NULL, 0);
  
  intButton     = XtCreateManagedWidget("intButton",
					commandWidgetClass,
					buttonBox,
					NULL, 0);

  infoBox       = XtCreateWidget("infoBox",
					formWidgetClass,
					titleBar,
					NULL, 0);
    
  infoLabel     = XtCreateManagedWidget("infoLabel",
					labelWidgetClass,
					infoBox,
					NULL, 0);

/*  helpButton    = XtCreateManagedWidget("helpButton",
					commandWidgetClass,
					buttonBox,
					NULL, 0);
*/

  nhelpButton   = XtCreateManagedWidget("nhelpButton",
                                        commandWidgetClass,
                                        buttonBox,
                                        NULL, 0);

  outputPane    = XtCreateManagedWidget("outputPane",
					viewportWidgetClass,
					wholeThing,
					NULL, 0);

  outputHistory = XtCreateManagedWidget("outputHistory",
					formWidgetClass,
					outputPane,
					NULL, 0);

  inputHistory  = XtCreateManagedWidget("inputHistory",
					asciiTextWidgetClass,
					wholeThing,
					NULL, 0);

  inputPane     = XtCreateManagedWidget("inputPane",
					asciiTextWidgetClass,
					wholeThing,
					NULL, 0);

  XtOverrideTranslations
    (inputPane, XtParseTranslationTable
     ("<Key>Return:	end-of-line() newline() process-input() step-button()\
    \n Shift<Key>):	insert-char() bracket-match() \n\
       Shift<Key>}:	insert-char() bracket-match() \n\
       Shift<Key>>:	insert-char() bracket-match() \n\
       <Key>d:		insert-char() bracket-match() \n\
       <Key>]:		insert-char() bracket-match() \n\
       Ctrl<Key>Tab:	bracket-complete()            \n\
       <Key>Up:		handle-up-arrow()    previous-line() bracket-demo() \n\
       <Key>Down:	handle-down-arrow()  next-line()     bracket-demo() \n\
       <Key>Right:	forward-character()  bracket-demo()        \n\
       <Key>Left:	backward-character() bracket-demo()        \n\
       <Key>F10:	reduce-help-contextual()                   \n\
       Ctrl<Key>F:	forward-character()  bracket-demo()        \n\
       Ctrl<Key>B:	backward-character() bracket-demo()        \n\
       Ctrl<Key>E:	end-of-line()        bracket-demo()        \n\
       Ctrl<Key>N:	next-line()          bracket-demo()        \n\
       Ctrl<Key>P:	previous-line()      bracket-demo()        \n\
       Ctrl<Key>U:	beginning-of-line()  kill-to-end-of-line() \n\
       Ctrl<Key>C:	reduce-interrupt()                         \n\
       Meta<Key>F:	forward-word()       bracket-demo()        \n\
       Meta<Key>B:	backward-word()      bracket-demo()        \n\
       <Btn1Down>:	step-button()        select-start()"));
  
  if ((app_data.reduceHistoryMax < REDUCE_HISTORY_MIN_MAX) ||
      (app_data.reduceHistoryMax > REDUCE_HISTORY_MAX_MAX)) {
    red_warn("Error in resource specifications:");
    fprintf(stderr, "reduceHistoryMax is %d; should be between %d and %d\n",
	    app_data.reduceHistoryMax,
	    REDUCE_HISTORY_MIN_MAX,
	    REDUCE_HISTORY_MAX_MAX);
    exit(1);
  }
  if ((app_data.reduceHistoryExcess < REDUCE_HISTORY_MIN_EXCESS) ||
      (app_data.reduceHistoryExcess > REDUCE_HISTORY_MAX_EXCESS)) {
    red_warn("Error in resource specifications:");
    fprintf(stderr, "reduceHistoryExcess is %d; should be between %d and %d\n",
	    app_data.reduceHistoryExcess,
	    REDUCE_HISTORY_MIN_EXCESS,
	    REDUCE_HISTORY_MAX_EXCESS);
    exit(1);
  }
  if (app_data.widthInColumns     < 0) {
    red_warn("Error in resource specifications:");
    fprintf(stderr, "widthInColumns must be non-negative\n");
    exit(1);
  }

  verbalFont       = FontLoadQueryFont(topLevel, app_data.outputTextFont);
  buttonFont       = FontLoadQueryFont(topLevel, app_data.optionButtonFont);
  inputPaneFont    = FontLoadQueryFont(topLevel, app_data.inputPaneFont);
  inputHistoryFont = FontLoadQueryFont(topLevel, app_data.inputHistoryFont);

  createOptionMenu(topLevel,buttonBox);
  createFileMenu(topLevel,buttonBox);
  createnhelpionMenu(topLevel,buttonBox);
  SetGenericVerbalSize(verbalFont);

  skullCursor = XCreateFontCursor(XtDisplay(topLevel),XC_pirate);
  i = 0; XtSetArg(arg[i], XtNcursor,      skullCursor); i++;
  XtSetValues(quitButton,    arg, i);

  i = 0; XtSetArg(arg[i], XtNpreferredPaneSize,    40); i++;
         XtSetArg(arg[i], XtNresizeToPreferred,  True); i++;
         XtSetArg(arg[i], XtNshowGrip,          False); i++;
         XtSetArg(arg[i], XtNskipAdjust,         True); i++;
         XtSetArg(arg[i], XtNheight,               35); i++;

  XtSetValues(titleBar,      arg, i);

  i = 0; XtSetArg(arg[i], XtNheight,
		           app_data.historyPaneHeight); i++;
         XtSetArg(arg[i], XtNpreferredPaneSize,
		           app_data.historyPaneHeight); i++;
         XtSetArg(arg[i], XtNresizeToPreferred,  True); i++;

  XtSetValues(outputPane,    arg, i);

  i = 0; XtSetArg(arg[i], XtNeditType,    XawtextRead); i++;
         XtSetArg(arg[i], XtNdataCompression,   False); i++;
         XtSetArg(arg[i], XtNscrollVertical,
		                  XawtextScrollAlways); i++;
         XtSetArg(arg[i], XtNstring,               ""); i++;
         XtSetArg(arg[i], XtNheight,
		             app_data.inputPaneHeight); i++;
         XtSetArg(arg[i], XtNpreferredPaneSize,
		             app_data.inputPaneHeight); i++;
         XtSetArg(arg[i], XtNresizeToPreferred,  True); i++;
         XtSetArg(arg[i], XtNfont,   inputHistoryFont); i++;

  XtSetValues(inputHistory,  arg, i);

  i = 0; XtSetArg(arg[i], XtNeditType,    XawtextEdit); i++;
         XtSetArg(arg[i], XtNdataCompression,   False); i++;
         XtSetArg(arg[i], XtNscrollVertical,
		                  XawtextScrollAlways); i++;
         XtSetArg(arg[i], XtNstring,               ""); i++;
         XtSetArg(arg[i], XtNfont,      inputPaneFont); i++;

  XtSetValues(inputPane,     arg, i);

  i = 0; XtSetArg(arg[i], XtNfont,         buttonFont); i++;
  XtSetValues(quitButton,    arg, i);
  XtSetValues(intButton,     arg, i);
  XtSetValues(infoLabel,     arg, i);
/*  XtSetValues(helpButton,    arg, i); */
  XtSetValues(nhelpButton,   arg, i);


  installManager(titleBar);
  
  XtAddCallback( quitButton, XtNcallback, QuitButton,   0 );
  XtAddCallback(  intButton, XtNcallback,  IntButton,   0 );
 /* XtAddCallback( helpButton, XtNcallback, HelpButton,   0 ); */
  XtAddCallback(nhelpButton, XtNcallback, nHelpButton,  0 );

  XtAddCallback( XawTextGetSource(inputPane),
		             XtNcallback, InputChanged, 0 );

  XtAppAddTimeOut(app_ctxt,
		  app_data.outputOffDelay,
		  HandleReduceOutputStream, 0);

  XtAppAddInput(app_ctxt, ReduceErrs[0], (XtPointer)XtInputReadMask,
		HandleReduceErrorStream, 0);

  XtAppAddActions(app_ctxt,
		  xreduceActions,
		  XtNumber(xreduceActions));

  XtSetKeyboardFocus(outputPane, inputPane);
}
