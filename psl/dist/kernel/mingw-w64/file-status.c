/*
 * file-status.c - PSL Packaging for the Unix "stat" system call.
 *
 * Author:    Russell D. Fish
 *         Computer Science Dept.
 *         University of Utah
 * Date:    Wed Nov 23 1983
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
