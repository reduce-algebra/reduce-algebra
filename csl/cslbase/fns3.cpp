// fns3.cpp                                Copyright (C) 1989-2022 Codemist

//
// Basic functions part 3.
// A concentration on vector and array access code here.
//

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
{   size_t n1;
    if (!is_fixnum(n) ||
        n < fixnum_of_int(-1)) return aerror1("mkvect", n);
    n1 = (1 + int_of_fixnum(n))*CELL;
// Oh! What an abomination! Standard Lisp allocated 0::n, while Common
// allocates n items, ie 0::n-1.
// Note that this allows the user to go (mkvect -1) to make a vector with
// no elements at all. This is mildly odd. But it is a consequence of agreeing
// that (mkvect 0) will make a vector of length 1.
    return onevalue(get_vector_init(n1+CELL, nil));
}

LispObject Lmksimplevec(LispObject env, LispObject n)
{   size_t n1;
    if (!is_fixnum(n) ||
        n < fixnum_of_int(-1)) return aerror1("make-simple-vector", n);
    n1 = (1+int_of_fixnum(n))*CELL;
    return onevalue(get_vector_init(n1+CELL, nil));
}

//
// This one creates a "structure" tagged vector.
//

LispObject Lmkevect(LispObject env, LispObject n)
{   size_t n1;
    if (!is_fixnum(n) ||
        n < fixnum_of_int(-1)) return aerror1("mkevect", n);
    n1 = (1+int_of_fixnum(n))*CELL;
// For now I will restrict the size here.
    n = get_basic_vector_init(n1+CELL, nil);
    errexit();
    setvechdr(n, vechdr(n) ^ (TYPE_SIMPLE_VEC ^ TYPE_STRUCTURE));
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
    if (!is_fixnum(n) ||
        n < fixnum_of_int(-1)) return aerror1("mkxvect", n);
    n1 = (1+int_of_fixnum(n))*CELL;
    if (n1 < 3*CELL) return aerror1("mkxvect", n);
// size-limited.
    n = get_basic_vector_init(n1+CELL, nil);
    errexit();
    setvechdr(n, vechdr(n) ^ (TYPE_SIMPLE_VEC ^ TYPE_MIXED1));
    return onevalue(n);
}

LispObject encapsulate_pointer(void *data)
// Creates a boxed up representation of a pointer.
{   LispObject w = get_basic_vector(TAG_VECTOR, TYPE_ENCAPSULATE, 2*CELL);
    errexit();
    *(void **)&basic_elt(w, 0) = data;
    return w;
}

void *extract_pointer(LispObject a)
{   if (!is_vector(a) ||
        type_of_header(vechdr(a)) != TYPE_ENCAPSULATE)
        return nullptr;
    else return *(void **)&basic_elt(a, 0);
}

LispObject Lencapsulatedp(LispObject env, LispObject a)
{   if (is_vector(a) && type_of_header(vechdr(a)) == TYPE_ENCAPSULATE)
        return onevalue(lisp_true);
    else return nil;
}

#if 0
// The next few functions were an experiment and apply when a reference to
// a native Maple object has somehow been imported into CSL and packed
// up as an "encapsulated pointer" as per above. It was used at a time
// when I was playing by building all of Reduce as a dynamically loadable
// library and loading it into Maple... It is not supported any more.

