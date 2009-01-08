
/* $srcdir/../csl-c\u12.c Machine generated C code */

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


/* Code for psum */

static Lisp_Object CC_psum(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v90, v108, v94;
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
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-5] = v16;
    stack[-6] = v0;
/* end of prologue */
    stack[-3] = nil;
    stack[-2] = nil;
    stack[-1] = nil;
    v90 = stack[-6];
    if (v90 == nil) goto v25;
    v90 = stack[-5];
    if (!(v90 == nil)) goto v17;
    v90 = stack[-6];
    stack[-2] = v90;
    { Lisp_Object res = stack[-2]; popv(9); return onevalue(res); }

v17:
    v90 = stack[-5];
    if (v90 == nil) { Lisp_Object res = stack[-2]; popv(9); return onevalue(res); }
    v90 = stack[-1];
    if (!(v90 == nil)) { Lisp_Object res = stack[-2]; popv(9); return onevalue(res); }
    v90 = stack[-5];
    v90 = qcar(v90);
    stack[0] = v90;
    v90 = stack[0];
    v90 = qcar(v90);
    stack[-7] = v90;
    goto v36;

v36:
    v90 = stack[-6];
    if (v90 == nil) goto v37;
    v108 = stack[-7];
    v90 = stack[-6];
    v90 = qcar(v90);
    v90 = qcar(v90);
    fn = elt(env, 1); /* dless */
    v90 = (*qfn2(fn))(qenv(fn), v108, v90);
    nil = C_nil;
    if (exception_pending()) goto v211;
    env = stack[-8];
    if (v90 == nil) goto v37;
    v90 = stack[-6];
    v108 = qcar(v90);
    v90 = stack[-3];
    v90 = cons(v108, v90);
    nil = C_nil;
    if (exception_pending()) goto v211;
    env = stack[-8];
    stack[-3] = v90;
    v90 = stack[-6];
    v90 = qcdr(v90);
    stack[-6] = v90;
    goto v36;

v37:
    v90 = stack[-6];
    if (v90 == nil) goto v103;
    v90 = stack[-6];
    v90 = qcar(v90);
    v94 = v90;
    v108 = stack[-7];
    v90 = v94;
    v90 = qcar(v90);
    if (equal(v108, v90)) goto v84;
    v108 = stack[0];
    v90 = stack[-3];
    v90 = cons(v108, v90);
    nil = C_nil;
    if (exception_pending()) goto v211;
    env = stack[-8];
    stack[-3] = v90;
    goto v128;

v128:
    v90 = stack[-5];
    v90 = qcdr(v90);
    stack[-5] = v90;
    v90 = stack[-5];
    if (!(v90 == nil)) goto v17;
    v90 = stack[-3];
    v108 = Lreverse(nil, v90);
    nil = C_nil;
    if (exception_pending()) goto v211;
    env = stack[-8];
    v90 = stack[-6];
    v90 = Lappend(nil, v108, v90);
    nil = C_nil;
    if (exception_pending()) goto v211;
    env = stack[-8];
    stack[-2] = v90;
    goto v17;

v84:
    v90 = v94;
    v108 = qcdr(v90);
    v90 = stack[0];
    v90 = qcdr(v90);
    fn = elt(env, 2); /* csum */
    v90 = (*qfn2(fn))(qenv(fn), v108, v90);
    nil = C_nil;
    if (exception_pending()) goto v211;
    env = stack[-8];
    stack[-4] = v90;
    stack[0] = stack[-4];
    fn = elt(env, 3); /* c_zero */
    v90 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v211;
    env = stack[-8];
    v90 = Lneq(nil, stack[0], v90);
    nil = C_nil;
    if (exception_pending()) goto v211;
    env = stack[-8];
    if (v90 == nil) goto v118;
    v94 = stack[-7];
    v108 = stack[-4];
    v90 = stack[-3];
    v90 = acons(v94, v108, v90);
    nil = C_nil;
    if (exception_pending()) goto v211;
    env = stack[-8];
    stack[-3] = v90;
    goto v118;

v118:
    v90 = stack[-6];
    v90 = qcdr(v90);
    stack[-6] = v90;
    v90 = stack[-6];
    if (v90 == nil) goto v128;
    else goto v128;

v103:
    v90 = stack[-3];
    v108 = Lreverse(nil, v90);
    nil = C_nil;
    if (exception_pending()) goto v211;
    env = stack[-8];
    v90 = stack[-5];
    v90 = Lappend(nil, v108, v90);
    nil = C_nil;
    if (exception_pending()) goto v211;
    env = stack[-8];
    stack[-2] = v90;
    v90 = lisp_true;
    stack[-1] = v90;
    goto v17;

v25:
    v90 = stack[-5];
    stack[-2] = v90;
    { Lisp_Object res = stack[-2]; popv(9); return onevalue(res); }
/* error exit handlers */
v211:
    popv(9);
    return nil;
}



/* Code for adddummy1a */

static Lisp_Object MS_CDECL CC_adddummy1a(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v16,
                         Lisp_Object v63, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v69, v67;
    Lisp_Object fn;
    argcheck(nargs, 3, "adddummy1a");
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
    stack[-1] = v63;
    v69 = v16;
    stack[-2] = v0;
/* end of prologue */

v45:
    v67 = v69;
    if (v67 == nil) { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }
    v67 = v69;
    v67 = qcdr(v67);
    stack[-3] = v67;
    v67 = stack[-1];
    if (v67 == nil) goto v17;
    v67 = stack[-1];
    v67 = qcar(v67);
    stack[0] = v67;
    goto v36;

v36:
    v67 = qcar(v69);
    v69 = stack[-2];
    v69 = qcdr(v69);
    fn = elt(env, 1); /* pappl_pv */
    v67 = (*qfn2(fn))(qenv(fn), v67, v69);
    nil = C_nil;
    if (exception_pending()) goto v66;
    env = stack[-4];
    v69 = stack[-1];
    if (v69 == nil) goto v39;
    v69 = stack[-1];
    v69 = qcdr(v69);
    goto v31;

v31:
    fn = elt(env, 2); /* insert_pv */
    v69 = (*qfn2(fn))(qenv(fn), v67, v69);
    nil = C_nil;
    if (exception_pending()) goto v66;
    env = stack[-4];
    v69 = cons(stack[0], v69);
    nil = C_nil;
    if (exception_pending()) goto v66;
    env = stack[-4];
    stack[-1] = v69;
    v69 = stack[-3];
    goto v45;

v39:
    v69 = stack[-1];
    goto v31;

v17:
    v67 = stack[-2];
    v67 = qcar(v67);
    stack[0] = v67;
    goto v36;
/* error exit handlers */
v66:
    popv(5);
    return nil;
}



/* Code for gizerop!: */

static Lisp_Object CC_gizeropT(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v19, v20, v21;
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v20 = v0;
/* end of prologue */
    v19 = v20;
    v19 = qcdr(v19);
    v21 = qcar(v19);
    v19 = (Lisp_Object)1; /* 0 */
    if (v21 == v19) goto v27;
    v19 = nil;
    return onevalue(v19);

v27:
    v19 = v20;
    v19 = qcdr(v19);
    v20 = qcdr(v19);
    v19 = (Lisp_Object)1; /* 0 */
    v19 = (v20 == v19 ? lisp_true : nil);
    return onevalue(v19);
}



/* Code for dim!<deg */

static Lisp_Object CC_dimRdeg(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v19, v20;
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
    v19 = v0;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* dimex!* */
    fn = elt(env, 2); /* deg!*farg */
    v19 = (*qfn1(fn))(qenv(fn), v19);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-1];
    fn = elt(env, 3); /* negf */
    v19 = (*qfn1(fn))(qenv(fn), v19);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-1];
    fn = elt(env, 4); /* addf */
    v19 = (*qfn2(fn))(qenv(fn), stack[0], v19);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-1];
    v20 = v19;
    v19 = v20;
    if (!(is_number(v19))) goto v29;
    v19 = v20;
    v19 = Lminusp(nil, v19);
    if (v19 == nil) goto v29;
    v19 = lisp_true;
    { popv(2); return onevalue(v19); }

v29:
    v19 = nil;
    { popv(2); return onevalue(v19); }
/* error exit handlers */
v22:
    popv(2);
    return nil;
}



/* Code for lessp!: */

static Lisp_Object CC_lesspT(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v8, v1;
    Lisp_Object fn;
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v1 = v16;
    v8 = v0;
/* end of prologue */
    {
        fn = elt(env, 1); /* greaterp!: */
        return (*qfn2(fn))(qenv(fn), v1, v8);
    }
}



/* Code for mv!-pow!-!+ */

static Lisp_Object CC_mvKpowKL(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v14, v46;
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
    stack[-2] = nil;
    goto v12;

v12:
    v14 = stack[-1];
    if (v14 == nil) goto v6;
    v14 = stack[-1];
    v46 = qcar(v14);
    v14 = stack[0];
    v14 = qcar(v14);
    v46 = plus2(v46, v14);
    nil = C_nil;
    if (exception_pending()) goto v36;
    env = stack[-3];
    v14 = stack[-2];
    v14 = cons(v46, v14);
    nil = C_nil;
    if (exception_pending()) goto v36;
    env = stack[-3];
    stack[-2] = v14;
    v14 = stack[-1];
    v14 = qcdr(v14);
    stack[-1] = v14;
    v14 = stack[0];
    v14 = qcdr(v14);
    stack[0] = v14;
    goto v12;

v6:
    v14 = stack[-2];
    {
        popv(4);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v14);
    }
/* error exit handlers */
v36:
    popv(4);
    return nil;
}



/* Code for rnquotient!: */

static Lisp_Object CC_rnquotientT(Lisp_Object env,
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
    v30 = qcdr(v30);
    stack[-2] = times2(v99, v30);
    nil = C_nil;
    if (exception_pending()) goto v46;
    env = stack[-3];
    v30 = stack[-1];
    v30 = qcdr(v30);
    v99 = qcdr(v30);
    v30 = stack[0];
    v30 = qcdr(v30);
    v30 = qcar(v30);
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



/* Code for general!-modular!-reciprocal */

static Lisp_Object CC_generalKmodularKreciprocal(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v40, v206, v41, v64;
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
    v40 = qvalue(elt(env, 1)); /* !*balanced_mod */
    if (v40 == nil) goto v37;
    v206 = stack[0];
    v40 = (Lisp_Object)1; /* 0 */
    v40 = (Lisp_Object)lessp2(v206, v40);
    nil = C_nil;
    if (exception_pending()) goto v134;
    v40 = v40 ? lisp_true : nil;
    env = stack[-2];
    if (v40 == nil) goto v37;
    stack[-1] = qvalue(elt(env, 2)); /* current!-modulus */
    v206 = stack[0];
    v40 = qvalue(elt(env, 2)); /* current!-modulus */
    v41 = plus2(v206, v40);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-2];
    v206 = (Lisp_Object)1; /* 0 */
    v40 = (Lisp_Object)17; /* 1 */
    {
        Lisp_Object v105 = stack[-1];
        popv(3);
        fn = elt(env, 3); /* general!-reciprocal!-by!-gcd */
        return (*qfnn(fn))(qenv(fn), 4, v105, v41, v206, v40);
    }

v37:
    v64 = qvalue(elt(env, 2)); /* current!-modulus */
    v41 = stack[0];
    v206 = (Lisp_Object)1; /* 0 */
    v40 = (Lisp_Object)17; /* 1 */
    {
        popv(3);
        fn = elt(env, 3); /* general!-reciprocal!-by!-gcd */
        return (*qfnn(fn))(qenv(fn), 4, v64, v41, v206, v40);
    }
/* error exit handlers */
v134:
    popv(3);
    return nil;
}



/* Code for rread */

static Lisp_Object MS_CDECL CC_rread(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v3;
    Lisp_Object fn;
    argcheck(nargs, 0, "rread");
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* end of prologue */
    v3 = elt(env, 1); /* " '" */
    fn = elt(env, 2); /* prin2x */
    v3 = (*qfn1(fn))(qenv(fn), v3);
    nil = C_nil;
    if (exception_pending()) goto v4;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 3); /* rread1 */
        return (*qfnn(fn))(qenv(fn), 0);
    }
/* error exit handlers */
v4:
    popv(1);
    return nil;
}



/* Code for c!:ordexn */

static Lisp_Object CC_cTordexn(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v145, v146;
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
    stack[0] = nil;
    stack[-3] = nil;
    goto v45;

v45:
    v145 = stack[-1];
    if (v145 == nil) goto v47;
    v146 = stack[-2];
    v145 = stack[-1];
    v145 = qcar(v145);
    if (equal(v146, v145)) goto v20;
    v145 = stack[-2];
    v145 = Lconsp(nil, v145);
    env = stack[-4];
    if (v145 == nil) goto v34;
    v145 = stack[-1];
    v145 = qcar(v145);
    v145 = Lconsp(nil, v145);
    env = stack[-4];
    if (!(v145 == nil)) goto v20;

v34:
    v146 = stack[-2];
    v145 = stack[-1];
    v145 = qcar(v145);
    fn = elt(env, 1); /* c!:ordxp */
    v145 = (*qfn2(fn))(qenv(fn), v146, v145);
    nil = C_nil;
    if (exception_pending()) goto v84;
    env = stack[-4];
    if (v145 == nil) goto v62;
    v146 = stack[-2];
    v145 = stack[-3];
    v145 = cons(v146, v145);
    nil = C_nil;
    if (exception_pending()) goto v84;
    env = stack[-4];
    v146 = Lreverse(nil, v145);
    nil = C_nil;
    if (exception_pending()) goto v84;
    env = stack[-4];
    v145 = stack[-1];
    v145 = Lappend(nil, v146, v145);
    nil = C_nil;
    if (exception_pending()) goto v84;
    {
        Lisp_Object v237 = stack[0];
        popv(5);
        return cons(v237, v145);
    }

v62:
    v145 = stack[-1];
    v146 = qcar(v145);
    v145 = stack[-3];
    v145 = cons(v146, v145);
    nil = C_nil;
    if (exception_pending()) goto v84;
    env = stack[-4];
    stack[-3] = v145;
    v145 = stack[-1];
    v145 = qcdr(v145);
    stack[-1] = v145;
    v145 = stack[0];
    v145 = (v145 == nil ? lisp_true : nil);
    stack[0] = v145;
    goto v45;

v20:
    v145 = nil;
    { popv(5); return onevalue(v145); }

v47:
    v146 = stack[-2];
    v145 = stack[-3];
    v145 = cons(v146, v145);
    nil = C_nil;
    if (exception_pending()) goto v84;
    env = stack[-4];
    v145 = Lreverse(nil, v145);
    nil = C_nil;
    if (exception_pending()) goto v84;
    {
        Lisp_Object v121 = stack[0];
        popv(5);
        return cons(v121, v145);
    }
/* error exit handlers */
v84:
    popv(5);
    return nil;
}



/* Code for vevmaptozero1 */

static Lisp_Object CC_vevmaptozero1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v43, v29;
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
    v43 = v16;
    stack[0] = v0;
/* end of prologue */

v4:
    v29 = stack[0];
    if (v29 == nil) { popv(2); return onevalue(v43); }
    v29 = stack[0];
    v29 = qcdr(v29);
    stack[0] = v29;
    v29 = (Lisp_Object)1; /* 0 */
    v43 = cons(v29, v43);
    nil = C_nil;
    if (exception_pending()) goto v18;
    env = stack[-1];
    goto v4;
/* error exit handlers */
v18:
    popv(2);
    return nil;
}



/* Code for addpf */

