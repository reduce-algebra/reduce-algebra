/*
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PXK:FLOAT.C
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
%
%  $Id: float.c 6307 2022-05-11 15:35:54Z schoepf $
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
*/

#include <stdio.h>
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
uxfloat(double *f,long long i)
{
  *f = i;
}

/* Tag( uxfix )
 */
long long uxfix(double *f)
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
  fegetexceptflag(&flagp, FE_OVERFLOW | FE_DIVBYZERO);
  if(flagp != 0) {feclearexcept(FE_OVERFLOW | FE_DIVBYZERO); return (0);}
  return (1);
}

/* Tag( uxplus2 )
 */
int
uxplus2(double *f1,double *f2,double *f3)
{
  *f1 = *f2 + *f3;
  fegetexceptflag(&flagp, FE_OVERFLOW | FE_DIVBYZERO);
  if(flagp != 0) {feclearexcept(FE_OVERFLOW | FE_DIVBYZERO); return (0);}
  return (1);
}

/* Tag( uxdifference )
 */
int
uxdifference(double *f1,double *f2,double *f3)
{
  *f1 = *f2 - *f3;
  fegetexceptflag(&flagp, FE_OVERFLOW | FE_DIVBYZERO);
  if(flagp != 0) {feclearexcept(FE_OVERFLOW | FE_DIVBYZERO); return (0);}
  return (1);
}

/* Tag( uxtimes2 )
 */
int
uxtimes2(double *f1,double *f2,double *f3)
{
  *f1 = *f2 * *f3;
  fegetexceptflag(&flagp, FE_OVERFLOW | FE_DIVBYZERO);
  if(flagp != 0) {feclearexcept(FE_OVERFLOW | FE_DIVBYZERO); return (0);}
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

/* Tag( uxequal )
 */
long long uxequal(double *f1,double *f2,long long val1,long long val2)
{
  if (*f1 == *f2)
    return val1;
  else
    return val2;
}

/* Tag( uxgreaterp )
 */
long long uxgreaterp(double *f1,double *f2,long long val1,long long val2)
{
  if (*f1 > *f2)
    return val1;
  else
    return val2;
}

/* Tag( uxlessp )
 */
long long uxlessp(double *f1,double *f2,long long val1,long long val2)
{
  if (*f1 < *f2)
    return val1;
  else
    return val2;
}

#define WRITENUMBERBUFFERSIZE 100

typedef struct {
  long long size;
  char string[WRITENUMBERBUFFERSIZE-8];
} LispString;

/* Tag( uxwritefloat )
 */
void
uxwritefloat(LispString *buf, double *flt, char *convstr)
//     char *buf;          /* String buffer to return float int */
//     double *flt;        /* Pointer to the float */
//     char *convstr;      /* String containing conversion field for sprintf */
{
  char *temps, *dot, *e;
  char tempbuf [100]; /* reasonable size limit */

  temps = buf->string;       /* Skip over lisp string length to write data */

  snprintf(temps, WRITENUMBERBUFFERSIZE-8, convstr, *flt);

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
	      strlcat(temps, ".0", WRITENUMBERBUFFERSIZE-8);
	      strlcat(temps, tempbuf, WRITENUMBERBUFFERSIZE-8);
	    }
	  else
	    {
	      strlcat(temps, ".0", WRITENUMBERBUFFERSIZE-8);
	    }
	}
    }
  /* Install the length of the string into the Lisp header word
   */
  buf->size = strlen(temps) - 1;
}

void
uxwritefloat8(LispString* buf, double* flt, char* convstr, int dummy)
//     char *buf;          /* String buffer to return float int */
//     double *flt;        /* Pointer to the float */
//     char *convstr;      /* String containing conversion field for sprintf */
//     int dummy;  /* We need to have 128 bit alingemnt of the stack */
{ uxwritefloat(buf, flt, convstr); }


/* Tag( uxdoubletofloat )
 */
void
uxdoubletofloat (double *dbl,float *flt)
{
  *flt = (float) *dbl;
}

void
uxfloattodouble (float *flt, double *dbl)
{
  *dbl = (double) *flt;
}

/* Functions for fast-math.sl (Unix C replacement for mathlib.) */
int
uxsin (double *r, double *x)
{
  *r = sin( *x );
  fegetexceptflag(&flagp, FE_OVERFLOW | FE_DIVBYZERO);
  if(flagp != 0) {feclearexcept(FE_OVERFLOW | FE_DIVBYZERO); return (0);}
  return (1);
}

int
uxcos (double *r, double *x)
{
  *r = cos( *x );
  fegetexceptflag(&flagp, FE_OVERFLOW | FE_DIVBYZERO);
  if(flagp != 0) {feclearexcept(FE_OVERFLOW | FE_DIVBYZERO); return (0);}
  return (1);
}

