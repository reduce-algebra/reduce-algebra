 
/*
   Graphical module.  Chris Cannam, Berlin 1992-93
*/


#include "xreduce.h"		/* also includes X things and xredres.h */
#include "main.h"		/* basic definitions                    */
#include "widgets.h"
#include "fancy.h"
#include "font.h"
#include "manager.h"
#include "printer.h"

#include <X11/IntrinsicP.h>
#include <X11/CoreP.h>

static Boolean       gotD = False;
static Boolean       oneD;
static unsigned int  howD;

#define CopyArea(s,d,x,y,w,h,X,Y) { if (oneD) { \
    XCopyPlane (display,(s),(d),copyGC,(x),(y),(w),(h),(X),(Y),1); \
  } else { \
    XCopyArea  (display,(s),(d),copyGC,(x),(y),(w),(h),(X),(Y)); } }

char   * fancy_lines[500];
int      fancy_xrange;
int      fancy_yrange;
int      fancy_tab;
int      font_height[2];
int      font_width[2];		/* defined as width of '0', and assumed thus */
int      xOffset;
int      yOffset;
int      boldGraphics;
int      graphIndex = 0;	/* referred to by printer module */
GC    ** textGC;		/* referred to by font selector  */
Boolean  PostScriptMode = False;

void RedrawGraphical();

static GC      drawingGC;
static GC      clearGC;
static GC      copyGC;
static Boolean GCsCreated = False;

static XFontStruct ***textFt;
static Display      * display;
static Dimension      pBlankwd;
static Dimension      pBlankht;
static Pixmap         blankMap = 0;
static Pixmap         buildMap;
static Widget         referenceWidget;
static Font           referenceFont;
static Boolean        errorFlag      = False;
static Boolean        fontLoadFailed = False;
static XFontStruct  * fontSP;

static CoreWidgetClass gWC;

static char *greekLetters[] = {

  "alpha" , "beta" , "chi"     , "delta"   , "epsilon" , "phi"    ,
  "gamma" , "eta"  , "iota"    , "<etwas>" , "kappa"   , "lambda" ,
  "mu"    , "nu"   , "omicron" , "pi"      , "<etwas>" , "rho"    ,
  "sigma" , "tau"  , "upsilon" , "<etwas>" , "omega"   , "xi"     ,
  "psi"   , "zeta" ,
};



OutputPixmapList *outputPixmapList;


/* The warning function isn't exactly efficient, but that's not important */

void warning(s1,s2)
  char *s1;
  char *s2;
{
  char *text;
  char *instance;
  int   len;
  int   i;

  len = 0;

  for (i = 0; fancy_lines[i] != NULL; i++)
    len += strlen(fancy_lines[i]);

  instance = (char *)XtMalloc(len + 1);

  len = 0;

  for (i = 0; fancy_lines[i] != NULL; i++) {
    strcpy(instance + len, fancy_lines[i]);
    len += strlen(fancy_lines[i]);
  }

  instance[len] = 0x0;

  text = (char *)XtMalloc(strlen(s1) +
			  strlen(s2) +
			  len + 100);

  sprintf(text,"\n***** %s: %s [ %s ]\n***** in %s\n",
	  "XR Warning", s1, s2, instance);

  errorFlag = True;
  PlaceSomeLines(text);
}


void QueryCharDimensions(c, ffont, charset, asc, desc,
			 width, height, charSpecific)
  char    c;
  int     ffont;
  int     charset;
  int   * asc;
  int   * desc;
  int   * width;
  int   * height;
  Boolean charSpecific;
{
  int          iasc;
  int          idesc;
  int          direction;
  XCharStruct  information;
  static char *sc = NULL;

  if (!sc) sc = XtNewString(" ");
  *sc = c;

  XTextExtents(textFt[ffont][charset], sc, 1,
	       &direction, &iasc, &idesc, &information);
  
  if (charSpecific) {

    if (asc   )    *asc = information.ascent;
    if (desc  )   *desc = information.descent;
    if (width )  *width = information.width;
    if (height) *height = information.ascent + information.descent;

  } else {

    if (asc   )    *asc = iasc;
    if (desc  )   *desc = idesc;
    if (width )  *width = information.width;
    if (height) *height = iasc + idesc;
  }
}



/* Just a way of trying to ensure that only reasonably valid   */
/* fonts are loaded.  It doesn't work particularly well, which */
/* is not surprising since the logic & code are a bit iffy     */

Font GetFont(widget,name)
  Widget widget;
  char * name;
{
  fontLoadFailed = False;

  if ((fontSP = XLoadQueryFont(XtDisplay(widget),name)) == NULL) {

    fontLoadFailed = True;

    if (!quietMode)
      fprintf(stderr, "XR: No font \"%s\"; trying \"fixed\"\n", name);
    fontSP = XLoadQueryFont(XtDisplay(widget),"fixed");

    if ((fontSP = XLoadQueryFont(XtDisplay(widget),"fixed")) == NULL)
      red_err("Couldn't load default font");
  }

  XFreeFont(XtDisplay(widget),fontSP);

  if (fontLoadFailed) return XLoadFont(XtDisplay(widget),"fixed");
  else                return XLoadFont(XtDisplay(widget),  name );
}



