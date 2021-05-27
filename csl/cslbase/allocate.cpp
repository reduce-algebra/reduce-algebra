// allocate.cpp                            Copyright (C) 1989-2021 Codemist

//
// Code to deal with storage allocation, both grabbing memory at the start
// or a run and significant aspects of garbage collection.
//

/**************************************************************************
 * Copyright (C) 2021, Codemist.                         A C Norman       *
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

/*!!! csl
*/

#include "headers.h"

#ifndef WIN32
#include <unistd.h>
#include <sys/mman.h>
#endif // !WIN32

uintptr_t lfringe;
uintptr_t lheaplimit;
uintptr_t vfringe;
uintptr_t vheaplimit;

uintptr_t *C_stackbase;


void garbage_collect()
{   term_printf("\nGarbage collect here. Not yet implemented\n");
    my_abort();
}

char *big_chunk_start, *big_chunk_end;

// the "pages" considered here are of size CSL_PAGE_SIZE

void **pages,
     **heap_pages,
     **vheap_pages;
void **new_heap_pages,
     **new_vheap_pages;

size_t pages_count,
       heap_pages_count,
       vheap_pages_count,
       new_heap_pages_count,
       new_vheap_pages_count;

void *allocate_page(const char *why)
{   if (pages_count == 0) fatal_error(err_no_store);
    return pages[--pages_count];
}

void init_heap_segments(double store_size)
// This function just makes nil and the pool of page-frames available.
// The store-size is passed in units bytes, and as a double not
// an integer so that overflow is not an issue.
{
    pages = new (std::nothrow) void *[MAX_PAGES];
    heap_pages = new (std::nothrow) void *[MAX_PAGES];
    vheap_pages = new (std::nothrow) void *[MAX_PAGES];
    new_heap_pages = new (std::nothrow) void *[MAX_PAGES];
    new_vheap_pages = new (std::nothrow) void *[MAX_PAGES];
    if (pages == nullptr ||
        new_heap_pages == nullptr ||
        new_vheap_pages == nullptr ||
        heap_pages == nullptr ||
        vheap_pages == nullptr)
    {   fatal_error(err_no_store);
    }

    {   size_t free_space = INITIAL_HEAPSIZE;
        size_t request = (size_t)store_size;
// By doing this in size_t I should avoid overflow
        if (request != 0) free_space = request;
        free_space = free_space/(CSL_PAGE_SIZE+4);
        if (free_space > MAX_PAGES) free_space = MAX_PAGES;
        pages_count = heap_pages_count = vheap_pages_count = 0;
        nilsegment = nullptr;
        {   size_t n = (size_t)(NIL_SEGMENT_SIZE+free_space*CSL_PAGE_SIZE);
// I try to get the whole of the initial hunk of memory that I need in
// one gulp since that (maybe) gives me the best chance to obtain all
// the memory in just one half of my address space.
            char *pool = reinterpret_cast<char *>(
                new (std::nothrow) Align8[n/8]);
            if (pool != nullptr)
            {   big_chunk_start = reinterpret_cast<char *>(pool);
                big_chunk_end = big_chunk_start + (n-1);
                nilsegment = reinterpret_cast<LispObject *>(pool);
                pool = pool + NIL_SEGMENT_SIZE;
#ifdef COMMON
// NB here that NIL is tagged as a CONS not as a symbol
                nil = static_cast<LispObject>((uintptr_t)nilsegment + TAG_CONS + 8);
#else
                nil = static_cast<LispObject>((uintptr_t)nilsegment + TAG_SYMBOL);
#endif
// If at the end of the run I am going to free some space I had better not
// free these pages. When I free the nilsegment they all get discarded at
// once.
                while (pages_count < free_space)
                {   void *page =
// Ha Ha - for some long while I had a bug whereby I missed out the cast
// to size_t here and as a result if you asked for over 4G of memory
// there was an integer overflow in the subscript calculation leading to
// reasonably obscure disaster.
                        reinterpret_cast<void *>(&pool[pages_count*
                                                       (size_t)CSL_PAGE_SIZE]);
                    pages[pages_count++] = page;
                }
            }
        }
    }

// If the user had asked for an oversize stack it has to be allocated
// independently here anyway.
    if (nilsegment != nullptr && pages_count > 0)
    {   if (stack_segsize != 1)
        {   stacksegment =
                reinterpret_cast<LispObject *>(
                    new (std::nothrow) Align8[stack_segsize*CSL_PAGE_SIZE/8]);
            if (stacksegment == nullptr) fatal_error(err_no_store);
        }
        else stacksegment = reinterpret_cast<LispObject *>(pages[--pages_count]);
    }
    else
    {   std::printf("pages_count <= 0 = %d\n",
                    static_cast<int>(pages_count));
        fatal_error(err_no_store);
    }
    stackBase = reinterpret_cast<LispObject *>(stacksegment);
}

