
/* 
   Module to handle user's input into the XReduce window, and to
   arrange passing of input over to Reduce and, editing of the input
   and the history list, bracket matching and completion, etc.

   Chris Cannam, Berlin 1992-93.
*/

#include "xreduce.h"
#include "main.h"
#include "verbal.h"
#include "widgets.h"
#include "output.h"
#include "file.h"

#define BracketRestoreMatchDelay 50
#define PromptChangedChar        0x4
#define PromptUnchangedChar      0x5
#define PromptInDoubtChar        0x6
#define QuotedDollarChar         0x7
#define QuotedSemicolonChar      0x8

#define  LeftBracketP(y,z) ((((y)[(z)])=='{')||(((y)[(z)])=='[')|| \
			    (((y)[(z)])=='(')||prognP((y),(z),'<')|| \
			    beginP((y),(z)))

#define RightBracketP(y,z) ((((y)[(z)])=='}')||(((y)[(z)])==']')|| \
			    (((y)[(z)])==')')||prognP((y),(z),'>')|| \
			    endP((y),(z)))

#define     PromptCharP(c) (((c) == PromptChangedChar) || \
			    ((c) == PromptInDoubtChar) || \
			    ((c) == PromptUnchangedChar))

#define QuoteTerminator(x) (((x)=='$')? QuotedDollarChar : QuotedSemicolonChar)
#define UnQuoteTerminator(x) (((x)==(QuotedDollarChar))?'$':';')

long int               inputFromChar;
int                    linesInInputHistory;
static char          * tempBuffer = NULL;
static Boolean         inString = False;
static Boolean         bracketHighlighted = False;
static Boolean         bracketRestored    = False;
static XawTextPosition highlitBracket;
static XawTextPosition hBPrevDisplay;
static int             hBLength;
static Widget          hBWidget;
static XawTextPosition lastAdaptedPrompt;
static XtIntervalId    bracketUHTimeout;
static XtIntervalId    bracketMHTimeout;
Boolean                quotedP();
int                    FindMatching();


/*
   A cunning but quite complicated stratagem which attempts to ensure
   that XReduce can keep approximately in sync with Reduce on issues
   like whether or not the parser is reading a string, or a <<...>>
   block, or something, for bracket-matching purposes.  The idea is
   for XReduce to include a marker in its input-history string at each
   point where Reduce should issue a new prompt, ie. after every semi-
   colon or dollar symbol.  Then whenever XReduce encounters a prompt,
   it takes note of whether or not the prompt number has increased
   since the previous one, and calls the function below.  (Checking
   the number is done in output.c.)  This function scans through the
   input history string, changing the markers for mere prompt-existence
   into markers for prompt-changed or prompt-unchanged; then the
   scanner later can assume that each prompt-changed symbol must be
   outside all strings or <<...>> or begin...end pairs.

   If you don't believe that this is correct or that it will work,
   I really don't blame you.  I don't believe it either.
*/

void PlacePromptMarker(changed)
  Boolean changed;
{
  Arg             arg[2];
  int             i;
  char          * buffer;
  char            modifyChar[2];
  XawTextPosition pos;
  XawTextBlock  * change;

  i = 0; XtSetArg(arg[i], XtNstring, &buffer); i++;
  XtGetValues(XawTextGetSource(inputHistory), arg, i);

  for (pos = lastAdaptedPrompt; (buffer[pos] &&
				 buffer[pos] != PromptInDoubtChar); ++pos);

  if (buffer[pos]) {

    i = 0; XtSetArg(arg[i], XtNeditType, XawtextEdit); i++;
    XtSetValues(inputHistory, arg, i);

    modifyChar[0] = changed ? PromptChangedChar : PromptUnchangedChar;
    modifyChar[1] = 0x0;

    change = (XawTextBlock *)XtMalloc(sizeof(XawTextBlock));
    change->firstPos = 0;
    change->length   = 1;
    change->ptr      = modifyChar;
    change->format   = FMT8BIT;

    XawTextReplace(inputHistory, pos, pos+1, change);

    XtFree((char *)change);

    i = 0; XtSetArg(arg[i], XtNeditType, XawtextRead); i++;
    XtSetValues(inputHistory, arg, i);
  }
}


void PlacePartOnPending(text,len,addCR)
  char   *text;
  int     len;
  Boolean addCR;
{
  char *tempText;

  tempText = (char *)XtMalloc(len + 2);

  strncpy(tempText,text,len);
  if (addCR)
    tempText[len ++] = END_OF_LINE;
  tempText[len] = 0x0;

  while (--len >= 0)
    if (tempText[len] ==  QuotedSemicolonChar ||
	tempText[len] ==  QuotedDollarChar)
        tempText[len] = UnQuoteTerminator(tempText[len]);

  if (lastInput       == NULL) {                        /* very first item */
      lastInput = (PendingInputList *)XtMalloc(sizeof(PendingInputList));
      lastInput->next =  NULL;
      pendingInput    =  lastInput;

    } else {

      if (lastInput->text == NULL) {               /* nothing else pending */
	  lastInput->next =  NULL;

	} else {		                     /* something else first */

	  lastInput->next = (PendingInputList *)
	     XtMalloc(sizeof(PendingInputList));
	  lastInput       = lastInput->next;
	  lastInput->next = NULL;
	}
    }
  
  lastInput->text = XtNewString(tempText);
  lastInput->show = True;
  XtFree(tempText);
}



