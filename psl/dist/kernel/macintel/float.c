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
% (c) Copyright 1986, University of Utah, all rights reserved.
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
#include <architecture/i386/fenv.h>

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
   if (fetestexcept(_FE_OVERFLOW| _FE_DIVBYZERO))
     { feclearexcept(_FE_OVERFLOW| _FE_DIVBYZERO);
       return (-1); }

}

/* Tag( uxquotient )
 */
uxquotient(f1,f2,f3)
     double *f1, *f2, *f3;
{
  *f1 = *f2 / *f3;
   if (fetestexcept(_FE_OVERFLOW| _FE_DIVBYZERO))
     { feclearexcept(_FE_OVERFLOW| _FE_DIVBYZERO);
       return (-1); }
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
  *((int *)buf) = strlen(temps) - 1;
}


/* Tag( uxdoubletofloat )
 */
uxdoubletofloat (dbl,flt)
     double *dbl;
     float  *flt;
{
  *flt = (float) *dbl;
}

uxfloattodouble (flt,dbl)
     float  *flt;             
     double *dbl;             
{
  *dbl = (double) *flt;
}

/* Functions for fast-math.sl (Unix C replacement for mathlib.) */
uxsin (r, x)
     double *r, *x;
{
    *r = sin( *x );
}

uxcos (r, x)
     double *r, *x;
{
    *r = cos( *x );
}

uxtan (r, x)
     double *r, *x;
{
    *r = tan( *x );
}

uxasin (r, x)
     double *r, *x;
{
    *r = asin( *x );
}

uxacos (r, x)
     double *r, *x;
{
    *r = acos( *x );
}

uxatan (r, x)
     double *r, *x;
{
    *r = atan( *x );
}

uxsqrt (r, x)
     double *r, *x;
{
    *r = sqrt( *x );
}

uxexp (r, x)
     double *r, *x;
{
    *r = exp( *x );
}

uxlog (r, x)
     double *r, *x;
{
    *r = log( *x );
}

uxatan2 (r, y, x)
     double *r, *y, *x;
{
    *r = atan2( *y, *x );
}
