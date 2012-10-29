/****************************************************************************

***************************************************************************/

#include "psllw.h"
#include "psllcall.h"
#include "winext.h"

extern int     wColumns;
extern HWND    hWnd;
extern int     storedir;
extern char    FileName[];
extern HANDLE  hPageCurs;
extern char    return_type;

HWND pipe_open(LPSTR name);
pipe_write(HANDLE ,LPSTR ,long);     


long psll_call(p1,p2,p3,p4)
    long p1,p2,p3,p4;
   { DWORD ptr16;
     LPSTR sptr;
     int k; long l;
     char c;

    switch((unsigned int) p4){

     case YIELD:
        return((long)prio_loop(1));
    
     case YESP:                             /* 18 yesp  */
        return((long)yesp((char*)p1));
     
     case LINELENGTH:
       return((long) local_linelength());    /* get window linelength */
    
     case ASKUSER:                             /* ask user */
        if(askUser0((char*)p1))
        { return_type = 's';  return((long)FileName);}
        else return((long)0);

     case HELP:                             /* help entry */
        l= psl_help((int)p1,(char*)p2);
        return(l);


     case PIPE_OPEN:
        return((long)pipe_open((char*)p1));
        break;


     case PIPE_WRITE:
        pipe_puts(p2,(char*)p1);
        return(0);

     case PIPE_CLOSE: 
        return(pipe_close((int)p1));

     case MENU:                             /* menu service */
        return((long)psl_menu((long)p1,(char*)p2,(long)p3));

     case WIN_PAR:
         {
           long q;
           q = win_params[p1];
           win_params[p1] = p2;
           return (q);
         }

     case FILE_TREE:       
        file_tree();
        return_type = 's';
        return((long)FileName);

     default:
        my_puts("psll_call unknown mode:"); my_newline();
        melden("p1:",(long) p1);
        melden("p2:",(long) p2); 
        melden("p3:",(long) p3); 
        melden("p4:",(long) p4); 
        break; 
     }

     return((long)0);
   }

melden(char * txt, long i)
   { my_puts(txt);
     my_putint(i);
     my_newline();
   }

#include "winpipes.c"
