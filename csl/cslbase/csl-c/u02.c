
/* $srcdir/../csl-c\u02.c Machine generated C code */

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


/* Code for subs2f1 */

static Lisp_Object CC_subs2f1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v310, v311, v312, v313, v314;
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
    v310 = stack[-7];
    if (!consp(v310)) goto v3;
    v310 = stack[-7];
    v310 = qcar(v310);
    if (!consp(v310)) goto v3;
    stack[-3] = nil;
    v310 = stack[-7];
    v310 = qcar(v310);
    v310 = qcar(v310);
    v310 = qcar(v310);
    stack[-8] = v310;
    v311 = nil;
    v310 = (Lisp_Object)17; /* 1 */
    v310 = cons(v311, v310);
    nil = C_nil;
    if (exception_pending()) goto v315;
    env = stack[-9];
    stack[-2] = v310;
    goto v15;

v15:
    v310 = stack[-7];
    if (v310 == nil) goto v43;
    v311 = stack[-7];
    v310 = stack[-8];
    fn = elt(env, 10); /* degr */
    v311 = (*qfn2(fn))(qenv(fn), v311, v310);
    nil = C_nil;
    if (exception_pending()) goto v315;
    env = stack[-9];
    v310 = (Lisp_Object)1; /* 0 */
    if (v311 == v310) goto v43;
    v310 = stack[-7];
    v311 = qcar(v310);
    v310 = stack[-3];
    v310 = cons(v311, v310);
    nil = C_nil;
    if (exception_pending()) goto v315;
    env = stack[-9];
    stack[-3] = v310;
    v310 = stack[-7];
    v310 = qcdr(v310);
    stack[-7] = v310;
    goto v15;

v43:
    v310 = qvalue(elt(env, 1)); /* powlis!* */
    stack[-4] = v310;
    goto v29;

v29:
    v310 = stack[-4];
    if (v310 == nil) goto v17;
    v310 = stack[-3];
    v310 = qcar(v310);
    v310 = qcar(v310);
    v311 = qcar(v310);
    v310 = stack[-4];
    v310 = qcar(v310);
    v310 = qcar(v310);
    if (equal(v311, v310)) goto v145;
    v311 = stack[-8];
    v310 = elt(env, 2); /* expt */
    if (!consp(v311)) goto v59;
    v311 = qcar(v311);
    if (!(v311 == v310)) goto v59;
    v310 = stack[-8];
    v310 = qcdr(v310);
    v311 = qcar(v310);
    v310 = stack[-4];
    v310 = qcar(v310);
    v310 = qcar(v310);
    if (!(equal(v311, v310))) goto v59;
    v310 = stack[-8];
    v310 = qcdr(v310);
    v310 = qcdr(v310);
    v311 = qcar(v310);
    v310 = elt(env, 3); /* quotient */
    if (!consp(v311)) goto v59;
    v311 = qcar(v311);
    if (!(v311 == v310)) goto v59;
    v310 = stack[-8];
    v310 = qcdr(v310);
    v310 = qcdr(v310);
    v310 = qcar(v310);
    v310 = qcdr(v310);
    v311 = qcar(v310);
    v310 = (Lisp_Object)17; /* 1 */
    if (!(v311 == v310)) goto v59;
    v310 = stack[-8];
    v310 = qcdr(v310);
    v310 = qcdr(v310);
    v310 = qcar(v310);
    v310 = qcdr(v310);
    v310 = qcdr(v310);
    v310 = qcar(v310);
    if (!(is_number(v310))) goto v59;
    v310 = stack[-3];
    v310 = qcar(v310);
    v310 = qcar(v310);
    v311 = qcdr(v310);
    v310 = stack[-8];
    v310 = qcdr(v310);
    v310 = qcdr(v310);
    v310 = qcar(v310);
    v310 = qcdr(v310);
    v310 = qcdr(v310);
    v310 = qcar(v310);
    v310 = Ldivide(nil, v311, v310);
    nil = C_nil;
    if (exception_pending()) goto v315;
    env = stack[-9];
    stack[-6] = v310;
    v310 = stack[-6];
    v311 = qcar(v310);
    v310 = (Lisp_Object)1; /* 0 */
    v310 = Lneq(nil, v311, v310);
    nil = C_nil;
    if (exception_pending()) goto v315;
    env = stack[-9];
    if (v310 == nil) goto v316;
    v310 = stack[-8];
    v310 = qcdr(v310);
    v310 = qcar(v310);
    fn = elt(env, 11); /* simp */
    v311 = (*qfn1(fn))(qenv(fn), v310);
    nil = C_nil;
    if (exception_pending()) goto v315;
    env = stack[-9];
    v310 = stack[-6];
    v310 = qcar(v310);
    fn = elt(env, 12); /* exptsq */
    v310 = (*qfn2(fn))(qenv(fn), v311, v310);
    nil = C_nil;
    if (exception_pending()) goto v315;
    env = stack[-9];
    stack[-5] = v310;
    goto v203;

v203:
    v310 = stack[-6];
    v311 = qcdr(v310);
    v310 = (Lisp_Object)1; /* 0 */
    v310 = Lneq(nil, v311, v310);
    nil = C_nil;
    if (exception_pending()) goto v315;
    env = stack[-9];
    if (v310 == nil) goto v317;
    stack[-1] = qvalue(elt(env, 4)); /* alglist!* */
    qvalue(elt(env, 4)) = nil; /* alglist!* */
    stack[0] = qvalue(elt(env, 5)); /* dmode!* */
    qvalue(elt(env, 5)) = nil; /* dmode!* */
    v310 = nil;
    v310 = ncons(v310);
    nil = C_nil;
    if (exception_pending()) goto v318;
    env = stack[-9];
    qvalue(elt(env, 4)) = v310; /* alglist!* */
    v310 = stack[-6];
    v311 = qcdr(v310);
    v310 = stack[-8];
    v310 = qcdr(v310);
    v310 = qcdr(v310);
    v310 = qcar(v310);
    v310 = qcdr(v310);
    v310 = qcdr(v310);
    v310 = qcar(v310);
    v310 = cons(v311, v310);
    nil = C_nil;
    if (exception_pending()) goto v318;
    env = stack[-9];
    fn = elt(env, 13); /* cancel */
    v310 = (*qfn1(fn))(qenv(fn), v310);
    nil = C_nil;
    if (exception_pending()) goto v318;
    env = stack[-9];
    stack[-6] = v310;
    qvalue(elt(env, 5)) = stack[0]; /* dmode!* */
    qvalue(elt(env, 4)) = stack[-1]; /* alglist!* */
    v310 = stack[-8];
    v310 = qcdr(v310);
    v311 = qcar(v310);
    v310 = stack[-6];
    v310 = qcar(v310);
    v312 = cons(v311, v310);
    nil = C_nil;
    if (exception_pending()) goto v315;
    env = stack[-9];
    v310 = stack[-4];
    v310 = qcar(v310);
    v310 = qcdr(v310);
    v311 = qcar(v310);
    v310 = stack[-4];
    v310 = qcar(v310);
    v310 = qcdr(v310);
    v310 = qcdr(v310);
    v310 = qcdr(v310);
    v310 = qcar(v310);
    fn = elt(env, 14); /* subs2p */
    v311 = (*qfnn(fn))(qenv(fn), 3, v312, v311, v310);
    nil = C_nil;
    if (exception_pending()) goto v315;
    env = stack[-9];
    v310 = stack[-6];
    v310 = qcdr(v310);
    fn = elt(env, 15); /* raddsq */
    v311 = (*qfn2(fn))(qenv(fn), v311, v310);
    nil = C_nil;
    if (exception_pending()) goto v315;
    env = stack[-9];
    v310 = stack[-5];
    fn = elt(env, 16); /* multsq */
    v310 = (*qfn2(fn))(qenv(fn), v311, v310);
    nil = C_nil;
    if (exception_pending()) goto v315;
    env = stack[-9];
    stack[-5] = v310;
    goto v317;

v317:
    stack[0] = stack[-5];
    v310 = stack[-3];
    v310 = qcar(v310);
    v310 = qcdr(v310);
    v310 = CC_subs2f1(env, v310);
    nil = C_nil;
    if (exception_pending()) goto v315;
    env = stack[-9];
    fn = elt(env, 16); /* multsq */
    v311 = (*qfn2(fn))(qenv(fn), stack[0], v310);
    nil = C_nil;
    if (exception_pending()) goto v315;
    env = stack[-9];
    v310 = stack[-2];
    fn = elt(env, 17); /* addsq */
    v310 = (*qfn2(fn))(qenv(fn), v311, v310);
    nil = C_nil;
    if (exception_pending()) goto v315;
    env = stack[-9];
    stack[-2] = v310;
    goto v20;

v20:
    v310 = stack[-3];
    v310 = qcdr(v310);
    stack[-3] = v310;
    v310 = stack[-3];
    if (!(v310 == nil)) goto v43;

v21:
    v310 = stack[-7];
    v310 = CC_subs2f1(env, v310);
    nil = C_nil;
    if (exception_pending()) goto v315;
    env = stack[-9];
    stack[-3] = v310;
    v310 = qvalue(elt(env, 8)); /* !*exp */
    if (!(v310 == nil)) goto v319;
    v310 = stack[-3];
    v310 = qcar(v310);
    fn = elt(env, 18); /* mkprod */
    stack[0] = (*qfn1(fn))(qenv(fn), v310);
    nil = C_nil;
    if (exception_pending()) goto v315;
    env = stack[-9];
    v310 = stack[-3];
    v310 = qcdr(v310);
    fn = elt(env, 18); /* mkprod */
    v310 = (*qfn1(fn))(qenv(fn), v310);
    nil = C_nil;
    if (exception_pending()) goto v315;
    env = stack[-9];
    v310 = cons(stack[0], v310);
    nil = C_nil;
    if (exception_pending()) goto v315;
    env = stack[-9];
    stack[-3] = v310;
    goto v319;

v319:
    v311 = stack[-2];
    v310 = stack[-3];
    {
        popv(10);
        fn = elt(env, 17); /* addsq */
        return (*qfn2(fn))(qenv(fn), v311, v310);
    }

v316:
    v311 = (Lisp_Object)17; /* 1 */
    v310 = (Lisp_Object)17; /* 1 */
    v310 = cons(v311, v310);
    nil = C_nil;
    if (exception_pending()) goto v315;
    env = stack[-9];
    stack[-5] = v310;
    goto v203;

v59:
    v310 = stack[-4];
    v310 = qcdr(v310);
    stack[-4] = v310;
    goto v29;

v145:
    v310 = stack[-3];
    v310 = qcar(v310);
    v312 = qcar(v310);
    v310 = stack[-4];
    v310 = qcar(v310);
    v310 = qcdr(v310);
    v311 = qcar(v310);
    v310 = stack[-4];
    v310 = qcar(v310);
    v310 = qcdr(v310);
    v310 = qcdr(v310);
    v310 = qcdr(v310);
    v310 = qcar(v310);
    fn = elt(env, 14); /* subs2p */
    v310 = (*qfnn(fn))(qenv(fn), 3, v312, v311, v310);
    nil = C_nil;
    if (exception_pending()) goto v315;
    env = stack[-9];
    stack[-5] = v310;
    goto v317;

v17:
    v310 = qvalue(elt(env, 6)); /* powlis1!* */
    stack[-4] = v310;
    goto v18;

v18:
    v310 = stack[-4];
    if (v310 == nil) goto v320;
    v310 = stack[-3];
    v310 = qcar(v310);
    v314 = qcar(v310);
    v310 = stack[-4];
    v310 = qcar(v310);
    v313 = qcar(v310);
    v310 = stack[-4];
    v310 = qcar(v310);
    v310 = qcdr(v310);
    v310 = qcdr(v310);
    v312 = qcar(v310);
    v310 = stack[-4];
    v310 = qcar(v310);
    v310 = qcdr(v310);
    v310 = qcar(v310);
    v311 = qcar(v310);
    v310 = stack[-4];
    v310 = qcar(v310);
    v310 = qcdr(v310);
    v310 = qcar(v310);
    v310 = qcdr(v310);
    fn = elt(env, 19); /* mtchp */
    v310 = (*qfnn(fn))(qenv(fn), 5, v314, v313, v312, v311, v310);
    nil = C_nil;
    if (exception_pending()) goto v315;
    env = stack[-9];
    stack[-5] = v310;
    if (!(v310 == nil)) goto v317;
    v310 = stack[-4];
    v310 = qcdr(v310);
    stack[-4] = v310;
    goto v18;

v320:
    v311 = stack[-8];
    v310 = elt(env, 2); /* expt */
    if (!consp(v311)) goto v321;
    v311 = qcar(v311);
    if (!(v311 == v310)) goto v321;
    v310 = qvalue(elt(env, 7)); /* !*structure */
    if (!(v310 == nil)) goto v321;

v322:
    v310 = stack[-3];
    v310 = qcar(v310);
    v310 = qcar(v310);
    v311 = qcdr(v310);
    v310 = (Lisp_Object)17; /* 1 */
    if (!(v311 == v310)) goto v323;
    v310 = stack[-8];
    v310 = qcdr(v310);
    v311 = qcar(v310);
    v310 = elt(env, 2); /* expt */
    if (!consp(v311)) goto v324;
    v311 = qcar(v311);
    if (!(v311 == v310)) goto v324;

v323:
    v310 = stack[-8];
    v310 = qcdr(v310);
    stack[0] = qcar(v310);
    v312 = elt(env, 9); /* times */
    v310 = stack[-8];
    v310 = qcdr(v310);
    v310 = qcdr(v310);
    v311 = qcar(v310);
    v310 = stack[-3];
    v310 = qcar(v310);
    v310 = qcar(v310);
    v310 = qcdr(v310);
    v310 = list3(v312, v311, v310);
    nil = C_nil;
    if (exception_pending()) goto v315;
    env = stack[-9];
    v310 = list2(stack[0], v310);
    nil = C_nil;
    if (exception_pending()) goto v315;
    env = stack[-9];
    fn = elt(env, 20); /* simpexpt */
    v310 = (*qfn1(fn))(qenv(fn), v310);
    nil = C_nil;
    if (exception_pending()) goto v315;
    env = stack[-9];
    stack[-5] = v310;
    goto v325;

v325:
    stack[0] = stack[-5];
    v310 = stack[-3];
    v310 = qcar(v310);
    v310 = qcdr(v310);
    v310 = CC_subs2f1(env, v310);
    nil = C_nil;
    if (exception_pending()) goto v315;
    env = stack[-9];
    fn = elt(env, 16); /* multsq */
    v311 = (*qfn2(fn))(qenv(fn), stack[0], v310);
    nil = C_nil;
    if (exception_pending()) goto v315;
    env = stack[-9];
    v310 = stack[-2];
    fn = elt(env, 17); /* addsq */
    v310 = (*qfn2(fn))(qenv(fn), v311, v310);
    nil = C_nil;
    if (exception_pending()) goto v315;
    env = stack[-9];
    stack[-2] = v310;
    v310 = stack[-3];
    v310 = qcdr(v310);
    stack[-3] = v310;
    v310 = stack[-3];
    if (v310 == nil) goto v21;
    else goto v322;

v324:
    v311 = stack[-8];
    v310 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 21); /* mksq */
    v310 = (*qfn2(fn))(qenv(fn), v311, v310);
    nil = C_nil;
    if (exception_pending()) goto v315;
    env = stack[-9];
    stack[-5] = v310;
    goto v325;

v321:
    v310 = stack[-3];
    v310 = qcar(v310);
    v311 = qcar(v310);
    v310 = (Lisp_Object)17; /* 1 */
    v310 = cons(v311, v310);
    nil = C_nil;
    if (exception_pending()) goto v315;
    env = stack[-9];
    v311 = ncons(v310);
    nil = C_nil;
    if (exception_pending()) goto v315;
    env = stack[-9];
    v310 = (Lisp_Object)17; /* 1 */
    stack[0] = cons(v311, v310);
    nil = C_nil;
    if (exception_pending()) goto v315;
    env = stack[-9];
    v310 = stack[-3];
    v310 = qcar(v310);
    v310 = qcdr(v310);
    v310 = CC_subs2f1(env, v310);
    nil = C_nil;
    if (exception_pending()) goto v315;
    env = stack[-9];
    fn = elt(env, 16); /* multsq */
    v311 = (*qfn2(fn))(qenv(fn), stack[0], v310);
    nil = C_nil;
    if (exception_pending()) goto v315;
    env = stack[-9];
    v310 = stack[-2];
    fn = elt(env, 17); /* addsq */
    v310 = (*qfn2(fn))(qenv(fn), v311, v310);
    nil = C_nil;
    if (exception_pending()) goto v315;
    env = stack[-9];
    stack[-2] = v310;
    goto v20;

