// fns1.cpp                                Copyright (C) 1989-2017 Codemist    

//
// Basic functions part 1.
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

#ifdef WIN32
#include <windows.h>
#else
#include <dlfcn.h>
#endif

/*!!! csl
*/

/*****************************************************************************/
//      Some basic functions
/*****************************************************************************/

// For some debugging purposes it is noce to have a counter...

static uintptr_t countup_counter = 0;

LispObject Lcount_up(LispObject)
{   return fixnum_of_int(countup_counter++);
}

LispObject integerp(LispObject p)
{   if (is_fixnum(p) || (is_numbers(p) && is_bignum(p))) return lisp_true;
    else return nil;
}

/*****************************************************************************/
//      Storage allocation.
/*****************************************************************************/

// gc-forcer(a, b) should arrange that a garbage collection is triggered
// when at most A cons-sized units of consing happens or when at most
// B units of space is used for vectors (where vectors include bignums and
// boxed floats). This is intended to be used to trigger garbage collection
// with rather fine control over when it happens to help with debugging
// storage management issues.

bool next_gc_is_hard = false;
uint64_t force_cons=0, force_vec = 0;

LispObject Lgc_forcer(LispObject env, LispObject a, LispObject b)
{   if (force_cons != 0 || force_vec != 0)
        trace_printf("Remaining CONS : %" PRIu64 " VEC : %" PRIu64 "\n",
            force_cons, force_vec);
// If you pass a non-fixnum then that leaves the trigger-point unchanged.
    if (is_fixnum(a)) force_cons = (uint64_t)sixty_four_bits(a);
    if (is_fixnum(b)) force_vec = (uint64_t)sixty_four_bits(b);
    return onevalue(nil);
}

LispObject Lgc_forcer1(LispObject env, LispObject a)
{   return Lgc_forcer(env, a, a);
}

LispObject cons(LispObject a, LispObject b)
{   LispObject r = (LispObject)((char *)fringe - sizeof(Cons_Cell));
    qcar(r) = a;
    qcdr(r) = b;
    fringe = r;
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        (char *)r <= (char *)heaplimit || cons_forced(1))
        return reclaim((LispObject)((char *)r + TAG_CONS),
                       "internal cons", GC_CONS, 0);
    else return (LispObject)((char *)r + TAG_CONS);
}

LispObject cons_no_gc(LispObject a, LispObject b)
{   LispObject r = (LispObject)((char *)fringe - sizeof(Cons_Cell));
    qcar(r) = a;
    qcdr(r) = b;
    fringe = r;
    return (LispObject)((char *)r + TAG_CONS);
}

// cons_gc_test() MUST be called after any sequence of cons_no_gc() calls.

LispObject cons_gc_test(LispObject p)
{   if (++reclaim_trigger_count == reclaim_trigger_target ||
        (char *)fringe <= (char *)heaplimit)
        return reclaim(p, "cons gc test", GC_CONS, 0);
    else return p;
}

LispObject ncons(LispObject a)
{   LispObject r = (LispObject)((char *)fringe - sizeof(Cons_Cell));
    qcar(r) = a;
    qcdr(r) = nil;
    fringe = r;
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        (char *)r <= (char *)heaplimit || cons_forced(1))
        return reclaim((LispObject)((char *)r + TAG_CONS),
                       "internal ncons", GC_CONS, 0);
    else return (LispObject)((char *)r + TAG_CONS);
}

LispObject list2(LispObject a, LispObject b)
{
// Note that building two cons cells at once saves some overhead here
    LispObject r = (LispObject)((char *)fringe - 2*sizeof(Cons_Cell));
    qcar(r) = a;
    qcdr(r) = (LispObject)((char *)r + sizeof(Cons_Cell) + TAG_CONS);
    qcar((char *)r+sizeof(Cons_Cell)) = b;
    qcdr((char *)r+sizeof(Cons_Cell)) = nil;
    fringe = r;
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        (char *)r <= (char *)heaplimit || cons_forced(2))
        return reclaim((LispObject)((char *)r + TAG_CONS),
                       "internal list2", GC_CONS, 0);
    else return (LispObject)((char *)r + TAG_CONS);
}

LispObject list2star(LispObject a, LispObject b, LispObject c)
{   LispObject r = (LispObject)((char *)fringe - 2*sizeof(Cons_Cell));
    qcar(r) = a;
    qcdr(r) = (LispObject)((char *)r + sizeof(Cons_Cell) + TAG_CONS);
    qcar((char *)r+sizeof(Cons_Cell)) = b;
    qcdr((char *)r+sizeof(Cons_Cell)) = c;
    fringe = r;
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        (char *)r <= (char *)heaplimit || cons_forced(2))
        return reclaim((LispObject)((char *)r + TAG_CONS),
                       "internal list2*", GC_CONS, 0);
    else return (LispObject)((char *)r + TAG_CONS);
}

LispObject list2starrev(LispObject c, LispObject b, LispObject a)
{   LispObject r = (LispObject)((char *)fringe - 2*sizeof(Cons_Cell));
    qcar(r) = a;
    qcdr(r) = (LispObject)((char *)r + sizeof(Cons_Cell) + TAG_CONS);
    qcar((char *)r+sizeof(Cons_Cell)) = b;
    qcdr((char *)r+sizeof(Cons_Cell)) = c;
    fringe = r;
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        (char *)r <= (char *)heaplimit || cons_forced(2))
        return reclaim((LispObject)((char *)r + TAG_CONS),
                       "internal list2*", GC_CONS, 0);
    else return (LispObject)((char *)r + TAG_CONS);
}

LispObject list3star(LispObject a, LispObject b, LispObject c, LispObject d)
{   LispObject r = (LispObject)((char *)fringe - 3*sizeof(Cons_Cell));
    qcar(r) = a;
    qcdr(r) = (LispObject)((char *)r + sizeof(Cons_Cell) + TAG_CONS);
    qcar((char *)r+sizeof(Cons_Cell)) = b;
    qcdr((char *)r+sizeof(Cons_Cell)) =
        (LispObject)((char *)r + 2*sizeof(Cons_Cell) + TAG_CONS);
    qcar((char *)r+2*sizeof(Cons_Cell)) = c;
    qcdr((char *)r+2*sizeof(Cons_Cell)) = d;
    fringe = r;
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        (char *)r <= (char *)heaplimit || cons_forced(3))
        return reclaim((LispObject)((char *)r + TAG_CONS),
                       "internal list3*", GC_CONS, 0);
    else return (LispObject)((char *)r + TAG_CONS);
}

LispObject list4(LispObject a, LispObject b, LispObject c, LispObject d)
{   LispObject r = (LispObject)((char *)fringe - 4*sizeof(Cons_Cell));
    qcar(r) = a;
    qcdr(r) = (LispObject)((char *)r + sizeof(Cons_Cell) + TAG_CONS);
    qcar((char *)r+sizeof(Cons_Cell)) = b;
    qcdr((char *)r+sizeof(Cons_Cell)) =
        (LispObject)((char *)r + 2*sizeof(Cons_Cell) + TAG_CONS);
    qcar((char *)r+2*sizeof(Cons_Cell)) = c;
    qcdr((char *)r+2*sizeof(Cons_Cell)) =
        (LispObject)((char *)r + 3*sizeof(Cons_Cell) + TAG_CONS);
    qcar((char *)r +3*sizeof(Cons_Cell)) = d;
    qcdr((char *)r + 3*sizeof(Cons_Cell)) = nil;
    fringe = r;
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        (char *)r <= (char *)heaplimit || cons_forced(4))
        return reclaim((LispObject)((char *)r + TAG_CONS),
                       "internal list4", GC_CONS, 0);
    else return (LispObject)((char *)r + TAG_CONS);
}



LispObject acons(LispObject a, LispObject b, LispObject c)
{   LispObject r = (LispObject)((char *)fringe - 2*sizeof(Cons_Cell));
    qcar(r) = (LispObject)((char *)r + sizeof(Cons_Cell) + TAG_CONS);
    qcdr(r) = c;
    qcar((char *)r+sizeof(Cons_Cell)) = a;
    qcdr((char *)r+sizeof(Cons_Cell)) = b;
    fringe = r;
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        (char *)r <= (char *)heaplimit || cons_forced(2))
        return reclaim((LispObject)((char *)r + TAG_CONS),
                       "internal acons", GC_CONS, 0);
    else return (LispObject)((char *)r + TAG_CONS);
}

LispObject acons_no_gc(LispObject a, LispObject b, LispObject c)
{   LispObject r = (LispObject)((char *)fringe - 2*sizeof(Cons_Cell));
    qcar(r) = (LispObject)((char *)r + sizeof(Cons_Cell) + TAG_CONS);
    qcdr(r) = c;
    qcar((char *)r+sizeof(Cons_Cell)) = a;
    qcdr((char *)r+sizeof(Cons_Cell)) = b;
    fringe = r;
    return (LispObject)((char *)r + TAG_CONS);
}

LispObject list3(LispObject a, LispObject b, LispObject c)
{   LispObject r = (LispObject)((char *)fringe - 3*sizeof(Cons_Cell));
    qcar(r) = a;
    qcdr(r) = (LispObject)((char *)r + sizeof(Cons_Cell) + TAG_CONS);
    qcar((char *)r+sizeof(Cons_Cell)) = b;
    qcdr((char *)r+sizeof(Cons_Cell)) =
        (LispObject)((char *)r + 2*sizeof(Cons_Cell) + TAG_CONS);
    qcar((char *)r+2*sizeof(Cons_Cell)) = c;
    qcdr((char *)r+2*sizeof(Cons_Cell)) = nil;
    fringe = r;
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        (char *)r <= (char *)heaplimit || cons_forced(3))
        return reclaim((LispObject)((char *)r + TAG_CONS),
                       "internal list3", GC_CONS, 0);
    else return (LispObject)((char *)r + TAG_CONS);
}

LispObject list3rev(LispObject c, LispObject b, LispObject a)
{   LispObject r = (LispObject)((char *)fringe - 3*sizeof(Cons_Cell));
    qcar(r) = a;
    qcdr(r) = (LispObject)((char *)r + sizeof(Cons_Cell) + TAG_CONS);
    qcar((char *)r+sizeof(Cons_Cell)) = b;
    qcdr((char *)r+sizeof(Cons_Cell)) =
        (LispObject)((char *)r + 2*sizeof(Cons_Cell) + TAG_CONS);
    qcar((char *)r+2*sizeof(Cons_Cell)) = c;
    qcdr((char *)r+2*sizeof(Cons_Cell)) = nil;
    fringe = r;
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        (char *)r <= (char *)heaplimit || cons_forced(3))
        return reclaim((LispObject)((char *)r + TAG_CONS),
                       "internal list3", GC_CONS, 0);
    else return (LispObject)((char *)r + TAG_CONS);
}

/*****************************************************************************/
/*****************************************************************************/
//**              Lisp-callable versions of all the above                  **
/*****************************************************************************/
/*****************************************************************************/

//
// The set of car/cdr combinations here seem pretty dull, but they
// are fairly important for performance...
//

/*! fns [car] \item [{\ttfamily car} {\itshape expr}] \index{{\ttfamily car} {\itshape expr}} ~\newline
 * For a non-empty list the function {\ttfamily car} will return the
 * first element. For a dotted pair (created using {\ttfamily cons})
 * it extracts the first component. This is the fundamental low-level
 * data structure access function in Lisp. See {\ttfamily cdr} for the
 * function that returns the tail or a list or the second component of
 * a dotted pair. In CSL any attempt to take {\ttfamily car} of an atom
 * should be detected and will be treated as an error. If CSL had been
 * compiled in Common Lisp mode (which is now not probable) a special
 * exemption would apply and {\ttfamily car} and {\ttfamily cdr} of the
 * empty lisp {\ttfamily nil} would be {\ttfamily nil}.
 */

LispObject Lcar(LispObject, LispObject a)
{   if (!car_legal(a)) return onevalue(carerror(a));
    else return onevalue(qcar(a));
}

//
// (car* a) = (car a) if a is non-atomic, but just a otherwise.
//

/*! fns [car*] \item[{\ttfamily car!*} {\itshape expr}] \index{{\ttfamily car"!*} {\itshape expr}} ~\newline
 * This function behaves like {\ttfamily car} except that if its argument
 * is atomic then the argument is returned unaltered rather than that case
 * being treated as an error.
 */

LispObject Lcar_star(LispObject, LispObject a)
{   if (!car_legal(a)) return onevalue(a);
    else return onevalue(qcar(a));
}

/*! fns [cdr] \item [{\ttfamily cdr} {\itshape expr}] \index{{\ttfamily cdr} {\itshape expr}} ~\newline
 * See {\ttfamily car}.
 */

LispObject Lcdr(LispObject, LispObject a)
{   if (!car_legal(a)) return onevalue(cdrerror(a));
    else return onevalue(qcdr(a));
}

/*! fns [caar] \item [{\ttfamily caar \ldots cddddr} {\itshape expr}] \index{{\ttfamily caar \ldots cddddr} {\itshape expr}} ~\newline
 * Names that start with {\ttfamily c}, then have a sequence of
 * {\ttfamily a} or {\ttfamily d}s and finally {\ttfamily r} provide
 * shorthand functions for chains of uses of {\ttfamily car} and
 * {\ttfamily cdr}. Thus for instance
 * {\ttfamily (cadar x)} has the same meaning as
 * {\ttfamily (car (cdr (car x)))}.
 */

LispObject Lcaar(LispObject, LispObject a)
{   if (!car_legal(a)) return onevalue(carerror(a));
    else a = qcar(a);
    if (!car_legal(a)) return onevalue(carerror(a));
    else return onevalue(qcar(a));
}

/*! fns [cadr] \item [{\ttfamily  cadr} {\itshape expr}] \index{{\ttfamily  cadr} {\itshape expr}} ~\newline
 * see {\ttfamily caar} and {\ttfamily second}.
 */

LispObject Lcadr(LispObject, LispObject a)
{   if (!car_legal(a)) return onevalue(cdrerror(a));
    else a = qcdr(a);
    if (!car_legal(a)) return onevalue(carerror(a));
    else return onevalue(qcar(a));
}

/*! fns [cdar] \item[{\ttfamily cdar} {\itshape expr}] \index{{\ttfamily cdar} {\itshape expr}} ~\newline
 * see {\ttfamily caar}.
 */

LispObject Lcdar(LispObject, LispObject a)
{   if (!car_legal(a)) return onevalue(carerror(a));
    else a = qcar(a);
    if (!car_legal(a)) return onevalue(cdrerror(a));
    else return onevalue(qcdr(a));
}

/*! fns [cddr] \item[{\ttfamily cddr} {\itshape expr}] \index{{\ttfamily cddr} {\itshape expr}} ~\newline
 * see {\ttfamily caar}.
 */

LispObject Lcddr(LispObject, LispObject a)
{   if (!car_legal(a)) return onevalue(cdrerror(a));
    else a = qcdr(a);
    if (!car_legal(a)) return onevalue(cdrerror(a));
    else return onevalue(qcdr(a));
}

