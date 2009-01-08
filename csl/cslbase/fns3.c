/*  fns3.c                          Copyright (C) 1989-2008 Codemist Ltd */

/*
 * Basic functions part 3.
 * A concentration on hashtable, vector and array access code here.
 */

/**************************************************************************
 * Copyright (C) 2008, Codemist Ltd.                     A C Norman       *
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



/* Signature: 124475ef 24-May-2008 */

#include "headers.h"


#ifdef COMMON
#include "clsyms.h"
#endif

/*
 * Common Lisp and Standard Lisp disagree about vector sizes.  Common
 * Lisp counts the number of elements in a vector (with make-simple-vector
 * and vector-bound) while Standard Lisp uses the value n, where the
 * vector concerned will accept index values from 0 to n (inclusive)
 * (mkvect and upbv).  I provide the Standard Lisp versions always, so I
 * can use them even in Common Lisp mode.  The vectors are exactly the
 * same - it is just a different way of talking about them.
 */

Lisp_Object Lmkvect(Lisp_Object nil, Lisp_Object n)
{
    int32_t n1;
    if (!is_fixnum(n)) return aerror1("mkvect", n);
    n1 = int_of_fixnum(n)*CELL;
    n1 += CELL; /* Oh! What an abomination! Standard Lisp allocated 0::n, */
                /* Common allocates n items                               */
/* Note that this allows the user to go (mkvect -1) to make a vector with
 * no elements at all. This is mildly odd! */
    if (n1 < 0) return aerror1("mkvect", n);
    return onevalue(getvector_init(n1+CELL, nil));
}

#ifdef COMMON
Lisp_Object Lmksimplevec(Lisp_Object nil, Lisp_Object n)
{
    int32_t n1;
    if (!is_fixnum(n)) return aerror1("make-simple-vector", n);
    n1 = int_of_fixnum(n)*CELL;
    if (n1 < 0) return aerror1("make-simple-vector", n);
    return onevalue(getvector_init(n1+CELL, nil));
}
#endif

/*
 * This one creates a "structure" tagged vector.
 */

Lisp_Object Lmkevect(Lisp_Object nil, Lisp_Object n)
{
    int32_t n1;
    if (!is_fixnum(n)) return aerror1("mkevect", n);
    n1 = int_of_fixnum(n)*CELL;
#ifndef COMMON
    n1 += CELL; /* Oh! What an abomination! Standard Lisp allocated 0::n, */
                /* Common allocates n items                               */
#endif
    if (n1 < 0) return aerror1("mkevect", n);
    n = getvector_init(n1+CELL, nil);
    errexit();
    vechdr(n) ^= (TYPE_SIMPLE_VEC ^ TYPE_STRUCTURE);
    return onevalue(n);
}

/*
 * The following creates a sort of vector where the first 3 items are
 * lisp pointers, and the remainder may be filled with binary stuff (which
 * is not byte-flipped or anything on garbage collection, and so is possibly
 * fairly unsafe). It is intended for internal or experimental use only.
 */

Lisp_Object Lmkxvect(Lisp_Object nil, Lisp_Object n)
{
    int32_t n1;
    if (!is_fixnum(n)) return aerror1("mkxvect", n);
    n1 = int_of_fixnum(n)*CELL;
#ifndef COMMON
    n1 += CELL; /* Oh! What an abomination! Standard Lisp allocated 0::n, */
                /* Common allocates n items                               */
#endif
    if (n1 < 3*CELL) return aerror1("mkxvect", n);
    n = getvector_init(n1+CELL, nil);
    errexit();
    vechdr(n) ^= (TYPE_SIMPLE_VEC ^ TYPE_MIXED1);
    return onevalue(n);
}

Lisp_Object encapsulate_pointer(void *data)
/*
 * Creates a boxed up representation of a pointer. Note that with this
 * function in place the tag-name SPARE is a misnomer! However I view
 * this code as a temporary experiment at the present...
 */
{   Lisp_Object w = getvector(TAG_VECTOR, TYPE_SPARE, 2*CELL);
    Lisp_Object nil;
    errexit();
    elt(w, 0) = (Lisp_Object)data;
    return w;
}

void *extract_pointer(Lisp_Object a)
{
    if (!is_vector(a) ||
        type_of_header(vechdr(a)) != TYPE_SPARE)
        return NULL;
    else return (void *)elt(a, 0);
}

Lisp_Object Lencapsulatedp(Lisp_Object nil, Lisp_Object a)
{
    if (is_vector(a) && type_of_header(vechdr(a)) == TYPE_SPARE)
        return onevalue(lisp_true);
    else return nil;
}

/*
 * The next few functions are an EXPERIMENT and apply when a reference to
 * a native Maple object has somehow been imported into CSL and packed
 * up as an "encapsulated pointer" as per above.
 */

Lisp_Object Lmaple_atomic_value(Lisp_Object nil, Lisp_Object a)
{
    Lisp_Object v;
    CSL_IGNORE(nil);
    if (!is_vector(a) ||
        type_of_header(vechdr(a)) != TYPE_SPARE)
        return aerror1("not an encapsulated pointer", a);
    v = (Lisp_Object)extract_pointer(a);
    if ((v & 1) != 0)
    {
/*
 * The next line overflows the range of CSL fixnums too early, but
 * will serve as a place-holder for a while!
 */
        return onevalue(fixnum_of_int(v >> 1));
    }
    else return onevalue(C_nil);
}

Lisp_Object Lmaple_tag(Lisp_Object nil, Lisp_Object a)
{
    Lisp_Object v;
    Lisp_Object *v1;
    CSL_IGNORE(nil);
    if (!is_vector(a) ||
        type_of_header(vechdr(a)) != TYPE_SPARE)
        return aerror1("not an encapsulated pointer", a);
    v = (Lisp_Object)extract_pointer(a);
    if ((v & 1) != 0) return onevalue(C_nil); /* an atomic value */
    v1 = (Lisp_Object *)v;
    v = *v1;    /* the header word of the Maple object */
/* The following line will be incorrect on 64-bit machines */
    return onevalue(fixnum_of_int(v >> 26));
}

Lisp_Object Lmaple_length(Lisp_Object nil, Lisp_Object a)
{
    Lisp_Object v;
    Lisp_Object *v1;
    CSL_IGNORE(nil);
    if (!is_vector(a) ||
        type_of_header(vechdr(a)) != TYPE_SPARE)
        return aerror1("not an encapsulated pointer", a);
    v = (Lisp_Object)extract_pointer(a);
    if ((v & 1) != 0) return onevalue(C_nil); /* an atomic value */
    v1 = (Lisp_Object *)v;
    v = *v1;    /* the header word of the Maple object */
/* The following line will be incorrect on 64-bit machines */
    return onevalue(fixnum_of_int(v & 0x03ffffff));
}

Lisp_Object Lmaple_string_data(Lisp_Object nil, Lisp_Object a)
{
    Lisp_Object *p = (Lisp_Object *)extract_pointer(a);
    char *s = (char *)&p[3];
    CSL_IGNORE(nil);
    return onevalue(make_string(s));
}

Lisp_Object Lmaple_integer(Lisp_Object nil, Lisp_Object a)
{
    Lisp_Object r = fixnum_of_int(0);
    Lisp_Object *p = (Lisp_Object *)extract_pointer(a);
    int i;
    Lisp_Object t = fixnum_of_int(1);
    int len = (int)(*p & 0x03ffffff);
    for (i=1; i<len; i++)
    {   int d = fixnum_of_int((int)p[i]);
        push2(r, t);
        d = Ltimes2(nil, d, t);
        pop2(t, r);
        errexit();
        push(t);
        r = Lplus2(nil, r, d);
        pop(t);
        errexit();
        push(r);
        t = Ltimes2(nil, t, fixnum_of_int(10000));
        pop(r);
        errexit();
    }
    return r;
}

Lisp_Object Lmaple_component(Lisp_Object nil, Lisp_Object a, Lisp_Object nn)
{
    Lisp_Object v;
    Lisp_Object *v1;
    int32_t len, n;
    CSL_IGNORE(nil);
    if (!is_fixnum(nn)) return aerror1("integer needed as selector", nn);
    if (!is_vector(a) ||
        type_of_header(vechdr(a)) != TYPE_SPARE)
        return aerror1("not an encapsulated pointer", a);
    v = (Lisp_Object)extract_pointer(a);
    if ((v & 1) != 0) return onevalue(C_nil); /* an atomic value */
    v1 = (Lisp_Object *)v;
    v = *v1;    /* the header word of the Maple object */
    n = int_of_fixnum(nn);
/* The following line will be incorrect on 64-bit machines */
    len = v & 0x03ffffff;
    if (n < 0 || n >= len) return aerror1("subscript out of range", nn);
    return onevalue(encapsulate_pointer((void *)v1[n+1]));
}

int primep(int32_t n)
/*
 * Used to ensure that the body of a hash-table has a size that is prime.
 * Assumes that the value to be checked is not especially large.
 *  Since it will have been handed in as a
 * fixnum it is at worst 2^28 or so, so brute-force should be OK.
 */
{
    int32_t i;
    if ((n & 1) == 0) return 0;   /* even */
    for (i=3; i*i<=n; i+=2)
        if (n%i == 0) return 0;
    return 1;
}

#define HASH_CHUNK_SIZE   (((uint32_t)1) << (PAGE_BITS-3))
#define HASH_CHUNK_WORDS  (HASH_CHUNK_SIZE/CELL)

static Lisp_Object get_hash_vector(int32_t n)
{
    Lisp_Object v, nil = C_nil;
/*
 * A major ugliness here is that I need to support hash tables that are
 * larger than the largest simple vector I can use (as limited by
 * CSL_PAGE_SIZE). To achieve this I will handle such huge tables using
 * a vector of vectors, with the higher level vector tagged as a STRUCT,
 * and the lower level vectors each sized at around 1/8 of a CSL page. The
 * modest chunk size is intended to limit the packing lossage I will see at
 * page boundaries. HASH_CHUNK_SIZE is the size (in bytes) used for data in
 * each such hash chunk.
 */
    if (n > CSL_PAGE_SIZE/2)   /* A fairly arbitrary cut-off */
    {   int32_t chunks = (n + HASH_CHUNK_SIZE - 1)/HASH_CHUNK_SIZE;
        int32_t i;
        v = getvector_init(CELL*(chunks+3), nil);
        errexit();
/* The next line tags the top level vector as a struct */
        vechdr(v) ^= (TYPE_SIMPLE_VEC ^ TYPE_STRUCTURE);
        elt(v, 1) = fixnum_of_int(n);
        for (i=0; i<chunks; i++)
        {   Lisp_Object v1;
            push(v);
/*
 * In general the last of these chunks will be larger that it really needs
 * to be, but keeping all chunks the same standard size seems a useful
 * simplification right at present!
 */
            v1 = getvector_init(HASH_CHUNK_SIZE+CELL, SPID_HASH0);
            pop(v);
            errexit();
            elt(v, i+2) = v1;
        }
    }
    else v = getvector_init(n, SPID_HASH0);
    return v;
}

Lisp_Object MS_CDECL Lmkhash(Lisp_Object nil, int nargs, ...)
/*
 * size suggests how many items can be inserted before re-hashing
 * occurs. flavour is 0, 1, 2, 3 or 4 corresponding to hash tables
 * that use EQ, EQL, EQUAL, EQUALS or EQUALP.  growth is a floating point
 * value suggesting how much to grow by when rehashing is needed.
 *
 * NB.  Hash tables of type 0 or 1 (using EQ or EQL) will need special
 * treatment by the garbage collector - in particular since the garbage
 * collector can relocate values the entire contents of the tables will
 * need rearrangement.  Tables of types 2, 3 and 4 use hash-codes that are
 * more expensive to compute, but which are insensitive to memory addresses
 * and the like, and so so NOT need special treatment.  Tables that need
 * re-hashing on GC are kept on a special list, known to the GC. Even type
 * 2, 3 and 4 hash tables are rehashed when a core image is re-loaded, since
 * the hash function may be byte-order sensitive.
 *
 * If flavour is not a number it might be a dotted pair (hashfn . eqfn)
 * where hashfn is a user-provided function to compute hash values (which
 * will actually be permitted to be anything at all, since I will then
 * hash the output again as if hashing under EQL - but I expect that really
 * I expect numeric hash values), and eqfn is a function used to compare
 * items. [this facility may not be implemented at first]
 */
{
    va_list a;
    int32_t size1, size2;
    Lisp_Object v, v1, size, flavour, growth;
    argcheck(nargs, 3, "mkhash");
    va_start(a, nargs);
    size = va_arg(a, Lisp_Object);
    flavour = va_arg(a, Lisp_Object);
    growth = va_arg(a, Lisp_Object);
    va_end(a);
    if (!is_fixnum(size)) return aerror1("mkhash", size);
    size1 = int_of_fixnum(size);
    if (size1 <= 0) return aerror1("mkhash", size);
    if (!is_fixnum(flavour) && !consp(flavour))
        return aerror1("mkhash", flavour);
/*
 * I will start with a table with around 1.5 times as many slots as
 * were requested, and will ensure that the size is a prime. I also add
 * in a little more so that people who ask for VERY small tables get
 * given ones that are not mindlessly tiny.
 */
    size2 = (size1 + (size1/2) + 4) | 1;
    while (!primep(size2)) size2 += 2;
    size2 = size2*CELL;
    push(growth);
/*
 * Huge hash tables will be stored (internally) in chunks.
 */
    v = get_hash_vector(2*size2+2*CELL);
    errexitn(1);
    push(v);
    v1 = getvector_init(6*CELL, nil);
    pop2(v, growth);
    errexit();
    push3(v, v1, growth);
    v = ncons(v);
    errexitn(3);
/*
 * I keep a list of all hash tables in a weak list-head.  The use of ncons
 * followed by a RPLACD is because I want xx_hash_tables to be the ONLY
 * possible pointer to that bit of list. Even if I garbage collect while
 * updating it. Note that I also re-hash every garbage collection if the
 * hash function is a user-provided one. This is a matter of security
 * since it will often not really be necessary, since it will be a bit hard
 * for user hash functions to depend on absolute memory addresses. But all
 * rehashing costs is some time, I hope.
 */
    if (flavour == fixnum_of_int(0) ||
        flavour == fixnum_of_int(1) || !is_fixnum(flavour))
    {   qcdr(v) = eq_hash_tables;
        eq_hash_tables = v;
    }
    else
    {   qcdr(v) = equal_hash_tables;
        equal_hash_tables = v;
    }
    pop3(growth, v1, v);
    elt(v, 0) = elt(v1, 0) = flavour;
    elt(v1, 1) = fixnum_of_int(0);
    elt(v1, 2) = size;
    elt(v1, 3) = growth;
    elt(v1, 4) = v;
    vechdr(v1) ^= (TYPE_SIMPLE_VEC ^ TYPE_HASH);
    return onevalue(v1);
}

/*
 * I use the following while combining parts of a structure to compute a
 * hash value. It may not be totally wonderful (I would need to soak my mind
 * in pseudo-random numbers to do a really good job) but it will probably
 * serve for now.
 */

static uint32_t update_hash(uint32_t prev, uint32_t data)
{
    prev = prev ^ data;
    prev = prev ^ (prev >> 11);
    prev = prev ^ ((prev & 0xffffff) * 169);
    return prev & 0x7fffffff;
}

static uint32_t hash_eql(Lisp_Object key)
/*
 * Must return same code for two eql numbers.  This is remarkably
 * painfull! I would like the value to be insensitive to fine details
 * of the machine I am running on.
 */
{
    if (is_bfloat(key))
    {   int32_t h = type_of_header(flthdr(key));
/*
 * For floating point values I look at the binary representation of
 * the number.
 */
        union nasty
        {   double fp;
            uint32_t i[2];
        } nasty_union;
        nasty_union.i[0] = nasty_union.i[1] = 0;
        switch (h)
        {
#ifdef COMMON
    case TYPE_SINGLE_FLOAT:
            nasty_union.fp = (double)single_float_val(key);
            break;
#endif
    case TYPE_DOUBLE_FLOAT:
            nasty_union.fp = double_float_val(key);
            break;
#ifdef COMMON
    case TYPE_LONG_FLOAT:
            nasty_union.fp = (double)long_float_val(key);
            break;
#endif
    default:
            nasty_union.fp = 0.0;
        }
/*
 * The following line is OK on any one computer, but will generate values
 * that are not portable across machines with different floating point
 * representation. This is not too important when the hash value is only
 * used with my built-in implementation of hash tables, since I arrange
 * to re-hash everything when an image file is re-loaded (as well as on
 * any garbage collection), so non-portable calculation here is corrected
 * for automatically.
 */
        return update_hash(nasty_union.i[0], nasty_union.i[1]);
    }
    else if (is_numbers(key))
    {   Header h = numhdr(key);
        uint32_t r;
        int n;
        switch (type_of_header(h))
        {
    case TYPE_BIGNUM:
            n = length_of_header(h);
            n = (n>>2) - 2;  /* last index into the data */
            r = update_hash(1, (uint32_t)h);
/*
 * This mat be overkill - for very long bignums it is possibly a waste to
 * walk over ALL the digits when computing a hash value - I could do well
 * enough just looking at a few. But I still feel safer using all of them.
 */
            while (n >= 0)
            {   r = update_hash(r, bignum_digits(key)[n]);
                n--;
            }
            return r;
#ifdef COMMON
    case TYPE_RATNUM:
    case TYPE_COMPLEX_NUM:
            return update_hash(hash_eql(numerator(key)),
                               hash_eql(denominator(key)));
#endif
    default:
            return 0x12345678;  /* unknown type of number? */
        }
    }
/*
 * For all things OTHER than messy numbers I just hand back the
 * representation of the object as a C pointer. Well, I scramble it a bit
 * because otherwise too often Lisp objects only differ in their low order
 * bits.
 */
    else return update_hash(1, (uint32_t)key);
}