v3:
    v310 = stack[-7];
    {
        popv(10);
        fn = elt(env, 22); /* !*d2q */
        return (*qfn1(fn))(qenv(fn), v310);
    }
/* error exit handlers */
v318:
    env = stack[-9];
    qvalue(elt(env, 5)) = stack[0]; /* dmode!* */
    qvalue(elt(env, 4)) = stack[-1]; /* alglist!* */
    popv(10);
    return nil;
v315:
    popv(10);
    return nil;
}



/* Code for prepsq */

static Lisp_Object CC_prepsq(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v28, v38;
    Lisp_Object fn;
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v38 = v0;
/* end of prologue */
    v28 = v38;
    v28 = qcar(v28);
    if (v28 == nil) goto v3;
    v28 = elt(env, 1); /* prepf */
    {
        fn = elt(env, 2); /* sqform */
        return (*qfn2(fn))(qenv(fn), v38, v28);
    }

v3:
    v28 = (Lisp_Object)1; /* 0 */
    return onevalue(v28);
}



/* Code for update!-pline */

static Lisp_Object MS_CDECL CC_updateKpline(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v16,
                         Lisp_Object v63, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v109, v110, v215;
    argcheck(nargs, 3, "update-pline");
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
    v215 = v63;
    stack[-4] = v16;
    stack[-5] = v0;
/* end of prologue */
    v110 = stack[-5];
    v109 = (Lisp_Object)1; /* 0 */
    if (!(v110 == v109)) goto v29;
    v110 = stack[-4];
    v109 = (Lisp_Object)1; /* 0 */
    if (v110 == v109) { popv(8); return onevalue(v215); }
    else goto v29;

v29:
    v109 = v215;
    stack[-6] = v109;
    v109 = stack[-6];
    if (v109 == nil) goto v53;
    v109 = stack[-6];
    v109 = qcar(v109);
    stack[0] = v109;
    v109 = stack[0];
    v109 = qcar(v109);
    v109 = qcar(v109);
    v110 = qcar(v109);
    v109 = stack[-5];
    v215 = (Lisp_Object)(int32)((int32)v110 + (int32)v109 - TAG_FIXNUM);
    v109 = stack[0];
    v109 = qcar(v109);
    v109 = qcar(v109);
    v110 = qcdr(v109);
    v109 = stack[-5];
    v109 = (Lisp_Object)(int32)((int32)v110 + (int32)v109 - TAG_FIXNUM);
    v215 = cons(v215, v109);
    nil = C_nil;
    if (exception_pending()) goto v88;
    env = stack[-7];
    v109 = stack[0];
    v109 = qcar(v109);
    v110 = qcdr(v109);
    v109 = stack[-4];
    v110 = (Lisp_Object)(int32)((int32)v110 + (int32)v109 - TAG_FIXNUM);
    v109 = stack[0];
    v109 = qcdr(v109);
    v109 = acons(v215, v110, v109);
    nil = C_nil;
    if (exception_pending()) goto v88;
    env = stack[-7];
    v109 = ncons(v109);
    nil = C_nil;
    if (exception_pending()) goto v88;
    env = stack[-7];
    stack[-2] = v109;
    stack[-3] = v109;
    goto v23;

v23:
    v109 = stack[-6];
    v109 = qcdr(v109);
    stack[-6] = v109;
    v109 = stack[-6];
    if (v109 == nil) { Lisp_Object res = stack[-3]; popv(8); return onevalue(res); }
    stack[-1] = stack[-2];
    v109 = stack[-6];
    v109 = qcar(v109);
    stack[0] = v109;
    v109 = stack[0];
    v109 = qcar(v109);
    v109 = qcar(v109);
    v110 = qcar(v109);
    v109 = stack[-5];
    v215 = (Lisp_Object)(int32)((int32)v110 + (int32)v109 - TAG_FIXNUM);
    v109 = stack[0];
    v109 = qcar(v109);
    v109 = qcar(v109);
    v110 = qcdr(v109);
    v109 = stack[-5];
    v109 = (Lisp_Object)(int32)((int32)v110 + (int32)v109 - TAG_FIXNUM);
    v215 = cons(v215, v109);
    nil = C_nil;
    if (exception_pending()) goto v88;
    env = stack[-7];
    v109 = stack[0];
    v109 = qcar(v109);
    v110 = qcdr(v109);
    v109 = stack[-4];
    v110 = (Lisp_Object)(int32)((int32)v110 + (int32)v109 - TAG_FIXNUM);
    v109 = stack[0];
    v109 = qcdr(v109);
    v109 = acons(v215, v110, v109);
    nil = C_nil;
    if (exception_pending()) goto v88;
    env = stack[-7];
    v109 = ncons(v109);
    nil = C_nil;
    if (exception_pending()) goto v88;
    env = stack[-7];
    v109 = Lrplacd(nil, stack[-1], v109);
    nil = C_nil;
    if (exception_pending()) goto v88;
    env = stack[-7];
    v109 = stack[-2];
    v109 = qcdr(v109);
    stack[-2] = v109;
    goto v23;

v53:
    v109 = nil;
    { popv(8); return onevalue(v109); }
/* error exit handlers */
v88:
    popv(8);
    return nil;
}



/* Code for prepsqxx */

static Lisp_Object CC_prepsqxx(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v4;
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
    v4 = v0;
/* end of prologue */
    fn = elt(env, 1); /* prepsqx */
    v4 = (*qfn1(fn))(qenv(fn), v4);
    nil = C_nil;
    if (exception_pending()) goto v12;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* negnumberchk */
        return (*qfn1(fn))(qenv(fn), v4);
    }
/* error exit handlers */
v12:
    popv(1);
    return nil;
}



/* Code for simpminus */

static Lisp_Object CC_simpminus(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v1, v2;
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
    v1 = v0;
/* end of prologue */
    v2 = v1;
    v1 = elt(env, 1); /* minus */
    fn = elt(env, 2); /* carx */
    v1 = (*qfn2(fn))(qenv(fn), v2, v1);
    nil = C_nil;
    if (exception_pending()) goto v25;
    env = stack[0];
    fn = elt(env, 3); /* simp */
    v1 = (*qfn1(fn))(qenv(fn), v1);
    nil = C_nil;
    if (exception_pending()) goto v25;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 4); /* negsq */
        return (*qfn1(fn))(qenv(fn), v1);
    }
/* error exit handlers */
v25:
    popv(1);
    return nil;
}



/* Code for ordpa */

static Lisp_Object CC_ordpa(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v81, v97, v118, v135;
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
    v97 = v16;
    v118 = v0;
/* end of prologue */

v4:
    v81 = v118;
    if (v81 == nil) goto v5;
    v81 = v97;
    if (v81 == nil) goto v2;
    v81 = v118;
    v81 = Lsimple_vectorp(nil, v81);
    env = stack[0];
    if (v81 == nil) goto v27;
    v81 = v97;
    v81 = Lsimple_vectorp(nil, v81);
    env = stack[0];
    if (v81 == nil) goto v10;
    v81 = v118;
    {
        popv(1);
        fn = elt(env, 1); /* ordpv */
        return (*qfn2(fn))(qenv(fn), v81, v97);
    }

v10:
    v81 = v97;
    v81 = (consp(v81) ? nil : lisp_true);
    { popv(1); return onevalue(v81); }

v27:
    v81 = v118;
    if (!consp(v81)) goto v31;
    v81 = v97;
    if (!consp(v81)) goto v85;
    v81 = v118;
    v135 = qcar(v81);
    v81 = v97;
    v81 = qcar(v81);
    if (equal(v135, v81)) goto v141;
    v81 = v118;
    v81 = qcar(v81);
    v118 = v81;
    v81 = v97;
    v81 = qcar(v81);
    v97 = v81;
    goto v4;

v141:
    v81 = v118;
    v81 = qcdr(v81);
    v118 = v81;
    v81 = v97;
    v81 = qcdr(v81);
    v97 = v81;
    goto v4;

v85:
    v81 = lisp_true;
    { popv(1); return onevalue(v81); }

v31:
    v81 = v97;
    if (!consp(v81)) goto v33;
    v81 = nil;
    { popv(1); return onevalue(v81); }

v33:
    v81 = v118;
    if (is_number(v81)) goto v52;
    v81 = v97;
    if (symbolp(v81)) goto v72;
    v81 = v97;
    v81 = (is_number(v81) ? lisp_true : nil);
    { popv(1); return onevalue(v81); }

v72:
    v81 = v118;
        popv(1);
        return Lorderp(nil, v81, v97);

v52:
    v81 = v97;
    if (is_number(v81)) goto v100;
    v81 = nil;
    { popv(1); return onevalue(v81); }

v100:
    v81 = v118;
    v81 = (Lisp_Object)lessp2(v81, v97);
    nil = C_nil;
    if (exception_pending()) goto v119;
    v81 = v81 ? lisp_true : nil;
    v81 = (v81 == nil ? lisp_true : nil);
    { popv(1); return onevalue(v81); }

v2:
    v81 = lisp_true;
    { popv(1); return onevalue(v81); }

v5:
    v81 = v97;
    v81 = (v81 == nil ? lisp_true : nil);
    { popv(1); return onevalue(v81); }
/* error exit handlers */
v119:
    popv(1);
    return nil;
}



/* Code for setdiff */

static Lisp_Object CC_setdiff(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v20, v21;
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
    v20 = v0;
/* end of prologue */

v4:
    v21 = stack[0];
    if (v21 == nil) { popv(2); return onevalue(v20); }
    v21 = v20;
    if (v21 == nil) goto v1;
    v21 = stack[0];
    v21 = qcar(v21);
    v20 = Ldelete(nil, v21, v20);
    nil = C_nil;
    if (exception_pending()) goto v23;
    env = stack[-1];
    v21 = stack[0];
    v21 = qcdr(v21);
    stack[0] = v21;
    goto v4;

v1:
    v20 = nil;
    { popv(2); return onevalue(v20); }
/* error exit handlers */
v23:
    popv(2);
    return nil;
}



/* Code for subs2 */

static Lisp_Object CC_subs2(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v102, v95, v220;
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
    v95 = v0;
/* end of prologue */
    stack[-3] = nil;
    stack[-2] = nil;
    stack[-1] = nil;
    v102 = qvalue(elt(env, 1)); /* subfg!* */
    if (v102 == nil) { popv(5); return onevalue(v95); }
    v102 = qvalue(elt(env, 2)); /* !*sub2 */
    if (!(v102 == nil)) goto v25;
    v102 = qvalue(elt(env, 3)); /* powlis1!* */
    if (!(v102 == nil)) goto v25;

v6:
    v102 = v95;
    fn = elt(env, 8); /* exptchksq */
    v102 = (*qfn1(fn))(qenv(fn), v102);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-4];
    v95 = v102;
    v220 = elt(env, 4); /* slash */
    v102 = elt(env, 5); /* opmtch */
    v102 = get(v220, v102);
    env = stack[-4];
    stack[0] = v102;
    v102 = qvalue(elt(env, 6)); /* !*match */
    if (!(v102 == nil)) goto v53;
    v102 = stack[0];
    if (v102 == nil) { popv(5); return onevalue(v95); }
    else goto v53;

v53:
    v102 = v95;
    v102 = qcar(v102);
    if (v102 == nil) { popv(5); return onevalue(v95); }
    v102 = qvalue(elt(env, 7)); /* !*exp */
    if (!(v102 == nil)) goto v30;
    v102 = lisp_true;
    stack[-3] = v102;
    v102 = lisp_true;
    qvalue(elt(env, 7)) = v102; /* !*exp */
    v102 = v95;
    stack[-2] = v102;
    v102 = v95;
    fn = elt(env, 9); /* resimp */
    v102 = (*qfn1(fn))(qenv(fn), v102);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-4];
    v95 = v102;
    stack[-1] = v102;
    goto v30;

v30:
    v102 = v95;
    fn = elt(env, 10); /* subs3q */
    v102 = (*qfn1(fn))(qenv(fn), v102);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-4];
    v95 = v102;
    v102 = stack[-3];
    if (v102 == nil) goto v41;
    v102 = nil;
    qvalue(elt(env, 7)) = v102; /* !*exp */
    v220 = v95;
    v102 = stack[-1];
    if (!(equal(v220, v102))) goto v41;
    v102 = stack[-2];
    v95 = v102;
    goto v41;

v41:
    v102 = stack[0];
    if (v102 == nil) { popv(5); return onevalue(v95); }
    v102 = v95;
    fn = elt(env, 11); /* subs4q */
    v102 = (*qfn1(fn))(qenv(fn), v102);
    nil = C_nil;
    if (exception_pending()) goto v86;
    v95 = v102;
    { popv(5); return onevalue(v95); }

v25:
    v102 = v95;
    fn = elt(env, 12); /* subs2q */
    v102 = (*qfn1(fn))(qenv(fn), v102);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-4];
    v95 = v102;
    goto v6;
/* error exit handlers */
v86:
    popv(5);
    return nil;
}



/* Code for ordad */

static Lisp_Object CC_ordad(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v87, v66;
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
    goto v5;

v5:
    v87 = stack[0];
    if (v87 == nil) goto v46;
    v66 = stack[-1];
    v87 = stack[0];
    v87 = qcar(v87);
    fn = elt(env, 1); /* ordp */
    v87 = (*qfn2(fn))(qenv(fn), v66, v87);
    nil = C_nil;
    if (exception_pending()) goto v57;
    env = stack[-3];
    if (!(v87 == nil)) goto v46;
    v87 = stack[0];
    v66 = qcar(v87);
    v87 = stack[-2];
    v87 = cons(v66, v87);
    nil = C_nil;
    if (exception_pending()) goto v57;
    env = stack[-3];
    stack[-2] = v87;
    v87 = stack[0];
    v87 = qcdr(v87);
    stack[0] = v87;
    goto v5;

v46:
    v66 = stack[-1];
    v87 = stack[0];
    v87 = cons(v66, v87);
    nil = C_nil;
    if (exception_pending()) goto v57;
    env = stack[-3];
    stack[0] = v87;
    goto v49;

v49:
    v87 = stack[-2];
    if (v87 == nil) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v87 = stack[-2];
    v87 = qcdr(v87);
    stack[-1] = v87;
    v66 = stack[-2];
    v87 = stack[0];
    v87 = Lrplacd(nil, v66, v87);
    nil = C_nil;
    if (exception_pending()) goto v57;
    env = stack[-3];
    v87 = stack[-2];
    stack[0] = v87;
    v87 = stack[-1];
    stack[-2] = v87;
    goto v49;
/* error exit handlers */
v57:
    popv(4);
    return nil;
}



/* Code for noncomperm */