/*! fns [caaar] \item[{\ttfamily caaar} {\itshape expr}] \index{{\ttfamily caaar} {\itshape expr}} ~\newline
 * see {\ttfamily caar}.
 */

LispObject Lcaaar(LispObject, LispObject a)
{   if (!car_legal(a)) return onevalue(carerror(a));
    else a = qcar(a);
    if (!car_legal(a)) return onevalue(carerror(a));
    else a = qcar(a);
    if (!car_legal(a)) return onevalue(carerror(a));
    else return onevalue(qcar(a));
}

/*! fns [caadr] \item[{\ttfamily caadr} {\itshape expr}] \index{{\ttfamily caadr} {\itshape expr}} ~\newline
 * see {\ttfamily caar}.
 */

LispObject Lcaadr(LispObject, LispObject a)
{   if (!car_legal(a)) return onevalue(cdrerror(a));
    else a = qcdr(a);
    if (!car_legal(a)) return onevalue(carerror(a));
    else a = qcar(a);
    if (!car_legal(a)) return onevalue(carerror(a));
    else return onevalue(qcar(a));
}

/*! fns [cadar] \item[{\ttfamily cadar} {\itshape expr}] \index{{\ttfamily cadar} {\itshape expr}} ~\newline
 * see {\ttfamily caar}.
 */

LispObject Lcadar(LispObject, LispObject a)
{   if (!car_legal(a)) return onevalue(carerror(a));
    else a = qcar(a);
    if (!car_legal(a)) return onevalue(cdrerror(a));
    else a = qcdr(a);
    if (!car_legal(a)) return onevalue(carerror(a));
    else return onevalue(qcar(a));
}

/*! fns [caddr] \item[{\ttfamily caddr} {\itshape expr}] \index{{\ttfamily caddr} {\itshape expr}} ~\newline
 * see {\ttfamily caar} and {\ttfamily third}.
 */

LispObject Lcaddr(LispObject, LispObject a)
{   if (!car_legal(a)) return onevalue(cdrerror(a));
    else a = qcdr(a);
    if (!car_legal(a)) return onevalue(cdrerror(a));
    else a = qcdr(a);
    if (!car_legal(a)) return onevalue(carerror(a));
    else return onevalue(qcar(a));
}

/*! fns [cdaar] \item[{\ttfamily cdaar} {\itshape expr}] \index{{\ttfamily cdaar} {\itshape expr}} ~\newline
 * see {\ttfamily caar}.
 */

LispObject Lcdaar(LispObject, LispObject a)
{   if (!car_legal(a)) return onevalue(carerror(a));
    else a = qcar(a);
    if (!car_legal(a)) return onevalue(carerror(a));
    else a = qcar(a);
    if (!car_legal(a)) return onevalue(cdrerror(a));
    else return onevalue(qcdr(a));
}

/*! fns [cdadr] \item[{\ttfamily cdadr} {\itshape expr}] \index{{\ttfamily cdadr} {\itshape expr}} ~\newline
 * see {\ttfamily caar}.
 */

LispObject Lcdadr(LispObject, LispObject a)
{   if (!car_legal(a)) return onevalue(cdrerror(a));
    else a = qcdr(a);
    if (!car_legal(a)) return onevalue(carerror(a));
    else a = qcar(a);
    if (!car_legal(a)) return onevalue(cdrerror(a));
    else return onevalue(qcdr(a));
}

/*! fns [cddar] \item[{\ttfamily cddar} {\itshape expr}] \index{{\ttfamily cddar} {\itshape expr}} ~\newline
 * see {\ttfamily caar}.
 */

LispObject Lcddar(LispObject, LispObject a)
{   if (!car_legal(a)) return onevalue(carerror(a));
    else a = qcar(a);
    if (!car_legal(a)) return onevalue(cdrerror(a));
    else a = qcdr(a);
    if (!car_legal(a)) return onevalue(cdrerror(a));
    else return onevalue(qcdr(a));
}

/*! fns [cdddr] \item[{\ttfamily cdddr} {\itshape expr}] \index{{\ttfamily cdddr} {\itshape expr}} ~\newline
 * see {\ttfamily caar}.
 */

LispObject Lcdddr(LispObject, LispObject a)
{   if (!car_legal(a)) return onevalue(cdrerror(a));
    else a = qcdr(a);
    if (!car_legal(a)) return onevalue(cdrerror(a));
    else a = qcdr(a);
    if (!car_legal(a)) return onevalue(cdrerror(a));
    else return onevalue(qcdr(a));
}

/*! fns [caaaar] \item[{\ttfamily caaaar} {\itshape expr}] \index{{\ttfamily caaaar} {\itshape expr}} ~\newline
 * see {\ttfamily caar}.
 */

LispObject Lcaaaar(LispObject, LispObject a)
{   if (!car_legal(a)) return onevalue(carerror(a));
    else a = qcar(a);
    if (!car_legal(a)) return onevalue(carerror(a));
    else a = qcar(a);
    if (!car_legal(a)) return onevalue(carerror(a));
    else a = qcar(a);
    if (!car_legal(a)) return onevalue(carerror(a));
    else return onevalue(qcar(a));
}

/*! fns [caaadr] \item[{\ttfamily caaadr} {\itshape expr}] \index{{\ttfamily caaadr} {\itshape expr}} ~\newline
 * see {\ttfamily caar}.
 */

LispObject Lcaaadr(LispObject, LispObject a)
{   if (!car_legal(a)) return onevalue(cdrerror(a));
    else a = qcdr(a);
    if (!car_legal(a)) return onevalue(carerror(a));
    else a = qcar(a);
    if (!car_legal(a)) return onevalue(carerror(a));
    else a = qcar(a);
    if (!car_legal(a)) return onevalue(carerror(a));
    else return onevalue(qcar(a));
}

/*! fns [caadar] \item[{\ttfamily caadar} {\itshape expr}] \index{{\ttfamily caadar} {\itshape expr}} ~\newline
 * see {\ttfamily caar}.
 */

LispObject Lcaadar(LispObject, LispObject a)
{   if (!car_legal(a)) return onevalue(carerror(a));
    else a = qcar(a);
    if (!car_legal(a)) return onevalue(cdrerror(a));
    else a = qcdr(a);
    if (!car_legal(a)) return onevalue(carerror(a));
    else a = qcar(a);
    if (!car_legal(a)) return onevalue(carerror(a));
    else return onevalue(qcar(a));
}

/*! fns [caaddr] \item[{\ttfamily caaddr} {\itshape expr}] \index{{\ttfamily caaddr} {\itshape expr}} ~\newline
 * see {\ttfamily caar}.
 */

LispObject Lcaaddr(LispObject, LispObject a)
{   if (!car_legal(a)) return onevalue(cdrerror(a));
    else a = qcdr(a);
    if (!car_legal(a)) return onevalue(cdrerror(a));
    else a = qcdr(a);
    if (!car_legal(a)) return onevalue(carerror(a));
    else a = qcar(a);
    if (!car_legal(a)) return onevalue(carerror(a));
    else return onevalue(qcar(a));
}

/*! fns [cadaar] \item[{\ttfamily cadaar} {\itshape expr}] \index{{\ttfamily cadaar} {\itshape expr}} ~\newline
 * see {\ttfamily caar}.
 */

LispObject Lcadaar(LispObject, LispObject a)
{   if (!car_legal(a)) return onevalue(carerror(a));
    else a = qcar(a);
    if (!car_legal(a)) return onevalue(carerror(a));
    else a = qcar(a);
    if (!car_legal(a)) return onevalue(cdrerror(a));
    else a = qcdr(a);
    if (!car_legal(a)) return onevalue(carerror(a));
    else return onevalue(qcar(a));
}

/*! fns [cadadr] \item[{\ttfamily cadadr} {\itshape expr}] \index{{\ttfamily cadadr} {\itshape expr}} ~\newline
 * see {\ttfamily caar}.
 */

LispObject Lcadadr(LispObject, LispObject a)
{   if (!car_legal(a)) return onevalue(cdrerror(a));
    else a = qcdr(a);
    if (!car_legal(a)) return onevalue(carerror(a));
    else a = qcar(a);
    if (!car_legal(a)) return onevalue(cdrerror(a));
    else a = qcdr(a);
    if (!car_legal(a)) return onevalue(carerror(a));
    else return onevalue(qcar(a));
}

/*! fns [caddar] \item[{\ttfamily caddar} {\itshape expr}] \index{{\ttfamily caddar} {\itshape expr}} ~\newline
 * see {\ttfamily caar}.
 */

LispObject Lcaddar(LispObject, LispObject a)
{   if (!car_legal(a)) return onevalue(carerror(a));
    else a = qcar(a);
    if (!car_legal(a)) return onevalue(cdrerror(a));
    else a = qcdr(a);
    if (!car_legal(a)) return onevalue(cdrerror(a));
    else a = qcdr(a);
    if (!car_legal(a)) return onevalue(carerror(a));
    else return onevalue(qcar(a));
}

/*! fns [cadddr] \item[{\ttfamily cadddr} {\itshape expr}] \index{{\ttfamily cadddr} {\itshape expr}} ~\newline
 * see {\ttfamily caar} and {\ttfamily fourth}.
 */

LispObject Lcadddr(LispObject, LispObject a)
{   if (!car_legal(a)) return onevalue(cdrerror(a));
    else a = qcdr(a);
    if (!car_legal(a)) return onevalue(cdrerror(a));
    else a = qcdr(a);
    if (!car_legal(a)) return onevalue(cdrerror(a));
    else a = qcdr(a);
    if (!car_legal(a)) return onevalue(carerror(a));
    else return onevalue(qcar(a));
}

/*! fns [cdaaar] \item[{\ttfamily cdaaar} {\itshape expr}] \index{{\ttfamily cdaaar} {\itshape expr}} ~\newline
 * see {\ttfamily caar}.
 */

LispObject Lcdaaar(LispObject, LispObject a)
{   if (!car_legal(a)) return onevalue(carerror(a));
    else a = qcar(a);
    if (!car_legal(a)) return onevalue(carerror(a));
    else a = qcar(a);
    if (!car_legal(a)) return onevalue(carerror(a));
    else a = qcar(a);
    if (!car_legal(a)) return onevalue(cdrerror(a));
    else return onevalue(qcdr(a));
}

/*! fns [cdaadr] \item[{\ttfamily cdaadr} {\itshape expr}] \index{{\ttfamily cdaadr} {\itshape expr}} ~\newline
 * see {\ttfamily caar}.
 */

LispObject Lcdaadr(LispObject, LispObject a)
{   if (!car_legal(a)) return onevalue(cdrerror(a));
    else a = qcdr(a);
    if (!car_legal(a)) return onevalue(carerror(a));
    else a = qcar(a);
    if (!car_legal(a)) return onevalue(carerror(a));
    else a = qcar(a);
    if (!car_legal(a)) return onevalue(cdrerror(a));
    else return onevalue(qcdr(a));
}

/*! fns [cdadar] \item[{\ttfamily cdadar} {\itshape expr}] \index{{\ttfamily cdadar} {\itshape expr}} ~\newline
 * see {\ttfamily caar}.
 */

LispObject Lcdadar(LispObject, LispObject a)
{   if (!car_legal(a)) return onevalue(carerror(a));
    else a = qcar(a);
    if (!car_legal(a)) return onevalue(cdrerror(a));
    else a = qcdr(a);
    if (!car_legal(a)) return onevalue(carerror(a));
    else a = qcar(a);
    if (!car_legal(a)) return onevalue(cdrerror(a));
    else return onevalue(qcdr(a));
}

/*! fns [cdaddr] \item[{\ttfamily cdaddr} {\itshape expr}] \index{{\ttfamily cdaddr} {\itshape expr}} ~\newline
 * see {\ttfamily caar}.
 */

LispObject Lcdaddr(LispObject, LispObject a)
{   if (!car_legal(a)) return onevalue(cdrerror(a));
    else a = qcdr(a);
    if (!car_legal(a)) return onevalue(cdrerror(a));
    else a = qcdr(a);
    if (!car_legal(a)) return onevalue(carerror(a));
    else a = qcar(a);
    if (!car_legal(a)) return onevalue(cdrerror(a));
    else return onevalue(qcdr(a));
}

/*! fns [cddaar] \item[{\ttfamily cddaar} {\itshape expr}] \index{{\ttfamily cddaar} {\itshape expr}} ~\newline
 * see {\ttfamily caar}.
 */

LispObject Lcddaar(LispObject, LispObject a)
{   if (!car_legal(a)) return onevalue(carerror(a));
    else a = qcar(a);
    if (!car_legal(a)) return onevalue(carerror(a));
    else a = qcar(a);
    if (!car_legal(a)) return onevalue(cdrerror(a));
    else a = qcdr(a);
    if (!car_legal(a)) return onevalue(cdrerror(a));
    else return onevalue(qcdr(a));
}

/*! fns [cddadr] \item[{\ttfamily cddadr} {\itshape expr}] \index{{\ttfamily cddadr} {\itshape expr}} ~\newline
 * see {\ttfamily caar}.
 */

LispObject Lcddadr(LispObject, LispObject a)
{   if (!car_legal(a)) return onevalue(cdrerror(a));
    else a = qcdr(a);
    if (!car_legal(a)) return onevalue(carerror(a));
    else a = qcar(a);
    if (!car_legal(a)) return onevalue(cdrerror(a));
    else a = qcdr(a);
    if (!car_legal(a)) return onevalue(cdrerror(a));
    else return onevalue(qcdr(a));
}

/*! fns [cdddar] \item[{\ttfamily cdddar} {\itshape expr}] \index{{\ttfamily cdddar} {\itshape expr}} ~\newline
 * see {\ttfamily caar}.
 */

LispObject Lcdddar(LispObject, LispObject a)
{   if (!car_legal(a)) return onevalue(carerror(a));
    else a = qcar(a);
    if (!car_legal(a)) return onevalue(cdrerror(a));
    else a = qcdr(a);
    if (!car_legal(a)) return onevalue(cdrerror(a));
    else a = qcdr(a);
    if (!car_legal(a)) return onevalue(cdrerror(a));
    else return onevalue(qcdr(a));
}

/*! fns [cddddr] \item[{\ttfamily cddddr} {\itshape expr}] \index{{\ttfamily cddddr} {\itshape expr}} ~\newline
 * see {\ttfamily caar}.
 */

LispObject Lcddddr(LispObject, LispObject a)
{   if (!car_legal(a)) return onevalue(cdrerror(a));
    else a = qcdr(a);
    if (!car_legal(a)) return onevalue(cdrerror(a));
    else a = qcdr(a);
    if (!car_legal(a)) return onevalue(cdrerror(a));
    else a = qcdr(a);
    if (!car_legal(a)) return onevalue(cdrerror(a));
    else return onevalue(qcdr(a));
}

