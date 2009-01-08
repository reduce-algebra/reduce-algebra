
/* $srcdir/../csl-c\u06.c Machine generated C code */

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


/* Code for nssimp */

static Lisp_Object CC_nssimp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v429, v430, v249, v168, v167;
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
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-4] = v16;
    stack[-5] = v0;
/* end of prologue */
    stack[-6] = nil;
    stack[-3] = nil;
    stack[-2] = nil;
    v430 = stack[-5];
    v429 = stack[-4];
    fn = elt(env, 11); /* dsimp */
    v429 = (*qfn2(fn))(qenv(fn), v430, v429);
    nil = C_nil;
    if (exception_pending()) goto v465;
    env = stack[-7];
    stack[-5] = v429;
    goto v8;

v8:
    v429 = stack[-5];
    if (v429 == nil) { Lisp_Object res = stack[-2]; popv(8); return onevalue(res); }
    v429 = stack[-5];
    v429 = qcar(v429);
    stack[0] = v429;
    goto v1;

v1:
    v429 = stack[0];
    if (v429 == nil) goto v2;
    v429 = stack[0];
    v429 = qcar(v429);
    stack[-1] = v429;
    if (is_number(v429)) goto v106;
    v430 = stack[-1];
    v429 = elt(env, 1); /* !*div */
    if (!consp(v430)) goto v69;
    v430 = qcar(v430);
    if (!(v430 == v429)) goto v69;

v112:
    v430 = stack[-3];
    v429 = stack[-1];
    fn = elt(env, 12); /* aconc!* */
    v429 = (*qfn2(fn))(qenv(fn), v430, v429);
    nil = C_nil;
    if (exception_pending()) goto v465;
    env = stack[-7];
    stack[-3] = v429;
    goto v30;

v30:
    v429 = stack[0];
    v429 = qcdr(v429);
    stack[0] = v429;
    goto v1;

v69:
    v429 = stack[-1];
    fn = elt(env, 13); /* getrtype */
    v430 = (*qfn1(fn))(qenv(fn), v429);
    nil = C_nil;
    if (exception_pending()) goto v465;
    env = stack[-7];
    v249 = v430;
    v429 = elt(env, 2); /* yetunknowntype */
    if (v430 == v429) goto v57;
    v429 = v249;
    v430 = v429;
    goto v206;

v206:
    v429 = stack[-4];
    if (v430 == v429) goto v112;
    else goto v106;

v106:
    v430 = stack[-6];
    v429 = stack[-1];
    fn = elt(env, 12); /* aconc!* */
    v429 = (*qfn2(fn))(qenv(fn), v430, v429);
    nil = C_nil;
    if (exception_pending()) goto v465;
    env = stack[-7];
    stack[-6] = v429;
    goto v30;

v57:
    v430 = stack[-1];
    v429 = nil;
    fn = elt(env, 14); /* eval!-yetunknowntypeexpr */
    v429 = (*qfn2(fn))(qenv(fn), v430, v429);
    nil = C_nil;
    if (exception_pending()) goto v465;
    env = stack[-7];
    stack[-1] = v429;
    fn = elt(env, 13); /* getrtype */
    v429 = (*qfn1(fn))(qenv(fn), v429);
    nil = C_nil;
    if (exception_pending()) goto v465;
    env = stack[-7];
    v430 = v429;
    goto v206;

v2:
    v429 = stack[-3];
    if (!(v429 == nil)) goto v135;
    v429 = stack[-4];
    stack[-3] = v429;
    v429 = stack[-6];
    v429 = qcar(v429);
    if (symbolp(v429)) goto v214;
    v430 = stack[-3];
    v429 = elt(env, 6); /* tag */
    v430 = get(v430, v429);
    env = stack[-7];
    v429 = elt(env, 7); /* i2d */
    v429 = get(v430, v429);
    env = stack[-7];
    stack[0] = v429;
    if (v429 == nil) goto v508;
    v430 = stack[0];
    v429 = (Lisp_Object)17; /* 1 */
    v429 = Lapply1(nil, v430, v429);
    nil = C_nil;
    if (exception_pending()) goto v465;
    env = stack[-7];
    v429 = ncons(v429);
    nil = C_nil;
    if (exception_pending()) goto v465;
    env = stack[-7];
    stack[-3] = v429;
    goto v135;

v135:
    v429 = stack[-6];
    if (v429 == nil) goto v231;
    v429 = stack[-6];
    fn = elt(env, 15); /* simptimes */
    v429 = (*qfn1(fn))(qenv(fn), v429);
    nil = C_nil;
    if (exception_pending()) goto v465;
    env = stack[-7];
    v430 = v429;
    goto v98;

v98:
    v429 = stack[-3];
    v430 = cons(v430, v429);
    nil = C_nil;
    if (exception_pending()) goto v465;
    env = stack[-7];
    v429 = stack[-2];
    fn = elt(env, 16); /* addns */
    v429 = (*qfn2(fn))(qenv(fn), v430, v429);
    nil = C_nil;
    if (exception_pending()) goto v465;
    env = stack[-7];
    stack[-2] = v429;
    v429 = stack[-5];
    v429 = qcdr(v429);
    stack[-5] = v429;
    v429 = nil;
    stack[-3] = v429;
    stack[-6] = v429;
    goto v8;

v231:
    v430 = (Lisp_Object)17; /* 1 */
    v429 = (Lisp_Object)17; /* 1 */
    v429 = cons(v430, v429);
    nil = C_nil;
    if (exception_pending()) goto v465;
    env = stack[-7];
    v430 = v429;
    goto v98;

v508:
    v249 = elt(env, 8); /* "Missing" */
    v430 = stack[-3];
    v429 = elt(env, 9); /* "in" */
    v167 = list3(v249, v430, v429);
    nil = C_nil;
    if (exception_pending()) goto v465;
    env = stack[-7];
    v429 = stack[-6];
    v168 = qcar(v429);
    v249 = nil;
    v430 = nil;
    v429 = lisp_true;
    fn = elt(env, 17); /* msgpri */
    v429 = (*qfnn(fn))(qenv(fn), 5, v167, v168, v249, v430, v429);
    nil = C_nil;
    if (exception_pending()) goto v465;
    env = stack[-7];
    goto v455;

v455:
    v429 = stack[-6];
    v249 = qcar(v429);
    v430 = elt(env, 10); /* rtype */
    v429 = stack[-3];
    v429 = Lputprop(nil, 3, v249, v430, v429);
    nil = C_nil;
    if (exception_pending()) goto v465;
    env = stack[-7];
    v429 = stack[-6];
    v429 = qcar(v429);
    v429 = ncons(v429);
    nil = C_nil;
    if (exception_pending()) goto v465;
    env = stack[-7];
    stack[-3] = v429;
    v429 = stack[-6];
    v429 = qcdr(v429);
    stack[-6] = v429;
    goto v135;

v214:
    v429 = stack[-6];
    v249 = qcar(v429);
    v430 = stack[-3];
    v429 = elt(env, 3); /* fn */
    v429 = get(v430, v429);
    env = stack[-7];
    v429 = Lflagp(nil, v249, v429);
    env = stack[-7];
    if (v429 == nil) goto v187;
    stack[-1] = elt(env, 4); /* alg */
    stack[0] = (Lisp_Object)481; /* 30 */
    v249 = stack[-3];
    v430 = stack[-6];
    v429 = elt(env, 5); /* "not set" */
    v429 = list3(v249, v430, v429);
    nil = C_nil;
    if (exception_pending()) goto v465;
    env = stack[-7];
    fn = elt(env, 18); /* rerror */
    v429 = (*qfnn(fn))(qenv(fn), 3, stack[-1], stack[0], v429);
    nil = C_nil;
    if (exception_pending()) goto v465;
    env = stack[-7];
    goto v455;

v187:
    v429 = stack[-6];
    v430 = qcar(v429);
    v429 = stack[-3];
    fn = elt(env, 19); /* redmsg */
    v429 = (*qfn2(fn))(qenv(fn), v430, v429);
    nil = C_nil;
    if (exception_pending()) goto v465;
    env = stack[-7];
    goto v455;
/* error exit handlers */
v465:
    popv(8);
    return nil;
}



/* Code for wtchk */

static Lisp_Object CC_wtchk(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v54, v87, v66;
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
    v54 = stack[-1];
    if (v54 == nil) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v54 = stack[-2];
    stack[-3] = ncons(v54);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-4];
    stack[0] = elt(env, 1); /* k!* */
    v87 = stack[-1];
    v54 = stack[-2];
    v54 = qcar(v54);
    v54 = qcdr(v54);
    v54 = times2(v87, v54);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-4];
    fn = elt(env, 3); /* to */
    v87 = (*qfn2(fn))(qenv(fn), stack[0], v54);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-4];
    v54 = (Lisp_Object)17; /* 1 */
    v54 = cons(v87, v54);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-4];
    v54 = ncons(v54);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-4];
    fn = elt(env, 4); /* quotf */
    v54 = (*qfn2(fn))(qenv(fn), stack[-3], v54);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-4];
    v87 = v54;
    v54 = v87;
    if (v54 == nil) goto v34;
    v54 = v87;
    v54 = qcar(v54);
    { popv(5); return onevalue(v54); }

v34:
    v66 = elt(env, 2); /* "weight confusion" */
    v87 = stack[-2];
    v54 = stack[-1];
    v54 = list3(v66, v87, v54);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-4];
    {
        popv(5);
        fn = elt(env, 5); /* errach */
        return (*qfn1(fn))(qenv(fn), v54);
    }
/* error exit handlers */
v72:
    popv(5);
    return nil;
}



/* Code for mchkopt1 */

static Lisp_Object MS_CDECL CC_mchkopt1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v16,
                         Lisp_Object v63, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v181, v434, v257;
    Lisp_Object fn;
    argcheck(nargs, 3, "mchkopt1");
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
    push(nil);
/* copy arguments values to proper place */
    stack[-4] = v63;
    v181 = v16;
    v434 = v0;
/* end of prologue */
    v181 = qcdr(v181);
    v257 = v181;
    if (v181 == nil) goto v8;
    v181 = v257;
    v181 = qcar(v181);
    stack[-3] = v181;
    v181 = v257;
    v181 = qcdr(v181);
    v257 = v181;
    if (v181 == nil) goto v38;
    v181 = v257;
    v181 = qcar(v181);
    stack[-5] = v181;
    v181 = v257;
    v181 = qcdr(v181);
    if (v181 == nil) goto v31;
    v181 = nil;
    { popv(7); return onevalue(v181); }

v31:
    v257 = stack[-3];
    v181 = elt(env, 1); /* optional */
    v181 = Lflagp(nil, v257, v181);
    env = stack[-6];
    if (v181 == nil) goto v117;
    v181 = stack[-5];
    fn = elt(env, 2); /* mchk */
    v181 = (*qfn2(fn))(qenv(fn), v434, v181);
    nil = C_nil;
    if (exception_pending()) goto v460;
    env = stack[-6];
    stack[-5] = v181;
    v181 = stack[-5];
    if (v181 == nil) goto v69;
    v181 = stack[-5];
    v181 = qcar(v181);
    v257 = stack[-3];
    v434 = stack[-4];
    v434 = qcar(v434);
    v181 = acons(v257, v434, v181);
    nil = C_nil;
    if (exception_pending()) goto v460;
    env = stack[-6];
    v181 = ncons(v181);
    nil = C_nil;
    if (exception_pending()) goto v460;
    env = stack[-6];
    stack[-1] = v181;
    stack[-2] = v181;
    goto v35;

v35:
    v181 = stack[-5];
    v181 = qcdr(v181);
    stack[-5] = v181;
    v181 = stack[-5];
    if (v181 == nil) { Lisp_Object res = stack[-2]; popv(7); return onevalue(res); }
    stack[0] = stack[-1];
    v181 = stack[-5];
    v181 = qcar(v181);
    v257 = stack[-3];
    v434 = stack[-4];
    v434 = qcar(v434);
    v181 = acons(v257, v434, v181);
    nil = C_nil;
    if (exception_pending()) goto v460;
    env = stack[-6];
    v181 = ncons(v181);
    nil = C_nil;
    if (exception_pending()) goto v460;
    env = stack[-6];
    v181 = Lrplacd(nil, stack[0], v181);
    nil = C_nil;
    if (exception_pending()) goto v460;
    env = stack[-6];
    v181 = stack[-1];
    v181 = qcdr(v181);
    stack[-1] = v181;
    goto v35;

v69:
    v181 = nil;
    { popv(7); return onevalue(v181); }

v117:
    v257 = stack[-5];
    v181 = elt(env, 1); /* optional */
    v181 = Lflagp(nil, v257, v181);
    env = stack[-6];
    if (v181 == nil) goto v352;
    v181 = stack[-3];
    fn = elt(env, 2); /* mchk */
    v181 = (*qfn2(fn))(qenv(fn), v434, v181);
    nil = C_nil;
    if (exception_pending()) goto v460;
    env = stack[-6];
    stack[-3] = v181;
    v181 = stack[-3];
    if (v181 == nil) goto v133;
    v181 = stack[-3];
    v181 = qcar(v181);
    v257 = stack[-5];
    v434 = stack[-4];
    v434 = qcdr(v434);
    v434 = qcar(v434);
    v181 = acons(v257, v434, v181);
    nil = C_nil;
    if (exception_pending()) goto v460;
    env = stack[-6];
    v181 = ncons(v181);
    nil = C_nil;
    if (exception_pending()) goto v460;
    env = stack[-6];
    stack[-1] = v181;
    stack[-2] = v181;
    goto v235;

v235:
    v181 = stack[-3];
    v181 = qcdr(v181);
    stack[-3] = v181;
    v181 = stack[-3];
    if (v181 == nil) { Lisp_Object res = stack[-2]; popv(7); return onevalue(res); }
    stack[0] = stack[-1];
    v181 = stack[-3];
    v181 = qcar(v181);
    v257 = stack[-5];
    v434 = stack[-4];
    v434 = qcdr(v434);
    v434 = qcar(v434);
    v181 = acons(v257, v434, v181);
    nil = C_nil;
    if (exception_pending()) goto v460;
    env = stack[-6];
    v181 = ncons(v181);
    nil = C_nil;
    if (exception_pending()) goto v460;
    env = stack[-6];
    v181 = Lrplacd(nil, stack[0], v181);
    nil = C_nil;
    if (exception_pending()) goto v460;
    env = stack[-6];
    v181 = stack[-1];
    v181 = qcdr(v181);
    stack[-1] = v181;
    goto v235;

v133:
    v181 = nil;
    { popv(7); return onevalue(v181); }

v352:
    v181 = nil;
    { popv(7); return onevalue(v181); }

v38:
    v181 = nil;
    { popv(7); return onevalue(v181); }

v8:
    v181 = nil;
    { popv(7); return onevalue(v181); }
/* error exit handlers */
v460:
    popv(7);
    return nil;
}



/* Code for gcdf2 */

static Lisp_Object CC_gcdf2(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v464, v161, v162;
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
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-4] = v16;
    stack[-5] = v0;
