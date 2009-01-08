
/* $srcdir/../csl-c\u11.c Machine generated C code */

/* Signature: 00000000 24-Nov-2006 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdarg.h>
#include <time.h>
#ifndef _cplusplus
#include <setjmp.h>
#endif

#include "config.h"

#ifndef header_machine_h
#define header_machine_h 1
#if !defined UNDER_CE && ((defined HAVE_SOCKET && defined HAVE_SYS_SOCKET_H) || defined WIN32)
#define SOCKETS                  1
#endif
#ifndef MS_CDECL
#ifdef _MSC_VER
#  define MS_CDECL __cdecl
#else
#  define MS_CDECL
#endif
#endif
#ifdef WIN32
#  ifdef WIN64
#     define OPSYS           "win64"
#     define IMPNAME         "win64"
#  else
#     define OPSYS           "win32"
#     define IMPNAME         "win32"
#  endif
#else
#  ifdef HOST_OS
#     define OPSYS           HOST_OS
#     ifdef HOST_CPU
#        define IMPNAME      HOST_OS ":" HOST_CPU
#     else
#        define IMPNAME      HOST_OS
#     endif
#  else
#     define OPSYS           "Unknown"
#     define IMPNAME         "Generic"
#  endif
#endif
#endif 
#ifndef header_tags_h
#define header_tags_h 1
#if SIZEOF_INT==8 || SIZEOF_LONG==8 || (defined SIZEOF_LONG_LONG && SIZEOF_LONG_LONG==8)
#  define SIXTY_FOUR_BIT 1
#endif
#if SIZEOF_VOID_P==8
#  define ADDRESS_64 1
#endif
#if defined SIXTY_FOUR_BIT && SIZEOF_LONG<8
#define LONG_LONG_64 1
#endif
#if SIZEOF_INT<8 && SIZEOF_LONG<8 && defined SIZEOF_LONG_LONG && SIZEOF_LONG_LONG==8
typedef long long             int64;
typedef unsigned long long    unsigned64;
#else
#if SIZEOF_LONG==8
typedef long int                 int64;
typedef unsigned long int        unsigned64;
#else
#if SIZEOF_INT==8
typedef int                      int64;
typedef unsigned int             unsigned64;
#else
#endif
#endif
#endif
#if SIZEOF_INT==4
typedef int                      int32;
typedef unsigned int             unsigned32;
#else
#if SIZEOF_SHORT_INT==4
typedef short int                int32;
typedef unsigned short int       unsigned32;
#else
#if SIZEOF_LONG==4
typedef long int                 int32;
typedef unsigned long int        unsigned32;
#else
typedef int                      int32;
typedef unsigned int             unsigned32;
#define OVERWIDE32 1
#endif
#endif
#endif
#if SIZEOF_SHORT_INT==2
typedef short int           int16;
typedef unsigned short int  unsigned16;
#else
#define ILP64 1
#endif
typedef signed char         int8;
typedef unsigned char       unsigned8;
#if defined SIXTY_FOUR_BIT && !defined OVERWIDE32
#define MULDIV64 1
#endif
typedef int                 CSLbool;
#define YES                 1
#define NO                  0
#ifndef PAGE_BITS
#  define PAGE_BITS             22
#endif 
#define PAGE_POWER_OF_TWO       (((unsigned32)1) << PAGE_BITS)
#define CSL_PAGE_SIZE           (PAGE_POWER_OF_TWO - 256U)
#ifndef MAX_HEAPSIZE
#  ifdef ADDRESS_64
#     define MAX_HEAPSIZE       20480
#  else
#     define MAX_HEAPSIZE       2048
#  endif
#endif 
#ifndef MAX_BPSSIZE
#  define MAX_BPSSIZE           64
#endif 
#define MEGABYTE                ((unsigned32)0x100000U)
#if PAGE_BITS >= 20
#define MAX_PAGES               (MAX_HEAPSIZE >> (PAGE_BITS-20))
#define MAX_BPS_PAGES           (MAX_BPSSIZE >> (PAGE_BITS-20))
#else
#define MAX_PAGES               (MAX_HEAPSIZE << (20-PAGE_BITS))
#define MAX_BPS_PAGES           (MAX_BPSSIZE << (20-PAGE_BITS))
#endif
#define MAX_NATIVE_PAGES        MAX_BPS_PAGES
#define PAGE_MASK               ((((unsigned32)1) << (32-PAGE_BITS)) - 1)
#define OFFSET_MASK             ((((unsigned32)1) << PAGE_BITS) - 1)
#define CSL_IGNORE(x)           (x = x)
#define LONGEST_LEGAL_FILENAME 200
#define FP_WORD_ORDER 0x01
#define FP_BYTE_ORDER 0x02
#define FP_VAXREP     0x04   
#define FP_IBMREP     0x08   
#define FP_MASK       0xff
#define FP_ARM  FP_WORD_ORDER
#define FP_370  (FP_WORD_ORDER|FP_BYTE_ORDER|FP_IBMREP)
#define FP_MIPS 0                              
#define FP_VAX  FP_VAXREP                      
#define FP_88K  (FP_WORD_ORDER|FP_BYTE_ORDER)  
#ifdef ADDRESS_64
typedef int64 Lisp_Object;
typedef int64 intxx;
typedef unsigned64 unsignedxx;
#else 
typedef int32 Lisp_Object;
typedef int32 intxx;
typedef unsigned32 unsignedxx;
#endif 
#define CELL sizeof(Lisp_Object)
#define TAG_BITS        7
#define TAG_CONS        0   
                            
#define TAG_FIXNUM      1   
#define TAG_ODDS        2   
#ifdef COMMON
#define TAG_SFLOAT      3   
#endif 
#define TAG_SYMBOL      4   
#define TAG_NUMBERS     5   
#define TAG_VECTOR      6   
#define TAG_BOXFLOAT    7   
#define fixnum_of_int(x)    ((Lisp_Object)(TAG_FIXNUM + (((int32)(x)) << 4)))
#ifdef SIGNED_SHIFTS_ARE_LOGICAL
#define int_of_fixnum(x)    ((int32)(((int32)(x)) < 0 ?           \
                             (((int32)(x))>>4) | (-0x10000000) :  \
                             (((int32)(x))>>4)))
#else 
#define int_of_fixnum(x)    ((int32)(((int32)(x)) >> 4))
#endif 
#define GC_BIT_I        8               
#define GC_BIT_H        8               
#ifdef ADDRESS_64
#define GC_BIT_P        ((intxx)(~0x7fffffffffffffffL))
#else 
#define GC_BIT_P        (~0x7fffffff)   
#endif 
#define is_marked_i(w)      (((int)(w) & GC_BIT_I) != 0)
extern Lisp_Object address_sign;  
#define is_marked_p(w)      (((Lisp_Object)(w) - address_sign) < 0)
#define clear_mark_bit_p(w) (((Lisp_Object)(w) & ~GC_BIT_P) + \
                              address_sign)
#define flip_mark_bit_i(w)  ((Lisp_Object)(w) ^ GC_BIT_I)
#define flip_mark_bit_h(w)  ((Header)(w) ^ GC_BIT_H)
#define flip_mark_bit_p(w)  ((Lisp_Object)(w) ^ GC_BIT_P)
#define is_marked_h(w)      (((int)(w) & GC_BIT_H) != 0)
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
#define is_odds(p)   ((((int)(p)) & TAG_BITS) == TAG_ODDS) 
#ifdef COMMON
#define is_sfloat(p) ((((int)(p)) & TAG_BITS) == TAG_SFLOAT)
#endif 
#define is_symbol(p) ((((int)(p)) & TAG_BITS) == TAG_SYMBOL)
#define is_numbers(p)((((int)(p)) & TAG_BITS) == TAG_NUMBERS)
#define is_vector(p) ((((int)(p)) & TAG_BITS) == TAG_VECTOR)
#define is_bfloat(p) ((((int)(p)) & TAG_BITS) == TAG_BOXFLOAT)
#ifdef COMMON
#define consp(p)     (is_cons(p) && (p) != nil)
#define symbolp(p)   (is_symbol(p) || (p) == nil)
#else 
#define consp(p)     is_cons(p)
#define symbolp(p)   is_symbol(p)
#endif 
#define car_legal(p) is_cons(p)
#define is_number(p) ((((int)(p)) & 1) != 0) 
#define is_float(p)  ((((int)(p)) & 3) == 3) 
#define is_immed_or_cons(p) ((((int)(p)) & 4) == 0)
typedef struct Cons_Cell
{
    Lisp_Object car;
    Lisp_Object cdr;
} Cons_Cell;
#ifdef MEMORY_TRACE
extern Cons_Cell *memory_reference(intxx p);
extern char *cmemory_reference(intxx p);
extern void identify_page_types();
extern long int car_counter;
extern unsigned long int car_low, car_high;
#define qcar(p) (memory_reference((intxx)p)->car)
#define qcdr(p) (memory_reference((intxx)p)->cdr)
#else 
#define qcar(p) (((Cons_Cell *) (p))->car)
#define qcdr(p) (((Cons_Cell *) (p))->cdr)
#endif 
#define car32(p) (*(int32 *)(p))
typedef Lisp_Object Special_Form(Lisp_Object, Lisp_Object);
typedef Lisp_Object one_args(Lisp_Object, Lisp_Object);
typedef Lisp_Object two_args(Lisp_Object, Lisp_Object, Lisp_Object);
typedef Lisp_Object MS_CDECL n_args(Lisp_Object, int, ...);
#ifdef ADDRESS_64
typedef unsigned64 Header;
#else
typedef unsigned32 Header;
#endif
#define header_mask          0x3f0
#define type_of_header(h)    (((unsigned int)(h)) & header_mask)
#define length_of_header(h)  (((unsigned32)(h)) >> 10)
#define TYPE_SYMBOL         0x00000010
#define  SYM_SPECIAL_VAR    0x00000040  
#define  SYM_GLOBAL_VAR     0x00000080  
#define  SYM_SPECIAL_FORM   0x00000100  
#define  SYM_MACRO          0x00000200  
#define  SYM_C_DEF          0x00000400  
#define  SYM_CODEPTR        0x00000800  
#define  SYM_ANY_GENSYM     0x00001000  
#define  SYM_TRACED         0x00002000
#define  SYM_FASTGET_MASK   0x000fc000  
#define  SYM_FASTGET_SHIFT  14
#ifdef COMMON
#define  SYM_EXTERN_IN_HOME 0x00100000  
#define  SYM_IN_PACKAGE     0xffe00000  
#define  SYM_IN_PKG_SHIFT   23
#define  SYM_IN_PKG_COUNT   11
#else 
#define  SYM_UNPRINTED_GENSYM 0x00100000
#endif 
#define symhdr_length       ((sizeof(Symbol_Head) + 7) & ~7)
#define is_symbol_header(h) (((int)h & 0x30) == TYPE_SYMBOL)
#define header_fastget(h)   (((h) >> SYM_FASTGET_SHIFT) & 0x3f)
#define TYPE_BIGNUM         0x020   
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
#define numhdr(v) (*(Header *)memory_reference((intxx)((char *)(v) - \
                                               TAG_NUMBERS)))
#define flthdr(v) (*(Header *)memory_reference((intxx)((char *)(v) - \
                                               TAG_BOXFLOAT)))
#else
#define numhdr(v) (*(Header *)((char *)(v) - TAG_NUMBERS))
#define flthdr(v) (*(Header *)((char *)(v) - TAG_BOXFLOAT))
#endif
#define is_numbers_header(h) (((int)(h) & 0x330) == 0x020)
#define is_boxfloat_header(h)(((int)(h) & 0x330) == 0x120)
#ifdef COMMON
#define is_ratio(n) \
    (type_of_header(numhdr(n)) == TYPE_RATNUM)
#define is_complex(n) \
    (type_of_header(numhdr(n)) == TYPE_COMPLEX_NUM)
#endif 
#define is_bignum_header(h) (type_of_header(h) == TYPE_BIGNUM)
#define is_bignum(n) is_bignum_header(numhdr(n))
#ifdef ADDRESS_64
#define ADDRESS_SHIFT 3
#else
#define ADDRESS_SHIFT 2
#endif
#ifdef MEMORY_TRACE
#define vechdr(v)  (*(Header *)memory_reference((intxx)((char *)(v) - \
                               TAG_VECTOR)))
#define elt(v, n)  (*(Lisp_Object *)memory_reference((intxx)((char *)(v) + \
                               (CELL-TAG_VECTOR) + \
                               (((intxx)(n))<<ADDRESS_SHIFT))))
#define celt(v, n) (*cmemory_reference((intxx)((char *)(v) + \
                               (CELL-TAG_VECTOR)+((intxx)(n)))))
#define ucelt(v, n) (*(unsigned char *)cmemory_reference( \
                               (intxx)((char *)(v) + \
                               (CELL-TAG_VECTOR)+((intxx)(n)))))
#define scelt(v, n) (*(signed char *)cmemory_reference( \
                               (intxx)((char *)(v) + \
                               (CELL-TAG_VECTOR)+((intxx)(n)))))
#else 
#define vechdr(v)  (*(Header *)((char *)(v) - TAG_VECTOR))
#define elt(v, n)  (*(Lisp_Object *)((char *)(v) + \
                               (CELL-TAG_VECTOR) + \
                               (((intxx)(n))<<ADDRESS_SHIFT)))
#define celt(v, n) (*((char *)(v) + (CELL-TAG_VECTOR)+((intxx)(n))))
#define ucelt(v, n) (*((unsigned char *)(v) + (CELL-TAG_VECTOR)+((intxx)(n))))
#define scelt(v, n) (*((signed char *)(v) + (CELL-TAG_VECTOR)+((intxx)(n))))
#endif 
#ifdef ADDRESS_64
#define helt(v, n) \
   ((*(unsigned char *)((v) + (CELL-TAG_VECTOR) + (2*(intxx)(n))) | \
    (*(signed char *)((v) + (CELL-TAG_VECTOR+1) + (2*(intxx)(n)))) << 8))
#define sethelt(v, n, x) \
   do { \
      *(char *)((v) + (CELL-TAG_VECTOR+0) + (2*(intxx)(n))) = (x); \
      *(char *)((v) + (CELL-TAG_VECTOR+1) + (2*(intxx)(n))) = (x)>>8; \
      } while (0)
#else
#define helt(v, n)  (*(short int *)((char *)(v) + \
                           (CELL-TAG_VECTOR)+(2*(intxx)(n))))
#define sethelt(v, n, x) (helt(v, n) = (x))
#endif 
#define ielt(v, n)  (*(intxx *)((char *)(v) + \
                           (CELL-TAG_VECTOR)+(((intxx)(n))<<ADDRESS_SHIFT)))
#define ielt32(v, n)  (*(int32 *)((char *)(v) + \
                           (CELL-TAG_VECTOR)+(((intxx)(n))<<2)))
#define felt(v, n)  (*(float *)((char *)(v) + \
                           (CELL-TAG_VECTOR)+(((intxx)(n))<<2)))
#define delt(v, n)  (*(double *)((char *)(v) + \
                           (2*CELL-TAG_VECTOR)+(((intxx)(n))<<3)))
#ifdef COMMON
#define TYPE_BITVEC1        0x030   
#define TYPE_BITVEC2        0x0b0   
#define TYPE_BITVEC3        0x130
#define TYPE_BITVEC4        0x1b0   
#define TYPE_BITVEC5        0x230   
#define TYPE_BITVEC6        0x2b0   
#define TYPE_BITVEC7        0x330   
#define TYPE_BITVEC8        0x3b0   
#define header_of_bitvector(h) (((h) & 0x70) == TYPE_BITVEC1)
#endif 
#define TYPE_STRING         0x070   
#define TYPE_BPS            0x170   
#define TYPE_SPARE          0x270   
#define TYPE_MAPLEREF       TYPE_SPARE 
#define TYPE_SP             0x370   
#ifdef COMMON
#define vector_holds_binary(h) (((h) & 0x80) == 0 || header_of_bitvector(h))
#else
#define vector_holds_binary(h) (((h) & 0x80) == 0)
#endif
#define TYPE_SIMPLE_VEC     0x0f0   
#define TYPE_HASH           0x1f0   
#define TYPE_ARRAY          0x2f0   
#define TYPE_STRUCTURE      0x3f0   
#define is_mixed_header(h) (((h) & 0x2b0) == TYPE_MIXED1)
#define TYPE_VEC8           TYPE_BPS
#define TYPE_VEC16          0x220   
#define TYPE_VEC32          0x260   
#define TYPE_MIXED1         0x2a0   
#define TYPE_MIXED2         0x2e0   
#define TYPE_FLOAT32        0x320   
#define TYPE_FLOAT64        0x360   
#define TYPE_MIXED3         0x3a0   
#define TYPE_STREAM         0x3e0   
#define ODDS_MASK           0xff
#define TAG_CHAR            0x02    
#define TAG_BPS             0x42
#define TAG_SPID            0xc2    
#define SPID_NIL            (TAG_SPID+0x0000)  
#define SPID_FBIND          (TAG_SPID+0x0100)  
#define SPID_CATCH          (TAG_SPID+0x0200)  
#define SPID_PROTECT        (TAG_SPID+0x0300)  
#define SPID_HASH0          (TAG_SPID+0x0400)  
#define SPID_HASH1          (TAG_SPID+0x0500)  
#define SPID_GCMARK         (TAG_SPID+0x0600)  
#define SPID_NOINPUT        (TAG_SPID+0x0700)  
#define SPID_ERROR          (TAG_SPID+0x0800)  
#define SPID_PVBIND         (TAG_SPID+0x0900)  
#define SPID_NOARG          (TAG_SPID+0x0a00)  
#define SPID_NOPROP         (TAG_SPID+0x0b00)  
#define SPID_LIBRARY        (TAG_SPID+0x0c00)  
#define is_header(x) (((int)(x) & 0x30) != 0)     
#define is_char(x)   (((int)(x) & ODDS_MASK) == TAG_CHAR)
#define is_bps(x)    (((int)(x) & ODDS_MASK) == TAG_BPS)
#define is_hashtab(x)(((int)(x) & ODDS_MASK) == TAG_HASHTAB)
#define is_spid(x)   (((int)(x) & ODDS_MASK) == TAG_SPID)
#define is_library(x)(((int)(x) & 0xffff)    == SPID_LIBRARY)
#define library_number(x) (((x) >> 20) & 0xfff)
#define font_of_char(n)  (((int32)(n) >> 24) & 0xff)
#define bits_of_char(n)  (((int32)(n) >> 16) & 0xff)
#ifdef Kanji
#define code_of_char(n)  (((int32)(n) >>  8) & 0xffff)
#else
#define code_of_char(n)  ((char)(((int32)(n) >>  8) & 0xff))
#endif
#define pack_char(bits, font, code)                                \
    ((Lisp_Object)((((unsigned32)(font)) << 24) |                  \
    (((unsigned32)(bits)) << 16) | (((unsigned32)(code)) << 8) | TAG_CHAR))
    
#define CHAR_EOF pack_char(0, 0xff, 4)
 
#define data_of_bps(v) \
  ((char *)(doubleword_align_up((intxx) \
             bps_pages[((unsigned32)(v))>>(PAGE_BITS+6)]) + \
            (((v) >> 6) & (PAGE_POWER_OF_TWO-4))))
typedef int32 junk;      
typedef intxx junkxx;    
typedef struct Symbol_Head
{
    Header header;      
    Lisp_Object value;  
    Lisp_Object env;    
    intxx function1;     
    intxx function2;     
    intxx functionn;     
    Lisp_Object pname;   
    Lisp_Object plist;   
    Lisp_Object fastgets;
    unsignedxx count;    
#ifdef COMMON
    Lisp_Object package;
#endif
} Symbol_Head;
#define MAX_FASTGET_SIZE  63
#ifdef ADDRESS_64
#ifdef COMMON
#define symalign(n) ((char *)((intxx)(n) & ~(intxx)TAG_SYMBOL))
#else
#define symalign(n) (n)
#endif
#else
#define symalign(n) (n)
#endif
#ifndef MEMORY_TRACE
#define qheader(p)     (*(Header *)     symalign((char *)(p) - TAG_SYMBOL))
#define qvalue(p)      (*(Lisp_Object *)symalign((char *)(p) + (CELL - TAG_SYMBOL)))
#define qenv(p)        (*(Lisp_Object *)symalign((char *)(p) + (2*CELL - TAG_SYMBOL)))
#define qfn1(p)        ((one_args *) *((intxx *)symalign((char *)(p) + \
                                         (3*CELL - TAG_SYMBOL))))
#define qfn2(p)        ((two_args *) *((intxx *)symalign((char *)(p) + \
                                         (4*CELL - TAG_SYMBOL))))
#define qfnn(p)        ((n_args *)   *((intxx *)symalign((char *)(p) + \
                                         (5*CELL - TAG_SYMBOL))))
#define ifn1(p)        (*(intxx *)      symalign((char *)(p) + (3*CELL-TAG_SYMBOL)))
#define ifn2(p)        (*(intxx *)      symalign((char *)(p) + (4*CELL-TAG_SYMBOL)))
#define ifnn(p)        (*(intxx *)      symalign((char *)(p) + (5*CELL-TAG_SYMBOL)))
#define qpname(p)      (*(Lisp_Object *)symalign((char *)(p) + (6*CELL-TAG_SYMBOL)))
#define qplist(p)      (*(Lisp_Object *)symalign((char *)(p) + (7*CELL-TAG_SYMBOL)))
#define qfastgets(p)   (*(Lisp_Object *)symalign((char *)(p) + (8*CELL-TAG_SYMBOL)))
#define qcount(p)      (*(unsignedxx *) symalign((char *)(p) + (9*CELL-TAG_SYMBOL)))
#ifdef COMMON
#define qpackage(p)    (*(Lisp_Object *)symalign((char *)(p) + (10*CELL-TAG_SYMBOL)))
#endif
#else 
#define qheader(p)     (*(Header *)     memory_reference((intxx) \
                                         symalign((char *)(p) - TAG_SYMBOL)))
#define qvalue(p)      (*(Lisp_Object *)memory_reference((intxx) \
                                         symalign((char *)(p) + (CELL-TAG_SYMBOL))))
#define qenv(p)        (*(Lisp_Object *)memory_reference((intxx) \
                                         symalign((char *)(p) + (2*CELL-TAG_SYMBOL))))
#define qfn1(p)        ((one_args *) *(intxx *)memory_reference((intxx) \
                                         symalign((char *)(p) + (3*CELL-TAG_SYMBOL))))
#define qfn2(p)        ((two_args *) *(intxx *)memory_reference((intxx) \
                                         symalign((char *)(p) + (4*CELL-TAG_SYMBOL))))
#define qfnn(p)        ((n_args *)   *(intxx *)memory_reference((intxx) \
                                         symalign((char *)(p) + (5*CELL-TAG_SYMBOL))))
#define ifn1(p)        (*(intxx *)      memory_reference((intxx) \
                                         symalign((char *)(p) + (3*CELL-TAG_SYMBOL))))
#define ifn2(p)        (*(intxx *)      memory_reference((intxx) \
                                         symalign((char *)(p) + (4*CELL-TAG_SYMBOL))))
#define ifnn(p)        (*(intxx *)      memory_reference((intxx) \
                                         symalign((char *)(p) + (5*CELL-TAG_SYMBOL))))
#define qpname(p)      (*(Lisp_Object *)memory_reference((intxx) \
                                         symalign((char *)(p) + (6*CELL-TAG_SYMBOL))))
#define qplist(p)      (*(Lisp_Object *)memory_reference((intxx) \
                                         symalign((char *)(p) + (7*CELL-TAG_SYMBOL))))
#define qfastgets(p)   (*(Lisp_Object *)memory_reference((intxx) \
                                         symalign((char *)(p) + (8*CELL-TAG_SYMBOL))))
#define qcount(p)      (*(unsigned32 *) memory_reference((intxx) \
                                         symalign((char *)(p) + (9*CELL-TAG_SYMBOL))))
#ifdef COMMON
#define qpackage(p)    (*(Lisp_Object *)memory_reference((intxx) \
                                         symalign((char *)(p) + (10*CELL-TAG_SYMBOL))))
#endif
#endif 
#ifdef COMMON
typedef union Float_union
{
    float f;
    int32 i;
} Float_union;
#endif
typedef struct Big_Number
{
    Header h;
    unsigned32 d[1];  
} Big_Number;
#define bignum_length(b)  length_of_header(numhdr(b))
#ifdef MEMORY_TRACE
#define bignum_digits(b)  ((unsigned32 *)memory_reference((intxx)((char *)b + \
                                         (CELL-TAG_NUMBERS))))
#else
#define bignum_digits(b)  ((unsigned32 *)((char *)b  + (CELL-TAG_NUMBERS)))
#endif
#define make_bighdr(n)    (TAG_ODDS+TYPE_BIGNUM+(((intxx)(n))<<12))
#define pack_hdrlength(n) (((intxx)(n))<<12)
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
       int32 i;
    } f;
} Single_Float;
#define single_float_val(v) \
    (((Single_Float *)((char *)(v)-TAG_BOXFLOAT))->f.f)
#endif 
typedef struct Double_Float
{
    Header header;
#ifndef ADDRESS_64
    junk padding;     
#endif
    union double_or_ints {
        double f;         
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
    junk padding;
#endif
    union long_or_ints {
        double f;
        int32 i[2];
    } f;
} Long_Float;
#define long_float_val(v)       (*(double *)((char *)(v) + \
                                   (8-TAG_BOXFLOAT)))
#endif
#define doubleword_align_up(n) ((Lisp_Object)(((intxx)(n) + 7) & (-8)))
#define doubleword_align_down(n) ((Lisp_Object)((intxx)(n) & (-8)))
#define quadword_align_up(n) ((Lisp_Object)(((intxx)(n) + 15) & (-16)))
#define quadword_align_down(n) ((Lisp_Object)((intxx)(n) & (-16)))
#define UNWIND_NULL       0x0         
#define UNWIND_GO         0x1
#define UNWIND_RETURN     0x2
#define UNWIND_THROW      0x3
#define UNWIND_RESTART    0x4
#define UNWIND_ERROR      0x100       
#define UNWIND_UNWIND     0x200       
#endif 
#ifndef header_cslerror_h
#define header_cslerror_h 1
extern Lisp_Object interrupted(Lisp_Object p);
extern Lisp_Object MS_CDECL error(int nargs, int code, ...);
extern Lisp_Object MS_CDECL cerror(int nargs, int code1, int code2, ...);
extern Lisp_Object too_few_2(Lisp_Object env, Lisp_Object a1);
extern Lisp_Object too_many_1(Lisp_Object env, Lisp_Object a1, Lisp_Object a2);
extern Lisp_Object wrong_no_0a(Lisp_Object env, Lisp_Object a1);
extern Lisp_Object wrong_no_0b(Lisp_Object env, Lisp_Object a1, Lisp_Object a2);
extern Lisp_Object wrong_no_3a(Lisp_Object env, Lisp_Object a1);
extern Lisp_Object wrong_no_3b(Lisp_Object env, Lisp_Object a1, Lisp_Object a2);
extern Lisp_Object wrong_no_na(Lisp_Object env, Lisp_Object a1);
extern Lisp_Object wrong_no_nb(Lisp_Object env, Lisp_Object a1, Lisp_Object a2);
extern Lisp_Object MS_CDECL wrong_no_1(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL wrong_no_2(Lisp_Object env, int nargs, ...);
extern Lisp_Object bad_special2(Lisp_Object env, Lisp_Object a1, Lisp_Object a2);
extern Lisp_Object MS_CDECL bad_specialn(Lisp_Object env, int nargs, ...);
extern Lisp_Object aerror(char *s);         
extern Lisp_Object aerror0(char *s);
extern Lisp_Object aerror1(char *s, Lisp_Object a);
extern Lisp_Object aerror2(char *s, Lisp_Object a, Lisp_Object b);
extern void MS_CDECL fatal_error(int code, ...);
#define GC_MESSAGES   0x01
#define FASL_MESSAGES 0x02
#define VERBOSE_MSGS  0x04
#define GC_MSG_BITS   0x07
#define HEADLINE_FLAG 0x08
#define MESSAGES_FLAG 0x10
#define ALWAYS_NOISY  0x20
#define verbos_flag (miscflags & GC_MSG_BITS)
 
#define err_bad_car               0      
#define err_bad_cdr               1      
#define err_no_store              2      
#define err_undefined_function_1  3      
#define err_undefined_function_2  4      
#define err_undefined_function_n  5      
#define err_wrong_no_args         6      
#define err_unbound_lexical       7      
#define err_bad_rplac             8      
#define err_bad_arith             9      
#define err_redef_special        10      
#define err_bad_arg              11      
#define err_bad_declare          12      
#define err_bad_fn               13      
#define err_unset_var            14      
#define err_too_many_args1       15      
#define err_too_many_args2       16      
#define err_bad_apply            17      
#define err_macroex_hook         18      
#define err_block_tag            19      
#define err_go_tag               20      
#define err_excess_args          21
#define err_insufficient_args    22
#define err_bad_bvl              23      
#define err_bad_keyargs          24
#define err_write_err            25
#define err_bad_endp             26      
#define err_no_fasldir           27
#define err_no_fasl              28      
#define err_open_failed          29      
#define err_pipe_failed          30      
#define err_stack_overflow       31
#define err_top_bit              32
#define err_mem_spans_zero       33
#define err_registration         34
#define err_no_tempdir           35
    
#ifdef INCLUDE_ERROR_STRING_TABLE
static char *error_message_table[] =
{
    "attempt to take car of an atom",
    "attempt to take cdr of an atom",
    "insufficient freestore to run this package",
    "undefined function (1 arg)",
    "undefined function (2 args)",
    "undefined function",
    "wrong number of arguments",
    "unbound lexical variable",
    "bad rplaca/rplacd",
    "bad argument for an arithmetic function",
    "attempt to redefine a special form",
    "not a variable",
    "bad use of declare",
    "attempt to apply non-function",
    "unset variable",
    "too many arguments",
    "too many arguments",
    "object not valid as a function (apply,",
    "macroexpand-hook failure",
    "block tag not found",
    "go tag not found",
    "too many arguments provided",
    "not enough arguments provided",
    "bad item in bound variable list",
    "bad keyword arguments",
    "write-error on file",
    "endp used on badly terminated list",
    "environment parameter 'fasldir' not set",
    "loadable module not found for loading",
    "file could not be opened",
    "unable to establish pipe",
    "stack overflow",
    "top bit of address has unexpected value",
    "memory block spans the zero address",
    "registration code corrupt or invalid",
    "unable to find a directory for temporary files",
    "dummy final error message"
};
#endif
#endif 
#ifndef header_externs_h
#define header_externs_h 1
#ifdef __cplusplus
extern "C" {
#endif
#ifdef USE_MPI
#include "mpi.h"
extern int32 mpi_rank,mpi_size;
#endif
extern void **pages,
            **heap_pages, **vheap_pages,
            **bps_pages, **native_pages;
#ifndef NO_COPYING_GC
extern void **new_heap_pages, **new_vheap_pages,
            **new_bps_pages, **new_native_pages;
#endif
extern int32 pages_count,
             heap_pages_count, vheap_pages_count,
             bps_pages_count, native_pages_count;
#ifndef NO_COPYING_GC
extern int32 new_heap_pages_count, new_vheap_pages_count,
             new_bps_pages_count, new_native_pages_count;
#endif
extern int native_pages_changed;
extern int32 native_fringe;
extern Lisp_Object *nilsegment, *stacksegment;
extern Lisp_Object *stackbase;
extern int32 stack_segsize;  
extern Lisp_Object *C_stack;
#define stack C_stack
#ifdef MEMORY_TRACE
#define push(a)         do { \
                          *++stack = (a); \
                          memory_reference((intxx)stack); } while (0)
#define push2(a,b)      do { \
                          *++stack = (a); \
                          memory_reference((intxx)stack); \
                          *++stack = (b); \
                          memory_reference((intxx)stack); } while (0)
#define push3(a,b,c)    do { \
                          *++stack = (a); \
                          memory_reference((intxx)stack); \
                          *++stack = (b); \
                          memory_reference((intxx)stack); \
                          *++stack = (c); \
                          memory_reference((intxx)stack); } while (0)
#define push4(a,b,c,d)  do { \
                          *++stack = (a); \
                          memory_reference((intxx)stack); \
                          *++stack = (b); \
                          memory_reference((intxx)stack); \
                          *++stack = (c); \
                          memory_reference((intxx)stack); \
                          *++stack = (d); \
                          memory_reference((intxx)stack); } while (0)
#define push5(a,b,c,d,e)do { \
                          *++stack = (a); \
                          memory_reference((intxx)stack); \
                          *++stack = (b); \
                          memory_reference((intxx)stack); \
                          *++stack = (c); \
                          memory_reference((intxx)stack); \
                          *++stack = (d); \
                          memory_reference((intxx)stack); \
                          *++stack = (e); \
                          memory_reference((intxx)stack); } while (0)
#define push6(a,b,c,d,e,f) do {push3(a,b,c); push3(d,e,f); } while (0)
#define my_pop()        (memory_reference((int32)stack), (*stack--))
#define pop(a)          { memory_reference((intxx)stack); (a) = *stack--; }
#define pop2(a,b)       { memory_reference((intxx)stack); (a) = *stack--; memory_reference((intxx)stack); (b) = *stack--; }
#define pop3(a,b,c)     { memory_reference((intxx)stack); (a) = *stack--; memory_reference((intxx)stack); (b) = *stack--; memory_reference((intxx)stack); (c) = *stack--; }
#define pop4(a,b,c,d)   { memory_reference((intxx)stack); (a) = *stack--; memory_reference((intxx)stack); (b) = *stack--; memory_reference((intxx)stack); (c) = *stack--; \
                          memory_reference((intxx)stack); (d) = *stack--; }
#define pop5(a,b,c,d,e) { memory_reference((intxx)stack); (a) = *stack--; memory_reference((intxx)stack); (b) = *stack--; memory_reference((intxx)stack); (c) = *stack--; \
                          memory_reference((intxx)stack); (d) = *stack--; memory_reference((intxx)stack); (e) = *stack--; }
#define pop6(a,b,c,d,e,f) {pop3(a,b,c); pop3(d,e,f)}
#define popv(n)           stack -= (n)
#else 
#define push(a)         { *++stack = (a); }
#define push2(a,b)      { stack[1] = (a); stack[2] = (b); stack += 2; }
#define push3(a,b,c)    { stack[1] = (a); stack[2] = (b); stack[3] = (c); \
                          stack += 3; }
#define push4(a,b,c,d)  { stack[1] = (a); stack[2] = (b); stack[3] = (c); \
                          stack[4] = (d); stack += 4; }
#define push5(a,b,c,d,e){ stack[1] = (a); stack[2] = (b); stack[3] = (c); \
                          stack[4] = (d); stack[5] = (e); stack += 5; }
#define push6(a,b,c,d,e,f) {                                              \
                          stack[1] = (a); stack[2] = (b); stack[3] = (c); \
                          stack[4] = (d); stack[5] = (e); stack[6] = (f); \
                          stack += 6; }
#define pop(a)          { (a) = *stack--; }
#define pop2(a,b)       { stack -= 2;     (a) = stack[2]; (b) = stack[1]; }
#define pop3(a,b,c)     { stack -= 3;     (a) = stack[3]; (b) = stack[2]; \
                          (c) = stack[1]; }
#define pop4(a,b,c,d)   { stack -= 4;     (a) = stack[4]; (b) = stack[3]; \
                          (c) = stack[2]; (d) = stack[1]; }
#define pop5(a,b,c,d,e) { stack -= 5;     (a) = stack[5]; (b) = stack[4]; \
                          (c) = stack[3]; (d) = stack[2]; (e) = stack[1]; }
#define pop6(a,b,c,d,e, f) { stack -= 6;                                  \
                          (a) = stack[6]; (b) = stack[5]; (c) = stack[4]; \
                          (d) = stack[3]; (e) = stack[2]; (f) = stack[1]; }
#define popv(n)           stack -= (n)
#endif 
#define errexit()    { nil = C_nil; if (exception_pending()) return nil; }
#define errexitn(n)  { nil = C_nil;                                      \
                       if (exception_pending()) { popv(n); return nil; } }
#define errexitv()   { nil = C_nil; if (exception_pending()) return; }
#define errexitvn(n) { nil = C_nil;                                      \
                       if (exception_pending()) { popv(n); return; } }
#define GC_USER_SOFT 0
#define GC_USER_HARD 1
#define GC_STACK     2
#define GC_CONS      3
#define GC_VEC       4
#define GC_BPS       5
#define GC_PRESERVE  6
#define GC_NATIVE    7
#ifdef CHECK_STACK
extern int check_stack(char *file, int line);
#define if_check_stack \
   if (check_stack(__FILE__,__LINE__)) return aerror("stack overflow");
#else
#define if_check_stack
#endif
extern int32 software_ticks, countdown;
#define stackcheck0(k)                                      \
    if_check_stack                                          \
    if ((--countdown < 0 && deal_with_tick()) ||            \
        stack >= stacklimit)                                \
    {   reclaim(nil, "stack", GC_STACK, 0);                 \
        nil = C_nil;                                        \
        if (exception_pending()) { popv(k); return nil; }   \
    }
#define stackcheck1(k, a1)                                  \
    if_check_stack                                          \
    if ((--countdown < 0 && deal_with_tick()) ||            \
        stack >= stacklimit)                                \
    {   a1 = reclaim(a1, "stack", GC_STACK, 0);             \
        nil = C_nil;                                        \
        if (exception_pending()) { popv(k); return nil; }   \
    }
#define stackcheck2(k, a1, a2)                              \
    if_check_stack                                          \
    if ((--countdown < 0 && deal_with_tick()) ||            \
        stack >= stacklimit)                                \
    {   push(a2);                                           \
        a1 = reclaim(a1, "stack", GC_STACK, 0); pop(a2);    \
        nil = C_nil;                                        \
        if (exception_pending()) { popv(k); return nil; }   \
    }
#define stackcheck3(k, a1, a2, a3)                          \
    if_check_stack                                          \
    if ((--countdown < 0 && deal_with_tick()) ||            \
        stack >= stacklimit)                                \
    {   push2(a2, a3);                                      \
        a1 = reclaim(a1, "stack", GC_STACK, 0);             \
        pop2(a3, a2);                                       \
        nil = C_nil;                                        \
        if (exception_pending()) { popv(k); return nil; }   \
    }
#define stackcheck4(k, a1, a2, a3, a4)                      \
    if_check_stack                                          \
    if ((--countdown < 0 && deal_with_tick()) ||            \
        stack >= stacklimit)                                \
    {   push3(a2, a3, a4);                                  \
        a1 = reclaim(a1, "stack", GC_STACK, 0);             \
        pop3(a4, a3, a2);                                   \
        nil = C_nil;                                        \
        if (exception_pending()) { popv(k); return nil; }   \
    }
extern Lisp_Object C_nil;
#define first_nil_offset         50     
#define work_0_offset           200
#define last_nil_offset         251
#define NIL_SEGMENT_SIZE    (last_nil_offset*sizeof(Lisp_Object) + 32)
#define SPARE                   512
#ifdef ADDRESS_64
#ifdef COMMON
#define BASE ((Lisp_Object *)nil)
#else
#define BASE ((Lisp_Object *)(nil+4))
#endif
#else
#define BASE ((Lisp_Object *)nil)
#endif
#ifdef NILSEG_EXTERNS
#define nil_as_base
extern unsigned32 byteflip;
extern Lisp_Object codefringe;
extern Lisp_Object volatile codelimit;
extern Lisp_Object * volatile stacklimit;
extern Lisp_Object fringe;
extern Lisp_Object volatile heaplimit;
extern Lisp_Object volatile vheaplimit;
extern Lisp_Object vfringe;
extern int32 nwork;
extern int32 exit_reason;
extern int32 exit_count;
extern unsigned32 gensym_ser, print_precision, miscflags;
extern int32 current_modulus, fastget_size, package_bits;
extern Lisp_Object lisp_true, lambda, funarg, unset_var, opt_key, rest_key;
extern Lisp_Object quote_symbol, function_symbol, comma_symbol;
extern Lisp_Object comma_at_symbol, cons_symbol, eval_symbol;
extern Lisp_Object work_symbol, evalhook, applyhook, macroexpand_hook;
extern Lisp_Object append_symbol, exit_tag, exit_value, catch_tags;
extern Lisp_Object current_package, startfn;
extern Lisp_Object gensym_base, string_char_sym, boffo;
extern Lisp_Object err_table;
extern Lisp_Object progn_symbol;
extern Lisp_Object lisp_work_stream, charvec, raise_symbol, lower_symbol;
extern Lisp_Object echo_symbol, codevec, litvec, supervisor, B_reg;
extern Lisp_Object savedef, comp_symbol, compiler_symbol, faslvec;
extern Lisp_Object tracedfn, lisp_terminal_io;
extern Lisp_Object lisp_standard_output, lisp_standard_input, lisp_error_output;
extern Lisp_Object lisp_trace_output, lisp_debug_io, lisp_query_io;
extern Lisp_Object prompt_thing, faslgensyms;
extern Lisp_Object prinl_symbol, emsg_star, redef_msg;
extern Lisp_Object expr_symbol, fexpr_symbol, macro_symbol;
extern Lisp_Object cl_symbols, active_stream, current_module;
extern Lisp_Object native_defs, features_symbol, lisp_package;
extern Lisp_Object sys_hash_table, help_index, cfunarg, lex_words;
extern Lisp_Object get_counts, fastget_names, input_libraries;
extern Lisp_Object output_library, current_file, break_function;
extern Lisp_Object standard_output, standard_input, debug_io;
extern Lisp_Object error_output, query_io, terminal_io;
extern Lisp_Object trace_output, fasl_stream;
extern Lisp_Object native_code, native_symbol, traceprint_symbol;
extern Lisp_Object loadsource_symbol;
extern Lisp_Object hankaku_symbol, bytecoded_symbol, nativecoded_symbol;
#ifdef COMMON
extern Lisp_Object keyword_package;
extern Lisp_Object all_packages, package_symbol, internal_symbol;
extern Lisp_Object external_symbol, inherited_symbol;
extern Lisp_Object key_key, allow_other_keys, aux_key;
extern Lisp_Object format_symbol;
extern Lisp_Object expand_def_symbol, allow_key_key, declare_symbol;
extern Lisp_Object special_symbol;
#endif
#ifdef OPENMATH
extern Lisp_Object MS_CDECL om_openFileDev(Lisp_Object env, int nargs, ...);
extern Lisp_Object om_openStringDev(Lisp_Object nil, Lisp_Object lstr, Lisp_Object lenc);
extern Lisp_Object om_closeDev(Lisp_Object env, Lisp_Object dev);
extern Lisp_Object om_setDevEncoding(Lisp_Object nil, Lisp_Object ldev, Lisp_Object lenc);
extern Lisp_Object om_makeConn(Lisp_Object nil, Lisp_Object ltimeout);
extern Lisp_Object om_closeConn(Lisp_Object nil, Lisp_Object lconn);
extern Lisp_Object om_getConnInDevice(Lisp_Object nil, Lisp_Object lconn);
extern Lisp_Object om_getConnOutDevice(Lisp_Object nil, Lisp_Object lconn);
extern Lisp_Object MS_CDECL om_connectTCP(Lisp_Object nil, int nargs, ...);
extern Lisp_Object om_bindTCP(Lisp_Object nil, Lisp_Object lconn, Lisp_Object lport);
extern Lisp_Object om_putApp(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putEndApp(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putAtp(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putEndAtp(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putAttr(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putEndAttr(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putBind(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putEndBind(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putBVar(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putEndBVar(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putError(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putEndError(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putObject(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putEndObject(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putInt(Lisp_Object nil, Lisp_Object ldev, Lisp_Object val);
extern Lisp_Object om_putFloat(Lisp_Object nil, Lisp_Object ldev, Lisp_Object val);
extern Lisp_Object om_putByteArray(Lisp_Object nil, Lisp_Object ldev, Lisp_Object val);
extern Lisp_Object om_putVar(Lisp_Object nil, Lisp_Object ldev, Lisp_Object val);
extern Lisp_Object om_putString(Lisp_Object nil, Lisp_Object ldev, Lisp_Object val);
extern Lisp_Object om_putSymbol(Lisp_Object nil, Lisp_Object ldev, Lisp_Object val);
extern Lisp_Object MS_CDECL om_putSymbol2(Lisp_Object nil, int nargs, ...);
extern Lisp_Object om_getApp(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getEndApp(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getAtp(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getEndAtp(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getAttr(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getEndAttr(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getBind(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getEndBind(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getBVar(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getEndBVar(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getError(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getEndError(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getObject(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getEndObject(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getInt(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getFloat(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getByteArray(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getVar(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getString(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getSymbol(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getType(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_stringToStringPtr(Lisp_Object nil, Lisp_Object lstr);
extern Lisp_Object om_stringPtrToString(Lisp_Object nil, Lisp_Object lpstr);
extern Lisp_Object om_read(Lisp_Object nil, Lisp_Object dev);
extern Lisp_Object om_supportsCD(Lisp_Object nil, Lisp_Object lcd);
extern Lisp_Object om_supportsSymbol(Lisp_Object nil, Lisp_Object lcd, Lisp_Object lsym);
extern Lisp_Object MS_CDECL om_listCDs(Lisp_Object nil, int nargs, ...);
extern Lisp_Object om_listSymbols(Lisp_Object nil, Lisp_Object lcd);
extern Lisp_Object om_whichCDs(Lisp_Object nil, Lisp_Object lsym);
#endif
extern Lisp_Object workbase[51];
extern Lisp_Object user_base_0, user_base_1, user_base_2;
extern Lisp_Object user_base_3, user_base_4, user_base_5;
extern Lisp_Object user_base_6, user_base_7, user_base_8;
extern Lisp_Object user_base_9;
#define work_0              workbase[0]
#define work_1              workbase[1]
#define mv_1                workbase[1]
#define mv_2                workbase[2]
#define mv_3                workbase[3]
#define work_50             workbase[50]
#else 
#define nil_as_base  Lisp_Object nil = C_nil;
#define byteflip              (*(unsigned32 *)&BASE[12])
#define codefringe            BASE[13]
#define codelimit             (*(Lisp_Object volatile *)&BASE[14])
extern Lisp_Object * volatile stacklimit;
#define fringe                BASE[18]
#define heaplimit             (*(Lisp_Object volatile *)&BASE[19])
#define vheaplimit            (*(Lisp_Object volatile *)&BASE[20])
#define vfringe               BASE[21]
#define miscflags             (*(unsigned32 *)&BASE[22])
#define nwork                 (*(int32 *)&BASE[24])
#define exit_reason           (*(int32 *)&BASE[25])
#define exit_count            (*(int32 *)&BASE[26])
#define gensym_ser            (*(unsigned32 *)&BASE[27])
#define print_precision       (*(unsigned32 *)&BASE[28])
#define current_modulus       (*(int32 *)&BASE[29])
#define fastget_size          (*(int32 *)&BASE[30])
#define package_bits          (*(int32 *)&BASE[31])
#define current_package       BASE[52]
#define B_reg                 BASE[53]
#define codevec               BASE[54]
#define litvec                BASE[55]
#define exit_tag              BASE[56]
#define exit_value            BASE[57]
#define catch_tags            BASE[58]
#define lisp_package          BASE[59]
#define boffo                 BASE[60]
#define charvec               BASE[61]
#define sys_hash_table        BASE[62]
#define help_index            BASE[63]
#define gensym_base           BASE[64]
#define err_table             BASE[65]
#define supervisor            BASE[66]
#define startfn               BASE[67]
#define faslvec               BASE[68]
#define tracedfn              BASE[69]
#define prompt_thing          BASE[70]
#define faslgensyms           BASE[71]
#define cl_symbols            BASE[72]
#define active_stream         BASE[73]
#define current_module        BASE[74]
#define native_defs           BASE[75]
#define append_symbol         BASE[90]
#define applyhook             BASE[91]
#define cfunarg               BASE[92]
#define comma_at_symbol       BASE[93]
#define comma_symbol          BASE[94]
#define compiler_symbol       BASE[95]
#define comp_symbol           BASE[96]
#define cons_symbol           BASE[97]
#define echo_symbol           BASE[98]
#define emsg_star             BASE[99]
#define evalhook              BASE[100]
#define eval_symbol           BASE[101]
#define expr_symbol           BASE[102]
#define features_symbol       BASE[103]
#define fexpr_symbol          BASE[104]
#define funarg                BASE[105]
#define function_symbol       BASE[106]
#define lambda                BASE[107]
#define lisp_true             BASE[108]
#define lower_symbol          BASE[109]
#define macroexpand_hook      BASE[110]
#define macro_symbol          BASE[111]
#define opt_key               BASE[112]
#define prinl_symbol          BASE[113]
#define progn_symbol          BASE[114]
#define quote_symbol          BASE[115]
#define raise_symbol          BASE[116]
#define redef_msg             BASE[117]
#define rest_key              BASE[118]
#define savedef               BASE[119]
#define string_char_sym       BASE[120]
#define unset_var             BASE[121]
#define work_symbol           BASE[122]
#define lex_words             BASE[123]
#define get_counts            BASE[124]
#define fastget_names         BASE[125]
#define input_libraries       BASE[126]
#define output_library        BASE[127]
#define current_file          BASE[128]
#define break_function        BASE[129]
#define lisp_work_stream      BASE[130]
#define lisp_standard_output  BASE[131]
#define lisp_standard_input   BASE[132]
#define lisp_debug_io         BASE[133]
#define lisp_error_output     BASE[134]
#define lisp_query_io         BASE[135]
#define lisp_terminal_io      BASE[136]
#define lisp_trace_output     BASE[137]
#define standard_output       BASE[138]
#define standard_input        BASE[139]
#define debug_io              BASE[140]
#define error_output          BASE[141]
#define query_io              BASE[142]
#define terminal_io           BASE[143]
#define trace_output          BASE[144]
#define fasl_stream           BASE[145]
#define native_code           BASE[146]
#define native_symbol         BASE[147]
#define traceprint_symbol     BASE[148]
#define loadsource_symbol     BASE[149]
#define hankaku_symbol        BASE[150]
#define bytecoded_symbol      BASE[151]
#define nativecoded_symbol    BASE[152]
#ifdef COMMON
#define keyword_package       BASE[170]
#define all_packages          BASE[171]
#define package_symbol        BASE[172]
#define internal_symbol       BASE[173]
#define external_symbol       BASE[174]
#define inherited_symbol      BASE[175]
#define key_key               BASE[176]
#define allow_other_keys      BASE[177]
#define aux_key               BASE[178]
#define format_symbol         BASE[179]
#define expand_def_symbol     BASE[180]
#define allow_key_key         BASE[181]
#define declare_symbol        BASE[182]
#define special_symbol        BASE[183]
#endif
extern Lisp_Object user_base_0, user_base_1, user_base_2;
extern Lisp_Object user_base_3, user_base_4, user_base_5;
extern Lisp_Object user_base_6, user_base_7, user_base_8;
extern Lisp_Object user_base_9;
#define work_0                BASE[200]
#define work_1                BASE[201]
#define mv_1                  work_1
#define mv_2                  BASE[202]
#define mv_3                  BASE[203]
#define work_50               BASE[250]
#endif 
extern void copy_into_nilseg(int fg);
extern void copy_out_of_nilseg(int fg);
#define eq_hash_table_list     BASE[50] 
#define equal_hash_table_list  BASE[51] 
#define current_package_offset 52
extern void rehash_this_table(Lisp_Object v);
extern Lisp_Object eq_hash_tables, equal_hash_tables;
extern Lisp_Object volatile savecodelimit;
extern Lisp_Object * volatile savestacklimit;
extern Lisp_Object volatile saveheaplimit;
extern Lisp_Object volatile savevheaplimit;
extern char *exit_charvec;
#ifdef DEBUG
extern int trace_all;
#endif
#define MAX_INPUT_FILES         40  
#define MAX_SYMBOLS_TO_DEFINE   40
#define MAX_FASL_PATHS          20
extern char *files_to_read[MAX_INPUT_FILES],
     *symbols_to_define[MAX_SYMBOLS_TO_DEFINE],
     *fasl_paths[MAX_FASL_PATHS];
extern int fasl_output_file, output_directory;
extern FILE *binary_read_file;
#ifndef COMMON
#ifdef HAVE_FWIN
extern char **loadable_packages;
extern char **switches;
extern void review_switch_settings();
#endif
#endif
#ifdef SOCKETS
extern int sockets_ready;
extern void flush_socket(void);
#endif
extern CSLbool undefine_this_one[MAX_SYMBOLS_TO_DEFINE];
extern CSLbool always_noisy;
extern int number_of_input_files,
    number_of_symbols_to_define,
    number_of_fasl_paths,
    init_flags;
extern int native_code_tag;
extern char *standard_directory;
extern CSLbool gc_method_is_copying;
extern int32 gc_number;
#define INIT_QUIET      1
#define INIT_VERBOSE    2
#define INIT_EXPANDABLE 4
#define Lispify_predicate(p)  ((p) ? lisp_true : nil)
extern int tty_count;
extern FILE *spool_file;
extern char spool_file_name[32];
typedef struct Ihandle
{
    FILE *f;        
    long int o;     
    long int n;     
    unsigned32 chk; 
    int status;     
} Ihandle;
extern int32 compression_worth_while;
#define CODESIZE                0x1000
typedef struct entry_point1
{
    one_args *p;
    char *s;
} entry_point1;
typedef struct entry_point2
{
    two_args *p;
    char *s;
} entry_point2;
typedef struct entry_pointn
{
    n_args *p;
    char *s;
} entry_pointn;
extern entry_point1 entries_table1[];
extern entry_point2 entries_table2[];
extern entry_pointn entries_tablen[];
extern entry_pointn entries_table_io[];
extern void set_up_entry_lookup(void);
extern int32 code_up_fn1(one_args *e);
extern int32 code_up_fn2(two_args *e);
extern int32 code_up_fnn(n_args *e);
extern int32 code_up_io(void *e);
extern int doubled_execution;
extern char *linker_type;
extern char *compiler_command[], *import_data[],
            *config_header[], *csl_headers[];
extern Lisp_Object encapsulate_pointer(void *);
typedef void initfn(Lisp_Object *, Lisp_Object **, Lisp_Object * volatile *);
extern int load_dynamic(char *objname, char *modname,
                        Lisp_Object name, Lisp_Object fns);
extern Lisp_Object Linstate_c_code(Lisp_Object nil,
                                   Lisp_Object name, Lisp_Object fns);
#ifdef MEMORY_TRACE
extern intxx memory_base, memory_size;
extern unsigned char *memory_map;
extern FILE *memory_file;
extern void memory_comment(int n);
#endif
#define ARG_CUT_OFF 25
extern void push_args(va_list a, int nargs);
extern void push_args_1(va_list a, int nargs);
extern void Iinit(void);
extern void IreInit(void);
extern void Icontext(Ihandle *);
extern void Irestore_context(Ihandle);
extern void Ilist(void);
extern CSLbool open_output(char *s, int len);
extern CSLbool Iopen(char *name, int len, CSLbool dirn, char *expanded_name);
extern CSLbool Iopen_from_stdin(void), Iopen_to_stdout(void);
extern CSLbool IopenRoot(char *expanded_name, int hard);
extern CSLbool Iwriterootp(char *expanded);
extern CSLbool Iopen_help(int32 offset);
extern CSLbool Iopen_banner(int code);
extern CSLbool Imodulep(char *name, int len, char *datestamp, int32 *size,
                                 char *expanded_name);
extern CSLbool Icopy(char *name, int len);
extern CSLbool Idelete(char *name, int len);
extern CSLbool IcloseInput(int check_checksum);
extern CSLbool IcloseOutput(int write_checksum);
extern CSLbool Ifinished(void);
extern int  Igetc(void);
extern int32 Iread(void *buff, int32 size);
extern CSLbool Iputc(int ch);
extern CSLbool Iwrite(void *buff, int32 size);
extern long int Ioutsize(void);
extern char *CSLtmpnam(char *suffix, int32 suffixlen);
extern int Cmkdir(char *s);
#define REGISTRATION_SIZE     192
#define REGISTRATION_VERSION  "r1.0"
extern unsigned char registration_data[REGISTRATION_SIZE];
extern void CSL_MD5_Init(void);
extern void CSL_MD5_Update(unsigned char *data, int len);
extern void CSL_MD5_Final(unsigned char *md);
extern CSLbool CSL_MD5_busy;
extern unsigned char *CSL_MD5(unsigned char *data, int n, unsigned char *md);
extern void checksum(Lisp_Object a);
extern unsigned char unpredictable[256];
extern void inject_randomness(int n);
extern void crypt_init(char *key);
#define CRYPT_BLOCK 128
extern void crypt_get_block(unsigned char result[CRYPT_BLOCK]);
#define CRYPT_KEYS 10
extern char *crypt_keys[CRYPT_KEYS];
extern int crypt_active;
extern unsigned char *crypt_buffer;
extern int crypt_count;
extern void ensure_screen(void);
extern int window_heading;
extern void my_exit(int n);
extern void *my_malloc(size_t n);
extern clock_t base_time;
extern double *clock_stack;
extern void push_clock(void);
extern double pop_clock(void);
extern double consolidated_time[10], gc_time;
extern CSLbool volatile already_in_gc, tick_on_gc_exit;
extern CSLbool volatile interrupt_pending, tick_pending;
extern int deal_with_tick(void);
extern int current_fp_rep;
#ifndef __cplusplus
extern jmp_buf *errorset_buffer;
#endif
extern char *errorset_msg;
extern int errorset_code;
extern void unwind_stack(Lisp_Object *, CSLbool findcatch);
extern CSLbool segvtrap;
extern CSLbool batch_flag;
extern int escaped_printing;
extern void MS_CDECL low_level_signal_handler(int code);
extern int async_interrupt(int a);
extern void MS_CDECL sigint_handler(int code);
extern void record_get(Lisp_Object tag, CSLbool found);
extern int         primep(int32);
extern void        adjust_all(void);
extern void        set_up_functions(CSLbool restartp);
extern void        get_user_files_checksum(unsigned char *);
extern Lisp_Object acons(Lisp_Object a, Lisp_Object b, Lisp_Object c);
extern Lisp_Object ash(Lisp_Object a, Lisp_Object b);
extern Lisp_Object bytestream_interpret(Lisp_Object code, Lisp_Object lit,
                                        Lisp_Object *entry_stack);
extern CSLbool        complex_stringp(Lisp_Object a);
extern void        freshline_trace(void);
extern void        freshline_debug(void);
extern Lisp_Object cons(Lisp_Object a, Lisp_Object b);
extern Lisp_Object cons_no_gc(Lisp_Object a, Lisp_Object b);
extern Lisp_Object cons_gc_test(Lisp_Object a);
extern void        convert_fp_rep(void *p, int old_rep, int new_rep, int type);
extern Lisp_Object Ceval(Lisp_Object u, Lisp_Object env);
extern unsigned32  Crand(void);
extern Lisp_Object Cremainder(Lisp_Object a, Lisp_Object b);
extern void        Csrand(unsigned32 a, unsigned32 b);
extern void        discard(Lisp_Object a);
extern CSLbool eql_fn(Lisp_Object a, Lisp_Object b);
extern CSLbool cl_equal_fn(Lisp_Object a, Lisp_Object b);
extern CSLbool equal_fn(Lisp_Object a, Lisp_Object b);
#ifdef TRACED_EQUAL
extern CSLbool traced_equal_fn(Lisp_Object a, Lisp_Object b,
                                      char *, int, int);
#define equal_fn(a, b) traced_equal_fn(a, b, __FILE__, __LINE__, 0)
extern void dump_equals();
#endif
extern CSLbool equalp(Lisp_Object a, Lisp_Object b);
extern Lisp_Object apply(Lisp_Object fn, int nargs,
                         Lisp_Object env, Lisp_Object fname);
extern Lisp_Object apply_lambda(Lisp_Object def, int nargs,
                         Lisp_Object env, Lisp_Object name);
extern void        deallocate_pages(void);
extern void        drop_heap_segments(void);
extern Lisp_Object gcd(Lisp_Object a, Lisp_Object b);
extern Lisp_Object get_pname(Lisp_Object a);
#ifdef COMMON
extern Lisp_Object get(Lisp_Object a, Lisp_Object b, Lisp_Object c);
#else
extern Lisp_Object get(Lisp_Object a, Lisp_Object b);
#endif
extern Lisp_Object getvector(int tag, int32 type, intxx length);
extern Lisp_Object getvector_init(intxx n, Lisp_Object v);
extern Lisp_Object getcodevector(int32 type, intxx size);
extern unsigned32  hash_lisp_string(Lisp_Object s);
extern void lose_C_def(Lisp_Object a);
extern CSLbool        geq2(Lisp_Object a, Lisp_Object b);
extern CSLbool        greaterp2(Lisp_Object a, Lisp_Object b);
extern CSLbool        lesseq2(Lisp_Object a, Lisp_Object b);
extern CSLbool        lessp2(Lisp_Object a, Lisp_Object b);
extern Lisp_Object list2(Lisp_Object a, Lisp_Object b);
extern Lisp_Object list2star(Lisp_Object a, Lisp_Object b, Lisp_Object c);
extern Lisp_Object list3(Lisp_Object a, Lisp_Object b, Lisp_Object c);
extern Lisp_Object list3star(Lisp_Object a, Lisp_Object b,
                             Lisp_Object c, Lisp_Object d);
extern Lisp_Object list4(Lisp_Object a, Lisp_Object b,
                         Lisp_Object c, Lisp_Object d);
extern Lisp_Object lognot(Lisp_Object a);
extern Lisp_Object macroexpand(Lisp_Object form, Lisp_Object env);
extern Lisp_Object make_one_word_bignum(int32 n);
extern Lisp_Object make_package(Lisp_Object name);
extern Lisp_Object make_string(const char *b);
extern Lisp_Object make_nstring(char *b, int32 n);
extern Lisp_Object make_undefined_symbol(char const *s);
extern Lisp_Object make_symbol(char const *s, int restartp,
                               one_args *f1, two_args *f2, n_args *fn);
extern void MS_CDECL  stdout_printf(char *fmt, ...);
extern void MS_CDECL  term_printf(char *fmt, ...);
extern void MS_CDECL  err_printf(char *fmt, ...);
extern void MS_CDECL  debug_printf(char *fmt, ...);
extern void MS_CDECL  trace_printf(char *fmt, ...);
extern char        *my_getenv(char *name);
extern Lisp_Object ncons(Lisp_Object a);
extern Lisp_Object ndelete(Lisp_Object a, Lisp_Object b);
extern Lisp_Object negate(Lisp_Object a);
extern Lisp_Object nreverse(Lisp_Object a);
extern FILE        *open_file(char *filename, char *original_name,
                              size_t n, char *dirn, FILE *old_file);
extern Lisp_Object plus2(Lisp_Object a, Lisp_Object b);
extern void        preserve(char *msg);
extern void        preserve_native_code(void);
extern void        relocate_native_function(unsigned char *bps);
extern Lisp_Object prin(Lisp_Object u);
extern char *get_string_data(Lisp_Object a, char *why, int32 *len);
extern void prin_to_stdout(Lisp_Object u);
extern void prin_to_terminal(Lisp_Object u);
extern void prin_to_debug(Lisp_Object u);
extern void prin_to_query(Lisp_Object u);
extern void prin_to_trace(Lisp_Object u);
extern void prin_to_error(Lisp_Object u);
extern void loop_print_stdout(Lisp_Object o);
extern void loop_print_terminal(Lisp_Object o);
extern void loop_print_debug(Lisp_Object o);
extern void loop_print_query(Lisp_Object o);
extern void loop_print_trace(Lisp_Object o);
extern void loop_print_error(Lisp_Object o);
extern void internal_prin(Lisp_Object u, int prefix);
extern Lisp_Object princ(Lisp_Object u);
extern Lisp_Object print(Lisp_Object u);
extern Lisp_Object printc(Lisp_Object u);
extern void        print_bignum(Lisp_Object u, CSLbool blankp, int nobreak);
extern void        print_bighexoctbin(Lisp_Object u,
                       int radix, int width, CSLbool blankp, int nobreak);
extern Lisp_Object putprop(Lisp_Object a, Lisp_Object b,
                       Lisp_Object c);
extern Lisp_Object quot2(Lisp_Object a, Lisp_Object b);
extern Lisp_Object rational(Lisp_Object a);
extern void        read_eval_print(int noisy);
extern Lisp_Object reclaim(Lisp_Object value_to_return, char *why,
                           int stg_class, intxx size);
extern CSLbool do_not_kill_native_code;
extern void        set_fns(Lisp_Object sym, one_args *f1,
                                            two_args *f2, n_args *fn);
extern void        setup(int restartp, double storesize);
extern Lisp_Object simplify_string(Lisp_Object s);
extern CSLbool        stringp(Lisp_Object a);
extern Lisp_Object times2(Lisp_Object a, Lisp_Object b);
extern int32       thirty_two_bits(Lisp_Object a);
#ifdef ADDRESS_64
extern int64       sixty_four_bits(Lisp_Object a);
#endif
#if defined DEMO_MODE || defined DEMO_BUILD
extern void give_up();
#endif
#ifdef DEMO_BUILD
extern int32 demo_key1, demo_key2;
#endif
#ifdef COMMON
#define onevalue(r)   (exit_count=1, (r))
#define nvalues(r, n) (exit_count=(n), (r))
#else
#define onevalue(r)   (r)
#define nvalues(r, n) (r)
#endif
#ifdef COMMON
#define eval(a, b) Ceval(a, b)
#define voideval(a, b) Ceval(a, b)
#else
#define eval(a, b) \
    (is_cons(a) ? Ceval(a, b) : \
     is_symbol(a) ? (qvalue(a) == unset_var ? error(1, err_unset_var, a) : \
                     onevalue(qvalue(a))) : \
     onevalue(a))
#define voideval(a, b) \
    if (is_cons(a)) Ceval(a, b) 
#endif
#define equal(a, b)                                \
    ((a) == (b) ||                                 \
     (((((a) ^ (b)) & TAG_BITS) == 0) &&           \
      ((unsigned)(((a) & TAG_BITS) - 1) > 3) &&    \
      equal_fn(a, b)))
#define cl_equal(a, b)                             \
    ((a) == (b) ||                                 \
     (((((a) ^ (b)) & TAG_BITS) == 0) &&           \
      ((unsigned)(((a) & TAG_BITS) - 1) > 3) &&    \
      cl_equal_fn(a, b)))
#define eql(a, b)                                  \
    ((a) == (b) ||                                 \
     (((((a) ^ (b)) & TAG_BITS) == 0) &&           \
      ((unsigned)(((a) & TAG_BITS) - 1) > 3) &&    \
      eql_fn(a, b)))
#ifndef IMULTIPLY
extern unsigned32 Imultiply(unsigned32 *rlow, unsigned32 a,
                            unsigned32 b, unsigned32 c);
#endif
#ifndef IDIVIDE
extern unsigned32 Idivide(unsigned32 *qp, unsigned32 a,
                          unsigned32 b, unsigned32 c);
extern unsigned32 Idiv10_9(unsigned32 *qp, unsigned32 a, unsigned32 b);
#endif
#define argcheck(var, n, msg) if ((var)!=(n)) return aerror(msg);
extern n_args   *zero_arg_functions[];
extern one_args *one_arg_functions[];
extern two_args *two_arg_functions[];
extern n_args   *three_arg_functions[];
extern void     *useful_functions[];
extern char     *address_of_var(int n);
typedef struct setup_type
{
    char *name;
    one_args *one;
    two_args *two;
    n_args *n;
} setup_type;
typedef struct setup_type_1
{
    char *name;
    one_args *one;
    two_args *two;
    n_args *n;
    unsigned32 c1;
    unsigned32 c2;
} setup_type_1;
extern setup_type const
       arith06_setup[], arith08_setup[], arith10_setup[], arith12_setup[],
       char_setup[], eval1_setup[], eval2_setup[], eval3_setup[],
       funcs1_setup[], funcs2_setup[], funcs3_setup[], print_setup[],
       read_setup[], mpi_setup[];
extern setup_type const
       u01_setup[], u02_setup[], u03_setup[], u04_setup[],
       u05_setup[], u06_setup[], u07_setup[], u08_setup[],
       u09_setup[], u10_setup[], u11_setup[], u12_setup[];
#ifdef NAG
extern setup_type const nag_setup[], asp_setup[];
extern setup_type const socket_setup[], xdr_setup[], grep_setup[];
extern setup_type const gr_setup[], axfns_setup[];
#endif
#ifdef OPENMATH
extern setup_type const om_setup[];
extern setup_type const om_parse_setup[];
#endif
extern char *find_image_directory(int argc, char *argv[]);
extern char program_name[64];
extern Lisp_Object declare_fn(Lisp_Object args, Lisp_Object env);
extern Lisp_Object function_fn(Lisp_Object args, Lisp_Object env);
extern Lisp_Object let_fn_1(Lisp_Object bvl, Lisp_Object body,
                            Lisp_Object env, int compilerp);
extern Lisp_Object mv_call_fn(Lisp_Object args, Lisp_Object env);
extern Lisp_Object progn_fn(Lisp_Object args, Lisp_Object env);
extern Lisp_Object quote_fn(Lisp_Object args, Lisp_Object env);
extern Lisp_Object tagbody_fn(Lisp_Object args, Lisp_Object env);
extern CSLbool symbol_protect_flag, warn_about_protected_symbols;
#ifdef JIT
extern char *Jcompile(Lisp_Object def, Lisp_Object env);
extern unsigned long jit_size;
#define JIT_INIT_SIZE 8192
#endif
#ifdef __cplusplus
}
#endif
#endif 
#ifndef header_arith_h
#define header_arith_h 1
#define TWO_32    4294967296.0      
#define TWO_31    2147483648.0      
#define TWO_24    16777216.0        
#define TWO_22    4194304.0         
#define TWO_21    2097152.0         
#define TWO_20    1048576.0         
#define M2_31_1   -2147483649.0     
#define _pi       3.14159265358979323846
#define _half_pi  1.57079632679489661923
#define boole_clr   0
#define boole_and   1
#define boole_andc2 2
#define boole_1     3
#define boole_andc1 4
#define boole_2     5
#define boole_xor   6
#define boole_ior   7
#define boole_nor   8
#define boole_eqv   9
#define boole_c2    10
#define boole_orc2  11
#define boole_c1    12
#define boole_orc1  13
#define boole_nand  14
#define boole_set   15
#define top_bit_set(n)     (((int32)(n)) < 0)
#define top_bit(n)         (((unsigned32)(n)) >> 31)
#define set_top_bit(n)     ((n) | (unsigned32)0x80000000)
#define clear_top_bit(n)   ((n) & 0x7fffffff)
#define signed_overflow(n) top_bit_set((n) ^ (((int32)(n))<<1))
#ifdef MULDIV64
#define IMULTIPLY 1      
#define Dmultiply(hi, lo, a, b, c)                          \
 do { unsigned64 r64 = (unsigned64)(a) * (unsigned64)(b) +  \
                     (unsigned32)(c);                       \
      (lo) = 0x7fffffffu & (unsigned32)r64;                 \
      (hi) = (unsigned32)(r64 >> 31); } while (0)
#define IDIVIDE   1
#define Ddivide(r, q, a, b, c)                                      \
 do { unsigned64 r64 = (((unsigned64)(a)) << 31) | (unsigned64)(b); \
      unsigned64 c64 = (unsigned64)(unsigned32)(c);                 \
      q = (unsigned32)(r64 / c64);                                  \
      r = (unsigned32)(r64 % c64); } while (0)
#define Ddiv10_9(r, q, a, b) Ddivide(r, q, a, b, 1000000000u)
#else
#define Dmultiply(hi, lo, a, b, c) ((hi) = Imultiply(&(lo), (a), (b), (c)))
#define Ddivide(r, q, a, b, c) ((r) = Idivide(&(q), (a), (b), (c)))
#define Ddiv10_9(r, q, a, b)   ((r) = Idiv10_9(&(q), (a), (b)))
#endif
#define fix_mask (-0x08000000)
#define fixnum_minusp(a) ((int32)(a) < 0)
#define bignum_minusp(a) \
    ((int32)bignum_digits(a)[((bignum_length(a)-CELL)/4)-1]<0)
extern Lisp_Object negateb(Lisp_Object);
extern Lisp_Object copyb(Lisp_Object);
extern Lisp_Object negate(Lisp_Object);
extern Lisp_Object plus2(Lisp_Object a, Lisp_Object b);
extern Lisp_Object difference2(Lisp_Object a, Lisp_Object b);
extern Lisp_Object times2(Lisp_Object a, Lisp_Object b);
extern Lisp_Object quot2(Lisp_Object a, Lisp_Object b);
extern Lisp_Object CLquot2(Lisp_Object a, Lisp_Object b);
extern Lisp_Object quotbn(Lisp_Object a, int32 n);
extern Lisp_Object quotbn1(Lisp_Object a, int32 n);
extern Lisp_Object quotbb(Lisp_Object a, Lisp_Object b);
extern Lisp_Object Cremainder(Lisp_Object a, Lisp_Object b);
extern Lisp_Object rembi(Lisp_Object a, Lisp_Object b);
extern Lisp_Object rembb(Lisp_Object a, Lisp_Object b);
extern Lisp_Object shrink_bignum(Lisp_Object a, int32 lena);
extern Lisp_Object modulus(Lisp_Object a, Lisp_Object b);
extern Lisp_Object rational(Lisp_Object a);
extern Lisp_Object rationalize(Lisp_Object a);
extern Lisp_Object lcm(Lisp_Object a, Lisp_Object b);
extern Lisp_Object lengthen_by_one_bit(Lisp_Object a, int32 msd);
extern CSLbool numeq2(Lisp_Object a, Lisp_Object b);
extern CSLbool zerop(Lisp_Object a);
extern CSLbool onep(Lisp_Object a);
extern CSLbool minusp(Lisp_Object a);
extern CSLbool plusp(Lisp_Object a);
extern CSLbool lesspbd(Lisp_Object a, double b);
extern CSLbool lessprd(Lisp_Object a, double b);
extern CSLbool lesspdb(double a, Lisp_Object b);
extern CSLbool lesspdr(double a, Lisp_Object b);
extern Lisp_Object make_one_word_bignum(int32 n);
extern Lisp_Object make_two_word_bignum(int32 a, unsigned32 b);
extern Lisp_Object make_n_word_bignum(int32 a1, unsigned32 a2,
                                      unsigned32 a3, int32 n);
extern Lisp_Object make_sfloat(double d);
extern double float_of_integer(Lisp_Object a);
extern Lisp_Object add1(Lisp_Object p);
extern Lisp_Object sub1(Lisp_Object p);
extern Lisp_Object integerp(Lisp_Object p);
extern double float_of_number(Lisp_Object a);
extern Lisp_Object make_boxfloat(double a, int32 type);
extern Lisp_Object make_complex(Lisp_Object r, Lisp_Object i);
extern Lisp_Object make_ratio(Lisp_Object p, Lisp_Object q);
extern Lisp_Object ash(Lisp_Object a, Lisp_Object b);
extern Lisp_Object lognot(Lisp_Object a);
extern Lisp_Object logior2(Lisp_Object a, Lisp_Object b);
extern Lisp_Object logxor2(Lisp_Object a, Lisp_Object b);
extern Lisp_Object logand2(Lisp_Object a, Lisp_Object b);
extern Lisp_Object logeqv2(Lisp_Object a, Lisp_Object b);
extern Lisp_Object rationalf(double d);
extern int _reduced_exp(double, double *);
extern CSLbool lesspbi(Lisp_Object a, Lisp_Object b);
extern CSLbool lesspib(Lisp_Object a, Lisp_Object b);
#ifdef COMMON
typedef struct Complex
{
    double real;
    double imag;
} Complex;
extern Complex MS_CDECL Cln(Complex a);
extern Complex MS_CDECL Ccos(Complex a);
extern Complex MS_CDECL Cexp(Complex a);
extern Complex MS_CDECL Cpow(Complex a, Complex b);
extern double MS_CDECL Cabs(Complex a);
#endif
#endif 
#ifndef header_entries_h
#define header_entries_h 1
#ifdef __cplusplus
extern "C" {
#endif
extern Lisp_Object MS_CDECL Lbatchp(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL bytecounts(Lisp_Object nil, int nargs, ...);
extern Lisp_Object MS_CDECL Ldate(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Ldatestamp(Lisp_Object nil, int nargs, ...);
extern Lisp_Object MS_CDECL Leject(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lerror(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lerror0(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lflush(Lisp_Object nil, int nargs, ...);
extern Lisp_Object MS_CDECL Lgc0(Lisp_Object nil, int nargs, ...);
extern Lisp_Object MS_CDECL Lgctime(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lgensym(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Llist_modules(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Llibrary_members0(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Llposn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lmapstore0(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lnext_random(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lposn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lread(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lreadch(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lrtell(Lisp_Object nil, int nargs, ...);
extern Lisp_Object MS_CDECL Lterpri(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Ltime(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Ltmpnam(Lisp_Object nil, int nargs, ...);
extern Lisp_Object MS_CDECL Ltyi(Lisp_Object env, int nargs, ...);
extern Lisp_Object autoload1(Lisp_Object env, Lisp_Object a1);
extern Lisp_Object bytecoded1(Lisp_Object env, Lisp_Object a);
extern Lisp_Object byteopt1(Lisp_Object def, Lisp_Object a);
extern Lisp_Object byteoptrest1(Lisp_Object def, Lisp_Object a);
extern Lisp_Object double_bytecoded1(Lisp_Object env, Lisp_Object a);
extern Lisp_Object double_byteopt1(Lisp_Object def, Lisp_Object a);
extern Lisp_Object double_byteoptrest1(Lisp_Object def, Lisp_Object a);
extern Lisp_Object double_funarged1(Lisp_Object env, Lisp_Object a1);
extern Lisp_Object double_hardopt1(Lisp_Object def, Lisp_Object a);
extern Lisp_Object double_hardoptrest1(Lisp_Object def, Lisp_Object a);
extern Lisp_Object double_interpreted1(Lisp_Object env, Lisp_Object a1);
extern Lisp_Object funarged1(Lisp_Object env, Lisp_Object a1);
extern Lisp_Object tracefunarged1(Lisp_Object env, Lisp_Object a1);
extern Lisp_Object hardopt1(Lisp_Object def, Lisp_Object a);
extern Lisp_Object hardoptrest1(Lisp_Object def, Lisp_Object a);
extern Lisp_Object interpreted1(Lisp_Object env, Lisp_Object a1);
extern Lisp_Object tracebytecoded1(Lisp_Object env, Lisp_Object a);
extern Lisp_Object jitcompileme1(Lisp_Object env, Lisp_Object a);
extern Lisp_Object tracebyteopt1(Lisp_Object def, Lisp_Object a);
extern Lisp_Object tracebyteoptrest1(Lisp_Object def, Lisp_Object a);
extern Lisp_Object tracebytecoded1(Lisp_Object env, Lisp_Object a);
extern Lisp_Object traceinterpreted1(Lisp_Object env, Lisp_Object a1);
extern Lisp_Object tracehardopt1(Lisp_Object def, Lisp_Object a);
extern Lisp_Object tracehardoptrest1(Lisp_Object def, Lisp_Object a);
extern Lisp_Object undefined1(Lisp_Object env, Lisp_Object a1);
extern Lisp_Object f1_as_0(Lisp_Object env, Lisp_Object a);
extern Lisp_Object f1_as_1(Lisp_Object env, Lisp_Object a);
#ifdef CJAVA
extern Lisp_Object java1(Lisp_Object env, Lisp_Object a);
#endif
extern Lisp_Object Labsval(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Ladd1(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lalpha_char_p(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lapply0(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lapply_1(Lisp_Object env, Lisp_Object fn);
extern Lisp_Object Latan(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Latom(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lbanner(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lboundp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lbpsp(Lisp_Object nil, Lisp_Object a);
extern Lisp_Object Lbpsupbv(Lisp_Object nil, Lisp_Object v);
extern Lisp_Object Lcaaaar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcaaadr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcaaar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcaadar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcaaddr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcaadr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcaar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcaar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcadaar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcadadr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcadar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcaddar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcadddr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcaddr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcadr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcadr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcdaaar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcdaadr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcdaar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcdadar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcdaddr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcdadr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcdar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcdar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcddaar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcddadr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcddar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcdddar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcddddr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcdddr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcddr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcddr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcdr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcdr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lchar_code(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lclose(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcodep(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcompress(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lconsp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lconstantp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcopy_module(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Ldefine_in_module(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Ldelete_module(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Ldigitp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lendp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lerror1(Lisp_Object nil, Lisp_Object a1);
extern Lisp_Object Lerrorset1(Lisp_Object nil, Lisp_Object form);
extern Lisp_Object Leval(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Levenp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Levlis(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lexplode(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lexplode2lc(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lexplode2lcn(Lisp_Object nil, Lisp_Object a);
extern Lisp_Object Lexplode2n(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lexplodec(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lexplodecn(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lexplodehex(Lisp_Object nil, Lisp_Object a);
extern Lisp_Object Lexploden(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lexplodeoctal(Lisp_Object nil, Lisp_Object a);
extern Lisp_Object Lfixp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lfloat(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lfloatp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lfrexp(Lisp_Object nil, Lisp_Object a);
extern Lisp_Object Lfuncall1(Lisp_Object env, Lisp_Object fn);
extern Lisp_Object Lgc(Lisp_Object nil, Lisp_Object a);
extern Lisp_Object Lgensym1(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lgensym2(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lgetd(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lgetenv(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lget_bps(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lhelp(Lisp_Object nil, Lisp_Object a);
extern Lisp_Object Liadd1(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lidentity(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Liminus(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Liminusp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lindirect(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lintegerp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lintern(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lionep(Lisp_Object nil, Lisp_Object a);
extern Lisp_Object Lisub1(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lizerop(Lisp_Object nil, Lisp_Object a);
extern Lisp_Object Llength(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Llengthc(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Llibrary_members(Lisp_Object nil, Lisp_Object a);
extern Lisp_Object Llinelength(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Llist_to_string(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Llist_to_vector(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lload_module(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lload_source(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Llognot(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Llog_1(Lisp_Object nil, Lisp_Object a);
extern Lisp_Object Llsd(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lmacroexpand(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lmacroexpand_1(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lmacro_function(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lmake_global(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lmake_special(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lmapstore(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lmd5(Lisp_Object env, Lisp_Object a1);
extern Lisp_Object Lmd60(Lisp_Object env, Lisp_Object a1);
extern Lisp_Object Lminus(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lminusp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lmkevect(Lisp_Object nil, Lisp_Object n);
extern Lisp_Object Lmkquote(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lmkvect(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lmodular_minus(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lmodular_number(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lmodular_reciprocal(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lmodule_exists(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lmsd(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lmv_list(Lisp_Object nil, Lisp_Object a);
extern Lisp_Object Lncons(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lnreverse(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lnull(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lnumberp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Loddp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lonep(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lpagelength(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lplist(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lplusp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lprin(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lprin(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lprin2a(Lisp_Object nil, Lisp_Object a);
extern Lisp_Object Lprinc(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lprinc(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lprint(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lprintc(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lrandom(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lrational(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lrdf1(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lrds(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lremd(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lreverse(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lsetpchar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lset_small_modulus(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lsmkvect(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lspecial_char(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lspecial_form_p(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lspool(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lstart_module(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lstop(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lstringp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lsub1(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lsymbolp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lsymbol_argcount(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lsymbol_argcode(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lsymbol_env(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lsymbol_function(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lsymbol_globalp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lsymbol_name(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lsymbol_restore_fns(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lsymbol_specialp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lsymbol_value(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lsystem(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lthreevectorp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Ltrace(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Ltruncate(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lttab(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Ltyo(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lunintern(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lunmake_global(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lunmake_special(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Luntrace(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lupbv(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lsimple_vectorp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lvectorp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lverbos(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lwhitespace_char_p(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lwritable_libraryp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lwrite_module(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lwrs(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lxtab(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lxtab(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lzerop(Lisp_Object env, Lisp_Object a);
#ifdef COMMON
extern Lisp_Object Lfind_symbol_1(Lisp_Object nil, Lisp_Object str);
extern Lisp_Object Llistp(Lisp_Object env, Lisp_Object a);
#endif
extern Lisp_Object autoload2(Lisp_Object env, Lisp_Object a1, Lisp_Object a2);
extern Lisp_Object bytecoded2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object byteopt2(Lisp_Object def, Lisp_Object a, Lisp_Object b);
extern Lisp_Object byteoptrest2(Lisp_Object def, Lisp_Object a, Lisp_Object b);
extern Lisp_Object double_bytecoded2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object double_byteopt2(Lisp_Object def, Lisp_Object a, Lisp_Object b);
extern Lisp_Object double_byteoptrest2(Lisp_Object def, Lisp_Object a, Lisp_Object b);
extern Lisp_Object double_funarged2(Lisp_Object env, Lisp_Object a1, Lisp_Object a2);
extern Lisp_Object double_hardopt2(Lisp_Object def, Lisp_Object a, Lisp_Object b);
extern Lisp_Object double_hardoptrest2(Lisp_Object def, Lisp_Object a, Lisp_Object b);
extern Lisp_Object double_interpreted2(Lisp_Object env, Lisp_Object a1, Lisp_Object a2);
extern Lisp_Object funarged2(Lisp_Object env, Lisp_Object a1, Lisp_Object a2);
extern Lisp_Object tracefunarged2(Lisp_Object env, Lisp_Object a1, Lisp_Object a2);
extern Lisp_Object hardopt2(Lisp_Object def, Lisp_Object a, Lisp_Object b);
extern Lisp_Object hardoptrest2(Lisp_Object def, Lisp_Object a, Lisp_Object b);
extern Lisp_Object interpreted2(Lisp_Object env, Lisp_Object a1, Lisp_Object a2);
extern Lisp_Object tracebyteopt2(Lisp_Object def, Lisp_Object a, Lisp_Object b);
extern Lisp_Object tracebyteoptrest2(Lisp_Object def, Lisp_Object a, Lisp_Object b);
extern Lisp_Object tracebytecoded2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object jitcompileme2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object traceinterpreted2(Lisp_Object env, Lisp_Object a1, Lisp_Object a2);
extern Lisp_Object tracehardopt2(Lisp_Object def, Lisp_Object a, Lisp_Object b);
extern Lisp_Object tracehardoptrest2(Lisp_Object def, Lisp_Object a, Lisp_Object b);
extern Lisp_Object undefined2(Lisp_Object env, Lisp_Object a1, Lisp_Object a2);
extern Lisp_Object f2_as_0(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object f2_as_1(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object f2_as_2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
#ifdef CJAVA
extern Lisp_Object java2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
#endif
extern Lisp_Object Lappend(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lapply_2(Lisp_Object env, Lisp_Object fn, Lisp_Object a1);
extern Lisp_Object Lapply1(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lash(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lash1(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lassoc(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Latan2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Latan2d(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Latsoc(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lbpsgetv(Lisp_Object nil, Lisp_Object v, Lisp_Object n);
extern Lisp_Object Lcons(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lcopy_native(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Ldeleq(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Ldelete(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Ldifference2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Ldivide(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lelt(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Leq(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Leqcar(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lequalcar(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Leql(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Leqn(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lcl_equal(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lequal(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lerror2(Lisp_Object nil, Lisp_Object a1, Lisp_Object a2);
extern Lisp_Object Lerrorset2(Lisp_Object nil, Lisp_Object form, Lisp_Object ffg1);
extern Lisp_Object Lexpt(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lflag(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lflagp(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lflagpcar(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lfuncall2(Lisp_Object env, Lisp_Object fn, Lisp_Object a1);
extern Lisp_Object Lgcd(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lgeq(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lget(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lget_hash_2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lgetv(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lgreaterp(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lhelp_2(Lisp_Object nil, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lidifference(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Ligeq(Lisp_Object nil, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Ligreaterp(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lileq(Lisp_Object nil, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lilessp(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Limax(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Limin(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Linorm(Lisp_Object nil, Lisp_Object a, Lisp_Object k);
extern Lisp_Object Linstate_c_code(Lisp_Object nil, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lintersect(Lisp_Object nil, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Liplus2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Liquotient(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Liremainder(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lirightshift(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Litimes2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Llcm(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lleq(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Llessp(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Llist2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Llog(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Llog_2(Lisp_Object nil, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lmake_random_state(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lmake_random_state(Lisp_Object nil, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lmax2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lmember(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lmemq(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lmin2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lmod(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lmodular_difference(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lmodular_expt(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lmodular_plus(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lmodular_quotient(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lmodular_times(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lnconc(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lneq(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lnreverse2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lorderp(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lpair(Lisp_Object nil, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lplus2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lquotient(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lrem(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lremflag(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lremprop(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lrplaca(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lrplacd(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lrseek(Lisp_Object nil, Lisp_Object a);
extern Lisp_Object Lset(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lset_help_file(Lisp_Object nil, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lsgetv(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lsmemq(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lsubla(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lsublis(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lsymbol_protect(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lsymbol_set_definition(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lsymbol_set_env(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Ltimes2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lunion(Lisp_Object nil, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lwrite_help_module(Lisp_Object nil, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lxcons(Lisp_Object env, Lisp_Object a, Lisp_Object b);
#ifdef COMMON
extern Lisp_Object Laref2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Latan_2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lelt(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lfloat_2(Lisp_Object nil, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lintern_2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lmacroexpand_1_2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lmacroexpand_2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lrandom_2(Lisp_Object nil, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Ltruncate_2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lunintern_2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
#endif
extern Lisp_Object MS_CDECL autoloadn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL bytecoded0(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL bytecoded3(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL bytecodedn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL byteoptn(Lisp_Object def, int nargs, ...);
extern Lisp_Object MS_CDECL byteoptrestn(Lisp_Object def, int nargs, ...);
extern Lisp_Object MS_CDECL double_bytecoded0(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL double_bytecoded3(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL double_bytecodedn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL double_byteoptn(Lisp_Object def, int nargs, ...);
extern Lisp_Object MS_CDECL double_byteoptrestn(Lisp_Object def, int nargs, ...);
extern Lisp_Object MS_CDECL double_funargedn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL double_hardoptn(Lisp_Object def, int nargs, ...);
extern Lisp_Object MS_CDECL double_hardoptrestn(Lisp_Object def, int nargs, ...);
extern Lisp_Object MS_CDECL double_interpretedn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL funargedn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL tracefunargedn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL hardoptn(Lisp_Object def, int nargs, ...);
extern Lisp_Object MS_CDECL hardoptrestn(Lisp_Object def, int nargs, ...);
extern Lisp_Object MS_CDECL interpretedn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL tracebyteoptn(Lisp_Object def, int nargs, ...);
extern Lisp_Object MS_CDECL tracebyteoptrestn(Lisp_Object def, int nargs, ...);
extern Lisp_Object MS_CDECL tracebytecoded0(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL tracebytecoded3(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL tracebytecodedn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL jitcompileme0(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL jitcompileme3(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL jitcompilemen(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL traceinterpretedn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL tracehardoptn(Lisp_Object def, int nargs, ...);
extern Lisp_Object MS_CDECL tracehardoptrestn(Lisp_Object def, int nargs, ...);
extern Lisp_Object MS_CDECL undefinedn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL f0_as_0(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL f3_as_0(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL f3_as_1(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL f3_as_2(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL f3_as_3(Lisp_Object env, int nargs, ...);
#ifdef CJAVA
extern Lisp_Object MS_CDECL java0(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL java3(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL javan(Lisp_Object env, int nargs, ...);
#endif
extern Lisp_Object MS_CDECL Lacons(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lapply_n(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lapply2(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lapply3(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lbpsputv(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lerrorset3(Lisp_Object nil, int nargs, ...);
extern Lisp_Object MS_CDECL Lerrorsetn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lfuncalln(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lhelp_n(Lisp_Object nil, int nargs, ...);
extern Lisp_Object MS_CDECL Llist(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Llist2star(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Llist3(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Llogand(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Llogeqv(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Llogor(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Llogxor(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lmax(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lmin(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lmkhash(Lisp_Object nil, int nargs, ...);
extern Lisp_Object MS_CDECL Lput_hash(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lputprop(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lputv(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lsputv(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lsubst(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lvalues(Lisp_Object env, int nargs, ...);
#ifdef COMMON
extern Lisp_Object MS_CDECL Lappend_n(Lisp_Object nil, int nargs, ...);
extern Lisp_Object MS_CDECL Laref(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Laset(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Leqn_n(Lisp_Object nil, int nargs, ...);
extern Lisp_Object MS_CDECL Lgcd_n(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lgeq_n(Lisp_Object nil, int nargs, ...);
extern Lisp_Object MS_CDECL Lget_3(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lgreaterp_n(Lisp_Object nil, int nargs, ...);
extern Lisp_Object MS_CDECL Llcm_n(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lleq_n(Lisp_Object nil, int nargs, ...);
extern Lisp_Object MS_CDECL Llessp_n(Lisp_Object nil, int nargs, ...);
extern Lisp_Object MS_CDECL Lquotient_n(Lisp_Object nil, int nargs, ...);
#endif
#ifdef OPENMATH
extern Lisp_Object MS_CDECL om_openFileDev(Lisp_Object env, int nargs, ...);
extern Lisp_Object om_openStringDev(Lisp_Object nil, Lisp_Object lstr, Lisp_Object lenc);
extern Lisp_Object om_closeDev(Lisp_Object env, Lisp_Object dev);
extern Lisp_Object om_setDevEncoding(Lisp_Object nil, Lisp_Object ldev, Lisp_Object lenc);
extern Lisp_Object om_makeConn(Lisp_Object nil, Lisp_Object ltimeout);
extern Lisp_Object om_closeConn(Lisp_Object nil, Lisp_Object lconn);
extern Lisp_Object om_getConnInDevice(Lisp_Object nil, Lisp_Object lconn);
extern Lisp_Object om_getConnOutDevice(Lisp_Object nil, Lisp_Object lconn);
extern Lisp_Object MS_CDECL om_connectTCP(Lisp_Object nil, int nargs, ...);
extern Lisp_Object om_bindTCP(Lisp_Object nil, Lisp_Object lconn, Lisp_Object lport);
extern Lisp_Object om_putApp(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putEndApp(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putAtp(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putEndAtp(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putAttr(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putEndAttr(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putBind(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putEndBind(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putBVar(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putEndBVar(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putError(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putEndError(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putObject(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putEndObject(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putInt(Lisp_Object nil, Lisp_Object ldev, Lisp_Object val);
extern Lisp_Object om_putFloat(Lisp_Object nil, Lisp_Object ldev, Lisp_Object val);
extern Lisp_Object om_putByteArray(Lisp_Object nil, Lisp_Object ldev, Lisp_Object val);
extern Lisp_Object om_putVar(Lisp_Object nil, Lisp_Object ldev, Lisp_Object val);
extern Lisp_Object om_putString(Lisp_Object nil, Lisp_Object ldev, Lisp_Object val);
extern Lisp_Object om_putSymbol(Lisp_Object nil, Lisp_Object ldev, Lisp_Object val);
extern Lisp_Object MS_CDECL om_putSymbol2(Lisp_Object nil, int nargs, ...);
extern Lisp_Object om_getApp(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getEndApp(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getAtp(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getEndAtp(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getAttr(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getEndAttr(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getBind(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getEndBind(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getBVar(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getEndBVar(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getError(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getEndError(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getObject(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getEndObject(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getInt(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getFloat(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getByteArray(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getVar(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getString(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getSymbol(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getType(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_stringToStringPtr(Lisp_Object nil, Lisp_Object lstr);
extern Lisp_Object om_stringPtrToString(Lisp_Object nil, Lisp_Object lpstr);
extern Lisp_Object om_read(Lisp_Object nil, Lisp_Object dev);
extern Lisp_Object om_supportsCD(Lisp_Object nil, Lisp_Object lcd);
extern Lisp_Object om_supportsSymbol(Lisp_Object nil, Lisp_Object lcd, Lisp_Object lsym);
extern Lisp_Object MS_CDECL om_listCDs(Lisp_Object nil, int nargs, ...);
extern Lisp_Object om_listSymbols(Lisp_Object nil, Lisp_Object lcd);
extern Lisp_Object om_whichCDs(Lisp_Object nil, Lisp_Object lsym);
#endif
#ifdef __cplusplus
}
#endif
#endif 


/* Code for pv_applp */

