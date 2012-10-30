
/*
   Module to handle the XReduce built-in font selection utility.
   (My, we are getting ambitious -- perhaps too ambitious ...)

   This module specialises in the following:

   o  Commented-out debugging fprintf calls;
   o  Commented-out bug-ridden code;
   o  Less slick design than originally intended.

   (In these I suppose it might be considered normal software.)

   There has for quite a while been a small set of nasty bugs in
   here, providing at least three ways to crash the Font Selector,
   and XReduce with it, without doing anything illegal (or indeed
   necessarily anything at all).  After some months of tearing my
   hair out over the better-hidden bugs, I *think* I've now managed
   to exorcise two of those three, by restricting the arrangement
   and categorization of font families.  At least one remains.

   I hope, however, that the thing is now finally usable.

   At the moment this module is XR-specific; it shouldn't be too
   much work to make an independent thingy out of it, should anyone
   (oh, the fool) wish to try to use it as an extra to their own
   code.  It might be nice to make a separate stand-alone program
   out of it, with just the calling convention defining how it
   interacts, but I think that might be a bit complicated.

   -- Chris Cannam, Berlin, May 1993
*/


#include "xreduce.h"
#include "main.h"
#include "xredplus.h"
#include "widgets.h"
#include "option.h"
#include "message.h"
#include "manager.h"		/* for watchCursor */
#include "help.h"
#include "verbal.h"

#define FontBoldSizeLimit 20

#define NOFONTSLABEL   "No Family Selected"
#define DEFAULTFONT    "fixed"
#define MAXFONTSINLIST 3000
#define MAXFAMILIES    500
#define MAXPLEN        50
#define MAXPIXELSCALE  300
#define FAMILY_NONE    -1
#define HL_FONT        1
#define HL_FAMILY      2
#define HL_PURPOSE     4
#define BEGARG         { Arg arg;
#define SETARG(q,z,k)  { XtSetArg(arg,(z), (k)); XtSetValues((q),&arg,1); }
#define GETARG(q,z,k)  { XtSetArg(arg,(z),&(k)); XtGetValues((q),&arg,1); }
#define FINARG         }

#define NO_OF_PURPOSES 12

/* I need this macro to be fast; is doesn't have to be safe, because I'll  */
/* check the parameter first; it doesn't have to be localisable, at least  */
/* for the moment; and I don't want to rely on the SysV fast macro. Hence: */

#define RTU(x) ((x)-'a'+'A')

/* Define a structure to hold information about each font name, and define */
/* some mask values for font properties.  Most of the structure will start */
/* off empty, and only be filled in when needed.                           */

#define FontNormal   (1<<0)
#define FontBold     (1<<1)
#define FontSlanted  (1<<2)

typedef struct _FontNS {
  char     *name;	/* String shared from fullFontList                  */
  char     *alias;	/* Friendly name                                    */
  char     *refer;      /* Whichever of name or alias we should display     */
  unsigned  properties; /* Flags ORd from above-def'd masks, fill as needed */
  int       size;	/* Only relevant for scalable fonts, probably.  If  */
		        /* font is *not* scalable, this is -1.              */
} FontNS;

int               FontToActualSize();
void              installFontSelector();
void              FontToggle();
void              FontHandleFontSelectorWholeGeometry();
void              FontHandleFontSelectorSubGeometries();
void              FontPropagateButton();
void              FontPropYes();
void              FontPropNo();
void              FontInstallVerifier();
Boolean           fontSelectorActive = False;
static Widget     referenceWidget;
static Widget     fontShell;
static Widget     fontForm;
static Widget     fontFamilyBox;
static Widget     fontFamilyListTitle;
static Widget     fontFamilyListViewport;
static Widget     fontFamilyListList;
static Widget     fontPurposeBox;
static Widget     fontPurposeListTitle;
static Widget     fontPurposeListViewport;
static Widget     fontPurposeListList;
static Widget     fontToggleViewportBox;
static Widget     fontToggleViewport;
static Widget     fontToggleBox;
static Widget    *fontToggle;
static Widget     fontEmptyFamilyLabel;
static Widget     fontSideButtonBox;
static Widget     fontAnyButton;
static Widget     fontBoldButton;
static Widget     fontItalicButton;
static Widget     fontShowButton;
static Widget     fontScaleButton;
static Widget     fontButtonBox;
static Widget     fontApplyButton;
static Widget     fontPropagateButton;
static Widget     fontResetButton;
static Widget     fontDoneButton;
static Widget     fontVerifyShell;
static Widget     fontVerifyBox;
static Widget     fontVerifyTopLabel;
static Widget     fontVerifyShowBox;
static Widget     fontVerifyPurposeLabels[NO_OF_PURPOSES];
static Widget     fontVerifyBottomLabel;
static Widget     fontVerifyYesButton;
static Widget     fontVerifyNoButton;
static Widget     fontScaleShell;
static Widget     fontScaleDialog;
static Widget     fontScaleApply;
static Widget     fontScaleCancel;
static Widget     amendedWidget   = NULL;
static Cursor     normalCursor;
static XGCValues *valuesp;
static Dimension  toggleWidth;
static Dimension  iPSpace         = 4;
static Dimension  maxToggleWidth  = 1100;
static Boolean    useAlias        = True;
static Boolean    madeChanges;
static Boolean    doubleClicking;
static Boolean    scalableFamily  = False;
static unsigned   displayMask     = FontNormal | FontBold | FontSlanted;
static int        currentPurpose;
static int        currentFamily;
static int       *currentFontInFamily = NULL;   /* ix'd by family no.        */
static int        fontFamilyCount = 0;          /* No. of families           */
static int        maxFontFamilySize;
static int       *fontFamilySize  = NULL;       /* No. in each family        */
static char      *fontFamilyName[MAXFAMILIES];  /* Names of families         */
static char     **fullFontList    = NULL;	/* As supplied by XListFonts */
static FontNS   **fontList        = NULL;       /* fontList[fam][noInFam]=.. */
static char      *fontPurposes[NO_OF_PURPOSES];
static char      *oldFont[NO_OF_PURPOSES];
static char      *otherFontFamilyName = "Various";
static char      *dotFontFamilyName   = "TeX";

int               FontGetEmphasisStatus();
int               FontGetListedSize();
void              FontInstateOptionValues();
void              FontReleaseOptionButtons();

typedef struct _PurposeFontStruct {
  char    * purpose;
  char    * resource;
  char    * initial;		/* Always a non-shared string; can free  */
  char    * proposed;		/* Also a non-shared (malloc'd) string   */
  char    * selected;		/* Also always non-shared                */
  int       class;		/* Lowest class must be zero; step 1     */
  int       ideal;		/* Percentage, if you're wise            */
  Boolean   changed;		/* Has selected field changed?           */
  Boolean   inherit;		/* Should it inherit size information?   */
  int       actual;		/* Ascent + descent of selected font     */
  int       listed;		/* Listed pixel size of selected font    */
} PurposeFontStruct;

static PurposeFontStruct pList[NO_OF_PURPOSES] = {
  {
    "Option Buttons", XtNoptionButtonFont,
    NULL, NULL, NULL, 3, 100, False, False, 0, 0,
  }, {
    "Input Pane", XtNinputPaneFont,
    NULL, NULL, NULL, 0, 100, False, True,  0, 0,
  }, {
    "Input History", XtNinputHistoryFont,
    NULL, NULL, NULL, 0, 100, False, True,  0, 0,
  }, {
    "Output Text", XtNoutputTextFont,
    NULL, NULL, NULL, 0, 100, False, True,  0, 0,
  }, {
    "Formula Text", XtNnormalAsciiFont,
    NULL, NULL, NULL, 1, 100, False, True,  0, 0,
  }, {
    "Formula Small Text", XtNsmallAsciiFont,
    NULL, NULL, NULL, 1,  80, False, True,  0, 0,
  }, {
    "Formula Greek Text", XtNnormalGreekFont,
    NULL, NULL, NULL, 2, 100, False, True,  0, 0,
  }, {
    "Formula Small Greek Text", XtNsmallGreekFont,
    NULL, NULL, NULL, 2,  80, False, True,  0, 0,
  }, {
    "Verbatim Text", XtNverbatimFont,
    NULL, NULL, NULL, 6, 100, False, True,  0, 0,
  }, {
    "Help Normal Text", XtNhelpTextFont,
    NULL, NULL, NULL, 4, 100, False, True,  0, 0,
  }, {
    "Help Cross-Reference Text", XtNhelpXrefFont,
    NULL, NULL, NULL, 5, 100, False, True,  0, 0,
  }, {
    "Help Titles", XtNhelpTitleFont,
    NULL, NULL, NULL, 4, 100, False, True,  0, 0,
  },
};

typedef enum {
  FontOptionButtonsN = 0,
  FontInputPaneN,
  FontInputHistoryN,
  FontOutputTextN,
  FontOutputGraphicAsciiN,
  FontOutputGraphicSmallAsciiN,
  FontOutputGraphicGreekN,
  FontOutputGraphicSmallGreekN,
  FontVerbatimN,
  FontHelpNormalN,
  FontHelpCrossReferenceN,
  FontHelpTitleN
  } FontPurpose;



/* Convenience routine to load up fonts.  This error shouldn't really */
/* be a fatal XReduce error; it should really just be fatal within    */
/* the font selector.  I ought to do something about that.  Same goes */
/* for the other font-fatal errors in this module.                    */

XFontStruct *FontLoadQueryFont(widget,fn)
  Widget widget;
  char  *fn;
{
  XFontStruct *fontStructp;

  if ((fontStructp = XLoadQueryFont(XtDisplay(widget),fn)) == NULL) {
    if (!quietMode)
      fprintf(stderr,"XR: No font \"%s\", trying \"%s\"\n",
	    fn, DEFAULTFONT);
    if ((fontStructp = XLoadQueryFont(XtDisplay(widget),DEFAULTFONT))
	== NULL) red_err("Couldn't load default font");
  }
  return fontStructp;
}
    


char *FontGetInitialFont(purpose) /* Returns a shared string: don't change */
  FontPurpose purpose;		  /* it unless you know what you're doing, */
{				  /* and don't free it                     */
  switch(purpose) {

  case FontInputPaneN:
    return app_data.inputPaneFont;
  case FontInputHistoryN:
    return app_data.inputHistoryFont;
  case FontOutputTextN:
    return app_data.outputTextFont;
  case FontOutputGraphicAsciiN:
    return app_data.normalAsciiFont;
  case FontOutputGraphicGreekN:
    return app_data.normalGreekFont;
  case FontOutputGraphicSmallAsciiN:
    return app_data.smallAsciiFont;
  case FontOutputGraphicSmallGreekN:
    return app_data.smallGreekFont;
  case FontOptionButtonsN:
    return app_data.optionButtonFont;
  case FontVerbatimN:
    return app_data.verbatimFont;
  case FontHelpNormalN:
    return app_data.helpTextFont;
  case FontHelpCrossReferenceN:
    return app_data.helpXrefFont;
  case FontHelpTitleN:
    return app_data.helpTitleFont;
  default:
    return XtNewString(DEFAULTFONT);
  }
}



Boolean FontTestWhetherFIDNeeded(fid)
  Font fid;
{
  int i;

  if (fid ==       verbalFont->fid ||
      fid ==       buttonFont->fid ||
      fid ==    inputPaneFont->fid ||
      fid == inputHistoryFont->fid)
    return True;

  for (i = 0; i < 6; ++i) {

    if (XGetGCValues(XtDisplay(referenceWidget),
		     textGC[i/3][i%2],
		     GCFont, valuesp)) {

      if (valuesp->font == fid) return True;
    }
  }

  return False;
}



Boolean FontTestWhetherFontNeeded(fontStructp)
  XFontStruct * fontStructp;
{
  return FontTestWhetherFIDNeeded(fontStructp->fid);
}



