/* #include "windows.h"  */
#include "psllw.h"
#include "dde.h"
#include "winext.h" 
// #include <unistd.h>
#include <string.h>

#ifdef WIN32
#include "psllcall.h"
#include <stdio.h>
extern int script_mode;
extern FILE * DriFileFile;
#else
#define script_mode 0
#endif

#define LEADX 2

HFONT load_font(char * name,int pitch,int size,int nr);
HFONT load_symb_font(int pitch,int fat);
static void        delete_fonts();
void               ScriptInName(LPSTR);
extern HWND hpipe[];
extern HBRUSH BackgroundBrush;

int transparent=1;
int cLeadSymb=0;
int cLeadProp=0;
int old_sel_y, old_s_y;

       HMENU Hpsl_menu=NULL;
static HMENU Hhelp_menu=NULL;
static HMENU fk_menu=NULL;

static HANDLE metafile=NULL;

void mach_schwarz(int x,int y);
void mach_weiss();

int input_mark=-1;
int input_marklength=0;

void delete_all_objects()
   {
    int i;
    for(i=0;i<MAXPIPE;i++) pipe_close(hpipe[i]);
    delete_fonts();
    if(Hpsl_menu) DestroyMenu(Hpsl_menu); Hpsl_menu = NULL;
    if(Hhelp_menu) DestroyMenu(Hhelp_menu); Hhelp_menu = NULL;
    if(fk_menu) DestroyMenu(fk_menu); fk_menu = NULL;
    if(metafile) DeleteMetaFile(metafile);
    DestroyCaret();
   }


get_geometry(int save)
  {
    RECT rect; DWORD w;

    if(cHeight==0) return(0);
    if (!IsIconic(hWnd)) GetClientRect(hWnd,&rect);
    else { rect.left = 0; rect.top = 0;
	   rect.right = 800; rect.bottom = 600;}
    wpLines = rect.bottom - rect.top - 15;
    wLines = wpLines / cHeight;
    wpColumns = rect.right - rect.left - 5;
    wColumns = wpColumns / cWidth;
    wColumns = min(99,wColumns);
    if (save && !script_mode) update_defaults = 1;
  }

local_linelength()                /* 5.1.94 using prop font 0 */
  { 
    int l;
    l = wpColumns / font_width[0];
    l = (l * 95)/100;
    return(l); 
  }

/* Device Context */

dcon()
  { 
    int r;
    if(!during_paint && !has_DC) 
       { hDC = GetDC(hWnd); r=1; has_DC = 1;}  else r=0;
    if (hFont) SelectObject(hDC, hFont);
    /* if (insert !=0) */    /* 28.9.93 */ 
    SetBkMode(hDC,TRANSPARENT);
    SetTextColor(hDC,GetSysColor(COLOR_WINDOWTEXT));
    SetBkColor(hDC,GetSysColor(COLOR_WINDOW));
    transparent = !insert;
    return(r);
  }

dcoff()
  { 
    if(!during_paint && has_DC) 
      {
	ReleaseDC(hWnd, hDC); 
	has_DC = 0;
      }
  }

mySetBkMode(int m)
   {
     if(m == TRANSPARENT) transparent = 1;
	     else         transparent = 0;
   }

/* FONT resources */

static void delete_fonts()
   {
    if(hFont) DeleteObject(hFont); 
    if(font[0]) DeleteObject(font[0]);
    if(font[1]) DeleteObject(font[1]);
    if(symb_font[0]) DeleteObject(symb_font[0]);
    if(symb_font[1]) DeleteObject(symb_font[1]);
    hFont = font[0] = font[1] = symb_font[0] = symb_font[1] = NULL;
   }

char * font_name(int nr)
   {
     if(nr == IDM_FONT_COURIER)  return("courier new"); else
     if(nr == IDM_FONT_MODERN)   return("modern"); else
     if(nr == IDM_FONT_TIMES)    return("times new roman");  else
     if(nr == IDM_FONT_ARIAL)    return("arial"); else
     if(nr == IDM_FONT_SYS)      return("system");
   }

LOGFONT toload;

int CALLBACK protz (ENUMLOGFONT FAR* lpelf,int a,int type,LPARAM par)
  {
    if (strcmp(lpelf->elfFullName,"Symbol") == 0)
     toload = lpelf->elfLogFont; }