/*! fns [rplaca] \item[{\ttfamily rplaca} {\itshape expr}] \index{{\ttfamily rplaca} {\itshape expr}} ~\newline
 * This is a destructive function in that it alters the data structure
 * that it is given as its first argument by updating its {\ttfamily car}
 * component. The result is the updated object. See {\ttfamily rplacd}
 * for the corresponding function for updating the {\ttfamily cdr} component.
 */

LispObject Lrplaca(LispObject,
                   LispObject a, LispObject b)
{   if (!consp(a)) error(1, err_bad_rplac, a);
    qcar(a) = b;
    return onevalue(a);
}

/*! fns [rplacd] \item [{\ttfamily rplacd} {\itshape expr}] \index{{\ttfamily rplacd} {\itshape expr}} ~\newline
 * See {\ttfamily rplaca}
 */

LispObject Lrplacd(LispObject,
                   LispObject a, LispObject b)
{   if (!consp(a)) error(1, err_bad_rplac, a);
    qcdr(a) = b;
    return onevalue(a);
}

LispObject Lsymbolp(LispObject env, LispObject a)
{   return onevalue(Lispify_predicate(symbolp(a)));
}

LispObject Latom(LispObject env, LispObject a)
{   return onevalue(Lispify_predicate(!consp(a)));
}

LispObject Lconsp(LispObject env, LispObject a)
{   return onevalue(Lispify_predicate(consp(a)));
}

LispObject Lconstantp(LispObject env, LispObject a)
//
// This version is as required for Standard Lisp - it is inadequate
// for Common Lisp.
//
{
//
// Standard Lisp requires that I report that "Function Pointers" are
// "constant" here. It is not at all clear that I have a way of
// doing that. I will go some way by ensuring that code-vectors are
// reported as constant.
//
    return onevalue(Lispify_predicate(
                        a == nil || a == lisp_true ||
                        is_char(a) ||
                        is_number(a) ||
                        is_vector(a) ||
                        is_bps(a)));
}

LispObject Lidentity(LispObject, LispObject a)
{   return onevalue(a);
}

LispObject Llistp(LispObject env, LispObject a)
{   return onevalue(Lispify_predicate(is_cons(a)));
}

LispObject Lnumberp(LispObject env, LispObject a)
{   return onevalue(Lispify_predicate(is_number(a)));
}

LispObject Lintegerp(LispObject, LispObject a)
{   return onevalue(integerp(a));
}

LispObject Leq_safe(LispObject env, LispObject a)
{
//
// True if you can safely use EQ tests to check equality. Thus true for
// things that are represented in "immediate" form... and ALSO of nil
// and all other symbols.
//
    return onevalue(symbolp(a) ||
                    is_fixnum(a) ||
                    is_sfloat(a) ||
                    is_odds(a) ? lisp_true : nil);
}

LispObject Lfixp(LispObject env, LispObject a)
{
#ifdef COMMON
    return onevalue(is_fixnum(a) ? lisp_true : nil);
#else
//
// Standard Lisp defines fixp to say yes to bignums as well as
// fixnums. The code here is as in intergerp.
//
    if (is_fixnum(a)) return onevalue(lisp_true);
    else if (is_numbers(a))
    {   Header h = *(Header *)((char *)a - TAG_NUMBERS);
        if (type_of_header(h) == TYPE_BIGNUM) return onevalue(lisp_true);
        else return onevalue(nil);
    }
    else return onevalue(nil);
#endif
}

LispObject Lfloatp(LispObject env, LispObject p)
{   if (is_bfloat(p)) return onevalue(lisp_true);
    else if (is_sfloat(p)) return onevalue(lisp_true);
    else return onevalue(nil);
}

static LispObject Lshort_floatp(LispObject env, LispObject p)
{   if (is_sfloat(p) &&
        (!SIXTY_FOUR_BIT ||
         ((p & XTAG_FLOAT32) == 0))) return onevalue(lisp_true);
    else return onevalue(nil);
}

static LispObject Lsingle_floatp(LispObject env, LispObject p)
{   int tag = TAG_BITS & (int)p;
    if (SIXTY_FOUR_BIT &&
        is_sfloat(p) &&
        (p & XTAG_FLOAT32) != 0) return onevalue(lisp_true); 
    if (tag == TAG_BOXFLOAT &&
        type_of_header(flthdr(p)) == TYPE_SINGLE_FLOAT)
        return onevalue(lisp_true);
    else return onevalue(nil);
}

static LispObject Ldouble_floatp(LispObject env, LispObject p)
{   int tag = TAG_BITS & (int)p;
    if (tag == TAG_BOXFLOAT &&
        type_of_header(flthdr(p)) == TYPE_DOUBLE_FLOAT)
        return onevalue(lisp_true);
    else return onevalue(nil);
}

static LispObject Llong_floatp(LispObject env, LispObject p)
{   int tag = TAG_BITS & (int)p;
    if (tag == TAG_BOXFLOAT &&
        type_of_header(flthdr(p)) == TYPE_LONG_FLOAT)
        return onevalue(lisp_true);
    else return onevalue(nil);
}

static LispObject Lmantissa_bits(LispObject env, LispObject p)
{   if (Ldouble_floatp(env, p) != nil) return onevalue(fixnum_of_int(53));
    if (Lsingle_floatp(env, p) != nil) return onevalue(fixnum_of_int(24));
    if (Lshort_floatp(env, p) != nil) return onevalue(fixnum_of_int(20));
    if (Llong_floatp(env, p) != nil) return onevalue(fixnum_of_int(113));
    return onevalue(nil);
}

LispObject Lrationalp(LispObject env, LispObject a)
{   return onevalue(
               Lispify_predicate(
                   is_fixnum(a) ||
                   (is_numbers(a) &&
                    (is_bignum(a) || is_ratio(a)))));
}

LispObject Lcomplexp(LispObject env, LispObject a)
{   return onevalue(Lispify_predicate(is_numbers(a) && is_complex(a)));
}

bool complex_stringp(LispObject a)
//
// true if the arg is a string, but NOT a simple string.  In general
// when this is true simplify_string() will then be called to do
// an adjustment.
//
{   Header h;
    LispObject w;
    if (!is_vector(a)) return false;
    h = vechdr(a);
    if (type_of_header(h) != TYPE_ARRAY) return false;
//
// Note that the cheery Common Lisp Committee decided the abolish the
// separate type 'string-char, so the test here is maybe dubious...
//
    else if (elt(a, 0) != string_char_sym) return false;
    w = elt(a, 1);
    if (!consp(w) || consp(qcdr(w))) return false;
    else return true;
}

LispObject Lwarn_about_protected_symbols(LispObject env, LispObject a)
{   LispObject retval = Lispify_predicate(warn_about_protected_symbols);
    warn_about_protected_symbols = (a != nil);
    return onevalue(retval);
}

LispObject Lprotect_symbols(LispObject env, LispObject a)
{   LispObject retval = Lispify_predicate(symbol_protect_flag);
    symbol_protect_flag = (a != nil);
    return onevalue(retval);
}

bool stringp(LispObject a)
//
// True if arg is a simple OR a general string
//
{   Header h;
    LispObject w;
    if (!is_vector(a)) return false;
    h = vechdr(a);
    if (is_string_header(h)) return true;
    else if (type_of_header(h) != TYPE_ARRAY) return false;
//
// Beware abolition of 'string-char
//
    else if (elt(a, 0) != string_char_sym) return false;
    w = elt(a, 1);
    if (!consp(w) || consp(qcdr(w))) return false;
    else return true;
}

LispObject Lstringp(LispObject env, LispObject a)
//
// simple-string-p
//
{   if (!(is_vector(a)) || !is_string(a)) return onevalue(nil);
    else return onevalue(lisp_true);
}

// Common Lisp has "complicated strings" which may have fill pointers,
// indirection to their contents and basically be unnecessary generalisations
// of what one really uses.

static LispObject Lc_stringp(LispObject env, LispObject a)
{   return onevalue(Lispify_predicate(stringp(a)));
}

LispObject Lhash_table_p(LispObject env, LispObject a)
//
// hash-table-p
//
{   if (!(is_vector(a)) || type_of_header(vechdr(a)) != TYPE_HASH)
        return onevalue(nil);
    else return onevalue(lisp_true);
}

static LispObject Lsimple_bit_vector_p(LispObject env,
                                       LispObject a)
//
// simple-bit-vector-p
//
{   if (!(is_vector(a))) return onevalue(nil);
    else return onevalue(Lispify_predicate(is_bitvec_header(vechdr(a))));
}

LispObject Lsimple_vectorp(LispObject env, LispObject a)
//
// simple-vector-p
//
{   if (!(is_vector(a))) return onevalue(nil);
    else return onevalue(Lispify_predicate(
                                 type_of_header(vechdr(a))==TYPE_SIMPLE_VEC));
}

LispObject Lbpsp(LispObject env, LispObject a)
{   if (!(is_bps(a))) return onevalue(nil);
    else return onevalue(lisp_true);
}

LispObject Lthreevectorp(LispObject env, LispObject a)
//
// This is useful for REDUCE - it checks if something is a vector
// of size 3!
//
{   if (!(is_vector(a))) return onevalue(nil);
// The "pack_hdrlength(4*CELL/4)" is because I want a vector
// with 1 cell of header and 3 of data. So the 4*CELL deals with with that
// but gives a size expressed in bytes. The "/4" then converts that to a
// count expressed in 32-bit words which is what pach_hdrlength requires.
    return onevalue(Lispify_predicate(
        vechdr(a) == (TAG_HDR_IMMED + TYPE_SIMPLE_VEC +
            pack_hdrlength(4*CELL/4))));
}

static LispObject Larrayp(LispObject env, LispObject a)
{   Header h;
    if (!(is_vector(a))) return onevalue(nil);
    h = vechdr(a);
//
// I could consider accepting TYPE_VEC16 and TYPE_VEC32 etc here...
//
// Note that the suggestion that a string is an array is a real problem
// in a world that believes in Unicode...
    if (type_of_header(h)==TYPE_ARRAY ||
        is_string_header(h) ||
        type_of_header(h)==TYPE_SIMPLE_VEC ||
        is_bitvec_header(h)) return onevalue(lisp_true);
    else return onevalue(nil);
}

static LispObject Lcomplex_arrayp(LispObject env, LispObject a)
{   if (!(is_vector(a))) return onevalue(nil);
    else return onevalue(Lispify_predicate(
                                 type_of_header(vechdr(a))==TYPE_ARRAY));
}

static LispObject Lconvert_to_array(LispObject env, LispObject a)
{   if (!(is_basic_vector(a))) return onevalue(nil);
    vechdr(a) = TYPE_ARRAY + (vechdr(a) & ~header_mask);
    return onevalue(a);
}

static LispObject Lstructp(LispObject env, LispObject a)
//
// structp
//
{   if (!(is_basic_vector(a))) return onevalue(nil);
    else return onevalue(Lispify_predicate(
                                 type_of_header(vechdr(a))==TYPE_STRUCTURE));
}

static LispObject Lconvert_to_struct(LispObject env, LispObject a)
{   if (!(is_basic_vector(a))) return onevalue(nil);
    vechdr(a) = TYPE_STRUCTURE + (vechdr(a) & ~header_mask);
    return onevalue(a);
}

LispObject Lcons(LispObject, LispObject a, LispObject b)
{   LispObject r;
    r = (LispObject)((char *)fringe - sizeof(Cons_Cell));
    qcar(r) = a;
    qcdr(r) = b;
    fringe = r;
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        (char *)r <= (char *)heaplimit || cons_forced(1))
        return onevalue(reclaim((LispObject)((char *)r + TAG_CONS),
                                "cons", GC_CONS, 0));
    else return onevalue((LispObject)((char *)r + TAG_CONS));
}

LispObject Lxcons(LispObject, LispObject a, LispObject b)
{   LispObject r;
    r = (LispObject)((char *)fringe - sizeof(Cons_Cell));
    qcar(r) = b;
    qcdr(r) = a;
    fringe = r;
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        (char *)r <= (char *)heaplimit || cons_forced(1))
        return onevalue(reclaim((LispObject)((char *)r + TAG_CONS),
                                "xcons", GC_CONS, 0));
    else return onevalue((LispObject)((char *)r + TAG_CONS));
}

LispObject Lnilfn(LispObject)
{   return onevalue(nil);
}

LispObject Lncons(LispObject env, LispObject a)
{   LispObject r;
    r = (LispObject)((char *)fringe - sizeof(Cons_Cell));
    qcar(r) = a;
    qcdr(r) = nil;
    fringe = r;
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        (char *)r <= (char *)heaplimit || cons_forced(1))
        return onevalue(reclaim((LispObject)((char *)r + TAG_CONS),
                                "ncons", GC_CONS, 0));
    else return onevalue((LispObject)((char *)r + TAG_CONS));
}

LispObject Llist_2(LispObject env, LispObject a, LispObject b)
{   a = list2(a, b);
    return onevalue(a);
}

LispObject Lmkquote(LispObject env, LispObject a)
{   a = list2(quote_symbol, a);
    return onevalue(a);
}

LispObject Llist_2star(LispObject env, LispObject a, LispObject b, LispObject c)
{   return onevalue(list2star(a,b,c));
}

LispObject Llist_2starrev(LispObject env, LispObject a, LispObject b, LispObject c)
{   return onevalue(list2starrev(a,b,c));
}

LispObject Lacons(LispObject env, LispObject a, LispObject b, LispObject c)
{   return onevalue(acons(a, b, c));
}

LispObject Llist_3(LispObject env, LispObject a, LispObject b, LispObject c)
{   return onevalue(list3(a, b, c));
}

LispObject Llist_3rev(LispObject env, LispObject a, LispObject b, LispObject c)
{   return onevalue(list3rev(a, b, c));
}

LispObject Llist_3star(LispObject, LispObject a, LispObject b, LispObject c, LispObject a4up)
{   if (qcdr(a4up) != nil) aerror("too many arrguments for list3*");
    LispObject d = qcar(a4up);
    return onevalue(list3star(a,b,c,d));
}

LispObject Llist_4(LispObject env, LispObject a, LispObject b, LispObject c, LispObject a4up)
{   if (qcdr(a4up) != nil) aerror("too many arguments for list4");
    LispObject d = qcar(a4up);
    return onevalue(list4(a,b,c,d));
}


LispObject Llist_4up(LispObject env, LispObject a, LispObject b,
        LispObject c, LispObject a4up)
{   return onevalue(list3star(a, b, c, a4up));
}

LispObject Lliststar_4up(LispObject env, LispObject a, LispObject b,
        LispObject c, LispObject a4up)
{   LispObject r= nil, w;
    while (a4up != nil)
    {   w = qcdr(a4up);
        qcdr(a4up) = r;
        r = a4up;
        a4up = w;
    }
    a4up = qcar(r);
    r = qcdr(r);
    while (r != nil)
    {   w = qcdr(r);
        qcdr(r) = a4up;
        a4up = r;
        r = w;
    }
    return onevalue(a4up);
}