void FontSetFont(purpose,font)
  FontPurpose purpose;
  char      * font;
{
  Arg            arg;
  XFontStruct ** fontStructpp    = NULL;
  Widget         setWidget       = NULL;
  void        (* setFontHookA)() = NULL;
  void        (* setFontHookB)() = NULL;
  int            GCi;
  int            i;

  switch(purpose) {

  case FontInputPaneN:
    fontStructpp = &inputPaneFont;
    setWidget    = inputPane;
    break;
  case FontInputHistoryN:
    fontStructpp = &inputHistoryFont;
    setWidget    = inputHistory;
    break;
  case FontOutputTextN:
    fontStructpp = &verbalFont;
    if (!verbalVerbatim) {
      setFontHookA = SetGenericVerbalSize;
      if (endOfHistory &&
	  endOfHistory->flavour == ReduceVerbal)
	setWidget  = endOfHistory->widget;
    }
    break;
  case FontOutputGraphicAsciiN:
    GCi          = 0;
    boldGraphics = 0;
    if (FontToActualSize(font) >= FontBoldSizeLimit)
      boldGraphics |= 1;
    for (i = 0; i < ((int)strlen(font) - 4); ++i)
      if (!strncasecmp(font + i, "bold", 4)) {
	boldGraphics |= 2;
	break;
      }
    break;
  case FontOutputGraphicGreekN:
    GCi          = 4;
    break;
  case FontOutputGraphicSmallAsciiN:
    GCi          = 1;
    break;
  case FontOutputGraphicSmallGreekN:
    GCi          = 5;
    break;
  case FontOptionButtonsN:
    fontStructpp = &buttonFont;
    setFontHookA = SetButtonFonts;
    setFontHookB = SetOptionButtonFonts;
    HelpSetButtonFont(font);
    break;
  case FontHelpNormalN:
    HelpSetTextFont(font);
    return;
  case FontHelpCrossReferenceN:
    HelpSetXrefFont(font);
    return;
  case FontVerbatimN:
    HelpSetVerbatimFont(font);
    if (verbalVerbatim) {
      setFontHookA = SetGenericVerbalSize;
      if (endOfHistory &&
	  endOfHistory->flavour == ReduceVerbal)
	setWidget  = endOfHistory->widget;
    }
    return;
  case FontHelpTitleN:
    HelpSetTitleFont(font);
    return;
  default:
    red_err("Invalid font purpose requested");
  }

  if (fontStructpp != NULL) {

    if (!FontTestWhetherFontNeeded(*fontStructpp))
      XFreeFont(XtDisplay(referenceWidget), *fontStructpp);
    (*fontStructpp) = FontLoadQueryFont(referenceWidget,font);

    if (setWidget != NULL) {
      XtSetArg(arg, XtNfont, *fontStructpp);
      XtSetValues(setWidget, &arg, 1);
    }

    if (setFontHookA != NULL)
      setFontHookA(*fontStructpp);
    if (setFontHookB != NULL)
      setFontHookB(*fontStructpp);

  } else {

    valuesp->font = (FontLoadQueryFont(referenceWidget,font))->fid;
    XChangeGC(XtDisplay(referenceWidget),
	      textGC[GCi%2][GCi/3],
	      GCFont, valuesp);
    GetDefaultCharSizes();
  }
}


/*ARGSUSED*/
void FontViewportSetCoordinates(w, x, y)
  Widget   w;
  Position x;
  Position y;
{
#ifdef HAVE_VIEWPORT_SET_FUNCTIONS

  XawViewportSetCoordinates(w, x, y);

#endif
} 


void FontHighlightCurrent(hlFlags, rsFlag)
  int     hlFlags;	 /* Which bits to highlight? (Family, Purpose, Font) */
  Boolean rsFlag;	 /* Shall I set the relevant Font Toggle widget?     */
{
  Position  x;
  Position  y;
  Dimension hv;
  Dimension ht;
  long int  oht;
  Arg       arg[4];
  int       n;
  int       i;

  if ((hlFlags & HL_FONT) && currentFamily != FAMILY_NONE) {

    i = 0; XtSetArg(arg[i], XtNx,       &x); i++;
           XtSetArg(arg[i], XtNy,       &y); i++;
           XtSetArg(arg[i], XtNheight, &ht); i++;
    XtGetValues(fontToggle[currentFontInFamily[currentFamily]], arg, i);

    i = 0; XtSetArg(arg[i], XtNheight, &hv); i++;
    XtGetValues(fontToggleViewport, arg, i);

    if (rsFlag &&
	fontList[currentFamily][currentFontInFamily[currentFamily]].refer)
      XawToggleSetCurrent
	(fontToggle[0],
	 fontList[currentFamily][currentFontInFamily[currentFamily]].refer);

    if (((Dimension)y + ht/2) > (hv/2))
      FontViewportSetCoordinates(fontToggleViewport, x, y + ht/2 - hv/2);
    else
      FontViewportSetCoordinates(fontToggleViewport, x, 0);
  }

  if ((hlFlags & HL_FAMILY) && currentFamily != FAMILY_NONE) {

    i = 0; XtSetArg(arg[i], XtNheight,       &ht); i++;
           XtSetArg(arg[i], XtNnumberStrings, &n); i++;
    XtGetValues(fontFamilyListList, arg, i);

    i = 0; XtSetArg(arg[i], XtNheight, &hv); i++;
    XtGetValues(fontFamilyListViewport, arg, i);

    XawListHighlight(fontFamilyListList, currentFamily);

    oht = (((unsigned long int)((unsigned)ht))/n) * currentFamily;
    if (((Dimension)oht + (ht/(2*n))) > (hv/2))
      FontViewportSetCoordinates(fontFamilyListViewport, 0,
				 (Dimension)oht + (ht/(2*n)) - hv/2);
    else
      FontViewportSetCoordinates(fontFamilyListViewport, 0, 0);
  }

  if (hlFlags & HL_PURPOSE) {

    i = 0; XtSetArg(arg[i], XtNheight,       &ht); i++;
           XtSetArg(arg[i], XtNnumberStrings, &n); i++;
    XtGetValues(fontPurposeListList, arg, i);

    i = 0; XtSetArg(arg[i], XtNheight, &hv); i++;
    XtGetValues(fontPurposeListViewport, arg, i);

    XawListHighlight(fontPurposeListList, currentPurpose);

    oht = ((long int)ht) * currentPurpose;
    if (((Dimension)(oht/n) + (ht/(2*n))) > (hv/2))
      FontViewportSetCoordinates(fontPurposeListViewport, 0,
				 (Dimension)(oht/n) + (ht/(2*n)) - hv/2);
    else
      FontViewportSetCoordinates(fontPurposeListViewport, 0, 0);
  }
}


/* Invent a suitable name by which to refer to a font in the font list */
/* window.  If the name isn't XLFD-compliant, only make a token effort */
/* This function requires that the "properties" and "size" fields in   */
/* the FontNS structure for the font be correctly filled in already    */

char *FontMakeAlias(family, iX)
  int family;
  int iX;
{
  int      i, j;
  char    *alias;
  char    *name;

  name = fontList[family][iX].name;

  if (name[0] != '-') {		/* non-XLFD-compliant name */

    alias = (char *)XtMalloc(strlen(name) + 2);

    for (i = 0; name[i] && isalpha(name[i]); ++i) alias[i] = name[i];
    if  (i > 0 && islower(alias[0])) alias[0] = toupper(alias[0]);

    if (name[i]) {

      if (isdigit(name[j=i])) alias[j++] = '-';
      while (name[i]) alias[j++] = name[i++];
      alias[j] = 0;

    } else alias[i] = 0;

  } else {

    int      size;
    char    *famn;
    char    *foun;
    char    *extr;
    unsigned prop;

    famn  = fontFamilyName[family];

    for (i = 1; name[i] && name[i] != '-'; ++ i);
    if (name[i]) {

      foun = (char *)XtMalloc(i);
      for (j = 1; j < i; ++ j) foun[j-1] = name[j];
      if  (j > 1 && islower(foun[0])) foun[0] = toupper(foun[0]);
      foun[i-1] = 0;

    } else foun = XtNewString("somebody");

    if  ((prop = fontList[family][iX].properties) & FontBold)
      if (prop & FontSlanted) extr = XtNewString(" bold italic");
      else                    extr = XtNewString(" bold");
    else
      if (prop & FontSlanted) extr = XtNewString(" italic");
      else                    extr = XtNewString("");

    if (fontList[family][iX].size == -1) {

      alias= (char *)XtMalloc(strlen(famn) + strlen(foun) + strlen(extr) + 14);
      sprintf(alias, "%s %dpt %s%s", foun, FontGetListedSize(family, iX),
	      famn, extr);

    } else {

      size = fontList[family][iX].size;
      alias= (char *)XtMalloc(strlen(famn) + strlen(foun) + strlen(extr) + 33);

      if (size > 0) {
	sprintf(alias, "%s %dpt %s%s (scalable)",  foun, size, famn, extr);
      } else {
	sprintf(alias, "%s scalable %s%s, default size", foun, famn, extr);
      }
    }

    XtFree(foun);
    XtFree(extr);
  }

  return alias;
}



/* Rescale all scalable fonts in current family to the given pixel size */

void FontRescaleCurrentFamily(scale)
  int scale;
{
  int           i, j, k, n, m;
  Arg           arg[3];
  char        * name;
  char        * newname;
  Boolean       wasm;
  XFontStruct * fsP;

  for (k = 0; k < fontFamilySize[currentFamily]; ++k) {

    /* Is the font scalable? Could it be XLFD-compliant? */

    if (fontList[currentFamily][k].size >= 0 &&
	(name = fontList[currentFamily][k].name)[0] == '-') {

      /* Scan along for pixel size field, and if it's there, operate */

      for (i = j = 1; name[i] && j < 7; ++i) if (name[i] == '-') ++j;
      if (name[i] && isdigit(name[i])) {

	newname = (char *)XtMalloc(strlen(name) + 4);
	strncpy(newname, name, i);            /* get name up to pixel size */

	for (n = 0, m = i; name[m] && isdigit(name[m]); ++m)
	  n = 10*n + name[m]-'0';             /* read old size, for later  */

	for (j = 1, m += 1; name[m] && j < 4; ++m) if (name[m] == '-') ++j;
	if (!(name[m] && isalpha(name[m]))) {

	  XtFree(newname);	/* Seems it isn't XLFD compliant after all */

	} else {

	  sprintf(newname + i, "%d-0-0-0-%c-0-", scale, name[m]);
				/* Force other sizes to zero for no clash  */

	  for (j = i; newname[j] && !isalpha(newname[j]); ++j);
	                                      /* skip newly written sizes  */
	  if (!newname[j]) {

	    XtFree(newname);                  /* Something else wrong      */

	  } else {

	    strcpy(newname+j+1, name+m+1);    /* and copy rest of the name */

	    if ((wasm = XtIsManaged(fontToggle[k])))
	      XtUnmanageChild(fontToggle[k]);

	    if (n > 0) XtFree(name);
	                         /* true only if already been scaled once, */
				 /* hence safe to free 'cos no longer in   */
				 /* the structure returned from XListFonts */

	    XtFree(fontList[currentFamily][k].alias);
	    fontList[currentFamily][k].name  = newname;
	    fontList[currentFamily][k].size  = scale;
	    fontList[currentFamily][k].alias = FontMakeAlias(currentFamily,k);
	    fontList[currentFamily][k].refer =
	      useAlias ? fontList[currentFamily][k].alias : newname;

	    fsP = FontLoadQueryFont(referenceWidget,newname);
	    XtSetArg(arg[0], XtNfont,  fsP);
	    XtSetArg(arg[1], XtNlabel, fontList[currentFamily][k].refer);
	    XtSetArg(arg[2], XtNwidth, maxToggleWidth);
	    XtSetValues(fontToggle[k], arg, 3);

	    if (wasm) XtManageChild(fontToggle[k]);
	  }
	}
      }
    }
  }
}



void FontDisplayFamily(family,prevFamily)
  int family;                          /* assume widgets are all present */
  int prevFamily;
{
  Arg            arg[5];
  int            i, j;
  XFontStruct  * fontStructp;
  XFontStruct  * oldFontStructp;

  if (prevFamily != FAMILY_NONE) {
    if (XtIsManaged(fontEmptyFamilyLabel))
      XtUnmanageChild(fontEmptyFamilyLabel);
    XtUnmanageChildren(fontToggle, fontFamilySize[prevFamily]);
  } else {
    XtUnmanageChild(fontEmptyFamilyLabel);
    XtSetArg(arg[0], XtNlabel, "No Fonts");
    XtSetValues(fontEmptyFamilyLabel, arg, 1);
  }

  toggleWidth    = 0;
  scalableFamily = False;

  for (j = 0; j < maxFontFamilySize; ++j) {

    if (prevFamily != FAMILY_NONE && j < fontFamilySize[prevFamily]) {

      i = 0; XtSetArg(arg[i], XtNfont, &oldFontStructp); i++;
      XtGetValues(fontToggle[j], arg, i);
    }

    if (family != FAMILY_NONE && j < fontFamilySize[family]) {

      if (fontList[family][j].alias == NULL) {

       	if (FontGetListedSize(family, j) == 0) fontList[family][j].size = 0;
	fontList[family][j].properties = FontGetEmphasisStatus(family, j);
	fontList[family][j].alias      = FontMakeAlias(family, j);
      }	fontList[family][j].refer      =
	  useAlias ? fontList[family][j].alias : fontList[family][j].name;

      if (app_data.scaleFonts && fontList[family][j].size >= 0)
	scalableFamily = True;

      i = 0;
      fontStructp=FontLoadQueryFont(referenceWidget,fontList[family][j].name);

      XtSetArg(   arg[i], XtNfont,       fontStructp               ); i++;
      XtSetArg(   arg[i], XtNlabel,      fontList[family][j].refer ); i++;
      XtSetArg(   arg[i], XtNradioData,  fontList[family][j].refer ); i++;
      XtSetArg(   arg[i], XtNwidth,      maxToggleWidth            ); i++;
      if (j > 0) {
	XtSetArg( arg[i], XtNradioGroup, fontToggle[0]             ); i++;
      }
      XtSetValues(fontToggle[j], arg, i);

      if (!XtIsSensitive(fontShowButton)) FontReleaseOptionButtons();
      FontInstateOptionValues();
    }

    if (prevFamily != FAMILY_NONE && j < fontFamilySize[prevFamily]) {
      /* This seems to be freed too early.  Have to think about that. */
      XFreeFont(XtDisplay(referenceWidget),oldFontStructp);
    } else if (family != FAMILY_NONE && j > fontFamilySize[family]) break;
  }

  if (family != FAMILY_NONE) {

    if ((displayMask & (FontNormal | FontBold | FontSlanted)) ==
                       (FontNormal | FontBold | FontSlanted)) {

      if (fontFamilySize[family] > 0)
	XtManageChildren(fontToggle, fontFamilySize[family]);
      else XtManageChild(fontEmptyFamilyLabel);
      
    } else { 

      for (i = j = 0; i < fontFamilySize[family]; ++i) {
	if (fontList[family][i].properties == displayMask) {
	  XtManageChild(fontToggle[i]);
	  ++ j;
	} else if (XtIsManaged(fontToggle[i])) XtUnmanageChild(fontToggle[i]);
      }

      if (j == 0) XtManageChild(fontEmptyFamilyLabel);
    }
  } else
    XtManageChild(fontEmptyFamilyLabel);
}