void PlaceItemOnPending(text,len)
  char *text;
  int   len;
{
  int     i, j;

  for (i = 0, j = 0; i < len; i++) {

    switch (text[i]) {

    case ';':
    case '$':
      PlacePartOnPending(text+j, i-j+1, True);
      while (text[i+1] == END_OF_LINE && i < len) i++;
      j = i+1;
      break;
    }
  }

  if (i > j) PlacePartOnPending(text+j, i-j, False);
}



/* Place a string at the _start_ of the pending input list. String is      */
/* assumed not to need any further processing (ie. ends in \n\0, &c.),     */
/* unlike strings in the above two functions, which are reprocessed for    */
/* termination chars, quoted and unquoted, and for carriage returns.       */
/* Second arg is the string which XReduce should display as if it were the */
/* actual string sent; it is never really sent to Reduce.                  */
/* This function duplicates its args.  You may dispose of them afterwards. */

void PlaceUrgentItemOnPending(text,stxt)
  char *text;
  char *stxt;
{
  PendingInputList *tempInput;

  tempInput       = (PendingInputList *)XtMalloc(sizeof(PendingInputList));
  tempInput->text = XtNewString(text);
  tempInput->stxt = XtNewString(stxt);
  tempInput->next = pendingInput;
  tempInput->show = False;
  pendingInput    = tempInput;
  if (lastInput  == tempInput->next) lastInput = tempInput;
}



/*
   InterleaveInput():

   Places something from the Pending Input list into the Reduce output
   window (e.g. after a prompt).  It places one line of input per prompt.

   Returns False if it's managed to place an input line, and True if
   there's still more to go.  (This behaviour is used by GetReduceOutput.)

   This function used to be in verbal.c, which is a very silly place to
   keep it.
*/

/* Assume we're at the prompt. */

Boolean InterleaveInput()
{
  PendingInputList *tempList;
  int               pItLen;

  if (pendingInput       == NULL ||
      pendingInput->text == NULL)   return True;

  pItLen = strlen(pendingInput->text);
  write (MeToReduce[1], pendingInput->text, pItLen);
  if (app_data.logToFile) WriteToLogFile(pendingInput->text, pItLen);

  if (pendingInput->show)
    PlaceSomeLines(pendingInput->text);
  else
    PlaceSomeLines(pendingInput->stxt);

  if (pendingInput->next == NULL) {
    XtFree(pendingInput->text);
    pendingInput->text = NULL;
  } else {
    tempList     = pendingInput;
    pendingInput = pendingInput->next;
    XtFree((char *)tempList);
  }

  DisplayWatchCursor();
  return False;
}