static Lisp_Object CC_noncomperm(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v223, v139, v140;
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
    v223 = stack[-4];
    if (v223 == nil) goto v3;
    v223 = stack[-4];
    stack[-5] = v223;
    goto v24;

v24:
    v223 = stack[-5];
    if (v223 == nil) goto v44;
    v223 = stack[-5];
    v223 = qcar(v223);
    stack[0] = v223;
    v139 = stack[0];
    v223 = stack[-4];
    fn = elt(env, 2); /* noncomdel */
    v223 = (*qfn2(fn))(qenv(fn), v139, v223);
    nil = C_nil;
    if (exception_pending()) goto v235;
    env = stack[-6];
    v140 = v223;
    v139 = v140;
    v223 = elt(env, 1); /* failed */
    if (v139 == v223) goto v31;
    v223 = v140;
    v139 = CC_noncomperm(env, v223);
    nil = C_nil;
    if (exception_pending()) goto v235;
    env = stack[-6];
    v223 = stack[0];
    fn = elt(env, 3); /* mapcons */
    v223 = (*qfn2(fn))(qenv(fn), v139, v223);
    nil = C_nil;
    if (exception_pending()) goto v235;
    env = stack[-6];
    goto v46;

v46:
    stack[-3] = v223;
    v223 = stack[-3];
    fn = elt(env, 4); /* lastpair */
    v223 = (*qfn1(fn))(qenv(fn), v223);
    nil = C_nil;
    if (exception_pending()) goto v235;
    env = stack[-6];
    stack[-2] = v223;
    v223 = stack[-5];
    v223 = qcdr(v223);
    stack[-5] = v223;
    v223 = stack[-2];
    if (!consp(v223)) goto v24;
    else goto v26;

v26:
    v223 = stack[-5];
    if (v223 == nil) { Lisp_Object res = stack[-3]; popv(7); return onevalue(res); }
    stack[-1] = stack[-2];
    v223 = stack[-5];
    v223 = qcar(v223);
    stack[0] = v223;
    v139 = stack[0];
    v223 = stack[-4];
    fn = elt(env, 2); /* noncomdel */
    v223 = (*qfn2(fn))(qenv(fn), v139, v223);
    nil = C_nil;
    if (exception_pending()) goto v235;
    env = stack[-6];
    v140 = v223;
    v139 = v140;
    v223 = elt(env, 1); /* failed */
    if (v139 == v223) goto v226;
    v223 = v140;
    v139 = CC_noncomperm(env, v223);
    nil = C_nil;
    if (exception_pending()) goto v235;
    env = stack[-6];
    v223 = stack[0];
    fn = elt(env, 3); /* mapcons */
    v223 = (*qfn2(fn))(qenv(fn), v139, v223);
    nil = C_nil;
    if (exception_pending()) goto v235;
    env = stack[-6];
    goto v59;

v59:
    v223 = Lrplacd(nil, stack[-1], v223);
    nil = C_nil;
    if (exception_pending()) goto v235;
    env = stack[-6];
    v223 = stack[-2];
    fn = elt(env, 4); /* lastpair */
    v223 = (*qfn1(fn))(qenv(fn), v223);
    nil = C_nil;
    if (exception_pending()) goto v235;
    env = stack[-6];
    stack[-2] = v223;
    v223 = stack[-5];
    v223 = qcdr(v223);
    stack[-5] = v223;
    goto v26;

v226:
    v223 = nil;
    goto v59;

v31:
    v223 = nil;
    goto v46;

v44:
    v223 = nil;
    { popv(7); return onevalue(v223); }

v3:
    v223 = stack[-4];
    popv(7);
    return ncons(v223);
/* error exit handlers */
v235:
    popv(7);
    return nil;
}



/* Code for exc */

static Lisp_Object CC_exc(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v25, v13;
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v25 = v16;
    v13 = v0;
/* end of prologue */
    v13 = qcdr(v13);
    if (v13 == nil) return onevalue(v25);
    v25 = (v25 == nil ? lisp_true : nil);
    return onevalue(v25);
}



/* Code for mk!*sq */

static Lisp_Object CC_mkHsq(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v72, v122;
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
    v72 = v0;
/* end of prologue */
    fn = elt(env, 5); /* expchk */
    v72 = (*qfn1(fn))(qenv(fn), v72);
    nil = C_nil;
    if (exception_pending()) goto v65;
    env = stack[-2];
    stack[0] = v72;
    v72 = stack[0];
    v72 = qcar(v72);
    if (v72 == nil) goto v45;
    v72 = stack[0];
    v72 = qcar(v72);
    if (!(!consp(v72))) goto v2;
    v72 = stack[0];
    v122 = qcdr(v72);
    v72 = (Lisp_Object)17; /* 1 */
    if (!(v122 == v72)) goto v2;
    v72 = stack[0];
    v72 = qcar(v72);
    { popv(3); return onevalue(v72); }

v2:
    v72 = stack[0];
    fn = elt(env, 6); /* kernp */
    v72 = (*qfn1(fn))(qenv(fn), v72);
    nil = C_nil;
    if (exception_pending()) goto v65;
    env = stack[-2];
    if (v72 == nil) goto v40;
    v72 = stack[0];
    v72 = qcar(v72);
    v72 = qcar(v72);
    v72 = qcar(v72);
    v122 = qcar(v72);
    v72 = elt(env, 1); /* list */
    if (!consp(v122)) goto v40;
    v122 = qcar(v122);
    if (!(v122 == v72)) goto v40;
    v72 = stack[0];
    v72 = qcar(v72);
    v72 = qcar(v72);
    v72 = qcar(v72);
    v72 = qcar(v72);
    { popv(3); return onevalue(v72); }

v40:
    stack[-1] = elt(env, 2); /* !*sq */
    v72 = qvalue(elt(env, 3)); /* !*resubs */
    if (v72 == nil) goto v70;
    v72 = qvalue(elt(env, 4)); /* !*sqvar!* */
    goto v150;

v150:
    {
        Lisp_Object v103 = stack[-1];
        Lisp_Object v59 = stack[0];
        popv(3);
        return list2star(v103, v59, v72);
    }

v70:
    v72 = nil;
    v72 = ncons(v72);
    nil = C_nil;
    if (exception_pending()) goto v65;
    goto v150;

v45:
    v72 = (Lisp_Object)1; /* 0 */
    { popv(3); return onevalue(v72); }
/* error exit handlers */
v65:
    popv(3);
    return nil;
}



/* Code for negf */

static Lisp_Object CC_negf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v102, v95;
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
    v102 = stack[-1];
    if (v102 == nil) goto v5;
    v102 = stack[-1];
    if (!consp(v102)) goto v44;
    v102 = stack[-1];
    v102 = qcar(v102);
    if (!consp(v102)) goto v44;
    v102 = stack[-1];
    v102 = qcar(v102);
    stack[0] = qcar(v102);
    v102 = stack[-1];
    v102 = qcar(v102);
    v102 = qcdr(v102);
    v95 = CC_negf(env, v102);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-3];
    v102 = stack[-2];
    v102 = acons(stack[0], v95, v102);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-3];
    stack[-2] = v102;
    v102 = stack[-1];
    v102 = qcdr(v102);
    stack[-1] = v102;
    goto v4;

v44:
    stack[0] = stack[-2];
    v102 = stack[-1];
    if (!(!consp(v102))) goto v100;
    v95 = qvalue(elt(env, 1)); /* dmode!* */
    v102 = elt(env, 2); /* convert */
    v102 = Lflagp(nil, v95, v102);
    env = stack[-3];
    if (v102 == nil) goto v100;
    v95 = qvalue(elt(env, 1)); /* dmode!* */
    v102 = elt(env, 3); /* i2d */
    v95 = get(v95, v102);
    env = stack[-3];
    v102 = stack[-1];
    v102 = Lapply1(nil, v95, v102);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-3];
    goto v20;

v20:
    fn = elt(env, 4); /* !:minus */
    v102 = (*qfn1(fn))(qenv(fn), v102);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-3];
    {
        Lisp_Object v85 = stack[0];
        popv(4);
        fn = elt(env, 5); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v85, v102);
    }

v100:
    v102 = stack[-1];
    goto v20;

v5:
    v102 = stack[-2];
    {
        popv(4);
        fn = elt(env, 5); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v102);
    }
/* error exit handlers */
v62:
    popv(4);
    return nil;
}



/* Code for simp!* */

static Lisp_Object CC_simpH(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v231, v218;
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
    stack[-3] = qvalue(elt(env, 1)); /* !*asymp!* */
    qvalue(elt(env, 1)) = nil; /* !*asymp!* */
    v218 = stack[-2];
    v231 = elt(env, 2); /* !*sq */
    if (!consp(v218)) goto v21;
    v218 = qcar(v218);
    if (!(v218 == v231)) goto v21;
    v231 = stack[-2];
    v231 = qcdr(v231);
    v231 = qcdr(v231);
    v231 = qcar(v231);
    if (v231 == nil) goto v21;
    v231 = qvalue(elt(env, 3)); /* !*resimp */
    if (!(v231 == nil)) goto v21;
    v231 = stack[-2];
    v231 = qcdr(v231);
    v231 = qcar(v231);
    goto v4;

v4:
    qvalue(elt(env, 1)) = stack[-3]; /* !*asymp!* */
    { popv(5); return onevalue(v231); }

v21:
    v218 = qvalue(elt(env, 4)); /* mul!* */
    v231 = qvalue(elt(env, 5)); /* !*sub2 */
    v231 = cons(v218, v231);
    nil = C_nil;
    if (exception_pending()) goto v138;
    env = stack[-4];
    stack[-1] = v231;
    v231 = nil;
    qvalue(elt(env, 4)) = v231; /* mul!* */
    v231 = stack[-2];
    fn = elt(env, 13); /* simp */
    v231 = (*qfn1(fn))(qenv(fn), v231);
    nil = C_nil;
    if (exception_pending()) goto v138;
    env = stack[-4];
    stack[-2] = v231;
    v231 = qvalue(elt(env, 6)); /* !*nospurp */
    if (v231 == nil) goto v37;
    v218 = qvalue(elt(env, 4)); /* mul!* */
    v231 = elt(env, 7); /* (isimpq) */
    fn = elt(env, 14); /* union */
    v231 = (*qfn2(fn))(qenv(fn), v218, v231);
    nil = C_nil;
    if (exception_pending()) goto v138;
    env = stack[-4];
    qvalue(elt(env, 4)) = v231; /* mul!* */
    goto v37;

v37:
    v231 = qvalue(elt(env, 4)); /* mul!* */
    stack[0] = v231;
    goto v41;

v41:
    v231 = stack[0];
    if (v231 == nil) goto v206;
    v231 = stack[0];
    v231 = qcar(v231);
    v218 = v231;
    v231 = stack[-2];
    v231 = Lapply1(nil, v218, v231);
    nil = C_nil;
    if (exception_pending()) goto v138;
    env = stack[-4];
    stack[-2] = v231;
    v231 = stack[0];
    v231 = qcdr(v231);
    stack[0] = v231;
    goto v41;

v206:
    v231 = stack[-1];
    v231 = qcar(v231);
    qvalue(elt(env, 4)) = v231; /* mul!* */
    v231 = stack[-2];
    fn = elt(env, 15); /* subs2 */
    v231 = (*qfn1(fn))(qenv(fn), v231);
    nil = C_nil;
    if (exception_pending()) goto v138;
    env = stack[-4];
    stack[-2] = v231;
    v231 = qvalue(elt(env, 8)); /* !*combinelogs */
    if (v231 == nil) goto v234;
    v231 = stack[-2];
    fn = elt(env, 16); /* clogsq!* */
    v231 = (*qfn1(fn))(qenv(fn), v231);
    nil = C_nil;
    if (exception_pending()) goto v138;
    env = stack[-4];
    stack[-2] = v231;
    goto v234;

v234:
    v218 = qvalue(elt(env, 9)); /* dmode!* */
    v231 = elt(env, 10); /* !:gi!: */
    if (!(v218 == v231)) goto v141;
    v231 = qvalue(elt(env, 11)); /* !*norationalgi */
    if (!(v231 == nil)) goto v141;
    v231 = stack[-2];
    fn = elt(env, 17); /* girationalize!: */
    v231 = (*qfn1(fn))(qenv(fn), v231);
    nil = C_nil;
    if (exception_pending()) goto v138;
    env = stack[-4];
    stack[-2] = v231;
    goto v104;

v104:
    v231 = stack[-1];
    v231 = qcdr(v231);
    qvalue(elt(env, 5)) = v231; /* !*sub2 */
    v231 = qvalue(elt(env, 1)); /* !*asymp!* */
    if (v231 == nil) goto v119;
    v231 = qvalue(elt(env, 12)); /* !*rationalize */
    if (v231 == nil) goto v119;
    v231 = stack[-2];
    fn = elt(env, 18); /* gcdchk */
    v231 = (*qfn1(fn))(qenv(fn), v231);
    nil = C_nil;
    if (exception_pending()) goto v138;
    env = stack[-4];
    stack[-2] = v231;
    goto v119;

v119:
    v231 = stack[-2];
    goto v4;

v141:
    v231 = qvalue(elt(env, 12)); /* !*rationalize */
    if (v231 == nil) goto v191;
    v231 = stack[-2];
    fn = elt(env, 19); /* rationalizesq */
    v231 = (*qfn1(fn))(qenv(fn), v231);
    nil = C_nil;
    if (exception_pending()) goto v138;
    env = stack[-4];
    stack[-2] = v231;
    goto v104;

v191:
    v231 = stack[-2];
    fn = elt(env, 20); /* rationalizei */
    v231 = (*qfn1(fn))(qenv(fn), v231);
    nil = C_nil;
    if (exception_pending()) goto v138;
    env = stack[-4];
    stack[-2] = v231;
    goto v104;
/* error exit handlers */
v138:
    env = stack[-4];
    qvalue(elt(env, 1)) = stack[-3]; /* !*asymp!* */
    popv(5);
    return nil;
}



/* Code for ckpreci!# */

static Lisp_Object CC_ckpreciC(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v64, v100, v150;
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
    v64 = stack[0];
    v64 = qcar(v64);
    fn = elt(env, 2); /* timesip */
    stack[-1] = (*qfn1(fn))(qenv(fn), v64);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-2];
    v64 = stack[0];
    v64 = qcdr(v64);
    v64 = qcar(v64);
    fn = elt(env, 2); /* timesip */
    v64 = (*qfn1(fn))(qenv(fn), v64);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-2];
    v150 = stack[-1];
    v100 = v64;
    v64 = qvalue(elt(env, 1)); /* !*complex */
    if (v64 == nil) goto v2;
    v64 = v150;
    if (v64 == nil) goto v47;
    v64 = v100;
    if (!(v64 == nil)) goto v47;
    v64 = stack[0];
    v64 = qcar(v64);
    v100 = qcdr(v64);
    v64 = stack[0];
    v64 = qcdr(v64);
    v64 = qcar(v64);
    {
        popv(3);
        fn = elt(env, 3); /* ckprec2!# */
        return (*qfn2(fn))(qenv(fn), v100, v64);
    }

v47:
    v64 = v100;
    if (v64 == nil) goto v32;
    v64 = v150;
    if (!(v64 == nil)) goto v32;
    v64 = stack[0];
    v64 = qcdr(v64);
    v64 = qcar(v64);
    v100 = qcdr(v64);
    v64 = stack[0];
    v64 = qcar(v64);
    {
        popv(3);
        fn = elt(env, 3); /* ckprec2!# */
        return (*qfn2(fn))(qenv(fn), v100, v64);
    }

v32:
    v64 = nil;
    { popv(3); return onevalue(v64); }

v2:
    v64 = nil;
    { popv(3); return onevalue(v64); }
/* error exit handlers */
v69:
    popv(3);
    return nil;
}



/* Code for ord2 */