newfont(int nr,int size,int save) 
   { int i,j;
     char c;
     char * s;
     HFONT f,font2;
     TEXTMETRIC      textmetric; 
     int sec = 0;
     int fat =0;
 
    caret(0);
    toload.lfHeight = NULL;
    if(nr) font_nr = nr;
    if(size) font_size = size;
    if(!font_nr) font_nr = IDM_FONT_SYS;
    if(!font_size) font_size = 14;
    nr = font_nr;
    size = font_size;
    psl_msg = psl_msg | PSL_RESIZE;    

    if(nr == IDM_FONT_TIMES || nr == IDM_FONT_SYS) fat = 1;

    f = load_font(font_name(nr),FIXED_PITCH,size,nr);
    if(!f) {iwarning("cannot find font",font_name(nr)); return(0);}
    delete_fonts();
    hFont=f;
    
    if(save) update_defaults = 1;
    
    dcon();
       /* font geometry */
    GetTextMetrics(hDC, &textmetric);
    dcoff();
    caret_x = caret_x / cWidth; 
    /* caret_y = caret_y / cHeight; */
    cLead = max(0,textmetric.tmInternalLeading-LEADX);
    cHeight = textmetric.tmHeight  - cLead;
    cLeadProp = cLead;
    cWidth = textmetric.tmMaxCharWidth;
    if (nr == IDM_FONT_SYS) size=cHeight;  /* size of system font */

       /* set as default font */
    font[0] = hFont;
    font_height[0] = cHeight;    
    font_width[0] = cWidth;
    font[1] = hFont;
    font_height[1] = cHeight;    
    font_width[1] = cWidth;
 
       /* select an additional fixed font for roman, arial */
    if(nr == IDM_FONT_TIMES || nr == IDM_FONT_ARIAL)
    {
       if(nr == IDM_FONT_TIMES) hFont = load_font("system",FIXED_PITCH,size,0);
		      else      hFont = load_font("modern",FIXED_PITCH,size,0);   
       dcon();
	  /* font geometry */
       GetTextMetrics(hDC, &textmetric);
       dcoff();      
       cLead = max(0,textmetric.tmInternalLeading-LEADX);
       cHeight = textmetric.tmHeight  - cLead;
       cWidth = textmetric.tmMaxCharWidth;
    }
       /* put caret in right place */
    caret_x = caret_x * cWidth;  
   /* caret_y = caret_y * cHeight; */ 
     
 /* load secondary and proportional fonts   */

    EnumFontFamilies(hDC,0,protz,0);

    if(toload.lfHeight == NULL)
    symb_font[0] = (symb_font[1] = load_symb_font(size,fat)); 
    else {
  /*   if Enum found something*/
    
    if(fat == 0) toload.lfWeight =  700;
	 else toload.lfWeight =  FW_NORMAL;
    toload.lfHeight = - size;
    toload.lfWidth = (size *3)/4;
    symb_font[0] = (symb_font[1] = CreateFontIndirect(&toload));
	 }
    SelectObject(hDC,symb_font[0]);

    GetTextMetrics(hDC, &textmetric);
    cLeadSymb = max(0,textmetric.tmInternalLeading-LEADX);

    if(nr != IDM_FONT_SYS) 
    { 
      if(size>15) size = size-3; else size = size-2;
      font[1] = load_font(font_name(nr),FIXED_PITCH,size,nr);
      dcon();
      SelectObject(hDC,font[1]);
      GetTextMetrics(hDC, &textmetric);
      dcoff();
      font_height[1] = textmetric.tmHeight - cLead;
      font_width[1] = textmetric.tmMaxCharWidth;
      symb_font[1] = load_symb_font(size ,fat);
    }
    if(nr == IDM_FONT_TIMES)
    {  /* times: smaller average width */
      font_width[0] = font_width[0]/2;
      font_width[1] = font_width[1]/2;
    };
    InvalidateRect(hWnd,NULL,TRUE);  
   }
    

HFONT load_font(char * name,int pitch,int size,int nr)
   {
    HFONT fnt;
    int wgt=FW_NORMAL;
 
    if(size>=15 && nr==IDM_FONT_COURIER || nr==IDM_FONT_MODERN) wgt = FW_BOLD;
    
    if(font_nr == IDM_FONT_MODERN) pitch = pitch | FF_MODERN;

    fnt = CreateFont(
	 -size , 
	 0  , 
	 0,
	 0,
	 wgt,
	 FALSE,
	 FALSE,
	 FALSE,
	 ANSI_CHARSET,
	 OUT_DEFAULT_PRECIS,
	 CLIP_DEFAULT_PRECIS,
	 DEFAULT_QUALITY,
	 pitch,    /* | FF_MODERN,  */
	 name
	 );
	    
    if(!fnt) iwarning("font not found:",name);
    return(fnt);
    }

// static HFONT loaded = 0;

HFONT load_symb_font(int pitch,int fat)    
  {
    HFONT fnt;
   // if (loaded) return (loaded);

    if(fat) fat=700; else fat=FW_NORMAL;
    /* fat = FW_NORMAL; */
    fnt = CreateFont(
	 - pitch,
     (pitch*3)/4,  /* not 0: otherwise characters too narrow */ 
	 0,
	 0,
	 fat, 
	 FALSE,
	 FALSE,
	 FALSE,
	 SYMBOL_CHARSET,
	 OUT_TT_ONLY_PRECIS,
	 CLIP_DEFAULT_PRECIS,
	 DEFAULT_QUALITY,
	 FIXED_PITCH ,
	"Symbol"
	 ); 
     if(!fnt) iwarning("greek font not found:",fnt);
    // loaded = fnt;
     return(fnt);
   }

/* Copy Paste */

my_paste()
      {
      LPSTR lpszText;
      char c;
      int i,l;

    if (OpenClipboard(hWnd)) {
	/* get text from the clipboard */
	if (!(hClipData = GetClipboardData(CF_TEXT))) {
	    CloseClipboard();
	    return(0);	}

	l =  GlobalSize(hClipData);

	if (hText != NULL) {GlobalFree(hText);}
	if (!(hText = GlobalAlloc(GMEM_MOVEABLE,l)))
		       {    warning("paste","OutOfMemory");
			    CloseClipboard();
			    return(0);	}
	
	if (!(lpszText = GlobalLock(hText)))       
		       {  warning("paste","no lock");
			  CloseClipboard();
			  return(0);     }

	if (!(lpClipData = GlobalLock(hClipData))) {
			    warning("paste","noClipData");
			    CloseClipboard();
			    return(0);	}

	lstrcpy(lpszText,lpClipData);
	
	GlobalUnlock(hClipData);
	CloseClipboard();
	GlobalUnlock(hText);
	hdef_input = hText;
	hText = NULL;
	return (TRUE);
		    }
    else
	return (FALSE);
	    }

RECT rect;

start_pick(int x,int y)
   { 
     input_mark = -1;
     dcon();
     x = x/cWidth;
     y = y/cHeight;
     mach_weiss();
     mach_schwarz(x,y);
     s_x = sel_x = x;
     s_y = sel_y = y;
   }