void GetDefaultCharSizes()
{
  int       i;
  XGCValues lookup;

  for (i = 0; i < 6; ++i) {

    if (!(XGetGCValues(display, textGC[i/3][i%3], GCFont, &lookup)))
      red_err("Couldn't refer to graphics context fonts");

    textFt[i/3][i%3] = XQueryFont(display, lookup.font);
  }

  QueryCharDimensions('0',0,0,NULL,NULL,font_width,  font_height,  False);
  QueryCharDimensions('0',1,0,NULL,NULL,font_width+1,font_height+1,False);
}



void setupGraphics(topLevel)
  Widget topLevel;
{
  Arg           arg[3];
  int           i;
  Pixel         fg;
  Pixel         bg;
  XGCValues     values;
  XGCValues     tempValues;
  unsigned long textGCMask;
  unsigned long fullGCMask;

  if (!gotD) {
    howD = DefaultDepthOfScreen(XtScreen(topLevel));
    oneD = (howD == 1); gotD = True;
  }

  fullGCMask = GCFunction | GCPlaneMask | GCForeground | GCBackground;

  if (!GCsCreated) {

    textGC       = (GC **)XtMalloc(2 * sizeof(GC *));
    textGC[0]    = (GC  *)XtMalloc(3 * sizeof(GC  ));
    textGC[1]    = (GC  *)XtMalloc(3 * sizeof(GC  ));

    textFt       = (XFontStruct ***)XtMalloc(2 * sizeof(XFontStruct **));
    textFt[0]    = (XFontStruct  **)XtMalloc(3 * sizeof(XFontStruct  *));
    textFt[1]    = (XFontStruct  **)XtMalloc(3 * sizeof(XFontStruct  *));

    for (i = 0; i < 6; i++) textFt[i/3][i%3] = NULL;

    display         = XtDisplay(topLevel);
    referenceWidget = topLevel;
    referenceFont   = GetFont(topLevel,app_data.normalAsciiFont);

    for (i = 0; i < 6; ++i)
      textGC[i%2][i/2] = XCreateGC(display,
				   RootWindowOfScreen(XtScreen(topLevel)),
				   0, &values);
    textGCMask = GCFont;

     gWC = (CoreWidgetClass)XtMalloc(sizeof(struct _WidgetClassRec));
    *gWC = *coreWidgetClass;
     gWC->core_class.expose = RedrawGraphical;
    
  } else {

    XFreeGC(display,clearGC);
    XFreeGC(display,drawingGC);
    textGCMask = 0;
  }

  i = 0; XtSetArg(arg[i], XtNforeground, &fg); i++;
  XtGetValues(inputHistory, arg, i);
  i = 0; XtSetArg(arg[i], XtNbackground, &bg); i++;
  XtGetValues(outputPane, arg, i);

  if (XGetGCValues(display,
		   DefaultGCOfScreen(XtScreen(topLevel)),
		   fullGCMask, &values) == 0)
    red_err("Could not get default graphics context values");

  tempValues = values;

  tempValues.function = GXcopy;

  copyGC    = XCreateGC(display,
			RootWindowOfScreen(XtScreen(topLevel)),
			fullGCMask, &tempValues);

  tempValues.function   = values.function;

  if (app_data.reverseGraph) {
    tempValues.foreground = fg;
    tempValues.background = fg;
  } else {
    tempValues.foreground = bg;
    tempValues.background = bg;
  }

  clearGC   = XCreateGC(display,
			RootWindowOfScreen(XtScreen(topLevel)),
			fullGCMask, &tempValues);

  if (app_data.reverseGraph) {
    tempValues.foreground = bg;
  } else {
    tempValues.foreground = fg;
  }

  drawingGC = XCreateGC(display,
			RootWindowOfScreen(XtScreen(topLevel)),
			fullGCMask, &tempValues);

  values      = tempValues;
  fullGCMask |= textGCMask;

  values.font = GetFont(topLevel,app_data.normalAsciiFont);
  XChangeGC(display, textGC[0][0], fullGCMask, &values);
  values.font = GetFont(topLevel,app_data.smallAsciiFont);
  XChangeGC(display, textGC[1][0], fullGCMask, &values);

  values.font = GetFont(topLevel,app_data.normalGreekFont);
  XChangeGC(display, textGC[0][1], fullGCMask, &values);
  if (fontLoadFailed && app_data.useGreekFont && !quietMode)
    red_warn("Normal-size Greek characters will be in non-Greek font");

  values.font = GetFont(topLevel,app_data.smallGreekFont);
  XChangeGC(display, textGC[1][1], fullGCMask, &values);
  if (fontLoadFailed && app_data.useGreekFont && !quietMode)
    red_warn("Small Greek characters will be in non-Greek font");

  values.font = GetFont(topLevel,app_data.normalSymbolFont);
  XChangeGC(display, textGC[0][2], fullGCMask, &values);
  if (fontLoadFailed && app_data.useSymbolFont) {
    if (!quietMode)
      red_warn("No symbol font: drawing my own mathematical symbols");
    app_data.useSymbolFont = False;
  }

  values.font = GetFont(topLevel,app_data.smallSymbolFont);
  XChangeGC(display, textGC[1][2], fullGCMask, &values);
  if (fontLoadFailed && app_data.useSymbolFont) {
    if (!quietMode)
      red_warn("No small symbol font: drawing my own mathematical symbols");
    app_data.useSymbolFont = False;
  }

  if (!app_data.useSymbolFont) {

    values.font = GetFont(topLevel,app_data.normalAsciiFont);
    XChangeGC(display, textGC[0][2], fullGCMask, &values);
    values.font = GetFont(topLevel,app_data.smallAsciiFont);
    XChangeGC(display, textGC[1][2], fullGCMask, &values);
  }

  GetDefaultCharSizes();

  if (!GCsCreated) {

    boldGraphics = 0;
    if (FontToActualSize(app_data.normalAsciiFont) >= FontBoldSizeLimit)
      boldGraphics |= 1;
    for (i = 0; i < strlen(app_data.normalAsciiFont) - 4; ++i)
      if (!strncasecmp(app_data.normalAsciiFont + i, "bold", 4)) {
	boldGraphics |= 2;
	break;
      }

    outputPixmapList = NULL;
    GCsCreated       = True;
  }
}



