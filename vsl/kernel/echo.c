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

% Copyright 1983, Hewlett-Packard Company, see the file
%            HP_disclaimer at the root of the PSL file tree

%Changed a few function names to match
%  3.4 conventions, and deleted a few obsolete functions.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
*/

/*#include <sgtty.h> */
#include <sys/ioctl.h>
#include <stdio.h>
#include <pwd.h>


/* TAG( EchoOff )
 * Enter charcter-at-a-time mode.
 */
echooff()		/* (Note names lowercased by PSL compiler... */
{
}

/* TAG( EchoOn )
 * Re-enter line I/O mode.
 */
echoon()
{
}


/* TAG( External_CharsInInputBuffer )
 *  Return number of characters in input buffer.
 */
external_charsininputbuffer( fp )
FILE * fp;		/* Ptr to stdio file structure for terminal. */
{
}
    
/* TAG( FlushStdOutputBuffer )
 *  Clear out buffer, when in EchoOff mode.
 */
flushstdoutputbuffer()
{
    fflush( stdout );
}

int             getuid();
struct passwd   *getpwuid(), *getpwnam();

char *external_user_homedir_string()
{
  struct passwd *ptr;
  
  if ((ptr = getpwuid(getuid())) != NULL)
    return(ptr->pw_dir);
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

void pppprofil(u)
int u;
{}
