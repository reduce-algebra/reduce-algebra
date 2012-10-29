
/****************************************************************************

****************************************************************************/

#include "psllw.h"
#include  <stdio.h>
#include "winstruc.c"
#include "psllcall.h"
#include "string.h"

extern int input_mark;

#ifdef ALPHA
#define MY_LONG __int64
#define ADDRESSINGUNITSPERITEM 8
#else
#define MY_LONG long
#define ADDRESSINGUNITSPERITEM 4
#endif

int wait_input=0;
static int init_state=0;

long my_gets(char * buf);  
extern int  win_mode;
extern int slave_alife;
extern MY_LONG psl_callback1, psl_callback2, psl_callback3, psl_callback4;

MY_LONG bruch_bruch = 0;

static HWND hcaller=NULL;

FILE * DriFileFile; 
HBRUSH BackgroundBrush;

char szAppName[] = "Reduce";   // The name of this application

/****************************************************************************

    FUNCTION: WinMain(HANDLE, HANDLE, LPSTR, int)

    PURPOSE: calls initialization function, processes message loop

****************************************************************************/

LPSTR CmdLine;
MSG msg;

APIENTRY WinMain(hInstance, hPrevInstance, lpCmdLine, nCmdShow)
HINSTANCE hInstance;
HINSTANCE hPrevInstance;
LPSTR lpCmdLine;
int nCmdShow;
{
    MSG msg;

    CmdLine = lpCmdLine;

    if (hPrevInstance) return(FALSE);
     
    crack(CmdLine);

    if(min_mode()) nCmdShow = SW_MINIMIZE;
    
    if (!InitApplication(hInstance))
	    return (FALSE);

    if (!InitInstance(hInstance, nCmdShow))
	return (FALSE);
    
    if(!Catch(CatchBuf)) haupt(); 
    
PostQuitMessage(1);
    return (msg.wParam);
}

/* second part of initialization, to be performed after allocation of
   LISP memory 
      mode=1: batch mode
   */

init2(int mode,int kernel)
  {
      font_nr = get_profile_int("FONT",IDM_FONT_SYS);
      if (font_nr <= IDM_FONT || IDM_FONT_HI < font_nr) font_nr = IDM_FONT_SYS;    
      if (font_nr != IDM_FONT_SYS) 
	 { newfont(font_nr,0); get_geometry(0); }      
      init_state=2;
    
  }

/* third part of initialization, to be performed after loading the image */

init3()
  {
    char dir[128]; 
    int sm;
    psl_call(PSLCALL_RESIZE,wColumns,0,0); 
    get_profile_string("DIR","",dir,128);

    graphics_mode = get_profile_int("GRAPHICS_MODE",0);
    set_graphics_mode(graphics_mode);

    if(dir[0]) my_cd(dir,0);

    set_title();
    init_state=3;
  }


haupt()
  {
    int i,j;
    char zeile[100];

    DragAcceptFiles(hWnd,TRUE);
 
    win_mode = 1;
    psl_callback1 = 0;
    i = lisp_main(argc,argv); 
    close_all();  
    return(i);
  }

/* window: write string and sync */

wputs(char * str,long l)
  {
    prio_loop(0);
    while(l-- > 0) my_putc(*str++);
    my_flush();
    return(l);
  }


int do_win_loop = 1;
char * do_win_buf;
long do_win_lth;
int first_call=1;

long my_input(char buf[])
   {
     char c;

     if(first_call)
     { 
       first_call=0; 
       psl_call(PSLCALL_RESIZE,wColumns,0,0); 
     };
     input_to_slave(buf,do_win_lth=strlen(buf));
     return(1);
   }


// transaction processing: notify caller 

post_ready_message()
  {
    if (hcaller) PostMessage(hcaller,WM_SLAVE,13,(LPARAM)NULL);
    hcaller = NULL;
  }

static LPSTR lpszText;

	 /* process paste input */
paste_one_line()     
   { 
     char c,cc;

      if (hdef_input == NULL) return(0);

      if (!lpszText) 
	 {lpszText = GlobalLock(hdef_input);}

      if ( !lpszText) 
	 { warning("paste","impossible"); hdef_input=NULL; return(0);}      
      
      state = CALL;
     loop:
	   c=*lpszText++; 
	   if(c) PostMessage(hWnd,WM_CHAR,c,0); // do_char(cc=c); 
	   if(c && c != '\n') goto loop;
      if(c == '\0')
      { 
	GlobalUnlock(hdef_input);
	GlobalFree(hdef_input);
	prevent_caret = 0;
	state = LOOP;
	lpszText = NULL;
	hdef_input = NULL;
      } 

	// return T if line is complete
      return(cc=='\n'); 
   }

