// File cslgc.cpp                         Copyright (c) Codemist, 1990-2019

//
// Garbage collection.
//

/**************************************************************************
 * Copyright (C) 2019, Codemist.                         A C Norman       *
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

#ifndef CONSERVATIVE
// AT least for now I comment ALL of this file out if I am experimenting
// with the conservative version of the GC, and I have copied all the code in
// it into the file allocate.cpp. When I have that version stable I will
// transfer garbage collection stuff back. That means that the version here
// will never need to be conditional on CONSERVATIVE.

#ifdef WIN32
#include <conio.h>
#endif

int64_t gc_number = 0;
int64_t reclaim_trap_count = -1;
uintptr_t reclaim_stack_limit = 0;
uint64_t reclaim_trigger_count = 0, reclaim_trigger_target = 0;

static intptr_t cons_cells, symbol_heads, strings, user_vectors,
       big_numbers, box_floats, bytestreams, other_mem,
       litvecs, getvecs;

LispObject Lgc0(LispObject env)
{   return Lgc(env, lisp_true);
}

LispObject Lgc(LispObject env, LispObject a)
{   reclaim(nil, "user request",
            a != nil ? GC_USER_HARD : GC_USER_SOFT, 0);
    return nil;
}

LispObject Lverbos(LispObject env, LispObject a)
// (verbos 0) or (verbos nil)       silent garbage collection
// (verbos 1) or (verbos t)         standard GC messages
// (verbos 2)                       messages when FASL module loaded
// (verbos 4)                       extra timing info for GC process
// These bits can be added to get combination effects, except that
// "4" has no effect unless "1" is present.
{   int code, old_code = verbos_flag;
    if (a == nil) code = 0;
    else if (is_fixnum(a)) code = (int)int_of_fixnum(a);
    else code = 1;
    miscflags = (miscflags & ~GC_MSG_BITS) | (code & GC_MSG_BITS);
    return onevalue(fixnum_of_int(old_code));
}


static int stop_after_gc = 0;

static size_t trailing_heap_pages_count,
              trailing_vheap_pages_count;

static void copy(LispObject *p)
// This copies the object pointed at by p from the old to the new semi-space,
// and returns a copy to the pointer.  If scans the copied material to copy
// all relevent sub-structures to the new semi-space.
{   char *fr = (char *)fringe, *vfr = (char *)vfringe;
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
// The code here is a simulation of multiple procedure calls to the
// code that copies a single object.  What might otherwise have been
// a "return address" in the calls is handled by the variable "next" which
// takes positive values while copying vectors, and negative ones in
// the more common cases. I use "for (;;)" blocks a lot so that I can
// use "break" and "continue" to leap around in the code - maybe I
// would do better to be honest and use regular labels and "goto"
// statements.
    for (;;)
    {
// Copy one object, pointed at by p, from the old semi-space into the new
// one.
        LispObject a = *p;
        for (;;)
        {   if (a == nil) break;    // common and cheap enough to test here
            else if (is_immed_or_cons(a))
            {   if (is_cons(a))
                {   LispObject w;
                    w = qcar(a);
                    if (is_forward(w))
                    {   *p = w - TAG_FORWARD + TAG_CONS;
                        break;
                    }
                    fr = fr - sizeof(Cons_Cell);
                    cons_cells += 2*CELL;
// When I am doing regular calculation I leave myself a bunch of spare
// words (size SPARE bytes) so that I can afford to do several cons operations
// between tests.  Here I do careful tests on every step, and so I can
// sail much closer to the wind wrt filling up space.
                    if (fr <= (char *)heaplimit - SPARE + 32)
                    {   char *hl = (char *)heaplimit;
                        void *p;
                        qcar(fr) = SPID_GCMARK;
                        if (pages_count == 0) allocate_more_memory();
                        if (pages_count == 0)
                        {   term_printf("\n+++ Run out of memory\n");
                            ensure_screen();
                            my_exit(EXIT_FAILURE);
                        }
                        p = pages[--pages_count];
                        zero_out(p);
                        new_heap_pages[new_heap_pages_count++] = p;
                        heaplimit = (intptr_t)p;
                        hl = (char *)heaplimit;
                        fr = hl + CSL_PAGE_SIZE - sizeof(Cons_Cell);
                        heaplimit = (LispObject)(hl + SPARE);
                    }
                    qcar(fr) = w;
                    qcdr(fr) = qcdr(a);
                    *p = w = (LispObject)(fr + TAG_CONS);
                    qcar(a) = w + TAG_FORWARD;
                    break;
                }   // end of treatment of CONS
                else break;        // Immediate data drops out here
            }
            else                    // Here I have a symbol or vector
            {   Header h;
                int tag;
                size_t len;
                tag = ((int)a) & TAG_BITS;
                a = (LispObject)((char *)a - tag);
                h = *(Header *)a;
// If the symbol/number/vector has already been copied then its header
// word contains a forwarding address. Re-tag it.
                if (is_forward(h))
                {   *p = h - TAG_FORWARD + tag;
                    break;
                }
                if (tag == TAG_SYMBOL)
                    len = symhdr_length, symbol_heads += symhdr_length;
                else
                {
// length_of_header gives me the length in bytes, including the length
// of the header word and of any padding. Hmmm bit-vectors, byte-vectors
// (eg strings) and halfword vectors have a bit of a fudge in the way that
// their length is encoded, and so I will need to review that and confirm
// that all is safe! Yes - if you go length_of_header() on a string (or one
// of the other cases where tha actual data is short) then the result you
// get is the length in bytes of the data padded out to be a multiple of 4
// bytes long.
                    len = doubleword_align_up(length_of_header(h));
                    my_assert(len >= CELL,
                        [&]{ trace_printf("\nlen = %" PRIx64 " < CELL\n", len);
                             for (int i=-30; i<=30; i++)
                             { LispObject q = ((LispObject *)a)[i];
                               trace_printf("%3d: %" PRIx64, i, q);
                               if (is_odds(q) && is_header(q))
                                  trace_printf(" len=%" PRId64, length_of_header(q));
                               trace_printf("\n");
                             }
                           });
                    if (type_of_header(h) == TYPE_HASH)
                        h = h ^ (TYPE_HASH ^ TYPE_HASHX);
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
                    size_t free = (size_t)(vl - vfr);
// len indicates the length of the block of memory that must now be
// allocated...
                    if (len > free)
                    {   qcar(vfr) = 0;          // sentinel value
                        if (pages_count == 0) allocate_more_memory();
                        if (pages_count == 0)
                        {   term_printf("\n+++ Run out of memory\n");
                            ensure_screen();
                            my_exit(EXIT_FAILURE);
                        }
                        p1 = pages[--pages_count];
                        zero_out(p1);
                        new_vheap_pages[new_vheap_pages_count++] = p1;
                        vfr = (char *)p1 + 8;
                        vl = vfr + (CSL_PAGE_SIZE - 16);
                        vheaplimit = (LispObject)vl;
                        continue;
                    }
                    *p = (LispObject)(vfr + tag);
                    *(LispObject *)a = (LispObject)(vfr + TAG_FORWARD); 
                    *(Header *)vfr = h;
// I copy EVERYTHING from the old vector to the new one. By using memcpy
// I can do so with no worry about strict aliasing or the exact type of
// data present. So this will copy across any padder words.
                    memcpy((char *)vfr+CELL, (char *)a+CELL, len-CELL);
                    vfr += len;
                    break;
                }
                break;
            }
        }
// Now I have copied one object - the next thing to do is to scan to see
// if any further items are in the new space, and if so I will copy
// their offspring.
        for (;;)
        {   switch (next)
            {   case CONT:
                    if (tr_fr != fr)
                    {   tr_fr = tr_fr - sizeof(Cons_Cell);
                        if (qcar(tr_fr) == SPID_GCMARK)
                        {   char *w;
                            p1 = new_heap_pages[trailing_heap_pages_count++];
                            w = (char *)p1;
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
// The next word in the vector heap being a zero where a header was expected
// marks the end of data in this page of heap, so I will move on to the next
// one.
                            p1 = new_vheap_pages[trailing_vheap_pages_count++];
                            w = (char *)p1;
                            tr_vfr = w + 8;
                            h = *(Header *)tr_vfr;
                        }
                        if (is_symbol_header(h))
                        {   next = DONE_VALUE;
                            p = &(((Symbol_Head *)tr_vfr)->value);
                            break;
                        }
                        else
                        {   size_t len = length_of_header(h);
                            tr = tr_vfr;
                            tr_vfr = tr_vfr + doubleword_align_up(len);
                            if (len == CELL)
                            {
// Empty vectors should be treated as if they contained binary, because they
// certainly do not contain any pointers.
                                continue;
                            }
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
// There is a slight delight here. The test "vector_holds_binary" is only
// applicable if the header to be checked is a header of a genuine vector,
// ie something that would have TAG_VECTOR in the pointer to it. But here
// various numeric data types also live in the vector heap, so I need to
// separate them out explicitly. The switch block here does slightly more than
// it actually HAS to, since the vector_holds_binary test would happen to
// deal with several of the numeric types "by accident", but I feel that
// the security of listing them as separate cases is more important than the
// minor speed-up that might come from exploiting such marginal behaviour.
                                default:
                                    if (vector_holds_binary(h)) continue;
                                    // drop through on simple vectors, hash
                                    // tables etc etc. In general anything
                                    // that contains Lisp pointers.
                                case TYPE_RATNUM:
                                case TYPE_COMPLEX_NUM:
// Here I have a vector containing Lisp pointers. len gives its length
// including its header, so the final active data is at tr+len-CELL.
// I want to set next to indicate the offset of the item to be processed
// after I have dealt with that one, and that is len-2*CELL. Note that if
// the vector only held one pointer then len would have been just 2*CELL
// and this would ends up as zero - the correct value to indicate the
// end of processing a vector.
                                    next = len - 2*CELL;
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
// This will be the case when next is positive, in which case it is an
// offser from tr into a vector. It gets decreased as one goes and
// eventually ends up at zero (which is otherwise known as CONT) at
// which stage the vector has been fully processed and the next item
// to be scanned will be identified.
                    p = (LispObject *)(tr + next);
                    next -= CELL;
                    break;
            }
            break;
        }
    }
}

static bool reset_limit_registers()
// returns true if after resetting the limit registers there was
// enough space left for me to proceed. Return false on failure, ie
// need for a more genuine GC.
{   void *p;
// Put in a fence just to be cautious!
    std::atomic_thread_fence(std::memory_order_seq_cst);
    bool full = false;
// I wonder about the next test - memory would only really be full
// if there was enough LIVE data to fill all the available free pages,
// but what is tested here is based on the possibility that all the
// active pages are totally full. I scale up the vector page counts by
// a factor of 1.5 because fragmentation might behave differently in the
// old and new spaces so if there are some large vectors they may leave
// nasty gaps at the end of a page.
//
// If I get here during system start-up I will try to give myself some
// more memory. I expect that will usually be possible!
    if (!garbage_collection_permitted)
    {   if (pages_count == 0)
            full = !allocate_more_memory();
    }
    else full = (pages_count <=
        heap_pages_count + (3*vheap_pages_count + 1)/2);
    if (full) return false;
// reset_limit_registers should only be called when something has run out,
// so if it is CONS space I will expand the CONS heap, otherwise the VECTOR
// heap.
    if (fringe <= heaplimit)
    {   p = pages[--pages_count];
        space_now++;
        zero_out(p);
        heap_pages[heap_pages_count++] = p;
        heaplimit = (intptr_t)p;
        fringe = (LispObject)((char *)heaplimit + CSL_PAGE_SIZE);
        heaplimit = (LispObject)((char *)heaplimit + SPARE);
    }
    else
    {   char *vf, *vh;
        p = pages[--pages_count];
        space_now++;
        zero_out(p);
        vheap_pages[vheap_pages_count++] = p;
        vf = (char *)p + 8;
        vfringe = (LispObject)vf;
        vh = vf + (CSL_PAGE_SIZE - 16);
        vheaplimit = (LispObject)vh;
    }
    return true;
}

bool force_verbos = false;

static void report_at_end()
{   int n = heap_pages_count + vheap_pages_count;
    int n1 = n + pages_count;
    double fn = (double)n*(CSL_PAGE_SIZE/(1024.0*1024.0));
    double fn1 = (double)n1*(CSL_PAGE_SIZE/(1024.0*1024.0));
    double z = (100.0*n)/n1;
#ifdef WITH_GUI
    report_space(gc_number, z, fn1);
#endif // WITH_GUI
    if (verbos_flag & 1 || force_verbos)
    {   trace_printf(
            "At gc end about %.1f Mbytes of %.1f (%.1f%%) of heap is in use\n",
            fn, fn1, z);
    }
// This reports in Kbytes, and does not overflow until over 100 Gbytes
    qvalue(used_space) = fixnum_of_int((int)(1024.0*fn));
    qvalue(avail_space) = fixnum_of_int((int)(1024.0*fn1));
}

void use_gchook(LispObject arg)
{   LispObject g = gchook;
    if (symbolp(g) && g != unset_var)
    {   g = qvalue(g);
        if (symbolp(g) && g != unset_var && g != nil)
        {   class save_trapcount
            {   uint64_t count, target;
                public:
                save_trapcount()
                {   count = reclaim_trigger_count;
                    target = reclaim_trigger_target;
                    reclaim_trigger_target = 0;
                }
                ~save_trapcount()
                {   reclaim_trigger_count = count;
                    reclaim_trigger_target = target;
                }
            } RAII_trapcount;
            Lapply1(nil, g, arg);  // Call the hook
        }
    }
}

bool garbage_collection_permitted = false;

static void real_garbage_collector()
{
// I lift the real garbage collector to a separate function mainly
// so that I can set breakpoints on it!
    for (int i=0; i<=LOG2_VECTOR_CHUNK_BYTES; i++)
        free_vectors[i] = 0;

    cons_cells = symbol_heads = strings = user_vectors =
            big_numbers = box_floats = bytestreams = other_mem =
                                           litvecs = getvecs = 0;

// Set up the new half-space initially empty.
    new_heap_pages_count = 0;
    new_vheap_pages_count = 0;
    trailing_heap_pages_count = 1;
    trailing_vheap_pages_count = 1;
    assert(pages_count >= 2); // for the new half-space
    void *pp = pages[--pages_count];
    char *vf, *vl;
// A first page of (cons-)heap
    zero_out(pp);
    new_heap_pages[new_heap_pages_count++] = pp;
    heaplimit = (intptr_t)pp;
    vl = (char *)heaplimit;
    fringe = (LispObject)(vl + CSL_PAGE_SIZE);
    heaplimit = (LispObject)(vl + SPARE);
// A first page of vector heap.
    pp = pages[--pages_count];
    zero_out(pp);
    new_vheap_pages[new_vheap_pages_count++] = pp;
    vf = (char *)pp + 8;
    vfringe = (LispObject)vf;
    vl = vf + (CSL_PAGE_SIZE - 16);
    vheaplimit = (LispObject)vl;
// I should remind you, gentle reader, that the value cell
// and env cells of nil will always contain nil, which does not move,
// and so I do not need to copy them here provided that NIL itself
// never moves.
    copy(&(qplist(nil)));
    copy(&(qpname(nil)));
    copy(&(qfastgets(nil)));
    copy(&(qpackage(nil)));
// I dislike the special treatment of current_package that follows. Maybe
// I should arrange something totally different for copying the package
// structure...
    for (LispObject **p = list_bases; *p!=NULL; p++) copy(*p);
    for (LispObject *sp=stack; sp>(LispObject *)stackbase; sp--) copy(sp);
// When running the deserialization code I keep references to multiply-
// used items in repeat_heap, and if garbage collection occurs they must be
// updated.
    if (repeat_heap != NULL)
    {   for (size_t i=1; i<=repeat_count; i++)
            copy(&repeat_heap[i]);
    }
// Throw away the old semi-space - it is now junk.
    while (heap_pages_count!=0)
    {   void *spare = heap_pages[--heap_pages_count];
// I will fill the old space with explicit rubbish in the hope that that
// will generate failures as promptly as possible if it somehow gets
// referenced...
        memset(spare, 0x55, (size_t)CSL_PAGE_SIZE);
        pages[pages_count++] = spare;
    }
    while (vheap_pages_count!=0)
    {   void *spare = vheap_pages[--vheap_pages_count];
        memset(spare, 0xaa, (size_t)CSL_PAGE_SIZE);
        pages[pages_count++] = spare;
    }
// Flip the descriptors for the old and new semi-spaces.
    void **w = heap_pages;
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

// The string "why" is just a message that I can include in any message that
// the garbage collector displays. The "std_class" indicates what sort of
// memory might be running low and the cases are:
//   GC_CONS     cons heap
//   GC_VEC      vector heap   (and GC_BPS)
//   GC_STACK    Stack overflow. I think I should use respond_to_stack_event()
//   GC_USER_HARD              (and GC_USER_SOFT)
// The key thing is that in the GC_CONS and GC_VEC cases if I have an
// available memory page I should just allocate it and not do anything at all
// more.

void reclaim(const char *why, int stg_class)
{   if (pages_count != 0 ||
        (!garbage_collection_permitted && allocate_more_memory()))
    {   void *p;
        char *vf, *vh;
        switch (stg_class)
        {
        case GC_CONS:
            p = pages[--pages_count];
            space_now++;
            zero_out(p);
            heap_pages[heap_pages_count++] = p;
            heaplimit = (intptr_t)p;
            fringe = (LispObject)((char *)heaplimit + CSL_PAGE_SIZE);
            heaplimit = (LispObject)((char *)heaplimit + SPARE);
            return;
        case GC_VEC: case GC_BPS:
            p = pages[--pages_count];
            space_now++;
            zero_out(p);
            vheap_pages[vheap_pages_count++] = p;
            vf = (char *)p + 8;
            vfringe = (LispObject)vf;
            vh = vf + (CSL_PAGE_SIZE - 16);
            vheaplimit = (LispObject)vh;
            return;
        default:
        // GC_STACK, GC_USER_SOFT, GC_USER_HARD
            break;
        }
    }
    uint64_t t0;
    stop_after_gc = 0;
    t0 = read_clock();
// There are parts of the code in setup/restart where perhaps things are not
// yet in a consistent state and so any attempt at garbage collection could
// cause chaos. So during them I set a flag that I test here! Since this
// should never be triggered I am happy to leave it in state where the only
// sane way to respond to it is to run under a debugger and set breakpoints.
    if (!garbage_collection_permitted)
    {   fprintf(stderr,
                "\n+++ Garbage collection attempt when not permitted\n");
        fflush(stderr);
        my_exit(EXIT_FAILURE);    // totally drastic...
    }

    gc_number++;
    if (!valid_as_fixnum(gc_number)) gc_number = 0; // wrap round on 32-bit
                                                    // machines if too big.
    qvalue(gcknt_symbol) = fixnum_of_int(gc_number);

#ifdef WITH_GUI
// If I have a window system I tell it the current time every so often
// just to keep things cheery... so in such cases I will read the time
// every time there is a garbage collection regardless of whether I am
// generating GC messages. If I am not on a GUI system then  I only
// report time if GC messages are enabled, so I will only read the clock
// in that situation.
    {   long int t = (t0 - base_time)/10000; // in centiseconds
        long int gct = gc_time/10000;
// @@@@
// I guess that I want garbage collection messages, if any, to
// be sent to stderr rather than whatever output stream happens to
// be selected at the time of the garbage collection?
// At present messages go to the normal output stream, which only makes
// sense if GC messages are almost always disabled - maybe that will
// be the case!
        report_time(t, gct);
        time_now = read_clock();
        if ((verbos_flag & 1) || force_verbos)
        {   freshline_trace();
            trace_printf(
                "+++ Garbage collection %" PRId64
                " (%s) after %ld.%.2ld+%ld.%.2ld seconds\n",
                gc_number, why, t/100, t%100, gct/100, gct%100);
        }
    }
#else // !WITH_GUI
    if ((verbos_flag & 1) || force_verbos)
    {   long int t = (t0 - base_time)/10000;
        long int gct = gc_time/10000;
// @@@@
// I guess that I want garbage collection messages, if any, to
// be sent to stderr rather than whatever output stream happens to
// be selected at the time of the garbage collection?
// At present messages go to the normal output stream, which only makes
// sense if GC messages are almost always disabled - maybe that will
// be the case!
        time_now = t0;
        if ((time_limit >= 0 && time_now > time_limit) ||
            (io_limit >= 0 && io_now > io_limit))
            resource_exceeded();
        freshline_trace();
        trace_printf(
            "+++ Garbage collection %ld (%s) after %ld.%.2ld+%ld.%.2ld seconds\n",
            (long)gc_number, why, t/100, t%100, gct/100, gct%100);
    }
#endif // !WITH_GUI
    switch (pages_count)
    {
    case 0: allocate_more_memory(); // ...and drop through...
    case 1: allocate_more_memory();
    }
// If despite trying allocate_more_memory() I can not find a new pages to
// form that start of the new half-space I will have to give up.
    if (pages_count < 2)
    {   report_at_end();
        term_printf("\n+++ Run out of memory\n");
        ensure_screen();
        my_exit(EXIT_FAILURE);
    }
// If things crash really badly maybe I would rather have my output up
// to date.
    ensure_screen();
    if (spool_file != NULL) fflush(spool_file);
    if (gc_number == reclaim_trap_count)
    {   reclaim_trap_count = gc_number - 1;
        trace_printf("\nReclaim trap count reached...\n");
        aerror("reclaim-trap-count");
    }
    if (reclaim_stack_limit != 0 &&
        (uintptr_t)&t0 + reclaim_stack_limit < (uintptr_t)C_stackbase)
    {   reclaim_stack_limit = 0;
        trace_printf("\nReclaim stack limit reached...\n");
        aerror("reclaim-stack-limit");
    }

    if (reclaim_trigger_target != 0)
        trace_printf("+++ GC trigger = %" PRId64 "\n", reclaim_trigger_count);

// Now do the REAL work!
    real_garbage_collector();

    uint64_t t1 = read_clock();
    gc_time += t1 - t0;
    base_time += t1 - t0;
// (verbos 5) causes a display breaking down how space is used
    if ((verbos_flag & 5) == 5)
    {   trace_printf(
            "cons_cells=%" PRIdPTR ", symbol_heads=%" PRIdPTR ", strings=%" PRIdPTR ", user_vectors=%" PRIdPTR "\n",
            cons_cells, symbol_heads, strings, user_vectors-litvecs-getvecs);
        trace_printf(
            "bignums=%" PRIdPTR ", floats=%" PRIdPTR ", bytestreams=%" PRIdPTR ", other=%" PRIdPTR ", litvecs=%d\n",
            big_numbers, box_floats, bytestreams, other_mem, litvecs);
        trace_printf("getvecs=%" PRIdPTR " C-stacks=%" PRIdPTR "K Lisp-stack=%" PRIdPTR "K\n",
                     getvecs, (((char *)C_stackbase-(char *)&why)+1023)/1024,
                     (intptr_t)((stack-stackbase)+1023)/1024);
    }

    grab_more_memory(heap_pages_count + vheap_pages_count);

    report_at_end();
// Put limit registers back again...
    if (!reset_limit_registers())
    {   term_printf("\n+++ Run out of memory\n");
        ensure_screen();
        my_exit(EXIT_FAILURE);    // totally drastic...
    }
    if (stop_after_gc) Lstop1(nil, fixnum_of_int(0));
    if ((space_limit >= 0 && space_now > space_limit) ||
        (time_limit >= 0 && time_now > time_limit) ||
        (io_limit >= 0 && io_now > io_limit))
        resource_exceeded();
    stackcheck();
    use_gchook(lisp_true);
}

LispObject reclaim(LispObject p, const char *why, int stg_class, size_t size)
{   push(p);
    reclaim(why, stg_class);
    pop(p);
    return p;
}

#endif // !CONSERVATIVE

// end of file cslgc.cpp
