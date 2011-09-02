/* File gc.c                    Copyright (c) Codemist Ltd, 1990-2007 */

/*
 * Garbage collection.
 *    Version 5. The mark/slide code is being removed on the
 *    grounds that machines these days have LOTS of memory so ot should
 *    not really bbe needed, and it is a lot of messy code to support.
 *    there is also a start at support for a
 *    conservative garbage collector so that the separate C
 *    stack that I used to need is no longer called for: the hope is
 *    that this may seriously speed up much code... but it makes
 *    "cons" a little messier and "allocate_vector" a lot messier,
 *    and a somewhat-copying conservative GC hurts on the complication
 *    front quite a lot! That is enabled via --enable-conservative in
 *    that autoconf stuff, and is NOT working yet.
 *
 *    Fourth major version - now using Foster-style
 *    algorithm for relocating vector heap, and support for handling
 *    BPS via segmented handles. Pointer-reversing mark phase to go
 *    with same.
 *
 *    Furthermore there is (optionally) a copying 2-space garbage
 *    collector as well as the mark/slide one.  Now do you understand
 *    why this file seems so very long?
 *
 * The code in parts of this file (and also in preserve.c & restart.c)
 * is painfully sensitive to memory layout and I have some messy
 * conditional inclusion of code depending on whether a Lisp_Object is
 * a 32 or 64-bit value.
 */

/*
 * This code may be used and modified, and redistributed in binary
 * or source form, subject to the "CCL Public License", which should
 * accompany it. This license is a variant on the BSD license, and thus
 * permits use of code derived from this in either open and commercial
 * projects: but it does require that updates to this code be made
 * available back to the originators of the package.
 * Before merging other code in with this or linking this code
 * with other packages or libraries please check that the license terms
 * of the other material are compatible with those of this.
 */


/* Signature: 536448d8 19-Jan-2008 */

#include "headers.h"

#ifdef SOCKETS
#include "sockhdr.h"
#endif

int gc_number = 0;

static intptr_t cons_cells, symbol_heads, strings, user_vectors,
             big_numbers, box_floats, bytestreams, other_mem,
             litvecs, getvecs;

#define is_immed(x) (is_immed_or_cons(x) && !is_cons(x))

Lisp_Object MS_CDECL Lgc0(Lisp_Object nil, int nargs, ...)
{
    argcheck(nargs, 0, "reclaim");
    return Lgc(nil, lisp_true);
}

Lisp_Object Lgc(Lisp_Object nil, Lisp_Object a)
{
/*
 * If GC is called with a non-nil argument the garbage collection
 * will be a full one - otherwise it will be soft and may do hardly
 * anything.
 */
#ifdef DEMO_MODE
    return onevalue(nil);
#else
    return reclaim(nil, "user request",
                   a != nil ? GC_USER_HARD : GC_USER_SOFT, 0);
#endif
}

Lisp_Object Lverbos(Lisp_Object nil, Lisp_Object a)
/*
 * (verbos 0) or (verbos nil)       silent garbage collection
 * (verbos 1) or (verbos t)         standard GC messages
 * (verbos 2)                       messages when FASL module loaded
 * (verbos 4)                       extra timing info for GC process
 * These bits can be added to get combination effects, except that
 * "4" has no effect unless "1" is present.
 */
{
    int code, old_code = verbos_flag;
    if (a == nil) code = 0;
    else if (is_fixnum(a)) code = (int)int_of_fixnum(a);
    else code = 1;
/*
 * -G on the command line makes garbage collection noisy always...
 */
    if (miscflags & ALWAYS_NOISY) code |= 3;
    miscflags = (miscflags & ~GC_MSG_BITS) | (code & GC_MSG_BITS);
    return onevalue(fixnum_of_int(old_code));
}


CSLbool volatile already_in_gc, tick_on_gc_exit;
CSLbool volatile interrupt_pending, tick_pending;
Lisp_Object volatile saveheaplimit;
Lisp_Object volatile savevheaplimit;
Lisp_Object volatile savecodelimit;
Lisp_Object * volatile savestacklimit;


static int stop_after_gc = 0;

static void zero_out(void *p)
{
    char *p1 = (char *)doubleword_align_up((intptr_t)p);
    memset(p1, 0, CSL_PAGE_SIZE);
}

static int trailing_heap_pages_count,
           trailing_vheap_pages_count;