inline bool is_in_big_chunk(void *p)
{   return (reinterpret_cast<char *>(p) >= big_chunk_start &&
            reinterpret_cast<char *>(p) <= big_chunk_end);
}

static void abandon(void *p[], int32_t n)
{   while (n != 0)
    {   void *w = p[--n];
// The test here that avoids calling free on a nullptr pointer is
// certainly not needed with an ANSI compliant library - but
// rumour has it that many Unix libraries are unkind in this
// respect, and the test is pretty cheap... Also pages within the
// "big chunk" should not be released this way because they will
// all be recycled in one go when the whole chunk is freed. Note that
// the whole of the "big chunk" tends to get allocated as part of the
// segment that contans nil.
        if (w != nullptr && !is_in_big_chunk(w))
            delete [] reinterpret_cast<Align8 *>(w);
    }
}

void drop_heap_segments()
{   abandon(pages,           pages_count);
    abandon(heap_pages,      heap_pages_count);
    abandon(vheap_pages,     vheap_pages_count);
}

// This allocates another page of memory if that is allowed and if it is
// possible. It returns true on success.

bool allocate_more_memory()
{   if ((init_flags & INIT_EXPANDABLE) == 0) return false;
    if (max_store_size != 0.0)
    {   double page_limit =
            max_store_size/static_cast<double>(CSL_PAGE_SIZE);
        if (pages_count+heap_pages_count+vheap_pages_count >=
            (size_t)page_limit)
        {   init_flags &= ~INIT_EXPANDABLE;
            return false;
        }
    }
    void *page = reinterpret_cast<void *>(
        new (std::nothrow) Align8[CSL_PAGE_SIZE/8]);
    if (page == nullptr)
    {   init_flags &= ~INIT_EXPANDABLE;
        return false;
    }
    else
    {   pages[pages_count++] = page;
        return true;
    }
}

void grab_more_memory(size_t npages)
{
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
// On systems where it is possible to measure the amount of available
// real memory more sophisticated calculations may be possible.
    if ((init_flags & INIT_EXPANDABLE) != 0)
    {   size_t ideal =
            ok_to_grab_memory(heap_pages_count + vheap_pages_count);
// ideal is now liable to be about 3 times the amount of current active
// memory, and is the amount that I would like to have free at the end
// of this GC.
        ideal += heap_pages_count + vheap_pages_count; // ideal total space
// I have an architectural limit (well one based on the size of a vector..).
// On a 32-bit system I could cope with up to 2GB (but almost certainly I can
// not allocate that much, while on a 64-bit platform I allow for up to
// 2TB which is larger than I expect to encounter for a few years yet (2019).
        if (ideal > MAX_PAGES) ideal=MAX_PAGES;
// Also the user may have set a limit.
        if (max_store_size != 0.0)
        {   size_t plim = (size_t)(max_store_size/static_cast<double>
                                   (CSL_PAGE_SIZE));
            if (ideal > plim) ideal = plim;
        }
        while (ideal > pages_count+heap_pages_count+vheap_pages_count)
        {   if (!allocate_more_memory()) break;
        }
    }
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

// All this stuff with setcar and setcdr is bacause while a new bit of
// structure is being created no other thread can possibly have access
// to the new data, and so the ordering of memory transactions can be
// "relaxed". So setcar/set

LispObject cons(LispObject a, LispObject b)
{
#ifdef DEBUG
    if (is_exception(a) || is_exception(b))
        my_abort("exception value not trapped");
#endif // DEBUG
    LispObject r = static_cast<LispObject>(lfringe -= sizeof(Cons_Cell));
// As coded here I MUST have a safety margin such that at least 4 CONS
// cells can always be allocated. If I put the lheaplimit check before the
// code to write car and cdr fields in I would not need that, but then
// I would need to arrange (or be confident that) the arguments a and b
// would be safe across the garbage collection and I would need to write
// them in place after it.
    r += TAG_CONS;
    setcar(r, a);
    setcdr(r, b);
// cons_forced() always returns false unless this is a debug build. When it
// is a debug build the extra cost does not worry me. The scheme can then be
// used to trigger a full garbage collection after exactly some known number
// of CONS operations have been performed, and that may be a valuable
// capability when garbage collector bugs might relate to the exact place
// where the garbage collector was called from.
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        (uintptr_t)r < (uintptr_t)lheaplimit ||
        cons_forced(1))
        return reclaim(r, "internal cons", GC_CONS, 0);
    else return r;
}

