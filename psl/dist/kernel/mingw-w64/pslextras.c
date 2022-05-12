/*
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PXK:PSLEXTRAS.C
% Description:  Miscellaneous support routines.
% Author:       RAM, HP/FSD
% Created:      9-Mar-84
% Modified:     21-Mar-85 11:25:52
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
%
% Revisions:
%
% 05-Apr-88 (Julian Padget)
%  Reinstated alarm and ualarm (again)
% 29-May-87 (Leigh Stoller & Harold Carr)
%  Added external_setenv and friends.
% 21-Mar-85 11:09:00 (Scott Marovich)
%  Rewrite "timc()" to return time since 1st call, and never cream LISP tag.
% 21-Feb-85 09:02:49 (Vicki O'Day)
%  Fixed bug in uxwritefloat - it was setting the length field of the printable
%  string incorrectly.
% 18-Jul-84 11:14:24 (RAM)
%  Added external_time.  Put call to expand_file_name in external_stat,
%  external_link, and external_unlink.
% 10-Jul-84 (Vicki O'Day)
%  Added external_stat, external_link and external_unlink.
% 29-Jun-84 14:15:53 (RAM)
%  Removed hp_quit (obsolete).
% 27-Jun-84 (Vicki O'Day)
%  Added external_strlen and external_getenv.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
%  $Id$
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
*/
 
#include <windows.h>
#include <stdio.h>
#include <time.h>
#include <sys/stat.h>
#include <direct.h>

/*
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>

*/ 

extern int Debug;

unsigned int
external_alarm (unsigned int sec)
{
  /*  alarm (sec); */
  return (0);
}
 
useconds_t
external_ualarm (useconds_t usec, useconds_t repeat)
{
  /*  ualarm (usec, repeat); */
  return (0);
}

char *expand_file_name ();    /* from unix-io.c */
 
/* Tag( external_time )
 */
time_t external_time (time_t *tloc)
{
  return (time (tloc));
}

/* Tag( external_timc )
 */
struct tms
{
  clock_t tms_utime;		/* User CPU time.  */
  clock_t tms_stime;		/* System CPU time.  */

  clock_t tms_cutime;		/* User CPU time of dead children.  */
  clock_t tms_cstime;		/* System CPU time of dead children.  */
};

clock_t
external_timc (struct tms *buf)
{
  FILETIME creation_time, exit_time, kernel_time, user_time;
  BOOL ret = 0;

  while (!ret)
    {
      ret = GetProcessTimes (GetCurrentProcess (), &creation_time, &exit_time,
			     &kernel_time, &user_time);
    }

  buf->tms_stime = (((unsigned long long) kernel_time.dwHighDateTime << 32)
		    + ((unsigned)kernel_time.dwLowDateTime)) / 10; 
  buf->tms_utime =  (((unsigned long long) user_time.dwHighDateTime << 32)
		     + ((unsigned)user_time.dwLowDateTime)) / 10; 
  buf->tms_cutime = 0LL;
  buf->tms_cstime = 0LL;

  /* time in microseconds */
  return buf->tms_utime;
}
 
/* Tag( external_stat )
 */
int external_stat (char *path, struct stat *buf)
{
  return stat (expand_file_name (path), buf);
}

int external_mkdir (path, mode)
     char * path;
     mode_t mode;
{ 
  return _mkdir (expand_file_name(path)); 
}

int external_rmdir (path)
    char * path;
{ 
  return _rmdir (expand_file_name(path));
}

/* Tag( external_link )
 */
int external_link (char *oldpath, char *newpath)
{
  return CreateHardLink (expand_file_name (newpath),
			 expand_file_name (oldpath), NULL);
}

/* Tag( external_unlink )
 */
int external_unlink (char *path)
{
  return (DeleteFile (expand_file_name (path)) == 0 ? -1 : 0);
}

/* Tag( external_strlen )
 */
int external_strlen (char *s)
{
  return strlen(s);
}

/* Tag( external_getenv )
 */
char *external_getenv (char *name)
{
  return getenv(name);
}
 
int external_setenv (char *var, char *val)
{
  char *envnew;

  envnew = (char *) malloc (strlen(var) + strlen(val) + 2);
  strcpy(envnew, var);
  strcat(envnew, "=");
  strcat(envnew, val);
  return(_putenv (envnew));
}
 
#define LISPEOF  4      /* Lisp uses ctrl-D for end of file */
 
/* Tag( unixreadrecord )
 */
