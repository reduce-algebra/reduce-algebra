#include<windows.h>
#include <time.h>

#ifdef ALPHA
#define LONG __int64
#define ADDRESSINGUNITSPERITEM 8
#else
#define LONG long
#define ADDRESSINGUNITSPERITEM 4
#endif

unixsocketopen(name , number)

char * name;
int number;

{
}

getsocket (mail_fd , string , length)

int mail_fd,length;
char * string;

{
}

writesocket (mail_fd , string , length)

int mail_fd,length;
char * string;

{
}

unixclosesocket (conn_fd)
int conn_fd;

{
}


LONG getpid()
  { return((LONG)GetCurrentProcessId()); }
 
LONG external_timc(buffer)
     struct tms *buffer;
{
  //FILETIME a1,a2,a3,a4 , cl;
#ifdef WINPSL
   prio_loop();
#endif
  return(clock());  /* CLOCKS_PER_SEC is 1000 */
  //GetProcessTimes(GetCurrentProcess(),&a1,&a2,&a3,&a4);
  //printf("curget... %d\n",GetLastError());
  //return(a4.dwHighDateTime* 10000);
}
LONG whatsup(x)
DWORD * x;

{if ((int) x >1000) { *x = sizeof(OSVERSIONINFO);  
              return(GetVersionEx( (OSVERSIONINFO *) x)); }
else return (0);}

// for interrupts etc
