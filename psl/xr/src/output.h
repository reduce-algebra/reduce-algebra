
/*
   Header file to export from reduce-output module
*/


extern int     promptPresent;
extern Boolean preCmdFlag;
extern void  (*preCmd)();

extern void    initialiseOutput();
extern void    HandleReduceErrorStream();
extern void    HandleReduceOutputStream();
extern void    UnHandleReduceOutput();
extern void    RestartReduceOutput();
extern void    GetReduceOutput();
