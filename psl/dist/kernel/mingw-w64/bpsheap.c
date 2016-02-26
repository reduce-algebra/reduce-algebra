/*
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         bpsheap.c
% Description:  Code to dynamically set up bps and heap structures
% Author:       RAM, HP/FSD
% Created:      9-Mar-84
% Modified:
% Mode:         Text
% Package:
%
% (c) Copyright 1982, University of Utah
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
%
% Revisions:
%
% 11-Aug-88 (Julian Padget)
%  Added initialization of bpslowerbound in setupbps().
% 07-Apr-87 (Harold Carr & Leigh Stoller)
%  Put in error checking to ensure that the memory pointers will fit in
%   info field of the lisp item.
% 21-Dec-86 (Leigh Stoller)
%  Added allocatemorebps function, called from try-other-bps-spaces in
%   allocators.sl.
% 18-Dec-86 (Leigh Stoller)
%  Changed to newer model. Bps is now defined in bps.c so that unexec can
%  alter the text/data boundry. Took out code that allowed command line
%  modification of bpssize. (Now set in the Makefile). Added setupbps()
%  that initialzes nextbps and lastbps.
% 20-Sep-86 (Leigh Stoller)
%  Removed assembler alias statements because they are not portable. Instead,
%  a sed script will be used to convert the _variables of C to VARIABLES of
%  PSL.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
*/

long long unexec();

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>    /* for PAGESIZE */
#ifndef PAGESIZE
#define PAGESIZE 4096
#endif

#include <windows.h>

#if (USE_WIN_HEAPFUNCTIONS == 1)

#include <winbase.h>

HANDLE heapHandle;
LPVOID heapBaseAddr;

#else

#ifndef _SYS_UNISTD_H
extern void *sbrk (long long size);
#endif

#endif

void *install_function_table(ULONG64 codebase, ULONG size);


/* Use 1 if using compacting collector ($pxnk/compact-gc.sl).
Use 2 if using copying collector ($pnk/copying-gc.sl).
Be sure to update $pxnk/load-psl.sl to include correct collector. */

#define NUMBEROFHEAPS 2

#define MINSIZE        1000     /* Default total in number of bytes. */
#define MALLOCSIZE     500000   /* Default size for OS support functions. */
#define EXTRABPSSIZE   300000   /* Minimum amount to increase bps by. */
#define MINIMUMHEAPADD 20000    /* Minimum amount to increase heap by */


#ifndef BPSSIZE
#define BPSSIZE         1600000    /* Default bps size in number of bytes */
#endif

extern int Debug;


char *  imagefile;
char *  abs_imagefile = NULL;	/* like imagefile, but as an absolute pathname  */
long long   max_image_size;
long long   oldbreakvalue;

long long bpscontrol[2];

extern long long  alreadysetupbpsandheap;
extern long long  hashtable;
extern char bps[];
extern long long  symval;
extern long long  lastbps;
extern long long  nextbps;
extern long long  bpslowerbound;
extern long long  _infbitlength_;

extern long long  heaplowerbound;
extern long long  heapupperbound;
extern long long  heaplast;
extern long long  heaptrapbound;

extern long long  oldheaplowerbound;
extern long long  oldheapupperbound;
extern long long  oldheaplast;
extern long long  oldheaptrapbound;

/* Write this ourselves to keep from including half the math library */
static power(x, n)
int x, n;
{
int i, p;

p = 1;
for (i = 1; i <= n; ++i)
p = p * x;
return(p);
}

int creloc (long long array[], long len, long long diff, long long lowb);
char * cygpath2winpath(char * cygpath);

