
/*
   Header for XReduce resources, to be included by any
   module which might want to use resource values (in
   practice, all of them.)

   C Cannam, 1992-3.
*/


#define XtNreduceHistoryMax    "reduceHistoryMax"
#define XtCReduceHistoryMax    "ReduceHistoryMax"
#define XtNreduceHistoryExcess "reduceHistoryExcess"
#define XtCReduceHistoryExcess "ReduceHistoryExcess"
#define XtNwidthInColumns      "widthInColumns"
#define XtCWidthInColumns      "WidthInColumns"
#define XtNhistoryPaneHeight   "historyPaneHeight"
#define XtCHistoryPaneHeight   "HistoryPaneHeight"
#define XtNinputPaneHeight     "inputPaneHeight"
#define XtCInputPaneHeight     "InputPaneHeight"
#define XtNfontSelectorHeight  "fontSelectorHeight"
#define XtCFontSelectorHeight  "FontSelectorHeight"
#define XtNfontSelectorWidth   "fontSelectorWidth"
#define XtCFontSelectorWidth   "FontSelectorWidth"
#define XtNreducePath          "reducePath"
#define XtCReducePath          "ReducePath"
#define XtNreduceName          "reduceName"
#define XtCReduceName          "ReduceName"
#define XtNreduceInitFile      "reduceInitFile"
#define XtCReduceInitFile      "ReduceInitFile"
#define XtNreduceImageFile     "reduceImageFile"
#define XtCReduceImageFile     "ReduceImageFile"
#define XtNreduceHelpFile      "reduceHelpFile"
#define XtCReduceHelpFile      "ReduceHelpFile"
#define XtNinputBufferSize     "inputBufferSize"
#define XtCInputBufferSize     "InputBufferSize"
#define XtNoutputBufferSize    "outputBufferSize"
#define XtCOutputBufferSize    "OutputBufferSize"
#define XtNnormalAsciiFont     "normalAsciiFont"
#define XtCNormalAsciiFont     "NormalAsciiFont"
#define XtNnormalGreekFont     "normalGreekFont"
#define XtCNormalGreekFont     "NormalGreekFont"
#define XtNnormalSymbolFont    "normalSymbolFont"
#define XtCNormalSymbolFont    "NormalSymbolFont"
#define XtNsmallAsciiFont      "smallAsciiFont"
#define XtCSmallAsciiFont      "SmallAsciiFont"
#define XtNsmallGreekFont      "smallGreekFont"
#define XtCSmallGreekFont      "SmallGreekFont"
#define XtNsmallSymbolFont     "smallSymbolFont"
#define XtCSmallSymbolFont     "SmallSymbolFont"
#define XtNinputPaneFont       "inputPaneFont"
#define XtCInputPaneFont       "InputPaneFont"
#define XtNinputHistoryFont    "inputHistoryFont"
#define XtCInputHistoryFont    "InputHistoryFont"
#define XtNoutputTextFont      "outputTextFont"
#define XtCOutputTextFont      "OutputTextFont"
#define XtNoptionButtonFont    "optionButtonFont"
#define XtCOptionButtonFont    "OptionButtonFont"
#define XtNhelpTextFont        "helpTextFont"
#define XtCHelpTextFont        "HelpTextFont"
#define XtNhelpXrefFont        "helpXrefFont"
#define XtCHelpXrefFont        "HelpXrefFont"
#define XtNverbatimFont        "verbatimFont"
#define XtCVerbatimFont        "VerbatimFont"
#define XtNhelpTitleFont       "helpTitleFont"
#define XtCHelpTitleFont       "HelpTitleFont"
#define XtNpsTextFont          "psTextFont"
#define XtCPsTextFont          "PsTextFont"
#define XtNpsSymbolFont        "psSymbolFont"
#define XtCPsSymbolFont        "PsSymbolFont"
#define XtNpsAsciiFont         "psAsciiFont"
#define XtCPsAsciiFont         "PsAsciiFont"
#define XtNreverseGraph        "reverseGraph"
#define XtCReverseGraph        "ReverseGraph"
#define XtNoutputOnDelay       "outputOnDelay"
#define XtCOutputOnDelay       "OutputOnDelay"
#define XtNoutputOffDelay      "outputOffDelay"
#define XtCOutputOffDelay      "OutputOffDelay"
#define XtNmatchBrackets       "matchBrackets"
#define XtCMatchBrackets       "MatchBrackets"
#define XtNforceBracketMatch   "forceBracketMatch"
#define XtCForceBracketMatch   "ForceBracketMatch"
#define XtNgraphicalLineSpace  "graphicalLineSpace"
#define XtCGraphicalLineSpace  "GraphicalLineSpace"
#define XtNlogToFile           "logToFile"
#define XtCLogToFile           "LogToFile"
#define XtNlogFile             "logFile"
#define XtCLogFile             "LogFile"
#define XtNignoreTeXFonts      "ignoreTeXFonts"
#define XtCIgnoreTeXFonts      "IgnoreTeXFonts"
#define XtNfoundDefaults       "foundDefaults"
#define XtCFoundDefaults       "FoundDefaults"
#define XtNbracketFlashTime    "bracketFlashTime"
#define XtCBracketFlashTime    "BracketFlashTime"
#define XtNpageMode            "pageMode"
#define XtCPageMode            "PageMode"
#define XtNpointerJump         "pointerJump"
#define XtCPointerJump         "PointerJump"
#define XtNmultiClickTime      "multiClickTime"
#define XtCMultiClickTime      "MultiClickTime"
#define XtNkludgeTitleHeight   "kludgeTitleHeight"
#define XtCKludgeTitleHeight   "KludgeTitleHeight"
#define XtNuseGreekFont        "useGreekFont"
#define XtCUseGreekFont        "UseGreekFont"
#define XtNuseSymbolFont       "useSymbolFont"
#define XtCUseSymbolFont       "UseSymbolFont"
#define XtNuseGraphics         "useGraphics"
#define XtCUseGraphics         "UseGraphics"
#define XtNreduceOptions       "reduceOptions"
#define XtCReduceOptions       "ReduceOptions"
#define XtNscaleFonts          "scaleFonts"
#define XtCScaleFonts          "ScaleFonts"