/* end of prologue */
    stack[-6] = qvalue(elt(env, 1)); /* asymplis!* */
    qvalue(elt(env, 1)) = nil; /* asymplis!* */
    v464 = stack[-5];
    fn = elt(env, 3); /* num!-exponents */
    v464 = (*qfn1(fn))(qenv(fn), v464);
    nil = C_nil;
    if (exception_pending()) goto v262;
    env = stack[-7];
    if (v464 == nil) goto v7;
    v464 = stack[-4];
    fn = elt(env, 3); /* num!-exponents */
    v464 = (*qfn1(fn))(qenv(fn), v464);
    nil = C_nil;
    if (exception_pending()) goto v262;
    env = stack[-7];
    if (v464 == nil) goto v7;
    v464 = qvalue(elt(env, 2)); /* !*gcd */
    if (v464 == nil) goto v52;
    v161 = stack[-5];
    v464 = stack[-4];
    fn = elt(env, 4); /* kernord */
    v464 = (*qfn2(fn))(qenv(fn), v161, v464);
    nil = C_nil;
    if (exception_pending()) goto v262;
    env = stack[-7];
    stack[-3] = v464;
    v161 = Llength(nil, v464);
    nil = C_nil;
    if (exception_pending()) goto v262;
    env = stack[-7];
    v464 = (Lisp_Object)17; /* 1 */
    v464 = (Lisp_Object)greaterp2(v161, v464);
    nil = C_nil;
    if (exception_pending()) goto v262;
    v464 = v464 ? lisp_true : nil;
    env = stack[-7];
    if (v464 == nil) goto v52;
    v464 = stack[-3];
    fn = elt(env, 5); /* setkorder */
    v464 = (*qfn1(fn))(qenv(fn), v464);
    nil = C_nil;
    if (exception_pending()) goto v262;
    env = stack[-7];
    v464 = ncons(v464);
    nil = C_nil;
    if (exception_pending()) goto v262;
    env = stack[-7];
    stack[-3] = v464;
    v464 = stack[-5];
    fn = elt(env, 6); /* reorder */
    v464 = (*qfn1(fn))(qenv(fn), v464);
    nil = C_nil;
    if (exception_pending()) goto v262;
    env = stack[-7];
    stack[-5] = v464;
    v464 = stack[-4];
    fn = elt(env, 6); /* reorder */
    v464 = (*qfn1(fn))(qenv(fn), v464);
    nil = C_nil;
    if (exception_pending()) goto v262;
    env = stack[-7];
    stack[-4] = v464;
    goto v41;

v41:
    v464 = stack[-5];
    v464 = qcar(v464);
    v464 = qcar(v464);
    v161 = qcar(v464);
    v464 = stack[-4];
    v464 = qcar(v464);
    v464 = qcar(v464);
    v464 = qcar(v464);
    if (v161 == v464) goto v40;
    v464 = stack[-5];
    v464 = qcar(v464);
    v464 = qcar(v464);
    v464 = qcar(v464);
    fn = elt(env, 7); /* noncomp */
    v464 = (*qfn1(fn))(qenv(fn), v464);
    nil = C_nil;
    if (exception_pending()) goto v262;
    env = stack[-7];
    if (v464 == nil) goto v306;
    v464 = stack[-4];
    v464 = qcar(v464);
    v464 = qcar(v464);
    v464 = qcar(v464);
    fn = elt(env, 7); /* noncomp */
    v464 = (*qfn1(fn))(qenv(fn), v464);
    nil = C_nil;
    if (exception_pending()) goto v262;
    env = stack[-7];
    if (v464 == nil) goto v306;
    v162 = stack[-5];
    v161 = stack[-4];
    v464 = stack[-4];
    v464 = qcar(v464);
    v464 = qcar(v464);
    v464 = qcar(v464);
    fn = elt(env, 8); /* gcdfnc */
    v464 = (*qfnn(fn))(qenv(fn), 3, v162, v161, v464);
    nil = C_nil;
    if (exception_pending()) goto v262;
    env = stack[-7];
    stack[-2] = v464;
    goto v39;

v39:
    v464 = stack[-3];
    if (v464 == nil) goto v673;
    v464 = stack[-3];
    v464 = qcar(v464);
    fn = elt(env, 5); /* setkorder */
    v464 = (*qfn1(fn))(qenv(fn), v464);
    nil = C_nil;
    if (exception_pending()) goto v262;
    env = stack[-7];
    v464 = stack[-2];
    fn = elt(env, 6); /* reorder */
    v464 = (*qfn1(fn))(qenv(fn), v464);
    nil = C_nil;
    if (exception_pending()) goto v262;
    env = stack[-7];
    stack[-2] = v464;
    goto v673;

v673:
    v464 = stack[-2];
    goto v45;

v45:
    qvalue(elt(env, 1)) = stack[-6]; /* asymplis!* */
    { popv(8); return onevalue(v464); }

v306:
    v464 = stack[-5];
    v464 = qcar(v464);
    v464 = qcar(v464);
    v161 = qcar(v464);
    v464 = stack[-4];
    v464 = qcar(v464);
    v464 = qcar(v464);
    v464 = qcar(v464);
    fn = elt(env, 9); /* ordop */
    v464 = (*qfn2(fn))(qenv(fn), v161, v464);
    nil = C_nil;
    if (exception_pending()) goto v262;
    env = stack[-7];
    if (v464 == nil) goto v465;
    v464 = stack[-5];
    fn = elt(env, 10); /* comfac */
    v464 = (*qfn1(fn))(qenv(fn), v464);
    nil = C_nil;
    if (exception_pending()) goto v262;
    env = stack[-7];
    v161 = qcdr(v464);
    v464 = stack[-4];
    fn = elt(env, 11); /* gcdf1 */
    v464 = (*qfn2(fn))(qenv(fn), v161, v464);
    nil = C_nil;
    if (exception_pending()) goto v262;
    env = stack[-7];
    stack[-2] = v464;
    goto v39;

v465:
    v464 = stack[-4];
    fn = elt(env, 10); /* comfac */
    v464 = (*qfn1(fn))(qenv(fn), v464);
    nil = C_nil;
    if (exception_pending()) goto v262;
    env = stack[-7];
    v161 = qcdr(v464);
    v464 = stack[-5];
    fn = elt(env, 11); /* gcdf1 */
    v464 = (*qfn2(fn))(qenv(fn), v161, v464);
    nil = C_nil;
    if (exception_pending()) goto v262;
    env = stack[-7];
    stack[-2] = v464;
    goto v39;

v40:
    v464 = stack[-5];
    fn = elt(env, 10); /* comfac */
    v464 = (*qfn1(fn))(qenv(fn), v464);
    nil = C_nil;
    if (exception_pending()) goto v262;
    env = stack[-7];
    stack[-1] = v464;
    v464 = stack[-4];
    fn = elt(env, 10); /* comfac */
    v464 = (*qfn1(fn))(qenv(fn), v464);
    nil = C_nil;
    if (exception_pending()) goto v262;
    env = stack[-7];
    stack[0] = v464;
    v464 = stack[-1];
    v161 = qcdr(v464);
    v464 = stack[0];
    v464 = qcdr(v464);
    fn = elt(env, 11); /* gcdf1 */
    v464 = (*qfn2(fn))(qenv(fn), v161, v464);
    nil = C_nil;
    if (exception_pending()) goto v262;
    env = stack[-7];
    stack[-2] = v464;
    v464 = stack[-1];
    fn = elt(env, 12); /* comfac!-to!-poly */
    v464 = (*qfn1(fn))(qenv(fn), v464);
    nil = C_nil;
    if (exception_pending()) goto v262;
    env = stack[-7];
    fn = elt(env, 13); /* quotf1 */
    v464 = (*qfn2(fn))(qenv(fn), stack[-5], v464);
    nil = C_nil;
    if (exception_pending()) goto v262;
    env = stack[-7];
    stack[-5] = v464;
    v464 = stack[0];
    fn = elt(env, 12); /* comfac!-to!-poly */
    v464 = (*qfn1(fn))(qenv(fn), v464);
    nil = C_nil;
    if (exception_pending()) goto v262;
    env = stack[-7];
    fn = elt(env, 13); /* quotf1 */
    v464 = (*qfn2(fn))(qenv(fn), stack[-4], v464);
    nil = C_nil;
    if (exception_pending()) goto v262;
    env = stack[-7];
    stack[-4] = v464;
    v464 = qvalue(elt(env, 2)); /* !*gcd */
    if (v464 == nil) goto v144;
    v161 = stack[-5];
    v464 = stack[-4];
    fn = elt(env, 14); /* gcdk */
    v161 = (*qfn2(fn))(qenv(fn), v161, v464);
    nil = C_nil;
    if (exception_pending()) goto v262;
    env = stack[-7];
    v464 = stack[-2];
    fn = elt(env, 15); /* multf */
    v464 = (*qfn2(fn))(qenv(fn), v161, v464);
    nil = C_nil;
    if (exception_pending()) goto v262;
    env = stack[-7];
    stack[-2] = v464;
    goto v121;

v121:
    v464 = stack[-1];
    v464 = qcar(v464);
    if (v464 == nil) goto v39;
    v464 = stack[0];
    v464 = qcar(v464);
    if (v464 == nil) goto v39;
    v464 = stack[-1];
    v464 = qcar(v464);
    v161 = qcdr(v464);
    v464 = stack[0];
    v464 = qcar(v464);
    v464 = qcdr(v464);
    v464 = (Lisp_Object)greaterp2(v161, v464);
    nil = C_nil;
    if (exception_pending()) goto v262;
    v464 = v464 ? lisp_true : nil;
    env = stack[-7];
    if (v464 == nil) goto v208;
    v464 = stack[0];
    v161 = qcar(v464);
    v464 = (Lisp_Object)17; /* 1 */
    v464 = cons(v161, v464);
    nil = C_nil;
    if (exception_pending()) goto v262;
    env = stack[-7];
    v161 = ncons(v464);
    nil = C_nil;
    if (exception_pending()) goto v262;
    env = stack[-7];
    v464 = stack[-2];
    fn = elt(env, 15); /* multf */
    v464 = (*qfn2(fn))(qenv(fn), v161, v464);
    nil = C_nil;
    if (exception_pending()) goto v262;
    env = stack[-7];
    stack[-2] = v464;
    goto v39;

v208:
    v464 = stack[-1];
    v161 = qcar(v464);
    v464 = (Lisp_Object)17; /* 1 */
    v464 = cons(v161, v464);
    nil = C_nil;
    if (exception_pending()) goto v262;
    env = stack[-7];
    v161 = ncons(v464);
    nil = C_nil;
    if (exception_pending()) goto v262;
    env = stack[-7];
    v464 = stack[-2];
    fn = elt(env, 15); /* multf */
    v464 = (*qfn2(fn))(qenv(fn), v161, v464);
    nil = C_nil;
    if (exception_pending()) goto v262;
    env = stack[-7];
    stack[-2] = v464;
    goto v39;

v144:
    v464 = stack[-4];
    if (v464 == nil) goto v231;
    v161 = stack[-5];
    v464 = stack[-4];
    fn = elt(env, 13); /* quotf1 */
    v464 = (*qfn2(fn))(qenv(fn), v161, v464);
    nil = C_nil;
    if (exception_pending()) goto v262;
    env = stack[-7];
    if (v464 == nil) goto v231;
    v161 = stack[-4];
    v464 = stack[-2];
    fn = elt(env, 15); /* multf */
    v464 = (*qfn2(fn))(qenv(fn), v161, v464);
    nil = C_nil;
    if (exception_pending()) goto v262;
    env = stack[-7];
    stack[-2] = v464;
    goto v121;

v231:
    v464 = stack[-5];
    if (v464 == nil) goto v121;
    v161 = stack[-4];
    v464 = stack[-5];
    fn = elt(env, 13); /* quotf1 */
    v464 = (*qfn2(fn))(qenv(fn), v161, v464);
    nil = C_nil;
    if (exception_pending()) goto v262;
    env = stack[-7];
    if (v464 == nil) goto v121;
    v161 = stack[-5];
    v464 = stack[-2];
    fn = elt(env, 15); /* multf */
    v464 = (*qfn2(fn))(qenv(fn), v161, v464);
    nil = C_nil;
    if (exception_pending()) goto v262;
    env = stack[-7];
    stack[-2] = v464;
    goto v121;

v52:
    v464 = nil;
    stack[-3] = v464;
    goto v41;

v7:
    v464 = (Lisp_Object)17; /* 1 */
    goto v45;
/* error exit handlers */
v262:
    env = stack[-7];
    qvalue(elt(env, 1)) = stack[-6]; /* asymplis!* */
    popv(8);
    return nil;
}



/* Code for arglist_member */

static Lisp_Object CC_arglist_member(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v23, v30;
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
    v23 = stack[0];
    if (!consp(v23)) goto v4;
    v30 = stack[-1];
    v23 = stack[0];
    v23 = qcar(v23);
    fn = elt(env, 1); /* mvar_member */
    v23 = (*qfn2(fn))(qenv(fn), v30, v23);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-2];
    if (!(v23 == nil)) { popv(3); return onevalue(v23); }
    v30 = stack[-1];
    v23 = stack[0];
    v23 = qcdr(v23);
    stack[-1] = v30;
    stack[0] = v23;
    goto v11;

v4:
    v23 = nil;
    { popv(3); return onevalue(v23); }
/* error exit handlers */
v53:
    popv(3);
    return nil;
}



/* Code for mkvarg */

static Lisp_Object CC_mkvarg(Lisp_Object env,
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
    fn = elt(env, 1); /* vmult */
    v35 = (*qfn1(fn))(qenv(fn), v35);
    nil = C_nil;
    if (exception_pending()) goto v41;
    env = stack[-3];
    stack[-1] = v35;
    v34 = nil;
    v35 = (Lisp_Object)17; /* 1 */
    v35 = cons(v34, v35);
    nil = C_nil;
    if (exception_pending()) goto v41;
    env = stack[-3];
    stack[-2] = v35;
    goto v12;

v12:
    v35 = stack[-1];
    if (v35 == nil) { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
    v34 = stack[0];
    v35 = stack[-1];
    v35 = qcar(v35);
    v35 = qcdr(v35);
    v34 = Lapply1(nil, v34, v35);
    nil = C_nil;
    if (exception_pending()) goto v41;
    env = stack[-3];
    v35 = stack[-1];
    v35 = qcar(v35);
    v35 = qcar(v35);
    fn = elt(env, 2); /* multsq */
    v34 = (*qfn2(fn))(qenv(fn), v34, v35);
    nil = C_nil;
    if (exception_pending()) goto v41;
    env = stack[-3];
    v35 = stack[-2];
    fn = elt(env, 3); /* addsq */
    v35 = (*qfn2(fn))(qenv(fn), v34, v35);
    nil = C_nil;
    if (exception_pending()) goto v41;
    env = stack[-3];
    stack[-2] = v35;
    v35 = stack[-1];
    v35 = qcdr(v35);
    stack[-1] = v35;
    goto v12;
/* error exit handlers */
v41:
    popv(4);
    return nil;
}



/* Code for vmult1 */

static Lisp_Object CC_vmult1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v230, v468, v149, v111, v216;
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
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-6] = v16;
    stack[-7] = v0;
/* end of prologue */
    stack[0] = nil;
    v230 = stack[-6];
    if (!(v230 == nil)) goto v12;
    v230 = nil;
    { popv(10); return onevalue(v230); }

v12:
    v230 = stack[-7];
    if (v230 == nil) { Lisp_Object res = stack[0]; popv(10); return onevalue(res); }
    v230 = stack[-7];
    v230 = qcar(v230);
    v230 = qcdr(v230);
    v230 = qcdr(v230);
    if (v230 == nil) goto v51;
    v216 = elt(env, 1); /* "Redundant vector in" */
    v230 = stack[-7];
    v230 = qcar(v230);
    v111 = qcdr(v230);
    v149 = nil;
    v468 = nil;
    v230 = lisp_true;
    fn = elt(env, 2); /* msgpri */
    v230 = (*qfnn(fn))(qenv(fn), 5, v216, v111, v149, v468, v230);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[-9];
    goto v51;

