
/*
   Header file to export from main module
*/


extern char        * reduceInputBuffer;
extern char        * reduceOutputBuffer;
extern char        * reduceOutputPoint;
extern int           reduceOutputRemaining;
extern unsigned long reduceHistoryNumber;
extern int           reduceProcessID;
extern int           myProcessID;
extern int           MeToReduce[2],
                     ReduceToMe[2],
                     ReduceErrs[2];
extern Boolean       waitingToInterleave;
extern Boolean       quietMode;

extern EltType       historyMode;
extern HistList    * reduceHistory;
extern HistList    * endOfHistory;
extern HistList    * endOfManaged;

extern PendingInputList *pendingInput;
extern PendingInputList *lastInput;

extern AppData           app_data;
extern XtAppContext      app_ctxt;

extern char * EnsureFilename();
extern void   removeSignalHandlers();
extern void   red_err();
extern void   red_kill();
extern void   red_warn();
extern void   ReduceSigChld();	/* referred to by printer.c */
extern void   ReduceSigPipe();	/* likewise                 */