static uint32_t hash_cl_equal(Lisp_Object key, CSLbool descend)
/*
 * This function is the one used hashing things under EQUAL, and note
 * that Common Lisp expects that EQUAL will NOT descend vectors or
 * structures, so this code had better not. But it is supposed to
 * descend path-names and it must treat non-simple strings and bitvectors
 * as if they were like ordinary strings and bitvectors.  If descend is
 * false this will not descend through lists.
 */
{
    uint32_t r = 1, c;
    Lisp_Object nil = C_nil, w;
    int32_t len;
#ifdef COMMON
    int32_t bitoff;
#endif
    unsigned char *data;
    Header ha;
#ifdef CHECK_STACK
    if (check_stack(__FILE__,__LINE__))
    {   err_printf("Stack too deep in hash calculation\n");
        my_exit(EXIT_FAILURE);
    }
#endif
    for (;;)
    {   switch (TAG_BITS & (int32_t)key)
        {
    case TAG_CONS:
            if (key == C_nil || !descend) return r;
            r = update_hash(r, hash_cl_equal(qcar(key), YES));
            nil = C_nil;
            if (exception_pending()) return 0;
            key = qcdr(key);
            continue;
    case TAG_SYMBOL:
            if (key == C_nil) return r;
            key = get_pname(key);
            nil = C_nil;
            if (exception_pending()) return 0;
            r = update_hash(r, 1); /* makes name & string hash differently */
            /* Drop through, because the pname is a string */
    case TAG_VECTOR:
            {   ha = vechdr(key);
                len = type_of_header(ha);
/*
 * I need to treat strings and bitvectors here specially since in those
 * cases (and for pathnames) I must inspect the vector contents, while
 * in other cases I must not.
 */
                if (len == TYPE_STRING)
                {   len = length_of_header(ha) - CELL;
                    data = &ucelt(key, 0);
                    goto hash_as_string;
                }
#ifdef COMMON
                else if (header_of_bitvector(ha))
                {   len = length_of_header(ha);
                    len = (len - 5)*8 + ((ha & 0x380) >> 7) + 1;
                    bitoff = 0;
                    data = &ucelt(key, 0);
                    goto hash_as_bitvector;
                }
#endif
                else if (len == TYPE_ARRAY)
                {
/*
 * Arrays are fun here! I need to pick up the special case of character
 * vectors and bit vectors and make them compute the same hash value as the
 * simple case of the same thing.
 */
                    w = elt(key, 0);
                    if (w == string_char_sym) ha = 0;
#ifdef COMMON
                    else if (w == bit_symbol) ha = 1;
#endif
                    else return update_hash(r, (uint32_t)key);
                    w = elt(key, 1);                 /* List of dimensions */
                    if (!consp(w) || consp(qcdr(w))) /* 1 dim or more?     */
                        return update_hash(r, (uint32_t)key);
                    len = int_of_fixnum(qcar(w));    /* This is the length */
                    w = elt(key, 5);                 /* Fill pointer       */
                    if (is_fixnum(w)) len = int_of_fixnum(w);
                    w = elt(key, 3);       /* displace adjustment */
                    key = elt(key, 2);     /* vector holding the actual data */
                    data = &ucelt(key, 0);
#ifdef COMMON
                    if (ha)
                    {   bitoff = int_of_fixnum(w);
                        goto hash_as_bitvector;
                    }
#endif
                    data += int_of_fixnum(w);
                    goto hash_as_string;
                }
#ifdef COMMON
/*
 * Common Lisp demands that pathname structures be compared and hashed in
 * a way that is expected to look at their contents. Here I just descend
 * all components of the pathname.
 */
                else if (len == TYPE_STRUCTURE &&
                         elt(key, 0) == pathname_symbol &&
                         descend)
                {   len = doubleword_align_up(length_of_header(ha));
                    while ((len -= CELL) != 0)
                    {   Lisp_Object ea =
                            *((Lisp_Object *)((char *)key + len - TAG_VECTOR));
                        r = update_hash(r, hash_cl_equal(ea, YES));
                        nil = C_nil;
                        if (exception_pending()) return 0;
                    }
                    return r;
                }
#endif
                else return update_hash(r, (uint32_t)key);
            }
    case TAG_ODDS:
            if (is_bps(key))
            {   data = (unsigned char *)data_of_bps(key);
                /* I treat bytecode things as strings here */
                len = length_of_header(*(Header *)(data - CELL));
                goto hash_as_string;
            }
            else return update_hash(r, (uint32_t)key);
    case TAG_BOXFLOAT:
/*
 * The "case TAG_BOXFLOAT:" above is not logically necessary, but at least
 * one release of a Silicon Graphics C compiler seems to miscompile this
 * function without it (when optimised). It is as if it seems the masking
 * with TAG_BITS in the switch() and therefore knows that there is just a
 * limited range of possibilities, so it omits the normal range-check one
 * would use before a table-branch. But it then leaves the branch table
 * that it generates NOT padded with the final case (TAG_BOXFLOAT) that is
 * needed, so when a floating point values does arise the code goes into the
 * yonder and usually crashes.
 */
    default:
            return hash_eql(key);
        }

hash_as_string:
/* Here len is the length of the string data structure, excluding header */
        while (len > 0)
        {   c = data[--len];
            r = update_hash(r, c);
        }
        return r;
#ifdef COMMON
hash_as_bitvector:
/* here len is the number of bits to scan, and bitoff is a BIT offset */
        len += bitoff;
        while (len > bitoff)
        {   len--;
            c = data[len >> 3] & (1 << (len & 7));
            if (c != 0) c = 1;
            r = update_hash(r, c);
        }
        return r;
#endif
    }
}

static uint32_t hash_equal(Lisp_Object key)
/*
 * This function is the one used hashing things under the Standard Lisp
 * version of EQUAL, which descends vectors but is still sensitive to
 * case and which views different types of numbers as different. I will
 * make it view displaced or fill-pointered vectors as equivalent to the
 * corresponding simple vectors: I am pretty well obliged to do that for
 * strings and bitvectors so it seems polite to do the same for general
 * vectors (which are the only other ones I support!).
 */
{
    uint32_t r = 1, c;
    Lisp_Object nil = C_nil, w;
    int32_t type, len, offset = 0;
    unsigned char *data;
    Header ha;
#ifdef CHECK_STACK
    if (check_stack(__FILE__,__LINE__))
    {   err_printf("Stack too deep in hash calculation\n");
        my_exit(EXIT_FAILURE);
    }
#endif
    for (;;)
    {   switch (TAG_BITS & (int32_t)key)
        {
    case TAG_CONS:
            if (key == C_nil) return r;
            r = update_hash(r, hash_equal(qcar(key)));
            nil = C_nil;
            if (exception_pending()) return 0;
            key = qcdr(key);
            continue;
    case TAG_SYMBOL:
            if (key == C_nil) return r;
            key = get_pname(key);
            nil = C_nil;
            if (exception_pending()) return 0;
            r = update_hash(r, 1);
            /* Drop through, because the pname is a string */
    case TAG_VECTOR:
            {   ha = vechdr(key);
                type = type_of_header(ha);
                len = length_of_header(ha) - CELL;  /* counts in bytes here */
/*
 * First I will separate off the two important cases of strings and bitvectors
 */
                if (type == TYPE_STRING)
                {   data = &ucelt(key, 0);
                    goto hash_as_string;
                }
#ifdef COMMON
                else if (header_of_bitvector(ha))
                {   len = (len - 1)*8 + ((ha & 0x380) >> 7) + 1;
                    offset = 0;
                    data = &ucelt(key, 0);
                    goto hash_as_bitvector;
                }
#endif
#ifdef COMMON
/*
 * Common Lisp demands that pathname structures be compared and hashed in
 * a way that is expected to look at their contents. Here I just descend
 * all components of the pathname.
 */
                if (len == TYPE_STRUCTURE &&
                    elt(key, 0) != pathname_symbol)
                    return update_hash(r, (uint32_t)key);
#endif
/*
 * Now I will look for an array that is in fact just a vector.
 */
                if (type == TYPE_ARRAY)
                {   w = elt(key, 0);
                    if (w == string_char_sym) ha = 0;
#ifdef COMMON
                    else if (w == bit_symbol) ha = 1;
#endif
                    else ha = 2;
                    w = elt(key, 1);        /* List of dimensions */
                    if (consp(w) && !consp(qcdr(w)))   /* 1 dim or not?      */
                    {   len = int_of_fixnum(qcar(w));  /* This is the length */
                        w = elt(key, 5);               /* Fill pointer       */
                        if (is_fixnum(w)) len = int_of_fixnum(w);
                        w = elt(key, 3);       /* displace adjustment        */
                        key = elt(key, 2);     /* vector holding the data    */
                        switch (ha)
                        {
                    case 0: data = &ucelt(key, int_of_fixnum(w));
                            goto hash_as_string;
#ifdef COMMON
                    case 1:
                            data = &ucelt(key, 0);
                            offset = int_of_fixnum(w);
                            goto hash_as_bitvector;
#endif
                    default:
/* /* The code here can CRASH if asked to hash a general array that
 * has been represented in chunks because it has over 32K elements.
 */
                            ha = vechdr(key);
                            offset = int_of_fixnum(w);
                            break;
                        }
                    }
                }
/*
 * Now in the case that I had a non-simple vector I have reset key to point
 * to the vector containing the true data, ha to the header of same and
 * len is the length that I want to use. offset is an offset into the vector.
 * For simple vectors all the same variables are set up (and offset will be
 * zero). All cases of strings and bitvectors should have been dealt with
 * so the only vectors containing binary are things like "file" structures,
 * and I do not expect them to hash portably.
 */
                if (vector_holds_binary(ha))
                    return update_hash(r, (uint32_t)key);
                offset = CELL*offset;
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
                {   Lisp_Object ea =
                        *((Lisp_Object *)((char *)key +
                                          offset + len - TAG_VECTOR));
                    r = update_hash(r, hash_equal(ea));
                    nil = C_nil;
                    if (exception_pending()) return 0;
                }
                return r;
            }
    case TAG_ODDS:
            if (is_bps(key))
            {   data = (unsigned char *)data_of_bps(key);
                /* I treat bytecode things as strings here */
                len = length_of_header(*(Header *)(data - CELL));
                goto hash_as_string;
            }
            else return update_hash(r, (uint32_t)key);
    case TAG_BOXFLOAT:
    default:/* The default case here mainly covers numbers */
            return hash_eql(key);
        }

hash_as_string:
/* Here len is the length of the string data structure, excluding header */
        while (len > 0)
        {   c = data[--len];
            r = update_hash(r, c);
        }
        return r;
#ifdef COMMON
hash_as_bitvector:
/* here len is the number of bits to scan, and offset is a BIT offset */
        len += offset;
        while (len > offset)
        {   len--;
            c = data[len >> 3] & (1 << (len & 7));
            if (c != 0) c = 1;
            r = update_hash(r, c);
        }
        return r;
#endif
    }
}

static uint32_t hash_equalp(Lisp_Object key)
/*
 * This function is the one used hashing things under the Common Lisp
 * version of EQUALP, which descends vectors but not structs (except
 * pathnames), which is case-insensitive and which views numbers of
 * different types but similar values (eg 1 and 1.0) as EQUALP).
 */
{
    uint32_t r = 1, c;
    Lisp_Object nil=C_nil, w;
    int32_t type, len, offset = 0;
    unsigned char *data;
    Header ha;
#ifdef CHECK_STACK
    if (check_stack(__FILE__,__LINE__))
    {   err_printf("Stack too deep in hash calculation\n");
        my_exit(EXIT_FAILURE);
    }
#endif
    for (;;)
    {   switch (TAG_BITS & (int32_t)key)
        {
    case TAG_CONS:
            if (key == C_nil) return r;
            r = update_hash(r, hash_equalp(qcar(key)));
            nil = C_nil;
            if (exception_pending()) return 0;
            key = qcdr(key);
            continue;
    case TAG_SYMBOL:
            if (key == C_nil) return r;
            key = get_pname(key);
            nil = C_nil;
            if (exception_pending()) return 0;
            r = update_hash(r, 1);
            /* Drop through, because the pname is a string */
    case TAG_VECTOR:
            {   ha = vechdr(key);
                type = type_of_header(ha);
                len = length_of_header(ha) - CELL;  /* counts in bytes here */
/*
 * First I will separate off the two important cases of strings and bitvectors
 */
                if (type == TYPE_STRING)
                {   data = &ucelt(key, 0);
                    goto hash_as_string;
                }
#ifdef COMMON
                else if (header_of_bitvector(ha))
                {   len = (len - 1)*8 + ((ha & 0x380) >> 7) + 1;
                    offset = 0;
                    data = &ucelt(key, 0);
                    goto hash_as_bitvector;
                }
#endif
#ifdef COMMON
/*
 * Common Lisp demands that pathname structures be compared and hashed in
 * a way that is expected to look at their contents. Here I just descend
 * all components of the pathname. Other structs are not descended.
 */
                if (len == TYPE_STRUCTURE &&
                    elt(key, 0) != pathname_symbol)
                    return update_hash(r, (uint32_t)key);
#endif
/*
 * Now I will look for an array that is in fact just a vector.
 */
                if (type == TYPE_ARRAY)
                {   w = elt(key, 0);
                    if (w == string_char_sym) ha = 0;
#ifdef COMMON
                    else if (w == bit_symbol) ha = 1;
#endif
                    else ha = 2;
                    w = elt(key, 1);        /* List of dimensions */
                    if (consp(w) && !consp(qcdr(w)))   /* 1 dim or not?      */
                    {   len = int_of_fixnum(qcar(w));  /* This is the length */
                        w = elt(key, 5);               /* Fill pointer       */
                        if (is_fixnum(w)) len = int_of_fixnum(w);
                        w = elt(key, 3);       /* displace adjustment        */
                        key = elt(key, 2);     /* vector holding the data    */
                        switch (ha)
                        {
                    case 0: data = &ucelt(key, int_of_fixnum(w));
                            goto hash_as_string;
#ifdef COMMON
                    case 1:
                            data = &ucelt(key, 0);
                            offset = int_of_fixnum(w);
                            goto hash_as_bitvector;
#endif
                    default:
/* /* Trouble if a general array with over 32K elements gets to here */
                            ha = vechdr(key);
                            offset = int_of_fixnum(w);
                            break;
                        }
                    }
                }
/*
 * Now in the case that I had a non-simple vector I have reset key to point
 * to the vector containing the true data, ha to the header of same and
 * len is the length that I want to use. offset is an offset into the vector.
 * For simple vectors all the same variables are set up (and offset will be
 * zero). All cases of strings and bitvectors should have been dealt with
 * so the only vectors containing binary are things like "file" structures,
 * and I do not expect them to hash portably.
 */
                if (vector_holds_binary(ha))
                    return update_hash(r, (uint32_t)key);
                offset = 8*offset;
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
                {   Lisp_Object ea =
                        *((Lisp_Object *)((char *)key +
                                          offset + len - TAG_VECTOR));
                    r = update_hash(r, hash_equalp(ea));
                    nil = C_nil;
                    if (exception_pending()) return 0;
                }
                return r;
            }
    case TAG_ODDS:
            if (is_bps(key))
            {   data = (unsigned char *)data_of_bps(key);
                /* I treat bytecode things as strings here */
                len = length_of_header(*(Header *)(data - CELL));
                goto hash_as_string;
            }
            else if (is_char(key))
                key = pack_char(0, 0, tolower(code_of_char(key)));
            return update_hash(r, (uint32_t)key);
    case TAG_BOXFLOAT:
    default:/* The default case here mainly covers numbers */
            if (is_float(key))
            {   key = rational(key);  /* painful expense */
                nil = C_nil;
                if (exception_pending()) return 0;
            }
#ifdef COMMON
            if (is_numbers(key))
            {   switch (type_of_header(numhdr(key)))
                {
            case TYPE_RATNUM:
            case TYPE_COMPLEX_NUM:
                    return update_hash(hash_equalp(numerator(key)),
                                       hash_equalp(denominator(key)));
            default:
                    break;
                }
            }
#endif
            return hash_eql(key);
        }
/*
 * Note that I scan the elements of a string or bitvector in the same order
 * that I would process a general vector of the same length, and I adjust the
 * vector contents to its generic representation before updating the hash
 * value. For strings I fold to lower case.
 */
hash_as_string:
/* Here len is the length of the string data structure, excluding header */
        while (len > 0)
        {   c = tolower(data[--len]);
            r = update_hash(r, update_hash(1, pack_char(0, 0, c)));
        }
        return r;
#ifdef COMMON
hash_as_bitvector:
/* here len is the number of bits to scan, and offset is a BIT offset */
        len += offset;
        while (len > offset)
        {   len--;
            c = data[len >> 3] & (1 << (len & 7));
            if (c != 0) c = 1;
            r = update_hash(r, update_hash(1, fixnum_of_int(c)));
        }
        return r;
#endif
    }
}

static uint32_t hashcode;
static int hashsize, hashoffset, hashgap;

static CSLbool large_hash_table;

#define words_in_hash_table(v)                        \
    (((large_hash_table ? int_of_fixnum(elt(v, 1)) : \
       length_of_header(vechdr(v))) - 2*CELL)/CELL)

#define ht_elt(v, n)                                                 \
    (*(large_hash_table ?                                            \
      &elt(elt((v), 2+(n)/HASH_CHUNK_WORDS), (n)%HASH_CHUNK_WORDS) : \
      &elt((v), (n))))

