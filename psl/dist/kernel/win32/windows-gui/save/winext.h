/* external references for memory structures for Windows IO */

extern CATCHBUF        CatchBuf;
extern HANDLE          hInst;
extern HANDLE          hFile;
extern HWND            hWnd;  
extern HFONT           hFont; 
extern HDC             hDC; 
extern int             cHeight;                /* character height  */
extern int             cWidth;
extern int             cLead;                  /* internal leading */
extern int             wLines,wColumns;          /* window size in chars */
extern int             wpLines,wpColumns;        /* window size in pixels */
extern int             bLine;
extern int             caret_x,caret_y;
extern char            overwrite_caret,prevent_caret;
extern int             argc;
extern char           *argv[10];
extern HANDLE hData, hClipData;                  /* handles to clip data  */
extern HANDLE hText;
extern LPSTR lpData, lpClipData;                 /* pointers to clip data */
extern HANDLE         hdef_input;           /* handle for deferred input */
extern HCURSOR        hSaveCursor, hHourGlass, hArrow, hActCursor, hPageCurs;
extern int            dribble;                 /* dribble file to be written */  
extern int            dri_linew;               /* linewise mode for dirbble file*/
extern int            dri_cls;                 /* dynamic close control */
extern int            autocopy;
extern int            storedir;
extern char           update_defaults;
extern char           page_mode;
extern char           graphics_mode;
extern int            page_count;
extern int            mausdruck;
extern int            marked;
extern int            insert;                   /*  : insert ON */
extern int            ctrl ;                   /* control key pressed */
extern int            init;
extern char           destroy;
extern int            ScriptFile;      /* indicates script mode */
extern int            exitflag;                /* if 1, terminate windows */
extern int            psl_msg ;               /* messages for PSL */
extern char           during_paint ;
extern char           has_DC ;
extern WORD           wscreenmode;

	       warning(LPSTR,LPSTR);
	       do_char(char);
extern char           FileName[128];
extern char           DriFileName[128] ;
extern int            DriFile;
extern char           dir[128];
extern char           renv[128] ;
extern char           ahead_buf[128] ;
extern LPSTR          banner;

extern int            font_nr ;
extern int            font_size;
extern int            font_res ;  /* indicates that font resource is present */
extern int            font_height[2], font_width[2];
extern HFONT          font[2],symb_font[2];

extern int            fancy_xrange,fancy_yrange,fancy_tab,fancy_start;
extern char           fancy_on ;
extern LPSTR          fancy_lines[15];
#define        FANCY '@'


extern int            act_line;     /* actual line for new output */
extern int            act_show;     /* last line of actual display */
extern int            abs_line;     /* absolute line number */
 
extern int            org_x,org_y; /* screen basis */

extern int            mmm ;
extern char           buffo[255];

far pascal    FileDlg(HWND, unsigned, WORD, LONG);
extern int           my_getenv(char *,char *);
extern long          my_input(char s[]);

extern WORD          dde_message[MSG_STACK];
extern WORD          dde_wParam[MSG_STACK];
extern DWORD         dde_lParam[MSG_STACK];
extern int           dde_ptr;
extern char          dde_block;            /* prevent against cyclic dde */

extern int           state ;
extern char          IsActive;
extern char          during_scroll;

 /* prototypes for init file */

write_profile_int(char* title,int nr);     
write_profile_string(char * title,char * text);
int get_profile_int(char * title,int def);
int get_profile_string(char * title,char * def, char * buf,int lth);

 /* variables for input/output   */


extern int act_x, act_y;
extern int i_ptr; /* input pointer */
extern int o_ptr; 
extern int po_ptr;

    /* buffer for input lines */

extern int liptr;
extern int licount;
extern char ipuffer[255];
extern char lipuffer[MAXLIPUFFER][LINELENGTH];

    /* buffer for output lines */

extern HANDLE  lpuffer_handle;
extern char * lpuffer_mem;
extern char * lpuffer[MAXLOPUFFER+1];
extern char aux[80];
 
extern int sel_x,sel_y,s_x,s_y;

extern long win_params[];
