
//=========================================================================
//=========================================================================
// The LISP code is for incorporation in VSL or CSL
//=========================================================================
//=========================================================================

// The code in this region needs to be adapted to work with whatever
// language implementation you are going to use the arithmetic library from.
// In my case this will be one of two fairly closely related Lisp systems,
// where VSL is a "small" one and CSL is larger (and more complicated).
// The code here is left visible and available since it may provide some
// sort of model for anybody wanting to use this code in their own
// project.


// The code here can only make sense in the context of the CSL sources,
// and it is assumed that all the relevant CSL header files have already
// been #included.

inline std::uint64_t* reserve(std::size_t n)
{   LispObject a = get_basic_vector(TAG_NUMBERS,
                                    TYPE_NEW_BIGNUM,
                                    n*sizeof(Digit)+8);
    return reinterpret_cast<std::uint64_t*>(a + 8 - TAG_NUMBERS);
}

inline std::intptr_t confirmSize(std::uint64_t* p, std::size_t n,
                                 std::size_t final)
{   if (final == 1 && fitsIntoFixnum(static_cast<SignedDigit>(p[0])))
    {   std::intptr_t r = intToHandle(static_cast<SignedDigit>(p[0]));
// The bignum that I am abandoning was given a header word when it was
// first allocated, so it is in good order here.
        return r;
    }
// Note that pack_hdrlength() takes its argument measured in units of
// 32-bit words. That is because the way the length field is packed into
// an object header supported just that resolution (and special treatment is
// given to halfword, byte and bit-vectors to allow for their finer grain).
// The length also includes the size of a header-word, and on 32-bit platforms
// it has to allow for padding the data to allow the array of 64-bit digits
// to be properly aligned in memory. I do not use setNumberSize() here
// because the proper abstraction here belongs in a different world!
    ((LispObject* )&p[-1])[0] = make_new_bighdr(final+1);
// If I am on a 32-bit system the data for a bignum is 8 bit aligned and
// that leaves a 4-byte gap after the header. In such a case I will write
// in a zero just to keep memory tidy.
    if (sizeof(LispObject) == 4) ((LispObject* )&p[-1])[1] = 0;
// Here I could maybe reset fringe down by (final-n) if the current number
// is the most recently allocated item. Think about that later! However to
// be garbage-collector safe I fill any gaps with valid data...
    if (n != final)
    {   ((LispObject* )&p[final])[0] =
            TAG_HDR_IMMED + TYPE_PADDER + ((n-final)<<(Tw+8));
        if (sizeof(LispObject) == 4)
            ((LispObject* )&p[n])[1] = 0;
    }
    return vectorToHandle(p);
}

inline std::intptr_t confirmSize_x(std::uint64_t* p, std::size_t n,
                                   std::size_t final)
{
// Here I might need to write a nice dummy object into the gap left by
// shrinking the object.
    return confirmSize(p, n, final);
}

inline std::intptr_t vectorToHandle(std::uint64_t* p)
{   return reinterpret_cast<std::intptr_t>(p) - 8 + TAG_NUMBERS;
}

inline std::uint64_t* vectorOfHandle(std::intptr_t n)
{   return reinterpret_cast<std::uint64_t*>(n + 8 - TAG_NUMBERS);
}

inline std::size_t numberSize(std::uint64_t* p)
{
// The odd looking cast here is because in arithlib I am passing around
// arrays of explicitly 64-bit values, however in the underlying Lisp
// I expect to be modelling memory as made up of intptr-sized items
// that I arrange to have aligned on 8-byte boundaries. So to show some
// though about strict aliasing and the like I will access memory as
// an array of LispObject things when I access the header of an item.
    Header h = (Header)*(LispObject* )&p[-1];
    std::size_t r = length_of_header(h);
// On 32-bit systems a bignum will have a wasted 32-bit word after the
// header and before the digits, so that the digits are properly aligned
// in memory. The result will be that the bignum is laid out as follows
//      |     hdr64     | digit64 | digit64 | ... |    (64-bit world)
//      | hdr32 | gap32 | digit64 | digit64 | ... |    (32-bit world)
// The length value packed into the header is the length of the vector
// including its header.
    r = (r-8)/sizeof(Digit);
    return r;
}

inline bool storedAsFixnum(std::intptr_t a)
{   return is_fixnum(a);
}

