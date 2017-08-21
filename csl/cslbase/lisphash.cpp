// lisphash.cpp                            Copyright (C) 1989-2017 Codemist

//
// Hashtables...
//

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


#include "headers.h"

//
// (June 2016...) I am working on a total replacement for this file that
// will use a different hashing scheme based on Cuckoo Hashing so that
// I end up with a guarantee that every lookup will cost at worst 3 probes
// (and in practise lookups are expected to average out at under 1.5 probes
// when successful and under 2 when not). The new scheme will also cope with
// large tables more efficiently.  Perhaps the main
// difference elsewhere in the code will be that the new scheme expects
// the garbage collector to take hash tables as in need of rehashing, while
// the old one did some rehashing within the garbage collector itself. The
// idea behind the new version there is that the rehashing will now only
// happen when the table is next used, and parhaps many hash tables will
// just remain in a slightly messed up state saving the cost of gratuitously
// rehashing them in an eager manner.
//

LispObject Lmkhash2(LispObject env, LispObject size, LispObject flavour)
{   if (!is_fixnum(size)) aerror1("mkhash", size);
    if (int_of_fixnum(size) <= 0) aerror1("mkhash", size);
    size_t size1 = int_of_fixnum(size);
    if (!is_fixnum(flavour) && !consp(flavour))
        aerror1("mkhash", flavour);
// Very small requests will still lead to a table of size at least 5
    if (size1 < 10) size1 = 5;
// I want to table size to be a prime so that (hash%size) stands a good chance
// of making use of all the bits of hash, and to ease issues of the stride
// I use to resolve collisions.
    size1 = size1 | 1;
    while (!isprime(size1)) size1 += 2;
// Now the vector that I create will have 2*size+1 elements. That is because
// the vector will have information in element zero to indicate the hashing
// regime it uses, and it will then have pairs of values (key/value). The
// result is that overall the vector will have an even number of cells if you
// include its header word.
    LispObject v = get_vector_init((2*size1+2)*CELL, SPID_HASHEMPTY);
    push(v);
// The top-level of the hash vactor will be of fixed size with 4 cells
// [header, flavour, count_of_entries, vector]
    LispObject v1 = get_basic_vector_init(4*CELL, nil);
    pop(v);
    push2(v, v1);
// I do not go "cons(w, eq_hash_tables)" here because then if the cons
// triggered a garbage collection the value of eq_hash_tables would be
// somewhere where the GC scanned it, and that must not be allowed to
// happen.
    v = ncons(v);
    qcdr(v) = eq_hash_tables;
    eq_hash_tables = v;
    pop2(v1, v);
    elt(v, 0) = basic_elt(v1, 0) = flavour;
    basic_elt(v1, 1) = fixnum_of_int(0);
    basic_elt(v1, 2) = v;
    vechdr(v1) ^= (TYPE_SIMPLE_VEC ^ TYPE_HASH);
    return onevalue(v1);
}

LispObject Lmkhash(LispObject env, int nargs, ...)
//
// (mkhash size flavour growth)
//
// size suggests qbout how large the table will be. It certainly ends up
// rounded to a prime.
// flavour is 0, 1, 2, 3 or 4 corresponding to hash tables
// that use EQ, EQL, EQUAL, EQUALS or EQUALP.
// growth used to give an indication of how enthusuastically the table
// should be enlarged when it got full, but it is now ignored!
//
// If flavour is not a number it might be a dotted pair (hashfn . eqfn)
// where hashfn is a user-provided function to compute hash values (which
// will actually be permitted to be anything at all, since I will then
// hash the output again as if hashing under EQL - but I expect that really
// I expect numeric hash values), and eqfn is a function used to compare
// items. [this facility is at present not implemented]
//
{   va_list a;
    argcheck(nargs, 3, "mkhash");
    va_start(a, nargs);
    LispObject size = va_arg(a, LispObject);
    LispObject flavour = va_arg(a, LispObject);
//@ growth = va_arg(a, LispObject);   // just ignore third argument
    va_end(a);
    return Lmkhash2(env, size, flavour);
}

//
// I use the following while combining parts of a structure to compute a
// hash value. It may not be totally wonderful (I would need to soak my mind
// in pseudo-random numbers to do a really good job) but it will probably
// serve for now. Well I rather view it as pretty grotty in that it still
// returns just 31-bits. But I will not mess with it while I am making
// bigger changes here.
//

static uint64_t update_hash(uint64_t prev, uint64_t data)
{   prev = prev ^ data;
    prev = prev ^ (prev >> 11);
    prev = prev ^ ((prev & 0xffffff) * 169);
    return prev & 0x7fffffff;
}

