/* tags.h                               Copyright (C) Codemist 1990-2008 */

/*
 *   Data-structure and tag bit definitions, also common C macros
 *   for Lisp implementation.
 *
 */



/**************************************************************************
 * Copyright (C) 2008, Codemist Ltd.                     A C Norman       *
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

/* Signature: 593d661a 05-Jun-2008 */


#ifndef header_tags_h
#define header_tags_h 1

/*
 * These days I have make autoconf stuff check to see if the standard
 * header that defines known-size integer types is available. And then
 * in "headers.h" I patch things up for old systems where it is not present,
 * at least as best I can manage.
 */

#ifndef HAVE_INT32_T
#error This system needs a 32-bit integer type.
#endif

#define SIXTY_FOUR_BIT (sizeof(intptr_t) == 8)

typedef int                 CSLbool;

#define YES                 1
#define NO                  0

/*
 * I allocate memory (using malloc()) in CSL_PAGE_SIZE chunks.
 * This was first implemented for the benefit of 16-bit machines
 * (in particular MSDOS/286) but now seems generally reasonable.  The biggest
 * menace about it is that it limits the size of the largest vector I can ever
 * allocate - and this (as of the time of this comment) limits the size of
 * the symbol table (object list).
 *
 * My default at present is to use PAGE_BITS=22, which leads to 4 Mbyte pages.
 * I use that size on both 32 and 64-bit machines, which will mean that
 * 32 bit systems can support vectors that are longer than will fit into
 * a 64-bit system.
 *
 * Once upon a time I used 16-bit pages. For small hardware (such as a PDA)
 * I sometimes make my Makefile downgrade this to use 18-bit (256Kbyte)
 * pages to save some waste.
 */

#ifndef PAGE_BITS
#  define PAGE_BITS             22
#endif /* PAGE_BITS */

#define PAGE_POWER_OF_TWO       (((uint32_t)1) << PAGE_BITS)
/*
 * When I come to allocate memory I do so in chunks that are a little less
 * than the power of two suggested here, to allow for malloc() header
 * blocks etc.
 */
#define CSL_PAGE_SIZE           (PAGE_POWER_OF_TWO - 256U)

/*
 * On 64-bit systems I will limit myself to 20 Gbyte, while on 32-bit
 * ones the limit is around 2 Gbyte and in reality will usually be
 * rather less than that.
 */
#ifndef MAX_HEAPSIZE
#  define MAX_HEAPSIZE       (SIXTY_FOUR_BIT ? 20480 : 2048)
#endif /* MAX_HEAPSIZE */

#ifndef MAX_BPSSIZE
/*
 * Note once again that 64 (megabytes) is the largest valid value that can be
 * used here.  But also note that 64 Mbytes of bytecodes would be a pretty
 * large program!
 */
#  define MAX_BPSSIZE           64
#endif /* MAX_BPSSIZE */

#define MEGABYTE                ((uint32_t)0x100000U)

#if PAGE_BITS >= 20
#define MAX_PAGES               (MAX_HEAPSIZE >> (PAGE_BITS-20))
#define MAX_BPS_PAGES           (MAX_BPSSIZE >> (PAGE_BITS-20))
#else
#define MAX_PAGES               (MAX_HEAPSIZE << (20-PAGE_BITS))
#define MAX_BPS_PAGES           (MAX_BPSSIZE << (20-PAGE_BITS))
#endif

#define MAX_NATIVE_PAGES        MAX_BPS_PAGES

#define PAGE_MASK               ((((uint32_t)1) << (32-PAGE_BITS)) - 1)
#define OFFSET_MASK             ((((uint32_t)1) << PAGE_BITS) - 1)

#define CSL_IGNORE(x)           (x = x)

/*
 * Windows seems to say it can use file names up to 260 chars, Unix and
 * the like may not even have that limit, but I will assume something here.
 * There must be a number of cases of potential buffer overflow throughout
 * my code caused by this fixed limit.
 */
#define LONGEST_LEGAL_FILENAME 1024

/*
 * The following values relate to the identification of floating
 * point representations.  Note that they all fit in a byte. Actually these
 * days I think I will INSIST that the basic representation is as per IEEE,
 * but there can still be word and byte-order issues.
 * I am going to assume that if the byte order if "flipped" in a double
 * then it will be in a float too. And I will not support any really
 * odd cases where bits are messed around with halfword by halfword!
 */

#define FP_WORD_ORDER 0x01
#define FP_BYTE_ORDER 0x02
#define FP_MASK       0xff


/*
 * General objects in Lisp are represented as pointer-sized integers
 * and the type Lisp_Object reflects this representation and
 * not the elaborate tagged union that at some other level exists.
 * If I could use "void *" for this type that might give me a bit more
 * security since not much can be done with a "void *" object - in particular
 * it can not participate in arithmetic.  But when I do that I run into
 * trouble in protected mode on a PC if I have items of type Lisp_Object
 * that are not valid pointers. I suspect that the same used to be
 * the case on a Motorola 68000 with address and data registers.
 */
/*
 * Sometimes the pointer-sized integer will be 64-bits wide, and will be the
 * data type for the type Lisp_Object. A result will be that anywhere in
 * the code where I am sloppy about putting such an object into an int32_t
 * I will have trouble, and anywhere that I use absolute numeric offsets
 * instead of multiples of sizeof(Lisp_Object) there can be pain.
 * Coping with this means I have to be careful about integer constants that
 * could fit into 64 but not 32-bits.
 */

typedef intptr_t Lisp_Object;


/*
 * The macro CELL had better have either the value 4 or 8. It is the
 * size of the basic unit of memory within which CSL works.
 */

#define CELL sizeof(Lisp_Object)

/*
 * Lisp_Object is a datatype where the low 3 bits are used as tags -
 * this idea works provided all memory addresses needed can be kept
 * doubleword aligned.  The main tag allocation is documented here.
 */

#define TAG_BITS        7

