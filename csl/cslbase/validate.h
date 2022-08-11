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

INLINE_VAR std::unordered_set<LispObject> visited;

// forwardOK can be made true to allow forwarding pointers as valid, which
// is the situation part way through garbage collection. Normally the
// presence of one of them is a sign of a corrupt heap.

class Backtrace
{
public:
    bool special;
    const char* name;
    LispObject payload;
    Backtrace *parent;

    Backtrace(Backtrace *xparent, LispObject x, const char* msg="?")
    {   special = false;
        name = msg;
        payload = x;
        parent = xparent;
    }
    Backtrace(const char* s)
    {   special = true;
        name = s;
        payload = nil;
        parent = nullptr;
    }
    void print()
    {   if (special) zprintf("%s\nEND\n", name);
        else
        {   zprintf("B %a %s: ", payload, name);
            simple_print(payload);
            if (parent != nullptr) parent->print();
        }
    }
};

inline void validateObject(LispObject x,
                           bool forwardOK=false,
                           Backtrace *parent = nullptr)
{   if (is_immediate(x) || x == nil) return;     // Ha ha an easy case!
    if (visited.count(x) != 0) return;
    visited.insert(x);
    Backtrace bb(parent, x, "validateObject");
    if (is_cons(x))
    {   Page* p = pageOf(x);
        my_assert(p->type == consPageType, "cons pointer into vector page");
        LispObject c = car(x);
        if (is_forward(c))
        {   if (!forwardOK)
            {   zprintf("\nCONS %a => %a\n", x, c);
                bb.print();
                my_abort("illegal forwarding");
            }
            x = (c & ~TAG_BITS) | (x & TAG_BITS);
            p = pageOf(x);
            my_assert(p->type == consPageType,
                      "cons pointer forwards into vector page");
            c = car(x);
            my_assert(!is_forward(c), "double forward pointer");
        }
        my_assert(!is_odds(c) || !is_header(c), "header in car(x)");
        c = cdr(x);
        my_assert(!is_odds(c) || !is_header(c), "header in cdr(x)");
        bb.name = "car";
        validateObject(car(x), forwardOK, &bb);
        bb.name = "cdr";
        validateObject(cdr(x), forwardOK, &bb);
        return;
    }
    else if (is_symbol(x))
    {   Page* p = pageOf(x);
        my_assert(p->type == vecPageType, "symbol pointer into cons page");
        LispObject c = qheader(x);
        if (is_forward(c))
        {   if (!forwardOK)
            {   zprintf("\nSYMBOL %a => %a\n", x, c);
                bb.print();
                my_abort("illegal forwarding");
            }
            x = (c & ~TAG_BITS) | (x & TAG_BITS);
            p = pageOf(x);
            my_assert(p->type == vecPageType,
                      "symbol pointer forwards into cons page");
            c = qheader(x);
            my_assert(!is_forward(c), "double forward pointer");
        }
        my_assert(is_symbol_header_full_test(c), "symbol without header");
        bb.name = "qvalue";
        validateObject(qvalue(x), forwardOK, &bb);
        bb.name = "qenv";
        validateObject(qenv(x), forwardOK, &bb);
        bb.name = "qplist";
        validateObject(qplist(x), forwardOK, &bb);
        bb.name = "qfastgets";
        validateObject(qfastgets(x), forwardOK, &bb);
        bb.name = "qpackage";
        validateObject(qpackage(x), forwardOK, &bb);
        bb.name = "qpname";
        validateObject(qpname(x), forwardOK, &bb);
        return;
    }
    if (is_bfloat(x))
    {   Page* p = pageOf(x);
        Page* p1 = p;
        LispObject c = flthdr(x);
        if (is_forward(c))
        {   if (!forwardOK)
            {   zprintf("\nBOXFLOAT %a => %a\n", x, c);
                bb.print();
                my_abort("illegal forwarding");
            }
            x = (c & ~TAG_BITS) | (x & TAG_BITS);
            p1 = pageOf(x);
            c = flthdr(x);
            my_assert(!is_forward(c), "double forward pointer");
        }
        my_assert(is_odds(c) && is_header(c), "float needs a header");
        switch (type_of_header(c))
        {
        case TYPE_SINGLE_FLOAT:
        case TYPE_LONG_FLOAT:
            my_assert(p->type == vecPageType, "float in cons page");
            my_assert(p1->type == vecPageType, "float forwards into cons page");
            break;
        case TYPE_DOUBLE_FLOAT:
            if (SIXTY_FOUR_BIT)
            {   my_assert(p->type == consPageType, "double float in vector page");
                my_assert(p1->type == consPageType, "double float forwards into vector page");
            }
            else
            {   my_assert(p->type == vecPageType, "float in cons page");
                my_assert(p1->type == vecPageType, "float forwards into cons page");
            }
            break;
        default:
            my_abort("float with bad header");
        }        
        return;
    }
// In all other cases we should have some sort of vector.
    Page* p = pageOf(x);
    my_assert(p->type == vecPageType, "vector in cons page");
    LispObject c = car(x & ~TAG_BITS);
    if (is_forward(c))
    {   if (!forwardOK)
        {   zprintf("\nVEC %a => %a\n", x, c);
            bb.print();
            my_abort("illegal forwarding");
        }
        x = (c & ~TAG_BITS) | (x & TAG_BITS);
        p = pageOf(x);
        my_assert(p->type == vecPageType,
                      "vector forwards into cons page");
        c = car(x & ~TAG_BITS);
        my_assert(!is_forward(c), "double forward pointer");
    }
    my_assert(is_odds(c) && is_header(c), "vector needs a header");
    if (vector_header_of_binary(c)) return;
// Here I want to check the contents of the vector.
    size_t len = length_of_header(c);
    if (is_mixed_header(c)) len = 4*CELL;
    for (size_t i=CELL; i<len; i+=CELL)
    {   char msg[20];
        std::sprintf(msg, "[%d]", (int)i);
        bb.name = msg;
        validateObject(*(LispObject *)((x & ~TAG_BITS)+i), forwardOK, &bb);
    }
    return;
}

inline void validateAll(const char* why, bool forwardOK=false)
{   visited.clear();
    Backtrace bb("nil");
    zprintf("Starting validation %s\n", why);
    bb.name = "qvalue(nil)";
    validateObject(qvalue(nil), forwardOK, &bb);
    bb.name = "qenv(nil)";
    validateObject(qenv(nil), forwardOK, &bb);
    bb.name = "qplist(nil)";
    validateObject(qplist(nil), forwardOK, &bb);
    bb.name = "qpname(nil)";
    validateObject(qpname(nil), forwardOK, &bb);
    bb.name = "qfastgets(nil)";
    validateObject(qfastgets(nil), forwardOK, &bb);
    bb.name = "qpackage(nil)";
    validateObject(qpackage(nil), forwardOK, &bb);
    int k=0;
    for (LispObject* p:list_bases)
    {   bb.name = list_names[k++];
        validateObject(*p, forwardOK, &bb);
    }
    for (LispObject* sp=stack; sp>csl_cast<LispObject*>(stackBase); sp--)
    {   char msg[20];
        std::sprintf(msg, "Stack %d", (int)(stack-sp));
        bb.name = msg;
        validateObject(*sp, forwardOK, &bb);
    }
    zprintf("Validation success\n");
}

#endif // header_validate_h


// end of validate.h
