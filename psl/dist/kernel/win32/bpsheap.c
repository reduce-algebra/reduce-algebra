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
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% (c) Copyright 1983, Hewlett-Packard Company, see the file
%            HP_disclaimer at the root of the PSL file tree
%
%
% (c) Copyright 1982, University of Utah
%
% Redistribution and use in source and binary forms, with or without
% modification, are permitted provided that the following conditions are met:
%
%    * Redistributions of source code must retain the relevant copyright
%      notice, this list of conditions and the following disclaimer.
%
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
% 
%
% Revisions:
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>

/* Use 1 if using compacting collector ($pxnk/compact-gc.sl).
   Use 2 if using copying collector ($pnk/copying-gc.sl).
   Be sure to update $pxnk/load-psl.sl to include correct collector. */

#define NUMBEROFHEAPS 1

#define MINSIZE        16000000  /* Default total in number of bytes. */
#define MALLOCSIZE     500000   /* Default size for OS support functions. */
#define EXTRABPSSIZE   300000   /* Minimum amount to increase bps by. */
#define MINIMUMHEAPADD 20000    /* Minimum amount to increase heap by */


#ifndef BPSSIZE
#define BPSSIZE         5600000    /* Default bps size in number of bytes */
#endif

extern int Debug;

char *  imagefile;
char *  abs_imagefile = NULL;	/* like imagefile, but as an absolute pathname */
int     max_image_size;
int     oldbreakvalue;

int     bpssize;

extern int  alreadysetupbpsandheap;
extern int  mainstartinitialize;
extern int  HASHTABLE;
extern char  bps[];
extern char * SYMNAM;
extern char * SYMGET;
extern int  symms []; 
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

extern int  stacklowerbound;


extern FILE * scriptin, * scriptout;
extern int win_mode;
extern int script_mode;

extern int sbrk(void *);
extern char * datetag();
extern void my_puts(char *);
extern unixputs(char *);
extern external_user_homedir_string();

char * envname = (char*)NULL;
char * external_getenv(char *);

void setupbps();
void getheap(int,int);
char * cygpath2winpath(char * cygpath);

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
{ int ohl,ohtb,ohlb,ohub,hl,htb,hlb,hub,slb;
  int memset = 0; int feder = 200000;
  FILE * imago;
  char * scriptinfile = NULL, * scriptoutfile = NULL;
  int headerword [8];
  int    i, total,  heapsize, mallocsize;
  int    current_size_in_bytes, heapsize_in_bytes;
  double bpspercent, heappercent;
  char   *argp, *scanptr, *scanformat;
  //  int ii1,ii2,ii3,ii4,ii5,ii6,ii7,ii8,ii9,ii10,ii11;
  char line [MAX_PATH+100];

  total        = MINSIZE;
  mallocsize    = MALLOCSIZE;

  for (i=1; i<argc; i++)
    {
      argp = argv[i];
      /* printf("par %d: %s\n",i,argp);  */
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
	   case 'f': if(i<argc) imagefile = argv[i+1]; break;
	   case 'i': if(i<argc) scriptinfile = argv[i+1]; break;
	   case 'o': if(i<argc) scriptoutfile = argv[i+1]; break;
	   case 'w': win_mode = 1; break;
	   case 'g': scanptr = (char *)&feder;
		     scanformat = "%d"; break;
	   case 'e': if(i <argc) envname = argv[i+1]; break;
	  }
	  if (*scanformat != 0)
	   { 
	    if(*argv[i+1] == '%')  /* unexpanded environemnt variable */
	    { char * c;
	      argv[i+1]++;
	      c = argv[i+1];
	      while(*c && *c!='%') c++; *c=0;
	      argv[i+1] = external_getenv(argv[i+1]);
	    }
	    if(argv[i+1]) sscanf(argv[i+1],scanformat,scanptr);
	   }

	}
    }   /* end of for loop -- arg vector searched */

  if(scriptinfile)
    { 
      scriptin = fopen(scriptinfile,"r");
      if(scriptinfile == NULL)
      { 
	sprintf(line,"cannot open input file >%s<\n",scriptinfile);
	unixputs(line);
	exit(-1);
      }
    }

  if(scriptoutfile)
    { 
      scriptout = fopen(scriptoutfile,"w");
      if(scriptoutfile == NULL)
      { 
	sprintf(line,"cannot open output file >%s<\n",scriptoutfile);
	unixputs(line);
	exit(-1);
      }
    }
  
  if (scriptin && scriptout) 
    {
      script_mode = 1;
      my_puts("script mode:\n");
      my_puts("------------\n");
      my_puts("input from file ");
      my_puts(scriptinfile);
      my_puts("\noutput to file ");
      my_puts(scriptoutfile);
      my_puts("\n");
    }

  /* insure valid values */
  if (total == 0)
    total = MINSIZE;

  if (mallocsize <= 0)
    mallocsize = MALLOCSIZE;

  /* Reserve some space for C's usr of io buffers, etc. By mallocing then
     freeing, the memory is sbrk'ed onto the image, but available for future
     calls to malloc, which will not need to call sbrk again. */

 
  external_user_homedir_string(); /* This is done by read-init-file */

  bpssize = BPSSIZE;
  heapsize = 119000000;

  for (i=0;i<bpssize;i++) bps[i]=15;    /* illegal opcode */

  heapsize_in_bytes = total - bpssize;

  /* On systems in which the image does not start at address 0, this won't
     really allocate the full maximum, but close enough. */
  current_size_in_bytes = (long) malloc(4);
  max_image_size = power(2, _infbitlength_); /* 1 more than allowable size */