static uint64_t hash_eql(LispObject key)
//
// Must return same code for two eql numbers.  This is remarkably
// painful! I would like the value to be insensitive to fine details
// of the machine I am running on.
//
{   if (is_bfloat(key))
    {   int h = type_of_header(flthdr(key));
// For floating point values I look at the binary representation of
// the number.
// The Strict Aliasing Rules are liable to render this sort of things
// slightly dangerous.
        union nasty
        {   double fp;
            uint32_t i[2];
        } nasty_union;
        union nasty2
        {   float128_t fp;
            uint32_t i[sizeof(float128_t)/4];
        } nasty2_union;
        nasty_union.i[0] = nasty_union.i[1] = 0;
        switch (h)
        {   case TYPE_SINGLE_FLOAT:
                nasty_union.fp = (double)single_float_val(key);
//
// A *horrid* issue arises here in that (EQL 0.0 -0.0) will be true
// hence 0.0 and -0.0 must hash to the same value. Hence the following
// line even if at first sight it looks ridiculous!
//
                if (nasty_union.fp == -0.0) nasty_union.fp = 0.0;
                break;
            case TYPE_DOUBLE_FLOAT:
                nasty_union.fp = double_float_val(key);
                if (nasty_union.fp == -0.0) nasty_union.fp = 0.0;
                break;
            case TYPE_LONG_FLOAT:
                {   nasty2_union.fp = long_float_val(key);
                    if (f128M_zero(&nasty2_union.fp))
                        memset(&nasty2_union.i, 0, sizeof(nasty2_union));
                    uint64_t h128 = 0;
                    for (unsigned int i=0; i<sizeof(float128_t)/4; i++)
                        h128 = update_hash(h128, nasty2_union.i[i]);
                    return h128;
                }
            default:
                nasty_union.fp = 0.0;
        }
//
// The following line is OK on any one computer, but will generate values
// that are not portable across machines with different floating point
// representation. This is not too important when the hash value is only
// used with my built-in implementation of hash tables, since I arrange
// to re-hash everything when an image file is re-loaded (as well as on
// any garbage collection), so non-portable calculation here is corrected
// for automatically.
// But also beware the Strict Aliasing rules. I could probably be safe
// against them by using arrays of chars rather than of int32_t values...
        return update_hash(nasty_union.i[0], nasty_union.i[1]);
    }
    else if (is_numbers(key))
    {   Header h = numhdr(key);
        uint64_t r = 9876543;
        size_t n;
        switch (type_of_header(h))
        {   case TYPE_BIGNUM:
                n = length_of_header(h);
                n = (n-CELL-4)/4;  // last index into the data
//
// This may be overkill - for very long bignums it is possibly a waste to
// walk over ALL the digits when computing a hash value - I could do well
// enough just looking at a few. But I still feel safer using all of them.
// Note that all bignums have at least one word of data.
                for (;;)
                {   r = update_hash(r, bignum_digits(key)[n]);
                    if (n == 0) break;
                    n--;
                }
                return r;
            case TYPE_RATNUM:
            case TYPE_COMPLEX_NUM:
                return update_hash(hash_eql(numerator(key)),
                                   hash_eql(denominator(key)));
            default:
                return 0x12345678;  // unknown type of number?
        }
    }
//
// For all things OTHER than messy numbers I just hand back the
// representation of the object as a C pointer. Well, I scramble it a bit
// because otherwise too often Lisp objects only differ in their low order
// bits.
//
    else return update_hash(1, (uint64_t)key);
}

static uint64_t hash_cl_equal(LispObject key, bool descend)
//
// This function is the one used hashing things under EQUAL, and note
// that Common Lisp expects that EQUAL will NOT descend vectors or
// structures, so this code had better not. But it is supposed to
// descend path-names and it must treat non-simple strings and bitvectors
// as if they were like ordinary strings and bitvectors.  If descend is
// false this will not descend through lists.
//
{   uint64_t r = 1, c;
    LispObject w;
    size_t len;
    size_t offset;
    Header ha;
#ifdef CHECK_STACK
    if (check_stack("@" __FILE__,__LINE__))
    {   err_printf("Stack too deep in hash calculation\n");
        my_exit(EXIT_FAILURE);
    }
#endif
    for (;;)
    {   switch (TAG_BITS & (int)key)
        {   case TAG_CONS:
                if (key == nil || !descend) return r;
                r = update_hash(r, hash_cl_equal(qcar(key), true));
                key = qcdr(key);
                continue;
            case TAG_SYMBOL:
                if (key == nil) return r;
                return update_hash(1, (uint64_t)key);
            case TAG_VECTOR:
            {   ha = vechdr(key);
                len = bytes_in_vector(key);
//
// I need to treat strings and bitvectors here specially since in those
// cases (and for pathnames) I must inspect the vector contents, while
// in other cases I must not.
//
                if (is_string(key))
                {   len = bytes_in_bytevector(key);
                    offset = 0;
                    goto hash_as_string;
                }
//
// I might need to re-check that Common Lisp EQUAL and hence this
// version of hashing inspects the bits in a bit-vector.
//
                else if (is_bitvec(key))
                {   len = bits_in_bitvector(key);
                    offset = 0;
                    goto hash_as_bitvector;
                }
                else if (type_of_vector(key) == TYPE_ARRAY)
                {
//
// Arrays are fun here! I need to pick up the special case of character
// vectors and bit vectors and make them compute the same hash value as the
// simple case of the same thing.
//
                    w = basic_elt(key, 0);
                    if (w == string_char_sym) ha = 0;
#ifdef COMMON
                    else if (w == bit_symbol) ha = 1;
#endif
                    else return update_hash(r, (uint64_t)key);
//
// The stuff here is just for "non-simple" strings and bit-vectors. This
// code will not have been tested much - if at all. I furthermore view it as
// one of the areas where Common Lisp went over the top adding complexity
// beyond the benefit provided.
//
                    w = basic_elt(key, 1);           // List of dimensions
                    if (!consp(w) || consp(qcdr(w))) // 1 dim or more?
                        return update_hash(r, (uint64_t)key);
                    len = int_of_fixnum(qcar(w));    // This is the length
                    w = basic_elt(key, 5);           // Fill pointer
                    if (is_fixnum(w)) len = int_of_fixnum(w);
                    w = basic_elt(key, 3);           // displace adjustment
                    key = basic_elt(key, 2);         // vector holding the actual data
                    if (ha)
                    {   offset = int_of_fixnum(w);
                        goto hash_as_bitvector;
                    }
                    offset = int_of_fixnum(w);
                    goto hash_as_string;
                }
#ifdef COMMON
//
// Common Lisp demands that pathname structures be compared and hashed in
// a way that is expected to look at their contents. Here I just descend
// all components of the pathname.
//
                else if (type_of_vector(key) == TYPE_STRUCTURE &&
                         basic_elt(key, 0) == pathname_symbol &&
                         descend)
                {   len = doubleword_align_up(length_of_header(ha));
                    while ((len -= CELL) != 0)
                    {   LispObject ea =
                            *((LispObject *)((char *)key + len - TAG_VECTOR));
                        r = update_hash(r, hash_cl_equal(ea, true));
                    }
                    return r;
                }
#endif
                else return update_hash(r, (uint64_t)key);
            }
            case TAG_HDR_IMMED:
                return update_hash(r, (uint64_t)key);
            case TAG_BOXFLOAT:
            default:
                return update_hash(r, hash_eql(key));
        }

    hash_as_string:
//
// Here len is the length of the string data structure, excluding header.
// I work character by character here both because the final word of a
// string will usually not be full and to avoid sensitivity to byte order.
// but that may be adding to by costs in an unhelpful way, so maybe
// I should work harder to do this word at a time?
//
        while (len > 0)
        {   c = celt(key, --len + offset);
            r = update_hash(r, c);
        }
        return r;
    hash_as_bitvector:
//
// here len is the number of bits to scan, and offsetoff is a BIT offset.
// This really is clumsily inefficient but it is never used in Standard
// Lisp mode anyway, so I can test and enhance it if anybody not only
// uses Common Lisp but then relies on hashing bit-vectors.
//
        len += offset;
        while (len > offset)
        {   len--;
            c = celt(key, len >> 5) & (1u << (len & 31));
            if (c != 0) c = 1;
            r = update_hash(r, c);
        }
        return r;
    }
}