#define TAG_CONS        0   /* Cons cells (and for Common Lisp, the special */
                            /* case of NIL */
#define TAG_FIXNUM      1   /* 28-bit integers */
#define TAG_ODDS        2   /* Char constants, BPS addresses, vechdrs etc */
#ifdef COMMON
#define TAG_SFLOAT      3   /* Short float, 28 bits of immediate data */
#endif /* COMMON */
#define TAG_SYMBOL      4   /* Symbols (maybe except for NIL) */
#define TAG_NUMBERS     5   /* Bignum, Rational, Complex */
#define TAG_VECTOR      6   /* Regular Lisp vectors (except BPS maybe?) */
#define TAG_BOXFLOAT    7   /* Boxed floats */

/*
 * For each of the above tag classes I have a bunch of low-level
 * operations that need support - including type identification
 * predicates and conversions to and from native C formats.
 */

#define fixnum_of_int(x)    ((Lisp_Object)(TAG_FIXNUM + (((int32_t)(x)) << 4)))
/*
 * The multiple casts here are (a) to ensure that the shift is done
 * treating x as a signed value and (b) to stress that the shift is
 * done in an integer context. Note also that I would with a 32-bit
 * value here even on 64-bit machines. That is wasteful, but adapting to
 * use all the bits is a bigger change than I am prepared to contemplate
 * just now.
 */
#ifdef SIGNED_SHIFTS_ARE_LOGICAL
/* 
 * Beware - arg evaluated several time in this case. Also
 * note that even if I am using a 64-bit machine this turns a 64-bit
 * LispObject into a 32-bit integer
 */
#define int_of_fixnum(x)    ((int32_t)(((int32_t)(x)) < 0 ?           \
                             (((int32_t)(x))>>4) | (-0x10000000) :  \
                             (((int32_t)(x))>>4)))
#else /* SIGNED.. */
/*
 * Note that for 64-bit machines I expect the top 32 bits of a fixnum 
 * all to be copies of the sign bit. Of course I might imagine changing that
 * sometime later but for now it is the only reasonable way forward.
 */
#define int_of_fixnum(x)    ((int32_t)(((int32_t)(x)) >> 4))
#endif /* SIGNED .. */

/*
 * The garbage collector needs a spare bit in EVERY word...
 */

#define GC_BIT_I        8               /* Used with FIXNUM, CHAR, SFLOAT */
#define GC_BIT_H        8               /* Used in Header words */

#define GC_BIT_P        ((intptr_t)~((~(uintptr_t)0) >> 1))
/*
 * The above curious definition of GC_BIT_P is intended to ensure that
 * it looks like a negative value. This matters a lot if there is some
 * 64-bit arithmetic lurking somewhere, because then what goes on in the
 * upper 32 bits can come and bite me.  I will try to avoid trouble by
 * having all constants in this code written in a way that avoids any
 * need for explicit 'L' suffices. So this one goes
 *      00000000      0000000000000000   zero, cast to uintptr_t
 *      ffffffff      ffffffffffffffff   complement
 *      7fffffff      7fffffffffffffff   shift right one, NB unsigned
 *      80000000      8000000000000000   complement again, and cast to signed!
 * I really hope that the compiler processes this constant expression at
 * compile time, and that it gets the calculation right!
 */

/*
 * Here I assume that all valid pointers EITHER have top bit zero OR have
 * top bit one.  If this is so I can flip the top bit in a pointer to mark
 * things for the garbage collector.  Beware, I suppose, stack-allocated
 * objects on a VAX.  But note that garbage collection is only really
 * interested in the heap, which can probably be kept within one half of
 * the address space.  The nastiest case I have come across so far is
 * the Intel 80x86 where addresses spread over all 32 bits of a long int,
 * in a rather wasteful way.  For that very special machine I have to
 * invent specialist storage management schemes!
 *
 * [November 2003] Note well that many Linux systems are configured with
 * 3G of user space and 1G of systerm space within the 4G address map of a
 * 32-bit architecture. This can cause it to seem as if over 2G of memory
 * can be issued to the user. It also means that when amounts of memory
 * around a Gbyte are being allocated just where in the memory map things
 * are gets jolly uncertain and delicate. Specifically it may depend on the
 * excat version of Linux that you run. It all feels a big misery to me.
 * using that top bit could be held to be a mistake!
 */

#define is_marked_i(w)      (((int)(w) & GC_BIT_I) != 0)

/*
 * I assume that in any one run of CSL either all (malloc)
 * addresses have their top bit set OR all have their top bit clear, but
 * I can not predict in advance which case will apply.  This miserable
 * state arises with Win32 - under Windows-NT addresses are in the range
 * 0 to 0x7fffffff, while the same binary executing under Win32s has
 * addresses in the range 0x80000000 to 0xffffffff.
 * Note that many Linux (and maybe other) systems use the top 1G of a
 * 4G space for system, with the lower 3G for user space. Some will let
 * malloc return space above or below the 2G mark in a way that the user can
 * not easily control. Those worried need to move to 64 bit machines soon.
 */

extern Lisp_Object address_sign;  /* 0, 0x80000000 or 0x8000000000000000 */
#define is_marked_p(w)      (((Lisp_Object)(w) - address_sign) < 0)
#define clear_mark_bit_p(w) (((Lisp_Object)(w) & ~GC_BIT_P) + \
                              address_sign)

#define flip_mark_bit_i(w)  ((Lisp_Object)(w) ^ GC_BIT_I)
#define flip_mark_bit_h(w)  ((Header)(w) ^ GC_BIT_H)
#define flip_mark_bit_p(w)  ((Lisp_Object)(w) ^ GC_BIT_P)
#define is_marked_h(w)      (((int)(w) & GC_BIT_H) != 0)

/*
 * Exceptions are marked by setting a bit in NIL.  The following macros
 * provide an abstraction of this interface.  At one stage I used the
 * most significant bit in nil, but now for various reasons I have concluded
 * that it is nicer to use the least significant bit.
 */