/*  if ((heapsize_in_bytes + current_size_in_bytes) >= max_image_size) {
    heapsize_in_bytes = max_image_size - current_size_in_bytes;
    total = heapsize_in_bytes + bpssize;
    sprintf(line,"Size requested will result in pointer values larger than\n");
    unixputs(line);
    unixputs(" PSL items can handle. Will allocate maximum size instead.\n\n");
  }
*/
  heapsize =(heapsize_in_bytes / 4) * 4;  /* insure full words */

  heappercent = ((float) (total - bpssize) / total) * 100.0;
  bpspercent  = ((float) bpssize / total) * 100.0;

  if (imagefile == NULL)
  { unixputs("Setting heap limit as follows:\n");
    sprintf(line,"Total heap & bps space = %d (%X), bps = %.2f, heap = %.2f\n",
	  total, total, bpspercent, heappercent);
    unixputs(line);
  }

  setupbps();
  getheap(heapsize,feder);

  if (imagefile == NULL)
  {
   sprintf(line,"bpssize = %d (%X), heapsize = %d (%X)\n",
	  bpssize, bpssize,
	  heapsize, heapsize);
   unixputs(line);
  }

#ifdef WINPSL
   if(scriptout != NULL && scriptin != NULL)
      init2(1,0); /* second part of windows initialization */
	 else init2(0 , imagefile==NULL );
