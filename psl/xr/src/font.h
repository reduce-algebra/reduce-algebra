
/*
   Header file to export from font selection module.
*/


#define FontBoldSizeLimit 20

extern void         initialiseFontSel();
extern XFontStruct *FontLoadQueryFont();
extern int          FontToActualSize();
extern void         FontDoneButton();
extern void         FontDoneButtonAction();
extern Boolean      fontSelectorActive;
extern void         installFontSelector();