v51:
    stack[-8] = stack[0];
    v230 = stack[-6];
    stack[-5] = v230;
    v230 = stack[-5];
    if (v230 == nil) goto v134;
    v230 = stack[-5];
    v230 = qcar(v230);
    stack[-1] = v230;
    v230 = stack[-1];
    v468 = qcar(v230);
    v230 = stack[-7];
    v230 = qcar(v230);
    v230 = qcar(v230);
    fn = elt(env, 3); /* multsq */
    stack[0] = (*qfn2(fn))(qenv(fn), v468, v230);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[-9];
    v230 = stack[-1];
    v468 = qcdr(v230);
    v230 = stack[-7];
    v230 = qcar(v230);
    v230 = qcdr(v230);
    v230 = Lappend(nil, v468, v230);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[-9];
    v230 = cons(stack[0], v230);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[-9];
    v230 = ncons(v230);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[-9];
    stack[-3] = v230;
    stack[-4] = v230;
    goto v41;

v41:
    v230 = stack[-5];
    v230 = qcdr(v230);
    stack[-5] = v230;
    v230 = stack[-5];
    if (v230 == nil) goto v142;
    stack[-2] = stack[-3];
    v230 = stack[-5];
    v230 = qcar(v230);
    stack[-1] = v230;
    v230 = stack[-1];
    v468 = qcar(v230);
    v230 = stack[-7];
    v230 = qcar(v230);
    v230 = qcar(v230);
    fn = elt(env, 3); /* multsq */
    stack[0] = (*qfn2(fn))(qenv(fn), v468, v230);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[-9];
    v230 = stack[-1];
    v468 = qcdr(v230);
    v230 = stack[-7];
    v230 = qcar(v230);
    v230 = qcdr(v230);
    v230 = Lappend(nil, v468, v230);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[-9];
    v230 = cons(stack[0], v230);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[-9];
    v230 = ncons(v230);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[-9];
    v230 = Lrplacd(nil, stack[-2], v230);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[-9];
    v230 = stack[-3];
    v230 = qcdr(v230);
    stack[-3] = v230;
    goto v41;

v142:
    v230 = stack[-4];
    goto v50;

v50:
    fn = elt(env, 4); /* nconc!* */
    v230 = (*qfn2(fn))(qenv(fn), stack[-8], v230);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[-9];
    stack[0] = v230;
    v230 = stack[-7];
    v230 = qcdr(v230);
    stack[-7] = v230;
    goto v12;

v134:
    v230 = nil;
    goto v50;
/* error exit handlers */
v109:
    popv(10);
    return nil;
}



/* Code for simpiden */

static Lisp_Object CC_simpiden(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v269, v270, v403;
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
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0;
/* end of prologue */
    stack[-4] = nil;
    v269 = stack[0];
    v269 = qcar(v269);
    stack[-6] = v269;
    v269 = stack[0];
    v269 = qcdr(v269);
    stack[0] = v269;
    v270 = stack[-6];
    v269 = elt(env, 1); /* !:rn!: */
    v269 = get(v270, v269);
    env = stack[-7];
    if (!(v269 == nil)) goto v31;
    v270 = stack[-6];
    v269 = elt(env, 2); /* !:rd!: */
    v269 = get(v270, v269);
    env = stack[-7];
    if (!(v269 == nil)) goto v31;

v13:
    v269 = stack[0];
    if (v269 == nil) goto v50;
    v269 = stack[0];
    v270 = qcar(v269);
    v269 = elt(env, 3); /* list */
    if (!consp(v270)) goto v50;
    v270 = qcar(v270);
    if (!(v270 == v269)) goto v50;
    v269 = stack[0];
    v269 = qcdr(v269);
    if (!(v269 == nil)) goto v50;
    stack[-1] = stack[-6];
    v269 = stack[0];
    v269 = qcar(v269);
    fn = elt(env, 13); /* aeval */
    v269 = (*qfn1(fn))(qenv(fn), v269);
    nil = C_nil;
    if (exception_pending()) goto v405;
    env = stack[-7];
    v270 = list2(stack[-1], v269);
    nil = C_nil;
    if (exception_pending()) goto v405;
    env = stack[-7];
    v269 = (Lisp_Object)17; /* 1 */
    {
        popv(8);
        fn = elt(env, 14); /* mksq */
        return (*qfn2(fn))(qenv(fn), v270, v269);
    }

v50:
    v269 = stack[0];
    stack[-3] = v269;
    v269 = stack[-3];
    if (v269 == nil) goto v128;
    v269 = stack[-3];
    v269 = qcar(v269);
    fn = elt(env, 13); /* aeval */
    v269 = (*qfn1(fn))(qenv(fn), v269);
    nil = C_nil;
    if (exception_pending()) goto v405;
    env = stack[-7];
    v269 = ncons(v269);
    nil = C_nil;
    if (exception_pending()) goto v405;
    env = stack[-7];
    stack[-1] = v269;
    stack[-2] = v269;
    goto v86;

v86:
    v269 = stack[-3];
    v269 = qcdr(v269);
    stack[-3] = v269;
    v269 = stack[-3];
    if (v269 == nil) goto v121;
    stack[0] = stack[-1];
    v269 = stack[-3];
    v269 = qcar(v269);
    fn = elt(env, 13); /* aeval */
    v269 = (*qfn1(fn))(qenv(fn), v269);
    nil = C_nil;
    if (exception_pending()) goto v405;
    env = stack[-7];
    v269 = ncons(v269);
    nil = C_nil;
    if (exception_pending()) goto v405;
    env = stack[-7];
    v269 = Lrplacd(nil, stack[0], v269);
    nil = C_nil;
    if (exception_pending()) goto v405;
    env = stack[-7];
    v269 = stack[-1];
    v269 = qcdr(v269);
    stack[-1] = v269;
    goto v86;

v121:
    v269 = stack[-2];
    goto v85;

v85:
    stack[-5] = v269;
    v269 = stack[-5];
    stack[-3] = v269;
    v269 = stack[-3];
    if (v269 == nil) goto v327;
    v269 = stack[-3];
    v269 = qcar(v269);
    v403 = v269;
    v270 = v403;
    v269 = elt(env, 4); /* !*sq */
    if (!consp(v270)) goto v77;
    v270 = qcar(v270);
    if (!(v270 == v269)) goto v77;
    v269 = v403;
    v269 = qcdr(v269);
    v269 = qcar(v269);
    fn = elt(env, 15); /* prepsqxx */
    v269 = (*qfn1(fn))(qenv(fn), v269);
    nil = C_nil;
    if (exception_pending()) goto v405;
    env = stack[-7];
    goto v148;

v148:
    v269 = ncons(v269);
    nil = C_nil;
    if (exception_pending()) goto v405;
    env = stack[-7];
    stack[-1] = v269;
    stack[-2] = v269;
    goto v235;

v235:
    v269 = stack[-3];
    v269 = qcdr(v269);
    stack[-3] = v269;
    v269 = stack[-3];
    if (v269 == nil) goto v187;
    stack[0] = stack[-1];
    v269 = stack[-3];
    v269 = qcar(v269);
    v403 = v269;
    v270 = v403;
    v269 = elt(env, 4); /* !*sq */
    if (!consp(v270)) goto v131;
    v270 = qcar(v270);
    if (!(v270 == v269)) goto v131;
    v269 = v403;
    v269 = qcdr(v269);
    v269 = qcar(v269);
    fn = elt(env, 15); /* prepsqxx */
    v269 = (*qfn1(fn))(qenv(fn), v269);
    nil = C_nil;
    if (exception_pending()) goto v405;
    env = stack[-7];
    goto v129;

v129:
    v269 = ncons(v269);
    nil = C_nil;
    if (exception_pending()) goto v405;
    env = stack[-7];
    v269 = Lrplacd(nil, stack[0], v269);
    nil = C_nil;
    if (exception_pending()) goto v405;
    env = stack[-7];
    v269 = stack[-1];
    v269 = qcdr(v269);
    stack[-1] = v269;
    goto v235;

v131:
    v269 = v403;
    if (is_number(v269)) goto v257;
    v269 = v403;
    goto v129;

v257:
    v269 = v403;
    goto v129;

v187:
    v269 = stack[-2];
    goto v91;

v91:
    stack[0] = v269;
    v269 = stack[0];
    if (v269 == nil) goto v305;
    v269 = stack[0];
    v270 = qcar(v269);
    v269 = (Lisp_Object)1; /* 0 */
    if (!(v270 == v269)) goto v305;
    v270 = stack[-6];
    v269 = elt(env, 5); /* odd */
    v269 = Lflagp(nil, v270, v269);
    env = stack[-7];
    if (v269 == nil) goto v305;
    v270 = stack[-6];
    v269 = elt(env, 6); /* nonzero */
    v269 = Lflagp(nil, v270, v269);
    env = stack[-7];
    if (!(v269 == nil)) goto v305;
    v270 = nil;
    v269 = (Lisp_Object)17; /* 1 */
    popv(8);
    return cons(v270, v269);

v305:
    v270 = stack[-6];
    v269 = stack[0];
    v269 = cons(v270, v269);
    nil = C_nil;
    if (exception_pending()) goto v405;
    env = stack[-7];
    stack[0] = v269;
    v269 = stack[-6];
    if (!symbolp(v269)) v269 = nil;
    else { v269 = qfastgets(v269);
           if (v269 != nil) { v269 = elt(v269, 0); /* noncom */
#ifdef RECORD_GET
             if (v269 == SPID_NOPROP)
                record_get(elt(fastget_names, 0), 0),
                v269 = nil;
             else record_get(elt(fastget_names, 0), 1),
                v269 = lisp_true; }
           else record_get(elt(fastget_names, 0), 0); }
#else
             if (v269 == SPID_NOPROP) v269 = nil; else v269 = lisp_true; }}
#endif
    if (v269 == nil) goto v678;
    v269 = lisp_true;
    qvalue(elt(env, 7)) = v269; /* ncmp!* */
    goto v678;

v678:
    v269 = qvalue(elt(env, 8)); /* subfg!* */
    if (v269 == nil) goto v464;
    v270 = stack[-6];
    v269 = elt(env, 9); /* linear */
    v269 = Lflagp(nil, v270, v269);
    env = stack[-7];
    if (v269 == nil) goto v300;
    v269 = stack[0];
    fn = elt(env, 16); /* formlnr */
    v270 = (*qfn1(fn))(qenv(fn), v269);
    nil = C_nil;
    if (exception_pending()) goto v405;
    env = stack[-7];
    stack[-1] = v270;
    v269 = stack[0];
    v269 = Lneq(nil, v270, v269);
    nil = C_nil;
    if (exception_pending()) goto v405;
    env = stack[-7];
    if (v269 == nil) goto v300;
    v269 = stack[-1];
    {
        popv(8);
        fn = elt(env, 17); /* simp */
        return (*qfn1(fn))(qenv(fn), v269);
    }

v300:
    v269 = stack[0];
    fn = elt(env, 18); /* opmtch */
    v269 = (*qfn1(fn))(qenv(fn), v269);
    nil = C_nil;
    if (exception_pending()) goto v405;
    env = stack[-7];
    stack[-1] = v269;
    if (v269 == nil) goto v464;
    v269 = stack[-1];
    {
        popv(8);
        fn = elt(env, 17); /* simp */
        return (*qfn1(fn))(qenv(fn), v269);
    }

v464:
    v270 = stack[-6];
    v269 = elt(env, 10); /* symmetric */
    v269 = Lflagp(nil, v270, v269);
    env = stack[-7];
    if (v269 == nil) goto v679;
    stack[-1] = stack[-6];
    v269 = stack[0];
    v269 = qcdr(v269);
    fn = elt(env, 19); /* ordn */
    v269 = (*qfn1(fn))(qenv(fn), v269);
    nil = C_nil;
    if (exception_pending()) goto v405;
    env = stack[-7];
    v269 = cons(stack[-1], v269);
    nil = C_nil;
    if (exception_pending()) goto v405;
    env = stack[-7];
    stack[0] = v269;
    goto v680;

v680:
    v270 = stack[-6];
    v269 = elt(env, 12); /* even */
    v269 = Lflagp(nil, v270, v269);
    env = stack[-7];
    if (!(v269 == nil)) goto v440;
    v270 = stack[-6];
    v269 = elt(env, 5); /* odd */
    v269 = Lflagp(nil, v270, v269);
    env = stack[-7];
    if (!(v269 == nil)) goto v440;

v409:
    v270 = stack[0];
    v269 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 14); /* mksq */
    v269 = (*qfn2(fn))(qenv(fn), v270, v269);
    nil = C_nil;
    if (exception_pending()) goto v405;
    env = stack[-7];
    stack[0] = v269;
    v269 = stack[-4];
    if (v269 == nil) { Lisp_Object res = stack[0]; popv(8); return onevalue(res); }
    v269 = stack[0];
    {
        popv(8);
        fn = elt(env, 20); /* negsq */
        return (*qfn1(fn))(qenv(fn), v269);
    }

v440:
    v269 = stack[-5];
    if (v269 == nil) goto v409;
    v269 = stack[-5];
    v269 = qcar(v269);
    fn = elt(env, 17); /* simp */
    v269 = (*qfn1(fn))(qenv(fn), v269);
    nil = C_nil;
    if (exception_pending()) goto v405;
    env = stack[-7];
    stack[-5] = v269;
    v269 = qcar(v269);
    fn = elt(env, 21); /* minusf */
    v269 = (*qfn1(fn))(qenv(fn), v269);
    nil = C_nil;
    if (exception_pending()) goto v405;
    env = stack[-7];
    if (v269 == nil) goto v409;
    v270 = stack[-6];
    v269 = elt(env, 12); /* even */
    v269 = Lflagp(nil, v270, v269);
    env = stack[-7];
    if (!(v269 == nil)) goto v283;
    v269 = stack[-4];
    v269 = (v269 == nil ? lisp_true : nil);
    stack[-4] = v269;
    goto v283;

v283:
    stack[-1] = stack[-6];
    v269 = stack[-5];
    fn = elt(env, 20); /* negsq */
    v269 = (*qfn1(fn))(qenv(fn), v269);
    nil = C_nil;
    if (exception_pending()) goto v405;
    env = stack[-7];
    fn = elt(env, 15); /* prepsqxx */
    v270 = (*qfn1(fn))(qenv(fn), v269);
    nil = C_nil;
    if (exception_pending()) goto v405;
    env = stack[-7];
    v269 = stack[0];
    v269 = qcdr(v269);
    v269 = qcdr(v269);
    v269 = list2star(stack[-1], v270, v269);
    nil = C_nil;
    if (exception_pending()) goto v405;
    env = stack[-7];
    stack[0] = v269;
    v269 = stack[0];
    fn = elt(env, 18); /* opmtch */
    v269 = (*qfn1(fn))(qenv(fn), v269);
    nil = C_nil;
    if (exception_pending()) goto v405;
    env = stack[-7];
    stack[-1] = v269;
    if (v269 == nil) goto v409;
    v269 = stack[-4];
    if (v269 == nil) goto v681;
    v269 = stack[-1];
    fn = elt(env, 17); /* simp */
    v269 = (*qfn1(fn))(qenv(fn), v269);
    nil = C_nil;
    if (exception_pending()) goto v405;
    env = stack[-7];
    {
        popv(8);
        fn = elt(env, 20); /* negsq */
        return (*qfn1(fn))(qenv(fn), v269);
    }

v681:
    v269 = stack[-1];
    {
        popv(8);
        fn = elt(env, 17); /* simp */
        return (*qfn1(fn))(qenv(fn), v269);
    }

