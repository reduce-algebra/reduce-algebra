
/* $srcdir/../csl-c\u05.c Machine generated C code */

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


/* Code for comfac */

static Lisp_Object CC_comfac(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v230, v468;
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
    stack[-2] = v0;
/* end of prologue */
    v468 = qvalue(elt(env, 1)); /* dmode!* */
    v230 = elt(env, 2); /* field */
    v230 = Lflagp(nil, v468, v230);
    env = stack[-4];
    if (v230 == nil) goto v5;
    v230 = stack[-2];
    fn = elt(env, 3); /* lnc */
    v468 = (*qfn1(fn))(qenv(fn), v230);
    nil = C_nil;
    if (exception_pending()) goto v76;
    env = stack[-4];
    stack[-3] = v468;
    v230 = (Lisp_Object)17; /* 1 */
    v230 = Lneq(nil, v468, v230);
    nil = C_nil;
    if (exception_pending()) goto v76;
    env = stack[-4];
    if (v230 == nil) goto v5;
    v230 = stack[-3];
    fn = elt(env, 4); /* !:recip */
    v468 = (*qfn1(fn))(qenv(fn), v230);
    nil = C_nil;
    if (exception_pending()) goto v76;
    env = stack[-4];
    v230 = stack[-2];
    fn = elt(env, 5); /* multd */
    v230 = (*qfn2(fn))(qenv(fn), v468, v230);
    nil = C_nil;
    if (exception_pending()) goto v76;
    env = stack[-4];
    stack[-2] = v230;
    goto v5;

v5:
    v230 = stack[-2];
    v230 = qcdr(v230);
    if (v230 == nil) goto v37;
    v230 = stack[-2];
    v230 = qcar(v230);
    v230 = qcdr(v230);
    stack[-3] = v230;
    v230 = stack[-2];
    v230 = qcar(v230);
    v230 = qcar(v230);
    v230 = qcar(v230);
    stack[-1] = v230;
    goto v12;

v12:
    v230 = stack[-2];
    v230 = qcdr(v230);
    stack[-2] = v230;
    v468 = stack[-2];
    v230 = stack[-1];
    fn = elt(env, 6); /* degr */
    v468 = (*qfn2(fn))(qenv(fn), v468, v230);
    nil = C_nil;
    if (exception_pending()) goto v76;
    env = stack[-4];
    v230 = (Lisp_Object)1; /* 0 */
    if (v468 == v230) goto v58;
    v230 = stack[-2];
    v230 = qcdr(v230);
    if (v230 == nil) goto v98;
    v230 = stack[-2];
    v230 = qcar(v230);
    v468 = qcdr(v230);
    v230 = stack[-3];
    fn = elt(env, 7); /* gcdf */
    v230 = (*qfn2(fn))(qenv(fn), v468, v230);
    nil = C_nil;
    if (exception_pending()) goto v76;
    env = stack[-4];
    stack[-3] = v230;
    goto v12;

v98:
    v230 = stack[-2];
    v230 = qcar(v230);
    stack[0] = qcar(v230);
    v468 = stack[-3];
    v230 = stack[-2];
    v230 = qcar(v230);
    v230 = qcdr(v230);
    fn = elt(env, 7); /* gcdf */
    v230 = (*qfn2(fn))(qenv(fn), v468, v230);
    nil = C_nil;
    if (exception_pending()) goto v76;
    {
        Lisp_Object v214 = stack[0];
        popv(5);
        return cons(v214, v230);
    }

v58:
    stack[0] = nil;
    v230 = stack[-2];
    if (!consp(v230)) goto v456;
    v230 = stack[-2];
    v230 = qcar(v230);
    if (!consp(v230)) goto v456;
    v230 = stack[-1];
    fn = elt(env, 8); /* noncomp */
    v230 = (*qfn1(fn))(qenv(fn), v230);
    nil = C_nil;
    if (exception_pending()) goto v76;
    env = stack[-4];
    if (v230 == nil) goto v456;
    v230 = stack[-2];
    v230 = qcar(v230);
    v230 = qcar(v230);
    v230 = qcar(v230);
    fn = elt(env, 8); /* noncomp */
    v230 = (*qfn1(fn))(qenv(fn), v230);
    nil = C_nil;
    if (exception_pending()) goto v76;
    env = stack[-4];
    if (v230 == nil) goto v456;
    v230 = (Lisp_Object)17; /* 1 */
    goto v103;

v103:
    {
        Lisp_Object v75 = stack[0];
        popv(5);
        return cons(v75, v230);
    }

v456:
    v468 = stack[-3];
    v230 = stack[-2];
    fn = elt(env, 7); /* gcdf */
    v230 = (*qfn2(fn))(qenv(fn), v468, v230);
    nil = C_nil;
    if (exception_pending()) goto v76;
    goto v103;

v37:
    v230 = stack[-2];
    v230 = qcar(v230);
    { popv(5); return onevalue(v230); }
/* error exit handlers */
v76:
    popv(5);
    return nil;
}



/* Code for ckrn */

static Lisp_Object CC_ckrn(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v41, v64;
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
    v64 = qvalue(elt(env, 1)); /* dmode!* */
    v41 = elt(env, 2); /* field */
    v41 = Lflagp(nil, v64, v41);
    env = stack[-2];
    if (v41 == nil) goto v34;
    v64 = qvalue(elt(env, 1)); /* dmode!* */
    v41 = elt(env, 3); /* (!:rd!: !:cr!:) */
    v41 = Lmemq(nil, v64, v41);
    if (!(v41 == nil)) goto v34;
    v41 = stack[0];
    fn = elt(env, 4); /* lnc */
    v41 = (*qfn1(fn))(qenv(fn), v41);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-2];
    stack[-1] = v41;
    v64 = stack[0];
    fn = elt(env, 5); /* quotfd */
    v41 = (*qfn2(fn))(qenv(fn), v64, v41);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-2];
    fn = elt(env, 6); /* ckrn1 */
    v41 = (*qfn1(fn))(qenv(fn), v41);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-2];
    fn = elt(env, 7); /* multf */
    v41 = (*qfn2(fn))(qenv(fn), stack[-1], v41);
    nil = C_nil;
    if (exception_pending()) goto v134;
    v64 = v41;
    if (!(v64 == nil)) { popv(3); return onevalue(v41); }
    v41 = (Lisp_Object)17; /* 1 */
    { popv(3); return onevalue(v41); }

v34:
    v41 = stack[0];
    {
        popv(3);
        fn = elt(env, 6); /* ckrn1 */
        return (*qfn1(fn))(qenv(fn), v41);
    }
/* error exit handlers */
v134:
    popv(3);
    return nil;
}



/* Code for maprin */

static Lisp_Object CC_maprin(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v20, v21, v22;
    Lisp_Object fn;
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v21 = v0;
/* end of prologue */
    v20 = qvalue(elt(env, 1)); /* outputhandler!* */
    if (v20 == nil) goto v4;
    v20 = qvalue(elt(env, 1)); /* outputhandler!* */
    v22 = elt(env, 0); /* maprin */
        return Lapply2(nil, 3, v20, v22, v21);

v4:
    v20 = qvalue(elt(env, 2)); /* overflowed!* */
    if (v20 == nil) goto v43;
    v20 = nil;
    return onevalue(v20);

v43:
    v20 = (Lisp_Object)1; /* 0 */
    {
        fn = elt(env, 3); /* maprint */
        return (*qfn2(fn))(qenv(fn), v21, v20);
    }
}



/* Code for rnconc */

static Lisp_Object CC_rnconc(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v40, v206;
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
    v40 = stack[-1];
    if (v40 == nil) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v40 = qvalue(elt(env, 1)); /* !*ncmp */
    if (v40 == nil) goto v18;
    v40 = stack[-1];
    fn = elt(env, 2); /* noncomfp1 */
    v40 = (*qfn1(fn))(qenv(fn), v40);
    nil = C_nil;
    if (exception_pending()) goto v100;
    env = stack[-2];
    if (v40 == nil) goto v18;
    v40 = stack[0];
    fn = elt(env, 2); /* noncomfp1 */
    v40 = (*qfn1(fn))(qenv(fn), v40);
    nil = C_nil;
    if (exception_pending()) goto v100;
    env = stack[-2];
    if (v40 == nil) goto v18;
    v206 = stack[-1];
    v40 = stack[0];
    {
        popv(3);
        fn = elt(env, 3); /* addf */
        return (*qfn2(fn))(qenv(fn), v206, v40);
    }

v18:
    v40 = stack[-1];
    v206 = v40;
    goto v10;

v10:
    v40 = v206;
    v40 = qcdr(v40);
    if (v40 == nil) goto v50;
    v40 = v206;
    v40 = qcdr(v40);
    v206 = v40;
    goto v10;

v50:
    v40 = stack[0];
    v40 = Lrplacd(nil, v206, v40);
    nil = C_nil;
    if (exception_pending()) goto v100;
    { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
/* error exit handlers */
v100:
    popv(3);
    return nil;
}



/* Code for chknewnam */

static Lisp_Object CC_chknewnam(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v10, v53, v14, v46;
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
    v14 = v0;
/* end of prologue */

v8:
    v53 = v14;
    v10 = elt(env, 1); /* newnam */
    v10 = get(v53, v10);
    env = stack[0];
    v46 = v10;
    if (v10 == nil) { popv(1); return onevalue(v14); }
    v53 = v46;
    v10 = v14;
    if (v53 == v10) { popv(1); return onevalue(v14); }
    v10 = v46;
    if (!(symbolp(v10))) { popv(1); return onevalue(v46); }
    v10 = v46;
    v14 = v10;
    goto v8;
}



/* Code for raddf */

static Lisp_Object CC_raddf(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v214, v75;
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
    v214 = stack[-2];
    if (v214 == nil) goto v2;
    v214 = stack[-1];
    if (v214 == nil) goto v43;
    v214 = stack[-2];
    if (!consp(v214)) goto v31;
    v214 = stack[-2];
    v214 = qcar(v214);
    if (!consp(v214)) goto v31;
    v214 = stack[-1];
    if (!consp(v214)) goto v105;
    v214 = stack[-1];
    v214 = qcar(v214);
    if (!consp(v214)) goto v105;
    v214 = stack[-2];
    v214 = qcar(v214);
    v75 = qcar(v214);
    v214 = stack[-1];
    v214 = qcar(v214);
    v214 = qcar(v214);
    if (equal(v75, v214)) goto v104;
    v214 = stack[-2];
    v214 = qcar(v214);
    v75 = qcar(v214);
    v214 = stack[-1];
    v214 = qcar(v214);
    v214 = qcar(v214);
    fn = elt(env, 1); /* ordpp */
    v214 = (*qfn2(fn))(qenv(fn), v75, v214);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-4];
    if (v214 == nil) goto v213;
    v214 = stack[-2];
    v75 = qcar(v214);
    v214 = stack[-3];
    v214 = cons(v75, v214);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-4];
    stack[-3] = v214;
    v214 = stack[-2];
    v214 = qcdr(v214);
    stack[-2] = v214;
    goto v12;

v213:
    v214 = stack[-1];
    v75 = qcar(v214);
    v214 = stack[-3];
    v214 = cons(v75, v214);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-4];
    stack[-3] = v214;
    v214 = stack[-1];
    v214 = qcdr(v214);
    stack[-1] = v214;
    goto v12;

v104:
    v214 = stack[-2];
    v214 = qcar(v214);
    stack[0] = qcar(v214);
    v214 = stack[-2];
    v214 = qcar(v214);
    v75 = qcdr(v214);
    v214 = stack[-1];
    v214 = qcar(v214);
    v214 = qcdr(v214);
    v75 = CC_raddf(env, v75, v214);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-4];
    v214 = stack[-3];
    v214 = acons(stack[0], v75, v214);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-4];
    stack[-3] = v214;
    v214 = stack[-2];
    v214 = qcdr(v214);
    stack[-2] = v214;
    v214 = stack[-1];
    v214 = qcdr(v214);
    stack[-1] = v214;
    goto v12;

v105:
    stack[0] = stack[-3];
    v75 = stack[-1];
    v214 = stack[-2];
    fn = elt(env, 2); /* addd */
    v214 = (*qfn2(fn))(qenv(fn), v75, v214);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-4];
    {
        Lisp_Object v109 = stack[0];
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v109, v214);
    }

v31:
    stack[0] = stack[-3];
    v75 = stack[-2];
    v214 = stack[-1];
    fn = elt(env, 2); /* addd */
    v214 = (*qfn2(fn))(qenv(fn), v75, v214);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-4];
    {
        Lisp_Object v110 = stack[0];
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v110, v214);
    }

v43:
    v75 = stack[-3];
    v214 = stack[-2];
    {
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v75, v214);
    }

v2:
    v75 = stack[-3];
    v214 = stack[-1];
    {
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v75, v214);
    }
/* error exit handlers */
v189:
    popv(5);
    return nil;
}



/* Code for getrmacro */

static Lisp_Object CC_getrmacro(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v49, v50, v52;
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
    v49 = stack[0];
    if (symbolp(v49)) goto v5;
    v49 = nil;
    { popv(2); return onevalue(v49); }

v5:
    v49 = stack[0];
    fn = elt(env, 3); /* getd */
    v49 = (*qfn1(fn))(qenv(fn), v49);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-1];
    v52 = v49;
    if (v49 == nil) goto v20;
    v49 = v52;
    v50 = qcar(v49);
    v49 = elt(env, 1); /* macro */
    if (v50 == v49) { popv(2); return onevalue(v52); }
    else goto v20;

v20:
    v50 = stack[0];
    v49 = elt(env, 2); /* smacro */
    v49 = get(v50, v49);
    env = stack[-1];
    v52 = v49;
    if (v49 == nil) goto v33;
    v49 = elt(env, 2); /* smacro */
    v50 = v52;
    popv(2);
    return cons(v49, v50);

v33:
    v49 = nil;
    { popv(2); return onevalue(v49); }
/* error exit handlers */
v35:
    popv(2);
    return nil;
}



/* Code for comfac!-to!-poly */

static Lisp_Object CC_comfacKtoKpoly(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v25, v13;
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v25 = v0;
/* end of prologue */
    v13 = v25;
    v13 = qcar(v13);
    if (v13 == nil) goto v3;
    return ncons(v25);

v3:
    v25 = qcdr(v25);
    return onevalue(v25);
}



/* Code for diffsq */