int
uxtan (double *r, double *x)
{
  *r = tan( *x );
  fegetexceptflag(&flagp, FE_OVERFLOW | FE_DIVBYZERO);
  if(flagp != 0) {feclearexcept(FE_OVERFLOW | FE_DIVBYZERO); return (0);}
  return (1);

}

int
uxasin (double *r, double *x)
{
  *r = asin( *x );
  fegetexceptflag(&flagp, FE_OVERFLOW | FE_DIVBYZERO);
  if(flagp != 0) {feclearexcept(FE_OVERFLOW | FE_DIVBYZERO); return (0);}
  return (1);
}

int
uxacos (double *r, double *x)
{
  *r = acos( *x );
  fegetexceptflag(&flagp, FE_OVERFLOW | FE_DIVBYZERO);
  if(flagp != 0) {feclearexcept(FE_OVERFLOW | FE_DIVBYZERO); return (0);}
  return (1);
}

int
uxatan (double *r, double *x)
{
  *r = atan( *x );
  fegetexceptflag(&flagp, FE_OVERFLOW | FE_DIVBYZERO);
  if(flagp != 0) {feclearexcept(FE_OVERFLOW | FE_DIVBYZERO); return (0);}
  return (1);
}

int
uxsqrt (double *r, double *x)
{
  *r = sqrt( *x );
  fegetexceptflag(&flagp, FE_OVERFLOW | FE_DIVBYZERO);
  if(flagp != 0) {feclearexcept(FE_OVERFLOW | FE_DIVBYZERO); return (0);}
  return (1);
}

int
uxexp (double *r, double *x)
{
  *r = exp( *x );
  fegetexceptflag(&flagp, FE_OVERFLOW | FE_DIVBYZERO);
  if(flagp != 0) {feclearexcept(FE_OVERFLOW | FE_DIVBYZERO); return (0);}
  return (1);
}

int
uxlog (double *r, double *x)
{
  *r = log( *x );
  fegetexceptflag(&flagp, FE_OVERFLOW | FE_DIVBYZERO);
  if(flagp != 0) {feclearexcept(FE_OVERFLOW | FE_DIVBYZERO); return (0);}
  return (1);
}

#define _pi       ((12868.0 - 0.036490896206895257)/4096.0)
#define _half_pi  ((12868.0 - 0.036490896206895257)/8192.0)

int
uxatan2 (double *res, double *y, double *x)
{
#if 0

    *res = atan2( *y, *x );
    fegetexceptflag(&flagp, FE_OVERFLOW | FE_DIVBYZERO);
    if(flagp != 0) {feclearexcept(FE_OVERFLOW | FE_DIVBYZERO); return (0);}

#else

    double u=*x, v=*y, r;
    int q = 0;
    if (u < 0.0) u = -u, q = 1;
    if (v < 0.0) v = -v, q |= 2;
    if (v > u) { r = u; u = v; v = r; q |= 4; }
    if (u == 0.0 && v == 0.0) r = 0.0;
    else
    { r = atan(v/u);
      fegetexceptflag(&flagp, FE_OVERFLOW | FE_DIVBYZERO);
      if(flagp != 0) {feclearexcept(FE_OVERFLOW | FE_DIVBYZERO); return (0);}
      switch (q)
        {
    default:
    case 0: break;
    case 1: r = _pi - r;
            break;
    case 2: r = -r;
            break;
    case 3: r = -_pi + r;
            break;
    case 4: r = _half_pi - r;
            break;
    case 5: r = _half_pi + r;
            break;
    case 6: r = -_half_pi + r;
            break;
    case 7: r = -_half_pi - r;
            break;
        }
    }

    *res = r;
#endif
  return (1);
}

int
uxsinh (double *r, double *x)
{
  *r = sinh( *x );
  fegetexceptflag(&flagp, FE_OVERFLOW | FE_DIVBYZERO);
  if(flagp != 0) {feclearexcept(FE_OVERFLOW | FE_DIVBYZERO); return (0);}
  return (1);
}

int
uxcosh (double *r, double *x)
{
  *r = cosh( *x );
  fegetexceptflag(&flagp, FE_OVERFLOW | FE_DIVBYZERO);
  if(flagp != 0) {feclearexcept(FE_OVERFLOW | FE_DIVBYZERO); return (0);}
  return (1);
}

#if 0
// currently not used because it is not defined in crlibm
int
uxtanh (double *r, double *x)
{
  *r = tanh( *x );
  fegetexceptflag(&flagp, FE_OVERFLOW | FE_DIVBYZERO);
  if(flagp != 0) {feclearexcept(FE_OVERFLOW | FE_DIVBYZERO); return (0);}
  return (1);
}
#endif

int
uxhypot (double *res, double *x, double *y)
{
    *res = hypot( *x, *y );
    fegetexceptflag(&flagp, FE_OVERFLOW | FE_DIVBYZERO);
    if(flagp != 0) {feclearexcept(FE_OVERFLOW | FE_DIVBYZERO); return (0);}
    return 1;
}
