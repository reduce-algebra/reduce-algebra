// c_text.cpp
//     Support for a window that can support regular, bold, italic and symbol
//     fonts each in large & small, plus the ability to select the size of
//     characters to be used.
//
//
//     See accompanying file "cwin.tex" for an explanation of the policy
//     for scrolling, text selection and treatment of buffer over-full
//     conditions.
//
//     Copyright (C)/©/¸ Codemist Ltd, 1995-99

/* Signature: 7f4001bb 07-Mar-2000 */


#include "cwin.hpp"

// There are times when this code wants to indicate to the user's
// application that it should terminate.  If such a request has been
// raised the macro exception_pending() given here will evaluate to true,
// but the way that this happens is specific the the CSL/CCL Lisp system
// and thus is not exactly generic.

extern "C" {
extern int C_nil;
extern FILE *spool_file;
extern void inject_randomness(int);
}

#define exception_pending() ((C_nil&1) != 0)

static BOOL hasFinished = FALSE;

CMainWindow::CMainWindow()
{
    hasFinished = FALSE;
    complete = FALSE;
    char *menuName = "MainMenu";
    HINSTANCE hInst = AfxFindResourceHandle(menuName, RT_MENU);
    HMENU hMenu = ::LoadMenu(hInst, menuName);
    this->CreateEx(WS_EX_ACCEPTFILES,
                   mainWindowClass, "",
                   WS_OVERLAPPEDWINDOW | WS_HSCROLL | WS_VSCROLL,
                   CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
                   NULL, hMenu);

// Now I will add the dynamic menu items that I need...
// I demand that the "help" be the rightmost one on the menu bar
    HMENU helpMenu = ::GetSubMenu(hMenu, ::GetMenuItemCount(hMenu)-1);
    int i;
    theApp.dynamicCount = 0;
// Insert extra help menu items here. I expect that the registry will
// contain a subkey called HelpItems which is an integer, and then
// a bunch of strings takked as T000/P000, T001/P001 etc where the Tiii are
// strings to place on the menu and the Piii are paths to relevant help
// files that can be opened.
    int helpCount = theApp.GetProfileInt("HelpItems", "HowMany", 0);
#ifdef MAYBE
    int helpCount = theApp.GetProfileInt("HelpItems", "HowMany", -1);
    if (helpCount < 0)
    {   theApp.dynamic[0] = "&Contents"
        theApp.dynamic_files[0] = "???";
        theApp.dynamic[1] = "&Search for Help"
        theApp.dynamic_files[1] = "???";
        helpCount = 2;
        WriteProfileInt("HelpItems", "HowMany", 2);
        WriteProfileString("HelpItems", "T000", theApp.dynamic[0]);
        WriteProfileString("HelpItems", "P000", theApp.dynamic_files[0]);
        WriteProfileString("HelpItems", "T001", theApp.dynamic[1]);
        WriteProfileString("HelpItems", "P001", theApp.dynamic_files[1]);
    }
    else
#endif
    {   if (helpCount >= IDM_LAST_DYNAMIC-IDM_DYNAMIC_ITEMS)
            helpCount = IDM_LAST_DYNAMIC-IDM_DYNAMIC_ITEMS-1;
        for (i=0; i<helpCount; i++)
        {   char tag[8];
            sprintf(tag, "T%.3d", i);
            CString key(theApp.GetProfileString("HelpItems", tag, ""));
            sprintf(tag, "P%.3d", i);
            CString path(theApp.GetProfileString("HelpItems", tag, ""));
            if (key.GetLength() != 0 && path.GetLength() != 0)
            {   char *m;
                m = (char *)malloc(1+key.GetLength());
                strcpy(m, LPCTSTR(key));
                theApp.dynamic[theApp.dynamicCount] = m;
                m = (char *)malloc(1+path.GetLength());
                strcpy(m, LPCTSTR(path));
                theApp.dynamic_files[theApp.dynamicCount++] = m;
            }
        }
    }
// Now place them on the menu
    for (i=0; i<theApp.dynamicCount; i++)
        ::InsertMenu(helpMenu, IDM_HELP_ON_HELP, MF_BYCOMMAND,
                             IDM_DYNAMIC_ITEMS+i, theApp.dynamic[i]);

// typeAheadBuffer is a smallish buffer and when the user presses a key the
// resulting character is put there. No echoing is performed. Use of DEL
// can discard a previously-typed character and an attempt to over-fill the
// buffer before other parts of the code have emptied it will cause a BEEP.
//
    typeAheadP1 = typeAheadP2 = 0;              // pointers into typeAheadBuffer
// inputBuffer holds stuff that the user has accepted (by typing a newline)
// but that the program has not yet read. inputP shows where the next
// character should be read from it. The end of the buffer is marked with
// a newline. If inputP<0 the buffer is empty.
    inputP = -1;
// textBuffer is a large buffer just containing characters. textFirst
// points to the first active character and textLast to one after the last
// active character. Both pointers are kept masked with TEXT_MASK which
// wraps them around to give a circular buffer.
    textFirst = textLast = 0;           // main text buffer, now empty
    caretChar = 0;                      // char before which caret is shown
    caretLine = 0; caretX = 0;
    icaretChar = icaretLine = icaretX = 0;
    caretVisible = TRUE;
    caretFontWidths = windowFonts.HCourier.across;
    icaretFontWidths = windowFonts.HCourier.across;
    endFontWidths = windowFonts.HCourier.across;
    endX = 0;
    xOffset = 0;                        // Not horizontally scrolled.
    inputLineStart = -1;
    caretWidth = 2*GetSystemMetrics(SM_CXBORDER);

    clipboardInput = NULL;
    insertMode = TRUE;

    savedP1 = savedP2 = savedFirst = savedLast = 0;
    currentInputLine = -1;

    pageLine = 0;
    pageMode = pagePaused = FALSE;

    selFirstChar = selStartChar = selEndChar = 0;
    selFirstX = selStartX = selEndX = 0;
    selFirstLine = selStartLine = selEndLine = 0;
    trackingSelection = FALSE;
    selRootValid = FALSE;
    hasFocus = FALSE;

// The characters in textBuffer are organised into lines. The start of each
// line is recorded in lineBuffer, which is also a circular buffer so the
// pointers into it are kept reduced using LINE_MASK. lineFirst identified
// the first line stored.  lineLast identifies the last line. Note that
// the data making up a single line runs from where lineBuffer points either
// to where a termination character is found in the text (this will be
// a newline character) or until textLast. The latter case arises only for
// a final non-terminated line of text.  In general there will not be room
// on the screen to display all the lines of text that are present.
// lineVisible identifies the first line that can be displayed.
//
    lineFirst = lineVisible = 0;        // line buffer, contains one (empty)
    lineLast = 0;                       // line
    lineBuffer[0].position = 0;
    lineBuffer[0].up = 000;
    lineBuffer[0].height = 000;         // get filled in when fonts are created
    lineBuffer[0].width = 000;          // gets filled in when line painted.
    lineBuffer[0].address = textFirst;

    cLeft[0] = cRight[0] = 0;
    strncpy(cMid, programName, 31); cMid[31] = 0;
    GetSystemTime(&titleUpdateTime);
    inject_randomness((int)titleUpdateTime.wMilliseconds);
    cwin_display_date();

    strcpy(cwin_prompt_string, "> ");   // A default prompt string.

    windowColour = GetSysColor(COLOR_WINDOW);
    textColour = GetSysColor(COLOR_WINDOWTEXT);
    highlightColour = GetSysColor(COLOR_HIGHLIGHT);
    highlightTextColour = GetSysColor(COLOR_HIGHLIGHTTEXT);

#ifdef GRAPHICS_WINDOW
    graphicsShown = FALSE;
    graphicsWindow = new CGraphicsWindow;
    graphicsWindow->ShowWindow(SW_HIDE);
#endif
    helpShown = FALSE;
    helpWindow = new CHelpWindow;

    CClientDC dc(helpWindow);
    dc.SelectObject(&helpWindow->helpFont);
    TEXTMETRIC mm;
    dc.GetTextMetrics(&mm);
    helpWindow->height = mm.tmExternalLeading + mm.tmAscent + mm.tmDescent;
    int widths[4];
    dc.GetCharWidth('X', 'X', widths);
    helpWindow->width = widths[0];

    WINDOWPLACEMENT wp;
    helpWindow->GetWindowPlacement(&wp);
    int screenWidth = GetSystemMetrics(SM_CXSCREEN);
    RECT *wr = &wp.rcNormalPosition;
    int left = wr->left;
    int cwidth = 80*helpWindow->width +
                 3*GetSystemMetrics(SM_CXBORDER) +
                 2*GetSystemMetrics(SM_CXFRAME) + 5;
// Try to get the whole window onto the screen.
    if (left + cwidth > screenWidth)
    {   left = screenWidth - cwidth;
        if (left < 0) left = 0;
    }
    int screenHeight = GetSystemMetrics(SM_CYSCREEN);
    int top = wr->top;
    int cheight = 25*helpWindow->height +
                   GetSystemMetrics(SM_CYCAPTION) +
                   GetSystemMetrics(SM_CYMENU) +
                   3*GetSystemMetrics(SM_CYBORDER) +
                   2*GetSystemMetrics(SM_CYFRAME) + 5;
    if (top + cheight > screenHeight)
    {   top = screenHeight - cheight;
        if (top < 0) top = 0;
    } 
    helpWindow->SetWindowPos(NULL, 
       top, left,
       cwidth, cheight,
       SWP_NOACTIVATE | SWP_NOREDRAW | SWP_NOZORDER);

    helpWindow->ShowWindow(SW_HIDE);
    myTimer = SetTimer(1, 50, NULL);   // 20 ticks per second -> message queue
    cwin_interrupt_pending = 0;
    complete = TRUE;
}

CMainWindow::~CMainWindow()
{
}

void CMainWindow::OnDestroy()
{
#ifdef GRAPHICS_WINDOW
    graphicsWindow->viewpointWindow.DestroyWindow();
    graphicsWindow->DestroyWindow();
//  delete graphicsWindow;
#endif
    if (myTimer!=0) KillTimer(myTimer);
    windowFonts.DeleteFonts();
    hasFinished = TRUE;
}

BEGIN_MESSAGE_MAP(CMainWindow, CFrameWnd)

    ON_WM_DESTROY()
    ON_WM_CHAR()
    ON_WM_HSCROLL()
    ON_WM_KEYDOWN()
    ON_WM_KILLFOCUS()
    ON_WM_LBUTTONDBLCLK()
    ON_WM_LBUTTONDOWN()
    ON_WM_LBUTTONUP()
    ON_WM_MBUTTONDBLCLK()
    ON_WM_MBUTTONDOWN()
    ON_WM_MBUTTONUP()
    ON_WM_MOUSEMOVE()
//  ON_WM_NCLBUTTONDOWN()
//  ON_WM_NCMBUTTONDOWN()
//  ON_WM_NCRBUTTONDOWN()
    ON_WM_PAINT()
    ON_WM_TIMER()
    ON_WM_RBUTTONDBLCLK()
    ON_WM_RBUTTONDOWN()
    ON_WM_RBUTTONUP()
    ON_WM_SETFOCUS()
    ON_WM_SIZE()
    ON_WM_MOVE()
    ON_WM_VSCROLL()


// Now things on the menus...

    ON_COMMAND(IDM_READ,           OnRead)
    ON_COMMAND(IDM_SAVEAS,         OnSaveAs)
    ON_COMMAND(IDM_SAVESEL,        OnSaveSel)
    ON_COMMAND(IDM_PRINT,          OnPrint)
    ON_COMMAND(IDM_PRINTSEL,       OnPrintSel)
    ON_COMMAND(IDM_TOFILE,         OnToFile)
    ON_COMMAND(IDM_EXIT,           OnExit)

    ON_COMMAND(IDM_CUT,            OnCut)
    ON_COMMAND(IDM_COPY,           OnCopy)
    ON_COMMAND(IDM_PASTE,          OnPaste)
    ON_COMMAND(IDM_REINPUT,        OnReInput)
    ON_COMMAND(IDM_SELECTALL,      OnSelectAll)
    ON_COMMAND(IDM_CLEAR,          OnClear)
//  ON_COMMAND(IDM_UNDO,           OnUndo)
    ON_COMMAND(IDM_REDRAW,         OnRedraw)
    ON_COMMAND(IDM_HOME,           OnHome)
    ON_COMMAND(IDM_END,            OnEnd)
    ON_COMMAND(IDM_FONT,           OnFont)
    ON_COMMAND(IDM_RESET_FONT,     OnResetFont)
    ON_COMMAND(IDM_RESET_WINDOW,   OnResetWindow)

    ON_COMMAND(IDM_INTERRUPT,      OnInterrupt)
    ON_COMMAND(IDM_BACKTRACE,      OnBacktrace)
    ON_COMMAND(IDM_PAGEMODE,       OnPageMode)

#ifdef GRAPHICS_WINDOW
    ON_COMMAND(IDM_GRAPHICS,       OnGraphics)
    ON_MESSAGE(WM_USER,            OnGraphics1)
#endif

#ifndef COMMON
    ON_COMMAND_RANGE(IDM_FIRSTLOAD, IDM_FIRSTLOAD+199, OnLoadLibrary)
    ON_COMMAND_RANGE(IDS_FIRSTSWITCH, IDS_FIRSTSWITCH+199, OnSwitch)
#endif

END_MESSAGE_MAP()


// Message handlers...


#define caretY  (lineBuffer[caretLine].position - \
                 lineBuffer[lineVisible].position)
#define caretDY (lineBuffer[caretLine].height)
#define caretY1 (caretY+caretDY)

void CMainWindow::OnPaint()
{
    RECT update;
    inject_randomness((int)clock());
    if (!GetUpdateRect(&update, TRUE)) return;
    CPaintDC dc(this);
    dc.SetTextAlign(TA_BASELINE);
    dc.SetTextColor(RGB(0,0,0));          currentColour = CH_BLACK;
    dc.SetBkColor(windowColour);
    dc.SelectObject(windowFonts.Courier); currentFont = CH_COURIER;
    currentWidths = windowFonts.HCourier.across;
    int yBase = lineBuffer[lineVisible].position, line;
    HideCaret();
    for (line=lineVisible;; line=(line+1)&LINE_MASK)
    {   int y = lineBuffer[line].position - yBase;
        int y1 = y+lineBuffer[line].up;
        int y2 = y+lineBuffer[line].height;
        if (y2 >= update.top)
            lineBuffer[line].width =
                PaintTextLine(&dc, -xOffset, y, y1, y2,
                              lineBuffer[line].address,
                              clientWidth, &windowFonts, 0);
        if (y > update.bottom+lineBuffer[line].up) break;
        if (line==lineLast) break;
    }
    ShowCaret();
    dc.SelectStockObject(SYSTEM_FONT);
// Now I will worry about positioning the horizontal scroll thumb.
    int longestLine = 0;
    for (line=lineVisible;; line=(line+1)&LINE_MASK)
    {   int y = lineBuffer[line].position - yBase;
        if (y > clientHeight) break;
        int w = lineBuffer[line].width;
        if (w > longestLine) longestLine = w;
        if (line==lineLast) break;
    }
    if (longestLine <= clientWidth)
    {   if (xOffset != 0)
        {
// Mess here - my response is to force the X offset to zero
// and scroll the window to match - that will generally force a fresh
// painting operation.  This sort of thing can happen when there was a
// long line in the buffer and the window had been scrolled right to view it,
// and then by a sequence of vertical scrolling operations that line is
// no longer on the screen and all the lines that are visible are short enough
// to be shown in their entirity.  It can also happen when somebody
// increases the size of the window.
            ScrollWindow(xOffset, 0, NULL, NULL);
            xOffset = 0;
            SetScrollPos(SB_HORZ, 0, TRUE);
        }
    }
    else
    {   int HScrollPos = (100*xOffset)/(longestLine-clientWidth/2);
// If (for instance) the font had just cahnged or the windows size had been
// enlarged you might have too little left visible on the screen - in such
// cases I will forcibly scroll to correct things.
        if (HScrollPos > 100)
        {   ScrollWindow(xOffset-longestLine+clientWidth/2, 0, NULL, NULL);
            xOffset = longestLine-clientWidth/2;
            HScrollPos = 100;
        }
        SetScrollPos(SB_HORZ, HScrollPos, TRUE);
    }
    CPoint caretPos(caretX-xOffset, caretY);
    SetCaretPos(caretPos);
}

// a, b and c are pointers into the circular text buffer, with a<=c
// (logically). Test is a<=b<c.  The mess here is because of wrap-
// around with TEXT_MASK.

BOOL betweenChar(int a, int b, int c)
{
    if (a<=c) return (a<=b && b<c);
    else return (a<=b || b<c);
}

// Ditto but relative to the line buffer. Observe that the code I have is
// identical, but I still like to keep the abstractions separate.

BOOL betweenLine(int a, int b, int c)
{
    if (a<=c) return (a<=b && b<c);
    else return (a<=b || b<c);
}

