/* tags.h                               Copyright (C) Codemist 1990-1996 */

/*
 *   Data-structure and tag bit definitions, also common C macros
 *   for Lisp implementation.
 *
 */

/* Signature: 737aeab1 07-Mar-2000 */

#ifndef header_tags_h
#define header_tags_h 1

/*
 * Support for 64-bit architectures is something that is EXPERIMENTAL
 * and may or may not develop much. The options I purport to provide
 * so far are:
 *     SIXTY_FOUR_BIT      general indication that this is active
 *     LONG_LONG_64        need to say "long long int" to get int64
 *     ILP64               int = long = pointer = 64 bits (no 16 bit type)
 *                         (otherwise I assume int=32, long=64)
 *     ADDRESS_64          attempt to use 64-bit values as Lisp_Object
 *                         to cover full address space (very experimental)
 *     ARITH_64            exploit 64-bit arithmetic in bignum code
 *                         to try to speed it up (not yet implemented)
 *
 * Unless ADDRESS_64 is defined I will make Lisp_Object a 32-bit quantity
 * and suppose that all addresses that actually arise are located in the
 * low 4 Gbytes of memory, so that an address can be cast into a Lisp_Object
 * and back without loss.
 */

#ifdef LONG_LONG_64
#  define SIXTY_FOUR_BIT 1
#endif
#ifdef ILP64
#  define SIXTY_FOUR_BIT 1
#endif
#ifdef ADDRESS_64
#  define SIXTY_FOUR_BIT 1
#endif
#ifdef ARITH_64
#  define SIXTY_FOUR_BIT 1
#endif

#ifdef SIXTEEN_BIT
typedef long int            int32;
typedef unsigned long int   unsigned32;
#else
#ifdef SIXTY_FOUR_BIT
#ifdef LONG_LONG_64
typedef long long int            int64;
typedef unsigned long long int   unsigned64;
typedef int                      int32;
typedef unsigned int             unsigned32;
#else /* LONG_LONG_64 */
#ifdef ILP64
typedef int                      int64;
typedef unsigned int             unsigned64;
typedef short int                int32;
typedef unsigned short int       unsigned32;
#else /* ILP64 */
/*
 * And now the case that I think of as being "standard", where
 * long int  = 64
 * int       = 32
 * short int = 16
 */
typedef long int                 int64;
typedef unsigned long int        unsigned64;
typedef int                      int32;
typedef unsigned int             unsigned32;
#endif /* ILP64 */
#endif /* LONG_LONG_64 */
#else /* SIXTY_FOUR_BIT */
typedef int                 int32;
typedef unsigned int        unsigned32;
#endif /* SIXTY_FOUR_BIT */
#endif /* SIXTEEN_BIT */

#ifndef ILP64
/*
 * On an ILP64 machine I am not provided with any 16-bit data type, so
 * I will need to avoid any pretence of use of one.
 */
typedef short int           int16;
typedef unsigned short int  unsigned16;
#endif


typedef signed char         int8;
typedef unsigned char       unsigned8;

typedef int                 CSLbool;
#define YES                 1
#define NO                  0

/*
 * I allocate memory (using malloc()) in CSL_PAGE_SIZE chunks.
 * This was first implemented for the benefit of 16-bit machines
 * (in particular MSDOS/286) but now seems generally reasonable.  The biggest
 * menace about it is that it limits the size of the largest vector I can ever
 * allocate - and this (as of the time of this comment) limits the size of
 * the symbol table (object list).  On a true 32-bit computer you could
 * increase CSL_PAGE_SIZE somewhat without much trouble.  However, note the
 * macro data_of_bps (in tags.h) packs addresses assuming that the page
 * size is limited to 64 Kbytes and that there are at most 1024 pages
 * of code space.  The limits specified here may be overridden in machine.h
 * so that small machines do not waste effort pretending to support much
 * more memory than they will ever be configured with.
 *
 * NOTE:   The way I use this is that on small machines and especially
 *         on any remaining 16 bit machines I use PAGE_BITS=16 to allocate
 *         memory in 64Kbyte chunks.  This limits the size of the largest
 *         vector or bignum that CSL can handle.  On large systems (in
 *         particular all flavours of Unix) I use PAGE_BITS=18 to allocate
 *         in 256 Kbyte pages - and I rely on virtual memory not to penalise
 *         me too badly for the portions of those pages that go unused.
 *         For now image files created with one page size can not be used
 *         on a machine that uses another page size.  Re-work in preserve.c
 *         and restart.c may relax this constraint at some later stage.
 */
