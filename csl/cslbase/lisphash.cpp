// lisphash.cpp                                       A C Norman, 2020-2022

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

// This is a refresh of the Lisp hash table support for CSL, installed
// in 2017. It uses a scheme fairly traditional double hashing and by
// keeping the tables acceptably lightly loaded the average costs should
// be pretty good. Tables are marked as out of date by garbage collection
// and then rehashed if necessary when next accessed, so that any dormant
// tables do not get rehashed when that is not necessary.

#include "headers.h"

// Various internal functions that work on hash tables return either an
// index into a table or the marker value NOT_PRESENT.

#define NOT_PRESENT (SIZE_MAX)

#define TRACE 1

// This is an implementation of hash tables intended to be used when the
// keys in the table are structures of some sort. It might be useful for
// strings or structures representing symbols, or for more general large
// objects. There are two points to the issue of what the hashed items will
// be. The first is that the table will contain references to objects not
// the objects themselves - and this means that checking objects will
// access memory in ways that could involve cache misses. This is a different
// scenario from the one where keys are integers or other immediate data.
// The second issue is that both computing hash values and comparing keys
// may have significant cost, and in particular the costs there may be
// higher than general administration activity on the table itself.
//
// As with any general hash table implementation I occasionally need to
// expand or contract the table and re-hash.
//
// I write HASH() for the code that will compute a hash function, and
// COMPARE() for key comparison. COMPARE should never be called with an
// EMPTY or TOMBSTONE value, and that may at times allow a minor optimisation
// in its implementation.

// The following are the components that make up a hash table...

#define HASH_FLAVOUR    0  // EQ, EQL, ...
#define HASH_COUNT      1  // number of active keys (including tombstones).
#define HASH_SHIFT      2  // implies the total table size.
#define HASH_KEYS       3  // vector of keys.
#define HASH_VALUES     4  // vector of values if required.

// The multiplier is sort or arbitrary. The following is 2^64*0.6180339...
// where the multiplier is the golden ratio.
#define HASH_MULTIPLIER UINT64_C(0x9e3779b97f4a7c15)

// While performing operations on a table I will often load its components
// info some of the following static variables. When and if I move to
// a multi-threaded world I will need these to use thread local storage.

static LispObject h_table, v_table;
static int h_shift;
static size_t h_table_size;

typedef uint64_t hash_function_t(uint64_t r, LispObject key);
typedef bool hash_compare_t(LispObject key, LispObject hashentry);

static hash_function_t *hash_function;
static hash_compare_t  *hash_compare;

// The primary hash key is computed in a way that has to depend on the
// hashing regime in use. If hashing is based on the EQ test then it
// can be along the lines of (HASH_MULTIPLIER*key), while for EQUAL and
// other more elaborate  cases it will need to descend into the
// representation of its key.

inline void UPDATE(uint64_t& r, uint64_t x)
{   r = HASH_MULTIPLIER*(r ^ x);
    if (SIXTY_FOUR_BIT) r = HASH_MULTIPLIER*(r ^ (x>>32));
//  trace_printf("UPDATE64 %" PRIx64 "\n", x);
}

inline void UPDATE32(uint64_t& r, uint32_t x)
{   r = HASH_MULTIPLIER*(r ^ x);
//  trace_printf("UPDATE32 %" PRIx32 "\n", x);
}

inline uint64_t HASH(LispObject key)
{
//  trace_printf("\nhash "); prin_to_trace(key);
    uint64_t h = (*hash_function)(0, key);
//  trace_printf(" = %" PRIx64 "\n", h);
    return h;
}

// SECOND_HASH generated a second hash value from the initial one.

inline uint64_t SECOND_HASH(uint64_t h)
{   return ((h ^ (h>>32)) + 0x1234567)*HASH_MULTIPLIER;
}

inline bool COMPARE(LispObject k1, LispObject k2)
{
// Here neither k1 not k2 will be SPID_HASHEMPTY or SPID_HASHTOMB.
    return (*hash_compare)(k1, k2);
}

// I will give myself accessors to the keys and values.

inline LispObject& ht(size_t n)
{   return elt(h_table, n);
}

inline LispObject& htv(size_t n)
{   return elt(v_table, n);
}

// Now it may be that the biggest delicacy here is in the scheme for
// computing hash values!

static uint64_t hash_eq(uint64_t r, LispObject key);
static uint64_t hash_eql(uint64_t r, LispObject key);
static uint64_t hash_cl_equal(uint64_t r, LispObject key);
static uint64_t hash_equal(uint64_t r, LispObject key);
static uint64_t hash_equalp(uint64_t r, LispObject key);
static uint64_t hash_binary_vector(uint64_t r, LispObject key);

static bool hash_compare_eq(LispObject key, LispObject hashentry);
static bool hash_compare_eql(LispObject key, LispObject hashentry);
static bool hash_compare_cl_equal(LispObject key,
                                  LispObject hashentry);
static bool hash_compare_equal(LispObject key, LispObject hashentry);
static bool hash_compare_equalp(LispObject key, LispObject hashentry);

static bool hash_compare_symtab(LispObject key, LispObject hashentry);

static void set_hash_operations(LispObject tab)
{   switch (static_cast<LispObject>(basic_elt(tab, HASH_FLAVOUR)))
{       default:
        case FIXNUM_OF_INT(HASH_AS_EQ):
            hash_function = hash_eq;
            hash_compare = hash_compare_eq;
            break;
        case FIXNUM_OF_INT(HASH_AS_EQL):
            hash_function = hash_eql;
            hash_compare = hash_compare_eql;
            break;
        case FIXNUM_OF_INT(HASH_AS_CL_EQUAL):
            hash_function = hash_cl_equal;
            hash_compare = hash_compare_cl_equal;
            break;
        case FIXNUM_OF_INT(HASH_AS_EQUAL):
            hash_function = hash_equal;
            hash_compare = hash_compare_equal;
            break;
        case FIXNUM_OF_INT(HASH_AS_EQUALP):
            hash_function = hash_equalp;
            hash_compare = hash_compare_equalp;
            break;
// This case is not sorted out yet, but the intent is that it might support
// the object list ("packages" in the Common Lisp terminology) where the
// hash table is structured as a hash-set rather than a hash-table, the key
// as passed is a string, and the result (and value actually stored in the
// hash-set) is a symbol with the given string as its printname.
        case FIXNUM_OF_INT(HASH_AS_SYMBOL):
            hash_function = hash_binary_vector;
            hash_compare = hash_compare_symtab;
            break;
//      case FIXNUM_OF_INT(HASH_AS_SXHASH):
//          sxhash is JUST used for computing hash values and the system does
//          not use it in tables.
    }
    h_shift = int_of_fixnum(basic_elt(tab, HASH_SHIFT));
    my_assert(h_shift > 32 && h_shift < 63,
              [&] { trace_printf("\n+++ h_shift = %d\nfrom table: ", h_shift);
                    prin_to_trace(tab); trace_printf("\n");
                  });
    h_table_size = ((size_t)(1<<(64-h_shift)));
    h_table = basic_elt(tab, HASH_KEYS);
    v_table = basic_elt(tab, HASH_VALUES);
}


// The main lookup function, using traditional double hashing.

// Lookup a key in the table and return either the index where it is found
// or NOT_PRESENT.