Lisp_Object MS_CDECL Lget_hash(Lisp_Object nil, int nargs, ...)
{
    int32_t size, p, flavour = -1, hashstride, nprobes;
    va_list a;
    Lisp_Object v, key, tab, dflt;
    argcheck(nargs, 3, "gethash");
    va_start(a, nargs);
    key = va_arg(a, Lisp_Object);
    tab = va_arg(a, Lisp_Object);
    dflt = va_arg(a, Lisp_Object);
    va_end(a);
    if (!is_vector(tab) || type_of_header(vechdr(tab)) != TYPE_HASH)
        return aerror1("gethash", tab);
    v = elt(tab, 0);
/* /* The code here needs to allow for user-specified hash functions */
    if (is_fixnum(v)) flavour = int_of_fixnum(v);
    switch (flavour)
    {
default:
        return aerror1("gethash", cons(v, tab));
case 0:
        hashcode = update_hash(1, (uint32_t)key);
        break;
case 1:
        hashcode = hash_eql(key);  /* can never fail */
        break;
case 2:
        push3(key, tab, dflt);
        hashcode = hash_cl_equal(key, YES);
        pop3(dflt, tab, key);
        errexit();
        break;
case 3:
        push3(key, tab, dflt);
        hashcode = hash_equal(key);
        pop3(dflt, tab, key);
        errexit();
        break;
case 4:
        push3(key, tab, dflt);
        hashcode = hash_equalp(key);
        pop3(dflt, tab, key);
        errexit();
        break;
    }
    v = elt(tab, 4);
    large_hash_table = type_of_header(vechdr(v)) == TYPE_STRUCTURE;
    hashsize = size = words_in_hash_table(v);
    p = (hashcode % (uint32_t)(size >> 1))*2;
/*
 * I want to take my single 32-bit hash value and produce a secondary
 * hash value that is a stride for the search. I can just take the
 * remainder by 1 less than the hash table size (and add 1 so I get
 * a non-zero stride).
 */
    hashstride = (1 + (hashcode % (uint32_t)((size >> 1)-1)))*2;
    hashgap = -1;
    for (nprobes=0;nprobes<size;nprobes++)
    {   Lisp_Object q = ht_elt(v, p+1);
        CSLbool cf;
        if (q == SPID_HASH0)
        {   mv_2 = nil;
            work_0 = v;
            hashoffset = p;
            return nvalues(dflt, 2);
        }
        if (q == SPID_HASH1)
        {   hashgap = p;
            cf = NO;  /* vacated slot */
        }
/* /* again user-specified hash functions need insertion here */
        else switch (flavour)
        {
    default: /* case 0: */
            cf = (q == key);
            break;
    case 1: cf = eql(q, key);
            break;
    case 2: push4(key, tab, dflt, v);
            if (q == key) cf = YES;
            else cf = cl_equal(q, key);
            pop4(v, dflt, tab, key);
            errexit();
            break;
    case 3: push4(key, tab, dflt, v);
            if (q == key) cf = YES;
            else cf = equal(q, key);
            pop4(v, dflt, tab, key);
            errexit();
            break;
    case 4: push4(key, tab, dflt, v);
            if (q == key) cf = YES;
            else cf = equalp(q, key);
            pop4(v, dflt, tab, key);
            errexit();
            break;
        }
        if (cf)
        {   mv_2 = lisp_true;
            work_0 = v;
            hashoffset = p;
            return nvalues(ht_elt(v, p+2), 2);
        }
        p = p + hashstride;
        if (p >= size) p = p - size;
    }
    return aerror("too many probes in hash look-up");
}

static void reinsert_hash(Lisp_Object v, int32_t size, int32_t flavour,
                          Lisp_Object key, Lisp_Object val)
{
    int32_t p;
    uint32_t hcode, hstride;
    Lisp_Object nil = C_nil;
    switch (flavour)
    {
default: /* case 0: */
        hcode = update_hash(1, (uint32_t)key);
        break;
case 1:
        hcode = hash_eql(key);  /* can never fail */
        break;
case 2:
        push3(key, v, val);
        hcode = hash_cl_equal(key, YES);
        pop3(val, v, key);
        errexitv();
        break;
case 3:
        push3(key, v, val);
        hcode = hash_equal(key);
        pop3(val, v, key);
        errexitv();
        break;
case 4:
        push3(key, v, val);
        hcode = hash_equalp(key);
        pop3(val, v, key);
        errexitv();
        break;
    }
    p = (hcode % (uint32_t)(size >> 1))*2;
    hstride = (1 + (hcode % (uint32_t)((size >> 1)-1)))*2;
/*
 * When I re-insert the item into the table life is especially easy -
 * I know it is not there already and I know I will be able to find a
 * gap to put it in!  So I just have to look for a gap - no comparisons
 * are needed.
 */
    large_hash_table = type_of_header(vechdr(v)) == TYPE_STRUCTURE;
    for (;;)
    {   Lisp_Object q = ht_elt(v, p+1);
        if (q == SPID_HASH0 || q == SPID_HASH1)
        {   ht_elt(v, p+1) = key;
            ht_elt(v, p+2) = val;
            return;
        }
        p = p + hstride;
        if (p >= size) p = p - size;
    }
}

#define REHASH_CYCLES    2
#define REHASH_AT_ONE_GO 64

void rehash_this_table(Lisp_Object v)
/*
 * Hash tables where the hash function depends on absolute memory addresses
 * will sometimes need rehashing - I do this by removing items from the
 * table one at a time and re-inserting them. This does not guarantee that
 * the table is left in a perfect state, but for modest loading will be
 * adequate.  I reason that if I extract 64 (say) items at a time and
 * then re-insert them then (especially for smallish tables) I have a
 * better chance of things ending up in the ideal place. The problem is that
 * items that have not yet been moved may be sitting in places where a
 * re-hashed item ought to go. The effect will be that the newly re-inserted
 * item sees a clash and moves to a second-choice position. When the other
 * item is (later on) processed it will then vacate the place I would have
 * liked to use, leaving a "tombstone" marker behind.  If at the end of all
 * re-hashing there are too many tombstones left around lookup performance
 * in the table will degrade. I attempt to counter this effect by performing
 * the whole re-hashing procedure several times. But I have neither analysed
 * nore measured what happens! I will do so if practical applications show
 * up serious trouble here.
 */
{
    int32_t size, i, j, flavour, many;
    CSLbool old_large = large_hash_table;
    Lisp_Object pendkey[REHASH_AT_ONE_GO], pendval[REHASH_AT_ONE_GO];
    flavour = int_of_fixnum(elt(v, 0)); /* Done this way always */

    large_hash_table = type_of_header(vechdr(v)) == TYPE_STRUCTURE;
    size = words_in_hash_table(v);
/*
 * The cycle count here is something I may want to experiment with.
 */
    for (i=0; i<REHASH_CYCLES; i++)
    {
/*
 * Change all slots in the table that are empty just because something has
 * been deleted to indicate that they are truly not in use. This makes some
 * items inaccessible by normal hash searches (because a void will be placed
 * earlier than them on a search trajectory) but this does not matter because
 * everything is about to be taken out of the table and reinserted properly.
 */

        for (j=0; j<size; j+=2)
            if (ht_elt(v, j+1) == SPID_HASH1) ht_elt(v, j+1) = SPID_HASH0;
        many = 0;
        for (j=0; j<size; j+=2)
        {   Lisp_Object key = ht_elt(v, j+1), val = ht_elt(v, j+2);
            if (key == SPID_HASH0 || key == SPID_HASH1) continue;
            pendkey[many] = key;      pendval[many++] = val;
            ht_elt(v, j+1) = SPID_HASH1; ht_elt(v, j+2) = SPID_HASH0;
            if (many >= REHASH_AT_ONE_GO)
            {   while (many > 0)
                {   many--;
                    reinsert_hash(v, size, flavour,
                                  pendkey[many], pendval[many]);
                }
            }
        }
        while (--many >= 0)
            reinsert_hash(v, size, flavour, pendkey[many], pendval[many]);
    }
    large_hash_table = old_large;
}

Lisp_Object Lmaphash(Lisp_Object nil, Lisp_Object fn, Lisp_Object tab)
/*
 * There is a big worry here if the table is re-hashed because of
 * a garbage collection while I am in the middle of things. To
 * avoid utter shambles I will make a copy of the vector early
 * on and work from that.
 */
{   int32_t size, i;
    Lisp_Object v, v1;
    if (!is_vector(tab) || type_of_header(vechdr(tab)) != TYPE_HASH)
        return aerror1("maphash", tab);
    v = elt(tab, 4);
    large_hash_table = type_of_header(vechdr(v)) == TYPE_STRUCTURE;
    size = words_in_hash_table(v)*CELL+2*CELL;
    push2(fn, tab);
    v1 = get_hash_vector(size);
    pop2(tab, fn);
    v = elt(tab, 4);
    size = (size - CELL)/CELL;
    for (i=0; i<size; i++) ht_elt(v1, i) = ht_elt(v, i);
    for (i=1; i<size; i+=2)
    {   Lisp_Object key = ht_elt(v1, i), val = ht_elt(v1, i+1);
        int save = large_hash_table;
        if (key == SPID_HASH0 || key == SPID_HASH1) continue;
        push2(v1, fn);
        Lapply2(nil, 3, fn, key, val);
        pop2(fn, v1);
        large_hash_table = save;
        errexit();
    }
    return onevalue(nil);
}

Lisp_Object Lhashcontents(Lisp_Object nil, Lisp_Object tab)
/*
 * There is a big worry here if the table is re-hashed because of
 * a garbage collection while I am in the middle of things. To
 * avoid utter shambles I will restart if a GC happens while I
 * am unfolding the hash table. And fail if that happens twice
 * in a row.
 */
{
    int32_t size, i, ogcnum;
    int n_gc = 0;
    Lisp_Object v, r;
    if (!is_vector(tab) || type_of_header(vechdr(tab)) != TYPE_HASH)
        return aerror1("hashcontents", tab);
    v = elt(tab, 4);
    large_hash_table = type_of_header(vechdr(v)) == TYPE_STRUCTURE;
    size = words_in_hash_table(v)*CELL+2*CELL;
    size = (size - CELL)/CELL;
restart:
    r = nil;
    if (++n_gc > 2) return aerror("hashcontents");
    ogcnum = gc_number;
    for (i=1; i<size; i+=2)
    {   Lisp_Object k1 = ht_elt(v, i), v1 = ht_elt(v, i+1);
        if (k1 == SPID_HASH0 || k1 == SPID_HASH1) continue;
        push(v);
        r = acons(k1, v1, r);
        pop(v);
        errexit();
        if (gc_number != ogcnum) goto restart;
    }
    return onevalue(r);
}

Lisp_Object Lget_hash_1(Lisp_Object nil, Lisp_Object key)
{
#ifdef COMMON
    return Lget_hash(nil, 3, key, sys_hash_table, nil);
#else
/*
 * The definition implemented here is as required by Reduce in
 * the file matrix.red...  In the long term this is unsatisfactory.
 */
    Lisp_Object r;
    push(key);
    r = Lget_hash(nil, 3, key, sys_hash_table, nil);
    pop(key);
    errexit();
    if (mv_2 != nil)
    {   r = cons(key, r);
        errexit();
    }
    return onevalue(r);
#endif
}

Lisp_Object Lget_hash_2(Lisp_Object nil, Lisp_Object key, Lisp_Object tab)
{
    return Lget_hash(nil, 3, key, tab, nil);
}

Lisp_Object MS_CDECL Lput_hash(Lisp_Object nil, int nargs, ...)
{
    va_list a;
    Lisp_Object key, tab, val;
    va_start(a, nargs);
    key = va_arg(a, Lisp_Object);
    tab = va_arg(a, Lisp_Object);
    val = va_arg(a, Lisp_Object);
    va_end(a);
    argcheck(nargs, 3, "puthash");
    push3(key, tab, val);
    Lget_hash(nil, 3, key, tab, nil);
    pop3(val, tab, key);
    errexit();
    if (mv_2 == nil)    /* Not found, thus I point at an empty slot */
    {   if (hashgap >= 0) hashoffset = hashgap;
        ht_elt(work_0, hashoffset+1) = key;
        ht_elt(work_0, hashoffset+2) = val;
        elt(tab, 1) += 0x10;    /* increment count of used entries */
        if (elt(tab, 1) > elt(tab, 2))
        {   Lisp_Object size = elt(tab, 2),
                        growth = elt(tab, 3),
                        newhash, v;
            int32_t isize = int_of_fixnum(size), i;
            push2(tab, val);
            if (is_fixnum(growth))
            {   int32_t w1 = int_of_fixnum(growth);
                if (w1 > 0) isize = isize + w1;
                else isize = isize + (isize/2);
            }
            else if (is_float(growth))
            {   double w2 = float_of_number(growth);
                int32_t newsize = isize;
                if (1.0 < w2 && w2 < 10.0) newsize = (int32_t)(w2 * (double)isize);
                if (newsize > isize) isize = newsize;
                else isize = isize + (isize/2);
            }
            else isize = isize + (isize/2);
/*
 * NB - Lmkhash() does not disturb large_hash_table, so I can still
 * access the old table happily even after this call...
 */
            newhash = Lmkhash(nil, 3, fixnum_of_int(isize),
                              elt(tab, 0), growth);
            pop2(val, tab);
            errexit();
            v = elt(tab, 4);
            for (i=0; i<=4; i++) elt(tab, i) = elt(newhash, i);
            large_hash_table = type_of_header(vechdr(v)) == TYPE_STRUCTURE;
            isize = words_in_hash_table(v);
            for (i=0; i<isize; i+=2)
            {   Lisp_Object key1 = ht_elt(v, i+1), val1 = ht_elt(v, i+2);
                CSLbool large = large_hash_table;
                if (key1 == SPID_HASH0 || key1 == SPID_HASH1) continue;
/*
 * NB the new hash table is big enough to hold all the data that was in the
 * old one, so inserting stuff into it can not cause a (recursive)
 * enlargement here....
 */
                push3(v, tab, val);
                Lput_hash(nil, 3, key1, tab, val1);
                pop3(val, tab, v);
                large_hash_table = large; /* Maybe scrabled by put_hash */
            }
        }
        return onevalue(val);
    }
    else
    {   ht_elt(work_0, hashoffset+2) = val;
        return onevalue(val);
    }
}


Lisp_Object Lput_hash_2(Lisp_Object nil, Lisp_Object a, Lisp_Object b)
{
    return Lput_hash(nil, 3, a, sys_hash_table, b);
}

Lisp_Object Lrem_hash(Lisp_Object nil, Lisp_Object key, Lisp_Object tab)
{
    push2(key, tab);
    Lget_hash(nil, 3, key, tab, nil);
    pop2(tab, key);
    errexit();
    if (mv_2 == nil) return onevalue(nil);
    else
    {   ht_elt(work_0, hashoffset+1) = SPID_HASH1;
        ht_elt(work_0, hashoffset+2) = SPID_HASH0;
        elt(tab, 1) -= 0x10;
/*
 * Some folk would believe that if the table shrank too much I should
 * shrink it, or at the very least re-hash it.
 */
        return onevalue(lisp_true);
    }
}

Lisp_Object Lrem_hash_1(Lisp_Object nil, Lisp_Object a)
{
    return Lrem_hash(nil, a, sys_hash_table);
}

Lisp_Object Lclr_hash(Lisp_Object nil, Lisp_Object tab)
{
    Lisp_Object v;
    int32_t size, i;
    CSL_IGNORE(nil);
    if (!is_vector(tab) ||
        type_of_header(vechdr(tab)) != TYPE_HASH)
        return aerror1("clrhash", tab);
    elt(tab, 1) = fixnum_of_int(0);
    v = elt(tab, 4);
    large_hash_table = type_of_header(vechdr(v)) == TYPE_STRUCTURE;
    size = words_in_hash_table(v);
    for (i=1; i<size; i++) ht_elt(v, i) = SPID_HASH0;
    return tab;
}

Lisp_Object MS_CDECL Lclr_hash_0(Lisp_Object nil, int nargs, ...)
{
    argcheck(nargs, 0, "clrhash");
    return Lclr_hash(nil, sys_hash_table);
}

Lisp_Object Lsxhash(Lisp_Object nil, Lisp_Object key)
{
    uint32_t h = hash_cl_equal(key, YES);
    errexit();
    h = (h ^ (h >> 16)) & 0x03ffffff; /* ensure it will be a positive fixnum */
    return onevalue(fixnum_of_int(h));
}

Lisp_Object Leqlhash(Lisp_Object nil, Lisp_Object key)
{
    uint32_t h = hash_cl_equal(key, NO);
    errexit();
    h = (h ^ (h >> 16)) & 0x03ffffff; /* ensure it will be a positive fixnum */
    return onevalue(fixnum_of_int(h));
}

#ifdef COMMON
Lisp_Object Lhash_flavour(Lisp_Object nil, Lisp_Object tab)
{
    Lisp_Object v,flavour = fixnum_of_int(-1);

    if (!is_vector(tab) || type_of_header(vechdr(tab)) != TYPE_HASH)
        return aerror1("hash_flavour", tab);
    v = elt(tab, 0);
/*  The code here needs to allow for user-specified hash functions */
    if (is_fixnum(v)) flavour = v;
    return onevalue(flavour);
}
#endif

Lisp_Object MS_CDECL Lputv(Lisp_Object nil, int nargs, ...)
{
    Header h;
    va_list a;
    intptr_t n1, hl;
    Lisp_Object v, n, x;
    argcheck(nargs, 3, "putv");
    va_start(a, nargs);
    v = va_arg(a, Lisp_Object);
    n = va_arg(a, Lisp_Object);
    x = va_arg(a, Lisp_Object);
    va_end(a);
    CSL_IGNORE(nil);
    if (!is_vector(v) || vector_holds_binary(h = vechdr(v)))
        return aerror1("putv", v);
    else if (!is_fixnum(n)) return aerror1("putv offset not fixnum", n);
    hl = (length_of_header(h) - CELL)/CELL;
    n1 = int_of_fixnum(n);
    if (n1 < 0 || n1 >= hl) return aerror1("putv index range", n);
    elt(v, n1) = x;
    return onevalue(x);
}

Lisp_Object Lgetv(Lisp_Object nil, Lisp_Object v, Lisp_Object n)
{
    Header h;
    intptr_t n1, hl;
    CSL_IGNORE(nil);
    if (!is_vector(v) || vector_holds_binary(h = vechdr(v)))
        return aerror1("getv", v);
    else if (!is_fixnum(n)) return aerror1("getv offset not fixnum", n);
    hl = (length_of_header(h) - CELL)/CELL;
    n1 = int_of_fixnum(n);
    if (n1 < 0 || n1 >= hl) return aerror1("getv index range", n);
    else return onevalue(elt(v, n1));
}

/*
 * Here I make a (simple) string.
 */