static Lisp_Object CC_ord2(Lisp_Object env,
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
    CSL_IGNORE(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v16;
    stack[-1] = v0;
/* end of prologue */
    v99 = stack[-1];
    v30 = stack[0];
    fn = elt(env, 1); /* ordp */
    v30 = (*qfn2(fn))(qenv(fn), v99, v30);
    nil = C_nil;
    if (exception_pending()) goto v14;
    if (v30 == nil) goto v17;
    v99 = stack[-1];
    v30 = stack[0];
    popv(2);
    return list2(v99, v30);

v17:
    v99 = stack[0];
    v30 = stack[-1];
    popv(2);
    return list2(v99, v30);
/* error exit handlers */
v14:
    popv(2);
    return nil;
}



/* Code for prepd */

static Lisp_Object CC_prepd(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v85, v86;
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
    v85 = stack[0];
    if (!consp(v85)) goto v1;
    v85 = stack[0];
    v86 = qcar(v85);
    v85 = elt(env, 2); /* minusp */
    v86 = get(v86, v85);
    env = stack[-2];
    v85 = stack[0];
    v85 = Lapply1(nil, v86, v85);
    nil = C_nil;
    if (exception_pending()) goto v141;
    env = stack[-2];
    if (v85 == nil) goto v103;
    v85 = stack[0];
    fn = elt(env, 4); /* !:minus */
    v85 = (*qfn1(fn))(qenv(fn), v85);
    nil = C_nil;
    if (exception_pending()) goto v141;
    env = stack[-2];
    fn = elt(env, 5); /* prepd1 */
    v85 = (*qfn1(fn))(qenv(fn), v85);
    nil = C_nil;
    if (exception_pending()) goto v141;
    env = stack[-2];
    v86 = v85;
    v85 = v86;
    if (v85 == nil) goto v206;
    v85 = elt(env, 1); /* minus */
    popv(3);
    return list2(v85, v86);

v206:
    v85 = (Lisp_Object)1; /* 0 */
    { popv(3); return onevalue(v85); }

v103:
    v85 = stack[0];
    v86 = qcar(v85);
    v85 = elt(env, 3); /* prepfn */
    v86 = get(v86, v85);
    v85 = stack[0];
        popv(3);
        return Lapply1(nil, v86, v85);

v1:
    v86 = stack[0];
    v85 = (Lisp_Object)1; /* 0 */
    v85 = (Lisp_Object)lessp2(v86, v85);
    nil = C_nil;
    if (exception_pending()) goto v141;
    v85 = v85 ? lisp_true : nil;
    env = stack[-2];
    if (v85 == nil) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    stack[-1] = elt(env, 1); /* minus */
    v85 = stack[0];
    v85 = negate(v85);
    nil = C_nil;
    if (exception_pending()) goto v141;
    {
        Lisp_Object v128 = stack[-1];
        popv(3);
        return list2(v128, v85);
    }
/* error exit handlers */
v141:
    popv(3);
    return nil;
}



/* Code for sqform */

static Lisp_Object CC_sqform(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v50, v52, v193, v35;
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
    v52 = stack[0];
    v50 = stack[-1];
    v50 = qcar(v50);
    stack[-2] = Lapply1(nil, v52, v50);
    nil = C_nil;
    if (exception_pending()) goto v206;
    env = stack[-3];
    v52 = stack[0];
    v50 = stack[-1];
    v50 = qcdr(v50);
    v50 = Lapply1(nil, v52, v50);
    nil = C_nil;
    if (exception_pending()) goto v206;
    env = stack[-3];
    v35 = stack[-2];
    v193 = v50;
    v52 = v193;
    v50 = (Lisp_Object)17; /* 1 */
    if (v52 == v50) { popv(4); return onevalue(v35); }
    v50 = elt(env, 1); /* quotient */
    v52 = v35;
    popv(4);
    return list3(v50, v52, v193);
/* error exit handlers */
v206:
    popv(4);
    return nil;
}



/* Code for reval1 */

static Lisp_Object CC_reval1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v353, v354, v355;
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
    v353 = qvalue(elt(env, 1)); /* varstack!* */
    stack[-3] = qvalue(elt(env, 1)); /* varstack!* */
    qvalue(elt(env, 1)) = v353; /* varstack!* */
    v353 = stack[-2];
    if (v353 == nil) goto v8;
    v353 = stack[-2];
    v353 = Lstringp(nil, v353);
    env = stack[-4];
    if (v353 == nil) goto v24;
    v353 = stack[-2];
    goto v5;

v5:
    qvalue(elt(env, 1)) = stack[-3]; /* varstack!* */
    { popv(5); return onevalue(v353); }

v24:
    v353 = stack[-2];
    v353 = integerp(v353);
    if (v353 == nil) goto v44;
    v354 = qvalue(elt(env, 2)); /* dmode!* */
    v353 = elt(env, 3); /* convert */
    v353 = Lflagp(nil, v354, v353);
    env = stack[-4];
    if (v353 == nil) goto v33;
    v354 = stack[-2];
    v353 = stack[-1];
    fn = elt(env, 22); /* reval2 */
    v353 = (*qfn2(fn))(qenv(fn), v354, v353);
    nil = C_nil;
    if (exception_pending()) goto v356;
    env = stack[-4];
    goto v5;

v33:
    v353 = stack[-2];
    goto v5;

v44:
    v353 = stack[-2];
    if (!consp(v353)) goto v49;
    v353 = stack[-2];
    v353 = qcar(v353);
    if (symbolp(v353)) goto v78;
    v354 = stack[-2];
    v353 = lisp_true;
    fn = elt(env, 23); /* errpri2 */
    v353 = (*qfn2(fn))(qenv(fn), v354, v353);
    nil = C_nil;
    if (exception_pending()) goto v356;
    env = stack[-4];
    goto v7;

v7:
    v353 = stack[-2];
    fn = elt(env, 24); /* getrtype */
    v353 = (*qfn1(fn))(qenv(fn), v353);
    nil = C_nil;
    if (exception_pending()) goto v356;
    env = stack[-4];
    stack[0] = v353;
    if (v353 == nil) goto v357;
    v354 = stack[0];
    v353 = elt(env, 6); /* evfn */
    v353 = get(v354, v353);
    env = stack[-4];
    v355 = v353;
    if (v353 == nil) goto v262;
    v354 = stack[-2];
    v353 = stack[-1];
    v353 = Lapply2(nil, 3, v355, v354, v353);
    nil = C_nil;
    if (exception_pending()) goto v356;
    env = stack[-4];
    goto v5;

v262:
    stack[-2] = elt(env, 13); /* alg */
    stack[-1] = (Lisp_Object)1617; /* 101 */
    v354 = elt(env, 14); /* "Missing evaluation for type" */
    v353 = stack[0];
    v353 = list2(v354, v353);
    nil = C_nil;
    if (exception_pending()) goto v356;
    env = stack[-4];
    fn = elt(env, 25); /* rerror */
    v353 = (*qfnn(fn))(qenv(fn), 3, stack[-2], stack[-1], v353);
    nil = C_nil;
    if (exception_pending()) goto v356;
    env = stack[-4];
    goto v5;

v357:
    v353 = stack[-2];
    if (!consp(v353)) goto v358;
    v353 = stack[-2];
    v353 = qcdr(v353);
    if (!consp(v353)) goto v358;
    v353 = stack[-2];
    v353 = qcdr(v353);
    v353 = qcar(v353);
    fn = elt(env, 24); /* getrtype */
    v353 = (*qfn1(fn))(qenv(fn), v353);
    nil = C_nil;
    if (exception_pending()) goto v356;
    env = stack[-4];
    v355 = v353;
    if (v353 == nil) goto v358;
    v354 = v355;
    v353 = elt(env, 15); /* list */
    if (!(v354 == v353)) goto v359;
    v353 = stack[-2];
    v353 = qcdr(v353);
    v353 = qcdr(v353);
    if (!(v353 == nil)) goto v358;

v359:
    v354 = v355;
    v353 = elt(env, 16); /* aggregatefn */
    v353 = get(v354, v353);
    env = stack[-4];
    stack[0] = v353;
    if (v353 == nil) goto v358;
    v354 = stack[0];
    v353 = elt(env, 17); /* matrixmap */
    if (!(v354 == v353)) goto v360;
    v353 = stack[-2];
    v354 = qcar(v353);
    v353 = elt(env, 18); /* matmapfn */
    v353 = Lflagp(nil, v354, v353);
    env = stack[-4];
    if (!(v353 == nil)) goto v360;

v358:
    v354 = stack[-2];
    v353 = stack[-1];
    fn = elt(env, 22); /* reval2 */
    v353 = (*qfn2(fn))(qenv(fn), v354, v353);
    nil = C_nil;
    if (exception_pending()) goto v356;
    env = stack[-4];
    goto v5;

v360:
    v353 = stack[-2];
    v354 = qcar(v353);
    v353 = elt(env, 19); /* boolean */
    v353 = Lflagp(nil, v354, v353);
    env = stack[-4];
    if (!(v353 == nil)) goto v358;
    v353 = qvalue(elt(env, 20)); /* !*listargs */
    if (!(v353 == nil)) goto v358;
    v353 = stack[-2];
    v354 = qcar(v353);
    v353 = elt(env, 21); /* listargp */
    v353 = Lflagp(nil, v354, v353);
    env = stack[-4];
    if (!(v353 == nil)) goto v358;
    v355 = stack[0];
    v354 = stack[-2];
    v353 = stack[-1];
    v353 = Lapply2(nil, 3, v355, v354, v353);
    nil = C_nil;
    if (exception_pending()) goto v356;
    env = stack[-4];
    goto v5;

v78:
    v353 = stack[-2];
    v354 = qcar(v353);
    v353 = elt(env, 7); /* !*sq */
    if (v354 == v353) goto v213;
    v353 = stack[-2];
    v354 = qcar(v353);
    v353 = elt(env, 9); /* remember */
    v353 = Lflagp(nil, v354, v353);
    env = stack[-4];
    if (v353 == nil) goto v183;
    v354 = stack[-2];
    v353 = stack[-1];
    fn = elt(env, 26); /* rmmbreval */
    v353 = (*qfn2(fn))(qenv(fn), v354, v353);
    nil = C_nil;
    if (exception_pending()) goto v356;
    env = stack[-4];
    goto v5;

v183:
    v353 = stack[-2];
    v354 = qcar(v353);
    v353 = elt(env, 10); /* opfn */
    v353 = Lflagp(nil, v354, v353);
    env = stack[-4];
    if (v353 == nil) goto v361;
    v353 = stack[-2];
    fn = elt(env, 27); /* opfneval */
    v354 = (*qfn1(fn))(qenv(fn), v353);
    nil = C_nil;
    if (exception_pending()) goto v356;
    env = stack[-4];
    v353 = stack[-1];
    v353 = CC_reval1(env, v354, v353);
    nil = C_nil;
    if (exception_pending()) goto v356;
    env = stack[-4];
    goto v5;

v361:
    v353 = stack[-2];
    v354 = qcar(v353);
    v353 = elt(env, 11); /* psopfn */
    v353 = get(v354, v353);
    env = stack[-4];
    stack[0] = v353;
    if (v353 == nil) goto v251;
    v354 = stack[0];
    v353 = stack[-2];
    v353 = qcdr(v353);
    v353 = Lapply1(nil, v354, v353);
    nil = C_nil;
    if (exception_pending()) goto v356;
    env = stack[-4];
    stack[-2] = v353;
    v354 = stack[0];
    v353 = elt(env, 12); /* cleanupfn */
    v353 = get(v354, v353);
    env = stack[-4];
    stack[0] = v353;
    if (v353 == nil) goto v175;
    v355 = stack[0];
    v354 = stack[-2];
    v353 = stack[-1];
    v353 = Lapply2(nil, 3, v355, v354, v353);
    nil = C_nil;
    if (exception_pending()) goto v356;
    env = stack[-4];
    stack[-2] = v353;
    goto v175;

v175:
    v353 = stack[-2];
    goto v5;

v251:
    v353 = stack[-2];
    v353 = qcar(v353);
    fn = elt(env, 28); /* arrayp */
    v353 = (*qfn1(fn))(qenv(fn), v353);
    nil = C_nil;
    if (exception_pending()) goto v356;
    env = stack[-4];
    if (v353 == nil) goto v7;
    v353 = stack[-2];
    fn = elt(env, 29); /* getelv */
    v354 = (*qfn1(fn))(qenv(fn), v353);
    nil = C_nil;
    if (exception_pending()) goto v356;
    env = stack[-4];
    v353 = stack[-1];
    v353 = CC_reval1(env, v354, v353);
    nil = C_nil;
    if (exception_pending()) goto v356;
    env = stack[-4];
    goto v5;

v213:
    v353 = stack[-2];
    v353 = qcdr(v353);
    v353 = qcdr(v353);
    v353 = qcar(v353);
    if (v353 == nil) goto v125;
    v353 = qvalue(elt(env, 8)); /* !*resimp */
    if (!(v353 == nil)) goto v125;
    v353 = stack[-1];
    if (v353 == nil) goto v232;
    v353 = stack[-2];
    v353 = qcdr(v353);
    v353 = qcar(v353);
    fn = elt(env, 30); /* prepsqxx */
    v353 = (*qfn1(fn))(qenv(fn), v353);
    nil = C_nil;
    if (exception_pending()) goto v356;
    env = stack[-4];
    goto v5;

v232:
    v353 = stack[-2];
    goto v5;

v125:
    v354 = stack[-2];
    v353 = stack[-1];
    fn = elt(env, 22); /* reval2 */
    v353 = (*qfn2(fn))(qenv(fn), v354, v353);
    nil = C_nil;
    if (exception_pending()) goto v356;
    env = stack[-4];
    goto v5;

v49:
    v353 = qvalue(elt(env, 4)); /* subfg!* */
    if (v353 == nil) goto v34;
    v353 = stack[-2];
    if (!(symbolp(v353))) goto v7;
    v354 = stack[-2];
    v353 = elt(env, 5); /* avalue */
    v353 = get(v354, v353);
    env = stack[-4];
    stack[0] = v353;
    if (v353 == nil) goto v7;
    v354 = stack[-2];
    v353 = qvalue(elt(env, 1)); /* varstack!* */
    v353 = Lmemq(nil, v354, v353);
    if (v353 == nil) goto v62;
    v353 = stack[-2];
    fn = elt(env, 31); /* recursiveerror */
    v353 = (*qfn1(fn))(qenv(fn), v353);
    nil = C_nil;
    if (exception_pending()) goto v356;
    env = stack[-4];
    goto v7;

v62:
    v354 = stack[-2];
    v353 = qvalue(elt(env, 1)); /* varstack!* */
    v353 = cons(v354, v353);
    nil = C_nil;
    if (exception_pending()) goto v356;
    env = stack[-4];
    qvalue(elt(env, 1)) = v353; /* varstack!* */
    v353 = stack[0];
    v354 = qcar(v353);
    v353 = elt(env, 6); /* evfn */
    v353 = get(v354, v353);
    env = stack[-4];
    v355 = v353;
    if (v353 == nil) goto v217;
    v354 = stack[-2];
    v353 = stack[-1];
    v353 = Lapply2(nil, 3, v355, v354, v353);
    nil = C_nil;
    if (exception_pending()) goto v356;
    env = stack[-4];
    goto v5;

v217:
    v353 = stack[0];
    v353 = qcdr(v353);
    v354 = qcar(v353);
    v353 = stack[-1];
    v353 = CC_reval1(env, v354, v353);
    nil = C_nil;
    if (exception_pending()) goto v356;
    env = stack[-4];
    goto v5;

v34:
    v353 = stack[-2];
    goto v5;

v8:
    v353 = nil;
    goto v5;
/* error exit handlers */
v356:
    env = stack[-4];
    qvalue(elt(env, 1)) = stack[-3]; /* varstack!* */
    popv(5);
    return nil;
}



/* Code for sinitl */

static Lisp_Object CC_sinitl(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v27, v28;
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
    stack[0] = v27;
    v28 = v27;
    v27 = elt(env, 1); /* initl */
    v27 = get(v28, v27);
    env = stack[-1];
    fn = elt(env, 2); /* eval */
    v27 = (*qfn1(fn))(qenv(fn), v27);
    nil = C_nil;
    if (exception_pending()) goto v44;
    {
        Lisp_Object v47 = stack[0];
        popv(2);
        return Lset(nil, v47, v27);
    }
/* error exit handlers */
v44:
    popv(2);
    return nil;
}



/* Code for simp */

static Lisp_Object CC_simp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v435, v436, v437;
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
    stack[-5] = v0;
/* end of prologue */
    v435 = qvalue(elt(env, 1)); /* varstack!* */
    stack[-6] = qvalue(elt(env, 1)); /* varstack!* */
    qvalue(elt(env, 1)) = v435; /* varstack!* */
    v435 = stack[-5];
    v435 = integerp(v435);
    if (v435 == nil) goto v52;
    v436 = stack[-5];
    v435 = (Lisp_Object)1; /* 0 */
    if (v436 == v435) goto v17;
    v435 = qvalue(elt(env, 2)); /* dmode!* */
    if (!(v435 == nil)) goto v134;
    v436 = stack[-5];
    v435 = (Lisp_Object)17; /* 1 */
    v435 = cons(v436, v435);
    nil = C_nil;
    if (exception_pending()) goto v438;
    env = stack[-7];
    goto v45;

v45:
    qvalue(elt(env, 1)) = stack[-6]; /* varstack!* */
    { popv(8); return onevalue(v435); }

v134:
    v436 = stack[-5];
    v435 = qvalue(elt(env, 1)); /* varstack!* */
    v435 = cons(v436, v435);
    nil = C_nil;
    if (exception_pending()) goto v438;
    env = stack[-7];
    qvalue(elt(env, 1)) = v435; /* varstack!* */
    v436 = qvalue(elt(env, 3)); /* simpcount!* */
    v435 = qvalue(elt(env, 4)); /* simplimit!* */
    v435 = (Lisp_Object)greaterp2(v436, v435);
    nil = C_nil;
    if (exception_pending()) goto v438;
    v435 = v435 ? lisp_true : nil;
    env = stack[-7];
    if (v435 == nil) goto v120;
    v435 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 3)) = v435; /* simpcount!* */
    v437 = elt(env, 5); /* alg */
    v436 = (Lisp_Object)193; /* 12 */
    v435 = elt(env, 6); /* "Simplification recursion too deep" */
    fn = elt(env, 32); /* rerror */
    v435 = (*qfnn(fn))(qenv(fn), 3, v437, v436, v435);
    nil = C_nil;
    if (exception_pending()) goto v438;
    env = stack[-7];
    goto v66;