#ifdef PROFILE
static size_t next = 2, lookups = 0, probes=0;
#endif

size_t hash_lookup(LispObject key)
{   uint64_t h = HASH(key);
    size_t n = h>>h_shift;
    LispObject v = ht(n);
#ifdef PROFILE
    if (lookups == next)
    {   next = 2*next;
        std::printf("%d lookups %d probes %.2f\n",
                    static_cast<int>(lookups), static_cast<int>(probes),
                    probes/static_cast<double>(lookups));
    }
    lookups++; probes++;
#endif
    if (v == SPID_HASHEMPTY) return NOT_PRESENT;
    if (v != SPID_HASHTOMB && COMPARE(v, key)) return n;
    size_t inc = (SECOND_HASH(h)>>h_shift) | 1;
    size_t mask = (((size_t)1)<<(64-h_shift)) - 1;
// If the hash table ever got 100% full then the loop here would not
// terminate if you tried to look up a value that was not in the table.
// So my maintenance code must ALWAYS force table expansion before that
// happens.
    for (;;)
    {   n = (n + inc) & mask;
        v = ht(n);
#ifdef PROFILE
        probes++;
#endif
        if (v == SPID_HASHEMPTY) return NOT_PRESENT;
        if (v != SPID_HASHTOMB && COMPARE(v, key)) return n;
    }
}

// Lookup a key in the table and return either the address where the
// key is already stored, or an address (which will contain either
// SPID_HASHEMPTY or SPID_HASHTOMB) where it should be inserted.

#ifdef PROFILE
size_t next1 = 2, lookups1 = 0, probes1=0;
#endif

size_t hash_where_to_insert(LispObject key)
{   uint64_t h = HASH(key);
    size_t n = h>>h_shift;
    LispObject v = ht(n);
#ifdef PROFILE
    if (lookups1 == next1)
    {   next1 = 2*next1;
        std::printf("%d inserts %d probes %.2f\n",
                    static_cast<int>(lookups1), static_cast<int>(probes1),
                    probes1/static_cast<double>(lookups1));
    }
    lookups1++; probes1++;
#endif
    size_t gap;
    if (v == SPID_HASHEMPTY) return n;
    else if (v == SPID_HASHTOMB) gap = n;
    else if (COMPARE(v, key)) return n;
    else gap  = NOT_PRESENT;
    size_t inc = (SECOND_HASH(h)>>h_shift) | 1;
    size_t mask = (((size_t)1)<<(64-h_shift)) - 1;
    for (;;)
    {   n = (n + inc) & mask;
        v = ht(n);
#ifdef PROFILE
        probes1++;
#endif
        if (v == SPID_HASHEMPTY) return gap==NOT_PRESENT ? n : gap;
        else if (v == SPID_HASHTOMB) gap = n;
        else if (COMPARE(v, key)) return n;
    }
}

LispObject Lrem_hash(LispObject env, LispObject key, LispObject tab)
{   set_hash_operations(tab);
    size_t pos = hash_lookup(key);
    if (pos == NOT_PRESENT) return onevalue(nil); // item not there
// I replace the deleted key with a tombstone value. Because that still
// consumes space I will leave the record of how full the table is unchanged.
// The table may shrink following the next garbage collection.
    ht(pos) = SPID_HASHTOMB;
    if (v_table != nil) htv(pos) = SPID_HASHEMPTY;
    return onevalue(lisp_true);
}

LispObject Lrem_hash_1(LispObject env, LispObject a)
{   return Lrem_hash(env, a, sys_hash_table);
}

LispObject Lmkhash_3(LispObject env, LispObject size,
                     LispObject flavour, LispObject growth)
// (mkhash size flavour growth)
//
// In this implementation only flavour is used!
// flavour is 0, 1, 2, 3 or 5 corresponding to the following options:
//    #define HASH_AS_EQ        0
//    #define HASH_AS_EQL       1
//    #define HASH_AS_CL_EQUAL  2
//    #define HASH_AS_EQUAL     3
//    #define HASH_AS_EQUALP    4
//    #define HASH_AS_SYMBOL    5  // potential internal use for symbol table.
//    #define HASH_AS_SXHASH    6  // never used for a hash table!
{   STACK_SANITY;
    if (!is_fixnum(flavour) ||
        int_of_fixnum(flavour) < 0 ||
        int_of_fixnum(flavour) > HASH_AS_SYMBOL)
    {   if (flavour == eq_symbol) flavour = fixnum_of_int(HASH_AS_EQ);
        else if (flavour == eq_symbol) flavour = fixnum_of_int(HASH_AS_EQ);
        else if (flavour == eql_symbol) flavour = fixnum_of_int(HASH_AS_EQL);
        else if (flavour == cl_equal_symbol) flavour = fixnum_of_int(
                        HASH_AS_CL_EQUAL);
        else if (flavour == equal_symbol) flavour = fixnum_of_int(
                        HASH_AS_EQUAL);
        else if (flavour == equalp_symbol) flavour = fixnum_of_int(
                        HASH_AS_EQUALP);
        else return aerror1("mkhash", flavour);
    }
    size_t bits = 3;
    LispObject v1 = get_vector_init(CELL*((1<<bits)+1), SPID_HASHEMPTY);
    LispObject v, v2;
    THREADID;
    {   Save save(THREADARG v1);
        v2 = get_vector_init(CELL*((1<<bits)+1), SPID_HASHEMPTY);
        errexit();
        Save save1(THREADARG v2);
        v = get_basic_vector_init(6*CELL, nil);
        errexit();
        save1.restore(v2);
        save.restore(v1);
    }
    write_barrier(&basic_elt(v, HASH_FLAVOUR), flavour);
// I am being tricky here - when I write a fixnum into the vector I
// do not trigger the write-barrier because I know that a fixnum is not
// and up-pointer.
    basic_elt(v, HASH_COUNT) = fixnum_of_int(
                                   0);  // current number of items stored.
    int shift = 64 - bits;
    basic_elt(v, HASH_SHIFT) = fixnum_of_int(
                                   shift);  // 64-log2(table size)
    write_barrier(&basic_elt(v, HASH_KEYS), v1);
    write_barrier(&basic_elt(v, HASH_VALUES), v2);
    setvechdr(v, vechdr(v) ^ (TYPE_SIMPLE_VEC ^ TYPE_HASH));
    return onevalue(v);
}

LispObject Lmkhash_2(LispObject env, LispObject a, LispObject b)
{   return Lmkhash_3(env, a, b, nil);
}

// With one argument the argument sets the hashing mode (eg EQ vs EQUAL).

LispObject Lmkhash_1(LispObject env, LispObject a)
{   return Lmkhash_3(env, fixnum_of_int(8), a, nil);
}

// A hashset is a variant on a hash table. The operations are
//      mkhashset flavour        flavour selects EQ/EQUAL etc comparisons
//      sethashset(key, table)
//      resethashset(key, table)
//      gethashset(key, table)  return T or nil
//      clrhashset table