#define exception_pending() (((int)nil & 1) != 0)
#define flip_exception()    (nil = C_nil = (nil ^ 1))

#define ignore_exception() \
   do { nil = C_nil; if (exception_pending()) flip_exception(); } while (0)

#define set_mark_bit_h(h)   ((Header)(h) | GC_BIT_H)
#define clear_mark_bit_h(h) ((Header)(h) & ~GC_BIT_H)
#define set_mark_bit_i(h)   ((Lisp_Object)(h) | GC_BIT_I)
#define clear_mark_bit_i(h) ((Lisp_Object)(h) & ~GC_BIT_I)

#define is_cons(p)   ((((int)(p)) & TAG_BITS) == TAG_CONS)
#define is_fixnum(p) ((((int)(p)) & TAG_BITS) == TAG_FIXNUM)
#define is_odds(p)   ((((int)(p)) & TAG_BITS) == TAG_ODDS) /* many subcases */
#ifdef COMMON
#define is_sfloat(p) ((((int)(p)) & TAG_BITS) == TAG_SFLOAT)
#endif /* COMMON */
#define is_symbol(p) ((((int)(p)) & TAG_BITS) == TAG_SYMBOL)
#define is_numbers(p)((((int)(p)) & TAG_BITS) == TAG_NUMBERS)
#define is_vector(p) ((((int)(p)) & TAG_BITS) == TAG_VECTOR)
#define is_bfloat(p) ((((int)(p)) & TAG_BITS) == TAG_BOXFLOAT)

#ifdef COMMON
/*
 * The next two lines reveal a possible cause of great confusion -
 * but one that is motivated by the desire that car/cdr should be
 * cheap to implement.  is_cons detects cons cells OR nil, and
 * is_symbol detects symbols EXCEPT nil.  The following two macros
 * implement the tests that probably seem more natural.
 */

#define consp(p)     (is_cons(p) && (p) != nil)
#define symbolp(p)   (is_symbol(p) || (p) == nil)
#else /* COMMON */
/* In Standard Lisp mode I tag nil as a symbol, and life is easier */
#define consp(p)     is_cons(p)
#define symbolp(p)   is_symbol(p)
#endif /* COMMON */

/*
 * The next definition is fun!  In Common Lisp mode I want (car nil) to
 * be legal, and that is some of the motivation for tagging NIL as if
 * it had been a cons cell.  In Standard Lisp (car nil) is invalid.
 * I consider it important to make this test fast, which is why I have
 * made it just use the tag field of a value. There is a HORRID MESS whereby
 * on 64-bit machines the general low-bit tagging of symbols will mean that
 * access to NIL as a symbol would give problems because of NIL's tag as
 * a cons cell (on 32-bit systems I get away with it!). This is handled
 * later on by putting address masks in all symbol-component access in the
 * hard case.
 */
#define car_legal(p) is_cons(p)

/*
 * The tag codes have been selected so that various useful tests
 * can be done especially cheaply - here are some of those
 * composite tests.
 */

#define is_number(p) ((((int)(p)) & 1) != 0) /* Any numeric type */
#define is_float(p)  ((((int)(p)) & 3) == 3) /* Big or small float */

/*
 * immed_or_cons is a rather funny case, in that it includes
 * the ODDS tag, which may include segment/offset addresses of BPS
 * or environment vectors.  Anyway, whatever else, the immed_() test
 * indicates something that does not contain a natural direct C
 * pointer.
 */

#define is_immed_or_cons(p) ((((int)(p)) & 4) == 0)

typedef struct Cons_Cell
{
    Lisp_Object car;
    Lisp_Object cdr;
} Cons_Cell;

#ifdef MEMORY_TRACE

/*
 * The IDEAL here would be that every time I reference memory I would
 * call memory_reference() to record this fact. In fact I have changed
 * the most important Lisp data-structure access macros to do this, but
 * not all of them. For instance in a first pass I did not consider it
 * worth altering the code that inspects rational and complex numbers!
 * Any code that at the C level uses "*" directly will also not get
 * reported.
 */

extern Cons_Cell *memory_reference(intptr_t p);
extern char *cmemory_reference(intptr_t p);
extern void identify_page_types();
extern long int car_counter;
extern unsigned long int car_low, car_high;

#define qcar(p) (memory_reference((intptr_t)p)->car)
#define qcdr(p) (memory_reference((intptr_t)p)->cdr)

#else /* MEMORY_TRACE */

#define qcar(p) (((Cons_Cell *) (p))->car)
#define qcdr(p) (((Cons_Cell *) (p))->cdr)

#endif /* MEMORY_TRACE */

/*
 * car32(p) refers to the 32-bit integer pointed at by p. It is
 * used to cope with various bits of junk at the start and end of
 * "pages" of memory where (eg) the amount of the page that is in
 * use needs to be recorded.
 */

#define car32(p) (*(int32_t *)(p))

typedef Lisp_Object Special_Form(Lisp_Object, Lisp_Object);

typedef Lisp_Object one_args(Lisp_Object, Lisp_Object);
typedef Lisp_Object two_args(Lisp_Object, Lisp_Object, Lisp_Object);
typedef Lisp_Object MS_CDECL n_args(Lisp_Object, int, ...);


/*
 * Headers are also Lisp_Objects, but I give them a separate typedef
 * name to help me keep their identity separate.  There is only any
 * chance of headers and other objects getting confused during
 * garbage collection, and the code there has to be rather on the
 * careful side.  By making Headers unsigned I help the length
 * calculation on them.
 */

typedef uintptr_t Header;

