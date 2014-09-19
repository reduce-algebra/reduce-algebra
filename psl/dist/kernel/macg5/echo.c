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
% Status:       Experimental (Do Not Distribute)
%
% (c) Copyright 1984, Hewlett-Packard Company, all rights reserved.
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

