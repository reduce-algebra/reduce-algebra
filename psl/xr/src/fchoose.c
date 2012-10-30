
/*
   Implement a natty popup window for file selection purposes.  I'll
   try and make it non-XReduce-specific, so that if anyone else should
   wish to use it, they might even be able to.  If it works, that is.
   If I ever get most of it written, that is.

   Chris Cannam, Berlin May 1993
*/

/*
   Using It
   ========

   There are two external functions: FileGetFilename(), and FileSetFonts().
   The latter is used with a Widget argument for the proposed parent of the
   file selector box, and two XFontStruct* arguments to install the fonts
   to be used for (respectively) buttons and texts -- these must both be
   set properly before the selector is requested; the former is prototyp-
   able as follows:

   Boolean FileGetFilename(parent, purpose, error, path,
                           type, prefix, testp, openp, callback)
	   Widget      parent;
           char      * purpose,
	             * error,
                     * path,
                     * type,
		     * prefix;
           Boolean     testp,
                       openp;
           void     (* callback)();

   parent    Widget which the file selector window's outer shell widget
             should use as a parent.

   purpose   String describing why the filename is needed; this is shown
             in the top of the selection box as a prompt.  If this is
	     NULL, a generic message will be used instead.

   error     String to display as an error message in the event that
             there is nothing from which to choose -- ie. if none of
	     the path directories (see "path") exist, or if none of the
	     choices in a selection file are available.  If the error
	     message is NULL, a generic message will be used instead.

   path      This string may be one of the following:

             [1] the name of a directory, in which case the contents of
	         that directory are shown in the selection box;

	     [2] a list of directory names, separated by colons, where
	         the contents of the selection box will be those of the
		 first in the path which proves both to exist and to
		 be a real directory;

	     [3] the name of a file, in which case that file is taken as
	         a list of possibilities from which to choose, in a file
		 format as described below;

	     [4] a list of file names, separated by pipe symbols (`|'),
	         where the first file in the list found to exist and be
		 readable will be used to provide the list in the same
		 manner as in [3];

	     [5] NULL, in which case the current directory is assumed.

	     Note that in all cases environment variable expansion is
	     performed on the path names, and names not beginning with
	     a slash after expansion are taken relative to the current
	     directory.

	     Notice also that if there is only one element in the list
	     (case [1] or [3] above), the resulting behaviour will be
	     dependent upon whether it pointed to a directory or file;
	     if several, the behaviour will depend on whether the first
	     dividing character was a colon or a pipe.  Passing a string
	     containing both colon and pipe characters is not sensible.

   type      This is a string similar to the type argument passed to
             fopen(3), only without support for binary modes or anything
	     fancy like that.  Hence the valid strings are "r", "w", "a",
	     "r+", "w+" or "a+".  See the man page for fopen(3).  If this
	     is NULL, "r" will be assumed.

   prefix    String to be used as the prefix for the default filename,
             which will be generated using tempnam(3) and will therefore
	     be unique within the given directory.  (This feature is of
	     use when opening files for writing, on order to ensure that
	     the default doesn't overwrite an existing file.)  The string
	     should be no longer than five characters; if it is NULL,
	     as it should probably be when opening files for reading, no
	     filename will be generated and the default file name box will
	     be left blank.

   testp     Flag to declare whether destructive, creative or infeasible
             filename requests should be queried.  If True, a query box
	     will be popped up if one of the following conditions holds:

	     [1] the type is "a", "a+" or "r+" and the file does not
	         exist;

	     [2] the type is "w", "w+" or "r+" and the file exists.

	     If the type is "r", the user will not be allowed to choose
	     a nonexistent file, whether testp is True or not; likewise,
	     if the relevant permissions are unavailable on the file or
	     directory or if for some other reason the file cannot be
	     opened, the choice will be denied.

   openp     Flag to declare whether to open the file.  If False, the
             filename will be only tested for suitability and the file
	     will not be opened (or created).  Otherwise it will be
	     opened and a FILE* stream associated with it to pass to
	     the callback (below).

   callback  A function to be called when the filename has been obtained.
             It is assumed to take two arguments, which are a string (the
	     name of the file, either absolute or relative, variable
	     expansions already performed) and a FILE* stream pointer.
	     If openp was False and the file has not been opened, the
	     stream will be NULL; if no filename was obtained, the file
	     string will also be NULL.  If the callback function given
	     is NULL, no callback will be called.  (But what's the point?)
	     Note that the filename string passed is obtained from a call
	     to XtMalloc and may safely be freed by calling XtFree.

   If a file is given as the path argument, it should contain a series of
   entries, all referring to a single filename, and separated by single
   carriage returns, of the following format:

   <desc>::<file>::<name>

   <desc>    a textual description of the file.  This is the text that
	     will appear as a selection in the Selection Box.

   <file>    the pathname of a file (on which variable expansion will
             be carried out), given purely for testing purposes.  The
	     <desc> text will only be listed as an option if one of the
	     following conditions is met:

             [1] the type is "r" and <file> exists and is readable;

	     [2] the type is "w", "a", "w+", "r+" or "a+" and <file>
	         does not exist but can be created with the necessary
		 permissions;

	     [3] the type is "w" or "a" and <file> exists and is writable;

	     [4] the type is "r+", "w+" or "a+" and <file> exists and is
	         both readable and writable.

	     Note that if the type is "w" or "w+", an existing file can
	     be overwritten without complaint.  The testp file is not
	     referred to here; the behaviour is as if it was False.  The
	     openp flag, however, is used; if True, the file is opened
	     with the relevant type, and a file pointer passed as normal
	     to the callback; note, however, that the name passed to the
	     callback will not in general be the name of the opened file.

   <name>    a string to identify the selection.  When the callback
             function is called, its arguments will be (respectively)
	     this string, and NULL.  If no selection was successfully
	     made, the first argument will also be NULL.

   No entry (in the total of its <desc>::<file>::<name> structure) should
   be longer than 512 characters; this is likely to be less of a practical
   drawback than the fact that it must all fit on one line in the file.

   So as an example, XReduce might use a file containing lines similar
   to this one (only flush-left):

      The Taylor Series Package::$reduce/fasl/taylor.b::taylor

   then "The Taylor Series Package" would be listed as an option, if
   the file $reduce/binary/taylor.b was available (presuming the type
   given was "r"), and the string "taylor" would be returned to the
   callback if this was selected.

   The normal return value from this function is True.  If none of the
   directories in the directory path exist, or if a file is referred to
   and none of its choices are possible, or if something else goes wrong
   somewhere, then instead of the selection window a complaint window
   will be popped up, containing the specified error message and a Cancel
   button; then the function returns False and the callback, which is
   called when Cancel is pressed, receives two NULL arguments.
*/

/* 
   ADVERTISEMENT
   =============

   I am looking for a home for the following error code.

   fprintf(stderr,"XR: I'm sorry, your XR has been incorrectly installed.\n");
   fprintf(stderr,"XR: Please recompile with the -DTOTAL_IDIOT flag set.\n");
   exit(-1);
*/

