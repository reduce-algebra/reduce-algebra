/* ===================== pmaster.c ===========================*/
//   initiate slave process

//  #define TEST 1

#include <windows.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef ALPHA
#define LONG __int64
#else
#define LONG long
#endif

int script_mode=0;
int win_mode = 1;
int slave_alife = 0;
int adr_bruch = 0;

PROCESS_INFORMATION proc_info;
DWORD               thread_id;
HANDLE              hthread;
extern int wait_input;

#define MAXPIPE 5

extern HANDLE fe2lisp_read,fe2lisp_write, lisp2fe_read, lisp2fe_write; 

long psl_callback1=0;
long psl_callback2=0;
long psl_callback3=0; 
long psl_callback4=0;
long psl_callback5=0;   

extern long hpipe[];
extern long hWnd;

unsigned long listen_slave(void*);

isapipe(FILE*fp)
   {
     unsigned long ifp; int i;
 
     ifp = (unsigned long)fp;
     for (i = 0 ; i<MAXPIPE ; i++) 
	if (hpipe[i]==ifp) return(i+1);
     return(0);
   }

char collect[255], copy[255];  

char *expand_file_name(fname)
char *fname;
{
  char *c, *t, *e, *s, save;
  c = copy;
  s = fname;
  while (*c++ = *s++);
  s = copy;
  c = collect;
  *c = '\0';
  while (*s)
    {
      if (*s == '$')
	{
	  for (e = ++s; (*e != '/' && *e != '\\'  && *e != '.'
			  && *e != '\0' && *e != '$'); e++)
	    ;
	  t = 0;                        /* default initialization */
	    {
	      save = *e;
	      *e = '\0';
	      t = getenv(s);
	      *e = save;
	      s = e;
	    }
	  if (t)
	    while (*c++ = *t++)
	      ;
	  else
	    return(fname);   /* name not found, just return original fname */
	  c--;
	}
    for (; (*s != '\0' && *s != '$'); *c++ = *s++)
      ;
      *c = '\0';
  }
  return (collect);
}

close_all() {}

//=================================================================

char the_buffer[500];

int twoofthem =0; 

BOOL CALLBACK mach_kleinx(HWND w,LPARAM l)
     // send a minimize message to the REDUCE server window.
 {
   char titel[100];

   GetWindowText(w,titel,100);
   if (strcmp(titel,"Reduce Server") == 0)
   { 
     ShowWindow(w,SW_SHOWMINNOACTIVE);  twoofthem ++;
     if (twoofthem < 1) return(FALSE); else return (TRUE);
    }
     else 
   
   if (strncmp(titel,"LISP",4) == 0) 
   { 
     SetForegroundWindow(w); twoofthem ++;
     if (twoofthem < 1 ) return(FALSE); else return (TRUE);
   } 
      else return(TRUE);
 }

mach_klein()
  {  twoofthem = 0;
     EnumWindows(mach_kleinx,0);
     Sleep(200);
  }