void FontCreateFamilyWidgets(number)
  int number;
{
  Arg            arg;
  int            j;
  XtTranslations translations;

  toggleWidth  = 0;
  fontToggle   = (Widget *)XtCalloc(number,sizeof(Widget));
  translations = XtParseTranslationTable("<EnterWindow>: highlight(Always) \n\
   <LeaveWindow>: unhighlight() \n\
   <Btn1Down>,<Btn1Up>: set() notify()");

  for (j = 0; j < number; ++j) {

    XtSetArg(arg, XtNjustify, XtJustifyLeft);

    fontToggle[j] = XtCreateWidget("fontToggle",
				   toggleWidgetClass,
				   fontToggleBox,
				   &arg, 1);

    XtAddCallback(fontToggle[j], XtNcallback, FontToggle, 0);
    XtOverrideTranslations(fontToggle[j], translations);
  }

  XtManageChild(fontEmptyFamilyLabel);
}


void FontDestroyFamilyWidgets(number)
  int number;
{
  Arg           arg;
  int           j;
  XFontStruct * fontStructp;

  for (j = 0; j < number; ++j) {

    XtSetArg(arg, XtNfont, &fontStructp);
    XtGetValues(fontToggle[j], &arg, 1);

    XtDestroyWidget(fontToggle[j]);

    if (currentFamily != FAMILY_NONE && j < fontFamilySize[currentFamily])
      if (!FontTestWhetherFontNeeded(fontStructp))
	XFreeFont(XtDisplay(referenceWidget), fontStructp);
  }
}


void FontSelectorDestroyWidgets() /* Should be called after   */
{				  /* FontDestroyFamilyWidgets */
  XtPopdown(fontShell);

  XtDestroyWidget(fontDoneButton);
  XtDestroyWidget(fontPropagateButton);
  XtDestroyWidget(fontResetButton);
  XtDestroyWidget(fontApplyButton);
  XtDestroyWidget(fontToggleBox);
  XtDestroyWidget(fontToggleViewport);
  XtDestroyWidget(fontPurposeListList);
  XtDestroyWidget(fontPurposeListTitle);
  XtDestroyWidget(fontFamilyListList);
  XtDestroyWidget(fontFamilyListViewport);
  XtDestroyWidget(fontFamilyListTitle);
  XtDestroyWidget(fontForm);
  XtDestroyWidget(fontShell);
  XtDestroyWidget(fontEmptyFamilyLabel);

  if (fontToggle) XtFree((char *)fontToggle);
}


int FontFamilyStrCmp(a,b)	/* Test whether two font family names should */
  char *a;			/* be considered equal in the grand scheme   */
  char *b;			/* of things.                                */
{
  register int  i;
  register char ai;
  register char bi;
  register int  c;

  if (a == b) return 0;

  ai = a[0];
  bi = b[0];

  if      (!ai)
    if    (!bi) return  0;
    else        return -1;
  else if (!bi) return  1;

  if   (islower(ai))
    if (islower(bi)) { if (c = (   (ai) -    (bi))) return c; }
    else             { if (c = (RTU(ai) -    (bi))) return c; }
  else
    if (islower(bi)) { if (c = (   (ai) - RTU(bi))) return c; }
    else             { if (c = (   (ai) -    (bi))) return c; }

  /*
    Right, proceed while there's room in both strings, and neither string
    has reached the hyphen (that ends family name) and either the strings
    are equal, or the first is at start-of-word and it's LC and the UC is
    matched in the second, or the second is LC and the UC is matched in
    the first. I prefer Lisp, myself.
  */

  i = 0;

  do    { ai  = a[++i]; }
  while ((bi  = b[  i]) && ai &&
	 (ai != '-' && bi != '-' &&
	  (ai == bi ||
	   (a[i-1] == ' ' &&	     /* in which case b[i-1] == ' ' also */
	    ((islower(ai) ? RTU(ai) : ai) ==
	     (islower(bi) ? RTU(bi) : bi))
	    ))
	  ));

  if     ((ai == bi) ||
          (!bi && ai == '-') ||
          (!ai && bi == '-')) return  0;
  else if (!ai || ai == '-')  return -1;
  else if (!bi || bi == '-')  return  1;
  else return ((a[i-1] == ' ') ?
	       ((int)(islower(ai) ? RTU(ai) : ai) -
		(int)(islower(bi) ? RTU(bi) : bi)) :
	       ((int)ai - (int)bi));
}



/* Specialised binary search.  Searches for the string s in the array     */
/* fontFamilyName, which is assumed to have size fontFamilyCount.  This   */
/* uses FontFamilyStrCmp as a comparator & returns the index of the found */
/* item; if absent, it returns -(the index where it should be, plus 1).   */
/* For example, searching for "d" in the array { "a", "b", "e", "f" }     */
/* should return -3.  The reason for the plus 1 is so that you can tell   */
/* between "present at index 0" and "not present but should be at 0".     */

int FontFamilySearch(s)
  char *s;
{
  int up;
  int lo;
  int c;
  int n;

  lo = 0;
  up = fontFamilyCount - 1;

  if (up == lo)
    return ((c = FontFamilyStrCmp(s, fontFamilyName[up])) ?
	    ((c < 0) ? -(up+1) : -(up+2)) : up);

  while ((n = (up + lo)/2), (c = FontFamilyStrCmp(s, fontFamilyName[n]))) {

    if (c < 0) up = n; else lo = n+1;
    if (up == lo)
      return ((c = FontFamilyStrCmp(s, fontFamilyName[up])) ?
	      ((c < 0) ? -(up+1) : -(up+2)) : up);
  }
  return n;
}



/* Get the family name from the font name.  The family name is capitalized */
/* prettily, and shared space is used, kept updated, in the array          */
/* fontFamilyName.  Because the uniqueness of the strings is maintained,   */
/* strings returned from this function are stringwise EQUAL iff they are   */
/* pointer EQ, which can speed comparisons.  Ordering family name strings  */
/* from their pointers is not feasible, as the pointers are rearranged     */
/* completely every time a new family is encountered.                      */
/* If the font is found to be in the dotFontFamilyName family, and the     */
/* has requested that such fonts be ignored, it is placed in the Other     */
/* family.  This is not an especially satisfactory solution; it could lead */
/* to some odd effects.                                                    */

/* This function will only insert a new family name into its list if the   */
/* install flag is true; otherwise if the family name is one it doesn't    */
/* know yet it will just return NULL -- not an ideal solution, but for the */
/* moment I think it's all I need.                                         */

char *FontExtractFamilyName(font,install)
  char   *font;
  Boolean install;
{
  register int   i;
  int            j;
  char         * toMatch;
  static size_t  oofl;
  static size_t  dofl;
  static size_t  mofl = 0;
  static char    tempFam[50];
  static Boolean pfd = False;

  if (mofl == 0) {

    mofl = ((oofl = strlen(otherFontFamilyName))  >
	    (dofl = strlen(  dotFontFamilyName))) ? oofl : dofl;
    strncpy(tempFam + mofl - oofl, otherFontFamilyName, oofl);
    tempFam[mofl    ] = ' ';
    tempFam[mofl + 1] = '[';
  }

  if (font[0] == '-') {

    for (i = 1; font[i] && font[i] != '-'; ++i);

    if (font[i] && font[i+1] && font[i+1] != '-') toMatch = font + i + 1;
    else toMatch = otherFontFamilyName;

  } else {

    for (i = 0; i < (45-mofl) && font[i] && isalpha(font[i]); ++i)
      tempFam[i + 2 + mofl] =
	(i > 0 || !islower(font[i])) ? font[i] : RTU(font[i]);

    if (i > 0) {

      tempFam[i + 2 + mofl] = ']';
      tempFam[i + 3 + mofl] = 0x0;

      /* Note: TeX font family name code currently omitted (owing to small */
      /* incompatibilities with sorting code).  It may be reinstated.  For */
      /* the moment, TeX fonts will be filed under Various.                */

      if (pfd) {
	pfd     = False;
	strncpy(  tempFam + mofl - oofl, otherFontFamilyName, oofl);
      } toMatch = tempFam + mofl - oofl;
    } else toMatch = otherFontFamilyName;
  }

  /* This next loop should drop out and return most of the time; the */
  /* rest should only be followed once for each distinct font family */

  if (fontFamilyCount > 0)
    if ((i = FontFamilySearch(toMatch)) > -1)
      return fontFamilyName[i];
    else j = (-i) - 1;
  else j = 0;

  /* We should only get here if the font is unlisted. */

  if (install) {

    if (fontFamilyCount >= MAXFAMILIES - 1) red_err("Too many font families");
    if (fontFamilyCount > j)
      for (i = fontFamilyCount; i > j; --i)
	fontFamilyName[i] = fontFamilyName[i-1];

    for (i = 0; toMatch[i] && toMatch[i] != '-'; ++i);
    if (i == 0) fontFamilyName[j] = XtNewString("");
    else {

      if (toMatch == otherFontFamilyName ||
	  toMatch ==   dotFontFamilyName)
	fontFamilyName[j] = toMatch;
      else {

	fontFamilyName[j]    = (char *)XtMalloc(i + 1);
	fontFamilyName[j][i] = 0x0;
	fontFamilyName[j][0] = (islower(toMatch[0]) ?
				RTU(toMatch[0]) : toMatch[0]);

	while (--i > 0) {

	  if (toMatch[i-1] == ' ' && islower(toMatch[i]))
	    fontFamilyName[j][i] = RTU(toMatch[i]);
	  else
	    fontFamilyName[j][i] =     toMatch[i];
	}
      }
    }

    fontFamilyCount ++;
    return fontFamilyName[j];

  } else return NULL;
}



int FontCompare(a,b)
  char *a;
  char *b;
{
  char       * ca;
  char       * cb;
  register int i;

  if (a == b) return 0;

  if   (!a || !(*a)) 
    if (!b || !(*b)) return  0;
    else             return -1;
  else
    if (!b || !(*b)) return  1;

  /* Note that the following two (commented-out) lines apparently form */
  /* part of one of my least favourite bugs in the whole wide world. I */
  /* suspect that there's something in FontExtractFamilyName that will */
  /* not cooperate properly with qsort.  God only knows what.  In the  */
  /* end I've found myself forced to do a naive family-name cut (the   */
  /* two blocks below) and leave the calls to FontExtractFamilyName to */
  /* the separate categorising process later in installFontSelector.   */
  /* This seems (at the moment) to stabilise things a bit.  If anyone  */
  /* ever discovers what the bug actually is here, I'd love to know.   */
  /*     -- Chris Cannam, May 1993                                     */

  /* If the family names differ, return accordingly.                   */

  if (a[0] == '-') {
    for ( i = 1; a[i  ] && a[i  ] != '-'; ++i);
    if (a[i] &&  a[i+1] && a[i+1] != '-') ca = a + i + 1;
    else ca = otherFontFamilyName;
  } else ca = otherFontFamilyName;

  if (b[0] == '-') {
    for ( i = 1; b[i  ] && b[i  ] != '-'; ++i);
    if (b[i] &&  b[i+1] && b[i+1] != '-') cb = b + i + 1;
    else cb = otherFontFamilyName;
  } else cb = otherFontFamilyName;

  if (ca == otherFontFamilyName &&
      cb == otherFontFamilyName)
    return strcmp(a,b);

  i = FontFamilyStrCmp(ca,cb);
  if (i) return i;

  /* Find the first sequence of digits in a;                          */
  /* if there is such a string, find one in b as well; compare the    */
  /* decimal numbers they represent, and if they differ, return       */
  /* accordingly.  This is done on the assumption that the first      */
  /* digit sequence in the font name represents the size of the font. */
  /* If one contains digits but the other doesn't, consider the one   */
  /* without digits to be lexographically inferior to the one with.   */
  /* (We could still have problems with different numbering systems   */
  /* comparing differently -- points vs. pixels, &c. --; if this is   */
  /* a real problem I'll be surprised.)                               */

  {
    int     na = 0;
    int     nb = 0;
    Boolean da;
    Boolean db;

    if (ca == dotFontFamilyName) {

      for (i = 1; a[i] && a[i-1] != '.'; ++i);
      if (da = a[i]) na = 10 * atoi(a+i);

      for (i = 1; b[i] && b[i-1] != '.'; ++i);
      if (db = b[i]) nb = 10 * atoi(b+i);
    }

    for (i = 0; a[i] && !isdigit(a[i]); ++i);
    if (da = a[i]) na += atoi(a+i);

    for (i = 0; b[i] && !isdigit(b[i]); ++i);
    if (db = b[i]) nb += atoi(b+i);

    if (da) {
      if (db && (na != nb)) return na - nb;
      else if (!db) return  1;
    } else if ( db) return -1;

    /* We've now established that [i) a and b are from the same family; */
    /* [ii) either neither has numbers in its name, or the first        */
    /* numbers found in the names of both are equal, which probably     */
    /* means they have the equal point-size specifications.  Given two  */
    /* fonts of equal sizes from the same family, or of indeterminate   */
    /* sizes, we might as well sort them lexographically.  In fact do   */
    /* it in reverse order (better to have, for instance, italics after */
    /* regular (`r'), and bold after medium or demibold) if the names   */
    /* begin with a hyphen (assumed therefore to conform to the X       */
    /* recommended naming standard), and in forward order (consider eg. */
    /* `lucidasans-18' vs. `lucidasans-bold-18') otherwise.             */

    if (a[0] == '-' && b[0] == '-')
      return (-strcmp( a+1 , b+1 ));
    else
      return ( strcmp( a   , b   ));
  }
}