#ifndef PAGE_BITS
#  define PAGE_BITS             18
#endif
#define PAGE_POWER_OF_TWO       (((unsigned32)1) << PAGE_BITS)
/*
 * When I come to allocate memory I do so in chunks that are a little less
 * than the power of two suggested here, to allow for malloc() header
 * blocks etc.
 */
#define CSL_PAGE_SIZE           (PAGE_POWER_OF_TWO - 256U)
#ifndef MAX_HEAPSIZE
#  define MAX_HEAPSIZE          (2048*MEGABYTE)
#endif
#ifndef MAX_BPSSIZE
/*
 * Note once again that 64*MEGABYTE is the largest valid value that can be
 * used here.  But also note that 64 Mbytes of bytecodes would be a pretty
 * large program!
 */
#  define MAX_BPSSIZE           (64*MEGABYTE)
#endif

#define MAX_PAGES               (MAX_HEAPSIZE / PAGE_POWER_OF_TWO)
#define MAX_BPS_PAGES           (MAX_BPSSIZE / PAGE_POWER_OF_TWO)

#define MAX_NATIVE_PAGES        MAX_BPS_PAGES

#define PAGE_MASK               ((((unsigned32)1) << (32-PAGE_BITS)) - 1)
#define OFFSET_MASK             ((((unsigned32)1) << PAGE_BITS) - 1)

#define CSL_IGNORE(x)           (x = x)

#define LONGEST_LEGAL_FILENAME 256 /* maybe excessive for most purposes... */

/*
 * The following values relate to the identification of floating
 * point representations.  Note that they all fit in a byte.
 */

#define FP_WORD_ORDER 0x01
#define FP_BYTE_ORDER 0x02
#define FP_VAXREP     0x04
#define FP_IBMREP     0x08
#define FP_MASK       0xff

#define FP_ARM  FP_WORD_ORDER
#define FP_370  (FP_WORD_ORDER|FP_BYTE_ORDER|FP_IBMREP)/* IBM mainframes */
#define FP_MIPS 0                              /* MIPS, Intel 80x86, etc */
#define FP_VAX  FP_VAXREP                      /* also FP_WORD_ORDER?    */
#define FP_88K  (FP_WORD_ORDER|FP_BYTE_ORDER)  /* 680x0 etc too.         */


/*
 * General objects in Lisp are represented as 32-bit integers (usually)
 * and the type Lisp_Object reflects this representation and
 * not the elaborate tagged union that at some other level exists.
 * If I could use "void *" for this type that might give me a bit more
 * security since not much can be done with a "void *" object - in particular
 * it can not participate in arithmetic.  But when I do that I run into
 * trouble in protected mode on a PC if I have items of type Lisp_Object
 * that are not valid pointers.
 * If the *experimental* option ADDRESS_64 is defined I will use a 64-bit
 * data type for the type Lisp_Object. A result will be that anywhere in
 * the code where I am sloppy about putting such an object into an int32
 * I will have trouble, and anywhere that I use absolute numeric offsets
 * instead of multiples of sizeof(Lisp_Object) there can be pain. I can
 * also imagine trouble with numeric constants embedded in the code if
 * they would have their top bit set if they were 32-bits long, eg
 * 0xfffffffe, since in a 64-bit world they may not achieve the desired
 * effect.
 */

#ifdef ADDRESS_64
typedef int64 Lisp_Object;
#else
typedef int32 Lisp_Object;
#endif

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
#endif
#define TAG_SYMBOL      4   /* Symbols (maybe except for NIL) */
#define TAG_NUMBERS     5   /* Bignum, Rational, Complex */
#define TAG_VECTOR      6   /* Regular Lisp vectors (except BPS maybe?) */
#define TAG_BOXFLOAT    7   /* Boxed floats */

