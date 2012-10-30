
/*
   Header file to export from verbals module
*/


extern HistList * FlushAndStartNewVerbal();
extern HistList * CreateNewVerbal();
extern HistList * ClipFromHistList();

extern Boolean    verbalVerbatim;
extern void       VerbalVerbatim();
extern void       AddTextToVerbal();
extern void       PlaceSomeLines();
extern Boolean    InterleaveInput();