void AddPixmapToList(pMap,width,height)
  Pixmap    pMap;
  Dimension width;
  Dimension height;
{
  OutputPixmapList *entry;

  entry = outputPixmapList;

  printf("AddPixmapToList,%d,%d\n",width,height);

  if (entry == NULL) {

  printf("AddPixmapToList initial\n");
    outputPixmapList = (OutputPixmapList *)XtMalloc(sizeof(OutputPixmapList));
  printf("AddPixmapToList initial%x \n",outputPixmapList);
    entry            =  outputPixmapList;

  } else {

    while (entry->next != NULL)
               entry = entry->next;
    entry->next      = (OutputPixmapList *)XtMalloc(sizeof(OutputPixmapList));
    entry            = entry->next;
  printf("AddPixmapToList erweitert %x\n",outputPixmapList);
  }

  entry->pMap   = pMap;
  entry->width  = width;
  entry->height = height;
  entry->next   = NULL;
  printf("AddPixmapToList final%x \n",outputPixmapList);
}



void BuildPixmap()
{
  fancy_xrange += xOffset + 10;                    /* Hack! Hack! */
  fancy_yrange += yOffset;

  buildMap = XCreatePixmap(display,
			   RootWindowOfScreen(XtScreen(referenceWidget)),
			   (unsigned)fancy_xrange,
			   (unsigned)fancy_yrange, howD);

  XFillRectangle(display,
		 buildMap, clearGC,
		 0, 0, fancy_xrange, fancy_yrange);
  fancy_draw();

  AddPixmapToList(buildMap, fancy_xrange, fancy_yrange);
}



/* ARGSUSED */
void RedrawGraphical(w, event, region)
  Widget  w;
  XEvent *event;
  Region  region;
{
  HistList *hl;

printf("REDRAW Anfang %x %x\n", region,w);

  for (hl = reduceHistory; hl; hl = hl->next)
{

printf("REDRAW %x %d %d\n", hl, hl->width,hl->height);
    if (hl->widget == w) break;
}

  if (!hl) return;

printf("REDRAW  not returned \n");

  if (region != NULL)
    if (XRectInRegion(region, 0, 0, hl->pMapWidth, hl->height) == RectangleOut)
      return;

printf("REDRAW  not returned 2\n");


  XClearArea(display, XtWindow(w), 0, 0, hl->width,
	     app_data.graphicalLineSpace / 2 + 1, False);

  CopyArea(hl->pMap, XtWindow(w), 0, 0,
	   hl->pMapWidth, hl->height, 0, app_data.graphicalLineSpace / 2);

  if (hl->width > hl->pMapWidth)
    XClearArea(display, XtWindow(w), hl->pMapWidth, 0,
	       hl->width - hl->pMapWidth, hl->height, False);
}


