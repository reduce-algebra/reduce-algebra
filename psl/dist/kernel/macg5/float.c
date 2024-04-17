/*
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PB:FLOAT.C
% Description:  Miscellaneous floating point support routines.
% Author:       Leigh Stoller
% Created:      29-Oct-86 
% Modified:     
% Mode:         Text
% Package:      
% Status:       Open Source: BSD License
%
% (c) Copyright 1986, University of Utah, all rights reserved.
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
%
%  $Id$
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
*/

/*#include <strings.h>
*/
//#include <fptrap.h>
//#include <fpxcp.h>
#include <math.h>
#define index strchr
#define rindex strrchr

double hugolein,kunochen;

/* Tag( uxfloat )
 */
uxfloat(f,i)
     double *f;
     int i;
{
  copyfloat(&hugolein,f);
  hugolein = i;
 // if (fp_any_xcp()) fp_analyse_xcp();
  copyfloat(f,&hugolein);
}

/* Tag( uxfix )
 */
int uxfix(f)
     double *f;
{
  copyfloat(&hugolein,f);
 // if (fp_any_xcp()) fp_analyse_xcp();
  return hugolein;
}

/* Tag( uxassign )
 */
uxassign(f1,f2)
     double *f1, *f2;
{
  copyfloat(f1,f2);
}

/* Tag( uxplus2 )
 */
uxplus2(f1,f2,f3)
     double *f1, *f2, *f3;
{
 copyfloat(&hugolein,f3);
 copyfloat(&kunochen,f2);
 /* *f1 = *f2 + *f3;
 */
 hugolein = kunochen + hugolein;
// if (fp_any_xcp()) fp_analyse_xcp();
 copyfloat(f1,&hugolein);
 
}

/* Tag( uxdifference )
 */
uxdifference(f1,f2,f3)
     double *f1, *f2, *f3;
{
 copyfloat(&hugolein,f3);
 copyfloat(&kunochen,f2);
  /* *f1 = *f2 - *f3;
  */
 hugolein = kunochen - hugolein;
 copyfloat(f1,&hugolein);
}

/* Tag( uxtimes2 )
 */
uxtimes2(f1,f2,f3)
     double *f1, *f2, *f3;
{
 copyfloat(&hugolein,f3);
 copyfloat(&kunochen,f2);
 /* *f1 = *f2 * *f3;
 */
 hugolein = kunochen * hugolein;
 copyfloat(f1,&hugolein);
}

/* Tag( uxquotient )
 */
uxquotient(f1,f2,f3)
     double *f1, *f2, *f3;
{
 copyfloat(&hugolein,f3);
 copyfloat(&kunochen,f2);
 /* *f1 = *f2 / *f3;
 */
 hugolein = kunochen / hugolein;
 copyfloat(f1,&hugolein);
}

/* Tag( uxgreaterp )
 */
int uxgreaterp(f1,f2,val1,val2)
     double *f1, *f2;
     int val1, val2;
{
 copyfloat(&hugolein,f1);
 copyfloat(&kunochen,f2);
  if (hugolein > kunochen)
    return val1;
  else
    return val2;
}

/* Tag( uxlessp )
 */
int uxlessp(f1,f2,val1,val2)
     double *f1, *f2;
     int val1, val2;
{
 copyfloat(&hugolein,f1);
 copyfloat(&kunochen,f2);
  if (hugolein < kunochen)
    return val1;
  else
    return val2;
}

/* Tag( uxwritefloat )
 */
