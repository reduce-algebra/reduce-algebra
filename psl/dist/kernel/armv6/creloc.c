/*
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PXK:CRELOC.C
% Description:  A simple modifier/relocation for PSL items after a Savesystem.
%               It is needed for the image model in newer Linuxes, after say 2008.
%               Heaplowerbound can be very far away then.
% Author:       Winfried Neun, ZIB
% Created:      
% Modified:     
% Mode:         Text
% Package:
% Status:       Open Source: BSD License
%
% (c) Copyright 1983, Hewlett-Packard Company, see the file
%            HP_disclaimer at the root of the PSL file tree
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
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
*/

#include <stdio.h>

extern int Debug;

void creloc (unsigned int array[], int len, int diff, unsigned int lowb, unsigned int uppb, int do_symval)

{  long i;
   long skip;
   long tag;
   long inf;

   for (i=0;i< len; i += skip)
       {  tag = (array[i] >> 27) ;
          if (tag < 0) { tag += 32;}
          inf = (array[i] << 5) >> 5;
          skip = 1;
          if ( tag == 0 ) continue;  // posint
          if ( tag > 26 ) continue; // negint to forward
#ifdef DEBUG
	  if (Debug > 1) {
	    printf("at %lx: %d before %d %lx",&array[i],tag,i,array[i]);
	  }
#endif
	  if ( tag < 23  && (inf > lowb) && (inf < uppb))
                  {array[i] += diff;}
          if (tag == 23 && inf < 1000000)
                  { skip = (inf +5) /4  +1 ;} //strpack
             else if (tag==25 && inf < 1000000) { skip = inf + 2;}
             else if (tag==26 && inf < 1000000) { skip = 1;} // work on the vect contents
// One has to make sure that bignums are *NOT* vectors in gc, but WORD-VECT.
#ifdef DEBUG
	  if (Debug > 1) {
	    printf(" %d after %lx\n",skip, array[i]);
	  }
#endif
	  if (do_symval != 0) {
	    // symval entries must be relocated word by word
	    skip =1 ;
	  }
       } 
}