uint64_t hash_equal(LispObject key)
//
// This function is the one used hashing things under the Standard Lisp
// version of EQUAL, which descends vectors but is still sensitive to
// case and which views different types of numbers as different. I will
// make it view displaced or fill-pointered vectors as equivalent to the
// corresponding simple vectors: I am pretty well obliged to do that for
// strings and bitvectors so it seems polite to do the same for general
// vectors (which are the only other ones I support!).
//
{   uint64_t r = 1, c;
    LispObject w;
    int type;
    size_t len, offset = 0;
    Header ha;
#ifdef CHECK_STACK
    if (check_stack("@" __FILE__,__LINE__))
    {   err_printf("Stack too deep in hash calculation\n");
        my_exit(EXIT_FAILURE);
    }
#endif
    for (;;)
    {   switch (TAG_BITS & (int)key)
        {   case TAG_CONS:
                if (key == nil) return r;
                r = update_hash(r, hash_equal(qcar(key)));
                key = qcdr(key);
                continue;
            case TAG_SYMBOL:
                if (key == nil) return r;
                return update_hash(1, (uint64_t)key);
            case TAG_VECTOR:
            {   ha = vechdr(key);
                type = type_of_vector(key);
                len = bytes_in_vector(key);
//
// First I will separate off the two important cases of strings
// and bitvectors.
//
                if (is_string(key))
                {   len = bytes_in_bytevector(key);
                    offset = 0;
                    goto hash_as_string;
                }
                else if (is_bitvec(key))
                {   len = bits_in_bitvector(key);
                    offset = 0;
                    goto hash_as_bitvector;
                }
#ifdef COMMON
//
// Common Lisp demands that pathname structures be compared and hashed in
// a way that is expected to look at their contents. Here I just descend
// all components of the pathname. All other structures are hashed on
// the basis of EQ.
//
                if (type == TYPE_STRUCTURE &&
                    basic_elt(key, 0) != pathname_symbol)
                    return update_hash(r, (uint64_t)key);
#endif
//
// Now I will look for an array that is in fact just a vector.
//
                if (type == TYPE_ARRAY)
                {   w = basic_elt(key, 0);
                    if (w == string_char_sym) ha = 0;
#ifdef COMMON
                    else if (w == bit_symbol) ha = 1;
#endif
                    else ha = 2;
//
// All this mess really needs careful review and testing!
//
                    w = basic_elt(key, 1);        // List of dimensions
                    if (consp(w) && !consp(qcdr(w)))   // 1 dim or not?
                    {   len = int_of_fixnum(qcar(w));  // This is the length
                        w = basic_elt(key, 5);         // Fill pointer
                        if (is_fixnum(w)) len = int_of_fixnum(w);
                        w = basic_elt(key, 3);         // displace adjustment
                        key = basic_elt(key, 2);       // vector holding the data
                        switch (ha)
                        {   case 0:
                                offset = int_of_fixnum(w);
                                goto hash_as_string;
                            case 1:
                                offset = int_of_fixnum(w);
                                goto hash_as_bitvector;
                            default:
                                offset = int_of_fixnum(w);
                                break;
                        }
                    }
                }
//
// Now in the case that I had a non-simple vector I have reset key to point
// to the vector containing the true data, and
// len is the length that I want to use. offset is an offset into the vector.
// For simple vectors all the same variables are set up (and offset will be
// zero). All cases of strings and bitvectors should have been dealt with
// so the only vectors containing binary are things like "file" structures,
// and I do not expect them to hash portably: so I hash them in the basis of
// EQ.  Hmm did I implement vectors of unboxed 8, 16 and 32-bit ints and of
// floats? If so they might need to be treated above in the sort of way that
// strings are.
//
                if (vector_holds_binary(key))
                    return update_hash(r, (uint64_t)key);
// A "mixed" vector is something I use within CSL for various system
// purposes, and it has three list items at the front and then a load of
// binary data. I hash the binary data as raw 32-bit data.
                if (is_mixed_header(vechdr(key)))
                {   while (len > 3*CELL)
                    {   uint32_t ea;
                        len -= 4;
                        ea = *(uint32_t *)((char *)key + CELL +
                                           offset + len - TAG_VECTOR);
//@@printf("Hashing binary item at offset %d in vector (o=%d)\n", offset+len, offset);
                        r = update_hash(r, (uint64_t)ea);
                    }
                }
                while (len != 0)
                {   LispObject ea;
                    len -= CELL;
                    ea = elt(key, len/CELL+offset);
//@@printf("Hashing item at offset %d in vector (o=%d)\n", offset+len, offset);
                    r = update_hash(r, hash_equal(ea));
                }
//@@printf("Hash = %.8x\n", r);
                return r;
            }
            case TAG_HDR_IMMED:
                return update_hash(r, (uint64_t)key);
            case TAG_BOXFLOAT:
            default:// The default case here mainly covers numbers
                return update_hash(r, hash_eql(key));
        }

    hash_as_string:
// Here len is the length of the string data structure, excluding header
        {   int32_t w = 0;
            while (len > 0)
            {   c = celt(key, --len+offset);
                w = (w << 8) | c;
                if (w & 0xff000000)
                {   r = update_hash(r, w);
                    w = 0;
                }
            }
            if (w != 0) r = update_hash(r, w);
        }
        return r;
    hash_as_bitvector:
// here len is the number of bits to scan, and offset is a BIT offset
        len += offset;
        while (len > offset)
        {   len--;
            c = celt(key, len >> 3) & (1 << (len & 7));
            if (c != 0) c = 1;
            r = update_hash(r, c);
        }
        return r;
    }
}