lisp_main(argc,argv)
    int argc; char* argv[];

  { int l;
    LPTSTR cmdl;
    char * ptr;
    PROCESS_INFORMATION procinfo;
    int pnr;
    BOOL x;

    pnr = hWnd;

    init2(0,0);

	// create communication pipes

    my_popen_master(pnr);
    
	// create thread for reading LISP data.

    hthread = CreateThread(
       NULL,           //  sec
       (DWORD)0,       //  default stack
       (LPTHREAD_START_ROUTINE) listen_slave,   //  start routine
       (LPVOID)0,      //  parameter
       (DWORD)0,       //  create flags (run immediately)
       & thread_id);

    if (!hthread)
       {
	 iwarning("cannot create thread",GetLastError());
	 exit(0);
       }

      //================= LISP process

#ifdef TEST
    cmdl = "D:\\psl\\kernel\\alphant\\bpslw.exe";
#else
    cmdl = GetCommandLine();
#endif

    if(cmdl[0] == '\"') strcpy(the_buffer,(LPSTR) cmdl+1);
       else  strcpy(the_buffer,(LPSTR) cmdl);
       //  WIN 95 does it like "this"
    ptr = strstr(the_buffer,"BPSLW");
    if((int) ptr < 3) ptr = strstr(the_buffer,"bpslw");
    if((int) ptr < 3) warning("?? command line",the_buffer);

    *(ptr + 4) = ' ';
    if(cmdl[0] == '\"') *(ptr + 9) = ' '; // Windows 95   

    {
      char zahl[20];
      int i;
      STARTUPINFO startup_info;

      GetStartupInfo(&startup_info);
      startup_info.lpTitle = "Reduce Server";
      startup_info.wShowWindow = SW_MINIMIZE;

	 // add pipe handles to command line
      sprintf(zahl," -p %d",fe2lisp_read);
      strcat(the_buffer,zahl);
      sprintf(zahl," %d",lisp2fe_write);
      strcat(the_buffer,zahl);

      x=CreateProcess(
	NULL,              // module name (ref to command line)
	the_buffer,        // command line
	NULL,              // security process
	NULL,              // security thread
	TRUE,              // inherit handles
	CREATE_NEW_CONSOLE, // fwdCreate
	NULL,               // environment
#ifdef TEST
	"d:\\psl\\nonkern\\alphant\\lap",   // current Dir
#else
	NULL,               // current Dir
#endif
	&startup_info,
	&proc_info);
	
      if (!x)
       {
	 iwarning("cannot create process",GetLastError());
	 exit(0);
       }
       mach_klein();
       slave_alife = 1;
	
    } 

    ////init3();
    return(win_loop());
  }           

kill_slave()
  {
    TerminateProcess(proc_info.hProcess,(UINT)0);
  }
    
break_slave()
  {
     LONG b_b=0;
     DWORD written;
 
     if(!adr_bruch || wait_input) return(0);

     ReadProcessMemory(
	  proc_info.hProcess,
	  (LPVOID) adr_bruch,
	  (LPVOID) & b_b,
	  (DWORD) sizeof(b_b),
	  & written);

     if(b_b < -5)
      { 
	warning("terminating","more than 5 open interrupts");
	kill_slave();
	exit(0);
      };

     b_b--;

     if(WriteProcessMemory(
	  proc_info.hProcess,
	  (LPVOID) adr_bruch,
	  (LPVOID) & b_b,
	  (DWORD) sizeof(b_b),
	  & written))
     my_puts("\nTerminal Interrupt sent to LISP process\n");
       else
     warning("terminal interrupt","impossible");
  }

p_callback()
  {
     char lbuf[300];
 
     if(!psl_callback1) return(0);
    
     sprintf(lbuf,"%d,%d,%d,%d,%d",1,psl_callback1,psl_callback2,
	   psl_callback3,psl_callback4);
     
     my_rpc(lbuf,strlen(lbuf));
     psl_callback1 = 0;
   }

//=================================================================

char * my_plocp(char * ptr, char * s, LONG * p)
   // decode one parameter
  {
    char t,c; char * ss; int i=0;
    ss=s;
    t = * ptr ++;
    *p = 0;
    while((c = *ptr++) != '|' && i++<200) *ss++ = c; 
    *ss = '\0';
    if (t == 's') *p = (LONG)s;
    else if (t == 'i') sscanf(s,"%d",p);
    else {my_puts("illegal argument type:");
	  my_putc(t); my_newline();};
    return(ptr);
   }

char return_type;      // 's': return a string.

int my_plocalcall(char * buf, int len)
     { 
       char s1[255],s2[255],s3[255],s4[255];
       char * ptr;
       LONG p1,p2,p3,p4,r;

       // sprintf(s1,"RPC angekommen: %s\n",buf);
       // my_puts(s1);

       p1 = 3001; p2=3002; p3=3003; p4=3004;

       ptr = buf;
       ptr = my_plocp(ptr,&s1[0],&p1);
       ptr = my_plocp(ptr,&s2[0],&p2);
       ptr = my_plocp(ptr,&s3[0],&p3);
       ptr = my_plocp(ptr,&s4[0],&p4);
       return_type = '\0';
       r= psll_call(p1,p2,p3,p4);
       if (return_type == 's')
	   sprintf(buf,"s%s|",r);
	 else
	   sprintf(buf,"i%d|",r);
       return(strlen(buf));
     }

my_send_break()
     {
       char txt[1];

       my_psend('b',txt,0);
     }

local_puts(char * lbuf)
    {
       my_puts(lbuf);
       prio_loop(0);
    }