/*
 * An object can be up to 4 Mbytes long, and has 12 bits of tag + GC info
 * in its header word.  All header words have TAG_ODDS in their low order
 * 4 bits, then 6 more bits that identify what sort of object is being
 * headed.  The remaining 22 bits give the length (in bytes) of the
 * active part of the object.  Note well that this really is a limitation
 * on the largest size of an object, and it prevents me from having
 * vectors or bignums larger than 4 Mbytes regardless of the "page"
 * structure of my memory. Well on 64-but machine I will be
 * able to relax that sometime in the future - but not just now please. So
 * observe that right now I limit lengths to 32-bit values. I guess
 * that actually since a Header is 64-bits in the 64-bit case this
 * still lets me have objects up to 4 Gbytes large...
 */

#define header_mask          0x3f0
#define type_of_header(h)    (((unsigned int)(h)) & header_mask)
#define length_of_header(h)  (((uint32_t)(h)) >> 10)

/* Values for the type field in a header */

/*
 * Symbols are so important that they have 26 bits used to sub-classify them.
 * These are used by the interpreter to identify special variables, special
 * forms, and those symbols which are defined as macros.  The bits live where
 * other items would store a length, but since all symbol headers are the
 * same size an explicit length field is not necessary - but missing one out
 * means that I have to do a special check for the SYMBOL case whenever I
 * scan the vector heap, which is a bit messy.
 */

#define TYPE_SYMBOL         0x00000010
#define  SYM_SPECIAL_VAR    0x00000040  /* (fluid '(xxx))  */
#define  SYM_GLOBAL_VAR     0x00000080  /* (global '(xxx)) */
#define  SYM_SPECIAL_FORM   0x00000100  /* eg. COND, QUOTE */
#define  SYM_MACRO          0x00000200  /* (putd 'xxx 'macro ...) */
#define  SYM_C_DEF          0x00000400  /* has definition from C kernel */
#define  SYM_CODEPTR        0x00000800  /* just carries code pointer */
#define  SYM_ANY_GENSYM     0x00001000  /* gensym, printed or not */
#define  SYM_TRACED         0x00002000
#define  SYM_FASTGET_MASK   0x000fc000  /* used to support "fast" gets */
#define  SYM_FASTGET_SHIFT  14
/*
 * In Common Lisp mode I use the rest of the header to help speed up
 * test for the availability of a symbol in a package (while I am printing).
 * In Standard Lisp mode I only allocate a print-name to a gensym when I
 * first print it, so I have a bit that tells me when a gensym is still
 * not printed.
 */
#ifdef COMMON
#define  SYM_EXTERN_IN_HOME 0x00100000  /* external in its home package */
#define  SYM_IN_PACKAGE     0xffe00000  /* availability in 11 packages */
#define  SYM_IN_PKG_SHIFT   23
#define  SYM_IN_PKG_COUNT   11
#else /* COMMON */
#define  SYM_UNPRINTED_GENSYM 0x00100000/* not-yet-printed gensym */
#endif /* COMMON */

#define symhdr_length       ((sizeof(Symbol_Head) + 7) & ~7)
#define is_symbol_header(h) (((int)h & 0x30) == TYPE_SYMBOL)
#define header_fastget(h)   (((h) >> SYM_FASTGET_SHIFT) & 0x3f)

#define TYPE_BIGNUM         0x020   /* low 2-bits = '10' for numbers */
#ifdef COMMON
#define TYPE_RATNUM         0x060
#define TYPE_COMPLEX_NUM    0x0a0
#define TYPE_SINGLE_FLOAT   0x120
#endif /* COMMON */
#define TYPE_DOUBLE_FLOAT   0x160
#ifdef COMMON
#define TYPE_LONG_FLOAT     0x1a0
#endif /* COMMON */

#ifdef MEMORY_TRACE
#define numhdr(v) (*(Header *)memory_reference((intptr_t)((char *)(v) - \
                                               TAG_NUMBERS)))
#define flthdr(v) (*(Header *)memory_reference((intptr_t)((char *)(v) - \
                                               TAG_BOXFLOAT)))
#else
#define numhdr(v) (*(Header *)((char *)(v) - TAG_NUMBERS))
#define flthdr(v) (*(Header *)((char *)(v) - TAG_BOXFLOAT))
#endif

#define is_numbers_header(h) (((int)(h) & 0x330) == 0x020)
#define is_boxfloat_header(h)(((int)(h) & 0x330) == 0x120)

#ifdef COMMON
/*
 * The following tests are valid provided that n is already known to
 * have tag TAG_NUMBERS, i.e. it is a bignum, ratio or complex.
 */
#define is_ratio(n) \
    (type_of_header(numhdr(n)) == TYPE_RATNUM)

#define is_complex(n) \
    (type_of_header(numhdr(n)) == TYPE_COMPLEX_NUM)

#endif /* COMMON */

#define is_bignum_header(h) (type_of_header(h) == TYPE_BIGNUM)

#define is_bignum(n) is_bignum_header(numhdr(n))

/*
 * I very much hope that sensible C compilers will observe that the
 * value SIXTY_FOUR_BIT is a constant (but I am not allowed to know its
 * value at preprocessor time) and so will simplify this apparent test
 * so that at run-time you just use the value 2 or 3.
 */
#define ADDRESS_SHIFT (SIXTY_FOUR_BIT ? 3 : 2)

#ifdef MEMORY_TRACE
#define vechdr(v)  (*(Header *)memory_reference((intptr_t)((char *)(v) - \
                               TAG_VECTOR)))
#define elt(v, n)  (*(Lisp_Object *)memory_reference((intptr_t)((char *)(v) + \
                               (CELL-TAG_VECTOR) + \
                               (((intptr_t)(n))<<ADDRESS_SHIFT))))
#define celt(v, n) (*cmemory_reference((intptr_t)((char *)(v) + \
                               (CELL-TAG_VECTOR)+((intptr_t)(n)))))
#define ucelt(v, n) (*(unsigned char *)cmemory_reference( \
                               (intptr_t)((char *)(v) + \
                               (CELL-TAG_VECTOR)+((intptr_t)(n)))))
#define scelt(v, n) (*(signed char *)cmemory_reference( \
                               (intptr_t)((char *)(v) + \
                               (CELL-TAG_VECTOR)+((intptr_t)(n)))))
