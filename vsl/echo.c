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
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
*/

/*
 * There used to be a collection of comments here describing revisions
 * made from about 1982 to 1989. I think those are by now of interest
 * to archaeologists! So anybody who wants to see them can consult older
 * copies of this file in the repositories. It is neverthless proper to
 * record the names of those who (in addition to the original author)
 * have contributed:
 *     Leight Stoller
 */


#include <stdio.h>

#ifndef __WIN64__
#include <sys/ioctl.h>
#include <pwd.h>
#endif

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

#ifdef __linux__
#define _(x) _ ## x
#else
#define _(x) x
#endif



/* TAG( EchoOff )
 * Enter character-at-a-time mode.
 */
void _(echooff)()   /* (Note names lowercased by PSL compiler... */
{
}

/* TAG( EchoOn )
 * Re-enter line I/O mode.
 */
void _(echoon)()
{
}


/* TAG( External_CharsInInputBuffer )
 *  Return number of characters in input buffer.
 */
void _(external_charsininputbuffer)(FILE *fp)
{
}

/* TAG( FlushStdOutputBuffer )
 *  Clear out buffer, when in EchoOff mode.
 */
void _(flushstdoutputbuffer)()
{   fflush( stdout );
}

int             getuid();
struct passwd   *getpwuid(), *getpwnam();

char *_(external_user_homedir_string)()
{   struct passwd *ptr;

    if ((ptr = getpwuid(getuid())) != NULL)
        return(ptr->pw_dir);
    else
    {   fprintf(stderr, "Error in external_user_homedir_string()\n");
        return ("");
    }
}

char *_(external_anyuser_homedir_string)(const char *username)
{   struct passwd *ptr;
    if ((ptr = getpwnam(username)) != NULL) return(ptr -> pw_dir);
    else return "";
}

void _(pppprofil)(int u)
{}

/* end of echo.c */