/*
 * For each of the above tag classes I have a bunch of low-level
 * operations that need support - including type identification
 * predicates and conversions to and from native C formats.
 */

#define fixnum_of_int(x)    ((Lisp_Object)(TAG_FIXNUM + ((x) << 4)))
/*
 * The multiple casts here are (a) to ensure that the shift is done
 * treating x as a signed value and (b) to stress that the shift is
 * done in an integer context.
 */
#ifdef SIGNED_SHIFTS_ARE_LOGICAL
/* Beware - arg evaluated several time in this case */
#define int_of_fixnum(x)    ((int32)(((int32)(x)) < 0 ?           \
                             (((int32)(x))>>4) | (-0x10000000) :  \
                             (((int32)(x))>>4)))
#else
#define int_of_fixnum(x)    ((int32)(((int32)(x)) >> 4))
#endif

/*
 * The garbage collector needs a spare bit in EVERY word...
 */

#define GC_BIT_I        8               /* Used with FIXNUM, CHAR, SFLOAT */
#define GC_BIT_H        8               /* Used in Header words */
#ifdef ADDRESS_64
#define GC_BIT_P        (~0x7fffffffffffffff)   /* for 64-bit pointers */
#else
#define GC_BIT_P        (~0x7fffffff)   /* Used with pointer types */
#endif
/*
 * The above curious definition of GC_BIT_P is intended to ensure that
 * it looks like a negative value. This matters a lot if there is some
 * 64-bit arithmetic lurking somewhere, because then what goes on in the
 * upper 32 bits can come and bite me.  I will try to avoid trouble by
 * having all constants in this code written in a way that avoids any
 * need for explicit 'L' suffices.
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
 */

#define is_marked_i(w)      (((int)(w) & GC_BIT_I) != 0)

#ifdef ADDRESSES_HAVE_TOP_BIT_CLEAR  /* Probably the usual case */
/*
 * I expect that tests on the sign of a value will be more efficient on
 * most machines than tests written as ((w & 0x80000000) == 0), even
 * though I expect compiler optimisation could often make them give the
 * same code.  If I do not have 2's complement arithmetic I am in a mess!
 * Unless somebody says explicitly that the sign bit of addresses is known
 * I will use the dynamic version of the code.
 */
#define is_marked_p(w)      ((Lisp_Object)(w) < 0)
#define clear_mark_bit_p(w) ((Lisp_Object)(w) & ~GC_BIT_P)
#else
#ifdef ADDRESSES_HAVE_TOP_BIT_SET   /* Maybe the transputer or GEC/63? */
#define is_marked_p(w)      ((Lisp_Object)(w) >= 0)
#define clear_mark_bit_p(w) ((Lisp_Object)(w) | GC_BIT_P)
#else
/*
 * In this case I assume that in any one run of CSL either all (malloc)
 * addresses have their top bit set OR all have their top bit clear, but
 * I can not predict in advance which case will apply.  This miserable
 * state arises with Win32 - under Windows-NT addresses are in the range
 * 0 to 0x7fffffff, while the same binary executing under Win32s has
 * addresses in the range 0x80000000 to 0xffffffff.
 */
#ifndef ADDRESS_SIGN_UNKNOWN
#  define ADDRESS_SIGN_UNKNOWN 1
#endif
extern Lisp_Object address_sign;  /* 0, 0x80000000 or 0x8000000000000000 */
#define is_marked_p(w)      (((Lisp_Object)(w) - address_sign) < 0)
#define clear_mark_bit_p(w) (((Lisp_Object)(w) & ~GC_BIT_P) + \
                              address_sign)
#endif
#endif

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
   nil = C_nil; if (exception_pending()) flip_exception()

#define set_mark_bit_h(h)   ((Header)(h) | GC_BIT_H)
#define clear_mark_bit_h(h) ((Header)(h) & ~GC_BIT_H)
#define set_mark_bit_i(h)   ((Lisp_Object)(h) | GC_BIT_I)
#define clear_mark_bit_i(h) ((Lisp_Object)(h) & ~GC_BIT_I)