static Lisp_Object CC_diffsq(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v193, v35;
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
    v193 = stack[-2];
    v35 = qcar(v193);
    v193 = stack[-1];
    fn = elt(env, 1); /* difff */
    stack[-3] = (*qfn2(fn))(qenv(fn), v35, v193);
    nil = C_nil;
    if (exception_pending()) goto v41;
    env = stack[-4];
    stack[0] = stack[-2];
    v193 = stack[-2];
    v35 = qcdr(v193);
    v193 = stack[-1];
    fn = elt(env, 1); /* difff */
    v193 = (*qfn2(fn))(qenv(fn), v35, v193);
    nil = C_nil;
    if (exception_pending()) goto v41;
    env = stack[-4];
    fn = elt(env, 2); /* multsq */
    v193 = (*qfn2(fn))(qenv(fn), stack[0], v193);
    nil = C_nil;
    if (exception_pending()) goto v41;
    env = stack[-4];
    fn = elt(env, 3); /* negsq */
    v193 = (*qfn1(fn))(qenv(fn), v193);
    nil = C_nil;
    if (exception_pending()) goto v41;
    env = stack[-4];
    fn = elt(env, 4); /* addsq */
    stack[0] = (*qfn2(fn))(qenv(fn), stack[-3], v193);
    nil = C_nil;
    if (exception_pending()) goto v41;
    env = stack[-4];
    v35 = (Lisp_Object)17; /* 1 */
    v193 = stack[-2];
    v193 = qcdr(v193);
    v193 = cons(v35, v193);
    nil = C_nil;
    if (exception_pending()) goto v41;
    env = stack[-4];
    {
        Lisp_Object v64 = stack[0];
        popv(5);
        fn = elt(env, 2); /* multsq */
        return (*qfn2(fn))(qenv(fn), v64, v193);
    }
/* error exit handlers */
v41:
    popv(5);
    return nil;
}



/* Code for expdrmacro */

static Lisp_Object CC_expdrmacro(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v37, v36, v48;
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
    v37 = stack[0];
    fn = elt(env, 5); /* getrmacro */
    v37 = (*qfn1(fn))(qenv(fn), v37);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[-1];
    v48 = v37;
    if (v37 == nil) goto v45;
    v36 = stack[0];
    v37 = elt(env, 1); /* noexpand */
    v37 = Lflagp(nil, v36, v37);
    env = stack[-1];
    if (!(v37 == nil)) goto v45;
    v37 = qvalue(elt(env, 2)); /* !*cref */
    if (v37 == nil) { popv(2); return onevalue(v48); }
    v36 = stack[0];
    v37 = elt(env, 3); /* expand */
    v37 = Lflagp(nil, v36, v37);
    env = stack[-1];
    if (!(v37 == nil)) { popv(2); return onevalue(v48); }
    v37 = qvalue(elt(env, 4)); /* !*force */
    if (!(v37 == nil)) { popv(2); return onevalue(v48); }
    v37 = nil;
    { popv(2); return onevalue(v37); }

v45:
    v37 = nil;
    { popv(2); return onevalue(v37); }
/* error exit handlers */
v51:
    popv(2);
    return nil;
}



/* Code for xread */

static Lisp_Object CC_xread(Lisp_Object env,
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
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v0;
/* end of prologue */

v3:
    fn = elt(env, 4); /* scan */
    v47 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v29;
    env = stack[-1];
    v47 = qvalue(elt(env, 1)); /* !*eoldelimp */
    if (v47 == nil) goto v45;
    v15 = qvalue(elt(env, 2)); /* cursym!* */
    v47 = elt(env, 3); /* !*semicol!* */
    if (v15 == v47) goto v3;
    else goto v45;

v45:
    v47 = stack[0];
    {
        popv(2);
        fn = elt(env, 5); /* xread1 */
        return (*qfn1(fn))(qenv(fn), v47);
    }
/* error exit handlers */
v29:
    popv(2);
    return nil;
}



/* Code for exptpri */

static Lisp_Object CC_exptpri(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v290, v335, v321;
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
    v335 = v16;
    stack[-5] = v0;
/* end of prologue */
    stack[-6] = qvalue(elt(env, 1)); /* !*list */
    qvalue(elt(env, 1)) = nil; /* !*list */
    stack[0] = nil;
    v290 = qvalue(elt(env, 2)); /* !*nat */
    if (v290 == nil) goto v2;
    v290 = qvalue(elt(env, 3)); /* !*fort */
    if (!(v290 == nil)) goto v2;
    v321 = elt(env, 5); /* expt */
    v290 = elt(env, 6); /* infix */
    v290 = get(v321, v290);
    env = stack[-7];
    stack[-2] = v290;
    v290 = (Lisp_Object)greaterp2(v290, v335);
    nil = C_nil;
    if (exception_pending()) goto v293;
    v290 = v290 ? lisp_true : nil;
    env = stack[-7];
    v290 = (v290 == nil ? lisp_true : nil);
    stack[-4] = v290;
    v290 = stack[-5];
    v290 = qcdr(v290);
    v290 = qcar(v290);
    stack[-1] = v290;
    v290 = stack[-5];
    v290 = qcdr(v290);
    v290 = qcdr(v290);
    v290 = qcar(v290);
    stack[-3] = v290;
    v290 = qvalue(elt(env, 7)); /* !*eraise */
    if (v290 == nil) goto v107;
    v290 = stack[-1];
    if (!consp(v290)) goto v107;
    v290 = stack[-1];
    v335 = qcar(v290);
    v290 = elt(env, 8); /* prifn */
    v290 = get(v335, v290);
    env = stack[-7];
    stack[0] = v290;
    if (v290 == nil) goto v107;
    v335 = stack[0];
    v290 = elt(env, 5); /* expt */
    v335 = get(v335, v290);
    env = stack[-7];
    v290 = elt(env, 9); /* inbrackets */
    if (!(v335 == v290)) goto v107;
    v321 = stack[-1];
    v335 = (Lisp_Object)1; /* 0 */
    v290 = elt(env, 9); /* inbrackets */
    fn = elt(env, 19); /* layout!-formula */
    v290 = (*qfnn(fn))(qenv(fn), 3, v321, v335, v290);
    nil = C_nil;
    if (exception_pending()) goto v293;
    env = stack[-7];
    stack[-1] = v290;
    goto v33;

v33:
    v290 = stack[-1];
    if (v290 == nil) goto v219;
    stack[-5] = qvalue(elt(env, 11)); /* !*ratpri */
    qvalue(elt(env, 11)) = nil; /* !*ratpri */
    v335 = stack[-3];
    v290 = elt(env, 12); /* quotient */
    if (!consp(v335)) goto v126;
    v335 = qcar(v335);
    if (!(v335 == v290)) goto v126;
    v290 = stack[-3];
    v290 = qcdr(v290);
    v335 = qcar(v290);
    v290 = elt(env, 13); /* minus */
    if (!consp(v335)) goto v126;
    v335 = qcar(v335);
    if (!(v335 == v290)) goto v126;
    stack[0] = elt(env, 13); /* minus */
    v290 = stack[-3];
    v321 = qcar(v290);
    v290 = stack[-3];
    v290 = qcdr(v290);
    v290 = qcar(v290);
    v290 = qcdr(v290);
    v335 = qcar(v290);
    v290 = stack[-3];
    v290 = qcdr(v290);
    v290 = qcdr(v290);
    v290 = qcar(v290);
    v290 = list3(v321, v335, v290);
    nil = C_nil;
    if (exception_pending()) goto v291;
    env = stack[-7];
    v290 = list2(stack[0], v290);
    nil = C_nil;
    if (exception_pending()) goto v291;
    env = stack[-7];
    stack[-3] = v290;
    goto v180;

v180:
    v321 = stack[-3];
    v290 = qvalue(elt(env, 7)); /* !*eraise */
    if (v290 == nil) goto v351;
    v290 = (Lisp_Object)1; /* 0 */
    v335 = v290;
    goto v486;

v486:
    v290 = nil;
    fn = elt(env, 19); /* layout!-formula */
    v290 = (*qfnn(fn))(qenv(fn), 3, v321, v335, v290);
    nil = C_nil;
    if (exception_pending()) goto v291;
    env = stack[-7];
    stack[-3] = v290;
    qvalue(elt(env, 11)) = stack[-5]; /* !*ratpri */
    v290 = stack[-3];
    if (v290 == nil) goto v256;
    v290 = stack[-1];
    v290 = qcar(v290);
    v335 = qcdr(v290);
    v290 = stack[-3];
    v290 = qcar(v290);
    v290 = qcdr(v290);
    v290 = plus2(v335, v290);
    nil = C_nil;
    if (exception_pending()) goto v293;
    env = stack[-7];
    stack[-5] = v290;
    v290 = stack[-4];
    if (v290 == nil) goto v476;
    v335 = stack[-5];
    v290 = (Lisp_Object)33; /* 2 */
    v290 = plus2(v335, v290);
    nil = C_nil;
    if (exception_pending()) goto v293;
    env = stack[-7];
    stack[-5] = v290;
    goto v476;

v476:
    stack[0] = stack[-5];
    v290 = nil;
    v335 = Llinelength(nil, v290);
    nil = C_nil;
    if (exception_pending()) goto v293;
    env = stack[-7];
    v290 = qvalue(elt(env, 14)); /* spare!* */
    v335 = difference2(v335, v290);
    nil = C_nil;
    if (exception_pending()) goto v293;
    env = stack[-7];
    v290 = qvalue(elt(env, 15)); /* orig!* */
    v290 = difference2(v335, v290);
    nil = C_nil;
    if (exception_pending()) goto v293;
    env = stack[-7];
    v290 = (Lisp_Object)greaterp2(stack[0], v290);
    nil = C_nil;
    if (exception_pending()) goto v293;
    v290 = v290 ? lisp_true : nil;
    env = stack[-7];
    if (v290 == nil) goto v522;
    v290 = elt(env, 4); /* failed */
    goto v7;

v7:
    qvalue(elt(env, 1)) = stack[-6]; /* !*list */
    { popv(8); return onevalue(v290); }

v522:
    stack[0] = stack[-5];
    v290 = nil;
    v335 = Llinelength(nil, v290);
    nil = C_nil;
    if (exception_pending()) goto v293;
    env = stack[-7];
    v290 = qvalue(elt(env, 14)); /* spare!* */
    v335 = difference2(v335, v290);
    nil = C_nil;
    if (exception_pending()) goto v293;
    env = stack[-7];
    v290 = qvalue(elt(env, 16)); /* posn!* */
    v290 = difference2(v335, v290);
    nil = C_nil;
    if (exception_pending()) goto v293;
    env = stack[-7];
    v290 = (Lisp_Object)greaterp2(stack[0], v290);
    nil = C_nil;
    if (exception_pending()) goto v293;
    v290 = v290 ? lisp_true : nil;
    env = stack[-7];
    if (v290 == nil) goto v346;
    v290 = lisp_true;
    fn = elt(env, 20); /* terpri!* */
    v290 = (*qfn1(fn))(qenv(fn), v290);
    nil = C_nil;
    if (exception_pending()) goto v293;
    env = stack[-7];
    goto v346;

v346:
    v290 = stack[-4];
    if (v290 == nil) goto v523;
    v290 = elt(env, 17); /* "(" */
    fn = elt(env, 21); /* prin2!* */
    v290 = (*qfn1(fn))(qenv(fn), v290);
    nil = C_nil;
    if (exception_pending()) goto v293;
    env = stack[-7];
    goto v523;

v523:
    v290 = stack[-1];
    fn = elt(env, 22); /* putpline */
    v290 = (*qfn1(fn))(qenv(fn), v290);
    nil = C_nil;
    if (exception_pending()) goto v293;
    env = stack[-7];
    v290 = qvalue(elt(env, 7)); /* !*eraise */
    if (v290 == nil) goto v514;
    v335 = (Lisp_Object)17; /* 1 */
    v290 = stack[-3];
    v290 = qcdr(v290);
    v290 = qcar(v290);
    v290 = difference2(v335, v290);
    nil = C_nil;
    if (exception_pending()) goto v293;
    env = stack[-7];
    stack[-5] = v290;
    goto v482;

v482:
    v321 = (Lisp_Object)1; /* 0 */
    v335 = stack[-5];
    v290 = stack[-3];
    v290 = qcar(v290);
    v290 = qcar(v290);
    fn = elt(env, 23); /* update!-pline */
    stack[-2] = (*qfnn(fn))(qenv(fn), 3, v321, v335, v290);
    nil = C_nil;
    if (exception_pending()) goto v293;
    env = stack[-7];
    v290 = stack[-3];
    v290 = qcar(v290);
    stack[-1] = qcdr(v290);
    v290 = stack[-3];
    v290 = qcdr(v290);
    v335 = qcar(v290);
    v290 = stack[-5];
    stack[0] = plus2(v335, v290);
    nil = C_nil;
    if (exception_pending()) goto v293;
    env = stack[-7];
    v290 = stack[-3];
    v290 = qcdr(v290);
    v335 = qcdr(v290);
    v290 = stack[-5];
    v290 = plus2(v335, v290);
    nil = C_nil;
    if (exception_pending()) goto v293;
    env = stack[-7];
    v290 = cons(stack[0], v290);
    nil = C_nil;
    if (exception_pending()) goto v293;
    env = stack[-7];
    v290 = acons(stack[-2], stack[-1], v290);
    nil = C_nil;
    if (exception_pending()) goto v293;
    env = stack[-7];
    fn = elt(env, 22); /* putpline */
    v290 = (*qfn1(fn))(qenv(fn), v290);
    nil = C_nil;
    if (exception_pending()) goto v293;
    env = stack[-7];
    v290 = stack[-4];
    if (v290 == nil) goto v197;
    v290 = elt(env, 18); /* ")" */
    fn = elt(env, 21); /* prin2!* */
    v290 = (*qfn1(fn))(qenv(fn), v290);
    nil = C_nil;
    if (exception_pending()) goto v293;
    env = stack[-7];
    goto v197;

v197:
    v290 = nil;
    goto v7;

v514:
    v290 = elt(env, 5); /* expt */
    fn = elt(env, 24); /* oprin */
    v290 = (*qfn1(fn))(qenv(fn), v290);
    nil = C_nil;
    if (exception_pending()) goto v293;
    env = stack[-7];
    v290 = (Lisp_Object)1; /* 0 */
    stack[-5] = v290;
    goto v482;

v256:
    v290 = elt(env, 4); /* failed */
    goto v7;

v351:
    v290 = stack[-2];
    v335 = v290;
    goto v486;

v126:
    v290 = stack[-3];
    fn = elt(env, 25); /* negnumberchk */
    v290 = (*qfn1(fn))(qenv(fn), v290);
    nil = C_nil;
    if (exception_pending()) goto v291;
    env = stack[-7];
    stack[-3] = v290;
    goto v180;

v219:
    v290 = elt(env, 4); /* failed */
    goto v7;

v107:
    v335 = stack[0];
    v290 = elt(env, 10); /* indexprin */
    if (!(v335 == v290)) goto v119;
    v335 = stack[-1];
    v290 = stack[-3];
    fn = elt(env, 26); /* indexpower */
    v335 = (*qfn2(fn))(qenv(fn), v335, v290);
    nil = C_nil;
    if (exception_pending()) goto v293;
    env = stack[-7];
    v290 = elt(env, 4); /* failed */
    if (v335 == v290) goto v119;
    v290 = nil;
    goto v7;

v119:
    v321 = stack[-1];
    v335 = stack[-2];
    v290 = nil;
    fn = elt(env, 19); /* layout!-formula */
    v290 = (*qfnn(fn))(qenv(fn), 3, v321, v335, v290);
    nil = C_nil;
    if (exception_pending()) goto v293;
    env = stack[-7];
    stack[-1] = v290;
    goto v33;

v2:
    v290 = elt(env, 4); /* failed */
    goto v7;
/* error exit handlers */
v291:
    env = stack[-7];
    qvalue(elt(env, 11)) = stack[-5]; /* !*ratpri */
    qvalue(elt(env, 1)) = stack[-6]; /* !*list */
    popv(8);
    return nil;
v293:
    env = stack[-7];
    qvalue(elt(env, 1)) = stack[-6]; /* !*list */
    popv(8);
    return nil;
}