static Lisp_Object CC_pv_applp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v55, v65;
    Lisp_Object fn;
    if (stack >= stacklimit)
    {
        push2(v16,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v16);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-4] = v16;
    v55 = v0;
/* end of prologue */
    stack[-5] = v55;
    v55 = stack[-5];
    if (v55 == nil) goto v2;
    v55 = stack[-5];
    v55 = qcar(v55);
    v65 = v55;
    v55 = v65;
    stack[0] = qcar(v55);
    v55 = v65;
    v65 = qcdr(v55);
    v55 = stack[-4];
    fn = elt(env, 1); /* pappl0 */
    v55 = (*qfn2(fn))(qenv(fn), v65, v55);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-6];
    v55 = cons(stack[0], v55);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-6];
    v55 = ncons(v55);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-6];
    stack[-2] = v55;
    stack[-3] = v55;
    goto v6;

v6:
    v55 = stack[-5];
    v55 = qcdr(v55);
    stack[-5] = v55;
    v55 = stack[-5];
    if (v55 == nil) goto v36;
    stack[-1] = stack[-2];
    v55 = stack[-5];
    v55 = qcar(v55);
    v65 = v55;
    v55 = v65;
    stack[0] = qcar(v55);
    v55 = v65;
    v65 = qcdr(v55);
    v55 = stack[-4];
    fn = elt(env, 1); /* pappl0 */
    v55 = (*qfn2(fn))(qenv(fn), v65, v55);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-6];
    v55 = cons(stack[0], v55);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-6];
    v55 = ncons(v55);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-6];
    v55 = Lrplacd(nil, stack[-1], v55);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-6];
    v55 = stack[-2];
    v55 = qcdr(v55);
    stack[-2] = v55;
    goto v6;