#define is_cons(p)   ((((int)(p)) & TAG_BITS) == TAG_CONS)
#define is_fixnum(p) ((((int)(p)) & TAG_BITS) == TAG_FIXNUM)
#define is_odds(p)   ((((int)(p)) & TAG_BITS) == TAG_ODDS) /* many subcases */
#ifdef COMMON
#define is_sfloat(p) ((((int)(p)) & TAG_BITS) == TAG_SFLOAT)
#endif
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
#else
/* In Standard Lisp mode I tag nil as a symbol, and life is easier */
#define consp(p)     is_cons(p)
#define symbolp(p)   is_symbol(p)
#endif

/*
 * The next definition is fun!  In Common Lisp mode I want (car nil) to
 * be legal, and that is some of the motivation for tagging NIL as if
 * it had been a cons cell.  In Standard Lisp (car nil) is invalid.
 * I consider it important to make this test fast, which is why I have
 * made it just use the tag field of a value.
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
 * reported. NOTE that the MEMORY_TRACE option at present passes around
 * 32-bit values and so is incompatible with ADDRESS_64
 */

#ifdef ADDRESS_64
  This option will not work at present (deliberate syntax error)
#endif
 
extern Cons_Cell *memory_reference(int32 p);
extern char *cmemory_reference(int32 p);
extern void identify_page_types();
extern long int car_counter;
extern unsigned long int car_low, car_high;

#define qcar(p) (memory_reference((int32)p)->car)
#define qcdr(p) (memory_reference((int32)p)->cdr)

#else

/*
 * Using the HUGE memory model on a PC, the following use of field selectors
 * is only valid so long as I can be certain that a cons call does not
 * cross a 64Kbyte segment boundary.  Doubleword alignment should
 * ensure that this constraint is satisfied.
 */
#define qcar(p) (((Cons_Cell *) (p))->car)
#define qcdr(p) (((Cons_Cell *) (p))->cdr)
#endif

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

#ifdef ADDRESS_64
typedef unsigned64 Header;
#else
typedef unsigned32 Header;
#endif

/*
 * An object can be up to 4 Mbytes long, and has 12 bits of tag + GC info
 * in its header word.  All header words have TAG_ODDS in their low order
 * 4 bits, then 6 more bits that identify what sort of object is being
 * headed.  The remaining 22 bits give the length (in bytes) of the
 * active part of the object.  Note well that this really is a limitation
 * on the largest size of an object, and it prevents me from having
 * vectors or bignums larger than 4 Mbytes regardless of the "page"
 * structure of my memory.
 */

#define header_mask          0x3f0
#define type_of_header(h)    (((unsigned int)(h)) & header_mask)
#define length_of_header(h)  (((unsigned32)(h)) >> 10)

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
#else
#define  SYM_UNPRINTED_GENSYM 0x00100000/* not-yet-printed gensym */
#endif

#define symhdr_length       ((sizeof(Symbol_Head) + 7) & ~7)
#define is_symbol_header(h) (((int)h & 0x30) == TYPE_SYMBOL)
#define header_fastget(h)   (((h) >> SYM_FASTGET_SHIFT) & 0x3f)

#define TYPE_BIGNUM         0x020   /* low 2-bits = '10' for numbers */
#ifdef COMMON
#define TYPE_RATNUM         0x060
#define TYPE_COMPLEX_NUM    0x0a0
#define TYPE_SINGLE_FLOAT   0x120
#endif
#define TYPE_DOUBLE_FLOAT   0x160
#ifdef COMMON
#define TYPE_LONG_FLOAT     0x1a0
#endif

#ifdef MEMORY_TRACE
#define numhdr(v) (*(Header *)memory_reference((int32)((char *)(v) - \
                                               TAG_NUMBERS)))
#define flthdr(v) (*(Header *)memory_reference((int32)((char *)(v) - \
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
#endif

#define is_bignum_header(h) (type_of_header(h) == TYPE_BIGNUM)

#define is_bignum(n) is_bignum_header(numhdr(n))

#ifdef MEMORY_TRACE
#define vechdr(v)  (*(Header *)memory_reference((int32)((char *)(v) - \
                               TAG_VECTOR)))