/*ARGSUSED*/
void ProcessInput(w,event)
  Widget w;
  XButtonEvent *event;
{
  Arg            arg[2];
  int            i;
  int            len;
  int            oneLineLen;
  int            totalLen;
  int            prospectiveLinesInInputHistory;
  int            promptCount;
  int            skp;
  int            ix;
  char         * command;
  char         * oc;
  char         * nc;
  char         * buffer;
  XawTextBlock * blanker;
  XawTextBlock * filler;
  Boolean        inStr[1];
  Boolean        top[1];

  i = 0; XtSetArg(arg[i],
		  XtNstring,
		  &buffer); i++;

  XtGetValues(XawTextGetSource(w),arg,i);

  len  = strlen(buffer);
  oc   = command = (char *)XtMalloc(len + 1);
  strcpy(command, buffer);

  while (len > 1 &&
	 command[len - 1] == END_OF_LINE &&
	 command[len - 2] == END_OF_LINE) len --;
  command[len] = 0x0;

  for (ix=skp=0; command[ix]; ++ix)
    if (!isprint(command[ix]) &&
	!isspace(command[ix])) skp ++;
    else command[ix-skp] = command[ix];
  command[len  = ix-skp] = 0x0;

  prospectiveLinesInInputHistory = linesInInputHistory;

  oneLineLen  = 0;
  promptCount = 0;
  totalLen    = 0;
  nc          = oc;
  while (command[oneLineLen] != 0x0) {
    if  (command[oneLineLen] == END_OF_LINE) {
      PlaceItemOnPending(command, oneLineLen + 1);
      command   += oneLineLen + 1;
      oneLineLen = 0;
      totalLen  ++;
      prospectiveLinesInInputHistory ++;
    } else {
      if (command[oneLineLen] == ';' ||
	  command[oneLineLen] == '$') {

	if (!quotedP(command,oneLineLen)) {
	  inStr[0] = True;
	    top[0] = True;
	  inStr[0] = (FindMatching(&oc,top,totalLen,'"',inStr) >= 0);
	        oc = nc;
	  if (!(inStr[0])) promptCount ++;
	  else command[oneLineLen] = QuoteTerminator(command[oneLineLen]);
	} else command[oneLineLen] = QuoteTerminator(command[oneLineLen]);
      }
      oneLineLen ++;
      totalLen   ++;
    }
  }

  nc   = (char *)XtMalloc(len + promptCount + 1);

  for (oneLineLen = 0, promptCount = 0; oc[oneLineLen]; ++oneLineLen) {
    switch(oc[oneLineLen]) {

    case ';':
    case '$':
      nc[oneLineLen +   promptCount] = oc[oneLineLen];
      nc[oneLineLen + ++promptCount] = PromptInDoubtChar;
      break;
    case QuotedSemicolonChar:
    case QuotedDollarChar:
      nc[oneLineLen +   promptCount] = UnQuoteTerminator(oc[oneLineLen]);
      break;
    default:
      nc[oneLineLen +   promptCount] = oc[oneLineLen];
    }
  }
  nc[oneLineLen + promptCount] = 0x0;
  len += promptCount;

  blanker = (XawTextBlock *)XtMalloc(sizeof(XawTextBlock));
  blanker->firstPos = 0;
  blanker->length   = 0;
  blanker->ptr      = XtNewString("");
  blanker->format   = FMT8BIT;

  if (!(len == 1 && oc[0] == END_OF_LINE)) {

    XtGetValues(XawTextGetSource(inputHistory),arg,i);
    totalLen = strlen(buffer);
    if (totalLen == 0) lastAdaptedPrompt = 0;

    filler  = (XawTextBlock *)XtMalloc(sizeof(XawTextBlock));
    filler->firstPos  = 0;
    filler->length    = len;
    filler->ptr       = nc;
    filler->format    = FMT8BIT;

    i = 0; XtSetArg(arg[i], XtNeditType, XawtextAppend); i++;
    XtSetValues(inputHistory, arg, i);

    XawTextReplace(inputHistory, totalLen, totalLen, filler);
    XawTextReplace(w, 0, len, blanker);
    XtFree(blanker->ptr);
    XtFree((char *)blanker);
    XtFree((char *)filler);
    XtFree(oc);
    XtFree(nc);

    XawTextSetInsertionPoint(inputHistory, totalLen + len);

    i = 0; XtSetArg(arg[i], XtNeditType, XawtextRead); i++;
    XtSetValues(inputHistory, arg, i);
    linesInInputHistory = prospectiveLinesInInputHistory;

  } else {

    XawTextReplace(w, 0, len, blanker);
    XtFree(blanker->ptr);
    XtFree((char *)blanker);
    XtFree(oc);
  }

  inputFromChar = -1L;
  if (waitingToInterleave) GetReduceOutput(0, ReduceToMe, NULL);
}



/*ARGSUSED*/
void CopyDown(w,event)
  Widget w;
  XButtonEvent *event;
{
  Arg            arg[2];
  int            i;
  int            len = 0;
  int            sLen;
  int            maxLen;
  int            paneLen;
  int            offset;
  int            ooff;
  char         * paneBuf;
  char         * buffer;
  char         * newBuf;
  XawTextBlock * filler;

  i = 0; XtSetArg(arg[i], XtNstring, &buffer); i++;
  XtGetValues(XawTextGetSource(w),arg,i);

  maxLen = strlen(buffer);
  offset = ooff = XawTextGetInsertionPoint(w);

  while (offset > 0 &&
	 buffer[offset-1] != END_OF_LINE) offset --;
  while (buffer[offset]   == END_OF_LINE) offset ++;
  while ((offset + len) < maxLen &&
	 buffer[offset + len] != END_OF_LINE) len ++;

  if ((offset + len) < maxLen) len ++;

  newBuf = (char *)XtMalloc(len + 1);
  for (i = sLen = 0; sLen < len && (buffer[offset+sLen]); ++sLen) 
    if (isprint(buffer[offset+sLen]) || isspace(buffer[offset+sLen])) {
      newBuf[sLen-i] = buffer[offset+sLen];
    } else i++;
  len = sLen - i;
  newBuf[len] = 0x0;

  filler = (XawTextBlock *)XtMalloc(sizeof(XawTextBlock));
  filler->firstPos = 0;
  filler->length   = len;
  filler->ptr      = newBuf;
  filler->format   = FMT8BIT;

  i = 0; XtSetArg(arg[i], XtNstring, &paneBuf); i++;
  XtGetValues(XawTextGetSource(inputPane),arg,i);

  paneLen = strlen(paneBuf);
  XawTextReplace(inputPane, paneLen, paneLen, filler);

  ooff = ooff + sLen;
  if (ooff <= maxLen)
    XawTextSetInsertionPoint(w, ooff);

  XawTextSetInsertionPoint(inputPane, paneLen + len);

  XtFree(newBuf);
  XtFree((char *)filler);
}