static Lisp_Object CC_addpf(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v130, v131, v261;
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
    stack[0] = nil;
    goto v12;

v12:
    v130 = stack[-2];
    if (v130 == nil) goto v2;
    v130 = stack[-1];
    if (v130 == nil) goto v43;
    v130 = stack[-2];
    v130 = qcar(v130);
    v131 = qcar(v130);
    v130 = (Lisp_Object)17; /* 1 */
    if (v131 == v130) goto v193;
    v130 = stack[-1];
    v130 = qcar(v130);
    v131 = qcar(v130);
    v130 = (Lisp_Object)17; /* 1 */
    if (v131 == v130) goto v55;
    v130 = stack[-2];
    v130 = qcar(v130);
    v131 = qcar(v130);
    v130 = stack[-1];
    v130 = qcar(v130);
    v130 = qcar(v130);
    if (equal(v131, v130)) goto v96;
    v130 = stack[-2];
    v130 = qcar(v130);
    v131 = qcar(v130);
    v130 = stack[-1];
    v130 = qcar(v130);
    v130 = qcar(v130);
    fn = elt(env, 1); /* ordop */
    v130 = (*qfn2(fn))(qenv(fn), v131, v130);
    nil = C_nil;
    if (exception_pending()) goto v486;
    env = stack[-4];
    if (v130 == nil) goto v462;
    v130 = stack[-2];
    v131 = qcar(v130);
    v130 = stack[0];
    v130 = cons(v131, v130);
    nil = C_nil;
    if (exception_pending()) goto v486;
    env = stack[-4];
    stack[0] = v130;
    v130 = stack[-2];
    v130 = qcdr(v130);
    stack[-2] = v130;
    goto v12;

v462:
    v130 = stack[-1];
    v131 = qcar(v130);
    v130 = stack[0];
    v130 = cons(v131, v130);
    nil = C_nil;
    if (exception_pending()) goto v486;
    env = stack[-4];
    stack[0] = v130;
    v130 = stack[-1];
    v130 = qcdr(v130);
    stack[-1] = v130;
    goto v12;

v96:
    stack[-3] = stack[0];
    v130 = stack[-2];
    v130 = qcar(v130);
    v131 = qcdr(v130);
    v130 = stack[-1];
    v130 = qcar(v130);
    v130 = qcdr(v130);
    fn = elt(env, 2); /* addsq */
    stack[0] = (*qfn2(fn))(qenv(fn), v131, v130);
    nil = C_nil;
    if (exception_pending()) goto v486;
    env = stack[-4];
    v130 = stack[-2];
    v131 = qcdr(v130);
    v130 = stack[-1];
    v130 = qcdr(v130);
    v130 = CC_addpf(env, v131, v130);
    nil = C_nil;
    if (exception_pending()) goto v486;
    env = stack[-4];
    v131 = stack[0];
    v261 = v131;
    v261 = qcar(v261);
    if (v261 == nil) goto v142;
    v261 = stack[-2];
    v261 = qcar(v261);
    v261 = qcar(v261);
    v130 = acons(v261, v131, v130);
    nil = C_nil;
    if (exception_pending()) goto v486;
    env = stack[-4];
    goto v142;

v142:
    {
        Lisp_Object v467 = stack[-3];
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v467, v130);
    }

v55:
    v131 = stack[-1];
    v130 = stack[-2];
    fn = elt(env, 4); /* addmpf */
    v130 = (*qfn2(fn))(qenv(fn), v131, v130);
    nil = C_nil;
    if (exception_pending()) goto v486;
    env = stack[-4];
    {
        Lisp_Object v352 = stack[0];
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v352, v130);
    }

v193:
    v131 = stack[-2];
    v130 = stack[-1];
    fn = elt(env, 4); /* addmpf */
    v130 = (*qfn2(fn))(qenv(fn), v131, v130);
    nil = C_nil;
    if (exception_pending()) goto v486;
    env = stack[-4];
    {
        Lisp_Object v184 = stack[0];
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v184, v130);
    }

v43:
    v131 = stack[0];
    v130 = stack[-2];
    {
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v131, v130);
    }

v2:
    v131 = stack[0];
    v130 = stack[-1];
    {
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v131, v130);
    }
/* error exit handlers */
v486:
    popv(5);
    return nil;
}



/* Code for evaluate0 */

static Lisp_Object CC_evaluate0(Lisp_Object env,
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
    stack[0] = v16;
    v1 = v0;
/* end of prologue */
    fn = elt(env, 1); /* evaluate!-horner */
    v2 = (*qfn1(fn))(qenv(fn), v1);
    nil = C_nil;
    if (exception_pending()) goto v13;
    env = stack[-1];
    v1 = stack[0];
    {
        popv(2);
        fn = elt(env, 2); /* evaluate1 */
        return (*qfn2(fn))(qenv(fn), v2, v1);
    }
/* error exit handlers */
v13:
    popv(2);
    return nil;
}



/* Code for pneg */

static Lisp_Object CC_pneg(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v69, v67;
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
/* copy arguments values to proper place */
    v69 = v0;
/* end of prologue */
    stack[-4] = v69;
    v69 = stack[-4];
    if (v69 == nil) goto v8;
    v69 = stack[-4];
    v69 = qcar(v69);
    v67 = v69;
    v69 = v67;
    stack[0] = qcar(v69);
    v69 = v67;
    v69 = qcdr(v69);
    fn = elt(env, 1); /* cneg */
    v69 = (*qfn1(fn))(qenv(fn), v69);
    nil = C_nil;
    if (exception_pending()) goto v70;
    env = stack[-5];
    v69 = cons(stack[0], v69);
    nil = C_nil;
    if (exception_pending()) goto v70;
    env = stack[-5];
    v69 = ncons(v69);
    nil = C_nil;
    if (exception_pending()) goto v70;
    env = stack[-5];
    stack[-2] = v69;
    stack[-3] = v69;
    goto v45;

v45:
    v69 = stack[-4];
    v69 = qcdr(v69);
    stack[-4] = v69;
    v69 = stack[-4];
    if (v69 == nil) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    stack[-1] = stack[-2];
    v69 = stack[-4];
    v69 = qcar(v69);
    v67 = v69;
    v69 = v67;
    stack[0] = qcar(v69);
    v69 = v67;
    v69 = qcdr(v69);
    fn = elt(env, 1); /* cneg */
    v69 = (*qfn1(fn))(qenv(fn), v69);
    nil = C_nil;
    if (exception_pending()) goto v70;
    env = stack[-5];
    v69 = cons(stack[0], v69);
    nil = C_nil;
    if (exception_pending()) goto v70;
    env = stack[-5];
    v69 = ncons(v69);
    nil = C_nil;
    if (exception_pending()) goto v70;
    env = stack[-5];
    v69 = Lrplacd(nil, stack[-1], v69);
    nil = C_nil;
    if (exception_pending()) goto v70;
    env = stack[-5];
    v69 = stack[-2];
    v69 = qcdr(v69);
    stack[-2] = v69;
    goto v45;

v8:
    v69 = nil;
    { popv(6); return onevalue(v69); }
/* error exit handlers */
v70:
    popv(6);
    return nil;
}



/* Code for ordn */

static Lisp_Object CC_ordn(Lisp_Object env,
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
    push(nil);
/* copy arguments values to proper place */
    v48 = v0;
/* end of prologue */
    v36 = v48;
    if (v36 == nil) goto v3;
    v36 = v48;
    v36 = qcdr(v36);
    if (v36 == nil) { popv(2); return onevalue(v48); }
    v36 = v48;
    v36 = qcdr(v36);
    v36 = qcdr(v36);
    if (v36 == nil) goto v28;
    v36 = v48;
    stack[0] = qcar(v36);
    v36 = v48;
    v36 = qcdr(v36);
    v36 = CC_ordn(env, v36);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[-1];
    {
        Lisp_Object v42 = stack[0];
        popv(2);
        fn = elt(env, 1); /* ordad */
        return (*qfn2(fn))(qenv(fn), v42, v36);
    }

v28:
    v36 = v48;
    v36 = qcar(v36);
    v48 = qcdr(v48);
    v48 = qcar(v48);
    {
        popv(2);
        fn = elt(env, 2); /* ord2 */
        return (*qfn2(fn))(qenv(fn), v36, v48);
    }

v3:
    v36 = nil;
    { popv(2); return onevalue(v36); }
/* error exit handlers */
v51:
    popv(2);
    return nil;
}



/* Code for opnum!* */

static Lisp_Object CC_opnumH(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v57, v72, v122, v58;
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
    v57 = v0;
/* end of prologue */
    stack[-1] = nil;
    v72 = v57;
    if (symbolp(v72)) goto v45;
    stack[0] = v57;
    fn = elt(env, 2); /* collectindices */
    v57 = (*qfn1(fn))(qenv(fn), v57);
    nil = C_nil;
    if (exception_pending()) goto v103;
    env = stack[-2];
    fn = elt(env, 3); /* removeindices */
    v57 = (*qfn2(fn))(qenv(fn), stack[0], v57);
    nil = C_nil;
    if (exception_pending()) goto v103;
    env = stack[-2];
    goto v45;

v45:
    v72 = v57;
    if (symbolp(v72)) goto v47;
    v72 = v57;
    v72 = qcar(v72);
    v58 = v72;
    v57 = qcdr(v57);
    stack[-1] = v57;
    goto v14;

v14:
    v122 = stack[-1];
    v72 = v58;
    v57 = elt(env, 1); /* opnum */
    v57 = get(v72, v57);
    env = stack[-2];
    v72 = Lassoc(nil, v122, v57);
    v57 = v72;
    if (v72 == nil) goto v34;
    v57 = qcdr(v57);
    { popv(3); return onevalue(v57); }

v34:
    v72 = nil;
    v122 = v58;
    v57 = elt(env, 1); /* opnum */
    v57 = get(v122, v57);
    v57 = Lassoc(nil, v72, v57);
    v57 = qcdr(v57);
    { popv(3); return onevalue(v57); }

v47:
    v58 = v57;
    goto v14;
/* error exit handlers */
v103:
    popv(3);
    return nil;
}



/* Code for !*i2ar */

static Lisp_Object CC_Hi2ar(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v7, v8;
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v7 = v0;
/* end of prologue */
    v8 = elt(env, 1); /* !:ar!: */
    return cons(v8, v7);
}



/* Code for c!:extmult */

static Lisp_Object CC_cTextmult(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v77, v78;
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
    v77 = stack[-2];
    if (v77 == nil) goto v4;
    v77 = stack[-1];
    if (v77 == nil) goto v4;
    v78 = stack[-1];
    v77 = (Lisp_Object)17; /* 1 */
    if (v78 == v77) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v77 = stack[-2];
    v77 = qcar(v77);
    v77 = qcar(v77);
    v78 = qcar(v77);
    v77 = stack[-1];
    v77 = qcar(v77);
    v77 = qcar(v77);
    fn = elt(env, 1); /* c!:ordexn */
    v77 = (*qfn2(fn))(qenv(fn), v78, v77);
    nil = C_nil;
    if (exception_pending()) goto v216;
    env = stack[-4];
    v78 = v77;
    v77 = v78;
    if (v77 == nil) goto v231;
    v77 = v78;
    stack[0] = qcdr(v77);
    v77 = v78;
    v77 = qcar(v77);
    if (v77 == nil) goto v60;
    v77 = stack[-2];
    v77 = qcar(v77);
    v78 = qcdr(v77);
    v77 = stack[-1];
    v77 = qcar(v77);
    v77 = qcdr(v77);
    fn = elt(env, 2); /* c!:subs2multf */
    v77 = (*qfn2(fn))(qenv(fn), v78, v77);
    nil = C_nil;
    if (exception_pending()) goto v216;
    env = stack[-4];
    fn = elt(env, 3); /* negf */
    v77 = (*qfn1(fn))(qenv(fn), v77);
    nil = C_nil;
    if (exception_pending()) goto v216;
    env = stack[-4];
    goto v40;

v40:
    v77 = cons(stack[0], v77);
    nil = C_nil;
    if (exception_pending()) goto v216;
    env = stack[-4];
    stack[-3] = ncons(v77);
    nil = C_nil;
    if (exception_pending()) goto v216;
    env = stack[-4];
    v77 = stack[-2];
    v77 = qcar(v77);
    v78 = ncons(v77);
    nil = C_nil;
    if (exception_pending()) goto v216;
    env = stack[-4];
    v77 = stack[-1];
    v77 = qcdr(v77);
    stack[0] = CC_cTextmult(env, v78, v77);
    nil = C_nil;
    if (exception_pending()) goto v216;
    env = stack[-4];
    v77 = stack[-2];
    v78 = qcdr(v77);
    v77 = stack[-1];
    v77 = CC_cTextmult(env, v78, v77);
    nil = C_nil;
    if (exception_pending()) goto v216;
    env = stack[-4];
    fn = elt(env, 4); /* c!:extadd */
    v77 = (*qfn2(fn))(qenv(fn), stack[0], v77);
    nil = C_nil;
    if (exception_pending()) goto v216;
    env = stack[-4];
    {
        Lisp_Object v190 = stack[-3];
        popv(5);
        fn = elt(env, 4); /* c!:extadd */
        return (*qfn2(fn))(qenv(fn), v190, v77);
    }

v60:
    v77 = stack[-2];
    v77 = qcar(v77);
    v78 = qcdr(v77);
    v77 = stack[-1];
    v77 = qcar(v77);
    v77 = qcdr(v77);
    fn = elt(env, 2); /* c!:subs2multf */
    v77 = (*qfn2(fn))(qenv(fn), v78, v77);
    nil = C_nil;
    if (exception_pending()) goto v216;
    env = stack[-4];
    goto v40;

v231:
    v77 = stack[-2];
    v77 = qcar(v77);
    v78 = ncons(v77);
    nil = C_nil;
    if (exception_pending()) goto v216;
    env = stack[-4];
    v77 = stack[-1];
    v77 = qcdr(v77);
    stack[0] = CC_cTextmult(env, v78, v77);
    nil = C_nil;
    if (exception_pending()) goto v216;
    env = stack[-4];
    v77 = stack[-2];
    v78 = qcdr(v77);
    v77 = stack[-1];
    v77 = CC_cTextmult(env, v78, v77);
    nil = C_nil;
    if (exception_pending()) goto v216;
    env = stack[-4];
    {
        Lisp_Object v76 = stack[0];
        popv(5);
        fn = elt(env, 4); /* c!:extadd */
        return (*qfn2(fn))(qenv(fn), v76, v77);
    }

v4:
    v77 = nil;
    { popv(5); return onevalue(v77); }
/* error exit handlers */
v216:
    popv(5);
    return nil;
}



/* Code for vecp */

static Lisp_Object CC_vecp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v83, v84, v237, v121;
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
    v237 = v0;
/* end of prologue */
    v83 = v237;
    if (v83 == nil) goto v45;
    v83 = v237;
    if (is_number(v83)) goto v45;
    v83 = v237;
    if (!consp(v83)) goto v17;
    v83 = v237;
    v83 = Lthreevectorp(nil, v83);
    env = stack[0];
    if (v83 == nil) goto v46;
    v83 = lisp_true;
    { popv(1); return onevalue(v83); }

v46:
    v83 = v237;
    v83 = qcar(v83);
    v121 = v83;
    if (!(!consp(v83))) goto v70;
    v84 = v121;
    v83 = elt(env, 1); /* rtype */
    v84 = get(v84, v83);
    env = stack[0];
    v83 = elt(env, 2); /* !3vector */
    if (!(v84 == v83)) goto v70;
    v83 = v237;
    v83 = qcdr(v83);
    v83 = qcar(v83);
    {
        popv(1);
        fn = elt(env, 6); /* isvectorindex */
        return (*qfn1(fn))(qenv(fn), v83);
    }

v70:
    v84 = v121;
    v83 = elt(env, 3); /* vectorfn */
    v83 = Lflagp(nil, v84, v83);
    env = stack[0];
    if (v83 == nil) goto v102;
    v83 = lisp_true;
    { popv(1); return onevalue(v83); }

v102:
    v84 = v121;
    v83 = elt(env, 4); /* varithop */
    v83 = Lflagp(nil, v84, v83);
    env = stack[0];
    if (!(v83 == nil)) goto v65;
    v84 = v121;
    v83 = elt(env, 5); /* vectormapping */
    v83 = Lflagp(nil, v84, v83);
    env = stack[0];
    if (!(v83 == nil)) goto v65;
    v83 = nil;
    { popv(1); return onevalue(v83); }

v65:
    v83 = v237;
    v83 = qcdr(v83);
    {
        popv(1);
        fn = elt(env, 7); /* hasonevector */
        return (*qfn1(fn))(qenv(fn), v83);
    }

v17:
    v84 = v237;
    v83 = elt(env, 1); /* rtype */
    v83 = get(v84, v83);
    env = stack[0];
    v84 = elt(env, 2); /* !3vector */
    v83 = (v83 == v84 ? lisp_true : nil);
    if (!(v83 == nil)) { popv(1); return onevalue(v83); }
    v83 = v237;
        popv(1);
        return Lthreevectorp(nil, v83);

v45:
    v83 = nil;
    { popv(1); return onevalue(v83); }
}



/* Code for copy!-vector */

static Lisp_Object MS_CDECL CC_copyKvector(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v16,
                         Lisp_Object v63, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v48, v33, v51, v42, v49, v50, v52, v193;
    argcheck(nargs, 3, "copy-vector");
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v49 = v63;
    v50 = v16;
    v52 = v0;
/* end of prologue */
    v48 = (Lisp_Object)1; /* 0 */
    v193 = v48;
    goto v2;

v2:
    v33 = v50;
    v48 = v193;
    v48 = (Lisp_Object)(int32)((int32)v33 - (int32)v48 + TAG_FIXNUM);
    v48 = ((intxx)(v48) < 0 ? lisp_true : nil);
    if (!(v48 == nil)) return onevalue(v50);
    v42 = v49;
    v51 = v193;
    v33 = v52;
    v48 = v193;
    v48 = *(Lisp_Object *)((char *)v33 + (CELL-TAG_VECTOR) + ((int32)v48/(16/CELL)));
    *(Lisp_Object *)((char *)v42 + (CELL-TAG_VECTOR) + ((int32)v51/(16/CELL))) = v48;
    v48 = v193;
    v48 = (Lisp_Object)((int32)(v48) + 0x10);
    v193 = v48;
    goto v2;
}



