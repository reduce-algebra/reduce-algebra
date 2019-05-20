// int128_t.h                              Copyright (C) 1990-2019 Codemist

#ifndef header_int128_t_h
#define header_int128_t_h 1


/**************************************************************************
 * Copyright (C) 2019, Codemist.                         A C Norman       *
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

// This header provides a shallow abstraction for signed 128-bit integers.
// In the easy case it uses a built-in type, in the hard case it maps
// operations onto use of the 128-bit unsigned type that is supported
// in software.



#ifdef HAVE_NATIVE_INT128

inline uint128_t uint128(int128_t v)
{   return (uint128_t)v;
}

inline uint128_t uint128(uint64_t v)
{   return (uint128_t)v;
}

inline uint128_t uint128(int64_t v)
{   return (uint128_t)v;
}

inline int128_t int128(int64_t v)
{   return (int128_t)v;
}

inline bool greaterp128(int128_t a, int128_t b)
{   return a > b;
}

inline bool lessp128(int128_t a, int128_t b)
{   return a < b;
}

inline bool geq128(int128_t a, int128_t b)
{   return a >= b;
}

inline bool leq128(int128_t a, int128_t b)
{   return a <= b;
}

inline int128_t ASL128(int128_t a, int n)
{   if (n<0 || n>=8*(int)sizeof(int128_t)) n = 0;
    return(int128_t) ((uint128_t)a) << n;
}

#ifdef SIGNED_SHIFTS_ARE_ARITHMETIC

inline int128_t ASR128(int128_t a, int n)
{   if (n<0 || n>=8*(int)sizeof(int128_t)) n = 0;
    return a >> n;
}

#else // SIGNED_SHIFTS_ARE_ARITHMETIC

inline int128_t ASR128(int128_t a, int n)
{   if (n<0 || n>=sizeof(uint128_t)) n = 0;
    uint128_t r = ((uint128_t)a) >> n;
    uint128_t signbit = ((uint128_t)a) >> (8*sizeof(uint128_t)-1);
    if (n != 0) r |= ((-signbit) << (8*sizeof(uint128_t) - n);
    return (int128_t)r;
}

#endif // SIGNED_SHIFTS_ARE_ARITHMETIC

inline int64_t NARROW128(int128_t a)
{   return (int64_t)a;
}

inline void divrem128(int128_t a, int128_t b,
                      int128_t &q, int128_t &r)
{   uint128_t qq = a/b;
    q = qq;
    r = a - qq*b;
}

#else // HAVE_NATIVE_INT128_T

// Used if there is no native int128_t type available. I use a software
// uint128_t type. However note that converting a signed value to 128 bits
// using a simple cast does not propagate sign information into the top half,
// so here is code that does:

typedef uint128_t int128_t;

inline uint128_t uint128(int128_t v)
{   uint128_t r = v;
    return r;
}

inline uint128_t uint128(int64_t v)
{   uint128_t r = (uint64_t)v;
    return r;
}

inline uint128_t uint128(uint64_t v)
{   uint128_t r = v;
    return r;
}

// This MESS is based on me reading the code for uint128_t and hoping that
// this achieves what I need! Getting values into the top 64-bits is not
// as easy as I might have hoped!

inline int128_t int128(int64_t v)
{   int128_t r = (uint64_t)v;
    if (v < 0)
    {   int128_t w = -(uint64_t)1;
        w = w <<64;
        r = r | w;
    }
    return r;
}

// assignment, +, -, *, &, |, ^, ~, == and != can all behave exactly
// the same when I think of a value as being signed.

// Ordered comparisons need special treatment. I will do them using
// verbosely names functions.

inline bool greaterp128(const uint128_t & a, const uint128_t & b)
{   uint128_t aa(a.upper() ^ UINT64_C(0x8000000000000000), a.lower());
    uint128_t bb(b.upper() ^ UINT64_C(0x8000000000000000), b.lower());
    return aa > bb;
}

inline bool lessp128(const uint128_t & a, const uint128_t & b)
{   uint128_t aa(a.upper() ^ UINT64_C(0x8000000000000000), a.lower());
    uint128_t bb(b.upper() ^ UINT64_C(0x8000000000000000), b.lower());
    return aa < bb;
}

inline bool geq128(const uint128_t & a, const uint128_t & b)
{   uint128_t aa(a.upper() ^ UINT64_C(0x8000000000000000), a.lower());
    uint128_t bb(b.upper() ^ UINT64_C(0x8000000000000000), b.lower());
    return aa >= bb;
}

inline bool leq128(const uint128_t & a, const uint128_t & b)
{   uint128_t aa(a.upper() ^ UINT64_C(0x8000000000000000), a.lower());
    uint128_t bb(b.upper() ^ UINT64_C(0x8000000000000000), b.lower());
    return aa <= bb;
}

inline int128_t ASL128(const int128_t & a, int n)
{   if (n >= 128) return 0;
    if (n < 64) return
        int128_t((a.upper()<<n) | (a.lower()>>(64-n)),
                 a.lower()<<n);
    else if (n == 64) return int128_t(a.lower(), 0);
    else return int128_t(a.lower()<<(n-64), 0);
}

inline int128_t ASR128(const int128_t & a, int n)
{   if (n >= 128) return (a < 0 ? -1 : 0);
    if (n < 64) return int128_t(ASR((int64_t)a.upper(), n),
                                (a.upper()<<(64-n)) | (a.lower()>>n));
    else if (n == 64) return int128_t(-(int64_t)(a.upper()<0),
                                      a.upper());
    else if (n < 64) return int128_t(ASR((int64_t)a.upper(), n),
                                     (a.upper()<<(64-n)) | (a.lower()>>n));
    else return int128_t(-(int64_t)(a.upper()<0),
                         ASR(((int64_t)a.upper()), n-64));
}

inline int64_t NARROW128(const int128_t & a)
{   return (int64_t)a.lower();
}

// Produce quotient and remainder for signed values. I can take the
// absolute values of a and b as unsigned numbers. Note that the negations
// and divisions here are done as on unsigned values.

inline void divrem128(const int128_t & a, const int128_t & b,
                             int128_t & q, int128_t & r)
{   if ((int64_t)a.upper() < 0)
    {   if ((int64_t)b.upper() < 0) q = (-a)/(-b);
        else q = -((-a)/b);
    }
    else
    {   if ((int64_t)b.upper() < 0) q = -(a/(-b));
        else q = a/b;
    }
    r = a - q*b;
}

#endif // HAVE_NATIVE_INT128_T


#endif // header_int128_t_h

// end of int128_t.h
