/****************************************************************************
    PURPOSE: Filename Dialog 
*/ 

/* #include "windows.h" */
#include "psllw.h"


extern   HANDLE      hInst;
extern   HWND        hWnd;
extern   char        dir[];
extern   LPSTR       banner;
extern   int         storedir;         
	 char        title[120];      
extern   char       *argv[];
extern   char       *iname;
extern   int         ScriptFile;         
	 LPSTR       comment=NULL;
extern   char        ahead_buf[];

/* Additional includes needed for the fstat() function */

#include <sys\types.h>
#include <sys\stat.h>

extern char FileName[];
char DefPath [128];
char ActPath [128];
char  str[128];
char DefSpec[5] = "*.red";
char DefExt[5] = "";
char OpenName[128];



/****************************************************************************

    FUNCTION: FileDlg(HWND, unsigned, WORD, LONG)

    PURPOSE: Allows user to select a file name

    COMMENTS:

	This will initialize the window class if it is the first time this
	application is run.  It then creates the window, and processes the
	message loop until a PostQuitMessage is received.  It exits the
	application by returning the value passed by the PostQuitMessage.

****************************************************************************/

int WINAPI FileDlg(hDlg, message, wParam, lParam)
HWND hDlg;
UINT message;
UINT wParam;
LONG lParam;
{
    char TempName[128];
    int name_found;

    switch (message) {
	case WM_INITDIALOG:

		/* Process the path to fit within the IDC_PATH field */

	    if(comment)
	       SetDlgItemText(hDlg, IDC_PATH, comment);
	    else
	       DlgDirList(hDlg, DefPath, NULL, IDC_PATH, 0x4010);

		/* Send the current filename to the edit control */

	    SetDlgItemText(hDlg, IDC_EDIT, FileName);

		/* Accept all characters in the edit control */

	    SendDlgItemMessage(hDlg, IDC_EDIT, EM_SETSEL, 0,
		    MAKELONG(0, 0x7fff));
	    

	    EnableWindow(GetDlgItem(hDlg, IDOK), TRUE);

	    /* Set the focus to the edit control within the dialog box */

	    SetFocus(GetDlgItem(hDlg, IDC_EDIT));
	    return (FALSE);                 /* FALSE since Focus was changed */

	case WM_COMMAND:
	    switch (wParam) {
		case IDC_EDIT:

		    return (TRUE);

		case IDOK:

		    GetDlgItemText(hDlg, IDC_EDIT, FileName, 128);
		    EndDialog(hDlg, IDOK);
		    return (TRUE);

		case IDCANCEL:

		    /* Tell the caller the user canceled the SaveAs function */

		    EndDialog(hDlg, IDCANCEL);
		    return (TRUE);
	    }
	    break;

    }
    return (FALSE);
}

read_parameter(char* s)
   {
    FARPROC lpFileDlg;
    int r;

    comment = s;
    lpFileDlg = MakeProcInstance((FARPROC) FileDlg, hInst);
    r = DialogBox(hInst, "ReadParameter", hWnd, lpFileDlg);
    FreeProcInstance(lpFileDlg);
    comment = NULL;
    if(r=IDOK) return(1); else return(0);
    }


/*------------------------------------------------------------------
      Directory service
  ------------------------------------------------------------------*/
   
char * expand_file_name(char * filename);

my_cd(char * filename,int mode)   
  {
   int d; char c;
 
   filename = expand_file_name(filename);
   if(filename[1] == ':') 
   { c=filename[0];
     if(c>= 'a') d=c-'a'; else d=c-'A';
     _chdrive(d+1);
     filename = filename + 2;
   };
   _chdir(filename);
   set_dir();
   if(mode) WriteProfileString("PSLLW","DIR",dir); 
   set_title();
  }

set_dir()
   {
    Wgwd(dir);
   }

/*------------------------------------------------------------------
      YESP
  ------------------------------------------------------------------*/

yesp(LPSTR text1)
   { return(yesp2(text1,(LPSTR) ""));} 
   
LPSTR tx1,tx2;

yesp2(LPSTR text1,LPSTR text2)
   {
    FARPROC lpYespDlg;
    int r;
    
    tx1 = text1;
    tx2 = text2;
    lpYespDlg = MakeProcInstance((FARPROC) YespDlg, hInst);
    r = DialogBox(hInst, "Yesp", hWnd, lpYespDlg);
    FreeProcInstance(lpYespDlg);
    if(r==IDOK) return(1); else return(0); ;
   }

int WINAPI YespDlg(hDlg, message, wParam, lParam)
HWND hDlg;
UINT message;
UINT wParam;
LONG lParam;
{
    switch (message) {
	case WM_INITDIALOG:


		/* Send the current filename to the edit control */
	    SetDlgItemText(hDlg, IDC_PATH, tx1);
	    SetDlgItemText(hDlg, IDC_EDIT, tx2);
	    EnableWindow(GetDlgItem(hDlg, IDOK), TRUE);
	    SetFocus(GetDlgItem(hDlg, IDC_EDIT));
	    return (FALSE);                 /* FALSE since Focus was changed */

	case WM_COMMAND:
	    switch (wParam) {
		case IDC_EDIT:
		    return (TRUE);

		case IDOK:
		case IDCANCEL:
		    EndDialog(hDlg, wParam);
		    return (TRUE);

	    }
	    break;

    }
    return (FALSE);
}

filep(LPSTR name)
  { int f;
    if((f=_lopen(name,OF_READ))==-1) return(0);
    _lclose(f); return(1);
  }

set_title()
  { int i,j;
    set_dir();
    strcpy(title, "LISP: ");
    i = strlen(title);
    for(j=0; dir[j]; j++)  title[i+j] = dir[j];
    title[i+j++]='\\';
    title[i+j++]='.';  title[i+j++]='.'; title[i+j++]='.';
    title[i+j] = '\0';
    SetWindowText(hWnd,title);
  }
		
askUser(char * question)
   {
    FARPROC lpFileDlg;
    int r;
    comment = question;
    // FileName[0] = '\0';
    lpFileDlg = MakeProcInstance((FARPROC) FileDlg, hInst);
    r = DialogBox(hInst, "AskUser", hWnd, lpFileDlg);
    FreeProcInstance(lpFileDlg);
    return(r == IDOK);
    }


askUser0(char * question)  
    {
      FileName[0] = '\0';
      return askUser(question);
    }