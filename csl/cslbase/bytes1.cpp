// bytes1.cpp                              Copyright (C) 1991-2025 Codemist
//
//
// Bytecode interpreter for Lisp
//

/**************************************************************************
 * Copyright (C) 2025, Codemist.                         A C Norman       *
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

#include "bytes.h"

// I can arrange that the option that allows me to count the number of byte
// opcodes that are executed also lets me collect statistics on which
// indicators are most heavily used with PUT and GET.

#ifndef NO_BYTECOUNT
// RECORD_GET can be set to track all used of PUT, GET, FLAG and FLAGP. This
// may be useful when deciding which tags should be treated specially as
// "fastget" ones, but that decision is not going to be reviwed at all often
// and so I will leave things so that when somebody wants that information
// they need to manually edit this file or use "-DRECORD_GET" in CPPFLAGS
// rather than the expense of recording uses of GET being standard.
//
// #define RECORD_GET 1
#endif

void record_get(LispObject tag, bool found)
{
#ifdef RECORD_GET
    w = Lget_hash_2(nil, tag, get_counts);
    errexit();
    if (w == nil)
    {   w = cons_no_gc(fixnum_of_int(0), fixnum_of_int(0));
        Lput_hash(nil, 3, tag, get_counts, w);
    }
    if (found) car(w) += 0x10;
    else cdr(w) += 0x10;
#endif
}

// Here is a short essay on the interaction between flags and properties.
// It is written because the issue appears to be delicate, especially in the
// face of a scheme that I use to speed things up.
// (a) If you use FLAG, REMFLAG and FLAGP with some indicator then that
//     indicator is known as a flag.
// (b) If you use PUT, REMPROP and GET with an indicator then what you
//     have is a property.
// (c) Providing the names of flags and properties are disjoint no difficulty
//     whatever should arise.
// (d) If you use PLIST to gain direct access to a property list then flags
//     are visible as pairs (tag . t) and properties as (tag . value).
// (e) Using RPLACx operations on the result of PLIST may cause system
//     damage.  It is to be considered illegal. Also changes made that
//     way may not be matched in any accelerating caches that I keep.
// (f) After (FLAG '(id) 'tag) [when id did not previously have any flags
//     or properties] a call (GET 'id 'tag) will return t.
// (g) After (PUT 'id 'tag 'anything) a call (FLAGP 'id 'tag) will return t
//     whatever the value of "anything".  A call (GET 'id 'tag) will return
//     the saved value (which might be nil).  Thus FLAGP can be thought of
//     as a function that tests if a given property is attached to a
//     symbol.
// (h) As a consequence of (g) REMPROP and REMFLAG are really the same
//     operation.

LispObject get(LispObject a, LispObject b, LispObject c)
{   LispObject pl, prev, w;
    int n;
// In CSL mode plists are structured like association lists, and
// NOT as lists with alternate tags and values.  There is also
// a bitmap that can provide a fast test for the presence of a
// property...
// Common Lisp says that property lists are lists of even length with
// indicators and values alternating. If I needed to support that I would
// do so by making the symbol-plist function map from what I use here to
// that. And symbol-plist already has to do special things to cope with
// the "fastget" mechanism that I have...
    if (!symbolp(a))
    {
#ifdef RECORD_GET
        record_get(b, false);
        errexit();
#endif
        return c;
    }
    if (symbolp(b) && (n = header_fastget(qheader(b))) != 0)
    {   if ((w = qfastgets(a)) == nil)
        {
#ifdef RECORD_GET
            record_get(b, false);
            errexit();
#endif
            return c;
        }
        w = basic_elt(w, n-1); // use the fastget scheme
        if (w == SPID_NOPROP) w = c;
#ifdef RECORD_GET
        record_get(b, w != nil);
        errexit();
#endif
        return w;
    }
    pl = qplist(a);
    if (pl == nil)
    {
#ifdef RECORD_GET
        record_get(b, false);
        errexit();
#endif
        return c;
    }
    w = car(pl);
    if (car(w) == b)    // found at first position on the list
    {
#ifdef RECORD_GET
        record_get(b, true);
        errexit();
#endif
        return cdr(w);
    }
    pl = cdr(pl);
    if (pl == nil)
    {
#ifdef RECORD_GET
        record_get(b, false);
        errexit();
#endif
        return c;
    }
    w = car(pl);
    if (car(w) == b)    // found at second position on the list
    {
#ifdef RECORD_GET
        record_get(b, true);
        errexit();
#endif
        return cdr(w);
    }
    prev = pl;
    pl = cdr(pl);
    if (pl == prev) return aerror("looped up plist in get");
    if (pl == nil)
    {
#ifdef RECORD_GET
        record_get(b, false);
        errexit();
#endif
        return c;
    }
    for (;;)
    {   w = car(pl);
// If I find the item anywhere beyond the first two places in the plist I
// migrate it up to the front so that next time will be faster
        if (car(w) == b)   // found - do move to top operation.
        {   cdr(prev) = cdr(pl);
            cdr(pl) = qplist(a);
            qplist(a) = pl;
#ifdef RECORD_GET
            record_get(b, true);
            errexit();
#endif
            return cdr(w);
        }
        prev = pl;
        pl = cdr(pl);
        if (pl == prev) return aerror("looped up plist in get");
        if (pl == nil)
        {
#ifdef RECORD_GET
            record_get(b, false);
            errexit();
#endif
            return c;
        }
    }
}

LispObject putprop(LispObject a, LispObject b, LispObject c)
{   LispObject pl;
    int n;
    if (!symbolp(a)) return c;
    if (symbolp(b) && (n = header_fastget(qheader(b))) != 0)
    {   pl = qfastgets(a);
        if (pl == nil)
        {   pl = get_basic_vector_init(CELL+CELL*fastget_size, SPID_NOPROP);
            errexit();
            qfastgets(a) = pl;
        }
        basic_elt(pl, n-1) = c;
        return c;            // NB the property is NOT on the plist
    }
    pl = qplist(a);
    while (pl != nil)
    {   LispObject w = car(pl);
        if (car(w) == b)
        {   cdr(w) = c;
            return c;
        }
        else pl = cdr(pl);
    }
    stackcheck();
    b = acons(b, c, qplist(a));
    errexit();
    qplist(a) = b;
    return c;
}

LispObject remprop(LispObject a, LispObject b)
{   LispObject pl, prevp;
    int n;
    if (!symbolp(a)) return nil;
    if (symbolp(b) && (n = header_fastget(qheader(b))) != 0)
    {   pl = qfastgets(a);
        if (pl != nil)
        {   LispObject res = basic_elt(pl, n-1);
            if (res == SPID_NOPROP) res = nil;
            basic_elt(pl, n-1) = SPID_NOPROP;
            return res;
        }
        else return nil;
    }
    prevp = nil;
    pl = qplist(a);
    while (pl != nil)
    {   LispObject w = car(pl);
        if (car(w) == b)
        {   pl = cdr(pl);
            if (prevp == nil) qplist(a) = pl;
            else cdr(prevp) = pl;
            return cdr(w);
        }
        prevp = pl;
        pl = cdr(prevp);
        if (pl == prevp) return aerror("looped up plist in remprop");
    }
    return nil;
}

LispObject get_0(LispObject a, int n)
{   if (!symbolp(a)) return nil;
    LispObject w;
    if ((w = qfastgets(a)) == nil) return nil;
    if ((w = basic_elt(w, n)) != SPID_NOPROP) return w;
    else return nil;
}

LispObject Lget(LispObject env, LispObject a, LispObject b)
{   SingleValued fn;
    LispObject pl, prev, w;
    int n;
// In CSL mode plists are structured like association lists, and
// NOT as lists with alternate tags and values.  There is also
// a bitmap that can provide a fast test for the presence of a
// property...
    if (!symbolp(a))
    {
#ifdef RECORD_GET
        record_get(b, false);
        errexit();
#endif
        return nil;
    }
    if (symbolp(b) && (n = header_fastget(qheader(b))) != 0)
    {   if ((w = qfastgets(a)) == nil)
        {
#ifdef RECORD_GET
            record_get(b, false);
            errexit();
#endif
            return nil;
        }
        w = basic_elt(w, n-1);
        if (w == SPID_NOPROP) w = nil;
#ifdef RECORD_GET
        record_get(b, w != nil);
        errexit();
#endif
        return w;
    }
    pl = qplist(a);
    if (pl == nil)
    {
#ifdef RECORD_GET
        record_get(b, false);
        errexit();
#endif
        return nil;
    }
    w = car(pl);
    if (car(w) == b)
    {
#ifdef RECORD_GET
        record_get(b, true);
        errexit();
#endif
        return cdr(w);
    }
    pl = cdr(pl);
    if (pl == nil)
    {
#ifdef RECORD_GET
        record_get(b, false);
        errexit();
#endif
        return nil;
    }
    w = car(pl);
    if (car(w) == b)
    {
#ifdef RECORD_GET
        record_get(b, true);
        errexit();
#endif
        return cdr(w);
    }
    prev = pl;
    pl = cdr(pl);
    if (pl == prev) return aerror("looped up plist in Lget");
    if (pl == nil)
    {
#ifdef RECORD_GET
        record_get(b, false);
        errexit();
#endif
        return nil;
    }
    for (;;)
    {   w = car(pl);
// If I find the item anywhere beyond the first two places in the plist I
// migrate it up to the front so that next time will be faster
        if (car(w) == b)
        {   cdr(prev) = cdr(pl);
            cdr(pl) = qplist(a);
            qplist(a) = pl;
#ifdef RECORD_GET
            record_get(b, true);
            errexit();
#endif
            return cdr(w);
        }
        prev = pl;
        pl = cdr(pl);
        if (pl == prev) return aerror("looped up plist in Lget");
        if (pl == nil)
        {
#ifdef RECORD_GET
            record_get(b, false);
            errexit();
#endif
            return nil;
        }
    }
}

LispObject Lget_3(LispObject, LispObject a, LispObject b, LispObject c)
{   SingleValued fn;
    return get(a, b, c);
}

LispObject Lputprop(LispObject env, LispObject a, LispObject b, LispObject c)
{   SingleValued fn;
    return putprop(a, b, c);
}

LispObject Lflagp(LispObject env, LispObject a, LispObject b)
{   SingleValued fn;
    LispObject pl, prev, w;
    int n;
    if (!symbolp(a))
    {
#ifdef RECORD_GET
        record_get(b, false);
        errexit();
#endif
        return nil;
    }
    if (symbolp(b) && (n = header_fastget(qheader(b))) != 0)
    {   if ((w = qfastgets(a)) == nil)
        {
#ifdef RECORD_GET
            record_get(b, false);
            errexit();
#endif
            return nil;
        }
        w = basic_elt(w, n-1);
        if (w == SPID_NOPROP)
        {
#ifdef RECORD_GET
            record_get(b, false);
            errexit();
#endif
            return nil;
        }
#ifdef RECORD_GET
        record_get(b, true);
        errexit();
#endif
        return lisp_true;
    }
    pl = qplist(a);
    if (pl == nil)
    {
#ifdef RECORD_GET
        record_get(b, false);
        errexit();
#endif
        return nil;
    }
    w = car(pl);
    if (car(w) == b)
    {
#ifdef RECORD_GET
        record_get(b, true);
        errexit();
#endif
        return lisp_true;
    }
    pl = cdr(pl);
    if (pl == nil)
    {
#ifdef RECORD_GET
        record_get(b, false);
        errexit();
#endif
        return nil;
    }
    w = car(pl);
    if (car(w) == b)
    {
#ifdef RECORD_GET
        record_get(b, true);
        errexit();
#endif
        return lisp_true;
    }
    prev = pl;
    pl = cdr(pl);
    if (pl == prev) return aerror("looped up plist in Lflagp");
    if (pl == nil)
    {
#ifdef RECORD_GET
        record_get(b, false);
        errexit();
#endif
        return nil;
    }
    for (;;)
    {   w = car(pl);
// If I find the item anywhere beyond the first two places in the plist I
// migrate it up to the front so that next time will be faster
        if (car(w) == b)
        {   cdr(prev) = cdr(pl);
            cdr(pl) = qplist(a);
            qplist(a) = pl;
#ifdef RECORD_GET
            record_get(b, true);
            errexit();
#endif
            return lisp_true;
        }
        prev = pl;
        pl = cdr(pl);
        if (pl == prev) return aerror("looped up plist in Lflagp");
        if (pl == nil)
        {
#ifdef RECORD_GET
            record_get(b, false);
            errexit();
#endif
            return nil;
        }
    }
}

LispObject Lflagpcar(LispObject env, LispObject a, LispObject b)
{   SingleValued fn;
    LispObject pl, prev, w;
    int n;
// Fairly heavily used by Reduce test file - hence in here
    if (a != nil)
    {   if (!consp(a))
        {
#ifdef RECORD_GET
            record_get(b, false);
            errexit();
#endif
            return nil;
        }
        a = car(a);
        if (!symbolp(a))
        {
#ifdef RECORD_GET
            record_get(b, false);
            errexit();
#endif
            return nil;
        }
    }
    if (symbolp(b) && (n = header_fastget(qheader(b))) != 0)
    {   if ((w = qfastgets(a)) == nil)
        {
#ifdef RECORD_GET
            record_get(b, false);
            errexit();
#endif
            return nil;
        }
        w = basic_elt(w, n-1);
        if (w == SPID_NOPROP)
        {
#ifdef RECORD_GET
            record_get(b, false);
            errexit();
#endif
            return nil;
        }
#ifdef RECORD_GET
        record_get(b, true);
        errexit();
#endif
        return lisp_true;
    }
    pl = qplist(a);
    if (pl == nil)
    {
#ifdef RECORD_GET
        record_get(b, false);
        errexit();
#endif
        return nil;
    }
    w = car(pl);
    if (car(w) == b)
    {
#ifdef RECORD_GET
        record_get(b, true);
        errexit();
#endif
        return lisp_true;
    }
    pl = cdr(pl);
    if (pl == nil)
    {
#ifdef RECORD_GET
        record_get(b, false);
        errexit();
#endif
        return nil;
    }
    w = car(pl);
    if (car(w) == b)
    {
#ifdef RECORD_GET
        record_get(b, true);
        errexit();
#endif
        return lisp_true;
    }
    prev = pl;
    pl = cdr(pl);
    if (pl == prev) return aerror("looped up plist in flagpcar");
    if (pl == nil)
    {
#ifdef RECORD_GET
        record_get(b, false);
        errexit();
#endif
        return nil;
    }
    for (;;)
    {   w = car(pl);
// If I find the item anywhere beyond the first two places in the plist I
// migrate it up to the front so that next time will be faster
        if (car(w) == b)
        {   cdr(prev) = cdr(pl);
            cdr(pl) = qplist(a);
            qplist(a) = pl;
#ifdef RECORD_GET
            record_get(b, true);
            errexit();
#endif
            return lisp_true;
        }
        prev = pl;
        pl = cdr(pl);
        if (pl == prev) return aerror("looped up plist in flagpcar");
        if (pl == nil)
        {
#ifdef RECORD_GET
            record_get(b, false);
            errexit();
#endif
            return nil;
        }
    }
}

LispObject Lflag(LispObject env, LispObject a, LispObject b)
{   SingleValued fn;
    int n = 0;
    if (symbolp(b)) n = header_fastget(qheader(b));
    while (consp(a))
    {   LispObject v = car(a), pl;
        a = cdr(a);
        if (!symbolp(v)) continue;
// I store FLAGS just as if they were PROPERTIES that have the value
// T, so after (flag '(a b c) 'd) if anybody goes (get 'a 'd) they get back
// the value T.
        if (n)
        {   pl = qfastgets(v);
            if (pl == nil)
            {   pl = get_basic_vector_init(CELL+CELL*fastget_size, SPID_NOPROP);
                errexit();
                qfastgets(v) = pl;
            }
            basic_elt(pl, n-1) = lisp_true;
            continue;
        }
        pl = qplist(v);
        while (pl != nil)
        {   LispObject w = car(pl);
            if (car(w) == b)
            {   cdr(w) = lisp_true;
                goto already_flagged;
            }
            else pl = cdr(pl);
        }
        {   LispObject b1 = acons(b, lisp_true, qplist(v));
            errexit();
            qplist(v) = b1;
        }
    already_flagged:    ;
    }
    return nil;
}

LispObject Lremflag(LispObject env, LispObject a, LispObject b)
{   SingleValued fn;
    int n = 0;
    if (symbolp(b)) n = header_fastget(qheader(b));
    while (consp(a))
    {   LispObject pl, prevp, v = car(a);
        a = cdr(a);
        if (!symbolp(v)) continue;
        if (n)
        {   pl = qfastgets(v);
            if (pl != nil) basic_elt(pl, n-1) = SPID_NOPROP;
            continue;
        }
        prevp = nil;
        pl = qplist(v);
        while (pl != nil)
        {   LispObject w = car(pl);
            if (car(w) == b)
            {   pl = cdr(pl);
                if (prevp == nil) qplist(v) = pl;
                else cdr(prevp) = pl;
                break;
            }
            prevp = pl;
            pl = cdr(prevp);
            if (pl == prevp) return aerror("looped up plist in remflag");
        }
    }
    return nil;
}

LispObject Lremprop(LispObject, LispObject a, LispObject b)
{   SingleValued fn;
    return remprop(a, b);
}


LispObject Lplist(LispObject env, LispObject a)
{   SingleValued fn;
    LispObject r;
    int i;
    if (!symbolp(a)) return aerror1("plist", a);
    r = qplist(a);
#ifdef COMMON
    LispObject r1 = nil;
    while (r != nil)
    {   r1 = list2star(car(car(r)), cdr(car(r)), r1);
        errexit();
        r = cdr(r);
    }
    r = r1;
#endif
    a = qfastgets(a);
    if (a == nil) return r;
    for (i=0; i<fastget_size; i++)
    {   LispObject w = basic_elt(a, i);
        if (w != SPID_NOPROP)
        {
// Observe here that in Common Lisp mode I am creating an alternating
// list of indicators and values.
#ifdef COMMON
            r = list2star(elt(fastget_names, i), w, r);
#else
            r = acons(elt(fastget_names, i), w, r);
#endif
            errexit();
        }
    }
    return r;
}

#ifndef NO_BYTECOUNT
// Unless NO_BYTECOUNT is set I keep two sorts of counts - first
// ones that show how many bytecodes are executed in each separate
// piece of code that the user runs.  These can be inspected by
// calling MAPSTORE.  Then ones that show (overall) which particular
// byte opcodes are most heavily used.  This information is displayed
// when you call BYTECOUNTS.
extern bool profile_count_mode;

static uint64_t total = 0, frequencies[256];

#endif

LispObject Lbytecounts_0(LispObject env)
{   SingleValued fn;
#if !defined NO_BYTECOUNT || defined RECORD_GET
    int32_t i;
#endif
#ifdef RECORD_GET
    int32_t size;
    LispObject v;
    double tot;
#endif
#ifdef NO_BYTECOUNT
    stdout_printf("bytecode statistics not available\n");
#else
    stdout_printf("\nFrequencies of each bytecode (%ldM total)",
                  static_cast<int>(total/1000000));
    if (total == 0) total = 1;
    for (i=0; i<256; i++)
    {   if ((i & 3) == 0) stdout_printf("\n");
        stdout_printf("%-9.9s%7.4f  ",
                      opnames[i],
                      100.0*static_cast<double>(frequencies[i])/static_cast<double>(total));
    }
    stdout_printf("\n");
#endif

#ifdef RECORD_GET
    v = elt(get_counts, 4);
    if (v == nil) return nil;
    size = length_of_header(vechdr(v));
    size = (size - CELL)/CELL;
    term_printf("\n %%SCORE      TOTAL   NOTFOUND  INDICATOR-NAME\n");
    tot = 0.0;
    for (i=1; i<size; i+=2)
    {   LispObject key = elt(v, i), val = elt(v, i+1);
        int32_t yes, no;
        if (key == SPID_HASHEMPTY || key == SPID_HASHTOMB) continue;
        yes = no = 0;
        if (consp(val)) yes = int_of_fixnum(car(val)),
                            no  = int_of_fixnum(cdr(val));
        tot += static_cast<double>(yes+2*no);
    }
    tot /= 100.0;
    for (i=1; i<size; i+=2)
    {   LispObject key = elt(v, i), val = elt(v, i+1);
        int32_t yes, no;
        if (key == SPID_HASHEMPTY || key == SPID_HASHTOMB) continue;
        yes = no = 0;
        if (consp(val)) yes = int_of_fixnum(car(val)),
                            no  = int_of_fixnum(cdr(val));
        stdout_printf("%7.2f %10d %10d  ", static_cast<double>(yes+2*no)/tot,
                      yes+no, no);
        loop_print_stdout(key);
        stdout_printf("\n");
    }

    v = Lmkhash_2(nil, fixnum_of_int(5), fixnum_of_int(0));
    get_counts = v;
#endif
    return nil;
}

LispObject Lbytecounts_1(LispObject env, LispObject a)
{   SingleValued fn;
#ifdef RECORD_GET
    int32_t i, size;
    LispObject v;
    double tot;
#endif
#ifdef NO_BYTECOUNT
    stdout_printf("bytecode statistics not available\n");
#endif

#ifdef RECORD_GET
    v = elt(get_counts, 4);
    if (v == nil) return nil;
    size = length_of_header(vechdr(v));
    size = (size - CELL)/CELL;
    tot = 0.0;
    for (i=1; i<size; i+=2)
    {   LispObject key = elt(v, i), val = elt(v, i+1);
        int32_t yes, no;
        if (key == SPID_HASHEMPTY || key == SPID_HASHTOMB) continue;
        yes = no = 0;
        if (consp(val)) yes = int_of_fixnum(car(val)),
                        no  = int_of_fixnum(cdr(val));
        tot += static_cast<double>(yes+2*no);
    }
    tot /= 100.0;
    stdout_printf("\n(\n");
    for (i=1; i<size; i+=2)
    {   LispObject key = elt(v, i), val = elt(v, i+1);
        int32_t yes, no;
        if (key == SPID_HASHEMPTY || key == SPID_HASHTOMB) continue;
        yes = no = 0;
        if (consp(val)) yes = int_of_fixnum(car(val)),
                            no  = int_of_fixnum(cdr(val));
        stdout_printf("(%7.2f ", static_cast<double>(yes+2*no)/tot);
        loop_print_stdout(key);
        stdout_printf(")\n");
    }
    stdout_printf("\n)\n");

    v = Lmkhash_2(nil, 3, fixnum_of_int(5), fixnum_of_int(0));
    errexit();
    get_counts = v;
#endif

    return nil;
}

// Binding a fluid variable is done here - well potentially several
// at once. Suppose for tis exposition that we are binding x, y and z.
// First the existing values of x, y and z ars pushed on the (Lisp) stack.
// Then the vector [x,y,z] giving their names is pushed.
// finally a value SPID_FBIND is pushed. Life is easy if the execution
// continues smoothly and a freerstr is found. The fun will be if
// a throw or and error needs to unwind. For that case the (Lisp) stack will
// be popped one element at time until the lebel associated with entry to
// the current function (or a CATCH or UNWIND_PROTECT) is seen. If a value
// SPID_FBIND is spotted some fluids get restored. But a major point to
// note here is that in the absence of error or throw unwinding everything
// is actually rather simple!
// This does not have a useful result to hand back, but for the convenience
// of the JIT I make its signature show it as returning a LispObject.

inline LispObject do_freebind(LispObject bvec)
{   int32_t n, k;
    n = length_of_header(vechdr(bvec));
    for (k=CELL; k<n; k+=CELL)
    {   LispObject v = *reinterpret_cast<LispObject *>(
            static_cast<intptr_t>(bvec) + k - TAG_VECTOR);
        *++stack = qvalue(v);
        qvalue(v) = nil;
    }
// SPID_FBIND is a value that can NEVER occur elsewhere in the Lisp system,
// and so it unambiguously marks a block of fluid bindings on that stack.
    *++stack = bvec;
    *++stack = static_cast<LispObject>(SPID_FBIND);
    return nil;
}

// This can just undo the work of freebind.

inline LispObject do_freerstr()
{   LispObject bv;
    size_t n;
#ifdef DEBUG
    my_assert(*stack == static_cast<LispObject>(SPID_FBIND));
#endif // DEBUG
    stack--;
    bv = *stack--;
    n = length_of_header(vechdr(bv));
    while (n>CELL)
    {   LispObject v = *reinterpret_cast<LispObject *>(
            static_cast<intptr_t>(bv) + n - (CELL + TAG_VECTOR));
        n -= CELL;
        LispObject v1 = *stack--;;
        qvalue(v) = v1;
    }
    return nil;
}

inline int countdown = 100000;

ALWAYSINLINE inline void poll_jump_back(LispObject& A_reg)
{   if (--countdown < 0)
    {   countdown = 100000;
        stackcheck();
        if (time_limit >= 0 &&
            read_clock()/1000 > (std::uint64_t)time_limit)
                resource_exceeded();
    }
}

// "pvbind" is basically a Common Lisp Abomination used to support
// (PROGV '(v1 v2 ...) '(VAL1 VAL2 ...) body) that takes a dynamic
// list of names that are to be bound. This is supported by stacking
// an association-list style record of the original values of all
// the names followed by the value SPID_PVBIND. A simple "pvrestore"
// pops this information and can restore values easily, so as with
// "freebind" the entertainment is that in error/throw processing
// the SPID_PVBIND must be spotted and handled nicely.

static inline LispObject do_pvbind(LispObject vals, LispObject vars)
{   RealSave save(nil,// This will be a list ((var . old-value) ...)
                  SPID_PVBIND); // Flags up status of the above.
    LispObject &binding_list = save.val(1);
    {   RealSave save1(vars, vals);
        while (consp(vars))
        {   LispObject var = car(vars);
            vars = cdr(vars);
            if (!symbolp(var) || var == nil) continue;
            {   RealSave save2(vars);
                var = acons(var, qvalue(var), binding_list);
                errexit();
                save2.restore(vars);
            }
            binding_list = var;
        }
        save1.restore(vars, vals);
    }
// If the code exits ahead of getting here that is not a calamity. SOME
// at least of the variables will have their previous value saved, and
// unwinding code will restore them - even if they have not yet been changed.
    while (consp(vars))
    {   LispObject val;
        if (consp(vals)) val = car(vals), vals = cdr(vals);
        else val = unset_var;
        LispObject var = car(vars);
        if (symbolp(var) && var != nil) qvalue(var) = val;
        vars = cdr(vars);
    }
    return nil;
}

inline void do_pvrestore()
{   LispObject w;
    stack--;                     // the SPID_PVBIND
    w = *stack--;                // this list ((var . old-value) ...)
    while (w != nil)
    {   LispObject q = car(w);
        qvalue(car(q)) = cdr(q);
        w = cdr(w);
    }
}

inline LispObject encapsulate_sp(LispObject *sp)
// Creates a boxed up representation of a pointer into the stack.
{   LispObject w = get_basic_vector(TAG_VECTOR, TYPE_SP, 2*CELL);
    errexit();
    basic_elt(w, 0) = reinterpret_cast<LispObject>(sp);
    return w;
}

// To trace a function I can use one of thse. Eg for a 1-arg function
// where I would normally go just
//        (*f1)(name, a1)
// I can instead go
//        traced_call1(from, f1, name, a1)
// where name is the symbol whose name needs to appear in the message. That
// will print "Calling <name> from <wherever>", then "Arg1: <argument>.
// When those have been printed it will call the function and before it
// returns it will display "<name> => <value>". And similarly for 0, 2 and 3
// argument cases. The interpreter goes via the "apply" function of the
// interpreter for calls with larger numbers of arguments, and it will
// print trace output in similar style.
//
// I rather want trace_printf and loop_print_trace to be such that they
// NEVER call any Lisp functions in ways that could trigger tracing, since
// otherwise there could be nasty recursions arising.

// Well at some stage I may need to arrange to preserve multiple values
// across the printing here...


static LispObject show_result(LispObject name, LispObject r, int64_t count)
{   freshline_trace();
    loop_print_trace(name);
    errexit();
    if (count > 0)
    {   trace_printf(" [%" PRId64 "]", count);
        errexit();
    }
    trace_printf(" => ");
    loop_print_trace(r);
    errexit();
    trace_printf("\n");
    return r;
}
LispObject traced_call0(LispObject from, no_args *f0, LispObject name)
{   freshline_trace();
    trace_printf("Calling ");
    loop_print_trace(name);
    errexit();
    int64_t count = trace_count;
    if (count > 0)
    {   trace_count++;
        trace_printf(" [%" PRId64 "]", count);
        errexit();
    }
    trace_printf(" from ");
    loop_print_trace(from);
    errexit();
    trace_printf("\n");
    LispObject r = f0(name);
    errexit();
    return show_result(name, r, count);
}

LispObject traced_call1(LispObject from, one_arg *f1,
                        LispObject name, LispObject a1)
{   freshline_trace();
    trace_printf("Calling ");
    loop_print_trace(name);
    int64_t count = trace_count;
    if (count > 0)
    {   trace_count++;
        trace_printf(" [%" PRId64 "]", count);
        errexit();
    }
    trace_printf(" from ");
    loop_print_trace(from);
    errexit();
    trace_printf("\n");
    trace_printf("Arg1: ");
    loop_print_trace(a1);
    errexit();
    trace_printf("\n");
    LispObject r = f1(name, a1);
    errexit();
    return show_result(name, r, count);
}

LispObject traced_call2(LispObject from, two_args *f2,
                        LispObject name, LispObject a1, LispObject a2)
{   freshline_trace();
    trace_printf("Calling ");
    loop_print_trace(name);
    errexit();
    int64_t count = trace_count;
    if (count > 0)
    {   trace_count++;
        trace_printf(" [%" PRId64 "]", count);
        errexit();
    }
    trace_printf(" from ");
    loop_print_trace(from);
    errexit();
    trace_printf("\n");
    trace_printf("Arg1: ");
    loop_print_trace(a1);
    errexit();
    trace_printf("\n");
    trace_printf("Arg2: ");
    loop_print_trace(a2);
    errexit();
    trace_printf("\n");
    LispObject r = f2(name, a1, a2);
    errexit();
    return show_result(name, r, count);
}

LispObject traced_call3(LispObject from, three_args *f3,
                        LispObject name,
                        LispObject a1, LispObject a2, LispObject a3)
{   freshline_trace();
    trace_printf("Calling ");
    loop_print_trace(name);
    errexit();
    int64_t count = trace_count;
    if (count > 0)
    {   trace_count++;
        trace_printf(" [%" PRId64 "]", count);
        errexit();
    }
    trace_printf(" from ");
    loop_print_trace(from);
    errexit();
    trace_printf("\n");
    trace_printf("Arg1: ");
    loop_print_trace(a1);
    errexit();
    trace_printf("\n");
    trace_printf("Arg2: ");
    loop_print_trace(a2);
    errexit();
    trace_printf("\n");
    trace_printf("Arg3: ");
    loop_print_trace(a3);
    errexit();
    trace_printf("\n");
    LispObject r = f3(name, a1, a2, a3);
    errexit();
    return show_result(name, r, count);
}

LispObject traced_call4up(LispObject from, fourup_args *f4up,
                          LispObject name,
                          LispObject a1, LispObject a2, LispObject a3,
                          LispObject a4up)
{   freshline_trace();
    trace_printf("Calling ");
    loop_print_trace(name);
    errexit();
    int64_t count = trace_count;
    if (count > 0)
    {   trace_count++;
        trace_printf(" [%" PRId64 "]", count);
        errexit();
    }
    trace_printf(" from ");
    loop_print_trace(from);
    errexit();
    trace_printf("\n");
    trace_printf("Arg1: ");
    loop_print_trace(a1);
    errexit();
    trace_printf("\n");
    trace_printf("Arg2: ");
    loop_print_trace(a2);
    errexit();
    trace_printf("\n");
    trace_printf("Arg3: ");
    loop_print_trace(a3);
    errexit();
    trace_printf("\n");
    LispObject p = a4up;
    for (int i=4; p!=nil; i++)
    {   trace_printf("Arg%d: ", i);
        loop_print_trace(car(p));
        errexit();
        trace_printf("\n");
        p = cdr(p);
    }
    LispObject r = f4up(name, a1, a2, a3, a4up);
    errexit();
    return show_result(name, r, count);
}

LispObject print_traceset(int varname, LispObject val, LispObject litvec)
{   freshline_trace();
    loop_print_trace(elt(litvec, 0)); // Function this is within
    errexit();
    trace_printf(":  ");
    loop_print_trace(elt(litvec, varname));
    errexit();
    trace_printf(" := ");
    loop_print_trace(val);
    errexit();
    trace_printf("\n");
    return nil;
}

LispObject carerror(LispObject a)
{
#ifdef COMMON
// This is an example of where Common Lisp has a feature that
// adds cost!
    if (a == nil) return a;
#endif
    return error(1, err_bad_car, a);
}

LispObject cdrerror(LispObject a)
{
#ifdef COMMON
    if (a == nil) return a;
#endif
    return error(1, err_bad_cdr, a);
}

LispObject car_fails(LispObject a)
{   return error(1, err_bad_car, a);
}

LispObject car_fails()
{   return car_fails(JITarg1);
}

LispObject cdr_fails(LispObject a)
{   return error(1, err_bad_cdr, a);
}

LispObject cdr_fails()
{   return cdr_fails(JITarg1);
}

LispObject rplaca_fails(LispObject a)
{   return error(1, err_bad_rplaca, a);
}

LispObject rplaca_fails()
{   return rplaca_fails(JITarg1);
}

LispObject rplacd_fails(LispObject a)
{   return error(1, err_bad_rplacd, a);
}

LispObject rplacd_fails()
{   return rplacd_fails(JITarg1);
}

#define current_byte         (((unsigned char *)codevec)[ppc])
#define next_byte            (((unsigned char *)codevec)[ppc++])
#define previous_byte        (((unsigned char *)codevec)[ppc-1])

#ifdef CHECK_STACK
char *native_stack = nullptr, *native_stack_base = nullptr;
#endif

ALWAYSINLINE inline void short_jump(size_t& ppc, size_t xppc, LispObject codevec)
{
#ifdef LABEL_RESOLUTION_DEBUGGING
    size_t oldppc = ppc;
#endif
    ppc = ppc + (reinterpret_cast<unsigned char *>(codevec))[xppc];
// The extra test here was useful at a time I was worried about label
// resolution in the compiler, and some jumps led to bytecode execution
// resuming a byte early or late. The bug that was involved there has
// now been fixed, and i no longer put the label-marker bytes in the
// bytestream. The code here illustrates use of "my_assert" with a lambda
// expression so that I can have absolute control over the message
// displayed if the assertion fails.
#ifdef LABEL_RESOLUTION_DEBUGGING
    my_assert(
        current_byte == OP_SPARE2,
        [&] {trace_printf("failure at ppc=%d = %x from %d %x\n",
                          ppc, ppc, oldppc, oldppc);
            });
#endif
}

ALWAYSINLINE inline void short_jump_back(size_t& ppc, size_t xppc,
                            LispObject& A_reg, LispObject codevec)
{
#ifdef LABEL_RESOLUTION_DEBUGGING
    size_t oldppc = ppc;
#endif
    ppc = ppc - (reinterpret_cast<unsigned char *>(codevec))[xppc];
// To allow for interruption I will poll on every backwards jump
    poll_jump_back(A_reg);
#ifdef LABEL_RESOLUTION_DEBUGGING
    my_assert(
        current_byte == OP_SPARE2,
        [&] {trace_printf("failure at ppc=%d = %x from %d %x\n",
                          ppc, ppc, oldppc, oldppc);
            });
#endif
}

ALWAYSINLINE inline void long_jump(unsigned int w, size_t& ppc,
                      size_t xppc, LispObject codevec)
{
#ifdef LABEL_RESOLUTION_DEBUGGING
    size_t oldppc = ppc;
#endif
    ppc = ppc + ((w << 8) + (reinterpret_cast<unsigned char *>(codevec))[xppc]);
#ifdef LABEL_RESOLUTION_DEBUGGING
    my_assert(
        current_byte == OP_SPARE2,
        [&] {trace_printf("failure at ppc=%d = %x from %d %x\n",
                          ppc, ppc, oldppc, oldppc);
            });
#endif
}

ALWAYSINLINE inline void long_jump_back(unsigned int w, size_t& ppc, size_t xppc,
                           LispObject& A_reg, LispObject codevec)
{
#ifdef LABEL_RESOLUTION_DEBUGGING
    size_t oldppc = ppc;
#endif
    ppc = ppc - ((w << 8) + (reinterpret_cast<unsigned char *>
                             (codevec))[xppc]);
    poll_jump_back(A_reg);
#ifdef LABEL_RESOLUTION_DEBUGGING
    my_assert(
        current_byte == OP_SPARE2,
        [&] {trace_printf("failure at ppc=%d = %x from %d %x\n",
                          ppc, ppc, oldppc, oldppc);
            });
#endif
}

extern LispObject bytestream_interpret1(size_t ppc, LispObject lit,
                                        LispObject *entry_stack);
#ifdef CHECK_STACK
static int maxnest = 0;

class save_call_stack
{
public:
    save_call_stack()
    {}
    ~save_call_stack()
    {   call_stack = cdr(call_stack);
    }
};

#endif

LispObject bytestream_interpret(size_t ppc, LispObject lit,
                                LispObject *entry_stack)
#ifdef CHECK_STACK
{
// Here I have a wrapper function that is used to help me track
// ultra deep recursions! This is only used when CHECK_STACK had been
// defined at compile-time, and I view any performance consequences as
// utterly unimportant provided it sometimes allows me to discover
// what is leading to uncontrolled recursion. This must not trigger a GC
// until it calls bytestread_interpret1.
    LispObject w;
    int len = 0;
    call_stack = cons_no_gc(lit, call_stack);
    save_call_stack RAII;
    for (w = call_stack; w != nil; w = cdr(w)) len++;
    if (len > maxnest+(maxnest/2)+1)
    {   maxnest = len;
        trace_printf("\n+++++ bytecode nesting depth %d observed\n", maxnest);
        w = call_stack;
        while (w != nil)
        {   *++stack = w;
            prin_to_trace(car(w)); // should be a symbol
            w = *stack--;
            w = cdr(w);
            trace_printf("\n");
        }
    }
    if (len > 20000) return aerror("Stack overflow");
    else w = bytestream_interpret1(ppc, lit, entry_stack);
    return w;
}

LispObject bytestream_interpret1(size_t ppc, LispObject lit,
                                 LispObject *entry_stack)
#endif // CHECK_STACK
{
// I put the body of the interpreter in a separate file.
// In an "old version" this was a single large file "bytes2.cpp" but
// I am now moving to a version where the support for each byte opcode
// is in its own separate little file in the ops/ directory. This
// perhaps makes navigation to find things easier, but in fact the main
// motivation was to support an experiment where I see if I can make a
// just-in-time compiler that will map bytecoded functions onto native
// code. The new arrangement means I can put the code that interprets
// each byte op as documentation for what the code to be generated will
// need to do.


#define BYTECODE 1
#include "ops/bytes_head.cpp"
#include "ops/bytes_include.cpp"
#include "ops/bytes_tail.cpp"

    return A_reg;
}

// end of bytes1.cpp