LispObject Lmaple_atomic_value(LispObject env, LispObject a)
{   LispObject v;
    if (!is_vector(a) ||
        type_of_header(vechdr(a)) != TYPE_MAPLEREF)
        return aerror1("not an encapsulated pointer", a);
    v = static_cast<LispObject>(extract_pointer(a));
    if ((v & 1) != 0)
    {
// The next line overflows the range of CSL fixnums too early, but
// will serve as a place-holder for a while!
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
    v = static_cast<LispObject>(extract_pointer(a));
    if ((v & 1) != 0) return onevalue(nil); // an atomic value
    v1 = csl_cast<LispObject *>(v);
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
    v = static_cast<LispObject>(extract_pointer(a));
    if ((v & 1) != 0) return onevalue(nil); // an atomic value
    v1 = csl_cast<LispObject *>(v);
    v = *v1;    // the header word of the Maple object
// The following line will be incorrect on 64-bit machines
    return onevalue(fixnum_of_int(v & 0x03ffffff));
}

LispObject Lmaple_string_data(LispObject, LispObject a)
{   LispObject *p = csl_cast<LispObject *>(extract_pointer(
                        a));
    char *s = csl_cast<char *>()&p[3];
    return onevalue(make_string(s));
}

LispObject Lmaple_integer(LispObject env, LispObject a)
{   LispObject r = fixnum_of_int(0);
    LispObject *p = csl_cast<LispObject *>(extract_pointer(a));
    int i;
    LispObject t = fixnum_of_int(1);
    int len = static_cast<int>(*p & 0x03ffffff);
    THREADID;
    for (i=1; i<len; i++)
    {   int d = fixnum_of_int(static_cast<int>(p[i]));
        {   Save save(THREADARG r, t);
            d = Ltimes2(nil, d, t);
            errexit();
            save.restore(r, t);
        }
        {   Save save(THREADARG t);
            r = Lplus2(nil, r, d);
            errexit();
            save.restore(t);
        }
        Save save(THREADARG r);
        t = Ltimes2(nil, t, fixnum_of_int(10000));
        save.restore(r);
    }
    return r;
}

LispObject Lmaple_component(LispObject, LispObject a, LispObject nn)
{   LispObject v;
    LispObject *v1;
    size_t len, n;
    if (!is_fixnum(nn)) return aerror1("integer needed as selector", nn);
    if (!is_vector(a) ||
        type_of_header(vechdr(a)) != TYPE_MAPLEREF)
        return aerror1("not an encapsulated pointer", a);
    v = static_cast<LispObject>(extract_pointer(a));
    if ((v & 1) != 0) return onevalue(nil); // an atomic value
    v1 = csl_cast<LispObject *>(v);
    v = *v1;    // the header word of the Maple object
    n = int_of_fixnum(nn);
// The following line will be incorrect on 64-bit machines
    len = v & 0x03ffffff;
    if (n < 0 || n >= len) return aerror1("subscript out of range", nn);
    return onevalue(encapsulate_pointer(csl_cast<void *>
                                        (v1[n+1])));
}

#endif


// Test an integer up to 2^64 to see if it is prime. Note that despite
// its name this function will test any positive integer up to 2^64.

LispObject Lprimep32(LispObject, LispObject a)
{   uint64_t n;
    if (!is_number(a) ||
        (int64_t)(n = sixty_four_bits_unsigned(a)) == 0)
        return aerror1("primep32", a);
    return Lispify_predicate(isprime(n));
}

LispObject Lputv(LispObject, LispObject v, LispObject n, LispObject x)
{   Header h;
    size_t n1, hl;
    if (!is_vector(v)) return aerror1("putv", v);
    h = vechdr(v);
    if (type_of_header(h) == TYPE_INDEXVEC)
        h = type_of_header(vechdr(basic_elt(v,0)));
    if (vector_holds_binary(h)) return aerror1("putv", v);
    else if (!is_fixnum(n)) return aerror1("putv offset not fixnum", n);
    hl = cells_in_vector(v);
    n1 = int_of_fixnum(n);
// Note that if the index was passed as a negative value the conversion
// to type size_t will tend to make it end up large and positive, and
// in particular larger then the size of the vector.
    if (n1 >= hl) return aerror1("putv index range", n);
    write_barrier(&elt(v, n1), x);
    return onevalue(x);
}

LispObject Lgetv(LispObject, LispObject v, LispObject n)
{   Header h;
    size_t n1, hl;
    if (!is_vector(v)) return aerror1("getv", v);
    h = vechdr(v);
    if (type_of_header(h) == TYPE_INDEXVEC)
        h = type_of_header(vechdr(basic_elt(v,0)));
    if (vector_holds_binary(h)) return aerror1("getv", v);
    else if (!is_fixnum(n)) return aerror1("getv offset not fixnum", n);
    hl = cells_in_vector(v);
    n1 = int_of_fixnum(n);
    if (n1 >= hl) return aerror1("getv index range", n);
    else return onevalue(elt(v, n1));
}

// Here I make a (simple) string.

LispObject Lsmkvect(LispObject env, LispObject n)
{   LispObject w;
    size_t nn;
    if (!is_fixnum(n) || (intptr_t)n<0) return aerror1("make-simple-string", n);
    nn = int_of_fixnum(n);
    w = get_vector(TAG_VECTOR, TYPE_STRING_4, nn+CELL);
    errexit();
    nn = (intptr_t)doubleword_align_up(nn+CELL) - CELL;
    while (nn != 0)
    {   nn--;
        celt(w, nn) = 0;
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
    w = get_vector(TAG_VECTOR, TYPE_VEC8_4, nn+CELL);
    errexit();
    nn = (intptr_t)doubleword_align_up(nn+CELL) - CELL;
    while (nn != 0)
    {   nn--;
        celt(w, nn) = 0;
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
    nn = sizeof(std::int16_t)*(1 + int_of_fixnum(
                                   n)); // Note 1+ for Standard Lisp style
    w = get_vector(TAG_VECTOR, TYPE_VEC16_2, nn+CELL);
    errexit();
    nn = (intptr_t)doubleword_align_up(nn+CELL)-CELL;
    nn = nn/sizeof(std::int16_t);
    while (nn != 0)
    {   nn--;
        helt(w, nn) = 0;
    }
    return onevalue(w);
}

//
// Here I make a vector capable of holding 32-bit binary integers.
//

LispObject Lmkvect32(LispObject env, LispObject n)
{   LispObject w;
    size_t nn;
    if (!is_fixnum(n) || n<fixnum_of_int(-1)) return aerror1("mkvect32", n);
    nn = sizeof(int32_t)*(1 + int_of_fixnum(n));
// Size limited
    w = get_basic_vector(TAG_VECTOR, TYPE_VEC32, nn+CELL);
    errexit();
    nn = (intptr_t)doubleword_align_up(nn+CELL) - CELL;
    nn = nn/sizeof(int32_t);
    while (nn != 0)
    {   nn--;
        ielt32(w, nn) = 0;
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
    nn = sizeof(float)*(1 + int_of_fixnum(n));
// Size limited
    w = get_basic_vector(TAG_VECTOR, TYPE_VECFLOAT32, nn+CELL);
    errexit();
    nn = (intptr_t)doubleword_align_up(nn+CELL) - CELL;
    nn = nn/sizeof(float);
    while (nn != 0)
    {   nn--;
        felt(w, nn) = static_cast<float>(0.0);
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
    nn = sizeof(double)*(1 + int_of_fixnum(n));
    if (!SIXTY_FOUR_BIT) nn += 4; // get the doubles aligned
// Size limited
    w = get_basic_vector(TAG_VECTOR, TYPE_VECFLOAT64, nn+CELL);
    errexit();
    if (!SIXTY_FOUR_BIT) basic_elt(w, 0) = 0;
    nn = (intptr_t)nn;
    nn = nn/sizeof(double);
    while (nn != 0)
    {   nn--;
        delt(w, nn) = 0.0;
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
//@ large strings...
    if (is_string_header(h))
        return onevalue(s);                 // Already simple
    if (type_of_header(h) != TYPE_ARRAY) return aerror("simplify-string");
    h1 = basic_elt(s, 0);
    if (h1 != string_char_sym) return aerror("simplify-string");
    h1 = basic_elt(s, 1);                         // Dimension list
    if (!consp(h1)) return aerror("simplify-string");
    n = int_of_fixnum(car(h1));            // Look at size involved
    h1 = basic_elt(s, 5);                         // Fill pointer
    if (is_fixnum(h1)) n = int_of_fixnum(h1);
    THREADID;
    stackcheck(THREADARG s);
    Save save(THREADARG s);
// Size limited
    w = get_vector(TAG_VECTOR, TYPE_STRING_4, n+CELL);
    errexit();
    save.restore(s);
    errexit();
    i = (intptr_t)doubleword_align_up(n+CELL) - CELL;
    while (i != 0) // pre-fill target vector with zero
    {   i--;
        celt(w, i) = 0;
    }
    h1 = basic_elt(s, 3);
    h = int_of_fixnum(h1);               // Displace adjustment
    s = basic_elt(s, 2);
    for (i=0; i<n; i++) celt(w, i) = static_cast<char>(celt(s, i+h));
    return onevalue(w);
}

LispObject Lsputv(LispObject, LispObject v, LispObject n,
                  LispObject x)
{   Header h;
    intptr_t vx;
    size_t n1, hl;
//@ huge strings?
    if (!is_vector(v) || !is_string_header(h = vechdr(v)))
        return aerror1("putv-char", v);
    else if (!is_fixnum(n)) return aerror1("putv-char", n);
    else if (is_fixnum(x)) vx = int_of_fixnum(x);
    else if (is_char(x)) vx = code_of_char(x);
    else return aerror1("putv-char contents", x);
    hl = bytes_in_vector(v);
    n1 = int_of_fixnum(n);
    if (n1 >= hl) return aerror1("putv-char", n);
    celt(v, n1) = static_cast<char>(vx);
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

LispObject Lsputv2(LispObject, LispObject v, LispObject n,
                   LispObject x1, LispObject a4up)
{   Header h;
    intptr_t vx1, vx2;
    size_t n1, hl;
    LispObject x2 = arg4("sputv2", a4up);
    if (!is_vector(v) || !is_string_header(h = vechdr(v)))
        return aerror1("putv-char2", v);
// @ Huge strings?
    else if (!is_fixnum(n)) return aerror1("putv-char", n);
    if (is_fixnum(x1)) vx1 = int_of_fixnum(x1);
    else if (is_char(x1)) vx1 = code_of_char(x1);
    else return aerror1("putv-char2 contents", x1);
    if (is_fixnum(x2)) vx2 = int_of_fixnum(x2);
    else if (is_char(x2)) vx2 = code_of_char(x2);
    else return aerror1("putv-char2 contents", x2);
    hl = length_of_byteheader(h) - CELL;
    n1 = int_of_fixnum(n);
    if (n1+1 >= hl) return aerror1("putv-char2", n);
    celt(v, n1) = static_cast<char>(vx1);
    celt(v, n1+1) = static_cast<char>(vx2);
    return onevalue(x2);
}

LispObject Lsputv3(LispObject, LispObject v, LispObject n,
                   LispObject x1, LispObject a4up)
{   Header h;
    intptr_t vx1, vx2, vx3;
    size_t n1, hl;
    LispObject x2, x3;
    if (a4a5("sputv3", a4up, x2, x3)) return nil;
    if (!is_vector(v) || !is_string_header(h = vechdr(v)))
        return aerror1("putv-char3", v);
// @ Huge strings?
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
    if (n1+2 >= hl) return aerror1("putv-char3", n);
    celt(v, n1) = static_cast<char>(vx1);
    celt(v, n1+1) = static_cast<char>(vx2);
    celt(v, n1+2) = static_cast<char>(vx3);
    return onevalue(x3);
}

LispObject Lsputv4(LispObject, LispObject v, LispObject n,
                   LispObject x1, LispObject a4up)
{   Header h;
    intptr_t vx1, vx2, vx3, vx4;
    size_t n1, hl;
    LispObject x2, x3, x4;
    if (a4a5a6("sputv4", a4up, x2, x3, x4)) return nil;
    if (!is_vector(v) || !is_string_header(h = vechdr(v)))
        return aerror1("putv-char4", v);
// @ Huge strings?
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
    if (n1+3 >= hl) return aerror1("putv-char3", n);
    celt(v, n1) = static_cast<char>(vx1);
    celt(v, n1+1) = static_cast<char>(vx2);
    celt(v, n1+2) = static_cast<char>(vx3);
    celt(v, n1+3) = static_cast<char>(vx4);
    return onevalue(x4);
}

LispObject Lbpsupbv(LispObject, LispObject v)
{   size_t n;
    if (!is_bps(v)) return aerror1("bps-upbv", v);
    n = bytes_in_vector(v);
    return onevalue(fixnum_of_int(n-1));
}

LispObject Lbpsputv(LispObject, LispObject v, LispObject n,
                    LispObject x)
{   size_t n1, hl;
    if (!is_bps(v)) return aerror1("bpsputv", v);
    else if (!is_fixnum(n) || n < 0) return aerror1("bps-putv", n);
    else if (!is_fixnum(x)) return aerror1("bps-putv contents", x);
    hl = bytes_in_vector(v);
    n1 = int_of_fixnum(n);
    if (n1 >= hl) return aerror1("bps-putv", n);
    celt(v, n1) = static_cast<char>(int_of_fixnum(x));
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
    size_t n1, hl;
    if (!is_vector(v) || !is_string_header(h = vechdr(v)))
        return aerror1("schar on non-string", v);
    else if (!is_fixnum(n) ||
             n < 0) return aerror1("schar index type incorrect", n);
    hl = length_of_byteheader(h) - CELL;
    n1 = int_of_fixnum(n);
    if (n1 >= hl) return aerror1("schar index out of range", n);
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
    if (n1 >= hl) return aerror1("scharn", n);
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
    hl = bytes_in_vector(v);
    n1 = int_of_fixnum(n);
    if (n1 >= hl) return aerror1("byte-getv", n);
    w = ucelt(v, n1);
    return onevalue(fixnum_of_int(w));
}

LispObject Lbpsgetv(LispObject, LispObject v, LispObject n)
{   size_t n1, hl;
    if (!is_bps(v)) return aerror1("bps-getv", v);
    else if (!is_fixnum(n)) return aerror1("bps-getv", n);
    hl = bytes_in_vector(v);
    n1 = int_of_fixnum(n);
    if (n1 >= hl) return aerror1("bps-getv", n);
    n1 = ucelt(v, n1);
    return onevalue(fixnum_of_int(n1));
}

//
// Access functions for specialised (binary-contents) vectors. NOT integrated
// in with the greater generality of vector structures.
//

LispObject Lputv8(LispObject, LispObject v, LispObject n,
                  LispObject x)
{   Header h;
    size_t n1, hl;
    if (!is_vector(v) || !is_vec8_header(h = vechdr(v)))
        return aerror1("putv8", v);
    else if (!is_fixnum(n)) return aerror1("putv8 offset not fixnum", n);
    hl = length_of_byteheader(h) - CELL;
    n1 = int_of_fixnum(n);
    if (n1 >= hl) return aerror1("putv8 index range", n);
    scelt(v, n1) = static_cast<char>(int_of_fixnum(x));
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
    if (n1 >= hl) return aerror1("getv8 index range", n);
    else return onevalue(fixnum_of_int(scelt(v, n1)));
}

LispObject Lputv16(LispObject, LispObject v, LispObject n,
                   LispObject x)
{   Header h;
    size_t n1, hl;
    if (!is_vector(v) || !is_vec16_header(h = vechdr(v)))
        return aerror1("putv16", v);
    else if (!is_fixnum(n)) return aerror1("putv16 offset not fixnum", n);
    hl = length_of_hwordheader(h) - CELL/2;
    n1 = int_of_fixnum(n);
    if (n1 >= hl) return aerror1("putv16 index range", n);
    helt(v, n1) = int_of_fixnum(x);
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
    if (n1 >= hl) return aerror1("getv16 index range", n);
    n1 = helt(v, n1);
    return onevalue(fixnum_of_int(n1));
}

LispObject Lputv32(LispObject, LispObject v, LispObject n,
                   LispObject x)
{   Header h;
    size_t n1, hl;
    if (!is_vector(v) || type_of_header(h = vechdr(v)) != TYPE_VEC32)
        return aerror1("putv32", v);
    else if (!is_fixnum(n)) return aerror1("putv32 offset not fixnum", n);
    hl = (length_of_header(h) - CELL)/4;
    n1 = int_of_fixnum(n);
    if (n1 >= hl) return aerror1("putv32 index range", n);
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
    if (n1 >= hl) return aerror1("getv32 index range", n);
    n1 = ielt32(v, n1);
    return make_lisp_integer32(n1);
}

LispObject Lfputv32(LispObject, LispObject v, LispObject n,
                    LispObject x)
{   Header h;
    size_t n1, hl;
    double d = float_of_number(x);
    if (!is_vector(v) || type_of_header(h = vechdr(v)) != TYPE_VECFLOAT32)
        return aerror1("fputv32", v);
    else if (!is_fixnum(n)) return aerror1("fputv32 offset not fixnum", n);
    hl = (length_of_header(h) - CELL)/4;
    n1 = int_of_fixnum(n);
    if (n1 >= hl) return aerror1("fputv32 index range", n);
    felt(v, n1) = static_cast<float>(d);
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
    if (n1 >= hl) return aerror1("fgetv32 index range", n);
#ifdef COMMON
    v = make_boxfloat(static_cast<double>(felt(v, n1)),
                      TYPE_SINGLE_FLOAT);
#else
    v = make_boxfloat(static_cast<double>(felt(v, n1)),
                      TYPE_DOUBLE_FLOAT);
#endif
    return onevalue(v);
}

LispObject Lfputv64(LispObject, LispObject v, LispObject n,
                    LispObject x)
{   Header h;
    size_t n1, hl;
    double d = float_of_number(x);
    if (!is_vector(v) || type_of_header(h = vechdr(v)) != TYPE_VECFLOAT64)
        return aerror1("fputv64", v);
    else if (!is_fixnum(n)) return aerror1("fputv64 offset not fixnum", n);
// NB it is not a misprint - the first double ALWAYS starts 8 bytes in...
    hl = (length_of_header(h) - 8)/8;
    n1 = int_of_fixnum(n);
    if (n1 >= hl) return aerror1("fputv64 index range", n);
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
    if (n1 >= hl) return aerror1("fgetv64 index range", n);
    v = make_boxfloat(delt(v, n1), TYPE_DOUBLE_FLOAT);
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
    size_t n = CELL;
//
// The general LENGTH function deals with vectors as well as lists, and
// returns a Lisp integer result. So here I just write out a simple in-line
// version.
//
    for (v=a; consp(v); v = cdr(v)) n += CELL;
    THREADID;
    Save save(THREADARG a);
    v = get_vector(TAG_VECTOR, TYPE_SIMPLE_VEC, n);
    errexit();
    save.restore(a);
    for(n=0; consp(a); a = cdr(a), n++)
        elt(v, n) = static_cast<LispObject>(car(a));
    return onevalue(v);
}


//
// (defun putvec (v n x)
//    (cond
//       ((simple-string-p v) (putv-char v n x))
//       ((simple-bit-vector-p v) (putv-bit v n x))
//       (t (putv v n x))))
//

UNUSED_NAME static LispObject Lputvec(LispObject, LispObject v, LispObject n,
                          LispObject x)
{   Header h;
    intptr_t vx;
    size_t n1, hl;
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
        if (int_of_fixnum(n) < 0) return aerror1("putvec", n);
        n1 = int_of_fixnum(n);
        if (n1 >= hl) return aerror1("putvec", n);
        celt(v, n1) = static_cast<int>(vx);
        return onevalue(x);
    }
    if (is_bitvec_header(h))
    {   int b;
        if (!is_fixnum(x)) return aerror1("putvec on bitvec, contents", x);
        x = int_of_fixnum(x) & 1;
        n1 = int_of_fixnum(n);
        b = 1 << (n1 & 7);     // Bit selector
        n1 = n1 >> 3;          // Byte selector
        if (n1 >= length_of_bitheader(h)-8*CELL) return aerror1("putv-bit", n);
        n1 = n1 >> 3;          // Byte selector
        if (x == 0) celt(v, n1) &= ~b;
        else        celt(v, n1) |= b;
        return onevalue(fixnum_of_int(x));
    }
    if (vector_holds_binary(h)) return aerror1("putvec", v);
    hl = (length_of_header(h) - CELL)/CELL;
    n1 = int_of_fixnum(n);
    if (n1 >= hl) return aerror1("putvec index range", n);
    write_barrier(&elt(v, n1), x);
    return onevalue(x);
}

#ifdef DO_AREF_AND_ASET_LATER

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
    size_t hl, n1;
    intptr_t b;
    std::va_list a;
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
                if (n1 >= hl) return aerror1("aref index range", n);
                else return onevalue(elt(v, n1));
            }
            else if (is_string_header(h))
            {   va_end(a);
                hl = length_of_byteheader(h) - CELL;
                n1 = int_of_fixnum(n);
                if (n1 >= hl) return aerror1("aref index range", n);
                return onevalue(pack_char(0, celt(v, n1)));
            }
            else if (is_bitvec_header(h))
            {   va_end(a);
                n1 = int_of_fixnum(n);
                b = 1 << (n1 & 7);     // Bit selector
                if (n1 >= length_of_bitheader(h)-8*CELL)
                    return aerror1("aref index range", n);
                n1 = n1 >> 3;          // Byte selector
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
    w = cdr(w);
    while (nargs > 2 && w != nil)
    {   n = va_arg(a, LispObject);
        if (!is_fixnum(n))
        {   va_end(a);
            return aerror1("aref", n);
        }
        n1 = n1*int_of_fixnum(car(w)) + int_of_fixnum(n);
        nargs--;
        w = cdr(w);
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
        if (n1 >= hl) return aerror("aref index range");
        else return onevalue(elt(v, n1));
    }
    else if (type_of_header(h) == TYPE_STRUCTURE)
    {   size_t n2;
        hl = int_of_fixnum(elt(v, 0));
        if (n1 >= hl) return aerror("aref index range");
        n2 = n1 % 8192;
        n1 = n1 / 8192;
        return onevalue(elt(elt(v, n1+1), n2));
    }
    else if (is_string_header(h))
    {   hl = length_of_byteheader(h) - CELL;
        if (n1 >= hl) return aerror("aref index range");
        return onevalue(pack_char(0, celt(v, n1)));
    }
    else if (is_bitvec_header(h))
    {   b = 1 << (n1 & 7);     // Bit selector
        if (n1 >= length_of_bitheader(h) - 8*CELL) return aerror("aref index range");
        n1 = n1 >> 3;          // Byte selector
        if ((celt(v, n1) & b) == 0) return onevalue(fixnum_of_int(0));
        else return onevalue(fixnum_of_int(1));
    }
    return aerror("aref unknown type for vector representation");
}

static LispObject Laref_1(LispObject env, LispObject a)
{   return Laref(env, 1, a);
}

LispObject Laref_2(LispObject env, LispObject a, LispObject b)
{   return Laref(env, 2, a, b);
}

#else

LispObject Laref_1(LispObject env, LispObject a)
{   return aerror("aref");
}

LispObject Laref_2(LispObject env, LispObject a, LispObject n)
{   return aerror("aref");
}

LispObject Laref_3(LispObject env, LispObject a, LispObject n1,
                   LispObject n2)
{   return aerror("aref");
}

LispObject Laref_a4up(LispObject env, LispObject a, LispObject n1,
                      LispObject n2, LispObject n3up)
{   return aerror("aref");
}

LispObject Laset_1(LispObject env, LispObject a)
{   return aerror("aset");
}

LispObject Laset_2(LispObject env, LispObject a, LispObject n)
{   return aerror("aset");
}

LispObject Laset_3(LispObject env, LispObject a, LispObject n1,
                   LispObject n2)
{   return aerror("aset");
}

LispObject Laset_a4up(LispObject env, LispObject a, LispObject n1,
                      LispObject n2, LispObject n3up)
{   return aerror("aset");
}

#endif // DO_AREF_AND_ASET_LATER

LispObject Lelt(LispObject env, LispObject v, LispObject n)
{   Header h;
    LispObject w;
    size_t hl, n1;
    intptr_t b;
    if (!is_fixnum(n) || ((size_t)n) < 0) return aerror1("elt", n);
    n1 = int_of_fixnum(n);
    if (!is_vector(v))
    {   w = v;
        while (consp(w) && n1>0)
        {   n1--;
            w = cdr(w);
        }
        if (!consp(w)) return aerror1("elt", v);
        return onevalue(car(w));
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
    {   b = 1 << (n1 & 7);     // Bit selector
        n1 = n1 >> 3;          // Byte selector
        if (n1 >= length_of_bitheader(h) - 8*CELL)
            return aerror1("elt index range", n);
        if ((celt(v, n1) & b) == 0) return onevalue(fixnum_of_int(0));
        else return onevalue(fixnum_of_int(1));
    }
    if (type_of_header(h) != TYPE_ARRAY) return aerror1("elt", v);
    w = elt(v, 1);   // The list of dimensions - must be 1 dim here
    w = cdr(w);
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
    {   size_t n2;
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
        if (n1 >= h) return aerror("elt index range");
        if ((celt(v, n1) & b) == 0) return onevalue(fixnum_of_int(0));
        else return onevalue(fixnum_of_int(1));
    }
    return aerror("elt unknown type for vector representation");
}

#ifdef DO_AREF_AND_ASET_LATER

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

LispObject Laset_4up(LispObject env, int nargs, ...)
{   Header h;
    LispObject v, n, w, x;
    size_t hl, n1;
    intptr_t b;
    std::va_list a;
    if (nargs < 2) return aerror("aset");
    va_start(a, nargs);
    v = va_arg(a, LispObject);
    if (!is_vector(v))
    {   va_end(a);
        return aerror1("aset", v);
    }
    h = vechdr(v);
    if (nargs == 2) n =
            0;  // Funny case (aset v w) legal if no dimensions!
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
                if (n1 >= hl) return aerror1("aset index range", n);
                write_barrier(&elt(v, n1), x);
                return onevalue(x);
            }
            else if (is_string_header(h))
            {   x = va_arg(a, LispObject);
                va_end(a);
                hl = length_of_byteheader(h) - CELL;
                n1 = int_of_fixnum(n);
                if (n1 >= hl) return aerror1("aset index range", n);
                if (is_fixnum(x)) b = int_of_fixnum(x);
                else if (is_char(x)) b = code_of_char(x);
                else return aerror1("aset needs char", x);
                celt(v, n1) = b;
                return onevalue(x);
            }
            else if (is_bitvec_header(h))
            {   x = va_arg(a, LispObject);
                va_end(a);
                n1 = int_of_fixnum(n);
                b = 1 << (n1 & 7);     // Bit selector
                n1 = n1 >> 3;          // Byte selector
                if (n1 >= length_of_bitheader(h)-8*CELL)
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
        write_barrier(&elt(v, 2), x);
        return onevalue(x);
    }
    n1 = int_of_fixnum(n);
    w = cdr(w);
    while (nargs > 3 && w != nil)
    {   n = va_arg(a, LispObject);
        if (!is_fixnum(n))
        {   va_end(a);
            return aerror1("aset", n);
        }
        n1 = n1*int_of_fixnum(car(w)) + int_of_fixnum(n);
        nargs--;
        w = cdr(w);
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
        if (n1 >= hl) return aerror("aset index range");
        write_barrier(&elt(v, n1), x);
        return onevalue(x);
    }
    if (type_of_header(h) == TYPE_STRUCTURE)
    {   size_t n2;
        hl = int_of_fixnum(elt(v, 0));
        if (n1 >= hl) return aerror("aset index range");
        n2 = n1 % 8192;
        n1 = n1 / 8192;
        write_barrier(&elt(elt(v, n1+1), n2), x);
        return onevalue(x);
    }
    else if (is_string_header(h))
    {   hl = length_of_byteheader(h) - CELL;
        if (n1 >= hl) return aerror("aset index range");
        if (is_fixnum(x)) b = int_of_fixnum(x);
        else if (is_char(x)) b = code_of_char(x);
        else return aerror1("aset needs char", x);
        celt(v, n1) = b;
        return onevalue(x);
    }
    else if (is_bitvec_header(h))
    {   b = 1 << (n1 & 7);     // Bit selector
        if (n1 >= length_of_bitheader(h) - 8*CELL)
            return aerror("aset index range");
        n1 = n1 >> 3;          // Byte selector
        if (!is_fixnum(x)) return aerror1("aset needs bit", x);
        if (int_of_fixnum(x) & 1) ucelt(v, n1) |= b;
        else ucelt(v, n1) &= ~b;
        return onevalue(x);
    }
    return aerror("aset unknown type for vector representation");
}

static LispObject Laset_1(LispObject env, LispObject a)
{   return aerror("aset");
}

static LispObject Laset_2(LispObject env, LispObject a, LispObject b)
{   return Laset(env, 2, a, b);
}

#endif  // DO_AREF_AND_ASET_LATER

UNUSED_NAME static LispObject Lsetelt(LispObject env, LispObject v,
                                      LispObject n, LispObject x)
{   Header h;
    LispObject w;
    size_t hl, n1;
    intptr_t b;
    if (!is_fixnum(n) || n < 0) return aerror1("setelt", n);
    n1 = int_of_fixnum(n);
    if (!is_vector(v))
    {   w = v;
        while (consp(w) && n1>0)
        {   n1--;
            w = cdr(w);
        }
        if (!consp(w)) return aerror1("setelt", v);
        write_barrier(caraddr(w), x);
        return onevalue(x);
    }
    h = vechdr(v);
    if (type_of_header(h) == TYPE_SIMPLE_VEC ||
        type_of_header(h) == TYPE_STRUCTURE)
    {   hl = (length_of_header(h) - CELL)/CELL;
        if (n1 >= hl) return aerror1("setelt index range", n);
        write_barrier(&elt(v, n1), x);
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
        if (n1 >= h)
            return aerror1("setelt index range", n);
        if (x == 0) celt(v, n1) &= ~b;
        else celt(v, n1) |= b;
        return onevalue(fixnum_of_int(x));
    }
    if (type_of_header(h) != TYPE_ARRAY) return aerror1("setelt", v);
    w = elt(v, 1);   // The list of dimensions - must be 1 dim here
    w = cdr(w);
    if (w != nil) return aerror1("setelt", v);
    n1 += int_of_fixnum(elt(v, 3));  // displaced-index-offset
    v = elt(v, 2);
    h = vechdr(v);
    if (type_of_header(h) == TYPE_SIMPLE_VEC)
    {   hl = (length_of_header(h) - CELL)/CELL;
        if (n1 >= hl) return aerror("setelt index range");
        write_barrier(&elt(v, n1), x);
        return onevalue(x);
    }
    else if (type_of_header(h) == TYPE_STRUCTURE)
    {   size_t n2;
        hl = int_of_fixnum(elt(v, 0));
        if (n1 >= hl) return aerror("setelt index range");
        n2 = n1 % 8192;
        n1 = n1 / 8192;
        write_barrier(&elt(elt(v, n1+1), n2), x);
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
        if (n1 >= h) return aerror("setelt index range");
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
    int tt;
    if (!is_vector(a)) return onevalue(nil);
    h = vechdr(a);
    tt = type_of_header(h);
    if (tt == TYPE_SIMPLE_VEC ||
        is_string_header(h) ||
        is_bitvec_header(h)) return onevalue(lisp_true);
    if (tt == TYPE_ARRAY)
    {   a = elt(a, 1);   // List of dimensions
        if (consp(a) && !consp(cdr(a))) return onevalue(lisp_true);
    }
    return onevalue(nil);
}

//
// (defun char (s n)
//    (cond
//       ((simple-string-p s) (schar s n))
//       (t (aref s n))))
//

UNUSED_NAME static LispObject Lchar(LispObject env, LispObject v, LispObject n)
{   Header h;
    if (!is_vector(v)) return aerror("char");
    h = vechdr(v);
    if (is_string_header(h))
    {   size_t hl, n1;
        if (!is_fixnum(n)) return aerror1("char", n);
        hl = length_of_byteheader(h) - CELL;
        n1 = int_of_fixnum(n);
        if (n1 >= hl) return aerror1("schar", n);
        return onevalue(pack_char(0, celt(v, n1)));
    }
#ifdef DO_AREF_AND_ASET_LATER
    return Laref_2(nil, v, n);
#else
    return aerror("no AREF yet");
#endif
}

//
// (defun charset (s n c)
//    (cond
//       ((simple-string-p s) (putv-char s n c))
//       (t (aset s n c))))
//

UNUSED_NAME static LispObject Lcharset(LispObject env, LispObject v, LispObject n,
                           LispObject c)
{   Header h;
    if (!is_vector(v)) return aerror1("charset", v);
    h = vechdr(v);
    if (!is_fixnum(n)) return aerror1("charset", n);
    if (is_string_header(h))
    {   size_t hl, n1;
        intptr_t vx;
        if (!is_fixnum(n)) return aerror1("charset", n);
        hl = length_of_byteheader(h) - CELL;
        if (is_fixnum(c)) vx = int_of_fixnum(c);
        else if (is_char(c)) vx = code_of_char(c);
        else return aerror1("charset contents", c);
        n1 = int_of_fixnum(n);
        if (n1 >= hl) return aerror1("charset", n);
        celt(v, n1) = static_cast<int>(vx);
        return onevalue(c);
    }
#ifdef DO_AREF_AND_ASET_LATER
    return Laset(nil, 3, v, n, c);
#else
    return aerror("no aset yet");
#endif
}

//
// (defun make-string (len &key (initial-element #\ ))
//    (let ((s (make-simple-string len)))
//       (dotimes (i len) (charset s i initial-element))
//       s))
//

UNUSED_NAME static LispObject Lmake_string_3(LispObject env, LispObject n,
                                 LispObject key, LispObject init)
{   LispObject w;
    intptr_t nn, blanks;
    size_t z;
    if (!is_fixnum(n) || (intptr_t)n<0) return aerror1("make-string", n);
    if (!is_char(init) && !is_fixnum(init))
        return aerror1("make-string", init);
    if (key != initial_element) return aerror1("make-string", key);
    nn = int_of_fixnum(n);
// Size limited
    w = get_basic_vector(TAG_VECTOR, TYPE_STRING_4, nn+CELL);
    errexit();
    z = (size_t)doubleword_align_up(nn+CELL);
    if (is_char(init)) blanks = code_of_char(init);
    else blanks = int_of_fixnum(init);
    blanks = (blanks << 8) | blanks;
    blanks = (blanks << 16) | blanks;
    while (z > CELL)
    {   z -= 4;
        *(int32_t *)(csl_cast<char *>(w) - TAG_VECTOR + z) = blanks;
    }
    nn = nn + CELL;
    while ((nn & 7) != 0)
    {   *(csl_cast<char *>(w) - TAG_VECTOR + nn) = 0;
        nn++;
    }
    return onevalue(w);
}

UNUSED_NAME static LispObject Lmake_string_1(LispObject env, LispObject n)
{   LispObject w;
    intptr_t nn, blanks;
    size_t z;
    if (!is_fixnum(n) || (intptr_t)n<0) return aerror1("make-string", n);
    nn = int_of_fixnum(n);
// Size limited
    w = get_basic_vector(TAG_VECTOR, TYPE_STRING_4, nn+CELL);
    errexit();
    z = (size_t)doubleword_align_up(nn+CELL);
    blanks = (' ' << 24) | (' ' << 16) | (' ' << 8) | ' ';
    while (z > CELL)
    {   z -= 4;
        *(int32_t *)(csl_cast<char *>(w) - TAG_VECTOR + z) = blanks;
    }
    nn = nn + CELL;
    while ((nn & 7) != 0)
    {   *(csl_cast<char *>(w) - TAG_VECTOR + nn) = 0;
        nn++;
    }
    return onevalue(w);
}

//
// (defun string (x)
//    (cond
//       ((stringp x) x)
//       ((symbolp x) (symbol-name x))
//       ((string-char-p x) (make-string 1 :initial-element x))
//       (t (error "String expected, but found ~S" x))))
//

UNUSED_NAME static LispObject Lstring(LispObject env, LispObject a)
{   Header h;
    LispObject w;
    if (!is_vector(a))
    {   char dd[4];
        if (symbolp(a)) return onevalue(qpname(a));
        if (!is_char(a)) return aerror1("string", a);
        dd[0] = 'x'; // Done this way in case character arg has code 0
        dd[1] = 0;
        w = make_string(dd);
        celt(w, 0) = code_of_char(a);
        return onevalue(w);
    }
    h = vechdr(a);
    if (is_string_header(h)) return onevalue(a);
    else if (type_of_header(h) != TYPE_ARRAY) return aerror1("string", a);
//
// Beware abolition of 'string-char
//
    else if (static_cast<LispObject>(elt(a,
                                         0)) != string_char_sym) return aerror1("string", a);
    w = elt(a, 1);
    if (!consp(w) || consp(cdr(w))) return aerror1("string", a);
    else return onevalue(a);
}

//
// (defun copy-vector (old)
// ;; At present this only copies general vectors...
//    (let* ((len (vector-bound old))
//           (new (make-simple-vector len)))
//       (dotimes (i len new) (putv new i (svref old i)))))
//

UNUSED_NAME static LispObject Lcopy_vector(LispObject env, LispObject a)
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

LispObject Lvector_4up(LispObject env, LispObject a1, LispObject a2,
                       LispObject a3, LispObject a4up)
{   LispObject r = nil;
    size_t n = 3;
    for (LispObject x=a4up; x!=nil; x=cdr(x)) n++;
    THREADID;
    Save save(THREADARG a1, a2, a3, a4up);
    r = get_vector(TAG_VECTOR, TYPE_SIMPLE_VEC, CELL*(n+1));
    errexit();
    save.restore(a1, a2, a3, a4up);
    write_barrier(&elt(r, 0), a1);
    write_barrier(&elt(r, 1), a2);
    write_barrier(&elt(r, 2), a3);
    for (size_t i=3; i<n; i++)
    {   write_barrier(&elt(r, i), car(a4up));
        a4up = cdr(a4up);
    }
    return onevalue(r);
}

LispObject Lvector_0(LispObject env)
{   return onevalue(get_vector(TAG_VECTOR, TYPE_SIMPLE_VEC, CELL));
}

LispObject Lvector_1(LispObject env, LispObject a)
{   THREADID;
    Save save(THREADARG a);
    LispObject r = get_vector(TAG_VECTOR, TYPE_SIMPLE_VEC, 2*CELL);
    errexit();
    save.restore(a);
    write_barrier(&elt(r, 0), a);
    return onevalue(r);
}

LispObject Lvector_2(LispObject env, LispObject a, LispObject b)
{   THREADID;
    Save save(THREADARG a, b);
    LispObject r = get_vector(TAG_VECTOR, TYPE_SIMPLE_VEC, 3*CELL);
    errexit();
    save.restore(a, b);
    write_barrier(&elt(r, 0), a);
    write_barrier(&elt(r, 1), b);
    return onevalue(r);
}

LispObject Lvector_3(LispObject env, LispObject a, LispObject b,
                     LispObject c)
{   THREADID;
    Save save(THREADARG a, b, c);
    LispObject r = get_vector(TAG_VECTOR, TYPE_SIMPLE_VEC, 4*CELL);
    errexit();
    save.restore(a, b, c);
    write_barrier(&elt(r, 0), a);
    write_barrier(&elt(r, 1), b);
    write_barrier(&elt(r, 2), c);
    return onevalue(r);
}


UNUSED_NAME static LispObject Lshrink_vector(LispObject env,
                                 LispObject v, LispObject n)
{   size_t n1, n2;
    if (!is_vector(v)) return aerror1("shrink-vector", v);
    if (!is_fixnum(n)) return aerror1("shrink-vector", n);
    n1 = length_of_header(vechdr(v));
    n2 = CELL*int_of_fixnum(n)+CELL;
    if (n2 >= n1) return onevalue(v);  // Not shrunk at all
// In a previous version of this code I put a fake vector into any
// released space, so that linear scans of the heap were still possible.
// These days my garbage collector (and other code) never relies on
// such scans, so I simplify the code here.
    size_t adjustment = n1 - n2;  // number of bytes to shrink by
    setvechdr(v, vechdr(v) - pack_hdrlength(adjustment/4));
    return onevalue(v);
}

static LispObject Lmake_simple_bitvector(LispObject env, LispObject n)
{   size_t bytes;
    LispObject w;
    size_t n1;
    if (!is_fixnum(n) || n<0)
        return aerror1("make-simple-bitvector", n);
    n1 = int_of_fixnum(n);
    bytes = CELL+(n1+7)/8;
// Size limited
    w = get_basic_vector(TAG_VECTOR, bitvechdr_(n1), bytes);
    errexit();
    n1 = doubleword_align_up(bytes);
    while (n1 > CELL)
    {   n1 -= 4;
        *(int32_t *)(csl_cast<char *>(w) - TAG_VECTOR + n1) = 0;
    }
    return onevalue(w);
}

static LispObject Lbputv(LispObject, LispObject v, LispObject n,
                         LispObject x)
{   Header h;
    int b;
    size_t n1;
// This code is WRONG at present in that unexpectedly it is supposed to
// support bit-arrays of arbitrary rank, and not just simple vectors.
// But only wrong for Common Lisp.
    if (!(is_vector(v)) || !is_bitvec_header(h = vechdr(v)))
        return aerror1("putv-bit", v);
    if (!is_fixnum(n)) return aerror1("putv-bit", n);
    if (!is_fixnum(x)) return aerror1("putv-bit contents", x);
    x = int_of_fixnum(x) & 1;
    n1 = int_of_fixnum(n);
    b = 1 << (n1 & 7);     // Bit selector
    if (n1 >= length_of_bitheader(h) - 8*CELL) return aerror1("putv-bit", n);
    n1 = n1 >> 3;          // Byte selector
    if (x == 0) ucelt(v, n1) &= ~b;
    else        ucelt(v, n1) |= b;
    return onevalue(fixnum_of_int(x));
}

static LispObject Lbgetv(LispObject, LispObject v, LispObject n)
{   Header h;
    int b;
    size_t n1;
//
// This code is WRONG at present in that unexpectedly it is supposed to
// support bit-arrays of arbitrary rank, and not just simple vectors.
//
    if (!(is_vector(v)) || !is_bitvec_header(h = vechdr(v)))
        return aerror1("getv-bit", v);
    if (!is_fixnum(n) || n < 0) return aerror1("getv-bit", n);
    n1 = int_of_fixnum(n);
    b = 1 << (n1 & 7);     // Bit selector
    if (n1 >= length_of_bitheader(h) - 8*CELL) return aerror1("getv-bit", n);
    n1 = n1 >> 3;          // Byte selector
    if ((ucelt(v, n1) & b) == 0)
        return onevalue(fixnum_of_int(0));
    else return onevalue(fixnum_of_int(1));
}

LispObject Lupbv(LispObject env, LispObject v)
{   Header h;
    size_t n;
    if (!(is_vector(v))) return onevalue(nil); // Standard Lisp demands..
    h = vechdr(v);
    n = length_of_header(h) - CELL;
#ifdef COMMON
// The next bit is WRONG at present...
    if (is_bitvec_header(h))
    {   n = (n - 1)*8;
        n += ((h & 0x380) >> 7) + 1;
    }
    else
#endif
        switch (type_of_header(h))
        {   case TYPE_STRING_1:
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
    size_t n;
    if (!is_vector(v)) return aerror1("string-length", v);
    h = vechdr(v);
    if (!is_string_header(h)) return aerror1("string-length", v);
    n = length_of_byteheader(h) - CELL;
    return onevalue(fixnum_of_int(n));
}

LispObject Lvecbnd(LispObject, LispObject v)
{   Header h;
    size_t n;
    if (!(is_vector(v))) return aerror1("vector-bound", v);
    h = vechdr(v);
    n = length_of_header(h) - CELL;
    if (is_bitvec_header(h)) n = length_of_bitheader(h) - 8*CELL;
    else switch (type_of_header(h))
        {   case TYPE_STRING_1:
            case TYPE_STRING_2:
            case TYPE_STRING_3:
            case TYPE_STRING_4:
            case TYPE_BPS_1:
            case TYPE_BPS_2:
            case TYPE_BPS_3:
            case TYPE_BPS_4:
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
    return onevalue(fixnum_of_int(n));
}

//
// The following were added for efficiency reasons, MCD 14/8/96
//

LispObject list_subseq(LispObject sequence, size_t start, size_t end)
{   LispObject copy, last=nil, newv, seq=sequence;
    size_t seq_length, pntr = start;

    seq_length = end - start;

// Find start of subsequence
    while (consp(seq) && pntr > 0)
    {   pntr--;
        seq = cdr(seq);
    }
    if (!consp(seq)) return aerror1("subseq",sequence);

    copy = nil;

// Store the values
    THREADID;
    Save save(THREADARG sequence);
    while (consp(seq) && pntr < seq_length)
    {   Save save1(THREADARG seq,copy,last);
        newv = Lcons(nil,car(seq),nil);
        errexit();
        save1.restore(seq, copy, last);
        if (pntr == 0) copy = newv;
        else write_barrier(cdraddr(last), newv);
        last = newv;
        seq = cdr(seq);
        pntr++;
    }
    save.restore(sequence);
    if (pntr != seq_length) return aerror1("subseq",sequence);

    return onevalue(copy);
}

LispObject vector_subseq(LispObject sequence, size_t start,
                         size_t end)
{   LispObject copy;
    Header h;
    size_t hl, seq_length, i;
    THREADID;

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
        copy = get_vector_init(CELL+seq_length*CELL,nil);
        errexit();
        for (i=start; i < end; ++i)
            write_barrier(&elt(copy,i-start),
                          static_cast<LispObject>(elt(sequence,i)));
        return onevalue(copy);
    }
    else if (is_string_header(h))
    {   char *s;
        size_t k;

        hl = length_of_byteheader(h) - CELL;
        if (hl < end) return aerror0("vector-subseq* out of range");

        // Get a new string of the right size
        Save save(THREADARG sequence);
// Size limited
        copy = get_basic_vector(TAG_VECTOR, TYPE_STRING_4, CELL+seq_length+3);
        errexit();
        save.restore(sequence);
        errexit();

        // This code plagiarised from copy_string ...
        s = csl_cast<char *>(copy) - TAG_VECTOR;
        k = (seq_length + 3) & ~(int32_t)7;
        *(int32_t *)(s + k + CELL) = 0;
        if (k != 0) *(int32_t *)(s + k) = 0;

        std::memcpy(s + CELL,
                    csl_cast<char *>(sequence)+(CELL-TAG_VECTOR)+start,
                    (size_t)seq_length);

        return onevalue(copy);
    }
    else if (is_bitvec_header(h))
    {   hl = length_of_header(h) - CELL;
        if (hl < end/8) return aerror0("vector-subseq* out of range");

        // Grab a bit-vector of the right size
        Save save(THREADARG sequence);
        copy = Lmake_simple_bitvector(nil,fixnum_of_int(seq_length));
        errexit();
        save.restore(sequence);

        //
        // This is not terribly efficient since the calls to Lbputv and Lbgetv
        // ought to be coded inline, but on the other hand its no worse than the
        // original Lisp-coded version.
        //
        for (i=start; i<end; ++i)
        {   Save save1(THREADARG sequence, copy);
            LispObject v = Lbgetv(nil,sequence,fixnum_of_int(i));
            errexit();
            Lbputv(nil,copy,fixnum_of_int(i-start), v);
            save1.restore(sequence, copy);
        }

        return onevalue(copy);
    }
    else if (type_of_header(h) == TYPE_ARRAY)
    {   // elt(sequence, 1) is the list of dimensions - only handle 1-d case
        if (cdr(elt(sequence, 1)) != nil)
            return aerror1("vector-subseq*",sequence);
        i = int_of_fixnum(elt(sequence, 3));  // displaced-index-offset
        return vector_subseq(elt(sequence,2),start+i,end+i);
    }
    else
        return aerror1("vector-subseq*",sequence);
}

LispObject Llist_subseq1(LispObject env, LispObject seq,
                         LispObject start)
{   LispObject len;
    size_t first, last;
    THREADID;

    first = int_of_fixnum(start);
    Save save(THREADARG seq);
    len = Llength(nil,seq);
    errexit();
    save.restore(seq);
    last = int_of_fixnum(len);
    if (first > last) return aerror1("list-subseq* out of range",seq);
    return list_subseq(seq, first, last);
}

LispObject Llist_subseq2(LispObject env, LispObject seq,
                         LispObject start, LispObject end)
{   size_t first, last;
    first = int_of_fixnum(start);
    last  = int_of_fixnum(end);
    if (first > last) return aerror1("list-subseq* out of range",seq);

    return list_subseq(seq, first, last);
}

LispObject Lvector_subseq1(LispObject env, LispObject seq,
                           LispObject start)
{   LispObject len;
    size_t first, last;
    THREADID;

    first = int_of_fixnum(start);
    Save save(THREADARG seq);
    len = Llength(nil,seq);
    errexit();
    save.restore(seq);
    last = int_of_fixnum(len);

    if (first > last) return aerror1("vector-subseq* out of range",seq);

    return vector_subseq(seq, first, last);
}

LispObject Lvector_subseq2(LispObject env, LispObject seq,
                           LispObject start, LispObject end)
{   size_t first, last;
    first = int_of_fixnum(start);
    last  = int_of_fixnum(end);
    if (first > last) return aerror1("vector-subseq* out of range",seq);

    return vector_subseq(seq, first, last);
}

setup_type const funcs3_setup[] =
{   DEF_2("getv",              Lgetv),
    DEF_3("putv",              Lputv),
    DEF_2("getv8",             Lgetv8),
    DEF_3("putv8",             Lputv8),
    DEF_2("getv16",            Lgetv16),
    DEF_3("putv16",            Lputv16),
    DEF_2("getv32",            Lgetv32),
    DEF_3("putv32",            Lputv32),
    DEF_2("fgetv32",           Lfgetv32),
    DEF_3("fputv32",           Lfputv32),
    DEF_2("fgetv64",           Lfgetv64),
    DEF_3("fputv64",           Lfputv64),
    DEF_2("qgetv",             Lgetv),
    DEF_2("egetv",             Lgetv),
    DEF_3("qputv",             Lputv),
    DEF_3("eputv",             Lputv),
    DEF_1("make-simple-string", Lsmkvect),
    DEF_1("allocate-string",   Lsmkvect),
    DEF_3("putv-char",         Lsputv),
    DEF_3("string-store",      Lsputv),
    DEF_3("string-store1",     Lsputv),
    DEF_4up("string-store2",   Lsputv2),
    DEF_4up("string-store3",   Lsputv3),
    DEF_4up("string-store4",   Lsputv4),
    DEF_3("bps-putv",          Lbpsputv),
    DEF_2("bps-getv",          Lbpsgetv),
    DEF_1("bps-upbv",          Lbpsupbv),
    DEF_1("eupbv",             Lupbv),
    DEF_2("schar",             Lsgetv),
    DEF_2("scharn",            Lsgetvn),
    DEF_2("byte-getv",         Lbytegetv),
    DEF_1("mkvect",            Lmkvect),
    DEF_1("mkevect",           Lmkevect),
    DEF_1("mkxvect",           Lmkxvect),
    DEF_1("mkvect8",           Lmkvect8),
    DEF_1("mkvect16",          Lmkvect16),
    DEF_1("mkvect32",          Lmkvect32),
    DEF_1("mkfvect32",         Lmkfvect32),
    DEF_1("mkfvect64",         Lmkfvect64),
    DEF_1("upbv",              Lupbv),
    DEF_1("string-length",     Lstring_length),
    DEF_2("getv-bit",          Lbgetv),
    DEF_2("sbit",              Lbgetv),
    DEF_1("make-simple-bitvector", Lmake_simple_bitvector),
    DEF_3("putv-bit",          Lbputv),
    DEF_3("sbitset",           Lbputv),
    DEF_1("primep32",          Lprimep32),
    DEF_1("primep64",          Lprimep32),
#ifdef COMMON
    DEF_1("hashtable-flavour",  Lhash_flavour),
    DEF_1("make-simple-vector", Lmksimplevec),
    DEF_2("svref",             Lgetv),
    DEF_1("vector-bound",      Lvecbnd),
    DEF_3("putvec",            Lputvec),
#ifdef DO_AREF_AND_ASET_LATER
    {"aref",                   G0Wother, Laref_1, Laref_2, Laref_3, Laref_4up},
    {"aset",                   G0Wother, Laset_1, Laset_2, Laset_3, Laset_4up},
#endif
    DEF_2("elt",               Lelt),
    DEF_3("setelt",            Lsetelt),
    DEF_1("vectorp",           Lvectorp),
    DEF_2("char",              Lchar),
    DEF_3("charset",           Lcharset),
    {"make-string",            G0wother, Lmake_string_1, G2Wother, Lmake_string_3, G4Wother},
    DEF_2("shrink-vector",     Lshrink_vector),
    DEF_1("string",            Lstring),

#if 0
// These need serious updating if they are to be revived!
    {"vector-subseq*",         WRONG_NO_3A, Lvector_subseq1, Lvector_subseq2},
    {"list-subseq*",           WRONG_NO_3A, Llist_subseq1, Llist_subseq2},
    {"subseq",                 WRONG_NO_3A, Lvector_subseq1, Lvector_subseq2},
#endif
// The "x" is temporary while I debug
    DEF_1("xcopy-vector",      Lcopy_vector),
#endif
    {"vector",                 Lvector_0, Lvector_1, Lvector_2, Lvector_3, Lvector_4up},
    DEF_1("list-to-vector",    Llist_to_vector),
    DEF_1("encapsulatedp",     Lencapsulatedp),
#if 0
    DEF_1("maple_atomic_value", Lmaple_atomic_value),
    DEF_1("maple_tag",         Lmaple_tag),
    DEF_1("maple_length",      Lmaple_length),
    DEF_1("maple_string_data", Lmaple_string_data),
    DEF_1("maple_integer",     Lmaple_integer),
    DEF_2("maple_component",   Lmaple_component),
#endif
    {nullptr,                  nullptr, nullptr, nullptr, nullptr, nullptr}
};

// end of fns3.cpp