LispObject Lpair(LispObject env, LispObject a, LispObject b)
{   LispObject r = nil;
    while (consp(a) && consp(b))
    {   push2(a, b);
        r = acons(qcar(a), qcar(b), r);
        pop2(b, a);
        a = qcdr(a);
        b = qcdr(b);
    }
    a = nil;
    while (r != nil)
    {   b = qcdr(r);
        qcdr(r) = a;
        a = r;
        r = b;
    }
    return onevalue(a);
}


static size_t membercount(LispObject a, LispObject b)
//
// Counts how many times a is a member of the list b
//
{   size_t r = 0;
    if (is_symbol(a) || is_fixnum(a))
    {   while (consp(b))
        {   if (a == qcar(b)) r++;
            b = qcdr(b);
        }
        return r;
    }
    while (consp(b))
    {   LispObject cb = qcar(b);
        if (equal(a, cb)) r++;
        b = qcdr(b);
    }
    return r;
}

//
// INTERSECTION(A,B)
// The result will have its items in the order that they occur in A.
// If lists A and B contain duplicate items these will appear in the
// output if and only if the items involved are duplicated in both
// input lists.
//
LispObject Lintersect(LispObject env, LispObject a, LispObject b)
{   LispObject r = nil, w;
    push(b);
    while (consp(a))
    {   push2(a, r);
        w = Lmember(nil, qcar(a), stack[-2]);
// Here I ignore any item in a that is not also in b
        if (w != nil)
        {   size_t n1 = membercount(qcar(stack[-1]), stack[0]);
//
// Here I want to arrange that items only appear in the result list multiple
// times if they occur multiple times in BOTH the input lists.
//
            if (n1 != 0)
            {   size_t n2 = membercount(qcar(stack[-1]), stack[-2]);
                if (n2 > n1) n1 = 0;
            }
            if (n1 == 0)
            {   pop(r);
                a = stack[0];
                r = cons(qcar(a), r);
                pop(a);
            }
            else pop2(r, a);
        }
        else pop2(r, a);
        a = qcdr(a);
    }
    popv(1);
    a = nil;
    while (consp(r))
    {   b = r;
        r = qcdr(r);
        qcdr(b) = a;
        a = b;
    }
    return onevalue(a);
}

// If you have two lists where all items in both lists are just symbols
// then I can form the intersection in deterministic linear time using a
// tag bit in symbol headers.

class tidy_intersect
{   LispObject *save;
public:
    tidy_intersect()
    {   save = stack;
    }
    ~tidy_intersect()
    {   stack = save;
        LispObject b;
        pop(b);
        while (consp(b))
        {   qheader(qcar(b)) &= ~(Header)SYM_TAGGED;
            b = qcdr(b);
        }
    }
};

LispObject Lintersect_symlist(LispObject env, LispObject a, LispObject b)
{   LispObject r = nil, w;
// First tag all the symbols in the list b. Any items that are not
// symbols just get ignored.
    for (w = b; consp(w); w = qcdr(w))
    {   LispObject x = qcar(w);
        if (is_symbol(x)) qheader(x) |= SYM_TAGGED;
    }
// Now for each item in a push it onto a result list (r) if it a
// symbol that is tagged, i.e. if it was present in b.
    {   tidy_intersect RAII;
        while (consp(a))
        {   LispObject x = qcar(a);
            if (is_symbol(x) && (qheader(x) & SYM_TAGGED))
            {   push(a);
                r = cons(x, r);
                pop(a);
            }
            a = qcdr(a);
        }
    }
// The above built up the result in reversed order, so I fix that here.
    a = nil;
    while (consp(r))
    {   b = r;
        r = qcdr(r);
        qcdr(b) = a;
        a = b;
    }
    return onevalue(a);
}

//
// UNION(A, B)
// This works by consing onto the front of B each element of A that
// is not already in B.  Thus items in A (but not already in B) get
// added in reversed order.  Duplicates in B remain there, and but
// duplicates in A are dropped.
//
LispObject Lunion(LispObject env, LispObject a, LispObject b)
{   while (consp(a))
    {   LispObject c;
        push2(a, b);
        c = Lmember(nil, qcar(a), b);
        pop(b);
        if (c == nil)
        {   b = cons(qcar(stack[0]), b);
        }
        pop(a);
        a = qcdr(a);
    }
    return onevalue(b);
}

// union-symlist expects both arguments to be lists of symbols, and on that
// basis can run in linear time.

class tidy_union
{   LispObject *save;
public:
    tidy_union()
    {   save = stack;
    }
    ~tidy_union()
    {   stack = save;
        LispObject a = stack[0];
        while (consp(a))
        {   qheader(qcar(a)) &= ~(Header)SYM_TAGGED;
            a = qcdr(a);
        }
    }
};

LispObject Lunion_symlist(LispObject env, LispObject a, LispObject b)
{   LispObject r = nil, w;
// First tag all the symbols in the list b. Any items that are not
// symbols just ignored.
    for (w = b; consp(w); w = qcdr(w))
    {   LispObject x = qcar(w);
        if (is_symbol(x)) qheader(x) |= SYM_TAGGED;
    }
// Now for each item in a push it onto a result list (r) if it a
// symbol that is NOT tagged, i.e. if it was not present in b.
    push(b);
    {   tidy_union RAII;
        while (consp(a))
        {   LispObject x = qcar(a);
            if (is_symbol(x) && (qheader(x) & SYM_TAGGED) == 0)
            {   push(a);
                r = cons(x, r);
                pop(a);
            }
            a = qcdr(a);
        }
    }
// What I now have is a reversed list of new items in r, and the existing
// list b. So reverse r onto the front of b.
    pop(b);
    a = b;
    while (consp(r))
    {   b = r;
        r = qcdr(r);
        qcdr(b) = a;
        a = b;
    }
    return onevalue(a);
}


LispObject Lenable_errorset(LispObject env, LispObject a, LispObject b)
{   LispObject r = cons(fixnum_of_int(errorset_min),
                        fixnum_of_int(errorset_max));
    if (a == nil || a == fixnum_of_int(0))            errorset_min = 0;
    else if (a == fixnum_of_int(1))                   errorset_min = 1;
    else if (a == fixnum_of_int(2))                   errorset_min = 2;
    else if (a == fixnum_of_int(3) || a == lisp_true) errorset_min = 3;
    if (b == nil || b == fixnum_of_int(0))            errorset_max = 0;
    else if (b == fixnum_of_int(1))                   errorset_max = 1;
    else if (b == fixnum_of_int(2))                   errorset_max = 2;
    else if (b == fixnum_of_int(3) || b == lisp_true) errorset_max = 3;
// I increase the max to be at least as high as the indicated min
    if (errorset_min > errorset_max) errorset_max = errorset_min;
// I also arrange that the current state is within the specified range
    switch (errorset_min)
    {   case 0: break;
        case 1: miscflags |= HEADLINE_FLAG;
            break;
        case 2: miscflags |= HEADLINE_FLAG | FNAME_FLAG;
            break;
        default: // case 3:
            miscflags |= BACKTRACE_MSG_BITS;
            break;
    }
    switch (errorset_max)
    {   case 0: miscflags &= ~BACKTRACE_MSG_BITS;
            break;
        case 1: miscflags &= ~(FNAME_FLAG | ARGS_FLAG);
            break;
        case 2: miscflags &= ~ARGS_FLAG;
            break;
        default: // case 3:
            break;
    }
    return r;
}

LispObject Lenable_backtrace(LispObject env, LispObject a)
{
//
//    (enable-backtrace nil)    errors silent unless ALWAYS_NOISY set
//    (enable-backtrace 0)      ditto
//    (enable-backtrace 1)      show 1-line messaqe on error
//    (enable-backtrace 2)      show function names but not args in B/T
//    (enable-backtrace 3)      show functions and args
//    (enable-backtrace t)      ditto
//    otherwise                 just return previous setting
//
    int32_t n = miscflags;
    miscflags &= ~BACKTRACE_MSG_BITS;
    if (a == nil || a == fixnum_of_int(0)) /* nothing */;
    else if (a == fixnum_of_int(1))
        miscflags |=  HEADLINE_FLAG;
    else if (a == fixnum_of_int(2))
        miscflags |=  HEADLINE_FLAG | FNAME_FLAG;
    else if (a == lisp_true || a == fixnum_of_int(3))
        miscflags |= BACKTRACE_MSG_BITS;
    else miscflags = n; // Otherwise have no effect
    return onevalue(fixnum_of_int(miscflags & ARGS_FLAG ? 3 :
                                  miscflags & FNAME_FLAG ? 2 :
                                  miscflags & HEADLINE_FLAG ? 1 :
                                  0));
}

LispObject Lunwind(LispObject env)
{   exit_reason = (miscflags & ARGS_FLAG) ? UNWIND_ERROR :
                  (miscflags & FNAME_FLAG) ? UNWIND_FNAME :
                  UNWIND_UNWIND;
    exit_count = 0;
    exit_tag = nil;
    throw LispError();
}

//
// If the variable *break-function* has as its value a symbol, and that
// symbol names a function, then the function concerned will be called
// with one argument after the headline for the diagnostic. When it returns
// the system will unwind in the usual manner.
//

NORETURN void error_N(LispObject args)
{   LispObject w;
    errors_now++;
    if (errors_limit >= 0 && errors_now > errors_limit)
        resource_exceeded();
#ifdef COMMON
    LispObject a1 = qcar(args);
    args = qcdr(args);
// I will use FORMAT to handle error messages provided the first arg
// to error had been a string and also provided (for bootstrapping) that
// the function FORMAT seems to be defined.
        if (qfn1(format_symbol) == undefined_1 ||
            !stringp(a1)) loop_print_error(cons(a1, args));
        else Lapply_3(nil, format_symbol, qvalue(error_output), a1, args);
        err_printf("\n");
        pop(r);
    }
    qvalue(emsg_star) = cons(a1, r);     // "Error message" in CL world
    exit_value = fixnum_of_int(0);       // "Error number"  in CL world
#else
    if (miscflags & HEADLINE_FLAG)
    {   push2(args, qcdr(args));
        err_printf("\n+++ error: ");
        loop_print_error(qcar(stack[-1]));
        while (is_cons(stack[0]))
        {   err_printf(" ");
            loop_print_error(qcar(stack[0]));
            stack[0] = qcdr(stack[0]);
        }
        err_printf("\n");
        popv(1);
        pop(args);
    }
// So if you go (error n A B C) the output should be
//     +++ error n A B C
// and emsg!* gets set to A, while an errorset that catches this will get n.
    LispObject msg = nil;
    if (is_cons(qcdr(args))) msg = qcar(qcdr(args));
    qvalue(emsg_star) = msg;         // "Error message" in SL world
    exit_value = qcar(args);         // "Error number"  in SL world
#endif
    if ((w = qvalue(break_function)) != nil &&
        symbolp(w) &&
        qfn1(w) != undefined_1)
    {   (*qfn1(w))(qenv(w), qvalue(emsg_star));
    }
    exit_reason = (miscflags & ARGS_FLAG) ? UNWIND_ERROR :
                  (miscflags & FNAME_FLAG) ? UNWIND_FNAME :
                  UNWIND_UNWIND;
    exit_count = 0;
    exit_tag = nil;
    throw LispError();
}

NORETURN void Lerror_1(LispObject env, LispObject a1)
{   error_N(ncons(a1));
}

NORETURN void Lerror_2(LispObject env, LispObject a1, LispObject a2)
{   error_N(list2(a1, a2));
}

NORETURN void Lerror_3(LispObject env, LispObject a1, LispObject a2, LispObject a3)
{   error_N(list3(a1, a2, a3));
}

NORETURN void Lerror_4up(LispObject env, LispObject a1, LispObject a2,
        LispObject a3, LispObject a4up)
{   error_N(list3star(a1, a2, a3, a4up));
}

NORETURN void Lerror_0(LispObject env)
{
//
// Silently provoked error - unwind to surrounding errorset level. Note that
// this will NEVER enter a user-provided break loop...
// Also note that (enable-errorset) can set a lower limit to noise levels
// that can result in the error here NOT being silent!
//
    errors_now++;
    if (errors_limit >= 0 && errors_now > errors_limit)
        resource_exceeded();
    switch (errorset_min)
    {   case 0: miscflags &= ~BACKTRACE_MSG_BITS;
            break;
        case 1: miscflags &= ~(FNAME_FLAG | ARGS_FLAG);
            break;
        case 2: miscflags &= ~ARGS_FLAG;
        default:break;
    }
    exit_reason = (miscflags & ARGS_FLAG) ? UNWIND_ERROR :
                  (miscflags & FNAME_FLAG) ? UNWIND_FNAME :
                  UNWIND_UNWIND;
    exit_value = exit_tag = nil;
    exit_count = 0;
    throw LispError();
}

LispObject Lmake_special(LispObject, LispObject a)
{   if (!symbolp(a)) aerror1("make-special", a);
    if ((qheader(a) & SYM_GLOBAL_VAR) != 0)
        aerror1(
            "Variable is global or keyword so can not become fluid", a);
    qheader(a) |= SYM_SPECIAL_VAR;
    return onevalue(a);
}

LispObject Lmake_global(LispObject, LispObject a)
{   if (!symbolp(a)) aerror("make-global");
    if ((qheader(a) & SYM_SPECIAL_VAR) != 0)
        aerror1(
            "Variable is fluid or keyword so can not become global", a);
    qheader(a) |= SYM_GLOBAL_VAR;
    return onevalue(a);
}

LispObject Lmake_keyword(LispObject, LispObject a)
{   if (!symbolp(a)) aerror("make-keyword");
    if ((qheader(a) & (SYM_GLOBAL_VAR | SYM_SPECIAL_VAR)) != 0)
        aerror1(
            "Variable is fluid or global so can not become keyword", a);
    qheader(a) |= (SYM_SPECIAL_VAR | SYM_GLOBAL_VAR);
    qvalue(a) = a;   // value is itself.
    return onevalue(a);
}

// All the "unmake" functions leave the symbol as a normal one that is
// neither fluid, global nor keyword.

LispObject Lunmake_special(LispObject env, LispObject a)
{   if (!symbolp(a)) return onevalue(nil);
    qheader(a) &= ~(SYM_SPECIAL_VAR | SYM_GLOBAL_VAR);
    return onevalue(a);
}

LispObject Lunmake_global(LispObject env, LispObject a)
{   if (!symbolp(a)) return onevalue(nil);
    qheader(a) &= ~(SYM_SPECIAL_VAR | SYM_GLOBAL_VAR);
    return onevalue(a);
}

LispObject Lunmake_keyword(LispObject env, LispObject a)
{   if (!symbolp(a)) return onevalue(nil);
    qheader(a) &= ~(SYM_SPECIAL_VAR | SYM_GLOBAL_VAR);
    return onevalue(a);
}

