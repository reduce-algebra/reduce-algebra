//  arith10.cpp                       Copyright (C) 1990-2016 Codemist Ltd

//
// Arithmetic functions.
//

/**************************************************************************
 * Copyright (C) 2016, Codemist Ltd.                     A C Norman       *
 *                                                                        *
 * Redistribution and use in source and binary forms, with or without     *
 * modification, are permitted provided that the following conditions are *
 * met:                                                                   *
 *                                                                        *
 *     * Redistributions of source code must retain the relevant          *
 *       copyright notice, this list of conditions and the following      *
 *       disclaimer.                                                      *
 *     * Redistributions in binary form must reproduce the above          *
 *       copyright notice, this list of conditions and the following      *
 *       disclaimer in the documentation and/or other materials provided  *
 *       with the distribution.                                           *
 *                                                                        *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS    *
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT      *
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS      *
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE         *
 * COPYRIGHT OWNERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,   *
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,   *
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS  *
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND *
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR  *
 * TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF     *
 * THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH   *
 * DAMAGE.                                                                *
 *************************************************************************/


// $Id$


#include "headers.h"



/*****************************************************************************/
//**              Transcendental functions etcetera.                       **
/*****************************************************************************/


//
// Much of the code here is extracted from the portable Fortran library
// used by Codemist with its Fortran compiler.
//

//
// I think I should probably now view crlibm as something that will
// ALWAYS be in use...
//

#ifndef HAVE_CRLIBM

#ifdef WIN32

//
// At least as of the end of August 2011 the implementations of sin
// and cos in the C library that comes with i686-w64-mingw32 and
// x86_65-w64-mingw32 compilers do not do range reduction very well,
// and so a calculation "sin(4.0*atan(1.0))" gives a bad result -
// specifically one with a load of trailing zeros in its binary
// representation. The code here does some more careful range reduction
// and so calls the basic version only when it is safer.
//


static double arg_reduce(double a, int *quadrant)
//
// Reduce argument to the range -pi/4 to pi/4, and set quadrant to the
// relevant quadant.
//
{
//
// pi/2 is close to c1 + c2 + c3 and both c1 and c2 should be
// stored with only the top 30 bits in their FP representation non-zero.
// Furthermore the integers used to specify values here are less than
// 2^31 and so any internal working that could have limits at 32-bit
// integers should be safe.
//
    static double c1 = 1686629713.0/1073741824.0;
    static double c2 = 1121027177.0/1073741824.0/1073741824.0/16.0;
    static double c3 = 2.91273205609335616e-20;
    double w = a / 1.5707963267948966;
    int32_t n = (int)(w < 0.0 ? w - 0.5 : w + 0.5);
//
// OK - now n should be the nearest integer to a/(pi/2) so
// (a - n) should be at most (about) pi/4 in absolute value.
//
    w = a - (double)n*c1;
    w = w - (double)n*c2;
    w = w - (double)n*c3;
    *quadrant = (int)(n & 3);
    return w;
}

double my_sin(double x)
{   int quadrant;
    x = arg_reduce(x, &quadrant);
    switch (quadrant)
{       default:
        case 0: return sin(x);
        case 1: return cos(x);
        case 2: return sin(-x);
        case 3: return -cos(x);
    }
}

double my_cos(double x)
{   int quadrant;
    x = arg_reduce(x, &quadrant);
    switch (quadrant)
{       default:
        case 0: return cos(x);
        case 1: return sin(-x);
        case 2: return -cos(x);
        case 3: return sin(x);
    }
}

#else   // WIN32

#define my_sin sin
#define my_cos cos

#endif  // WIN32
#else

#define my_sin sin
#define my_cos cos

#endif // HAVE_CRLIBM

#define CSL_log_2 0.6931471805599453094

static Complex Cdiv_z(Complex, Complex);

//
// Here I should review the C library complex elementary functions
// that are available with newer installations - but I may end up
// preferring to use my own versions to achieve absolute compatibility
// across platforms. However if I have my own code I need to review its
// behaviour on branch cuts and with regards to +0.0 and -0.0.
//

static Complex CSLcpowi(Complex z, int n)
{
//
// Raises w complex number to an integer power by repeated squaring.
//
    if (n == 0)
    {   Complex one;
        one.real = 1.0;
        one.imag = 0.0;
        return one;
    }
    else if (n < 0)
    {   Complex one;
        one.real = 1.0;
        one.imag = 0.0;
        return Cdiv_z(one, CSLcpowi(z, -n));
    }
    else if (n == 1) return z;
    else
    {   Complex r = CSLcpowi(z, n/2);
        double x1 = r.real, y1 = r.imag;
        double x2, y2;
        if (n & 1)
        {   double x = z.real, y = z.imag;
            x2 = x*x1 - y*y1;
            y2 = x*y1 + y*x1;
        }
        else
        {   x2 = x1;
            y2 = y1;
        }
//
// This computes r = z^(n/2) and then evaluates either
//          r*r
//  or      (r*z)*r
// where the the calculation or (r*z) will not overflow unless the
// final result is going to.  Note that if the sum had been done as
//          (r*r)*z
// then in some cases r*r might have overflowed even though r*r*z would
// not (e.g. r*r giving a just-out-of-range real value, and having
// magnitude between 1 and sqrt(2), and argument pi/4).
// Although it is SHODDY, for at least the present I will not bother
// about overflow in during the process of the final complex
// multiplication.  After all I suspect ALL complex multiplications
// generated by the compiler will have the same limitation.
//
        z.real = x1*x2 - y1*y2;
        z.imag = x1*y2 + y1*x2;
        return z;
    }
}

static Complex CSLcsin(Complex z)
{   double x = z.real, y = z.imag;
//
// sin(x + iy) = sin(x)*cosh(y) + i cos(x)*sinh(y)
// For smallish y this can be used directly.  For |y| > 50 I will
// compute sinh and cosh as just +/- exp(|y|)/2
//
    double s = my_sin(x), c = my_cos(x);
    double absy = fabs(y);
    if (absy <= 50.0)
    {   double sh = sinh(y), ch = cosh(y);
        z.real = s * ch;
        z.imag = c * sh;
        return z;
    }
    else
    {   double w;
        int n = _reduced_exp(absy, &w) - 1;
        z.real = ldexp(s*w, n);
        if (y < 0.0) z.imag = ldexp(-c*w, n);
        else z.imag = ldexp(c*w, n);
        return z;
    }
}


#define CSL_sqrt_starter 0.7071
#define CSL_sqrt_iters   6

static Complex CSLcsqrt(Complex z)
{   double x = z.real, y = z.imag;
//
// I believe that IEEE expect sqrt(-0.0 + 0.0*i) to be -0.0 + 0.0*i
//
    int j, n;
    double scale;
    double vx, vy;
    if (y == 0.0)
    {   if (x < 0.0)
        {   z.real = 0.0;
            z.imag = sqrt(-x);
        }
        else
        {   z.real = sqrt(x);
            z.imag = 0.0;
        }
        return z;           // Pure real arguments are easy
    }
    (void)frexp(y, &n);
// Exact value returned by frexp not critical
    if (x != 0.0)
    {   int n1;
        (void)frexp(x, &n1);
        if (n1 > n) n = n1;
    }
    n &= ~1;                // ensure it is even
    scale = ldexp(1.0, n);
    x = x / scale;
    y = y / scale; // Now max(|x|, |y|) is in [0.5, 1)
//
// Generate some kind of starting approximation for a NR iteration.
// The value selected here here will give a relative error of 1.6e-5
// after 4 iterations, and so would give about 6.0e-20 after 6, which
// is more accurate (just) than the machines that I use can cope with.
// Note that for z near the real axis the starting approximation is
// either real or (pure) imaginary, thus helping ensure that the near-
// zero component of the answer comes out to decent accuracy.
//
    if (y < x)
    {   if (x > -y) vx = CSL_sqrt_starter, vy = 0.0;
        else vx = CSL_sqrt_starter, vy = -CSL_sqrt_starter;
    }
    else if (x > -y) vx = CSL_sqrt_starter, vy = CSL_sqrt_starter;
    else if (y > 0.0) vx = 0.0, vy = CSL_sqrt_starter;
    else vx = 0.0, vy = -CSL_sqrt_starter;
//
// For starting values as preconditioned here 6 iterations will converge
// to about adequate accuracy. For some arguments fewer iterations would
// suffice, but I am taking the view that the cost of providing a more
// elaborate end-test might well exceed the cost of the extra iterations
// that this code performs.  Experiment shows that the worst relative
// error after 4 iterations is 1.3e-5, so after 6 it will be about
// 3.0e-20, which is better than machine accuracy.  5 iterations would
// not be enough. I could perhaps use a look-up table to obtain a starting
// approximation that would save me a couple of iterations?
//
    for (j=0; j<CSL_sqrt_iters; j++)
    {   double t = vx*vx + vy*vy;
        double qx = (x*vx + y*vy)/t,
               qy = (y*vx - x*vy)/t;
        vx = (vx + qx)*0.5;
        vy = (vy + qy)*0.5;
    }
    n = n/2;
    z.real = ldexp(vx, n);
    z.imag = ldexp(vy, n);
    return z;
}

