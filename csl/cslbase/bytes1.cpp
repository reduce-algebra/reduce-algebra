// bytes1.cpp                             Copyright (C) 1991-2017, Codemist
//
//
// Bytecode interpreter for Lisp
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

#include "bytes.h"

//
// I can arrange that the option that allows me to count the number of byte
// opcodes that are executed also lets me collect statistics on which
// indicators are most heavily used with PUT and GET.
//

#ifndef NO_BYTECOUNT
//
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
    LispObject w;
    push(tag);
    w = Lget_hash_2(nil, tag, get_counts);
    pop(tag);
    if (w == nil)
    {   w = cons_no_gc(fixnum_of_int(0), fixnum_of_int(0));
        push(w);
        Lput_hash(nil, 3, tag, get_counts, w);
        pop(w);
    }
    if (found) qcar(w) += 0x10;
    else qcdr(w) += 0x10;
#endif
}

//
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
//

LispObject get(LispObject a, LispObject b, LispObject c)
{   LispObject pl, prev, w;
    int n;
//
// In CSL mode plists are structured like association lists, and
// NOT as lists with alternate tags and values.  There is also
// a bitmap that can provide a fast test for the presence of a
// property...
// Common Lisp says that property lists are lists of even length with
// indicators and values alternating. If I needed to support that I would
// do so by making the symbol-plist function map from what I use here to
// that. And symbol-plist already has to do special things to cope with
// the "fastget" mechanism that I have...
//
    if (!symbolp(a))
    {
#ifdef RECORD_GET
        record_get(b, false);
#endif
        return onevalue(c);
    }
    if (symbolp(b) && (n = header_fastget(qheader(b))) != 0)
    {   if ((w = qfastgets(a)) == nil)
        {
#ifdef RECORD_GET
            record_get(b, false);
#endif
            return onevalue(c);
        }
        w = elt(w, n-1); // use the fastget scheme
        if (w == SPID_NOPROP) w = c;
#ifdef RECORD_GET
        push(w);
        record_get(b, w != nil);
        pop(w);
#endif
        return onevalue(w);
    }
    pl = qplist(a);
    if (pl == nil)
    {
#ifdef RECORD_GET
        record_get(b, false);
#endif
        return onevalue(c);
    }
    w = qcar(pl);
    if (qcar(w) == b)    // found at first position on the list
    {
#ifdef RECORD_GET
        push(w);
        record_get(b, true);
        pop(w);
#endif
        return onevalue(qcdr(w));
    }
    pl = qcdr(pl);
    if (pl == nil)
    {
#ifdef RECORD_GET
        record_get(b, false);
#endif
        return onevalue(c);
    }
    w = qcar(pl);
    if (qcar(w) == b)    // found at second position on the list
    {
#ifdef RECORD_GET
        push(w);
        record_get(b, true);
        pop(w);
#endif
        return onevalue(qcdr(w));
    }
    prev = pl;
    pl = qcdr(pl);
    if (pl == prev) aerror("looped up plist in get");
    if (pl == nil)
    {
#ifdef RECORD_GET
        record_get(b, false);
#endif
        return onevalue(c);
    }
    for (;;)
    {   w = qcar(pl);
//
// If I find the item anywhere beyond the first two places in the plist I
// migrate it up to the front so that next time will be faster
//
        if (qcar(w) == b)   // found - do move to top operation.
        {   qcdr(prev) = qcdr(pl);
            qcdr(pl) = qplist(a);
            qplist(a) = pl;
#ifdef RECORD_GET
            push(w);
            record_get(b, true);
            pop(w);
#endif
            return onevalue(qcdr(w));
        }
        prev = pl;
        pl = qcdr(pl);
        if (pl == prev) aerror("looped up plist in get");
        if (pl == nil)
        {
#ifdef RECORD_GET
            record_get(b, false);
#endif
            return onevalue(c);
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
        {   push3(a, b, c);
            pl = get_basic_vector_init(CELL+CELL*fastget_size, SPID_NOPROP);
            pop3(c, b, a);
            qfastgets(a) = pl;
        }
        elt(pl, n-1) = c;
        return c;            // NB the property is NOT on the plist
    }
    pl = qplist(a);
    while (pl != nil)
    {   LispObject w = qcar(pl);
        if (qcar(w) == b)
        {   qcdr(w) = c;
            return c;
        }
        else pl = qcdr(pl);
    }
    stackcheck3(a, b, c);
    push2(a, c);
    b = acons(b, c, qplist(a));
    pop2(c, a);
    qplist(a) = b;
    return c;
}

static LispObject remprop(LispObject a, LispObject b)
{   LispObject pl, prevp;
    int n;
    if (!symbolp(a)) return nil;
    if (symbolp(b) && (n = header_fastget(qheader(b))) != 0)
    {   pl = qfastgets(a);
        if (pl != nil) elt(pl, n-1) = SPID_NOPROP;
        return nil;
    }
    prevp = nil;
    pl = qplist(a);
    while (pl != nil)
    {   LispObject w = qcar(pl);
        if (qcar(w) == b)
        {   pl = qcdr(pl);
            if (prevp == nil) qplist(a) = pl;
            else qcdr(prevp) = pl;
            return qcdr(w);
        }
        prevp = pl;
        pl = qcdr(prevp);
        if (pl == prevp) aerror("looped up plist in remprop");
    }
    return nil;
}

LispObject get_0(LispObject a, int n)
{   LispObject w;
    if (!symbolp(a)) return onevalue(nil);
    {   if ((w = qfastgets(a)) == nil)
            return onevalue(nil);
        w = elt(w, n);
        if (w == SPID_NOPROP) w = nil;
        return onevalue(w);
    }
}

LispObject Lget(LispObject env, LispObject a, LispObject b)
{   LispObject pl, prev, w;
    int n;
//
// In CSL mode plists are structured like association lists, and
// NOT as lists with alternate tags and values.  There is also
// a bitmap that can provide a fast test for the presence of a
// property...
//
    if (!symbolp(a))
    {
#ifdef RECORD_GET
        record_get(b, false);
#endif
        return onevalue(nil);
    }
    if (symbolp(b) && (n = header_fastget(qheader(b))) != 0)
    {   if ((w = qfastgets(a)) == nil)
        {
#ifdef RECORD_GET
            record_get(b, false);
#endif
            return onevalue(nil);
        }
        w = elt(w, n-1);
        if (w == SPID_NOPROP) w = nil;
#ifdef RECORD_GET
        push(w);
        record_get(b, w != nil);
        pop(w);
#endif
        return onevalue(w);
    }
    pl = qplist(a);
    if (pl == nil)
    {
#ifdef RECORD_GET
        record_get(b, false);
#endif
        return onevalue(nil);
    }
    w = qcar(pl);
    if (qcar(w) == b)
    {
#ifdef RECORD_GET
        push(w);
        record_get(b, true);
        pop(w);
#endif
        return onevalue(qcdr(w));
    }
    pl = qcdr(pl);
    if (pl == nil)
    {
#ifdef RECORD_GET
        record_get(b, false);
#endif
        return onevalue(nil);
    }
    w = qcar(pl);
    if (qcar(w) == b)
    {
#ifdef RECORD_GET
        push(w);
        record_get(b, true);
        pop(w);
#endif
        return onevalue(qcdr(w));
    }
    prev = pl;
    pl = qcdr(pl);
    if (pl == prev) aerror("looped up plist in Lget");
    if (pl == nil)
    {
#ifdef RECORD_GET
        record_get(b, false);
#endif
        return onevalue(nil);
    }
    for (;;)
    {   w = qcar(pl);
//
// If I find the item anywhere beyond the first two places in the plist I
// migrate it up to the front so that next time will be faster
//
        if (qcar(w) == b)
        {   qcdr(prev) = qcdr(pl);
            qcdr(pl) = qplist(a);
            qplist(a) = pl;
#ifdef RECORD_GET
            push(w);
            record_get(b, true);
            pop(w);
#endif
            return onevalue(qcdr(w));
        }
        prev = pl;
        pl = qcdr(pl);
        if (pl == prev) aerror("looped up plist in Lget");
        if (pl == nil)
        {
#ifdef RECORD_GET
            record_get(b, false);
#endif
            return onevalue(nil);
        }
    }
}

LispObject Lget_3(LispObject, LispObject a, LispObject b, LispObject c)
{   return onevalue(get(a, b, c));
}

LispObject Lputprop(LispObject env, LispObject a, LispObject b, LispObject c)
{   return onevalue(putprop(a, b, c));
}

LispObject Lflagp(LispObject env, LispObject a, LispObject b)
{   LispObject pl, prev, w;
    int n;
    if (!symbolp(a))
    {
#ifdef RECORD_GET
        record_get(b, false);
#endif
        return onevalue(nil);
    }
    if (symbolp(b) && (n = header_fastget(qheader(b))) != 0)
    {   if ((w = qfastgets(a)) == nil)
        {
#ifdef RECORD_GET
            record_get(b, false);
#endif
            return onevalue(nil);
        }
        w = elt(w, n-1);
        if (w == SPID_NOPROP)
        {
#ifdef RECORD_GET
            record_get(b, false);
#endif
            return onevalue(nil);
        }
#ifdef RECORD_GET
        record_get(b, true);
#endif
        return onevalue(lisp_true);
    }
    pl = qplist(a);
    if (pl == nil)
    {
#ifdef RECORD_GET
        record_get(b, false);
#endif
        return onevalue(nil);
    }
    w = qcar(pl);
    if (qcar(w) == b)
    {
#ifdef RECORD_GET
        record_get(b, true);
#endif
        return onevalue(lisp_true);
    }
    pl = qcdr(pl);
    if (pl == nil)
    {
#ifdef RECORD_GET
        record_get(b, false);
#endif
        return onevalue(nil);
    }
    w = qcar(pl);
    if (qcar(w) == b)
    {
#ifdef RECORD_GET
        record_get(b, true);
#endif
        return onevalue(lisp_true);
    }
    prev = pl;
    pl = qcdr(pl);
    if (pl == prev) aerror("looped up plist in Lflagp");
    if (pl == nil)
    {
#ifdef RECORD_GET
        record_get(b, false);
#endif
        return onevalue(nil);
    }
    for (;;)
    {   w = qcar(pl);
//
// If I find the item anywhere beyond the first two places in the plist I
// migrate it up to the front so that next time will be faster
//
        if (qcar(w) == b)
        {   qcdr(prev) = qcdr(pl);
            qcdr(pl) = qplist(a);
            qplist(a) = pl;
#ifdef RECORD_GET
            record_get(b, true);
#endif
            return onevalue(lisp_true);
        }
        prev = pl;
        pl = qcdr(pl);
        if (pl == prev) aerror("looped up plist in Lflagp");
        if (pl == nil)
        {
#ifdef RECORD_GET
            record_get(b, false);
#endif
            return onevalue(nil);
        }
    }
}

LispObject Lflagpcar(LispObject env, LispObject a, LispObject b)
{   LispObject pl, prev, w;
    int n;
// Fairly heavily used by Reduce test file - hence in here
    if (a != nil)
    {   if (!consp(a))
        {
#ifdef RECORD_GET
            record_get(b, false);
#endif
            return onevalue(nil);
        }
        a = qcar(a);
        if (!symbolp(a))
        {
#ifdef RECORD_GET
            record_get(b, false);
#endif
            return onevalue(nil);
        }
    }
    if (symbolp(b) && (n = header_fastget(qheader(b))) != 0)
    {   if ((w = qfastgets(a)) == nil)
        {
#ifdef RECORD_GET
            record_get(b, false);
#endif
            return onevalue(nil);
        }
        w = elt(w, n-1);
        if (w == SPID_NOPROP)
        {
#ifdef RECORD_GET
            record_get(b, false);
#endif
            return onevalue(nil);
        }
#ifdef RECORD_GET
        record_get(b, true);
#endif
        return onevalue(lisp_true);
    }
    pl = qplist(a);
    if (pl == nil)
    {
#ifdef RECORD_GET
        record_get(b, false);
#endif
        return onevalue(nil);
    }
    w = qcar(pl);
    if (qcar(w) == b)
    {
#ifdef RECORD_GET
        record_get(b, true);
#endif
        return onevalue(lisp_true);
    }
    pl = qcdr(pl);
    if (pl == nil)
    {
#ifdef RECORD_GET
        record_get(b, false);
#endif
        return onevalue(nil);
    }
    w = qcar(pl);
    if (qcar(w) == b)
    {
#ifdef RECORD_GET
        record_get(b, true);
#endif
        return onevalue(lisp_true);
    }
    prev = pl;
    pl = qcdr(pl);
    if (pl == prev) aerror("looped up plist in flagpcar");
    if (pl == nil)
    {
#ifdef RECORD_GET
        record_get(b, false);
#endif
        return onevalue(nil);
    }
    for (;;)
    {   w = qcar(pl);
//
// If I find the item anywhere beyond the first two places in the plist I
// migrate it up to the front so that next time will be faster
//
        if (qcar(w) == b)
        {   qcdr(prev) = qcdr(pl);
            qcdr(pl) = qplist(a);
            qplist(a) = pl;
#ifdef RECORD_GET
            record_get(b, true);
#endif
            return onevalue(lisp_true);
        }
        prev = pl;
        pl = qcdr(pl);
        if (pl == prev) aerror("looped up plist in flagpcar");
        if (pl == nil)
        {
#ifdef RECORD_GET
            record_get(b, false);
#endif
            return onevalue(nil);
        }
    }
}

LispObject Lflag(LispObject env, LispObject a, LispObject b)
{   int n = 0;
    if (symbolp(b)) n = header_fastget(qheader(b));
    while (consp(a))
    {   LispObject v = qcar(a), pl;
        a = qcdr(a);
        if (!symbolp(v)) continue;
//
// I store FLAGS just as if they were PROPERTIES that have the value
// T, so after (flag '(a b c) 'd) if anybody goes (get 'a 'd) they get back
// the value T.
//
        if (n)
        {   pl = qfastgets(v);
            if (pl == nil)
            {   push2(v, b);
                pl = get_basic_vector_init(CELL+CELL*fastget_size, SPID_NOPROP);
                pop2(b, v);
                qfastgets(v) = pl;
            }
            elt(pl, n-1) = lisp_true;
            continue;
        }
        push2(a, b);
        pl = qplist(v);
        while (pl != nil)
        {   LispObject w = qcar(pl);
            if (qcar(w) == b)
            {   qcdr(w) = lisp_true;
                goto already_flagged;
            }
            else pl = qcdr(pl);
        }
        push(v);
        b = acons(b, lisp_true, qplist(v));
        pop(v);
        qplist(v) = b;
    already_flagged:
        pop2(b, a);
    }
    return onevalue(nil);
}

LispObject Lremflag(LispObject env, LispObject a, LispObject b)
{   int n = 0;
    if (symbolp(b)) n = header_fastget(qheader(b));
    while (consp(a))
    {   LispObject pl, prevp, v = qcar(a);
        a = qcdr(a);
        if (!symbolp(v)) continue;
        if (n)
        {   pl = qfastgets(v);
            if (pl != nil) elt(pl, n-1) = SPID_NOPROP;
            continue;
        }
        prevp = nil;
        pl = qplist(v);
        while (pl != nil)
        {   LispObject w = qcar(pl);
            if (qcar(w) == b)
            {   pl = qcdr(pl);
                if (prevp == nil) qplist(v) = pl;
                else qcdr(prevp) = pl;
                break;
            }
            prevp = pl;
            pl = qcdr(prevp);
            if (pl == prevp) aerror("looped up plist in remflag");
        }
    }
    return onevalue(nil);
}

LispObject Lremprop(LispObject, LispObject a, LispObject b)
{   return onevalue(remprop(a, b));
}


LispObject Lplist(LispObject env, LispObject a)
{   LispObject r;
    int i;
    if (!symbolp(a)) aerror1("plist", a);
    r = qplist(a);
#ifdef COMMON
    LispObject r1 = nil;
    while (r != nil)
    {   r1 = list2star(qcar(qcar(r)), qcdr(qcar(r)), r1);
        r = qcdr(r);
    }
    r = r1;
#endif
    a = qfastgets(a);
    if (a == nil) return onevalue(r);
    for (i=0; i<fastget_size; i++)
    {   LispObject w = elt(a, i);
        if (w != SPID_NOPROP)
        {   push(a);
// Observe here that in Common Lisp mode I am creating an alternating
// list of indicators and values.
#ifdef COMMON
            r = list2star(elt(fastget_names, i), w, r);
#else
            r = acons(elt(fastget_names, i), w, r);
#endif
            pop(a);
        }
    }
    return onevalue(r);
}

#ifndef NO_BYTECOUNT
//
// Unless NO_BYTECOUNT is set I keep two sorts of counts - first
// ones that show how many bytecodes are executed in each separate
// piece of code that the user runs.  These can be inspected by
// calling MAPSTORE.  Then ones that show (overall) which particular
// byte opcodes are most heavily used.  This information is displayed
// when you call BYTECOUNTS.
//
extern bool profile_count_mode;

#include "opnames.cpp"

static uint64_t total = 0, frequencies[256];

#endif

LispObject Lbytecounts_0(LispObject env)
{
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
                  (int)(total/1000000));
    if (total == 0) total = 1;
    for (i=0; i<256; i++)
    {   if ((i & 3) == 0) stdout_printf("\n");
        stdout_printf("%-9.9s%7.4f  ",
                      opnames[i],
                      100.0*(double)frequencies[i]/(double)total);
    }
    stdout_printf("\n");
#endif

#ifdef RECORD_GET
    v = elt(get_counts, 4);
    if (v == nil) return onevalue(nil);
    size = length_of_header(vechdr(v));
    size = (size - CELL)/CELL;
    term_printf("\n %%SCORE      TOTAL   NOTFOUND  INDICATOR-NAME\n");
    tot = 0.0;
    for (i=1; i<size; i+=2)
    {   LispObject key = elt(v, i), val = elt(v, i+1);
        int32_t yes, no;
        if (key == SPID_HASHEMPTY || key == SPID_HASHTOMB) continue;
        yes = no = 0;
        if (consp(val)) yes = int_of_fixnum(qcar(val)),
                            no  = int_of_fixnum(qcdr(val));
        tot += (double)(yes+2*no);
    }
    tot /= 100.0;
    for (i=1; i<size; i+=2)
    {   LispObject key = elt(v, i), val = elt(v, i+1);
        int32_t yes, no;
        if (key == SPID_HASHEMPTY || key == SPID_HASHTOMB) continue;
        yes = no = 0;
        if (consp(val)) yes = int_of_fixnum(qcar(val)),
                            no  = int_of_fixnum(qcdr(val));
        stdout_printf("%7.2f %10d %10d  ", (double)(yes+2*no)/tot, yes+no, no);
        loop_print_stdout(key);
        stdout_printf("\n");
    }

    v = Lmkhash_2(nil, fixnum_of_int(5), fixnum_of_int(0));
    get_counts = v;
#endif
    return onevalue(nil);
}