Lisp_Object Lsmkvect(Lisp_Object nil, Lisp_Object n)
{
    Lisp_Object w;
    intptr_t nn;
    if (!is_fixnum(n) || (intptr_t)n<0) return aerror1("make-simple-string", n);
    nn = int_of_fixnum(n);
    w = getvector(TAG_VECTOR, TYPE_STRING, nn+CELL);
    errexit();
    nn = (intptr_t)doubleword_align_up(nn+CELL);
    while (nn > CELL)
    {   nn -= CELL;
        *(intptr_t *)((char *)w - TAG_VECTOR + nn) = 0;
    }
    return onevalue(w);
}

/*
 * Here I make a vector capable of holding 8-bit binary integers.
 */

Lisp_Object Lmkvect8(Lisp_Object nil, Lisp_Object n)
{
    Lisp_Object w;
    intptr_t nn;
    if (!is_fixnum(n) || (intptr_t)n<0) return aerror1("mkvect8", n);
    nn = int_of_fixnum(n);
    w = getvector(TAG_VECTOR, TYPE_VEC8, nn+CELL);
    errexit();
    nn = (intptr_t)doubleword_align_up(nn+CELL);
    while (nn > CELL)
    {   nn -= CELL;
        *(intptr_t *)((char *)w - TAG_VECTOR + nn) = 0;
    }
    return onevalue(w);
}

/*
 * Here I make a vector capable of holding 16-bit binary integers.
 */

Lisp_Object Lmkvect16(Lisp_Object nil, Lisp_Object n)
{
    Lisp_Object w;
    intptr_t nn;
    if (!is_fixnum(n) || (intptr_t)n<0) return aerror1("mkvect16", n);
    nn = 2*int_of_fixnum(n);
    w = getvector(TAG_VECTOR, TYPE_VEC16, nn+CELL);
    errexit();
    nn = (intptr_t)doubleword_align_up(nn+CELL);
    while (nn > CELL)
    {   nn -= CELL;
        *(intptr_t *)((char *)w - TAG_VECTOR + nn) = 0;
    }
    return onevalue(w);
}

/*
 * Here I make a vector capable of holding 32-bit binary integers.
 */

Lisp_Object Lmkvect32(Lisp_Object nil, Lisp_Object n)
{
    Lisp_Object w;
    intptr_t nn;
    if (!is_fixnum(n) || (intptr_t)n<0) return aerror1("mkvect32", n);
    nn = 4*int_of_fixnum(n);
    w = getvector(TAG_VECTOR, TYPE_VEC32, nn+CELL);
    errexit();
    nn = (intptr_t)doubleword_align_up(nn+CELL);
    while (nn > CELL)
    {   nn -= 4;
        *(int32_t *)((char *)w - TAG_VECTOR + nn) = 0;
    }
    return onevalue(w);
}

/*
 * Here I make a vector capable of holding 32-bit floats.
 */

Lisp_Object Lmkfvect32(Lisp_Object nil, Lisp_Object n)
{
    Lisp_Object w;
    intptr_t nn;
    if (!is_fixnum(n) || (intptr_t)n<0) return aerror1("mkfvect32", n);
    nn = 4*int_of_fixnum(n);
    w = getvector(TAG_VECTOR, TYPE_FLOAT32, nn+CELL);
    errexit();
    nn = (intptr_t)doubleword_align_up(nn+CELL);
    while (nn > CELL)
    {   nn -= 4;
        *(float *)((char *)w - TAG_VECTOR + nn) = (float)0.0;
    }
    return onevalue(w);
}

/*
 * Here I make a vector capable of holding 64-bit floats.
 */

Lisp_Object Lmkfvect64(Lisp_Object nil, Lisp_Object n)
{
    Lisp_Object w;
    intptr_t nn;
    if (!is_fixnum(n) || (intptr_t)n<0) return aerror1("mkfvect64", n);
    nn = 8*int_of_fixnum(n);
    if (!SIXTY_FOUR_BIT) nn += 4; /* get the doubles aligned */
    w = getvector(TAG_VECTOR, TYPE_FLOAT64, nn+CELL);
    errexit();
    nn = (intptr_t)(nn+CELL);
    while (nn > CELL)
    {   nn -= 8;
        *(double *)((char *)w - TAG_VECTOR + nn) = 0.0;
    }
    return onevalue(w);
}

Lisp_Object simplify_string(Lisp_Object s)
/*
 * s is supposed to be a string of some sort - return a simple string
 * with the same contents.  This is horrid and messy, and relies on
 * a load of stuff coded elsewhere in Lisp: is is coded here in C
 * despite that because despite the breaches of modularity that are involved
 * doing so seems to make bootstrapping easier.
 */
{
    Header h;
    Lisp_Object w, nil = C_nil, h1;
    intptr_t i, n = 0;
    if (!is_vector(s)) return aerror("simplify-string");
    h = vechdr(s);
    if (type_of_header(h) == TYPE_STRING)
        return onevalue(s);                 /* Already simple */
    if (type_of_header(h) != TYPE_ARRAY) return aerror("simplify-string");
    h1 = elt(s, 0);
    if (h1 != string_char_sym) return aerror("simplify-string");
    h1 = elt(s, 1);                         /* Dimension list */
    if (!consp(h1)) return aerror("simplify-string");
    n = int_of_fixnum(qcar(h1));            /* Look at size involved */
    h1 = elt(s, 5);                         /* Fill pointer */
    if (is_fixnum(h1)) n = int_of_fixnum(h1);
    stackcheck1(0, s);
    nil = C_nil;
    push(s);
    w = getvector(TAG_VECTOR, TYPE_STRING, n+CELL);
    pop(s);
    errexit();
    i = (intptr_t)doubleword_align_up(n+CELL);
    while (i > CELL) /* pre-fill target vector with zero */
    {   i -= CELL;
        *(intptr_t *)((char *)w - TAG_VECTOR + i) = 0;
    }
    h1 = elt(s, 3);
    h = int_of_fixnum(h1);               /* Displace adjustment */
    s = elt(s, 2);
    for (i=0; i<n; i++) celt(w, i) = celt(s, i+h);
    return onevalue(w);
}

