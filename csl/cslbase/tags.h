// tags.h                                  Copyright (C) Codemist 1990-2021

//
//   Data-structure and tag bit definitions, also common C macros
//   for Lisp implementation.
//
//

/**************************************************************************
 * Copyright (C) 2021, Codemist.                         A C Norman       *
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


#ifndef header_tags_h
#define header_tags_h 1

// General objects in Lisp are represented as pointer-sized integers
// and the type LispObject reflects this representation and
// not the elaborate tagged union that at some other level exists.
// If I could use "void *" for this type that might give me a bit more
// security since not much can be done with a "void *" object - in particular
// it can not participate in arithmetic.  But when I do that I run into
// trouble in protected mode on a PC if I have items of type LispObject
// that are not valid pointers. I suspect that the same used to be
// the case on a Motorola 68000 with address and data registers.
//
// Sometimes the pointer-sized integer will be 64-bits wide, and will be the
// data type for the type LispObject. A result will be that anywhere in
// the code where I am sloppy about putting such an object into an int32_t
// I will have trouble, and anywhere that I use absolute numeric offsets
// instead of multiples of sizeof(LispObject) there can be pain.

typedef intptr_t LispObject;

// Headers are also LispObjects, but I give them a separate typedef
// name to help me keep their identity separate.  There is only any
// chance of headers and other objects getting confused during
// garbage collection, and the code there has to be rather on the
// careful side.  By making Headers unsigned I help the length
// calculation on them.

typedef uintptr_t Header;

// The following is a really rather dodgy idea. Suppose a have variables
// LispObject x, *y;
// Then I will be able to go things like
//    ... AT(X) ...
//    ... AT(*y) ...
//    AT(x) = ...
//    AT(*y) = ...
// and the AT() wrapper should lead to the access to the stored values being
// performed as an atomic operation with sequentially_consistent memory
// ordering imposed. Neither the compiler not hardware (such as a memory
// write pipeline or buffer) should then re-order access to other values
// past this one, and if one thread stores a value and then another reads
// the same item then the two threads should then be in step as regards not
// just that particular transaction but all others that have happened
// previously.
// The reinterpret_cast here is in violation of C++ strict aliasing rules
// and there is no guarantee that the representation in memory of T and
// std::atomic<T> match but it seems to me that it would be a very brave
// compiler that omitted a load or store involving the raw data (ie x or y)
// or relied on a cached value past an atomic access.

template <typename T>
std::atomic<T>& AT(T& x)
{   return reinterpret_cast<std::atomic<T>>(x);
}

// Perhaps the most important value here is nil!
extern LispObject nil;

static constexpr bool SIXTY_FOUR_BIT = sizeof(intptr_t) == 8;

// I manage memory in CSL_PAGE_SIZE chunks.
//
// My default at present is to use PAGE_BITS=23, which leads to 8 Mbyte
// pages. I use that size on both 32 and 64-bit machines.

#ifndef PAGE_BITS
static constexpr size_t PAGE_BITS = 23;
#endif // PAGE_BITS

static constexpr size_t PAGE_POWER_OF_TWO = static_cast<size_t>(1) << PAGE_BITS;
static constexpr size_t CSL_PAGE_SIZE = PAGE_POWER_OF_TWO;

// On 64-bit systems I will limit myself to 2 Terabytes, while on 32-bit
// ones the limit is around 2 Gbyte and in reality will usually be
// rather less than that. Note that this limit is expected to be a power
// of 2.
#ifndef MAX_HEAPSIZE
static constexpr size_t MAX_HEAPBITS = SIXTY_FOUR_BIT ? 41 : 31;
// The number here is measured in megabytes so it is always reasonably small.
static constexpr size_t MAX_HEAPSIZE = static_cast<size_t>(1) << (MAX_HEAPBITS-20);
#endif // MAX_HEAPSIZE

static constexpr size_t MEGABYTE = 0x100000;

#ifndef INITIAL_HEAPSIZE
static constexpr size_t INITIAL_HEAPSIZE = (SIXTY_FOUR_BIT?768u:128u)*MEGABYTE;
#endif // MAX_HEAPSIZE

static constexpr size_t MAX_PAGES = MAX_HEAPSIZE >> (PAGE_BITS-20);

// Windows seems to say it can use file names up to 260 chars, Unix and
// the like may not even have that limit, but I will assume something here.
// There must be a number of cases of potential buffer overflow throughout
// my code caused by this fixed limit. Note that the Windows limit there is
// just when using 8-bit characters in the path-name, and it is 256 plus
// space for "x:\" at the start to specify a drive and a "\0" at the end to
// terminate the string. However if you use the Unicode version of the
// Windows API you can have names with length up to 32K. Well it is messier
// even that that. Since about mid 2016 Windows 10 allows users to opt out
// of there being a path length restriction by setting a registry key and
// perhaps by also putting extra stuff an an "application manifest".
// I rather wonder how many people exploit that option?

static constexpr size_t LONGEST_LEGAL_FILENAME = 1024;

// This class is provided just so I can allocate things so as to be
// (at least) 8-byte aligned.

class alignas(8) Align8
{
public:
    char data[8];
};

// The macro CELL had better have either the value 4 or 8. It is the
// size of the basic unit of memory within which CSL works.

static constexpr size_t CELL = sizeof(LispObject);

// LispObject is a datatype where the low 3 bits are used as tags -
// this idea works provided all memory addresses needed can be kept
// doubleword aligned.  The main tag allocation is documented here.

static constexpr uintptr_t TAG_BITS      = 0x7;
static constexpr uintptr_t XTAG_BITS     = 0xf;

// For almost all types I just use TAG_BITS and masking with that leaves
// an integer in the range 0-7. But the code 7 there is used both for small
// integers and for short floats and in that case the next bit up is used
// to discriminate, so there I may want to use XTAG_BITS which picks out
// the low 4 bits rather than just the low 3.

static constexpr uintptr_t TAG_CONS      =  0; // Cons cells                    01
static constexpr uintptr_t TAG_VECTOR    =  1; // Regular Lisp vectors          02
static constexpr uintptr_t TAG_HDR_IMMED =  2; // Char constants, vechdrs etc   04
static constexpr uintptr_t TAG_FORWARD   =  3; // For the Garbage Collector     08
static constexpr uintptr_t TAG_SYMBOL    =  4; // Symbols                       10
                 // Note that tags from 5 up are all for numeric date       e0
static constexpr uintptr_t TAG_NUMBERS   =  5; // Bignum, Rational, Complex     20
static constexpr uintptr_t TAG_BOXFLOAT  =  6; // Boxed floats                  40
static constexpr uintptr_t TAG_FIXNUM    =  7; // 28/60-bit integers            80
static constexpr uintptr_t TAG_XBIT      =  8; // extra bit!                    80
static constexpr uintptr_t XTAG_SFLOAT   = 15; // Short float, 28+ bits of data 80

// On a 32-bit machine I can pack a 28-bit float (implemented as a 32-bit
// one with the low 4 bits crudely masked off) by putting XTAG_FLOAT as the
// bottom 4 bits. On a 64-bit system I have 64-bit immediate data so if I
// I have XTAG_FLOAT as the low 4 bits then bit 5 select as between
// a 28 or a 32-bit value and the high 28 or 32-bits can be that value.
// Thus on a 64-bit machine single floats as well as short floats have
// an immediate representation.
static constexpr uintptr_t XTAG_FLOAT32  = 16;

inline bool is_forward(LispObject p)
{   return (p & TAG_BITS) == TAG_FORWARD;
}

inline bool is_number(LispObject p)
{   return (p & TAG_BITS) >= TAG_NUMBERS;
}

inline bool is_float(LispObject p)
{   return ((0xc040 >> (p & XTAG_BITS)) & 1) != 0;
}

inline bool is_pointer_type(LispObject p)
{   return ((0x73 >> (p & TAG_BITS)) & 1) != 0;
}

inline bool is_immed_or_cons(LispObject p)
{   return ((0x85 >> (p & TAG_BITS)) & 1) != 0;
}

inline bool is_immediate(LispObject p)
{   return ((0x84 >> (p & TAG_BITS)) & 1) != 0;
}

inline bool is_immed_cons_sym(LispObject p)
{   return ((0x95 >> (p & TAG_BITS)) & 1) != 0;
}

inline bool need_more_than_eq(LispObject p)
{   return ((0x63 >> (p & TAG_BITS)) & 1) != 0;
}

// For each of the above tag classes I have a bunch of low-level
// operations that need support - including type identification
// predicates and conversions to and from native C formats.

// fixnums now use the whole of an intptr_t, so they have 28 useful bits on
// a 32-bit machine and 60-bits on a 64-bit machine. By doing the left shift
// on an unsigned value I steer clear of C++ undefined behaviour, but then
// when I cast back to a signed value I am in "implementation defined"
// territory.

inline constexpr LispObject fixnum_of_int(intptr_t x)
{   return  (static_cast<uintptr_t>(x)<<4) + TAG_FIXNUM;
}

// There are places where I want to use this as a case-constant and then I
// may not use the inline procedure...
// Well maybe these days I could make it constexpr and that would do the
// trick?

inline constexpr LispObject FIXNUM_OF_INT(intptr_t n)
{   return (static_cast<uintptr_t>(n)<<4) + TAG_FIXNUM;
}

// The code here manages to get compiled as a simple arithmetic right shift
// on enough architectures that I will not worry about writing it as a
// division. My intent here is (x>>4) with the shift being arithmetic in that
// it should replicate the top bit of the word as it shifts. Masking off
// low bits and then doing a signed division should achieve this affect in a
// portable manner.

inline constexpr intptr_t int_of_fixnum(LispObject x)
{   return (static_cast<intptr_t>(x) &
            ~static_cast<intptr_t>(15)) / 16;
}

// The following test will see if an intptr_t value can be reduced to
// a Lisp fixnum without loss. I think that the logic is pretty clearly
// expressed here, but I want the code to run fast. Well I observe that
// using g++ on the computers that most matter to me this compiles
// rather as if it has been ((x<<4)>>4 == x), i.e. as two shifts followed
// by a comparison. This probably does well compared with some previous
// code I had that things like (x < 0x08000000 && x >= -0x08000000)
// which involves referring to two literal values and performing two
// comparisons. Of perhaps { t = (x & fix_mask); if (t==0 | t == fix_mask) ..}
// which is comparable. If you had a compiler that was less clever the
// resulting code here could be horrible!

// I need to overload these to cover various integer widths.

inline bool valid_as_fixnum(int32_t x)
{   if (SIXTY_FOUR_BIT) return true;
    else return int_of_fixnum(fixnum_of_int(x)) == x;
}

inline bool valid_as_fixnum(int64_t x)
{   return int_of_fixnum(fixnum_of_int(x)) == x;
}

inline bool valid_as_fixnum(int128_t x)
{   return int_of_fixnum(fixnum_of_int(static_cast<int64_t>(x))) == x;
}

// The following has given me some pain wrt the overloading where gcc and
// clang disagree about validity. Until I have read the C++ standard carefully
// enough I use this non-overloaded version in a few places. This issue is
// that intptr_t is liable to be either similar to int32_t or similar to
// int64_t. So if I try to provide overloads that accept all of int32_t,
// intptr_t and int64_t there is scope for confusion between the 3 versions.

inline bool intptr_valid_as_fixnum(intptr_t x)
{   return int_of_fixnum(fixnum_of_int(x)) == x;
}

inline bool valid_as_fixnum(uint32_t x)
{   if (SIXTY_FOUR_BIT) return true;
    else return x < ((static_cast<uintptr_t>(1)) << 28);
}

inline bool valid_as_fixnum(uint64_t x)
{   return x < ((static_cast<uintptr_t>(1)) << (SIXTY_FOUR_BIT ? 60 :
                28));
}

inline bool uint128_valid_as_fixnum(uint128_t x)
{   return x < ((static_cast<uintptr_t>(1)) << (SIXTY_FOUR_BIT ? 60 :
                28));
}

static constexpr intptr_t MOST_POSITIVE_FIXVAL =
    ((static_cast<intptr_t>(1) << (8*sizeof(LispObject)-5)) - 1);
static constexpr intptr_t MOST_NEGATIVE_FIXVAL =
    (-(static_cast<intptr_t>(1) << (8*sizeof(LispObject)-5)));

static constexpr LispObject MOST_POSITIVE_FIXNUM =
    fixnum_of_int(MOST_POSITIVE_FIXVAL);
static constexpr LispObject MOST_NEGATIVE_FIXNUM =
    fixnum_of_int(MOST_NEGATIVE_FIXVAL);

inline bool is_cons(LispObject p)
{   return (((static_cast<int>(p)) & TAG_BITS)  == TAG_CONS);
}

inline bool is_fixnum(LispObject p)
{   return (((static_cast<int>(p)) & XTAG_BITS) == TAG_FIXNUM);
}

inline bool is_immediate_num(LispObject p)
{   return (((static_cast<int>(p)) & TAG_BITS) == TAG_FIXNUM);
}

inline bool is_odds(LispObject p)
{   return (((static_cast<int>(p)) & TAG_BITS)  ==
            TAG_HDR_IMMED); // many subcases
}

inline bool is_sfloat(LispObject p)
{   return (((static_cast<int>(p)) & XTAG_BITS) == XTAG_SFLOAT);
}

inline bool is_symbol(LispObject p)
{   return (((static_cast<int>(p)) & TAG_BITS)  == TAG_SYMBOL);
}

inline bool is_numbers(LispObject p)
{   return (((static_cast<int>(p)) & TAG_BITS)  == TAG_NUMBERS);
}

inline bool is_vector(LispObject p)
{   return (((static_cast<int>(p)) & TAG_BITS)  == TAG_VECTOR);
}

inline bool is_bfloat(LispObject p)
{   return (((static_cast<int>(p)) & TAG_BITS)  == TAG_BOXFLOAT);
}

inline bool consp(LispObject p)
{   return is_cons(p);
}
inline bool symbolp(LispObject p)
{   return is_symbol(p);
}

// For Common Lisp it would be necessary to detect and trap any attempt
// to take CAR or CDR of NIL and do something special.

inline bool car_legal(LispObject p)
{   return is_cons(p);
}

typedef struct Cons_Cell_
{   LispObject car;
    LispObject cdr;
} Cons_Cell;


extern bool valid_address(void *pointer);
[[noreturn]] extern void my_abort();
[[noreturn]] extern void my_abort(const char *msg);

// Going forward I may want to be able to control where I have memory
// fences and what sort get used, so these access functions have (optional)
// arguments relating to that. The default relaxed behaviour should be best
// for performance if not for multi-thread consistency.

inline LispObject &car(LispObject p)
{   //if (!is_cons(p) || !valid_address((void *)p)) my_abort("invalid car");
    return reinterpret_cast<Cons_Cell *>(p)->car;
}

inline LispObject &cdr(LispObject p)
{   //if (!is_cons(p) || !valid_address((void *)p)) my_abort("invalid cdr");
    return reinterpret_cast<Cons_Cell *>(p)->cdr;
}

inline void setcar(LispObject p, LispObject q)
{   //if (!is_cons(p) || !valid_address((void *)p)) my_abort("invalid setcar");
    reinterpret_cast<Cons_Cell *>(p)->car = q;
}

inline void setcdr(LispObject p, LispObject q)
{   //if (!is_cons(p) || !valid_address((void *)p)) my_abort("invalid setcdr");
    reinterpret_cast<Cons_Cell *>(p)->cdr = q;
}

inline LispObject *caraddr(LispObject p)
{   //if (!is_cons(p) || !valid_address((void *)p)) my_abort("invalid caraddr");
    return &((reinterpret_cast<Cons_Cell *>(p))->car);
}

inline LispObject *cdraddr(LispObject p)
{   //if (!is_cons(p) || !valid_address((void *)p)) my_abort("invalid cdraddr");
    return &((reinterpret_cast<Cons_Cell *>(p))->cdr);
}

// At present (boo hiss) the serialization code and the garbage collector
// both expect to run with no other thread active, and they are coded using
// simple non-atomic data. These two return addressed on the car and cdr
// fields in a cons cell expecting atomic and non-atomic layouts to match.

inline LispObject *vcaraddr(LispObject p)
{   //if (!is_cons(p) || !valid_address((void *)p)) my_abort("invalid vcaraddr");
    return reinterpret_cast<LispObject *>(
               &(reinterpret_cast<Cons_Cell *>(p)->car));
}

inline LispObject *vcdraddr(LispObject p)
{   //if (!is_cons(p) || !valid_address((void *)p)) my_abort("invalid "vcdraddr");
    return reinterpret_cast<LispObject *>(
               &(reinterpret_cast<Cons_Cell *>(p)->cdr));
}

typedef LispObject Special_Form(LispObject, LispObject);

// The original CSL uses entries for 1, 2 and n arguments, where the general
// case has an argument count and uses va_args.
// A newer scheme will have entries for 0, 1, 2, 3 and more than that. For
// 4 or more arguments a count is passed. For exactly four arguments the
// final argument is passed directly.
//   (F 4 a1 a2 a3 a4)
// For the 5 up case arguments 4, 5, ...
// are passed as a list much as if the call had been
//   (F n a1 a2 a3 (list a4 a5 a6 ... an))

typedef LispObject no_args(LispObject);
typedef LispObject one_arg(LispObject, LispObject);
typedef LispObject two_args(LispObject, LispObject, LispObject);
typedef LispObject three_args(LispObject, LispObject, LispObject,
                              LispObject);
typedef LispObject fourup_args(LispObject, LispObject, LispObject,
                               LispObject, LispObject);

// Objects will have a header word with the following format:
//   xxxx:xxxx:xxxx:xxxx:xxxx:xx  yy:yyy z:z 010
//             22-bits            5-bits  2   3
// The low 3 bits are always TAG_HDR_IMMED.
//
// I will use a shift by Tw to cope with the width of 010 with
// Tw=3 so that the offset to where yyyy/zz starts is kept just a little
// bit abstract.

static constexpr unsigned int Tw = 3;

// The zz bits are
//        00    symbol header, character literal, special identifier (Spid)
//        01    vector containing Lisp pointers
//        10    bit-vectors
//        11    vector containing binary data
//
// The bits yyyyy are used to indicate which case within each above category
// applies. For class "00" only the two low bits are used, so there are then
// 25 bits of payload available.
// For the other cases the field xx(22)xx gives the number of (4-byte) words
// of data used in the object. Note that this count does not include the
// size of the header itself. Because this is in 32-bit words rather than bytes
// this allows the largest object to be 16 Mbytes if your word length is 32
// bits. That limit larger than the previous CSL tagging scheme permitted, but
// note that the size of objects is syill also limited by the csl "page" size,
// which is now 8 Mbytes.
//
// For vectors of bits, bytes and halfwords the high bits of yyyyy indicate the
// number of bits used in the final 32-bit word that is indicated by xxx.
// Consider the case for bytes (as used for strings). If there are n characters
// in a string then xxx must show ((n + 3) & ~3) [suitably shifted]. The two
// bits in yy will be ((n + 3) & 3) so that 0 indicates just one character in
// the final word and 3 denotes the final word being full.
// Now given w = xxxxxyy (the packed length) just subtracting 3 should
// recover the length n.

// It took me some while to get my head around the full consequences here!
// Because the length code is the length of active data (from 0 upwards)
// lengths can be from 0 to 0xffffff. A byte-vector can then have a length
// stored as up to 0xffffff:3 which stands for a length 0x3ffffc. This is a
// string that fills all the words of the vector. [these are described as for
// a 32-bit machine]. Note that if one includes the header word the total size
// of the object becomes 0x1000000.

// I have considered making the length code just the length of DATA not
// including the size of the header. In some respects that would be tidier,
// but at present I do not believe that the widespread code changes needed to
// move to it would be cost-effective and the risk introduced by a change
// that widestream could be large.

static constexpr uintptr_t header_mask = 0x7f<<Tw;

// Bit, byte and halfword-vectors need extra information held here so that
// their exact can be determined.  Generally headers hold length information
// measured in words, so a few more bits are required here.
// Bitvectors will now supported even in Standard Lisp mode.

static constexpr uintptr_t TYPE_BITVEC_1     = 0x02<<Tw;  // subtypes encode length mod 32
static constexpr uintptr_t TYPE_BITVEC_2     = 0x06<<Tw;  // BITVEC_n has n bits in use in its...
static constexpr uintptr_t TYPE_BITVEC_3     = 0x0a<<Tw;  // ... final 32-bit word.
static constexpr uintptr_t TYPE_BITVEC_4     = 0x0c<<Tw;  //
static constexpr uintptr_t TYPE_BITVEC_5     = 0x12<<Tw;  //
static constexpr uintptr_t TYPE_BITVEC_6     = 0x16<<Tw;  //
static constexpr uintptr_t TYPE_BITVEC_7     = 0x1a<<Tw;  //
static constexpr uintptr_t TYPE_BITVEC_8     = 0x1c<<Tw;  //
static constexpr uintptr_t TYPE_BITVEC_9     = 0x22<<Tw;  //
static constexpr uintptr_t TYPE_BITVEC_10    = 0x26<<Tw;  //
static constexpr uintptr_t TYPE_BITVEC_11    = 0x2a<<Tw;  //
static constexpr uintptr_t TYPE_BITVEC_12    = 0x2c<<Tw;  //
static constexpr uintptr_t TYPE_BITVEC_13    = 0x32<<Tw;  //
static constexpr uintptr_t TYPE_BITVEC_14    = 0x36<<Tw;  //
static constexpr uintptr_t TYPE_BITVEC_15    = 0x3a<<Tw;  //
static constexpr uintptr_t TYPE_BITVEC_16    = 0x3c<<Tw;  //
static constexpr uintptr_t TYPE_BITVEC_17    = 0x42<<Tw;  //
static constexpr uintptr_t TYPE_BITVEC_18    = 0x46<<Tw;  //
static constexpr uintptr_t TYPE_BITVEC_19    = 0x4a<<Tw;  //
static constexpr uintptr_t TYPE_BITVEC_20    = 0x4c<<Tw;  //
static constexpr uintptr_t TYPE_BITVEC_21    = 0x52<<Tw;  //
static constexpr uintptr_t TYPE_BITVEC_22    = 0x56<<Tw;  //
static constexpr uintptr_t TYPE_BITVEC_23    = 0x5a<<Tw;  //
static constexpr uintptr_t TYPE_BITVEC_24    = 0x5c<<Tw;  //
static constexpr uintptr_t TYPE_BITVEC_25    = 0x62<<Tw;  //
static constexpr uintptr_t TYPE_BITVEC_26    = 0x66<<Tw;  //
static constexpr uintptr_t TYPE_BITVEC_27    = 0x6a<<Tw;  //
static constexpr uintptr_t TYPE_BITVEC_28    = 0x6c<<Tw;  //
static constexpr uintptr_t TYPE_BITVEC_29    = 0x72<<Tw;  //
static constexpr uintptr_t TYPE_BITVEC_30    = 0x76<<Tw;  //
static constexpr uintptr_t TYPE_BITVEC_31    = 0x7a<<Tw;  //
static constexpr uintptr_t TYPE_BITVEC_32    = 0x7c<<Tw;  //

// A string is not really a vector of characters since it is in utf-8 so
// access to the nth characters or updating characters within it is
// hard. You should use a vector of 32-bit codepoints if you want
// a genuine vector of characters, but then you will not have a string!

static constexpr uintptr_t TYPE_STRING_1    = 0x07<<Tw; // simple (narrow) character vector
static constexpr uintptr_t TYPE_STRING_2    = 0x27<<Tw; // Strings are in UTF8
static constexpr uintptr_t TYPE_STRING_3    = 0x47<<Tw; //
static constexpr uintptr_t TYPE_STRING_4    = 0x67<<Tw; //

static constexpr uintptr_t TYPE_VEC8_1      = 0x03<<Tw; // vector of 8 bit values
static constexpr uintptr_t TYPE_VEC8_2      = 0x23<<Tw; //
static constexpr uintptr_t TYPE_VEC8_3      = 0x43<<Tw; //
static constexpr uintptr_t TYPE_VEC8_4      = 0x63<<Tw; //

static constexpr uintptr_t TYPE_BPS_1       = 0x0b<<Tw; // Bytecodes
static constexpr uintptr_t TYPE_BPS_2       = 0x2b<<Tw; //
static constexpr uintptr_t TYPE_BPS_3       = 0x4b<<Tw; //
static constexpr uintptr_t TYPE_BPS_4       = 0x6b<<Tw; //

// static constexpr uintptr_t TYPE_NATIVECODE  = 0x6f<<Tw; // (not implemented)

static constexpr uintptr_t TYPE_VEC16_1     = 0x0f<<Tw; // vector of 16 bit values
static constexpr uintptr_t TYPE_VEC16_2     = 0x4f<<Tw; //

#if 0
static constexpr uintptr_t TYPE_MAPLEREF    = 0x2f<<Tw; // hook for interface to Maple ...
// ... note this was an EXPERIMENT
#endif

static constexpr uintptr_t TYPE_FOREIGN     = 0x33<<Tw; // entrypoint to foreign function
static constexpr uintptr_t TYPE_SP          = 0x37<<Tw; // Encapsulated stack ptr
static constexpr uintptr_t TYPE_ENCAPSULATE = 0x3b<<Tw; // Encapsulated address

static constexpr uintptr_t TYPE_PADDER      = 0x7b<<Tw; // a padder vector


inline bool vector_holds_binary(Header h)
{   return  (h & (0x2<<Tw)) != 0;
}

static constexpr uintptr_t TYPE_SIMPLE_VEC   = 0x01<<Tw; // simple general vector
static constexpr uintptr_t TYPE_INDEXVEC     = 0x11<<Tw; // used for huge vectors
static constexpr uintptr_t TYPE_HASH         = 0x15<<Tw; // new style hash table
static constexpr uintptr_t TYPE_HASHX        = 0x19<<Tw; // new hash table in need of re-hashing
//static constexpr uintptr_t TYPE_OLDHASH    = 0x21<<Tw; // old style hash table.
static constexpr uintptr_t TYPE_ARRAY        = 0x05<<Tw; // header record for general array
static constexpr uintptr_t TYPE_STRUCTURE    = 0x09<<Tw; // .. includes packages etc possibly
static constexpr uintptr_t TYPE_OBJECT       = 0x0d<<Tw; // .. and "object"

static constexpr uintptr_t TYPE_VEC32        = 0x13<<Tw; // contains 32-bit integers
static constexpr uintptr_t TYPE_VEC64        = 0x17<<Tw; // contains 32-bit integers
static constexpr uintptr_t TYPE_VEC128       = 0x1b<<Tw; // contains 32-bit integers
static constexpr uintptr_t TYPE_VECFLOAT32   = 0x53<<Tw; // contains single-precision floats
static constexpr uintptr_t TYPE_VECFLOAT64   = 0x57<<Tw; // contains double-precision floats
static constexpr uintptr_t TYPE_VECFLOAT128  = 0x5b<<Tw; // contains long double floats

// The next items live amongst the vectors that hold Lisp pointers, but only
// the first three items are pointers - the rest of the stuff is binary
// data. This arrangements was required for streams, and the three other
// "mixed" cases are just in case anybody finds them useful.
static constexpr uintptr_t TYPE_MIXED1       = 0x41<<Tw; // general, but limited to 3 pointers
static constexpr uintptr_t TYPE_MIXED2       = 0x45<<Tw; // general, but limited to 3 pointers
static constexpr uintptr_t TYPE_MIXED3       = 0x49<<Tw; // only 3 pointers
static constexpr uintptr_t TYPE_STREAM       = 0x4d<<Tw; // 3 pointers then binary data

inline bool is_mixed_header(uintptr_t h)
{   return (h & (0x73<<Tw)) == TYPE_MIXED1;
}

static constexpr uintptr_t VIRTUAL_TYPE_CONS = 0x7d<<Tw; // what a header for a CONS would be!
static constexpr uintptr_t VIRTUAL_TYPE_REF  = 0x17d<<Tw;// Used by sxhash.
static constexpr uintptr_t VIRTUAL_TYPE_NIL  = 0x27d<<Tw;// Used in hashing.

static constexpr uintptr_t HDR_IMMED_MASK    = (0xf<<Tw) | TAG_BITS;
static constexpr uintptr_t TAG_CHAR          = (0x4<<Tw) | TAG_HDR_IMMED; // 25 bits payload
static constexpr uintptr_t TAG_SPID          = (0xc<<Tw) | TAG_HDR_IMMED; // Internal flag values

static constexpr uintptr_t SPID_NIL       = TAG_SPID+(0x00<<(Tw+4)); // NIL in checkpoint file
static constexpr uintptr_t SPID_FBIND     = TAG_SPID+(0x01<<(Tw+4)); // Fluid binding on stack
static constexpr uintptr_t SPID_CATCH     = TAG_SPID+(0x02<<(Tw+4)); // CATCH frame on stack
static constexpr uintptr_t SPID_PROTECT   = TAG_SPID+(0x03<<(Tw+4)); // UNWIND_PROTECT on stack
static constexpr uintptr_t SPID_HASHEMPTY = TAG_SPID+(0x04<<(Tw+4)); // Empty hash slot
static constexpr uintptr_t SPID_HASHTOMB  = TAG_SPID+(0x05<<(Tw+4)); // Deleted hash item (tombstone)
static constexpr uintptr_t SPID_GCMARK    = TAG_SPID+(0x06<<(Tw+4)); // Used by GC as sentinel
static constexpr uintptr_t SPID_NOINPUT   = TAG_SPID+(0x07<<(Tw+4)); // Used by (read) in #X()
static constexpr uintptr_t SPID_ERROR     = TAG_SPID+(0x08<<(Tw+4)); // Used to indicate error
static constexpr uintptr_t SPID_PVBIND    = TAG_SPID+(0x09<<(Tw+4)); // PROGV binding on stack
static constexpr uintptr_t SPID_NOARG     = TAG_SPID+(0x0a<<(Tw+4)); // Missing &OPTIONAL arg
static constexpr uintptr_t SPID_NOPROP    = TAG_SPID+(0x0b<<(Tw+4)); // fastget entry is empty
static constexpr uintptr_t SPID_LIBRARY   = TAG_SPID+(0x0c<<(Tw+4)); // + 0xnnn00000 offset

inline Header &vechdr(LispObject v)
{   return *reinterpret_cast<Header *>(v - TAG_VECTOR);
}

inline void setvechdr(LispObject v, Header h)
{   *reinterpret_cast<Header *>(
        reinterpret_cast<char *>(v) - TAG_VECTOR) = h;
}

inline unsigned int type_of_header(Header h)
{   return (static_cast<unsigned int>(h)) & header_mask;
}

// length_of_header returns the length of a word or doubleword oriented
// object in bytes. NOT in words.

inline size_t length_of_header(Header h)
{   return (static_cast<size_t>(h) >> (Tw+7)) << 2;
}

// length_of_bitheader returns a length in bits.
inline size_t length_of_bitheader(Header h)
{   return (static_cast<size_t>(h) >> (Tw+2)) - 31;
}

// length_of_byteheader returns a length in bytes, and so compatible with
// what length_of_header used to do on byte arrays (and hence strings)


inline size_t length_of_byteheader(Header h)
{   return (static_cast<size_t>(h) >> (Tw+5))  - 3;
}

// length_of_hwordheader gives the number of halfwords used.
inline size_t length_of_hwordheader(Header h)
{   return (static_cast<size_t>(h) >> (Tw+6)) - 1;
}

inline Header bitvechdr_(size_t n)
{   return TYPE_BITVEC_1 + (((n+31)&31)<<(Tw+2));
}

// Values for the type field in a header

// Symbols are so important that they have 25+ bits used to sub-classify them.
// These are used by the interpreter to identify special variables, special
// forms, and those symbols which are defined as macros.  The bits live where
// other items would store a length, but since all symbol headers are the
// same size an explicit length field is not necessary - but missing one out
// means that I have to do a special check for the SYMBOL case whenever I
// scan the vector heap, which is a bit messy. Well when I say "25 bits" what
// I mean is that even on a 32-bit machine there are 25 bits available. On a
// 64-bit system there are an extra 32 (which at present I do not use).

static constexpr uintptr_t TYPE_SYMBOL        = 0x00000000;
static constexpr uintptr_t  SYM_SPECIAL_VAR   = 0x00000080; // (fluid '(xxx))
static constexpr uintptr_t  SYM_FLUID_VAR     = 0x00000080; // (fluid '(xxx))
static constexpr uintptr_t  SYM_GLOBAL_VAR    = 0x00000100; // (global '(xxx))
// I will set both SPECIAL and GLOBAL for "keywords" and those will be
// initialised to have themselves as their value and then neither be
// bindable or settable.
static constexpr uintptr_t  SYM_KEYWORD_VAR   = 0x00000180; // (keyword '(xxx))
static constexpr uintptr_t  SYM_SPECIAL_FORM  = 0x00000200; // eg. COND, QUOTE
static constexpr uintptr_t  SYM_MACRO         = 0x00000400; // (putd 'xxx 'macro ...)
static constexpr uintptr_t  SYM_CODEPTR       = 0x00000800; // just carries code pointer
static constexpr uintptr_t  SYM_ANY_GENSYM    = 0x00001000; // gensym, printed or not
static constexpr uintptr_t  SYM_TRACED        = 0x00002000; // function is traced.
static constexpr uintptr_t  SYM_TRACESET      = 0x00004000; // traceset support
static constexpr uintptr_t  SYM_TAGGED        = 0x00008000; // used for special versions
static constexpr uintptr_t  SYM_FASTGET_MASK  = 0x007e0000; // used to support "fast" gets
static constexpr uintptr_t  SYM_FASTGET_SHIFT = 17;
//
#ifdef COMMON
// In Common Lisp mode I use the rest of the header to help speed up
// test for the availability of a symbol in a package (while I am printing).
// Note that on a 32-bit machine I have just 8 bits for that. I think that
// will help with the first 8 packages I come across (or many more on a
// 64-bit machine). If I ever enable package support!
static constexpr uintptr_t  SYM_EXTERN_IN_HOME= 0x00800000;  // external in its home package
static constexpr uintptr_t  SYM_IN_PACKAGE    = 0xff000000U; //availability in 8 packages
static constexpr uintptr_t  SYM_IN_PKG_SHIFT  = 24;
static constexpr uintptr_t  SYM_IN_PKG_COUNT  = 8;
#else // COMMON
// In Standard Lisp mode I only allocate a print-name to a gensym when I
// first print it, so I have a bit that tells me when a gensym is still
// not printed.
static constexpr uintptr_t  SYM_UNPRINTED_GENSYM= 0x00800000; // not-yet-printed gensym
// Here in Standard Lisp mode I have 8 bits left in a symbol header even
// on a 32-bit system.
#endif // COMMON

typedef struct Symbol_Head_
{   Header header;       // Header as for other vector-like types
    LispObject value;    // Global or special value cell
//
    LispObject env;      // Extra stuff to help function cell
    LispObject plist;    // A list
//
    LispObject fastgets; // to speed up flagp and get
    LispObject package;  // Home package - a package object
//
    LispObject pname;    // A string (always)
    uint32_t countLow;   // for statistics
    uint32_t countHigh;  // for statistics
//
    no_args *function0;      // Executable code always (no arguments)
    one_arg *function1;      // Executable code always (just 1 arg)
//
    two_args *function2;     // Executable code always (just 2 args)
    three_args *function3;   // Executable code always (just 3 args)
//
    fourup_args *function4up;// Executable code always (3 args + list of rest)
} Symbol_Head;

inline constexpr uintptr_t word_align_up(uintptr_t n)
{   return static_cast<LispObject>((n + 3) & -static_cast<uintptr_t>(4U));
}

inline constexpr uintptr_t doubleword_align_up(uintptr_t n)
{   return static_cast<uintptr_t>((n + 7) & -static_cast<uintptr_t>(8U));
}

inline constexpr LispObject doubleword_align_up(LispObject n)
{   return static_cast<LispObject>(
        (static_cast<uintptr_t>(n) + 7) & -static_cast<uintptr_t>(8U));
}

inline constexpr uintptr_t doubleword_align_down(uintptr_t n)
{   return static_cast<uintptr_t>(
        static_cast<intptr_t>(n) & -static_cast<uintptr_t>(8U));
}

inline constexpr uintptr_t object_align_up(uintptr_t n)
{   return static_cast<uintptr_t>((n + sizeof(LispObject) - 1) &
        -static_cast<uintptr_t>(sizeof(LispObject)));
}

inline constexpr uintptr_t object_2_align_up(uintptr_t n)
{   return static_cast<uintptr_t>(
               (n + 2*sizeof(LispObject) - 1) &
               -(2*sizeof(LispObject)));
}

static constexpr size_t symhdr_length =
    doubleword_align_up(sizeof(Symbol_Head));

inline bool is_symbol_header(Header h)
{   return (static_cast<int>(h) & (0xf<<Tw)) == TYPE_SYMBOL;
}

inline bool is_symbol_header_full_test(Header h)
{   return (static_cast<int>(h) & ((0xf<<Tw) + TAG_BITS)) ==
           (TYPE_SYMBOL + TAG_HDR_IMMED);
}

inline int header_fastget(Header h)
{   return (h >> SYM_FASTGET_SHIFT) & 0x3f;
}

inline bool is_number_header_full_test(Header h)
{   return (static_cast<int>(h) & ((0x1d<<Tw) + TAG_BITS)) == ((
                0x1d<<Tw) + TAG_HDR_IMMED);
}

// The "vector" case here includes vector-like number cases
inline bool is_vector_header_full_test(Header h)
{   return is_odds(h) && ((static_cast<int>(h) & (0x3<<Tw)) != 0);
}

inline bool is_array_header(Header h)
{   return type_of_header(h) == TYPE_ARRAY;
}

// The codes for yyyyy are as follows:

//   xx:x00 0:0 010  symbol header
//   xx:x01 0:0 010  character
//   xx:x10 0:0 010  handle for bytecode. Why do I do it this way?
//   xx:x11 0:0 010  special marker identifier (Spid) for internal use
//
//   00:000 0:1 010  simple vector
//   00:001 0:1 010  array
//   00:010 0:1 010  structure
//   00:011 0:1 010  object
//   00:100 0:1 010  indexvec (used to implement huge vectors)
//   00:101 0:1 010  new style hash table
//   00:110 0:1 010  new hash table with rehash pending
//   00:111 0:1 010  index vector for huge bignum *
//   01:000 0:1 010  old style hash table
//   01:0xx 0:1 010  (spare: 4 codes)
//   01:111 0:1 010  rational number  *
//   10:0xx 0:1 010  stream and mixed1, 2 and 3
//   10:111 0:1 010  complex number   *
//   11:111 0:1 010  (spare, but classifies as a number)
//   1x:xxx 0:1 010  (spare: 14 codes)
//   11:111 0:1 010  used when calculating hash codes as if it was the
//                   header for a CONS cell.

//   yyy:yy 10 010  bit-vector with yyyyy (1 to 32) bits in final word.

// The final column here explains what size units of storage fit within
// the object. For (eg) "encapsulated general pointer" I have made it
// 64 and I should pad 32-bit cases to that width - but I do not expect
// those sorts of data to survive serialization, so I annotate them here
// as "64?".

//   00:000 1:1 010  vec8-1                         8
//   00:001 1:1 010  string-1                       8
//   00:010 1:1 010  bytecode-1                     8
//   00:011 1:1 010  vec16-1                        16
//   00:100 1:1 010  vec32                          32
//   00:101 1:1 010  vec64                          64
//   00:110 1:1 010  vec128                         128
//   00:111 1:1 010  bignum            *            32
//   01:000 1:1 010  vec8-2                         8
//   01:001 1:1 010  string-2                       8
//   01:010 1:1 010  bytecode-2                     8
//   01:011 1:1 010  maple-ref                      64?
//   01:100 1:1 010  foreign                        64?
//   01:101 1:1 010  encapsulated-sp                64?
//   01:110 1:1 010  encapsulated general pointer   64?
//   01:111 1:1 010  float32           *            F32
//   10:000 1:1 010  vec8-2                         8
//   10:001 1:1 010  string-3                       8
//   10:010 1:1 010  bytecode-3                     8
//   10:011 1:1 010  vec16-2                        16
//   10:100 1:1 010  vecflt32                       F32
//   10:101 1:1 010  vecflt64                       F64
//   10:110 1:1 010  vecflt128                      F128
//   10:111 1:1 010  float64           *            F64
//   11:000 1:1 010  vec8-3                         8
//   11:001 1:1 010  string-4                       8
//   11:010 1:1 010  bytecode-4                     8
// [[11:011 1:1 010  nativecode                     8]] NOT USED
//   11:100 1:1 010  (spare: 1 code)                X
//   11:101 1:1 010  (spare: 1 code)                X
//   11:110 1:1 010  padder vector                  X
//   11:111 1:1 010  float128          *            F128

// I have tests that let me discern the size of storage units within a
// vector. This matters for serialization and deserialization because the
// source and target machines may use different ordering for bytes within
// words etc.

// I use a bitmap scheme for all of these because that gives me uniformity
// and because I do not believe that special treatment of any of the
// case would do much better. I expect that strings and bignums will be
// the most common cases.

inline bool is_basic_vector(LispObject v)
{   return is_vector(v) && type_of_header(vechdr(v)) != TYPE_INDEXVEC;
}

inline bool vector_i8(Header h)
{   return ((0x7f070707u >> ((h >> (Tw+2)) & 0x1f)) & 1) != 0;
}

inline bool vector_i16(Header h)
{   return ((0x00080008u >> ((h >> (Tw+2)) & 0x1f)) & 1) != 0;
}

inline bool vector_i32(Header h)
{   return ((0x00000090u >> ((h >> (Tw+2)) & 0x1f)) & 1) != 0;
}

inline bool vector_i64(Header h)
{   return ((0x00007820u >> ((h >> (Tw+2)) & 0x1f)) & 1) != 0;
}

inline bool vector_i128(Header h)
{   return ((0x00000040u >> ((h >> (Tw+2)) & 0x1f)) & 1) != 0;
}

inline bool vector_f32(Header h)
{   return ((0x00108000u >> ((h >> (Tw+2)) & 0x1f)) & 1) != 0;
}

inline bool vector_f64(Header h)
{   return ((0x00a00000u >> ((h >> (Tw+2)) & 0x1f)) & 1) != 0;
}

inline bool vector_f128(Header h)
{   return ((0x80400000u >> ((h >> (Tw+2)) & 0x1f)) & 1) != 0;
}

inline LispObject& basic_elt(LispObject v, size_t n)
{   return *reinterpret_cast<LispObject *>
           (reinterpret_cast<char *>(v) +
            (CELL-TAG_VECTOR) +
            (n*sizeof(LispObject)));
}

inline bool vector_i8(LispObject n)
{   if (!is_vector(n)) return false;
    else if (is_basic_vector(n)) return vector_i8(vechdr(n));
    else return vector_i8(vechdr(basic_elt(n, 0)));
}

inline bool vector_i16(LispObject n)
{   if (!is_vector(n)) return false;
    else if (is_basic_vector(n)) return vector_i16(vechdr(n));
    else return vector_i16(vechdr(basic_elt(n, 0)));
}

inline bool vector_i32(LispObject n)
{   if (!is_vector(n)) return false;
    else if (is_basic_vector(n)) return vector_i32(vechdr(n));
    else return vector_i32(vechdr(basic_elt(n, 0)));
}

inline bool vector_i64(LispObject n)
{   if (!is_vector(n)) return false;
    else if (is_basic_vector(n)) return vector_i64(vechdr(n));
    else return vector_i64(vechdr(basic_elt(n, 0)));
}

inline bool vector_i128(LispObject n)
{   if (!is_vector(n)) return false;
    else if (is_basic_vector(n)) return vector_i128(vechdr(n));
    else return vector_i128(vechdr(basic_elt(n, 0)));
}

inline bool vector_f32(LispObject n)
{   if (!is_vector(n)) return false;
    else if (is_basic_vector(n)) return vector_f32(vechdr(n));
    else return vector_f32(vechdr(basic_elt(n, 0)));
}

inline bool vector_f64(LispObject n)
{   if (!is_vector(n)) return false;
    else if (is_basic_vector(n)) return vector_f64(vechdr(n));
    else return vector_f64(vechdr(basic_elt(n, 0)));
}

inline bool vector_f128(LispObject n)
{   if (!is_vector(n)) return false;
    else if (is_basic_vector(n)) return vector_f128(vechdr(n));
    else return vector_f128(vechdr(basic_elt(n, 0)));
}

// I have made the allocation so that any header of the form xx1:11x1:010
// is the header of a number. And the ...:..x.:... bit indicates whether
// the number is stored as binary or Lisp data. Thus rational and complex
// numbers are (pairs of) Lisp objects, while bignums and boxed floats have
// binary data. The case BIGNUMINDEX is for bignums that need more than
// 4 Mbytes of memory and is an index vector containing a number of lower-
// level vectors of binary information. That case is not supported yet, and
// there is a real prospect that I will rearrange storage layout strategies
// so it never is!

static constexpr uintptr_t TYPE_BIGNUMINDEX    = 0x1d<<Tw;
static constexpr uintptr_t TYPE_BIGNUM         = 0x1f<<Tw;
static constexpr uintptr_t TYPE_RATNUM         = 0x3d<<Tw;
static constexpr uintptr_t TYPE_SINGLE_FLOAT   = 0x3f<<Tw;
static constexpr uintptr_t TYPE_COMPLEX_NUM    = 0x5d<<Tw;
static constexpr uintptr_t TYPE_DOUBLE_FLOAT   = 0x5f<<Tw;
//      unused              = 0x7d<<Tw;
// While gradually working on a new implementation of big-numbers I will
// have a "TYPE_NEW_BIGNUM" for big integers represented using 64-bit
// digits. These well not be fully integrated with everything else!
static constexpr uintptr_t TYPE_NEW_BIGNUM     = 0x7d<<Tw;  // Temporary provision!
static constexpr uintptr_t TYPE_LONG_FLOAT     = 0x7f<<Tw;

inline Header &numhdr(LispObject v)
{   return *reinterpret_cast<Header *>(v - TAG_NUMBERS);
}

inline Header &flthdr(LispObject v)
{   return *reinterpret_cast<Header *>(v - TAG_BOXFLOAT);
}

inline void setnumhdr(LispObject v, Header h)
{   *reinterpret_cast<Header *>(
         reinterpret_cast<char *>(v) - TAG_NUMBERS) = h;
}

inline void setflthdr(LispObject v, Header h)
{   *reinterpret_cast<Header *>(
         reinterpret_cast<char *>(v) - TAG_BOXFLOAT) = h;
}

inline bool is_short_float(LispObject v)
{   if (!is_sfloat(v)) return false;
    if (SIXTY_FOUR_BIT && (v & XTAG_FLOAT32) != 0) return false;
    return true;
}

inline bool is_single_float(LispObject v)
{   if (SIXTY_FOUR_BIT && is_sfloat(v) &&
        (v & XTAG_FLOAT32) != 0) return true;
    return is_bfloat(v) && type_of_header(flthdr(v)) == TYPE_SINGLE_FLOAT;
}

inline bool is_double_float(LispObject v)
{   return is_bfloat(v) &&
           type_of_header(flthdr(v)) == TYPE_DOUBLE_FLOAT;
}

inline bool is_long_float(LispObject v)
{   return is_bfloat(v) &&
           type_of_header(flthdr(v)) == TYPE_LONG_FLOAT;
}

inline bool is_ratio(LispObject n)
{   return is_numbers(n) && type_of_header(numhdr(n)) == TYPE_RATNUM;
}

inline bool is_complex(LispObject n)
{   return is_numbers(n) && type_of_header(numhdr(n)) == TYPE_COMPLEX_NUM;
}

inline bool is_bignum_header(Header h)
{   return type_of_header(h) == TYPE_BIGNUM;
}

inline bool is_bignum(LispObject n)
{   return is_numbers(n) && is_bignum_header(numhdr(n));
}

inline bool is_new_bignum_header(Header h)
{   return type_of_header(h) == TYPE_NEW_BIGNUM;
}

inline bool is_new_bignum(LispObject n)
{   return is_numbers(n) && is_new_bignum_header(numhdr(n));
}

inline bool is_string_header(Header h)
{   return (type_of_header(h) & (0x1f<<Tw)) == TYPE_STRING_1;
}

inline bool is_simple_string(LispObject n)
{   if (!is_vector(n)) return false;
    else return is_string_header(vechdr(n));
}

inline bool is_string(LispObject n)
{   if (!is_vector(n)) return false;
    else if (is_basic_vector(n)) return is_string_header(vechdr(n));
    else return is_string_header(vechdr(basic_elt(n, 0)));
}

inline bool is_vec8_header(Header h)
{   return (type_of_header(h) & (0x1f<<Tw)) == TYPE_VEC8_1;
}

inline bool is_vec8(LispObject n)
{   if (!is_vector(n)) return false;
    else if (is_basic_vector(n)) return is_vec8_header(vechdr(n));
    else return is_vec8_header(vechdr(basic_elt(n, 0)));
}

inline bool is_bps_header(Header h)
{   return (type_of_header(h) & (0x1f<<Tw)) == TYPE_BPS_1;
}

inline bool is_bps(LispObject n)
{   return is_vector(n) && is_bps_header(vechdr(n));
}

inline bool is_vec16_header(Header h)
{   return (type_of_header(h) & (0x3f<<Tw)) == TYPE_VEC16_1;
}

inline bool is_vec16(LispObject n)
{   if (!is_vector(n)) return false;
    else if (is_basic_vector(n)) return is_vec16_header(vechdr(n));
    else  return is_vec16_header(vechdr(basic_elt(n, 0)));
}

inline bool is_bitvec_header(Header h)
{   return  (type_of_header(h) & (0x03<<Tw)) == TYPE_BITVEC_1;
}

inline bool is_bitvec(LispObject n)
{   if (!is_vector(n)) return false;
    else if (is_basic_vector(n)) return is_bitvec_header(vechdr(n));
    else  return is_bitvec_header(vechdr(basic_elt(n, 0)));
}

inline char& basic_celt(LispObject v, size_t n)
{   return *(reinterpret_cast<char *>(v) + (CELL-TAG_VECTOR) + n);
}

inline unsigned char& basic_ucelt(LispObject v, size_t n)
{   return *(reinterpret_cast<unsigned char *>(v) +
             (CELL-TAG_VECTOR) + n);
}

inline signed char& basic_scelt(LispObject v, size_t n)
{   return *(reinterpret_cast<signed char *>(v) +
             (CELL-TAG_VECTOR) + n);
}

static constexpr size_t BPS_DATA_OFFSET = CELL-TAG_VECTOR;

inline unsigned char* data_of_bps(LispObject v)
{   return reinterpret_cast<unsigned char *>(v) + BPS_DATA_OFFSET;
}


// In the serialization code I want to access the fields in a symbol as
// if that symbol was a vector and the fields were indexed as follows:
//  vselt(p, -1) : qheader(p)
//  vselt(p, 1)  : qenv(p)
//  vselt(p, 2)  : qplist(p)
//  vselt(p, 3)  : qfastgets(p)
//  vselt(p, 4)  : qpackage(p)
//  vselt(p, 5)  : qpname(p)
// and I want vselt to apply to vectors too and do just what elt does in
// that case. I will also use vselt on things tagged as numbers (specifically
// RATIO and COMPLEX. But note that the serialization code is handling
// structures in terms of their raw representation and so any issues of
// large vs basic vectors does not apply.

inline LispObject& vselt(LispObject v, size_t n)
{   return *reinterpret_cast<LispObject *>(
               (static_cast<intptr_t>(v) &
                ~(static_cast<intptr_t>(TAG_BITS))) +
               ((1 + n)*sizeof(LispObject)));
}

// The next are for 16-bit & 32 bit values and single-float & double-float
// access. Note that halfwords are signed.
//
// In days of ancient history some systems did not support 16-bit values.
// Specifically the DEC Alpha compilers did not have a 16-bit data type and
// ARM did not support 16-bit usage at all well. However these days I intend
// to expect that int16_t will exist and will be something I can rely on.
inline int16_t& basic_helt(LispObject v, size_t n)
{   return *reinterpret_cast<int16_t *>(reinterpret_cast<char *>
            (v) +
            (CELL-TAG_VECTOR) +
            n*sizeof(int16_t));
}

inline intptr_t& basic_ielt(LispObject v, size_t n)
{   return  *reinterpret_cast<intptr_t *>(reinterpret_cast<char *>
                                          (v) +
                                          (CELL-TAG_VECTOR) +
                                          n*sizeof(intptr_t));
}

// Even on a 64-bit machine I will support packed arrays of 32-bit
// ints or short-floats.
inline int32_t& basic_ielt32(LispObject v, size_t n)
{   return *reinterpret_cast<int32_t *>(reinterpret_cast<char *>(v) +
                                        (CELL-TAG_VECTOR) +
                                        n*sizeof(int32_t));
}

inline float& basic_felt(LispObject v, size_t n)
{   return *reinterpret_cast<float *>(reinterpret_cast<char *>(v) +
                                      (CELL-TAG_VECTOR) +
                                      n*sizeof(float));
}

inline double& basic_delt(LispObject v, size_t n)
{   return *reinterpret_cast<double *>(reinterpret_cast<char *>(v) +
                                       (8-TAG_VECTOR) +
                                       n*sizeof(double));
}

// The above provide support for "basic" vectors, which have a limitation
// that they can only be up to around 4 Mbytes in size - which on a 64-bit
// system means that a normal Lisp vector can only have up to around half
// a million elements. Using a two-level structure with TYPE_INDEXVEC for
// the upper one allows vectors to get MUCH MUCH bigger. This scheme
// builds vectors out of 

static constexpr size_t LOG2_VECTOR_CHUNK_BYTES = PAGE_BITS-2;
static constexpr size_t VECTOR_CHUNK_BYTES =
    static_cast<size_t>(1)<<LOG2_VECTOR_CHUNK_BYTES;

// With the above large vectors are represented in chunks each of which is
// 1 Megabyte in size. That is smaller than the storage allocation chunk size
// so that I do not lose TOO much space to fragmentation there. Well I
// may lose 25%. Like this the largest 2-level structure on a 64-bit
// machine will have around 0.5 million sub-vectors, each of size a megabyte.
// that is 2^39 bytes, and so if this is used to store LispObjects there can
// be up to 2^36 of them. That is 64G cells, consuming 512GBytes of memory.
// At present (2019) that seems an acceptable limit. If at some stage (!) it
// became essential to go yet further the natural thing would be to increase
// the basic memory allocation block size from 4 Mbytes upwards, and each
// doubling of that could allow me to increase the largest vector size by
// a factor of 4. Note that the above limit is on the size of a single
// individual vector, and so mmy current limit is really unlikely to become
// and issue until people are using computers with several terabytes of
// main memory.

inline bool is_power_of_two(uint64_t n)
{   return (n == (n & (-n)));
}

inline unsigned int intlog2(uint64_t n)
{
// This fragment takes a 64-bit number that is a power of 2 and
// finds its logarithm, ie the number of bits that 1 needs to be shifted
// left to yield it. The function will return garbage if its input is
// not a power of 2.
//
// This table works because it is of length 67 and that is a prime, so
// the sequence 2^i mod 67 cycles through 1 .. 66 as I runs from 0 to 65,
// and 2^66 = 2^0 (mod 67). To help show this I have annotated the items at
// offsets 1, 2, 4, 8, 16, 32 and 64.
    static constexpr unsigned char intlog2_table[] =
    {   0,      0,/*1*/ 1,/*2*/ 39,     2,/*4*/ 15,     40,     23,
        3,/*8*/ 12,     16,     59,     41,     19,     24,     54,
        4,/*16*/0,      13,     10,     17,     62,     60,     28,
        42,     30,     20,     51,     25,     44,     55,     47,
        5,/*32*/32,     0,      38,     14,     22,     11,     58,
        18,     53,     63,     9,      61,     27,     29,     50,
        43,     46,     31,     37,     21,     57,     52,     8,
        26,     49,     45,     36,     56,     7,      48,     35,
        6,/*64*/34,     33
    };
    return intlog2_table[n % (sizeof(intlog2_table)/sizeof(unsigned char))];
}

