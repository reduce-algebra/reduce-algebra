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

#ifdef ALPHA
#define LONG __int64
#else
#define LONG long
#endif


#include <string.h>
#include <math.h>
#include <excpt.h>

extern LONG unix_error;

/* Tag( uxfloat )
 */
uxfloat(f,i)
     double *f;
     LONG i;
{
  *f = i;
}


LONG uxfix(f)
     double *f;
{
  LONG i;
  unix_error = 0; 
  try { i = *f;}
    except(EXCEPTION_EXECUTE_HANDLER) { unix_error = 1;};
  return i;
}


uxassign(f1,f2)
     double *f1, *f2;
{
  try{ *f1 = *f2; unix_error = 0;}
   except(EXCEPTION_EXECUTE_HANDLER) { unix_error = 1;};
}


uxplus2(f1,f2,f3)
     double *f1, *f2, *f3;
{
  try{ *f1 = *f2 + *f3; return 0;}
   except(EXCEPTION_EXECUTE_HANDLER) {return 1;}
}

uxdifference(f1,f2,f3)
     double *f1, *f2, *f3;
{
  try{ *f1 = *f2 - *f3; return 0;}
   except(EXCEPTION_EXECUTE_HANDLER) {return 1;}
}


uxtimes2(f1,f2,f3)
     double *f1, *f2, *f3;
{
  try{ *f1 = *f2 * *f3; return 0;}
   except(EXCEPTION_EXECUTE_HANDLER) {return 1;}
}

uxquotient(f1,f2,f3)
     double *f1, *f2, *f3;
{
  if(*f3 == 0.0) return(1);
  try{ *f1 = *f2 / *f3; return 0;}
   except(EXCEPTION_EXECUTE_HANDLER) {return 1;}
}


LONG uxgreaterp(f1,f2,val1,val2)
     double *f1, *f2;
     LONG val1, val2;
{
  if (*f1 > *f2)
    return val1;
  else
    return val2;
}



LONG uxlessp(f1,f2,val1,val2)
     double *f1, *f2;
     LONG val1, val2;
{
  if (*f1 < *f2)
    return val1;
  else
    return val2;
}



uxwritefloat(buf, flt, convstr)
     char *buf;          /* String buffer to return float int */
     double *flt;        /* Pointer to the float */
     char *convstr;      /* String containing conversion field for sprintf */
{  
  char *temps, *dot, *e;
  char tempbuf[100]; /* reasonable size limit */
  double tempf;

try{

#ifdef ALPHA
  temps = buf + 8;
#else
  temps = buf + 4;       /* Skip over lisp string length to write data */
#endif

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
  
  /* Install the length of the string into the Lisp header word */

  *((LONG *)buf) = strlen(temps) - 1;
  
   return 0;
 }
       except(EXCEPTION_EXECUTE_HANDLER) {return 1;}
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
uxxsin (r, x)
     double *r, *x;
{
  try{ *r = sin( *x ); return 0;}
   except(EXCEPTION_EXECUTE_HANDLER) {return 1;}
}

uxxcos (r, x)
     double *r, *x;
{
  try{ *r = cos( *x ); return 0;}
   except(EXCEPTION_EXECUTE_HANDLER) {return 1;}
}

uxxtan (r, x)
     double *r, *x;
{
  try{ *r = tan( *x ); return 0;}
   except(EXCEPTION_EXECUTE_HANDLER) {return 1;}
}

uxxasin (r, x)
     double *r, *x;
{
  try{ *r = asin( *x ); return 0;}
   except(EXCEPTION_EXECUTE_HANDLER) {return 1;}
}

uxxacos (r, x)
     double *r, *x;
{
  try{ *r = acos( *x ); return 0;}
   except(EXCEPTION_EXECUTE_HANDLER) {return 1;}
}

uxxatan (r, x)
     double *r, *x;
{
  try{ *r = atan( *x ); return 0;}
   except(EXCEPTION_EXECUTE_HANDLER) {return 1;}
}

uxxsqrt (r, x)
     double *r, *x;
{
  try{ *r = sqrt( *x ); return 0;}
   except(EXCEPTION_EXECUTE_HANDLER) {return 1;};
}

uxxexp (r, x)
     double *r, *x;
{
  try{ *r = exp( *x ); return 0;}
   except(EXCEPTION_EXECUTE_HANDLER) {return 1;}
}

uxxlog (r, x)
     double *r, *x;
{
  try{ *r = log( *x ); return 0;}
   except(EXCEPTION_EXECUTE_HANDLER) {return 1;}
}

uxxatan2 (r, y, x)
     double *r, *y, *x;
{
 try{ *r = atan2( *y, *x ); return 0;}
   except(EXCEPTION_EXECUTE_HANDLER) {return 1;}
}