int CMainWindow::PaintTextLine(CDC *dc, int x,
                               int topY, int y, int bottomY, int textChar,
                               int width, FontArray *ff, int context)
{
// context = 0     painting to screen
//         = 1     printing whole of buffer
//         = 2     just printing selected region
    int nCount = 0;
    int needFont = (currentFont != CH_COURIER);
    int needColour = (currentColour != CH_BLACK);
// I will buffer up to 80 characters of fixed-pitch output and display them
// using a single call to TextOut. This is intended to reduce the cost of
// calling the operating system for output.
    char buff[80];
    int bufp = 0, bufx = 0, bufy = 0;
    for (;;textChar=(textChar+1)&TEXT_MASK)
    {
// I reset the X coordinate relating to the root, start and end of
// any selection. This is necessary (for instance) after a font change,
// and also means I do not have to re-calculate the X offsets when I am
// inserting characters into the middle of the buffer.
        if (context == 0)
        {   if (textChar == selFirstChar) selFirstX = x+xOffset;
            if (textChar == selStartChar) selStartX = x+xOffset;
            if (textChar == selEndChar) selEndX = x+xOffset;
// Just after I have deleted a character (or two) I can have repositioned
// the character but I will have lost track of the font active at its new
// position, and thus of the font metrics, and the X coordinate that the
// caret will be at. So although when inserting characters into the buffer
// I can keep track of font & position I reset them here so that a
// Paint operation following a delection puts things back in a coherent
// state.
            if (textChar==caretChar)
            {   caretX = x+xOffset;
                caretFontWidths = currentWidths;
            }
            if (textChar==icaretChar)
            {   icaretX = x+xOffset;
                icaretFontWidths = currentWidths;
            }
// Ditto for the end of the text buffer.
            if (textChar==textLast)
            {   endX = x+xOffset;
                endFontWidths = currentWidths;
                break;
            }
        }
        else if (textChar==textLast) break;
// I will stop if I either find a newline character or I reach the end
// of the buffer. In each case I will have sorted out how long the line
// I was displaying was.
        int c = textBuffer[textChar];
// I permit ESC characters in the buffer, but I will display them as $
// following an ancient tradition. Other control characters are not really
// permitted and could lead to mangled display.
        if (c == 0x1b) c = '$';
        int w = currentWidths[c & 0xff];
        BOOL inSelection = betweenChar(selStartChar, textChar, selEndChar);
        if (context==0 && inSelection &&
            (currentColour==CH_BLACK || currentColour==CH_HIGHLIGHT))
        {   needColour = FALSE;
            currentColour = CH_HIGHLIGHT;
            if (bufp != 0) dc->TextOut(bufx, bufy, buff, bufp), bufp=0;
            dc->SetTextColor(highlightTextColour);
            dc->SetBkColor(highlightColour);
        }
        else if (!inSelection)
        {
// If I am outside the selected region and context==2 (printing selection)
// then I map characters onto blanks so thet they will not appear in the
// output.
            if (context == 2) c = ' ';
            if (currentColour==CH_HIGHLIGHT)
            {   needColour = FALSE;
                currentColour = CH_BLACK;
                if (bufp != 0) dc->TextOut(bufx, bufy, buff, bufp), bufp=0;
                dc->SetTextColor(RGB(0,0,0));
                dc->SetBkColor(windowColour);
            }
        }
        switch (c & 0xff)
        {
    case '\n':
            break;
    case CH_RED:
            needColour = FALSE;
            if (currentColour == c) continue;
            currentColour = c;
            if (bufp != 0) dc->TextOut(bufx, bufy, buff, bufp), bufp=0;
            dc->SetTextColor(RGB(255,0,0));
            dc->SetBkColor(windowColour);
            continue;
    case CH_BLUE:
            needColour = FALSE;
            if (currentColour == c) continue;
            currentColour = c;
            if (bufp != 0) dc->TextOut(bufx, bufy, buff, bufp), bufp=0;
            dc->SetTextColor(RGB(0,0,255));
            dc->SetBkColor(windowColour);
            continue;
    case CH_BLACK:
            if (inSelection && context==0)
            {   c = CH_HIGHLIGHT;
                needColour = FALSE;
                if (currentColour == c) continue;
                currentColour = c;
                if (bufp != 0) dc->TextOut(bufx, bufy, buff, bufp), bufp=0;
                dc->SetTextColor(highlightTextColour);
                dc->SetBkColor(highlightColour);
            }
            else
            {   needColour = FALSE;
                if (currentColour == c) continue;
                currentColour = c;
                if (bufp != 0) dc->TextOut(bufx, bufy, buff, bufp), bufp=0;
                dc->SetTextColor(RGB(0,0,0));
                dc->SetBkColor(windowColour);
            }
            continue;
    case CH_GRAY:
            needColour = FALSE;
            if (currentColour == c) continue;
            currentColour = c;
            if (bufp != 0) dc->TextOut(bufx, bufy, buff, bufp), bufp=0;
            dc->SetTextColor(RGB(128,128,128));
            dc->SetBkColor(windowColour);
            continue;
    case CH_COURIER:
            needFont = FALSE;
            if (currentFont == c) continue;
            currentFont = c;
            currentWidths = ff->HCourier.across;
            dc->SelectObject(ff->Courier);
            continue;
    case CH_ROMAN:
            needFont = FALSE;
            if (currentFont == c) continue;
            currentFont = c;
            currentWidths = ff->HRoman.across;
            if (bufp != 0) dc->TextOut(bufx, bufy, buff, bufp), bufp=0;
            dc->SelectObject(ff->Roman);
            continue;
    case CH_BOLD:
            needFont = FALSE;
            if (currentFont == c) continue;
            currentFont = c;
            currentWidths = ff->HBold.across;
            if (bufp != 0) dc->TextOut(bufx, bufy, buff, bufp), bufp=0;
            dc->SelectObject(ff->Bold);
            continue;
    case CH_ITALIC:
            needFont = FALSE;
            if (currentFont == c) continue;
            currentFont = c;
            currentWidths = ff->HItalic.across;
            if (bufp != 0) dc->TextOut(bufx, bufy, buff, bufp), bufp=0;
            dc->SelectObject(ff->Italic);
            continue;
    case CH_SYMBOL:
            needFont = FALSE;
            if (currentFont == c) continue;
            currentFont = c;
            currentWidths = ff->HSymbol.across;
            if (bufp != 0) dc->TextOut(bufx, bufy, buff, bufp), bufp=0;
            dc->SelectObject(ff->Symbol);
            continue;
    case CH_Roman:
            needFont = FALSE;
            if (currentFont == c) continue;
            currentFont = c;
            currentWidths = ff->Hroman.across;
            if (bufp != 0) dc->TextOut(bufx, bufy, buff, bufp), bufp=0;
            dc->SelectObject(ff->roman);
            continue;
    case CH_Bold:
            needFont = FALSE;
            if (currentFont == c) continue;
            currentFont = c;
            currentWidths = ff->Hbold.across;
            if (bufp != 0) dc->TextOut(bufx, bufy, buff, bufp), bufp=0;
            dc->SelectObject(ff->bold);
            continue;
    case CH_Italic:
            needFont = FALSE;
            if (currentFont == c) continue;
            currentFont = c;
            currentWidths = ff->Hitalic.across;
            if (bufp != 0) dc->TextOut(bufx, bufy, buff, bufp), bufp=0;
            dc->SelectObject(ff->italic);
            continue;
    case CH_Symbol:
            needFont = FALSE;
            if (currentFont == c) continue;
            currentFont = c;
            currentWidths = ff->Hsymbol.across;
            if (bufp != 0) dc->TextOut(bufx, bufy, buff, bufp), bufp=0;
            dc->SelectObject(ff->symbol);
            continue;
    default:
// The start of every line should be in regular-sized Courier and
// in black. But rather than calling Windows to force that selection
// on every line (I hypothesize that selecting a fond and a colour
// into my device context may be costly) I only do so when I find I have
// a character to display and then only in cases where what was left over
// from whatever was last printed was somehow different.
            if (context==0 && needColour && inSelection)
            {   if (bufp != 0) dc->TextOut(bufx, bufy, buff, bufp), bufp=0;
                dc->SetTextColor(highlightTextColour);
                dc->SetBkColor(highlightColour);
                currentColour = CH_BLUE;
                needColour = FALSE;
            }
            else if (needColour)
            {   if (bufp != 0) dc->TextOut(bufx, bufy, buff, bufp), bufp=0;
                dc->SetTextColor(RGB(0,0,0));
                dc->SetBkColor(windowColour);
                currentColour = CH_BLACK;
                needColour = FALSE;
            }
            if (needFont)
            {   dc->SelectObject(ff->Courier);
                currentFont = CH_COURIER;
                currentWidths = ff->HCourier.across;
                needFont = FALSE;
            }
            if (c == '\t')
            {   c = ' ';
                w = currentWidths[c]*(8-(nCount&7));
                nCount = 7;
            }
            else if (c < 32)
            {   w = currentWidths['^'];
// There is a curiosity here, that for the moment I am going to leave alone.
// If one has a control character in the buffer it is displayed as something
// like ^I (with the '^' as a separate character and the 'I' a normal letter).
// If this is within a selection the 'I' is shown in inverse video as usual
// but the '^' is not. This could perhaps be seen as a way of making it
// possible to distinguish between the control character and a regular pair
// of characters spelt the same.
                if (x+w>=0 && x<width)
                {   if (bufp>=sizeof(buff))
                        dc->TextOut(bufx, bufy, buff, bufp), bufp=0;
                    if (bufp == 0) bufx = x, bufy = y;
                    buff[bufp++] = '^';
                }
                x += currentWidths['^'];
                c = c | 0x40;
                w = currentWidths[c & 0xff];
                nCount++;
            }
            if (inSelection && context==0)
            {   CBrush b(highlightColour);
                CBrush *oldbrush = dc->SelectObject(&b);
                if (bufp != 0) dc->TextOut(bufx, bufy, buff, bufp), bufp=0;
                dc->SelectStockObject(NULL_PEN);
                dc->Rectangle(x, topY, x+w+1, bottomY+1);
                dc->SelectObject(oldbrush);
            }
            if (x+w>=0 && x<width)
            {   if (currentFont == CH_COURIER)
                {   if (bufp>=sizeof(buff))
                        dc->TextOut(bufx, bufy, buff, bufp), bufp = 0;
                    if (bufp == 0) bufx = x, bufy = y;
                    buff[bufp++] = c;
                }
                else
                {   if (bufp != 0) dc->TextOut(bufx, bufy, buff, bufp), bufp=0;
                    buff[0] = c;
                    dc->TextOut(x, y, buff, 1);
                }
            }
            x += w;
            nCount++;
            continue;
        }
        break;
    }
    if (bufp != 0) dc->TextOut(bufx, bufy, buff, bufp);
// I am NOT happy about the next few lines -- they fill an area in background
// colour out across to the end of the line. I do this because otherwise
// despite lots of calls to HideCaret I seem to observe remains of the caret
// displayed after I have made a line shorter. I do not understand why this
// happens but hope that what follows will work around the problem.
    if (context==0)
    {   CBrush b(windowColour);
        CBrush *oldbrush = dc->SelectObject(&b);
        dc->SelectStockObject(NULL_PEN);
        dc->Rectangle(x, topY,
                      width, bottomY+1);
        dc->SelectObject(oldbrush);
    }
    return x + xOffset;
}


int cwin_linelength = 80;

void CMainWindow::OnSize(UINT nType, int cx, int cy)
{
    WINDOWPLACEMENT wp;
    GetWindowPlacement(&wp);
    RECT *wr = &wp.rcNormalPosition;
    clientWidth = cx;
    clientHeight = cy;
    if (nType != SIZE_MINIMIZED)
        cwin_linelength = (clientWidth-5) / windowFonts.HCourier.across['X'];
    theApp.WriteProfileInt("MainWindow", "ScreenWidth",  wr->right-wr->left);
    theApp.WriteProfileInt("MainWindow", "ScreenHeight", wr->bottom-wr->top);
    theApp.WriteProfileInt("MainWindow", "LineLength",   cwin_linelength);
    if (caretVisible)
    {   OnVScroll(SB_FOR_CARET, 0, NULL);
        OnHScroll(SB_FOR_CARET, 0, NULL);
    }
    OnHScroll(SB_REFRESH_THUMB, 0, NULL);
    OnVScroll(SB_REFRESH_THUMB, 0, NULL);
}

void CMainWindow::OnMove(int x, int y)
{
    WINDOWPLACEMENT wp;
    GetWindowPlacement(&wp);
    RECT *wr = &wp.rcNormalPosition;
    theApp.WriteProfileInt("MainWindow", "ScreenLeft", wr->left);
    theApp.WriteProfileInt("MainWindow", "ScreenTop", wr->top);
}

void CMainWindow::OnResetWindow()
{
    int screenWidth = GetSystemMetrics(SM_CXSCREEN);
    WINDOWPLACEMENT wp;
    GetWindowPlacement(&wp);
    RECT *wr = &wp.rcNormalPosition;
    int left = wr->left;
    int cwidth = 80*windowFonts.HCourier.across['X'] +
                 3*GetSystemMetrics(SM_CXBORDER) +
                 2*GetSystemMetrics(SM_CXFRAME) +
                 GetSystemMetrics(SM_CXVSCROLL) + 5;
// Try to get the whole window onto the screen.
    if (left + cwidth > screenWidth)
    {   left = screenWidth - cwidth;
        if (left < 0) left = 0;
    }
    SetWindowPos(NULL, 
        left, wr->top,
        cwidth, (wr->bottom - wr->top),
        SWP_SHOWWINDOW | SWP_NOZORDER);
    UpdateWindow();
    cwin_linelength = 80;
    theApp.WriteProfileInt("MainWindow", "ScreenLeft",   left);
    theApp.WriteProfileInt("MainWindow", "ScreenWidth",  cwidth);
    theApp.WriteProfileInt("MainWindow", "ScreenTop",    wr->top);
    theApp.WriteProfileInt("MainWindow", "ScreenHeight", wr->bottom-wr->top);
    theApp.WriteProfileInt("MainWindow", "LineLength",   cwin_linelength);
} 

void CMainWindow::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar *pNctl)
{
// I will start by computing the total height of all the stuff I have in
// my text buffer. At the very worst I only save a couple of thousand lines,
// so adding up their heights again will not be TOO painful, I hope.
    int VScrollPos, movedUp=0, i, w;
    int aboveTop = -LineY(lineFirst);
    int totalHeight = aboveTop + LineY(lineLast) + LineDY(lineLast);

    inject_randomness(totalHeight);
// If I can make everything visible I will do that regardless of anything
// the user tries to do.
    if (totalHeight <= clientHeight)
    {   lineVisible = lineFirst;
        movedUp = aboveTop;
        VScrollPos = 0;
    }
    else
    {    switch (nSBCode)
        {
    case SB_ENDSCROLL:
            return;
    case SB_REFRESH_THUMB:
// In case the window has just been enlarged I check to see if I can scroll
// up a bit until one more scroll up would make the last line of my text
// drop off the (new) bottom of the window.
            while (lineVisible!=lineFirst)
            {   int lv = (lineVisible-1)&LINE_MASK;
                int nAbove = lineBuffer[lv].position -
                             lineBuffer[lineFirst].position;
                if (totalHeight > nAbove+clientHeight) break;
                lineVisible = lv;
                w = LineDY(lv);
                movedUp += w;
                aboveTop -= w;
            }
            break;
    case SB_THUMBPOSITION:
    case SB_THUMBTRACK:
            i = (nPos*(totalHeight-clientHeight))/100;
            if (i > aboveTop)
            {   while (totalHeight > aboveTop+clientHeight &&
                       i > aboveTop)
                {   w = LineDY(lineVisible);
                    aboveTop += w;
                    movedUp -= w;
                    lineVisible = (lineVisible+1) & LINE_MASK;
                }
            }
            else
            {   i += LineDY(lineVisible);
                while (lineVisible != lineFirst &&
                       i <= aboveTop)
                {   lineVisible = (lineVisible-1) & LINE_MASK;
                    w = LineDY(lineVisible);
                    aboveTop -= w;
                    movedUp += w;
                }
            }
            break;
    case SB_FOR_CARET:
            if (LineY(caretLine)+LineDY(caretLine) > clientHeight)
            {   while (totalHeight > aboveTop+clientHeight &&
                       LineY(caretLine)+LineDY(caretLine) > clientHeight)
                {   w = LineDY(lineVisible);
                    aboveTop += w;
                    movedUp -= w;
                    lineVisible = (lineVisible+1) & LINE_MASK;
                }
            }
            else
            {   while (lineVisible != lineFirst &&
                       LineY(caretLine) < 0)
                {   lineVisible = (lineVisible-1) & LINE_MASK;
                    w = LineDY(lineVisible);
                    aboveTop -= w;
                    movedUp += w;
                }
            }
            break;
    case SB_LINEDOWN:
// If the bottom line of text is already visible I will not scroll down
// any further.
            if (totalHeight > aboveTop+clientHeight)
            {   lineVisible = (lineVisible+1) & LINE_MASK;
                w = lineBuffer[lineVisible].height;
                aboveTop += w;
                movedUp = -w;
            }
            break;
    case SB_LINEUP:
            if (lineVisible != lineFirst)
            {   w = lineBuffer[lineVisible].height;
                aboveTop -= w;
                movedUp = w;
                lineVisible = (lineVisible-1) & LINE_MASK;
            }
            break;
// When asked to scroll be a "page" I in fact jump by around 0.7 times
// the number of lines visible on a page.
    case SB_PAGEDOWN:
            while (totalHeight > aboveTop+clientHeight &&
                   -10*movedUp < 7*clientHeight)
            {   lineVisible = (lineVisible+1) & LINE_MASK;
                w = lineBuffer[lineVisible].height;
                aboveTop += w;
                movedUp -= w;
            }
            break;
    case SB_PAGEUP:
            while (lineVisible != lineFirst &&
                   10*movedUp < 7*clientHeight)
            {   w = lineBuffer[lineVisible].height;
                aboveTop -= w;
                movedUp += w;
                lineVisible = (lineVisible-1) & LINE_MASK;
            }
            break;
        }
        if (lineVisible == lineFirst) VScrollPos = 0;
        else if (totalHeight <= aboveTop+clientHeight) VScrollPos = 100;
        else VScrollPos = (100*aboveTop)/(totalHeight-clientHeight);
    }
// If the user had just dragged the scroll bar I will tend to leave the
// scroll bar thumb where the user put it. However I will make an exception
// if the user's drag caused me to go to one or other extreme position, since
// I think it would be confusing to have the window totally fully scrolled
// and the thumb not extremal in its bar. But at all intermediate positions
// it is kindest to let it settle where the user put it!
    if (nSBCode == SB_THUMBPOSITION ||
        nSBCode == SB_THUMBTRACK)
    {   if (VScrollPos == 0 || VScrollPos == 100)
            nPos = VScrollPos;
        SetScrollPos(SB_VERT, nPos, TRUE);
    }
    else SetScrollPos(SB_VERT, VScrollPos, TRUE);
    if (movedUp != 0)
    {   HideCaret();
        ScrollWindow(0, movedUp, NULL, NULL);
        ShowCaret();
    }
// If the window is minimized then I will not change the status of apparent
// visibility of the caret. This is important because if the caret becomes
// marked as invisible because (for instance) the window is of zero size then
// it will remain invisible and the window will not be scrolled ever, leaving
// the text buffer to over-fill and hang things up.
    if (IsIconic()) return;
    else if (caretY >= 0 && caretY1 <= clientHeight &&
        caretX-xOffset >= 0 && caretX-xOffset < clientWidth)
        caretVisible = TRUE;
    else caretVisible = FALSE;
}


void CMainWindow::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar *PCntl)
{
// Each time I hit the horizontal scroll-bar I will check to find how
// long the longest (partially) visible line is.
    int yBase = lineBuffer[lineVisible].position;
    int line, longestLine = 0;
    for (line=lineVisible;; line=(line+1)&LINE_MASK)
    {   int y = lineBuffer[line].position - yBase;
        if (y > clientHeight) break;
        int w = lineBuffer[line].width;
        if (w > longestLine) longestLine = w;
        if (line==lineLast) break;
    }
// If everything fits I will just make sure I am scrolled fully left. Well as
// a matter of caution I do not force things that way if the request was
// to make the caret visible, since maybe if the screen is not quite up to
// date it may seem that I could afford to scroll fully left but that would
// in fact hide the caret.
    if (longestLine < clientWidth && nSBCode != SB_FOR_CARET)
    {   if (xOffset != 0)
        {   HideCaret();
            ScrollWindow(xOffset, 0, NULL, NULL);
            ShowCaret();
        }
        xOffset = 0;
        SetScrollPos(SB_HORZ, 0, TRUE);
        return;
    }
    int moveLeft = 0, w;
    switch (nSBCode)
    {
case SB_ENDSCROLL:
        return;
case SB_REFRESH_THUMB:
        break;
case SB_THUMBPOSITION:
case SB_THUMBTRACK:
        w = (nPos*(longestLine-clientWidth/2))/100;
        moveLeft = xOffset - w;
        xOffset = w;
        break;
case SB_FOR_CARET:
        w = windowFonts.HCourier.across['X'];
        if (caretX-xOffset < 5*w)
            moveLeft = w*((clientWidth/2 - (caretX-xOffset))/w);
        else if (caretX-xOffset >= clientWidth)
            moveLeft = -w*((caretX - xOffset - clientWidth)/w + 4);
        xOffset -= moveLeft;
        break;
// Small jumps are by the width of the letter X in the biggest fixed pitch
// font that I have selected. Thus if you select a big font you will get
// coarser contol over horizontal scrolling.
case SB_LINERIGHT:
        w = windowFonts.HCourier.across['X'];
        xOffset += w;
        moveLeft = -w;
        break;
case SB_LINELEFT:
        w = windowFonts.HCourier.across['X'];
        xOffset -= w;
        moveLeft = w;
        break;
// Big jumps are by roughly (2/3) the width of the main Window
case SB_PAGERIGHT:
        w = (2*clientWidth)/3;
        xOffset += w;
        moveLeft = -w;
        break;
case SB_PAGELEFT:
        w = (2*clientWidth)/3;
        xOffset -= w;
        moveLeft = w;
        break;
    }
    if (xOffset < 0)
    {   moveLeft += xOffset;
        xOffset = 0;
    }
// I will permit scrolls to the right to a stage where the longest line
// is (1/2) across the screen. But no further and especially I will not
// permit scrolls right that cause the text on the screen to vanish
// totally.  The limit I use here is somewhat of an arbitrary choice. If a
// "scroll page right" request looked as if it would move beyond this I will
// clip the scroll.
    w = longestLine - clientWidth/2;
    if (w <= 0)
    {   moveLeft += xOffset;
        xOffset = 0;
        w = 1;
    }
    else if (xOffset>w)
    {   moveLeft += xOffset - w;
        xOffset = w;
    }
    int HScrollPos = (100*xOffset)/w;
    if (HScrollPos > 100) HScrollPos = 100;
    if ((nSBCode != SB_THUMBPOSITION &&
         nSBCode != SB_THUMBTRACK) ||
        HScrollPos == 0 ||
        HScrollPos == 100) SetScrollPos(SB_HORZ, HScrollPos, TRUE);
    else SetScrollPos(SB_HORZ, nPos, TRUE);
    if (moveLeft != 0)
    {   HideCaret();
        ScrollWindow(moveLeft, 0, NULL, NULL);
        ShowCaret();
    }
}


