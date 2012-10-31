/* memory structures for Windows IO */

CATCHBUF        CatchBuf;
HANDLE          hInst;
HANDLE          hFile;
HWND            hWnd;  
HFONT           hFont=0; 
HDC             hDC; 
int             cHeight=0;                /* character height  */
int             cWidth=0;
int             cLead=0;                  /* internal leading */
int             wLines,wColumns;          /* window size in chars */
int             wpLines,wpColumns;        /* window size in pixels */
int             bLine = 0;                /* base line  of current screen */
int             caret_x,caret_y;
char            overwrite_caret=0,prevent_caret=0;
int             argc;
char           *argv[10];
HANDLE hData, hClipData;                  /* handles to clip data  */
HANDLE hText = NULL;
LPSTR lpData, lpClipData;                 /* pointers to clip data */
HANDLE         hdef_input=NULL;           /* handle for deferred input */
HCURSOR        hSaveCursor, hHourGlass, hArrow, hActCursor, hPageCurs;
int            dribble=0;                 /* dribble file to be written */  
int            dri_linew=0;               /* linewise mode for dirbble file*/
int            dri_cls=1;                 /* dynamic close control */
int            autocopy=1;
int            storedir=1;
char           update_defaults=0;         /* record whether defaults must be saved on exit*/
char           page_mode=0;
char           graphics_mode=0;
int            page_count=0;
int            mausdruck=0;
int            marked=0;
int            insert=0;                   /* =0 : insert ON */
int            ctrl = 0;                   /* control key pressed */
int            init=0;
char           destroy=0;
int            ScriptFile=0;      /* indicates script mode */
int            exitflag=0;                /* if 1, terminate windows */
int            psl_msg = 1;               /* messages for PSL */
char           during_paint = 0;
char           has_DC = 0;
WORD           wscreenmode = SIZENORMAL;  

	       warning(LPSTR,LPSTR);
	       do_char(char);
char           FileName[128];
char           DriFileName[128] = "reduce.lst";
int            DriFile;
char           dir[128];
char           renv[128] = "\0";
char           ahead_buf[256] = "\0";
LPSTR          banner;

int            font_nr = 0;
int            font_size = 0;
int            font_res = 0;  /* indicates that font resource is present */
int            font_height[2], font_width[2];
HFONT          font[2]={0,0},symb_font[2]={0,0};

int            fancy_xrange,fancy_yrange,fancy_tab,fancy_start=0;
char           fancy_on = 0;
LPSTR          fancy_lines[15];


int            act_line=0;     /* actual line for new output */
int            act_show=0;     /* last line of actual display */
int            abs_line=0;     /* absolute line number */

int            org_x=0,org_y=0; /* screen basis */

char           buffo[255];

far pascal    FileDlg(HWND, unsigned, WORD, LONG);
long          my_input(char s[]);

WORD          dde_message[MSG_STACK];
WORD          dde_wParam[MSG_STACK];
DWORD         dde_lParam[MSG_STACK];
int           dde_ptr=-1;
char          dde_block=0;            /* prevent against cyclic dde */

int           state = LOOP;
char          IsActive=0;
char          during_scroll=0;

 /* prototypes for init file */

write_profile_int(char* title,int nr);     
write_profile_string(char * title,char * text);
int get_profile_int(char * title,int def);
int get_profile_string(char * title,char * def, char * buf,int lth);

 /* variables for input/output   */


int act_x=0, act_y=0;
int i_ptr=0; /* input pointer */
int o_ptr=0; 
int po_ptr=0;

    /* buffer for input lines */

int liptr = MAXLIPUFFER;
int licount = MAXLIPUFFER;
char ipuffer[255] = "";
char lipuffer[MAXLIPUFFER][LINELENGTH];

    /* buffer for output lines */

HANDLE  lpuffer_handle;
char * lpuffer_mem;
char * lpuffer[MAXLOPUFFER+2];
char aux[80];

int sel_x=-1,sel_y=-1,s_x=-1,s_y=-1;    /* selected part of screen */ 

long win_params[4];
