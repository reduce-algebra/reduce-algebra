// fns3.cpp                                Copyright (C) 1989-2016 Codemist

//
// Basic functions part 3.
// A concentration on vector and array access code here.
//

/**************************************************************************
 * Copyright (C) 2016, Codemist.                         A C Norman       *
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
// Common Lisp and Standard Lisp disagree about vector sizes.  Common
// Lisp counts the number of elements in a vector (with make-simple-vector
// and vector-bound) while Standard Lisp uses the value n, where the
// vector concerned will accept index values from 0 to n (inclusive)
// (mkvect and upbv).  I provide the Standard Lisp versions always, so I
// can use them even in Common Lisp mode.  The vectors are exactly the
// same - it is just a different way of talking about them.
//

LispObject Lmkvect(LispObject env, LispObject n)
{   int32_t n1;
    if (!is_fixnum(n)) return aerror1("mkvect", n);
    n1 = int_of_fixnum(n)*CELL;
    n1 += CELL; // Oh! What an abomination! Standard Lisp allocated 0::n,
                // Common allocates n items
// Note that this allows the user to go (mkvect -1) to make a vector with
// no elements at all. This is mildly odd! But it is a consequence of agreeing
// that (mkvect 0) will make a vector of length 1.
    if (n1 < 0) return aerror1("mkvect", n);
    return onevalue(getvector_init(n1+CELL, nil));
}

#ifdef COMMON
LispObject Lmksimplevec(LispObject env, LispObject n)
{   int32_t n1;
    if (!is_fixnum(n)) return aerror1("make-simple-vector", n);
    n1 = int_of_fixnum(n)*CELL;
    if (n1 < 0) return aerror1("make-simple-vector", n);
    return onevalue(getvector_init(n1+CELL, nil));
}
#endif

//
// This one creates a "structure" tagged vector.
//

LispObject Lmkevect(LispObject env, LispObject n)
{   int32_t n1;
    if (!is_fixnum(n)) return aerror1("mkevect", n);
    n1 = int_of_fixnum(n)*CELL;
#ifndef COMMON
    n1 += CELL; // Oh! What an abomination! Standard Lisp allocated 0::n,
    // Common allocates n items
#endif
    if (n1 < 0) return aerror1("mkevect", n);
    n = getvector_init(n1+CELL, nil);
    errexit();
    vechdr(n) ^= (TYPE_SIMPLE_VEC ^ TYPE_STRUCTURE);
    return onevalue(n);
}

//
// The following creates a sort of vector where the first 3 items are
// lisp pointers, and the remainder may be filled with binary stuff (which
// is not byte-flipped or anything on garbage collection, and so is possibly
// fairly unsafe). It is intended for internal or experimental use only.
//

LispObject Lmkxvect(LispObject env, LispObject n)
{   size_t n1;
    if (!is_fixnum(n)) return aerror1("mkxvect", n);
    n1 = int_of_fixnum(n)*CELL;
#ifndef COMMON
    n1 += CELL; // Oh! What an abomination! Standard Lisp allocated 0::n,
    // Common allocates n items
#endif
    if (n1 < 3*CELL) return aerror1("mkxvect", n);
    n = getvector_init(n1+CELL, nil);
    errexit();
    vechdr(n) ^= (TYPE_SIMPLE_VEC ^ TYPE_MIXED1);
    return onevalue(n);
}

LispObject encapsulate_pointer(void *data)
//
// Creates a boxed up representation of a pointer.
//
{   LispObject w = getvector(TAG_VECTOR, TYPE_ENCAPSULATE, 2*CELL);
    errexit();
    *(void **)&elt(w, 0) = data;
    return w;
}

void *extract_pointer(LispObject a)
{   if (!is_vector(a) ||
        type_of_header(vechdr(a)) != TYPE_ENCAPSULATE)
        return NULL;
    else return *(void **)&elt(a, 0);
}

LispObject Lencapsulatedp(LispObject env, LispObject a)
{   if (is_vector(a) && type_of_header(vechdr(a)) == TYPE_ENCAPSULATE)
        return onevalue(lisp_true);
    else return nil;
}

//
// The next few functions are an experiment and apply when a reference to
// a native Maple object has somehow been imported into CSL and packed
// up as an "encapsulated pointer" as per above. It was used at a time
// when I was playing by building all of Reduce as a dynamically loadable
// library and loading it into Maple...
//

LispObject Lmaple_atomic_value(LispObject env, LispObject a)
{   LispObject v;
    if (!is_vector(a) ||
        type_of_header(vechdr(a)) != TYPE_MAPLEREF)
        return aerror1("not an encapsulated pointer", a);
    v = (LispObject)extract_pointer(a);
    if ((v & 1) != 0)
    {
//
// The next line overflows the range of CSL fixnums too early, but
// will serve as a place-holder for a while!
//
        return onevalue(fixnum_of_int(v >> 1));
    }
    else return onevalue(nil);
}

LispObject Lmaple_tag(LispObject, LispObject a)
{   LispObject v;
    LispObject *v1;
    if (!is_vector(a) ||
        type_of_header(vechdr(a)) != TYPE_MAPLEREF)
        return aerror1("not an encapsulated pointer", a);
    v = (LispObject)extract_pointer(a);
    if ((v & 1) != 0) return onevalue(nil); // an atomic value
    v1 = (LispObject *)v;
    v = *v1;    // the header word of the Maple object
// The following line will be incorrect on 64-bit machines
    return onevalue(fixnum_of_int(v >> 26));
}

LispObject Lmaple_length(LispObject, LispObject a)
{   LispObject v;
    LispObject *v1;
    if (!is_vector(a) ||
        type_of_header(vechdr(a)) != TYPE_MAPLEREF)
        return aerror1("not an encapsulated pointer", a);
    v = (LispObject)extract_pointer(a);
    if ((v & 1) != 0) return onevalue(nil); // an atomic value
    v1 = (LispObject *)v;
    v = *v1;    // the header word of the Maple object
// The following line will be incorrect on 64-bit machines
    return onevalue(fixnum_of_int(v & 0x03ffffff));
}

LispObject Lmaple_string_data(LispObject, LispObject a)
{   LispObject *p = (LispObject *)extract_pointer(a);
    char *s = (char *)&p[3];
    return onevalue(make_string(s));
}

LispObject Lmaple_integer(LispObject env, LispObject a)
{   LispObject r = fixnum_of_int(0);
    LispObject *p = (LispObject *)extract_pointer(a);
    int i;
    LispObject t = fixnum_of_int(1);
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

LispObject Lmaple_component(LispObject, LispObject a, LispObject nn)
{   LispObject v;
    LispObject *v1;
    int32_t len, n;
    if (!is_fixnum(nn)) return aerror1("integer needed as selector", nn);
    if (!is_vector(a) ||
        type_of_header(vechdr(a)) != TYPE_MAPLEREF)
        return aerror1("not an encapsulated pointer", a);
    v = (LispObject)extract_pointer(a);
    if ((v & 1) != 0) return onevalue(nil); // an atomic value
    v1 = (LispObject *)v;
    v = *v1;    // the header word of the Maple object
    n = int_of_fixnum(nn);
// The following line will be incorrect on 64-bit machines
    len = v & 0x03ffffff;
    if (n < 0 || n >= len) return aerror1("subscript out of range", nn);
    return onevalue(encapsulate_pointer((void *)v1[n+1]));
}

int primep(int32_t n)
//
// Used to ensure that the body of a hash-table has a size that is prime.
// Assumes that the value to be checked is not especially large.
//  Since it will have been handed in as a
// fixnum it is at worst 2^28 or so, so brute-force should be OK.
//
{   int32_t i;
    if ((n & 1) == 0) return 0;   // even
    for (i=3; i*i<=n; i+=2)
        if (n%i == 0) return 0;
    return 1;
}

LispObject Lputv(LispObject, int nargs, ...)
{   Header h;
    va_list a;
    size_t n1, hl;
    LispObject v, n, x;
    argcheck(nargs, 3, "putv");
    va_start(a, nargs);
    v = va_arg(a, LispObject);
    n = va_arg(a, LispObject);
    x = va_arg(a, LispObject);
    va_end(a);
    if (!is_vector(v) || vector_holds_binary(h = vechdr(v)))
        return aerror1("putv", v);
    else if (!is_fixnum(n)) return aerror1("putv offset not fixnum", n);
    hl = (length_of_header(h) - CELL)/CELL;
    n1 = int_of_fixnum(n);
    if (n1 < 0 || n1 >= hl) return aerror1("putv index range", n);
    elt(v, n1) = x;
    return onevalue(x);
}

LispObject Lgetv(LispObject, LispObject v, LispObject n)
{   Header h;
    size_t n1, hl;
    if (!is_vector(v) || vector_holds_binary(h = vechdr(v)))
        return aerror1("getv", v);
    else if (!is_fixnum(n)) return aerror1("getv offset not fixnum", n);
    hl = (length_of_header(h) - CELL)/CELL;
    n1 = int_of_fixnum(n);
    if (n1 < 0 || n1 >= hl) return aerror1("getv index range", n);
    else return onevalue(elt(v, n1));
}

//
// Here I make a (simple) string.
//

LispObject Lsmkvect(LispObject env, LispObject n)
{   LispObject w;
    size_t nn;
    if (!is_fixnum(n) || (intptr_t)n<0) return aerror1("make-simple-string", n);
    nn = int_of_fixnum(n);
    w = getvector(TAG_VECTOR, TYPE_STRING_4, nn+CELL);
    errexit();
    nn = (intptr_t)doubleword_align_up(nn+CELL);
    while (nn > CELL)
    {   nn -= CELL;
        *(intptr_t *)((char *)w - TAG_VECTOR + nn) = 0;
    }
    return onevalue(w);
}

//
// Here I make a vector capable of holding 8-bit binary integers.
//

LispObject Lmkvect8(LispObject env, LispObject n)
{   LispObject w;
    size_t nn;
    if (!is_fixnum(n) || (intptr_t)n<0) return aerror1("mkvect8", n);
    nn = 1 + int_of_fixnum(n);  // Note that in Standard Lisp style the +1
    w = getvector(TAG_VECTOR, TYPE_VEC8_4, nn+CELL);
    errexit();
    nn = (intptr_t)doubleword_align_up(nn+CELL);
    while (nn > CELL)
    {   nn -= CELL;
        *(intptr_t *)((char *)w - TAG_VECTOR + nn) = 0;
    }
    return onevalue(w);
}

//
// Here I make a vector capable of holding 16-bit binary integers.
//

LispObject Lmkvect16(LispObject env, LispObject n)
{   LispObject w;
    size_t nn;
    if (!is_fixnum(n) || (intptr_t)n<0) return aerror1("mkvect16", n);
    nn = 2*(1 + int_of_fixnum(n)); // Note 1+ for Standard Lisp style
    w = getvector(TAG_VECTOR, TYPE_VEC16_2, nn+CELL);
    errexit();
    nn = (intptr_t)doubleword_align_up(nn+CELL);
    while (nn > CELL)
    {   nn -= CELL;
        *(intptr_t *)((char *)w - TAG_VECTOR + nn) = 0;
    }
    return onevalue(w);
}

//
// Here I make a vector capable of holding 32-bit binary integers.
//

LispObject Lmkvect32(LispObject env, LispObject n)
{   LispObject w;
    size_t nn;
    if (!is_fixnum(n) || (intptr_t)n<0) return aerror1("mkvect32", n);
    nn = 4*(1 + int_of_fixnum(n));
    w = getvector(TAG_VECTOR, TYPE_VEC32, nn+CELL);
    errexit();
    nn = (intptr_t)doubleword_align_up(nn+CELL);
    while (nn > CELL)
    {   nn -= 4;
        *(int32_t *)((char *)w - TAG_VECTOR + nn) = 0;
    }
    return onevalue(w);
}

//
// Here I make a vector capable of holding 32-bit floats.
//

LispObject Lmkfvect32(LispObject env, LispObject n)
{   LispObject w;
    size_t nn;
    if (!is_fixnum(n) || (intptr_t)n<0) return aerror1("mkfvect32", n);
    nn = 4*(1 + int_of_fixnum(n));
    w = getvector(TAG_VECTOR, TYPE_VECFLOAT32, nn+CELL);
    errexit();
    nn = (intptr_t)doubleword_align_up(nn+CELL);
    while (nn > CELL)
    {   nn -= 4;
        *(float *)((char *)w - TAG_VECTOR + nn) = (float)0.0;
    }
    return onevalue(w);
}

//
// Here I make a vector capable of holding 64-bit floats.
//

LispObject Lmkfvect64(LispObject env, LispObject n)
{   LispObject w;
    size_t nn;
    if (!is_fixnum(n) || (intptr_t)n<0) return aerror1("mkfvect64", n);
    nn = 8*(1 + int_of_fixnum(n));
    if (!SIXTY_FOUR_BIT) nn += 4; // get the doubles aligned
    w = getvector(TAG_VECTOR, TYPE_VECFLOAT64, nn+CELL);
    errexit();
    nn = (intptr_t)(nn+CELL);
    while (nn > CELL)
    {   nn -= 8;
        *(double *)((char *)w - TAG_VECTOR + nn) = 0.0;
    }
    return onevalue(w);
}

LispObject simplify_string(LispObject s)
//
// s is supposed to be a string of some sort - return a simple string
// with the same contents.  This is horrid and messy, and relies on
// a load of stuff coded elsewhere in Lisp: is is coded here in C
// despite that because despite the breaches of modularity that are involved
// doing so seems to make bootstrapping easier.
//
{   Header h;
    LispObject w, h1;
    size_t i, n = 0;
    if (!is_vector(s)) return aerror("simplify-string");
    h = vechdr(s);
    if (is_string_header(h))
        return onevalue(s);                 // Already simple
    if (type_of_header(h) != TYPE_ARRAY) return aerror("simplify-string");
    h1 = elt(s, 0);
    if (h1 != string_char_sym) return aerror("simplify-string");
    h1 = elt(s, 1);                         // Dimension list
    if (!consp(h1)) return aerror("simplify-string");
    n = int_of_fixnum(qcar(h1));            // Look at size involved
    h1 = elt(s, 5);                         // Fill pointer
    if (is_fixnum(h1)) n = int_of_fixnum(h1);
    stackcheck1(0, s);
    push(s);
    w = getvector(TAG_VECTOR, TYPE_STRING_4, n+CELL);
    pop(s);
    errexit();
    i = (intptr_t)doubleword_align_up(n+CELL);
    while (i > CELL) // pre-fill target vector with zero
    {   i -= CELL;
        *(intptr_t *)((char *)w - TAG_VECTOR + i) = 0;
    }
    h1 = elt(s, 3);
    h = int_of_fixnum(h1);               // Displace adjustment
    s = elt(s, 2);
    for (i=0; i<n; i++) celt(w, i) = celt(s, i+h);
    return onevalue(w);
}

LispObject Lsputv(LispObject, int nargs, ...)
{   Header h;
    va_list a;
    int32_t vx;
    size_t n1, hl;
    LispObject v, n, x;
    argcheck(nargs, 3, "sputv");
    va_start(a, nargs);
    v = va_arg(a, LispObject);
    n = va_arg(a, LispObject);
    x = va_arg(a, LispObject);
    va_end(a);
    if (!is_vector(v) || !is_string_header(h = vechdr(v)))
        return aerror1("putv-char", v);
    else if (!is_fixnum(n)) return aerror1("putv-char", n);
    else if (is_fixnum(x)) vx = int_of_fixnum(x);
    else if (is_char(x)) vx = code_of_char(x);
    else return aerror1("putv-char contents", x);
    hl = length_of_byteheader(h) - CELL;
    n1 = int_of_fixnum(n);
    if (n1 < 0 || n1 >= hl) return aerror1("putv-char", n);
    celt(v, n1) = (char)vx;
    return onevalue(x);
}

//
// The next few correspond to multiple calls to string-store and are there
// so that if a string is updated in a way that is intended to put an UTL-8
// multi-byte sequnce into the middle of it then that can all be done in one
// call, not leaving an invalid UTF-8 sequence in a visible intermediate
// string. This would be an important abstraction if the underlying
// representation of strings was NOT in UTF-8 and the code around here
// was having to do mappings and conversions.
//

LispObject Lsputv2(LispObject, int nargs, ...)
{   Header h;
    va_list a;
    int32_t vx1, vx2;
    size_t n1, hl;
    LispObject v, n, x1, x2;
    argcheck(nargs, 4, "sputv2");
    va_start(a, nargs);
    v = va_arg(a, LispObject);
    n = va_arg(a, LispObject);
    x1 = va_arg(a, LispObject);
    x2 = va_arg(a, LispObject);
    va_end(a);
    if (!is_vector(v) || !is_string_header(h = vechdr(v)))
        return aerror1("putv-char2", v);
    else if (!is_fixnum(n)) return aerror1("putv-char", n);
    if (is_fixnum(x1)) vx1 = int_of_fixnum(x1);
    else if (is_char(x1)) vx1 = code_of_char(x1);
    else return aerror1("putv-char2 contents", x1);
    if (is_fixnum(x2)) vx2 = int_of_fixnum(x2);
    else if (is_char(x2)) vx2 = code_of_char(x2);
    else return aerror1("putv-char2 contents", x2);
    hl = length_of_byteheader(h) - CELL;
    n1 = int_of_fixnum(n);
    if (n1 < 0 || n1+1 >= hl) return aerror1("putv-char2", n);
    celt(v, n1) = (char)vx1;
    celt(v, n1+1) = (char)vx2;
    return onevalue(x2);
}

LispObject Lsputv3(LispObject, int nargs, ...)
{   Header h;
    va_list a;
    int32_t vx1, vx2, vx3;
    size_t n1, hl;
    LispObject v, n, x1, x2, x3;
    argcheck(nargs, 5, "sputv3");
    va_start(a, nargs);
    v = va_arg(a, LispObject);
    n = va_arg(a, LispObject);
    x1 = va_arg(a, LispObject);
    x2 = va_arg(a, LispObject);
    x3 = va_arg(a, LispObject);
    va_end(a);
    if (!is_vector(v) || !is_string_header(h = vechdr(v)))
        return aerror1("putv-char2", v);
    else if (!is_fixnum(n)) return aerror1("putv-char", n);
    if (is_fixnum(x1)) vx1 = int_of_fixnum(x1);
    else if (is_char(x1)) vx1 = code_of_char(x1);
    else return aerror1("putv-char2 contents", x1);
    if (is_fixnum(x2)) vx2 = int_of_fixnum(x2);
    else if (is_char(x2)) vx2 = code_of_char(x2);
    else return aerror1("putv-cha2r contents", x2);
    if (is_fixnum(x3)) vx3 = int_of_fixnum(x3);
    else if (is_char(x3)) vx3 = code_of_char(x3);
    else return aerror1("putv-char3 contents", x3);
    hl = length_of_byteheader(h) - CELL;
    n1 = int_of_fixnum(n);
    if (n1 < 0 || n1+2 >= hl) return aerror1("putv-char3", n);
    celt(v, n1) = (char)vx1;
    celt(v, n1+1) = (char)vx2;
    celt(v, n1+2) = (char)vx3;
    return onevalue(x3);
}

LispObject Lsputv4(LispObject, int nargs, ...)
{   Header h;
    va_list a;
    int32_t vx1, vx2, vx3, vx4;
    size_t n1, hl;
    LispObject v, n, x1, x2, x3, x4;
    argcheck(nargs, 6, "sputv4");
    va_start(a, nargs);
    v = va_arg(a, LispObject);
    n = va_arg(a, LispObject);
    x1 = va_arg(a, LispObject);
    x2 = va_arg(a, LispObject);
    x3 = va_arg(a, LispObject);
    x4 = va_arg(a, LispObject);
    va_end(a);
    if (!is_vector(v) || !is_string_header(h = vechdr(v)))
        return aerror1("putv-char2", v);
    else if (!is_fixnum(n)) return aerror1("putv-char", n);
    if (is_fixnum(x1)) vx1 = int_of_fixnum(x1);
    else if (is_char(x1)) vx1 = code_of_char(x1);
    else return aerror1("putv-char2 contents", x1);
    if (is_fixnum(x2)) vx2 = int_of_fixnum(x2);
    else if (is_char(x2)) vx2 = code_of_char(x2);
    else return aerror1("putv-cha2r contents", x2);
    if (is_fixnum(x3)) vx3 = int_of_fixnum(x3);
    else if (is_char(x3)) vx3 = code_of_char(x3);
    else return aerror1("putv-char3 contents", x3);
    if (is_fixnum(x4)) vx4 = int_of_fixnum(x4);
    else if (is_char(x4)) vx4 = code_of_char(x4);
    else return aerror1("putv-char4 contents", x4);
    hl = length_of_byteheader(h) - CELL;
    n1 = int_of_fixnum(n);
    if (n1 < 0 || n1+3 >= hl) return aerror1("putv-char3", n);
    celt(v, n1) = (char)vx1;
    celt(v, n1+1) = (char)vx2;
    celt(v, n1+2) = (char)vx3;
    celt(v, n1+3) = (char)vx4;
    return onevalue(x4);
}

LispObject Lbpsupbv(LispObject, LispObject v)
{   size_t n;
    if (!is_bps(v)) return aerror1("bps-upbv", v);
    n = length_of_byteheader(vechdr(v)) - CELL;
    return onevalue(fixnum_of_int(n-1));
}

LispObject Lbpsputv(LispObject, int nargs, ...)
{   va_list a;
    int32_t n1, hl;
    LispObject v, n, x;
    argcheck(nargs, 3, "bpsputv");
    va_start(a, nargs);
    v = va_arg(a, LispObject);
    n = va_arg(a, LispObject);
    x = va_arg(a, LispObject);
    va_end(a);
    if (!is_bps(v)) return aerror1("bpsputv", v);
    else if (!is_fixnum(n)) return aerror1("bps-putv", n);
    else if (!is_fixnum(x)) return aerror1("bps-putv contents", x);
    hl = length_of_byteheader(vechdr(v)) - CELL;
    n1 = int_of_fixnum(n);
    if (n1 < 0 || n1 >= hl) return aerror1("bps-putv", n);
    celt(v, n1) = (char)int_of_fixnum(x);
    return onevalue(x);
}

//
// To make this function Standard Lisp Friendly it will return as its
// value a SYMBOL. This is because unadorned character objects are not
// really part of Standard Lisp.  For cases where you want to character
// code I have introduced a function scharn which is almost exactly the
// same except that it returns an integer character code not a symbol.
// Note that this extracts a BYTE from the string rather than a character,
// even though the result is packed as a character.
//

LispObject Lsgetv(LispObject env, LispObject v, LispObject n)
{   Header h;
    int w;
    int32_t n1, hl;
    if (!is_vector(v) || !is_string_header(h = vechdr(v)))
        return aerror1("schar on non-string", v);
    else if (!is_fixnum(n)) return aerror1("schar index type incorrect", n);
    hl = length_of_byteheader(h) - CELL;
    n1 = int_of_fixnum(n);
    if (n1 < 0 || n1 >= hl) return aerror1("schar index out of range", n);
    w = celt(v, n1) & 0xff;
#ifdef COMMON
    return onevalue(pack_char(0, w));
#else
    n = elt(charvec, w);
    if (n == nil)
    {   if (w <= 0x7f)
        {   celt(boffo, 0) = w;
            n = iintern(boffo, 1, lisp_package, 0);
        }
        else
        {   celt(boffo, 0) = 0xc0 + ((w>>6) & 0x1f);
            celt(boffo, 1) = 0x80 + (w & 0x3f);
            n = iintern(boffo, 2, lisp_package, 0);
        }
        errexit();
        elt(charvec, w) = n;
    }
    return onevalue(n);
#endif
}

LispObject Lsgetvn(LispObject, LispObject v, LispObject n)
{   Header h;
    int w;
    size_t n1, hl;
    if (!is_vector(v) || !is_string_header(h = vechdr(v)))
        return aerror1("scharn", v);
    else if (!is_fixnum(n)) return aerror1("scharn", n);
    hl = length_of_byteheader(h) - CELL;
    n1 = int_of_fixnum(n);
    if (n1 < 0 || n1 >= hl) return aerror1("scharn", n);
    w = celt(v, n1) & 0xff;
    return onevalue(fixnum_of_int(w));
}

LispObject Lbytegetv(LispObject, LispObject v, LispObject n)
{   Header h;
    int w;
    size_t n1, hl;
    if (!is_vector(v) || !is_string_header(h = vechdr(v)))
        return aerror1("byte-getv", v);
    else if (!is_fixnum(n)) return aerror1("byte-getv", n);
    hl = length_of_byteheader(h) - CELL;
    n1 = int_of_fixnum(n);
    if (n1 < 0 || n1 >= hl) return aerror1("byte-getv", n);
    w = ucelt(v, n1);
    return onevalue(fixnum_of_int(w));
}

LispObject Lbpsgetv(LispObject, LispObject v, LispObject n)
{   size_t n1, hl;
    if (!is_bps(v)) return aerror1("bps-getv", v);
    else if (!is_fixnum(n)) return aerror1("bps-getv", n);
    hl = length_of_byteheader(vechdr(v)) - CELL;
    n1 = int_of_fixnum(n);
    if (n1 < 0 || n1 >= hl) return aerror1("bps-getv", n);
    n1 = celt(v, n1);
    return onevalue(fixnum_of_int(n1 & 0xff));
}

#ifdef REINSTATE_NATIVE_CODE_EXPERIMENT

//
// native-putv and native-getv have an optional trailing argument that
// should have the value 1, 2 or 4 to indicate the number of bytes to be
// transferred.
//

LispObject Lnativeputv(LispObject, int nargs, ...)
{   va_list a;
    int32_t o, v32, width;
    intptr_t p;
    LispObject v, n, x, w;
    if (nargs != 4)
    {   argcheck(nargs, 3, "native-putv");
    }
    va_start(a, nargs);
    v = va_arg(a, LispObject);
    n = va_arg(a, LispObject);
    x = va_arg(a, LispObject);
    if (nargs == 4) w = va_arg(a, LispObject);
    else w = fixnum_of_int(1);
    va_end(a);
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
{       default:
            return aerror1("native-putv width", w);
        case 1:
            *((char *)p + o) = (char)v32;
            break;
        case 2:
//
// The code that I had first written here tried to use int16, but
// there are some computers where that does not exist!  This could arise
// if sizeof(int)==8 and sizeof(short)==4.
// What I have here is probably not actually used yet and seems most
// unlikely to be a performance bottleneck even if it ever is! However
// the code I write here does impose a concrete byte-ordering...
//
            *((char *)p + o) = (char)v32;
            *((char *)p + o + 1) = (char)(v32 >> 8);
            break;
        case 4:
//
// NOTE that I access the memory here as an array of 32-bit values and I
// do not do anything to adjust for the order of bytes in the word, and I
// do not concern myself with alignment. The effect of mixtures of 1, 2 and
// 4 byte operations on native code space will be system dependent. But my
// intent at present is that native code is always to be generated on the
// machine on which it will run and that it will never be touched on other
// machines so this lack of portability is not really an issue! What could
// be a messier matter here is that the value x is
//
            *(int32_t *)((char *)p + o) = (int32_t)v32;
            break;
    }
    native_pages_changed = 1;
    return onevalue(x);
}

LispObject Lnativegetv(LispObject, LispObject v, LispObject n)
{   int32_t o;
    intptr_t p;
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

LispObject Lnativegetvn(LispObject, int nargs, ...)
{   LispObject v, n, w;
    int32_t o;
    intptr_t p;
    va_list a;
    argcheck(nargs, 3, "native-getv");
    va_start(a, nargs);
    v = va_arg(a, LispObject);
    n = va_arg(a, LispObject);
    w = va_arg(a, LispObject);
    va_end(a);
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
{       default:
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
            return make_lisp_integer32(o);
    }
}

LispObject Lnative_type(LispObject, int, ...)
{
//
// This mechanism is not being pursued at present...
//
#define NATIVE_CODE_TAG 0
    return onevalue(fixnum_of_int(NATIVE_CODE_TAG));
}

//
// (native-address fn nargs) fetches the value from the relevent function cell
// of the function and returns it represented as an integer. This gives
// the current real absolute address of the code involved and is intended
// to be useful while testing a native-mode compiler.
//

LispObject Lnative_address(LispObject, LispObject fn, LispObject nargs)
{   size_t n;
    if (!symbolp(fn)) return aerror1("native-address", fn);
    if (!is_fixnum(nargs)) return aerror1("native-address", nargs);
    n = int_of_fixnum(nargs);
    switch (n)
    {   case 1: n = ifn1(fn);
            break;
        case 2: n = ifn2(fn);
            break;
        default:n = ifnn(fn);
            break;
    }
    if (sizeof(intptr_t) == 4) return make_lisp_integer32((int32_t)n);
    else return make_lisp_integer64((int64_t)n);
}

//
// (native-address n) with one integer argument will return an integer that
// is the current memory address of a CSL/CCL internal variable identified
// by that integer. The association between integers and variables is as
// per the file "externs.h" and the switch statement here. The case 0 gives
// the address of NIL, while 1 gives the address of "stack".
// An invalid or unrecognised integer leads to a result
// of zero. This is intended solely for the use of a native-code compiler.
// It may not then be necessary to provide access to ALL of these variables,
// but at least to start with it seems easiest to be comprehensive.
// Negative integers use values in the following table, which are functions
// in CSL that might usefully be called directly. If the one argument is a
// cons then it is expected to be a native code handle and the associated
// real address is returned.
//

void *useful_functions[] =
{   (void *)cons,           // -1, 0
    (void *)ncons,          // -2, 1
    (void *)list2,          // -3, 2
    (void *)list2star,      // -4, 3
    (void *)acons,          // -5, 4
    (void *)list3,          // -6, 5
    (void *)plus2,          // -7, 6
    (void *)difference2,    // -8, 7
    (void *)add1,           // -9, 8
    (void *)sub1,           // -10, 9
    (void *)get,            // -11, 10
    (void *)lognot,         // -12, 11
    (void *)ash,            // -13, 12
    (void *)quot2,          // -14, 13
    (void *)Cremainder,     // -15, 14
    (void *)times2,         // -16, 15
    (void *)negate,         // -17, 16
    (void *)rational,       // -18, 17
    (void *)lessp2,         // -19, 18
    (void *)lesseq2,        // -20, 19
    (void *)greaterp2,      // -21, 20
    (void *)geq2,           // -22, 21
    (void *)zerop,          // -23, 22
    (void *)reclaim,        // -24, 23
    (void *)error,          // -25, 24
    (void *)equal_fn,       // -26, 25
    (void *)cl_equal_fn,    // -27, 26
    (void *)aerror,         // -28, 27
    (void *)integerp,       // -29, 28
    (void *)apply           // -30, 29
};

char *address_of_var(int n)
{   char *p = NULL;
    if (n == 0) p = (char *)nil;
    else if (n == 1) p = (char *)&stack;
    else
        switch (n)
    {       default:    p = 0;                              break;
            case  12:   p = (char *)&byteflip;              break;

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
#endif
            case 152:   p = (char *)&declare_symbol;        break;
            case 153:   p = (char *)&special_symbol;        break;
        }
    return p;
}


LispObject Lnative_address1(LispObject env, LispObject x)
{   int32_t n;
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
            if (n >= (intptr_t)(sizeof(useful_functions)/sizeof(void *)))
                return aerror1("native-address", x);
            else p = (intptr_t)useful_functions[n];
        }
        else p = (intptr_t)address_of_var(n);
    }
    if (sizeof(intptr_t) == 4) return make_lisp_integer32((int32_t)p);
    else return make_lisp_integer64((int64_t)p);
}

#endif // REINSTATE_NATIVE_CODE_EXPERIMENT



//
// Access functions for specialised (binary-contents) vectors. NOT integrated
// in with the greater generality of vector structures.
//

LispObject Lputv8(LispObject, int nargs, ...)
{   Header h;
    va_list a;
    size_t n1, hl;
    LispObject v, n, x;
    argcheck(nargs, 3, "putv8");
    va_start(a, nargs);
    v = va_arg(a, LispObject);
    n = va_arg(a, LispObject);
    x = va_arg(a, LispObject);
    va_end(a);
    if (!is_vector(v) || !is_vec8_header(h = vechdr(v)))
        return aerror1("putv8", v);
    else if (!is_fixnum(n)) return aerror1("putv8 offset not fixnum", n);
    hl = length_of_byteheader(h) - CELL;
    n1 = int_of_fixnum(n);
    if (n1 < 0 || n1 >= hl) return aerror1("putv8 index range", n);
    scelt(v, n1) = (char)int_of_fixnum(x);
    return onevalue(x);
}

LispObject Lgetv8(LispObject, LispObject v, LispObject n)
{   Header h;
    size_t n1, hl;
    if (!is_vector(v) || !is_vec8_header(h = vechdr(v)))
        return aerror1("getv8", v);
    else if (!is_fixnum(n)) return aerror1("getv8 offset not fixnum", n);
    hl = length_of_byteheader(h) - CELL;
    n1 = int_of_fixnum(n);
    if (n1 < 0 || n1 >= hl) return aerror1("getv8 index range", n);
    else return onevalue(fixnum_of_int(scelt(v, n1)));
}

LispObject Lputv16(LispObject, int nargs, ...)
{   Header h;
    va_list a;
    size_t n1, hl;
    LispObject v, n, x;
    argcheck(nargs, 3, "putv16");
    va_start(a, nargs);
    v = va_arg(a, LispObject);
    n = va_arg(a, LispObject);
    x = va_arg(a, LispObject);
    va_end(a);
    if (!is_vector(v) || !is_vec16_header(h = vechdr(v)))
        return aerror1("putv16", v);
    else if (!is_fixnum(n)) return aerror1("putv16 offset not fixnum", n);
    hl = length_of_hwordheader(h) - CELL/2;
    n1 = int_of_fixnum(n);
    if (n1 < 0 || n1 >= hl) return aerror1("putv16 index range", n);
    sethelt(v, n1, int_of_fixnum(x));
    return onevalue(x);
}

LispObject Lgetv16(LispObject, LispObject v, LispObject n)
{   Header h;
    size_t n1, hl;
    if (!is_vector(v) || !is_vec16_header(h = vechdr(v)))
        return aerror1("getv16", v);
    else if (!is_fixnum(n)) return aerror1("getv16 offset not fixnum", n);
    hl = length_of_hwordheader(h) - CELL/2;
    n1 = int_of_fixnum(n);
    if (n1 < 0 || n1 >= hl) return aerror1("getv16 index range", n);
    n1 = helt(v, n1);
    return onevalue(fixnum_of_int(n1));
}

LispObject Lputv32(LispObject, int nargs, ...)
{   Header h;
    va_list a;
    size_t n1, hl;
    LispObject v, n, x;
    argcheck(nargs, 3, "putv32");
    va_start(a, nargs);
    v = va_arg(a, LispObject);
    n = va_arg(a, LispObject);
    x = va_arg(a, LispObject);
    va_end(a);
    if (!is_vector(v) || type_of_header(h = vechdr(v)) != TYPE_VEC32)
        return aerror1("putv32", v);
    else if (!is_fixnum(n)) return aerror1("putv32 offset not fixnum", n);
    hl = (length_of_header(h) - CELL)/4;
    n1 = int_of_fixnum(n);
    if (n1 < 0 || n1 >= hl) return aerror1("putv32 index range", n);
    ielt32(v, n1) = thirty_two_bits(x);
    return onevalue(x);
}

LispObject Lgetv32(LispObject, LispObject v, LispObject n)
{   Header h;
    size_t n1, hl;
    if (!is_vector(v) || type_of_header(h = vechdr(v)) != TYPE_VEC32)
        return aerror1("getv32", v);
    else if (!is_fixnum(n)) return aerror1("getv32 offset not fixnum", n);
    hl = (length_of_header(h) - CELL)/4;
    n1 = int_of_fixnum(n);
    if (n1 < 0 || n1 >= hl) return aerror1("getv32 index range", n);
    n1 = ielt32(v, n1);
    return make_lisp_integer32(n1);
}

LispObject Lfputv32(LispObject, int nargs, ...)
{   Header h;
    va_list a;
    size_t n1, hl;
    LispObject v, n, x;
    double d;
    argcheck(nargs, 3, "fputv32");
    va_start(a, nargs);
    v = va_arg(a, LispObject);
    n = va_arg(a, LispObject);
    x = va_arg(a, LispObject);
    d = float_of_number(x);
    va_end(a);
    if (!is_vector(v) || type_of_header(h = vechdr(v)) != TYPE_VECFLOAT32)
        return aerror1("fputv32", v);
    else if (!is_fixnum(n)) return aerror1("fputv32 offset not fixnum", n);
    hl = (length_of_header(h) - CELL)/4;
    n1 = int_of_fixnum(n);
    if (n1 < 0 || n1 >= hl) return aerror1("fputv32 index range", n);
    felt(v, n1) = (float)d;
    return onevalue(x);
}

LispObject Lfgetv32(LispObject env, LispObject v, LispObject n)
{   Header h;
    size_t n1, hl;
    if (!is_vector(v) || type_of_header(h = vechdr(v)) != TYPE_VECFLOAT32)
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

LispObject Lfputv64(LispObject, int nargs, ...)
{   Header h;
    va_list a;
    size_t n1, hl;
    LispObject v, n, x;
    double d;
    argcheck(nargs, 3, "fputv64");
    va_start(a, nargs);
    v = va_arg(a, LispObject);
    n = va_arg(a, LispObject);
    x = va_arg(a, LispObject);
    d = float_of_number(x);
    va_end(a);
    if (!is_vector(v) || type_of_header(h = vechdr(v)) != TYPE_VECFLOAT64)
        return aerror1("fputv64", v);
    else if (!is_fixnum(n)) return aerror1("fputv64 offset not fixnum", n);
//
// NB it is not a misprint - the first double ALWAYS starts 8 bytes in...
//
    hl = (length_of_header(h) - 8)/8;
    n1 = int_of_fixnum(n);
    if (n1 < 0 || n1 >= hl) return aerror1("fputv64 index range", n);
    delt(v, n1) = d;
    return onevalue(x);
}

LispObject Lfgetv64(LispObject env, LispObject v, LispObject n)
{   Header h;
    size_t n1, hl;
    if (!is_vector(v) || type_of_header(h = vechdr(v)) != TYPE_VECFLOAT64)
        return aerror1("fgetv64", v);
    else if (!is_fixnum(n)) return aerror1("fgetv64 offset not fixnum", n);
    hl = (length_of_header(h) - 8)/8;
    n1 = int_of_fixnum(n);
    if (n1 < 0 || n1 >= hl) return aerror1("fgetv64 index range", n);
    v = make_boxfloat(delt(v, n1), TYPE_DOUBLE_FLOAT);
    errexit();
    return onevalue(v);
}

//
// This is useful in Standard as well as Common Lisp
//
// (defun list-to-vector (old)
//    (let* ((len (length old))
//           (new (make-simple-vector len)))
//       (dotimes (i len new) (putv new i (car old)) (setq old (cdr old)))))
//

LispObject Llist_to_vector(LispObject env, LispObject a)
{   LispObject v;
    int32_t n = CELL;
//
// The general LENGTH function deals with vectors as well as lists, and
// returns a Lisp integer result. So here I just write out a simple in-line
// version.
//
    for (v=a; consp(v); v = qcdr(v)) n += CELL;
    push(a);
    v = getvector(TAG_VECTOR, TYPE_SIMPLE_VEC, n);
    pop(a);
    errexit();
    for(n=0; consp(a); a = qcdr(a), n++) elt(v, n) = qcar(a);
    if (!SIXTY_FOUR_BIT && ((n & 1) == 0)) elt(v, n) = nil;  // Padder word
    return onevalue(v);
}


#ifdef COMMON
//
// (defun putvec (v n x)
//    (cond
//       ((simple-string-p v) (putv-char v n x))
//       ((simple-bit-vector-p v) (putv-bit v n x))
//       (t (putv v n x))))
//

static LispObject Lputvec(LispObject, int nargs, ...)
{   Header h;
    va_list a;
    int32_t vx;
    size_t n1, hl;
    LispObject v, n, x;
    argcheck(nargs, 3, "putvec");
    va_start(a, nargs);
    v = va_arg(a, LispObject);
    n = va_arg(a, LispObject);
    x = va_arg(a, LispObject);
    va_end(a);
//
// Oh joy - here I have to dispatch based on what sort of vector I have.
//
    if (!is_vector(v)) return aerror1("putvec", v);
    else if (!is_fixnum(n)) return aerror1("putvec", n);
    h = vechdr(v);
    if (is_string_header(h))
    {   if (is_fixnum(x)) vx = int_of_fixnum(x);
        else if (is_char(x)) vx = code_of_char(x);
        else return aerror1("putvec on string, contents", x);
        hl = length_of_byteheader(h) - CELL;
        n1 = int_of_fixnum(n);
        if (n1 < 0 || n1 >= hl) return aerror1("putvec", n);
        celt(v, n1) = (int)vx;
        return onevalue(x);
    }
    if (is_bitvec_header(h))
    {   int b;
        if (!is_fixnum(x)) return aerror1("putvec on bitvec, contents", x);
        x = int_of_fixnum(x) & 1;
// This will all need review...
        h = length_of_header(h) - CELL;
        n1 = int_of_fixnum(n);
        b = 1 << (n1 & 7);     // Bit selector
        n1 = n1 >> 3;          // Byte selector
//
// I am just a bit shoddy here - I only complain if an attempt is made to
// access beyond the last active byte of a bitvector - I do not
// do bound checking accurate to bit positions.
//
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

//
// (defun aref (v n1 &rest r)
//   (if (null r)
//       (cond
//          ((simple-vector-p v) (getv v n1))
//          ((simple-string-p v) (schar v n1))
//          ((simple-bit-vector-p v) (getv-bit v n1))
//          ((structp v) (getv v n1))
//          (t (general-aref v n1 r)))
//       (general-aref v n1 r)))
//
// (defun general-aref (v n1 r)
//    (when (not (arrayp v)) (error "aref ~s ~s" v (cons n1 r)))
//    (do ((dd (cdr (getv v 1)) (cdr dd)))
//        ((null r))
//        (setq n1 (+ (* n1 (car dd)) (pop r))))
//**** plus special magic to deal with segmented representations...
//    (aref (getv v 2) (+ (getv v 3) n1)))
//

LispObject Laref(LispObject env, int nargs, ...)
{   Header h;
    LispObject v, n, w;
    intptr_t hl, n1;
    int32_t b;
    va_list a;
    if (nargs == 0) return aerror("aref");
    va_start(a, nargs);
    v = va_arg(a, LispObject);
    if (!is_vector(v))
    {   va_end(a);
        return aerror1("aref", v);
    }
    h = vechdr(v);
    if (nargs == 1) n = 0;  // Funny case (aref v) legal if no dimensions!
    else
    {   n = va_arg(a, LispObject);   // First subscript
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
            else if (is_string_header(h))
            {   va_end(a);
                hl = length_of_byteheader(h) - CELL;
                n1 = int_of_fixnum(n);
                if (n1 < 0 || n1 >= hl) return aerror1("aref index range", n);
                return onevalue(pack_char(0, celt(v, n1)));
            }
            else if (is_bitvec_header(h))
            {   va_end(a);
// Will need review
                h = length_of_header(h) - CELL;
                n1 = int_of_fixnum(n);
                b = 1 << (n1 & 7);     // Bit selector
                n1 = n1 >> 3;          // Byte selector
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
//
// Here I had better have a general array, and I will need to calculate the
// real index location within it.
//
    w = elt(v, 1);   // The list of dimensions
    if (w == nil && nargs == 1)
    {   va_end(a);
        return onevalue(elt(v, 2));
    }
    n1 = int_of_fixnum(n);
    w = qcdr(w);
    while (nargs > 2 && w != nil)
    {   n = va_arg(a, LispObject);
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
    n1 += int_of_fixnum(elt(v, 3));  // displaced-index-offset
    v = elt(v, 2);
//
// Now I have got the vector that this array is displaced to or
// represented by. If it is in fact a structure (not a simple vector)
// then it is a row of 8K sub-vectors, and at element zero it has the
// nominal size of the big vector (as a Lisp integer)
//
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
    else if (is_string_header(h))
    {   hl = length_of_byteheader(h) - CELL;
        if (n1 < 0 || n1 >= hl) return aerror("aref index range");
        return onevalue(pack_char(0, celt(v, n1)));
    }
    else if (is_bitvec_header(h))
    {   h = length_of_header(h) - CELL;
// Will need review
        b = 1 << (n1 & 7);     // Bit selector
        n1 = n1 >> 3;          // Byte selector
        if (n1 < 0 || n1 >= (int32_t)h) return aerror("aref index range");
        if ((celt(v, n1) & b) == 0) return onevalue(fixnum_of_int(0));
        else return onevalue(fixnum_of_int(1));
    }
    return aerror("aref unknown type for vector representation");
}

static LispObject Laref1(LispObject env, LispObject a)
{   return Laref(nil, 1, a);
}

LispObject Laref2(LispObject env, LispObject a, LispObject b)
{   return Laref(nil, 2, a, b);
}

LispObject Lelt(LispObject env, LispObject v, LispObject n)
{   Header h;
    LispObject w;
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
    else if (is_string_header(h))
    {   hl = length_of_byteheader(h) - CELL;
        if (n1 >= hl) return aerror1("elt index range", n);
        return onevalue(pack_char(0, celt(v, n1)));
    }
    else if (is_bitvec_header(h))
    {   h = length_of_header(h) - CELL;
// Will need review
        b = 1 << (n1 & 7);     // Bit selector
        n1 = n1 >> 3;          // Byte selector
        if (n1 < 0 || n1 >= (int32_t)h)
            return aerror1("elt index range", n);
        if ((celt(v, n1) & b) == 0) return onevalue(fixnum_of_int(0));
        else return onevalue(fixnum_of_int(1));
    }
    if (type_of_header(h) != TYPE_ARRAY) return aerror1("elt", v);
    w = elt(v, 1);   // The list of dimensions - must be 1 dim here
    w = qcdr(w);
    if (w != nil) return aerror1("elt", v);
    n1 += int_of_fixnum(elt(v, 3));  // displaced-index-offset
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
    else if (is_string_header(h))
    {   hl = length_of_byteheader(h) - CELL;
        if (n1 >= hl) return aerror("elt index range");
        return onevalue(pack_char(0, celt(v, n1)));
    }
    else if (is_bitvec_header(h))
    {   h = length_of_header(h) - CELL;
        b = 1 << (n1 & 7);     // Bit selector
        n1 = n1 >> 3;          // Byte selector
        if (n1 >= (int32_t)h) return aerror("elt index range");
        if ((celt(v, n1) & b) == 0) return onevalue(fixnum_of_int(0));
        else return onevalue(fixnum_of_int(1));
    }
    return aerror("elt unknown type for vector representation");
}

//
// (defun aset (v n1 x &rest r)
//   (if (null r)
//      (cond
//         ((simple-vector-p v) (putv v n1 x))
//         ((simple-string-p v) (putv-char v n1 x))
//         ((simple-bit-vector-p v) (putv-bit v n1 x))
//         ((structp v) (putv v n1 x))
//         (t (general-aset v n1 x r)))
//      (general-aset v n1 x r)))
//
// (defun general-aset (v n1 x r)
//    (when (not (arrayp v)) (error "aref ~s ~s" v
//                  (reverse (cdr (reverse (cons n1 (cons x r)))))))
//    (setq r (cons x r))
//    (do ((dd (cdr (getv v 1)) (cdr dd)))
//        ((null (cdr r)))
//        (setq n1 (+ (* n1 (car dd)) (pop r))))
//**** plus special magic to deal with segmented representations...
//    (aset (getv v 2) (+ (getv v 3) n1) (car r)))
//

//
// Note that the code for ASET is really a mildly modified copy of that
// for AREF.
//

LispObject Laset(LispObject env, int nargs, ...)
{   Header h;
    LispObject v, n, w, x;
    int32_t hl, n1, b;
    va_list a;
    if (nargs < 2) return aerror("aset");
    va_start(a, nargs);
    v = va_arg(a, LispObject);
    if (!is_vector(v))
    {   va_end(a);
        return aerror1("aset", v);
    }
    h = vechdr(v);
    if (nargs == 2) n = 0;  // Funny case (aset v w) legal if no dimensions!
    else
    {   n = va_arg(a, LispObject);   // First subscript
        if (!is_fixnum(n))
        {   va_end(a);
            return aerror1("aset", n);
        }
        if (nargs == 3)
        {   if (type_of_header(h) == TYPE_SIMPLE_VEC ||
                type_of_header(h) == TYPE_STRUCTURE)
            {   x = va_arg(a, LispObject);
                va_end(a);
                hl = (length_of_header(h) - CELL)/CELL;
                n1 = int_of_fixnum(n);
                if (n1 < 0 || n1 >= hl) return aerror1("aset index range", n);
                elt(v, n1) = x;
                return onevalue(x);
            }
            else if (is_string_header(h))
            {   x = va_arg(a, LispObject);
                va_end(a);
                hl = length_of_byteheader(h) - CELL;
                n1 = int_of_fixnum(n);
                if (n1 < 0 || n1 >= hl) return aerror1("aset index range", n);
                if (is_fixnum(x)) b = int_of_fixnum(x);
                else if (is_char(x)) b = code_of_char(x);
                else return aerror1("aset needs char", x);
                celt(v, n1) = b;
                return onevalue(x);
            }
            else if (is_bitvec_header(h))
            {   x = va_arg(a, LispObject);
                va_end(a);
                h = length_of_header(h) - CELL;
                n1 = int_of_fixnum(n);
                b = 1 << (n1 & 7);     // Bit selector
                n1 = n1 >> 3;          // Byte selector
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
//
// Here I had better have a general array, and I will need to calculate the
// real index location within it.
//
    w = elt(v, 1);   // The list of dimensions
    if (w == nil && nargs == 2)
    {   x = va_arg(a, LispObject);
        va_end(a);
        elt(v, 2) = x;
        return onevalue(x);
    }
    n1 = int_of_fixnum(n);
    w = qcdr(w);
    while (nargs > 3 && w != nil)
    {   n = va_arg(a, LispObject);
        if (!is_fixnum(n))
        {   va_end(a);
            return aerror1("aset", n);
        }
        n1 = n1*int_of_fixnum(qcar(w)) + int_of_fixnum(n);
        nargs--;
        w = qcdr(w);
    }
    x = va_arg(a, LispObject);
    va_end(a);
    if (nargs > 3 || w != nil)
        return aerror("aset, wrong number of subscripts");
    n1 += int_of_fixnum(elt(v, 3)); // displaced-index-offset
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
    else if (is_string_header(h))
    {   hl = length_of_byteheader(h) - CELL;
        if (n1 < 0 || n1 >= hl) return aerror("aset index range");
        if (is_fixnum(x)) b = int_of_fixnum(x);
        else if (is_char(x)) b = code_of_char(x);
        else return aerror1("aset needs char", x);
        celt(v, n1) = b;
        return onevalue(x);
    }
    else if (is_bitvec_header(h))
    {   h = length_of_header(h) - CELL;
        b = 1 << (n1 & 7);     // Bit selector
        n1 = n1 >> 3;          // Byte selector
        if (n1 < 0 || n1 >= (int32_t)h) return aerror("aset index range");
        if (!is_fixnum(x)) return aerror1("aset needs bit", x);
        if (int_of_fixnum(x) & 1) ucelt(v, n1) |= b;
        else ucelt(v, n1) &= ~b;
        return onevalue(x);
    }
    return aerror("aset unknown type for vector representation");
}

static LispObject Laset1(LispObject env, LispObject a)
{   return aerror("aset");
}

static LispObject Laset2(LispObject env, LispObject a, LispObject b)
{   return Laset(nil, 2, a, b);
}

static LispObject Lsetelt(LispObject env, int nargs, ...)
{   LispObject v, n, x;
    Header h;
    LispObject w;
    int32_t hl, n1, b;
    va_list a;
    argcheck(nargs, 3, "setelt");
    va_start(a, nargs);
    v = va_arg(a, LispObject);
    n = va_arg(a, LispObject);
    x = va_arg(a, LispObject);
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
    else if (is_string_header(h))
    {   int vx;
        hl = length_of_byteheader(h) - CELL;
        if (n1 >= hl) return aerror1("setelt index range", n);
        if (is_fixnum(x)) vx = int_of_fixnum(x);
        else if (is_char(x)) vx = code_of_char(x);
        else return aerror1("setelt contents", x);
        celt(v, n1) = vx;
        return onevalue(x);
    }
    else if (is_bitvec_header(h))
    {   if (!is_fixnum(x)) return aerror1("setelt contents", x);
        x = int_of_fixnum(x) & 1;
        h = length_of_header(h) - CELL;
        b = 1 << (n1 & 7);     // Bit selector
        n1 = n1 >> 3;          // Byte selector
        if (n1 >= (int32_t)h)
            return aerror1("setelt index range", n);
        if (x == 0) celt(v, n1) &= ~b;
        else celt(v, n1) |= b;
        return onevalue(fixnum_of_int(x));
    }
    if (type_of_header(h) != TYPE_ARRAY) return aerror1("setelt", v);
    w = elt(v, 1);   // The list of dimensions - must be 1 dim here
    w = qcdr(w);
    if (w != nil) return aerror1("setelt", v);
    n1 += int_of_fixnum(elt(v, 3));  // displaced-index-offset
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
    else if (is_string_header(h))
    {   int vx;
        hl = length_of_byteheader(h) - CELL;
        if (is_fixnum(x)) vx = int_of_fixnum(x);
        else if (is_char(x)) vx = code_of_char(x);
        else return aerror1("setelt contents", x);
        if (n1 >= hl) return aerror("setelt index range");
        celt(v, n1) = vx;
        return onevalue(x);
    }
    else if (is_bitvec_header(h))
    {   if (!is_fixnum(x)) return aerror1("setelt contents", x);
        x = int_of_fixnum(x) & 1;
        h = length_of_header(h) - CELL;
        b = 1 << (n1 & 7);     // Bit selector
        n1 = n1 >> 3;          // Byte selector
        if (n1 >= (int32_t)h) return aerror("setelt index range");
        if (x == 0) celt(v, n1) &= ~b;
        else celt(v, n1) |= b;
        return onevalue(fixnum_of_int(x));
    }
    return aerror("setelt unknown type for vector representation");
}

//
// (defun vectorp (x)
//     (or (simple-vector-p x)
//         (simple-string-p x)
//         (simple-bit-vector-p x)
//         (and (arrayp x) (length-one-p (svref x 1)))))
//

LispObject Lvectorp(LispObject env, LispObject a)
{   Header h;
    int32_t tt;
    if (!is_vector(a)) return onevalue(nil);
    h = vechdr(a);
    tt = type_of_header(h);
    if (tt == TYPE_SIMPLE_VEC ||
        is_string_header(h) ||
        is_bitvec_header(h)) return onevalue(lisp_true);
    if (tt == TYPE_ARRAY)
    {   a = elt(a, 1);   // List of dimensions
        if (consp(a) && !consp(qcdr(a))) return onevalue(lisp_true);
    }
    return onevalue(nil);
}

//
// (defun char (s n)
//    (cond
//       ((simple-string-p s) (schar s n))
//       (t (aref s n))))
//

static LispObject Lchar(LispObject env, LispObject v, LispObject n)
{   Header h;
    if (!is_vector(v)) return aerror("char");
    h = vechdr(v);
    if (is_string_header(h))
    {   int32_t hl, n1;
        if (!is_fixnum(n)) return aerror1("char", n);
        hl = length_of_byteheader(h) - CELL;
        n1 = int_of_fixnum(n);
        if (n1 < 0 || n1 >= hl) return aerror1("schar", n);
        return onevalue(pack_char(0, celt(v, n1)));
    }
    return Laref(nil, 2, v, n);
}

//
// (defun charset (s n c)
//    (cond
//       ((simple-string-p s) (putv-char s n c))
//       (t (aset s n c))))
//

static LispObject Lcharset(LispObject env, int nargs, ...)
{   LispObject v, n, c;
    Header h;
    va_list a;
    argcheck(nargs, 3, "charset");
    va_start(a, nargs);
    v = va_arg(a, LispObject);
    n = va_arg(a, LispObject);
    c = va_arg(a, LispObject);
    va_end(a);
    if (!is_vector(v)) return aerror1("charset", v);
    h = vechdr(v);
    if (!is_fixnum(n)) return aerror1("charset", n);
    if (is_string_header(h))
    {   int32_t hl, n1, vx;
        if (!is_fixnum(n)) return aerror1("charset", n);
        hl = length_of_byteheader(h) - CELL;
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

//
// (defun make-string (len &key (initial-element #\ ))
//    (let ((s (make-simple-string len)))
//       (dotimes (i len) (charset s i initial-element))
//       s))
//

static LispObject Lmake_string(LispObject env, int nargs, ...)
{   va_list a;
    LispObject w, n, key, init;
    int32_t nn, z, blanks;
    argcheck(nargs, 3, "make-string");
    va_start(a, nargs);
    n = va_arg(a, LispObject);
    key = va_arg(a, LispObject);
    init = va_arg(a, LispObject);
    va_end(a);
    if (!is_fixnum(n) || (int32_t)n<0) return aerror1("make-string", n);
    if (!is_char(init) && !is_fixnum(init))
        return aerror1("make-string", init);
    if (key != initial_element) return aerror1("make-string", key);
    nn = int_of_fixnum(n);
    w = getvector(TAG_VECTOR, TYPE_STRING_4, nn+CELL);
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

static LispObject Lmake_string1(LispObject env, LispObject n)
{   LispObject w;
    int32_t nn, z, blanks;
    if (!is_fixnum(n) || (int32_t)n<0) return aerror1("make-string", n);
    nn = int_of_fixnum(n);
    w = getvector(TAG_VECTOR, TYPE_STRING_4, nn+CELL);
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

static LispObject Lmake_string2(LispObject env, LispObject a, LispObject b)
{   return Lmake_string(nil, 2, a, b);
}

//
// (defun string (x)
//    (cond
//       ((stringp x) x)
//       ((symbolp x) (symbol-name x))
//       ((string-char-p x) (make-string 1 :initial-element x))
//       (t (error "String expected, but found ~S" x))))
//

static LispObject Lstring(LispObject env, LispObject a)
{   Header h;
    LispObject w;
    if (!is_vector(a))
    {   char dd[4];
        if (symbolp(a)) return onevalue(qpname(a));
        if (!is_char(a)) return aerror1("string", a);
        dd[0] = 'x'; // Done this way in case character arg has code 0
        dd[1] = 0;
        w = make_string(dd);
        errexit();
        celt(w, 0) = code_of_char(a);
        return onevalue(w);
    }
    h = vechdr(a);
    if (is_string_header(h)) return onevalue(a);
    else if (type_of_header(h) != TYPE_ARRAY) return aerror1("string", a);
//
// Beware abolition of 'string-char
//
    else if (elt(a, 0) != string_char_sym) return aerror1("string", a);
    w = elt(a, 1);
    if (!consp(w) || consp(qcdr(w))) return aerror1("string", a);
    else return onevalue(a);
}

//
// (defun copy-vector (old)
// ;; At present this only copies general vectors...
//    (let* ((len (vector-bound old))
//           (new (make-simple-vector len)))
//       (dotimes (i len new) (putv new i (svref old i)))))
//

static LispObject Lcopy_vector(LispObject env, LispObject a)
{   // not done yet!
    return onevalue(nil);
}


//
// (defun vector (&rest args)
// ;; Note that a vector made this way can have at most 50 elements...
//    (let* ((l (length args))
//           (g (make-simple-vector l)))
//       (dotimes (i l g)
//           (putv g i (car args))
//           (setq args (cdr args)))))
//

static LispObject Lvector(LispObject env, int nargs, ...)
{   LispObject r = nil, w;
    va_list a;
    va_start(a, nargs);
    push_args(a, nargs);
    r = getvector(TAG_VECTOR, TYPE_SIMPLE_VEC, CELL*nargs+CELL);
    errexitn(nargs);
//
// The next line allows for the fact that vectors MUST pad to an even
// number of words.
//
    if (!SIXTY_FOUR_BIT && ((nargs & 1) == 0)) elt(r, nargs) = nil;
    while (nargs > 0)
    {   pop(w);
        elt(r, --nargs) = w;
    }
    return onevalue(r);
}

static LispObject Lvector1(LispObject env, LispObject a)
{   return Lvector(nil, 1, a);
}

static LispObject Lvector2(LispObject env, LispObject a, LispObject b)
{   return Lvector(nil, 2, a, b);
}


static LispObject Lshrink_vector(LispObject env,
                                 LispObject v, LispObject n)
{   int32_t n1, n2;
    if (!is_vector(v)) return aerror1("shrink-vector", v);
    if (!is_fixnum(n)) return aerror1("shrink-vector", n);
    n1 = length_of_header(vechdr(v));
    n2 = CELL*int_of_fixnum(n)+CELL;
    if (n2 >= n1) return onevalue(v);  // Not shrunk at all
    if (!SIXTY_FOUR_BIT && (n1==n2+4) && ((n2&4)==0))   // No space to free
        *(LispObject *)((char *)v-TAG_VECTOR+n2) = nil;
    else
    {   int32_t n2a = doubleword_align_up(n2);
        n1 = doubleword_align_up(n1);
        *(LispObject *)((char *)v-TAG_VECTOR+n1) = make_padder(n1-n2a);
    }
    vechdr(v) = TAG_HDR_IMMED+
        type_of_header(vechdr(v))+
        pack_headerlengthbytes(n2);
    return onevalue(v);
}

#endif // COMMON

static LispObject Lmake_simple_bitvector(LispObject env, LispObject n)
{   int32_t bytes;
    LispObject w;
    size_t n1;
    if (!is_fixnum(n) || (int32_t)n<0)
        return aerror1("make-simple-bitvector", n);
    n1 = int_of_fixnum(n);
    bytes = CELL+(n1+7)/8;
    w = getvector(TAG_VECTOR, bitvechdr_(n1), bytes);
    errexit();
    n1 = doubleword_align_up(bytes);
    while (n1 > CELL)
    {   n1 -= 4;
        *(int32_t *)((char *)w - TAG_VECTOR + n1) = 0;
    }
    return onevalue(w);
}

static LispObject Lbputv(LispObject, int nargs, ...)
{   Header h;
    va_list a;
    int b;
    int32_t n1;
    LispObject v, n, x;
    argcheck(nargs, 3, "bputv");
    va_start(a, nargs);
    v = va_arg(a, LispObject);
    n = va_arg(a, LispObject);
    x = va_arg(a, LispObject);
    va_end(a);
//
// This code is WRONG at present in that unexpectedly it is supposed to
// support bit-arrays of arbitrary rank, and not just simple vectors.
//
    if (!(is_vector(v)) || !is_bitvec_header(h = vechdr(v)))
        return aerror1("putv-bit", v);
    if (!is_fixnum(n)) return aerror1("putv-bit", n);
    if (!is_fixnum(x)) return aerror1("putv-bit contents", x);
    x = int_of_fixnum(x) & 1;
    h = length_of_header(h) - CELL;
    n1 = int_of_fixnum(n);
    b = 1 << (n1 & 7);     // Bit selector
    n1 = n1 >> 3;          // Byte selector
//
// I am just a bit shoddy here - I only complain if an attempt is made to
// access beyond the last active byte of a bitvector - I do not
// do bound checking accurate to bit positions.
//
    if (n1 < 0 || n1 >= (int32_t)h) return aerror1("putv-bit", n);
    if (x == 0) ucelt(v, n1) &= ~b;
    else        ucelt(v, n1) |= b;
    return onevalue(fixnum_of_int(x));
}

static LispObject Lbgetv(LispObject, LispObject v, LispObject n)
{   Header h;
    int b;
    int32_t n1;
//
// This code is WRONG at present in that unexpectedly it is supposed to
// support bit-arrays of arbitrary rank, and not just simple vectors.
//
    if (!(is_vector(v)) || !is_bitvec_header(h = vechdr(v)))
        return aerror1("getv-bit", v);
    if (!is_fixnum(n)) return aerror1("getv-bit", n);
    h = length_of_header(h) - CELL;
    n1 = int_of_fixnum(n);
    b = 1 << (n1 & 7);     // Bit selector
    n1 = n1 >> 3;          // Byte selector
    if (n1 < 0 || n1 >= (int32_t)h) return aerror1("getv-bit", n);
    if ((ucelt(v, n1) & b) == 0)
        return onevalue(fixnum_of_int(0));
    else return onevalue(fixnum_of_int(1));
}

LispObject Lupbv(LispObject env, LispObject v)
{   Header h;
    int32_t n;
    if (!(is_vector(v))) return onevalue(nil); // Standard Lisp demands..
    h = vechdr(v);
    n = length_of_header(h) - CELL;
#ifdef COMMON
    if (is_bitvec_header(h))
    {   n = (n - 1)*8;
        n += ((h & 0x380) >> 7) + 1;
    }
    else
#endif
        switch (type_of_header(h))
        {
            case TYPE_STRING_1:
            case TYPE_STRING_2:
            case TYPE_STRING_3:
            case TYPE_STRING_4:
            case TYPE_BPS_1:
            case TYPE_BPS_2:
            case TYPE_BPS_3:
            case TYPE_BPS_4:
            case TYPE_VEC8_1:
            case TYPE_VEC8_2:
            case TYPE_VEC8_3:
            case TYPE_VEC8_4:
                n = length_of_byteheader(h) - CELL;
                break;
            case TYPE_VEC16_1:
            case TYPE_VEC16_2:
                n = length_of_hwordheader(h) - CELL/2;
                break;
            case TYPE_VEC32:
                n = n/4;
                break;
            case TYPE_VECFLOAT64:
                n = n/8;
                break;
            default:
                n = n/CELL;
                break;
        }
    n--;    // c.f. mkvect
    return onevalue(fixnum_of_int(n));
}

LispObject Lstring_length(LispObject, LispObject v)
{   Header h;
    int32_t n;
    if (!is_vector(v)) return aerror1("string-length", v);
    h = vechdr(v);
    if (!is_string_header(h)) return aerror1("string-length", v);
    n = length_of_byteheader(h) - CELL;
    return onevalue(fixnum_of_int(n));
}

#ifdef COMMON
LispObject Lvecbnd(LispObject, LispObject v)
{   Header h;
    int32_t n;
//
// in non segmented mode this will support BPS, but really
// you ought not to rely on that.
//
    if (!(is_vector(v))) return aerror1("vector-bound", v);
    h = vechdr(v);
    n = length_of_header(h) - CELL;
#ifdef EXPERIMENT
// UNRECONSTRUCTED here -- see code in upbv for hints. But at present this is
// disabled by the "#ifdef COMMON" so is not a pressing issue.
#error unreconstructed
#endif
    if (is_bitvec_header(h))
    {   n = (n - 1)*8;
        n += ((h & 0x380) >> 7) + 1;
    }
    else switch (type_of_header(h))
        {   case TYPE_STRING:
            case TYPE_BPS:
                n = length_of_byteheader(h) - CELL;
                break;
            case TYPE_VEC16:
                n = length_of_hwordheader(h) - CELL/2;
                break;
            case TYPE_VEC32:
                n = n/4;
                break;
            case TYPE_VECFLOAT64:
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

//
// The following were added for efficiency reasons, MCD 14/8/96
//

LispObject list_subseq(LispObject sequence, int32_t start, int32_t end)
{   LispObject copy, last, new, seq=sequence;
    int32_t seq_length, pntr = start;

    seq_length = end - start;

// Find start of subsequence
    while (consp(seq) && pntr > 0)
    {   pntr--;
        seq = qcdr(seq);
    }
    if (!consp(seq)) return aerror1("subseq",sequence);

    copy = nil;

// Store the values
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

LispObject vector_subseq(LispObject sequence, int32_t start, int32_t end)
{   LispObject copy;
    Header h;
    int32_t hl, seq_length, i;

    if (is_cons(sequence))
        return list_subseq(sequence,start,end);
    else if (!is_vector(sequence))
        return aerror1("vector-subseq*",sequence);

    seq_length = end - start;

    h = vechdr(sequence);

    if (type_of_header(h) == TYPE_SIMPLE_VEC )
    {   hl = (length_of_header(h) - CELL)/CELL;
        if (hl < end) return aerror0("vector-subseq* out of range");

        //
        // Since we are dealing with a simple vector the following shift is
        // guarenteed to work.  The extra CELL bytes are for the header.
        //
        copy = getvector_init(CELL+seq_length*CELL,nil);
        for (i=start; i < end; ++i) elt(copy,i-start) = elt(sequence,i);

        return onevalue(copy);
    }
    else if (is_string_header(h))
    {   char *s;
        int32_t k;

        hl = length_of_byteheader(h) - CELL;
        if (hl < end) return aerror0("vector-subseq* out of range");

        // Get a new string of the right size
        push(sequence);
        copy = getvector(TAG_VECTOR, TYPE_STRING_4, CELL+seq_length+3);
        pop(sequence);

        // This code plagiarised from copy_string ...
        s = (char *)copy - TAG_VECTOR;
        k = (seq_length + 3) & ~(int32_t)7;
        errexit();
        *(int32_t *)(s + k + CELL) = 0;
        if (k != 0) *(int32_t *)(s + k) = 0;

        memcpy(s + CELL, (char *)sequence+(CELL-TAG_VECTOR)+start, (size_t)seq_length);

        return onevalue(copy);
    }
    else if (is_bitvec_header(h))
    {   hl = length_of_header(h) - CELL;
        if (hl < end/8) return aerror0("vector-subseq* out of range");

        // Grab a bit-vector of the right size
        push(sequence);
        copy = Lmake_simple_bitvector(nil,fixnum_of_int(seq_length));
        pop(sequence);
        errexit();

        //
        // This is not terribly efficient since the calls to Lbputv and Lbgetv
        // ought to be coded inline, but on the other hand its no worse than the
        // original Lisp-coded version.
        //
        for (i=start; i<end; ++i)
        {   push2(sequence,copy);
            Lbputv(nil,3,copy,fixnum_of_int(i-start),
                   Lbgetv(nil,sequence,fixnum_of_int(i)));
            pop2(copy,sequence);
            errexit();
        }

        return onevalue(copy);
    }
    else if (type_of_header(h) == TYPE_ARRAY)
    {   // elt(sequence, 1) is the list of dimensions - only handle 1-d case
        if (qcdr(elt(sequence, 1)) != nil)
            return aerror1("vector-subseq*",sequence);
        i = int_of_fixnum(elt(sequence, 3));  // displaced-index-offset
        return vector_subseq(elt(sequence,2),start+i,end+i);
    }
    else
        return aerror1("vector-subseq*",sequence);
}

LispObject Llist_subseq1(LispObject env, LispObject seq, LispObject start)
{   LispObject len;
    int32_t first, last;

    first = int_of_fixnum(start);
    push(seq);
    len = Llength(nil,seq);
    pop(seq);
    errexit();
//
    /**// For super-long sequences the length may not be a fixnum!