#else /* MEMORY_TRACE */

#define vechdr(v)  (*(Header *)((char *)(v) - TAG_VECTOR))
#define elt(v, n)  (*(Lisp_Object *)((char *)(v) + \
                               (CELL-TAG_VECTOR) + \
                               (((intptr_t)(n))<<ADDRESS_SHIFT)))
#define celt(v, n) (*((char *)(v) + (CELL-TAG_VECTOR)+((intptr_t)(n))))
#define ucelt(v, n) (*((unsigned char *)(v) + (CELL-TAG_VECTOR)+((intptr_t)(n))))
#define scelt(v, n) (*((signed char *)(v) + (CELL-TAG_VECTOR)+((intptr_t)(n))))

#endif /* MEMORY_TRACE */

/*
 * The next are for 16-bit & 32 bit values and single-float & double-float 
 * access. Note that halfwords are signed.
 */
/*
 * On the DEC Alpha the C compiler did not provide a 16-bit data type.
 * In some sense the ARM does not really have one. I am expecting that
 * 16-bit values will only be used in a very few places in my code so
 * performance will not be vital here, so I implement 16-bit access as
 * pairs of 8-bit transfers.
 * NOTE NOTE NOTE that by doing this I am imposing my own idea of
 * byte ordering on 16-bit values in memory. But if the two macros
 * hare are the only use I make I will be safe unless a preserve/restart
 * operation flips things around for me!
 */
#define helt(v, n) \
   ((*(unsigned char *)((v) + (CELL-TAG_VECTOR) + (2*(intptr_t)(n))) | \
    (*(signed char *)((v) + (CELL-TAG_VECTOR+1) + (2*(intptr_t)(n)))) << 8))
#define sethelt(v, n, x) \
   do { \
      *(char *)((v) + (CELL-TAG_VECTOR+0) + (2*(intptr_t)(n))) = (x); \
      *(char *)((v) + (CELL-TAG_VECTOR+1) + (2*(intptr_t)(n))) = (x)>>8; \
      } while (0)
#define ielt(v, n)  (*(intptr_t *)((char *)(v) + \
                           (CELL-TAG_VECTOR)+(((intptr_t)(n))<<ADDRESS_SHIFT)))
/*
 * Even on a 64-bit machine I will support packed arrays of 32-bit
 * ints or short-floats.
 */
#define ielt32(v, n)  (*(int32_t *)((char *)(v) + \
                           (CELL-TAG_VECTOR)+(((intptr_t)(n))<<2)))
#define felt(v, n)  (*(float *)((char *)(v) + \
                           (CELL-TAG_VECTOR)+(((intptr_t)(n))<<2)))
/* NB doubles are 64-bits on every machine */
#define delt(v, n)  (*(double *)((char *)(v) + \
                           (2*CELL-TAG_VECTOR)+(((intptr_t)(n))<<3)))

#ifdef COMMON
/*
 * Simple bit-vectors need extra information held here so that their exact
 * can be determined.  Generally headers hold length information measured
 * in bytes, so three more bits are required here. Bitvectors are not
 * supported in Standard Lisp mode.
 */

#define TYPE_BITVEC1        0x030   /* subtypes encode length mod 8    */
#define TYPE_BITVEC2        0x0b0   /* (counts bits used in last byte) */
#define TYPE_BITVEC3        0x130
#define TYPE_BITVEC4        0x1b0   /* Observe that bit-length continues .. */
#define TYPE_BITVEC5        0x230   /* .. byte-length field in header word. */
#define TYPE_BITVEC6        0x2b0   /* However to extract length of bitvec  */
#define TYPE_BITVEC7        0x330   /* is harder because count here is 1-8  */
#define TYPE_BITVEC8        0x3b0   /* rather than 0-7.                     */

#define header_of_bitvector(h) (((h) & 0x70) == TYPE_BITVEC1)
#endif /* COMMON */

#define TYPE_STRING         0x070   /* simple character vector */
#define TYPE_BPS            0x170   /* bytes of compiled code  */
#define TYPE_SPARE          0x270   /* SPARE (holds binary information) */
#define TYPE_MAPLEREF       TYPE_SPARE /* An EXPERIMENTAL adjustment */
#define TYPE_SP             0x370   /* Encapsulated stack ptr  */

#ifdef COMMON
#define vector_holds_binary(h) (((h) & 0x80) == 0 || header_of_bitvector(h))
#else
#define vector_holds_binary(h) (((h) & 0x80) == 0)
#endif

#define TYPE_SIMPLE_VEC     0x0f0   /* simple general vector */
#define TYPE_HASH           0x1f0   /* hash table */
#define TYPE_ARRAY          0x2f0   /* header record for general array */
#define TYPE_STRUCTURE      0x3f0   /* includes packages etc possibly. */

/*
 * The following classes of vectors will start of as experiments. I want
 * to have at least some vectors that contain a mixture of general and binary
 * information, so TYPE_MIXED1 to TYPE_MIXED4 will serve for this, and are
 * limited to hold exactly three pointer objects. Note that for the garbage
 * collector to work properly I MUST have an odd number of pointers stored
 * in any vector...  "MIXED4" is used for stream handles.
 */

#define is_mixed_header(h) (((h) & 0x2b0) == TYPE_MIXED1)

#define TYPE_VEC8           TYPE_BPS/* contains 8-bit integers */

#define TYPE_VEC16          0x220   /* contains 16-bit integers */
#define TYPE_VEC32          0x260   /* contains 32-bit integers */
#define TYPE_MIXED1         0x2a0   /* general, but limited to 3 pointers */
#define TYPE_MIXED2         0x2e0   /* general, but limited to 3 pointers */
#define TYPE_FLOAT32        0x320   /* contains single-precision floats */
#define TYPE_FLOAT64        0x360   /* contains double-precision floats */
#define TYPE_MIXED3         0x3a0   /* only 3 pointers */
#define TYPE_STREAM         0x3e0   /* 3 pointers then binary data */

