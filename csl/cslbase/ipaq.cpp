//
// Framework for a Windows CE Application... This is being
// built for CE version 420 to run on an IPAQ 4700 (which is a VGA
// system). I am not going to guarantee or even worry too much (to start
// with at least) about support of other platform variants.
//
//                                 A C Norman, Codemist Ltd, March 2005
//

/**************************************************************************
 * Copyright (C) 2008, Codemist Ltd.                     A C Norman       *
 *                                                                        *
 * Redistribution and use in source and binary forms, with or without     *
 * modification, are permitted provided that the following conditions are *
 * met:                                                                   *
 *                                                                        *
 *     * Redistributions of source code must retain the relevant          *
 *       copyright notice, this list of conditions and the following      *
 *       disclaimer.                                                      *
 *     * Redistributions in binary form must reproduce the above          *
 *       copyright notice, this list of conditions and the following      *
 *       disclaimer in the documentation and/or other materials provided  *
 *       with the distribution.                                           *
 *                                                                        *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS    *
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT      *
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS      *
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE         *
 * COPYRIGHT OWNERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,   *
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,   *
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS  *
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND *
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR  *
 * TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF     *
 * THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH   *
 * DAMAGE.                                                                *
 **************************************************************************

/* Signature: 63b0fb9a 24-May-2008 */

#include <windows.h>
#include "res.h"
#include <commctrl.h>
#include <aygshell.h>
#include <stdio.h>

HINSTANCE g_hInst;       // The current instance
HWND      g_hwndCB;      // The command bar handle
HWND      g_hWnd = NULL; // main window


HFONT     hFont = 0;

// Private messages that I use within this application.

#define WM_REQUESTINPUT (WM_APP+0x01)
#define WM_PRINTCHAR    (WM_APP+0x02)
#define WM_PRINTBUFFER  (WM_APP+0x03)
#define WM_WORKERQUIT   (WM_APP+0x04)

HANDLE    workerThread;

HANDLE    mutex1, mutex2;
int       readRequestPending = 0;
char      inputLine[200], workerLine[200];
int       inputN = 0, workerN = 0, workerP = 0;
#define TYPEAHEADSIZE 256
char      typeAhead[TYPEAHEADSIZE];
int       aheadIn = 0, aheadOut = 0;


static RECT windowSize;

static SHACTIVATEINFO s_sai;

// Forward declarations of functions included in this code module:
ATOM             MyRegisterClass(HINSTANCE);
BOOL             InitInstance(HINSTANCE, int);
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK About(HWND, UINT, WPARAM, LPARAM);
HWND             CreateRpCommandBar(HWND);
DWORD WINAPI     WorkerProc(LPVOID parm);