/* Code for algmodep */

static Lisp_Object CC_algmodep(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v28, v38;
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v38 = v0;
/* end of prologue */
    v28 = v38;
    if (!consp(v28)) goto v3;
    v28 = v38;
    v28 = qcar(v28);
    v38 = elt(env, 1); /* (aeval aeval!*) */
    v28 = Lmemq(nil, v28, v38);
    return onevalue(v28);

v3:
    v28 = nil;
    return onevalue(v28);
}



/* Code for simprecip */

static Lisp_Object CC_simprecip(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v10, v53;
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
    v53 = v0;
/* end of prologue */
    v10 = qvalue(elt(env, 1)); /* !*mcd */
    if (v10 == nil) goto v26;
    v10 = elt(env, 2); /* recip */
    fn = elt(env, 3); /* carx */
    v10 = (*qfn2(fn))(qenv(fn), v53, v10);
    nil = C_nil;
    if (exception_pending()) goto v14;
    env = stack[0];
    fn = elt(env, 4); /* simp */
    v10 = (*qfn1(fn))(qenv(fn), v10);
    nil = C_nil;
    if (exception_pending()) goto v14;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 5); /* invsq */
        return (*qfn1(fn))(qenv(fn), v10);
    }

v26:
    v10 = elt(env, 2); /* recip */
    fn = elt(env, 3); /* carx */
    v53 = (*qfn2(fn))(qenv(fn), v53, v10);
    nil = C_nil;
    if (exception_pending()) goto v14;
    env = stack[0];
    v10 = (Lisp_Object)-15; /* -1 */
    v10 = list2(v53, v10);
    nil = C_nil;
    if (exception_pending()) goto v14;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 6); /* simpexpt */
        return (*qfn1(fn))(qenv(fn), v10);
    }
/* error exit handlers */
v14:
    popv(1);
    return nil;
}



/* Code for addns */

static Lisp_Object CC_addns(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v121, v143, v144;
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
    v121 = stack[0];
    if (v121 == nil) goto v2;
    v121 = stack[-1];
    v143 = qcdr(v121);
    v121 = stack[0];
    v121 = qcar(v121);
    v121 = qcdr(v121);
    if (equal(v143, v121)) goto v37;
    v121 = stack[-1];
    v143 = qcdr(v121);
    v121 = stack[0];
    v121 = qcar(v121);
    v121 = qcdr(v121);
    fn = elt(env, 1); /* ordp */
    v121 = (*qfn2(fn))(qenv(fn), v143, v121);
    nil = C_nil;
    if (exception_pending()) goto v81;
    env = stack[-3];
    if (v121 == nil) goto v226;
    v143 = stack[-1];
    v121 = stack[0];
    v121 = cons(v143, v121);
    nil = C_nil;
    if (exception_pending()) goto v81;
    env = stack[-3];
    {
        Lisp_Object v97 = stack[-2];
        popv(4);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v97, v121);
    }

v226:
    v121 = stack[0];
    v143 = qcar(v121);
    v121 = stack[-2];
    v121 = cons(v143, v121);
    nil = C_nil;
    if (exception_pending()) goto v81;
    env = stack[-3];
    stack[-2] = v121;
    v121 = stack[0];
    v121 = qcdr(v121);
    stack[0] = v121;
    goto v12;

v37:
    v121 = stack[-1];
    v143 = qcar(v121);
    v121 = stack[0];
    v121 = qcar(v121);
    v121 = qcar(v121);
    fn = elt(env, 3); /* addsq */
    v121 = (*qfn2(fn))(qenv(fn), v143, v121);
    nil = C_nil;
    if (exception_pending()) goto v81;
    env = stack[-3];
    v144 = v121;
    v121 = stack[-1];
    v143 = qcdr(v121);
    v121 = stack[0];
    v121 = qcdr(v121);
    v121 = acons(v144, v143, v121);
    nil = C_nil;
    if (exception_pending()) goto v81;
    env = stack[-3];
    {
        Lisp_Object v118 = stack[-2];
        popv(4);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v118, v121);
    }

v2:
    stack[0] = stack[-2];
    v121 = stack[-1];
    v121 = ncons(v121);
    nil = C_nil;
    if (exception_pending()) goto v81;
    env = stack[-3];
    {
        Lisp_Object v135 = stack[0];
        popv(4);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v135, v121);
    }
/* error exit handlers */
v81:
    popv(4);
    return nil;
}



/* Code for !*!*a2i */

static Lisp_Object CC_HHa2i(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v17, v18;
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
    v17 = v16;
    stack[0] = v0;
/* end of prologue */
    v18 = stack[0];
    fn = elt(env, 2); /* intexprnp */
    v17 = (*qfn2(fn))(qenv(fn), v18, v17);
    nil = C_nil;
    if (exception_pending()) goto v20;
    env = stack[-1];
    if (!(v17 == nil)) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v18 = elt(env, 1); /* ieval */
    v17 = stack[0];
    popv(2);
    return list2(v18, v17);
/* error exit handlers */
v20:
    popv(2);
    return nil;
}



/* Code for quotof */

static Lisp_Object CC_quotof(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v524, v465, v357;
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
    v524 = stack[-3];
    if (v524 == nil) goto v4;
    v465 = stack[-3];
    v524 = stack[-2];
    if (equal(v465, v524)) goto v6;
    v465 = stack[-2];
    v524 = (Lisp_Object)17; /* 1 */
    if (v465 == v524) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v524 = stack[-2];
    if (!consp(v524)) goto v14;
    v524 = stack[-2];
    v524 = qcar(v524);
    if (!consp(v524)) goto v14;
    v524 = stack[-3];
    if (!consp(v524)) goto v33;
    v524 = stack[-3];
    v524 = qcar(v524);
    if (!consp(v524)) goto v33;
    v524 = stack[-3];
    v524 = qcar(v524);
    v465 = qcar(v524);
    v524 = stack[-2];
    v524 = qcar(v524);
    v524 = qcar(v524);
    stack[0] = v465;
    stack[-4] = v524;
    v524 = stack[0];
    v465 = qcar(v524);
    v524 = stack[-4];
    v524 = qcar(v524);
    if (v465 == v524) goto v235;
    v524 = stack[0];
    v465 = qcar(v524);
    v524 = stack[-4];
    v524 = qcar(v524);
    fn = elt(env, 3); /* ordop */
    v524 = (*qfn2(fn))(qenv(fn), v465, v524);
    nil = C_nil;
    if (exception_pending()) goto v484;
    env = stack[-5];
    if (v524 == nil) goto v202;
    stack[-1] = stack[0];
    v524 = stack[-3];
    v524 = qcar(v524);
    v465 = qcdr(v524);
    v524 = stack[-2];
    stack[0] = CC_quotof(env, v465, v524);
    nil = C_nil;
    if (exception_pending()) goto v484;
    env = stack[-5];
    v524 = stack[-3];
    v465 = qcdr(v524);
    v524 = stack[-2];
    v524 = CC_quotof(env, v465, v524);
    nil = C_nil;
    if (exception_pending()) goto v484;
    {
        Lisp_Object v244 = stack[-1];
        Lisp_Object v245 = stack[0];
        popv(6);
        return acons(v244, v245, v524);
    }

v202:
    v524 = stack[-4];
    stack[0] = qcar(v524);
    v524 = stack[-4];
    v524 = qcdr(v524);
    v524 = negate(v524);
    nil = C_nil;
    if (exception_pending()) goto v484;
    env = stack[-5];
    fn = elt(env, 4); /* mksp */
    stack[0] = (*qfn2(fn))(qenv(fn), stack[0], v524);
    nil = C_nil;
    if (exception_pending()) goto v484;
    env = stack[-5];
    stack[-1] = stack[-3];
    v465 = stack[-2];
    v524 = elt(env, 2); /* lcx */
    fn = elt(env, 5); /* carx */
    v524 = (*qfn2(fn))(qenv(fn), v465, v524);
    nil = C_nil;
    if (exception_pending()) goto v484;
    env = stack[-5];
    v524 = qcdr(v524);
    v524 = CC_quotof(env, stack[-1], v524);
    nil = C_nil;
    if (exception_pending()) goto v484;
    env = stack[-5];
    v524 = cons(stack[0], v524);
    nil = C_nil;
    if (exception_pending()) goto v484;
    popv(6);
    return ncons(v524);

v235:
    v524 = stack[0];
    v465 = qcdr(v524);
    v524 = stack[-4];
    v524 = qcdr(v524);
    stack[-1] = difference2(v465, v524);
    nil = C_nil;
    if (exception_pending()) goto v484;
    env = stack[-5];
    v524 = stack[-3];
    v524 = qcar(v524);
    stack[0] = qcdr(v524);
    v465 = stack[-2];
    v524 = elt(env, 2); /* lcx */
    fn = elt(env, 5); /* carx */
    v524 = (*qfn2(fn))(qenv(fn), v465, v524);
    nil = C_nil;
    if (exception_pending()) goto v484;
    env = stack[-5];
    v524 = qcdr(v524);
    stack[0] = CC_quotof(env, stack[0], v524);
    nil = C_nil;
    if (exception_pending()) goto v484;
    env = stack[-5];
    v524 = stack[-3];
    v465 = qcdr(v524);
    v524 = stack[-2];
    v524 = CC_quotof(env, v465, v524);
    nil = C_nil;
    if (exception_pending()) goto v484;
    env = stack[-5];
    v357 = stack[-1];
    stack[-1] = stack[0];
    stack[0] = v524;
    v465 = v357;
    v524 = (Lisp_Object)1; /* 0 */
    if (v465 == v524) goto v473;
    v524 = stack[-4];
    v524 = qcar(v524);
    v465 = v357;
    fn = elt(env, 6); /* to */
    v357 = (*qfn2(fn))(qenv(fn), v524, v465);
    nil = C_nil;
    if (exception_pending()) goto v484;
    v465 = stack[-1];
    v524 = stack[0];
    popv(6);
    return acons(v357, v465, v524);

v473:
    v465 = stack[-1];
    v524 = stack[0];
    {
        popv(6);
        fn = elt(env, 7); /* raddf */
        return (*qfn2(fn))(qenv(fn), v465, v524);
    }

v33:
    v524 = stack[-2];
    v524 = qcar(v524);
    v524 = qcar(v524);
    v524 = qcdr(v524);
    v465 = stack[-2];
    v465 = qcar(v465);
    v465 = qcar(v465);
    stack[0] = qcar(v465);
    v465 = v524;
    if (is_number(v465)) goto v58;
    v465 = elt(env, 1); /* minus */
    v524 = list2(v465, v524);
    nil = C_nil;
    if (exception_pending()) goto v484;
    env = stack[-5];
    goto v87;

v87:
    fn = elt(env, 4); /* mksp */
    stack[0] = (*qfn2(fn))(qenv(fn), stack[0], v524);
    nil = C_nil;
    if (exception_pending()) goto v484;
    env = stack[-5];
    stack[-1] = stack[-3];
    v465 = stack[-2];
    v524 = elt(env, 2); /* lcx */
    fn = elt(env, 5); /* carx */
    v524 = (*qfn2(fn))(qenv(fn), v465, v524);
    nil = C_nil;
    if (exception_pending()) goto v484;
    env = stack[-5];
    v524 = qcdr(v524);
    v524 = CC_quotof(env, stack[-1], v524);
    nil = C_nil;
    if (exception_pending()) goto v484;
    env = stack[-5];
    v524 = cons(stack[0], v524);
    nil = C_nil;
    if (exception_pending()) goto v484;
    popv(6);
    return ncons(v524);

v58:
    v524 = negate(v524);
    nil = C_nil;
    if (exception_pending()) goto v484;
    env = stack[-5];
    goto v87;

v14:
    v465 = stack[-3];
    v524 = stack[-2];
    {
        popv(6);
        fn = elt(env, 8); /* quotofd */
        return (*qfn2(fn))(qenv(fn), v465, v524);
    }

v6:
    v524 = (Lisp_Object)17; /* 1 */
    { popv(6); return onevalue(v524); }

v4:
    v524 = nil;
    { popv(6); return onevalue(v524); }
/* error exit handlers */
v484:
    popv(6);
    return nil;
}



/* Code for form1 */

static Lisp_Object MS_CDECL CC_form1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v16,
                         Lisp_Object v63, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v547, v310, v311, v312;
    Lisp_Object fn;
    argcheck(nargs, 3, "form1");
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

v11:
    v547 = stack[-3];
    if (!consp(v547)) goto v7;
    v547 = stack[-3];
    v547 = qcar(v547);
    if (!consp(v547)) goto v87;
    v311 = stack[-3];
    v310 = stack[-2];
    v547 = stack[-1];
    {
        popv(6);
        fn = elt(env, 27); /* form2 */
        return (*qfnn(fn))(qenv(fn), 3, v311, v310, v547);
    }

v87:
    v547 = stack[-3];
    v547 = qcar(v547);
    if (symbolp(v547)) goto v226;
    v547 = stack[-3];
    v310 = qcar(v547);
    v547 = elt(env, 4); /* "operator" */
    fn = elt(env, 28); /* typerr */
    v547 = (*qfn2(fn))(qenv(fn), v310, v547);
    nil = C_nil;
    if (exception_pending()) goto v548;
    env = stack[-5];
    goto v196;

v196:
    v310 = stack[-1];
    v547 = elt(env, 7); /* symbolic */
    if (v310 == v547) goto v153;
    v547 = stack[-3];
    v310 = qcar(v547);
    v547 = elt(env, 19); /* opfn */
    v547 = Lflagp(nil, v310, v547);
    env = stack[-5];
    if (!(v547 == nil)) goto v153;

