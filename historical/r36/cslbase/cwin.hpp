// cwin.hpp
//         Header file that defines the class structure and all the
//         external variables used in the user-interface support code.
//
//     Copyright (C)/©/¸ Codemist Ltd, 1995-96


/* Signature: 0a32db51 19-Feb-1999 */


#ifndef header_cwin_hpp
#define header_cwin_hpp 1

#include <stdarg.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <afxwin.h>                      // Microsoft Foundation Classes
#include <afxdlgs.h>

#include "cwin.h"                        // Public interface
#include "cwinres.h"                     // resource file interface


extern CString mainWindowClass;          // a Window Class that I register

#ifdef GRAPHICS_WINDOW

// ButtonPlace records are used to define the shapes that I draw
// in the "viewpoint selection" dialog box.

typedef struct tagButtonPlace
{
    unsigned int id:7, x:7, y:7, width:7, flavour:4;
    char *text;
} ButtonPlace;

typedef double fourByFour[4][4];    // A transformation matrix.

// The viewpoint window is used to scale, translate and rotate graphical
// objects.

class CViewpointWindow : public CWnd
{
public:
    CViewpointWindow();
    virtual ~CViewpointWindow();
    CFont labelFont, titleFont;
    void resetXform(int whence);
    void changeXform(double w[4][4]);
    void rotateXform(int axis, double angle);
    void scaleXform(double factor);
    void translateXform(double x, double y);

private:
    BOOL OnEraseBkgnd(CDC *dc);
    void OnPaint();
    void OnSetFocus(CWnd *pOldWnd);
    void OnKillFocus(CWnd *pNewWnd);
    BOOL hasFocus;
    void OnChar(UINT ch, UINT nRepCnt, UINT nFlags);
    void OnKeyDown(UINT ch, UINT nRepCnt, UINT nFlags);
    void OnLButtonDown(UINT nFlags, CPoint point);
    void OnLButtonUp(UINT nFlags, CPoint point);
    void OnMouseMove(UINT nFlags, CPoint point);
    void OnLButtonDblClk(UINT nFlags, CPoint point);

    void setArcPoints();
    void LText(CDC *dc, int x1, int y, char *s);
    void CText(CDC *dc, int x1, int x2, int y, char *s);
    void RText(CDC *dc, int x2, int y, char *s);
    const ButtonPlace *FindControl(int x, int y);
    int inButton(const ButtonPlace *b, int x, int y);
    void SetControl(const ButtonPlace *b, int state);
    void DrawButton(CDC *dc, const ButtonPlace *pb);
    void ButtonAction(int n);

    int dlgWidth, dlgHeight;
    int click;                    // measurement unit in my dialog box

    const ButtonPlace *activeButton;
    int mouseDrag, mouseX, mouseY;

    int moveObject;

    char buttonPressed[60];

    fourByFour view1, view2;
#define undoMask  31
    fourByFour undoStack[32];
    int undoCount, undoPoint;

    DECLARE_MESSAGE_MAP()
};

extern fourByFour stdView;

typedef struct tagXYZPoint
{
    unsigned int x:16;                    // X coordinate of point
    unsigned int y:16;                    // Y coordinate of point
    int z;                                // Z coordinate of point
    signed int nx:10, ny:10, nz:10;       // normal to surface at point
    unsigned int red:8, green:8, blue:8,  // colour to paint surface
                 spare:8;
} XYZPoint;


// A GraphicsWindow displays a shaded surface

class CGraphicsWindow : public CFrameWnd
{
public:
    CGraphicsWindow();
    virtual ~CGraphicsWindow();
    void InitWindow();
    double xform[4][4];
    double perspecDistance;
    CViewpointWindow viewpointWindow;
    int fullRender, fullyRendered;
    int ctrlPressed;

private:
    void OnPaint();
    void OnSize(UINT nType, int cx, int cy);
    void OnSetFocus(CWnd *pOldWnd);
    void OnKillFocus(CWnd *pNewWnd);
    BOOL hasFocus;
    void OnChar(UINT ch, UINT nRepCnt, UINT nFlags);
    void OnKeyDown(UINT ch, UINT nRepCnt, UINT nFlags);
    void OnKeyUp(UINT ch, UINT nRepCnt, UINT nFlags);

    void OnLButtonDblClk(UINT nFlags, CPoint point);
    void OnLButtonDown(UINT nFlags, CPoint point);
    void OnLButtonUp(UINT nFlags, CPoint point);
    void OnMButtonDblClk(UINT nFlags, CPoint point);
    void OnMButtonDown(UINT nFlags, CPoint point);
    void OnMButtonUp(UINT nFlags, CPoint point);
    void OnRButtonDblClk(UINT nFlags, CPoint point);
    void OnRButtonDown(UINT nFlags, CPoint point);
    void OnRButtonUp(UINT nFlags, CPoint point);
    void OnMouseMove(UINT nFlags, CPoint point);
    void OnNcLButtonDown(UINT nFlags, CPoint point);
    void OnNcMButtonDown(UINT nFlags, CPoint point);
    void OnNcRButtonDown(UINT nFlags, CPoint point);

