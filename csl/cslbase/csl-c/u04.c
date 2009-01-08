
/* $srcdir/../csl-c\u04.c Machine generated C code */

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


/* Code for gcdf1 */

static Lisp_Object CC_gcdf1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v461, v232;
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
    v461 = stack[-2];
    if (v461 == nil) { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }
    v461 = stack[-1];
    if (v461 == nil) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v232 = stack[-2];
    v461 = (Lisp_Object)17; /* 1 */
    if (v232 == v461) goto v24;
    v232 = stack[-1];
    v461 = (Lisp_Object)17; /* 1 */
    if (v232 == v461) goto v24;
    v461 = stack[-2];
    if (!consp(v461)) goto v48;
    v461 = stack[-2];
    v461 = qcar(v461);
    if (!consp(v461)) goto v48;
    v461 = stack[-1];
    if (!consp(v461)) goto v100;
    v461 = stack[-1];
    v461 = qcar(v461);
    if (!consp(v461)) goto v100;
    v461 = stack[-2];
    fn = elt(env, 5); /* num!-exponents */
    v461 = (*qfn1(fn))(qenv(fn), v461);
    nil = C_nil;
    if (exception_pending()) goto v89;
    env = stack[-4];
    if (v461 == nil) goto v96;
    v461 = stack[-1];
    fn = elt(env, 5); /* num!-exponents */
    v461 = (*qfn1(fn))(qenv(fn), v461);
    nil = C_nil;
    if (exception_pending()) goto v89;
    env = stack[-4];
    if (v461 == nil) goto v96;
    v232 = stack[-2];
    v461 = stack[-1];
    fn = elt(env, 6); /* quotf1 */
    v461 = (*qfn2(fn))(qenv(fn), v232, v461);
    nil = C_nil;
    if (exception_pending()) goto v89;
    env = stack[-4];
    if (!(v461 == nil)) { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }
    v232 = stack[-1];
    v461 = stack[-2];
    fn = elt(env, 6); /* quotf1 */
    v461 = (*qfn2(fn))(qenv(fn), v232, v461);
    nil = C_nil;
    if (exception_pending()) goto v89;
    env = stack[-4];
    if (!(v461 == nil)) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }

v96:
    v232 = stack[-2];
    v461 = stack[-1];
    fn = elt(env, 7); /* gcdf2 */
    v461 = (*qfn2(fn))(qenv(fn), v232, v461);
    nil = C_nil;
    if (exception_pending()) goto v89;
    env = stack[-4];
    stack[-3] = v461;
    v461 = qvalue(elt(env, 1)); /* !*gcd */
    if (v461 == nil) { Lisp_Object res = stack[-3]; popv(5); return onevalue(res); }
    v232 = qvalue(elt(env, 2)); /* dmode!* */
    v461 = elt(env, 3); /* (!:rd!: !:cr!:) */
    v461 = Lmemq(nil, v232, v461);
    if (!(v461 == nil)) { Lisp_Object res = stack[-3]; popv(5); return onevalue(res); }
    v232 = stack[-2];
    v461 = stack[-3];
    fn = elt(env, 6); /* quotf1 */
    v461 = (*qfn2(fn))(qenv(fn), v232, v461);
    nil = C_nil;
    if (exception_pending()) goto v89;
    env = stack[-4];
    if (v461 == nil) goto v121;
    v232 = stack[-1];
    v461 = stack[-3];
    fn = elt(env, 6); /* quotf1 */
    v461 = (*qfn2(fn))(qenv(fn), v232, v461);
    nil = C_nil;
    if (exception_pending()) goto v89;
    env = stack[-4];
    if (!(v461 == nil)) { Lisp_Object res = stack[-3]; popv(5); return onevalue(res); }

v121:
    v461 = stack[-2];
    fn = elt(env, 8); /* noncomfp */
    v461 = (*qfn1(fn))(qenv(fn), v461);
    nil = C_nil;
    if (exception_pending()) goto v89;
    env = stack[-4];
    if (!(v461 == nil)) goto v132;
    v461 = stack[-1];
    fn = elt(env, 8); /* noncomfp */
    v461 = (*qfn1(fn))(qenv(fn), v461);
    nil = C_nil;
    if (exception_pending()) goto v89;
    env = stack[-4];
    if (!(v461 == nil)) goto v132;
    stack[0] = elt(env, 4); /* "gcdf failed" */
    v461 = stack[-2];
    fn = elt(env, 9); /* prepf */
    stack[-2] = (*qfn1(fn))(qenv(fn), v461);
    nil = C_nil;
    if (exception_pending()) goto v89;
    env = stack[-4];
    v461 = stack[-1];
    fn = elt(env, 9); /* prepf */
    v461 = (*qfn1(fn))(qenv(fn), v461);
    nil = C_nil;
    if (exception_pending()) goto v89;
    env = stack[-4];
    v461 = list3(stack[0], stack[-2], v461);
    nil = C_nil;
    if (exception_pending()) goto v89;
    env = stack[-4];
    fn = elt(env, 10); /* errach */
    v461 = (*qfn1(fn))(qenv(fn), v461);
    nil = C_nil;
    if (exception_pending()) goto v89;
    { Lisp_Object res = stack[-3]; popv(5); return onevalue(res); }

v132:
    v461 = (Lisp_Object)17; /* 1 */
    { popv(5); return onevalue(v461); }

v100:
    v232 = stack[-1];
    v461 = stack[-2];
    {
        popv(5);
        fn = elt(env, 11); /* gcdfd */
        return (*qfn2(fn))(qenv(fn), v232, v461);
    }

v48:
    v232 = stack[-2];
    v461 = stack[-1];
    {
        popv(5);
        fn = elt(env, 11); /* gcdfd */
        return (*qfn2(fn))(qenv(fn), v232, v461);
    }

v24:
    v461 = (Lisp_Object)17; /* 1 */
    { popv(5); return onevalue(v461); }
/* error exit handlers */
v89:
    popv(5);
    return nil;
}



/* Code for read!-comment1 */

static Lisp_Object CC_readKcomment1(Lisp_Object env,
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
    push2(nil, nil);
/* copy arguments values to proper place */
    v19 = v0;
/* end of prologue */
    stack[-1] = qvalue(elt(env, 1)); /* !*lower */
    qvalue(elt(env, 1)) = nil; /* !*lower */
    v19 = qvalue(elt(env, 2)); /* !*raise */
    stack[0] = v19;
    v19 = nil;
    qvalue(elt(env, 2)) = v19; /* !*raise */
    goto v12;

v12:
    v19 = qvalue(elt(env, 3)); /* crchar!* */
    fn = elt(env, 6); /* delcp */
    v19 = (*qfn1(fn))(qenv(fn), v19);
    nil = C_nil;
    if (exception_pending()) goto v23;
    env = stack[-2];
    if (v19 == nil) goto v8;
    v20 = qvalue(elt(env, 3)); /* crchar!* */
    v19 = qvalue(elt(env, 4)); /* !$eol!$ */
    if (v20 == v19) goto v8;
    v19 = elt(env, 5); /* !  */
    qvalue(elt(env, 3)) = v19; /* crchar!* */
    v19 = stack[0];
    qvalue(elt(env, 2)) = v19; /* !*raise */
    fn = elt(env, 7); /* condterpri */
    v19 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v23;
    env = stack[-2];
    v19 = nil;
    qvalue(elt(env, 1)) = stack[-1]; /* !*lower */
    { popv(3); return onevalue(v19); }

v8:
    fn = elt(env, 8); /* readch1 */
    v19 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v23;
    env = stack[-2];
    qvalue(elt(env, 3)) = v19; /* crchar!* */
    goto v12;
/* error exit handlers */
v23:
    env = stack[-2];
    qvalue(elt(env, 1)) = stack[-1]; /* !*lower */
    popv(3);
    return nil;
}



/* Code for revlis */

static Lisp_Object CC_revlis(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v33;
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
    v33 = v0;
/* end of prologue */
    stack[-3] = v33;
    v33 = stack[-3];
    if (v33 == nil) goto v8;
    v33 = stack[-3];
    v33 = qcar(v33);
    fn = elt(env, 1); /* reval */
    v33 = (*qfn1(fn))(qenv(fn), v33);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-4];
    v33 = ncons(v33);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-4];
    stack[-1] = v33;
    stack[-2] = v33;
    goto v45;

v45:
    v33 = stack[-3];
    v33 = qcdr(v33);
    stack[-3] = v33;
    v33 = stack[-3];
    if (v33 == nil) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    stack[0] = stack[-1];
    v33 = stack[-3];
    v33 = qcar(v33);
    fn = elt(env, 1); /* reval */
    v33 = (*qfn1(fn))(qenv(fn), v33);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-4];
    v33 = ncons(v33);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-4];
    v33 = Lrplacd(nil, stack[0], v33);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-4];
    v33 = stack[-1];
    v33 = qcdr(v33);
    stack[-1] = v33;
    goto v45;

v8:
    v33 = nil;
    { popv(5); return onevalue(v33); }
/* error exit handlers */
v52:
    popv(5);
    return nil;
}



/* Code for adddm */

static Lisp_Object CC_adddm(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v66, v70, v71;
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
    v70 = v16;
    v71 = v0;
/* end of prologue */
    v66 = v71;
    if (!(!consp(v66))) goto v69;
    v66 = v70;
    if (!(!consp(v66))) goto v69;
    v66 = v71;
    v66 = plus2(v66, v70);
    nil = C_nil;
    if (exception_pending()) goto v101;
    env = stack[0];
    v71 = v66;
    v66 = qvalue(elt(env, 1)); /* dmode!* */
    if (v66 == nil) goto v47;
    v70 = qvalue(elt(env, 1)); /* dmode!* */
    v66 = elt(env, 2); /* convert */
    v66 = Lflagp(nil, v70, v66);
    env = stack[0];
    if (v66 == nil) goto v47;
    v70 = qvalue(elt(env, 1)); /* dmode!* */
    v66 = elt(env, 3); /* i2d */
    v66 = get(v70, v66);
    env = stack[0];
    v70 = v71;
    v66 = Lapply1(nil, v66, v70);
    nil = C_nil;
    if (exception_pending()) goto v101;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 5); /* int!-equiv!-chk */
        return (*qfn1(fn))(qenv(fn), v66);
    }

v47:
    v66 = v71;
    {
        popv(1);
        fn = elt(env, 6); /* !*n2f */
        return (*qfn1(fn))(qenv(fn), v66);
    }

v69:
    v66 = elt(env, 4); /* plus */
    {
        popv(1);
        fn = elt(env, 7); /* dcombine */
        return (*qfnn(fn))(qenv(fn), 3, v71, v70, v66);
    }
/* error exit handlers */
v101:
    popv(1);
    return nil;
}



/* Code for opmtch */

static Lisp_Object CC_opmtch(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v110, v215, v74;
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
    v110 = stack[-5];
    v215 = qcar(v110);
    v110 = elt(env, 0); /* opmtch */
    v110 = get(v215, v110);
    env = stack[-7];
    stack[-4] = v110;
    if (v110 == nil) goto v2;
    v110 = qvalue(elt(env, 1)); /* subfg!* */
    if (v110 == nil) goto v29;
    v215 = stack[-5];
    v110 = qvalue(elt(env, 2)); /* alglist!* */
    v110 = qcdr(v110);
    v110 = Lassoc(nil, v215, v110);
    stack[-6] = v110;
    if (v110 == nil) goto v1;
    v110 = stack[-6];
    v110 = qcdr(v110);
    { popv(8); return onevalue(v110); }

v1:
    v110 = stack[-5];
    v110 = qcdr(v110);
    stack[-3] = v110;
    v110 = stack[-3];
    if (v110 == nil) goto v34;
    v110 = stack[-3];
    v110 = qcar(v110);
    fn = elt(env, 3); /* emtch */
    v110 = (*qfn1(fn))(qenv(fn), v110);
    nil = C_nil;
    if (exception_pending()) goto v89;
    env = stack[-7];
    v110 = ncons(v110);
    nil = C_nil;
    if (exception_pending()) goto v89;
    env = stack[-7];
    stack[-1] = v110;
    stack[-2] = v110;
    goto v49;

v49:
    v110 = stack[-3];
    v110 = qcdr(v110);
    stack[-3] = v110;
    v110 = stack[-3];
    if (v110 == nil) goto v54;
    stack[0] = stack[-1];
    v110 = stack[-3];
    v110 = qcar(v110);
    fn = elt(env, 3); /* emtch */
    v110 = (*qfn1(fn))(qenv(fn), v110);
    nil = C_nil;
    if (exception_pending()) goto v89;
    env = stack[-7];
    v110 = ncons(v110);
    nil = C_nil;
    if (exception_pending()) goto v89;
    env = stack[-7];
    v110 = Lrplacd(nil, stack[0], v110);
    nil = C_nil;
    if (exception_pending()) goto v89;
    env = stack[-7];
    v110 = stack[-1];
    v110 = qcdr(v110);
    stack[-1] = v110;
    goto v49;

v54:
    v110 = stack[-2];
    goto v42;

v42:
    stack[0] = v110;
    goto v5;

v5:
    v110 = stack[-4];
    if (v110 == nil) goto v148;
    v74 = stack[0];
    v110 = stack[-4];
    v110 = qcar(v110);
    v215 = qcar(v110);
    v110 = stack[-5];
    v110 = qcar(v110);
    fn = elt(env, 4); /* mcharg */
    v110 = (*qfnn(fn))(qenv(fn), 3, v74, v215, v110);
    nil = C_nil;
    if (exception_pending()) goto v89;
    env = stack[-7];
    stack[-1] = v110;
    goto v6;

v6:
    v110 = stack[-1];
    if (v110 == nil) goto v121;
    v110 = stack[-1];
    v215 = qcar(v110);
    v110 = stack[-4];
    v110 = qcar(v110);
    v110 = qcdr(v110);
    v110 = qcar(v110);
    v110 = qcdr(v110);
    v110 = Lsubla(nil, v215, v110);
    nil = C_nil;
    if (exception_pending()) goto v89;
    env = stack[-7];
    fn = elt(env, 5); /* lispeval */
    v110 = (*qfn1(fn))(qenv(fn), v110);
    nil = C_nil;
    if (exception_pending()) goto v89;
    env = stack[-7];
    if (v110 == nil) goto v237;
    v110 = stack[-1];
    v215 = qcar(v110);
    v110 = stack[-4];
    v110 = qcar(v110);
    v110 = qcdr(v110);
    v110 = qcdr(v110);
    v110 = qcar(v110);
    v110 = Lsubla(nil, v215, v110);
    nil = C_nil;
    if (exception_pending()) goto v89;
    env = stack[-7];
    stack[-6] = v110;
    goto v148;

v148:
    stack[0] = qvalue(elt(env, 2)); /* alglist!* */
    v74 = stack[-5];
    v215 = stack[-6];
    v110 = qvalue(elt(env, 2)); /* alglist!* */
    v110 = qcdr(v110);
    v110 = acons(v74, v215, v110);
    nil = C_nil;
    if (exception_pending()) goto v89;
    env = stack[-7];
    v110 = Lrplacd(nil, stack[0], v110);
    nil = C_nil;
    if (exception_pending()) goto v89;
    { Lisp_Object res = stack[-6]; popv(8); return onevalue(res); }

v237:
    v110 = stack[-1];
    v110 = qcdr(v110);
    stack[-1] = v110;
    goto v6;

v121:
    v110 = stack[-4];
    v110 = qcdr(v110);
    stack[-4] = v110;
    goto v5;

v34:
    v110 = nil;
    goto v42;

v29:
    v110 = nil;
    { popv(8); return onevalue(v110); }

v2:
    v110 = nil;
    { popv(8); return onevalue(v110); }
/* error exit handlers */
v89:
    popv(8);
    return nil;
}



