// File cslgc.cpp                         Copyright (c) Codemist, 1990-2016

//
// Garbage collection.
//
//    October 2016 and once again I REMOVE the mark/slide collector. This
//    decision is to simplify the code and ease a transition to a replacement
//    copying collector, and because I no longer view 32-bit machines as
//    high priority. Well a Raspberry Pi with 1 Gbyte can still do serious
//    size calculations even with the copying collector.
//
//    HMMMM - the justification I gave for removing the mark/slide
//    collector is DUBIOUS. Specifically on a machine that is limited by
//    address-space not by actual real memory the fact that the copying
//    collector can only afford to fill up half the address-space before
//    leaping into action may be SAD. So on 64-bit systems where address
//    space is cheap I think that only copying is good, but on a 32-bit
//    system in the case that a user's task needs a gigabyte or so of
//    memory the call has to be different. I am thus reinstating the
//    old mark/slide collector! But note that this will NOT be compatible
//    with my experiment towards a conservative collector (ditto if I ever
//    tried to go generational!).
//
//    Version 5. The mark/slide code is being removed on the
//    grounds that machines these days have LOTS of memory so ot should
//    not really be needed, and it is a lot of messy code to support.
//    there is also a start at support for a
//    conservative garbage collector so that the separate C
//    stack that I used to need is no longer called for: the hope is
//    that this may seriously speed up much code... but it makes
//    "cons" a little messier and "allocate_vector" a lot messier,
//    and a somewhat-copying conservative GC hurts on the complication
//    front quite a lot! That is enabled via --enable-conservative in
//    that autoconf stuff, and is NOT working yet.
//
//    Fourth major version - now using Foster-style
//    algorithm for relocating vector heap, and support for handling
//    BPS via segmented handles. Pointer-reversing mark phase to go
//    with same.
//
//    Furthermore there is (optionally) a copying 2-space garbage
//    collector as well as the mark/slide one.  Now do you understand
//    why this file seems so very long?
//
// The code in parts of this file (and also in preserve.c & restart.c)
// is painfully sensitive to memory layout and I have some messy
// conditional inclusion of code depending on whether a Lisp_Object is
// a 32 or 64-bit value.
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

#ifdef WIN32
#include <conio.h>
#endif

void validate_failed()
{
    ensure_screen();
    fflush(stdout);
    fflush(stderr);
    abort();
}

#ifdef DEBUG_VALIDATE

//
// The purpose of this code is to traverse the active data in the heap
// checking that the structure is correct. It is for use when hunting
// bugs that have led to memory corruption. It is only built if DEBUG
// is defined, and so is not present in a production version. Because of
// that I feel entitles to make it a bit profligate in memory use and
// stack use. It will use bitmaps to record which bits of data have been
// visited, and simple recursion in its traverse.
//


//
// The scheme here will FAIL if invoked early on when a 32-bit image
// has been re-loaded on a 64-bit platform, because in that situation
// there can be some double-sized pages used. This really needs to be
// resolved, but since the code here is merely for debugging purposes
// I will consider that case later on when I run into trouble with it.
//


static const char *validate_why, *validate_file;
static int validate_line, validate_line1;

//
// p is a (reference to a) cons cell. Verify it is within a
// cons heap-page, set a mark bit for it and return 1 if it had
// already been marked.
//

#define MAP_SIZE (((size_t)MAX_PAGES)*((size_t)((CSL_PAGE_SIZE+255)/256)))

static int32_t (*heap_map)[MAX_PAGES][(CSL_PAGE_SIZE+255)/256];

static int bitmap_mark_cons(LispObject p)
{   int32_t i;
    LispObject nil = C_nil;
    if (!consp(p))
    {   term_printf("\n%p is not a cons pointer\n", (void *)p);
        term_printf("Validation for %s at line %d of file %s (%d)\n",
                    validate_why, validate_line, validate_file, validate_line1);
        validate_failed();
    }
    for (i=0; i<heap_pages_count; i++)
    {   void *page = heap_pages[i];
        char *base = (char *)quadword_align_up((intptr_t)page);
//
// This checking is INCORRECT just after you have loaded a 32-bit image
// on a 64-bit machine because in that situation the pages can be
// twice the regular size until the first copying garbage collection has
// regularised matters.
//
        if ((intptr_t)base <= (intptr_t)p &&
            (intptr_t)p <= (intptr_t)(base+CSL_PAGE_SIZE))
        {   unsigned int offset = ((unsigned int)((char *)p - base)) >> 3;
            int b = offset%32, w = offset/32;
            int32_t m = 1 << b;
            int32_t r = (*heap_map)[i][w];
            (*heap_map)[i][w] |= m;
            return (r & m) != 0;
        }
    }
    term_printf("\nCons address %p not found in heap\n", (void *)p);
    term_printf("Validation for %s at line %d of file %s (%d)\n",
                validate_why, validate_line, validate_file, validate_line1);
    term_printf("nil = %p\n", (void *)nil);
    term_printf("Heap: %d\n", heap_pages_count);
    for (i=0; i<heap_pages_count; i++)
        term_printf("%d:  %p\n", i, (void *)heap_pages[i]);
    term_printf("VecHeap: %d\n", vheap_pages_count);
    for (i=0; i<vheap_pages_count; i++)
        term_printf("%d:  %p\n", i, (void *)vheap_pages[i]);
    validate_failed();
    return 1;
}

//
// p is a reference to something in the vector heap. Verify it is within a
// vector heap-page, set a mark bit for it and return 1 if it had
// already been marked.
//

static int32_t (*vecheap_map)[MAX_PAGES][(CSL_PAGE_SIZE+255)/256];

static int bitmap_mark_vec(LispObject p)
{   int32_t i;
    const char *info = "unknown";
    LispObject nil = C_nil;
//
// Check that the object is corectly tagged. Note that NIL must be
// handled specially since althout it is (sort of) a symbol it does not
// live in any of the vheap_pages.
//
    if (!is_symbol(p) &&
        !is_numbers(p) &&
        !is_vector(p) &&
        !is_bfloat(p))
    {   term_printf("\n%p is not a vector pointer\n", (void *)p);
        term_printf("Validation for %s at line %d of file %s (%d)\n",
                    validate_why, validate_line, validate_file, validate_line1);
        validate_failed();
    }
// Now I will check if the header looks good...
    if (is_vector(p))
    {   Header h = vechdr(p);
        if (!is_vector_header_full_test(h))
        {   term_printf("header of vector is wrong\n");
            term_printf("Validation for %s at line %d of file %s (%d)\n",
                        validate_why, validate_line, validate_file, validate_line1);
            validate_failed();
        }
    }
    else if (is_symbol(p))
    {   Header h = qheader(p);
        if (!is_symbol_header_full_test(h))
        {   term_printf("symbol header is wrong at %" PRIxPTR "\n", h);
            term_printf("Validation for %s at line %d of file %s (%d)\n",
                        validate_why, validate_line, validate_file, validate_line1);
            validate_failed();
        }
    }
    {   LispObject x = p;
        if (is_symbol(x)) x = qpname(x);
        if (is_vector(x) && is_string(x)) info = &celt(x, 0);
        else if (is_symbol(p)) info = "unnamed symbol";
        else if (is_vector(x)) info = "vector";
        else if (is_numbers(x)) info = "numbers";
        else if (is_bfloat(x)) info = "boxed float";
        else info = "huh???";
    }
    for (i=0; i<vheap_pages_count; i++)
    {   void *page = vheap_pages[i];
        char *base = (char *)quadword_align_up((intptr_t)page);
        if ((intptr_t)base <= (intptr_t)(p & ~TAG_BITS) &&
            (intptr_t)p <= (intptr_t)(base+CSL_PAGE_SIZE))
        {   unsigned int offset =
                ((unsigned int)((char *)(p & ~TAG_BITS) - base)) >> 3;
            int b = offset%32, w = offset/32;
            int32_t m = 1 << b;
            int32_t r = (*vecheap_map)[i][w];
            (*vecheap_map)[i][w] |= m;
            return (r & m) != 0;
        }
    }
    term_printf("\nVector address %p not found in heap\n", (void *)p);
    term_printf("Validation for %s at line %d of file %s (%d)\n",
                validate_why, validate_line, validate_file, validate_line1);
    term_printf("info = %s\n", info);
    term_printf("nil = %p\n", (void *)nil);
    term_printf("Heap: %d\n", heap_pages_count);
    for (i=0; i<heap_pages_count; i++)
        term_printf("%d:  %p\n", i, (void *)heap_pages[i]);
    term_printf("VecHeap: %d\n", vheap_pages_count);
    for (i=0; i<vheap_pages_count; i++)
        term_printf("%d:  %p\n", i, (void *)vheap_pages[i]);
    validate_failed();
    return 1;
}

