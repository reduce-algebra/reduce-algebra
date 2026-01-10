/*
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PXK:FLOAT.C
% Description:  Miscellaneous floating point support routines for FreeBSD on i386.
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
%
%  $Id$
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
*/

#include <string.h>
#include <math.h>
#include <fenv.h>

#ifdef USE_CRLIBM
#include "crlibm.h"

#define sin	sin_rn
#define cos	cos_rn
#define tan 	tan_rn
#define asin	asin_rn
#define acos	acos_rn
#define atan	atan_rn
#define exp	exp_rn
#define log	log_rn
#define sinh	sinh_rn
#define cosh	cosh_rn

#endif

/* Tag( uxfloat )
 */
void
uxfloat(double *f,int i)
{
  *f = i;
}

/* Tag( uxfix )
 */
int uxfix(double *f)
{
  return *f;
}

/* Tag( uxassign )
 */
void
uxassign(double *f1, double*f2)
{
  *f1 = *f2;
}


fexcept_t flagp;

int
uxminus(double *f1,double *f2)
{
  *f1 = -*f2;
  fegetexceptflag(&flagp, FE_OVERFLOW | FE_DIVBYZERO | FE_INVALID);
  if(flagp != 0) {feclearexcept(FE_OVERFLOW | FE_DIVBYZERO | FE_INVALID); return (0);}
  return (1);
}

/* Tag( uxplus2 )
 */
int
uxplus2(double *f1,double *f2,double *f3)
{
  *f1 = *f2 + *f3;
  fegetexceptflag(&flagp, FE_OVERFLOW | FE_DIVBYZERO | FE_INVALID);
  if(flagp != 0) {feclearexcept(FE_OVERFLOW | FE_DIVBYZERO | FE_INVALID); return (0);}
  return (1);
}

/* Tag( uxdifference )
 */
int
uxdifference(double *f1,double *f2,double *f3)
{
  *f1 = *f2 - *f3;
  fegetexceptflag(&flagp, FE_OVERFLOW | FE_DIVBYZERO | FE_INVALID);
  if(flagp != 0) {feclearexcept(FE_OVERFLOW | FE_DIVBYZERO | FE_INVALID); return (0);}
  return (1);
}

/* Tag( uxtimes2 )
 */
int
uxtimes2(double *f1,double *f2,double *f3)
{
  *f1 = *f2 * *f3;
  fegetexceptflag(&flagp, FE_OVERFLOW | FE_DIVBYZERO | FE_INVALID);
  if(flagp != 0) {feclearexcept(FE_OVERFLOW | FE_DIVBYZERO | FE_INVALID); return (0);}
  return (1);
}

/* Tag( uxquotient )
 */
int
uxquotient(double *f1,double *f2,double *f3)
{
  *f1 = *f2 / *f3;
  fegetexceptflag(&flagp, FE_OVERFLOW | FE_DIVBYZERO | FE_INVALID);
  if(flagp != 0) {feclearexcept(FE_OVERFLOW | FE_DIVBYZERO | FE_INVALID); return (0);}
  return (1);
}

/* Tag( uxgreaterp )
 */
int uxgreaterp(double *f1,double *f2,int val1,int val2)
{
  if (*f1 > *f2)
    return val1;
  else
    return val2;
}

/* Tag( uxlessp )
 */
int uxlessp(double *f1,double *f2,int val1,int val2)
{
  if (*f1 < *f2)
    return val1;
  else
    return val2;
}

/* Tag( uxwritefloat )
 */
void
uxwritefloat(char *buf, double *flt, char *convstr)
//     char *buf;          /* String buffer to return float int */
//     double *flt;        /* Pointer to the float */
//     char *convstr;      /* String containing conversion field for sprintf */
{
  char *temps, *dot, *e;
  char tempbuf[102]; /* reasonable size limit */

  temps = buf + 4;       /* Skip over lisp string length to write data */

  snprintf(temps, 99, convstr, *flt);

  if (finite(*flt))
    {
      /* Make sure that there is a trailing .0
       */
      dot = strrchr(temps, '.');
      if (dot == NULL)
	{
	  /* Check to see if the number is in scientific notation. If so, we need
	   *  add the .0 into the middle of the string, just before the e.
	   */
	  if ((e = strrchr(temps, 'e')) || (e = strrchr(temps, 'E')))
	    {
	      strncpy(tempbuf, e, 100); /* save exponent part */
	      // Now add ".0" and exponent part
	      *e = '\0'; 
	      strcat(temps, ".0");     /* Add .0 onto original string */
	      strcat(temps, tempbuf);  /* add the exponent part onto the end */
	    }
	  else
	    {
	      strcat(temps, ".0");
	    }
	}
    }
  /* Install the length of the string into the Lisp header word
   */
  *((int *)buf) = strlen(temps) - 1;
}


/* Tag( uxdoubletofloat )
 */
void
uuxdoubletofloat (double *dbl,float *flt)
{
  *flt = (float) *dbl;
}