/* Code for reduce!-mod!-p */

static Lisp_Object CC_reduceKmodKp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v46;
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
    v46 = stack[-1];
    if (v46 == nil) goto v3;
    v46 = stack[-1];
    if (!consp(v46)) goto v5;
    v46 = stack[-1];
    v46 = qcar(v46);
    if (!consp(v46)) goto v5;
    v46 = stack[-1];
    v46 = qcar(v46);
    stack[-2] = qcar(v46);
    v46 = stack[-1];
    v46 = qcar(v46);
    v46 = qcdr(v46);
    stack[0] = CC_reduceKmodKp(env, v46);
    nil = C_nil;
    if (exception_pending()) goto v36;
    env = stack[-3];
    v46 = stack[-1];
    v46 = qcdr(v46);
    v46 = CC_reduceKmodKp(env, v46);
    nil = C_nil;
    if (exception_pending()) goto v36;
    env = stack[-3];
    {
        Lisp_Object v48 = stack[-2];
        Lisp_Object v33 = stack[0];
        popv(4);
        fn = elt(env, 1); /* adjoin!-term */
        return (*qfnn(fn))(qenv(fn), 3, v48, v33, v46);
    }

v5:
    v46 = stack[-1];
    v46 = Lmodular_number(nil, v46);
    env = stack[-3];
    {
        popv(4);
        fn = elt(env, 2); /* !*n2f */
        return (*qfn1(fn))(qenv(fn), v46);
    }

v3:
    v46 = nil;
    { popv(4); return onevalue(v46); }
/* error exit handlers */
v36:
    popv(4);
    return nil;
}



/* Code for gintequiv!: */

static Lisp_Object CC_gintequivT(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v44, v47, v15;
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v47 = v0;
/* end of prologue */
    v44 = v47;
    v44 = qcdr(v44);
    v15 = qcdr(v44);
    v44 = (Lisp_Object)1; /* 0 */
    if (v15 == v44) goto v3;
    v44 = nil;
    return onevalue(v44);

v3:
    v44 = v47;
    v44 = qcdr(v44);
    v44 = qcar(v44);
    return onevalue(v44);
}



/* Code for trwrite */

static Lisp_Object CC_trwrite(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v49, v50;
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
    v49 = stack[0];
    v50 = qcar(v49);
    v49 = elt(env, 1); /* tracing */
    v49 = Lflagp(nil, v50, v49);
    env = stack[-1];
    if (v49 == nil) goto v45;
    v49 = elt(env, 2); /* "**in procedure: " */
    v49 = Lprinc(nil, v49);
    nil = C_nil;
    if (exception_pending()) goto v193;
    env = stack[-1];
    v49 = stack[0];
    v49 = qcar(v49);
    v49 = Lprinc(nil, v49);
    nil = C_nil;
    if (exception_pending()) goto v193;
    env = stack[-1];
    v49 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v193;
    env = stack[-1];
    v49 = stack[0];
    v49 = qcdr(v49);
    stack[0] = v49;
    goto v20;

v20:
    v49 = stack[0];
    if (v49 == nil) goto v19;
    v49 = stack[0];
    v49 = qcar(v49);
    v49 = Lprinc(nil, v49);
    nil = C_nil;
    if (exception_pending()) goto v193;
    env = stack[-1];
    v49 = stack[0];
    v49 = qcdr(v49);
    stack[0] = v49;
    goto v20;

v19:
    v49 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v193;
    v49 = nil;
    { popv(2); return onevalue(v49); }

v45:
    v49 = nil;
    { popv(2); return onevalue(v49); }
/* error exit handlers */
v193:
    popv(2);
    return nil;
}



/* Code for red!-ratios2 */

static Lisp_Object MS_CDECL CC_redKratios2(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v16,
                         Lisp_Object v63, Lisp_Object v9, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v145, v146, v142, v236;
    Lisp_Object fn;
    argcheck(nargs, 4, "red-ratios2");
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

v11:
    v145 = stack[-4];
    if (v145 == nil) goto v8;
    v146 = stack[-2];
    v145 = stack[-3];
    v145 = qcar(v145);
    stack[0] = times2(v146, v145);
    nil = C_nil;
    if (exception_pending()) goto v144;
    env = stack[-6];
    stack[-5] = stack[0];
    v146 = stack[-1];
    v145 = stack[-4];
    v145 = qcar(v145);
    v145 = times2(v146, v145);
    nil = C_nil;
    if (exception_pending()) goto v144;
    env = stack[-6];
    if (!(equal(stack[0], v145))) goto v220;
    v146 = stack[-5];
    v145 = (Lisp_Object)1; /* 0 */
    v145 = Lneq(nil, v146, v145);
    nil = C_nil;
    if (exception_pending()) goto v144;
    env = stack[-6];
    if (v145 == nil) goto v220;
    v146 = stack[-1];
    v145 = stack[-2];
    v146 = Lgcd(nil, v146, v145);
    nil = C_nil;
    if (exception_pending()) goto v144;
    env = stack[-6];
    v145 = stack[-1];
    v146 = Cremainder(v146, v145);
    nil = C_nil;
    if (exception_pending()) goto v144;
    env = stack[-6];
    v145 = (Lisp_Object)1; /* 0 */
    if (!(v146 == v145)) goto v220;
    v146 = stack[-1];
    v145 = stack[-2];
    {
        popv(7);
        fn = elt(env, 1); /* red!-lowest!-terms */
        return (*qfn2(fn))(qenv(fn), v146, v145);
    }

v220:
    v145 = stack[-4];
    v236 = qcdr(v145);
    v145 = stack[-3];
    v142 = qcdr(v145);
    v146 = stack[-2];
    v145 = stack[-1];
    stack[-4] = v236;
    stack[-3] = v142;
    stack[-2] = v146;
    stack[-1] = v145;
    goto v11;

v8:
    v145 = nil;
    { popv(7); return onevalue(v145); }
/* error exit handlers */
v144:
    popv(7);
    return nil;
}



/* Code for dv_skelhead */

static Lisp_Object CC_dv_skelhead(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v4;
    Lisp_Object fn;
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v4 = v0;
/* end of prologue */
    v4 = qcar(v4);
    {
        fn = elt(env, 1); /* dv_cambhead */
        return (*qfn1(fn))(qenv(fn), v4);
    }
}



/* Code for general!-modular!-minus */

static Lisp_Object CC_generalKmodularKminus(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v43, v29, v17;
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v17 = v0;
/* end of prologue */
    v29 = v17;
    v43 = (Lisp_Object)1; /* 0 */
    if (v29 == v43) return onevalue(v17);
    v43 = qvalue(elt(env, 1)); /* current!-modulus */
    v29 = v17;
    return difference2(v43, v29);
}



/* Code for i!&prn */

static Lisp_Object CC_iGprn(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v44;
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
    v44 = v0;
/* end of prologue */
    stack[0] = v44;
    goto v4;

v4:
    v44 = stack[0];
    if (v44 == nil) goto v3;
    v44 = stack[0];
    v44 = qcar(v44);
    v44 = Lprinc(nil, v44);
    nil = C_nil;
    if (exception_pending()) goto v15;
    env = stack[-1];
    v44 = stack[0];
    v44 = qcdr(v44);
    stack[0] = v44;
    goto v4;

v3:
        popv(2);
        return Lterpri(nil, 0);
/* error exit handlers */
v15:
    popv(2);
    return nil;
}



/* Code for wedget2 */

static Lisp_Object CC_wedget2(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v226, v96, v145;
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
    v226 = stack[-1];
    v96 = qcar(v226);
    v226 = (Lisp_Object)17; /* 1 */
    if (v96 == v226) goto v26;
    v226 = stack[0];
    v226 = qcar(v226);
    v96 = qcar(v226);
    v226 = (Lisp_Object)17; /* 1 */
    if (v96 == v226) goto v49;
    v226 = stack[-1];
    v145 = qcar(v226);
    v226 = stack[0];
    v96 = qcar(v226);
    v226 = nil;
    fn = elt(env, 1); /* wedgek2 */
    stack[-2] = (*qfnn(fn))(qenv(fn), 3, v145, v96, v226);
    nil = C_nil;
    if (exception_pending()) goto v456;
    env = stack[-3];
    v226 = stack[-1];
    v96 = qcdr(v226);
    v226 = stack[0];
    v226 = qcdr(v226);
    fn = elt(env, 2); /* multsq */
    v226 = (*qfn2(fn))(qenv(fn), v96, v226);
    nil = C_nil;
    if (exception_pending()) goto v456;
    env = stack[-3];
    {
        Lisp_Object v83 = stack[-2];
        popv(4);
        fn = elt(env, 3); /* multpfsq */
        return (*qfn2(fn))(qenv(fn), v83, v226);
    }

v49:
    v226 = stack[-1];
    v226 = qcar(v226);
    stack[-2] = ncons(v226);
    nil = C_nil;
    if (exception_pending()) goto v456;
    env = stack[-3];
    v226 = stack[-1];
    v96 = qcdr(v226);
    v226 = stack[0];
    v226 = qcdr(v226);
    fn = elt(env, 2); /* multsq */
    v226 = (*qfn2(fn))(qenv(fn), v96, v226);
    nil = C_nil;
    if (exception_pending()) goto v456;
    env = stack[-3];
    v226 = cons(stack[-2], v226);
    nil = C_nil;
    if (exception_pending()) goto v456;
    popv(4);
    return ncons(v226);

v26:
    v226 = stack[0];
    stack[-2] = qcar(v226);
    v226 = stack[-1];
    v96 = qcdr(v226);
    v226 = stack[0];
    v226 = qcdr(v226);
    fn = elt(env, 2); /* multsq */
    v226 = (*qfn2(fn))(qenv(fn), v96, v226);
    nil = C_nil;
    if (exception_pending()) goto v456;
    env = stack[-3];
    v226 = cons(stack[-2], v226);
    nil = C_nil;
    if (exception_pending()) goto v456;
    popv(4);
    return ncons(v226);
/* error exit handlers */
v456:
    popv(4);
    return nil;
}



/* Code for minus!: */

static Lisp_Object CC_minusT(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v27, v28;
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
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0;
/* end of prologue */
    stack[-1] = elt(env, 1); /* !:rd!: */
    v27 = stack[0];
    v27 = qcdr(v27);
    v27 = qcar(v27);
    v28 = negate(v27);
    nil = C_nil;
    if (exception_pending()) goto v47;
    v27 = stack[0];
    v27 = qcdr(v27);
    v27 = qcdr(v27);
    {
        Lisp_Object v15 = stack[-1];
        popv(2);
        return list2star(v15, v28, v27);
    }
/* error exit handlers */
v47:
    popv(2);
    return nil;
}



/* Code for greaterp!: */

static Lisp_Object CC_greaterpT(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v88, v89, v90;
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
    stack[0] = v16;
    v90 = v0;
/* end of prologue */
    v88 = v90;
    v88 = qcdr(v88);
    v89 = qcdr(v88);
    v88 = stack[0];
    v88 = qcdr(v88);
    v88 = qcdr(v88);
    if (equal(v89, v88)) goto v28;
    v88 = v90;
    fn = elt(env, 2); /* csl_normbf */
    stack[-1] = (*qfn1(fn))(qenv(fn), v88);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-5];
    v88 = stack[0];
    fn = elt(env, 2); /* csl_normbf */
    v88 = (*qfn1(fn))(qenv(fn), v88);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-5];
    stack[0] = v88;
    v88 = stack[-1];
    v88 = qcdr(v88);
    v89 = qcdr(v88);
    v88 = stack[0];
    v88 = qcdr(v88);
    v88 = qcdr(v88);
    v90 = difference2(v89, v88);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-5];
    v88 = stack[-1];
    v88 = qcdr(v88);
    v89 = qcar(v88);
    v88 = stack[0];
    v88 = qcdr(v88);
    v88 = qcar(v88);
    stack[-4] = v90;
    stack[-3] = v89;
    stack[-2] = v88;
    v89 = stack[-4];
    v88 = (Lisp_Object)1; /* 0 */
    if (v89 == v88) goto v101;
    v89 = (Lisp_Object)33; /* 2 */
    v88 = qvalue(elt(env, 1)); /* !:bprec!: */
    v88 = times2(v89, v88);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-5];
    stack[-1] = v88;
    v89 = stack[-4];
    v88 = stack[-1];
    v88 = (Lisp_Object)greaterp2(v89, v88);
    nil = C_nil;
    if (exception_pending()) goto v124;
    v88 = v88 ? lisp_true : nil;
    env = stack[-5];
    if (v88 == nil) goto v81;
    v89 = stack[-3];
    v88 = (Lisp_Object)1; /* 0 */
        popv(6);
        return Lgreaterp(nil, v89, v88);

v81:
    stack[0] = stack[-4];
    v88 = stack[-1];
    v88 = negate(v88);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-5];
    v88 = (Lisp_Object)lessp2(stack[0], v88);
    nil = C_nil;
    if (exception_pending()) goto v124;
    v88 = v88 ? lisp_true : nil;
    env = stack[-5];
    if (v88 == nil) goto v137;
    v89 = stack[-2];
    v88 = (Lisp_Object)1; /* 0 */
        popv(6);
        return Llessp(nil, v89, v88);

v137:
    v89 = stack[-4];
    v88 = (Lisp_Object)1; /* 0 */
    v88 = (Lisp_Object)greaterp2(v89, v88);
    nil = C_nil;
    if (exception_pending()) goto v124;
    v88 = v88 ? lisp_true : nil;
    env = stack[-5];
    if (v88 == nil) goto v93;
    v89 = stack[-3];
    v88 = stack[-4];
    v89 = Lash1(nil, v89, v88);
    nil = C_nil;
    if (exception_pending()) goto v124;
    v88 = stack[-2];
        popv(6);
        return Lgreaterp(nil, v89, v88);

v93:
    stack[0] = stack[-3];
    stack[-1] = stack[-2];
    v88 = stack[-4];
    v88 = negate(v88);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-5];
    v88 = Lash1(nil, stack[-1], v88);
    nil = C_nil;
    if (exception_pending()) goto v124;
    {
        Lisp_Object v125 = stack[0];
        popv(6);
        return Lgreaterp(nil, v125, v88);
    }

v101:
    v89 = stack[-3];
    v88 = stack[-2];
        popv(6);
        return Lgreaterp(nil, v89, v88);

v28:
    v88 = v90;
    v88 = qcdr(v88);
    v89 = qcar(v88);
    v88 = stack[0];
    v88 = qcdr(v88);
    v88 = qcar(v88);
        popv(6);
        return Lgreaterp(nil, v89, v88);
/* error exit handlers */
v124:
    popv(6);
    return nil;
}



/* Code for contrsp */

static Lisp_Object CC_contrsp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v46, v31, v32;
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
    v46 = stack[-1];
    v46 = qcdr(v46);
    v32 = qcar(v46);
    v46 = stack[-1];
    v46 = qcdr(v46);
    v46 = qcdr(v46);
    v31 = qcar(v46);
    v46 = stack[0];
    fn = elt(env, 1); /* contrsp2 */
    v46 = (*qfnn(fn))(qenv(fn), 3, v32, v31, v46);
    nil = C_nil;
    if (exception_pending()) goto v48;
    env = stack[-2];
    if (!(v46 == nil)) { popv(3); return onevalue(v46); }
    v46 = stack[-1];
    v46 = qcdr(v46);
    v46 = qcdr(v46);
    v32 = qcar(v46);
    v46 = stack[-1];
    v46 = qcdr(v46);
    v31 = qcar(v46);
    v46 = stack[0];
    {
        popv(3);
        fn = elt(env, 1); /* contrsp2 */
        return (*qfnn(fn))(qenv(fn), 3, v32, v31, v46);
    }
/* error exit handlers */
v48:
    popv(3);
    return nil;
}



/* Code for mo_diff */

static Lisp_Object CC_mo_diff(Lisp_Object env,
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
    fn = elt(env, 1); /* mo_neg */
    v1 = (*qfn1(fn))(qenv(fn), v1);
    nil = C_nil;
    if (exception_pending()) goto v13;
    env = stack[-1];
    {
        Lisp_Object v24 = stack[0];
        popv(2);
        fn = elt(env, 2); /* mo_sum */
        return (*qfn2(fn))(qenv(fn), v24, v1);
    }
/* error exit handlers */
v13:
    popv(2);
    return nil;
}



/* Code for c!:extadd */