v36:
    v55 = stack[-3];
    goto v5;

v5:
    {
        popv(7);
        fn = elt(env, 2); /* pv_sort */
        return (*qfn1(fn))(qenv(fn), v55);
    }

v2:
    v55 = nil;
    goto v5;
/* error exit handlers */
v106:
    popv(7);
    return nil;
}



/* Code for rntimes!: */

static Lisp_Object CC_rntimesT(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v30, v99;
    Lisp_Object fn;
    if (stack >= stacklimit)
    {
        push2(v16,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v16);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v16;
    stack[-1] = v0;
/* end of prologue */
    v30 = stack[-1];
    v30 = qcdr(v30);
    v99 = qcar(v30);
    v30 = stack[0];
    v30 = qcdr(v30);
    v30 = qcar(v30);
    stack[-2] = times2(v99, v30);
    nil = C_nil;
    if (exception_pending()) goto v46;
    env = stack[-3];
    v30 = stack[-1];
    v30 = qcdr(v30);
    v99 = qcdr(v30);
    v30 = stack[0];
    v30 = qcdr(v30);
    v30 = qcdr(v30);
    v30 = times2(v99, v30);
    nil = C_nil;
    if (exception_pending()) goto v46;
    env = stack[-3];
    {
        Lisp_Object v31 = stack[-2];
        popv(4);
        fn = elt(env, 1); /* mkrn */
        return (*qfn2(fn))(qenv(fn), v31, v30);
    }
/* error exit handlers */
v46:
    popv(4);
    return nil;
}



/* Code for !*modular2f */

static Lisp_Object CC_Hmodular2f(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v142, v236;
    if (stack >= stacklimit)
    {
        push(v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0;
/* end of prologue */

v6:
    v236 = stack[0];
    v142 = (Lisp_Object)1; /* 0 */
    if (v236 == v142) goto v45;
    v142 = qvalue(elt(env, 1)); /* !*balanced_mod */
    if (v142 == nil) goto v234;
    v236 = stack[0];
    v142 = stack[0];
    v236 = plus2(v236, v142);
    nil = C_nil;
    if (exception_pending()) goto v84;
    env = stack[-2];
    v142 = qvalue(elt(env, 2)); /* current!-modulus */
    v142 = (Lisp_Object)greaterp2(v236, v142);
    nil = C_nil;
    if (exception_pending()) goto v84;
    v142 = v142 ? lisp_true : nil;
    env = stack[-2];
    if (v142 == nil) goto v67;
    stack[-1] = elt(env, 3); /* !:mod!: */
    v236 = stack[0];
    v142 = qvalue(elt(env, 2)); /* current!-modulus */
    v142 = difference2(v236, v142);
    nil = C_nil;
    if (exception_pending()) goto v84;
    {
        Lisp_Object v237 = stack[-1];
        popv(3);
        return cons(v237, v142);
    }

v67:
    v236 = stack[0];
    v142 = stack[0];
    stack[-1] = plus2(v236, v142);
    nil = C_nil;
    if (exception_pending()) goto v84;
    env = stack[-2];
    v142 = qvalue(elt(env, 2)); /* current!-modulus */
    v142 = negate(v142);
    nil = C_nil;
    if (exception_pending()) goto v84;
    env = stack[-2];
    v142 = (Lisp_Object)lesseq2(stack[-1], v142);
    nil = C_nil;
    if (exception_pending()) goto v84;
    v142 = v142 ? lisp_true : nil;
    env = stack[-2];
    if (v142 == nil) goto v220;
    v236 = stack[0];
    v142 = qvalue(elt(env, 2)); /* current!-modulus */
    v142 = plus2(v236, v142);
    nil = C_nil;
    if (exception_pending()) goto v84;
    env = stack[-2];
    stack[0] = v142;
    goto v6;

v220:
    v236 = elt(env, 3); /* !:mod!: */
    v142 = stack[0];
    popv(3);
    return cons(v236, v142);

v234:
    v236 = elt(env, 3); /* !:mod!: */
    v142 = stack[0];
    popv(3);
    return cons(v236, v142);

v45:
    v142 = nil;
    { popv(3); return onevalue(v142); }
/* error exit handlers */
v84:
    popv(3);
    return nil;
}



/* Code for divide!: */

static Lisp_Object MS_CDECL CC_divideT(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v16,
                         Lisp_Object v63, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v87, v66;
    Lisp_Object fn;
    argcheck(nargs, 3, "divide:");
    if (stack >= stacklimit)
    {
        push3(v63,v16,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v16,v63);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v63;
    stack[-2] = v16;
    stack[-3] = v0;
/* end of prologue */
    stack[0] = stack[-1];
    v87 = stack[-2];
    v87 = qcdr(v87);
    v87 = qcar(v87);
    v87 = Labsval(nil, v87);
    nil = C_nil;
    if (exception_pending()) goto v122;
    env = stack[-5];
    fn = elt(env, 2); /* msd */
    v87 = (*qfn1(fn))(qenv(fn), v87);
    nil = C_nil;
    if (exception_pending()) goto v122;
    env = stack[-5];
    v87 = add1(v87);
    nil = C_nil;
    if (exception_pending()) goto v122;
    env = stack[-5];
    v87 = plus2(stack[0], v87);
    nil = C_nil;
    if (exception_pending()) goto v122;
    env = stack[-5];
    fn = elt(env, 3); /* conv!:mt */
    v87 = (*qfn2(fn))(qenv(fn), stack[-3], v87);
    nil = C_nil;
    if (exception_pending()) goto v122;
    env = stack[-5];
    stack[-3] = v87;
    stack[-4] = elt(env, 1); /* !:rd!: */
    v87 = stack[-3];
    v87 = qcdr(v87);
    v66 = qcar(v87);
    v87 = stack[-2];
    v87 = qcdr(v87);
    v87 = qcar(v87);
    stack[0] = quot2(v66, v87);
    nil = C_nil;
    if (exception_pending()) goto v122;
    env = stack[-5];
    v87 = stack[-3];
    v87 = qcdr(v87);
    v66 = qcdr(v87);
    v87 = stack[-2];
    v87 = qcdr(v87);
    v87 = qcdr(v87);
    v87 = difference2(v66, v87);
    nil = C_nil;
    if (exception_pending()) goto v122;
    env = stack[-5];
    v87 = list2star(stack[-4], stack[0], v87);
    nil = C_nil;
    if (exception_pending()) goto v122;
    env = stack[-5];
    stack[-3] = v87;
    v66 = stack[-3];
    v87 = stack[-1];
    {
        popv(6);
        fn = elt(env, 4); /* round!:mt */
        return (*qfn2(fn))(qenv(fn), v66, v87);
    }
/* error exit handlers */
v122:
    popv(6);
    return nil;
}



/* Code for mkwedge */

static Lisp_Object CC_mkwedge(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v25, v13, v24;
    if (stack >= stacklimit)
    {
        push(v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v25 = v0;
/* end of prologue */
    v24 = v25;
    v13 = (Lisp_Object)17; /* 1 */
    v25 = (Lisp_Object)17; /* 1 */
    v25 = list2star(v24, v13, v25);
    errexit();
    return ncons(v25);
}



/* Code for noncommutingf */

static Lisp_Object CC_noncommutingf(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v42, v49;
    Lisp_Object fn;
    if (stack >= stacklimit)
    {
        push2(v16,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v16);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v16;
    stack[-1] = v0;
/* end of prologue */

v11:
    v42 = stack[0];
    fn = elt(env, 1); /* domain!*p */
    v42 = (*qfn1(fn))(qenv(fn), v42);
    nil = C_nil;
    if (exception_pending()) goto v193;
    env = stack[-2];
    if (v42 == nil) goto v24;
    v42 = nil;
    { popv(3); return onevalue(v42); }

v24:
    v49 = stack[-1];
    v42 = stack[0];
    v42 = qcar(v42);
    v42 = qcar(v42);
    v42 = qcar(v42);
    fn = elt(env, 2); /* noncommuting */
    v42 = (*qfn2(fn))(qenv(fn), v49, v42);
    nil = C_nil;
    if (exception_pending()) goto v193;
    env = stack[-2];
    if (!(v42 == nil)) { popv(3); return onevalue(v42); }
    v49 = stack[-1];
    v42 = stack[0];
    v42 = qcar(v42);
    v42 = qcdr(v42);
    v42 = CC_noncommutingf(env, v49, v42);
    nil = C_nil;
    if (exception_pending()) goto v193;
    env = stack[-2];
    if (!(v42 == nil)) { popv(3); return onevalue(v42); }
    v49 = stack[-1];
    v42 = stack[0];
    v42 = qcdr(v42);
    stack[-1] = v49;
    stack[0] = v42;
    goto v11;
/* error exit handlers */
v193:
    popv(3);
    return nil;
}



/* Code for mo!=lexcomp */

static Lisp_Object CC_moMlexcomp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v40, v206, v41, v64;
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v206 = v16;
    v41 = v0;
/* end of prologue */

v4:
    v40 = v41;
    if (v40 == nil) goto v5;
    v40 = v206;
    if (v40 == nil) goto v38;
    v40 = v41;
    v64 = qcar(v40);
    v40 = v206;
    v40 = qcar(v40);
    if (equal(v64, v40)) goto v43;
    v40 = v41;
    v40 = qcar(v40);
    v206 = qcar(v206);
    if (((int32)(v40)) > ((int32)(v206))) goto v31;
    v40 = (Lisp_Object)-15; /* -1 */
    return onevalue(v40);

v31:
    v40 = (Lisp_Object)17; /* 1 */
    return onevalue(v40);

v43:
    v40 = v41;
    v40 = qcdr(v40);
    v41 = v40;
    v40 = v206;
    v40 = qcdr(v40);
    v206 = v40;
    goto v4;

v38:
    v40 = elt(env, 1); /* (0) */
    v206 = v40;
    goto v4;

v5:
    v40 = v206;
    if (v40 == nil) goto v2;
    v40 = elt(env, 1); /* (0) */
    v41 = v40;
    goto v4;

v2:
    v40 = (Lisp_Object)1; /* 0 */
    return onevalue(v40);
}



/* Code for insert_pv1 */

static Lisp_Object MS_CDECL CC_insert_pv1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v16,
                         Lisp_Object v63, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v112, v120;
    Lisp_Object fn;
    argcheck(nargs, 3, "insert_pv1");
    if (stack >= stacklimit)
    {
        push3(v63,v16,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v16,v63);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v63;
    stack[-1] = v16;
    stack[-2] = v0;
/* end of prologue */

v45:
    v112 = stack[-1];
    if (v112 == nil) goto v7;
    v112 = stack[-2];
    if (v112 == nil) goto v22;
    v112 = stack[-1];
    v112 = qcar(v112);
    v112 = qcar(v112);
    v120 = qcdr(v112);
    v112 = stack[-2];
    v112 = qcar(v112);
    v112 = qcdr(v112);
    v112 = (Lisp_Object)greaterp2(v120, v112);
    nil = C_nil;
    if (exception_pending()) goto v142;
    v112 = v112 ? lisp_true : nil;
    env = stack[-4];
    if (v112 == nil) goto v95;
    v112 = stack[-1];
    v112 = qcdr(v112);
    stack[-3] = v112;
    v112 = stack[-1];
    v120 = qcar(v112);
    v112 = stack[-2];
    fn = elt(env, 1); /* reduce_pv */
    v112 = (*qfn2(fn))(qenv(fn), v120, v112);
    nil = C_nil;
    if (exception_pending()) goto v142;
    env = stack[-4];
    fn = elt(env, 2); /* pv_renorm */
    v120 = (*qfn1(fn))(qenv(fn), v112);
    nil = C_nil;
    if (exception_pending()) goto v142;
    env = stack[-4];
    v112 = stack[0];
    v112 = cons(v120, v112);
    nil = C_nil;
    if (exception_pending()) goto v142;
    env = stack[-4];
    stack[0] = v112;
    v112 = stack[-3];
    stack[-1] = v112;
    goto v45;

v95:
    v112 = nil;
    stack[-3] = v112;
    v120 = stack[-2];
    v112 = stack[0];
    v112 = cons(v120, v112);
    nil = C_nil;
    if (exception_pending()) goto v142;
    env = stack[-4];
    stack[0] = v112;
    v112 = stack[-3];
    stack[-2] = v112;
    goto v45;

v22:
    v112 = nil;
    stack[-2] = v112;
    v112 = stack[-1];
    v112 = qcdr(v112);
    stack[-3] = v112;
    v112 = stack[-1];
    v120 = qcar(v112);
    v112 = stack[0];
    v112 = cons(v120, v112);
    nil = C_nil;
    if (exception_pending()) goto v142;
    env = stack[-4];
    stack[0] = v112;
    v112 = stack[-3];
    stack[-1] = v112;
    goto v45;

v7:
    v112 = stack[-2];
    if (v112 == nil) goto v13;
    v120 = stack[-2];
    v112 = stack[0];
    v112 = cons(v120, v112);
    nil = C_nil;
    if (exception_pending()) goto v142;
        popv(5);
        return Lnreverse(nil, v112);

v13:
    v112 = stack[0];
        popv(5);
        return Lnreverse(nil, v112);
/* error exit handlers */
v142:
    popv(5);
    return nil;
}



/* Code for mod!# */

static Lisp_Object CC_modC(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v99, v10;
    if (stack >= stacklimit)
    {
        push(v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v99 = v0;
/* end of prologue */
    v10 = v99;
    v99 = qvalue(elt(env, 1)); /* current!-modulus */
    v99 = Cremainder(v10, v99);
    nil = C_nil;
    if (exception_pending()) goto v14;
    env = stack[-1];
    stack[0] = v99;
    v10 = stack[0];
    v99 = (Lisp_Object)1; /* 0 */
    v99 = (Lisp_Object)lessp2(v10, v99);
    nil = C_nil;
    if (exception_pending()) goto v14;
    v99 = v99 ? lisp_true : nil;
    env = stack[-1];
    if (v99 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v99 = stack[0];
    v10 = qvalue(elt(env, 1)); /* current!-modulus */
    popv(2);
    return plus2(v99, v10);
/* error exit handlers */
v14:
    popv(2);
    return nil;
}



/* Code for convprec!* */

static Lisp_Object CC_convprecH(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v28, v38;
    Lisp_Object fn;
    if (stack >= stacklimit)
    {
        push(v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v28 = v0;
/* end of prologue */
    v38 = v28;
    if (!consp(v38)) goto v3;
    v38 = elt(env, 1); /* !:rd!: */
    v28 = cons(v38, v28);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[0];
    goto v3;

v3:
    {
        popv(1);
        fn = elt(env, 2); /* convchk */
        return (*qfn1(fn))(qenv(fn), v28);
    }
/* error exit handlers */
v44:
    popv(1);
    return nil;
}



/* Code for physopp!* */

static Lisp_Object CC_physoppH(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v54, v87;
    Lisp_Object fn;
    if (stack >= stacklimit)
    {
        push(v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v0;
/* end of prologue */
    v54 = stack[0];
    fn = elt(env, 4); /* physopp */
    v54 = (*qfn1(fn))(qenv(fn), v54);
    nil = C_nil;
    if (exception_pending()) goto v70;
    env = stack[-1];
    if (!(v54 == nil)) { popv(2); return onevalue(v54); }
    v54 = stack[0];
    if (!consp(v54)) goto v6;
    v54 = stack[0];
    v87 = qcar(v54);
    v54 = elt(env, 1); /* physopfn */
    v54 = Lflagp(nil, v87, v54);
    env = stack[-1];
    if (!(v54 == nil)) { popv(2); return onevalue(v54); }
    v54 = stack[0];
    v87 = qcar(v54);
    v54 = elt(env, 2); /* physoparith */
    v54 = Lflagp(nil, v87, v54);
    env = stack[-1];
    if (v54 == nil) goto v21;
    v54 = stack[0];
    v54 = qcdr(v54);
    fn = elt(env, 5); /* hasonephysop */
    v54 = (*qfn1(fn))(qenv(fn), v54);
    nil = C_nil;
    if (exception_pending()) goto v70;
    env = stack[-1];
    goto v20;

v20:
    if (!(v54 == nil)) { popv(2); return onevalue(v54); }
    v54 = stack[0];
    v87 = qcar(v54);
    v54 = elt(env, 3); /* physopmapping */
    v54 = Lflagp(nil, v87, v54);
    env = stack[-1];
    if (v54 == nil) goto v52;
    v54 = stack[0];
    v54 = qcdr(v54);
    {
        popv(2);
        fn = elt(env, 5); /* hasonephysop */
        return (*qfn1(fn))(qenv(fn), v54);
    }

v52:
    v54 = nil;
    { popv(2); return onevalue(v54); }

v21:
    v54 = nil;
    goto v20;

v6:
    v54 = nil;
    { popv(2); return onevalue(v54); }
/* error exit handlers */
v70:
    popv(2);
    return nil;
}



/* Code for red_divtestbe */

static Lisp_Object MS_CDECL CC_red_divtestbe(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v16,
                         Lisp_Object v63, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v33, v51;
    Lisp_Object fn;
    argcheck(nargs, 3, "red_divtestbe");
    if (stack >= stacklimit)
    {
        push3(v63,v16,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v16,v63);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v63;
    stack[-1] = v16;
    stack[-2] = v0;
/* end of prologue */

v12:
    v33 = stack[-2];
    if (v33 == nil) goto v6;
    v33 = stack[-2];
    v33 = qcar(v33);
    fn = elt(env, 1); /* bas_dpecart */
    v51 = (*qfn1(fn))(qenv(fn), v33);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-3];
    v33 = stack[0];
    v33 = (Lisp_Object)lesseq2(v51, v33);
    nil = C_nil;
    if (exception_pending()) goto v52;
    v33 = v33 ? lisp_true : nil;
    env = stack[-3];
    if (v33 == nil) goto v32;
    v33 = stack[-2];
    v33 = qcar(v33);
    fn = elt(env, 2); /* bas_dpoly */
    v33 = (*qfn1(fn))(qenv(fn), v33);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-3];
    fn = elt(env, 3); /* dp_lmon */
    v51 = (*qfn1(fn))(qenv(fn), v33);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-3];
    v33 = stack[-1];
    fn = elt(env, 4); /* mo_vdivides!? */
    v33 = (*qfn2(fn))(qenv(fn), v51, v33);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-3];
    if (v33 == nil) goto v32;
    v33 = stack[-2];
    v33 = qcar(v33);
    { popv(4); return onevalue(v33); }

v32:
    v33 = stack[-2];
    v33 = qcdr(v33);
    stack[-2] = v33;
    goto v12;

v6:
    v33 = nil;
    { popv(4); return onevalue(v33); }
/* error exit handlers */
v52:
    popv(4);
    return nil;
}



/* Code for gperm1 */

static Lisp_Object MS_CDECL CC_gperm1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v16,
                         Lisp_Object v63, Lisp_Object v9, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v67, v68, v56;
    Lisp_Object fn;
    argcheck(nargs, 4, "gperm1");
    if (stack >= stacklimit)
    {
        push4(v9,v63,v16,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v16,v63,v9);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-1] = v9;
    stack[-2] = v63;
    stack[-3] = v16;
    stack[-4] = v0;
/* end of prologue */

v6:
    v67 = stack[-4];
    if (v67 == nil) goto v24;
    v67 = stack[-4];
    v67 = qcdr(v67);
    stack[-5] = v67;
    v67 = stack[-4];
    v68 = qcar(v67);
    v67 = stack[-2];
    v67 = cons(v68, v67);
    nil = C_nil;
    if (exception_pending()) goto v57;
    env = stack[-6];
    stack[0] = v67;
    v68 = stack[-3];
    v67 = stack[-2];
    v67 = cons(v68, v67);
    nil = C_nil;
    if (exception_pending()) goto v57;
    env = stack[-6];
    fn = elt(env, 1); /* rev */
    v68 = (*qfn2(fn))(qenv(fn), stack[-4], v67);
    nil = C_nil;
    if (exception_pending()) goto v57;
    env = stack[-6];
    v67 = stack[-1];
    v67 = cons(v68, v67);
    nil = C_nil;
    if (exception_pending()) goto v57;
    env = stack[-6];
    stack[-1] = v67;
    v67 = stack[0];
    stack[-2] = v67;
    v67 = stack[-5];
    stack[-4] = v67;
    goto v6;

v24:
    v56 = stack[-3];
    v68 = stack[-2];
    v67 = stack[-1];
    popv(7);
    return acons(v56, v68, v67);
/* error exit handlers */
v57:
    popv(7);
    return nil;
}



/* Code for deg!*farg */

static Lisp_Object CC_degHfarg(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v36, v48;
    Lisp_Object fn;
    if (stack >= stacklimit)
    {
        push(v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    v48 = v0;
/* end of prologue */
    v36 = v48;
    v36 = qcdr(v36);
    if (v36 == nil) goto v3;
    stack[-1] = nil;
    v36 = v48;
    stack[0] = v36;
    goto v28;

v28:
    v36 = stack[0];
    if (v36 == nil) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v36 = stack[0];
    v36 = qcar(v36);
    fn = elt(env, 1); /* deg!*form */
    v48 = (*qfn1(fn))(qenv(fn), v36);
    nil = C_nil;
    if (exception_pending()) goto v42;
    env = stack[-2];
    v36 = stack[-1];
    fn = elt(env, 2); /* addf */
    v36 = (*qfn2(fn))(qenv(fn), v48, v36);
    nil = C_nil;
    if (exception_pending()) goto v42;
    env = stack[-2];
    stack[-1] = v36;
    v36 = stack[0];
    v36 = qcdr(v36);
    stack[0] = v36;
    goto v28;

v3:
    v36 = v48;
    v36 = qcar(v36);
    {
        popv(3);
        fn = elt(env, 1); /* deg!*form */
        return (*qfn1(fn))(qenv(fn), v36);
    }
/* error exit handlers */
v42:
    popv(3);
    return nil;
}



/* Code for abs!: */

static Lisp_Object CC_absT(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v10, v53;
    if (stack >= stacklimit)
    {
        push(v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0;
/* end of prologue */
    v10 = stack[0];
    v10 = qcdr(v10);
    v53 = qcar(v10);
    v10 = (Lisp_Object)1; /* 0 */
    v10 = (Lisp_Object)greaterp2(v53, v10);
    nil = C_nil;
    if (exception_pending()) goto v31;
    v10 = v10 ? lisp_true : nil;
    env = stack[-2];
    if (!(v10 == nil)) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    stack[-1] = elt(env, 1); /* !:rd!: */
    v10 = stack[0];
    v10 = qcdr(v10);
    v10 = qcar(v10);
    v53 = negate(v10);
    nil = C_nil;
    if (exception_pending()) goto v31;
    v10 = stack[0];
    v10 = qcdr(v10);
    v10 = qcdr(v10);
    {
        Lisp_Object v32 = stack[-1];
        popv(3);
        return list2star(v32, v53, v10);
    }
/* error exit handlers */
v31:
    popv(3);
    return nil;
}



/* Code for dp_diff */

static Lisp_Object CC_dp_diff(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v1, v2;
    Lisp_Object fn;
    if (stack >= stacklimit)
    {
        push2(v16,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v16);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v1 = v16;
    v2 = v0;
/* end of prologue */
    stack[0] = v2;
    fn = elt(env, 1); /* dp_neg */
    v1 = (*qfn1(fn))(qenv(fn), v1);
    nil = C_nil;
    if (exception_pending()) goto v13;
    env = stack[-1];
    {
        Lisp_Object v24 = stack[0];
        popv(2);
        fn = elt(env, 2); /* dp_sum */
        return (*qfn2(fn))(qenv(fn), v24, v1);
    }
/* error exit handlers */
v13:
    popv(2);
    return nil;
}



/* Code for pv_sort2a */

static Lisp_Object CC_pv_sort2a(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v143, v144;
    if (stack >= stacklimit)
    {
        push2(v16,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v16);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v16;
    stack[-1] = v0;
/* end of prologue */

v4:
    v143 = stack[0];
    v143 = qcdr(v143);
    if (v143 == nil) goto v26;
    v143 = stack[-1];
    v144 = qcdr(v143);
    v143 = stack[0];
    v143 = qcar(v143);
    v143 = qcdr(v143);
    v143 = (Lisp_Object)greaterp2(v144, v143);
    nil = C_nil;
    if (exception_pending()) goto v81;
    v143 = v143 ? lisp_true : nil;
    env = stack[-3];
    if (v143 == nil) goto v95;
    v143 = stack[0];
    v143 = qcdr(v143);
    stack[0] = v143;
    goto v4;

v95:
    v143 = stack[0];
    v144 = qcar(v143);
    v143 = stack[0];
    v143 = qcdr(v143);
    v143 = cons(v144, v143);
    nil = C_nil;
    if (exception_pending()) goto v81;
    env = stack[-3];
    stack[-2] = v143;
    v144 = stack[0];
    v143 = stack[-1];
    v144 = Lrplaca(nil, v144, v143);
    nil = C_nil;
    if (exception_pending()) goto v81;
    v143 = stack[-2];
        popv(4);
        return Lrplacd(nil, v144, v143);

v26:
    v143 = stack[-1];
    v144 = qcdr(v143);
    v143 = stack[0];
    v143 = qcar(v143);
    v143 = qcdr(v143);
    v143 = (Lisp_Object)greaterp2(v144, v143);
    nil = C_nil;
    if (exception_pending()) goto v81;
    v143 = v143 ? lisp_true : nil;
    env = stack[-3];
    if (v143 == nil) goto v31;
    v143 = stack[-1];
    v143 = ncons(v143);
    nil = C_nil;
    if (exception_pending()) goto v81;
    {
        Lisp_Object v97 = stack[0];
        popv(4);
        return Lrplacd(nil, v97, v143);
    }

v31:
    v143 = stack[0];
    v144 = qcar(v143);
    v143 = stack[0];
    v143 = qcdr(v143);
    v143 = cons(v144, v143);
    nil = C_nil;
    if (exception_pending()) goto v81;
    env = stack[-3];
    stack[-2] = v143;
    v144 = stack[0];
    v143 = stack[-1];
    v144 = Lrplaca(nil, v144, v143);
    nil = C_nil;
    if (exception_pending()) goto v81;
    v143 = stack[-2];
        popv(4);
        return Lrplacd(nil, v144, v143);
/* error exit handlers */
v81:
    popv(4);
    return nil;
}



/* Code for modplus!: */

static Lisp_Object CC_modplusT(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v25, v13;
    Lisp_Object fn;
    if (stack >= stacklimit)
    {
        push2(v16,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v16);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v25 = v16;
    v13 = v0;
/* end of prologue */
    v13 = qcdr(v13);
    v25 = qcdr(v25);
    fn = elt(env, 1); /* general!-modular!-plus */
    v25 = (*qfn2(fn))(qenv(fn), v13, v25);
    nil = C_nil;
    if (exception_pending()) goto v24;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* !*modular2f */
        return (*qfn1(fn))(qenv(fn), v25);
    }
/* error exit handlers */
v24:
    popv(1);
    return nil;
}



/* Code for mkgi */

static Lisp_Object CC_mkgi(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v25, v13, v24;
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v25 = v16;
    v13 = v0;
/* end of prologue */
    v24 = elt(env, 1); /* !:gi!: */
    return list2star(v24, v13, v25);
}



/* Code for evcompless!? */

static Lisp_Object CC_evcomplessW(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v27, v28;
    Lisp_Object fn;
    if (stack >= stacklimit)
    {
        push2(v16,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v16);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v28 = v16;
    v27 = v0;
/* end of prologue */
    stack[0] = (Lisp_Object)17; /* 1 */
    fn = elt(env, 1); /* evcomp */
    v27 = (*qfn2(fn))(qenv(fn), v28, v27);
    nil = C_nil;
    if (exception_pending()) goto v44;
    v27 = (stack[0] == v27 ? lisp_true : nil);
    { popv(1); return onevalue(v27); }
/* error exit handlers */
v44:
    popv(1);
    return nil;
}



/* Code for rd!:zerop */

static Lisp_Object CC_rdTzerop(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v15, v43;
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v15 = v0;
/* end of prologue */
    v43 = v15;
    v43 = qcdr(v43);
    if (!consp(v43)) goto v3;
    v15 = qcdr(v15);
    v43 = qcar(v15);
    v15 = (Lisp_Object)1; /* 0 */
    v15 = (v43 == v15 ? lisp_true : nil);
    return onevalue(v15);

v3:
    v15 = qcdr(v15);
        return Lzerop(nil, v15);
}



/* Code for red!-char!-downcase */

static Lisp_Object CC_redKcharKdowncase(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v44, v47, v15;
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v47 = v0;
/* end of prologue */
    v44 = v47;
    v15 = qvalue(elt(env, 1)); /* charassoc!* */
    v44 = Latsoc(nil, v44, v15);
    v15 = v44;
    v44 = v15;
    if (v44 == nil) return onevalue(v47);
    v44 = v15;
    v44 = qcdr(v44);
    return onevalue(v44);
}



/* Code for dp_times_bc */

static Lisp_Object CC_dp_times_bc(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v58, v55;
    Lisp_Object fn;
    if (stack >= stacklimit)
    {
        push2(v16,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v16);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    v58 = v16;
    stack[-4] = v0;
/* end of prologue */
    stack[-5] = v58;
    v58 = stack[-5];
    if (v58 == nil) goto v1;
    v58 = stack[-5];
    v58 = qcar(v58);
    v55 = v58;
    stack[0] = qcar(v55);
    v55 = stack[-4];
    v58 = qcdr(v58);
    fn = elt(env, 1); /* bc_prod */
    v58 = (*qfn2(fn))(qenv(fn), v55, v58);
    nil = C_nil;
    if (exception_pending()) goto v220;
    env = stack[-6];
    v58 = cons(stack[0], v58);
    nil = C_nil;
    if (exception_pending()) goto v220;
    env = stack[-6];
    v58 = ncons(v58);
    nil = C_nil;
    if (exception_pending()) goto v220;
    env = stack[-6];
    stack[-2] = v58;
    stack[-3] = v58;
    goto v5;

v5:
    v58 = stack[-5];
    v58 = qcdr(v58);
    stack[-5] = v58;
    v58 = stack[-5];
    if (v58 == nil) { Lisp_Object res = stack[-3]; popv(7); return onevalue(res); }
    stack[-1] = stack[-2];
    v58 = stack[-5];
    v58 = qcar(v58);
    v55 = v58;
    stack[0] = qcar(v55);
    v55 = stack[-4];
    v58 = qcdr(v58);
    fn = elt(env, 1); /* bc_prod */
    v58 = (*qfn2(fn))(qenv(fn), v55, v58);
    nil = C_nil;
    if (exception_pending()) goto v220;
    env = stack[-6];
    v58 = cons(stack[0], v58);
    nil = C_nil;
    if (exception_pending()) goto v220;
    env = stack[-6];
    v58 = ncons(v58);
    nil = C_nil;
    if (exception_pending()) goto v220;
    env = stack[-6];
    v58 = Lrplacd(nil, stack[-1], v58);
    nil = C_nil;
    if (exception_pending()) goto v220;
    env = stack[-6];
    v58 = stack[-2];
    v58 = qcdr(v58);
    stack[-2] = v58;
    goto v5;

v1:
    v58 = nil;
    { popv(7); return onevalue(v58); }
/* error exit handlers */
v220:
    popv(7);
    return nil;
}



/* Code for tsym4 */

static Lisp_Object MS_CDECL CC_tsym4(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v16,
                         Lisp_Object v63, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v33, v51;
    Lisp_Object fn;
    argcheck(nargs, 3, "tsym4");
    if (stack >= stacklimit)
    {
        push3(v63,v16,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v16,v63);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v63;
    stack[-1] = v16;
    v33 = v0;
/* end of prologue */

v45:
    v51 = v33;
    if (v51 == nil) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v51 = v33;
    v51 = qcdr(v51);
    stack[-2] = v51;
    v51 = stack[-1];
    v51 = qcdr(v51);
    v33 = qcar(v33);
    fn = elt(env, 1); /* pv_applp */
    v51 = (*qfn2(fn))(qenv(fn), v51, v33);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-3];
    v33 = stack[0];
    fn = elt(env, 2); /* sieve_pv */
    v33 = (*qfn2(fn))(qenv(fn), v51, v33);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-3];
    fn = elt(env, 3); /* pv_renorm */
    v51 = (*qfn1(fn))(qenv(fn), v33);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-3];
    v33 = stack[0];
    fn = elt(env, 4); /* insert_pv */
    v33 = (*qfn2(fn))(qenv(fn), v51, v33);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-3];
    stack[0] = v33;
    v33 = stack[-2];
    goto v45;
/* error exit handlers */
v52:
    popv(4);
    return nil;
}



/* Code for diplength */

static Lisp_Object CC_diplength(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v48, v33;
    if (stack >= stacklimit)
    {
        push(v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0;
/* end of prologue */
    stack[-1] = nil;
    goto v12;

v12:
    v48 = stack[0];
    if (v48 == nil) goto v45;
    v33 = (Lisp_Object)17; /* 1 */
    v48 = stack[-1];
    v48 = cons(v33, v48);
    nil = C_nil;
    if (exception_pending()) goto v49;
    env = stack[-2];
    stack[-1] = v48;
    v48 = stack[0];
    v48 = qcdr(v48);
    v48 = qcdr(v48);
    stack[0] = v48;
    goto v12;

v45:
    v48 = (Lisp_Object)1; /* 0 */
    v33 = v48;
    goto v5;

v5:
    v48 = stack[-1];
    if (v48 == nil) { popv(3); return onevalue(v33); }
    v48 = stack[-1];
    v48 = qcar(v48);
    v48 = plus2(v48, v33);
    nil = C_nil;
    if (exception_pending()) goto v49;
    env = stack[-2];
    v33 = v48;
    v48 = stack[-1];
    v48 = qcdr(v48);
    stack[-1] = v48;
    goto v5;
/* error exit handlers */
v49:
    popv(3);
    return nil;
}



/* Code for mknwedge */

static Lisp_Object CC_mknwedge(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v38, v44;
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v44 = v0;
/* end of prologue */
    v38 = v44;
    v38 = qcdr(v38);
    if (v38 == nil) goto v24;
    v38 = elt(env, 1); /* wedge */
    return cons(v38, v44);

v24:
    v38 = v44;
    v38 = qcar(v38);
    return onevalue(v38);
}



/* Code for worderp */

static Lisp_Object CC_worderp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v149, v111, v216;
    Lisp_Object fn;
    if (stack >= stacklimit)
    {
        push2(v16,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v16);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v16;
    stack[-1] = v0;
/* end of prologue */

v4:
    v149 = stack[-1];
    if (!consp(v149)) goto v6;
    v149 = stack[-1];
    v111 = qcar(v149);
    v149 = elt(env, 1); /* indexvar */
    v149 = Lflagp(nil, v111, v149);
    env = stack[-2];
    if (v149 == nil) goto v6;
    v149 = stack[0];
    if (!consp(v149)) goto v6;
    v149 = stack[0];
    v111 = qcar(v149);
    v149 = elt(env, 1); /* indexvar */
    v149 = Lflagp(nil, v111, v149);
    env = stack[-2];
    if (v149 == nil) goto v6;
    v111 = stack[-1];
    v149 = stack[0];
    {
        popv(3);
        fn = elt(env, 3); /* indexvarordp */
        return (*qfn2(fn))(qenv(fn), v111, v149);
    }

v6:
    v149 = stack[-1];
    if (!consp(v149)) goto v36;
    v111 = stack[-1];
    v149 = qvalue(elt(env, 2)); /* kord!* */
    v149 = Lmemq(nil, v111, v149);
    if (!(v149 == nil)) goto v36;
    v149 = stack[0];
    if (!consp(v149)) goto v237;
    v111 = stack[0];
    v149 = qvalue(elt(env, 2)); /* kord!* */
    v149 = Lmemq(nil, v111, v149);
    if (!(v149 == nil)) goto v237;
    v149 = stack[-1];
    fn = elt(env, 4); /* peel */
    v149 = (*qfn1(fn))(qenv(fn), v149);
    nil = C_nil;
    if (exception_pending()) goto v214;
    env = stack[-2];
    stack[-1] = v149;
    v149 = stack[0];
    fn = elt(env, 4); /* peel */
    v149 = (*qfn1(fn))(qenv(fn), v149);
    nil = C_nil;
    if (exception_pending()) goto v214;
    env = stack[-2];
    stack[0] = v149;
    goto v4;

v237:
    v149 = stack[-1];
    fn = elt(env, 4); /* peel */
    v149 = (*qfn1(fn))(qenv(fn), v149);
    nil = C_nil;
    if (exception_pending()) goto v214;
    env = stack[-2];
    v216 = v149;
    v111 = v216;
    v149 = stack[0];
    if (v111 == v149) goto v140;
    v111 = v216;
    v149 = stack[0];
    stack[-1] = v111;
    stack[0] = v149;
    goto v4;

v140:
    v149 = nil;
    { popv(3); return onevalue(v149); }

v36:
    v149 = stack[0];
    if (!consp(v149)) goto v101;
    v111 = stack[0];
    v149 = qvalue(elt(env, 2)); /* kord!* */
    v149 = Lmemq(nil, v111, v149);
    if (!(v149 == nil)) goto v101;
    v149 = stack[0];
    fn = elt(env, 4); /* peel */
    v149 = (*qfn1(fn))(qenv(fn), v149);
    nil = C_nil;
    if (exception_pending()) goto v214;
    env = stack[-2];
    v216 = v149;
    v111 = stack[-1];
    v149 = v216;
    if (v111 == v149) goto v61;
    v149 = stack[-1];
    v111 = v216;
    stack[-1] = v149;
    stack[0] = v111;
    goto v4;

v61:
    v149 = lisp_true;
    { popv(3); return onevalue(v149); }

v101:
    v111 = stack[-1];
    v149 = stack[0];
    {
        popv(3);
        fn = elt(env, 5); /* ordop */
        return (*qfn2(fn))(qenv(fn), v111, v149);
    }
/* error exit handlers */
v214:
    popv(3);
    return nil;
}



/* Code for rd!:onep */

static Lisp_Object CC_rdTonep(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v53, v14;
    Lisp_Object fn;
    if (stack >= stacklimit)
    {
        push(v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v53 = v0;
/* end of prologue */
    v14 = v53;
    v14 = qcdr(v14);
    if (!consp(v14)) goto v24;
    stack[0] = qvalue(elt(env, 3)); /* bfone!* */
    fn = elt(env, 4); /* bftrim!: */
    v53 = (*qfn1(fn))(qenv(fn), v53);
    nil = C_nil;
    if (exception_pending()) goto v31;
    env = stack[-1];
    {
        Lisp_Object v32 = stack[0];
        popv(2);
        fn = elt(env, 5); /* equal!: */
        return (*qfn2(fn))(qenv(fn), v32, v53);
    }

v24:
    v14 = elt(env, 1); /* 1.0 */
    v53 = qcdr(v53);
    v53 = difference2(v14, v53);
    nil = C_nil;
    if (exception_pending()) goto v31;
    env = stack[-1];
    v53 = Labsval(nil, v53);
    nil = C_nil;
    if (exception_pending()) goto v31;
    env = stack[-1];
    v14 = qvalue(elt(env, 2)); /* !!fleps1 */
        popv(2);
        return Llessp(nil, v53, v14);
/* error exit handlers */
v31:
    popv(2);
    return nil;
}



/* Code for getphystype!*sq */

static Lisp_Object CC_getphystypeHsq(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v12;
    Lisp_Object fn;
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v12 = v0;
/* end of prologue */
    v12 = qcar(v12);
    v12 = qcar(v12);
    {
        fn = elt(env, 1); /* getphystypesf */
        return (*qfn1(fn))(qenv(fn), v12);
    }
}



/* Code for groeb!=testa */

static Lisp_Object CC_groebMtesta(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v29, v17;
    Lisp_Object fn;
    if (stack >= stacklimit)
    {
        push2(v16,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v16);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v16;
    v29 = v0;
/* end of prologue */
    v17 = v29;
    v29 = (Lisp_Object)49; /* 3 */
    fn = elt(env, 1); /* nth */
    stack[-1] = (*qfn2(fn))(qenv(fn), v17, v29);
    nil = C_nil;
    if (exception_pending()) goto v20;
    env = stack[-2];
    v17 = stack[0];
    v29 = (Lisp_Object)49; /* 3 */
    fn = elt(env, 1); /* nth */
    v29 = (*qfn2(fn))(qenv(fn), v17, v29);
    nil = C_nil;
    if (exception_pending()) goto v20;
    env = stack[-2];
    {
        Lisp_Object v21 = stack[-1];
        popv(3);
        fn = elt(env, 2); /* mo_divides!? */
        return (*qfn2(fn))(qenv(fn), v21, v29);
    }
/* error exit handlers */
v20:
    popv(3);
    return nil;
}



/* Code for gperm */

static Lisp_Object CC_gperm(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v122, v58;
    Lisp_Object fn;
    if (stack >= stacklimit)
    {
        push(v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0;
/* end of prologue */
    stack[-1] = nil;
    goto v2;

v2:
    v58 = stack[0];
    v122 = (Lisp_Object)1; /* 0 */
    v122 = (Lisp_Object)greaterp2(v58, v122);
    nil = C_nil;
    if (exception_pending()) goto v60;
    v122 = v122 ? lisp_true : nil;
    env = stack[-4];
    if (v122 == nil) goto v12;
    v58 = stack[0];
    v122 = stack[-1];
    v122 = cons(v58, v122);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-4];
    stack[-1] = v122;
    v122 = stack[0];
    v122 = sub1(v122);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-4];
    stack[0] = v122;
    goto v2;

v12:
    v122 = stack[-1];
    fn = elt(env, 1); /* gperm0 */
    v122 = (*qfn1(fn))(qenv(fn), v122);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-4];
    stack[-3] = v122;
    v122 = stack[-3];
    if (v122 == nil) goto v37;
    v122 = stack[-3];
    v122 = qcar(v122);
    fn = elt(env, 2); /* pkp */
    v122 = (*qfn1(fn))(qenv(fn), v122);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-4];
    v122 = ncons(v122);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-4];
    stack[-1] = v122;
    stack[-2] = v122;
    goto v53;

v53:
    v122 = stack[-3];
    v122 = qcdr(v122);
    stack[-3] = v122;
    v122 = stack[-3];
    if (v122 == nil) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    stack[0] = stack[-1];
    v122 = stack[-3];
    v122 = qcar(v122);
    fn = elt(env, 2); /* pkp */
    v122 = (*qfn1(fn))(qenv(fn), v122);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-4];
    v122 = ncons(v122);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-4];
    v122 = Lrplacd(nil, stack[0], v122);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-4];
    v122 = stack[-1];
    v122 = qcdr(v122);
    stack[-1] = v122;
    goto v53;

v37:
    v122 = nil;
    { popv(5); return onevalue(v122); }
/* error exit handlers */
v60:
    popv(5);
    return nil;
}



/* Code for minus!-mod!-p */

static Lisp_Object CC_minusKmodKp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v52, v193;
    Lisp_Object fn;
    if (stack >= stacklimit)
    {
        push(v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0;
/* end of prologue */
    stack[-2] = nil;
    goto v4;

v4:
    v52 = stack[-1];
    if (v52 == nil) goto v5;
    v52 = stack[-1];
    if (!consp(v52)) goto v44;
    v52 = stack[-1];
    v52 = qcar(v52);
    if (!consp(v52)) goto v44;
    v52 = stack[-1];
    v52 = qcar(v52);
    stack[0] = qcar(v52);
    v52 = stack[-1];
    v52 = qcar(v52);
    v52 = qcdr(v52);
    v193 = CC_minusKmodKp(env, v52);
    nil = C_nil;
    if (exception_pending()) goto v40;
    env = stack[-3];
    v52 = stack[-2];
    v52 = acons(stack[0], v193, v52);
    nil = C_nil;
    if (exception_pending()) goto v40;
    env = stack[-3];
    stack[-2] = v52;
    v52 = stack[-1];
    v52 = qcdr(v52);
    stack[-1] = v52;
    goto v4;

v44:
    v193 = stack[-2];
    v52 = stack[-1];
    {   int32 w = int_of_fixnum(v52);
        if (w != 0) w = current_modulus - w;
        v52 = fixnum_of_int(w);
    }
    {
        popv(4);
        fn = elt(env, 1); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v193, v52);
    }

v5:
    v52 = stack[-2];
    {
        popv(4);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v52);
    }
/* error exit handlers */
v40:
    popv(4);
    return nil;
}



/* Code for xdegree */

static Lisp_Object CC_xdegree(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v25, v13;
    Lisp_Object fn;
    if (stack >= stacklimit)
    {
        push(v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v25 = v0;
/* end of prologue */
    fn = elt(env, 1); /* deg!*form */
    v25 = (*qfn1(fn))(qenv(fn), v25);
    errexit();
    v13 = v25;
    v25 = v13;
    if (!(v25 == nil)) return onevalue(v13);
    v25 = (Lisp_Object)1; /* 0 */
    return onevalue(v25);
}



/* Code for boundindp */

static Lisp_Object CC_boundindp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v23, v30, v99, v10;
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v30 = v16;
    v99 = v0;
/* end of prologue */

v4:
    v23 = v99;
    if (v23 == nil) goto v5;
    v23 = v99;
    v10 = qcar(v23);
    v23 = v30;
    v23 = Lmember(nil, v10, v23);
    if (v23 == nil) goto v20;
    v23 = v99;
    v23 = qcdr(v23);
    v99 = v23;
    goto v4;

v20:
    v23 = nil;
    return onevalue(v23);

v5:
    v23 = lisp_true;
    return onevalue(v23);
}



/* Code for dp_sum */

static Lisp_Object CC_dp_sum(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v114, v115, v132;
    Lisp_Object fn;
    if (stack >= stacklimit)
    {
        push2(v16,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v16);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v16;
    stack[-1] = v0;
/* end of prologue */

v11:
    v114 = stack[-1];
    if (v114 == nil) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v114 = stack[0];
    if (v114 == nil) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v114 = stack[-1];
    fn = elt(env, 1); /* dp_lmon */
    stack[-2] = (*qfn1(fn))(qenv(fn), v114);
    nil = C_nil;
    if (exception_pending()) goto v213;
    env = stack[-3];
    v114 = stack[0];
    fn = elt(env, 1); /* dp_lmon */
    v114 = (*qfn1(fn))(qenv(fn), v114);
    nil = C_nil;
    if (exception_pending()) goto v213;
    env = stack[-3];
    fn = elt(env, 2); /* mo_compare */
    v114 = (*qfn2(fn))(qenv(fn), stack[-2], v114);
    nil = C_nil;
    if (exception_pending()) goto v213;
    env = stack[-3];
    v132 = v114;
    v115 = v132;
    v114 = (Lisp_Object)17; /* 1 */
    if (v115 == v114) goto v37;
    v115 = v132;
    v114 = (Lisp_Object)-15; /* -1 */
    if (v115 == v114) goto v70;
    v114 = stack[-1];
    fn = elt(env, 3); /* dp_lc */
    stack[-2] = (*qfn1(fn))(qenv(fn), v114);
    nil = C_nil;
    if (exception_pending()) goto v213;
    env = stack[-3];
    v114 = stack[0];
    fn = elt(env, 3); /* dp_lc */
    v114 = (*qfn1(fn))(qenv(fn), v114);
    nil = C_nil;
    if (exception_pending()) goto v213;
    env = stack[-3];
    fn = elt(env, 4); /* bc_sum */
    v114 = (*qfn2(fn))(qenv(fn), stack[-2], v114);
    nil = C_nil;
    if (exception_pending()) goto v213;
    env = stack[-3];
    stack[-2] = v114;
    v114 = stack[-2];
    fn = elt(env, 5); /* bc_zero!? */
    v114 = (*qfn1(fn))(qenv(fn), v114);
    nil = C_nil;
    if (exception_pending()) goto v213;
    env = stack[-3];
    if (v114 == nil) goto v139;
    v114 = stack[-1];
    v115 = qcdr(v114);
    v114 = stack[0];
    v114 = qcdr(v114);
    stack[-1] = v115;
    stack[0] = v114;
    goto v11;

v139:
    v114 = stack[-1];
    fn = elt(env, 1); /* dp_lmon */
    v114 = (*qfn1(fn))(qenv(fn), v114);
    nil = C_nil;
    if (exception_pending()) goto v213;
    env = stack[-3];
    fn = elt(env, 6); /* dp_term */
    stack[-2] = (*qfn2(fn))(qenv(fn), stack[-2], v114);
    nil = C_nil;
    if (exception_pending()) goto v213;
    env = stack[-3];
    v114 = stack[-1];
    v115 = qcdr(v114);
    v114 = stack[0];
    v114 = qcdr(v114);
    v114 = CC_dp_sum(env, v115, v114);
    nil = C_nil;
    if (exception_pending()) goto v213;
    {
        Lisp_Object v77 = stack[-2];
        popv(4);
        return cons(v77, v114);
    }

v70:
    v114 = stack[0];
    stack[-2] = qcar(v114);
    v115 = stack[-1];
    v114 = stack[0];
    v114 = qcdr(v114);
    v114 = CC_dp_sum(env, v115, v114);
    nil = C_nil;
    if (exception_pending()) goto v213;
    {
        Lisp_Object v78 = stack[-2];
        popv(4);
        return cons(v78, v114);
    }

v37:
    v114 = stack[-1];
    stack[-2] = qcar(v114);
    v114 = stack[-1];
    v115 = qcdr(v114);
    v114 = stack[0];
    v114 = CC_dp_sum(env, v115, v114);
    nil = C_nil;
    if (exception_pending()) goto v213;
    {
        Lisp_Object v230 = stack[-2];
        popv(4);
        return cons(v230, v114);
    }
/* error exit handlers */
v213:
    popv(4);
    return nil;
}



/* Code for pappl_pv */

static Lisp_Object CC_pappl_pv(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v55, v65;
    Lisp_Object fn;
    if (stack >= stacklimit)
    {
        push2(v16,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v16);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    v55 = v16;
    stack[-4] = v0;
/* end of prologue */
    stack[-5] = v55;
    v55 = stack[-5];
    if (v55 == nil) goto v2;
    v55 = stack[-5];
    v55 = qcar(v55);
    v65 = v55;
    stack[0] = qcar(v65);
    v65 = stack[-4];
    v55 = qcdr(v55);
    fn = elt(env, 1); /* pappl0 */
    v55 = (*qfn2(fn))(qenv(fn), v65, v55);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-6];
    v55 = cons(stack[0], v55);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-6];
    v55 = ncons(v55);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-6];
    stack[-2] = v55;
    stack[-3] = v55;
    goto v6;

v6:
    v55 = stack[-5];
    v55 = qcdr(v55);
    stack[-5] = v55;
    v55 = stack[-5];
    if (v55 == nil) goto v36;
    stack[-1] = stack[-2];
    v55 = stack[-5];
    v55 = qcar(v55);
    v65 = v55;
    stack[0] = qcar(v65);
    v65 = stack[-4];
    v55 = qcdr(v55);
    fn = elt(env, 1); /* pappl0 */
    v55 = (*qfn2(fn))(qenv(fn), v65, v55);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-6];
    v55 = cons(stack[0], v55);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-6];
    v55 = ncons(v55);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-6];
    v55 = Lrplacd(nil, stack[-1], v55);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-6];
    v55 = stack[-2];
    v55 = qcdr(v55);
    stack[-2] = v55;
    goto v6;

v36:
    v55 = stack[-3];
    goto v5;

v5:
    {
        popv(7);
        fn = elt(env, 2); /* pv_sort */
        return (*qfn1(fn))(qenv(fn), v55);
    }

v2:
    v55 = nil;
    goto v5;
/* error exit handlers */
v106:
    popv(7);
    return nil;
}



/* Code for arzerop!: */

static Lisp_Object CC_arzeropT(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v4;
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v4 = v0;
/* end of prologue */
    v4 = qcdr(v4);
    v4 = (v4 == nil ? lisp_true : nil);
    return onevalue(v4);
}



/* Code for general!-plus!-mod!-p */

static Lisp_Object CC_generalKplusKmodKp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v470, v432;
    Lisp_Object fn;
    if (stack >= stacklimit)
    {
        push2(v16,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v16);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v16;
    stack[-3] = v0;
/* end of prologue */
    stack[0] = nil;
    goto v12;

v12:
    v470 = stack[-3];
    if (v470 == nil) goto v2;
    v470 = stack[-2];
    if (v470 == nil) goto v43;
    v470 = stack[-3];
    if (!consp(v470)) goto v22;
    v470 = stack[-3];
    v470 = qcar(v470);
    if (!consp(v470)) goto v22;
    v470 = stack[-2];
    if (!consp(v470)) goto v106;
    v470 = stack[-2];
    v470 = qcar(v470);
    if (!consp(v470)) goto v106;
    v470 = stack[-3];
    v470 = qcar(v470);
    v432 = qcar(v470);
    v470 = stack[-2];
    v470 = qcar(v470);
    v470 = qcar(v470);
    if (equal(v432, v470)) goto v144;
    v470 = stack[-3];
    v470 = qcar(v470);
    v470 = qcar(v470);
    v432 = qcar(v470);
    v470 = stack[-2];
    v470 = qcar(v470);
    v470 = qcar(v470);
    v470 = qcar(v470);
    if (!(equal(v432, v470))) goto v125;
    v470 = stack[-3];
    v470 = qcar(v470);
    v470 = qcar(v470);
    v432 = qcdr(v470);
    v470 = stack[-2];
    v470 = qcar(v470);
    v470 = qcar(v470);
    v470 = qcdr(v470);
    if (!(((int32)(v432)) > ((int32)(v470)))) goto v125;

v183:
    v470 = stack[-3];
    v432 = qcar(v470);
    v470 = stack[0];
    v470 = cons(v432, v470);
    nil = C_nil;
    if (exception_pending()) goto v177;
    env = stack[-5];
    stack[0] = v470;
    v470 = stack[-3];
    v470 = qcdr(v470);
    stack[-3] = v470;
    goto v12;

v125:
    v470 = stack[-3];
    v470 = qcar(v470);
    v470 = qcar(v470);
    v432 = qcar(v470);
    v470 = stack[-2];
    v470 = qcar(v470);
    v470 = qcar(v470);
    v470 = qcar(v470);
    if (equal(v432, v470)) goto v519;
    v470 = stack[-3];
    v470 = qcar(v470);
    v470 = qcar(v470);
    v432 = qcar(v470);
    v470 = stack[-2];
    v470 = qcar(v470);
    v470 = qcar(v470);
    v470 = qcar(v470);
    fn = elt(env, 1); /* ordop */
    v470 = (*qfn2(fn))(qenv(fn), v432, v470);
    nil = C_nil;
    if (exception_pending()) goto v177;
    env = stack[-5];
    if (!(v470 == nil)) goto v183;

v519:
    v470 = stack[-2];
    v432 = qcar(v470);
    v470 = stack[0];
    v470 = cons(v432, v470);
    nil = C_nil;
    if (exception_pending()) goto v177;
    env = stack[-5];
    stack[0] = v470;
    v470 = stack[-2];
    v470 = qcdr(v470);
    stack[-2] = v470;
    goto v12;

v144:
    stack[-4] = stack[0];
    v470 = stack[-3];
    v470 = qcar(v470);
    stack[-1] = qcar(v470);
    v470 = stack[-3];
    v470 = qcar(v470);
    v432 = qcdr(v470);
    v470 = stack[-2];
    v470 = qcar(v470);
    v470 = qcdr(v470);
    stack[0] = CC_generalKplusKmodKp(env, v432, v470);
    nil = C_nil;
    if (exception_pending()) goto v177;
    env = stack[-5];
    v470 = stack[-3];
    v432 = qcdr(v470);
    v470 = stack[-2];
    v470 = qcdr(v470);
    v470 = CC_generalKplusKmodKp(env, v432, v470);
    nil = C_nil;
    if (exception_pending()) goto v177;
    env = stack[-5];
    fn = elt(env, 2); /* adjoin!-term */
    v470 = (*qfnn(fn))(qenv(fn), 3, stack[-1], stack[0], v470);
    nil = C_nil;
    if (exception_pending()) goto v177;
    env = stack[-5];
    {
        Lisp_Object v254 = stack[-4];
        popv(6);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v254, v470);
    }

v106:
    v470 = stack[-3];
    v432 = qcar(v470);
    v470 = stack[0];
    v470 = cons(v432, v470);
    nil = C_nil;
    if (exception_pending()) goto v177;
    env = stack[-5];
    stack[0] = v470;
    v470 = stack[-3];
    v470 = qcdr(v470);
    stack[-3] = v470;
    goto v12;

v22:
    v470 = stack[-2];
    if (!consp(v470)) goto v41;
    v470 = stack[-2];
    v470 = qcar(v470);
    if (!consp(v470)) goto v41;
    v470 = stack[-2];
    v432 = qcar(v470);
    v470 = stack[0];
    v470 = cons(v432, v470);
    nil = C_nil;
    if (exception_pending()) goto v177;
    env = stack[-5];
    stack[0] = v470;
    v470 = stack[-2];
    v470 = qcdr(v470);
    stack[-2] = v470;
    goto v12;

v41:
    v432 = stack[-3];
    v470 = stack[-2];
    fn = elt(env, 4); /* general!-modular!-plus */
    v470 = (*qfn2(fn))(qenv(fn), v432, v470);
    nil = C_nil;
    if (exception_pending()) goto v177;
    env = stack[-5];
    fn = elt(env, 5); /* !*n2f */
    v470 = (*qfn1(fn))(qenv(fn), v470);
    nil = C_nil;
    if (exception_pending()) goto v177;
    env = stack[-5];
    {
        Lisp_Object v201 = stack[0];
        popv(6);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v201, v470);
    }

v43:
    v432 = stack[0];
    v470 = stack[-3];
    {
        popv(6);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v432, v470);
    }

v2:
    v432 = stack[0];
    v470 = stack[-2];
    {
        popv(6);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v432, v470);
    }
/* error exit handlers */
v177:
    popv(6);
    return nil;
}



/* Code for gsetsugar */

static Lisp_Object CC_gsetsugar(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v22, v23;
    Lisp_Object fn;
    if (stack >= stacklimit)
    {
        push2(v16,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v16);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    v23 = v16;
    stack[-1] = v0;
/* end of prologue */
    v22 = qvalue(elt(env, 1)); /* !*gsugar */
    if (v22 == nil) goto v5;
    stack[-2] = stack[-1];
    stack[0] = elt(env, 2); /* sugar */
    v22 = v23;
    if (!(v22 == nil)) goto v38;
    v22 = stack[-1];
    fn = elt(env, 3); /* vdptdeg */
    v22 = (*qfn1(fn))(qenv(fn), v22);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-3];
    goto v38;

v38:
    fn = elt(env, 4); /* vdpputprop */
    v22 = (*qfnn(fn))(qenv(fn), 3, stack[-2], stack[0], v22);
    nil = C_nil;
    if (exception_pending()) goto v53;
    goto v45;

v45:
    if (v22 == nil) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    else { popv(4); return onevalue(v22); }

v5:
    v22 = nil;
    goto v45;
/* error exit handlers */
v53:
    popv(4);
    return nil;
}



/* Code for deg!*form */

static Lisp_Object CC_degHform(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v183, v256, v210;
    Lisp_Object fn;
    if (stack >= stacklimit)
    {
        push(v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0;
/* end of prologue */

v11:
    v183 = stack[0];
    if (!consp(v183)) goto v5;
    v183 = stack[0];
    v183 = qcar(v183);
    v210 = v183;
    v256 = v210;
    v183 = elt(env, 2); /* indexvar */
    v183 = Lflagp(nil, v256, v183);
    env = stack[-2];
    if (v183 == nil) goto v122;
    v183 = stack[0];
    v183 = qcdr(v183);
    v210 = Llength(nil, v183);
    nil = C_nil;
    if (exception_pending()) goto v248;
    env = stack[-2];
    v183 = stack[0];
    v256 = qcar(v183);
    v183 = elt(env, 3); /* ifdegree */
    v183 = get(v256, v183);
    v183 = Lassoc(nil, v210, v183);
    v256 = v183;
    v183 = v256;
    if (v183 == nil) goto v70;
    v183 = v256;
    v183 = qcdr(v183);
    { popv(3); return onevalue(v183); }

v70:
    v183 = nil;
    { popv(3); return onevalue(v183); }

v122:
    v256 = v210;
    v183 = elt(env, 4); /* wedge */
    if (v256 == v183) goto v57;
    v256 = v210;
    v183 = elt(env, 5); /* d */
    if (v256 == v183) goto v112;
    v256 = v210;
    v183 = elt(env, 6); /* hodge */
    if (v256 == v183) goto v118;
    v256 = v210;
    v183 = elt(env, 8); /* partdf */
    if (v256 == v183) goto v233;
    v256 = v210;
    v183 = elt(env, 9); /* liedf */
    if (v256 == v183) goto v77;
    v256 = v210;
    v183 = elt(env, 10); /* innerprod */
    if (v256 == v183) goto v186;
    v256 = v210;
    v183 = elt(env, 11); /* (plus minus difference quotient) */
    v183 = Lmemq(nil, v256, v183);
    if (v183 == nil) goto v352;
    v183 = stack[0];
    v183 = qcdr(v183);
    v183 = qcar(v183);
    stack[0] = v183;
    goto v11;

v352:
    v256 = v210;
    v183 = elt(env, 12); /* times */
    if (v256 == v183) goto v486;
    v183 = nil;
    { popv(3); return onevalue(v183); }

v486:
    v183 = stack[0];
    v183 = qcdr(v183);
    {
        popv(3);
        fn = elt(env, 13); /* deg!*farg */
        return (*qfn1(fn))(qenv(fn), v183);
    }

v186:
    stack[-1] = (Lisp_Object)-15; /* -1 */
    v183 = stack[0];
    v183 = qcdr(v183);
    v183 = qcdr(v183);
    v183 = qcar(v183);
    v183 = CC_degHform(env, v183);
    nil = C_nil;
    if (exception_pending()) goto v248;
    env = stack[-2];
    {
        Lisp_Object v224 = stack[-1];
        popv(3);
        fn = elt(env, 14); /* addd */
        return (*qfn2(fn))(qenv(fn), v224, v183);
    }

v77:
    v183 = stack[0];
    v183 = qcdr(v183);
    v183 = qcdr(v183);
    v183 = qcar(v183);
    stack[0] = v183;
    goto v11;

v233:
    v183 = stack[0];
    v183 = qcdr(v183);
    v183 = qcdr(v183);
    if (v183 == nil) goto v147;
    v183 = nil;
    { popv(3); return onevalue(v183); }

v147:
    v183 = (Lisp_Object)-15; /* -1 */
    { popv(3); return onevalue(v183); }

v118:
    stack[-1] = qvalue(elt(env, 7)); /* dimex!* */
    v183 = stack[0];
    v183 = qcdr(v183);
    v183 = qcar(v183);
    v183 = CC_degHform(env, v183);
    nil = C_nil;
    if (exception_pending()) goto v248;
    env = stack[-2];
    fn = elt(env, 15); /* negf */
    v183 = (*qfn1(fn))(qenv(fn), v183);
    nil = C_nil;
    if (exception_pending()) goto v248;
    env = stack[-2];
    {
        Lisp_Object v350 = stack[-1];
        popv(3);
        fn = elt(env, 16); /* addf */
        return (*qfn2(fn))(qenv(fn), v350, v183);
    }

v112:
    stack[-1] = (Lisp_Object)17; /* 1 */
    v183 = stack[0];
    v183 = qcdr(v183);
    v183 = qcar(v183);
    v183 = CC_degHform(env, v183);
    nil = C_nil;
    if (exception_pending()) goto v248;
    env = stack[-2];
    {
        Lisp_Object v478 = stack[-1];
        popv(3);
        fn = elt(env, 14); /* addd */
        return (*qfn2(fn))(qenv(fn), v478, v183);
    }

v57:
    v183 = stack[0];
    v183 = qcdr(v183);
    {
        popv(3);
        fn = elt(env, 13); /* deg!*farg */
        return (*qfn1(fn))(qenv(fn), v183);
    }

v5:
    v256 = stack[0];
    v183 = elt(env, 1); /* fdegree */
    v183 = get(v256, v183);
    v256 = v183;
    v183 = v256;
    if (v183 == nil) goto v15;
    v183 = v256;
    v183 = qcar(v183);
    { popv(3); return onevalue(v183); }

v15:
    v183 = nil;
    { popv(3); return onevalue(v183); }
/* error exit handlers */
v248:
    popv(3);
    return nil;
}



/* Code for !:difference */

static Lisp_Object CC_Tdifference(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v35, v34, v39, v40;
    Lisp_Object fn;
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v39 = v16;
    v40 = v0;
/* end of prologue */
    v35 = v40;
    if (v35 == nil) goto v4;
    v35 = v39;
    if (v35 == nil) return onevalue(v40);
    v34 = v40;
    v35 = v39;
    if (equal(v34, v35)) goto v25;
    v35 = v40;
    if (!(!consp(v35))) goto v37;
    v35 = v39;
    if (!(!consp(v35))) goto v37;
    v35 = v40;
    v34 = v39;
    return difference2(v35, v34);

v37:
    v34 = v40;
    v35 = elt(env, 1); /* difference */
    {
        fn = elt(env, 2); /* dcombine */
        return (*qfnn(fn))(qenv(fn), 3, v34, v39, v35);
    }

v25:
    v35 = nil;
    return onevalue(v35);

v4:
    v35 = v39;
    {
        fn = elt(env, 3); /* !:minus */
        return (*qfn1(fn))(qenv(fn), v35);
    }
}



/* Code for vecopp */

static Lisp_Object CC_vecopp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v150, v134, v105;
    Lisp_Object fn;
    if (stack >= stacklimit)
    {
        push(v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v134 = v0;
/* end of prologue */
    v150 = v134;
    if (symbolp(v150)) goto v28;
    v150 = nil;
    goto v12;

v12:
    if (!(v150 == nil)) { popv(1); return onevalue(v150); }
    v150 = v134;
    if (!consp(v150)) goto v21;
    v150 = v134;
    v105 = qcar(v150);
    v150 = elt(env, 1); /* phystype */
    v105 = get(v105, v150);
    env = stack[0];
    v150 = elt(env, 2); /* vector */
    if (v105 == v150) goto v34;
    v150 = nil;
    { popv(1); return onevalue(v150); }

v34:
    v150 = v134;
    v150 = qcdr(v150);
    v150 = qcar(v150);
    fn = elt(env, 3); /* isanindex */
    v150 = (*qfn1(fn))(qenv(fn), v150);
    nil = C_nil;
    if (exception_pending()) goto v69;
    v150 = (v150 == nil ? lisp_true : nil);
    { popv(1); return onevalue(v150); }

v21:
    v150 = nil;
    { popv(1); return onevalue(v150); }

v28:
    v105 = v134;
    v150 = elt(env, 1); /* phystype */
    v105 = get(v105, v150);
    env = stack[0];
    v150 = elt(env, 2); /* vector */
    v150 = (v105 == v150 ? lisp_true : nil);
    goto v12;
/* error exit handlers */
v69:
    popv(1);
    return nil;
}



/* Code for red!-weight */

static Lisp_Object CC_redKweight(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v28, v38;
    Lisp_Object fn;
    if (stack >= stacklimit)
    {
        push2(v16,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v16);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v16;
    stack[-1] = v0;
/* end of prologue */
    v28 = stack[-1];
    fn = elt(env, 1); /* nonzero!-length */
    stack[-2] = (*qfn1(fn))(qenv(fn), v28);
    nil = C_nil;
    if (exception_pending()) goto v43;
    env = stack[-3];
    v38 = stack[-1];
    v28 = stack[0];
    fn = elt(env, 2); /* red!-weight1 */
    v28 = (*qfn2(fn))(qenv(fn), v38, v28);
    nil = C_nil;
    if (exception_pending()) goto v43;
    {
        Lisp_Object v29 = stack[-2];
        popv(4);
        return cons(v29, v28);
    }
/* error exit handlers */
v43:
    popv(4);
    return nil;
}



/* Code for divd */

static Lisp_Object CC_divd(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v144, v191, v192;
    Lisp_Object fn;
    if (stack >= stacklimit)
    {
        push2(v16,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v16);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v16;
    stack[-2] = v0;
/* end of prologue */
    stack[-3] = nil;
    goto v12;

v12:
    v144 = stack[-1];
    if (v144 == nil) goto v6;
    v144 = stack[-2];
    if (v144 == nil) goto v206;
    v144 = stack[-2];
    if (!consp(v144)) goto v66;
    v144 = stack[-2];
    v144 = qcar(v144);
    if (!consp(v144)) goto v66;
    v144 = stack[-2];
    v144 = qcar(v144);
    stack[0] = qcar(v144);
    v144 = stack[-2];
    v144 = qcar(v144);
    v191 = qcdr(v144);
    v144 = stack[-1];
    v191 = CC_divd(env, v191, v144);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-4];
    v144 = stack[-3];
    v144 = acons(stack[0], v191, v144);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-4];
    stack[-3] = v144;
    v144 = stack[-2];
    v144 = qcdr(v144);
    stack[-2] = v144;
    goto v12;

v66:
    stack[0] = stack[-3];
    v191 = stack[-2];
    v144 = stack[-1];
    fn = elt(env, 4); /* divdm */
    v144 = (*qfn2(fn))(qenv(fn), v191, v144);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-4];
    {
        Lisp_Object v119 = stack[0];
        popv(5);
        fn = elt(env, 5); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v119, v144);
    }

v206:
    v144 = stack[-3];
    {
        popv(5);
        fn = elt(env, 5); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v144);
    }

v6:
    v144 = stack[-2];
    if (v144 == nil) goto v27;
    stack[0] = stack[-3];
    v192 = elt(env, 1); /* poly */
    v191 = (Lisp_Object)33; /* 2 */
    v144 = elt(env, 3); /* "Zero divisor" */
    fn = elt(env, 6); /* rerror */
    v144 = (*qfnn(fn))(qenv(fn), 3, v192, v191, v144);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-4];
    {
        Lisp_Object v98 = stack[0];
        popv(5);
        fn = elt(env, 5); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v98, v144);
    }

v27:
    stack[0] = stack[-3];
    v192 = elt(env, 1); /* poly */
    v191 = (Lisp_Object)17; /* 1 */
    v144 = elt(env, 2); /* "0/0 formed" */
    fn = elt(env, 6); /* rerror */
    v144 = (*qfnn(fn))(qenv(fn), 3, v192, v191, v144);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-4];
    {
        Lisp_Object v117 = stack[0];
        popv(5);
        fn = elt(env, 5); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v117, v144);
    }
/* error exit handlers */
v135:
    popv(5);
    return nil;
}