// In the past when something is tagged TAG_VECTOR I have used
// type_of_header(vechdr(v)) to detect its type. In the future
// I should in general use type_of_vector(cv) because that can cope
// with "large" as well as basic vector. Doing so somewhat relies on
// a "sufficiently clever compiler" inlining the functions and then
// observing that vechdr(v) is a value common to several of the paths,
// and even that type_of_header(vechdr(v)) is something where repeated
// evaluation can be avoided.

inline int type_of_vector(LispObject v)
{   if (is_basic_vector(v)) return type_of_header(vechdr(v));
    else return type_of_header(vechdr(basic_elt(v, 0)));
}

// In the past I have tended to use length_of_header() to get the size
// of vectors. I now intend to move towards use of this function -
// bytes_in_vector will find the size in bytes of active data excluding
// and header words, and cells_in_vector() will get the number of
// LispObjects that can be stored.

inline size_t bytes_in_bytevector(LispObject v)
{   if (is_basic_vector(v)) return length_of_byteheader(vechdr(v)) - CELL;
    size_t n = (length_of_header(vechdr(v))-CELL)/CELL;
// Observe that the final chunk has its length treated individually. This
// adds to the cost, but the extra cost only arises when the vector is
// rather large to start with, and so I am not going to worry.
    return VECTOR_CHUNK_BYTES*(n-1) +
           length_of_byteheader(vechdr(basic_elt(v, n-1))) - CELL;
}