//
    last = int_of_fixnum(len);

    if (first > last) return aerror1("list-subseq* out of range",seq);

    return list_subseq(seq, first, last);
}

LispObject Llist_subseq2(LispObject env, int32_t nargs, ...)
{   va_list args;
    int32_t first, last;
    LispObject seq, start, end;
    argcheck(nargs, 3, "list-subseq*");
    va_start(args, nargs);
    seq   = va_arg(args, LispObject);
    start = va_arg(args, LispObject);
    end   = va_arg(args, LispObject);
    va_end(args);

    first = int_of_fixnum(start);
    last  = int_of_fixnum(end);
    if (first > last) return aerror1("list-subseq* out of range",seq);

    return list_subseq(seq, first, last);
}

LispObject Lvector_subseq1(LispObject env, LispObject seq, LispObject start)
{   LispObject len;
    int32_t first, last;

    first = int_of_fixnum(start);
    push(seq);
    len = Llength(nil,seq);
    pop(seq);
    errexit();

//
// For super-long list sequences the length may not be a fixnum, but
// for vectors I should be safe.
//
    last = int_of_fixnum(len);

    if (first > last) return aerror1("vector-subseq* out of range",seq);

    return vector_subseq(seq, first, last);
}

LispObject Lvector_subseq2(LispObject env, int32_t nargs, ...)
{   va_list args;
    int32_t first, last;
    LispObject seq, start, end;
    argcheck(nargs, 3, "vector-subseq*");
    va_start(args, nargs);
    seq   = va_arg(args, LispObject);
    start = va_arg(args, LispObject);
    end   = va_arg(args, LispObject);
    va_end(args);

    first = int_of_fixnum(start);
    last  = int_of_fixnum(end);
    if (first > last) return aerror1("vector-subseq* out of range",seq);

    return vector_subseq(seq, first, last);
}