//
// Note that BPS items are stored as a sort of handle that encodes the
// page number and the offset, so I do not need to do elaborate searches
// to validate them. If I was keen I would take a BPS handle and decode it
// and check that what it referred to at least gave some impression of
// being as expected - specifically I could check that there was a BPS
// header just before it. But I do not do that yet!
//


//
// The next procedure is given a Lisp_Object and it checks that it is
// at least vaguely sensible, It similarly inspects all items reachable
// from that object.
//

static void validate(LispObject p, int line1)
{   LispObject nil = C_nil;
// This code is activate when there is a suspected bug in the garbage
// collector. A consequence is that it may be called when the heap is in
// a corrupt state. The variable "info" here is set to give a small amount
// of information about what has been being scanned, but is not inspected
// by the code. It is present so that a debugger can check it following any
// crash.
    volatile const char *info = "unknown";
    Header h = 0;
    validate_line1 = line1;
    size_t i = 0;
    (void)info;   // Tends to prevent gcc from moaning about definition
                  // without use.
    if (p == nil) return;
    if (p == 0)
    {   term_printf("NULL item found\n");
        term_printf("Validation for %s at line %d of file %s (%d)\n",
                    validate_why, validate_line, validate_file, validate_line1);
        validate_failed();
    }
//
// The code here is going to be simply recursive so that if any problem
// is detected I have maximum information on the stack about where it
// came from. But note that this could use a LOT of stack....
//
    if (is_immed_or_cons(p))
    {   if (!is_cons(p)) return;
        info = "cons cell";
        if (bitmap_mark_cons(p)) return;
        validate(qcar(p), __LINE__);
        validate(qcdr(p), __LINE__);
        return;
    }
// here we have a vector of some sort
    switch ((int)p & TAG_BITS)
{       default:            // The case-list is exhaustive!
        case TAG_CONS:      // Already processed
        case TAG_FIXNUM:    // Invalid here
        case TAG_HDR_IMMED: // Invalid here
#ifdef SHORT_FLOAT
        case TAG_SFLOAT:    // Invalid here
#endif
            term_printf("\nBad object in VALIDATE (%.8lx)\n", (long)p);
            term_printf("Validation for %s at line %d of file %s (%d)\n",
                        validate_why, validate_line, validate_file, validate_line1);
            validate_failed();

        case TAG_SYMBOL:
            info = "symbol";
            if (is_vector(qpname(p)) &&
                is_string(qpname(p))) info = &celt(qpname(p), 0);
            if (bitmap_mark_vec(p)) return;
            validate(qvalue(p), __LINE__);
            validate(qenv(p), __LINE__);
            validate(qpname(p), __LINE__);
            validate(qpackage(p), __LINE__);
            validate(qplist(p), __LINE__);
            return;

        case TAG_NUMBERS:
            info = "numbers";
            if (bitmap_mark_vec(p)) return;
            h = numhdr(p);
            if (is_bignum_header(h)) return;
            validate(real_part(p), __LINE__);
            validate(imag_part(p), __LINE__);
            return;

        case TAG_BOXFLOAT:
            info = "boxfloat";
            if (bitmap_mark_vec(p)) return;
            return;

        case TAG_VECTOR:
            info = "vector";
            if (bitmap_mark_vec(p)) return;
            h = vechdr(p);
            if (vector_holds_binary(h)) return;  // strings & bitvecs
            info = "lispvector";
            i = (intptr_t)doubleword_align_up(length_of_header(h));
            if (is_mixed_header(h))
                i = 4*CELL;  // Only use first few pointers
            while (i >= 2*CELL)
            {   i -= CELL;
                validate(*(LispObject *)((char *)p - TAG_VECTOR + i), __LINE__);
            }
            return;
    }
}

void validate_all(const char *why, int line, const char *file)
{   LispObject *sp = NULL;
    LispObject nil = C_nil;
    int i;
    validate_why = why;
    validate_line = line;
    validate_line1 = 0;
    validate_file = file;   // In case a diagnostic is needed
//  term_printf("Validate heap for %s at line %d of %s\n", why, line, file);
    if (heap_map == NULL)
    {   if ((heap_map =
                (int32_t (*)[MAX_PAGES][(CSL_PAGE_SIZE+255)/256])
                calloc(MAP_SIZE, 1)) == NULL)
        {   term_printf("Unable to allocate %dM (%x) space for heap map\n",
                        (int)(MAP_SIZE/(1024*1024)), (int)(MAP_SIZE/(1024*1024)));
            return;
        }
    }
    if (vecheap_map == NULL)
    {   if ((vecheap_map =
                 (int32_t (*)[MAX_PAGES][(CSL_PAGE_SIZE+255)/256])
                 calloc(MAP_SIZE, 1)) == NULL)
        {   term_printf("Unable to allocate %dM (%x) space for vecheap map\n",
                        (int)(MAP_SIZE/(1024*1024)), (int)(MAP_SIZE/(1024*1024)));
            return;
        }
    }
//
// The list bases to check from are
// (a) nil    [NB: validate(nil) would be ineffective],
// (b) the special ones addressed relative to nil,
// (c) everything on the Lisp stack,
// (d) the package structure,
//
    validate(qplist(nil), __LINE__);
    validate(qpname(nil), __LINE__);
    validate(qfastgets(nil), __LINE__);
    validate(qpackage(nil), __LINE__);

    for (i = first_nil_offset; i<last_nil_offset; i++) validate(BASE[i], __LINE__);
    for (sp=stack; sp>(LispObject *)stackbase; sp--) validate(*sp, __LINE__);
    validate(eq_hash_tables, __LINE__);
    validate(equal_hash_tables, __LINE__);
//  term_printf("Validation complete\n");
}



int check_env(LispObject env)
{
//
// Return 1 if environment call of something compiled into C looks bad.
//
    if (env == 0 ||
        !is_vector(env)) return 1;
    return 0;
}

#endif // DEBUG_VALIDATE: the validate code

#ifdef SOCKETS
#include "sockhdr.h"
#endif // SOCKETS

int gc_number = 0;
int reclaim_trap_count = -1;
int reclaim_stack_limit = 0;

static intptr_t cons_cells, symbol_heads, strings, user_vectors,
       big_numbers, box_floats, bytestreams, other_mem,
       litvecs, getvecs;

LispObject Lgc0(LispObject nil, int nargs, ...)
{   argcheck(nargs, 0, "reclaim");
    return Lgc(nil, lisp_true);
}

LispObject Lgc(LispObject nil, LispObject a)
{
//
// If GC is called with a non-nil argument the garbage collection
// will be a full one - otherwise it will be soft and may do hardly
// anything.
//
    return reclaim(nil, "user request",
                   a != nil ? GC_USER_HARD : GC_USER_SOFT, 0);
}

LispObject Lverbos(LispObject nil, LispObject a)
//
// (verbos 0) or (verbos nil)       silent garbage collection
// (verbos 1) or (verbos t)         standard GC messages
// (verbos 2)                       messages when FASL module loaded
// (verbos 4)                       extra timing info for GC process
// These bits can be added to get combination effects, except that
// "4" has no effect unless "1" is present.
//
{   int code, old_code = verbos_flag;
    if (a == nil) code = 0;
    else if (is_fixnum(a)) code = (int)int_of_fixnum(a);
    else code = 1;
    miscflags = (miscflags & ~GC_MSG_BITS) | (code & GC_MSG_BITS);
    return onevalue(fixnum_of_int(old_code));
}


bool volatile already_in_gc, tick_on_gc_exit;
bool volatile interrupt_pending, tick_pending;
LispObject volatile saveheaplimit;
LispObject volatile savevheaplimit;
LispObject * volatile savestacklimit;


static int stop_after_gc = 0;

static void zero_out(void *p)
{   char *p1 = (char *)doubleword_align_up((intptr_t)p);
    memset(p1, 0, CSL_PAGE_SIZE);
}


//
// You may like to observe how much more compact the code for the copying
// garbage collector is when compared with the mark/slide mess.  It is
// naturally and easily non-recursive and does not get involved in any
// over-dubious punning on bit-patterns... It just requires a lot of spare
// memory for the new semi-space.
//