/* 
   First include various things -- standard headers, plus X stuff.
   Do not include anything specific to the host application.
*/

#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>

#include <sys/types.h>
#include <sys/stat.h>

#include <X11/Intrinsic.h>
#include <X11/StringDefs.h>
#include <X11/Shell.h>

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

#ifndef PATH_MAX
#define PATH_MAX 512
#endif

#ifndef NAME_MAX
#define NAME_MAX 512
#endif

#ifdef HAVE_VIEWPORT_SET_FUNCTIONS
#define FileViewportSetHeight(v,c,y) { XawViewportSetCoordinates((v),0,(y)); }
#else
#define FileViewportSetHeight(v,c,y) { XtMoveWidget((c),0,(-(y))); }
#endif

#define WIDGET(q,z,k,v) { q = XtCreateManagedWidget((z),(k),(v),NULL,0); }
#define BEGARG          { Arg arg;
#define SETARG(q,z,k)   { XtSetArg(arg,(z), (k)); XtSetValues((q),&arg,1); }
#define GETARG(q,z,k)   { XtSetArg(arg,(z),&(k)); XtGetValues((q),&arg,1); }
#define FINARG           }
#define Try(x)          { if ( (x) == False ) { goto oops; } else {}; }

#define MAXNROFFILES 256
#define SHELLHEIGHT  400
#define SHELLWIDTH   400

static Widget filePopup = NULL;
static Widget fileBox;
static Widget fileLabel;
static Widget fileDir;
static Widget fileUp;
static Widget fileRescan;
static Widget fileHidden;
static Widget fileViewport;
static Widget fileList;
static Widget fileNameNEd;
static Widget fileNameEd;
static Widget fileName;
static Widget fileOK;
static Widget fileCancel;
static Widget fileQueryPopup;
static Widget fileQueryBox;
static Widget fileQueryLabel;
static Widget fileQueryYes;
static Widget fileQueryNo;
static Widget referenceWidget;

typedef struct _ftstruct {
  char  * name;			/* Filename                  */
  char  * call;			/* Name as listed on window  */
  char  * retn;			/* Name to return (if index) */
  mode_t  mode;			/* Mode of file              */
  uid_t   uid;			/* UID and GID of file       */
  gid_t   gid;			/* (not used if index file)  */
} ftstruct;

static char     *directory = NULL;
static char    **filecall  = NULL;
static ftstruct *filelist  = NULL;
static char     *filename  = NULL;
static int       filecount = 0;

static char     *Error;
static char     *Type;
static Boolean   Testp;
static Boolean   Openp;
static Boolean   GlobDots;  /* True if we should display dotfiles and such */
static Boolean   File;	    /* True if we're using an index file, in which */
			    /* case, cunningly, `directory' will be a file */
static Boolean   Editable;  /* True if we should allow the user to edit    */
                            /* the filename (ie. if not opening read-only) */

static void    (*Callback)();
static Dimension tlHt = 0;
static Dimension tlWd = 0;
static Dimension tfWd = 0;
static Dimension tbWd = 0;
static Dimension taWd = 0;
static Dimension tvHt = 0;

static XFontStruct *fileButtonFont = NULL;
static XFontStruct *fileTextFont   = NULL;

void FileUp();
void FileRescan();
void FileHidden();
void FileList();
void FileApply();
void FileCancel();
void FileQueryYes();
void FileQueryNo();
void FileErrorYes();



/* ARGSUSED */
void FileErrorYes(w, a, b)
  Widget w;
  caddr_t a,b;
{
  XtSetSensitive(fileQueryYes, False);
  XtPopdown(fileQueryPopup);
  XtSetSensitive(fileQueryYes, True);
  XtUnrealizeWidget(fileQueryPopup);
  XtRemoveCallback(fileQueryYes, XtNcallback, FileErrorYes, 0);
}


void FileError(message,arg)
  char *message;
  char *arg;
{
  /* 
     Arrangement of boxes:

     +--------------------------+
     | +----------------------+ |
     | |    fileQueryLabel    | |
     | +----------------------+ |
     | +----------+             |
     | | QueryYes |             |
     | +----------+             |
     +--------------------------+
  */

  int         dir;
  int         asc;
  int         dsc;
  int         tWd;
  int         yWd;
  char       *msg;
  Position    rxr;
  Position    ryr;
  Dimension   lHt;
  Dimension   sHt;
  Dimension   lWd;
  Dimension   iSp;
  Dimension   bWd;
  XCharStruct info;

  XtUnmanageChild(fileQueryNo);
  if (arg) {
    msg = (char *)XtMalloc(strlen(message) + strlen(arg) + 2);
    sprintf(msg, message, arg);
  } else msg = XtNewString(message);

  BEGARG;

  XTextExtents(fileButtonFont, msg, strlen(msg), &dir, &asc, &dsc, &info);
  sHt = asc + dsc; tWd = info.width;
  XTextExtents(fileButtonFont, "Continue", 8, &dir, &asc, &dsc, &info);
  yWd = info.width;

  GETARG(fileQueryLabel, XtNborderWidth,    bWd);
  GETARG(fileQueryBox,   XtNvSpace,         iSp);
  GETARG(fileQueryLabel, XtNinternalHeight, lHt);

  SETARG(fileQueryLabel, XtNlabel,  msg);
  SETARG(fileQueryYes,   XtNlabel, "Continue");

  lWd = ((tWd > yWd) ? tWd : yWd) + 2*lHt + 2*bWd + 3*iSp;
  sHt = 2*sHt + 3*iSp + 5*bWd + 4*lHt;

  XtRealizeWidget(fileQueryPopup);

  SETARG(fileQueryPopup, XtNwidth,  lWd);
  SETARG(fileQueryPopup, XtNheight, sHt);
  SETARG(fileQueryBox,   XtNwidth,  lWd);
  SETARG(fileQueryBox,   XtNheight, sHt);

  if (filePopup && XtIsRealized(filePopup))
    XtTranslateCoords(filePopup,       SHELLWIDTH/2 - lWd/2,
		      SHELLHEIGHT/2 - sHt/2, &rxr, &ryr);
  else
    XtTranslateCoords(referenceWidget, SHELLWIDTH/2 - lWd/2,
		      SHELLHEIGHT/2 - sHt/2, &rxr, &ryr);

  SETARG(fileQueryPopup, XtNx, rxr);
  SETARG(fileQueryPopup, XtNy, ryr);

  FINARG;

  XtAddCallback(fileQueryYes, XtNcallback, FileErrorYes, 0);
  XtPopup(fileQueryPopup, XtGrabNonexclusive);
  XtFree(msg);
  XRaiseWindow(XtDisplay(fileQueryPopup), XtWindow(fileQueryPopup));
  return;
}