void move_pick(int x,int y,int m)
   { int xx,yy;
  
     if(sel_y<0) return;                          /* 8.5.93 */

     x = x/cWidth;
     y = y/cHeight;
      
	/*move backwards: renew selection */
     if(y<s_y || (y==s_y && x<s_x) || y<sel_y)   /*8.5.93 */ 
     {
      mach_weiss();  
      s_x = sel_x; s_y = sel_y;
      mach_schwarz(s_x,s_y);
	     /*ignore movement beyond starting point */
      if(y<sel_y || y==sel_y && x<sel_x) return; 
     }
     for(yy=s_y;yy<=y;yy++)
      for(xx=0;xx <wColumns;xx++)
       if ( (xx > s_x || yy > s_y)
	      &&(xx <= x || yy < y)  )
	    mach_schwarz(xx,yy);
     s_x = x;
     s_y = y;
     if(m==0) return;
     marked = 1;
     old_sel_y = sel_y; old_s_y = s_y;
    /* if(autocopy) my_copy();                           8.5.93 auskommentiert */
   }

void de_select()                                      /* 8.5.93 neu */
  {
     mach_weiss();
     input_mark = -1;
     s_x = sel_x = s_y = sel_y = -1;
     marked = 0;
  }
    
void de_select_ext()
  {
    dcon();
    de_select();
    dcoff();
   }

void end_pick()
   {
			
	       /* 20.7.93  , 19.1.94 */
     if(// s_x==sel_x &&         // 8.2.94 
	   s_y == sel_y && s_y*cHeight == act_y)
     {   /* position cursor in input line */
      cursor_to_end();
      while(i_ptr >0 && caret_x > sel_x*cWidth)
	    { i_ptr--; caret_x = caret_x - cWidth;};
      input_mark = i_ptr;
      input_marklength = s_x-sel_x+1;
     }   

    if(!marked) return;
    if(s_x<=sel_x && s_y <= sel_y) de_select();
	else 
     if(autocopy) my_copy();
     dcoff();
   }


dbl_pick(int x,int y,int m)
   { int b;
     b = max(0,act_line - wLines +1); /* base */
     s_x = sel_x = x;
     s_y = sel_y = y;
     my_showpage(act_show);
     mach_schwarz(x,y);
     if(wordp(lpuffer[x][b+y]))
     {
	while(sel_x>0 && wordp(lpuffer[b+y][sel_x-1]) )
	    {sel_x--; mach_schwarz(sel_x,y);}
	while(s_x<wColumns && wordp(lpuffer[b+y][s_x+1]) )
	    {s_x++; mach_schwarz(s_x,y);}
     }
     marked = 1;
     if(autocopy) my_copy();
   }

int wordp(char c)
   {return ( ('A' <= c && c <= 'Z')
	   ||('a' <= c && c <= 'z')
	   ||('0' <= c && c <= '9')
	   ||(c == '_') );}

void mach_schwarz(int x,int y)
  {  x = x*cWidth;
     y = y*cHeight;
     rect.top = y;
     rect.bottom = y + cHeight;
     rect.left = x;
     rect.right = x + cWidth;
     InvertRect(hDC,&rect);
   }

void mach_weiss()
  /* give up current selection */
  { int xx,yy; 
   for(yy=sel_y;yy<=s_y;yy++)
      for(xx=0;xx <wColumns;xx++)
       if ( yy >= 0
	  &&(xx >= sel_x || yy > sel_y)
	      &&(xx <= s_x || yy < s_y)  )
	    mach_schwarz(xx,yy);
    marked = 0;
  }

my_copy()
	  {
    LPSTR lpData;
    int l,b,xx,yy;
    HANDLE hData;
    char c;
    int do_it;

    if(!marked || s_y<0) return(0);
    
       /* compute length of text */
    if (sel_y == s_y) l = s_x - sel_x +1;
	else          l = wColumns - sel_x +3              /* first line */
			+ (s_y - sel_y -1)*(wColumns+3)    /* full lines */
			+ s_x +1;                          /* last line  */
    if (l<=0) return(0);

	/* Allocate memory and copy the string to it */
    if (!(hData = GlobalAlloc(GMEM_MOVEABLE, l+1))) 
       { warning("Copy:","out of Memory"); return (TRUE);} 
    if (!(lpData = GlobalLock(hData))) 
       {warning("copy:","lock data");return (TRUE);}
	/* move character to data buffer */
    /* b = max(0,act_show - wLines +1); /* base */ 
    b = bLine;
    for(yy=sel_y;yy<=s_y;yy++)
     {for(xx=0;xx <wColumns;xx++)
       if ( (xx >= sel_x || yy > sel_y)
	  &&(xx <= s_x || yy < s_y)  )
	    /* 23.7.93*/
       {        
	if (b+yy == act_line && xx >= o_ptr)
	     { c=ipuffer[xx-o_ptr]; do_it = 1;}
	  else
	     { c=lpuffer[b+yy][xx]; 
	       do_it = !line_empty(lpuffer[b+yy],xx,wColumns);
	     }
	if(do_it) *lpData++ = c;
       } 
     if(yy<s_y){*lpData++ = 0xd; *lpData++ = 0xa;} 
     };
    *lpData++ = '\0';
    GlobalUnlock (hData);

	/* Clear the current contents of the clipboard, and set
	 * the data handle to the new string.
	 */

     if (OpenClipboard(hWnd)) {
	    EmptyClipboard();
	    SetClipboardData(CF_TEXT, hData);
	    CloseClipboard();
	} else warning("unable","to set Clipboard");
     hData = NULL;        
    }

line_empty(char lpuffer[],int xx,int wc)
   {
     int i=1; char c;
  loop:
     c = lpuffer[xx];
     if (c == '\0' || xx >= wc) return(1);
     if (c != ' ') return(0);
     xx++;
     goto loop;
   }  