LispObject Lmkhashset(LispObject env, LispObject flavour)
// (mkhashset flavour)
{   STACK_SANITY;
    if (!is_fixnum(flavour)) return aerror1("mkhashset", flavour);
    size_t bits = 3;
    LispObject v1 = get_vector_init(CELL*((1<<bits)+1), SPID_HASHEMPTY);
    LispObject v;
    THREADID;
    {   Save save(THREADARG v1);
        v = get_basic_vector_init(6*CELL, nil);
        errexit();
        save.restore(v1);
    }
    write_barrier(&basic_elt(v, HASH_FLAVOUR), flavour);
    basic_elt(v, HASH_COUNT) = fixnum_of_int(
                                   0);  // current number of items stored.
    int shift = 64 - bits;
    basic_elt(v, HASH_SHIFT) = fixnum_of_int(
                                   shift);  // 64-log2(table size)
    write_barrier(&basic_elt(v, HASH_KEYS), v1);
    basic_elt(v, HASH_VALUES) = nil;              // value table.
// nil can never be an up-pointer.
//  write_barrier(&basic_elt(v, HASH_VALUES), nil);
    setvechdr(v, vechdr(v) ^ (TYPE_SIMPLE_VEC ^ TYPE_HASH));
    return onevalue(v);
}

// Hashing under EQ is the easiest case, since I will just use the bitwise
// representation of the object as basis for its hash value.

// An issue here is that I will be using the high order bits of the (raw)
// hash function. High order bits of the input would only have a modest
// and rather simple effect on these bits if the hash was computer as just
//     key*multiplier
// and so in the 64-bit case I will merge in use of the top half of the
// key shifted right by 32 bits. I use XOR not PLUS to make it a bit
// nonlinear.

static uint64_t hash_eq(uint64_t r, LispObject key)
{   UPDATE(r, (uint64_t)key);
    return r;
}

// For the symbol table I will pass a string to the hashing code, but
// what will end up in the table will be a symbol.
//
// This function is generically suitable for hashing any sort of Lisp vector
// that contains binary data. It requires that the data is padded up to
// a number of uintptr_t cells, which should be reasonable. It always works
// 32-bits at a time. The header word of the vector is involved in the hash
// calculation and that means that vectors of different types are distinguished
// and the leading or trailing zeros in the raw data will not cause any
// confusion. I can not use if for numbers because it used "vechdr" rather
// then flthdr or numhdr to access the header word. I need to worry a bit
// about its use for strings and bit-vectors because I will need to arrange
// that non-simple strings and non-simple bit-vectors end up delivering the
// same hash values as this version that has been optimised for use in the
// simple case. Well do I REALLY think that Common Lisp non-simple arrays
// are something I wish to support? Also when this is used on vectors that
// were not written as either sequences of characters or sequences of
// 32-bit integers there could be Strict Aliasing worries...

static uint64_t hash_binary_vector(uint64_t r, LispObject key)
{
// Find number of bytes in use, and start the hash code off with the
// header word (which involves the length).
    r = hash_eq(r, static_cast<LispObject>(vechdr(key)));
    size_t n = length_of_byteheader(vechdr(key))-CELL;
    uint32_t *p = (uint32_t *)&basic_ielt(key, 0);
// Hash the string 32 bits at a time regardless on word-length.
    for (size_t i=0; i<n; i+=sizeof(uint32_t)) UPDATE32(r, *p++);
// Any part-filled word at the end MUST be zero-padded.
    return r;
}

static uint64_t hash_byte_vector(uint64_t r, LispObject key)
{
// This is used when hashing strings and bitvectors in sxhash mode, and
// it works byte by byte.
    UPDATE(r, (uint64_t)vechdr(key));
    size_t n = length_of_byteheader(vechdr(key))-CELL;
    unsigned char *p = reinterpret_cast<unsigned char *>(&basic_ucelt(key, 0));
    for (size_t i=0; i<n; i++) UPDATE32(r, *p++);
    return r;
}

static uint64_t hash_halfword_vector(uint64_t r, LispObject key)
{   UPDATE(r, (uint64_t)vechdr(key));
    size_t n = length_of_hwordheader(vechdr(key))-CELL/sizeof(
                   std::uint16_t);
    std::uint16_t *p = reinterpret_cast<std::uint16_t *>(&basic_helt(key, 0));
    for (size_t i=0; i<n; i++) UPDATE32(r, *p++);
    return r;
}

static uint64_t hash_double_vector(uint64_t r, LispObject key)
{
// This is used when hashing arrays of doubles or 64-bit integers in
// sxhash mode. I will ignore horrid issues of strict aliasing here,
// and assume that byte-order variations from machine to machine behave
// the same way for doubles and for 64-bit integers.
    UPDATE(r, (uint64_t)vechdr(key));
    size_t n = length_of_header(vechdr(key))-CELL;
    uint64_t *p = (uint64_t *)&basic_delt(key, 0);
    for (size_t i=0; i<n; i+=sizeof(uint64_t)) UPDATE(r, *p++);
    return r;
}

static uint64_t hash_eql(uint64_t r, LispObject key)
// Must return same code for two eql numbers. This regime views
// numbers as equal if they have the same type aned the same value, so
// apart from an ugly dispatch to cope with all the different sorts of
// number this is not too bad. Well it is NASTY because Common Lisp would
// insist that (eql +0.0 -0.0) => nil, and only (= +0.0 -0.0) or
// (equal +0.0 -0.0) should give t. Standard Lisp will view this as
// silly and will want eql to treat positive and negative zeros as the
// same.
{   if (is_bfloat(key))
    {   Header h = flthdr(key);
// The headers of floating point values fit in just 32-bits so I do not do the
// two steps that I would with general vector headers.
        UPDATE(r, (uint64_t)h);
        switch (type_of_header(h))
        {   case TYPE_SINGLE_FLOAT:
// Here I hash single floats as if they had been represented in the way that
// they would have been on a 64-bit machine. This is so that the values
// returned by sxhash can be consistent across platforms.
            {   uint64_t v = intfloat32_t_val(key);
                v = (v<<32) + XTAG_SFLOAT + XTAG_FLOAT32;
                UPDATE(r, v);
                return r;
            }
            default:
            case TYPE_DOUBLE_FLOAT:
                UPDATE32(r, (uint64_t)h);
                if (double_float_val(key) == 0.0) UPDATE(r, 0);
                else UPDATE(r, intfloat64_t_val(key));
                return r;
#ifdef HAVE_SOFTFLOAT
            case TYPE_LONG_FLOAT:
                UPDATE32(r, (uint64_t)h);
                if (f128M_zero(reinterpret_cast<float128_t *>(long_float_addr(key))))
                {   UPDATE(r, 0);
                    UPDATE(r, 0);
                }
                else
                {   UPDATE(r, intfloat128_t_val0(key));
                    UPDATE(r, intfloat128_t_val1(key));
                }
                return r;
#endif // HAVE_SOFTFLOAT
        }
    }
    else if (is_numbers(key))
    {   Header h = numhdr(key);
        size_t n;
        UPDATE(r, (uint64_t)h);
        switch (type_of_header(h))
        {   case TYPE_BIGNUM:
                n = (length_of_header(h)-CELL-4)/4;
                for (;;)
                {   UPDATE(r, bignum_digits(key)[n]);
                    if (n == 0) break;
                    n--;
                }
                return r;
            case TYPE_RATNUM:
            case TYPE_COMPLEX_NUM:
                r = hash_eql(r, numerator(key));
                return hash_eql(r, denominator(key));
            default:
                return hash_eq(r, key);  // unknown type of number?
        }
    }
// For non-numbers I hash as for EQ.
    else return hash_eq(r, key);
}