LispObject Lbytecounts_1(LispObject env, LispObject a)
{
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
    if (v == nil) return onevalue(nil);
    size = length_of_header(vechdr(v));
    size = (size - CELL)/CELL;
    tot = 0.0;
    for (i=1; i<size; i+=2)
    {   LispObject key = elt(v, i), val = elt(v, i+1);
        int32_t yes, no;
        if (key == SPID_HASHEMPTY || key == SPID_HASHTOMB) continue;
        yes = no = 0;
        if (consp(val)) yes = int_of_fixnum(qcar(val)),
                            no  = int_of_fixnum(qcdr(val));
        tot += (double)(yes+2*no);
    }
    tot /= 100.0;
    stdout_printf("\n(\n");
    for (i=1; i<size; i+=2)
    {   LispObject key = elt(v, i), val = elt(v, i+1);
        int32_t yes, no;
        if (key == SPID_HASHEMPTY || key == SPID_HASHTOMB) continue;
        yes = no = 0;
        if (consp(val)) yes = int_of_fixnum(qcar(val)),
                            no  = int_of_fixnum(qcdr(val));
        stdout_printf("(%7.2f ", (double)(yes+2*no)/tot);
        loop_print_stdout(key);
        stdout_printf(")\n");
    }
    stdout_printf("\n)\n");

    v = Lmkhash_2(nil, 3, fixnum_of_int(5), fixnum_of_int(0));
    get_counts = v;
#endif

    return onevalue(nil);
}

