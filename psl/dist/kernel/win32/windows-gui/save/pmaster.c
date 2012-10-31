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

#define MAXPIPE 5

long psl_callback1=0;
long psl_callback2=0;
long psl_callback3=0; 
long psl_callback4=0;
long psl_callback5=0;   

extern long hpipe[];
extern long hWnd;

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

lisp_main(argc,argv)
    int argc; char* argv[];

  { int l;
    LPTSTR cmdl;
    char * ptr;
    PROCESS_INFORMATION procinfo;
    int pnr;

    pnr = hWnd;

    init2(0,0);
    my_popen_master(pnr);
    
        // create PSL process.

    cmdl = GetCommandLine();
        // prefix terminal shell and replace bpslw by bpsl
    strcpy(the_buffer,"cmd /c ");
    strcat(the_buffer,(LPSTR)cmdl);
    ptr = strstr(the_buffer,"bpslw");
    *(ptr + 4) = ' ';

    {
      char zahl[20];
      UINT x;

         // add pipe name to command line
      sprintf(zahl," -p %d",pnr);
      strcat(the_buffer,zahl);
         // execute program 
      x = WinExec(the_buffer,SW_MINIMIZE);
      if(x < 32) {iwarning("exec error",x); exit(1);}
    } 


    the_buffer[0] = '\0';
    my_wait_slave();
    slave_alife = 1;
    my_master_dispatch(the_buffer, -1);
    init3();
 loop:
    l = my_gets(the_buffer);
    the_buffer[l] = '\0';
    p_callback();
    psl_callback1=0;
    my_master_dispatch(the_buffer,l+1);
    goto loop;
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