inline size_t hwords_in_hwordvector(LispObject v)
{   if (is_basic_vector(v)) return length_of_hwordheader(vechdr(v)) - (CELL/2);
    size_t n = (length_of_header(vechdr(v))-CELL)/CELL;
// Observe that the final chunk has its length treated individually. This
// adds to the cost, but the extra cost only arises when the vector is
// rather large to start with, and so I am not going to worry.
    return (VECTOR_CHUNK_BYTES/2)*(n-1) +
           length_of_hwordheader(vechdr(basic_elt(v, n-1))) - (CELL/2);
}

inline size_t bits_in_bitvector(LispObject v)
{   if (is_basic_vector(v)) return length_of_bitheader(vechdr(v)) - 8*CELL;
    size_t n = (length_of_header(vechdr(v))-CELL)/CELL;
// Observe that the final chunk has its length treated individually. This
// adds to the cost, but the extra cost only arises when the vector is
// rather large to start with, and so I am not going to worry.
    return (8*VECTOR_CHUNK_BYTES)*(n-1) +
           length_of_bitheader(vechdr(basic_elt(v, n-1))) - 8*CELL;
}

// This is the general one, and it is applicable to any sort of
// vector with elements of size at least 4 bytes.

inline size_t bytes_in_vector(LispObject v)
{   if (is_basic_vector(v)) return length_of_header(vechdr(v)) - CELL;
    size_t n = (length_of_header(vechdr(v))-CELL)/CELL;
// Observe that the final chunk has its length treated individually. This
// adds to the cost, but the extra cost only arises when the vector is
// rather large to start with, and so I am not going to worry.
    return VECTOR_CHUNK_BYTES*(n-1) +
           length_of_header(vechdr(basic_elt(v, n-1))) - CELL;
}