#ifdef ADDRESS_64
#define elt(v, n)  (*(Lisp_Object *)memory_reference((int32)((char *)(v) + \
                               (CELL-TAG_VECTOR)+(((int32)(n))<<3))))
#else
#define elt(v, n)  (*(Lisp_Object *)memory_reference((int32)((char *)(v) + \
                               (CELL-TAG_VECTOR)+(((int32)(n))<<2))))
#endif
#define celt(v, n) (*cmemory_reference((int32)((char *)(v) + \
                               (CELL-TAG_VECTOR)+((int32)(n)))))
#define ucelt(v, n) (*(unsigned char *)cmemory_reference( \
                               (int32)((unsigned char *)(v) + \
                               (CELL-TAG_VECTOR)+((int32)(n)))))
#define scelt(v, n) (*(signed char *)cmemory_reference( \
                               (int32)((signed char *)(v) + \
                               (CELL-TAG_VECTOR)+((int32)(n)))))
#else
#define vechdr(v)  (*(Header *)((char *)(v) - TAG_VECTOR))
#ifdef ADDRESS_64
#define elt(v, n)  (*(Lisp_Object *)((char *)(v) + \
                               (CELL-TAG_VECTOR)+(((int32)(n))<<3)))
#else
#define elt(v, n)  (*(Lisp_Object *)((char *)(v) + \
                               (CELL-TAG_VECTOR)+(((int32)(n))<<2)))
#endif
#define celt(v, n) (*((char *)(v) + (CELL-TAG_VECTOR)+((int32)(n))))
#define ucelt(v, n) (*((unsigned char *)(v) + (CELL-TAG_VECTOR)+((int32)(n))))
#define scelt(v, n) (*((signed char *)(v) + (CELL-TAG_VECTOR)+((int32)(n))))
#endif

/*
 * The next are for 16-bit & 32 bit values and single-float & double-float 
 * access. Note that halfwords are signed.
 */
#ifdef ADDRESS_64
/*
 * For the sake of the DEC Alpha and general future-proofing I will
 * suppos ethat machines with 64-bit addresses do not have a 16-bit
 * integer data type, so I will use pairs of byte-fetches. This is
 * a bit pessimistic, but the half-word accesses are only used in a
 * very few places so performance probably does not matter much.
 */
#define helt(v, n) \
   ((*(unsigned char *)((v) + (CELL-TAG_VECTOR) + (((int32)(n))<<1)) | \
    (*(signed char *)((v) + (CELL-TAG_VECTOR+1) + (((int32)(n))<<1))) << 8))
#define sethelt(v, n, x) \
   (*(char *)((v) + (CELL-TAG_VECTOR) + (((int32)(n))<<1)) = (x), \
    *(char *)((v) + (CELL-TAG_VECTOR+1) + (((int32)(n))<<1)) = ((x)>>8))
#else
#define helt(v, n)  (*(short int *)((char *)(v) + \
                           (CELL-TAG_VECTOR)+(((int32)(n))<<1)))
#define sethelt(v, n, x) (helt(v, n) = (x))
#endif
#define ielt(v, n)  (*(int32 *)((char *)(v) + \
                           (CELL-TAG_VECTOR)+(((int32)(n))<<2)))
#define felt(v, n)  (*(float *)((char *)(v) + \
                           (CELL-TAG_VECTOR)+(((int32)(n))<<2)))
#define delt(v, n)  (*(double *)((char *)(v) + \
                           (2*CELL-TAG_VECTOR)+(((int32)(n))<<3)))

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
#endif

#define TYPE_STRING         0x070   /* simple character vector */
#define TYPE_BPS            0x170   /* bytes of compiled code  */
#define TYPE_SPARE          0x270   /* SPARE (holds binary information) */
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
 * in any vector...  MIXED4 is used for stream handles.
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
 * If "Kanji" is defined than Forbs Systems Co code to support
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
#define font_of_char(n)  (((int32)(n) >> 24) & 0xff)
#define bits_of_char(n)  (((int32)(n) >> 16) & 0xff)
#ifdef Kanji
#define code_of_char(n)  (((int32)(n) >>  8) & 0xffff)
#else
/* NB cast to (char) in case that is a signed type. Ugh! */
#define code_of_char(n)  ((char)(((int32)(n) >>  8) & 0xff))
#endif