Lisp_Object MS_CDECL Lsputv(Lisp_Object nil, int nargs, ...)
{
    Header h;
    va_list a;
    int32_t vx;
    intptr_t n1, hl;
    Lisp_Object v, n, x;
    argcheck(nargs, 3, "sputv");
    va_start(a, nargs);
    v = va_arg(a, Lisp_Object);
    n = va_arg(a, Lisp_Object);
    x = va_arg(a, Lisp_Object);
    va_end(a);
    CSL_IGNORE(nil);
    if (!is_vector(v) || type_of_header(h = vechdr(v)) != TYPE_STRING)
        return aerror1("putv-char", v);
    else if (!is_fixnum(n)) return aerror1("putv-char", n);
    else if (is_fixnum(x)) vx = int_of_fixnum(x);
    else if (is_char(x)) vx = code_of_char(x);
    else return aerror1("putv-char contents", x);
    hl = length_of_header(h) - CELL;
    n1 = int_of_fixnum(n);
    if (n1 < 0 || n1 >= hl) return aerror1("putv-char", n);
#ifdef Kanji
    if (iswchar((int)vx)
    {   if (n1 == hl-1) return aerror1("putv-char", n);
        celt(v, n1) = (char)(vx >> 8);
        celt(v, n1+1) = (char)vx;
    }
    else celt(v, n1) = (char)vx;
#else
    celt(v, n1) = (char)vx;
#endif
    return onevalue(x);
}

Lisp_Object Lbpsupbv(Lisp_Object nil, Lisp_Object v)
{
    Header h;
    int32_t n;
    CSL_IGNORE(nil);
    if (!(is_bps(v))) return aerror1("bps-upbv", v);
    h = *(Header *)((char *)data_of_bps(v) - CELL);
    n = length_of_header(h) - CELL;
    return onevalue(fixnum_of_int(n-1));
}

Lisp_Object MS_CDECL Lbpsputv(Lisp_Object nil, int nargs, ...)
{
    Header h;
    va_list a;
    int32_t n1, hl;
    Lisp_Object v, n, x;
    argcheck(nargs, 3, "bpsputv");
    va_start(a, nargs);
    v = va_arg(a, Lisp_Object);
    n = va_arg(a, Lisp_Object);
    x = va_arg(a, Lisp_Object);
    va_end(a);
    CSL_IGNORE(nil);
    if (!is_bps(v)) return aerror1("bpsputv", v);
    else if (!is_fixnum(n)) return aerror1("bps-putv", n);
    else if (!is_fixnum(x)) return aerror1("bps-putv contents", x);
    h = *(Header *)((char *)data_of_bps(v) - CELL);
    hl = length_of_header(h) - CELL;
    n1 = int_of_fixnum(n);
    if (n1 < 0 || n1 >= hl) return aerror1("bps-putv", n);
    *((char *)data_of_bps(v) + n1) = (char)int_of_fixnum(x);
    return onevalue(x);
}

/*
 * To make this function Standard Lisp Friendly it will return as its
 * value a SYMBOL. This is because unadorned character objects are not
 * really part of Standard Lisp.  For cases where you want to character
 * code I have introduced a function scharn which is almost exactly the
 * same except that it returns an integer character code not a symbol.
 */

Lisp_Object Lsgetv(Lisp_Object nil, Lisp_Object v, Lisp_Object n)
{
    Header h;
    int w;
    int32_t n1, hl;
    CSL_IGNORE(nil);
    if (!is_vector(v) || type_of_header(h = vechdr(v)) != TYPE_STRING)
        return aerror1("schar", v);
    else if (!is_fixnum(n)) return aerror1("schar", n);
    hl = length_of_header(h) - CELL;
    n1 = int_of_fixnum(n);
    if (n1 < 0 || n1 >= hl) return aerror1("schar", n);
    w = celt(v, n1);
#ifdef Kanji
    if (n1 < hl-1 && is2byte(w)) w = (w << 8) + celt(v, n+1);
#endif
#ifdef COMMON
    return onevalue(pack_char(0, 0, w)); /* NB 16-bit chars OK here */
#else
#ifdef Kanji
    if (w & 0xff00)
    {   celt(boffo, 0) = w >> 8;
        celt(boffo, 1) = w;
/*
 * If it is an extended character I will look up a symbol for it each time.
 * this will make processing extended characters distinctly more expensive
 * than working with the basic ASCII ones, but I hope it will still be
 * acceptable.
 */
        n = iintern(boffo, 2, lisp_package, 0);
        errexit();
        return onevalue(n);
    }
#endif
/*
 * For 8-bit characters I keep a table of ready-interned Lisp symbols.
 */
    n = elt(charvec, w & 0xff);
    if (n == nil)
    {   celt(boffo, 0) = (char)w;
        n = iintern(boffo, 1, lisp_package, 0);
        errexit();
        elt(charvec, w & 0xff) = n;
    }
    return onevalue(n);
#endif
}

Lisp_Object Lsgetvn(Lisp_Object nil, Lisp_Object v, Lisp_Object n)
{
    Header h;
    int w;
    intptr_t n1, hl;
    CSL_IGNORE(nil);
    if (!is_vector(v) || type_of_header(h = vechdr(v)) != TYPE_STRING)
        return aerror1("scharn", v);
    else if (!is_fixnum(n)) return aerror1("scharn", n);
    hl = length_of_header(h) - CELL;
    n1 = int_of_fixnum(n);
    if (n1 < 0 || n1 >= hl) return aerror1("scharn", n);
    w = celt(v, n1);
#ifdef Kanji
    if (n1 < hl-1 && is2byte(w)) w = (w << 8) + celt(v, n+1);
#endif
    return onevalue(fixnum_of_int(w));
}

Lisp_Object Lbytegetv(Lisp_Object nil, Lisp_Object v, Lisp_Object n)
{
    Header h;
    int w;
    intptr_t n1, hl;
    CSL_IGNORE(nil);
    if (!is_vector(v) || type_of_header(h = vechdr(v)) != TYPE_STRING)
        return aerror1("byte-getv", v);
    else if (!is_fixnum(n)) return aerror1("byte-getv", n);
    hl = length_of_header(h) - CELL;
    n1 = int_of_fixnum(n);
    if (n1 < 0 || n1 >= hl) return aerror1("byte-getv", n);
    w = ucelt(v, n1);
    return onevalue(fixnum_of_int(w));
}

Lisp_Object Lbpsgetv(Lisp_Object nil, Lisp_Object v, Lisp_Object n)
{
    Header h;
    intptr_t n1, hl;
    CSL_IGNORE(nil);
    if (!is_bps(v)) return aerror1("bps-getv", v);
    else if (!is_fixnum(n)) return aerror1("bps-getv", n);
    h = *(Header *)((char *)data_of_bps(v) - CELL);
    hl = length_of_header(h) - CELL;
    n1 = int_of_fixnum(n);
    if (n1 < 0 || n1 >= hl) return aerror1("bps-getv", n);
    n1 = *((char *)data_of_bps(v) + n1);
    return onevalue(fixnum_of_int(n1 & 0xff));
}

/*
 * native-putv and native-getv have an optional trailing argument that
 * should have the value 1, 2 or 4 to indicate the number of bytes to be
 * transferred.
 */

Lisp_Object MS_CDECL Lnativeputv(Lisp_Object nil, int nargs, ...)
{
    va_list a;
    int32_t o, v32, width;
    intptr_t p;
    Lisp_Object v, n, x, w;
    if (nargs != 4)
    {   argcheck(nargs, 3, "native-putv");
    }
    va_start(a, nargs);
    v = va_arg(a, Lisp_Object);
    n = va_arg(a, Lisp_Object);
    x = va_arg(a, Lisp_Object);
    if (nargs == 4) w = va_arg(a, Lisp_Object);
    else w = fixnum_of_int(1);
    va_end(a);
    CSL_IGNORE(nil);
    if (!consp(v) ||
        !is_fixnum(qcar(v)) ||
        !is_fixnum(qcdr(v)) ||
        (p = int_of_fixnum(qcar(v))) < 0 ||
        p > native_pages_count) return aerror1("native-putv", v);
    else if (!is_fixnum(n)) return aerror1("native-putv", n);
    else if (!is_fixnum(x) &&
             (!is_numbers(x) || !is_bignum(x)))
        return aerror1("native-putv contents", x);
    else if (!is_fixnum(w)) return aerror1("native-putv width", w);
    width = int_of_fixnum(w);
    o = int_of_fixnum(qcdr(v)) + int_of_fixnum(n);
    if (o < 0 || o >= CSL_PAGE_SIZE) return aerror1("native-putv", n);
    p = (intptr_t)native_pages[p];
    p = doubleword_align_up(p);
    v32 = thirty_two_bits(x);
    switch (width)
    {
default:
        return aerror1("native-putv width", w);
case 1:
        *((char *)p + o) = (char)v32;
        break;
case 2:
/*
 * The code that I had first written here tried to use int16, but
 * there are some computers where that does not exist!  This could arise
 * if sizeof(int)==8 and sizeof(short)==4.
 * What I have here is probably not actually used yet and seems most
 * unlikely to be a performance bottleneck even if it ever is! However
 * the code I write here does impose a concrete byte-ordering...
 */
        *((char *)p + o) = (char)v32;
        *((char *)p + o + 1) = (char)(v32 >> 8);
        break;
case 4:
/*
 * NOTE that I access the memory here as an array of 32-bit values and I
 * do not do anything to adjust for the order of bytes in the word, and I
 * do not concern myself with alignment. The effect of mixtures of 1, 2 and
 * 4 byte operations on native code space will be system dependent. But my
 * intent at present is that native code is always to be generated on the
 * machine on which it will run and that it will never be touched on other
 * machines so this lack of portability is not really an issue! What could
 * be a messier matter here is that the value x is
 */
        *(int32_t *)((char *)p + o) = (int32_t)v32;
        break;
    }
    native_pages_changed = 1;
    return onevalue(x);
}

Lisp_Object Lnativegetv(Lisp_Object nil, Lisp_Object v, Lisp_Object n)
{
    int32_t o;
    intptr_t p;
    CSL_IGNORE(nil);
    if (!consp(v) ||
        !is_fixnum(qcar(v)) ||
        !is_fixnum(qcdr(v)) ||
        (p = int_of_fixnum(qcar(v))) < 0 ||
        p > native_pages_count) return aerror1("native-getv", v);
    else if (!is_fixnum(n)) return aerror1("native-getv", n);
    o = int_of_fixnum(qcdr(v)) + int_of_fixnum(n);
    if (o < 0 || o >= CSL_PAGE_SIZE) return aerror1("native-getv", o);
    p = (intptr_t)native_pages[p];
    p = doubleword_align_up(p);
    o = *((char *)p + o);
    return onevalue(fixnum_of_int(o & 0xff));
}

Lisp_Object MS_CDECL Lnativegetvn(Lisp_Object nil, int nargs, ...)
{
    Lisp_Object v, n, w;
    int32_t o;
    intptr_t p;
    va_list a;
    argcheck(nargs, 3, "native-getv");
    va_start(a, nargs);
    v = va_arg(a, Lisp_Object);
    n = va_arg(a, Lisp_Object);
    w = va_arg(a, Lisp_Object);
    va_end(a);
    CSL_IGNORE(nil);
    if (!consp(v) ||
        !is_fixnum(qcar(v)) ||
        !is_fixnum(qcdr(v)) ||
        (p = int_of_fixnum(qcar(v))) < 0 ||
        p > native_pages_count) return aerror1("native-getv", v);
    else if (!is_fixnum(n)) return aerror1("native-getv", n);
    else if (!is_fixnum(w)) return aerror1("native-getv width", w);
    o = int_of_fixnum(qcdr(v)) + int_of_fixnum(n);
    if (o < 0 || o >= CSL_PAGE_SIZE) return aerror1("native-getv", o);
    p = (intptr_t)native_pages[p];
    p = doubleword_align_up(p);
    switch (int_of_fixnum(w))
    {
default:
        return aerror1("native-getv width", w);
case 1:
        o = *((char *)p + o);
        return onevalue(fixnum_of_int(o & 0xff));
case 2:
        o = ((*((char *)p + o + 1) & 0xff) << 8) +
             (*((char *)p + o) & 0xff);
        return onevalue(fixnum_of_int(o & 0xffff));
case 4:
        o = *(int32_t *)((char *)p + o);
        p = o & fix_mask;
        if (p==0 || p==fix_mask) return onevalue(fixnum_of_int(o & 0xff));
        else if ((o & 0x80000000) == 0)
        {   w = make_one_word_bignum(o);
            errexit();
            return onevalue(w);
        }
        else
        {   w = make_two_word_bignum(1, o & 0x7fffffff);
            errexit();
            return onevalue(w);
        }
    }
}

Lisp_Object MS_CDECL Lnative_type(Lisp_Object nil, int nargs, ...)
{
    CSL_IGNORE(nil);
    CSL_IGNORE(nargs);
/*
 * This mechanism is not being pursued at present...
 */
#define NATIVE_CODE_TAG 0
    return onevalue(fixnum_of_int(NATIVE_CODE_TAG));
}

/*
 * (native-address fn nargs) fetches the value from the relevent function cell
 * of the function and returns it represented as an integer. This gives
 * the current real absolute address of the code involved and is intended
 * to be useful while testing a native-mode compiler.
 */

Lisp_Object Lnative_address(Lisp_Object nil, Lisp_Object fn, Lisp_Object nargs)
{
    intptr_t n, n1;
    CSL_IGNORE(nil);
    if (!symbolp(fn)) return aerror1("native-address", fn);
    if (!is_fixnum(nargs)) return aerror1("native-address", nargs);
    n = int_of_fixnum(nargs);
    switch (n)
    {
case 1: n = ifn1(fn);
        break;
case 2: n = ifn2(fn);
        break;
default:n = ifnn(fn);
        break;
    }
    n1 = n & fix_mask;
/*
 * I could bother more about 64-bit machines here and pack up longer
 * addresses properly, but this function is really just a private debug
 * hack so I will not worry just yet.
 */
    if (n1 == 0 || n1 == fix_mask) return onevalue(fixnum_of_int(n));
    fn = make_one_word_bignum(n);
    errexit();
    return onevalue(fn);
}

/*
 * (native-address n) with one integer argument will return an integer that
 * is the current memory address of a CSL/CCL internal variable identified
 * by that integer. The association between integers and variables is as
 * per the file "externs.h" and the switch statement here. The case 0 gives
 * the address of NIL, while 1 gives the address of "stack".
 * An invalid or unrecognised integer leads to a result
 * of zero. This is intended solely for the use of a native-code compiler.
 * It may not then be necessary to provide access to ALL of these variables,
 * but at least to start with it seems easiest to be comprehensive.
 * Negative integers use values in the following table, which are functions
 * in CSL that might usefully be called directly. If the one argument is a
 * cons then it is expected to be a native code handle and the associated
 * real address is returned.
 */

void *useful_functions[] =
{
    (void *)cons,           /* -1, 0 */
    (void *)ncons,          /* -2, 1 */
    (void *)list2,          /* -3, 2 */
    (void *)list2star,      /* -4, 3 */
    (void *)acons,          /* -5, 4 */
    (void *)list3,          /* -6, 5 */
    (void *)plus2,          /* -7, 6 */
    (void *)difference2,    /* -8, 7 */
    (void *)add1,           /* -9, 8 */
    (void *)sub1,           /* -10, 9 */
    (void *)get,            /* -11, 10 */
    (void *)lognot,         /* -12, 11 */
    (void *)ash,            /* -13, 12 */
    (void *)quot2,          /* -14, 13 */
    (void *)Cremainder,     /* -15, 14 */
    (void *)times2,         /* -16, 15 */
    (void *)negate,         /* -17, 16 */
    (void *)rational,       /* -18, 17 */
    (void *)lessp2,         /* -19, 18 */
    (void *)lesseq2,        /* -20, 19 */
    (void *)greaterp2,      /* -21, 20 */
    (void *)geq2,           /* -22, 21 */
    (void *)zerop,          /* -23, 22 */
    (void *)reclaim,        /* -24, 23 */
    (void *)error,          /* -25, 24 */
    (void *)equal_fn,       /* -26, 25 */
    (void *)cl_equal_fn,    /* -27, 26 */
    (void *)aerror,         /* -28, 27 */
    (void *)integerp,       /* -29, 28 */
    (void *)apply           /* -30, 29 */
};

char *address_of_var(int n)
{
    char *p = NULL;
    Lisp_Object nil = C_nil;
    if (n == 0) p = (char *)nil;
    else if (n == 1) p = (char *)&stack;
    else
#ifdef NILSEG_EXTERNS
    switch (n)
    {
default:    p = 0;                              break;
case  12:   p = (char *)&byteflip;              break;
case  13:   p = (char *)&codefringe;            break;
case  14:   p = (char *)&codelimit;             break;
#ifdef COMMON
case  16:   p = (char *)&stacklimit;            break;
#else
case  15:   p = (char *)&stacklimit;            break;
#endif
case  18:   p = (char *)&fringe;                break;
case  19:   p = (char *)&heaplimit;             break;
case  20:   p = (char *)&vheaplimit;            break;
case  21:   p = (char *)&vfringe;               break;
case  22:   p = (char *)&miscflags;             break;
case  24:   p = (char *)&nwork;                 break;
case  25:   p = (char *)&exit_reason;           break;
case  26:   p = (char *)&exit_count;            break;
case  27:   p = (char *)&gensym_ser;            break;
case  28:   p = (char *)&print_precision;       break;
case  29:   p = (char *)&current_modulus;       break;
case  30:   p = (char *)&fastget_size;          break;
case  31:   p = (char *)&package_bits;          break;
case  52:   p = (char *)&current_package;       break;
case  53:   p = (char *)&B_reg;                 break;
case  54:   p = (char *)&codevec;               break;
case  55:   p = (char *)&litvec;                break;
case  56:   p = (char *)&exit_tag;              break;
case  57:   p = (char *)&exit_value;            break;
case  58:   p = (char *)&catch_tags;            break;
case  59:   p = (char *)&lisp_package;          break;
case  60:   p = (char *)&boffo;                 break;
case  61:   p = (char *)&charvec;               break;
case  62:   p = (char *)&sys_hash_table;        break;
case  63:   p = (char *)&help_index;            break;
case  64:   p = (char *)&gensym_base;           break;
case  65:   p = (char *)&err_table;             break;
case  66:   p = (char *)&supervisor;            break;
case  67:   p = (char *)&startfn;               break;
case  68:   p = (char *)&faslvec;               break;
case  69:   p = (char *)&tracedfn;              break;
case  70:   p = (char *)&prompt_thing;          break;
case  71:   p = (char *)&faslgensyms;           break;
case  72:   p = (char *)&cl_symbols;            break;
case  73:   p = (char *)&active_stream;         break;
case  80:   p = (char *)&append_symbol;         break;
case  81:   p = (char *)&applyhook;             break;
case  82:   p = (char *)&cfunarg;               break;
case  83:   p = (char *)&comma_at_symbol;       break;
case  84:   p = (char *)&comma_symbol;          break;
case  85:   p = (char *)&compiler_symbol;       break;
case  86:   p = (char *)&comp_symbol;           break;
case  87:   p = (char *)&cons_symbol;           break;
case  88:   p = (char *)&echo_symbol;           break;
case  89:   p = (char *)&emsg_star;             break;
case  90:   p = (char *)&evalhook;              break;
case  91:   p = (char *)&eval_symbol;           break;
case  92:   p = (char *)&expr_symbol;           break;
case  93:   p = (char *)&features_symbol;       break;
case  94:   p = (char *)&fexpr_symbol;          break;
case  95:   p = (char *)&funarg;                break;
case  96:   p = (char *)&function_symbol;       break;
case  97:   p = (char *)&lambda;                break;
case  98:   p = (char *)&lisp_true;             break;
case  99:   p = (char *)&lower_symbol;          break;
case 100:   p = (char *)&macroexpand_hook;      break;
case 101:   p = (char *)&macro_symbol;          break;
case 102:   p = (char *)&opt_key;               break;
case 103:   p = (char *)&prinl_symbol;          break;
case 104:   p = (char *)&progn_symbol;          break;
case 105:   p = (char *)&quote_symbol;          break;
case 106:   p = (char *)&raise_symbol;          break;
case 107:   p = (char *)&redef_msg;             break;
case 108:   p = (char *)&rest_key;              break;
case 109:   p = (char *)&savedef;               break;
case 110:   p = (char *)&string_char_sym;       break;
case 111:   p = (char *)&unset_var;             break;
case 112:   p = (char *)&work_symbol;           break;
case 113:   p = (char *)&lex_words;             break;
case 114:   p = (char *)&get_counts;            break;
case 115:   p = (char *)&fastget_names;         break;
case 116:   p = (char *)&input_libraries;       break;
case 117:   p = (char *)&output_library;        break;
case 118:   p = (char *)&current_file;          break;
case 119:   p = (char *)&break_function;        break;
case 120:   p = (char *)&lisp_work_stream;      break;
case 121:   p = (char *)&lisp_standard_output;  break;
case 122:   p = (char *)&lisp_standard_input;   break;
case 123:   p = (char *)&lisp_debug_io;         break;
case 124:   p = (char *)&lisp_error_output;     break;
case 125:   p = (char *)&lisp_query_io;         break;
case 126:   p = (char *)&lisp_terminal_io;      break;
case 127:   p = (char *)&lisp_trace_output;     break;
case 128:   p = (char *)&standard_output;       break;
case 129:   p = (char *)&standard_input;        break;
case 130:   p = (char *)&debug_io;              break;
case 131:   p = (char *)&error_output;          break;
case 132:   p = (char *)&query_io;              break;
case 133:   p = (char *)&terminal_io;           break;
case 134:   p = (char *)&trace_output;          break;
case 135:   p = (char *)&fasl_stream;           break;
case 136:   p = (char *)&native_code;           break;
#ifdef COMMON
case 140:   p = (char *)&keyword_package;       break;
case 141:   p = (char *)&all_packages;          break;
case 142:   p = (char *)&package_symbol;        break;
case 143:   p = (char *)&internal_symbol;       break;
case 144:   p = (char *)&external_symbol;       break;
case 145:   p = (char *)&inherited_symbol;      break;
case 146:   p = (char *)&key_key;               break;
case 147:   p = (char *)&allow_other_keys;      break;
case 148:   p = (char *)&aux_key;               break;
case 149:   p = (char *)&format_symbol;         break;
case 150:   p = (char *)&expand_def_symbol;     break;
case 151:   p = (char *)&allow_key_key;         break;
case 152:   p = (char *)&declare_symbol;        break;
case 153:   p = (char *)&special_symbol;        break;
#endif
    }
#else /* NILSEG_EXTERNS */
    if (n >= 160) switch (n)
    {
default:    p = 0;                              break;
case 160:   p = (char *)&user_base_0;           break;
case 161:   p = (char *)&user_base_1;           break;
case 162:   p = (char *)&user_base_2;           break;
case 163:   p = (char *)&user_base_3;           break;
case 164:   p = (char *)&user_base_4;           break;
case 165:   p = (char *)&user_base_5;           break;
case 166:   p = (char *)&user_base_6;           break;
case 167:   p = (char *)&user_base_7;           break;
case 168:   p = (char *)&user_base_8;           break;
case 169:   p = (char *)&user_base_9;           break;
    }
    else p = (char *)&(((int32_t *)nil)[n]);
#endif /* NILSEG_EXTERNS */
    return p;
}


Lisp_Object Lnative_address1(Lisp_Object nil, Lisp_Object x)
{
    int32_t n, n1;
    intptr_t p;
    if (consp(x))
    {   if (!is_fixnum(qcar(x)) ||
            !is_fixnum(qcdr(x)) ||
            (p = int_of_fixnum(qcar(x))) < 0 ||
            p > native_pages_count) return aerror1("native-address", x);
            n = int_of_fixnum(qcdr(x));
            if (n < 0 || n >= CSL_PAGE_SIZE) return aerror1("native-address", x);
        p = (intptr_t)native_pages[p];
        p = doubleword_align_up(p);
        p = (intptr_t)((char *)p + n);
    }
    else
    {   if (!is_fixnum(x)) return aerror1("native-address", x);
        n = int_of_fixnum(x);
        if (n < 0)
        {   n = (-n) - 1;
            if (n >= sizeof(useful_functions)/sizeof(void *))
                return aerror1("native-address", x);
            else p = (intptr_t)useful_functions[n];
        }
        else p = (intptr_t)address_of_var(n);
    }
    n1 = p & fix_mask;
    if (n1 == 0 || n1 == fix_mask) return onevalue(fixnum_of_int(p));
    x = make_one_word_bignum(p);
    errexit();
    return onevalue(x);
}


/*
 * Access functions for specialised (binary-contents) vectors. NOT integrated
 * in with the greater generality of vector structures.
 */

Lisp_Object MS_CDECL Lputv8(Lisp_Object nil, int nargs, ...)
{
    Header h;
    va_list a;
    intptr_t n1, hl;
    Lisp_Object v, n, x;
    argcheck(nargs, 3, "putv8");
    va_start(a, nargs);
    v = va_arg(a, Lisp_Object);
    n = va_arg(a, Lisp_Object);
    x = va_arg(a, Lisp_Object);
    va_end(a);
    CSL_IGNORE(nil);
    if (!is_vector(v) || type_of_header(h = vechdr(v)) != TYPE_VEC8)
        return aerror1("putv8", v);
    else if (!is_fixnum(n)) return aerror1("putv8 offset not fixnum", n);
    hl = length_of_header(h) - CELL;
    n1 = int_of_fixnum(n);
    if (n1 < 0 || n1 >= hl) return aerror1("putv8 index range", n);
    scelt(v, n1) = (char)int_of_fixnum(x);
    return onevalue(x);
}

Lisp_Object Lgetv8(Lisp_Object nil, Lisp_Object v, Lisp_Object n)
{
    Header h;
    intptr_t n1, hl;
    CSL_IGNORE(nil);
    if (!is_vector(v) || type_of_header(h = vechdr(v)) != TYPE_VEC8)
        return aerror1("getv8", v);
    else if (!is_fixnum(n)) return aerror1("getv8 offset not fixnum", n);
    hl = length_of_header(h) - CELL;
    n1 = int_of_fixnum(n);
    if (n1 < 0 || n1 >= hl) return aerror1("getv8 index range", n);
    else return onevalue(fixnum_of_int(scelt(v, n1)));
}

Lisp_Object MS_CDECL Lputv16(Lisp_Object nil, int nargs, ...)
{
    Header h;
    va_list a;
    intptr_t n1, hl;
    Lisp_Object v, n, x;
    argcheck(nargs, 3, "putv16");
    va_start(a, nargs);
    v = va_arg(a, Lisp_Object);
    n = va_arg(a, Lisp_Object);
    x = va_arg(a, Lisp_Object);
    va_end(a);
    CSL_IGNORE(nil);
    if (!is_vector(v) || type_of_header(h = vechdr(v)) != TYPE_VEC16)
        return aerror1("putv16", v);
    else if (!is_fixnum(n)) return aerror1("putv16 offset not fixnum", n);
    hl = (length_of_header(h) - CELL) >> 1;
    n1 = int_of_fixnum(n);
    if (n1 < 0 || n1 >= hl) return aerror1("putv16 index range", n);
    sethelt(v, n1, int_of_fixnum(x));
    return onevalue(x);
}

Lisp_Object Lgetv16(Lisp_Object nil, Lisp_Object v, Lisp_Object n)
{
    Header h;
    intptr_t n1, hl;
    CSL_IGNORE(nil);
    if (!is_vector(v) || type_of_header(h = vechdr(v)) != TYPE_VEC16)
        return aerror1("getv16", v);
    else if (!is_fixnum(n)) return aerror1("getv16 offset not fixnum", n);
    hl = (length_of_header(h) - CELL) >> 1;
    n1 = int_of_fixnum(n);
    if (n1 < 0 || n1 >= hl) return aerror1("getv16 index range", n);
    n1 = helt(v, n1);
    return onevalue(fixnum_of_int(n1));
}

Lisp_Object MS_CDECL Lputv32(Lisp_Object nil, int nargs, ...)
{
    Header h;
    va_list a;
    intptr_t n1, hl;
    Lisp_Object v, n, x;
    argcheck(nargs, 3, "putv32");
    va_start(a, nargs);
    v = va_arg(a, Lisp_Object);
    n = va_arg(a, Lisp_Object);
    x = va_arg(a, Lisp_Object);
    va_end(a);
    CSL_IGNORE(nil);
    if (!is_vector(v) || type_of_header(h = vechdr(v)) != TYPE_VEC32)
        return aerror1("putv32", v);
    else if (!is_fixnum(n)) return aerror1("putv32 offset not fixnum", n);
    hl = (length_of_header(h) - CELL)/4;
    n1 = int_of_fixnum(n);
    if (n1 < 0 || n1 >= hl) return aerror1("putv32 index range", n);
    ielt32(v, n1) = thirty_two_bits(x);
    return onevalue(x);
}

Lisp_Object Lgetv32(Lisp_Object nil, Lisp_Object v, Lisp_Object n)
{
    Header h;
    intptr_t n1, hl;
    CSL_IGNORE(nil);
    if (!is_vector(v) || type_of_header(h = vechdr(v)) != TYPE_VEC32)
        return aerror1("getv32", v);
    else if (!is_fixnum(n)) return aerror1("getv32 offset not fixnum", n);
    hl = (length_of_header(h) - CELL)/4;
    n1 = int_of_fixnum(n);
    if (n1 < 0 || n1 >= hl) return aerror1("getv32 index range", n);
    n1 = ielt32(v, n1);
    hl = n1 & fix_mask;
    if (hl == 0 || hl == fix_mask) return fixnum_of_int(n1);
    n = make_one_word_bignum(n1);
    errexit();
    return onevalue(n);
}

Lisp_Object MS_CDECL Lfputv32(Lisp_Object nil, int nargs, ...)
{
    Header h;
    va_list a;
    intptr_t n1, hl;
    Lisp_Object v, n, x;
    double d;
    argcheck(nargs, 3, "fputv32");
    va_start(a, nargs);
    v = va_arg(a, Lisp_Object);
    n = va_arg(a, Lisp_Object);
    x = va_arg(a, Lisp_Object);
    d = float_of_number(x);
    va_end(a);
    CSL_IGNORE(nil);
    if (!is_vector(v) || type_of_header(h = vechdr(v)) != TYPE_FLOAT32)
        return aerror1("fputv32", v);
    else if (!is_fixnum(n)) return aerror1("fputv32 offset not fixnum", n);
    hl = (length_of_header(h) - CELL)/4;
    n1 = int_of_fixnum(n);
    if (n1 < 0 || n1 >= hl) return aerror1("fputv32 index range", n);
    felt(v, n1) = (float)d;
    return onevalue(x);
}

Lisp_Object Lfgetv32(Lisp_Object nil, Lisp_Object v, Lisp_Object n)
{
    Header h;
    intptr_t n1, hl;
    CSL_IGNORE(nil);
    if (!is_vector(v) || type_of_header(h = vechdr(v)) != TYPE_FLOAT32)
        return aerror1("fgetv32", v);
    else if (!is_fixnum(n)) return aerror1("fgetv32 offset not fixnum", n);
    hl = (length_of_header(h) - CELL)/4;
    n1 = int_of_fixnum(n);
    if (n1 < 0 || n1 >= hl) return aerror1("fgetv32 index range", n);
#ifdef COMMON
    v = make_boxfloat((double)felt(v, n1), TYPE_SINGLE_FLOAT);
#else
    v = make_boxfloat((double)felt(v, n1), TYPE_DOUBLE_FLOAT);
#endif
    errexit();
    return onevalue(v);
}

Lisp_Object MS_CDECL Lfputv64(Lisp_Object nil, int nargs, ...)
{
    Header h;
    va_list a;
    intptr_t n1, hl;
    Lisp_Object v, n, x;
    double d;
    argcheck(nargs, 3, "fputv64");
    va_start(a, nargs);
    v = va_arg(a, Lisp_Object);
    n = va_arg(a, Lisp_Object);
    x = va_arg(a, Lisp_Object);
    d = float_of_number(x);
    va_end(a);
    CSL_IGNORE(nil);
    if (!is_vector(v) || type_of_header(h = vechdr(v)) != TYPE_FLOAT64)
        return aerror1("fputv64", v);
    else if (!is_fixnum(n)) return aerror1("fputv64 offset not fixnum", n);
/*
 * NB it is not a misprint - the first double ALWAYS starts 8 bytes in...
 */
    hl = (length_of_header(h) - 8)/8;
    n1 = int_of_fixnum(n);
    if (n1 < 0 || n1 >= hl) return aerror1("fputv64 index range", n);
    delt(v, n1) = d;
    return onevalue(x);
}

Lisp_Object Lfgetv64(Lisp_Object nil, Lisp_Object v, Lisp_Object n)
{
    Header h;
    intptr_t n1, hl;
    CSL_IGNORE(nil);
    if (!is_vector(v) || type_of_header(h = vechdr(v)) != TYPE_FLOAT64)
        return aerror1("fgetv64", v);
    else if (!is_fixnum(n)) return aerror1("fgetv64 offset not fixnum", n);
    hl = (length_of_header(h) - 8)/8;
    n1 = int_of_fixnum(n);
    if (n1 < 0 || n1 >= hl) return aerror1("fgetv64 index range", n);
    v = make_boxfloat(delt(v, n1), TYPE_DOUBLE_FLOAT);
    errexit();
    return onevalue(v);
}

/*
 * This is useful in Standard as well as Common Lisp
 *
 * (defun list-to-vector (old)
 *    (let* ((len (length old))
 *           (new (make-simple-vector len)))
 *       (dotimes (i len new) (putv new i (car old)) (setq old (cdr old)))))
 */

Lisp_Object Llist_to_vector(Lisp_Object nil, Lisp_Object a)
{
    Lisp_Object v;
    int32_t n = CELL;
/*
 * The general LENGTH function deals with vectors as well as lists, and
 * returns a Lisp integer result. So here I just write out a simple in-line
 * version.
 */
    for (v=a; consp(v); v = qcdr(v)) n += CELL;
    push(a);
    v = getvector(TAG_VECTOR, TYPE_SIMPLE_VEC, n);
    pop(a);
    errexit();
    for(n=0; consp(a); a = qcdr(a), n++) elt(v, n) = qcar(a);
    if (!SIXTY_FOUR_BIT && ((n & 1) == 0)) elt(v, n) = nil;  /* Padder word */
    return onevalue(v);
}


#ifdef COMMON
/*
 * (defun putvec (v n x)
 *    (cond
 *       ((simple-string-p v) (putv-char v n x))
 *       ((simple-bit-vector-p v) (putv-bit v n x))
 *       (t (putv v n x))))
 */

static Lisp_Object MS_CDECL Lputvec(Lisp_Object nil, int nargs, ...)
{
    Header h;
    va_list a;
    int32_t vx;
    intptr_t n1, hl;
    Lisp_Object v, n, x;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "putvec");
    va_start(a, nargs);
    v = va_arg(a, Lisp_Object);
    n = va_arg(a, Lisp_Object);
    x = va_arg(a, Lisp_Object);
    va_end(a);
/*
 * Oh joy - here I have to dispatch based on what sort of vector I have.
 */
    if (!is_vector(v)) return aerror1("putvec", v);
    else if (!is_fixnum(n)) return aerror1("putvec", n);
    h = vechdr(v);
    if (type_of_header(h) == TYPE_STRING)
    {   if (is_fixnum(x)) vx = int_of_fixnum(x);
        else if (is_char(x)) vx = code_of_char(x);
        else return aerror1("putvec on string, contents", x);
        hl = length_of_header(h) - CELL;
        n1 = int_of_fixnum(n);
        if (n1 < 0 || n1 >= hl) return aerror1("putvec", n);
        celt(v, n1) = (int)vx;
        return onevalue(x);
    }
    if (header_of_bitvector(h))
    {   int b;
        if (!is_fixnum(x)) return aerror1("putvec on bitvec, contents", x);
        x = int_of_fixnum(x) & 1;
        h = length_of_header(h) - CELL;
        n1 = int_of_fixnum(n);
        b = 1 << (n1 & 7);     /* Bit selector */
        n1 = n1 >> 3;          /* Byte selector */
/*
 * I am just a bit shoddy here - I only complain if an attempt is made to
 * access beyond the last active byte of a bitvector - I do not
 * do bound checking accurate to bit positions.
 */
        if (n1 < 0 || n1 >= (int32_t)h) return aerror1("putv-bit", n);
        if (x == 0) celt(v, n1) &= ~b;
        else        celt(v, n1) |= b;
        return onevalue(fixnum_of_int(x));
    }
    if (vector_holds_binary(h)) return aerror1("putvec", v);
    hl = (length_of_header(h) - CELL)/CELL;
    n1 = int_of_fixnum(n);
    if (n1 < 0 || n1 >= hl) return aerror1("putvec index range", n);
    elt(v, n1) = x;
    return onevalue(x);
}