LispObject Lsymbol_specialp(LispObject env, LispObject a)
{   if (!symbolp(a)) return onevalue(nil);
    else if ((qheader(a) & (SYM_SPECIAL_VAR | SYM_GLOBAL_VAR)) ==
                           SYM_SPECIAL_VAR) return onevalue(lisp_true);
    else return onevalue(nil);
}

LispObject Lsymbol_globalp(LispObject env, LispObject a)
{   if (!symbolp(a)) return onevalue(nil);
    else if ((qheader(a) & (SYM_SPECIAL_VAR | SYM_GLOBAL_VAR)) ==
                           SYM_GLOBAL_VAR) return onevalue(lisp_true);
    else return onevalue(nil);
}

LispObject Lsymbol_keywordp(LispObject env, LispObject a)
{   if (!symbolp(a)) return onevalue(nil);
    else if ((qheader(a) & (SYM_SPECIAL_VAR | SYM_GLOBAL_VAR)) ==
                           (SYM_SPECIAL_VAR | SYM_GLOBAL_VAR))
        return onevalue(lisp_true);
    else return onevalue(nil);
}

LispObject Lboundp(LispObject env, LispObject a)
{   if (!symbolp(a)) return onevalue(nil);
//
// In COMMON Lisp it seems that this is intended to just check if the
// value cell in a shallow-bound implementation contains some marker value
// that stands for "junk".  In Standard Lisp mode I deem that variables
// that have not been declared fluid are unbound.  Seems to me like a
// classical mix-up between the concept of binding and of having some
// particular value...  Oh well.
//
// (September 2010) I just changed that so that a name that is not fluid
// but that has been given a value (using SET or SETQ I expect) is counted
// as "bound". This probably matches what PSL does and this function is
// also probably used by few enough people that this will not lead to
// too many bugs even though it is an incompatible change in behavior.
//
#if 0
    else if ((qheader(a) & (SYM_SPECIAL_VAR|SYM_GLOBAL_VAR)) == 0)
        return onevalue(nil);
#endif
    else if (qvalue(a) == unset_var) return onevalue(nil); // no value yet
    else return onevalue(lisp_true);
}

LispObject Lsymbol_value(LispObject, LispObject a)
{   if (!symbolp(a)) return onevalue(a);
    else return onevalue(qvalue(a));
}

LispObject Lset(LispObject env, LispObject a, LispObject b)
{   if (!symbolp(a) || a == nil || a == lisp_true) aerror("set");
    qvalue(a) = b;
    return onevalue(b);
}

LispObject Lmakeunbound(LispObject env, LispObject a)
{   if (!symbolp(a) || a == nil || a == lisp_true) aerror("makeunbound");
    qvalue(a) = unset_var;
    return onevalue(a);
}

LispObject Lsymbol_function(LispObject env, LispObject a)
{   no_args *f0;
    one_arg *f1;
    two_args *f2;
    three_args *f3;
    fourup_args *f4up;
    if (!symbolp(a)) return onevalue(nil);
    f0 = qfn0(a);
    f1 = qfn1(a);
    f2 = qfn2(a);
    f3 = qfn3(a);
    f4up = qfn4up(a);
    if ((qheader(a) & (SYM_SPECIAL_FORM | SYM_MACRO)) != 0 ||
        (f0 == undefined_0 && f1 == undefined_1 && f2 == undefined_2 &&
         f3 == undefined_3 && f4up == undefined_4up)) return onevalue(nil);
    else if (f0 == interpreted_0 ||
             f1 == interpreted_1 ||
             f2 == interpreted_2 ||
             f3 == interpreted_3 ||
             f4up == interpreted_4up)
        return onevalue(cons(lambda, qenv(a)));
    else if (f0 == funarged_0 ||
             f1 == funarged_1 ||
             f2 == funarged_2 ||
             f3 == funarged_3 ||
             f4up == funarged_4up)
        return onevalue(cons(funarg, qenv(a)));
    else
    {   LispObject b = get(a, work_symbol, nil);
//
// If I have already manufactured a code pointer for this function I
// can find it on the property list - in that case I will re-use it.
//
        while (b != nil)
        {   LispObject c = qcar(b);
            if ((qheader(c) & (SYM_C_DEF | SYM_CODEPTR)) ==
                (SYM_CODEPTR | (qheader(a) & SYM_C_DEF)))
                return onevalue(c);
            b = qcdr(b);
        }
        push(a);
//
// To carry a code-pointer I manufacture a sort of gensym, flagging
// it in its header as a "code pointer object" and sticking the required
// definition in with it.  I need to link this to the originating
// definition in some cases to allow for preserve/restart problems wrt
// the initialisation of function addresses that refer to C code.
// I make the carrier using GENSYM1, but need to clear the gensym flag bit
// to show I have a regular name for the object, and that I will not need
// to append a serial number later on. In Common Lisp mode I let the name
// of the gensym be just the name of the function, while in Standard Lisp
// mode I will append a numeric suffix. I do this because in Common Lisp
// mode the thing will print as (say) #:apply which is visibly different
// from the name 'apply of the base function, while in Standard Lisp a name
// like apply775 is needed to make the distinction (easily) visible.
//
        get_pname(a);  // to do with unprinted gensyms.
#ifdef COMMON
        b = Lgensym2(nil, a);
#else
        b = Lgensym0(nil, a, "#code");
#endif
        pop(a);
        qfn0(b) = qfn0(a);
        qfn1(b) = qfn1(a);
        qfn2(b) = qfn2(a);
        qfn3(b) = qfn3(a);
        qfn4up(b) = qfn4up(a);
        qenv(b) = qenv(a);
#ifdef COMMON
// in Common Lisp mode gensyms that are "unprinted" are not special
        qheader(b) ^= (SYM_ANY_GENSYM | SYM_CODEPTR);
#else
        qheader(b) ^= (SYM_UNPRINTED_GENSYM | SYM_ANY_GENSYM | SYM_CODEPTR);
#endif
        if ((qheader(a) & SYM_C_DEF) != 0)
        {   LispObject c, w;
            c = get(a, unset_var, nil);
            if (c == nil) c = a;
            push3(a, b, c);
            qheader(b) |= SYM_C_DEF;
            putprop(b, unset_var, c);
            c = stack[0]; b = stack[-1];
            w = get(c, work_symbol, nil);
            w = cons(b, w);
            pop(c);
            putprop(c, work_symbol, w);
            pop2(b, a);
        }
        return onevalue(b);
    }
}

LispObject Lspecial_form_p(LispObject env, LispObject a)
{   if (!symbolp(a)) return onevalue(nil);
    else if ((qheader(a) & SYM_SPECIAL_FORM) != 0) return onevalue(lisp_true);
    else return onevalue(nil);
}

LispObject Lcodep(LispObject env, LispObject a)
//
// This responds TRUE for the special pseudo-symbols that are used to
// carry compiled code objects.  It returns NIL on the symbols that
// are normally used by the user.
//
{   if (!symbolp(a)) return onevalue(nil);
    if ((qheader(a) & (SYM_CODEPTR | SYM_C_DEF)) == SYM_CODEPTR)
        return onevalue(lisp_true);
    else return onevalue(nil);
}

LispObject get_basic_vector(int tag, int type, size_t size)
{
//
// tag is the value (e.g. TAG_SYMBOL) that will go in the low order
// 3 bits of the pointer result.
// type is the code (e.g. TYPE_SYMBOL) that gets packed, together with
// the size, into a header word.
// size is measured in bytes and must allow space for the header word.
// [Note that this last issue - size including the header - was probably
// a mistake since the header size depends on whether I am using a
// 32-bit or 64-bit representation. However it would be hard to unwind
// that now!]
//
    for (;;)
    {   char *r = (char *)vfringe;
        size_t free = (size_t)((char *)vheaplimit - r);
        size_t alloc_size = (size_t)doubleword_align_up(size);
// Basic vectors must be smaller then the CSL page size.
        if (alloc_size > (CSL_PAGE_SIZE - 32))
            aerror1("request for basic vector too big",
                    fixnum_of_int(alloc_size/CELL-1));
        if (++reclaim_trigger_count == reclaim_trigger_target ||
            alloc_size > free || vec_forced(alloc_size/CELL))
        {   char msg[40];
//
// I go to a whole load of trouble here to tell the user what sort of
// vector request provoked this garbage collection.  I wonder if the user
// really cares - but I do very much when I am chasing after GC bugs!
//
            switch (tag)
            {   case TAG_SYMBOL:
                    sprintf(msg, "symbol header");
                    break;
                case TAG_NUMBERS:
                    switch (type)
                    {   case TYPE_BIGNUM:
                            sprintf(msg, "bignum(%ld)", (long)size);
                            break;
                        default:
                            sprintf(msg, "numbers(%lx,%ld)", (long)type, (long)size);
                            break;
                    }
                    break;
                case TAG_VECTOR:
                    switch (type)
                    {
                        case TYPE_STRING_1:
                        case TYPE_STRING_2:
                        case TYPE_STRING_3:
                        case TYPE_STRING_4:
                            sprintf(msg, "string(%ld)", (long)size);
                            break;
                        case TYPE_BPS_1:
                        case TYPE_BPS_2:
                        case TYPE_BPS_3:
                        case TYPE_BPS_4:
                            sprintf(msg, "BPS(%ld)", (long)size);
                            break;
                        case TYPE_SIMPLE_VEC:
                            sprintf(msg, "simple vector(%ld)", (long)size);
                            break;
                        case TYPE_HASH:
                            sprintf(msg, "hash table(%ld)", (long)size);
                            break;
                        default:
                            sprintf(msg, "vector(%lx,%ld)", (long)type, (long)size);
                            break;
                    }
                    break;
                case TAG_BOXFLOAT:
                    sprintf(msg, "float(%ld)", (long)size);
                    break;
                default:
                    sprintf(msg, "get_basic_vector(%lx,%ld)", (long)tag, (long)size);
                    break;
            }
            reclaim(nil, msg, GC_VEC, alloc_size);
// Note the CONTINUE here so that I go and repeat the test. Consider the
// case where I have a page almost full but then garbage collection recovers
// a lof of space but still leaves the final used page almost full... I
// need the garbage collector to take care with its final argument to be
// certain that the loop here terminates!
            continue;
        }
        vfringe = (LispObject)(r + alloc_size);
        *((Header *)r) = type + (size << (Tw+5)) + TAG_HDR_IMMED;
//
// DANGER: the vector allocated here is left uninitialised at this stage.
// This is OK if the vector will contain binary information, but if it
// will hold any LispObjects it needs safe values put in PDQ.
//
// All vectors are allocated so as to be 8-byte aligned. On a 64-bit system
// a vector that will not end up being a multipe of 8 bytes long naturally
// gets padded out. Here I arrange to zero out any such padder word. This
// should not be very important since nobody should ever try to use that
// word. When the garbage collector copies material around it transcribes
// the whole vector (including the padder), but it should never try to trace
// through it. By tidying this up here can feel that I do not have any
// need to worry about it elsewhere.
        if (!SIXTY_FOUR_BIT && alloc_size != size)
            *(LispObject *)(vfringe-CELL) = 0;
        return (LispObject)(r + tag);
    }
}

LispObject get_basic_vector_init(size_t n, LispObject k)
{   LispObject p;
    push(k);
    p = get_basic_vector(TAG_VECTOR, TYPE_SIMPLE_VEC, n);
    pop(k);
    n = n/CELL - 1;
    for (size_t i=0; i<n; i++)
        basic_elt(p, i) = k;
    return p;
}

// I make big vectors out of chunks each of which are vectors using
// (up to) a megabyte.
// Well there is a delicacy in that if one of that size is created on a
// 32 bit system and dumped, and the image is then reloaded on a 64
// bit system then the vector will consume around 2 Mbytes. I do not
// believe that this can cause trouble.
// I can have two levels of structure, and by the time the index level
// is at maximum size (128K entries on a 64-bit system) size I will have
// a table with 128K*128K = 16G slots in it and occupying 128 Gbytes.
// At present (2017) I view the limits there are such that they will
// not embarass me for some while. My belief is that allocating space in
// chunks like this is going to be more friendly as regards memory
// fragmentation than just using huge contiguous blocks.

//#define LOG2_VECTOR_CHUNK_BYTES 20     // in externs.h ...
//#define VECTOR_CHUNK_BYTES  ((size_t)(1<<LOG2_VECTOR_CHUNK_BYTES))

// I use zero to mark entries here that are not in use.  As far as a
// LispObject is concerned that is a pointer to a CONS cell but at
// address zero, which should not arise. And anyway I am only going
// to put references to vectors here and this array will be cleared by the
// garbage collector rather than being scanned. Every vector put in
// here should have tag TAG_VECTOR and type TYPE_SIMPLE_VECTOR

LispObject free_vectors[LOG2_VECTOR_CHUNK_BYTES+1] = {0};

// This will recover a saved vector if one is available. Its argument is
// the size of the vector including its header word, but as far as powers
// of 2 go I look at the size of the data part only.

static LispObject gvector(int tag, int type, size_t n)
{   size_t n1 = n/CELL - 1;    // size in words of data part.
    if (is_power_of_two(n1))   // special if size is a power of 2.
    {   int i = intlog2(n1);   // identify what power of 2 we have.
        LispObject r;
        if (i <= LOG2_VECTOR_CHUNK_BYTES &&
            (r = free_vectors[i]) != 0)
        {   free_vectors[i] = basic_elt(r, 0);
// reset type field
            vechdr(r) = type + (n << (Tw+5)) + TAG_HDR_IMMED;
            return r - TAG_VECTOR + tag;
        }
    }
// If there is no saved vector then allocate a new one. Note that when
// called from here this will be a smallish vector.
    return get_basic_vector(tag, type, n);
}

LispObject get_vector(int tag, int type, size_t n)
{   LispObject v;
//
// A major ugliness here is that I need to support huge vectors.
// To achieve this I will handle big cases using a vector of vectors, with
// the higher level vector tagged as a INDEXVEC and the lower level vectors
// each modestly sized.
// So:
//   A vector of size up to VECTOR_CHUNK_BYTES will be represented
//     naturally as a single block of memory. That is the size of the DATA
//     not including the header cell.
//   Larger vectors will have an INDEXVEC most of whose contents are
//     vectors of size VECTOR_CHUNK_BYTES but where the final item
//     may be smaller.
//
    if (n-CELL > VECTOR_CHUNK_BYTES)
    {
// If the number size is exactly a multiple of the chunk size I will not
// need a special shorter final vector.
        size_t chunks = (n - CELL + VECTOR_CHUNK_BYTES - 1)/VECTOR_CHUNK_BYTES;
        size_t i;
// The final chunk will be full size if I have a neat multiple of
// VECTOR_CHUNK_BYTES, otherwise smaller.
        size_t last_size = (n - CELL) % VECTOR_CHUNK_BYTES;
        if (last_size == 0) last_size = VECTOR_CHUNK_BYTES;
        v = gvector(TAG_VECTOR, TYPE_INDEXVEC, CELL*(chunks+1));
// Note that this index vector will be around while the various sub
// vectors are allocated, so I need to make it GC safe...
        for (i=0; i<chunks; i++)
            basic_elt(v, i) = nil;
        for (i=0; i<chunks; i++)
        {   LispObject v1;
            int k = i==chunks-1 ? last_size : VECTOR_CHUNK_BYTES;
            push(v);
            v1 = gvector(tag, type, k+CELL);
            pop(v);
// The vector here will be active as later chunks are allocated, so it needs
// to be GC safe.
            if (!vector_holds_binary(v1))
            {   size_t k1 = k/CELL;
                for (size_t j=0; j<k1; j++)
                    basic_elt(v1, j) = nil;
            }
            basic_elt(v, i) = v1;
        }
    }
    else v = gvector(tag, type, n);
    return v;
}

