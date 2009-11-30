#include "psllcall.h"
#include <stdio.h>

#define MAXPIPE 5

#ifdef ALPHA
#define LONG __int64
#else
#define LONG long
#endif

extern LONG psl_callback1;
extern LONG psl_callback2;
extern LONG psl_callback3; 
extern LONG psl_callback4;
extern LONG psl_callback5;   

extern int pipe_mode;

int my_plocalcall(char * buf, int len)
     { 
       LONG mode; LONG p1;
                          psl_callback2 = 0;
       psl_callback3 = 0; psl_callback4 = 0;
       sscanf(buf,"%d,%d,%d,%d,%d",&mode,&p1,&psl_callback2,
           &psl_callback3,&psl_callback4);
       psl_callback1 = psl_callback1 | p1; // accumulate
       printf("local: %s %d %d %d %d \n", buf,  psl_callback1,
        psl_callback2, psl_callback3, psl_callback4);
       psl_call(p1,psl_callback2,psl_callback3,psl_callback4);
       printf("return \n");
       return (0);
       /*
       {
          char z[100];
          sprintf(z,"calls: %s %x\n",buf);
          my_puts(z);
          sprintf(z,"calli: %x\n",psl_callback1);
          my_puts(z);
       }
*/
     }

stringp(LONG u)
    { return(u>10000);}

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
    else {printf("illegal argument type: %c\n",t); };
    return(ptr);
   }


psll_call1(LONG p1, LONG p2, LONG p3, LONG p4, int f)
    {
     char lbuf[512]; char sr[255];
     int r;  LONG pr;

     if (!pipe_mode) return(0);

     if (f<1 || !stringp(p1) && !stringp(p2) && !stringp(p3))
       sprintf(lbuf,"i%d|i%d|i%d|i%d|",p1,p2,p3,p4);
        else
     if (f<2 || stringp(p1) && !stringp(p2) && !stringp(p3))
       sprintf(lbuf,"s%s|i%d|i%d|i%d|",p1,p2,p3,p4);
        else
     if (f<3 || stringp(p1) && stringp(p2) && !stringp(p3))
       sprintf(lbuf,"s%s|s%s|i%d|i%d|",p1,p2,p3,p4);
         else
     if (stringp(p1) && stringp(p2) && stringp(p3))
       sprintf(lbuf,"s%s|s%s|s%s|i%d|",p1,p2,p3,p4);

     r= my_rpc(lbuf,strlen(lbuf));

     my_plocp((char*)lbuf,&sr[0],&pr);

     if (p4 == PIPE_OPEN && pr !=0) notify_wpipe(pr);
     if (p4 == PIPE_CLOSE) delete_wpipe(p1);
      
     return(pr);
    }

psll_call(LONG p1, LONG p2, LONG p3, LONG p4)
  { 
    int n=3;

    if(p4 == PIPE_CLOSE) n=0;
    return(psll_call1(p1, p2, p3, p4, n)); 
  }


LONG hpipe[MAXPIPE];

notify_wpipe(LONG p)
   {
      int h;
      h=isapipe((LONG)NULL);
      hpipe[h-1] = p;
   }

delete_wpipe(LONG p)
   {
      int h;
      h=isapipe(p);
      hpipe[h-1] = (LONG)NULL;
   }

pipe_write(LONG pipe, char * s,LONG n)
  {
      // warning: arg 1 and 2 interchanged!!!
     s[n] = '\0';
     psll_call1((LONG)s,pipe,n,(LONG)PIPE_WRITE,1);
     return(n);
  }

local_puts(char * lbuf)
    {
       printf("unexpected message: %s\n",lbuf);
    }