int WINAPI WinMain(HINSTANCE hInstance,
                   HINSTANCE hPrevInstance,
                   LPTSTR    lpCmdLine,
                   int       nCmdShow)
{
    MSG msg;
    HACCEL hAccelTable;

    // Perform application initialization:
    if (!InitInstance(hInstance, nCmdShow)) return FALSE;

    hAccelTable = LoadAccelerators(hInstance, L"ACCEL");

    // Main message loop:
    while (GetMessage(&msg, NULL, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {   TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }
    return msg.wParam;
}

//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
//  COMMENTS:
//
//    It is important to call this function so that the application
//    will get 'well formed' small icons associated with it.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASS wc;
    wc.style         = CS_HREDRAW | CS_VREDRAW;
    wc.lpfnWndProc   = (WNDPROC)WndProc;
    wc.cbClsExtra    = 0;
    wc.cbWndExtra    = 0;
    wc.hInstance     = hInstance;
    wc.hIcon         = LoadIcon(hInstance, L"ICON");
    wc.hCursor       = 0;
    wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
    wc.lpszMenuName  = 0;
    wc.lpszClassName = L"PPC-CSL";
    return RegisterClass(&wc);
}

#define TEXTSIZE 5000
#define TEXTLINES 33

TCHAR text[TEXTSIZE];
unsigned char textColour[(TEXTSIZE+3)/4]; // 2-bits per character.
int textIn = 0;


#define TEXT_BLACK 0
#define TEXT_RED   1
#define TEXT_BLUE  2
#define TEXT_GREEN 3
int currentColour = TEXT_BLACK;

int textLine[TEXTLINES];
int textX = 0, textY = 0;

// Another brief essay about how I do things. In particular the representation
// of text. I will allow for LIMITED scrollback (although that is not yet
// implemented) by having a circular buffer that actually contains the
// text. This is stored in Unicode as a sequence of lines each terminated
// with a newline. An array textLine[] identifies that start in this buffer
// of the visible lines of the screen:
//
//   text:    0 1 2 3 4 5 6 7 8 9
//            - - A B \ C D \ - -    ("\" stands for newline here)
//                ^           ^
//    (textOut)---^           ^--- textIn
//
//      textLine[0]  2 
//      textLine[1]  5
//      textLine[2]  -1 (indicates no such line)
//      textLine[3]  -1 (and -1 from now on)
//
// The data in the text buffer wraps round in a circular manner (and thus
// when it is displayed it will sometimes take two steps to write a split
// line. The textLine array is kept up to date as text is added, and so
// values in it are shuffled if a scroll is needed. If adding characters
// tries to overwrite the first line then the first stored line is totally
// purged. I will assume that even when the maximum number of visible lines
// are stored that the text buffer is not full so I do not have to panic
// about overflow.
// Individual output lines can only be displayed up to character 68, and so I
// can truncate after (about) that, which ensures space. This width comes
// from using a screen with 480 pixels width and characters that are 7
// pixels wide.
// Each character in the text buffer has 2-bits of associated attribute
// information which control the colour of display used.
//    0: black,  1:red,   2:blue,   3:green
//


inline int attribute(int n)
{
    return (textColour[n>>2] >> (2*(n & 3))) & 3;
}

void setAttribute(int n, int v)
{
    int k = n>>2;
    int b = textColour[k];
    int s = 2*(n & 3);
    int mask = 3 << s;
    int d = v << s;
    b = (b & ~mask) | d;
    textColour[k] = b;
}

//
//  FUNCTION: InitInstance(HANDLE, int)
//
//  PURPOSE: Saves instance handle and creates main window
//
//  COMMENTS:
//
// In this function, we save the instance handle in a global variable and
// create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
    g_hInst = hInstance; // Store instance handle in our global variable

    //If it is already running, then focus on the window
    g_hWnd = FindWindow(L"PPC-CSL", L"CSL");
    if (g_hWnd)
    {   // set focus to foremost child window
        // The "| 0x01" is used to bring any owned windows to the
        // foreground and activate them.
        SetForegroundWindow((HWND)((ULONG)g_hWnd | 0x01));
        return 0;
    }

    MyRegisterClass(hInstance);

    g_hWnd =
        CreateWindow(L"PPC-CSL", L"CSL", WS_VISIBLE,
                     CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
                     CW_USEDEFAULT, NULL, NULL, hInstance, NULL);
    if (!g_hWnd) return FALSE;
// When the main window is created using CW_USEDEFAULT the height of the
// menubar (if one is created is not taken into account). So we resize
// the window after creating it if a menubar is present
    GetWindowRect(g_hWnd, &windowSize);
    if (g_hwndCB)
    {   RECT rcMenuBar;
        GetWindowRect(g_hwndCB, &rcMenuBar);
        windowSize.bottom -= (rcMenuBar.bottom - rcMenuBar.top);
        MoveWindow(g_hWnd, windowSize.left,
                           windowSize.top,
                           windowSize.right - windowSize.left,
                           windowSize.bottom - windowSize.top,
                           FALSE);
    }
    LOGFONT f;
    memset(&f, 0, sizeof(f));
    f.lfHeight = 16;
    f.lfWidth = 8;
    f.lfQuality = CLEARTYPE_COMPAT_QUALITY;
    f.lfPitchAndFamily = FIXED_PITCH;
    hFont = CreateFontIndirect(&f);

    for (int i=1; i<TEXTLINES; i++)
        textLine[i] = -1;
    textLine[0] = 0;
    text[0] = '\n';
    textIn = 0;              // text buffer now empty
    textX = textY = 0;       // writing to line 0, at column 0 at present
    currentColour = TEXT_BLACK;

    ShowWindow(g_hWnd, nCmdShow);
    UpdateWindow(g_hWnd);

    mutex1 = CreateMutex(NULL, 1, NULL);
    mutex2 = CreateMutex(NULL, 0, NULL);
    workerThread = CreateThread(NULL, 0, WorkerProc, NULL, 0, NULL);

    return TRUE;
}

void deleteChar()
{
// Do nothing at present...
}

void insertChar(int ch)
{
    int n = (textIn + 1) % TEXTSIZE;
    text[textIn] = ch;
    setAttribute(textIn, currentColour);
    textIn = n;
    text[n] = '\n';       // makes the re-painting code simpler
}