LispObject *stack;

static inline void do_freebind(LispObject bvec)
{   int32_t n, k;
    n = length_of_header(vechdr(bvec));
    for (k=CELL; k<n; k+=CELL)
    {   LispObject v = *(LispObject *)((intptr_t)bvec + k - TAG_VECTOR);
        push(qvalue(v));
        qvalue(v) = nil;
    }
//
// SPID_FBIND is a value that can NEVER occur elsewhere in the Lisp system,
// and so it unambiguously marks a block of fluid bindings on that stack.
//
    push2(bvec, (LispObject)SPID_FBIND);
}

static inline void do_freerstr()
{   LispObject bv;
    size_t n;
    popv(1);
    pop(bv);
    n = length_of_header(vechdr(bv));
    while (n>CELL)
    {   LispObject v = *(LispObject *)((intptr_t)bv + n - (CELL + TAG_VECTOR));
        n -= CELL;
        pop(qvalue(v));
    }
}

static inline void poll_jump_back(LispObject& A_reg)
{   if (--countdown < 0) deal_with_tick();
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        stack >= stacklimit)
        A_reg = reclaim(A_reg, "stack", GC_STACK, 0);
}

static inline void do_pvbind(LispObject vals, LispObject vars)
{   LispObject val, var;
    push4(nil,         // This will be a list ((var . old-value) ...)
          SPID_PVBIND, // Flags up status of the above.
          vars, vals);
    while (consp(vars))
    {   var = qcar(vars);
        vars = qcdr(vars);
        if (!symbolp(var) || var == nil) continue;
        push(vars);
        var = acons(var, qvalue(var), stack[-4]);
        stack[-4] = var;
        pop(vars);
    }
    pop2(vals, vars);
// If the code exits ahead of getting here that is not a calamity. SOME
// at least of the variables will have their previous value saved, and
// unwinding code will restore them - even if they have not yet been changed.
    while (consp(vars))
    {   if (consp(vals)) val = qcar(vals), vals = qcdr(vals);
        else val = unset_var;
        var = qcar(vars);
        if (symbolp(var) && var != nil) qvalue(var) = val;
        vars = qcdr(vars);
    }
}

