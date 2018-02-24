/*
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PXK:PSLSOCKET.C
% Description:  Interface to *ix sockets
% Author:
% Created:
% Modified:
% Mode:         Text
% Package:
% Status:       Open Source: BSD License
%
% (c) Copyright 1983, Hewlett-Packard Company, see the file
%            HP_disclaimer at the root of the PSL file tree
%
% Redistribution and use in source and binary forms, with or without
% modification, are permitted provided that the following conditions are met:
%
%    * Redistributions of source code must retain the relevant copyright
%      notice, this list of conditions and the following disclaimer.
%    * Redistributions in binary form must reproduce the above copyright
%      notice, this list of conditions and the following disclaimer in the
%      documentation and/or other materials provided with the distribution.
%
% THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
% AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
% THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
% PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNERS OR
% CONTRIBUTORS
% BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
% CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
% SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
% INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
% CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
% ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
% POSSIBILITY OF SUCH DAMAGE.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
*/

#include <stdio.h>
#include <unistd.h>
#include <strings.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>

/*
 * The functions here are (just) called from compiled code. In the
 * assembly code for the kernel the code is written with the names
 * having a leading underscore. For Linux that underscore remains
 * visible here in the C code that is linked to, while under Cygwin
 * or on a Macintosh it is not. So here I define functions whose names
 * have leading underscores if I am on Linux but not otherwise. This is
 * a bit messy and ugly but is still about the neatest I can think of
 * at present if I want one body of code to apply everywhere.
 */

#if defined __linux__ || defined __CYGWIN__
#define _(x) _ ## x
#else
#define _(x) x
#endif



/* #define PORT_NUMBER 1188 */ /* Port number to listen on.
                               Must be the same as in client!!!! */

int _(unixsocketopen)(char *name, int number)
{   struct hostent *host_info;
    struct sockaddr_in mail_addr;   /* Address structure */
    socklen_t mail_len = sizeof(struct sockaddr_in);
    int port_fd, conn_fd;
    int mail_fd, temp;
    int continue1;
    char message[80];
    char *getlogin();

    if (name == (char *) 0)
    {   /*
         *   SERVER: This program is the server side of the connection.
         *           It waits for clients to come along and requests connections.
         */

        if ((port_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        {   perror ("socket");
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
        {   perror ("bind");
            close (port_fd);
            return(-1);
        }
        /*
         *   Allow for up to 5 connection requests to be pending at one time.
         */
        if (listen (port_fd, 5) != 0)
        {   perror ("listen");
            close (port_fd);
            return(-1);
        }

        conn_fd = accept(port_fd, (struct sockaddr *)&mail_addr, &mail_len);
        return(conn_fd);
    }
    else
    {   if ((host_info = gethostbyname(name)) == NULL) /* Get inet address */
        {   fprintf (stderr,"ERROR: Unknown host %s.\n",name);
            return (-1);
        }

        /*
         *   Create a socket and then try to connect it to the server.
         */

        if ((mail_fd = socket (AF_INET, SOCK_STREAM, 0)) < 0)
        {   perror ("socket");
            return(-1);
        }

        mail_addr.sin_family = AF_INET;
        mail_addr.sin_port = number;
        bcopy (host_info->h_addr, (char *) &mail_addr.sin_addr, host_info->h_length);
        if (connect (mail_fd, (struct sockaddr *)&mail_addr, sizeof (mail_addr)) != 0)
        {   perror ("connect");
            return(-1);
        }
        return (mail_fd);
    }
}

int _(getsocket)(int mail_fd, char *string, int length)
{   int len;
    while(1)
    {   if((len = recv (mail_fd, string, length, 0)) <=0) sleep (1);
        else
        {   string[len] = (char) 0x00;
            return(len);
        }
    }
}

ssize_t _(writesocket)(int mail_fd, char *string, int length)
{   return send(mail_fd, string, length, 0);
}

int _(unixclosesocket)(int conn_fd)
{   return close(conn_fd);
}

/* end of pslsocket.c */