#undef CSL_sqrt_starter
#undef CSL_sqrt_iters


static Complex CSLctan(Complex z)
{   double x = z.real, y = z.imag;
//
// tan(x + iy) = (tan(x) + i tanh(y))/(1 - i tan(x)*tanh(y))
//
    double t = tan(x), th = tanh(y);
    double t2 = t*t, th2 = th*th;
    // many risks of premature overflow here
    double d = 1.0 + t2*th2;
    z.real = t*(1.0-th2)/d;  // /* if th2 is very near 1.0 this is inaccurate
    z.imag = th*(1.0+t2)/d;
    return z;
}

static Complex Cdiv_z(Complex p, Complex q)
{
//
// (p/q) as a complex number.  Note abominable issues about scaling so
// the large values of p and q can be handled properly.
// The easy scheme for (a + ib)/(c + id) would have been
//         (ac+bd)/w + i(bc - ad)/w            with w = cc + dd
//
    double a = p.real, b = p.imag;
    double c = q.real, d = q.imag;
    Complex r;
    if (d == 0.0)      // dividing by a real number
    {   r.real = a/c;
        r.imag = b/c;
        return r;
    }
    else if (c == 0.0) // dividing by a purely imaginary number
    {   r.real = b/d;
        r.imag = -a/d;
        return r;
    }
    else
    {   double scalep, scaleq, w;
        int n1, n2, n;
//
// I avoid going frexp(0.0, &n1) since the exponent handed back in that
// case is zero, which is not actually very helpful here, where I would
// rather it was minus infinity.
//
        if (a == 0.0)
        {   if (b == 0.0) return p;         // (0.0, 0.0)/z
// Exact results from frexp unimportant
            else (void)frexp(b, &n1);
        }
        else if (b == 0.0) (void)frexp(a, &n1);
        else
        {   (void)frexp(a, &n1);
            (void)frexp(b, &n2);
            if (n2>n1) n1 = n2;
        }
        n = n1;
        scalep = ldexp(1.0, n1);        // scale numerator
        a = a / scalep;
        b = b / scalep;
// At this stage I know that the denominator has nonzero real & imag parts
        (void)frexp(c, &n1);
        (void)frexp(d, &n2);
        if (n2>n1) n1 = n2;
        n = n - n1;
        scaleq = ldexp(1.0, n1);        // scale denominator
        c = c / scaleq;
        d = d / scaleq;
        w = c*c + d*d;  // no overflow
        r.real = ldexp((a*c + b*d)/w, n);   // rescale final result
        r.imag = ldexp((b*c - a*d)/w, n);
        return r;
    }
}


static LispObject make_complex_float(Complex v, LispObject a)
//
// Here a complex result has been been computed (with double precision values
// for both real and imag parts).  Squash to the required floating point
// types and package up as a complex value, where (a) was the original input
// value and so should defined the type needed.  Note that both
// components of a will have the same type so only one needs testing.
// I do the 'onevalue' here.
//
{   int32_t type;
    LispObject a1, a2, nil;
    a = real_part(a);
#ifdef SHORT_FLOAT
    if (is_sfloat(a))
    {   Float_union r, i;
        r.f = (float)v.real;
        i.f = (float)v.imag;
        a1 = make_complex((r.i & ~(int32_t)0xf) + TAG_SFLOAT,
                          (i.i & ~(int32_t)0xf) + TAG_SFLOAT);
        errexit();
        return onevalue(a1);
    }
#endif
    if (is_bfloat(a)) type = type_of_header(flthdr(a));
    else type = TYPE_SINGLE_FLOAT;
// There are MANY uses of make_boxfloat here. In pretty well all cases I let
// make_boxfloat do any overflow checks, and I do not support 128-bit floats.
    a1 = make_boxfloat(v.real, type);
    errexit();
    a2 = make_boxfloat(v.imag, type);
    errexit();
    a1 = make_complex(a1, a2);
    errexit();
    return onevalue(a1);
}

static double rln(double x)
{   if (!(x == x)) return x;   // Ie a NaN
    else if (x < 0.0) x = -x;
    return log(x);
}

static double iln(double x)
{   if (!(x == x)) return x;   // Ie a NaN
    else if (x < 0.0) return _pi;
    else return 0.0;
}

static double rsqrt(double x)
{   if (!(x == x)) return x;   // Ie a NaN
    else if (x < 0.0) return 0.0;
    else return sqrt(x);
}

static double isqrt(double x)
{   if (!(x == x)) return x;   // Ie a NaN
    if (x < 0.0) return sqrt(-x);
    else return 0.0;
}

static double rasin(double x)
{   if (1.0 < x) return _half_pi;
    else if (x <= -1.0) return -_half_pi;
    else return asin(x);
}


static double iasin(double x)
{   bool sign;
    if (-1.0 <= x && x <= 1.0) return 0.0;
    else if (x < 0.0) x = -x, sign = true;
    else sign = false;
    if (x < 2.0)
    {   x += sqrt(x*x - 1.0);
        x = log(x);             // /* serious inaccuracy here
    }
    else if (x < 1.0e9)
    {   x += sqrt(x*x - 1.0);
        x = log(x);
    }
    else x = CSL_log_2 + log(x);
    if (sign) return -x;
    else return x;
}

static double racos(double x)
{   if (x <= -1.0) return _pi;
    else if (1.0 <= x) return 0.0;
    else return acos(x);
}

static double iacos(double x)
{   bool sign;
    if (x < -1.0) x = -x, sign = true;
    else if (1.0 < x) sign = false;
    else return 0.0;
    if (x < 2.0)
    {   x += sqrt(x*x - 1.0);
        x = log(x);             // /* serious inaccuracy here
    }
    else if (x < 1.0e9)
    {   x += sqrt(x*x - 1.0);
        x = log(x);
    }
    else x = CSL_log_2 + log(x);
    if (sign) return x;
    else return -x;
}

static double CSLasinh(double x)
{   bool sign;
    if (x < 0.0) x = -x, sign = true;
    else sign = false;
    if (x < 1.0e-3)
    {   double xx = x*x;
        x = x*(1 - xx*((1.0/6.0) - (3.0/40.0)*xx));
    }
    else if (x < 1.0e9)
    {   x += sqrt(1.0 + x*x);
        x = log(x);
    }
    else x = log(x) + CSL_log_2;
    if (sign) x = -x;
    return x;
}