paste_all_lines()  // WN 1.1. 98   
   { while (hdef_input) paste_one_line();}


int win_loop()
  {
    while (GetMessage(&msg, (HWND)NULL, (UINT)NULL, (UINT)NULL)) 
    {   
	TranslateMessage(&msg);
	DispatchMessage(&msg);
    }
    return (msg.wParam);
}

int prio_loop(int n)
   {
     while (PeekMessage(&msg,hWnd,(UINT)NULL,(UINT)NULL,PM_NOREMOVE))
     {
       GetMessage(&msg, (HWND)NULL, (UINT)NULL, (UINT)NULL);
       TranslateMessage(&msg);

       if(msg.message == WM_PAINT) DispatchMessage(&msg);
	  else 
       /*       if(msg.message == 0x100) bruch_bruch = 1;   */
       if ((msg.message == WM_KEYDOWN) 
	    &&
	       (msg.wParam == 0x13 
	     || msg.wParam == 0x3
	     || msg.wParam == 0x90
	       )) { 
		    warning("terminal","interrupt");
		    if(n==1) return(0xfff);
		    psl_call(PSLCALL_TERMINAL_INTERRUPT,0,0,0);
		  }
     }
     return(1);
   }


win_quit(i)
   {
     warning("quit","quit");
     PostQuitMessage(i);
   }

switch_input_mode(int m)
   {
      wait_input = m;
	 // call the thread which owns the windows loop.
      PostMessage(hWnd,WM_USER+1,m,0);
   }

/****************************************************************************

    FUNCTION: InitApplication(HANDLE)

    PURPOSE: Initializes window data and registers window class

****************************************************************************/

BOOL InitApplication(HINSTANCE hInstance)
{
    WNDCLASS  wc;

    BackgroundBrush = CreateSolidBrush(GetSysColor(COLOR_WINDOW));
    if(!BackgroundBrush) BackgroundBrush = GetStockObject(WHITE_BRUSH); 

    wc.style          = CS_DBLCLKS; 
    wc.lpfnWndProc    = (WNDPROC)MainWndProc;
    wc.cbClsExtra     = 0;
    wc.cbWndExtra     = 0;
    wc.hInstance      = hInstance;
    wc.hIcon          = LoadIcon(hInstance,"psllwrIcon");
    wc.hCursor        = LoadCursor(NULL, IDC_ARROW);
    hArrow            = wc.hCursor;
    wc.hbrBackground  = (HBRUSH) (COLOR_WINDOW+1); 
    wc.lpszMenuName   = "psllMenu";
    wc.lpszClassName  = szAppName;

    return (RegisterClass(&wc));
}


/****************************************************************************

    FUNCTION:  InitInstance(HANDLE, int)

    PURPOSE:  Saves instance handle and creates main window

****************************************************************************/

BOOL InitInstance(hInstance, nCmdShow)
    HANDLE          hInstance;
    int             nCmdShow;
{


    TEXTMETRIC      textmetric;
    int             nLineHeight;
    LPSTR           b1;
    char            aux[20];
    int             i,j;

    hInst = hInstance;
  ///  LoadAccelerators(hInst,"EditMenuAcc");
    banner = "LISP";
  ///  b1 = banner;
  ///  while (*b1) {if (*b1 == '\\') banner = ++b1; else  b1++;};

    hWnd = CreateWindow(
    szAppName,
    banner,
	WS_OVERLAPPEDWINDOW | WS_VSCROLL,  /* horz & vert scroll bars */
	org_x = get_profile_int("WX0",CW_USEDEFAULT),
	org_y = get_profile_int("WY0",CW_USEDEFAULT),
	get_profile_int("WX1",CW_USEDEFAULT),
	get_profile_int("WY1",CW_USEDEFAULT),
	NULL,
	NULL,
	hInstance,
	NULL
    );

    if (!hWnd)
	return (FALSE);

    ShowWindow(hWnd,SW_SHOWNORMAL); // ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);

    hHourGlass = LoadCursor(NULL, IDC_WAIT);
    hPageCurs = LoadCursor(hInstance, "pageCursor");

    dcon();

    hFont = CreateFont(
	 8,   /* 10, */
	 0,   /* 8,  */
	 0,
	 0,
	 FW_NORMAL,
	 FALSE,
	 FALSE,
	 FALSE,
	 ANSI_CHARSET,
	 OUT_DEFAULT_PRECIS,
	 CLIP_DEFAULT_PRECIS,
	 DEFAULT_QUALITY,
	 FIXED_PITCH | FF_MODERN,
	 "system" 
	 );
    if (hFont) SelectObject(hDC, hFont);
       /* font geometry */
    GetTextMetrics(hDC, &textmetric);
    dcoff();
    nLineHeight = /* textmetric.tmExternalLeading + */ textmetric.tmHeight;
    cWidth = textmetric.tmMaxCharWidth;
    cHeight = nLineHeight;
      /* window geometry */

    get_geometry(0);
     

    my_prepare();
    font_nr = get_profile_int("FONT",IDM_FONT_SYS);
    font_size = get_profile_int("FONTSIZE",0);
    if (font_nr <= IDM_FONT || IDM_FONT_HI < font_nr) font_nr = IDM_FONT_SYS;

    newfont(font_nr,font_size,0);
    get_geometry(0);

    page_mode = get_profile_int("PAGE_MODE",0);

      /* prepare for dialog */
    init_state = init = 1;
    set_title();    
    IsActive = 1;
    return (TRUE);

}

