// validate.h                                   Copyright (C) 2022 Codemist

#ifndef header_validate_h
#define header_validate_h 1

// $Id$


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


// I now have some code intended for testing and debugging. A LispObject
// is a tagged value. If it is a pointer it must point into the right
// sort of Page and the first word that it refers to must be proper -
// for instance a value tagged as a vector must have a vector header there
// while something that should be a cons cell must not.

#include <unordered_set>
#include <stack>

INLINE_VAR std::unordered_set<LispObject> visited;
INLINE_VAR std::stack<LispObject> trail;
INLINE_VAR std::stack<intptr_t> state;

enum
{
    Xtop     = -1,
    Xcar     = -2,
    Xcdr     = -3,
    Xvalue   = -4,
    Xenv     = -5,
    Xplist   = -6,
    Xfastgets= -7,
    Xpackage = -8,
    Xpname   = -9,
    Xelt0    =  0,
    Xelt1    =  1,
    Xelt2    =  2   // etc!
};

inline void checkOldVsNew(LispObject x, bool oldSpaceValid)
{   if (!oldSpaceValid &&
        ((consOldPages.contains(pageOf(x)) &&
          !consIsPinned(x, pageOf(x)) &&
          !consIsNewPinned(x, pageOf(x))) ||
         (vecOldPages.contains(pageOf(x)) &&
          !vecIsPinned(x, pageOf(x)) &&
          !vecIsNewPinned(x, pageOf(x)))))
    {   zprintf("Bad reference to %a\n", x);
        simple_print(x);
        my_abort(where("reference into old half-space"));
    }
}

inline void checkCons(LispObject x, bool forwardOK)
{   Page* p = pageOf(x);
    my_assert(p->type == consPageType, where("cons pointer into vector page"));
    LispObject c = car(x);
    if (is_forward(c))
    {   if (!forwardOK)
        {   zprintf("\nCONS %a => %a\n", x, c);
            my_abort(where("illegal forwarding"));
        }
        x = (c & ~TAG_BITS) | (x & TAG_BITS);
        p = pageOf(x);
        my_assert(p->type == consPageType,
                  where("cons pointer forwards into vector page"));
        c = car(x);
        my_assert(!is_forward(c), where("double forward pointer"));
    }
    my_assert(!is_sym_or_vec_hdr(c), where("header in car(x)"));
    c = cdr(x);
    my_assert(!is_sym_or_vec_hdr(c), where("header in cdr(x)"));
}

inline void checkSymbol(LispObject x, bool forwardOK)
{   Page* p = pageOf(x);
    my_assert(p->type == vecPageType, where("symbol pointer into cons page"));
    LispObject c = qheader(x);
    if (is_forward(c))
    {   if (!forwardOK)
        {   zprintf("\nSYMBOL %a => %a\n", x, c);
            my_abort(where("left over forwarding pointer on symbol"));
        }
        x = (c & ~TAG_BITS) | (x & TAG_BITS);
        p = pageOf(x);
        my_assert(p->type == vecPageType,
                  where("symbol pointer forwards into cons page"));
        c = qheader(x);
        my_assert(!is_forward(c), where("double forward pointer"));
    }
    my_assert(is_symbol_header_full_test(c), where("symbol without header"));
    my_assert(!is_forward(qvalue(x)) &&
              !is_sym_or_vec_hdr(qvalue(x)), "bad qvalue");
    my_assert(!is_forward(qenv(x)) &&
              !is_sym_or_vec_hdr(qenv(x)), "bad qenv");
    my_assert(!is_forward(qplist(x)) &&
              !is_sym_or_vec_hdr(qplist(x)), "bad qplist");
    my_assert(!is_forward(qfastgets(x)) &&
              !is_sym_or_vec_hdr(qfastgets(x)), "bad qfastgets");
    my_assert(!is_forward(qpackage(x)) &&
              !is_sym_or_vec_hdr(qpackage(x)), "bad qpackage");
    my_assert(!is_forward(qpname(x)) &&
              !is_sym_or_vec_hdr(qpname(x)), "bad qpname");
}