v66:
    v435 = qvalue(elt(env, 3)); /* simpcount!* */
    v435 = add1(v435);
    nil = C_nil;
    if (exception_pending()) goto v438;
    env = stack[-7];
    qvalue(elt(env, 3)) = v435; /* simpcount!* */
    v435 = stack[-5];
    if (!consp(v435)) goto v77;
    v435 = stack[-5];
    v435 = qcar(v435);
    if (!(symbolp(v435))) goto v76;
    v435 = stack[-5];
    v435 = qcar(v435);
    if (v435 == nil) goto v76;
    v435 = stack[-5];
    v436 = qcar(v435);
    v435 = elt(env, 15); /* opfn */
    v435 = Lflagp(nil, v436, v435);
    env = stack[-7];
    if (v435 == nil) goto v439;
    v435 = stack[-5];
    fn = elt(env, 33); /* opfneval */
    v435 = (*qfn1(fn))(qenv(fn), v435);
    nil = C_nil;
    if (exception_pending()) goto v438;
    env = stack[-7];
    stack[-1] = v435;
    fn = elt(env, 34); /* getrtype */
    v435 = (*qfn1(fn))(qenv(fn), v435);
    nil = C_nil;
    if (exception_pending()) goto v438;
    env = stack[-7];
    v436 = v435;
    if (v435 == nil) goto v328;
    v435 = elt(env, 16); /* yetunknowntype */
    if (!(v436 == v435)) goto v247;
    v435 = stack[-1];
    fn = elt(env, 35); /* reval */
    v435 = (*qfn1(fn))(qenv(fn), v435);
    nil = C_nil;
    if (exception_pending()) goto v438;
    env = stack[-7];
    stack[-1] = v435;
    fn = elt(env, 34); /* getrtype */
    v435 = (*qfn1(fn))(qenv(fn), v435);
    nil = C_nil;
    if (exception_pending()) goto v438;
    env = stack[-7];
    if (!(v435 == nil)) goto v247;
    v435 = stack[-1];
    v435 = CC_simp(env, v435);
    nil = C_nil;
    if (exception_pending()) goto v438;
    env = stack[-7];
    goto v45;

v247:
    v436 = stack[-5];
    v435 = elt(env, 17); /* "scalar" */
    fn = elt(env, 36); /* typerr */
    v435 = (*qfn2(fn))(qenv(fn), v436, v435);
    nil = C_nil;
    if (exception_pending()) goto v438;
    env = stack[-7];
    goto v132;

v132:
    v435 = nil;
    goto v45;

v328:
    v435 = stack[-1];
    fn = elt(env, 37); /* simp_without_resimp */
    v436 = (*qfn1(fn))(qenv(fn), v435);
    nil = C_nil;
    if (exception_pending()) goto v438;
    env = stack[-7];
    v435 = stack[-5];
    fn = elt(env, 38); /* !*ssave */
    v435 = (*qfn2(fn))(qenv(fn), v436, v435);
    nil = C_nil;
    if (exception_pending()) goto v438;
    env = stack[-7];
    goto v45;

v439:
    v435 = stack[-5];
    v436 = qcar(v435);
    v435 = elt(env, 18); /* psopfn */
    v435 = get(v436, v435);
    env = stack[-7];
    stack[-1] = v435;
    if (v435 == nil) goto v440;
    stack[0] = stack[-1];
    v435 = stack[-5];
    fn = elt(env, 39); /* argnochk */
    v435 = (*qfn1(fn))(qenv(fn), v435);
    nil = C_nil;
    if (exception_pending()) goto v438;
    env = stack[-7];
    v435 = qcdr(v435);
    v435 = Lapply1(nil, stack[0], v435);
    nil = C_nil;
    if (exception_pending()) goto v438;
    env = stack[-7];
    stack[-1] = v435;
    fn = elt(env, 34); /* getrtype */
    v435 = (*qfn1(fn))(qenv(fn), v435);
    nil = C_nil;
    if (exception_pending()) goto v438;
    env = stack[-7];
    if (v435 == nil) goto v441;
    v436 = stack[-5];
    v435 = elt(env, 17); /* "scalar" */
    fn = elt(env, 36); /* typerr */
    v435 = (*qfn2(fn))(qenv(fn), v436, v435);
    nil = C_nil;
    if (exception_pending()) goto v438;
    env = stack[-7];
    goto v132;

v441:
    v436 = stack[-1];
    v435 = stack[-5];
    if (equal(v436, v435)) goto v442;
    v435 = stack[-1];
    fn = elt(env, 37); /* simp_without_resimp */
    v436 = (*qfn1(fn))(qenv(fn), v435);
    nil = C_nil;
    if (exception_pending()) goto v438;
    env = stack[-7];
    v435 = stack[-5];
    fn = elt(env, 38); /* !*ssave */
    v435 = (*qfn2(fn))(qenv(fn), v436, v435);
    nil = C_nil;
    if (exception_pending()) goto v438;
    env = stack[-7];
    goto v45;

v442:
    v436 = stack[-1];
    v435 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 40); /* to */
    v436 = (*qfn2(fn))(qenv(fn), v436, v435);
    nil = C_nil;
    if (exception_pending()) goto v438;
    env = stack[-7];
    v435 = (Lisp_Object)17; /* 1 */
    v435 = cons(v436, v435);
    nil = C_nil;
    if (exception_pending()) goto v438;
    env = stack[-7];
    v436 = ncons(v435);
    nil = C_nil;
    if (exception_pending()) goto v438;
    env = stack[-7];
    v435 = (Lisp_Object)17; /* 1 */
    v436 = cons(v436, v435);
    nil = C_nil;
    if (exception_pending()) goto v438;
    env = stack[-7];
    v435 = stack[-5];
    fn = elt(env, 38); /* !*ssave */
    v435 = (*qfn2(fn))(qenv(fn), v436, v435);
    nil = C_nil;
    if (exception_pending()) goto v438;
    env = stack[-7];
    goto v45;

v440:
    v435 = stack[-5];
    v436 = qcar(v435);
    v435 = elt(env, 19); /* polyfn */
    v435 = get(v436, v435);
    env = stack[-7];
    stack[-1] = v435;
    if (v435 == nil) goto v275;
    v435 = stack[-5];
    fn = elt(env, 39); /* argnochk */
    v435 = (*qfn1(fn))(qenv(fn), v435);
    nil = C_nil;
    if (exception_pending()) goto v438;
    env = stack[-7];
    stack[-4] = stack[-1];
    v435 = stack[-5];
    v435 = qcdr(v435);
    stack[-3] = v435;
    v435 = stack[-3];
    if (v435 == nil) goto v443;
    v435 = stack[-3];
    v435 = qcar(v435);
    fn = elt(env, 41); /* simp!* */
    v435 = (*qfn1(fn))(qenv(fn), v435);
    nil = C_nil;
    if (exception_pending()) goto v438;
    env = stack[-7];
    fn = elt(env, 42); /* !*q2f */
    v435 = (*qfn1(fn))(qenv(fn), v435);
    nil = C_nil;
    if (exception_pending()) goto v438;
    env = stack[-7];
    v435 = ncons(v435);
    nil = C_nil;
    if (exception_pending()) goto v438;
    env = stack[-7];
    stack[-1] = v435;
    stack[-2] = v435;
    goto v444;

v444:
    v435 = stack[-3];
    v435 = qcdr(v435);
    stack[-3] = v435;
    v435 = stack[-3];
    if (v435 == nil) goto v445;
    stack[0] = stack[-1];
    v435 = stack[-3];
    v435 = qcar(v435);
    fn = elt(env, 41); /* simp!* */
    v435 = (*qfn1(fn))(qenv(fn), v435);
    nil = C_nil;
    if (exception_pending()) goto v438;
    env = stack[-7];
    fn = elt(env, 42); /* !*q2f */
    v435 = (*qfn1(fn))(qenv(fn), v435);
    nil = C_nil;
    if (exception_pending()) goto v438;
    env = stack[-7];
    v435 = ncons(v435);
    nil = C_nil;
    if (exception_pending()) goto v438;
    env = stack[-7];
    v435 = Lrplacd(nil, stack[0], v435);
    nil = C_nil;
    if (exception_pending()) goto v438;
    env = stack[-7];
    v435 = stack[-1];
    v435 = qcdr(v435);
    stack[-1] = v435;
    goto v444;

v445:
    v435 = stack[-2];
    goto v355;

v355:
    fn = elt(env, 43); /* lispapply */
    v436 = (*qfn2(fn))(qenv(fn), stack[-4], v435);
    nil = C_nil;
    if (exception_pending()) goto v438;
    env = stack[-7];
    v435 = (Lisp_Object)17; /* 1 */
    v436 = cons(v436, v435);
    nil = C_nil;
    if (exception_pending()) goto v438;
    env = stack[-7];
    v435 = stack[-5];
    fn = elt(env, 38); /* !*ssave */
    v435 = (*qfn2(fn))(qenv(fn), v436, v435);
    nil = C_nil;
    if (exception_pending()) goto v438;
    env = stack[-7];
    goto v45;

v443:
    v435 = nil;
    goto v355;

v275:
    v435 = stack[-5];
    v436 = qcar(v435);
    v435 = elt(env, 20); /* opmtch */
    v435 = get(v436, v435);
    env = stack[-7];
    if (v435 == nil) goto v446;
    v435 = stack[-5];
    v436 = qcar(v435);
    v435 = elt(env, 21); /* simpfn */
    v436 = get(v436, v435);
    env = stack[-7];
    v435 = elt(env, 22); /* simpiden */
    if (v436 == v435) goto v446;
    v435 = stack[-5];
    fn = elt(env, 44); /* opmtchrevop */
    v435 = (*qfn1(fn))(qenv(fn), v435);
    nil = C_nil;
    if (exception_pending()) goto v438;
    env = stack[-7];
    stack[-1] = v435;
    if (v435 == nil) goto v446;
    v435 = stack[-1];
    v436 = CC_simp(env, v435);
    nil = C_nil;
    if (exception_pending()) goto v438;
    env = stack[-7];
    v435 = stack[-5];
    fn = elt(env, 38); /* !*ssave */
    v435 = (*qfn2(fn))(qenv(fn), v436, v435);
    nil = C_nil;
    if (exception_pending()) goto v438;
    env = stack[-7];
    goto v45;

v446:
    v435 = stack[-5];
    v436 = qcar(v435);
    v435 = elt(env, 21); /* simpfn */
    v435 = get(v436, v435);
    env = stack[-7];
    stack[-1] = v435;
    if (v435 == nil) goto v447;
    stack[0] = stack[-1];
    v436 = stack[-1];
    v435 = elt(env, 22); /* simpiden */
    if (v436 == v435) goto v448;
    v435 = stack[-5];
    v436 = qcar(v435);
    v435 = elt(env, 23); /* full */
    v435 = Lflagp(nil, v436, v435);
    env = stack[-7];
    if (!(v435 == nil)) goto v448;
    v435 = stack[-5];
    fn = elt(env, 39); /* argnochk */
    v435 = (*qfn1(fn))(qenv(fn), v435);
    nil = C_nil;
    if (exception_pending()) goto v438;
    env = stack[-7];
    v435 = qcdr(v435);
    goto v310;

v310:
    v436 = Lapply1(nil, stack[0], v435);
    nil = C_nil;
    if (exception_pending()) goto v438;
    env = stack[-7];
    v435 = stack[-5];
    fn = elt(env, 38); /* !*ssave */
    v435 = (*qfn2(fn))(qenv(fn), v436, v435);
    nil = C_nil;
    if (exception_pending()) goto v438;
    env = stack[-7];
    goto v45;

v448:
    v435 = stack[-5];
    fn = elt(env, 39); /* argnochk */
    v435 = (*qfn1(fn))(qenv(fn), v435);
    nil = C_nil;
    if (exception_pending()) goto v438;
    env = stack[-7];
    goto v310;

v447:
    v435 = stack[-5];
    v436 = qcar(v435);
    v435 = elt(env, 24); /* rtype */
    v435 = get(v436, v435);
    env = stack[-7];
    stack[-1] = v435;
    if (v435 == nil) goto v449;
    v436 = stack[-1];
    v435 = elt(env, 25); /* getelemfn */
    v435 = get(v436, v435);
    env = stack[-7];
    stack[-1] = v435;
    if (v435 == nil) goto v449;
    v436 = stack[-1];
    v435 = stack[-5];
    v435 = Lapply1(nil, v436, v435);
    nil = C_nil;
    if (exception_pending()) goto v438;
    env = stack[-7];
    v436 = CC_simp(env, v435);
    nil = C_nil;
    if (exception_pending()) goto v438;
    env = stack[-7];
    v435 = stack[-5];
    fn = elt(env, 38); /* !*ssave */
    v435 = (*qfn2(fn))(qenv(fn), v436, v435);
    nil = C_nil;
    if (exception_pending()) goto v438;
    env = stack[-7];
    goto v45;

v449:
    v435 = stack[-5];
    v436 = qcar(v435);
    v435 = elt(env, 26); /* boolean */
    v435 = Lflagp(nil, v436, v435);
    env = stack[-7];
    if (!(v435 == nil)) goto v450;
    v435 = stack[-5];
    v436 = qcar(v435);
    v435 = elt(env, 27); /* infix */
    v435 = get(v436, v435);
    env = stack[-7];
    if (!(v435 == nil)) goto v450;
    v435 = stack[-5];
    v436 = qcar(v435);
    v435 = elt(env, 30); /* nochange */
    v435 = Lflagp(nil, v436, v435);
    env = stack[-7];
    if (v435 == nil) goto v451;
    v435 = stack[-5];
    fn = elt(env, 45); /* lispeval */
    v435 = (*qfn1(fn))(qenv(fn), v435);
    nil = C_nil;
    if (exception_pending()) goto v438;
    env = stack[-7];
    v436 = CC_simp(env, v435);
    nil = C_nil;
    if (exception_pending()) goto v438;
    env = stack[-7];
    v435 = stack[-5];
    fn = elt(env, 38); /* !*ssave */
    v435 = (*qfn2(fn))(qenv(fn), v436, v435);
    nil = C_nil;
    if (exception_pending()) goto v438;
    env = stack[-7];
    goto v45;

v451:
    v435 = stack[-5];
    v436 = qcar(v435);
    v435 = elt(env, 18); /* psopfn */
    v435 = get(v436, v435);
    env = stack[-7];
    if (!(v435 == nil)) goto v452;
    v435 = stack[-5];
    v436 = qcar(v435);
    v435 = elt(env, 31); /* rtypefn */
    v435 = get(v436, v435);
    env = stack[-7];
    if (!(v435 == nil)) goto v452;
    v435 = stack[-5];
    v436 = qcar(v435);
    v435 = elt(env, 12); /* "operator" */
    fn = elt(env, 46); /* redmsg */
    v435 = (*qfn2(fn))(qenv(fn), v436, v435);
    nil = C_nil;
    if (exception_pending()) goto v438;
    env = stack[-7];
    v435 = stack[-5];
    v435 = qcar(v435);
    fn = elt(env, 47); /* mkop */
    v435 = (*qfn1(fn))(qenv(fn), v435);
    nil = C_nil;
    if (exception_pending()) goto v438;
    env = stack[-7];
    v436 = stack[-5];
    v435 = qvalue(elt(env, 1)); /* varstack!* */
    v435 = Ldelete(nil, v436, v435);
    nil = C_nil;
    if (exception_pending()) goto v438;
    env = stack[-7];
    qvalue(elt(env, 1)) = v435; /* varstack!* */
    v435 = stack[-5];
    v436 = CC_simp(env, v435);
    nil = C_nil;
    if (exception_pending()) goto v438;
    env = stack[-7];
    v435 = stack[-5];
    fn = elt(env, 38); /* !*ssave */
    v435 = (*qfn2(fn))(qenv(fn), v436, v435);
    nil = C_nil;
    if (exception_pending()) goto v438;
    env = stack[-7];
    goto v45;

v452:
    v436 = stack[-5];
    v435 = elt(env, 17); /* "scalar" */
    fn = elt(env, 36); /* typerr */
    v435 = (*qfn2(fn))(qenv(fn), v436, v435);
    nil = C_nil;
    if (exception_pending()) goto v438;
    env = stack[-7];
    goto v132;

v450:
    v435 = stack[-5];
    v436 = qcar(v435);
    v435 = elt(env, 28); /* prtch */
    v435 = get(v436, v435);
    env = stack[-7];
    stack[-1] = v435;
    if (v435 == nil) goto v453;
    v435 = stack[-1];
    v436 = v435;
    goto v454;