copy_bitmap()
   /* copy to clipboard in bitmap format */
		{
		   RECT rect;
		   HBITMAP bitmap;
		   HDC mem;
	   int q;

		   BringWindowToTop(hWnd);
		   UpdateWindow(hWnd); 
		      /* get the context */
		   dcon();
		   GetClientRect(hWnd, &rect);

	   if(marked)
	   {    
	     mach_weiss(); 
	     q = rect.top;
	     rect.top = q + max(sel_y * cHeight,0);
	     rect.bottom = q + (s_y+1) * cHeight;
	   }
	       
		   mem = CreateCompatibleDC(hDC);
		   bitmap = CreateCompatibleBitmap(hDC, 
				rect.right - rect.left,
				rect.bottom - rect.top+1);
		   if (bitmap)
		   {
		     SelectObject(mem, bitmap);
		     BitBlt(mem,0,0,rect.right - rect.left,
		       rect.bottom - rect.top+1, hDC, rect.left, rect.top, 
			SRCCOPY);
		     DeleteDC(mem);
		     OpenClipboard(hWnd);
		     EmptyClipboard();
		     SetClipboardData(CF_BITMAP, bitmap);
	     CloseClipboard();
		   }
			 else warning("clipboard","insuficient memory");
	   dcoff();
		   return 0;
	       }

main_reset()
     {  
	hSaveCursor = hArrow;
	SetCursor(hArrow);
     }

#ifdef WIN32

dribble_line(char * l,int i,int cls)
     {

	if(DriFile<0)
	  { DriFileFile = fopen(DriFileName,"a");
	    if(!DriFileFile) warning("dribble","cannot open file");
	  }
	fwrite(l,(long)i,1,DriFileFile);
	fwrite("\015\012",(long)2,1,DriFileFile);
	if(cls || dri_linew)
	  { fclose(DriFileFile); DriFile = -1;}
     }

#else

dribble_line(char * l,int i,int cls)
     { 
	
	if(DriFile<0) 
	  { DriFile = _lopen((LPSTR) DriFileName,OF_WRITE);
	    _llseek(DriFile,(long)0,2);      /* go to the end */
	    if(!DriFile<0) warning("dribble","cannot open file");
	  }
	_lwrite(DriFile,(LPSTR)l,i);
	_lwrite(DriFile,(LPSTR)"\015\012",2);
	if(cls || dri_linew) 
	  { _lclose(DriFile); DriFile = -1;}
     }

#endif


clear_rect(int x0,int y0,int x1,int y1)
  {
     HRGN rgn;

     if(y0<0) y0=0;
     rgn=CreateRectRgn(x0,y0,x1,y1);
     FillRgn(hDC,rgn,BackgroundBrush);  
     DeleteObject(rgn);
  }

clear_screen()
  {
    int d;
    RECT rect;

    d=dcon();
    rect.left = 0; rect.top = 0;
    rect.bottom = wpLines+15; rect.right = wpColumns+5;
    FillRect(hDC,&rect,BackgroundBrush);
    if(d) dcoff();
  }

/*-------------------------  psl menu service--------------------*/

int menu_i=0;

int psl_menu(long m1, LPSTR m2, long m3)
 {
    RECT rect; 
    MSG msg;
    int r = -1,m;

   if (m1==0)
   {
      // fresh menu
      if (Hpsl_menu) DestroyMenu(Hpsl_menu);   Hpsl_menu = NULL;
      if (Hhelp_menu) DestroyMenu(Hhelp_menu); Hhelp_menu = NULL;
      Hpsl_menu = CreatePopupMenu();
      AppendMenu(Hpsl_menu,MF_STRING | MF_DISABLED,IDM_HELP,m2);
      AppendMenu(Hpsl_menu,MF_SEPARATOR,NULL,NULL);
      menu_i=IDM_HELP;
   }
   else if (m1==1)
   { 
      // exend menu
      menu_i++;
      AppendMenu(Hpsl_menu,MF_STRING, menu_i, m2);
      if(m3 == 1) CheckMenuItem(Hpsl_menu, menu_i, MF_CHECKED);
   }
   else if (m1==2)
   { 
      //activate menu   
      GetWindowRect(hWnd,&rect);
      TrackPopupMenu(Hpsl_menu,0,rect.left+100,rect.top+20,0,hWnd,NULL);
 
      WaitMessage();

      if(PeekMessage(&msg,NULL,WM_COMMAND,WM_COMMAND,PM_REMOVE) 
		&& (m=LOWORD(msg.wParam)) > IDM_HELP && m <= menu_i)
			    r=LOWORD(msg.wParam)-IDM_HELP;
#ifdef WIN32
      DestroyMenu(Hpsl_menu);
#endif
      return (r);
   }
 }

/*-------------------------  help system entry ---------------------*/


void MakePathName(FileName,extens)
char * FileName; char * extens;
{
  file_tree();
   lstrcat(FileName,extens);
}

psl_help (int mode, LPSTR topic)
  {
    MakePathName(FileName,"\\help\\help.hlp");
/*    
    if (mode == 0) WinHelp(hWnd,FileName,HELP_INDEX,0L);
	 else  WinHelp(hWnd,FileName,HELP_KEY,(DWORD)topic);
*/  
   
  WinHelp(hWnd,FileName,HELP_INDEX,0L);
  } 


int help_file=0;

help_open_file()
  {  
     MakePathName(FileName,"\\help\\helpdir");
     help_file=_lopen(FileName,OF_READ);
     if(help_file == -1 ) 
      {lstrcpy(FileName,getenv("helpdir"));
       help_file= _lopen(lstrcat(FileName,"\\helpdir"),OF_READ);}
     if(help_file == -1) 
	iwarning("Cannot open help control file",help_file);
     return(help_file);
  }