static int trailing_heap_pages_count,
       trailing_vheap_pages_count;

static void copy(LispObject *p)
//
// This copies the object pointed at by p from the old to the new semi-space,
// and returns a copy to the pointer.  If scans the copied material to copy
// all relevent sub-structures to the new semi-space.
//
{   LispObject nil = C_nil;
    char *fr = (char *)fringe, *vfr = (char *)vfringe;
    char *tr_fr = fr, *tr_vfr = vfr;
    void *p1;
#define CONT           0
#define DONE_CAR      -1
#define DONE_VALUE    -2
#define DONE_ENV      -3
#define DONE_PNAME    -4
#define DONE_PLIST    -5
#define DONE_FASTGETS -6
    int next = CONT;
    char *tr=NULL;
#ifdef DEBUG_GC
    term_printf("Copy [%p] %p\n", (void *)p, (void *)*p);
#endif // DEBUG_GC
//
// The code here is a simulation of multiple procedure calls to the
// code that copies a single object.  What might otherwise have been
// a "return address" in the calls is handled by the variable "next" which
// takes positive values while copying vectors, and negative ones in
// the more common cases. I use "for (;;)" blocks a lot so that I can
// use "break" and "continue" to leap around in the code - maybe I
// would do better to be honest and use regular labels and "goto"
// statements.
//
    for (;;)
    {
//
// Copy one object, pointed at by p, from the old semi-space into the new
// one.
//
        LispObject a = *p;
#ifdef DEBUG_GC
        term_printf("Next copy [%p] %p\n", (void *)p, (void *)a);
        if (a == 0)
        {   term_printf("Shambles\n");
            *(int *)(-1) = 0;
        }
#endif // DEBUG_GC
        for (;;)
        {   if (a == nil) break;    // common and cheap enough to test here
            else if (is_immed_or_cons(a))
            {   if (is_cons(a))
                {   LispObject w;
                    w = qcar(a);
                    if (is_cons(w) && is_marked_p(w)) // a forwarding address
                    {   *p = flip_mark_bit_p(w);
                        break;
                    }
                    fr = fr - sizeof(Cons_Cell);
                    cons_cells += 2*CELL;
//
// When I am doing regular calculation I leave myself a bunch of spare
// words (size SPARE bytes) so that I can afford to do several cons operations
// between tests.  Here I do careful tests on every step, and so I can
// sail much closer to the wind wrt filling up space.
//
                    if (fr <= (char *)heaplimit - SPARE + 32)
                    {   char *hl = (char *)heaplimit;
                        void *p;
                        int32_t len = (int32_t)(fr - (hl - SPARE) +
                                                sizeof(Cons_Cell));
                        car32(hl - SPARE) = len;
                        qcar(fr) = SPID_GCMARK;
                        if (pages_count == 0)
                        {   term_printf("pages_count = 0 in GC\n");
                            validate_failed();
                            return;
                        }
                        p = pages[--pages_count];
                        zero_out(p);
                        new_heap_pages[new_heap_pages_count++] = p;
                        heaplimit = quadword_align_up((intptr_t)p);
                        hl = (char *)heaplimit;
                        car32(heaplimit) = CSL_PAGE_SIZE;
                        fr = hl + CSL_PAGE_SIZE - sizeof(Cons_Cell);
                        heaplimit = (LispObject)(hl + SPARE);
                    }
                    qcar(fr) = w;
                    qcdr(fr) = qcdr(a);
#ifdef DEBUG_GC
                    term_printf("new data for cons %p %p\n", (void *)w, (void *)qcdr(a));
#endif // DEBUG_GC
                    *p = w = (LispObject)(fr + TAG_CONS);
                    qcar(a) = flip_mark_bit_p(w);
                    break;
                }   // end of treatment of CONS
                else break;        // Immediate data drops out here
            }
            else                    // Here I have a symbol or vector
            {   Header h;
                int tag;
                intptr_t len;
                tag = ((int)a) & TAG_BITS;
                a = (LispObject)((char *)a - tag);
                h = *(Header *)a;
#ifdef DEBUG_GC
                term_printf("Header is %p\n", (void *)h);
#endif // DEBUG_GC
                if (!is_odds(h))
                {   *p = h;
                    break;
                }
                if (tag == TAG_SYMBOL)
                    len = symhdr_length, symbol_heads += symhdr_length;
                else
                {   len = doubleword_align_up(length_of_header(h));
                    if (type_of_header(h) == TYPE_NEWHASH)
                        h = h ^ (TYPE_NEWHASH ^ TYPE_NEWHASHX);
                    switch (type_of_header(h))
                    {
                        case TYPE_STRING_1:
                        case TYPE_STRING_2:
                        case TYPE_STRING_3:
                        case TYPE_STRING_4:
                            strings += len; break;
                        case TYPE_BIGNUM:
                            big_numbers += len; break;
                        case TYPE_SINGLE_FLOAT:
                        case TYPE_LONG_FLOAT:
                        case TYPE_DOUBLE_FLOAT:
                            box_floats += len; break;
                        case TYPE_SIMPLE_VEC:
                            user_vectors += len; break;
                        default:
                            other_mem += len; break;
                    }
                }
                for (;;)
                {   char *vl = (char *)vheaplimit;
                    int32_t free = (int32_t)(vl - vfr);
                    if (len > free)
                    {   int32_t free1 =
                            (int32_t)(vfr - (vl - (CSL_PAGE_SIZE - 8)));
                        car32(vl - (CSL_PAGE_SIZE - 8)) = free1;
                        qcar(vfr) = 0;          // sentinel value
                        if (pages_count == 0)
                        {   term_printf("pages_count = 0 in GC\n");
                            validate_failed();
                            return;
                        }
                        p1 = pages[--pages_count];
                        zero_out(p1);
                        new_vheap_pages[new_vheap_pages_count++] = p1;
                        vfr = (char *)doubleword_align_up((intptr_t)p1) + 8;
                        vl = vfr + (CSL_PAGE_SIZE - 16);
                        vheaplimit = (LispObject)vl;
                        free1 = (uintptr_t)(vfr - (vl - (CSL_PAGE_SIZE - 8)));
                        car32(vl - (CSL_PAGE_SIZE - 8)) = free1;
                        continue;
                    }
                    *(LispObject *)a = *p = (LispObject)(vfr + tag);
                    *(Header *)vfr = h;
                    memcpy((char *)vfr+CELL, (char *)a+CELL, len-CELL);
                    vfr += len;
                    break;
                }
                break;
            }
        }
//
// Now I have copied one object - the next thing to do is to scan to see
// if any further items are in the new space, and if so I will copy
// their offspring.
//
        for (;;)
        {
#ifdef DEBUG_GC
            switch (next)
            {   case CONT:
                    term_printf("next is CONT\n");
                    break;
                case DONE_CAR:
                    term_printf("next is DONE_CAR\n");
                    break;
                case DONE_VALUE:
                    term_printf("next is DONE_VALUE\n");
                    break;
                case DONE_ENV:
                    term_printf("next is DONE_ENV\n");
                    break;
                case DONE_PNAME:
                    term_printf("next is DONE_PNAME\n");
                    break;
                case DONE_PLIST:
                    term_printf("next is DONE_PLIST\n");
                    break;
                case DONE_FASTGETS:
                    term_printf("next is DONE_FASTGETS\n");
                    break;
                default:
                    term_printf("next is array offset %d = %x\n", next, next);
                    break;
            }
#endif // DEBUG_GC
            switch (next)
            {   case CONT:
                    if (tr_fr != fr)
                    {   tr_fr = tr_fr - sizeof(Cons_Cell);
                        if (qcar(tr_fr) == SPID_GCMARK)
                        {   char *w;
                            p1 = new_heap_pages[trailing_heap_pages_count++];
                            w = (char *)quadword_align_up((intptr_t)p1);
                            tr_fr = w + (CSL_PAGE_SIZE - sizeof(Cons_Cell));
                        }
                        next = DONE_CAR;
                        p = &qcar(tr_fr);
                        break;              // Takes me to the outer loop
                    }
                    else if (tr_vfr != vfr)
                    {   Header h;
                        h = *(Header *)tr_vfr;
                        if (h == 0)
                        {   char *w;
                            p1 = new_vheap_pages[trailing_vheap_pages_count++];
                            w = (char *)doubleword_align_up((intptr_t)p1);
                            tr_vfr = w + 8;
                            h = *(Header *)tr_vfr;
                        }
                        if (is_symbol_header(h))
                        {   next = DONE_VALUE;
                            p = &(((Symbol_Head *)tr_vfr)->value);
                            break;
                        }
                        else
                        {   int32_t len = doubleword_align_up(length_of_header(h));
                            tr = tr_vfr;
                            tr_vfr = tr_vfr + len;
                            if (len == CELL)
                            {
//
// In a 64-bit world vectors are not padded to be an even number of cells,
// and so a vector with no elements consists of just its header word. This
// is best treated as if it contained binary because it certainly does not
// contain any pointers, while the general code for handling vectors is
// written on the assumption that every vector that contains pointers at
// all contains at least one.
//
#ifdef DEBUG_GC
                                term_printf("zero length vector in 64-bit world\n");
#endif // DEBUG_GC
                                continue;
                            }
#ifdef DEBUG_GC
                            term_printf("header = %llx, type = %d/%x len = %d\n",
                                        (long long)h, type_of_header(h), type_of_header(h), len);
#endif // DEBUG_GC

                            switch (type_of_header(h))
                            {   case TYPE_SINGLE_FLOAT:
                                case TYPE_LONG_FLOAT:
                                case TYPE_DOUBLE_FLOAT:
                                case TYPE_BIGNUM:
                                    continue;
                                case TYPE_MIXED1: case TYPE_MIXED2:
                                case TYPE_MIXED3: case TYPE_STREAM:
                                    next = 2*CELL;
                                    break;
//
// There is a slight delight here. The test "vector_holds_binary" is only
// applicable if the header to be checked is a header of a genuine vector,
// ie something that would have TAG_VECTOR in the pointer to it. But here
// various numeric data types also live in the vector heap, so I need to
// separate them out explicitly. The switch block here does slightly more than
// it actually HAS to, since the vector_holds_binary test would happen to
// deal with several of the numeric types "by accident", but I feel that
// the security of listing them as separate cases is more important than the
// minor speed-up that might come from exploiting such marginal behaviour.
//
                                default:
                                    if (vector_holds_binary(h)) continue;
                                case TYPE_RATNUM:
                                case TYPE_COMPLEX_NUM:
                                    next = len - 2*CELL;
#ifdef DEBUG_GC
                                    term_printf("line %d next now %d\n", __LINE__, next);
                                    if (next < 0)
                                    {   term_printf("unexpectedly negative\n");
                                        // Just a vector with no elements on a 64-bit system?
                                        continue;
                                    }
#endif // DEBUG_GC
                                    break;
                            }
                            p = (LispObject *)(tr + next + CELL);
                            break;
                        }
                    }
                    else
                    {   fringe = (LispObject)fr;
                        vfringe = (LispObject)vfr;
                        return;        // Final exit when all has been copied
                    }
                case DONE_CAR:
                    next = CONT;
                    p = &qcdr(tr_fr);
                    break;
                case DONE_VALUE:
                    next = DONE_ENV;
                    p = &(((Symbol_Head *)tr_vfr)->env);
                    break;
                case DONE_ENV:
                    next = DONE_FASTGETS;
                    p = &(((Symbol_Head *)tr_vfr)->fastgets);
                    break;
                case DONE_FASTGETS:
                    next = DONE_PNAME;
                    p = &(((Symbol_Head *)tr_vfr)->pname);
                    break;
                case DONE_PNAME:
                    next = DONE_PLIST;
                    p = &(((Symbol_Head *)tr_vfr)->plist);
                    break;
                case DONE_PLIST:
                    next = CONT;
                    p = &(((Symbol_Head *)tr_vfr)->package);
                    tr_vfr = tr_vfr + symhdr_length;
                    break;
                default:
                    p = (LispObject *)(tr + next);
                    next -= CELL;
#ifdef DEBUG_GC
                    term_printf("line %d next now %d\n", __LINE__, next);
                    if (next < 0)
                    {   term_printf("unexpectedly negative\n");
                        *(int *)(-1) = 0;
                    }
#endif // DEBUG_GC
                    break;
            }
            break;
        }
    }
}