inline size_t cells_in_vector(LispObject v)
{   return bytes_in_vector(v)/CELL;
}

inline bool vector_holds_binary(LispObject v)
{   if (is_basic_vector(v)) return vector_holds_binary(vechdr(v));
    else return vector_holds_binary(vechdr(basic_elt(v, 0)));
}

// the table of free vectors is not saved across checkpoint/restore operations,
// and so issues of 64- vs 32-bit sizing in that context do not arise.

extern LispObject free_vectors[LOG2_VECTOR_CHUNK_BYTES+1];

inline void discard_basic_vector(LispObject v)
{   size_t size = length_of_header(vechdr(v));
// I should never try to discard a vector that has a size that is not
// a multiple of CELL. If I did then the division on the next line could
// truncate to potential bad effect.
    size_t n = size/CELL - 1;
    if (is_power_of_two(n))    // save if this has byte-count 2^i
    {   unsigned int i = intlog2(n); // identify what power of 2 we have
        if (i <= LOG2_VECTOR_CHUNK_BYTES)
        {   basic_elt(v, 0) = free_vectors[i];
// I put the discarded vector in the free-chain as a "simple vector"
// regardless of what it used to be. If it has contained binary information
// its contents will not be GC safe - but the GC should never encounter it
// so that should not matter.
            setvechdr(v,TYPE_SIMPLE_VEC +
                      (size << (Tw+5)) +
                      TAG_HDR_IMMED);
            v = (v & ~reinterpret_cast<uintptr_t>(TAG_BITS)) | TAG_VECTOR;
            free_vectors[i] = v;
        }
    }
}