v292:
    v547 = stack[-3];
    v311 = qcdr(v547);
    v310 = stack[-2];
    v547 = stack[-1];
    fn = elt(env, 29); /* formlis */
    v547 = (*qfnn(fn))(qenv(fn), 3, v311, v310, v547);
    nil = C_nil;
    if (exception_pending()) goto v548;
    env = stack[-5];
    stack[-4] = v547;
    v310 = stack[-4];
    v547 = stack[-3];
    v547 = qcdr(v547);
    if (equal(v310, v547)) goto v440;
    v547 = stack[-3];
    v310 = qcar(v547);
    v547 = stack[-4];
    v547 = cons(v310, v547);
    nil = C_nil;
    if (exception_pending()) goto v548;
    env = stack[-5];
    goto v549;

v549:
    stack[0] = v547;
    v310 = stack[-1];
    v547 = elt(env, 7); /* symbolic */
    if (v310 == v547) goto v323;
    v547 = stack[-3];
    v310 = qcar(v547);
    v547 = elt(env, 13); /* stat */
    v547 = get(v310, v547);
    env = stack[-5];
    if (!(v547 == nil)) goto v323;
    v547 = stack[-3];
    v547 = qcdr(v547);
    if (v547 == nil) goto v550;
    v547 = stack[-3];
    v547 = qcdr(v547);
    v310 = qcar(v547);
    v547 = elt(env, 20); /* quote */
    if (!consp(v310)) goto v550;
    v310 = qcar(v310);
    if (!(v310 == v547)) goto v550;
    v547 = qvalue(elt(env, 21)); /* !*micro!-version */
    if (v547 == nil) goto v323;
    v547 = qvalue(elt(env, 22)); /* !*defn */
    if (!(v547 == nil)) goto v323;

v550:
    v310 = stack[0];
    v547 = stack[-2];
    fn = elt(env, 30); /* intexprnp */
    v547 = (*qfn2(fn))(qenv(fn), v310, v547);
    nil = C_nil;
    if (exception_pending()) goto v548;
    env = stack[-5];
    if (v547 == nil) goto v403;
    v547 = qvalue(elt(env, 23)); /* !*composites */
    if (!(v547 == nil)) goto v403;
    v310 = qvalue(elt(env, 24)); /* current!-modulus */
    v547 = (Lisp_Object)17; /* 1 */
    if (!(v310 == v547)) goto v403;

v323:
    v310 = stack[0];
    v547 = stack[-1];
    {
        popv(6);
        fn = elt(env, 31); /* macrochk */
        return (*qfn2(fn))(qenv(fn), v310, v547);
    }

v403:
    v310 = stack[-1];
    v547 = elt(env, 25); /* algebraic */
    if (v310 == v547) goto v499;
    v312 = stack[0];
    v311 = stack[-2];
    v310 = stack[-1];
    v547 = elt(env, 25); /* algebraic */
    {
        popv(6);
        fn = elt(env, 32); /* convertmode */
        return (*qfnn(fn))(qenv(fn), 4, v312, v311, v310, v547);
    }

v499:
    stack[0] = elt(env, 26); /* list */
    v547 = stack[-3];
    v310 = qcar(v547);
    v547 = stack[-2];
    fn = elt(env, 33); /* algid */
    v310 = (*qfn2(fn))(qenv(fn), v310, v547);
    nil = C_nil;
    if (exception_pending()) goto v548;
    v547 = stack[-4];
    {
        Lisp_Object v551 = stack[0];
        popv(6);
        return list2star(v551, v310, v547);
    }

v440:
    v547 = stack[-3];
    goto v549;

v153:
    v547 = stack[-3];
    fn = elt(env, 34); /* argnochk */
    v547 = (*qfn1(fn))(qenv(fn), v547);
    nil = C_nil;
    if (exception_pending()) goto v548;
    env = stack[-5];
    goto v292;

v226:
    v547 = stack[-3];
    v310 = qcar(v547);
    v547 = elt(env, 5); /* comment */
    if (v310 == v547) goto v237;
    v547 = stack[-3];
    v310 = qcar(v547);
    v547 = elt(env, 6); /* noform */
    v547 = Lflagp(nil, v310, v547);
    env = stack[-5];
    if (!(v547 == nil)) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v547 = stack[-3];
    v547 = qcar(v547);
    fn = elt(env, 35); /* arrayp */
    v547 = (*qfn1(fn))(qenv(fn), v547);
    nil = C_nil;
    if (exception_pending()) goto v548;
    env = stack[-5];
    if (v547 == nil) goto v235;
    v310 = stack[-1];
    v547 = elt(env, 7); /* symbolic */
    if (!(v310 == v547)) goto v235;
    stack[0] = elt(env, 8); /* getel */
    v311 = stack[-3];
    v310 = stack[-2];
    v547 = stack[-1];
    fn = elt(env, 36); /* intargfn */
    v547 = (*qfnn(fn))(qenv(fn), 3, v311, v310, v547);
    nil = C_nil;
    if (exception_pending()) goto v548;
    {
        Lisp_Object v552 = stack[0];
        popv(6);
        return list2(v552, v547);
    }

v235:
    v547 = stack[-3];
    v547 = qcdr(v547);
    if (v547 == nil) goto v209;
    v547 = stack[-3];
    v310 = qcar(v547);
    v547 = elt(env, 9); /* rtype */
    v310 = get(v310, v547);
    env = stack[-5];
    v547 = elt(env, 10); /* vector */
    if (v310 == v547) goto v434;
    v547 = stack[-3];
    v547 = qcdr(v547);
    v547 = qcar(v547);
    v547 = Lsimple_vectorp(nil, v547);
    env = stack[-5];
    if (!(v547 == nil)) goto v434;
    v547 = stack[-3];
    v547 = qcdr(v547);
    v310 = qcar(v547);
    v547 = elt(env, 11); /* vecfn */
    v547 = Lflagpcar(nil, v310, v547);
    env = stack[-5];
    if (!(v547 == nil)) goto v434;

v209:
    v547 = stack[-3];
    v310 = qcar(v547);
    v547 = elt(env, 2); /* modefn */
    v547 = Lflagp(nil, v310, v547);
    env = stack[-5];
    if (v547 == nil) goto v201;
    v547 = stack[-3];
    v547 = qcdr(v547);
    v312 = qcar(v547);
    v311 = stack[-2];
    v310 = stack[-1];
    v547 = stack[-3];
    v547 = qcar(v547);
    {
        popv(6);
        fn = elt(env, 32); /* convertmode */
        return (*qfnn(fn))(qenv(fn), 4, v312, v311, v310, v547);
    }

v201:
    v547 = stack[-3];
    v310 = qcar(v547);
    v547 = elt(env, 12); /* formfn */
    v547 = get(v310, v547);
    env = stack[-5];
    stack[-4] = v547;
    if (v547 == nil) goto v167;
    v312 = stack[-4];
    v311 = stack[-3];
    v310 = stack[-2];
    v547 = stack[-1];
    v310 = Lapply3(nil, 4, v312, v311, v310, v547);
    nil = C_nil;
    if (exception_pending()) goto v548;
    env = stack[-5];
    v547 = stack[-1];
    {
        popv(6);
        fn = elt(env, 31); /* macrochk */
        return (*qfn2(fn))(qenv(fn), v310, v547);
    }

v167:
    v547 = stack[-3];
    v310 = qcar(v547);
    v547 = elt(env, 13); /* stat */
    v310 = get(v310, v547);
    env = stack[-5];
    v547 = elt(env, 14); /* rlis */
    if (v310 == v547) goto v244;
    v547 = stack[-3];
    v310 = qcar(v547);
    v547 = elt(env, 15); /* !*comma!* */
    if (!(v310 == v547)) goto v196;
    v547 = stack[-3];
    v547 = qcdr(v547);
    v547 = qcar(v547);
    if (!consp(v547)) goto v155;
    v547 = stack[-3];
    v547 = qcdr(v547);
    v547 = qcdr(v547);
    v547 = qcar(v547);
    if (!(!consp(v547))) goto v155;
    v547 = stack[-3];
    v547 = qcdr(v547);
    v547 = qcar(v547);
    v310 = qcar(v547);
    v547 = elt(env, 16); /* type */
    v547 = Lflagp(nil, v310, v547);
    env = stack[-5];
    if (v547 == nil) goto v155;
    v547 = stack[-3];
    v547 = qcdr(v547);
    v547 = qcar(v547);
    v547 = qcar(v547);
    fn = elt(env, 37); /* blocktyperr */
    v547 = (*qfn1(fn))(qenv(fn), v547);
    nil = C_nil;
    if (exception_pending()) goto v548;
    env = stack[-5];
    goto v196;

v155:
    stack[-4] = elt(env, 17); /* rlisp */
    stack[0] = (Lisp_Object)161; /* 10 */
    v310 = elt(env, 18); /* "Syntax error: , invalid after" */
    v547 = stack[-3];
    v547 = qcdr(v547);
    v547 = qcar(v547);
    v547 = list2(v310, v547);
    nil = C_nil;
    if (exception_pending()) goto v548;
    env = stack[-5];
    fn = elt(env, 38); /* rerror */
    v547 = (*qfnn(fn))(qenv(fn), 3, stack[-4], stack[0], v547);
    nil = C_nil;
    if (exception_pending()) goto v548;
    env = stack[-5];
    goto v196;

v244:
    v311 = stack[-3];
    v310 = stack[-2];
    v547 = stack[-1];
    fn = elt(env, 39); /* formrlis */
    v310 = (*qfnn(fn))(qenv(fn), 3, v311, v310, v547);
    nil = C_nil;
    if (exception_pending()) goto v548;
    env = stack[-5];
    v547 = stack[-1];
    {
        popv(6);
        fn = elt(env, 31); /* macrochk */
        return (*qfn2(fn))(qenv(fn), v310, v547);
    }

v434:
    v311 = stack[-3];
    v310 = stack[-2];
    v547 = stack[-1];
    {
        popv(6);
        fn = elt(env, 40); /* getvect */
        return (*qfnn(fn))(qenv(fn), 3, v311, v310, v547);
    }

v237:
    v547 = stack[-3];
    fn = elt(env, 41); /* lastpair */
    v547 = (*qfn1(fn))(qenv(fn), v547);
    nil = C_nil;
    if (exception_pending()) goto v548;
    env = stack[-5];
    v311 = qcar(v547);
    v310 = stack[-2];
    v547 = stack[-1];
    stack[-3] = v311;
    stack[-2] = v310;
    stack[-1] = v547;
    goto v11;

v7:
    v547 = stack[-3];
    if (!(symbolp(v547))) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v310 = stack[-3];
    v547 = elt(env, 1); /* ed */
    if (v310 == v547) goto v28;
    v310 = stack[-3];
    v547 = elt(env, 2); /* modefn */
    v547 = Lflagp(nil, v310, v547);
    env = stack[-5];
    if (v547 == nil) goto v51;
    v547 = stack[-3];
    {
        popv(6);
        fn = elt(env, 42); /* set!-global!-mode */
        return (*qfn1(fn))(qenv(fn), v547);
    }

v51:
    v310 = stack[-1];
    v547 = elt(env, 3); /* idfn */
    v547 = get(v310, v547);
    stack[-4] = v547;
    if (v547 == nil) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v311 = stack[-4];
    v310 = stack[-3];
    v547 = stack[-2];
        popv(6);
        return Lapply2(nil, 3, v311, v310, v547);

v28:
    v547 = stack[-3];
    popv(6);
    return ncons(v547);
/* error exit handlers */
v548:
    popv(6);
    return nil;
}



/* Code for formc */

static Lisp_Object MS_CDECL CC_formc(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v16,
                         Lisp_Object v63, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v57, v72, v122, v58;
    Lisp_Object fn;
    argcheck(nargs, 3, "formc");
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
    v57 = qvalue(elt(env, 1)); /* !*rlisp88 */
    if (v57 == nil) goto v31;
    v72 = stack[-2];
    v57 = elt(env, 2); /* modefn */
    v57 = Lflagpcar(nil, v72, v57);
    env = stack[-3];
    if (v57 == nil) goto v31;
    v57 = stack[-2];
    v72 = qcar(v57);
    v57 = elt(env, 3); /* symbolic */
    if (v72 == v57) goto v31;
    v72 = elt(env, 4); /* "algebraic expression" */
    v57 = elt(env, 5); /* "Rlisp88 form" */
    {
        popv(4);
        fn = elt(env, 7); /* typerr */
        return (*qfn2(fn))(qenv(fn), v72, v57);
    }

v31:
    v72 = stack[0];
    v57 = elt(env, 6); /* algebraic */
    if (!(v72 == v57)) goto v150;
    v72 = stack[-2];
    v57 = stack[-1];
    fn = elt(env, 8); /* intexprnp */
    v57 = (*qfn2(fn))(qenv(fn), v72, v57);
    nil = C_nil;
    if (exception_pending()) goto v59;
    env = stack[-3];
    if (!(v57 == nil)) { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }

v150:
    v58 = stack[-2];
    v122 = stack[-1];
    v72 = elt(env, 3); /* symbolic */
    v57 = stack[0];
    {
        popv(4);
        fn = elt(env, 9); /* convertmode */
        return (*qfnn(fn))(qenv(fn), 4, v58, v122, v72, v57);
    }
/* error exit handlers */
v59:
    popv(4);
    return nil;
}



/* Code for getrtype1 */

static Lisp_Object CC_getrtype1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v9;
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v9 = v0;
/* end of prologue */
    v9 = nil;
    return onevalue(v9);
}



/* Code for command1 */

static Lisp_Object MS_CDECL CC_command1(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v5;
    Lisp_Object fn;
    argcheck(nargs, 0, "command1");
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* end of prologue */
    fn = elt(env, 3); /* scan */
    v5 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v6;
    env = stack[0];
    fn = elt(env, 4); /* setcloc!* */
    v5 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v6;
    env = stack[0];
    v5 = qvalue(elt(env, 1)); /* cursym!* */
    qvalue(elt(env, 2)) = v5; /* key!* */
    v5 = nil;
    {
        popv(1);
        fn = elt(env, 5); /* xread1 */
        return (*qfn1(fn))(qenv(fn), v5);
    }
/* error exit handlers */
v6:
    popv(1);
    return nil;
}



/* Code for convertmode1 */