void DisplayMeldedPixmaps(crt)
  Boolean crt;			/* Create new histlist entry, instead of */
{				/* recycling the old one?                */
  Arg                arg[6];
  int                i;
  int                lineCount;
  Dimension          mapWidth;
  Dimension          fullWidth;
  Dimension          fullHeight;
  Dimension          maxLineHeight;
  OutputPixmapList * entry;
  OutputPixmapList * prevEntry;
  OutputPixmapList * tempEntry;
  Widget             spw;
  Widget             preW;

  maxLineHeight = app_data.graphicalLineSpace;
  entry         = outputPixmapList;
  fullWidth     = maxWidth;
  fullHeight    = 0;
  mapWidth      = 0;


  if (entry == NULL) return;	/* Empty list?  Don't bother   */

  for (lineCount = 0, prevEntry = NULL; entry != NULL;
       prevEntry = entry, entry = entry->next, ++lineCount) {

printf("displayMELDED %x %d %d\n",crt,entry->width ,entry->height);

    if (entry->width  > mapWidth)      mapWidth      = entry->width;
    if (entry->height > maxLineHeight) maxLineHeight = entry->height;

    fullHeight += entry->height + app_data.graphicalLineSpace;

    if (app_data.pageMode &&
	(placedHeight + fullHeight >= screenHeight) && prevEntry) {

      prevEntry->next  = NULL;
      DisplayMeldedPixmaps(crt);
      placedHeight     = 0;
      outputPixmapList = entry;
      DisplayMeldedPixmaps(crt);
      return;
    }
  }

  if (mapWidth > fullWidth) fullWidth = mapWidth;
  fullHeight -= app_data.graphicalLineSpace;
  RaisePlacedHeight(fullHeight);

  if (lineCount == 0) {
				           /* if there only is one pixmap,   */
    buildMap   = outputPixmapList->pMap;   /* use same copy of it as in list */

  } else {

    entry      = outputPixmapList;
    buildMap   = XCreatePixmap(display,
			       RootWindowOfScreen(XtScreen(referenceWidget)),
			       mapWidth, fullHeight, howD);
    if (!blankMap) {

      blankMap = XCreatePixmap(display,
			       RootWindowOfScreen(XtScreen(referenceWidget)),
			       mapWidth, maxLineHeight, howD);
      pBlankwd = mapWidth;
      pBlankht = maxLineHeight;

      XFillRectangle(display, blankMap, clearGC,
		     0, 0, mapWidth, maxLineHeight);

    } else if (maxLineHeight > pBlankht || mapWidth > pBlankwd) {

      XFreePixmap(display,blankMap);

      blankMap = XCreatePixmap(display,
			       RootWindowOfScreen(XtScreen(referenceWidget)),
			       mapWidth, maxLineHeight, howD);
      pBlankwd = mapWidth;
      pBlankht = maxLineHeight;

      XFillRectangle(display, blankMap, clearGC,
		     0, 0, mapWidth, maxLineHeight);
    }

    fullHeight = 0;

    while (entry != NULL) {

      CopyArea(entry->pMap, buildMap, 0, 0,
	       entry->width, entry->height, 0, fullHeight);

      CopyArea(blankMap, buildMap, 0, 0, mapWidth, app_data.graphicalLineSpace,
	       0, fullHeight + entry->height);

      if (fullWidth > entry->width) {

	CopyArea(blankMap, buildMap, 0, 0, mapWidth - entry->width,
		 entry->height, entry->width, fullHeight);
      }

      fullHeight += entry->height + app_data.graphicalLineSpace;
      entry       = entry->next;
    }

    fullHeight -= app_data.graphicalLineSpace;
 }

  i = 0;

  if (crt && endOfHistory) {
         XtSetArg(arg[i], XtNfromVert,  endOfHistory->widget); i++;
       } else if (!crt) {
	 XtSetArg(arg[i], XtNfromVert,                 &preW); i++;
	 XtGetValues(endOfHistory->widget, arg, 1);
	 XtSetArg(arg[i], XtNfromVert,                  preW); i++;
       }
         XtSetArg(arg[i], XtNwidth,          fullWidth);       i++;
         XtSetArg(arg[i], XtNborderWidth,    0);               i++;
         XtSetArg(arg[i], XtNheight,
		  fullHeight + app_data.graphicalLineSpace);   i++;

  if (!crt) spw = endOfHistory->widget;
  else {
    endOfHistory->next     = (HistList *)XtMalloc(sizeof(HistList));
    endOfHistory           = endOfHistory->next;
  }
  endOfHistory->flavour    = ReduceGraphical;
  endOfHistory->histNo     = reduceHistoryNumber;
  endOfHistory->managed    = InitiallyManaged();
  endOfHistory->height     = fullHeight + app_data.graphicalLineSpace;
  endOfHistory->width      = fullWidth;
  endOfHistory->pMapWidth  = mapWidth;
  endOfHistory->pMap       = buildMap;
  endOfHistory->next       = NULL;
  endOfHistory->widget     = CreateWidget("historyGraphical",
					  (WidgetClass)gWC,
					  outputHistory,
					  arg, (Cardinal)i);
  if (!crt) {
    XtUnmanageChild(spw);
    XtDestroyWidget(spw);
  }

  if (endOfHistory->managed)
    RedrawGraphical(endOfHistory->widget, NULL, NULL);

  if (lineCount == 0) {

    XtFree((char *)outputPixmapList); /* don't free the pixmap - it's shared */

  } else {

    entry = outputPixmapList;

    while (entry != NULL) {

      XFreePixmap(display,entry->pMap);
      tempEntry = entry;
      entry     = entry->next;
      XtFree((char *)tempEntry);
    }
  }

  printf("DisplayMelded reset\n",outputPixmapList);
  outputPixmapList = NULL;
  lineCount ++;
  reduceHistoryNumber += lineCount;

  ManageSomeHistList();
}


