
/*
   Verbal output widget module.

   Chris Cannam, 1992 - 1993.
*/


#include "xreduce.h"
#include "main.h"
#include "widgets.h"
#include "xredplus.h"
#include "manager.h"
#include "help.h"		/* For the verbatim font */

static Widget *toGoList;
static int     toGoIndx; 
Boolean        verbalVerbatim = False;



/*
   CreateNewVerbal():

   Returns a pointer to a new empty verbal widget structure (not just
   the widget) whose name is derived from the current history number.
*/

HistList *CreateNewVerbal()
{
  Arg       arg[12];
  int       i;
  HistList *verbal;

  verbal             = (HistList *)XtMalloc(sizeof(HistList));
  verbal->next       = NULL;
  verbal->nLines     = 0;
  verbal->histNo     = reduceHistoryNumber;
  verbal->flavour    = ReduceVerbal;
  verbal->height     = verbalHeight;
  verbal->managed    = InitiallyManaged();
  verbal->usedOnLine = 0;	/* usedOnLine holds the number of chars */
  verbal->textLength = 0;

  i = 0; XtSetArg(arg[i], XtNstring,          "");               i++;
         XtSetArg(arg[i], XtNwidth,           maxWidth);         i++;
         XtSetArg(arg[i], XtNborderWidth,     0);                i++;
         XtSetArg(arg[i], XtNdisplayCaret,    False);            i++;
         XtSetArg(arg[i], XtNtopMargin,       0);                i++;
         XtSetArg(arg[i], XtNbottomMargin,    0);                i++;
         XtSetArg(arg[i], XtNresizable,       True);             i++;
         XtSetArg(arg[i], XtNheight,          verbalHeight);     i++;
         XtSetArg(arg[i], XtNwrap,            XawtextWrapNever); i++;
  if (verbalVerbatim) {
         XtSetArg(arg[i], XtNfont,            helpXmplFont);     i++;
       } else {
         XtSetArg(arg[i], XtNfont,            verbalFont);       i++;
       }
  if (endOfHistory) {
         XtSetArg(arg[i], XtNfromVert,    endOfHistory->widget); i++;
       }

  verbal->widget = CreateWidget("historyVerbal",
				asciiTextWidgetClass,
				outputHistory,
				arg, (Cardinal)i);
  return verbal;
}



HistList *FlushAndStartNewVerbal(verbal)
  HistList *verbal;
{
  ManageSomeHistList();

  verbal->next   = CreateNewVerbal();
  if (endOfHistory == verbal)
    endOfHistory = verbal->next;
  verbal         = verbal->next; 
  placedHeight   = 0;

  return verbal;
}



/* Switch on or off verbatim mode (which just uses the helpXmplFont for */
/* all output, and is used when graphics are switched off).             */

void VerbalVerbatim(flg)
  Boolean flg;
{
  Arg arg;

  verbalVerbatim = flg;
  SetGenericVerbalSize(flg ? helpXmplFont : verbalFont);

  if (endOfHistory && endOfHistory->flavour == ReduceVerbal)
    if (flg) {

      XtSetArg(arg, XtNfont, helpXmplFont);
      XtSetValues(endOfHistory->widget, &arg, 1);

    } else {

      FlushAndStartNewVerbal(endOfHistory);
    }
}



void AddTextToVerbal(verbal,text,forceFlag)
  HistList *verbal;
  char     *text;
  Boolean   forceFlag;
{
  Arg            arg[4];
  int            i;
  int            nLines;
  int            maxLines;
  int            sinceNL;
  int            newlen;
  int            oldPoint;
  char         * oldText;
  char         * newText;
  char         * copyTo;
  XawTextBlock * toAppend;

  oldPoint   = verbal->textLength;
  newlen     = strlen(text);
  if (newlen == 0) return;
  newText    = (char *)XtMalloc(newlen + 2 + newlen/(app_data.widthInColumns));
  copyTo     = newText;
  oldText    = text;
  sinceNL    = verbal->usedOnLine;
  nLines     = oldPoint ? 0 : 1;

  if (app_data.pageMode) {

    if (placedHeight >= screenHeight) maxLines = 0;
    else  maxLines = (screenHeight - placedHeight) / verbalHeight - 1;
    if   (maxLines < 1) {
      verbal   = FlushAndStartNewVerbal(verbal);
      maxLines = (screenHeight - placedHeight) / verbalHeight - 1;
      if (maxLines < 1) maxLines = 0;
    }
  }

  while (*text) {
    sinceNL ++;
      
    if (*text == END_OF_LINE) {

      nLines++;
      sinceNL = 0;		    /* Keep track of length in lines  */

    /* If we get more than one line's worth of text between newlines, */
    /* split it and count the extra newline char in newlen            */
    
    } else {

      if (sinceNL > app_data.widthInColumns) {
	*copyTo++ = END_OF_LINE;
	nLines++;
	sinceNL = 1;
	newlen++;
      }
    }

    if (app_data.pageMode && nLines >= maxLines && !forceFlag) {

      XtFree(newText);
      *text++      = 0x0;
      strcpy((newText = (char *)XtMalloc(newlen-(text-oldText)+1)), text);
      AddTextToVerbal(verbal,oldText,True);
      verbal       = FlushAndStartNewVerbal(verbal);
      AddTextToVerbal(verbal,newText,False);
      XtFree(newText);
      return;

    } else *copyTo++ = *text++;
  }

  *copyTo  = 0x0;		         /* Remember the null terminator   */

  newlen = strlen(newText);

  toAppend = (XawTextBlock *)XtMalloc(sizeof(XawTextBlock));
  toAppend->firstPos = 0;
  toAppend->length   = newlen;
  toAppend->ptr      = newText;
  toAppend->format   = FMT8BIT;

  reduceHistoryNumber += nLines;
  verbal->nLines      += nLines;
  verbal->textLength  += newlen;
  verbal->usedOnLine   = sinceNL;
  verbal->height      += nLines * verbalHeight;   /* Also changed elsewhere; */
				                  /* not generally actual ht */

  i = 0; XtSetArg(arg[i], XtNeditType, XawtextAppend); i++;
         XtSetArg(arg[i], XtNheight, verbal->nLines * verbalHeight); i++;
  XtSetValues(verbal->widget, arg, i);

  XawTextReplace(verbal->widget, oldPoint, oldPoint, toAppend);

  XtFree(newText);
  XtFree((char *)toAppend);

  RaisePlacedHeight(nLines * verbalHeight);

  i = 0; XtSetArg(arg[i], XtNeditType, XawtextRead); i++;
  XtSetValues(verbal->widget, arg, i);
  XtResizeWidget(verbal->widget, maxWidth, verbal->nLines * verbalHeight, 0);
}