setupbpsandheap(argc,argv)
int argc;
char *argv[];
{
  long long ohl,ohtb,ohlb,ohub,hl,htb,hlb,hub,diff;
  int memset = 1;
  FILE * imago;
  long long headerword [8];
  long long i, total, bpssize, heapsize, mallocsize;
  long long current_size_in_bytes, heapsize_in_bytes;
  double bpspercent, heappercent;
  char   *argp, *scanptr, *scanformat;
  int ii1,ii2,ii3,ii4,ii5,ii6,ii7,ii8,ii9,ii10,ii11;
  long hugo;

  char *prog;
  char *imagefile_default;

  total        = MINSIZE;
  mallocsize    = MALLOCSIZE;

  for (i=1; i<argc-1; i++)
    {
      argp = argv[i];
      if (*argp++ == '-')
	{
	  scanformat = "";
	  switch (*argp++) {
	  case 't': scanptr = (char *)&total;
	    memset = 1;
	    switch (*argp) {
	    case 'x': scanformat = "%x";
	      break;
	    case 'd': scanformat = "%d";
	      break;
	    }
	    break;
	  case 'm': scanptr = (char *)&mallocsize;
	    switch (*argp) {
	    case 'x': scanformat = "%lx";
	      break;
	    case 'd': scanformat = "%ld";
	      break;
	    }
	    break;
	  case 'f': imagefile = argv[i+1]; break;
	  }
	  if (*scanformat != 0)
	    sscanf(argv[i+1],scanformat,scanptr);
	}
    }   /* end of for loop -- arg vector searched */

  /* insure valid values */

  if (total < 1000000)  total = total * 1000000;

  if (total == 0)
    total = MINSIZE;

  if (mallocsize <= 0)
    mallocsize = MALLOCSIZE;

  /* Reserve some space for C's usr of io buffers, etc. By mallocing then
     freeing, the memory is sbrk'ed onto the image, but available for future
     calls to malloc, which will not need to call sbrk again. */

  bpssize = BPSSIZE;
  heapsize_in_bytes = total - bpssize;

  /* On systems in which the image does not start at address 0, this won't
     really allocate the full maximum, but close enough. */
#if (USE_WIN_HEAPFUNCTIONS != 1)
  current_size_in_bytes = (((long long) sbrk(0))<<5)>>5;
#endif
  max_image_size = 0x1000000000000LL; /* 1 more than allowable size */

  if ((heapsize_in_bytes + current_size_in_bytes) >= max_image_size) {
    heapsize_in_bytes = max_image_size - current_size_in_bytes;
    total = heapsize_in_bytes + bpssize;
    printf("total %llx %llx %llx\n",heapsize_in_bytes , current_size_in_bytes,total);
    printf("Size requested will result in pointer values larger than\n");
    printf(" PSL items can handle. Will allocate maximum size instead.\n\n");
  }

#if (NUMBEROFHEAPS == 2)
  heapsize =(heapsize_in_bytes / 8) * 4;  /* insure full words */
#else
  heapsize =(heapsize_in_bytes / 8) * 8;  /* insure full words */
#endif

  heappercent = ((float) (total - bpssize) / total) * 100.0;
  bpspercent  = ((float) bpssize / total) * 100.0;

  if (imagefile == NULL)
    {
      prog = strrchr(argv[0], '\\');
      if (prog == NULL)
	prog = argv[0];
      else
	prog++;
      
      if (strncmp (prog, "bpsl", 4))
	{
	  imagefile_default = malloc (strlen(argv[0]) + 5);
	  strcpy(imagefile_default, argv[0]);
	  strcat(imagefile_default, ".img");
	  
	  if (access(imagefile_default, R_OK) == 0)
	    imagefile = imagefile_default;
	  else
	    free (imagefile_default);
	}
    }

  if (imagefile == NULL) {
    if (Debug > 0) {
      printf("Setting heap limit as follows:\n");
      printf("Total heap & bps space = %lld (%llx) bps = %.2f, heap = %.2f\n",
	     total, total, bpspercent, heappercent);
    }
  }

  setupbps();
  getheap(heapsize);

  if (imagefile == NULL) {
    printf("bpsaddr = %lld (%llX), heapaddr = %lld (%llX)\n",
	   bpslowerbound, bpslowerbound,
	   heaplowerbound, heaplowerbound);

    printf("bpssize = %lld (%llX), heapsize = %lld (%llX)\nTotal image size = %lld (%llX)\n",
	   bpssize, bpssize,
	   heapsize, heapsize,
#if (USE_WIN_HEAPFUNCTIONS == 1)
	   oldbreakvalue, oldbreakvalue);
#else
    (long long) sbrk(0), (long long) sbrk(0));
#endif
}

