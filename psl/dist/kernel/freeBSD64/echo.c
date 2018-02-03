/*
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PXK:ECHO.C
% Description:  Handle raw/cooked terminal I/O, get homedir info
% Author:       Russ Fish
% Created:      2 March 1982
% Modified:     
% Mode:         Text
% Package:      
% Status:       Open Source: BSD License

% Copyright 1983, Hewlett-Packard Company, see the file
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
#include <sys/ioctl.h>
#include <stdio.h>
#include <pwd.h>


/* TAG( EchoOff )
 * Enter charcter-at-a-time mode.
 */
void
echooff()		/* (Note names lowercased by PSL compiler... */
{
}

/* TAG( EchoOn )
 * Re-enter line I/O mode.
 */
void
echoon()
{
}


/* TAG( External_CharsInInputBuffer )
 *  Return number of characters in input buffer.
 */
void
external_charsininputbuffer( fp )
FILE * fp;		/* Ptr to stdio file structure for terminal. */
{
}
    
/* TAG( FlushStdOutputBuffer )
 *  Clear out buffer, when in EchoOff mode.
 */
void
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
  if ((ptr = getpwnam(username)))
    return(ptr -> pw_dir);
  else 
    return "";
}

void profil(u)
int u;
{}
