// int128_t.h                              Copyright (C) 1990-2017 Codemist

#ifndef header_int128_t_h
#define header_int128_t_h 1


/**************************************************************************
 * Copyright (C) 2017, Codemist.                         A C Norman       *
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
// In the ueasy case it uses a built-in type, in the hard case it maps
// operations onto use of the 128-bit unsigned type that is supported
// in software.



#ifdef HAVE_NATIVE_INT128

static inline bool greaterp128(int128_t a, int128_t b)
{   return a > b;
}

static inline bool lessp128(int128_t a, int128_t b)
{   return a < b;
}

static inline bool geq128(int128_t a, int128_t b)
{   return a >= b;
}

static inline bool leq128(int128_t a, int128_t b)
{   return a <= b;
}

static inline int128_t ASL128(int128_t a, int n)
{   return (uint128_t)a << MAXSHIFT(n, int128_t);
}

#ifdef SIGNED_SHIFTS_ARE_ARITHMETIC

static inline int128_t ASR128(int128_t a, int n)
{   return a >> MAXSHIFT(n, int128_t);
}

#else // SIGNED_SHIFTS_ARE_ARITHMETIC

static inline int128_t ASR128(int128_t a, int n)
{   n = MAXSHIFT(n, int128_t);
    return (a & ~((uint128_t)1<<n - 1))/(int128_t)1<<n;
}

#endif // SIGNED_SHIFTS_ARE_ARITHMETIC

static inline int64_t NARROW128(int128_t a)
{   return (int64_t)a;
}

static inline void divrem128(int128_t a, int128_t b,
                             int128_t & q, int128_t & r)
{   uint128_t qq = a/b;
    q = qq;
    r = a - qq*b;
}

#else // HAVE_NATIVE_INT128_T

// Used if there is no native int128_t type available.

typedef uint128_t int128_t;

// assignment, +, -, *, &, |, ^, ~, == and != can all behave exactly
// the same when I think of a value as being signed.

// Ordered comparisons need special treatment. I will do them using
// verbosely names functions.

static inline bool greaterp128(const uint128_t & a, const uint128_t & b)
{   uint128_t aa(a.upper() ^ UINT64_C(0x8000000000000000), a.lower());
    uint128_t bb(b.upper() ^ UINT64_C(0x8000000000000000), b.lower());
    return aa > bb;
}

static inline bool lessp128(const uint128_t & a, const uint128_t & b)
{   uint128_t aa(a.upper() ^ UINT64_C(0x8000000000000000), a.lower());
    uint128_t bb(b.upper() ^ UINT64_C(0x8000000000000000), b.lower());
    return aa < bb;
}

static inline bool geq128(const uint128_t & a, const uint128_t & b)
{   uint128_t aa(a.upper() ^ UINT64_C(0x8000000000000000), a.lower());
    uint128_t bb(b.upper() ^ UINT64_C(0x8000000000000000), b.lower());
    return aa >= bb;
}

static inline bool leq128(const uint128_t & a, const uint128_t & b)
{   uint128_t aa(a.upper() ^ UINT64_C(0x8000000000000000), a.lower());
    uint128_t bb(b.upper() ^ UINT64_C(0x8000000000000000), b.lower());
    return aa <= bb;
}

static inline int128_t ASL128(const int128_t & a, int n)
{   n = MAXSHIFT(n, int128_t);
    if (n < 64) return
        int128_t((a.upper()<<n) | (a.lower()>>(64-n)),
                 a.lower()<<n);
    else if (n == 64) return int128_t(a.lower(), 0);
    else return int128_t(a.lower()<<(n-64), 0);
}

static inline int128_t ASR128(const int128_t & a, int n)
{   n = MAXSHIFT(n, int128_t);
    if (n < 64) return int128_t(ASR((int64_t)a.upper(), n),
                                (a.upper()<<(64-n)) | (a.lower()>>n));
    else if (n == 64) return int128_t(-(int64_t)(a.upper()<0),
                                      a.upper());
    else return int128_t(-(int64_t)(a.upper()<0),
                         ASR(((int64_t)a.upper()), n-64));
}

static inline int64_t NARROW128(const int128_t & a)
{   return (int64_t)a.lower();
}

// Produce quotient and remainder for signed values. I can take the
// absolute values of a and b as unsigned numbers. Note that the negations
// and divisions here are done as on unsigned values.

static inline void divrem128(const int128_t & a, const int128_t & b,
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