/* Code for dp_term */

static Lisp_Object CC_dp_term(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v8, v1;
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v8 = v16;
    v1 = v0;
/* end of prologue */
    return cons(v8, v1);
}



/* Code for gperm2 */

static Lisp_Object MS_CDECL CC_gperm2(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v16,
                         Lisp_Object v63, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v37, v36, v48, v33;
    Lisp_Object fn;
    argcheck(nargs, 3, "gperm2");
    if (stack >= stacklimit)
    {
        push3(v63,v16,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v16,v63);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v63;
    stack[-1] = v16;
    v37 = v0;
/* end of prologue */

v45:
    v36 = v37;
    if (v36 == nil) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v36 = v37;
    v36 = qcdr(v36);
    stack[-2] = v36;
    v36 = qcar(v37);
    v37 = nil;
    fn = elt(env, 1); /* rev */
    v33 = (*qfn2(fn))(qenv(fn), v36, v37);
    nil = C_nil;
    if (exception_pending()) goto v50;
    env = stack[-3];
    v48 = stack[-1];
    v36 = nil;
    v37 = stack[0];
    fn = elt(env, 2); /* gperm1 */
    v37 = (*qfnn(fn))(qenv(fn), 4, v33, v48, v36, v37);
    nil = C_nil;
    if (exception_pending()) goto v50;
    env = stack[-3];
    stack[0] = v37;
    v37 = stack[-2];
    goto v45;
/* error exit handlers */
v50:
    popv(4);
    return nil;
}



/* Code for times!-in!-vector */

static Lisp_Object MS_CDECL CC_timesKinKvector(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v16,
                         Lisp_Object v63, Lisp_Object v9,
                         Lisp_Object v3, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v127, v186, v187, v88, v89, v90, v108, v94, v212, v462, v123, v124, v125, v473, v474;
    argcheck(nargs, 5, "times-in-vector");
    if (stack >= stacklimit)
    {
        push5(v3,v9,v63,v16,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v0,v16,v63,v9,v3);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v462 = v3;
    v123 = v9;
    v124 = v63;
    v125 = v16;
    v473 = v0;
/* end of prologue */
    v186 = v125;
    v127 = (Lisp_Object)1; /* 0 */
    if (((int32)(v186)) < ((int32)(v127))) goto v2;
    v186 = v123;
    v127 = (Lisp_Object)1; /* 0 */
    if (((int32)(v186)) < ((int32)(v127))) goto v2;
    v186 = v125;
    v127 = v123;
    v127 = (Lisp_Object)(int32)((int32)v186 + (int32)v127 - TAG_FIXNUM);
    v474 = v127;
    v127 = (Lisp_Object)1; /* 0 */
    v88 = v127;
    goto v52;

v52:
    v186 = v474;
    v127 = v88;
    v127 = (Lisp_Object)(int32)((int32)v186 - (int32)v127 + TAG_FIXNUM);
    v127 = ((intxx)(v127) < 0 ? lisp_true : nil);
    if (v127 == nil) goto v150;
    v127 = (Lisp_Object)1; /* 0 */
    v94 = v127;
    goto v60;

v60:
    v186 = v125;
    v127 = v94;
    v127 = (Lisp_Object)(int32)((int32)v186 - (int32)v127 + TAG_FIXNUM);
    v127 = ((intxx)(v127) < 0 ? lisp_true : nil);
    if (!(v127 == nil)) { popv(1); return onevalue(v474); }
    v186 = v473;
    v127 = v94;
    v127 = *(Lisp_Object *)((char *)v186 + (CELL-TAG_VECTOR) + ((int32)v127/(16/CELL)));
    v212 = v127;
    v127 = (Lisp_Object)1; /* 0 */
    v108 = v127;
    goto v143;

v143:
    v186 = v123;
    v127 = v108;
    v127 = (Lisp_Object)(int32)((int32)v186 - (int32)v127 + TAG_FIXNUM);
    v127 = ((intxx)(v127) < 0 ? lisp_true : nil);
    if (v127 == nil) goto v98;
    v127 = v94;
    v127 = (Lisp_Object)((int32)(v127) + 0x10);
    v94 = v127;
    goto v60;

v98:
    v186 = v94;
    v127 = v108;
    v127 = (Lisp_Object)(int32)((int32)v186 + (int32)v127 - TAG_FIXNUM);
    v90 = v462;
    v89 = v127;
    v186 = v462;
    v88 = *(Lisp_Object *)((char *)v186 + (CELL-TAG_VECTOR) + ((int32)v127/(16/CELL)));
    v187 = v212;
    v186 = v124;
    v127 = v108;
    v127 = *(Lisp_Object *)((char *)v186 + (CELL-TAG_VECTOR) + ((int32)v127/(16/CELL)));
    v127 = Lmodular_times(nil, v187, v127);
    env = stack[0];
    {   int32 w = int_of_fixnum(v88) + int_of_fixnum(v127);
        if (w >= current_modulus) w -= current_modulus;
        v127 = fixnum_of_int(w);
    }
    *(Lisp_Object *)((char *)v90 + (CELL-TAG_VECTOR) + ((int32)v89/(16/CELL))) = v127;
    v127 = v108;
    v127 = (Lisp_Object)((int32)(v127) + 0x10);
    v108 = v127;
    goto v143;

v150:
    v187 = v462;
    v186 = v88;
    v127 = (Lisp_Object)1; /* 0 */
    *(Lisp_Object *)((char *)v187 + (CELL-TAG_VECTOR) + ((int32)v186/(16/CELL))) = v127;
    v127 = v88;
    v127 = (Lisp_Object)((int32)(v127) + 0x10);
    v88 = v127;
    goto v52;

v2:
    v127 = (Lisp_Object)-15; /* -1 */
    { popv(1); return onevalue(v127); }
}



/* Code for ptoken */

static Lisp_Object MS_CDECL CC_ptoken(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v39, v40;
    Lisp_Object fn;
    argcheck(nargs, 0, "ptoken");
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* end of prologue */
    fn = elt(env, 5); /* token */
    v39 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v41;
    env = stack[-1];
    stack[0] = v39;
    v40 = stack[0];
    v39 = elt(env, 1); /* !) */
    if (!(v40 == v39)) goto v12;
    v40 = qvalue(elt(env, 2)); /* outl!* */
    v39 = elt(env, 3); /* !  */
    if (!consp(v40)) goto v12;
    v40 = qcar(v40);
    if (!(v40 == v39)) goto v12;
    v39 = qvalue(elt(env, 2)); /* outl!* */
    v39 = qcdr(v39);
    qvalue(elt(env, 2)) = v39; /* outl!* */
    goto v12;

v12:
    v39 = stack[0];
    fn = elt(env, 6); /* prin2x */
    v39 = (*qfn1(fn))(qenv(fn), v39);
    nil = C_nil;
    if (exception_pending()) goto v41;
    env = stack[-1];
    v40 = stack[0];
    v39 = elt(env, 4); /* !( */
    if (v40 == v39) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v40 = stack[0];
    v39 = elt(env, 1); /* !) */
    if (v40 == v39) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v39 = elt(env, 3); /* !  */
    fn = elt(env, 6); /* prin2x */
    v39 = (*qfn1(fn))(qenv(fn), v39);
    nil = C_nil;
    if (exception_pending()) goto v41;
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
/* error exit handlers */
v41:
    popv(2);
    return nil;
}



/* Code for vdpgetprop */

static Lisp_Object CC_vdpgetprop(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v54, v87, v66, v70;
    Lisp_Object fn;
    if (stack >= stacklimit)
    {
        push2(v16,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v16);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    v66 = v16;
    v70 = v0;
/* end of prologue */
    v54 = v70;
    if (v54 == nil) goto v4;
    v87 = v70;
    v54 = elt(env, 1); /* vdp */
    if (!consp(v87)) goto v38;
    v87 = qcar(v87);
    if (!(v87 == v54)) goto v38;
    v54 = v66;
    v87 = v70;
    v87 = qcdr(v87);
    v87 = qcdr(v87);
    v87 = qcdr(v87);
    v87 = qcdr(v87);
    v87 = qcar(v87);
    v54 = Lassoc(nil, v54, v87);
    v87 = v54;
    v54 = v87;
    if (v54 == nil) goto v67;
    v54 = v87;
    v54 = qcdr(v54);
    { popv(3); return onevalue(v54); }

v67:
    v54 = nil;
    { popv(3); return onevalue(v54); }

v38:
    stack[-1] = elt(env, 2); /* dipoly */
    stack[0] = (Lisp_Object)113; /* 7 */
    v54 = elt(env, 3); /* "vdpgetprop given a non-vdp as 1st parameter" */
    v87 = v70;
    v54 = list3(v54, v87, v66);
    nil = C_nil;
    if (exception_pending()) goto v57;
    env = stack[-2];
    {
        Lisp_Object v72 = stack[-1];
        Lisp_Object v122 = stack[0];
        popv(3);
        fn = elt(env, 4); /* rerror */
        return (*qfnn(fn))(qenv(fn), 3, v72, v122, v54);
    }

v4:
    v54 = nil;
    { popv(3); return onevalue(v54); }
/* error exit handlers */
v57:
    popv(3);
    return nil;
}



/* Code for areallindices */

static Lisp_Object CC_areallindices(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v44;
    Lisp_Object fn;
    if (stack >= stacklimit)
    {
        push(v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v0;
/* end of prologue */

v11:
    v44 = stack[0];
    v44 = qcar(v44);
    fn = elt(env, 1); /* isanindex */
    v44 = (*qfn1(fn))(qenv(fn), v44);
    nil = C_nil;
    if (exception_pending()) goto v15;
    env = stack[-1];
    if (v44 == nil) goto v3;
    v44 = stack[0];
    v44 = qcdr(v44);
    v44 = (v44 == nil ? lisp_true : nil);
    if (!(v44 == nil)) { popv(2); return onevalue(v44); }
    v44 = stack[0];
    v44 = qcdr(v44);
    stack[0] = v44;
    goto v11;

v3:
    v44 = nil;
    { popv(2); return onevalue(v44); }
/* error exit handlers */
v15:
    popv(2);
    return nil;
}



/* Code for contrsp2 */

static Lisp_Object MS_CDECL CC_contrsp2(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v16,
                         Lisp_Object v63, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v105, v69;
    argcheck(nargs, 3, "contrsp2");
    if (stack >= stacklimit)
    {
        push3(v63,v16,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v16,v63);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v63;
    stack[-1] = v16;
    stack[-2] = v0;
/* end of prologue */
    stack[-3] = (Lisp_Object)33; /* 2 */
    v105 = stack[-2];
    v105 = Llength(nil, v105);
    nil = C_nil;
    if (exception_pending()) goto v87;
    if (stack[-3] == v105) goto v38;
    v105 = nil;
    { popv(4); return onevalue(v105); }

v38:
    v69 = stack[0];
    v105 = stack[-2];
    v105 = qcar(v105);
    if (equal(v69, v105)) goto v20;
    v69 = stack[0];
    v105 = stack[-2];
    v105 = qcdr(v105);
    v105 = qcar(v105);
    if (equal(v69, v105)) goto v193;
    v105 = nil;
    { popv(4); return onevalue(v105); }

v193:
    v105 = stack[-2];
    v69 = qcar(v105);
    v105 = stack[-1];
    popv(4);
    return cons(v69, v105);

v20:
    v105 = stack[-2];
    v105 = qcdr(v105);
    v69 = qcar(v105);
    v105 = stack[-1];
    popv(4);
    return cons(v69, v105);
/* error exit handlers */
v87:
    popv(4);
    return nil;
}



/* Code for mo!=deglist */

static Lisp_Object CC_moMdeglist(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v327, v79;
    Lisp_Object fn;
    if (stack >= stacklimit)
    {
        push(v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-4] = v0;
/* end of prologue */
    v327 = stack[-4];
    if (v327 == nil) goto v3;
    v327 = stack[-4];
    v79 = qcar(v327);
    v327 = qvalue(elt(env, 2)); /* cali!=degrees */
    v327 = Lassoc(nil, v79, v327);
    stack[-5] = v327;
    v327 = qvalue(elt(env, 1)); /* cali!=basering */
    fn = elt(env, 3); /* ring_degrees */
    v327 = (*qfn1(fn))(qenv(fn), v327);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-6];
    stack[-3] = v327;
    v327 = stack[-3];
    if (v327 == nil) goto v55;
    v327 = stack[-3];
    v327 = qcar(v327);
    v79 = stack[-4];
    v79 = qcdr(v79);
    fn = elt(env, 4); /* mo!=sprod */
    v327 = (*qfn2(fn))(qenv(fn), v79, v327);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-6];
    v327 = ncons(v327);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-6];
    stack[-1] = v327;
    stack[-2] = v327;
    goto v101;

v101:
    v327 = stack[-3];
    v327 = qcdr(v327);
    stack[-3] = v327;
    v327 = stack[-3];
    if (v327 == nil) goto v96;
    stack[0] = stack[-1];
    v327 = stack[-3];
    v327 = qcar(v327);
    v79 = stack[-4];
    v79 = qcdr(v79);
    fn = elt(env, 4); /* mo!=sprod */
    v327 = (*qfn2(fn))(qenv(fn), v79, v327);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-6];
    v327 = ncons(v327);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-6];
    v327 = Lrplacd(nil, stack[0], v327);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-6];
    v327 = stack[-1];
    v327 = qcdr(v327);
    stack[-1] = v327;
    goto v101;

v96:
    v327 = stack[-2];
    v79 = v327;
    goto v67;

v67:
    v327 = stack[-5];
    if (v327 == nil) goto v137;
    v327 = stack[-5];
    v327 = qcdr(v327);
    v327 = qcdr(v327);
    goto v68;

v68:
    {
        popv(7);
        fn = elt(env, 5); /* mo!=sum */
        return (*qfn2(fn))(qenv(fn), v79, v327);
    }

v137:
    v327 = nil;
    goto v68;

v55:
    v327 = nil;
    v79 = v327;
    goto v67;

v3:
    v327 = qvalue(elt(env, 1)); /* cali!=basering */
    fn = elt(env, 3); /* ring_degrees */
    v327 = (*qfn1(fn))(qenv(fn), v327);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-6];
    stack[-3] = v327;
    v327 = stack[-3];
    if (v327 == nil) goto v26;
    v327 = (Lisp_Object)1; /* 0 */
    v327 = ncons(v327);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-6];
    stack[-1] = v327;
    stack[-2] = v327;
    goto v1;