static inline void do_pvrestore()
{   LispObject w;
    popv(1);                // the SPID_PVBIND
    pop(w);                 // this list ((var . old-value) ...)
    while (w != nil)
    {   LispObject q = qcar(w);
        qvalue(qcar(q)) = qcdr(q);
        w = qcdr(w);
    }
}

static inline LispObject encapsulate_sp(LispObject *sp)
//
// Creates a boxed up representation of a pointer into the stack.
//
{   LispObject w = get_basic_vector(TAG_VECTOR, TYPE_SP, 2*CELL);
    elt(w, 0) = (LispObject)sp;
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
static LispObject show_result(LispObject r)
{   LispObject name = stack[0];
    stack[0] = r;
    freshline_trace();
    loop_print_trace(name);
    trace_printf(" => ");
    loop_print_trace(stack[0]);
    trace_printf("\n");
    pop(r);
    return r;
}
LispObject traced_call0(LispObject from, no_args *f0, LispObject name)
{   push(name);
    push(from);
    freshline_trace();
    trace_printf("Calling ");
    loop_print_trace(name);
    trace_printf(" from ");
    pop(from);
    loop_print_trace(from);
    trace_printf("\n");
    LispObject r = f0(stack[0]);
    return show_result(r);
}

LispObject traced_call1(LispObject from, one_arg *f1,
                        LispObject name, LispObject a1)
{   push2(name, a1);
    push(from);
    freshline_trace();
    trace_printf("Calling ");
    loop_print_trace(name);
    trace_printf(" from ");
    pop(from);
    loop_print_trace(from);
    trace_printf("\n");
    trace_printf("Arg1: ");
    loop_print_trace(stack[0]);
    trace_printf("\n");
    pop(a1);
    LispObject r = f1(stack[0], a1);
    return show_result(r);
}

LispObject traced_call2(LispObject from, two_args *f2,
                        LispObject name, LispObject a1, LispObject a2)
{   push3(name, a1, a2);
    push(from);
    freshline_trace();
    trace_printf("Calling ");
    loop_print_trace(name);
    trace_printf(" from ");
    pop(from);
    loop_print_trace(from);
    trace_printf("\n");
    trace_printf("Arg1: ");
    loop_print_trace(stack[-1]);
    trace_printf("\n");
    trace_printf("Arg2: ");
    loop_print_trace(stack[0]);
    trace_printf("\n");
    pop2(a2, a1);
    LispObject r = f2(stack[0], a1, a2);
    return show_result(r);
}

LispObject traced_call3(LispObject from, three_args *f3,
                        LispObject name,
                        LispObject a1, LispObject a2, LispObject a3)
{   push4(name, a1, a2, a3);
    push(from);
    freshline_trace();
    trace_printf("Calling ");
    loop_print_trace(name);
    trace_printf(" from ");
    pop(from);
    loop_print_trace(from);
    trace_printf("\n");
    trace_printf("Arg1: ");
    loop_print_trace(stack[-2]);
    trace_printf("\n");
    trace_printf("Arg2: ");
    loop_print_trace(stack[-1]);
    trace_printf("\n");
    trace_printf("Arg3: ");
    loop_print_trace(stack[0]);
    trace_printf("\n");
    pop3(a3, a2, a1);
    LispObject r = f3(stack[0], a1, a2, a3);
    return show_result(r);
}

LispObject traced_call4up(LispObject from, fourup_args *f4up,
                          LispObject name,
                          LispObject a1, LispObject a2, LispObject a3,
                          LispObject a4up)
{   push5(name, a1, a2, a3, a4up);
    push(from);
    freshline_trace();
    trace_printf("Calling ");
    loop_print_trace(name);
    trace_printf(" from ");
    pop(from);
    loop_print_trace(from);
    trace_printf("\n");
    trace_printf("Arg1: ");
    loop_print_trace(stack[-3]);
    trace_printf("\n");
    trace_printf("Arg2: ");
    loop_print_trace(stack[-2]);
    trace_printf("\n");
    trace_printf("Arg3: ");
    loop_print_trace(stack[-1]);
    trace_printf("\n");
    push(stack[0]);
    for (int i=4; stack[0]!=nil; i++)
    {   trace_printf("Arg%d: ", i);
        loop_print_trace(qcar(stack[0]));
        trace_printf("\n");
        stack[0] = qcdr(stack[0]);
    }
    popv(1);
    pop4(a4up, a3, a2, a1);
    LispObject r = f4up(stack[0], a1, a2, a3, a4up);
    return show_result(r);
}

void print_traceset(int varname, LispObject val)
{   push(val);
    freshline_trace();
    loop_print_trace(elt(litvec, 0)); // Function this is within
    trace_printf(":  ");
    loop_print_trace(elt(litvec, varname));
    trace_printf(" := ");
    pop(val);
    loop_print_trace(val);
    trace_printf("\n");
}

LispObject carerror(LispObject a)
{
#ifdef COMMON
    if (a == nil) return a;
#endif
    error(1, err_bad_car, a);
}

LispObject cdrerror(LispObject a)
{
#ifdef COMMON
    if (a == nil) return a;
#endif
    error(1, err_bad_cdr, a);
}

void car_fails(LispObject a)
{   error(1, err_bad_car, a);
}

void cdr_fails(LispObject a)
{   error(1, err_bad_cdr, a);
}

void rplaca_fails(LispObject a)
{   error(1, err_bad_rplac, a);
}

void rplacd_fails(LispObject a)
{   error(1, err_bad_rplac, a);
}

#define current_byte         (((unsigned char *)codevec)[ppc])
#define next_byte            (((unsigned char *)codevec)[ppc++])
#define previous_byte        (((unsigned char *)codevec)[ppc-1])

#ifdef CHECK_STACK
char *native_stack = NULL, *native_stack_base = NULL;
#endif

static inline void short_jump(size_t& ppc, size_t xppc)
{
#ifdef LABEL_RESOLUTION_DEBUGGING
    size_t oldppc = ppc;
#endif
    ppc = ppc + ((unsigned char *)codevec)[xppc];
// The extra test here was useful at a time I was worried about label
// resolution in the compiler, and some jumps led to bytecode execution
// resuming a byte early or late. The bug that was involved there has
// now been fixed, and i no longer put the label-marker bytes in the
// bytestream. The code here illustrates use of "my_abort" with a lambda
// expression so that I can have absolute control over the message
// displayed if the assertion fails.
#ifdef LABEL_RESOLUTION_DEBUGGING
    my_assert(
        current_byte == OP_SPARE,
        [&]{trace_printf("failure at ppc=%d = %x from %d %x\n",
                         ppc, ppc, oldppc, oldppc);
           });
#endif
}

static inline void short_jump_back(size_t& ppc, size_t xppc, LispObject& A_reg)
{
#ifdef LABEL_RESOLUTION_DEBUGGING
    size_t oldppc = ppc;
#endif
    ppc = ppc - ((unsigned char *)codevec)[xppc];
// To allow for interruption I will poll on every backwards jump
    poll_jump_back(A_reg);
#ifdef LABEL_RESOLUTION_DEBUGGING
    my_assert(
        current_byte == OP_SPARE,
        [&]{trace_printf("failure at ppc=%d = %x from %d %x\n",
                         ppc, ppc, oldppc, oldppc);
           });
#endif
}

static inline void long_jump(unsigned int w, size_t& ppc, size_t xppc)
{
#ifdef LABEL_RESOLUTION_DEBUGGING
    size_t oldppc = ppc;
#endif
    ppc = ppc + ((w << 8) + ((unsigned char *)codevec)[xppc]);
#ifdef LABEL_RESOLUTION_DEBUGGING
    my_assert(
        current_byte == OP_SPARE,
        [&]{trace_printf("failure at ppc=%d = %x from %d %x\n",
                         ppc, ppc, oldppc, oldppc);
           });
#endif
}

static inline void long_jump_back(unsigned int w, size_t& ppc, size_t xppc, LispObject& A_reg)
{
#ifdef LABEL_RESOLUTION_DEBUGGING
    size_t oldppc = ppc;
#endif
    ppc = ppc - ((w << 8) + ((unsigned char *)codevec)[xppc]);
    poll_jump_back(A_reg);
#ifdef LABEL_RESOLUTION_DEBUGGING
    my_assert(
        current_byte == OP_SPARE,
        [&]{trace_printf("failure at ppc=%d = %x from %d %x\n",
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
    {   call_stack = qcdr(call_stack);
    }
};

#endif

LispObject bytestream_interpret(size_t ppc, LispObject lit,
                                LispObject *entry_stack)
#ifdef CHECK_STACK
{
//
// Here I have a wrapper function that is used to help me track
// ultra deep recursions! This is only used when CHECK_STACK had been
// defined at compile-time, and I view any performance consequences as
// utterly unimportant provided it sometimes allows me to discover
// what is leading to uncontrolled recursion. This must not trigger a GC
// until it calls bytestread_interpret1.
//
    LispObject w;
    int len = 0;
    call_stack = cons_no_gc(lit, call_stack);
    save_call_stack RAII;
    for (w = call_stack; w != nil; w = qcdr(w)) len++;
    if (len > maxnest+(maxnest/2)+1)
    {   maxnest = len;
        trace_printf("\n+++++ bytecode nesting depth %d observed\n", maxnest);
        w = call_stack;
        while (w != nil)
        {   *++stack = w;
            prin_to_trace(qcar(w)); // should be a symbol
            w = *stack--;
            w = qcdr(w);
            trace_printf("\n");
        }
    }
    if (len > 20000) aerror("Stack overflow");
    else w = bytestream_interpret1(ppc, lit, entry_stack);
    return w;
}

LispObject bytestream_interpret1(size_t ppc, LispObject lit,
                                 LispObject *entry_stack)
#endif // CHECK_STACK
{
// I put the body of the interpreter in a separate file. For now (at least)
// I just textually include it here...

#include "bytes2.cpp"

}

// end of bytes1.cpp