v454:
    v435 = elt(env, 29); /* "algebraic operator" */
    fn = elt(env, 36); /* typerr */
    v435 = (*qfn2(fn))(qenv(fn), v436, v435);
    nil = C_nil;
    if (exception_pending()) goto v438;
    env = stack[-7];
    goto v132;

v453:
    v435 = stack[-5];
    v435 = qcar(v435);
    v436 = v435;
    goto v454;

v76:
    v435 = stack[-5];
    v435 = qcar(v435);
    if (!consp(v435)) goto v127;
    v435 = stack[-5];
    v435 = qcar(v435);
    v435 = qcar(v435);
    if (!(symbolp(v435))) goto v182;
    v435 = stack[-5];
    v435 = qcar(v435);
    v436 = qcar(v435);
    v435 = elt(env, 13); /* name */
    v435 = get(v436, v435);
    env = stack[-7];
    if (v435 == nil) goto v182;
    v436 = stack[-5];
    v435 = stack[-5];
    fn = elt(env, 38); /* !*ssave */
    v435 = (*qfn2(fn))(qenv(fn), v436, v435);
    nil = C_nil;
    if (exception_pending()) goto v438;
    env = stack[-7];
    goto v45;

v182:
    v435 = stack[-5];
    v436 = qcar(v435);
    v435 = elt(env, 14); /* mat */
    if (!consp(v436)) goto v455;
    v436 = qcar(v436);
    if (!(v436 == v435)) goto v455;
    v435 = stack[-5];
    v435 = qcdr(v435);
    fn = elt(env, 48); /* revlis */
    v435 = (*qfn1(fn))(qenv(fn), v435);
    nil = C_nil;
    if (exception_pending()) goto v438;
    env = stack[-7];
    stack[-1] = v435;
    fn = elt(env, 49); /* numlis */
    v435 = (*qfn1(fn))(qenv(fn), v435);
    nil = C_nil;
    if (exception_pending()) goto v438;
    env = stack[-7];
    if (v435 == nil) goto v455;
    v435 = stack[-1];
    v436 = Llength(nil, v435);
    nil = C_nil;
    if (exception_pending()) goto v438;
    env = stack[-7];
    v435 = (Lisp_Object)33; /* 2 */
    if (!(v436 == v435)) goto v455;
    v435 = stack[-5];
    v435 = qcar(v435);
    v436 = qcdr(v435);
    v435 = stack[-1];
    v435 = qcar(v435);
    fn = elt(env, 50); /* nth */
    v436 = (*qfn2(fn))(qenv(fn), v436, v435);
    nil = C_nil;
    if (exception_pending()) goto v438;
    env = stack[-7];
    v435 = stack[-1];
    v435 = qcdr(v435);
    v435 = qcar(v435);
    fn = elt(env, 50); /* nth */
    v435 = (*qfn2(fn))(qenv(fn), v436, v435);
    nil = C_nil;
    if (exception_pending()) goto v438;
    env = stack[-7];
    v436 = CC_simp(env, v435);
    nil = C_nil;
    if (exception_pending()) goto v438;
    env = stack[-7];
    v435 = stack[-5];
    fn = elt(env, 38); /* !*ssave */
    v435 = (*qfn2(fn))(qenv(fn), v436, v435);
    nil = C_nil;
    if (exception_pending()) goto v438;
    env = stack[-7];
    goto v45;

v455:
    v436 = stack[-5];
    v435 = lisp_true;
    fn = elt(env, 51); /* errpri2 */
    v435 = (*qfn2(fn))(qenv(fn), v436, v435);
    nil = C_nil;
    if (exception_pending()) goto v438;
    env = stack[-7];
    goto v132;

v127:
    v435 = stack[-5];
    v436 = qcar(v435);
    v435 = elt(env, 12); /* "operator" */
    fn = elt(env, 36); /* typerr */
    v435 = (*qfn2(fn))(qenv(fn), v436, v435);
    nil = C_nil;
    if (exception_pending()) goto v438;
    env = stack[-7];
    goto v132;

v77:
    v435 = stack[-5];
    fn = elt(env, 52); /* simpatom */
    v436 = (*qfn1(fn))(qenv(fn), v435);
    nil = C_nil;
    if (exception_pending()) goto v438;
    env = stack[-7];
    v435 = stack[-5];
    fn = elt(env, 38); /* !*ssave */
    v435 = (*qfn2(fn))(qenv(fn), v436, v435);
    nil = C_nil;
    if (exception_pending()) goto v438;
    env = stack[-7];
    goto v45;

v120:
    v436 = stack[-5];
    v435 = elt(env, 7); /* !*sq */
    if (!consp(v436)) goto v128;
    v436 = qcar(v436);
    if (!(v436 == v435)) goto v128;
    v435 = stack[-5];
    v435 = qcdr(v435);
    v435 = qcdr(v435);
    v435 = qcar(v435);
    if (v435 == nil) goto v128;
    v435 = qvalue(elt(env, 8)); /* !*resimp */
    if (!(v435 == nil)) goto v128;
    v435 = stack[-5];
    v435 = qcdr(v435);
    v435 = qcar(v435);
    goto v45;

v128:
    v435 = qvalue(elt(env, 9)); /* !*uncached */
    if (!(v435 == nil)) goto v66;
    v436 = stack[-5];
    v435 = qvalue(elt(env, 10)); /* alglist!* */
    v435 = qcar(v435);
    v435 = Lassoc(nil, v436, v435);
    stack[-1] = v435;
    if (v435 == nil) goto v66;
    v435 = stack[-1];
    v435 = qcdr(v435);
    v435 = qcar(v435);
    if (v435 == nil) goto v218;
    v435 = lisp_true;
    qvalue(elt(env, 11)) = v435; /* !*sub2 */
    goto v218;

v218:
    v435 = stack[-1];
    v435 = qcdr(v435);
    v435 = qcdr(v435);
    goto v45;

v17:
    v436 = nil;
    v435 = (Lisp_Object)17; /* 1 */
    v435 = cons(v436, v435);
    nil = C_nil;
    if (exception_pending()) goto v438;
    env = stack[-7];
    goto v45;

v52:
    v436 = stack[-5];
    v435 = qvalue(elt(env, 1)); /* varstack!* */
    v435 = Lmember(nil, v436, v435);
    if (v435 == nil) goto v134;
    v435 = stack[-5];
    fn = elt(env, 53); /* recursiveerror */
    v435 = (*qfn1(fn))(qenv(fn), v435);
    nil = C_nil;
    if (exception_pending()) goto v438;
    env = stack[-7];
    goto v134;
/* error exit handlers */
v438:
    env = stack[-7];
    qvalue(elt(env, 1)) = stack[-6]; /* varstack!* */
    popv(8);
    return nil;
}



/* Code for retimes1 */

static Lisp_Object CC_retimes1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v117, v113;
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
    v117 = stack[0];
    if (v117 == nil) goto v5;
    v117 = stack[0];
    v113 = qcar(v117);
    v117 = (Lisp_Object)17; /* 1 */
    if (v113 == v117) goto v2;
    v117 = stack[0];
    v117 = qcar(v117);
    v117 = Lminusp(nil, v117);
    env = stack[-2];
    if (v117 == nil) goto v17;
    v117 = qvalue(elt(env, 1)); /* !*bool */
    v117 = (v117 == nil ? lisp_true : nil);
    qvalue(elt(env, 1)) = v117; /* !*bool */
    v117 = stack[0];
    v117 = qcar(v117);
    v113 = negate(v117);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-2];
    v117 = stack[0];
    v117 = qcdr(v117);
    v117 = cons(v113, v117);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-2];
    stack[0] = v117;
    goto v4;

v17:
    v117 = stack[0];
    v117 = qcar(v117);
    if (!consp(v117)) goto v50;
    v117 = stack[0];
    v117 = qcar(v117);
    v113 = qcar(v117);
    v117 = elt(env, 2); /* minus */
    if (v113 == v117) goto v100;
    v117 = stack[0];
    v117 = qcar(v117);
    v113 = qcar(v117);
    v117 = elt(env, 3); /* times */
    if (v113 == v117) goto v120;
    v117 = stack[0];
    v113 = qcar(v117);
    v117 = stack[-1];
    v117 = cons(v113, v117);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-2];
    stack[-1] = v117;
    v117 = stack[0];
    v117 = qcdr(v117);
    stack[0] = v117;
    goto v4;

v120:
    v117 = stack[0];
    v117 = qcar(v117);
    v113 = qcdr(v117);
    v117 = stack[0];
    v117 = qcdr(v117);
    v117 = Lappend(nil, v113, v117);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-2];
    stack[0] = v117;
    goto v4;

v100:
    v117 = qvalue(elt(env, 1)); /* !*bool */
    v117 = (v117 == nil ? lisp_true : nil);
    qvalue(elt(env, 1)) = v117; /* !*bool */
    v117 = stack[0];
    v117 = qcar(v117);
    v117 = qcdr(v117);
    v113 = qcar(v117);
    v117 = stack[0];
    v117 = qcdr(v117);
    v117 = cons(v113, v117);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-2];
    stack[0] = v117;
    goto v4;

v50:
    v117 = stack[0];
    v113 = qcar(v117);
    v117 = stack[-1];
    v117 = cons(v113, v117);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-2];
    stack[-1] = v117;
    v117 = stack[0];
    v117 = qcdr(v117);
    stack[0] = v117;
    goto v4;

v2:
    v117 = stack[0];
    v117 = qcdr(v117);
    stack[0] = v117;
    goto v4;

v5:
    v117 = stack[-1];
    {
        popv(3);
        fn = elt(env, 4); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v117);
    }
/* error exit handlers */
v139:
    popv(3);
    return nil;
}



/* Code for rationalizei */

static Lisp_Object CC_rationalizei(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v142, v236;
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
    v142 = stack[-1];
    v142 = qcdr(v142);
    stack[-2] = v142;
    v236 = v142;
    v142 = v236;
    v142 = (consp(v142) ? nil : lisp_true);
    if (!(v142 == nil)) goto v13;
    v142 = v236;
    v142 = qcar(v142);
    v142 = (consp(v142) ? nil : lisp_true);
    goto v13;

v13:
    if (!(v142 == nil)) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v236 = elt(env, 1); /* i */
    v142 = stack[-2];
    v142 = Lsmemq(nil, v236, v142);
    nil = C_nil;
    if (exception_pending()) goto v237;
    env = stack[-3];
    if (v142 == nil) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v236 = elt(env, 1); /* i */
    v142 = qvalue(elt(env, 2)); /* kord!* */
    v142 = cons(v236, v142);
    nil = C_nil;
    if (exception_pending()) goto v237;
    env = stack[-3];
    stack[0] = qvalue(elt(env, 2)); /* kord!* */
    qvalue(elt(env, 2)) = v142; /* kord!* */
    v142 = stack[-1];
    fn = elt(env, 4); /* reordsq */
    v142 = (*qfn1(fn))(qenv(fn), v142);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-3];
    stack[-2] = v142;
    qvalue(elt(env, 2)) = stack[0]; /* kord!* */
    v142 = stack[-2];
    v142 = qcdr(v142);
    stack[0] = v142;
    v142 = qcar(v142);
    v236 = qcar(v142);
    v142 = elt(env, 3); /* (i . 1) */
    if (!(equal(v236, v142))) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v142 = stack[0];
    v142 = qcdr(v142);
    if (!(v142 == nil)) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v236 = elt(env, 1); /* i */
    v142 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 5); /* to */
    v236 = (*qfn2(fn))(qenv(fn), v236, v142);
    nil = C_nil;
    if (exception_pending()) goto v237;
    env = stack[-3];
    v142 = (Lisp_Object)17; /* 1 */
    v142 = cons(v236, v142);
    nil = C_nil;
    if (exception_pending()) goto v237;
    env = stack[-3];
    stack[-1] = ncons(v142);
    nil = C_nil;
    if (exception_pending()) goto v237;
    env = stack[-3];
    v142 = stack[-2];
    v142 = qcar(v142);
    fn = elt(env, 6); /* reorder */
    v142 = (*qfn1(fn))(qenv(fn), v142);
    nil = C_nil;
    if (exception_pending()) goto v237;
    env = stack[-3];
    fn = elt(env, 7); /* multf */
    v142 = (*qfn2(fn))(qenv(fn), stack[-1], v142);
    nil = C_nil;
    if (exception_pending()) goto v237;
    env = stack[-3];
    fn = elt(env, 8); /* negf */
    stack[-1] = (*qfn1(fn))(qenv(fn), v142);
    nil = C_nil;
    if (exception_pending()) goto v237;
    env = stack[-3];
    v142 = stack[0];
    v142 = qcar(v142);
    v142 = qcdr(v142);
    fn = elt(env, 6); /* reorder */
    v142 = (*qfn1(fn))(qenv(fn), v142);
    nil = C_nil;
    if (exception_pending()) goto v237;
    {
        Lisp_Object v143 = stack[-1];
        popv(4);
        return cons(v143, v142);
    }
/* error exit handlers */
v121:
    env = stack[-3];
    qvalue(elt(env, 2)) = stack[0]; /* kord!* */
    popv(4);
    return nil;
v237:
    popv(4);
    return nil;
}



/* Code for aeval */

static Lisp_Object CC_aeval(Lisp_Object env,
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
    v7 = nil;
    {
        fn = elt(env, 1); /* reval1 */
        return (*qfn2(fn))(qenv(fn), v8, v7);
    }
}



/* Code for algid */

static Lisp_Object CC_algid(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v21, v22, v23;
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
    v21 = v16;
    v23 = v0;
/* end of prologue */
    v22 = v23;
    v21 = Latsoc(nil, v22, v21);
    if (!(v21 == nil)) return onevalue(v23);
    v22 = v23;
    v21 = elt(env, 1); /* share */
    v21 = Lflagp(nil, v22, v21);
    if (!(v21 == nil)) return onevalue(v23);
    v21 = v23;
        return Lmkquote(nil, v21);
}



/* Code for maprint */

static Lisp_Object CC_maprint(Lisp_Object env,
                         Lisp_Object v16, Lisp_Object v63)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v249, v168, v167;
    Lisp_Object fn;
    if (stack >= stacklimit)
    {
        push2(v63,v16);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v16,v63);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    v249 = v63;
    stack[-3] = v16;
/* end of prologue */
    stack[-4] = qvalue(elt(env, 1)); /* p!*!* */
    qvalue(elt(env, 1)) = nil; /* p!*!* */
    qvalue(elt(env, 1)) = v249; /* p!*!* */
    stack[0] = nil;
    v249 = qvalue(elt(env, 1)); /* p!*!* */
    stack[-2] = v249;
    v249 = stack[-3];
    if (v249 == nil) goto v24;
    v249 = stack[-3];
    if (!consp(v249)) goto v38;
    v249 = stack[-3];
    v249 = qcar(v249);
    if (!consp(v249)) goto v120;
    v249 = stack[-3];
    v168 = qcar(v249);
    v249 = stack[-2];
    v249 = CC_maprint(env, v168, v249);
    nil = C_nil;
    if (exception_pending()) goto v328;
    env = stack[-5];
    goto v13;

v13:
    v249 = elt(env, 4); /* "(" */
    fn = elt(env, 13); /* prin2!* */
    v249 = (*qfn1(fn))(qenv(fn), v249);
    nil = C_nil;
    if (exception_pending()) goto v328;
    env = stack[-5];
    v249 = nil;
    qvalue(elt(env, 11)) = v249; /* obrkp!* */
    v249 = qvalue(elt(env, 9)); /* orig!* */
    stack[0] = v249;
    v168 = qvalue(elt(env, 10)); /* posn!* */
    v249 = (Lisp_Object)289; /* 18 */
    v249 = (Lisp_Object)lessp2(v168, v249);
    nil = C_nil;
    if (exception_pending()) goto v328;
    v249 = v249 ? lisp_true : nil;
    env = stack[-5];
    if (v249 == nil) goto v174;
    v249 = qvalue(elt(env, 10)); /* posn!* */
    goto v203;

v203:
    qvalue(elt(env, 9)) = v249; /* orig!* */
    v249 = stack[-3];
    v249 = qcdr(v249);
    if (v249 == nil) goto v222;
    v167 = elt(env, 12); /* !*comma!* */
    v168 = (Lisp_Object)1; /* 0 */
    v249 = stack[-3];
    v249 = qcdr(v249);
    fn = elt(env, 14); /* inprint */
    v249 = (*qfnn(fn))(qenv(fn), 3, v167, v168, v249);
    nil = C_nil;
    if (exception_pending()) goto v328;
    env = stack[-5];
    goto v222;