int unixreadrecord(fp, buf)
     FILE *fp;
     char *buf;
{
  int i;
  char c;
  for (i=0, c=' '; ((c != LISPEOF) && (c != '\n')); i++)
    {
      c = fgetc(fp);
      if (c == EOF )
    c = LISPEOF;
      *buf++ = c;
    }
  return i;
}
 
/* Tag( unixwriterecord )
 */
int unixwriterecord(fp, buf, count)
     FILE *fp;
     char *buf;
int  count;
{
  int i;
  for (i=0; i<count; i++, buf++)
    fputc(*buf, fp);
}

int
mprotect_exec (void *addr,  long long size)
{
  DWORD OldProtect;

  return VirtualProtect (addr, size, PAGE_EXECUTE_READWRITE, &OldProtect);
}

#if (USE_WIN_HEAPFUNCTIONS != 1)

/*
  winsup/cygwin/dlmalloc.c

  Emulation of sbrk for WIN32
  All code within the ifdef WIN32 is untested by me.
*/

#ifndef ASSERT
#define ASSERT(expr) ((void)0)
#endif
    
#define malloc_pagesize (sysinfo_cache.dwPageSize)
#define malloc_allocation_unit	(sysinfo_cache.dwAllocationGranularity)

#define ROUND_UP(p, align)   (((DWORD64)(p) + (align)-1) & ~((align)-1))
#define ROUND_DOWN(p, align) ((DWORD64)(p) & ~((align)-1))
#define RVA_TO_PTR(rva) ((unsigned char *)((DWORD64)(rva) + (DWORD64)GetModuleHandleA (NULL)))

#define AlignPage(add) (((add) + (malloc_pagesize-1)) & \
			~(malloc_pagesize-1))

/* resrve 64MB to insure large contiguous space */
#define RESERVED_SIZE (1024*1024*64)
#define NEXT_SIZE (2048*1024)
#define TOP_MEMORY ((unsigned long long)((1LL << 56)-1))

/* This gives us the page size and the size of the allocation unit on WIN64. */
SYSTEM_INFO sysinfo_cache;
BOOL sysinfo_cache_init = 0;

struct GmListElement;
typedef struct GmListElement GmListElement;

struct GmListElement
{
  GmListElement* next;
  void* base;
};

static GmListElement* head = 0;
static unsigned long long gNextAddress = 0;
static unsigned long long gAddressBase = 0;
static unsigned long long gAllocatedSize = 0;

static GmListElement*
makeGmListElement (void* bas)
{
  GmListElement* this;
  this = (GmListElement*)(void*)LocalAlloc (0, sizeof (GmListElement));
  ASSERT (this);
  if (this)
    {
      this->base = bas;
      this->next = head;
      head = this;
    }

  return this;
}

void
gcleanup ()
{
  BOOL rval;
  ASSERT ( (head == NULL) || (head->base == (void*)gAddressBase));
  if (gAddressBase && (gNextAddress - gAddressBase))
    {
      rval = VirtualFree ((void*)gAddressBase,
			  gNextAddress - gAddressBase,
			  MEM_DECOMMIT);
      ASSERT (rval);
    }
  while (head)
    {
      GmListElement* next = head->next;
      rval = VirtualFree (head->base, 0, MEM_RELEASE);
      ASSERT (rval);
      LocalFree (head);
      head = next;
    }
}

#ifndef _SYS_UNISTD_H
static void*
findRegion (void* start_address, SIZE_T size)
{
  SIZE_T result;
  MEMORY_BASIC_INFORMATION info;
  while ((unsigned long long)start_address < TOP_MEMORY)
    {
      if (Debug > 0)
        fprintf(stderr,"Calling VirtualQuery with %llx\n",start_address);
      result = VirtualQuery (start_address, &info, sizeof (info));
      if (result == 0 && Debug > 0) {
	fprintf(stderr,"VirtualQuery returned 0\n");
      } 
      if (Debug > 0) {
        fprintf(stderr,"VirtualQuery State = %d %llX %llX %llx(%lld)\n",
                info.State,info.BaseAddress,info.AllocationBase,
                info.RegionSize, info.RegionSize);
      }
      if (info.State != MEM_FREE) {
	start_address = (char*)info.BaseAddress + info.RegionSize;
      }
      else if (info.RegionSize >= size)
	return start_address;
      else
	start_address = (char*)info.BaseAddress + info.RegionSize;
    }
  return NULL;
}

/* Return pointer to section header for named section. */
extern PIMAGE_SECTION_HEADER _FindPESectionByName (const char *);