typedef struct mapstore_item
{   double w;
    double n;
    uint64_t n1;
    LispObject p;
} mapstore_item;

int profile_count_mode = 0;

static int profile_cf(const void *a, const void *b)
{   mapstore_item *aa = (mapstore_item *)a,
                       *bb = (mapstore_item *)b;

    if (profile_count_mode)
    {   if (aa->n1 == bb->n1) return 0;
        if (aa->n1 < bb->n1) return 1;
        else return -1;
    }
    if (aa->w == bb->w) return 0;
    else if (aa->w < bb->w) return 1;
    else return -1;
}


LispObject Lmapstore(LispObject nil, LispObject a)
//
// Argument controls what happens:
//    nil or 0      print statistics and reset to zero
//           1      print, but do not reset
//           2      return list of stats, reset to zero
//           3      return list, do not reset
//           4      reset to zero, do not print, return nil
//       8      Toggle call count mode
//
{   int pass, what;
    int j, gcn = 0;
    double itotal = 0.0, total = 0.0;
    LispObject res = nil;
    mapstore_item *buff=NULL;
    int buffp=0, buffn=0;
    if (a == nil) a = fixnum_of_int(0);
    if (is_fixnum(a)) what = int_of_fixnum(a);
    else what = 0;
    if ((what & 6) == 0)
    {   buff = (mapstore_item *)(*malloc_hook)(100*sizeof(mapstore_item));
        if (buff == NULL) return onevalue(nil); // fail
        buffp = 0;
        buffn = 100;
    }
    if ((what & 2) != 0)
    {   Lgc0(nil, 0); // Force GC at start to avoid one in the middle
        nil = C_nil;
        if (exception_pending()) return nil;
        gcn = gc_number;
    }

    if ((what & 8) != 0)
        profile_count_mode = !profile_count_mode;
#ifdef PROFILED
//
// PROFILED is intended to be defined if we were compiled with a -p option,
// and we take system dependent action to dump out results (e.g. on some systems
// it may be useful to invoke monitor() or moncontrol() here.
//

#ifdef SHOW_COUNTS_AVAILABLE
    show_counts();
    write_profile("counts");   // Useful if -px option to compiler
#endif // SHOW_COUNTS_AVAILABLE

#endif // PROFILED
    {   char *vf = (char *)vfringe,
                  *vl = (char *)vheaplimit;
        int32_t len = (int32_t)(vf - (vl - (CSL_PAGE_SIZE - 8)));
//
// Set up the current page so I can tell where the active data is.
//
        car32(vl - (CSL_PAGE_SIZE - 8)) = len;
    }
    for (pass=0; pass<2; pass++)
    {   for (j=0; j<vheap_pages_count; j++)
        {   void *page = vheap_pages[j];
            char *low = (char *)doubleword_align_up((intptr_t)page);
            char *high = low + car32(low);
            low += 8;
            while (low<high)
            {   Header h = *(Header *)low;
                if (is_symbol_header(h))
                {   LispObject e = qenv(low + TAG_SYMBOL);
                    intptr_t clen = 0;
                    uint64_t n;
                    if (is_cons(e))
                    {   e = qcar(e);
                        if (is_bps(e))
                            clen = length_of_byteheader(vechdr(e)) - CELL;
                    }
                    n = qcount(low + TAG_SYMBOL);
                    if (n != 0 && clen != 0)
                    {   double w = (double)n/(double)clen;
//
// Here I want a measure that will give a good idea of how worthwhile it
// would be to compile the given function into C - what I have chosen is
// a count of bytecodes executed scaled by the length
// of the bytestream code defining the function.  This will cause "good value"
// cases to show up best.  I scale this relative to the total across all
// functions recorded to make the numbers less sensitive to details of
// how I generate test cases.  For interest I also display the proportion
// of actual bytecodes interpreted.  In each case I record these out of
// a total of 100.0 (percent) to give comfortable ranges of numbers to admire.
//
                        if (pass == 0) itotal += (double)n, total += w;
                        else
                        {   if (w/total > 0.00001 ||
                                (double)n/itotal > 0.0001)
                            {   if ((what & 6) == 0)
                                {   if (buffp == buffn)
                                    {   buffn += 100;
                                        buff = (mapstore_item *)
                                               (*realloc_hook)((void *)buff,
                                                               sizeof(mapstore_item)*buffn);
                                        if (buff == NULL) return onevalue(nil);
                                    }
                                    buff[buffp].w = 100.0*w/total;
                                    buff[buffp].n = 100.0*(double)n/itotal;
                                    buff[buffp].n1 = n;
                                    buff[buffp].p = (LispObject)(low + TAG_SYMBOL);
                                    buffp++;
                                }
                                if ((what & 2) != 0)
                                {   LispObject w1;
// Result is a list of items ((name size bytes-executed) ...).
// You might think that I needed to push res here - but I abort if there
// is a GC, so it is not necessary after all.
//
                                    w1 = list3((LispObject)(low + TAG_SYMBOL),
                                               fixnum_of_int(clen),
                                               make_lisp_integer64(n));
                                    nil = C_nil;
                                    if (exception_pending() || gcn != gc_number)
                                        return nil;
                                    res = cons(w1, res);
                                    nil = C_nil;
                                    if (exception_pending() || gcn != gc_number)
                                        return nil;
                                }
                            }
//
// Reset count unless 1 bit of arg is set
//
                            if ((what & 1) == 0)
                            {   qcount(low + TAG_SYMBOL) = 0;
//                              if (CELL==4)
//                                  putprop((LispObject)(low+TAG_SYMBOL),
//                                          count_high,
//                                          fixnum_of_int(0));
                            }
                        }
                    }
                    low += symhdr_length;
                }
                else low += (intptr_t)doubleword_align_up(length_of_header(h));
            }
        }
    }
    if ((what & 6) == 0)
    {   double running = 0.0;
        qsort((void *)buff, buffp, sizeof(buff[0]), profile_cf);
        trace_printf("\n  Value  %%bytes (So far) MBytecodes Function name\n");
        for (j=0; j<buffp; j++)
        {   running += buff[j].n;
            trace_printf("%7.2f %7.2f (%6.2f) %9lu: ",
                         buff[j].w, buff[j].n, running,
                         (long unsigned)(buff[j].n1/10000u));
            prin_to_trace(buff[j].p);
            trace_printf("\n");
        }
        trace_printf("\n");
        (*free_hook)((void *)buff);
    }
    return onevalue(res);
}