v679:
    v270 = stack[-6];
    v269 = elt(env, 11); /* antisymmetric */
    v269 = Lflagp(nil, v270, v269);
    env = stack[-7];
    if (v269 == nil) goto v680;
    v269 = stack[0];
    v269 = qcdr(v269);
    fn = elt(env, 22); /* repeats */
    v269 = (*qfn1(fn))(qenv(fn), v269);
    nil = C_nil;
    if (exception_pending()) goto v405;
    env = stack[-7];
    if (v269 == nil) goto v426;
    v270 = nil;
    v269 = (Lisp_Object)17; /* 1 */
    popv(8);
    return cons(v270, v269);

v426:
    v269 = stack[0];
    v269 = qcdr(v269);
    fn = elt(env, 19); /* ordn */
    v270 = (*qfn1(fn))(qenv(fn), v269);
    nil = C_nil;
    if (exception_pending()) goto v405;
    env = stack[-7];
    stack[-1] = v270;
    v269 = stack[0];
    v269 = qcdr(v269);
    fn = elt(env, 23); /* permp */
    v269 = (*qfn2(fn))(qenv(fn), v270, v269);
    nil = C_nil;
    if (exception_pending()) goto v405;
    env = stack[-7];
    if (!(v269 == nil)) goto v543;
    v269 = lisp_true;
    stack[-4] = v269;
    goto v543;

v543:
    v269 = stack[0];
    v270 = qcar(v269);
    v269 = stack[-1];
    v269 = cons(v270, v269);
    nil = C_nil;
    if (exception_pending()) goto v405;
    env = stack[-7];
    stack[-6] = v269;
    v270 = stack[-1];
    v269 = stack[0];
    v269 = qcdr(v269);
    v269 = Lneq(nil, v270, v269);
    nil = C_nil;
    if (exception_pending()) goto v405;
    env = stack[-7];
    if (v269 == nil) goto v196;
    v269 = stack[-6];
    fn = elt(env, 18); /* opmtch */
    v269 = (*qfn1(fn))(qenv(fn), v269);
    nil = C_nil;
    if (exception_pending()) goto v405;
    env = stack[-7];
    stack[-1] = v269;
    if (v269 == nil) goto v196;
    v269 = stack[-4];
    if (v269 == nil) goto v480;
    v269 = stack[-1];
    fn = elt(env, 17); /* simp */
    v269 = (*qfn1(fn))(qenv(fn), v269);
    nil = C_nil;
    if (exception_pending()) goto v405;
    env = stack[-7];
    {
        popv(8);
        fn = elt(env, 20); /* negsq */
        return (*qfn1(fn))(qenv(fn), v269);
    }

v480:
    v269 = stack[-1];
    {
        popv(8);
        fn = elt(env, 17); /* simp */
        return (*qfn1(fn))(qenv(fn), v269);
    }

v196:
    v269 = stack[-6];
    stack[0] = v269;
    goto v680;

v77:
    v269 = v403;
    if (is_number(v269)) goto v92;
    v269 = v403;
    goto v148;

v92:
    v269 = v403;
    goto v148;

v327:
    v269 = nil;
    goto v91;

v128:
    v269 = nil;
    goto v85;

v31:
    v270 = stack[-6];
    v269 = stack[0];
    fn = elt(env, 24); /* valuechk */
    v269 = (*qfn2(fn))(qenv(fn), v270, v269);
    nil = C_nil;
    if (exception_pending()) goto v405;
    env = stack[-7];
    stack[-5] = v269;
    if (v269 == nil) goto v13;
    else { Lisp_Object res = stack[-5]; popv(8); return onevalue(res); }
/* error exit handlers */
v405:
    popv(8);
    return nil;
}



/* Code for condterpri */

static Lisp_Object MS_CDECL CC_condterpri(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v30;
    argcheck(nargs, 0, "condterpri");
    CSL_IGNORE(env);
/* end of prologue */
    v30 = qvalue(elt(env, 1)); /* !*output */
    if (v30 == nil) goto v9;
    v30 = qvalue(elt(env, 2)); /* !*echo */
    if (v30 == nil) goto v45;
    v30 = qvalue(elt(env, 3)); /* !*extraecho */
    if (v30 == nil) goto v8;
    v30 = qvalue(elt(env, 4)); /* !*int */
    if (v30 == nil) goto v24;
    v30 = qvalue(elt(env, 5)); /* ifl!* */
    if (!(v30 == nil)) goto v24;
    v30 = nil;
    return onevalue(v30);

v24:
    v30 = qvalue(elt(env, 6)); /* !*defn */
    if (v30 == nil) goto v15;
    v30 = nil;
    return onevalue(v30);

v15:
    v30 = qvalue(elt(env, 7)); /* !*demo */
    if (v30 == nil) goto v21;
    v30 = nil;
    return onevalue(v30);

v21:
        return Lterpri(nil, 0);

v8:
    v30 = nil;
    return onevalue(v30);

v45:
    v30 = nil;
    return onevalue(v30);

v9:
    v30 = nil;
    return onevalue(v30);
}



/* Code for prepreform */

static Lisp_Object CC_prepreform(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v26, v27;
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
    v26 = v0;
/* end of prologue */
    stack[0] = v26;
    v27 = qvalue(elt(env, 1)); /* ordl!* */
    v26 = qvalue(elt(env, 2)); /* factors!* */
    v26 = Lappend(nil, v27, v26);
    nil = C_nil;
    if (exception_pending()) goto v38;
    env = stack[-1];
    {
        Lisp_Object v44 = stack[0];
        popv(2);
        fn = elt(env, 3); /* prepreform1 */
        return (*qfn2(fn))(qenv(fn), v44, v26);
    }
/* error exit handlers */
v38:
    popv(2);
    return nil;
}



/* Code for revalx */

static Lisp_Object CC_revalx(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v26, v27;
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
    v27 = v0;
/* end of prologue */
    v26 = v27;
    if (!consp(v26)) goto v25;
    v26 = v27;
    v26 = qcar(v26);
    if (!consp(v26)) goto v25;
    v26 = v27;
    fn = elt(env, 1); /* prepf */
    v26 = (*qfn1(fn))(qenv(fn), v26);
    nil = C_nil;
    if (exception_pending()) goto v28;
    env = stack[0];
    goto v3;

v3:
    {
        popv(1);
        fn = elt(env, 2); /* reval */
        return (*qfn1(fn))(qenv(fn), v26);
    }

v25:
    v26 = v27;
    goto v3;
/* error exit handlers */
v28:
    popv(1);
    return nil;
}



/* Code for !*!*a2s */

static Lisp_Object CC_HHa2s(Lisp_Object env,
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
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    v55 = v16;
    stack[-1] = v0;
/* end of prologue */
    v55 = stack[-1];
    if (v55 == nil) goto v4;
    v65 = stack[-1];
    v55 = elt(env, 2); /* nochange */
    v55 = Lflagpcar(nil, v65, v55);
    env = stack[-3];
    if (v55 == nil) goto v99;
    v55 = stack[-1];
    v65 = qcar(v55);
    v55 = elt(env, 3); /* getel */
    if (!(v65 == v55)) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }

v99:
    v65 = elt(env, 4); /* random */
    v55 = stack[-1];
    v55 = Lsmemq(nil, v65, v55);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-3];
    if (v55 == nil) goto v70;
    stack[-2] = elt(env, 5); /* lambda */
    stack[0] = elt(env, 6); /* (!*uncached) */
    v65 = qvalue(elt(env, 7)); /* !*!*a2sfn */
    v55 = stack[-1];
    v55 = list2(v65, v55);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-3];
    v65 = list3(stack[-2], stack[0], v55);
    nil = C_nil;
    if (exception_pending()) goto v102;
    v55 = lisp_true;
    popv(4);
    return list2(v65, v55);

v70:
    v65 = qvalue(elt(env, 7)); /* !*!*a2sfn */
    v55 = stack[-1];
    popv(4);
    return list2(v65, v55);

v4:
    v55 = elt(env, 1); /* "tell Hearn!!" */
    {
        popv(4);
        fn = elt(env, 8); /* rederr */
        return (*qfn1(fn))(qenv(fn), v55);
    }
/* error exit handlers */
v102:
    popv(4);
    return nil;
}



/* Code for eofcheck */

static Lisp_Object MS_CDECL CC_eofcheck(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v18, v19;
    argcheck(nargs, 0, "eofcheck");
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* end of prologue */
    v19 = qvalue(elt(env, 1)); /* program!* */
    v18 = qvalue(elt(env, 2)); /* !$eof!$ */
    if (v19 == v18) goto v13;
    v18 = nil;
    { popv(1); return onevalue(v18); }

v13:
    v19 = qvalue(elt(env, 3)); /* ttype!* */
    v18 = (Lisp_Object)49; /* 3 */
    if (v19 == v18) goto v15;
    v18 = nil;
    { popv(1); return onevalue(v18); }

v15:
    v18 = qvalue(elt(env, 4)); /* eof!* */
    v18 = add1(v18);
    nil = C_nil;
    if (exception_pending()) goto v20;
    env = stack[0];
    qvalue(elt(env, 4)) = v18; /* eof!* */
    { popv(1); return onevalue(v18); }
/* error exit handlers */
v20:
    popv(1);
    return nil;
}



/* Code for veval */

static Lisp_Object CC_veval(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v107, v141, v128, v234, v112;
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
    v107 = v16;
    v141 = v0;
/* end of prologue */
    stack[0] = nil;
    v107 = elt(env, 1); /* hvector */
    fn = elt(env, 5); /* nssimp */
    v107 = (*qfn2(fn))(qenv(fn), v141, v107);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-3];
    stack[-2] = v107;
    goto v6;

v6:
    v107 = stack[-2];
    if (v107 == nil) goto v5;
    v107 = stack[-2];
    v107 = qcar(v107);
    stack[-1] = v107;
    v107 = stack[-1];
    v107 = qcdr(v107);
    if (v107 == nil) goto v99;
    v107 = stack[-1];
    v107 = qcdr(v107);
    v107 = qcdr(v107);
    if (v107 == nil) goto v55;
    v112 = elt(env, 4); /* "Redundant vector in" */
    v107 = stack[-1];
    v234 = qcdr(v107);
    v128 = nil;
    v141 = nil;
    v107 = lisp_true;
    fn = elt(env, 6); /* msgpri */
    v107 = (*qfnn(fn))(qenv(fn), 5, v112, v234, v128, v141, v107);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-3];
    goto v55;

v55:
    v107 = stack[-1];
    v107 = qcar(v107);
    fn = elt(env, 7); /* prepsq */
    v141 = (*qfn1(fn))(qenv(fn), v107);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-3];
    v107 = stack[-1];
    v107 = qcdr(v107);
    v107 = cons(v141, v107);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-3];
    fn = elt(env, 8); /* retimes */
    v107 = (*qfn1(fn))(qenv(fn), v107);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-3];
    fn = elt(env, 9); /* aconc!* */
    v107 = (*qfn2(fn))(qenv(fn), stack[0], v107);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-3];
    stack[0] = v107;
    v107 = stack[-2];
    v107 = qcdr(v107);
    stack[-2] = v107;
    goto v6;

v99:
    v128 = elt(env, 2); /* hephys */
    v141 = (Lisp_Object)49; /* 3 */
    v107 = elt(env, 3); /* "Missing vector" */
    fn = elt(env, 10); /* rerror */
    v107 = (*qfnn(fn))(qenv(fn), 3, v128, v141, v107);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-3];
    goto v55;

v5:
    v107 = stack[0];
    {
        popv(4);
        fn = elt(env, 11); /* replus */
        return (*qfn1(fn))(qenv(fn), v107);
    }
/* error exit handlers */
v145:
    popv(4);
    return nil;
}



/* Code for remcomma */

static Lisp_Object CC_remcomma(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v38, v44, v47;
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v44 = v0;
/* end of prologue */
    v38 = v44;
    v47 = elt(env, 1); /* !*comma!* */
    if (!consp(v38)) goto v24;
    v38 = qcar(v38);
    if (!(v38 == v47)) goto v24;
    v38 = v44;
    v38 = qcdr(v38);
    return onevalue(v38);

v24:
    v38 = v44;
    return ncons(v38);
}



/* Code for add2inputbuf */

static Lisp_Object CC_add2inputbuf(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v23, v30, v99;
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
    fn = elt(env, 4); /* terminalp */
    v23 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v14;
    env = stack[-2];
    if (v23 == nil) goto v45;
    v23 = qvalue(elt(env, 1)); /* !*nosave!* */
    if (!(v23 == nil)) goto v45;
    v99 = qvalue(elt(env, 2)); /* statcounter */
    v30 = stack[0];
    v23 = stack[-1];
    v30 = list3(v99, v30, v23);
    nil = C_nil;
    if (exception_pending()) goto v14;
    env = stack[-2];
    v23 = qvalue(elt(env, 3)); /* inputbuflis!* */
    v23 = cons(v30, v23);
    nil = C_nil;
    if (exception_pending()) goto v14;
    env = stack[-2];
    qvalue(elt(env, 3)) = v23; /* inputbuflis!* */
    v23 = nil;
    { popv(3); return onevalue(v23); }

v45:
    v23 = nil;
    { popv(3); return onevalue(v23); }
/* error exit handlers */
v14:
    popv(3);
    return nil;
}



/* Code for requote1 */

static Lisp_Object CC_requote1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v120, v226;
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
    v120 = stack[0];
    if (v120 == nil) goto v6;
    v120 = stack[0];
    v120 = qcar(v120);
    if (is_number(v120)) goto v21;
    v120 = stack[0];
    v226 = qcar(v120);
    v120 = elt(env, 1); /* (nil t) */
    v120 = Lmemq(nil, v226, v120);
    if (!(v120 == nil)) goto v21;
    v120 = stack[0];
    v120 = qcar(v120);
    if (!consp(v120)) goto v46;
    v120 = stack[0];
    v120 = qcar(v120);
    v226 = qcar(v120);
    v120 = elt(env, 2); /* quote */
    if (v226 == v120) goto v206;
    v120 = stack[0];
    v120 = qcar(v120);
    v226 = qcar(v120);
    v120 = elt(env, 3); /* list */
    if (!(v226 == v120)) goto v107;
    v120 = stack[0];
    v120 = qcar(v120);
    v120 = qcdr(v120);
    v120 = CC_requote1(env, v120);
    nil = C_nil;
    if (exception_pending()) goto v146;
    env = stack[-2];
    v226 = v120;
    if (v120 == nil) goto v107;
    v120 = stack[-1];
    v120 = cons(v226, v120);
    nil = C_nil;
    if (exception_pending()) goto v146;
    env = stack[-2];
    stack[-1] = v120;
    goto v5;

v5:
    v120 = stack[0];
    v120 = qcdr(v120);
    stack[0] = v120;
    goto v12;

v107:
    v120 = nil;
    { popv(3); return onevalue(v120); }

v206:
    v120 = stack[0];
    v120 = qcar(v120);
    v120 = qcdr(v120);
    v226 = qcar(v120);
    v120 = stack[-1];
    v120 = cons(v226, v120);
    nil = C_nil;
    if (exception_pending()) goto v146;
    env = stack[-2];
    stack[-1] = v120;
    goto v5;

v46:
    v120 = nil;
    { popv(3); return onevalue(v120); }

v21:
    v120 = stack[0];
    v226 = qcar(v120);
    v120 = stack[-1];
    v120 = cons(v226, v120);
    nil = C_nil;
    if (exception_pending()) goto v146;
    env = stack[-2];
    stack[-1] = v120;
    goto v5;

v6:
    v120 = stack[-1];
        popv(3);
        return Lnreverse(nil, v120);
/* error exit handlers */
v146:
    popv(3);
    return nil;
}



/* Code for simpatom */