void CMainWindow::OnSetFocus(CWnd *pOldWnd)
{
    CreateSolidCaret(caretWidth, windowFonts.HCourier.height);
    ShowCaret();
    SetWindowPos(&wndTop, 0, 0, 0, 0, SWP_NOMOVE|SWP_NOSIZE|SWP_SHOWWINDOW);
    selectScrollSpeed = 0;
    hasFocus = TRUE;   /* True just after focus has returned to this window */
}


void CMainWindow::OnKillFocus(CWnd *pNewWnd)
{
    ::DestroyCaret();
    hasFocus = FALSE;
}


// Sometime I find reading documentation quite hard. I had really thought that
// when one selected an application (eg using ALT+TAB) that would give the
// input focus to that application's main window. But it appears
// (experimentally) that this is not always true, and I found myself with
// a window with hard blue title bar but no input focus. It seems (?) that
// the application has been "activated", so here I ensure that when that
// happens it grabs the focus. Elsewhere you will find that whenever I see a
// mouse button depressed I grab the focus too (just to be on the safe side).

void CMainWindow::OnActivate(UINT state, CWnd *pWnd, BOOL minim)
{
    if (state != WA_INACTIVE) SetFocus();
}

// When I put a character into the text buffer I need to worry about purging
// old characters when the buffer wraps around. That may have an effect on
// what is visible on the screen, or on a selected region. If I insert a
// character and I am at the foot of a page I may need to scroll up. All
// in all the funny cases are quite messy here!

void CMainWindow::cwin_putchar(int ch)
{
    if (hasFinished) return;
    BOOL caretAtEnd = (caretChar == textLast);
    if (ch == '\n')
    {
// If the caret is at the end of the text and if "page mode" is enabled
// then putting a newline into the text buffer will sometimes lead to
// a pause....
        BOOL usualTitle = TRUE;
// The test here says pause if
//  (a) I am in page mode
//  (b) lineVisible==pageLine. Well lineFirst is the line that is now in
//      danger of being about to scroll off the top of the screen, and so
//      pageLine will identify the current line to be "protected" from that
//      fate.
//  (c) caretLine vs clientHeight: This tries to test if scrolling would be
//      called for if the caret moved down a line (hence the 2*LineDY()).
//  In the pause case I just loop polling the window manager until something
//  magic happens. In general I can do the correct magic by making a suitable
//  selection of events do "pageLine = caretLine;"
//
// Actually it is nastier than that, because lineVisible may not be up to
// date - so I have to work out what lineVisible WOULD be in the relevant
// situation by having code rather line that in OnVScroll/SB_FOR_CARET.
        while (pageMode)
        {   int lv = lineVisible, w;
            int aboveTop = -LineY(lineFirst);
            int totalHeight = aboveTop + LineY(lineLast) + LineDY(lineLast);
            if (totalHeight <= clientHeight) lv = lineFirst;
            else while (totalHeight > aboveTop+clientHeight &&
                   LineY(caretLine)+LineDY(caretLine) > clientHeight)
            {   w = LineDY(lv);
                aboveTop += w;
                lv = (lv+1) & LINE_MASK;
            }
            if (lv==pageLine &&
                (LineY(caretLine)+2*LineDY(caretLine) > clientHeight))
            {   if (usualTitle)
                {   usualTitle = FALSE;
                    pagePaused = TRUE;
//                  BeginWaitCursor();
// For reasons that I do not fully understand a "wait" cursor established here
// gets turned back into the usual arrow one before I want it to. I suspect
// maybe that whenever the system re-draws the cursor it does so using the
// version that is set as default for the application? Anyway the effect is
// that I get an apparantly inconsistent behaviour, and at present I think
// that keeping the cursor consistently an arrow is better than letting it
// flash incoherently between that and an hourglass.
                    SetWindowText("(page-mode) Type any key to continue");
                }
// Here I will force the caret to be visible and poll the window manager
                if (!hasFinished)
                {   OnVScroll(SB_FOR_CARET, 0, NULL);
                    OnHScroll(SB_FOR_CARET, 0, NULL);
                    cwin_poll_window_manager();
                }
                if (hasFinished) return;
                continue;
            }
            else break;
        }
        if (!usualTitle)
        {   SetWindowText(mainTitle);
//          EndWaitCursor();
        }
        pagePaused = FALSE;
        textBuffer[textLast] = '\n';
        int n = (textLast+1) & TEXT_MASK;
        if (n == textFirst) WrapTextBuffer(TRUE);
        textLast = n;
// When I see a newline I may need to wrap the line buffer, discarding the
// oldest saved line.
        int nextPos = lineBuffer[lineLast].position +
                      lineBuffer[lineLast].height;
        n = (lineLast+1) & LINE_MASK;
        if (n == lineFirst) WrapTextBuffer(TRUE);
        lineLast = n;
        lineBuffer[lineLast].position = nextPos;
        lineBuffer[lineLast].up = windowFonts.HCourier.up;
        lineBuffer[lineLast].height = windowFonts.HCourier.up +
                                      windowFonts.HCourier.down;
        lineBuffer[lineLast].width = 0;
        lineBuffer[lineLast].address = textLast;
        endFontWidths = windowFonts.HCourier.across;
        endX = 0;
        if (caretAtEnd)
        {   caretChar = icaretChar = textLast;
            caretLine = icaretLine = lineLast;
            caretX = icaretX = 0;
            caretFontWidths = icaretFontWidths = windowFonts.HCourier.across;
        }
    }
    else
    {   textBuffer[textLast] = ch;
        int n = (textLast+1) & TEXT_MASK;
        if (n == textFirst) WrapTextBuffer(TRUE);
// I invalidate all the way to the right of the line just to be on the
// safe side. This is probably excessive... but equally the painting in of
// the solid blank to the right of any real text will not be too expensive.
        CRect cr(lineBuffer[lineLast].width-xOffset, LineY(lineLast),
                 clientWidth, LineY(lineLast)+LineDY(lineLast));
        InvalidateRect(&cr);  // Should I hide the caret here?
        textLast = n;
        endX += endFontWidths[ch];
        lineBuffer[lineLast].width += endFontWidths[ch];
        if (caretAtEnd)
        {   caretChar = icaretChar = textLast;
            caretX += caretFontWidths[ch];
            icaretX = caretX;
        }
    }
}

// This code inserts characters wherever the caret happens to be, typically
// in the middle of the text buffer. This returns TRUE if it succeeds. The
// case when it might fail is if the text buffer is full and the caret is on
// the first line. Then to make room for the next stuff the first line would
// need to be discarded, but I can not do that without loss of the caret.
//
// UnTypeAhead() is used to push characters into the type-ahead buffer if
// a newline is inserted into the current line of input (ie between
// inputLineStart and textLast). It returns FALSE if pushing characters
// flushed out previously typed stuff.

BOOL CMainWindow::UnTypeAhead(int ch)
{
    int w = (typeAheadP1-1)&typeAheadBufferMask;
    typeAheadBuffer[w] = ch;
    typeAheadP1 = w;
    if (typeAheadP1 == typeAheadP2)
    {   typeAheadP2 = (typeAheadP2-1)&typeAheadBufferMask;
        return FALSE;  // Inserting pushes out something else
    }
    else return TRUE;
}

BOOL CMainWindow::InsertAtCaret(char *s, int n)
{
// I will do large inserts in 60-character chunks. That is so I can have
// a limited size circular buffer (64 chars here) for use when copying
// stuff down the buffer. Huge inserts would benefit from a larger chunk-size
// here, at the cost of using more memory for the copy buffer.
    while (n > 60)
    {   if (!InsertAtCaret(s, 60)) return FALSE;
        s += 60;
        n -= 60;
    }
    if (n == 0) return TRUE;
    int oldCaretLine = caretLine, oldCaretChar = caretChar;
    BOOL startEnd = (inputLineStart == textLast);
    int i, p = textLast;
// Firstly I will make sure that there is room for the inserted text by
// stepping on n characters from the current end of the text buffer and
// wraping to free up the space I walk over.  If this were to collide with
// the caret position I would be in a MESS so in such cases I will not
// perform the insert & will return a failure flag.
    for (i=0; i<n; i++)
    {   p = (p+1)&TEXT_MASK;
        if (p == textFirst)
        {   if (caretLine == lineFirst) return FALSE; // fail
            else WrapTextBuffer(FALSE);
        }
    }
// Also I need to ensure that there is room for the number of new lines
// that I will insert. It will be rare that this is a problem, I suspect.
// Also beware here if the caret is positioned on the top line of the
// buffer.
    int k = 0;
    for (i=0; i<n; i++) if (s[i] == '\n') k++;
    p = lineLast;
    for (i=0; i<k; i++)
    {   p = (p+1)&LINE_MASK;
        if (p == lineFirst)
        {   if (caretLine == lineFirst) return FALSE; // fail
            else WrapTextBuffer(FALSE);
        }
    }
// Now I know that there is room for the insertion, I will "just" need to
// copy characters up through the text buffer.
    char circle[64], circleFlags[64];
    memcpy(circle, s, n);
    memset(circleFlags, 0, n);
    int inP = n, outP = 0;
// (line,p) is where I read characters from the buffer, while (line1,p1)
// is where I put them back. Certainly at the start, and quite often all
// the way through these values will remain in step. They may drift apart if
// previous deletions within lines lave left gaps in the buffer between the
// end of one line and the start of the next.
    int line = caretLine;
    p = caretChar;
    int line1 = line, p1 = p;
    while (p != textLast)
    {   int c = textBuffer[p];
        circle[inP] = c;
        circleFlags[inP] = 0;
        if (p == caretChar) circleFlags[inP] |= 1;
// I will leave inputLineStart where it is if it lies just before the
// caret position at the start of the insert operation.
        if (p == inputLineStart && p != oldCaretChar) circleFlags[inP] |= 2;
        if (p == icaretChar) circleFlags[inP] |= 4;
        if (c == '\n')
        {   line = (line+1)&LINE_MASK;
            p = lineBuffer[line].address;
        }
        else p = (p+1)&TEXT_MASK;
        inP = (inP+1)&63;
        int c1 = circle[outP];
        textBuffer[p1] = c1;
        if (circleFlags[outP] & 1) caretChar = p1, caretLine = line1;
        if (circleFlags[outP] & 2) inputLineStart = p1;
        if (circleFlags[outP] & 4) icaretChar = p1, icaretLine = line1;
        p1 = (p1+1)&TEXT_MASK;
        outP = (outP+1)&63;
// Now if I had just inserted a newline I need to fix up the pointers
// from the line buffer into the text buffer.
        if (c1 == '\n')
        {   if (line == line1) // Here I need to shuffle lines up
            {   int a = p1, line2=line;
                lineLast = (lineLast+1)&LINE_MASK;
                for (;;)
                {   line2 = (line2+1)&LINE_MASK;
                    int w = lineBuffer[line2].address;
                    lineBuffer[line2].address = a;
                    if (line2==lineLast) break;
                    a = w;
                }
                line = (line+1)&LINE_MASK;
            }
            line1 = (line1+1)&LINE_MASK;
            lineBuffer[line1].address = p1;
        }
    }
    while (inP != outP)
    {   int c1 = circle[outP];
        textBuffer[p1] = c1;
        if (circleFlags[outP] & 1) caretChar = p1, caretLine = line1;
        if (circleFlags[outP] & 2) inputLineStart = p1;
        if (circleFlags[outP] & 4) icaretChar = p1, icaretLine = line1;
        if (c1 == '\n')
        {   line1 = (line1+1)&LINE_MASK;
            lineBuffer[line1].address = p1;
        }
        p1 = (p1+1)&TEXT_MASK;
        outP = (outP+1)&63;
    }
    textLast = p1;
    lineLast = line1;
// Here it may be that a newline had been inserted within the line that
// was being prepared for input. If so, stuff after that newline must be
// pushed back into the type-ahead buffer. When this happens it will always
// be the case that the text in the buffer after inputLineStart will form
// a compact block so I can just copy chars backwards
    BOOL success = TRUE;
    if (startEnd) inputLineStart = textLast;
    else if (inputLineStart>=0 && k!=0)
    {   int lastNewline = inputLineStart;
        while (lastNewline!=textLast && textBuffer[lastNewline]!='\n')
            lastNewline = (lastNewline+1)&TEXT_MASK;
        while (textLast!=lastNewline)
        {   int nn = (textLast-1)&TEXT_MASK;
            if (textLast==caretChar) caretChar = nn;
            if (textLast==icaretChar) icaretChar = nn;
            if (textLast==selStartChar ||
                textLast==selFirstChar ||
                textLast==selEndChar) CancelSelection();
            textLast = nn;
            int c = textBuffer[textLast];
            if (!UnTypeAhead(c)) success = FALSE;
            if (c=='\n') lineLast = (lineLast-1)&LINE_MASK;
        }
    }
    LineSizes();
    CRect cr(0, LineY(oldCaretLine), clientWidth, clientHeight);
    if (k==0)                      // No newlines inserted
    {   cr.left = caretX;
        cr.bottom = LineY(caretLine)+LineDY(caretLine);
    }
    InvalidateRect(&cr);
    UpdateWindow();
    cwin_poll_window_manager();
    return success;
}

void CMainWindow::cwin_caret_putchar(int ch)
{
    if (hasFinished) return;
// If the caret happens to be at the end maybe I ought not to have got here
// anyway, but I will chain to the code that inserts things at the end of the
// text.
    if (caretChar == textLast)
    {   cwin_putchar(ch);
        return;
    }
    char buff[4];
    buff[0] = ch;
// I beep if the insertion was impossible.
    if (!InsertAtCaret(buff, 1)) ::MessageBeep(0xffffffff);
}

void CMainWindow::cwin_caret_replacechar(int ch)
{
    if (hasFinished) return;
// If the caret happens to be at the end maybe I ought not to have got here
// anyway, but I will chain to the code that inserts things at the end of the
// text.
    if (caretChar == textLast || ch == '\n' || textBuffer[caretChar] == '\n')
    {   cwin_putchar(ch);
        return;
    }
// Gosh this OUGHT to be easy!
    textBuffer[caretChar] = ch;
    if (caretChar == icaretChar)
    {   icaretX += caretFontWidths[ch];
        icaretChar++;
    }
    CRect cr(caretX, LineY(caretLine),
             clientWidth, LineY(caretLine)+LineDY(caretLine));
    InvalidateRect(&cr);
    caretX += caretFontWidths[ch];
    caretChar++;
    UpdateWindow();
    cwin_ensure_screen(FALSE);
}

// When I have put enough characters on the screen my text buffer may become
// full. In which case I will discard the earliest stored line in it. Because
// the line will always be stored with at least a newline character present
// this guarantees to free up at least one byte in the buffer. I can also
// call this routine to discard the top line of the buffer when I need to
// recycle space in the record of lines (as distinct from characters).
//
// If I attempt to cancel part of the buffer by coming here but either the
// top line of the buffer is visible on the screen or part of the top line
// is included in a selection then I will pause until the user scrolls the
// window or does something to the selection that will mean that throwing
// away information will not discard anything still being looked at.
//
// Note that when I say here "Part of the first line is selected" I will
// mean that a non-empty part of the line is selected. Not having a
// selection in force is indicated by selStartChar==selEndChar, but the
// selection pointers can otherwise point anywhere at all in the buffer
// or indeed outside it.

void CMainWindow::WrapTextBuffer(BOOL waitForSelection)
{
    selRootValid = FALSE;
    BOOL usualTitle = TRUE;
    if (waitForSelection)
    {   while ((lineVisible == lineFirst && caretChar != textLast &&
                LineY(lineLast)+LineDY(lineLast)>=clientHeight) ||
               (selStartLine == lineFirst &&
                selStartChar != selEndChar))
        {   cwin_ensure_screen(FALSE);
            if (usualTitle)
                usualTitle = FALSE,
                SetWindowText(
                    "Output pending: cancel selection/scroll down please");
            cwin_poll_window_manager();
        }
    }
    if (hasFinished) return;
    if (!usualTitle) SetWindowText(mainTitle);
    if (lineFirst==lineLast) OnClear(); // Drastic!
    else
    {   lineFirst = (lineFirst+1)&LINE_MASK;
        textFirst = lineBuffer[lineFirst].address;
    }
}

void cwin_putchar(int c)
{
    theApp.mainWindow->cwin_putchar(c);
    inject_randomness(c);
    inject_randomness((int)clock());
}

void CMainWindow::cwin_puts(const char *s)
{
    if (hasFinished) return;
    int ch;
// Here I should be careful and do just ONE call to Invalidate for all the
// changes that I make. But to start with it is MUCH easier to call putchar
// lots of times, so that is what I will do.
    while ((ch=*s++)!=0) cwin_putchar(ch);
}

void cwin_puts(const char *s)
{
    theApp.mainWindow->cwin_puts(s);
}

#ifndef MS_CDECL
#ifdef _MSC_VER
#define MS_CDECL __cdecl
#else
#define MS_CDECL
#endif
#endif

void MS_CDECL CMainWindow::cwin_printf(const char *s, ...)
{
    if (hasFinished) return;
    va_list a;
    va_start(a, s);
    cwin_vfprintf(s, a);
    va_end(a);
}

void MS_CDECL cwin_printf(const char *s, ...)
{
    if (hasFinished) return;
    va_list a;
    va_start(a, s);
    theApp.mainWindow->cwin_vfprintf(s, a);
    va_end(a);
}

// The versions of printf() that work with the window system use an internal
// buffer and print characters into that before sending them to the screen.
// It appears to be hard to check for overflow of this buffer, so the user
// will have to take care. A call to cwin_printf that generates more than
// MAX_PRINTF_OUTPUT characters can crash the system. Sorry.  Maybe I
// should use the Watcom-specific _vbprintf() function here...

#define MAX_PRINTF_OUTPUT 256

void CMainWindow::cwin_vfprintf(const char *s, va_list a)
{
    if (hasFinished) return;
    char temp[MAX_PRINTF_OUTPUT];
#ifdef __WATCOMC__
    _vbprintf(temp, MAX_PRINTF_OUTPUT, s, a);
// I put a zero byte at the end of the buffer to ensure that the string
// left there is properly terminated even if _vbprintf() wrote proper
// characters right up to the end.
    temp[MAX_PRINTF_OUTPUT-1] = 0;
#else
    vsprintf(temp, s, a);
#endif
    cwin_puts(temp);
}