#define pack_char(bits, font, code)                                \
    ((Lisp_Object)((((unsigned32)(font)) << 24) |                  \
    (((unsigned32)(bits)) << 16) | (((unsigned32)(code)) << 8) | TAG_CHAR))
    
#define CHAR_EOF pack_char(0, 0xff, 4)
 

/*
 * The following shows that a BPS entrypoint is represented with
 * 8 bits of tag at the bottom of the word.  There follow (PAGE_BITS-2)
 * bits of word-offset within the page.  Finally the rest of the word is
 * a page number.  This allows for up to 64 Mbytes of code space.
 */
#define data_of_bps(v) \
  ((char *)(doubleword_align_up((int32) \
             bps_pages[((unsigned32)(v))>>(PAGE_BITS+6)]) + \
            (((v) >> 6) & (PAGE_POWER_OF_TWO-4))))



typedef int32 junk;                      /* Unused fields in structures */

#ifdef ADDRESS_64
typedef struct Symbol_Head
{
    unsigned64 header;      /* Standard format header for vector types */
/*
 * TAG_SYMBOL has the value 4, so on a 32-bit system a pointer
 * to a symbol points at the second word of it, ie the value cell. The
 * effect in that case is that the selector CAR would access the value
 * cell. For 64-bit addresses this pun will not work. The only truly
 * bad effect that I can see at present is that in Common Lisp mode
 * it causes trouble about any attempt to take CAR or CDR of NIL.
 */
    Lisp_Object value;  /* Global or special value cell */
    Lisp_Object env;    /* Extra stuff to help function cell */
    int64 function1;     /* Executable code always (just 1 arg) */
    int64 function2;     /* Executable code always (just 2 args) */
    int64 functionn;     /* Executable code always (0, or >= 3 args) */
    Lisp_Object pname;   /* A string (always) */
    Lisp_Object plist;   /* A list */
    Lisp_Object fastgets;/* to speed up flagp and get */
    unsigned64 count;    /* for statistics */
#ifdef COMMON
    Lisp_Object package;/* Home package - a package object */
#endif
} Symbol_Head;
#else /* ADDRESS_64 */


/*
 * The version that follows is the normal one and is used in all
 * cases except when I have to try to support 64-bit addresses.
 */

typedef struct Symbol_Head
{
    Header header;      /* Standard format header for vector types */
/*
 * TAG_SYMBOL has the value 4, so a pointer to a symbol points
 * directly at the value cell - if a pun is made between symbols
 * and cons cells the value cell is the CAR and the environment
 * cell is the CDR.  For the symbol NIL I manage to keep both
 * of these fields containing NIL, in case I am in Common Lisp mode
 * and the user can access them.
 */
    Lisp_Object value;  /* Global or special value cell */
    Lisp_Object env;    /* Extra stuff to help function cell */
/*
 * The next 3 components will hold function entrypoints. So why are they
 * given the type "int32" here?  Well, that is to force 64-bit architectures
 * to allocate just 32 bits.  I will then use horrid casts to put things
 * back to the correct types later on.
 */
    int32 function1;     /* Executable code always (just 1 arg) */
    int32 function2;     /* Executable code always (just 2 args) */
    int32 functionn;     /* Executable code always (0, or >= 3 args) */
    Lisp_Object pname;   /* A string (always) */
    Lisp_Object plist;   /* A list */
    Lisp_Object fastgets;/* to speed up flagp and get */
    unsigned32 count;    /* for statistics */
#ifdef COMMON
    Lisp_Object package;/* Home package - a package object */
#endif
} Symbol_Head;
#endif

#define MAX_FASTGET_SIZE  63
/* I have up to 63 "fast" tags for PUT/GET/FLAG/FLAGP */

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
#define qheader(p)     (*(Header *)     ((char *)(p) - TAG_SYMBOL))
#define qvalue(p)      (*(Lisp_Object *)((char *)(p) + (CELL - TAG_SYMBOL)))
#define qenv(p)        (*(Lisp_Object *)((char *)(p) + (2*CELL - TAG_SYMBOL)))
#ifdef ADDRESS_64
#define qfn1(p)        ((one_args *) *((int64 *)((char *)(p) + \
                                         (3*CELL-TAG_SYMBOL))))