int FontCompareP(a,b)
  char *a;
  char *b;
{
  return FontCompare(*((char **)a),*((char **)b));
}


int FontToFamily(font,firstFamily)
  char *font;
  int   firstFamily;		/* start counting from here */
{
  int   k;
  int   m = -1;
  char *toMatch;

  if ((toMatch = FontExtractFamilyName(font,False)) == NULL) return m;

  for (k = firstFamily; k < fontFamilyCount; ++k)
    if (fontFamilyName[k] == toMatch) {
      m = k; break;
    }
  return m;
}


int FontToFontInFamily(font, family)
  char *font;
  int   family;
{
  int match = -1;
  int i, j, k;

  if (family >= 0) {

    for (k = 0; k < fontFamilySize[family]; ++k) {

      i = 0; j = 0;

      while (fontList[family][k].name[i] && font[j]) {

	if (font[j] == '*') {

	  while (fontList[family][k].name[i] &&
		 fontList[family][k].name[i] != '-') ++i;

	  while (font[j] &&
		 font[j] != '-') ++j;

	} else
	  if ((isupper(fontList[family][k].name[i]) ?
	       tolower(fontList[family][k].name[i]) :
	       fontList[family][k].name[i]) !=
	      (isupper(font[j]) ?
	       tolower(font[j]) : font[j])) break;
	  else { ++i; ++j; }
      }

      if (!(fontList[family][k].name[i] || font[j])) match = k;
    }
  }
  return match;
}


int FontGetFamilyAndFontNumber(famP,font)
  int  *famP;
  char *font;
{
  int fam;
  int fonn;
  int ffam = 0;

 loop:

  fam  = FontToFamily(font,ffam);
  fonn = FontToFontInFamily(font,fam);

  if (fonn < 0 && fam >= 0 && ffam < fontFamilyCount)
    { ffam = fam + 1; goto loop; }

  if (fonn < 0) {

    if (!strcmp(font,DEFAULTFONT)) {

      if (quietMode) fprintf(stderr,"XR: Can't locate default font");
      else {
	fprintf(stderr,"XR: Can't locate default font \"%s\"; sorry\n",
		DEFAULTFONT);
	fprintf(stderr,"XR: Copping out and returning \"%s\"\n",
		fontList[0][0].name);
      } fam = fonn = 0;

    } else {
      if (!quietMode)
	fprintf(stderr,"XR: Can't locate font \"%s\"; trying \"%s\".\n",
		font, DEFAULTFONT);
      return FontGetFamilyAndFontNumber(famP, DEFAULTFONT);
    }
  }

  if (famP) *famP = fam;
  return fonn;
}


int FontGetActualSize(family, fontNo)
  int family;
  int fontNo;
{
  Arg           arg[2];
  int           i;
  int           sz;
  XFontStruct * fontStructp;

  if ((family == currentFamily) && (fontToggle != NULL)) {

    i = 0; XtSetArg(arg[i], XtNfont, &fontStructp); i++;
    XtGetValues(fontToggle[fontNo], arg, i);
    sz = fontStructp->ascent + fontStructp->descent;

  } else {

    fontStructp =
      FontLoadQueryFont(referenceWidget,fontList[family][fontNo].name);
    sz = fontStructp->ascent + fontStructp->descent;
    if (!FontTestWhetherFontNeeded(fontStructp))
      XFreeFont(XtDisplay(referenceWidget), fontStructp);
  }

  return sz;
}


int FontToActualSize(font)
  char *font;
{
  int           sz;
  XFontStruct * fontStructp;

  fontStructp = FontLoadQueryFont(referenceWidget,font);
  sz = fontStructp->ascent + fontStructp->descent;
  if (!FontTestWhetherFontNeeded(fontStructp))
    XFreeFont(XtDisplay(referenceWidget), fontStructp);

 return sz;
}


int FontGetNextActualSize(family, iXP)
  int  family;
  int *iXP;
{
  int r;

  (*iXP) = (*iXP) + 1;
  if ((*iXP) >= fontFamilySize[family]) return -1;
  r = FontGetActualSize(family, *iXP);

  return r;
}


int FontGetListedSize(family, fontNo)
  int family;
  int fontNo;
{
  char *font;
  int   i, j;

  font = fontList[family][fontNo].name;

  if (font[0] == '-') {

    for (i = j = 1; font[i] && j < 7; ++i) if (font[i] == '-') ++j;
    if (font[i] && isdigit(font[i])) return atoi(font+i);
  }

  for (i = 0; font[i] && !isdigit(font[i]); ++i);
  if (!(font[i])) return 0;
  else return atoi(font+i);
}


int FontGetNextListedSize(family, iXP)
  int  family;
  int *iXP;
{
  int r;

  (*iXP) = (*iXP) + 1;
  if ((*iXP) >= fontFamilySize[family]) return -1;
  r = FontGetListedSize(family, *iXP);

  return r;
}


int FontGetEmphasisStatus(family, iX)
  int family;
  int iX;
{
  unsigned *fpr;

  if (!*(fpr = &(fontList[family][iX].properties))) {

    char *font;
    char *fpt;
    int   i = 1;

    font = fontList[family][iX].name;

    if (font[0]  == '-') {

      for (  fpt = font + 1; fpt && i < 4; ++ fpt)
	if (*fpt == '-') ++i;

      if   (*fpt) {

	if (!strncasecmp(fpt,"i-" ,2)  ||
	    !strncasecmp(fpt,"o-" ,2)  ||
	    !strncasecmp(fpt,"ri-",3)  ||
	    !strncasecmp(fpt,"ro-",3)) *fpr |= FontSlanted;
      }

    } else {
  
      if (strstr(font,"italic" ) ||
	  strstr(font,"oblique")) *fpr |= FontSlanted;
    } if (strstr(font,"bold"))    *fpr |= FontBold;

    if (!(*fpr & (FontSlanted | FontBold))) *fpr |= FontNormal;
  }

  return (*fpr) ;
}



/*
   Code to handle the Font Propagation Three-Year Plan.  This is a scheme
   whereby the user should be able to choose one (or two, or three, or
   however many) font(s), and press a button and let XReduce choose the
   rest automatically.  A Good Idea from Herbert.
*/

char *FontPropChooseFont(current, family, full, minB, maxB, eF, sizeFinder)
  int    current;
  int    family;
  double full;
  int    minB;
  int    maxB;
  int    eF;
  int  (*sizeFinder)();
{
  int lower;
  int upper;
  int liX;
  int uiX;
  int ciX;
  int reqd;
  int this;
  int got;

  lower = upper = -1;
  ciX   = 0;
  reqd  = (int)(((full * (double)(pList[current].ideal)) / 100.0) + 0.5);

  /* It would be quicker to choose the first font in the family that meets */
  /* the specification, or the first of those that meet it equally well;   */
  /* in fact we will choose the *last* of the possible fonts.  Firstly, it */
  /* shouldn't be much slower; and secondly, later fonts are often better  */
  /* quality (honest! You sometimes get a higher point size for your pixel */
  /* size, which is often a sign of a better quality font)                 */

  while ((this = sizeFinder(family, &ciX)) > -1) {

    if (eF == FontGetEmphasisStatus(family, ciX)) {

      if (this == reqd) {
	lower = upper = this;
	liX   = uiX   = ciX;
      } else if ((this > reqd) &&
		 ((maxB  ==  0) || (this <  maxB)) &&
		 ((upper == -1) || (this <= upper))) {
	upper = this;
	uiX   = ciX;
      } else if ((this < reqd) &&
		 ((minB  ==  0) || (this >  minB)) &&
		 ((lower == -1) || (this >= lower))) {
	lower = this;
	liX   = ciX;
      }
    }
  }

  if      (lower == -1 && upper == -1) return NULL;
  else if (lower == -1) got = uiX;
  else if (upper == -1) got = liX;
  else if (lower == reqd || ((reqd-lower) < (upper-reqd))) got = liX;
  else got = uiX;

  return XtNewString(fontList[family][got].name);
}


/*ARGSUSED*/
void FontPropagateButton(w, n, m)
  Widget w;
  caddr_t n, m;
{
  int     pClass;
  int     cStart;
  int     ref = -1;
  int     current;
  int     family;
  int     refFonN;
  int     maxB;
  int     minB;
  int     i,j,k;
  int     eF;
  int   (*sizeFinder)();
  char   *provisionalFont;
  char   *chosenFont[NO_OF_PURPOSES];
  double  full;

  pClass = 0;
  for (i = 0; i < NO_OF_PURPOSES; ++i) chosenFont[i] = NULL;

 doClass:

  for (i = 0; i < NO_OF_PURPOSES && pList[i].class != pClass; ++i);
  if  (i == NO_OF_PURPOSES) goto chosen;
  cStart  = i;
  current = i - 1;

  for ( ; i < NO_OF_PURPOSES; ++i)
    if (pList[i].class == pClass && pList[i].changed) {
      ref = i; break;
    }

  if (i == NO_OF_PURPOSES) {

    if (!(pList[cStart].inherit)) {
      pClass ++;
      goto doClass;
    }

    for (i = j = 0, k = -1; i < NO_OF_PURPOSES; ++i)
      if (pList[i].changed && pList[i].class > k) k = pList[j=i].class;
    if (j == -1) goto chosen;
    ref = j;

    refFonN = FontGetFamilyAndFontNumber(&family, pList[cStart].selected);
    eF      = FontGetEmphasisStatus(family, refFonN);

  } else {

    refFonN = FontGetFamilyAndFontNumber(&family, pList[ref].selected);
    eF      = FontGetEmphasisStatus(family, refFonN);
  }

  madeChanges = True;

  if (family == currentFamily) {
    full = ((double)(pList[ref].actual) * 100.0) / (double)(pList[ref].ideal);
    sizeFinder = FontGetNextActualSize;
  } else {
    full = ((double)(pList[ref].listed) * 100.0) / (double)(pList[ref].ideal);
    sizeFinder = FontGetNextListedSize;
  }

 doPurpose:

  for (i = current+1; i < NO_OF_PURPOSES; ++i)
    if (pList[i].class == pClass && !pList[i].changed) {
      current = i; break;
    }

  if (i == NO_OF_PURPOSES) {
    pClass ++; goto doClass;
  }

  maxB = minB = 0;
  provisionalFont = NULL;

  if      (pList[ref].ideal == pList[current].ideal &&
	   pList[ref].class == pList[current].class)
    provisionalFont = XtNewString(pList[ref].selected);
  else if (pList[ref].ideal  > pList[current].ideal)
    maxB = (family == currentFamily) ? pList[ref].actual : pList[ref].listed;
  else 
    minB = (family == currentFamily) ? pList[ref].actual : pList[ref].listed;

  if (!provisionalFont) provisionalFont =
    FontPropChooseFont(current,family,full,minB,maxB,eF,sizeFinder);
  if ( provisionalFont) chosenFont[current] = provisionalFont;

  goto doPurpose;

 chosen:

  for (i = 0; i < NO_OF_PURPOSES; ++i) {
    if (chosenFont[i]) {
      oldFont[i] = pList[i].selected;
      pList[i].selected = chosenFont[i];
    } else oldFont[i] = NULL;
  }

  FontInstallVerifier("Results of Propagation:", "Shall I Apply these?",
		      FontPropYes, FontPropNo, True, True);
}


/*ARGSUSED*/
void FontPropYes(w, n, m)
  Widget w;
  caddr_t n,m;
{
  int i;

  XtPopdown(fontVerifyShell);
  XtDestroyWidget(fontVerifyShell);
  XtSetSensitive(fontPropagateButton, True);
  XtSetSensitive(fontApplyButton,     True);
  XtSetSensitive(fontResetButton,     True);
  XtSetSensitive(fontDoneButton,      True);

  for(i = 0; i < NO_OF_PURPOSES; ++i) {
    FontSetFont((FontPurpose)i, pList[i].selected);
    if (pList[i].proposed) XtFree(pList[i].proposed);
    pList[i].proposed = XtNewString(pList[i].selected);
    if (oldFont[i]) {
      XtFree(oldFont[i]);
      oldFont[i] = NULL;
    }
  }
}