    void OnSaveAs();
    void OnPrint();
    void OnCloseButton();
    void OnCopy();
    void OnClear();
    void OnRedraw();
    void OnViewpoint();
    void OnViewpoint1(UINT a, LONG b);
    void OnWireframe();
    void OnNoSurface();
    void OnSurface();
    void OnSquares();
    void OnTriangles();
    void OnSmooth();
    void OnHiSmooth();
    void OnWirePreview();
    void OnRotLeft();
    void OnRotRight();
    void OnRotUp();
    void OnRotDown();
    void OnClockwise();
    void OnAntiClockwise();
    void OnEnlarge();
    void OnShrink();

    void PaintOrPrint(CDC *dc, RECT *clip, int width, int height,
                      CFont *mainfont, CFont *smallfont);
    HGLOBAL PaintBitmap(int *totalSize, int *psize);

    void initSurface();
    void sortTriangles();
    void paintTriangles(CDC *dc, RECT *clip, int width, int height);

    void MoveTo(CDC *dc, int x, int y);
    void LineTo(CDC *dc, int x, int y);
    void Rectangle(CDC *dc, int x1, int y1, int x2, int y2);
    void SubTriangle(CDC *dc, int x1, int y1, int red1, int green1, int blue1,
                              int x2, int y2, int red2, int green2, int blue2,
                              int x3, int y3, int red3, int green3, int blue3,
                              int n);

    BOOL viewpointShown;
    int drawWire, drawSurface, wirePreview;

    int screenWidth, screenHeight;
    int graphicsHeight, graphicsWidth;

    DECLARE_MESSAGE_MAP()
};

#endif

// I will support a really crude and simple form of hypertext help, based
// on the style popularised by the GNU texinfo program. To start with I will
// implement this so it has just a simple 80 by 25 text window that can
// display in just a single fixed-pitch font (using inverse video for
// highlighting).

class CHelpWindow : public CFrameWnd
{
public:
    CHelpWindow();
    CFont helpFont;
    int height, width;
    char contents[25][80];
    int highline, highstart, highend;

private:
    void OnPaint();
    void OnChar(UINT ch, UINT nRepCnt, UINT nFlags);
    void OnKeyDown(UINT ch, UINT nRepCnt, UINT nFlags);
    void OnLButtonDown(UINT nFlags, CPoint point);
    void OnRedraw();
    void OnCopy();
    void OnClose();

    DECLARE_MESSAGE_MAP()
};

// In a text window I want nine fonts (Courier, Roman and Symbol with
// italic and bold and two sizes). I encapsulate these here mainly so that
// the FontArray destructor can be called automatically for me when my
// window gets destroyed.

class FontHeights
{
public:
    int up;
    int down;
    int height;
    unsigned char across[256];
};

class FontArray
{
public:
    char baseFace[32];
    int boldFlag;
    CFont *Courier, *Roman, *Bold, *Italic, *Symbol,
                    *roman, *bold, *italic, *symbol;
    FontHeights HCourier, HRoman, HBold, HItalic, HSymbol,
                Hroman, Hbold, Hitalic, Hsymbol;
    void InitFont(CDC *dc, const char *name, int weight, int size);
    void ChangeFont(CDC *dc, int height, int weight, const char *baseFace);
    void DeleteFonts();
};

class TextLine
{
public:
    int position;                // sum of heights of all previous lines
    unsigned int up:8, height:8; // font may not be > 256 pixels high
    unsigned int address:16;     // text buffer is only 64 Kbytes
    int width;                   // in SILLY cases lines may get very long!
};

extern UINT clipboardformat;

class CMainWindow : public CFrameWnd
{
public:
    CMainWindow();
    virtual ~CMainWindow();
    void InitWindow();
    FontArray windowFonts, printerFonts;
#ifdef GRAPHICS_WINDOW
    CGraphicsWindow *graphicsWindow;
#endif
    CHelpWindow *helpWindow;
    int clientWidth, clientHeight;

    void cwin_caret_putchar(int c);     // for K/B input: insert at caret
    void cwin_caret_replacechar(int c); // for K/B input: replace at caret
    void cwin_caret_unputchar();        // for K/B input: DELETE before caret
    BOOL InsertAtCaret(char *s, int n);
    BOOL UnTypeAhead(int ch);

