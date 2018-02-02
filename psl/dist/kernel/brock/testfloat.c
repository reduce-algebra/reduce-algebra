/*
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PXK:TESTFLOAT.C
% Description:  Miscellaneous floating point support routines.
% Author:       Leigh Stoller
% Created:      29-Oct-86 
% Modified:     
% Mode:         Text
% Package:      
% Status:       Open Source: BSD License
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
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Revisions:
%  
% 05-May-87 (Leigh Stoller)
%  Added C defintions for external float routines used in fast-math.sl.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <fenv.h>

int raus()

{ exit (0);}

fexcept_t flagp;

int main()
{ double aa; int i;
  aa = 10.0;
  for (i=1;i<500;i++){ aa = 10.0*aa;
  fegetexceptflag(&flagp, FE_OVERFLOW | FE_DIVBYZERO);
  if (flagp != 0) {printf("exit1 %d %x\n",i,flagp); break;}}
  printf("was soll das\n");
  aa = 10.0;
  feclearexcept(FE_OVERFLOW | FE_DIVBYZERO);
  for (i=1;i<500;i++){ aa = 10.0*aa;
  fegetexceptflag(&flagp, FE_OVERFLOW | FE_DIVBYZERO);
  if (flagp != 0) {printf("exit2 %d %x\n",i,flagp); break;}}
}