static Lisp_Object CC_simpatom(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v249, v168, v167;
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
    v249 = stack[-1];
    if (v249 == nil) goto v5;
    v249 = stack[-1];
    if (is_number(v249)) goto v47;
    v249 = stack[-1];
    v249 = Lstringp(nil, v249);
    env = stack[-3];
    if (v249 == nil) goto v468;
    v168 = elt(env, 7); /* "String" */
    v249 = stack[-1];
    v168 = list2(v168, v249);
    nil = C_nil;
    if (exception_pending()) goto v485;
    env = stack[-3];
    v249 = elt(env, 8); /* "identifier" */
    {
        popv(4);
        fn = elt(env, 15); /* typerr */
        return (*qfn2(fn))(qenv(fn), v168, v249);
    }

v468:
    v168 = stack[-1];
    v249 = elt(env, 9); /* share */
    v249 = Lflagp(nil, v168, v249);
    env = stack[-3];
    if (v249 == nil) goto v199;
    v249 = stack[-1];
    fn = elt(env, 16); /* lispeval */
    v249 = (*qfn1(fn))(qenv(fn), v249);
    nil = C_nil;
    if (exception_pending()) goto v485;
    env = stack[-3];
    v167 = v249;
    v168 = v167;
    v249 = stack[-1];
    if (v168 == v249) goto v187;
    v249 = v167;
    {
        popv(4);
        fn = elt(env, 17); /* simp */
        return (*qfn1(fn))(qenv(fn), v249);
    }

v187:
    v168 = stack[-1];
    v249 = (Lisp_Object)17; /* 1 */
    {
        popv(4);
        fn = elt(env, 18); /* mksq */
        return (*qfn2(fn))(qenv(fn), v168, v249);
    }

v199:
    v168 = stack[-1];
    v249 = elt(env, 10); /* idvalfn */
    v249 = get(v168, v249);
    env = stack[-3];
    stack[-2] = v249;
    if (v249 == nil) goto v261;
    v168 = stack[-2];
    v249 = stack[-1];
        popv(4);
        return Lapply1(nil, v168, v249);

v261:
    v249 = qvalue(elt(env, 11)); /* !*numval */
    if (v249 == nil) goto v471;
    v249 = qvalue(elt(env, 2)); /* dmode!* */
    if (v249 == nil) goto v471;
    v168 = stack[-1];
    v249 = elt(env, 12); /* constant */
    v249 = Lflagp(nil, v168, v249);
    env = stack[-3];
    if (v249 == nil) goto v471;
    v168 = stack[-1];
    v249 = qvalue(elt(env, 2)); /* dmode!* */
    v249 = get(v168, v249);
    env = stack[-3];
    stack[-2] = v249;
    if (v249 == nil) goto v471;
    stack[0] = elt(env, 13); /* lispapply */
    v249 = stack[-2];
    v168 = Lmkquote(nil, v249);
    nil = C_nil;
    if (exception_pending()) goto v485;
    env = stack[-3];
    v249 = nil;
    v168 = list3(stack[0], v168, v249);
    nil = C_nil;
    if (exception_pending()) goto v485;
    env = stack[-3];
    v249 = nil;
    fn = elt(env, 19); /* errorset!* */
    v249 = (*qfn2(fn))(qenv(fn), v168, v249);
    nil = C_nil;
    if (exception_pending()) goto v485;
    env = stack[-3];
    stack[-2] = v249;
    fn = elt(env, 20); /* errorp */
    v249 = (*qfn1(fn))(qenv(fn), v249);
    nil = C_nil;
    if (exception_pending()) goto v485;
    env = stack[-3];
    if (!(v249 == nil)) goto v471;
    v249 = stack[-2];
    v249 = qcar(v249);
    {
        popv(4);
        fn = elt(env, 21); /* !*d2q */
        return (*qfn1(fn))(qenv(fn), v249);
    }

v471:
    v249 = stack[-1];
    fn = elt(env, 22); /* getrtype */
    v249 = (*qfn1(fn))(qenv(fn), v249);
    nil = C_nil;
    if (exception_pending()) goto v485;
    env = stack[-3];
    if (v249 == nil) goto v507;
    v168 = stack[-1];
    v249 = elt(env, 14); /* scalar */
    fn = elt(env, 15); /* typerr */
    v249 = (*qfn2(fn))(qenv(fn), v168, v249);
    nil = C_nil;
    if (exception_pending()) goto v485;
    v249 = nil;
    { popv(4); return onevalue(v249); }

v507:
    v168 = stack[-1];
    v249 = (Lisp_Object)17; /* 1 */
    {
        popv(4);
        fn = elt(env, 18); /* mksq */
        return (*qfn2(fn))(qenv(fn), v168, v249);
    }

v47:
    v168 = stack[-1];
    v249 = (Lisp_Object)1; /* 0 */
    if (v168 == v249) goto v21;
    v249 = stack[-1];
    v249 = integerp(v249);
    if (v249 == nil) goto v36;
    v168 = qvalue(elt(env, 2)); /* dmode!* */
    v249 = elt(env, 3); /* !:mod!: */
    if (!(v168 == v249)) goto v106;
    v168 = qvalue(elt(env, 4)); /* current!-modulus */
    v249 = (Lisp_Object)17; /* 1 */
    if (!(v168 == v249)) goto v106;
    v168 = nil;
    v249 = (Lisp_Object)17; /* 1 */
    popv(4);
    return cons(v168, v249);

v106:
    v168 = qvalue(elt(env, 2)); /* dmode!* */
    v249 = elt(env, 5); /* convert */
    v249 = Lflagp(nil, v168, v249);
    env = stack[-3];
    if (v249 == nil) goto v113;
    v168 = stack[-1];
    v249 = (Lisp_Object)17; /* 1 */
    v249 = Lneq(nil, v168, v249);
    nil = C_nil;
    if (exception_pending()) goto v485;
    env = stack[-3];
    if (v249 == nil) goto v113;
    v168 = qvalue(elt(env, 2)); /* dmode!* */
    v249 = elt(env, 6); /* i2d */
    v168 = get(v168, v249);
    env = stack[-3];
    v249 = stack[-1];
    v249 = Lapply1(nil, v168, v249);
    nil = C_nil;
    if (exception_pending()) goto v485;
    env = stack[-3];
    {
        popv(4);
        fn = elt(env, 21); /* !*d2q */
        return (*qfn1(fn))(qenv(fn), v249);
    }

v113:
    v168 = stack[-1];
    v249 = (Lisp_Object)17; /* 1 */
    popv(4);
    return cons(v168, v249);

v36:
    stack[0] = elt(env, 1); /* !:rd!: */
    v249 = stack[-1];
    fn = elt(env, 23); /* fl2bf */
    v249 = (*qfn1(fn))(qenv(fn), v249);
    nil = C_nil;
    if (exception_pending()) goto v485;
    v168 = qcdr(v249);
    v249 = (Lisp_Object)17; /* 1 */
    {
        Lisp_Object v345 = stack[0];
        popv(4);
        return acons(v345, v168, v249);
    }

v21:
    v168 = nil;
    v249 = (Lisp_Object)17; /* 1 */
    popv(4);
    return cons(v168, v249);

v5:
    v168 = nil;
    v249 = (Lisp_Object)17; /* 1 */
    popv(4);
    return cons(v168, v249);
/* error exit handlers */
v485:
    popv(4);
    return nil;
}



/* Code for symbol */

static Lisp_Object CC_symbol(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v7, v8;
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v7 = v0;
/* end of prologue */
    v8 = elt(env, 1); /* symbol!-character */
    return get(v7, v8);
}



/* Code for subs3t */

static Lisp_Object CC_subs3t(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v676, v674, v685, v322;
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
    v674 = v16;
    stack[-4] = v0;
/* end of prologue */
    stack[-5] = nil;
    v676 = stack[-4];
    stack[0] = qcar(v676);
    v676 = stack[-4];
    v676 = qcdr(v676);
    if (!consp(v676)) goto v46;
    v676 = stack[-4];
    v676 = qcdr(v676);
    v676 = qcar(v676);
    if (!consp(v676)) goto v46;
    v676 = v674;
    goto v38;

v38:
    fn = elt(env, 5); /* mtchk */
    v676 = (*qfn2(fn))(qenv(fn), stack[0], v676);
    nil = C_nil;
    if (exception_pending()) goto v686;
    env = stack[-6];
    stack[-3] = v676;
    v676 = stack[-3];
    if (v676 == nil) goto v145;
    v676 = stack[-3];
    v676 = qcar(v676);
    v676 = qcar(v676);
    if (v676 == nil) goto v8;
    v676 = stack[-4];
    v685 = qcdr(v676);
    v674 = stack[-3];
    v676 = nil;
    fn = elt(env, 6); /* subs3f1 */
    v676 = (*qfnn(fn))(qenv(fn), 3, v685, v674, v676);
    nil = C_nil;
    if (exception_pending()) goto v686;
    env = stack[-6];
    stack[-2] = v676;
    v676 = qvalue(elt(env, 1)); /* mchfg!* */
    if (v676 == nil) goto v145;
    v676 = stack[-4];
    v674 = qcar(v676);
    v676 = (Lisp_Object)17; /* 1 */
    v676 = cons(v674, v676);
    nil = C_nil;
    if (exception_pending()) goto v686;
    env = stack[-6];
    v674 = ncons(v676);
    nil = C_nil;
    if (exception_pending()) goto v686;
    env = stack[-6];
    v676 = (Lisp_Object)17; /* 1 */
    v674 = cons(v674, v676);
    nil = C_nil;
    if (exception_pending()) goto v686;
    env = stack[-6];
    v676 = stack[-2];
    {
        popv(7);
        fn = elt(env, 7); /* multsq */
        return (*qfn2(fn))(qenv(fn), v674, v676);
    }

v145:
    v676 = stack[-4];
    v674 = ncons(v676);
    nil = C_nil;
    if (exception_pending()) goto v686;
    v676 = (Lisp_Object)17; /* 1 */
    popv(7);
    return cons(v674, v676);

v8:
    v676 = stack[-3];
    v676 = qcar(v676);
    v676 = qcdr(v676);
    v676 = qcdr(v676);
    stack[-3] = v676;
    v676 = stack[-3];
    v676 = qcdr(v676);
    v676 = qcar(v676);
    v676 = qcar(v676);
    stack[-1] = v676;
    v676 = nil;
    qvalue(elt(env, 1)) = v676; /* mchfg!* */
    v676 = stack[-4];
    v685 = qcdr(v676);
    v674 = qvalue(elt(env, 2)); /* !*match */
    v676 = nil;
    fn = elt(env, 6); /* subs3f1 */
    v676 = (*qfnn(fn))(qenv(fn), 3, v685, v674, v676);
    nil = C_nil;
    if (exception_pending()) goto v686;
    env = stack[-6];
    stack[-2] = v676;
    v676 = lisp_true;
    qvalue(elt(env, 1)) = v676; /* mchfg!* */
    v676 = stack[-1];
    v674 = qcar(v676);
    v676 = stack[-4];
    v676 = qcar(v676);
    v676 = qcar(v676);
    v676 = Lneq(nil, v674, v676);
    nil = C_nil;
    if (exception_pending()) goto v686;
    env = stack[-6];
    if (v676 == nil) goto v78;
    v676 = stack[-1];
    v676 = qcar(v676);
    fn = elt(env, 8); /* simp */
    stack[0] = (*qfn1(fn))(qenv(fn), v676);
    nil = C_nil;
    if (exception_pending()) goto v686;
    env = stack[-6];
    v676 = stack[-4];
    v676 = qcar(v676);
    v676 = qcar(v676);
    fn = elt(env, 8); /* simp */
    v676 = (*qfn1(fn))(qenv(fn), v676);
    nil = C_nil;
    if (exception_pending()) goto v686;
    env = stack[-6];
    v676 = Lneq(nil, stack[0], v676);
    nil = C_nil;
    if (exception_pending()) goto v686;
    env = stack[-6];
    if (v676 == nil) goto v488;
    v322 = elt(env, 0); /* subs3t */
    v685 = stack[-4];
    v674 = stack[-3];
    v676 = stack[-1];
    v676 = list4(v322, v685, v674, v676);
    nil = C_nil;
    if (exception_pending()) goto v686;
    env = stack[-6];
    fn = elt(env, 9); /* errach */
    v676 = (*qfn1(fn))(qenv(fn), v676);
    nil = C_nil;
    if (exception_pending()) goto v686;
    env = stack[-6];
    goto v488;

v488:
    v676 = stack[-1];
    v674 = qcdr(v676);
    v676 = stack[-4];
    v676 = qcar(v676);
    v676 = qcdr(v676);
    v676 = Lneq(nil, v674, v676);
    nil = C_nil;
    if (exception_pending()) goto v686;
    env = stack[-6];
    if (v676 == nil) goto v184;
    v676 = stack[-4];
    v676 = qcar(v676);
    stack[0] = qcar(v676);
    v676 = stack[-4];
    v676 = qcar(v676);
    v674 = qcdr(v676);
    v676 = stack[-1];
    v676 = qcdr(v676);
    v676 = difference2(v674, v676);
    nil = C_nil;
    if (exception_pending()) goto v686;
    env = stack[-6];
    fn = elt(env, 10); /* to */
    v674 = (*qfn2(fn))(qenv(fn), stack[0], v676);
    nil = C_nil;
    if (exception_pending()) goto v686;
    env = stack[-6];
    v676 = (Lisp_Object)17; /* 1 */
    v676 = cons(v674, v676);
    nil = C_nil;
    if (exception_pending()) goto v686;
    env = stack[-6];
    v674 = ncons(v676);
    nil = C_nil;
    if (exception_pending()) goto v686;
    env = stack[-6];
    v676 = (Lisp_Object)17; /* 1 */
    v674 = cons(v674, v676);
    nil = C_nil;
    if (exception_pending()) goto v686;
    env = stack[-6];
    v676 = stack[-2];
    fn = elt(env, 7); /* multsq */
    v676 = (*qfn2(fn))(qenv(fn), v674, v676);
    nil = C_nil;
    if (exception_pending()) goto v686;
    env = stack[-6];
    stack[-2] = v676;
    goto v184;

v184:
    v676 = stack[-3];
    fn = elt(env, 11); /* simpcar */
    v674 = (*qfn1(fn))(qenv(fn), v676);
    nil = C_nil;
    if (exception_pending()) goto v686;
    env = stack[-6];
    v676 = stack[-2];
    fn = elt(env, 7); /* multsq */
    v676 = (*qfn2(fn))(qenv(fn), v674, v676);
    nil = C_nil;
    if (exception_pending()) goto v686;
    env = stack[-6];
    stack[-2] = v676;
    v676 = stack[-3];
    v676 = qcdr(v676);
    v676 = qcar(v676);
    v676 = qcdr(v676);
    stack[-3] = v676;
    v676 = stack[-3];
    if (v676 == nil) { Lisp_Object res = stack[-2]; popv(7); return onevalue(res); }
    v676 = (Lisp_Object)17; /* 1 */
    stack[-1] = v676;
    goto v2;

v2:
    v676 = stack[-3];
    if (v676 == nil) goto v25;
    v676 = stack[-3];
    v676 = qcar(v676);
    v676 = qcar(v676);
    if (!consp(v676)) goto v349;
    v676 = stack[-3];
    v676 = qcar(v676);
    v676 = qcar(v676);
    fn = elt(env, 12); /* sfp */
    v676 = (*qfn1(fn))(qenv(fn), v676);
    nil = C_nil;
    if (exception_pending()) goto v686;
    env = stack[-6];
    if (!(v676 == nil)) goto v349;
    v676 = nil;
    stack[-4] = qvalue(elt(env, 3)); /* subfg!* */
    qvalue(elt(env, 3)) = v676; /* subfg!* */
    v676 = stack[-3];
    v676 = qcar(v676);
    v676 = qcar(v676);
    fn = elt(env, 8); /* simp */
    v676 = (*qfn1(fn))(qenv(fn), v676);
    nil = C_nil;
    if (exception_pending()) goto v278;
    env = stack[-6];
    stack[0] = v676;
    v676 = stack[0];
    fn = elt(env, 13); /* kernp */
    v676 = (*qfn1(fn))(qenv(fn), v676);
    nil = C_nil;
    if (exception_pending()) goto v278;
    env = stack[-6];
    if (v676 == nil) goto v457;
    v676 = stack[0];
    v676 = qcar(v676);
    v676 = qcar(v676);
    v676 = qcar(v676);
    v674 = qcar(v676);
    stack[0] = v674;
    v676 = stack[-3];
    v676 = qcar(v676);
    v676 = qcar(v676);
    v676 = qcar(v676);
    if (!consp(v674)) goto v457;
    v674 = qcar(v674);
    if (!(v674 == v676)) goto v457;
    v676 = stack[0];
    goto v175;

v175:
    qvalue(elt(env, 3)) = stack[-4]; /* subfg!* */
    goto v519;

v519:
    stack[0] = v676;
    v676 = stack[0];
    fn = elt(env, 14); /* noncomp */
    v676 = (*qfn1(fn))(qenv(fn), v676);
    nil = C_nil;
    if (exception_pending()) goto v686;
    env = stack[-6];
    if (!(v676 == nil)) goto v167;
    v676 = qvalue(elt(env, 4)); /* !*mcd */
    if (!(v676 == nil)) goto v301;

v167:
    v676 = lisp_true;
    stack[-5] = v676;
    goto v301;

v301:
    v676 = stack[-5];
    if (v676 == nil) goto v479;
    v676 = stack[-3];
    v676 = qcar(v676);
    v676 = qcdr(v676);
    v676 = negate(v676);
    nil = C_nil;
    if (exception_pending()) goto v686;
    env = stack[-6];
    goto v299;

v299:
    fn = elt(env, 15); /* mksp */
    v674 = (*qfn2(fn))(qenv(fn), stack[0], v676);
    nil = C_nil;
    if (exception_pending()) goto v686;
    env = stack[-6];
    v676 = (Lisp_Object)17; /* 1 */
    v676 = cons(v674, v676);
    nil = C_nil;
    if (exception_pending()) goto v686;
    env = stack[-6];
    v676 = ncons(v676);
    nil = C_nil;
    if (exception_pending()) goto v686;
    env = stack[-6];
    fn = elt(env, 16); /* multf */
    v676 = (*qfn2(fn))(qenv(fn), stack[-1], v676);
    nil = C_nil;
    if (exception_pending()) goto v686;
    env = stack[-6];
    stack[-1] = v676;
    v676 = stack[-3];
    v676 = qcdr(v676);
    stack[-3] = v676;
    goto v2;

v479:
    v676 = stack[-3];
    v676 = qcar(v676);
    v676 = qcdr(v676);
    goto v299;

v457:
    v676 = stack[-3];
    v676 = qcar(v676);
    v676 = qcar(v676);
    fn = elt(env, 17); /* revop1 */
    v676 = (*qfn1(fn))(qenv(fn), v676);
    nil = C_nil;
    if (exception_pending()) goto v278;
    env = stack[-6];
    goto v175;

v349:
    v676 = stack[-3];
    v676 = qcar(v676);
    v676 = qcar(v676);
    goto v519;

v25:
    v676 = stack[-5];
    if (v676 == nil) goto v492;
    v674 = stack[-1];
    v676 = stack[-2];
    v676 = qcar(v676);
    fn = elt(env, 16); /* multf */
    v674 = (*qfn2(fn))(qenv(fn), v674, v676);
    nil = C_nil;
    if (exception_pending()) goto v686;
    v676 = stack[-2];
    v676 = qcdr(v676);
    popv(7);
    return cons(v674, v676);

v492:
    v676 = stack[-2];
    stack[0] = qcar(v676);
    v674 = stack[-1];
    v676 = stack[-2];
    v676 = qcdr(v676);
    fn = elt(env, 16); /* multf */
    v676 = (*qfn2(fn))(qenv(fn), v674, v676);
    nil = C_nil;
    if (exception_pending()) goto v686;
    {
        Lisp_Object v279 = stack[0];
        popv(7);
        return cons(v279, v676);
    }

v78:
    v674 = stack[-1];
    v676 = stack[-4];
    v676 = qcar(v676);
    v676 = Lneq(nil, v674, v676);
    nil = C_nil;
    if (exception_pending()) goto v686;
    env = stack[-6];
    if (v676 == nil) goto v184;
    v676 = stack[-4];
    v676 = qcar(v676);
    stack[0] = qcar(v676);
    v676 = stack[-4];
    v676 = qcar(v676);
    v674 = qcdr(v676);
    v676 = stack[-1];
    v676 = qcdr(v676);
    v676 = difference2(v674, v676);
    nil = C_nil;
    if (exception_pending()) goto v686;
    env = stack[-6];
    fn = elt(env, 10); /* to */
    v674 = (*qfn2(fn))(qenv(fn), stack[0], v676);
    nil = C_nil;
    if (exception_pending()) goto v686;
    env = stack[-6];
    v676 = (Lisp_Object)17; /* 1 */
    v676 = cons(v674, v676);
    nil = C_nil;
    if (exception_pending()) goto v686;
    env = stack[-6];
    v674 = ncons(v676);
    nil = C_nil;
    if (exception_pending()) goto v686;
    env = stack[-6];
    v676 = (Lisp_Object)17; /* 1 */
    v674 = cons(v674, v676);
    nil = C_nil;
    if (exception_pending()) goto v686;
    env = stack[-6];
    v676 = stack[-2];
    fn = elt(env, 7); /* multsq */
    v676 = (*qfn2(fn))(qenv(fn), v674, v676);
    nil = C_nil;
    if (exception_pending()) goto v686;
    env = stack[-6];
    stack[-2] = v676;
    goto v184;

v46:
    v676 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 18); /* sizchk */
    v676 = (*qfn2(fn))(qenv(fn), v674, v676);
    nil = C_nil;
    if (exception_pending()) goto v686;
    env = stack[-6];
    goto v38;
