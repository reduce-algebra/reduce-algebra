// A second (or third!) attempt at general multiplication for large
// integers.

// Overall plan:
//    (1) Cases from 1x1 to 7x7 are dealt with using special code
//        in the hope that those small cases can be handled really
//        fast. I unroll and inline everything. Also cases of Nx1 to
//        Nx7 have their inner x1 to x7 loops unrolled.
//    (2) min(N,M)<=threshold. Use simple long multiplication because
//        anything like Karatsuba will not pay off.
//    (3) N>1.5*M or M>1.5*N and the smaller is >7. Do a sequence of
//        MxM multiplications until the residual N is small enough
//        that a different case applies.
//    (5) If N,M and less than another threshold do Karatsuba rather as if
//        NxN. Because of the threshold I have a known bound on workspace
//        needs so use fixed size stack allocated workspace.
//    (6) Use 3-thread Karatsuba with workspace allocation via my
//        "stkvector" scheme. Or 4-thread Toom32.
//
// Possibly consider Toom23 for some unbalanced cases. This would be based
// on (a*x^2+b*x+c)*(d*x+e) having 4 digits in its result and obtaining those
// via interpolation base on evaluations at 0, -1, +1 and infinity. The
// idea here is that it would then be possible to guarantee that cases
// proceeding beyound step 3 above would have the two numbers closer to
// each other in length.

// So the chain of functions goes
//     generalMul(a, N, b, M, result)         entrypoint
//       oneWordMul                           1*1
//       smallCaseMul                         up to 7x7
//       bigBySmallMul                        up to 7*x
//       balancedMul                          8*8 to 14*14
//       simpleMul                            classical method
//       biggerMul                            as it says!
// The oddest looking choice for a special case is that of 8*8 to 14*14.
// I cite three use-cases for multiplications of equal sized numbers:
// (1) Within an implementation of extended precision floating point;
// (2) Modular arithmetic where the modulus is that large;
// (3) Base cases for Karatsuba, where many of the sub-products are of
//     equal-sized values and ones that are small enough not to call
//     for further Karatsuba-style decomosition get caught here.
//
//     biggerMul(a, N, b, M, result)
//       unbalancedMul                        3N > 2M
//       threeByTwoMul
//       kara
//
//     kara                                   N>=some threshold Ks
//       kara                                 2 or 3 times
//       generalMul
//
//     threeByTwoMul
//       kara
//       generalMul
//


// I hide almost all of the functions here as private within this
// class as a way of controlling the namespace and also so that
// if some of the functions are only used once there is a chance for
// compilers to notice this fact.

#include <atomic>

