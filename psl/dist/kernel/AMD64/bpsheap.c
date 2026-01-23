/*
 * File:         PXK:bpsheap.c
 * Description:  Code to dynamically set up bps and heap structures
 * Author:       RAM, HP/FSD
 * Created:      9-Mar-84
 * Modified:
 * Status:       Open Source: BSD License
 * Mode:         Text
 * Package:
 *
 * (c) Copyright 1982, University of Utah
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *    * Redistributions of source code must retain the relevant copyright
 *      notice, this list of conditions and the following disclaimer.
 *    * Redistributions in binary form must reproduce the above copyright
 *      notice, this list of conditions and the following disclaimer in the
 *      documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNERS OR
 * CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ******************************************************************************
 *
 * Revisions:
 *
 * 11-Aug-88 (Julian Padget)
 *  Added initialization of bpslowerbound in setupbps().
 * 07-Apr-87 (Harold Carr & Leigh Stoller)
 *  Put in error checking to ensure that the memory pointers will fit in
 *   info field of the lisp item.
 * 21-Dec-86 (Leigh Stoller)
 *  Added allocatemorebps function, called from try-other-bps-spaces in
 *   allocators.sl.
 * 18-Dec-86 (Leigh Stoller)
 *  Changed to newer model. Bps is now defined in bps.c so that unexec can
 *  alter the text/data boundry. Took out code that allowed command line
 *  modification of bpssize. (Now set in the Makefile). Added setupbps()
 *  that initialzes nextbps and lastbps.
 * 20-Sep-86 (Leigh Stoller)
 *  Removed assembler alias statements because they are not portable. Instead,
 *  a sed script will be used to convert the _variables of C to VARIABLES of
 *  PSL.
 *
 *****************************************************************************
 *
 *  $Id$
 *
 *****************************************************************************
 */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>    // for PAGESIZE
#include <inttypes.h>  // Make newer integer types of known width available
#include <unistd.h>
#include <sys/mman.h>

#ifndef MY_PAGESIZE
#define MY_PAGESIZE 4096
#endif


/* Use 1 if using compacting collector ($pxnk/compact-gc.sl).
   Use 2 if using copying collector ($pnk/copying-gc.sl).
   Be sure to update $pxnk/load-psl.sl to include correct collector. */

#define NUMBEROFHEAPS 2

#define MINSIZE        1000 * 1024 * 1024  /* Default total in number of bytes. */
#define MALLOCSIZE     500000              /* Default size for OS support functions. */
#define EXTRABPSSIZE   300000              /* Minimum amount to increase bps by. */
#define MINIMUMHEAPADD 20000               /* Minimum amount to increase heap by */


#ifndef BPSSIZE
#define BPSSIZE         1600000    /* Default bps size in number of bytes */
#endif

extern int Debug;

char *  imagefile;
char *  abs_imagefile = NULL; /* like imagefile, but as an absolute path */
long long   max_image_size;
long pagesize = -1;

long long bpscontrol[2];

extern long long  alreadysetupbpsandheap;
extern long long  hashtable;
extern char bps[];
extern long long  symval;
extern long long  symprp;
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


void creloc (long long array, long len, long long diff, long long lowb);

long sizeofsymvectors = 0;

void setupbps(void);
void getheap(long long);
void read_error(char *,long long,long long);
void * unexec(void);