LispObject get_vector_init(size_t n, LispObject val)
{   LispObject p;
    push(val);
    p = get_vector(TAG_VECTOR, TYPE_SIMPLE_VEC, n);
    pop(val);
    n = n/CELL - 1;
    while (n != 0)
    {   n--;
        elt(p, n) = val;
    }
    return p;
}

NORETURN void Lstop1(LispObject env, LispObject code)
{   if (!is_fixnum(code)) aerror("stop");
    if (Lposn(nil) != fixnum_of_int(0)) Lterpri(nil);
    exit_value = code;
    exit_tag = fixnum_of_int(0);    // Flag to say "stop"
    exit_reason = UNWIND_RESTART;
    exit_count = 1;
    throw LispRestart();
}

NORETURN void Lstop0(LispObject env)
{   Lstop1(env, fixnum_of_int(0));
}

clock_t base_time;
double *clock_stack, consolidated_time[10], gc_time;

void push_clock(void)
{   clock_t t0 = read_clock();
//
// Provided that I do this often enough I will not suffer clock
// wrap-around or overflow.
//
    double delta = (double)(t0 - base_time)/(double)CLOCKS_PER_SEC;
    base_time = t0;
    *clock_stack += delta;
    *++clock_stack = 0.0;
}

double pop_clock(void)
{   clock_t t0 = read_clock();
    double delta = (double)(t0 - base_time)/(double)CLOCKS_PER_SEC;
    base_time = t0;
    return delta + *clock_stack--;
}

LispObject Ltime(LispObject env)
{   LispObject r;
    if (clock_stack == &consolidated_time[0])
    {   clock_t t0 = read_clock();
        double delta = (double)(t0 - base_time)/(double)CLOCKS_PER_SEC;
        base_time = t0;
        consolidated_time[0] += delta;
    }
    r = make_lisp_unsigned64((uint64_t)(1000.0 * consolidated_time[0]));
    return onevalue(r);
}

LispObject Lgctime(LispObject env)
{   LispObject r = make_lisp_unsigned64((uint64_t)(1000.0 * gc_time));
    return onevalue(r);
}

LispObject Ldecoded_time(LispObject env)
{   time_t t0 = time(NULL);
//
//        tm_sec      -- seconds 0..59
//        tm_min      -- minutes 0..59
//        tm_hour     -- hour of day 0..23
//        tm_mday     -- day of month 1..31
//        tm_mon      -- month 0..11
//        tm_year     -- years since 1900
//        tm_wday     -- day of week, 0..6 (Sunday..Saturday)
//        tm_yday     -- day of year, 0..365
//        tm_isdst    -- >0 if daylight savings time
//                    -- ==0 if not DST
//                    -- <0 if don't know
//
    struct tm *tbuf = localtime(&t0);
    LispObject r, *p = &mv_2;
    int w;
    r = fixnum_of_int(tbuf->tm_sec);
    *p++ = fixnum_of_int(tbuf->tm_min);
    *p++ = fixnum_of_int(tbuf->tm_hour);
    *p++ = fixnum_of_int(tbuf->tm_mday);
    *p++ = fixnum_of_int(tbuf->tm_mon+1);
    *p++ = fixnum_of_int(tbuf->tm_year+1900);
    w = tbuf->tm_wday;
    *p++ = fixnum_of_int(w == 0 ? 6 : w-1);
    *p++ = tbuf->tm_isdst > 0 ? lisp_true : nil;
    *p++ = fixnum_of_int(0);  // Time zone info not available?
//
// Until and unless I implement multiple values in Standard Lisp mode this
// function will count as a bit silly in that most of its results will
// be just lost!
//
    return nvalues(r, 9);
}

//
// (date)             "14-May-13"
// (date!-and!-time)  "Tue May 14 09:52:45 2013"
//
// Then (date t) and (date!-and!-time t) flip formats (well actually any
// argument will suffice).
//

LispObject Ldate(LispObject env)
{   LispObject w;
    time_t t = time(NULL);
    char today[32];
    char today1[32];
    strcpy(today, ctime(&t));  // e.g. "Sun Sep 16 01:03:52 1973\n"
    //       012345678901234567890123
    today[24] = 0;             // loses final '\n'
    today1[0] = today[8]==' ' ? '0' : today[8];
    today1[1] = today[9];
    today1[2] = '-';
    today1[3] = today[4];
    today1[4] = today[5];
    today1[5] = today[6];
    today1[6] = '-';
    today1[7] = today[22];
    today1[8] = today[23];
    today1[9] = 0;             // Now as in 03-Apr-09
    w = make_string(today1);
    return onevalue(w);
}

LispObject Ldate1(LispObject env, LispObject a1)
{   LispObject w;
    time_t t = time(NULL);
    char today[32];
    strcpy(today, ctime(&t));  // e.g. "Sun Sep 16 01:03:52 1973\n"
    today[24] = 0;             // loses final '\n'
    w = make_string(today);
    return onevalue(w);
}

LispObject Ldate_and_time(LispObject env)
{   LispObject w;
    time_t t = time(NULL);
    char today[32];
    strcpy(today, ctime(&t));  // e.g. "Sun Sep 16 01:03:52 1973\n"
    today[24] = 0;             // loses final '\n'
    w = make_string(today);
    return onevalue(w);
}

LispObject Ldate_and_time1(LispObject env, LispObject a1)
{   LispObject w;
    time_t t = time(NULL);
    char today[32], today1[32];
    strcpy(today, ctime(&t));  // e.g. "Sun Sep 16 01:03:52 1973\n"
    //       012345678901234567890123
    today[24] = 0;             // loses final '\n'
    today1[0] = today[8]==' ' ? '0' : today[8];
    today1[1] = today[9];
    today1[2] = '-';
    today1[3] = today[4];
    today1[4] = today[5];
    today1[5] = today[6];
    today1[6] = '-';
    today1[7] = today[22];
    today1[8] = today[23];
    today1[9] = 0;             // Now as in 03-Apr-09
    w = make_string(today1);
    return onevalue(w);
}

LispObject Ldatestamp(LispObject env)
// Returns date-stamp integer, which on many systems will be the
// number of seconds between 1970.0.0 and now, but which could be
// pretty-well almost any other thing, as per the C "time_t" type.
// I do not allow for time-zones etc here either!
{   time_t t = time(NULL);
    return onevalue(make_lisp_integer64((int64_t)t));
}

LispObject Ltimeofday(LispObject env)
//
// This is like datestamp, in that it returns information about the
// current real time. However it returns a pair of two values, the
// first being in seconds and the second (when available) being in
// microseconds.
//
{   LispObject w;
    time_t t = time(NULL);
//
// Note that if this is a 32-bit value it will wrap in 2038. Probably some
// other API should be used here!
//
    uint64_t n = (uint64_t)t;
    uint32_t un = 0;  // will be for microseconds, so value will be 0-999999
#ifdef HAVE_SYS_TIME_H
#ifdef HAVE_GETTIMEOFDAY
// If more precise information is available then use it
    struct timeval tv;
    gettimeofday(&tv, NULL);
    n = (uint64_t)tv.tv_sec;
    un = (uint32_t)tv.tv_usec;
#endif
#endif
    w = make_lisp_unsigned64(n);
    return onevalue(cons(w, fixnum_of_int(un)));
}

// This will be the header for a string of length exactly 24. It is
// used because a valid date will be a string of just that length.

#define STR24HDR (TAG_HDR_IMMED+TYPE_STRING_4+((24+CELL)<<(Tw+5)))

static int getint(char *p, int len)
{   int r = 0;
    while (len-- != 0)
    {   int c = *p++;
        if (c == ' ') c = '0';
        r = 10*r + (c - '0');
    }
    return r;
}

static int getmon(char *s)
{   int c1 = s[0], c2 = s[1], c3 = s[2], r = -1, w;
    const char *m = "janfebmaraprmayjunjulaugsepoctnovdec";
    if (isupper(c1)) c1 = tolower(c1);
    if (isupper(c2)) c2 = tolower(c2);
    if (isupper(c3)) c3 = tolower(c3);
    for (w=0; w<12; w++)
    {   if (c1==m[0] && c2==m[1] && c3==m[2])
        {   r = w;
            break;
        }
        m += 3;
    }
    return r;
}

static LispObject Ldatelessp(LispObject env, LispObject a, LispObject b)
//
// This is maybe a bit of an abomination!  The functions (date) and
// (filedate "filename") [and also (modulep 'modulename)] return times
// as strings of 24 characters.  This function decodes these and
// sorts out which time is earlier.  The alternative would be to provide
// a collection of functions that returned coded times (as in C "time_t"),
// but I have greater doubts about making those utterly portable, while the
// textual arrangement used here seems fairly robust (until you start
// worrying about carrying a portable machine across time zones or switching
// to daylight savings time).
//
{   char *aa, *bb;
    bool res;
    int wa, wb;
    if (!is_vector(a) || !is_vector(b) ||
        vechdr(a) != STR24HDR ||
        vechdr(b) != STR24HDR) aerror2("datelessp", a, b);
    aa = (char *)a + (CELL - TAG_VECTOR);
    bb = (char *)b + (CELL - TAG_VECTOR);
//
// Layout is eg. "Wed May 12 15:50:23 1993"
//                012345678901234567890123
// Note that the year is 4 digits so that the year 2000 should hold
// no special terrors JUST here.
//
    if ((wa = getint(aa+20, 4)) != (wb = getint(bb+20, 4))) res = wa < wb;
    else if ((wa = getmon(aa+4)) != (wb = getmon(bb+4))) res = wa < wb;
    else if ((wa = getint(aa+8, 2)) != (wb = getint(bb+8, 2))) res = wa < wb;
    else if ((wa = getint(aa+11, 2)) != (wb = getint(bb+11, 2))) res = wa < wb;
    else if ((wa = getint(aa+14, 2)) != (wb = getint(bb+14, 2))) res = wa < wb;
    else if ((wa = getint(aa+17, 2)) != (wb = getint(bb+17, 2))) res = wa < wb;
    else res = false;
    return onevalue(Lispify_predicate(res));
}

LispObject Lrepresentation1(LispObject env, LispObject a)
//
// Intended for debugging, and use with indirect (q.v.)
//
{   a = make_lisp_integer64((intptr_t)a);
    return onevalue(a);
}

LispObject Lrepresentation2(LispObject env, LispObject a, LispObject b)
//
// Intended for debugging, and use with indirect (q.v.).  arg2, if
// present and non-nil makes this more verbose. If arg2 is numeric it
// prints slightly less than if it is other non-nil things!
//
{   if (SIXTY_FOUR_BIT)
    {   if (b != nil)
        {   if (!is_fixnum(b))
                trace_printf("R = %.16" PRIx64 " ", (uint64_t)a);
            if (is_numbers(a) && is_bignum(a))
            {   size_t len = (length_of_header(numhdr(a))-CELL)/4;
                for (size_t i=len; i>0; i--)
                    trace_printf("%.8x ", bignum_digits(a)[i-1]);
            }
            else if (is_fixnum(a))
                trace_printf("#%cFIX:%" PRIx64, ((intptr_t)a>=0 ? 'p' : 'n'),
                             int_of_fixnum(a));
            trace_printf("\n");
        }
        a = make_lisp_integer64((intptr_t)a);
        return onevalue(a);
    }
    else
    {   if (b != nil)
        {   if (!is_fixnum(b))
                trace_printf("R = %.8lx ", (long)(uint32_t)a);
            if (is_numbers(a) && is_bignum(a))
            {   size_t len = (length_of_header(numhdr(a))-CELL)/4;
                for (size_t i=len; i>0; i--)
                    trace_printf("%.8x ", bignum_digits(a)[i-1]);
            }
            trace_printf("\n");
        }
        a = make_lisp_integer32((int32_t)a);
        return onevalue(a);
    }
}

LispObject Lindirect(LispObject, LispObject a)
{   return onevalue(*(LispObject *)(intptr_t)sixty_four_bits(a));
}

//
// A basic foreign function interface...
//


//
//   (setq libobject (open!-foreign!-library "libraryname"))
// On windows ".dll" is appended, on other systems ".so", unless there is
// already a suffix. Returns nil if the library can not be accessed.
//
// I will not (for now) provide a call to close the library - it should be
// closed when the system exits.
//

LispObject Lopen_foreign_library(LispObject env, LispObject name)
{
#ifdef WIN32
    HANDLE a;
#else
    void *a;
#endif
    LispObject r;
    char libname[LONGEST_LEGAL_FILENAME];
    size_t len = 0;
    const char *w;
    char *w2, *w1 = NULL;
    memset(libname, 0, sizeof(libname));
    w = get_string_data(name, "find-foreign-library", len);
    if (len > sizeof(libname)-5) len = sizeof(libname)-5;
    sprintf(libname, "%.*s", (int)len, w);
    for (w2=libname; *w2!=0; w2++)
        if (w1==NULL && *w2 == '.') w1 = w2;
        else if (*w2 == '/' || *w2 == '\\') w1 = NULL;
//
// Now of w1 is not NULL it identifies a suffix ".xxx" where there is no
// "/" or "\\" in the string xxx. A suffix such as ".so.1.3.2" is reported as
// a whole despite the embedded dots.
// On Windows if no suffix is provided a ".dll" will be appended, while
// on other systems ".so" is used.
//
#ifdef WIN32
    if (w1 == NULL) strcat(libname, ".dll");
    for (w1=libname; *w1!=0; w1++)
        if (*w1 == '/') *w1 = '\\';
//
// For now I will leave the trace print of the library name here, since
// it should only appear once per run so ought not to cause over-much grief.
// eventually I will remove it!
//
#ifdef DEBUG
    printf("open-library Windows %s\n", libname);
#endif
    a = LoadLibrary(libname);
    if (a == 0)
    {
#ifdef DEBUG
        DWORD err = GetLastError();
        char errbuf[80];
//
// The printf calls here to report errors will not be useful in some
// windowed contexts, so I will need to rework them in due course.
//
        printf("Error code %ld = %lx\n", (long)err, (long)err);
        err = FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM |
                            FORMAT_MESSAGE_IGNORE_INSERTS,
                            NULL, err, 0, errbuf, 80, NULL);
        if (err != 0) printf("%s", errbuf);
#endif
        return onevalue(nil);
    }