static double acosh_coeffs[] =
{   -0.15718655513711019382e-5,          // x^11
    +0.81758779765416234142e-5,          // x^10
    -0.24812280287135584149e-4,          // x^9
    +0.62919005027033514743e-4,          // x^8
    -0.15404104307204835991e-3,          // x^7
    +0.38339903706706128921e-3,          // x^6
    -0.98871347029548821795e-3,          // x^5
    +0.26854094489454297811e-2,          // x^4
    -0.78918167367399344521e-2,          // x^3
    +0.26516504294146930609e-1,          // x^2
    -0.11785113019775570984,             // x
    +1.41421356237309504786              // 1

};

static double racosh(double x)
{   bool sign;
    if (x < -1.0) x = -x, sign = true;
    else if (1.0 < x) sign = false;
    else return 0.0;
    if (x < 1.5)
    {   int i;
        double r = acosh_coeffs[0];
        x = (x - 0.5) - 0.5;
//
// This is a minimax approximation to acosh(1+x)/sqrt(x) over the
// range x=0 to 0.5
//
        for (i=1; i<=11; i++) r = x*r + acosh_coeffs[i];
        x = sqrt(x)*r;
    }
    else if (x < 1.0e9)
    {   x += sqrt((x - 1.0)*(x + 1.0));
        x = log(x);
    }
    else x = log(x) + CSL_log_2;
    if (sign) return -x;
    else return x;
}

static double iacosh(double x)
{   if (1.0 <= x) return 0.0;
    else if (x <= -1.0) return _pi;
    else return acos(x);
}

static double ratanh(double z)
{   if (z > -0.01 && z < -0.01)
    {   double zz = z*z;
        return z * (1 + zz*((1.0/3.0) + zz*((1.0/5.0) + zz*(1.0/7.0))));
    }
    z = (1.0 + z) / (1.0 - z);
    if (z < 0.0) z = -z;
    return log(z) / 2.0;
}

static double iatanh(double x)
{   if (x < -1.0) return _half_pi;
    else if (1.0 < x) return -_half_pi;
    else return 0.0;
}

//
// The functions from here on (for a bit) represent re-work to support the
// full set of elementary functions that Reduce would (maybe) like. They
// have not been adjusted to allow use with the software floating point
// option.
//

#define n180pi 57.2957795130823208768   // 180/pi

#define pi180  0.017453292519943295769  // pi/180

#define sqrthalf 0.7071                 // sqrt(0.5), low accuracy OK

static double racosd(double a)
{   if (a <= -1.0) return 180.0;
    else if (a < -sqrthalf) return 180.0 - n180pi*acos(-a);
    else if (a < 0.0) return 90.0 + n180pi*asin(-a);
    else if (a < sqrthalf) return 90.0 - n180pi*asin(a);
    else if (a < 1.0) return n180pi*acos(a);
    else return 0.0;
}

static double iacosd(double a)
//
// This version is only good enough for real-mode CSL, not for CCL
//
{   if (a >= -1.0 && a <= 1.0) return 0.0;
    else return 1.0;
}

static double racot(double a)
{   if (a >= 0.0)
        if (a > 1.0) return atan(1.0/a);
        else return _half_pi - atan(a);
    else if (a < -1.0) return _pi - atan(-1.0/a);
    else return _half_pi + atan(-a);
}

static double racotd(double a)
{   if (a >= 0.0)
        if (a > 1.0) return n180pi*atan(1.0/a);
        else return 90.0 - n180pi*atan(a);
    else if (a < -1.0) return 180.0 - n180pi*atan(-1.0/a);
    else return 90.0 + n180pi*atan(-a);
}

static double racoth(double a)
//
// No good in complex case
//
{   if (a >= -1.0 && a <= 1.0) return 0.0;
    else return ratanh(1.0/a);
}

static double iacoth(double a)
{   if (a >= -1.0 && a <= 1.0) return 1.0;
    else return 0.0;
}

static double racsc(double a)
{   if (a > -1.0 && a < 1.0) return 0.0;
    else return asin(1.0/a);
}

static double iacsc(double a)
{   if (a > -1.0 && a < 1.0) return 1.0;
    else return 0.0;
}

static double racscd(double a)
{   if (a > -1.0 && a < 1.0) return 0.0;
//
// I could do better than this, I suspect...
//
    else return n180pi*asin(1.0/a);
}

static double iacscd(double a)
{   if (a > -1.0 && a < 1.0) return 1.0;
    else return 0.0;
}

static double racsch(double a)
{   if (a == 0.0) return HUGE_VAL;
    else return CSLasinh(1.0/a);
}

static double rasec(double a)
{   if (a > -1.0 && a <= 1.0) return 0.0;
    else return acos(1.0/a);
}

static double iasec(double a)
{   if (a > -1.0 && a < 1.0) return 1.0;
    else return 0.0;
}

static double rasecd(double a)
{   if (a > -1.0 && a <= 1.0) return 0.0;
//
// I could do better than this, I suspect...
//
    else return n180pi*acos(1.0/a);
}

static double iasecd(double a)
{   if (a > -1.0 && a < 1.0) return 1.0;
    else return 0.0;
}

static double rasech(double a)
{   if (a <= 0.0 || a >= 1.0) return 0.0;
    else return racosh(1.0/a);
}

static double iasech(double a)
{   if (a <= 0.0 || a > 1.0) return 1.0;
    else return 0.0;
}

static double rasind(double a)
{   if (a <= -1.0) return -90.0;
    else if (a < -sqrthalf) return -90.0 + n180pi*acos(-a);
    else if (a < sqrthalf) return n180pi*asin(a);
    else if (a < 1.0) return 90.0 - n180pi*acos(a);
    else return 90.0;
}

static double iasind(double a)
{   if (a >= -1.0 && a <= 1.0) return 0.0;
    else return 1.0;
}

static double ratand(double a)
{   if (a < -1.0) return -90.0 + n180pi*atan(-1.0/a);
    else if (a < 1.0) return n180pi*atan(a);
    else return 90.0 - n180pi*atan(1.0/a);
}

static double rcbrt(double a)
{   int xx, x, i, neg = 0;
    double b;
    if (a == 0.0) return 0.0;
    else if (a < 0.0) a = -a, neg = 1;
    b = frexp(a, &xx);  // end-conditions unimportant
    x = xx;
//
// b is now in the range 0.5 to 1.  The next line produces an
// approximately minimax linear approximation to the cube root
//% function over the range concerned.
//
    b = 0.5996 + 0.4081*b;
    while (x % 3 != 0) x--; b *= 1.26;
    b = ldexp(b, x/3);
//
// Experiment shows that there are values of the input variable
// that lead to the last of the following iterations making a
// (small) change to the result, but almost all of the time I
// could get away with one less.  Still, I do not consider cbrt
// important enough to optimise any further (e.g. I could go to
// use of a minimax rational first approximation...)
//
    for (i=0; i<6; i++)
        b = (2.0*b + a/(b*b))/3.0;
    if (neg) return -b;
    else return b;
}

static double rcot(double a)
//
// Compare this code with rcotd(). Here I just compute a tangent and
// form its reciprocal.  What about an arg of pi/2 then, where the
// tangent calculation might overflow?  Well it should not, since no
// integer multiple of pi/2 has an exact machine representation, so
// if you try to compute tan(pi/2) in floating point you should get a
// large but finite value.  For very large a where the tan() function
// loses resolution there could still be trouble, which is why I use
// a slower formula for big a.
//
{   if (a > 1000.0 || a < -1000.0) return my_cos(a)/my_sin(a);
    else return 1.0/tan(a);
}

static double arg_reduce_degrees(double a, int *quadrant)
//
// Reduce argument to the range -45 to 45, and set quadrant to the
// relevant quadant.  Returns arg converted to radians.
//
{   double w = a / 90.0;
    int32_t n = (int)w;
    w = a - 90.0*n;
    while (w < -45.0)
    {   n--;
        w = a - 90.0*n;
    }
    while (w >= 45.0)
    {   n++;
        w = a - 90.0*n;
    }
    *quadrant = (int)(n & 3);
    return pi180*w;
}

