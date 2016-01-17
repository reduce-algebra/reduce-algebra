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
% (c) Copyright 1987, University of Utah, all rights reserved.
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
#include <stdlib.h>
#include <errno.h>
#include <limits.h>    /* for PAGESIZE */
       #ifndef PAGESIZE
       #define PAGESIZE 4096
       #endif


void * sbrk(int);


/* Use 1 if using compacting collector ($pxnk/compact-gc.sl).
   Use 2 if using copying collector ($pnk/copying-gc.sl).
   Be sure to update $pxnk/load-psl.sl to include correct collector. */

#define NUMBEROFHEAPS 2

#define MINSIZE        50000000 /* Default total in number of bytes. */
#define MALLOCSIZE     500000   /* Default size for OS support functions. */
#define EXTRABPSSIZE   300000   /* Minimum amount to increase bps by. */
#define MINIMUMHEAPADD 20000    /* Minimum amount to increase heap by */


#ifndef BPSSIZE
#define BPSSIZE         1600000    /* Default bps size in number of bytes */
#endif

extern int Debug;

char *  imagefile;
char *  abs_imagefile = NULL; /* like imagefile, but as an absolute path */
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
static int power(x, n)
     int x, n;
{
  int i, p;

  p = 1;
  for (i = 1; i <= n; ++i)
    p = p * x;
  return(p);
}


int creloc (long long array, long len, long long diff, long long lowb);

void setupbps();
void getheap(long long);
void read_error();

long sizeofsymvectors = 0;