if (imagefile != NULL) {
  ohl = oldheaplowerbound; ohub = oldheapupperbound;
  ohl =  oldheaplast; ohtb = oldheaptrapbound;
  hlb = heaplowerbound; hub = heapupperbound;
  hl =  heaplast; htb = heaptrapbound;
  /* save the new values around restore of the old ones */

  imagefile = cygpath2winpath(imagefile);
  imago = fopen (imagefile,"rb");
  if (imago == NULL) {
    perror (imagefile);
    exit (-1);
  }
  printf("Loading image file: %s \n",imagefile); 
  fread (headerword,8,2,imago);
  unexec();      /* set control vector */
  if (bpscontrol[0] != headerword[0] || bpscontrol[1] != headerword[1])
    { printf(" Cannot start the image with this bpsl \n");
      printf(" %lx != %llx, %lx != %llx\n", bpscontrol[0], headerword [0], bpscontrol[1], headerword[1]);
      exit (-19);
    }
  fread (headerword,8,4,imago);
  hugo = fread (&symval,1,headerword[0],imago);
  if (Debug > 0) {
    printf("neu: %lx => %lx\n",hlb, heaplowerbound);
  }
  diff = hlb-heaplowerbound;
  //       if (hlb < heaplowerbound)
  //             {creloc(&symval,headerword[0]/8,diff,hlb -1);} 
  //        else
  {creloc(&symval,headerword[0]/8,diff, heaplowerbound -1);}

  if (hugo != headerword[0]) read_error();
  
  hugo = fread ((char*)hlb,1,headerword[1],imago);
  //       if (hlb < heaplowerbound)
  //	 {creloc((long long *)hlb,headerword[1]/8,diff,hlb -1);}
  //       else
  {creloc((long long *)hlb,headerword[1]/8,diff, heaplowerbound -1);}
  heaplast += diff;
  
  if (hugo != headerword[1]) read_error();
  hugo = fread (&hashtable,1,headerword[2],imago);
  if (hugo != headerword[2]) read_error();
  hugo = fread ((char*)bpslowerbound,1,headerword[3],imago);
  if (hugo != headerword[3]) read_error();
  fclose (imago);
  if (memset) {
    oldheaplowerbound = ohl; oldheapupperbound = ohub;
    oldheaplast = ohl; oldheaptrapbound = ohtb;
    heaplowerbound = hlb; heapupperbound = hub;
    heaptrapbound = htb;}
  abs_imagefile = _fullpath(NULL,imagefile,_MAX_PATH);
  return (4711);
 }
return (0);

}

read_error()
{
  printf("file too short\n");
  exit(-1);
}

/* The current procedure is to convert the starting address of the char
   array defined in bps.c to an address and store it in nextbps. A check
   is made to make sure that nextbps falls on an even word boundry.
*/

extern int mprotect_exec (char *p,  long long bpssize);

setupbps ()
{
  char *p = (char *) bps;
  long long bpssize;
  char c;

  nextbps  =  ((long long)bps + 7) & ~7;        /* Up to a multiple of 8. */
  bpslowerbound = nextbps;
  lastbps  =  ((long long)bps + BPSSIZE) & ~7;    /* Down to a multiple of 8. */
  p = (char *)(( bpslowerbound  -1) & ~(PAGESIZE-1));
  bpssize =  ((BPSSIZE + PAGESIZE-1) & ~(PAGESIZE-1));
  if (!(nextbps = (long long) install_function_table ((ULONG64) nextbps, bpssize))) {
    exit(-1);
  }
  if (!mprotect_exec (p, bpssize)) {
    perror("Couldn’t mprotect");
    exit(errno);
  }
}

/* Allocate alternate bps space. Note: The use of sbrk(), and the fact that
   nextbps is now greater than heaplast means that unexec should be not be
   tried after this routine is called. The image would be huge.
 */