void cwin_vfprintf(const char *s, va_list a)
{
    theApp.mainWindow->cwin_vfprintf(s, a);
}

void CMainWindow::cwin_ensure_screen(BOOL poll)
{
    if (hasFinished) return;
// Here I need to do Invalidate operations, re-position the caret
// and adjust the position of scroll-bar thumbs.
    if (caretVisible)
    {   OnVScroll(SB_FOR_CARET, 0, NULL);
        OnHScroll(SB_FOR_CARET, 0, NULL);
    }
//  OnVScroll(SB_REFRESH_THUMB, 0, NULL);
    HideCaret();
    CPoint caretPos(caretX-xOffset, caretY);
    SetCaretPos(caretPos);
    ShowCaret();
    if (poll) cwin_poll_window_manager();
}

void cwin_ensure_screen()
{
    theApp.mainWindow->cwin_ensure_screen(TRUE);
}

// This will remove a character from the buffer at a location defined
// by the caret, which will in general not be at the end of the text.


void CMainWindow::cwin_caret_unputchar()
{
// When I try to remove a character from the screen I know that there is
// no selection active, since a DELETE when there was a selection deleted it
// as a block, and so did not reach this bit of code. So perhaps I can
// make this code work by creating a selected region containing the
// character (or prompt string) that I to be discarded and then do a
// DeleteSelection.
    if (hasFinished) return;
// If it happens that I am at the end of the text I will call the other
// bit of character deletion code, so that in the bulk of this function I
// can know that I am in the general case (which tends to be an expensive one)
    if (caretChar==textLast)
    {   cwin_unputchar();
        return;
    }
    selRootValid = FALSE;
// If the caret is right at the start of the buffer I do not have
// anything to delete. This will, of course, include the case where the
// buffer is totally empty.
    if (caretChar==textFirst) return;
// Set up the start of the selection at the position of the caret.
    selFirstChar = selStartChar = selEndChar = caretChar;
    selFirstX = selStartX = selEndX = caretX;
    selFirstLine = selStartLine = selEndLine = caretLine;
// Now I need to step back a "character", where that could be a newline
// or a prompt string rather than any single simple character. I also
// ought to worry here about deletion of items in the text buffer that
// control formatting. All in all this is pretty dodgy, so I will cope with
// just the simple cases to start with.
    int n;
    if (lineBuffer[caretLine].address == caretChar)  // deleting a newline?
    {   return;
// For now I am going to prevent deletion of or through a prompt or newline
        n = (caretLine-1)&LINE_MASK;
        caretLine=n;
        caretX = lineBuffer[n].width;
        n = lineBuffer[n].address;
        while (textBuffer[n]!='\n') n = (n+1)&TEXT_MASK;
    }
    else
    {   n = (caretChar-1) & TEXT_MASK;
// I produce just an APPROXIMATION to the desired caretX here, but want that
// so that I can limit the amount of re-painting that happens.
        int w = windowFonts.HCourier.across['X'];
        if ((textBuffer[n]&0xff)==CH_ENDPROMPT)   // delete whole of a prompt
        {
            return;                        // do not delete prompt
            do
            {   n = (n-1)&TEXT_MASK;
                caretX -= w;
            } while (n!=textFirst && (textBuffer[n]&0xff)!=CH_PROMPT);
        }
        else caretX -= w;
    }
    caretChar = n;
    if (caretLine == lineLast)
    {   icaretChar = caretChar;
        icaretLine = caretLine;
        icaretX = caretX;
    }
    selStartChar = n;
    selStartLine = caretLine;
    selStartX = caretX;
    DeleteSelection();
}

// Now a version of unputchar that deletes characters from the end of the
// text buffer (and the caret may or may not be there).

void CMainWindow::cwin_unputchar()
{
    if (hasFinished) return;
    selRootValid = FALSE;
    int n;
    if (textFirst == textLast) return;             // utterly empty buffer
    if (lineBuffer[lineLast].address == textLast)  // deleting a newline?
    {   return;
        n = (lineLast-1)&LINE_MASK;
        endX = lineBuffer[n].width;
        if (caretLine==lineLast) caretLine=n, caretX=endX;
        if (icaretLine==lineLast) icaretLine=n, icaretX=endX;
        lineLast=n;
        n = lineBuffer[n].address;
        while (textBuffer[n]!='\n') n = (n+1)&TEXT_MASK;
        if (textLast == caretChar) caretChar = n;
        if (textLast == icaretChar) icaretChar = n;
        if (textLast == inputLineStart) inputLineStart = n;
        textLast = n;
    }
    else
    {   n = (textLast-1) & TEXT_MASK;
        int w = windowFonts.HCourier.across['X'];
        if ((textBuffer[n]&0xff)==CH_ENDPROMPT)   // delete whole of a prompt
        {   return;
            do
            {   n = (n-1)&TEXT_MASK;
                endX -= w;
            } while (n!=textFirst && (textBuffer[n]&0xff)!=CH_PROMPT);
        }
        else endX -= w;
        if (textLast == caretChar) caretChar = n;
        if (textLast == icaretChar) icaretChar = n;
        if (textLast == inputLineStart) inputLineStart = n;
        textLast = n;
// The amount of invalidation done here runs across to the end of the
// last line, and that ought to get rid of any residues of the old
// caret. I use an APPROXIMATION to the new value of endX, but hope that
// that gets corrected during the re-painting.
        CRect cr(endX-xOffset, LineY(lineLast),
                 clientWidth, LineY(lineLast)+LineDY(lineLast));
        InvalidateRect(&cr);  // Should I hide the caret here?
    }
    UpdateWindow();
    HideCaret();
    CPoint caretPos(caretX-xOffset, caretY);
    SetCaretPos(caretPos);
    ShowCaret();
}

int CMainWindow::cwin_getchar()
{
    if (hasFinished) return EOF;
    int ch;
    if (inputP >= 0)
    {   ch = inputBuffer[inputP++];
        if (ch == '\n') inputP = -1; // This buffer now all used up.
        return ch;
    }
    cwin_putchar(CH_PROMPT);
    cwin_puts(cwin_prompt_string);
    if (spool_file != NULL) fprintf(spool_file, "%s", cwin_prompt_string);
    cwin_putchar(CH_ENDPROMPT);
    if (hasFinished) return EOF;
    inputLineStart = textLast;          // just beyond the prompt
// Next I move characters across from the type-ahead buffer into the main
// text buffer, echoing them as I go (and handling DELETE chars too). I
// stop when I find a newline.  Perhaps some people would like if if some
// other characters would terminate an input line, but for the moment I am
// sticking to just newline.... except that any keyboard or menu activity
// that raises an "exception" will stop input for me rather abruptly.
    for (;;)
    {   cwin_ensure_screen(FALSE);
        while (typeAheadP1 == typeAheadP2 &&
               clipboardInput == NULL)
        {   cwin_poll_window_manager();
            if (hasFinished || exception_pending()) return EOF;
        }
        if (clipboardInput != NULL)
        {   ch = *clipboardInputP++;
// When input is coming from the clipboard to the very end of the input
// text I will ignore copied prompt strings. Note that this is different
// from the situation with PASTE inserts into the middle of the text.
// A curious side-effect here is that if a regular TEXT clipboard file is
// pasted in and it happens to contain these funny character codes...
            while ((ch&0xff) == CH_PROMPT)
            {   while ((ch = *clipboardInputP++) != 0 &&
                       (ch&0xff) != CH_ENDPROMPT);
                if (ch == 0) break;
                ch = *clipboardInputP++;
            }
            if (ch == '\r') continue;
            if (ch == 0)
            {   free(clipboardInput);
                clipboardInput = NULL;
                continue;
            }
        }
        else
        {   ch = typeAheadBuffer[typeAheadP1];
            typeAheadP1 = (typeAheadP1 + 1) & typeAheadBufferMask;
        }
        if (ch == 0x7f) cwin_unputchar();
        else cwin_putchar(ch);
        if (ch == '\n' || hasFinished) break;
    }
    if (hasFinished) return EOF;
// By the time I exit the above loop there must be at least one character
// in the line that has just been read, even if it is only the terminating
// '\n'.
    inputP = 0;
// When I copy stuff from the screen into the input buffer I discard any
// prompts. They might be there if the line of input was created in part by
// pasting material into the middle of a partly-typed line.
    BOOL inPrompt = FALSE;
    for (;;)
    {   ch = textBuffer[inputLineStart];
        inputLineStart = (inputLineStart+1)&TEXT_MASK;
// Here I quietly truncate very very long input lines. For my first attempt
// I have inputBufferSize set at 2048.
        if ((ch&0xff) == CH_PROMPT) inPrompt = TRUE;
        if (inputP<inputBufferSize && !inPrompt) inputBuffer[inputP++] = ch;
        if ((ch&0xff) == CH_ENDPROMPT) inPrompt = FALSE;
        else if (ch == '\n') break;
    }
    inputBuffer[inputBufferSize-1] = '\n';
// Now I have the next line of user input in inputBuffer, running from 0
// up to the first '\n' (and I know there is a '\n' in there somewhere).
// I want to copy it away into a "saved input lines" buffer, so that they
// can be retrieved later by a DOSKEY-like protocol. Note that provided
// I keep the size of the save buffer larger than that of the input buffer
// the copying operation here will not cause embarassing overflow!
    currentInputLine = -1;
    savedLines[savedP2++] = savedLast;
    if (savedP2 == MAX_SAVED_LINES) savedP2 = 0;
    if (savedP2 == savedP1)
    {   savedP1++;
        if (savedP1 == MAX_SAVED_LINES) savedP1 = 0;
        savedFirst = savedLines[savedP1];
    }
    inputP = 0;
    for (;;)
    {   ch = inputBuffer[inputP++];
        savedChars[savedLast++] = ch;
        if (savedLast == MAX_SAVED_CHARS) savedLast = 0;
        if (savedLast == savedFirst)
        {   savedP1++;
            if (savedP1 == MAX_SAVED_LINES) savedP1 = 0;
            savedFirst = savedLines[savedP1];
        }
        if (ch == '\n') break;
    }
    inputP = 0;
    ch = inputBuffer[inputP++];
    if (ch == '\n') inputP = -1; // This buffer now all used up.
    cwin_ensure_screen(FALSE);
    return ch;
}

int cwin_getchar()
{
    return theApp.mainWindow->cwin_getchar();
}

int CMainWindow::cwin_getchar_nowait()
{
    if (hasFinished) return EOF;
    int ch;
    if (inputP >= 0)
    {   ch = inputBuffer[inputP++];
        if (ch == '\n') inputP = -1; // This buffer now all used up.
        return ch;
    }
    cwin_putchar(CH_PROMPT);
    cwin_puts(cwin_prompt_string);
    if (spool_file != NULL) fprintf(spool_file, "%s", cwin_prompt_string);
    cwin_putchar(CH_ENDPROMPT);
    if (hasFinished) return EOF;
    inputLineStart = textLast;          // just beyond the prompt
// Next I move characters across from the type-ahead buffer into the main
// text buffer, echoing them as I go (and handling DELETE chars too). I
// stop when I find a newline.
    for (;;)
    {   cwin_ensure_screen(FALSE);
        if (typeAheadP1 == typeAheadP2 &&
            clipboardInput == NULL) return EOF;
        if (clipboardInput != NULL)
        {   ch = *clipboardInputP++;
            while ((ch&0xff) == CH_PROMPT)
            {   while ((ch = *clipboardInputP++) != 0 &&
                       (ch&0xff) != CH_ENDPROMPT);
                if (ch == 0) break;
                ch = *clipboardInputP++;
            }
            if (ch == '\r') continue;
            if (ch == 0)
            {   free(clipboardInput);
                clipboardInput = NULL;
                continue;
            }
        }
        else
        {   ch = typeAheadBuffer[typeAheadP1];
            typeAheadP1 = (typeAheadP1 + 1) & typeAheadBufferMask;
        }
        if (ch == 0x7f) cwin_unputchar();
        else cwin_putchar(ch);
        if (ch == '\n' || hasFinished) break;
    }
    if (hasFinished) return EOF;
// By the time I exit the above loop there must be at least one character
// in the line that has just been read, even if it is only the terminating
// '\n'.
    inputP = 0;
    BOOL inPrompt = FALSE;
    for (;;)
    {   ch = textBuffer[inputLineStart];
        inputLineStart = (inputLineStart+1)&TEXT_MASK;
// Here I quietly truncate very very long input lines. For my first attempt
// I have inputBufferSize set at 2048.
        if ((ch&0xff) == CH_PROMPT) inPrompt = TRUE;
        if (inputP<inputBufferSize && !inPrompt) inputBuffer[inputP++] = ch;
        if ((ch&0xff) == CH_ENDPROMPT) inPrompt = FALSE;
        else if (ch == '\n') break;
    }
    inputBuffer[inputBufferSize-1] = '\n';
    inputP = 0;
    ch = inputBuffer[inputP++];
    if (ch == '\n') inputP = -1; // This buffer now all used up.
    return ch;
}

int cwin_getchar_nowait()
{
    return theApp.mainWindow->cwin_getchar_nowait();
}

void CMainWindow::cwin_discard_input()
{
    typeAheadP1 = typeAheadP2 = 0;
    if (clipboardInput) free(clipboardInput);
    clipboardInput = 0;
}

void cwin_discard_input()
{
    theApp.mainWindow->cwin_discard_input();
}

void CMainWindow::cwin_set_prompt(const char *s)
{
    strncpy(cwin_prompt_string, s, 31);
    cwin_prompt_string[31] = 0;
}

void cwin_set_prompt(const char *s)
{
    theApp.mainWindow->cwin_set_prompt(s);
}


// The READ command on the menu will work by forcing the caret to the
// end of the input buffer and simulating some typed in text which
// contains a file-name.  I will make a start at pretending to make it
// configurable here.  But there seem to be LOTS of things that need to be
// changed to match the system that is using the window manager code...
// I hope that eventually I will provide configuration calls so that the
// grim detail here gets set from "user" code. The basic idea is that
// readFileCommand holds a string to be generated, with a marker (%) somewhere
// where the file-name should go.  I need options to control processing
// of the file-name to get around reader escape conventions etc. I also need
// to tell the file selection dialog what sorts of files to look for...

#define VERBATIM_FILENAME    0
#define DOUBLE_BACKSLASH     1
#define DOUBLE_DOUBLEQUOTE   2

#ifdef COMMON
static char *readFileCommand  = "(load \"%\")";
static int fileOptions = DOUBLE_BACKSLASH;
static char *defaultExtension = "lsp";
static char *defaultFile      = "*.lsp";
static char *fileNameFilter   =
   "Lisp Files (*.lsp)|*.lsp|All Files (*.*)|*.*||\0";
#else
static char *readFileCommand  = "in \"%\";";
static int fileOptions = DOUBLE_DOUBLEQUOTE;
static char *defaultExtension = "red";
static char *defaultFile      = "*.RED;*.TST";
static char *fileNameFilter   =
   "Reduce (*.red/*.tst)|*.RED;*.TST|Lisp Files (*.lsp)|*.LSP|All Files (*.*)|*.*||\0";
#endif

void CMainWindow::OnRead()
{
    OnEnd();
    pageLine = caretLine;
    CFileDialog FDialog(TRUE, defaultExtension,
        defaultFile, OFN_FILEMUSTEXIST | OFN_HIDEREADONLY,
        fileNameFilter, NULL);
    FDialog.m_ofn.lpstrTitle = "Read File";
    if (FDialog.DoModal() != IDOK)
    {   cwin_ensure_screen(FALSE);  // needed to re-position caret, it seems.
        return;
    }
    CString p = FDialog.GetPathName();
    int nameLength = p.GetLength();
    char *q = readFileCommand;
    int i = strlen(q);
    while (i-- != 0)
    {   int ch = q[i];
        if (ch == '%')
        {   int j = nameLength;
            while (j-- != 0)
            {   int ch1 = p[j];
                switch (fileOptions)
                {
            case DOUBLE_BACKSLASH:
                    if (ch1 == '\\') UnTypeAhead(ch1);
                    break;
            case DOUBLE_DOUBLEQUOTE:
                    if (ch1 == '"') UnTypeAhead(ch1);
                    break;
            default:break;
                }
                UnTypeAhead(ch1);
            }
        }
        else UnTypeAhead(ch);
    }
    cwin_ensure_screen(FALSE);
}

#ifndef COMMON

static char **library_name_p = NULL;
static int library_name_n = 0;

static char *library_name[] =
{
    "algint",
    "applysym",
    "arnum",
    "assist",
    "avector",
    "boolean",
    "cali",
    "camal",
    "changevr",
    "compact",
    "complex",
    "crack",
    "cvit",
    "decompos",
    "defint",
    "desir",
    "dfpart",
    "dummy",
    "elem",
    "excalc",
    "fide",
    "fps",
    "gentran",
    "gnuplot",
    "groebner",
    "ideals",
    "ineq",
    "invbase",
    "laplace",
    "lie",
    "linalg",
    "modsr",
    "ncpoly",
    "normform",
    "numeric",
    "odesolve",
    "orthovec",
    "physop",
    "pmrules",
    "randpoly",
    "reacteqn",
    "residue",
    "rlfi",
    "rsolve",
    "scope",
    "sets",
    "spde",
    "specfn",
    "symmetry",
    "taylor",
    "tps",
    "tri",
    "trigsimp",
    "wu",
    "xcolor",
    "xideal",
    "zeilberg",
    "ztrans"
};

void CMainWindow::OnLoadLibrary(UINT a)
{
    OnEnd();
    pageLine = caretLine;
    char q[100];
    int i;
    if (library_name_p != NULL)
    {   if (a-IDM_FIRSTLOAD >= library_name_n) return;
        sprintf(q, "load_package %s;\n", 
                   library_name_p[a - IDM_FIRSTLOAD]);
    }
    else
    {   sprintf(q, "load_package %s;\n", library_name[a - IDM_FIRSTLOAD]);
    }
    i = strlen(q);
    while (i-- != 0)
    {   int ch = q[i];
        UnTypeAhead(ch);
    }
    cwin_ensure_screen(FALSE);
}

static char **switch_name_p = NULL;
static int switch_name_n = 0;

static struct { char *name; int status; } switch_name[] =
{
    {"algint",             0},
    {"adjprec",            0},
    {"allbranch",          0},
    {"allfac",             1},
    {"arbvars",            0},
    {"asterisk",           1},
    {"backtrace",          0},
    {"balanced_mod",       0},
    {"bfspace",            0},
    {"combineexpt",        0},
    {"combinelogs",        0},
    {"comp",               0},
    {"complex",            0},
    {"compxroots",         0},
    {"cramer",             0},
    {"cref",               0},
    {"defn",               0},
    {"demo",               0},
    {"dfprint",            0},
    {"div",                0},
    {"echo",               0},
    {"errcont",            0},
    {"evallhseqp",         0},
    {"exp",                1},
    {"expandexpt",         1},
    {"expandlogs",         0},
    {"ezgcd",              0},
    {"factor",             0},
    {"fastfor",            0},
    {"force",              0},
    {"fort",               0},
    {"fortupper",          0},
    {"fullprec",           0},
    {"fullprecision",      0},
    {"fullroots",          0},
    {"gc",                 0},
    {"gcd",                0},
    {"heugcd",             0},
    {"horner",             0},
    {"ifactor",            0},
    {"int",                0},
    {"intstr",             0},
    {"lcm",                1},
    {"lessspace",          0},
    {"limitedfactors",     0},
    {"list",               0},
    {"listargs",           0},
    {"lower",              1},
    {"mcd",                1},
    {"modular",            0},
    {"msg",                1},
    {"multiplicities",     0},
    {"nat",                1},
    {"nero",               0},
    {"noarg",              1},
    {"noconvert",          0},
    {"nonlnr",             0},
    {"nosplit",            1},
    {"numval",             1},
    {"output",             1},
    {"period",             1},
    {"pgwd",               0},
    {"plap",               0},
    {"precise",            1},
    {"pret",               0},
    {"pri",                1},
    {"pwrds",              1},
    {"quotenewnam",        1},
    {"raise",              0},
    {"rat",                0},
    {"ratarg",             0},
    {"rational",           0},
    {"rationalize",        0},
    {"ratpri",             1},
    {"reduced",            0},
    {"revpri",             0},
    {"rlisp88",            0},
    {"rootmsg",            0},
    {"roundall",           1},
    {"roundbf",            0},
    {"rounded",            0},
    {"savestructr",        0},
    {"solvesingular",      0},
    {"time",               0},
    {"trallfac",           0},
    {"trfac",              0},
    {"trint",              0},
    {"trroot",             0}
};