void FileQueryYes(w, callback, call_data)
  Widget  w;
  void (* callback)();
  caddr_t call_data;
{
  XtSetSensitive(fileQueryYes, False);
  XtPopdown(fileQueryPopup);
  XtSetSensitive(fileQueryYes, True);
  XtUnrealizeWidget(fileQueryPopup);
  XtRemoveCallback(fileQueryYes, XtNcallback, FileQueryYes, callback);
  XtRemoveCallback(fileQueryNo,  XtNcallback, FileQueryNo,  callback);
  callback(True);
}


void FileQueryNo(w, callback, call_data)
  Widget w;
  void (* callback)();
  caddr_t call_data;
{
  XtSetSensitive(fileQueryNo, False);
  XtPopdown(fileQueryPopup);
  XtSetSensitive(fileQueryNo, True);
  XtUnrealizeWidget(fileQueryPopup);
  XtRemoveCallback(fileQueryYes, XtNcallback, FileQueryYes, callback);
  XtRemoveCallback(fileQueryNo,  XtNcallback, FileQueryNo,  callback);
  callback(False);
}
  

void FileQuery(message, callback)
  char  *message;
  void (*callback)();
{
  /* 
     Arrangement of boxes:

     +--------------------------+
     | +----------------------+ |
     | |    fileQueryLabel    | |
     | +----------------------+ |
     | +----------+ +---------+ |
     | | QueryYes | | QueryNo | |
     | +----------+ +---------+ |
     +--------------------------+
  */

  int         dir;
  int         asc;
  int         dsc;
  int         tWd;
  int         yWd;
  char       *msg;
  Position    rxr;
  Position    ryr;
  Dimension   lHt;
  Dimension   sHt;
  Dimension   lWd;
  Dimension   iSp;
  Dimension   bWd;
  XCharStruct info;

  XtManageChild(fileQueryNo);
  if (filename) {
    msg = (char *)XtMalloc(strlen(message) + strlen(filename) + 2);
    sprintf(msg, message, filename);
  } else msg = XtNewString(message);

  BEGARG;

  XTextExtents(fileButtonFont, msg, strlen(msg), &dir, &asc, &dsc, &info);
  sHt = asc + dsc; tWd = info.width;
  XTextExtents(fileButtonFont, "Yes", 8, &dir, &asc, &dsc, &info);
  yWd = info.width * 2;

  GETARG(fileQueryLabel, XtNborderWidth,    bWd);
  GETARG(fileQueryBox,   XtNvSpace,         iSp);
  GETARG(fileQueryLabel, XtNinternalHeight, lHt);

  SETARG(fileQueryLabel, XtNlabel,  msg);
  SETARG(fileQueryYes,   XtNlabel, "Yes");
  SETARG(fileQueryNo,    XtNlabel, "No");

  lWd = ((tWd > yWd) ? tWd : yWd) + 2*lHt + 2*bWd + 3*iSp;
  sHt = 2*sHt + 3*iSp + 5*bWd + 4*lHt;

  XtRealizeWidget(fileQueryPopup);

  SETARG(fileQueryPopup, XtNwidth,  lWd);
  SETARG(fileQueryPopup, XtNheight, sHt);
  SETARG(fileQueryBox,   XtNwidth,  lWd);
  SETARG(fileQueryBox,   XtNheight, sHt);

  XtTranslateCoords(filePopup, SHELLWIDTH/2 - lWd/2, SHELLHEIGHT/2 - sHt/2,
		    &rxr, &ryr);

  SETARG(fileQueryPopup, XtNx, rxr);
  SETARG(fileQueryPopup, XtNy, ryr);

  FINARG;

  XtAddCallback(fileQueryYes, XtNcallback, FileQueryYes, callback);
  XtAddCallback(fileQueryNo,  XtNcallback, FileQueryNo,  callback);
  XtPopup(fileQueryPopup, XtGrabNonexclusive);
  XtFree(msg);
  XRaiseWindow(XtDisplay(fileQueryPopup), XtWindow(fileQueryPopup));
  return;
}


Boolean FileDestroyWidgets()
{
  if (filePopup) XtDestroyWidget(filePopup);
  filePopup = NULL;
  return True;
}


Boolean FileCreateWidgets(parent)
  Widget parent;
{
  filePopup = XtCreatePopupShell("file selector", transientShellWidgetClass,
				 parent, NULL, 0);

  WIDGET(fileBox,      "fileBox",      boxWidgetClass,       filePopup);
  WIDGET(fileLabel,    "fileLabel",    labelWidgetClass,     fileBox);
  WIDGET(fileDir,      "fileDir",      labelWidgetClass,     fileBox);
  WIDGET(fileUp,       "fileUp",       commandWidgetClass,   fileBox);
  WIDGET(fileRescan,   "fileRescan",   commandWidgetClass,   fileBox);
  WIDGET(fileHidden,   "fileHidden",   commandWidgetClass,   fileBox);
  WIDGET(fileViewport, "fileViewport", viewportWidgetClass,  fileBox);
  WIDGET(fileList,     "fileList",     listWidgetClass,      fileViewport);
  WIDGET(fileNameNEd,  "fileNameNEd",  labelWidgetClass,     fileBox);
  WIDGET(fileNameEd,   "fileNameEd",   asciiTextWidgetClass, fileBox);
  WIDGET(fileOK,       "fileOK",       commandWidgetClass,   fileBox);
  WIDGET(fileCancel,   "fileCancel",   commandWidgetClass,   fileBox);

  fileQueryPopup = XtCreatePopupShell("question", transientShellWidgetClass,
				      parent, NULL, 0);

  WIDGET(fileQueryBox,   "fileQueryBox",   boxWidgetClass,     fileQueryPopup);
  WIDGET(fileQueryLabel, "fileQueryLabel", labelWidgetClass,   fileQueryBox);
  WIDGET(fileQueryYes,   "fileQueryYes",   commandWidgetClass, fileQueryBox);
  WIDGET(fileQueryNo,    "fileQueryNo",    commandWidgetClass, fileQueryBox);

  XtAddCallback(fileUp,     XtNcallback, FileUp,     0);
  XtAddCallback(fileRescan, XtNcallback, FileRescan, 0);
  XtAddCallback(fileHidden, XtNcallback, FileHidden, 0);
  XtAddCallback(fileList,   XtNcallback, FileList,   0);
  XtAddCallback(fileOK,     XtNcallback, FileApply,  0);
  XtAddCallback(fileCancel, XtNcallback, FileCancel, 0);

  return True;
}


Boolean FileSetDirLabel()
{
  char *bdS;
  Arg   arg[3];
  int   i;

  bdS = directory ? XtNewString(directory) : XtNewString("");
  i = 0; XtSetArg(arg[i], XtNlabel,   bdS); i++;
         XtSetArg(arg[i], XtNheight, tlHt); i++;
         XtSetArg(arg[i], XtNwidth,  tlWd); i++;
  XtSetValues(fileDir, arg, i);
  XtFree(bdS);

  return True;
}