v222:
    v249 = lisp_true;
    qvalue(elt(env, 11)) = v249; /* obrkp!* */
    v249 = stack[0];
    qvalue(elt(env, 9)) = v249; /* orig!* */
    v249 = elt(env, 5); /* ")" */
    fn = elt(env, 13); /* prin2!* */
    v249 = (*qfn1(fn))(qenv(fn), v249);
    nil = C_nil;
    if (exception_pending()) goto v328;
    env = stack[-5];
    v249 = stack[-3];
    goto v12;

v12:
    qvalue(elt(env, 1)) = stack[-4]; /* p!*!* */
    { popv(6); return onevalue(v249); }

v174:
    v168 = qvalue(elt(env, 9)); /* orig!* */
    v249 = (Lisp_Object)49; /* 3 */
    v249 = plus2(v168, v249);
    nil = C_nil;
    if (exception_pending()) goto v328;
    env = stack[-5];
    goto v203;

v120:
    v249 = stack[-3];
    v168 = qcar(v249);
    v249 = elt(env, 6); /* pprifn */
    v249 = get(v168, v249);
    env = stack[-5];
    stack[-1] = v249;
    if (v249 == nil) goto v136;
    v167 = stack[-1];
    v168 = stack[-3];
    v249 = stack[-2];
    v168 = Lapply2(nil, 3, v167, v168, v249);
    nil = C_nil;
    if (exception_pending()) goto v328;
    env = stack[-5];
    v249 = elt(env, 7); /* failed */
    if (!(v168 == v249)) goto v107;

v136:
    v249 = stack[-3];
    v168 = qcar(v249);
    v249 = elt(env, 8); /* prifn */
    v249 = get(v168, v249);
    env = stack[-5];
    stack[-1] = v249;
    if (v249 == nil) goto v216;
    v168 = stack[-1];
    v249 = stack[-3];
    v168 = Lapply1(nil, v168, v249);
    nil = C_nil;
    if (exception_pending()) goto v328;
    env = stack[-5];
    v249 = elt(env, 7); /* failed */
    if (!(v168 == v249)) goto v107;

v216:
    v249 = stack[-3];
    v168 = qcar(v249);
    v249 = elt(env, 3); /* infix */
    v249 = get(v168, v249);
    env = stack[-5];
    stack[-1] = v249;
    if (v249 == nil) goto v207;
    v168 = stack[-1];
    v249 = stack[-2];
    v249 = (Lisp_Object)greaterp2(v168, v249);
    nil = C_nil;
    if (exception_pending()) goto v328;
    v249 = v249 ? lisp_true : nil;
    env = stack[-5];
    v249 = (v249 == nil ? lisp_true : nil);
    stack[-2] = v249;
    v249 = stack[-2];
    if (v249 == nil) goto v434;
    v249 = qvalue(elt(env, 9)); /* orig!* */
    stack[0] = v249;
    v249 = elt(env, 4); /* "(" */
    fn = elt(env, 13); /* prin2!* */
    v249 = (*qfn1(fn))(qenv(fn), v249);
    nil = C_nil;
    if (exception_pending()) goto v328;
    env = stack[-5];
    v168 = qvalue(elt(env, 10)); /* posn!* */
    v249 = (Lisp_Object)289; /* 18 */
    v249 = (Lisp_Object)lessp2(v168, v249);
    nil = C_nil;
    if (exception_pending()) goto v328;
    v249 = v249 ? lisp_true : nil;
    env = stack[-5];
    if (v249 == nil) goto v227;
    v249 = qvalue(elt(env, 10)); /* posn!* */
    goto v462;

v462:
    qvalue(elt(env, 9)) = v249; /* orig!* */
    goto v434;

v434:
    v249 = stack[-3];
    v167 = qcar(v249);
    v168 = stack[-1];
    v249 = stack[-3];
    v249 = qcdr(v249);
    fn = elt(env, 14); /* inprint */
    v249 = (*qfnn(fn))(qenv(fn), 3, v167, v168, v249);
    nil = C_nil;
    if (exception_pending()) goto v328;
    env = stack[-5];
    v249 = stack[-2];
    if (v249 == nil) goto v209;
    v249 = elt(env, 5); /* ")" */
    fn = elt(env, 13); /* prin2!* */
    v249 = (*qfn1(fn))(qenv(fn), v249);
    nil = C_nil;
    if (exception_pending()) goto v328;
    env = stack[-5];
    v249 = stack[0];
    qvalue(elt(env, 9)) = v249; /* orig!* */
    goto v209;

v209:
    v249 = stack[-3];
    goto v12;

v227:
    v168 = qvalue(elt(env, 9)); /* orig!* */
    v249 = (Lisp_Object)49; /* 3 */
    v249 = plus2(v168, v249);
    nil = C_nil;
    if (exception_pending()) goto v328;
    env = stack[-5];
    goto v462;

v207:
    v249 = stack[-3];
    v249 = qcar(v249);
    fn = elt(env, 13); /* prin2!* */
    v249 = (*qfn1(fn))(qenv(fn), v249);
    nil = C_nil;
    if (exception_pending()) goto v328;
    env = stack[-5];
    goto v13;

v107:
    v249 = stack[-3];
    goto v12;

v38:
    v249 = stack[-3];
    v249 = Lsimple_vectorp(nil, v249);
    env = stack[-5];
    if (v249 == nil) goto v17;
    v168 = stack[-3];
    v249 = qvalue(elt(env, 1)); /* p!*!* */
    fn = elt(env, 15); /* vec!-maprin */
    v249 = (*qfn2(fn))(qenv(fn), v168, v249);
    nil = C_nil;
    if (exception_pending()) goto v328;
    env = stack[-5];
    goto v43;

v43:
    v249 = stack[-3];
    goto v12;

v17:
    v249 = stack[-3];
    if (!(is_number(v249))) goto v14;
    v168 = stack[-3];
    v249 = (Lisp_Object)1; /* 0 */
    v249 = (Lisp_Object)lessp2(v168, v249);
    nil = C_nil;
    if (exception_pending()) goto v328;
    v249 = v249 ? lisp_true : nil;
    env = stack[-5];
    if (v249 == nil) goto v14;
    v167 = stack[-2];
    v168 = elt(env, 2); /* minus */
    v249 = elt(env, 3); /* infix */
    v249 = get(v168, v249);
    env = stack[-5];
    v249 = (Lisp_Object)lesseq2(v167, v249);
    nil = C_nil;
    if (exception_pending()) goto v328;
    v249 = v249 ? lisp_true : nil;
    env = stack[-5];
    if (!(v249 == nil)) goto v14;
    v249 = elt(env, 4); /* "(" */
    fn = elt(env, 13); /* prin2!* */
    v249 = (*qfn1(fn))(qenv(fn), v249);
    nil = C_nil;
    if (exception_pending()) goto v328;
    env = stack[-5];
    v249 = stack[-3];
    fn = elt(env, 13); /* prin2!* */
    v249 = (*qfn1(fn))(qenv(fn), v249);
    nil = C_nil;
    if (exception_pending()) goto v328;
    env = stack[-5];
    v249 = elt(env, 5); /* ")" */
    fn = elt(env, 13); /* prin2!* */
    v249 = (*qfn1(fn))(qenv(fn), v249);
    nil = C_nil;
    if (exception_pending()) goto v328;
    env = stack[-5];
    goto v43;

v14:
    v249 = stack[-3];
    fn = elt(env, 13); /* prin2!* */
    v249 = (*qfn1(fn))(qenv(fn), v249);
    nil = C_nil;
    if (exception_pending()) goto v328;
    env = stack[-5];
    goto v43;

v24:
    v249 = nil;
    goto v12;
/* error exit handlers */
v328:
    env = stack[-5];
    qvalue(elt(env, 1)) = stack[-4]; /* p!*!* */
    popv(6);
    return nil;
}



/* Code for !*n2f */

static Lisp_Object CC_Hn2f(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v1, v2;
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
    v2 = v0;
/* end of prologue */
    v1 = v2;
    v1 = (Lisp_Object)zerop(v1);
    v1 = v1 ? lisp_true : nil;
    if (v1 == nil) return onevalue(v2);
    v1 = nil;
    return onevalue(v1);
}



/* Code for smemql */

static Lisp_Object CC_smemql(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v32, v37;
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
    v32 = stack[-1];
    if (v32 == nil) goto v6;
    v32 = stack[-1];
    v37 = qcar(v32);
    v32 = stack[0];
    v32 = Lsmemq(nil, v37, v32);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[-3];
    if (v32 == nil) goto v53;
    v32 = stack[-1];
    v37 = qcar(v32);
    v32 = stack[-2];
    v32 = cons(v37, v32);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[-3];
    stack[-2] = v32;
    v32 = stack[-1];
    v32 = qcdr(v32);
    stack[-1] = v32;
    goto v12;

v53:
    v32 = stack[-1];
    v32 = qcdr(v32);
    stack[-1] = v32;
    goto v12;

v6:
    v32 = stack[-2];
    {
        popv(4);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v32);
    }
/* error exit handlers */
v51:
    popv(4);
    return nil;
}



/* Code for mcharg2 */

static Lisp_Object MS_CDECL CC_mcharg2(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v16,
                         Lisp_Object v63, Lisp_Object v9, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v80, v116, v114;
    Lisp_Object fn;
    argcheck(nargs, 4, "mcharg2");
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
    push(nil);
/* copy arguments values to proper place */
    stack[-6] = v9;
    stack[-7] = v63;
    stack[-8] = v16;
    stack[-9] = v0;
/* end of prologue */
    v80 = stack[-9];
    if (v80 == nil) { Lisp_Object res = stack[-7]; popv(12); return onevalue(res); }
    v80 = stack[-9];
    v116 = qcar(v80);
    v80 = stack[-8];
    v80 = qcar(v80);
    fn = elt(env, 1); /* mchk */
    v80 = (*qfn2(fn))(qenv(fn), v116, v80);
    nil = C_nil;
    if (exception_pending()) goto v111;
    env = stack[-11];
    v116 = v80;
    v80 = stack[-9];
    v80 = qcdr(v80);
    stack[-9] = v80;
    v80 = stack[-8];
    v80 = qcdr(v80);
    stack[-8] = v80;
    v80 = v116;
    stack[-10] = v80;
    goto v30;

v30:
    v80 = stack[-10];
    if (v80 == nil) goto v46;
    v80 = stack[-10];
    v80 = qcar(v80);
    stack[-2] = v80;
    stack[-1] = stack[-9];
    v114 = stack[-2];
    v116 = stack[-8];
    v80 = stack[-6];
    fn = elt(env, 2); /* updtemplate */
    stack[0] = (*qfnn(fn))(qenv(fn), 3, v114, v116, v80);
    nil = C_nil;
    if (exception_pending()) goto v111;
    env = stack[-11];
    v116 = stack[-7];
    v80 = stack[-2];
    fn = elt(env, 3); /* msappend */
    v116 = (*qfn2(fn))(qenv(fn), v116, v80);
    nil = C_nil;
    if (exception_pending()) goto v111;
    env = stack[-11];
    v80 = stack[-6];
    v80 = CC_mcharg2(env, 4, stack[-1], stack[0], v116, v80);
    nil = C_nil;
    if (exception_pending()) goto v111;
    env = stack[-11];
    stack[-5] = v80;
    v80 = stack[-5];
    fn = elt(env, 4); /* lastpair */
    v80 = (*qfn1(fn))(qenv(fn), v80);
    nil = C_nil;
    if (exception_pending()) goto v111;
    env = stack[-11];
    stack[-4] = v80;
    v80 = stack[-10];
    v80 = qcdr(v80);
    stack[-10] = v80;
    v80 = stack[-4];
    if (!consp(v80)) goto v30;
    else goto v99;

v99:
    v80 = stack[-10];
    if (v80 == nil) { Lisp_Object res = stack[-5]; popv(12); return onevalue(res); }
    stack[-3] = stack[-4];
    v80 = stack[-10];
    v80 = qcar(v80);
    stack[-2] = v80;
    stack[-1] = stack[-9];
    v114 = stack[-2];
    v116 = stack[-8];
    v80 = stack[-6];
    fn = elt(env, 2); /* updtemplate */
    stack[0] = (*qfnn(fn))(qenv(fn), 3, v114, v116, v80);
    nil = C_nil;
    if (exception_pending()) goto v111;
    env = stack[-11];
    v116 = stack[-7];
    v80 = stack[-2];
    fn = elt(env, 3); /* msappend */
    v116 = (*qfn2(fn))(qenv(fn), v116, v80);
    nil = C_nil;
    if (exception_pending()) goto v111;
    env = stack[-11];
    v80 = stack[-6];
    v80 = CC_mcharg2(env, 4, stack[-1], stack[0], v116, v80);
    nil = C_nil;
    if (exception_pending()) goto v111;
    env = stack[-11];
    v80 = Lrplacd(nil, stack[-3], v80);
    nil = C_nil;
    if (exception_pending()) goto v111;
    env = stack[-11];
    v80 = stack[-4];
    fn = elt(env, 4); /* lastpair */
    v80 = (*qfn1(fn))(qenv(fn), v80);
    nil = C_nil;
    if (exception_pending()) goto v111;
    env = stack[-11];
    stack[-4] = v80;
    v80 = stack[-10];
    v80 = qcdr(v80);
    stack[-10] = v80;
    goto v99;

v46:
    v80 = nil;
    { popv(12); return onevalue(v80); }
/* error exit handlers */
v111:
    popv(12);
    return nil;
}



/* Code for mksf */

static Lisp_Object CC_mksf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v33, v51, v42;
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
    v51 = stack[0];
    v33 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 2); /* mksq */
    v33 = (*qfn2(fn))(qenv(fn), v51, v33);
    nil = C_nil;
    if (exception_pending()) goto v50;
    env = stack[-1];
    v42 = v33;
    v33 = v42;
    v51 = qcdr(v33);
    v33 = (Lisp_Object)17; /* 1 */
    if (v51 == v33) goto v13;
    v33 = lisp_true;
    qvalue(elt(env, 1)) = v33; /* !*sub2 */
    v51 = stack[0];
    v33 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 3); /* mksp */
    v51 = (*qfn2(fn))(qenv(fn), v51, v33);
    nil = C_nil;
    if (exception_pending()) goto v50;
    env = stack[-1];
    v33 = (Lisp_Object)17; /* 1 */
    v33 = cons(v51, v33);
    nil = C_nil;
    if (exception_pending()) goto v50;
    popv(2);
    return ncons(v33);

v13:
    v33 = v42;
    v33 = qcar(v33);
    { popv(2); return onevalue(v33); }
/* error exit handlers */
v50:
    popv(2);
    return nil;
}



/* Code for prepsqx */

static Lisp_Object CC_prepsqx(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v2, v25;
    Lisp_Object fn;
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v25 = v0;
/* end of prologue */
    v2 = qvalue(elt(env, 1)); /* !*intstr */
    if (v2 == nil) goto v6;
    v2 = v25;
    {
        fn = elt(env, 2); /* prepsq!* */
        return (*qfn1(fn))(qenv(fn), v2);
    }

v6:
    v2 = v25;
    {
        fn = elt(env, 3); /* prepsq */
        return (*qfn1(fn))(qenv(fn), v2);
    }
}



/* Code for emtch */

static Lisp_Object CC_emtch(Lisp_Object env,
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
    stack[0] = v0;
/* end of prologue */
    v47 = stack[0];
    if (!consp(v47)) { Lisp_Object res = stack[0]; popv(1); return onevalue(res); }
    v47 = stack[0];
    fn = elt(env, 1); /* opmtch */
    v47 = (*qfn1(fn))(qenv(fn), v47);
    nil = C_nil;
    if (exception_pending()) goto v29;
    v15 = v47;
    v47 = v15;
    if (v47 == nil) { Lisp_Object res = stack[0]; popv(1); return onevalue(res); }
    else { popv(1); return onevalue(v15); }
/* error exit handlers */
v29:
    popv(1);
    return nil;
}



/* Code for setkorder */