static uint64_t hash_equalp(LispObject key)
//
// This function is the one used hashing things under the Common Lisp
// version of EQUALP, which descends vectors but not structs (except
// pathnames), which is case-insensitive and which views numbers of
// different types but similar values (eg 1 and 1.0) as EQUALP).
//
{   uint64_t r = 1, c;
    LispObject w;
    size_t len, offset = 0;
    Header ha;
#ifdef CHECK_STACK
    if (check_stack("@" __FILE__,__LINE__))
    {   err_printf("Stack too deep in hash calculation\n");
        my_exit(EXIT_FAILURE);
    }
#endif
    for (;;)
    {   switch (TAG_BITS & (int)key)
        {   case TAG_CONS:
                if (key == nil) return r;
                r = update_hash(r, hash_equalp(qcar(key)));
                key = qcdr(key);
                continue;
            case TAG_SYMBOL:
                if (key == nil) return r;
                return update_hash(1, (uint64_t)key);
            case TAG_VECTOR:
            {   ha = vechdr(key);
                len = bytes_in_vector(key);
// First I will separate off the two important cases of strings and bitvectors
                if (is_string(key))
                {   len = bytes_in_bytevector(key);
                    offset = 0;
                    goto hash_as_string;
                }
// Treatment of bitvecs will be WRONG here! But I now forget how or why!
// That was a comment I had put in long ago.
                else if (is_bitvec(key))
                {   len = bits_in_bitvector(key);
                    offset = 0;
                    goto hash_as_bitvector;
                }
#ifdef COMMON
//
// Common Lisp demands that pathname structures be compared and hashed in
// a way that is expected to look at their contents. Here I just descend
// all components of the pathname. Other structs are not descended.
//
                if (type_of_vector(key) == TYPE_STRUCTURE &&
                    basic_elt(key, 0) != pathname_symbol)
                    return update_hash(r, (uint64_t)key);
#endif
//
// Now I will look for an array that is in fact just a vector.
//
                if (type_of_vector(key) == TYPE_ARRAY)
                {   w = basic_elt(key, 0);
                    if (w == string_char_sym) ha = 0;
#ifdef COMMON
                    else if (w == bit_symbol) ha = 1;
#endif
                    else ha = 2;
                    w = basic_elt(key, 1);             // List of dimensions
                    if (consp(w) && !consp(qcdr(w)))   // 1 dim or not?
                    {   len = int_of_fixnum(qcar(w));  // This is the length
                        w = basic_elt(key, 5);         // Fill pointer
                        if (is_fixnum(w)) len = int_of_fixnum(w);
                        w = basic_elt(key, 3);         // displace adjustment
                        key = basic_elt(key, 2);       // vector holding the data
                        switch (ha)
                        {   case 0:
                                offset = int_of_fixnum(w);
                                goto hash_nearly_as_string;
                            case 1:
                                offset = int_of_fixnum(w);
                                goto hash_as_bitvector;
                            default:
                                offset = int_of_fixnum(w);
                                break;
                        }
                    }
                }
//
// Now in the case that I had a non-simple vector I have reset key to point
// to the vector containing the true data and
// len is the length that I want to use. offset is an offset into the vector.
// For simple vectors all the same variables are set up (and offset will be
// zero). All cases of strings and bitvectors should have been dealt with
// so the only vectors containing binary are things like "file" structures,
// and I do not expect them to hash portably.
//
                if (vector_holds_binary(key))
                    return update_hash(r, (uint64_t)key);
                if (is_mixed_header(ha))
                {   while (len > 4*CELL)
                    {   uint32_t ea;
                        len -= 4;
                        ea = *(uint32_t *)((char *)key +
                                           offset + len - TAG_VECTOR);
                        r = update_hash(r, ea);
                    }
                }
                while ((len -= CELL) != 0)
                {   LispObject ea = elt(key, len/CELL+offset);
                    r = update_hash(r, hash_equalp(ea));
                }
                return r;
            }
            case TAG_HDR_IMMED:
                if (is_char(key))
                    key = pack_char(0, tolower(code_of_char(key)));
                return update_hash(r, (uint64_t)key);
            case TAG_BOXFLOAT:
            default:// The default case here mainly covers numbers
                if (is_float(key))
                {   key = rational(key);  // painful expense
                }
                if (is_numbers(key))
                {   switch (type_of_header(numhdr(key)))
                    {   case TYPE_RATNUM:
                        case TYPE_COMPLEX_NUM:
                            return update_hash(r,
                                               update_hash(hash_equalp(numerator(key)),
                                                           hash_equalp(denominator(key))));
                        default:
                            break;
                    }
                }
                return update_hash(r, hash_eql(key));
        }
//
// Note that I scan the elements of a string or bitvector in the same order
// that I would process a general vector of the same length, and I adjust the
// vector contents to its generic representation before updating the hash
// value. For strings I fold to lower case.
//
    hash_as_string:
// Here len is the length of the string data structure, excluding header
        {   int32_t w = 0;
            while (len > 0)
            {   c = celt(key, --len + offset);
                c = tolower(c);
                w = (w << 8) | c;
                if (w & 0xff000000)
                {   r = update_hash(r, w);
                    w = 0;
                }
            }
            if (w != 0) r = update_hash(r, w);
        }
        return r;
    hash_nearly_as_string:
// Here len is the length of the string data structure, excluding header
        {   int32_t w = 0;
            while (len > 0)
            {   c = celt(key, --len + offset);
                w = (w << 8) | c;
                if (w & 0xff000000)
                {   r = update_hash(r, w);
                    w = 0;
                }
            }
            if (w != 0) r = update_hash(r, w);
        }
        return r;
    hash_as_bitvector:
// here len is the number of bits to scan, and offset is a BIT offset
        len += offset;
        while (len > offset)
        {   len--;
            c = celt(key, len >> 3) & (1 << (len & 7));
            if (c != 0) c = 1;
            r = update_hash(r, update_hash(1, fixnum_of_int(c)));
        }
        return r;
    }
}