allocatemorebps()
{
  int old_nextbps = nextbps;

#if (USE_WIN_HEAPFUNCTIONS == 1)

  /* always allocate two bytes more so that we can increment to an even
   * number
   */
  nextbps = (long long) HeapAlloc(heapHandle,(DWORD) 0,EXTRABPSSIZE + 2);

  if (nextbps == 0) {
    nextbps = old_nextbps;
    return 0;
  }

  if ((nextbps + EXTRABPSSIZE)  >= max_image_size) {
    /* Cannot use this address */
    HeapFree(heapHandle, (DWORD) 0, (LPVOID) nextbps);
    return 0;
  }

  if (nextbps % 2 == 1) {
    nextbps++;
  }

#else

  long long current_size_in_bytes;

  current_size_in_bytes = (long long)sbrk(0);

  if ((current_size_in_bytes + EXTRABPSSIZE) >= max_image_size)
    return(0);

  if (((long long)sbrk(0)) % 2)      /* force to even word boundary*/
     nextbps = (long long)sbrk(1);

  nextbps = (long long)sbrk(EXTRABPSSIZE);   /* allocate extra BPS */
  if (nextbps == -1) {
    nextbps = old_nextbps;
    return(0);
  }

#endif

  if (!install_function_table ((ULONG64) nextbps, EXTRABPSSIZE)) {
    exit(-1);
  }
  if (!mprotect_exec ((char *)nextbps, EXTRABPSSIZE)) {
    perror("Couldn’t mprotect");
    nextbps = old_nextbps;
    return 0;
  }


  lastbps = nextbps + EXTRABPSSIZE;

  return(EXTRABPSSIZE);   /* This will be a paramter later */
}


getheap(heapsize)
long long heapsize;
{

#if (USE_WIN_HEAPFUNCTIONS == 1)

  long long lastheapaddress;
  long long heapsize_in_bytes;

  oldheaplowerbound     = -1;

  heapHandle = GetProcessHeap();

  if (heapHandle == NULL) {
    fprintf(stderr,"getheap: GetProcessHeap failed: %d\n",GetLastError());
    exit(-1);
  }

  heapsize_in_bytes =  NUMBEROFHEAPS * (SIZE_T) heapsize;

  heapBaseAddr = HeapAlloc(heapHandle,
                           (DWORD) 0,
	 		   heapsize_in_bytes);

  if (heapBaseAddr == NULL) {
     fprintf(stderr,"getheap: HeapAlloc failed\n");
    exit(-1);
  }

  heaplowerbound = (long long) heapBaseAddr;

  if (heaplowerbound + heapsize_in_bytes >= max_image_size) {

    heapsize_in_bytes = max_image_size - heaplowerbound;

    printf("Heap limits %llx %llx\n", heaplowerbound, heaplowerbound + heapsize_in_bytes);
    printf("Size requested will result in pointer values larger than\n");
    printf(" PSL items can handle. Will allocate maximum size instead.\n\n");

    heapBaseAddr = HeapReAlloc(heapHandle,
                               HEAP_REALLOC_IN_PLACE_ONLY,
			       heapBaseAddr,
			       heapsize_in_bytes);

    if (heapBaseAddr == NULL) {
      fprintf(stderr,"getheap: HeapReAlloc failed\n");
      exit(-1);
    }

    heaplowerbound = (long long) heapBaseAddr;

  }

#else

#if (NUMBEROFHEAPS == 1)
  heaplowerbound        = (long long)sbrk(heapsize);  /* allocate first heap */;
  oldheaplowerbound     = -1;
#else
  heaplowerbound        = (long long)sbrk(2 * heapsize);  /* allocate first heap */;
#endif
  if (heaplowerbound  == (long long) -1 || heaplowerbound == (long long) 0)  {
    perror("GETHEAP");
    exit(-1);
  }

#endif

  heapupperbound        = heaplowerbound + heapsize;
  heaplast              = heaplowerbound;
  heaptrapbound         = heapupperbound -120;

#if (NUMBEROFHEAPS == 2)
  oldheaplowerbound     = heapupperbound;
  oldheapupperbound     = oldheaplowerbound + heapsize;
  oldheaplast           = oldheaplowerbound;
  oldheaptrapbound      = oldheapupperbound -120;
#endif

#if (USE_WIN_HEAPFUNCTIONS == 1)
  oldbreakvalue = heaplowerbound + NUMBEROFHEAPS * heapsize;
#else
  oldbreakvalue = (long long)sbrk(0);
#endif
}

/* Tag( alterheapsize )
 */