    void cwin_putchar(int c);       // for program output - always at end
    void cwin_unputchar();          // delete at end of buffer
    void cwin_puts(const char *s);
    void
#ifdef _MSC_VER
         __cdecl
#endif
         cwin_printf(const char *fmt, ...);
    void cwin_vfprintf(const char *fmt, va_list a);
    void cwin_ensure_screen(BOOL poll);

    int cwin_getchar();
    int cwin_getchar_nowait();
    void cwin_discard_input();
    void cwin_set_prompt(const char *s);
    char cwin_prompt_string[32];

    void cwin_menus(char **packages, char **switches);
    void cwin_report_left(const char *msg);
    void cwin_report_mid(const char *msg);
    void cwin_report_right(const char *msg);
    void cwin_display_date();
    SYSTEMTIME titleUpdateTime, lastFlushTime;
    BOOL leftSetByUser;

#define LINE_BITS   11
#define LINE_SIZE   (1<<LINE_BITS)   // Keep up to 2048 lines in buffer
#define LINE_MASK   (LINE_SIZE-1)
    TextLine lineBuffer[LINE_SIZE];
    int lineFirst, lineVisible, lineLast;
    void LineSizes();
    DWORD windowColour, textColour, highlightColour, highlightTextColour;
    BOOL complete;

private:
    UINT myTimer;
    void OnDestroy();
    void OnPaint();
    int PaintTextLine(CDC *dc, int x, int topY, int y, int bottomY,
                      int textp, int width, FontArray *fa, int context);
    void OnTimer(UINT timerId);
    void OnSize(UINT nType, int cx, int cy);
    void OnMove(int x, int y);
    void AfterSizeChange();
#define SB_REFRESH_THUMB   (-1)
#define SB_FOR_CARET       (-2)
    void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar *PCntl);
    void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar *PCntl);
    void OnSetFocus(CWnd *pOldWnd);
    void OnKillFocus(CWnd *pNewWnd);
    BOOL hasFocus;
    void OnActivate(UINT state, CWnd *pWnd, BOOL minim);
    void OnChar(UINT ch, UINT nRepCnt, UINT nFlags);
#define typeAheadBufferSize (1<<11)
#define typeAheadBufferMask (typeAheadBufferSize-1)
        unsigned char typeAheadBuffer[typeAheadBufferSize];
        int typeAheadP1, typeAheadP2;
#define inputBufferSize      typeAheadBufferSize
        unsigned char inputBuffer[inputBufferSize];
#define MAX_SAVED_LINES 100
#define MAX_SAVED_CHARS (4*inputBufferSize)
        int currentInputLine, savedP1, savedP2, savedFirst, savedLast;
        int savedLines[MAX_SAVED_LINES];
        unsigned char savedChars[MAX_SAVED_CHARS];
    void ReplaceLastLine(unsigned char *s);
        int inputP;
        BOOL insertMode;
    void OnKeyDown(UINT ch, UINT nRepCnt, UINT nFlags);
    void MakeSpaceAtCaret(int n);
    int FindMouseChar(CPoint point);
    void StartSelection();
    void ExtendSelection();
    void InvalidateSelection(int l1, int x1, int l2, int x2);
    void CancelSelection();
        int caretWidth;
        BOOL selRootValid, caretVisible;
        unsigned char *endFontWidths;
        unsigned char *caretFontWidths;
        unsigned char *icaretFontWidths;
        int selFirstX, selStartX, selEndX, caretX, icaretX, endX;
        int selFirstLine, selStartLine, selEndLine, caretLine, icaretLine;
        int selFirstChar, selStartChar, selEndChar, caretChar, icaretChar;
        int selectScrollSpeed, selectScrollCount, selectScrollDirection;
        CPoint selectScrollPoint;
        int mouseOutside;
        BOOL pageMode, pagePaused;
        int pageLine;
    void OnLButtonDblClk(UINT nFlags, CPoint point);
    void OnLButtonDown(UINT nFlags, CPoint point);
    void OnLButtonUp(UINT nFlags, CPoint point);
    void OnMButtonDblClk(UINT nFlags, CPoint point);
    void OnMButtonDown(UINT nFlags, CPoint point);
    void OnMButtonUp(UINT nFlags, CPoint point);
    void OnRButtonDblClk(UINT nFlags, CPoint point);
    void OnRButtonDown(UINT nFlags, CPoint point);
    void OnRButtonUp(UINT nFlags, CPoint point);
    void OnMouseMove(UINT nFlags, CPoint point);
    void OnNcLButtonDown(UINT nFlags, CPoint point);
    void OnNcMButtonDown(UINT nFlags, CPoint point);
    void OnNcRButtonDown(UINT nFlags, CPoint point);
    void WrapTextBuffer(BOOL flag);

    void OnRead();
    void OnToFile();
    void OnExit();
    void OnSaveAs();
    void OnSaveSel();
    void OnPrint();
    void OnPrintSel();
    void OnCut();
    void DeleteSelection();
    void OnCopy();
    void OnPaste();
        char *clipboardInput, *clipboardInputP;
    void OnReInput();
    void OnSelectAll();
    void OnClear();
    void OnUndo();
    void OnRedraw();
    void OnHome();
    void OnEnd();
    void OnFont();
    void OnResetFont();
    void OnResetWindow();
    void OnInterrupt();
    void OnBacktrace();
    void OnPageMode();