// There are a range of EQUAL-like functions used for hashing.
// CL_EQUAL
//   Traverses lists and inspects the contents of strings and bit-vectors,
//   but does not in general descend through vectors. There are supposed to
//   be special cases for non-simple arrays (especially including non-simple
//   strings and bitvectors) and structures that are "path-names". Common
//   Lisp also demands that +0.0 and -0.0 be reported as different. I will
//   not implement all these refinements on the YAGNI (You Ain'y Gonna Need It)
//   principle.
// EQUAL
//   The Standard Lisp understanding where vectors are descended through.
// EQUALP
//   A further Common Lisp oddity, where notably strings are compared in a
//   case insensitive manner! This is also expected to allow you to compute
//   hash values for hash tables based on their content, and that seems a
//   messy thing to support.
//   I should view numbers of different types but similar values (eg 1 and
//   1.0) as EQUALP. This issue is rather horrid. So for instance
//   1152921504606846976 is a bignum  and has the value 2^60. Then since
//   1152921504606846976.0 happens to be exactly a power of 2 its
//   representation in floating point is exact, and it has therefore to hash
//   to the same code as the integer version. This sort of thing has to
//   happen for values up to the largest floating point value. In Common Lisp
//   there are also rational values, and it looks probable that hashing the
//   result of the calculation 1.0/3.0 must yield the same value as that for
//   the rational number 6004799503160661/18014398509481984.
//   So hashing here may be unexpectedly expensive, and it can certainly
//   risk memory allocation and hence garbage collection. Oh dear. Perhaps I
//   need a special variation on multiple-precision arithmetic just for use
//   when converting floating point numbers so that garbage collection can be
//   avoided. It I allow for long floats with a 16-bit exponent I believe
//   that will mean dealing with integers of up to almost 10000 decimal
//   digits, or around 1000 31-bit units.
//
// Well such a lot of the Common Lisp specification seems utterly over the
// top to me that I am not going to implement it! The result will be that
// my code will be shorter, simpler and faster, and I find it hard to
// believe that SANE code can rely on the special-case pedantry mentioned
// above. If somebody gets VERY keen at a later stage they can degrade the code
// to. I observe that "clisp" (by Haible, Stoll, Steingold and others) does
// make their EQUALP function do some of these ridiculous things... so perhaps
// I ought to even though I view it as majorly silly.

//
// I will have one generic function with an extra argument that is used to
// control its behaviour in the cases where these three regimes differ in
// behaviour.


static uint64_t hash_generic_equal(uint64_t r, LispObject key,
                                   int mode, size_t depth);

#ifdef DEBUG
static uint64_t hash_generic_equal1(uint64_t r, LispObject key,
                                    int mode, size_t depth);
#endif // DEBUG

static uint64_t hash_cl_equal(uint64_t r, LispObject key)
{   return hash_generic_equal(r, key, HASH_AS_CL_EQUAL, 0);
}

#ifdef DEBUG
static uint64_t hash_equal(uint64_t r, LispObject key)
{   return hash_generic_equal1(r, key, HASH_AS_EQUAL, 0);
}
#else // DEBUG
static uint64_t hash_equal(uint64_t r, LispObject key)
{   return hash_generic_equal(r, key, HASH_AS_EQUAL, 0);
}
#endif // DEBUG

static uint64_t hash_equalp(uint64_t r, LispObject key)
{   return hash_generic_equal(r, key, HASH_AS_EQUALP, 0);
}

static uint64_t hash_nonsimple_string(uint64_t r, LispObject key)
{   std::printf("\nNon-simple-string\n");  // Pending!!!!
    return hash_eq(r, key);        // hash as for EQ for now
}

static uint64_t hash_nonsimple_bitvector(uint64_t r, LispObject key)
{   std::printf("\nNon-simple-bitvector\n"); // Pending!!!
    return hash_eq(r, key);
}

// This function has not yet been fully implemented but is intended to let
// me support EQUALP. If the input is a number that can be converted to
// a float WITH NO LOSS OF ACCURACY then set bigfloat_result to the
// converted value and return true. Otherwise return false.
// Anything that is a float already can be converted. short, single and
// double floats need widening. Integers can be converted if the value has
// new enough leading bits nonzero and if the value will lead to no exponent
// overflow. Ratios are OK if the numerator has limited nonzero leading bits
// and if the denominator is a power of 2 so that there is no underflow.
// Sub-normal numbers represent a special edge case for this.

#ifdef HAVE_SOFTFLOAT
static float128_t bigfloat_result;

UNUSED_NAME static bool float_if_exact(LispObject x)
{   if (is_fixnum(x))
    {   i32_to_f128M(int_of_fixnum(x), &bigfloat_result);
        return true;
    }
    else if (is_numbers(x))
    {   if (is_bignum(x)) return false;       // @@@ More work
        else if (is_ratio(x)) return false;   // @@@ More work
// Do I need to spot the case of a complex number with zero complex
// component?
        else if (is_complex(x)) return false; // @@@@ More work
        else return false;
    }
    else if (is_bfloat(x))
    {   switch (type_of_header(flthdr(x)))
        {   case TYPE_SINGLE_FLOAT:
                f32_to_f128M(float32_t_val(x), &bigfloat_result);
                return true;
            case TYPE_DOUBLE_FLOAT:
                f64_to_f128M(float64_t_val(x), &bigfloat_result);
                return true;
            case TYPE_LONG_FLOAT:
                bigfloat_result = long_float_val(x);
                return true;
            default:
                return false;
        }
    }
    else if (is_sfloat(x)) return false;      // @@@ More work
    else return false;
}
#endif // HAVE_SOFTFLOAT

// When computing a hash function I will only explore the top of the
// structure. So if you have two trees of similar shape but with different
// leaves and the leaves are all far enough down then the two will hash to
// the same value. The alternative can involve exploring the whole of
// really huge structures in a way that may not be good.

static const size_t hash_explore_depth = 5;
static const size_t hash_explore_breadth = 10;