/*
 * (defun aref (v n1 &rest r)
 *   (if (null r)
 *       (cond
 *          ((simple-vector-p v) (getv v n1))
 *          ((simple-string-p v) (schar v n1))
 *          ((simple-bit-vector-p v) (getv-bit v n1))
 *          ((structp v) (getv v n1))
 *          (t (general-aref v n1 r)))
 *       (general-aref v n1 r)))
 *
 * (defun general-aref (v n1 r)
 *    (when (not (arrayp v)) (error "aref ~s ~s" v (cons n1 r)))
 *    (do ((dd (cdr (getv v 1)) (cdr dd)))
 *        ((null r))
 *        (setq n1 (+ (* n1 (car dd)) (pop r))))
 ***** plus special magic to deal with segmented representations...
 *    (aref (getv v 2) (+ (getv v 3) n1)))
 */

Lisp_Object MS_CDECL Laref(Lisp_Object nil, int nargs, ...)
{
    Header h;
    Lisp_Object v, n, w;
    intptr_t hl, n1;
    int32_t b;
    va_list a;
    if (nargs == 0) return aerror("aref");
    va_start(a, nargs);
    v = va_arg(a, Lisp_Object);
    if (!is_vector(v))
    {   va_end(a);
        return aerror1("aref", v);
    }
    h = vechdr(v);
    if (nargs == 1) n = 0;  /* Funny case (aref v) legal if no dimensions! */
    else
    {   n = va_arg(a, Lisp_Object);  /* First subscript */
        if (!is_fixnum(n))
        {   va_end(a);
            return aerror1("aref", n);
        }
        if (nargs == 2)
        {   if (type_of_header(h) == TYPE_SIMPLE_VEC ||
                     type_of_header(h) == TYPE_STRUCTURE)
            {   va_end(a);
                hl = (length_of_header(h) - CELL)/CELL;
                n1 = int_of_fixnum(n);
                if (n1 < 0 || n1 >= hl) return aerror1("aref index range", n);
                else return onevalue(elt(v, n1));
            }
            else if (type_of_header(h) == TYPE_STRING)
            {   va_end(a);
                hl = length_of_header(h) - CELL;
                n1 = int_of_fixnum(n);
                if (n1 < 0 || n1 >= hl) return aerror1("aref index range", n);
                return onevalue(pack_char(0, 0, celt(v, n1)));
            }
            else if (header_of_bitvector(h))
            {   va_end(a);
                h = length_of_header(h) - CELL;
                n1 = int_of_fixnum(n);
                b = 1 << (n1 & 7);     /* Bit selector */
                n1 = n1 >> 3;          /* Byte selector */
                if (n1 < 0 || n1 >= (int32_t)h)
                    return aerror1("aref index range", n);
                if ((celt(v, n1) & b) == 0) return onevalue(fixnum_of_int(0));
                else return onevalue(fixnum_of_int(1));
            }
        }
    }
    if (type_of_header(h) != TYPE_ARRAY)
    {   va_end(a);
        return aerror1("aref", v);
    }
/*
 * Here I had better have a general array, and I will need to calculate the
 * real index location within it.
 */
    w = elt(v, 1);   /* The list of dimensions */
    if (w == nil && nargs == 1)
    {   va_end(a);
        return onevalue(elt(v, 2));
    }
    n1 = int_of_fixnum(n);
    w = qcdr(w);
    while (nargs > 2 && w != nil)
    {   n = va_arg(a, Lisp_Object);
        if (!is_fixnum(n))
        {   va_end(a);
            return aerror1("aref", n);
        }
        n1 = n1*int_of_fixnum(qcar(w)) + int_of_fixnum(n);
        nargs--;
        w = qcdr(w);
    }
    va_end(a);
    if (nargs > 2 || w != nil)
        return aerror("aref, wrong number of subscripts");
    n1 += int_of_fixnum(elt(v, 3));  /* displaced-index-offset */
    v = elt(v, 2);
/*
 * Now I have got the vector that this array is displaced to or
 * represented by. If it is in fact a structure (not a simple vector)
 * then it is a row of 8K sub-vectors, and at element zero it has the
 * nominal size of the big vector (as a Lisp integer)
 */
    h = vechdr(v);
    if (type_of_header(h) == TYPE_SIMPLE_VEC)
    {   hl = (length_of_header(h) - CELL)/CELL;
        if (n1 < 0 || n1 >= hl) return aerror("aref index range");
        else return onevalue(elt(v, n1));
    }
    else if (type_of_header(h) == TYPE_STRUCTURE)
    {   int32_t n2;
        hl = int_of_fixnum(elt(v, 0));
        if (n1 < 0 || n1 >= hl) return aerror("aref index range");
        n2 = n1 % 8192;
        n1 = n1 / 8192;
        return onevalue(elt(elt(v, n1+1), n2));
    }
    else if (type_of_header(h) == TYPE_STRING)
    {   hl = length_of_header(h) - CELL;
        if (n1 < 0 || n1 >= hl) return aerror("aref index range");
        return onevalue(pack_char(0, 0, celt(v, n1)));
    }
    else if (header_of_bitvector(h))
    {   h = length_of_header(h) - CELL;
        b = 1 << (n1 & 7);     /* Bit selector */
        n1 = n1 >> 3;          /* Byte selector */
        if (n1 < 0 || n1 >= (int32_t)h) return aerror("aref index range");
        if ((celt(v, n1) & b) == 0) return onevalue(fixnum_of_int(0));
        else return onevalue(fixnum_of_int(1));
    }
    return aerror("aref unknown type for vector representation");
}

static Lisp_Object Laref1(Lisp_Object nil, Lisp_Object a)
{
    return Laref(nil, 1, a);
}

Lisp_Object Laref2(Lisp_Object nil, Lisp_Object a, Lisp_Object b)
{
    return Laref(nil, 2, a, b);
}

Lisp_Object Lelt(Lisp_Object nil, Lisp_Object v, Lisp_Object n)
{
    Header h;
    Lisp_Object w;
    int32_t hl, n1, b;
    if (!is_fixnum(n) || ((int32_t)n) < 0) return aerror1("elt", n);
    n1 = int_of_fixnum(n);
    if (!is_vector(v))
    {   w = v;
        while (consp(w) && n1>0)
        {   n1--;
            w = qcdr(w);
        }
        if (!consp(w)) return aerror1("elt", v);
        return onevalue(qcar(w));
    }
    h = vechdr(v);
    if (type_of_header(h) == TYPE_SIMPLE_VEC ||
             type_of_header(h) == TYPE_STRUCTURE)
    {   hl = (length_of_header(h) - CELL)/CELL;
        if (n1 >= hl) return aerror1("elt index range", n);
        else return onevalue(elt(v, n1));
    }
    else if (type_of_header(h) == TYPE_STRING)
    {   hl = length_of_header(h) - CELL;
        if (n1 >= hl) return aerror1("elt index range", n);
        return onevalue(pack_char(0, 0, celt(v, n1)));
    }
    else if (header_of_bitvector(h))
    {   h = length_of_header(h) - CELL;
        b = 1 << (n1 & 7);     /* Bit selector */
        n1 = n1 >> 3;          /* Byte selector */
        if (n1 < 0 || n1 >= (int32_t)h)
            return aerror1("elt index range", n);
        if ((celt(v, n1) & b) == 0) return onevalue(fixnum_of_int(0));
        else return onevalue(fixnum_of_int(1));
    }
    if (type_of_header(h) != TYPE_ARRAY) return aerror1("elt", v);
    w = elt(v, 1);   /* The list of dimensions - must be 1 dim here */
    w = qcdr(w);
    if (w != nil) return aerror1("elt", v);
    n1 += int_of_fixnum(elt(v, 3));  /* displaced-index-offset */
    v = elt(v, 2);
    h = vechdr(v);
    if (type_of_header(h) == TYPE_SIMPLE_VEC)
    {   hl = (length_of_header(h) - CELL)/CELL;
        if (n1 >= hl) return aerror("elt index range");
        else return onevalue(elt(v, n1));
    }
    else if (type_of_header(h) == TYPE_STRUCTURE)
    {   int32_t n2;
        hl = int_of_fixnum(elt(v, 0));
        if (n1 >= hl) return aerror("elt index range");
        n2 = n1 % 8192;
        n1 = n1 / 8192;
        return onevalue(elt(elt(v, n1+1), n2));
    }
    else if (type_of_header(h) == TYPE_STRING)
    {   hl = length_of_header(h) - CELL;
        if (n1 >= hl) return aerror("elt index range");
        return onevalue(pack_char(0, 0, celt(v, n1)));
    }
    else if (header_of_bitvector(h))
    {   h = length_of_header(h) - CELL;
        b = 1 << (n1 & 7);     /* Bit selector */
        n1 = n1 >> 3;          /* Byte selector */
        if (n1 >= (int32_t)h) return aerror("elt index range");
        if ((celt(v, n1) & b) == 0) return onevalue(fixnum_of_int(0));
        else return onevalue(fixnum_of_int(1));
    }
    return aerror("elt unknown type for vector representation");
}

/*
 * (defun aset (v n1 x &rest r)
 *   (if (null r)
 *      (cond
 *         ((simple-vector-p v) (putv v n1 x))
 *         ((simple-string-p v) (putv-char v n1 x))
 *         ((simple-bit-vector-p v) (putv-bit v n1 x))
 *         ((structp v) (putv v n1 x))
 *         (t (general-aset v n1 x r)))
 *      (general-aset v n1 x r)))
 *
 * (defun general-aset (v n1 x r)
 *    (when (not (arrayp v)) (error "aref ~s ~s" v
 *                  (reverse (cdr (reverse (cons n1 (cons x r)))))))
 *    (setq r (cons x r))
 *    (do ((dd (cdr (getv v 1)) (cdr dd)))
 *        ((null (cdr r)))
 *        (setq n1 (+ (* n1 (car dd)) (pop r))))
 ***** plus special magic to deal with segmented representations...
 *    (aset (getv v 2) (+ (getv v 3) n1) (car r)))
 */

/*
 * Note that the code for ASET is really a mildly modified copy of that
 * for AREF.
 */