#else
    if (w1 == NULL) strcat(libname, ".so");
#ifdef DEBUG
//
// For now I will leave the trace print of the library name here, since
// it should only appear once per run so ought not to cause over-much grief.
// eventually I will remove it!
//
    printf("open-library Linux/Mac/BSD/Unix etc %s\n", libname);
#endif
#ifdef EMBEDDED
    a = NULL;
#else
    a = dlopen(libname, RTLD_NOW | RTLD_GLOBAL);
#endif
    if (a == NULL)
    {
#ifdef DEBUG
        printf("Err = <%s>\n", dlerror()); fflush(stdout);
#endif
        return onevalue(nil);
    }
#endif
    r = encapsulate_pointer((void *)a);
    return onevalue(r);
}

//
// (setq entrypoint (find!-foreign!-function "fname" libobject))
// Using a library opened by open!-foreign!-library look up an entrypoint
// for a function called "fname". If one can not be found return nil.
//

LispObject Lfind_foreign_function(LispObject env, LispObject name,
                                  LispObject lib)
{   LispObject r;
    void *b;
    const char *w;
    char sname[100];
    size_t len = 0;
#ifdef WIN32
    HMODULE a;
#else
    void *a;
#endif
    if (Lencapsulatedp(nil, lib) == nil)
        aerror("find-foreign-function");
#ifdef WIN32
    a = (HMODULE)extract_pointer(lib);
#else
    a = extract_pointer(lib);
#endif
    w = get_string_data(name, "find-foreign-function", len);
    if (len > sizeof(sname)-2) len = sizeof(sname)-2;
    sprintf(sname, "%.*s", (int)len, w);
//=== #ifdef __CYGWIN__
//===     printf("name to look up = %s\r\n", sname);
//=== #else
//===     printf("name to look up = %s\n", sname);
//=== #endif
#ifdef EMBEDDED
    b = NULL;
#else
#ifdef WIN32
    b = (void *)GetProcAddress(a, sname);
#else
    b = dlsym(a, sname);
#endif
#endif
    if (b == NULL) return onevalue(nil);
    r = encapsulate_pointer(b);
// Observe that the result is an encapsulated pointer to the entrypoint of the
// function that you are interested in.
    return onevalue(r);
}

//
// (call!-foreign!-function fnptr)
// call the function as found by find!-foreign!-function not passing it
// any arguments and not expecting any result.
//

typedef void void_function();

LispObject Lcallf_1(LispObject env, LispObject entry)
{   void *f;
    if (Lencapsulatedp(nil, entry) == nil)
        aerror("call-foreign-function");
    f = extract_pointer(entry);
    ffi_cif cif;
    if (ffi_prep_cif(&cif, FFI_DEFAULT_ABI, 0, &ffi_type_void, NULL) != FFI_OK)
        aerror("callf for a function with no arguments");
// The strange looking double cast here is because some versions of C++ took
// the view that conversion between function pointers and object pointers
// should be labelled as illegal. On a Harvard architecture machine you can
// see that as making a lof of sense. So I convert from the object pointer
// "void *" to the function pointer "void_function *" using intptr_t as
// an intermediary. This is obviously undefined behaviour! But "The Spirit
// of C" would give a clear indication of expectations!
    ffi_call(&cif, (void_function *)(uintptr_t)f, NULL, NULL);
    return onevalue(nil);
}

//
// For calling foreign functions I need to know something of their type
// signature. The view I will take here is NOT guaranteed portable but
// is liable to work on many practical systems. I classify arguments that
// are actually passed as Int32, Int64 or Double. These are expected to
// be sufficient for:
// Int32     int when sizeof(int)==4
//           char *, void * when sizeof(void *)==4, and hence "abcdef"
//           'x'
// Int64     int, long or long long when sizeof(.)==8
//           size_t if it has size 8
//           char *, void *, strings etc when size 8
// Double    double
//

#define MAX_ARGCOUNT 20
#define MAX_STRINGLEN 256

// I will collect arguments for foreign functions in these arrays.

// targs and vargs are the arrays passed to libffi. i32args etc are
// where the data is actually put.

ffi_type *targs[MAX_ARGCOUNT];
void     *vargs[MAX_ARGCOUNT];

void *fresult;

int32_t i32args[MAX_ARGCOUNT];
int64_t i64args[MAX_ARGCOUNT];
int64_t dblargs[MAX_ARGCOUNT];
char    strargs[MAX_ARGCOUNT][MAX_STRINGLEN];

long longres;
int32_t i32res;
int64_t i64res;
double  dblres;
void   *strres;

//
// Given a symbol (or in fact a string) this checks if its name is the
// same as the value given as arg2.
//
int name_matches(LispObject a, const char *s)
{   size_t len = 0;
    const char *w = get_string_data(a, "call-foreign", len);
    if (len == strlen(s) &&
        strncmp(w, s, len) == 0) return 1;
    else return 0;
}

//
// The general scheme for call-foreign-function is as follows, where the
// key issue is that of the types of data passed and returned...
//
//    (call-foreign-function f)    call f with no args, ignoring any result
//    (call-foreign-function f a1)
//    (call-foreign-function f a1 a2)
//    (call-foreign-function f a1 a2 ...)
//    etc
// Each argument can be one of the following:
//    A symbol, where int32, int64, int, long, longlong, intptr and size
//    double and string are the useful values. This specifies the way in
//    which the next argument will be passed. If there is no
//    further argument then the name can also possibly be void,
//    and it indicates a return type.
//
//    An integer. This is passed as the next argument to the function
//    as a 32-bit integer unless a type was specified by the previous symbol.
//
//    A double-precision float. Passed to the function as the next argument.
//
//    A string. A C string is passed to the function. There will be a
//    limit on the length of string that can be passed this way.
//    You might very reasonablly have expected that the string could be
//    passed to the foreign function without being copied. That is not
//    (always) possible because the Lisp representation of strings holds them
//    as a length and then bytes of data rather than as a null-terminated
//    sequence of bytes.
//
//    A pair (sym . val) where sym can be one of
//        int int32 long int64 longlong intptr size string double
//    and val is something that can be mapped onto the matching type. The
//    purpose of this is so that whether an integer passed this way will be
//    32 or 64-bit can depend on the nature of the host system.
//

static void dumparg(int i, LispObject type, LispObject value)
{   size_t len = 0;
    const char *w = get_string_data(type, "call-foreign-function", len);
    if ((len==5 && strncmp(w, "int64", 5)==0) ||
        (sizeof(long)==8 && len==4 && strncmp(w, "long", 4)==0) ||
        (sizeof(size_t)==8 && len==4 && strncmp(w, "size", 4)==0) ||
        (sizeof(intptr_t)==8 && len==6 && strncmp(w, "intptr", 6)==0) ||
        (len==8 && strncmp(w, "longlong", 8)==0))
    {   vargs[i] = &i64args[i];
        targs[i] = &ffi_type_sint64;
        i64args[i] = sixty_four_bits(value);
    }
    else if ((type == nil && (is_fixnum(value) || is_bignum(value))) ||
        (len==5 && strncmp(w, "int32", 5)==0) ||
        (sizeof(long)==4 && len==4 && strncmp(w, "long", 4)==0) ||
        (sizeof(size_t)==4 && len==4 && strncmp(w, "size", 4)==0) ||
        (sizeof(intptr_t)==4 && len==6 && strncmp(w, "intptr", 6)==0) ||
        (len==3 && strncmp(w, "int", 3)==0))
    {   vargs[i] = &i32args[i];
        targs[i] = &ffi_type_sint32;
        i32args[i] = thirty_two_bits(value);
    }
    else if ((type == nil && is_float(value)) ||
             (len==6 && strncmp(w, "double", 6)==0))
    {   vargs[i] = &dblargs[i];
        targs[i] = &ffi_type_double;
        dblargs[i] = float_of_number(value);
    }
    else if ((type == nil && is_string(value)) ||
             (len==6 && strncmp(w, "string", 6)==0))
    {   const char *w = get_string_data(value, "call-foreign-function", len);
        memcpy(&strargs[i][0], w, len);
        strargs[i][len] = 0;
        vargs[i] = &strargs[i][0];
        targs[i] = &ffi_type_pointer;
    }
    else aerror2("call-foreign-function", type, value);
}

LispObject callf_n(LispObject fun, LispObject args)
{   if (Lencapsulatedp(nil, fun) == nil)
        aerror1("call-foreign-function", fun);
// Note double cast to allow some pre C++-11 compilers to cope.
    void_function *f = (void_function *)(uintptr_t)extract_pointer(fun);
    LispObject currenttype = nil;
    unsigned int nargs = 0;
    while (args != nil)
    {   LispObject a = qcar(args);
        args = qcdr(args);
// Perhaps the next argument is (type . value)...
        if (is_cons(a))
        {   if (nargs >= MAX_ARGCOUNT) aerror("call-foreign-function");
            dumparg(nargs++, qcar(a), qcdr(a));
            currenttype = nil;
        }
// Perhaps the next argument is just a type name. I should never have two
// type names in a row.
        else if (is_symbol(a))
        {   if (currenttype != nil) aerror1("call-foreign-function", a);
            currenttype = a;
        }
// The next argument is a value, which will either use the type specified
// by the previous argument, or a default type based on what its own type is.
        else if (is_fixnum(a) || is_numbers(a) ||
                 is_bfloat(a) || stringp(a))
        {   if (nargs >= MAX_ARGCOUNT) aerror("call-foreign-function");
            dumparg(nargs++, currenttype, a);
            currenttype = nil;
        }
// Other cases are invalid.
        else aerror1("call-foreign-function", a);
    }
// The last item in the argument list may have been a type-name, in which
// case it indicates a return type. If that was not provided then the
// return type is taken as "void". You will see here that there are various
// synonyms, sometimes conditional on the machine being used. So for instance
// intptr_t is identified with either int32_t or int64_t.
    ffi_cif cif;
    if (currenttype == nil || name_matches(currenttype, "void"))
    {   if (ffi_prep_cif(&cif, FFI_DEFAULT_ABI, nargs, &ffi_type_void, targs) != FFI_OK)
            aerror("call-foreign-function");
        ffi_call(&cif, f, NULL, vargs);
        return onevalue(nil); 
    }
    if (name_matches(currenttype, "int32") ||
        name_matches(currenttype, "int") ||
        (sizeof(long)==4 && name_matches(currenttype, "long")) ||
        (sizeof(size_t)==4 && name_matches(currenttype, "size")) ||
        (sizeof(intptr_t)==4 && name_matches(currenttype, "intptr")))
    {   if (ffi_prep_cif(&cif, FFI_DEFAULT_ABI, nargs, &ffi_type_sint32, targs) != FFI_OK)
            aerror("call-foreign-function");
        ffi_call(&cif, f, &i32res, vargs);
        return onevalue(make_lisp_integer32(i32res)); 
    }
    if (name_matches(currenttype, "int64") ||
        name_matches(currenttype, "longlong") ||
        (sizeof(long)==8 && name_matches(currenttype, "long")) ||
        (sizeof(size_t)==8 && name_matches(currenttype, "size")) ||
        (sizeof(intptr_t)==8 && name_matches(currenttype, "intptr")))
    {   if (ffi_prep_cif(&cif, FFI_DEFAULT_ABI, nargs, &ffi_type_sint64, targs) != FFI_OK)
            aerror("call-foreign-function");
        ffi_call(&cif, f, &i64res, vargs);
        return onevalue(make_lisp_integer64(i64res)); 
    }
    if (name_matches(currenttype, "double"))
    {   if (ffi_prep_cif(&cif, FFI_DEFAULT_ABI, nargs, &ffi_type_double, targs) != FFI_OK)
            aerror("call-foreign-function");
        ffi_call(&cif, f, &dblres, vargs);
        return onevalue(make_boxfloat(dblres, TYPE_DOUBLE_FLOAT)); 
    }
    if (name_matches(currenttype, "string"))
    {   if (ffi_prep_cif(&cif, FFI_DEFAULT_ABI, nargs, &ffi_type_pointer, targs) != FFI_OK)
            aerror("call-foreign-function");
        ffi_call(&cif, f, &strres, vargs);
        return onevalue(make_string((const char *)strres)); 
    }
    else aerror1("call-foreign-function", currenttype);
}

LispObject Lcallf_4up(LispObject env, LispObject a1, LispObject a2,
        LispObject a3, LispObject a4up)
{   return callf_n(a1, list2star(a2, a3, a4up));
}

LispObject Lcallf_3(LispObject env, LispObject entry, LispObject a1, LispObject a2)
{   return callf_n(entry, list2(a1, a2));
}

LispObject Lcallf_2(LispObject env, LispObject entry, LispObject a1)
{   return callf_n(entry, ncons(a1));
}

//
// It may be useful to pass callbacks into CSL to a foreign function so that
// they can be stored and used...
//

static LispObject Lget_callback(LispObject env, LispObject a)
{   void *r = NULL;
    if (!is_fixnum(a)) aerror("get_callback needs an integer arg");
    switch (int_of_fixnum(a))
    {   case  0:  r = (void *)execute_lisp_function;
            break;
        case  1:  r = (void *)PROC_set_callbacks;
            break;
        case  2:  r = (void *)PROC_load_package;
            break;
        case  3:  r = (void *)PROC_set_switch;
            break;
        case  4:  r = (void *)PROC_gc_messages;
            break;
        case  5:  r = (void *)PROC_clear_stack;
            break;
        case  6:  r = (void *)PROC_push_symbol;
            break;
        case  7:  r = (void *)PROC_push_string;
            break;
        case  8:  r = (void *)PROC_push_small_integer;
            break;
        case  9:  r = (void *)PROC_push_big_integer;
            break;
        case 10:  r = (void *)PROC_push_floating;
            break;
        case 11:  r = (void *)PROC_make_function_call;
            break;
        case 12:  r = (void *)PROC_save;
            break;
        case 13:  r = (void *)PROC_load;
            break;
        case 14:  r = (void *)PROC_dup;
            break;
        case 15:  r = (void *)PROC_pop;
            break;
        case 16:  r = (void *)PROC_simplify;
            break;
        case 17:  r = (void *)PROC_make_printable;
            break;
        case 18:  r = (void *)PROC_get_value;
            break;
        case 19:  r = (void *)PROC_atom;
            break;
        case 20:  r = (void *)PROC_null;
            break;
        case 21:  r = (void *)PROC_fixnum;
            break;
        case 22:  r = (void *)PROC_floatnum;
            break;
        case 23:  r = (void *)PROC_string;
            break;
        case 24:  r = (void *)PROC_symbol;
            break;
        case 25:  r = (void *)PROC_first;
            break;
        case 26:  r = (void *)PROC_rest;
            break;
        case 27:  r = (void *)PROC_integer_value;
            break;
        case 28:  r = (void *)PROC_floating_value;
            break;
        case 29:  r = (void *)PROC_symbol_name;
            break;
        case 30:  r = (void *)PROC_string_data;
            break;
        case 31:  r = (void *)PROC_lisp_eval;
            break;
        case 32:  r = (void *)PROC_get_raw_value;
            break;
    }
    return onevalue(make_lisp_integer64((LispObject)r));
}