/* error exit handlers */
v278:
    env = stack[-6];
    qvalue(elt(env, 3)) = stack[-4]; /* subfg!* */
    popv(7);
    return nil;
v686:
    popv(7);
    return nil;
}



/* Code for mchcomb */

static Lisp_Object MS_CDECL CC_mchcomb(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v16,
                         Lisp_Object v63, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v493, v301, v299, v483, v464;
    Lisp_Object fn;
    argcheck(nargs, 3, "mchcomb");
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
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-6] = v63;
    stack[-7] = v16;
    stack[-8] = v0;
/* end of prologue */
    v493 = stack[-8];
    stack[0] = Llength(nil, v493);
    nil = C_nil;
    if (exception_pending()) goto v428;
    env = stack[-10];
    v493 = stack[-7];
    v493 = Llength(nil, v493);
    nil = C_nil;
    if (exception_pending()) goto v428;
    env = stack[-10];
    v493 = difference2(stack[0], v493);
    nil = C_nil;
    if (exception_pending()) goto v428;
    env = stack[-10];
    v493 = add1(v493);
    nil = C_nil;
    if (exception_pending()) goto v428;
    env = stack[-10];
    stack[0] = v493;
    v301 = stack[0];
    v493 = (Lisp_Object)17; /* 1 */
    v493 = (Lisp_Object)lessp2(v301, v493);
    nil = C_nil;
    if (exception_pending()) goto v428;
    v493 = v493 ? lisp_true : nil;
    env = stack[-10];
    if (v493 == nil) goto v99;
    v493 = nil;
    { popv(11); return onevalue(v493); }

v99:
    v301 = stack[0];
    v493 = (Lisp_Object)17; /* 1 */
    if (v301 == v493) goto v36;
    v301 = qvalue(elt(env, 1)); /* frlis!* */
    v493 = stack[-7];
    fn = elt(env, 3); /* smemqlp */
    v493 = (*qfn2(fn))(qenv(fn), v301, v493);
    nil = C_nil;
    if (exception_pending()) goto v428;
    env = stack[-10];
    if (v493 == nil) goto v34;
    v301 = stack[-8];
    v493 = stack[0];
    fn = elt(env, 4); /* comb */
    v493 = (*qfn2(fn))(qenv(fn), v301, v493);
    nil = C_nil;
    if (exception_pending()) goto v428;
    env = stack[-10];
    stack[-9] = v493;
    goto v66;

v66:
    v493 = stack[-9];
    if (v493 == nil) goto v60;
    v493 = stack[-9];
    v493 = qcar(v493);
    stack[-2] = v493;
    v493 = qvalue(elt(env, 2)); /* ncmp!* */
    if (v493 == nil) goto v236;
    v464 = stack[-2];
    v483 = stack[-8];
    v299 = nil;
    v301 = nil;
    v493 = nil;
    fn = elt(env, 5); /* mchcomb2 */
    v493 = (*qfnn(fn))(qenv(fn), 5, v464, v483, v299, v301, v493);
    nil = C_nil;
    if (exception_pending()) goto v428;
    env = stack[-10];
    stack[0] = v493;
    v493 = stack[0];
    if (v493 == nil) goto v147;
    v299 = stack[-6];
    v301 = stack[-2];
    v493 = stack[0];
    v493 = qcar(v493);
    stack[-1] = acons(v299, v301, v493);
    nil = C_nil;
    if (exception_pending()) goto v428;
    env = stack[-10];
    v493 = stack[0];
    v493 = qcdr(v493);
    if (v493 == nil) goto v212;
    v493 = stack[-7];
    v493 = Lreverse(nil, v493);
    nil = C_nil;
    if (exception_pending()) goto v428;
    env = stack[-10];
    v301 = v493;
    goto v76;

v76:
    v493 = stack[-6];
    fn = elt(env, 6); /* mchsarg */
    v493 = (*qfnn(fn))(qenv(fn), 3, stack[-1], v301, v493);
    nil = C_nil;
    if (exception_pending()) goto v428;
    env = stack[-10];
    goto v86;

v86:
    stack[-5] = v493;
    v493 = stack[-5];
    fn = elt(env, 7); /* lastpair */
    v493 = (*qfn1(fn))(qenv(fn), v493);
    nil = C_nil;
    if (exception_pending()) goto v428;
    env = stack[-10];
    stack[-4] = v493;
    v493 = stack[-9];
    v493 = qcdr(v493);
    stack[-9] = v493;
    v493 = stack[-4];
    if (!consp(v493)) goto v66;
    else goto v70;

v70:
    v493 = stack[-9];
    if (v493 == nil) { Lisp_Object res = stack[-5]; popv(11); return onevalue(res); }
    stack[-3] = stack[-4];
    v493 = stack[-9];
    v493 = qcar(v493);
    stack[-2] = v493;
    v493 = qvalue(elt(env, 2)); /* ncmp!* */
    if (v493 == nil) goto v316;
    v464 = stack[-2];
    v483 = stack[-8];
    v299 = nil;
    v301 = nil;
    v493 = nil;
    fn = elt(env, 5); /* mchcomb2 */
    v493 = (*qfnn(fn))(qenv(fn), 5, v464, v483, v299, v301, v493);
    nil = C_nil;
    if (exception_pending()) goto v428;
    env = stack[-10];
    stack[0] = v493;
    v493 = stack[0];
    if (v493 == nil) goto v306;
    v299 = stack[-6];
    v301 = stack[-2];
    v493 = stack[0];
    v493 = qcar(v493);
    stack[-1] = acons(v299, v301, v493);
    nil = C_nil;
    if (exception_pending()) goto v428;
    env = stack[-10];
    v493 = stack[0];
    v493 = qcdr(v493);
    if (v493 == nil) goto v244;
    v493 = stack[-7];
    v493 = Lreverse(nil, v493);
    nil = C_nil;
    if (exception_pending()) goto v428;
    env = stack[-10];
    v301 = v493;
    goto v466;

v466:
    v493 = stack[-6];
    fn = elt(env, 6); /* mchsarg */
    v493 = (*qfnn(fn))(qenv(fn), 3, stack[-1], v301, v493);
    nil = C_nil;
    if (exception_pending()) goto v428;
    env = stack[-10];
    goto v181;

v181:
    v493 = Lrplacd(nil, stack[-3], v493);
    nil = C_nil;
    if (exception_pending()) goto v428;
    env = stack[-10];
    v493 = stack[-4];
    fn = elt(env, 7); /* lastpair */
    v493 = (*qfn1(fn))(qenv(fn), v493);
    nil = C_nil;
    if (exception_pending()) goto v428;
    env = stack[-10];
    stack[-4] = v493;
    v493 = stack[-9];
    v493 = qcdr(v493);
    stack[-9] = v493;
    goto v70;

v244:
    v493 = stack[-7];
    v301 = v493;
    goto v466;

v306:
    v493 = nil;
    goto v181;

v316:
    stack[-1] = stack[-6];
    stack[0] = stack[-2];
    v301 = stack[-8];
    v493 = stack[-2];
    fn = elt(env, 8); /* setdiff */
    v493 = (*qfn2(fn))(qenv(fn), v301, v493);
    nil = C_nil;
    if (exception_pending()) goto v428;
    env = stack[-10];
    v299 = acons(stack[-1], stack[0], v493);
    nil = C_nil;
    if (exception_pending()) goto v428;
    env = stack[-10];
    v301 = stack[-7];
    v493 = stack[-6];
    fn = elt(env, 6); /* mchsarg */
    v493 = (*qfnn(fn))(qenv(fn), 3, v299, v301, v493);
    nil = C_nil;
    if (exception_pending()) goto v428;
    env = stack[-10];
    goto v181;

v212:
    v493 = stack[-7];
    v301 = v493;
    goto v76;

v147:
    v493 = nil;
    goto v86;

v236:
    stack[-1] = stack[-6];
    stack[0] = stack[-2];
    v301 = stack[-8];
    v493 = stack[-2];
    fn = elt(env, 8); /* setdiff */
    v493 = (*qfn2(fn))(qenv(fn), v301, v493);
    nil = C_nil;
    if (exception_pending()) goto v428;
    env = stack[-10];
    v299 = acons(stack[-1], stack[0], v493);
    nil = C_nil;
    if (exception_pending()) goto v428;
    env = stack[-10];
    v301 = stack[-7];
    v493 = stack[-6];
    fn = elt(env, 6); /* mchsarg */
    v493 = (*qfnn(fn))(qenv(fn), 3, v299, v301, v493);
    nil = C_nil;
    if (exception_pending()) goto v428;
    env = stack[-10];
    goto v86;

v60:
    v493 = nil;
    { popv(11); return onevalue(v493); }

v34:
    v493 = nil;
    { popv(11); return onevalue(v493); }

v36:
    v299 = stack[-8];
    v301 = stack[-7];
    v493 = stack[-6];
    {
        popv(11);
        fn = elt(env, 6); /* mchsarg */
        return (*qfnn(fn))(qenv(fn), 3, v299, v301, v493);
    }
/* error exit handlers */
v428:
    popv(11);
    return nil;
}



/* Code for quotematrix */

static Lisp_Object CC_quotematrix(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object v9;
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v9 = v0;
/* end of prologue */
    v9 = elt(env, 1); /* matrix */
    return onevalue(v9);
}



/* Code for mkrn */

