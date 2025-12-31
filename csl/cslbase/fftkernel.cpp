
// fftkernel.cpp                                           Copyright 2025 A C Norman

// $Id$

/**************************************************************************
 * Copyright (C) 2026, Codemist.                         A C Norman       *
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


// Here I have the implementation of my FFT code - it is in a separate
// file here because at least on Intel platforms I am liable to compile it
// three times to provide versions suitable for different generations of CPU.
// In particular baseline, ones with SSE4.2 and ones with AVX. The idea is
// that for the more modern processors some SIMD operations can be used.


// First I have Decimation in Frequency where the vector length can
// be a power of 2 or three times a power of 2. I am taking the view that
// taking remainder operations by the prime P will be espensive so I try
// to reduce the number of them - first by separating out places where I
// would be multiplying by a twiddle factor of 1, and then by exploiting
// the fact that my prime is a bit less than 2^32 so I can combine two
// products before needing to take a remainder. Ie I go (u*v+w*x)%P rather
// than (u*v)%P + (w*x)%P followed by a test to see if the addition led
// to a vale >=P. 

template <uint32_t P, uint32_t cube_root>
static void DIF_FT(DigitPtr32 x, size_t N, DigitPtr32 omegas)
{   size_t M, co_M;
    if (N%3 == 0)
    {   M = N/3;
        Digit temp1 = times64(cube_root, x[M]);
        Digit temp2 = times64(cube_root, x[2*M]);
        Digit32 s = plusmod<P>(plusmod<P>(x[0], x[M]), x[2*M]);
        Digit32 t = (times64(P,P) + x[0] + temp1 - x[2*M] - temp2)%P;
        Digit32 u = (times64(P,P) + x[0] - x[M]  - temp1  + temp2)%P;
        x[0]   = s;
        x[M]   = t;
        x[2*M] = u;
        for (size_t n = 1; n<M; n++)
        {   temp1 = times64(cube_root, x[n+M]);
            temp2 = times64(cube_root, x[n+2*M]);
            s = plusmod<P>(plusmod<P>(x[n], x[n+M]), x[n+2*M]);
            t = (times64(P,P) + x[n] + temp1  - x[n+2*M] - temp2)%P;
            u = (times64(P,P) + x[n] - x[n+M] - temp1    + temp2)%P;
            x[n]     = s;
            x[n+M]   = timesmod<P>(t, omegas[n]);
            x[n+2*M] = timesmod<P>(u, omegas[2*n]);
        }
        co_M = 3;
    }
    else
    {   M = N;
        co_M = 1;
    }
    while (M%8 == 0)
    {   M = M/2;
// Here M = 4, 8, 16 etc so I can unroll the following loop by 4 and
// when I do that there is an enhanced prospect of the C++ compiler
// using 128-bit vectors and SIMD instructions to do the work.
        for (size_t k = 0; k<N; k+=2*M)
        {   for (size_t n = 0; n<M; n+=4)
            {   uint32_t u0 = x[n+0+k];
                uint32_t u1 = x[n+1+k];
                uint32_t u2 = x[n+2+k];
                uint32_t u3 = x[n+3+k];
                uint32_t v0 = x[n+0+k+M];
                uint32_t v1 = x[n+1+k+M];
                uint32_t v2 = x[n+2+k+M];
                uint32_t v3 = x[n+3+k+M];
                x[n+0+k]    = plusmod<P>(u0, v0);
                x[n+1+k]    = plusmod<P>(u1, v1);
                x[n+2+k]    = plusmod<P>(u2, v2);
                x[n+3+k]    = plusmod<P>(u3, v3);
                uint32_t t0 = u0 + P - v0;
                uint32_t t1 = u1 + P - v1;
                uint32_t t2 = u2 + P - v2;
                uint32_t t3 = u3 + P - v3;
                x[n+0+M+k] = timesmod<P>(t0, omegas[(n+0)*co_M]);
                x[n+1+M+k] = timesmod<P>(t1, omegas[(n+1)*co_M]);
                x[n+2+M+k] = timesmod<P>(t2, omegas[(n+2)*co_M]);
                x[n+3+M+k] = timesmod<P>(t3, omegas[(n+3)*co_M]);
            }
        }
        co_M = 2*co_M;
    }
    while (M != 1)
    {   M = M/2;
        for (size_t k = 0; k<N; k+=2*M)
        {   Digit32 s = plusmod<P>(x[k], x[k+M]);
            Digit32 t = differencemod<P>(x[k], x[k+M]);
            x[k]   = s;
            x[M+k] = t;
            for (size_t n = 1; n<M; n++)
            {   s = plusmod<P>(x[n+k], x[n+k+M]);
                t = x[n+k] + P - x[n+k+M];
                x[n+k]   = s;
                x[n+M+k] = timesmod<P>(t, omegas[n*co_M]);
            }
        }
        co_M = 2*co_M;
    }
#ifdef PRINT
    prinvec("dif_ft", x, N);
#endif
}

// Decimation in Frequency here uses the inverse of the root of unity
// used above (and the other complex cube root of unity) amd so provides
// an inverse transform.

template <uint32_t P, uint32_t cube_root>
static void DIT_FT(DigitPtr32 x, size_t N, DigitPtr32 omegas)
{   size_t M = 1;
    size_t co_M = N;
    while (co_M%2 == 0 && M<4)
    {   co_M = co_M/2;
        for (size_t k = 0; k<N; k+=2*M)
        {   Digit32 s = x[k];
            Digit32 t = x[k+M];
            x[k] = plusmod<P>(s, t);
            x[k+M] = differencemod<P>(s, t);
            for (size_t n = 1; n<M; n++)
            {   s = x[k+n];
                t = timesmod<P>(x[k+n+M], omegas[n*co_M]);
                x[k+n] = plusmod<P>(s, t);
                x[k+n+M] = differencemod<P>(s, t);
            }
        }
        M = 2*M;
    }
    while (co_M%2 == 0)
    {   co_M = co_M/2;
// M is at least 4 and has been got to that state by being doubled. So
// here I can unroll the inner loop by a factor of 4. As before this may
// help a C++ compiler use SIMD operations.
        for (size_t k = 0; k<N; k+=2*M)
        {   assert(M%4 == 0);
            for (size_t n = 0; n<M; n+=4)
            {   Digit32 s0 = x[k+n+0];
                Digit32 s1 = x[k+n+1];
                Digit32 s2 = x[k+n+2];
                Digit32 s3 = x[k+n+3];
                Digit32 t0 = timesmod<P>(x[k+n+0+M], omegas[(n+0)*co_M]);
                Digit32 t1 = timesmod<P>(x[k+n+1+M], omegas[(n+1)*co_M]);
                Digit32 t2 = timesmod<P>(x[k+n+2+M], omegas[(n+2)*co_M]);
                Digit32 t3 = timesmod<P>(x[k+n+3+M], omegas[(n+3)*co_M]);
                x[k+n+0] = plusmod<P>(s0, t0);
                x[k+n+1] = plusmod<P>(s1, t1);
                x[k+n+2] = plusmod<P>(s2, t2);
                x[k+n+3] = plusmod<P>(s3, t3);
                x[k+n+0+M] = differencemod<P>(s0, t0);
                x[k+n+1+M] = differencemod<P>(s1, t1);
                x[k+n+2+M] = differencemod<P>(s2, t2);
                x[k+n+3+M] = differencemod<P>(s3, t3);
            }
        }
        M = 2*M;
    }
    if (co_M == 3)
    {   Digit32 s = x[0];
        Digit32 t = x[M];
        Digit32 u = x[2*M];
        Digit temp1 = times64(cube_root, t);
        Digit temp2 = times64(cube_root, u);
        x[0]   = plusmod<P>(plusmod<P>(s, t), u);
        x[M]   = (times64(P,P) + s + temp1 - u     - temp2)%P;
        x[2*M] = (times64(P,P) + s - t     - temp1 + temp2)%P;
        for (size_t n = 1; n<M; n++)
        {   s = x[n];
            t = timesmod<P>(x[n+M], omegas[n]);
            u = timesmod<P>(x[n+2*M], omegas[2*n]);
            temp1 = times64(cube_root, t);
            temp2 = times64(cube_root, u);
            x[n]     = plusmod<P>(plusmod<P>(s, t), u);
            x[n+M]   = (times64(P,P) + s + temp1 - u     - temp2)%P;
            x[n+2*M] = (times64(P,P) + s - t     - temp1 + temp2)%P;
        }
    }
}

