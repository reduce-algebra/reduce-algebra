/*
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PXK:bpsheap.c
% Description:  Code to dynamically set up bps and heap structures
% Author:       RAM, HP/FSD
% Created:      9-Mar-84
% Modified:
% Status:       Open Source: BSD License
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
*/

/*
 * There used to be a collection of comments here describing revisions
 * made from about 1982 to 1989. I think those are by now of interest
 * to archaeologists! So anybody who wants to see them can consult older
 * copies of this file in the repositories. It is neverthless proper to
 * record the names of those who (in addition to the original author)
 * have contributed:
 *     Julian Padget, Harold Carr, Leigh Stoller
 */

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



long _(unexec)();

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>    // for PAGESIZE
#include <inttypes.h>  // Make newer integer types  of known width available
#include <unistd.h>

#ifndef PAGESIZE
#define PAGESIZE 4096
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
int64_t   max_image_size;
int64_t   oldbreakvalue;

long bpscontrol[2];

extern int64_t  alreadysetupbpsandheap;
extern int64_t  hashtable;
extern char bps[];
extern int64_t  symval;
extern int64_t  lastbps;
extern int64_t  nextbps;
extern int64_t  bpslowerbound;
extern int64_t  _infbitlength_;

extern int64_t  heaplowerbound;
extern int64_t  heapupperbound;
extern int64_t  heaplast;
extern int64_t  heaptrapbound;

extern int64_t  oldheaplowerbound;
extern int64_t  oldheapupperbound;
extern int64_t  oldheaplast;
extern int64_t  oldheaptrapbound;

/* Write this ourselves to keep from including half the math library */
static int power(int x, int n)
{   int i, p;

    p = 1;
    for (i = 1; i <= n; ++i)
        p = p * x;
    return (p);
}

int creloc(int64_t array, long len, int64_t diff, int64_t lowb);

long sizeofsymvectors = 0;

void setupbps();
void getheap(int64_t);
void read_error(char *,int64_t,int64_t);