static Lisp_Object MS_CDECL CC_convertmode1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v16,
                         Lisp_Object v63, Lisp_Object v9, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v139, v140, v136, v233, v231, v218, v219;
    Lisp_Object fn;
    argcheck(nargs, 4, "convertmode1");
    if (stack >= stacklimit)
    {
        push4(v9,v63,v16,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v16,v63,v9);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v136 = v9;
    v233 = v63;
    v231 = v16;
    v218 = v0;
/* end of prologue */
    v140 = v136;
    v139 = elt(env, 1); /* real */
    if (!(v140 == v139)) goto v43;
    v139 = elt(env, 2); /* algebraic */
    v136 = v139;
    goto v43;

v43:
    v140 = v233;
    v139 = elt(env, 1); /* real */
    if (!(v140 == v139)) goto v53;
    v139 = elt(env, 2); /* algebraic */
    v233 = v139;
    goto v53;

v53:
    v140 = v233;
    v139 = v136;
    if (v140 == v139) { popv(1); return onevalue(v218); }
    v139 = v218;
    if (!(symbolp(v139))) goto v112;
    v140 = v218;
    v139 = v231;
    v139 = Latsoc(nil, v140, v139);
    v219 = v139;
    if (v139 == nil) goto v112;
    v139 = v219;
    v140 = qcdr(v139);
    v139 = elt(env, 3); /* (integer scalar real) */
    v139 = Lmemq(nil, v140, v139);
    if (!(v139 == nil)) goto v112;
    v139 = v219;
    v140 = qcdr(v139);
    v139 = v136;
    if (v140 == v139) goto v112;
    v139 = v218;
    v140 = v231;
    v136 = v233;
    v233 = v219;
    v233 = qcdr(v233);
    {
        popv(1);
        fn = elt(env, 4); /* convertmode */
        return (*qfnn(fn))(qenv(fn), 4, v139, v140, v136, v233);
    }

v112:
    v140 = v136;
    v139 = v233;
    v139 = get(v140, v139);
    env = stack[0];
    v219 = v139;
    if (v139 == nil) goto v456;
    v139 = v219;
    v140 = v218;
    v136 = v231;
        popv(1);
        return Lapply2(nil, 3, v139, v140, v136);

v456:
    v139 = v136;
    v140 = v233;
    fn = elt(env, 5); /* typerr */
    v139 = (*qfn2(fn))(qenv(fn), v139, v140);
    nil = C_nil;
    if (exception_pending()) goto v91;
    v139 = nil;
    { popv(1); return onevalue(v139); }
/* error exit handlers */
v91:
    popv(1);
    return nil;
}



/* Code for !*s2arg */

static Lisp_Object CC_Hs2arg(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v145, v146, v142;
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
    stack[-3] = v16;
    v146 = v0;
/* end of prologue */
    v145 = v146;
    if (!consp(v145)) { popv(6); return onevalue(v146); }
    v145 = v146;
    v142 = qcar(v145);
    v145 = elt(env, 1); /* quote */
    if (v142 == v145) { popv(6); return onevalue(v146); }
    v145 = v146;
    v145 = qcar(v145);
    if (!(symbolp(v145))) goto v28;
    v145 = v146;
    v142 = qcar(v145);
    v145 = elt(env, 2); /* nochange */
    v145 = Lflagp(nil, v142, v145);
    env = stack[-5];
    if (v145 == nil) goto v28;
    v145 = stack[-3];
    {
        popv(6);
        fn = elt(env, 3); /* mkarg */
        return (*qfn2(fn))(qenv(fn), v146, v145);
    }

v28:
    v145 = v146;
    stack[-4] = v145;
    v145 = stack[-4];
    if (v145 == nil) goto v48;
    v145 = stack[-4];
    v145 = qcar(v145);
    v146 = v145;
    v145 = stack[-3];
    v145 = CC_Hs2arg(env, v146, v145);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-5];
    v145 = ncons(v145);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-5];
    stack[-1] = v145;
    stack[-2] = v145;
    goto v31;

v31:
    v145 = stack[-4];
    v145 = qcdr(v145);
    stack[-4] = v145;
    v145 = stack[-4];
    if (v145 == nil) { Lisp_Object res = stack[-2]; popv(6); return onevalue(res); }
    stack[0] = stack[-1];
    v145 = stack[-4];
    v145 = qcar(v145);
    v146 = v145;
    v145 = stack[-3];
    v145 = CC_Hs2arg(env, v146, v145);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-5];
    v145 = ncons(v145);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-5];
    v145 = Lrplacd(nil, stack[0], v145);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-5];
    v145 = stack[-1];
    v145 = qcdr(v145);
    stack[-1] = v145;
    goto v31;

v48:
    v145 = nil;
    { popv(6); return onevalue(v145); }
/* error exit handlers */
v121:
    popv(6);
    return nil;
}



/* Code for quotofd */

static Lisp_Object CC_quotofd(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v69, v67;
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
    v69 = stack[-2];
    if (v69 == nil) goto v6;
    v69 = stack[-2];
    if (!consp(v69)) goto v47;
    v69 = stack[-2];
    v69 = qcar(v69);
    if (!consp(v69)) goto v47;
    v69 = stack[-2];
    v69 = qcar(v69);
    stack[0] = qcar(v69);
    v69 = stack[-2];
    v69 = qcar(v69);
    v67 = qcdr(v69);
    v69 = stack[-1];
    v67 = CC_quotofd(env, v67, v69);
    nil = C_nil;
    if (exception_pending()) goto v66;
    env = stack[-4];
    v69 = stack[-3];
    v69 = acons(stack[0], v67, v69);
    nil = C_nil;
    if (exception_pending()) goto v66;
    env = stack[-4];
    stack[-3] = v69;
    v69 = stack[-2];
    v69 = qcdr(v69);
    stack[-2] = v69;
    goto v12;

v47:
    stack[0] = stack[-3];
    v67 = stack[-2];
    v69 = stack[-1];
    fn = elt(env, 1); /* quotodd */
    v69 = (*qfn2(fn))(qenv(fn), v67, v69);
    nil = C_nil;
    if (exception_pending()) goto v66;
    env = stack[-4];
    {
        Lisp_Object v70 = stack[0];
        popv(5);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v70, v69);
    }

v6:
    v69 = stack[-3];
    {
        popv(5);
        fn = elt(env, 2); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v69);
    }
/* error exit handlers */
v66:
    popv(5);
    return nil;
}



/* Code for vmult */

static Lisp_Object CC_vmult(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v42, v49;
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
    v49 = (Lisp_Object)17; /* 1 */
    v42 = (Lisp_Object)17; /* 1 */
    v42 = cons(v49, v42);
    nil = C_nil;
    if (exception_pending()) goto v193;
    env = stack[-2];
    v42 = ncons(v42);
    nil = C_nil;
    if (exception_pending()) goto v193;
    env = stack[-2];
    v42 = ncons(v42);
    nil = C_nil;
    if (exception_pending()) goto v193;
    env = stack[-2];
    stack[-1] = v42;
    goto v4;

v4:
    v42 = stack[0];
    if (v42 == nil) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v42 = stack[0];
    v49 = qcar(v42);
    v42 = elt(env, 1); /* hvector */
    fn = elt(env, 2); /* nssimp */
    v49 = (*qfn2(fn))(qenv(fn), v49, v42);
    nil = C_nil;
    if (exception_pending()) goto v193;
    env = stack[-2];
    v42 = stack[-1];
    fn = elt(env, 3); /* vmult1 */
    v42 = (*qfn2(fn))(qenv(fn), v49, v42);
    nil = C_nil;
    if (exception_pending()) goto v193;
    env = stack[-2];
    stack[-1] = v42;
    v42 = stack[-1];
    if (v42 == nil) goto v32;
    v42 = stack[0];
    v42 = qcdr(v42);
    stack[0] = v42;
    goto v4;

v32:
    v42 = nil;
    { popv(3); return onevalue(v42); }
/* error exit handlers */
v193:
    popv(3);
    return nil;
}



/* Code for quotodd */

static Lisp_Object CC_quotodd(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v21, v22, v23;
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
    v22 = v16;
    v23 = v0;
/* end of prologue */
    v21 = v23;
    if (!(!consp(v21))) goto v15;
    v21 = v22;
    if (!(!consp(v21))) goto v15;
    v21 = v23;
    fn = elt(env, 1); /* mkrn */
    v21 = (*qfn2(fn))(qenv(fn), v21, v22);
    nil = C_nil;
    if (exception_pending()) goto v30;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* int!-equiv!-chk */
        return (*qfn1(fn))(qenv(fn), v21);
    }

v15:
    v21 = v23;
    {
        popv(1);
        fn = elt(env, 3); /* lowest!-terms */
        return (*qfn2(fn))(qenv(fn), v21, v22);
    }
/* error exit handlers */
v30:
    popv(1);
    return nil;
}



/* Code for rnonep!: */

static Lisp_Object CC_rnonepT(Lisp_Object env,
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
    v19 = (Lisp_Object)17; /* 1 */
    v19 = (v20 == v19 ? lisp_true : nil);
    return onevalue(v19);
}



/* Code for klistt */

static Lisp_Object CC_klistt(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v99, v10;
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
    stack[-1] = nil;
    goto v4;

v4:
    v99 = stack[0];
    if (!consp(v99)) goto v5;
    v99 = stack[0];
    v99 = qcar(v99);
    v10 = qcar(v99);
    v99 = stack[-1];
    v99 = cons(v10, v99);
    nil = C_nil;
    if (exception_pending()) goto v46;
    env = stack[-2];
    stack[-1] = v99;
    v10 = stack[0];
    v99 = elt(env, 1); /* list */
    fn = elt(env, 2); /* carx */
    v99 = (*qfn2(fn))(qenv(fn), v10, v99);
    nil = C_nil;
    if (exception_pending()) goto v46;
    env = stack[-2];
    v99 = qcdr(v99);
    stack[0] = v99;
    goto v4;

v5:
    v99 = stack[-1];
    {
        popv(3);
        fn = elt(env, 3); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v99);
    }
/* error exit handlers */
v46:
    popv(3);
    return nil;
}



/* Code for resimp */

static Lisp_Object CC_resimp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v12, v45;
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
    v45 = v0;
/* end of prologue */
    v12 = nil;
    stack[0] = qvalue(elt(env, 1)); /* varstack!* */
    qvalue(elt(env, 1)) = v12; /* varstack!* */
    v12 = v45;
    fn = elt(env, 2); /* resimp1 */
    v12 = (*qfn1(fn))(qenv(fn), v12);
    nil = C_nil;
    if (exception_pending()) goto v6;
    env = stack[-1];
    qvalue(elt(env, 1)) = stack[0]; /* varstack!* */
    { popv(2); return onevalue(v12); }
/* error exit handlers */
v6:
    env = stack[-1];
    qvalue(elt(env, 1)) = stack[0]; /* varstack!* */
    popv(2);
    return nil;
}



/* Code for mkkl */

static Lisp_Object CC_mkkl(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v19, v20, v21;
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
    v19 = v16;
    v20 = v0;
/* end of prologue */

v12:
    v21 = v20;
    if (v21 == nil) { popv(2); return onevalue(v19); }
    v21 = v20;
    v21 = qcdr(v21);
    stack[0] = v21;
    v20 = qcar(v20);
    v19 = cons(v20, v19);
    nil = C_nil;
    if (exception_pending()) goto v23;
    env = stack[-1];
    v19 = ncons(v19);
    nil = C_nil;
    if (exception_pending()) goto v23;
    env = stack[-1];
    v20 = stack[0];
    goto v12;
/* error exit handlers */
v23:
    popv(2);
    return nil;
}



/* Code for reordop */

static Lisp_Object CC_reordop(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v20, v21;
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
    v20 = qvalue(elt(env, 1)); /* !*ncmp */
    if (v20 == nil) goto v5;
    v20 = stack[-1];
    fn = elt(env, 2); /* noncomp1 */
    v20 = (*qfn1(fn))(qenv(fn), v20);
    nil = C_nil;
    if (exception_pending()) goto v30;
    env = stack[-2];
    if (v20 == nil) goto v1;
    v20 = stack[0];
    fn = elt(env, 2); /* noncomp1 */
    v20 = (*qfn1(fn))(qenv(fn), v20);
    nil = C_nil;
    if (exception_pending()) goto v30;
    env = stack[-2];
    goto v45;

v45:
    if (!(v20 == nil)) { popv(3); return onevalue(v20); }
    v21 = stack[-1];
    v20 = stack[0];
    {
        popv(3);
        fn = elt(env, 3); /* ordop */
        return (*qfn2(fn))(qenv(fn), v21, v20);
    }

v1:
    v20 = nil;
    goto v45;

v5:
    v20 = nil;
    goto v45;
/* error exit handlers */
v30:
    popv(3);
    return nil;
}



/* Code for xread1 */

static Lisp_Object CC_xread1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v646, v647, v648;
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
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-7] = v0;
/* end of prologue */
    stack[-8] = nil;
    stack[-6] = nil;
    stack[-5] = nil;
    stack[-4] = nil;
    stack[-2] = nil;
    stack[-1] = nil;
    v646 = qvalue(elt(env, 1)); /* commentlist!* */
    if (v646 == nil) goto v1;
    v646 = qvalue(elt(env, 1)); /* commentlist!* */
    stack[-1] = v646;
    v646 = nil;
    qvalue(elt(env, 1)) = v646; /* commentlist!* */
    goto v1;

v1:
    v646 = qvalue(elt(env, 2)); /* cursym!* */
    stack[-3] = v646;
    goto v2;

v2:
    v646 = stack[-3];
    if (!(symbolp(v646))) goto v25;
    v647 = stack[-3];
    v646 = elt(env, 3); /* !*lpar!* */
    if (v647 == v646) goto v26;
    v647 = stack[-3];
    v646 = elt(env, 4); /* !*rpar!* */
    if (v647 == v646) goto v28;
    v647 = stack[-3];
    v646 = elt(env, 5); /* infix */
    v646 = get(v647, v646);
    env = stack[-9];
    stack[-4] = v646;
    if (!(v646 == nil)) goto v38;
    v647 = stack[-3];
    v646 = elt(env, 6); /* delim */
    v646 = Lflagp(nil, v647, v646);
    env = stack[-9];
    if (v646 == nil) goto v104;
    v647 = qvalue(elt(env, 2)); /* cursym!* */
    v646 = elt(env, 44); /* !*semicol!* */
    if (v647 == v646) goto v649;
    fn = elt(env, 52); /* eolcheck */
    v646 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v650;
    env = stack[-9];
    goto v649;

v649:
    v647 = stack[-3];
    v646 = elt(env, 45); /* !*colon!* */
    if (!(v647 == v646)) goto v651;
    v647 = stack[-7];
    v646 = elt(env, 46); /* for */
    if (v647 == v646) goto v651;
    v646 = qvalue(elt(env, 47)); /* !*blockp */
    if (v646 == nil) goto v652;
    v646 = stack[-6];
    if (v646 == nil) goto v652;
    v646 = stack[-6];
    v646 = qcar(v646);
    if (!(!consp(v646))) goto v652;
    v646 = stack[-6];
    v646 = qcdr(v646);
    if (!(v646 == nil)) goto v652;

v651:
    v647 = stack[-3];
    v646 = elt(env, 48); /* nodel */
    v646 = Lflagp(nil, v647, v646);
    env = stack[-9];
    if (v646 == nil) goto v653;
    v646 = stack[-7];
    if (v646 == nil) goto v652;
    v647 = stack[-7];
    v646 = elt(env, 24); /* group */
    if (!(v647 == v646)) goto v653;
    v647 = stack[-3];
    v646 = elt(env, 49); /* (!*rsqbkt!* !*rcbkt!* !*rsqb!*) */
    v646 = Lmemq(nil, v647, v646);
    if (!(v646 == nil)) goto v653;

