#include <windows.h>
#include "pcommon.h"

#ifndef WINAPI
#define  WINAPI FAR PASCAL
#else
#include <setjmp.h>
#define CATCHBUF jmp_buf
#define Throw longjmp
#define Catch setjmp
#endif

#ifndef UINT
#define UINT unsigned int
#endif

int WINAPI WinMain(HANDLE, HANDLE, LPSTR, int);
BOOL InitApplication(HANDLE);
BOOL InitInstance(HANDLE, int);
long WINAPI MainWndProc(HWND, UINT, UINT, LONG);
BOOL WINAPI About(HWND, UINT, UINT, LONG);

BOOL yesp(LPSTR);
BOOL yesp2(LPSTR,LPSTR);
BOOL filep(LPSTR);
     warning(LPSTR,LPSTR);
    iwarning(LPSTR,long);
int WINAPI YespDlg(HWND, UINT, UINT, LONG);
int WINAPI HelpDlg(HWND, UINT, UINT, LONG);

dumpo(LPSTR,int);
long help(long,LPSTR);

#define LOOP 0
#define CALL 1


/*----------------------------------------------------------------*/

TextOutProp(HDC hDC,int x,int y,LPSTR s,int lth);
TextOutFix(HDC hDC,int x,int y,LPSTR s,int lth);

#define PROFILE "PSLLW"