/*ARGSUSED*/
void FontPropNo(w, n, m)
  Widget w;
  caddr_t n,m;
{
  int i;

  XtPopdown(fontVerifyShell);
  XtDestroyWidget(fontVerifyShell);
  XtSetSensitive(fontPropagateButton, True);
  XtSetSensitive(fontApplyButton,     True);
  XtSetSensitive(fontResetButton,     True);
  XtSetSensitive(fontDoneButton,      True);

  for(i = 0; i < NO_OF_PURPOSES; ++i) {
    if (oldFont[i]) {
      if (pList[i].selected) XtFree(pList[i].selected);
      pList[i].selected = oldFont[i];
      oldFont[i] = NULL;
    }
  }
}



void FontDoneCancel()
{
  XtPopdown(fontVerifyShell);
  XtDestroyWidget(fontVerifyShell);
  XtSetSensitive(fontPropagateButton, True);
  XtSetSensitive(fontApplyButton,     True);
  XtSetSensitive(fontResetButton,     True);
  XtSetSensitive(fontDoneButton,      True);

  FontDestroyFamilyWidgets(maxFontFamilySize);
  FontSelectorDestroyWidgets();
  fontSelectorActive = False;
}


/*ARGSUSED*/
void FontDoneNoSave(w, n, m)
  Widget w;
  caddr_t n,m;
{
  FontDestroyFamilyWidgets(maxFontFamilySize);
  FontSelectorDestroyWidgets();
  fontSelectorActive = False;
}


void FontDoneSaveAux(name, fptr)
  char *name;
  FILE *fptr;
{
  int i;

  if (!name || !fptr) {
    FontDoneCancel();
    return;
  }

  fputs("\n", fptr);
  for (i = 0; i < NO_OF_PURPOSES; ++i)
    fprintf(fptr, "xr*%s:  \t%s\n", pList[i].resource, pList[i].selected);
  fclose(fptr);

  FontDoneCancel();
}


void FontDoneSave(w, n, m)
  Widget w;
  caddr_t n,m;
{
  FileSetFonts(fontVerifyShell, buttonFont, helpXmplFont);
  FileGetFilename(fontVerifyShell, "Select Xdefaults file for appending...",
		  "Can't get list of possible defaults files",
"$HOME/.xrdefaults|$reduce/xr/doc/defaults|$reduce/xr/defaults|\
$reduce/xr/bin/defaults|$reduce/xr/src/defaults|$reduce/defaults|\
$reduce/.xrdefaults",
		  "a", NULL, False, True,
		  FontDoneSaveAux);
}


/*ARGSUSED*/
void FontDoneButton(w, n, m)
  Widget  w;
  caddr_t n,m;
{
  if (madeChanges) {

    FontInstallVerifier("The following fonts are selected:",
			"Do you want to save them in your Xdefaults file?",
			FontDoneSave, FontDoneCancel, False, False);

  } else FontDoneNoSave(fontVerifyNoButton, 0, 0);
}



/* This function isn't really the Done Button Action -- it's the Delete  */
/* Window action, which aims to clear out the window reasonably safely   */
/* but as quickly as possible, and therefore doesn't pop up the verifier */
/* window or anything like that.                                         */

/* ARGSUSED */
void FontDoneButtonAction(w, event)
  Widget w;
  XButtonEvent *event;
{
  FontDoneNoSave(fontVerifyNoButton, 0, 0);
}



void FontDisplayAndHighlightFamilyAndFont(prevFamily)
  int prevFamily;
{
  Arg arg;

  FontDisplayFamily(currentFamily,prevFamily);
  FontHighlightCurrent(HL_FONT, True);

  XtSetArg(arg, XtNcursor, normalCursor);
  XtSetValues(amendedWidget, &arg, 1);

  amendedWidget = NULL;
}



void FontNoDoubleClick(client_data)
  caddr_t client_data;
{
  doubleClicking = False;
  FontHighlightCurrent(client_data, True);
}


/*ARGSUSED*/
void FontFamilyListList(w, n, d)
  Widget                w;
  caddr_t               n;
  XawListReturnStruct * d;
{
  int    prevFamily;
  Cursor tempCursor;
  Arg    arg;

  prevFamily    = currentFamily;
  currentFamily = d->list_index;

  if (prevFamily  != currentFamily) {

    if (amendedWidget == NULL) {

      amendedWidget = w;

      XtSetArg(arg, XtNcursor, &tempCursor);
      XtGetValues(amendedWidget, &arg, 1);

      if (tempCursor != watchCursor)
	normalCursor  =  tempCursor;

      XtSetArg(arg, XtNcursor, watchCursor);
      XtSetValues(amendedWidget, &arg, 1);

      XSync(XtDisplay(referenceWidget), False);
    }

    XtAppAddTimeOut(app_ctxt, 50,
		    FontDisplayAndHighlightFamilyAndFont,
		    (caddr_t) prevFamily);

    XtAppAddTimeOut(app_ctxt, app_data.multiClickTime,
		    FontNoDoubleClick, (caddr_t) HL_FAMILY);
  }
}


char *FontUnalias(family, font)
  int   family;
  char *font;
{
  int   i;
  char *name = NULL;

  if (font == NULL)		/* Experience shows that this is possible.  */
				/*  It's certainly a bug; if more problems  */
				/*  crop up, I'll have to investigate...    */

    return DEFAULTFONT;		/* Experience also shows that in such cases */
				/*  it doesn't seem to matter what value    */
				/*  you return, so long as it's something   */

  if (useAlias) {

    for (i = 0; i < fontFamilySize[family]; ++i)
      if (font == fontList[family][i].alias) name = fontList[family][i].name;

    if (name == NULL) {

      if (!quietMode)
	fprintf(stderr,"XR: Can't locate font alias \"%s\"; using \"%s\".\n",
		font, DEFAULTFONT);

      return DEFAULTFONT;
    } else return name;
  } else return font;
}



/*ARGSUSED*/
void FontPurposeListList(w, n, d)
  Widget                w;
  caddr_t               n;
  XawListReturnStruct * d;
{
  int    prevFamily;
  int    prevFont;
  int    prevPurpose;
  int    tFon;
  int    hlFlags = 0;
  Cursor tempCursor;
  Arg    arg;

  prevPurpose    = currentPurpose;
  currentPurpose = d->list_index;

  if ((prevPurpose == currentPurpose) && (doubleClicking)) {

    doubleClicking = False;
    prevFamily     = currentFamily;
    prevFont       = currentFontInFamily[currentFamily];

    tFon = FontGetFamilyAndFontNumber(&currentFamily,
				      pList[currentPurpose].selected);
    currentFontInFamily[currentFamily] = tFon;

    if ( prevFont    != currentFontInFamily[currentFamily] )
      hlFlags = hlFlags | HL_FONT;

    if ( prevFamily  != currentFamily  ) {

      if (amendedWidget == NULL) {

	amendedWidget = fontPurposeListList;

	XtSetArg(arg, XtNcursor, &tempCursor);
	XtGetValues(amendedWidget, &arg, 1);

	if (tempCursor != watchCursor)
	  normalCursor  =  tempCursor;

	XtSetArg(arg, XtNcursor, watchCursor);
	XtSetValues(amendedWidget, &arg, 1);

	XSync(XtDisplay(referenceWidget), False);
      }

      XtAppAddTimeOut(app_ctxt, 50,
		      FontDisplayAndHighlightFamilyAndFont,
		      (caddr_t) prevFamily);

      hlFlags = hlFlags | HL_FAMILY;
    }
  } else {

    if (XtIsManaged(fontToggle[0])) {

      if (pList[currentPurpose].proposed)
	XtFree(pList[currentPurpose].proposed);
      pList[currentPurpose].proposed =
	XtNewString(FontUnalias(currentFamily,
				XawToggleGetCurrent(fontToggle[0])));
    }

    doubleClicking = True;
    XtAppAddTimeOut(app_ctxt, app_data.multiClickTime,
		    FontNoDoubleClick, (caddr_t) HL_PURPOSE);
  }

  FontHighlightCurrent(hlFlags, True);
}


/*ARGSUSED*/
void FontToggle(w, n, m)
  Widget  w;
  caddr_t n;
  caddr_t m;
{
  char *font;

#ifdef HAVE_VIEWPORT_SET_FUNCTIONS

  font = FontUnalias(currentFamily, XawToggleGetCurrent(w));

  currentFontInFamily[currentFamily] =
    FontGetFamilyAndFontNumber(NULL, font);
      
  if (font) {

    if (pList[currentPurpose].proposed) XtFree(pList[currentPurpose].proposed);
    pList[currentPurpose].proposed = XtNewString(font);

    FontHighlightCurrent(HL_FONT, False);
  }

#else  

  /* This is a bit of a hack for the fact that the translations to ensure  */
  /* that only one of the toggles is set at a time seem to fail on certain */
  /* versions of X.  Clash with the Window Manager Properties, I think.    */
  /* The behaviour that results from this hack is still nasty, and a real  */
  /* solution would be nice.                                               */

  Arg   arg;
  int   cf;

  cf = currentFontInFamily[currentFamily];
  font = FontUnalias(currentFamily, XawToggleGetCurrent(w));

  if (font) {

    if ((currentFontInFamily[currentFamily] =
	 FontGetFamilyAndFontNumber(NULL, font)) != cf) {
      
      XtSetArg(arg, XtNstate, False);
      XtSetValues(fontToggle[cf], &arg, 1);
    }

    if (pList[currentPurpose].proposed) XtFree(pList[currentPurpose].proposed);
    pList[currentPurpose].proposed = XtNewString(font);

    FontHighlightCurrent(HL_FONT, False);
  }

#endif /* HAVE_VEIWPORT_SET_FUNCTIONS */
}


/*ARGSUSED*/
void FontApplyButton(w, n, m)
  Widget  w;
  caddr_t n;
  caddr_t m;
{
  if (currentFamily == FAMILY_NONE) {

    XBell(XtDisplay(referenceWidget), 50);
    return;
  }

  if (pList[currentPurpose].selected &&
      pList[currentPurpose].proposed &&
      strcmp(pList[currentPurpose].selected,pList[currentPurpose].proposed))
    madeChanges = True;

  if (pList[currentPurpose].selected) XtFree(pList[currentPurpose].selected);
  pList[currentPurpose].selected = XtNewString(pList[currentPurpose].proposed);

  pList[currentPurpose].changed  = True;
  pList[currentPurpose].actual   =
    FontGetActualSize(currentFamily, currentFontInFamily[currentFamily]);
  pList[currentPurpose].listed   =
    FontGetListedSize(currentFamily, currentFontInFamily[currentFamily]);

  XStoreBytes(XtDisplay(referenceWidget),
	      pList[currentPurpose].selected,
	      strlen(pList[currentPurpose].selected));

  FontSetFont(currentPurpose, pList[currentPurpose].selected);
}


/*ARGSUSED*/
void FontResetButton(w, n, m)
  Widget  w;
  caddr_t n;
  caddr_t m;
{
  int prevFamily;
  int prevFont;
  int tFon;
  int hlFlags = 0;

  if (pList[currentPurpose].proposed) XtFree(pList[currentPurpose].proposed);
  pList[currentPurpose].proposed = XtNewString(pList[currentPurpose].initial);
  pList[currentPurpose].changed  = False;

  prevFamily     = currentFamily;
  prevFont       = currentFontInFamily[currentFamily];
  tFon           = FontGetFamilyAndFontNumber(&currentFamily,
					      pList[currentPurpose].proposed);
  currentFontInFamily[currentFamily] = tFon;

  pList[currentPurpose].actual =
    FontGetActualSize(currentFamily, currentFontInFamily[currentFamily]);
  pList[currentPurpose].listed =
    FontGetListedSize(currentFamily, currentFontInFamily[currentFamily]);

  if ( prevFont    != currentFontInFamily[currentFamily] )
    hlFlags = hlFlags | HL_FONT;
  if ( prevFamily  != currentFamily  ) {

    FontDisplayFamily(currentFamily,prevFamily);
    hlFlags = hlFlags | HL_FAMILY;
    hlFlags = hlFlags | HL_FONT;
  }

  FontHighlightCurrent(hlFlags, True);
  FontApplyButton(fontApplyButton,0,0);
}


void FontReleaseOptionButtons()
{
  XtSetSensitive(fontShowButton,   True);
  XtSetSensitive(fontAnyButton,    True); 
  XtSetSensitive(fontBoldButton,   True);
  XtSetSensitive(fontItalicButton, True);
  XtSetSensitive(fontScaleButton,  scalableFamily);
}  


void FontInstateOptionValues()
{
  Arg     arg;
  Boolean any;
  Boolean state;

  any = ((displayMask & (FontNormal | FontBold | FontSlanted))
                     == (FontNormal | FontBold | FontSlanted));

  XtSetSensitive(fontScaleButton, scalableFamily);

  if (any) {

    XtSetArg(arg, XtNstate, True);
    XtSetValues(fontAnyButton, &arg, 1);

    XtSetArg(arg, XtNstate, False);
    XtSetValues(fontBoldButton, &arg, 1);
    XtSetValues(fontItalicButton, &arg, 1);

  } else {

    XtSetArg(arg, XtNstate, False);
    XtSetValues(fontAnyButton, &arg, 1);

    XtSetSensitive(fontBoldButton, True);
    XtSetSensitive(fontItalicButton, True);

    if (displayMask & FontBold) {
      XtSetArg(arg, XtNstate, True);
      XtSetValues(fontBoldButton, &arg, 1);
    } else {
      XtSetArg(arg, XtNstate, False);
      XtSetValues(fontBoldButton, &arg, 1);
    }

    if (displayMask & FontSlanted) {
      XtSetArg(arg, XtNstate, True);
      XtSetValues(fontItalicButton, &arg, 1);
    } else {
      XtSetArg(arg, XtNstate, False);
      XtSetValues(fontItalicButton, &arg, 1);
    }
  }
}