LispObject cons_no_gc(LispObject a, LispObject b)
{
    LispObject r = static_cast<LispObject>(lfringe -= sizeof(Cons_Cell));
    r += TAG_CONS;
    setcar(r, a);
    setcdr(r, b);
    return r;
}

// cons_gc_test() MUST be called after any sequence of cons_no_gc() calls.

LispObject cons_gc_test(LispObject p)
{   if (++reclaim_trigger_count == reclaim_trigger_target ||
        (uintptr_t)lfringe <= (uintptr_t)lheaplimit)
        return reclaim(p, "cons gc test", GC_CONS, 0);
    else return p;
}

LispObject ncons(LispObject a)
{
    LispObject r = static_cast<LispObject>(lfringe -= sizeof(Cons_Cell));
    r += TAG_CONS;
    setcar(r, a);
    setcdr(r, nil);
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        (uintptr_t)r < (uintptr_t)lheaplimit || cons_forced(1))
        return reclaim(r, "internal ncons", GC_CONS, 0);
    else return r;
}

LispObject list2(LispObject a, LispObject b)
{
// Note that building two cons cells at once saves some overhead here
    LispObject r = static_cast<LispObject>(lfringe -= 2*sizeof(Cons_Cell));
    r += TAG_CONS;
    setcar(r, a);
    setcdr(r, r + sizeof(Cons_Cell));
    setcar(r+sizeof(Cons_Cell), b);
    setcdr(r+sizeof(Cons_Cell), nil);
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        (uintptr_t)r < (uintptr_t)lheaplimit || cons_forced(2))
        return reclaim(r, "internal list2", GC_CONS, 0);
    else return r;
}

LispObject list2star(LispObject a, LispObject b, LispObject c)
{
    LispObject r = static_cast<LispObject>(lfringe -= 2*sizeof(Cons_Cell));
    r += TAG_CONS;
    setcar(r, a);
    setcdr(r,  r + sizeof(Cons_Cell));
    setcar(r+sizeof(Cons_Cell), b);
    setcdr(r+sizeof(Cons_Cell), c);
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        (uintptr_t)r < (uintptr_t)lheaplimit || cons_forced(2))
        return reclaim(r, "internal list2*", GC_CONS, 0);
    else return r;
}

LispObject list2starrev(LispObject c, LispObject b, LispObject a)
{
    LispObject r = static_cast<LispObject>(lfringe -= 2*sizeof(Cons_Cell));
    r += TAG_CONS;
    setcar(r, a);
    setcdr(r, r + sizeof(Cons_Cell));
    setcar(r+sizeof(Cons_Cell), b);
    setcdr(r+sizeof(Cons_Cell), c);
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        (uintptr_t)r < (uintptr_t)lheaplimit || cons_forced(2))
        return reclaim(r, "internal list2*", GC_CONS, 0);
    else return r;
}

LispObject list3star(LispObject a, LispObject b, LispObject c,
                     LispObject d)
{
    LispObject r = static_cast<LispObject>(lfringe -= 3*sizeof(Cons_Cell));
    r += TAG_CONS;
    setcar(r, a);
    setcdr(r, r + sizeof(Cons_Cell));
    setcar(r+sizeof(Cons_Cell), b);
    setcdr(r+sizeof(Cons_Cell),
           r + 2*sizeof(Cons_Cell));
    setcar(r+2*sizeof(Cons_Cell), c);
    setcdr(r+2*sizeof(Cons_Cell), d);
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        (uintptr_t)r < (uintptr_t)lheaplimit || cons_forced(3))
        return reclaim(r, "internal list3*", GC_CONS, 0);
    else return r;
}