help_read_char()
  {
     char c=0;
     _lread(help_file,&c,1);
     return(c);
  }

help_close_file()
  {
     _lclose(help_file);
  }

help_read_type()
  {
    char c='1';
    while (c && (c != 'H' && c!= 'B')) c=help_read_char();
    return(c);
  }

LPSTR help_read_item()
  {
   int i=1; char c,t;
   t='\0';
   buffo[0] = '\0';
   while((c=help_read_char()) && c<=' ');
   if (c=='"') {t=c;c=help_read_char();}
   buffo[0]=c;
   while((c=help_read_char()) 
	  && (c>='.' ||  (t && c!=t)))
	      buffo[i++]=c;
   buffo[i] = '\0';
   return((LPSTR)buffo);
  }
	
help_menu()
 { 
   RECT rect; 
   int i;

   GetWindowRect(hWnd,&rect);
   
   if (Hpsl_menu) DestroyMenu(Hpsl_menu);   Hpsl_menu = NULL;
   if (Hhelp_menu) DestroyMenu(Hhelp_menu); Hhelp_menu = NULL;
   
   Hhelp_menu = CreatePopupMenu();
   AppendMenu(Hhelp_menu,MF_STRING | MF_DISABLED,0,"Available Help Entries:");
   AppendMenu(Hhelp_menu,MF_SEPARATOR,NULL,NULL);
   i=1;
   if(!help_open_file()) return(0);
   while(help_read_type())
   {  
      AppendMenu(Hhelp_menu,MF_STRING,IDM_HELP+ (i++), help_read_item());
      help_read_item();
   }
   help_close_file();
   TrackPopupMenu(Hhelp_menu,0,rect.left+100,rect.top+20,0,hWnd,NULL);
 }

help_do(int mode)
  {
    char m; char*t; int i;

    DestroyMenu(Hhelp_menu);
    help_open_file();
    mode = mode-IDM_HELP;
    for (i=1;i<=mode;i++)
     { m=help_read_type();
       if(!m) return(0);
       help_read_item();
       t = help_read_item(); 
    }

    MakePathName(FileName,t);
    if(access(FileName,OF_READ) == -1)
      {lstrcpy(FileName,getenv("helpdir"));
       lstrcat(FileName,t+5);}
    
    if(m=='H')
       WinHelp(hWnd,FileName,HELP_INDEX,0L);
    else
    { char cmd[100]="notepad ";
      lstrcat(cmd,FileName);
      WinExec((LPSTR)cmd,SW_SHOWNORMAL);
    }

    help_close_file();
  }
    
/*------------------------------------------------------------------*/


char speicher[255];

#ifdef WIN32
crack(LPSTR cline)
   {int j; char c;
    argc = 1; j = 0;
    if(cline[0]=='\0') {argc=0; return(0);};
    argv[0] =& speicher[0];
  loop:  
    argv[argc] = & speicher[j];
    while((c = cline[j]) != ' ' 
		    && c != '\0' 
		    && c != 0x0d 
		    && c != 0x0a 
		    && j <= 255)
	 { speicher[j] = c; j++;};
    speicher[j] = '\0';
    j++;
    if (argc<10 && j<255 && c!=0x0d && c!=0x0a && c!='\0') 
    { argc++; goto loop;};
   }

#else 

crack(LPSTR cline)
   {int j; char c;
    argc = j = 0;
    if(cline[0]=='\0') {argc=-1; return(0);}; 
  loop:  
    while(cline[j] == ' ') j++;  /* eat leading blanks */
    argv[argc] = & speicher[j];
    while((c = cline[j]) != ' ' 
		    && c != '\0' 
		    && c != 0x0d 
		    && c != 0x0a 
		    && j <= 255)
	 { speicher[j] = c; j++;};
    speicher[j] = '\0';
    j++;
    if (argc<10 && j<255 && c!=0x0d && c!=0x0a && c!='\0') 
    { argc++; goto loop;};
   }
#endif

min_mode()
  { int i,j=0;
    for(i=0;i<argc;i++)
       if(argv[i][0] == '-' && argv[i][1] == 'm')
	 j=1;
    return(j);
  }

#ifndef WIN32
my_mode()
   /* evaluate special command line parameters */
   { int i; char c;
     for(i=0;i<=argc;i++)
      if(argv[i][0] == '-' && argv[i][2] == '\0')
       { c= argv[i][1];
	if(c == 'x' || c == 'X') exitflag = 1;
	   else
	if(c == 'o' || c == 'O') 
	  {lstrcpy(DriFileName, argv[i+1]);
	   DriFile = _lcreat((LPSTR) DriFileName,0);
	   if(DriFile >= 0) {_lclose(DriFile); dribble = 1;}
		 else warning("cannot open file",argv[i+1]);
	  }
	    else
    if(c == 'm' || c == 'M') ShowWindow(hWnd,SW_MINIMIZE);
	else
	if(c == 'i' || c == 'I')
	  {
	   SetWindowText(hWnd,argv[i+1]);  /* set as title */
       ScriptFile = i+1;
	  } 
     }
    }
#endif

#ifndef WIN32
   /* drive session from script file */

extern char lisp_mode;

static void read_string(LPSTR str)
  {
    char c; 
    while(c = *str++) SendMessage(hWnd,WM_CHAR,(WORD) c,(DWORD) c);
  }

void ScriptInName(LPSTR FileName)
  {
    int w;
    w = wColumns; wColumns = LINELENGTH;
    if (lisp_mode)
    {
      read_string("(dskin \"");
      read_string(FileName);
      read_string("\" ) (exitlisp)\n");
    }
    else
    {
      read_string("in \"");
      read_string(FileName);
      read_string("\";quit;\n");
    }
    wColumns = w;
  }