/*
   Test whether the character "buf[pos]" is quoted (by '!').
*/

Boolean quotedP(buf, pos)
  char *buf;
  int   pos;
{
  return ((pos > 0) && (buf[pos-1] == '!') && !quotedP(buf,pos-1));
}



/*
   Test whether the char "buf[pos]" is a valid first-char-of-opening-
   Reduce-progn-brace-'<', or valid second-char-of-closing-Reduce-
   progn-brace-'>'.  Considers whether it's quoted, but not whether
   it's in a string.
*/

Boolean prognP(buf, pos, c)
  char *buf;
  int   pos;
  char  c;
{
  int     i, d;
  Boolean s = False;

  if (((c == '<') || (c == '>')) && (c == buf[pos]) && !quotedP(buf,pos)) {
    for (i = pos + (d = ((c == '>') ? -1 : 1));
	 i >= 0 && buf[i] && buf[i] == c;
	 i += d, s = !s);
    if ((d < 0) && quotedP(buf, i - d)) s = !s;
  }

  return s;
}


/*
   Test whether the character "buf[pos]" is the opening 'b' of a
   "begin" keyword.
*/

Boolean beginP(buf, pos)
  char *buf;
  int   pos;
{
  return (((buf[pos] == 'b') || (buf[pos] == 'B')) &&
	  !quotedP(buf,pos) && !strncasecmp(buf+pos+1,"egin",4) &&
	  ((pos == 0)   || (!isalnum(buf[pos-1]))) &&
	  ((buf[pos+5]) ?  (!isalnum(buf[pos+5])) : True));
}


/*
   Test whether the character "buf[pos]" is the closing 'd' of
   and "end" keyword.
*/

Boolean endP(buf, pos)
  char *buf;
  int   pos;
{
  return (((buf[pos] == 'd') || (buf[pos] == 'D')) && (pos > 1) &&
	  !quotedP(buf,pos-2) && !strncasecmp(buf+pos-2,"en",2) &&
	  ((pos == 2)   || (!isalnum(buf[pos-3]))) &&
	  ((buf[pos+1]) ?  (!isalnum(buf[pos+1])) : True));
}



/*
   Test whether two characters (assumed to denote brackets) are
   of the same sort.
*/

Boolean alikeP(a,b)
  char a;
  char b;
{
  return ((a == '"') ? (b == '"') :
	  (a == '('  || a == ')') ? (b == '(' || b == ')') :
	  (a == '{'  || a == '}') ? (b == '{' || b == '}') :
	  (a == '['  || a == ']') ? (b == '[' || b == ']') :
	  (a == '<'  || a == '>') ? (b == '<' || b == '>') :
	  (a == 'b'  || a == 'B'  || a == 'd' || a == 'D') ?
	  (b == 'b'  || b == 'B'  || b == 'd' || b == 'D') : False);
}



/*
   FindMatching(): performs bracket matching.  Given a string, an integer
   index into the string and a character to match, searches back from
   the index through the string until it finds the bracket matching the
   given character.  Returns the index in the string of that character,
   or a negative value for failure: -1 if the match failed because the
   bracket was the wrong kind of simple bracket, or -2 if it was the
   wrong kind of compound bracket (<< or begin); it returns -3 if it
   failed because the search ran out of buffer before matching (ie. the
   bracket was one too many).  These values are not meaningful when
   matching string quotes.

   The buffer argument is taken as a pointer to a string, because the
   function needs to be able to change `globally' the address of the
   string it is to consider (eg. if recursive calls require to return
   to the top buffer).  Do not therefore rely upon the subsequent value
   of *buffer.

   Also takes a pointer to a Boolean argument, top, which is True if the
   string is to be considered as that in the inputHistory pane, and False
   if it is to be considered as that in the active inputPane.  If it is
   False, then if the scan reaches the start of the buffer, the buffer is
   loaded from the inputHistory widget and matching continues from the
   end of that buffer.  To operate on an arbitrary string, top should be
   True.  The argument is taken as a pointer so that recursive calls can
   alter it as if it were global.

   Similarly, it takes a pointer to Boolean called inStr, which indicates
   (for the purpose of ignoring quoted or strung brackets) whether or not
   we are currently within a string.  Again, this may very well be
   changed within the routine.  *instr should be True if the function is
   being called to match string quotes, and otherwise normally False, or
   the results may be somewhat unexpected.  The value of *inStr on exit
   from the top-level function is not intended to be meaningful (in fact
   it should always be False for bracket matching, unless the match
   failed).

   The value of *top upon exit from the function determines in which
   buffer the match was found.

   This function may be called to match:

     - brackets, with the toMatch argument either ')', '}' or ']':
       when matching brackets it will proceed backwards through the
       buffer, loading in the top buffer if needed, until there is
       no more buffer, or a matching or unmatching bracket is met,
       or a PromptChangedChar is met;

     - string quotes, with the toMatch argument '"' (or by default,
       any other character not matching another accepted bracket):
       when matching strings it will proceed backwards until the
       next string quote is met, or it runs out of buffer, or the
       next PromptChangedChar is found;

     - block brackets, Reduce-style, with the toMatch argument '>':
       no test is made that the '>' is actually a correct closing
       progn brace; the function will attempt to match in a manner
       similar to that for other brackets, if a little more compli-
       catedly.  The returned point in this case is the first of
       the two '<' characters that make up the matching bracket:
       that is, the second one to be met by this function.

   You are not expected to enjoy this.
*/