v1:
    v327 = stack[-3];
    v327 = qcdr(v327);
    stack[-3] = v327;
    v327 = stack[-3];
    if (v327 == nil) { Lisp_Object res = stack[-2]; popv(7); return onevalue(res); }
    stack[0] = stack[-1];
    v327 = (Lisp_Object)1; /* 0 */
    v327 = ncons(v327);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-6];
    v327 = Lrplacd(nil, stack[0], v327);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-6];
    v327 = stack[-1];
    v327 = qcdr(v327);
    stack[-1] = v327;
    goto v1;

v26:
    v327 = nil;
    { popv(7); return onevalue(v327); }
/* error exit handlers */
v147:
    popv(7);
    return nil;
}



/* Code for pdmult */

static Lisp_Object CC_pdmult(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v261, v180;
    Lisp_Object fn;
    if (stack >= stacklimit)
    {
        push2(v16,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v16);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-8] = v16;
    v261 = v0;
/* end of prologue */
    stack[-9] = v261;
    v261 = stack[-9];
    if (v261 == nil) goto v1;
    v261 = stack[-9];
    v261 = qcar(v261);
    stack[-4] = v261;
    v261 = stack[-4];
    v180 = qcar(v261);
    v261 = stack[-8];
    fn = elt(env, 1); /* pair */
    v261 = (*qfn2(fn))(qenv(fn), v180, v261);
    nil = C_nil;
    if (exception_pending()) goto v257;
    env = stack[-10];
    stack[-3] = v261;
    v261 = stack[-3];
    if (v261 == nil) goto v48;
    v261 = stack[-3];
    v261 = qcar(v261);
    v180 = v261;
    v180 = qcar(v180);
    v261 = qcdr(v261);
    v261 = (Lisp_Object)(int32)((int32)v180 + (int32)v261 - TAG_FIXNUM);
    v261 = ncons(v261);
    nil = C_nil;
    if (exception_pending()) goto v257;
    env = stack[-10];
    stack[-1] = v261;
    stack[-2] = v261;
    goto v22;

v22:
    v261 = stack[-3];
    v261 = qcdr(v261);
    stack[-3] = v261;
    v261 = stack[-3];
    if (v261 == nil) goto v56;
    stack[0] = stack[-1];
    v261 = stack[-3];
    v261 = qcar(v261);
    v180 = v261;
    v180 = qcar(v180);
    v261 = qcdr(v261);
    v261 = (Lisp_Object)(int32)((int32)v180 + (int32)v261 - TAG_FIXNUM);
    v261 = ncons(v261);
    nil = C_nil;
    if (exception_pending()) goto v257;
    env = stack[-10];
    v261 = Lrplacd(nil, stack[0], v261);
    nil = C_nil;
    if (exception_pending()) goto v257;
    env = stack[-10];
    v261 = stack[-1];
    v261 = qcdr(v261);
    stack[-1] = v261;
    goto v22;

v56:
    v261 = stack[-2];
    v180 = v261;
    goto v15;

v15:
    v261 = stack[-4];
    v261 = qcdr(v261);
    v261 = cons(v180, v261);
    nil = C_nil;
    if (exception_pending()) goto v257;
    env = stack[-10];
    v261 = ncons(v261);
    nil = C_nil;
    if (exception_pending()) goto v257;
    env = stack[-10];
    stack[-6] = v261;
    stack[-7] = v261;
    goto v5;

v5:
    v261 = stack[-9];
    v261 = qcdr(v261);
    stack[-9] = v261;
    v261 = stack[-9];
    if (v261 == nil) { Lisp_Object res = stack[-7]; popv(11); return onevalue(res); }
    stack[-5] = stack[-6];
    v261 = stack[-9];
    v261 = qcar(v261);
    stack[-4] = v261;
    v261 = stack[-4];
    v180 = qcar(v261);
    v261 = stack[-8];
    fn = elt(env, 1); /* pair */
    v261 = (*qfn2(fn))(qenv(fn), v180, v261);
    nil = C_nil;
    if (exception_pending()) goto v257;
    env = stack[-10];
    stack[-3] = v261;
    v261 = stack[-3];
    if (v261 == nil) goto v80;
    v261 = stack[-3];
    v261 = qcar(v261);
    v180 = v261;
    v180 = qcar(v180);
    v261 = qcdr(v261);
    v261 = (Lisp_Object)(int32)((int32)v180 + (int32)v261 - TAG_FIXNUM);
    v261 = ncons(v261);
    nil = C_nil;
    if (exception_pending()) goto v257;
    env = stack[-10];
    stack[-1] = v261;
    stack[-2] = v261;
    goto v136;

v136:
    v261 = stack[-3];
    v261 = qcdr(v261);
    stack[-3] = v261;
    v261 = stack[-3];
    if (v261 == nil) goto v92;
    stack[0] = stack[-1];
    v261 = stack[-3];
    v261 = qcar(v261);
    v180 = v261;
    v180 = qcar(v180);
    v261 = qcdr(v261);
    v261 = (Lisp_Object)(int32)((int32)v180 + (int32)v261 - TAG_FIXNUM);
    v261 = ncons(v261);
    nil = C_nil;
    if (exception_pending()) goto v257;
    env = stack[-10];
    v261 = Lrplacd(nil, stack[0], v261);
    nil = C_nil;
    if (exception_pending()) goto v257;
    env = stack[-10];
    v261 = stack[-1];
    v261 = qcdr(v261);
    stack[-1] = v261;
    goto v136;

v92:
    v261 = stack[-2];
    v180 = v261;
    goto v119;

v119:
    v261 = stack[-4];
    v261 = qcdr(v261);
    v261 = cons(v180, v261);
    nil = C_nil;
    if (exception_pending()) goto v257;
    env = stack[-10];
    v261 = ncons(v261);
    nil = C_nil;
    if (exception_pending()) goto v257;
    env = stack[-10];
    v261 = Lrplacd(nil, stack[-5], v261);
    nil = C_nil;
    if (exception_pending()) goto v257;
    env = stack[-10];
    v261 = stack[-6];
    v261 = qcdr(v261);
    stack[-6] = v261;
    goto v5;

v80:
    v261 = nil;
    v180 = v261;
    goto v119;

v48:
    v261 = nil;
    v180 = v261;
    goto v15;

v1:
    v261 = nil;
    { popv(11); return onevalue(v261); }
/* error exit handlers */
v257:
    popv(11);
    return nil;
}