/* Scan a string, expanding all environment variables found in it (ie.  */
/* anything beginning with `$'.  Return a new string, in space obtained */
/* from XtMalloc, containing the expanded version.  If any environment  */
/* variable is unobtainable, complain to stderr (only the first time it */
/* happens), and then return NULL.  Non-NULL returns can be XtFree'd.   */

char *FileExpandForEnvironment(str)
  char *str;
{
  char          *vv;
  int            i,j,k;
  static char    vn[NAME_MAX + 1];
  static char    wk[NAME_MAX + PATH_MAX + 1];
  static Boolean complained = False;

  for (i = k = 0; str[i]; ) {

    if (str[i] == '$') {

      for (j = ++i; str[j] && j-i < NAME_MAX &&
	   (isalnum(str[j]) || str[j] == '_'); ++j) vn[j-i] = str[j];

      vn[j-i] = 0;

      if (vv = getenv(vn)) { strcpy(wk + k, vv); k += strlen(vv); }
      else {
	if (!complained) {
	  fprintf(stderr,
        "File Handler: Couldn't get value of environment variable $%s\n", vn);
	  complained = True;
	} return NULL;
      }

      i = j;

    } else wk[k++] = str[i++];
  }

  wk[k] = 0;

  return XtNewString(wk);
}



void FileConsolidateFilename()
{
  if (Editable) {

    Arg   arg;
    char *str;

    XtSetArg(arg, XtNstring, &str);
    XtGetValues(fileNameEd, &arg, 1);

    if (filename) XtFree(filename);
    filename = XtNewString(str);
  }
}


Boolean FileSetFileLabel()
{
  char *bdS;
  Arg   arg[4];
  int   i = 0;

  bdS = (char *)XtMalloc(10 + (filename ? strlen(filename) : 0));
  sprintf(bdS, "%s%s", Editable ? "" : "File: ", filename ? filename : "");

  if (Editable) XtSetArg(arg[i], XtNstring, bdS);
  else          XtSetArg(arg[i], XtNlabel,  bdS);

  i++;
  XtSetArg(arg[i], XtNheight, tlHt); i++;
  XtSetArg(arg[i], XtNwidth,  tfWd); i++;
  XtSetValues(fileName, arg, i);

  if (Editable) XawTextSetInsertionPoint(fileName, strlen(bdS));

  XtFree(bdS);
  return True;
}


Boolean FileSetHideLabel()
{
  Arg arg[3];
  int i;

  i = 0; XtSetArg(arg[i], XtNlabel,  GlobDots ? "Hide" : "Show"); i++;
         XtSetArg(arg[i], XtNheight, tlHt); i++;
         XtSetArg(arg[i], XtNwidth,  tbWd); i++;
  XtSetValues(fileHidden, arg, i);

  return True;
}


Boolean FileSetFileNameList()
{
  Arg            arg[4];
  int            i;
  int            dir;
  int            asc;
  int            dsc;
  int            mwd = 0;
  static Boolean fileNLSet = False;
  XCharStruct    info;

  for (i = 0; i < filecount && filecall[i]; ++i) {

    XTextExtents(fileTextFont, filecall[i], strlen(filecall[i]),
		 &dir, &asc, &dsc, &info);

    if (info.width > mwd) mwd = info.width;
  }

  if (!fileNLSet) {

    i = 0;
    XtSetArg(arg[i], XtNlist,          filecall);  i++;
    XtSetArg(arg[i], XtNnumberStrings, filecount); i++;
    XtSetArg(arg[i], XtNlongest,       mwd + 6);   i++;
    XtSetValues(fileList, arg, i);
    fileNLSet = True;

  } else {

    XawListChange(fileList, filecall, filecount, mwd + 6, True);
  }

  XawListUnhighlight(fileList);

  if (XtIsRealized(fileViewport) &&
      XtIsRealized(fileList)) FileViewportSetHeight(fileViewport, fileList, 0);

  i = 0;
  XtSetArg(arg[i], XtNwidth,  tlWd - 16); i++;
  XtSetValues(fileList, arg, i);

  i = 0;
  XtSetArg(arg[i], XtNheight, tvHt); i++;
  XtSetArg(arg[i], XtNwidth,  tlWd); i++;
  XtSetValues(fileViewport, arg, i);

  return True;
}



char *FileDirCat(a,b)
  char *a;
  char *b;
{
  char *r;
  char *s;
  char *t;
  int   i, j;

  r = (char *)XtMalloc(strlen(a) + strlen(b) + 2);
  sprintf(r, "%s/%s", a, b);

  if (!(s = getcwd(NULL, PATH_MAX + NAME_MAX)))
    { XtFree(r); return NULL; }

  if (chdir(r))
    { XtFree(r); free(s); return NULL; }

  if (!(t = getcwd(NULL, PATH_MAX + NAME_MAX)))
    { XtFree(r); free(s); return NULL; }

  if (chdir(s))
    { XtFree(r); free(s); free(t); return NULL; }

  XtFree(r); free(s);
  r = XtNewString(t);
  free(t); return r;
}



/* This function makes the visible representation of the filename.     */
/* It is passed i, and assumes filename[i] and filetype[i] are present */
/* and correct in order to produce a name (to go into filecall[i]).    */

char *FileMakeFileCall(i)
  int i;
{
  char *call;
  uid_t uid;
  gid_t gid;
  int   len;
  char  ind = 0;

  uid  = getuid();
  gid  = getgid();
  call = (char *)XtMalloc(4 + (len = strlen(filelist[i].name)));

  if      ((filelist[i].mode & S_IFDIR)  == S_IFDIR)  ind = '/';
  else if ((filelist[i].mode & S_IFLNK)  == S_IFLNK)  ind = '@';
  else if ((filelist[i].mode & S_IFSOCK) == S_IFSOCK) ind = '=';
  else if ((filelist[i].uid == uid && (filelist[i].mode & S_IXUSR)) ||
	   (filelist[i].gid == gid && (filelist[i].mode & S_IXGRP)) ||
	   (filelist[i].uid != uid &&  filelist[i].gid != gid &&
	    (filelist[i].mode & S_IXOTH))) ind = '*';

  sprintf(call, " %s%c%s", filelist[i].name, ind ? ind : ' ', ind ? " " : "");
  return  call;
}


int FileStrCmpP(a,b)
  char *a;
  char *b;
{
  ftstruct *ca;
  ftstruct *cb;

  ca = (ftstruct *)a;
  cb = (ftstruct *)b;

  if (File) return strcmp(ca->call, cb->call);

  if (ca->name[0] == '.' && cb->name[0] != '.') return -1;
  if (cb->name[0] == '.' && ca->name[0] != '.') return  1;

  if   (S_ISDIR(ca->mode))
    if (S_ISDIR(cb->mode)) return strcmp(ca->name, cb->name);
    else return -1;
  else
    if (S_ISDIR(cb->mode)) return 1;

  return strcmp(ca->name, cb->name);
}