static uint64_t hashcode;
static size_t hashsize, hashoffset, hashgap;

LispObject Lget_hash(LispObject env, int nargs, ...)
{   int32_t flavour = -1;
    size_t p, size, hashstride, nprobes;
    va_list a;
    LispObject v, key, tab, dflt;
    argcheck(nargs, 3, "gethash");
    va_start(a, nargs);
    key = va_arg(a, LispObject);
    tab = va_arg(a, LispObject);
    dflt = va_arg(a, LispObject);
    va_end(a);
    if (!is_vector(tab) || type_of_vector(tab) != TYPE_HASH)
        aerror1("gethash", tab);
    v = basic_elt(tab, 0);
// /* The code here needs to allow for user-specified hash functions
    if (is_fixnum(v)) flavour = int_of_fixnum(v);
    switch (flavour)
    {   default:
            aerror1("gethash", cons(v, tab));
        case 0:
            hashcode = update_hash(1, (uint64_t)key);
            break;
        case 1:
            hashcode = hash_eql(key);
            break;
        case 2:
            push3(key, tab, dflt);
            hashcode = hash_cl_equal(key, true);
            pop3(dflt, tab, key);
            break;
        case 3:
            push3(key, tab, dflt);
            hashcode = hash_equal(key);
            pop3(dflt, tab, key);
            break;
        case 4:
            push3(key, tab, dflt);
            hashcode = hash_equalp(key);
            pop3(dflt, tab, key);
            break;
    }
    v = basic_elt(tab, 2);
    hashsize = size = cells_in_vector(v)-1;
    p = (hashcode % (uint64_t)(size >> 1))*2;
//
// I want to take my single 64-bit hash value and produce a secondary
// hash value that is a stride for the search. I can just take the
// remainder by 1 less than the hash table size (and add 1 so I get
// a non-zero stride).
//
    hashstride = (1 + (hashcode % (uint64_t)((size >> 1)-1)))*2;
    hashgap = (size_t)-1;
    for (nprobes=0; nprobes<size; nprobes++)
    {   LispObject q = elt(v, p+1);
        bool cf;
        if (q == SPID_HASHEMPTY)
        {   mv_2 = nil;
            work_0 = v;
            hashoffset = p;
#ifdef HASH_STATISTICS
            Nhget++;              // item not present
#endif
            return nvalues(dflt, 2);
        }
        if (q == SPID_HASHTOMB)
        {   hashgap = p;
            cf = false;  // vacated slot
        }
// /* again user-specified hash functions need insertion here
        else switch (flavour)
        {   default: // case 0:
                cf = (q == key);
                break;
            case 1: cf = eql(q, key);
                break;
            case 2: push4(key, tab, dflt, v);
                if (q == key) cf = true;
                else cf = cl_equal(q, key);
                pop4(v, dflt, tab, key);
                break;
            case 3: push4(key, tab, dflt, v);
                if (q == key) cf = true;
                else cf = equal(q, key);
                pop4(v, dflt, tab, key);
                break;
            case 4: push4(key, tab, dflt, v);
                if (q == key) cf = true;
                else cf = equalp(q, key);
                pop4(v, dflt, tab, key);
                break;
        }
#ifdef HASH_STATISTICS
        Nhgetp++;
#endif
        if (cf)
        {   mv_2 = lisp_true;
            work_0 = v;
            hashoffset = p;
#ifdef HASH_STATISTICS
            Nhget++;              // item found
#endif
            return nvalues(elt(v, p+2), 2);
        }
        p = p + hashstride;
        if (p >= size) p = p - size;
    }
    aerror("too many probes in hash look-up");
}