inline void checkBoxfloat(LispObject x, bool forwardOK)
{   Page* p = pageOf(x);
    Page* p1 = p;
    LispObject c = flthdr(x);
    if (is_forward(c))
    {   if (!forwardOK)
        {   zprintf("\nBOXFLOAT %a => %a\n", x, c);
            my_abort(where("illegal forwarding"));
        }
        x = (c & ~TAG_BITS) | (x & TAG_BITS);
        p1 = pageOf(x);
        c = flthdr(x);
        my_assert(!is_forward(c), where("double forward pointer"));
    }
    my_assert(is_odds(c) && is_header(c), where("float needs a header"));
    switch (type_of_header(c))
    {
    case TYPE_SINGLE_FLOAT:
    case TYPE_LONG_FLOAT:
        my_assert(p->type == vecPageType, where("float in cons page"));
        my_assert(p1->type == vecPageType, where("float forwards into cons page"));
        break;
    case TYPE_DOUBLE_FLOAT:
        if (SIXTY_FOUR_BIT)
        {   my_assert(p->type == consPageType, where("double float in vector page"));
            my_assert(p1->type == consPageType, where("double float forwards into vector page"));
        }
        else
        {   my_assert(p->type == vecPageType, where("float in cons page"));
            my_assert(p1->type == vecPageType, where("float forwards into cons page"));
        }
        break;
    default:
        my_abort(where("float with bad header"));
    }        
}

inline void checkVector(LispObject x, bool forwardOK)
{   Page* p = pageOf(x);
    my_assert(p->type == vecPageType, where("vector in cons page"));
    LispObject c = car(x & ~TAG_BITS);
    if (is_forward(c))
    {   if (!forwardOK)
        {   zprintf("\nVEC %a => %a\n", x, c);
            my_abort(where("illegal forwarding"));
        }
        x = (c & ~TAG_BITS) | (x & TAG_BITS);
        p = pageOf(x);
        my_assert(p->type == vecPageType,
                      where("vector forwards into cons page"));
        c = car(x & ~TAG_BITS);
        if (is_forward(c))
            my_abort(where("double forward pointer"));
    }
    my_assert(is_odds(c) && is_header(c), where("vector needs a header"));
    if (vector_header_of_binary(c)) return;
// Here I want to check the contents of the vector.
    size_t len = length_of_header(c);
    if (is_mixed_header(c)) len = 4*CELL;
    for (size_t i=CELL; i<len; i+=CELL)
    {   LispObject v = *(LispObject *)((x & ~TAG_BITS)+i);
        my_assert(!is_forward(v) &&
                   !is_sym_or_vec_hdr(v), "bad vec contents");
    }
}

// The code here uses std::stack<T> rather than recursion to traverse
// data, so that it can not suffer from stack overflow and thereby corrupt
// everything in a potentially confusing way. Well the std::stack can
// fail to allocate space when it needs to expand, but I rather hope that
// will be a clear-cut matter if it arises.

inline void validateObject(LispObject x,
                           bool forwardOK=false,
                           bool oldSpaceValid=true)
{
    intptr_t pc = Xtop;
    trail.push(x);
    state.push(pc);
    Header h;
down:
// When we get to "down:" x is an object to check and pc is an indication
// of its source. If the object has components the code will push x and pc
// so that they will be available later, set x to the component and pc to
// say which it was and return to down:. If an object has been visited
// before or is trivial it just heads to up:.
    if (is_immediate(x) || x == nil) goto up;     // Ha ha an easy case!
    if (visited.count(x) != 0) goto up;
    checkOldVsNew(x, oldSpaceValid);
    visited.insert(x);
    if (is_cons(x))
    {   if (forwardOK)
        {   LispObject f = indirect(x-TAG_CONS);
            if (is_forward(f)) x = f-TAG_FORWARD+TAG_CONS;
        }
        checkCons(x, forwardOK);
        trail.push(x);
        state.push(pc);
        x = car(x);
        pc = Xcar;
        goto down;
    }
    else if (is_symbol(x))
    {   if (forwardOK)
        {   LispObject f = indirect(x-TAG_SYMBOL);
            if (is_forward(f)) x = f-TAG_FORWARD+TAG_SYMBOL;
        }
        checkSymbol(x, forwardOK);
        trail.push(x);
        state.push(pc);
        x = qvalue(x);
        pc = Xvalue;
        goto down;
    }
    else if (is_numbers(x))
    {   if (forwardOK)
        {   LispObject f = indirect(x-TAG_NUMBERS);
            if (is_forward(f)) x = f-TAG_FORWARD+TAG_NUMBERS;
        }
// I am not doing proper checking here (yet)
        goto up;
    }
    else if (is_bfloat(x))
    {   if (forwardOK)
        {   LispObject f = indirect(x-TAG_BOXFLOAT);
            if (is_forward(f)) x = f-TAG_FORWARD+TAG_BOXFLOAT;
        }
        checkBoxfloat(x, forwardOK);
        goto up;
    }
    if (forwardOK)
    {   LispObject f = indirect(x-TAG_VECTOR);
        if (is_forward(f)) x = f-TAG_FORWARD+TAG_VECTOR;
    }
// Here x is a vector.
    checkVector(x, forwardOK);
    h = vechdr(x);
    if (vector_header_of_binary(h) ||
        length_of_header(h) == CELL) goto up;
    trail.push(x);
    state.push(pc);
    pc = length_of_header(h)/CELL-2;
    if (is_mixed_header(h)) pc = 2;
    x = basic_elt(x, pc);
    goto down;    

up:
// at "up:" the top of the trail will be the object whose component has just
// been processed and pc will indicate which component had been handled.
// If there are more components to go then one must reset x to the next
// field from the trail-top and pc to indicate that component and go to
// down: with no stack depth change. If an object has now been completed then
// the trail and state stacks are popped and up: control returns to up:
    if (trail.empty()) my_abort("stack unexpectedly empty");
    x = trail.top();
// vectors are processed by pc being the index of the entry being handled.
// So if we have just handled entry 0 then this vector is done with.
    if (pc == Xelt0)
    {   trail.pop();
        pc = state.top();
        state.pop();
        goto up;
    }
    else if (pc > Xelt0)
    {   pc--;
        x = basic_elt(x, pc);
        goto down;
    }
    else switch (pc)
    {
    default:
        my_abort("pc had bad value in validate");
    case Xtop:
        return;
    case Xcar:
        x = cdr(x);
        pc = Xcdr;
        goto down;
    case Xcdr:
        trail.pop();
        pc = state.top();
        state.pop();
        goto up;
    case Xvalue:
        x = qenv(x);
        pc = Xenv;
        goto down;
    case Xenv:
        x = qplist(x);
        pc = Xplist;
        goto down;
    case Xplist:
        x = qfastgets(x);
        pc = Xfastgets;
        goto down;
    case Xfastgets:
        x = qpackage(x);
        pc = Xpackage;
        goto down;
    case Xpackage:
        x = qpname(x);
        pc = Xpname;
        goto down;
    case Xpname:
        trail.pop();
        pc = state.top();
        state.pop();
        goto up;
    }
}