constexpr inline SignedDigit intOfHandle(std::intptr_t a)
{   return int_of_fixnum(a);
}

inline std::intptr_t intToHandle(SignedDigit n)
{   return fixnum_of_int(n);
}

inline const SignedDigit MIN_FIXNUM = intOfHandle(INTPTR_MIN);
inline const SignedDigit MAX_FIXNUM = intOfHandle(INTPTR_MAX);

inline bool fitsIntoFixnum(SignedDigit a)
{   return a>=MIN_FIXNUM && a<=MAX_FIXNUM;
}

inline void abandon(std::uint64_t* p)
{   // No need to do anything! But MIGHT reset fringe pointer?
}

inline void abandon(std::intptr_t p)
{   if (!storedAsFixnum(p) && p!=0)
    {   std::uint64_t* pp = vectorOfHandle(p);
        abandon(pp);
    }
}

inline char* reserveString(std::size_t n)
{   LispObject a = get_basic_vector(TAG_VECTOR, TYPE_STRING_4, CELL+n);
    return reinterpret_cast<char*>(a - TAG_VECTOR + sizeof(LispObject));
}

inline LispObject confirmSizeString(char* p, std::size_t n,
                                             std::size_t final)
{
// The size of the string object in memory must allow for  a Lisp header
    n += sizeof(std::uintptr_t);
    final += sizeof(std::uintptr_t);
// The object size gets padded up to a multiple of 8 bytes.
    size_t nPadded = (n+7) & -8;
    size_t finalPadded = (final+7) & -8;
    if (nPadded != finalPadded)
       * reinterpret_cast<LispObject*>(p+finalPadded) =
            TAG_HDR_IMMED + TYPE_PADDER +
            ((nPadded-finalPadded)<<(Tw+5));
    LispObject* a = reinterpret_cast<LispObject*>(p - sizeof(LispObject));
   * a = TAG_HDR_IMMED + TYPE_STRING_4 + (final<<(Tw+5));
    return (LispObject)a + TAG_VECTOR;
}

inline void abandonString(string_handle s)
{   // Do nothing.
}

template <class OP,class RES>
inline RES op_dispatch1(std::intptr_t a1)
{   if (storedAsFixnum(a1)) return OP::op(intOfHandle(a1));
    else return OP::op(vectorOfHandle(a1));
}

template <class OP,class RES>
inline RES op_dispatch1(std::intptr_t a1, SignedDigit n)
{   if (storedAsFixnum(a1)) return OP::op(intOfHandle(a1), n);
    else return OP::op(vectorOfHandle(a1), n);
}

template <class OP,class RES>
inline RES op_dispatch1(std::intptr_t a1, std::uint64_t* n)
{   if (storedAsFixnum(a1)) return OP::op(intOfHandle(a1), n);
    else return OP::op(vectorOfHandle(a1), n);
}

template <class OP,class RES>
inline RES op_dispatch2(std::intptr_t a1, std::intptr_t a2)
{   if (storedAsFixnum(a1))
    {   LIKELY
        if (storedAsFixnum(a2))
            LIKELY
            return OP::op(intOfHandle(a1), intOfHandle(a2));
        else return OP::op(intOfHandle(a1), vectorOfHandle(a2));
    }
    else
    {   if (storedAsFixnum(a2))
            LIKELY
            return OP::op(vectorOfHandle(a1), intOfHandle(a2));
        else return OP::op(vectorOfHandle(a1), vectorOfHandle(a2));
    }
}

inline std::intptr_t alwaysCopyBignum(std::uint64_t* p)
{   std::size_t n = numberSize(p);
    std::uint64_t* r = reserve(n);
    std::memcpy(r, p, n*sizeof(Digit));
    return confirmSize(r, n, n);
}

inline std::intptr_t copyIfNoGarbageCollector(std::uint64_t* p)
{   std::size_t n = numberSize(p);
    std::uint64_t* r = reserve(n);
    std::memcpy(r, p, n*sizeof(Digit));
    return confirmSize(r, n, n);
}

inline std::intptr_t copyIfNoGarbageCollector(std::intptr_t pp)
{   if (storedAsFixnum(pp)) return pp;
    std::uint64_t* p = vectorOfHandle(pp);
    std::size_t n = numberSize(p);
    std::uint64_t* r = reserve(n);
    std::memcpy(r, p, n*sizeof(Digit));
    return confirmSize(r, n, n);
}



// end of memalloc.h