static Lisp_Object CC_mkrn(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v100, v150;
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

v8:
    v150 = stack[-1];
    v100 = (Lisp_Object)1; /* 0 */
    v100 = (Lisp_Object)lessp2(v150, v100);
    nil = C_nil;
    if (exception_pending()) goto v68;
    v100 = v100 ? lisp_true : nil;
    env = stack[-4];
    if (v100 == nil) goto v29;
    v100 = stack[-2];
    v100 = negate(v100);
    nil = C_nil;
    if (exception_pending()) goto v68;
    env = stack[-4];
    stack[-2] = v100;
    v100 = stack[-1];
    v100 = negate(v100);
    nil = C_nil;
    if (exception_pending()) goto v68;
    env = stack[-4];
    stack[-1] = v100;
    goto v8;

v29:
    v150 = stack[-2];
    v100 = stack[-1];
    v100 = Lgcd(nil, v150, v100);
    nil = C_nil;
    if (exception_pending()) goto v68;
    env = stack[-4];
    stack[-3] = v100;
    stack[0] = elt(env, 1); /* !:rn!: */
    v150 = stack[-2];
    v100 = stack[-3];
    stack[-2] = quot2(v150, v100);
    nil = C_nil;
    if (exception_pending()) goto v68;
    env = stack[-4];
    v150 = stack[-1];
    v100 = stack[-3];
    v100 = quot2(v150, v100);
    nil = C_nil;
    if (exception_pending()) goto v68;
    {
        Lisp_Object v56 = stack[0];
        Lisp_Object v54 = stack[-2];
        popv(5);
        return list2star(v56, v54, v100);
    }
/* error exit handlers */
v68:
    popv(5);
    return nil;
}



/* Code for kahane */

static Lisp_Object MS_CDECL CC_kahane(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v16,
                         Lisp_Object v63, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v280, v317, v677;
    Lisp_Object fn;
    argcheck(nargs, 3, "kahane");
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
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-9] = v63;
    stack[0] = v16;
    stack[-10] = v0;
/* end of prologue */
    stack[-11] = nil;
    stack[-1] = nil;
    stack[-8] = nil;
    stack[-7] = nil;
    stack[-6] = nil;
    stack[-4] = nil;
    v280 = (Lisp_Object)1; /* 0 */
    stack[-3] = v280;
    v317 = stack[-10];
    v280 = elt(env, 1); /* a */
    if (!consp(v317)) goto v13;
    v317 = qcar(v317);
    if (!(v317 == v280)) goto v13;

v67:
    v317 = stack[-7];
    v280 = stack[-10];
    v280 = qcar(v280);
    fn = elt(env, 5); /* aconc!* */
    v280 = (*qfn2(fn))(qenv(fn), v317, v280);
    nil = C_nil;
    if (exception_pending()) goto v674;
    env = stack[-12];
    stack[-7] = v280;
    goto v26;

v26:
    v280 = stack[-10];
    v280 = qcdr(v280);
    stack[-10] = v280;
    goto v13;

v13:
    v280 = stack[-11];
    v280 = (v280 == nil ? lisp_true : nil);
    stack[-11] = v280;
    v280 = stack[-10];
    if (v280 == nil) goto v237;
    v280 = stack[-10];
    v317 = qcar(v280);
    v280 = stack[0];
    v280 = Lmember(nil, v317, v280);
    if (v280 == nil) goto v67;
    v280 = stack[-10];
    v317 = qcar(v280);
    v280 = stack[-11];
    v280 = cons(v317, v280);
    nil = C_nil;
    if (exception_pending()) goto v674;
    env = stack[-12];
    stack[-5] = v280;
    stack[-2] = stack[-6];
    v317 = stack[-5];
    v280 = stack[-7];
    v317 = cons(v317, v280);
    nil = C_nil;
    if (exception_pending()) goto v674;
    env = stack[-12];
    v280 = stack[-4];
    v280 = acons(stack[-2], v317, v280);
    nil = C_nil;
    if (exception_pending()) goto v674;
    env = stack[-12];
    stack[-4] = v280;
    v280 = stack[-5];
    stack[-6] = v280;
    v280 = nil;
    stack[-7] = v280;
    v280 = stack[-3];
    v280 = add1(v280);
    nil = C_nil;
    if (exception_pending()) goto v674;
    env = stack[-12];
    stack[-3] = v280;
    goto v26;

v237:
    stack[0] = nil;
    v317 = stack[-6];
    v280 = stack[-7];
    v317 = cons(v317, v280);
    nil = C_nil;
    if (exception_pending()) goto v674;
    env = stack[-12];
    v280 = stack[-4];
    v280 = acons(stack[0], v317, v280);
    nil = C_nil;
    if (exception_pending()) goto v674;
    env = stack[-12];
    stack[-4] = v280;
    v280 = (Lisp_Object)17; /* 1 */
    stack[-2] = v280;
    goto v38;

v38:
    v280 = stack[-4];
    if (v280 == nil) goto v688;
    v280 = stack[-4];
    v280 = qcar(v280);
    v280 = qcar(v280);
    stack[-10] = v280;
    v280 = stack[-4];
    v280 = qcar(v280);
    v280 = qcdr(v280);
    v280 = qcar(v280);
    stack[-6] = v280;
    v280 = stack[-4];
    v280 = qcar(v280);
    v280 = qcdr(v280);
    v280 = qcdr(v280);
    stack[-7] = v280;
    v280 = stack[-4];
    v280 = qcdr(v280);
    stack[-4] = v280;
    v280 = stack[-2];
    v280 = add1(v280);
    nil = C_nil;
    if (exception_pending()) goto v674;
    env = stack[-12];
    stack[-2] = v280;
    v280 = stack[-10];
    if (v280 == nil) goto v108;
    v280 = stack[-10];
    v317 = qcar(v280);
    v280 = stack[-6];
    v280 = qcar(v280);
    if (!(v317 == v280)) goto v213;
    v317 = stack[-6];
    v280 = stack[-10];
    v280 = qcdr(v280);
    fn = elt(env, 6); /* exc */
    v280 = (*qfn2(fn))(qenv(fn), v317, v280);
    nil = C_nil;
    if (exception_pending()) goto v674;
    env = stack[-12];
    if (!(v280 == nil)) goto v17;

v213:
    v280 = stack[-7];
    v280 = Lreverse(nil, v280);
    nil = C_nil;
    if (exception_pending()) goto v674;
    env = stack[-12];
    stack[-7] = v280;
    v280 = lisp_true;
    stack[-1] = v280;
    goto v108;

v108:
    v317 = stack[-6];
    v280 = stack[-1];
    fn = elt(env, 6); /* exc */
    v280 = (*qfn2(fn))(qenv(fn), v317, v280);
    nil = C_nil;
    if (exception_pending()) goto v674;
    env = stack[-12];
    v280 = (v280 == nil ? lisp_true : nil);
    stack[-11] = v280;
    v280 = stack[-6];
    v280 = qcar(v280);
    stack[-6] = v280;
    v280 = nil;
    stack[-5] = v280;
    goto v47;

v47:
    v280 = stack[-4];
    if (v280 == nil) goto v199;
    v317 = stack[-6];
    v280 = stack[-4];
    v280 = qcar(v280);
    v280 = qcdr(v280);
    v280 = qcar(v280);
    stack[0] = v280;
    v280 = qcar(v280);
    if (!(v317 == v280)) goto v172;
    v317 = stack[0];
    v280 = stack[-11];
    fn = elt(env, 6); /* exc */
    v280 = (*qfn2(fn))(qenv(fn), v317, v280);
    nil = C_nil;
    if (exception_pending()) goto v674;
    env = stack[-12];
    if (!(v280 == nil)) goto v172;
    v280 = stack[-4];
    v280 = qcar(v280);
    v280 = qcar(v280);
    stack[-6] = v280;
    v280 = stack[-4];
    v280 = qcar(v280);
    v280 = qcdr(v280);
    v317 = qcdr(v280);
    v280 = stack[-7];
    v280 = Lappend(nil, v317, v280);
    nil = C_nil;
    if (exception_pending()) goto v674;
    env = stack[-12];
    stack[-7] = v280;
    v280 = nil;
    stack[-1] = v280;
    goto v679;

v679:
    v317 = stack[-5];
    v280 = stack[-4];
    v280 = qcdr(v280);
    fn = elt(env, 7); /* appr */
    v280 = (*qfn2(fn))(qenv(fn), v317, v280);
    nil = C_nil;
    if (exception_pending()) goto v674;
    env = stack[-12];
    stack[-4] = v280;
    v280 = stack[-6];
    if (v280 == nil) goto v420;
    v317 = stack[-10];
    v280 = stack[-6];
    v280 = qcar(v280);
    if (!consp(v317)) goto v108;
    v317 = qcar(v317);
    if (!(v317 == v280)) goto v108;

v17:
    v280 = stack[-7];
    if (v280 == nil) goto v689;
    v280 = stack[-10];
    v280 = qcdr(v280);
    if (v280 == nil) goto v689;
    v280 = stack[-7];
    v317 = qcdr(v280);
    v280 = stack[-7];
    v280 = qcar(v280);
    fn = elt(env, 5); /* aconc!* */
    v280 = (*qfn2(fn))(qenv(fn), v317, v280);
    nil = C_nil;
    if (exception_pending()) goto v674;
    env = stack[-12];
    stack[-7] = v280;
    goto v689;

v689:
    v677 = stack[-7];
    v317 = stack[-9];
    v280 = nil;
    fn = elt(env, 8); /* brace */
    v317 = (*qfnn(fn))(qenv(fn), 3, v677, v317, v280);
    nil = C_nil;
    if (exception_pending()) goto v674;
    env = stack[-12];
    v280 = stack[-8];
    fn = elt(env, 9); /* multf */
    v280 = (*qfn2(fn))(qenv(fn), v317, v280);
    nil = C_nil;
    if (exception_pending()) goto v674;
    env = stack[-12];
    stack[-8] = v280;
    goto v38;

v420:
    v677 = elt(env, 4); /* g */
    v317 = stack[-9];
    v280 = stack[-7];
    v280 = list2star(v677, v317, v280);
    nil = C_nil;
    if (exception_pending()) goto v674;
    env = stack[-12];
    fn = elt(env, 10); /* mksf */
    v280 = (*qfn1(fn))(qenv(fn), v280);
    nil = C_nil;
    if (exception_pending()) goto v674;
    env = stack[-12];
    stack[-8] = v280;
    v280 = stack[-4];
    v280 = Lreverse(nil, v280);
    nil = C_nil;
    if (exception_pending()) goto v674;
    env = stack[-12];
    stack[-4] = v280;
    v317 = stack[-3];
    v280 = (Lisp_Object)33; /* 2 */
    v280 = quot2(v317, v280);
    nil = C_nil;
    if (exception_pending()) goto v674;
    env = stack[-12];
    stack[-3] = v280;
    goto v38;

v172:
    v317 = stack[-6];
    v280 = stack[-4];
    v280 = qcar(v280);
    v280 = qcar(v280);
    stack[0] = v280;
    v280 = qcar(v280);
    if (!(v317 == v280)) goto v328;
    v317 = stack[0];
    v280 = stack[-11];
    fn = elt(env, 6); /* exc */
    v280 = (*qfn2(fn))(qenv(fn), v317, v280);
    nil = C_nil;
    if (exception_pending()) goto v674;
    env = stack[-12];
    if (v280 == nil) goto v328;
    v280 = stack[-4];
    v280 = qcar(v280);
    v280 = qcdr(v280);
    v280 = qcar(v280);
    stack[-6] = v280;
    v280 = stack[-4];
    v280 = qcar(v280);
    v280 = qcdr(v280);
    v317 = qcdr(v280);
    v280 = stack[-7];
    fn = elt(env, 7); /* appr */
    v280 = (*qfn2(fn))(qenv(fn), v317, v280);
    nil = C_nil;
    if (exception_pending()) goto v674;
    env = stack[-12];
    stack[-7] = v280;
    v280 = lisp_true;
    stack[-1] = v280;
    goto v679;

v328:
    v280 = stack[-4];
    v317 = qcar(v280);
    v280 = stack[-5];
    v280 = cons(v317, v280);
    nil = C_nil;
    if (exception_pending()) goto v674;
    env = stack[-12];
    stack[-5] = v280;
    v280 = stack[-4];
    v280 = qcdr(v280);
    stack[-4] = v280;
    goto v47;

v199:
    stack[-1] = elt(env, 2); /* hephys */
    stack[0] = (Lisp_Object)177; /* 11 */
    v317 = elt(env, 3); /* "Unmatched index" */
    v280 = stack[-5];
    if (v280 == nil) goto v348;
    v280 = stack[-5];
    v280 = qcar(v280);
    v280 = qcdr(v280);
    v280 = qcar(v280);
    if (!consp(v280)) goto v224;
    v280 = stack[-5];
    v280 = qcar(v280);
    v280 = qcdr(v280);
    v280 = qcar(v280);
    goto v351;

v351:
    v280 = cons(v317, v280);
    nil = C_nil;
    if (exception_pending()) goto v674;
    env = stack[-12];
    fn = elt(env, 11); /* rerror */
    v280 = (*qfnn(fn))(qenv(fn), 3, stack[-1], stack[0], v280);
    nil = C_nil;
    if (exception_pending()) goto v674;
    env = stack[-12];
    goto v328;

v224:
    v280 = stack[-5];
    v280 = qcar(v280);
    v280 = qcar(v280);
    if (!consp(v280)) goto v470;
    v280 = stack[-5];
    v280 = qcar(v280);
    v280 = qcar(v280);
    goto v351;

v470:
    v280 = nil;
    goto v351;

v348:
    v280 = nil;
    goto v351;

v688:
    v317 = (Lisp_Object)33; /* 2 */
    v280 = stack[-3];
    v280 = Lexpt(nil, v317, v280);
    nil = C_nil;
    if (exception_pending()) goto v674;
    env = stack[-12];
    stack[-10] = v280;
    v317 = stack[-3];
    v280 = stack[-2];
    v280 = difference2(v317, v280);
    nil = C_nil;
    if (exception_pending()) goto v674;
    env = stack[-12];
    v280 = Levenp(nil, v280);
    env = stack[-12];
    if (!(v280 == nil)) goto v285;
    v280 = stack[-10];
    v280 = negate(v280);
    nil = C_nil;
    if (exception_pending()) goto v674;
    env = stack[-12];
    stack[-10] = v280;
    goto v285;

v285:
    v317 = stack[-10];
    v280 = stack[-8];
    {
        popv(13);
        fn = elt(env, 12); /* multd!* */
        return (*qfn2(fn))(qenv(fn), v317, v280);
    }
/* error exit handlers */
v674:
    popv(13);
    return nil;
}



/* Code for exptsq */

