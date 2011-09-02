/*
 * This file provides a description of the interface to the version
 * of "StdWin" used with CSL.  Some of this is taken from the StdWin
 * source. Used with permission.
 *
 *  Copyright 1988-1995 by Stichting Mathematisch Centrum, Amsterdam, The
 *  Netherlands.
 *
 *                          All Rights Reserved
 */

/* Signature: 6979b37c 11-Jun-1996 */

#ifndef __STDWIN_H__	/* Guard against multiple inclusion */
#define __STDWIN_H__

#include "_ARGS.h"	/* Definition of _ARGS() macro */


/***********************************/
/* Section 1.  Types and constants */
/***********************************/


/* These structs are implementation-dependent, the user only sees
   pointers to them */

#define WINDOW struct _window
#define MENU struct _menu
#define CURSOR struct _cursor
#define BITMAP struct _bitmap


/* Fake window type used by the wgettag() and wsettag() macros */

struct _fakewindow {
	short tag;
};

#define _FAKEWINDOW struct _fakewindow


/* EVENT struct */

struct _event {
	int type;
	WINDOW *window;
	union {
	/* case WE_CHAR: */
		int character;
	/* case WE_COMMAND: */
		int command;
	/* case WE_MENU: */
		struct { int id; int item; } m;
	/* case WE_DRAW: */
		struct { int left, top, right, bottom; } area;
	/* case WE_MOUSE_DOWN, WE_MOUSE_MOVE, WE_MOUSE_UP: */
		struct {
			int h;
			int v;
			int clicks;
			int button;
			int mask;
		} where;
	/* case WE_LOST_SEL: */
		int sel;
	/* case WE_KEY: */
		struct { int code; int mask; } key;
	} u;
};

#define EVENT struct _event


/* Event types */
/* XXX Should be reordered */

#define WE_NULL		0	/* (Used internally) */
#define WE_ACTIVATE	1	/* Window became active */
#define WE_CHAR		2	/* Character typed at keyboard */
#define WE_COMMAND	3	/* Special command, function key etc. */
#define WE_MOUSE_DOWN	4	/* Mouse button pressed */
#define WE_MOUSE_MOVE	5	/* Mouse moved with button down */
#define WE_MOUSE_UP	6	/* Mouse button released */
#define WE_MENU		7	/* Menu item selected */
#define WE_SIZE		8	/* Window size changed */
#define WE_MOVE		9	/* Window moved (reserved) */
#define WE_DRAW		10	/* Request to redraw part of window */
#define WE_TIMER	11	/* Window's timer went off */
#define WE_DEACTIVATE	12	/* Window became inactive */
#define WE_EXTERN	13	/* Externally generated event (Amoeba) */
#define WE_KEY		14	/* Non-ASCII key event */
#define WE_LOST_SEL	15	/* Lost selection */
#define WE_CLOSE	16	/* User wants to close window */


/* Special keys reported by WE_COMMAND */
/* XXX Should become key events */

#define WC_CLOSE	1	/* Obsolete */
/* The following four are arrow keys */
#define WC_LEFT		2
#define WC_RIGHT	3
#define WC_UP		4
#define WC_DOWN		5
/* ASCII keys */
#define WC_CANCEL	6
#define WC_BACKSPACE	7
#define WC_TAB		8
#define WC_RETURN	9
/* IBM-PC keys -- not in all implementations */
/* XXX Should be done differently */
#define WC_HOME		10
#define WC_END		11
#define WC_CLEAR	12
#define WC_INS		13
#define WC_DEL		14
#define WC_PAGE_UP	15
#define WC_PAGE_DOWN	16
#define WC_META_LEFT	17
#define WC_META_RIGHT	18
#define WC_META_HOME	19
#define WC_META_END	20
#define WC_META_PAGE_UP	21
#define WC_META_PAGE_DOWN	22
/* XXX Should have entries for Alt-letter and F1-F10 etc. ? */


/* Codes for selections (e.u.sel for WE_LOST_SEL) */

#define WS_CLIPBOARD	0
#define WS_PRIMARY	1
#define WS_SECONDARY	2


/* Masks for EVENT->u.where.mask and EVENT->u.key.mask.
   Some of these happen to be the same as the X11 masks (which are cast
   in stone for eternity); the implementation relies on that.
   (It is merely a convention that Meta is bit 3, and Option/Num aren't
   normally used in X11.) */

#define WM_SHIFT	(1 << 0)
#define WM_LOCK		(1 << 1)
#define WM_CONTROL	(1 << 2)
#define WM_META		(1 << 3)
#define WM_OPTION	(1 << 4)
#define WM_NUM		(1 << 5)