void CMainWindow::OnSwitch(UINT a)
{
    OnEnd();
    pageLine = caretLine;
    char q[100];
    int i;
    if (switch_name_p != NULL)
    {   int n = a - IDS_FIRSTSWITCH;
        if (n >= switch_name_n) return;
        i = switch_name_p[n][0] == 'y';
        switch_name_p[n][0] ^= ('y' ^ 'n');
// Note well - if the user types "on xxx" or "off xxx" directly rather than
// by using this mechanism then the checked or otherwise status of the menu
// items will get out of step. Tough luck. If you use the menu to set or clear
// a switch the switch will certainly be brought into line with what the
// menu information indicates.
        GetMenu()->CheckMenuItem(a, MF_BYCOMMAND |
                                    (i ? MF_UNCHECKED : MF_CHECKED));
        DrawMenuBar();
        sprintf(q, "%s %s;\n",
                i ? "off" : "on",
                1+switch_name_p[n]);
    }
    else
    {   i = switch_name[a - IDS_FIRSTSWITCH].status;
        switch_name[a - IDS_FIRSTSWITCH].status = !i;
// Note well - if the user types "on xxx" or "off xxx" directly rather than
// by using this mechanism then the checked or otherwise status of the menu
// items will get out of step. Tough luck. If you use the menu to set or clear
// a switch the switch will certainly be brought into line with what the
// menu information indicates.
        GetMenu()->CheckMenuItem(a, MF_BYCOMMAND |
                                    (i ? MF_UNCHECKED : MF_CHECKED));
        DrawMenuBar();
        sprintf(q, "%s %s;\n",
                i ? "off" : "on",
                switch_name[a - IDS_FIRSTSWITCH].name);
    }
    i = strlen(q);
    while (i-- != 0)
    {   int ch = q[i];
        UnTypeAhead(ch);
    }
    cwin_ensure_screen(FALSE);
}

#endif

void CMainWindow::OnExit()
{
    pageLine = caretLine;
    DestroyWindow();
}

int cwin_interrupt_pending = 0;

void CMainWindow::OnInterrupt()
{
    pageLine = caretLine;
    cwin_interrupt_pending = 1;
    cwin_ensure_screen(FALSE);
}

void CMainWindow::OnBacktrace()
{
    pageLine = caretLine;
    cwin_interrupt_pending = 3;
    cwin_ensure_screen(FALSE);
}

void CMainWindow::OnPageMode()
{
    pageLine = caretLine;
    pageMode = !pageMode;
    GetMenu()->CheckMenuItem(IDM_PAGEMODE,
        MF_BYCOMMAND | (pageMode ? MF_CHECKED : MF_UNCHECKED));
    DrawMenuBar();
    cwin_ensure_screen(FALSE);
}

#ifdef GRAPHICS_WINDOW
void CMainWindow::OnGraphics()
{
    graphicsWindow->ShowWindow(graphicsShown ? SW_HIDE : SW_SHOW);
    if (graphicsShown) graphicsWindow->viewpointWindow.ShowWindow(SW_HIDE);
    graphicsShown = !graphicsShown;
    if (graphicsShown) graphicsWindow->Invalidate();
    GetMenu()->CheckMenuItem(IDM_GRAPHICS,
        MF_BYCOMMAND | (graphicsShown ? MF_CHECKED : MF_UNCHECKED));
    DrawMenuBar();
    cwin_ensure_screen(FALSE);
}

void CMainWindow::OnGraphics1(UINT a, LONG b)
{
    OnGraphics();
}
#endif

void CMainWindow::ReWriteTitleText()
{
    if (hasFinished) return;
    CWindowDC dc(this);
// It is not (at present) clear to me how to decide how wide to make
// the title.  What follows is some sort of a guess.
    CRect clientArea;
    GetClientRect(&clientArea);
    int wTitle = clientArea.Width() -
                 3*::GetSystemMetrics(SM_CXVSCROLL);
    int wLeft  = dc.GetTextExtent(cLeft, strlen(cLeft)).cx;
    int wMid   = dc.GetTextExtent(cMid, strlen(cMid)).cx;
    int wRight = dc.GetTextExtent(cRight, strlen(cRight)).cx;
// For the calculations about padding that I use here to work the font used
// in the title bar had better not do any kerning and overhang-effects must
// not interfere.  I find I have all sorts of horrid problems if I try to
// use regular blank characters for padding, but '\xa0' displays as blank
// space and is better behaved.  It also seems (???) that at least under
// Windows 3.1 there is no great joy in trying to use caption strings that
// are longer than 78 characters...
#define PADDING_CHAR   '\xa0'
    char strSp[4]; strSp[0] = PADDING_CHAR;
    int wSp    = dc.GetTextExtent(strSp, 1).cx;
    int cw = wTitle / wSp;
// I first measure things on the supposition that I would allow up to
// 90 characters in the title.  After balancing it a bit I cut that
// down to the 78 that Windows 3.1 seems to be prepared to tolerate.
    if (cw > 90) wTitle = 90*wSp;
    int pad = (wTitle - wMid)/2;
    char *l = cLeft, *r = cRight;
    for (;;)
    {   int padLeft  = (pad - wLeft) / wSp;
        int padRight = (pad - wRight) / wSp;
        int excess = strlen(cLeft) + padLeft + strlen(cMid) +
                     padRight + strlen(cRight) - 78;
        if (excess > 0)
        {   if (excess & 1)
            {   if (padLeft > padRight) padLeft--; else padRight--;
                excess--;
            }
            excess /= 2;
            padLeft -= excess;
            padRight -= excess;
        }
#ifdef DISCARD_LEFT_IF_TITLE_OVERFULL
        if (padLeft <= 0 && padRight <= 0)
        {   strcpy(mainTitle, cMid);    // Abandon both right & left items
            break;
        }
#else
// Here even though there is no room to display the whole text I wanted
// on the title bar (maybe the window had been iconized?) I will display
// the left & mid parts with a single blank between.
        if (padLeft <= 0 && padRight <= 0)
        {   sprintf(mainTitle, "%s%c%s", cLeft, PADDING_CHAR, cMid);
            break;
        }
#endif
        else
        {
#ifdef DISCARD_LEFT_IF_TITLE_OVERFULL
            if (padLeft <= 0 && wLeft != 0)
            {   l = "";                       // Abandon left item & re-try
                wLeft = 0;
                continue;
            }
#endif
            if (padRight <= 0 && wRight != 0) // Abandon right item & re-try
            {   r = "";
                wRight = 0;
                continue;
            }
            char *p = mainTitle;
            while (*l != 0) *p++ = *l++;
            for (int i=0; i<padLeft; i++) *p++ = PADDING_CHAR;
            l = cMid;
            while (*l != 0) *p++ = *l++;
            for (i=0; i<padRight; i++) *p++ = PADDING_CHAR;
            while (*r != 0) *p++ = *r++;
            *p = 0;
            break;
        }
    }
    SetWindowText(mainTitle);
}

void CMainWindow::cwin_report_left(const char *msg)
{
// I will take this opportunity to make the "To-File" menu item track
// whether there really is a spool file active. This only effects how
// the menu gets displayed, not what it does...
    if (complete)
    {   GetMenu()->ModifyMenu(IDM_TOFILE+MF_STRING, MF_BYCOMMAND, IDM_TOFILE,
                              spool_file==NULL ? "&To File ..." :
                              "&Terminate log");
        DrawMenuBar();
    }
    if (msg == NULL)
    {   leftSetByUser = FALSE;
        return;                         // Date and time of day will appear
    }
    strncpy(cLeft, msg, 31); cLeft[31] = 0;
    ReWriteTitleText();
    leftSetByUser = TRUE;
}

void cwin_report_left(const char *s)
{
    theApp.mainWindow->cwin_report_left(s);
}

void CMainWindow::cwin_report_mid(const char *msg)
{
    if (msg == NULL) msg = programName;
    strncpy(cMid, msg, 31); cLeft[31] = 0;
    ReWriteTitleText();
}

void cwin_report_mid(const char *s)
{
    theApp.mainWindow->cwin_report_mid(s);
}

void CMainWindow::cwin_report_right(const char *msg)
{
    if (msg == NULL) msg = "";
    strncpy(cRight, msg, 31); cRight[31] = 0;
    ReWriteTitleText();
}

void cwin_report_right(const char *s)
{
    theApp.mainWindow->cwin_report_right(s);
}

void CMainWindow::cwin_display_date()
{
    char dateBuffer[20];
    time_t t0 = time(NULL);
    char *m = ctime(&t0);
#ifdef OLD_AND_USES_UNIVERSAL_TIME_WHICH_IS_SILLY
    sprintf(dateBuffer, "%02d-%.3s-%02d, %02d:%02d:%02d",
       titleUpdateTime.wDay,
       "xxxJanFebMarAprMayJunJulAugSepOctNovDec"+3*titleUpdateTime.wMonth,
       titleUpdateTime.wYear%100,
       titleUpdateTime.wHour, titleUpdateTime.wMinute,
       titleUpdateTime.wSecond);
#else
    sprintf(dateBuffer, "%.2s-%.3s-%.2s, %.8s",
                        m+8, m+4, m+22, m+11);
#endif
    cwin_report_left(dateBuffer);
    leftSetByUser = FALSE;
}

void cwin_menus(char **packages, char **switches)
{
    theApp.mainWindow->cwin_menus(packages, switches);
}

void CMainWindow::cwin_menus(char **packages, char **switches)
{
    CMenu *main = GetMenu();  // main menu bar for this window
    if (packages != NULL && *packages != NULL)
    {   library_name_p = packages;
        main->DeleteMenu(4, MF_BYPOSITION);
        int n = IDM_FIRSTLOAD;
        CMenu mload;
        mload.CreatePopupMenu();
        int firstletter = 'a';
        int lastletter = 'a', nextletter;
        int count = 0, nextcount;
        char **p = packages;
        library_name_n = 0;
        while (*p++ != NULL) library_name_n++;
        p = packages;
        while (*p && **p == lastletter) count++, p++;
        char **p1 = p;
        while (*packages)
        {   for (;;)
            {   nextcount = 0;
                nextletter = lastletter + 1;
                while (*p && **p == nextletter) nextcount++, p++;
                if (count + nextcount > 20) break;
                lastletter = nextletter;
                count += nextcount;
                p1 = p;
                if (lastletter == 'z') break;
            }
            char subname[8];
            if (firstletter == lastletter) sprintf(subname, "%c", firstletter);
            else sprintf(subname, "%c-%c", firstletter, lastletter);
            CMenu sub1;
            sub1.CreatePopupMenu();
            while (packages != p1)
                sub1.AppendMenu(MF_STRING, n++, *packages++);
            mload.AppendMenu(MF_STRING | MF_POPUP, (UINT)sub1.Detach(), subname);
            firstletter = lastletter = nextletter;
            count = nextcount;
            p1 = p;
        }
        main->InsertMenu(4, MF_BYPOSITION | MF_POPUP | MF_STRING, 
                         (UINT)mload.Detach(), "&Load");
    }
// Now do roughly the same with switches
    if (switches != NULL && *switches != NULL)
    {   switch_name_p = switches;
        main->DeleteMenu(5, MF_BYPOSITION);
        int n = IDS_FIRSTSWITCH;
        CMenu mload;
        mload.CreatePopupMenu();
        int firstletter = 'a';
        int lastletter = 'a', nextletter;
        int count = 0, nextcount;
        char **p = switches;
        switch_name_n = 0;
        while (*p++ != NULL) switch_name_n++;
        p = switches;
        while (*p && (*p)[1] == lastletter) count++, p++;
        char **p1 = p;
        while (*switches)
        {   for (;;)
            {   nextcount = 0;
                nextletter = lastletter + 1;
                while (*p && (*p)[1] == nextletter) nextcount++, p++;
                if (count + nextcount > 20) break;
                lastletter = nextletter;
                count += nextcount;
                p1 = p;
                if (lastletter == 'z') break;
            }
            char subname[8];
            if (firstletter == lastletter) sprintf(subname, "%c", firstletter);
            else sprintf(subname, "%c-%c", firstletter, lastletter);
            CMenu sub1;
            sub1.CreatePopupMenu();
            while (switches != p1)
            {   sub1.AppendMenu(MF_STRING, n, 1+*switches);
                sub1.CheckMenuItem(n, MF_BYCOMMAND |
                   (**switches=='y' ? MF_CHECKED : MF_UNCHECKED));
                n++;
                switches++;
            }
            mload.AppendMenu(MF_STRING | MF_POPUP, (UINT)sub1.Detach(), subname);
            firstletter = lastletter = nextletter;
            count = nextcount;
            p1 = p;
        }
        main->InsertMenu(5, MF_BYPOSITION | MF_POPUP | MF_STRING, 
                         (UINT)mload.Detach(), "&Switch");
    }
 
    DrawMenuBar();
}

// When the user types in a key all that happens (to start with) is that
// I store it in a buffer.  If the buffer gets to be full I beep and
// ignore any further characters.

#define Ctrl(x) ((x) & 0x1f)

void CMainWindow::OnChar(UINT ch, UINT nRepCnt, UINT nFlags)
{
// I turn the ENTER key into a newline character (and consequently ^M will
// also go that way). I also discard 0x7f (for the delete/erase key) and
// anything in the range 0x80 to 0xa0 (which I reserve for my own private
// use in the text buffer).  I ignore the repetition count.
// I also have to process some accelerators.
    pageLine = caretLine;
// The following line is in effect following a request from F J Wright. He
// pointed out that the character that gets pressed when one is in page mode
// to un-pause the screen should be allowed to do just that and should not
// also appear as an input character. So here if I find a character being
// typed when things are paused I just lose it (as well as clearing the
// flags that pause things.
    if (pagePaused) 
    {   pagePaused = FALSE;
        return;
    }
    inject_randomness(ch);
    inject_randomness((int)time(NULL));
    switch (ch)
    {
case Ctrl('C'):
        ToIcaret();
        caretVisible = TRUE;
        cwin_ensure_screen(FALSE);  // may jump screen to caret location
        OnInterrupt();
        return;
// I make Ctrl+D and Ctrl+Z exit, but note very well that they both
// exit from this system super-promptly when the key is typed, and
// they do NOT wait until the program gets around to reading them.
case Ctrl('D'):          // Some Unix users may be used to Ctrl+D as EOF?
        OnExit();
        return;
case Ctrl('G'):
        ToIcaret();
        caretVisible = TRUE;
        cwin_ensure_screen(FALSE);  // may jump screen to caret location
        OnBacktrace();
        return;
case Ctrl('I'):          // TAB  (I need to worry about the display of tabs!)
        break;
case Ctrl('J'):          // LINEFEED
        ch = '\n';
        break;
case Ctrl('L'):
        OnRedraw();
        return;
case Ctrl('M'):          // CARRIAGE RETURN
        ch = '\n';
case Ctrl('N'):
        OnEnd();         // so that CR accepts the line always
        break;
case Ctrl('O'):
        OnCopy();
        return;
case Ctrl('Q'):
        if (pageMode) OnPageMode();
        return;
case Ctrl('R'):
        OnReInput();
        return;
case Ctrl('S'):
        if (!pageMode) OnPageMode();
        return;
case Ctrl('V'):
        OnPaste();
        return;
case Ctrl('X'):
        OnCut();
        return;
case Ctrl('Z'):         // Some PC users may be used to Ctrl+Z as EOF?
        OnExit();
        return;
case 0x1b:              // ESC goes through to the user
        break;
default:
        if ((ch & 0x7f) < 0x20) return;  // Discard control chars.
        break;
    }
    CancelSelection();
    ToIcaret();
    caretVisible = TRUE;
    cwin_ensure_screen(FALSE);
// If the caret is NOT at the end of the text then the insert operation I do
// here goes directly into the text buffer. If the caret IS at the end of the
// text I push the character into a type-ahead buffer, and beep if there
// was no room for it there.
    if (caretChar != textLast)
    {   if (insertMode) cwin_caret_putchar(ch);
        else cwin_caret_replacechar(ch);
    }
    else
    {   int p2 = (typeAheadP2 + 1) & typeAheadBufferMask;
        if (p2 == typeAheadP1)
        {   ::MessageBeep(0xffffffff);
            return;
        }
        typeAheadBuffer[typeAheadP2] = ch;
        typeAheadP2 = p2;
    }
}

void CMainWindow::ReplaceLastLine(unsigned char *s)
{
    typeAheadP1 = typeAheadP2 = 0;  // cancel type-ahead
    selRootValid = FALSE;
    OnEnd();
    caretVisible = TRUE;
// The following loop deletes characters from the last line of the input,
// until what is left is (a) a totally empty buffer, (b) a buffer where the
// last line is empty or (c) the final thing in the buffer is a prompt
// item. While doing the deletion I will not update the screen at all.
    while (textFirst != textLast &&
           lineBuffer[lineLast].address != textLast)
    {   int n = (textLast-1) & TEXT_MASK;
        if ((textBuffer[n]&0xff)==CH_ENDPROMPT) break;
        if (textLast == caretChar) caretChar = n;
        if (textLast == icaretChar) icaretChar = n;
        if (textLast == inputLineStart) inputLineStart = n;
        textLast = n;
    }
    int i=savedLines[currentInputLine];
    for (;;)
    {   int ch = savedChars[i++];
        if (ch == '\n') break;
        if (i == MAX_SAVED_CHARS) i = 0;
        cwin_putchar(ch);
    }
    CRect cr(0, LineY(lineLast),
             clientWidth, LineY(lineLast)+LineDY(lineLast));
    InvalidateRect(&cr);
    LineSizes();
    UpdateWindow();
    cwin_ensure_screen(FALSE);
}

