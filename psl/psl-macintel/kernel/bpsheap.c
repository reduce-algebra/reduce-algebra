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

long unexec();

#include <stdio.h>

/* Use 1 if using compacting collector ($pxnk/compact-gc.sl).
   Use 2 if using copying collector ($pnk/copying-gc.sl).
   Be sure to update $pxnk/load-psl.sl to include correct collector. */

#define NUMBEROFHEAPS 1

#define MINSIZE        5000000  /* Default total in number of bytes. */
#define MALLOCSIZE     500000   /* Default size for OS support functions. */
#define EXTRABPSSIZE   300000   /* Minimum amount to increase bps by. */
#define MINIMUMHEAPADD 20000    /* Minimum amount to increase heap by */


#ifndef BPSSIZE
#define BPSSIZE         1600000    /* Default bps size in number of bytes */
#endif

char *  imagefile ;
int     max_image_size;
int     oldbreakvalue;

long bpscontrol[2];

extern int  alreadysetupbpsandheap;
extern int  hashtable;
extern char bps[];
extern int  symval;
extern int  lastbps;
extern int  nextbps;
extern int  bpslowerbound;
extern int  _infbitlength_;

extern int  heaplowerbound;
extern int  heapupperbound;
extern int  heaplast;
extern int  heaptrapbound;

extern int  oldheaplowerbound;
extern int  oldheapupperbound;
extern int  oldheaplast;
extern int  oldheaptrapbound;

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
  int memset = 0;
  FILE * imago;
  int headerword [8];
  int    i, total, bpssize, heapsize, mallocsize;
  int    current_size_in_bytes, heapsize_in_bytes;
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
                        case 'x': scanformat = "%x";
                                  break;
                        case 'd': scanformat = "%d";
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
  if (total == 0)
    total = MINSIZE;

  if (mallocsize <= 0)
    mallocsize = MALLOCSIZE;

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
  current_size_in_bytes = (((int) sbrk(0))<<5)>>5;
  max_image_size = power(2, _infbitlength_); /* 1 more than allowable size */

  if ((heapsize_in_bytes + current_size_in_bytes) >= max_image_size) {
    heapsize_in_bytes = max_image_size - current_size_in_bytes;
    total = heapsize_in_bytes + bpssize;
    printf("Size requested will result in pointer values larger than\n");
    printf(" PSL items can handle. Will allocate maximum size instead.\n\n");
  }

#if (NUMBEROFHEAPS == 2)
  heapsize =(heapsize_in_bytes / 4) * 2;  /* insure full words */
#else
  heapsize =(heapsize_in_bytes / 4) * 4;  /* insure full words */
#endif

  heappercent = ((float) (total - bpssize) / total) * 100.0;
  bpspercent  = ((float) bpssize / total) * 100.0;

  if (imagefile == NULL)
  { printf("Setting heap limit as follows:\n");
    printf("Total heap & bps space = %d (%X), bps = %.2f, heap = %.2f\n",
          total, total, bpspercent, heappercent);
  }

  setupbps();
  getheap(heapsize);

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
	ohl =  oldheaplast; ohtb = oldheaptrapbound;
        hlb = heaplowerbound; hub = heapupperbound;
        hl =  heaplast; htb = heaptrapbound;
    /* save the new values around restore of the old ones */

       printf("Loading image file :%s \n",imagefile); 
       imago = fopen (imagefile,"r");
       if (imago == NULL) { perror ("error"); exit (-1); }
       fread (headerword,4,2,imago);
       unexec();      /* set control vector */
      if ((int) bpscontrol[0] != headerword[0] 
                || bpscontrol[1] != headerword[1])
		{ printf(" Cannot start the image with this bpsl \n");
                  printf(" %x != %x, %x != %x\n", bpscontrol[0], headerword [0], bpscontrol[1], headerword[1]);
		  exit (-19); }
       fread (headerword,4,4,imago);
       hugo = fread (&symval,1,headerword[0],imago);
       if (hugo != headerword[0]) read_error();

       hugo = fread ((char*)heaplowerbound,1,headerword[1],imago);
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
setupbps()
{
  nextbps  =  ((int)bps + 3) & ~3;        /* Up to a multiple of 4. */
  bpslowerbound = nextbps;
  lastbps  =  ((int)bps + BPSSIZE) & ~3;    /* Down to a multiple of 4. */
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


getheap(heapsize)
     int heapsize;
{

//#if (NUMBEROFHEAPS == 1)
/*  heaplowerbound        = (int)sbrk(heapsize);  /* allocate first heap * /;
  oldheaplowerbound     = -1;
#else

  heaplowerbound        = (int)sbrk(2 * heapsize);  /* allocate first heap * /;
#endif
  if (heaplowerbound == -1) {
    perror("GETHEAP");
    exit(-1);
  } */
  heapsize = 110000000;
  heaplowerbound = &bps;
  heaplowerbound += BPSSIZE;
  heapupperbound        = heaplowerbound + heapsize;
  heaplast              = heaplowerbound;
  heaptrapbound         = heapupperbound -120;

#if (NUMBEROFHEAPS == 2)
  oldheaplowerbound     = heapupperbound;
  oldheapupperbound     = oldheaplowerbound + heapsize;
  oldheaplast           = oldheaplowerbound;
  oldheaptrapbound      = oldheapupperbound -120;
#endif
  oldbreakvalue = (int)sbrk(0);
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

#if (NUMBEROFHEAPS == 1)
  int gcarraysize, newbreakvalue;
 
  printf("***** cannot extend heap on this machine\n");
  return(0);

  if ((int) sbrk(0) != oldbreakvalue)  /* Non contiguous memory */
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

  if ((int)sbrk(increment) == -1)     /* the sbrk failed. */
     return(0);

  newbreakvalue = (int) sbrk(0);
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

  if ((int) sbrk(0) != oldbreakvalue)  /* Non contiguous memory */
      {  printf(" unable to allocate %x %x\n",sbrk(0),oldbreakvalue);
        return(0); }

  current_size_in_bytes = ( (int) sbrk(0) <<5) >>5;

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
#endif

}

long unexec()
{
  bpscontrol[0] = bpslowerbound;
  bpscontrol[1] = BPSSIZE;
  return((long) bpscontrol);
}