v652:
    v647 = elt(env, 23); /* "Improper delimiter" */
    v646 = nil;
    fn = elt(env, 53); /* symerr */
    v646 = (*qfn2(fn))(qenv(fn), v647, v646);
    nil = C_nil;
    if (exception_pending()) goto v650;
    env = stack[-9];
    goto v23;

v23:
    v646 = stack[-4];
    if (v646 == nil) goto v654;
    v647 = elt(env, 23); /* "Improper delimiter" */
    v646 = nil;
    fn = elt(env, 53); /* symerr */
    v646 = (*qfn2(fn))(qenv(fn), v647, v646);
    nil = C_nil;
    if (exception_pending()) goto v650;
    env = stack[-9];
    goto v655;

v655:
    v646 = (Lisp_Object)1; /* 0 */
    stack[-4] = v646;
    goto v43;

v43:
    v646 = stack[-6];
    if (!(v646 == nil)) goto v656;
    v647 = elt(env, 23); /* "Improper delimiter" */
    v646 = nil;
    fn = elt(env, 53); /* symerr */
    v646 = (*qfn2(fn))(qenv(fn), v647, v646);
    nil = C_nil;
    if (exception_pending()) goto v650;
    env = stack[-9];
    goto v656;

v656:
    v646 = stack[-6];
    v647 = qcar(v646);
    v646 = stack[-3];
    fn = elt(env, 54); /* mkvar */
    v646 = (*qfn2(fn))(qenv(fn), v647, v646);
    nil = C_nil;
    if (exception_pending()) goto v650;
    env = stack[-9];
    stack[0] = v646;
    goto v29;

v29:
    v646 = stack[-6];
    v646 = qcdr(v646);
    stack[-6] = v646;
    v646 = stack[-6];
    if (v646 == nil) goto v548;
    v646 = stack[-6];
    v646 = qcar(v646);
    if (!(!consp(v646))) goto v547;
    v646 = stack[-6];
    v646 = qcar(v646);
    if (symbolp(v646)) goto v547;
    v647 = elt(env, 29); /* "Missing operator" */
    v646 = nil;
    fn = elt(env, 53); /* symerr */
    v646 = (*qfn2(fn))(qenv(fn), v647, v646);
    nil = C_nil;
    if (exception_pending()) goto v650;
    env = stack[-9];
    goto v547;

v547:
    v646 = stack[-6];
    v647 = qcar(v646);
    v646 = stack[0];
    v646 = list2(v647, v646);
    nil = C_nil;
    if (exception_pending()) goto v650;
    env = stack[-9];
    stack[0] = v646;
    goto v29;

v548:
    v647 = stack[0];
    v646 = stack[-8];
    v646 = cons(v647, v646);
    nil = C_nil;
    if (exception_pending()) goto v650;
    env = stack[-9];
    stack[-8] = v646;
    goto v18;

v18:
    v646 = stack[-5];
    if (v646 == nil) goto v397;
    v647 = stack[-4];
    v646 = stack[-5];
    v646 = qcar(v646);
    v646 = qcar(v646);
    v646 = (Lisp_Object)lessp2(v647, v646);
    nil = C_nil;
    if (exception_pending()) goto v650;
    v646 = v646 ? lisp_true : nil;
    env = stack[-9];
    if (!(v646 == nil)) goto v657;
    v647 = stack[-4];
    v646 = stack[-5];
    v646 = qcar(v646);
    v646 = qcar(v646);
    if (!(equal(v647, v646))) goto v658;
    v647 = stack[-3];
    v646 = stack[-5];
    v646 = qcar(v646);
    v646 = qcdr(v646);
    if (!(v647 == v646)) goto v382;
    v647 = stack[-3];
    v646 = elt(env, 30); /* nary */
    v646 = Lflagp(nil, v647, v646);
    env = stack[-9];
    if (!(v646 == nil)) goto v382;
    v647 = stack[-3];
    v646 = elt(env, 31); /* right */
    v646 = Lflagp(nil, v647, v646);
    env = stack[-9];
    if (!(v646 == nil)) goto v382;

v657:
    v646 = stack[-8];
    v646 = qcdr(v646);
    v647 = qcar(v646);
    v646 = elt(env, 34); /* not */
    if (!consp(v647)) goto v659;
    v647 = qcar(v647);
    if (!(v647 == v646)) goto v659;
    v646 = stack[-5];
    v646 = qcar(v646);
    v648 = qcar(v646);
    v647 = elt(env, 35); /* member */
    v646 = elt(env, 5); /* infix */
    v646 = get(v647, v646);
    env = stack[-9];
    v646 = (Lisp_Object)geq2(v648, v646);
    nil = C_nil;
    if (exception_pending()) goto v650;
    v646 = v646 ? lisp_true : nil;
    env = stack[-9];
    if (v646 == nil) goto v659;
    v647 = elt(env, 36); /* "NOT" */
    v646 = elt(env, 37); /* "infix operator" */
    fn = elt(env, 55); /* typerr */
    v646 = (*qfn2(fn))(qenv(fn), v647, v646);
    nil = C_nil;
    if (exception_pending()) goto v650;
    env = stack[-9];
    goto v659;

v659:
    v646 = stack[-8];
    v646 = qcdr(v646);
    v647 = qcar(v646);
    v646 = elt(env, 28); /* !*!*un!*!* */
    if (v647 == v646) goto v660;
    v646 = stack[-5];
    v646 = qcar(v646);
    stack[0] = qcdr(v646);
    v646 = stack[-8];
    v647 = qcar(v646);
    v646 = stack[-5];
    v646 = qcar(v646);
    v646 = qcdr(v646);
    if (!consp(v647)) goto v661;
    v647 = qcar(v647);
    if (!(v647 == v646)) goto v661;
    v646 = stack[-5];
    v646 = qcar(v646);
    v647 = qcdr(v646);
    v646 = elt(env, 30); /* nary */
    v646 = Lflagp(nil, v647, v646);
    env = stack[-9];
    if (v646 == nil) goto v661;
    v646 = stack[-8];
    v646 = qcdr(v646);
    v647 = qcar(v646);
    v646 = stack[-8];
    v646 = qcar(v646);
    v646 = qcdr(v646);
    v646 = cons(v647, v646);
    nil = C_nil;
    if (exception_pending()) goto v650;
    env = stack[-9];
    goto v662;

v662:
    v646 = cons(stack[0], v646);
    nil = C_nil;
    if (exception_pending()) goto v650;
    env = stack[-9];
    stack[0] = v646;
    goto v663;

v663:
    v646 = stack[-5];
    v646 = qcdr(v646);
    stack[-5] = v646;
    v647 = stack[0];
    v646 = stack[-8];
    v646 = qcdr(v646);
    v646 = qcdr(v646);
    v646 = cons(v647, v646);
    nil = C_nil;
    if (exception_pending()) goto v650;
    env = stack[-9];
    stack[-8] = v646;
    goto v18;

v661:
    v646 = stack[-8];
    v646 = qcdr(v646);
    v647 = qcar(v646);
    v646 = stack[-8];
    v646 = qcar(v646);
    v646 = list2(v647, v646);
    nil = C_nil;
    if (exception_pending()) goto v650;
    env = stack[-9];
    goto v662;

v660:
    v646 = stack[-8];
    v647 = qcar(v646);
    v646 = elt(env, 28); /* !*!*un!*!* */
    if (v647 == v646) goto v658;
    v646 = stack[-5];
    v646 = qcar(v646);
    v647 = qcdr(v646);
    v646 = stack[-8];
    v646 = qcar(v646);
    v646 = list2(v647, v646);
    nil = C_nil;
    if (exception_pending()) goto v650;
    env = stack[-9];
    stack[0] = v646;
    goto v663;

v658:
    v648 = stack[-4];
    v647 = stack[-3];
    v646 = stack[-5];
    v646 = acons(v648, v647, v646);
    nil = C_nil;
    if (exception_pending()) goto v650;
    env = stack[-9];
    stack[-5] = v646;
    v647 = stack[-3];
    v646 = elt(env, 21); /* !*comma!* */
    if (!(v647 == v646)) goto v15;
    v646 = stack[-5];
    v646 = qcdr(v646);
    if (!(v646 == nil)) goto v24;
    v646 = stack[-7];
    if (v646 == nil) goto v24;
    v647 = stack[-7];
    v646 = elt(env, 33); /* (lambda paren) */
    v646 = Lmemq(nil, v647, v646);
    if (!(v646 == nil)) goto v24;
    v647 = stack[-7];
    v646 = elt(env, 19); /* struct */
    v646 = Lflagp(nil, v647, v646);
    env = stack[-9];
    if (!(v646 == nil)) goto v24;

v30:
    v646 = stack[-8];
    v646 = qcdr(v646);
    if (v646 == nil) goto v664;
    v646 = elt(env, 51); /* "Please send hearn@rand.org your program!!" */
    v646 = Lprint(nil, v646);
    nil = C_nil;
    if (exception_pending()) goto v650;
    env = stack[-9];
    v647 = elt(env, 23); /* "Improper delimiter" */
    v646 = nil;
    fn = elt(env, 53); /* symerr */
    v646 = (*qfn2(fn))(qenv(fn), v647, v646);
    nil = C_nil;
    if (exception_pending()) goto v650;
    v646 = nil;
    { popv(10); return onevalue(v646); }

v664:
    v646 = stack[-8];
    v647 = qcar(v646);
    v646 = stack[-1];
    {
        popv(10);
        fn = elt(env, 56); /* xcomment */
        return (*qfn2(fn))(qenv(fn), v647, v646);
    }

v24:
    fn = elt(env, 57); /* scan */
    v646 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v650;
    env = stack[-9];
    stack[-3] = v646;
    goto v2;

v15:
    v646 = stack[-2];
    stack[-3] = v646;
    goto v2;

v382:
    v646 = stack[-5];
    v646 = qcar(v646);
    v647 = qcdr(v646);
    v646 = elt(env, 32); /* alt */
    v646 = get(v647, v646);
    env = stack[-9];
    if (v646 == nil) goto v658;
    else goto v657;

v397:
    v647 = stack[-4];
    v646 = (Lisp_Object)1; /* 0 */
    if (v647 == v646) goto v30;
    else goto v658;

v654:
    v646 = stack[-8];
    if (!(v646 == nil)) goto v655;
    v646 = stack[-6];
    if (!(v646 == nil)) goto v655;
    v646 = stack[-5];
    if (!(v646 == nil)) goto v655;
    v647 = nil;
    v646 = stack[-1];
    {
        popv(10);
        fn = elt(env, 56); /* xcomment */
        return (*qfn2(fn))(qenv(fn), v647, v646);
    }

v653:
    v646 = stack[-7];
    if (!(symbolp(v646))) goto v23;
    v647 = stack[-7];
    v646 = elt(env, 20); /* paren */
    if (v647 == v646) goto v665;
    v647 = stack[-7];
    v646 = elt(env, 19); /* struct */
    v646 = Lflagp(nil, v647, v646);
    env = stack[-9];
    if (v646 == nil) goto v23;
    else goto v665;

v665:
    v647 = elt(env, 50); /* "Too few right parentheses" */
    v646 = nil;
    fn = elt(env, 53); /* symerr */
    v646 = (*qfn2(fn))(qenv(fn), v647, v646);
    nil = C_nil;
    if (exception_pending()) goto v650;
    env = stack[-9];
    goto v23;

v104:
    v647 = stack[-3];
    v646 = elt(env, 7); /* stat */
    v646 = get(v647, v646);
    env = stack[-9];
    stack[-4] = v646;
    if (v646 == nil) goto v85;
    v647 = stack[-4];
    v646 = elt(env, 38); /* endstat */
    if (v647 == v646) goto v666;
    fn = elt(env, 52); /* eolcheck */
    v646 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v650;
    env = stack[-9];
    goto v666;

v666:
    v647 = stack[-3];
    v646 = elt(env, 39); /* go */
    v646 = Lflagp(nil, v647, v646);
    env = stack[-9];
    if (!(v646 == nil)) goto v667;
    v647 = stack[-7];
    v646 = elt(env, 17); /* proc */
    if (v647 == v646) goto v25;
    v647 = stack[-4];
    v646 = elt(env, 40); /* endstatfn */
    v646 = Lflagp(nil, v647, v646);
    env = stack[-9];
    if (!(v646 == nil)) goto v667;
    v646 = qvalue(elt(env, 12)); /* nxtsym!* */
    fn = elt(env, 58); /* delcp */
    v646 = (*qfn1(fn))(qenv(fn), v646);
    nil = C_nil;
    if (exception_pending()) goto v650;
    env = stack[-9];
    if (!(v646 == nil)) goto v25;
    v647 = qvalue(elt(env, 12)); /* nxtsym!* */
    v646 = elt(env, 41); /* !, */
    if (!(v647 == v646)) goto v667;

v25:
    v646 = nil;
    stack[-4] = v646;
    goto v231;

v231:
    v647 = stack[-3];
    v646 = stack[-6];
    v646 = cons(v647, v646);
    nil = C_nil;
    if (exception_pending()) goto v650;
    env = stack[-9];
    stack[-6] = v646;
    v646 = stack[-3];
    fn = elt(env, 59); /* toknump */
    v646 = (*qfn1(fn))(qenv(fn), v646);
    nil = C_nil;
    if (exception_pending()) goto v650;
    env = stack[-9];
    if (v646 == nil) goto v308;
    v647 = stack[-2];
    v646 = qvalue(elt(env, 11)); /* !$eol!$ */
    if (v647 == v646) goto v308;
    v646 = qvalue(elt(env, 12)); /* nxtsym!* */
    fn = elt(env, 60); /* chknewnam */
    v646 = (*qfn1(fn))(qenv(fn), v646);
    nil = C_nil;
    if (exception_pending()) goto v650;
    env = stack[-9];
    stack[-2] = v646;
    if (!(symbolp(v646))) goto v308;
    v647 = stack[-2];
    v646 = elt(env, 6); /* delim */
    v646 = Lflagp(nil, v647, v646);
    env = stack[-9];
    if (!(v646 == nil)) goto v308;
    v647 = stack[-2];
    v646 = elt(env, 13); /* switch!* */
    v646 = get(v647, v646);
    env = stack[-9];
    if (v646 == nil) goto v125;
    v647 = stack[-2];
    v646 = elt(env, 14); /* !( */
    if (!(v647 == v646)) goto v308;

v125:
    v647 = stack[-2];
    v646 = elt(env, 5); /* infix */
    v646 = get(v647, v646);
    env = stack[-9];
    if (!(v646 == nil)) goto v308;
    v646 = qvalue(elt(env, 15)); /* !*eoldelimp */
    if (v646 == nil) goto v79;
    v647 = stack[-2];
    v646 = qvalue(elt(env, 11)); /* !$eol!$ */
    if (!(v647 == v646)) goto v79;