void PlaceSomeGraphics(desc,lineDoneFlag,allDoneFlag)
  char   *desc;
  Boolean lineDoneFlag;
  Boolean allDoneFlag;
{
  int i = 0;
  int j = 0;

printf("PlaceSomeGraphics\n");
  while (desc[i]) {
    if  (desc[i] == END_OF_LINE) {
      fancy_lines[graphIndex] = (char *)XtMalloc(i-j+1);
      strncpy(fancy_lines[graphIndex], desc+j, i-j);

      fancy_lines[graphIndex][i-j] = 0x0;
      graphIndex ++;
      while (desc[i] == END_OF_LINE) i++;
      j = i;
    } else i++;
  }

  if (i > j) {
    fancy_lines[graphIndex] = XtNewString(desc+j);
    graphIndex ++;
  }

  if (lineDoneFlag) {

    fancy_lines[graphIndex] = NULL;
    fancy_decode();

    if (fancy_xrange == 0 || 
	fancy_yrange == 0) { fancy_xrange = fancy_yrange = 8;
			     errorFlag = True; }

    xOffset = fancy_tab * font_width[0];
    yOffset = 0;

    if (errorFlag) errorFlag = False;
    else if (!allDoneFlag) BuildPixmap();
    else {

      BuildPixmap();

      /* If the previous widget is an empty verbal, we want to replace   */
      /* it with this one, instead of creating a new one; this avoids    */
      /* getting blank verbals between supposedly consecutive graphicals */

      if (endOfHistory->flavour == ReduceVerbal && 0) {

	char *str;
	Arg   arg;
        int   i;

printf("case ReduceVerbal\n");
	XtSetArg(arg, XtNstring, &str);
	XtGetValues(endOfHistory->widget, &arg, 1);

	for (i = 0; str[i] && isspace(str[i]); ++i);
	DisplayMeldedPixmaps(str[i]);

      } else DisplayMeldedPixmaps(True);
    }

    for (i = 0; i < graphIndex; i++)
      XtFree(fancy_lines[i]);
    graphIndex = 0;
  }
}



char *GetGreekNameAndSize(c,ffont,ra,wd,ht)
  char c;
  int  ffont;
  int *ra;
  int *wd;
  int *ht;
{
  int         dir;
  int         asc;
  int         desc;
  XCharStruct info;
  char       *word;

  if (c == (char)0xa5)
    word = "infinity";
  else if (islower(c))
    word = greekLetters[c-'a'];
  else if (isupper(c))
    word = greekLetters[c-'A'];
  else {
    word    = (char *)XtMalloc(4);
    word[0] = '\'';
    word[1] = c;
    word[2] = '\'';
    word[3] = 0x0;
    warning("No such Greek letter",word);
    XtFree(word);
    word =greekLetters['j'-'a'];
  }

  XTextExtents(textFt[ffont][0], word, strlen(word),
	       &dir, &asc, &desc, &info);

  if (ra != NULL) *ra = asc;
  if (wd != NULL) *wd = info.width;
  if (ht != NULL) *ht = asc + desc;

  return word;
}
  


void inquire_char_box(coords, c, charset, ffont)
  int * coords;
  char  c;
  int   charset;
  int   ffont;
{
  coords[0]  = 0;
  coords[1]  = 0;		/* x1, y1 */

  if (charset == 0 && isdigit(c)) {

    coords[2] = font_width[ffont];
    coords[3] = font_height[ffont];

  } else {

    int     heightFactor;
    Boolean charSpecific;

    if (charset == 2) {		/* Mathematical character? */

      if (app_data.useSymbolFont) {

	switch(c) {
        case 'i':
          c            = 243;
          heightFactor = 2;
          charSpecific = True;  
          break;  
	case 'I':
	  c            = 243;
	  heightFactor = 2;
	  charSpecific = True;	/* because int (&c) may be bigger than   */
	  break;		/* normal font chars, and isn't expected */
	case 'S':		/* to be lined up with other symbols, we */
	  c            = 'W';	/* should take the actual height of the  */
	  heightFactor = 1;  	/* int char; for most chars we should    */
	  charSpecific = False;	/* take the standard height of the font. */
	  charset      = 0;	/* For the sum, make it the same size as */
	  break;		/* the normal characters' generic height */
	default:
	  heightFactor = 1;
	  charSpecific = True;
	}
      } else {
	
	switch(c) {
        case 'i':
          c            = 'M';
          heightFactor = 2;
          charSpecific = False;
          charset      = 0;
          break;
	case 'I':
	  c            = 'M';
	  heightFactor = 2;
	  charSpecific = False;
	  charset      = 0;
	  break;
	case 'S':
	  c            = 'W';
	  heightFactor = 1;  
	  charSpecific = False;
	  charset      = 0;
	  break;
	default:
	  heightFactor = 1;
	  charSpecific = True;
	}
      }
    } else {

      heightFactor = 1;
      charSpecific = False;
    }

    if (charset == 1) {

      if (app_data.useGreekFont) {

	/* make Greek chars same height as Roman */

	QueryCharDimensions(c, ffont, 1, NULL, NULL, coords+2, NULL, False);
	QueryCharDimensions(c, ffont, 0, NULL, NULL, NULL, coords+3, False);

      } else (void)GetGreekNameAndSize(c, ffont, NULL, coords+2, coords+3);

    } else {

      QueryCharDimensions(c, ffont, charset, NULL, NULL,
			  coords+2, coords+3, charSpecific);

      if (charset == 1) {	/* make Greek chars same height as Roman */
	QueryCharDimensions(c, ffont, 0, NULL, NULL, NULL, coords+3, False);
      }
    }
    coords[3] *= heightFactor;
  }
}