/* Code for aronep!: */

static Lisp_Object CC_aronepT(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v8, v1;
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v8 = v0;
/* end of prologue */
    v1 = qcdr(v8);
    v8 = (Lisp_Object)17; /* 1 */
    v8 = (v1 == v8 ? lisp_true : nil);
    return onevalue(v8);
}



/* Code for clear!-column */

static Lisp_Object MS_CDECL CC_clearKcolumn(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v16,
                         Lisp_Object v63, Lisp_Object v9, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v340, v260, v441, v491, v320, v495, v496, v424;
    argcheck(nargs, 4, "clear-column");
    if (stack >= stacklimit)
    {
        push4(v9,v63,v16,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v16,v63,v9);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-1] = v9;
    stack[-2] = v63;
    stack[-3] = v16;
    stack[-4] = v0;
/* end of prologue */
    v340 = (Lisp_Object)1; /* 0 */
    v260 = v340;
    goto v17;

v17:
    v441 = stack[-2];
    v340 = v260;
    v441 = *(Lisp_Object *)((char *)v441 + (CELL-TAG_VECTOR) + ((int32)v340/(16/CELL)));
    v340 = stack[-4];
    v441 = *(Lisp_Object *)((char *)v441 + (CELL-TAG_VECTOR) + ((int32)v340/(16/CELL)));
    v340 = (Lisp_Object)1; /* 0 */
    if (v441 == v340) goto v57;
    v441 = v260;
    v340 = stack[-4];
    if (!(((int32)(v441)) < ((int32)(v340)))) goto v107;
    v441 = stack[-2];
    v340 = v260;
    v441 = *(Lisp_Object *)((char *)v441 + (CELL-TAG_VECTOR) + ((int32)v340/(16/CELL)));
    v340 = v260;
    v441 = *(Lisp_Object *)((char *)v441 + (CELL-TAG_VECTOR) + ((int32)v340/(16/CELL)));
    v340 = (Lisp_Object)1; /* 0 */
    if (!(v441 == v340)) goto v57;

v107:
    v441 = stack[-2];
    v340 = v260;
    v340 = *(Lisp_Object *)((char *)v441 + (CELL-TAG_VECTOR) + ((int32)v340/(16/CELL)));
    stack[-5] = v340;
    v491 = stack[-2];
    v441 = v260;
    v260 = stack[-2];
    v340 = stack[-4];
    v340 = *(Lisp_Object *)((char *)v260 + (CELL-TAG_VECTOR) + ((int32)v340/(16/CELL)));
    *(Lisp_Object *)((char *)v491 + (CELL-TAG_VECTOR) + ((int32)v441/(16/CELL))) = v340;
    v441 = stack[-2];
    v260 = stack[-4];
    v340 = stack[-5];
    *(Lisp_Object *)((char *)v441 + (CELL-TAG_VECTOR) + ((int32)v260/(16/CELL))) = v340;
    v260 = stack[-2];
    v340 = stack[-4];
    v260 = *(Lisp_Object *)((char *)v260 + (CELL-TAG_VECTOR) + ((int32)v340/(16/CELL)));
    v340 = stack[-4];
    v340 = *(Lisp_Object *)((char *)v260 + (CELL-TAG_VECTOR) + ((int32)v340/(16/CELL)));
    v340 = Lmodular_reciprocal(nil, v340);
    nil = C_nil;
    if (exception_pending()) goto v339;
    env = stack[-6];
    {   int32 w = int_of_fixnum(v340);
        if (w != 0) w = current_modulus - w;
        v340 = fixnum_of_int(w);
    }
    stack[-5] = v340;
    v340 = (Lisp_Object)1; /* 0 */
    stack[0] = v340;
    goto v216;

v216:
    v260 = stack[-1];
    v340 = stack[0];
    v340 = (Lisp_Object)(int32)((int32)v260 - (int32)v340 + TAG_FIXNUM);
    v340 = ((intxx)(v340) < 0 ? lisp_true : nil);
    if (v340 == nil) goto v461;
    v340 = stack[-4];
    v320 = v340;
    goto v302;

v302:
    v260 = stack[-1];
    v340 = v320;
    v340 = (Lisp_Object)(int32)((int32)v260 - (int32)v340 + TAG_FIXNUM);
    v340 = ((intxx)(v340) < 0 ? lisp_true : nil);
    if (!(v340 == nil)) { Lisp_Object res = stack[-3]; popv(7); return onevalue(res); }
    v260 = stack[-2];
    v340 = stack[-4];
    v491 = *(Lisp_Object *)((char *)v260 + (CELL-TAG_VECTOR) + ((int32)v340/(16/CELL)));
    v441 = v320;
    v260 = stack[-2];
    v340 = stack[-4];
    v260 = *(Lisp_Object *)((char *)v260 + (CELL-TAG_VECTOR) + ((int32)v340/(16/CELL)));
    v340 = v320;
    v260 = *(Lisp_Object *)((char *)v260 + (CELL-TAG_VECTOR) + ((int32)v340/(16/CELL)));
    v340 = stack[-5];
    v340 = Lmodular_times(nil, v260, v340);
    env = stack[-6];
    *(Lisp_Object *)((char *)v491 + (CELL-TAG_VECTOR) + ((int32)v441/(16/CELL))) = v340;
    v340 = v320;
    v340 = (Lisp_Object)((int32)(v340) + 0x10);
    v320 = v340;
    goto v302;

v461:
    v260 = stack[0];
    v340 = stack[-4];
    v340 = Lneq(nil, v260, v340);
    nil = C_nil;
    if (exception_pending()) goto v339;
    env = stack[-6];
    if (v340 == nil) goto v110;
    v260 = stack[-2];
    v340 = stack[0];
    v260 = *(Lisp_Object *)((char *)v260 + (CELL-TAG_VECTOR) + ((int32)v340/(16/CELL)));
    v340 = stack[-4];
    v340 = *(Lisp_Object *)((char *)v260 + (CELL-TAG_VECTOR) + ((int32)v340/(16/CELL)));
    v424 = v340;
    v260 = v424;
    v340 = (Lisp_Object)1; /* 0 */
    if (v260 == v340) goto v110;
    v260 = v424;
    v340 = stack[-5];
    v340 = Lmodular_times(nil, v260, v340);
    env = stack[-6];
    v424 = v340;
    v340 = stack[-4];
    v496 = v340;
    goto v316;

v316:
    v260 = stack[-1];
    v340 = v496;
    v340 = (Lisp_Object)(int32)((int32)v260 - (int32)v340 + TAG_FIXNUM);
    v340 = ((intxx)(v340) < 0 ? lisp_true : nil);
    if (!(v340 == nil)) goto v110;
    v260 = stack[-2];
    v340 = stack[0];
    v495 = *(Lisp_Object *)((char *)v260 + (CELL-TAG_VECTOR) + ((int32)v340/(16/CELL)));
    v320 = v496;
    v260 = stack[-2];
    v340 = stack[0];
    v260 = *(Lisp_Object *)((char *)v260 + (CELL-TAG_VECTOR) + ((int32)v340/(16/CELL)));
    v340 = v496;
    v491 = *(Lisp_Object *)((char *)v260 + (CELL-TAG_VECTOR) + ((int32)v340/(16/CELL)));
    v441 = v424;
    v260 = stack[-2];
    v340 = stack[-4];
    v260 = *(Lisp_Object *)((char *)v260 + (CELL-TAG_VECTOR) + ((int32)v340/(16/CELL)));
    v340 = v496;
    v340 = *(Lisp_Object *)((char *)v260 + (CELL-TAG_VECTOR) + ((int32)v340/(16/CELL)));
    v340 = Lmodular_times(nil, v441, v340);
    env = stack[-6];
    {   int32 w = int_of_fixnum(v491) + int_of_fixnum(v340);
        if (w >= current_modulus) w -= current_modulus;
        v340 = fixnum_of_int(w);
    }
    *(Lisp_Object *)((char *)v495 + (CELL-TAG_VECTOR) + ((int32)v320/(16/CELL))) = v340;
    v340 = v496;
    v340 = (Lisp_Object)((int32)(v340) + 0x10);
    v496 = v340;
    goto v316;

v110:
    v340 = stack[0];
    v340 = (Lisp_Object)((int32)(v340) + 0x10);
    stack[0] = v340;
    goto v216;

v57:
    v340 = v260;
    v441 = (Lisp_Object)((int32)(v340) + 0x10);
    v260 = v441;
    v340 = stack[-1];
    if (!(((int32)(v441)) > ((int32)(v340)))) goto v17;
    v260 = stack[-4];
    v340 = stack[-3];
    popv(7);
    return cons(v260, v340);
/* error exit handlers */
v339:
    popv(7);
    return nil;
}



