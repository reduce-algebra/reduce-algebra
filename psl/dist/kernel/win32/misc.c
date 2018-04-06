/*
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PXK:MISC.C
% Description:  various UNIX functions which are needed as (long) external references
% Author:       Herbert Melenk (ZIB Berlin)
% Created:      17-Nov-89
% Modified:     
% Mode:         Text
% Package:
% Status:       Open Source: BSD License
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
*/

 
#define lldiv standardlldiv
#include <stdio.h>
#include <windows.h>
#undef lldiv
/*

long p_fopen(c,m)
	long m; char * c;
	{return ( (long) fopen(c,m)); }
 
long p_fgets(b,c,fp)
	long c,fp; char*b;
	{return ( (long) fgets(b,c,fp)); }
 
*/

long p_clearerr(fp)
	FILE* fp;
{clearerr(fp); return 0;}
 
long lmul(l1,l2)
	long l1,l2;
	{return (l1 * l2);}
 
long lldiv(l1,l2)
	long l1,l2;
        {l1 = (l1/l2); return (l1);}
 
long lrem(l1,l2)
	long l1,l2;
	{return (l1 % l2);}
 
 
 setlinebuf(stream)
 FILE* stream;
 { setvbuf(stream, (char *) NULL, _IOLBF, 80);}
// { setvbuf(stream, (char *) NULL, _IONBF, 0);}

 
profil(long freq,long time)
    { return(Beep(freq,time)); }