#ifdef GRAPHICS_WINDOW
    void OnGraphics();
    void OnGraphics1(UINT a, LONG b);
    BOOL graphicsShown;
#endif
    BOOL helpShown;
#ifndef COMMON
    void OnLoadLibrary(UINT a);
    void OnSwitch(UINT a);
#endif

// Elsewhere in this code I use a 16-bit field to identify characters in the
// text buffer, so 64K bytes is the largest I can make it.
#define TEXT_BITS  16
#define TEXT_SIZE  (1<<TEXT_BITS)    // Keep up to 64K characters in buffer
#define TEXT_MASK  (TEXT_SIZE-1)
    unsigned char textBuffer[TEXT_SIZE];
    int textFirst, textLast;
    int textmark;
    int inputLineStart;
    BOOL trackingSelection;

    void ToIcaret();

    void MeasureLine(int address, int *up, int *down, FontArray *fa);
    int currentFont, currentColour;
    unsigned char *currentWidths;
    int xOffset;                     // amount of horizontal scrolling

    char mainTitle[84], cLeft[32], cMid[32], cRight[32];
    void ReWriteTitleText();

    DECLARE_MESSAGE_MAP()
};

#define LineY(n) (lineBuffer[n].position-lineBuffer[lineVisible].position)
#define LineDY(n) lineBuffer[n].height

class CTheApp : public CWinApp
{
public:
    BOOL InitInstance();
    int Run();                           // override top level loop (!)
    BOOL OnIdle(LONG lCount);
    MSG *msgPtr;
    CMainWindow *mainWindow;

    void OnHelpContents();    // Help is associated with the application
    void OnHelpSearch();      // ... not with any particular instance.
    void OnHelpOnHelp();
    void OnAbout();
    int dynamicCount;
    const char *dynamic[IDM_LAST_DYNAMIC-IDM_DYNAMIC_ITEMS];
    const char *dynamic_files[IDM_LAST_DYNAMIC-IDM_DYNAMIC_ITEMS];
    void OnDynamic(unsigned int commandId);

    void cwin_set_help_file(const char *key, const char *path);

    DECLARE_MESSAGE_MAP()
};

extern void cwin_poll_window_manager();
extern int cwin_main(int argc, char *argv[]);

extern CTheApp theApp;

// I can not find the following an the set of header files provided
// with Watcom C 10.5, but they are in the on-line documentation

#define VK_LEFT     0x25
#define VK_UP       0x26
#define VK_RIGHT    0x27
#define VK_DOWN     0x28
#define VK_SHIFT    0x10
#define VK_CONTROL  0x11
#define VK_X        0x58
#define VK_Y        0x59
#define VK_Z        0x5a
#define VK_NUMPAD2  0x62
#define VK_NUMPAD4  0x64
#define VK_NUMPAD6  0x66
#define VK_NUMPAD8  0x68

#define StdView  0
#define Xaxis    1
#define Yaxis    2
#define Zaxis    3
#define View1    4
#define View2    5
#define Undo     6

// I use various control characters in my display buffer.
// I reserve the range 0x80 to 0x9f for such uses.


#define CH_NULL     0
#define CH_TAB      9
#define CH_ENDLINE  10   
#define CH_FORMFEED 12
#define CH_ESCAPE   31
#define CH_SPACE    32   // first regular character

// There is a real ugliness about using characters with the 0x80 bit set,
// in that if I store then in a "char *" buffer when I pull them out they
// may have got sign-extended.

#define CH_COURIER  0x90
#define CH_ROMAN    0x91
#define CH_ITALIC   0x92
#define CH_BOLD     0x93
#define CH_SYMBOL   0x94
#define CH_Roman    0x95
#define CH_Italic   0x96
#define CH_Bold     0x97
#define CH_Symbol   0x98

#define CH_RED      0x99
#define CH_BLUE     0x9a   // used to mark start of prompt text
#define CH_PROMPT   0x9a
#define CH_GRAY     0x9b
#define CH_BLACK    0x9c
#define CH_ENDPROMPT 0x9c
#define CH_HIGHLIGHT 0x100 // can never occur in the text buffer


extern void
#ifdef _MSC_VER
           __cdecl
#endif
           DisplayMsg(char *msg, ...);  // Used for debugging

#endif /* header_cwin_hpp */

// End of "cwin.hpp"