static LispObject Lsigsegv(LispObject env, LispObject arg)
{   trace_printf("\nsigsegv about to be raised\n");
    printf("llsh = %p\n", low_level_signal_handler);
    printf("signal result = %p\n", signal(SIGSEGV, low_level_signal_handler));
    ensure_screen();
    if (arg == nil) raise(SIGSEGV);
    else *(char *)(-1) = 0x55;
    return onevalue(nil);
}

setup_type const funcs1_setup[] =
{   {"acons",                   G0W3, G1W3, G2W3, Lacons, G4W3},
    {"atom",                    G0W1, Latom, G2W1, G3W1, G4W1},
    {"boundp",                  G0W1, Lboundp, G2W1, G3W1, G4W1},

    {"car",                     G0W1, Lcar, G2W1, G3W1, G4W1},
    {"car*",                    G0W1, Lcar_star, G2W1, G3W1, G4W1},
    {"cdr",                     G0W1, Lcdr, G2W1, G3W1, G4W1},
    {"caar",                    G0W1, Lcaar, G2W1, G3W1, G4W1},
    {"cadr",                    G0W1, Lcadr, G2W1, G3W1, G4W1},
    {"cdar",                    G0W1, Lcdar, G2W1, G3W1, G4W1},
    {"cddr",                    G0W1, Lcddr, G2W1, G3W1, G4W1},
    {"caaar",                   G0W1, Lcaaar, G2W1, G3W1, G4W1},
    {"caadr",                   G0W1, Lcaadr, G2W1, G3W1, G4W1},
    {"cadar",                   G0W1, Lcadar, G2W1, G3W1, G4W1},
    {"caddr",                   G0W1, Lcaddr, G2W1, G3W1, G4W1},
    {"cdaar",                   G0W1, Lcdaar, G2W1, G3W1, G4W1},
    {"cdadr",                   G0W1, Lcdadr, G2W1, G3W1, G4W1},
    {"cddar",                   G0W1, Lcddar, G2W1, G3W1, G4W1},
    {"cdddr",                   G0W1, Lcdddr, G2W1, G3W1, G4W1},
    {"caaaar",                  G0W1, Lcaaaar, G2W1, G3W1, G4W1},
    {"caaadr",                  G0W1, Lcaaadr, G2W1, G3W1, G4W1},
    {"caadar",                  G0W1, Lcaadar, G2W1, G3W1, G4W1},
    {"caaddr",                  G0W1, Lcaaddr, G2W1, G3W1, G4W1},
    {"cadaar",                  G0W1, Lcadaar, G2W1, G3W1, G4W1},
    {"cadadr",                  G0W1, Lcadadr, G2W1, G3W1, G4W1},
    {"caddar",                  G0W1, Lcaddar, G2W1, G3W1, G4W1},
    {"cadddr",                  G0W1, Lcadddr, G2W1, G3W1, G4W1},
    {"cdaaar",                  G0W1, Lcdaaar, G2W1, G3W1, G4W1},
    {"cdaadr",                  G0W1, Lcdaadr, G2W1, G3W1, G4W1},
    {"cdadar",                  G0W1, Lcdadar, G2W1, G3W1, G4W1},
    {"cdaddr",                  G0W1, Lcdaddr, G2W1, G3W1, G4W1},
    {"cddaar",                  G0W1, Lcddaar, G2W1, G3W1, G4W1},
    {"cddadr",                  G0W1, Lcddadr, G2W1, G3W1, G4W1},
    {"cdddar",                  G0W1, Lcdddar, G2W1, G3W1, G4W1},
    {"cddddr",                  G0W1, Lcddddr, G2W1, G3W1, G4W1},

    {"qcar",                    G0W1, Lcar, G2W1, G3W1, G4W1},
    {"qcdr",                    G0W1, Lcdr, G2W1, G3W1, G4W1},
    {"qcaar",                   G0W1, Lcaar, G2W1, G3W1, G4W1},
    {"qcadr",                   G0W1, Lcadr, G2W1, G3W1, G4W1},
    {"qcdar",                   G0W1, Lcdar, G2W1, G3W1, G4W1},
    {"qcddr",                   G0W1, Lcddr, G2W1, G3W1, G4W1},

    {"bpsp",                    G0W1, Lbpsp, G2W1, G3W1, G4W1},
    {"codep",                   G0W1, Lcodep, G2W1, G3W1, G4W1},
    {"cons",                    G0W2, G1W2, Lcons, G3W2, G4W2},
    {"constantp",               G0W1, Lconstantp, G2W1, G3W1, G4W1},
    {"count-up",                Lcount_up, G1W0, G2W0, G3W0, G4W0},
    {"date",                    Ldate, Ldate1, G2Wother, G3Wother, G4Wother},
    {"date-and-time",           Ldate_and_time, Ldate_and_time1, G2Wother, G3Wother, G4Wother},
    {"datestamp",               Ldatestamp, G1W0, G2W0, G3W0, G4W0},
    {"timeofday",               Ltimeofday, G1W0, G2W0, G3W0, G4W0},
    {"enable-errorset",         G0W2, G1W2, Lenable_errorset, G3W2, G4W2},
    {"enable-backtrace",        G0W1, Lenable_backtrace, G2W1, G3W1, G4W1},
// The casts here are because error, stop and a few related functions
// have the NORETURN attribute which would otherwise upset the type checker
// in C++.
    {"error",                   (no_args *)Lerror_0, (one_arg *)Lerror_1, (two_args *)Lerror_2, (three_args *)Lerror_3, (fourup_args *)Lerror_4up},
    {"error1",                  (no_args *)Lerror_0, G1W0, G2W0, G3W0, G4W0},
#ifdef NAG
    {"unwind",                  Lunwind, G1W0, G2W0, G3W0, G4W0},
#endif
    {"eq-safe",                 G0W1, Leq_safe, G2W1, G3W1, G4W1},
    {"fixp",                    G0W1, Lfixp, G2W1, G3W1, G4W1},
    {"floatp",                  G0W1, Lfloatp, G2W1, G3W1, G4W1},
    {"fluidp",                  G0W1, Lsymbol_specialp, G2W1, G3W1, G4W1},
    {"gctime",                  Lgctime, G1W0, G2W0, G3W0, G4W0},
    {"globalp",                 G0W1, Lsymbol_globalp, G2W1, G3W1, G4W1},
    {"hash-table-p",            G0W1, Lhash_table_p, G2W1, G3W1, G4W1},
    {"indirect",                G0W1, Lindirect, G2W1, G3W1, G4W1},
    {"integerp",                G0W1, Lintegerp, G2W1, G3W1, G4W1},
    {"intersection",            G0W2, G1W2, Lintersect, G3W2, G4W2},
    {"intersection_symlist",    G0W2, G1W2, Lintersect_symlist, G3W2, G4W2},
    {"keywordp",                G0W1, Lsymbol_keywordp, G2W1, G3W1, G4W1},
    {"list2",                   G0W2, G1W2, Llist_2, G3W2, G4W2},
    {"list2*",                  G0W3, G1W3, G2W3, Llist_2star, G4W3},
    {"list2*rev",               G0W3, G1W3, G2W3, Llist_2starrev, G4W3},
    {"list3",                   G0W3, G1W3, G2W3, Llist_3, G4W3},
    {"list3rev",                G0W3, G1W3, G2W3, Llist_3rev, G4W3},
    {"list3*",                  G0W4up, G1W4up, G2W4up, G3W4up, Llist_3star},
    {"list4",                   G0W4up, G1W4up, G2W4up, G3W4up, Llist_4},
    {"make-global",             G0W1, Lmake_global, G2W1, G3W1, G4W1},
    {"make-keyword",            G0W1, Lmake_keyword, G2W1, G3W1, G4W1},
    {"make-special",            G0W1, Lmake_special, G2W1, G3W1, G4W1},
    {"mkquote",                 G0W1, Lmkquote, G2W1, G3W1, G4W1},
    {"ncons",                   G0W1, Lncons, G2W1, G3W1, G4W1},
    {"numberp",                 G0W1, Lnumberp, G2W1, G3W1, G4W1},
    {"pair",                    G0W2, G1W2, Lpair, G3W2, G4W2},
    {"protect-symbols",         G0W1, Lprotect_symbols, G2W1, G3W1, G4W1},
    {"protected-symbol-warn",   G0W1, Lwarn_about_protected_symbols, G2W1, G3W1, G4W1},
    {"put",                     G0W3, G1W3, G2W3, Lputprop, G4W3},
    {"remprop",                 G0W2, G1W2, Lremprop, G3W2, G4W2},
    {"representation",          G0W1, Lrepresentation1, Lrepresentation2, G3Wother, G4Wother},
    {"rplaca",                  G0W2, G1W2, Lrplaca, G3W2, G4W2},
    {"rplacd",                  G0W2, G1W2, Lrplacd, G3W2, G4W2},
    {"set",                     G0W2, G1W2, Lset, G3W2, G4W2},
    {"makeunbound",             G0W1, Lmakeunbound, G2W1, G3W1, G4W1},
    {"special-form-p",          G0W1, Lspecial_form_p, G2W1, G3W1, G4W1},
    {"stop",                    (no_args *)Lstop0, (one_arg *)Lstop1, G2Wother, G3Wother, G4Wother},
    {"symbol-function",         G0W1, Lsymbol_function, G2W1, G3W1, G4W1},
    {"symbol-value",            G0W1, Lsymbol_value, G2W1, G3W1, G4W1},
    {"time",                    Ltime, G1W0, G2W0, G3W0, G4W0},
    {"datelessp",               G0W2, G1W2, Ldatelessp, G3W2, G4W2},
    {"union",                   G0W2, G1W2, Lunion, G3W2, G4W2},
    {"union-symlist",           G0W2, G1W2, Lunion_symlist, G3W2, G4W2},
    {"unmake-global",           G0W1, Lunmake_global, G2W1, G3W1, G4W1},
    {"unmake-keyword",          G0W1, Lunmake_keyword, G2W1, G3W1, G4W1},
    {"unmake-special",          G0W1, Lunmake_special, G2W1, G3W1, G4W1},
    {"xcons",                   G0W2, G1W2, Lxcons, G3W2, G4W2},
// I provide both IDP and SYMBOLP in both modes...
    {"symbolp",                 G0W1, Lsymbolp, G2W1, G3W1, G4W1},
    {"idp",                     G0W1, Lsymbolp, G2W1, G3W1, G4W1},
// I support the Common Lisp names here in both modes
    {"simple-string-p",         G0W1, Lstringp, G2W1, G3W1, G4W1},
    {"simple-vector-p",         G0W1, Lsimple_vectorp, G2W1, G3W1, G4W1},
    {"get-decoded-time",        Ldecoded_time, G1W0, G2W0, G3W0, G4W0},
    {"short-floatp",            G0W1, Lshort_floatp, G2W1, G3W1, G4W1},
    {"single-floatp",           G0W1, Lsingle_floatp, G2W1, G3W1, G4W1},
    {"double-floatp",           G0W1, Ldouble_floatp, G2W1, G3W1, G4W1},
    {"long-floatp",             G0W1, Llong_floatp, G2W1, G3W1, G4W1},
    {"mantissa-bits",           G0W1, Lmantissa_bits, G2W1, G3W1, G4W1},
    {"rationalp",               G0W1, Lrationalp, G2W1, G3W1, G4W1},
    {"complexp",                G0W1, Lcomplexp, G2W1, G3W1, G4W1},
    {"bit-vector-p",            G0W1, Lsimple_bit_vector_p, G2W1, G3W1, G4W1},
    {"simple-bit-vector-p",     G0W1, Lsimple_bit_vector_p, G2W1, G3W1, G4W1},
    {"get",                     G0Wother, G1Wother, Lget, Lget_3, G4Wother},
    {"arrayp",                  G0W1, Larrayp, G2W1, G3W1, G4W1},
    {"complex-arrayp",          G0W1, Lcomplex_arrayp, G2W1, G3W1, G4W1},
    {"consp",                   G0W1, Lconsp, G2W1, G3W1, G4W1},
    {"convert-to-array",        G0W1, Lconvert_to_array, G2W1, G3W1, G4W1},
    {"convert-to-struct",       G0W1, Lconvert_to_struct, G2W1, G3W1, G4W1},
    {"identity",                G0W1, Lidentity, G2W1, G3W1, G4W1},
    {"list",                    Lnilfn, Lncons, Llist_2, Llist_3, Llist_4up},
    {"list*",                   G0W1, Lidentity, Lcons, Llist_2star, Lliststar_4up},
    {"listp",                   G0W1, Llistp, G2W1, G3W1, G4W1},
    {"structp",                 G0W1, Lstructp, G2W1, G3W1, G4W1},
    {"flag",                    G0W2, G1W2, Lflag, G3W2, G4W2},
    {"flagp",                   G0W2, G1W2, Lflagp, G3W2, G4W2},
    {"flagpcar",                G0W2, G1W2, Lflagpcar, G3W2, G4W2},
    {"remflag",                 G0W2, G1W2, Lremflag, G3W2, G4W2},
    {"time*",                   Ltime, G1W0, G2W0, G3W0, G4W0},
    {"convert-to-evector",      G0W1, Lconvert_to_struct, G2W1, G3W1, G4W1},
    {"evectorp",                G0W1, Lstructp, G2W1, G3W1, G4W1},
    {"get*",                    G0W2, G1W2, Lget, G3W2, G4W2},
    {"pairp",                   G0W1, Lconsp, G2W1, G3W1, G4W1},
    {"consp",                   G0W1, Lconsp, G2W1, G3W1, G4W1},
    {"flagp**",                 G0W2, G1W2, Lflagp, G3W2, G4W2},
    {"cl-stringp",              G0W1, Lc_stringp, G2W1, G3W1, G4W1},
    {"stringp",                 G0W1, Lstringp, G2W1, G3W1, G4W1},
    {"threevectorp",            G0W1, Lthreevectorp, G2W1, G3W1, G4W1},
    {"vectorp",                 G0W1, Lsimple_vectorp, G2W1, G3W1, G4W1},
    {"open-foreign-library",    G0W1, Lopen_foreign_library, G2W1, G3W1, G4W1},
    {"find-foreign-function",   G0W2, G1W2, Lfind_foreign_function, G3W2, G4W2},
    {"call-foreign-function",   G0Wother, Lcallf_1, Lcallf_2, Lcallf_3, Lcallf_4up},
    {"get-callback",            G0W1, Lget_callback, G2W1, G3W1, G4W1},
    {"gc-forcer",               G0Wother, Lgc_forcer1, Lgc_forcer, G3Wother, G4Wother},
    {"sigsegv",                 G0W1, Lsigsegv, G2W1, G3W1, G4W1},
    {NULL,                      0, 0, 0, 0, 0}
};

// end of fns1.cpp