void showChar(int ch)
{
    RECT r;
    if (ch == '\n')         // end a line
    {   insertChar(ch);
        if (textY == TEXTLINES-1)
        {   for (int i=0; i<TEXTLINES-1; i++)
                textLine[i] = textLine[i+1];
// If the screen scrolls I will erase the whole background so I can
// paint everything again. Maybe if I had a BitBlt to scroll data on the
// screen directly I could use that.
            InvalidateRect(g_hWnd, NULL, TRUE);
        }
        else textY++;
        textLine[textY] = textIn;
        textX = 0;          // now at column 0
        return;
    }
    if (textX > 70) return; // silently truncate after 70 chars
    insertChar(ch);
    r.left = 7*textX;
    r.right = 7*textX + 7;
    r.top = 16*textY;
    r.bottom = 16*textY + 16;
// I invalidate without erasing the background here, and when I paint the
// characters I do so in non-opaque mode.
    InvalidateRect(g_hWnd, &r, FALSE);
    textX++;
}

char promptString[32] = {'A', ':', ' ', 0};

void displayPrompt()
{
    char *p = promptString;
    currentColour = TEXT_BLUE;
    while (*p != 0) showChar(*p++);
    currentColour = TEXT_RED;
    promptString[0]++; // make prompts change over time
}

int colourTable[4] =       // These colours are subject to review!
{    // bbggrr
    0x00000000,   // black           normal program output
    0x004000c0,   // redish maroon   echo of keyboard input
    0x00801000,   // darkish blue    prompt strings
    0x00208000    // darkish green   (unassigned at first)
};

//
//  FUNCTION: WndProc(HWND, unsigned, WORD, LONG)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_COMMAND  - process the application menu
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
//