/*
   ClipAux() and ClipFromHistList():

   Given a pointer to an output widget structure (either verbal or graphical,
   and not just the widget), which of course is really the head of a list of
   such structures, chop it down to size so that the history length is below
   the maximum limit.  If the first widget in the list is textual, its lines
   are stripped one by one from the top, and if all of them go, it is destroyed
   and the next widget is considered; if the first widget is graphical it is
   simply discarded and the next considered.  Continues until it's removed
   enough or it runs out of widgets.  Returns a pointer to the first remaining
   widget structure in the list, or if there were none left, a brand new
   structure.

   Second arg lastHL now gives the history element to be considered at the
   end of the list.  No clipping will go on beyond this, and it is considered
   the element relative to which to compute the history length.  (Previous
   versions always used endOfHistory; this is not necessarily correct in
   page mode.)
*/

HistList *ClipAux(histList, lastHL)
  HistList *histList;
  HistList *lastHL;
{
  int         nLines;        /* The number of history lines to be clipped */
  HistList  * tempHistList;
  int         brutallyMurderable;

  nLines = (lastHL->histNo - histList->histNo) - app_data.reduceHistoryMax;
  if (nLines <= 0) return histList;

  /* First consider verbal widgets, and strip them line by line. */

  if (histList->flavour == ReduceVerbal) {

    if (histList->nLines <= nLines) nLines -= histList->nLines;
    else return histList;

  } else {

    /* Investigate the disposal of Verbal widgets in the rest of the list. */
    /* We shall refuse to remove any graphical widget unless there are at  */
    /* least three verbal widgets after it.  This means that the last two  */
    /* results and prompts should always be visible.                       */

    for  (brutallyMurderable     = 0,
	  tempHistList           = histList;
	  tempHistList          != NULL;
	  tempHistList           = tempHistList->next)
      if (tempHistList->flavour == ReduceVerbal) brutallyMurderable ++;

    if (brutallyMurderable > 2) {

      XFreePixmap(XtDisplay(histList->widget),histList->pMap);

    } else return histList;
  }

  toGoList[toGoIndx++] = histList->widget;

  tempHistList = histList;
  histList     = histList->next;
  
  if (endOfHistory == tempHistList) endOfHistory = histList;
  if (endOfManaged == tempHistList) endOfManaged = histList;

  XtFree((char *)tempHistList);
    
  if (histList == NULL) {
    if (endOfHistory == NULL) {
      endOfHistory = CreateNewVerbal();
      if (endOfManaged == NULL) endOfManaged = endOfHistory;
      return endOfHistory;
    } else if (endOfManaged == NULL) {
      endOfManaged = CreateNewVerbal();
      return endOfManaged;
    } else return CreateNewVerbal();
  }

  /* If there's still need for stripping and there's still some */
  /* widgets to strip, (tail-)recurse down the list             */

  if (nLines > 0) {
    return ClipAux(histList,lastHL);
  } else {
    return histList;
  }
}



HistList *ClipFromHistList(histList, lastHL)
  HistList *histList;
  HistList *lastHL;
{
  Arg       arg;
  HistList *result;

  toGoIndx = 0;
  toGoList = (Widget *)XtMalloc(sizeof(Widget) *
				(20 + app_data.reduceHistoryExcess));

  if (lastHL) result = ClipAux(histList, lastHL);
  else        result = ClipAux(histList, lastHL /* endOfHistory */);

  if (toGoIndx > 0) {
    XtSetArg(arg, XtNfromVert, 0);
    XtSetValues(result->widget, &arg, 1);
    XtUnmanageChildren(toGoList, toGoIndx);
    while (toGoIndx > 0)
      XtDestroyWidget(toGoList[--toGoIndx]);
  }

  XtFree((char *)toGoList);
  return result;
}



/*
   PlaceSomeLines():

   Takes some text, decides what format of widget to use (do I append to a
   previous textual widget? do I create a new textual or graphical one?) and
   puts the text wherever.  Checks for history getting too long, and if it
   is, clips; then sets the viewport to look upon the end of the list.
*/

void PlaceSomeLines(text)
  char *text;
{
  if (endOfHistory->flavour != ReduceVerbal) {

    endOfHistory->next = CreateNewVerbal();
    endOfHistory       = endOfHistory->next;
    AddTextToVerbal(endOfHistory,text,False);

  } else {

    AddTextToVerbal(endOfHistory,text,False);
  }

  ManageSomeHistList();
}