/*
ScriptIn()
   {int i,l,r;
    char b[128];
    r=1; l=128;
  
   while(r && l==128)
   { l = _lread(ScriptFile,b,128);
     i=0; while(i<l && (r=do_char(b[i++])));
   }
   _lclose(ScriptFile);
   ScriptFile = 0;
   if(exitflag) ExitWindows(0,0);
   }
*/
#endif

char caret_an=0;

caret(int mode)
  { if (mode && (prevent_caret || act_show != act_line)) return(0);
    if (mode==caret_an || !IsActive) return(0);
    if(ScriptFile) return(0);   /* do not display caret then */
    if(mode) 
    { if(insert) CreateCaret(hWnd,NULL,cWidth,cHeight);
	 else    CreateCaret(hWnd,1,cWidth,cHeight);
      SetCaretPos(caret_x,caret_y);
      /* SetCaretBlinkTime(200) */;
      ShowCaret(hWnd);
    }
     else DestroyCaret();
     caret_an=mode;
  }

/* ----------------------------- function keys ------------------------------*/


show_f_keys()
 { 
   RECT rect; 
   int n;
   char key[4] = "F  ";
   char text1[100],text2[60];
   int l;
   int c=0;

   if(fk_menu) DestroyMenu(fk_menu);

   GetWindowRect(hWnd,&rect);
   
   fk_menu = CreatePopupMenu();
   AppendMenu(fk_menu,MF_STRING,0,"Set Function Key:");
   for(n=1; n<13; n++) if(n!=10)
     {
	key[1] = '0'+n;
	if(n>9) {key[1] = '1'; key[2] = '0'+n-10;}
	lstrcpy(text2,key);
	l=get_profile_string(key,"",text1,100);
	if(l != 0)
	{ text1[55] = '\0';lstrcat(text2,": "); lstrcat(text2,text1);}
	AppendMenu(fk_menu,MF_STRING,IDM_SHOW_F+n,text2);
     }
   TrackPopupMenu(fk_menu,0,rect.left+100,rect.top+20,0,hWnd,NULL);
 }

define_F_key(int n)
  {
    char key[4] = "F  ";
    char question [60] = "define text for key >>     << (use # for CR)";

    if(fk_menu) DestroyMenu(fk_menu); fk_menu = NULL;

    key[1] = '0'+n;
    if(n>9) {key[1] = '1'; key[2] = '0'+n-10;}
    question[23] = key[0];
    question[24] = key[1];
    question[25] = key[2];
    get_profile_string(key,"",FileName,100);
    askUser(question);
    write_profile_string(key,FileName);
   }

paste_f_key(int n)
   {
     char key[4] = "F  ";
     char text[100];
     int l;
     LPSTR lpszText;
     char *c;

     key[1] = '0'+n;
     if(n>9) {key[1] = '1'; key[2] = '0'+n-10;}
     l=get_profile_string(key,"",text,100);
     if(l == 0) { warning("Function key not set:",key); return(0); } 

     /* convert # in cr */
     c = text;
     while(*c)
     { if(*c == '#') *c = '\n'; c++; } 

     if (!(hText = GlobalAlloc(GMEM_MOVEABLE,l))) return (0);
	 if (!(lpszText = GlobalLock(hText))) return(0);       
	 lstrcpy(lpszText,text);
	 GlobalUnlock(hText);
	 hdef_input = hText;
	 hText = NULL;
	 return (TRUE);

  }

/* ----------------------------- profile ------------------------------------*/

write_defaults()
   {
      if(!update_defaults) return(0);
      update_defaults = 0;
      GetWindowRect(hWnd,&rect);
      if(wscreenmode == SIZENORMAL)  // don't save if iconic or max
      { 
	write_profile_int("WX0",rect.left);
	write_profile_int("WX1",rect.right-rect.left);
	write_profile_int("WY0",rect.top);
	write_profile_int("WY1",rect.bottom-rect.top);
      }     

      write_profile_int("FONT",font_nr); 
      write_profile_int("FONTSIZE",font_size); 
     
      if(page_mode) write_profile_int("PAGE_MODE",1);
			else write_profile_int("PAGE_MODE",0);   
   
      if(graphics_mode) write_profile_int("GRAPHICS_MODE",1);
			else write_profile_int("GRAPHICS_MODE",0);  
   }

#ifdef WIN32 

HANDLE reg;

int reg_open()
 {
   int d;
   LONG l;
   reg = NULL;

   l=RegOpenKeyEx(
	 HKEY_CURRENT_USER,
	 "PSL",
	 (DWORD)NULL,
	 KEY_ALL_ACCESS,
	 &reg);
   if(l == ERROR_SUCCESS) return(1);

   

  l=RegCreateKeyEx(
	 HKEY_CURRENT_USER,
	 "PSL",
	 (DWORD)NULL,
	 "",
	 REG_OPTION_NON_VOLATILE,
	 KEY_ALL_ACCESS,
	 NULL,
	 &reg,
	 &d);
   return(1);
}
      
reg_close()
  {
   RegCloseKey(reg);
  }

write_profile_string(char * title,char * text)
 { long ret;
   reg_open();
   ret=RegSetValueEx(reg,title,(DWORD)NULL,REG_SZ,text,strlen(text));
   reg_close();
 }

write_profile_int(char * title,int i)
 { 
   long l;
   
   reg_open();
   l=RegSetValueEx(reg,title,(DWORD)NULL,REG_DWORD,&i,4);
   reg_close();
 }