#define ODDS_MASK           0xff
#define TAG_CHAR            0x02    /* these cases leave 24 bits spare */
#define TAG_BPS             0x42
/* #define TAG_LITVEC       0x82    .. Not used at present, intended for  */
/*                                  .. read-only vectors in BPS heap.     */
#define TAG_SPID            0xc2    /* Collection of internal flag values */

#define SPID_NIL            (TAG_SPID+0x0000)  /* NIL in checkpoint file  */
#define SPID_FBIND          (TAG_SPID+0x0100)  /* Fluid binding on stack  */
#define SPID_CATCH          (TAG_SPID+0x0200)  /* CATCH frame on stack    */
#define SPID_PROTECT        (TAG_SPID+0x0300)  /* UNWIND_PROTECT on stack */
#define SPID_HASH0          (TAG_SPID+0x0400)  /* Empty hash slot         */
#define SPID_HASH1          (TAG_SPID+0x0500)  /* Deleted hash slot       */
#define SPID_GCMARK         (TAG_SPID+0x0600)  /* Used by GC as sentinel  */
#define SPID_NOINPUT        (TAG_SPID+0x0700)  /* Used by (read) in #X()  */
#define SPID_ERROR          (TAG_SPID+0x0800)  /* Used to indicate error  */
#define SPID_PVBIND         (TAG_SPID+0x0900)  /* PROGV binding on stack  */
#define SPID_NOARG          (TAG_SPID+0x0a00)  /* Missing &OPTIONAL arg   */
#define SPID_NOPROP         (TAG_SPID+0x0b00)  /* fastget entry is empty  */
#define SPID_LIBRARY        (TAG_SPID+0x0c00)  /* + 0xnnn00000 offset     */

#define is_header(x) (((int)(x) & 0x30) != 0)     /* valid if is_odds() */
#define is_char(x)   (((int)(x) & ODDS_MASK) == TAG_CHAR)
#define is_bps(x)    (((int)(x) & ODDS_MASK) == TAG_BPS)
#define is_hashtab(x)(((int)(x) & ODDS_MASK) == TAG_HASHTAB)
#define is_spid(x)   (((int)(x) & ODDS_MASK) == TAG_SPID)
#define is_library(x)(((int)(x) & 0xffff)    == SPID_LIBRARY)
#define library_number(x) (((x) >> 20) & 0xfff)

/*
 * For no especially good reason I represent an end of file marker
 * as character 4 (^D) in font number 255.  That at least keeps it
 * away from the standard characters that exist in font 0.
 * If "Kanji" is defined then Forbs Systems Co code to support
 * Eastern alphabets is enabled. Note that the original arrangement
 * of FONT/BITS/CODE that I had was as mandated for Common Lisp and that
 * the Kanji option is thus probably not directly compatible with
 * Common Lisp mode. To make life a little closer to reasonable in this
 * regard I will support both names needed for Common and Kanji.
 * Thus a character is stored using 24 bits (plus 8 bits of tag):
 *       Kanji mode           Ordinary mode
 *       font                 font
 *       code )               bits
 *       code ) 16 bits       code
 * Note that pack_char could now take a 16-bit code which would then fill in
 * all of code.  Note also that to avoid pain with re-working historical
 * bits of the CSL code I leave the macro pack_char with args in the order
 * bits/font/code.  In Common Lisp Mode if Kanji is enabled then extended
 * characters will have "bits".
 */
#define font_of_char(n)  (((int32_t)(n) >> 24) & 0xff)
#define bits_of_char(n)  (((int32_t)(n) >> 16) & 0xff)
#ifdef Kanji
#define code_of_char(n)  (((int32_t)(n) >>  8) & 0xffff)
#else
/* NB cast to (char) in case that is a signed type. Ugh! */
#define code_of_char(n)  ((char)(((int32_t)(n) >>  8) & 0xff))
#endif

#define pack_char(bits, font, code)                                \
    ((Lisp_Object)((((uint32_t)(font)) << 24) |                  \
    (((uint32_t)(bits)) << 16) | (((uint32_t)(code)) << 8) | TAG_CHAR))
    
#define CHAR_EOF pack_char(0, 0xff, 4)
 

/*
 * The following shows that a BPS entrypoint is represented with
 * 8 bits of tag at the bottom of the word.  There follow (PAGE_BITS-2)
 * bits of word-offset within the page.  Finally the rest of the word is
 * a page number.  This allows for up to 64 Mbytes of code space if I
 * am on a 32-bit machine. If PAGE_BITS is 22 (my current default on
 * most systems) this will be up to 16 pages each holding 4 Mbytes.
 * Given the compactness of the bytecode format the limit seems generous
 * enough at present!
 */
#define data_of_bps(v) \
  ((char *)(doubleword_align_up((intptr_t) \
             bps_pages[((uint32_t)(v))>>(PAGE_BITS+6)]) + \
            (((v) >> 6) & (PAGE_POWER_OF_TWO-4))))


typedef int32_t junk;      /* Unused 4-byte field for structures (for padding) */
typedef intptr_t junkxx;    /* Unused cell-sized field for structures */

