
/*
   Header for all files in xreduce source.
*/


/* I am assuming that X11R4 or newer is present */

#include <ctype.h>
#include <stdio.h>
#include <signal.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/uio.h>
#include <sys/stat.h>
#include <sys/wait.h>

#include <X11/Intrinsic.h>
#include <X11/StringDefs.h>
#include <X11/Shell.h>
#include <X11/Core.h>
#include <X11/Xutil.h>

#include <X11/cursorfont.h>

#include <X11/Xaw/AsciiText.h>
#include <X11/Xaw/Box.h>
#include <X11/Xaw/Command.h>
#include <X11/Xaw/Dialog.h>
#include <X11/Xaw/Form.h>
#include <X11/Xaw/Label.h>
#include <X11/Xaw/List.h>
#include <X11/Xaw/Paned.h>
#include <X11/Xaw/Scrollbar.h>
#include <X11/Xaw/Text.h>
#include <X11/Xaw/Toggle.h>
#include <X11/Xaw/Viewport.h>

#ifdef EXPLICIT_EDITRES
#include <X11/Xmu/Editres.h>	/* Our X11R5 doesn't support editres by */
#endif				/* default -- dunno why -- so you have  */
				/* to do it by hand                     */
#include "xredres.h"

/*
   Default constants.  Some of these are also parameterised as defaults in
   xredres.h; the others probably should be (most notably the buffer-length
   constants).
*/

#define END_OF_LINE                 10     /* ASCII eol                      */
#define REDUCE_HISTORY_MIN_MAX      1      /* Min hist-length for X default  */
#define REDUCE_HISTORY_MAX_MAX      1000   /* Max likewise                   */
#define REDUCE_HISTORY_MIN_EXCESS   1      /* Excess is how far hist can grow*/
#define REDUCE_HISTORY_MAX_EXCESS   200	   /* beyond max before it's clipped */
#define REDUCE_WIDNAME_LENGTH       20     /* For names of history widgets   */
#define REDUCE_INPUT_BUFFER_LENGTH  500000
#define REDUCE_OUTPUT_BUFFER_LENGTH 8000   /* Reduce to Me communication     */
#define REDUCE_PATH                 "/bin/redu35"
#define REDUCE_NAME                 "redu35"
#define REDUCE_TEX_ON               16	   /* Char Reduce outputs to indicate*/
#define REDUCE_TEX_OFF              17     /* beginning and end of graphics  */
#define INPUT_ESCAPE_CHAR 0x2


/*
   Some types.  EltType is used to indicate difference between textual and
   graphical widgets; the HistList is the structure that stores all the
   Reduce output widgets.
*/


/* Enumerate possibilities for current state of output stream */

typedef enum { ReduceVerbal, ReduceGraphical, ReduceMessage } EltType;


/* Type for blocks to be displayed in Reduce output widget box.  Each  */
/* contains a widget, to be managed, and various pieces of information */
/* about its content and how to manage it.                             */
/* There are three blocks: information for all widgets, for verbals    */
/* only, and for graphicals only.  I could conceivably use a union for */
/* these, but I don't think there's enough wasted memory to warrant it */

typedef struct _HistList {
  EltType           flavour;	/* Verbal or Graphical?                      */
  unsigned long     histNo;	/* Value of Reduce History Number at start   */
  Boolean           managed;	/* Currently displayed? (Or awaiting page?)  */
  Dimension         width;	/* Pixel width of widget                     */
  Dimension         height;	/* Pixel height of widget                    */
  Widget            widget;	/* The actual Widget to be displayed         */
  struct _HistList *next;	/* It's a simple linked list                 */

  /* These are for Verbals only: */

  int               nLines;	/* Number of lines of text on verbal         */
  int               textLength;	/* Chars total in current verbal             */
  int               usedOnLine;	/* Chars drawn on current line               */

  /* These are for Graphicals only: */

  Dimension         pMapWidth;	/* Pixel width of pixmap                     */
  Dimension         pMapHeight;	/* Pixel height of pixmap                    */
  Pixmap            pMap;	/* Pixmap itself, Graphical only             */

} HistList;


/* Type for pixmaps awaiting assemblage into a single output block. */

typedef struct _OutputPixmapList {
  Pixmap                    pMap;
  Dimension                 width;
  Dimension                 height;
  struct _OutputPixmapList *next;
} OutputPixmapList;


/* Type for lines of user input awaiting a prompt so they can be sent */
/* to Reduce.                                                         */

typedef struct _PendingInputList {
  char                     *text;
  char                     *stxt;
  Boolean                   show;
  struct _PendingInputList *next;
} PendingInputList;


/* Types for Option and File boxes. */

typedef struct _OptToggleSet {
  Widget         form;
  Widget         label;
  Widget         toggle;
  Boolean        datumP;
  char         * datum;
  XtCallbackProc callback;
} OptToggleSet;

typedef struct _OptToggleDesc {
  char         * name;
  XtCallbackProc callback;
} OptToggleDesc;

typedef struct _nhelpToggleSet {
  Widget         form;
  Widget         label;
  Widget         toggle;
  Boolean        datumP;
  char         * datum;
  XtCallbackProc callback;
} nhelpToggleSet;

typedef struct _nhelpToggleDesc {
  char         * name;
  XtCallbackProc callback;
} nhelpToggleDesc;


