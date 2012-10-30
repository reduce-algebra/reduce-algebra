
/*
   Header file to export from Help module.
*/


extern int   HelpSetTextFont();
extern int   HelpSetXrefFont();
extern int   HelpSetButtonFont();
extern int   HelpSetTitleFont();
extern int   HelpSetVerbatimFont();

extern XFontStruct *helpTextFont;
extern XFontStruct *helpXrefFont;
extern XFontStruct *helpCommFont;
extern XFontStruct *helpHeadFont;
extern XFontStruct *helpXmplFont;

extern int   HelpInitialise();
extern int   HelpSetTopic();
extern int   HelpInstallHelp();
extern void  HelpClose();
extern int   HelpSetHelpFile();
extern char *HelpGetHelpFile();
extern int   HelpCloseHelpFile();
extern void  HelpDoneButtonAction();
extern void  HelpContextHelpAction();

extern int   HelpWriteIndexFile();
