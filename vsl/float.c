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
*/

/*
 * There used to be a collection of comments here describing revisions
 * made from about 1982 to 1989. I think those are by now of interest
 * to archaeologists! So anybody who wants to see them can consult older
 * copies of this file in the repositories. It is neverthless proper to
 * record the names of those who (in addition to the original author)
 * have contributed:
 *             Leigh Stoller
 */


#include <stdio.h>
#include <string.h>
#include <math.h>
#include <fenv.h>
#include <inttypes.h>

#ifdef USE_CRLIBM
#include "crlibm.h"

#define sin     sin_rn
#define cos     cos_rn
#define tan     tan_rn
#define asin    asin_rn
#define acos    acos_rn
#define atan    atan_rn
#define exp     exp_rn
#define log     log_rn

#endif

/*
 * The functions here are (just) called from compiled code. In the
 * assembly code for the kernel the code is written with the names
 * having a leading underscore. For Linux that underscore remains
 * visible here in the C code that is linked to, while under Cygwin
 * or on a Macintosh it is not. So here I define functions whose names
 * have leading underscores if I am on Linux but not otherwise. This is
 * a bit messy and ugly but is still about the neatest I can think of
 * at present if I want one body of code to apply everywhere.
 */

#if defined __linux__ || defined __CYGWIN__
#define _(x) _ ## x
#else
#define _(x) x
#endif

/* Tag( uxfloat )
 */
void _(uxfloat)(double *f, int64_t i)
{   *f = i;
}

/* Tag( uxfix )
 */
int64_t _(uxfix)(double *f)
{   return *f;
}

/* Tag( uxassign )
 */
void _(uxassign)(double *f1, double *f2)
{   *f1 = *f2;
}

fexcept_t flagp;

/* Tag( uxplus2 )
 */
int _(uxplus2)(double *f1, double *f2, double *f3)
{   *f1 = *f2 + *f3;
    fegetexceptflag(&flagp, FE_OVERFLOW | FE_DIVBYZERO);
    if(flagp != 0)
    {   feclearexcept(FE_OVERFLOW | FE_DIVBYZERO);
        return (0);
    }
    return (1);
}

/* Tag( uxdifference )
 */
int _(uxdifference)(double *f1, double *f2, double *f3)
{   *f1 = *f2 - *f3;
    fegetexceptflag(&flagp, FE_OVERFLOW | FE_DIVBYZERO);
    if(flagp != 0)
    {   feclearexcept(FE_OVERFLOW | FE_DIVBYZERO);
        return (0);
    }
    return (1);
}

/* Tag( uxtimes2 )
 */
int _(uxtimes2)(double *f1, double *f2, double *f3)
{   *f1 = *f2 * *f3;
    fegetexceptflag(&flagp, FE_OVERFLOW | FE_DIVBYZERO);
    if(flagp != 0)
    {   feclearexcept(FE_OVERFLOW | FE_DIVBYZERO);
        return (0);
    }
    return (1);
}

/* Tag( uxquotient )
 */
int _(uxquotient)(double *f1, double *f2, double *f3)
{   *f1 = *f2 / *f3;
    fegetexceptflag(&flagp, FE_OVERFLOW | FE_DIVBYZERO | FE_INVALID);
    if(flagp != 0)
    {   feclearexcept(FE_OVERFLOW | FE_DIVBYZERO | FE_INVALID);
        return (0);
    }
    return (1);
}

/* Tag( uxgreaterp )
 */
int64_t _(uxgreaterp)(double *f1, double *f2, int64_t val1, int64_t val2)
{   if (*f1 > *f2) return val1;
    else return val2;
}

/* Tag( uxlessp )
 */
int64_t _(uxlessp)(double *f1, double *f2, int64_t val1, int64_t val2)
{   if (*f1 < *f2) return val1;
    else return val2;
}

/* Tag( uxwritefloat )
 */
void _(uxwritefloat)(char *buf, double *flt, const char *convstr)
/*   char *buf;           String buffer to return float int */
/*   double *flt;         Pointer to the float */
/*   char *convstr;       String containing conversion field for sprintf */
{   char *temps, *dot, *e;
    char tempbuf[100]; /* reasonable size limit */
    float tempf;

    temps = buf + 8;       /* Skip over lisp string length to write data */

    sprintf(temps, convstr, *flt);

    if (isfinite(*flt))
    {

        /* Make sure that there is a trailing .0
         */
        dot = strrchr(temps, '.');
        if (dot == NULL)
        {   /* Check to see if the number is in scientific notation. If so, we need
             *  add the .0 into the middle of the string, just before the e.
             */
            if ((e = strrchr(temps, 'e')) || (e = strrchr(temps, 'E')))
            {   strcpy(tempbuf, e);       /* save exponent part */
                *e = '\0';
                strcat(temps, ".0");     /* Add .0 ono original string */
                strcat(temps, tempbuf);  /* add the exponent part onto the end */
            }
            else
            {   strcat(temps, ".0");
            }
        }
    }
    /* Install the length of the string into the Lisp header word
     */
    *((int64_t *)buf) = strlen(temps) - 1;
}