int FindMatching(buffer,top,posn,toMatch,inStr)
  char   ** buffer;
  Boolean * top;
  int       posn;
  char      toMatch;
  Boolean * inStr;
{
  char    c;
  int     success;

  while ((--posn) >= 0) {

    c = (*buffer)[posn];
    if (!quotedP(*buffer,posn)) {

      if (c == PromptChangedChar) return -3;

      if (c == '"') {

	*inStr = !(*inStr);
	if (alikeP(c,toMatch))
	  if ((success = FindMatching(buffer,top,posn,c,inStr)) < 0) 
	    return posn;
	  else return -1;
      }

      else if (!(*inStr) && toMatch != '"') {

	if ( LeftBracketP(*buffer,posn))
	  if (alikeP(c,toMatch)) return posn;
	  else                   return (prognP(*buffer,posn,'<') ||
					 beginP(*buffer,posn)) ? -2 : -1;

	if (RightBracketP(*buffer,posn))
	  if ((success = FindMatching(buffer,top,posn,c,inStr)) < 0)
	    return success;
	  else posn = success;
      }
    }
  }

  if (*top == True) return (-3);

  else {

    Arg   arg[1];
    char *topBuffer;

    XtSetArg(arg[0], XtNstring, &topBuffer);
    XtGetValues(XawTextGetSource(inputHistory), arg, 1);

    *top    = True;
    *buffer = topBuffer;

    return FindMatching(buffer,top,strlen(topBuffer),toMatch,inStr);
  }
}



void HighlightBracket()
{
  Arg             arg[2];
  int             i, n;
  char          * buf;
  XawTextPosition j;

  XawTextSetSelection(hBWidget, highlitBracket, highlitBracket + hBLength);

  i = 0; XtSetArg(arg[i], XtNstring, &buf); i++;
  XtGetValues(XawTextGetSource(hBWidget), arg, i);

  j = XawTextGetInsertionPoint(hBWidget);

  for (n = 0; j > highlitBracket; --j)
    if (buf[j] == END_OF_LINE) n ++;

  if (n && (n > 3)) {
    for (j = highlitBracket, n = 2; j >= 0 && n > 0; --j)
      if (buf[j  ] == END_OF_LINE) n --;
    if   (buf[j+1] == END_OF_LINE) j ++;

    i = 0; XtSetArg(arg[i], XtNdisplayPosition, ++j); i++;
    XtSetValues(hBWidget, arg, i);
  }
}



void UnHighlightBracket()
{
  Arg arg[2];
  int i;

  XawTextUnsetSelection(hBWidget);
  bracketRestored    = False;
  bracketHighlighted = False;

  i = 0; XtSetArg(arg[i], XtNdisplayPosition, hBPrevDisplay); i++;
  XtSetValues(hBWidget, arg, i);
}



void MaintainHighlight()
{
  if (bracketHighlighted) {

    HighlightBracket();
    bracketRestored  = True;
    bracketUHTimeout = XtAppAddTimeOut(app_ctxt, app_data.bracketFlashTime,
				       UnHighlightBracket, 0);
  }
}



void TestAndUnHighlightBracket()
{
  if (bracketHighlighted) {

    if (bracketRestored) XtRemoveTimeOut(bracketUHTimeout);
    else                 XtRemoveTimeOut(bracketMHTimeout);

    UnHighlightBracket();
  }
}