/* Code for mvar_member */

static Lisp_Object CC_mvar_member(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v22, v23, v30, v99;
    Lisp_Object fn;
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v30 = v16;
    v99 = v0;
/* end of prologue */
    v23 = v99;
    v22 = v30;
    v22 = (equal(v23, v22) ? lisp_true : nil);
    if (!(v22 == nil)) return onevalue(v22);
    v22 = v30;
    if (!consp(v22)) goto v24;
    v22 = v99;
    v23 = v30;
    v23 = qcdr(v23);
    {
        fn = elt(env, 1); /* arglist_member */
        return (*qfn2(fn))(qenv(fn), v22, v23);
    }

v24:
    v22 = nil;
    return onevalue(v22);
}



/* Code for comb */

static Lisp_Object CC_comb(Lisp_Object env,
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
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-3] = v16;
    stack[-4] = v0;
/* end of prologue */
    stack[0] = nil;
    v146 = stack[-3];
    v145 = (Lisp_Object)1; /* 0 */
    if (v146 == v145) goto v7;
    v145 = stack[-4];
    v146 = Llength(nil, v145);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-6];
    v145 = stack[-3];
    v146 = difference2(v146, v145);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-6];
    stack[-5] = v146;
    v145 = (Lisp_Object)1; /* 0 */
    v145 = (Lisp_Object)lessp2(v146, v145);
    nil = C_nil;
    if (exception_pending()) goto v121;
    v145 = v145 ? lisp_true : nil;
    env = stack[-6];
    if (v145 == nil) goto v32;
    v145 = nil;
    { popv(7); return onevalue(v145); }

v32:
    v145 = (Lisp_Object)17; /* 1 */
    stack[-2] = v145;
    goto v39;

v39:
    v146 = stack[-5];
    v145 = stack[-2];
    v145 = difference2(v146, v145);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-6];
    v145 = Lminusp(nil, v145);
    env = stack[-6];
    if (v145 == nil) goto v69;
    v146 = stack[-4];
    v145 = stack[0];
    popv(7);
    return cons(v146, v145);

v69:
    stack[-1] = stack[0];
    v145 = stack[-4];
    stack[0] = qcdr(v145);
    v145 = stack[-3];
    v145 = sub1(v145);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-6];
    v146 = CC_comb(env, stack[0], v145);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-6];
    v145 = stack[-4];
    v145 = qcar(v145);
    fn = elt(env, 1); /* mapcons */
    v145 = (*qfn2(fn))(qenv(fn), v146, v145);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-6];
    fn = elt(env, 2); /* nconc!* */
    v145 = (*qfn2(fn))(qenv(fn), stack[-1], v145);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-6];
    stack[0] = v145;
    v145 = stack[-4];
    v145 = qcdr(v145);
    stack[-4] = v145;
    v145 = stack[-2];
    v145 = add1(v145);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-6];
    stack[-2] = v145;
    goto v39;

v7:
    v145 = nil;
    popv(7);
    return ncons(v145);
/* error exit handlers */
v121:
    popv(7);
    return nil;
}



/* Code for gcddd */

static Lisp_Object CC_gcddd(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v136, v233, v231;
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
    v233 = stack[-1];
    v136 = (Lisp_Object)17; /* 1 */
    if (v233 == v136) goto v4;
    v233 = stack[0];
    v136 = (Lisp_Object)17; /* 1 */
    if (v233 == v136) goto v4;
    v136 = stack[-1];
    if (!consp(v136)) goto v43;
    v136 = stack[0];
    if (!consp(v136)) goto v54;
    v136 = stack[-1];
    v233 = qcar(v136);
    v136 = elt(env, 2); /* field */
    v136 = Lflagp(nil, v233, v136);
    env = stack[-2];
    if (!(v136 == nil)) goto v86;
    v136 = stack[0];
    v233 = qcar(v136);
    v136 = elt(env, 2); /* field */
    v136 = Lflagp(nil, v233, v136);
    env = stack[-2];
    if (!(v136 == nil)) goto v86;
    v231 = stack[-1];
    v233 = stack[0];
    v136 = elt(env, 1); /* gcd */
    {
        popv(3);
        fn = elt(env, 3); /* dcombine */
        return (*qfnn(fn))(qenv(fn), 3, v231, v233, v136);
    }

v86:
    v136 = (Lisp_Object)17; /* 1 */
    { popv(3); return onevalue(v136); }

v54:
    v136 = stack[-1];
    v233 = qcar(v136);
    v136 = elt(env, 2); /* field */
    v136 = Lflagp(nil, v233, v136);
    env = stack[-2];
    if (v136 == nil) goto v103;
    v136 = (Lisp_Object)17; /* 1 */
    { popv(3); return onevalue(v136); }

v103:
    v231 = stack[-1];
    v233 = stack[0];
    v136 = elt(env, 1); /* gcd */
    {
        popv(3);
        fn = elt(env, 3); /* dcombine */
        return (*qfnn(fn))(qenv(fn), 3, v231, v233, v136);
    }

v43:
    v136 = stack[0];
    if (!consp(v136)) goto v30;
    v136 = stack[0];
    fn = elt(env, 4); /* fieldp */
    v136 = (*qfn1(fn))(qenv(fn), v136);
    nil = C_nil;
    if (exception_pending()) goto v91;
    env = stack[-2];
    if (v136 == nil) goto v50;
    v136 = (Lisp_Object)17; /* 1 */
    { popv(3); return onevalue(v136); }

v50:
    v231 = stack[-1];
    v233 = stack[0];
    v136 = elt(env, 1); /* gcd */
    {
        popv(3);
        fn = elt(env, 3); /* dcombine */
        return (*qfnn(fn))(qenv(fn), 3, v231, v233, v136);
    }

v30:
    v233 = stack[-1];
    v136 = stack[0];
        popv(3);
        return Lgcd(nil, v233, v136);

v4:
    v136 = (Lisp_Object)17; /* 1 */
    { popv(3); return onevalue(v136); }
/* error exit handlers */
v91:
    popv(3);
    return nil;
}



/* Code for token1 */

static Lisp_Object MS_CDECL CC_token1(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v425, v426;
    Lisp_Object fn;
    argcheck(nargs, 0, "token1");
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* end of prologue */
    stack[-2] = nil;
    v425 = qvalue(elt(env, 1)); /* crchar!* */
    stack[-3] = v425;
    goto v4;

v4:
    v425 = stack[-3];
    v425 = Lwhitespace_char_p(nil, v425);
    env = stack[-4];
    if (v425 == nil) goto v24;
    v426 = stack[-3];
    v425 = qvalue(elt(env, 2)); /* !$eol!$ */
    if (!(v426 == v425)) goto v13;
    v425 = qvalue(elt(env, 3)); /* !*eoldelimp */
    if (!(v425 == nil)) goto v24;

v13:
    fn = elt(env, 22); /* readch1 */
    v425 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v320;
    env = stack[-4];
    stack[-3] = v425;
    goto v4;

v24:
    v425 = stack[-3];
    v425 = Ldigitp(nil, v425);
    env = stack[-4];
    if (v425 == nil) goto v30;
    v425 = stack[-3];
    {
        popv(5);
        fn = elt(env, 23); /* token!-number */
        return (*qfn1(fn))(qenv(fn), v425);
    }

v30:
    v425 = stack[-3];
    v425 = Lalpha_char_p(nil, v425);
    env = stack[-4];
    if (!(v425 == nil)) goto v45;
    v426 = stack[-3];
    v425 = elt(env, 4); /* tokprop */
    v425 = get(v426, v425);
    env = stack[-4];
    stack[-2] = v425;
    if (v425 == nil) goto v67;
    v426 = stack[-2];
    v425 = nil;
    {
        popv(5);
        fn = elt(env, 24); /* lispapply */
        return (*qfn2(fn))(qenv(fn), v426, v425);
    }

v67:
    v426 = stack[-3];
    v425 = elt(env, 5); /* !% */
    if (!(v426 == v425)) goto v58;
    v425 = qvalue(elt(env, 6)); /* !*savecomments!* */
    if (!(v425 == nil)) goto v58;
    stack[-1] = qvalue(elt(env, 18)); /* !*lower */
    qvalue(elt(env, 18)) = nil; /* !*lower */
    v425 = qvalue(elt(env, 19)); /* !*raise */
    stack[0] = v425;
    v425 = nil;
    qvalue(elt(env, 19)) = v425; /* !*raise */
    goto v494;

v494:
    fn = elt(env, 22); /* readch1 */
    v426 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v495;
    env = stack[-4];
    v425 = qvalue(elt(env, 2)); /* !$eol!$ */
    if (!(v426 == v425)) goto v494;
    v425 = stack[0];
    qvalue(elt(env, 19)) = v425; /* !*raise */
    qvalue(elt(env, 18)) = stack[-1]; /* !*lower */
    fn = elt(env, 22); /* readch1 */
    v425 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v320;
    env = stack[-4];
    stack[-3] = v425;
    goto v4;

v58:
    v426 = stack[-3];
    v425 = elt(env, 7); /* !! */
    if (!(v426 == v425)) goto v104;
    v425 = qvalue(elt(env, 8)); /* !*micro!-version */
    if (v425 == nil) goto v12;
    v425 = qvalue(elt(env, 9)); /* !*defn */
    if (!(v425 == nil)) goto v12;

v104:
    v426 = stack[-3];
    v425 = elt(env, 10); /* !" */
    if (v426 == v425) goto v7;
    v425 = (Lisp_Object)49; /* 3 */
    qvalue(elt(env, 11)) = v425; /* ttype!* */
    v426 = stack[-3];
    v425 = qvalue(elt(env, 12)); /* !$eof!$ */
    if (!(v426 == v425)) goto v145;
    v425 = elt(env, 13); /* !  */
    qvalue(elt(env, 1)) = v425; /* crchar!* */
    fn = elt(env, 25); /* filenderr */
    v425 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v320;
    env = stack[-4];
    goto v145;

v145:
    v425 = stack[-3];
    qvalue(elt(env, 14)) = v425; /* nxtsym!* */
    v425 = stack[-3];
    fn = elt(env, 26); /* delcp */
    v425 = (*qfn1(fn))(qenv(fn), v425);
    nil = C_nil;
    if (exception_pending()) goto v320;
    env = stack[-4];
    if (v425 == nil) goto v136;
    v425 = elt(env, 13); /* !  */
    qvalue(elt(env, 1)) = v425; /* crchar!* */
    goto v138;

v138:
    v426 = stack[-3];
    v425 = elt(env, 15); /* !- */
    if (!(v426 == v425)) goto v6;
    v425 = qvalue(elt(env, 1)); /* crchar!* */
    v425 = Ldigitp(nil, v425);
    env = stack[-4];
    if (v425 == nil) goto v6;
    v425 = qvalue(elt(env, 16)); /* !*minusliter */
    if (v425 == nil) goto v6;
    v425 = qvalue(elt(env, 1)); /* crchar!* */
    fn = elt(env, 23); /* token!-number */
    v425 = (*qfn1(fn))(qenv(fn), v425);
    nil = C_nil;
    if (exception_pending()) goto v320;
    env = stack[-4];
    stack[-3] = v425;
    v425 = stack[-3];
    if (is_number(v425)) goto v190;
    v425 = stack[-3];
    stack[0] = qcdr(v425);
    v426 = elt(env, 17); /* minus */
    v425 = stack[-3];
    v425 = qcdr(v425);
    v425 = qcar(v425);
    v425 = Lapply1(nil, v426, v425);
    nil = C_nil;
    if (exception_pending()) goto v320;
    env = stack[-4];
    v425 = Lrplaca(nil, stack[0], v425);
    nil = C_nil;
    if (exception_pending()) goto v320;
    { Lisp_Object res = stack[-3]; popv(5); return onevalue(res); }

v190:
    v426 = elt(env, 17); /* minus */
    v425 = stack[-3];
        popv(5);
        return Lapply1(nil, v426, v425);

v6:
    v425 = qvalue(elt(env, 14)); /* nxtsym!* */
    { popv(5); return onevalue(v425); }

v136:
    fn = elt(env, 22); /* readch1 */
    v425 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v320;
    env = stack[-4];
    qvalue(elt(env, 1)) = v425; /* crchar!* */
    goto v138;

v7:
    stack[0] = qvalue(elt(env, 18)); /* !*lower */
    qvalue(elt(env, 18)) = nil; /* !*lower */
    v425 = qvalue(elt(env, 19)); /* !*raise */
    stack[-1] = v425;
    v425 = nil;
    qvalue(elt(env, 19)) = v425; /* !*raise */
    goto v173;

v173:
    v426 = stack[-3];
    v425 = stack[-2];
    v425 = cons(v426, v425);
    nil = C_nil;
    if (exception_pending()) goto v496;
    env = stack[-4];
    stack[-2] = v425;
    fn = elt(env, 22); /* readch1 */
    v426 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v496;
    env = stack[-4];
    stack[-3] = v426;
    v425 = qvalue(elt(env, 12)); /* !$eof!$ */
    if (v426 == v425) goto v429;
    v426 = stack[-3];
    v425 = elt(env, 10); /* !" */
    if (!(v426 == v425)) goto v173;

v299:
    v426 = stack[-3];
    v425 = stack[-2];
    v425 = cons(v426, v425);
    nil = C_nil;
    if (exception_pending()) goto v496;
    env = stack[-4];
    stack[-2] = v425;
    fn = elt(env, 22); /* readch1 */
    v425 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v496;
    env = stack[-4];
    stack[-3] = v425;
    v426 = stack[-3];
    v425 = elt(env, 10); /* !" */
    if (v426 == v425) goto v173;
    v425 = stack[-2];
    fn = elt(env, 27); /* reversip!* */
    v425 = (*qfn1(fn))(qenv(fn), v425);
    nil = C_nil;
    if (exception_pending()) goto v496;
    env = stack[-4];
    v425 = Lcompress(nil, v425);
    nil = C_nil;
    if (exception_pending()) goto v496;
    env = stack[-4];
    fn = elt(env, 28); /* mkstrng */
    v425 = (*qfn1(fn))(qenv(fn), v425);
    nil = C_nil;
    if (exception_pending()) goto v496;
    env = stack[-4];
    qvalue(elt(env, 14)) = v425; /* nxtsym!* */
    v425 = stack[-1];
    qvalue(elt(env, 19)) = v425; /* !*raise */
    qvalue(elt(env, 18)) = stack[0]; /* !*lower */
    v425 = (Lisp_Object)17; /* 1 */
    qvalue(elt(env, 11)) = v425; /* ttype!* */
    v425 = stack[-3];
    qvalue(elt(env, 1)) = v425; /* crchar!* */
    goto v6;

v429:
    v425 = stack[-1];
    qvalue(elt(env, 19)) = v425; /* !*raise */
    v425 = elt(env, 13); /* !  */
    qvalue(elt(env, 1)) = v425; /* crchar!* */
    v426 = elt(env, 21); /* "***** End-of-file in string" */
    v425 = nil;
    fn = elt(env, 29); /* lpriw */
    v425 = (*qfn2(fn))(qenv(fn), v426, v425);
    nil = C_nil;
    if (exception_pending()) goto v496;
    env = stack[-4];
    fn = elt(env, 25); /* filenderr */
    v425 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v496;
    env = stack[-4];
    goto v299;

v12:
    stack[0] = qvalue(elt(env, 18)); /* !*lower */
    qvalue(elt(env, 18)) = nil; /* !*lower */
    v425 = qvalue(elt(env, 19)); /* !*raise */
    stack[-1] = v425;
    v425 = nil;
    qvalue(elt(env, 19)) = v425; /* !*raise */
    v426 = stack[-3];
    v425 = stack[-2];
    v425 = cons(v426, v425);
    nil = C_nil;
    if (exception_pending()) goto v424;
    env = stack[-4];
    stack[-2] = v425;
    fn = elt(env, 22); /* readch1 */
    v425 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v424;
    env = stack[-4];
    stack[-3] = v425;
    v425 = stack[-1];
    qvalue(elt(env, 19)) = v425; /* !*raise */
    qvalue(elt(env, 18)) = stack[0]; /* !*lower */
    goto v45;

v45:
    v425 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 11)) = v425; /* ttype!* */
    goto v352;

