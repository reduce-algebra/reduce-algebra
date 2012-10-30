
/*
   Header file to export from XReduce output widget management module.

   Chris Cannam, Feb 1993
*/


extern Dimension placedHeight;
extern Dimension screenHeight;
extern Cursor    watchCursor;
extern Cursor    moreCursor;

extern Widget  CreateWidget();
extern Boolean InitiallyManaged();
extern void    StepButtonAction();
extern void    RaisePlacedHeight();
extern void    FreeManager();
extern void    ManageSomeHistList();
extern void    DisplayWatchCursor();
extern void    UndisplayWatchCursor();
extern void    SwitchPageModeBackOff();