void DrawLines(point,pnum,a,b,offset)
  XPoint *point;
  int     pnum;
  int     a;
  int     b;
  int     offset;
{
  int i;

  XDrawLines(display,
	     buildMap,
	     drawingGC,
	     point, pnum,
	     CoordModeOrigin);

  if (boldGraphics) {

    for (i = a; i < b; ++i)
      point[i].x += offset;

    XDrawLines(display,
	       buildMap,
	       drawingGC,
	       point, pnum,
	       CoordModeOrigin);
  }
}
   

/* This is used when the standard symbol font is   */
/* unavailable, or the user decides not to use it. */
/* It is not the most elegant of symbols.          */

void DrawLineIntegral(x, y, ffont)
  int x;
  int y;
  int ffont;
{
  XPoint point[2];
  int    pnum = 2;
  int    mx;
  int    my;
  int    lx;
  int    ly;

  QueryCharDimensions('M',ffont,0,NULL,NULL,&mx,&my,False);

  x += xOffset + mx/6;
  y += yOffset;
  mx = (mx*2)/3;
  my =  my*2;
  lx =  mx/2;
  ly =  my/6;

  point[0].x = x + lx; point[0].y = y + ly - 1;
  point[1].x = x + lx; point[1].y = y + my - ly;

  DrawLines(point, pnum, 0, pnum, 1);

  XDrawArc(display,
	   buildMap, drawingGC,
	   x+lx+1, y+ly+2, mx-lx+1, -ly-1, 11520, 8640);

  XDrawArc(display,
	   buildMap, drawingGC,
	   x, y+my-2, lx, -ly, 0, 8640);

  if (boldGraphics) {

    XDrawArc(display,
	     buildMap, drawingGC,
	     x+lx+2, y+ly+2, mx-lx+1, -ly-1, 11520, 8640);

    XDrawArc(display,
	     buildMap, drawingGC,
	     x+1, y+my-2, lx, -ly, 0, 8640);
  }
}
  


void DrawIntegral(x, y, ffont)
  int x;
  int y;
  int ffont;
{
  char   halfSymbol[2];
  int    asc;
  int    desc;

  if (!app_data.useSymbolFont) {

    DrawLineIntegral(x,y,ffont);
    return;
  }

  QueryCharDimensions(243,ffont,2,&asc,&desc,NULL,NULL,True);

  y = y + asc;

  halfSymbol[0] = 243;
  halfSymbol[1] = 0x0;

  XDrawString(display,
	      buildMap,
	      textGC[ffont][2],
	      x + xOffset, y + yOffset, halfSymbol, 1);

  if (boldGraphics > 2)
    XDrawString(display,
		buildMap,
		textGC[ffont][2],
		x + xOffset + 1, y + yOffset, halfSymbol, 1);

  y = y + asc + desc;

  halfSymbol[0] = 245;

  XDrawString(display,
	      buildMap,
	      textGC[ffont][2],
	      x + xOffset, y + yOffset, halfSymbol, 1);

  if (boldGraphics > 2)
    XDrawString(display,
		buildMap,
		textGC[ffont][2],
		x + xOffset + 1, y + yOffset, halfSymbol, 1);
}