void
uuxfloattodouble (float *flt, double *dbl)
{
  *dbl = (double) *flt;
}

/* Functions for fast-math.sl (Unix C replacement for mathlib.) */
int
uuxsin (double *r, double *x)
{
    *r = sin( *x );
    fegetexceptflag(&flagp, FE_OVERFLOW | FE_DIVBYZERO | FE_INVALID);
    if(flagp != 0) {feclearexcept(FE_OVERFLOW | FE_DIVBYZERO | FE_INVALID); return (0);}
  return (1);
}

int
uuxcos (double *r, double *x)
{
  *r = cos( *x );
  fegetexceptflag(&flagp, FE_OVERFLOW | FE_DIVBYZERO);
  if(flagp != 0) {feclearexcept(FE_OVERFLOW | FE_DIVBYZERO); return (0);}
  return (1);
}

int
uuxtan (double *r, double *x)
{
    *r = tan( *x );
    fegetexceptflag(&flagp, FE_OVERFLOW | FE_DIVBYZERO | FE_INVALID);
    if(flagp != 0) {feclearexcept(FE_OVERFLOW | FE_DIVBYZERO | FE_INVALID); return (0);}
  return (1);
}

int
uuxasin (double *r, double *x)
{
    *r = asin( *x );
    fegetexceptflag(&flagp, FE_OVERFLOW | FE_DIVBYZERO | FE_INVALID);
if(flagp != 0) {feclearexcept(FE_OVERFLOW | FE_DIVBYZERO | FE_INVALID); return (0);}
  return (1);
}

int
uuxacos (double *r, double *x)
{
  *r = acos( *x );
  fegetexceptflag(&flagp, FE_OVERFLOW | FE_DIVBYZERO);
  if(flagp != 0) {feclearexcept(FE_OVERFLOW | FE_DIVBYZERO); return (0);}
  return (1);
}

int
uuxatan (double *r, double *x)
{
  *r = atan( *x );
  fegetexceptflag(&flagp, FE_OVERFLOW | FE_DIVBYZERO | FE_INVALID);
  if(flagp != 0) {feclearexcept(FE_OVERFLOW | FE_DIVBYZERO | FE_INVALID); return (0);}
  return (1);
}

int
uuxsqrt (double *r, double *x)
{
    *r = sqrt( *x );
    fegetexceptflag(&flagp, FE_OVERFLOW | FE_DIVBYZERO | FE_INVALID);
    if(flagp != 0) {feclearexcept(FE_OVERFLOW | FE_DIVBYZERO | FE_INVALID); return (0);}
    return (1);      
}

int
uuxexp (double *r, double *x)
{
  *r = exp( *x );
  fegetexceptflag(&flagp, FE_OVERFLOW | FE_DIVBYZERO | FE_INVALID);
  if(flagp != 0) {feclearexcept(FE_OVERFLOW | FE_DIVBYZERO | FE_INVALID); return (0);}
  return (1);
}

int
uuxlog (double *r, double *x)
{
  *r = log( *x );
  fegetexceptflag(&flagp, FE_OVERFLOW | FE_DIVBYZERO | FE_INVALID);
  if(flagp != 0) {feclearexcept(FE_OVERFLOW | FE_DIVBYZERO | FE_INVALID); return (0);}
  return (1);
}

int
uuxatan2 (double *r, double *y, double *x)
{
  *r = atan2( *y, *x );
  fegetexceptflag(&flagp, FE_OVERFLOW | FE_DIVBYZERO);
  if(flagp != 0) {feclearexcept(FE_OVERFLOW | FE_DIVBYZERO); return (0);}
  return (1);
}

int
uuxsinh (double *r, double *x)
{
  *r = sinh( *x );
  fegetexceptflag(&flagp, FE_OVERFLOW | FE_DIVBYZERO);
  if(flagp != 0) {feclearexcept(FE_OVERFLOW | FE_DIVBYZERO); return (0);}
  return (1);
}

int
uuxcosh (double *r, double *x)
{
  *r = cosh( *x );
  fegetexceptflag(&flagp, FE_OVERFLOW | FE_DIVBYZERO);
  if(flagp != 0) {feclearexcept(FE_OVERFLOW | FE_DIVBYZERO); return (0);}
  return (1);
}

int
uuxtanh (double *r, double *x)
{
  *r = tanh( *x );
  fegetexceptflag(&flagp, FE_OVERFLOW | FE_DIVBYZERO);
  if(flagp != 0) {feclearexcept(FE_OVERFLOW | FE_DIVBYZERO); return (0);}
  return (1);
}

int
uuxhypot (double *res, double *x, double *y)
{
    *res = hypot( *x, *y );
    fegetexceptflag(&flagp, FE_OVERFLOW | FE_DIVBYZERO);
    if(flagp != 0) {feclearexcept(FE_OVERFLOW | FE_DIVBYZERO); return (0);}
    return 1;
}
