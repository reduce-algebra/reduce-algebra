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


#ifdef TEST
#define TEST_PRINT(fmt,p1,p2) pmelden(fmt,p1,p2)
#else
#define TEST_PRINT(fmt,p1,p2)
#endif

static HANDLE the_named_pipe; 
static int slave_mode = 1;

HANDLE my_popen_master(int n);
HANDLE my_popen_slave(int n);

extern LONG bruch_bruch;

#ifndef SLAVE
#include "master.c"
#endif

//protocol:
//     c:   remote procedure call
//     a:   answer to rpc
//     r:   read request
//     d:   data reply to 'r'
//     b:   break
//     x:   exit

void my_peek();

char * who()
   {
      if(slave_mode) return("slave"); else return("master");
   }

pmelden(char * fmt,char * p1, char * p2)
   {
      char str[100];
      sprintf(str,fmt,who(),p1,p2);
      if(slave_mode) puts(str); else my_puts(str);
   } 
      
my_rpc(char * buf, int len)
   {
         TEST_PRINT("%s RPC call\n %s\n",buf,"");
      my_psend('c',buf,len);
      return(my_preceive('a',buf,len));
   }

#ifndef SLAVE

my_master_dispatch(char * buf, int len)
   {
         // reply to slave read request.
         // write data to slave and wait for next read

      int llen,ret;
      char t;
      char lbuf[600];
      
      if (len > -1) my_psend('d',buf,len);

      next:
       llen = myReadFromNamedPipe(lbuf, 600);
       llen -- ; t = lbuf[llen]; lbuf[llen] ='\0';

          TEST_PRINT("%s dispatch - received: %s\n",&t,"");
 
       if (t == 'x') 
          { exit(0); }
       else if(t == 'b')
          bruch_bruch--;
       else if(t == 'w')
         {
           local_puts(lbuf);
         }
       else  if(t == 'c')  // slave calls master
         { 
           ret=my_plocalcall(lbuf,llen);    // call local procedure
           my_psend('a',lbuf,ret);          // result return
           goto next;
         }
       else if(t == 'r')  // read data
           return(0);
       else
         {
           sprintf(lbuf,"master error: unexpected message %d: >%c<\n",llen,t);
           my_puts(lbuf);
         }
      goto next;

    }

my_wait_slave()
     {
       return(ConnectNamedPipe(the_named_pipe,(LPOVERLAPPED)NULL));
     }

#endif

my_pexit()
   {
      char lbuf[8];
      my_psend('x',lbuf,0);
      myDeleteNamedPipe();
   }

my_pwrite(char * buf, int len)
   {
       return(my_psend('w',buf,len));
   }

my_pread(char * buf, int len)
   {
       my_psend('r',"",0);
       return(my_preceive('d',buf, len));
   }

my_psend(char type, char * buf, int len)
   {
       int ret;
       char lbuf[600];

       strncpy(lbuf,buf,len);

       lbuf[len] = type;
          TEST_PRINT("%s sends: %s\n",lbuf,"");
       ret=myWriteToNamedPipe(lbuf,len+1);
       my_peek();
       return(ret);
   }

my_preceive(char type, char * buf, int len)
   {
     int ret,t,llen;
     char lbuf[600]; 

         TEST_PRINT("%s waits for %s\n",(char*)&type,"");
     next:
       llen = myReadFromNamedPipe(lbuf, 600);
       llen -- ; t = lbuf[llen]; lbuf[llen] = '\0'; 

       if (t == type)
         {
           strncpy(buf,lbuf,llen); 
             TEST_PRINT("%s received %s\n",&type,"");
           return(llen);
         };

             TEST_PRINT("%s received %s\n",(char*)&t,""); 
       if(t == 'x')  // exit
          exit(0);
       else if(t == 'w')
         {
           local_puts(lbuf);
         }    
       else if(t == 'c')  // remote procedure call
         { 
              TEST_PRINT("%s received RPC %s\n",lbuf,"");
           ret=my_plocalcall(lbuf,llen);    // call local procedure
              TEST_PRINT("%s returns from RPC\n","","");
           my_psend('a',lbuf,ret);    // result return
         }
       else
        { 
          sprintf(lbuf," error: unexpected message >%c< instead of >%c<\n",t,type);
          pmelden("%s %s\n",lbuf,"");
        }
      goto next;
   }

