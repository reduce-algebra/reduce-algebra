// arith10.cpp                            Copyright (C) 1990-2022 Codemist

//
// Arithmetic functions.
//

/**************************************************************************
 * Copyright (C) 2022, Codemist.                         A C Norman       *
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


// Much of the code here is extracted from the portable Fortran library
// used by Codemist with its Fortran compiler.

// I think I should probably now view crlibm as something that will
// ALWAYS be in use...

#ifndef HAVE_CRLIBM

#ifdef WIN32

// At least as of the end of August 2011 the implementations of sin
// and cos in the C library that comes with i686-w64-mingw32 and
// x86_65-w64-mingw32 compilers do not do range reduction very well,
// and so a calculation "sin(4.0*atan(1.0))" gives a bad result -
// specifically one with a load of trailing zeros in its binary
// representation. The code here does some more careful range reduction
// and so calls the basic version only when it is safer.
//
// In very many cases I will be using crlibm and so this hack will not
// get activated.


static double arg_reduce(double a, int *quadrant)
// Reduce argument to the range -pi/4 to pi/4, and set quadrant to the
// relevant quadant.
{
// pi/2 is close to c1 + c2 + c3 and both c1 and c2 should be
// stored with only the top 30 bits in their FP representation non-zero.
// Furthermore the integers used to specify values here are less than
// 2^31 and so any internal working that could have limits at 32-bit
// integers should be safe.
    static double c1 = 1686629713.0/1073741824.0;
    static double c2 = 1121027177.0/1073741824.0/1073741824.0/16.0;
    static double c3 = 2.91273205609335616e-20;
    double w = a / 1.5707963267948966;
    int32_t n = static_cast<int>(w < 0.0 ? w - 0.5 : w + 0.5);
// OK - now n should be the nearest integer to a/(pi/2) so
// (a - n) should be at most (about) pi/4 in absolute value.
    w = a - static_cast<double>(n)*c1;
    w = w - static_cast<double>(n)*c2;
    w = w - static_cast<double>(n)*c3;
    *quadrant = static_cast<int>(n & 3);
    return w;
}

double my_sin(double x)
{   int quadrant;
    x = arg_reduce(x, &quadrant);
    switch (quadrant)
{       default:
        case 0: return CSLsin(x);
        case 1: return CSLcos(x);
        case 2: return CSLsin(-x);
        case 3: return -CSLcos(x);
    }
}

double my_cos(double x)
{   int quadrant;
    x = arg_reduce(x, &quadrant);
    switch (quadrant)
{       default:
        case 0: return CSLcos(x);
        case 1: return CSLsin(-x);
        case 2: return -CSLcos(x);
        case 3: return CSLsin(x);
    }
}

#else   // WIN32

#define my_sin CSLsin
#define my_cos CSLcos

#endif  // WIN32
#else

#define my_sin CSLsin
#define my_cos CSLcos

#endif // HAVE_CRLIBM

#define CSL_log_2 0.6931471805599453094

static Complex Cdiv_z(Complex, Complex);

// Here I should review the C library complex elementary functions
// that are available with newer installations - but I may end up
// preferring to use my own versions to achieve absolute compatibility
// across platforms. However if I have my own code I need to review its
// behaviour on branch cuts and with regards to +0.0 and -0.0.

UNUSED_NAME static Complex CSLcpowi(Complex z, int n)
{
// Raises w complex number to an integer power by repeated squaring.
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
        z.real = x1*x2 - y1*y2;
        z.imag = x1*y2 + y1*x2;
        return z;
    }
}

static Complex CSLcsin(Complex z)
{   double x = z.real, y = z.imag;
// sin(x + iy) = sin(x)*cosh(y) + i cos(x)*sinh(y)
// For smallish y this can be used directly.  For |y| > 50 I will
// compute sinh and cosh as just +/- exp(|y|)/2
    double s = my_sin(x), c = my_cos(x);
    double absy = std::fabs(y);
    if (absy <= 50.0)
    {   double sh = CSLsinh(y), ch = CSLcosh(y);
        z.real = s * ch;
        z.imag = c * sh;
        return z;
    }
    else
    {   double w;
        int n = _reduced_exp(absy, &w) - 1;
        z.real = std::ldexp(s*w, n);
        if (y < 0.0) z.imag = std::ldexp(-c*w, n);
        else z.imag = std::ldexp(c*w, n);
        return z;
    }
}


#define CSL_sqrt_starter 0.7071
#define CSL_sqrt_iters   6

static Complex CSLcsqrt(Complex z)
{   double x = z.real, y = z.imag;
// I believe that IEEE expect sqrt(-0.0 + 0.0*i) to be -0.0 + 0.0*i
    int j, n;
    double scale;
    double vx, vy;
    if (y == 0.0)
    {   if (x < 0.0)
        {   z.real = 0.0;
            z.imag = std::sqrt(-x);
        }
        else
        {   z.real = std::sqrt(x);
            z.imag = 0.0;
        }
        return z;           // Pure real arguments are easy
    }
    static_cast<void>(std::frexp(y, &n));
// Exact value returned by frexp not critical
    if (x != 0.0)
    {   int n1;
        static_cast<void>(std::frexp(x, &n1));
        if (n1 > n) n = n1;
    }
    n &= ~1;                // ensure it is even
    scale = std::ldexp(1.0, n);
    x = x / scale;
    y = y / scale; // Now max(|x|, |y|) is in [0.5, 1)
// Generate some kind of starting approximation for a NR iteration.
// The value selected here here will give a relative error of 1.6e-5
// after 4 iterations, and so would give about 6.0e-20 after 6, which
// is more accurate (just) than the machines that I use can cope with.
// Note that for z near the real axis the starting approximation is
// either real or (pure) imaginary, thus helping ensure that the near-
// zero component of the answer comes out to decent accuracy.
    if (y < x)
    {   if (x > -y) vx = CSL_sqrt_starter, vy = 0.0;
        else vx = CSL_sqrt_starter, vy = -CSL_sqrt_starter;
    }
    else if (x > -y) vx = CSL_sqrt_starter, vy = CSL_sqrt_starter;
    else if (y > 0.0) vx = 0.0, vy = CSL_sqrt_starter;
    else vx = 0.0, vy = -CSL_sqrt_starter;
// For starting values as preconditioned here 6 iterations will converge
// to about adequate accuracy. For some arguments fewer iterations would
// suffice, but I am taking the view that the cost of providing a more
// elaborate end-test might well exceed the cost of the extra iterations
// that this code performs.  Experiment shows that the worst relative
// error after 4 iterations is 1.3e-5, so after 6 it will be about
// 3.0e-20, which is better than machine accuracy.  5 iterations would
// not be enough. I could perhaps use a look-up table to obtain a starting
// approximation that would save me a couple of iterations?
    for (j=0; j<CSL_sqrt_iters; j++)
    {   double t = vx*vx + vy*vy;
        double qx = (x*vx + y*vy)/t,
               qy = (y*vx - x*vy)/t;
        vx = (vx + qx)*0.5;
        vy = (vy + qy)*0.5;
    }
    n = n/2;
    z.real = std::ldexp(vx, n);
    z.imag = std::ldexp(vy, n);
    return z;
}

#undef CSL_sqrt_starter
#undef CSL_sqrt_iters


static Complex CSLctan(Complex z)
{   double x = z.real, y = z.imag;
// tan(x + iy) = (tan(x) + i tanh(y))/(1 - i tan(x)*tanh(y))
    double t = CSLtan(x), th = std::tanh(y);
    double t2 = t*t, th2 = th*th;
    // many risks of premature overflow here
    double d = 1.0 + t2*th2;
    z.real = t*(1.0
                -th2)/d;  // /* if th2 is very near 1.0 this is inaccurate
    z.imag = th*(1.0+t2)/d;
    return z;
}

static Complex Cdiv_z(Complex p, Complex q)
{
// (p/q) as a complex number.  Note abominable issues about scaling so
// the large values of p and q can be handled properly.
// The easy scheme for (a + ib)/(c + id) would have been
//         (ac+bd)/w + i(bc - ad)/w            with w = cc + dd
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
// I avoid going frexp(0.0, &n1) since the exponent handed back in that
// case is zero, which is not actually very helpful here, where I would
// rather it was minus infinity.
        if (a == 0.0)
        {   if (b == 0.0) return p;         // (0.0, 0.0)/z
// Exact results from frexp unimportant
            else static_cast<void>(std::frexp(b, &n1));
        }
        else if (b == 0.0) static_cast<void>(std::frexp(a, &n1));
        else
        {   static_cast<void>(std::frexp(a, &n1));
            static_cast<void>(std::frexp(b, &n2));
            if (n2>n1) n1 = n2;
        }
        n = n1;
        scalep = std::ldexp(1.0, n1);        // scale numerator
        a = a / scalep;
        b = b / scalep;
// At this stage I know that the denominator has nonzero real & imag parts
        static_cast<void>(std::frexp(c, &n1));
        static_cast<void>(std::frexp(d, &n2));
        if (n2>n1) n1 = n2;
        n = n - n1;
        scaleq = std::ldexp(1.0, n1);        // scale denominator
        c = c / scaleq;
        d = d / scaleq;
        w = c*c + d*d;  // no overflow
        r.real = std::ldexp((a*c + b*d)/w, n);   // rescale final result
        r.imag = std::ldexp((b*c - a*d)/w, n);
        return r;
    }
}


static LispObject make_complex_float(Complex v, LispObject a)
// Here a complex result has been been computed (with double precision values
// for both real and imag parts).  Squash to the required floating point
// types and package up as a complex value, where (a) was the original input
// value and so should defined the type needed.  Note that both
// components of a will have the same type so only one needs testing.
// I do the 'onevalue' here.
//
// Note that regardless of their input type the elementary functions deliver
// at most double precision results.
{   int32_t type;
    LispObject a1, a2;
    a = real_part(a);
    if (is_sfloat(a))
        return onevalue(make_complex(pack_immediate_float(v.real, a),
                                     pack_immediate_float(v.imag, a)));
    if (is_bfloat(a)) type = type_of_header(flthdr(a));
    else type = TYPE_SINGLE_FLOAT;
    if (type == TYPE_LONG_FLOAT) type = TYPE_DOUBLE_FLOAT;
// There are MANY uses of make_boxfloat here. In pretty well all cases I let
// make_boxfloat do any overflow checks, and I do not support 128-bit floats.
    a1 = make_boxfloat(v.real, type);
    a2 = make_boxfloat(v.imag, type);
    a1 = make_complex(a1, a2);
    return onevalue(a1);
}

static double rln(double x)
{   if (!(x == x)) return x;   // Ie a NaN
    else if (x < 0.0) x = -x;
    return CSLlog(x);
}

static double iln(double x)
{   if (!(x == x)) return x;   // Ie a NaN
    else if (x < 0.0) return _pi;
    else return 0.0;
}

static double rsqrt(double x)
{   if (!(x == x)) return x;   // Ie a NaN
    else if (x < 0.0) return 0.0;
    else return std::sqrt(x);
}

static double isqrt(double x)
{   if (!(x == x)) return x;   // Ie a NaN
    if (x < 0.0) return std::sqrt(-x);
    else return 0.0;
}

static double rasin(double x)
{   if (1.0 < x) return _half_pi;
    else if (x <= -1.0) return -_half_pi;
    else return CSLasin(x);
}


static double iasin(double x)
{   bool sign;
    if (-1.0 <= x && x <= 1.0) return 0.0;
    else if (x < 0.0) x = -x, sign = true;
    else sign = false;
    if (x < 2.0)
    {   x += std::sqrt(x*x - 1.0);
        x = CSLlog(x);             // /* serious inaccuracy here
    }
    else if (x < 1.0e9)
    {   x += std::sqrt(x*x - 1.0);
        x = CSLlog(x);
    }
    else x = CSL_log_2 + CSLlog(x);
    if (sign) return -x;
    else return x;
}

static double racos(double x)
{   if (x <= -1.0) return _pi;
    else if (1.0 <= x) return 0.0;
    else return CSLacos(x);
}

static double iacos(double x)
{   bool sign;
    if (x < -1.0) x = -x, sign = true;
    else if (1.0 < x) sign = false;
    else return 0.0;
    if (x < 2.0)
    {   x += std::sqrt(x*x - 1.0);
        x = CSLlog(x);             // /* serious inaccuracy here
    }
    else if (x < 1.0e9)
    {   x += std::sqrt(x*x - 1.0);
        x = CSLlog(x);
    }
    else x = CSL_log_2 + CSLlog(x);
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
    {   x += std::sqrt(1.0 + x*x);
        x = CSLlog(x);
    }
    else x = CSLlog(x) + CSL_log_2;
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
// This is a minimax approximation to acosh(1+x)/sqrt(x) over the
// range x=0 to 0.5
        for (i=1; i<=11; i++) r = x*r + acosh_coeffs[i];
        x = std::sqrt(x)*r;
    }
    else if (x < 1.0e9)
    {   x += std::sqrt((x - 1.0)*(x + 1.0));
        x = CSLlog(x);
    }
    else x = CSLlog(x) + CSL_log_2;
    if (sign) return -x;
    else return x;
}

static double iacosh(double x)
{   if (1.0 <= x) return 0.0;
    else if (x <= -1.0) return _pi;
    else return CSLacos(x);
}

static double ratanh(double z)
{   if (z > -0.01 && z < -0.01)
    {   double zz = z*z;
        return z * (1 + zz*((1.0/3.0) + zz*((1.0/5.0) + zz*(1.0/7.0))));
    }
    z = (1.0 + z) / (1.0 - z);
    if (z < 0.0) z = -z;
    return CSLlog(z) / 2.0;
}

static double iatanh(double x)
{   if (x < -1.0) return _half_pi;
    else if (1.0 < x) return -_half_pi;
    else return 0.0;
}

// The functions from here on (for a bit) represent re-work to support the
// full set of elementary functions that Reduce would (maybe) like. They
// have not been adjusted to allow use with the software floating point
// option.

#define n180pi 57.2957795130823208768   // 180/pi

#define pi180  0.017453292519943295769  // pi/180

#define sqrthalf 0.7071                 // sqrt(0.5), low accuracy OK

static double racosd(double a)
{   if (a <= -1.0) return 180.0;
    else if (a < -sqrthalf) return 180.0 - n180pi*CSLacos(-a);
    else if (a < 0.0) return 90.0 + n180pi*CSLasin(-a);
    else if (a < sqrthalf) return 90.0 - n180pi*CSLasin(a);
    else if (a < 1.0) return n180pi*CSLacos(a);
    else return 0.0;
}

static double iacosd(double a)
// This version is only good enough for real-mode CSL, not for CCL
{   if (a >= -1.0 && a <= 1.0) return 0.0;
    else return 1.0;
}

static double racot(double a)
{   if (a >= 0.0)
        if (a > 1.0) return CSLatan(1.0/a);
        else return _half_pi - CSLatan(a);
    else if (a < -1.0) return _pi - CSLatan(-1.0/a);
    else return _half_pi + CSLatan(-a);
}

static double racotd(double a)
{   if (a >= 0.0)
        if (a > 1.0) return n180pi*CSLatan(1.0/a);
        else return 90.0 - n180pi*CSLatan(a);
    else if (a < -1.0) return 180.0 - n180pi*CSLatan(-1.0/a);
    else return 90.0 + n180pi*CSLatan(-a);
}

static double racoth(double a)
// No good in complex case
{   if (a >= -1.0 && a <= 1.0) return 0.0;
    else return ratanh(1.0/a);
}

static double iacoth(double a)
{   if (a >= -1.0 && a <= 1.0) return 1.0;
    else return 0.0;
}

static double racsc(double a)
{   if (a > -1.0 && a < 1.0) return 0.0;
    else return CSLasin(1.0/a);
}

static double iacsc(double a)
{   if (a > -1.0 && a < 1.0) return 1.0;
    else return 0.0;
}

static double racscd(double a)
{   if (a > -1.0 && a < 1.0) return 0.0;
// I could do better than this, I suspect...
    else return n180pi*CSLasin(1.0/a);
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
    else return CSLacos(1.0/a);
}

static double iasec(double a)
{   if (a > -1.0 && a < 1.0) return 1.0;
    else return 0.0;
}

static double rasecd(double a)
{   if (a > -1.0 && a <= 1.0) return 0.0;
// I could do better than this, I suspect...
    else return n180pi*CSLacos(1.0/a);
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
    else if (a < -sqrthalf) return -90.0 + n180pi*CSLacos(-a);
    else if (a < sqrthalf) return n180pi*CSLasin(a);
    else if (a < 1.0) return 90.0 - n180pi*CSLacos(a);
    else return 90.0;
}

static double iasind(double a)
{   if (a >= -1.0 && a <= 1.0) return 0.0;
    else return 1.0;
}

static double ratand(double a)
{   if (a < -1.0) return -90.0 + n180pi*CSLatan(-1.0/a);
    else if (a < 1.0) return n180pi*CSLatan(a);
    else return 90.0 - n180pi*CSLatan(1.0/a);
}

static double rcbrt(double a)
{   int xx, x, i, neg = 0;
    double b;
    if (a == 0.0) return 0.0;
    else if (a < 0.0) a = -a, neg = 1;
    b = std::frexp(a, &xx);  // end-conditions unimportant
    x = xx;
// b is now in the range 0.5 to 1.  The next line produces an
// approximately minimax linear approximation to the cube root
// function over the range concerned.
    b = 0.5996 + 0.4081*b;
    while (x % 3 != 0)
    {   x--;
        b *= 1.26;
    }
    b = std::ldexp(b, x/3);
// Experiment shows that there are values of the input variable
// that lead to the last of the following iterations making a
// (small) change to the result, but almost all of the time I
// could get away with one less.  Still, I do not consider cbrt
// important enough to optimise any further (e.g. I could go to
// use of a minimax rational first approximation...)
    for (i=0; i<6; i++)
        b = (2.0*b + a/(b*b))/3.0;
    if (neg) return -b;
    else return b;
}

static double rcot(double a)
// Compare this code with rcotd(). Here I just compute a tangent and
// form its reciprocal.  What about an arg of pi/2 then, where the
// tangent calculation might overflow?  Well it should not, since no
// integer multiple of pi/2 has an exact machine representation, so
// if you try to compute tan(pi/2) in floating point you should get a
// large but finite value.  For very large a where the tan() function
// loses resolution there could still be trouble, which is why I use
// a slower formula for big a.
{   if (a > 1000.0 || a < -1000.0) return my_cos(a)/my_sin(a);
    else return 1.0/CSLtan(a);
}

static double arg_reduce_degrees(double a, int *quadrant)
// Reduce argument to the range -45 to 45, and set quadrant to the
// relevant quadant.  Returns arg converted to radians.
{   double w = a / 90.0;
    int32_t n = static_cast<int>(w);
    w = a - 90.0*n;
    while (w < -45.0)
    {   n--;
        w = a - 90.0*n;
    }
    while (w >= 45.0)
    {   n++;
        w = a - 90.0*n;
    }
    *quadrant = static_cast<int>(n & 3);
    return pi180*w;
}

static double rsind(double a)
{   int quadrant;
    a = arg_reduce_degrees(a, &quadrant);
    switch (quadrant)
{       default:
        case 0: return CSLsin(a);
        case 1: return CSLcos(a);
        case 2: return CSLsin(-a);
        case 3: return -CSLcos(a);
    }
}

static double rcosd(double a)
{   int quadrant;
    a = arg_reduce_degrees(a, &quadrant);
    switch (quadrant)
{       default:
        case 0: return CSLcos(a);
        case 1: return CSLsin(-a);
        case 2: return -CSLcos(a);
        case 3: return CSLsin(a);
    }
}

static double rtand(double a)
{   int quadrant;
    a = arg_reduce_degrees(a, &quadrant);
    switch (quadrant)
{       default:
        case 0:
        case 2: return CSLtan(a);
        case 1:
        case 3: return 1.0/CSLtan(-a);
    }
}

static double rcotd(double a)
{   int quadrant;
    a = arg_reduce_degrees(a, &quadrant);
    switch (quadrant)
{       default:
        case 0:
        case 2: return 1.0/CSLtan(a);
        case 1:
        case 3: return CSLtan(-a);
    }
}


static double rcoth(double a)
{   if (a == 0.0) return HUGE_VAL;
    else return 1.0/std::tanh(a);
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
// This code is imperfect in that (at least!) exp(-a) can underflow to zero
// before 2*exp(-a) ought to have.  I will not worry about such refinement
// here. Much.
    if (a == 0.0) return HUGE_VAL;
    else if (a > 20.0) return 2.0*CSLexp(-a);
    else if (a < -20.0) return -2.0*CSLexp(a);
    else return 1.0/CSLsinh(a);
}

#define CSL_log10 2.302585092994045684

static double rlog10(double a)
{   if (a > 0.0) return CSLlog(a)/CSL_log10;
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
        a = std::frexp(a, &x);
        return CSLlog(a)/CSL_log2 + static_cast<double>(x);
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
// When |a| is big I ought to return 0.0
    return 1.0/CSLcosh(a);
}

#define i_times(z) \
    { double temp = z.imag; z.imag = z.real; z.real = -temp; }

#define m_i_times(z) \
    { double temp = z.imag; z.imag = -z.real; z.real = temp; }


// The calculations in the next few procedures are numerically
// crummy, but they should get branch cuts correct.  Re-work later.

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
// The following is asserted to behave better. I believe that the
// calculation (pi/2 - z.real) is guaranteed to introduce severe error
// when the answer is close to zero, and so this is probably not the ultimate
// proper formula to use.
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

// The next collection of things have not been implemented yet,
// but might be wanted in a full extended system.... maybe.

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

// Now the Lisp callable entrypoints for the above

typedef double real_arg_fn(double);
typedef Complex complex_arg_fn(Complex);

// Each trig function has three associated helpers.
// the first two are used for real arguments, and return the real and
// imaginary parts of the answer. If the function is always real for
// real input then the second function is given as nullptr.
// The final case is for genuine complex arguments.

typedef struct trigfn
{   double (*real)(double);
    double (*imag)(double);
    Complex (*complex)(Complex);
    const char *name;
} trigfn_record;

static trigfn_record const trig_functions[] =
{   {racos,  iacos,  CSLcacos,  "acos"},  // acos   0  inverse cos, rads, [0, pi)
    {racosd, iacosd, CSLcacosd, "acosd"}, // acosd  1  inverse cos, degs, [0, 180)
    {racosh, iacosh, CSLcacosh, "acosh"}, // acosh  2  inverse hyperbolic cosine
    {racot,  nullptr,CSLcacot,  "acot"},  // acot   3  inverse cot, rads, (0, pi)
    {racotd, nullptr,CSLcacotd, "acotd"}, // acotd  4  inverse cot, degs, (0, 180)
    {racoth, iacoth, CSLcacoth, "acoth"}, // acoth  5  inverse hyperbolic cotangent
    {racsc,  iacsc,  CSLcacsc,  "acsc"},  // acsc   6  inverse cosec, [-pi/2, pi/2]
    {racscd, iacscd, CSLcacscd, "acscd"}, // acscd  7  inverse cosec, degs, [-90, 90]
    {racsch, nullptr,CSLcacsch, "acsch"}, // acsch  8  inverse hyperbolic coseCSLcant
    {rasec,  iasec,  CSLcasec,  "asec"},  // asec   9  inverse sec, rads, [0, pi)
    {rasecd, iasecd, CSLcasecd, "asecd"}, // asecd  10 inverse sec, degs, [0, 180)
    {rasech, iasech, CSLcasech, "asech"}, // asech  11 inverse hyperbolic seCSLcant
    {rasin,  iasin,  CSLcasin,  "asin"},  // asin   12 inverse sin, rads, [-pi/2, pi/2]
    {rasind, iasind, CSLcasind, "asind"}, // asind  13 inverse sin, degs, [-90, 90]
    {CSLasinh, nullptr, CSLcasinh, "asinh"}, // asinh  14 inverse hyperbolic sin
    {CSLatan,nullptr,CSLcatan,  "atan"},  // atan   15 1-arg inverse tan, (-pi/2, pi/2)
    {ratand, nullptr,CSLcatand, "atand"}, // atand  16 inverse tan, degs, (-90, 90)
    {nullptr,nullptr,nullptr,      "atan2"}, // atan2  17 2-arg inverse tan, [0, 2pi)
    {nullptr,nullptr,nullptr,      "atan2d"},// atan2d 18 2-arg inverse tan, degs, [0, 360)
    {ratanh, iatanh, CSLcatanh, "atanh"}, // atanh  19 inverse hyperbolic tan
    {rcbrt,  nullptr,ccbrt,     "cbrt"},  // cbrt   20 cube root
    {my_cos, nullptr,Ccos,      "cos"},   // cos    21 cosine, rads
    {rcosd,  nullptr,CSLccosd,  "cosd"},  // cosd   22 cosine, degs
    {CSLcosh,nullptr,CSLccosh,  "cosh"},  // cosh   23 hyperbolic cosine
    {rcot,   nullptr,CSLccot,   "cot"},   // cot    24 cotangent, rads
    {rcotd,  nullptr,CSLccotd,  "cotd"},  // cotd   25 cotangent, degs
    {rcoth,  nullptr,CSLccoth,  "coth"},  // coth   26 hyperbolic cotangent
    {rcsc,   nullptr,CSLccsc,   "csc"},   // csc    27 cosecant, rads
    {rcscd,  nullptr,CSLccscd,  "cscd"},  // cscd   28 cosecant, degs
    {rcsch,  nullptr,CSLccsch,  "csch"},  // csch   29 hyperbolic cosecant
    {CSLexp, nullptr,Cexp,      "exp"},   // exp    30 exp(x) = e^z, e approx 2.71828
    {nullptr,nullptr,nullptr,   "expt"},  // expt   31 expt(a,b) = a^b
    {nullptr,nullptr,nullptr,   "hypot"}, // hypot  32 hypot(a,b) = sqrt(a^2+b^2)
    {rln,    iln,    Cln,       "ln"},    // ln     33 log base e, e approx 2.71828
    {nullptr,nullptr,nullptr,   "log"},   // log    34 2-arg log
    {rlog10, ilog10, CSLclog10, "log10"}, // log10  35 log to base 10
    {rsec,   nullptr,CSLcsec,   "sec"},   // sec    36 secant, rads
    {rsecd,  nullptr,CSLcsecd,  "secd"},  // secd   37 secant, degs
    {rsech,  nullptr,CSLcsech,  "sech"},  // sech   38 hyperbolic secant
    {my_sin, nullptr,CSLcsin,   "sin"},   // sin    39 sine, rads
    {rsind,  nullptr,CSLcsind,  "sind"},  // sind   40 sine, degs
    {CSLsinh,nullptr,CSLcsinh,  "sinh"},  // sinh   41 hyperbolic sine
    {rsqrt,  isqrt,  CSLcsqrt,  "sqrt"},  // sqrt   42 square root
    {CSLtan, nullptr,CSLctan,   "tan"},   // tan    43 tangent, rads
    {rtand,  nullptr,CSLctand,  "tand"},  // tand   44 tangent, degs
    {std::tanh,nullptr,CSLctanh,"tanh"},  // tanh   45 hyperbolic tangent
    {rlog2,  ilog2,  CSLclog2,  "log2"}   // log2   46 log to base 2
};

static LispObject Ltrigfn(unsigned int which_one, LispObject a)
// This one piece of code does the type-dispatch for the main collection
// of elementary functions.
{   double d;
#ifndef COMMON
    int32_t restype = TYPE_DOUBLE_FLOAT;
#else
// single floats seem to me to be a bad idea! But they are the default
// for Common Lisp. Boo Hiss.
    int32_t restype = TYPE_SINGLE_FLOAT;
#endif
    if (which_one > 46) return aerror("trigfn internal error");
    switch (static_cast<int>(a) & TAG_BITS)
    {   case TAG_FIXNUM:
            if (is_sfloat(a))
            {   d = value_of_immediate_float(a);
                restype = 0;
                break;
            }
            else d = static_cast<double>(int_of_fixnum(a));
            break;
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
        if (im == nullptr)
// If there is no function for giving the complex part of a result
// from a real argument then at this point I have a real input and
// so I just deal with it simply.
//
// I really suspect I should do something writh errno here to
// keep track of when things go wrong.  Doing so feels fairly
// messy, but it is necessary if I am to raise exceptions for
// Lisp if an elementary function leads to overflow.
        {   double (*rl)(double) = trig_functions[which_one].real;
            if (rl == nullptr) return aerror("unimplemented trig function");
            return onevalue(make_boxfloat((*rl)(d), restype));
        }
        else
        {   double c1r, c1i;
            LispObject rp, ip;
            double (*rl)(double) = trig_functions[which_one].real;
            if (rl == 0) return aerror("unimplemented trig function");
            c1r = (*rl)(d);
            c1i = (*im)(d);
// if the imaginary part of the value is zero then I will return a real
// answer - this is correct since the original argument was real, but
// it has to be done by hand here because normally complex values with
// zero imaginary part remain complex.
            if (c1i == 0.0) return onevalue(make_boxfloat(c1r, restype));
#ifndef COMMON
// For now at least I will keep raising an error in cases where the
// result would not be real
            const char *name = trig_functions[which_one].name;
            char errbuff[64];
            std::sprintf(errbuff, "Arg for %s out of range", name);
            return aerror1(errbuff, a);
#endif
            rp = make_boxfloat(c1r, restype);
            ip = make_boxfloat(c1i, restype);
            return onevalue(make_complex(rp, ip));
        }
    }
}

static LispObject makenum(LispObject a, int32_t n)
// Make the value n, but type-consistent with the object a.  Usually
// used with n=0 or n=1
{
#ifndef COMMON
    int32_t restype = TYPE_DOUBLE_FLOAT;
#else
    int32_t restype = TYPE_SINGLE_FLOAT;
#endif
    switch (static_cast<int>(a) & TAG_BITS)
    {   case TAG_FIXNUM:
            if (is_sfloat(a))
                return pack_immediate_float(static_cast<double>(n), a);
            else return fixnum_of_int(n);
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
                    ii = makenum(a, 0);
                    a = make_complex(rr, ii);
                    return onevalue(a);
                }
            }
            return aerror1("bad arg for makenumber",  a);
        }
        case TAG_BOXFLOAT:
            restype = type_of_header(flthdr(a));
#ifdef HAVE_SOFTFLOAT
            if (restype == TYPE_LONG_FLOAT)
                return onevalue(make_boxfloat128(
                                    float128_of_number(fixnum_of_int(n))));
#endif // HAVE_SOFTFLOAT
            return onevalue(make_boxfloat(static_cast<double>(n), restype));
        default:
            return aerror1("bad arg for makenumber",  a);
    }
}

static LispObject CSLpowi(LispObject a, uint32_t n)
// Raise a to the power n by repeated multiplication. The name is CSLpowi
// rather than just powi because some miserable C compilers come with an
// external function called powi in <cmath> and then moan about the
// name clash.
{   if (n == 0) return makenum(a, 1); // value 1 of appropriate type
    else if (n == 1) return a;
    else if ((n & 1) == 0)
    {   a = CSLpowi(a, n/2);
        errexit();
        return times2(a, a);
    }
    else
    {   LispObject b;
        THREADID;
        Save save(THREADARG a);
        b = CSLpowi(a, n/2);
        errexit();
        b = times2(b, b);
        errexit();
        save.restore(a);
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

static LispObject Lhypot(LispObject env, LispObject a, LispObject b)
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
// A worry I have is that the multiplication on the following line can
// overflow, blowing me out of the water.
        r = v * std::sqrt(1.0 + r*r);
    }
    a = make_boxfloat(r, TYPE_DOUBLE_FLOAT);
    return onevalue(a);
}

LispObject Lexpt(LispObject env, LispObject a, LispObject b)
{   double d, e;
    int32_t restype, n;
    LispObject w;
    Complex c1, c2, c3;
// I take special action on 1, 0 and -1 raised to a power that is an integer
// or a bignum. In part this is because raising 1 to a power may be a fairly
// common case worthy of special care, but the main pressure came because
// these numbers raised to bignum powers can still have fixnum results, and
// the value can be computed fast. I am not doing this for -1.0, 0.0 or 1.0.
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
// In a similar vein I will take special action on #C(0 1) and #C(0 -1)
// raise to integer (including bignum) powers. Note that these are complex
// values with integer components.
    if (is_numbers(a) && is_complex(a) &&
        real_part(a)==fixnum_of_int(0) &&
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
                return onevalue(a);
            default:  break;
        }
    }
    if (is_fixnum(b))   // bignum exponents would yield silly values!
    {   n = int_of_fixnum(b);
        if (n == 1) return onevalue(a);
        if (n < 0)
        {
// With floating point value if I compute a^(-n) as 1.0/a^n then I can get
// premature overflow, and indeed an exception from overflow (if I am in
// exception-raising mode) when the result would be finite - in particular
// if the result is a denormalised value.
// I worry that if instead I compute (1.0/a)^n that rounding in computing
// 1.0/a could be amplified unduly. But still that is what I do.
#ifdef COMMON
            a = CLquot2(fixnum_of_int(1), a);
#else
            a = quot2(fixnum_of_int(1), a);
#endif
            a = CSLpowi(a, (uint32_t)(-n));
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
        b = make_boxfloat(c3.imag, restype);
        a = make_complex(a, b);
        return onevalue(a);
    }
    d = float_of_number(a);
    e = float_of_number(b);
    if (d < 0.0)
    {   c1.real = d; c1.imag = 0.0;
        c2.real = e; c2.imag = 0.0;
        c3 = Cpow(c1, c2);
        a = make_boxfloat(c3.real, restype);
        b = make_boxfloat(c3.imag, restype);
        a = make_complex(a, b);
        return onevalue(a);
    }
    d = CSLpow(d, e);
    a = make_boxfloat(d, restype);
    return onevalue(a);
}

LispObject Llog_2(LispObject env, LispObject a, LispObject b)
// Log with specified base.
{   THREADID;
    Save save(THREADARG b);
    a = Ltrigfn(33, a);
    errexit();
    save.restore(b);
    Save save1(THREADARG a);
    b = Ltrigfn(33, b);
    errexit();
    save1.restore(a);
    return quot2(a, b);
}

#ifdef ISQRT_IMPLEMENTED_PROPERLY
// This can only be used when it is implemented properly!
static LispObject Lisqrt(LispObject, LispObject a)
{   double d;
// This makes some pretence at computing an integer square root, but it
// does so incredibly clumsily by mapping onto a floating point value and
// then expecting the square root computed that way to fit into a fixnum,
// ie to be at worst 27 or 60 bits long. That is not at all good enough for
// serious use so I am disabling it for now!
    switch (static_cast<int>(a) & TAG_BITS)
    {   case TAG_FIXNUM:
            d = static_cast<double>(int_of_fixnum(a));
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
    d = std::sqrt(d);
// /* This is not anything like good enough yet
    return onevalue(fixnum_of_int((int32_t)d));
}
#endif

LispObject Labsval(LispObject env, LispObject a)
// I call this Labsval not Labs because a non-case-sensitive linker
// would confuse Labs with labs, and labs is defined in the C libraries...
// Of course I do not think that case-insensitive linkers should be allowed
// to remain in service....
{   switch (static_cast<int>(a) & TAG_BITS)
    {   case TAG_FIXNUM:
//      case XTAG_SFLOAT:
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
    if (minusp(a)) a = negate(a);
    return onevalue(a);
}

static LispObject Lphase(LispObject env, LispObject a)
{   bool s;
    double d;
    if (is_numbers(a) && is_complex(a))
        return Latan2(nil, imag_part(a), real_part(a));
    s = minusp(a);
    if (s) d = -_pi;
    else d = _pi;
    a = make_boxfloat(d, TYPE_DOUBLE_FLOAT);
    return onevalue(a);
// /* Wrong precision, I guess
}

static LispObject Lsignum(LispObject env, LispObject a)
{
//* This seems an expensive way of doing things - huh? Maybe complex values?
    bool z;
    LispObject w;
    z = zerop(a);
    if (z) return onevalue(a);
    THREADID;
    Save save(THREADARG a);
    w = Labsval(nil, a);
    errexit();
    save.restore(a);
    a = quot2(a, w);
    return onevalue(a);
}

static LispObject Lcis(LispObject, LispObject a)
// Implement as exp(i*a) - this permits complex args which goes
// beyond the specification of Common Lisp.
{   LispObject ii;
    THREADID;
    Save save(THREADARG a);
    ii = make_complex(fixnum_of_int(0), fixnum_of_int(1));
    errexit();
    save.restore(a);
// it seems a bit gross to multiply by i by calling times2(), but
// doing so avoids loads of messy type dispatch code here and
// I am not over-worried about performance at this level (yet).
    a = times2(a, ii);
    return Ltrigfn(30, a);     // exp()
}

LispObject Latan(LispObject, LispObject a)
{   return Ltrigfn(15, a);     // atan()
}

LispObject Latan_2(LispObject env, LispObject a, LispObject b)
{   return Latan2(env, a, b);
}

LispObject Latan2(LispObject env, LispObject y, LispObject x)
{   double u, v, r;
    u = float_of_number(x);
    v = float_of_number(y);
    if (u == 0.0 && v == 0.0) r = 0.0; // really an error case
// Here I am assuming IEEE arithmetic and hence that a division by zero
// just yields an infinity, not an error.
    else if (u >= 0.0) r = CSLatan(v/u);
// On the next line x was negative so I will be careful about the sign
// of a zero value for y because the negative real axis is a branch cut.
    else if (v > 0.0 || (v == 0.0 && 1.0/v > 0.0))
// The adjustment here is done by computing pi/2+atan(-u/v) rather
// than as pi-atan(-v/u) to reduce risk of cancellation errors.
        r = _half_pi + CSLatan(-u/v);
    else r = -_half_pi - CSLatan(u/v);
    x = make_boxfloat(r, TYPE_DOUBLE_FLOAT);
    return onevalue(x);
}

LispObject Latan2d(LispObject env, LispObject y, LispObject x)
{   double u, v, r;
    u = float_of_number(x);
    v = float_of_number(y);
    if (u == 0.0 && v == 0.0) r = 0.0; // really an error case
    else if (u >= 0.0) r = n180pi*CSLatan(v/u);
    else if (v > 0.0 || (v == 0.0 && 1.0/v > 0.0))
        r = 90.0 + n180pi*CSLatan(-u/v);
    else r = -90.0 - n180pi*CSLatan(u/v);
    x = make_boxfloat(r, TYPE_DOUBLE_FLOAT);
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

// If ARITHLIB is enabled all these functions will have their names
// prefixed with "old" so that the versions from the arithlib code
// provide the default behaviour

#ifdef ARITHLIB
#define X "old"
#else // ARITHLIB
#define X
#endif // ARITHLIB

setup_type const arith10_setup[] =
{   DEF_1(X "abs",          Labsval),
    DEF_1(X "acos",         Lacos),
    DEF_1(X "acosd",        Lacosd),
    DEF_1(X "acosh",        Lacosh),
    DEF_1(X "acot",         Lacot),
    DEF_1(X "acotd",        Lacotd),
    DEF_1(X "acoth",        Lacoth),
    DEF_1(X "acsc",         Lacsc),
    DEF_1(X "acscd",        Lacscd),
    DEF_1(X "acsch",        Lacsch),
    DEF_1(X "asec",         Lasec),
    DEF_1(X "asecd",        Lasecd),
    DEF_1(X "asech",        Lasech),
    DEF_1(X "asin",         Lasin),
    DEF_1(X "asind",        Lasind),
    DEF_1(X "asinh",        Lasinh),
    DEF_1(X "atand",        Latand),
    DEF_2(X "atan2",        Latan2),
    DEF_2(X "atan2d",       Latan2d),
    DEF_1(X "atanh",        Latanh),
    DEF_1(X "cbrt",         Lcbrt),
    DEF_1(X "cos",          Lcos),
    DEF_1(X "cosd",         Lcosd),
    DEF_1(X "cosh",         Lcosh),
    DEF_1(X "cot",          Lcot),
    DEF_1(X "cotd",         Lcotd),
    DEF_1(X "coth",         Lcoth),
    DEF_1(X "csc",          Lcsc),
    DEF_1(X "cscd",         Lcscd),
    DEF_1(X "csch",         Lcsch),
    DEF_1(X "exp",          Lexp),
    DEF_2(X "expt",         Lexpt),
    DEF_2(X "hypot",        Lhypot),
    DEF_1(X "ln",           Lln),
    {X "log",               G0Wother, Lln, Llog_2, G3Wother, G4Wother},
    DEF_1(X "log2",         Llog2),
    DEF_1(X "log10",        Llog10),
    DEF_1(X "sec",          Lsec),
    DEF_1(X "secd",         Lsecd),
    DEF_1(X "sech",         Lsech),
    DEF_1(X "sin",          Lsin),
    DEF_1(X "sind",         Lsind),
    DEF_1(X "sinh",         Lsinh),
    DEF_1(X "sqrt",         Lsqrt),
    DEF_1(X "tan",          Ltan),
    DEF_1(X "tand",         Ltand),
    DEF_1(X "tanh",         Ltanh),
    DEF_1(X "cis",          Lcis),
//  DEF_1(X "isqrt",        Lisqrt),
    DEF_1(X "phase",        Lphase),
    DEF_1(X "signum",       Lsignum),
    {X "atan",              G0Wother, Latan, Latan_2, G3Wother, G4Wother},
    DEF_2(X "logb",         Llog_2),
    {nullptr,             nullptr, nullptr, nullptr, nullptr, nullptr}
};

// end of arith10.cpp