void _(uxwritefloat8)(char *buf, double *flt, const char *convstr, int dummy)
/*     char *buf;           String buffer to return float int */
/*     double *flt;         Pointer to the float */
/*     char *convstr;       String containing conversion field for sprintf */
/*     int dummy;   We need to have 128 bit alignemnt of the stack */
{   _(uxwritefloat)(buf, flt, convstr);
}


/* Tag( uxdoubletofloat )
 */
void _(uxdoubletofloat)(double *dbl, float *flt)
{   *flt = (float) *dbl;
}

void _(uxfloattodouble)(float *flt, double *dbl)
{   *dbl = (double) *flt;
}

/* Functions for fast-math.sl (Unix C replacement for mathlib.) */
int _(uxsin)(double *r, double *x)
{   *r = sin( *x );
    fegetexceptflag(&flagp, FE_OVERFLOW | FE_DIVBYZERO);
    if(flagp != 0)
    {   feclearexcept(FE_OVERFLOW | FE_DIVBYZERO);
        return (0);
    }
    return (1);
}

int _(uxcos)(double *r, double *x)
{   *r = cos( *x );
    fegetexceptflag(&flagp, FE_OVERFLOW | FE_DIVBYZERO);
    if(flagp != 0)
    {   feclearexcept(FE_OVERFLOW | FE_DIVBYZERO);
        return (0);
    }
    return (1);
}

int _(uxtan)(double *r, double *x)
{   *r = tan( *x );
    fegetexceptflag(&flagp, FE_OVERFLOW | FE_DIVBYZERO);
    if(flagp != 0)
    {   feclearexcept(FE_OVERFLOW | FE_DIVBYZERO);
        return (0);
    }
    return (1);

}

int _(uxasin)(double *r, double *x)
{   *r = asin( *x );
    fegetexceptflag(&flagp, FE_OVERFLOW | FE_DIVBYZERO);
    if(flagp != 0)
    {   feclearexcept(FE_OVERFLOW | FE_DIVBYZERO);
        return (0);
    }
    return (1);
}

int _(uxacos)(double *r, double *x)
{   *r = acos( *x );
    fegetexceptflag(&flagp, FE_OVERFLOW | FE_DIVBYZERO);
    if(flagp != 0)
    {   feclearexcept(FE_OVERFLOW | FE_DIVBYZERO);
        return (0);
    }
    return (1);
}

int _(uxatan)(double *r, double *x)
{   *r = atan( *x );
    fegetexceptflag(&flagp, FE_OVERFLOW | FE_DIVBYZERO);
    if(flagp != 0)
    {   feclearexcept(FE_OVERFLOW | FE_DIVBYZERO);
        return (0);
    }
    return (1);
}

int _(uxsqrt)(double *r, double *x)
{   *r = sqrt( *x );
    fegetexceptflag(&flagp, FE_OVERFLOW | FE_DIVBYZERO);
    if(flagp != 0)
    {   feclearexcept(FE_OVERFLOW | FE_DIVBYZERO);
        return (0);
    }
    return (1);
}

int _(uxexp)(double *r, double *x)
{   *r = exp( *x );
    fegetexceptflag(&flagp, FE_OVERFLOW | FE_DIVBYZERO);
    if(flagp != 0)
    {   feclearexcept(FE_OVERFLOW | FE_DIVBYZERO);
        return (0);
    }
    return (1);
}

int _(uxlog)(double *r, double *x)
{   *r = log( *x );
    fegetexceptflag(&flagp, FE_OVERFLOW | FE_DIVBYZERO);
    if(flagp != 0)
    {   feclearexcept(FE_OVERFLOW | FE_DIVBYZERO);
        return (0);
    }
    return (1);
}

#define _pi       ((12868.0 - 0.036490896206895257)/4096.0)
#define _half_pi  ((12868.0 - 0.036490896206895257)/8192.0)

int _(uxatan2)(double *res, double *y, double *x)
{   double u=*x, v=*y, r;
    int q = 0;
    if (u < 0.0) u = -u, q = 1;
    if (v < 0.0) v = -v, q |= 2;
    if (v > u)
    {   r = u;
        u = v;
        v = r;
        q |= 4;
    }
    if (u == 0.0 && v == 0.0) r = 0.0;
    else
    {   r = atan(v/u);
        fegetexceptflag(&flagp, FE_OVERFLOW | FE_DIVBYZERO);
        if(flagp != 0)
        {   feclearexcept(FE_OVERFLOW | FE_DIVBYZERO);
            return (0);
        }
        switch (q)
    {       default:
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
    return (1);
}

/* end of float.c */