Boolean FileTestIndexFileStat(np)
  char *np;
{
  struct stat bf;
  uid_t       uid;
  gid_t       gid;
  Boolean     rst;

  uid = getuid();
  gid = getgid();

  if (!stat(np, &bf)) {

    if (!strcmp(Type, "r")  || !strcmp(Type, "r+") ||
	!strcmp(Type, "w+") || !strcmp(Type, "a+")) {

      rst = ((bf.st_uid == uid && (bf.st_mode & S_IRUSR)) ||
	     (bf.st_gid == gid && (bf.st_mode & S_IRGRP)) ||
	     (bf.st_uid != uid &&
	      bf.st_gid != gid && (bf.st_mode & S_IROTH)));

      if (!rst || !strcmp(Type, "r")) return rst;
    }

    if (!strcmp(Type, "w")  || !strcmp(Type, "a")  ||
	!strcmp(Type, "r+") || !strcmp(Type, "w+") || !strcmp(Type, "a+")) {

      rst = ((bf.st_uid == uid && (bf.st_mode & S_IWUSR)) ||
	     (bf.st_gid == gid && (bf.st_mode & S_IWGRP)) ||
	     (bf.st_uid != uid &&
	      bf.st_gid != gid && (bf.st_mode & S_IWOTH)));

      return rst;
    }
  } else {

    if (errno == ENOENT &&
	(!strcmp(Type, "w")  || !strcmp(Type, "a")  ||
	 !strcmp(Type, "r+") || !strcmp(Type, "w+") || !strcmp(Type, "a+"))) {

      if (creat(np, S_IRUSR | S_IWUSR | S_IFREG) >= 0) {

	if (unlink(np)) perror("File Handler");
	return True;

      } else {

	perror("File Handler");
	return False;
      }
    } else return False;
  }
}



Boolean FileGetFileList()
{
  int            i,j;
  int            len;
  struct stat    bf;
  char           path[PATH_MAX + NAME_MAX + 1];

  if (!directory) return False;

  if (filelist) {
    for (i = 0; i < MAXNROFFILES && filelist[i].name; ++i) {
      XtFree(filelist[i].name);
      if (filelist[i].retn) XtFree(filelist[i].retn);
    }
    XtFree((char *)filelist);
  }
  if (filecall) {
    for (i = 0; i < MAXNROFFILES && filecall[i]; ++i) XtFree(filecall[i]);
    XtFree((char *)filecall);
  }
  
  filecall = (char    **)XtCalloc(MAXNROFFILES, sizeof(char   *));
  filelist = (ftstruct *)XtCalloc(MAXNROFFILES, sizeof(ftstruct));

  if (!File) {

    struct dirent *dp;
    DIR           *dirP;

    if (!(dirP = opendir(directory))) return False;

    strcpy(path, directory);
    strcpy(path + (len = strlen(directory)), "/");

    for (dp = readdir(dirP), i = 0; dp != NULL && i < MAXNROFFILES;
	 dp = readdir(dirP),  ++ i) {

      if (!strcmp(dp->d_name, ".")  ||
	  !strcmp(dp->d_name, "..") ||
	  (!GlobDots && (dp->d_name[0] == '.' ||
			 dp->d_name[j = strlen(dp->d_name) - 1] == '~' ||
			 dp->d_name[j] == '#' ||
			 dp->d_name[j] == '%'))) --i;
      else {
	strcpy(path + len + 1, dp->d_name);
	if (stat(path, &bf)) -- i;
	else {
	  filelist[i].retn = NULL;
	  filelist[i].name = XtNewString(dp->d_name);
	  filelist[i].mode = bf.st_mode;
	  filelist[i].uid  = bf.st_uid;
	  filelist[i].gid  = bf.st_gid;
	}
      }
    }

    if (closedir(dirP)) { perror("File Handler"); return False; }
    filecount = i;
    qsort(filelist, (size_t)filecount, sizeof(ftstruct), FileStrCmpP);

    for (i = 0; i < filecount; ++i) {

      filecall[i]      = FileMakeFileCall(i);
      filelist[i].call = filecall[i];
    }
    return True;

  } else {

    int   k,m;
    int   len;
    char *np;
    char  rn[512];
    FILE *fileP;

    if (!(fileP = fopen(directory, "r"))) return False;
    i = 0;

    while(fgets(rn, 511, fileP)) {

      for (j = k = 0; rn[j]; ++j) {

	if (rn[j] == ':' && rn[j+1] == ':')

	  if (k == 0) { rn[m = j] = 0; ++ k; m += 2; }
	  else {

	    rn[j] = 0;

	    if (np = FileExpandForEnvironment(rn + m)) {

	      if (!(FileTestIndexFileStat(np))) { XtFree(np); break; }

	      filelist[i].name = np;
	      filelist[i].retn = XtNewString(rn + j + 2);
	      filelist[i].call = XtNewString(rn);

	      if ((len = strlen(filelist[i].retn)) > 0) {

		if (filelist[i].retn[len - 1] == '\n')
                    filelist[i].retn[len - 1] = 0;
		i++; break;
	      }
	    }
	  }
      }
    }

    fclose(fileP);
    filecount = i;

    qsort(filelist, (size_t)filecount, sizeof(ftstruct), FileStrCmpP);
    for (i = 0; i < filecount; ++i) filecall[i] = filelist[i].call;

    return True;
  }
}


void FileAbandon()
{
  int i;

  if (directory) XtFree(directory);
  directory = NULL;
  if (filename)  XtFree(filename);
  filename  = NULL;
  Callback  = NULL;

  if (filecall) {
    for (i = 0; i < MAXNROFFILES && filecall[i]; ++i) XtFree(filecall[i]);
    XtFree((char *)filecall);
  }
  filecall = NULL;

  if (filelist) {
    for (i = 0; i < filecount; ++i) {
      if (filelist[i].name) XtFree(filelist[i].name);
    } XtFree((char *)filelist);
  }
  filelist  = NULL;
  filecount = 0;

  if (filePopup) {
    XtSetSensitive(fileOK,     False);
    XtSetSensitive(fileCancel, False);
    XtPopdown(filePopup);
    XtSetSensitive(fileOK,     True);
    XtSetSensitive(fileCancel, True);
    XtUnrealizeWidget(filePopup);
  }
}


/* ARGSUSED */
void FileCancel(w, a, b)
  Widget  w;
  caddr_t a,b;
{
  FileAbandon();
  return;
}


Boolean FileChDir(newdir)
  char *newdir;
{
  char *nd;

  FileConsolidateFilename();

  if (filename && filename[0] != '/') {
    nd = (char *)XtMalloc(strlen(directory) + strlen(filename) + 2);
    sprintf(nd, "%s/%s", directory, filename);
    XtFree(filename);
    filename = nd;
  }

  if (!(nd = FileDirCat(directory ? directory : ".", newdir))) goto oops;
  if (directory) XtFree(directory);
  directory = nd;

  Try(FileSetFileLabel());
  Try(FileSetDirLabel());
  Try(FileGetFileList());
  Try(FileSetFileNameList());
  return True;

 oops:
  if (!nd && errno == EACCES)
    FileError("Permission denied on directory ``%s''", directory);
  else
    FileError("Cannot read directory ``%s''", directory);
  return False;
}