inline void discard_vector(LispObject v)
{   if (is_basic_vector(v)) discard_basic_vector(v);
    else
    {   size_t n1 = length_of_header(vechdr(v))/CELL - 1;
        for (size_t i=0; i<n1; i++)
            discard_basic_vector(basic_elt(v, i));
        discard_basic_vector(v);
    }
}

// elt() and friends will now work on large or basic vectors.
// I should probably consider using a template to generate the code
// here.

inline LispObject& elt(LispObject v, size_t n)
{   if (is_basic_vector(v)) return basic_elt(v, n);
    return basic_elt(basic_elt(v, n/(VECTOR_CHUNK_BYTES/CELL)),
                     n%(VECTOR_CHUNK_BYTES/CELL));
}

inline char& celt(LispObject v, size_t n)
{   if (is_basic_vector(v)) return basic_celt(v, n);
    return basic_celt(basic_elt(v, n/VECTOR_CHUNK_BYTES),
                      n%VECTOR_CHUNK_BYTES);
}

inline unsigned char& ucelt(LispObject v, size_t n)
{   if (is_basic_vector(v)) return basic_ucelt(v, n);
    return basic_ucelt(basic_elt(v, n/VECTOR_CHUNK_BYTES),
                       n%VECTOR_CHUNK_BYTES);
}