static void reinsert_hash(LispObject v, size_t size, int flavour,
                          LispObject key, LispObject val)
{   size_t p, hstride;
    uint64_t hcode;
    switch (flavour)
    {   default: // case 0:
            hcode = update_hash(1, (uint64_t)key);
            break;
        case 1:
            hcode = hash_eql(key);
            break;
        case 2:
            push3(key, v, val);
            hcode = hash_cl_equal(key, true);
            pop3(val, v, key);
            break;
        case 3:
            push3(key, v, val);
            hcode = hash_equal(key);
            pop3(val, v, key);
            break;
        case 4:
            push3(key, v, val);
            hcode = hash_equalp(key);
            pop3(val, v, key);
            break;
    }
    p = (hcode % (uint64_t)(size >> 1))*2;
    hstride = (1 + (hcode % (uint64_t)((size >> 1)-1)))*2;
//
// When I re-insert the item into the table life is especially easy -
// I know it is not there already and I know I will be able to find a
// gap to put it in!  So I just have to look for a gap - no comparisons
// are needed.
//
    for (;;)
    {   LispObject q = elt(v, p+1);
        if (q == SPID_HASHEMPTY || q == SPID_HASHTOMB)
        {   elt(v, p+1) = key;
            elt(v, p+2) = val;
            return;
        }
        p = p + hstride;
        if (p >= size) p = p - size;
    }
}

#define REHASH_CYCLES    2
#define REHASH_AT_ONE_GO 64

void rehash_this_table(LispObject v)
// Hash tables in general have hash function depending on addresses and
// will sometimes need rehashing - I do this by removing items from the
// table one at a time and re-inserting them. This does not guarantee that
// the table is left in a perfect state, but for modest loading will be
// adequate.  I reason that if I extract 64 (say) items at a time and
// then re-insert them then (especially for smallish tables) I have a
// better chance of things ending up in the ideal place. The problem is that
// items that have not yet been moved may be sitting in places where a
// re-hashed item ought to go. The effect will be that the newly re-inserted
// item sees a clash and moves to a second-choice position. When the other
// item is (later on) processed it will then vacate the place I would have
// liked to use, leaving a "tombstone" marker behind.  If at the end of all
// re-hashing there are too many tombstones left around lookup performance
// in the table will degrade. I attempt to counter this effect by performing
// the whole re-hashing procedure several times. But I have neither analysed
// nore measured what happens! I will do so if practical applications show
// up serious trouble here.
//
{   size_t size, i, j, many;
    int32_t flavour;
    LispObject pendkey[REHASH_AT_ONE_GO], pendval[REHASH_AT_ONE_GO];
    flavour = int_of_fixnum(elt(v, 0)); // Done this way always

    size = cells_in_vector(v)-1;
//
// The cycle count here is something I may want to experiment with.
//
    for (i=0; i<REHASH_CYCLES; i++)
    {
//
// Change all slots in the table that are empty just because something has
// been deleted to indicate that they are truly not in use. This makes some
// items inaccessible by normal hash searches (because a void will be placed
// earlier than them on a search trajectory) but this does not matter because
// everything is about to be taken out of the table and reinserted properly.
//

        for (j=0; j<size; j+=2)
            if (elt(v, j+1) == SPID_HASHTOMB) elt(v, j+1) = SPID_HASHEMPTY;
        many = 0;
        for (j=0; j<size; j+=2)
        {   LispObject key = elt(v, j+1),
                       val = elt(v, j+2);
            if (key == SPID_HASHEMPTY || key == SPID_HASHTOMB) continue;
            pendkey[many] = key;
            pendval[many++] = val;
            elt(v, j+1) = SPID_HASHTOMB;
            elt(v, j+2) = SPID_HASHEMPTY;
            if (many >= REHASH_AT_ONE_GO)
            {   while (many > 0)
                {   many--;
                    reinsert_hash(v, size, flavour,
                                  pendkey[many], pendval[many]);
                }
            }
        }
        while (many != 0)
        {   many--;
            reinsert_hash(v, size, flavour, pendkey[many], pendval[many]);
        }
    }
}