static uint64_t hash_generic_equal(uint64_t r, LispObject key,
                                   int mode, size_t depth)
{   size_t len;
    unsigned char *data;
    Header h;
#ifdef CHECK_STACK
    if (check_stack("@" __FILE__,__LINE__) || depth > 0x0fffffff)
    {   err_printf("Stack too deep in hash calculation\n");
        my_exit();
    }
#endif
//@ if (mode == HASH_AS_SXHASH)
//@ {   LispObject prev = Lget_hash_2(nil, key, sxhash_hash_table);
//@     if (prev != nil)
//@     {   UPDATE32(r, VIRTUAL_TYPE_REF | TAG_HDR_IMMED);
//@         return hash_eq(r, prev);
//@     }
//@     Lput_hash(nil, key, sxhash_hash_table, fixnum_of_int(depth));
//@ }
// I will iterate along any chain of CONS cells, and put a sort of virtual
// header word on the front of each cell to keep the calculation robust.
    if (depth > hash_explore_depth) UPDATE32(r, 999999); 
    else
    {   size_t m = 0;
        while (is_cons(key) && key != nil && m++ < hash_explore_breadth)
        {   UPDATE32(r, VIRTUAL_TYPE_CONS | TAG_HDR_IMMED);
            r = hash_generic_equal(r, car(key), mode, depth+1);
            key = cdr(key);
        }
    }
// Partly because in CSL (in Common Lisp mode) I tagged NIL in an odd way
// I will compute its hash value specially here.
    if (key == nil)
    {   UPDATE32(r, VIRTUAL_TYPE_NIL | TAG_HDR_IMMED);
        return r;
    }
    switch (TAG_BITS & (int32_t)key)
    {   case TAG_CONS:
            return r;
        case TAG_SYMBOL:
            if (mode == HASH_AS_SXHASH)
            {   key = get_pname(key);
                UPDATE32(r, TYPE_SYMBOL | TAG_HDR_IMMED);
// Hash symbols based on their names in SXHASH mode.
                return hash_generic_equal(r, key, mode, depth+1);
            }
            else return hash_eq(r, key);
        case TAG_VECTOR:
// There is a superb horror here as to hashing a hash table! I will ignore
// that issue for now.
        {   h = vechdr(key);
// I need to treat strings and bitvectors here specially since in those
// cases (and for pathnames, if they existed as a separate data type here!)
// I must inspect the vector contents, while in other cases I must not.
            if (is_string_header(h))
            {   switch (mode)
                {   case HASH_AS_CL_EQUAL:
                    // drop through. Note that for non-simple
                    // strings I am going to need to arrange to
                    // compute the value as used here. Ugh Ugh!
                    case HASH_AS_EQUAL:
                        return hash_binary_vector(r, key);
                    case HASH_AS_SXHASH:
// In sxhash mode I need to be careful and hash based on the width of items
// in the vector so that I get results that are not sensitive to the byte-
// order used on my host.
                        switch (type_of_header(h))
                        {   default:
                                return hash_byte_vector(r, key);
                            case TYPE_VEC16_1:
                            case TYPE_VEC16_2:
                                return hash_halfword_vector(r, key);
                            case TYPE_VEC32:
                            case TYPE_VECFLOAT32:
                                return hash_binary_vector(r, key);
                            case TYPE_VEC64:
                            case TYPE_VEC128:
                            case TYPE_VECFLOAT64:
                            case TYPE_VECFLOAT128:
                                return hash_double_vector(r, key);
                        }
                    case HASH_AS_EQUALP:
// Here I must compute a case-insensitive hash value. Ugh this means I work
// character by character and so slow things down.
                        r = hash_eq(r, static_cast<LispObject>(h));
                        data = reinterpret_cast<unsigned char *>(&ucelt(key, 0));
                        len = length_of_byteheader(h) - CELL;
                        while (len-- != 0)
                        {   int c = *data++;
// The string will be stored in UTF8. A consequence is that any bytes forming
// part of a character beyond Basic Latin will have their top bit set. I will
// case-convert Basic Latin characters (only).
                            if ((c & 0x80) == 0) c = std::tolower(c);
                            UPDATE32(r, c);
                        }
                        return r;
                }
            }
            if (is_bitvec_header(h))
            {
// I always hash bitvectors byte by byte - this may be slower than going
// word by word but is safer for sxhash, and the situation is not expected
// to be common.
                return hash_byte_vector(r, key);
            }
// I will allow for non-simple vectors in whatever style I am in, including
// allowing non-simple strings and bit-vectors to be handled in special ways.
            if (is_array_header(h) && depth <= hash_explore_depth)
            {   LispObject arraytype = elt(key, 0);
                if (arraytype == string_char_sym)
                    return hash_nonsimple_string(r, key);
                if (arraytype == bit_symbol)
                    return hash_nonsimple_bitvector(r, key);
                UNUSED_NAME LispObject dims = elt(key, 1);
                UNUSED_NAME LispObject vec = elt(key, 2);
                UNUSED_NAME LispObject displace = elt(key, 3);
                UNUSED_NAME LispObject adjustable = elt(key, 4);
                UNUSED_NAME LispObject fill = elt(key, 5);
// Give up and hash using EQ!!!! This is a temporary cop-out.
                if (mode == HASH_AS_SXHASH) return hash_eq(r, 0x12345);
                else return hash_eq(r, key);
            }
// here in the case of EQUAL and EQUALP I must descend vectors. Well EQUALP
// is an especially jolly case in that a general vector that happens to
// hold characters must compare as EQUALP to a string that agrees in a
// case-insenstive manner, with offsets and fill-pointers all dealt with.
            else
            {   switch (mode)
                {   case HASH_AS_EQUAL:
                    case HASH_AS_EQUALP:
                    case HASH_AS_SXHASH:
// Here I should POSSIBLY look at non-simple strings and bitvectors and at
// pathnames. For now I intend to follw the principle of "You Ain't Gonna
// Need It" and just ignore the issues.
                        UPDATE(r, (uint64_t)h);
                        len = length_of_header(h)/CELL - 1;
                        if (len > hash_explore_breadth)
                            len = hash_explore_breadth;
                        if (depth > hash_explore_depth) UPDATE32(r, 999999);
                        else while (len-- != 0)
                            r = hash_generic_equal(r, elt(key, len),
                                                   mode, depth+1);
                        return r;
                    default:
// the Common Lisp version of EQUAL hashing does not descend vectors.
                        return hash_eq(r, key);
                }
            }
        }
        case TAG_BOXFLOAT:
        case TAG_NUMBERS:
// For EQUALP I am supposed to hash things such that numbers that differ in
// type but have the same value will agree. I think that the most plausible
// way to achieve that would be that if a number can be converted to a long
// float without any rounding arising I should do that. For instance for
// bignums that involves checking if the number of trailing zero bits is
// big enough, and for ratios it involves verifying that the denominator is
// a power of 2. I will not do that at present, but I could if I felt like
// indulging myself with what is basically a waste of time. I have put in
// functions that are placeholders for a conversion that would be needed.
            return hash_eql(r, key);
        default:
// The default case includes various sorts of immediate data. I can see one
// trouble for sxhash. On a 64-bit machine a single float is represented as
// immediate data and so comes here, while on a 32-bit machine it will have
// been boxed. To resolve that I will arrange that the hashing of boxed single
// floats generates what this would.
            return hash_eq(r, key);
    }
}

#ifdef DEBUG

#define MAX_DEPTH 40000

// This is ugly slow code that checks if a key used with a hash table
// is cyclic and if so it complains. It is only activated in DEBUG mode.
// In production mode it a cyclic structure is used with a hash table the
// result will be either a non-terminating loop or a stack overflow - and
// both of those are unrecoverable. So anybody who suspects that they may
// be facing such a situation cen build a debug-mode cope of Reduce and
// they then get a clear-cut abort (but need to debug that using gdb etc).

LispObject trailvec[MAX_DEPTH];

static bool is_cyclic(LispObject key, int trail)
{   if (is_cons(key))
    {   for (int i=0; i<trail; i++) 
            if (trailvec[i] == key) return true;
        trailvec[trail++] = key;
        if (trail>=MAX_DEPTH) my_abort("too deep");
        if (is_cyclic(car(key), trail)) return true;
        return is_cyclic(cdr(key), trail);
    }
    if (is_vector(key) && !vector_header_of_binary(vechdr(key)))
    {   for (int i=0; i<trail; i++) 
            if (trailvec[i] == key) return true;
        size_t len = length_of_header(vechdr(key))/CELL - 1;
        trailvec[trail++] = key;
        if (trail>=MAX_DEPTH) my_abort("too deep");
        for (size_t i=0; i<len; i++)
            if (is_cyclic(elt(key, i), trail)) return true;
        return false;
    }
    return false;
}