class BigMultiplication
{

public:

// I need some commentary about this! I have three worker threads
// available and a multiplication can decompose either a 2N by 2N
// multiplication into 3 tasks or a 3N by 2N one into 4 tasks.
// If the caller is a multi-threaded program then several of those
// threads might each start to perform a multiplication, but I need to
// ensure that only one of them gets to use the worker threads.
// To achieve this I have an atomic variable threadsInUse and I
// use a compare_exchange operation that will always end up with it
// having the value true, but that leaves mayUseThreads true if it had
// initially been false. The class destructor for ManageWorkers ensures
// that when a scope where use of the worker threads exits the access
// control flag is reset. Using compare_exchange_weak means that requests
// for access to the workers may spuriously fail (!) but the _strong
// version may have higher overheads. On architectures where there is
// a genuine compare-exchange function the spurious failure will not arise,
// but on machines where atomic access is supported using load-locked
// and store-conditional combinations (eg arm processors, including code
// compiled for aarch64 before version 8.1) the store conditional can be
// rejected because some other activity has touched the memory - even if
// the value in the memory is the "expected" one. This can lead the
// compare_exchange to report failure even in a case that could have been
// deemed a success. With low contention this will hardly ever happen!

class ManageWorkers
{
public:
    static std::atomic<bool> threadsInUse;
    bool mayUseThreads;
    ManageWorkers()
    {   bool expected = false;
        mayUseThreads = threadsInUse.compare_exchange_weak(expected, true);
    }
    ~ManageWorkers()
    {   if (mayUseThreads) threadsInUse.store(false);
    }
};

private:

// Set (hi,lo) to the 128-bit product of a by b.

// Ha ha - because this is a method defined within a class the word
// "static" implies "inline" in that the class definition may be included
// in multiple compilation units but only one copy of the method is liable
// to arise.

static void oneWordMul(std::uint64_t a, std::uint64_t b,
                       std::uint64_t &hi, std::uint64_t &lo)
{   UINT128 r = static_cast<UINT128>(a)*static_cast<UINT128>(b);
    hi = static_cast<std::uint64_t>(r >> 64);
    lo = static_cast<std::uint64_t>(r);
}

// Now much the same but forming a*b+c. Note that this can not overflow
// the 128-bit result. Both hi and lo are only updated at the end
// of this, and so they are allowed to be the same as input arguments.

static void oneWordMul(std::uint64_t a, std::uint64_t b,
                       std::uint64_t c,
                       std::uint64_t &hi, std::uint64_t &lo)
{   UINT128 r = static_cast<UINT128>(a)*static_cast<UINT128>(b) +
                static_cast<UINT128>(c);
    hi = static_cast<std::uint64_t>(r >> 64);
    lo = static_cast<std::uint64_t>(r);
}

// The version here has to have N>=M but given that the loops on i
// all have a simpler starting condition and a single test for their
// end condition. Here is a fine case where a "sufficiently smart compiler"
// could take the above commented out code and split the loop into three
// just as I have done here. But until that is available I make
// transformations of this sort for myself.

// verySimpleMul exists ONLY for testing - specifically to generate
// reference products that the output from other more complicated code
// can be compared against.

public:

static void verySimpleMul(ConstDigitPtr a, std::size_t N,
                          ConstDigitPtr b, std::size_t M,
                          DigitPtr result)
{   Digit carry = 0, lo = 0, hi = 0;
    for (std::size_t k=0; k<N+M-1; k++)
    {   for (std::size_t i=0; i<N; i++)
        {   if (k < i) continue;
            if (k-i >= M) continue;
            Digit hi1;
            oneWordMul(a[i], b[k-i], lo, hi1, lo);
            carry += ((hi += hi1) < hi1);
        }
        result[k] = lo;
        lo = hi;
        hi = carry;
        carry = 0;
    }
    result[N+M-1] = lo;
}

private:

// I have a general idiom I intend to use for loops where the
// body of the iteration is small. If one has
//     for (i=A; i<B; i++) { X(i); }
// I will unroll the loop, writing
//     for (i=A; i<B-1; i+=2)
//     {   X(i);
//         X(i+1);
//     }
//     if (i<B) { X(i); i++; }
// This adds to the cost if the loop is traversed only once, is broadly
// cost neutral if it is traversed twice and from there up it saves tests
// and control-flow. Of course it increases code bulk. 

// Here I have classical multiplication for the case N>=M and as
// used here M>7. This is written out as succession of 3 loops since
// that leads to each having simpler start and end conditions, and I
// hope that reduces overhead.

static void simpleMul(ConstDigitPtr a, std::size_t N,
                      ConstDigitPtr b, std::size_t M,
                      DigitPtr result)
{
// For this I will require N>=M
    Digit carry = 0, lo, hi = 0, hi1;
// The lowest Digit can be handled specially to get things going.
    oneWordMul(a[0], b[0], lo, result[0]);
    std::size_t k=1;
    for (; k<M; k++)
    {   std::size_t i;
// Here I want k<M<=N so certainly if i<k then i<N
//@@    for (i=0; i<=k; i++)
//@@    {   oneWordMul(a[i], b[k-i], lo, hi1, lo);
//@@        carry += addWithCarry(hi, hi1, hi);
//@@    }
        for (i=0; i<=k-1; i+=2)
        {   oneWordMul(a[i], b[k-i], lo, hi1, lo);
            carry += addWithCarry(hi, hi1, hi);
            oneWordMul(a[i+1], b[k-i-1], lo, hi1, lo);
            carry += addWithCarry(hi, hi1, hi);
        }
        if (i<=k)
        {   oneWordMul(a[i], b[k-i], lo, hi1, lo);
            carry += addWithCarry(hi, hi1, hi);
        }
        result[k] = lo;
        lo = hi;
        hi = carry;
        carry = 0;
    }
// Now k>=M, I want i<=k to imply i<N so go as far as k<N
    for (; k<N; k++)
    {
//@@    for (std::size_t j=0; j<M; j++)
//@@    {
//@@ // Ha ha in this loop I iterate on j=k-i which makes the loop
//@@ // just a little nicer to express.
//@@        oneWordMul(a[k-j], b[j], lo, hi1, lo);
//@@        carry += addWithCarry(hi, hi1, hi);
//@@    }
        std::size_t j;
        for (j=0; j<M-1; j+=2)
        {   oneWordMul(a[k-j], b[j], lo, hi1, lo);
            carry += addWithCarry(hi, hi1, hi);
            oneWordMul(a[k-j-1], b[j+1], lo, hi1, lo);
            carry += addWithCarry(hi, hi1, hi);
        }
        if (j<M)
        {   oneWordMul(a[k-j], b[j], lo, hi1, lo);
            carry += addWithCarry(hi, hi1, hi);
        }
        result[k] = lo;
        lo = hi;
        hi = carry;
        carry = 0;
    }
// Finally k>=N so i<N will imply i<=k
    for (; k<N+M-1; k++)
    {
//@@    for (std::size_t i=k+1-M; i<N; i++)
//@@    {   oneWordMul(a[i], b[k-i], lo, hi1, lo);
//@@        carry += addWithCarry(hi, hi1, hi);
//@@    }
        std::size_t i;
        for (i=k+1-M; i<N-1; i+=2)
        {   oneWordMul(a[i], b[k-i], lo, hi1, lo);
            carry += addWithCarry(hi, hi1, hi);
            oneWordMul(a[i+1], b[k-i-1], lo, hi1, lo);
            carry += addWithCarry(hi, hi1, hi);
        }
        if (i<N)
        {   oneWordMul(a[i], b[k-i], lo, hi1, lo);
            carry += addWithCarry(hi, hi1, hi);
        }
        result[k] = lo;
        lo = hi;
        hi = carry;
        carry = 0;
    }
// The very final digit of the result drops out here.
    result[k] = lo;
}


// Multiplications where M and N are both no more than than 7
// are done by unrolled and inlined special code.
// From when the larger is at least KARASTART I will use Karatsuba,
// and from KARABIG on it will not be just Karatsuba but the top
// level decomosition will be run using three threads. Also up as
// far as KARABIG I will use some stack allocated space while from
// there up I will use my "stkvector" scheme so that there is no
// serious limit to the amount that can be used.

static const std::size_t MUL_INLINE_LIMIT = 7;

public:
#ifdef START
static const std::size_t KARASTART        = START;
#else
static const std::size_t KARASTART        = 15;
#endif

#ifdef BIG
static const std::size_t KARABIG          = BIG;
#else
static const std::size_t KARABIG          = 60;
#endif
private:

// Now I want code for multiplying N*M digit numbers with N up to some
// small limit as fast as I can. Here I have all the cases with both
// N and M up to 7 covered. Also cases where N=M<=14 and ones where
// M<=7 but N can be arbitrary. These cases represent bulky and perhaps
// ugly in-line code but I expect them to be the most performance
// critical parts of the base for multiplication.

#include "inlinemul.cpp"

// The vector a has M digits and result has N (with N>=M). Add the
// value in a into result and return any carry.

static Digit addMdigits(ConstDigitPtr a, std::size_t M, DigitPtr result, std::size_t N)
{   Digit carry = addWithCarry(a[0], result[0], result[0]);
    std::size_t i=1;
//@@for (; i<M; i++)
//@@    carry = addWithCarry(a[i], result[i], carry, result[i]);
    for (; i<M-1; i+=2)
    {   carry = addWithCarry(a[i], result[i], carry, result[i]);
        carry = addWithCarry(a[i+1], result[i+1], carry, result[i+1]);
    }
    if (i<M)
    {   carry = addWithCarry(a[i], result[i], carry, result[i]);
        i++;
    }
    while (carry != 0 && i<N)
    {   carry = addWithCarry(result[i], 1, result[i]);
        i++;
    }
    return carry;
}

public:

// Some of the functions here have are tempalated with a boolean
// called "thread". When this is true the code is entitled to cause
// worker threads to be launched to perform subsidiary multiplications.
// The multi-thread decomposition may only happen once, and that is enforced
// by making thread=false for all the lower level calls.

// Now the main entrypoint to my new code for multiplying
// unsigned values. It tries to put simple cheap tests to spot
// cheap cases inline and then dispatch to the separate procedures
// that apply in each case.
// The small cases covered here are liable to get expanded in line
// in rather extreme manners!

[[gnu::always_inline]]
static void generalMul(ConstDigitPtr a, std::size_t N,
                       ConstDigitPtr b, std::size_t M,
                       DigitPtr result)
{
// I take a view that case of single word multiplication as both so
// special and so important that I do that in-line here.
    if ((N|M) == 1)
    {   oneWordMul(a[0], b[0], 0, result[1], result[0]);
        return;
    }
// I next have special treatment for all the cases where both M and N are
// at most 7. I make the cut off there because I can test if either N
// or M exceeds the bound using a bitwide OR here which I expect to be
// nice and cheap! Also because I expect small cases like this to be
// especially commonly used, and to be ones where loop overheads might
// intrude.
    if ((N|M) <= 7)
    {   LIKELY
        smallCaseMul(a, N, b, M, result);
        return;
    }
    if (N < M)
    {   std::swap(a, b);
        std::swap(N, M);
    }
// If the smaller number is fairly small I again use classical long
// multiplication, but with the inner loop unrolled.
    if (M <= 7)
    {   bigBySmallMul(a, N, b, M, result);
        return;
    }
    if (N < KARASTART)    // Too small for Karatsuba.
    {   if (N==M && N<=14) balancedMul(a, b, N, result);
        else simpleMul(a, N, b, M, result);
    }
    else biggerMul(a, N, b, M, result);
}

private:

template <bool threads>
[[gnu::always_inline]]
static void unbalancedMul(ConstDigitPtr a, std::size_t N,
                          ConstDigitPtr b, std::size_t M,
                          DigitPtr result)
{
// Here N is (much) bigger than M
    generalMul(a, M, b, M, result);
    N -= M;
    a += M;
    result += M;
    stkvector<Digit> temp(M);
    while (2*N > 3*M)
    {   std::memcpy(temp, result, M*sizeof(Digit));
        generalMul(a, M, b, M, result);
// Now add M digits from temp into the 2M digit number in result. There
// can not be an overflow.
        addMdigits(temp, M, result, 2*M);
        N -= M;
        a += M;
        result += M;
    }
    if (N != 0)
    {   std::memcpy(temp, result, M*sizeof(Digit));
        generalMul(a, N, b, M, result);
// Now add M digits from temp into the M+N digit number in result. There
// can not be an overflow.
        addMdigits(temp, M, result, M+N);
    }
}

// Some sub-functions that I will need that add, subtract and halve
// integers and arrange associated carries and borrows.

[[gnu::always_inline]]
static Digit karaAdd(ConstDigitPtr a, std::size_t lenA,
                     ConstDigitPtr b, std::size_t lenB,
                     Digit carry,
                     DigitPtr result)
{   std::size_t i;
#ifdef DEBUG
    assert(lenA >= lenB);
#endif
    for (i=0; i<lenB-1; i+=2)
    {   carry = addWithCarry(a[i], b[i], carry, result[i]);
        carry = addWithCarry(a[i+1], b[i+1], carry, result[i+1]);
    }
    if (i<lenB)
    {   carry = addWithCarry(a[i], b[i], carry, result[i]);
        i++;
    }
    for (; i<lenA; i++)
        carry = addWithCarry(a[i], carry, result[i]);
    return carry;
}

[[gnu::always_inline]]
static Digit karaAdd(ConstDigitPtr a, std::size_t lenA,
                     ConstDigitPtr b, std::size_t lenB,
                     DigitPtr result)
{   return karaAdd(a, lenA, b, lenB, 0, result);
}


[[gnu::always_inline]]
static Digit karaSubtract(ConstDigitPtr a, std::size_t lenA,
                          ConstDigitPtr b, std::size_t lenB,
                          DigitPtr result)
{   Digit borrow = 0;
#ifdef DEBUG
    assert(lenA >= lenB);
#endif
    std::size_t i;
    for (i=0; i<lenB-1; i+=2)
    {   borrow = subtractWithBorrow(a[i], b[i], borrow, result[i]);
        borrow = subtractWithBorrow(a[i+1], b[i+1], borrow, result[i+1]);
    }
    if (i<lenB)
    {   borrow = subtractWithBorrow(a[i], b[i], borrow, result[i]);
        i++;
    }
    for (; i<lenA; i++)
        borrow = subtractWithBorrow(a[i], 0, borrow, result[i]);
    return borrow;
}

[[gnu::always_inline]]
static Digit karaRevSubtract(ConstDigitPtr a, std::size_t lenA,
                          ConstDigitPtr b, std::size_t lenB,
                          DigitPtr result)
{   Digit borrow = 0;
#ifdef DEBUG
    assert(lenA >= lenB);
#endif
    std::size_t i;
    for (i=0; i<lenB-1; i+=2)
    {   borrow = subtractWithBorrow(b[i], a[i], borrow, result[i]);
        borrow = subtractWithBorrow(b[i+1], a[i+1], borrow, result[i+1]);
    }
    if (i<lenB)
    {   borrow = subtractWithBorrow(b[i], a[i], borrow, result[i]);
        i++;
    }
    for (; i<lenA; i++)
        borrow = subtractWithBorrow(0, a[i], borrow, result[i]);
    return borrow;
}

[[gnu::always_inline]]
static void karaCarry(Digit carry, DigitPtr v)
{   size_t i = 0;
    while (carry != 0)
    {   carry = addWithCarry(v[i], carry, v[i]);
        i++;
    }
}

[[gnu::always_inline]]
static void karaBorrow(Digit borrow, DigitPtr v)
{   size_t i = 0;
    while (borrow != 0)
    {   borrow = subtractWithBorrow(v[i], borrow, v[i]);
        i++;
    }
}

static SignedDigit karaHalve(SignedDigit top, DigitPtr a, std::size_t len)
{   Digit carry = top & 1;
    top = top - carry;
    for (size_t i=len-1; i!=0; i--)
    {   Digit w = a[i];
        a[i] = (w>>1) | (carry<<63);
        carry = w & 1;
    }
    a[0] = (a[0]>>1) | (carry<<63);
    return top/2;
}

// I have special code for multiplying N*M numbers when N is about
// 1.5 times M. This splits the big number into 3 chunks and the
// smaller into two.

// Here is a description of the procedure in nice readable compact form.
//
// a := ahigh*x^2 + amid*x + alow;
// b :=            bhigh*x + blow;
//
// x^3 * (ahigh*bhigh) +
// x^2 * (ahigh*blow + amid*bhigh) +
// x   * (alow*bhigh + amid*blow) +
//       (alow*blow)
//
// asum := ahigh+amid+alow;
// bsum := bhigh+blow;
// adiff := ahigh-amid+alow;
// bdiff := blow-bhigh;
// p0 := alow*blow;
// p1 := asum*bsum;
// p2 := adiff*bdiff;
// p3 := ahigh*bhigh;
//
// d0 := p0;                         alow*blow
// d1 := (p1 - p2)/2 - p3;           alow*bhigh + amid*blow
// d2 := (p1 + p2)/2 - p0;           ahigh*blow + amid*bhigh
// d3 := p3;                         ahigh*bhigh

// This divides a value by 2, where the value has a signed top digit
// and a vector of unsigned additional digits.

template <bool thread=false>
static void threeByTwoMul(ConstDigitPtr a, std::size_t N,
                          ConstDigitPtr b, std::size_t M,
                          DigitPtr c)
{
// I will start by viewing a as (ahigh, amid, alow) and b as (bhigh, blow)
// where amid, alow, blow all have the same size (toomLen). Then
// ahigh and bhigh need to have at least some digits but may not have more
// then toomLen.
// I let a(t) = ahigh*t^2 + anid*t + alow and b(t) - bhigh*t + blow.
// then I evaluate a() and b() at 0, +1, -1 and infinity - and I can
// interpolate through products of those values to get digits for my result.
// A classical 3x2 multiplication would use 6 partial products - this uses
// just 4 but obviously a bunch of extra additions and subtractions together
// with some general overhead. 
    size_t toomLen = (M+1)/2;
    size_t lenALow = toomLen;
    size_t lenAMid = toomLen;
    assert(N > 2*toomLen);
    size_t lenAHigh = N-2*toomLen;
    assert(lenAHigh <= toomLen);
    size_t lenBLow = toomLen;
    size_t lenBHigh = M-toomLen;
    ConstDigitPtr aLow = a;
    ConstDigitPtr aMid = a + toomLen;
    ConstDigitPtr aHigh = aMid + toomLen;
    ConstDigitPtr bLow = b;
    ConstDigitPtr bHigh = b + toomLen;
// Now we have
//     a = (aHigh*B^2, aMid*B, aLow)
//     b = (bHigh*B, bLow)
// and I will need to compute
//     aSum = aHigh + aMid + Alow   (c = 0, 1, 2)
//     bSum = bHigh + blow          (c = 0, 1)
// and
//     aDiff = aHigh - aMid + aLow  (c = -1, 0, 1)
//     bDiff = bLow - bHigh         (c = 0, -1)
//
// Next
//     P0 = aLow*bLow
//     P1 = aSum*bSum
//     P2 = aDiff*bDiff
//     P3 = aHigh*bHigh
// I will use the result space as workspace to start with.
    DigitPtr P0 = c;
    DigitPtr P1 = c;                 SignedDigit P1Top;
    stkvector<Digit> D1(thread ? 8*toomLen :4*toomLen); SignedDigit D1Top;
    DigitPtr D2 = D1 + 2*toomLen;    SignedDigit D2Top; 
    DigitPtr P2 = c + 2*toomLen;     SignedDigit P2Top; 
    DigitPtr P3 = c + 3*toomLen;
    if constexpr (thread)
    {   P2 = D1 + 4*toomLen;
        P3 = D1 + 6*toomLen;
    }
    DigitPtr aSum = D1;              Digit aSumTop;
    DigitPtr aDiff = D1 + toomLen;   SignedDigit aDiffTop;
    DigitPtr bSum = D2;              Digit bSumTop;
    DigitPtr bDiff = D2 + toomLen;   SignedDigit bDiffTop; 
    aSumTop = karaAdd(aLow, toomLen, aHigh, lenAHigh, aSum);
    aDiffTop = aSumTop - karaSubtract(aSum, toomLen, aMid, toomLen, aDiff);
    aSumTop += karaAdd(aMid, toomLen, aSum, toomLen, aSum);
    bSumTop = karaAdd(bLow, toomLen, bHigh, lenBHigh, bSum);
    bDiffTop = -karaSubtract(bLow, toomLen, bHigh, lenBHigh, bDiff);
    if constexpr (thread)
    {   setupKara(driverData.wd_0, aSum, toomLen, bSum, toomLen, P1);
        setupKara(driverData.wd_1, aDiff, toomLen, bDiff, toomLen, P2);
// In this case to use all available threads I will be computing P0 and P3
// now. That means I can not use their memory as workspace, which is
// what I do in the purely sequential case.
        setupKara(driverData.wd_2, aLow, toomLen, bLow, toomLen, P0);
        driverData.releaseWorkers(true);
            generalMul(aHigh, lenAHigh, bHigh, lenBHigh, P3);
        driverData.wait_for_workers(true);
    }
    else
    {   generalMul(aSum, toomLen, bSum, toomLen, P1);
//      + aSumTop*bSum + bSumTop*aSum + aSumTop*bSumTop
        generalMul(aDiff, toomLen, bDiff, toomLen, P2);
//      + aDiffTop*bDiff + bDiffTop*aDiff + aDiffTop*bDiffTop
// noting that aDiffTop and bDiffTop are signed values.
    }
    P1Top = 0;
    switch (aSumTop)
    {   case 2:
            P1Top = karaAdd(bSum, toomLen, P1+toomLen, toomLen, P1+toomLen);
            [[fallthrough]];
        case 1:
            P1Top += karaAdd(bSum, toomLen, P1+toomLen, toomLen, P1+toomLen);
            break;
        case 0:
            break;
    }
    if (bSumTop != 0)
        P1Top += karaAdd(aSum, toomLen, P1+toomLen, toomLen, P1+toomLen);
    P1Top += aSumTop*bSumTop;   
    P2Top = 0;
    switch (aDiffTop)
    {   case 1:
            P2Top = karaAdd(bDiff, toomLen, P2+toomLen, toomLen, P2+toomLen);
            break;
        case -1:
            P2Top = -karaSubtract(P2+toomLen, toomLen,
                                  bDiff, toomLen, P2+toomLen);
            break;
        case 0:
            break;
    }        
    switch (bDiffTop)
    {   case -1:
            P2Top -= karaSubtract(P2+toomLen, toomLen,
                                  aDiff, toomLen, P2+toomLen);
        break;
    }
    P2Top += aDiffTop*bDiffTop;   
// Now set D1 = P1-P2, D2=P1+P2
    D1Top = P1Top - P2Top - karaSubtract(P1, 2*toomLen, P2, 2*toomLen, D1);
    D2Top = P1Top + P2Top + karaAdd(P1, 2*toomLen, P2, 2*toomLen, D2);
// Halve both of these
    D1Top = karaHalve(D1Top, D1, 2*toomLen);
    D2Top = karaHalve(D2Top, D2, 2*toomLen);
    if constexpr (thread) // These already computed in the threaded version
    {   generalMul(aLow, toomLen, bLow, toomLen, P0);
        generalMul(aHigh, lenAHigh, bHigh, lenBHigh, P3);
    }
// I need to D1 -= P3; D2 -= P0;
    D1Top -= karaSubtract(D1, 2*toomLen, P3, lenAHigh+lenBHigh, D1);
    D2Top -= karaSubtract(D2, 2*toomLen, P0, 2*toomLen, D2);
// Now to assemble the final result I just need to cope with the fact
// the the partial products P0, D1, D1 and P3 overlap.
// So now I have
//   c:     P3hi  P3lo   xxx   P0Hi P0Lo
//                D1Top  D1Hi  D1Lo
//          D2Top D2Hi   D2Low
    Digit carry = karaAdd(D1, toomLen,            // D1Lo
                          c+toomLen, toomLen,     // P0Hi
                          c+toomLen);
    carry = karaAdd(D1+toomLen, toomLen,          // D1Hi
                    D2, toomLen, carry,           // D2Lo
                    c+2*toomLen);
    carry = karaAdd(D2+toomLen, toomLen,          // D2Hi
                    c+3*toomLen, toomLen, carry,  // P3Lo
                    c+3*toomLen);
    // karaCarry(carry, c+4*toomLen); by adding carry into D2Top I do this
    D2Top += carry;
// I need to merge in D1Top and D2TOP. Note that either could be positive
// or negative, and that is part of why I did not merge them in earlier.
    if (D1Top > 0)      karaCarry(D1Top, c+3*toomLen);
    else if (D1Top < 0) karaBorrow(-D1Top, c+3*toomLen);
    if (D2Top > 0)      karaCarry(D2Top, c+4*toomLen);
    else if (D2Top < 0) karaBorrow(-D2Top, c+4*toomLen);
}

static void biggerMul(ConstDigitPtr a, std::size_t N,
                      ConstDigitPtr b, std::size_t M,
                      DigitPtr result)
{   ManageWorkers manager;
// Now manager.mayUseThreads will be true if I am allowed to use the
// worker threads.
//
// Now look at out-of balance cases. Here I take the view that if N>1.5M
// I will hive off square multiplications as much as I can. They will each
// be MxM so I need M space to keep some digits already computed that I
// will need to combine with the output from the next square multiply.
#ifdef DEBUG_TIMES
    display("\na", a, N);
    display("\nb", b, M);
#endif // DEBUG_TIMES
    if (2*N > 3*M)
    {   if (manager.mayUseThreads) unbalancedMul<true>(a, N, b, M, result);
        else unbalancedMul<false>(a, N, b, M, result);
    }
// Karatsuba cases here.
    else if (N < KARABIG || !manager.mayUseThreads)
        kara<false>(a, N, b, M, result);
    else kara<true>(a, N, b, M, result);
}

[[gnu::always_inline]]
static void differenceLengthsMatch(ConstDigitPtr low, std::size_t length,
                                   ConstDigitPtr high, DigitPtr result)
{   Digit borrow = subtractWithBorrow(low[0], high[0], result[0]);
//@@for (std::size_t i=1; i<length; i++)
//@@    borrow = subtractWithBorrow(low[i], high[i], borrow, result[i]);
    std::size_t i;
    for (i=1; i<length-1; i+=2)
    {   borrow = subtractWithBorrow(low[i], high[i], borrow, result[i]);
        borrow = subtractWithBorrow(low[i+1], high[i+1], borrow, result[i+1]);
    }
    if (i<length)
        borrow = subtractWithBorrow(low[i], high[i], borrow, result[i]);
}

[[gnu::always_inline]]
static bool differenceLengthsDiffer(ConstDigitPtr low, std::size_t lenLow,
                                    ConstDigitPtr high, std::size_t lenHigh,
                                    DigitPtr result)
{   Digit borrow = subtractWithBorrow(low[0], high[0], result[0]);
    std::size_t i=1;
//@@for (; i<lenHigh; i++)
//@@    borrow = subtractWithBorrow(low[i], high[i], borrow, result[i]);
    for (; i<lenHigh-1; i+=2)
    {   borrow = subtractWithBorrow(low[i], high[i], borrow, result[i]);
        borrow = subtractWithBorrow(low[i+1], high[i+1], borrow, result[i+1]);
    }
    if (i<lenHigh)
    {   borrow = subtractWithBorrow(low[i], high[i], borrow, result[i]);
        i++;
    }
// I will not unwind this loop because I expect that lenHigh will usually
// be very close to lenLow so there will be little to save.
    for (; i<lenLow; i++)
        borrow = subtractWithBorrow(low[i], borrow, result[i]);
    if (borrow == 0) return false;
// If necessary negate the result. This case arises if low has at least one
// zero leading digit and is less that high in magnitide.
    borrow = 0;
    for (i=0; i<lenLow; i++)
        borrow = subtractWithBorrow(0, result[i], borrow, result[i]);
    return true;
}

// set result = |low-high| and return true if high>low.
// A special feature here is that the "low" values here can have
// leading zeros - for instance consider the partitioned form of
// the number 1234_5678:0000_0234_5678 where I have used ":" to mark
// where the whole number is split into high and low parts. The high
// part has 2 digits and the low has 3, however the low part has the
// smaller value. So in that case the correct absolute value of
// the differenfce will be 0000_1000_0000

[[gnu::always_inline]]
static bool absDifference(ConstDigitPtr low, std::size_t lenLow,
                          ConstDigitPtr high, std::size_t lenHigh,
                          DigitPtr result)
{   if (lenHigh != lenLow)
        return differenceLengthsDiffer(low, lenLow, high, lenHigh, result);
// Here the two numbers both have the same number of digits. I need to
// work out which is the larger. Usually I will only need to look at
// the top digit. On that basis I make the code capable of scanning all
// the way down the number.
// An alternative stretegy would be do compute (low-high) always, detect
// a borrow at the end (ie that the difference was negative) and in that
// case negate the answer. That might do a full linear-cost negation about
// half the time where what I do here frequently only tests one digit.
    std::size_t i = lenLow-1; 
    for (;;)
    {   if (high[i] < low[i])
        {   differenceLengthsMatch(low, lenLow, high, result);
            return false;
        }
        else if (high[i] > low[i])
        {   differenceLengthsMatch(high, lenLow, low, result);
            return true;
        }
        if (i == 0)   // Here the two numbers are equal.
        {   std::memset(result, 0, lenLow*sizeof(Digit));
            return false;
        }
        i--;
    }
}

[[gnu::always_inline]]
static void setupKara(arithlib_implementation::WorkerData& wd,
                      ConstDigitPtr a, std::size_t lena,
                      ConstDigitPtr b, std::size_t lenb,
                      DigitPtr result)
{   wd.a = a;
    wd.lena = lena;
    wd.b = b;
    wd.lenb = lenb;
    wd.c = result;
}

// This is the entrypoint for Karatsuba multiplication, and it
// will be called with N>=M amd with a workspace vector big enough for
// its needs.

public:

template <bool thread=false>
static void kara(ConstDigitPtr a, std::size_t N,
                 ConstDigitPtr b, std::size_t M,
                 DigitPtr result)
{   std::size_t lowSize = (N+1)/2;
    std::size_t aHighSize = N-lowSize;
    std::size_t bHighSize = M-lowSize;
    ConstDigitPtr aHigh = a+lowSize;
    ConstDigitPtr bHigh = b+lowSize;
#ifdef DEBUG_TIMES
    display("\nahigh", aHigh, aHighSize);
    display("\nalow", a, lowSize);
    display("\nbhigh", bHigh, bHighSize);
    display("\nblow", b, lowSize);
#endif // DEBUG_TIMES
// I have now split a and b into low and and high parts where the two
// low parts are half the size of the larger input (rounded up if that
// was odd). I now want to form |aHigh - aLow| and similarly for b
// keeping track of whether taking the absolute values involved a sign flip.
    DigitPtr aDiff, bDiff;
    stkvector<Digit> workspace((thread?4:2)*lowSize);
    if constexpr (thread)
    {   aDiff = workspace+2*lowSize;
        bDiff = workspace+3*lowSize;
    }
    else
    {   aDiff = result;
        bDiff = result+lowSize;
    }
    bool sign = absDifference(a, lowSize, aHigh, aHighSize, aDiff);
    if (absDifference(b, lowSize, bHigh, bHighSize, bDiff)) sign = !sign;
#ifdef DEBUG_TIMES
    display("\nadiff", aDiff, lowSize);
    display("\nbdiff", bDiff, lowSize);
    std::cout << "% sign = " << sign << "\n";
#endif // DEBUG_TIMES
    if constexpr (thread)
    {   setupKara(driverData.wd_0, aDiff, lowSize, bDiff, lowSize, workspace);
        setupKara(driverData.wd_1, a, lowSize, b, lowSize, result);
// Let the threads run while I do aHigh*bHigh. I expect that I will only
// launch threads when the inputs are rather large, and in particular large
// enough that the half-sized multiplications triggered here will be
// Karatsuba rather than classical.
        driverData.releaseWorkers(false);
            // Do this while worker threads do their stuff.
            generalMul(aHigh, aHighSize, bHigh, bHighSize, result+2*lowSize);
        driverData.wait_for_workers(false);
    }
    else
    {   generalMul(aDiff, lowSize, bDiff, lowSize, workspace);
        generalMul(a, lowSize, b, lowSize, result);
        generalMul(aHigh, aHighSize, bHigh, bHighSize, result+2*lowSize);
#ifdef DEBUG_TIMES
    display("\nlowprod", result, 2*lowSize);
    display("\nmidprod", workspace, 2*lowSize);
    display("\nhighprod", result+2*lowSize, aHighSize+bHighSize);
#endif // DEBUG_TIMES
    }
// At this stage result has aHigh*bHigh in its top half and aLow*bLow
// in its bottom half. Then workspace hold aDiff*bDiff. I now need to
// combine these to get my final result. 
// If sign is false workspace holds aHigh*bHigh+aLow*bLow-middleTerms
// so I want to go
// 1.    workspace = aHigh*bHigh - workspace
// 2.    workspace = aLow*bLow + workspace
// 3.    result[middle] += workspace --- carry up into high part if needed.
// Step 1 can generate a borrow and step 2 a carry, so on input to step 3
// there is an extra -1, 0 or +1 to deal with.
// If sign is true I want
// 1.    workspace = aHigh*bHigh + workspace
// 2.    workspace = aLow*bLow + workspace
// 3.    result[middle] += workspace --- carry up into high part if needed.
// and now each of steps 1 and 2 may generate a carry, so step 3 starts
// with an extra 0, +1 or +2.
    int extra = 0;
    if (sign) extra =
        karaAdd(workspace, 2*lowSize,
                result+2*lowSize, aHighSize+bHighSize,
                workspace);
    else extra =
        -karaRevSubtract(workspace, 2*lowSize,
                         result+2*lowSize, aHighSize+bHighSize,
                         workspace);
    extra += karaAdd(result, 2*lowSize,
                     workspace, 2*lowSize, workspace);
// extra can now be -1, 0, 1 or 2
    Digit carry = karaAdd(workspace, 2*lowSize,
                          result+lowSize, 2*lowSize, result+lowSize);
    karaCarry(carry, result+3*lowSize);
    if (extra > 0) karaCarry(extra, result+3*lowSize);
    else if (extra < 0) karaBorrow(-extra, result+3*lowSize);
#ifdef DEBUG_TIMES
    display("\nresult", result, M+N);
#endif // DEBUG_TIMES
}  

private:


};

inline std::atomic<bool> BigMultiplication::ManageWorkers::threadsInUse(false);

// Now the external world needs access to the entrypoint "generalMul"
// so I provide a shim that calls it so that others do not need to
// fuss about the class name.

[[gnu::always_inline]]
inline void generalMul(ConstDigitPtr a, std::size_t N,
                       ConstDigitPtr b, std::size_t M,
                       DigitPtr result)
{   BigMultiplication::generalMul(a, N, b, M, result);
}

// verySimpleMul is intended to deliver the same results as generalMul
// but using clear (if less efficient code) so it can be use as a
// reference implementation during testing.

inline void verySimpleMul(ConstDigitPtr a, std::size_t N,
                          ConstDigitPtr b, std::size_t M,
                          DigitPtr result)
{   BigMultiplication::verySimpleMul(a, N, b, M, result);
}

// End of integer multiplication code.
//=========================================================================