static double rsind(double a)
{   int quadrant;
    a = arg_reduce_degrees(a, &quadrant);
    switch (quadrant)
{       default:
        case 0: return sin(a);
        case 1: return cos(a);
        case 2: return sin(-a);
        case 3: return -cos(a);
    }
}

static double rcosd(double a)
{   int quadrant;
    a = arg_reduce_degrees(a, &quadrant);
    switch (quadrant)
{       default:
        case 0: return cos(a);
        case 1: return sin(-a);
        case 2: return -cos(a);
        case 3: return sin(a);
    }
}

static double rtand(double a)
{   int quadrant;
    a = arg_reduce_degrees(a, &quadrant);
    switch (quadrant)
{       default:
        case 0:
        case 2: return tan(a);
        case 1:
        case 3: return 1.0/tan(-a);
    }
}

static double rcotd(double a)
{   int quadrant;
    a = arg_reduce_degrees(a, &quadrant);
    switch (quadrant)
{       default:
        case 0:
        case 2: return 1.0/tan(a);
        case 1:
        case 3: return tan(-a);
    }
}


static double rcoth(double a)
{   if (a == 0.0) return HUGE_VAL;
    else return 1.0/tanh(a);
}

static double rcsc(double a)
{   a = my_sin(a);
    if (a == 0.0) return HUGE_VAL;
    else return 1.0/a;
}

static double rcscd(double a)
{   a = rsind(a);
    if (a == 0.0) return HUGE_VAL;
    else return 1.0/a;
}

static double rcsch(double a)
{
//
// This code is imperfect in that (at least!) exp(-a) can underflow to zero
// before 2*exp(-a) ought to have.  I will not worry about such refinement
// here. Much.
//
    if (a == 0.0) return HUGE_VAL;
    else if (a > 20.0) return 2.0*exp(-a);
    else if (a < -20.0) return -2.0*exp(a);
    else return 1.0/sinh(a);
}

#define CSL_log10 2.302585092994045684

static double rlog10(double a)
{   if (a > 0.0) return log(a)/CSL_log10;
    else return 0.0;
}

static double ilog10(double a)
{   if (a <= 0) return 1.0;
    else return 0.0;
}

#define CSL_log2 0.693147180559945309417

static double rlog2(double a)
{   if (a > 0.0)
    {   int x;
        a = frexp(a, &x);
        return log(a)/CSL_log2 + (double)x;
    }
    else return 0.0;
}

static double ilog2(double a)
{   if (a <= 0) return 1.0;
    else return 0.0;
}

static double rsec(double a)
{   a = my_cos(a);
    if (a == 0.0) return HUGE_VAL;
    else return 1.0/a;
}

static double rsecd(double a)
{   a = rcosd(a);
    if (a == 0.0) return HUGE_VAL;
    else return 1.0/a;
}

static double rsech(double a)
{
//
// When |a| is big I ought to return 0.0
//
    return 1.0/cosh(a);
}

#define i_times(z) \
    { double temp = z.imag; z.imag = z.real; z.real = -temp; }

#define m_i_times(z) \
    { double temp = z.imag; z.imag = -z.real; z.real = temp; }


//
// The calculations in the next few procedures are numerically
// crummy, but they should get branch cuts correct.  Re-work later.
//

static Complex CSLcasinh(Complex z)
// log(z + sqrt(1 + z^2))
{   int quadrant = 0;
    Complex w;
    if (z.real < 0.0)
    {   z.real = -z.real;
        z.imag = -z.imag;
        quadrant = 1;
    }
    if (z.imag < 0.0)
    {   z.imag = -z.imag;
        quadrant |= 2;
    }
// /* The next line can overflow or lose precision
    w.real = z.real*z.real - z.imag*z.imag + 1.0;
    w.imag = 2*z.real*z.imag;
    w = CSLcsqrt(w);
    w.real += z.real;
    w.imag += z.imag;
    w = Cln(w);
    if (quadrant & 2) w.imag = -w.imag;
    if (quadrant & 1) w.real = -w.real, w.imag = -w.imag;
    return w;
}

static Complex CSLcacosh(Complex z)
// 2*log(sqrt((z+1)/2) + sqrt((z-1)/2))
{   Complex w1, w2;
    w1.real = (z.real + 1.0)/2.0;
    w2.real = (z.real - 1.0)/2.0;
    w1.imag = w2.imag = z.imag/2.0;
    w1 = CSLcsqrt(w1);
    w2 = CSLcsqrt(w2);
    w1.real += w2.real;
    w1.imag += w2.imag;
    z = Cln(w1);
    z.real *= 2.0;
    z.imag *= 2.0;
    return z;
}

static Complex CSLcatanh(Complex z)
// (log(1+z) - log(1-z))/2
{   Complex w1, w2;
    w1.real = 1.0 + z.real;
    w2.real = 1.0 - z.real;
    w1.imag = z.imag;
    w2.imag = -z.imag;
    w1 = Cln(w1);
    w2 = Cln(w2);
    w1.real -= w2.real;
    w1.imag -= w2.imag;
    w1.real /= 2.0;
    w1.imag /= 2.0;
    return w1;
}

static Complex CSLcasin(Complex z)
{   i_times(z);
    z = CSLcasinh(z);
    m_i_times(z);
    return z;
}

static Complex CSLcacos(Complex z)
{
//
// The following is asserted to behave better. I believe that the
// calculation (pi/2 - z.real) is guaranteed to introduce severe error
// when the answer is close to zero, and so this is probably not the ultimate
// proper formula to use.
//
    z = CSLcasin(z);
    z.real = _half_pi - z.real;
    z.imag = - z.imag;
    return z;

}

static Complex CSLcatan(Complex z)
{   i_times(z);
    z = CSLcatanh(z);
    m_i_times(z);
    return z;
}

static Complex CSLcsinh(Complex z)
{   i_times(z);
    z = CSLcsin(z);
    m_i_times(z);
    return z;
}

static Complex CSLccosh(Complex z)
{   i_times(z);
    return Ccos(z);
}

static Complex CSLctanh(Complex z)
{   i_times(z);
    z = CSLctan(z);
    m_i_times(z);
    return z;
}

//
// The next collection of things have not been implemented yet,
// but might be wanted in a full extended system.... maybe.
//

static Complex CSLcacosd(Complex a)
{   return a;
}


static Complex CSLcacot(Complex a)
{   return a;
}


static Complex CSLcacotd(Complex a)
{   return a;
}


static Complex CSLcacoth(Complex a)
{   return a;
}


static Complex CSLcacsc(Complex a)
{   return a;
}


static Complex CSLcacscd(Complex a)
{   return a;
}


static Complex CSLcacsch(Complex a)
{   return a;
}


static Complex CSLcasec(Complex a)
{   return a;
}


static Complex CSLcasecd(Complex a)
{   return a;
}


static Complex CSLcasech(Complex a)
{   return a;
}


static Complex CSLcasind(Complex a)
{   return a;
}


static Complex CSLcatand(Complex a)
{   return a;
}


static Complex ccbrt(Complex a)
{   return a;
}


static Complex CSLccosd(Complex a)
{   return a;
}


static Complex CSLccot(Complex a)
{   return a;
}


static Complex CSLccotd(Complex a)
{   return a;
}


static Complex CSLccoth(Complex a)
{   return a;
}


static Complex CSLccsc(Complex a)
{   return a;
}


static Complex CSLccscd(Complex a)
{   return a;
}


static Complex CSLccsch(Complex a)
{   return a;
}


static Complex CSLclog10(Complex a)
{   return a;
}


static Complex CSLclog2(Complex a)
{   return a;
}


static Complex CSLcsec(Complex a)
{   return a;
}


static Complex CSLcsecd(Complex a)
{   return a;
}


static Complex CSLcsech(Complex a)
{   return a;
}


static Complex CSLcsind(Complex a)
{   return a;
}


static Complex CSLctand(Complex a)
{   return a;
}