void FontAnyButton(a,b,c)
  Widget  a;
  caddr_t b,c;
{
  static preM = FontNormal;

  if ((displayMask & (FontNormal | FontBold | FontSlanted))
                  == (FontNormal | FontBold | FontSlanted))
       displayMask = preM;

  else {

    preM = displayMask;
    displayMask = FontNormal | FontBold | FontSlanted;
  }

  FontInstateOptionValues();
  FontDisplayFamily(currentFamily, currentFamily);
}


void FontBoldButton(a,b,c)
  Widget  a;
  caddr_t b,c;
{
  Arg     arg;
  Boolean state;

  if ((displayMask & (FontNormal | FontBold | FontSlanted))
                  == (FontNormal | FontBold | FontSlanted))
       displayMask = FontBold;
  else displayMask = (displayMask & FontBold) ^ FontBold;

  XtSetArg(arg, XtNstate, &state);
  XtGetValues(fontItalicButton, &arg, 1);
  if (state) displayMask |= FontSlanted;
  if (displayMask == 0) displayMask = FontNormal;

  FontInstateOptionValues();
  FontDisplayFamily(currentFamily, currentFamily);
}


void FontItalicButton(a,b,c)
  Widget  a;
  caddr_t b,c;
{
  Arg arg;
  Boolean state;

  if ((displayMask & (FontNormal | FontBold | FontSlanted))
                  == (FontNormal | FontBold | FontSlanted))
       displayMask = FontSlanted;
  else displayMask = (displayMask & FontSlanted) ^ FontSlanted;

  XtSetArg(arg, XtNstate, &state);
  XtGetValues(fontBoldButton, &arg, 1);
  if (state) displayMask |= FontBold;
  if (displayMask == 0) displayMask = FontNormal;

  FontInstateOptionValues();
  FontDisplayFamily(currentFamily, currentFamily);
}


void FontScaleButton(w,b,c)
  Widget  w;
  caddr_t b,c;
{
  Widget    label;
  Position  x;
  Position  y;

  BEGARG;

  SETARG(fontScaleDialog, XtNlabel, "Scale fonts to point size:");
  SETARG(fontScaleDialog, XtNvalue,                           "");

  XRedTranslateCoords(w, 15, 12, &x, &y, 200, 200);

  SETARG(fontScaleShell, XtNx, x);
  SETARG(fontScaleShell, XtNy, y);

  XtRealizeWidget(fontScaleShell);

  if ((label = XtNameToWidget(fontScaleDialog, "label")) == NULL)
       label = fontScaleCancel;

  XRedSizeLabelForLabel(label,           NULL, NULL);
  XRedSizeLabelForLabel(fontScaleCancel, NULL, NULL);

  FINARG;

  XtSetSensitive(fontScaleButton, False);
  XtPopup(fontScaleShell, XtGrabNonexclusive);
  XRaiseWindow(XtDisplay(fontScaleShell), XtWindow(fontScaleShell));
}


void FontScaleApplyAux(newscale)
  caddr_t newscale;
{
  Arg arg;

  FontRescaleCurrentFamily((int)newscale);
  XtSetArg(arg, XtNcursor, normalCursor);
  XtSetValues(fontScaleApply, &arg, 1);
  XtSetSensitive(fontScaleApply, False);
  XtPopdown(fontScaleShell);
  XtSetSensitive(fontScaleApply,  True);
  XtSetSensitive(fontScaleButton, True);
  XtUnrealizeWidget(fontScaleShell);
  XRaiseWindow(XtDisplay(fontShell), XtWindow(fontShell));
}
  

void FontScaleApply(w,d,c)
  Widget  w;
  Widget  d;
  caddr_t c;
{
  Arg    arg;
  int    newscale;
  char   newstext[20];
  char   complain[20];
  Cursor tempCursor;

  newscale = atoi(XawDialogGetValueString(d));

  if (newscale < 1 || newscale > MAXPIXELSCALE) {

    if (newscale < 1) sprintf(complain, "Minimum is 1");
    else              sprintf(complain, "Maximum is %d", MAXPIXELSCALE);

    XtSetArg(arg, XtNlabel, complain);
    XtSetValues(d, &arg, 1);

    XBell(XtDisplay(w), 80);

  } else {

    XtSetArg(arg, XtNcursor, &tempCursor);
    XtGetValues(fontScaleApply, &arg, 1);

    if (tempCursor != watchCursor)
      normalCursor  =  tempCursor;

    XtSetArg(arg, XtNcursor, watchCursor);
    XtSetValues(fontScaleApply, &arg, 1);
    XSync(XtDisplay(fontScaleApply), False);

    XtAppAddTimeOut(app_ctxt, 50,
		    FontScaleApplyAux, (caddr_t) newscale);
  }
}


void FontScaleCancel(w,d,c)
  Widget  w;
  Widget  d;
  caddr_t c;
{
  XtSetSensitive(w, False);
  XtPopdown(fontScaleShell);
  XtSetSensitive(w, True);
  XtSetSensitive(fontScaleButton, True);
  XtUnrealizeWidget(fontScaleShell);
  XRaiseWindow(XtDisplay(fontShell), XtWindow(fontShell));
}



void FontShowButton(a,b,c)
  Widget  a;
  caddr_t b,c;
{
  useAlias = !useAlias;
  FontDisplayFamily(currentFamily, currentFamily);
}



void FontSelectorRetry()
{
  FontSelectorDestroyWidgets();
  fontSelectorActive = False;
  if (messageAnswer) installFontSelector();
}


void FontHandleFontSelectorWholeGeometry()
{
  XSizeHints sizeHints;

  sizeHints.flags = PMinSize | PMaxSize;
  sizeHints.min_width  = app_data.fontSelectorWidth;
  sizeHints.max_width  = app_data.fontSelectorWidth;
  sizeHints.min_height = app_data.fontSelectorHeight;
  sizeHints.max_height = app_data.fontSelectorHeight;

  BEGARG;

  SETARG( fontShell, XtNwidth,  app_data.fontSelectorWidth  );
  SETARG( fontShell, XtNheight, app_data.fontSelectorHeight );
  SETARG( fontForm,  XtNspace,                      iPSpace );
  SETARG( fontForm,  XtNvSpace,                     iPSpace );
  SETARG( fontForm,  XtNwidth,  app_data.fontSelectorWidth  );
  SETARG( fontForm,  XtNheight, app_data.fontSelectorHeight );
  SETARG( fontShell, XtNx,                               10 );
  SETARG( fontShell, XtNy,
	 DisplayHeight(XtDisplay(referenceWidget),
		       DefaultScreen(XtDisplay(referenceWidget)))
	 - app_data.fontSelectorHeight - 30);
  FINARG;

  XSetWMNormalHints(XtDisplay(fontShell), XtWindow(fontShell), &sizeHints);
}


void FontHandleFontSelectorSubGeometries()
{
  Dimension ht;
  Dimension hb;
  Dimension hf;
  Dimension wd;
  Dimension sb;
  Dimension sw;
  Dimension ah;
  int       n = 5;

  if (app_data.scaleFonts) n = 6;
  else {
    XtUnmanageChild(fontScaleButton);
    XtUnrealizeWidget(fontScaleButton);
  }

  BEGARG;

  ht = app_data.fontSelectorHeight - iPSpace * 6 - 2;
  wd = app_data.fontSelectorWidth  - iPSpace * 5;
  hb = 26;

  SETARG( fontFamilyListViewport,  XtNallowVert,                     True );
  SETARG( fontPurposeListViewport, XtNallowVert,                     True );
  SETARG( fontToggleViewport,      XtNallowVert,                     True );
  
  SETARG( fontFamilyBox,           XtNwidth,                         wd/2 );
  SETARG( fontFamilyListTitle,     XtNfromHoriz,                     NULL );
  SETARG( fontFamilyListTitle,     XtNfromVert,                      NULL );
  SETARG( fontFamilyListTitle,     XtNhorizDistance,              iPSpace );
  SETARG( fontFamilyListTitle,     XtNvertDistance,               iPSpace );
  SETARG( fontFamilyListTitle,     XtNjustify,            XtJustifyCenter );
  SETARG( fontFamilyListViewport,  XtNfromHoriz,                     NULL );
  SETARG( fontFamilyListViewport,  XtNfromVert,       fontFamilyListTitle );
  SETARG( fontFamilyListViewport,  XtNhorizDistance,              iPSpace );
  SETARG( fontFamilyListViewport,  XtNvertDistance,               iPSpace );
  SETARG( fontFamilyListViewport,  XtNheight,                    (ht*2)/5 );
  SETARG( fontFamilyListViewport,  XtNwidth,             wd/2 - 2*iPSpace );
  
  SETARG( fontPurposeBox,          XtNwidth,                         wd/2 );
  SETARG( fontPurposeListTitle,    XtNfromHoriz,                     NULL );
  SETARG( fontPurposeListTitle,    XtNfromVert,                      NULL );
  SETARG( fontPurposeListTitle,    XtNhorizDistance,              iPSpace );
  SETARG( fontPurposeListTitle,    XtNvertDistance,               iPSpace );
  SETARG( fontPurposeListTitle,    XtNjustify,            XtJustifyCenter );
  SETARG( fontPurposeListViewport, XtNfromHoriz,                     NULL );
  SETARG( fontPurposeListViewport, XtNfromVert,      fontPurposeListTitle );
  SETARG( fontPurposeListViewport, XtNhorizDistance,              iPSpace );
  SETARG( fontPurposeListViewport, XtNvertDistance,               iPSpace );
  SETARG( fontPurposeListViewport, XtNheight,                    (ht*2)/5 );
  SETARG( fontPurposeListViewport, XtNwidth,             wd/2 - 2*iPSpace );

  SETARG( fontApplyButton,         XtNfromHoriz,                     NULL );
  SETARG( fontApplyButton,         XtNfromVert,                      NULL );
  SETARG( fontApplyButton,         XtNhorizDistance,              iPSpace );
  SETARG( fontApplyButton,         XtNvertDistance,           2 + iPSpace );
  SETARG( fontResetButton,         XtNfromHoriz,          fontApplyButton );
  SETARG( fontResetButton,         XtNfromVert,                      NULL );
  SETARG( fontResetButton,         XtNhorizDistance,              iPSpace );
  SETARG( fontResetButton,         XtNvertDistance,           2 + iPSpace );
  SETARG( fontPropagateButton,     XtNfromHoriz,          fontResetButton );
  SETARG( fontPropagateButton,     XtNfromVert,                      NULL );
  SETARG( fontPropagateButton,     XtNhorizDistance,              iPSpace );
  SETARG( fontPropagateButton,     XtNvertDistance,           2 + iPSpace );
  SETARG( fontDoneButton,          XtNfromHoriz,      fontPropagateButton );
  SETARG( fontDoneButton,          XtNfromVert,                      NULL );
  SETARG( fontDoneButton,          XtNhorizDistance,              iPSpace );
  SETARG( fontDoneButton,          XtNvertDistance,           2 + iPSpace );

  XRedSizeLabelForLabel(fontApplyButton,      NULL,  &ah);
  XRedSizeLabelForLabel(fontPurposeListTitle, NULL, NULL);
  XRedSizeLabelForLabel(fontFamilyListTitle,  NULL, NULL);
  hf = (ht*2)/5 + ah + 3 * iPSpace + 2;

  SETARG( fontToggleViewportBox,   XtNwidth,               wd + 2*iPSpace );
  SETARG( fontToggleViewportBox,   XtNheight,  (ht - hf) - hb - 2*iPSpace );
  SETARG( fontSideButtonBox,       XtNfromHoriz,       fontToggleViewport );
  SETARG( fontSideButtonBox,       XtNfromVert,                      NULL );
  SETARG( fontSideButtonBox,       XtNheight,  (ht - hf) - hb - 4*iPSpace );
  SETARG( fontSideButtonBox,       XtNwidth,             wd / n - iPSpace );

  sb = ((((ht - hf) - hb - ((n-1)*2)*iPSpace) / (n-1)) -
	(app_data.scaleFonts ? 0 : 1));
  sw = (wd / 6 - iPSpace * 3) - 3;

  SETARG( fontAnyButton,           XtNborderWidth,                      0 );
  SETARG( fontAnyButton,           XtNfromVert,                      NULL );
  SETARG( fontAnyButton,           XtNhorizDistance,              iPSpace );
  SETARG( fontAnyButton,           XtNvertDistance,               iPSpace );
  SETARG( fontAnyButton,           XtNwidth,                           sw );
  SETARG( fontAnyButton,           XtNheight,                          sb );
  SETARG( fontBoldButton,          XtNborderWidth,                      0 );
  SETARG( fontBoldButton,          XtNfromVert,             fontAnyButton );
  SETARG( fontBoldButton,          XtNhorizDistance,              iPSpace );
  SETARG( fontBoldButton,          XtNvertDistance,               iPSpace );
  SETARG( fontBoldButton,          XtNwidth,                           sw );
  SETARG( fontBoldButton,          XtNheight,                          sb );
  SETARG( fontItalicButton,        XtNborderWidth,                      0 );
  SETARG( fontItalicButton,        XtNfromVert,            fontBoldButton );
  SETARG( fontItalicButton,        XtNhorizDistance,              iPSpace );
  SETARG( fontItalicButton,        XtNvertDistance,               iPSpace );
  SETARG( fontItalicButton,        XtNwidth,                           sw );
  SETARG( fontItalicButton,        XtNheight,                          sb );
  SETARG( fontScaleButton,         XtNborderWidth,                      0 );
  SETARG( fontScaleButton,         XtNfromVert,          fontItalicButton );
  SETARG( fontScaleButton,         XtNhorizDistance,              iPSpace );
  SETARG( fontScaleButton,         XtNvertDistance,               iPSpace );
  SETARG( fontScaleButton,         XtNwidth,                           sw );
  SETARG( fontScaleButton,         XtNheight,                      sb + 1 );
  SETARG( fontShowButton,          XtNborderWidth,                      0 );
  SETARG( fontShowButton,          XtNfromVert,
	         app_data.scaleFonts ? fontScaleButton : fontItalicButton );
  SETARG( fontShowButton,          XtNhorizDistance,              iPSpace );
  SETARG( fontShowButton,          XtNvertDistance,               iPSpace );
  SETARG( fontShowButton,          XtNwidth,                           sw );
  SETARG( fontShowButton,          XtNheight,                      sb + 1 );

  SETARG( fontToggleViewport,      XtNwidth,             (wd * (n-1)) / n );
  SETARG( fontToggleViewport,      XtNheight,  (ht - hf) - hb - 4*iPSpace );
  SETARG( fontToggleViewport,      XtNfromHoriz,                     NULL );
  SETARG( fontToggleViewport,      XtNfromVert,                      NULL );
  SETARG( fontToggleViewport,      XtNhorizDistance,              iPSpace );
  SETARG( fontToggleViewport,      XtNvertDistance,               iPSpace );

  FINARG;
}