LRESULT CALLBACK WndProc(HWND hWnd, UINT message,
                                    WPARAM wParam, LPARAM lParam)
{
    HDC hdc;
    int wmId, wmEvent;
    PAINTSTRUCT ps;
    int i, x, y;
    switch (message)
    {
case WM_CHAR:
// I need to write myself an essay about how I will handle input!
//
// At the start of a run there is no input request pending. The worker
// thread can make such a request by posting a message to the GUI thread
// and then going into a waiting state until a response arrives.
//
// If keyboard input arrives when there is no input request pending then
// printable characters are inserted into a type-ahead buffer. The only
// non-printable character that is handled is BACKSPACE, and that removes
// a character from the buffer unless the buffer is empty or the character
// that would be removed is an ENTER. At a later stage I will want to
// process at least ^\ (exit) and ^C (interrupt) even in this state.
//
// If an input request arrives I will first put a prompt string on the screen.
// Then if the type-ahead buffer is non-empty I will start moving characters
// from it into a current-line buffer, echoing each to the screen as I go. If
// I find an ENTER I return the line to the worker thread.
//
// If, even after processing some type-ahead, the current-line is incomplete
// I just await further keyboard input. Any that arrives is placed in the
// current-line and echoed on the screen. When an ENTER arrives I return to
// the worker (and in doing so I clear the input-request-pending status, as I
// did on returning a line from typed-ahead characters).
//
// The proper way to do a lot of this is to handle KEYDOWN and KEYUP
// events rather than CHAR. By so doing it becomes possibly to distinguish
// between (eg) backspace and ^H. But as best I can see at present I will
// need to detect shift and CTRL keys and maintain my own information about
// when they are pressed (and perhaps similarly for CAPS-LOCK) and do my own
// handling of character repetition. That all feels pretty heavy. So my
// strategy will be to start by handling CHAR messages and later (perhaps)
// I will detect the other cases.
//
        if (!readRequestPending)
        {   if (wParam == (0x1f & 'H'))
            {   if (aheadIn == aheadOut) return 0; // no type-ahead
                int p = aheadIn == 0 ? TYPEAHEADSIZE-1 : aheadIn-1;
// When the user presses ENTER the line they have just completed becomes
// committed. ENTER is represented as Ctl-M
                if (typeAhead[p] == (0x1f & 'M')) return 0;
                aheadIn = p;
            }
            else
            {   int p = (aheadIn+1) % TYPEAHEADSIZE;
                if (p == aheadOut) return 0; // no room in the buffer
                typeAhead[aheadIn] = wParam;
                aheadIn = p;
            }
            return 0;
        }

        switch (wParam)
        {
    case 0x1f & 'H':
// Backspace: if no chars in current line just ignore it.
            if (inputN == 0) return 0;
            inputN--;
            deleteChar();
            return 0;
    default:
            if (inputN < sizeof(inputLine)-1) 
            {   inputLine[inputN++] = wParam;
                currentColour = TEXT_RED;
                showChar(wParam);
            }
            return 0;
    case 0x1f & 'M':
// ENTER: and there was a read request pending so I must pass data to the
// worker thread and release it.
            inputLine[inputN++] = '\n'; // return as '\n' even if '\r'
            inputLine[inputN] = 0;      // terminate the input line
            showChar('\n');
            currentColour = TEXT_BLACK;
            readRequestPending = 0;
            HANDLE m2 = mutex2;
            ReleaseMutex(mutex1);   // permits worker to access the char
// The next line has a slight depth. It waits until the worker thread has
// accepted the data (and because it was waiting for it that should happen
// promptly). But while the worker has control it flips the two variables
// mutex1 and mutex2 so that after the WaitForSingleObject here the mutext
// actually claimed will be the one referred to be mutex1.
            WaitForSingleObject(m2, INFINITE);
            return 0;
        }

//  void ce_getline()
//  {
//      PostMessage(hWnd, WM_REQUESTINPUT, 0, 0);
//      WaitForSingleObject(mutex1, INFINITE);
//      memcpy(workerLine, inputLine, inputN);
//      workerN = inputN;
//      HANDLE w = mutex1;
//      mutext1 = mutex2;
//      mutex2 = w;
//      ReleaseMutex(mutex1);
//  // input data is now in workerLine.
//  }

// The next few messages are ones that my worker thread can post to me.
case WM_REQUESTINPUT:
        inputN = 0;
        displayPrompt();
        while (aheadOut != aheadIn)
        {   int ch = typeAhead[aheadOut];
            aheadOut = (aheadOut+1) % TYPEAHEADSIZE;
            if (ch == (0x1f & 'M'))
            {   inputLine[inputN++] = '\n';
                inputLine[inputN] = 0;
                showChar('\n');
                currentColour = TEXT_BLACK;
                HANDLE m2 = mutex2;
                ReleaseMutex(mutex1);
                WaitForSingleObject(m2, INFINITE);
                return 0;
            }
            inputLine[inputN++] = ch;
            currentColour = TEXT_RED;
            showChar(ch);
        }
        readRequestPending = 1;
        return 0;

case WM_PRINTCHAR:
        showChar(wParam);
        return 0;

case WM_PRINTBUFFER:
// This is pending!
        {   char *s = "<printbuffer>";
            while (*s != 0) showChar(*s++);
        }
        return 0;

case WM_WORKERQUIT: // the worker can send this to terminate the application
        SendMessage(hWnd, WM_CLOSE, 0, 0);
        return 0;

// Now handlers for some system messages that get treated in fairly
// standard manners.

case WM_COMMAND:
        wmId    = LOWORD(wParam);
        wmEvent = HIWORD(wParam);
        switch (wmId)
        {
    case IDM_HELP_ABOUT:
            DialogBox(g_hInst, (LPCTSTR)IDD_ABOUTBOX, hWnd, (DLGPROC)About);
            return 0;
    case IDM_ITEM_QUIT:
    case IDOK:
            SendMessage(hWnd, WM_CLOSE, 0, 0);
            return 0;
    default:
            return DefWindowProc(hWnd, message, wParam, lParam);
        }
case WM_CREATE:
        g_hwndCB = CreateRpCommandBar(hWnd);
        // Initialize the shell activate info structure
        memset(&s_sai, 0, sizeof(s_sai));
        s_sai.cbSize = sizeof(s_sai);
        return 0;
case WM_PAINT:
        RECT rt;
        hdc = BeginPaint(hWnd, &ps);
        if (hFont != 0) SelectObject(hdc, hFont);
        for (i=0; i<TEXTLINES; i++)
        {   int start = textLine[i],
                end = textLine[i+1];
            if (start == end) continue;
// Now the text that I need to draw may have to be drawn in several
// segments. There are two reasons for making a break: (a) the line can
// be represented by a sequence of chars that wrap around in the circular
// text buffer and (b) I may need to deal with colour effects
            x = 0;
            y = 16*i;
            int ch = text[start];
            while (ch != '\n' && ch != 0)
            {   int attstart = attribute(start);
                int next = start;
                int count = 0;
                while (ch != '\n' && ch != 0)
                {   next = (next + 1) % TEXTSIZE;
                    count++;
                    if (next == 0) break; // circular buffer wrap
                    int attnext = attribute(next);
                    if (attstart != attnext) break; // colour change
                    ch = text[next];
                }
                SetTextColor(hdc, colourTable[attstart]);
                ExtTextOut(hdc, x, y, 0, NULL,
                           &text[start], count, NULL);
// Note that to cope with cleartype fonts I do not use opaque chars.
// Thus I need to clear the background manually at some stage. I think
// that two times SHOULD suffice for that: (a) at the start of the 
// session and (b) clearing a row of stuff when I scroll the screen up.
                x += 7*count;  // I believe that my chars are 7 pixels wide
                start = next;
                ch = text[start];
            }
        }
        EndPaint(hWnd, &ps);
        return 0;
case WM_DESTROY:
        CommandBar_Destroy(g_hwndCB);
        if (hFont != 0) DeleteObject(hFont);
        PostQuitMessage(0);
        return 0;
case WM_ACTIVATE:
        // Notify shell of our activate message
        SHHandleWMActivate(hWnd, wParam, lParam, &s_sai, FALSE);
        return 0;
case WM_SETTINGCHANGE:
        SHHandleWMSettingChange(hWnd, wParam, lParam, &s_sai);
        return 0;
default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
}

HWND CreateRpCommandBar(HWND hwnd)
{
    SHMENUBARINFO mbi;
    memset(&mbi, 0, sizeof(SHMENUBARINFO));
    mbi.cbSize     = sizeof(SHMENUBARINFO);
    mbi.hwndParent = hwnd;
    mbi.nToolBarId = IDM_MENU;
    mbi.hInstRes   = g_hInst;
    mbi.nBmpId     = 0;
    mbi.cBmpImages = 0;
    if (!SHCreateMenuBar(&mbi))
        return NULL;
    return mbi.hwndMB;
}

// Message handler for the About box.
LRESULT CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    SHINITDLGINFO shidi;
    switch (message)
    {
case WM_INITDIALOG:
        // Create a Done button and size it.
        shidi.dwMask = SHIDIM_FLAGS;
        shidi.dwFlags = SHIDIF_DONEBUTTON | SHIDIF_SIPDOWN |
                        SHIDIF_SIZEDLGFULLSCREEN;
        shidi.hDlg = hDlg;
        SHInitDialog(&shidi);
        return TRUE;
case WM_COMMAND:
        if (LOWORD(wParam) == IDOK)
        {   EndDialog(hDlg, LOWORD(wParam));
            return TRUE;
        }
        break;
    }
    return FALSE;
}