uxwritefloat(buf, flt, convstr)
     char *buf;          /* String buffer to return float int */
     double *flt;        /* Pointer to the float */
     char *convstr;      /* String containing conversion field for sprintf */
{
  char *temps, *dot, *e;
  char tempbuf[100]; /* reasonable size limit */

  temps = buf + 8;       /* Skip over lisp string length to write data */

  copyfloat(&hugolein,flt);
  sprintf(temps, convstr, hugolein);

  /* Make sure that there is a trailing .0
   */
  dot = rindex(temps, '.');
  if (dot == '\0')
    /* Check to see if the number is in scientific notation. If so, we need
     *  add the .0 into the middle of the string, just before the e.
     */
    if ((e = rindex(temps, 'e')) || (e = rindex(temps, 'E')))
      {
	strcpy(tempbuf, e);       /* save save exponent part */
	*e = '\0'; 
	strcat(temps, ".0");     /* Add .0 ono original string */
	strcat(temps, tempbuf);  /* add the exponent part onto the end */
      }
  else
    {
      strcat(temps, ".0");
    }
  
  /* Install the length of the string into the Lisp header word
   */
  *((int *)(buf +4) ) = strlen(temps) - 1;
}

/* Tag( uxdoubletofloat )
 */
uxdoubletofloat (dbl,flt)
     double *dbl;
     float  *flt;
{
  copyfloat(&hugolein,dbl);
  *flt = (float) hugolein;
}

uxfloattodouble (flt,dbl)
     float  *flt;
     double *dbl;
{
  hugolein = (double) *flt;
  copyfloat(dbl,&hugolein);
}

/* Functions for fast-math.sl (Unix C replacement for mathlib.) */
uxsin (r, x)
     double *r, *x;
{
    copyfloat(&hugolein,x);
    kunochen = sin(hugolein);
    copyfloat(r,&kunochen);
    /* *r = sin( *x ); */
}

uxcos (r, x)
     double *r, *x;
{
    copyfloat(&hugolein,x);
    kunochen = cos(hugolein);
    copyfloat(r,&kunochen);
    /* *r = cos( *x ); */
}

uxtan (r, x)
     double *r, *x;
{
    copyfloat(&hugolein,x);
    kunochen = tan(hugolein);
    copyfloat(r,&kunochen);
    /* *r = tan( *x ); */
}

uxasin (r, x)
     double *r, *x;
{
    copyfloat(&hugolein,x);
    kunochen = asin(hugolein);
    copyfloat(r,&kunochen);
    /* *r = asin( *x ); */
}

uxacos (r, x)
     double *r, *x;
{
    copyfloat(&hugolein,x);
    kunochen = acos(hugolein);
    copyfloat(r,&kunochen);
    /* *r = acos( *x ); */
}

uxatan (r, x)
     double *r, *x;
{
    copyfloat(&hugolein,x);
    kunochen = atan(hugolein);
    copyfloat(r,&kunochen);
    /* *r = atan( *x ); */
}

uxsqrt (r, x)
     double *r, *x;
{
    copyfloat(&hugolein,x);
    kunochen = sqrt(hugolein);
    copyfloat(r,&kunochen);
    /* *r = sqrt( *x ); */
}

uxexp (r, x)
     double *r, *x;
{
    copyfloat(&hugolein,x);
    kunochen = exp(hugolein);
    copyfloat(r,&kunochen);
    /* *r = exp( *x ); */
}

uxlog (r, x)
     double *r, *x;
{
    copyfloat(&hugolein,x);
    kunochen = log(hugolein);
    copyfloat(r,&kunochen);
    /* *r = log( *x ); */
}

uxatan2 (r, y, x)
     double *r, *y, *x;
{
    copyfloat(&hugolein,x);
    copyfloat(&kunochen,y);
    kunochen = atan2(kunochen,hugolein);
    copyfloat(r,&kunochen);
    /* *r = atan2( *y , *x ); */
}


copyfloat(to,from)
int * to,*from;

{ to[0] = from [0];
  to[1] = from [1];
  return (0);
}

/*
fp_analyse_xcp()

{ if  (fp_read_flag() & FP_DIV_BY_ZERO) kill(getpid(),8);
  if  (fp_read_flag() &  FP_OVERFLOW)   kill(getpid(),8);
  if  (fp_read_flag() & FP_INVALID)     kill(getpid(),8);
    fp_swap_flag (0);
}*/