#define qfn2(p)        ((two_args *) *((int64 *)((char *)(p) + \
                                         (4*CELL-TAG_SYMBOL))))
#define qfnn(p)        ((n_args *)   *((int64 *)((char *)(p) + \
                                         (5*CELL-TAG_SYMBOL))))
/*
 * The ifn() selector gives access to the qfn() cell, but treating its
 * contents as (int64).
 */
#define ifn1(p)        (*(int64 *)      ((char *)(p) + (3*CELL-TAG_SYMBOL)))
#define ifn2(p)        (*(int64 *)      ((char *)(p) + (4*CELL-TAG_SYMBOL)))
#define ifnn(p)        (*(int64 *)      ((char *)(p) + (5*CELL-TAG_SYMBOL)))
#else /* ADDRESS_64 */
/*
 * I do some NASTY casts here to support the idea that the function
 * addresses REALLY fit into 32 bits.  These macros do not allow me
 * to update the function cells - see ifn1, ifn2, ifnn for that. The
 * numerical offsets used here assume 32-bit Lisp_Objects.
 */
#define qfn1(p)        ((one_args *) *((int32 *)(p) + 2))
#define qfn2(p)        ((two_args *) *((int32 *)(p) + 3))
#define qfnn(p)        ((n_args *)   *((int32 *)(p) + 4))
/*
 * The ifn() selector gives access to the qfn() cell, but treating its
 * contents as (int32).  This pun is so that I can set the cell to
 * the values I want in the very special case that genuine pointers are
 * 64 bits long but I am certain that all the addresses that I ever use
 * will fit entirely in the low 32 bits.
 */
#define ifn1(p)        (*(int32 *)      ((char *)(p) + 8))
#define ifn2(p)        (*(int32 *)      ((char *)(p) + 12))
#define ifnn(p)        (*(int32 *)      ((char *)(p) + 16))
#endif /* ADDRESS_64 */
#define qpname(p)      (*(Lisp_Object *)((char *)(p) + (6*CELL-TAG_SYMBOL)))
#define qplist(p)      (*(Lisp_Object *)((char *)(p) + (7*CELL-TAG_SYMBOL)))
#define qfastgets(p)   (*(Lisp_Object *)((char *)(p) + (8*CELL-TAG_SYMBOL)))
#define qcount(p)      (*(unsigned32 *) ((char *)(p) + (9*CELL-TAG_SYMBOL)))
#ifdef COMMON
#define qpackage(p)    (*(Lisp_Object *)((char *)(p) + (10*CELL-TAG_SYMBOL)))
#endif

#else /* MEMORY_TRACE */

#define qheader(p)     (*(Header *)     memory_reference((int32) \
                                         ((char *)(p) - TAG_SYMBOL)))
#define qvalue(p)      (*(Lisp_Object *)memory_reference((int32) \
                                         ((char *)(p) + (CELL-TAG_SYMBOL))))
#define qenv(p)        (*(Lisp_Object *)memory_reference((int32) \
                                         ((char *)(p) + (2*CELL-TAG_SYMBOL))))
/*
 * The next three lines UNRECONSTRUCTED in the ADDRESS_64 case.
 */
#define qfn1(p)        ((one_args *) *(int32 *)memory_reference((int32) \
                                         ((int32 *)(p) + 2)))
#define qfn2(p)        ((two_args *) *(int32 *)memory_reference((int32) \
                                         ((int32 *)(p) + 3)))
#define qfnn(p)        ((n_args *)   *(int32 *)memory_reference((int32) \
                                         ((int32 *)(p) + 4)))
#define ifn1(p)        (*(int32 *)      memory_reference((int32) \
                                         ((char *)(p) + (3*CELL-TAG_SYMBOL))))
#define ifn2(p)        (*(int32 *)      memory_reference((int32) \
                                         ((char *)(p) + (4*CELL-TAG_SYMBOL))))