/* Code for termordp */

static Lisp_Object CC_termordp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v2;
    Lisp_Object fn;
    if (stack >= stacklimit)
    {
        push2(v16,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v16);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v16;
    v2 = v0;
/* end of prologue */
    fn = elt(env, 1); /* wedgefax */
    stack[-1] = (*qfn1(fn))(qenv(fn), v2);
    nil = C_nil;
    if (exception_pending()) goto v24;
    env = stack[-2];
    v2 = stack[0];
    fn = elt(env, 1); /* wedgefax */
    v2 = (*qfn1(fn))(qenv(fn), v2);
    nil = C_nil;
    if (exception_pending()) goto v24;
    env = stack[-2];
    {
        Lisp_Object v26 = stack[-1];
        popv(3);
        fn = elt(env, 2); /* monordp */
        return (*qfn2(fn))(qenv(fn), v26, v2);
    }
/* error exit handlers */
v24:
    popv(3);
    return nil;
}



/* Code for cut!:ep */

static Lisp_Object CC_cutTep(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v102, v95;
    Lisp_Object fn;
    if (stack >= stacklimit)
    {
        push2(v16,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v16);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v16;
    stack[-2] = v0;
/* end of prologue */
    v95 = stack[-2];
    v102 = elt(env, 1); /* !:rd!: */
    if (!consp(v95)) goto v65;
    v95 = qcar(v95);
    if (!(v95 == v102)) goto v65;
    v102 = stack[-2];
    v102 = qcdr(v102);
    if (!consp(v102)) goto v65;
    v102 = stack[-1];
    v102 = integerp(v102);
    if (v102 == nil) goto v65;
    v95 = stack[-1];
    v102 = stack[-2];
    v102 = qcdr(v102);
    v102 = qcdr(v102);
    v95 = difference2(v95, v102);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-4];
    stack[-1] = v95;
    v102 = (Lisp_Object)1; /* 0 */
    v102 = (Lisp_Object)lesseq2(v95, v102);
    nil = C_nil;
    if (exception_pending()) goto v85;
    v102 = v102 ? lisp_true : nil;
    env = stack[-4];
    if (!(v102 == nil)) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    stack[-3] = elt(env, 1); /* !:rd!: */
    v102 = stack[-2];
    v102 = qcdr(v102);
    stack[0] = qcar(v102);
    v102 = stack[-1];
    v102 = negate(v102);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-4];
    stack[0] = Lash1(nil, stack[0], v102);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-4];
    v102 = stack[-2];
    v102 = qcdr(v102);
    v95 = qcdr(v102);
    v102 = stack[-1];
    v102 = plus2(v95, v102);
    nil = C_nil;
    if (exception_pending()) goto v85;
    {
        Lisp_Object v86 = stack[-3];
        Lisp_Object v104 = stack[0];
        popv(5);
        return list2star(v86, v104, v102);
    }

v65:
    v102 = elt(env, 0); /* cut!:ep */
    {
        popv(5);
        fn = elt(env, 2); /* bflerrmsg */
        return (*qfn1(fn))(qenv(fn), v102);
    }
/* error exit handlers */
v85:
    popv(5);
    return nil;
}



/* Code for getphystype */

static Lisp_Object CC_getphystype(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v82, v81;
    Lisp_Object fn;
    if (stack >= stacklimit)
    {
        push(v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0;
/* end of prologue */
    v82 = stack[0];
    fn = elt(env, 8); /* physopp */
    v82 = (*qfn1(fn))(qenv(fn), v82);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-2];
    if (v82 == nil) goto v5;
    v82 = stack[0];
    fn = elt(env, 9); /* scalopp */
    v82 = (*qfn1(fn))(qenv(fn), v82);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-2];
    if (v82 == nil) goto v25;
    v82 = elt(env, 1); /* scalar */
    { popv(3); return onevalue(v82); }

v25:
    v82 = stack[0];
    fn = elt(env, 10); /* vecopp */
    v82 = (*qfn1(fn))(qenv(fn), v82);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-2];
    if (v82 == nil) goto v28;
    v82 = elt(env, 2); /* vector */
    { popv(3); return onevalue(v82); }