int
setupbpsandheap(int argc,char *argv[])
{
  long long ohl,ohtb,ohlb,ohub,hl,htb,hlb,hub,diff;
  int memset = 0;
  FILE * imago;
  long long headerword [8];
  long long i, total, bpssize, heapsize, mallocsize;
  long long heapsize_in_bytes;
  double bpspercent, heappercent;
  char   *argp, *scanptr, *scanformat;
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

  /* protect against invalid values */
  if (total < 1000000)  total = total * 1000000;

  if (total < MINSIZE)
    total = MINSIZE;

  if (mallocsize <= 0)
    mallocsize = MALLOCSIZE;

  bpssize = BPSSIZE;

  heapsize_in_bytes = total - bpssize;

  /* On systems in which the image does not start at address 0, this won't
     really allocate the full maximum, but close enough. */
  max_image_size = 0x1000000000000; /* 1 more than allowable size */

#if (NUMBEROFHEAPS == 2)
  heapsize = (heapsize_in_bytes / 8) * 4;  /* ensure full words */
#else
  heapsize = (heapsize_in_bytes / 8) * 8;  /* ensure full words */
#endif

  heappercent = ((float) (total - bpssize) / total) * 100.0;
  bpspercent  = ((float) bpssize / total) * 100.0;

  if (imagefile == NULL)
    {
      if (Debug > 0)
	{
	  printf("Setting heap limit as follows:\n");
	  printf("Total heap & bps space = %lld (%llx), bps = %.2f, heap = %.2f\n",
		 total, total, bpspercent, heappercent);
	}
    }

  setupbps();

  if (imagefile != NULL) imago = fopen (imagefile,"r");
  /* before getheap */

  getheap(heapsize);

  if (imagefile == NULL)
    {
      printf("symbol table size = %llu (%llX), symbol table address = %llu (%llX)\n"
	     "bpssize = %llu (%llX), bps address = %llu (%llX)\n"
	     "heapsize = %llu (%llX), heap address = %llu (%llX)\n"
	     "Page size = %ld (%lX)\n",
	     (unsigned long long) 5*(&symprp - &symval), (unsigned long long) 5*(&symprp - &symval),
	     (unsigned long long) &symval, (unsigned long long) &symval,
	     bpssize, bpssize,
	     bpslowerbound, bpslowerbound,
	     heapsize, heapsize,
	     heaplowerbound, heaplowerbound,
	     pagesize,pagesize);
    }

  if (imagefile != NULL)
    {
      ohlb = oldheaplowerbound; ohub = oldheapupperbound;
      ohl =  oldheaplast; ohtb = oldheaptrapbound;
      hlb = heaplowerbound; hub = heapupperbound;
      hl =  heaplast; htb = heaptrapbound;
      /* save the new values around restore of the old ones */

      if (Debug > 0)
	{
	  printf("symbol table size = %llu (%llX), symbol table address = %llu (%llx)\n"
		 "bpssize = %llu (%llX), bps address =  %llu (%llX)\n"
		 "heapsize = %llu (%llX), heap address = %llu (%llX), heaplast = %llu (%llX)\n",
		 (unsigned long long) 5*(&symprp - &symval), (unsigned long long) 5*(&symprp - &symval),
		 (unsigned long long) &symval, (unsigned long long) &symval,
		 bpssize, bpssize,
		 bpslowerbound, bpslowerbound,
		 heapsize, heapsize,
		 heaplowerbound, heaplowerbound,
		 hl, hl);
	}

      printf("Loading image file: %s \n",imagefile); 
      if (imago == NULL)
	{
	  perror ("Error loading image file");
	  exit (-1);
	}
      fread (headerword,8,2,imago);
      unexec();      /* set control vector */
      if (bpscontrol[0] != headerword[0] || bpscontrol[1] != headerword[1])
	{
	  printf(" Cannot start the image with this bpsl \n");
	  printf(" %llx != %llx, %llx != %llx\n", bpscontrol[0], headerword [0], bpscontrol[1], headerword[1]);
	  exit (-19);
	}
      fread (headerword,8,4,imago);

      if (Debug > 0)
	{
	  printf("symbol table: %llu (%llX) bytes\n",headerword[0],headerword[0]);
	  printf("heap: %llu (%llx) bytes\n",headerword[1],headerword[1]);
	  printf("hash table: %llu (%llX) bytes\n",headerword[2],headerword[2]);
	  printf("BPS: %llu (%llX) bytes\n",headerword[3],headerword[3]);
	}

      hugo = fread (&symval,1,headerword[0],imago);
      if (hugo != headerword[0]) read_error("symbol table",hugo,headerword[0]);

      diff = hlb-heaplowerbound;

      if (Debug > 0)
	{
	  printf("Relocate heap: %lld (%llx) => %lld (%llx): shift by %lld\n", heaplowerbound, heaplowerbound, hlb, hlb, diff);
	}

      if (hlb < heaplowerbound)
	{
	  creloc((unsigned long long) &symval,headerword[0]/8,diff,hlb -1);
	} 
      else
	{
	  creloc((unsigned long long) &symval,headerword[0]/8,diff, heaplowerbound -1);
	}

      sizeofsymvectors = headerword[0]/8;

      hugo = fread ((char*)hlb,1,headerword[1],imago);
      if (hugo != headerword[1]) read_error("heap",hugo,headerword[1]);

      if (hlb < heaplowerbound)
	{
	  creloc(hlb,headerword[1]/8,diff,hlb -1);
	}
      else
	{
	  creloc(hlb,headerword[1]/8,diff, heaplowerbound -1);
	}
      heaplast += diff;

      hugo = fread (&hashtable,1,headerword[2],imago);
      if (hugo != headerword[2]) read_error("hash table",hugo,headerword[2]);
      hugo = fread ((char*)bpslowerbound,1,headerword[3],imago);
      if (hugo != headerword[3]) read_error("BPS",hugo,headerword[3]);
      fclose (imago);
      if (memset)
	{
	  oldheaplowerbound = ohlb; oldheapupperbound = ohub;
	  oldheaplast = ohl; oldheaptrapbound = ohtb;
	  heaplowerbound = hlb; heapupperbound = hub;
	  heaptrapbound = htb;
	}
      abs_imagefile = realpath(imagefile,NULL);
      return (4711);
    }
  return (0);

}

