// File cslgc.cpp                         Copyright (c) Codemist, 1990-2017

//
// Garbage collection.
//
//    October 2016 and once again I REMOVE the mark/slide collector. This
//    decision is to simplify the code and ease a transition to a replacement
//    copying collector, and because I no longer view 32-bit machines as
//    high priority. Well a Raspberry Pi with 1 Gbyte can still do serious
//    size calculations even with the copying collector.
//    This shortens and simplifies the code quite a lot!
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
#include <conio.h>
#endif

int64_t gc_number = 0;
int64_t reclaim_trap_count = -1;
uintptr_t reclaim_stack_limit = 0;

static intptr_t cons_cells, symbol_heads, strings, user_vectors,
       big_numbers, box_floats, bytestreams, other_mem,
       litvecs, getvecs;

LispObject Lgc0(LispObject env, int nargs, ...)
{   argcheck(nargs, 0, "reclaim");
    return Lgc(env, lisp_true);
}

LispObject Lgc(LispObject env, LispObject a)
{
//
// If GC is called with a non-nil argument the garbage collection
// will be a full one - otherwise it will be soft and may do hardly
// anything.
//
    return reclaim(nil, "user request",
                   a != nil ? GC_USER_HARD : GC_USER_SOFT, 0);
}

LispObject Lverbos(LispObject env, LispObject a)
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


static int trailing_heap_pages_count,
           trailing_vheap_pages_count;

static void copy(LispObject *p)
//
// This copies the object pointed at by p from the old to the new semi-space,
// and returns a copy to the pointer.  If scans the copied material to copy
// all relevent sub-structures to the new semi-space.
//
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
                            my_abort();
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
                    *p = w = (LispObject)(fr + TAG_CONS);
                    qcar(a) = w + TAG_FORWARD;
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
// If the symbol/number/vector has already been copied then its header
// word contains a forwarding address. Re-tag it.
                if (is_forward(h))
                {   *p = h - TAG_FORWARD + tag;
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
                            my_abort();
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
                    *p = (LispObject)(vfr + tag);
                    *(LispObject *)a = (LispObject)(vfr + TAG_FORWARD); 
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
        {   switch (next)
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
                    break;
            }
            break;
        }
    }
}

static bool reset_limit_registers(intptr_t vheap_need, bool stack_flag)
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
            (3*vheap_pages_count + 1)/2);
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
    while ((q = *p) != nil)
    {   Header h;
        r = qcar(q);
        h = vechdr(r);
        if (!is_forward((LispObject)h)) *p = qcdr(q);
        else p = &qcdr(q);
    }
    p = &equal_hash_tables;
    while ((q = *p) != nil)
    {   Header h;
        r = qcar(q);
        h = vechdr(r);
        if (!is_forward((LispObject)h)) *p = qcdr(q);
        else p = &qcdr(q);
    }
}

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

// The following fnction can be called from a signal handler. It just looks
// and and sets some volatile variables.

int async_interrupt(int type)
{   int prev = async_type;
    if (type != QUERY_INTERRUPT)
    {   async_type = type;
        stacklimit = stackbase;
    }
    return prev;
}

static void report_at_end()
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

// The next function is intended to allow me to detect some values as
// being certain not to be valid LispObjects, and hence not in need of
// processing by a conservative coollector. For now this is does not
// do anything meaningful!