v352:
    v426 = stack[-3];
    v425 = stack[-2];
    v425 = cons(v426, v425);
    nil = C_nil;
    if (exception_pending()) goto v320;
    env = stack[-4];
    stack[-2] = v425;
    fn = elt(env, 22); /* readch1 */
    v425 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v320;
    env = stack[-4];
    stack[-3] = v425;
    v425 = Ldigitp(nil, v425);
    env = stack[-4];
    if (!(v425 == nil)) goto v352;
    v425 = stack[-3];
    v425 = Lalpha_char_p(nil, v425);
    env = stack[-4];
    if (!(v425 == nil)) goto v352;
    v426 = stack[-3];
    v425 = elt(env, 7); /* !! */
    if (v426 == v425) goto v12;
    v426 = stack[-3];
    v425 = elt(env, 15); /* !- */
    if (!(v426 == v425)) goto v476;
    v425 = qvalue(elt(env, 16)); /* !*minusliter */
    if (v425 == nil) goto v476;
    v426 = elt(env, 7); /* !! */
    v425 = stack[-2];
    v425 = cons(v426, v425);
    nil = C_nil;
    if (exception_pending()) goto v320;
    env = stack[-4];
    stack[-2] = v425;
    goto v352;

v476:
    v426 = stack[-3];
    v425 = elt(env, 20); /* !_ */
    if (v426 == v425) goto v352;
    v425 = stack[-2];
    fn = elt(env, 27); /* reversip!* */
    v425 = (*qfn1(fn))(qenv(fn), v425);
    nil = C_nil;
    if (exception_pending()) goto v320;
    env = stack[-4];
    v425 = Lcompress(nil, v425);
    nil = C_nil;
    if (exception_pending()) goto v320;
    env = stack[-4];
    v425 = Lintern(nil, v425);
    nil = C_nil;
    if (exception_pending()) goto v320;
    env = stack[-4];
    qvalue(elt(env, 14)) = v425; /* nxtsym!* */
    v425 = stack[-3];
    qvalue(elt(env, 1)) = v425; /* crchar!* */
    goto v6;
/* error exit handlers */
v424:
    env = stack[-4];
    qvalue(elt(env, 18)) = stack[0]; /* !*lower */
    popv(5);
    return nil;
v496:
    env = stack[-4];
    qvalue(elt(env, 18)) = stack[0]; /* !*lower */
    popv(5);
    return nil;
v495:
    env = stack[-4];
    qvalue(elt(env, 18)) = stack[-1]; /* !*lower */
    popv(5);
    return nil;
v320:
    popv(5);
    return nil;
}



/* Code for prinfit */

static Lisp_Object MS_CDECL CC_prinfit(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v16,
                         Lisp_Object v63, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v67, v68, v56;
    Lisp_Object fn;
    argcheck(nargs, 3, "prinfit");
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
    v67 = qvalue(elt(env, 1)); /* !*nat */
    if (v67 == nil) goto v6;
    v67 = qvalue(elt(env, 2)); /* testing!-width!* */
    if (!(v67 == nil)) goto v6;
    v56 = stack[-2];
    v68 = stack[-1];
    v67 = stack[0];
    fn = elt(env, 3); /* layout!-formula */
    v67 = (*qfnn(fn))(qenv(fn), 3, v56, v68, v67);
    nil = C_nil;
    if (exception_pending()) goto v70;
    env = stack[-3];
    v68 = v67;
    v67 = v68;
    if (v67 == nil) goto v48;
    v67 = v68;
    fn = elt(env, 4); /* putpline */
    v67 = (*qfn1(fn))(qenv(fn), v67);
    nil = C_nil;
    if (exception_pending()) goto v70;
    v67 = nil;
    { popv(4); return onevalue(v67); }

v48:
    v67 = stack[0];
    if (v67 == nil) goto v40;
    v67 = stack[0];
    fn = elt(env, 5); /* oprin */
    v67 = (*qfn1(fn))(qenv(fn), v67);
    nil = C_nil;
    if (exception_pending()) goto v70;
    env = stack[-3];
    goto v40;

v40:
    v68 = stack[-2];
    v67 = stack[-1];
    {
        popv(4);
        fn = elt(env, 6); /* maprint */
        return (*qfn2(fn))(qenv(fn), v68, v67);
    }

v6:
    v67 = stack[0];
    if (v67 == nil) goto v15;
    v67 = stack[0];
    fn = elt(env, 5); /* oprin */
    v67 = (*qfn1(fn))(qenv(fn), v67);
    nil = C_nil;
    if (exception_pending()) goto v70;
    env = stack[-3];
    goto v15;

v15:
    v68 = stack[-2];
    v67 = stack[-1];
    {
        popv(4);
        fn = elt(env, 6); /* maprint */
        return (*qfn2(fn))(qenv(fn), v68, v67);
    }
/* error exit handlers */
v70:
    popv(4);
    return nil;
}



/* Code for opmtchrevop */

static Lisp_Object CC_opmtchrevop(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v30, v99;
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
    v30 = qvalue(elt(env, 1)); /* !*val */
    if (v30 == nil) goto v3;
    v99 = elt(env, 2); /* cons */
    v30 = stack[0];
    v30 = Lsmemq(nil, v99, v30);
    nil = C_nil;
    if (exception_pending()) goto v14;
    env = stack[-2];
    if (!(v30 == nil)) goto v3;
    v30 = stack[0];
    stack[-1] = qcar(v30);
    v30 = stack[0];
    v30 = qcdr(v30);
    fn = elt(env, 3); /* revlis */
    v30 = (*qfn1(fn))(qenv(fn), v30);
    nil = C_nil;
    if (exception_pending()) goto v14;
    env = stack[-2];
    v30 = cons(stack[-1], v30);
    nil = C_nil;
    if (exception_pending()) goto v14;
    env = stack[-2];
    {
        popv(3);
        fn = elt(env, 4); /* opmtch */
        return (*qfn1(fn))(qenv(fn), v30);
    }

v3:
    v30 = stack[0];
    {
        popv(3);
        fn = elt(env, 4); /* opmtch */
        return (*qfn1(fn))(qenv(fn), v30);
    }
/* error exit handlers */
v14:
    popv(3);
    return nil;
}



/* Code for updtemplate */

static Lisp_Object MS_CDECL CC_updtemplate(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v16,
                         Lisp_Object v63, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v231, v218;
    Lisp_Object fn;
    argcheck(nargs, 3, "updtemplate");
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
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-5] = v63;
    v231 = v16;
    stack[-6] = v0;
/* end of prologue */
    stack[-4] = v231;
    v231 = stack[-4];
    if (v231 == nil) goto v26;
    v231 = stack[-4];
    v231 = qcar(v231);
    stack[0] = v231;
    v218 = stack[-6];
    v231 = stack[0];
    v218 = Lsubla(nil, v218, v231);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-8];
    stack[-7] = v218;
    v231 = stack[0];
    if (equal(v218, v231)) goto v18;
    v218 = stack[-7];
    v231 = stack[-5];
    fn = elt(env, 1); /* reval!-without */
    v218 = (*qfn2(fn))(qenv(fn), v218, v231);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-8];
    stack[0] = v218;
    v231 = stack[-7];
    v231 = Lneq(nil, v218, v231);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-8];
    if (v231 == nil) goto v69;
    v231 = stack[0];
    goto v17;

v17:
    v231 = ncons(v231);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-8];
    stack[-2] = v231;
    stack[-3] = v231;
    goto v2;

v2:
    v231 = stack[-4];
    v231 = qcdr(v231);
    stack[-4] = v231;
    v231 = stack[-4];
    if (v231 == nil) { Lisp_Object res = stack[-3]; popv(9); return onevalue(res); }
    stack[-1] = stack[-2];
    v231 = stack[-4];
    v231 = qcar(v231);
    stack[0] = v231;
    v218 = stack[-6];
    v231 = stack[0];
    v218 = Lsubla(nil, v218, v231);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-8];
    stack[-7] = v218;
    v231 = stack[0];
    if (equal(v218, v231)) goto v62;
    v218 = stack[-7];
    v231 = stack[-5];
    fn = elt(env, 1); /* reval!-without */
    v218 = (*qfn2(fn))(qenv(fn), v218, v231);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-8];
    stack[0] = v218;
    v231 = stack[-7];
    v231 = Lneq(nil, v218, v231);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-8];
    if (v231 == nil) goto v223;
    v231 = stack[0];
    goto v61;

v61:
    v231 = ncons(v231);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-8];
    v231 = Lrplacd(nil, stack[-1], v231);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-8];
    v231 = stack[-2];
    v231 = qcdr(v231);
    stack[-2] = v231;
    goto v2;

v223:
    v231 = stack[-7];
    goto v61;

v62:
    v231 = stack[0];
    goto v61;

v69:
    v231 = stack[-7];
    goto v17;

v18:
    v231 = stack[0];
    goto v17;

v26:
    v231 = nil;
    { popv(9); return onevalue(v231); }
/* error exit handlers */
v80:
    popv(9);
    return nil;
}



/* Code for reordsq */

static Lisp_Object CC_reordsq(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v25;
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
    v25 = stack[0];
    v25 = qcar(v25);
    fn = elt(env, 1); /* reorder */
    stack[-1] = (*qfn1(fn))(qenv(fn), v25);
    nil = C_nil;
    if (exception_pending()) goto v26;
    env = stack[-2];
    v25 = stack[0];
    v25 = qcdr(v25);
    fn = elt(env, 1); /* reorder */
    v25 = (*qfn1(fn))(qenv(fn), v25);
    nil = C_nil;
    if (exception_pending()) goto v26;
    {
        Lisp_Object v27 = stack[-1];
        popv(3);
        return cons(v27, v25);
    }
/* error exit handlers */
v26:
    popv(3);
    return nil;
}



/* Code for invsq */

static Lisp_Object CC_invsq(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v23, v30, v99;
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
    v23 = stack[0];
    v23 = qcar(v23);
    if (!(v23 == nil)) goto v4;
    v99 = elt(env, 1); /* poly */
    v30 = (Lisp_Object)49; /* 3 */
    v23 = elt(env, 2); /* "Zero divisor" */
    fn = elt(env, 4); /* rerror */
    v23 = (*qfnn(fn))(qenv(fn), 3, v99, v30, v23);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-1];
    goto v4;

v4:
    v23 = stack[0];
    fn = elt(env, 5); /* revpr */
    v23 = (*qfn1(fn))(qenv(fn), v23);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-1];
    stack[0] = v23;
    v23 = qvalue(elt(env, 3)); /* !*rationalize */
    if (v23 == nil) goto v43;
    v23 = stack[0];
    fn = elt(env, 6); /* gcdchk */
    v23 = (*qfn1(fn))(qenv(fn), v23);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-1];
    stack[0] = v23;
    goto v43;

v43:
    v23 = stack[0];
    {
        popv(2);
        fn = elt(env, 7); /* canonsq */
        return (*qfn1(fn))(qenv(fn), v23);
    }
/* error exit handlers */
v53:
    popv(2);
    return nil;
}



/* Code for scan */