void my_peek()
   {
       // handle messages with may come asynchronously

     int ret,t,llen,l1,l2;
     char lbuf[600]; 

       if(!PeekNamedPipe(the_named_pipe,lbuf,600,&llen,&l1,&l2)
             || llen<1)
          {
             TEST_PRINT("%s peek empty\n","","");
             return;
          }

       llen -- ; t = lbuf[llen]; lbuf[llen] = '\0'; 
           
           TEST_PRINT("%s peek sees message %s\n",(char*)&t, "");

       if (!(t == 'x' || t == 'c' || t == 'b' || (t == 'w' && ! slave_mode))) return;

           TEST_PRINT("%s peek processes message %s\n",(char*)&t, "");

       llen = myReadFromNamedPipe(lbuf, 600);
      
       if(t == 'x')  // exit
          exit(0);
       else if(t == 'c')  // remote procedure call
         { 
           ret=my_plocalcall(lbuf,llen);    // call local procedure
           my_psend('a',lbuf,ret);          // result return
         }
       else if(t == 'b') 
           bruch_bruch--;
       else if(t == 'w')
         {
           local_puts(lbuf);
         }    
    }

#define TIME_OUT  500

HANDLE my_popen_master(int n)
 {
       CHAR   fileName[255];

      slave_mode = 0;

      sprintf (fileName, "%s%s%s", "\\\\", ".", "\\PIPE\\Psl%d");

      the_named_pipe = 
         CreateNamedPipe (fileName,
               PIPE_ACCESS_DUPLEX                // 2 way pipe.
               ,                                 //| FILE_FLAG_OVERLAPPED,           // Use overlapped structure.
               PIPE_WAIT                         // Wait on messages.
               | PIPE_READMODE_MESSAGE           // Specify message mode pipe.
               | PIPE_TYPE_MESSAGE,
               1,                                // Maximum instance limit.
               512,                              // Buffer sizes.
               512,
               TIME_OUT,                         // Specify time out.
               NULL);                            // Security attributes.
        return(the_named_pipe);
  }

myDeleteNamedPipe()
  {
       CloseHandle(the_named_pipe);
  }


HANDLE my_popen_slave(int n)
   {
       CHAR   fileName[255];

       sprintf (fileName, "%s%s%s", "\\\\", ".", "\\PIPE\\Psl%d",n);


                      // File or Pipe handle.
                                       // Do CreateFile() to connect to the
                                       // named pipe.
       the_named_pipe = CreateFile (fileName,              // Pipe name.
                           GENERIC_WRITE          // Generic access, read/write.
                           | GENERIC_READ,
                           FILE_SHARE_READ        // Share both read and write.
                           | FILE_SHARE_WRITE ,
                           NULL,                  // No security.
                           OPEN_EXISTING,         // Fail if not existing.
                           FILE_ATTRIBUTE_NORMAL,                  // FILE_FLAG_OVERLAPPED,  // Use overlap.
                           NULL);                 // No template.
      return (the_named_pipe);
  }

myWriteToNamedPipe(char * buf, int bytes)
  {
      DWORD  retCode;
      DWORD bytesWritten;

      retCode = WriteFile (the_named_pipe, buf, bytes,
                     &bytesWritten, (LPOVERLAPPED)NULL);

      return((int)bytesWritten);
 }

myReadFromNamedPipe(char * buf, int bytes)
  {
 
      DWORD  retCode;
      DWORD bytesRead;

      while(!(retCode = ReadFile (the_named_pipe, buf, bytes, 
                      &bytesRead, (LPOVERLAPPED)NULL))) Sleep(500);

      return((int) bytesRead);
  }