#endif


   if (imagefile != NULL) {
	ohl = oldheaplowerbound; ohub = oldheapupperbound;
	ohl =  oldheaplast; ohtb = oldheaptrapbound;
	hlb = heaplowerbound; hub = heapupperbound;
	hl =  heaplast; htb = heaptrapbound;
/*sprintf(line,"%x slb original \n",stacklowerbound);
 * unixputs(line);*/
        slb = stacklowerbound;

    /* save the new values around restore of the old ones */

     { 
       char tempname[MAX_PATH]; 
       char *s1; char*s2;
       s2 = tempname;
       if (envname)
       { 
	     s1 = (char*) getenv(envname);
	     if(!s1) {
		   printf("variable %s not set\n",envname);
		   exit (-1);
		 }
	     while(*s1) *s2++ = *s1++; 
	       *s2++  = '\\';
         }

         s1 = imagefile;
         while(*s1) *s2++ = *s1++;
         *s2 = 0;

         imago = fopen (cygpath2winpath(tempname),"rb");
         if (imago == NULL) { 
		   perror (tempname); 
		   exit (-1);
         }  

	     sprintf(line,"Loading image file :%s \n",tempname);
         unixputs(line);
	   }

       fread (headerword,4,8,imago);

       if (strcmp((char *)headerword,datetag()))
		{ sprintf(line," Cannot start the image with this bpsl \n");
		  unixputs(line);
		  exit (-19); }

      fread (headerword,4,7,imago);
       i = fread (SYMNAM,1,240000 /* headerword[0] */,imago);
       i = fread (SYMGET,1,240000 /* headerword[0] */,imago);
       i = fread (symms ,1,720000 /* headerword[0] */,imago); 
  
       if (heaplowerbound != headerword[6]) {
         if (Debug > 0) {
            printf (" heaplowerbound = %x (new) %x (file)\n", heaplowerbound,
	  		headerword[6]);
	 }
       }

	if(   
	       /* headerword[6] > heaplowerbound + feder/2 ||  */
	   
	   headerword[6] < heaplowerbound - feder/2) 
	{
		unixputs (" Cant relocate the image"); 
		sprintf (line," heaplowerbound = %x (new) %x (file)\n", 
			  heaplowerbound, headerword[6]); 
		unixputs(line);
		exit (-3); 
	}
       feder = heaplowerbound - headerword[6];
       { int l1,l2,l3,l4;
	     l1 = fread ((char*)headerword[6],1,headerword[1],imago);
	     l2 = fread ((char*)HASHTABLE,1,headerword[2],imago);
	     l3 = fread ((char*)bpslowerbound,1,headerword[3],imago);
	     l4 = fread ((char*)headerword[4],1,headerword[5],imago);
	     if(l1 != headerword[1] || l2 != headerword[2] ||
		l3 != headerword[3] || l4 != headerword[5])
	       {sprintf(line,"*** Image file damaged %x %x %x %x\n",l1,l2,l3,l4);
		unixputs(line);
		exit(3);
	       };
       }
       
       mainstartinitialize = 1;
       fclose (imago);
#ifdef WINPSL
       init3();
#endif
       if (memset) {
	oldheaplowerbound = ohl; oldheapupperbound = ohub;
	oldheaplast = ohl; oldheaptrapbound = ohtb;
	heaplowerbound = hlb; heapupperbound = hub;
	heaptrapbound = htb; }
       abs_imagefile = _fullpath(NULL, imagefile, _MAX_PATH);
       return (4711);
     }
return (0);

}
/* The current procedure is to convert the starting address of the char
   array defined in bps.c to an address and store it in nextbps. A check
   is made to make sure that nextbps falls on an even word boundry.
 */
void setupbps()
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
  return(-1);   /* This will be a paramter later */
}


/* tag( getheap )
 */
void getheap(int heapsize,int feder)
{
  int s=0,i; char * c;
  
 //  s = heapsize+feder;
 //   heaplowerbound        = (int)malloc(s); 
 //    we need a static heap allocation under Windows Vista
  
 heapsize = 110000000;
 heaplowerbound = (int) &bps;
 heaplowerbound += BPSSIZE;
 heapupperbound        = heaplowerbound + heapsize;
 heaplast              = heaplowerbound;
 heaptrapbound         = heapupperbound -120;

   if (heaplowerbound <= 0) 
  {
    unixputs("****** Memory not available ********");
    exit(-1);
  }

  for(i=0;i<s;i=i+2048)
  { 
      c = ((char *)(heaplowerbound + i));
      *c = '*';
  }
  
 
//  heapupperbound       += feder /2;
  heapupperbound        = heaplowerbound + heapsize;
  heaplast              = heaplowerbound;
  heaptrapbound         = heapupperbound -120;


  oldheaplowerbound     = 0;
  oldheapupperbound     = 0;
  oldheaplast           = 0;
  oldheaptrapbound      = 0;
  oldbreakvalue         = (int)sbrk(0); 
}

/* Tag( alterheapsize )
 */
alterheapsize(increment)
int increment;
{
  return(-1);

}

unexec()
{
  return(bpssize);
}

char * get_imagefilepath ()
{
  return abs_imagefile;
}