static Lisp_Object CC_cTextadd(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v327, v79, v80;
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
    stack[0] = nil;
    goto v12;

v12:
    v327 = stack[-2];
    if (v327 == nil) goto v2;
    v327 = stack[-1];
    if (v327 == nil) goto v43;
    v327 = stack[-2];
    v327 = qcar(v327);
    v79 = qcar(v327);
    v327 = stack[-1];
    v327 = qcar(v327);
    v327 = qcar(v327);
    if (equal(v79, v327)) goto v51;
    v327 = stack[-2];
    v327 = qcar(v327);
    v79 = qcar(v327);
    v327 = stack[-1];
    v327 = qcar(v327);
    v327 = qcar(v327);
    fn = elt(env, 1); /* c!:ordexp */
    v327 = (*qfn2(fn))(qenv(fn), v79, v327);
    nil = C_nil;
    if (exception_pending()) goto v133;
    env = stack[-4];
    if (v327 == nil) goto v136;
    v327 = stack[-2];
    v79 = qcar(v327);
    v327 = stack[0];
    v327 = cons(v79, v327);
    nil = C_nil;
    if (exception_pending()) goto v133;
    env = stack[-4];
    stack[0] = v327;
    v327 = stack[-2];
    v327 = qcdr(v327);
    stack[-2] = v327;
    goto v12;

v136:
    v327 = stack[-1];
    v79 = qcar(v327);
    v327 = stack[0];
    v327 = cons(v79, v327);
    nil = C_nil;
    if (exception_pending()) goto v133;
    env = stack[-4];
    stack[0] = v327;
    v327 = stack[-1];
    v327 = qcdr(v327);
    stack[-1] = v327;
    goto v12;

v51:
    stack[-3] = stack[0];
    v327 = stack[-2];
    v327 = qcar(v327);
    v79 = qcdr(v327);
    v327 = stack[-1];
    v327 = qcar(v327);
    v327 = qcdr(v327);
    fn = elt(env, 2); /* addf */
    stack[0] = (*qfn2(fn))(qenv(fn), v79, v327);
    nil = C_nil;
    if (exception_pending()) goto v133;
    env = stack[-4];
    v327 = stack[-2];
    v79 = qcdr(v327);
    v327 = stack[-1];
    v327 = qcdr(v327);
    v327 = CC_cTextadd(env, v79, v327);
    nil = C_nil;
    if (exception_pending()) goto v133;
    env = stack[-4];
    v79 = stack[0];
    v80 = v79;
    if (v80 == nil) goto v50;
    v80 = stack[-2];
    v80 = qcar(v80);
    v80 = qcar(v80);
    v327 = acons(v80, v79, v327);
    nil = C_nil;
    if (exception_pending()) goto v133;
    env = stack[-4];
    goto v50;

v50:
    {
        Lisp_Object v147 = stack[-3];
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v147, v327);
    }

v43:
    v79 = stack[0];
    v327 = stack[-2];
    {
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v79, v327);
    }

v2:
    v79 = stack[0];
    v327 = stack[-1];
    {
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v79, v327);
    }
/* error exit handlers */
v133:
    popv(5);
    return nil;
}



/* Code for flatindxl */

static Lisp_Object CC_flatindxl(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v62, v85, v86;
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
    v62 = v0;
/* end of prologue */
    stack[-3] = v62;
    v62 = stack[-3];
    if (v62 == nil) goto v8;
    v62 = stack[-3];
    v62 = qcar(v62);
    v86 = v62;
    v62 = v86;
    if (!consp(v62)) goto v44;
    v85 = v86;
    v62 = elt(env, 1); /* minus */
    if (!consp(v85)) goto v46;
    v85 = qcar(v85);
    if (!(v85 == v62)) goto v46;
    v62 = v86;
    v62 = qcdr(v62);
    v62 = qcar(v62);
    goto v38;

v38:
    v62 = ncons(v62);
    nil = C_nil;
    if (exception_pending()) goto v234;
    env = stack[-4];
    stack[-1] = v62;
    stack[-2] = v62;
    goto v45;

v45:
    v62 = stack[-3];
    v62 = qcdr(v62);
    stack[-3] = v62;
    v62 = stack[-3];
    if (v62 == nil) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    stack[0] = stack[-1];
    v62 = stack[-3];
    v62 = qcar(v62);
    v86 = v62;
    v62 = v86;
    if (!consp(v62)) goto v67;
    v85 = v86;
    v62 = elt(env, 1); /* minus */
    if (!consp(v85)) goto v60;
    v85 = qcar(v85);
    if (!(v85 == v62)) goto v60;
    v62 = v86;
    v62 = qcdr(v62);
    v62 = qcar(v62);
    goto v69;

v69:
    v62 = ncons(v62);
    nil = C_nil;
    if (exception_pending()) goto v234;
    env = stack[-4];
    v62 = Lrplacd(nil, stack[0], v62);
    nil = C_nil;
    if (exception_pending()) goto v234;
    env = stack[-4];
    v62 = stack[-1];
    v62 = qcdr(v62);
    stack[-1] = v62;
    goto v45;

v60:
    v62 = v86;
    v62 = qcdr(v62);
    goto v69;

v67:
    v62 = v86;
    goto v69;

v46:
    v62 = v86;
    v62 = qcdr(v62);
    goto v38;

v44:
    v62 = v86;
    goto v38;

v8:
    v62 = nil;
    { popv(5); return onevalue(v62); }
/* error exit handlers */
v234:
    popv(5);
    return nil;
}



/* Code for leftzeros */

static Lisp_Object CC_leftzeros(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v39, v40;
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
    v39 = stack[0];
    if (v39 == nil) goto v45;
    v39 = stack[0];
    v40 = qcar(v39);
    v39 = (Lisp_Object)1; /* 0 */
    v39 = Lneq(nil, v40, v39);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-2];
    if (!(v39 == nil)) goto v45;
    v40 = (Lisp_Object)17; /* 1 */
    v39 = stack[-1];
    v39 = cons(v40, v39);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-2];
    stack[-1] = v39;
    v39 = stack[0];
    v39 = qcdr(v39);
    stack[0] = v39;
    goto v12;

v45:
    v39 = (Lisp_Object)1; /* 0 */
    v40 = v39;
    goto v5;

v5:
    v39 = stack[-1];
    if (v39 == nil) { popv(3); return onevalue(v40); }
    v39 = stack[-1];
    v39 = qcar(v39);
    v39 = (Lisp_Object)(int32)((int32)v39 + (int32)v40 - TAG_FIXNUM);
    v40 = v39;
    v39 = stack[-1];
    v39 = qcdr(v39);
    stack[-1] = v39;
    goto v5;
/* error exit handlers */
v64:
    popv(3);
    return nil;
}



/* Code for th_match0 */

static Lisp_Object CC_th_match0(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v30, v99, v10;
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
    v10 = v0;
/* end of prologue */
    v30 = v10;
    v99 = qcar(v30);
    v30 = stack[0];
    v30 = qcar(v30);
    if (equal(v99, v30)) goto v28;
    v30 = nil;
    { popv(3); return onevalue(v30); }

v28:
    v30 = v10;
    v30 = qcdr(v30);
    v30 = qcar(v30);
    stack[-1] = Llength(nil, v30);
    nil = C_nil;
    if (exception_pending()) goto v46;
    env = stack[-2];
    v30 = stack[0];
    v30 = qcdr(v30);
    v30 = qcar(v30);
    v30 = Llength(nil, v30);
    nil = C_nil;
    if (exception_pending()) goto v46;
    v30 = (equal(stack[-1], v30) ? lisp_true : nil);
    { popv(3); return onevalue(v30); }
/* error exit handlers */
v46:
    popv(3);
    return nil;
}



/* Code for tokquote */

static Lisp_Object MS_CDECL CC_tokquote(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v5;
    Lisp_Object fn;
    argcheck(nargs, 0, "tokquote");
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* end of prologue */
    fn = elt(env, 4); /* readch1 */
    v5 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v6;
    env = stack[0];
    qvalue(elt(env, 1)) = v5; /* crchar!* */
    fn = elt(env, 5); /* rread */
    v5 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v6;
    env = stack[0];
    v5 = Lmkquote(nil, v5);
    nil = C_nil;
    if (exception_pending()) goto v6;
    env = stack[0];
    qvalue(elt(env, 2)) = v5; /* nxtsym!* */
    v5 = (Lisp_Object)65; /* 4 */
    qvalue(elt(env, 3)) = v5; /* ttype!* */
    v5 = qvalue(elt(env, 2)); /* nxtsym!* */
    { popv(1); return onevalue(v5); }
/* error exit handlers */
v6:
    popv(1);
    return nil;
}



/* Code for plus!: */

static Lisp_Object CC_plusT(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v116, v114, v115, v132;
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
    v115 = v16;
    v132 = v0;
/* end of prologue */
    v116 = v132;
    v116 = qcdr(v116);
    v114 = qcar(v116);
    stack[-1] = v114;
    v116 = (Lisp_Object)1; /* 0 */
    if (v114 == v116) { popv(6); return onevalue(v115); }
    v116 = v115;
    v116 = qcdr(v116);
    v114 = qcar(v116);
    stack[0] = v114;
    v116 = (Lisp_Object)1; /* 0 */
    if (v114 == v116) { popv(6); return onevalue(v132); }
    v116 = v132;
    v116 = qcdr(v116);
    v116 = qcdr(v116);
    stack[-4] = v116;
    v114 = v115;
    v114 = qcdr(v114);
    v114 = qcdr(v114);
    stack[-2] = v114;
    v114 = difference2(v116, v114);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-5];
    stack[-3] = v114;
    v116 = (Lisp_Object)1; /* 0 */
    if (v114 == v116) goto v64;
    v114 = stack[-3];
    v116 = (Lisp_Object)1; /* 0 */
    v116 = (Lisp_Object)greaterp2(v114, v116);
    nil = C_nil;
    if (exception_pending()) goto v78;
    v116 = v116 ? lisp_true : nil;
    env = stack[-5];
    if (v116 == nil) goto v81;
    stack[-4] = elt(env, 1); /* !:rd!: */
    v114 = stack[-1];
    v116 = stack[-3];
    v114 = Lash1(nil, v114, v116);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-5];
    v116 = stack[0];
    v114 = plus2(v114, v116);
    nil = C_nil;
    if (exception_pending()) goto v78;
    v116 = stack[-2];
    {
        Lisp_Object v230 = stack[-4];
        popv(6);
        return list2star(v230, v114, v116);
    }

v81:
    stack[-2] = elt(env, 1); /* !:rd!: */
    v116 = stack[-3];
    v116 = negate(v116);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-5];
    v116 = Lash1(nil, stack[0], v116);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-5];
    v114 = plus2(stack[-1], v116);
    nil = C_nil;
    if (exception_pending()) goto v78;
    v116 = stack[-4];
    {
        Lisp_Object v468 = stack[-2];
        popv(6);
        return list2star(v468, v114, v116);
    }

v64:
    stack[-2] = elt(env, 1); /* !:rd!: */
    v114 = stack[-1];
    v116 = stack[0];
    v114 = plus2(v114, v116);
    nil = C_nil;
    if (exception_pending()) goto v78;
    v116 = stack[-4];
    {
        Lisp_Object v149 = stack[-2];
        popv(6);
        return list2star(v149, v114, v116);
    }
/* error exit handlers */
v78:
    popv(6);
    return nil;
}



/* Code for treesizep1 */

static Lisp_Object CC_treesizep1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v53, v14;
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
    v53 = stack[-1];
    if (!consp(v53)) goto v5;
    v53 = stack[-1];
    v14 = qcar(v53);
    v53 = stack[0];
    v14 = CC_treesizep1(env, v14, v53);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-2];
    stack[0] = v14;
    v53 = (Lisp_Object)1; /* 0 */
    v53 = (Lisp_Object)greaterp2(v14, v53);
    nil = C_nil;
    if (exception_pending()) goto v32;
    v53 = v53 ? lisp_true : nil;
    env = stack[-2];
    if (v53 == nil) goto v30;
    v53 = stack[-1];
    v53 = qcdr(v53);
    stack[-1] = v53;
    goto v4;

v30:
    v53 = (Lisp_Object)1; /* 0 */
    { popv(3); return onevalue(v53); }

v5:
    v53 = stack[0];
    popv(3);
    return sub1(v53);
/* error exit handlers */
v32:
    popv(3);
    return nil;
}



/* Code for scalopp */

static Lisp_Object CC_scalopp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v460, v183, v256;
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
/* copy arguments values to proper place */
    stack[-3] = v0;
/* end of prologue */
    v460 = stack[-3];
    if (symbolp(v460)) goto v28;
    v460 = nil;
    goto v12;

v12:
    if (!(v460 == nil)) { popv(6); return onevalue(v460); }
    v460 = stack[-3];
    if (!consp(v460)) goto v21;
    v460 = stack[-3];
    v183 = qcar(v460);
    v460 = elt(env, 1); /* phystype */
    v183 = get(v183, v460);
    env = stack[-5];
    v460 = elt(env, 2); /* scalar */
    v460 = (v183 == v460 ? lisp_true : nil);
    if (!(v460 == nil)) { popv(6); return onevalue(v460); }
    v460 = stack[-3];
    v183 = qcar(v460);
    v460 = elt(env, 1); /* phystype */
    v183 = get(v183, v460);
    env = stack[-5];
    v460 = elt(env, 3); /* vector */
    if (v183 == v460) goto v55;
    v460 = nil;
    goto v64;

v64:
    if (!(v460 == nil)) { popv(6); return onevalue(v460); }
    v460 = stack[-3];
    v183 = qcar(v460);
    v460 = elt(env, 1); /* phystype */
    v183 = get(v183, v460);
    env = stack[-5];
    v460 = elt(env, 4); /* tensor */
    if (v183 == v460) goto v237;
    v460 = nil;
    { popv(6); return onevalue(v460); }

v237:
    v460 = stack[-3];
    v460 = qcdr(v460);
    v256 = Llength(nil, v460);
    nil = C_nil;
    if (exception_pending()) goto v350;
    env = stack[-5];
    v460 = stack[-3];
    v183 = qcar(v460);
    v460 = elt(env, 5); /* tensdimen */
    v460 = get(v183, v460);
    env = stack[-5];
    v460 = (Lisp_Object)geq2(v256, v460);
    nil = C_nil;
    if (exception_pending()) goto v350;
    v460 = v460 ? lisp_true : nil;
    env = stack[-5];
    if (v460 == nil) goto v456;
    v460 = (Lisp_Object)17; /* 1 */
    stack[-4] = v460;
    v460 = stack[-3];
    v183 = qcar(v460);
    v460 = elt(env, 5); /* tensdimen */
    v183 = get(v183, v460);
    env = stack[-5];
    v460 = stack[-4];
    v460 = difference2(v183, v460);
    nil = C_nil;
    if (exception_pending()) goto v350;
    env = stack[-5];
    v460 = Lminusp(nil, v460);
    env = stack[-5];
    if (v460 == nil) goto v229;
    v460 = nil;
    goto v235;

v235:
    {
        popv(6);
        fn = elt(env, 6); /* areallindices */
        return (*qfn1(fn))(qenv(fn), v460);
    }

v229:
    v460 = stack[-3];
    v183 = qcdr(v460);
    v460 = stack[-4];
    fn = elt(env, 7); /* nth */
    v460 = (*qfn2(fn))(qenv(fn), v183, v460);
    nil = C_nil;
    if (exception_pending()) goto v350;
    env = stack[-5];
    v460 = ncons(v460);
    nil = C_nil;
    if (exception_pending()) goto v350;
    env = stack[-5];
    stack[-1] = v460;
    stack[-2] = v460;
    goto v137;

v137:
    v460 = stack[-4];
    v460 = add1(v460);
    nil = C_nil;
    if (exception_pending()) goto v350;
    env = stack[-5];
    stack[-4] = v460;
    v460 = stack[-3];
    v183 = qcar(v460);
    v460 = elt(env, 5); /* tensdimen */
    v183 = get(v183, v460);
    env = stack[-5];
    v460 = stack[-4];
    v460 = difference2(v183, v460);
    nil = C_nil;
    if (exception_pending()) goto v350;
    env = stack[-5];
    v460 = Lminusp(nil, v460);
    env = stack[-5];
    if (v460 == nil) goto v180;
    v460 = stack[-2];
    goto v235;

v180:
    stack[0] = stack[-1];
    v460 = stack[-3];
    v183 = qcdr(v460);
    v460 = stack[-4];
    fn = elt(env, 7); /* nth */
    v460 = (*qfn2(fn))(qenv(fn), v183, v460);
    nil = C_nil;
    if (exception_pending()) goto v350;
    env = stack[-5];
    v460 = ncons(v460);
    nil = C_nil;
    if (exception_pending()) goto v350;
    env = stack[-5];
    v460 = Lrplacd(nil, stack[0], v460);
    nil = C_nil;
    if (exception_pending()) goto v350;
    env = stack[-5];
    v460 = stack[-1];
    v460 = qcdr(v460);
    stack[-1] = v460;
    goto v137;