inline signed char& scelt(LispObject v, size_t n)
{   if (is_basic_vector(v)) return basic_scelt(v, n);
    return basic_scelt(basic_elt(v, n/VECTOR_CHUNK_BYTES),
                       n%VECTOR_CHUNK_BYTES);
}

inline int16_t& helt(LispObject v, size_t n)
{   if (is_basic_vector(v)) return basic_helt(v, n);
    return basic_helt(elt(v, n/(VECTOR_CHUNK_BYTES/sizeof(int16_t))),
                      n%(VECTOR_CHUNK_BYTES/sizeof(int16_t)));
}

inline intptr_t& ielt(LispObject v, size_t n)
{   if (is_basic_vector(v)) return basic_ielt(v, n);
    return basic_ielt(
               elt(v, n/(VECTOR_CHUNK_BYTES/sizeof(intptr_t))),
               n%(VECTOR_CHUNK_BYTES/sizeof(intptr_t)));
}

inline int32_t& ielt32(LispObject v, size_t n)
{   if (is_basic_vector(v)) return basic_ielt32(v, n);
    return basic_ielt32(elt(v, n/(VECTOR_CHUNK_BYTES/sizeof(int32_t))),
                        n%(VECTOR_CHUNK_BYTES/sizeof(int32_t)));
}

inline float& felt(LispObject v, size_t n)
{   if (is_basic_vector(v)) return basic_felt(v, n);
    return basic_felt(elt(v, n/(VECTOR_CHUNK_BYTES/sizeof(float))),
                      n%(VECTOR_CHUNK_BYTES/sizeof(float)));
}