/* ARGSUSED */
void FileList(w, a, d)
  Widget               w;
  caddr_t              a;
  XawListReturnStruct *d;
{
  int       n;
  int       i = 0;
  Arg       arg[2];
  Dimension vh;
  Dimension bh;
  Position  by;

  XtSetArg(arg[i], XtNheight,       &bh); i++;
  XtSetArg(arg[i], XtNnumberStrings, &n); i++;
  XtGetValues(fileList, arg, i);

  i = 0;
  XtSetArg(arg[i], XtNheight, &vh); i++;
  XtGetValues(fileViewport, arg, i);

  by = (Position)((((unsigned long int)((unsigned)bh))/n) * d->list_index);

  if (((Dimension)by + (bh/(2*n))) <= (vh/2)) {
    FileViewportSetHeight(fileViewport, fileList, 0);
  } else {
    FileViewportSetHeight(fileViewport, fileList,
			  (Dimension)by + (bh/(2*n)) - vh/2);
  }

  if (S_ISDIR(filelist[d->list_index].mode)) {

    Try(FileChDir(filelist[d->list_index].name));
    return;

  } else {

    if (filename) XtFree(filename);
    if (File) filename = XtNewString(filelist[d->list_index].call);
    else      filename = XtNewString(filelist[d->list_index].name);
    Try(FileSetFileLabel());
    return;
  }

 oops: return;
}


/* ARGSUSED */
void FileUp(w, a, b)		/* ... or should that be FoulUp ? */
  Widget w;
  caddr_t a,b;
{
  Try(FileChDir(".."));
  return;

 oops: return;
}


/* ARGSUSED */
void FileRescan(w, a, b)
  Widget w;
  caddr_t a,b;
{
  if (!directory) if (!(directory = FileDirCat(".","."))) goto oops;

  Try(FileSetDirLabel());
  Try(FileGetFileList());
  Try(FileSetFileNameList());
  return;

 oops:
  FileError("Couldn't reopen current directory. I'm confused.", NULL);
  return;
}


/* ARGSUSED */
void FileHidden(w, a, b)
  Widget w;
  caddr_t a,b;
{
  GlobDots = !GlobDots;

  Try(FileSetHideLabel());
  FileRescan(w, a, b);
  return;

 oops:
  fprintf(stderr, "File Handler: Couldn't set Hide label\n");
  return;
}


Boolean FileInstallFonts()
{
  Arg arg;

  if (!fileTextFont || !fileButtonFont) {
    fprintf(stderr,"File Handler: Fonts incorrectly specified\n");
    return False;
  }

  XtSetArg(arg, XtNfont,      fileTextFont);
  XtSetValues(fileList,       &arg, 1);
  XtSetArg(arg, XtNfont,      fileButtonFont);
  XtSetValues(fileLabel,      &arg, 1);
  XtSetValues(fileDir,        &arg, 1);
  XtSetValues(fileUp,         &arg, 1);
  XtSetValues(fileRescan,     &arg, 1);
  XtSetValues(fileHidden,     &arg, 1);
  XtSetValues(fileNameNEd,    &arg, 1);
  XtSetValues(fileNameEd,     &arg, 1);
  XtSetValues(fileOK,         &arg, 1);
  XtSetValues(fileCancel,     &arg, 1);
  XtSetValues(fileQueryLabel, &arg, 1);
  XtSetValues(fileQueryYes,   &arg, 1);
  XtSetValues(fileQueryNo,    &arg, 1);

  return True;
}


void FileSetFonts(parent, bf, tf)
  Widget       parent;
  XFontStruct *bf;
  XFontStruct *tf;
{
  if (parent != referenceWidget) Try(FileDestroyWidgets());
  if (filePopup == NULL)         Try(FileCreateWidgets(parent));
  if (fileButtonFont)            XtFree((char *)fileButtonFont);
  if (fileTextFont)              XtFree((char *)fileTextFont);

  referenceWidget = parent;
   fileButtonFont = (XFontStruct *)XtMalloc(sizeof(XFontStruct));
   fileTextFont   = (XFontStruct *)XtMalloc(sizeof(XFontStruct));
  *fileButtonFont = *bf;
  *fileTextFont   = *tf;

  (void)FileInstallFonts();

 oops: return;
}