static void*
findBase (SIZE_T size)
{
/* Info for managing our preload heap, which is essentially a fixed size
   data area in the executable.  */
  PIMAGE_SECTION_HEADER preload_heap_section = _FindPESectionByName (".bss");

  unsigned long long base =
    ROUND_UP ((RVA_TO_PTR (preload_heap_section->VirtualAddress)
	       + preload_heap_section->Misc.VirtualSize),
	      malloc_allocation_unit);

  return findRegion ((void *)base, size);
}

/*
 * Shift start address of memory by this amount if first attempt fails
 */
#define RETRY_INCREMENT 0x10000 
void*
sbrk (SIZE_T size)
{
  void* tmp;

  /* Cache page size, allocation unit, processor type, etc.  */
  if (!sysinfo_cache_init)
    {
      GetSystemInfo (&sysinfo_cache);
      sysinfo_cache_init = 1;
    }

  if (size > 0)
    {
      if (gAddressBase == 0)
	{
	  gAllocatedSize = max (RESERVED_SIZE, AlignPage (size));
          if (Debug > 0)
 	    fprintf(stderr,"sbrk: size: %lld, allocated: %lld\n",
                    size,gAllocatedSize);
	  tmp = findBase (gAllocatedSize);
	  gNextAddress = gAddressBase =
	    (unsigned long long)VirtualAlloc (tmp,
			      gAllocatedSize,	MEM_RESERVE, PAGE_NOACCESS);
          if (gNextAddress == 0) {
            if (Debug > 0)
              fprintf(stderr,"sbrk error: %d %lld %llX retrying \n",
                      GetLastError(),gAllocatedSize,tmp);
            tmp = findRegion (tmp+RETRY_INCREMENT,gAllocatedSize);
            gNextAddress = gAddressBase =
            (unsigned long long)VirtualAlloc (tmp,
                              gAllocatedSize,   MEM_RESERVE, PAGE_NOACCESS);
            if (gNextAddress == 0 && Debug > 0) {
              fprintf(stderr,"sbrk error: %d %lld %llX fail\n",
                      GetLastError(),gAllocatedSize,tmp);
	    }
	  }
	} else if (AlignPage (gNextAddress + size) > (gAddressBase +
						      gAllocatedSize))
	{
	  long new_size = max (NEXT_SIZE, AlignPage (size));
	  void* new_address = (void*)(gAddressBase+gAllocatedSize);
	  do
	    {
	      new_address = findRegion (new_address, new_size);
	      if (new_address == 0) {
                errno = ENOMEM;
		return (void*)-1;
              }
	      gAddressBase = gNextAddress =
		(unsigned long long)VirtualAlloc (new_address, new_size,
					    MEM_RESERVE, PAGE_NOACCESS);
	      // repeat in case of race condition
	      // The region that we found has been snagged
	      // by another thread
	    }
	  while (gAddressBase == 0);
	  ASSERT (new_address == (void*)gAddressBase);
	  gAllocatedSize = new_size;

	  if (!makeGmListElement ((void*)gAddressBase)) {
            errno = ENOMEM;
	    return (void*)-1;
          }
	}
      if ((size + gNextAddress) > AlignPage (gNextAddress))
	{
	  void* res;
	  res = VirtualAlloc ((void*)AlignPage (gNextAddress),
			      (size + gNextAddress -
			       AlignPage (gNextAddress)),
			      MEM_COMMIT, PAGE_READWRITE);
	  if (res == 0) {
            errno = ENOMEM;
	    return (void*)-1;
          }
	}
      tmp = (void*)gNextAddress;
      gNextAddress = (unsigned long long)tmp + size;
      if (tmp == 0 && Debug > 0)
        fprintf(stderr,"sbrk error (tmp): %d\n",GetLastError());
      return tmp;
    }
  else if (size < 0)
    {
      unsigned long long alignedGoal = AlignPage (gNextAddress + size);
      /* Trim by releasing the virtual memory */
      if (alignedGoal >= gAddressBase)
	{
	  VirtualFree ((void*)alignedGoal, gNextAddress - alignedGoal,
		       MEM_DECOMMIT);
	  gNextAddress = gNextAddress + size;
	  return (void*)gNextAddress;
	}
      else
	{
	  VirtualFree ((void*)gAddressBase, gNextAddress - gAddressBase,
		       MEM_DECOMMIT);
	  gNextAddress = gAddressBase;
          errno = ENOMEM;
	  return (void*)-1;
	}
    }
  else
    {
      return (void*)gNextAddress;
    }
}
#endif

#else

void gcleanup() {}

#endif

/*
#define _XOPEN_SOURCE 500
#include <signal.h>
*/

int
sigrelse (int sig)
{
  return (0);
}

/*
#include <unistd.h>
*/

int /* pid_t */
fork (void)
{
  return (0);
}

