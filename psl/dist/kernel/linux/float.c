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
% Status:       Experimental (Do Not Distribute)
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

#include <string.h>
#include <math.h>

/* Tag( uxfloat )
 */
uxfloat(f,i)
     double *f;
     int i;
{
  *f = i;
}

/* Tag( uxfix )
 */
int uxfix(f)
     double *f;
{
  return *f;
}

/* Tag( uxassign )
 */
uxassign(f1,f2)
     double *f1, *f2;
{
  *f1 = *f2;
}

uxminus(f1,f2)
     double *f1, *f2;
{
  *f1 = -*f2;
}

/* Tag( uxplus2 )
 */
uxplus2(f1,f2,f3)
     double *f1, *f2, *f3;
{
  *f1 = *f2 + *f3;
}

/* Tag( uxdifference )
 */
uxdifference(f1,f2,f3)
     double *f1, *f2, *f3;
{
  *f1 = *f2 - *f3;
}

/* Tag( uxtimes2 )
 */
uxtimes2(f1,f2,f3)
     double *f1, *f2, *f3;
{
  *f1 = *f2 * *f3;
}

/* Tag( uxquotient )
 */
uxquotient(f1,f2,f3)
     double *f1, *f2, *f3;
{
  *f1 = *f2 / *f3;
}

/* Tag( uxgreaterp )
 */
int uxgreaterp(f1,f2,val1,val2)
     double *f1, *f2;
     int val1, val2;
{
  if (*f1 > *f2)
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
  if (*f1 < *f2)
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
  double tempf;

  temps = buf + 4;       /* Skip over lisp string length to write data */

  sprintf(temps, convstr, *flt);

  if (finite(*flt))
    {

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
    } 
  /* Install the length of the string into the Lisp header word
   */
  *((int *)buf) = strlen(temps) - 1;
}


/* Tag( uxdoubletofloat )
 */
uuxdoubletofloat (dbl,flt)
     double *dbl;
     float  *flt;
{
  *flt = (float) *dbl;
}

uuxfloattodouble (flt,dbl)
     float  *flt;             
     double *dbl;             
{
  *dbl = (double) *flt;
}

/* Functions for fast-math.sl (Unix C replacement for mathlib.) */
uuxsin (r, x)
     double *r, *x;
{
    *r = sin( *x );
}

uuxcos (r, x)
     double *r, *x;
{
    *r = cos( *x );
}

uuxtan (r, x)
     double *r, *x;
{
    *r = tan( *x );
}

uuxasin (r, x)
     double *r, *x;
{
    *r = asin( *x );
}

uuxacos (r, x)
     double *r, *x;
{
    *r = acos( *x );
}

uuxatan (r, x)
     double *r, *x;
{
    *r = atan( *x );
}

uuxsqrt (r, x)
     double *r, *x;
{
    *r = sqrt( *x );
}

uuxexp (r, x)
     double *r, *x;
{
    *r = exp( *x );
}

uuxlog (r, x)
     double *r, *x;
{
    *r = log( *x );
}

uuxatan2 (r, y, x)
     double *r, *y, *x;
{
    *r = atan2( *y, *x );
}
