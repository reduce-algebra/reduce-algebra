
/*
   Header file to export from user-input module.
*/


extern long  inputFromChar;	/* was inputFromLine */
extern int   linesInInputHistory;

extern void  PlaceItemOnPending();
extern void  PlaceUrgentItemOnPending();
extern void  ProcessInput();
extern void  CopyDown();
extern void  BracketMatch();
extern void  BracketDemonstrateMatch();
extern void  BracketComplete();
extern void  HandleStringQuote();
extern void  HandleUpArrow();
extern void  HandleDownArrow();
extern void  InputChanged();
extern void  PlacePromptMarker();
extern char *GuessHelpContext();