inline void validateVecPage(Page* p, bool isCurrent)
{   size_t c = 0;
    while (c < chunkInfoSize)
    {   bool pin = chunkNoIsPinned(p, c);
        bool newPin = chunkNoIsNewPinned(p, c);
        uint32_t len = p->chunkLength[c];
        uint32_t seq = p->chunkSeqNo[c];
// Here I am a first bit if any extended chunk
        my_assert(seq == 0, "chunk starts at other then zero");
        if (isCurrent && addressFromChunkNo(p, c) > vecFringe &&
            !pin && !newPin) my_assert(len == 1, "len>1 above vecFringe");
        if (!isCurrent && addressFromChunkNo(p, c) > p->dataEnd &&
            !pin && !newPin) my_assert(len == 1, "len>1 above dataEnd");
        if (len != 1)
        {   for (size_t c1=c+1; c1<c+len; c1++)
            {   my_assert(!chunkNoIsPinned(p, c1), "pin in middle");
                my_assert(!chunkNoIsNewPinned(p, c1), "pin in middle");
                my_assert(p->chunkLength[c1] == 1, "bad len in middle");
                my_assert(p->chunkSeqNo[c1] == c1-c, "bad seq in middle");
            }
        }
        c += len;
        my_assert(c <= chunkInfoSize, "overflow at end of chunks");
    }
}

inline void validateAll(const char* why, bool forwardOK=false, bool oldSpaceValid=true)
{   for (Page* p:vecPages) validateVecPage(p, p==vecCurrent);
    for (Page* p:vecOldPages) validateVecPage(p, false);
    for (Page* p:vecPinPages) validateVecPage(p, false);
    for (Page* p:vecCloggedPages) validateVecPage(p, false);
    visited.clear();
    if (GCTRACE) zprintf("Starting validation %s\n", why);
    validateObject(qvalue(nil), forwardOK, oldSpaceValid);
    validateObject(qenv(nil), forwardOK, oldSpaceValid);
    validateObject(qplist(nil), forwardOK, oldSpaceValid);
    validateObject(qpname(nil), forwardOK, oldSpaceValid);
    validateObject(qfastgets(nil), forwardOK, oldSpaceValid);
    validateObject(qpackage(nil), forwardOK, oldSpaceValid);
    for (LispObject* p:list_bases)
        validateObject(*p, forwardOK, oldSpaceValid);
    for (LispObject* sp=stack; sp>bit_cast<LispObject*>(stackBase); sp--)
        validateObject(*sp, forwardOK, oldSpaceValid);
    if (GCTRACE) zprintf("Validation success\n");
}

#endif // header_validate_h

// end of validate.h
