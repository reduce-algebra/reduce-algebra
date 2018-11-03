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

 */
 
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
 
typedef struct{
    char * string_value;        /* Interpretation of a field. */
    int numeric_value;            /* One of the stat fields. */
} stat_info;
 
/* Tag( get_file_status )
 */
int                     /* Returns "stat" value, 0 == success. */
get_file_status( file_name_string, info_block, do_strings )
char * file_name_string;        /* File to stat. */
stat_info info_block[7];        /* Space to return values. */
int do_strings;                /* Whether to interpret numbers. */
{
    /* Strings to be imported into the PSL. */
    static char write_str[25], access_str[25], change_str[25];
    char *get_mode_string(), *ctime();
#   define RET_INFO(slot,number,string) \
      ( info_block[slot].numeric_value = (number), \
    info_block[slot].string_value = (do_strings? (string) : (char *)NULL) )
#   define TIME_STRING(st_field,dest) \
      ( strncpy( dest, ctime(&stat_buff.st_field), 24 ), dest[24]='\0', dest )
 
    struct stat stat_buff;
    int stat_ret;
 
    struct passwd *uidpasswd, *getpwuid();
    struct group  *gidgroup, *getgrgid();
 
    stat_ret = stat( file_name_string, &stat_buff );
    if ( stat_ret == 0 )
    {
        uidpasswd = getpwuid( stat_buff.st_uid );
    gidgroup  = getgrgid( stat_buff.st_gid );
    RET_INFO( 0, stat_buff.st_uid, uidpasswd->pw_name );
    RET_INFO( 1, stat_buff.st_gid, gidgroup->gr_name );
    RET_INFO( 2, stat_buff.st_mode, get_mode_string( stat_buff.st_mode ) );
    RET_INFO( 3, stat_buff.st_size, NULL );    /* No string for file size. */
    RET_INFO( 4, stat_buff.st_mtime, TIME_STRING( st_mtime, write_str ) );
    RET_INFO( 5, stat_buff.st_atime, TIME_STRING( st_atime, access_str ) );
    RET_INFO( 6, stat_buff.st_ctime, TIME_STRING( st_ctime, change_str ) );
    }
    return stat_ret;
}
 
/* fmtmode() and its data lifted from ls.c and made internal to this file. */
#define internal static
internal int    m1[] = { 1, S_IREAD>>0, 'r', '-' };
internal int    m2[] = { 1, S_IWRITE>>0, 'w', '-' };
internal int    m3[] = { 2, S_ISUID, 's', S_IEXEC>>0, 'x', '-' };
internal int    m4[] = { 1, S_IREAD>>3, 'r', '-' };
internal int    m5[] = { 1, S_IWRITE>>3, 'w', '-' };
internal int    m6[] = { 2, S_ISGID, 's', S_IEXEC>>3, 'x', '-' };
internal int    m7[] = { 1, S_IREAD>>6, 'r', '-' };
internal int    m8[] = { 1, S_IWRITE>>6, 'w', '-' };
internal int    m9[] = { 2, S_ISVTX, 't', S_IEXEC>>6, 'x', '-' };
 
internal int    *m[] = { m1, m2, m3, m4, m5, m6, m7, m8, m9};
 
/* Tag( fmtmode )
 */
internal
char *
fmtmode(lp, flags)
    char *lp;
    int flags;
{
    int **mp;
 
    for (mp = &m[0]; mp < &m[sizeof(m)/sizeof(m[0])]; ) {
        register int *pairp = *mp++;
        register int n = *pairp++;
 
        while (--n >= 0 && (flags&*pairp++) == 0)
            pairp++;
        *lp++ = *pairp;
    }
    return (lp);
}
 
/* Tag( get_mode_string )
 * Parse the mode value into a string.  Based on /usr/src/bin/ls.c .
 */
char *
get_mode_string( mode )
unsigned short mode;
{
    static char mode_string[11] = "drwxrwxrwx";
 
    /* From gstat() in ls.c . */
    switch ( mode & S_IFMT ) {
 
    case S_IFDIR:
        mode_string[0] = 'd'; break;
    case S_IFBLK:
        mode_string[0] = 'b'; break;
    case S_IFCHR:
        mode_string[0] = 'c'; break;
#ifdef   S_IFSOCK        /* 4.1a and above. */
    case S_IFSOCK:
        mode_string[0] = 's'; break;
#endif
#ifdef   S_IFLNK        /* 4.1a and above. */
    case S_IFLNK:
        mode_string[0] = 'l'; break;
#endif
    default:
        mode_string[0] = '-'; break;
    }
 
    fmtmode( &mode_string[1], mode & ~S_IFMT );
 
    return mode_string;
}
