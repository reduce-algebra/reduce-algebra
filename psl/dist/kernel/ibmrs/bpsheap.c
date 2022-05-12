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
% Status:       Open Source: BSD License
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
%
%  $Id$
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
*/

#include <stdio.h>

/* Use 1 if using compacting collector ($pxnk/compact-gc.sl).
   Use 2 if using copying collector ($pnk/copying-gc.sl).
   Be sure to update $pxnk/load-psl.sl to include correct collector. */

#define MINSIZE        8000000  /* Default total in number of bytes. */
#define MALLOCSIZE     500000   /* Default size for OS support functions. */
#define EXTRABPSSIZE   100000   /* Minimum amount to increase bps by. */
#define MINIMUMHEAPADD 20000    /* Minimum amount to increase heap by */


#ifndef BPSSIZE
#define BPSSIZE          800000    /* Default bps size in number of bytes */
#endif

char *  imagefile ;
int     max_image_size;
int     oldbreakvalue;

extern int  alreadysetupbpsandheap;
extern int  hashtable;
extern char bps[];
extern int  lastbps;
extern int  nextbps;
extern int  bpslowerbound;

extern int  heaplowerbound;
extern int  heapupperbound;
extern int  heaplast;
extern int  heaptrapbound;

extern int  oldheaplowerbound;
extern int  oldheapupperbound;
extern int  oldheaplast;
extern int  oldheaptrapbound;

extern int  SYMVAL;

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

setupbpsandheap(argc,argv)
     int argc;
     char *argv[];
{ int ohl,ohtb,ohlb,ohub,hl,htb,hlb,hub;
  int memset = 0; int feder = 200000;
  FILE * imago;
  int headerword [8];
  int    i, total, bpssize, heapsize, mallocsize;
  int    current_size_in_bytes, heapsize_in_bytes;
  double bpspercent, heappercent;
  char   *argp, *scanptr, *scanformat;
  int ii1,ii2,ii3,ii4,ii5,ii6,ii7,ii8,ii9,ii10,ii11;

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
                        case 'x': scanformat = "%x";
                                  break;
                        case 'd': scanformat = "%d";
                                  break;
                      }
                      break;
           case 'f': imagefile = argv[i+1]; break;
           case 'g': scanptr = (char *)&feder;
                     scanformat = "%d"; break;
          }
          if (*scanformat != 0)
            sscanf(argv[i+1],scanformat,scanptr);
        }
    }   /* end of for loop -- arg vector searched */

  /* insure valid values */
  if (total == 0) total = MINSIZE;

  if (mallocsize <= 0) mallocsize = MALLOCSIZE;



  /* Reserve some space for C's usr of io buffers, etc. By mallocing then
     freeing, the memory is sbrk'ed onto the image, but available for future
     calls to malloc, which will not need to call sbrk again. */


  ii1=malloc(0x408);
  ii2=calloc(3,3);
  ii3=malloc(0x408);
  ii4=malloc(0x142c);
  ii5=malloc(0x1008);
  ii6=malloc(0x17);
  ii7=malloc(0x3);
  ii8=malloc(0x1068);
  ii9=malloc(0x28);
  ii10=malloc(0xc);
  ii11=malloc(0x384);

  external_user_homedir_string(); /* This is done by read-init-file */
  external_anyuser_homedir_string("hugo"); 

  bpssize = BPSSIZE;

  heapsize_in_bytes = total - bpssize;

  /* On systems in which the image does not start at address 0, this won't
     really allocate the full maximum, but close enough. */
  current_size_in_bytes = (((int) sbrk(0))<<4)>>4;
  max_image_size = power(2, 27); /* 1 more than allowable size */

  if ((heapsize_in_bytes + current_size_in_bytes) >= max_image_size) {
    heapsize_in_bytes = max_image_size - current_size_in_bytes;
    total = heapsize_in_bytes + bpssize;
    printf("Size requested will result in pointer values larger than\n");
    printf(" PSL items can handle. Will allocate maximum size instead.\n\n");
  }

  heapsize =(heapsize_in_bytes / 8) * 4;  /* insure full words */
  heappercent = ((float) (total - bpssize) / total) * 100.0;
  bpspercent  = ((float) bpssize / total) * 100.0;

  if (imagefile == NULL)
  { printf("Setting heap limit as follows:\n");
    printf("Total heap & bps space = %d (%X), bps = %.2f, heap = %.2f\n",
          total, total, bpspercent, heappercent);
  }

  setupbps();
  getheap(heapsize,feder);

  free (ii2); free(ii4); free (ii6); free(ii8);
  free (ii1); free (ii3); free (ii5); free(ii7);
  free (ii11); free (ii9); free (ii10);


  if (imagefile == NULL)
  printf("bpssize = %d (%X), heapsize = %d (%X)\nTotal image size = %d (%X)\n",
          bpssize, bpssize,
          heapsize, heapsize,
          (int) sbrk(0), (int) sbrk(0));


   if (imagefile != NULL) {
        ohl = oldheaplowerbound; ohub = oldheapupperbound;
        ohl = oldheaplast;    ohtb = oldheaptrapbound;
        hlb = heaplowerbound; hub = heapupperbound;
        hl  = heaplast;       htb = heaptrapbound;
    /* save the new values around restore of the old ones */

       printf("Loading image file: %s \n",imagefile);
       imago = fopen (imagefile,"r");
       if (imago == NULL) { perror ("error"); exit (-1); }
       fread (headerword,4,8,imago);

       if (strcmp(headerword,datetag()))
                { printf(" Cannot start the image with this bpsl \n");
                  exit (-19); } 

       fread (headerword,4,7,imago);
       fread (&SYMVAL,1,headerword[0],imago);
       /* printf (" heaplowerbound = %x (new) %x (file)\n" heaplowerbound,
                        headerword[6]); */
        if(headerword[6] > heaplowerbound + feder/2) {
                printf (" Cant relocate the image"); exit (-3); }
        if(headerword[6] < heaplowerbound - feder/2) {
                printf (" Cant relocate the image"); exit (-3); }
       feder = heaplowerbound - headerword[6];
       fread (headerword[6],1,headerword[1],imago);
       fread (&hashtable,1,headerword[2],imago);
       fread (bpslowerbound,1,headerword[3],imago);
       fread (headerword[4],1,headerword[5],imago);
       fclose (imago);
       vvm_cflush (bpslowerbound,BPSSIZE);
       if (memset) {
           oldheaplowerbound = ohl -feder; 
           oldheapupperbound = ohub -feder;
           oldheaplast  =  ohl -feder;   
           oldheaptrapbound = ohtb -feder;
           heapupperbound = hub -feder;
           heaptrapbound = htb -feder; }
       return (4711);
     }