Boolean FileContourAndInstallWidgets(purpose)
  char * purpose;
{
  int         dir;
  int         asc;
  int         dsc;
  int         tWd;
  int         tHt;
  int         bHt;
  Position    rxr;
  Position    ryr;
  Dimension   sWd;
  Dimension   sHt;
  Dimension   iSp;
  Dimension   bWd;
  Dimension   fWd;
  Dimension   lHt;
  XCharStruct info;
  XSizeHints  size;
  Atom        wmPrtcls[2];

  /*
     Arrangement of boxes:

     +-------------------------------+
     | +---------------------------+ |
     | |         fileLabel         | |
     | +---------------------------+ |
     | +---------------------------+ |
     | |          fileDir          | |
     | +---------------------------+ |
     | +-------+ +-------+ +-------+ |
     | |  Up   | |Rescan | |Hidden | |
     | +-------+ +-------+ +-------+ |
     | +---------------------------+ |
     | |                           | |
     | |        fileViewport,      | |
     | |         containing        | |
     | |          fileList         | |
     | |                           | |
     | +---------------------------+ |
     | +---------------------------+ |      | +---------+ +---------------+ | 
     | |          fileName         | |  or: | | NameNEd | | fileNameEd    | |
     | +---------------------------+ |      | +---------+ +---------------+ |
     | +------------+ +------------+ |
     | |   fileOK   | | fileCancel | |
     | +------------+ +------------+ |
     +-------------------------------+

     A picture is worth a thousand words
  */

  if (Editable) {

    XtManageChild(fileNameEd);
    fileName = fileNameEd;

  } else {

    XtUnmanageChild(fileNameEd);
    fileName = fileNameNEd;
  }

  BEGARG;

  XTextExtents(fileTextFont,   purpose, strlen(purpose), &dir,&asc,&dsc,&info);
  tHt = asc + dsc; tWd = info.width;
  XTextExtents(fileButtonFont, purpose, strlen(purpose), &dir,&asc,&dsc,&info);
  bHt = asc + dsc;
  XTextExtents(fileButtonFont, "File: ", 6, &dir, &asc, &dsc, &info);
  fWd = info.width;

  SETARG(fileLabel,    XtNlabel,          purpose);
  GETARG(fileBox,      XtNvSpace,         iSp);
  GETARG(fileBox,      XtNborderWidth,    bWd);
  GETARG(fileLabel,    XtNinternalHeight, lHt);

  SETARG(fileViewport, XtNallowVert,  True);
  SETARG(fileViewport, XtNforceBars,  True);
  SETARG(fileDir,      XtNjustify,    XtJustifyCenter);
  SETARG(fileNameNEd,  XtNjustify,    XtJustifyLeft);
  SETARG(fileNameEd,   XtNeditType,   XawtextEdit);

  SETARG(fileUp,       XtNlabel,     "Up");
  SETARG(fileRescan,   XtNlabel, "Rescan");
  SETARG(fileOK,       XtNlabel,  "Apply");
  SETARG(fileCancel,   XtNlabel, "Cancel");

  if (!tlHt) tlHt = bHt + 2*lHt + 2*bWd;
  if (!tlWd) tlWd =  SHELLWIDTH  - 2*iSp -  2*bWd;
  if (!tbWd) tbWd = (SHELLWIDTH  - 4*iSp -  6*bWd) / 3;
  if (!tvHt) tvHt =  SHELLHEIGHT - 7*iSp - 12*bWd - 5*tlHt;
  if (!taWd) taWd = (SHELLWIDTH  - 3*iSp -  4*bWd) / 2;

  SETARG(fileLabel,    XtNheight, tlHt);
  SETARG(fileLabel,    XtNwidth,  tlWd);
  SETARG(fileDir,      XtNheight, tlHt);
  SETARG(fileDir,      XtNwidth,  tlWd);
  SETARG(fileUp,       XtNwidth,  tbWd);
  SETARG(fileUp,       XtNheight, tlHt);
  SETARG(fileRescan,   XtNwidth,  tbWd);
  SETARG(fileRescan,   XtNheight, tlHt);
  SETARG(fileHidden,   XtNwidth,  tbWd);
  SETARG(fileHidden,   XtNheight, tlHt);
  SETARG(fileNameNEd,  XtNheight, tlHt);
  fWd += 2 * iSp;

  if (Editable) {

    if (!tfWd || tfWd == tlWd) tfWd = tlWd - 2*iSp - 4*bWd - fWd;
    SETARG(fileNameNEd, XtNwidth,   fWd);
    SETARG(fileNameEd,  XtNwidth,  tfWd);
    SETARG(fileNameEd,  XtNheight, tlHt);
    SETARG(fileNameNEd, XtNlabel, "File: ");

  } else {

    tfWd = tlWd;
    SETARG(fileNameNEd, XtNwidth, tfWd);
  }

  SETARG(fileNameNEd,  XtNheight, tlHt);
  SETARG(fileOK,       XtNheight, tlHt);
  SETARG(fileOK,       XtNwidth,  taWd);
  SETARG(fileCancel,   XtNheight, tlHt);
  SETARG(fileCancel,   XtNwidth,  taWd);
  SETARG(fileViewport, XtNheight, tvHt);
  SETARG(fileViewport, XtNwidth,  tlWd);

  Try(FileGetFileList());

  if ((filecount == 0) && File) {

    FileError(Error, NULL);
    FileAbandon();
    return False;
  }


  Try(FileSetDirLabel());
  Try(FileSetHideLabel());
  Try(FileSetFileLabel());
  Try(FileSetFileNameList());

  XtRealizeWidget(filePopup);

  SETARG(filePopup, XtNwidth,  SHELLWIDTH);
  SETARG(filePopup, XtNheight, SHELLHEIGHT);
  SETARG(fileBox,   XtNwidth,  SHELLWIDTH);
  SETARG(fileBox,   XtNheight, SHELLHEIGHT);

  XtTranslateCoords(referenceWidget, 150, -15, &rxr, &ryr);

  sWd =  DisplayWidth(XtDisplay(referenceWidget),
		      DefaultScreen(XtDisplay(referenceWidget)));
  sHt = DisplayHeight(XtDisplay(referenceWidget),
		      DefaultScreen(XtDisplay(referenceWidget)));

  if (rxr + SHELLWIDTH  > sWd) rxr = sWd - SHELLWIDTH;
  if (ryr + SHELLHEIGHT > sHt) ryr = sHt - SHELLHEIGHT;
  if (rxr < 0) rxr = 0;
  if (ryr < 0) ryr = 0;

  SETARG(filePopup, XtNx, rxr);
  SETARG(filePopup, XtNy, ryr);

  FINARG;

  if (File) {

    XtSetSensitive(fileUp,     False);
    XtSetSensitive(fileRescan, False);
    XtSetSensitive(fileHidden, False);

  } else {

    XtSetSensitive(fileUp,     True);
    XtSetSensitive(fileRescan, True);
    XtSetSensitive(fileHidden, True);
  }

  size.flags = PMinSize | PMaxSize;
  size.min_width  = SHELLWIDTH;
  size.max_width  = SHELLWIDTH;
  size.min_height = SHELLHEIGHT;
  size.max_height = SHELLHEIGHT;

  XtPopup(filePopup, XtGrabNonexclusive);
  XRaiseWindow(XtDisplay(filePopup), XtWindow(filePopup));
  XSetWMNormalHints(XtDisplay(filePopup), XtWindow(filePopup), &size);

  wmPrtcls[0] =
    XInternAtom(XtDisplay(filePopup), "WM_DELETE_WINDOW", False);
  wmPrtcls[1] =
    XInternAtom(XtDisplay(filePopup), "WM_SAVE_YOURSELF", False);

  XtOverrideTranslations
    (filePopup,
     XtParseTranslationTable("<Message>WM_PROTOCOLS: reduce-file-done()"));

  XSetWMProtocols(XtDisplay(filePopup), XtWindow(filePopup), wmPrtcls, 2);

  return True;

 oops: return False;
}


/* Attempt to open a single path element -- ie. a file or directory name, */
/* rather then a full path list (the sort with colons in it).  Expands    */
/* environment variables and makes the path absolute; if fileFlg is True  */
/* it will allow the path to be either file (in which case the file read  */
/* convention will be used) or directory (in which case the `directory'   */
/* variable will be set); otherwise only directories will be allowed.     */
/* If both fileFlg and forceFlg are True, *only* files will be allowed,   */
/* not directories.  Returns True for success and False for failure.      */

Boolean FileOpenPathElt(path, fileFlg, forceFlg)
  char   *path;
  Boolean fileFlg;
  Boolean forceFlg;
{
  char       *np;
  struct stat bf;

  if (!(np = FileExpandForEnvironment(path))) return False;

  if (stat(np, &bf)) return False;
  if (S_ISDIR(bf.st_mode) && !(fileFlg && forceFlg)) {

    if (np[0] == '/') directory = FileDirCat(np, ".");
    else              directory = FileDirCat(".", np);

    XtFree(np);

    if (directory) return True;
    else           return False;

  } else if (fileFlg && S_ISREG(bf.st_mode)) {

    directory = np;

    return (File = True);

  } else {

    XtFree(np);

    return False;
  }
}



/* Attempt to open a path and place the current directory in `directory'. */
/* Args are path string, a flag to say whether a file is acceptable as a  */
/* path -- if True, then the file reading convention will be used and a   */
/* list of names (rather than actual files) gleaned from it to present to */
/* the user --, and a flag which if True declares that if there is only a */
/* single element to the path, it must be of the type indicated by the    */
/* file flag (directory if file flag is False and file if True).  Returns */
/* True if successful, or False (and pops up an error box) for failure.   */

