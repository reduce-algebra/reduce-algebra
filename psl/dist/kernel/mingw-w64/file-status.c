/*
% File:         PXK:file-status.c
% Description:  PSL Packaging for the Unix "stat" system call.
% Author:       Russell D. Fish, Computer Science Dept., University of Utah
% Created:      23-Nov-83
% Modified:     
% Mode:         Text
% Package:      
% Status:       Open Source: BSD License
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
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
%  $Id$
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

 */
 
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

#include <windows.h>
#include <winbase.h>


/* forward declaration */
int win_file_status(LPCSTR name,DWORD * buf);

/* Tag( get_file_status )
 */
int                     /* Returns "stat" value, 0 == success. */
get_file_status( char *file_name_string, void *info_block, int do_strings )
{    return ( win_file_status(file_name_string,info_block));
}
 
 

/****************************************************************************

****************************************************************************/

int win_file_status(LPCSTR name,DWORD * buf)

{ HANDLE hand;

  hand = CreateFile (name,
	   (DWORD) GENERIC_READ,
	   (DWORD) 0,
	   (LPSECURITY_ATTRIBUTES) NULL,
	   OPEN_EXISTING,
	   FILE_ATTRIBUTE_NORMAL,0);
 
  if (hand == (HANDLE) -1) return (-1); else
    {GetFileTime(hand,(FILETIME *) buf , (FILETIME *) (buf +2),
			  (FILETIME *) (buf + 4));
    CloseHandle (hand);
     return (0); }
}