//
// Now the Lisp callable entrypoints for the above
//

typedef double real_arg_fn(double);
typedef Complex complex_arg_fn(Complex);

//
// Each trig function has three associated helpers.
// the first two are used for real arguments, and return the real and
// imaginary parts of the answer. If the function is always real for
// real input then the second function is gicen as NULL.
// The final case is for genuine complex arguments.
//

typedef struct trigfn
{   double (*real)(double);
    double (*imag)(double);
    Complex (*complex)(Complex);
} trigfn_record;

static trigfn_record const trig_functions[] =
{   {racos,  iacos,  CSLcacos},  // acos   0  inverse cos, rads, [0, pi)
    {racosd, iacosd, CSLcacosd}, // acosd  1  inverse cos, degs, [0, 180)
    {racosh, iacosh, CSLcacosh}, // acosh  2  inverse hyperbolic cosine
    {racot,  NULL,   CSLcacot},  // acot   3  inverse cot, rads, (0, pi)
    {racotd, NULL,   CSLcacotd}, // acotd  4  inverse cot, degs, (0, 180)
    {racoth, iacoth, CSLcacoth}, // acoth  5  inverse hyperbolic cotangent
    {racsc,  iacsc,  CSLcacsc},  // acsc   6  inverse cosec, [-pi/2, pi/2]
    {racscd, iacscd, CSLcacscd}, // acscd  7  inverse cosec, degs, [-90, 90]
    {racsch, NULL,   CSLcacsch}, // acsch  8  inverse hyperbolic coseCSLcant
    {rasec,  iasec,  CSLcasec},  // asec   9  inverse sec, rads, [0, pi)
    {rasecd, iasecd, CSLcasecd}, // asecd  10 inverse sec, degs, [0, 180)
    {rasech, iasech, CSLcasech}, // asech  11 inverse hyperbolic seCSLcant
    {rasin,  iasin,  CSLcasin},  // asin   12 inverse sin, rads, [-pi/2, pi/2]
    {rasind, iasind, CSLcasind}, // asind  13 inverse sin, degs, [-90, 90]
    {CSLasinh, NULL, CSLcasinh}, // asinh  14 inverse hyperbolic sin
    {atan,   NULL,   CSLcatan},  // atan   15 1-arg inverse tan, (-pi/2, pi/2)
    {ratand, NULL,   CSLcatand}, // atand  16 inverse tan, degs, (-90, 90)
    {NULL,   NULL,   NULL},   // atan2  17 2-arg inverse tan, [0, 2pi)
    {NULL,   NULL,   NULL},   // atan2d 18 2-arg inverse tan, degs, [0, 360)
    {ratanh, iatanh, CSLcatanh}, // atanh  19 inverse hyperbolic tan
    {rcbrt,  NULL,   ccbrt},  // cbrt   20 cube root
    {my_cos, NULL,   Ccos},   // cos    21 cosine, rads
    {rcosd,  NULL,   CSLccosd},  // cosd   22 cosine, degs
    {cosh,   NULL,   CSLccosh},  // cosh   23 hyperbolic cosine
    {rcot,   NULL,   CSLccot},   // cot    24 cotangent, rads
    {rcotd,  NULL,   CSLccotd},  // cotd   25 cotangent, degs
    {rcoth,  NULL,   CSLccoth},  // coth   26 hyperbolic cotangent
    {rcsc,   NULL,   CSLccsc},   // csc    27 cosecant, rads
    {rcscd,  NULL,   CSLccscd},  // cscd   28 cosecant, degs
    {rcsch,  NULL,   CSLccsch},  // csch   29 hyperbolic cosecant
    {exp,    NULL,   Cexp},   // exp    30 exp(x) = e^z, e approx 2.71828
    {NULL,   NULL,   NULL},   // expt   31 expt(a,b) = a^b
    {NULL,   NULL,   NULL},   // hypot  32 hypot(a,b) = sqrt(a^2+b^2)
    {rln,    iln,    Cln},    // ln     33 log base e, e approx 2.71828
    {NULL,   NULL,   NULL},   // log    34 2-arg log
    {rlog10, ilog10, CSLclog10}, // log10  35 log to base 10
    {rsec,   NULL,   CSLcsec},   // sec    36 secant, rads
    {rsecd,  NULL,   CSLcsecd},  // secd   37 secant, degs
    {rsech,  NULL,   CSLcsech},  // sech   38 hyperbolic secant
    {my_sin, NULL,   CSLcsin},   // sin    39 sine, rads
    {rsind,  NULL,   CSLcsind},  // sind   40 sine, degs
    {sinh,   NULL,   CSLcsinh},  // sinh   41 hyperbolic sine
    {rsqrt,  isqrt,  CSLcsqrt},  // sqrt   42 square root
    {tan,    NULL,   CSLctan},   // tan    43 tangent, rads
    {rtand,  NULL,   CSLctand},  // tand   44 tangent, degs
    {tanh,   NULL,   CSLctanh},  // tanh   45 hyperbolic tangent
    {rlog2,  ilog2,  CSLclog2}   // log2   46 log to base 2
};

static LispObject Ltrigfn(unsigned int which_one, LispObject a)
//
// This one piece of code does the type-dispatch for the main collection
// of elementary functions.
//
{   double d;
    LispObject nil = C_nil;
#ifndef COMMON
    int32_t restype = TYPE_DOUBLE_FLOAT;
#else
//
// single floats seem to me to be a bad idea!
//
    int32_t restype = TYPE_SINGLE_FLOAT;
#endif
    if (which_one > 46) return aerror("trigfn internal error");
    switch ((int)a & TAG_BITS)
    {   case TAG_FIXNUM:
            d = (double)int_of_fixnum(a);
            break;
#ifdef SHORT_FLOAT
        case TAG_SFLOAT:
        {   Float_union aa;
            aa.i = a - TAG_SFLOAT;
            d = (double)aa.f;
            restype = 0;
            break;
        }
#endif
        case TAG_NUMBERS:
        {   int32_t ha = type_of_header(numhdr(a));
            switch (ha)
            {   case TYPE_BIGNUM:
                case TYPE_RATNUM:
                    d = float_of_number(a);
                    break;
                case TYPE_COMPLEX_NUM:
                {   Complex c1, c2;
                    c1.real = float_of_number(real_part(a));
                    c1.imag = float_of_number(imag_part(a));
                    c2 = (*trig_functions[which_one].complex)(c1);
// make_complex_float does the onevalue() for me
                    return make_complex_float(c2, a);
                }
                default:
                    return aerror1("bad arg for trig function",  a);
            }
            break;
        }
        case TAG_BOXFLOAT:
            restype = type_of_header(flthdr(a));
            d = float_of_number(a);
            break;
        default:
            return aerror1("bad arg for trig function",  a);
    }
    {       double (*im)(double) = trig_functions[which_one].imag;
        if (im == NULL)
//
// If there is no function for giving the complex part of a result
// from a real argument then at this point I have a real input and
// so I just deal with it simply.
//
// I really suspect I should do something writh errno here to
// keep track of when things go wrong.  Doing so feels fairly
// messy, but it is necessary if I am to raise exceptions for
// Lisp if an elementary function leads to overflow.
//
        {   double (*rl)(double) = trig_functions[which_one].real;
            if (rl == NULL) return aerror("unimplemented trig function");
            d = (*rl)(d);
            if (trap_floating_overflow &&
                floating_edge_case(d))
            {   floating_clear_flags();
                return aerror("error in floating point elementary function");
            }
            a = make_boxfloat(d, restype);
            errexit();
            return onevalue(a);
        }
        else
        {   double c1r, c1i;
            LispObject nil;
            LispObject rp, ip;
            double (*rl)(double) = trig_functions[which_one].real;
            if (rl == 0) return aerror("unimplemented trig function");
            c1r = (*rl)(d);
            c1i = (*im)(d);
            if (trap_floating_overflow &&
                (floating_edge_case(c1r) ||
                 floating_edge_case(c1i)))
            {   floating_clear_flags();
                return aerror("error in floating point elementary function");
            }
            a = make_boxfloat(d, restype);
//
// if the imaginary part of the value is zero then I will return a real
// answer - this is correct since the original argument was real, but
// it has to be done by hand here because normally complex values with
// zero imaginary part remain complex.
//
            if (c1i == 0.0)
            {   a = make_boxfloat(c1r, restype);
                errexit();
                return onevalue(a);
            }
#ifndef COMMON
// For now at least I will keep raising an error in cases where the
// result would not be real
//
            return aerror("Elementary function argument out of range");
#endif
            rp = make_boxfloat(c1r, restype);
            errexit();
            ip = make_boxfloat(c1i, restype);
            errexit();
            a = make_complex(rp, ip);
            errexit();
            return onevalue(a);
        }
    }
}