//****************************************************************************

my_check(HMENU wParam,int tag,int mode)
  {
    if (mode)
	CheckMenuItem(wParam, tag, MF_CHECKED);
     else
	CheckMenuItem(wParam, tag, MF_UNCHECKED);
   }

my_enable(HMENU wParam,int tag,int mode)
  {
    if (mode)
	EnableMenuItem(wParam, tag, MF_ENABLED);
     else
	EnableMenuItem(wParam, tag, MF_GRAYED);
   }

//****************************************************************************/


LRESULT CALLBACK WINAPI  MainWndProc(hWnd, message, wParam, lParam)
HWND hWnd;
UINT message;
WPARAM wParam;
LPARAM lParam;
{
    FARPROC lpProcAbout;
    PAINTSTRUCT ps;                  /* paint structure              */
    char HorzOrVertText[12];
    char ScrollTypeText[20];
    RECT rect;
    int i,j;
    FARPROC lpFileDlg;
    int Success;                            /* return value from SaveAsDlg() */
    int IOStatus;                           /* result of file i/o      */
       
/*   
	if(init && message!=15 && message!=20)
	{   my_puts("mess");
	    my_putint((long)message);
	    my_puts(" ");
	    my_putoct((long)wParam);
	    my_puts(" ");
	    my_putoct(lParam);
	    my_puts("\n");
	}
*/

    caret(0);

  switch(message){

	case WM_INITMENU:
	    if ((HMENU)wParam == GetMenu(hWnd)) 
	    {
		if (OpenClipboard(hWnd)) 
		{
		    if (IsClipboardFormatAvailable(CF_TEXT)
			|| IsClipboardFormatAvailable(CF_OEMTEXT))
			EnableMenuItem((HMENU)wParam, IDM_PASTE, MF_ENABLED);
		    else
			EnableMenuItem((HMENU)wParam, IDM_PASTE, MF_GRAYED);
		    CloseClipboard();
		}    

		my_check((HMENU)wParam, IDM_GRAPHICS,graphics_mode);

		my_check ((HMENU)wParam, IDM_DRIBBLE, dribble);
		my_check ((HMENU)wParam, IDM_DRI_ON, dribble);
		my_check ((HMENU)wParam, IDM_DRI_OFF, !dribble);
		
		my_check ((HMENU)wParam, IDM_DRI_LINEW, dri_linew);
		my_check ((HMENU)wParam, IDM_AUTOCOPY, autocopy);
		my_check ((HMENU)wParam, IDM_STOREDIR, storedir);
		my_enable((HMENU)wParam, IDM_COPY, marked);
		my_enable((HMENU)wParam, IDM_CUT, marked && input_mark > -1);
		my_check ((HMENU)wParam, IDM_PAGE_MODE, page_mode);    
		
		for(i=IDM_FONT+1; i<=IDM_FONT_HI; i++)
		 { if(i == font_nr)
		      CheckMenuItem((HMENU)wParam,i,MF_CHECKED);
			else
		      CheckMenuItem((HMENU)wParam,i,MF_UNCHECKED);
		 };

	 for(i=10; i<=IDM_FONT_MAX; i=i+2)
		 { 
	     j = i-10 + IDM_FONT_10;
	     if(i == font_size)
			CheckMenuItem((HMENU)wParam,j,MF_CHECKED);
		      else
			CheckMenuItem((HMENU)wParam,j,MF_UNCHECKED);
		  };

	    }
	    return (TRUE);
     
	case WM_COMMAND:
	    switch (LOWORD(wParam)) {
		case IDM_ABOUT:
		    lpProcAbout = MakeProcInstance(About, hInst);
		    DialogBox(hInst, "AboutBox", hWnd, lpProcAbout);
		    FreeProcInstance(lpProcAbout);
		    break;

		case IDM_AUTOCOPY:
		   if(autocopy) autocopy=0; else autocopy=1;
		    break;

		case IDM_DRI_OFF:
		   dribble =0; break;

		case IDM_DRI_ON:
		   if(DriFile) { dribble = 1; break;}

		case IDM_DRI_FILE:
		   lstrcpy(FileName, DriFileName);
		   lpFileDlg = MakeProcInstance((FARPROC) FileDlg, hInst);
		   i = DialogBox(hInst, "DribbleFile", hWnd, lpFileDlg);
		   FreeProcInstance(lpFileDlg);
		   
		   if(i == IDOK)
		   { if(FileName[1] == ':')  /* absolute path? */
			lstrcpy(DriFileName, FileName);
		     else
			{i=0;
			 while(DriFileName[i] = dir[i]) i++;
			 DriFileName[i++] = '\\';
			 j=0;
			 while(DriFileName[i++] = FileName[j++]);
			}
		     if(!filep(DriFileName)
			|| yesp2(DriFileName,"overwrite existing file?"))
		     {DriFileFile = fopen(DriFileName,"w");
		       if(DriFileFile)
		       {fclose(DriFileFile); DriFile = -1;
			 dribble = 1;
		       } 
			else warning("DRIBBLE","cannot create file");
		     }
		       else
		     if(yesp2(DriFileName,"extend existing file?"))
			{ dribble = 1; DriFile = -1;}
		  } 
		  break;

		case IDM_DRI_LINEW:
		  if(dri_linew) dri_linew=0; else dri_linew = 1; break;

	case IDM_PRINT:
	  my_print(); break;

		case IDM_EXIT: 
		   if(DriFile>0) fclose(DriFileFile);
		   write_defaults();
		   kill_slave();
		   PostMessage(hWnd,WM_DESTROY,0,0);
		   exit(0);
		    
		   break;

		/* edit menu commands */

		case IDM_COPY: my_copy(); break;

		case IDM_CCOPY: copy_bitmap(); break; 

		case IDM_MCOPY: copy_metafile(); break;

		case IDM_PASTE:    my_paste(); paste_one_line(); break;
   
		case IDM_CUT:
		     if (!autocopy) my_copy();
		     char_delete(0);
		     break;
		case IDM_FONT_SYS:
		case IDM_FONT_ARIAL:
		case IDM_FONT_COURIER:
		case IDM_FONT_MODERN:
		case IDM_FONT_TIMES:
		   newfont(wParam,0,1); 
		   get_geometry(0); 
		   break;


		case IDM_FONT_10:
		case IDM_FONT_12:
		case IDM_FONT_14:
		case IDM_FONT_16:
		case IDM_FONT_18:
		case IDM_FONT_20:
		case IDM_FONT_22:
		case IDM_FONT_24:
		  newfont(0,10 + wParam - IDM_FONT_10,1);  
		  get_geometry(0); 
		  break;

		case IDM_PAGE_MODE: 
		     page_mode = ! page_mode; 
		     update_defaults = 1;    
		     break;

		case IDM_GRAPHICS: 
		     graphics_mode = ! graphics_mode; 
		     update_defaults = 1;    
		     set_graphics_mode(graphics_mode);  
		     break;
 
       case IDM_SHOW_F: show_f_keys(); break;

       case IDM_F1: case IDM_F2: case IDM_F3: case IDM_F4:
       case IDM_F5: case IDM_F6: case IDM_F7: case IDM_F8:
       case IDM_F9: case IDM_F10: case IDM_F11: case IDM_F12:
	     define_F_key(wParam-IDM_F1+1);
	     break;

		case IDM_HELP: 
		     help_menu();
		     break;
		
		case IDM_MODES:
		     win_params[0] = 1;
		     psl_call(PSLCALL_MENU,wColumns,0,0);
		     break;
 
		default:
	     if (IDM_HELP < wParam && wParam < IDM_HELP+100) help_do(wParam);
	
	     return (DefWindowProc(hWnd, message, wParam, lParam));

	    }; 
	    InvalidateRect(hWnd,NULL,TRUE);
	    break;

     
	case WM_MOUSEMOVE:
	    if (mausdruck) move_pick(LOWORD(lParam),HIWORD(lParam),0);
	    break;

	case WM_RBUTTONDOWN:
	case WM_MBUTTONDOWN: my_paste(); paste_one_line(); break;

	case WM_LBUTTONDOWN:
	    if (mausdruck == -1) {mausdruck =0; } else {  // WN 1.1. 98
	    mausdruck = 1;
	    prevent_caret=1;
	    start_pick(LOWORD(lParam),HIWORD(lParam)); }
	    break;

	case WM_LBUTTONUP:
	    prevent_caret=0;
	    if(mausdruck)
	      {mausdruck=0;
	       move_pick (LOWORD(lParam),HIWORD(lParam),1);
	      }
	    end_pick();
	    break;

	case WM_SETFOCUS: mausdruck = -1; break;  //WN 1.1.98
 
	case WM_SYSCHAR:
	    if (!wait_input) return(0); 
	    SetFocus(hWnd);  /* 27.3. neu */
	    if((lParam>>16) & 0x20) 
	      {
		SetFocus(hWnd);
		goto char_in;
	      }
	      break;

	case WM_KEYDOWN:
	    if(wParam == 0x13) break_slave();
	      else
	    if(0x70 <= wParam && wParam<=0x7b && wait_input)
	     { paste_f_key(wParam-0x70+1); paste_one_line();}
	    else
	    if(wParam==0x11) ctrl=1;
	      else
	    if ((wParam == 0x8 || (0x1b <= wParam && wParam <= 0x2e)) && wait_input)
		    cursorKey(wParam);
	    break;

	case WM_KEYUP:
	    if(wParam==0x11) ctrl=0;              
	    break;

	case WM_CHAR: 
	    if (!wait_input) return(0); 
		 caret(0);
 	    /* 21.7.93 neu */
		{ unsigned char c;
		c = (unsigned char)wParam;
		if (c == 0x03)  /* Ctrl C */   {my_copy(); break; };
		if (c == 0x16)  /* Ctrl V */   {my_paste(); paste_one_line(); break; };
		if (c == 0x18)  /* Ctrl X */
				  { if (!autocopy) my_copy(); char_delete(0); break; };
	       	if (c == 0x7)   /* Ctrl G */
	   		  		wParam = 0x1b;  /* Esc, transferred to LISP */
	       	if (c == 0x1b)  /* Esc - already handled by KEYDOWN */
	    	 break;
	 }
  
      char_in:
		 caret(0);
		 ctrl = 0;
		 prevent_caret = 0;
		 page_count = 0;
		 state = CALL;
		 if(HIWORD(lParam) == 0x1c) 
		    { 
		      i = do_char('\n');
		      if(dribble && DriFile>0) 
			{ fclose(DriFileFile); DriFile=-1;}
		    }
		   else do_char((unsigned char)wParam);
		 state = LOOP;
		 if(wait_input) caret(1);
	    break;

	case WM_VSCROLL:
	     scrollbar(wParam,lParam);
	     break;

	case WM_PAINT:
	    hDC = BeginPaint (hWnd, &ps);
 	    if(!during_scroll || !(hWnd==GetForegroundWindow()))
         /* WN 2.1.98    We need to find out whether
	the window is focussed or not. If not, it looks ugly */
	    {SetBkMode(hDC,TRANSPARENT);
	     if (act_show == act_line) my_refresh(); 
	     else  my_showpage(act_show);
	    }
	    EndPaint(hWnd, &ps);
	    break;
	
	case WM_DESTROY:
	     prevent_caret=1;
	     write_defaults();
	     delete_all_objects();
	     my_pexit();
	     PostQuitMessage(0);
	    break;

	case WM_ACTIVATE:
	    if(init)
	       {if(wParam == 0) 
		  {SetWindowText(hWnd,banner); 
	   de_select_ext();                  /* 8.5.93 neu */
		   caret(0);
		   IsActive = 0;
		  }                       
		       else 
		  {
		   if (!IsActive) set_title(); 
		   IsActive = 1;
		   SetFocus(hWnd);
		  }
	       };
	  /*  return (DefWindowProc(hWnd, message, wParam, lParam));    */
	     break;
	    

	case WM_SIZE:
	     wscreenmode = wParam;
	     if(wParam!=SIZEICONIC && wParam!=SIZE_MINIMIZED)
	     {  get_geometry(1); 
	    InvalidateRect(hWnd,NULL,TRUE);
		    psl_call(PSLCALL_RESIZE,wColumns,0,0); 
		    caret_y = act_y;
	     }
	     break;

	case WM_MOVE:
	     org_x = LOWORD(lParam); org_y = HIWORD(lParam);
	     get_geometry(1);
	     break;

	case WM_SLAVE:
	     // external call
	     if (wParam==0)   // transaction start: supply callers window handle 
		    hcaller = (HWND)lParam;  
	       else 
	     if (wParam==1)   // execute one computation 
		    GlobalGetAtomName((ATOM)lParam,(LPSTR)ahead_buf,256);
	     break;

	case WM_DROPFILES:
	     if(DragQueryFile((HANDLE)wParam,-1,NULL,(UINT)0) != 1)
		warning("Drop file","can accept only one file");
	     else if(i=DragQueryFile((HANDLE)wParam,0,FileName,(UINT)128)>0)
	      { 
		lstrcpy(ahead_buf,"in \"");
		lstrcat(ahead_buf,FileName);
		lstrcat(ahead_buf,"\"$\n");
	      }
	     DragFinish((HANDLE)wParam);
	     ShowWindow(hWnd,SW_SHOWNORMAL);
	     SetForegroundWindow(hWnd);
	     break;

	case WM_SYSCOLORCHANGE:
	     DeleteObject(BackgroundBrush);
	     BackgroundBrush = CreateSolidBrush(GetSysColor(COLOR_WINDOW));
	     break;

	case WM_USER+1:
	     if(wParam && init_state<3) init3();
	     break;  // just do the standard end handling.

	default:
	  def:
	    
	    return (DefWindowProc(hWnd, message, wParam, lParam));
    }
      
     /* process eventual deferred input */
    if(!during_scroll && ahead_buf[0])
    { char c; int l; 
      l = lstrlen(ahead_buf);
      state = CALL;
      for(i=0;i<l;i++) { c = ahead_buf[i]; ahead_buf[i] =0 ; do_char(c);}
      state = LOOP;
      ahead_buf[0]=0;
    };
	     
    if(!during_scroll  
	&& hWnd==GetFocus()      
	&& wait_input) 
       caret(1);

exit:
    return (0);
}

