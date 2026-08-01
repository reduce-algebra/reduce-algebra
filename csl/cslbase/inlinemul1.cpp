
inline constexpr std::size_t MUL_INLINE_LIMIT = 7;


inline void inlineMul_1_1(ConstDigitPtr a,
                          ConstDigitPtr b,
                          DigitPtr result)
{   multiply64(a[0], b[0], result[1], result[0]);
}

inline void inlineMul_2_1(ConstDigitPtr a,
                          ConstDigitPtr b,
                          DigitPtr result)
{   uint64_t dhi, dlo;
    multiply64(a[0], b[0], dlo, result[0]);
    dhi = 0;
    uint64_t whi, carry;
    carry = 0;
    multiply64(a[1], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[1] = dlo;
    dlo = dhi;
    dhi = carry;
    result[2] = dlo;
}

inline void inlineMul_2_2(ConstDigitPtr a,
                          ConstDigitPtr b,
                          DigitPtr result)
{   uint64_t dhi, dlo;
    multiply64(a[0], b[0], dlo, result[0]);
    dhi = 0;
    uint64_t whi, carry;
    carry = 0;
    multiply64(a[0], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    multiply64(a[1], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[1] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    multiply64(a[1], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[2] = dlo;
    dlo = dhi;
    dhi = carry;
    result[3] = dlo;
}

inline void inlineMul_3_1(ConstDigitPtr a,
                          ConstDigitPtr b,
                          DigitPtr result)
{   uint64_t dhi, dlo;
    multiply64(a[0], b[0], dlo, result[0]);
    dhi = 0;
    uint64_t whi, carry;
    carry = 0;
    multiply64(a[1], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[1] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    multiply64(a[2], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[2] = dlo;
    dlo = dhi;
    dhi = carry;
    result[3] = dlo;
}

inline void inlineMul_3_2(ConstDigitPtr a,
                          ConstDigitPtr b,
                          DigitPtr result)
{   uint64_t dhi, dlo;
    multiply64(a[0], b[0], dlo, result[0]);
    dhi = 0;
    uint64_t whi, carry;
    carry = 0;
    multiply64(a[0], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    multiply64(a[1], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[1] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    multiply64(a[1], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    multiply64(a[2], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[2] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    multiply64(a[2], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[3] = dlo;
    dlo = dhi;
    dhi = carry;
    result[4] = dlo;
}

inline void inlineMul_3_3(ConstDigitPtr a,
                          ConstDigitPtr b,
                          DigitPtr result)
{   uint64_t dhi, dlo;
    multiply64(a[0], b[0], dlo, result[0]);
    dhi = 0;
    uint64_t whi, carry;
    carry = 0;
    multiply64(a[0], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    multiply64(a[1], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[1] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    multiply64(a[0], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    multiply64(a[1], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    multiply64(a[2], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[2] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    multiply64(a[1], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    multiply64(a[2], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[3] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    multiply64(a[2], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[4] = dlo;
    dlo = dhi;
    dhi = carry;
    result[5] = dlo;
}

inline void inlineMul_4_1(ConstDigitPtr a,
                          ConstDigitPtr b,
                          DigitPtr result)
{   uint64_t dhi, dlo;
    multiply64(a[0], b[0], dlo, result[0]);
    dhi = 0;
    uint64_t whi, carry;
    carry = 0;
    multiply64(a[1], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[1] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    multiply64(a[2], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[2] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    multiply64(a[3], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[3] = dlo;
    dlo = dhi;
    dhi = carry;
    result[4] = dlo;
}

inline void inlineMul_4_2(ConstDigitPtr a,
                          ConstDigitPtr b,
                          DigitPtr result)
{   uint64_t dhi, dlo;
    multiply64(a[0], b[0], dlo, result[0]);
    dhi = 0;
    uint64_t whi, carry;
    carry = 0;
    multiply64(a[0], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    multiply64(a[1], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[1] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    multiply64(a[1], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    multiply64(a[2], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[2] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    multiply64(a[2], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    multiply64(a[3], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[3] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    multiply64(a[3], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[4] = dlo;
    dlo = dhi;
    dhi = carry;
    result[5] = dlo;
}

extern void inlineMul_4_3(ConstDigitPtr a,
                          ConstDigitPtr b,
                          DigitPtr result);

extern void inlineMul_4_4(ConstDigitPtr a,
                          ConstDigitPtr b,
                          DigitPtr result);

inline void inlineMul_5_1(ConstDigitPtr a,
                          ConstDigitPtr b,
                          DigitPtr result)
{   uint64_t dhi, dlo;
    multiply64(a[0], b[0], dlo, result[0]);
    dhi = 0;
    uint64_t whi, carry;
    carry = 0;
    multiply64(a[1], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[1] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    multiply64(a[2], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[2] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    multiply64(a[3], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[3] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    multiply64(a[4], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[4] = dlo;
    dlo = dhi;
    dhi = carry;
    result[5] = dlo;
}

inline void inlineMul_5_2(ConstDigitPtr a,
                          ConstDigitPtr b,
                          DigitPtr result)
{   uint64_t dhi, dlo;
    multiply64(a[0], b[0], dlo, result[0]);
    dhi = 0;
    uint64_t whi, carry;
    carry = 0;
    multiply64(a[0], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    multiply64(a[1], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[1] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    multiply64(a[1], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    multiply64(a[2], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[2] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    multiply64(a[2], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    multiply64(a[3], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[3] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    multiply64(a[3], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    multiply64(a[4], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[4] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    multiply64(a[4], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[5] = dlo;
    dlo = dhi;
    dhi = carry;
    result[6] = dlo;
}

extern void inlineMul_5_3(ConstDigitPtr a,
                          ConstDigitPtr b,
                          DigitPtr result);

extern void inlineMul_5_4(ConstDigitPtr a,
                          ConstDigitPtr b,
                          DigitPtr result);

extern void inlineMul_5_5(ConstDigitPtr a,
                          ConstDigitPtr b,
                          DigitPtr result);

inline void inlineMul_6_1(ConstDigitPtr a,
                          ConstDigitPtr b,
                          DigitPtr result)
{   uint64_t dhi, dlo;
    multiply64(a[0], b[0], dlo, result[0]);
    dhi = 0;
    uint64_t whi, carry;
    carry = 0;
    multiply64(a[1], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[1] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    multiply64(a[2], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[2] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    multiply64(a[3], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[3] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    multiply64(a[4], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[4] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    multiply64(a[5], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[5] = dlo;
    dlo = dhi;
    dhi = carry;
    result[6] = dlo;
}

extern void inlineMul_6_2(ConstDigitPtr a,
                          ConstDigitPtr b,
                          DigitPtr result);

extern void inlineMul_6_3(ConstDigitPtr a,
                          ConstDigitPtr b,
                          DigitPtr result);

extern void inlineMul_6_4(ConstDigitPtr a,
                          ConstDigitPtr b,
                          DigitPtr result);

extern void inlineMul_6_5(ConstDigitPtr a,
                          ConstDigitPtr b,
                          DigitPtr result);

extern void inlineMul_6_6(ConstDigitPtr a,
                          ConstDigitPtr b,
                          DigitPtr result);

inline void inlineMul_7_1(ConstDigitPtr a,
                          ConstDigitPtr b,
                          DigitPtr result)
{   uint64_t dhi, dlo;
    multiply64(a[0], b[0], dlo, result[0]);
    dhi = 0;
    uint64_t whi, carry;
    carry = 0;
    multiply64(a[1], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[1] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    multiply64(a[2], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[2] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    multiply64(a[3], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[3] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    multiply64(a[4], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[4] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    multiply64(a[5], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[5] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    multiply64(a[6], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[6] = dlo;
    dlo = dhi;
    dhi = carry;
    result[7] = dlo;
}

extern void inlineMul_7_2(ConstDigitPtr a,
                          ConstDigitPtr b,
                          DigitPtr result);

extern void inlineMul_7_3(ConstDigitPtr a,
                          ConstDigitPtr b,
                          DigitPtr result);

extern void inlineMul_7_4(ConstDigitPtr a,
                          ConstDigitPtr b,
                          DigitPtr result);

extern void inlineMul_7_5(ConstDigitPtr a,
                          ConstDigitPtr b,
                          DigitPtr result);

extern void inlineMul_7_6(ConstDigitPtr a,
                          ConstDigitPtr b,
                          DigitPtr result);

extern void inlineMul_7_7(ConstDigitPtr a,
                          ConstDigitPtr b,
                          DigitPtr result);

extern void inlineMul_8_8(ConstDigitPtr a,
                          ConstDigitPtr b,
                          DigitPtr result);

extern void inlineMul_9_9(ConstDigitPtr a,
                          ConstDigitPtr b,
                          DigitPtr result);

extern void inlineMul_10_10(ConstDigitPtr a,
                          ConstDigitPtr b,
                          DigitPtr result);

extern void inlineMul_11_11(ConstDigitPtr a,
                          ConstDigitPtr b,
                          DigitPtr result);

extern void inlineMul_12_12(ConstDigitPtr a,
                          ConstDigitPtr b,
                          DigitPtr result);

extern void inlineMul_13_13(ConstDigitPtr a,
                          ConstDigitPtr b,
                          DigitPtr result);

extern void inlineMul_14_14(ConstDigitPtr a,
                          ConstDigitPtr b,
                          DigitPtr result);

extern void inlineMul_15_15(ConstDigitPtr a,
                          ConstDigitPtr b,
                          DigitPtr result);

inline void inlineMul_1(ConstDigitPtr a, std::size_t N,
                        ConstDigitPtr b,
                        DigitPtr result)
{   Digit carry = 0, lo, hi = 0, hi1;
    multiply64(a[0], b[0], lo, result[0]);
    for (std::size_t k=1; k<N; k++)
    {
        multiply64(a[k-0], b[0], lo, hi1, lo);
        carry += addWithCarry(hi, hi1, hi);
        result[k] = lo;
        lo = hi;
        hi = carry;
        carry = 0;
    }
    result[N+0] = lo;
}

inline void inlineMul_2(ConstDigitPtr a, std::size_t N,
                        ConstDigitPtr b,
                        DigitPtr result)
{   Digit carry = 0, lo, hi = 0, hi1;
    multiply64(a[0], b[0], lo, result[0]);
    multiply64(a[0], b[1], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    multiply64(a[1], b[0], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    result[1] = lo;
    lo = hi;
    hi = carry;
    carry = 0;
    for (std::size_t k=2; k<N; k++)
    {
        multiply64(a[k-0], b[0], lo, hi1, lo);
        carry += addWithCarry(hi, hi1, hi);
        multiply64(a[k-1], b[1], lo, hi1, lo);
        carry += addWithCarry(hi, hi1, hi);
        result[k] = lo;
        lo = hi;
        hi = carry;
        carry = 0;
    }
    multiply64(a[N-1], b[1], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    result[N+0] = lo;
    lo = hi;
    hi = carry;
    carry = 0;
    result[N+1] = lo;
}

inline void inlineMul_3(ConstDigitPtr a, std::size_t N,
                        ConstDigitPtr b,
                        DigitPtr result)
{   Digit carry = 0, lo, hi = 0, hi1;
    multiply64(a[0], b[0], lo, result[0]);
    multiply64(a[0], b[1], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    multiply64(a[1], b[0], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    result[1] = lo;
    lo = hi;
    hi = carry;
    carry = 0;
    multiply64(a[0], b[2], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    multiply64(a[1], b[1], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    multiply64(a[2], b[0], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    result[2] = lo;
    lo = hi;
    hi = carry;
    carry = 0;
    for (std::size_t k=3; k<N; k++)
    {
        multiply64(a[k-0], b[0], lo, hi1, lo);
        carry += addWithCarry(hi, hi1, hi);
        multiply64(a[k-1], b[1], lo, hi1, lo);
        carry += addWithCarry(hi, hi1, hi);
        multiply64(a[k-2], b[2], lo, hi1, lo);
        carry += addWithCarry(hi, hi1, hi);
        result[k] = lo;
        lo = hi;
        hi = carry;
        carry = 0;
    }
    multiply64(a[N-1], b[1], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    multiply64(a[N-2], b[2], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    result[N+0] = lo;
    lo = hi;
    hi = carry;
    carry = 0;
    multiply64(a[N-1], b[2], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    result[N+1] = lo;
    lo = hi;
    hi = carry;
    carry = 0;
    result[N+2] = lo;
}

inline void inlineMul_4(ConstDigitPtr a, std::size_t N,
                        ConstDigitPtr b,
                        DigitPtr result)
{   Digit carry = 0, lo, hi = 0, hi1;
    multiply64(a[0], b[0], lo, result[0]);
    multiply64(a[0], b[1], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    multiply64(a[1], b[0], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    result[1] = lo;
    lo = hi;
    hi = carry;
    carry = 0;
    multiply64(a[0], b[2], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    multiply64(a[1], b[1], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    multiply64(a[2], b[0], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    result[2] = lo;
    lo = hi;
    hi = carry;
    carry = 0;
    multiply64(a[0], b[3], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    multiply64(a[1], b[2], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    multiply64(a[2], b[1], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    multiply64(a[3], b[0], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    result[3] = lo;
    lo = hi;
    hi = carry;
    carry = 0;
    for (std::size_t k=4; k<N; k++)
    {
        multiply64(a[k-0], b[0], lo, hi1, lo);
        carry += addWithCarry(hi, hi1, hi);
        multiply64(a[k-1], b[1], lo, hi1, lo);
        carry += addWithCarry(hi, hi1, hi);
        multiply64(a[k-2], b[2], lo, hi1, lo);
        carry += addWithCarry(hi, hi1, hi);
        multiply64(a[k-3], b[3], lo, hi1, lo);
        carry += addWithCarry(hi, hi1, hi);
        result[k] = lo;
        lo = hi;
        hi = carry;
        carry = 0;
    }
    multiply64(a[N-1], b[1], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    multiply64(a[N-2], b[2], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    multiply64(a[N-3], b[3], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    result[N+0] = lo;
    lo = hi;
    hi = carry;
    carry = 0;
    multiply64(a[N-1], b[2], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    multiply64(a[N-2], b[3], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    result[N+1] = lo;
    lo = hi;
    hi = carry;
    carry = 0;
    multiply64(a[N-1], b[3], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    result[N+2] = lo;
    lo = hi;
    hi = carry;
    carry = 0;
    result[N+3] = lo;
}

extern void inlineMul_5(ConstDigitPtr a, std::size_t N,
                        ConstDigitPtr b,
                        DigitPtr result);

extern void inlineMul_6(ConstDigitPtr a, std::size_t N,
                        ConstDigitPtr b,
                        DigitPtr result);

extern void inlineMul_7(ConstDigitPtr a, std::size_t N,
                        ConstDigitPtr b,
                        DigitPtr result);

inline void smallCaseMul(ConstDigitPtr a, std::size_t N,
                         ConstDigitPtr b, std::size_t M,
                         DigitPtr result)
{
// For this I will already have checked that both M and N are at most
// 7 and so that switch statement will cover all the possibilities and
// everything should then expand to inline code.
    switch (MUL_INLINE_LIMIT*N + M)
    {
        case 7*1+2:
            std::swap(a, b);
        case 7*2+1:
            inlineMul_2_1(a, b, result);
            return;
        case 7*2+2:
            inlineMul_2_2(a, b, result);
            return;
        case 7*1+3:
            std::swap(a, b);
        case 7*3+1:
            inlineMul_3_1(a, b, result);
            return;
        case 7*2+3:
            std::swap(a, b);
        case 7*3+2:
            inlineMul_3_2(a, b, result);
            return;
        case 7*3+3:
            inlineMul_3_3(a, b, result);
            return;
        case 7*1+4:
            std::swap(a, b);
        case 7*4+1:
            inlineMul_4_1(a, b, result);
            return;
        case 7*2+4:
            std::swap(a, b);
        case 7*4+2:
            inlineMul_4_2(a, b, result);
            return;
        case 7*3+4:
            std::swap(a, b);
        case 7*4+3:
            inlineMul_4_3(a, b, result);
            return;
        case 7*4+4:
            inlineMul_4_4(a, b, result);
            return;
        case 7*1+5:
            std::swap(a, b);
        case 7*5+1:
            inlineMul_5_1(a, b, result);
            return;
        case 7*2+5:
            std::swap(a, b);
        case 7*5+2:
            inlineMul_5_2(a, b, result);
            return;
        case 7*3+5:
            std::swap(a, b);
        case 7*5+3:
            inlineMul_5_3(a, b, result);
            return;
        case 7*4+5:
            std::swap(a, b);
        case 7*5+4:
            inlineMul_5_4(a, b, result);
            return;
        case 7*5+5:
            inlineMul_5_5(a, b, result);
            return;
        case 7*1+6:
            std::swap(a, b);
        case 7*6+1:
            inlineMul_6_1(a, b, result);
            return;
        case 7*2+6:
            std::swap(a, b);
        case 7*6+2:
            inlineMul_6_2(a, b, result);
            return;
        case 7*3+6:
            std::swap(a, b);
        case 7*6+3:
            inlineMul_6_3(a, b, result);
            return;
        case 7*4+6:
            std::swap(a, b);
        case 7*6+4:
            inlineMul_6_4(a, b, result);
            return;
        case 7*5+6:
            std::swap(a, b);
        case 7*6+5:
            inlineMul_6_5(a, b, result);
            return;
        case 7*6+6:
            inlineMul_6_6(a, b, result);
            return;
        case 7*1+7:
            std::swap(a, b);
        case 7*7+1:
            inlineMul_7_1(a, b, result);
            return;
        case 7*2+7:
            std::swap(a, b);
        case 7*7+2:
            inlineMul_7_2(a, b, result);
            return;
        case 7*3+7:
            std::swap(a, b);
        case 7*7+3:
            inlineMul_7_3(a, b, result);
            return;
        case 7*4+7:
            std::swap(a, b);
        case 7*7+4:
            inlineMul_7_4(a, b, result);
            return;
        case 7*5+7:
            std::swap(a, b);
        case 7*7+5:
            inlineMul_7_5(a, b, result);
            return;
        case 7*6+7:
            std::swap(a, b);
        case 7*7+6:
            inlineMul_7_6(a, b, result);
            return;
        case 7*7+7:
            inlineMul_7_7(a, b, result);
            return;
        default: arithlib_abort("bad smallCaseMul");
    }
}

extern void simpleMul(ConstDigitPtr a, size_t N,
                      ConstDigitPtr b, std::size_t M,
                      DigitPtr result);

inline void bigBySmallMul(ConstDigitPtr a, std::size_t N,
                          ConstDigitPtr b, std::size_t M,
                          DigitPtr result)
{   switch (M)
    {
        case 1:
            inlineMul_1(a, N, b, result); return;
        case 2:
            inlineMul_2(a, N, b, result); return;
        case 3:
            inlineMul_3(a, N, b, result); return;
        case 4:
            inlineMul_4(a, N, b, result); return;
        case 5:
            inlineMul_5(a, N, b, result); return;
        case 6:
            inlineMul_6(a, N, b, result); return;
        case 7:
            inlineMul_7(a, N, b, result); return;
        default: arithlib_abort("bad bigBySmallMul");
    }
}

inline void balancedMul(ConstDigitPtr a, ConstDigitPtr b, std::size_t N,
                        DigitPtr result)
{   switch (N)
    {   default: simpleMul(a, N, b, N, result); return;
        case 1:  inlineMul_1_1(a, b, result);   return;
        case 2:  inlineMul_2_2(a, b, result);   return;
        case 3:  inlineMul_3_3(a, b, result);   return;
        case 4:  inlineMul_4_4(a, b, result);   return;
        case 5:  inlineMul_5_5(a, b, result);   return;
        case 6:  inlineMul_6_6(a, b, result);   return;
        case 7:  inlineMul_7_7(a, b, result);   return;
        case 8:  inlineMul_8_8(a, b, result);   return;
        case 9:  inlineMul_9_9(a, b, result);   return;
        case 10:  inlineMul_10_10(a, b, result);   return;
        case 11:  inlineMul_11_11(a, b, result);   return;
        case 12:  inlineMul_12_12(a, b, result);   return;
        case 13:  inlineMul_13_13(a, b, result);   return;
        case 14:  inlineMul_14_14(a, b, result);   return;
        case 15:  inlineMul_15_15(a, b, result);   return;
    }
}