static LispObject makenum(LispObject a, int32_t n)
//
// Make the value n, but type-consistent with the object a.  Usually
// used with n=0 or n=1
//
{
#ifndef COMMON
    int32_t restype = TYPE_DOUBLE_FLOAT;
#else
    int32_t restype = TYPE_SINGLE_FLOAT;
#endif
    LispObject nil = C_nil;
    switch ((int)a & TAG_BITS)
    {   case TAG_FIXNUM:
            return fixnum_of_int(n);
#ifdef SHORT_FLOAT
        case TAG_SFLOAT:
        {   Float_union aa;
            aa.f = (float)n;
            return (aa.i & ~(int32_t)0xf) + TAG_SFLOAT;
        }
#endif
        case TAG_NUMBERS:
        {   int32_t ha = type_of_header(numhdr(a));
            switch (ha)
            {   case TYPE_BIGNUM:
                case TYPE_RATNUM:
                    return fixnum_of_int(n);
                case TYPE_COMPLEX_NUM:
                {   LispObject rr, ii;
                    a = real_part(a);
                    rr = makenum(a, 1);
                    errexit();
                    ii = makenum(a, 0);
                    errexit();
                    a = make_complex(rr, ii);
                    errexit();
                    return onevalue(a);
                }
            }
            return aerror1("bad arg for makenumber",  a);
        }
        case TAG_BOXFLOAT:
            restype = type_of_header(flthdr(a));
            a = make_boxfloat((double)n, restype);
            errexit();
            return onevalue(a);
        default:
            return aerror1("bad arg for makenumber",  a);
    }
}

static LispObject CSLpowi(LispObject a, uint32_t n)
//
// Raise a to the power n by repeated multiplication. The name is CSLpowi
// rather than just powi because some miserable C compilers come with an
// external function called powi in <cmath> and then moan about the
// name clash.
//
{   LispObject nil;
    if (n == 0) return makenum(a, 1); // value 1 of appropriate type
    else if (n == 1) return a;
    else if ((n & 1) == 0)
    {   a = CSLpowi(a, n/2);
        errexit();
        return times2(a, a);
    }
    else
    {   LispObject b;
        push(a);
        b = CSLpowi(a, n/2);
        nil = C_nil;
        if (!exception_pending()) b = times2(b, b);
        pop(a);
        errexit();
        return times2(a, b);
    }
}

static Complex complex_of_number(LispObject a)
{   Complex z;
    if (is_numbers(a) && is_complex(a))
    {   z.real = float_of_number(real_part(a));
        z.imag = float_of_number(imag_part(a));
    }
    else
    {   z.real = float_of_number(a);
        z.imag = 0.0;
    }
    return z;
}

static LispObject Lhypot(LispObject nil, LispObject a, LispObject b)
{   double u, v, r;
    u = float_of_number(a);
    v = float_of_number(b);
    if (u < 0.0) u = -u;
    if (v < 0.0) v = -v;
    if (u > v)
    {   r = u;
        u = v;
        v = r;
    }
    // Now 0.0 < u < v
    if (u + v == v) r = v;  // u is very small compared to v
    else
    {   r = u/v;
//
// A worry I have is that the multiplication on the following line can
// overflow, blowing me out of the water.
//
        r = v * sqrt(1.0 + r*r);
    }
    a = make_boxfloat(r, TYPE_DOUBLE_FLOAT);
    errexit();
    if (trap_floating_overflow &&
        floating_edge_case(a))
    {   floating_clear_flags();
        return aerror("floating point hypotenuse");
    }
    return onevalue(a);
}

LispObject Lexpt(LispObject nil, LispObject a, LispObject b)
{   double d, e;
    int32_t restype, n;
    LispObject w;
    Complex c1, c2, c3;
//
// I take special action on 1, 0 and -1 raised to a power that is an integer
// or a bignum. In part this is because raising 1 to a power may be a fairly
// common case worthy of special care, but the main pressure came because
// these numbers raised to bignum powers can still have fixnum results, and
// the value can be computed fast.
//
    if (a == fixnum_of_int(1) ||
        a == fixnum_of_int(0) ||
        a == fixnum_of_int(-1))
    {   if (is_fixnum(b))
        {   n = int_of_fixnum(b);
            switch (int_of_fixnum(a))
            {   case 1:  return onevalue(a);
                case 0:  if (n < 0) return aerror2("expt", a, b);
                    // In Common Lisp (expt 0 0) is defined to be 0
                    else if (n == 0) return onevalue(fixnum_of_int(1));
                    else return onevalue(a);
                case -1: if (n & 1) return onevalue(a);
                    else return onevalue(fixnum_of_int(1));
            }
        }
        else if (is_numbers(b) && is_bignum(b))
        {   switch (int_of_fixnum(a))
            {   case 1:  return onevalue(a);
                case 0:  n = bignum_digits(b)[(bignum_length(b)-CELL-4)/4];
                    if (n <= 0) return aerror2("expt", a, b);
                    else return onevalue(a);
                case -1: n = bignum_digits(b)[0];
                    if (n & 1) return onevalue(a);
                    else return onevalue(fixnum_of_int(1));
            }
        }
    }
//
// In a similar vein I will take special action on #C(0 1) and #C(0 -1)
// raise to integer (including bignum) powers.
//
    if (is_numbers(a) && is_complex(a) && real_part(a)==fixnum_of_int(0) &&
        (imag_part(a) == fixnum_of_int(1) ||
         imag_part(a) == fixnum_of_int(-1)))
    {   n = -1;
        if (is_fixnum(b)) n = int_of_fixnum(b) & 3;
        else if (is_numbers(b) && is_bignum(b))
            n = bignum_digits(b)[0] & 3;
        switch (n)
        {   case 0:   return onevalue(fixnum_of_int(1));
            case 2:   return onevalue(fixnum_of_int(-1));
            case 1:
            case 3:   if (int_of_fixnum(imag_part(a)) == 1) n ^= 2;
                a = make_complex(fixnum_of_int(0),
                                 fixnum_of_int((n & 2) ? 1 : -1));
                errexit();
                return onevalue(a);
            default:  break;
        }
    }
    if (is_fixnum(b))   // bignum exponents would yield silly values!
    {   n = int_of_fixnum(b);
        if (n < 0)
        {   a = CSLpowi(a, (uint32_t)(-n));
            nil = C_nil;
#ifdef COMMON
            if (!exception_pending()) a = CLquot2(fixnum_of_int(1), a);
#else
            if (!exception_pending()) a = quot2(fixnum_of_int(1), a);
#endif
        }
        else a = CSLpowi(a, (uint32_t)n);
        return onevalue(a);
    }
    if (is_numbers(a) && is_complex(a)) w = real_part(a);
    else w = a;
    if (is_sfloat(w)) restype = 0;
    else if (is_bfloat(w)) restype = type_of_header(flthdr(w));
    else restype = TYPE_SINGLE_FLOAT;
    if (is_numbers(b) && is_complex(b)) w = real_part(b);
    else w = b;
    if (is_bfloat(w))
    {   n = type_of_header(flthdr(w));
        if (restype == 0 || restype == TYPE_SINGLE_FLOAT ||
            (restype == TYPE_DOUBLE_FLOAT && n == TYPE_LONG_FLOAT))
            restype = n;
    }
    else if (restype == 0) restype = TYPE_SINGLE_FLOAT;
// At least for now I do not support long floats here - I demote to double
// floats.
    if (restype == TYPE_LONG_FLOAT) restype = TYPE_DOUBLE_FLOAT;
    if ((is_numbers(a) && is_complex(a)) ||
        (is_numbers(b) && is_complex(b)))
    {   c1 = complex_of_number(a);
        c2 = complex_of_number(b);
        c3 = Cpow(c1, c2);
        a = make_boxfloat(c3.real, restype);
        errexit();
        b = make_boxfloat(c3.imag, restype);
        errexit();
        a = make_complex(a, b);
        errexit();
        return onevalue(a);
    }
    d = float_of_number(a);
    e = float_of_number(b);
    if (d < 0.0)
    {   c1.real = d; c1.imag = 0.0;
        c2.real = e; c2.imag = 0.0;
        c3 = Cpow(c1, c2);
        a = make_boxfloat(c3.real, restype);
        errexit();
        b = make_boxfloat(c3.imag, restype);
        errexit();
        a = make_complex(a, b);
        errexit();
        return onevalue(a);
    }
    d = pow(d, e);
    a = make_boxfloat(d, restype);
    errexit();
    return onevalue(a);
}