LispObject Lmapstore0(LispObject nil, int nargs, ...)
{   argcheck(nargs, 0, "mapstore");
    return Lmapstore(nil, nil);
}

static bool reset_limit_registers(intptr_t vheap_need,
                                     intptr_t native_need,
                                     bool stack_flag)
//
// returns true if after resetting the limit registers there was
// enough space left for me to proceed. Return false on failure, ie
// need for a more genuine GC.
//
{   void *p;
    uintptr_t len;
    bool full;
//
// I wonder about the next test - memory would only really be full
// if there was enough LIVE data to fill all the available free pages,
// but what is tested here is based on the possibility that all the
// active pages are totally full. I scale up the vector page counts by
// a factor of 1.5 because fragmentation might behave differently in the
// old and new spaces so if there are some large vectors they may leave
// nasty gaps at the end of a page.
//
    full = (pages_count <=
            heap_pages_count +
            (3*(vheap_pages_count +
                native_pages_count) + 1)/2);
    if (fringe <= heaplimit)
    {   if (full) return false;
        p = pages[--pages_count];
        space_now++;
        zero_out(p);
        heap_pages[heap_pages_count++] = p;
        heaplimit = quadword_align_up((intptr_t)p);
        car32(heaplimit) = CSL_PAGE_SIZE;
        fringe = (LispObject)((char *)heaplimit + CSL_PAGE_SIZE);
        heaplimit = (LispObject)((char *)heaplimit + SPARE);
    }
    {   char *vh = (char *)vheaplimit,
                  *vf = (char *)vfringe;
        len = (uintptr_t)(vh - vf);
    }
    if (vheap_need > (intptr_t)len)
    {   char *vf, *vh;
        if (full) return false;
        p = pages[--pages_count];
        space_now++;
        zero_out(p);
        vheap_pages[vheap_pages_count++] = p;
        vf = (char *)doubleword_align_up((intptr_t)p) + 8;
        vfringe = (LispObject)vf;
        vh = vf + (CSL_PAGE_SIZE - 16);
        vheaplimit = (LispObject)vh;
        len = (uintptr_t)(vf - (vh - (CSL_PAGE_SIZE - 8)));
        car32(vh - (CSL_PAGE_SIZE - 8)) = len;
    }
    if (native_need != 0)
    {   if (full || native_pages_count >= MAX_NATIVE_PAGES - 1) return false;
        p = pages[--pages_count];
        space_now++;
        zero_out(p);
        native_pages[native_pages_count++] = p;
        native_fringe = 8;
    }
    if (stack_flag) return (stack < stacklimit);
    else return true;
}

static void tidy_fringes(void)
//
// heaplimit was SPARE bytes above the actual base of the page,
// so the next line dumps fringe somewhere where it can be found
// later on when needed while scanning a page of heap.  Similarly
// vfringe is stashed away at the end of its page.
//
{   char *fr = (char *)fringe,
         *vf = (char *)vfringe,
         *hl = (char *)heaplimit,
         *vl = (char *)vheaplimit;
    int32_t len = (int32_t)(fr - (hl - SPARE));
//
// If I used the top bit of this location to save info that a page
// was double-size then I just clobbered that information here!
//
    car32(hl - SPARE) = len;
    len = (uintptr_t)(vf - (vl - (CSL_PAGE_SIZE - 8)));
    car32(vl - (CSL_PAGE_SIZE - 8)) = (LispObject)len;
}

static void lose_dead_hashtables(void)
//
// This splices out from the list of hash tables all entries that point to
// tables that have not been marked or copied this garbage collection.
//
{   LispObject *p = &eq_hash_tables, q, r;
    while ((q = *p) != C_nil)
    {   Header h;
        r = qcar(q);
        h = vechdr(r);
        if (is_odds(h) && !is_marked_h(h)) *p = qcdr(q);
        else p = &qcdr(q);
    }
    p = &equal_hash_tables;
    while ((q = *p) != C_nil)
    {   Header h;
        r = qcar(q);
        h = vechdr(r);
        if (is_odds(h) && !is_marked_h(h)) *p = qcdr(q);
        else p = &qcdr(q);
    }
}

#ifdef HAVE_FWIN

//
// I need a way that a thread that is not synchronised with this one can
// generate a Lisp-level interrupt. I achieve that by
// letting that thread reset stacklimit. Then rather soon CSL will
// do a stackcheck() and will call reclaim with type GC_STACK.
//
// call this with
//    arg=0 to have no effect at all (!)   QUERY_INTERRUPT
//    arg=1 for a clock tick event         TICK_INTERRUPT
//    arg=2 for quiet unwind               QUIET_INTERRUPT
//    arg=3 for backtrace.                 NOISY_INTERRUPT
// in each case the previous value of the flag is returned. Note that
// I do not do a "test-and-set" here so do NOT treat this as a proper
// start at a mutex or semaphore! However if I apply a rule that the
// asynchronous (GUI) task only ever sets the flag to a non-zero value
// and only ever tests then to see if it has been reset to zero, while the
// main worker thread only reads it to check for non-zero and then
// resets it I have some degree of sanity.
//

static volatile int async_type = QUERY_INTERRUPT;

int async_interrupt(int type)
{   int prev = async_type;
    if (type != QUERY_INTERRUPT)
    {   async_type = type;
        stacklimit = stackbase;
    }
    return prev;
}

#endif // HAVE_FWIN

static void report_at_end(LispObject nil)
{   int n = heap_pages_count + vheap_pages_count;
    int n1 = n + pages_count;
    double fn = (double)n*(CSL_PAGE_SIZE/(1024.0*1024.0));
    double fn1 = (double)n1*(CSL_PAGE_SIZE/(1024.0*1024.0));
    double z = (100.0*n)/n1;
#ifdef WINDOW_SYSTEM
    {   report_space(gc_number, z);
        if (verbos_flag & 1) trace_printf(
                "At gc end about %.1f Mbytes of %.1f (%.1f%%) of heap is in use\n",
                fn, fn1, z);
    }
#else // WINDOW_SYSTEM
    if (verbos_flag & 1)
    {   trace_printf(
            "At gc end about %.1f Mbytes of %.1f (%.1f%%) of heap is in use\n",
            fn, fn1, z);
    }
#endif // WINDOW_SYSTEM
// This reports in Kbytes, and does not overflow until over 100 Gbytes
    qvalue(used_space) = fixnum_of_int((int)(1024.0*fn));
    qvalue(avail_space) = fixnum_of_int((int)(1024.0*fn1));
}

#ifdef CONSERVATIVE