typedef struct {
  int       reduceHistoryMax;
  int       reduceHistoryExcess;
  int       widthInColumns;
  int       graphicalLineSpace;
  int       inputBufferSize;
  int       outputBufferSize;
  int       outputOnDelay;
  int       outputOffDelay;
  int       bracketFlashTime;
  int       multiClickTime;
  Dimension historyPaneHeight;
  Dimension inputPaneHeight;
  Dimension fontSelectorHeight;
  Dimension fontSelectorWidth;
  Dimension kludgeTitleHeight;
  String    reducePath;
  String    reduceName;
  String    reduceInitFile;
  String    reduceImageFile;
  String    reduceHelpFile;
  String    normalAsciiFont;
  String    normalGreekFont;
  String    normalSymbolFont;
  String    smallAsciiFont;
  String    smallGreekFont;
  String    smallSymbolFont;
  String    inputPaneFont;
  String    inputHistoryFont;
  String    outputTextFont;
  String    optionButtonFont;
  String    helpTextFont;
  String    helpXrefFont;
  String    verbatimFont;
  String    helpTitleFont;
  String    psTextFont;
  String    psSymbolFont;
  String    psAsciiFont;
  String    logFile;
  String    reduceOptions;
  Boolean   useGraphics;
  Boolean   reverseGraph;
  Boolean   matchBrackets;
  Boolean   forceBracketMatch;
  Boolean   logToFile;
  Boolean   ignoreTeXFonts;
  Boolean   pageMode;
  Boolean   pointerJump;
  Boolean   useGreekFont;
  Boolean   useSymbolFont;
  Boolean   scaleFonts;
  Boolean   foundDefaults;
} AppData, *AppDataPtr;