static uint64_t hash_generic_equal1(uint64_t r, LispObject key,
                                    int mode, size_t depth)
{   if (is_cyclic(key, 0)) my_abort("Cyclic structure to hash-equal");
    return hash_generic_equal(r, key, mode, depth);
}

#endif // DEBUG

static bool hash_compare_eq(LispObject key, LispObject hashentry)
{   return (key == hashentry);
}

static bool hash_compare_eql(LispObject key, LispObject hashentry)
{   return eql(key,hashentry);
}

static bool hash_compare_cl_equal(LispObject key,
                                  LispObject hashentry)
{   return cl_equal(key, hashentry);
}

static bool hash_compare_equal(LispObject key, LispObject hashentry)
{   return equal(key, hashentry);
}

// Beware implementation of comparisons between floats and other numeric
// types, that characters must be compared in a case-insenstive manner,
// and that atrings must match other sorts of arrays that happen to have
// characters in them.

static bool hash_compare_equalp(LispObject key, LispObject hashentry)
{   return equalp(key, hashentry);
}

// For hash_compare_symtab key will be a string and hashentry will be
// a symbol here... I compare strings word at a time not byte at a time,
// and this is liable to count as undefined behaviour in C and C++ and
// may run risks of breacing strict aliasing rules.

static bool hash_compare_symtab(LispObject key, LispObject hashentry)
{   size_t n;
    uintptr_t *p1, *p2;
    hashentry = qpname(
                    hashentry); // allow for entry in table being a symbol.
    if (vechdr(key) != vechdr(hashentry)) return false; // lengths differ.
    n = length_of_byteheader(vechdr(key));
    p1 = (uintptr_t *)&celt(key, 0);
    p2 = (uintptr_t *)&celt(hashentry, 0);
// Compare the string 32 or 64-bits at a time depending on word-length.
    while (n >= sizeof(uintptr_t))
    {   if (*p1++ != *p2++) return false;
        n -= sizeof(uintptr_t);
    }
// There may be a partly-filled word to check at the end.
    if (n != 0 && *p1 != *p2) return false;
    return true;
}

//==========================================================================

// First copy from h_table and v_table to oldkeys and oldvals,
// then hash back. This rehashes the main table while not changing
// its size, and oldkeys, oldvals are purely temporary. h_table,
// v_table and h_table_size are static variable so do not need to be
// passed as arguments. Well this only copies active data into
// oldkeys and oldvals, so empty space is ignored and tombstones end
// up discarded. If in the process this discovers that the table is
// rather empty it will shrink it.

void rehashInPlace(LispObject tab, LispObject oldkeys, LispObject oldvals)
{   size_t load = 0;
// Copy live data to the borrowed space and make the existing table empty.
    for (size_t i=0; i<h_table_size; i++)
    {   LispObject k = ht(i);
        if (k != SPID_HASHEMPTY && k != SPID_HASHTOMB)
        {   elt(oldkeys, load) = k;
            if (v_table != nil)
            {   elt(oldvals, load) = static_cast<LispObject>(htv(i));
                htv(i) = SPID_HASHEMPTY;
            }
            load++;
        }
        ht(i) = SPID_HASHEMPTY;
    }
// If the table is under 20% occupied (and if it is big enough for shrinking
// to be sensible) I halve its size, so it will still end up at worst 40%
// occupied. It a really large fraction of its contents had been removed
// it will be repeatedly halved in size but with a slightly more conservative
// stopping point.
    if (load < h_table_size/5 && h_table_size > 16)
    {   do
        {   h_shift++;
            h_table_size /= 2;
        }
        while (load < h_table_size/6 && h_table_size > 16);
// I can reduce the size of a vector and doing so preserves the contents
// of the cells that remain (here they will all contain nil). However if
// the vector shrinks from a segmented representation to a basic one the
// address involved may change, so I must update the referenced in the
// main table.
        h_table = reduce_vector_size(h_table, CELL*(load+1));
        if (v_table != nil)
            v_table = reduce_vector_size(v_table, CELL*(load+1));
        write_barrier(&basic_elt(tab, HASH_KEYS), h_table);
        write_barrier(&basic_elt(tab, HASH_VALUES), v_table);
    }
// As perhaps a matter of caution I will re-create the COUNT.
    basic_elt(tab, HASH_COUNT) = fixnum_of_int(0);
    for (size_t i=0; i<load; i++)
    {   LispObject k = elt(oldkeys, i);
        size_t j = hash_where_to_insert(k);
        write_barrier(&ht(j), k);
        if (v_table != nil)
            write_barrier(&htv(j),
                          static_cast<LispObject>(elt(oldvals, i)));
        basic_elt(tab, HASH_COUNT) =
            static_cast<LispObject>(basic_elt(tab, HASH_COUNT)) + 0x10;
    }
}

LispObject Lget_hash(LispObject env, LispObject key, LispObject tab,
                     LispObject dflt)
{   STACK_SANITY;
    size_t pos;
    if (!is_vector(tab) || type_of_header(vechdr(tab)) != TYPE_HASH)
    {   if (type_of_header(vechdr(tab)) != TYPE_HASHX)
            return aerror1("gethash", tab);
        setvechdr(tab, vechdr(tab) ^ (TYPE_HASH ^ TYPE_HASHX));
        set_hash_operations(tab);
// Here I have a table that at some stage had all fitted into the table, and
// I am not adding new data. I need to rehash it because garbage collection
// may have shuffled memory and so hash values that are based on memory
// addresses can be out of date.
// If I "prepare_for_borrowing" by creating an instance of the Borrowing class
// I can allocate new space using borrow_vector but that space is then
// transient. The idea is that "borrowed" space comes from the memory
// half-space that is reserved by the copying garbage collector to copy
// material into when a GC is needed. The result is that plenty of space
// should always be available, but it will be imporant that GC is not
// triggered while a borrowed vector is still in use. However for small
// tables I will just use a pre-allocated pair of vectors. A consequence
// of that is that those vectors may keep the table content alive even if
// the hash table itself is altered - but only until the next time something
// gets rehashed in this way!
        if (h_table_size <= REHASHVEC_SIZE)
            rehashInPlace(tab, rehash_vec1, rehash_vec2);
        else
        {   Borrowing borrowObject;
            LispObject oldkeys = borrow_vector(TAG_VECTOR, TYPE_SIMPLE_VEC,
                                               CELL*(h_table_size+1));
            LispObject oldvals = v_table == nil ? nil :
                                 borrow_vector(TAG_VECTOR, TYPE_SIMPLE_VEC,
                                               CELL*(h_table_size+1));
            rehashInPlace(tab, oldkeys, oldvals);
        }
    }
    else set_hash_operations(tab);
    pos = hash_lookup(key);
// For hashsets I return T or nil.
    if (v_table == nil)
        return onevalue(pos == NOT_PRESENT ? nil : lisp_true);
    if (pos == NOT_PRESENT)
    {   mv_2 = nil;
        return nvalues(dflt, 2);
    }
    mv_2 = lisp_true;
    return nvalues(htv(pos), 2);
}

