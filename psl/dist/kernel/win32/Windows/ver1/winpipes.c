/***************************************************************************
  support of unix style pipes
****************************************************************************/

int vorlesen = 0;

static HWND hpipe0,hparent0;

HWND hpipe[MAXPIPE];
static HWND hparent[MAXPIPE];

BOOL FAR PASCAL Vorlesen(HWND hwnd,DWORD dummy);

char wndname[50];


HWND pipe_open(LPSTR name)
  { WORD r;
    char name1[50];
    char * c, *d;
    FARPROC lpProc;        
    int subwindow;
    int s=SW_MINIMIZE;   
    int h;

    h=isapipe((HWND)NULL);
        // no more free slot
    if(!h) { warning("error","too many open pipes"); return((HWND)NULL);}

    c = name; d = name1;
    if (*c == '*') { vorlesen=1; c++;} else vorlesen=0;
    if (*c == '+') { s = SW_SHOWNORMAL; c++;} else vorlesen=0;
    
    while(*c && *c!=';') *d++ = *c++;
    if(!*c) return(0);
    *d = 0; *c++; d=wndname;
    while(*c && *c!=';' ) *d++ = *c++; *d=0;

    r = WinExec(name1,s);      
    if(r<=32 && !vorlesen) return(0);
    
    lpProc = MakeProcInstance(Vorlesen, hInst);
    if(vorlesen) my_puts("current windows are:"); my_newline();
    EnumWindows(lpProc,0);
    hparent0 = hpipe0;
    if (*c == 0) goto val;

    if(vorlesen) my_puts("Childs\n"); 
    /* subwindows name */
    *c++; d=wndname;
    while(*c) *d++ = *c++; *d=0;

    EnumChildWindows(hpipe0,lpProc,1);
    ShowWindow(hpipe0,SW_HIDE);
 
  val:
    hparent[h-1] = hparent0;
    hpipe[h-1] = hpipe0;
    return(hpipe0);
  }


#ifdef USE_CLIPBOARD

pipe_puts(HWND pipe,LPSTR s)
  {
    long l; 
    LPSTR c;
    c = s;
    l=0; while(*c && *c++!='\n') l++;

    return pipe_write(pipe,s,l);
  }
      
pipe_write(HWND pipe,LPSTR s,long l)
  {
    LPSTR lpData;
    int b,xx,yy;
    HANDLE hData;
    char c;

	/* Allocate memory and copy the string to it */
    if (!(hData = GlobalAlloc(GMEM_MOVEABLE, l+1))) 
       { warning("Copy:","out of Memory"); return (TRUE);} 
    if (!(lpData = GlobalLock(hData))) 
       {warning("copy:","lock data");return (TRUE);}
	/* move character to data buffer */
    
    while(l && (*lpData++ = *s++)) l--;  
    *lpData = '\0';
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
     SendMessage(pipe,WM_COMMAND,IDM_PASTE,NULL);   
    }

#else

pipe_puts(HWND pipe,LPSTR s)
  {

    while(*s) 
	{ if(*s != '\n')
	    SendMessage(pipe,WM_CHAR,*s,MAKELONG(1,0x1e));
	      else
	    SendMessage(pipe,WM_CHAR,0xd,MAKELONG(1,0x1c));
	   s++;
	}

  }



pipe_write(HWND pipe,LPSTR s,long l)
  {
      HWND w; 

      while(l>0) 
	{ if(*s != '\n')
	    SendMessage(pipe,WM_CHAR,*s,MAKELONG(1,0x1e));
	      else
	    SendMessage(pipe,WM_CHAR,0xd,MAKELONG(1,0x1c));
	   s++; l--;
	}

      if(w = FindWindow(NULL,"gnuplot graph"))
	  SetWindowText(w,"REDUCE plot");

  }

#endif

pipe_close(HWND pipe)
  {
      int p;
      if(pipe==NULL) return(0);
      p = isapipe(pipe);
      if(p) hpipe[p-1] = 0;
      SendMessage(hparent[p-1],WM_DESTROY,0,0);
  }

BOOL FAR PASCAL Vorlesen(HWND hwnd,DWORD dummy)
  {
    char buff1[80];
    char buff2[80];
    int l;

    hpipe0 = NULL;
    buff2[0]=0;
    l=GetClassName(hwnd,(LPSTR)buff2,80);
    if(vorlesen)  
    {
       my_puts("title:");
       my_puts(buff2); my_newline();
    }
    if(0==lstrcmp(buff2,wndname)) hpipe0=hwnd;
    if(hpipe0) return(0); else return(1);
  }

