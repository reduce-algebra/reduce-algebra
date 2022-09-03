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
    int depth;

    Backtrace(Backtrace *xparent, int xdepth, LispObject x, const char* msg="?")
    {   special = false;
        name = msg;
        payload = x;
        parent = xparent;
        depth = xdepth;
    }
    Backtrace(const char* s)
    {   special = true;
        name = s;
        payload = nil;
        parent = nullptr;
        depth = 0;
    }
    void print()
    {   if (special) zprintf("%s\nEND\n", name);
        else
        {   zprintf("Bt %a %s: ", payload, name);
            simple_print(payload);
            if (parent != nullptr) parent->print();
        }
    }
};

inline void validateObject(LispObject x,
                           bool forwardOK=false,
                           bool oldSpaceValid=true,
                           Backtrace *parent=nullptr)
{   if (is_immediate(x) || x == nil) return;     // Ha ha an easy case!
    if (visited.count(x) != 0) return;
    if (!oldSpaceValid &&
        ((consOldPages.contains(pageOf(x)) &&
          !consIsPinned(x, pageOf(x)) &&
          !consIsNewPinned(x, pageOf(x))) ||
         (vecOldPages.contains(pageOf(x)) &&
          !vecIsPinned(x, pageOf(x)) &&
          !vecIsNewPinned(x, pageOf(x)))))
    {   zprintf("Bad reference to %a\n", x);
        simple_print(x);
        if (parent != nullptr) parent->print();
        my_abort(where("reference into old half-space"));
    }
    visited.insert(x);
    if (parent->depth > 100) return; // Avoid stack overflow.
    Backtrace bb(parent, parent->depth+1, x, "validateObject");
    if (is_cons(x))
    {   Page* p = pageOf(x);
        my_assert(p->type == consPageType, where("cons pointer into vector page"));
        LispObject c = car(x);
        if (is_forward(c))
        {   if (!forwardOK)
            {   zprintf("\nCONS %a => %a\n", x, c);
                bb.print();
                my_abort(where("illegal forwarding"));
            }
            x = (c & ~TAG_BITS) | (x & TAG_BITS);
            p = pageOf(x);
            my_assert(p->type == consPageType,
                      where("cons pointer forwards into vector page"));
            c = car(x);
            my_assert(!is_forward(c), where("double forward pointer"));
        }
        my_assert(!is_odds(c) || !is_header(c), where("header in car(x)"));
        c = cdr(x);
        my_assert(!is_odds(c) || !is_header(c), where("header in cdr(x)"));
        bb.name = "car";
        validateObject(car(x), forwardOK, oldSpaceValid, &bb);
        bb.name = "cdr";
        validateObject(cdr(x), forwardOK, oldSpaceValid, &bb);
        return;
    }
    else if (is_symbol(x))
    {   Page* p = pageOf(x);
        my_assert(p->type == vecPageType, where("symbol pointer into cons page"));
        LispObject c = qheader(x);
        if (is_forward(c))
        {   if (!forwardOK)
            {   zprintf("\nSYMBOL %a => %a\n", x, c);
                bb.print();
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
        bb.name = "qvalue";
        validateObject(qvalue(x), forwardOK, oldSpaceValid, &bb);
        bb.name = "qenv";
        validateObject(qenv(x), forwardOK, oldSpaceValid, &bb);
        bb.name = "qplist";
        validateObject(qplist(x), forwardOK, oldSpaceValid, &bb);
        bb.name = "qfastgets";
        validateObject(qfastgets(x), forwardOK, oldSpaceValid, &bb);
        bb.name = "qpackage";
        validateObject(qpackage(x), forwardOK, oldSpaceValid, &bb);
        bb.name = "qpname";
        validateObject(qpname(x), forwardOK, oldSpaceValid, &bb);
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
        return;
    }
// In all other cases we should have some sort of vector.
    Page* p = pageOf(x);
    my_assert(p->type == vecPageType, where("vector in cons page"));
    LispObject c = car(x & ~TAG_BITS);
    if (is_forward(c))
    {   if (!forwardOK)
        {   zprintf("\nVEC %a => %a\n", x, c);
            bb.print();
            my_abort(where("illegal forwarding"));
        }
        x = (c & ~TAG_BITS) | (x & TAG_BITS);
        p = pageOf(x);
        my_assert(p->type == vecPageType,
                      where("vector forwards into cons page"));
        c = car(x & ~TAG_BITS);
        if (is_forward(c))
        {   bb.print();
            my_abort(where("double forward pointer"));
        }
    }
    my_assert(is_odds(c) && is_header(c), where("vector needs a header"));
    if (vector_header_of_binary(c)) return;
// Here I want to check the contents of the vector.
    size_t len = length_of_header(c);
    if (is_mixed_header(c)) len = 4*CELL;
    for (size_t i=CELL; i<len; i+=CELL)
    {   char msg[20];
        std::sprintf(msg, "[%d]", (int)i);
        bb.name = msg;
        validateObject(*(LispObject *)((x & ~TAG_BITS)+i), forwardOK, oldSpaceValid, &bb);
    }
    return;
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
    Backtrace bb("nil");
    if (GCTRACE) zprintf("Starting validation %s\n", why);
    bb.name = "qvalue(nil)";
    validateObject(qvalue(nil), forwardOK, oldSpaceValid, &bb);
    bb.name = "qenv(nil)";
    validateObject(qenv(nil), forwardOK, oldSpaceValid, &bb);
    bb.name = "qplist(nil)";
    validateObject(qplist(nil), forwardOK, oldSpaceValid, &bb);
    bb.name = "qpname(nil)";
    validateObject(qpname(nil), forwardOK, oldSpaceValid, &bb);
    bb.name = "qfastgets(nil)";
    validateObject(qfastgets(nil), forwardOK, oldSpaceValid, &bb);
    bb.name = "qpackage(nil)";
    validateObject(qpackage(nil), forwardOK, oldSpaceValid, &bb);
    int k=0;
    for (LispObject* p:list_bases)
    {   bb.name = list_names[k++];
        validateObject(*p, forwardOK, oldSpaceValid, &bb);
    }
    for (LispObject* sp=stack; sp>bit_cast<LispObject*>(stackBase); sp--)
    {   char msg[20];
        std::sprintf(msg, "Stack %d", (int)(stack-sp));
        bb.name = msg;
        validateObject(*sp, forwardOK, oldSpaceValid, &bb);
    }
    if (GCTRACE) zprintf("Validation success\n");
}

#endif // header_validate_h

// end of validate.h