static Lisp_Object MS_CDECL CC_scan(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v447, v510, v511;
    Lisp_Object fn;
    argcheck(nargs, 0, "scan");
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* end of prologue */
    v510 = qvalue(elt(env, 1)); /* cursym!* */
    v447 = elt(env, 2); /* !*semicol!* */
    if (!(v510 == v447)) goto v45;

v12:
    fn = elt(env, 32); /* token */
    v447 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v392;
    env = stack[-3];
    qvalue(elt(env, 3)) = v447; /* nxtsym!* */
    goto v45;

v45:
    v447 = qvalue(elt(env, 3)); /* nxtsym!* */
    if (!consp(v447)) goto v48;
    v447 = qvalue(elt(env, 3)); /* nxtsym!* */
    fn = elt(env, 33); /* toknump */
    v447 = (*qfn1(fn))(qenv(fn), v447);
    nil = C_nil;
    if (exception_pending()) goto v392;
    env = stack[-3];
    if (!(v447 == nil)) goto v48;
    v447 = qvalue(elt(env, 3)); /* nxtsym!* */
    v510 = qcar(v447);
    v447 = elt(env, 30); /* string */
    if (!(v510 == v447)) goto v26;
    v447 = elt(env, 31); /* " " */
    fn = elt(env, 34); /* prin2x */
    v447 = (*qfn1(fn))(qenv(fn), v447);
    nil = C_nil;
    if (exception_pending()) goto v392;
    env = stack[-3];
    v447 = qvalue(elt(env, 3)); /* nxtsym!* */
    v447 = qcdr(v447);
    v447 = qcar(v447);
    v447 = Lmkquote(nil, v447);
    nil = C_nil;
    if (exception_pending()) goto v392;
    env = stack[-3];
    qvalue(elt(env, 3)) = v447; /* nxtsym!* */
    v447 = qcdr(v447);
    v447 = qcar(v447);
    fn = elt(env, 34); /* prin2x */
    v447 = (*qfn1(fn))(qenv(fn), v447);
    nil = C_nil;
    if (exception_pending()) goto v392;
    env = stack[-3];
    goto v26;

v26:
    v447 = qvalue(elt(env, 3)); /* nxtsym!* */
    qvalue(elt(env, 1)) = v447; /* cursym!* */
    fn = elt(env, 32); /* token */
    v447 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v392;
    env = stack[-3];
    qvalue(elt(env, 3)) = v447; /* nxtsym!* */
    v510 = qvalue(elt(env, 3)); /* nxtsym!* */
    v447 = qvalue(elt(env, 19)); /* !$eof!$ */
    if (!(v510 == v447)) goto v27;
    v510 = qvalue(elt(env, 10)); /* ttype!* */
    v447 = (Lisp_Object)49; /* 3 */
    if (!(v510 == v447)) goto v27;
    {
        popv(4);
        fn = elt(env, 35); /* filenderr */
        return (*qfnn(fn))(qenv(fn), 0);
    }

v27:
    v447 = qvalue(elt(env, 3)); /* nxtsym!* */
    if (is_number(v447)) goto v512;
    v447 = qvalue(elt(env, 3)); /* nxtsym!* */
    if (!(!consp(v447))) goto v513;
    v510 = qvalue(elt(env, 3)); /* nxtsym!* */
    v447 = elt(env, 24); /* switch!* */
    v447 = get(v510, v447);
    env = stack[-3];
    if (!(v447 == nil)) goto v513;

v512:
    v447 = elt(env, 31); /* " " */
    fn = elt(env, 34); /* prin2x */
    v447 = (*qfn1(fn))(qenv(fn), v447);
    nil = C_nil;
    if (exception_pending()) goto v392;
    env = stack[-3];
    goto v513;

v513:
    v447 = qvalue(elt(env, 1)); /* cursym!* */
    {
        popv(4);
        fn = elt(env, 36); /* addcomment */
        return (*qfn1(fn))(qenv(fn), v447);
    }

v48:
    v510 = qvalue(elt(env, 3)); /* nxtsym!* */
    v447 = elt(env, 4); /* else */
    if (v510 == v447) goto v32;
    v510 = qvalue(elt(env, 1)); /* cursym!* */
    v447 = elt(env, 2); /* !*semicol!* */
    if (!(v510 == v447)) goto v23;

v32:
    v447 = nil;
    qvalue(elt(env, 5)) = v447; /* outl!* */
    goto v23;

v23:
    v447 = qvalue(elt(env, 3)); /* nxtsym!* */
    fn = elt(env, 34); /* prin2x */
    v447 = (*qfn1(fn))(qenv(fn), v447);
    nil = C_nil;
    if (exception_pending()) goto v392;
    env = stack[-3];
    goto v5;

v5:
    v447 = qvalue(elt(env, 3)); /* nxtsym!* */
    if (!(symbolp(v447))) goto v26;
    v510 = qvalue(elt(env, 3)); /* nxtsym!* */
    v447 = elt(env, 6); /* newnam */
    v447 = get(v510, v447);
    env = stack[-3];
    stack[-1] = v447;
    if (v447 == nil) goto v85;
    v510 = stack[-1];
    v447 = qvalue(elt(env, 3)); /* nxtsym!* */
    if (equal(v510, v447)) goto v85;
    v447 = stack[-1];
    qvalue(elt(env, 3)) = v447; /* nxtsym!* */
    v447 = stack[-1];
    v447 = Lstringp(nil, v447);
    env = stack[-3];
    if (!(v447 == nil)) goto v26;
    v447 = stack[-1];
    if (!consp(v447)) goto v5;
    else goto v26;

v85:
    v510 = qvalue(elt(env, 3)); /* nxtsym!* */
    v447 = elt(env, 7); /* comment */
    if (v510 == v447) goto v61;
    v510 = qvalue(elt(env, 3)); /* nxtsym!* */
    v447 = elt(env, 9); /* !% */
    if (!(v510 == v447)) goto v327;
    v510 = qvalue(elt(env, 10)); /* ttype!* */
    v447 = (Lisp_Object)49; /* 3 */
    if (!(v510 == v447)) goto v327;
    v447 = elt(env, 11); /* percent_comment */
    fn = elt(env, 37); /* read!-comment1 */
    v447 = (*qfn1(fn))(qenv(fn), v447);
    nil = C_nil;
    if (exception_pending()) goto v392;
    env = stack[-3];
    stack[-1] = v447;
    v447 = qvalue(elt(env, 8)); /* !*comment */
    if (v447 == nil) goto v12;
    else { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }

v327:
    v510 = qvalue(elt(env, 3)); /* nxtsym!* */
    v447 = elt(env, 12); /* !#if */
    if (v510 == v447) goto v292;
    v510 = qvalue(elt(env, 3)); /* nxtsym!* */
    v447 = elt(env, 13); /* !#else */
    if (v510 == v447) goto v133;
    v510 = qvalue(elt(env, 3)); /* nxtsym!* */
    v447 = elt(env, 14); /* !#elif */
    if (v510 == v447) goto v133;
    v510 = qvalue(elt(env, 3)); /* nxtsym!* */
    v447 = elt(env, 15); /* !#endif */
    if (v510 == v447) goto v12;
    v510 = qvalue(elt(env, 3)); /* nxtsym!* */
    v447 = elt(env, 16); /* !#eval */
    if (v510 == v447) goto v124;
    v510 = qvalue(elt(env, 3)); /* nxtsym!* */
    v447 = elt(env, 18); /* !#define */
    if (v510 == v447) goto v181;
    v510 = qvalue(elt(env, 10)); /* ttype!* */
    v447 = (Lisp_Object)49; /* 3 */
    if (!(v510 == v447)) goto v26;
    v510 = qvalue(elt(env, 3)); /* nxtsym!* */
    v447 = qvalue(elt(env, 19)); /* !$eof!$ */
    if (v510 == v447) goto v252;
    v510 = qvalue(elt(env, 3)); /* nxtsym!* */
    v447 = elt(env, 20); /* !' */
    if (v510 == v447) goto v490;
    v447 = qvalue(elt(env, 22)); /* !*eoldelimp */
    if (v447 == nil) goto v165;
    v510 = qvalue(elt(env, 3)); /* nxtsym!* */
    v447 = qvalue(elt(env, 23)); /* !$eol!$ */
    if (!(v510 == v447)) goto v165;

v25:
    v447 = qvalue(elt(env, 3)); /* nxtsym!* */
    qvalue(elt(env, 29)) = v447; /* semic!* */
    v447 = elt(env, 2); /* !*semicol!* */
    {
        popv(4);
        fn = elt(env, 36); /* addcomment */
        return (*qfn1(fn))(qenv(fn), v447);
    }

v165:
    v510 = qvalue(elt(env, 3)); /* nxtsym!* */
    v447 = elt(env, 24); /* switch!* */
    v447 = get(v510, v447);
    env = stack[-3];
    stack[-1] = v447;
    if (v447 == nil) goto v26;
    v447 = stack[-1];
    v510 = qcdr(v447);
    v447 = elt(env, 2); /* !*semicol!* */
    if (!consp(v510)) goto v69;
    v510 = qcar(v510);
    if (v510 == v447) goto v25;
    else goto v69;

v69:
    v447 = qvalue(elt(env, 25)); /* crchar!* */
    v447 = Lwhitespace_char_p(nil, v447);
    env = stack[-3];
    stack[-2] = v447;
    goto v6;

v6:
    fn = elt(env, 32); /* token */
    v447 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v392;
    env = stack[-3];
    qvalue(elt(env, 3)) = v447; /* nxtsym!* */
    v510 = qvalue(elt(env, 10)); /* ttype!* */
    v447 = (Lisp_Object)49; /* 3 */
    if (!(v510 == v447)) goto v7;
    v510 = qvalue(elt(env, 3)); /* nxtsym!* */
    v447 = qvalue(elt(env, 19)); /* !$eof!$ */
    if (v510 == v447) goto v514;
    v447 = stack[-1];
    v447 = qcar(v447);
    if (v447 == nil) goto v7;
    v447 = stack[-2];
    if (!(v447 == nil)) goto v7;
    v510 = qvalue(elt(env, 3)); /* nxtsym!* */
    v447 = stack[-1];
    v447 = qcar(v447);
    v447 = Latsoc(nil, v510, v447);
    stack[0] = v447;
    if (v447 == nil) goto v7;
    v447 = qvalue(elt(env, 3)); /* nxtsym!* */
    fn = elt(env, 34); /* prin2x */
    v447 = (*qfn1(fn))(qenv(fn), v447);
    nil = C_nil;
    if (exception_pending()) goto v392;
    env = stack[-3];
    v447 = stack[0];
    v447 = qcdr(v447);
    stack[-1] = v447;
    v447 = stack[-1];
    v447 = qcar(v447);
    if (!(v447 == nil)) goto v6;
    v447 = stack[-1];
    v447 = qcdr(v447);
    v510 = qcar(v447);
    v447 = elt(env, 27); /* !*comment!* */
    if (!(v510 == v447)) goto v6;
    fn = elt(env, 38); /* read!-comment */
    v447 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v392;
    env = stack[-3];
    qvalue(elt(env, 28)) = v447; /* comment!* */
    goto v12;

v7:
    v447 = stack[-1];
    v447 = qcdr(v447);
    v447 = qcar(v447);
    qvalue(elt(env, 1)) = v447; /* cursym!* */
    v510 = qvalue(elt(env, 1)); /* cursym!* */
    v447 = elt(env, 26); /* !*rpar!* */
    if (v510 == v447) goto v27;
    v447 = qvalue(elt(env, 1)); /* cursym!* */
    {
        popv(4);
        fn = elt(env, 36); /* addcomment */
        return (*qfn1(fn))(qenv(fn), v447);
    }

v514:
    {
        popv(4);
        fn = elt(env, 35); /* filenderr */
        return (*qfnn(fn))(qenv(fn), 0);
    }

v490:
    v447 = elt(env, 21); /* "Invalid QUOTE" */
    fn = elt(env, 39); /* rederr */
    v447 = (*qfn1(fn))(qenv(fn), v447);
    nil = C_nil;
    if (exception_pending()) goto v392;
    env = stack[-3];
    goto v69;

v252:
    {
        popv(4);
        fn = elt(env, 35); /* filenderr */
        return (*qfnn(fn))(qenv(fn), 0);
    }

v181:
    fn = elt(env, 40); /* rread */
    v511 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v392;
    env = stack[-3];
    v510 = qvalue(elt(env, 17)); /* !*backtrace */
    v447 = nil;
    fn = elt(env, 41); /* errorset */
    v447 = (*qfnn(fn))(qenv(fn), 3, v511, v510, v447);
    nil = C_nil;
    if (exception_pending()) goto v392;
    env = stack[-3];
    stack[-1] = v447;
    v447 = stack[-1];
    fn = elt(env, 42); /* errorp */
    v447 = (*qfn1(fn))(qenv(fn), v447);
    nil = C_nil;
    if (exception_pending()) goto v392;
    env = stack[-3];
    if (!(v447 == nil)) goto v12;
    fn = elt(env, 40); /* rread */
    v511 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v392;
    env = stack[-3];
    v510 = qvalue(elt(env, 17)); /* !*backtrace */
    v447 = nil;
    fn = elt(env, 41); /* errorset */
    v447 = (*qfnn(fn))(qenv(fn), 3, v511, v510, v447);
    nil = C_nil;
    if (exception_pending()) goto v392;
    env = stack[-3];
    stack[0] = v447;
    v447 = stack[0];
    fn = elt(env, 42); /* errorp */
    v447 = (*qfn1(fn))(qenv(fn), v447);
    nil = C_nil;
    if (exception_pending()) goto v392;
    env = stack[-3];
    if (!(v447 == nil)) goto v12;
    v511 = stack[-1];
    v510 = elt(env, 6); /* newnam */
    v447 = stack[0];
    v447 = Lputprop(nil, 3, v511, v510, v447);
    nil = C_nil;
    if (exception_pending()) goto v392;
    env = stack[-3];
    goto v12;

v124:
    fn = elt(env, 40); /* rread */
    v511 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v392;
    env = stack[-3];
    v510 = qvalue(elt(env, 17)); /* !*backtrace */
    v447 = nil;
    fn = elt(env, 41); /* errorset */
    v447 = (*qfnn(fn))(qenv(fn), 3, v511, v510, v447);
    nil = C_nil;
    if (exception_pending()) goto v392;
    env = stack[-3];
    goto v12;

v133:
    v447 = nil;
    stack[-1] = v447;
    qvalue(elt(env, 3)) = v447; /* nxtsym!* */
    goto v330;

v330:
    v510 = qvalue(elt(env, 3)); /* nxtsym!* */
    v447 = elt(env, 15); /* !#endif */
    if (v510 == v447) goto v515;
    v510 = qvalue(elt(env, 3)); /* nxtsym!* */
    v447 = elt(env, 12); /* !#if */
    if (v510 == v447) goto v516;
    v510 = qvalue(elt(env, 3)); /* nxtsym!* */
    v447 = elt(env, 13); /* !#else */
    if (!(v510 == v447)) goto v278;
    v447 = stack[-1];
    if (v447 == nil) goto v12;
    else goto v278;

v278:
    v510 = qvalue(elt(env, 3)); /* nxtsym!* */
    v447 = elt(env, 14); /* !#elif */
    if (!(v510 == v447)) goto v517;
    v447 = stack[-1];
    if (!(v447 == nil)) goto v517;

v292:
    fn = elt(env, 40); /* rread */
    v511 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v392;
    env = stack[-3];
    v510 = qvalue(elt(env, 17)); /* !*backtrace */
    v447 = nil;
    fn = elt(env, 41); /* errorset */
    v447 = (*qfnn(fn))(qenv(fn), 3, v511, v510, v447);
    nil = C_nil;
    if (exception_pending()) goto v392;
    env = stack[-3];
    stack[-1] = v447;
    v447 = stack[-1];
    fn = elt(env, 42); /* errorp */
    v447 = (*qfn1(fn))(qenv(fn), v447);
    nil = C_nil;
    if (exception_pending()) goto v392;
    env = stack[-3];
    if (!(v447 == nil)) goto v518;
    v447 = stack[-1];
    v447 = qcar(v447);
    if (!(v447 == nil)) goto v12;

v518:
    v447 = nil;
    stack[-1] = v447;
    goto v330;

v517:
    fn = elt(env, 32); /* token */
    v447 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v392;
    env = stack[-3];
    qvalue(elt(env, 3)) = v447; /* nxtsym!* */
    v510 = qvalue(elt(env, 10)); /* ttype!* */
    v447 = (Lisp_Object)49; /* 3 */
    if (!(v510 == v447)) goto v330;
    v510 = qvalue(elt(env, 3)); /* nxtsym!* */
    v447 = qvalue(elt(env, 19)); /* !$eof!$ */
    if (!(v510 == v447)) goto v330;
    {
        popv(4);
        fn = elt(env, 35); /* filenderr */
        return (*qfnn(fn))(qenv(fn), 0);
    }

v516:
    v510 = nil;
    v447 = stack[-1];
    v447 = cons(v510, v447);
    nil = C_nil;
    if (exception_pending()) goto v392;
    env = stack[-3];
    stack[-1] = v447;
    goto v517;

v515:
    v447 = stack[-1];
    if (v447 == nil) goto v12;
    v447 = stack[-1];
    v447 = qcdr(v447);
    stack[-1] = v447;
    goto v517;

v61:
    v447 = elt(env, 7); /* comment */
    fn = elt(env, 37); /* read!-comment1 */
    v447 = (*qfn1(fn))(qenv(fn), v447);
    nil = C_nil;
    if (exception_pending()) goto v392;
    env = stack[-3];
    stack[-1] = v447;
    v447 = qvalue(elt(env, 8)); /* !*comment */
    if (v447 == nil) goto v12;
    else { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
/* error exit handlers */
v392:
    popv(4);
    return nil;
}



/* Code for kernlp */

static Lisp_Object CC_kernlp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v29, v17;
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v29 = v0;
/* end of prologue */

v3:
    v17 = v29;
    if (!consp(v17)) return onevalue(v29);
    v17 = v29;
    v17 = qcar(v17);
    if (!consp(v17)) return onevalue(v29);
    v17 = v29;
    v17 = qcdr(v17);
    if (v17 == nil) goto v13;
    v29 = nil;
    return onevalue(v29);

v13:
    v29 = qcar(v29);
    v29 = qcdr(v29);
    goto v3;
}