void DrawSummation(x, y, ffont)
  int x;
  int y;
  int ffont;
{
  XPoint point[10];
  int    ht;
  int    wd;
  int    mx;
  int    my;
  int    lx;
  int    ly;
  int    pnum = 10;

  /* Use generic normal charset height for sum characters, and */
  /* a reasonably great width -- use capital W as a standard   */
  
  QueryCharDimensions('W',ffont,0,NULL,NULL,&wd,&ht,False);

  /* Now, draw a sum.  (The one in the standard font is crap.) */

  x += xOffset;
  y += yOffset;
  wd = (wd*3)/4;
  mx = (wd*2)/5;
  my = ht/2;
  lx = wd/10;
  ly = wd/6;

  point[0].x = x + wd - lx; point[0].y = y + ly;
  point[1].x = x + wd;      point[1].y = y;
  point[2].x = x;           point[2].y = y;
  point[3].x = x + mx;      point[3].y = y + my;
  point[4].x = x + 1;       point[4].y = y + ht;
  point[5].x = x + mx + 1;  point[5].y = y + my;
  point[6].x = x + mx;      point[6].y = y + my;
  point[7].x = x;           point[7].y = y + ht;
  point[8].x = x + wd;      point[8].y = y + ht;
  point[9].x = x + wd - lx; point[9].y = y + ht - ly;

  DrawLines(point, pnum, 1, pnum-1, 1, 1);
}



void draw_math(x, y, c, ffont)
  int    x;
  int    y;
  char * c;
  int    ffont;
{
  if (PostScriptMode) { PSDrawMath(x, y, c, ffont); return; }

  switch(*c) {

  case 'i':
    DrawIntegral(x, y, ffont);
    break;

  case 'I':
    DrawIntegral(x, y, ffont);
    break;

  case 'S':
    DrawSummation(x, y, ffont);
    break;

  default:
    break;
  }
}



/* This function is used when the Greek font */
/* is unavailable or the user has requested  */
/* that it not be used; then the name of the */
/* Greek character is written out in full.   */

void WriteGreekName(x, y, c, ffont)
  int x;
  int y;
  int c;
  int ffont;
{
  char *word;
  int   wd;
  int   ht;
  int   asc;

  word = GetGreekNameAndSize(c, ffont, &asc, &wd, &ht);

  XDrawString(display,
	      buildMap,
	      textGC[ffont][0],
	      x + xOffset, y + yOffset + asc, word, strlen(word));
}



void draw_string(x, y, c, len, charset, ffont)
  int    x;
  int    y;
  char * c;
  int    len;
  int    charset;
  int    ffont;
{
  int asc;

  if (PostScriptMode) { PSDrawString(x, y, c, len, charset, ffont); return; }

  switch(charset) {

  case 2:

    switch(*c) {

    case 'i':
      DrawIntegral(x, y, ffont);
      break;
    case 'I':
      DrawIntegral(x, y, ffont);
      break;
    case 'S':
      DrawSummation(x, y, ffont);
      break;
    default:
      break;
    }
    return;

  case 1:

    if (!app_data.useGreekFont) {
      WriteGreekName(x, y, *c, ffont);
      return;
    }				/* fall through; note ascent of Greek chars */
				/* assumed == to Roman to line up baselines */

  case 0:

    QueryCharDimensions(*c,ffont,0,&asc,NULL,NULL,NULL,False);

    XDrawString(display, buildMap, textGC[ffont][charset],
		x + xOffset, y + yOffset + asc, c, len);

    /* Assume that the Greek font is not bold, and therefore Greek */
    /* characters will, if the ascii font is bold, need some extra */
    /* degree of fake emboldening.  Not as good as real bold text. */

    if (charset == 1 && (boldGraphics & 2))
      XDrawString(display,
		  buildMap,
		  textGC[ffont][charset],
		  x + xOffset + 1, y + yOffset + asc, c, len);
  }
}



void draw_line(x0, y0, x1, y1)
  int x0;
  int y0;
  int x1;
  int y1;
{
  if (PostScriptMode) { PSDrawLine(x0, y0, x1, y1); return; }

  XDrawLine(display,
	    buildMap,
	    drawingGC,
	    x0 + xOffset, y0 + yOffset,
	    x1 + xOffset, y1 + yOffset);

  if (boldGraphics)
    XDrawLine(display,
	      buildMap,
	      drawingGC,
	      x0 + xOffset + 1, y0 + yOffset,
	      x1 + xOffset + 1, y1 + yOffset);
}