void CMainWindow::OnKeyDown(UINT ch, UINT nRepCnt, UINT nFlags)
{
    CPoint cp;
    int saveX, saveY;
    pageLine = caretLine;
    switch (ch)
    {
// The INS key flips the status with respect to insert mode. I make this
// TRUE at the start of a run, and any time anybody does a PASTE operation.
case VK_INSERT:
        insertMode = !insertMode;
        return;

// I make the DEL key delete forwards by first simulating a right-arrow
// cursor movement effect and then performing the sort of deletion that
// I consider ordinary.
case VK_DELETE:
        ToIcaret();
        caretVisible = TRUE;
        cwin_ensure_screen(FALSE);
        if (selStartChar != selEndChar)
        {   DeleteSelection();
            return;
        }
        if (caretChar == textLast) return;
        OnKeyDown(VK_RIGHT, 1, nFlags);
        if (caretChar != textLast)
        {   cwin_caret_unputchar();
            return;
        }
        if (typeAheadP1 == typeAheadP2)
        {   typeAheadBuffer[typeAheadP2] = 0x7f;
            typeAheadP2 = (typeAheadP2 + 1) & typeAheadBufferMask;
            return;
        }
        typeAheadP2 = (typeAheadP2 - 1) & typeAheadBufferMask;
        return;

case VK_BACK:
        ToIcaret();
        caretVisible = TRUE;
        cwin_ensure_screen(FALSE);  // may jump screen to caret location
// If there is a selection valid then DELETE will delete it, without any
// regard for where the caret is (although the caret will generally be
// at one or other end of the selected region).
        if (selStartChar != selEndChar)
        {   DeleteSelection();
            return;
        }
// If the caret is NOT at the end of the text then DELETE has to work
// inside the buffer. This will typically make it a fairly expensive
// operation.
        if (caretChar != textLast)
        {   cwin_caret_unputchar();
            return;
        }
// If there are no characters typed ahead I will put 0x7f into the
// input buffer. This case can arise in two different circumstances. The
// first is if a user types DELETE as the first character on a line. Then
// I will want to discard the junk characters later on. Otherwise it may be
// that the current line is partly displayed and is subject to interactive
// editing and then the 0x7f put in the buffer will be found again very
// soon and used to cause deletion of some prior character.  Because of this
// latter case I will not beep on initial DELETE characters on a line.
        if (typeAheadP1 == typeAheadP2)
        {   typeAheadBuffer[typeAheadP2] = 0x7f;
            typeAheadP2 = (typeAheadP2 + 1) & typeAheadBufferMask;
            return;
        }
// If there are typed-ahead characters I can just discard the most recent. At
// this stage the character has not been displayed (eg a user typed XXX DEL
// before the application was ready to look at it) so the removal is really
// very easy.
        typeAheadP2 = (typeAheadP2 - 1) & typeAheadBufferMask;
        return;
// The various keys like "PAGE UP" etc do just what the scroll bar can do.
case VK_PRIOR:
        OnVScroll(SB_PAGEUP, 0, NULL);
        return;
case VK_NEXT:
        OnVScroll(SB_PAGEDOWN, 0, NULL);
        return;
case VK_HOME:
        OnHome();
        return;
case VK_END:
        OnEnd();
        return;
// The cursor arrow keys are funny here, with behaviour inspired by the
// DOSKEY history program.  Right and left movement moves the caret, but
// up and down will bring back one of a number of stored input line.
case VK_UP:
// If my caret is on the last line I will do something DOSKEY-ish...
        if (caretLine == lineLast)
        {   if (currentInputLine == savedP1) return;
            if (currentInputLine == -1) currentInputLine = savedP2;
            if (currentInputLine == 0) currentInputLine = MAX_SAVED_LINES;
            currentInputLine--;
            ReplaceLastLine(&savedChars[savedLines[currentInputLine]]);
            return;
        }
        if (caretLine == lineFirst) return;
        if (caretLine == lineVisible) OnVScroll(SB_LINEUP, 0, NULL);
        cp.x = caretX-xOffset;
        cp.y = caretY - 1;
        FindMouseChar(cp);
        caretVisible = TRUE;
        cwin_ensure_screen(FALSE);
        return;
case VK_DOWN:
// If my caret is on the last line I will do something DOSKEY-ish...
        if (caretLine == lineLast)
        {   int n = currentInputLine + 1;
            if (n == MAX_SAVED_LINES) n = 0;
            if (currentInputLine == -1 || n == savedP2) return;
            currentInputLine = n;
            ReplaceLastLine(&savedChars[savedLines[currentInputLine]]);
            return;
        }
        cp.x = caretX-xOffset;
        saveY = caretY, saveX = caretX;
        cp.y = caretY + LineDY(caretLine) + 1;
// The case when I am at the bottom of the screen and hit the "DOWN" key
// is a bit of a mess. I call FindMouse Char as usual to try to re-position
// the caret. If that would be outside the window I get a flag set to tell me
// so. In that case I re-position the caret where it just came from, then
// scroll the window, and finally repeat my attempt to re-position the
// caret.
        FindMouseChar(cp);
        if (mouseOutside & 8)
        {   cp.x = saveX-xOffset;
            cp.y = saveY + 1;
            FindMouseChar(cp);
            OnVScroll(SB_LINEDOWN, 0, NULL);
            cp.x = caretX-xOffset;
            cp.y = caretY + LineDY(caretLine) + 1;
            FindMouseChar(cp);
        }
        caretVisible = TRUE;
        cwin_ensure_screen(FALSE);
        return;
case VK_LEFT:
        caretVisible = TRUE;
        if (textFirst == caretChar) return;             // at start of buffer?
        if (lineBuffer[caretLine].address == caretChar) // back over a newline?
        {   int n = (caretLine-1)&LINE_MASK;
            caretX = lineBuffer[n].width;
            caretLine=n;
            n = lineBuffer[n].address;
            while (textBuffer[n]!='\n') n = (n+1)&TEXT_MASK;
            caretChar = n;
        }
        else
        {   int n = (caretChar-1) & TEXT_MASK;
            int w = windowFonts.HCourier.across['X'];
            if ((textBuffer[n]&0xff)==CH_ENDPROMPT)   // move over whole of a prompt
            {   do
                {   n = (n-1)&TEXT_MASK;
                    caretX -= w;
                } while (n!=textFirst && (textBuffer[n]&0xff)!=CH_PROMPT);
                caretChar = n;
                if (lineBuffer[caretLine].address == caretChar) // back over a newline?
                {   n = (caretLine-1)&LINE_MASK;
                    caretX = lineBuffer[n].width;
                    caretLine=n;
                    n = lineBuffer[n].address;
                    while (textBuffer[n]!='\n') n = (n+1)&TEXT_MASK;
                    caretChar = n;
                }
            }
            else caretX -= w;
            if (caretLine == lineLast) icaretChar = n, icaretLine = lineLast;
            caretChar = n;
// The amount of invalidation done here runs across to the end of the
// last line, and that ought to get rid of any residues of the old
// caret. I use an APPROXIMATION to the new value of caretX, but hope that
// that gets corrected during the re-painting.
            CRect cr(caretX-xOffset, LineY(caretLine),
                     clientWidth, LineY(caretLine)+LineDY(caretLine));
            InvalidateRect(&cr);  // Should I hide the caret here?
        }
        UpdateWindow();
        cwin_ensure_screen(FALSE);
        return;
case VK_RIGHT:
        caretVisible = TRUE;
        if (textLast == caretChar) return;              // at end of buffer?
        if (textBuffer[caretChar] == '\n')              // at a newline?
        {   caretX = 0;
            int w = windowFonts.HCourier.across['X'];
            caretLine = (caretLine+1)&LINE_MASK;
            caretChar = lineBuffer[caretLine].address;
            if (caretChar!=textLast &&
                (textBuffer[caretChar]&0xff)==CH_PROMPT)   // move over whole of a prompt
            {   while (caretChar!=textLast && 
                       (textBuffer[caretChar]&0xff)!=CH_ENDPROMPT)
                {   caretChar = (caretChar+1)&TEXT_MASK;
                    caretX += w;
                }
                caretX -= w;
                if (caretChar!=textLast) caretChar = (caretChar+1)&TEXT_MASK;
            }
            CPoint caretPos(caretX-xOffset, caretY);
            SetCaretPos(caretPos);
            if (caretLine == lineLast)
            {   icaretLine = caretLine;
                icaretChar = caretChar;
                icaretX = caretX;
            }
        }
        else
        {   int n = caretChar;
            int oldCaretX = caretX;
            int w = windowFonts.HCourier.across['X'];
            n = (n+1)&TEXT_MASK;
            caretX += w;
            if (caretLine == lineLast) icaretChar = n, icaretLine = caretLine;
            caretChar = n;
            CRect cr(oldCaretX-xOffset, LineY(caretLine),
                     caretX-xOffset+w, LineY(caretLine)+LineDY(caretLine));
            InvalidateRect(&cr);  // Should I hide the caret here?
        }
        UpdateWindow();
        cwin_ensure_screen(FALSE);
        return;
    }
}


// The next function takes a mouse position and identifies the character in
// the text buffer that it identifies.  It must be kept well in step with
// the corresponding code in PaintTextLine().

int CMainWindow::FindMouseChar(CPoint point)
{
// I may have captured the mouse, in which case the coordinates returned may
// be outside my client area. Clip them to it before doing anything else.
    int x = point.x, y = point.y;
    int nCount = 0;
    mouseOutside = 0;
    if (x<0) x=0, mouseOutside |= 1;
    else if (x>clientWidth) x=clientWidth, mouseOutside |= 2;
    if (y<0) y=0, x=0, mouseOutside |= 4;
    else if (y>clientHeight) y=clientHeight, x=clientWidth, mouseOutside |= 8;
    if (mouseOutside == 0) selectScrollSpeed = 0;
    int yOffset = lineBuffer[lineVisible].position;
    int line;
    for (line=lineVisible;;line=(line+1)&LINE_MASK)
    {   int y1 = lineBuffer[line].position - yOffset;
        int y2 = y1 + lineBuffer[line].height;
        if (y>=y1 && y<=y2) break;
        if (line==lineLast) break;
    }
// Now I have identified the line that the mouse cursor is on.
    int textChar = lineBuffer[line].address;
    int activeFont = CH_COURIER;
    unsigned char *activeWidths = windowFonts.HCourier.across;
    int xc = -xOffset;
    int inPrompt = -1, inPromptX;
    for (;;textChar=(textChar+1)&TEXT_MASK)
    {   if (textChar==textLast) break;
        int c = textBuffer[textChar];
        int w = activeWidths[c & 0xff];
        switch (c & 0xff)
        {
    case '\n':
            break;
    case CH_PROMPT:
            inPrompt = textChar, inPromptX = xc;
            continue;
    case CH_ENDPROMPT:
            inPrompt = -1;
            continue;
    case CH_RED:
//    case CH_BLUE:
//    case CH_BLACK:
    case CH_GRAY:
            continue;
    case CH_COURIER:
            activeFont = c;
            activeWidths = windowFonts.HCourier.across;
            continue;
    case CH_ROMAN:
            activeFont = c;
            activeWidths = windowFonts.HRoman.across;
            continue;
    case CH_BOLD:
            activeFont = c;
            activeWidths = windowFonts.HBold.across;
            continue;
    case CH_ITALIC:
            activeFont = c;
            activeWidths = windowFonts.HItalic.across;
            continue;
    case CH_SYMBOL:
            activeFont = c;
            activeWidths = windowFonts.HSymbol.across;
            continue;
    case CH_Roman:
            activeFont = c;
            activeWidths = windowFonts.Hroman.across;
            continue;
    case CH_Bold:
            activeFont = c;
            activeWidths = windowFonts.Hbold.across;
            continue;
    case CH_Italic:
            activeFont = c;
            activeWidths = windowFonts.Hitalic.across;
            continue;
    case CH_Symbol:
            activeFont = c;
            activeWidths = windowFonts.Hsymbol.across;
            continue;
    default:
            if (c == '\t')
            {   c = ' ';
                w = currentWidths[' ']*(8-(nCount&7));
                nCount = 7;
            }
            else if (c < 32) w = activeWidths['^'] + activeWidths[c & 0xff],
                             nCount++;
            if (x <= xc+w/2)
            {
// I will not allow the user to select a position within a prompt, since
// if I did it would make it possible to CUT or DELete part of the prompt
// string, including either the control character that marked its start or
// its end. The result would be that the status of the text as "prompt" would
// be lost with possible consequent confusion.
                if (inPrompt>=0) textChar=inPrompt, xc=inPromptX;
                break;   // Bingo! Found it.
            }
            xc += w;
            nCount++;
            continue;
        }
        break;
    }
// If the mouse click moves me to the last line then I place the
// input caret there. Otherwise if a previous caret had been on the last line
// I leave the input caret where the previous caret had been.
    if (line == lineLast)
    {   icaretChar = textChar;
        icaretX = xc+xOffset;
        icaretFontWidths = activeWidths;
        icaretLine = line;
    }
    else if (caretLine == lineLast)
    {   icaretChar = caretChar;
        icaretX = caretX;
        icaretFontWidths = caretFontWidths;
        icaretLine = caretLine;
    }
    caretChar = textChar;
    caretX = xc+xOffset;
    caretFontWidths = activeWidths;
    caretLine = line;
    inject_randomness(caretX);
    inject_randomness(caretLine);
// In the case that mouse activity re-positions the caret I will move the
// caret on the screen directly to where it needs to be shown. No benefit
// would come from delaying until a future re-paint operation.
    HideCaret();
    CPoint caretPos(caretX-xOffset, caretY);
    SetCaretPos(caretPos);
    ShowCaret();
    return caretChar;
}

// StartSelection is slightly curious in that it sets the selection
// to be empty but rooted at a specific point. The effect will be that
// a subsequent MouseMove or shift-click can extend the selection to
// be non-trivial.  The ugly feature of this is that a selection that has
// been "started" in this way could suffer if the contents of the text buffer
// moved. To prevent trouble I will keep a flag that indicates when I have
// a selection starting-point that I will count as valid. I will set this
// flag here and clear it anywhere where I move or destroy bits of the
// buffer.

void CMainWindow::StartSelection()
{
    CancelSelection();
    selFirstChar = selStartChar = selEndChar = caretChar;
    selFirstX = selStartX = selEndX = caretX;
    selFirstLine = selStartLine = selEndLine = caretLine;
    selRootValid = TRUE;
}

void CMainWindow::InvalidateSelection(int l1, int x1, int l2, int x2)
{
    int w;
    if (l1 > l2)
    {   w=l1, l1=l2, l2=w, w=x1, x1=x2, x2=w;
        if (x2 == 0) l2=(l2-1)&LINE_MASK, x2=clientWidth+xOffset;
    }
    HideCaret();
    if (l1==l2)
    {   if (x1>x2) w=x1, x1=x2, x2=w;
        CRect r(x1-xOffset, LineY(l1),
                x2+caretWidth-xOffset, LineY(l1)+LineDY(l1));
        if (x1 != x2) InvalidateRect(&r);
    }
    else
    {   CRect r(0, LineY(l1), clientWidth, LineY(l2)+LineDY(l2));
        InvalidateRect(&r);
    }
    ShowCaret();
}

void CMainWindow::ExtendSelection()
{
    int oldStart = selStartChar, oldEnd = selEndChar;
    if (selFirstChar == selStartChar)
        InvalidateSelection(selEndLine, selEndX, caretLine, caretX);
    else InvalidateSelection(selStartLine, selStartX, caretLine, caretX);
    if (betweenChar(textFirst, caretChar, selFirstChar))
    {   selStartChar = caretChar;     selStartX = caretX;  selStartLine = caretLine;
        selEndChar = selFirstChar; selEndX = selFirstX; selEndLine = selFirstLine;
    }
    else
    {   selStartChar = selFirstChar; selStartX = selFirstX; selStartLine = selFirstLine;
        selEndChar = caretChar;         selEndX = caretX;      selEndLine = caretLine;
    }
    if (selStartChar==oldStart && selEndChar==oldEnd) return;
}

void CMainWindow::CancelSelection()
{
    InvalidateSelection(selStartLine, selStartX, selEndLine, selEndX);
    selFirstChar = selStartChar = selEndChar = caretChar;
    selFirstX = selStartX = selEndX = caretX;
    selFirstLine = selStartLine = selEndLine = caretLine;
}

void CMainWindow::OnLButtonDblClk(UINT nFlags, CPoint point)
{
}


void CMainWindow::OnLButtonDown(UINT nFlags, CPoint point)
{
/*
 * The idea here is that a first click within a window should NOT move
 * the caret or start a new selection, since it was probably (?) the
 * mouse event that just caused the window to become active again.
 */
    if (pagePaused || hasFocus) return;
    FindMouseChar(point);
    trackingSelection = TRUE;
    SetCapture();
    selectScrollSpeed = 0;
    if (nFlags & MK_SHIFT && selRootValid) ExtendSelection();
    else StartSelection();
}


void CMainWindow::OnLButtonUp(UINT nFlags, CPoint point)
{
    if (hasFocus)
    {   hasFocus = FALSE;
        return;
    }
    if (pagePaused) pageLine = caretLine;
    else
    {   FindMouseChar(point);
        ::ReleaseCapture();
        if (trackingSelection) ExtendSelection();
        trackingSelection = FALSE;
        selectScrollSpeed = 0;
    }
}


void CMainWindow::OnMButtonDblClk(UINT nFlags, CPoint point)
{
}


void CMainWindow::OnMButtonDown(UINT nFlags, CPoint point)
{
}


void CMainWindow::OnMButtonUp(UINT nFlags, CPoint point)
{
    if (hasFocus)
    {   hasFocus = FALSE;
        return;
    }
    pageLine = caretLine;
}


void CMainWindow::OnRButtonDblClk(UINT nFlags, CPoint point)
{
}


void CMainWindow::OnRButtonDown(UINT nFlags, CPoint point)
{
}


void CMainWindow::OnRButtonUp(UINT nFlags, CPoint point)
{
    if (hasFocus)
    {   hasFocus = FALSE;
        return;
    }
    pageLine = caretLine;
}


void CMainWindow::OnMouseMove(UINT nFlags, CPoint point)
{
    inject_randomness((int)clock());
    if (trackingSelection && !pagePaused)
    {   FindMouseChar(point);
        if (mouseOutside != 0)
        {   if (selectScrollSpeed == 0)
                selectScrollSpeed = 7,
                selectScrollCount = 1;
            selectScrollDirection = mouseOutside;
            selectScrollPoint = point;
            OnTimer(1);
        }
        else ExtendSelection();
    }
}


void CMainWindow::OnTimer(UINT timerId)
{
    if (selectScrollSpeed == 0) return;
    selectScrollCount--;
    if (selectScrollCount > 0) return;
    if (selectScrollDirection == 0) return;
    if (selectScrollDirection & 8) OnVScroll(SB_LINEDOWN, 0, NULL);
    else if (selectScrollDirection & 4) OnVScroll(SB_LINEUP, 0, NULL);
    else if (selectScrollDirection & 1 && xOffset!=0)
        OnHScroll(SB_LINELEFT, 0, NULL);
    else if (selectScrollDirection & 2 &&
             caretX < lineBuffer[caretLine].width)
        OnHScroll(SB_LINERIGHT, 0, NULL);
    selectScrollCount = selectScrollSpeed;
    if (selectScrollSpeed > 1) selectScrollSpeed--;
    FindMouseChar(selectScrollPoint);
    ExtendSelection();
}

void CMainWindow::OnNcLButtonDown(UINT nFlags, CPoint point)
{
}


void CMainWindow::OnNcMButtonDown(UINT nFlags, CPoint point)
{
}


void CMainWindow::OnNcRButtonDown(UINT nFlags, CPoint point)
{
}



//
// Now the things provoked from the menus...
//

// SAVEAS will dump everything that is in the text buffer into a
// log file. The status of prompts and any other funny stuff will not
// concern me here - I will just dump out bytes as they appear in the
// text buffer. But at least I will arrange that I do not dump any characters
// that have a code >= 0x80 into the saved file.