void
read_error(char * what,long long bytesread,long long byteswanted)
{
  printf("File too short while reading %s: bytes read = %lld (%llx), bytes expected = %lld (%llx)\n",
	 what,bytesread,bytesread,byteswanted,byteswanted);
  exit(-1);
}


/* The current procedure is to convert the starting address of the char
   array defined in bps.c to an address and store it in nextbps. A check
   is made to make sure that nextbps falls on an even word boundry.
 */

void
setupbps()
{
  char *p = (char *) bps;
  int bpssize;

  pagesize = sysconf(_SC_PAGESIZE);
  if (pagesize == -1) {
    pagesize = MY_PAGESIZE;
  }

  nextbps  =  ((long long)bps + 7) & ~7;        /* Up to a multiple of 8. */
  bpslowerbound = nextbps;
  lastbps  =  ((long long)bps + BPSSIZE) & ~7;    /* Down to a multiple of 8. */
  p = (char *)(((long long) bpslowerbound - 1) & ~(pagesize-1));
  bpssize =  ((BPSSIZE + pagesize-1) & ~(pagesize-1));
  if (mprotect(p, bpssize, PROT_READ | PROT_WRITE | PROT_EXEC))
    {
      perror("Couldn’t mprotect");
      exit(errno);
    }
}


/* Allocate alternate bps space.
 */
long long
allocatemorebps()
{
  unsigned long long old_nextbps = nextbps;

  nextbps = (unsigned long long) malloc(EXTRABPSSIZE + 2);

  if ((void *) nextbps == NULL)
    {
      nextbps = old_nextbps;
      return 0;
    }

  if ((nextbps + EXTRABPSSIZE)  >= max_image_size)
    {
      /* Cannot use this address */
      free((void *) nextbps);
      nextbps = old_nextbps;
      return 0;
    }

  /* force to even word boundary*/
  if (nextbps % 2 == 1)
    {
      nextbps++;
    }

  if (mprotect((void *)nextbps, EXTRABPSSIZE, PROT_READ | PROT_WRITE | PROT_EXEC))
    {
      perror("Couldn’t mprotect");
      free((void *)nextbps);
      nextbps = old_nextbps;
      return 0;
    }

  lastbps = nextbps + EXTRABPSSIZE;

  return(EXTRABPSSIZE);   /* This will be a parameter later */
}