LispObject Lmap_hash(LispObject env, LispObject fn, LispObject tab)
// I should consider what happens if there is a garbage collection while
// I am performing this scan of the hash table. Well the table contents are
// not rearranged by garbage collection - the main thing that happens is that
// the table is re-tagged from TYPE_HASH to TYPE_HASHX. So I believe
// that provided nobody tries either lookup or set operations on the table I
// will be OK.
{   STACK_SANITY;
    int32_t size, i;
    LispObject v, v1;
    if (!is_vector(tab) ||
        (type_of_header(vechdr(tab)) != TYPE_HASH &&
         type_of_header(vechdr(tab)) != TYPE_HASHX))
        return aerror1("maphash", tab);
    v = basic_elt(tab, HASH_KEYS);
    v1 = basic_elt(tab, HASH_VALUES);
    size = cells_in_vector(v);
    THREADID;
    for (i=0; i<size; i++)
    {   LispObject key = elt(v, i);
        if (key == SPID_HASHEMPTY) continue;
        if (v1 == nil)
        {   Save save(THREADARG v, v1, fn);
            Lapply1(nil, fn, key);
            errexit();
            save.restore(v, v1, fn);
        }
        else
        {   LispObject val = elt(v1, i);
            Save save(THREADARG v, v1, fn);
            Lapply2(nil, fn, key, val);
            errexit();
            save.restore(v, v1, fn);
        }
    }
    return onevalue(nil);
}

LispObject Lhash_contents(LispObject env, LispObject tab)
// As for maphash I believe that garbage collection is pretty benign here.
// I make this work on both hashsets and hashtables. In the former case it
// returns a list of keys, in the latter an association list of keys
// and values.
{   STACK_SANITY;
    size_t size, i;
    LispObject v, v1, r;
    if (!is_vector(tab) ||
        (type_of_header(vechdr(tab)) != TYPE_HASH &&
         type_of_header(vechdr(tab)) != TYPE_HASHX))
        return aerror1("hashcontents", tab);
    v = basic_elt(tab, HASH_KEYS);
    v1 = basic_elt(tab, HASH_VALUES);
    size = cells_in_vector(v);
    r = nil;
    THREADID;
    for (i=0; i<size; i++)
    {   LispObject key = elt(v, i);
        if (key == SPID_HASHEMPTY) continue;
        Save save(THREADARG v, v1);
        if (v1 == nil) r = cons(key, r);
        else r = acons(key, elt(v1, i), r);
        errexit();
        save.restore(v, v1);
    }
// The ordering of items in the result a-list is unpredictable.
// That is probably quite reasonable.
    return onevalue(r);
}

LispObject Lget_hash_1(LispObject env, LispObject key)
{
#ifdef COMMON
    return Lget_hash(nil, key, sys_hash_table, nil);
#else
// The definition implemented here is as required by Reduce in
// the file matrix.red...  In the long term this is unsatisfactory.
    LispObject r;
    THREADID;
    Save save(THREADARG key);
    r = Lget_hash(nil, key, sys_hash_table, nil);
    errexit();
    save.restore(key);
    if (mv_2 != nil)
    {   r = cons(key, r);
        errexit();
    }
    return onevalue(r);
#endif
}

LispObject Lget_hash_2(LispObject env, LispObject key, LispObject tab)
{   return Lget_hash(env, key, tab, nil);
}

#ifdef DEBUG
size_t fullest_hash_table = 0;
#endif

LispObject Lput_hash(LispObject env,
                     LispObject key, LispObject tab, LispObject val)
{   STACK_SANITY;
    LispObject k1;
    bool needs_rehashing = false;
    if (!is_vector(tab)) return aerror1("puthash", tab);
    if (type_of_header(vechdr(tab)) != TYPE_HASH)
    {   if (type_of_header(vechdr(tab)) == TYPE_HASHX)
        {   needs_rehashing = true;
            setvechdr(tab, vechdr(tab) ^ (TYPE_HASH ^ TYPE_HASHX));
        }
        else return aerror1("puthash", tab);
    }
    set_hash_operations(tab);
    size_t count = int_of_fixnum(basic_elt(tab, HASH_COUNT));
#ifdef DEBUG
    if (count > fullest_hash_table) fullest_hash_table = count;
#endif
    if (5*count > 4*h_table_size) needs_rehashing = true;
// I will rehash either if I have to because there has been a garbage
// collection since the last operation on the table (and hence hash codes
// may have changed) or if the table is at least 80% full). The table is
// not rehashed on general operations when it has shrunk, but when garbage
// collection occurs and forces a rehash it may shrink.
    if (needs_rehashing)
    {   size_t load = 0;
        for (size_t i=0; i<h_table_size; i++)
            if (static_cast<LispObject>(ht(i)) != SPID_HASHEMPTY &&
                static_cast<LispObject>(ht(i)) != SPID_HASHTOMB) load++;
#ifdef PROFILE
        std::printf("Inserting with load=%d count=%d size=%d\n",
                    static_cast<int>(load), static_cast<int>(count),
                    static_cast<int>(h_table_size));
#endif
// When I rehash I may grow, shrink or leave the table the same size. If the
// data (excluding tombstones) is at least (1/2) of the table size I will
// expand. For cases where there has not been any deletion this just arranges
// that when there happens to have been a garbage collection hash tables will
// tend to be enlarged rather early, but between garbage collection tables
// have to get 80% full before expanding. If there are many deletions this
// will tend to keep tables sparse all the time.
        if (2*load >= h_table_size)
        {   LispObject newkeys, newvals;
            THREADID;
            {   Save save(THREADARG key, val, tab);
                h_shift--;
                newkeys =
                    get_vector_init(CELL*(2*h_table_size+1), SPID_HASHEMPTY);
                errexit();
                Save save1(THREADARG newkeys);
                newvals = (v_table == nil) ? nil :
                    get_vector_init(CELL*(2*h_table_size+1), SPID_HASHEMPTY);
                errexit();
                save1.restore(newkeys);
                save.restore(key, val, tab);
            }
// Allocating the new table might trigger garbage collection, and that
// could mark the table as in need of rehashing. Well I am about to
// rehash everything already, so I can cancel any new request.
            if (type_of_header(vechdr(tab)) == TYPE_HASHX)
                setvechdr(tab, vechdr(tab) ^ (TYPE_HASH ^ TYPE_HASHX));
            LispObject oldkeys = basic_elt(tab, HASH_KEYS);
            LispObject oldvals = basic_elt(tab, HASH_VALUES);
            h_table = newkeys;
            write_barrier(&basic_elt(tab, HASH_KEYS), newkeys);
            v_table = newvals;
            write_barrier(&basic_elt(tab, HASH_VALUES), newvals);
            basic_elt(tab, HASH_SHIFT) = fixnum_of_int(h_shift);
            basic_elt(tab, HASH_COUNT) = fixnum_of_int(0);
            for (size_t i=0; i<h_table_size; i++)
            {   LispObject k = elt(oldkeys, i);
// Copy active stuff to the new table...
                if (k != SPID_HASHEMPTY && k != SPID_HASHTOMB)
                {   size_t j = hash_where_to_insert(k);
                    write_barrier(&ht(j), k);
                    if (v_table != nil)
                        write_barrier(&htv(j),
                                      static_cast<LispObject>(elt(oldvals, i)));
                    basic_elt(tab, HASH_COUNT) =
                        static_cast<LispObject>(
                            basic_elt(tab, HASH_COUNT)) + 0x10;
                }
            }
// Here I can recycle the old space. This is not going to be very important
// for small hash tables, but may help when they get large.
            discard_vector(oldkeys);
            discard_vector(oldvals);
        }
        else
        {   if (h_table_size <= REHASHVEC_SIZE)
                rehashInPlace(tab, rehash_vec1, rehash_vec2);
            else
            {   Borrowing borrowObject;
                LispObject oldkeys = borrow_vector(TAG_VECTOR, TYPE_SIMPLE_VEC,
                                                   CELL*(h_table_size+1));
                LispObject oldvals = v_table == nil ? nil :
                                     borrow_vector(TAG_VECTOR, TYPE_SIMPLE_VEC,
                                                   CELL*(h_table_size+1));
                rehashInPlace(tab, oldkeys, oldvals);
            }
        }
    }
    size_t pos = hash_where_to_insert(key);
    k1 = ht(pos);
// If I insert where a tombstone value had been I do not increment the
// occupancy count, since the tombstone is counted as an occupier.
    if (k1 == SPID_HASHEMPTY)
        basic_elt(tab, HASH_COUNT) = static_cast<LispObject>(basic_elt(tab,
                                     HASH_COUNT)) + 0x10; // Increment count.
    write_barrier(&ht(pos), key);
    if (v_table != nil) write_barrier(&htv(pos), val);
    return onevalue(val);
}