/*ARGSUSED*/
void BracketMatch(w,event)
  Widget w;
  XButtonEvent *event;
{
  Arg     arg[3];
  int     i;
  int     posn;
  int     matching;
  char  * buffer;
  char  * oldBuf;
  Boolean inStr[1];
  Boolean top[1];

  i = 0; XtSetArg(arg[i],
		  XtNstring,
		  &buffer); i++;

  XtGetValues(XawTextGetSource(w), arg, i);

      posn = XawTextGetInsertionPoint(w) - 1;
  inStr[0] = True;
    top[0] = False;
    oldBuf = buffer;

  if (quotedP(buffer,posn) ||
      ( buffer[posn] == '>' && !prognP(buffer, posn, '>')) ||
      ((buffer[posn] == 'd' || buffer[posn] == 'D') && !endP(buffer,posn)))
    return;

  inString = (FindMatching(&buffer,top,posn,'"',inStr) >= 0);
  inStr[0] = False;
    top[0] = False;
    buffer = oldBuf;

  if (inString || (!(app_data.matchBrackets ||
		     app_data.forceBracketMatch)))
    return;

  if ((matching =
       FindMatching(&buffer,top,posn,buffer[posn],inStr)) < 0) {

     XBell(XtDisplay(w), 50);

    if (app_data.forceBracketMatch &&
	oldBuf[posn] != 'd'        &&
	oldBuf[posn] != 'D') {

      XawTextBlock * blanker;

      blanker = (XawTextBlock *)XtMalloc(sizeof(XawTextBlock));
      blanker->firstPos = 0;
      blanker->length   = 0;
      blanker->ptr      = XtNewString("");
      blanker->format   = FMT8BIT;

      hBLength = ((oldBuf[posn] == '>') ? 2 : 1);
      posn    -= hBLength - 1;

      XawTextReplace(w, posn, posn+hBLength, blanker);
      XawTextSetInsertionPoint(w, posn);

      XtFree(blanker->ptr);
      XtFree((char *)blanker);
    }
   } else {

     if (app_data.bracketFlashTime > 0) {

       TestAndUnHighlightBracket();
       bracketHighlighted = True;
       bracketRestored    = False;
       highlitBracket     = matching;
       hBWidget           = (top[0]) ? inputHistory : inputPane;
       hBPrevDisplay      = XawTextTopPosition(hBWidget);
       hBLength           = ((oldBuf[posn] == '>') ? 2 :
			     (oldBuf[posn] == 'd' ||
			      oldBuf[posn] == 'D') ? 5 : 1);
       HighlightBracket();
       bracketMHTimeout   = XtAppAddTimeOut(app_ctxt,
					    BracketRestoreMatchDelay,
					    MaintainHighlight, 0);
     }
   }
}


/*ARGSUSED*/
void BracketDemonstrateMatch(w,event)
  Widget w;
  XButtonEvent *event;
{
  Arg     arg[3];
  int     i;
  int     posn;
  int     matching;
  char  * buffer;
  char  * oldBuf;
  Boolean inStr[1];
  Boolean top[1];

  if (!(app_data.matchBrackets || app_data.forceBracketMatch)) return;

  TestAndUnHighlightBracket();

  i = 0; XtSetArg(arg[i],
		  XtNstring,
		  &buffer); i++;

  XtGetValues(XawTextGetSource(w), arg, i);

      posn = XawTextGetInsertionPoint(w) - 1;
  inStr[0] = True;
    top[0] = False;
    oldBuf = buffer;

  if (!RightBracketP(buffer,posn) || quotedP(buffer,posn)) return;

  inString = (FindMatching(&buffer,top,posn,'"',inStr) >= 0);
  inStr[0] = False;
    top[0] = False;
    buffer = oldBuf;

  if (inString ||
      ((matching = FindMatching(&buffer,top,posn,buffer[posn],inStr)) < 0))
    return;

  if (app_data.bracketFlashTime > 0) {

    bracketHighlighted = True;
    bracketRestored    = False;
    highlitBracket     = matching;
    hBWidget           = (top[0]) ? inputHistory : inputPane;
    hBPrevDisplay      = XawTextTopPosition(hBWidget);
    hBLength           = ((oldBuf[posn] == '>') ? 2 :
			  (oldBuf[posn] == 'd' ||
			   oldBuf[posn] == 'D') ? 5 : 1);
    HighlightBracket();
    bracketMHTimeout   = XtAppAddTimeOut(app_ctxt,
					 BracketRestoreMatchDelay,
					 MaintainHighlight, 0);
  }
}