v456:
    v460 = nil;
    { popv(6); return onevalue(v460); }

v55:
    v460 = stack[-3];
    v460 = qcdr(v460);
    v460 = qcar(v460);
    fn = elt(env, 8); /* isanindex */
    v460 = (*qfn1(fn))(qenv(fn), v460);
    nil = C_nil;
    if (exception_pending()) goto v350;
    env = stack[-5];
    goto v64;

v21:
    v460 = nil;
    { popv(6); return onevalue(v460); }

v28:
    v183 = stack[-3];
    v460 = elt(env, 1); /* phystype */
    v183 = get(v183, v460);
    env = stack[-5];
    v460 = elt(env, 2); /* scalar */
    v460 = (v183 == v460 ? lisp_true : nil);
    goto v12;
/* error exit handlers */
v350:
    popv(6);
    return nil;
}



/* Code for b!:extmult */

static Lisp_Object CC_bTextmult(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v132, v133;
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
    v132 = stack[-3];
    if (v132 == nil) goto v4;
    v132 = stack[-2];
    if (v132 == nil) goto v4;
    v133 = stack[-2];
    v132 = (Lisp_Object)17; /* 1 */
    if (v133 == v132) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v132 = stack[-3];
    v132 = qcar(v132);
    v132 = qcar(v132);
    v133 = qcar(v132);
    v132 = stack[-2];
    v132 = qcar(v132);
    v132 = qcar(v132);
    fn = elt(env, 1); /* b!:ordexn */
    v132 = (*qfn2(fn))(qenv(fn), v133, v132);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[-5];
    v133 = v132;
    v132 = v133;
    if (v132 == nil) goto v223;
    v132 = v133;
    stack[-4] = qcdr(v132);
    v132 = v133;
    v132 = qcar(v132);
    if (v132 == nil) goto v58;
    v132 = stack[-3];
    v132 = qcar(v132);
    v133 = qcdr(v132);
    v132 = stack[-2];
    v132 = qcar(v132);
    v132 = qcdr(v132);
    fn = elt(env, 2); /* multf */
    v132 = (*qfn2(fn))(qenv(fn), v133, v132);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[-5];
    fn = elt(env, 3); /* negf */
    v132 = (*qfn1(fn))(qenv(fn), v132);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[-5];
    stack[-1] = v132;
    goto v234;

v234:
    v132 = stack[-3];
    v132 = qcar(v132);
    v133 = ncons(v132);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[-5];
    v132 = stack[-2];
    v132 = qcdr(v132);
    stack[0] = CC_bTextmult(env, v133, v132);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[-5];
    v132 = stack[-3];
    v133 = qcdr(v132);
    v132 = stack[-2];
    v132 = CC_bTextmult(env, v133, v132);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[-5];
    fn = elt(env, 4); /* b!:extadd */
    v132 = (*qfn2(fn))(qenv(fn), stack[0], v132);
    nil = C_nil;
    if (exception_pending()) goto v230;
    {
        Lisp_Object v468 = stack[-4];
        Lisp_Object v149 = stack[-1];
        popv(6);
        return acons(v468, v149, v132);
    }

v58:
    v132 = stack[-3];
    v132 = qcar(v132);
    v133 = qcdr(v132);
    v132 = stack[-2];
    v132 = qcar(v132);
    v132 = qcdr(v132);
    fn = elt(env, 2); /* multf */
    v132 = (*qfn2(fn))(qenv(fn), v133, v132);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[-5];
    stack[-1] = v132;
    goto v234;

v223:
    v132 = stack[-3];
    v133 = qcdr(v132);
    v132 = stack[-2];
    stack[0] = CC_bTextmult(env, v133, v132);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[-5];
    v132 = stack[-3];
    v132 = qcar(v132);
    v133 = ncons(v132);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[-5];
    v132 = stack[-2];
    v132 = qcdr(v132);
    v132 = CC_bTextmult(env, v133, v132);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[-5];
    {
        Lisp_Object v111 = stack[0];
        popv(6);
        fn = elt(env, 4); /* b!:extadd */
        return (*qfn2(fn))(qenv(fn), v111, v132);
    }

v4:
    v132 = nil;
    { popv(6); return onevalue(v132); }
/* error exit handlers */
v230:
    popv(6);
    return nil;
}



/* Code for conv!:mt */

static Lisp_Object CC_convTmt(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v116, v114;
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
    stack[0] = v16;
    stack[-2] = v0;
/* end of prologue */
    v114 = stack[-2];
    v116 = elt(env, 1); /* !:rd!: */
    if (!consp(v114)) goto v326;
    v114 = qcar(v114);
    if (!(v114 == v116)) goto v326;
    v116 = stack[-2];
    v116 = qcdr(v116);
    if (!consp(v116)) goto v326;
    v116 = stack[0];
    v116 = integerp(v116);
    if (v116 == nil) goto v326;
    v114 = stack[0];
    v116 = (Lisp_Object)1; /* 0 */
    v116 = (Lisp_Object)greaterp2(v114, v116);
    nil = C_nil;
    if (exception_pending()) goto v148;
    v116 = v116 ? lisp_true : nil;
    env = stack[-4];
    if (v116 == nil) goto v326;
    v116 = stack[-2];
    v116 = qcdr(v116);
    v116 = qcar(v116);
    v116 = Labsval(nil, v116);
    nil = C_nil;
    if (exception_pending()) goto v148;
    env = stack[-4];
    fn = elt(env, 2); /* msd */
    v114 = (*qfn1(fn))(qenv(fn), v116);
    nil = C_nil;
    if (exception_pending()) goto v148;
    env = stack[-4];
    v116 = stack[0];
    v114 = difference2(v114, v116);
    nil = C_nil;
    if (exception_pending()) goto v148;
    env = stack[-4];
    stack[0] = v114;
    v116 = (Lisp_Object)1; /* 0 */
    if (v114 == v116) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v114 = stack[0];
    v116 = (Lisp_Object)1; /* 0 */
    v116 = (Lisp_Object)lessp2(v114, v116);
    nil = C_nil;
    if (exception_pending()) goto v148;
    v116 = v116 ? lisp_true : nil;
    env = stack[-4];
    if (v116 == nil) goto v96;
    v116 = stack[0];
    v116 = negate(v116);
    nil = C_nil;
    if (exception_pending()) goto v148;
    env = stack[-4];
    stack[-3] = v116;
    stack[-1] = elt(env, 1); /* !:rd!: */
    v116 = stack[-2];
    v116 = qcdr(v116);
    v114 = qcar(v116);
    v116 = stack[-3];
    stack[0] = Lash1(nil, v114, v116);
    nil = C_nil;
    if (exception_pending()) goto v148;
    env = stack[-4];
    v116 = stack[-2];
    v116 = qcdr(v116);
    v114 = qcdr(v116);
    v116 = stack[-3];
    v116 = difference2(v114, v116);
    nil = C_nil;
    if (exception_pending()) goto v148;
    {
        Lisp_Object v213 = stack[-1];
        Lisp_Object v77 = stack[0];
        popv(5);
        return list2star(v213, v77, v116);
    }

v96:
    v116 = stack[0];
    v116 = sub1(v116);
    nil = C_nil;
    if (exception_pending()) goto v148;
    env = stack[-4];
    stack[-3] = v116;
    stack[-1] = elt(env, 1); /* !:rd!: */
    v116 = stack[-2];
    v116 = qcdr(v116);
    stack[0] = qcar(v116);
    v116 = stack[-3];
    v116 = negate(v116);
    nil = C_nil;
    if (exception_pending()) goto v148;
    env = stack[-4];
    stack[0] = Lash1(nil, stack[0], v116);
    nil = C_nil;
    if (exception_pending()) goto v148;
    env = stack[-4];
    v116 = stack[-2];
    v116 = qcdr(v116);
    v114 = qcdr(v116);
    v116 = stack[-3];
    v116 = plus2(v114, v116);
    nil = C_nil;
    if (exception_pending()) goto v148;
    env = stack[-4];
    v116 = list2star(stack[-1], stack[0], v116);
    nil = C_nil;
    if (exception_pending()) goto v148;
    env = stack[-4];
    {
        popv(5);
        fn = elt(env, 3); /* round!:last */
        return (*qfn1(fn))(qenv(fn), v116);
    }

v326:
    v116 = elt(env, 0); /* conv!:mt */
    {
        popv(5);
        fn = elt(env, 4); /* bflerrmsg */
        return (*qfn1(fn))(qenv(fn), v116);
    }
/* error exit handlers */
v148:
    popv(5);
    return nil;
}



/* Code for horner!-rule */

static Lisp_Object MS_CDECL CC_hornerKrule(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v16,
                         Lisp_Object v63, Lisp_Object v9, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v257, v308, v309, v351;
    Lisp_Object fn;
    argcheck(nargs, 4, "horner-rule");
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

v11:
    v257 = stack[-2];
    if (!consp(v257)) goto v45;
    v257 = stack[-2];
    v257 = qcar(v257);
    if (!consp(v257)) goto v45;
    v257 = stack[-2];
    v257 = qcar(v257);
    v257 = qcar(v257);
    v308 = qcar(v257);
    v257 = stack[-1];
    v257 = qcar(v257);
    v257 = qcar(v257);
    if (equal(v308, v257)) goto v119;
    v257 = stack[-1];
    v257 = qcar(v257);
    v257 = qcdr(v257);
    v257 = (Lisp_Object)zerop(v257);
    v257 = v257 ? lisp_true : nil;
    env = stack[-6];
    if (v257 == nil) goto v141;
    v308 = stack[-2];
    v257 = stack[-1];
    v257 = qcdr(v257);
    {
        popv(7);
        fn = elt(env, 1); /* evaluate!-in!-order */
        return (*qfn2(fn))(qenv(fn), v308, v257);
    }

v141:
    v308 = stack[-2];
    v257 = stack[-1];
    v257 = qcdr(v257);
    fn = elt(env, 1); /* evaluate!-in!-order */
    stack[0] = (*qfn2(fn))(qenv(fn), v308, v257);
    nil = C_nil;
    if (exception_pending()) goto v210;
    env = stack[-6];
    stack[-2] = stack[-4];
    v257 = stack[-1];
    v257 = qcar(v257);
    v308 = qcdr(v257);
    v257 = stack[-3];
    v257 = Lexpt(nil, v308, v257);
    nil = C_nil;
    if (exception_pending()) goto v210;
    env = stack[-6];
    v257 = times2(stack[-2], v257);
    nil = C_nil;
    if (exception_pending()) goto v210;
    {
        Lisp_Object v200 = stack[0];
        popv(7);
        return plus2(v200, v257);
    }

v119:
    v257 = stack[-2];
    v257 = qcar(v257);
    v257 = qcar(v257);
    v257 = qcdr(v257);
    stack[-5] = v257;
    v257 = stack[-1];
    v257 = qcar(v257);
    v257 = qcdr(v257);
    v257 = (Lisp_Object)zerop(v257);
    v257 = v257 ? lisp_true : nil;
    env = stack[-6];
    if (v257 == nil) goto v215;
    v257 = stack[-2];
    v257 = qcar(v257);
    v308 = qcdr(v257);
    v257 = stack[-1];
    v257 = qcdr(v257);
    fn = elt(env, 1); /* evaluate!-in!-order */
    v257 = (*qfn2(fn))(qenv(fn), v308, v257);
    nil = C_nil;
    if (exception_pending()) goto v210;
    env = stack[-6];
    v351 = v257;
    goto v219;

v219:
    v309 = stack[-5];
    v257 = stack[-2];
    v308 = qcdr(v257);
    v257 = stack[-1];
    stack[-4] = v351;
    stack[-3] = v309;
    stack[-2] = v308;
    stack[-1] = v257;
    goto v11;

v215:
    v257 = stack[-2];
    v257 = qcar(v257);
    v308 = qcdr(v257);
    v257 = stack[-1];
    v257 = qcdr(v257);
    fn = elt(env, 1); /* evaluate!-in!-order */
    stack[0] = (*qfn2(fn))(qenv(fn), v308, v257);
    nil = C_nil;
    if (exception_pending()) goto v210;
    env = stack[-6];
    v257 = stack[-1];
    v257 = qcar(v257);
    v309 = qcdr(v257);
    v308 = stack[-3];
    v257 = stack[-5];
    v257 = (Lisp_Object)(int32)((int32)v308 - (int32)v257 + TAG_FIXNUM);
    v257 = Lexpt(nil, v309, v257);
    nil = C_nil;
    if (exception_pending()) goto v210;
    env = stack[-6];
    v257 = times2(stack[-4], v257);
    nil = C_nil;
    if (exception_pending()) goto v210;
    env = stack[-6];
    v257 = plus2(stack[0], v257);
    nil = C_nil;
    if (exception_pending()) goto v210;
    env = stack[-6];
    v351 = v257;
    goto v219;

v45:
    v257 = stack[-1];
    v257 = qcar(v257);
    v257 = qcdr(v257);
    v257 = (Lisp_Object)zerop(v257);
    v257 = v257 ? lisp_true : nil;
    env = stack[-6];
    if (v257 == nil) goto v18;
    v257 = stack[-2];
    {
        popv(7);
        fn = elt(env, 2); /* !*d2n */
        return (*qfn1(fn))(qenv(fn), v257);
    }

v18:
    v257 = stack[-2];
    fn = elt(env, 2); /* !*d2n */
    stack[0] = (*qfn1(fn))(qenv(fn), v257);
    nil = C_nil;
    if (exception_pending()) goto v210;
    env = stack[-6];
    stack[-2] = stack[-4];
    v257 = stack[-1];
    v257 = qcar(v257);
    v308 = qcdr(v257);
    v257 = stack[-3];
    v257 = Lexpt(nil, v308, v257);
    nil = C_nil;
    if (exception_pending()) goto v210;
    env = stack[-6];
    v257 = times2(stack[-2], v257);
    nil = C_nil;
    if (exception_pending()) goto v210;
    {
        Lisp_Object v209 = stack[0];
        popv(7);
        return plus2(v209, v257);
    }
/* error exit handlers */
v210:
    popv(7);
    return nil;
}



/* Code for xord_lex */

static Lisp_Object CC_xord_lex(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v67, v68, v56, v54;
    Lisp_Object fn;
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v68 = v16;
    v56 = v0;
/* end of prologue */

v4:
    v67 = v56;
    if (v67 == nil) goto v5;
    v67 = v56;
    v54 = qcar(v67);
    v67 = (Lisp_Object)17; /* 1 */
    if (v54 == v67) goto v5;
    v67 = v68;
    if (v67 == nil) goto v47;
    v67 = v68;
    v54 = qcar(v67);
    v67 = (Lisp_Object)17; /* 1 */
    if (v54 == v67) goto v47;
    v67 = v56;
    v54 = qcar(v67);
    v67 = v68;
    v67 = qcar(v67);
    if (v54 == v67) goto v53;
    v67 = v56;
    v67 = qcar(v67);
    v68 = qcar(v68);
    {
        fn = elt(env, 1); /* factorordp */
        return (*qfn2(fn))(qenv(fn), v67, v68);
    }

v53:
    v67 = v56;
    v67 = qcdr(v67);
    v56 = v67;
    v67 = v68;
    v67 = qcdr(v67);
    v68 = v67;
    goto v4;

v47:
    v67 = lisp_true;
    return onevalue(v67);

v5:
    v67 = nil;
    return onevalue(v67);
}



/* Code for errorset2 */

static Lisp_Object CC_errorset2(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v26, v27, v28;
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
    v27 = v0;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* !*protfg */
    qvalue(elt(env, 1)) = nil; /* !*protfg */
    v26 = lisp_true;
    qvalue(elt(env, 1)) = v26; /* !*protfg */
    v28 = v27;
    v27 = nil;
    v26 = nil;
    fn = elt(env, 2); /* errorset */
    v26 = (*qfnn(fn))(qenv(fn), 3, v28, v27, v26);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-1];
    qvalue(elt(env, 1)) = stack[0]; /* !*protfg */
    { popv(2); return onevalue(v26); }
/* error exit handlers */
v44:
    env = stack[-1];
    qvalue(elt(env, 1)) = stack[0]; /* !*protfg */
    popv(2);
    return nil;
}



/* Code for exptmod!: */

static Lisp_Object CC_exptmodT(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v2, v25;
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
    v2 = v16;
    v25 = v0;
/* end of prologue */
    v25 = qcdr(v25);
    fn = elt(env, 1); /* general!-modular!-expt */
    v2 = (*qfn2(fn))(qenv(fn), v25, v2);
    nil = C_nil;
    if (exception_pending()) goto v13;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* !*modular2f */
        return (*qfn1(fn))(qenv(fn), v2);
    }
/* error exit handlers */
v13:
    popv(1);
    return nil;
}



/* Code for symbid */