Lisp_Object MS_CDECL Laset(Lisp_Object nil, int nargs, ...)
{
    Header h;
    Lisp_Object v, n, w, x;
    int32_t hl, n1, b;
    va_list a;
    if (nargs < 2) return aerror("aset");
    va_start(a, nargs);
    v = va_arg(a, Lisp_Object);
    if (!is_vector(v))
    {   va_end(a);
        return aerror1("aset", v);
    }
    h = vechdr(v);
    if (nargs == 2) n = 0;  /* Funny case (aset v w) legal if no dimensions! */
    else
    {   n = va_arg(a, Lisp_Object);  /* First subscript */
        if (!is_fixnum(n))
        {   va_end(a);
            return aerror1("aset", n);
        }
        if (nargs == 3)
        {   if (type_of_header(h) == TYPE_SIMPLE_VEC ||
                     type_of_header(h) == TYPE_STRUCTURE)
            {   x = va_arg(a, Lisp_Object);
                va_end(a);
                hl = (length_of_header(h) - CELL)/CELL;
                n1 = int_of_fixnum(n);
                if (n1 < 0 || n1 >= hl) return aerror1("aset index range", n);
                elt(v, n1) = x;
                return onevalue(x);
            }
            else if (type_of_header(h) == TYPE_STRING)
            {   x = va_arg(a, Lisp_Object);
                va_end(a);
                hl = length_of_header(h) - CELL;
                n1 = int_of_fixnum(n);
                if (n1 < 0 || n1 >= hl) return aerror1("aset index range", n);
                if (is_fixnum(x)) b = int_of_fixnum(x);
                else if (is_char(x)) b = code_of_char(x);
                else return aerror1("aset needs char", x);
                celt(v, n1) = b;
                return onevalue(x);
            }
            else if (header_of_bitvector(h))
            {   x = va_arg(a, Lisp_Object);
                va_end(a);
                h = length_of_header(h) - CELL;
                n1 = int_of_fixnum(n);
                b = 1 << (n1 & 7);     /* Bit selector */
                n1 = n1 >> 3;          /* Byte selector */
                if (n1 < 0 || n1 >= (int32_t)h)
                    return aerror1("aset index range", n);
                if (!is_fixnum(x)) return aerror1("aset needs bit", x);
                if (int_of_fixnum(x) & 1) ucelt(v, n1) |= b;
                else ucelt(v, n1) &= ~b;
                return onevalue(x);
            }
        }
    }
    if (type_of_header(h) != TYPE_ARRAY)
    {   va_end(a);
        return aerror1("aset", v);
    }
/*
 * Here I had better have a general array, and I will need to calculate the
 * real index location within it.
 */
    w = elt(v, 1);   /* The list of dimensions */
    if (w == nil && nargs == 2)
    {   x = va_arg(a, Lisp_Object);
        va_end(a);
        elt(v, 2) = x;
        return onevalue(x);
    }
    n1 = int_of_fixnum(n);
    w = qcdr(w);
    while (nargs > 3 && w != nil)
    {   n = va_arg(a, Lisp_Object);
        if (!is_fixnum(n))
        {   va_end(a);
            return aerror1("aset", n);
        }
        n1 = n1*int_of_fixnum(qcar(w)) + int_of_fixnum(n);
        nargs--;
        w = qcdr(w);
    }
    x = va_arg(a, Lisp_Object);
    va_end(a);
    if (nargs > 3 || w != nil)
        return aerror("aset, wrong number of subscripts");
    n1 += int_of_fixnum(elt(v, 3)); /* displaced-index-offset */
    v = elt(v, 2);
    h = vechdr(v);
    if (type_of_header(h) == TYPE_SIMPLE_VEC)
    {   hl = (length_of_header(h) - CELL)/CELL;
        if (n1 < 0 || n1 >= hl) return aerror("aset index range");
        elt(v, n1) = x;
        return onevalue(x);
    }
    if (type_of_header(h) == TYPE_STRUCTURE)
    {   int32_t n2;
        hl = int_of_fixnum(elt(v, 0));
        if (n1 < 0 || n1 >= hl) return aerror("aset index range");
        n2 = n1 % 8192;
        n1 = n1 / 8192;
        elt(elt(v, n1+1), n2) = x;
        return onevalue(x);
    }
    else if (type_of_header(h) == TYPE_STRING)
    {   hl = length_of_header(h) - CELL;
        if (n1 < 0 || n1 >= hl) return aerror("aset index range");
        if (is_fixnum(x)) b = int_of_fixnum(x);
        else if (is_char(x)) b = code_of_char(x);
        else return aerror1("aset needs char", x);
        celt(v, n1) = b;
        return onevalue(x);
    }
    else if (header_of_bitvector(h))
    {   h = length_of_header(h) - CELL;
        b = 1 << (n1 & 7);     /* Bit selector */
        n1 = n1 >> 3;          /* Byte selector */
        if (n1 < 0 || n1 >= (int32_t)h) return aerror("aset index range");
        if (!is_fixnum(x)) return aerror1("aset needs bit", x);
        if (int_of_fixnum(x) & 1) ucelt(v, n1) |= b;
        else ucelt(v, n1) &= ~b;
        return onevalue(x);
    }
    return aerror("aset unknown type for vector representation");
}

static Lisp_Object Laset1(Lisp_Object nil, Lisp_Object a)
{
    return aerror("aset");
}

static Lisp_Object Laset2(Lisp_Object nil, Lisp_Object a, Lisp_Object b)
{
    return Laset(nil, 2, a, b);
}

static Lisp_Object MS_CDECL Lsetelt(Lisp_Object nil, int nargs, ...)
{
    Lisp_Object v, n, x;
    Header h;
    Lisp_Object w;
    int32_t hl, n1, b;
    va_list a;
    argcheck(nargs, 3, "setelt");
    va_start(a, nargs);
    v = va_arg(a, Lisp_Object);
    n = va_arg(a, Lisp_Object);
    x = va_arg(a, Lisp_Object);
    va_end(a);
    if (!is_fixnum(n) || ((int32_t)n) < 0) return aerror1("setelt", n);
    n1 = int_of_fixnum(n);
    if (!is_vector(v))
    {   w = v;
        while (consp(w) && n1>0)
        {   n1--;
            w = qcdr(w);
        }
        if (!consp(w)) return aerror1("setelt", v);
        qcar(w) = x;
        return onevalue(x);
    }
    h = vechdr(v);
    if (type_of_header(h) == TYPE_SIMPLE_VEC ||
             type_of_header(h) == TYPE_STRUCTURE)
    {   hl = (length_of_header(h) - CELL)/CELL;
        if (n1 >= hl) return aerror1("setelt index range", n);
        elt(v, n1) = x;
        return onevalue(x);
    }
    else if (type_of_header(h) == TYPE_STRING)
    {   int vx;
        hl = length_of_header(h) - CELL;
        if (n1 >= hl) return aerror1("setelt index range", n);
        if (is_fixnum(x)) vx = int_of_fixnum(x);
        else if (is_char(x)) vx = code_of_char(x);
        else return aerror1("setelt contents", x);
        celt(v, n1) = vx;
        return onevalue(x);
    }
    else if (header_of_bitvector(h))
    {   if (!is_fixnum(x)) return aerror1("setelt contents", x);
        x = int_of_fixnum(x) & 1;
        h = length_of_header(h) - CELL;
        b = 1 << (n1 & 7);     /* Bit selector */
        n1 = n1 >> 3;          /* Byte selector */
        if (n1 >= (int32_t)h)
            return aerror1("setelt index range", n);
        if (x == 0) celt(v, n1) &= ~b;
        else celt(v, n1) |= b;
        return onevalue(fixnum_of_int(x));
    }
    if (type_of_header(h) != TYPE_ARRAY) return aerror1("setelt", v);
    w = elt(v, 1);   /* The list of dimensions - must be 1 dim here */
    w = qcdr(w);
    if (w != nil) return aerror1("setelt", v);
    n1 += int_of_fixnum(elt(v, 3));  /* displaced-index-offset */
    v = elt(v, 2);
    h = vechdr(v);
    if (type_of_header(h) == TYPE_SIMPLE_VEC)
    {   hl = (length_of_header(h) - CELL)/CELL;
        if (n1 >= hl) return aerror("setelt index range");
        elt(v, n1) = x;
        return onevalue(x);
    }
    else if (type_of_header(h) == TYPE_STRUCTURE)
    {   int32_t n2;
        hl = int_of_fixnum(elt(v, 0));
        if (n1 >= hl) return aerror("setelt index range");
        n2 = n1 % 8192;
        n1 = n1 / 8192;
        elt(elt(v, n1+1), n2) = x;
        return onevalue(x);
    }
    else if (type_of_header(h) == TYPE_STRING)
    {   int vx;
        hl = length_of_header(h) - CELL;
        if (is_fixnum(x)) vx = int_of_fixnum(x);
        else if (is_char(x)) vx = code_of_char(x);
        else return aerror1("setelt contents", x);
        if (n1 >= hl) return aerror("setelt index range");
        celt(v, n1) = vx;
        return onevalue(x);
    }
    else if (header_of_bitvector(h))
    {   if (!is_fixnum(x)) return aerror1("setelt contents", x);
        x = int_of_fixnum(x) & 1;
        h = length_of_header(h) - CELL;
        b = 1 << (n1 & 7);     /* Bit selector */
        n1 = n1 >> 3;          /* Byte selector */
        if (n1 >= (int32_t)h) return aerror("setelt index range");
        if (x == 0) celt(v, n1) &= ~b;
        else celt(v, n1) |= b;
        return onevalue(fixnum_of_int(x));
    }
    return aerror("setelt unknown type for vector representation");
}

/*
 * (defun vectorp (x)
 *     (or (simple-vector-p x)
 *         (simple-string-p x)
 *         (simple-bit-vector-p x)
 *         (and (arrayp x) (length-one-p (svref x 1)))))
 */

Lisp_Object Lvectorp(Lisp_Object nil, Lisp_Object a)
{
    Header h;
    int32_t tt;
    if (!is_vector(a)) return onevalue(nil);
    h = vechdr(a);
    tt = type_of_header(h);
    if (tt == TYPE_SIMPLE_VEC ||
        tt == TYPE_STRING ||
        header_of_bitvector(h)) return onevalue(lisp_true);
    if (tt == TYPE_ARRAY)
    {   a = elt(a, 1);   /* List of dimensions */
        if (consp(a) && !consp(qcdr(a))) return onevalue(lisp_true);
    }
    return onevalue(nil);
}

/*
 * (defun char (s n)
 *    (cond
 *       ((simple-string-p s) (schar s n))
 *       (t (aref s n))))
 */

static Lisp_Object Lchar(Lisp_Object nil, Lisp_Object v, Lisp_Object n)
{
    Header h;
    if (!is_vector(v)) return aerror("char");
    h = vechdr(v);
    if (type_of_header(h) == TYPE_STRING)
    {   int32_t hl, n1;
        if (!is_fixnum(n)) return aerror1("char", n);
        hl = length_of_header(h) - CELL;
        n1 = int_of_fixnum(n);
        if (n1 < 0 || n1 >= hl) return aerror1("schar", n);
        return onevalue(pack_char(0, 0, celt(v, n1)));
    }
    return Laref(nil, 2, v, n);
}

/*
 * (defun charset (s n c)
 *    (cond
 *       ((simple-string-p s) (putv-char s n c))
 *       (t (aset s n c))))
 */

static Lisp_Object MS_CDECL Lcharset(Lisp_Object nil, int nargs, ...)
{
    Lisp_Object v, n, c;
    Header h;
    va_list a;
    argcheck(nargs, 3, "charset");
    va_start(a, nargs);
    v = va_arg(a, Lisp_Object);
    n = va_arg(a, Lisp_Object);
    c = va_arg(a, Lisp_Object);
    va_end(a);
    if (!is_vector(v)) return aerror1("charset", v);
    h = vechdr(v);
    if (!is_fixnum(n)) return aerror1("charset", n);
    if (type_of_header(h) == TYPE_STRING)
    {   int32_t hl, n1, vx;
        if (!is_fixnum(n)) return aerror1("charset", n);
        hl = length_of_header(h) - CELL;
        if (is_fixnum(c)) vx = int_of_fixnum(c);
        else if (is_char(c)) vx = code_of_char(c);
        else return aerror1("charset contents", c);
        n1 = int_of_fixnum(n);
        if (n1 < 0 || n1 >= hl) return aerror1("charset", n);
        celt(v, n1) = (int)vx;
        return onevalue(c);
    }
    return Laset(nil, 3, v, n, c);
}

/*
 * (defun make-string (len &key (initial-element #\ ))
 *    (let ((s (make-simple-string len)))
 *       (dotimes (i len) (charset s i initial-element))
 *       s))
 */

static Lisp_Object MS_CDECL Lmake_string(Lisp_Object nil, int nargs, ...)
{
    va_list a;
    Lisp_Object w, n, key, init;
    int32_t nn, z, blanks;
    argcheck(nargs, 3, "make-string");
    va_start(a, nargs);
    n = va_arg(a, Lisp_Object);
    key = va_arg(a, Lisp_Object);
    init = va_arg(a, Lisp_Object);
    va_end(a);
    if (!is_fixnum(n) || (int32_t)n<0) return aerror1("make-string", n);
    if (!is_char(init) && !is_fixnum(init))
        return aerror1("make-string", init);
    if (key != initial_element) return aerror1("make-string", key);
    nn = int_of_fixnum(n);
    w = getvector(TAG_VECTOR, TYPE_STRING, nn+CELL);
    errexit();
    z = (int32_t)doubleword_align_up(nn+CELL);
    if (is_char(init)) blanks = code_of_char(init);
    else blanks = int_of_fixnum(init);
    blanks = (blanks << 8) | blanks;
    blanks = (blanks << 16) | blanks;
    while (z > CELL)
    {   z -= 4;
        *(int32_t *)((char *)w - TAG_VECTOR + z) = blanks;
    }
    nn = nn + CELL;
    while ((nn & 7) != 0)
    {   *((char *)w - TAG_VECTOR + nn) = 0;
        nn++;
    }
    return onevalue(w);
}

static Lisp_Object Lmake_string1(Lisp_Object nil, Lisp_Object n)
{
    Lisp_Object w;
    int32_t nn, z, blanks;
    if (!is_fixnum(n) || (int32_t)n<0) return aerror1("make-string", n);
    nn = int_of_fixnum(n);
    w = getvector(TAG_VECTOR, TYPE_STRING, nn+CELL);
    errexit();
    z = (int32_t)doubleword_align_up(nn+CELL);
    blanks = (' ' << 24) | (' ' << 16) | (' ' << 8) | ' ';
    while (z > CELL)
    {   z -= 4;
        *(int32_t *)((char *)w - TAG_VECTOR + z) = blanks;
    }
    nn = nn + CELL;
    while ((nn & 7) != 0)
    {   *((char *)w - TAG_VECTOR + nn) = 0;
        nn++;
    }
    return onevalue(w);
}

static Lisp_Object Lmake_string2(Lisp_Object nil, Lisp_Object a, Lisp_Object b)
{
    return Lmake_string(nil, 2, a, b);
}

/*
 * (defun string (x)
 *    (cond
 *       ((stringp x) x)
 *       ((symbolp x) (symbol-name x))
 *       ((string-char-p x) (make-string 1 :initial-element x))
 *       (t (error "String expected, but found ~S" x))))
 */

static Lisp_Object Lstring(Lisp_Object nil, Lisp_Object a)
{
    Header h;
    Lisp_Object w;
    if (!is_vector(a))
    {   char dd[4];
        if (symbolp(a)) return onevalue(qpname(a));
        if (!is_char(a)) return aerror1("string", a);
        dd[0] = 'x'; /* Done this way in case character arg has code 0 */
        dd[1] = 0;
        w = make_string(dd);
        errexit();
        celt(w, 0) = code_of_char(a);
        return onevalue(w);
    }
    h = vechdr(a);
    if (type_of_header(h) == TYPE_STRING) return onevalue(a);
    else if (type_of_header(h) != TYPE_ARRAY) return aerror1("string", a);
/*
 * Beware abolition of 'string-char
 */
    else if (elt(a, 0) != string_char_sym) return aerror1("string", a);
    w = elt(a, 1);
    if (!consp(w) || consp(qcdr(w))) return aerror1("string", a);
    else return onevalue(a);
}

/*
 * (defun copy-vector (old)
 * ;; At present this only copies general vectors...
 *    (let* ((len (vector-bound old))
 *           (new (make-simple-vector len)))
 *       (dotimes (i len new) (putv new i (svref old i)))))
 */

static Lisp_Object Lcopy_vector(Lisp_Object nil, Lisp_Object a)
{
    /* not done yet! */
    return onevalue(nil);
}


/*
 * (defun vector (&rest args)
 * ;; Note that a vector made this way can have at most 50 elements...
 *    (let* ((l (length args))
 *           (g (make-simple-vector l)))
 *       (dotimes (i l g)
 *           (putv g i (car args))
 *           (setq args (cdr args)))))
 */

static Lisp_Object MS_CDECL Lvector(Lisp_Object nil, int nargs, ...)
{
    Lisp_Object r = nil, w;
    va_list a;
    va_start(a, nargs);
    push_args(a, nargs);
    r = getvector(TAG_VECTOR, TYPE_SIMPLE_VEC, CELL*nargs+CELL);
    errexitn(nargs);
/*
 * The next line allows for the fact that vectors MUST pad to an even
 * number of words.
 */
    if (!SIXTY_FOUR_BIT && ((nargs & 1) == 0)) elt(r, nargs) = nil;
    while (nargs > 0)
    {   pop(w);
        elt(r, --nargs) = w;
    }
    return onevalue(r);
}

static Lisp_Object Lvector1(Lisp_Object nil, Lisp_Object a)
{
    return Lvector(nil, 1, a);
}

static Lisp_Object Lvector2(Lisp_Object nil, Lisp_Object a, Lisp_Object b)
{
    return Lvector(nil, 2, a, b);
}


static Lisp_Object Lshrink_vector(Lisp_Object nil,
                                  Lisp_Object v, Lisp_Object n)
{
    int32_t n1, n2;
    if (!is_vector(v)) return aerror1("shrink-vector", v);
    if (!is_fixnum(n)) return aerror1("shrink-vector", n);
    n1 = length_of_header(vechdr(v));
    n2 = CELL*int_of_fixnum(n)+CELL;
    if (n2 >= n1) return onevalue(v);  /* Not shrunk at all */
    if (!SIXTY_FOUR_BIT && (n1==n2+4) && ((n2&4)==0))   /* No space to free */
        *(Lisp_Object *)((char *)v-TAG_VECTOR+n2) = nil;
    else
    {   int32_t n2a = doubleword_align_up(n2);
        n1 = doubleword_align_up(n1);
        *(Lisp_Object *)((char *)v-TAG_VECTOR+n1) =
            TAG_ODDS+TYPE_STRING+((n1-n2a)<<10);
    }
    vechdr(v) = TAG_ODDS+type_of_header(vechdr(v))+(n2<<10);
    return onevalue(v);
}

static Lisp_Object Lmake_simple_bitvector(Lisp_Object nil, Lisp_Object n)
{
    int32_t bytes;
    Lisp_Object w;
    int32_t n1;
    if (!is_fixnum(n) || (int32_t)n<0)
        return aerror1("make-simple-bitvector", n);
    n1 = int_of_fixnum(n);
    bytes = CELL+(n1+7)/8;
#define bitvechdr_(n) (TYPE_BITVEC1 + ((((n)+7)&7)<<7))
    w = getvector(TAG_VECTOR, bitvechdr_(n1), bytes);
    errexit();
    n1 = doubleword_align_up(bytes);
    while (n1 > CELL)
    {   n1 -= 4;
        *(int32_t *)((char *)w - TAG_VECTOR + n1) = 0;
    }
    return onevalue(w);
}