int get_profile_string(char * title,char * nix,char * text,int ll)
 { long ret;
   int l = ll;
   int type;

   text[0]= '\0';
   reg_open();
   ret = RegQueryValueEx(reg,
		  title,
		  (DWORD)NULL,
		  &type,
		  text,
		  &l);
   reg_close();
   return (l);
 }

int get_profile_int(char * title,int r)
 { 
   int l=4;
   int type;

   reg_open();
   RegQueryValueEx(reg,
		   title,
		   (DWORD)NULL,
		   &type,
		   &r,
		   &l);
   reg_close();
   return(r);  
 }


#else

write_profile_int(char* title,int nr)     
  { char text[10];
     /* save number */
    text[0] = '0' + nr/1000;
    text[1] = '0' + (nr/100)%10;
    text[2] = '0' + (nr/10)%10;
    text[3] = '0' + nr % 10;
    text[4] = '\0';
    WriteProfileString((LPSTR)PROFILE,(LPSTR)title,text); 
  }

write_profile_string(char * title,char * text)
 {
    WriteProfileString((LPSTR)PROFILE,(LPSTR)title,(LPSTR)text);
 }

int get_profile_int(char* title,int def)
  {
    return(GetProfileInt((LPSTR)PROFILE,(LPSTR)title,def));
  }

int get_profile_string(char * title,char * def, char * buf,int lth)
  {
    return(
     GetProfileString((LPSTR)PROFILE,(LPSTR)title,(LPSTR)def,(LPSTR)buf,lth));
  }

#endif

#ifdef WIN32 

int my_getenv(char * var, char * val)
   {
     *val = 0;
     strcat(val,getenv(var));
     return(strlen(val));
   }

#else 

int my_getenv(char * var, char * val)
  { int i;
    char c;
    char d;
    LPSTR env;
    int found=0;
        d = 'a' - 'A';
    
    env = GetDOSEnvironment();
    if(!env) return(0);
    while(*env!=0x01 && !found)
    {
       i=0;
       while(var[i] &&  (    var[i] == env[i]
			  || var[i]+d == env[i]
			  || var[i] == env[i]+d
			)
	  ) i++;
	  
       if(!var[i] && env[i] == '=') found=i+1;
	 else
	    while(*env++);  /* skip */
    }
    if(!found) return(0);
    env = &env[found];
    while(*val++ = *env++);
    return(1);
  }

#endif


file_tree()
{
   int i,j,k;

   GetModuleFileName(GetModuleHandle("psllw.exe"),FileName,100);
   i=0; k=0; j=0;
   while(FileName[i]) i++;
   while(i && k<3)
     {if(FileName[i] == '\\') {k++; FileName[i] = '\0';} ; i--;};
   return(1);
 }


void warning(LPSTR head,LPSTR s)
  {MessageBox(GetFocus(),s,head,
	 MB_ICONASTERISK | MB_OK); }

char loc_buffo[9];

void iwarning (LPSTR head,long i)
  {
   wsprintf(loc_buffo,"%lx",i);
   warning(head,(LPSTR) loc_buffo);
  }


int wait_keyboard()
     {
      MSG msg;
      HANDLE curs;
      POINT c;
      int brk = 0;
      int i=0;

      curs = SetCursor(hPageCurs);
      /* GetCursorPos(&c); SetCursorPos(50,0); */
      SetWindowText(hWnd,
	 (LPSTR)"#### Output halted; break key: terminate | any other key: continue ####");
    iwarning("Output halted",(long) curs);
    /*  while (!PeekMessage(&msg,NULL,(UINT) NULL, (UINT) NULL,PM_REMOVE) //WM_KEYFIRST,WM_KEYLAST,PM_REMOVE)
	   && ((i++) < 10000000) /*        &&
	     !PeekMessage(&msg,NULL,WM_LBUTTONDOWN,WM_LBUTTONUP,PM_REMOVE) * /
	    ); */
      set_title();
      /* SetCursorPos(c.x,c.y); */
      SetCursor(curs);
      if ((msg.message ==WM_KEYUP || msg.message == WM_KEYDOWN) 
	    &&
	       (msg.wParam == 0x13 
	     || msg.wParam == 0x3
	     || msg.wParam == 0x90
	       )) brk=1;
      return(brk);
     }


#ifdef WIN32
Wgwd(char * dir)
  {
      if (NULL == _getcwd(dir,128))
	  error("no current dir found","");
  }
#endif

#ifdef WIN32
int Wgdrv(char * dir)
  {
      return( _getdrive());
  }
#endif

#ifdef WIN32
void MoveTo(HDC hDC,int x,int y)
  {
    MoveToEx(hDC,x,y,NULL);
  }
#endif

/* Text output */

void TextOutFix(HDC hDC,int x,int y,LPSTR s,int lth)
  {  
   if(!transparent) clear_rect(x,y,x+lth*cWidth,y+cHeight); 
   y = y - cLead;
   if (font_nr == IDM_FONT_SYS) TextOut(hDC,x,y,s,lth);
     else
   while(lth-- > 0)
    {  TextOut(hDC,x,y,s++,1); x=x+cWidth;}
  }
   
void TextOutProp(HDC hDC,int x,int y,LPSTR s,int lth)
  {
   y = y - cLeadProp;
   TextOut(hDC,x,y,s,lth);  
  }

void TextOutSymb(HDC hDC,int x,int y,LPSTR s,int lth)
  {
   y = y - cLeadSymb;
   TextOut(hDC,x,y,s,lth);  
  }

/* -------------------  PRINTER interface ---------------------- */

#ifndef MAXSTR 
#define MAXSTR 128
#endif