static Lisp_Object CC_setkorder(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v47, v15, v43;
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
    v43 = v0;
/* end of prologue */
    v47 = qvalue(elt(env, 1)); /* kord!* */
    stack[0] = v47;
    v15 = v43;
    v47 = stack[0];
    if (equal(v15, v47)) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v47 = v43;
    qvalue(elt(env, 1)) = v47; /* kord!* */
    v47 = nil;
    v47 = ncons(v47);
    nil = C_nil;
    if (exception_pending()) goto v17;
    env = stack[-1];
    qvalue(elt(env, 2)) = v47; /* alglist!* */
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
/* error exit handlers */
v17:
    popv(2);
    return nil;
}



/* Code for simpdiff */

static Lisp_Object CC_simpdiff(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v13;
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
    v13 = stack[0];
    fn = elt(env, 1); /* ckpreci!# */
    v13 = (*qfn1(fn))(qenv(fn), v13);
    nil = C_nil;
    if (exception_pending()) goto v27;
    env = stack[-2];
    v13 = stack[0];
    fn = elt(env, 2); /* simpcar */
    stack[-1] = (*qfn1(fn))(qenv(fn), v13);
    nil = C_nil;
    if (exception_pending()) goto v27;
    env = stack[-2];
    v13 = stack[0];
    v13 = qcdr(v13);
    fn = elt(env, 3); /* simpminus */
    v13 = (*qfn1(fn))(qenv(fn), v13);
    nil = C_nil;
    if (exception_pending()) goto v27;
    env = stack[-2];
    {
        Lisp_Object v28 = stack[-1];
        popv(3);
        fn = elt(env, 4); /* addsq */
        return (*qfn2(fn))(qenv(fn), v28, v13);
    }
/* error exit handlers */
v27:
    popv(3);
    return nil;
}



/* Code for oprin */

static Lisp_Object CC_oprin(Lisp_Object env,
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
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0;
/* end of prologue */
    v58 = stack[0];
    v122 = elt(env, 1); /* prtch */
    v122 = get(v58, v122);
    env = stack[-2];
    stack[-1] = v122;
    v122 = stack[-1];
    if (v122 == nil) goto v2;
    v122 = qvalue(elt(env, 3)); /* !*fort */
    if (v122 == nil) goto v15;
    v122 = stack[-1];
    {
        popv(3);
        fn = elt(env, 10); /* prin2!* */
        return (*qfn1(fn))(qenv(fn), v122);
    }

v15:
    v122 = qvalue(elt(env, 4)); /* !*list */
    if (v122 == nil) goto v64;
    v122 = qvalue(elt(env, 5)); /* obrkp!* */
    if (v122 == nil) goto v64;
    v58 = stack[0];
    v122 = elt(env, 6); /* (plus minus) */
    v122 = Lmemq(nil, v58, v122);
    if (v122 == nil) goto v64;
    v122 = qvalue(elt(env, 7)); /* testing!-width!* */
    if (v122 == nil) goto v50;
    v122 = lisp_true;
    qvalue(elt(env, 8)) = v122; /* overflowed!* */
    { popv(3); return onevalue(v122); }

v50:
    v122 = lisp_true;
    fn = elt(env, 11); /* terpri!* */
    v122 = (*qfn1(fn))(qenv(fn), v122);
    nil = C_nil;
    if (exception_pending()) goto v103;
    env = stack[-2];
    v122 = stack[-1];
    {
        popv(3);
        fn = elt(env, 10); /* prin2!* */
        return (*qfn1(fn))(qenv(fn), v122);
    }

v64:
    v58 = stack[0];
    v122 = elt(env, 9); /* spaced */
    v122 = Lflagp(nil, v58, v122);
    env = stack[-2];
    if (v122 == nil) goto v71;
    v122 = elt(env, 2); /* " " */
    fn = elt(env, 10); /* prin2!* */
    v122 = (*qfn1(fn))(qenv(fn), v122);
    nil = C_nil;
    if (exception_pending()) goto v103;
    env = stack[-2];
    v122 = stack[-1];
    fn = elt(env, 10); /* prin2!* */
    v122 = (*qfn1(fn))(qenv(fn), v122);
    nil = C_nil;
    if (exception_pending()) goto v103;
    env = stack[-2];
    v122 = elt(env, 2); /* " " */
    {
        popv(3);
        fn = elt(env, 10); /* prin2!* */
        return (*qfn1(fn))(qenv(fn), v122);
    }

v71:
    v122 = stack[-1];
    {
        popv(3);
        fn = elt(env, 10); /* prin2!* */
        return (*qfn1(fn))(qenv(fn), v122);
    }

v2:
    v122 = elt(env, 2); /* " " */
    fn = elt(env, 10); /* prin2!* */
    v122 = (*qfn1(fn))(qenv(fn), v122);
    nil = C_nil;
    if (exception_pending()) goto v103;
    env = stack[-2];
    v122 = stack[0];
    fn = elt(env, 10); /* prin2!* */
    v122 = (*qfn1(fn))(qenv(fn), v122);
    nil = C_nil;
    if (exception_pending()) goto v103;
    env = stack[-2];
    v122 = elt(env, 2); /* " " */
    {
        popv(3);
        fn = elt(env, 10); /* prin2!* */
        return (*qfn1(fn))(qenv(fn), v122);
    }
/* error exit handlers */
v103:
    popv(3);
    return nil;
}



/* Code for minusf */

static Lisp_Object CC_minusf(Lisp_Object env,
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
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v206 = v0;
/* end of prologue */

v3:
    v40 = v206;
    if (v40 == nil) goto v45;
    v40 = v206;
    if (!consp(v40)) goto v8;
    v40 = v206;
    v40 = qcar(v40);
    if (!consp(v40)) goto v8;
    v40 = v206;
    v40 = qcar(v40);
    v40 = qcdr(v40);
    v206 = v40;
    goto v3;

v8:
    v40 = v206;
    if (!consp(v40)) goto v17;
    v40 = v206;
    v41 = qcar(v40);
    v40 = elt(env, 1); /* minusp */
    v40 = get(v41, v40);
        return Lapply1(nil, v40, v206);

v17:
    v40 = (Lisp_Object)1; /* 0 */
        return Llessp(nil, v206, v40);

v45:
    v40 = nil;
    return onevalue(v40);
}



/* Code for cdarx */

static Lisp_Object CC_cdarx(Lisp_Object env,
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
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v8 = v0;
/* end of prologue */
    v1 = v8;
    v8 = elt(env, 1); /* cdar */
    fn = elt(env, 2); /* carx */
    v8 = (*qfn2(fn))(qenv(fn), v1, v8);
    errexit();
    v8 = qcdr(v8);
    return onevalue(v8);
}



/* Code for fkern */

static Lisp_Object CC_fkern(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v119, v98, v117;
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
    v119 = stack[-1];
    if (!consp(v119)) goto v1;
    v119 = stack[-1];
    v98 = qcar(v119);
    v119 = elt(env, 1); /* fkernfn */
    v119 = get(v98, v119);
    env = stack[-3];
    stack[-2] = v119;
    if (v119 == nil) goto v45;
    v98 = stack[-2];
    v119 = stack[-1];
        popv(4);
        return Lapply1(nil, v98, v119);

v45:
    v119 = stack[-1];
    v119 = qcar(v119);
    if (!consp(v119)) goto v51;
    v119 = qvalue(elt(env, 3)); /* exlist!* */
    goto v31;

v31:
    stack[0] = v119;
    v98 = stack[-1];
    v119 = stack[0];
    v119 = Lassoc(nil, v98, v119);
    stack[-2] = v119;
    if (!(v119 == nil)) { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
    v98 = stack[-1];
    v119 = nil;
    v119 = list2(v98, v119);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-3];
    stack[-2] = v119;
    v98 = stack[-2];
    v119 = stack[0];
    fn = elt(env, 5); /* ordad */
    v119 = (*qfn2(fn))(qenv(fn), v98, v119);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-3];
    stack[0] = v119;
    v119 = stack[-1];
    v119 = qcar(v119);
    if (!consp(v119)) goto v141;
    v119 = stack[0];
    qvalue(elt(env, 3)) = v119; /* exlist!* */
    { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }

v141:
    v119 = stack[-1];
    v119 = qcar(v119);
    v98 = ncons(v119);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-3];
    v119 = qvalue(elt(env, 4)); /* kprops!* */
    fn = elt(env, 6); /* union */
    v119 = (*qfn2(fn))(qenv(fn), v98, v119);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-3];
    qvalue(elt(env, 4)) = v119; /* kprops!* */
    v119 = stack[-1];
    v117 = qcar(v119);
    v98 = elt(env, 2); /* klist */
    v119 = stack[0];
    v119 = Lputprop(nil, 3, v117, v98, v119);
    nil = C_nil;
    if (exception_pending()) goto v139;
    { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }

v51:
    v119 = stack[-1];
    v98 = qcar(v119);
    v119 = elt(env, 2); /* klist */
    v119 = get(v98, v119);
    env = stack[-3];
    goto v31;

v1:
    v98 = stack[-1];
    v119 = nil;
    popv(4);
    return list2(v98, v119);
/* error exit handlers */
v139:
    popv(4);
    return nil;
}



/* Code for revpr */

static Lisp_Object CC_revpr(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v1, v2;
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v1 = v0;
/* end of prologue */
    v2 = v1;
    v2 = qcdr(v2);
    v1 = qcar(v1);
    return cons(v2, v1);
}



/* Code for putpline */

static Lisp_Object CC_putpline(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v121, v143, v144;
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
    v143 = qvalue(elt(env, 1)); /* posn!* */
    v121 = stack[0];
    v121 = qcar(v121);
    v121 = qcdr(v121);
    stack[-1] = (Lisp_Object)(int32)((int32)v143 + (int32)v121 - TAG_FIXNUM);
    v121 = nil;
    v143 = Llinelength(nil, v121);
    nil = C_nil;
    if (exception_pending()) goto v82;
    env = stack[-2];
    v121 = qvalue(elt(env, 2)); /* spare!* */
    v121 = (Lisp_Object)(int32)((int32)v143 - (int32)v121 + TAG_FIXNUM);
    v121 = (Lisp_Object)greaterp2(stack[-1], v121);
    nil = C_nil;
    if (exception_pending()) goto v82;
    v121 = v121 ? lisp_true : nil;
    env = stack[-2];
    if (v121 == nil) goto v52;
    v121 = lisp_true;
    fn = elt(env, 8); /* terpri!* */
    v121 = (*qfn1(fn))(qenv(fn), v121);
    nil = C_nil;
    if (exception_pending()) goto v82;
    env = stack[-2];
    goto v52;

v52:
    v143 = qvalue(elt(env, 1)); /* posn!* */
    v121 = qvalue(elt(env, 3)); /* orig!* */
    v144 = (Lisp_Object)(int32)((int32)v143 - (int32)v121 + TAG_FIXNUM);
    v143 = qvalue(elt(env, 4)); /* ycoord!* */
    v121 = stack[0];
    v121 = qcar(v121);
    v121 = qcar(v121);
    fn = elt(env, 9); /* update!-pline */
    v143 = (*qfnn(fn))(qenv(fn), 3, v144, v143, v121);
    nil = C_nil;
    if (exception_pending()) goto v82;
    env = stack[-2];
    v121 = qvalue(elt(env, 5)); /* pline!* */
    v121 = Lappend(nil, v143, v121);
    nil = C_nil;
    if (exception_pending()) goto v82;
    env = stack[-2];
    qvalue(elt(env, 5)) = v121; /* pline!* */
    v143 = qvalue(elt(env, 1)); /* posn!* */
    v121 = stack[0];
    v121 = qcar(v121);
    v121 = qcdr(v121);
    v121 = (Lisp_Object)(int32)((int32)v143 + (int32)v121 - TAG_FIXNUM);
    qvalue(elt(env, 1)) = v121; /* posn!* */
    v144 = qvalue(elt(env, 6)); /* ymin!* */
    v121 = stack[0];
    v121 = qcdr(v121);
    v143 = qcar(v121);
    v121 = qvalue(elt(env, 4)); /* ycoord!* */
    v121 = (Lisp_Object)(int32)((int32)v143 + (int32)v121 - TAG_FIXNUM);
    fn = elt(env, 10); /* min */
    v121 = (*qfn2(fn))(qenv(fn), v144, v121);
    nil = C_nil;
    if (exception_pending()) goto v82;
    env = stack[-2];
    qvalue(elt(env, 6)) = v121; /* ymin!* */
    v144 = qvalue(elt(env, 7)); /* ymax!* */
    v121 = stack[0];
    v121 = qcdr(v121);
    v143 = qcdr(v121);
    v121 = qvalue(elt(env, 4)); /* ycoord!* */
    v121 = (Lisp_Object)(int32)((int32)v143 + (int32)v121 - TAG_FIXNUM);
    fn = elt(env, 11); /* max */
    v121 = (*qfn2(fn))(qenv(fn), v144, v121);
    nil = C_nil;
    if (exception_pending()) goto v82;
    env = stack[-2];
    qvalue(elt(env, 7)) = v121; /* ymax!* */
    v121 = nil;
    { popv(3); return onevalue(v121); }
/* error exit handlers */
v82:
    popv(3);
    return nil;
}



setup_type const u02_setup[] =
{
    {"subs2f1",                 CC_subs2f1,     too_many_1,    wrong_no_1},
    {"prepsq",                  CC_prepsq,      too_many_1,    wrong_no_1},
    {"update-pline",            wrong_no_na,    wrong_no_nb,   (n_args *)CC_updateKpline},
    {"prepsqxx",                CC_prepsqxx,    too_many_1,    wrong_no_1},
    {"simpminus",               CC_simpminus,   too_many_1,    wrong_no_1},
    {"ordpa",                   too_few_2,      CC_ordpa,      wrong_no_2},
    {"setdiff",                 too_few_2,      CC_setdiff,    wrong_no_2},
    {"subs2",                   CC_subs2,       too_many_1,    wrong_no_1},
    {"ordad",                   too_few_2,      CC_ordad,      wrong_no_2},
    {"noncomperm",              CC_noncomperm,  too_many_1,    wrong_no_1},
    {"exc",                     too_few_2,      CC_exc,        wrong_no_2},
    {"mk*sq",                   CC_mkHsq,       too_many_1,    wrong_no_1},
    {"negf",                    CC_negf,        too_many_1,    wrong_no_1},
    {"simp*",                   CC_simpH,       too_many_1,    wrong_no_1},
    {"ckpreci#",                CC_ckpreciC,    too_many_1,    wrong_no_1},
    {"ord2",                    too_few_2,      CC_ord2,       wrong_no_2},
    {"prepd",                   CC_prepd,       too_many_1,    wrong_no_1},
    {"sqform",                  too_few_2,      CC_sqform,     wrong_no_2},
    {"reval1",                  too_few_2,      CC_reval1,     wrong_no_2},
    {"sinitl",                  CC_sinitl,      too_many_1,    wrong_no_1},
    {"simp",                    CC_simp,        too_many_1,    wrong_no_1},
    {"retimes1",                CC_retimes1,    too_many_1,    wrong_no_1},
    {"rationalizei",            CC_rationalizei,too_many_1,    wrong_no_1},
    {"aeval",                   CC_aeval,       too_many_1,    wrong_no_1},
    {"algid",                   too_few_2,      CC_algid,      wrong_no_2},
    {"maprint",                 too_few_2,      CC_maprint,    wrong_no_2},
    {"*n2f",                    CC_Hn2f,        too_many_1,    wrong_no_1},
    {"smemql",                  too_few_2,      CC_smemql,     wrong_no_2},
    {"mcharg2",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_mcharg2},
    {"mksf",                    CC_mksf,        too_many_1,    wrong_no_1},
    {"prepsqx",                 CC_prepsqx,     too_many_1,    wrong_no_1},
    {"emtch",                   CC_emtch,       too_many_1,    wrong_no_1},
    {"setkorder",               CC_setkorder,   too_many_1,    wrong_no_1},
    {"simpdiff",                CC_simpdiff,    too_many_1,    wrong_no_1},
    {"oprin",                   CC_oprin,       too_many_1,    wrong_no_1},
    {"minusf",                  CC_minusf,      too_many_1,    wrong_no_1},
    {"cdarx",                   CC_cdarx,       too_many_1,    wrong_no_1},
    {"fkern",                   CC_fkern,       too_many_1,    wrong_no_1},
    {"revpr",                   CC_revpr,       too_many_1,    wrong_no_1},
    {"putpline",                CC_putpline,    too_many_1,    wrong_no_1},
    {NULL, (one_args *)"u02", (two_args *)"21244 6068060 3546623", 0}
};

/* end of generated code */