#define WM_BUTTON1	(1 << 8)
#define WM_BUTTON2	(1 << 9)
#define WM_BUTTON3	(1 << 10)
#define WM_BUTTON4	(1 << 11)
#define WM_BUTTON5	(1 << 12)


/* TEXTATTR struct */

/* The contents of a text attributes struct are disclosed here because
   the interface allows the programmer to declare objects of this type.
   (I'm not so sure anymore that this is the right thing to do!) */

struct _textattr {
	short font;
	unsigned char size;
	unsigned char style;
};

#define TEXTATTR struct _textattr


/* Color */

#define COLOR long
#define BADCOLOR ((COLOR)(-1))


/* Point type for wdrawpoly and wfillpoly -- compatible with X */

struct _point {
	short h, v;
};
#define POINT struct _point


/*************************************/
/* Section 2.  Function declarations */
/*************************************/


void wargs _ARGS((int *pargc, char ***pargv));
void winit _ARGS((void));
void winitargs _ARGS((int *pargc, char ***pargv));
void wdone _ARGS((void));

void wgetscrsize _ARGS((int *pwidth, int *pheight));
void wgetscrmm _ARGS((int *pmmwidth, int *pmmheight));
int wgetmouseconfig _ARGS((void));

void wsetmaxwinsize _ARGS((int width, int height));
void wsetdefwinsize _ARGS((int width, int height));
void wgetdefwinsize _ARGS((int *pwidth, int *pheight));
void wsetdefwinpos _ARGS((int h, int v));
void wgetdefwinpos _ARGS((int *ph, int *pv));
void wsetdefscrollbars _ARGS((/*bool*/int hbar, /*bool*/int vbar));
void wgetdefscrollbars _ARGS((/*bool*/int *phbar, /*bool*/int *pvbar));

WINDOW *wopen _ARGS((char *title,
		void (*drawproc)(/*WINDOW *win,
				int left, int top, int right, int bottom*/)));
void wclose _ARGS((WINDOW *win));
#define wgettag(win) (((_FAKEWINDOW *)(win)) -> tag)
#define wsettag(win, newtag) (((_FAKEWINDOW *)(win)) -> tag = (newtag))
void wsetactive _ARGS((WINDOW *win));
WINDOW *wgetactive _ARGS((void));
void wgetwinsize _ARGS((WINDOW *win, int *width, int *height));
void wsetwinsize _ARGS((WINDOW *win, int width, int height));
void wgetwinpos _ARGS((WINDOW *win, int *h, int *v));
void wsetwinpos _ARGS((WINDOW *win, int h, int v));
void wsetdocsize _ARGS((WINDOW *win, int width, int height));
void wgetdocsize _ARGS((WINDOW *win, int *width, int *height));
void wsettitle _ARGS((WINDOW *win, char *title));
char *wgettitle _ARGS((WINDOW *win)); /* Returns pointer to static data */

void wsetorigin _ARGS((WINDOW *win, int h, int v));
void wgetorigin _ARGS((WINDOW *win, int *h, int *v));
void wshow _ARGS((WINDOW *win, int left, int top, int right, int bottom));
void wchange _ARGS((WINDOW *win, int left, int top, int right, int bottom));
void wscroll _ARGS((WINDOW *win, int left, int top, int right, int bottom,
	int dh, int dv));

void wfleep _ARGS((void));
void wmessage _ARGS((char *str));
void wperror _ARGS((char *name));
/*bool*/int waskstr _ARGS((char *prompt, char *buf, int buflen));
int waskync _ARGS((char *question, int dflt));
/*bool*/int waskfile _ARGS((char *prompt, char *buf, int buflen,
						/*bool*/int newfile));

void wsetcaret _ARGS((WINDOW *win, int h, int v));
void wnocaret _ARGS((WINDOW *win));

void wsettimer _ARGS((WINDOW *win, int deciseconds));

MENU *wmenucreate _ARGS((int id, char *title));
void wmenudelete _ARGS((MENU *mp));
int wmenuadditem _ARGS((MENU *mp, char *text, int shortcut));
void wmenusetitem _ARGS((MENU *mp, int i, char *text));
void wmenusetdeflocal _ARGS((/*bool*/int local));
void wmenuattach _ARGS((WINDOW *win, MENU *mp));
void wmenudetach _ARGS((WINDOW *win, MENU *mp));
void wmenuenable _ARGS((MENU *mp, int item, int flag));
void wmenucheck _ARGS((MENU *mp, int item, int flag));

