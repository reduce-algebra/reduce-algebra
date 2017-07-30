#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 

#include <winsock.h>

/* #define PORT_NUMBER 1188    /* Port number to listen on. 
                               Must be the same as in client!!!! */ 

int
unixsocketopen(name , number)

char * name;
int number;

{  struct hostent *host_info;
   struct sockaddr_in mail_addr;   /* Address structure */ 
   int mail_len = sizeof(struct sockaddr_in); 
   int port_fd, conn_fd; 
   int mail_fd, temp;
   int continue1;
   char message[80]; 
 
  if (name == (char *) 0)
  {
/*
 *   SERVER: This program is the server side of the connection.
 *           It waits for clients to come along and requests connections.
 */

   if ((port_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) 
   { 
      perror ("socket"); 
      return(-1); 
   } 
   mail_addr.sin_family = AF_INET;     /* Setup address structure */ 
   mail_addr.sin_port = number; 
   mail_addr.sin_addr.s_addr = INADDR_ANY; 
/* 
 *   Open up a socket for us to accept connections on and
 *   bind an address to it which other systems can see.
 */
   if (bind (port_fd, (struct sockaddr *)&mail_addr, mail_len) != 0) 
   { perror ("bind"); close (port_fd); return(-1); } 
/* 
 *   Allow for up to 5 connection requests to be pending at one time. 
 */ 
   if (listen (port_fd, 5) != 0) 
   { perror ("listen"); close (port_fd); return(-1); } 
 
  conn_fd = accept (port_fd, (struct sockaddr *)&mail_addr, &mail_len);
  return(conn_fd);
  }
  else
  {
     if ((host_info = gethostbyname(name)) == NULL) /* Get inet address */
   { fprintf (stderr,"ERROR: Unknown host %s.\n",name); return (-1); }
      
/*
 *   Create a socket and then try to connect it to the server.
 */
 
   if ((mail_fd = socket (AF_INET, SOCK_STREAM, 0)) < 0)
   { perror ("socket"); return(-1); }
      
   mail_addr.sin_family = AF_INET;
   mail_addr.sin_port = number;
   memcpy ((char *) &mail_addr.sin_addr, host_info->h_addr, host_info->h_length); 
   if (connect (mail_fd, (struct sockaddr *)&mail_addr, sizeof (mail_addr)) != 0)
   { perror ("connect"); return(-1); }
   return (mail_fd);   
  }
}

int
getsocket (mail_fd , string , length)

int mail_fd,length;
char * string;

{ int len;
  while(1)
  {
  if((len = recv (mail_fd, string, length, 0)) <=0) sleep (1); 
  else { string[len] = (char) 0x00;
         return(len);}}}

long
writesocket (mail_fd , string , length) 

int mail_fd,length; 
char * string; 
 
{ send (mail_fd, string, length, 0); }

int
unixclosesocket (conn_fd)
int conn_fd;

{ close (conn_fd); }