/* Code for multfnc */

static Lisp_Object CC_multfnc(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v181, v434, v257;
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
    v181 = stack[-2];
    v181 = qcar(v181);
    stack[0] = qcdr(v181);
    v181 = stack[-1];
    v181 = qcar(v181);
    v181 = ncons(v181);
    nil = C_nil;
    if (exception_pending()) goto v509;
    env = stack[-4];
    fn = elt(env, 2); /* multf */
    v181 = (*qfn2(fn))(qenv(fn), stack[0], v181);
    nil = C_nil;
    if (exception_pending()) goto v509;
    env = stack[-4];
    stack[-3] = v181;
    v181 = stack[-3];
    if (v181 == nil) goto v125;
    v181 = stack[-3];
    if (!consp(v181)) goto v17;
    v181 = stack[-3];
    v181 = qcar(v181);
    if (!consp(v181)) goto v17;
    v181 = stack[-3];
    v181 = qcar(v181);
    v181 = qcar(v181);
    v434 = qcar(v181);
    v181 = stack[-2];
    v181 = qcar(v181);
    v181 = qcar(v181);
    v181 = qcar(v181);
    if (!(v434 == v181)) goto v17;
    v181 = stack[-2];
    v181 = qcar(v181);
    v181 = qcar(v181);
    stack[0] = qcar(v181);
    v181 = stack[-2];
    v181 = qcar(v181);
    v181 = qcar(v181);
    v434 = qcdr(v181);
    v181 = stack[-3];
    v181 = qcar(v181);
    v181 = qcar(v181);
    v181 = qcdr(v181);
    v181 = plus2(v434, v181);
    nil = C_nil;
    if (exception_pending()) goto v509;
    env = stack[-4];
    fn = elt(env, 3); /* mkspm */
    v181 = (*qfn2(fn))(qenv(fn), stack[0], v181);
    nil = C_nil;
    if (exception_pending()) goto v509;
    env = stack[-4];
    v257 = v181;
    if (v181 == nil) goto v206;
    v434 = v257;
    v181 = (Lisp_Object)17; /* 1 */
    if (v434 == v181) goto v95;
    v434 = v257;
    v181 = stack[-3];
    v181 = qcar(v181);
    v181 = qcdr(v181);
    v181 = cons(v434, v181);
    nil = C_nil;
    if (exception_pending()) goto v509;
    env = stack[-4];
    v181 = ncons(v181);
    nil = C_nil;
    if (exception_pending()) goto v509;
    env = stack[-4];
    stack[0] = v181;
    goto v135;

v135:
    v181 = stack[-2];
    v181 = qcar(v181);
    v434 = qcar(v181);
    v181 = (Lisp_Object)17; /* 1 */
    v181 = cons(v434, v181);
    nil = C_nil;
    if (exception_pending()) goto v509;
    env = stack[-4];
    v434 = ncons(v181);
    nil = C_nil;
    if (exception_pending()) goto v509;
    env = stack[-4];
    v181 = stack[-3];
    v181 = qcdr(v181);
    fn = elt(env, 2); /* multf */
    v181 = (*qfn2(fn))(qenv(fn), v434, v181);
    nil = C_nil;
    if (exception_pending()) goto v509;
    env = stack[-4];
    fn = elt(env, 4); /* addf */
    v181 = (*qfn2(fn))(qenv(fn), stack[0], v181);
    nil = C_nil;
    if (exception_pending()) goto v509;
    env = stack[-4];
    stack[-3] = v181;
    goto v125;

v125:
    v181 = stack[-2];
    v434 = qcdr(v181);
    v181 = stack[-1];
    fn = elt(env, 2); /* multf */
    stack[0] = (*qfn2(fn))(qenv(fn), v434, v181);
    nil = C_nil;
    if (exception_pending()) goto v509;
    env = stack[-4];
    v181 = stack[-2];
    v181 = qcar(v181);
    v434 = ncons(v181);
    nil = C_nil;
    if (exception_pending()) goto v509;
    env = stack[-4];
    v181 = stack[-1];
    v181 = qcdr(v181);
    fn = elt(env, 2); /* multf */
    v181 = (*qfn2(fn))(qenv(fn), v434, v181);
    nil = C_nil;
    if (exception_pending()) goto v509;
    env = stack[-4];
    fn = elt(env, 4); /* addf */
    v181 = (*qfn2(fn))(qenv(fn), stack[0], v181);
    nil = C_nil;
    if (exception_pending()) goto v509;
    env = stack[-4];
    {
        Lisp_Object v471 = stack[-3];
        popv(5);
        fn = elt(env, 4); /* addf */
        return (*qfn2(fn))(qenv(fn), v471, v181);
    }

v95:
    v181 = stack[-3];
    v181 = qcar(v181);
    v181 = qcdr(v181);
    stack[0] = v181;
    goto v135;

v206:
    v181 = nil;
    stack[0] = v181;
    goto v135;

v17:
    v181 = stack[-2];
    v181 = qcar(v181);
    v181 = qcar(v181);
    v181 = qcar(v181);
    fn = elt(env, 5); /* noncomp */
    v181 = (*qfn1(fn))(qenv(fn), v181);
    nil = C_nil;
    if (exception_pending()) goto v509;
    env = stack[-4];
    if (v181 == nil) goto v213;
    v181 = stack[-2];
    v181 = qcar(v181);
    v434 = qcar(v181);
    v181 = stack[-3];
    v181 = cons(v434, v181);
    nil = C_nil;
    if (exception_pending()) goto v509;
    env = stack[-4];
    v181 = ncons(v181);
    nil = C_nil;
    if (exception_pending()) goto v509;
    env = stack[-4];
    stack[-3] = v181;
    goto v125;

v213:
    v181 = lisp_true;
    stack[0] = qvalue(elt(env, 1)); /* !*!*processed */
    qvalue(elt(env, 1)) = v181; /* !*!*processed */
    v181 = stack[-2];
    v181 = qcar(v181);
    v434 = qcar(v181);
    v181 = (Lisp_Object)17; /* 1 */
    v181 = cons(v434, v181);
    nil = C_nil;
    if (exception_pending()) goto v460;
    env = stack[-4];
    v434 = ncons(v181);
    nil = C_nil;
    if (exception_pending()) goto v460;
    env = stack[-4];
    v181 = stack[-3];
    fn = elt(env, 2); /* multf */
    v181 = (*qfn2(fn))(qenv(fn), v434, v181);
    nil = C_nil;
    if (exception_pending()) goto v460;
    env = stack[-4];
    stack[-3] = v181;
    qvalue(elt(env, 1)) = stack[0]; /* !*!*processed */
    goto v125;
/* error exit handlers */
v460:
    env = stack[-4];
    qvalue(elt(env, 1)) = stack[0]; /* !*!*processed */
    popv(5);
    return nil;
v509:
    popv(5);
    return nil;
}



/* Code for remove!-free!-vars!-l */

static Lisp_Object CC_removeKfreeKvarsKl(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v206, v41, v64;
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

v3:
    v206 = stack[0];
    if (!consp(v206)) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v206 = stack[0];
    v41 = qcar(v206);
    v206 = elt(env, 1); /* !*sq */
    if (v41 == v206) goto v8;
    v206 = stack[0];
    v206 = qcar(v206);
    fn = elt(env, 2); /* remove!-free!-vars */
    stack[-1] = (*qfn1(fn))(qenv(fn), v206);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-2];
    v206 = stack[0];
    v206 = qcdr(v206);
    v206 = CC_removeKfreeKvarsKl(env, v206);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-2];
    v206 = cons(stack[-1], v206);
    nil = C_nil;
    if (exception_pending()) goto v134;
    v64 = v206;
    v41 = v64;
    v206 = stack[0];
    if (equal(v41, v206)) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    else { popv(3); return onevalue(v64); }

v8:
    v206 = stack[0];
    v206 = qcdr(v206);
    v206 = qcar(v206);
    fn = elt(env, 3); /* prepsq!* */
    v206 = (*qfn1(fn))(qenv(fn), v206);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-2];
    stack[0] = v206;
    goto v3;
/* error exit handlers */
v134:
    popv(3);
    return nil;
}



/* Code for simpexpon */

static Lisp_Object CC_simpexpon(Lisp_Object env,
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
    v7 = elt(env, 1); /* simp!* */
    {
        fn = elt(env, 2); /* simpexpon1 */
        return (*qfn2(fn))(qenv(fn), v8, v7);
    }
}



/* Code for subs3f1 */

static Lisp_Object MS_CDECL CC_subs3f1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v16,
                         Lisp_Object v63, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v147, v148, v213;
    Lisp_Object fn;
    argcheck(nargs, 3, "subs3f1");
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
    v148 = nil;
    v147 = (Lisp_Object)17; /* 1 */
    v147 = cons(v148, v147);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-4];
    stack[-3] = v147;
    goto v5;

v5:
    v147 = stack[-2];
    if (v147 == nil) { Lisp_Object res = stack[-3]; popv(5); return onevalue(res); }
    v147 = stack[-2];
    if (!consp(v147)) goto v30;
    v147 = stack[-2];
    v147 = qcar(v147);
    if (!consp(v147)) goto v30;
    v147 = stack[0];
    if (v147 == nil) goto v69;
    v147 = stack[-2];
    v147 = qcar(v147);
    v147 = qcdr(v147);
    if (!consp(v147)) goto v326;
    v147 = stack[-2];
    v147 = qcar(v147);
    v147 = qcdr(v147);
    v147 = qcar(v147);
    if (!(!consp(v147))) goto v69;

v326:
    v147 = stack[-2];
    v147 = qcar(v147);
    v148 = ncons(v147);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-4];
    v147 = (Lisp_Object)17; /* 1 */
    v147 = cons(v148, v147);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-4];
    v213 = v147;
    goto v140;

v140:
    v147 = stack[-3];
    v148 = v213;
    fn = elt(env, 5); /* addsq */
    v147 = (*qfn2(fn))(qenv(fn), v147, v148);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-4];
    stack[-3] = v147;
    v147 = stack[-2];
    v147 = qcdr(v147);
    stack[-2] = v147;
    goto v5;

v69:
    v147 = stack[-2];
    v148 = qcar(v147);
    v147 = stack[-1];
    fn = elt(env, 6); /* subs3t */
    v147 = (*qfn2(fn))(qenv(fn), v148, v147);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-4];
    v213 = v147;
    v147 = stack[0];
    if (v147 == nil) goto v140;
    v147 = qvalue(elt(env, 1)); /* mchfg!* */
    if (v147 == nil) goto v140;
    v147 = nil;
    qvalue(elt(env, 1)) = v147; /* mchfg!* */
    v147 = v213;
    v148 = qcar(v147);
    v147 = stack[-2];
    if (!(equal(v148, v147))) goto v95;
    v147 = v213;
    v148 = qcdr(v147);
    v147 = (Lisp_Object)17; /* 1 */
    if (!(v148 == v147)) goto v95;
    v148 = stack[-2];
    v147 = (Lisp_Object)17; /* 1 */
    v147 = cons(v148, v147);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-4];
    v213 = v147;
    goto v140;

v95:
    v147 = qvalue(elt(env, 2)); /* !*resubs */
    if (v147 == nil) goto v140;
    v147 = qvalue(elt(env, 3)); /* !*sub2 */
    if (!(v147 == nil)) goto v81;
    v147 = qvalue(elt(env, 4)); /* powlis1!* */
    if (!(v147 == nil)) goto v81;

v60:
    v147 = v213;
    fn = elt(env, 7); /* subs3q */
    v147 = (*qfn1(fn))(qenv(fn), v147);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-4];
    v213 = v147;
    goto v140;

v81:
    v147 = v213;
    fn = elt(env, 8); /* subs2q */
    v147 = (*qfn1(fn))(qenv(fn), v147);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-4];
    v213 = v147;
    goto v60;