static void copy(Lisp_Object *p)
/*
 * This copies the object pointed at by p from the old to the new semi-space,
 * and returns a copy to the pointer.  If scans the copied material to copy
 * all relevent sub-structures to the new semi-space.
 */
{
    Lisp_Object nil = C_nil;
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
#endif
/*
 * The code here is a simulation of multiple procedure calls to the
 * code that copies a single object.  What might otherwise have been
 * a "return address" in the calls is handled by the variable "next" which
 * takes positive values while copying vectors, and negative ones in
 * the more common cases. I use "for (;;)" blocks a lot so that I can
 * use "break" and "continue" to leap around in the code - maybe I
 * would do better to be honest and use regular labels and "goto"
 * statements.
 */
    for (;;)
    {
/*
 * Copy one object, pointed at by p, from the old semi-space into the new
 * one.
 */
        Lisp_Object a = *p;
#ifdef DEBUG_GC
        term_printf("Next copy [%p] %p\n", (void *)p, (void *)a);
        if (a == 0)
        {   term_printf("Shambles\n");
            *(int *)(-1) = 0;
        }
#endif
        for (;;)
        {
            if (a == nil) break;    /* common and cheap enough to test here */
            else if (is_immed_or_cons(a))
            {   if (is_cons(a))
                {   Lisp_Object w;
                    w = qcar(a);
                    if (is_cons(w) && is_marked_p(w)) /* a forwarding address */
                    {   *p = flip_mark_bit_p(w);
                        break;
                    }
                    fr = fr - sizeof(Cons_Cell);
                    cons_cells += 2*CELL;
/*
 * When I am doing regular calculation I leave myself a bunch of spare
 * words (size SPARE bytes) so that I can afford to do several cons operations
 * between tests.  Here I do careful tests on every step, and so I can
 * sail much closer to the wind wrt filling up space.
 */
                    if (fr <= (char *)heaplimit - SPARE + 32)
                    {   char *hl = (char *)heaplimit;
                        void *p;
                        int32_t len = (int32_t)(fr - (hl - SPARE) +
                                                     sizeof(Cons_Cell));
                        car32(hl - SPARE) = len;
                        qcar(fr) = SPID_GCMARK;
                        if (pages_count == 0)
                        {   term_printf("pages_count = 0 in GC\n");
                            ensure_screen();
                            abort();
                            return;
                        }
                        p = pages[--pages_count];
                        zero_out(p);
                        new_heap_pages[new_heap_pages_count++] = p;
                        heaplimit = quadword_align_up((intptr_t)p);
                        hl = (char *)heaplimit;
                        car32(heaplimit) = CSL_PAGE_SIZE;
                        fr = hl + CSL_PAGE_SIZE - sizeof(Cons_Cell);
                        heaplimit = (Lisp_Object)(hl + SPARE);
                    }
                    qcar(fr) = w;
                    qcdr(fr) = qcdr(a);
#ifdef DEBUG_GC
                    term_printf("new data for cons %p %p\n", (void *)w, (void *)qcdr(a));
#endif
                    *p = w = (Lisp_Object)(fr + TAG_CONS);
                    qcar(a) = flip_mark_bit_p(w);
                    break;
                }   /* end of treatment of CONS */
                else if (is_bps(a))
                {   char *d = data_of_bps(a) - CELL, *rr;
                    int32_t alloc_size;
                    Header h = *(Header *)d;
                    int32_t len;
                    if (is_bps(h))  /* Replacement handle in header field? */
                    {   *p = h ;
                        break;
                    }
                    len = length_of_header(h);
                    alloc_size = doubleword_align_up(len);
                    bytestreams += alloc_size;
                    for (;;)
                    {   char *cf = (char *)codefringe,
                             *cl = (char *)codelimit;
                        int32_t free = (int32_t)(cf - cl);
                        if (alloc_size > free)
                        {
                            void *p;
                            if (codelimit != 0)
                            {   int32_t len = (int32_t)(cf - (cl - 8));
                                car32(cl - 8) = len;
                            }
                            if (pages_count == 0)
                            {   term_printf("pages_count = 0 in GC\n");
                                ensure_screen();
                                abort();
                                return;
                            }
                            p = pages[--pages_count];
                            zero_out(p);
                            new_bps_pages[new_bps_pages_count++] = p;
                            cl = (char *)doubleword_align_up((intptr_t)p);
                            codefringe = (Lisp_Object)(cl + CSL_PAGE_SIZE);
                            codelimit = (Lisp_Object)(cl + 8);
                            continue;
                        }
                        rr = cf - alloc_size;
                        codefringe = (Lisp_Object)rr;
/*
 * See comments in fns2.c for the curious packing here!
 */
                        *(Header *)d = *p = TAG_BPS +
                           (((intptr_t)((rr + CELL) - (cl - 8)) &
                             (PAGE_POWER_OF_TWO-4)) << 6) +
                           (((intptr_t)(new_bps_pages_count-1))<<(PAGE_BITS+6));
                        /* Wow! How obscure!! */
                        *(Header *)rr = h;
                        memcpy(rr+CELL, d+CELL, alloc_size-CELL);
                        break;
                    }
                    break;
                }
                else break;        /* Immediate data drops out here */
            }
            else                    /* Here I have a symbol or vector */
            {   Header h;
                int tag;
                intptr_t len;
                tag = ((int)a) & TAG_BITS;
                a = (Lisp_Object)((char *)a - tag);
                h = *(Header *)a;
#ifdef DEBUG_GC
                term_printf("Header is %p\n", (void *)h);
#endif
                if (!is_odds(h))
                {   *p = h;
                    break;
                }
                if (tag == TAG_SYMBOL)
                    len = symhdr_length, symbol_heads += symhdr_length;
                else
                {   len = doubleword_align_up(length_of_header(h));
                    switch (type_of_header(h))
                    {
                case TYPE_STRING:
                        strings += len; break;
                case TYPE_BIGNUM:
                        big_numbers += len; break;
#ifdef COMMON
                case TYPE_SINGLE_FLOAT:
                case TYPE_LONG_FLOAT:
#endif
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
                        qcar(vfr) = 0;          /* sentinel value */
                        if (pages_count == 0)
                        {   term_printf("pages_count = 0 in GC\n");
                            ensure_screen();
                            abort();
                            return;
                        }
                        p1 = pages[--pages_count];
                        zero_out(p1);
                        new_vheap_pages[new_vheap_pages_count++] = p1;
                        vfr = (char *)doubleword_align_up((intptr_t)p1) + 8;
                        vl = vfr + (CSL_PAGE_SIZE - 16);
                        vheaplimit = (Lisp_Object)vl;
                        free1 = (uintptr_t)(vfr - (vl - (CSL_PAGE_SIZE - 8)));
                        car32(vl - (CSL_PAGE_SIZE - 8)) = free1;
                        continue;
                    }
                    *(Lisp_Object *)a = *p = (Lisp_Object)(vfr + tag);
                    *(Header *)vfr = h;
                    memcpy((char *)vfr+CELL, (char *)a+CELL, len-CELL);
                    vfr += len;
                    break;
                }
                break;
            }
        }
/*
 * Now I have copied one object - the next thing to do is to scan to see
 * if any further items are in the new space, and if so I will copy
 * their offspring.
 */
        for (;;)
        {
#ifdef DEBUG_GC
            switch (next)
            {
        case CONT:
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
#endif
            switch (next)
            {
        case CONT:
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
                    break;              /* Takes me to the outer loop */
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
/*
 * In a 64-bit world vectors are not padded to be an even number of cells,
 * and so a vector with no elements consists of just its header word. This
 * is best treated as if it contained binary because it certainly does not
 * contain any pointers, while the general code for handling vectors is
 * written on the assumption that every vector that contains pointers at
 * all contains at least one.
 */
#ifdef DEBUG_GC
                            term_printf("zero length vector in 64-bit world\n");
#endif
                            continue;
                        }
#ifdef DEBUG_GC
                        term_printf("header = %llx, type = %d/%x len = %d\n",
                           (long long)h, type_of_header(h), type_of_header(h), len);
#endif

                        switch (type_of_header(h))
                        {
#ifdef COMMON
                    case TYPE_SINGLE_FLOAT:
                    case TYPE_LONG_FLOAT:
#endif
                    case TYPE_DOUBLE_FLOAT:
                    case TYPE_BIGNUM:
                            continue;
                    case TYPE_MIXED1: case TYPE_MIXED2:
                    case TYPE_MIXED3: case TYPE_STREAM:
                            next = 2*CELL;
                            break;
/*
 * There is a slight delight here. The test "vector_holds_binary" is only
 * applicable if the header to be checked is a header of a genuine vector,
 * ie something that would have TAG_VECTOR in the pointer to it. But here
 * various numeric data types also live in the vector heap, so I need to
 * separate them out explicitly. The switch block here does slightly more than
 * it actually HAS to, since the vector_holds_binary test would happen to
 * deal with several of the numeric types "by accident", but I feel that
 * the security of listing them as separate cases is more important than the
 * minor speed-up that might come from exploiting such marginal behaviour.
 */
                    default:
                            if (vector_holds_binary(h)) continue;
#ifdef COMMON
                    case TYPE_RATNUM:
                    case TYPE_COMPLEX_NUM:
#endif
                            next = len - 2*CELL;
#ifdef DEBUG_GC
                            term_printf("line %d next now %d\n", __LINE__, next);
                            if (next < 0)
                            {   term_printf("unexpectedly negative\n");
/* Just a vector with no elements on a 64-bit system? */                                continue;
                            }
#endif
                            break;
                        }
                        p = (Lisp_Object *)(tr + next + CELL);
                        break;
                    }
                }
                else
                {   fringe = (Lisp_Object)fr;
                    vfringe = (Lisp_Object)vfr;
                    return;        /* Final exit when all has been copied */
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
#ifndef COMMON
                next = CONT;
                p = &(((Symbol_Head *)tr_vfr)->plist);
                tr_vfr = tr_vfr + symhdr_length;
                break;
#else
                next = DONE_PLIST;   
                p = &(((Symbol_Head *)tr_vfr)->plist);
                break;
        case DONE_PLIST:
                next = CONT;
                p = &(((Symbol_Head *)tr_vfr)->package);
                tr_vfr = tr_vfr + symhdr_length;
                break;
#endif
        default:
                p = (Lisp_Object *)(tr + next);
                next -= CELL;
#ifdef DEBUG_GC
                term_printf("line %d next now %d\n", __LINE__, next);
                if (next < 0)
                {   term_printf("unexpectedly negative\n");
                    *(int *)(-1) = 0;
                }
#endif
                break;
            }
            break;
        }
    }
}