scrollbar(UINT wParam,UINT lParam)                                 
  { if(act_line > wLines)
    switch(LOWORD(wParam))
   {
	case SB_BOTTOM:     my_showpage(act_line); break;
	case SB_LINEDOWN:   my_movepage(1); // my_showpage(act_show + 1); 
			    break;
	case SB_LINEUP:     my_movepage(-1); // my_showpage(act_show - 1); 
			    break;
	case SB_PAGEDOWN:   my_showpage(act_show + wLines); break;
	case SB_PAGEUP:     my_showpage(act_show - wLines); break;
	case SB_THUMBPOSITION:
			    my_showpage(lParam); break;
	case SB_TOP:        my_showpage(wLines);
  }}

/****************************************************************************

    FUNCTION: About(HWND, UINT, UINT, LONG)

    PURPOSE:  Processes messages for "About" dialog box

    MESSAGES:

	WM_INITDIALOG - initialize dialog box
	WM_COMMAND    - Input received

****************************************************************************/

BOOL WINAPI About(hDlg, message, wParam, lParam)
HWND hDlg;
UINT message;
UINT wParam;
LONG lParam;
{
    switch (message) {
	case WM_INITDIALOG:
	    return (TRUE);

	case WM_COMMAND:
	    if (wParam == IDOK) {
		EndDialog(hDlg, TRUE);
		return (TRUE);
	    }
	    break;
    }
    return (FALSE);
}

error(char * txt)
  {
    warning("ERROR:",txt);
    PostQuitMessage(0);
    Throw(CatchBuf,1);
  }


TerminalInterrupt()
  {
    psl_call(PSLCALL_TERMINAL_INTERRUPT,0,0,0);
  }

set_graphics_mode(char m)
{
 if(m) psl_call(PSLCALL_GRAPHICS_MODE_ON,0,0,0);
  else psl_call(PSLCALL_GRAPHICS_MODE_OFF,0,0,0);    
}

psl_call(int a,int b,int c,int d)
  {
    psl_callback1 = psl_callback1 | (1L << a);
    psl_callback2 = b;
    psl_callback3 = c;
    psl_callback4 = d;
    if(slave_alife) p_callback();
  }
