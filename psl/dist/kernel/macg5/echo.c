/*
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         ECHO.C
% Description:  Handle raw/cooked terminal I/O, get homedir info
% Author:       Russ Fish
% Created:      2 March 1982
% Modified:     
% Mode:         Text
% Package:      
% Status:       Open Source: BSD License
%
% (c) Copyright 1984, Hewlett-Packard Company, all rights reserved.
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
%
% Revisions:
%
% 21-Sep-86 (Leigh Stoller)
%  Copied from Sun kernel 3.2 directory. Changed a few function names to match
%  3.4 conventions, and deleted a few obsolete functions.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
%  $Id$
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
*/

#include <sgtty.h>
#include <sys/ioctl.h>
#include <stdio.h>
#include <pwd.h>


int modes_saved;		/* Flag to indicate initial modes saved. */
/*struct sgttyb sav_ioctlb, ioctlb;	/* TTY mode descriptor for ioctl. */
int sav_lmodeb, lmodeb;			/* Extended mode bits. */
/*struct tchars sav_tcharsb, tcharsb;	/* Terminal interrupt chars. */
/*struct ltchars sav_ltcharsb, ltcharsb;	/* Extended terminal chars. */

/* TAG( EchoOff )
 * Enter charcter-at-a-time mode.
 */
echooff()		/* (Note names lowercased by PSL compiler... */
{
return (0);
}

/* TAG( EchoOn )
 * Re-enter line I/O mode.
 */
echoon()
{
    fflush( stdout );
}


/* TAG( External_CharsInInputBuffer )
 *  Return number of characters in input buffer.
external_charsininputbuffer( fp )
FILE * fp;		/* Ptr to stdio file structure for terminal. * /
{
    int CharCnt;
    ioctl (0, FIONREAD, &CharCnt);	/* Chars waiting in tty driver. * /
    CharCnt += fp->_cnt;		/* Chars already in buffer. * /
    return CharCnt;
}
*/
    
/* TAG( FlushStdOutputBuffer )
 *  Clear out buffer, when in EchoOff mode.
 */
flushstdoutputbuffer()
{
    fflush( stdout );
}

int             getuid();

struct passwd   *getpwuid(), *getpwnam();

static int initpwdirstring = 0;
static char pwdirstring [100];

char *external_user_homedir_string()
{
  struct passwd *ptr;
  if (initpwdirstring != 0) return (pwdirstring);

  if ((ptr = getpwuid(getuid())) != NULL)
    { initpwdirstring = 1;
    strcpy(pwdirstring , (ptr->pw_dir));
    return(ptr->pw_dir); }
  
  else {
    fprintf(stderr, "Error in external_user_homedir_string()\n");
    return ("");
  }
}

char *external_anyuser_homedir_string(username)
char *username;
{
  struct passwd *ptr;
  if (ptr = getpwnam(username))
    return(ptr -> pw_dir);
  else 
    return "";
}

