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
%  $Id$
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
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
#define pow     pow_rn

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
uxassign(double *f1, double *f2)
{
  *f1 = *f2;
}


fexcept_t flagp;

int
uxminus(double *f1,double *f2)
{
  feclearexcept(FE_OVERFLOW | FE_INVALID);
  *f1 = -*f2;
  if(fetestexcept(FE_OVERFLOW | FE_INVALID) != 0)
    {
      feclearexcept(FE_OVERFLOW | FE_INVALID);
      return (0);
    }
  return (1);
}

/* Tag( uxplus2 )
 */
int
uxplus2(double *f1,double *f2,double *f3)
{
  feclearexcept(FE_OVERFLOW | FE_INVALID);
  *f1 = *f2 + *f3;
  if(fetestexcept(FE_OVERFLOW | FE_INVALID) != 0)
    {
      feclearexcept(FE_OVERFLOW | FE_INVALID);
      return (0);
    }
  return (1);
}

/* Tag( uxdifference )
 */
int
uxdifference(double *f1,double *f2,double *f3)
{
  feclearexcept(FE_OVERFLOW | FE_INVALID);
  *f1 = *f2 - *f3;
  if(fetestexcept(FE_OVERFLOW | FE_INVALID) != 0)
    {
      feclearexcept(FE_OVERFLOW | FE_INVALID);
      return (0);
    }
  return (1);
}

/* Tag( uxtimes2 )
 */
int
uxtimes2(double *f1,double *f2,double *f3)
{
  feclearexcept(FE_OVERFLOW | FE_INVALID);
  *f1 = *f2 * *f3;
  if(fetestexcept(FE_OVERFLOW | FE_INVALID) != 0)
    {
      feclearexcept(FE_OVERFLOW | FE_INVALID);
      return (0);
    }
  return (1);
}

/* Tag( uxquotient )
 */
int
uxquotient(double *f1,double *f2,double *f3)
{
  feclearexcept(FE_OVERFLOW | FE_DIVBYZERO | FE_INVALID);
  *f1 = *f2 / *f3;
  if(fetestexcept(FE_OVERFLOW | FE_DIVBYZERO | FE_INVALID) != 0)
    {
      feclearexcept(FE_OVERFLOW | FE_DIVBYZERO | FE_INVALID) ;
      return (0);
    }
  return (1);
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


// Length of lisp string object in bytes, as allocated in printers.sl.
#define WRITENUMBERBUFFERSIZE 100
// Maximum length of string for floating point printing
#define MAX_FLOAT_STRING_LENGTH WRITENUMBERBUFFERSIZE-8

typedef struct {
  long long size;
  char string[MAX_FLOAT_STRING_LENGTH];
} LispString;

/* Tag( uxwritefloat )
 */
void
uxwritefloat(LispString *buf, double *flt, char *convstr)
//     LispString *buf;    /* Lisp string buffer to return float in */
//     double *flt;        /* Pointer to the float */
//     char *convstr;      /* String containing conversion field for sprintf */
{
  char *temps, *dot, *e;
  char tempbuf [WRITENUMBERBUFFERSIZE]; /* reasonable size limit */

  temps = buf->string;       /* Skip over lisp string length to write data */

  snprintf(temps, MAX_FLOAT_STRING_LENGTH, convstr, *flt);

  if (isfinite(*flt))
    {
      /* Make sure that there is a trailing .0
       */
      dot = strrchr(temps, '.');
      if (dot == NULL)
	{
	  /* Check to see if the number is in scientific notation. If so,
	   *  we must add the .0 into the middle of the string,
	   *  just before the "e".
	   */
	  if ((e = strrchr(temps, 'e')) != NULL ||
	      (e = strrchr(temps, 'E')) != NULL)
	    {
	      /* save exponent part */
	      strncpy(tempbuf, e, sizeof(tempbuf) - 1);
	      // Now splice in ".0" before the exponent part
	      *e = '\0'; 
	      strncat(temps, ".0", MAX_FLOAT_STRING_LENGTH - strlen(temps) - 1);
	      strncat(temps, tempbuf, MAX_FLOAT_STRING_LENGTH - strlen(temps) - 1);
	    }
	  else
	    {
	      strncat(temps, ".0", MAX_FLOAT_STRING_LENGTH - strlen(temps) - 1);
	    }
	}
    }
  /* Install the length of the string into the Lisp header word.
     Note that the header word is the 0-based index of the last character,
     e.g. length - 1 .
   */
  buf->size = strlen(temps) - 1;
}

void
uxwritefloat8(LispString* buf, double* flt, char* convstr, int dummy)
//     LispString *buf;    /* Lisp string buffer to return float int */
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
  feclearexcept(FE_INVALID);
  *r = sin( *x );
  if(fetestexcept(FE_INVALID) != 0)
    {
      feclearexcept(FE_INVALID);
      return (0);
    }
  return (1);
}