LispObject Lput_hash_2(LispObject env, LispObject a, LispObject b)
{   return Lput_hash(env, a, sys_hash_table, b);
}

LispObject Lset_hashset(LispObject env, LispObject a, LispObject b)
{   return Lput_hash(env, a, b, lisp_true);
}

LispObject Lclr_hash(LispObject env, LispObject tab)
{   if (!is_vector(tab) ||
        (type_of_header(vechdr(tab)) != TYPE_HASH &&
         type_of_header(vechdr(tab)) != TYPE_HASHX))
        return aerror1("clrhash", tab);
    set_hash_operations(tab);
    if (basic_elt(tab, HASH_COUNT) == fixnum_of_int(0))
        return onevalue(nil);
    set_hash_operations(tab);
    int sh = int_of_fixnum(basic_elt(tab, HASH_SHIFT));
    size_t size = ((size_t)1)<<(64-sh);
    if (size > (1<<4))
    {   size = (1<<4);
        h_table = reduce_vector_size(h_table, CELL*(size+1));
        if (v_table != nil)
            v_table = reduce_vector_size(v_table, CELL*(size+1));
        write_barrier(&basic_elt(tab, HASH_KEYS), h_table);
        write_barrier(&basic_elt(tab, HASH_VALUES), v_table);
        basic_elt(tab, HASH_SHIFT) = fixnum_of_int(64-4);
    }
    LispObject keys = basic_elt(tab, HASH_KEYS);
    LispObject vals = basic_elt(tab, HASH_VALUES);
    for (size_t i=0; i<size; i++)
    {   elt(keys, i) = SPID_HASHEMPTY;
        if (vals != nil) elt(vals, i) = SPID_HASHEMPTY;
    }
    basic_elt(tab, HASH_COUNT) = fixnum_of_int(0);
    if (type_of_header(vechdr(tab)) == TYPE_HASHX)
        setvechdr(tab, vechdr(tab) ^ (TYPE_HASH ^ TYPE_HASHX));
    return tab;
}

LispObject Lclr_hash_0(LispObject env)
{   return Lclr_hash(env, sys_hash_table);
}

// (sxhash key) is supposed to return a positive fixnum such that any
// two items that are EQUAL in the Common Lisp sense will yield the same
// result. It has further constraints that the values must be consistent
// from run to run and across a range of changes to the environment.
// I believe that I can get away with hashing numbers based on their values,
// strings on the characters that make them up, symbols on their print-name
// (but I am NOT allowed to pay attention to package information) and almost
// everything else can just return a code based on the type of the object.
// The result is obliged to be a positive fixnum.
// the Common Lisp version of EQUAL does not descend vectors, but the
// obligation I have here is just that things that are (CL-)EQUAL must yield
// the same hash value, so I can afford to descend and that seems kinder to me.
// Common Lisp also says that this function should always terminate even for
// cyclic structures. Yuk that adds an extra unwelcome level of mess, and
// in an earlier revision I traversed the entire structure with an extra
// hash table to detect cycles. I now have a limit to the depth that I
// investigate and that renders the code safe against cycles, so I do not
// need the cost and complication of the extra hash table.

LispObject Lsxhash(LispObject env, LispObject key)
{   uint64_t h;
    if (is_symbol(key))
    {   key = get_pname(key);
        h = 1;
// The value returned is supposed to be cross-platform consistent and so
// I can not work word at a time - i need to work byte at a time.
        for (size_t i=0; i<bytes_in_vector(key); i++)
            h = 0x123456789ab*ucelt(key, i);
    }
    else if (is_fixnum(key))
    {   h = int_of_fixnum(key);
    }
    else if (is_simple_string(key))
    {   h = 2;
        for (size_t i=0; i<bytes_in_vector(key); i++)
            h = 0x123456789ab*ucelt(key, i);
    }
    else
    {   //@ Lclr_hash(nil, sxhash_hash_table);
        h = hash_generic_equal(0, key, HASH_AS_SXHASH, 0);
//@     Lclr_hash(nil, sxhash_hash_table); // Just to tidy up.
    }
    h = h ^ (h >> 32);
    h = (h ^ (h >> 16)) &
        0x03ffffff; // ensure it will be a positive fixnum
    return onevalue(fixnum_of_int(h));
}

setup_type const lisphash_setup[] =
{   {"mkhash",         G0Wother, Lmkhash_1, Lmkhash_2, Lmkhash_3, G4Wother},
    {"gethash",        G0Wother, Lget_hash_1, Lget_hash_2, Lget_hash, G4Wother},
    {"puthash",        G0Wother, G1Wother, Lput_hash_2, Lput_hash, G4Wother},
    {"remhash",        G0Wother, Lrem_hash_1, Lrem_hash, G3Wother, G4Wother},
    {"clrhash",        Lclr_hash_0, Lclr_hash, G2Wother, G3Wother, G4Wother},
    DEF_2("maphash",        Lmap_hash),
    DEF_1("hashcontents",   Lhash_contents),
// Now somewhat similarly for hashsets rather than hashtables. To some extent
// these are the same code!
    DEF_1("mkhashset",      Lmkhashset),
    DEF_2("gethashset",     Lget_hash_2),
    DEF_2("sethashset",     Lset_hashset),
    DEF_2("resethashset",   Lrem_hash),
    DEF_1("clrhashset",     Lclr_hash),
    DEF_2("maphashset",     Lmap_hash),
    DEF_1("hashsetcontents",Lhash_contents),
// And finally something that Common Lisp asks for that seems a bit silly!
    DEF_1("sxhash",         Lsxhash),
    {nullptr,          nullptr, nullptr, nullptr, nullptr, nullptr}
};

// end of lisphash.cpp