long
gethostid (void)
{
  return (0);
}

/*
#include <sys/types.h>
#include <sys/wait.h>
*/

pid_t
wait (int *status)
{
  return (0);
}

/*
#include <sys/types.h>
#include <sys/shm.h>
*/

typedef long long key_t;
typedef unsigned int uid_t;
typedef unsigned int gid_t;
typedef unsigned long int shmatt_t;

/* Data structure used to pass permission information to IPC operations.  */
struct ipc_perm
  {
    key_t key;				/* Key.  */
    uid_t uid;				/* Owner's user ID.  */
    gid_t gid;				/* Owner's group ID.  */
    uid_t cuid;				/* Creator's user ID.  */
    gid_t cgid;				/* Creator's group ID.  */
    unsigned short int mode;		/* Read/write permission.  */
    unsigned short int __pad1;
    unsigned short int __seq;		/* Sequence number.  */
    unsigned short int __pad2;
    unsigned long int __unused1;
    unsigned long int __unused2;
  };

/* Data structure describing a shared memory segment.  */
struct shmid_ds
  {
    struct ipc_perm shm_perm;		/* operation permission struct */
    size_t shm_segsz;			/* size of segment in bytes */
    time_t shm_atime;			/* time of last shmat() */
    time_t shm_dtime;			/* time of last shmdt() */
    time_t shm_ctime;			/* time of last change by shmctl() */
    pid_t shm_cpid;			/* pid of creator */
    pid_t shm_lpid;			/* pid of last shmop */
    shmatt_t shm_nattch;		/* number of current attaches */
    unsigned long int __unused4;
    unsigned long int __unused5;
  };

void *
shmat (int shmid, const void *shmaddr, int shmflg)
{
  return (NULL);
}

int
shmctl (int shmid, int cmd, struct shmid_ds *buf)
{
  return (0);
}

int
shmdt (const void *shmaddr)
{
  return (0);
}

int
shmget (key_t key, size_t size, int shmflg)
{
  return (0);
}

/*
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
*/
/* Structure used for argument to `semop' to describe operations.  */
struct sembuf
{
  unsigned short int sem_num;	/* semaphore number */
  short int sem_op;		/* semaphore operation */
  short int sem_flg;		/* operation flag */
};

int
semctl (int semid, int semnum, int cmd, ...)
{
  return (0);
}

int
semget (key_t key, int nsems, int semflg)
{
  return (0);
}

int
semop (int semid, struct sembuf *sops, size_t nsops)
{
  return (0);
}

#define REGBUFLEN 1024
static char regbuffer[REGBUFLEN];

long
get_registry_value(char *key, char *subkey, char* name, long long *infobuf)
{
  int length = REGBUFLEN;
  HKEY hKey;
  HKEY keyhandle;
  LONG r, r1;
  DWORD type;

  if (strcmp(key,"HKCR") == 0) {
    hKey = HKEY_CLASSES_ROOT;
  }
  else if (strcmp(key,"HKCC") == 0) {
    hKey = HKEY_CURRENT_CONFIG;
  }
  else if (strcmp(key,"HKCU") == 0) {
    hKey = HKEY_CURRENT_USER;
  }
  else if (strcmp(key,"HKLM") == 0) {
    hKey = HKEY_LOCAL_MACHINE;
  }
  else if (strcmp(key,"HKU") == 0) {
    hKey = HKEY_USERS;
  }
  else {
  // unknown keytype
    return -1;
  }

//  printf("Starting with type %s/%d infobuf=%lld/%llx\n",key,hKey,infobuf,infobuf);
  r1 = RegOpenKeyEx(hKey,
                    (LPCTSTR) subkey,
		    (DWORD) 0,
                    KEY_QUERY_VALUE,
                    &keyhandle);

//  printf("RegOpenKeyEx: %ld %ld\n",r1,keyhandle);
  if (r1 != ERROR_SUCCESS) {
    return r1;
  }

  r = RegQueryValueEx(keyhandle,
                      (LPCTSTR) name,
                      NULL,
		      (LPDWORD)&type,
                      (PVOID)regbuffer,
                      (LPDWORD)&length);

//  printf("RegQueryValueEx: %ld %ld\n",r,length);


  r1 = RegCloseKey(keyhandle);
  if (r != ERROR_SUCCESS) {
    return r;
  }
  else {
    infobuf[0] = type;
    infobuf[1] = length;
    infobuf[2] = (long long) regbuffer;
//    printf("Returning with type %d, length %d, resultbuf = %lld/%llX\n",
//            type,length,regbuffer,regbuffer);
    return 0;
  }
}