int
setupbpsandheap(argc,argv)
     int argc;
     char *argv[];
{ long long ohl,ohtb,ohlb,ohub,hl,htb,hlb,hub,diff;
  int memset = 0;
  FILE * imago;
  long long headerword [8];
  long long i, total, bpssize, heapsize, mallocsize;
  long long current_size_in_bytes, heapsize_in_bytes;
  double bpspercent, heappercent;
  char   *argp, *scanptr, *scanformat;
  int ii1,ii2,ii3,ii4,ii5,ii6,ii7,ii8,ii9,ii10,ii11;
  long hugo;

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

  if (total < 1000000)  total = total * 1024*1024;

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
  current_size_in_bytes = (((long long) sbrk(0))<<5)>>5;
  max_image_size = 0x1000000000000; /* 1 more than allowable size */

  if ((heapsize_in_bytes + current_size_in_bytes) >= max_image_size) {
    heapsize_in_bytes = max_image_size - current_size_in_bytes;
    total = heapsize_in_bytes + bpssize;
printf("total %llX %llX %llx\n",heapsize_in_bytes , current_size_in_bytes,total);
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
  { printf("Setting heap limit as follows:\n");
    if (Debug > 0) {
      printf("Total heap & bps space = %lld (%llx), bps = %.2f, heap = %.2f\n",
             total, total, bpspercent, heappercent);
    }
  }

  setupbps();
  getheap(heapsize);

  if (imagefile == NULL)
  printf("bpssize = %llu (%llX), heapsize = %llu (%llX)\nTotal image size = %llu (%llX)\n",
          bpssize, bpssize,
          heapsize, heapsize,
          (unsigned long long) sbrk(0), (unsigned long long) sbrk(0));

   if (imagefile != NULL) {
	ohl = oldheaplowerbound; ohub = oldheapupperbound;
	ohl =  oldheaplast; ohtb = oldheaptrapbound;
        hlb = heaplowerbound; hub = heapupperbound;
        hl =  heaplast; htb = heaptrapbound;
    /* save the new values around restore of the old ones */

       printf("Loading image file: %s \n",imagefile); 
       imago = fopen (imagefile,"r");
       if (imago == NULL) { perror ("error"); exit (-1); }
       fread (headerword,8,2,imago);
       unexec();      /* set control vector */
      if ((long long) bpscontrol[0] != headerword[0] 
                || bpscontrol[1] != headerword[1])
		{ printf(" Cannot start the image with this bpsl \n");
                  printf(" %llx != %llx, %llx != %llx\n", bpscontrol[0], headerword [0], bpscontrol[1], headerword[1]);
		  exit (-19); }
       fread (headerword,8,4,imago);
       hugo = fread (&symval,1,headerword[0],imago);
       if (hugo != headerword[0]) read_error();

       sizeofsymvectors = headerword[0]/8;

       diff = hlb-heaplowerbound;

       if (diff != 0) {
	 if (Debug > 0) {
	   printf("relocate heap: %llx(img) => %llx(new)\n", heaplowerbound, hlb);
	 }
         creloc((long long)&symval, sizeofsymvectors, diff, heaplowerbound -1);
       }

       hugo = fread ((char*)hlb,1,headerword[1],imago);
       if (diff != 0)
	 creloc((long long)hlb,headerword[1]/8,diff, heaplowerbound -1);
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
       abs_imagefile = realpath(imagefile,NULL);
       return (4711);
     }
return (0);

}

void
read_error()
  {
    printf("file too short\n");
    exit(-1);
  }


/* The current procedure is to convert the starting address of the char
   array defined in bps.c to an address and store it in nextbps. A check
   is made to make sure that nextbps falls on an even word boundry.
 */

#include <sys/mman.h>

void
setupbps()
{ char *p = (char *) bps;
  int bpssize;
  char c;

  nextbps  =  ((long long) bps + 7) & ~7;        /* Up to a multiple of 8. */
  bpslowerbound = nextbps;
  lastbps  =  ((long long)bps + BPSSIZE) & ~7;    /* Down to a multiple of 8. */
  p = (char *)(( bpslowerbound  -1) & ~(PAGESIZE-1));
  bpssize =  ((BPSSIZE + PAGESIZE-1) & ~(PAGESIZE-1));
  if (mprotect(p, bpssize, PROT_READ | PROT_WRITE | PROT_EXEC)) {
            perror("Couldnt mprotect");
            exit(errno);
          } 
}


/* Allocate alternate bps space. Note: The use of sbrk(), and the fact that
   nextbps is now greater than heaplast means that unexec should be not be
   tried after this routine is called. The image would be huge.
 */
long long
allocatemorebps()
{
  int current_size_in_bytes;
  int old_nextbps = nextbps;

  current_size_in_bytes = (long long)sbrk(0);

  if ((current_size_in_bytes + EXTRABPSSIZE) >= max_image_size)
    return(0);

  if (((long long)sbrk(0)) % 2)      /* force to even word boundary*/
     nextbps = (long long)sbrk(1);

  nextbps = (int)sbrk(EXTRABPSSIZE);   /* allocate extra BPS */
  if (nextbps == -1) {
    nextbps = old_nextbps;
    return(0);
  }
  lastbps = nextbps + EXTRABPSSIZE;

  return(EXTRABPSSIZE);   /* This will be a paramter later */
}


void
getheap(heapsize)
     long long heapsize;
{
  heaplowerbound        = (long long )calloc(heapsize/512 +1,1024);  /* allocate first heap */;

  if ((int) heaplowerbound == 0) {
    perror("GETHEAP");
    exit(-1);
  }
  heapupperbound        = heaplowerbound + heapsize;
  heaplast              = heaplowerbound;
  heaptrapbound         = heapupperbound -320;

#if (NUMBEROFHEAPS == 2)
  oldheaplowerbound     = heapupperbound;
  oldheapupperbound     = oldheaplowerbound + heapsize;
  oldheaplast           = oldheaplowerbound;
  oldheaptrapbound      = oldheapupperbound -320;
#endif
  oldbreakvalue = (long long)sbrk(0);
}

/* Tag( alterheapsize )
 */
long long
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
  long long diff;

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

  if ((long long)sbrk(increment) != 0)     /* the sbrk failed. */
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
  /* assumes the current heap is the 'lower' one */
  int newbreakvalue;
  void * realo;

  if ((long long) sbrk(0) != oldbreakvalue)  /* Non contiguous memory */
      {  printf(" unable to allocate %llx %llx\n",(long long)sbrk(0),oldbreakvalue);
        return(0); }

  current_size_in_bytes = ( (long long) sbrk(0) <<5) >>5;

  if ((current_size_in_bytes + 2* increment) >= max_image_size)
    return(-1);

  if (Debug > 0) {
    fprintf(stderr,"Trying to increase heap size by %d bytes\n",increment);
  }

  realo = realloc((void *)heaplowerbound,
               oldheapupperbound - heaplowerbound + 2*increment);
  if (realo == (void *) NULL) {
    if (Debug > 0) {
      fprintf(stderr,"realloc returned NULL\n");
    }
    return (-2);
  }
  if (Debug > 0) {
    fprintf(stderr,"Old heaplowerbound = %lld (%llX), new = %lld (%llX)\n",heaplowerbound,heaplowerbound,(long long)realo,(long long)realo);
  }
  diff =  realo - (void *)heaplowerbound;
  if (realo < (void *)heaplowerbound)
             {creloc((long long) &symval,sizeofsymvectors,diff,(long long)realo -1);}
        else {creloc((long long) &symval,sizeofsymvectors,diff, heaplowerbound -1);}
   if (realo < (void *)heaplowerbound)
             {creloc((long long)realo,(heapupperbound - heaplowerbound)/8,diff,(long long)realo -1);}
        else {creloc((long long)realo,(heapupperbound - heaplowerbound)/8,diff,
              heaplowerbound -1);}


  newbreakvalue = (long long) sbrk(0);

  heaplowerbound        = (unsigned long long) realo;
  heaplast              = heaplast + diff ;
  heapupperbound        = heapupperbound  + diff + increment ;
  heaptrapbound         = heapupperbound - 120;
  oldheaplowerbound     = oldheaplowerbound + diff + increment;
  oldheapupperbound     = oldheapupperbound + diff + 2* increment ;
  oldheaplast           = oldheaplowerbound + diff ;
  oldheaptrapbound      = oldheapupperbound -120;


/*
 *   heapupperbound        = heapupperbound + increment ;
 *   heaptrapbound         = heapupperbound - 120;
 *   oldheaplowerbound     = oldheaplowerbound + increment;
 *   oldheapupperbound     = oldheapupperbound + 2* increment ;
 *   oldheaplast           = oldheaplowerbound;
 *   oldheaptrapbound      = oldheapupperbound -120;
 */

  oldbreakvalue = newbreakvalue;
  return(increment);
#endif

}

long long unexec()
{
  bpscontrol[0] = bpslowerbound;
  bpscontrol[1] = BPSSIZE;
  return((long long) bpscontrol);
}

char * get_imagefilepath ()
{
  return abs_imagefile;
}