void BracketComplete(w,event)
  Widget w;
  XButtonEvent *event;
{
  Arg            arg[3];
  int            i, j;
  int            posn;
  int            oposn;
  int            matching;
  char           try[3];
  char         * buffer;
  Boolean        inStr[1];
  Boolean        top[1];
  XawTextBlock * filler;

  filler = (XawTextBlock *)XtMalloc(sizeof(XawTextBlock));
  filler->firstPos = 0;
  filler->length   = 1;
  filler->ptr      = XtNewString(")");
  filler->format   = FMT8BIT;

  j = 0; XtSetArg(arg[j],
		  XtNstring,
		  &buffer); j++;

  XtGetValues(XawTextGetSource(w), arg, j);

      posn = XawTextGetInsertionPoint(w);
     oposn = posn;
  inStr[0] = True;
    top[0] = False;

  if (quotedP(buffer,posn) ||
      (inString = (FindMatching(&buffer,top,posn,'"',inStr) >= 0)))
    goto failure;

  try[0] = ')';
  try[1] = '}';
  try[2] = ']';

 loop:

  for (i = 0; i < 3; ++i) {

    XtGetValues(XawTextGetSource(w), arg, j);
    inStr[0] = False;
      top[0] = False;
    matching = FindMatching(&buffer,top,posn,try[i],inStr);

    if (matching >= 0) {

      filler->ptr[0] = try[i];
      XawTextReplace(w, posn, posn, filler);
      posn ++;
      goto loop;

    } else if (matching < -1) goto success;
  }

 failure:

  XBell(XtDisplay(w), 50);

  if (posn > oposn) {
    filler->ptr[0] = 0x0;
    filler->length = 0;
    XawTextReplace(w, oposn, posn, filler);
  }

  XawTextSetInsertionPoint(w, oposn);
  XtFree(filler->ptr);
  XtFree((char *)filler);
  return;

 success:

  XawTextSetInsertionPoint(w, posn);
  XtFree(filler->ptr);
  XtFree((char *)filler);
  BracketDemonstrateMatch(w,event);
  return;
}


/*ARGSUSED*/
void InputChanged(w,client_data,call_data)
  Widget  w;
  caddr_t client_data,
          call_data;
{
  inputFromChar = -1L;
  TestAndUnHighlightBracket();
  return;
}


long BlockBack(from)
  long from;
{
  char *buffer;
  Arg   arg;
  long  to;

  XtSetArg(arg, XtNstring, &buffer);
  XtGetValues(XawTextGetSource(inputHistory), &arg, 1);

  for (to = from; to > 0 && !PromptCharP(buffer[to]); --to);
  if  (to > 0) return to-1;
  else return from;
}


long BlockForward(from)
  long from;
{
  char *buffer;
  Arg   arg;
  long  to;

  XtSetArg(arg, XtNstring, &buffer);
  XtGetValues(XawTextGetSource(inputHistory), &arg, 1);

  if (PromptCharP(buffer[from+1])) to = from+2;
  else to = from;

  while (buffer[to] && !PromptCharP(buffer[to])) ++to;
  if    (buffer[to]) return to-1;
  else return from;
}


void InstateHistoryCopy(w,charNo,toLen)
  Widget w;
  long   charNo;
  int    toLen;
{
  XawTextBlock * blanker;
  XawTextBlock * filler;
  char         * fromBuf;
  char         * newBuf = NULL;
  long           sLen;
  long           i, j;
  long           filll;
  Arg            arg[2];

  if (charNo == -1) {

    filler = (XawTextBlock *)XtMalloc(sizeof(XawTextBlock));
    filler->firstPos = 0;
    filler->length   = strlen(tempBuffer);
    filler->ptr      = tempBuffer;
    filler->format   = FMT8BIT;

  } else {

    i = 0; XtSetArg(arg[i], XtNstring, &fromBuf); i++;
    XtGetValues(XawTextGetSource(inputHistory), arg, i);

    for (i = charNo, filll = 0;
	 i > 0 && !PromptCharP(fromBuf[i]); --i, ++filll);
    if (PromptCharP(fromBuf[i])) ++i, --filll;

    while (i < charNo && isspace(fromBuf[i])) ++i, --filll;

    newBuf = (char *)XtMalloc(filll + 2);
    for (j = sLen = 0; sLen < (filll+1) && (fromBuf[i+sLen]); ++sLen) 
      if (isprint(fromBuf[i+sLen])) {
	newBuf[sLen-j] = fromBuf[i+sLen];
      } else j++;
    filll = sLen - j;
    newBuf[filll] = 0x0;

    filler = (XawTextBlock *)XtMalloc(sizeof(XawTextBlock));
    filler->firstPos  = 0;
    filler->length    = filll;
    filler->ptr       = newBuf;
    filler->format    = FMT8BIT;
  }

  blanker = (XawTextBlock *)XtMalloc(sizeof(XawTextBlock));
  blanker->firstPos = 0;
  blanker->length   = 0;
  blanker->ptr      = XtNewString("");
  blanker->format   = FMT8BIT;

  XawTextReplace(w, 0, toLen, blanker);
  XawTextReplace(w, 0, 0, filler);
 
  if (newBuf) XtFree(newBuf);
  XtFree(blanker->ptr);
  XtFree((char *)blanker);
  XtFree((char *)filler);
}
 