#define ifnn(p)        (*(int32 *)      memory_reference((int32) \
                                         ((char *)(p) + (5*CELL-TAG_SYMBOL))))
#define qpname(p)      (*(Lisp_Object *)memory_reference((int32) \
                                         ((char *)(p) + (6*CELL-TAG_SYMBOL))))
#define qplist(p)      (*(Lisp_Object *)memory_reference((int32) \
                                         ((char *)(p) + (7*CELL-TAG_SYMBOL))))
#define qfastgets(p)   (*(Lisp_Object *)memory_reference((int32) \
                                         ((char *)(p) + (8*CELL-TAG_SYMBOL))))
#define qcount(p)      (*(unsigned32 *) memory_reference((int32) \
                                         ((char *)(p) + (9*CELL-TAG_SYMBOL))))
#ifdef COMMON
#define qpackage(p)    (*(Lisp_Object *)memory_reference((int32) \
                                         ((char *)(p) + (10*CELL-TAG_SYMBOL))))
#endif

#endif /* MEMORY_TRACE */

#ifdef COMMON
typedef union Float_union
{
    float f;
    int32 i;
} Float_union;
#endif

typedef struct Big_Number
{
/* see "arith.h" for a description of bignum formats */
    Header h;
/*
 * At least for now EVEN when I have 64-bit addresses I will represent
 * big-numbers as arrays of 32-bit values. The fact that this will no
 * longer automatically be equivalent to an array of Lisp_Objects will
 * need careful checking for places where I have been sloppy.
 */
    unsigned32 d[1];  /* generally more digits than this */
} Big_Number;

#define bignum_length(b)  length_of_header(numhdr(b))
#ifdef MEMORY_TRACE
#define bignum_digits(b)  ((unsigned32 *)memory_reference((int32)((char *)b + \
                                         (CELL-TAG_NUMBERS))))
#else
#define bignum_digits(b)  ((unsigned32 *)((char *)b  + (CELL-TAG_NUMBERS)))
#endif
#define make_bighdr(n)    (TAG_ODDS+TYPE_BIGNUM+(((int32)(n))<<12))
#define pack_hdrlength(n) (((int32)(n))<<12)

#ifdef COMMON
typedef struct Rational_Number
{
    Header header;
    Lisp_Object num;
    Lisp_Object den;
} Rational_Number;

/*
 * The "->" selectors would need replacing for PC use in HUGE mode
 */
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
       int32 i;
    } f;
} Single_Float;

/*
 * A Single float is just of size 8, so doubleword alignment will
 * ensure that a Single_Float never spans a segment boundary on 32-bit
 * systems.
 */
#define single_float_val(v) (((Single_Float *)((char *)(v)-TAG_BOXFLOAT))->f.f)
#endif

typedef struct Double_Float
{
    Header header;
#ifndef ADDRESS_64
    junk padding;
#endif
    union double_or_ints {
        double f;         /* padding is so as to doubleword align the data */
        int32 i[2];
    } f;
} Double_Float;

#define double_float_val(v)     (*(double *)((char *)(v) + \
                                   (8-TAG_BOXFLOAT)))

#ifdef COMMON
typedef struct Long_Float
{
    Header header;
#ifndef ADDRESS_64
    junk padding;       /* May be 3-word float one day */
#endif
    union long_or_ints {
        double f;
        int32 i[2];
    } f;
} Long_Float;

#define long_float_val(v)       (*(double *)((char *)(v) + \
                                   (8-TAG_BOXFLOAT)))
#endif

#define doubleword_align_up(n) ((Lisp_Object)(((int32)(n) + 7) & (-8)))
#define doubleword_align_down(n) ((Lisp_Object)((int32)(n) & (-8)))

/*
 * values to go in exit_reason at times when exception_pending() is true.
 */

#define UNWIND_NULL       0x0         /* no error or action at all */
#define UNWIND_GO         0x1
#define UNWIND_RETURN     0x2
#define UNWIND_THROW      0x3
#define UNWIND_RESTART    0x4

#define UNWIND_ERROR      0x100       /* when backtrace is needed */
#define UNWIND_UNWIND     0x200       /* no backtrace, still an error */

#endif /* header_tags_h */

/* end of tags.h */