v28:
    v82 = stack[0];
    fn = elt(env, 11); /* tensopp */
    v82 = (*qfn1(fn))(qenv(fn), v82);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-2];
    if (v82 == nil) goto v43;
    v82 = elt(env, 3); /* tensor */
    { popv(3); return onevalue(v82); }

v43:
    v82 = stack[0];
    fn = elt(env, 12); /* statep */
    v82 = (*qfn1(fn))(qenv(fn), v82);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-2];
    if (v82 == nil) goto v30;
    v82 = elt(env, 4); /* state */
    { popv(3); return onevalue(v82); }

v30:
    v82 = nil;
    { popv(3); return onevalue(v82); }

v5:
    v82 = stack[0];
    if (!consp(v82)) goto v53;
    v82 = stack[0];
    v81 = qcar(v82);
    v82 = elt(env, 5); /* phystype */
    v81 = get(v81, v82);
    env = stack[-2];
    v82 = v81;
    if (!(v81 == nil)) { popv(3); return onevalue(v82); }
    v82 = stack[0];
    v81 = qcar(v82);
    v82 = elt(env, 6); /* phystypefn */
    v81 = get(v81, v82);
    env = stack[-2];
    v82 = v81;
    if (v81 == nil) goto v39;
    v81 = v82;
    v82 = stack[0];
    v82 = qcdr(v82);
        popv(3);
        return Lapply1(nil, v81, v82);

v39:
    v82 = stack[0];
    fn = elt(env, 13); /* collectphystype */
    v81 = (*qfn1(fn))(qenv(fn), v82);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-2];
    v82 = v81;
    if (v81 == nil) goto v57;
    v81 = v82;
    v81 = qcdr(v81);
    if (v81 == nil) goto v65;
    v81 = elt(env, 4); /* state */
    v82 = Lmember(nil, v81, v82);
    if (v82 == nil) goto v96;
    v82 = elt(env, 4); /* state */
    { popv(3); return onevalue(v82); }

v96:
    stack[-1] = elt(env, 0); /* getphystype */
    v81 = elt(env, 7); /* "PHYSOP type conflict in" */
    v82 = stack[0];
    v82 = list2(v81, v82);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-2];
    {
        Lisp_Object v119 = stack[-1];
        popv(3);
        fn = elt(env, 14); /* rederr2 */
        return (*qfn2(fn))(qenv(fn), v119, v82);
    }

v65:
    v82 = qcar(v82);
    { popv(3); return onevalue(v82); }

v57:
    v82 = nil;
    { popv(3); return onevalue(v82); }

v53:
    v82 = nil;
    { popv(3); return onevalue(v82); }
/* error exit handlers */
v135:
    popv(3);
    return nil;
}



/* Code for red!-weight1 */

static Lisp_Object CC_redKweight1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v206, v41;
    if (stack >= stacklimit)
    {
        push2(v16,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v16);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v16;
    stack[-1] = v0;
/* end of prologue */
    stack[-2] = nil;
    goto v45;

v45:
    v206 = stack[-1];
    if (v206 == nil) goto v5;
    v206 = stack[-1];
    v206 = qcar(v206);
    v41 = Labsval(nil, v206);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-3];
    v206 = stack[0];
    v206 = qcar(v206);
    v41 = times2(v41, v206);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-3];
    v206 = stack[-2];
    v206 = cons(v41, v206);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-3];
    stack[-2] = v206;
    v206 = stack[-1];
    v206 = qcdr(v206);
    stack[-1] = v206;
    v206 = stack[0];
    v206 = qcdr(v206);
    stack[0] = v206;
    goto v45;

v5:
    v206 = (Lisp_Object)1; /* 0 */
    v41 = v206;
    goto v6;

v6:
    v206 = stack[-2];
    if (v206 == nil) { popv(4); return onevalue(v41); }
    v206 = stack[-2];
    v206 = qcar(v206);
    v206 = plus2(v206, v41);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-3];
    v41 = v206;
    v206 = stack[-2];
    v206 = qcdr(v206);
    stack[-2] = v206;
    goto v6;
/* error exit handlers */
v134:
    popv(4);
    return nil;
}



/* Code for sc_kern */

static Lisp_Object CC_sc_kern(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v25;
    if (stack >= stacklimit)
    {
        push(v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v25 = v0;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* g_sc_ve */
    v25 = sub1(v25);
    nil = C_nil;
    if (exception_pending()) goto v24;
    v25 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32)v25/(16/CELL)));
    v25 = qcdr(v25);
    v25 = qcdr(v25);
    v25 = qcar(v25);
    { popv(1); return onevalue(v25); }
/* error exit handlers */
v24:
    popv(1);
    return nil;
}



/* Code for rnplus!: */

static Lisp_Object CC_rnplusT(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v35, v34;
    Lisp_Object fn;
    if (stack >= stacklimit)
    {
        push2(v16,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v16);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v16;
    stack[-1] = v0;
/* end of prologue */
    v35 = stack[-1];
    v35 = qcdr(v35);
    v34 = qcar(v35);
    v35 = stack[0];
    v35 = qcdr(v35);
    v35 = qcdr(v35);
    stack[-2] = times2(v34, v35);
    nil = C_nil;
    if (exception_pending()) goto v41;
    env = stack[-3];
    v35 = stack[-1];
    v35 = qcdr(v35);
    v34 = qcdr(v35);
    v35 = stack[0];
    v35 = qcdr(v35);
    v35 = qcar(v35);
    v35 = times2(v34, v35);
    nil = C_nil;
    if (exception_pending()) goto v41;
    env = stack[-3];
    stack[-2] = plus2(stack[-2], v35);
    nil = C_nil;
    if (exception_pending()) goto v41;
    env = stack[-3];
    v35 = stack[-1];
    v35 = qcdr(v35);
    v34 = qcdr(v35);
    v35 = stack[0];
    v35 = qcdr(v35);
    v35 = qcdr(v35);
    v35 = times2(v34, v35);
    nil = C_nil;
    if (exception_pending()) goto v41;
    env = stack[-3];
    {
        Lisp_Object v64 = stack[-2];
        popv(4);
        fn = elt(env, 1); /* mkrn */
        return (*qfn2(fn))(qenv(fn), v64, v35);
    }
/* error exit handlers */
v41:
    popv(4);
    return nil;
}



/* Code for general!-times!-term!-mod!-p */

static Lisp_Object CC_generalKtimesKtermKmodKp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v232, v127, v186;
    Lisp_Object fn;
    if (stack >= stacklimit)
    {
        push2(v16,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v16);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v16;
    stack[-2] = v0;
/* end of prologue */
    v232 = stack[-1];
    if (v232 == nil) goto v4;
    v232 = stack[-1];
    if (!consp(v232)) goto v26;
    v232 = stack[-1];
    v232 = qcar(v232);
    if (!consp(v232)) goto v26;
    v232 = stack[-2];
    v232 = qcar(v232);
    v127 = qcar(v232);
    v232 = stack[-1];
    v232 = qcar(v232);
    v232 = qcar(v232);
    v232 = qcar(v232);
    if (equal(v127, v232)) goto v150;
    v232 = stack[-2];
    v232 = qcar(v232);
    v127 = qcar(v232);
    v232 = stack[-1];
    v232 = qcar(v232);
    v232 = qcar(v232);
    v232 = qcar(v232);
    fn = elt(env, 1); /* ordop */
    v232 = (*qfn2(fn))(qenv(fn), v127, v232);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-4];
    if (v232 == nil) goto v114;
    v232 = stack[-2];
    stack[0] = qcar(v232);
    v232 = stack[-2];
    v127 = qcdr(v232);
    v232 = stack[-1];
    fn = elt(env, 2); /* general!-times!-mod!-p */
    v127 = (*qfn2(fn))(qenv(fn), v127, v232);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-4];
    v232 = nil;
    {
        Lisp_Object v94 = stack[0];
        popv(5);
        fn = elt(env, 3); /* adjoin!-term */
        return (*qfnn(fn))(qenv(fn), 3, v94, v127, v232);
    }

v114:
    v232 = stack[-1];
    v232 = qcar(v232);
    stack[-3] = qcar(v232);
    v127 = stack[-2];
    v232 = stack[-1];
    v232 = qcar(v232);
    v232 = qcdr(v232);
    stack[0] = CC_generalKtimesKtermKmodKp(env, v127, v232);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-4];
    v127 = stack[-2];
    v232 = stack[-1];
    v232 = qcdr(v232);
    v232 = CC_generalKtimesKtermKmodKp(env, v127, v232);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-4];
    {
        Lisp_Object v212 = stack[-3];
        Lisp_Object v462 = stack[0];
        popv(5);
        fn = elt(env, 3); /* adjoin!-term */
        return (*qfnn(fn))(qenv(fn), 3, v212, v462, v232);
    }

v150:
    v232 = stack[-2];
    v232 = qcar(v232);
    v186 = qcar(v232);
    v232 = stack[-2];
    v232 = qcar(v232);
    v127 = qcdr(v232);
    v232 = stack[-1];
    v232 = qcar(v232);
    v232 = qcar(v232);
    v232 = qcdr(v232);
    v232 = (Lisp_Object)(int32)((int32)v127 + (int32)v232 - TAG_FIXNUM);
    fn = elt(env, 4); /* mksp */
    stack[-3] = (*qfn2(fn))(qenv(fn), v186, v232);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-4];
    v232 = stack[-2];
    v127 = qcdr(v232);
    v232 = stack[-1];
    v232 = qcar(v232);
    v232 = qcdr(v232);
    fn = elt(env, 2); /* general!-times!-mod!-p */
    stack[0] = (*qfn2(fn))(qenv(fn), v127, v232);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-4];
    v127 = stack[-2];
    v232 = stack[-1];
    v232 = qcdr(v232);
    v232 = CC_generalKtimesKtermKmodKp(env, v127, v232);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-4];
    {
        Lisp_Object v123 = stack[-3];
        Lisp_Object v124 = stack[0];
        popv(5);
        fn = elt(env, 3); /* adjoin!-term */
        return (*qfnn(fn))(qenv(fn), 3, v123, v124, v232);
    }

v26:
    v232 = stack[-2];
    stack[0] = qcar(v232);
    v232 = stack[-2];
    v127 = qcdr(v232);
    v232 = stack[-1];
    fn = elt(env, 5); /* gen!-mult!-by!-const!-mod!-p */
    v127 = (*qfn2(fn))(qenv(fn), v127, v232);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-4];
    v232 = nil;
    {
        Lisp_Object v125 = stack[0];
        popv(5);
        fn = elt(env, 3); /* adjoin!-term */
        return (*qfnn(fn))(qenv(fn), 3, v125, v127, v232);
    }

v4:
    v232 = nil;
    { popv(5); return onevalue(v232); }
/* error exit handlers */
v108:
    popv(5);
    return nil;
}



/* Code for xdegreemon */

static Lisp_Object CC_xdegreemon(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v42, v49, v50;
    Lisp_Object fn;
    if (stack >= stacklimit)
    {
        push(v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v49 = v0;
/* end of prologue */
    v42 = qvalue(elt(env, 1)); /* xdegreelist!* */
    if (v42 == nil) goto v3;
    v42 = v49;
    stack[0] = v42;
    v42 = (Lisp_Object)1; /* 0 */
    v50 = v42;
    goto v24;

v24:
    v42 = stack[0];
    if (v42 == nil) { popv(2); return onevalue(v50); }
    v42 = stack[0];
    v42 = qcar(v42);
    v49 = v42;
    v42 = qvalue(elt(env, 1)); /* xdegreelist!* */
    v42 = Latsoc(nil, v49, v42);
    v42 = qcdr(v42);
    v49 = v50;
    v42 = plus2(v42, v49);
    nil = C_nil;
    if (exception_pending()) goto v193;
    env = stack[-1];
    v50 = v42;
    v42 = stack[0];
    v42 = qcdr(v42);
    stack[0] = v42;
    goto v24;

v3:
    v42 = v49;
    fn = elt(env, 2); /* mknwedge */
    v42 = (*qfn1(fn))(qenv(fn), v42);
    nil = C_nil;
    if (exception_pending()) goto v193;
    env = stack[-1];
    {
        popv(2);
        fn = elt(env, 3); /* xdegree */
        return (*qfn1(fn))(qenv(fn), v42);
    }
/* error exit handlers */
v193:
    popv(2);
    return nil;
}



/* Code for make!-set */

static Lisp_Object CC_makeKset(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v8, v1;
    Lisp_Object fn;
    if (stack >= stacklimit)
    {
        push(v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v8 = v0;
/* end of prologue */
    v1 = v8;
    v8 = elt(env, 1); /* set!-ordp */
    fn = elt(env, 2); /* sort */
    v8 = (*qfn2(fn))(qenv(fn), v1, v8);
    nil = C_nil;
    if (exception_pending()) goto v2;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 3); /* makelist */
        return (*qfn1(fn))(qenv(fn), v8);
    }
/* error exit handlers */
v2:
    popv(1);
    return nil;
}



/* Code for contr1!-strand */

static Lisp_Object CC_contr1Kstrand(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v26, v27, v28, v38;
    Lisp_Object fn;
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v26 = v16;
    v27 = v0;
/* end of prologue */
    v38 = v27;
    v28 = v26;
    v27 = nil;
    v26 = nil;
    {
        fn = elt(env, 1); /* contr2!-strand */
        return (*qfnn(fn))(qenv(fn), 4, v38, v28, v27, v26);
    }
}



/* Code for mv!-pow!-minusp */

static Lisp_Object CC_mvKpowKminusp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v29, v17;
    if (stack >= stacklimit)
    {
        push(v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v0;
/* end of prologue */

v11:
    v29 = stack[0];
    if (v29 == nil) goto v3;
    v29 = stack[0];
    v17 = qcar(v29);
    v29 = (Lisp_Object)1; /* 0 */
    v29 = (Lisp_Object)lessp2(v17, v29);
    nil = C_nil;
    if (exception_pending()) goto v19;
    v29 = v29 ? lisp_true : nil;
    env = stack[-1];
    if (!(v29 == nil)) { popv(2); return onevalue(v29); }
    v29 = stack[0];
    v29 = qcdr(v29);
    stack[0] = v29;
    goto v11;

v3:
    v29 = nil;
    { popv(2); return onevalue(v29); }
/* error exit handlers */
v19:
    popv(2);
    return nil;
}



/* Code for bas_make1 */

static Lisp_Object MS_CDECL CC_bas_make1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v16,
                         Lisp_Object v63, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v18, v19;
    Lisp_Object fn;
    argcheck(nargs, 3, "bas_make1");
    if (stack >= stacklimit)
    {
        push3(v63,v16,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v16,v63);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v63;
    stack[-3] = v16;
    v18 = v0;
/* end of prologue */
    stack[-4] = v18;
    stack[-1] = stack[-3];
    v18 = stack[-3];
    stack[0] = Llength(nil, v18);
    nil = C_nil;
    if (exception_pending()) goto v99;
    env = stack[-5];
    v18 = stack[-3];
    fn = elt(env, 1); /* dp_ecart */
    v19 = (*qfn1(fn))(qenv(fn), v18);
    nil = C_nil;
    if (exception_pending()) goto v99;
    env = stack[-5];
    v18 = stack[-2];
    v18 = list2(v19, v18);
    nil = C_nil;
    if (exception_pending()) goto v99;
    {
        Lisp_Object v10 = stack[-4];
        Lisp_Object v53 = stack[-1];
        Lisp_Object v14 = stack[0];
        popv(6);
        return list3star(v10, v53, v14, v18);
    }
/* error exit handlers */
v99:
    popv(6);
    return nil;
}



/* Code for general!-modular!-quotient */

static Lisp_Object CC_generalKmodularKquotient(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v1, v2;
    Lisp_Object fn;
    if (stack >= stacklimit)
    {
        push2(v16,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v16);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v1 = v16;
    v2 = v0;
/* end of prologue */
    stack[0] = v2;
    fn = elt(env, 1); /* general!-modular!-reciprocal */
    v1 = (*qfn1(fn))(qenv(fn), v1);
    nil = C_nil;
    if (exception_pending()) goto v13;
    env = stack[-1];
    {
        Lisp_Object v24 = stack[0];
        popv(2);
        fn = elt(env, 2); /* general!-modular!-times */
        return (*qfn2(fn))(qenv(fn), v24, v1);
    }
/* error exit handlers */
v13:
    popv(2);
    return nil;
}



/* Code for bcsum */

static Lisp_Object CC_bcsum(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v36, v48, v33;
    Lisp_Object fn;
    if (stack >= stacklimit)
    {
        push2(v16,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v16);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v16;
    stack[-1] = v0;
/* end of prologue */
    v36 = qvalue(elt(env, 1)); /* !*grmod!* */
    if (v36 == nil) goto v15;
    v48 = stack[-1];
    v36 = stack[0];
    v36 = plus2(v48, v36);
    nil = C_nil;
    if (exception_pending()) goto v49;
    env = stack[-2];
    {
        popv(3);
        fn = elt(env, 3); /* bcfi */
        return (*qfn1(fn))(qenv(fn), v36);
    }

v15:
    v33 = stack[-1];
    v48 = stack[0];
    v36 = elt(env, 2); /* plus2 */
    fn = elt(env, 4); /* bcint2op */
    v36 = (*qfnn(fn))(qenv(fn), 3, v33, v48, v36);
    nil = C_nil;
    if (exception_pending()) goto v49;
    env = stack[-2];
    if (!(v36 == nil)) { popv(3); return onevalue(v36); }
    v48 = stack[-1];
    v36 = stack[0];
    fn = elt(env, 5); /* addsq */
    v36 = (*qfn2(fn))(qenv(fn), v48, v36);
    nil = C_nil;
    if (exception_pending()) goto v49;
    env = stack[-2];
    {
        popv(3);
        fn = elt(env, 6); /* bccheckz */
        return (*qfn1(fn))(qenv(fn), v36);
    }
/* error exit handlers */
v49:
    popv(3);
    return nil;
}



/* Code for convchk */

static Lisp_Object CC_convchk(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v150, v134, v105;
    Lisp_Object fn;
    if (stack >= stacklimit)
    {
        push(v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v150 = v0;
/* end of prologue */
    v134 = qvalue(elt(env, 1)); /* !*!*roundbf */
    if (v134 == nil) goto v4;
    v134 = v150;
    if (!(!consp(v134))) { popv(1); return onevalue(v150); }
    v134 = v150;
    v134 = Lfloatp(nil, v134);
    env = stack[0];
    if (v134 == nil) goto v38;
    {
        popv(1);
        fn = elt(env, 3); /* fl2bf */
        return (*qfn1(fn))(qenv(fn), v150);
    }

v38:
    v134 = v150;
    if (!(!consp(v134))) goto v43;
    v134 = v150;
    v134 = integerp(v134);
    if (v134 == nil) goto v33;
    v105 = elt(env, 2); /* !:rd!: */
    v134 = v150;
    v150 = (Lisp_Object)1; /* 0 */
    v150 = list2star(v105, v134, v150);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[0];
    goto v43;

v43:
    {
        popv(1);
        fn = elt(env, 4); /* csl_normbf */
        return (*qfn1(fn))(qenv(fn), v150);
    }

v33:
    fn = elt(env, 5); /* read!:num */
    v150 = (*qfn1(fn))(qenv(fn), v150);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[0];
    goto v43;

v4:
    v134 = v150;
    if (!consp(v134)) { popv(1); return onevalue(v150); }
    {
        popv(1);
        fn = elt(env, 6); /* bf2flck */
        return (*qfn1(fn))(qenv(fn), v150);
    }
/* error exit handlers */
v69:
    popv(1);
    return nil;
}



/* Code for optype */

static Lisp_Object CC_optype(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v7, v8;
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v7 = v0;
/* end of prologue */
    v8 = elt(env, 1); /* !*optype!* */
    return get(v7, v8);
}



/* Code for !*q2a */

static Lisp_Object CC_Hq2a(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v7, v8;
    Lisp_Object fn;
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v7 = v0;
/* end of prologue */
    v8 = v7;
    v7 = qvalue(elt(env, 1)); /* !*nosq */
    {
        fn = elt(env, 2); /* !*q2a1 */
        return (*qfn2(fn))(qenv(fn), v8, v7);
    }
}



/* Code for mv!-pow!-mv!-term!-!+ */

static Lisp_Object CC_mvKpowKmvKtermKL(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v38, v44;
    Lisp_Object fn;
    if (stack >= stacklimit)
    {
        push2(v16,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v16);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v16;
    v38 = v0;
/* end of prologue */
    v44 = v38;
    v38 = stack[0];
    v38 = qcar(v38);
    fn = elt(env, 1); /* mv!-pow!-!+ */
    v44 = (*qfn2(fn))(qenv(fn), v44, v38);
    nil = C_nil;
    if (exception_pending()) goto v15;
    v38 = stack[0];
    v38 = qcdr(v38);
    popv(1);
    return cons(v44, v38);
/* error exit handlers */
v15:
    popv(1);
    return nil;
}



/* Code for dp_ecart */

static Lisp_Object CC_dp_ecart(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v44;
    Lisp_Object fn;
    if (stack >= stacklimit)
    {
        push(v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0;
/* end of prologue */
    v44 = stack[0];
    if (v44 == nil) goto v3;
    v44 = stack[0];
    fn = elt(env, 1); /* dp!=ecart */
    stack[-1] = (*qfn1(fn))(qenv(fn), v44);
    nil = C_nil;
    if (exception_pending()) goto v43;
    env = stack[-2];
    v44 = stack[0];
    fn = elt(env, 2); /* dp_lmon */
    v44 = (*qfn1(fn))(qenv(fn), v44);
    nil = C_nil;
    if (exception_pending()) goto v43;
    env = stack[-2];
    fn = elt(env, 3); /* mo_ecart */
    v44 = (*qfn1(fn))(qenv(fn), v44);
    nil = C_nil;
    if (exception_pending()) goto v43;
    {
        Lisp_Object v29 = stack[-1];
        popv(3);
        return difference2(v29, v44);
    }

v3:
    v44 = (Lisp_Object)1; /* 0 */
    { popv(3); return onevalue(v44); }
/* error exit handlers */
v43:
    popv(3);
    return nil;
}



setup_type const u11_setup[] =
{
    {"pv_applp",                too_few_2,      CC_pv_applp,   wrong_no_2},
    {"rntimes:",                too_few_2,      CC_rntimesT,   wrong_no_2},
    {"*modular2f",              CC_Hmodular2f,  too_many_1,    wrong_no_1},
    {"divide:",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_divideT},
    {"mkwedge",                 CC_mkwedge,     too_many_1,    wrong_no_1},
    {"noncommutingf",           too_few_2,      CC_noncommutingf,wrong_no_2},
    {"mo=lexcomp",              too_few_2,      CC_moMlexcomp, wrong_no_2},
    {"insert_pv1",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_insert_pv1},
    {"mod#",                    CC_modC,        too_many_1,    wrong_no_1},
    {"convprec*",               CC_convprecH,   too_many_1,    wrong_no_1},
    {"physopp*",                CC_physoppH,    too_many_1,    wrong_no_1},
    {"red_divtestbe",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_red_divtestbe},
    {"gperm1",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_gperm1},
    {"deg*farg",                CC_degHfarg,    too_many_1,    wrong_no_1},
    {"abs:",                    CC_absT,        too_many_1,    wrong_no_1},
    {"dp_diff",                 too_few_2,      CC_dp_diff,    wrong_no_2},
    {"pv_sort2a",               too_few_2,      CC_pv_sort2a,  wrong_no_2},
    {"modplus:",                too_few_2,      CC_modplusT,   wrong_no_2},
    {"mkgi",                    too_few_2,      CC_mkgi,       wrong_no_2},
    {"evcompless?",             too_few_2,      CC_evcomplessW,wrong_no_2},
    {"rd:zerop",                CC_rdTzerop,    too_many_1,    wrong_no_1},
    {"red-char-downcase",       CC_redKcharKdowncase,too_many_1,wrong_no_1},
    {"dp_times_bc",             too_few_2,      CC_dp_times_bc,wrong_no_2},
    {"tsym4",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_tsym4},
    {"diplength",               CC_diplength,   too_many_1,    wrong_no_1},
    {"mknwedge",                CC_mknwedge,    too_many_1,    wrong_no_1},
    {"worderp",                 too_few_2,      CC_worderp,    wrong_no_2},
    {"rd:onep",                 CC_rdTonep,     too_many_1,    wrong_no_1},
    {"getphystype*sq",          CC_getphystypeHsq,too_many_1,  wrong_no_1},
    {"groeb=testa",             too_few_2,      CC_groebMtesta,wrong_no_2},
    {"gperm",                   CC_gperm,       too_many_1,    wrong_no_1},
    {"minus-mod-p",             CC_minusKmodKp, too_many_1,    wrong_no_1},
    {"xdegree",                 CC_xdegree,     too_many_1,    wrong_no_1},
    {"boundindp",               too_few_2,      CC_boundindp,  wrong_no_2},
    {"dp_sum",                  too_few_2,      CC_dp_sum,     wrong_no_2},
    {"pappl_pv",                too_few_2,      CC_pappl_pv,   wrong_no_2},
    {"arzerop:",                CC_arzeropT,    too_many_1,    wrong_no_1},
    {"general-plus-mod-p",      too_few_2,      CC_generalKplusKmodKp,wrong_no_2},
    {"gsetsugar",               too_few_2,      CC_gsetsugar,  wrong_no_2},
    {"deg*form",                CC_degHform,    too_many_1,    wrong_no_1},
    {":difference",             too_few_2,      CC_Tdifference,wrong_no_2},
    {"vecopp",                  CC_vecopp,      too_many_1,    wrong_no_1},
    {"red-weight",              too_few_2,      CC_redKweight, wrong_no_2},
    {"divd",                    too_few_2,      CC_divd,       wrong_no_2},
    {"dp_term",                 too_few_2,      CC_dp_term,    wrong_no_2},
    {"gperm2",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_gperm2},
    {"times-in-vector",         wrong_no_na,    wrong_no_nb,   (n_args *)CC_timesKinKvector},
    {"ptoken",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_ptoken},
    {"vdpgetprop",              too_few_2,      CC_vdpgetprop, wrong_no_2},
    {"areallindices",           CC_areallindices,too_many_1,   wrong_no_1},
    {"contrsp2",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_contrsp2},
    {"mo=deglist",              CC_moMdeglist,  too_many_1,    wrong_no_1},
    {"pdmult",                  too_few_2,      CC_pdmult,     wrong_no_2},
    {"aronep:",                 CC_aronepT,     too_many_1,    wrong_no_1},
    {"clear-column",            wrong_no_na,    wrong_no_nb,   (n_args *)CC_clearKcolumn},
    {"termordp",                too_few_2,      CC_termordp,   wrong_no_2},
    {"cut:ep",                  too_few_2,      CC_cutTep,     wrong_no_2},
    {"getphystype",             CC_getphystype, too_many_1,    wrong_no_1},
    {"red-weight1",             too_few_2,      CC_redKweight1,wrong_no_2},
    {"sc_kern",                 CC_sc_kern,     too_many_1,    wrong_no_1},
    {"rnplus:",                 too_few_2,      CC_rnplusT,    wrong_no_2},
    {"general-times-term-mod-p",too_few_2,      CC_generalKtimesKtermKmodKp,wrong_no_2},
    {"xdegreemon",              CC_xdegreemon,  too_many_1,    wrong_no_1},
    {"make-set",                CC_makeKset,    too_many_1,    wrong_no_1},
    {"contr1-strand",           too_few_2,      CC_contr1Kstrand,wrong_no_2},
    {"mv-pow-minusp",           CC_mvKpowKminusp,too_many_1,   wrong_no_1},
    {"bas_make1",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_bas_make1},
    {"general-modular-quotient",too_few_2,      CC_generalKmodularKquotient,wrong_no_2},
    {"bcsum",                   too_few_2,      CC_bcsum,      wrong_no_2},
    {"convchk",                 CC_convchk,     too_many_1,    wrong_no_1},
    {"optype",                  CC_optype,      too_many_1,    wrong_no_1},
    {"*q2a",                    CC_Hq2a,        too_many_1,    wrong_no_1},
    {"mv-pow-mv-term-+",        too_few_2,      CC_mvKpowKmvKtermKL,wrong_no_2},
    {"dp_ecart",                CC_dp_ecart,    too_many_1,    wrong_no_1},
    {NULL, (one_args *)"u11", (two_args *)"13677 4569936 9763889", 0}
};

/* end of generated code */