void CMainWindow::OnSaveAs()
{
    CFileDialog FDialog(FALSE, "LOG", "savefile.log",
        OFN_HIDEREADONLY,
        "Log Files (*.LOG)|*.LOG|All Files (*.*)|*.*||", NULL);
    FDialog.m_ofn.lpstrTitle = "Save As";
    if (FDialog.DoModal() != IDOK) return;
    FILE *ofile = fopen(FDialog.GetPathName(), "w");
    if (ofile == NULL)
    {   DisplayMsg("Could not write to file");
        cwin_ensure_screen(FALSE);
        return;
    }
    for (int i=lineFirst; i!=lineLast; i=(i+1)&LINE_MASK)
    {   int p = lineBuffer[i].address, c;
        while ((c = textBuffer[p]) != '\n')
        {   if ((c & 0x80) == 0) putc(c, ofile);
            p = (p+1) & TEXT_MASK;
        }
        putc('\n', ofile);
    }
    int p = lineBuffer[lineLast].address;
    while (p != textLast)
    {   int c = textBuffer[p];
        if ((c & 0x80) == 0) putc(c, ofile);
        p = (p+1) & TEXT_MASK;
    }
    putc('\n', ofile);  // extra newline at end to be tidy.
    fclose(ofile);
    cwin_ensure_screen(FALSE);
}

void CMainWindow::OnSaveSel()
{
    CFileDialog FDialog(FALSE, "LOG", "savesel.log",
        OFN_HIDEREADONLY,
        "Log Files (*.LOG)|*.LOG|All Files (*.*)|*.*||", NULL);
    FDialog.m_ofn.lpstrTitle = "Save Selection";
    if (FDialog.DoModal() != IDOK) return;
    FILE *ofile = fopen(FDialog.GetPathName(), "w");
    if (ofile == NULL)
    {   DisplayMsg("Could not write to file");
        cwin_ensure_screen(FALSE);
        return;
    }
// print selected region...
    int l1 = selStartLine;
    int cp = selStartChar;
    for (;;)
    {   while (cp!=selEndChar && textBuffer[cp]!='\n')
        {   int c = textBuffer[cp];
            if ((c & 0x80) == 0) putc(c, ofile);
            cp = (cp+1)&TEXT_MASK;
        }
        if (cp==selEndChar) break;
        putc('\n', ofile);
        l1 = (l1+1)&LINE_MASK;
        cp = lineBuffer[l1].address;
    }
    fclose(ofile);
    cwin_ensure_screen(FALSE);
}

void CMainWindow::OnToFile()
{
// When I have a log file active I will make the menu entry into
// one that closes the transcript, while if I do not have a file in
// use the File/&T menu entry will start one off.
//
// NOTE that the "spool_file" mentioned here belongs somewhere in CSL,
// and is not in the "cwin" code in any more direct way.
    if (spool_file != NULL)
    {   fprintf(spool_file, "\n+++ End of transcript +++\n");
        fclose(spool_file);
        spool_file = NULL;
        GetMenu()->ModifyMenu(IDM_TOFILE+MF_STRING, MF_BYCOMMAND,
                              IDM_TOFILE, "&To File...");
        DrawMenuBar();
        cwin_ensure_screen(FALSE);
        return;
    }
    CFileDialog FDialog(FALSE, "LOG", "logfile.log",
        OFN_HIDEREADONLY,
        "Log Files (*.LOG)|*.LOG|All Files (*.*)|*.*||", NULL);
    FDialog.m_ofn.lpstrTitle = "Transcript File";
    if (FDialog.DoModal() != IDOK) return;
    FILE *ofile = fopen(FDialog.GetPathName(), "w");
    if (ofile == NULL)
    {   DisplayMsg("Could not write to file");
        cwin_ensure_screen(FALSE);
        return;
    }
    spool_file = ofile;
    time_t t0 = time(NULL);
    fprintf(spool_file, "+++ Transcript started at %.24s +++\n", ctime(&t0));
    GetMenu()->ModifyMenu(IDM_TOFILE+MF_STRING, MF_BYCOMMAND,
                          IDM_TOFILE, "&Terminate log");
    DrawMenuBar();
    cwin_ensure_screen(FALSE);
}

static CFont *MakeNewFont(CDC *dc, FontHeights *fh, DWORD charSet,
                          const char *fontName, int weight,
                          DWORD italic, int height)
{
    CFont *newFont = new CFont;
    newFont->CreateFont(
        height, 0,        // height, width
        0, 0,             // angle of escapement, base line orientation angle
        weight, italic,   // weight, italic-flag
        0, 0, charSet,    // underline, strike-out, character-set
        OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
        DEFAULT_QUALITY, DEFAULT_PITCH+FF_DONTCARE,
        fontName);
    dc->SelectObject(newFont);
    TEXTMETRIC mm;
    dc->GetTextMetrics(&mm);
    fh->up = mm.tmExternalLeading + mm.tmAscent;
    fh->down = mm.tmDescent;
    fh->height = mm.tmHeight;
    int widths[256], i;
    dc->GetCharWidth(0, 255, widths);
    for (i=0x80; i<0xa0; i++) widths[i] = 0; // my control characters
// The width of a character in any sensible sized font will be less than
// 256 pixels, so I save some space by stashing the information in a byte
// array rather than a word array.  If I really knew I was only ever going to
// use TrueType fonts maybe I ought to use ABCWidths rather than just
// widths. At present I think that would count as overkill.
    for (i=0; i<256; i++) fh->across[i] = (unsigned char)widths[i];
    return newFont;
}

void CMainWindow::OnPrint()
{
    CPrintDialog pd(FALSE);
    if (pd.DoModal() != IDOK)
    {   cwin_ensure_screen(FALSE);
        return;
    }
    CDC PrintDC;
    if (PrintDC.CreateDC(pd.GetDriverName(), pd.GetDeviceName(),
                         pd.GetPortName(), NULL))
    {   int printWidth = PrintDC.GetDeviceCaps(HORZRES),
            printHeight = PrintDC.GetDeviceCaps(VERTRES);
// Also get the size of the print area in mm.
        int sizeX = PrintDC.GetDeviceCaps(HORZRES),  // measured in pixels
            sizeY = PrintDC.GetDeviceCaps(VERTRES);
        int mmX = PrintDC.GetDeviceCaps(HORZSIZE),   // measured in mm
            mmY = PrintDC.GetDeviceCaps(VERTSIZE);
// I will try to allow a 10mm margin to right & left and a 15mm at top
//and bottom of the printed page.
        int offsetX = (10*sizeX)/mmX;
        int offsetY = (15*sizeY)/mmY;
        sizeX -= 2*offsetX;
        sizeY -= 2*offsetY;

// Create printer fonts, using the same type face as is present on the
// screen.  Scale it so that around 80 columns will fit across the page.
// I scale for 81 not 80 to leave a margin for rounding etc etc.
        FontHeights fh;
        CFont *f = MakeNewFont(&PrintDC, &fh, ANSI_CHARSET,
                               (char *)windowFonts.baseFace,
                               windowFonts.boldFlag, 0, 100);
        PrintDC.SelectStockObject(SYSTEM_FONT);
        delete f;
        int X = fh.across['X'];
        int newH = (fh.height * sizeX)/(81 * X);
        printerFonts.ChangeFont(&PrintDC, newH,
                                windowFonts.boldFlag, windowFonts.baseFace);

        DOCINFO DocInfo;
        DocInfo.cbSize = sizeof(DOCINFO);
        DocInfo.lpszDocName = "Screen Dump";
        DocInfo.lpszOutput = NULL;
        if (PrintDC.StartDoc(&DocInfo) != -1)
        {
            PrintDC.StartPage();
            PrintDC.SetTextAlign(TA_BASELINE);
            PrintDC.SetTextColor(RGB(0,0,0));          currentColour = CH_BLACK;
            PrintDC.SetBkColor(windowColour);
            PrintDC.SelectObject(printerFonts.Courier);currentFont = CH_COURIER;
            currentWidths = printerFonts.HCourier.across;

            int y = offsetY, line;
            for (line=lineFirst;; line=(line+1)&LINE_MASK)
            {   int up, down;
                MeasureLine(lineBuffer[line].address,
                            &up, &down, &printerFonts);
                int y1 = y+up;
                int y2 = y+up+down;
                if (y2 > sizeY)
                {    PrintDC.EndPage();
                     PrintDC.StartPage();
                     PrintDC.SetTextAlign(TA_BASELINE);
                     PrintDC.SetTextColor(RGB(0,0,0));          currentColour = CH_BLACK;
                     PrintDC.SetBkColor(windowColour);
                     PrintDC.SelectObject(printerFonts.Courier);currentFont = CH_COURIER;
                     currentWidths = printerFonts.HCourier.across;
                     y = offsetY;
                     y1 = y+up;
                     y2 = y+up+down;
                }
                PaintTextLine(&PrintDC, offsetX, y, y1, y2,
                              lineBuffer[line].address,
                              sizeX, &printerFonts, 1);
                y = y2;
                if (line==lineLast) break;
            }
            PrintDC.SelectStockObject(BLACK_PEN);
            PrintDC.EndPage();
            PrintDC.EndDoc();
        }
        printerFonts.DeleteFonts();
    }
    GlobalFree(pd.m_pd.hDevMode);
    GlobalFree(pd.m_pd.hDevNames);
    cwin_ensure_screen(FALSE);
}

void CMainWindow::OnPrintSel()
{
    if (selStartChar == selEndChar) return; // nothing selected!
    CPrintDialog pd(FALSE);
    if (pd.DoModal() != IDOK)
    {   cwin_ensure_screen(FALSE);
        return;
    }
    CDC PrintDC;
    if (PrintDC.CreateDC(pd.GetDriverName(), pd.GetDeviceName(),
                         pd.GetPortName(), NULL))
    {   int printWidth = PrintDC.GetDeviceCaps(HORZRES),
            printHeight = PrintDC.GetDeviceCaps(VERTRES);
// Also get the size of the print area in mm.
        int sizeX = PrintDC.GetDeviceCaps(HORZRES),  // measured in pixels
            sizeY = PrintDC.GetDeviceCaps(VERTRES);
        int mmX = PrintDC.GetDeviceCaps(HORZSIZE),   // measured in mm
            mmY = PrintDC.GetDeviceCaps(VERTSIZE);
// I will try to allow a 10mm margin to right & left and a 15mm at top
//and bottom of the printed page.
        int offsetX = (10*sizeX)/mmX;
        int offsetY = (15*sizeY)/mmY;
        sizeX -= 2*offsetX;
        sizeY -= 2*offsetY;

// Create printer fonts, using the same type face as is present on the
// screen.  Scale it so that around 80 columns will fit across the page.
// I scale for 81 not 80 to leave a margin for rounding etc etc.
        FontHeights fh;
        CFont *f = MakeNewFont(&PrintDC, &fh, ANSI_CHARSET,
                               (char *)windowFonts.baseFace,
                               windowFonts.boldFlag, 0, 100);
        PrintDC.SelectStockObject(SYSTEM_FONT);
        delete f;
        int X = fh.across['X'];
        int newH = (fh.height * sizeX)/(81 * X);
        printerFonts.ChangeFont(&PrintDC, newH,
                                windowFonts.boldFlag, windowFonts.baseFace);

        DOCINFO DocInfo;
        DocInfo.cbSize = sizeof(DOCINFO);
        DocInfo.lpszDocName = "Selection Dump";
        DocInfo.lpszOutput = NULL;
        if (PrintDC.StartDoc(&DocInfo) != -1)
        {
            PrintDC.StartPage();
            PrintDC.SetTextAlign(TA_BASELINE);
            PrintDC.SetTextColor(RGB(0,0,0));          currentColour = CH_BLACK;
            PrintDC.SetBkColor(windowColour);
            PrintDC.SelectObject(printerFonts.Courier);currentFont = CH_COURIER;
            currentWidths = printerFonts.HCourier.across;

            int y = offsetY, line;
            for (line=selStartLine;; line=(line+1)&LINE_MASK)
            {   int up, down;
                MeasureLine(lineBuffer[line].address,
                            &up, &down, &printerFonts);
                int y1 = y+up;
                int y2 = y+up+down;
                if (y2 > sizeY)
                {    PrintDC.EndPage();
                     PrintDC.StartPage();
                     PrintDC.SetTextAlign(TA_BASELINE);
                     PrintDC.SetTextColor(RGB(0,0,0));          currentColour = CH_BLACK;
                     PrintDC.SetBkColor(windowColour);
                     PrintDC.SelectObject(printerFonts.Courier);currentFont = CH_COURIER;
                     currentWidths = printerFonts.HCourier.across;
                     y = offsetY;
                     y1 = y+up;
                     y2 = y+up+down;
                }
                PaintTextLine(&PrintDC, offsetX, y, y1, y2,
                              lineBuffer[line].address,
                              sizeX, &printerFonts, 2);
                y = y2;
                if (line==selEndLine) break;
            }
            PrintDC.SelectStockObject(BLACK_PEN);
            PrintDC.EndPage();
            PrintDC.EndDoc();
        }
        printerFonts.DeleteFonts();
    }
    GlobalFree(pd.m_pd.hDevMode);
    GlobalFree(pd.m_pd.hDevNames);
    cwin_ensure_screen(FALSE);
}

void CMainWindow::OnCut()
{
    OnCopy();
    DeleteSelection();
    cwin_ensure_screen(FALSE);
}

void CMainWindow::DeleteSelection()
{
    int p = selStartChar, q = selEndChar;
    if (betweenChar(p, caretChar, q))
    {   caretChar = p;
        caretLine = selStartLine;
// In general after a delete operation caretX will not be valid, but the
// paint operation puts that right soon enough.
//--    caretX = selStartX;
    }
    if (betweenChar(p, icaretChar, q))
    {   icaretChar = p;
        icaretLine = selStartLine;
// In general after a delete operation icaretX will not be valid, but the
// paint operation puts that right soon enough.
//--    icaretX = selStartX;
    }
    if (selStartLine==selEndLine)
    {   while (q!=textLast)
        {   int c = textBuffer[q];
            textBuffer[p] = c;
            if (caretChar==q) caretChar = p;
            if (icaretChar==q) icaretChar = p;
            if (inputLineStart==q) inputLineStart=p;
            if (c == '\n') break;
            p = (p+1)&TEXT_MASK;
            q = (q+1)&TEXT_MASK;
        }
        if (textLast==q) textLast = p;
        if (inputLineStart==q) inputLineStart=p;
        if (caretChar==q) caretChar=p;
        if (icaretChar==q) icaretChar=p;
// The caret will have its position re-calculated during the re-draw, and also
// the line-length record will be adjusted then.
        InvalidateSelection(selStartLine, selStartX,
                            selStartLine, clientWidth+xOffset);
    }
    else
    {   int l = selStartLine, l1 = selEndLine;
        lineLast = l;
        for (;;)
        {   while (q!=textLast)
            {   int c = textBuffer[q];
                textBuffer[p] = c;
                if (caretChar==q) caretChar=q, caretLine = l;
                if (inputLineStart==q) inputLineStart=p;
                if (icaretChar==q) icaretChar=p, icaretLine = l;
                p = (p+1)&TEXT_MASK;
                q = (q+1)&TEXT_MASK;
                if (c=='\n') break;
            }
            if (q==textLast) break;
            l1 = (l1+1)&LINE_MASK;
            q = lineBuffer[l1].address;
            l = (l+1)&LINE_MASK;
            lineBuffer[l].address = p;
            lineLast = l;
        }
        if (inputLineStart==q) inputLineStart=p;
        if (caretChar==q) caretChar=p;
        if (icaretChar==q) caretChar=p;
        textLast = p;
        LineSizes();
// I invalidate down to the bottom of the screen. In some cases maybe I
// count do a ScrollWindow to good effect, and the plain invalidation
// here may cause the screen to flicker more than would be ideal.
        CRect cr(0, LineY(selStartLine), clientWidth, clientHeight);
        InvalidateRect(&cr);
    }
    selFirstChar = selEndChar = selStartChar;
    selFirstX = selEndX = selStartX;
    selFirstLine = selEndLine = selStartLine;
// The following sequence of operations is intended to scroll the window
// (if necessary) to make the caret visible, to get scroll bar thumbs
// up to date (eg after a multi-line delete) etc.
    UpdateWindow();
    OnSize(SIZE_RESTORED, clientWidth, clientHeight);
    HideCaret();
    CPoint caretPos(caretX-xOffset, caretY);
    SetCaretPos(caretPos);
    ShowCaret();
}

void CMainWindow::OnCopy()
{
// Here I have to allocate some global memory and copy text out of my buffer
// into it, making sure I insert CR/LF combinations between lines and a
// zero byte on the end as a terminator.  If the text buffer contains funny
// characters that are used to indicate font changes etc I will just leave
// them in there for the moment.
    if (!OpenClipboard()) return;
    if (!::EmptyClipboard()) return;  // Take control of clipboard

    int l1 = selStartLine;
    int cp = selStartChar, size=1;
    for (;;)
    {   while (cp!=selEndChar && textBuffer[cp]!='\n')
        {   cp = (cp+1)&TEXT_MASK;
            size++;
        }
        if (cp==selEndChar) break;
        size=size+2;
        l1 = (l1+1)&LINE_MASK;
        cp = lineBuffer[l1].address;
    }
    HGLOBAL h = ::GlobalAlloc(GMEM_MOVEABLE+GMEM_DDESHARE, size);
    HGLOBAL h1 = 0;
    if (clipboardformat != 0)
        h1 = ::GlobalAlloc(GMEM_MOVEABLE+GMEM_DDESHARE, size);
    char *p = NULL, *p1 = NULL;
    if (h != NULL) p = (char *)::GlobalLock(h);
    if (h1 != NULL) p1 = (char *)::GlobalLock(h1);
    if (p != NULL)
    {   l1 = selStartLine;
        cp = selStartChar;
        for (;;)
        {   while (cp!=selEndChar && textBuffer[cp]!='\n')
            {   int c = textBuffer[cp];
                if ((c&0xff) != CH_PROMPT && (c&0xff) != CH_ENDPROMPT) *p++ = c;
                if (p1 != NULL) *p1++ = c;
                cp = (cp+1)&TEXT_MASK;
                size++;
            }
            if (cp==selEndChar) break;
            *p++ = '\r'; *p++ = '\n';   // CR/LF combination at end of line
            if (p1 != NULL)
            {   *p1++ = '\r';
                *p1++ = '\n';
            }
            l1 = (l1+1)&LINE_MASK;
            cp = lineBuffer[l1].address;
        }
        *p = 0;
        ::GlobalUnlock(h);
        if (p1 != NULL)
        {   *p1 = 0;
            ::GlobalUnlock(h1);
            ::SetClipboardData(clipboardformat, h1);
        }
        ::SetClipboardData(CF_TEXT, h);
        
    }
    ::CloseClipboard();
    cwin_ensure_screen(FALSE);
}