LispObject list4(LispObject a, LispObject b, LispObject c,
                 LispObject d)
{
    LispObject r = static_cast<LispObject>(lfringe -= 4*sizeof(Cons_Cell));
    r += TAG_CONS;
    setcar(r, a);
    setcdr(r, r + sizeof(Cons_Cell));
    setcar(r+sizeof(Cons_Cell), b);
    setcdr(r+sizeof(Cons_Cell),
           r + 2*sizeof(Cons_Cell));
    setcar(r+2*sizeof(Cons_Cell), c);
    setcdr(r+2*sizeof(Cons_Cell),
           r + 3*sizeof(Cons_Cell));
    setcar(r + 3*sizeof(Cons_Cell), d);
    setcdr(r + 3*sizeof(Cons_Cell), nil);
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        (uintptr_t)r < (uintptr_t)lheaplimit || cons_forced(4))
        return reclaim(r, "internal list4", GC_CONS, 0);
    else return r;
}



LispObject acons(LispObject a, LispObject b, LispObject c)
{
    LispObject r = static_cast<LispObject>(lfringe -= 2*sizeof(Cons_Cell));
    r += TAG_CONS;
    setcar(r, r + sizeof(Cons_Cell));
    setcdr(r, c);
    setcar(r+sizeof(Cons_Cell), a);
    setcdr(r+sizeof(Cons_Cell), b);
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        (uintptr_t)r < (uintptr_t)lheaplimit || cons_forced(2))
        return reclaim(r, "internal acons", GC_CONS, 0);
    else return r;
}

LispObject acons_no_gc(LispObject a, LispObject b, LispObject c)
{
    LispObject r = static_cast<LispObject>(lfringe -= 2*sizeof(Cons_Cell));
    r += TAG_CONS;
    setcar(r, r + sizeof(Cons_Cell));
    setcdr(r, c);
    setcar(r+sizeof(Cons_Cell), a);
    setcdr(r+sizeof(Cons_Cell), b);
    return r;
}

LispObject list3(LispObject a, LispObject b, LispObject c)
{
    LispObject r = static_cast<LispObject>(lfringe -= 3*sizeof(Cons_Cell));
    r += TAG_CONS;
    setcar(r, a);
    setcdr(r, r + sizeof(Cons_Cell));
    setcar(r+sizeof(Cons_Cell), b);
    setcdr(r+sizeof(Cons_Cell),
           r + 2*sizeof(Cons_Cell));
    setcar(r + 2*sizeof(Cons_Cell), c);
    setcdr(r + 2*sizeof(Cons_Cell), nil);
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        (uintptr_t)r < (uintptr_t)lheaplimit || cons_forced(3))
        return reclaim(r, "internal list3", GC_CONS, 0);
    else return r;
}

LispObject list3rev(LispObject c, LispObject b, LispObject a)
{
    LispObject r = static_cast<LispObject>(lfringe -= 3*sizeof(Cons_Cell));
    r += TAG_CONS;
    setcar(r, a);
    setcdr(r, r + sizeof(Cons_Cell));
    setcar(r + sizeof(Cons_Cell), b);
    setcdr(r + sizeof(Cons_Cell),
           r + 2*sizeof(Cons_Cell));
    setcar(r + 2*sizeof(Cons_Cell), c);
    setcdr(r + 2*sizeof(Cons_Cell), nil);
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        (uintptr_t)r < (uintptr_t)lheaplimit || cons_forced(3))
        return reclaim(r, "internal list3", GC_CONS, 0);
    else return r;
}

LispObject Lcons(LispObject, LispObject a, LispObject b)
{
    LispObject r = static_cast<LispObject>(lfringe -= sizeof(Cons_Cell));
    r += TAG_CONS;
    setcar(r, a);
    setcdr(r, b);
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        (uintptr_t)r < (uintptr_t)lheaplimit || cons_forced(1))
        return onevalue(reclaim(r, "cons", GC_CONS, 0));
    else return onevalue(r);
}