void draw_small_brack(x, y0, y1, c, ffont)
  int  x;
  int  y0;
  int  y1;
  char c;
  int  ffont;
{
  XPoint  point[7];
  int     pnum;
  int     p;
  int     w;
  int     x0;
  int     x1;
  int     ym;

  p  = font_height[ffont];
  w  = 4;

  if (c == '(' || c == '[' || c == '{') {
    x  = x + xOffset + font_width[ffont] - w - 2;
    x0 = x + w;
    x1 = x;
  } else {
    x  = x + xOffset;
    x0 = x;
    x1 = x + w;
  }

  x  = x  + w/2;
  y0 = y0 + yOffset;
  y1 = y1 + yOffset;
  ym = y0 + (y1-y0)/2;

  switch(c) {

  case '[':
  case ']':

    point[0].x = x0; point[0].y = y0;
    point[1].x = x;  point[1].y = y0;
    point[2].x = x;  point[2].y = y1;
    point[3].x = x0; point[3].y = y1;

    pnum = 3;
    break;

  case '(':
  case ')':

    p = p / 3;

    point[0].x = x0; point[0].y = y0;
    point[1].x = x;  point[1].y = y0 + p;
    point[2].x = x;  point[2].y = y1 - p;
    point[3].x = x0; point[3].y = y1;

    pnum = 4;
    break;

  case '{':
  case '}':

    p = p / 6;

    point[0].x = x0; point[0].y = y0;
    point[1].x = x;  point[1].y = y0 + p;
    point[2].x = x;  point[2].y = ym - p;
    point[3].x = x1; point[3].y = ym;
    point[4].x = x;  point[4].y = ym + p;
    point[5].x = x;  point[5].y = y1 - p;
    point[6].x = x0; point[6].y = y1;

    pnum = 7;
    break;
  }

  DrawLines(point, pnum, 1, pnum-1,
	    (c == '(' || c == '{' || c == '[') ? 1 : -1);
}



void draw_brack(x, y0, y1, c, ffont)
  int  x;
  int  y0;
  int  y1;
  char c;
  int  ffont;
{
  int           units;
  int           i;
  int           asc;
  int           desc;
  int           y00;
  int           ascw;
  int           toph;
  int           midh;
  int           midw;
  int           both;
  unsigned char topc[2];
  unsigned char midc[2];
  unsigned char botc[2];

  if (PostScriptMode) { PSDrawBrack(x, y0, y1, c, ffont); return; }

  if (!app_data.useSymbolFont) {
    draw_small_brack(x, y0, y1-1, c, ffont);
    return;
  }

  topc[0] = ((c == '(') ? 230 :
	     (c == '[') ? 233 :
	     (c == '{') ? 236 :
	     (c == ')') ? 246 :
	     (c == '|') ? 239 :
	     (c == ']') ? 249 :
	                  252);

  midc[0] = topc[0] + 1;
  botc[0] = midc[0] + 1;
  if (c == '|') botc[0]=239;

  topc[1] = midc[1] = botc[1] = 0x0;

  if (c == '{' || c == '}' || c == '|') midc[0] = 239;

  QueryCharDimensions(topc[0],ffont,2,&asc,&desc,NULL, &toph,True);
  QueryCharDimensions(midc[0],ffont,2,NULL,NULL, &midw,&midh,True);
  QueryCharDimensions(botc[0],ffont,2,NULL,NULL, &ascw,&both,True);

  if ((y1-y0) <= (toph + midh + both)/2) {
    draw_small_brack(x, y0, y1-1, c, ffont); return;
  }

  units = (y1-y0) / midh;

  if (c == '{' ||
      c == '(' ||
      c == '[')
    x = x + font_width[1] - ascw;

  y00 = y0;

  if (units > 1) {
    y0 = y0 + asc + (y1-y0 - (toph + both + (units-2) * midh)) / 2;
    y1 = y1 + asc + asc - (y0 - y00) - 1;
  } else {
    y0 = y0 + asc - 1;
    y1 = y1 + asc;
  }

  XDrawString(display,
	      buildMap,
	      textGC[ffont][2],
	      x + xOffset, y0 + yOffset, topc, 1);

  XDrawString(display,
	      buildMap,
	      textGC[ffont][2],
	      x + xOffset, y1 + yOffset - both, botc, 1);

  if (boldGraphics) {

    XDrawString(display,
		buildMap,
		textGC[ffont][2],
		x + xOffset + 1, y0 + yOffset, topc, 1);

    XDrawString(display,
		buildMap,
		textGC[ffont][2],
		x + xOffset + 1, y1 + yOffset - both, botc, 1);
  }

  for (i = 1; i < units-1; i++) {

    XDrawString(display,
		buildMap,
		textGC[ffont][2],
		x + xOffset, y0 + yOffset + toph + (i-1)*midh, midc, 1);

    if (boldGraphics)
    XDrawString(display,
		buildMap,
		textGC[ffont][2],
		x + xOffset + 1, y0 + yOffset + toph + (i-1)*midh, midc, 1);
  }

  if (c == '{' || c == '}') {

    if (units > 1) { y0 = y00 + (toph + both + (units-2) * midh + asc) / 2; }
	 else { y0 = (y00 + y1 + asc - midh) / 2; }

    for (i = 0; i < midw; i++)
      XDrawLine(display, buildMap, clearGC,
		x + xOffset + i, y0 + yOffset - asc + 1,
		x + xOffset + i, y0 + yOffset - asc + midh - 1);

    midc[0] = topc[0] + 1;

    XDrawString(display, buildMap, textGC[ffont][2],
		x + xOffset, y0 + yOffset, midc, 1);

    if (boldGraphics)
      XDrawString(display, buildMap, textGC[ffont][2],
		  x + xOffset + 1, y0 + yOffset, midc, 1);
  }
}