#else
//
// This definition is so that exports and imports can be the same in
// both COMMON and regular cases.
//
LispObject Lvectorp(LispObject env, LispObject a)
{   return Lsimple_vectorp(nil, a);
}

#endif

setup_type const funcs3_setup[] =
{   {"getv",                    too_few_2, Lgetv, wrong_no_2},
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
    {"allocate-string",         Lsmkvect, too_many_1, wrong_no_1},
    {"putv-char",               wrong_no_3a, wrong_no_3b, Lsputv},
    {"string-store",            wrong_no_3a, wrong_no_3b, Lsputv},
    {"string-store1",           wrong_no_3a, wrong_no_3b, Lsputv},
    {"string-store2",           wrong_no_3a, wrong_no_3b, Lsputv2},
    {"string-store3",           wrong_no_3a, wrong_no_3b, Lsputv3},
    {"string-store4",           wrong_no_3a, wrong_no_3b, Lsputv4},
    {"bps-putv",                wrong_no_3a, wrong_no_3b, Lbpsputv},
    {"bps-getv",                too_few_2, Lbpsgetv, wrong_no_2},
    {"bps-upbv",                Lbpsupbv, too_many_1, wrong_no_1},
#ifdef REINSTATE_NATIVE_CODE_EXPERIMENT
    {"native-type",             wrong_no_na, wrong_no_nb, Lnative_type},
    {"native-putv",             wrong_no_3a, wrong_no_3b, Lnativeputv},
    {"native-getv",             too_few_2, Lnativegetv, Lnativegetvn},
    {"native-address",          Lnative_address1, Lnative_address, wrong_no_2},
#endif
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
    {"upbv",                    Lupbv, too_many_1, wrong_no_1},
    {"string-length",           Lstring_length, too_many_1, wrong_no_1},
    {"getv-bit",                too_few_2, Lbgetv, wrong_no_2},
    {"sbit",                    too_few_2, Lbgetv, wrong_no_2},
    {"make-simple-bitvector",   Lmake_simple_bitvector, too_many_1, wrong_no_1},
    {"putv-bit",                wrong_no_3a, wrong_no_3b, Lbputv},
    {"sbitset",                 wrong_no_3a, wrong_no_3b, Lbputv},
#ifdef COMMON
    {"hashtable-flavour",       Lhash_flavour, too_many_1, wrong_no_1},
    {"make-simple-vector",      Lmksimplevec, too_many_1, wrong_no_1},
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
// The "x" is temporary while I debug
    {"xcopy-vector",            Lcopy_vector, too_many_1, wrong_no_1},
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

// end of fns3.cpp