void ce_getline()
{
    PostMessage(g_hWnd, WM_REQUESTINPUT, 0, 0);
    WaitForSingleObject(mutex1, INFINITE);
    memcpy(workerLine, inputLine, inputN);
    workerN = inputN;
    workerP = 0;
    HANDLE w = mutex1;
    mutex1 = mutex2;
    mutex2 = w;
    ReleaseMutex(mutex1);
// input data is now in workerLine.
}

extern "C"
{
extern int ce_readch();
extern void ce_print(char *s);
}

int ce_readch()
{
    if (workerN == workerP) ce_getline();
    if (workerN == workerP) return EOF;
    else return workerLine[workerP++];
}

void ce_print(char *s)
{
    while (*s != 0) PostMessage(g_hWnd, WM_PRINTCHAR, *s++, 0);
}

char *argvec[] =
{
    "csl",
    "-v",
    "-i",
    "\\IPAQ File Store\\reduce.img",
    NULL
};

extern "C"
{
extern int fwin_main(int argc, char *argv[]);
}

DWORD WINAPI WorkerProc(LPVOID parm)
{
    WaitForSingleObject(mutex2, INFINITE);
    int i;
    for (i=0; i<7; i++)
        ce_print("....:....*");
    ce_print("\n");
    ce_print("This is a message from the worker\n");
//  for (i=0; i<2; i++)
//  {   int ch = ce_readch();
//      char b[30];
//      sprintf(b, "Char %#.2x\n", ch);
//      ce_print(b);
//  }
//  ce_print("Done...\n");
// After finishing I will wait 4 seconds or until an ENTER before
// killing the application.
//  WaitForSingleObject(mutex1, 4000);
    ce_print("will now try to start fwin_main\n");
    fwin_main(4, argvec);
    ce_print("fwin_main returned: press ENTER to quit\n");
    ce_getline(); // wait for user to type ENTER
    WaitForSingleObject(mutex1, 1000); // then wait 1 second more
    PostMessage(g_hWnd, WM_WORKERQUIT, 0, 0);
    return 1;
}

// end of ipaq.cpp