v30:
    stack[0] = stack[-3];
    v148 = stack[-2];
    v147 = (Lisp_Object)17; /* 1 */
    v147 = cons(v148, v147);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-4];
    {
        Lisp_Object v111 = stack[0];
        popv(5);
        fn = elt(env, 5); /* addsq */
        return (*qfn2(fn))(qenv(fn), v111, v147);
    }
/* error exit handlers */
v149:
    popv(5);
    return nil;
}



/* Code for rmultpf */

static Lisp_Object CC_rmultpf(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v65, v103;
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
    v65 = stack[-1];
    if (v65 == nil) goto v6;
    v65 = stack[-1];
    if (!consp(v65)) goto v53;
    v65 = stack[-1];
    v65 = qcar(v65);
    if (!consp(v65)) goto v53;
    v65 = stack[-2];
    v103 = qcar(v65);
    v65 = stack[-1];
    v65 = qcar(v65);
    v65 = qcar(v65);
    v65 = qcar(v65);
    fn = elt(env, 1); /* reordop */
    v65 = (*qfn2(fn))(qenv(fn), v103, v65);
    nil = C_nil;
    if (exception_pending()) goto v220;
    env = stack[-4];
    if (!(v65 == nil)) goto v53;
    v65 = stack[-1];
    v65 = qcar(v65);
    stack[0] = qcar(v65);
    v103 = stack[-2];
    v65 = stack[-1];
    v65 = qcar(v65);
    v65 = qcdr(v65);
    v103 = CC_rmultpf(env, v103, v65);
    nil = C_nil;
    if (exception_pending()) goto v220;
    env = stack[-4];
    v65 = stack[-3];
    v65 = acons(stack[0], v103, v65);
    nil = C_nil;
    if (exception_pending()) goto v220;
    env = stack[-4];
    stack[-3] = v65;
    v65 = stack[-1];
    v65 = qcdr(v65);
    stack[-1] = v65;
    goto v12;

v53:
    stack[0] = stack[-3];
    v103 = stack[-2];
    v65 = stack[-1];
    v65 = cons(v103, v65);
    nil = C_nil;
    if (exception_pending()) goto v220;
    env = stack[-4];
    v65 = ncons(v65);
    nil = C_nil;
    if (exception_pending()) goto v220;
    env = stack[-4];
    {
        Lisp_Object v106 = stack[0];
        popv(5);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v106, v65);
    }

v6:
    v65 = stack[-3];
    {
        popv(5);
        fn = elt(env, 2); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v65);
    }
/* error exit handlers */
v220:
    popv(5);
    return nil;
}



/* Code for mkg1 */

static Lisp_Object CC_mkg1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v37, v36, v48, v33;
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
    v36 = v16;
    v48 = v0;
/* end of prologue */
    v33 = v36;
    v37 = elt(env, 1); /* nospur */
    v37 = Lflagp(nil, v33, v37);
    env = stack[0];
    if (v37 == nil) goto v26;
    v37 = elt(env, 2); /* g */
    v37 = list2star(v37, v36, v48);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 3); /* mksf */
        return (*qfn1(fn))(qenv(fn), v37);
    }

v26:
    v37 = elt(env, 2); /* g */
    v37 = list2star(v37, v36, v48);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 3); /* mksf */
        return (*qfn1(fn))(qenv(fn), v37);
    }
/* error exit handlers */
v51:
    popv(1);
    return nil;
}



/* Code for intexprlisp */

static Lisp_Object CC_intexprlisp(Lisp_Object env,
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
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v16;
    stack[-1] = v0;
/* end of prologue */

v11:
    v30 = stack[-1];
    v30 = (v30 == nil ? lisp_true : nil);
    if (!(v30 == nil)) { popv(3); return onevalue(v30); }
    v30 = stack[-1];
    v99 = qcar(v30);
    v30 = stack[0];
    fn = elt(env, 1); /* intexprnp */
    v30 = (*qfn2(fn))(qenv(fn), v99, v30);
    nil = C_nil;
    if (exception_pending()) goto v14;
    env = stack[-2];
    if (v30 == nil) goto v7;
    v30 = stack[-1];
    v99 = qcdr(v30);
    v30 = stack[0];
    stack[-1] = v99;
    stack[0] = v30;
    goto v11;

v7:
    v30 = nil;
    { popv(3); return onevalue(v30); }
/* error exit handlers */
v14:
    popv(3);
    return nil;
}



/* Code for sort */

static Lisp_Object CC_sort(Lisp_Object env,
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
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v16;
    v27 = v0;
/* end of prologue */
    v28 = v27;
    v27 = nil;
    v28 = Lappend(nil, v28, v27);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-1];
    v27 = stack[0];
    {
        popv(2);
        fn = elt(env, 1); /* stable!-sortip */
        return (*qfn2(fn))(qenv(fn), v28, v27);
    }
/* error exit handlers */
v44:
    popv(2);
    return nil;
}



/* Code for mchsarg */

static Lisp_Object MS_CDECL CC_mchsarg(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v16,
                         Lisp_Object v63, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v225, v189;
    Lisp_Object fn;
    argcheck(nargs, 3, "mchsarg");
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
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-5] = v63;
    stack[-6] = v16;
    stack[-1] = v0;
/* end of prologue */
    v225 = stack[-6];
    fn = elt(env, 2); /* mtp */
    v225 = (*qfn1(fn))(qenv(fn), v225);
    nil = C_nil;
    if (exception_pending()) goto v186;
    env = stack[-8];
    if (v225 == nil) goto v60;
    v189 = stack[-5];
    v225 = elt(env, 1); /* times */
    v225 = Lneq(nil, v189, v225);
    nil = C_nil;
    if (exception_pending()) goto v186;
    env = stack[-8];
    if (!(v225 == nil)) goto v45;
    v225 = stack[-1];
    fn = elt(env, 3); /* noncomfree */
    v225 = (*qfn1(fn))(qenv(fn), v225);
    nil = C_nil;
    if (exception_pending()) goto v186;
    env = stack[-8];
    if (!(v225 == nil)) goto v45;

v60:
    v225 = stack[-1];
    fn = elt(env, 4); /* noncomperm */
    v225 = (*qfn1(fn))(qenv(fn), v225);
    nil = C_nil;
    if (exception_pending()) goto v186;
    env = stack[-8];
    stack[-7] = v225;
    goto v85;

v85:
    v225 = stack[-7];
    if (v225 == nil) goto v234;
    v225 = stack[-7];
    v225 = qcar(v225);
    stack[-1] = v225;
    stack[0] = stack[-6];
    v225 = nil;
    v189 = ncons(v225);
    nil = C_nil;
    if (exception_pending()) goto v186;
    env = stack[-8];
    v225 = stack[-5];
    fn = elt(env, 5); /* mcharg2 */
    v225 = (*qfnn(fn))(qenv(fn), 4, stack[-1], stack[0], v189, v225);
    nil = C_nil;
    if (exception_pending()) goto v186;
    env = stack[-8];
    stack[-4] = v225;
    v225 = stack[-4];
    fn = elt(env, 6); /* lastpair */
    v225 = (*qfn1(fn))(qenv(fn), v225);
    nil = C_nil;
    if (exception_pending()) goto v186;
    env = stack[-8];
    stack[-3] = v225;
    v225 = stack[-7];
    v225 = qcdr(v225);
    stack[-7] = v225;
    v225 = stack[-3];
    if (!consp(v225)) goto v85;
    else goto v86;

v86:
    v225 = stack[-7];
    if (v225 == nil) goto v231;
    stack[-2] = stack[-3];
    v225 = stack[-7];
    v225 = qcar(v225);
    stack[-1] = v225;
    stack[0] = stack[-6];
    v225 = nil;
    v189 = ncons(v225);
    nil = C_nil;
    if (exception_pending()) goto v186;
    env = stack[-8];
    v225 = stack[-5];
    fn = elt(env, 5); /* mcharg2 */
    v225 = (*qfnn(fn))(qenv(fn), 4, stack[-1], stack[0], v189, v225);
    nil = C_nil;
    if (exception_pending()) goto v186;
    env = stack[-8];
    v225 = Lrplacd(nil, stack[-2], v225);
    nil = C_nil;
    if (exception_pending()) goto v186;
    env = stack[-8];
    v225 = stack[-3];
    fn = elt(env, 6); /* lastpair */
    v225 = (*qfn1(fn))(qenv(fn), v225);
    nil = C_nil;
    if (exception_pending()) goto v186;
    env = stack[-8];
    stack[-3] = v225;
    v225 = stack[-7];
    v225 = qcdr(v225);
    stack[-7] = v225;
    goto v86;

v231:
    v225 = stack[-4];
    goto v12;

v12:
    {
        popv(9);
        fn = elt(env, 7); /* reversip!* */
        return (*qfn1(fn))(qenv(fn), v225);
    }

v234:
    v225 = nil;
    goto v12;

v45:
    v225 = stack[-6];
    fn = elt(env, 4); /* noncomperm */
    v225 = (*qfn1(fn))(qenv(fn), v225);
    nil = C_nil;
    if (exception_pending()) goto v186;
    env = stack[-8];
    stack[-4] = v225;
    v225 = stack[-4];
    if (v225 == nil) goto v10;
    v225 = stack[-4];
    v225 = qcar(v225);
    v189 = v225;
    v225 = stack[-1];
    fn = elt(env, 8); /* pair */
    v225 = (*qfn2(fn))(qenv(fn), v189, v225);
    nil = C_nil;
    if (exception_pending()) goto v186;
    env = stack[-8];
    v225 = ncons(v225);
    nil = C_nil;
    if (exception_pending()) goto v186;
    env = stack[-8];
    stack[-2] = v225;
    stack[-3] = v225;
    goto v21;

v21:
    v225 = stack[-4];
    v225 = qcdr(v225);
    stack[-4] = v225;
    v225 = stack[-4];
    if (v225 == nil) goto v206;
    stack[0] = stack[-2];
    v225 = stack[-4];
    v225 = qcar(v225);
    v189 = v225;
    v225 = stack[-1];
    fn = elt(env, 8); /* pair */
    v225 = (*qfn2(fn))(qenv(fn), v189, v225);
    nil = C_nil;
    if (exception_pending()) goto v186;
    env = stack[-8];
    v225 = ncons(v225);
    nil = C_nil;
    if (exception_pending()) goto v186;
    env = stack[-8];
    v225 = Lrplacd(nil, stack[0], v225);
    nil = C_nil;
    if (exception_pending()) goto v186;
    env = stack[-8];
    v225 = stack[-2];
    v225 = qcdr(v225);
    stack[-2] = v225;
    goto v21;

v206:
    v225 = stack[-3];
    goto v12;

v10:
    v225 = nil;
    goto v12;
/* error exit handlers */
v186:
    popv(9);
    return nil;
}



/* Code for gcdf!* */

static Lisp_Object CC_gcdfH(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v13, v24, v26;
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
    v24 = v16;
    v26 = v0;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* !*gcd */
    qvalue(elt(env, 1)) = nil; /* !*gcd */
    v13 = lisp_true;
    qvalue(elt(env, 1)) = v13; /* !*gcd */
    v13 = v26;
    fn = elt(env, 2); /* gcdf */
    v13 = (*qfn2(fn))(qenv(fn), v13, v24);
    nil = C_nil;
    if (exception_pending()) goto v28;
    env = stack[-1];
    qvalue(elt(env, 1)) = stack[0]; /* !*gcd */
    { popv(2); return onevalue(v13); }
/* error exit handlers */
v28:
    env = stack[-1];
    qvalue(elt(env, 1)) = stack[0]; /* !*gcd */
    popv(2);
    return nil;
}



/* Code for rmplus */

static Lisp_Object CC_rmplus(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v38, v44, v47;
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v44 = v0;
/* end of prologue */
    v38 = v44;
    v47 = elt(env, 1); /* plus */
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



/* Code for rnzerop!: */

static Lisp_Object CC_rnzeropT(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v1, v2;
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v1 = v0;
/* end of prologue */
    v1 = qcdr(v1);
    v2 = qcar(v1);
    v1 = (Lisp_Object)1; /* 0 */
    v1 = (v2 == v1 ? lisp_true : nil);
    return onevalue(v1);
}



/* Code for unplus */

static Lisp_Object CC_unplus(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v103, v59, v60;
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
    v60 = nil;
    goto v4;

v4:
    v103 = stack[-1];
    if (!consp(v103)) goto v1;
    v103 = stack[-1];
    v59 = qcar(v103);
    v103 = elt(env, 1); /* plus */
    if (v59 == v103) goto v28;
    v103 = stack[-1];
    v103 = qcar(v103);
    if (!consp(v103)) goto v49;
    v103 = stack[-1];
    v59 = qcar(v103);
    v103 = elt(env, 1); /* plus */
    if (!consp(v59)) goto v49;
    v59 = qcar(v59);
    if (!(v59 == v103)) goto v49;
    stack[-2] = v60;
    v103 = stack[-1];
    v103 = qcar(v103);
    stack[0] = qcdr(v103);
    v103 = stack[-1];
    v103 = qcdr(v103);
    v103 = CC_unplus(env, v103);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-3];
    v103 = Lappend(nil, stack[0], v103);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-3];
    {
        Lisp_Object v61 = stack[-2];
        popv(4);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v61, v103);
    }

v49:
    v103 = stack[-1];
    v103 = qcar(v103);
    v59 = v60;
    v103 = cons(v103, v59);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-3];
    v60 = v103;
    v103 = stack[-1];
    v103 = qcdr(v103);
    stack[-1] = v103;
    goto v4;

v28:
    v103 = stack[-1];
    v103 = qcdr(v103);
    stack[-1] = v103;
    goto v4;

v1:
    v59 = v60;
    v103 = stack[-1];
    {
        popv(4);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v59, v103);
    }
/* error exit handlers */
v106:
    popv(4);
    return nil;
}



/* Code for prepsq!*2 */

static Lisp_Object CC_prepsqH2(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v25, v13, v24;
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
    v25 = v0;
/* end of prologue */
    v24 = v25;
    v13 = (Lisp_Object)17; /* 1 */
    v25 = nil;
    fn = elt(env, 1); /* prepsq!*1 */
    v25 = (*qfnn(fn))(qenv(fn), 3, v24, v13, v25);
    nil = C_nil;
    if (exception_pending()) goto v26;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* replus */
        return (*qfn1(fn))(qenv(fn), v25);
    }
/* error exit handlers */
v26:
    popv(1);
    return nil;
}



/* Code for sprgen1 */

