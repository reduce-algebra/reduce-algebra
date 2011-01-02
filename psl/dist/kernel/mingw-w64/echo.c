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
% (c) Copyright 1983, Hewlett-Packard Company, see the file
%            HP_disclaimer at the root of the PSL file tree
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

/*#include <sgtty.h> */
#include <stdio.h>

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

char *external_user_homedir_string()
{
  return ("");
}

char *external_anyuser_homedir_string(username)
char *username;
{
  return "";
}

void profil(u)
int u;
{}
