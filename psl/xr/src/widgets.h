
/*
   Header file to export from widget setup module.
*/


extern Widget        inputPane;
extern Widget        inputHistory;
extern Widget        outputHistory;
extern Widget        outputPane;
extern Dimension     maxWidth;
extern Dimension     verbalHeight;
extern XFontStruct * verbalFont;
extern XFontStruct * buttonFont;
extern XFontStruct * inputPaneFont;
extern XFontStruct * inputHistoryFont;

extern void XRedSizeLabelForLabel();
extern void XRedTranslateCoords();
extern void SetGenericVerbalSize();
extern void SetOutputToBottom();
extern void SetButtonFonts();
extern void createWidgets();
extern void QuitButton();
extern void IntButton();