//
// The conservative collector needs to cope with some ambiguous pointers.
// these must all be marked from, but the data that they seem to point to
// must not be moved since the pointer must not be changed in any way in
// case it is in fact not a pointer. To support that I need to be ready
// to track and record all the ambiguous roots. I will use a hash table
// as part of this process.
//

LispObject *C_stackbase, *C_stacktop;

void get_stacktop()
{   volatile LispObject sp;
    C_stacktop = (LispObject *)&sp;
}

//
// I want the following number to be a prime to make some hash-table
// activity work smoothly.
// the LOAD value is to let the hash table become 7/8 full before I
// give up on it.
//
#define AMBIGUOUS_CACHE_SIZE 2003U
#define AMBIGUOUS_LOAD   ((7*AMBIGUOUS_CACHE_SIZE)/8)

static LispObject ambiguous[AMBIGUOUS_CACHE_SIZE];
static int nambiguous;
static LispObject *C_stack_remaining;

static bool certainly_not_valid(LispObject p)
{   switch (p & (GC_BIT_P | 0x7))
    {   case TAG_CONS:

        case TAG_SYMBOL:
        case TAG_NUMBERS:
        case TAG_VECTOR:
        case TAG_BOXFLOAT:

        default:
            return true;
    }
}

typedef void process_ambiguous_pointer_t(LispObject x);

static void scan_ambiguous(process_ambiguous_pointer_t *fn)
{   unsigned int i;
    LispObject *s;
    for (i=0; i<AMBIGUOUS_CACHE_SIZE; i++)
    {   LispObject p = ambiguous[i];
        if (p == 0) continue;
        (*fn)(p);
    }
    for (s=C_stack_remaining; s<=C_stackbase; s++)
    {   LispObject p = *s;
        if (certainly_not_valid(p)) continue;
        (*fn)(p);
    }
}

static void cache_ambiguous()
{
//
// This sets up my hash table of ambiguous pointers and MUST be called before
// I use scan_ambiguous.
//
    unsigned int i;
    LispObject *s;
    for (i=0; i<AMBIGUOUS_CACHE_SIZE; i++) ambiguous[i] = 0;
    nambiguous = 0;
    for (s=C_stacktop; s<=C_stackbase && nambiguous<AMBIGUOUS_LOAD; s++)
    {   LispObject p = *s;
        if (certainly_not_valid(p)) continue;
        i = (unsigned int)(((uintptr_t)p) % (uintptr_t)AMBIGUOUS_CACHE_SIZE);
        for (;;)
        {   if (ambiguous[i] == 0)
            {   ambiguous[i] = p;   // enter new pointer into the table
                nambiguous++;       // count entries in the table
                break;
            }
            else if (ambiguous[i] == p) break; // seen before
//
// I make my stride through the hash table depend on the value too, but
// by having a table whose size is prime I will always eventually look in
// every location.
//
            i += 1 + (int)(((uintptr_t)p) %
                           (uintptr_t)(AMBIGUOUS_CACHE_SIZE-2));
        }
    }
}

#endif // CONSERVATIVE

LispObject use_gchook(LispObject p, LispObject arg)
{   LispObject nil = C_nil;
    LispObject g = gchook;
    if (symbolp(g) && g != unset_var)
    {   g = qvalue(g);
        if (symbolp(g) && g != unset_var && g != nil)
        {   push(p);
            Lapply1(nil, g, arg);  // Call the hook
            errexitn(1);      // the hook function failed
            pop(p);
        }
    }
    return onevalue(p);
}

static double prev_consolidated = 0.0;
static int prev_consolidated_set = 1;

bool garbage_collection_permitted = false;

#ifdef DEBUG_WITH_HASH
#define GCHASH 10000
uint32_t stackhash[GCHASH];
#endif