int
uxcos (double *r, double *x)
{
  feclearexcept(FE_INVALID);
  *r = cos( *x );
  if(fetestexcept(FE_INVALID) != 0)
    {
      feclearexcept(FE_INVALID);
      return (0);
    }
  return (1);
}

int
uxtan (double *r, double *x)
{
  feclearexcept(FE_OVERFLOW | FE_INVALID);
  *r = tan( *x );
  if(fetestexcept(FE_OVERFLOW | FE_INVALID) != 0)
    {
      feclearexcept(FE_OVERFLOW | FE_INVALID);
      return (0);
    }
  return (1);
}

int
uxasin (double *r, double *x)
{
  feclearexcept(FE_INVALID);
  *r = asin( *x );
  if(fetestexcept(FE_INVALID) != 0)
    {
      feclearexcept(FE_INVALID);
      return (0);
    }
  return (1);
}

int
uxacos (double *r, double *x)
{
  feclearexcept(FE_INVALID);
  *r = acos( *x );
  if(fetestexcept(FE_INVALID) != 0)
    {
      feclearexcept(FE_INVALID);
      return (0);
    }
  return (1);
}

int
uxatan (double *r, double *x)
{
  feclearexcept(FE_OVERFLOW | FE_DIVBYZERO| FE_INVALID);
  *r = atan( *x );
  if(fetestexcept(FE_OVERFLOW | FE_DIVBYZERO | FE_INVALID) != 0)
    {
      feclearexcept(FE_OVERFLOW | FE_DIVBYZERO | FE_INVALID);
      return (0);
    }
  return (1);
}

int
uxsqrt (double *r, double *x)
{
  feclearexcept(FE_INVALID);
  *r = sqrt( *x );
  if(fetestexcept(FE_INVALID) != 0)
    {
      feclearexcept(FE_INVALID);
      return (0);
    }
  return (1);
}

int
uxexp (double *r, double *x)
{
  feclearexcept(FE_OVERFLOW | FE_UNDERFLOW);
  *r = exp( *x );
  if(fetestexcept(FE_OVERFLOW | FE_UNDERFLOW) != 0)
    {
      feclearexcept(FE_OVERFLOW | FE_UNDERFLOW);
      return (0);
    }
  return (1);
}

int
uxlog (double *r, double *x)
{
  feclearexcept(FE_DIVBYZERO | FE_INVALID);
  *r = log( *x );
  if(fetestexcept(FE_DIVBYZERO | FE_INVALID) != 0)
    {
      feclearexcept(FE_DIVBYZERO | FE_INVALID);return (0);
    }
  return (1);
}

int
uxatan2 (double *r, double *y, double *x)
{
  feclearexcept(FE_OVERFLOW | FE_DIVBYZERO);
  *r = atan2( *y, *x );
  if(fetestexcept(FE_OVERFLOW | FE_DIVBYZERO) != 0)
    {
      feclearexcept(FE_OVERFLOW | FE_DIVBYZERO);
      return (0);
    }
  return (1);
}

int
uxsinh (double *r, double *x)
{
  feclearexcept(FE_OVERFLOW);
  *r = sinh( *x );
  if(fetestexcept(FE_OVERFLOW) != 0)
    {
      feclearexcept(FE_OVERFLOW);
      return (0);
    }
  return (1);
}

int
uxcosh (double *r, double *x)
{
  feclearexcept(FE_OVERFLOW);
  *r = cosh( *x );
  if(fetestexcept(FE_OVERFLOW) != 0)
    {
      feclearexcept(FE_OVERFLOW);
      return (0);
    }
  return (1);
}

int
uxtanh (double *r, double *x)
{
  feclearexcept(FE_OVERFLOW | FE_DIVBYZERO);
  *r = tanh( *x );
  if(fetestexcept(FE_OVERFLOW | FE_DIVBYZERO) != 0)
    {
      feclearexcept(FE_OVERFLOW | FE_DIVBYZERO);
      return (0);
    }
  return (1);
}

int
uxhypot (double *res, double *x, double *y)
{
  feclearexcept(FE_OVERFLOW | FE_UNDERFLOW);
  *res = hypot( *x, *y );
  if(fetestexcept(FE_OVERFLOW | FE_UNDERFLOW) != 0)
    {
      feclearexcept(FE_OVERFLOW | FE_UNDERFLOW);
      return (0);
    }
  return 1;
}

int
uxpow (double *res, double *x, double *y)
{
  feclearexcept(FE_OVERFLOW | FE_UNDERFLOW | FE_DIVBYZERO | FE_INVALID);
  *res = pow( *x, *y );
  if(fetestexcept(FE_OVERFLOW | FE_UNDERFLOW | FE_DIVBYZERO | FE_INVALID) != 0)
    {
      feclearexcept(FE_OVERFLOW | FE_UNDERFLOW | FE_DIVBYZERO | FE_INVALID);
      return (0);
    }
  return 1;
}