static Lisp_Object CC_exptsq(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v678, v490, v431;
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
    v490 = stack[-1];
    v678 = (Lisp_Object)17; /* 1 */
    if (v490 == v678) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v490 = stack[-1];
    v678 = (Lisp_Object)1; /* 0 */
    if (v490 == v678) goto v27;
    v678 = stack[-2];
    v678 = qcar(v678);
    if (v678 == nil) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v490 = stack[-1];
    v678 = (Lisp_Object)1; /* 0 */
    v678 = (Lisp_Object)lessp2(v490, v678);
    nil = C_nil;
    if (exception_pending()) goto v346;
    v678 = v678 ? lisp_true : nil;
    env = stack[-4];
    if (v678 == nil) goto v134;
    v678 = stack[-2];
    fn = elt(env, 5); /* mk!*sq */
    v490 = (*qfn1(fn))(qenv(fn), v678);
    nil = C_nil;
    if (exception_pending()) goto v346;
    env = stack[-4];
    v678 = stack[-1];
    v678 = list2(v490, v678);
    nil = C_nil;
    if (exception_pending()) goto v346;
    env = stack[-4];
    {
        popv(5);
        fn = elt(env, 6); /* simpexpt */
        return (*qfn1(fn))(qenv(fn), v678);
    }

v134:
    v678 = qvalue(elt(env, 3)); /* !*exp */
    if (v678 == nil) goto v104;
    v678 = stack[-2];
    fn = elt(env, 7); /* kernp */
    v678 = (*qfn1(fn))(qenv(fn), v678);
    nil = C_nil;
    if (exception_pending()) goto v346;
    env = stack[-4];
    if (v678 == nil) goto v136;
    v678 = stack[-2];
    v678 = qcar(v678);
    v678 = qcar(v678);
    v678 = qcar(v678);
    v490 = qcar(v678);
    v678 = stack[-1];
    {
        popv(5);
        fn = elt(env, 8); /* mksq */
        return (*qfn2(fn))(qenv(fn), v490, v678);
    }

v136:
    v678 = stack[-2];
    v490 = qcdr(v678);
    v678 = (Lisp_Object)17; /* 1 */
    if (v490 == v678) goto v115;
    v678 = stack[-2];
    v678 = qcar(v678);
    if (!consp(v678)) goto v187;
    v678 = stack[-2];
    v678 = qcar(v678);
    v678 = qcar(v678);
    if (!consp(v678)) goto v187;
    v678 = stack[-2];
    stack[-3] = v678;
    goto v509;

v509:
    v678 = stack[-1];
    v490 = sub1(v678);
    nil = C_nil;
    if (exception_pending()) goto v346;
    env = stack[-4];
    stack[-1] = v490;
    v678 = (Lisp_Object)1; /* 0 */
    v678 = (Lisp_Object)greaterp2(v490, v678);
    nil = C_nil;
    if (exception_pending()) goto v346;
    v678 = v678 ? lisp_true : nil;
    env = stack[-4];
    if (v678 == nil) goto v181;
    v678 = stack[-2];
    v490 = qcar(v678);
    v678 = stack[-3];
    v678 = qcar(v678);
    fn = elt(env, 9); /* multf */
    stack[0] = (*qfn2(fn))(qenv(fn), v490, v678);
    nil = C_nil;
    if (exception_pending()) goto v346;
    env = stack[-4];
    v678 = stack[-2];
    v490 = qcdr(v678);
    v678 = stack[-3];
    v678 = qcdr(v678);
    fn = elt(env, 9); /* multf */
    v678 = (*qfn2(fn))(qenv(fn), v490, v678);
    nil = C_nil;
    if (exception_pending()) goto v346;
    env = stack[-4];
    v678 = cons(stack[0], v678);
    nil = C_nil;
    if (exception_pending()) goto v346;
    env = stack[-4];
    stack[-3] = v678;
    goto v509;

v181:
    v678 = stack[-3];
    fn = elt(env, 10); /* canonsq */
    v678 = (*qfn1(fn))(qenv(fn), v678);
    nil = C_nil;
    if (exception_pending()) goto v346;
    env = stack[-4];
    stack[-3] = v678;
    goto v45;

v45:
    v678 = stack[-3];
    v678 = qcdr(v678);
    if (!(v678 == nil)) { Lisp_Object res = stack[-3]; popv(5); return onevalue(res); }
    v431 = elt(env, 1); /* poly */
    v490 = (Lisp_Object)1617; /* 101 */
    v678 = elt(env, 4); /* "Zero divisor" */
    fn = elt(env, 11); /* rerror */
    v678 = (*qfnn(fn))(qenv(fn), 3, v431, v490, v678);
    nil = C_nil;
    if (exception_pending()) goto v346;
    { Lisp_Object res = stack[-3]; popv(5); return onevalue(res); }

v187:
    v678 = stack[-2];
    v490 = qcar(v678);
    v678 = stack[-1];
    fn = elt(env, 12); /* !:expt */
    v490 = (*qfn2(fn))(qenv(fn), v490, v678);
    nil = C_nil;
    if (exception_pending()) goto v346;
    env = stack[-4];
    v678 = (Lisp_Object)17; /* 1 */
    stack[-3] = cons(v490, v678);
    nil = C_nil;
    if (exception_pending()) goto v346;
    env = stack[-4];
    stack[0] = (Lisp_Object)17; /* 1 */
    v678 = stack[-2];
    v490 = qcdr(v678);
    v678 = stack[-1];
    fn = elt(env, 13); /* exptf */
    v678 = (*qfn2(fn))(qenv(fn), v490, v678);
    nil = C_nil;
    if (exception_pending()) goto v346;
    env = stack[-4];
    v678 = cons(stack[0], v678);
    nil = C_nil;
    if (exception_pending()) goto v346;
    env = stack[-4];
    fn = elt(env, 14); /* multsq */
    v678 = (*qfn2(fn))(qenv(fn), stack[-3], v678);
    nil = C_nil;
    if (exception_pending()) goto v346;
    env = stack[-4];
    stack[-3] = v678;
    goto v45;

v115:
    v678 = stack[-2];
    v490 = qcar(v678);
    v678 = stack[-1];
    fn = elt(env, 13); /* exptf */
    v490 = (*qfn2(fn))(qenv(fn), v490, v678);
    nil = C_nil;
    if (exception_pending()) goto v346;
    v678 = (Lisp_Object)17; /* 1 */
    popv(5);
    return cons(v490, v678);

v104:
    v678 = stack[-2];
    v490 = qcar(v678);
    v678 = stack[-1];
    fn = elt(env, 15); /* mksfpf */
    stack[0] = (*qfn2(fn))(qenv(fn), v490, v678);
    nil = C_nil;
    if (exception_pending()) goto v346;
    env = stack[-4];
    v678 = stack[-2];
    v490 = qcdr(v678);
    v678 = stack[-1];
    fn = elt(env, 15); /* mksfpf */
    v678 = (*qfn2(fn))(qenv(fn), v490, v678);
    nil = C_nil;
    if (exception_pending()) goto v346;
    {
        Lisp_Object v507 = stack[0];
        popv(5);
        return cons(v507, v678);
    }

v27:
    v678 = stack[-2];
    v678 = qcar(v678);
    if (v678 == nil) goto v99;
    v490 = (Lisp_Object)17; /* 1 */
    v678 = (Lisp_Object)17; /* 1 */
    popv(5);
    return cons(v490, v678);

v99:
    v431 = elt(env, 1); /* poly */
    v490 = (Lisp_Object)65; /* 4 */
    v678 = elt(env, 2); /* " 0**0 formed" */
    {
        popv(5);
        fn = elt(env, 11); /* rerror */
        return (*qfnn(fn))(qenv(fn), 3, v431, v490, v678);
    }
/* error exit handlers */
v346:
    popv(5);
    return nil;
}



/* Code for dfn_prop */

static Lisp_Object CC_dfn_prop(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v50, v52, v193;
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
    v50 = v0;
/* end of prologue */
    v50 = qcdr(v50);
    v50 = Llength(nil, v50);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[0];
    v193 = v50;
    v52 = v193;
    v50 = (Lisp_Object)17; /* 1 */
    if (v52 == v50) goto v5;
    v52 = v193;
    v50 = (Lisp_Object)33; /* 2 */
    if (v52 == v50) goto v27;
    v52 = v193;
    v50 = (Lisp_Object)49; /* 3 */
    if (v52 == v50) goto v19;
    v50 = elt(env, 1); /* dfn */
    v52 = v193;
    {
        popv(1);
        fn = elt(env, 4); /* mkid */
        return (*qfn2(fn))(qenv(fn), v50, v52);
    }

v19:
    v50 = elt(env, 3); /* dfn3 */
    { popv(1); return onevalue(v50); }

v27:
    v50 = elt(env, 2); /* dfn2 */
    { popv(1); return onevalue(v50); }

v5:
    v50 = elt(env, 1); /* dfn */
    { popv(1); return onevalue(v50); }
/* error exit handlers */
v35:
    popv(1);
    return nil;
}



/* Code for spurr */

static Lisp_Object MS_CDECL CC_spurr(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v16,
                         Lisp_Object v63, Lisp_Object v9, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v205, v176, v177, v254;
    Lisp_Object fn;
    argcheck(nargs, 4, "spurr");
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
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-8] = v9;
    stack[-9] = v63;
    stack[-10] = v16;
    stack[0] = v0;
/* end of prologue */
    stack[-5] = nil;
    goto v2;

v2:
    v205 = stack[0];
    if (v205 == nil) goto v25;
    v205 = stack[0];
    v176 = qcar(v205);
    v205 = stack[0];
    v205 = qcdr(v205);
    v205 = Lmember(nil, v176, v205);
    if (v205 == nil) goto v14;
    v205 = stack[0];
    v205 = qcar(v205);
    stack[-7] = v205;
    v205 = stack[0];
    v205 = qcdr(v205);
    stack[-6] = v205;
    v205 = stack[-6];
    stack[-11] = v205;
    v205 = (Lisp_Object)17; /* 1 */
    stack[-4] = v205;
    goto v83;

v83:
    v176 = stack[-7];
    v205 = stack[-11];
    v205 = qcar(v205);
    if (v176 == v205) goto v135;
    stack[0] = elt(env, 3); /* cons */
    v176 = stack[-7];
    v205 = stack[-11];
    v205 = qcar(v205);
    fn = elt(env, 4); /* ord2 */
    v205 = (*qfn2(fn))(qenv(fn), v176, v205);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-12];
    v205 = cons(stack[0], v205);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-12];
    fn = elt(env, 5); /* mksf */
    v205 = (*qfn1(fn))(qenv(fn), v205);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-12];
    v176 = v205;
    v205 = v176;
    if (v205 == nil) goto v126;
    stack[-3] = v176;
    v176 = stack[-6];
    v205 = stack[-4];
    fn = elt(env, 6); /* remove */
    stack[-2] = (*qfn2(fn))(qenv(fn), v176, v205);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-12];
    stack[-1] = stack[-10];
    stack[0] = stack[-9];
    v176 = (Lisp_Object)33; /* 2 */
    v205 = stack[-8];
    v205 = times2(v176, v205);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-12];
    v205 = CC_spurr(env, 4, stack[-2], stack[-1], stack[0], v205);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-12];
    fn = elt(env, 7); /* mkf */
    v176 = (*qfn2(fn))(qenv(fn), stack[-3], v205);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-12];
    v205 = stack[-5];
    fn = elt(env, 8); /* addf */
    v205 = (*qfn2(fn))(qenv(fn), v176, v205);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-12];
    stack[-5] = v205;
    goto v126;

v126:
    v205 = stack[-11];
    v205 = qcdr(v205);
    stack[-11] = v205;
    v205 = stack[-8];
    v205 = negate(v205);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-12];
    stack[-8] = v205;
    v205 = stack[-4];
    v205 = add1(v205);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-12];
    stack[-4] = v205;
    goto v83;

v135:
    stack[0] = elt(env, 3); /* cons */
    v176 = stack[-7];
    v205 = stack[-7];
    fn = elt(env, 4); /* ord2 */
    v205 = (*qfn2(fn))(qenv(fn), v176, v205);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-12];
    v205 = cons(stack[0], v205);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-12];
    fn = elt(env, 5); /* mksf */
    v205 = (*qfn1(fn))(qenv(fn), v205);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-12];
    stack[-11] = v205;
    if (v205 == nil) { Lisp_Object res = stack[-5]; popv(13); return onevalue(res); }
    stack[0] = stack[-11];
    v176 = stack[-7];
    v205 = stack[-6];
    v254 = Ldelete(nil, v176, v205);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-12];
    v177 = stack[-10];
    v176 = stack[-9];
    v205 = stack[-8];
    v205 = CC_spurr(env, 4, v254, v177, v176, v205);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-12];
    fn = elt(env, 7); /* mkf */
    v176 = (*qfn2(fn))(qenv(fn), stack[0], v205);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-12];
    v205 = stack[-5];
    {
        popv(13);
        fn = elt(env, 8); /* addf */
        return (*qfn2(fn))(qenv(fn), v176, v205);
    }

v14:
    v205 = stack[0];
    v176 = qcar(v205);
    v205 = stack[-9];
    v205 = cons(v176, v205);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-12];
    stack[-9] = v205;
    v205 = stack[0];
    v205 = qcdr(v205);
    stack[0] = v205;
    goto v2;

v25:
    v205 = stack[-9];
    if (v205 == nil) { Lisp_Object res = stack[-8]; popv(13); return onevalue(res); }
    v176 = stack[-10];
    v205 = elt(env, 1); /* nospur */
    v205 = Lflagp(nil, v176, v205);
    env = stack[-12];
    if (v205 == nil) goto v61;
    stack[0] = stack[-8];
    v177 = elt(env, 2); /* g */
    v176 = stack[-10];
    v205 = stack[-9];
    v205 = list2star(v177, v176, v205);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-12];
    fn = elt(env, 5); /* mksf */
    v205 = (*qfn1(fn))(qenv(fn), v205);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-12];
    {
        Lisp_Object v222 = stack[0];
        popv(13);
        fn = elt(env, 9); /* multd!* */
        return (*qfn2(fn))(qenv(fn), v222, v205);
    }

v61:
    stack[0] = stack[-8];
    v205 = stack[-9];
    fn = elt(env, 10); /* sprgen */
    v205 = (*qfn1(fn))(qenv(fn), v205);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-12];
    {
        Lisp_Object v546 = stack[0];
        popv(13);
        fn = elt(env, 9); /* multd!* */
        return (*qfn2(fn))(qenv(fn), v546, v205);
    }
/* error exit handlers */
v305:
    popv(13);
    return nil;
}



setup_type const u06_setup[] =
{
    {"nssimp",                  too_few_2,      CC_nssimp,     wrong_no_2},
    {"wtchk",                   too_few_2,      CC_wtchk,      wrong_no_2},
    {"mchkopt1",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_mchkopt1},
    {"gcdf2",                   too_few_2,      CC_gcdf2,      wrong_no_2},
    {"arglist_member",          too_few_2,      CC_arglist_member,wrong_no_2},
    {"mkvarg",                  too_few_2,      CC_mkvarg,     wrong_no_2},
    {"vmult1",                  too_few_2,      CC_vmult1,     wrong_no_2},
    {"simpiden",                CC_simpiden,    too_many_1,    wrong_no_1},
    {"condterpri",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_condterpri},
    {"prepreform",              CC_prepreform,  too_many_1,    wrong_no_1},
    {"revalx",                  CC_revalx,      too_many_1,    wrong_no_1},
    {"**a2s",                   too_few_2,      CC_HHa2s,      wrong_no_2},
    {"eofcheck",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_eofcheck},
    {"veval",                   too_few_2,      CC_veval,      wrong_no_2},
    {"remcomma",                CC_remcomma,    too_many_1,    wrong_no_1},
    {"add2inputbuf",            too_few_2,      CC_add2inputbuf,wrong_no_2},
    {"requote1",                CC_requote1,    too_many_1,    wrong_no_1},
    {"simpatom",                CC_simpatom,    too_many_1,    wrong_no_1},
    {"symbol",                  CC_symbol,      too_many_1,    wrong_no_1},
    {"subs3t",                  too_few_2,      CC_subs3t,     wrong_no_2},
    {"mchcomb",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_mchcomb},
    {"quotematrix",             CC_quotematrix, too_many_1,    wrong_no_1},
    {"mkrn",                    too_few_2,      CC_mkrn,       wrong_no_2},
    {"kahane",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_kahane},
    {"exptsq",                  too_few_2,      CC_exptsq,     wrong_no_2},
    {"dfn_prop",                CC_dfn_prop,    too_many_1,    wrong_no_1},
    {"spurr",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_spurr},
    {NULL, (one_args *)"u06", (two_args *)"792 500714 8439866", 0}
};

/* end of generated code */