static bool certainly_not_valid(LispObject p)
{   switch (p & 0x7)
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
{   LispObject g = gchook;
    if (symbolp(g) && g != unset_var)
    {   g = qvalue(g);
        if (symbolp(g) && g != unset_var && g != nil)
        {   push(p);
            Lapply1(nil, g, arg);  // Call the hook
            pop(p);
        }
    }
    return onevalue(p);
}

static double prev_consolidated = 0.0;
static int prev_consolidated_set = 1;

bool garbage_collection_permitted = false;

LispObject reclaim(LispObject p, const char *why, int stg_class, intptr_t size)
{   size_t i;
    clock_t t0, t1, t2;
    LispObject *sp;
    intptr_t vheap_need = 0;
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
    already_in_gc = true;
#if defined WIN32 && !defined __CYGWIN__
    _kbhit(); // Fairly harmless anyway, but is here to let ^c get noticed
//    printf("(*)"); fflush(stdout);  // while I debug!
#endif // WIN32
    push_clock(); t0 = base_time;
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
                resource_exceeded();
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
        return interrupted(p);
    }
    else
    {   tidy_fringes();
        if ((!next_gc_is_hard || stg_class == GC_STACK) &&
            stg_class != GC_USER_HARD &&
            reset_limit_registers(vheap_need, true))
        {   already_in_gc = false;
            pop_clock();
            if (space_limit >= 0 && space_now > space_limit)
                resource_exceeded();
//
// I have "soft" garbage collections - perhaps fairly frequently. I will
// only call the GC hook function around once every 5 seconds to avoid undue
// overhead in it.
//
            if (!prev_consolidated_set)
            {   prev_consolidated = consolidated_time[0];
                prev_consolidated_set = 1;
            }
            if (consolidated_time[0] > prev_consolidated + 5.0)
            {   prev_consolidated = consolidated_time[0];
                return use_gchook(p, nil); // Soft GC
            }
            return onevalue(p);
        }
    }

    if (stack >= stacklimit)
    {   if (stacklimit != stackbase)
        {   stacklimit = &stacklimit[50];  // Allow a bit of slack
            pop_clock();
            error(0, err_stack_overflow);
        }
    }

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
    next_gc_is_hard = false;
    if (!valid_as_fixnum(gc_number)) gc_number = 0; // wrap round on 32-bit
                                                    // machines if too big.
    qvalue(gcknt_symbol) = fixnum_of_int(gc_number);

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
                "+++ Garbage collection %" PRId64
                " (%s) after %ld.%.2ld+%ld.%.2ld seconds\n",
                gc_number, why, t/100, t%100, gct/100, gct%100);
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
            resource_exceeded();
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
    if (spool_file != NULL) fflush(spool_file);
    if (gc_number == reclaim_trap_count)
    {   reclaim_trap_count = gc_number - 1;
        trace_printf("\nReclaim trap count reached...\n");
        aerror("reclaim-trap-count");
    }
    if (reclaim_stack_limit != 0 &&
        (uintptr_t)&t0 + reclaim_stack_limit < (uintptr_t)C_stack_base)
    {   reclaim_stack_limit = 0;
        trace_printf("\nReclaim stack limit reached...\n");
        aerror("reclaim-stack-limit");
    }

    for (int i=0; i<LOG2_VECTOR_CHUNK_WORDS+1; i++)
        free_vectors[i] = 0;

#ifdef CONSERVATIVE
    cache_ambiguous();
#endif // CONSERVATIVE

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
// I should remind you, gentle reader, that the value cell
// and env cells of nil will always contain nil, which does not move,
// and so I do not need to copy them here provided that NIL itself
// never moves.
//
        copy(&(qplist(nil)));
        copy(&(qpname(nil)));
        copy(&(qfastgets(nil)));
        copy(&(qpackage(nil)));

//
// I dislike the special treatment of current_package that follows. Maybe
// I should arrange something totally different for copying the package
// structure...
//
        for (LispObject **p = list_bases; *p!=NULL; p++) copy(*p);

        for (sp=stack; sp>(LispObject *)stackbase; sp--) copy(sp);
// When running the deserialization code I keep references to multiply-
// used items in repeat_heap, and if garbage collection occurs they must be
// updated.
        if (repeat_heap != NULL)
        {   for (i=1; i<=repeat_count; i++)
                copy(&repeat_heap[i]);
        }
//
// Now I need to perform some magic on the list of hash tables...
//
        lose_dead_hashtables();
// When I have transitions to the new hash table scheme the two lists
// processed specially here become redundant and this fragment of code can
// go, I think.
        copy(&eq_hash_tables);
        copy(&equal_hash_tables);

        tidy_fringes();

//
// Throw away the old semi-space - it is now junk.
//
        while (heap_pages_count!=0)
        {   void *spare = heap_pages[--heap_pages_count];
// I will fill the old space with explicit rubbish in the hope that that
// will generate failures as promptly as possible if it somehow gets
// referenced...
            memset(spare, 0x55, (size_t)CSL_PAGE_SIZE+16);
            pages[pages_count++] = spare;
        }
        while (vheap_pages_count!=0)
        {   void *spare = vheap_pages[--vheap_pages_count];
            memset(spare, 0xaa, (size_t)CSL_PAGE_SIZE+16);
            pages[pages_count++] = spare;
        }

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
    t2 = base_time;

    if ((verbos_flag & 5) == 5)
//
// (verbos 4) gets the system to tell me how long each phase of GC took,
// but (verbos 1) must be ORd in too.
//
    {   
        trace_printf("Copy %ld ms\n",
                     (long int)(1000.0 *
                                (double)(t2-t0)/(double)CLOCKS_PER_SEC));
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
            if (page == NULL)
            {   init_flags &= ~INIT_EXPANDABLE;
                break;
            }
            else pages[pages_count++] = page;
        }
    }
    if (!reset_limit_registers(vheap_need, false))
    {   if (stack < stacklimit || stacklimit != stackbase)
        {   report_at_end();
            term_printf("\n+++ No space left at all\n");
            my_exit(EXIT_FAILURE);    // totally drastic...
        }
    }
    report_at_end();
    if (stop_after_gc) Lstop(nil, fixnum_of_int(0));
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
        resource_exceeded();
    prev_consolidated = consolidated_time[0];
    return use_gchook(p, lisp_true);
}

// end of file cslgc.cpp