static Lisp_Object CC_symbid(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v101, v57, v72, v122;
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
    v72 = v16;
    stack[0] = v0;
/* end of prologue */
    v101 = qvalue(elt(env, 1)); /* fname!* */
    if (v101 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v57 = qvalue(elt(env, 2)); /* ftype!* */
    v101 = elt(env, 3); /* (macro smacro) */
    v101 = Lmemq(nil, v57, v101);
    if (!(v101 == nil)) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v101 = stack[0];
    v57 = v72;
    v101 = Latsoc(nil, v101, v57);
    if (!(v101 == nil)) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v101 = stack[0];
    v101 = Lsymbol_specialp(nil, v101);
    nil = C_nil;
    if (exception_pending()) goto v55;
    env = stack[-1];
    if (!(v101 == nil)) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v101 = stack[0];
    v101 = Lsymbol_globalp(nil, v101);
    env = stack[-1];
    if (!(v101 == nil)) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v101 = stack[0];
    if (v101 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v57 = stack[0];
    v101 = lisp_true;
    if (v57 == v101) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v57 = stack[0];
    v101 = elt(env, 4); /* share */
    v101 = Lflagp(nil, v57, v101);
    env = stack[-1];
    if (!(v101 == nil)) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v101 = qvalue(elt(env, 5)); /* !*comp */
    if (!(v101 == nil)) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v122 = elt(env, 6); /* "nonlocal use of undeclared variable" */
    v72 = stack[0];
    v57 = elt(env, 7); /* "in procedure" */
    v101 = qvalue(elt(env, 1)); /* fname!* */
    v101 = list4(v122, v72, v57, v101);
    nil = C_nil;
    if (exception_pending()) goto v55;
    env = stack[-1];
    fn = elt(env, 8); /* lprim */
    v101 = (*qfn1(fn))(qenv(fn), v101);
    nil = C_nil;
    if (exception_pending()) goto v55;
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
/* error exit handlers */
v55:
    popv(2);
    return nil;
}



/* Code for powers2 */

static Lisp_Object MS_CDECL CC_powers2(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v16,
                         Lisp_Object v63, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v105, v69, v67;
    Lisp_Object fn;
    argcheck(nargs, 3, "powers2");
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
    v105 = stack[-2];
    if (!consp(v105)) goto v7;
    v105 = stack[-2];
    v105 = qcar(v105);
    if (!consp(v105)) goto v7;
    v105 = stack[-2];
    v105 = qcar(v105);
    v105 = qcdr(v105);
    stack[-3] = v105;
    v105 = stack[-2];
    v67 = qcdr(v105);
    v69 = stack[-1];
    v105 = stack[0];
    v105 = CC_powers2(env, 3, v67, v69, v105);
    nil = C_nil;
    if (exception_pending()) goto v66;
    env = stack[-4];
    stack[-1] = v105;
    v105 = stack[-2];
    v105 = qcar(v105);
    v69 = qcar(v105);
    v105 = stack[0];
    v105 = cons(v69, v105);
    nil = C_nil;
    if (exception_pending()) goto v66;
    env = stack[-4];
    stack[0] = v105;
    v105 = stack[-3];
    stack[-2] = v105;
    goto v45;

v7:
    v105 = stack[-2];
    if (v105 == nil) { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }
    v69 = stack[0];
    v105 = stack[-1];
    {
        popv(5);
        fn = elt(env, 1); /* powers4 */
        return (*qfn2(fn))(qenv(fn), v69, v105);
    }
/* error exit handlers */
v66:
    popv(5);
    return nil;
}



/* Code for mksgnsq */

static Lisp_Object CC_mksgnsq(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v34, v39, v40;
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
    v39 = v0;
/* end of prologue */
    v34 = v39;
    fn = elt(env, 1); /* evenfree */
    v34 = (*qfn1(fn))(qenv(fn), v34);
    nil = C_nil;
    if (exception_pending()) goto v41;
    env = stack[-1];
    v39 = v34;
    if (v34 == nil) goto v6;
    v40 = v39;
    v34 = (Lisp_Object)17; /* 1 */
    if (v40 == v34) goto v17;
    stack[0] = (Lisp_Object)-15; /* -1 */
    v34 = (Lisp_Object)17; /* 1 */
    v34 = cons(v39, v34);
    nil = C_nil;
    if (exception_pending()) goto v41;
    env = stack[-1];
    fn = elt(env, 2); /* mk!*sq */
    v34 = (*qfn1(fn))(qenv(fn), v34);
    nil = C_nil;
    if (exception_pending()) goto v41;
    env = stack[-1];
    v34 = list2(stack[0], v34);
    nil = C_nil;
    if (exception_pending()) goto v41;
    env = stack[-1];
    {
        popv(2);
        fn = elt(env, 3); /* simpexpt */
        return (*qfn1(fn))(qenv(fn), v34);
    }

v17:
    v39 = (Lisp_Object)-15; /* -1 */
    v34 = (Lisp_Object)17; /* 1 */
    popv(2);
    return cons(v39, v34);

v6:
    v39 = (Lisp_Object)17; /* 1 */
    v34 = (Lisp_Object)17; /* 1 */
    popv(2);
    return cons(v39, v34);
/* error exit handlers */
v41:
    popv(2);
    return nil;
}



/* Code for ncmpchk */

static Lisp_Object CC_ncmpchk(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v15, v43;
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
    v43 = stack[-1];
    v15 = stack[0];
    fn = elt(env, 1); /* noncommuting */
    v15 = (*qfn2(fn))(qenv(fn), v43, v15);
    nil = C_nil;
    if (exception_pending()) goto v18;
    env = stack[-2];
    v15 = (v15 == nil ? lisp_true : nil);
    if (!(v15 == nil)) { popv(3); return onevalue(v15); }
    v43 = stack[-1];
    v15 = stack[0];
    {
        popv(3);
        fn = elt(env, 2); /* ordop */
        return (*qfn2(fn))(qenv(fn), v43, v15);
    }
/* error exit handlers */
v18:
    popv(3);
    return nil;
}



/* Code for mv!-domainlist!-!- */

static Lisp_Object CC_mvKdomainlistKK(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v14, v46;
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
    stack[-2] = nil;
    goto v12;

v12:
    v14 = stack[-1];
    if (v14 == nil) goto v6;
    v14 = stack[-1];
    v46 = qcar(v14);
    v14 = stack[0];
    v14 = qcar(v14);
    v46 = difference2(v46, v14);
    nil = C_nil;
    if (exception_pending()) goto v36;
    env = stack[-3];
    v14 = stack[-2];
    v14 = cons(v46, v14);
    nil = C_nil;
    if (exception_pending()) goto v36;
    env = stack[-3];
    stack[-2] = v14;
    v14 = stack[-1];
    v14 = qcdr(v14);
    stack[-1] = v14;
    v14 = stack[0];
    v14 = qcdr(v14);
    stack[0] = v14;
    goto v12;

v6:
    v14 = stack[-2];
    {
        popv(4);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v14);
    }
/* error exit handlers */
v36:
    popv(4);
    return nil;
}



/* Code for make!-term */

static Lisp_Object MS_CDECL CC_makeKterm(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v16,
                         Lisp_Object v63, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v256, v210, v200;
    Lisp_Object fn;
    argcheck(nargs, 3, "make-term");
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
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-3] = v63;
    stack[-4] = v16;
    stack[-5] = v0;
/* end of prologue */
    v256 = (Lisp_Object)1; /* 0 */
    stack[-2] = v256;
    v256 = (Lisp_Object)1; /* 0 */
    stack[0] = v256;
    goto v47;

v47:
    v210 = stack[-4];
    v256 = stack[0];
    v210 = *(Lisp_Object *)((char *)v210 + (CELL-TAG_VECTOR) + ((int32)v256/(16/CELL)));
    v256 = (Lisp_Object)1; /* 0 */
    v256 = (Lisp_Object)lessp2(v210, v256);
    nil = C_nil;
    if (exception_pending()) goto v208;
    v256 = v256 ? lisp_true : nil;
    env = stack[-7];
    if (v256 == nil) goto v32;
    v256 = (Lisp_Object)-15; /* -1 */
    stack[-2] = v256;
    goto v2;

v2:
    v256 = (Lisp_Object)49; /* 3 */
    v256 = Lmkvect(nil, v256);
    nil = C_nil;
    if (exception_pending()) goto v208;
    env = stack[-7];
    stack[-6] = v256;
    v210 = stack[-2];
    v256 = (Lisp_Object)17; /* 1 */
    if (v210 == v256) goto v96;
    v210 = stack[-5];
    v256 = elt(env, 2); /* cos */
    if (v210 == v256) goto v96;
    stack[-1] = stack[-6];
    stack[0] = (Lisp_Object)1; /* 0 */
    v210 = elt(env, 3); /* (-1 . 1) */
    v256 = stack[-3];
    fn = elt(env, 4); /* multsq */
    v256 = (*qfn2(fn))(qenv(fn), v210, v256);
    nil = C_nil;
    if (exception_pending()) goto v208;
    env = stack[-7];
    *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32)stack[0]/(16/CELL))) = v256;
    goto v231;

v231:
    v200 = stack[-6];
    v210 = (Lisp_Object)17; /* 1 */
    v256 = stack[-5];
    *(Lisp_Object *)((char *)v200 + (CELL-TAG_VECTOR) + ((int32)v210/(16/CELL))) = v256;
    v210 = stack[-2];
    v256 = (Lisp_Object)-15; /* -1 */
    if (!(v210 == v256)) goto v261;
    v256 = (Lisp_Object)113; /* 7 */
    v256 = Lmkvect(nil, v256);
    nil = C_nil;
    if (exception_pending()) goto v208;
    env = stack[-7];
    stack[-2] = v256;
    v256 = (Lisp_Object)1; /* 0 */
    stack[-3] = v256;
    goto v189;

v189:
    v210 = (Lisp_Object)113; /* 7 */
    v256 = stack[-3];
    v256 = difference2(v210, v256);
    nil = C_nil;
    if (exception_pending()) goto v208;
    env = stack[-7];
    v256 = Lminusp(nil, v256);
    env = stack[-7];
    if (v256 == nil) goto v127;
    v256 = stack[-2];
    stack[-4] = v256;
    goto v261;

v261:
    v200 = stack[-6];
    v210 = (Lisp_Object)33; /* 2 */
    v256 = stack[-4];
    *(Lisp_Object *)((char *)v200 + (CELL-TAG_VECTOR) + ((int32)v210/(16/CELL))) = v256;
    v200 = stack[-6];
    v210 = (Lisp_Object)49; /* 3 */
    v256 = nil;
    *(Lisp_Object *)((char *)v200 + (CELL-TAG_VECTOR) + ((int32)v210/(16/CELL))) = v256;
    { Lisp_Object res = stack[-6]; popv(8); return onevalue(res); }

v127:
    stack[-1] = stack[-2];
    stack[0] = stack[-3];
    v210 = stack[-4];
    v256 = stack[-3];
    v256 = *(Lisp_Object *)((char *)v210 + (CELL-TAG_VECTOR) + ((int32)v256/(16/CELL)));
    v256 = negate(v256);
    nil = C_nil;
    if (exception_pending()) goto v208;
    env = stack[-7];
    *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32)stack[0]/(16/CELL))) = v256;
    v256 = stack[-3];
    v256 = add1(v256);
    nil = C_nil;
    if (exception_pending()) goto v208;
    env = stack[-7];
    stack[-3] = v256;
    goto v189;

v96:
    v200 = stack[-6];
    v210 = (Lisp_Object)1; /* 0 */
    v256 = stack[-3];
    *(Lisp_Object *)((char *)v200 + (CELL-TAG_VECTOR) + ((int32)v210/(16/CELL))) = v256;
    goto v231;

v32:
    v210 = stack[-4];
    v256 = stack[0];
    v210 = *(Lisp_Object *)((char *)v210 + (CELL-TAG_VECTOR) + ((int32)v256/(16/CELL)));
    v256 = (Lisp_Object)1; /* 0 */
    v256 = (Lisp_Object)greaterp2(v210, v256);
    nil = C_nil;
    if (exception_pending()) goto v208;
    v256 = v256 ? lisp_true : nil;
    env = stack[-7];
    if (v256 == nil) goto v34;
    v256 = (Lisp_Object)17; /* 1 */
    stack[-2] = v256;
    goto v2;

v34:
    v210 = stack[0];
    v256 = (Lisp_Object)113; /* 7 */
    if (v210 == v256) goto v67;
    v256 = stack[0];
    v256 = (Lisp_Object)((int32)(v256) + 0x10);
    stack[0] = v256;
    goto v47;

v67:
    v210 = stack[-5];
    v256 = elt(env, 1); /* sin */
    if (!(v210 == v256)) goto v2;
    v256 = nil;
    { popv(8); return onevalue(v256); }
/* error exit handlers */
v208:
    popv(8);
    return nil;
}



/* Code for listtest */

static Lisp_Object MS_CDECL CC_listtest(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v16,
                         Lisp_Object v63, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v36, v48, v33;
    argcheck(nargs, 3, "listtest");
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
    v36 = stack[-2];
    if (v36 == nil) goto v6;
    v33 = stack[0];
    v36 = stack[-2];
    v48 = qcar(v36);
    v36 = stack[-1];
    v36 = Lapply2(nil, 3, v33, v48, v36);
    nil = C_nil;
    if (exception_pending()) goto v50;
    env = stack[-3];
    if (v36 == nil) goto v46;
    v36 = stack[-2];
    v36 = qcar(v36);
    if (v36 == nil) goto v20;
    v36 = stack[-2];
    v36 = qcar(v36);
    { popv(4); return onevalue(v36); }

v20:
    v36 = lisp_true;
    { popv(4); return onevalue(v36); }

v46:
    v36 = stack[-2];
    v36 = qcdr(v36);
    stack[-2] = v36;
    goto v12;

v6:
    v36 = nil;
    { popv(4); return onevalue(v36); }
/* error exit handlers */
v50:
    popv(4);
    return nil;
}



/* Code for ord */

static Lisp_Object CC_ord(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v17, v18, v19;
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
    v19 = v0;
/* end of prologue */
    v18 = qvalue(elt(env, 1)); /* ordering */
    v17 = elt(env, 2); /* lex */
    if (v18 == v17) goto v13;
    v17 = v19;
    v17 = qcar(v17);
    { popv(1); return onevalue(v17); }

v13:
    v17 = elt(env, 3); /* plus */
    v18 = v19;
    v17 = cons(v17, v18);
    nil = C_nil;
    if (exception_pending()) goto v20;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 4); /* eval */
        return (*qfn1(fn))(qenv(fn), v17);
    }
/* error exit handlers */
v20:
    popv(1);
    return nil;
}



/* Code for pv_neg */

static Lisp_Object CC_pv_neg(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v10, v53, v14;
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
    goto v45;

v45:
    v10 = stack[0];
    if (v10 == nil) goto v12;
    v10 = stack[0];
    v10 = qcar(v10);
    v10 = qcar(v10);
    v14 = negate(v10);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-2];
    v10 = stack[0];
    v10 = qcar(v10);
    v53 = qcdr(v10);
    v10 = stack[-1];
    v10 = acons(v14, v53, v10);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-2];
    stack[-1] = v10;
    v10 = stack[0];
    v10 = qcdr(v10);
    stack[0] = v10;
    goto v45;

v12:
    v10 = stack[-1];
        popv(3);
        return Lnreverse(nil, v10);
/* error exit handlers */
v32:
    popv(3);
    return nil;
}



/* Code for crprcd */

static Lisp_Object CC_crprcd(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v38, v44;
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
    v38 = stack[0];
    v38 = qcdr(v38);
    v38 = qcar(v38);
    fn = elt(env, 1); /* convprec!* */
    stack[-1] = (*qfn1(fn))(qenv(fn), v38);
    nil = C_nil;
    if (exception_pending()) goto v43;
    env = stack[-2];
    v38 = stack[0];
    v38 = qcdr(v38);
    v38 = qcdr(v38);
    fn = elt(env, 1); /* convprec!* */
    v38 = (*qfn1(fn))(qenv(fn), v38);
    nil = C_nil;
    if (exception_pending()) goto v43;
    v44 = stack[-1];
    popv(3);
    return cons(v44, v38);
/* error exit handlers */
v43:
    popv(3);
    return nil;
}



/* Code for vevcompless!? */