LispObject Lmaphash(LispObject env, LispObject fn, LispObject tab)
//
// There is a big worry here if the table is re-hashed because of
// a garbage collection while I am in the middle of things. To
// avoid utter shambles I will make a copy of the vector early
// on and work from that.
//
{   size_t size, i;
    LispObject v, v1;
    if (!is_vector(tab) || type_of_vector(tab) != TYPE_HASH)
        aerror1("maphash", tab);
    v = elt(tab, 2);
    size = cells_in_vector(v)-1;
    push2(fn, tab);
    v1 = get_vector_init((size+2)*CELL, SPID_HASHEMPTY);
    pop2(tab, fn);
    v = elt(tab, 2);
    for (i=1; i<=size; i++) elt(v1, i) = elt(v, i);
    for (i=1; i<size; i+=2)
    {   LispObject key = elt(v1, i),
                   val = elt(v1, i+1);
        if (key == SPID_HASHEMPTY || key == SPID_HASHTOMB) continue;
        push2(v1, fn);
        Lapply2(nil, 3, fn, key, val);
        pop2(fn, v1);
    }
    return onevalue(nil);
}

LispObject Lhashcontents(LispObject env, LispObject tab)
//
// There is a big worry here if the table is re-hashed because of
// a garbage collection while I am in the middle of things. To
// avoid utter shambles I will restart if a GC happens while I
// am unfolding the hash table. And fail if that happens twice
// in a row, on the ground that that suggests that I could not
// find enough space for the contents even if I started immediately
// after a GC.
//
{   int32_t size, i;
    int64_t ogcnum;
    int n_gc = 0;
    LispObject v, r;
    if (!is_vector(tab) || type_of_vector(tab) != TYPE_HASH)
        aerror1("hashcontents", tab);
    v = elt(tab, 2);
    size = cells_in_vector(v)-1;
restart:
    r = nil;
    if (++n_gc > 2) aerror("hashcontents");
    ogcnum = gc_number;
    for (i=1; i<size; i+=2)
    {   LispObject k1 = elt(v, i),
                   v1 = elt(v, i+1);
        if (k1 == SPID_HASHEMPTY || k1 == SPID_HASHTOMB) continue;
        push(v);
        r = acons(k1, v1, r);
        pop(v);
        if (gc_number != ogcnum) goto restart;
    }
    return onevalue(r);
}

LispObject Lget_hash_1(LispObject env, LispObject key)
{
#ifdef COMMON
    return Lget_hash(env, 3, key, sys_hash_table, nil);
#else
//
// The definition implemented here is as required by Reduce in
// the file matrix.red...  In the long term this is unsatisfactory.
//
    LispObject r;
    push(key);
    r = Lget_hash(nil, 3, key, sys_hash_table, nil);
    pop(key);
    if (mv_2 != nil)
    {   r = cons(key, r);
    }
    return onevalue(r);
#endif
}

LispObject Lget_hash_2(LispObject env, LispObject key, LispObject tab)
{   return Lget_hash(env, 3, key, tab, nil);
}

#ifdef DEBUG
//static int biggest_hash = 0;
#endif

LispObject Lput_hash(LispObject env, int nargs, ...)
{   va_list a;
    LispObject key, tab, val;
    va_start(a, nargs);
    key = va_arg(a, LispObject);
    tab = va_arg(a, LispObject);
    val = va_arg(a, LispObject);
    va_end(a);
    argcheck(nargs, 3, "puthash");
    if (!is_vector(tab) || type_of_vector(tab) != TYPE_HASH)
        aerror1("puthash", tab);
    push3(key, tab, val);
// I call Lget_hash here and that updates the GET statistics. So I fiddle
// things a bit to arrange that the GET numbers do not end up changed after
// and and that I know how many probes were performed.
#ifdef HASH_STATISTICS
    Nhputtmp = Nhgetp;
#endif
// A side effect of get_hash is that it leaves a pointer to either the
// entry in the table where something was found or to the first available
// empty cell encountered.
    Lget_hash(nil, 3, key, tab, nil);
#ifdef HASH_STATISTICS
    Nhputtmp = Nhgetp - Nhputtmp;
    Nhgetp -= Nhputtmp;
    Nhget--;
#endif
    pop3(val, tab, key);
    if (mv_2 == nil)    // Not found, thus I point at an empty slot
    {
#ifdef HASH_STATISTICS
        Nhputp1 += Nhputtmp;
        Nhput1++;               // adding a NEW item
#endif
        if (hashgap != (size_t)(-1)) hashoffset = hashgap;
        elt(work_0, hashoffset+1) = key;
        elt(work_0, hashoffset+2) = val;
// The zeroth element in the table tells me how many items are stored in it.
// I increment it as a fixnum here. On a 32-bit machine this could overflow
// at around 2^27 entries, but that is way too many to fit in memory so is
// not a worry.
        elt(tab, 1) += 0x10;    // increment count of used entries
        size_t capacity = cells_in_vector(basic_elt(tab, 2))-1;
// I will expand the table if it gets to be 75% full.
        if ((size_t)int_of_fixnum(basic_elt(tab, 1)) >
                    (capacity/2-capacity/8-1))
        {   push2(tab, val);
// Double the current size then round up to the next prime.
            size_t size = (capacity-1)/2;  // count of key-value pairs
            size = 2*size + 1;
            while (!isprime(size)) size += 2;
            LispObject v = get_vector_init((2*size+2)*CELL, SPID_HASHEMPTY);
            elt(v, 0) = basic_elt(tab, 0);
            pop2(val, tab);
            LispObject v1 = elt(tab, 2);  // existing (ie old) table
            basic_elt(tab, 1) = fixnum_of_int(0);
            basic_elt(tab, 2) = v;
            size_t isize = cells_in_vector(v1)-1;
            for (size_t i=1; i<isize; i+=2)
            {   LispObject key1 = elt(v1, i),
                           val1 = elt(v1, i+1);
                if (key1 == SPID_HASHEMPTY || key1 == SPID_HASHTOMB) continue;
                push3(v, tab, val);
// Re-inserting will add to the counts for hash PUT operations.
                Lput_hash(nil, 3, key1, tab, val1);
                pop3(val, tab, v);
            }
        }
        return onevalue(val);
    }
    else
    {
#ifdef HASH_STATISTICS
        Nhputp2 += Nhputtmp; // Count cases wheer an existing item is updated.
        Nhput2++;
#endif
        elt(work_0, hashoffset+2) = val;
//@@    printf("hash entry updated\n");
        return onevalue(val);
    }
}