/*ARGSUSED*/
void HandleUpArrow(w,event)
  Widget w;
  XButtonEvent *event;
{
  Arg     arg[2];
  int     i;
  char  * buffer;
  int     posn;
  int     maxp;
  long    origl;
  Boolean firstLine;

  i = 0; XtSetArg(arg[i], XtNstring, &buffer); i++;
  XtGetValues(XawTextGetSource(w), arg, i);

  posn  = XawTextGetInsertionPoint(w);
  maxp  = strlen(buffer);
  origl = inputFromChar;

  for (firstLine = True, i = posn-1; i >= 0 && firstLine == True; --i)
    if (buffer[i] == END_OF_LINE) firstLine = False;

  if (firstLine == False) return;

  if (inputFromChar == 0L) {

    XBell(XtDisplay(w), 50);

  } else if (inputFromChar == -1L) {

    char *upbuf;

    if (tempBuffer != NULL) {
      XtFree(tempBuffer);
    }
    tempBuffer    = (char *)XtMalloc(maxp + 1);

    XtSetArg(arg[0], XtNstring, &upbuf);
    XtGetValues(XawTextGetSource(inputHistory), arg, 1);
    inputFromChar = (long)strlen(upbuf) - 1;

    while (upbuf[inputFromChar] == END_OF_LINE ||
	   PromptCharP(upbuf[inputFromChar])) -- inputFromChar;

    strcpy(tempBuffer, buffer);

  } else
    inputFromChar = BlockBack(inputFromChar);

  if (origl != inputFromChar) {
    XtRemoveCallback(XawTextGetSource(w), XtNcallback, InputChanged, 0);
    InstateHistoryCopy(w,inputFromChar,maxp);
    XawTextSetInsertionPoint(w,0);
    XtAddCallback(XawTextGetSource(w), XtNcallback, InputChanged, 0);
  }
}


/*ARGSUSED*/
void HandleDownArrow(w,event)
  Widget w;
  XButtonEvent event;
{
  Arg     arg[2];
  int     i;
  char  * buffer;
  char  * upbuf;
  int     posn;
  int     maxp;
  long    origl;
  Boolean lastLine;

  i = 0; XtSetArg(arg[i], XtNstring, &buffer); i++;
  XtGetValues(XawTextGetSource(w), arg, i);

  posn  = XawTextGetInsertionPoint(w);
  maxp  = strlen(buffer);
  origl = inputFromChar;

  for (lastLine = True, i = posn; i < maxp && lastLine == False; ++i)
    if (buffer[i] == END_OF_LINE) lastLine = False;

  if (lastLine == False) return;

  if (inputFromChar == -1L) {

    XBell(XtDisplay(w), 50);

  } else {

    XtSetArg(arg[0], XtNstring, &upbuf);
    XtGetValues(XawTextGetSource(inputHistory), arg, 1);

    inputFromChar ++;
    while ( upbuf[inputFromChar] &&
	   (upbuf[inputFromChar] == END_OF_LINE ||
	    PromptCharP(upbuf[inputFromChar]))) ++inputFromChar;

    if  (!upbuf[inputFromChar]) inputFromChar = -1L;
    else inputFromChar  = BlockForward(inputFromChar);
  }

  if (origl != inputFromChar) {
    XtRemoveCallback(XawTextGetSource(w), XtNcallback, InputChanged, 0);
    InstateHistoryCopy(w,inputFromChar,maxp);
    XawTextSetInsertionPoint(w,0);
    XtAddCallback(XawTextGetSource(w), XtNcallback, InputChanged, 0);
  }
}



char *GuessHelpContext()
{
  int     i,j;
  int     word;
  int     prel = 0;
  int     prew;
  Arg     arg;
  char   *orig;
  char   *done;
  char   *temp;
  Boolean useBoth = False;

  XtSetArg(arg, XtNstring, &orig);
  XtGetValues(XawTextGetSource(inputPane), &arg, 1);

  for (i = j = strlen(orig), word = 0; i >= 0 && word < 7; --i)
    if ((j-i) > 2 && !isalpha(orig[i])) { j = i; ++ word; }

  if ((prew = word) > 0) {

    done = (char *)XtMalloc(j-i+1);

    for (j = 0; orig[++i]; )
      if      (isalpha(orig[i  ])) done[j++] = orig[i];
      else if (isalpha(orig[i-1])) done[j++] = ' ';

    done[prel = j] = 0;
    if (word >= 7) return done;

  } else done = NULL;

  XtGetValues(XawTextGetSource(inputHistory), &arg, 1);

  for (i = j = strlen(orig); i >= 0 && word < 7; --i)
    if ((j-i) > 2 && !isalpha(orig[i])) { j = i; ++ word; }

  if (word > prew) {

    temp = done;
    done = (char *)XtMalloc(j-i+1+prel);

    if (prel > 0) { strcpy(done,temp); XtFree(temp); }

    for (j = prel; orig[++i]; )
      if      (isalpha(orig[i  ])) done[j++] = orig[i];
      else if (isalpha(orig[i-1])) done[j++] = ' ';

    done[j] = 0;
    return done;

  } else
    if (word > 0) return done;
    else return XtNewString("Top");
}