HDC getprinter()
 {
       /* See Petzold, "Programming Windows", ed 2, p721 */
       /* Use Default device - Should be upgraded to allow choice */
       char name[MAXSTR];
       LPSTR dev;
       LPSTR drv;
       LPSTR out;

       GetProfileString("windows", "device", ",,,", name, MAXSTR);
       if ((dev = strtok(name, ",")) && (drv = strtok(NULL, ", ")) &&
	       (out = strtok(NULL, ", ")) )
       {
	       return CreateDC(drv, dev, out, (void *) NULL);
	       }
       return NULL;
       }

#ifdef WIN32
#define Yesp2 yesp2
#endif

void my_print()
    {
     static char szMessage [] = "Print1: Printing";
     BOOL        bError = FALSE;
     HDC         hPrnDC,saveDC;
     int         xPage,yPage,xOffs,yOffs,q,lo=0,hi=0;
 
     if(!marked && !Yesp2((LPSTR)"nothing selected",(LPSTR)"print complete window?")) return;
     if(marked) { lo=old_sel_y; hi=old_s_y;} 

     if (NULL == (hPrnDC = getprinter())) return;
     
     xPage = GetDeviceCaps (hPrnDC, HORZRES);
     yPage = GetDeviceCaps (hPrnDC, VERTRES);
 
     if (Escape(hPrnDC, STARTDOC, sizeof szMessage - 1, szMessage,NULL) > 0)
	{
	  
	  /* Rectangle(hPrnDC,0,0,xPage,xPage); */
	  xOffs = xPage/10;
	  yOffs = yPage/10;
	  SaveDC(hPrnDC);
	  SetMapMode(hPrnDC, MM_ISOTROPIC);
#ifdef WIN32
	  SetWindowExtEx(hPrnDC,wpColumns,wpLines,NULL);
	  SetViewportOrgEx(hPrnDC,xOffs,yOffs,NULL); 
	  SetViewportExtEx(hPrnDC,xPage-2*xOffs,yPage-2*yOffs,NULL); 
#else
	  SetWindowExt(hPrnDC,wpColumns,wpLines);
	  SetViewportOrg(hPrnDC,xOffs,yOffs); 
	  SetViewportExt(hPrnDC,xPage-2*xOffs,yPage-2*yOffs); 
#endif
	
	  saveDC = hDC;
	  hDC = hPrnDC;
	  if (hFont) SelectObject(hDC, hFont);
	  SetBkMode(hDC,TRANSPARENT);
     
	  my_print_page(lo,hi);
       
	  hDC = saveDC;
	  RestoreDC(hPrnDC,-1);

	  if (Escape (hPrnDC, NEWFRAME, 0, NULL,NULL) > 0)
	       Escape (hPrnDC, ENDDOC, 0, NULL,NULL);
	  else
	       bError = TRUE;
	}
     else bError = TRUE;

     DeleteDC (hPrnDC);
     if(marked) mach_weiss();
     return;
    }

// copy data to a meta file.


void copy_metafile()
    {
     static char szMessage [] = "Print1: Printing";
     BOOL        bError = FALSE;
     HDC         saveDC;
     int         xPage,yPage,xOffs,yOffs,q,lo=0,hi=0,sn,zn;
     int         ratio=150;
    
 
     if(!marked && !Yesp2((LPSTR)"nothing selected",(LPSTR)"copy complete window?")) return;
     if(marked) { lo=old_sel_y; hi=old_s_y; zn=hi-lo+1; } 
	else zn=wLines;

     sn=wColumns;
     if(metafile) DeleteMetaFile(metafile);
     if (NULL == (metafile = CreateMetaFile(NULL))) return;
     
     SaveDC(metafile);
     SetMapMode(metafile, MM_ISOTROPIC);
#ifdef WIN32
     SetWindowExtEx(metafile,
		    GetSystemMetrics(SM_CXSCREEN),
		    GetSystemMetrics(SM_CYSCREEN),NULL);
     SetViewportOrgEx(metafile,0,0,NULL); 
    // SetViewportExtEx(hPrnDC,xPage-2*xOffs,yPage-2*yOffs,NULL); 
     SetViewportExtEx(metafile,
		    GetSystemMetrics(SM_CXSCREEN),
		    GetSystemMetrics(SM_CYSCREEN),NULL);
#else
     SetWindowExt(metafile,wpColumns,wpLines);
     SetViewportOrg(metafile,0,0); 
     SetViewportExt(metafile,GetSystemMetrics(SM_CXSCREEN),
			     GetSystemMetrics(SM_CYSCREEN)); 
#endif
	
     saveDC = hDC;
     hDC = metafile; 
     if (hFont) SelectObject(hDC, hFont);
     SetBkMode(hDC,TRANSPARENT);
     
     my_print_page(lo,hi);
       
     hDC = saveDC;
     RestoreDC(metafile,-1);
     metafile=CloseMetaFile(metafile);

     if (OpenClipboard(hWnd)) 
     {
	    METAFILEPICT mf;
	    HANDLE hData;
	    LPSTR lpData;
	    WORD r;

	    mf.mm  = MM_ISOTROPIC;
	    mf.hMF = metafile;
	    mf.xExt = -sn; 
	    mf.yExt = -zn; 
	    if (!(hData = GlobalAlloc(GMEM_MOVEABLE, sizeof(METAFILEPICT)))) 
		{ warning("Copy:","out of Memory"); return;} 
	    if (!(lpData = GlobalLock(hData))) 
		{warning("copy:","lock data");return;}
	    memcpy(lpData,&mf.mm,sizeof(METAFILEPICT));
	    GlobalUnlock(hData);
	    EmptyClipboard();
	    r=SetClipboardData(CF_METAFILEPICT, hData);
	    CloseClipboard();
     } 
       else warning("unable","to set Clipboard");

     if(marked) mach_weiss();
     return;
    }