static Lisp_Object CC_vevcomplessW(Lisp_Object env,
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



/* Code for rd!:minus */

static Lisp_Object CC_rdTminus(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v47, v15;
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
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v15 = v0;
/* end of prologue */
    v47 = v15;
    v47 = qcdr(v47);
    if (!consp(v47)) goto v6;
    v47 = v15;
    {
        popv(1);
        fn = elt(env, 2); /* minus!: */
        return (*qfn1(fn))(qenv(fn), v47);
    }

v6:
    stack[0] = elt(env, 1); /* !:rd!: */
    v47 = v15;
    v47 = qcdr(v47);
    v47 = negate(v47);
    nil = C_nil;
    if (exception_pending()) goto v29;
    {
        Lisp_Object v17 = stack[0];
        popv(1);
        return cons(v17, v47);
    }
/* error exit handlers */
v29:
    popv(1);
    return nil;
}



/* Code for revalind */

static Lisp_Object CC_revalind(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v18, v19, v20;
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
    stack[0] = qvalue(elt(env, 1)); /* alglist!* */
    qvalue(elt(env, 1)) = nil; /* alglist!* */
    v18 = nil;
    v18 = ncons(v18);
    nil = C_nil;
    if (exception_pending()) goto v30;
    env = stack[-3];
    qvalue(elt(env, 1)) = v18; /* alglist!* */
    v18 = qvalue(elt(env, 2)); /* subfg!* */
    stack[-2] = v18;
    v18 = nil;
    qvalue(elt(env, 2)) = v18; /* subfg!* */
    v20 = elt(env, 3); /* !0 */
    v19 = (Lisp_Object)1; /* 0 */
    v18 = stack[-1];
    v18 = Lsubst(nil, 3, v20, v19, v18);
    nil = C_nil;
    if (exception_pending()) goto v30;
    env = stack[-3];
    stack[-1] = v18;
    v18 = stack[-1];
    fn = elt(env, 4); /* simp */
    v18 = (*qfn1(fn))(qenv(fn), v18);
    nil = C_nil;
    if (exception_pending()) goto v30;
    env = stack[-3];
    fn = elt(env, 5); /* prepsq */
    v18 = (*qfn1(fn))(qenv(fn), v18);
    nil = C_nil;
    if (exception_pending()) goto v30;
    env = stack[-3];
    v19 = v18;
    v18 = stack[-2];
    qvalue(elt(env, 2)) = v18; /* subfg!* */
    v18 = v19;
    qvalue(elt(env, 1)) = stack[0]; /* alglist!* */
    { popv(4); return onevalue(v18); }
/* error exit handlers */
v30:
    env = stack[-3];
    qvalue(elt(env, 1)) = stack[0]; /* alglist!* */
    popv(4);
    return nil;
}



/* Code for getphystypesf */

static Lisp_Object CC_getphystypesf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v17;
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
    v17 = stack[0];
    if (v17 == nil) goto v3;
    v17 = stack[0];
    fn = elt(env, 1); /* domain!*p */
    v17 = (*qfn1(fn))(qenv(fn), v17);
    nil = C_nil;
    if (exception_pending()) goto v19;
    env = stack[-1];
    if (!(v17 == nil)) goto v3;
    v17 = stack[0];
    v17 = qcar(v17);
    v17 = qcar(v17);
    v17 = qcar(v17);
    fn = elt(env, 2); /* getphystype */
    v17 = (*qfn1(fn))(qenv(fn), v17);
    nil = C_nil;
    if (exception_pending()) goto v19;
    env = stack[-1];
    if (!(v17 == nil)) { popv(2); return onevalue(v17); }
    v17 = stack[0];
    v17 = qcar(v17);
    v17 = qcdr(v17);
    stack[0] = v17;
    goto v11;

v3:
    v17 = nil;
    { popv(2); return onevalue(v17); }
/* error exit handlers */
v19:
    popv(2);
    return nil;
}



/* Code for divdm */

static Lisp_Object CC_divdm(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v67, v68, v56;
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
    v67 = stack[-1];
    if (!(!consp(v67))) goto v35;
    v67 = stack[0];
    if (!(!consp(v67))) goto v35;
    v68 = stack[-1];
    v67 = stack[0];
    v68 = Cremainder(v68, v67);
    nil = C_nil;
    if (exception_pending()) goto v66;
    env = stack[-2];
    v67 = (Lisp_Object)1; /* 0 */
    if (v68 == v67) goto v21;
    v68 = stack[-1];
    v67 = stack[0];
    fn = elt(env, 2); /* mkrn */
    v67 = (*qfn2(fn))(qenv(fn), v68, v67);
    nil = C_nil;
    if (exception_pending()) goto v66;
    env = stack[-2];
    {
        popv(3);
        fn = elt(env, 3); /* !:rn2rd */
        return (*qfn1(fn))(qenv(fn), v67);
    }

v21:
    v68 = stack[-1];
    v67 = stack[0];
    popv(3);
    return quot2(v68, v67);

v35:
    v56 = stack[-1];
    v68 = stack[0];
    v67 = elt(env, 1); /* quotient */
    {
        popv(3);
        fn = elt(env, 4); /* dcombine */
        return (*qfnn(fn))(qenv(fn), 3, v56, v68, v67);
    }
/* error exit handlers */
v66:
    popv(3);
    return nil;
}



/* Code for red_divtest */

static Lisp_Object CC_red_divtest(Lisp_Object env,
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
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v16;
    stack[-1] = v0;
/* end of prologue */

v4:
    v22 = stack[-1];
    if (v22 == nil) goto v5;
    v22 = stack[-1];
    v22 = qcar(v22);
    fn = elt(env, 1); /* bas_dpoly */
    v22 = (*qfn1(fn))(qenv(fn), v22);
    nil = C_nil;
    if (exception_pending()) goto v10;
    env = stack[-2];
    fn = elt(env, 2); /* dp_lmon */
    v23 = (*qfn1(fn))(qenv(fn), v22);
    nil = C_nil;
    if (exception_pending()) goto v10;
    env = stack[-2];
    v22 = stack[0];
    fn = elt(env, 3); /* mo_vdivides!? */
    v22 = (*qfn2(fn))(qenv(fn), v23, v22);
    nil = C_nil;
    if (exception_pending()) goto v10;
    env = stack[-2];
    if (v22 == nil) goto v18;
    v22 = stack[-1];
    v22 = qcar(v22);
    { popv(3); return onevalue(v22); }

v18:
    v22 = stack[-1];
    v22 = qcdr(v22);
    stack[-1] = v22;
    goto v4;

v5:
    v22 = nil;
    { popv(3); return onevalue(v22); }
/* error exit handlers */
v10:
    popv(3);
    return nil;
}



/* Code for !*id2num */

static Lisp_Object CC_Hid2num(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v28, v38;
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v28 = v0;
/* end of prologue */
    v38 = qvalue(elt(env, 1)); /* pair_id_num!* */
    v28 = Lassoc(nil, v28, v38);
    v38 = v28;
    if (v28 == nil) goto v12;
    v28 = v38;
    v28 = qcdr(v28);
    return onevalue(v28);

v12:
    v28 = nil;
    return onevalue(v28);
}



/* Code for b!:ordexn */

static Lisp_Object CC_bTordexn(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v128, v234;
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
    stack[0] = nil;
    stack[-3] = nil;
    goto v45;

v45:
    v128 = stack[-1];
    if (v128 == nil) goto v47;
    v234 = stack[-2];
    v128 = stack[-1];
    v128 = qcar(v128);
    if (equal(v234, v128)) goto v20;
    v128 = stack[-2];
    if (v128 == nil) goto v60;
    v234 = stack[-2];
    v128 = stack[-1];
    v128 = qcar(v128);
    v128 = (Lisp_Object)greaterp2(v234, v128);
    nil = C_nil;
    if (exception_pending()) goto v145;
    v128 = v128 ? lisp_true : nil;
    env = stack[-4];
    if (v128 == nil) goto v60;
    v234 = stack[-2];
    v128 = stack[-3];
    v128 = cons(v234, v128);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-4];
    v234 = Lreverse(nil, v128);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-4];
    v128 = stack[-1];
    v128 = Lappend(nil, v234, v128);
    nil = C_nil;
    if (exception_pending()) goto v145;
    {
        Lisp_Object v146 = stack[0];
        popv(5);
        return cons(v146, v128);
    }

v60:
    v128 = stack[-1];
    v234 = qcar(v128);
    v128 = stack[-3];
    v128 = cons(v234, v128);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-4];
    stack[-3] = v128;
    v128 = stack[-1];
    v128 = qcdr(v128);
    stack[-1] = v128;
    v128 = stack[0];
    v128 = (v128 == nil ? lisp_true : nil);
    stack[0] = v128;
    goto v45;

v20:
    v128 = nil;
    { popv(5); return onevalue(v128); }

v47:
    v234 = stack[-2];
    v128 = stack[-3];
    v128 = cons(v234, v128);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-4];
    v128 = Lreverse(nil, v128);
    nil = C_nil;
    if (exception_pending()) goto v145;
    {
        Lisp_Object v142 = stack[0];
        popv(5);
        return cons(v142, v128);
    }
/* error exit handlers */
v145:
    popv(5);
    return nil;
}



/* Code for general!-reciprocal!-by!-gcd */

static Lisp_Object MS_CDECL CC_generalKreciprocalKbyKgcd(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v16,
                         Lisp_Object v63, Lisp_Object v9, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v118, v135, v119;
    Lisp_Object fn;
    argcheck(nargs, 4, "general-reciprocal-by-gcd");
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
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v9;
    stack[-3] = v63;
    stack[-4] = v16;
    stack[-5] = v0;
/* end of prologue */

v6:
    v135 = stack[-4];
    v118 = (Lisp_Object)1; /* 0 */
    if (v135 == v118) goto v26;
    v135 = stack[-4];
    v118 = (Lisp_Object)17; /* 1 */
    if (v135 == v118) goto v37;
    v135 = stack[-5];
    v118 = stack[-4];
    v118 = quot2(v135, v118);
    nil = C_nil;
    if (exception_pending()) goto v136;
    env = stack[-7];
    stack[-6] = v118;
    stack[-1] = stack[-4];
    stack[0] = stack[-5];
    v135 = stack[-4];
    v118 = stack[-6];
    v118 = times2(v135, v118);
    nil = C_nil;
    if (exception_pending()) goto v136;
    env = stack[-7];
    stack[-4] = difference2(stack[0], v118);
    nil = C_nil;
    if (exception_pending()) goto v136;
    env = stack[-7];
    stack[0] = stack[-2];
    v135 = stack[-2];
    v118 = stack[-6];
    v118 = times2(v135, v118);
    nil = C_nil;
    if (exception_pending()) goto v136;
    env = stack[-7];
    v118 = difference2(stack[-3], v118);
    nil = C_nil;
    if (exception_pending()) goto v136;
    env = stack[-7];
    stack[-5] = stack[-1];
    stack[-3] = stack[0];
    stack[-2] = v118;
    goto v6;

v37:
    v135 = stack[-2];
    v118 = (Lisp_Object)1; /* 0 */
    v118 = (Lisp_Object)lessp2(v135, v118);
    nil = C_nil;
    if (exception_pending()) goto v136;
    v118 = v118 ? lisp_true : nil;
    env = stack[-7];
    if (v118 == nil) { Lisp_Object res = stack[-2]; popv(8); return onevalue(res); }
    v118 = stack[-2];
    v135 = qvalue(elt(env, 3)); /* current!-modulus */
    popv(8);
    return plus2(v118, v135);

v26:
    v119 = elt(env, 1); /* alg */
    v135 = (Lisp_Object)129; /* 8 */
    v118 = elt(env, 2); /* "Invalid modular division" */
    {
        popv(8);
        fn = elt(env, 4); /* rerror */
        return (*qfnn(fn))(qenv(fn), 3, v119, v135, v118);
    }
/* error exit handlers */
v136:
    popv(8);
    return nil;
}



/* Code for mkuwedge */

static Lisp_Object CC_mkuwedge(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v47, v15;
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
    v47 = v0;
/* end of prologue */
    v15 = v47;
    v15 = qcdr(v15);
    if (v15 == nil) goto v27;
    v15 = elt(env, 1); /* wedge */
    v47 = cons(v15, v47);
    nil = C_nil;
    if (exception_pending()) goto v43;
    env = stack[0];
    fn = elt(env, 2); /* fkern */
    v47 = (*qfn1(fn))(qenv(fn), v47);
    nil = C_nil;
    if (exception_pending()) goto v43;
    v47 = qcar(v47);
    { popv(1); return onevalue(v47); }

v27:
    v47 = qcar(v47);
    { popv(1); return onevalue(v47); }
/* error exit handlers */
v43:
    popv(1);
    return nil;
}



/* Code for deletemult!* */

static Lisp_Object CC_deletemultH(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v40, v206, v41;
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
    stack[0] = v0;
/* end of prologue */
    v40 = stack[0];
    if (v40 == nil) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v40 = stack[0];
    v40 = qcar(v40);
    v40 = ncons(v40);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-3];
    stack[-2] = v40;
    v40 = stack[0];
    v40 = qcdr(v40);
    stack[0] = v40;
    v40 = stack[0];
    stack[-1] = v40;
    goto v28;

v28:
    v40 = stack[-1];
    if (v40 == nil) { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
    v40 = stack[-1];
    v40 = qcar(v40);
    v41 = v40;
    v206 = v41;
    v40 = stack[-2];
    v40 = Lmember(nil, v206, v40);
    if (!(v40 == nil)) goto v22;
    stack[0] = stack[-2];
    v40 = v41;
    v40 = ncons(v40);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-3];
    v40 = Lnconc(nil, stack[0], v40);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-3];
    goto v22;

v22:
    v40 = stack[-1];
    v40 = qcdr(v40);
    stack[-1] = v40;
    goto v28;
/* error exit handlers */
v134:
    popv(4);
    return nil;
}



/* Code for compactfmatch2 */

static Lisp_Object CC_compactfmatch2(Lisp_Object env,
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
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0;
/* end of prologue */
    v99 = stack[0];
    if (!consp(v99)) goto v3;
    v99 = stack[0];
    v10 = qcar(v99);
    v99 = elt(env, 1); /* !~ */
    if (v10 == v99) goto v5;
    v99 = stack[0];
    v99 = qcar(v99);
    stack[-1] = CC_compactfmatch2(env, v99);
    nil = C_nil;
    if (exception_pending()) goto v46;
    env = stack[-2];
    v99 = stack[0];
    v99 = qcdr(v99);
    v99 = CC_compactfmatch2(env, v99);
    nil = C_nil;
    if (exception_pending()) goto v46;
    {
        Lisp_Object v31 = stack[-1];
        popv(3);
        return Lappend(nil, v31, v99);
    }

v5:
    v99 = stack[0];
    popv(3);
    return ncons(v99);

v3:
    v99 = nil;
    { popv(3); return onevalue(v99); }
/* error exit handlers */
v46:
    popv(3);
    return nil;
}



/* Code for dividef */

static Lisp_Object CC_dividef(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v34, v39, v40, v206;
    if (stack >= stacklimit)
    {
        push2(v16,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v16);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v34 = v16;
    v39 = v0;
/* end of prologue */
    v34 = Ldivide(nil, v39, v34);
    errexit();
    v206 = v34;
    v34 = v206;
    v39 = qcar(v34);
    v34 = (Lisp_Object)1; /* 0 */
    if (v39 == v34) goto v38;
    v34 = v206;
    v34 = qcar(v34);
    v40 = v34;
    goto v31;

v31:
    v34 = v206;
    v39 = qcdr(v34);
    v34 = (Lisp_Object)1; /* 0 */
    if (v39 == v34) goto v14;
    v34 = v206;
    v34 = qcdr(v34);
    goto v24;

v24:
    return cons(v40, v34);

v14:
    v34 = nil;
    goto v24;

v38:
    v34 = nil;
    v40 = v34;
    goto v31;
}



/* Code for arintequiv!: */

static Lisp_Object CC_arintequivT(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v32, v37, v36;
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v37 = v0;
/* end of prologue */
    v32 = v37;
    v32 = qcdr(v32);
    if (is_number(v32)) goto v3;
    v32 = v37;
    v32 = qcdr(v32);
    v32 = qcar(v32);
    v36 = elt(env, 1); /* !:rn!: */
    if (!(v32 == v36)) goto v14;
    v32 = v37;
    v32 = qcdr(v32);
    v32 = qcdr(v32);
    v36 = qcdr(v32);
    v32 = (Lisp_Object)17; /* 1 */
    if (!(v36 == v32)) goto v14;
    v32 = v37;
    v32 = qcdr(v32);
    v32 = qcdr(v32);
    v32 = qcar(v32);
    return onevalue(v32);

v14:
    v32 = nil;
    return onevalue(v32);

v3:
    v32 = v37;
    v32 = qcdr(v32);
    return onevalue(v32);
}



/* Code for applmacro */

static Lisp_Object MS_CDECL CC_applmacro(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v16,
                         Lisp_Object v63, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v28, v38, v44;
    argcheck(nargs, 3, "applmacro");
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
    push(nil);
/* copy arguments values to proper place */
    v28 = v63;
    v38 = v16;
    v44 = v0;
/* end of prologue */
    stack[0] = v44;
    v28 = cons(v28, v38);
    nil = C_nil;
    if (exception_pending()) goto v15;
    {
        Lisp_Object v43 = stack[0];
        popv(1);
        return Lapply1(nil, v43, v28);
    }
/* error exit handlers */
v15:
    popv(1);
    return nil;
}



/* Code for gionep!: */

static Lisp_Object CC_gionepT(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v19, v20, v21;
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v20 = v0;
/* end of prologue */
    v19 = v20;
    v19 = qcdr(v19);
    v21 = qcar(v19);
    v19 = (Lisp_Object)17; /* 1 */
    if (v21 == v19) goto v27;
    v19 = nil;
    return onevalue(v19);

v27:
    v19 = v20;
    v19 = qcdr(v19);
    v20 = qcdr(v19);
    v19 = (Lisp_Object)1; /* 0 */
    v19 = (v20 == v19 ? lisp_true : nil);
    return onevalue(v19);
}



/* Code for free!-powerp */

static Lisp_Object CC_freeKpowerp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v22;
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
    v22 = stack[0];
    if (!consp(v22)) goto v3;
    v22 = stack[0];
    v22 = qcar(v22);
    if (!consp(v22)) goto v3;
    v22 = stack[0];
    v22 = qcar(v22);
    v22 = qcar(v22);
    v22 = qcdr(v22);
    v22 = integerp(v22);
    v22 = (v22 == nil ? lisp_true : nil);
    if (!(v22 == nil)) { popv(2); return onevalue(v22); }
    v22 = stack[0];
    v22 = qcar(v22);
    v22 = qcdr(v22);
    v22 = CC_freeKpowerp(env, v22);
    nil = C_nil;
    if (exception_pending()) goto v30;
    env = stack[-1];
    if (!(v22 == nil)) { popv(2); return onevalue(v22); }
    v22 = stack[0];
    v22 = qcdr(v22);
    stack[0] = v22;
    goto v11;

v3:
    v22 = nil;
    { popv(2); return onevalue(v22); }
/* error exit handlers */
v30:
    popv(2);
    return nil;
}