v308:
    v647 = stack[-7];
    v646 = elt(env, 17); /* proc */
    if (!(v647 == v646)) goto v24;
    v646 = stack[-6];
    v647 = Llength(nil, v646);
    nil = C_nil;
    if (exception_pending()) goto v650;
    env = stack[-9];
    v646 = (Lisp_Object)33; /* 2 */
    v646 = (Lisp_Object)greaterp2(v647, v646);
    nil = C_nil;
    if (exception_pending()) goto v650;
    v646 = v646 ? lisp_true : nil;
    env = stack[-9];
    if (v646 == nil) goto v24;
    v647 = elt(env, 18); /* "Syntax error in procedure header" */
    v646 = nil;
    fn = elt(env, 53); /* symerr */
    v646 = (*qfn2(fn))(qenv(fn), v647, v646);
    nil = C_nil;
    if (exception_pending()) goto v650;
    env = stack[-9];
    goto v24;

v79:
    v646 = elt(env, 16); /* times */
    qvalue(elt(env, 2)) = v646; /* cursym!* */
    goto v1;

v667:
    v647 = stack[-3];
    v646 = elt(env, 42); /* procedure */
    if (!(v647 == v646)) goto v668;
    v646 = qvalue(elt(env, 8)); /* !*reduce4 */
    if (v646 == nil) goto v668;
    v646 = stack[-6];
    if (v646 == nil) goto v669;
    v646 = stack[-6];
    v646 = qcdr(v646);
    if (!(v646 == nil)) goto v670;
    v646 = qvalue(elt(env, 8)); /* !*reduce4 */
    if (!(v646 == nil)) goto v670;
    v646 = stack[-6];
    v646 = qcar(v646);
    fn = elt(env, 61); /* procstat1 */
    v646 = (*qfn1(fn))(qenv(fn), v646);
    nil = C_nil;
    if (exception_pending()) goto v650;
    env = stack[-9];
    v646 = ncons(v646);
    nil = C_nil;
    if (exception_pending()) goto v650;
    env = stack[-9];
    stack[-6] = v646;
    goto v671;

v671:
    v646 = nil;
    stack[-4] = v646;
    goto v1;

v670:
    v647 = elt(env, 43); /* "proc form" */
    v646 = nil;
    fn = elt(env, 53); /* symerr */
    v646 = (*qfn2(fn))(qenv(fn), v647, v646);
    nil = C_nil;
    if (exception_pending()) goto v650;
    env = stack[-9];
    goto v671;

v669:
    v646 = nil;
    fn = elt(env, 61); /* procstat1 */
    v646 = (*qfn1(fn))(qenv(fn), v646);
    nil = C_nil;
    if (exception_pending()) goto v650;
    env = stack[-9];
    v646 = ncons(v646);
    nil = C_nil;
    if (exception_pending()) goto v650;
    env = stack[-9];
    stack[-6] = v646;
    goto v671;

v668:
    v647 = stack[-4];
    v646 = nil;
    fn = elt(env, 62); /* lispapply */
    v647 = (*qfn2(fn))(qenv(fn), v647, v646);
    nil = C_nil;
    if (exception_pending()) goto v650;
    env = stack[-9];
    v646 = stack[-6];
    v646 = cons(v647, v646);
    nil = C_nil;
    if (exception_pending()) goto v650;
    env = stack[-9];
    stack[-6] = v646;
    goto v671;

v85:
    v646 = qvalue(elt(env, 8)); /* !*reduce4 */
    if (!(v646 == nil)) goto v25;
    v647 = stack[-3];
    v646 = elt(env, 9); /* type */
    v646 = Lflagp(nil, v647, v646);
    env = stack[-9];
    if (v646 == nil) goto v25;
    v647 = elt(env, 10); /* decstat */
    v646 = nil;
    fn = elt(env, 62); /* lispapply */
    v647 = (*qfn2(fn))(qenv(fn), v647, v646);
    nil = C_nil;
    if (exception_pending()) goto v650;
    env = stack[-9];
    v646 = stack[-6];
    v646 = cons(v647, v646);
    nil = C_nil;
    if (exception_pending()) goto v650;
    env = stack[-9];
    stack[-6] = v646;
    goto v1;

v38:
    fn = elt(env, 52); /* eolcheck */
    v646 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v650;
    env = stack[-9];
    v647 = stack[-3];
    v646 = elt(env, 21); /* !*comma!* */
    if (v647 == v646) goto v44;
    fn = elt(env, 57); /* scan */
    v646 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v650;
    env = stack[-9];
    stack[-2] = v646;
    if (!(!consp(v646))) goto v44;
    v646 = stack[-2];
    fn = elt(env, 59); /* toknump */
    v646 = (*qfn1(fn))(qenv(fn), v646);
    nil = C_nil;
    if (exception_pending()) goto v650;
    env = stack[-9];
    if (!(v646 == nil)) goto v44;
    v647 = stack[-2];
    v646 = elt(env, 4); /* !*rpar!* */
    if (v647 == v646) goto v47;
    v647 = stack[-2];
    v646 = elt(env, 21); /* !*comma!* */
    if (v647 == v646) goto v47;
    v647 = stack[-2];
    v646 = elt(env, 6); /* delim */
    v646 = Lflagp(nil, v647, v646);
    env = stack[-9];
    if (!(v646 == nil)) goto v47;
    v647 = stack[-2];
    v646 = elt(env, 3); /* !*lpar!* */
    if (!(v647 == v646)) goto v44;
    fn = elt(env, 52); /* eolcheck */
    v646 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v650;
    env = stack[-9];
    if (!(v646 == nil)) goto v44;
    v646 = elt(env, 20); /* paren */
    fn = elt(env, 63); /* xread */
    v646 = (*qfn1(fn))(qenv(fn), v646);
    nil = C_nil;
    if (exception_pending()) goto v650;
    env = stack[-9];
    stack[-2] = v646;
    if (!consp(v646)) goto v44;
    v646 = stack[-2];
    v647 = qcar(v646);
    v646 = elt(env, 21); /* !*comma!* */
    if (!(v647 == v646)) goto v44;
    v647 = stack[-3];
    v646 = stack[-2];
    v646 = qcdr(v646);
    v646 = cons(v647, v646);
    nil = C_nil;
    if (exception_pending()) goto v650;
    env = stack[-9];
    stack[-3] = v646;
    if (!(v646 == nil)) goto v2;

v44:
    v646 = stack[-6];
    if (!(v646 == nil)) goto v43;
    v647 = stack[-3];
    v646 = elt(env, 26); /* unary */
    v646 = get(v647, v646);
    env = stack[-9];
    stack[-3] = v646;
    if (!(v646 == nil)) goto v672;
    v647 = elt(env, 27); /* "Redundant operator" */
    v646 = nil;
    fn = elt(env, 53); /* symerr */
    v646 = (*qfn2(fn))(qenv(fn), v647, v646);
    nil = C_nil;
    if (exception_pending()) goto v650;
    env = stack[-9];
    goto v672;

v672:
    v647 = elt(env, 28); /* !*!*un!*!* */
    v646 = stack[-8];
    v646 = cons(v647, v646);
    nil = C_nil;
    if (exception_pending()) goto v650;
    env = stack[-9];
    stack[-8] = v646;
    goto v658;

v47:
    v646 = stack[-4];
    if (v646 == nil) goto v535;
    v646 = nil;
    stack[-4] = v646;
    goto v535;

v535:
    v647 = stack[-3];
    v646 = stack[-6];
    v646 = cons(v647, v646);
    nil = C_nil;
    if (exception_pending()) goto v650;
    env = stack[-9];
    stack[-6] = v646;
    goto v15;

v28:
    v646 = stack[-7];
    if (v646 == nil) goto v295;
    v647 = stack[-7];
    v646 = elt(env, 24); /* group */
    if (v647 == v646) goto v295;
    v647 = stack[-7];
    v646 = elt(env, 17); /* proc */
    if (!(v647 == v646)) goto v23;

v295:
    v647 = elt(env, 25); /* "Too many right parentheses" */
    v646 = nil;
    fn = elt(env, 53); /* symerr */
    v646 = (*qfn2(fn))(qenv(fn), v647, v646);
    nil = C_nil;
    if (exception_pending()) goto v650;
    env = stack[-9];
    goto v38;

v26:
    fn = elt(env, 52); /* eolcheck */
    v646 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v650;
    env = stack[-9];
    v646 = nil;
    stack[-4] = v646;
    fn = elt(env, 57); /* scan */
    v647 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v650;
    env = stack[-9];
    v646 = elt(env, 4); /* !*rpar!* */
    if (v647 == v646) goto v27;
    v647 = stack[-6];
    v646 = elt(env, 19); /* struct */
    v646 = Lflagpcar(nil, v647, v646);
    env = stack[-9];
    if (v646 == nil) goto v222;
    v646 = stack[-6];
    v646 = qcar(v646);
    v646 = CC_xread1(env, v646);
    nil = C_nil;
    if (exception_pending()) goto v650;
    env = stack[-9];
    stack[-3] = v646;
    goto v431;

v431:
    v647 = stack[-7];
    v646 = elt(env, 19); /* struct */
    v646 = Lflagp(nil, v647, v646);
    env = stack[-9];
    if (v646 == nil) goto v430;
    v646 = stack[-3];
    fn = elt(env, 64); /* remcomma */
    v646 = (*qfn1(fn))(qenv(fn), v646);
    nil = C_nil;
    if (exception_pending()) goto v650;
    env = stack[-9];
    stack[-3] = v646;
    goto v231;

v430:
    v647 = stack[-3];
    v646 = elt(env, 21); /* !*comma!* */
    if (!consp(v647)) goto v231;
    v647 = qcar(v647);
    if (!(v647 == v646)) goto v231;
    v646 = stack[-6];
    if (v646 == nil) goto v166;
    v646 = stack[-6];
    v648 = qcar(v646);
    v646 = stack[-3];
    v647 = qcdr(v646);
    v646 = stack[-6];
    v646 = qcdr(v646);
    v646 = acons(v648, v647, v646);
    nil = C_nil;
    if (exception_pending()) goto v650;
    env = stack[-9];
    stack[-6] = v646;
    goto v24;

v166:
    v647 = stack[-7];
    v646 = elt(env, 22); /* lambda */
    if (v647 == v646) goto v231;
    v647 = elt(env, 23); /* "Improper delimiter" */
    v646 = nil;
    fn = elt(env, 53); /* symerr */
    v646 = (*qfn2(fn))(qenv(fn), v647, v646);
    nil = C_nil;
    if (exception_pending()) goto v650;
    env = stack[-9];
    goto v24;

v222:
    v646 = elt(env, 20); /* paren */
    v646 = CC_xread1(env, v646);
    nil = C_nil;
    if (exception_pending()) goto v650;
    env = stack[-9];
    stack[-3] = v646;
    goto v431;

v27:
    v646 = stack[-6];
    if (v646 == nil) goto v24;
    v646 = stack[-6];
    v646 = qcar(v646);
    v647 = ncons(v646);
    nil = C_nil;
    if (exception_pending()) goto v650;
    env = stack[-9];
    v646 = stack[-6];
    v646 = qcdr(v646);
    v646 = cons(v647, v646);
    nil = C_nil;
    if (exception_pending()) goto v650;
    env = stack[-9];
    stack[-6] = v646;
    goto v24;
/* error exit handlers */
v650:
    popv(10);
    return nil;
}



/* Code for dfprintfn */

static Lisp_Object CC_dfprintfn(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v49, v50, v52;
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
    v49 = v0;
/* end of prologue */
    v50 = qvalue(elt(env, 1)); /* !*nat */
    if (v50 == nil) goto v3;
    v50 = qvalue(elt(env, 2)); /* !*fort */
    if (!(v50 == nil)) goto v3;
    v50 = qvalue(elt(env, 3)); /* !*dfprint */
    if (v50 == nil) goto v3;
    v50 = elt(env, 5); /* !!df!! */
    v49 = qcdr(v49);
    v52 = cons(v50, v49);
    nil = C_nil;
    if (exception_pending()) goto v193;
    env = stack[0];
    v50 = (Lisp_Object)1; /* 0 */
    v49 = nil;
    fn = elt(env, 6); /* layout!-formula */
    v49 = (*qfnn(fn))(qenv(fn), 3, v52, v50, v49);
    nil = C_nil;
    if (exception_pending()) goto v193;
    env = stack[0];
    v50 = v49;
    v49 = v50;
    if (v49 == nil) goto v31;
    v49 = v50;
    fn = elt(env, 7); /* putpline */
    v49 = (*qfn1(fn))(qenv(fn), v49);
    nil = C_nil;
    if (exception_pending()) goto v193;
    v49 = nil;
    { popv(1); return onevalue(v49); }

v31:
    v49 = elt(env, 4); /* failed */
    { popv(1); return onevalue(v49); }

v3:
    v49 = elt(env, 4); /* failed */
    { popv(1); return onevalue(v49); }
/* error exit handlers */
v193:
    popv(1);
    return nil;
}



/* Code for !*sqprint */

static Lisp_Object CC_Hsqprint(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v12;
    Lisp_Object fn;
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v12 = v0;
/* end of prologue */
    v12 = qcdr(v12);
    v12 = qcar(v12);
    {
        fn = elt(env, 1); /* sqprint */
        return (*qfn1(fn))(qenv(fn), v12);
    }
}



/* Code for depends */