inline double& delt(LispObject v, size_t n)
{   if (is_basic_vector(v)) return basic_delt(v, n);
    return basic_delt(elt(v, n/(VECTOR_CHUNK_BYTES/sizeof(double))),
                      n%(VECTOR_CHUNK_BYTES/sizeof(double)));
}

inline bool is_header(LispObject x)
{   return (static_cast<int>(x) & (0x3<<Tw)) != 0; // valid if TAG_HDR_IMMED
}

inline bool is_char(LispObject x)
{   return (static_cast<int>(x) & HDR_IMMED_MASK) == TAG_CHAR;
}

inline bool is_spid(LispObject x)
{   return (static_cast<int>(x) & HDR_IMMED_MASK) == TAG_SPID;
}

inline bool is_library(LispObject x)
{   return (static_cast<int>(x) & 0xfffff) == SPID_LIBRARY;
}

inline bool is_exception(LispObject x)
{   return (static_cast<int>(x) & 0xfffff) == SPID_ERROR;
}

inline unsigned int library_number(LispObject x)
{   return (x >> 20) & 0xfff;
}

inline int exception_type(LispObject x)
{   return (x >> 20) & 0xfff;
}

// I will now support the full range of Unicode from U+0000 to U+10FFFF.
//
// Note that pack_char now takes a 21-bit code but only values up to
// 0x0010ffff are valid for Unicode. Internally I will generally pack
// things using utf-8 encoded strings.

// The absolute shift values here reflect the fact that I have (at least)
// 25 bits of payload in a CHAR object. It is not at all obvious to me that
// the Common Lisp "font" component of characters was a good idea to start
// with or that it has any respectable purpose today, and I only support
// 16 distinct "Font" codes when I am on 32-bit hardware.

inline constexpr int font_of_char(LispObject n)
{   return (static_cast<int32_t>(n) >> (21+4+Tw)) & 0xf;
}

// The Common Lisp "bits" part of a character object no longer makes any sense!
inline constexpr int bits_of_char(LispObject n)
{   return 0;
}

inline constexpr unsigned int code_of_char(LispObject n)
{   return   (static_cast<uint32_t>(n) >>  (4+Tw)) & 0x001fffff;
}

inline constexpr LispObject pack_char(int font, unsigned int code)
{   return static_cast<LispObject>(
               ((static_cast<uint32_t>(font)) << (21+4+Tw)) |
               ((static_cast<uint32_t>(code)) << (4+Tw)) | TAG_CHAR);
}

// For internal purposes here I will use a pseudo-character with code
// 0x0010ffff to stand for an end of file marker. This can be packed as
// 4 bytes in utf-8 (f4/8f/bf/bf) and it is the last codepoint in the
// Unicode range and is reserved in Unicode as not being a valid
// character.
static constexpr LispObject CHAR_EOF = pack_char(0, 0x0010ffff);

static constexpr size_t MAX_FASTGET_SIZE = 63;
// I have up to 63 "fast" tags for PUT/GET/FLAG/FLAGP

inline Header &qheader(LispObject p)
{   return reinterpret_cast<Symbol_Head *>(p-TAG_SYMBOL)->header;
}

inline LispObject &qvalue(LispObject p)
{   return reinterpret_cast<Symbol_Head *>(p-TAG_SYMBOL)->value;
}

inline LispObject &qenv(LispObject p)
{   return reinterpret_cast<Symbol_Head *>(p-TAG_SYMBOL)->env;
}

inline LispObject &qplist(LispObject p)
{   return reinterpret_cast<Symbol_Head *>(p-TAG_SYMBOL)->plist;
}

inline LispObject &qfastgets(LispObject p)
{   return reinterpret_cast<Symbol_Head *>(p-TAG_SYMBOL)->fastgets;
}

inline LispObject &qpackage(LispObject p)
{   return reinterpret_cast<Symbol_Head *>(p-TAG_SYMBOL)->package;
}

inline LispObject &qpname(LispObject p)
{   return reinterpret_cast<Symbol_Head *>(p-TAG_SYMBOL)->pname;
}

inline LispObject *valueaddr(LispObject p)
{   return &(reinterpret_cast<Symbol_Head *>(p-TAG_SYMBOL)->value);
}

inline LispObject *envaddr(LispObject p)
{   return &(reinterpret_cast<Symbol_Head *>(p-TAG_SYMBOL)->env);
}

inline LispObject *plistaddr(LispObject p)
{   return &(reinterpret_cast<Symbol_Head *>(p-TAG_SYMBOL)->plist);
}

inline LispObject *fastgetsaddr(LispObject p)
{   return &(reinterpret_cast<Symbol_Head *>(p-TAG_SYMBOL)->fastgets);
}

inline LispObject *packageaddr(LispObject p)
{   return &(reinterpret_cast<Symbol_Head *>(p-TAG_SYMBOL)->package);
}

inline LispObject *pnameaddr(LispObject p)
{   return &(reinterpret_cast<Symbol_Head *>(p-TAG_SYMBOL)->pname);
}

inline void setheader(LispObject p, Header h)
{   reinterpret_cast<Symbol_Head *>(p-TAG_SYMBOL)->header = h;
}

inline void setvalue(LispObject p, LispObject q)
{   reinterpret_cast<Symbol_Head *>(p-TAG_SYMBOL)->value = q;
}

inline void setenv(LispObject p, LispObject q)
{   reinterpret_cast<Symbol_Head *>(p-TAG_SYMBOL)->env = q;
}

inline void setplist(LispObject p, LispObject q)
{   reinterpret_cast<Symbol_Head *>(p-TAG_SYMBOL)->plist = q;
}

inline void setfastgets(LispObject p, LispObject q)
{   reinterpret_cast<Symbol_Head *>(p-TAG_SYMBOL)->fastgets = q;
}

inline void setpackage(LispObject p, LispObject q)
{   reinterpret_cast<Symbol_Head *>(p-TAG_SYMBOL)->package = q;
}

inline void setpname(LispObject p, LispObject q)
{   reinterpret_cast<Symbol_Head *>(p-TAG_SYMBOL)->pname = q;
}

inline no_args*& qfn0(LispObject p)
{   return reinterpret_cast<Symbol_Head *>(p-TAG_SYMBOL)->function0;
}

inline one_arg*& qfn1(LispObject p)
{   return reinterpret_cast<Symbol_Head *>(p-TAG_SYMBOL)->function1;
}

inline two_args*& qfn2(LispObject p)
{   return reinterpret_cast<Symbol_Head *>(p-TAG_SYMBOL)->function2;
}

inline three_args*& qfn3(LispObject p)
{   return reinterpret_cast<Symbol_Head *>(p-TAG_SYMBOL)->function3;
}

inline fourup_args*& qfn4up(LispObject p)
{   return reinterpret_cast<Symbol_Head *>(p-TAG_SYMBOL)->function4up;
}

extern LispObject aerror1(const char *s, LispObject a);

// When I have functions with 4 or more args I may need to
// extract them..

inline LispObject arg4(const char *name, LispObject a4up)
{   if (cdr(a4up) != nil) return aerror1(name, a4up);
                          // Too many args provided
    return car(a4up);
}

inline bool a4a5(const char *name, LispObject a4up,
                 LispObject& a4, LispObject& a5)
{   a4 = car(a4up);
    a4up = cdr(a4up);
    if (a4up==nil ||
        cdr(a4up) != nil)
    {   aerror1(name, a4up);     // wrong number
        return true;
    }
    a5 = car(a4up);
    return false;
}

inline bool a4a5a6(const char *name, LispObject a4up,
                   LispObject& a4, LispObject& a5, LispObject& a6)
{   a4 = car(a4up);
    a4up = cdr(a4up);
    if (a4up == nil)
    {   aerror1(name, a4up); // not enough args
        return true;
    }
    a5 = car(a4up);
    a4up = cdr(a4up);
    if (a4up==nil ||
        cdr(a4up) != nil)
    {   aerror1(name, a4up); // wrong number
        return true;
    }
    a6 = car(a4up);
    return false;
}

// I store qcount as an unsigned 64-bit integer, but because on some
// 32-bit machines one needs to take extra stape to get support for
// 64-bit atomic values I will keep it as two 32-bit parts. This is
// clearly clumsy and will slow things down, but I only access the count
// field when I am in the bootstrap process not in production code and
// so I will not worry a lot.
// Furthermore I will use the low 22 bits of this field not as a count but
// as a serial number for the symbol concerned, accessible via id2Int.
// This allows for around 4 million symbols (including gensyms) before the
// field wraps. It leaves 42 bits for the genuine bytecount. That could
// overflow on a calculation that lasted an hour or so!

inline uint32_t& qcountLow(LispObject p)
{   return reinterpret_cast<Symbol_Head *>(p-TAG_SYMBOL)->countLow;
}

inline uint32_t& qcountHigh(LispObject p)
{   return reinterpret_cast<Symbol_Head *>(p-TAG_SYMBOL)->countHigh;
}

inline uint64_t qcount(LispObject p)
{   Symbol_Head *pp = reinterpret_cast<Symbol_Head *>(p-TAG_SYMBOL);
    return (static_cast<uint64_t>(pp->countHigh)<<32 | pp->countLow)>>22;
}

// The amount that the count should be incremented here must not be
// greater than 1023.

inline void incCount(LispObject p, uint32_t m=1)
{   Symbol_Head *pp = reinterpret_cast<Symbol_Head *>(p-TAG_SYMBOL);
    m <<= 22;
    uint32_t low = pp->countLow += m;
    if (low < m) pp->countHigh++;
}

#ifndef HAVE_SOFTFLOAT
typedef struct _float32_t
{   uint32_t v;
} float32_t;

typedef struct _float64_t
{   uint64_t v;
} float64_t;
#endif

typedef union _Float_union
{   float f;
    uint32_t i;
    float32_t f32;
} Float_union;

// The following macro clears any bits in a LispObject above the
// bottom 32.

inline LispObject low32(LispObject a)
{   return static_cast<LispObject>(static_cast<uint32_t>(a));
}

typedef struct Big_Number_
{
// see "arith.h" for a description of bignum formats
    Header h;
// EVEN when I have 64-bit addresses I will represent
// big-numbers as arrays of 32-bit values.  So I will still have to
// ensure that I end up with a rounded number of digits - but in the
// 64-bit case it will need to be an even number because the
// header word at the front of a bignum becomes 64-bits long.
    uint32_t d[1];  // generally more digits than this
} Big_Number;

inline size_t bignum_length(LispObject b)
{   return length_of_header(numhdr(b));
}

inline uint32_t* bignum_digits(LispObject b)
{   return reinterpret_cast<uint32_t *>(
               reinterpret_cast<char *>(b)  + (CELL-TAG_NUMBERS));
}