int setupbpsandheap(int argc,char *argv[])
{   int64_t ohl,ohtb,ohlb,ohub,hl,htb,hlb,hub,diff;
    int memset = 0;
    FILE * imago;
    int64_t headerword [8];
    int64_t i, total, bpssize, heapsize, mallocsize;
    int64_t current_size_in_bytes, heapsize_in_bytes;
    double bpspercent, heappercent;
    char   *argp, *scanptr, *scanformat;
    int ii1,ii2,ii3,ii4,ii5,ii6,ii7,ii8,ii9,ii10,ii11;
    long hugo;

    total        = MINSIZE;
    mallocsize    = MALLOCSIZE;

    for (i=1; i<argc-1; i++)
    {   argp = argv[i];
        if (*argp++ == '-')
        {   scanformat = "";
            switch (*argp++)
            {   case 't': scanptr = (char *)&total;
                    memset = 1;
                    switch (*argp)
                    {   case 'x': scanformat = "%x";
                            break;
                        case 'd': scanformat = "%d";
                            break;
                    }
                    break;
                case 'm': scanptr = (char *)&mallocsize;
                    switch (*argp)
                    {   case 'x': scanformat = "%lx";
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
    current_size_in_bytes = (((int64_t) sbrk(0))<<5)>>5;
    max_image_size = INT64_C(0x1000000000000); /* 1 more than allowable size */

    if ((heapsize_in_bytes + current_size_in_bytes) >= max_image_size)
    {   heapsize_in_bytes = max_image_size - current_size_in_bytes;
        total = heapsize_in_bytes + bpssize;
        printf("total %" PRIx64 " %" PRIx64 " %" PRIx64 "\n",heapsize_in_bytes, current_size_in_bytes,total);
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
    {   printf("Setting heap limit as follows:\n");
        if (Debug > 0)
        {   printf("Total heap & bps space = %" PRId64 " (%" PRIx64 "), bps = %.2f, heap = %.2f\n",
                   total, total, bpspercent, heappercent);
        }
    }

    setupbps();
    if (imagefile != NULL) imago = fopen (imagefile,"r");
    /* before getheap */

    getheap(heapsize);

    if (imagefile == NULL)
        printf("bpssize = %" PRId64 " (%" PRIX64 "), heapsize = %" PRId64 " (%" PRIX64 ")\nTotal image size = %" PRId64 " (%" PRIX64 ")\n",
               bpssize, bpssize,
               heapsize, heapsize,
               (int64_t) sbrk(0), (int64_t) sbrk(0));

    if (imagefile != NULL)
    {   ohl = oldheaplowerbound; ohub = oldheapupperbound;
        ohl =  oldheaplast; ohtb = oldheaptrapbound;
        hlb = heaplowerbound; hub = heapupperbound;
        hl =  heaplast; htb = heaptrapbound;
        /* save the new values around restore of the old ones */

        printf("Loading image file: %s \n",imagefile);
        if (imago == NULL)
        {   perror ("error");
            exit (-1);
        }
        fread (headerword,8,2,imago);
        _(unexec)();      /* set control vector */
        if ((int) bpscontrol[0] != headerword[0]
            || bpscontrol[1] != headerword[1])
        {   printf(" Cannot start the image with this bpsl \n");
            printf(" %lx != %" PRIx64 ", %lx != %" PRIx64 "\n", bpscontrol[0], headerword [0], bpscontrol[1], headerword[1]);
            exit (-19);
        }
        fread (headerword,8,4,imago);
#ifdef DEBUG
        printf("symbol table: %ld (%lx) bytes\n",headerword[0],headerword[0]);
#endif
        hugo = fread (&symval,1,headerword[0],imago);
//       printf("neu: %lx => %lx\n",hlb, heaplowerbound);
        diff = hlb-heaplowerbound;
        if (hlb < heaplowerbound)
        {   creloc((int64_t) &symval,headerword[0]/8,diff,hlb -1);
        }
        else
        {   creloc((int64_t) &symval,headerword[0]/8,diff, heaplowerbound -1);
        }

        sizeofsymvectors = headerword[0]/8;

        if (hugo != headerword[0]) read_error("symbol table",hugo,headerword[0]);

#ifdef DEBUG
        printf("heap: %ld (%lx) bytes\n",headerword[1],headerword[1]);
#endif
        hugo = fread ((char*)hlb,1,headerword[1],imago);
        if (hlb < heaplowerbound)
        {   creloc(hlb,headerword[1]/8,diff,hlb -1);
        }
        else
        {   creloc(hlb,headerword[1]/8,diff, heaplowerbound -1);
        }
        heaplast += diff;

        if (hugo != headerword[1]) read_error("heap",hugo,headerword[1]);
#ifdef DEBUG
        printf("hash table: %ld (%lx) bytes\n",headerword[2],headerword[2]);
#endif
        hugo = fread (&hashtable,1,headerword[2],imago);
        if (hugo != headerword[2]) read_error("hash table",hugo,headerword[2]);
#ifdef DEBUG
        printf("BPS: %ld (%lx) bytes\n",headerword[3],headerword[3]);
#endif
        hugo = fread ((char*)bpslowerbound,1,headerword[3],imago);
        if (hugo != headerword[3]) read_error("BPS",hugo,headerword[3]);
        fclose (imago);
        if (memset)
        {   oldheaplowerbound = ohl; oldheapupperbound = ohub;
            oldheaplast = ohl; oldheaptrapbound = ohtb;
            heaplowerbound = hlb; heapupperbound = hub;
            heaptrapbound = htb;
        }
        abs_imagefile = realpath(imagefile,NULL);
        return (4711);
    }
    return (0);

}

void read_error(char * what,int64_t bytesread,int64_t byteswanted)
{   printf("File too short while reading %s: bytes read = %" PRId64 " (%" PRIx64 "), bytes expected = %" PRId64 " (%" PRIx64 ")\n",
           what,bytesread,bytesread,byteswanted,byteswanted);
    exit(-1);
}


/* The current procedure is to convert the starting address of the char
   array defined in bps.c to an address and store it in nextbps. A check
   is made to make sure that nextbps falls on an even word boundry.
 */

#include <sys/mman.h>

void setupbps()
{   char *p = (char *) bps;
    int bpssize;
    char c;

    nextbps  =  ((int64_t)bps + 7) & ~7;        /* Up to a multiple of 8. */
    bpslowerbound = nextbps;
    lastbps  =  ((int64_t)bps + BPSSIZE) & ~7;    /* Down to a multiple of 8. */
    p = (char *)(((int64_t) bpslowerbound  -1) & ~(PAGESIZE-1));
    bpssize =  ((BPSSIZE + PAGESIZE-1) & ~(PAGESIZE-1));
    if (mprotect(p, bpssize, PROT_READ | PROT_WRITE | PROT_EXEC))
    {   perror("Couldn't1 mprotect");
        exit(errno);
    }
}


/* Allocate alternate bps space. Note: The use of sbrk(), and the fact that
   nextbps is now greater than heaplast means that unexec should be not be
   tried after this routine is called. The image would be huge.
 */
int64_t _(allocatemorebps)()
{   int64_t current_size_in_bytes;
    long old_nextbps = nextbps;

    current_size_in_bytes = (int64_t)sbrk(0);

    if ((current_size_in_bytes + EXTRABPSSIZE) >= max_image_size)
        return(0);

    if (((int64_t)sbrk(0)) % 2)      /* force to even word boundary*/
        nextbps = (int64_t)sbrk(1);

    nextbps = (int64_t)sbrk(EXTRABPSSIZE);   /* allocate extra BPS */
    if (nextbps == -1)
    {   nextbps = old_nextbps;
        return(0);
    }
    lastbps = nextbps + EXTRABPSSIZE;

    return(EXTRABPSSIZE);   /* This will be a parameter later */
}

void getheap(int64_t heapsize)
{

#if (NUMBEROFHEAPS == 1)
    heaplowerbound        = (int64_t)sbrk(heapsize);  /* allocate first heap */;
    oldheaplowerbound     = -1;
#else

    heaplowerbound        = (int64_t )malloc(2 * heapsize);  /* allocate first heap */;
#endif
    if (heaplowerbound  == (int64_t) NULL )
    {   perror("GETHEAP");
        exit(-1);
    }
    heapupperbound        = heaplowerbound + heapsize;
    heaplast              = heaplowerbound;
    heaptrapbound         = heapupperbound -120;

#if (NUMBEROFHEAPS == 2)
    oldheaplowerbound     = heapupperbound;
    oldheapupperbound     = oldheaplowerbound + heapsize;
    oldheaplast           = oldheaplowerbound;
    oldheaptrapbound      = oldheapupperbound -120;
#endif
    oldbreakvalue = (int64_t )sbrk(0);
}

/* Tag( alterheapsize )
 */
int64_t _(alterheapsize)(int increment)
{   /*
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
    int64_t diff;

#if (NUMBEROFHEAPS == 1)
    int gcarraysize, newbreakvalue;

    printf("***** cannot extend heap on this machine\n");
    return(0);

    if ((int64_t) sbrk(0) != oldbreakvalue)  /* Non contiguous memory */
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

    if ((int64_t)sbrk(increment) == -1)     /* the sbrk failed. */
        return(0);

    newbreakvalue = (int64_t) sbrk(0);
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

    if ((int64_t) sbrk(0) != oldbreakvalue)  /* Non contiguous memory */
    {   printf(" unable to allocate %" PRIx64 " %" PRIx64 "\n",(int64_t)sbrk(0),oldbreakvalue);
        return(0);
    }

    current_size_in_bytes = ( (int64_t) sbrk(0) <<5) >>5;

    if ((current_size_in_bytes + 2* increment) >= max_image_size)
        return(-1);

    realo = realloc((void *)heaplowerbound,
                    oldheapupperbound - heaplowerbound + 2*increment);
    if (realo == (void *) NULL)
    {   if (Debug > 0)
        {   fprintf(stderr,"realloc returned NULL\n");
        }
        return (-2);
    }
    if (Debug > 0)
    {   fprintf(stderr,"Old heaplowerbound = %" PRId64 " (%" PRIX64 "), new = %" PRId64 " (%" PRIX64 ")\n",heaplowerbound,heaplowerbound,(int64_t)realo,(int64_t)realo);
    }
    diff =  realo - (void *)heaplowerbound;
    if (realo < (void *)heaplowerbound)
    {   creloc((int64_t) &symval,sizeofsymvectors,diff,(int64_t)realo -1);
    }
    else
    {   creloc((int64_t) &symval,sizeofsymvectors,diff, heaplowerbound -1);
    }
    if (realo < (void *)heaplowerbound)
    {   creloc((int64_t)realo,(heapupperbound - heaplowerbound)/8,diff,(int64_t)realo -1);
    }
    else
    {   creloc((int64_t)realo,(heapupperbound - heaplowerbound)/8,diff,
               heaplowerbound -1);
    }



    newbreakvalue = (int64_t) sbrk(0);

    heaplowerbound        = (uint64_t) realo;
    heaplast              = heaplast + diff ;
    heapupperbound        = heapupperbound  + diff + increment ;
    heaptrapbound         = heapupperbound - 120;
    oldheaplowerbound     = oldheaplowerbound + diff + increment;
    oldheapupperbound     = oldheapupperbound + diff + 2* increment ;
    oldheaplast           = oldheaplowerbound + diff ;
    oldheaptrapbound      = oldheapupperbound -120;


    /*
      heapupperbound        = heapupperbound + increment ;
      heaptrapbound         = heapupperbound - 120;
      oldheaplowerbound     = oldheaplowerbound + increment;
      oldheapupperbound     = oldheapupperbound + 2* increment ;
      oldheaplast           = oldheaplowerbound;
      oldheaptrapbound      = oldheapupperbound -120;
    */


    oldbreakvalue = newbreakvalue;
    return(increment);
#endif

}

long _(unexec)()
{   bpscontrol[0] = bpslowerbound;
    bpscontrol[1] = BPSSIZE;
    return((long) bpscontrol);
}

char *_(get_imagefilepath)()
{   return abs_imagefile;
}

/* end of bpsheap.c */