LispObject Llog_2(LispObject nil, LispObject a, LispObject b)
//
// Log with specified base.
//
{   push(b);
    a = Ltrigfn(33, a);
    pop(b);
    errexit();
    push(a);
    b = Ltrigfn(33, b);
    pop(a);
    errexit();
    return quot2(a, b);
}

#ifdef ISQRT_IMPLEMENTED_PROPERLY
// This can only be used wgen it is implemented properly!
static LispObject Lisqrt(LispObject, LispObject a)
{   double d;
// This makes some pretence at computing an integer square root, but it
// does so incredibly clumsily by mapping onto a floating point value and
// then expecting the square root computed that way to fir into a fixnum,
// ie to be at worst 27 bits long. That is not at all good enough for
// serious use so I am disabling it for now!
    switch ((int)a & TAG_BITS)
    {   case TAG_FIXNUM:
            d = (double)int_of_fixnum(a);
            break;
        case TAG_NUMBERS:
        {   int32_t ha = type_of_header(numhdr(a));
            switch (ha)
            {   case TYPE_BIGNUM:
                    d = float_of_number(a);
                    break;
                default:
                    return aerror1("bad arg for isqrt",  a);
            }
            break;
        }
        default:
            return aerror1("bad arg for isqrt",  a);
    }
    d = sqrt(d);
// /* This is not anything like good enough yet
    return onevalue(fixnum_of_int((int32_t)d));
}
#endif

LispObject Labsval(LispObject nil, LispObject a)
//
// I call this Labsval not Labs because a non-case-sensitive linker
// would confuse Labs with labs, and labs is defined in the C libraries...
// Of course I do not think that case-insensitive linkers should be allowed
// to remain in service....
//
{   switch ((int)a & TAG_BITS)
    {   case TAG_FIXNUM:
#ifdef SHORT_FLOAT
        case TAG_SFLOAT:
#endif
            break;
        case TAG_NUMBERS:
        {   int32_t ha = type_of_header(numhdr(a));
            switch (ha)
            {   case TYPE_BIGNUM:
                case TYPE_RATNUM:
                    break;
                case TYPE_COMPLEX_NUM:
                {   Complex c1;
                    double d;
                    c1.real = float_of_number(real_part(a));
                    c1.imag = float_of_number(imag_part(a));
                    d = Cabs(c1);
// /* I wonder if I am allowed to promote short or single values to
//    double precision here?
                    a = make_boxfloat(d, TYPE_DOUBLE_FLOAT);
                    errexit();
                    return onevalue(a);
                }
                default:
                    return aerror1("bad arg for abs",  a);
            }
            break;
        }
        case TAG_BOXFLOAT:
            break;
        default:
            return aerror1("bad arg for abs",  a);
    }
    if (minusp(a))
    {   nil = C_nil;
        if (!exception_pending()) a = negate(a);
    }
    errexit();
    return onevalue(a);
}

static LispObject Lphase(LispObject nil, LispObject a)
{   bool s;
    double d;
    if (is_numbers(a) && is_complex(a))
        return Latan2(nil, imag_part(a), real_part(a));
    s = minusp(a);
    errexit();
    if (s) d = -_pi;
    else d = _pi;
    a = make_boxfloat(d, TYPE_DOUBLE_FLOAT);
    errexit();
    return onevalue(a);
// /* Wrong precision, I guess
}

static LispObject Lsignum(LispObject nil, LispObject a)
{
//
//* This seems an expensive way of doing things - huh? Maybe complex values?
    bool z;
    LispObject w;
    z = zerop(a);
    nil = C_nil;
    if (z || exception_pending()) return onevalue(a);
    push(a);
    w = Labsval(nil, a);
    pop(a);
    errexit();
    a = quot2(a, w);
    errexit();
    return onevalue(a);
}

static LispObject Lcis(LispObject, LispObject a)
//
// Implement as exp(i*a) - this permits complex args which goes
// beyond the specification of Common Lisp.
//
{   LispObject ii, nil;
    push(a);
    ii = make_complex(fixnum_of_int(0), fixnum_of_int(1));
    pop(a);
    errexit();
//
// it seems a bit gross to multiply by i by calling times2(), but
// doing so avoids loads of messy type dispatch code here and
// I am not over-worried about performance at this level (yet).
//
    a = times2(a, ii);
    errexit();
    return Ltrigfn(30, a);     // exp()
}

LispObject Latan(LispObject, LispObject a)
{   return Ltrigfn(15, a);     // atan()
}

LispObject Latan_2(LispObject env, LispObject a, LispObject b)
{   return Latan2(env, a, b);
}

LispObject Latan2(LispObject nil, LispObject y, LispObject x)
{   double u, v, r;
    u = float_of_number(x);
    v = float_of_number(y);
    if (u == 0.0 && v == 0.0) r = 0.0; // really an error case
//
// Here I am assuming IEEE arithmetic and hence that a division by zero
// just yields an infinity, not an error.
//
    else if (u >= 0.0) r = atan(v/u);
//
// On the next line x was negative so I will be careful about the sign
// of a zero value for y because the negative real axis is a branch cut.
//
    else if (v > 0.0 || (v == 0.0 && 1.0/v > 0.0))
//
// The adjustment here is done by computing pi/2+atan(-u/v) rather
// than as pi-atan(-v/u) to reduce risk of cancellation errors.
//
        r = _half_pi + atan(-u/v);
    else r = -_half_pi - atan(u/v);
    x = make_boxfloat(r, TYPE_DOUBLE_FLOAT);
    errexit();
    return onevalue(x);
}

LispObject Latan2d(LispObject nil, LispObject y, LispObject x)
{   double u, v, r;
    u = float_of_number(x);
    v = float_of_number(y);
    if (u == 0.0 && v == 0.0) r = 0.0; // really an error case
    else if (u >= 0.0) r = n180pi*atan(v/u);
    else if (v > 0.0 || (v == 0.0 && 1.0/v > 0.0))
        r = 90.0 + n180pi*atan(-u/v);
    else r = -90.0 - n180pi*atan(u/v);
    x = make_boxfloat(r, TYPE_DOUBLE_FLOAT);
    errexit();
    return onevalue(x);
}

LispObject Lacos(LispObject, LispObject a)
{   return Ltrigfn(0, a);
}

LispObject Lacosd(LispObject, LispObject a)
{   return Ltrigfn(1, a);
}