LispObject Lxcons(LispObject, LispObject a, LispObject b)
{
    LispObject r = static_cast<LispObject>(lfringe -= sizeof(Cons_Cell));
    r += TAG_CONS;
    setcar(r, b);
    setcdr(r, a);
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        (uintptr_t)r < (uintptr_t)lheaplimit || cons_forced(1))
        return onevalue(reclaim(r, "xcons", GC_CONS, 0));
    else return onevalue(r);
}

LispObject Lnilfn(LispObject)
{   return onevalue(nil);
}

LispObject Lncons(LispObject env, LispObject a)
{
    LispObject r = static_cast<LispObject>(lfringe -= sizeof(Cons_Cell));
    r += TAG_CONS;
    setcar(r, a);
    setcdr(r, nil);
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        (uintptr_t)r < (uintptr_t)lheaplimit || cons_forced(1))
        return onevalue(reclaim(r, "ncons", GC_CONS, 0));
    else return onevalue(r);
}

LispObject get_symbol(bool gensymp)
{   return get_basic_vector(TAG_SYMBOL, TYPE_SYMBOL, symhdr_length);
}

LispObject get_basic_vector(int tag, int type, size_t size)
{
// tag is the value (e.g. TAG_VECTOR) that will go in the low order
// 3 bits of the pointer result.
// type is the code (e.g. TYPE_STRING) that gets packed, together with
// the size, into a header word.
// size is measured in bytes and must allow space for the header word.
// [Note that this last issue - size including the header - was probably
// a mistake since the header size depends on whether I am using a
// 32-bit or 64-bit representation. However it would be hard to unwind
// that now!]
    size_t alloc_size = (size_t)doubleword_align_up(size);
// Basic vectors must be smaller then the CSL page size.
    if (alloc_size > (CSL_PAGE_SIZE - 32))
        return aerror1("request for basic vector too big",
                fixnum_of_int(alloc_size/CELL-1));
    for (;;)
    {   uintptr_t r = (vfringe += alloc_size) - alloc_size;
        if (++reclaim_trigger_count == reclaim_trigger_target ||
            (r + alloc_size) > vheaplimit ||
            vec_forced(alloc_size/CELL))
        {   vfringe = r;
            char msg[40];
// I go to a whole load of trouble here to tell the user what sort of
// vector request provoked this garbage collection.  I wonder if the user
// really cares - but I do very much when I am chasing after GC bugs!
            switch (tag)
            {   case TAG_SYMBOL:
                    std::sprintf(msg, "symbol header");
                    break;
                case TAG_NUMBERS:
                    switch (type)
                    {   case TYPE_BIGNUM:
                            std::sprintf(msg, "bignum(%ld)", static_cast<long>(size));
                            break;
                        default:
                            std::sprintf(msg, "numbers(%lx,%ld)", static_cast<long>(type),
                                         static_cast<long>(size));
                            break;
                    }
                    break;
                case TAG_VECTOR:
                    switch (type)
                    {   case TYPE_STRING_1:
                        case TYPE_STRING_2:
                        case TYPE_STRING_3:
                        case TYPE_STRING_4:
                            std::sprintf(msg, "string(%ld)", static_cast<long>(size));
                            break;
                        case TYPE_BPS_1:
                        case TYPE_BPS_2:
                        case TYPE_BPS_3:
                        case TYPE_BPS_4:
                            std::sprintf(msg, "BPS(%ld)", static_cast<long>(size));
                            break;
                        case TYPE_SIMPLE_VEC:
                            std::sprintf(msg, "simple vector(%ld)", static_cast<long>(size));
                            break;
                        case TYPE_HASH:
                            std::sprintf(msg, "hash table(%ld)", static_cast<long>(size));
                            break;
                        default:
                            std::sprintf(msg, "vector(%lx,%ld)", static_cast<long>(type),
                                         static_cast<long>(size));
                            break;
                    }
                    break;
                case TAG_BOXFLOAT:
                    std::sprintf(msg, "float(%ld)", static_cast<long>(size));
                    break;
                default:
                    std::sprintf(msg, "get_basic_vector(%lx,%ld)", static_cast<long>(tag),
                                 static_cast<long>(size));
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
        *reinterpret_cast<Header *>(r) = type + (size <<
                                         (Tw+5)) + TAG_HDR_IMMED;
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
            *reinterpret_cast<LispObject *>(vfringe-CELL) = 0;
        return static_cast<LispObject>(r + tag);
    }
}

// This takes a vector (which can be one represented using an INDEXVEC)
// and reduces its size to a total value len. It returns the shorter
// vector. Only used on simple vectors.

LispObject reduce_basic_vector_size(LispObject v, size_t len)
{   setvechdr(v, TYPE_SIMPLE_VEC + (len << (Tw+5)) + TAG_HDR_IMMED);
    return v;
}

// The next functions (eg borrow_vector) are called just like the
// functions that allocate new vectors, but they use space in the part
// of memory space not at present in use by the garbage collector. If a
// copying garbage collection triggered "right now" were to be able to
// succeed there must be enough reserved space to make this possible provided
// I only borrow space sufficient to make copies of existing live data.
// One must NEVER garbage collect while space has been borrowed in this
// way. At present this scheme is only ever used while rehashing hash
// tables.

size_t borrowed_pages_count;
static LispObject borrowed_vfringe, borrowed_vheaplimit;

void get_borrowed_page()
{   if (borrowed_pages_count == 0)
    {   trace_printf("\nRun out of memory (for rehashing)\n");
#ifdef DEBUG
        my_abort("memory full");
#endif
        Lstop(nil, fixnum_of_int(1));
    }
    void *p = pages[--borrowed_pages_count];
    zero_out(p);
    borrowed_vfringe =
        reinterpret_cast<LispObject>(reinterpret_cast<char *>
                                     (doubleword_align_up((intptr_t)p)) + 8);
    borrowed_vheaplimit =
        reinterpret_cast<LispObject>(reinterpret_cast<char *>
                                     (borrowed_vfringe) + (CSL_PAGE_SIZE-16));
}

LispObject borrow_basic_vector(int tag, int type, size_t size)
{   for (;;)
    {   char *r = reinterpret_cast<char *>(borrowed_vfringe);
        size_t freespace = (size_t)(reinterpret_cast<char *>
                                    (borrowed_vheaplimit) - r);
        size_t alloc_size = (size_t)doubleword_align_up(size);
        if (alloc_size > freespace)
        {   get_borrowed_page();
            continue;
        }
        borrowed_vfringe = reinterpret_cast<LispObject>(r + alloc_size);
        *(reinterpret_cast<Header *>(r)) = type + (size <<
                                           (Tw+5)) + TAG_HDR_IMMED;
        if (!SIXTY_FOUR_BIT && alloc_size != size)
            *reinterpret_cast<LispObject *>(borrowed_vfringe-CELL) = 0;
        return reinterpret_cast<LispObject>(r + tag);
    }
}

LispObject borrow_vector(int tag, int type, size_t n)
{   LispObject v;
    if (n-CELL > VECTOR_CHUNK_BYTES)
    {   size_t chunks = (n - CELL + VECTOR_CHUNK_BYTES - 1) /
                        VECTOR_CHUNK_BYTES;
        size_t i;
        size_t last_size = (n - CELL) % VECTOR_CHUNK_BYTES;
        if (last_size == 0) last_size = VECTOR_CHUNK_BYTES;
        v = borrow_basic_vector(TAG_VECTOR, TYPE_INDEXVEC, CELL*(chunks+1));
        errexit();
        for (i=0; i<chunks; i++)
            basic_elt(v, i) = nil;
        for (i=0; i<chunks; i++)
        {   LispObject v1;
            int k = i==chunks-1 ? last_size : VECTOR_CHUNK_BYTES;
            Save save(v);
            v1 = borrow_basic_vector(tag, type, k+CELL);
            errexit();
            save.restore(v);
            size_t k1 = k/CELL;
            for (size_t j=0; j<k1; j++)
                basic_elt(v1, j) = nil;
            basic_elt(v, i) = v1;
        }
    }
    else v = borrow_basic_vector(tag, type, n);
    return v;
}

// end of allocate.cpp