/* Code for vevdif */

static Lisp_Object CC_vevdif(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v97, v118, v135;
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
    stack[-3] = v16;
    stack[-4] = v0;
/* end of prologue */
    stack[-5] = nil;
    v118 = nil;
    v97 = stack[-4];
    stack[-1] = v97;
    v97 = stack[-3];
    stack[0] = v97;
    goto v25;

v25:
    v97 = stack[-1];
    if (v97 == nil) goto v2;
    v97 = stack[0];
    if (v97 == nil) goto v2;
    v97 = v118;
    if (!(v97 == nil)) goto v2;
    v97 = stack[-1];
    v118 = qcar(v97);
    v97 = stack[0];
    v97 = qcar(v97);
    v97 = (Lisp_Object)(int32)((int32)v118 - (int32)v97 + TAG_FIXNUM);
    stack[-2] = v97;
    v118 = stack[-2];
    v97 = stack[-5];
    v97 = cons(v118, v97);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-6];
    stack[-5] = v97;
    v118 = stack[-2];
    v97 = (Lisp_Object)1; /* 0 */
    v97 = ((intxx)v118 < (intxx)v97) ? lisp_true : nil;
    v118 = v97;
    v97 = stack[-1];
    v97 = qcdr(v97);
    stack[-1] = v97;
    v97 = stack[0];
    v97 = qcdr(v97);
    stack[0] = v97;
    goto v25;

v2:
    v97 = v118;
    if (!(v97 == nil)) goto v100;
    v97 = stack[0];
    if (v97 == nil) goto v237;
    v97 = stack[0];
    if (v97 == nil) goto v237;
    v97 = stack[0];
    v118 = qcar(v97);
    v97 = (Lisp_Object)1; /* 0 */
    if (!(v118 == v97)) goto v100;
    v97 = stack[0];
    v97 = qcdr(v97);
    fn = elt(env, 4); /* vevzero!?1 */
    v97 = (*qfn1(fn))(qenv(fn), v97);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-6];
    if (!(v97 == nil)) goto v237;

v100:
    v97 = stack[-4];
    v97 = Lprint(nil, v97);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-6];
    v97 = stack[-3];
    v97 = Lprint(nil, v97);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-6];
    v97 = elt(env, 1); /* backtrace */
    fn = elt(env, 5); /* getd */
    v97 = (*qfn1(fn))(qenv(fn), v97);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-6];
    if (v97 == nil) goto v112;
    fn = elt(env, 1); /* backtrace */
    v97 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-6];
    goto v112;

v112:
    v135 = elt(env, 2); /* dipoly */
    v118 = (Lisp_Object)81; /* 5 */
    v97 = elt(env, 3); /* "Vevdif, difference would be < 0" */
    {
        popv(7);
        fn = elt(env, 6); /* rerror */
        return (*qfnn(fn))(qenv(fn), 3, v135, v118, v97);
    }

v237:
    v97 = stack[-5];
    v118 = Lnreverse(nil, v97);
    v97 = stack[-1];
        popv(7);
        return Lnconc(nil, v118, v97);
/* error exit handlers */
v139:
    popv(7);
    return nil;
}



/* Code for split!-road */

static Lisp_Object CC_splitKroad(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v33, v51, v42;
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
    v33 = stack[-1];
    stack[-3] = qcar(v33);
    v33 = stack[-2];
    v42 = qcar(v33);
    v33 = stack[-2];
    v51 = qcdr(v33);
    v33 = stack[-1];
    v33 = qcdr(v33);
    v33 = qcar(v33);
    fn = elt(env, 1); /* sroad */
    stack[0] = (*qfnn(fn))(qenv(fn), 3, v42, v51, v33);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-4];
    v33 = stack[-2];
    v42 = qcar(v33);
    v33 = stack[-2];
    v51 = qcdr(v33);
    v33 = stack[-1];
    v33 = qcdr(v33);
    v33 = qcdr(v33);
    v33 = qcar(v33);
    fn = elt(env, 1); /* sroad */
    v33 = (*qfnn(fn))(qenv(fn), 3, v42, v51, v33);
    nil = C_nil;
    if (exception_pending()) goto v35;
    {
        Lisp_Object v34 = stack[-3];
        Lisp_Object v39 = stack[0];
        popv(5);
        return list3(v34, v39, v33);
    }
/* error exit handlers */
v35:
    popv(5);
    return nil;
}



/* Code for mv!-pow!-!- */

static Lisp_Object CC_mvKpowKK(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v14, v46;
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
    stack[-2] = nil;
    goto v12;

v12:
    v14 = stack[-1];
    if (v14 == nil) goto v6;
    v14 = stack[-1];
    v46 = qcar(v14);
    v14 = stack[0];
    v14 = qcar(v14);
    v46 = difference2(v46, v14);
    nil = C_nil;
    if (exception_pending()) goto v36;
    env = stack[-3];
    v14 = stack[-2];
    v14 = cons(v46, v14);
    nil = C_nil;
    if (exception_pending()) goto v36;
    env = stack[-3];
    stack[-2] = v14;
    v14 = stack[-1];
    v14 = qcdr(v14);
    stack[-1] = v14;
    v14 = stack[0];
    v14 = qcdr(v14);
    stack[0] = v14;
    goto v12;

v6:
    v14 = stack[-2];
    {
        popv(4);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v14);
    }
/* error exit handlers */
v36:
    popv(4);
    return nil;
}



/* Code for red_better */

static Lisp_Object CC_red_better(Lisp_Object env,
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
    fn = elt(env, 1); /* bas_dplen */
    stack[-1] = (*qfn1(fn))(qenv(fn), v2);
    nil = C_nil;
    if (exception_pending()) goto v24;
    env = stack[-2];
    v2 = stack[0];
    fn = elt(env, 1); /* bas_dplen */
    v2 = (*qfn1(fn))(qenv(fn), v2);
    nil = C_nil;
    if (exception_pending()) goto v24;
    {
        Lisp_Object v26 = stack[-1];
        popv(3);
        return Llessp(nil, v26, v2);
    }
/* error exit handlers */
v24:
    popv(3);
    return nil;
}



/* Code for conv!:bf2i */

static Lisp_Object CC_convTbf2i(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v25, v13;
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v25 = v0;
/* end of prologue */
    v13 = v25;
    v13 = qcdr(v13);
    v13 = qcar(v13);
    v25 = qcdr(v25);
    v25 = qcdr(v25);
        return Lash1(nil, v13, v25);
}



/* Code for i!&makelines */

static Lisp_Object CC_iGmakelines(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v70, v71, v101;
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

v4:
    v70 = stack[-1];
    if (v70 == nil) goto v1;
    v71 = stack[-1];
    v70 = qvalue(elt(env, 1)); /* !$eol!$ */
    if (!consp(v71)) goto v35;
    v71 = qcar(v71);
    if (!(v71 == v70)) goto v35;
    v70 = stack[-1];
    v70 = qcdr(v70);
    stack[-1] = v70;
    v101 = nil;
    v70 = stack[0];
    v70 = qcar(v70);
    v71 = Lnreverse(nil, v70);
    env = stack[-3];
    v70 = stack[0];
    v70 = qcdr(v70);
    v70 = list2star(v101, v71, v70);
    nil = C_nil;
    if (exception_pending()) goto v58;
    env = stack[-3];
    stack[0] = v70;
    goto v4;

v35:
    stack[-2] = stack[0];
    v70 = stack[-1];
    v71 = qcar(v70);
    v70 = stack[0];
    v70 = qcar(v70);
    v70 = cons(v71, v70);
    nil = C_nil;
    if (exception_pending()) goto v58;
    env = stack[-3];
    fn = elt(env, 2); /* setcar */
    v70 = (*qfn2(fn))(qenv(fn), stack[-2], v70);
    nil = C_nil;
    if (exception_pending()) goto v58;
    env = stack[-3];
    v70 = stack[-1];
    v70 = qcdr(v70);
    stack[-1] = v70;
    goto v4;

v1:
    v70 = stack[0];
    v70 = qcar(v70);
    v71 = Lnreverse(nil, v70);
    v70 = stack[0];
    v70 = qcdr(v70);
    popv(4);
    return cons(v71, v70);
/* error exit handlers */
v58:
    popv(4);
    return nil;
}



setup_type const u12_setup[] =
{
    {"psum",                    too_few_2,      CC_psum,       wrong_no_2},
    {"adddummy1a",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_adddummy1a},
    {"gizerop:",                CC_gizeropT,    too_many_1,    wrong_no_1},
    {"dim<deg",                 CC_dimRdeg,     too_many_1,    wrong_no_1},
    {"lessp:",                  too_few_2,      CC_lesspT,     wrong_no_2},
    {"mv-pow-+",                too_few_2,      CC_mvKpowKL,   wrong_no_2},
    {"rnquotient:",             too_few_2,      CC_rnquotientT,wrong_no_2},
    {"general-modular-reciprocal",CC_generalKmodularKreciprocal,too_many_1,wrong_no_1},
    {"rread",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_rread},
    {"c:ordexn",                too_few_2,      CC_cTordexn,   wrong_no_2},
    {"vevmaptozero1",           too_few_2,      CC_vevmaptozero1,wrong_no_2},
    {"addpf",                   too_few_2,      CC_addpf,      wrong_no_2},
    {"evaluate0",               too_few_2,      CC_evaluate0,  wrong_no_2},
    {"pneg",                    CC_pneg,        too_many_1,    wrong_no_1},
    {"ordn",                    CC_ordn,        too_many_1,    wrong_no_1},
    {"opnum*",                  CC_opnumH,      too_many_1,    wrong_no_1},
    {"*i2ar",                   CC_Hi2ar,       too_many_1,    wrong_no_1},
    {"c:extmult",               too_few_2,      CC_cTextmult,  wrong_no_2},
    {"vecp",                    CC_vecp,        too_many_1,    wrong_no_1},
    {"copy-vector",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_copyKvector},
    {"reduce-mod-p",            CC_reduceKmodKp,too_many_1,    wrong_no_1},
    {"gintequiv:",              CC_gintequivT,  too_many_1,    wrong_no_1},
    {"trwrite",                 CC_trwrite,     too_many_1,    wrong_no_1},
    {"red-ratios2",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_redKratios2},
    {"dv_skelhead",             CC_dv_skelhead, too_many_1,    wrong_no_1},
    {"general-modular-minus",   CC_generalKmodularKminus,too_many_1,wrong_no_1},
    {"i&prn",                   CC_iGprn,       too_many_1,    wrong_no_1},
    {"wedget2",                 too_few_2,      CC_wedget2,    wrong_no_2},
    {"minus:",                  CC_minusT,      too_many_1,    wrong_no_1},
    {"greaterp:",               too_few_2,      CC_greaterpT,  wrong_no_2},
    {"contrsp",                 too_few_2,      CC_contrsp,    wrong_no_2},
    {"mo_diff",                 too_few_2,      CC_mo_diff,    wrong_no_2},
    {"c:extadd",                too_few_2,      CC_cTextadd,   wrong_no_2},
    {"flatindxl",               CC_flatindxl,   too_many_1,    wrong_no_1},
    {"leftzeros",               CC_leftzeros,   too_many_1,    wrong_no_1},
    {"th_match0",               too_few_2,      CC_th_match0,  wrong_no_2},
    {"tokquote",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_tokquote},
    {"plus:",                   too_few_2,      CC_plusT,      wrong_no_2},
    {"treesizep1",              too_few_2,      CC_treesizep1, wrong_no_2},
    {"scalopp",                 CC_scalopp,     too_many_1,    wrong_no_1},
    {"b:extmult",               too_few_2,      CC_bTextmult,  wrong_no_2},
    {"conv:mt",                 too_few_2,      CC_convTmt,    wrong_no_2},
    {"horner-rule",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_hornerKrule},
    {"xord_lex",                too_few_2,      CC_xord_lex,   wrong_no_2},
    {"errorset2",               CC_errorset2,   too_many_1,    wrong_no_1},
    {"exptmod:",                too_few_2,      CC_exptmodT,   wrong_no_2},
    {"symbid",                  too_few_2,      CC_symbid,     wrong_no_2},
    {"powers2",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_powers2},
    {"mksgnsq",                 CC_mksgnsq,     too_many_1,    wrong_no_1},
    {"ncmpchk",                 too_few_2,      CC_ncmpchk,    wrong_no_2},
    {"mv-domainlist--",         too_few_2,      CC_mvKdomainlistKK,wrong_no_2},
    {"make-term",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_makeKterm},
    {"listtest",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_listtest},
    {"ord",                     CC_ord,         too_many_1,    wrong_no_1},
    {"pv_neg",                  CC_pv_neg,      too_many_1,    wrong_no_1},
    {"crprcd",                  CC_crprcd,      too_many_1,    wrong_no_1},
    {"vevcompless?",            too_few_2,      CC_vevcomplessW,wrong_no_2},
    {"rd:minus",                CC_rdTminus,    too_many_1,    wrong_no_1},
    {"revalind",                CC_revalind,    too_many_1,    wrong_no_1},
    {"getphystypesf",           CC_getphystypesf,too_many_1,   wrong_no_1},
    {"divdm",                   too_few_2,      CC_divdm,      wrong_no_2},
    {"red_divtest",             too_few_2,      CC_red_divtest,wrong_no_2},
    {"*id2num",                 CC_Hid2num,     too_many_1,    wrong_no_1},
    {"b:ordexn",                too_few_2,      CC_bTordexn,   wrong_no_2},
    {"general-reciprocal-by-gcd",wrong_no_na,   wrong_no_nb,   (n_args *)CC_generalKreciprocalKbyKgcd},
    {"mkuwedge",                CC_mkuwedge,    too_many_1,    wrong_no_1},
    {"deletemult*",             CC_deletemultH, too_many_1,    wrong_no_1},
    {"compactfmatch2",          CC_compactfmatch2,too_many_1,  wrong_no_1},
    {"dividef",                 too_few_2,      CC_dividef,    wrong_no_2},
    {"arintequiv:",             CC_arintequivT, too_many_1,    wrong_no_1},
    {"applmacro",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_applmacro},
    {"gionep:",                 CC_gionepT,     too_many_1,    wrong_no_1},
    {"free-powerp",             CC_freeKpowerp, too_many_1,    wrong_no_1},
    {"vevdif",                  too_few_2,      CC_vevdif,     wrong_no_2},
    {"split-road",              too_few_2,      CC_splitKroad, wrong_no_2},
    {"mv-pow--",                too_few_2,      CC_mvKpowKK,   wrong_no_2},
    {"red_better",              too_few_2,      CC_red_better, wrong_no_2},
    {"conv:bf2i",               CC_convTbf2i,   too_many_1,    wrong_no_1},
    {"i&makelines",             too_few_2,      CC_iGmakelines,wrong_no_2},
    {NULL, (one_args *)"u12", (two_args *)"1113 7130717 1333440", 0}
};

/* end of generated code */