void initialiseFontSel(topLevel)
  Widget topLevel;
{
  valuesp = (XGCValues *)XtMalloc(sizeof(XGCValues));
  referenceWidget = topLevel;
}


void installFontSelector()
{
  Arg       arg[5];
  int       i, j, k;
  int       nFonts;
  int       thisFamilySize;
  int       currentFamilyNo;
  char     *currentFamilyName;
  char     *nextFamilyName;
  Atom      wmPrtcls[2];

  fontSelectorActive  = True;
  fontToggle          = NULL;
  madeChanges         = False;

  i = 0; XtSetArg(arg[i], XtNtitle, "XR Font Selector"); i++;

  fontShell = XtCreatePopupShell("font selector",
				 topLevelShellWidgetClass,
				 referenceWidget,
				 arg, i);

  fontForm                = XtCreateManagedWidget("fontForm",
						  boxWidgetClass,
						  fontShell,
						  NULL, 0);

  fontPurposeBox          = XtCreateManagedWidget("fontPurposeBox",
						  formWidgetClass,
						  fontForm,
						  NULL, 0);

  fontFamilyBox           = XtCreateManagedWidget("fontFamilyBox",
						  formWidgetClass,
						  fontForm,
						  NULL, 0);

  fontFamilyListTitle     = XtCreateManagedWidget("fontFamilyListTitle",
						  labelWidgetClass,
						  fontFamilyBox,
						  NULL, 0);

  fontPurposeListTitle    = XtCreateManagedWidget("fontPurposeListTitle",
						  labelWidgetClass,
						  fontPurposeBox,
						  NULL, 0);

  fontFamilyListViewport  = XtCreateManagedWidget("fontFamilyListViewport",
						  viewportWidgetClass,
						  fontFamilyBox,
						  NULL, 0);

  fontFamilyListList      = XtCreateManagedWidget("fontFamilyListList",
						  listWidgetClass,
						  fontFamilyListViewport,
						  NULL, 0);

  fontPurposeListViewport = XtCreateManagedWidget("fontPurposeListViewport",
						  viewportWidgetClass,
						  fontPurposeBox,
						  NULL, 0);

  fontPurposeListList     = XtCreateManagedWidget("fontPurposeListList",
						  listWidgetClass,
						  fontPurposeListViewport,
						  NULL, 0);

  fontToggleViewportBox   = XtCreateManagedWidget("fontToggleViewportBox",
						  formWidgetClass,
						  fontForm,
						  NULL, 0);

  fontToggleViewport      = XtCreateManagedWidget("fontToggleViewport",
						  viewportWidgetClass,
						  fontToggleViewportBox,
						  NULL, 0);

  fontToggleBox           = XtCreateManagedWidget("fontToggleBox",
						  boxWidgetClass,
						  fontToggleViewport,
						  NULL, 0);

  fontSideButtonBox       = XtCreateManagedWidget("fontSideButtonBox",
						  formWidgetClass,
						  fontToggleViewportBox,
						  NULL, 0);

  fontAnyButton           = XtCreateManagedWidget("fontAnyButton",
						  toggleWidgetClass,
						  fontSideButtonBox,
						  NULL, 0);

  fontBoldButton          = XtCreateManagedWidget("fontBoldButton",
						  toggleWidgetClass,
						  fontSideButtonBox,
						  NULL, 0);

  fontItalicButton        = XtCreateManagedWidget("fontItalicButton",
						  toggleWidgetClass,
						  fontSideButtonBox,
						  NULL, 0);

  fontScaleButton         = XtCreateManagedWidget("fontScaleButton",
						  commandWidgetClass,
						  fontSideButtonBox,
						  NULL, 0);

  fontShowButton          = XtCreateManagedWidget("fontShowButton",
						  commandWidgetClass,
						  fontSideButtonBox,
						  NULL, 0);

  fontButtonBox           = XtCreateManagedWidget("fontButtonBox",
						  formWidgetClass,
						  fontForm,
						  NULL, 0);

  fontApplyButton         = XtCreateManagedWidget("fontApplyButton",
						  commandWidgetClass,
						  fontButtonBox,
						  NULL, 0);

  fontResetButton         = XtCreateManagedWidget("fontResetButton",
						  commandWidgetClass,
						  fontButtonBox,
						  NULL, 0);

  fontPropagateButton     = XtCreateManagedWidget("fontPropagateButton",
						  commandWidgetClass,
						  fontButtonBox,
						  NULL, 0);

  fontDoneButton          = XtCreateManagedWidget("fontDoneButton",
						  commandWidgetClass,
						  fontButtonBox,
						  NULL, 0);

  fontEmptyFamilyLabel    = XtCreateManagedWidget("fontEmptyFamilyLabel",
						  labelWidgetClass,
						  fontToggleBox,
						  NULL, 0);

  fontScaleShell          =    XtCreatePopupShell("scale",
						  transientShellWidgetClass,
						  fontScaleButton,
						  NULL, 0);

  fontScaleDialog         = XtCreateManagedWidget("fontScaleDialog",
						  dialogWidgetClass,
						  fontScaleShell,
						  NULL, 0);

  fontScaleApply          = XtCreateManagedWidget("fontScaleApply",
						  commandWidgetClass,
						  fontScaleDialog,
						  NULL, 0);

  fontScaleCancel         = XtCreateManagedWidget("fontScaleCancel",
						  commandWidgetClass,
						  fontScaleDialog,
						  NULL, 0);

  i = 0; XtSetArg(arg[i], XtNfont, buttonFont); i++;
  XtSetValues(fontApplyButton,      arg, i);
  XtSetValues(fontResetButton,      arg, i);
  XtSetValues(fontPropagateButton,  arg, i);
  XtSetValues(fontDoneButton,       arg, i);
  XtSetValues(fontAnyButton,        arg, i);
  XtSetValues(fontBoldButton,       arg, i);
  XtSetValues(fontItalicButton,     arg, i);
  XtSetValues(fontScaleButton,      arg, i);
  XtSetValues(fontShowButton,       arg, i);
  XtSetValues(fontFamilyListTitle,  arg, i);
  XtSetValues(fontPurposeListTitle, arg, i);
  XtSetValues(fontScaleApply,       arg, i);
  XtSetValues(fontScaleCancel,      arg, i);
  i = 0; XtSetArg(arg[i], XtNfont, verbalFont); i++;
  XtSetValues(fontFamilyListList,   arg, i);
  XtSetValues(fontPurposeListList,  arg, i);
  XtSetValues(fontEmptyFamilyLabel, arg, i);
  i = 0; XtSetArg(arg[i], XtNlabel, NOFONTSLABEL); i++;
         XtSetArg(arg[i], XtNborderWidth,      0); i++;
  XtSetValues(fontEmptyFamilyLabel, arg, i);

  if (fullFontList == NULL) {

    fullFontList = XListFonts(XtDisplay(referenceWidget), "*",
			      MAXFONTSINLIST, &nFonts);

    if (fullFontList == NULL) {

      sendAnswersToReduce = False;
      gotMessageHook      = FontSelectorRetry;
      PlaceSomeMessage(fontShell, "Cannot get font information.  Retry?",
		       True, True, False);
      return;
    }

    /* Remove potential TeX or PCF fonts, if so requested                  */

    if (app_data.ignoreTeXFonts) {

      for (i = 0, k = 0; i < nFonts; ++i) {

	if (k != i)
	  fullFontList[k] = fullFontList[i];

	for (j = 0; (fullFontList[k][j] &&
		     fullFontList[k][j] != '.'); ++j);

	if (fullFontList[k][j]) {
	  ++j; while(isdigit(fullFontList[k][j])) ++j;
	  if (fullFontList[k][j]) k++;
	} else k++;
      }

      nFonts = k;
    }

    /* Font list should be sorted, so that the families are all together.  */

    /* This call _should_ also initialise the fontFamilyName array and the */
    /* fontFamilyCount variable; unfortunately as part of the exciting new */
    /* Font Selector Bug Suite, this feature was something of a success.   */
    /* Therefore it doesn't do so any more; these variables are now set up */
    /* -- still passively -- later on, when categorising the fonts.        */

    qsort((char *)fullFontList, (size_t)nFonts, sizeof(char *), FontCompareP);

    /* Count the number of distinct families.  Assume that all fonts in a  */
    /* given family are listed together, which should be true as a         */
    /* consequence of our sorting comparison strategy.                     */

    currentFamilyName   =  NULL;
    nextFamilyName      =  NULL;
    currentFamilyNo     = -1;
    thisFamilySize      =  0;
    maxFontFamilySize   =  1;

    fontFamilySize = (int     *)XtMalloc(MAXFAMILIES * sizeof(int));
    fontList       = (FontNS **)XtMalloc(MAXFAMILIES * sizeof(FontNS *));

    for (i = j = 0; i <= nFonts; ++ i) {

      /* The next line is what gets the fontFamilyName array (&c) set up */

      if (i < nFonts)
        nextFamilyName = FontExtractFamilyName(fullFontList[i],True);
      else
        nextFamilyName = NULL;

      if ((i == nFonts) || (nextFamilyName != currentFamilyName)) {

	if (currentFamilyNo >= 0) {

	  fontFamilySize[currentFamilyNo] = thisFamilySize;

	  fontList[currentFamilyNo] =
	    (FontNS *)XtMalloc(thisFamilySize * sizeof(FontNS));

	  for (k = 0; k < thisFamilySize; ++ k) {

	    fontList[currentFamilyNo][k].name       =  fullFontList[j];
	    fontList[currentFamilyNo][k].alias      =  NULL;
	    fontList[currentFamilyNo][k].refer      =  NULL;
	    fontList[currentFamilyNo][k].properties =  0;
	    fontList[currentFamilyNo][k].size       = -1;
	    ++ j;
	  }
	}

	currentFamilyNo  ++;
	thisFamilySize    = 1;
	currentFamilyName = nextFamilyName;
	
      } else {

	if (++thisFamilySize > maxFontFamilySize)
	   maxFontFamilySize =    thisFamilySize;
      }
    }
  }

  /*
  fprintf(stderr,"currentFamilyNo is %d; fontFamilyCount is %d\n",
	  currentFamilyNo, fontFamilyCount);
  fflush(stderr);
  */

  currentFontInFamily = (int *)XtCalloc(fontFamilyCount, sizeof(int));

  for (i = 0; i < NO_OF_PURPOSES; ++i) {
    if (!(pList[i].initial))
      pList[i].initial  = XtNewString(FontGetInitialFont((FontPurpose)i));
    if (!(pList[i].proposed))
      pList[i].proposed = XtNewString(pList[i].initial);
    if (!(pList[i].selected))
      pList[i].selected = XtNewString(pList[i].initial);
    fontPurposes[i]     = pList[i].purpose;
  }

  for (i = 0; i < fontFamilyCount; ++i)
    currentFontInFamily[i] = 0;

  currentPurpose = 0;
  currentFamily  = FAMILY_NONE;

  for (i = 0; i < NO_OF_PURPOSES; ++i) {
    j = FontGetFamilyAndFontNumber(&k, pList[i].initial);
    pList[i].actual = FontGetActualSize(k, j);
    pList[i].listed = FontGetListedSize(k, j);
  }

  FontCreateFamilyWidgets(maxFontFamilySize);

  i = 0; XtSetArg(arg[i], XtNlist,          fontFamilyName  ); i++;
         XtSetArg(arg[i], XtNnumberStrings, fontFamilyCount ); i++;
  XtSetValues(fontFamilyListList,  arg, i);

  i = 0; XtSetArg(arg[i], XtNlist,          fontPurposes    ); i++;
         XtSetArg(arg[i], XtNnumberStrings, NO_OF_PURPOSES  ); i++;
  XtSetValues(fontPurposeListList, arg, i);

  XtAddCallback(fontAnyButton,       XtNcallback, FontAnyButton,       0);
  XtAddCallback(fontBoldButton,      XtNcallback, FontBoldButton,      0);
  XtAddCallback(fontItalicButton,    XtNcallback, FontItalicButton,    0);
  XtAddCallback(fontScaleButton,     XtNcallback, FontScaleButton,     0);
  XtAddCallback(fontShowButton,      XtNcallback, FontShowButton,      0);
  XtAddCallback(fontDoneButton,      XtNcallback, FontDoneButton,      0);
  XtAddCallback(fontFamilyListList,  XtNcallback, FontFamilyListList,  0);
  XtAddCallback(fontPurposeListList, XtNcallback, FontPurposeListList, 0);
  XtAddCallback(fontApplyButton,     XtNcallback, FontApplyButton,     0);
  XtAddCallback(fontResetButton,     XtNcallback, FontResetButton,     0);
  XtAddCallback(fontPropagateButton, XtNcallback, FontPropagateButton, 0);
  XtAddCallback(fontScaleApply,      XtNcallback, FontScaleApply,      
		fontScaleDialog);
  XtAddCallback(fontScaleCancel,     XtNcallback, FontScaleCancel,     
		fontScaleDialog);

  XtSetSensitive(fontAnyButton,    False);
  XtSetSensitive(fontBoldButton,   False);
  XtSetSensitive(fontItalicButton, False);
  XtSetSensitive(fontScaleButton,  False);
  XtSetSensitive(fontShowButton,   False);

  FontHandleFontSelectorSubGeometries();
  XtRealizeWidget(fontShell);
  FontHandleFontSelectorWholeGeometry();

  wmPrtcls[0] =
    XInternAtom(XtDisplay(fontShell), "WM_DELETE_WINDOW", False);
  wmPrtcls[1] =
    XInternAtom(XtDisplay(fontShell), "WM_SAVE_YOURSELF", False);

  XtOverrideTranslations
    (fontShell,
     XtParseTranslationTable("<Message>WM_PROTOCOLS: reduce-font-done()"));

  XSetWMProtocols(XtDisplay(fontShell), XtWindow(fontShell), wmPrtcls, 2);

  XtPopup(fontShell, XtGrabNone);
  XRaiseWindow(XtDisplay(fontShell), XtWindow(fontShell));

  FontHighlightCurrent(HL_FONT | HL_FAMILY | HL_PURPOSE, True);
}