static Lisp_Object CC_depends(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v109, v110, v215;
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
    v109 = stack[-1];
    if (v109 == nil) goto v4;
    v109 = stack[-1];
    if (is_number(v109)) goto v4;
    v109 = stack[0];
    if (is_number(v109)) goto v4;
    v110 = stack[-1];
    v109 = stack[0];
    if (equal(v110, v109)) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v109 = stack[-1];
    if (!(!consp(v109))) goto v32;
    v110 = stack[-1];
    v109 = qvalue(elt(env, 1)); /* frlis!* */
    v109 = Lmemq(nil, v110, v109);
    if (v109 == nil) goto v32;
    v109 = lisp_true;
    { popv(3); return onevalue(v109); }

v32:
    v110 = stack[-1];
    v109 = qvalue(elt(env, 2)); /* depl!* */
    v109 = Lassoc(nil, v110, v109);
    v110 = v109;
    v109 = v110;
    if (v109 == nil) goto v35;
    v109 = v110;
    v110 = qcdr(v109);
    v109 = stack[0];
    fn = elt(env, 5); /* ldepends */
    v109 = (*qfn2(fn))(qenv(fn), v110, v109);
    nil = C_nil;
    if (exception_pending()) goto v461;
    env = stack[-2];
    goto v193;

v193:
    if (v109 == nil) goto v31;
    v109 = lisp_true;
    { popv(3); return onevalue(v109); }

v31:
    v109 = stack[-1];
    if (!consp(v109)) goto v66;
    v109 = stack[-1];
    v109 = qcar(v109);
    if (!(symbolp(v109))) goto v66;
    v109 = stack[-1];
    v110 = qcar(v109);
    v109 = elt(env, 3); /* dname */
    v109 = get(v110, v109);
    env = stack[-2];
    if (v109 == nil) goto v66;
    v109 = stack[-1];
    v110 = qcar(v109);
    v109 = elt(env, 4); /* domain!-depends!-fn */
    v109 = get(v110, v109);
    v110 = v109;
    v109 = v110;
    if (v109 == nil) goto v192;
    v215 = v110;
    v110 = stack[-1];
    v109 = stack[0];
        popv(3);
        return Lapply2(nil, 3, v215, v110, v109);

v192:
    v109 = nil;
    { popv(3); return onevalue(v109); }

v66:
    v109 = stack[-1];
    if (!consp(v109)) goto v118;
    v109 = stack[-1];
    v110 = qcdr(v109);
    v109 = stack[0];
    fn = elt(env, 5); /* ldepends */
    v109 = (*qfn2(fn))(qenv(fn), v110, v109);
    nil = C_nil;
    if (exception_pending()) goto v461;
    env = stack[-2];
    if (!(v109 == nil)) goto v97;
    v109 = stack[-1];
    v110 = qcar(v109);
    v109 = stack[0];
    v109 = CC_depends(env, v110, v109);
    nil = C_nil;
    if (exception_pending()) goto v461;
    env = stack[-2];
    if (!(v109 == nil)) goto v97;

v118:
    v109 = stack[0];
    if (!consp(v109)) goto v115;
    v109 = stack[0];
    v109 = qcar(v109);
    if (!(symbolp(v109))) goto v92;
    v109 = stack[0];
    v110 = qcar(v109);
    v109 = elt(env, 3); /* dname */
    v109 = get(v110, v109);
    if (!(v109 == nil)) goto v115;

v92:
    v109 = nil;
    { popv(3); return onevalue(v109); }

v115:
    v109 = nil;
    { popv(3); return onevalue(v109); }

v97:
    v109 = lisp_true;
    { popv(3); return onevalue(v109); }

v35:
    v109 = nil;
    goto v193;

v4:
    v109 = nil;
    { popv(3); return onevalue(v109); }
/* error exit handlers */
v461:
    popv(3);
    return nil;
}



/* Code for rnequiv */

static Lisp_Object CC_rnequiv(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v38, v44, v47;
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v44 = v0;
/* end of prologue */
    v38 = v44;
    v38 = qcdr(v38);
    v44 = v38;
    v47 = qcdr(v38);
    v38 = (Lisp_Object)17; /* 1 */
    if (v47 == v38) goto v3;
    v38 = nil;
    return onevalue(v38);

v3:
    v38 = v44;
    v38 = qcar(v38);
    return onevalue(v38);
}



/* Code for quotdd */

static Lisp_Object CC_quotdd(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v234, v112, v120;
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
    v234 = stack[-1];
    if (!(!consp(v234))) goto v220;
    v234 = stack[0];
    if (!consp(v234)) goto v26;
    v234 = stack[0];
    v112 = qcar(v234);
    v234 = elt(env, 1); /* i2d */
    v234 = get(v112, v234);
    env = stack[-2];
    v112 = v234;
    if (v234 == nil) goto v36;
    v234 = stack[-1];
    v234 = Lapply1(nil, v112, v234);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-2];
    stack[-1] = v234;
    goto v220;

v220:
    v120 = stack[-1];
    v112 = stack[0];
    v234 = elt(env, 2); /* quotient */
    {
        popv(3);
        fn = elt(env, 3); /* dcombine */
        return (*qfnn(fn))(qenv(fn), 3, v120, v112, v234);
    }

v36:
    v234 = stack[0];
    if (!(!consp(v234))) goto v220;
    v234 = stack[-1];
    v112 = qcar(v234);
    v234 = elt(env, 1); /* i2d */
    v234 = get(v112, v234);
    env = stack[-2];
    v112 = v234;
    if (v234 == nil) goto v220;
    v234 = stack[0];
    v234 = Lapply1(nil, v112, v234);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-2];
    stack[0] = v234;
    goto v220;

v26:
    v112 = stack[-1];
    v234 = stack[0];
    v234 = Ldivide(nil, v112, v234);
    nil = C_nil;
    if (exception_pending()) goto v145;
    v112 = v234;
    v234 = v112;
    v120 = qcdr(v234);
    v234 = (Lisp_Object)1; /* 0 */
    if (v120 == v234) goto v17;
    v234 = nil;
    { popv(3); return onevalue(v234); }

v17:
    v234 = v112;
    v234 = qcar(v234);
    { popv(3); return onevalue(v234); }
/* error exit handlers */
v145:
    popv(3);
    return nil;
}



/* Code for macrochk */

static Lisp_Object CC_macrochk(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v70, v71, v101, v57;
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
    v70 = stack[-1];
    if (!consp(v70)) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v70 = stack[-1];
    v70 = qcar(v70);
    fn = elt(env, 4); /* expdrmacro */
    v70 = (*qfn1(fn))(qenv(fn), v70);
    nil = C_nil;
    if (exception_pending()) goto v58;
    env = stack[-2];
    v71 = v70;
    if (v70 == nil) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v101 = stack[0];
    v70 = elt(env, 1); /* symbolic */
    if (v101 == v70) goto v34;
    v70 = stack[-1];
    v70 = qcar(v70);
    if (!(symbolp(v70))) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v70 = stack[-1];
    v101 = qcar(v70);
    v70 = elt(env, 2); /* opfn */
    v70 = Lflagp(nil, v101, v70);
    env = stack[-2];
    if (v70 == nil) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    else goto v34;

v34:
    v70 = v71;
    v101 = qcar(v70);
    v70 = elt(env, 3); /* macrofn */
    v57 = get(v101, v70);
    v70 = v71;
    v101 = qcdr(v70);
    v70 = stack[-1];
    v71 = qcdr(v70);
    v70 = stack[-1];
    v70 = qcar(v70);
        popv(3);
        return Lapply3(nil, 4, v57, v101, v71, v70);
/* error exit handlers */
v58:
    popv(3);
    return nil;
}



/* Code for delasc */

static Lisp_Object CC_delasc(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v42, v49;
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
    goto v5;

v5:
    v42 = stack[0];
    if (v42 == nil) goto v45;
    v42 = stack[0];
    v42 = qcar(v42);
    if (!consp(v42)) goto v99;
    v49 = stack[-1];
    v42 = stack[0];
    v42 = qcar(v42);
    v42 = qcar(v42);
    v42 = Lneq(nil, v49, v42);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-3];
    if (!(v42 == nil)) goto v99;

v24:
    v42 = stack[0];
    v42 = qcdr(v42);
    stack[0] = v42;
    goto v5;

v99:
    v42 = stack[0];
    v49 = qcar(v42);
    v42 = stack[-2];
    v42 = cons(v49, v42);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-3];
    stack[-2] = v42;
    goto v24;

v45:
    v42 = stack[-2];
        popv(4);
        return Lnreverse(nil, v42);
/* error exit handlers */
v35:
    popv(4);
    return nil;
}



/* Code for resimp1 */

static Lisp_Object CC_resimp1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v21, v22;
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
    v21 = stack[0];
    v22 = qcar(v21);
    v21 = nil;
    fn = elt(env, 2); /* subf1 */
    stack[-1] = (*qfn2(fn))(qenv(fn), v22, v21);
    nil = C_nil;
    if (exception_pending()) goto v99;
    env = stack[-2];
    v21 = stack[0];
    v22 = qcdr(v21);
    v21 = nil;
    fn = elt(env, 2); /* subf1 */
    v21 = (*qfn2(fn))(qenv(fn), v22, v21);
    nil = C_nil;
    if (exception_pending()) goto v99;
    env = stack[-2];
    fn = elt(env, 3); /* quotsq */
    v21 = (*qfn2(fn))(qenv(fn), stack[-1], v21);
    nil = C_nil;
    if (exception_pending()) goto v99;
    env = stack[-2];
    stack[0] = v21;
    v21 = lisp_true;
    qvalue(elt(env, 1)) = v21; /* !*sub2 */
    { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
/* error exit handlers */
v99:
    popv(3);
    return nil;
}



/* Code for lispapply */

static Lisp_Object CC_lispapply(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v53, v14, v46;
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
    v14 = v16;
    v46 = v0;
/* end of prologue */
    v53 = v46;
    if (!consp(v53)) goto v20;
    stack[-1] = elt(env, 1); /* rlisp */
    stack[0] = (Lisp_Object)33; /* 2 */
    v53 = elt(env, 2); /* "Apply called with non-id arg" */
    v14 = v46;
    v53 = list2(v53, v14);
    nil = C_nil;
    if (exception_pending()) goto v37;
    env = stack[-2];
    {
        Lisp_Object v36 = stack[-1];
        Lisp_Object v48 = stack[0];
        popv(3);
        fn = elt(env, 3); /* rerror */
        return (*qfnn(fn))(qenv(fn), 3, v36, v48, v53);
    }

v20:
    v53 = v46;
    {
        popv(3);
        fn = elt(env, 4); /* apply */
        return (*qfn2(fn))(qenv(fn), v53, v14);
    }
/* error exit handlers */
v37:
    popv(3);
    return nil;
}



/* Code for ldepends */

static Lisp_Object CC_ldepends(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v48, v33;
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
    v48 = stack[-1];
    if (v48 == nil) goto v4;
    v48 = stack[-1];
    if (!consp(v48)) goto v2;
    v48 = stack[-1];
    v33 = qcar(v48);
    v48 = stack[0];
    fn = elt(env, 1); /* depends */
    v48 = (*qfn2(fn))(qenv(fn), v33, v48);
    nil = C_nil;
    if (exception_pending()) goto v49;
    env = stack[-2];
    if (!(v48 == nil)) { popv(3); return onevalue(v48); }
    v48 = stack[-1];
    v33 = qcdr(v48);
    v48 = stack[0];
    stack[-1] = v33;
    stack[0] = v48;
    goto v11;

v2:
    v33 = stack[-1];
    v48 = stack[0];
    {
        popv(3);
        fn = elt(env, 1); /* depends */
        return (*qfn2(fn))(qenv(fn), v33, v48);
    }

v4:
    v48 = nil;
    { popv(3); return onevalue(v48); }
/* error exit handlers */
v49:
    popv(3);
    return nil;
}



/* Code for setcloc!* */

static Lisp_Object MS_CDECL CC_setclocH(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v44, v47, v15;
    argcheck(nargs, 0, "setcloc*");
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* end of prologue */
    v44 = qvalue(elt(env, 1)); /* ifl!* */
    if (v44 == nil) goto v9;
    v44 = qvalue(elt(env, 1)); /* ifl!* */
    v15 = qcar(v44);
    v47 = (Lisp_Object)17; /* 1 */
    v44 = qvalue(elt(env, 2)); /* curline!* */
    v44 = list2star(v15, v47, v44);
    nil = C_nil;
    if (exception_pending()) goto v43;
    env = stack[0];
    goto v63;

v63:
    qvalue(elt(env, 3)) = v44; /* cloc!* */
    { popv(1); return onevalue(v44); }

v9:
    v44 = nil;
    goto v63;
/* error exit handlers */
v43:
    popv(1);
    return nil;
}



setup_type const u05_setup[] =
{
    {"comfac",                  CC_comfac,      too_many_1,    wrong_no_1},
    {"ckrn",                    CC_ckrn,        too_many_1,    wrong_no_1},
    {"maprin",                  CC_maprin,      too_many_1,    wrong_no_1},
    {"rnconc",                  too_few_2,      CC_rnconc,     wrong_no_2},
    {"chknewnam",               CC_chknewnam,   too_many_1,    wrong_no_1},
    {"raddf",                   too_few_2,      CC_raddf,      wrong_no_2},
    {"getrmacro",               CC_getrmacro,   too_many_1,    wrong_no_1},
    {"comfac-to-poly",          CC_comfacKtoKpoly,too_many_1,  wrong_no_1},
    {"diffsq",                  too_few_2,      CC_diffsq,     wrong_no_2},
    {"expdrmacro",              CC_expdrmacro,  too_many_1,    wrong_no_1},
    {"xread",                   CC_xread,       too_many_1,    wrong_no_1},
    {"exptpri",                 too_few_2,      CC_exptpri,    wrong_no_2},
    {"algmodep",                CC_algmodep,    too_many_1,    wrong_no_1},
    {"simprecip",               CC_simprecip,   too_many_1,    wrong_no_1},
    {"addns",                   too_few_2,      CC_addns,      wrong_no_2},
    {"**a2i",                   too_few_2,      CC_HHa2i,      wrong_no_2},
    {"quotof",                  too_few_2,      CC_quotof,     wrong_no_2},
    {"form1",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_form1},
    {"formc",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_formc},
    {"getrtype1",               CC_getrtype1,   too_many_1,    wrong_no_1},
    {"command1",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_command1},
    {"convertmode1",            wrong_no_na,    wrong_no_nb,   (n_args *)CC_convertmode1},
    {"*s2arg",                  too_few_2,      CC_Hs2arg,     wrong_no_2},
    {"quotofd",                 too_few_2,      CC_quotofd,    wrong_no_2},
    {"vmult",                   CC_vmult,       too_many_1,    wrong_no_1},
    {"quotodd",                 too_few_2,      CC_quotodd,    wrong_no_2},
    {"rnonep:",                 CC_rnonepT,     too_many_1,    wrong_no_1},
    {"klistt",                  CC_klistt,      too_many_1,    wrong_no_1},
    {"resimp",                  CC_resimp,      too_many_1,    wrong_no_1},
    {"mkkl",                    too_few_2,      CC_mkkl,       wrong_no_2},
    {"reordop",                 too_few_2,      CC_reordop,    wrong_no_2},
    {"xread1",                  CC_xread1,      too_many_1,    wrong_no_1},
    {"dfprintfn",               CC_dfprintfn,   too_many_1,    wrong_no_1},
    {"*sqprint",                CC_Hsqprint,    too_many_1,    wrong_no_1},
    {"depends",                 too_few_2,      CC_depends,    wrong_no_2},
    {"rnequiv",                 CC_rnequiv,     too_many_1,    wrong_no_1},
    {"quotdd",                  too_few_2,      CC_quotdd,     wrong_no_2},
    {"macrochk",                too_few_2,      CC_macrochk,   wrong_no_2},
    {"delasc",                  too_few_2,      CC_delasc,     wrong_no_2},
    {"resimp1",                 CC_resimp1,     too_many_1,    wrong_no_1},
    {"lispapply",               too_few_2,      CC_lispapply,  wrong_no_2},
    {"ldepends",                too_few_2,      CC_ldepends,   wrong_no_2},
    {"setcloc*",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_setclocH},
    {NULL, (one_args *)"u05", (two_args *)"6759 7779058 9370293", 0}
};

/* end of generated code */