static Lisp_Object CC_sprgen1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v117, v113;
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
    v117 = stack[-4];
    if (v117 == nil) goto v4;
    v117 = stack[-4];
    v117 = qcdr(v117);
    v117 = qcdr(v117);
    if (v117 == nil) goto v24;
    stack[-1] = nil;
    v117 = stack[-4];
    v117 = qcar(v117);
    stack[-5] = v117;
    v117 = stack[-4];
    v117 = qcdr(v117);
    stack[-4] = v117;
    v117 = stack[-4];
    stack[-2] = v117;
    goto v34;

v34:
    v117 = stack[-4];
    if (v117 == nil) { Lisp_Object res = stack[-1]; popv(7); return onevalue(res); }
    stack[0] = elt(env, 1); /* cons */
    v113 = stack[-5];
    v117 = stack[-4];
    v117 = qcar(v117);
    fn = elt(env, 2); /* ord2 */
    v117 = (*qfn2(fn))(qenv(fn), v113, v117);
    nil = C_nil;
    if (exception_pending()) goto v231;
    env = stack[-6];
    v117 = cons(stack[0], v117);
    nil = C_nil;
    if (exception_pending()) goto v231;
    env = stack[-6];
    fn = elt(env, 3); /* mksf */
    v117 = (*qfn1(fn))(qenv(fn), v117);
    nil = C_nil;
    if (exception_pending()) goto v231;
    env = stack[-6];
    v113 = v117;
    if (v117 == nil) goto v39;
    stack[0] = v113;
    v117 = stack[-4];
    v113 = qcar(v117);
    v117 = stack[-2];
    v113 = Ldelete(nil, v113, v117);
    nil = C_nil;
    if (exception_pending()) goto v231;
    env = stack[-6];
    v117 = stack[-3];
    v117 = CC_sprgen1(env, v113, v117);
    nil = C_nil;
    if (exception_pending()) goto v231;
    env = stack[-6];
    fn = elt(env, 4); /* multf */
    v113 = (*qfn2(fn))(qenv(fn), stack[0], v117);
    nil = C_nil;
    if (exception_pending()) goto v231;
    env = stack[-6];
    v117 = stack[-1];
    fn = elt(env, 5); /* addf */
    v117 = (*qfn2(fn))(qenv(fn), v113, v117);
    nil = C_nil;
    if (exception_pending()) goto v231;
    env = stack[-6];
    stack[-1] = v117;
    goto v39;

v39:
    v117 = stack[-3];
    v117 = (v117 == nil ? lisp_true : nil);
    stack[-3] = v117;
    v117 = stack[-4];
    v117 = qcdr(v117);
    stack[-4] = v117;
    goto v34;

v24:
    stack[0] = elt(env, 1); /* cons */
    v117 = stack[-4];
    v113 = qcar(v117);
    v117 = stack[-4];
    v117 = qcdr(v117);
    v117 = qcar(v117);
    fn = elt(env, 2); /* ord2 */
    v117 = (*qfn2(fn))(qenv(fn), v113, v117);
    nil = C_nil;
    if (exception_pending()) goto v231;
    env = stack[-6];
    v117 = cons(stack[0], v117);
    nil = C_nil;
    if (exception_pending()) goto v231;
    env = stack[-6];
    fn = elt(env, 3); /* mksf */
    v117 = (*qfn1(fn))(qenv(fn), v117);
    nil = C_nil;
    if (exception_pending()) goto v231;
    env = stack[-6];
    v113 = v117;
    v117 = stack[-3];
    if (!(v117 == nil)) { popv(7); return onevalue(v113); }
    v117 = v113;
    {
        popv(7);
        fn = elt(env, 6); /* negf */
        return (*qfn1(fn))(qenv(fn), v117);
    }

v4:
    v117 = nil;
    { popv(7); return onevalue(v117); }
/* error exit handlers */
v231:
    popv(7);
    return nil;
}



/* Code for frvarsof */

static Lisp_Object CC_frvarsof(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v105, v69, v67, v68;
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
    v69 = v16;
    v67 = v0;
/* end of prologue */

v8:
    v68 = v67;
    v105 = qvalue(elt(env, 1)); /* frlis!* */
    v105 = Lmemq(nil, v68, v105);
    if (v105 == nil) goto v7;
    v68 = v67;
    v105 = v69;
    v105 = Lmemq(nil, v68, v105);
    if (!(v105 == nil)) { popv(2); return onevalue(v69); }
    stack[0] = v69;
    v105 = v67;
    v105 = ncons(v105);
    nil = C_nil;
    if (exception_pending()) goto v54;
    {
        Lisp_Object v87 = stack[0];
        popv(2);
        return Lappend(nil, v87, v105);
    }

v7:
    v105 = v67;
    if (!consp(v105)) { popv(2); return onevalue(v69); }
    v105 = v67;
    v105 = qcdr(v105);
    stack[0] = v105;
    v105 = v67;
    v105 = qcar(v105);
    v105 = CC_frvarsof(env, v105, v69);
    nil = C_nil;
    if (exception_pending()) goto v54;
    env = stack[-1];
    v69 = v105;
    v105 = stack[0];
    v67 = v105;
    goto v8;
/* error exit handlers */
v54:
    popv(2);
    return nil;
}



/* Code for simpdot */

static Lisp_Object CC_simpdot(Lisp_Object env,
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
    v7 = elt(env, 1); /* dotord */
    {
        fn = elt(env, 2); /* mkvarg */
        return (*qfn2(fn))(qenv(fn), v8, v7);
    }
}



/* Code for gck2 */

static Lisp_Object CC_gck2(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v256, v210;
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

v4:
    v256 = stack[-1];
    if (v256 == nil) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v210 = stack[-2];
    v256 = stack[-1];
    if (equal(v210, v256)) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v256 = stack[-2];
    if (!consp(v256)) goto v47;
    v256 = stack[-2];
    v256 = qcar(v256);
    if (!consp(v256)) goto v47;
    v256 = stack[-1];
    if (!consp(v256)) goto v82;
    v256 = stack[-1];
    v256 = qcar(v256);
    if (!consp(v256)) goto v82;
    v256 = stack[-2];
    v256 = qcar(v256);
    v210 = qcar(v256);
    v256 = stack[-1];
    v256 = qcar(v256);
    v256 = qcar(v256);
    stack[-3] = v210;
    stack[0] = v256;
    v256 = stack[-3];
    v210 = qcar(v256);
    v256 = stack[0];
    v256 = qcar(v256);
    if (v210 == v256) goto v75;
    v256 = stack[-3];
    v210 = qcar(v256);
    v256 = stack[0];
    v256 = qcar(v256);
    fn = elt(env, 4); /* ordop */
    v256 = (*qfn2(fn))(qenv(fn), v210, v256);
    nil = C_nil;
    if (exception_pending()) goto v350;
    env = stack[-4];
    if (v256 == nil) goto v308;
    v256 = stack[-2];
    fn = elt(env, 5); /* cdarx */
    v210 = (*qfn1(fn))(qenv(fn), v256);
    nil = C_nil;
    if (exception_pending()) goto v350;
    env = stack[-4];
    v256 = stack[-1];
    stack[-2] = v210;
    stack[-1] = v256;
    goto v4;

v308:
    stack[0] = stack[-2];
    v256 = stack[-1];
    fn = elt(env, 5); /* cdarx */
    v256 = (*qfn1(fn))(qenv(fn), v256);
    nil = C_nil;
    if (exception_pending()) goto v350;
    env = stack[-4];
    stack[-2] = stack[0];
    stack[-1] = v256;
    goto v4;

v75:
    v256 = stack[-3];
    v210 = qcdr(v256);
    v256 = stack[0];
    v256 = qcdr(v256);
    v256 = (Lisp_Object)greaterp2(v210, v256);
    nil = C_nil;
    if (exception_pending()) goto v350;
    v256 = v256 ? lisp_true : nil;
    env = stack[-4];
    if (v256 == nil) goto v73;
    v256 = stack[0];
    stack[0] = v256;
    goto v186;

v186:
    v256 = stack[-2];
    fn = elt(env, 5); /* cdarx */
    stack[-2] = (*qfn1(fn))(qenv(fn), v256);
    nil = C_nil;
    if (exception_pending()) goto v350;
    env = stack[-4];
    v256 = stack[-1];
    fn = elt(env, 5); /* cdarx */
    v256 = (*qfn1(fn))(qenv(fn), v256);
    nil = C_nil;
    if (exception_pending()) goto v350;
    env = stack[-4];
    v256 = CC_gck2(env, stack[-2], v256);
    nil = C_nil;
    if (exception_pending()) goto v350;
    env = stack[-4];
    v256 = cons(stack[0], v256);
    nil = C_nil;
    if (exception_pending()) goto v350;
    popv(5);
    return ncons(v256);

v73:
    v256 = stack[-3];
    stack[0] = v256;
    goto v186;

v82:
    v256 = stack[-2];
    fn = elt(env, 5); /* cdarx */
    v256 = (*qfn1(fn))(qenv(fn), v256);
    nil = C_nil;
    if (exception_pending()) goto v350;
    env = stack[-4];
    stack[-2] = v256;
    goto v4;

v47:
    v256 = stack[-1];
    if (!consp(v256)) goto v33;
    v256 = stack[-1];
    v256 = qcar(v256);
    if (!consp(v256)) goto v33;
    v256 = stack[-1];
    fn = elt(env, 5); /* cdarx */
    v256 = (*qfn1(fn))(qenv(fn), v256);
    nil = C_nil;
    if (exception_pending()) goto v350;
    env = stack[-4];
    stack[-1] = v256;
    goto v4;

v33:
    v210 = qvalue(elt(env, 1)); /* dmode!* */
    v256 = elt(env, 2); /* field */
    v256 = Lflagp(nil, v210, v256);
    env = stack[-4];
    if (!(v256 == nil)) goto v32;
    v256 = stack[-2];
    v256 = Lconsp(nil, v256);
    env = stack[-4];
    if (v256 == nil) goto v35;
    v256 = stack[-2];
    v210 = qcar(v256);
    v256 = elt(env, 2); /* field */
    v256 = Lflagp(nil, v210, v256);
    env = stack[-4];
    if (!(v256 == nil)) goto v32;

v35:
    v256 = stack[-1];
    v256 = Lconsp(nil, v256);
    env = stack[-4];
    if (v256 == nil) goto v95;
    v256 = stack[-1];
    v210 = qcar(v256);
    v256 = elt(env, 2); /* field */
    v256 = Lflagp(nil, v210, v256);
    env = stack[-4];
    if (!(v256 == nil)) goto v32;

v95:
    v210 = qvalue(elt(env, 1)); /* dmode!* */
    v256 = elt(env, 3); /* !:gi!: */
    if (v210 == v256) goto v107;
    v210 = stack[-2];
    v256 = stack[-1];
    {
        popv(5);
        fn = elt(env, 6); /* gcddd */
        return (*qfn2(fn))(qenv(fn), v210, v256);
    }

v107:
    v210 = stack[-2];
    v256 = stack[-1];
    {
        popv(5);
        fn = elt(env, 7); /* intgcdd */
        return (*qfn2(fn))(qenv(fn), v210, v256);
    }

v32:
    v256 = (Lisp_Object)17; /* 1 */
    { popv(5); return onevalue(v256); }
/* error exit handlers */
v350:
    popv(5);
    return nil;
}



/* Code for terpri!* */

static Lisp_Object CC_terpriH(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v103, v59, v60;
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
    v103 = qvalue(elt(env, 1)); /* outputhandler!* */
    if (v103 == nil) goto v6;
    v59 = qvalue(elt(env, 1)); /* outputhandler!* */
    v60 = elt(env, 2); /* terpri */
    v103 = stack[0];
        popv(3);
        return Lapply2(nil, 3, v59, v60, v103);

v6:
    v103 = qvalue(elt(env, 3)); /* testing!-width!* */
    if (v103 == nil) goto v15;
    v103 = lisp_true;
    qvalue(elt(env, 4)) = v103; /* overflowed!* */
    { popv(3); return onevalue(v103); }

v15:
    v103 = qvalue(elt(env, 5)); /* !*fort */
    if (v103 == nil) goto v18;
    v103 = stack[0];
    {
        popv(3);
        fn = elt(env, 13); /* fterpri */
        return (*qfn1(fn))(qenv(fn), v103);
    }

v18:
    v103 = qvalue(elt(env, 6)); /* !*nat */
    if (v103 == nil) goto v45;
    v103 = qvalue(elt(env, 7)); /* pline!* */
    if (v103 == nil) goto v45;
    v103 = qvalue(elt(env, 7)); /* pline!* */
    v103 = Lreverse(nil, v103);
    nil = C_nil;
    if (exception_pending()) goto v220;
    env = stack[-2];
    qvalue(elt(env, 7)) = v103; /* pline!* */
    v103 = qvalue(elt(env, 8)); /* ymax!* */
    stack[-1] = v103;
    goto v193;

v193:
    v59 = stack[-1];
    v103 = qvalue(elt(env, 9)); /* ymin!* */
    v103 = difference2(v59, v103);
    nil = C_nil;
    if (exception_pending()) goto v220;
    env = stack[-2];
    v103 = Lminusp(nil, v103);
    env = stack[-2];
    if (v103 == nil) goto v150;
    v103 = nil;
    qvalue(elt(env, 7)) = v103; /* pline!* */
    goto v45;

v45:
    v103 = stack[0];
    if (v103 == nil) goto v101;
    v103 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v220;
    env = stack[-2];
    goto v101;

v101:
    v103 = qvalue(elt(env, 10)); /* orig!* */
    qvalue(elt(env, 11)) = v103; /* posn!* */
    v103 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 9)) = v103; /* ymin!* */
    qvalue(elt(env, 8)) = v103; /* ymax!* */
    qvalue(elt(env, 12)) = v103; /* ycoord!* */
    v103 = nil;
    { popv(3); return onevalue(v103); }

v150:
    v59 = qvalue(elt(env, 7)); /* pline!* */
    v103 = stack[-1];
    fn = elt(env, 14); /* scprint */
    v103 = (*qfn2(fn))(qenv(fn), v59, v103);
    nil = C_nil;
    if (exception_pending()) goto v220;
    env = stack[-2];
    v103 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v220;
    env = stack[-2];
    v103 = stack[-1];
    v103 = sub1(v103);
    nil = C_nil;
    if (exception_pending()) goto v220;
    env = stack[-2];
    stack[-1] = v103;
    goto v193;
/* error exit handlers */
v220:
    popv(3);
    return nil;
}



/* Code for canonsq */