static Lisp_Object MS_CDECL Lbputv(Lisp_Object nil, int nargs, ...)
{
    Header h;
    va_list a;
    int b;
    int32_t n1;
    Lisp_Object v, n, x;
    argcheck(nargs, 3, "bputv");
    va_start(a, nargs);
    v = va_arg(a, Lisp_Object);
    n = va_arg(a, Lisp_Object);
    x = va_arg(a, Lisp_Object);
    va_end(a);
    CSL_IGNORE(nil);
/*
 * This code is WRONG at present in that unexpectedly it is supposed to
 * support bit-arrays of arbitrary rank, and not just simple vectors.
 */
    if (!(is_vector(v)) || !header_of_bitvector(h = vechdr(v)))
        return aerror1("putv-bit", v);
    if (!is_fixnum(n)) return aerror1("putv-bit", n);
    if (!is_fixnum(x)) return aerror1("putv-bit contents", x);
    x = int_of_fixnum(x) & 1;
    h = length_of_header(h) - CELL;
    n1 = int_of_fixnum(n);
    b = 1 << (n1 & 7);     /* Bit selector */
    n1 = n1 >> 3;          /* Byte selector */
/*
 * I am just a bit shoddy here - I only complain if an attempt is made to
 * access beyond the last active byte of a bitvector - I do not
 * do bound checking accurate to bit positions.
 */
    if (n1 < 0 || n1 >= (int32_t)h) return aerror1("putv-bit", n);
    if (x == 0) ucelt(v, n1) &= ~b;
    else        ucelt(v, n1) |= b;
    return onevalue(fixnum_of_int(x));
}

static Lisp_Object Lbgetv(Lisp_Object nil, Lisp_Object v, Lisp_Object n)
{
    Header h;
    int b;
    int32_t n1;
    CSL_IGNORE(nil);
/*
 * This code is WRONG at present in that unexpectedly it is supposed to
 * support bit-arrays of arbitrary rank, and not just simple vectors.
 */
    if (!(is_vector(v)) || !header_of_bitvector(h = vechdr(v)))
        return aerror1("getv-bit", v);
    if (!is_fixnum(n)) return aerror1("getv-bit", n);
    h = length_of_header(h) - CELL;
    n1 = int_of_fixnum(n);
    b = 1 << (n1 & 7);     /* Bit selector */
    n1 = n1 >> 3;          /* Byte selector */
    if (n1 < 0 || n1 >= (int32_t)h) return aerror1("getv-bit", n);
    if ((ucelt(v, n1) & b) == 0)
        return onevalue(fixnum_of_int(0));
    else return onevalue(fixnum_of_int(1));
}

#endif /* COMMON */

Lisp_Object Lupbv(Lisp_Object nil, Lisp_Object v)
{
    Header h;
    int32_t n;
    CSL_IGNORE(nil);
/*
 * in non segmented mode this will support BPS, but really
 * you ought not to rely on that.
 */
    if (!(is_vector(v))) return onevalue(nil); /* Standard Lisp demands.. */
    h = vechdr(v);
    n = length_of_header(h) - CELL;
#ifdef COMMON
    if (header_of_bitvector(h))
    {   n = (n - 1)*8;
        n += ((h & 0x380) >> 7) + 1;
    }
    else
#endif
        switch (type_of_header(h))
        {
    case TYPE_STRING:
    case TYPE_VEC8:
            break;
    case TYPE_VEC16:
            n = n/2;
            break;
    case TYPE_VEC32:
            n = n/4;
            break;
    case TYPE_FLOAT64:
            n = n/8;
            break;
    default:
            n = n/CELL;
            break;
        }
    n--;    /* c.f. mkvect */
    return onevalue(fixnum_of_int(n));
}

#ifdef COMMON
Lisp_Object Lvecbnd(Lisp_Object nil, Lisp_Object v)
{
    Header h;
    int32_t n;
    CSL_IGNORE(nil);
/*
 * in non segmented mode this will support BPS, but really
 * you ought not to rely on that.
 */
    if (!(is_vector(v))) return aerror1("vector-bound", v);
    h = vechdr(v);
    n = length_of_header(h) - CELL;
    if (header_of_bitvector(h))
    {   n = (n - 1)*8;
        n += ((h & 0x380) >> 7) + 1;
    }
    else switch (type_of_header(h))
    {
case TYPE_STRING:
case TYPE_VEC8:
        break;
case TYPE_VEC16:
        n = n/2;
        break;
case TYPE_VEC32:
        n = n/4;
        break;
case TYPE_FLOAT64:
        n = n/8;
        break;
default:
        n = n/CELL;
        break;
    }
    return onevalue(fixnum_of_int(n));
}
#endif

#ifdef COMMON

/*
 * The following were added for efficiency reasons, MCD 14/8/96
 */

Lisp_Object list_subseq(Lisp_Object sequence, int32_t start, int32_t end)
{
    Lisp_Object nil=C_nil, copy, last, new, seq=sequence;
    int32_t seq_length, pntr = start;

    seq_length = end - start;

/* Find start of subsequence */
    while (consp(seq) && pntr > 0)
    {   pntr--;
        seq = qcdr(seq);
    }
    if (!consp(seq)) return aerror1("subseq",sequence);

    copy = nil;

/* Store the values */
    push(sequence);
    while (consp(seq) && pntr < seq_length)
    {   push3(seq,copy,last);
        new = Lcons(nil,qcar(seq),nil);
        pop3(last,copy,seq);
        if (pntr == 0) copy = new;
        else qcdr(last) = new;
        last = new;
        seq = qcdr(seq);
        pntr++;
    }
    pop(sequence);
    errexit();
    if (pntr != seq_length) return aerror1("subseq",sequence);

    return onevalue(copy);
}

Lisp_Object vector_subseq(Lisp_Object sequence, int32_t start, int32_t end)
{
  Lisp_Object nil=C_nil, copy;
  Header h;
  int32_t hl, seq_length, i;

  if (is_cons(sequence)) 
    return list_subseq(sequence,start,end);
  else if (!is_vector(sequence))
    return aerror1("vector-subseq*",sequence);

  seq_length = end - start;

  h = vechdr(sequence);

  if (type_of_header(h) == TYPE_SIMPLE_VEC ) {
    hl = (length_of_header(h) - CELL)/CELL;
    if (hl < end) return aerror0("vector-subseq* out of range");

    /* 
     * Since we are dealing with a simple vector the following shift is
     * guarenteed to work.  The extra CELL bytes are for the header.
     */
    copy = getvector_init(CELL+seq_length*CELL,nil); 
    for (i=start; i < end; ++i) elt(copy,i-start) = elt(sequence,i);

    return onevalue(copy);
  }
  else if (type_of_header(h) == TYPE_STRING) {
    char *s;
    int32_t k;

    hl = length_of_header(h) - CELL;
    if (hl < end) return aerror0("vector-subseq* out of range");

    /* Get a new string of the right size */
    push(sequence);
    copy = getvector(TAG_VECTOR, TYPE_STRING, CELL+seq_length);
    pop(sequence);

    /* This code plagiarised from copy_string ... */
    s = (char *)copy - TAG_VECTOR;
    k = (seq_length + 3) & ~(int32_t)7;
    errexit();
    *(int32_t *)(s + k + CELL) = 0;
    if (k != 0) *(int32_t *)(s + k) = 0;

    memcpy(s + CELL, (char *)sequence+(CELL-TAG_VECTOR)+start, (size_t)seq_length);

    return onevalue(copy);
  }
  else if (header_of_bitvector(h)) {
    hl = length_of_header(h) - CELL;
    if (hl < end/8) return aerror0("vector-subseq* out of range");

    /* Grab a bit-vector of the right size */
    push(sequence);
    copy = Lmake_simple_bitvector(nil,fixnum_of_int(seq_length));
    pop(sequence);
    errexit();

    /*
     * This is not terribly efficient since the calls to Lbputv and Lbgetv
     * ought to be coded inline, but on the other hand its no worse than the
     * original Lisp-coded version.
     */
    for (i=start; i<end; ++i) {
      push2(sequence,copy);
      Lbputv(nil,3,copy,fixnum_of_int(i-start),
             Lbgetv(nil,sequence,fixnum_of_int(i)));
      pop2(copy,sequence);
      errexit();
    }

    return onevalue(copy);
  }
  else if (type_of_header(h) == TYPE_ARRAY) {
    /* elt(sequence, 1) is the list of dimensions - only handle 1-d case */
    if (qcdr(elt(sequence, 1)) != nil)
      return aerror1("vector-subseq*",sequence);
    i = int_of_fixnum(elt(sequence, 3));  /* displaced-index-offset */
    return vector_subseq(elt(sequence,2),start+i,end+i);
  }
  else
    return aerror1("vector-subseq*",sequence);
}

Lisp_Object Llist_subseq1(Lisp_Object nil, Lisp_Object seq, Lisp_Object start)
{
  Lisp_Object len;
  int32_t first, last;

  first = int_of_fixnum(start);
  push(seq);
  len = Llength(nil,seq);
  pop(seq);
  errexit();
/*
 */* For super-long sequences the length may not be a fixnum!
 */
  last = int_of_fixnum(len);

  if (first > last) return aerror1("list-subseq* out of range",seq);

  return list_subseq(seq, first, last);
}

Lisp_Object MS_CDECL Llist_subseq2(Lisp_Object nil, int32_t nargs, ...)
{
  va_list args;
  int32_t first, last;
  Lisp_Object seq, start, end;
  argcheck(nargs, 3, "list-subseq*");
  va_start(args, nargs);
  seq   = va_arg(args, Lisp_Object);
  start = va_arg(args, Lisp_Object);
  end   = va_arg(args, Lisp_Object);
  va_end(args);

  first = int_of_fixnum(start);
  last  = int_of_fixnum(end);
  if (first > last) return aerror1("list-subseq* out of range",seq);

  return list_subseq(seq, first, last);
}

Lisp_Object Lvector_subseq1(Lisp_Object nil, Lisp_Object seq, Lisp_Object start)
{
  Lisp_Object len;
  int32_t first, last;

  first = int_of_fixnum(start);
  push(seq);
  len = Llength(nil,seq);
  pop(seq);
  errexit();

/*
 * For super-long list sequences the length may not be a fixnum, but
 * for vectors I should be safe.
 */
  last = int_of_fixnum(len);

  if (first > last) return aerror1("vector-subseq* out of range",seq);

  return vector_subseq(seq, first, last);
}

Lisp_Object MS_CDECL Lvector_subseq2(Lisp_Object nil, int32_t nargs, ...)
{
  va_list args;
  int32_t first, last;
  Lisp_Object seq, start, end;
  argcheck(nargs, 3, "vector-subseq*");
  va_start(args, nargs);
  seq   = va_arg(args, Lisp_Object);
  start = va_arg(args, Lisp_Object);
  end   = va_arg(args, Lisp_Object);
  va_end(args);

  first = int_of_fixnum(start);
  last  = int_of_fixnum(end);
  if (first > last) return aerror1("vector-subseq* out of range",seq);

  return vector_subseq(seq, first, last);
}

#else
/*
 * This definition is so that exports and imports can be the same in
 * both COMMON and regular cases.
 */
Lisp_Object Lvectorp(Lisp_Object nil, Lisp_Object a)
{
    return Lsimple_vectorp(nil, a);
}

#endif

setup_type const funcs3_setup[] =
{
    {"getv",                    too_few_2, Lgetv, wrong_no_2},
    {"putv",                    wrong_no_3a, wrong_no_3b, Lputv},
    {"getv8",                   too_few_2, Lgetv8, wrong_no_2},
    {"putv8",                   wrong_no_3a, wrong_no_3b, Lputv8},
    {"getv16",                  too_few_2, Lgetv16, wrong_no_2},
    {"putv16",                  wrong_no_3a, wrong_no_3b, Lputv16},
    {"getv32",                  too_few_2, Lgetv32, wrong_no_2},
    {"putv32",                  wrong_no_3a, wrong_no_3b, Lputv32},
    {"fgetv32",                 too_few_2, Lfgetv32, wrong_no_2},
    {"fputv32",                 wrong_no_3a, wrong_no_3b, Lfputv32},
    {"fgetv64",                 too_few_2, Lfgetv64, wrong_no_2},
    {"fputv64",                 wrong_no_3a, wrong_no_3b, Lfputv64},
    {"qgetv",                   too_few_2, Lgetv, wrong_no_2},
    {"egetv",                   too_few_2, Lgetv, wrong_no_2},
    {"qputv",                   wrong_no_3a, wrong_no_3b, Lputv},
    {"eputv",                   wrong_no_3a, wrong_no_3b, Lputv},
    {"make-simple-string",      Lsmkvect, too_many_1, wrong_no_1},
    {"putv-char",               wrong_no_3a, wrong_no_3b, Lsputv},
    {"bps-putv",                wrong_no_3a, wrong_no_3b, Lbpsputv},
    {"bps-getv",                too_few_2, Lbpsgetv, wrong_no_2},
    {"bps-upbv",                Lbpsupbv, too_many_1, wrong_no_1},
    {"native-type",             wrong_no_na, wrong_no_nb, Lnative_type},
    {"native-putv",             wrong_no_3a, wrong_no_3b, Lnativeputv},
    {"native-getv",             too_few_2, Lnativegetv, Lnativegetvn},
    {"native-address",          Lnative_address1, Lnative_address, wrong_no_2},
    {"eupbv",                   Lupbv, too_many_1, wrong_no_1},
    {"schar",                   too_few_2, Lsgetv, wrong_no_2},
    {"scharn",                  too_few_2, Lsgetvn, wrong_no_2},
    {"byte-getv",               too_few_2, Lbytegetv, wrong_no_2},
    {"mkvect",                  Lmkvect, too_many_1, wrong_no_1},
    {"mkevect",                 Lmkevect, too_many_1, wrong_no_1},
    {"mkxvect",                 Lmkxvect, too_many_1, wrong_no_1},
    {"mkvect8",                 Lmkvect8, too_many_1, wrong_no_1},
    {"mkvect16",                Lmkvect16, too_many_1, wrong_no_1},
    {"mkvect32",                Lmkvect32, too_many_1, wrong_no_1},
    {"mkfvect32",               Lmkfvect32, too_many_1, wrong_no_1},
    {"mkfvect64",               Lmkfvect64, too_many_1, wrong_no_1},
    {"mkhash",                  wrong_no_3a, wrong_no_3b, Lmkhash},
    {"gethash",                 Lget_hash_1, Lget_hash_2, Lget_hash},
    {"puthash",                 wrong_no_3a, Lput_hash_2, Lput_hash},
    {"remhash",                 Lrem_hash_1, Lrem_hash, wrong_no_2},
    {"clrhash",                 Lclr_hash, too_many_1, Lclr_hash_0},
    {"sxhash",                  Lsxhash, too_many_1, wrong_no_1},
    {"eqlhash",                 Leqlhash, too_many_1, wrong_no_1},
    {"maphash",                 too_few_2, Lmaphash, wrong_no_2},
    {"hashcontents",            Lhashcontents, too_many_1, wrong_no_1},
    {"upbv",                    Lupbv, too_many_1, wrong_no_1},
#ifdef COMMON
    {"hashtable-flavour",       Lhash_flavour, too_many_1, wrong_no_1},
    {"getv-bit",                too_few_2, Lbgetv, wrong_no_2},
    {"sbit",                    too_few_2, Lbgetv, wrong_no_2},
    {"make-simple-bitvector",   Lmake_simple_bitvector, too_many_1, wrong_no_1},
    {"make-simple-vector",      Lmksimplevec, too_many_1, wrong_no_1},
    {"putv-bit",                wrong_no_3a, wrong_no_3b, Lbputv},
    {"sbitset",                 wrong_no_3a, wrong_no_3b, Lbputv},
    {"svref",                   too_few_2, Lgetv, wrong_no_2},
    {"vector-bound",            Lvecbnd, too_many_1, wrong_no_1},
    {"putvec",                  wrong_no_3a, wrong_no_3b, Lputvec},
    {"aref",                    Laref1, Laref2, Laref},
    {"aset",                    Laset1, Laset2, Laset},
    {"elt",                     too_few_2, Lelt, wrong_no_2},
    {"setelt",                  wrong_no_3a, wrong_no_3b, Lsetelt},
    {"vectorp",                 Lvectorp, too_many_1, wrong_no_1},
    {"char",                    too_few_2, Lchar, wrong_no_2},
    {"charset",                 wrong_no_3a, wrong_no_3b, Lcharset},
    {"make-string",             Lmake_string1, Lmake_string2, Lmake_string},
    {"vector",                  Lvector1, Lvector2, Lvector},
    {"shrink-vector",           too_few_2, Lshrink_vector, wrong_no_2},
    {"string",                  Lstring, too_many_1, wrong_no_1},
    {"vector-subseq*",          wrong_no_3a, Lvector_subseq1, Lvector_subseq2},
    {"list-subseq*",            wrong_no_3a, Llist_subseq1, Llist_subseq2},
    {"subseq",                  wrong_no_3a, Lvector_subseq1, Lvector_subseq2},
/* The "x" is temporary while I debug */
    {"xcopy-vector",             Lcopy_vector, too_many_1, wrong_no_1},
#endif
    {"list-to-vector",          Llist_to_vector, too_many_1, wrong_no_1},
    {"encapsulatedp",           Lencapsulatedp, too_many_1, wrong_no_1},
    {"maple_atomic_value",      Lmaple_atomic_value, too_many_1, wrong_no_1},
    {"maple_tag",               Lmaple_tag, too_many_1, wrong_no_1},
    {"maple_length",            Lmaple_length, too_many_1, wrong_no_1},
    {"maple_string_data",       Lmaple_string_data, too_many_1, wrong_no_1},
    {"maple_integer",           Lmaple_integer, too_many_1, wrong_no_1},
    {"maple_component",         too_few_2, Lmaple_component, wrong_no_2}, 
    {NULL,                      0, 0, 0}
};

/* end of fns3.c */