void FontRealizeAndHandleVerifierGeometry(topLabel, bottomLabel, detailFlag)
  char   *topLabel;
  char   *bottomLabel;
  Boolean detailFlag;
{
  Dimension    isp;		   /* Internal space, all compound widgets  */
  Dimension    bwd;		   /* Border width, all label/box widgets   */
  Dimension    fht;		   /* Height of font display labels         */
  Dimension    bht;		   /* Height of font display box            */
  Dimension    twd;		   /* Total width of display thingy         */
  Dimension    tht;		   /* Total height of display thingy        */
  int          asc;		   /* Ascent of trial font                  */
  int          dsc;		   /* Descent into the depths of Hell       */
  int          dir;		   /* Not to be too poetic about it         */
  XFontStruct *fn[NO_OF_PURPOSES]; /* Nessun maggior dolore, che ricordarsi */
  XCharStruct  ovr;		   /* del tempo felice, and so forth        */
  int          i;
  Position     x;
  Position     ya;
  Position     yb;
  char        *texts[NO_OF_PURPOSES];

  for (i = 0, fht = 0, twd = 0; i < NO_OF_PURPOSES; ++i) {

    if (detailFlag) {

      texts[i] = (char *)XtMalloc(25 + strlen(pList[i].purpose));
      sprintf(texts[i], "%d. %s (%s choice)", i+1, pList[i].purpose,
	      (pList[i].changed) ? "user's" : "my");

    } else {

      texts[i] = (char *)XtMalloc(6 + strlen(pList[i].purpose));
      sprintf(texts[i], "%d. %s", i+1, pList[i].purpose);
    }

    fn[i] = FontLoadQueryFont(referenceWidget,pList[i].selected);

    XQueryTextExtents(XtDisplay(referenceWidget),
		      fn[i]->fid,
		      texts[i], strlen(texts[i]),
		      &dir, &asc, &dsc, &ovr);
    if ((Dimension)(asc + dsc) > fht) fht = asc + dsc;
    if ((Dimension)(ovr.width) > twd) twd = ovr.width;
  }

  XQueryTextExtents(XtDisplay(referenceWidget),
		    buttonFont->fid,
		    topLabel, strlen(topLabel),
		    &dir, &asc, &dsc, &ovr);
  if ((Dimension)(asc + dsc) > fht) fht = asc + dsc;
  if ((Dimension)(ovr.width) > twd) twd = ovr.width;

  XQueryTextExtents(XtDisplay(referenceWidget),
		    buttonFont->fid,
		    bottomLabel, strlen(bottomLabel),
		    &dir, &asc, &dsc, &ovr);
  if ((Dimension)(asc + dsc) > fht) fht = asc + dsc;
  if ((Dimension)(ovr.width) > twd) twd = ovr.width;

  isp  = 4;
  bwd  = 1;
  twd  = twd + isp*3 + bwd*2;
  fht += 2;
  bht  = fht*NO_OF_PURPOSES + isp*(NO_OF_PURPOSES+1) + 2*bwd;
  tht  = fht*3 + 2*bwd + bht + 5*isp;

  BEGARG;

  SETARG( fontVerifyTopLabel, XtNfont,                     buttonFont );
  SETARG( fontVerifyTopLabel, XtNlabel,                      topLabel );
  SETARG( fontVerifyTopLabel, XtNheight,                          fht );
  SETARG( fontVerifyTopLabel, XtNwidth,                           twd );
  SETARG( fontVerifyTopLabel, XtNborderWidth,                       0 );
  SETARG( fontVerifyTopLabel, XtNjustify,             XtJustifyCenter );

  for (i = 0; i < NO_OF_PURPOSES; ++i) {

    SETARG( fontVerifyPurposeLabels[i], XtNfont,                fn[i] );
    SETARG( fontVerifyPurposeLabels[i], XtNlabel,            texts[i] );
    SETARG( fontVerifyPurposeLabels[i], XtNheight,                fht );
    SETARG( fontVerifyPurposeLabels[i], XtNwidth,     twd-isp*2-bwd*2 );
    SETARG( fontVerifyPurposeLabels[i], XtNborderWidth,             0 );
    SETARG( fontVerifyPurposeLabels[i], XtNjustify,   XtJustifyCenter );
  }

  SETARG( fontVerifyShowBox, XtNheight,                           bht );
  SETARG( fontVerifyShowBox, XtNwidth,                            twd );
  SETARG( fontVerifyShowBox, XtNvSpace,                           isp );
  SETARG( fontVerifyShowBox, XtNhSpace,                           isp );
  SETARG( fontVerifyShowBox, XtNborderWidth,                      bwd );

  SETARG( fontVerifyBottomLabel, XtNfont,                  buttonFont );
  SETARG( fontVerifyBottomLabel, XtNlabel,                bottomLabel );
  SETARG( fontVerifyBottomLabel, XtNheight,                       fht );
  SETARG( fontVerifyBottomLabel, XtNwidth,                        twd );
  SETARG( fontVerifyBottomLabel, XtNborderWidth,                    0 );
  SETARG( fontVerifyBottomLabel, XtNjustify,          XtJustifyCenter );

  SETARG( fontVerifyYesButton, XtNfont,                    buttonFont );
  SETARG( fontVerifyYesButton, XtNheight,                         fht );
  SETARG( fontVerifyYesButton, XtNborderWidth,                      0 );
  SETARG( fontVerifyYesButton, XtNjustify,            XtJustifyCenter );

  SETARG( fontVerifyNoButton, XtNfont,                     buttonFont );
  SETARG( fontVerifyNoButton, XtNheight,                          fht );
  SETARG( fontVerifyNoButton, XtNborderWidth,                       0 );
  SETARG( fontVerifyNoButton, XtNjustify,             XtJustifyCenter );

  XtRealizeWidget(fontVerifyShell);
  XtTranslateCoords(fontShell, 60, 23, &x, &ya);
  yb = DisplayHeight(XtDisplay(referenceWidget),
		     DefaultScreen(XtDisplay(referenceWidget))) - tht - 40;
  if (ya > yb) ya = yb;

  SETARG( fontVerifyShell, XtNwidth,                      twd + isp*2 );
  SETARG( fontVerifyShell, XtNheight,                             tht );
  SETARG( fontVerifyBox,   XtNwidth,                      twd + isp*2 );
  SETARG( fontVerifyBox,   XtNheight,                             tht );
  SETARG( fontVerifyShell, XtNx,                                    x );
  SETARG( fontVerifyShell, XtNy,                                   ya );

  FINARG;
}


void FontInstallVerifier(topLabel, bottomLabel,
			 yesCallback, noCallback, detailFlag, deft)
  char   *topLabel;
  char   *bottomLabel;
  void  (*yesCallback)();
  void  (*noCallback)();
  Boolean detailFlag;
  Boolean deft;
{
  int       i;
  int       opx;
  int       opy;
  int       owx;
  int       owy;
  Arg       arg[5];
  Widget    defaultButton;
  Window    discard1;
  Window    discard2;
  Position  x;
  Position  y;
  Position  px;
  Position  py;
  Dimension dh;
  Dimension dw;
  unsigned  keys;

  fontVerifyShell = XtCreatePopupShell("verify",
				       transientShellWidgetClass,
				       fontShell,
				       NULL, 0);

  fontVerifyBox         = XtCreateManagedWidget("fontVerifyBox",
						boxWidgetClass,
						fontVerifyShell,
						NULL, 0);

  fontVerifyTopLabel    = XtCreateManagedWidget("fontVerifyTopLabel",
						labelWidgetClass,
						fontVerifyBox,
						NULL, 0);

  fontVerifyShowBox     = XtCreateManagedWidget("fontVerifyShowBox",
						boxWidgetClass,
						fontVerifyBox,
						NULL, 0);

  fontVerifyBottomLabel = XtCreateManagedWidget("fontVerifyBottomLabel",
						labelWidgetClass,
						fontVerifyBox,
						NULL, 0);

  fontVerifyYesButton   = XtCreateManagedWidget("fontVerifyYesButton",
						commandWidgetClass,
						fontVerifyBox,
						NULL, 0);

  fontVerifyNoButton    = XtCreateManagedWidget("fontVerifyNoButton",
						commandWidgetClass,
						fontVerifyBox,
						NULL, 0);

  for (i = 0; i < NO_OF_PURPOSES; ++i)
    fontVerifyPurposeLabels[i] =
      XtCreateManagedWidget("fontVerifyPurposeLabel",
			    labelWidgetClass,
			    fontVerifyShowBox,
			    NULL, 0);

  FontRealizeAndHandleVerifierGeometry(topLabel, bottomLabel, detailFlag);

  XtAddCallback(fontVerifyYesButton, XtNcallback, yesCallback, 0);
  XtAddCallback(fontVerifyNoButton,  XtNcallback,  noCallback, 0);

  XtSetSensitive(fontPropagateButton, False);
  XtSetSensitive(fontApplyButton,     False);
  XtSetSensitive(fontResetButton,     False);
  XtSetSensitive(fontDoneButton,      False);
  XtPopup(fontVerifyShell, XtGrabNone);
  XRaiseWindow(XtDisplay(fontVerifyShell), XtWindow(fontVerifyShell));

  if (app_data.pointerJump) {

    defaultButton = deft ? fontVerifyYesButton : fontVerifyNoButton;

    i = 0; XtSetArg(arg[i], XtNwidth,  &dw); i++;
           XtSetArg(arg[i], XtNheight, &dh); i++;
           XtSetArg(arg[i], XtNx,       &x); i++;
           XtSetArg(arg[i], XtNy,       &y); i++;
    XtGetValues(defaultButton, arg, i);

    XtTranslateCoords(fontVerifyShell,
		      (Position) (x + dw / 2),
		      (Position) (y + dh / 2 + app_data.kludgeTitleHeight),
		      &px, &py);

    XQueryPointer(XtDisplay(defaultButton),
		  RootWindowOfScreen(XtScreen(defaultButton)),
		  &discard1, &discard2,
		  &opx, &opy,
		  &owx, &owy, &keys);

    XWarpPointer(XtDisplay(defaultButton),
		 RootWindowOfScreen(XtScreen(defaultButton)),
		 RootWindowOfScreen(XtScreen(defaultButton)), opx, opy,
		 DisplayWidth (XtDisplay(defaultButton),
			       DefaultScreen(XtDisplay(defaultButton))),
		 DisplayHeight(XtDisplay(defaultButton),
			       DefaultScreen(XtDisplay(defaultButton))),
		 px, py);
  }
}