return (0);

}


/* The current procedure is to convert the starting address of the char
   array defined in bps.c to an address and store it in nextbps. A check
   is made to make sure that nextbps falls on an even word boundry.
 */

setupbps()
{ bpslowerbound = ((int)bps + 3) & ~3;
  nextbps  = ((int)bps + 3) & ~3;        /* Up to a multiple of 4. */
  lastbps  = ((int)bps + BPSSIZE) & ~3;    /* Down to a multiple of 4. */
}


/* Allocate alternate bps space. Note: The use of sbrk(), and the fact that
   nextbps is now greater than heaplast means that unexec should be not be
   tried after this routine is called. The image would be huge.
 */
allocatemorebps()
{
  int current_size_in_bytes;
  int old_nextbps = nextbps;

  current_size_in_bytes = sbrk(0);

  if ((current_size_in_bytes + EXTRABPSSIZE) >= max_image_size)
    return(0);

  if (((int)sbrk(0)) % 2)      /* force to even word boundary*/
     nextbps = (int)sbrk(1);

  nextbps = (int)sbrk(EXTRABPSSIZE);   /* allocate extra BPS */
  if (nextbps == -1) {
    nextbps = old_nextbps;
    return(0);
  }
  lastbps = nextbps + EXTRABPSSIZE;
  return(EXTRABPSSIZE);   /* This will be a paramter later */
}


/* tag( getheap )
 */

getheap(heapsize,feder)
     int heapsize,feder;
{
  heaplowerbound        = (int)sbrk(2 * heapsize + feder );
                  /* allocate first heap */;
  
  if (heaplowerbound == -1) {
    perror("GETHEAP");
    exit(-1);
  }
     heaplowerbound += feder / 2;
     heaplowerbound  = heaplowerbound;
     heapupperbound  = heaplowerbound + heapsize;
     heaplast        = heaplowerbound;
     heaptrapbound   = heapupperbound -120;

     oldheaplowerbound = heapupperbound;
     oldheapupperbound = oldheaplowerbound + heapsize;
     oldheaplast       = oldheaplowerbound;
     oldheaptrapbound  = oldheapupperbound -120;

     oldbreakvalue = (int)sbrk(0);
}


/* Tag( alterheapsize )
 */

alterheapsize(increment)

int increment;

{
/*
  alters the size of the heap by the specified increment.  Returns
  the increment if successful, otherwise returns 0.  May fai i
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

  /* assumes the current heap is the 'lower' one */
  int newbreakvalue;

  if ((int) sbrk(0) != oldbreakvalue)  /* Non contiguous memory */
      {  printf(" unable to allocate %x %x\n",sbrk(0),oldbreakvalue);
        return(0); }

  current_size_in_bytes = ( (int) sbrk(0) <<4) >>4;

  if ((current_size_in_bytes + 2* increment) >= max_image_size)
    return(-1);

  if ((int)sbrk(2 * increment) == -1)       /* the sbrk failed. */
     return(-2);

  newbreakvalue = (int) sbrk(0);

  heapupperbound        = heapupperbound + increment ;
  heaptrapbound         = heapupperbound - 120;
  oldheaplowerbound     = oldheaplowerbound + increment;
  oldheapupperbound     = oldheapupperbound + 2* increment ;
  oldheaplast           = oldheaplowerbound;
  oldheaptrapbound      = oldheapupperbound -120;


  oldbreakvalue = newbreakvalue;
  return(increment);
}
unexec ()
  { return (BPSSIZE); }