static Lisp_Object CC_canonsq(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v175, v221, v477;
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
    v175 = stack[-1];
    v221 = qcdr(v175);
    v175 = (Lisp_Object)17; /* 1 */
    if (v221 == v175) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v175 = stack[-1];
    v175 = qcar(v175);
    if (v175 == nil) goto v38;
    v175 = qvalue(elt(env, 1)); /* asymplis!* */
    if (v175 == nil) goto v99;
    v175 = stack[-1];
    v221 = qcar(v175);
    v175 = stack[-1];
    v175 = qcdr(v175);
    fn = elt(env, 8); /* gcdf */
    v221 = (*qfn2(fn))(qenv(fn), v221, v175);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-3];
    stack[-2] = v221;
    v175 = (Lisp_Object)17; /* 1 */
    v175 = Lneq(nil, v221, v175);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-3];
    if (v175 == nil) goto v99;
    v175 = stack[-1];
    v221 = qcar(v175);
    v175 = stack[-2];
    fn = elt(env, 9); /* quotf */
    stack[0] = (*qfn2(fn))(qenv(fn), v221, v175);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-3];
    v175 = stack[-1];
    v221 = qcdr(v175);
    v175 = stack[-2];
    fn = elt(env, 9); /* quotf */
    v175 = (*qfn2(fn))(qenv(fn), v221, v175);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-3];
    v175 = cons(stack[0], v175);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-3];
    stack[-1] = v175;
    goto v99;

v99:
    v175 = stack[-1];
    v175 = qcdr(v175);
    fn = elt(env, 10); /* lnc */
    v175 = (*qfn1(fn))(qenv(fn), v175);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-3];
    stack[-2] = v175;
    v221 = stack[-2];
    v175 = (Lisp_Object)17; /* 1 */
    if (v221 == v175) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v175 = stack[-2];
    if (!consp(v175)) goto v226;
    v175 = stack[-2];
    v221 = qcar(v175);
    v175 = elt(env, 2); /* minusp */
    v221 = get(v221, v175);
    env = stack[-3];
    v175 = stack[-2];
    v175 = Lapply1(nil, v221, v175);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-3];
    if (v175 == nil) goto v61;
    v175 = stack[-1];
    v175 = qcar(v175);
    fn = elt(env, 11); /* negf */
    stack[0] = (*qfn1(fn))(qenv(fn), v175);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-3];
    v175 = stack[-1];
    v175 = qcdr(v175);
    fn = elt(env, 11); /* negf */
    v175 = (*qfn1(fn))(qenv(fn), v175);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-3];
    v175 = cons(stack[0], v175);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-3];
    stack[-1] = v175;
    v175 = stack[-2];
    v221 = qcar(v175);
    v175 = elt(env, 3); /* difference */
    stack[0] = get(v221, v175);
    env = stack[-3];
    v175 = stack[-2];
    v221 = qcar(v175);
    v175 = elt(env, 4); /* i2d */
    v221 = get(v221, v175);
    env = stack[-3];
    v175 = (Lisp_Object)1; /* 0 */
    v221 = Lapply1(nil, v221, v175);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-3];
    v175 = stack[-2];
    v175 = Lapply2(nil, 3, stack[0], v221, v175);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-3];
    stack[-2] = v175;
    goto v61;

v61:
    v175 = stack[-2];
    if (is_number(v175)) goto v350;
    v221 = qvalue(elt(env, 5)); /* dmode!* */
    v175 = elt(env, 6); /* unitsfn */
    v175 = get(v221, v175);
    env = stack[-3];
    v221 = v175;
    if (v175 == nil) goto v350;
    v477 = v221;
    v221 = stack[-1];
    v175 = stack[-2];
        popv(4);
        return Lapply2(nil, 3, v477, v221, v175);

v350:
    v221 = qvalue(elt(env, 5)); /* dmode!* */
    v175 = elt(env, 7); /* field */
    v175 = Lflagp(nil, v221, v175);
    env = stack[-3];
    if (!(v175 == nil)) goto v205;
    v175 = stack[-2];
    if (!consp(v175)) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v175 = stack[-2];
    v221 = qcar(v175);
    v175 = elt(env, 7); /* field */
    v175 = Lflagp(nil, v221, v175);
    env = stack[-3];
    if (v175 == nil) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    else goto v205;

v205:
    v221 = stack[-2];
    v175 = stack[-1];
    {
        popv(4);
        fn = elt(env, 12); /* fieldconv */
        return (*qfn2(fn))(qenv(fn), v221, v175);
    }

v226:
    v175 = stack[-2];
    v175 = Lminusp(nil, v175);
    env = stack[-3];
    if (v175 == nil) goto v61;
    v175 = stack[-1];
    v175 = qcar(v175);
    fn = elt(env, 11); /* negf */
    stack[0] = (*qfn1(fn))(qenv(fn), v175);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-3];
    v175 = stack[-1];
    v175 = qcdr(v175);
    fn = elt(env, 11); /* negf */
    v175 = (*qfn1(fn))(qenv(fn), v175);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-3];
    v175 = cons(stack[0], v175);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-3];
    stack[-1] = v175;
    v175 = stack[-2];
    v175 = negate(v175);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-3];
    stack[-2] = v175;
    goto v61;

v38:
    v221 = nil;
    v175 = (Lisp_Object)17; /* 1 */
    popv(4);
    return cons(v221, v175);
/* error exit handlers */
v305:
    popv(4);
    return nil;
}



/* Code for formop */

static Lisp_Object CC_formop(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v100, v150;
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
    goto v12;

v12:
    v100 = stack[-1];
    if (!consp(v100)) goto v45;
    v100 = stack[-1];
    v100 = qcar(v100);
    if (!consp(v100)) goto v45;
    v100 = stack[-1];
    v100 = qcar(v100);
    stack[0] = qcar(v100);
    v100 = stack[-1];
    v100 = qcar(v100);
    v100 = qcdr(v100);
    v100 = CC_formop(env, v100);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[-3];
    fn = elt(env, 1); /* multop */
    v150 = (*qfn2(fn))(qenv(fn), stack[0], v100);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[-3];
    v100 = stack[-2];
    v100 = cons(v150, v100);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[-3];
    stack[-2] = v100;
    v100 = stack[-1];
    v100 = qcdr(v100);
    stack[-1] = v100;
    goto v12;

v45:
    v100 = stack[-1];
    v150 = v100;
    goto v5;

v5:
    v100 = stack[-2];
    if (v100 == nil) { popv(4); return onevalue(v150); }
    v100 = stack[-2];
    v100 = qcar(v100);
    fn = elt(env, 2); /* raddf */
    v100 = (*qfn2(fn))(qenv(fn), v100, v150);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[-3];
    v150 = v100;
    v100 = stack[-2];
    v100 = qcdr(v100);
    stack[-2] = v100;
    goto v5;
/* error exit handlers */
v67:
    popv(4);
    return nil;
}



/* Code for multop */

static Lisp_Object CC_multop(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v51, v42, v49;
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
    v49 = v0;
/* end of prologue */
    v51 = qvalue(elt(env, 1)); /* kord!* */
    if (v51 == nil) goto v24;
    v51 = v49;
    v42 = qcar(v51);
    v51 = elt(env, 2); /* k!* */
    if (v42 == v51) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v42 = v49;
    v51 = stack[0];
    {
        popv(2);
        fn = elt(env, 3); /* rmultpf */
        return (*qfn2(fn))(qenv(fn), v42, v51);
    }

v24:
    v42 = v49;
    v51 = (Lisp_Object)17; /* 1 */
    v51 = cons(v42, v51);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-1];
    v42 = ncons(v51);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-1];
    v51 = stack[0];
    {
        popv(2);
        fn = elt(env, 4); /* multf */
        return (*qfn2(fn))(qenv(fn), v42, v51);
    }
/* error exit handlers */
v52:
    popv(2);
    return nil;
}



/* Code for simpexpon1 */

static Lisp_Object CC_simpexpon1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v193, v35;
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
    v193 = qvalue(elt(env, 1)); /* !*numval */
    if (v193 == nil) goto v99;
    v35 = qvalue(elt(env, 2)); /* dmode!* */
    v193 = elt(env, 3); /* !:rd!: */
    if (v35 == v193) goto v18;
    v35 = qvalue(elt(env, 2)); /* dmode!* */
    v193 = elt(env, 4); /* !:cr!: */
    if (!(v35 == v193)) goto v99;

v18:
    v35 = stack[-1];
    v193 = stack[-2];
        popv(5);
        return Lapply1(nil, v35, v193);

v99:
    stack[-3] = qvalue(elt(env, 2)); /* dmode!* */
    qvalue(elt(env, 2)) = nil; /* dmode!* */
    stack[0] = qvalue(elt(env, 5)); /* alglist!* */
    qvalue(elt(env, 5)) = nil; /* alglist!* */
    v193 = nil;
    v193 = ncons(v193);
    nil = C_nil;
    if (exception_pending()) goto v41;
    env = stack[-4];
    qvalue(elt(env, 5)) = v193; /* alglist!* */
    v35 = stack[-1];
    v193 = stack[-2];
    v193 = Lapply1(nil, v35, v193);
    nil = C_nil;
    if (exception_pending()) goto v41;
    env = stack[-4];
    qvalue(elt(env, 5)) = stack[0]; /* alglist!* */
    qvalue(elt(env, 2)) = stack[-3]; /* dmode!* */
    { popv(5); return onevalue(v193); }
/* error exit handlers */
v41:
    env = stack[-4];
    qvalue(elt(env, 5)) = stack[0]; /* alglist!* */
    qvalue(elt(env, 2)) = stack[-3]; /* dmode!* */
    popv(5);
    return nil;
}



/* Code for subs3q */

static Lisp_Object CC_subs3q(Lisp_Object env,
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
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0;
/* end of prologue */
    v44 = qvalue(elt(env, 1)); /* mchfg!* */
    stack[-2] = v44;
    v44 = nil;
    qvalue(elt(env, 1)) = v44; /* mchfg!* */
    v44 = stack[-1];
    v44 = qcar(v44);
    fn = elt(env, 2); /* subs3f */
    stack[0] = (*qfn1(fn))(qenv(fn), v44);
    nil = C_nil;
    if (exception_pending()) goto v29;
    env = stack[-3];
    v44 = stack[-1];
    v44 = qcdr(v44);
    fn = elt(env, 2); /* subs3f */
    v44 = (*qfn1(fn))(qenv(fn), v44);
    nil = C_nil;
    if (exception_pending()) goto v29;
    env = stack[-3];
    fn = elt(env, 3); /* quotsq */
    v44 = (*qfn2(fn))(qenv(fn), stack[0], v44);
    nil = C_nil;
    if (exception_pending()) goto v29;
    env = stack[-3];
    stack[-1] = v44;
    v44 = stack[-2];
    qvalue(elt(env, 1)) = v44; /* mchfg!* */
    { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
/* error exit handlers */
v29:
    popv(4);
    return nil;
}



/* Code for memlis */

static Lisp_Object CC_memlis(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v20, v21, v22, v23;
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v21 = v16;
    v22 = v0;
/* end of prologue */

v4:
    v20 = v21;
    if (v20 == nil) goto v5;
    v23 = v22;
    v20 = v21;
    v20 = qcar(v20);
    v20 = Lmember(nil, v23, v20);
    if (v20 == nil) goto v29;
    v20 = v21;
    v20 = qcar(v20);
    return onevalue(v20);

v29:
    v20 = v21;
    v20 = qcdr(v20);
    v21 = v20;
    goto v4;

v5:
    v20 = nil;
    return onevalue(v20);
}



setup_type const u04_setup[] =
{
    {"gcdf1",                   too_few_2,      CC_gcdf1,      wrong_no_2},
    {"read-comment1",           CC_readKcomment1,too_many_1,   wrong_no_1},
    {"revlis",                  CC_revlis,      too_many_1,    wrong_no_1},
    {"adddm",                   too_few_2,      CC_adddm,      wrong_no_2},
    {"opmtch",                  CC_opmtch,      too_many_1,    wrong_no_1},
    {"mvar_member",             too_few_2,      CC_mvar_member,wrong_no_2},
    {"comb",                    too_few_2,      CC_comb,       wrong_no_2},
    {"gcddd",                   too_few_2,      CC_gcddd,      wrong_no_2},
    {"token1",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_token1},
    {"prinfit",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_prinfit},
    {"opmtchrevop",             CC_opmtchrevop, too_many_1,    wrong_no_1},
    {"updtemplate",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_updtemplate},
    {"reordsq",                 CC_reordsq,     too_many_1,    wrong_no_1},
    {"invsq",                   CC_invsq,       too_many_1,    wrong_no_1},
    {"scan",                    wrong_no_na,    wrong_no_nb,   (n_args *)CC_scan},
    {"kernlp",                  CC_kernlp,      too_many_1,    wrong_no_1},
    {"multfnc",                 too_few_2,      CC_multfnc,    wrong_no_2},
    {"remove-free-vars-l",      CC_removeKfreeKvarsKl,too_many_1,wrong_no_1},
    {"simpexpon",               CC_simpexpon,   too_many_1,    wrong_no_1},
    {"subs3f1",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_subs3f1},
    {"rmultpf",                 too_few_2,      CC_rmultpf,    wrong_no_2},
    {"mkg1",                    too_few_2,      CC_mkg1,       wrong_no_2},
    {"intexprlisp",             too_few_2,      CC_intexprlisp,wrong_no_2},
    {"sort",                    too_few_2,      CC_sort,       wrong_no_2},
    {"mchsarg",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_mchsarg},
    {"gcdf*",                   too_few_2,      CC_gcdfH,      wrong_no_2},
    {"rmplus",                  CC_rmplus,      too_many_1,    wrong_no_1},
    {"rnzerop:",                CC_rnzeropT,    too_many_1,    wrong_no_1},
    {"unplus",                  CC_unplus,      too_many_1,    wrong_no_1},
    {"prepsq*2",                CC_prepsqH2,    too_many_1,    wrong_no_1},
    {"sprgen1",                 too_few_2,      CC_sprgen1,    wrong_no_2},
    {"frvarsof",                too_few_2,      CC_frvarsof,   wrong_no_2},
    {"simpdot",                 CC_simpdot,     too_many_1,    wrong_no_1},
    {"gck2",                    too_few_2,      CC_gck2,       wrong_no_2},
    {"terpri*",                 CC_terpriH,     too_many_1,    wrong_no_1},
    {"canonsq",                 CC_canonsq,     too_many_1,    wrong_no_1},
    {"formop",                  CC_formop,      too_many_1,    wrong_no_1},
    {"multop",                  too_few_2,      CC_multop,     wrong_no_2},
    {"simpexpon1",              too_few_2,      CC_simpexpon1, wrong_no_2},
    {"subs3q",                  CC_subs3q,      too_many_1,    wrong_no_1},
    {"memlis",                  too_few_2,      CC_memlis,     wrong_no_2},
    {NULL, (one_args *)"u04", (two_args *)"7194 1236146 2932805", 0}
};

/* end of generated code */