LispObject Lput_hash_2(LispObject env, LispObject a, LispObject b)
{   return Lput_hash(env, 3, a, sys_hash_table, b);
}

LispObject Lrem_hash(LispObject env, LispObject key, LispObject tab)
{   push2(key, tab);
    Lget_hash(nil, 3, key, tab, nil);
    pop2(tab, key);
    if (mv_2 == nil) return onevalue(nil);
    else
    {   elt(work_0, hashoffset+1) = SPID_HASHTOMB;
        elt(work_0, hashoffset+2) = SPID_HASHEMPTY;
        basic_elt(tab, 1) -= 0x10;
// Some folk would believe that if the table shrank too much I should
// shrink it, or at the very least re-hash it.
// Right now I am not doing that!
        return onevalue(lisp_true);
    }
}

LispObject Lrem_hash_1(LispObject env, LispObject a)
{   return Lrem_hash(env, a, sys_hash_table);
}

LispObject Lclr_hash(LispObject, LispObject tab)
{   LispObject v;
    size_t size, i;
    if (!is_vector(tab) ||
        type_of_vector(tab) != TYPE_HASH)
        aerror1("clrhash", tab);
    basic_elt(tab, 1) = fixnum_of_int(0);
    v = basic_elt(tab, 2);
    size = cells_in_vector(v)-1;
    for (i=1; i<size; i+=2)
    {   elt(v, i) = SPID_HASHEMPTY;
        elt(v, i+1) = SPID_HASHEMPTY;
    }
    return tab;
}

LispObject Lclr_hash_0(LispObject env, int nargs, ...)
{   argcheck(nargs, 0, "clrhash");
    return Lclr_hash(env, sys_hash_table);
}

// sxhash is a function that I am coming to believe that I do not like.
// For the "hash value" that it returns to follow the requirements that
// Common Lisp was garbled from the start and clean-ups seem to me to leave
// it still a mess. Tha main issue here is that the hash value that is
// computed must not change when garbage collection shuffles memory, and
// so all items that EQUAL compares using EQ have to have some special
// treatment where it is not clear that there is a sensible behaviour
// to use. But the KEY issue here is that the hash function used to support
// built-in hash tables is probably not going to be suitable.

LispObject Lsxhash(LispObject env, LispObject key)
{
//
// Does not descend vectors
//
    uint64_t h = hash_cl_equal(key, true);
    h = (h ^ (h >> 16)) & 0x03ffffff; // ensure it will be a positive fixnum
    return onevalue((intptr_t)fixnum_of_int(h));
}

LispObject Leqlhash(LispObject env, LispObject key)
{
//
// Only handles atoms
//
    uint32_t h = hash_cl_equal(key, false);
    h = (h ^ (h >> 16)) & 0x03ffffff; // ensure it will be a positive fixnum
    return onevalue(fixnum_of_int(h));
}

LispObject Lequalhash(LispObject env, LispObject key)
{
//
// Descends vectors as the Standard Lisp EQUAL function does.
//
    uint32_t h = hash_equal(key);
    h = (h ^ (h >> 16)) & 0x03ffffff; // ensure it will be a positive fixnum
    return onevalue(fixnum_of_int(h));
}

LispObject Lhash_flavour(LispObject env, LispObject tab)
{   LispObject v,flavour = fixnum_of_int(-1);

    if (!is_vector(tab) || type_of_header(vechdr(tab)) != TYPE_HASH)
        aerror1("hash_flavour", tab);
    v = elt(tab, 0);
//  The code here needs to allow for user-specified hash functions
    if (is_fixnum(v)) flavour = v;
    return onevalue(flavour);
}

setup_type const lisphash_setup[] =
{   {"mkhash",                  WRONG_NO_3A, Lmkhash2, Lmkhash},
    {"gethash",                 Lget_hash_1, Lget_hash_2, Lget_hash},
    {"puthash",                 WRONG_NO_3A, Lput_hash_2, Lput_hash},
    {"remhash",                 Lrem_hash_1, Lrem_hash, WRONG_NO_2},
    {"clrhash",                 Lclr_hash, TOO_MANY_1, Lclr_hash_0},
    {"sxhash",                  Lsxhash, TOO_MANY_1, WRONG_NO_1},
    {"eqlhash",                 Leqlhash, TOO_MANY_1, WRONG_NO_1},
    {"equalhash",               Lequalhash, TOO_MANY_1, WRONG_NO_1},
    {"maphash",                 TOO_FEW_2, Lmaphash, WRONG_NO_2},
    {"hashcontents",            Lhashcontents, TOO_MANY_1, WRONG_NO_1},
    {"hashtable-flavour",       Lhash_flavour, TOO_MANY_1, WRONG_NO_1},
    {NULL,                      0, 0, 0}
};

// end of lisphash.cpp