LispObject Lacosh(LispObject, LispObject a)
{   return Ltrigfn(2, a);
}

LispObject Lacot(LispObject, LispObject a)
{   return Ltrigfn(3, a);
}

LispObject Lacotd(LispObject, LispObject a)
{   return Ltrigfn(4, a);
}

LispObject Lacoth(LispObject, LispObject a)
{   return Ltrigfn(5, a);
}

LispObject Lacsc(LispObject, LispObject a)
{   return Ltrigfn(6, a);
}

LispObject Lacscd(LispObject, LispObject a)
{   return Ltrigfn(7, a);
}

LispObject Lacsch(LispObject, LispObject a)
{   return Ltrigfn(8, a);
}

LispObject Lasec(LispObject, LispObject a)
{   return Ltrigfn(9, a);
}

LispObject Lasecd(LispObject, LispObject a)
{   return Ltrigfn(10, a);
}

LispObject Lasech(LispObject, LispObject a)
{   return Ltrigfn(11, a);
}

LispObject Lasin(LispObject, LispObject a)
{   return Ltrigfn(12, a);
}

LispObject Lasind(LispObject, LispObject a)
{   return Ltrigfn(13, a);
}

LispObject Lasinh(LispObject, LispObject a)
{   return Ltrigfn(14, a);
}

// code 15 is for atan

LispObject Latand(LispObject, LispObject a)
{   return Ltrigfn(16, a);
}

// code 17 is atan2, 18 is atan2d

LispObject Latanh(LispObject, LispObject a)
{   return Ltrigfn(19, a);
}

LispObject Lcbrt(LispObject, LispObject a)
{   return Ltrigfn(20, a);
}

LispObject Lcos(LispObject, LispObject a)
{   return Ltrigfn(21, a);
}

LispObject Lcosd(LispObject, LispObject a)
{   return Ltrigfn(22, a);
}

LispObject Lcosh(LispObject, LispObject a)
{   return Ltrigfn(23, a);
}

LispObject Lcot(LispObject, LispObject a)
{   return Ltrigfn(24, a);
}

LispObject Lcotd(LispObject, LispObject a)
{   return Ltrigfn(25, a);
}

LispObject Lcoth(LispObject, LispObject a)
{   return Ltrigfn(26, a);
}

LispObject Lcsc(LispObject, LispObject a)
{   return Ltrigfn(27, a);
}

LispObject Lcscd(LispObject, LispObject a)
{   return Ltrigfn(28, a);
}

LispObject Lcsch(LispObject, LispObject a)
{   return Ltrigfn(29, a);
}

LispObject Lexp(LispObject, LispObject a)
{   return Ltrigfn(30, a);
}

// 31 is expt, 32 is hypot

LispObject Lln(LispObject, LispObject a)
{   return Ltrigfn(33, a);
}

// 34 is 2-arg log

LispObject Llog10(LispObject, LispObject a)
{   return Ltrigfn(35, a);
}

LispObject Llog2(LispObject, LispObject a)
{   return Ltrigfn(46, a);
}

LispObject Lsec(LispObject, LispObject a)
{   return Ltrigfn(36, a);
}

LispObject Lsecd(LispObject, LispObject a)
{   return Ltrigfn(37, a);
}

LispObject Lsech(LispObject, LispObject a)
{   return Ltrigfn(38, a);
}

LispObject Lsin(LispObject, LispObject a)
{   return Ltrigfn(39, a);
}

LispObject Lsind(LispObject, LispObject a)
{   return Ltrigfn(40, a);
}

LispObject Lsinh(LispObject, LispObject a)
{   return Ltrigfn(41, a);
}

LispObject Lsqrt(LispObject, LispObject a)
{   return Ltrigfn(42, a);
}

LispObject Ltan(LispObject, LispObject a)
{   return Ltrigfn(43, a);
}

LispObject Ltand(LispObject, LispObject a)
{   return Ltrigfn(44, a);
}

LispObject Ltanh(LispObject, LispObject a)
{   return Ltrigfn(45, a);
}

setup_type const arith10_setup[] =
{   {"abs",                     Labsval, too_many_1, wrong_no_1},
    {"acos",                    Lacos, too_many_1, wrong_no_1},
    {"acosd",                   Lacosd, too_many_1, wrong_no_1},
    {"acosh",                   Lacosh, too_many_1, wrong_no_1},
    {"acot",                    Lacot, too_many_1, wrong_no_1},
    {"acotd",                   Lacotd, too_many_1, wrong_no_1},
    {"acoth",                   Lacoth, too_many_1, wrong_no_1},
    {"acsc",                    Lacsc, too_many_1, wrong_no_1},
    {"acscd",                   Lacscd, too_many_1, wrong_no_1},
    {"acsch",                   Lacsch, too_many_1, wrong_no_1},
    {"asec",                    Lasec, too_many_1, wrong_no_1},
    {"asecd",                   Lasecd, too_many_1, wrong_no_1},
    {"asech",                   Lasech, too_many_1, wrong_no_1},
    {"asin",                    Lasin, too_many_1, wrong_no_1},
    {"asind",                   Lasind, too_many_1, wrong_no_1},
    {"asinh",                   Lasinh, too_many_1, wrong_no_1},
    {"atand",                   Latand, too_many_1, wrong_no_1},
    {"atan2",                   too_few_2, Latan2, wrong_no_2},
    {"atan2d",                  too_few_2, Latan2d, wrong_no_2},
    {"atanh",                   Latanh, too_many_1, wrong_no_1},
    {"cbrt",                    Lcbrt, too_many_1, wrong_no_1},
    {"cos",                     Lcos, too_many_1, wrong_no_1},
    {"cosd",                    Lcosd, too_many_1, wrong_no_1},
    {"cosh",                    Lcosh, too_many_1, wrong_no_1},
    {"cot",                     Lcot, too_many_1, wrong_no_1},
    {"cotd",                    Lcotd, too_many_1, wrong_no_1},
    {"coth",                    Lcoth, too_many_1, wrong_no_1},
    {"csc",                     Lcsc, too_many_1, wrong_no_1},
    {"cscd",                    Lcscd, too_many_1, wrong_no_1},
    {"csch",                    Lcsch, too_many_1, wrong_no_1},
    {"exp",                     Lexp, too_many_1, wrong_no_1},
    {"expt",                    too_few_2, Lexpt, wrong_no_2},
    {"hypot",                   too_few_2, Lhypot, wrong_no_2},
    {"ln",                      Lln, too_many_1, wrong_no_1},
    {"log",                     Lln, Llog_2, wrong_no_2},
    {"log2",                    Llog2, too_many_1, wrong_no_2},
    {"log10",                   Llog10, too_many_1, wrong_no_1},
    {"sec",                     Lsec, too_many_1, wrong_no_1},
    {"secd",                    Lsecd, too_many_1, wrong_no_1},
    {"sech",                    Lsech, too_many_1, wrong_no_1},
    {"sin",                     Lsin, too_many_1, wrong_no_1},
    {"sind",                    Lsind, too_many_1, wrong_no_1},
    {"sinh",                    Lsinh, too_many_1, wrong_no_1},
    {"sqrt",                    Lsqrt, too_many_1, wrong_no_1},
    {"tan",                     Ltan, too_many_1, wrong_no_1},
    {"tand",                    Ltand, too_many_1, wrong_no_1},
    {"tanh",                    Ltanh, too_many_1, wrong_no_1},
    {"cis",                     Lcis, too_many_1, wrong_no_1},
//  {"isqrt",                   Lisqrt, too_many_1, wrong_no_1},
    {"phase",                   Lphase, too_many_1, wrong_no_1},
    {"signum",                  Lsignum, too_many_1, wrong_no_1},
    {"atan",                    Latan, Latan_2, wrong_no_1},
    {"logb",                    too_few_2, Llog_2, wrong_no_2},
    {NULL,                      0, 0, 0}
};

// end of arith10.cpp