typedef struct Symbol_Head
{
    Header header;      /* Standard format header for vector types */
/*
 * TAG_SYMBOL has the value 4, so on a 32-bit system a pointer
 * to a symbol points at the second word of it, ie the value cell. The
 * effect in that case is that the selector CAR would access the value
 * cell. For 64-bit addresses this pun will not work so easily. The
 * main case where this causes BIG pain is in Common Lisp mode wrt NIL
 * where (car nil) and (cdr nil) must both be legal and yield nil. This
 * can be handled by tagging NIL as a CONS not a SYMBOL in the Common Lisp
 * case. But then when NIL is used as a SYMBOL all the offsets will be
 * wrong... In 32-bit mode this makes 
 *
 * BEWARE!
 */
    Lisp_Object value;  /* Global or special value cell */
    Lisp_Object env;    /* Extra stuff to help function cell */
    intptr_t function1;     /* Executable code always (just 1 arg) */
    intptr_t function2;     /* Executable code always (just 2 args) */
    intptr_t functionn;     /* Executable code always (0, or >= 3 args) */
    Lisp_Object pname;   /* A string (always) */
    Lisp_Object plist;   /* A list */
    Lisp_Object fastgets;/* to speed up flagp and get */
    uintptr_t count;     /* for statistics */
#ifdef COMMON
    Lisp_Object package;/* Home package - a package object */
/*
 * If I am on a 32-bit system in COMMON mode then all objects are padded
 * to be an even number of cells long, so I need a padding word here. I
 * view it as holding binary data and so will never even bother the
 * initialise it.
 */
/*
 * But because C does not let me use "sizeof" in an #ifdef I can not put
 * this here the way I would perhaps like to!
 *
 * #if !SIXTY_FOUR_BIT
 *     intptr_t padding;
 * #endif
 */
#endif /* COMMON */
} Symbol_Head;


#define MAX_FASTGET_SIZE  63
/* I have up to 63 "fast" tags for PUT/GET/FLAG/FLAGP */

/*
 * The next bit is just to cope with the funny status of NIL in Common Lisp
 * on 64-bit architures, where the tagging pretty well breaks down.
 */
#ifdef COMMON
#define symalign(n) (SIXTY_FOUR_BIT ? \
     ((char *)((intptr_t)(n) & ~(intptr_t)TAG_SYMBOL)) : \
     (n)
#else
#define symalign(n) (n)
#endif

#ifndef MEMORY_TRACE

/*
 * The access macros are coded this way rather than using -> and
 * a structure since this reveals directly what offsets are involved
 * in the addressing, and so gives the C compiler an easier job!
 * There are so many casts anyway that this is not so very bad really!
 * I also use absolute numeric offsets (and do not use the offsetof
 * macro) to stress that I view the store layout as fixed, and because
 * offsetof is badly supported by some C compilers I have come across.
 */
#define qheader(p)     (*(Header *)     symalign((char *)(p) - TAG_SYMBOL))
#define qvalue(p)      (*(Lisp_Object *)symalign((char *)(p) + (CELL - TAG_SYMBOL)))
#define qenv(p)        (*(Lisp_Object *)symalign((char *)(p) + (2*CELL - TAG_SYMBOL)))

#define qfn1(p)        ((one_args *) *((intptr_t *)symalign((char *)(p) + \
                                         (3*CELL - TAG_SYMBOL))))
#define qfn2(p)        ((two_args *) *((intptr_t *)symalign((char *)(p) + \
                                         (4*CELL - TAG_SYMBOL))))
#define qfnn(p)        ((n_args *)   *((intptr_t *)symalign((char *)(p) + \
                                         (5*CELL - TAG_SYMBOL))))
/*
 * The ifn() selector gives access to the qfn() cell, but treating its
 * contents as (intptr_t).
 */
#define ifn1(p)        (*(intptr_t *)      symalign((char *)(p) + (3*CELL-TAG_SYMBOL)))
#define ifn2(p)        (*(intptr_t *)      symalign((char *)(p) + (4*CELL-TAG_SYMBOL)))
#define ifnn(p)        (*(intptr_t *)      symalign((char *)(p) + (5*CELL-TAG_SYMBOL)))

#define qpname(p)      (*(Lisp_Object *)symalign((char *)(p) + (6*CELL-TAG_SYMBOL)))
#define qplist(p)      (*(Lisp_Object *)symalign((char *)(p) + (7*CELL-TAG_SYMBOL)))

#define qfastgets(p)   (*(Lisp_Object *)symalign((char *)(p) + (8*CELL-TAG_SYMBOL)))
#define qcount(p)      (*(uintptr_t *) symalign((char *)(p) + (9*CELL-TAG_SYMBOL)))

#ifdef COMMON
#define qpackage(p)    (*(Lisp_Object *)symalign((char *)(p) + (10*CELL-TAG_SYMBOL)))
#endif

#else /* MEMORY_TRACE */

#define qheader(p)     (*(Header *)     memory_reference((intptr_t) \
                                         symalign((char *)(p) - TAG_SYMBOL)))
#define qvalue(p)      (*(Lisp_Object *)memory_reference((intptr_t) \
                                         symalign((char *)(p) + (CELL-TAG_SYMBOL))))
#define qenv(p)        (*(Lisp_Object *)memory_reference((intptr_t) \
                                         symalign((char *)(p) + (2*CELL-TAG_SYMBOL))))
#define qfn1(p)        ((one_args *) *(intptr_t *)memory_reference((intptr_t) \
                                         symalign((char *)(p) + (3*CELL-TAG_SYMBOL))))
#define qfn2(p)        ((two_args *) *(intptr_t *)memory_reference((intptr_t) \
                                         symalign((char *)(p) + (4*CELL-TAG_SYMBOL))))
#define qfnn(p)        ((n_args *)   *(intptr_t *)memory_reference((intptr_t) \
                                         symalign((char *)(p) + (5*CELL-TAG_SYMBOL))))
#define ifn1(p)        (*(intptr_t *)      memory_reference((intptr_t) \
                                         symalign((char *)(p) + (3*CELL-TAG_SYMBOL))))
#define ifn2(p)        (*(intptr_t *)      memory_reference((intptr_t) \
                                         symalign((char *)(p) + (4*CELL-TAG_SYMBOL))))
#define ifnn(p)        (*(intptr_t *)      memory_reference((intptr_t) \
                                         symalign((char *)(p) + (5*CELL-TAG_SYMBOL))))
#define qpname(p)      (*(Lisp_Object *)memory_reference((intptr_t) \
                                         symalign((char *)(p) + (6*CELL-TAG_SYMBOL))))