inline uint32_t* vbignum_digits(LispObject b)
{   return reinterpret_cast<uint32_t *>(
               reinterpret_cast<char *>(b)  + (CELL-TAG_NUMBERS));
}

// For work on bignums when I have a 64-bit machine I frequently need the
// top word of a bignum as a 64-bit (signed) value...
inline int64_t bignum_digits64(LispObject b, size_t n)
{   return static_cast<int64_t>(
               reinterpret_cast<int32_t *>(
                   reinterpret_cast<char *>(b)+(CELL-TAG_NUMBERS))[n]);
}


// make_bighdr takes an argument measured in 32-bit units, including space
// for the header word. This is the natural space unit used in the tagging
// scheme so I just need to shift the count to where it has to live.
inline Header make_bighdr(size_t n)
{   return TAG_HDR_IMMED+TYPE_BIGNUM+(n<<(Tw+7));
}

// New bignums come in 64-bit units.

inline Header make_new_bighdr(size_t n)
{   return TAG_HDR_IMMED+TYPE_NEW_BIGNUM+(n<<(Tw+8));
}

inline uint64_t* new_bignum_digits(LispObject b)
{   return reinterpret_cast<uint64_t *>(
               reinterpret_cast<char *>(b)  + (8-TAG_NUMBERS));
}

// pack_hdrlength takes a length in 32-bit words (including the size of
// the header). NOTE VERY WELL that although the other header length packers
// take a count of items this one takes a length in 32-bit words!
inline uintptr_t pack_hdrlength(size_t n)
{   return static_cast<intptr_t>(n)<<(Tw+7);
}

typedef struct Rational_Number_
{   Header header;
    LispObject num;
    LispObject den;
} Rational_Number;

inline LispObject numerator(LispObject r)
{   return ((Rational_Number *)(reinterpret_cast<char *>
                                (r)-TAG_NUMBERS))->num;
}

inline LispObject denominator(LispObject r)
{   return ((Rational_Number *)(reinterpret_cast<char *>
                                (r)-TAG_NUMBERS))->den;
}

inline void setnumerator(LispObject r, LispObject v)
{   ((Rational_Number *)(reinterpret_cast<char *>
                         (r)-TAG_NUMBERS))->num = v;
}

inline void setdenominator(LispObject r, LispObject v)
{   ((Rational_Number *)(reinterpret_cast<char *>
                         (r)-TAG_NUMBERS))->den = v;
}

typedef struct Complex_Number_
{   Header header;
    LispObject real;
    LispObject imag;
} Complex_Number;

inline LispObject real_part(LispObject r)
{   return ((Complex_Number *)(reinterpret_cast<char *>
                               (r)-TAG_NUMBERS))->real;
}

inline LispObject imag_part(LispObject r)
{   return ((Complex_Number *)(reinterpret_cast<char *>
                               (r)-TAG_NUMBERS))->imag;
}

inline void setreal_part(LispObject r, LispObject v)
{   ((Complex_Number *)(reinterpret_cast<char *>
                        (r)-TAG_NUMBERS))->real = v;
}

inline void setimag_part(LispObject r, LispObject v)
{   ((Complex_Number *)(reinterpret_cast<char *>
                        (r)-TAG_NUMBERS))->imag = v;
}

typedef struct Single_Float_
{   Header header;
    union float_or_int
    {   float f;
        float32_t f32;
        int32_t i;
    } f;
} Single_Float;

inline float& single_float_val(LispObject v)
{   return ((Single_Float *)(reinterpret_cast<char *>
                             (v)-TAG_BOXFLOAT))->f.f;
}

inline float32_t& float32_t_val(LispObject v)
{   return ((Single_Float *)(reinterpret_cast<char *>
                             (v)-TAG_BOXFLOAT))->f.f32;
}

inline int32_t& intfloat32_t_val(LispObject v)
{   return ((Single_Float *)(reinterpret_cast<char *>
                             (v)-TAG_BOXFLOAT))->f.i;
}

// The structures here are not actually used - because I can not get
// as strong control of alignment as I would like. So I use macros that
// do address arithmetic explicitly for me...
//
//  typedef struct Double_Float_
//  {
//      Header header;
//  // I want the data to 
//      alignas (8) union double_or_ints {
//          double f;
//          float64_t f64;
//          int32_t i[2];
//          int64_t ii;
//      } f;
//  } Double_Float;

typedef union _Double_union
{   double f;
    uint32_t i[2];
    uint64_t i64;
    float64_t f64;

} Double_union;

static constexpr size_t SIZEOF_DOUBLE_FLOAT = 16;
inline double *double_float_addr(LispObject v)
{   return reinterpret_cast<double *>(reinterpret_cast<char *>(v) +
                                      (8-TAG_BOXFLOAT));
}

// on 32-bit machines there has to be a padding work in a double_float,
// and this lets me clear it out.
inline int32_t& double_float_pad(LispObject v)
{   return *reinterpret_cast<int32_t *>(reinterpret_cast<char *>
                                        (v) + (4-TAG_BOXFLOAT));
}

inline double& double_float_val(LispObject v)
{   return *reinterpret_cast<double *>(reinterpret_cast<char *>(v) +
                                       (8-TAG_BOXFLOAT));
}

inline float64_t& float64_t_val(LispObject v)
{   return *reinterpret_cast<float64_t *>(reinterpret_cast<char *>
                                          (v) + (8-TAG_BOXFLOAT));
}

inline int64_t& intfloat64_t_val(LispObject v)
{   return *reinterpret_cast<int64_t *>(reinterpret_cast<char *>
                                        (v) + (8-TAG_BOXFLOAT));
}

inline int32_t& intfloat64_t_val_hi(LispObject v)
{   return *reinterpret_cast<int32_t *>(reinterpret_cast<char *>
                                        (v) + (8-TAG_BOXFLOAT));
}

inline int32_t& intfloat64_t_val_lo(LispObject v)
{   return *reinterpret_cast<int32_t *>(
               reinterpret_cast<char *>(v) + (12-TAG_BOXFLOAT));
}

// Again I do not actually introduce the struct...
//
// For "long double" I use float128_t as implemented in the SoftFloat_3a
// library. This represents each float with 16-bits of exponent and 113
// bits of mantissa (including the hidden bit). Basic arithmetic is
// supported, but not the elementary functions. I am going to ASSUME that
// everything can be aligned at 8-byte boundaries.
//
//  typedef struct Long_Float_
//  {
//      Header header;
//  What follows ALWAYS starts exactly 8 bytes on from the start
//  of the object, ie (8-TAG_BOXFLOAT) bytes on from the tagged pointer
//  that identifies it.
//      alignas (8) union long_or_ints {
//          float128_t f128;
//          int32_t i[4];
//          int64_t ii[2];
//      } f;
//  } Long_Float;

#ifdef HAVE_SOFTFLOAT
static constexpr size_t SIZEOF_LONG_FLOAT = 24;
inline float128_t *long_float_addr(LispObject v)
{   return (float128_t *)(reinterpret_cast<char *>(v) +
                          (8-TAG_BOXFLOAT));
}

inline int32_t& long_float_pad(LispObject v)
{   return *reinterpret_cast<int32_t *>(reinterpret_cast<char *>
                                        (v) + (4-TAG_BOXFLOAT));
}

inline float128_t& long_float_val(LispObject v)
{   return *reinterpret_cast<float128_t *>(reinterpret_cast<char *>
                                           (v) + (8-TAG_BOXFLOAT));
}

inline float128_t& float128_t_val(LispObject v)
{   return *reinterpret_cast<float128_t *>(reinterpret_cast<char *>
                                           (v) + (8-TAG_BOXFLOAT));
}

inline int64_t& intfloat128_t_val0(LispObject v)
{   return *reinterpret_cast<int64_t *>(
               reinterpret_cast<char *>(
                   v) + (8-TAG_BOXFLOAT));
}

inline int64_t& intfloat128_t_val1(LispObject v)
{   return *reinterpret_cast<int64_t *>(
               reinterpret_cast<char *>(
                   v) + (16-TAG_BOXFLOAT));
}

inline int32_t& intfloat128_t_val32_0(LispObject v)
{   return *reinterpret_cast<int32_t *>(
               reinterpret_cast<char *>(v) + (8-TAG_BOXFLOAT));
}

inline int32_t& intfloat128_t_val32_1(LispObject v)
{   return *reinterpret_cast<int32_t *>(
               reinterpret_cast<char *>(v) + (12-TAG_BOXFLOAT));
}

inline int32_t& intfloat128_t_val32_2(LispObject v)
{   return *reinterpret_cast<int32_t *>(
               reinterpret_cast<char *>(
                   v) + (16-TAG_BOXFLOAT));
}

inline int32_t& intfloat128_t_val32_3(LispObject v)
{   return *reinterpret_cast<int32_t *>(
               reinterpret_cast<char *>(v) + (20-TAG_BOXFLOAT));
}
#endif // HAVE_SOFTFLOAT

// Values to go in exit_reason at times when exceptions are being thrown.

static constexpr uintptr_t UNWIND_NULL     = 0x0;   // no error or action at all
static constexpr uintptr_t UNWIND_GO       = 0x1;   // GO, to support non-local case
static constexpr uintptr_t UNWIND_RETURN   = 0x2;   // RETURN, to support non-local
static constexpr uintptr_t UNWIND_THROW    = 0x3;   // THROW is obvious
static constexpr uintptr_t UNWIND_RESTART  = 0x4;   // (restart!-csl ...)
static constexpr uintptr_t UNWIND_RESOURCE = 0x5;   // used with (resource!-limit ...)
//static constexpr uintptr_t UNWIND_SIGINT = 0x6;   // SIGINT

static constexpr uintptr_t UNWIND_FNAME    = 0x100; // at least short backtrace is needed
static constexpr uintptr_t UNWIND_ARGS     = 0x200; // produce long form backtrace
static constexpr uintptr_t UNWIND_ERROR    = (UNWIND_FNAME|UNWIND_ARGS);
static constexpr uintptr_t UNWIND_UNWIND   = 0x400; // no backtrace, still an error

#define SHOW_FNAME  ((exit_reason & UNWIND_FNAME) != 0)
#define SHOW_ARGS   ((exit_reason & UNWIND_ARGS) != 0)

// Styles or flavours of hash table.

static constexpr int HASH_AS_EQ        = 0;
static constexpr int HASH_AS_EQL       = 1;
static constexpr int HASH_AS_CL_EQUAL  = 2;
static constexpr int HASH_AS_EQUAL     = 3;
static constexpr int HASH_AS_EQUALP    = 4;
static constexpr int HASH_AS_SYMBOL    = 5;
static constexpr int HASH_AS_SXHASH    = 6;

#endif // header_tags_h

// end of tags.h
