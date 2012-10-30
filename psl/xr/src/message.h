
/*
   Header file to export from popup message widget module
*/


extern Boolean sendAnswersToReduce;
extern Boolean messageAnswer;
extern void (* gotMessageHook)();

extern void    setupMessages();
extern void    PlaceSomeMessage();
extern void    MessageYesAction();
extern void    MessageNoAction();
extern void    MessageInterruptAction();