#ifndef DEMO_MODE

typedef struct mapstore_item
{
    double w;
    double n;
    uint32_t n1;
    Lisp_Object p;
} mapstore_item;

int profile_count_mode;

static int MS_CDECL profile_cf(const void *a, const void *b)
{
    mapstore_item *aa = (mapstore_item *)a,
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

#endif

Lisp_Object Lmapstore(Lisp_Object nil, Lisp_Object a)
/*
 * Argument controls what happens:
 *    nil or 0      print statistics and reset to zero
 *           1      print, but do not reset
 *           2      return list of stats, reset to zero
 *           3      return list, do not reset
 *           4      reset to zero, do not print, return nil
 *	     8	    Toggle call count mode
 */
{
#ifdef DEMO_MODE
    return onevalue(nil);
#else
    int pass, what;
    int j, gcn = 0;
    double itotal = 0.0, total = 0.0;
    Lisp_Object res = nil;
    mapstore_item *buff=NULL;
    int buffp=0, buffn=0;
    if (a == nil) a = fixnum_of_int(0);
    if (is_fixnum(a)) what = int_of_fixnum(a);
    else what = 0;
    if ((what & 6) == 0)
    {   buff = (mapstore_item *)(*malloc_hook)(100*sizeof(mapstore_item));
        if (buff == NULL) return onevalue(nil); /* fail */
        buffp = 0;
        buffn = 100;
    }
    if ((what & 2) != 0)
    {   Lgc0(nil, 0); /* Force GC at start to avoid one in the middle */
        nil = C_nil;
        if (exception_pending()) return nil;
        gcn = gc_number;
    }

    if ((what & 8) != 0)
	profile_count_mode = !profile_count_mode;
#ifdef PROFILED
/*
 * PROFILED is intended to be defined if we were compiled with a -p option,
 * and we take system dependent action to dump out results (e.g. on some systems
 * it may be useful to invoke monitor() or moncontrol() here.
 */

#ifdef SHOW_COUNTS_AVAILABLE
    show_counts();
    write_profile("counts");   /* Useful if -px option to compiler */
#endif

#endif /* PROFILED */
    {   char *vf = (char *)vfringe,
             *vl = (char *)vheaplimit;
        int32_t len = (int32_t)(vf - (vl - (CSL_PAGE_SIZE - 8)));
/*
 * Set up the current page so I can tell where the active data is.
 */
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
                {   Lisp_Object e = qenv(low + TAG_SYMBOL);
                    intptr_t clen = 0;
                    uintptr_t n;
                    if (is_cons(e))
                    {   e = qcar(e);
                        if (is_bps(e))
                        {   Header ch = *(Header *)(data_of_bps(e) - CELL);
                            clen = length_of_header(ch);
                        }
                    }
                    n = qcount(low + TAG_SYMBOL);
                    if (n != 0 && clen != 0)
                    {   double w = (double)n/(double)clen;
/*
 * Here I want a measure that will give a good idea of how worthwhile it
 * would be to compile the given function into C - what I have chosen is
 * a count of bytecodes executed scaled by the length
 * of the bytestream code defining the function.  This will cause "good value"
 * cases to show up best.  I scale this relative to the total across all
 * functions recorded to make the numbers less sensitive to details of
 * how I generate test cases.  For interest I also display the proportion
 * of actual bytecodes interpreted.  In each case I record these out of
 * a total of 100.0 (percent) to give comfortable ranges of numbers to admire.
 */
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
                                    buff[buffp].p = (Lisp_Object)(low + TAG_SYMBOL);
                                    buffp++;
                                }
                                if ((what & 2) != 0)
                                {   Lisp_Object w1;
/* Result is a list of items ((name size bytes-executed) ...).
 * You might think that I needed to push res here - but I abort if there
 * is a GC, so it is not necessary after all.
 */
                                    w1 = list3((Lisp_Object)(low + TAG_SYMBOL),
                                              fixnum_of_int(clen),
                                              fixnum_of_int(n));
                                    nil = C_nil;
                                    if (exception_pending() || gcn != gc_number)
                                        return nil;
                                    res = cons(w1, res);
                                    nil = C_nil;
                                    if (exception_pending() || gcn != gc_number)
                                        return nil;
                                }
                            }
/*
 * Reset count unless 1 bit of arg is set
 */
                            if ((what & 1) == 0)
                                qcount(low + TAG_SYMBOL) = 0;
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
        trace_printf("\n  Value  %%bytes (So far) Bytecodes  Function name\n");
        for (j=0; j<buffp; j++)
        {   running += buff[j].n;
            trace_printf("%7.2f %7.2f (%6.2f) %9lu: ",
                buff[j].w, buff[j].n, running, (long unsigned)buff[j].n1);
            prin_to_trace(buff[j].p);
            trace_printf("\n");
        }
        trace_printf("\n");
        (*free_hook)((void *)buff);
    }
    return onevalue(res);
#endif /* DEMO_MODE */
}

Lisp_Object MS_CDECL Lmapstore0(Lisp_Object nil, int nargs, ...)
{
    argcheck(nargs, 0, "mapstore");
    return Lmapstore(nil, nil);
}

static CSLbool reset_limit_registers(intptr_t vheap_need,
                                     intptr_t bps_need,
                                     intptr_t native_need,
                                     CSLbool stack_flag)
/*
 * returns YES if after resetting the limit registers there was
 * enough space left for me to proceed. Return NO on failure, ie
 * need for a more genuine GC.
 */
{
    void *p;
    nil_as_base
    uintptr_t len;
    CSLbool full;
/*
 * I wonder about the next test - memory would only really be full
 * if there was enough LIVE data to fill all the available free pages,
 * but what is tested here is based on the possibility that all the
 * active pages are totally full.
 */
    full = (pages_count <=
             heap_pages_count + vheap_pages_count +
             bps_pages_count + native_pages_count);
    if (fringe <= heaplimit)
    {   if (full) return NO;
        p = pages[--pages_count];
        zero_out(p);
        heap_pages[heap_pages_count++] = p;
        heaplimit = quadword_align_up((intptr_t)p);
        car32(heaplimit) = CSL_PAGE_SIZE;
        fringe = (Lisp_Object)((char *)heaplimit + CSL_PAGE_SIZE);
        heaplimit = (Lisp_Object)((char *)heaplimit + SPARE);
    }
    {   char *vh = (char *)vheaplimit,
             *vf = (char *)vfringe;
        len = (uintptr_t)(vh - vf);
    }
    if (vheap_need > (intptr_t)len)
    {   char *vf, *vh;
        if (full) return NO;
        p = pages[--pages_count];
        zero_out(p);
        vheap_pages[vheap_pages_count++] = p;
        vf = (char *)doubleword_align_up((intptr_t)p) + 8;
        vfringe = (Lisp_Object)vf;
        vh = vf + (CSL_PAGE_SIZE - 16);
        vheaplimit = (Lisp_Object)vh;
        len = (uintptr_t)(vf - (vh - (CSL_PAGE_SIZE - 8)));
        car32(vh - (CSL_PAGE_SIZE - 8)) = len;
    }
    {   char *cl = (char *)codelimit,
             *cf = (char *)codefringe;
        len = (uintptr_t)(cf - cl);
    }
    if (bps_need != 0 && bps_need >= (intptr_t)len)
    {   char *cl;
        if (full || bps_pages_count >= MAX_BPS_PAGES - 1) return NO;
        p = pages[--pages_count];
        zero_out(p);
        bps_pages[bps_pages_count++] = p;
        cl = (char *)doubleword_align_up((intptr_t)p);
        codefringe = (Lisp_Object)(cl + CSL_PAGE_SIZE);
        codelimit = (Lisp_Object)(cl + 8);
    }
    if (native_need != 0)
    {   if (full || native_pages_count >= MAX_NATIVE_PAGES - 1) return NO;
        p = pages[--pages_count];
        zero_out(p);
        native_pages[native_pages_count++] = p;
        native_fringe = 8;
    }
    if (stack_flag) return (stack < stacklimit);
    else return YES;
}

static void tidy_fringes(void)
/*
 * heaplimit was SPARE bytes above the actual base of the page,
 * so the next line dumps fringe somewhere where it can be found
 * later on when needed while scanning a page of heap.  Similarly
 * vfringe is stashed away at the end of its page.
 */
{   nil_as_base
    char *fr = (char *)fringe,
         *vf = (char *)vfringe,
         *cf = (char *)codefringe,
         *hl = (char *)heaplimit,
         *vl = (char *)vheaplimit,
         *cl = (char *)codelimit;
    int32_t len = (int32_t)(fr - (hl - SPARE));
    car32(hl - SPARE) = len;
    len = (uintptr_t)(vf - (vl - (CSL_PAGE_SIZE - 8)));
    car32(vl - (CSL_PAGE_SIZE - 8)) = (Lisp_Object)len;
    if (codelimit != 0)
    {   len = (int32_t)(cf - (cl - 8));
        car32(cl - 8) = len;
    }
}

static void lose_dead_hashtables(void)
/*
 * This splices out from the list of hash tables all entries that point to
 * tables that have not been marked or copied this garbage collection.
 */
{
    Lisp_Object *p = &eq_hash_tables, q, r;
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

#ifdef DEMO_MODE

extern CSLbool terminal_pushed;

void give_up()
{
    Lisp_Object nil;
#define m(s) err_printf(s)
m("\n+++ DEMONSTRATION VERSION OF REDUCE - RESOURCE LIMIT EXCEEDED +++\n");
m("This version of REDUCE has been provided for testing and\n");
m("demonstration purposes.  It has a built-in cut-out that will\n");
m("terminate processing after a time that should be sufficient for\n");
m("various small tests to run, but which will probably stop it\n");
m("from being useful as a serious tool.  You are permitted to copy\n");
m("the demonstration version and pass it on to friends subject to\n");
m("not changing it, and in particular neither changing the various\n");
m("messages it prints nor attempting to circumvent the time-out\n");
m("mechanism.  Full versions of REDUCE are available to run on a\n");
m("wide range of types of computer, and a machine-readable file\n");
m("listing suppliers was provided with the documentation that goes\n");
m("with this version.  Some suppliers are:\n");
m("  Codemist Ltd, Alta, Horsecombe Vale, Combe Down, Bath BA2 5QR,\n");
m("    England.  Phone and fax +44-225-837430,\n");
m("    http://www.codemist.co.uk\n");
m("  Winfried Neun, Konrad-Zuse-Zentrum fuer Informationstechnik Berlin\n");
m("    Heilbronner Str. 10, D 10711 Berlin-Wilmersdorf, GERMANY\n");
m("    Phone: +44-30-89604-195  Fax +49-30-89604-125.\n");
m("  (Codemist provided this version, the ZIB differs slightly)\n");
m("<Close window/type RETURN to exit>\n");
#undef m
    nil = C_nil;
    prompt_thing = CHAR_EOF;    /* Disables the prompt */
    ensure_screen();
    terminal_pushed = NOT_CHAR;
    tty_count = 0;
    char_from_terminal(0);      /* intended to delay until a char is typed */
    my_exit(EXIT_FAILURE);
}

#endif

#ifdef HAVE_FWIN

/*
 * I need a way that a thread that is not synchronised with this one can
 * generate a Lisp-level interrupt. I achieve that by
 * letting that thread reset stacklimit. Then rather soon CSL will
 * do a stackcheck() and will call reclaim with type GC_STACK.
 *
 * call this with
 *    arg=0 to have no effect at all (!)   QUERY_INTERRUPT
 *    arg=1 for a clock tick event         TICK_INTERRUPT
 *    arg=2 for quiet unwind               QUIET_INTERRUPT
 *    arg=3 for backtrace.                 NOISY_INTERRUPT
 * in each case the previous value of the flag is returned. Note that
 * I do not do a "test-and-set" here so do NOT treat this as a proper
 * start at a mutex or semaphore! However if I apply a rule that the
 * asynchronous (GUI) task only ever sets the flag to a non-zero value
 * and only ever tests then to see if it has been reset to zero, while the
 * main worker thread only reads it to check for non-zero and then
 * resets it I have some degree of sanity.
 */

static volatile int async_type = QUERY_INTERRUPT;

int async_interrupt(int type)
{
    int prev = async_type;
    if (type != QUERY_INTERRUPT)
    {   async_type = type;
        stacklimit = stackbase;
    }
    return prev;
}

#endif

static void report_at_end(Lisp_Object nil)
{
#ifdef WINDOW_SYSTEM
    {   int n = heap_pages_count + vheap_pages_count + bps_pages_count;
        int n1 = n + pages_count;
        double z = (100.0*n)/n1;
        report_space(gc_number, z);
        if (verbos_flag & 1) trace_printf(
           "At gc end about %.1f Mbytes of %.1f (%.1f%%) of heap is in use\n",
           ((double)n)*(CSL_PAGE_SIZE/(1024.0*1024.0)),
           ((double)n1)*(CSL_PAGE_SIZE/(1024.0*1024.0)), z);
    }
#else
    if (verbos_flag & 1)
    {   int n = heap_pages_count + vheap_pages_count + bps_pages_count;
        int n1 = n + pages_count;
        trace_printf(
            "At gc end about %.1f Mbytes of %.1f (%.1f%%) of heap is in use\n",
            (double)n*(CSL_PAGE_SIZE/(1024.0*1024.0)),
            (double)n1*(CSL_PAGE_SIZE/(1024.0*1024.0)),
            (100.0*n)/n1);
    }
#endif
}

#ifdef CONSERVATIVE

/*
 * The conservative collector needs to cope with some ambiguous pointers.
 * these must all be marked from, but the data that they seem to point to
 * must not be moved since the pointer must not be changed in any way in
 * case it is in fact not a pointer. To support that I need to be ready
 * to track and record all the ambiguous roots. I will use a hash table
 * as part of this process.
 */ 

Lisp_Object *C_stackbase, *C_stacktop;

void get_stacktop()
{
    volatile Lisp_Object sp;
    C_stacktop = (Lisp_Object *)&sp;
}

/*
 * I want the following number to be a prime to make some hash-table
 * activity work smoothly.
 * the LOAD value is to let the hash table become 7/8 full before I
 * give up on it.
 */
#define AMBIGUOUS_CACHE_SIZE 2003U
#define AMBIGUOUS_LOAD   ((7*AMBIGUOUS_CACHE_SIZE)/8)

static Lisp_Object ambiguous[AMBIGUOUS_CACHE_SIZE];
static int nambiguous;
static Lisp_Object *C_stack_remaining;

static CSLbool certainly_not_valid(Lisp_Object p)
{
    switch (p & (GC_BIT_P | 0x7))
    {
case TAG_CONS:

case TAG_SYMBOL:
case TAG_NUMBERS:
case TAG_VECTOR:
case TAG_BOXFLOAT:

default:
        return YES;
    }
}

typedef void process_ambiguous_pointer_t(Lisp_Object x);

static void scan_ambiguous(process_ambiguous_pointer_t *fn)
{
    unsigned int i;
    Lisp_Object *s;
    for (i=0; i<AMBIGUOUS_CACHE_SIZE; i++)
    {   Lisp_Object p = ambiguous[i];
        if (p == 0) continue;
        (*fn)(p);
    }
    for (s=C_stack_remaining; s<=C_stackbase; s++)
    {   Lisp_Object p = *s;
        if (certainly_not_valid(p)) continue;
        (*fn)(p);
    }
}

static void cache_ambiguous()
{
/*
 * This sets up my hash table of ambiguous pointers and MUST be called before
 * I use scan_ambiguous.
 */
    unsigned int i;
    Lisp_Object *s;
    for (i=0; i<AMBIGUOUS_CACHE_SIZE; i++) ambiguous[i] = 0;
    nambiguous = 0;
    for (s=C_stacktop; s<=C_stackbase && nambiguous<AMBIGUOUS_LOAD; s++)
    {   Lisp_Object p = *s;
        if (certainly_not_valid(p)) continue;
        i = (unsigned int)(((uintptr_t)p) % (uintptr_t)AMBIGUOUS_CACHE_SIZE);
        for (;;)
        {   if (ambiguous[i] == 0)
            {   ambiguous[i] = p;   /* enter new pointer into the table */
                nambiguous++;       /* count entries in the table */
                break;
            }
            else if (ambiguous[i] == p) break; /* seen before */
/*
 * I make my stride through the hash table depend on the value too, but
 * by having a table whose size is prime I will always eventually look in
 * every location.
 */
            i += 1 + (int)(((uintptr_t)p) %
                            (uintptr_t)(AMBIGUOUS_CACHE_SIZE-2));
        }
    }
}

#endif /* CONSERVATIVE */

Lisp_Object use_gchook(Lisp_Object p, Lisp_Object arg)
{
    Lisp_Object nil = C_nil;
    Lisp_Object g = gchook;
    if (symbolp(g) && g != unset_var)
    {   g = qvalue(g);
        if (symbolp(g) && g != unset_var)
        {   push(p);
            Lapply1(nil, g, arg);  /* Call the hook */
            errexitn(1);      /* the hook function failed */
            pop(p);
        }
    }
    return onevalue(p);
}

Lisp_Object reclaim(Lisp_Object p, char *why, int stg_class, intptr_t size)
{
    intptr_t i;
    clock_t t0, t1, t2, t3;
    Lisp_Object *sp, nil = C_nil;
    intptr_t vheap_need = 0, bps_need = 0, native_need = 0;
#ifdef DEBUG_GC
    term_printf("Start of a garbage collection %d\n", gc_number);
#endif
#ifdef CONSERVATIVE
/*
 * How do I know that all callee-save registers are on the stack by the
 * stage that I get to the level that C_stacktop now refers to???
 */
    get_stacktop();
    trace_printf("\n=== C stack size = %5d\n", (C_stackbase-C_stacktop)); 
    trace_printf("\n=== C_stackbase=%p C_stacktop=%p\n",
                        (void *)C_stackbase, (void *)C_stacktop); 
#endif /* CONSERVATIVE */
    stop_after_gc = 0;
    if (stg_class == GC_VEC) vheap_need = size;
    else if (stg_class == GC_BPS) bps_need = size;
    else if (stg_class == GC_NATIVE) native_need = size;
    already_in_gc = YES;
#ifdef WIN32
    _kbhit(); /* Fairly harmless anyway, but is here to let ^c get noticed */
/*    printf("(*)"); fflush(stdout);  /* while I debug! */
#endif
#ifdef SOCKETS
    if (socket_server != 0)
    {   time_t tt0 = time(NULL);
        t0 = clock();
        tt0 = time(NULL);
        if (t0 > cpu_timeout ||
            tt0 > elapsed_timeout)
        {   cpu_timeout = t0 + 20;
            elapsed_timeout = tt0 + 20;
            term_printf("\nSorry: timeout on this session. Closing down\n");
            return Lstop(nil, fixnum_of_int(1));
        }
    }
#endif

    push_clock(); t0 = base_time;

#ifdef HAVE_FWIN
/*
 * Life is a bit horrid here. I can have two significantly different sorts of
 * thing that cause this soft-GC to happen under FWIN. One is when I am in
 * windowed mode and FWIN provokes an asynchronous event for me. The other is
 * in non-windowed mode when my software_ticks counter overflows and does
 * a somewhat similar job... but from within this worker thread. The really
 * bad news is the thought of both of these active together, and so conflict
 * and confusion. Fresh and careful thought about that is needed before I
 * re-work this code.
 *
 * In non-windowed mode a problem I have is the detection of ^C interrupts.
 * Under Windows I have used SetConsoleMode (and under Unix/Linux tcsetattr)
 * to put the input into raw mode if it is direct from a keyboard. Thus
 * the operating system will not process ^C for me.
 */
    if (stg_class == GC_STACK && stacklimit == stackbase)
    {   stacklimit = savestacklimit;
        if (tick_pending)
        {   tick_pending = 0;
            heaplimit = saveheaplimit;
	    vheaplimit = savevheaplimit;
	    codelimit = savecodelimit;
	    stacklimit = savestacklimit;
        }
        tidy_fringes();
        already_in_gc = NO;
        pop_clock();
/*
 * There could, of course, be another async interrupt generated even during
 * this processing and certainly by the time I get into interrupted(),
 * and there could be "genuine" need for garbage collection or stack overflow
 * processing at any stage.
 */
        if (exception_pending()) nil = nil ^ 1;
        if (async_type == TICK_INTERRUPT)
        {   long int t = (long int)(100.0 * consolidated_time[0]);
            long int gct = (long int)(100.0 * gc_time);
            async_type = QUERY_INTERRUPT;     /* accepted! */
            fwin_acknowledge_tick();
            report_time(t, gct);
            return onevalue(p);
        }
        else if (async_type == NOISY_INTERRUPT)
            miscflags |= HEADLINE_FLAG | MESSAGES_FLAG;
        else miscflags &= ~MESSAGES_FLAG;
        async_type = QUERY_INTERRUPT;     /* accepted! */
        return interrupted(p);
    }
    else
#else /* HAVE_FWIN */
	if (interrupt_pending)
	{   if (tick_pending)
            {   tick_pending = 0;
                heaplimit = saveheaplimit;
	        vheaplimit = savevheaplimit;
	        codelimit = savecodelimit;
	        stacklimit = savestacklimit;
            }
	    tidy_fringes();
	    interrupt_pending = NO;
	    pop_clock();
	    return interrupted(p);
	}
#endif /* HAVE_FWIN */
    {   tidy_fringes();
        if (stg_class != GC_PRESERVE &&
            stg_class != GC_USER_HARD &&
            reset_limit_registers(vheap_need, bps_need, native_need, YES))
        {   already_in_gc = NO;
            pop_clock();
            return use_gchook(p, nil); /* Soft GC */
        }
    }

    if (stack >= stacklimit)
    {    if (stacklimit != stackbase)
        {   stacklimit = &stacklimit[50];  /* Allow a bit of slack */
            pop_clock();
            return error(0, err_stack_overflow);
        }
    }

#ifdef MEMORY_TRACE
#ifndef CHECK_ONLY
    identify_page_types();
    memory_comment(4);
#endif
#endif

#ifdef DEMO_MODE
    give_up();
    pop_clock();
    return nil;
#else
    push(p);

    gc_number++;

#ifdef WINDOW_SYSTEM
/*
 * If I have a window system I tell it the current time every so often
 * just to keep things cheery...
 */
    {   long int t = (long int)(100.0 * consolidated_time[0]);
        long int gct = (long int)(100.0 * gc_time);
/* /*
 * I guess that I want garbage collection messages, if any, to
 * be sent to stderr rather than whatever output stream happens to
 * be selected at the time of the garbage collection?
 * At present messages go to the normal output stream, which only makes
 * sense if GC messages are almost always disabled - maybe that will
 * be the case!
 */
        report_time(t, gct);
        if (verbos_flag & 1)
        {   freshline_trace();
            trace_printf(
        "+++ Garbage collection %ld (%s) after %ld.%.2ld+%ld.%.2ld seconds\n",
                 (long)gc_number, why, t/100, t%100, gct/100, gct%100);
        }
    }
#else
    if (verbos_flag & 1)
    {   long int t = (long int)(100.0 * consolidated_time[0]);
        long int gct = (long int)(100.0 * gc_time);
/* /* I guess that I want garbage collection messages, if any, to
 * be sent to stderr rather than whatever output stream happens to
 * be selected at the time of the garbage collection?
 * At present messages go to the normal output stream, which only makes
 * sense if GC messages are almost always disabled - maybe that will
 * be the case!
 */
        freshline_trace();
        trace_printf(
         "+++ Garbage collection %ld (%s) after %ld.%.2ld+%ld.%.2ld seconds\n",
         (long)gc_number, why, t/100, t%100, gct/100, gct%100);
    }
#endif
/*
 * If things crash really badly maybe I would rather have my output up
 * to date.
 */
    ensure_screen();
    nil = C_nil;
    if (exception_pending())
    {   stop_after_gc = 1;
        flip_exception();
    }
    if (spool_file != NULL) fflush(spool_file);

#ifdef CONSERVATIVE
/*
 * if stg_class==GC_PRESERVE I will not need to process the C stack and
 * the Lisp stack ought to be empty. Otherwise here is where I start to
 * capture the set of ambiguous pointers that are in play.
 */
    if (stg_class != GC_PRESERVE)
    {   cache_ambiguous();
    }
#endif /* CONSERVATIVE */

    copy_into_nilseg(NO);

    cons_cells = symbol_heads = strings = user_vectors =
             big_numbers = box_floats = bytestreams = other_mem =
             litvecs = getvecs = 0;

/*
 * Here I need to sort of what sort of GC I should do. In the new world
 * here I should do a conservative mostly-copying one most of the time, but
 * the GC from "preserve" can afford to be a full and proper one that
 * does not worry about junk on the C stack, that can assume everything it
 * finds in a List Base is a valid Lisp object and so it can compact
 * perfectly.
 */

    t2 = t1 = t0;   /* Time is not split down in this case */
/*
 * Set up the new half-space initially empty.
 */
    new_heap_pages_count = 0;
    new_vheap_pages_count = 0;
    new_bps_pages_count = 0;
    trailing_heap_pages_count = 1;
    trailing_vheap_pages_count = 1;
    {   void *pp = pages[--pages_count];
        char *vf, *vl;
        int32_t len;
/*
 * A first page of (cons-)heap
 */
        zero_out(pp);
        new_heap_pages[new_heap_pages_count++] = pp;
        heaplimit = quadword_align_up((intptr_t)pp);
        car32(heaplimit) = CSL_PAGE_SIZE;
        vl = (char *)heaplimit;
        fringe = (Lisp_Object)(vl + CSL_PAGE_SIZE);
        heaplimit = (Lisp_Object)(vl + SPARE);
#ifdef DEBUG_GC
        term_printf("fr = %p, hl = %p\n", (void *)fringe, (void *)heaplimit);
#endif
/*
 * A first page of vector heap.
 */
        pp = pages[--pages_count];
        zero_out(pp);
        new_vheap_pages[new_vheap_pages_count++] = pp;
        vf = (char *)doubleword_align_up((intptr_t)pp) + 8;
        vfringe = (Lisp_Object)vf;
        vl = vf + (CSL_PAGE_SIZE - 16);
        vheaplimit = (Lisp_Object)vl;
        len = (int32_t)(vf - (vl - (CSL_PAGE_SIZE - 8)));
        car32(vl - (CSL_PAGE_SIZE - 8)) = len;
/*
 * The BPS heap can start of utterly non-existent.
 */
        codefringe = codelimit = 0;
    }

/*
 * The very first thing that I will copy will be the main object-vector,
 * this is done early to ensure that it gets a full empty page of vector
 * heap to fit into.
 */
#ifdef DEBUG_GC
    term_printf("About to copy the object vector\n");
#endif
    copy(&BASE[current_package_offset]);
/*
 * The above line is "really"
 *          copy(&current_package);
 * but I use an offset into the nilseg in explicit form because otherwise
 * there is a big foul-up with the NILSEG_EXTERNS option...  Sorry!
 */

/*
 * I should remind you, gentle reader, that the value cell
 * and env cells of nil will always contain nil, which does not move,
 * and so I do not need to copy them here.
 */
#ifdef DEBUG_GC
    term_printf("About to copy NIL\n");
#endif
    copy(&(qplist(nil)));
    copy(&(qpname(nil)));
    copy(&(qfastgets(nil)));
#ifdef COMMON
    copy(&(qpackage(nil)));
#endif

/*
 * I dislike the special treatment of current_package that follows. Maybe
 * I should arrange something totally different for copying the package
 * structure...
 */
    for (i = first_nil_offset; i<last_nil_offset; i++)
        if (i != current_package_offset)
        {
        /* current-package - already copied by hand */
#ifdef DEBUG_GC
            term_printf("About to copy list-base %d\n", i);
#endif
            copy(&BASE[i]);
        }

#ifdef DEBUG_GC
    term_printf("About to copy the stack\n");
#endif
    for (sp=stack; sp>(Lisp_Object *)stackbase; sp--) copy(sp);
#ifdef DEBUG_GC
    term_printf("Stack processed\n");
#endif
/*
 * Now I need to perform some magic on the list of hash tables...
 */
    lose_dead_hashtables();
#ifdef DEBUG_GC
    term_printf("About to copy eq hash tables\n");
#endif
    copy(&eq_hash_tables);
#ifdef DEBUG_GC
    term_printf("About to copy equal hash tables\n");
#endif
    copy(&equal_hash_tables);

#ifdef DEBUG_GC
    term_printf("About to tidy fringes and finish up\n");
#endif
    tidy_fringes();

/*
 * Throw away the old semi-space - it is now junk.
 */
    while (heap_pages_count!=0)
        pages[pages_count++] = heap_pages[--heap_pages_count];
    while (vheap_pages_count!=0)
        pages[pages_count++] = vheap_pages[--vheap_pages_count];
    while (bps_pages_count!=0)
        pages[pages_count++] = bps_pages[--bps_pages_count];

/*
 * Flip the descriptors for the old and new semi-spaces.
 */
    {   void **w = heap_pages;
        heap_pages = new_heap_pages;
        new_heap_pages = w;
        w = vheap_pages;
        vheap_pages = new_vheap_pages;
        new_vheap_pages = w;
        w = bps_pages;
        bps_pages = new_bps_pages;
        new_bps_pages = w;
        heap_pages_count = new_heap_pages_count;
        new_heap_pages_count = 0;
        vheap_pages_count = new_vheap_pages_count;
        new_vheap_pages_count = 0;
        bps_pages_count = new_bps_pages_count;
        new_bps_pages_count = 0;
    }

    {   Lisp_Object qq;
/*
 * Note that EQUAL hash tables do not need to be rehashed here, though
 * they do if a heap image is exported from one system to another.
 */
        for (qq = eq_hash_tables; qq!=nil; qq=qcdr(qq))
            rehash_this_table(qcar(qq));
    }

    gc_time += pop_clock();
    t3 = base_time;

    copy_out_of_nilseg(NO);

    if ((verbos_flag & 5) == 5)
/*
 * (verbos 4) gets the system to tell me how long each phase of GC took,
 * but (verbos 1) must be ORd in too.
 */
    trace_printf("Copy %ld ms\n",
        (long int)(1000.0 * (double)(t3-t0)/(double)CLOCKS_PER_SEC));

/* (verbos 5) causes a display breaking down how space is used */
    if ((verbos_flag & 5) == 5)
    {   trace_printf(
            "cons_cells=%d, symbol_heads=%d, strings=%d, user_vectors=%d\n",
             cons_cells, symbol_heads, strings, user_vectors-litvecs-getvecs);
        trace_printf(
            "bignums=%d, floats=%d, bytestreams=%d, other=%d, litvecs=%d\n",
            big_numbers, box_floats, bytestreams, other_mem, litvecs);
        trace_printf("getvecs=%d\n", getvecs);
    }

    pop(p);

    if (!reset_limit_registers(vheap_need, bps_need, native_need, NO))
    {   if (stack < stacklimit || stacklimit != stackbase)
        {   report_at_end(nil);
            term_printf("\n+++ No space left at all\n");
            my_exit(EXIT_FAILURE);    /* totally drastic... */
        }
    }
#ifndef MEMORY_TRACE
/*
 * Here I grab more memory (if I am allowed to).
 * An initial version here, and one still suitable on machines that will
 * have plenty of real memory, will be to defined ok_to_grab_memory(n) as
 * 3*n + 2. This expands until the proportion of the heap active at the
 * end of garbage collection is less than 1/4.
 * If the attempt to grab more memory fails I clear the bit in init_flags
 * that allows me to try to expand, so I will not waste time again.  If
 * HOLD_BACK_MEMORY was asserted (for machines where grabbing all seemingly
 * available memory may cause a crash) I do not try this operation.  The
 * aim of keeping the heap less than half full is an heuristic and could be
 * adjusted on the basis of experience with this code.
 * The "+2" at the end of calculating the ideal heap size is intended
 * to keep us (mostly) in the copying GC domain.  If it is omitted the
 * heap tends to stay just 25% full and sliding GC is used. Overall this is
 * roughly as expensive as copying, but it is more disruptive since it comes
 * in larger gulps.
 * On systems where it is possible to measure the amount of available
 * real memory more sophisticated calculations may be possible.
 */
    if (init_flags & INIT_EXPANDABLE)
    {   int ideal = ok_to_grab_memory(heap_pages_count +
                                      vheap_pages_count +
                                      bps_pages_count);
        int more;
        if (ideal > MAX_PAGES) ideal = MAX_PAGES;
        more = ideal - pages_count;
        while (more-- > 0)
        {   void *page = (void *)my_malloc((size_t)(CSL_PAGE_SIZE + 8));
            intptr_t pun, pun1;
/*
 * When I first grabbed memory in restart.c I used my_malloc_1(), which
 * gobbles a large stack frame and then called regular malloc - the idea
 * there was to avoid malloc grabbing space needed for the stack. I can
 * not properly do that here since reclaim() may be called with a deep
 * stack already active.  There is thus a danger that expanding the heap here
 * may cause me to run out of stack elsewhere.  Oh well, I guess I can not
 * win in all ways.
 */
/*
 * Verify that new block does not span zero & has correct sign bit
 */
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
#endif /* MEMORY_TRACE */
    report_at_end(nil);
    if (stop_after_gc)
    {
#ifdef MEMORY_TRACE
#ifndef CHECK_ONLY
        memory_comment(15);
#endif
#endif
        return Lstop(nil, fixnum_of_int(0));
    }
#ifdef MEMORY_TRACE
#ifndef CHECK_ONLY
    memory_comment(15);
#endif
#endif
    if (interrupt_pending)
    {   interrupt_pending = NO;
        already_in_gc = NO;
        tick_on_gc_exit = NO;
        return interrupted(p);
    }
    already_in_gc = NO;
    return use_gchook(p, lisp_true);
#endif /* DEMO_MODE */
}

/* end of file gc.c */