/* The following is only available in termcap stdwin: */
void wsetshortcut _ARGS((int id, int item, char *keys));

void wgetevent _ARGS((EVENT *ep));
/*bool*/int wpollevent _ARGS((EVENT *ep));
void wungetevent _ARGS((EVENT *ep));
void wupdate _ARGS((WINDOW *win));
void wbegindrawing _ARGS((WINDOW *win));
void wenddrawing _ARGS((WINDOW *win));
void wflush _ARGS((void));

void wdrawline _ARGS((int h1, int v1, int h2, int v2));
void wxorline _ARGS((int h1, int v1, int h2, int v2));

void wdrawbox _ARGS((int left, int top, int right, int bottom));
void wpaint _ARGS((int left, int top, int right, int bottom));
void winvert _ARGS((int left, int top, int right, int bottom));
void werase _ARGS((int left, int top, int right, int bottom));
void wshade _ARGS((int left, int top, int right, int bottom, int percent));

void wdrawcircle _ARGS((int h, int v, int radius));
void wfillcircle _ARGS((int h, int v, int radius));
void wxorcircle _ARGS((int h, int v, int radius));

void wdrawelarc _ARGS((int h, int v, int hrad, int vrad, int ang1, int ang2));
void wfillelarc _ARGS((int h, int v, int hrad, int vrad, int ang1, int ang2));
void wxorelarc _ARGS((int h, int v, int hrad, int vrad, int ang1, int ang2));

void wdrawpoly _ARGS((int n, POINT points[]));
void wfillpoly _ARGS((int n, POINT points[]));
void wxorpoly _ARGS((int n, POINT points[]));

void wcliprect _ARGS((int left, int top, int right, int bottom));
void wnoclip _ARGS((void));

void wdrawtext _ARGS((int h, int v, char *str, int len));
void wdrawchar _ARGS((int h, int v, int c));
int wlineheight _ARGS((void));
int wbaseline _ARGS((void));
int wtextwidth _ARGS((char *str, int len));
int wcharwidth _ARGS((int c));
int wtextbreak _ARGS((char *str, int len, int width));

void wgettextattr _ARGS((TEXTATTR *attr));
void wsettextattr _ARGS((TEXTATTR *attr));
void wgetwintextattr _ARGS((WINDOW *win, TEXTATTR *attr));
void wsetwintextattr _ARGS((WINDOW *win, TEXTATTR *attr));

void wsetplain _ARGS((void));
void wsethilite _ARGS((void));
void wsetinverse _ARGS((void));
void wsetitalic _ARGS((void));
void wsetbold _ARGS((void));
void wsetbolditalic _ARGS((void));
void wsetunderline _ARGS((void));

char **wlistfontnames _ARGS((char *, int *));
int wsetfont _ARGS((char *fontname));
void wsetsize _ARGS((int pointsize));

/* Colors */
COLOR wfetchcolor _ARGS((char *colorname));
void wsetfgcolor _ARGS((COLOR color));
COLOR wgetfgcolor _ARGS((void));
void wsetbgcolor _ARGS((COLOR color));
COLOR wgetbgcolor _ARGS((void));

/* Setting the mouse cursor for a window */
CURSOR *wfetchcursor _ARGS((char *name));
void wsetwincursor _ARGS((WINDOW *win, CURSOR *cursor));

/* X11 Selection interface */
/*bool*/int wsetselection _ARGS((WINDOW *, int, char *, int));
void wresetselection _ARGS((int));
char *wgetselection _ARGS((int, int *));

/* Cut buffer interface */
void wsetcutbuffer _ARGS((int, char *, int));
char *wgetcutbuffer _ARGS((int, int *));
void wrotatecutbuffers _ARGS((int));
void wsetclip _ARGS((char *, int));
char *wgetclip _ARGS((void));

/* Bitmap operations */
BITMAP *wnewbitmap _ARGS((int width, int height));
void wfreebitmap _ARGS((BITMAP *bp));
void wgetbitmapsize _ARGS((BITMAP *bp, int *p_width, int *p_height));
void wsetbit _ARGS((BITMAP *bp, int h, int v, int bit));
int wgetbit _ARGS((BITMAP *bp, int h, int v));
void wdrawbitmap _ARGS((int h, int v, BITMAP *bp, BITMAP *maskp));
#define ALLBITS ((BITMAP *)NULL)

/* Pull in definitions for TEXTEDIT package */

#include "stdwtext.h"

#endif /* __STDWIN_H__ */
