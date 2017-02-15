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

LispObject integerp(LispObject p)
{   int tag = ((int)p) & TAG_BITS;
    if (tag == TAG_FIXNUM) return lisp_true;
    else if (tag == TAG_NUMBERS)
    {   Header h = *(Header *)((char *)p - TAG_NUMBERS);
        if (type_of_header(h) == TYPE_BIGNUM) return lisp_true;
        else return nil;
    }
    else return nil;
}

/*****************************************************************************/
//      Storage allocation.
/*****************************************************************************/


LispObject cons(LispObject a, LispObject b)
{   LispObject r = (LispObject)((char *)fringe - sizeof(Cons_Cell));
    qcar(r) = a;
    qcdr(r) = b;
    fringe = r;
    if ((char *)r <= (char *)heaplimit)
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

//
// cons_gc_test() MUST be called after any sequence of cons_no_gc() calls.
//

LispObject cons_gc_test(LispObject p)
{   if ((char *)fringe <= (char *)heaplimit)
        return reclaim(p, "cons gc test", GC_CONS, 0);
    else return p;
}

LispObject ncons(LispObject a)
{   LispObject r = (LispObject)((char *)fringe - sizeof(Cons_Cell));
    qcar(r) = a;
    qcdr(r) = nil;
    fringe = r;
    if ((char *)r <= (char *)heaplimit)
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
    if ((char *)r <= (char *)heaplimit)
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
    if ((char *)r <= (char *)heaplimit)
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
    if ((char *)r <= (char *)heaplimit)
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
    if ((char *)r <= (char *)heaplimit)
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
    if ((char *)r <= (char *)heaplimit)
        return reclaim((LispObject)((char *)r + TAG_CONS),
                       "internal acons", GC_CONS, 0);
    else return (LispObject)((char *)r + TAG_CONS);
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
    if ((char *)r <= (char *)heaplimit)
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
{   if (is_sfloat(p)) return onevalue(lisp_true);
    else return onevalue(nil);
}

static LispObject Lsingle_floatp(LispObject env, LispObject p)
{   int tag = TAG_BITS & (int)p;
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
{   if (!(is_vector(a))) return onevalue(nil);
    vechdr(a) = TYPE_ARRAY + (vechdr(a) & ~header_mask);
    return onevalue(a);
}

static LispObject Lstructp(LispObject env, LispObject a)
//
// structp
//
{   if (!(is_vector(a))) return onevalue(nil);
    else return onevalue(Lispify_predicate(
                                 type_of_header(vechdr(a))==TYPE_STRUCTURE));
}

static LispObject Lconvert_to_struct(LispObject env, LispObject a)
{   if (!(is_vector(a))) return onevalue(nil);
    vechdr(a) = TYPE_STRUCTURE + (vechdr(a) & ~header_mask);
    return onevalue(a);
}

LispObject Lcons(LispObject, LispObject a, LispObject b)
{   LispObject r;
    r = (LispObject)((char *)fringe - sizeof(Cons_Cell));
    qcar(r) = a;
    qcdr(r) = b;
    fringe = r;
    if ((char *)r <= (char *)heaplimit)
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
    if ((char *)r <= (char *)heaplimit)
        return onevalue(reclaim((LispObject)((char *)r + TAG_CONS),
                                "xcons", GC_CONS, 0));
    else return onevalue((LispObject)((char *)r + TAG_CONS));
}

LispObject Lncons(LispObject env, LispObject a)
{   LispObject r;
    r = (LispObject)((char *)fringe - sizeof(Cons_Cell));
    qcar(r) = a;
    qcdr(r) = nil;
    fringe = r;
    if ((char *)r <= (char *)heaplimit)
        return onevalue(reclaim((LispObject)((char *)r + TAG_CONS),
                                "ncons", GC_CONS, 0));
    else return onevalue((LispObject)((char *)r + TAG_CONS));
}

LispObject Llist2(LispObject env, LispObject a, LispObject b)
{   a = list2(a, b);
    return onevalue(a);
}

LispObject Lmkquote(LispObject env, LispObject a)
{   a = list2(quote_symbol, a);
    return onevalue(a);
}

LispObject Llist2star(LispObject env, int nargs, ...)
{   va_list aa;
    LispObject a, b, c;
    argcheck(nargs, 3, "list2*");
    va_start(aa, nargs);
    a = va_arg(aa, LispObject);
    b = va_arg(aa, LispObject);
    c = va_arg(aa, LispObject);
    va_end(aa);
    a = list2star(a,b,c);
    return onevalue(a);
}

LispObject Lacons(LispObject env, int nargs, ...)
{   va_list aa;
    LispObject a, b, c;
    argcheck(nargs, 3, "acons");
    va_start(aa, nargs);
    a = va_arg(aa, LispObject);
    b = va_arg(aa, LispObject);
    c = va_arg(aa, LispObject);
    va_end(aa);
    a = acons(a,b,c);
    return onevalue(a);
}

LispObject Llist3(LispObject env, int nargs, ...)
{   va_list aa;
    LispObject a, b, c;
    argcheck(nargs, 3, "list3");
    va_start(aa, nargs);
    a = va_arg(aa, LispObject);
    b = va_arg(aa, LispObject);
    c = va_arg(aa, LispObject);
    va_end(aa);
    a = list3(a,b,c);
    return onevalue(a);
}

LispObject Llist3star(LispObject env, int nargs, ...)
{   va_list aa;
    LispObject a, b, c, d;
    argcheck(nargs, 4, "list3*");
    va_start(aa, nargs);
    a = va_arg(aa, LispObject);
    b = va_arg(aa, LispObject);
    c = va_arg(aa, LispObject);
    d = va_arg(aa, LispObject);
    va_end(aa);
    a = list3star(a,b,c,d);
    return onevalue(a);
}

LispObject Llist4(LispObject env, int nargs, ...)
{   va_list aa;
    LispObject a, b, c, d;
    argcheck(nargs, 4, "list4");
    va_start(aa, nargs);
    a = va_arg(aa, LispObject);
    b = va_arg(aa, LispObject);
    c = va_arg(aa, LispObject);
    d = va_arg(aa, LispObject);
    va_end(aa);
    a = list4(a,b,c,d);
    return onevalue(a);
}


LispObject Llist(LispObject env, int nargs, ...)
{   LispObject r = nil, w, w1;
    va_list a;
    va_start(a, nargs);
    push_args(a, nargs);
    while (nargs > 1)
    {   pop2(w, w1);
        nargs-=2;
        r = list2star(w1, w, r);
    }
// I could possibly speed up long cases a little by doing 2 or 3 cons
// operations at a time...
    while (nargs > 0)
    {   pop(w);
        nargs--;
        r = cons(w, r);
    }
    return onevalue(r);
}

static LispObject Lliststar(LispObject env, int nargs, ...)
{   LispObject r, w, w1;
    va_list a;
    if (nargs == 0) return onevalue(nil);
    va_start(a, nargs);
    push_args(a, nargs);
    pop(r);
    nargs--;
    while (nargs > 1)
    {   pop2(w, w1);
        nargs-=2;
        r = list2star(w1, w, r);
    }
    while (nargs > 0)
    {   pop(w);
        nargs--;
        r = cons(w, r);
    }
    return onevalue(r);
}

//
// fill-vector is used for open-compilation of (vector ...) to avoid
// passing grossly unreasonable numbers of arguments. The expansion of
// (vector e1 ... en) should be
//    (let ((v (mkvect <n-1>)) (i 0))
//       (setq i (fill-vector v i e1 e2 ... e10))
//       (setq i (fill-vector v i e11 e12 ... ))
//       ...
//       v)
//
static LispObject Lfill_vector(LispObject, int nargs, ...)
{   va_list a;
    LispObject v, il;
    intptr_t i;
    if (nargs < 3) aerror("fill-vector");
    va_start(a, nargs);
    v = va_arg(a, LispObject);
    il = va_arg(a, LispObject);
    if (!is_vector(v) || !is_fixnum(il)) aerror("fill-vector");
    i = int_of_fixnum(il);
    nargs -= 2;
    while (nargs != 0)
    {   elt(v, i++) = va_arg(a, LispObject);
        nargs--;
    }
    return onevalue(fixnum_of_int(i));
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

LispObject Lunwind(LispObject env, int nargs, ...)
{   argcheck(nargs, 0, "unwind");
    exit_reason = (miscflags & ARGS_FLAG) ? UNWIND_ERROR :
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

void Lerror(LispObject env, int nargs, ...)
{   va_list a;
    LispObject w;
#ifdef COMMON
    LispObject r = nil, w1;
#else
    int i;
#endif
    if (nargs == 0) aerror("error");
    errors_now++;
    if (errors_limit >= 0 && errors_now > errors_limit)
        resource_exceeded();
    va_start(a, nargs);
    push_args(a, nargs);
#ifdef COMMON
    while (nargs > 1)
    {   pop2(w, w1);
        nargs -= 2;
        if_error(r = list2star(w1, w, r), r = nil);
    }
    while (nargs > 0)
    {   pop(w);
        nargs--;
        if_error(r = cons(w, r), r = nil);
    }
    if (miscflags & (HEADLINE_FLAG|ALWAYS_NOISY))
    {   push(r);
        err_printf("\n+++ error: ");
//
// I will use FORMAT to handle error messages provided the first arg
// to error had been a string and also provided (for bootstrapping) that
// the function FORMAT seems to be defined.
//
        if (qfn1(format_symbol) == undefined1 ||
            !consp(r) ||
            !stringp(qcar(r))) loop_print_error(r);
        else Lapply_n(nil, 3, format_symbol, qvalue(error_output), r);
        err_printf("\n");
        pop(r);
    }
    qvalue(emsg_star) = r;               // "Error message" in CL world
    exit_value = fixnum_of_int(0);       // "Error number"  in CL world
#else
    if (miscflags & HEADLINE_FLAG)
    {   err_printf("\n+++ error: ");
        loop_print_error(stack[1-nargs]);
        for (i=1; i<nargs; i++)
        {   err_printf(" ");
            loop_print_error(stack[1+i-nargs]);
        }
        err_printf("\n");
    }
    if (nargs == 1)
    {   push(nil);
        nargs++;
    }
    qvalue(emsg_star) = stack[2-nargs];  // "Error message" in SL world
    exit_value = stack[1-nargs];         // "Error number"  in SL world
    popv(nargs);
#endif
    if ((w = qvalue(break_function)) != nil &&
        symbolp(w) &&
        qfn1(w) != undefined1)
    {   (*qfn1(w))(qenv(w), qvalue(emsg_star));
    }
    exit_reason = (miscflags & ARGS_FLAG) ? UNWIND_ERROR :
                  (miscflags & FNAME_FLAG) ? UNWIND_FNAME :
                  UNWIND_UNWIND;
    exit_count = 0;
    exit_tag = nil;
    throw LispError();
}

void Lerror1(LispObject env, LispObject a1)
{   Lerror(env, 1, a1);
}

void Lerror2(LispObject env, LispObject a1, LispObject a2)
{   Lerror(env, 2, a1, a2);
}

void Lerror0(LispObject env, int nargs, ...)
{
//
// Silently provoked error - unwind to surrounding errorset level. Note that
// this will NEVER enter a user-provided break loop...
// Also note that (enable-errorset) can set a lower limit to noise levels
// that can result in the error here NOT being silent!
//
    argcheck(nargs, 0, "error0");
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
{   one_args *f1;
    two_args *f2;
    n_args *fn;
    if (!symbolp(a)) return onevalue(nil);
// @@ This will need adapting for fn0 and fn3...
    f1 = qfn1(a); f2 = qfn2(a); fn = qfnn(a);
    if ((qheader(a) & (SYM_SPECIAL_FORM | SYM_MACRO)) != 0 ||
        (f1 == undefined1 && f2 == undefined2 &&
         fn == undefinedn)) return onevalue(nil);
    else if (f1 == interpreted1 ||
             f2 == interpreted2 ||
             fn == interpretedn)
// I wonder if onevalue(cons(...)) is really valid here. It is OK in SL mode
        return onevalue(cons(lambda, qenv(a)));
    else if (f1 == funarged1 ||
             f2 == funarged2 ||
             fn == funargedn)
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
        qfnn(b) = qfnn(a);
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

#ifdef DEBUG_VALIDATE
static int validate_count = 0;
#endif

LispObject getvector(int tag, int type, size_t size)
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
#ifdef DEBUG_VALIDATE
//
// If I do a full validation every time I allocate a vector that REALLY
// hits performance, so I will do it occasionally. The 1 in 500 indicated
// at present is a pretty random choice of frequency!
//
    if ((++validate_count) % 500 == 0)
    {   copy_into_nilseg(false);
        validate_all("getvector", __LINE__, __FILE__);
    }
#endif
    for (;;)
    {   char *r = (char *)vfringe;
        size_t free = (size_t)((char *)vheaplimit - r);
//
// On a 64-bit system the allocation size will be a multiple of 8 anyway, so
// the doubleword_align here will have no effect! The result is that I never
// need or use a padding word at the end of a vector in that case. Note that
// well. On 32-bit systems vectors may have a dummy padder word at the end
// but on 64-bit systems they do not.
//
        size_t alloc_size = (size_t)doubleword_align_up(size);
//
// There is a real NASTY here - it is quite possible that I ought to implement
// a scheme whereby large vectors can be allocated as a series of chunks so as
// to avoid the current absolute limit on size.
// For now there is a limit on the size of the largest vector you can
// create.
        if (alloc_size > (CSL_PAGE_SIZE - 32))
            aerror1("vector request too big",
                           fixnum_of_int(alloc_size/CELL-1));
        if (alloc_size > free)
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
                    sprintf(msg, "getvector(%lx,%ld)", (long)tag, (long)size);
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
        return (LispObject)(r + tag);
    }
}

LispObject getvector_init(size_t n, LispObject k)
{   LispObject p;
    push(k);
    p = getvector(TAG_VECTOR, TYPE_SIMPLE_VEC, n);
    pop(k);
    if (!SIXTY_FOUR_BIT && ((n & 4) != 0))
        n += 4;   // Ensure last doubleword is tidy
    while (n > CELL)
    {   n -= CELL;
        *(LispObject *)((char *)p - TAG_VECTOR + n) = k;
    }
    return p;
}

void Lstop(LispObject env, LispObject code)
{   if (!is_fixnum(code)) aerror("stop");
    exit_value = code;
    exit_tag = fixnum_of_int(0);    // Flag to say "stop"
    exit_reason = UNWIND_RESTART;
    exit_count = 1;
    throw LispRestart();
}

void Lstop2(LispObject env, LispObject code, LispObject)
{   Lstop(env, code);
}

void Lstop0(LispObject env, int nargs, ...)
{   va_list aa;
    LispObject code = fixnum_of_int(0);
    if (nargs != 0)
    {   va_start(aa, nargs);
        code = va_arg(aa, LispObject);
        va_end(aa);
    }
    Lstop(env, code);
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

LispObject Ltime(LispObject env, int nargs, ...)
{   LispObject r;
    if (clock_stack == &consolidated_time[0])
    {   clock_t t0 = read_clock();
        double delta = (double)(t0 - base_time)/(double)CLOCKS_PER_SEC;
        base_time = t0;
        consolidated_time[0] += delta;
    }
    argcheck(nargs, 0, "time");
    r = make_lisp_unsigned64((uint64_t)(1000.0 * consolidated_time[0]));
    return onevalue(r);
}

LispObject Lgctime(LispObject env, int nargs, ...)
{   LispObject r;
    argcheck(nargs, 0, "gctime");
    r = make_lisp_unsigned64((uint64_t)(1000.0 * gc_time));
    return onevalue(r);
}

LispObject Ldecoded_time(LispObject env, int nargs, ...)
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
    argcheck(nargs, 0, "get-decoded-time");
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

LispObject Ldate(LispObject env, int nargs, ...)
{   LispObject w;
    time_t t = time(NULL);
    char today[32];
    char today1[32];
    argcheck(nargs, 0, "date");
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

LispObject Ldate_and_time(LispObject env, int nargs, ...)
{   LispObject w;
    time_t t = time(NULL);
    char today[32];
    argcheck(nargs, 0, "date");
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

LispObject Ldatestamp(LispObject env, int nargs, ...)
//
// Returns date-stamp integer, which on many systems will be the
// number of seconds between 1970.0.0 and now, but which could be
// pretty-well almost any other thing, as per the C "time_t" type.
// I do not allow for time-zones etc here either!
//
{   LispObject r;
    time_t t = time(NULL);
    argcheck(nargs, 0, "datestamp");
    r = make_lisp_integer64((int64_t)t);
    return onevalue(r);
}

LispObject Ltimeofday(LispObject env, int nargs, ...)
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
    argcheck(nargs, 0, "datestamp");
    w = make_lisp_unsigned64(n);
    w = cons(w, fixnum_of_int(un));
    return onevalue(w);
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
//=== //
//=== // Again I will leave the print statement in on a temporary basis...
//=== //
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
    return onevalue(r);
}

//
// (call!-foreign!-function fnptr)
// call the function as found by find!-foreign!-function not passing it
// any arguments and not expecting any result.
//

LispObject Lcallf1(LispObject env, LispObject entry)
{   void *f;
    if (Lencapsulatedp(nil, entry) == nil)
        aerror("call-foreign-function");
    f = extract_pointer(entry);
    (*(void(*)())f)();
    return onevalue(nil);
}

//
// For calling foreign functions I need to know something of their type
// signature. The view I will take here is NOT guaranteed portable but
// is liable to work on many practical systems. I classify arguments that
// are actually passed as Int32, Int64 or Double. These are expected to
// be sufficiant for:
// Int32     int when sizeof(int)==4
//           char *, void * when sizeof(void *)==4, and hence "abcdef"
//           'x'
// Int64     int, long or long long when sizeof(.)==8
//           size_t if it has size 8
//           char *, void *, strings etc when size 8
// Double    double
//
// So the code that arranges to pass arguments will need to map from one of
// the intended types to one of the above three options. It could be that for
// some system that pointers and integers (of the relevant with) are passed in
// different locations or with different alignment constraints, but I believe
// that will not be the case on any system I am at present concerned with.
// Result types can be any of the above together with Void.
// As one further mess, a function signature can end with "..." and I use
// the pseudo-type VarArg to denote that.
//

#define foreign_Int32  0
#define foreign_Int64  1
#define foreign_Double 2
#define foreign_VarArg 3
//
// The ones that follow are only given as return types.
//
#define foreign_Void   4
#define foreign_String 5

#define A1(a1)             (a1)
#define A2(a1, a2)         ((a2)<<2 | (a1))
#define A3(a1, a2, a3)     ((a3)<<4 | (a2)<<2 | (a1))
#define A4(a1, a2, a3, a4) ((a4)<<6 | (a3)<<4 | (a2)<<2 | (a1))

#define MAX_ARGCOUNT 10
#define MAX_STRINGLEN 256

int32_t i32a[MAX_ARGCOUNT];
int64_t i64a[MAX_ARGCOUNT];
double da[MAX_ARGCOUNT];
char sa[MAX_ARGCOUNT][MAX_STRINGLEN];

int32_t i32r;
int64_t i64r;
double dr;

//
// This seems HORRID to me, and as it is it only supports passing up to three
// arguments. The alternatives that I can think of seem even worse!
// Well ACTUALLY I should change all of this to use "libffi" (which is subject
// to a generously liberal license and so will not cause problems in the
// BSD context I am working in). But it would be nice if somebody else did
// that conversion for me... since it should be a useful and self-contained
// task that would generalise and clean up the code but doing it would take
// me away from other things that I also want to do.
//

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

// I rather strongly believe that by using libffi I could make the code
// here a LOT nicer!

LispObject callforeign(void *f, int returntype, int nargs, int signature)
{   int rt = (returntype == foreign_String) ?
             (sizeof(char *)==4 ? foreign_Int32 : foreign_Int64) :
             returntype;
    switch (rt)
    {   case foreign_Void:
            switch (nargs)
            {   case 0:
                    (*(void(*)())f)();
                    return onevalue(nil);
                case 1:
                    switch (signature)
                    {   case A1(foreign_Int32):
                            (*(void(*)(int32_t))f)(i32a[0]);
                            return onevalue(nil);
                        case A1(foreign_Int64):
                            (*(void(*)(int64_t))f)(i64a[0]);
                            return onevalue(nil);
                        case A1(foreign_Double):
                            (*(void(*)(double))f)(da[0]);
                            return onevalue(nil);
                        default:
                            break;
                    }
                case 2:
                    switch (signature)
                    {   case A2(foreign_Int32,foreign_Int32):
                            (*(void(*)(int32_t,int32_t))f)(i32a[0],i32a[1]);
                            return onevalue(nil);
                        case A2(foreign_Int32,foreign_Int64):
                            (*(void(*)(int32_t,int64_t))f)(i32a[0],i64a[1]);
                            return onevalue(nil);
                        case A2(foreign_Int32,foreign_Double):
                            (*(void(*)(int32_t,double))f)(i32a[0],da[1]);
                            return onevalue(nil);
                        case A2(foreign_Int64,foreign_Int32):
                            (*(void(*)(int64_t,int32_t))f)(i64a[0],i32a[1]);
                            return onevalue(nil);
                        case A2(foreign_Int64,foreign_Int64):
                            (*(void(*)(int64_t,int64_t))f)(i64a[0],i64a[1]);
                            return onevalue(nil);
                        case A2(foreign_Int64,foreign_Double):
                            (*(void(*)(int64_t,double))f)(i64a[0],da[1]);
                            return onevalue(nil);
                        case A2(foreign_Double,foreign_Int32):
                            (*(void(*)(double,int32_t))f)(da[0],i32a[1]);
                            return onevalue(nil);
                        case A2(foreign_Double,foreign_Int64):
                            (*(void(*)(double,int64_t))f)(da[0],i64a[1]);
                            return onevalue(nil);
                        case A2(foreign_Double,foreign_Double):
                            (*(void(*)(double,double))f)(da[0],da[1]);
                            return onevalue(nil);
                        default:
                            break;
                    }
                case 3:
                    switch (signature)
                    {   case A3(foreign_Int32,foreign_Int32,foreign_Int32):
                            (*(void(*)(int32_t,int32_t,int32_t))f)(i32a[0],i32a[1],i32a[2]);
                            return onevalue(nil);
                        case A3(foreign_Int32,foreign_Int32,foreign_Int64):
                            (*(void(*)(int32_t,int32_t,int64_t))f)(i32a[0],i32a[1],i64a[2]);
                            return onevalue(nil);
                        case A3(foreign_Int32,foreign_Int32,foreign_Double):
                            (*(void(*)(int32_t,int32_t,double))f)(i32a[0],i32a[1],da[2]);
                            return onevalue(nil);
                        case A3(foreign_Int32,foreign_Int64,foreign_Int32):
                            (*(void(*)(int32_t,int64_t,int32_t))f)(i32a[0],i64a[1],i32a[2]);
                            return onevalue(nil);
                        case A3(foreign_Int32,foreign_Int64,foreign_Int64):
                            (*(void(*)(int32_t,int64_t,int64_t))f)(i32a[0],i64a[1],i32a[2]);
                            return onevalue(nil);
                        case A3(foreign_Int32,foreign_Int64,foreign_Double):
                            (*(void(*)(int32_t,int64_t,double))f)(i32a[0],i64a[1],da[2]);
                            return onevalue(nil);
                        case A3(foreign_Int32,foreign_Double,foreign_Int32):
                            (*(void(*)(int32_t,double,int32_t))f)(i32a[0],da[1],i32a[2]);
                            return onevalue(nil);
                        case A3(foreign_Int32,foreign_Double,foreign_Int64):
                            (*(void(*)(int32_t,double,int64_t))f)(i32a[0],da[1],i32a[2]);
                            return onevalue(nil);
                        case A3(foreign_Int32,foreign_Double,foreign_Double):
                            (*(void(*)(int32_t,double,double))f)(i32a[0],da[1],da[2]);
                            return onevalue(nil);

                        case A3(foreign_Int64,foreign_Int32,foreign_Int32):
                            (*(void(*)(int64_t,int32_t,int32_t))f)(i64a[0],i32a[1],i32a[2]);
                            return onevalue(nil);
                        case A3(foreign_Int64,foreign_Int32,foreign_Int64):
                            (*(void(*)(int64_t,int32_t,int64_t))f)(i64a[0],i32a[1],i64a[2]);
                            return onevalue(nil);
                        case A3(foreign_Int64,foreign_Int32,foreign_Double):
                            (*(void(*)(int64_t,int32_t,double))f)(i64a[0],i32a[1],da[2]);
                            return onevalue(nil);
                        case A3(foreign_Int64,foreign_Int64,foreign_Int32):
                            (*(void(*)(int64_t,int64_t,int32_t))f)(i64a[0],i64a[1],i32a[2]);
                            return onevalue(nil);
                        case A3(foreign_Int64,foreign_Int64,foreign_Int64):
                            (*(void(*)(int64_t,int64_t,int64_t))f)(i64a[0],i64a[1],i64a[2]);
                            return onevalue(nil);
                        case A3(foreign_Int64,foreign_Int64,foreign_Double):
                            (*(void(*)(int64_t,int64_t,double))f)(i64a[0],i64a[1],da[2]);
                            return onevalue(nil);
                        case A3(foreign_Int64,foreign_Double,foreign_Int32):
                            (*(void(*)(int64_t,double,int32_t))f)(i64a[0],da[1],i32a[2]);
                            return onevalue(nil);
                        case A3(foreign_Int64,foreign_Double,foreign_Int64):
                            (*(void(*)(int64_t,double,int64_t))f)(i64a[0],da[1],i64a[2]);
                            return onevalue(nil);
                        case A3(foreign_Int64,foreign_Double,foreign_Double):
                            (*(void(*)(int64_t,double,double))f)(i64a[0],da[1],da[2]);
                            return onevalue(nil);

                        case A3(foreign_Double,foreign_Int32,foreign_Int32):
                            (*(void(*)(double,int32_t,int32_t))f)(da[0],i32a[1],i32a[2]);
                            return onevalue(nil);
                        case A3(foreign_Double,foreign_Int32,foreign_Int64):
                            (*(void(*)(double,int32_t,int64_t))f)(da[0],i32a[1],i64a[2]);
                            return onevalue(nil);
                        case A3(foreign_Double,foreign_Int32,foreign_Double):
                            (*(void(*)(double,int32_t,double))f)(da[0],i32a[1],da[2]);
                            return onevalue(nil);
                        case A3(foreign_Double,foreign_Int64,foreign_Int32):
                            (*(void(*)(double,int64_t,int32_t))f)(da[0],i64a[1],i32a[2]);
                            return onevalue(nil);
                        case A3(foreign_Double,foreign_Int64,foreign_Int64):
                            (*(void(*)(double,int64_t,int64_t))f)(da[0],i64a[1],i64a[2]);
                            return onevalue(nil);
                        case A3(foreign_Double,foreign_Int64,foreign_Double):
                            (*(void(*)(double,int64_t,double))f)(da[0],i64a[1],da[2]);
                            return onevalue(nil);
                        case A3(foreign_Double,foreign_Double,foreign_Int32):
                            (*(void(*)(double,double,int32_t))f)(da[0],da[1],i32a[2]);
                            return onevalue(nil);
                        case A3(foreign_Double,foreign_Double,foreign_Int64):
                            (*(void(*)(double,double,int64_t))f)(da[0],da[1],i64a[2]);
                            return onevalue(nil);
                        case A3(foreign_Double,foreign_Double,foreign_Double):
                            (*(void(*)(double,double,double))f)(da[0],da[1],da[2]);
                            return onevalue(nil);
                        default:
                            break;
                    }
                    break;
            }
            break;
        case foreign_Int32:
            switch (nargs)
            {   case 0:
                    i32r = (*(int32_t(*)())f)();
                    return make_lisp_integer32(i32r);
                case 1:
                    switch (signature)
                    {   case A1(foreign_Int32):
                            i32r = (*(int32_t(*)(int32_t))f)(i32a[0]);
                            return make_lisp_integer32(i32r);
                        case A1(foreign_Int64):
                            i32r = (*(int32_t(*)(int64_t))f)(i64a[0]);
                            return make_lisp_integer32(i32r);
                        case A1(foreign_Double):
                            i32r = (*(int32_t(*)(double))f)(da[0]);
                            return make_lisp_integer32(i32r);
                        default:
                            break;
                    }
                case 2:
                    switch (signature)
                    {   case A2(foreign_Int32,foreign_Int32):
                            i32r = (*(int32_t(*)(int32_t,int32_t))f)(i32a[0],i32a[1]);
                            return make_lisp_integer32(i32r);
                        case A2(foreign_Int32,foreign_Int64):
                            i32r = (*(int32_t(*)(int32_t,int64_t))f)(i32a[0],i64a[1]);
                            return make_lisp_integer32(i32r);
                        case A2(foreign_Int32,foreign_Double):
                            i32r = (*(int32_t(*)(int32_t,double))f)(i32a[0],da[1]);
                            return make_lisp_integer32(i32r);
                        case A2(foreign_Int64,foreign_Int32):
                            i32r = (*(int32_t(*)(int64_t,int32_t))f)(i64a[0],i32a[1]);
                            return make_lisp_integer32(i32r);
                        case A2(foreign_Int64,foreign_Int64):
                            i32r = (*(int32_t(*)(int64_t,int64_t))f)(i64a[0],i64a[1]);
                            return make_lisp_integer32(i32r);
                        case A2(foreign_Int64,foreign_Double):
                            i32r = (*(int32_t(*)(int64_t,double))f)(i64a[0],da[1]);
                            return make_lisp_integer32(i32r);
                        case A2(foreign_Double,foreign_Int32):
                            i32r = (*(int32_t(*)(double,int32_t))f)(da[0],i32a[1]);
                            return make_lisp_integer32(i32r);
                        case A2(foreign_Double,foreign_Int64):
                            i32r = (*(int32_t(*)(double,int64_t))f)(da[0],i64a[1]);
                            return make_lisp_integer32(i32r);
                        case A2(foreign_Double,foreign_Double):
                            i32r = (*(int32_t(*)(double,double))f)(da[0],da[1]);
                            return make_lisp_integer32(i32r);
                        default:
                            break;
                    }
                case 3:
                    switch (signature)
                    {   case A3(foreign_Int32,foreign_Int32,foreign_Int32):
                            i32r = (*(int32_t(*)(int32_t,int32_t,int32_t))f)(i32a[0],i32a[1],i32a[2]);
                            return make_lisp_integer32(i32r);
                        case A3(foreign_Int32,foreign_Int32,foreign_Int64):
                            i32r = (*(int32_t(*)(int32_t,int32_t,int64_t))f)(i32a[0],i32a[1],i64a[2]);
                            return make_lisp_integer32(i32r);
                        case A3(foreign_Int32,foreign_Int32,foreign_Double):
                            i32r = (*(int32_t(*)(int32_t,int32_t,double))f)(i32a[0],i32a[1],da[2]);
                            return make_lisp_integer32(i32r);
                        case A3(foreign_Int32,foreign_Int64,foreign_Int32):
                            i32r = (*(int32_t(*)(int32_t,int64_t,int32_t))f)(i32a[0],i64a[1],i32a[2]);
                            return make_lisp_integer32(i32r);
                        case A3(foreign_Int32,foreign_Int64,foreign_Int64):
                            i32r = (*(int32_t(*)(int32_t,int64_t,int64_t))f)(i32a[0],i64a[1],i32a[2]);
                            return make_lisp_integer32(i32r);
                        case A3(foreign_Int32,foreign_Int64,foreign_Double):
                            i32r = (*(int32_t(*)(int32_t,int64_t,double))f)(i32a[0],i64a[1],da[2]);
                            return make_lisp_integer32(i32r);
                        case A3(foreign_Int32,foreign_Double,foreign_Int32):
                            i32r = (*(int32_t(*)(int32_t,double,int32_t))f)(i32a[0],da[1],i32a[2]);
                            return make_lisp_integer32(i32r);
                        case A3(foreign_Int32,foreign_Double,foreign_Int64):
                            i32r = (*(int32_t(*)(int32_t,double,int64_t))f)(i32a[0],da[1],i32a[2]);
                            return make_lisp_integer32(i32r);
                        case A3(foreign_Int32,foreign_Double,foreign_Double):
                            i32r = (*(int32_t(*)(int32_t,double,double))f)(i32a[0],da[1],da[2]);
                            return make_lisp_integer32(i32r);

                        case A3(foreign_Int64,foreign_Int32,foreign_Int32):
                            i32r = (*(int32_t(*)(int64_t,int32_t,int32_t))f)(i64a[0],i32a[1],i32a[2]);
                            return make_lisp_integer32(i32r);
                        case A3(foreign_Int64,foreign_Int32,foreign_Int64):
                            i32r = (*(int32_t(*)(int64_t,int32_t,int64_t))f)(i64a[0],i32a[1],i64a[2]);
                            return make_lisp_integer32(i32r);
                        case A3(foreign_Int64,foreign_Int32,foreign_Double):
                            i32r = (*(int32_t(*)(int64_t,int32_t,double))f)(i64a[0],i32a[1],da[2]);
                            return make_lisp_integer32(i32r);
                        case A3(foreign_Int64,foreign_Int64,foreign_Int32):
                            i32r = (*(int32_t(*)(int64_t,int64_t,int32_t))f)(i64a[0],i64a[1],i32a[2]);
                            return make_lisp_integer32(i32r);
                        case A3(foreign_Int64,foreign_Int64,foreign_Int64):
                            i32r = (*(int32_t(*)(int64_t,int64_t,int64_t))f)(i64a[0],i64a[1],i64a[2]);
                            return make_lisp_integer32(i32r);
                        case A3(foreign_Int64,foreign_Int64,foreign_Double):
                            i32r = (*(int32_t(*)(int64_t,int64_t,double))f)(i64a[0],i64a[1],da[2]);
                            return make_lisp_integer32(i32r);
                        case A3(foreign_Int64,foreign_Double,foreign_Int32):
                            i32r = (*(int32_t(*)(int64_t,double,int32_t))f)(i64a[0],da[1],i32a[2]);
                            return make_lisp_integer32(i32r);
                        case A3(foreign_Int64,foreign_Double,foreign_Int64):
                            i32r = (*(int32_t(*)(int64_t,double,int64_t))f)(i64a[0],da[1],i64a[2]);
                            return make_lisp_integer32(i32r);
                        case A3(foreign_Int64,foreign_Double,foreign_Double):
                            i32r = (*(int32_t(*)(int64_t,double,double))f)(i64a[0],da[1],da[2]);
                            return make_lisp_integer32(i32r);

                        case A3(foreign_Double,foreign_Int32,foreign_Int32):
                            i32r = (*(int32_t(*)(double,int32_t,int32_t))f)(da[0],i32a[1],i32a[2]);
                            return make_lisp_integer32(i32r);
                        case A3(foreign_Double,foreign_Int32,foreign_Int64):
                            i32r = (*(int32_t(*)(double,int32_t,int64_t))f)(da[0],i32a[1],i64a[2]);
                            return make_lisp_integer32(i32r);
                        case A3(foreign_Double,foreign_Int32,foreign_Double):
                            i32r = (*(int32_t(*)(double,int32_t,double))f)(da[0],i32a[1],da[2]);
                            return make_lisp_integer32(i32r);
                        case A3(foreign_Double,foreign_Int64,foreign_Int32):
                            i32r = (*(int32_t(*)(double,int64_t,int32_t))f)(da[0],i64a[1],i32a[2]);
                            return make_lisp_integer32(i32r);
                        case A3(foreign_Double,foreign_Int64,foreign_Int64):
                            i32r = (*(int32_t(*)(double,int64_t,int64_t))f)(da[0],i64a[1],i64a[2]);
                            return make_lisp_integer32(i32r);
                        case A3(foreign_Double,foreign_Int64,foreign_Double):
                            i32r = (*(int32_t(*)(double,int64_t,double))f)(da[0],i64a[1],da[2]);
                            return make_lisp_integer32(i32r);
                        case A3(foreign_Double,foreign_Double,foreign_Int32):
                            i32r = (*(int32_t(*)(double,double,int32_t))f)(da[0],da[1],i32a[2]);
                            return make_lisp_integer32(i32r);
                        case A3(foreign_Double,foreign_Double,foreign_Int64):
                            i32r = (*(int32_t(*)(double,double,int64_t))f)(da[0],da[1],i64a[2]);
                            return make_lisp_integer32(i32r);
                        case A3(foreign_Double,foreign_Double,foreign_Double):
                            i32r = (*(int32_t(*)(double,double,double))f)(da[0],da[1],da[2]);
                            return make_lisp_integer32(i32r);
                        default:
                            break;
                    }
                    break;
            }
            break;
        case foreign_Int64:
            switch (nargs)
            {   case 0:
                    i64r = (*(int64_t(*)())f)();
                    return make_lisp_integer64(i64r);
                case 1:
                    switch (signature)
                    {   case A1(foreign_Int32):
                            i64r = (*(int64_t(*)(int32_t))f)(i32a[0]);
                            return make_lisp_integer64(i64r);
                        case A1(foreign_Int64):
                            i64r = (*(int64_t(*)(int64_t))f)(i64a[0]);
                            return make_lisp_integer64(i64r);
                        case A1(foreign_Double):
                            i64r = (*(int64_t(*)(double))f)(da[0]);
                            return make_lisp_integer64(i64r);
                        default:
                            break;
                    }
                case 2:
                    switch (signature)
                    {   case A2(foreign_Int32,foreign_Int32):
                            i64r = (*(int64_t(*)(int32_t,int32_t))f)(i32a[0],i32a[1]);
                            return make_lisp_integer64(i64r);
                        case A2(foreign_Int32,foreign_Int64):
                            i64r = (*(int64_t(*)(int32_t,int64_t))f)(i32a[0],i64a[1]);
                            return make_lisp_integer64(i64r);
                        case A2(foreign_Int32,foreign_Double):
                            i64r = (*(int64_t(*)(int32_t,double))f)(i32a[0],da[1]);
                            return make_lisp_integer64(i64r);
                        case A2(foreign_Int64,foreign_Int32):
                            i64r = (*(int64_t(*)(int64_t,int32_t))f)(i64a[0],i32a[1]);
                            return make_lisp_integer64(i64r);
                        case A2(foreign_Int64,foreign_Int64):
                            i64r = (*(int64_t(*)(int64_t,int64_t))f)(i64a[0],i64a[1]);
                            return make_lisp_integer64(i64r);
                        case A2(foreign_Int64,foreign_Double):
                            i64r = (*(int64_t(*)(int64_t,double))f)(i64a[0],da[1]);
                            return make_lisp_integer64(i64r);
                        case A2(foreign_Double,foreign_Int32):
                            i64r = (*(int64_t(*)(double,int32_t))f)(da[0],i32a[1]);
                            return make_lisp_integer64(i64r);
                        case A2(foreign_Double,foreign_Int64):
                            i64r = (*(int64_t(*)(double,int64_t))f)(da[0],i64a[1]);
                            return make_lisp_integer64(i64r);
                        case A2(foreign_Double,foreign_Double):
                            i64r = (*(int64_t(*)(double,double))f)(da[0],da[1]);
                            return make_lisp_integer64(i64r);
                        default:
                            break;
                    }
                case 3:
                    switch (signature)
                    {   case A3(foreign_Int32,foreign_Int32,foreign_Int32):
                            i64r = (*(int64_t(*)(int32_t,int32_t,int32_t))f)(i32a[0],i32a[1],i32a[2]);
                            return make_lisp_integer64(i64r);
                        case A3(foreign_Int32,foreign_Int32,foreign_Int64):
                            i64r = (*(int64_t(*)(int32_t,int32_t,int64_t))f)(i32a[0],i32a[1],i64a[2]);
                            return make_lisp_integer64(i64r);
                        case A3(foreign_Int32,foreign_Int32,foreign_Double):
                            i64r = (*(int64_t(*)(int32_t,int32_t,double))f)(i32a[0],i32a[1],da[2]);
                            return make_lisp_integer64(i64r);
                        case A3(foreign_Int32,foreign_Int64,foreign_Int32):
                            i64r = (*(int64_t(*)(int32_t,int64_t,int32_t))f)(i32a[0],i64a[1],i32a[2]);
                            return make_lisp_integer64(i64r);
                        case A3(foreign_Int32,foreign_Int64,foreign_Int64):
                            i64r = (*(int64_t(*)(int32_t,int64_t,int64_t))f)(i32a[0],i64a[1],i32a[2]);
                            return make_lisp_integer64(i64r);
                        case A3(foreign_Int32,foreign_Int64,foreign_Double):
                            i64r = (*(int64_t(*)(int32_t,int64_t,double))f)(i32a[0],i64a[1],da[2]);
                            return make_lisp_integer64(i64r);
                        case A3(foreign_Int32,foreign_Double,foreign_Int32):
                            i64r = (*(int64_t(*)(int32_t,double,int32_t))f)(i32a[0],da[1],i32a[2]);
                            return make_lisp_integer64(i64r);
                        case A3(foreign_Int32,foreign_Double,foreign_Int64):
                            i64r = (*(int64_t(*)(int32_t,double,int64_t))f)(i32a[0],da[1],i32a[2]);
                            return make_lisp_integer64(i64r);
                        case A3(foreign_Int32,foreign_Double,foreign_Double):
                            i64r = (*(int64_t(*)(int32_t,double,double))f)(i32a[0],da[1],da[2]);
                            return make_lisp_integer64(i64r);

                        case A3(foreign_Int64,foreign_Int32,foreign_Int32):
                            i64r = (*(int64_t(*)(int64_t,int32_t,int32_t))f)(i64a[0],i32a[1],i32a[2]);
                            return make_lisp_integer64(i64r);
                        case A3(foreign_Int64,foreign_Int32,foreign_Int64):
                            i64r = (*(int64_t(*)(int64_t,int32_t,int64_t))f)(i64a[0],i32a[1],i64a[2]);
                            return make_lisp_integer64(i64r);
                        case A3(foreign_Int64,foreign_Int32,foreign_Double):
                            i64r = (*(int64_t(*)(int64_t,int32_t,double))f)(i64a[0],i32a[1],da[2]);
                            return make_lisp_integer64(i64r);
                        case A3(foreign_Int64,foreign_Int64,foreign_Int32):
                            i64r = (*(int64_t(*)(int64_t,int64_t,int32_t))f)(i64a[0],i64a[1],i32a[2]);
                            return make_lisp_integer64(i64r);
                        case A3(foreign_Int64,foreign_Int64,foreign_Int64):
                            i64r = (*(int64_t(*)(int64_t,int64_t,int64_t))f)(i64a[0],i64a[1],i64a[2]);
                            return make_lisp_integer64(i64r);
                        case A3(foreign_Int64,foreign_Int64,foreign_Double):
                            i64r = (*(int64_t(*)(int64_t,int64_t,double))f)(i64a[0],i64a[1],da[2]);
                            return make_lisp_integer64(i64r);
                        case A3(foreign_Int64,foreign_Double,foreign_Int32):
                            i64r = (*(int64_t(*)(int64_t,double,int32_t))f)(i64a[0],da[1],i32a[2]);
                            return make_lisp_integer64(i64r);
                        case A3(foreign_Int64,foreign_Double,foreign_Int64):
                            i64r = (*(int64_t(*)(int64_t,double,int64_t))f)(i64a[0],da[1],i64a[2]);
                            return make_lisp_integer64(i64r);
                        case A3(foreign_Int64,foreign_Double,foreign_Double):
                            i64r = (*(int64_t(*)(int64_t,double,double))f)(i64a[0],da[1],da[2]);
                            return make_lisp_integer64(i64r);

                        case A3(foreign_Double,foreign_Int32,foreign_Int32):
                            i64r = (*(int64_t(*)(double,int32_t,int32_t))f)(da[0],i32a[1],i32a[2]);
                            return make_lisp_integer64(i64r);
                        case A3(foreign_Double,foreign_Int32,foreign_Int64):
                            i64r = (*(int64_t(*)(double,int32_t,int64_t))f)(da[0],i32a[1],i64a[2]);
                            return make_lisp_integer64(i64r);
                        case A3(foreign_Double,foreign_Int32,foreign_Double):
                            i64r = (*(int64_t(*)(double,int32_t,double))f)(da[0],i32a[1],da[2]);
                            return make_lisp_integer64(i64r);
                        case A3(foreign_Double,foreign_Int64,foreign_Int32):
                            i64r = (*(int64_t(*)(double,int64_t,int32_t))f)(da[0],i64a[1],i32a[2]);
                            return make_lisp_integer64(i64r);
                        case A3(foreign_Double,foreign_Int64,foreign_Int64):
                            i64r = (*(int64_t(*)(double,int64_t,int64_t))f)(da[0],i64a[1],i64a[2]);
                            return make_lisp_integer64(i64r);
                        case A3(foreign_Double,foreign_Int64,foreign_Double):
                            i64r = (*(int64_t(*)(double,int64_t,double))f)(da[0],i64a[1],da[2]);
                            return make_lisp_integer64(i64r);
                        case A3(foreign_Double,foreign_Double,foreign_Int32):
                            i64r = (*(int64_t(*)(double,double,int32_t))f)(da[0],da[1],i32a[2]);
                            return make_lisp_integer64(i64r);
                        case A3(foreign_Double,foreign_Double,foreign_Int64):
                            i64r = (*(int64_t(*)(double,double,int64_t))f)(da[0],da[1],i64a[2]);
                            return make_lisp_integer64(i64r);
                        case A3(foreign_Double,foreign_Double,foreign_Double):
                            i64r = (*(int64_t(*)(double,double,double))f)(da[0],da[1],da[2]);
                            return make_lisp_integer64(i64r);
                        default:
                            break;
                    }
                    break;
            }
            break;
        case foreign_Double:
            switch (nargs)
            {   case 0:
                    dr = (*(double(*)())f)();
                    return make_boxfloat(dr, TYPE_DOUBLE_FLOAT);
                case 1:
                    switch (signature)
                    {   case A1(foreign_Int32):
                            dr = (*(double(*)(int32_t))f)(i32a[0]);
                            return make_boxfloat(dr, TYPE_DOUBLE_FLOAT);
                        case A1(foreign_Int64):
                            dr = (*(double(*)(int64_t))f)(i64a[0]);
                            return make_boxfloat(dr, TYPE_DOUBLE_FLOAT);
                        case A1(foreign_Double):
                            dr = (*(double(*)(double))f)(da[0]);
                            return make_boxfloat(dr, TYPE_DOUBLE_FLOAT);
                        default:
                            break;
                    }
                case 2:
                    switch (signature)
                    {   case A2(foreign_Int32,foreign_Int32):
                            dr = (*(double(*)(int32_t,int32_t))f)(i32a[0],i32a[1]);
                            return make_boxfloat(dr, TYPE_DOUBLE_FLOAT);
                        case A2(foreign_Int32,foreign_Int64):
                            dr = (*(double(*)(int32_t,int64_t))f)(i32a[0],i64a[1]);
                            return make_boxfloat(dr, TYPE_DOUBLE_FLOAT);
                        case A2(foreign_Int32,foreign_Double):
                            dr = (*(double(*)(int32_t,double))f)(i32a[0],da[1]);
                            return make_boxfloat(dr, TYPE_DOUBLE_FLOAT);
                        case A2(foreign_Int64,foreign_Int32):
                            dr = (*(double(*)(int64_t,int32_t))f)(i64a[0],i32a[1]);
                            return make_boxfloat(dr, TYPE_DOUBLE_FLOAT);
                        case A2(foreign_Int64,foreign_Int64):
                            dr = (*(double(*)(int64_t,int64_t))f)(i64a[0],i64a[1]);
                            return make_boxfloat(dr, TYPE_DOUBLE_FLOAT);
                        case A2(foreign_Int64,foreign_Double):
                            dr = (*(double(*)(int64_t,double))f)(i64a[0],da[1]);
                            return make_boxfloat(dr, TYPE_DOUBLE_FLOAT);
                        case A2(foreign_Double,foreign_Int32):
                            dr = (*(double(*)(double,int32_t))f)(da[0],i32a[1]);
                            return make_boxfloat(dr, TYPE_DOUBLE_FLOAT);
                        case A2(foreign_Double,foreign_Int64):
                            dr = (*(double(*)(double,int64_t))f)(da[0],i64a[1]);
                            return make_boxfloat(dr, TYPE_DOUBLE_FLOAT);
                        case A2(foreign_Double,foreign_Double):
                            dr = (*(double(*)(double,double))f)(da[0],da[1]);
                            return make_boxfloat(dr, TYPE_DOUBLE_FLOAT);
                        default:
                            break;
                    }
                case 3:
                    switch (signature)
                    {   case A3(foreign_Int32,foreign_Int32,foreign_Int32):
                            dr = (*(double(*)(int32_t,int32_t,int32_t))f)(i32a[0],i32a[1],i32a[2]);
                            return make_boxfloat(dr, TYPE_DOUBLE_FLOAT);
                        case A3(foreign_Int32,foreign_Int32,foreign_Int64):
                            dr = (*(double(*)(int32_t,int32_t,int64_t))f)(i32a[0],i32a[1],i64a[2]);
                            return make_boxfloat(dr, TYPE_DOUBLE_FLOAT);
                        case A3(foreign_Int32,foreign_Int32,foreign_Double):
                            dr = (*(double(*)(int32_t,int32_t,double))f)(i32a[0],i32a[1],da[2]);
                            return make_boxfloat(dr, TYPE_DOUBLE_FLOAT);
                        case A3(foreign_Int32,foreign_Int64,foreign_Int32):
                            dr = (*(double(*)(int32_t,int64_t,int32_t))f)(i32a[0],i64a[1],i32a[2]);
                            return make_boxfloat(dr, TYPE_DOUBLE_FLOAT);
                        case A3(foreign_Int32,foreign_Int64,foreign_Int64):
                            dr = (*(double(*)(int32_t,int64_t,int64_t))f)(i32a[0],i64a[1],i32a[2]);
                            return make_boxfloat(dr, TYPE_DOUBLE_FLOAT);
                        case A3(foreign_Int32,foreign_Int64,foreign_Double):
                            dr = (*(double(*)(int32_t,int64_t,int32_t))f)(i32a[0],i64a[1],da[2]);
                            return make_boxfloat(dr, TYPE_DOUBLE_FLOAT);
                        case A3(foreign_Int32,foreign_Double,foreign_Int32):
                            dr = (*(double(*)(int32_t,double,int32_t))f)(i32a[0],da[1],i32a[2]);
                            return make_boxfloat(dr, TYPE_DOUBLE_FLOAT);
                        case A3(foreign_Int32,foreign_Double,foreign_Int64):
                            dr = (*(double(*)(int32_t,double,int64_t))f)(i32a[0],da[1],i32a[2]);
                            return make_boxfloat(dr, TYPE_DOUBLE_FLOAT);
                        case A3(foreign_Int32,foreign_Double,foreign_Double):
                            dr = (*(double(*)(int32_t,double,int32_t))f)(i32a[0],da[1],da[2]);
                            return make_boxfloat(dr, TYPE_DOUBLE_FLOAT);

                        case A3(foreign_Int64,foreign_Int32,foreign_Int32):
                            dr = (*(double(*)(int64_t,int32_t,int32_t))f)(i64a[0],i32a[1],i32a[2]);
                            return make_boxfloat(dr, TYPE_DOUBLE_FLOAT);
                        case A3(foreign_Int64,foreign_Int32,foreign_Int64):
                            dr = (*(double(*)(int64_t,int32_t,int64_t))f)(i64a[0],i32a[1],i64a[2]);
                            return make_boxfloat(dr, TYPE_DOUBLE_FLOAT);
                        case A3(foreign_Int64,foreign_Int32,foreign_Double):
                            dr = (*(double(*)(int64_t,int32_t,double))f)(i64a[0],i32a[1],da[2]);
                            return make_boxfloat(dr, TYPE_DOUBLE_FLOAT);
                        case A3(foreign_Int64,foreign_Int64,foreign_Int32):
                            dr = (*(double(*)(int64_t,int64_t,int32_t))f)(i64a[0],i64a[1],i32a[2]);
                            return make_boxfloat(dr, TYPE_DOUBLE_FLOAT);
                        case A3(foreign_Int64,foreign_Int64,foreign_Int64):
                            dr = (*(double(*)(int64_t,int64_t,int64_t))f)(i64a[0],i64a[1],i64a[2]);
                            return make_boxfloat(dr, TYPE_DOUBLE_FLOAT);
                        case A3(foreign_Int64,foreign_Int64,foreign_Double):
                            dr = (*(double(*)(int64_t,int64_t,double))f)(i64a[0],i64a[1],da[2]);
                            return make_boxfloat(dr, TYPE_DOUBLE_FLOAT);
                        case A3(foreign_Int64,foreign_Double,foreign_Int32):
                            dr = (*(double(*)(int64_t,double,int32_t))f)(i64a[0],da[1],i32a[2]);
                            return make_boxfloat(dr, TYPE_DOUBLE_FLOAT);
                        case A3(foreign_Int64,foreign_Double,foreign_Int64):
                            dr = (*(double(*)(int64_t,double,int64_t))f)(i64a[0],da[1],i64a[2]);
                            return make_boxfloat(dr, TYPE_DOUBLE_FLOAT);
                        case A3(foreign_Int64,foreign_Double,foreign_Double):
                            dr = (*(double(*)(int64_t,double,double))f)(i64a[0],da[1],da[2]);
                            return make_boxfloat(dr, TYPE_DOUBLE_FLOAT);

                        case A3(foreign_Double,foreign_Int32,foreign_Int32):
                            dr = (*(double(*)(double,int32_t,int32_t))f)(da[0],i32a[1],i32a[2]);
                            return make_boxfloat(dr, TYPE_DOUBLE_FLOAT);
                        case A3(foreign_Double,foreign_Int32,foreign_Int64):
                            dr = (*(double(*)(double,int32_t,int64_t))f)(da[0],i32a[1],i64a[2]);
                            return make_boxfloat(dr, TYPE_DOUBLE_FLOAT);
                        case A3(foreign_Double,foreign_Int32,foreign_Double):
                            dr = (*(double(*)(double,int32_t,double))f)(da[0],i32a[1],da[2]);
                            return make_boxfloat(dr, TYPE_DOUBLE_FLOAT);
                        case A3(foreign_Double,foreign_Int64,foreign_Int32):
                            dr = (*(double(*)(double,int64_t,int32_t))f)(da[0],i64a[1],i32a[2]);
                            return make_boxfloat(dr, TYPE_DOUBLE_FLOAT);
                        case A3(foreign_Double,foreign_Int64,foreign_Int64):
                            dr = (*(double(*)(double,int64_t,int64_t))f)(da[0],i64a[1],i64a[2]);
                            return make_boxfloat(dr, TYPE_DOUBLE_FLOAT);
                        case A3(foreign_Double,foreign_Int64,foreign_Double):
                            dr = (*(double(*)(double,int64_t,double))f)(da[0],i64a[1],da[2]);
                            return make_boxfloat(dr, TYPE_DOUBLE_FLOAT);
                        case A3(foreign_Double,foreign_Double,foreign_Int32):
                            dr = (*(double(*)(double,double,int32_t))f)(da[0],da[1],i32a[2]);
                            return make_boxfloat(dr, TYPE_DOUBLE_FLOAT);
                        case A3(foreign_Double,foreign_Double,foreign_Int64):
                            dr = (*(double(*)(double,double,int64_t))f)(da[0],da[1],i64a[2]);
                            return make_boxfloat(dr, TYPE_DOUBLE_FLOAT);
                        case A3(foreign_Double,foreign_Double,foreign_Double):
                            dr = (*(double(*)(double,double,double))f)(da[0],da[1],da[2]);
                            return make_boxfloat(dr, TYPE_DOUBLE_FLOAT);
                        default:
                            break;
                    }
                    break;
            }
            break;
        default:
            break;
    }
    aerror("Too many arguments for foreign function");
}

//
// For things with type-signatures involving "..." the only case I will
// support at present is "int f(const char *s,...)" which is of course the
// signature of printf. I will permit three arguments beyond the "char *" one.
//

LispObject callforeignvarargs(void *f, int returntype, int nargs, int signature)
{   const char *s;
    if (sizeof(const char *)==4) s = (const char *)(intptr_t)i32a[0];
    else s = (const char *)(intptr_t)i64a[0];
    switch (nargs)
    {   case 0:
            i32r = (*(int32_t(*)(const char *s,...))f)(s);
            return make_lisp_integer32(i32r);
        case 1:
            switch (signature)
            {   case A1(foreign_Int32):
                    i32r = (*(int32_t(*)(const char *s,...))f)(s,i32a[1]);
                    return make_lisp_integer32(i32r);
                case A1(foreign_Int64):
                    i32r = (*(int32_t(*)(const char *s,...))f)(s,i64a[1]);
                    return make_lisp_integer32(i32r);
                case A1(foreign_Double):
                    i32r = (*(int32_t(*)(const char *s,...))f)(s,da[1]);
                    return make_lisp_integer32(i32r);
                default:
                    break;
            }
        case 2:
            switch (signature)
            {   case A2(foreign_Int32,foreign_Int32):
                    i32r = (*(int32_t(*)(const char *s,...))f)(s,i32a[1],i32a[2]);
                    return make_lisp_integer32(i32r);
                case A2(foreign_Int32,foreign_Int64):
                    i32r = (*(int32_t(*)(const char *s,...))f)(s,i32a[1],i64a[2]);
                    return make_lisp_integer32(i32r);
                case A2(foreign_Int32,foreign_Double):
                    i32r = (*(int32_t(*)(const char *s,...))f)(s,i32a[1],da[2]);
                    return make_lisp_integer32(i32r);
                case A2(foreign_Int64,foreign_Int32):
                    i32r = (*(int32_t(*)(const char *s,...))f)(s,i64a[1],i32a[2]);
                    return make_lisp_integer32(i32r);
                case A2(foreign_Int64,foreign_Int64):
                    i32r = (*(int32_t(*)(const char *s,...))f)(s,i64a[1],i64a[2]);
                    return make_lisp_integer32(i32r);
                case A2(foreign_Int64,foreign_Double):
                    i32r = (*(int32_t(*)(const char *s,...))f)(s,i64a[1],da[2]);
                    return make_lisp_integer32(i32r);
                case A2(foreign_Double,foreign_Int32):
                    i32r = (*(int32_t(*)(const char *s,...))f)(s,da[1],i32a[2]);
                    return make_lisp_integer32(i32r);
                case A2(foreign_Double,foreign_Int64):
                    i32r = (*(int32_t(*)(const char *s,...))f)(s,da[1],i64a[2]);
                    return make_lisp_integer32(i32r);
                case A2(foreign_Double,foreign_Double):
                    i32r = (*(int32_t(*)(const char *s,...))f)(s,da[1],da[2]);
                    return make_lisp_integer32(i32r);
                default:
                    break;
            }
        case 3:
            switch (signature)
            {   case A3(foreign_Int32,foreign_Int32,foreign_Int32):
                    i32r = (*(int32_t(*)(const char *s,...))f)(s,i32a[1],i32a[2],i32a[3]);
                    return make_lisp_integer32(i32r);
                case A3(foreign_Int32,foreign_Int32,foreign_Int64):
                    i32r = (*(int32_t(*)(const char *s,...))f)(s,i32a[1],i32a[2],i64a[3]);
                    return make_lisp_integer32(i32r);
                case A3(foreign_Int32,foreign_Int32,foreign_Double):
                    i32r = (*(int32_t(*)(const char *s,...))f)(s,i32a[1],i32a[2],da[3]);
                    return make_lisp_integer32(i32r);
                case A3(foreign_Int32,foreign_Int64,foreign_Int32):
                    i32r = (*(int32_t(*)(const char *s,...))f)(s,i32a[1],i64a[2],i32a[3]);
                    return make_lisp_integer32(i32r);
                case A3(foreign_Int32,foreign_Int64,foreign_Int64):
                    i32r = (*(int32_t(*)(const char *s,...))f)(s,i32a[1],i64a[2],i32a[3]);
                    return make_lisp_integer32(i32r);
                case A3(foreign_Int32,foreign_Int64,foreign_Double):
                    i32r = (*(int32_t(*)(const char *s,...))f)(s,i32a[1],i64a[2],da[3]);
                    return make_lisp_integer32(i32r);
                case A3(foreign_Int32,foreign_Double,foreign_Int32):
                    i32r = (*(int32_t(*)(const char *s,...))f)(s,i32a[1],da[2],i32a[3]);
                    return make_lisp_integer32(i32r);
                case A3(foreign_Int32,foreign_Double,foreign_Int64):
                    i32r = (*(int32_t(*)(const char *s,...))f)(s,i32a[1],da[2],i32a[3]);
                    return make_lisp_integer32(i32r);
                case A3(foreign_Int32,foreign_Double,foreign_Double):
                    i32r = (*(int32_t(*)(const char *s,...))f)(s,i32a[1],da[2],da[3]);
                    return make_lisp_integer32(i32r);

                case A3(foreign_Int64,foreign_Int32,foreign_Int32):
                    i32r = (*(int32_t(*)(const char *s,...))f)(s,i64a[1],i32a[2],i32a[3]);
                    return make_lisp_integer32(i32r);
                case A3(foreign_Int64,foreign_Int32,foreign_Int64):
                    i32r = (*(int32_t(*)(const char *s,...))f)(s,i64a[1],i32a[2],i64a[3]);
                    return make_lisp_integer32(i32r);
                case A3(foreign_Int64,foreign_Int32,foreign_Double):
                    i32r = (*(int32_t(*)(const char *s,...))f)(s,i64a[1],i32a[2],da[3]);
                    return make_lisp_integer32(i32r);
                case A3(foreign_Int64,foreign_Int64,foreign_Int32):
                    i32r = (*(int32_t(*)(const char *s,...))f)(s,i64a[1],i64a[2],i32a[3]);
                    return make_lisp_integer32(i32r);
                case A3(foreign_Int64,foreign_Int64,foreign_Int64):
                    i32r = (*(int32_t(*)(const char *s,...))f)(s,i64a[1],i64a[2],i64a[3]);
                    return make_lisp_integer32(i32r);
                case A3(foreign_Int64,foreign_Int64,foreign_Double):
                    i32r = (*(int32_t(*)(const char *s,...))f)(s,i64a[1],i64a[2],da[3]);
                    return make_lisp_integer32(i32r);
                case A3(foreign_Int64,foreign_Double,foreign_Int32):
                    i32r = (*(int32_t(*)(const char *s,...))f)(s,i64a[1],da[2],i32a[3]);
                    return make_lisp_integer32(i32r);
                case A3(foreign_Int64,foreign_Double,foreign_Int64):
                    i32r = (*(int32_t(*)(const char *s,...))f)(s,i64a[1],da[2],i64a[3]);
                    return make_lisp_integer32(i32r);
                case A3(foreign_Int64,foreign_Double,foreign_Double):
                    i32r = (*(int32_t(*)(const char *s,...))f)(s,i64a[1],da[2],da[3]);
                    return make_lisp_integer32(i32r);

                case A3(foreign_Double,foreign_Int32,foreign_Int32):
                    i32r = (*(int32_t(*)(const char *s,...))f)(s,da[1],i32a[2],i32a[3]);
                    return make_lisp_integer32(i32r);
                case A3(foreign_Double,foreign_Int32,foreign_Int64):
                    i32r = (*(int32_t(*)(const char *s,...))f)(s,da[1],i32a[2],i64a[3]);
                    return make_lisp_integer32(i32r);
                case A3(foreign_Double,foreign_Int32,foreign_Double):
                    i32r = (*(int32_t(*)(const char *s,...))f)(s,da[1],i32a[2],da[3]);
                    return make_lisp_integer32(i32r);
                case A3(foreign_Double,foreign_Int64,foreign_Int32):
                    i32r = (*(int32_t(*)(const char *s,...))f)(s,da[1],i64a[2],i32a[3]);
                    return make_lisp_integer32(i32r);
                case A3(foreign_Double,foreign_Int64,foreign_Int64):
                    i32r = (*(int32_t(*)(const char *s,...))f)(s,da[1],i64a[2],i64a[3]);
                    return make_lisp_integer32(i32r);
                case A3(foreign_Double,foreign_Int64,foreign_Double):
                    i32r = (*(int32_t(*)(const char *s,...))f)(s,da[1],i64a[2],da[3]);
                    return make_lisp_integer32(i32r);
                case A3(foreign_Double,foreign_Double,foreign_Int32):
                    i32r = (*(int32_t(*)(const char *s,...))f)(s,da[1],da[2],i32a[3]);
                    return make_lisp_integer32(i32r);
                case A3(foreign_Double,foreign_Double,foreign_Int64):
                    i32r = (*(int32_t(*)(const char *s,...))f)(s,da[1],da[2],i64a[3]);
                    return make_lisp_integer32(i32r);
                case A3(foreign_Double,foreign_Double,foreign_Double):
                    i32r = (*(int32_t(*)(const char *s,...))f)(s,da[1],da[2],da[3]);
                    return make_lisp_integer32(i32r);
                default:
                    break;
            }
            break;
    }
    aerror("Too many arguments for foreign varargs function");
}

//
// The general scheme for call-foreign-function is as follows, where the
// key issue is that of the types of data passed and returned...
//
//    (call-foreign-function f)    call f with no args, ignoring any result
//    (call-foreign-function f a1)
//    (call-foreign-function f a1 a2)
//    (call-foreign-function f a1 a2 a3)
//    etc
// Each argument can be one of the following:
//    A symbol, where int32, int64, int, long, longlong, intptr and size
//    are the useful values. This specifies the way in which the next
//    argument (which should be an integer) will be passed. If there is no
//    further argument then the name can also possibly be void, string
//    or double and it indicates a return type.
//
//    An integer. This is passed as the next argument to the function
//    as a 32-bit integer unless a type was specified by the previous symbol.
//    A double-precision float. Passed to the function as the next argument.
//
//    A string. A C string is passed to the function. There will be a
//    limit on the length of string that can be passed this way.
//
//    A pair (sym . val) where sym can be one of
//        int int32 long int64 longlong intptr size string double
//    and val is something that can be mapped onto the matching type. The
//    purpose of this is so that whether an integer passed this way will be
//    32 or 64-bit can depend on the nature of the host system.
//
// The foreign function may only be provided with 0, 1, 2 or 3 arguments.
// At some stage I may need to find a way to be able to call functions that
// use va_arg style argument passing. But that is not worked out or
// implemented yet.
//

int dumparg(int i, LispObject type, LispObject value)
{   int typecode;
    size_t len = 0;
    const char *w = get_string_data(type, "call-foreign-function", len);
    if (len==5 && strncmp(w, "int32", 5)==0)
    {   i32a[i] = thirty_two_bits(value);
        typecode = foreign_Int32;
    }
    else if (len==3 && strncmp(w, "int", 3)==0)
    {   i32a[i] = thirty_two_bits(value);
        typecode = foreign_Int32;
    }
    else if (len==5 && strncmp(w, "int64", 5)==0)
    {   i64a[i] = sixty_four_bits(value);
        typecode = foreign_Int64;
    }
    else if (len==4 && strncmp(w, "long", 4)==0)
    {   if (sizeof(long)==4)
        {   i32a[i] = thirty_two_bits(value);
            typecode = foreign_Int32;
        }
        else
        {   i64a[i] = sixty_four_bits(value);
            typecode = foreign_Int64;
        }
    }
    else if (len==8 && strncmp(w, "longlong", 8)==0)
    {   i64a[i] = sixty_four_bits(value);
        typecode = foreign_Int64;
    }
    else if (len==4 && strncmp(w, "size", 4)==0)
    {   if (sizeof(size_t)==4)
        {   i32a[i] = thirty_two_bits(value);
            typecode = foreign_Int32;
        }
        else
        {   i64a[i] = sixty_four_bits(value);
            typecode = foreign_Int64;
        }
    }
    else if (len==6 && strncmp(w, "intptr", 6)==0)
    {   if (sizeof(intptr_t)==4)
        {   i32a[i] = thirty_two_bits(value);
            typecode = foreign_Int32;
        }
        else
        {   i64a[i] = sixty_four_bits(value);
            typecode = foreign_Int64;
        }
    }
    else if (len==6 && strncmp(w, "double", 6)==0)
    {   da[i] = float_of_number(value);
        typecode = foreign_Double;
    }
    else if (len==6 && strncmp(w, "string", 6)==0)
    {   w = get_string_data(value, "call-foreign-function", len);
        memcpy(&sa[i][0], w, len);
        sa[i][len] = 0;
        if (sizeof(char *)==4)
        {   i32a[i] = (int32_t)(intptr_t)&sa[i][0];
            typecode = foreign_Int32;
        }
        else
        {   i64a[i] = (int64_t)(intptr_t)&sa[i][0];
            typecode = foreign_Int64;
        }
    }
    else
    {   i32a[i] = 0;
        typecode = foreign_Int32;
    }
    return typecode << (2*i);
}

LispObject Lcallfn(LispObject env, int nargs, ...)
{   int i;
    LispObject w;
    void *f;
    int resulttype = foreign_Void, rtype, typemap = 0;
    LispObject currenttype = nil;
    va_list aa;
    for (i=0; i<MAX_ARGCOUNT; i++)
    {   i32a[i] = 0;
        i64a[i] = 0;
        da[i] = 0.0;
    }
    i = 0;  // Where to put next argument
    va_start(aa, nargs);
    w = va_arg(aa, LispObject);
    nargs--;
    if (Lencapsulatedp(nil, w) == nil)
        aerror("call-foreign-function");
    f = extract_pointer(w);
    while (nargs > 0)
    {   nargs--;
        w = va_arg(aa, LispObject);
        if (is_cons(w))
        {   typemap |= dumparg(i, qcar(w), qcdr(w));
            i++;
            currenttype = nil;
        }
        else if (is_symbol(w))
        {   currenttype = w;
        }
        else if (is_fixnum(w) || is_numbers(w) ||
                 is_bfloat(w) || stringp(w))
        {   typemap |= dumparg(i, currenttype, w);
            i++;
            currenttype = nil;
        }
        else aerror1("call-foreign-function", w);
    }
    va_end(aa);
//
// Now I need to call (*f)
//
    resulttype = foreign_Void;
    if (currenttype != nil)
    {   if (name_matches(currenttype, "int32")) resulttype = foreign_Int32;
        else if (name_matches(currenttype, "int64")) resulttype = foreign_Int64;
        else if (name_matches(currenttype, "int")) resulttype = foreign_Int32;
        else if (name_matches(currenttype, "long")) resulttype = sizeof(long)==4 ? foreign_Int32 : foreign_Int64;
        else if (name_matches(currenttype, "longlong")) resulttype = foreign_Int64;
        else if (name_matches(currenttype, "size")) resulttype = sizeof(size_t)==4 ? foreign_Int32 : foreign_Int64;
        else if (name_matches(currenttype, "intptr")) resulttype = sizeof(void *)==4 ? foreign_Int32 : foreign_Int64;
        else if (name_matches(currenttype, "double")) resulttype = foreign_Double;
        else if (name_matches(currenttype, "string")) resulttype = foreign_String;
        else if (name_matches(currenttype, "void")) resulttype = foreign_Void;
        else aerror1("call-foreign-function", currenttype);
    }
    rtype = (resulttype == foreign_String) ? (sizeof(void *)==4 ? foreign_Int32 : foreign_Int64) :
            resulttype;
    w = callforeign(f, rtype, i, typemap);
    if (resulttype == foreign_String)
    {   char *s = (char *)(intptr_t)sixty_four_bits(w);
        w = make_string(s);
    }
    return onevalue(w);
}

LispObject Lcallf2(LispObject env, LispObject entry, LispObject arg)
{   return Lcallfn(env, 2, entry, arg);;
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

setup_type const funcs1_setup[] =
{   {"acons",                   WRONG_NO_NA, WRONG_NO_NB, Lacons},
    {"atom",                    Latom, TOO_MANY_1, WRONG_NO_1},
    {"boundp",                  Lboundp, TOO_MANY_1, WRONG_NO_1},

    {"car",                     Lcar, TOO_MANY_1, WRONG_NO_1},
    {"car*",                    Lcar_star, TOO_MANY_1, WRONG_NO_1},
    {"cdr",                     Lcdr, TOO_MANY_1, WRONG_NO_1},
    {"caar",                    Lcaar, TOO_MANY_1, WRONG_NO_1},
    {"cadr",                    Lcadr, TOO_MANY_1, WRONG_NO_1},
    {"cdar",                    Lcdar, TOO_MANY_1, WRONG_NO_1},
    {"cddr",                    Lcddr, TOO_MANY_1, WRONG_NO_1},
    {"caaar",                   Lcaaar, TOO_MANY_1, WRONG_NO_1},
    {"caadr",                   Lcaadr, TOO_MANY_1, WRONG_NO_1},
    {"cadar",                   Lcadar, TOO_MANY_1, WRONG_NO_1},
    {"caddr",                   Lcaddr, TOO_MANY_1, WRONG_NO_1},
    {"cdaar",                   Lcdaar, TOO_MANY_1, WRONG_NO_1},
    {"cdadr",                   Lcdadr, TOO_MANY_1, WRONG_NO_1},
    {"cddar",                   Lcddar, TOO_MANY_1, WRONG_NO_1},
    {"cdddr",                   Lcdddr, TOO_MANY_1, WRONG_NO_1},
    {"caaaar",                  Lcaaaar, TOO_MANY_1, WRONG_NO_1},
    {"caaadr",                  Lcaaadr, TOO_MANY_1, WRONG_NO_1},
    {"caadar",                  Lcaadar, TOO_MANY_1, WRONG_NO_1},
    {"caaddr",                  Lcaaddr, TOO_MANY_1, WRONG_NO_1},
    {"cadaar",                  Lcadaar, TOO_MANY_1, WRONG_NO_1},
    {"cadadr",                  Lcadadr, TOO_MANY_1, WRONG_NO_1},
    {"caddar",                  Lcaddar, TOO_MANY_1, WRONG_NO_1},
    {"cadddr",                  Lcadddr, TOO_MANY_1, WRONG_NO_1},
    {"cdaaar",                  Lcdaaar, TOO_MANY_1, WRONG_NO_1},
    {"cdaadr",                  Lcdaadr, TOO_MANY_1, WRONG_NO_1},
    {"cdadar",                  Lcdadar, TOO_MANY_1, WRONG_NO_1},
    {"cdaddr",                  Lcdaddr, TOO_MANY_1, WRONG_NO_1},
    {"cddaar",                  Lcddaar, TOO_MANY_1, WRONG_NO_1},
    {"cddadr",                  Lcddadr, TOO_MANY_1, WRONG_NO_1},
    {"cdddar",                  Lcdddar, TOO_MANY_1, WRONG_NO_1},
    {"cddddr",                  Lcddddr, TOO_MANY_1, WRONG_NO_1},

    {"qcar",                    Lcar, TOO_MANY_1, WRONG_NO_1},
    {"qcdr",                    Lcdr, TOO_MANY_1, WRONG_NO_1},
    {"qcaar",                   Lcaar, TOO_MANY_1, WRONG_NO_1},
    {"qcadr",                   Lcadr, TOO_MANY_1, WRONG_NO_1},
    {"qcdar",                   Lcdar, TOO_MANY_1, WRONG_NO_1},
    {"qcddr",                   Lcddr, TOO_MANY_1, WRONG_NO_1},

    {"bpsp",                    Lbpsp, TOO_MANY_1, WRONG_NO_1},
    {"codep",                   Lcodep, TOO_MANY_1, WRONG_NO_1},
    {"cons",                    TOO_FEW_2, Lcons, WRONG_NO_2},
    {"constantp",               Lconstantp, TOO_MANY_1, WRONG_NO_1},
    {"date",                    Ldate1, WRONG_NO_NB, Ldate},
    {"date-and-time",           Ldate_and_time1, WRONG_NO_NB, Ldate_and_time},
    {"datestamp",               WRONG_NO_NA, WRONG_NO_NB, Ldatestamp},
    {"timeofday",               WRONG_NO_NA, WRONG_NO_NB, Ltimeofday},
    {"enable-errorset",         TOO_FEW_2, Lenable_errorset, WRONG_NO_2},
    {"enable-backtrace",        Lenable_backtrace, TOO_MANY_1, WRONG_NO_1},
    {"error",                   (one_args *)Lerror1, (two_args *)Lerror2, (n_args *)Lerror},
    {"error1",                  WRONG_NO_NA, WRONG_NO_NB, (n_args *)Lerror0},
#ifdef NAG
    {"unwind",                  WRONG_NO_NA, WRONG_NO_NB, Lunwind},
#endif
    {"eq-safe",                 Leq_safe, TOO_MANY_1, WRONG_NO_1},
    {"fixp",                    Lfixp, TOO_MANY_1, WRONG_NO_1},
    {"floatp",                  Lfloatp, TOO_MANY_1, WRONG_NO_1},
    {"fluidp",                  Lsymbol_specialp, TOO_MANY_1, WRONG_NO_1},
    {"gctime",                  WRONG_NO_NA, WRONG_NO_NB, Lgctime},
    {"globalp",                 Lsymbol_globalp, TOO_MANY_1, WRONG_NO_1},
    {"hash-table-p",            Lhash_table_p, TOO_MANY_1, WRONG_NO_1},
    {"indirect",                Lindirect, TOO_MANY_1, WRONG_NO_1},
    {"integerp",                Lintegerp, TOO_MANY_1, WRONG_NO_1},
    {"intersection",            TOO_FEW_2, Lintersect, WRONG_NO_2},
    {"intersection_symlist",    TOO_FEW_2, Lintersect_symlist, WRONG_NO_2},
    {"keywordp",                Lsymbol_keywordp, TOO_MANY_1, WRONG_NO_1},
    {"list2",                   TOO_FEW_2, Llist2, WRONG_NO_2},
    {"list2*",                  WRONG_NO_NA, WRONG_NO_NB, Llist2star},
    {"list3",                   WRONG_NO_NA, WRONG_NO_NB, Llist3},
    {"list3*",                  WRONG_NO_NA, WRONG_NO_NB, Llist3star},
    {"list4",                   WRONG_NO_NA, WRONG_NO_NB, Llist4},
    {"make-global",             Lmake_global, TOO_MANY_1, WRONG_NO_1},
    {"make-keyword",            Lmake_keyword, TOO_MANY_1, WRONG_NO_1},
    {"make-special",            Lmake_special, TOO_MANY_1, WRONG_NO_1},
    {"mkquote",                 Lmkquote, TOO_MANY_1, WRONG_NO_1},
    {"ncons",                   Lncons, TOO_MANY_1, WRONG_NO_1},
    {"numberp",                 Lnumberp, TOO_MANY_1, WRONG_NO_1},
    {"pair",                    TOO_FEW_2, Lpair, WRONG_NO_2},
    {"protect-symbols",     Lprotect_symbols, TOO_MANY_1, WRONG_NO_1},
    {"protected-symbol-warn",   Lwarn_about_protected_symbols, TOO_MANY_1, WRONG_NO_1},
    {"put",                     WRONG_NO_NA, WRONG_NO_NB, Lputprop},
    {"remprop",                 TOO_FEW_2, Lremprop, WRONG_NO_2},
    {"representation",          Lrepresentation1, Lrepresentation2, WRONG_NO_2},
    {"rplaca",                  TOO_FEW_2, Lrplaca, WRONG_NO_2},
    {"rplacd",                  TOO_FEW_2, Lrplacd, WRONG_NO_2},
    {"set",                     TOO_FEW_2, Lset, WRONG_NO_2},
    {"makeunbound",             Lmakeunbound, TOO_MANY_1, WRONG_NO_1},
    {"special-form-p",          Lspecial_form_p, TOO_MANY_1, WRONG_NO_1},
    {"stop",                    (one_args *)Lstop, (two_args *)Lstop2, (n_args *)Lstop0},
    {"symbol-function",         Lsymbol_function, TOO_MANY_1, WRONG_NO_1},
    {"symbol-value",            Lsymbol_value, TOO_MANY_1, WRONG_NO_1},
    {"time",                    WRONG_NO_NA, WRONG_NO_NB, Ltime},
    {"datelessp",               TOO_FEW_2, Ldatelessp, WRONG_NO_2},
    {"union",                   TOO_FEW_2, Lunion, WRONG_NO_2},
    {"union-symlist",           TOO_FEW_2, Lunion_symlist, WRONG_NO_2},
    {"unmake-global",           Lunmake_global, TOO_MANY_1, WRONG_NO_1},
    {"unmake-keyword",          Lunmake_keyword, TOO_MANY_1, WRONG_NO_1},
    {"unmake-special",          Lunmake_special, TOO_MANY_1, WRONG_NO_1},
    {"xcons",                   TOO_FEW_2, Lxcons, WRONG_NO_2},
// I provide both IDP and SYMBOLP in both modes...
    {"symbolp",                 Lsymbolp, TOO_MANY_1, WRONG_NO_1},
    {"idp",                     Lsymbolp, TOO_MANY_1, WRONG_NO_1},
// I support the Common Lisp names here in both modes
    {"simple-string-p",         Lstringp, TOO_MANY_1, WRONG_NO_1},
    {"simple-vector-p",         Lsimple_vectorp, TOO_MANY_1, WRONG_NO_1},
    {"get-decoded-time",        WRONG_NO_0A, WRONG_NO_0B, Ldecoded_time},
    {"short-floatp",            Lshort_floatp, TOO_MANY_1, WRONG_NO_1},
    {"single-floatp",           Lsingle_floatp, TOO_MANY_1, WRONG_NO_1},
    {"double-floatp",           Ldouble_floatp, TOO_MANY_1, WRONG_NO_1},
    {"long-floatp",             Llong_floatp, TOO_MANY_1, WRONG_NO_1},
    {"rationalp",               Lrationalp, TOO_MANY_1, WRONG_NO_1},
    {"complexp",                Lcomplexp, TOO_MANY_1, WRONG_NO_1},
    {"bit-vector-p",            Lsimple_bit_vector_p, TOO_MANY_1, WRONG_NO_1},
    {"simple-bit-vector-p",     Lsimple_bit_vector_p, TOO_MANY_1, WRONG_NO_1},
    {"fill-vector",             WRONG_NO_NA, WRONG_NO_NB, Lfill_vector},
    {"get",                     TOO_FEW_2, Lget, Lget_3},
    {"arrayp",                  Larrayp, TOO_MANY_1, WRONG_NO_1},
    {"complex-arrayp",          Lcomplex_arrayp, TOO_MANY_1, WRONG_NO_1},
    {"consp",                   Lconsp, TOO_MANY_1, WRONG_NO_1},
    {"convert-to-array",        Lconvert_to_array, TOO_MANY_1, WRONG_NO_1},
    {"convert-to-struct",       Lconvert_to_struct, TOO_MANY_1, WRONG_NO_1},
    {"identity",                Lidentity, TOO_MANY_1, WRONG_NO_1},
    {"list",                    Lncons, Llist2, Llist},
    {"list*",                   Lidentity, Lcons, Lliststar},
    {"listp",                   Llistp, TOO_MANY_1, WRONG_NO_1},
//  {"stringp",                 Lc_stringp, TOO_MANY_1, WRONG_NO_1},
    {"structp",                 Lstructp, TOO_MANY_1, WRONG_NO_1},
    {"flag",                    TOO_FEW_2, Lflag, WRONG_NO_2},
    {"flagp",                   TOO_FEW_2, Lflagp, WRONG_NO_2},
    {"flagpcar",                TOO_FEW_2, Lflagpcar, WRONG_NO_2},
    {"remflag",                 TOO_FEW_2, Lremflag, WRONG_NO_2},
    {"time*",                   WRONG_NO_NA, WRONG_NO_NB, Ltime},
    {"convert-to-evector",      Lconvert_to_struct, TOO_MANY_1, WRONG_NO_1},
    {"evectorp",                Lstructp, TOO_MANY_1, WRONG_NO_1},
    {"get*",                    TOO_FEW_2, Lget, WRONG_NO_2},
    {"pairp",                   Lconsp, TOO_MANY_1, WRONG_NO_1},
    {"consp",                   Lconsp, TOO_MANY_1, WRONG_NO_1},
    {"flagp**",                 TOO_FEW_2, Lflagp, WRONG_NO_2},
    {"stringp",                 Lstringp, TOO_MANY_1, WRONG_NO_1},
    {"threevectorp",            Lthreevectorp, TOO_MANY_1, WRONG_NO_1},
//  {"throw",                   Lthrow_nil, Lthrow_one_value, WRONG_NO_2},
    {"vectorp",                 Lsimple_vectorp, TOO_MANY_1, WRONG_NO_1},
    {"open-foreign-library",    Lopen_foreign_library, TOO_MANY_1, WRONG_NO_1},
    {"find-foreign-function",   TOO_FEW_2, Lfind_foreign_function, WRONG_NO_2},
    {"call-foreign-function",   Lcallf1, Lcallf2, Lcallfn},
    {"get-callback",            Lget_callback, TOO_MANY_1, WRONG_NO_1},
    {NULL,                      0, 0, 0}
};

// end of fns1.cpp