#define qplist(p)      (*(Lisp_Object *)memory_reference((intptr_t) \
                                         symalign((char *)(p) + (7*CELL-TAG_SYMBOL))))
#define qfastgets(p)   (*(Lisp_Object *)memory_reference((intptr_t) \
                                         symalign((char *)(p) + (8*CELL-TAG_SYMBOL))))
#define qcount(p)      (*(uintptr_t *) memory_reference((intptr_t) \
                                         symalign((char *)(p) + (9*CELL-TAG_SYMBOL))))
#ifdef COMMON
#define qpackage(p)    (*(Lisp_Object *)memory_reference((intptr_t) \
                                         symalign((char *)(p) + (10*CELL-TAG_SYMBOL))))
#endif

#endif /* MEMORY_TRACE */

#ifdef COMMON
typedef union Float_union
{
    float f;
    int32_t i;
} Float_union;
#endif

typedef struct Big_Number
{
/* see "arith.h" for a description of bignum formats */
    Header h;
/*
 * EVEN when I have 64-bit addresses I will represent
 * big-numbers as arrays of 32-bit values.  So I will still have to
 * ensure that I end up with a rounded number of digits - but in the
 * 64-bit case it will need to be an even number because the
 * header word at the front of a bignum becomes 64-bits long.
 */
    uint32_t d[1];  /* generally more digits than this */
} Big_Number;

#define bignum_length(b)  length_of_header(numhdr(b))
#ifdef MEMORY_TRACE
#define bignum_digits(b)  ((uint32_t *)memory_reference((intptr_t)((char *)b + \
                                         (CELL-TAG_NUMBERS))))
#else
#define bignum_digits(b)  ((uint32_t *)((char *)b  + (CELL-TAG_NUMBERS)))
#endif
#define make_bighdr(n)    (TAG_ODDS+TYPE_BIGNUM+(((intptr_t)(n))<<12))
#define pack_hdrlength(n) (((intptr_t)(n))<<12)

#ifdef COMMON
typedef struct Rational_Number
{
    Header header;
    Lisp_Object num;
    Lisp_Object den;
} Rational_Number;

#define numerator(r)    (((Rational_Number *)((char *)(r)-TAG_NUMBERS))->num)
#define denominator(r)  (((Rational_Number *)((char *)(r)-TAG_NUMBERS))->den)

typedef struct Complex_Number
{
    Header header;
    Lisp_Object real;
    Lisp_Object imag;
} Complex_Number;

#define real_part(r)    (((Complex_Number *)((char *)(r)-TAG_NUMBERS))->real)
#define imag_part(r)    (((Complex_Number *)((char *)(r)-TAG_NUMBERS))->imag)

typedef struct Single_Float
{
    Header header;
    union float_or_int {
       float f;
       int32_t i;
    } f;
} Single_Float;

#define single_float_val(v) \
    (((Single_Float *)((char *)(v)-TAG_BOXFLOAT))->f.f)

#endif /* COMMON */

/*
 * The structures here are not actually used - because I can not get
 * as strong control of alignment as I would like. So I use macros that
 * do address arithmetic explicitly for me...
 *
 *  typedef struct Double_Float
 *  {
 *      Header header;
 *                            // SIXTY_FOUR_BIT is not a compile-time constant
 *  #ifndef SIXTY_FOUR_BIT    // Can not do this #ifdef!!
 *      junk padding;         // for 64-bit the header was 64 bits wide
 *  #endif
 *      union double_or_ints {
 *          double f;         // padded to doubleword align the data.
 *          int32_t i[2];
 *      } f;
 *  } Double_Float;
 */

#define SIZEOF_DOUBLE_FLOAT     16
#define double_float_addr(v)    ((double *)((char *)(v) + \
                                   (8-TAG_BOXFLOAT)))
#define double_float_val(v)     (*(double *)((char *)(v) + \
                                   (8-TAG_BOXFLOAT)))

#ifdef COMMON

/*
 * Again I do not actually introduce the struct...
 *
 *  typedef struct Long_Float
 *  {
 *                          // For use if I ever wanted an 80-bit float type.
 *      Header header;
 *  #ifndef SIXTY_FOUR_BIT  // Illegal #ifdef here!
 *      junk padding;
 *  #endif
 *      union long_or_ints {
 *          double f;
 *          int32_t i[2];
 *      } f;
 *  } Long_Float;
 */

#define SIZEOF_LONG_FLOAT       16
#define long_float_addr(v)      ((double *)((char *)(v) + \
                                   (8-TAG_BOXFLOAT)))
#define long_float_val(v)       (*(double *)((char *)(v) + \
                                   (8-TAG_BOXFLOAT)))
#endif

#define doubleword_align_up(n) ((Lisp_Object)(((intptr_t)(n) + 7) & (-8)))
#define doubleword_align_down(n) ((Lisp_Object)((intptr_t)(n) & (-8)))

/*
 * For the benefit of 64-bit architectures I will make the big blocks
 * of memory that I allocate from 128-bit aligned. This may help me at
 * one delicate place in the garbage collector!
 */
#define quadword_align_up(n) ((Lisp_Object)(((intptr_t)(n) + 15) & (-16)))
#define quadword_align_down(n) ((Lisp_Object)((intptr_t)(n) & (-16)))

/*
 * values to go in exit_reason at times when exception_pending() is true.
 */

#define UNWIND_NULL       0x0         /* no error or action at all */
#define UNWIND_GO         0x1         /* GO, to support non-local case */
#define UNWIND_RETURN     0x2         /* RETURN, to support non-local */
#define UNWIND_THROW      0x3         /* THROW is obvious */
#define UNWIND_RESTART    0x4         /* (restart!-csl ...) */
#define UNWIND_RESOURCE   0x5         /* used with (resource!-limit ...) */

#define UNWIND_ERROR      0x100       /* when backtrace is needed */
#define UNWIND_UNWIND     0x200       /* no backtrace, still an error */

#endif /* header_tags_h */

/* end of tags.h */