alterheapsize(increment)
int increment;
{
/*
  alters the size of the heap by the specified increment.  Returns
  the increment if successful, otherwise returns 0.  May fail if
  the sbrk is unsuccessful or if the user tries to cut the heap back
  to nothing or the current break value does not match the old value.
  The latter case occurs when a malloc or sbrk has allocated space for
  some other software, in which case we cannot allocate any more space
  contiguously.

  Modifies both the heap and gcarray size.
  NOTE: a garbage collection should probably be performed before this
    routine is called.
  NOTE: only implemented for the one heap version on the 68000.
*/

  int heapsize;
  int current_size_in_bytes;

#if (USE_WIN_HEAPFUNCTIONS == 1)
#endif

#if (NUMBEROFHEAPS == 1)
  int gcarraysize, newbreakvalue;
 
  printf("***** cannot extend heap on this machine\n");
  return(0);

  if ((long long) sbrk(0) != oldbreakvalue)  /* Non contiguous memory */
      return(0);

  newbreakvalue = oldbreakvalue + increment;

  /* don't let the user cut his heap back to nothing, taking into account
     space for the gcarray. */
  if ((increment < 0) &&
      ((newbreakvalue - heaplowerbound) <
       (((heaplast + MINIMUMHEAPADD - heaplowerbound) * 9) / 8)))
    return(0);

  current_size_in_bytes = sbrk(0);

  if ((current_size_in_bytes +  increment) >= max_image_size)
    return(0);

  if ((long long)sbrk(increment) == -1)     /* the sbrk failed. */
     return(0);

  newbreakvalue = (long long) sbrk(0);
  heapsize = (((newbreakvalue - heaplowerbound) / 4) * 4);

  gcarraysize = (((heapsize / 9) / 4) * 4);
  heapsize = heapsize - gcarraysize;

  heapupperbound = heaplowerbound + heapsize;
  heaptrapbound     = heapupperbound;

  oldbreakvalue    = newbreakvalue;
  return(increment);
#else

#if (USE_WIN_HEAPFUNCTIONS == 1)

  long long newbreakvalue;
  SIZE_T heapSize;
  LPVOID newHeapBaseAddr;

  heapSize = HeapSize(heapHandle,(DWORD) 0,heapBaseAddr);
  if (heapSize == (SIZE_T)-1) {
    /* internal error */
    printf("***** HeapSize failed -- cannot extend heap\n");
    return(0);
  }

  newHeapBaseAddr = HeapReAlloc(heapHandle,
				HEAP_REALLOC_IN_PLACE_ONLY,
				heapBaseAddr,
				heapSize + 2 * increment);

  if (newHeapBaseAddr == NULL) {
    printf("***** HeapReAlloc failed -- cannot extend heap\n");
    return(0);
  }
  else if (newHeapBaseAddr != heapBaseAddr) {
    printf("***** Internal error: HeapReAlloc moved heap -- ABORT\n");
    exit(-2);
  }

  newbreakvalue = oldbreakvalue + increment;
					  
#else
  /* assumes the current heap is the 'lower' one */
  long long newbreakvalue;

  if ((long long) sbrk(0) != oldbreakvalue)  /* Non contiguous memory */
      {  printf(" unable to allocate %llx %llx\n",
		(long long)sbrk(0),oldbreakvalue);
        return(0); }

  current_size_in_bytes = ( (long long) sbrk(0) <<5) >>5;

  if ((current_size_in_bytes + 2* increment) >= max_image_size)
    return(-1);

  if ((long long)sbrk(2 * increment) == -1)       /* the sbrk failed. */
     return(-2);

  newbreakvalue = (long long) sbrk(0);

#endif

  heapupperbound        = heapupperbound + increment ;
  heaptrapbound         = heapupperbound - 120;
  oldheaplowerbound     = oldheaplowerbound + increment;
  oldheapupperbound     = oldheapupperbound + 2* increment ;
  oldheaplast           = oldheaplowerbound;
  oldheaptrapbound      = oldheapupperbound -120;


  oldbreakvalue = newbreakvalue;
  return(increment);
#endif

}

long long unexec()
{
  bpscontrol[0] = bpslowerbound;
  bpscontrol[1] = BPSSIZE;
  return((long long)bpscontrol);
}

char * get_imagefilepath ()
{
  return abs_imagefile;
}