Boolean FileOpenPath(path, fileFlg, forceFlg)
  char   *path;
  Boolean fileFlg;
  Boolean forceFlg;
{
  int   i;
  int   len;
  int   sc = True;
  char *np = NULL;

  File = False;

  if (!path) {

    directory = FileDirCat(".","");
    if (!directory && !(directory = FileDirCat(".","."))) goto oops;

  } else {

    np = XtNewString(path);

    for (i = 0, len = strlen(np); i < len && np[i] != ':'; ++i);
    if  (i >= len)    for (i = 0; i < len && np[i] != '|'; ++i);
    if  (i >= len) sc = FileOpenPathElt(np, fileFlg, forceFlg);
    else {

      fileFlg  = (np[i] == '|'); np[i] = 0;
      if (!(sc = FileOpenPathElt(np,  fileFlg, True)) &&
	  !(sc = FileOpenPath(np+i+1, fileFlg, True))) goto oops;
    }

    XtFree(np);
    np = NULL;
  }

  if (sc) return True;
  FileError(Error, NULL);
  /* fall on through */

 oops:

  if (np) XtFree(np);

  return False;
}



Boolean FileGetFilename(parent, purpose, error, path,
			type, prefix, testp, openp, callback)
  Widget  parent;
  char   *purpose;
  char   *error;
  char   *path;
  char   *type;
  char   *prefix;
  Boolean testp;
  Boolean openp;
  void  (*callback)();
{
  Error    = XtNewString(error);
  Type     = XtNewString(type);
  Testp    = testp;
  Openp    = openp;
  Callback = callback;
  GlobDots = False;
  Editable = strcmp(type,"r");

  if (parent != referenceWidget) Try(FileDestroyWidgets());
  referenceWidget = parent;
  Try(FileOpenPath(path, True, False));
  if (!directory) return False;

  if (File) {

    if (filename) XtFree(filename);
    filename = NULL;
    Editable = False;

  } else {

    if (filename) XtFree(filename);
    if (!prefix) filename = NULL;
    else {
      char *nc;

      if (!(nc = tempnam(directory, prefix))) goto oops;

      if (strncmp(directory, nc, strlen(directory)))
	filename = XtNewString(nc); /* Want to use Xt allocator because  */
				    /* we're going to use Xt deallocator */
      else if (nc[strlen(directory)] == '/')
	filename = XtNewString(nc + strlen(directory) + 1);
      else
	filename = XtNewString(nc + strlen(directory));

      free(nc);
    }
  }

 if (filePopup == NULL) Try(FileCreateWidgets(parent));
  Try(FileContourAndInstallWidgets(purpose));

  return True;

 oops:

 return False;
}



void FileApplyAux(success)
  Boolean success;
{
  struct stat bf;
  uid_t       uid;
  gid_t       gid;
  FILE       *fptr = NULL;

  if (!success) return;

  /* Right, we've checked that the file either exists (if the requested */
  /* type is "r", "a", "r+" or "a+") or doesn't (if the requested type  */
  /* is "w", "w+" or "r+"), or that the user doesn't mind this state of */
  /* affairs; now if we can't read or write (as appropriate) the file,  */
  /* we're still going to have to complain about it.                    */

  /* Of course, we can assume that a nonexistent file can now be safely */
  /* created in silence, as we've checked that below.                   */

  uid = getuid();
  gid = getgid();

  if (stat(filename,&bf)) {
    if (errno != ENOENT) {

      FileError("Cannot open ``%s''", filename);
      return;
    }
  } else {

    if (!strcmp(Type, "a")  ||
	!strcmp(Type, "a+") ||
	!strcmp(Type, "r")  ||
	!strcmp(Type, "r+")) {

      if (!((bf.st_uid == uid && (bf.st_mode & S_IRUSR)) ||
	    (bf.st_gid == gid && (bf.st_mode & S_IRGRP)) ||
	    (bf.st_uid != uid &&  bf.st_gid != gid &&
	     (bf.st_mode & S_IROTH)))) {
	FileError("Read permission denied on ``%s''", filename);
	return;
      }
    }

    if (!strcmp(Type, "a")  ||
	!strcmp(Type, "a+") ||
	!strcmp(Type, "r+") ||
	!strcmp(Type, "w")  ||
	!strcmp(Type, "w+")) {

      if (!((bf.st_uid == uid && (bf.st_mode & S_IWUSR)) ||
	    (bf.st_gid == gid && (bf.st_mode & S_IWGRP)) ||
	    (bf.st_uid != uid &&  bf.st_gid != gid &&
	     (bf.st_mode & S_IWOTH)))) {
	FileError("Write permission denied on ``%s''", filename);
	return;
      }
    }
  }

  if (Openp && !(fptr = fopen(filename, Type))) {
    FileError("Cannot open ``%s''", filename);
    return;
  }

  if (Callback) Callback(XtNewString(filename), fptr);
  FileAbandon();
  return;
}



/* ARGSUSED */
void FileApply(w, a, b)
  Widget w;
  caddr_t a,b;
{
  char       *nd;
  Boolean     exists = True;
  struct stat bf;

  FileConsolidateFilename();

  if (!filename || strlen(filename) == 0) {
    if (Callback) Callback(NULL,NULL);
    FileAbandon();
    return;
  }

  if (File) {

    int   i;
    FILE *fptr;

    for (i = 0; i < MAXNROFFILES && filelist[i].name &&
	 strcmp(filename, filelist[i].call); i ++);

    if (i >= MAXNROFFILES || !(filelist[i].name)) Callback(NULL, NULL);
    else {

      if (Openp && (fptr = fopen(filelist[i].name, Type)))
	Callback(XtNewString(filelist[i].retn), fptr);
      else
	Callback(XtNewString(filelist[i].retn), NULL);
    }

    FileAbandon();
    return;

  } else {

    if (filename[0] != '/') {
      nd = (char *)XtMalloc(strlen(directory) + strlen(filename) + 2);
      sprintf(nd, "%s/%s", directory, filename);
      XtFree(filename);
      filename = nd;
    }

    if (stat(filename, &bf))
      if (errno == ENOENT) exists = False;
      else {
	FileError("Cannot open ``%s''",filename);
	return;
      }

    if      (Testp &&
	     (exists  &&
	      (!strcmp(Type, "w")    ||
	       !strcmp(Type, "w+")   ||
	       !strcmp(Type, "r+"))))
      FileQuery("File ``%s'' exists. Overwrite?", FileApplyAux);

    else if (Testp &&
	     (!exists &&
	      (!strcmp(Type, "a")    ||
	       !strcmp(Type, "a+")   ||
	       !strcmp(Type, "r+"))))
      FileQuery("File ``%s'' doesn't exist. Create it?", FileApplyAux);

    else FileApplyAux(True);
 
    return;
  }
}