void
getheap(long long heapsize)
{
  long long heapsize_in_bytes;
  void *heapBaseAddr;

  oldheaplowerbound     = -1;

  heapsize_in_bytes =  NUMBEROFHEAPS * (size_t) heapsize;

  heapBaseAddr = malloc(heapsize_in_bytes);

  if (heapBaseAddr == NULL)
    {
      fprintf(stderr,"getheap: malloc of heap failed\n");
      exit(-1);
    }

  heaplowerbound = (long long) heapBaseAddr;

  if (heaplowerbound + heapsize_in_bytes >= max_image_size)
    {

      heapsize_in_bytes = max_image_size - heaplowerbound;

      printf("Heap limits %llx %llx\n", heaplowerbound, heaplowerbound + heapsize_in_bytes);
      printf("Size requested will result in pointer values larger than\n");
      printf(" PSL items can handle (%llx). Will allocate maximum size instead.\n\n",max_image_size);

      heapBaseAddr = realloc(heapBaseAddr, heapsize_in_bytes);

      if (heapBaseAddr == NULL)
	{
	  fprintf(stderr,"getheap: realloc of heap failed\n");
	  exit(-1);
	}

      heaplowerbound = (long long) heapBaseAddr;
    }

  heapupperbound        = heaplowerbound + heapsize;
  heaplast              = heaplowerbound;
  heaptrapbound         = heapupperbound - 120;

#if (NUMBEROFHEAPS == 2)
  oldheaplowerbound     = heapupperbound;
  oldheapupperbound     = oldheaplowerbound + heapsize;
  oldheaplast           = oldheaplowerbound;
  oldheaptrapbound      = oldheapupperbound - 120;

#endif

}

/* Tag( alterheapsize )
 */
long long
alterheapsize(int increment)
{
/*
  alters the size of the heap by the specified increment.  Returns
  the increment if successful, otherwise returns 0.  May fail if
  the realloc is unsuccessful or if the user tries to cut the heap back.

  Modifies both the heap and gcarray size.
  NOTE: a garbage collection should probably be performed before this
    routine is called.
*/

  long long diff;

#if (NUMBEROFHEAPS == 1)

  int heapsize;
  int gcarraysize, newbreakvalue;
 
  printf("***** Cannot extend heap on this machine\n");
  return(0);

#else

  /* assumes the current heap is the 'lower' one */
  void * realo;

  if (increment < 0)
    {
      return(0);
    }
  
  if ((oldheapupperbound + 2*increment) >= max_image_size)
    {
      return(-1);
    }

  if (Debug > 0)
    {
      fprintf(stderr,"Trying to increase heap size by %d bytes\n",increment);
    }

  realo = realloc((void *)heaplowerbound,
		  oldheapupperbound - heaplowerbound + 2*increment);
  if (realo == (void *) NULL)
    {
      if (Debug > 0)
	{
	  perror("realloc returned NULL\n");
	}
      return (-2);
    }
  if (Debug > 0)
    {
      fprintf(stderr,"Old heaplowerbound = %lld (%llX), new = %lld (%llX)\n",
	      heaplowerbound,heaplowerbound,(long long)realo,(long long)realo);
    }

  diff =  realo - (void *)heaplowerbound;
  if (realo < (void *)heaplowerbound)
    {
      creloc((long long)realo,(heapupperbound - heaplowerbound)/8,diff,(long long)realo -1);
      creloc((long long) &symval,sizeofsymvectors,diff,(long long)realo -1);
    }
  else if (realo > (void *)heaplowerbound)
    {
      creloc((long long)realo,(heapupperbound - heaplowerbound)/8,diff,heaplowerbound -1);
      creloc((long long) &symval,sizeofsymvectors,diff, heaplowerbound -1);
    }

  heaplowerbound        = (unsigned long long) realo;
  heaplast              = heaplast + diff;
  heapupperbound        = heapupperbound + diff + increment;
  heaptrapbound         = heapupperbound - 120;
  oldheaplowerbound     = oldheaplowerbound + diff + increment;
  oldheapupperbound     = oldheapupperbound + diff + 2*increment;
  oldheaplast           = oldheaplowerbound + diff;
  oldheaptrapbound      = oldheapupperbound - 120;

  return(increment);

#endif

}

void *
unexec()
{
  bpscontrol[0] = bpslowerbound;
  bpscontrol[1] = BPSSIZE;
  return (bpscontrol);
}

char * get_imagefilepath ()
{
  return abs_imagefile;
}