void CMainWindow::OnPaste()
{
    HGLOBAL clipboardInputHandle;
    char *w;
    ToIcaret();
    caretVisible = TRUE;
    cwin_ensure_screen(FALSE);  // may jump screen to caret location
    pageLine = caretLine;
    insertMode = TRUE;
    if (!OpenClipboard()) return;
// If I get a new PASTE operation before an earlier one has quite finished
// I will just abandon the end of the old one without further fuss.
    if (clipboardInput != NULL) free(clipboardInput);
// If I had managed to register my own format I will use data in that format
// in preference to text. Otherwise I will just grab text.
    if (clipboardformat != 0)
        clipboardInputHandle = ::GetClipboardData(clipboardformat);
    else clipboardInputHandle = 0;
    if (clipboardInputHandle == 0)
        clipboardInputHandle = ::GetClipboardData(CF_TEXT);
    clipboardInput = NULL;
    if (clipboardInputHandle != 0)
    {   w = (char *)::GlobalLock(clipboardInputHandle);
        if (w != NULL)
        {   int n = strlen(w); // amount of data found
            clipboardInput = clipboardInputP = (char *)malloc(n+1);
            if (clipboardInput != NULL) strcpy(clipboardInput, w);
            ::GlobalUnlock(clipboardInputHandle);
        }
    }
    ::CloseClipboard();
    if (caretChar != textLast)
    {   char oneLine[128];
        for (;;)
        {   int i=0, c;
            while (i<120 && clipboardInput!=NULL && (c=*clipboardInputP++)!=0)
            {   if (c == '\r') continue;
                oneLine[i++] = c;
                if (c == '\n') break;  // Do pastes one line at a time
break; // do it one CHARACTER at a time...
            }
            InsertAtCaret(oneLine, i);
            if (c == 0) break;
        }
        if (clipboardInput != NULL) free(clipboardInput);
        clipboardInput = NULL;
    }
    cwin_ensure_screen(FALSE);
}

// The REINPUT request just combines a COPY and PASTE. It seems clumsy to
// have to do both as separate actions.

void CMainWindow::OnReInput()
{
    OnCopy();
    OnPaste();
}

void CMainWindow::OnSelectAll()
{
    selFirstChar = selStartChar = textFirst;
    selEndChar = textLast;
    selFirstX = selStartX = 0;
    selEndX = lineBuffer[lineLast].width;
    selFirstLine = selStartLine = lineFirst;
    selEndLine = lineLast;
    HideCaret();
    Invalidate();
    ShowCaret();
}

void CMainWindow::OnClear()
{
    CancelSelection();
    caretChar = icaretChar = textFirst = textLast;
    caretLine = icaretLine = lineFirst = lineLast;
    caretX = icaretX = endX = 0;
    xOffset = 0;
    caretVisible = TRUE;
    caretFontWidths = windowFonts.HCourier.across;
    endFontWidths = windowFonts.HCourier.across;
    if (inputLineStart>=0) inputLineStart = textLast;
    pageLine = caretLine;
    cwin_ensure_screen(FALSE);
}

// void CMainWindow::OnUndo()
// {
//     DisplayMsg("OnUndo Text");
// }

void CMainWindow::OnRedraw()
{
    HideCaret();
    Invalidate();
    ShowCaret();
}

// I make END reset the caret to the end of the text buffer, since that
// is an important state to be in, both with regard to input and to output.
// HOME just scrolls the window to make the top of the text visible, but does
// not re-position the caret. That is done because I do not generally expect
// people to want to insert characters at the very top of the buffer.

void CMainWindow::OnHome()
{
    OnVScroll(SB_THUMBPOSITION, 0, NULL);
    OnHScroll(SB_THUMBPOSITION, 0, NULL);
}

void CMainWindow::OnEnd()
{
    icaretLine = caretLine = lineLast;
    icaretChar = caretChar = textLast;
    icaretX = caretX = endX;
    caretFontWidths = endFontWidths;
    selRootValid = TRUE;

    OnVScroll(SB_FOR_CARET, 0, NULL);
    OnHScroll(SB_FOR_CARET, 0, NULL);
    caretVisible = TRUE;
    cwin_ensure_screen(FALSE);  // makes sure caret is properly on screen
}

void CMainWindow::ToIcaret()
{
    caretLine = icaretLine;
    caretChar = icaretChar;
    caretX = icaretX;
    caretFontWidths = icaretFontWidths;

    OnVScroll(SB_FOR_CARET, 0, NULL);
    OnHScroll(SB_FOR_CARET, 0, NULL);
    caretVisible = TRUE;
    cwin_ensure_screen(FALSE);  // makes sure caret is properly on screen
}

//
// The font arrangements are as follows - at each stage I will have a
// master fixed-pitch font (typically "Courier New"). Whenever I change
// that font I locate a collection of slave fonts - Roman, Roman Italic
// and Symbol each in two sizes (one about the same as the master font and
// another about (10/12)^2 of that size, for use in sub- and super-scripts).
//

// When I change fonts I will only change the ones used for display in
// my window. The ones used when printing will be left as their original size.
// I only permit font selection to alter the font (name) for the simple
// fixed-pitch font that I use. But I still need to reconstruct printer
// fonts to allow for changes there.

void CMainWindow::OnResetFont()
{
    HideCaret();
    CClientDC dc(this);
// I need to find a suitable size for my default font, so I create one
// asking for "size=0" and see what windows hands back to me.
    FontHeights fh;
    CFont *f = MakeNewFont(&dc, &fh, ANSI_CHARSET, "Courier New",
                           FW_BOLD, 0, 0);
    dc.SelectStockObject(SYSTEM_FONT);
    delete f;
// If there is a font already set up somebody must discard it...
    windowFonts.DeleteFonts();
    windowFonts.ChangeFont(&dc, fh.height, FW_BOLD, "Courier New");
    theApp.WriteProfileInt("MainWindow", "FontSize", fh.height);
    theApp.WriteProfileString("MainWindow", "FontName", "Courier New");
    theApp.WriteProfileInt("MainWindow", "FontWeight", 0);
    // scroll activity may be needed here just as it is
    // after some changes of window size.
    OnSize(SIZE_RESTORED, clientWidth, clientHeight);
    Invalidate();    // I think a total re-draw after a font change
                     // makes sense, and will not worry evan if the new
                     // font was identical to the old one, since after all
                     // the user prodded the OK not the CANCEL button.
    ShowCaret();
}

void CMainWindow::OnFont()
{
    HideCaret();
    CClientDC dc(this);
    LOGFONT logFont;
    windowFonts.Courier->GetObject(sizeof(logFont), &logFont);
    CFontDialog fontDialog(&logFont,
                           CF_SCREENFONTS | CF_FIXEDPITCHONLY |
                           CF_TTONLY |
                           CF_ANSIONLY | CF_INITTOLOGFONTSTRUCT);
// I will keep trying to obtain fonts from the user until I find one that
// can be properly installed.  Maybe it is unkind, but if a font as selected
// from the dialog box fails to be created I just restart the dialog without
// further explanation.
    for (;;)
    {   int w = fontDialog.DoModal();
        if (w == IDCANCEL) break;
        else if (w != IDOK) continue;
        LOGFONT *lf = fontDialog.m_cf.lpLogFont;
// If there is a font already set up somebody must discard it...
        windowFonts.DeleteFonts();
// Whatever the user does I do not want either very very small fonts or
// ones that would be so huge that their metrics could exceed 256. I apply
// rather arbitrary cut-offs here.
        if (lf->lfHeight < -150) lf->lfHeight = -150;
        if (lf->lfHeight <= -6);
        else if (lf->lfHeight < 6) lf->lfHeight = -6;
        else if (lf->lfHeight > 150) lf->lfHeight = -150;
        windowFonts.ChangeFont(&dc, lf->lfHeight, lf->lfWeight, lf->lfFaceName);
        theApp.WriteProfileInt("MainWindow", "FontSize", lf->lfHeight);
        theApp.WriteProfileString("MainWindow", "FontName", lf->lfFaceName);
        theApp.WriteProfileInt("MainWindow", "FontWeight",
                               lf->lfWeight==FW_BOLD ? 0 : 1);
        break;
    }
    // scroll activity may be needed here just as it is
    // after some changes of window size.
    OnSize(SIZE_RESTORED, clientWidth, clientHeight);
    Invalidate();    // I think a total re-draw after a font change
                     // makes sense, and will not worry evan if the new
                     // font was identical to the old one, since after all
                     // the user prodded the OK not the CANCEL button.
    ShowCaret();
}

void FontArray::InitFont(CDC *dc, const char *name, int weight, int size)
{
// Create and install a suitable initial font - I use "Courier New"
// and ask for a default size the very first time, and this is
// achieved by passing down "Courier New" and "0".
// Because Courier tends to look rather light on
// the screen I will use a bold weight by default.
// I really hope that the default size will be such that 80 columns will fit
// neatly across the screen...
    FontHeights fh;
    weight = weight ? FW_NORMAL : FW_BOLD;
    CFont *f = MakeNewFont(dc, &fh, ANSI_CHARSET, name,
                           weight, 0, size);
    dc->SelectStockObject(SYSTEM_FONT);
    delete f;
    ChangeFont(dc, size == 0 ? fh.height : size, weight, name);
}

void FontArray::DeleteFonts()
{
    delete Courier;    Courier = NULL;
    delete Roman;      Roman = NULL;
    delete Bold;       Bold = NULL;
    delete Italic;     Italic = NULL;
    delete Symbol;     Symbol = NULL;
    delete roman;      roman = NULL;
    delete bold;       bold = NULL;
    delete italic;     italic = NULL;
    delete symbol;     symbol = NULL;
}

// The next function is a place-holder, I guess.

void CMainWindow::MeasureLine(int address, int *up, int *down, FontArray *fa)
{
    *up = fa->HCourier.up;
    *down = fa->HCourier.down;
}

void FontArray::ChangeFont(CDC *dc, int size, int weight, const char *facename)
{
    strcpy(baseFace, facename);
    boldFlag = weight;
    Courier = MakeNewFont(dc, &HCourier,    ANSI_CHARSET,
                          facename,         weight, 0, size);
// I choose the scale factor 1.2^2 between my main and my script font mainly
// because that is what TeX seems to have adopted - Windows will generally
// round the size I ask for somewhat.... I also reload the size of my
// basic fixed-pitch font in case an inconvenient value had been handed in
// to start with and creating the font led to rounding.
    size = HCourier.height;
    int small = (100*size+72)/144;
// These fonts have my predefined font-names and weights. They are not in fact
// really (?) used at present.
    Roman  = MakeNewFont(dc, &HRoman,       ANSI_CHARSET,
                         "Times New Roman", FW_NORMAL, 0, size);
    Bold   = MakeNewFont(dc, &HBold,        ANSI_CHARSET,
                         "Times New Roman", FW_BOLD,   0, size);
    Italic = MakeNewFont(dc, &HItalic,      ANSI_CHARSET,
                         "Times New Roman", FW_NORMAL, 1, size);
    Symbol = MakeNewFont(dc, &HSymbol,      SYMBOL_CHARSET,
                         "Symbol",          FW_NORMAL, 0, size);
    roman  = MakeNewFont(dc, &Hroman,       ANSI_CHARSET,
                         "Times New Roman", FW_NORMAL, 0, small);
    bold   = MakeNewFont(dc, &Hbold,        ANSI_CHARSET,
                         "Times New Roman", FW_BOLD,   0, small);
    italic = MakeNewFont(dc, &Hitalic,      ANSI_CHARSET,
                         "Times New Roman", FW_NORMAL, 1, small);
    symbol = MakeNewFont(dc, &Hsymbol,      SYMBOL_CHARSET,
                         "Symbol",          FW_NORMAL, 0, small);
    theApp.mainWindow->LineSizes();
    ::DestroyCaret();
    theApp.mainWindow->CreateSolidCaret(
        2*GetSystemMetrics(SM_CXBORDER), HCourier.height);
}

void CMainWindow::LineSizes()
{
    int up, down, pos;
    int lineFirst = theApp.mainWindow->lineFirst;
    int lineLast = theApp.mainWindow->lineLast;
    TextLine *lineBuffer = &theApp.mainWindow->lineBuffer[0];
    MeasureLine(lineBuffer[lineFirst].address, &up, &down, &windowFonts);
    lineBuffer[lineFirst].position = 0;
    lineBuffer[lineFirst].up = up;
    lineBuffer[lineFirst].height = up+down;
    lineBuffer[lineFirst].width = 000;
    pos = up + down;
    for (int i=(lineFirst+1)&LINE_MASK;;i=(i+1)&LINE_MASK)
    {   MeasureLine(lineBuffer[i].address, &up, &down, &windowFonts);
        lineBuffer[i].position = pos;
        lineBuffer[i].up = up;
        lineBuffer[i].height = up+down;
        lineBuffer[i].width = 000;
        pos += up + down;
        if (i==lineLast) break;
    }
}

// Now some support for a really crude and simple text-based help window.
// The interface I provide here is intended to be such that I can have
// alternative implementations (eg using Unix) that use a "curses" style
// screen manager.

// For Windows I will only support an 80 by 25 window. I guess it
// would be easy enough to permit other sizes, except that I do not have
// an easy answer to what should happen if the user re-sizes the window
// while other things are going on. Hence my conservative caution - at
// least for now!

extern "C" {

int LINES = 25, COLS = 80;

// initscr() must be called once at the start of a run
extern void initscr();

// initkb() and resetkb() delimit regions in the code where keyboard
// input is treated as requests to the curses window but is accepted
// with no delay and no echo.  Also mouse events can be posted during
// this time.

extern void initkb();
extern void resetkb();

extern int mouse_button;  // set non-zero when user presses a button
extern int mouse_cx;      // 0 <= mouse_cx < COLS
extern int mouse_cy;      // 0 <= mouse_cy < LINES

// refresh() is called to force the screen to be up to date
extern void refresh();

// endwin() hides the curses window, restoring simple text handling
extern void endwin();

// Move text insertion point. Origin (0,0) is top left of screen
extern void move(int y, int x);

// standout() and standend() delimit inverse video (or whatever) text
extern void standout();
extern void standend();

// erase() clears the whole screen
extern void erase();

//
// addch() and addstr() add text to the screen, advancing the cursor. I
// view it as illegal to write beyond either right or bottom margin of the
// screen.
//
extern void addch(int ch);
extern void addstr(char *s);

//
// getch() reads a character from the keyboard. It does not wait for
// a newline, and does not echo anything. Because the name getch() may be
// in use in some C libraries in a way that could conflict I use some

// re-naming here.  If there has been a mouse-click recently then getch()
// should return a value (0x100 + bits) where the odd bits may indicate which
// button was pressed. In that case (mouse_cx,mouse_cy) will be the
// character-position coordinates at which the hit was taken. Systems
// that can not support a mouse do not have to worry about this and can always
// return a value in the range 0..255, or EOF. On some systems getch() will
// return 0 with no delay if there is no character available (so that
// the application will busy-wait). On others it is entitled to wait until
// the user presses a key. But (once again) it should not do line editing or
// wait for an ENTER.
//
extern int my_getch();
#undef getch
#define getch() my_getch()

}

static BOOL helpShown = FALSE;
static int helpChar = -1;

void initscr()
{
    helpShown = FALSE;
    helpChar = -1;
}

void initkb()
{
    if (!helpShown)
    {   erase();
        theApp.mainWindow->helpWindow->ShowWindow(SW_SHOW);
        helpShown = TRUE;
    }
    helpChar = -1;
}

void resetkb()
{
    if (helpShown)
    {   theApp.mainWindow->helpWindow->ShowWindow(SW_HIDE);
        helpShown = FALSE;
    }
}

void endwin()
{
    resetkb();
}

static int helpY, helpX;

void move(int y, int x)
{
    helpY = y;
    helpX = x;
}

void erase()
{
    helpX = helpY = 0;
    for (int y=0; y<LINES; y++)
        for (int x=0; x<COLS; x++)
            theApp.mainWindow->helpWindow->contents[y][x] = ' ';
    theApp.mainWindow->helpWindow->highline =
        theApp.mainWindow->helpWindow->highstart =
        theApp.mainWindow->helpWindow->highend = -1;
}

void standout()
{
    theApp.mainWindow->helpWindow->highline = helpY;
    theApp.mainWindow->helpWindow->highstart =
        theApp.mainWindow->helpWindow->highend = helpX;
}

void standend()
{
    if (theApp.mainWindow->helpWindow->highline != helpY)
    {   theApp.mainWindow->helpWindow->highline = helpY;
        theApp.mainWindow->helpWindow->highstart = 0;
    }
    theApp.mainWindow->helpWindow->highend = helpX;
}

void addch(int ch)
{
    if (helpX < COLS && helpY < LINES)
    {   theApp.mainWindow->helpWindow->contents[helpY][helpX] = ch;
        helpX++;
    }
}

void addstr(char *s)
{
    while (*s != 0) addch(*s++);
}

int mouse_button = 0, mouse_cx = 0, mouse_cy = 0;

void refresh()
{
    if (!helpShown) initkb();
    theApp.mainWindow->helpWindow->Invalidate();
}

int my_getch()
{
    while (helpChar < 0) cwin_poll_window_manager();
    int ch = helpChar;
    helpChar = -1;
    return ch;    
}

CHelpWindow::CHelpWindow()
{
    char *menuName = "HelpMenu";
    HINSTANCE hInst = AfxFindResourceHandle(menuName, RT_MENU);
    HMENU hMenu = ::LoadMenu(hInst, menuName);
    this->CreateEx(0, mainWindowClass, "Help Window",
                   WS_OVERLAPPED | WS_CAPTION,
                   CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
                   NULL, hMenu);
    helpFont.CreateFont(
        0, 0,           // height, width
        0, 0,           // angle of escapement, base line orientation angle
        FW_BOLD, 0,     // weight, italic-flag
        0, 0, ANSI_CHARSET,    // underline, strike-out, character-set
        OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
        DEFAULT_QUALITY, DEFAULT_PITCH+FF_DONTCARE,
        "Courier New");
    for (int y=0;y<25;y++)
        for (int x=0;x<80;x++) contents[y][x] = ' ';
    highline = 5;
    highstart = 7;
    highend = 11;
}


BEGIN_MESSAGE_MAP(CHelpWindow, CFrameWnd)

    ON_WM_PAINT()
    ON_WM_CHAR()
    ON_WM_KEYDOWN()
    ON_WM_LBUTTONDOWN()
    ON_COMMAND(IDM_REDRAW,         OnRedraw)
//  ON_COMMAND(IDM_COPY,           OnCopy)
    ON_COMMAND(IDM_CLOSE,          OnClose)

END_MESSAGE_MAP()


void CHelpWindow::OnPaint()
{
    CPaintDC dc(this);
    dc.SelectObject(&helpFont);
    for (int i = 0; i<25; i++)
    {   if (i == highline)
        {   dc.TextOut(0, i*height, contents[i], highstart);
            dc.SetTextColor(theApp.mainWindow->highlightTextColour);
            dc.SetBkColor(theApp.mainWindow->highlightColour);
            dc.TextOut(highstart*width, i*height, &contents[i][highstart],
                       highend-highstart);
            dc.SetTextColor(theApp.mainWindow->textColour);
            dc.SetBkColor(theApp.mainWindow->windowColour);
            dc.TextOut(highend*width, i*height, &contents[i][highend],
                       80-highend);
        }
        else dc.TextOut(0, i*height, contents[i], 80);
    }
    dc.SelectStockObject(SYSTEM_FONT);
}

void CHelpWindow::OnChar(UINT ch, UINT nRepCnt, UINT nFlags)
{
    switch (ch)
    {
//case ('O' & 0x1f):
//        OnCopy();
//        return;
case ('L' & 0x1f):
        OnRedraw();
        return;
default:
        helpChar = ch;
        return;
    }
}

void CHelpWindow::OnKeyDown(UINT ch, UINT nRepCnt, UINT nFlags)
{
}


void CHelpWindow::OnLButtonDown(UINT nFlags, CPoint point)
{
}

//void CHelpWindow::OnCopy()
//{
//    HGLOBAL hpbmi = 0;   // @@@@@@@@@
//    if (this->OpenClipboard())
//    {   ::EmptyClipboard();
//        ::SetClipboardData(CF_DIB, hpbmi);
//        ::CloseClipboard();
//    }
//}

void CHelpWindow::OnRedraw()
{
    Invalidate();
}

void CHelpWindow::OnClose()
{
    helpChar = 'q';
}


// end of c_text.cpp