LispObject reclaim(LispObject p, const char *why, int stg_class, intptr_t size)
{   intptr_t i;
    clock_t t0, t1, t2, t3;
    int bottom_page_number;
    LispObject *sp, nil = C_nil;
    intptr_t vheap_need = 0, native_need = 0;
#ifdef DEBUG_GC
    term_printf("Start of a garbage collection %d\n", gc_number);
#endif // DEBUG_GC
#ifdef DEBUG_VALIDATE
    validate_all("start of gc", __LINE__, __FILE__);
#endif
#ifdef CONSERVATIVE
//
// How do I know that all callee-save registers are on the stack by the
// stage that I get to the level that C_stacktop now refers to???
//
    get_stacktop();
    trace_printf("\n=== C stack size = %5d\n", (C_stackbase-C_stacktop));
    trace_printf("\n=== C_stackbase=%p C_stacktop=%p\n",
                 (void *)C_stackbase, (void *)C_stacktop);
#endif // CONSERVATIVE
    stop_after_gc = 0;
    if (stg_class == GC_VEC || stg_class == GC_BPS) vheap_need = size;
    else if (stg_class == GC_NATIVE) native_need = size;
    already_in_gc = true;
#if defined WIN32 && !defined __CYGWIN__
    _kbhit(); // Fairly harmless anyway, but is here to let ^c get noticed
//    printf("(*)"); fflush(stdout);  // while I debug!
#endif // WIN32
    push_clock(); t0 = base_time;

#ifdef HAVE_FWIN
//
// Life is a bit horrid here. I can have two significantly different sorts of
// thing that cause this soft-GC to happen under FWIN. One is when I am in
// windowed mode and FWIN provokes an asynchronous event for me. The other is
// in non-windowed mode when my software_ticks counter overflows and does
// a somewhat similar job... but from within this worker thread. The really
// bad news is the thought of both of these active together, and so conflict
// and confusion. Fresh and careful thought about that is needed before I
// re-work this code.
//
// In non-windowed mode a problem I have is the detection of ^C interrupts.
// Under Windows I have used SetConsoleMode (and under Unix/Linux tcsetattr)
// to put the input into raw mode if it is direct from a keyboard. Thus
// the operating system will not process ^C for me.
//
    if (stg_class == GC_STACK && stacklimit == stackbase)
    {   stacklimit = savestacklimit;
        if (tick_pending)
        {   tick_pending = 0;
            heaplimit = saveheaplimit;
            vheaplimit = savevheaplimit;
            stacklimit = savestacklimit;
        }
        tidy_fringes();
        already_in_gc = false;
        pop_clock();
//
// There could, of course, be another async interrupt generated even during
// this processing and certainly by the time I get into interrupted(),
// and there could be "genuine" need for garbage collection or stack overflow
// processing at any stage.
//
        if (exception_pending()) nil = nil ^ 1;
        if (async_type == TICK_INTERRUPT)
        {   long int t = (long int)(100.0 * consolidated_time[0]);
            long int gct = (long int)(100.0 * gc_time);
            async_type = QUERY_INTERRUPT;     // accepted!
            fwin_acknowledge_tick();
#ifndef EMBEDDED
            report_time(t, gct);
#endif
            time_now = (int)consolidated_time[0];
            if ((time_limit >= 0 && time_now > time_limit) ||
                (io_limit >= 0 && io_now > io_limit))
                return resource_exceeded();
#ifdef DEBUG_VALIDATE
            validate_all("end of gc", __LINE__, __FILE__);
#endif
            return onevalue(p);
        }
//
// If the user provokes a backtrace then at present I *ALWAYS* make it
// a 100% full one. At some stage I could provide a different menu item
// to deliver a semi-quiet interrupt...
//
        else if (async_type == NOISY_INTERRUPT)
            miscflags |= BACKTRACE_MSG_BITS;
        else miscflags &= ~BACKTRACE_MSG_BITS;
        async_type = QUERY_INTERRUPT;     // accepted!
#ifdef DEBUG_VALIDATE
        validate_all("end of gc", __LINE__, __FILE__);
#endif
        return interrupted(p);
    }
    else
#else // HAVE_FWIN
    if (interrupt_pending)
    {   if (tick_pending)
        {   tick_pending = 0;
            heaplimit = saveheaplimit;
            vheaplimit = savevheaplimit;
            stacklimit = savestacklimit;
        }
        tidy_fringes();
        interrupt_pending = false;
        pop_clock();
#ifdef DEBUG_VALIDATE
        validate_all("end of gc", __LINE__, __FILE__);
#endif
        time_now = (int)consolidated_time[0];
        if ((time_limit >= 0 && time_now > time_limit) ||
            (io_limit >= 0 && io_now > io_limit))
            return resource_exceeded();
        return interrupted(p);
    }
#endif // HAVE_FWIN
    {   tidy_fringes();
        if (stg_class != GC_PRESERVE &&
            stg_class != GC_USER_HARD &&
            reset_limit_registers(vheap_need, native_need, true))
        {   already_in_gc = false;
            pop_clock();
#ifdef DEBUG_VALIDATE
            validate_all("end of gc", __LINE__, __FILE__);
#endif
            if (space_limit >= 0 && space_now > space_limit)
                return resource_exceeded();
#ifndef OLD_GCHOOK_CODE
//
// I have "soft" garbage collections - perhaps fairly frequently. I will
// only call the GC hook function around once every 30 seconds to avoid undue
// overhead in it.
//
            if (!prev_consolidated_set)
            {   prev_consolidated = consolidated_time[0];
                prev_consolidated_set = 1;
            }
            if (consolidated_time[0] > prev_consolidated + 30.0)
            {   prev_consolidated = consolidated_time[0];
                return use_gchook(p, nil); // Soft GC
            }
            return onevalue(p);
#else
            return use_gchook(p, nil);
#endif
        }
    }

    if (stack >= stacklimit)
    {   if (stacklimit != stackbase)
        {   stacklimit = &stacklimit[50];  // Allow a bit of slack
            pop_clock();
            return error(0, err_stack_overflow);
        }
    }

#ifdef MEMORY_TRACE
#ifndef CHECK_ONLY
    identify_page_types();
    memory_comment(4);
#endif // CHECK_ONLY
#endif // MEMORY_TRACE

//
// There are parts of the code in setup/restart where perhaps things are not
// yet in a consistent state and so any attempt at garbage collection could
// cause chaos. So during them I set a flag that I test here! Since this
// should never be triggered I am happy to leave it in state where the only
// sane way to respond to it is to run under a debugger and set breakpoints.
//
    if (!garbage_collection_permitted)
    {   fprintf(stderr,
                "\n+++ Garbage collection attempt when not permitted\n");
        my_exit(EXIT_FAILURE);    // totally drastic...
    }

    push(p);

    gc_number++;
#ifdef DEBUG_VALIDATE
    validate_all("continuation of gc", __LINE__, __FILE__);
#endif

#ifdef WINDOW_SYSTEM
//
// If I have a window system I tell it the current time every so often
// just to keep things cheery...
//
    {   long int t = (long int)(100.0 * consolidated_time[0]);
        long int gct = (long int)(100.0 * gc_time);
// @@@@
// I guess that I want garbage collection messages, if any, to
// be sent to stderr rather than whatever output stream happens to
// be selected at the time of the garbage collection?
// At present messages go to the normal output stream, which only makes
// sense if GC messages are almost always disabled - maybe that will
// be the case!
//
#ifndef EMBEDDED
        report_time(t, gct);
#endif
        time_now = (int)consolidated_time[0];
        if (verbos_flag & 1)
        {   freshline_trace();
            trace_printf(
                "+++ Garbage collection %ld (%s) after %ld.%.2ld+%ld.%.2ld seconds\n",
                (long)gc_number, why, t/100, t%100, gct/100, gct%100);
#ifdef DEBUG
            if (reclaim_trap_count >= 0)
                trace_printf("Will trap at GC %d. ", reclaim_trap_count);
#endif
        }
    }
#else // WINDOW_SYSTEM
    if (verbos_flag & 1)
    {   long int t = (long int)(100.0 * consolidated_time[0]);
        long int gct = (long int)(100.0 * gc_time);
// @@@@
// I guess that I want garbage collection messages, if any, to
// be sent to stderr rather than whatever output stream happens to
// be selected at the time of the garbage collection?
// At present messages go to the normal output stream, which only makes
// sense if GC messages are almost always disabled - maybe that will
// be the case!
//
        time_now = (int)consolidated_time[0];
        if ((time_limit >= 0 && time_now > time_limit) ||
            (io_limit >= 0 && io_now > io_limit))
            return resource_exceeded();
        freshline_trace();
        trace_printf(
            "+++ Garbage collection %ld (%s) after %ld.%.2ld+%ld.%.2ld seconds\n",
            (long)gc_number, why, t/100, t%100, gct/100, gct%100);
    }
#endif // WINDOW_SYSTEM
//
// If things crash really badly maybe I would rather have my output up
// to date.
//
    ensure_screen();
    nil = C_nil;
    if (exception_pending())
    {   stop_after_gc = 1;
        flip_exception();
    }
    if (spool_file != NULL) fflush(spool_file);
    if (gc_number == reclaim_trap_count)
    {   reclaim_trap_count = gc_number - 1;
        trace_printf("\nReclaim trap count reached...\n");
        return aerror("reclaim-trap-count");
    }
    if (reclaim_stack_limit != 0 &&
        (uintptr_t)&t0 + reclaim_stack_limit < (uintptr_t)C_stack_base)
    {   reclaim_stack_limit = 0;
        trace_printf("\nReclaim stack limit reached...\n");
        return aerror("reclaim-stack-limit");
    }

    for (int i=0; i<LOG2_VECTOR_CHUNK_WORDS+1; i++)
        free_vectors[i] = 0;

#ifdef CONSERVATIVE
//
// if stg_class==GC_PRESERVE I will not need to process the C stack and
// the Lisp stack ought to be empty. Otherwise here is where I start to
// capture the set of ambiguous pointers that are in play.
//
    if (stg_class != GC_PRESERVE)
    {   cache_ambiguous();
    }
#endif // CONSERVATIVE

    copy_into_nilseg(false);
#ifdef DEBUG_VALIDATE
    printf("Validating at start of GC\n");
    validate_all("gc start", __LINE__, __FILE__);
#endif

    cons_cells = symbol_heads = strings = user_vectors =
            big_numbers = box_floats = bytestreams = other_mem =
                                           litvecs = getvecs = 0;

    {
//
// Here I need to sort of what sort of GC I should do. In the new world
// here I should do a conservative mostly-copying one most of the time, but
// the GC from "preserve" can afford to be a full and proper one that
// does not worry about junk on the C stack, that can assume everything it
// finds in a List Base is a valid Lisp object and so it can compact
// perfectly.
//
        t2 = t1 = t0;   // Time is not split down in this case
//
// Set up the new half-space initially empty.
//
        new_heap_pages_count = 0;
        new_vheap_pages_count = 0;
        trailing_heap_pages_count = 1;
        trailing_vheap_pages_count = 1;
        {   void *pp = pages[--pages_count];
            char *vf, *vl;
            int32_t len;
//
// A first page of (cons-)heap
//
            zero_out(pp);
            new_heap_pages[new_heap_pages_count++] = pp;
            heaplimit = quadword_align_up((intptr_t)pp);
            car32(heaplimit) = CSL_PAGE_SIZE;
            vl = (char *)heaplimit;
            fringe = (LispObject)(vl + CSL_PAGE_SIZE);
            heaplimit = (LispObject)(vl + SPARE);
#ifdef DEBUG_GC
            term_printf("fr = %p, hl = %p\n", (void *)fringe, (void *)heaplimit);
#endif // DEBUG_GC
//
// A first page of vector heap.
//
            pp = pages[--pages_count];
            zero_out(pp);
            new_vheap_pages[new_vheap_pages_count++] = pp;
            vf = (char *)doubleword_align_up((intptr_t)pp) + 8;
            vfringe = (LispObject)vf;
            vl = vf + (CSL_PAGE_SIZE - 16);
            vheaplimit = (LispObject)vl;
            len = (uintptr_t)(vf - (vl - (CSL_PAGE_SIZE - 8)));
            car32(vl - (CSL_PAGE_SIZE - 8)) = (LispObject)len;
        }

//
// The very first thing that I will copy will be the main object-vector,
// this is done early to ensure that it gets a full empty page of vector
// heap to fit into.
//
#ifdef DEBUG_GC
        term_printf("About to copy the object vector\n");
#endif // DEBUG_GC
        copy(&BASE[current_package_offset]);
//
// The above line is "really"
//          copy(&current_package);
// but I use an offset into the nilseg in explicit form because otherwise
// there is confusion between the real and copied location of the pointer
// to the package.
//

//
// I should remind you, gentle reader, that the value cell
// and env cells of nil will always contain nil, which does not move,
// and so I do not need to copy them here.
//
#ifdef DEBUG_GC
        term_printf("About to copy NIL\n");
#endif // DEBUG_GC
        copy(&(qplist(nil)));
        copy(&(qpname(nil)));
        copy(&(qfastgets(nil)));
        copy(&(qpackage(nil)));

//
// I dislike the special treatment of current_package that follows. Maybe
// I should arrange something totally different for copying the package
// structure...
//
        for (i = first_nil_offset; i<last_nil_offset; i++)
        {
            if (i != current_package_offset)
            {   // current-package - already copied by hand
#ifdef DEBUG_GC
                term_printf("About to copy list-base %d\n", i);
#endif // DEBUG_GC
                copy(&BASE[i]);
            }
        }

#ifdef DEBUG_GC
        term_printf("About to copy the stack\n");
#endif // DEBUG_GC
        for (sp=stack; sp>(LispObject *)stackbase; sp--) copy(sp);
#ifdef DEBUG_GC
        term_printf("Stack processed\n");
#endif // DEBUG_GC
//
// Now I need to perform some magic on the list of hash tables...
//
        lose_dead_hashtables();
// When I have transitions to the new hash table scheme the two lists
// processed specially here become redundant and this fragment of code can
// go, I think.
#ifdef DEBUG_GC
        term_printf("About to copy eq hash tables\n");
#endif // DEBUG_GC
        copy(&eq_hash_tables);
#ifdef DEBUG_GC
        term_printf("About to copy equal hash tables\n");
#endif // DEBUG_GC
        copy(&equal_hash_tables);

#ifdef DEBUG_GC
        term_printf("About to tidy fringes and finish up\n");
#endif // DEBUG_GC
        tidy_fringes();

//
// Throw away the old semi-space - it is now junk.
//
        while (heap_pages_count!=0)
            pages[pages_count++] = heap_pages[--heap_pages_count];
        while (vheap_pages_count!=0)
            pages[pages_count++] = vheap_pages[--vheap_pages_count];

//
// Flip the descriptors for the old and new semi-spaces.
//
        {   void **w = heap_pages;
            heap_pages = new_heap_pages;
            new_heap_pages = w;
            w = vheap_pages;
            vheap_pages = new_vheap_pages;
            new_vheap_pages = w;
            heap_pages_count = new_heap_pages_count;
            new_heap_pages_count = 0;
            vheap_pages_count = new_vheap_pages_count;
            new_vheap_pages_count = 0;
        }
    }

    LispObject qq;
//
// Note that EQUAL hash tables do not need to be rehashed here, though
// they do if a heap image is exported from one system to another.
//
    for (qq = eq_hash_tables; qq!=nil; qq=qcdr(qq))
        rehash_this_table(qcar(qq));

    gc_time += pop_clock();
    t3 = base_time;

#ifdef DEBUG_VALIDATE
    validate_all("gc end", __LINE__, __FILE__);
#endif

#ifdef DEBUG_WITH_HASH
        for (sp=stack; sp>(LispObject *)stackbase; sp--)
        {   int n = sp - (LispObject *)stackbase;
            uint32_t hh;
            if (n < GCHASH)
            {   if (stackhash[n] != (hh = hash_for_checking(*sp, 0)))
                {   printf("@@@Stack offset %d was %x now %x\n",
                        n, stackhash[n], hh);
                }
            }
        }
#endif

    copy_out_of_nilseg(false);

    if ((verbos_flag & 5) == 5)
//
// (verbos 4) gets the system to tell me how long each phase of GC took,
// but (verbos 1) must be ORd in too.
//
    {   
        trace_printf("Copy %ld ms\n",
                     (long int)(1000.0 * (double)(t3-t0)/(double)CLOCKS_PER_SEC));
    }

// (verbos 5) causes a display breaking down how space is used
    if ((verbos_flag & 5) == 5)
    {   trace_printf(
            "cons_cells=%" PRIdPTR ", symbol_heads=%" PRIdPTR ", strings=%" PRIdPTR ", user_vectors=%" PRIdPTR "\n",
            cons_cells, symbol_heads, strings, user_vectors-litvecs-getvecs);
        trace_printf(
            "bignums=%" PRIdPTR ", floats=%" PRIdPTR ", bytestreams=%" PRIdPTR ", other=%" PRIdPTR ", litvecs=%d\n",
            big_numbers, box_floats, bytestreams, other_mem, litvecs);
        trace_printf("getvecs=%" PRIdPTR " C-stacks=%" PRIdPTR "K Lisp-stack=%" PRIdPTR "K\n",
                     getvecs, ((C_stack_base-(char *)&sp)+1023)/1024,
                     (intptr_t)((stack-stackbase)+1023)/1024);
    }

    pop(p);

#ifndef MEMORY_TRACE
//
// Here I grab more memory (if I am allowed to).
// An initial version here, and one still suitable on machines that will
// have plenty of real memory, will be to defined ok_to_grab_memory(n) as
// 3*n + 2. This expands until the proportion of the heap active at the
// end of garbage collection is less than 1/4.
// If the attempt to grab more memory fails I clear the bit in init_flags
// that allows me to try to expand, so I will not waste time again.  If
// HOLD_BACK_MEMORY was asserted (for machines where grabbing all seemingly
// available memory may cause a crash) I do not try this operation.  The
// aim of keeping the heap less than half full is an heuristic and could be
// adjusted on the basis of experience with this code.
// The "+2" at the end of calculating the ideal heap size is intended
// to keep us (mostly) in the copying GC domain.  If it is omitted the
// heap tends to stay just 25% full and sliding GC is used. Overall this is
// roughly as expensive as copying, but it is more disruptive since it comes
// in larger gulps.
// On systems where it is possible to measure the amount of available
// real memory more sophisticated calculations may be possible.
//
    if (init_flags & INIT_EXPANDABLE)
    {   int ideal = ok_to_grab_memory(heap_pages_count + vheap_pages_count);
        int more;
        if (ideal > MAX_PAGES) ideal = MAX_PAGES;
        if (max_store_size != 0.0)
        {   double page_limit = max_store_size*1024*1024/(double)CSL_PAGE_SIZE;
// Limit memory to (about) the amount the user indicated with --max-mem
            int plim = (int)page_limit;
            if (ideal > plim) ideal = plim;
        }
        more = ideal - pages_count;
        while (more-- > 0)
        {   void *page = (void *)my_malloc((size_t)(CSL_PAGE_SIZE + 8));
            intptr_t pun, pun1;
//
// When I first grabbed memory in restart.c I used my_malloc_1(), which
// gobbles a large stack frame and then called regular malloc - the idea
// there was to avoid malloc grabbing space needed for the stack. I can
// not properly do that here since reclaim() may be called with a deep
// stack already active.  There is thus a danger that expanding the heap here
// may cause me to run out of stack elsewhere.  Oh well, I guess I can not
// win in all ways.
//
//
// Verify that new block does not span zero & has correct sign bit
//
            pun = (intptr_t)page;
            pun1 = (intptr_t)((char *)page + CSL_PAGE_SIZE + 8);
            if ((pun ^ pun1) < 0) page = NULL;
            if ((pun + address_sign) < 0) page = NULL;
            if (page == NULL)
            {   init_flags &= ~INIT_EXPANDABLE;
                break;
            }
            else pages[pages_count++] = page;
        }
    }
#endif // MEMORY_TRACE
    if (!reset_limit_registers(vheap_need, native_need, false))
    {   if (stack < stacklimit || stacklimit != stackbase)
        {   report_at_end(nil);
            term_printf("\n+++ No space left at all\n");
            my_exit(EXIT_FAILURE);    // totally drastic...
        }
    }
    report_at_end(nil);
#ifdef DEBUG_VALIDATE
    validate_all("end of gc", __LINE__, __FILE__);
#endif
    if (stop_after_gc)
    {
#ifdef MEMORY_TRACE
#ifndef CHECK_ONLY
        memory_comment(15);
#endif // CHECK_ONLY
#endif // MEMORY_TRACE
        return Lstop(nil, fixnum_of_int(0));
    }
#ifdef MEMORY_TRACE
#ifndef CHECK_ONLY
    memory_comment(15);
#endif // CHECK_ONLY
#endif // MEMORY_TRACE
    if (interrupt_pending)
    {   interrupt_pending = false;
        already_in_gc = false;
        tick_on_gc_exit = false;
        return interrupted(p);
    }
    already_in_gc = false;
    if ((space_limit >= 0 && space_now > space_limit) ||
        (time_limit >= 0 && time_now > time_limit) ||
        (io_limit >= 0 && io_now > io_limit))
        return resource_exceeded();
#ifndef OLD_GCHOOK_CODE
    prev_consolidated = consolidated_time[0];
#endif
    return use_gchook(p, lisp_true);
}

// end of file cslgc.cpp
