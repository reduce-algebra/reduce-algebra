
/* $srcdir/../csl-c\u08.c Machine generated C code */

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


/* Code for token!-number */

static Lisp_Object CC_tokenKnumber(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v341, v304, v472;
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
    stack[-5] = nil;
    stack[-2] = nil;
    stack[-1] = nil;
    stack[0] = nil;
    v341 = (Lisp_Object)1; /* 0 */
    stack[-3] = v341;
    v341 = (Lisp_Object)33; /* 2 */
    qvalue(elt(env, 1)) = v341; /* ttype!* */
    goto v6;

v6:
    v341 = stack[-1];
    if (!(v341 == nil)) goto v99;
    v304 = stack[-4];
    v341 = elt(env, 2); /* !) */
    if (!(v304 == v341)) goto v99;

v38:
    v341 = stack[-5];
    if (v341 == nil) goto v34;
    v341 = stack[-3];
    v341 = sub1(v341);
    nil = C_nil;
    if (exception_pending()) goto v164;
    env = stack[-6];
    stack[-3] = v341;
    goto v34;

v34:
    fn = elt(env, 20); /* readch1 */
    v304 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v164;
    env = stack[-6];
    stack[-4] = v304;
    v341 = elt(env, 3); /* !. */
    if (v304 == v341) goto v193;
    v341 = stack[-4];
    v341 = Ldigitp(nil, v341);
    env = stack[-6];
    if (!(v341 == nil)) goto v6;
    v304 = stack[-1];
    v341 = elt(env, 6); /* (!0) */
    if (!(equal(v304, v341))) goto v82;
    v304 = stack[-4];
    v341 = elt(env, 7); /* x */
    if (v304 == v341) goto v1;
    v304 = stack[-4];
    v341 = elt(env, 8); /* !X */
    if (!(v304 == v341)) goto v82;

v1:
    v341 = (Lisp_Object)1; /* 0 */
    stack[-1] = v341;
    goto v131;

v131:
    fn = elt(env, 20); /* readch1 */
    v304 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v164;
    env = stack[-6];
    stack[-4] = v304;
    v341 = elt(env, 14); /* hexdigit */
    v341 = get(v304, v341);
    env = stack[-6];
    stack[0] = v341;
    if (v341 == nil) goto v24;
    v304 = (Lisp_Object)257; /* 16 */
    v341 = stack[-1];
    v304 = times2(v304, v341);
    nil = C_nil;
    if (exception_pending()) goto v164;
    env = stack[-6];
    v341 = stack[0];
    v341 = plus2(v304, v341);
    nil = C_nil;
    if (exception_pending()) goto v164;
    env = stack[-6];
    stack[-1] = v341;
    goto v131;

v24:
    v341 = stack[-5];
    if (v341 == nil) goto v455;
    v472 = elt(env, 15); /* !:dn!: */
    v304 = stack[-1];
    v341 = stack[-3];
    v341 = list2star(v472, v304, v341);
    nil = C_nil;
    if (exception_pending()) goto v164;
    env = stack[-6];
    goto v250;

v250:
    qvalue(elt(env, 18)) = v341; /* nxtsym!* */
    v341 = stack[-4];
    qvalue(elt(env, 19)) = v341; /* crchar!* */
    v341 = qvalue(elt(env, 18)); /* nxtsym!* */
    { popv(7); return onevalue(v341); }

v455:
    v341 = qvalue(elt(env, 16)); /* !*adjprec */
    if (v341 == nil) goto v524;
    v472 = elt(env, 17); /* !:int!: */
    v304 = stack[-1];
    v341 = nil;
    v341 = list2star(v472, v304, v341);
    nil = C_nil;
    if (exception_pending()) goto v164;
    env = stack[-6];
    goto v250;

v524:
    v341 = stack[-1];
    goto v250;

v82:
    v304 = stack[-4];
    v341 = elt(env, 9); /* !\ */
    if (v304 == v341) goto v191;
    v304 = stack[-4];
    v341 = elt(env, 10); /* e */
    if (v304 == v341) goto v52;
    v304 = stack[-4];
    v341 = elt(env, 11); /* !E */
    if (!(v304 == v341)) goto v13;

v52:
    v341 = lisp_true;
    stack[-5] = v341;
    fn = elt(env, 20); /* readch1 */
    v304 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v164;
    env = stack[-6];
    stack[-4] = v304;
    v341 = elt(env, 12); /* !- */
    if (v304 == v341) goto v132;
    v304 = stack[-4];
    v341 = elt(env, 13); /* !+ */
    if (v304 == v341) goto v8;
    v341 = stack[-4];
    v341 = Ldigitp(nil, v341);
    env = stack[-6];
    if (v341 == nil) goto v13;
    v341 = stack[-4];
    v341 = ncons(v341);
    nil = C_nil;
    if (exception_pending()) goto v164;
    env = stack[-6];
    stack[0] = v341;
    goto v8;

v8:
    fn = elt(env, 20); /* readch1 */
    v341 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v164;
    env = stack[-6];
    stack[-4] = v341;
    v341 = Ldigitp(nil, v341);
    env = stack[-6];
    if (v341 == nil) goto v25;
    v304 = stack[-4];
    v341 = stack[0];
    v341 = cons(v304, v341);
    nil = C_nil;
    if (exception_pending()) goto v164;
    env = stack[-6];
    stack[0] = v341;
    goto v8;

v25:
    v341 = stack[0];
    if (!(v341 == nil)) goto v210;
    v472 = elt(env, 4); /* rlisp */
    v304 = (Lisp_Object)65; /* 4 */
    v341 = elt(env, 5); /* "Syntax error: improper number" */
    fn = elt(env, 21); /* rerror */
    v341 = (*qfnn(fn))(qenv(fn), 3, v472, v304, v341);
    nil = C_nil;
    if (exception_pending()) goto v164;
    env = stack[-6];
    goto v210;

v210:
    v341 = stack[0];
    fn = elt(env, 22); /* reversip!* */
    v341 = (*qfn1(fn))(qenv(fn), v341);
    nil = C_nil;
    if (exception_pending()) goto v164;
    env = stack[-6];
    v341 = Lcompress(nil, v341);
    nil = C_nil;
    if (exception_pending()) goto v164;
    env = stack[-6];
    stack[0] = v341;
    v341 = stack[-2];
    if (v341 == nil) goto v204;
    v304 = stack[-3];
    v341 = stack[0];
    v341 = difference2(v304, v341);
    nil = C_nil;
    if (exception_pending()) goto v164;
    env = stack[-6];
    stack[-3] = v341;
    goto v13;

v13:
    v341 = stack[-1];
    fn = elt(env, 22); /* reversip!* */
    v341 = (*qfn1(fn))(qenv(fn), v341);
    nil = C_nil;
    if (exception_pending()) goto v164;
    env = stack[-6];
    v341 = Lcompress(nil, v341);
    nil = C_nil;
    if (exception_pending()) goto v164;
    env = stack[-6];
    stack[-1] = v341;
    goto v24;

v204:
    v304 = stack[-3];
    v341 = stack[0];
    v341 = plus2(v304, v341);
    nil = C_nil;
    if (exception_pending()) goto v164;
    env = stack[-6];
    stack[-3] = v341;
    goto v13;

v132:
    v341 = lisp_true;
    stack[-2] = v341;
    goto v8;

v191:
    v341 = Lreadch(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v164;
    env = stack[-6];
    goto v34;

v193:
    v341 = stack[-5];
    if (v341 == nil) goto v58;
    v472 = elt(env, 4); /* rlisp */
    v304 = (Lisp_Object)49; /* 3 */
    v341 = elt(env, 5); /* "Syntax error: improper number" */
    fn = elt(env, 21); /* rerror */
    v341 = (*qfnn(fn))(qenv(fn), 3, v472, v304, v341);
    nil = C_nil;
    if (exception_pending()) goto v164;
    env = stack[-6];
    goto v52;

v58:
    v341 = lisp_true;
    stack[-5] = v341;
    goto v34;

v99:
    v304 = stack[-4];
    v341 = stack[-1];
    v341 = cons(v304, v341);
    nil = C_nil;
    if (exception_pending()) goto v164;
    env = stack[-6];
    stack[-1] = v341;
    goto v38;
/* error exit handlers */
v164:
    popv(7);
    return nil;
}



/* Code for assgnpri */

static Lisp_Object MS_CDECL CC_assgnpri(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v16,
                         Lisp_Object v63, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v309, v351, v182;
    Lisp_Object fn;
    argcheck(nargs, 3, "assgnpri");
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
    v309 = nil;
    qvalue(elt(env, 1)) = v309; /* overflowed!* */
    qvalue(elt(env, 2)) = v309; /* testing!-width!* */
    v309 = stack[-2];
    if (!(v309 == nil)) goto v6;
    v309 = (Lisp_Object)1; /* 0 */
    stack[-2] = v309;
    goto v6;

v6:
    v309 = qvalue(elt(env, 3)); /* !*nero */
    if (v309 == nil) goto v13;
    v351 = stack[-2];
    v309 = (Lisp_Object)1; /* 0 */
    if (!(v351 == v309)) goto v13;
    v309 = nil;
    { popv(5); return onevalue(v309); }

v13:
    v309 = qvalue(elt(env, 4)); /* !*tex */
    if (v309 == nil) goto v23;
    v182 = stack[-2];
    v351 = stack[-1];
    v309 = stack[0];
    {
        popv(5);
        fn = elt(env, 17); /* texpri */
        return (*qfnn(fn))(qenv(fn), 3, v182, v351, v309);
    }

v23:
    v309 = elt(env, 5); /* vecp */
    fn = elt(env, 18); /* getd */
    v309 = (*qfn1(fn))(qenv(fn), v309);
    nil = C_nil;
    if (exception_pending()) goto v256;
    env = stack[-4];
    if (v309 == nil) goto v21;
    v309 = stack[-2];
    fn = elt(env, 5); /* vecp */
    v309 = (*qfn1(fn))(qenv(fn), v309);
    nil = C_nil;
    if (exception_pending()) goto v256;
    env = stack[-4];
    if (v309 == nil) goto v21;
    v351 = stack[-2];
    v309 = elt(env, 6); /* mat */
    {
        popv(5);
        fn = elt(env, 19); /* vecpri */
        return (*qfn2(fn))(qenv(fn), v351, v309);
    }

v21:
    v309 = stack[-2];
    fn = elt(env, 20); /* getrtype */
    v309 = (*qfn1(fn))(qenv(fn), v309);
    nil = C_nil;
    if (exception_pending()) goto v256;
    env = stack[-4];
    v182 = v309;
    if (v309 == nil) goto v231;
    v351 = v182;
    v309 = elt(env, 7); /* sprifn */
    v309 = Lflagp(nil, v351, v309);
    env = stack[-4];
    if (v309 == nil) goto v231;
    v309 = qvalue(elt(env, 8)); /* outputhandler!* */
    if (!(v309 == nil)) goto v231;
    v309 = stack[-1];
    if (v309 == nil) goto v96;
    v182 = elt(env, 11); /* setq */
    v309 = stack[-1];
    v351 = qcar(v309);
    v309 = stack[-2];
    v309 = list3(v182, v351, v309);
    nil = C_nil;
    if (exception_pending()) goto v256;
    env = stack[-4];
    fn = elt(env, 21); /* maprin */
    v309 = (*qfn1(fn))(qenv(fn), v309);
    nil = C_nil;
    if (exception_pending()) goto v256;
    goto v60;

v60:
    v309 = nil;
    { popv(5); return onevalue(v309); }

v96:
    v351 = v182;
    v309 = elt(env, 9); /* tag */
    v351 = get(v351, v309);
    env = stack[-4];
    v309 = elt(env, 10); /* prifn */
    v351 = get(v351, v309);
    env = stack[-4];
    v309 = stack[-2];
    v309 = Lapply1(nil, v351, v309);
    nil = C_nil;
    if (exception_pending()) goto v256;
    goto v60;

v231:
    v351 = stack[0];
    v309 = elt(env, 12); /* (first only) */
    v309 = Lmemq(nil, v351, v309);
    if (v309 == nil) goto v140;
    v309 = lisp_true;
    fn = elt(env, 22); /* terpri!* */
    v309 = (*qfn1(fn))(qenv(fn), v309);
    nil = C_nil;
    if (exception_pending()) goto v256;
    env = stack[-4];
    goto v140;

v140:
    v309 = stack[-1];
    fn = elt(env, 23); /* evalvars */
    v309 = (*qfn1(fn))(qenv(fn), v309);
    nil = C_nil;
    if (exception_pending()) goto v256;
    env = stack[-4];
    stack[-1] = v309;
    v309 = qvalue(elt(env, 13)); /* !*fort */
    if (v309 == nil) goto v115;
    v182 = stack[-2];
    v351 = stack[-1];
    v309 = stack[0];
    fn = elt(env, 24); /* fvarpri */
    v309 = (*qfnn(fn))(qenv(fn), 3, v182, v351, v309);
    nil = C_nil;
    if (exception_pending()) goto v256;
    v309 = nil;
    { popv(5); return onevalue(v309); }

v115:
    v309 = stack[-1];
    if (v309 == nil) goto v212;
    stack[-3] = elt(env, 11); /* setq */
    v351 = stack[-1];
    v309 = stack[-2];
    fn = elt(env, 25); /* aconc */
    v309 = (*qfn2(fn))(qenv(fn), v351, v309);
    nil = C_nil;
    if (exception_pending()) goto v256;
    env = stack[-4];
    v309 = cons(stack[-3], v309);
    nil = C_nil;
    if (exception_pending()) goto v256;
    env = stack[-4];
    goto v229;

v229:
    fn = elt(env, 21); /* maprin */
    v309 = (*qfn1(fn))(qenv(fn), v309);
    nil = C_nil;
    if (exception_pending()) goto v256;
    env = stack[-4];
    v309 = stack[0];
    if (v309 == nil) goto v473;
    v351 = stack[0];
    v309 = elt(env, 14); /* first */
    if (v351 == v309) goto v473;
    v309 = qvalue(elt(env, 15)); /* !*nat */
    if (!(v309 == nil)) goto v125;
    v309 = elt(env, 16); /* "$" */
    fn = elt(env, 26); /* prin2!* */
    v309 = (*qfn1(fn))(qenv(fn), v309);
    nil = C_nil;
    if (exception_pending()) goto v256;
    env = stack[-4];
    goto v125;

v125:
    v309 = qvalue(elt(env, 15)); /* !*nat */
    v309 = (v309 == nil ? lisp_true : nil);
    fn = elt(env, 22); /* terpri!* */
    v309 = (*qfn1(fn))(qenv(fn), v309);
    nil = C_nil;
    if (exception_pending()) goto v256;
    v309 = nil;
    { popv(5); return onevalue(v309); }

v473:
    v309 = nil;
    { popv(5); return onevalue(v309); }

v212:
    v309 = stack[-2];
    goto v229;
/* error exit handlers */
v256:
    popv(5);
    return nil;
}



/* Code for getsetvars */

static Lisp_Object CC_getsetvars(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v66, v70;
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
    v66 = stack[0];
    if (!consp(v66)) goto v5;
    v66 = stack[0];
    v70 = qcar(v66);
    v66 = elt(env, 1); /* (setel setk) */
    v66 = Lmemq(nil, v70, v66);
    if (v66 == nil) goto v37;
    v66 = stack[0];
    v66 = qcdr(v66);
    v66 = qcar(v66);
    fn = elt(env, 3); /* getsetvarlis */
    v70 = (*qfn1(fn))(qenv(fn), v66);
    nil = C_nil;
    if (exception_pending()) goto v57;
    env = stack[-2];
    v66 = stack[-1];
    v66 = cons(v70, v66);
    nil = C_nil;
    if (exception_pending()) goto v57;
    env = stack[-2];
    stack[-1] = v66;
    v66 = stack[0];
    v66 = qcdr(v66);
    v66 = qcdr(v66);
    v66 = qcar(v66);
    stack[0] = v66;
    goto v4;

v37:
    v66 = stack[0];
    v70 = qcar(v66);
    v66 = elt(env, 2); /* setq */
    if (v70 == v66) goto v193;
    v66 = stack[-1];
    {
        popv(3);
        fn = elt(env, 4); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v66);
    }

v193:
    v66 = stack[0];
    v66 = qcdr(v66);
    v66 = qcar(v66);
    v70 = Lmkquote(nil, v66);
    nil = C_nil;
    if (exception_pending()) goto v57;
    env = stack[-2];
    v66 = stack[-1];
    v66 = cons(v70, v66);
    nil = C_nil;
    if (exception_pending()) goto v57;
    env = stack[-2];
    stack[-1] = v66;
    v66 = stack[0];
    v66 = qcdr(v66);
    v66 = qcdr(v66);
    v66 = qcar(v66);
    stack[0] = v66;
    goto v4;

v5:
    v66 = stack[-1];
    {
        popv(3);
        fn = elt(env, 4); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v66);
    }
/* error exit handlers */
v57:
    popv(3);
    return nil;
}



/* Code for add2resultbuf */

static Lisp_Object CC_add2resultbuf(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v101, v57, v72;
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
    v101 = v16;
    stack[0] = v0;
/* end of prologue */
    v72 = v101;
    v57 = elt(env, 1); /* symbolic */
    if (v72 == v57) goto v45;
    v57 = stack[0];
    if (!(v57 == nil)) goto v26;
    v57 = qvalue(elt(env, 2)); /* !*reduce4 */
    if (v57 == nil) goto v45;
    v72 = v101;
    v57 = elt(env, 3); /* empty_list */
    if (!(v72 == v57)) goto v45;

v26:
    v57 = qvalue(elt(env, 4)); /* !*nosave!* */
    if (!(v57 == nil)) goto v45;
    v57 = qvalue(elt(env, 2)); /* !*reduce4 */
    if (v57 == nil) goto v193;
    v72 = elt(env, 5); /* ws */
    v57 = stack[0];
    fn = elt(env, 9); /* putobject */
    v101 = (*qfnn(fn))(qenv(fn), 3, v72, v57, v101);
    nil = C_nil;
    if (exception_pending()) goto v58;
    env = stack[-1];
    goto v10;

v10:
    fn = elt(env, 10); /* terminalp */
    v101 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v58;
    env = stack[-1];
    if (v101 == nil) goto v41;
    v72 = qvalue(elt(env, 7)); /* statcounter */
    v57 = stack[0];
    v101 = qvalue(elt(env, 8)); /* resultbuflis!* */
    v101 = acons(v72, v57, v101);
    nil = C_nil;
    if (exception_pending()) goto v58;
    env = stack[-1];
    qvalue(elt(env, 8)) = v101; /* resultbuflis!* */
    goto v41;

v41:
    v101 = nil;
    { popv(2); return onevalue(v101); }

v193:
    v101 = nil;
    v101 = ncons(v101);
    nil = C_nil;
    if (exception_pending()) goto v58;
    env = stack[-1];
    qvalue(elt(env, 6)) = v101; /* alglist!* */
    v101 = stack[0];
    qvalue(elt(env, 5)) = v101; /* ws */
    goto v10;

v45:
    v101 = nil;
    { popv(2); return onevalue(v101); }
/* error exit handlers */
v58:
    popv(2);
    return nil;
}



/* Code for listp */

static Lisp_Object CC_listp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v27, v28;
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v27 = v0;
/* end of prologue */

v11:
    v28 = v27;
    v28 = (v28 == nil ? lisp_true : nil);
    if (!(v28 == nil)) return onevalue(v28);
    v28 = v27;
    if (!consp(v28)) goto v6;
    v27 = qcdr(v27);
    goto v11;

v6:
    v27 = nil;
    return onevalue(v27);
}



/* Code for form */

static Lisp_Object CC_form(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v456, v83, v84;
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
    v83 = v0;
/* end of prologue */
    v456 = v83;
    if (!consp(v456)) goto v4;
    v456 = v83;
    v84 = qcar(v456);
    v456 = elt(env, 1); /* always_nform */
    v456 = Lflagp(nil, v84, v456);
    env = stack[0];
    if (v456 == nil) goto v4;
    v456 = v83;
    {
        popv(1);
        fn = elt(env, 9); /* n_form */
        return (*qfn1(fn))(qenv(fn), v456);
    }

v4:
    v456 = qvalue(elt(env, 2)); /* !*rlisp88 */
    if (v456 == nil) goto v43;
    v84 = qvalue(elt(env, 4)); /* !*mode */
    v456 = elt(env, 5); /* symbolic */
    if (!(v84 == v456)) goto v95;
    v84 = v83;
    v456 = elt(env, 6); /* modefn */
    v456 = Lflagp(nil, v84, v456);
    env = stack[0];
    if (v456 == nil) goto v56;
    v84 = v83;
    v456 = elt(env, 5); /* symbolic */
    if (!(v84 == v456)) goto v95;

v56:
    v84 = v83;
    v456 = elt(env, 6); /* modefn */
    v456 = Lflagpcar(nil, v84, v456);
    env = stack[0];
    if (v456 == nil) goto v128;
    v456 = v83;
    v84 = qcar(v456);
    v456 = elt(env, 5); /* symbolic */
    if (!(v84 == v456)) goto v95;

v128:
    v84 = v83;
    v83 = qvalue(elt(env, 3)); /* !*vars!* */
    v456 = qvalue(elt(env, 4)); /* !*mode */
    {
        popv(1);
        fn = elt(env, 10); /* form1 */
        return (*qfnn(fn))(qenv(fn), 3, v84, v83, v456);
    }

v95:
    v83 = elt(env, 7); /* "algebraic expression" */
    v456 = elt(env, 8); /* "Rlisp88 form" */
    {
        popv(1);
        fn = elt(env, 11); /* typerr */
        return (*qfn2(fn))(qenv(fn), v83, v456);
    }

v43:
    v84 = v83;
    v83 = qvalue(elt(env, 3)); /* !*vars!* */
    v456 = qvalue(elt(env, 4)); /* !*mode */
    {
        popv(1);
        fn = elt(env, 10); /* form1 */
        return (*qfnn(fn))(qenv(fn), 3, v84, v83, v456);
    }
}



/* Code for mchkminus */

static Lisp_Object CC_mchkminus(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v229, v92, v225;
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
    v229 = stack[0];
    v92 = qcar(v229);
    v229 = elt(env, 1); /* (times quotient) */
    v229 = Lmemq(nil, v92, v229);
    if (v229 == nil) goto v4;
    v229 = stack[-1];
    if (!consp(v229)) goto v10;
    v229 = stack[-1];
    v92 = qcar(v229);
    v229 = stack[0];
    v229 = qcar(v229);
    if (!(v92 == v229)) goto v10;
    v229 = stack[-1];
    v229 = qcdr(v229);
    v229 = qcar(v229);
    if (is_number(v229)) goto v113;
    v229 = stack[-1];
    v229 = qcdr(v229);
    v229 = qcar(v229);
    v229 = Lconsp(nil, v229);
    env = stack[-2];
    if (v229 == nil) goto v226;
    v229 = stack[-1];
    v229 = qcdr(v229);
    v229 = qcar(v229);
    v92 = qcar(v229);
    v229 = elt(env, 5); /* dname */
    v229 = get(v92, v229);
    env = stack[-2];
    if (!(v229 == nil)) goto v113;

v226:
    v229 = stack[0];
    v92 = qcar(v229);
    v229 = elt(env, 6); /* quotient */
    if (v92 == v229) goto v113;
    v92 = elt(env, 7); /* (minus 1) */
    v229 = stack[-1];
    v229 = qcdr(v229);
    v225 = cons(v92, v229);
    nil = C_nil;
    if (exception_pending()) goto v110;
    env = stack[-2];
    v229 = stack[0];
    v92 = qcdr(v229);
    v229 = elt(env, 2); /* times */
    {
        popv(3);
        fn = elt(env, 8); /* mcharg */
        return (*qfnn(fn))(qenv(fn), 3, v225, v92, v229);
    }

v113:
    v92 = elt(env, 4); /* minus */
    v229 = stack[-1];
    v229 = qcdr(v229);
    v229 = qcar(v229);
    v92 = list2(v92, v229);
    nil = C_nil;
    if (exception_pending()) goto v110;
    env = stack[-2];
    v229 = stack[-1];
    v229 = qcdr(v229);
    v229 = qcdr(v229);
    v225 = cons(v92, v229);
    nil = C_nil;
    if (exception_pending()) goto v110;
    env = stack[-2];
    v229 = stack[0];
    v92 = qcdr(v229);
    v229 = stack[0];
    v229 = qcar(v229);
    {
        popv(3);
        fn = elt(env, 8); /* mcharg */
        return (*qfnn(fn))(qenv(fn), 3, v225, v92, v229);
    }

v10:
    v229 = stack[0];
    v92 = qcar(v229);
    v229 = elt(env, 2); /* times */
    if (v92 == v229) goto v33;
    v92 = elt(env, 4); /* minus */
    v229 = stack[-1];
    v92 = list2(v92, v229);
    nil = C_nil;
    if (exception_pending()) goto v110;
    env = stack[-2];
    v229 = stack[0];
    {
        popv(3);
        fn = elt(env, 9); /* mchkopt */
        return (*qfn2(fn))(qenv(fn), v92, v229);
    }

v33:
    v225 = stack[-1];
    v92 = stack[0];
    v229 = elt(env, 3); /* ((minus 1) (minus 1)) */
    {
        popv(3);
        fn = elt(env, 10); /* mchkopt1 */
        return (*qfnn(fn))(qenv(fn), 3, v225, v92, v229);
    }

v4:
    v229 = nil;
    { popv(3); return onevalue(v229); }
/* error exit handlers */
v110:
    popv(3);
    return nil;
}



/* Code for let3 */

static Lisp_Object MS_CDECL CC_let3(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v16,
                         Lisp_Object v63, Lisp_Object v9,
                         Lisp_Object v3, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v200, v209, v248, v224, v350, v478;
    Lisp_Object fn;
    argcheck(nargs, 5, "let3");
    if (stack >= stacklimit)
    {
        push5(v3,v9,v63,v16,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v0,v16,v63,v9,v3);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v3;
    stack[-2] = v9;
    stack[-3] = v63;
    stack[-4] = v16;
    stack[-5] = v0;
/* end of prologue */
    v200 = stack[-5];
    stack[-6] = v200;
    v200 = stack[-6];
    if (v200 == nil) goto v13;
    v200 = stack[-6];
    if (is_number(v200)) goto v44;
    v200 = stack[-4];
    fn = elt(env, 5); /* getrtype */
    v200 = (*qfn1(fn))(qenv(fn), v200);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-7];
    stack[0] = v200;
    v200 = stack[-2];
    if (v200 == nil) goto v20;
    v200 = stack[-6];
    if (!(symbolp(v200))) goto v20;
    v209 = stack[-6];
    v200 = elt(env, 1); /* rtype */
    v200 = Lremprop(nil, v209, v200);
    env = stack[-7];
    v209 = stack[-6];
    v200 = elt(env, 2); /* avalue */
    v200 = Lremprop(nil, v209, v200);
    env = stack[-7];
    goto v20;

v20:
    v200 = stack[-6];
    fn = elt(env, 5); /* getrtype */
    v200 = (*qfn1(fn))(qenv(fn), v200);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-7];
    v248 = v200;
    if (v200 == nil) goto v206;
    v209 = v248;
    v200 = elt(env, 3); /* typeletfn */
    v200 = get(v209, v200);
    env = stack[-7];
    v209 = v200;
    if (v200 == nil) goto v456;
    stack[-3] = v209;
    stack[-5] = stack[-6];
    stack[-1] = stack[-4];
    stack[0] = v248;
    v200 = stack[-4];
    fn = elt(env, 5); /* getrtype */
    v200 = (*qfn1(fn))(qenv(fn), v200);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-7];
    v200 = list2(stack[-2], v200);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-7];
    v200 = list3star(stack[-5], stack[-1], stack[0], v200);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-7];
    {
        Lisp_Object v433 = stack[-3];
        popv(8);
        fn = elt(env, 6); /* lispapply */
        return (*qfn2(fn))(qenv(fn), v433, v200);
    }

v456:
    stack[-3] = stack[-6];
    stack[-1] = stack[-4];
    stack[0] = v248;
    v200 = stack[-4];
    fn = elt(env, 5); /* getrtype */
    v200 = (*qfn1(fn))(qenv(fn), v200);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-7];
    {
        Lisp_Object v251 = stack[-3];
        Lisp_Object v179 = stack[-1];
        Lisp_Object v361 = stack[0];
        Lisp_Object v458 = stack[-2];
        popv(8);
        fn = elt(env, 7); /* typelet */
        return (*qfnn(fn))(qenv(fn), 5, v251, v179, v361, v458, v200);
    }

v206:
    v200 = stack[0];
    if (v200 == nil) goto v228;
    v209 = stack[0];
    v200 = elt(env, 4); /* yetunknowntype */
    if (v209 == v200) goto v228;
    v209 = stack[0];
    v200 = elt(env, 3); /* typeletfn */
    v200 = get(v209, v200);
    env = stack[-7];
    v209 = v200;
    if (v200 == nil) goto v108;
    stack[-3] = v209;
    stack[-5] = stack[-6];
    stack[-1] = nil;
    v209 = stack[-2];
    v200 = stack[0];
    v200 = list2(v209, v200);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-7];
    v200 = list3star(stack[-5], stack[-4], stack[-1], v200);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-7];
    {
        Lisp_Object v203 = stack[-3];
        popv(8);
        fn = elt(env, 6); /* lispapply */
        return (*qfn2(fn))(qenv(fn), v203, v200);
    }

v108:
    v350 = stack[-6];
    v224 = stack[-4];
    v248 = nil;
    v209 = stack[-2];
    v200 = stack[0];
    {
        popv(8);
        fn = elt(env, 7); /* typelet */
        return (*qfnn(fn))(qenv(fn), 5, v350, v224, v248, v209, v200);
    }

v228:
    v478 = stack[-5];
    v350 = stack[-4];
    v224 = stack[-3];
    v248 = stack[-6];
    v209 = stack[-2];
    v200 = stack[-1];
    fn = elt(env, 8); /* letscalar */
    v200 = (*qfnn(fn))(qenv(fn), 6, v478, v350, v224, v248, v209, v200);
    nil = C_nil;
    if (exception_pending()) goto v178;
    v200 = nil;
    { popv(8); return onevalue(v200); }

v44:
    v200 = stack[-5];
    {
        popv(8);
        fn = elt(env, 9); /* errpri1 */
        return (*qfn1(fn))(qenv(fn), v200);
    }

v13:
    v200 = (Lisp_Object)1; /* 0 */
    stack[-5] = v200;
    v200 = stack[-5];
    {
        popv(8);
        fn = elt(env, 9); /* errpri1 */
        return (*qfn1(fn))(qenv(fn), v200);
    }
/* error exit handlers */
v178:
    popv(8);
    return nil;
}



/* Code for rlis */

static Lisp_Object MS_CDECL CC_rlis(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v64, v100;
    Lisp_Object fn;
    argcheck(nargs, 0, "rlis");
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* end of prologue */
    v64 = qvalue(elt(env, 1)); /* cursym!* */
    stack[0] = v64;
    fn = elt(env, 6); /* scan */
    v100 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-2];
    v64 = elt(env, 2); /* delim */
    v64 = Lflagp(nil, v100, v64);
    env = stack[-2];
    if (v64 == nil) goto v5;
    v100 = stack[0];
    v64 = nil;
    popv(3);
    return list2(v100, v64);

v5:
    v64 = qvalue(elt(env, 3)); /* !*reduce4 */
    if (v64 == nil) goto v193;
    stack[-1] = stack[0];
    stack[0] = elt(env, 4); /* list */
    v64 = elt(env, 5); /* lambda */
    fn = elt(env, 7); /* xread1 */
    v64 = (*qfn1(fn))(qenv(fn), v64);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-2];
    fn = elt(env, 8); /* remcomma */
    v64 = (*qfn1(fn))(qenv(fn), v64);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-2];
    v64 = cons(stack[0], v64);
    nil = C_nil;
    if (exception_pending()) goto v105;
    {
        Lisp_Object v69 = stack[-1];
        popv(3);
        return list2(v69, v64);
    }

v193:
    v64 = elt(env, 5); /* lambda */
    fn = elt(env, 7); /* xread1 */
    v64 = (*qfn1(fn))(qenv(fn), v64);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-2];
    fn = elt(env, 8); /* remcomma */
    v64 = (*qfn1(fn))(qenv(fn), v64);
    nil = C_nil;
    if (exception_pending()) goto v105;
    {
        Lisp_Object v67 = stack[0];
        popv(3);
        return cons(v67, v64);
    }
/* error exit handlers */
v105:
    popv(3);
    return nil;
}



/* Code for sprgen */

static Lisp_Object CC_sprgen(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v80, v116, v114;
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
    stack[-1] = nil;
    v80 = stack[-2];
    v116 = qcar(v80);
    v80 = elt(env, 1); /* a */
    if (v116 == v80) goto v30;
    v116 = stack[-2];
    v80 = lisp_true;
    {
        popv(5);
        fn = elt(env, 3); /* sprgen1 */
        return (*qfn2(fn))(qenv(fn), v116, v80);
    }

v30:
    v80 = stack[-2];
    v116 = qcdr(v80);
    stack[-2] = v116;
    v80 = (Lisp_Object)65; /* 4 */
    fn = elt(env, 4); /* comb */
    v80 = (*qfn2(fn))(qenv(fn), v116, v80);
    nil = C_nil;
    if (exception_pending()) goto v148;
    env = stack[-4];
    stack[-3] = v80;
    if (v80 == nil) goto v21;
    v80 = stack[-3];
    v80 = qcdr(v80);
    if (!(v80 == nil)) goto v45;
    v80 = stack[-3];
    v80 = qcar(v80);
    fn = elt(env, 5); /* mkepsf */
    v80 = (*qfn1(fn))(qenv(fn), v80);
    nil = C_nil;
    if (exception_pending()) goto v148;
    env = stack[-4];
    stack[-1] = v80;
    goto v5;

v5:
    v80 = stack[-3];
    v80 = qcdr(v80);
    stack[-3] = v80;
    goto v45;

v45:
    v80 = stack[-3];
    if (v80 == nil) goto v56;
    v80 = stack[-3];
    v80 = qcar(v80);
    fn = elt(env, 5); /* mkepsf */
    v80 = (*qfn1(fn))(qenv(fn), v80);
    nil = C_nil;
    if (exception_pending()) goto v148;
    env = stack[-4];
    stack[0] = v80;
    v80 = stack[-3];
    v114 = qcar(v80);
    v116 = stack[-2];
    v80 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 6); /* asign */
    v116 = (*qfnn(fn))(qenv(fn), 3, v114, v116, v80);
    nil = C_nil;
    if (exception_pending()) goto v148;
    env = stack[-4];
    v80 = (Lisp_Object)-15; /* -1 */
    if (!(v116 == v80)) goto v223;
    v80 = stack[0];
    fn = elt(env, 7); /* negf */
    v80 = (*qfn1(fn))(qenv(fn), v80);
    nil = C_nil;
    if (exception_pending()) goto v148;
    env = stack[-4];
    stack[0] = v80;
    goto v223;

v223:
    v116 = stack[-2];
    v80 = stack[-3];
    v80 = qcar(v80);
    fn = elt(env, 8); /* setdiff */
    v116 = (*qfn2(fn))(qenv(fn), v116, v80);
    nil = C_nil;
    if (exception_pending()) goto v148;
    env = stack[-4];
    v80 = lisp_true;
    fn = elt(env, 3); /* sprgen1 */
    v80 = (*qfn2(fn))(qenv(fn), v116, v80);
    nil = C_nil;
    if (exception_pending()) goto v148;
    env = stack[-4];
    fn = elt(env, 9); /* multf */
    v116 = (*qfn2(fn))(qenv(fn), stack[0], v80);
    nil = C_nil;
    if (exception_pending()) goto v148;
    env = stack[-4];
    v80 = stack[-1];
    fn = elt(env, 10); /* addf */
    v80 = (*qfn2(fn))(qenv(fn), v116, v80);
    nil = C_nil;
    if (exception_pending()) goto v148;
    env = stack[-4];
    stack[-1] = v80;
    goto v5;

v56:
    v116 = elt(env, 2); /* i */
    v80 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 11); /* to */
    v116 = (*qfn2(fn))(qenv(fn), v116, v80);
    nil = C_nil;
    if (exception_pending()) goto v148;
    env = stack[-4];
    v80 = (Lisp_Object)17; /* 1 */
    v80 = cons(v116, v80);
    nil = C_nil;
    if (exception_pending()) goto v148;
    env = stack[-4];
    v116 = ncons(v80);
    nil = C_nil;
    if (exception_pending()) goto v148;
    env = stack[-4];
    v80 = stack[-1];
    {
        popv(5);
        fn = elt(env, 9); /* multf */
        return (*qfn2(fn))(qenv(fn), v116, v80);
    }

v21:
    v80 = nil;
    { popv(5); return onevalue(v80); }
/* error exit handlers */
v148:
    popv(5);
    return nil;
}



/* Code for forstat */

static Lisp_Object MS_CDECL CC_forstat(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v20, v21;
    Lisp_Object fn;
    argcheck(nargs, 0, "forstat");
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
    stack[0] = qvalue(elt(env, 1)); /* !*blockp */
    qvalue(elt(env, 1)) = nil; /* !*blockp */
    fn = elt(env, 5); /* scan */
    v21 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v23;
    env = stack[-1];
    v20 = elt(env, 2); /* all */
    if (v21 == v20) goto v12;
    v21 = qvalue(elt(env, 3)); /* cursym!* */
    v20 = elt(env, 4); /* each */
    if (v21 == v20) goto v24;
    fn = elt(env, 6); /* forloop */
    v20 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v23;
    env = stack[-1];
    goto v9;

v9:
    qvalue(elt(env, 1)) = stack[0]; /* !*blockp */
    { popv(2); return onevalue(v20); }

v24:
    fn = elt(env, 7); /* foreachstat */
    v20 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v23;
    env = stack[-1];
    goto v9;

v12:
    fn = elt(env, 8); /* forallstat */
    v20 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v23;
    env = stack[-1];
    goto v9;
/* error exit handlers */
v23:
    env = stack[-1];
    qvalue(elt(env, 1)) = stack[0]; /* !*blockp */
    popv(2);
    return nil;
}



/* Code for sfp */

static Lisp_Object CC_sfp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v25, v13;
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v25 = v0;
/* end of prologue */
    v13 = v25;
    if (!consp(v13)) goto v3;
    v25 = qcar(v25);
    v25 = (consp(v25) ? nil : lisp_true);
    v25 = (v25 == nil ? lisp_true : nil);
    return onevalue(v25);

v3:
    v25 = nil;
    return onevalue(v25);
}



/* Code for powers0 */

static Lisp_Object CC_powers0(Lisp_Object env,
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

v11:
    v121 = stack[-1];
    if (v121 == nil) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v121 = stack[-1];
    if (!consp(v121)) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v121 = stack[-1];
    v121 = qcar(v121);
    if (!consp(v121)) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v121 = stack[-1];
    v121 = qcar(v121);
    v121 = qcar(v121);
    v143 = qcar(v121);
    v121 = stack[0];
    v143 = Latsoc(nil, v143, v121);
    v121 = v143;
    if (v143 == nil) goto v57;
    v143 = stack[-1];
    v143 = qcar(v143);
    v143 = qcar(v143);
    v143 = qcdr(v143);
    v121 = qcdr(v121);
    v121 = (Lisp_Object)greaterp2(v143, v121);
    nil = C_nil;
    if (exception_pending()) goto v81;
    v121 = v121 ? lisp_true : nil;
    env = stack[-3];
    if (v121 == nil) goto v104;
    v121 = stack[-1];
    v121 = qcar(v121);
    v121 = qcar(v121);
    v144 = qcar(v121);
    v121 = stack[-1];
    v121 = qcar(v121);
    v121 = qcar(v121);
    v143 = qcdr(v121);
    v121 = stack[0];
    fn = elt(env, 1); /* repasc */
    v121 = (*qfnn(fn))(qenv(fn), 3, v144, v143, v121);
    nil = C_nil;
    if (exception_pending()) goto v81;
    env = stack[-3];
    stack[0] = v121;
    goto v104;

v104:
    v121 = stack[-1];
    stack[-2] = qcdr(v121);
    v121 = stack[-1];
    v121 = qcar(v121);
    v143 = qcdr(v121);
    v121 = stack[0];
    v121 = CC_powers0(env, v143, v121);
    nil = C_nil;
    if (exception_pending()) goto v81;
    env = stack[-3];
    stack[-1] = stack[-2];
    stack[0] = v121;
    goto v11;

v57:
    v121 = stack[-1];
    v121 = qcar(v121);
    v121 = qcar(v121);
    v144 = qcar(v121);
    v121 = stack[-1];
    v121 = qcar(v121);
    v121 = qcar(v121);
    v143 = qcdr(v121);
    v121 = stack[0];
    v121 = acons(v144, v143, v121);
    nil = C_nil;
    if (exception_pending()) goto v81;
    env = stack[-3];
    stack[0] = v121;
    goto v104;
/* error exit handlers */
v81:
    popv(4);
    return nil;
}



/* Code for brace */

static Lisp_Object MS_CDECL CC_brace(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v16,
                         Lisp_Object v63, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v123, v124, v125, v473;
    Lisp_Object fn;
    argcheck(nargs, 3, "brace");
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
    v124 = v63;
    stack[0] = v16;
    stack[-3] = v0;
/* end of prologue */
    v123 = stack[-3];
    if (v123 == nil) goto v12;
    v123 = stack[-3];
    fn = elt(env, 4); /* xnp */
    v123 = (*qfn2(fn))(qenv(fn), v124, v123);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-5];
    if (!(v123 == nil)) goto v14;
    v124 = stack[0];
    v123 = elt(env, 1); /* nospur */
    v123 = Lflagp(nil, v124, v123);
    env = stack[-5];
    if (!(v123 == nil)) goto v14;
    v123 = stack[-3];
    v124 = qcar(v123);
    v123 = elt(env, 2); /* a */
    if (v124 == v123) goto v39;
    v123 = stack[-3];
    fn = elt(env, 5); /* hevenp */
    v123 = (*qfn1(fn))(qenv(fn), v123);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-5];
    if (v123 == nil) goto v73;
    v473 = stack[-3];
    v125 = stack[0];
    v124 = (Lisp_Object)33; /* 2 */
    v123 = nil;
    {
        popv(6);
        fn = elt(env, 6); /* spr2 */
        return (*qfnn(fn))(qenv(fn), 4, v473, v125, v124, v123);
    }

v73:
    v473 = stack[-3];
    v125 = stack[0];
    v124 = (Lisp_Object)33; /* 2 */
    v123 = nil;
    {
        popv(6);
        fn = elt(env, 7); /* spr1 */
        return (*qfnn(fn))(qenv(fn), 4, v473, v125, v124, v123);
    }

v39:
    v123 = stack[-3];
    fn = elt(env, 5); /* hevenp */
    v123 = (*qfn1(fn))(qenv(fn), v123);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-5];
    if (v123 == nil) goto v113;
    v125 = elt(env, 3); /* g */
    v124 = stack[0];
    v123 = stack[-3];
    v123 = list2star(v125, v124, v123);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-5];
    fn = elt(env, 8); /* mksf */
    stack[-4] = (*qfn1(fn))(qenv(fn), v123);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-5];
    stack[-2] = elt(env, 3); /* g */
    stack[-1] = stack[0];
    stack[0] = elt(env, 2); /* a */
    v123 = stack[-3];
    v123 = qcdr(v123);
    v123 = Lreverse(nil, v123);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-5];
    v123 = cons(stack[0], v123);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-5];
    v123 = list2star(stack[-2], stack[-1], v123);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-5];
    fn = elt(env, 8); /* mksf */
    v123 = (*qfn1(fn))(qenv(fn), v123);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-5];
    fn = elt(env, 9); /* negf */
    v123 = (*qfn1(fn))(qenv(fn), v123);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-5];
    {
        Lisp_Object v131 = stack[-4];
        popv(6);
        fn = elt(env, 10); /* addf */
        return (*qfn2(fn))(qenv(fn), v131, v123);
    }

v113:
    v125 = elt(env, 3); /* g */
    v124 = stack[0];
    v123 = elt(env, 2); /* a */
    v123 = list3(v125, v124, v123);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-5];
    fn = elt(env, 8); /* mksf */
    stack[-1] = (*qfn1(fn))(qenv(fn), v123);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-5];
    v123 = stack[-3];
    v473 = qcdr(v123);
    v125 = stack[0];
    v124 = (Lisp_Object)33; /* 2 */
    v123 = nil;
    fn = elt(env, 6); /* spr2 */
    v123 = (*qfnn(fn))(qenv(fn), 4, v473, v125, v124, v123);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-5];
    {
        Lisp_Object v261 = stack[-1];
        popv(6);
        fn = elt(env, 11); /* mkf */
        return (*qfn2(fn))(qenv(fn), v261, v123);
    }

v14:
    v124 = stack[-3];
    v123 = stack[0];
    fn = elt(env, 12); /* mkg1 */
    stack[-1] = (*qfn2(fn))(qenv(fn), v124, v123);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-5];
    v123 = stack[-3];
    v124 = Lreverse(nil, v123);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-5];
    v123 = stack[0];
    fn = elt(env, 12); /* mkg1 */
    v123 = (*qfn2(fn))(qenv(fn), v124, v123);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-5];
    {
        Lisp_Object v180 = stack[-1];
        popv(6);
        fn = elt(env, 10); /* addf */
        return (*qfn2(fn))(qenv(fn), v180, v123);
    }

v12:
    v123 = (Lisp_Object)33; /* 2 */
    { popv(6); return onevalue(v123); }
/* error exit handlers */
v130:
    popv(6);
    return nil;
}



/* Code for evload */

static Lisp_Object CC_evload(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v24;
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
    v24 = stack[0];
    if (v24 == nil) goto v45;
    v24 = stack[0];
    v24 = qcar(v24);
    v24 = Lload_module(nil, v24);
    nil = C_nil;
    if (exception_pending()) goto v27;
    env = stack[-1];
    v24 = stack[0];
    v24 = qcdr(v24);
    stack[0] = v24;
    goto v3;

v45:
    v24 = nil;
    { popv(2); return onevalue(v24); }
/* error exit handlers */
v27:
    popv(2);
    return nil;
}



/* Code for module */

static Lisp_Object CC_module(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v13, v24;
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
    v13 = v0;
/* end of prologue */
    v24 = qvalue(elt(env, 1)); /* !*mode */
    v13 = qvalue(elt(env, 2)); /* mode!-list!* */
    v13 = cons(v24, v13);
    nil = C_nil;
    if (exception_pending()) goto v26;
    env = stack[0];
    qvalue(elt(env, 2)) = v13; /* mode!-list!* */
    v13 = nil;
    v13 = ncons(v13);
    nil = C_nil;
    if (exception_pending()) goto v26;
    env = stack[0];
    qvalue(elt(env, 3)) = v13; /* alglist!* */
    v13 = elt(env, 4); /* symbolic */
    qvalue(elt(env, 1)) = v13; /* !*mode */
    v13 = nil;
    { popv(1); return onevalue(v13); }
/* error exit handlers */
v26:
    popv(1);
    return nil;
}



/* Code for mkstrng */

static Lisp_Object CC_mkstrng(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object v9;
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v9 = v0;
/* end of prologue */
    return onevalue(v9);
}



/* Code for eqexpr */

static Lisp_Object CC_eqexpr(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v30, v99, v10;
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
    v10 = v0;
/* end of prologue */
    v30 = v10;
    if (!consp(v30)) goto v3;
    v30 = v10;
    v99 = qcar(v30);
    v30 = elt(env, 1); /* equalopr */
    v30 = Lflagp(nil, v99, v30);
    if (v30 == nil) goto v5;
    v30 = v10;
    v30 = qcdr(v30);
    v30 = qcdr(v30);
    if (v30 == nil) goto v38;
    v30 = v10;
    v30 = qcdr(v30);
    v30 = qcdr(v30);
    v30 = qcdr(v30);
    v30 = (v30 == nil ? lisp_true : nil);
    return onevalue(v30);

v38:
    v30 = nil;
    return onevalue(v30);

v5:
    v30 = nil;
    return onevalue(v30);

v3:
    v30 = nil;
    return onevalue(v30);
}



/* Code for diffp */

static Lisp_Object CC_diffp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v795, v796, v797, v798;
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
    stack[-1] = nil;
    v795 = stack[-5];
    v795 = qcdr(v795);
    stack[-6] = v795;
    v795 = stack[-5];
    v795 = qcar(v795);
    stack[-5] = v795;
    v796 = stack[-6];
    v795 = (Lisp_Object)17; /* 1 */
    v795 = (Lisp_Object)greaterp2(v796, v795);
    nil = C_nil;
    if (exception_pending()) goto v799;
    v795 = v795 ? lisp_true : nil;
    env = stack[-7];
    if (v795 == nil) goto v117;
    v795 = stack[-5];
    fn = elt(env, 19); /* noncomp */
    v795 = (*qfn1(fn))(qenv(fn), v795);
    nil = C_nil;
    if (exception_pending()) goto v799;
    env = stack[-7];
    if (v795 == nil) goto v117;
    v796 = stack[-5];
    v795 = stack[-4];
    v795 = list2(v796, v795);
    nil = C_nil;
    if (exception_pending()) goto v799;
    env = stack[-7];
    fn = elt(env, 20); /* simpdf */
    stack[-1] = (*qfn1(fn))(qenv(fn), v795);
    nil = C_nil;
    if (exception_pending()) goto v799;
    env = stack[-7];
    stack[0] = stack[-5];
    v795 = stack[-6];
    v795 = sub1(v795);
    nil = C_nil;
    if (exception_pending()) goto v799;
    env = stack[-7];
    v795 = list2(stack[0], v795);
    nil = C_nil;
    if (exception_pending()) goto v799;
    env = stack[-7];
    fn = elt(env, 21); /* simpexpt */
    v795 = (*qfn1(fn))(qenv(fn), v795);
    nil = C_nil;
    if (exception_pending()) goto v799;
    env = stack[-7];
    fn = elt(env, 22); /* multsq */
    stack[-1] = (*qfn2(fn))(qenv(fn), stack[-1], v795);
    nil = C_nil;
    if (exception_pending()) goto v799;
    env = stack[-7];
    v796 = stack[-5];
    v795 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 23); /* to */
    v796 = (*qfn2(fn))(qenv(fn), v796, v795);
    nil = C_nil;
    if (exception_pending()) goto v799;
    env = stack[-7];
    v795 = (Lisp_Object)17; /* 1 */
    v795 = cons(v796, v795);
    nil = C_nil;
    if (exception_pending()) goto v799;
    env = stack[-7];
    v796 = ncons(v795);
    nil = C_nil;
    if (exception_pending()) goto v799;
    env = stack[-7];
    v795 = (Lisp_Object)17; /* 1 */
    stack[0] = cons(v796, v795);
    nil = C_nil;
    if (exception_pending()) goto v799;
    env = stack[-7];
    stack[-2] = stack[-5];
    v795 = stack[-6];
    v795 = sub1(v795);
    nil = C_nil;
    if (exception_pending()) goto v799;
    env = stack[-7];
    v796 = cons(stack[-2], v795);
    nil = C_nil;
    if (exception_pending()) goto v799;
    env = stack[-7];
    v795 = stack[-4];
    v795 = CC_diffp(env, v796, v795);
    nil = C_nil;
    if (exception_pending()) goto v799;
    env = stack[-7];
    fn = elt(env, 22); /* multsq */
    v795 = (*qfn2(fn))(qenv(fn), stack[0], v795);
    nil = C_nil;
    if (exception_pending()) goto v799;
    env = stack[-7];
    {
        Lisp_Object v800 = stack[-1];
        popv(8);
        fn = elt(env, 24); /* addsq */
        return (*qfn2(fn))(qenv(fn), v800, v795);
    }

v117:
    v796 = stack[-5];
    v795 = stack[-4];
    if (!(v796 == v795)) goto v119;
    v796 = (Lisp_Object)17; /* 1 */
    v795 = (Lisp_Object)17; /* 1 */
    v795 = cons(v796, v795);
    nil = C_nil;
    if (exception_pending()) goto v799;
    env = stack[-7];
    stack[-1] = v795;
    if (!(v795 == nil)) goto v425;

v119:
    v795 = stack[-5];
    if (!consp(v795)) goto v324;
    v795 = stack[-5];
    v795 = qcar(v795);
    if (!consp(v795)) goto v214;
    v796 = stack[-5];
    v795 = stack[-4];
    fn = elt(env, 25); /* difff */
    v795 = (*qfn2(fn))(qenv(fn), v796, v795);
    nil = C_nil;
    if (exception_pending()) goto v799;
    env = stack[-7];
    stack[-1] = v795;
    if (!(v795 == nil)) goto v425;

v214:
    v795 = stack[-5];
    v796 = qcar(v795);
    v795 = elt(env, 1); /* !*sq */
    if (!(v796 == v795)) goto v212;
    v795 = stack[-5];
    v795 = qcdr(v795);
    v796 = qcar(v795);
    v795 = stack[-4];
    fn = elt(env, 26); /* diffsq */
    v795 = (*qfn2(fn))(qenv(fn), v796, v795);
    nil = C_nil;
    if (exception_pending()) goto v799;
    env = stack[-7];
    stack[-1] = v795;
    if (!(v795 == nil)) goto v425;

v212:
    v795 = stack[-5];
    v796 = qcar(v795);
    v795 = elt(env, 2); /* dfform */
    v795 = get(v796, v795);
    env = stack[-7];
    stack[-3] = v795;
    if (v795 == nil) goto v257;
    v798 = stack[-3];
    v797 = stack[-5];
    v796 = stack[-4];
    v795 = stack[-6];
        popv(8);
        return Lapply3(nil, 4, v798, v797, v796, v795);

v257:
    v795 = stack[-5];
    stack[0] = qcar(v795);
    v795 = stack[-5];
    fn = elt(env, 27); /* dfn_prop */
    v795 = (*qfn1(fn))(qenv(fn), v795);
    nil = C_nil;
    if (exception_pending()) goto v799;
    env = stack[-7];
    v795 = get(stack[0], v795);
    env = stack[-7];
    stack[-3] = v795;
    if (v795 == nil) goto v248;
    v795 = stack[-3];
    stack[-2] = v795;
    v795 = stack[-5];
    v795 = qcdr(v795);
    stack[0] = v795;
    goto v476;

v476:
    v795 = stack[0];
    v795 = qcar(v795);
    fn = elt(env, 28); /* simp */
    v796 = (*qfn1(fn))(qenv(fn), v795);
    nil = C_nil;
    if (exception_pending()) goto v799;
    env = stack[-7];
    v795 = stack[-4];
    fn = elt(env, 26); /* diffsq */
    v796 = (*qfn2(fn))(qenv(fn), v796, v795);
    nil = C_nil;
    if (exception_pending()) goto v799;
    env = stack[-7];
    v795 = stack[-1];
    v795 = cons(v796, v795);
    nil = C_nil;
    if (exception_pending()) goto v799;
    env = stack[-7];
    stack[-1] = v795;
    v795 = stack[-1];
    v795 = qcar(v795);
    v795 = qcar(v795);
    if (v795 == nil) goto v546;
    v795 = stack[-2];
    v795 = qcar(v795);
    if (!(v795 == nil)) goto v546;

v732:
    v795 = stack[-5];
    v796 = qcar(v795);
    v795 = elt(env, 13); /* df */
    if (v796 == v795) goto v801;
    v797 = elt(env, 13); /* df */
    v796 = stack[-5];
    v795 = stack[-4];
    v795 = list3(v797, v796, v795);
    nil = C_nil;
    if (exception_pending()) goto v799;
    env = stack[-7];
    stack[-1] = v795;
    goto v26;

v26:
    v795 = stack[-1];
    fn = elt(env, 29); /* opmtch */
    v795 = (*qfn1(fn))(qenv(fn), v795);
    nil = C_nil;
    if (exception_pending()) goto v799;
    env = stack[-7];
    stack[-3] = v795;
    if (v795 == nil) goto v802;
    v795 = stack[-3];
    fn = elt(env, 28); /* simp */
    v795 = (*qfn1(fn))(qenv(fn), v795);
    nil = C_nil;
    if (exception_pending()) goto v799;
    env = stack[-7];
    stack[-1] = v795;
    goto v425;

v425:
    v796 = stack[-5];
    v795 = qvalue(elt(env, 4)); /* wtl!* */
    v795 = Latsoc(nil, v796, v795);
    stack[-3] = v795;
    if (v795 == nil) goto v296;
    stack[0] = elt(env, 5); /* k!* */
    v795 = stack[-3];
    v795 = qcdr(v795);
    v795 = negate(v795);
    nil = C_nil;
    if (exception_pending()) goto v799;
    env = stack[-7];
    fn = elt(env, 23); /* to */
    v796 = (*qfn2(fn))(qenv(fn), stack[0], v795);
    nil = C_nil;
    if (exception_pending()) goto v799;
    env = stack[-7];
    v795 = (Lisp_Object)17; /* 1 */
    v795 = cons(v796, v795);
    nil = C_nil;
    if (exception_pending()) goto v799;
    env = stack[-7];
    v796 = ncons(v795);
    nil = C_nil;
    if (exception_pending()) goto v799;
    env = stack[-7];
    v795 = (Lisp_Object)17; /* 1 */
    v796 = cons(v796, v795);
    nil = C_nil;
    if (exception_pending()) goto v799;
    env = stack[-7];
    v795 = stack[-1];
    fn = elt(env, 22); /* multsq */
    v795 = (*qfn2(fn))(qenv(fn), v796, v795);
    nil = C_nil;
    if (exception_pending()) goto v799;
    env = stack[-7];
    stack[-1] = v795;
    goto v296;

v296:
    v795 = stack[-6];
    v795 = sub1(v795);
    nil = C_nil;
    if (exception_pending()) goto v799;
    env = stack[-7];
    stack[0] = v795;
    v796 = stack[-6];
    v795 = (Lisp_Object)17; /* 1 */
    if (v796 == v795) goto v289;
    v796 = qvalue(elt(env, 6)); /* dmode!* */
    v795 = elt(env, 7); /* convert */
    v795 = Lflagp(nil, v796, v795);
    env = stack[-7];
    if (v795 == nil) goto v537;
    v796 = qvalue(elt(env, 6)); /* dmode!* */
    v795 = elt(env, 8); /* i2d */
    v796 = get(v796, v795);
    env = stack[-7];
    v795 = stack[-6];
    v795 = Lapply1(nil, v796, v795);
    nil = C_nil;
    if (exception_pending()) goto v799;
    env = stack[-7];
    fn = elt(env, 30); /* int!-equiv!-chk */
    v795 = (*qfn1(fn))(qenv(fn), v795);
    nil = C_nil;
    if (exception_pending()) goto v799;
    env = stack[-7];
    stack[-6] = v795;
    if (!(v795 == nil)) goto v537;
    v796 = nil;
    v795 = (Lisp_Object)17; /* 1 */
    v795 = cons(v796, v795);
    nil = C_nil;
    if (exception_pending()) goto v799;
    env = stack[-7];
    goto v291;

v291:
    {
        popv(8);
        fn = elt(env, 31); /* rationalizesq */
        return (*qfn1(fn))(qenv(fn), v795);
    }

v537:
    v796 = stack[-5];
    v795 = stack[0];
    fn = elt(env, 23); /* to */
    v796 = (*qfn2(fn))(qenv(fn), v796, v795);
    nil = C_nil;
    if (exception_pending()) goto v799;
    env = stack[-7];
    v795 = stack[-6];
    v795 = cons(v796, v795);
    nil = C_nil;
    if (exception_pending()) goto v799;
    env = stack[-7];
    v796 = ncons(v795);
    nil = C_nil;
    if (exception_pending()) goto v799;
    env = stack[-7];
    v795 = (Lisp_Object)17; /* 1 */
    v796 = cons(v796, v795);
    nil = C_nil;
    if (exception_pending()) goto v799;
    env = stack[-7];
    v795 = stack[-1];
    fn = elt(env, 22); /* multsq */
    v795 = (*qfn2(fn))(qenv(fn), v796, v795);
    nil = C_nil;
    if (exception_pending()) goto v799;
    env = stack[-7];
    goto v291;

v289:
    v795 = stack[-1];
    goto v291;

v802:
    v796 = stack[-5];
    v795 = stack[-4];
    fn = elt(env, 32); /* depends */
    v795 = (*qfn2(fn))(qenv(fn), v796, v795);
    nil = C_nil;
    if (exception_pending()) goto v799;
    env = stack[-7];
    if (!(v795 == nil)) goto v803;
    v795 = qvalue(elt(env, 10)); /* !*depend */
    if (!(v795 == nil)) goto v803;
    v796 = nil;
    v795 = (Lisp_Object)17; /* 1 */
    popv(8);
    return cons(v796, v795);

v803:
    v796 = stack[-1];
    v795 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 33); /* mksq */
    v795 = (*qfn2(fn))(qenv(fn), v796, v795);
    nil = C_nil;
    if (exception_pending()) goto v799;
    env = stack[-7];
    stack[-1] = v795;
    goto v425;

v801:
    v795 = stack[-5];
    v795 = qcdr(v795);
    v796 = qcar(v795);
    v795 = stack[-4];
    if (!(v796 == v795)) goto v603;
    v795 = qvalue(elt(env, 14)); /* !*commutedf */
    if (v795 == nil) goto v804;
    v795 = qvalue(elt(env, 10)); /* !*depend */
    if (!(v795 == nil)) goto v804;
    v796 = nil;
    v795 = (Lisp_Object)17; /* 1 */
    popv(8);
    return cons(v796, v795);

v804:
    v795 = qvalue(elt(env, 15)); /* !*simpnoncomdf */
    if (v795 == nil) goto v805;
    v796 = stack[-4];
    v795 = qvalue(elt(env, 12)); /* depl!* */
    v795 = Latsoc(nil, v796, v795);
    stack[-1] = v795;
    if (v795 == nil) goto v805;
    v795 = stack[-1];
    v795 = qcdr(v795);
    v795 = qcdr(v795);
    if (!(v795 == nil)) goto v805;
    v795 = stack[-5];
    v795 = qcdr(v795);
    v795 = qcdr(v795);
    v795 = qcar(v795);
    stack[-3] = v795;
    v797 = elt(env, 13); /* df */
    v796 = stack[-5];
    v795 = stack[-3];
    v795 = list3(v797, v796, v795);
    nil = C_nil;
    if (exception_pending()) goto v799;
    env = stack[-7];
    fn = elt(env, 28); /* simp */
    stack[0] = (*qfn1(fn))(qenv(fn), v795);
    nil = C_nil;
    if (exception_pending()) goto v799;
    env = stack[-7];
    v797 = elt(env, 13); /* df */
    v796 = stack[-4];
    v795 = stack[-3];
    v795 = list3(v797, v796, v795);
    nil = C_nil;
    if (exception_pending()) goto v799;
    env = stack[-7];
    fn = elt(env, 28); /* simp */
    v795 = (*qfn1(fn))(qenv(fn), v795);
    nil = C_nil;
    if (exception_pending()) goto v799;
    env = stack[-7];
    fn = elt(env, 34); /* quotsq */
    v795 = (*qfn2(fn))(qenv(fn), stack[0], v795);
    nil = C_nil;
    if (exception_pending()) goto v799;
    env = stack[-7];
    stack[-1] = v795;
    goto v425;

v805:
    v795 = stack[-5];
    v795 = qcdr(v795);
    v796 = qcar(v795);
    v795 = elt(env, 16); /* int */
    if (!consp(v796)) goto v603;
    v796 = qcar(v796);
    if (!(v796 == v795)) goto v603;
    v795 = stack[-5];
    v795 = qcdr(v795);
    v795 = qcar(v795);
    v795 = qcdr(v795);
    v795 = qcdr(v795);
    v796 = qcar(v795);
    v795 = stack[-4];
    if (v796 == v795) goto v806;
    v795 = qvalue(elt(env, 17)); /* !*allowdfint */
    if (v795 == nil) goto v603;
    v795 = stack[-5];
    v795 = qcdr(v795);
    v795 = qcar(v795);
    v795 = qcdr(v795);
    v795 = qcar(v795);
    fn = elt(env, 35); /* simp!* */
    v796 = (*qfn1(fn))(qenv(fn), v795);
    nil = C_nil;
    if (exception_pending()) goto v799;
    env = stack[-7];
    v795 = stack[-4];
    fn = elt(env, 26); /* diffsq */
    v795 = (*qfn2(fn))(qenv(fn), v796, v795);
    nil = C_nil;
    if (exception_pending()) goto v799;
    env = stack[-7];
    stack[-1] = v795;
    fn = elt(env, 36); /* not_df_p */
    v795 = (*qfn1(fn))(qenv(fn), v795);
    nil = C_nil;
    if (exception_pending()) goto v799;
    env = stack[-7];
    if (v795 == nil) goto v603;
    stack[-2] = elt(env, 13); /* df */
    stack[0] = elt(env, 16); /* int */
    v795 = stack[-1];
    fn = elt(env, 37); /* mk!*sq */
    v796 = (*qfn1(fn))(qenv(fn), v795);
    nil = C_nil;
    if (exception_pending()) goto v799;
    env = stack[-7];
    v795 = stack[-5];
    v795 = qcdr(v795);
    v795 = qcar(v795);
    v795 = qcdr(v795);
    v795 = qcdr(v795);
    v795 = qcar(v795);
    v795 = list3(stack[0], v796, v795);
    nil = C_nil;
    if (exception_pending()) goto v799;
    env = stack[-7];
    fn = elt(env, 38); /* reval */
    v796 = (*qfn1(fn))(qenv(fn), v795);
    nil = C_nil;
    if (exception_pending()) goto v799;
    env = stack[-7];
    v795 = stack[-5];
    v795 = qcdr(v795);
    v795 = qcdr(v795);
    v795 = list2star(stack[-2], v796, v795);
    nil = C_nil;
    if (exception_pending()) goto v799;
    env = stack[-7];
    stack[-1] = v795;
    goto v26;

v603:
    v795 = stack[-5];
    v795 = qcdr(v795);
    stack[0] = qcar(v795);
    v796 = stack[-5];
    v795 = stack[-4];
    fn = elt(env, 39); /* merge!-ind!-vars */
    v795 = (*qfn2(fn))(qenv(fn), v796, v795);
    nil = C_nil;
    if (exception_pending()) goto v799;
    env = stack[-7];
    v797 = cons(stack[0], v795);
    nil = C_nil;
    if (exception_pending()) goto v799;
    env = stack[-7];
    stack[-1] = v797;
    v796 = elt(env, 13); /* df */
    v795 = elt(env, 18); /* kvalue */
    v795 = get(v796, v795);
    env = stack[-7];
    fn = elt(env, 40); /* find_sub_df */
    v795 = (*qfn2(fn))(qenv(fn), v797, v795);
    nil = C_nil;
    if (exception_pending()) goto v799;
    env = stack[-7];
    stack[-3] = v795;
    if (v795 == nil) goto v807;
    v795 = stack[-3];
    v795 = qcar(v795);
    fn = elt(env, 28); /* simp */
    v795 = (*qfn1(fn))(qenv(fn), v795);
    nil = C_nil;
    if (exception_pending()) goto v799;
    env = stack[-7];
    stack[-1] = v795;
    v795 = stack[-3];
    v795 = qcdr(v795);
    stack[-3] = v795;
    goto v808;

v808:
    v795 = stack[-3];
    if (v795 == nil) goto v425;
    v795 = stack[-3];
    v795 = qcar(v795);
    stack[-2] = v795;
    v795 = (Lisp_Object)17; /* 1 */
    stack[0] = v795;
    goto v809;

v809:
    v795 = stack[-2];
    v796 = qcdr(v795);
    v795 = stack[0];
    v795 = difference2(v796, v795);
    nil = C_nil;
    if (exception_pending()) goto v799;
    env = stack[-7];
    v795 = Lminusp(nil, v795);
    env = stack[-7];
    if (v795 == nil) goto v810;
    v795 = stack[-3];
    v795 = qcdr(v795);
    stack[-3] = v795;
    goto v808;

v810:
    v796 = stack[-1];
    v795 = stack[-2];
    v795 = qcar(v795);
    fn = elt(env, 26); /* diffsq */
    v795 = (*qfn2(fn))(qenv(fn), v796, v795);
    nil = C_nil;
    if (exception_pending()) goto v799;
    env = stack[-7];
    stack[-1] = v795;
    v795 = stack[0];
    v795 = add1(v795);
    nil = C_nil;
    if (exception_pending()) goto v799;
    env = stack[-7];
    stack[0] = v795;
    goto v809;

v807:
    v796 = elt(env, 13); /* df */
    v795 = stack[-1];
    v795 = cons(v796, v795);
    nil = C_nil;
    if (exception_pending()) goto v799;
    env = stack[-7];
    stack[-1] = v795;
    goto v26;

v806:
    v797 = elt(env, 13); /* df */
    v795 = stack[-5];
    v795 = qcdr(v795);
    v795 = qcar(v795);
    v795 = qcdr(v795);
    v796 = qcar(v795);
    v795 = stack[-5];
    v795 = qcdr(v795);
    v795 = qcdr(v795);
    v795 = list2star(v797, v796, v795);
    nil = C_nil;
    if (exception_pending()) goto v799;
    env = stack[-7];
    stack[-1] = v795;
    goto v26;

v546:
    v795 = stack[-2];
    v795 = qcdr(v795);
    stack[-2] = v795;
    v795 = stack[0];
    v795 = qcdr(v795);
    stack[0] = v795;
    v795 = stack[0];
    if (v795 == nil) goto v522;
    v795 = stack[-2];
    if (!(v795 == nil)) goto v476;

v522:
    v795 = stack[0];
    if (!(v795 == nil)) goto v732;
    v795 = stack[-2];
    if (!(v795 == nil)) goto v732;
    v795 = stack[-1];
    v795 = Lreverse(nil, v795);
    nil = C_nil;
    if (exception_pending()) goto v799;
    env = stack[-7];
    stack[-2] = v795;
    v795 = stack[-5];
    v795 = qcdr(v795);
    stack[0] = v795;
    v796 = nil;
    v795 = (Lisp_Object)17; /* 1 */
    v795 = cons(v796, v795);
    nil = C_nil;
    if (exception_pending()) goto v799;
    env = stack[-7];
    stack[-1] = v795;
    goto v1;

v1:
    v795 = stack[-2];
    v795 = qcar(v795);
    v795 = qcar(v795);
    if (v795 == nil) goto v673;
    v795 = stack[-2];
    stack[-4] = qcar(v795);
    v795 = stack[-3];
    v795 = qcar(v795);
    v796 = qcar(v795);
    v795 = stack[0];
    fn = elt(env, 41); /* pair */
    v796 = (*qfn2(fn))(qenv(fn), v796, v795);
    nil = C_nil;
    if (exception_pending()) goto v799;
    env = stack[-7];
    v795 = stack[-3];
    v795 = qcar(v795);
    v795 = qcdr(v795);
    v795 = Lsubla(nil, v796, v795);
    nil = C_nil;
    if (exception_pending()) goto v799;
    env = stack[-7];
    fn = elt(env, 28); /* simp */
    v795 = (*qfn1(fn))(qenv(fn), v795);
    nil = C_nil;
    if (exception_pending()) goto v799;
    env = stack[-7];
    fn = elt(env, 22); /* multsq */
    v796 = (*qfn2(fn))(qenv(fn), stack[-4], v795);
    nil = C_nil;
    if (exception_pending()) goto v799;
    env = stack[-7];
    v795 = stack[-1];
    fn = elt(env, 24); /* addsq */
    v795 = (*qfn2(fn))(qenv(fn), v796, v795);
    nil = C_nil;
    if (exception_pending()) goto v799;
    env = stack[-7];
    stack[-1] = v795;
    goto v673;

v673:
    v795 = stack[-3];
    v795 = qcdr(v795);
    stack[-3] = v795;
    v795 = stack[-2];
    v795 = qcdr(v795);
    stack[-2] = v795;
    v795 = stack[-2];
    if (v795 == nil) goto v425;
    else goto v1;

v248:
    v795 = stack[-5];
    v796 = qcar(v795);
    v795 = elt(env, 3); /* plus */
    if (!(v796 == v795)) goto v732;
    v795 = stack[-5];
    fn = elt(env, 28); /* simp */
    v796 = (*qfn1(fn))(qenv(fn), v795);
    nil = C_nil;
    if (exception_pending()) goto v799;
    env = stack[-7];
    v795 = stack[-4];
    fn = elt(env, 26); /* diffsq */
    v795 = (*qfn2(fn))(qenv(fn), v796, v795);
    nil = C_nil;
    if (exception_pending()) goto v799;
    env = stack[-7];
    stack[-1] = v795;
    if (v795 == nil) goto v732;
    else goto v425;

v324:
    v796 = stack[-5];
    v795 = stack[-4];
    fn = elt(env, 32); /* depends */
    v795 = (*qfn2(fn))(qenv(fn), v796, v795);
    nil = C_nil;
    if (exception_pending()) goto v799;
    env = stack[-7];
    if (!(v795 == nil)) goto v811;
    v796 = stack[-5];
    v795 = qvalue(elt(env, 9)); /* powlis!* */
    v795 = Latsoc(nil, v796, v795);
    stack[-3] = v795;
    if (v795 == nil) goto v502;
    v795 = stack[-3];
    v795 = qcdr(v795);
    v795 = qcdr(v795);
    v795 = qcdr(v795);
    v796 = qcar(v795);
    v795 = stack[-4];
    fn = elt(env, 32); /* depends */
    v795 = (*qfn2(fn))(qenv(fn), v796, v795);
    nil = C_nil;
    if (exception_pending()) goto v799;
    env = stack[-7];
    if (!(v795 == nil)) goto v811;

v502:
    v795 = qvalue(elt(env, 10)); /* !*depend */
    if (!(v795 == nil)) goto v811;
    v796 = nil;
    v795 = (Lisp_Object)17; /* 1 */
    popv(8);
    return cons(v796, v795);

v811:
    v795 = qvalue(elt(env, 11)); /* !*expanddf */
    if (v795 == nil) goto v699;
    v797 = stack[-4];
    v796 = stack[-5];
    v795 = qvalue(elt(env, 12)); /* depl!* */
    v795 = Latsoc(nil, v796, v795);
    v795 = qcdr(v795);
    stack[-3] = v795;
    v795 = Lmemq(nil, v797, v795);
    if (!(v795 == nil)) goto v699;
    v796 = nil;
    v795 = (Lisp_Object)17; /* 1 */
    v795 = cons(v796, v795);
    nil = C_nil;
    if (exception_pending()) goto v799;
    env = stack[-7];
    stack[-1] = v795;
    v795 = stack[-3];
    stack[-3] = v795;
    goto v812;

v812:
    v795 = stack[-3];
    if (v795 == nil) goto v425;
    v795 = stack[-3];
    v795 = qcar(v795);
    stack[-2] = v795;
    v797 = elt(env, 13); /* df */
    v796 = stack[-5];
    v795 = stack[-2];
    v795 = list3(v797, v796, v795);
    nil = C_nil;
    if (exception_pending()) goto v799;
    env = stack[-7];
    fn = elt(env, 28); /* simp */
    stack[0] = (*qfn1(fn))(qenv(fn), v795);
    nil = C_nil;
    if (exception_pending()) goto v799;
    env = stack[-7];
    v797 = elt(env, 13); /* df */
    v796 = stack[-2];
    v795 = stack[-4];
    v795 = list3(v797, v796, v795);
    nil = C_nil;
    if (exception_pending()) goto v799;
    env = stack[-7];
    fn = elt(env, 28); /* simp */
    v795 = (*qfn1(fn))(qenv(fn), v795);
    nil = C_nil;
    if (exception_pending()) goto v799;
    env = stack[-7];
    fn = elt(env, 22); /* multsq */
    v795 = (*qfn2(fn))(qenv(fn), stack[0], v795);
    nil = C_nil;
    if (exception_pending()) goto v799;
    env = stack[-7];
    fn = elt(env, 24); /* addsq */
    v795 = (*qfn2(fn))(qenv(fn), stack[-1], v795);
    nil = C_nil;
    if (exception_pending()) goto v799;
    env = stack[-7];
    stack[-1] = v795;
    v795 = stack[-3];
    v795 = qcdr(v795);
    stack[-3] = v795;
    goto v812;

v699:
    v797 = elt(env, 13); /* df */
    v796 = stack[-5];
    v795 = stack[-4];
    v795 = list3(v797, v796, v795);
    nil = C_nil;
    if (exception_pending()) goto v799;
    env = stack[-7];
    stack[-1] = v795;
    v795 = stack[-1];
    fn = elt(env, 29); /* opmtch */
    v795 = (*qfn1(fn))(qenv(fn), v795);
    nil = C_nil;
    if (exception_pending()) goto v799;
    env = stack[-7];
    stack[-3] = v795;
    if (v795 == nil) goto v813;
    v795 = stack[-3];
    fn = elt(env, 28); /* simp */
    v795 = (*qfn1(fn))(qenv(fn), v795);
    nil = C_nil;
    if (exception_pending()) goto v799;
    env = stack[-7];
    goto v814;

v814:
    stack[-1] = v795;
    goto v425;

v813:
    v796 = stack[-1];
    v795 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 33); /* mksq */
    v795 = (*qfn2(fn))(qenv(fn), v796, v795);
    nil = C_nil;
    if (exception_pending()) goto v799;
    env = stack[-7];
    goto v814;
/* error exit handlers */
v799:
    popv(8);
    return nil;
}



/* Code for put!-avalue */

static Lisp_Object MS_CDECL CC_putKavalue(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v16,
                         Lisp_Object v63, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v143, v144, v191;
    Lisp_Object fn;
    argcheck(nargs, 3, "put-avalue");
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
    stack[-2] = v16;
    stack[0] = v0;
/* end of prologue */
    v144 = stack[-2];
    v143 = elt(env, 1); /* scalar */
    if (v144 == v143) goto v44;
    v144 = stack[0];
    v143 = stack[-1];
    fn = elt(env, 6); /* smember */
    v143 = (*qfn2(fn))(qenv(fn), v144, v143);
    nil = C_nil;
    if (exception_pending()) goto v118;
    env = stack[-4];
    if (v143 == nil) goto v107;
    v143 = stack[0];
    {
        popv(5);
        fn = elt(env, 7); /* recursiveerror */
        return (*qfn1(fn))(qenv(fn), v143);
    }

v107:
    stack[-3] = stack[0];
    stack[0] = elt(env, 5); /* avalue */
    v144 = stack[-2];
    v143 = stack[-1];
    v143 = list2(v144, v143);
    nil = C_nil;
    if (exception_pending()) goto v118;
    {
        Lisp_Object v135 = stack[-3];
        Lisp_Object v119 = stack[0];
        popv(5);
        return Lputprop(nil, 3, v135, v119, v143);
    }

v44:
    v144 = stack[-1];
    v143 = elt(env, 2); /* !*sq */
    if (!consp(v144)) goto v27;
    v144 = qcar(v144);
    if (!(v144 == v143)) goto v27;
    v144 = stack[0];
    v143 = stack[-1];
    v143 = qcdr(v143);
    v143 = qcar(v143);
    fn = elt(env, 8); /* sq_member */
    v143 = (*qfn2(fn))(qenv(fn), v144, v143);
    nil = C_nil;
    if (exception_pending()) goto v118;
    env = stack[-4];
    if (v143 == nil) goto v27;
    v143 = stack[0];
    {
        popv(5);
        fn = elt(env, 7); /* recursiveerror */
        return (*qfn1(fn))(qenv(fn), v143);
    }

v27:
    v143 = qvalue(elt(env, 3)); /* !*reduce4 */
    if (v143 == nil) goto v100;
    v191 = stack[0];
    v144 = stack[-1];
    v143 = elt(env, 4); /* generic */
    {
        popv(5);
        fn = elt(env, 9); /* putobject */
        return (*qfnn(fn))(qenv(fn), 3, v191, v144, v143);
    }

v100:
    stack[-3] = stack[0];
    stack[0] = elt(env, 5); /* avalue */
    v144 = stack[-2];
    v143 = stack[-1];
    v143 = list2(v144, v143);
    nil = C_nil;
    if (exception_pending()) goto v118;
    {
        Lisp_Object v98 = stack[-3];
        Lisp_Object v117 = stack[0];
        popv(5);
        return Lputprop(nil, 3, v98, v117, v143);
    }
/* error exit handlers */
v118:
    popv(5);
    return nil;
}



/* Code for spur0i */

static Lisp_Object MS_CDECL CC_spur0i(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v16,
                         Lisp_Object v63, Lisp_Object v9,
                         Lisp_Object v3, Lisp_Object v4,
                         Lisp_Object v12, Lisp_Object v45,
                         Lisp_Object v5, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v264, v679, v159, v158, v160;
    Lisp_Object fn;
    argcheck(nargs, 9, "spur0i");
    if (stack >= stacklimit)
    {
        push6(v5,v45,v12,v4,v3,v9);
        push3(v63,v16,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop6(v0,v16,v63,v9,v3,v4);
        pop3(v12,v45,v5);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v5;
    stack[-3] = v45;
    stack[-4] = v12;
    stack[-5] = v4;
    stack[-6] = v3;
    stack[-7] = v9;
    stack[-8] = v63;
    stack[-9] = v16;
    stack[-10] = v0;
/* end of prologue */
    stack[-11] = nil;
    v679 = stack[-5];
    v264 = elt(env, 1); /* nospur */
    v264 = Lflagp(nil, v679, v264);
    env = stack[-12];
    if (v264 == nil) goto v35;
    v264 = stack[-2];
    v679 = qcar(v264);
    v264 = elt(env, 1); /* nospur */
    v264 = Lflagp(nil, v679, v264);
    env = stack[-12];
    if (v264 == nil) goto v35;
    v159 = elt(env, 2); /* hephys */
    v679 = (Lisp_Object)161; /* 10 */
    v264 = elt(env, 3); /* "NOSPUR on more than one line not implemented" */
    fn = elt(env, 7); /* rerror */
    v264 = (*qfnn(fn))(qenv(fn), 3, v159, v679, v264);
    nil = C_nil;
    if (exception_pending()) goto v238;
    env = stack[-12];
    goto v13;

v13:
    v264 = stack[-2];
    v264 = qcdr(v264);
    stack[-2] = v264;
    v264 = stack[-2];
    v264 = qcar(v264);
    stack[-1] = v264;
    v264 = stack[-2];
    v264 = qcdr(v264);
    v264 = Lreverse(nil, v264);
    nil = C_nil;
    if (exception_pending()) goto v238;
    env = stack[-12];
    stack[-2] = v264;
    v264 = stack[-1];
    if (v264 == nil) goto v70;
    v679 = elt(env, 4); /* a */
    v264 = stack[-2];
    v264 = cons(v679, v264);
    nil = C_nil;
    if (exception_pending()) goto v238;
    env = stack[-12];
    stack[-2] = v264;
    goto v70;

v70:
    v264 = nil;
    stack[-1] = v264;
    goto v104;

v104:
    v264 = stack[-10];
    v679 = qcar(v264);
    v264 = stack[-2];
    v264 = qcar(v264);
    if (v679 == v264) goto v220;
    v264 = stack[-2];
    v679 = qcar(v264);
    v264 = stack[-1];
    v264 = cons(v679, v264);
    nil = C_nil;
    if (exception_pending()) goto v238;
    env = stack[-12];
    stack[-1] = v264;
    v264 = stack[-2];
    v264 = qcdr(v264);
    stack[-2] = v264;
    goto v104;

v220:
    v264 = stack[-2];
    v264 = qcdr(v264);
    stack[-2] = v264;
    v264 = stack[-10];
    v264 = qcdr(v264);
    stack[-10] = v264;
    v679 = stack[-5];
    v264 = elt(env, 1); /* nospur */
    v264 = Lflagp(nil, v679, v264);
    env = stack[-12];
    if (v264 == nil) goto v135;
    stack[0] = stack[-3];
    stack[-3] = stack[-10];
    v679 = stack[-1];
    v264 = stack[-2];
    v264 = cons(v679, v264);
    nil = C_nil;
    if (exception_pending()) goto v238;
    env = stack[-12];
    v264 = list2star(stack[0], stack[-3], v264);
    nil = C_nil;
    if (exception_pending()) goto v238;
    env = stack[-12];
    stack[-3] = v264;
    v264 = stack[-3];
    v264 = qcar(v264);
    stack[-1] = v264;
    v264 = stack[-3];
    v264 = qcdr(v264);
    v264 = qcar(v264);
    stack[-2] = v264;
    v264 = stack[-3];
    v264 = qcdr(v264);
    v264 = qcdr(v264);
    v264 = qcar(v264);
    stack[-10] = v264;
    v264 = stack[-3];
    v264 = qcdr(v264);
    v264 = qcdr(v264);
    v264 = qcdr(v264);
    stack[-3] = v264;
    goto v135;

v135:
    v264 = stack[-3];
    v264 = Lreverse(nil, v264);
    nil = C_nil;
    if (exception_pending()) goto v238;
    env = stack[-12];
    stack[-3] = v264;
    v264 = stack[-10];
    if (v264 == nil) goto v462;
    v679 = stack[-3];
    v264 = elt(env, 4); /* a */
    if (!consp(v679)) goto v462;
    v679 = qcar(v679);
    if (!(v679 == v264)) goto v462;

v109:
    v264 = stack[-10];
    fn = elt(env, 8); /* hevenp */
    v264 = (*qfn1(fn))(qenv(fn), v264);
    nil = C_nil;
    if (exception_pending()) goto v238;
    env = stack[-12];
    if (!(v264 == nil)) goto v228;
    v264 = stack[-4];
    v264 = negate(v264);
    nil = C_nil;
    if (exception_pending()) goto v238;
    env = stack[-12];
    stack[-4] = v264;
    goto v228;

v228:
    stack[0] = elt(env, 4); /* a */
    v679 = stack[-10];
    v264 = stack[-3];
    v264 = qcdr(v264);
    v264 = Lappend(nil, v679, v264);
    nil = C_nil;
    if (exception_pending()) goto v238;
    env = stack[-12];
    v264 = cons(stack[0], v264);
    nil = C_nil;
    if (exception_pending()) goto v238;
    env = stack[-12];
    stack[-10] = v264;
    goto v189;

v189:
    v264 = stack[-11];
    if (v264 == nil) goto v519;
    v264 = stack[-11];
    stack[-5] = v264;
    goto v519;

v519:
    stack[-3] = elt(env, 5); /* g */
    stack[0] = stack[-5];
    v264 = stack[-1];
    v264 = Lreverse(nil, v264);
    nil = C_nil;
    if (exception_pending()) goto v238;
    env = stack[-12];
    v264 = list2star(stack[-3], stack[0], v264);
    nil = C_nil;
    if (exception_pending()) goto v238;
    env = stack[-12];
    fn = elt(env, 9); /* mksf */
    stack[-1] = (*qfn1(fn))(qenv(fn), v264);
    nil = C_nil;
    if (exception_pending()) goto v238;
    env = stack[-12];
    v159 = stack[-10];
    v679 = stack[-5];
    v264 = stack[-9];
    fn = elt(env, 10); /* brace */
    stack[-3] = (*qfnn(fn))(qenv(fn), 3, v159, v679, v264);
    nil = C_nil;
    if (exception_pending()) goto v238;
    env = stack[-12];
    stack[0] = stack[-4];
    v679 = stack[-2];
    v264 = stack[-5];
    fn = elt(env, 11); /* mkg1 */
    v264 = (*qfn2(fn))(qenv(fn), v679, v264);
    nil = C_nil;
    if (exception_pending()) goto v238;
    env = stack[-12];
    fn = elt(env, 12); /* multf */
    v264 = (*qfn2(fn))(qenv(fn), stack[0], v264);
    nil = C_nil;
    if (exception_pending()) goto v238;
    env = stack[-12];
    fn = elt(env, 12); /* multf */
    v264 = (*qfn2(fn))(qenv(fn), stack[-3], v264);
    nil = C_nil;
    if (exception_pending()) goto v238;
    env = stack[-12];
    fn = elt(env, 13); /* mkf */
    v264 = (*qfn2(fn))(qenv(fn), stack[-1], v264);
    nil = C_nil;
    if (exception_pending()) goto v238;
    env = stack[-12];
    stack[-2] = v264;
    v160 = stack[-2];
    v158 = stack[-9];
    v159 = stack[-8];
    v679 = stack[-7];
    v264 = stack[-6];
    fn = elt(env, 14); /* isimp1 */
    v264 = (*qfnn(fn))(qenv(fn), 5, v160, v158, v159, v679, v264);
    nil = C_nil;
    if (exception_pending()) goto v238;
    env = stack[-12];
    stack[-2] = v264;
    v264 = stack[-2];
    if (v264 == nil) { Lisp_Object res = stack[-2]; popv(13); return onevalue(res); }
    v679 = stack[-2];
    v264 = (Lisp_Object)33; /* 2 */
    fn = elt(env, 15); /* quotf */
    v264 = (*qfn2(fn))(qenv(fn), v679, v264);
    nil = C_nil;
    if (exception_pending()) goto v238;
    env = stack[-12];
    stack[-2] = v264;
    if (!(v264 == nil)) { Lisp_Object res = stack[-2]; popv(13); return onevalue(res); }
    stack[0] = elt(env, 6); /* spur0 */
    stack[-1] = stack[-4];
    stack[-2] = stack[-9];
    v159 = stack[-8];
    v679 = stack[-7];
    v264 = stack[-6];
    v264 = list3(v159, v679, v264);
    nil = C_nil;
    if (exception_pending()) goto v238;
    env = stack[-12];
    v264 = list3star(stack[0], stack[-1], stack[-2], v264);
    nil = C_nil;
    if (exception_pending()) goto v238;
    env = stack[-12];
    fn = elt(env, 16); /* errach */
    v264 = (*qfn1(fn))(qenv(fn), v264);
    nil = C_nil;
    if (exception_pending()) goto v238;
    v264 = nil;
    { popv(13); return onevalue(v264); }

v462:
    v679 = stack[-10];
    v264 = stack[-3];
    v264 = Lappend(nil, v679, v264);
    nil = C_nil;
    if (exception_pending()) goto v238;
    env = stack[-12];
    stack[-10] = v264;
    if (v264 == nil) goto v109;
    else goto v189;

v35:
    v264 = stack[-2];
    v679 = qcar(v264);
    v264 = elt(env, 1); /* nospur */
    v264 = Lflagp(nil, v679, v264);
    env = stack[-12];
    if (v264 == nil) goto v13;
    v264 = stack[-2];
    v264 = qcar(v264);
    stack[-11] = v264;
    goto v13;
/* error exit handlers */
v238:
    popv(13);
    return nil;
}



/* Code for extmult */

static Lisp_Object CC_extmult(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v235, v137;
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
    v235 = stack[-3];
    if (v235 == nil) goto v4;
    v235 = stack[-2];
    if (v235 == nil) goto v4;
    v235 = stack[-3];
    v235 = qcar(v235);
    v235 = qcar(v235);
    v137 = qcar(v235);
    v235 = stack[-2];
    v235 = qcar(v235);
    v235 = qcar(v235);
    fn = elt(env, 1); /* ordexn */
    v235 = (*qfn2(fn))(qenv(fn), v137, v235);
    nil = C_nil;
    if (exception_pending()) goto v116;
    env = stack[-5];
    v137 = v235;
    v235 = v137;
    if (v235 == nil) goto v82;
    v235 = v137;
    stack[-4] = qcdr(v235);
    v235 = v137;
    v235 = qcar(v235);
    if (v235 == nil) goto v56;
    v235 = stack[-3];
    v235 = qcar(v235);
    v137 = qcdr(v235);
    v235 = stack[-2];
    v235 = qcar(v235);
    v235 = qcdr(v235);
    fn = elt(env, 2); /* c!:subs2multf */
    v235 = (*qfn2(fn))(qenv(fn), v137, v235);
    nil = C_nil;
    if (exception_pending()) goto v116;
    env = stack[-5];
    fn = elt(env, 3); /* negf */
    v235 = (*qfn1(fn))(qenv(fn), v235);
    nil = C_nil;
    if (exception_pending()) goto v116;
    env = stack[-5];
    stack[-1] = v235;
    goto v220;

v220:
    v235 = stack[-3];
    v235 = qcar(v235);
    v137 = ncons(v235);
    nil = C_nil;
    if (exception_pending()) goto v116;
    env = stack[-5];
    v235 = stack[-2];
    v235 = qcdr(v235);
    stack[0] = CC_extmult(env, v137, v235);
    nil = C_nil;
    if (exception_pending()) goto v116;
    env = stack[-5];
    v235 = stack[-3];
    v137 = qcdr(v235);
    v235 = stack[-2];
    v235 = CC_extmult(env, v137, v235);
    nil = C_nil;
    if (exception_pending()) goto v116;
    env = stack[-5];
    fn = elt(env, 4); /* extadd */
    v235 = (*qfn2(fn))(qenv(fn), stack[0], v235);
    nil = C_nil;
    if (exception_pending()) goto v116;
    {
        Lisp_Object v114 = stack[-4];
        Lisp_Object v115 = stack[-1];
        popv(6);
        return acons(v114, v115, v235);
    }

v56:
    v235 = stack[-3];
    v235 = qcar(v235);
    v137 = qcdr(v235);
    v235 = stack[-2];
    v235 = qcar(v235);
    v235 = qcdr(v235);
    fn = elt(env, 2); /* c!:subs2multf */
    v235 = (*qfn2(fn))(qenv(fn), v137, v235);
    nil = C_nil;
    if (exception_pending()) goto v116;
    env = stack[-5];
    stack[-1] = v235;
    goto v220;

v82:
    v235 = stack[-3];
    v137 = qcdr(v235);
    v235 = stack[-2];
    stack[0] = CC_extmult(env, v137, v235);
    nil = C_nil;
    if (exception_pending()) goto v116;
    env = stack[-5];
    v235 = stack[-3];
    v235 = qcar(v235);
    v137 = ncons(v235);
    nil = C_nil;
    if (exception_pending()) goto v116;
    env = stack[-5];
    v235 = stack[-2];
    v235 = qcdr(v235);
    v235 = CC_extmult(env, v137, v235);
    nil = C_nil;
    if (exception_pending()) goto v116;
    env = stack[-5];
    {
        Lisp_Object v132 = stack[0];
        popv(6);
        fn = elt(env, 4); /* extadd */
        return (*qfn2(fn))(qenv(fn), v132, v235);
    }

v4:
    v235 = nil;
    { popv(6); return onevalue(v235); }
/* error exit handlers */
v116:
    popv(6);
    return nil;
}



/* Code for setk */

static Lisp_Object CC_setk(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v456, v83, v84;
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
    v83 = v0;
/* end of prologue */
    v456 = v83;
    if (!consp(v456)) goto v96;
    v456 = v83;
    v84 = qcar(v456);
    v456 = elt(env, 1); /* evalargfn */
    v456 = get(v84, v456);
    env = stack[-2];
    v84 = v456;
    v456 = v84;
    if (v456 == nil) goto v206;
    v456 = v83;
    stack[-1] = qcar(v456);
    v456 = v84;
    v83 = qcdr(v83);
    v456 = Lapply1(nil, v456, v83);
    nil = C_nil;
    if (exception_pending()) goto v143;
    env = stack[-2];
    v83 = cons(stack[-1], v456);
    nil = C_nil;
    if (exception_pending()) goto v143;
    env = stack[-2];
    v456 = stack[0];
    {
        popv(3);
        fn = elt(env, 4); /* setk0 */
        return (*qfn2(fn))(qenv(fn), v83, v456);
    }

v206:
    v456 = v83;
    v84 = qcar(v456);
    v456 = elt(env, 2); /* rtype */
    v84 = get(v84, v456);
    env = stack[-2];
    v456 = elt(env, 3); /* matrix */
    if (v84 == v456) goto v87;
    v456 = v83;
    stack[-1] = qcar(v456);
    v456 = v83;
    v456 = qcdr(v456);
    fn = elt(env, 5); /* revlis */
    v456 = (*qfn1(fn))(qenv(fn), v456);
    nil = C_nil;
    if (exception_pending()) goto v143;
    env = stack[-2];
    v83 = cons(stack[-1], v456);
    nil = C_nil;
    if (exception_pending()) goto v143;
    env = stack[-2];
    v456 = stack[0];
    {
        popv(3);
        fn = elt(env, 4); /* setk0 */
        return (*qfn2(fn))(qenv(fn), v83, v456);
    }

v87:
    v456 = stack[0];
    {
        popv(3);
        fn = elt(env, 4); /* setk0 */
        return (*qfn2(fn))(qenv(fn), v83, v456);
    }

v96:
    v456 = stack[0];
    {
        popv(3);
        fn = elt(env, 4); /* setk0 */
        return (*qfn2(fn))(qenv(fn), v83, v456);
    }
/* error exit handlers */
v143:
    popv(3);
    return nil;
}



/* Code for domainvalchk */

static Lisp_Object CC_domainvalchk(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v71, v101, v57;
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
    v101 = qvalue(elt(env, 1)); /* dmode!* */
    v71 = elt(env, 0); /* domainvalchk */
    v71 = get(v101, v71);
    env = stack[-3];
    stack[-2] = v71;
    if (v71 == nil) goto v5;
    v57 = stack[-2];
    v101 = stack[-1];
    v71 = stack[0];
        popv(4);
        return Lapply2(nil, 3, v57, v101, v71);

v5:
    v71 = stack[0];
    v71 = Lreverse(nil, v71);
    nil = C_nil;
    if (exception_pending()) goto v55;
    env = stack[-3];
    stack[0] = v71;
    goto v12;

v12:
    v71 = stack[0];
    if (v71 == nil) goto v46;
    v71 = stack[0];
    v71 = qcar(v71);
    v101 = qcdr(v71);
    v71 = (Lisp_Object)17; /* 1 */
    v71 = Lneq(nil, v101, v71);
    nil = C_nil;
    if (exception_pending()) goto v55;
    env = stack[-3];
    if (v71 == nil) goto v150;
    v71 = nil;
    { popv(4); return onevalue(v71); }

v150:
    v71 = stack[0];
    v71 = qcar(v71);
    fn = elt(env, 2); /* mk!*sq */
    v101 = (*qfn1(fn))(qenv(fn), v71);
    nil = C_nil;
    if (exception_pending()) goto v55;
    env = stack[-3];
    v71 = stack[-2];
    v71 = cons(v101, v71);
    nil = C_nil;
    if (exception_pending()) goto v55;
    env = stack[-3];
    stack[-2] = v71;
    v71 = stack[0];
    v71 = qcdr(v71);
    stack[0] = v71;
    goto v12;

v46:
    v101 = stack[-1];
    v71 = stack[-2];
    {
        popv(4);
        fn = elt(env, 3); /* valuechk */
        return (*qfn2(fn))(qenv(fn), v101, v71);
    }
/* error exit handlers */
v55:
    popv(4);
    return nil;
}



/* Code for stable!-sortip */

static Lisp_Object CC_stableKsortip(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v207, v519, v349;
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
    v207 = stack[-3];
    if (v207 == nil) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v207 = stack[-3];
    stack[-4] = v207;
    v207 = stack[-3];
    v207 = qcdr(v207);
    stack[-1] = v207;
    v207 = stack[-1];
    if (v207 == nil) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v207 = stack[-1];
    v207 = qcdr(v207);
    stack[-3] = v207;
    v207 = stack[-3];
    if (v207 == nil) goto v10;
    v207 = stack[-4];
    stack[-3] = v207;
    goto v71;

v71:
    v207 = stack[-1];
    if (v207 == nil) goto v70;
    v349 = stack[-2];
    v207 = stack[-1];
    v519 = qcar(v207);
    v207 = stack[-3];
    v207 = qcar(v207);
    v207 = Lapply2(nil, 3, v349, v519, v207);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-5];
    if (!(v207 == nil)) goto v70;
    v207 = stack[-1];
    stack[-3] = v207;
    v207 = stack[-1];
    v207 = qcdr(v207);
    stack[-1] = v207;
    goto v71;

v70:
    v207 = stack[-1];
    if (v207 == nil) { Lisp_Object res = stack[-4]; popv(6); return onevalue(res); }
    v207 = stack[-4];
    stack[-1] = v207;
    v207 = stack[-1];
    v207 = qcdr(v207);
    v207 = qcdr(v207);
    stack[-3] = v207;
    goto v143;

v143:
    v207 = stack[-3];
    if (v207 == nil) goto v121;
    v207 = stack[-3];
    v207 = qcdr(v207);
    if (v207 == nil) goto v121;
    v207 = stack[-1];
    v207 = qcdr(v207);
    stack[-1] = v207;
    v207 = stack[-3];
    v207 = qcdr(v207);
    v207 = qcdr(v207);
    stack[-3] = v207;
    goto v143;

v121:
    v207 = stack[-1];
    stack[-3] = v207;
    v207 = stack[-1];
    v207 = qcdr(v207);
    stack[-1] = v207;
    v519 = stack[-3];
    v207 = nil;
    v207 = Lrplacd(nil, v519, v207);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-5];
    v519 = stack[-4];
    v207 = stack[-2];
    v207 = CC_stableKsortip(env, v519, v207);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-5];
    stack[-4] = v207;
    v519 = stack[-1];
    v207 = stack[-2];
    v207 = CC_stableKsortip(env, v519, v207);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-5];
    stack[-1] = v207;
    v207 = nil;
    v207 = ncons(v207);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-5];
    stack[0] = v207;
    stack[-3] = v207;
    goto v214;

v214:
    v207 = stack[-4];
    if (v207 == nil) goto v76;
    v207 = stack[-1];
    if (v207 == nil) goto v76;
    v349 = stack[-2];
    v207 = stack[-1];
    v519 = qcar(v207);
    v207 = stack[-4];
    v207 = qcar(v207);
    v207 = Lapply2(nil, 3, v349, v519, v207);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-5];
    if (v207 == nil) goto v467;
    v519 = stack[0];
    v207 = stack[-1];
    v207 = Lrplacd(nil, v519, v207);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-5];
    v207 = stack[-1];
    stack[0] = v207;
    v207 = stack[-1];
    v207 = qcdr(v207);
    stack[-1] = v207;
    goto v214;

v467:
    v519 = stack[0];
    v207 = stack[-4];
    v207 = Lrplacd(nil, v519, v207);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-5];
    v207 = stack[-4];
    stack[0] = v207;
    v207 = stack[-4];
    v207 = qcdr(v207);
    stack[-4] = v207;
    goto v214;

v76:
    v207 = stack[-4];
    if (v207 == nil) goto v200;
    v207 = stack[-4];
    stack[-1] = v207;
    goto v200;

v200:
    v519 = stack[0];
    v207 = stack[-1];
    v207 = Lrplacd(nil, v519, v207);
    nil = C_nil;
    if (exception_pending()) goto v361;
    v207 = stack[-3];
    v207 = qcdr(v207);
    { popv(6); return onevalue(v207); }

v10:
    v349 = stack[-2];
    v207 = stack[-1];
    v519 = qcar(v207);
    v207 = stack[-4];
    v207 = qcar(v207);
    v207 = Lapply2(nil, 3, v349, v519, v207);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-5];
    if (v207 == nil) { Lisp_Object res = stack[-4]; popv(6); return onevalue(res); }
    v207 = stack[-4];
    v207 = qcar(v207);
    stack[-3] = v207;
    v519 = stack[-4];
    v207 = stack[-1];
    v207 = qcar(v207);
    v207 = Lrplaca(nil, v519, v207);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-5];
    v519 = stack[-1];
    v207 = stack[-3];
    v207 = Lrplaca(nil, v519, v207);
    nil = C_nil;
    if (exception_pending()) goto v361;
    { Lisp_Object res = stack[-4]; popv(6); return onevalue(res); }
/* error exit handlers */
v361:
    popv(6);
    return nil;
}



/* Code for letscalar */

static Lisp_Object MS_CDECL CC_letscalar(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v16,
                         Lisp_Object v63, Lisp_Object v9,
                         Lisp_Object v3, Lisp_Object v4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v487, v417, v488, v518, v549, v440;
    Lisp_Object fn;
    argcheck(nargs, 6, "letscalar");
    if (stack >= stacklimit)
    {
        push6(v4,v3,v9,v63,v16,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop6(v0,v16,v63,v9,v3,v4);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v4;
    stack[-3] = v3;
    stack[-4] = v9;
    stack[-5] = v63;
    stack[-6] = v16;
    stack[-7] = v0;
/* end of prologue */
    v487 = stack[-4];
    if (!consp(v487)) goto v1;
    v487 = stack[-4];
    v487 = qcar(v487);
    if (symbolp(v487)) goto v21;
    v417 = stack[-7];
    v487 = elt(env, 1); /* hold */
    {
        popv(10);
        fn = elt(env, 23); /* errpri2 */
        return (*qfn2(fn))(qenv(fn), v417, v487);
    }

v21:
    v487 = stack[-4];
    v417 = qcar(v487);
    v487 = elt(env, 2); /* df */
    if (v417 == v487) goto v48;
    v487 = stack[-4];
    v487 = qcar(v487);
    fn = elt(env, 24); /* getrtype */
    v487 = (*qfn1(fn))(qenv(fn), v487);
    nil = C_nil;
    if (exception_pending()) goto v515;
    env = stack[-9];
    if (v487 == nil) goto v62;
    v487 = stack[-4];
    fn = elt(env, 25); /* reval */
    v518 = (*qfn1(fn))(qenv(fn), v487);
    nil = C_nil;
    if (exception_pending()) goto v515;
    env = stack[-9];
    v488 = stack[-6];
    v417 = stack[-5];
    v487 = stack[-3];
    {
        popv(10);
        fn = elt(env, 26); /* let2 */
        return (*qfnn(fn))(qenv(fn), 4, v518, v488, v417, v487);
    }

v62:
    v487 = stack[-4];
    v417 = qcar(v487);
    v487 = elt(env, 3); /* simpfn */
    v487 = get(v417, v487);
    env = stack[-9];
    if (!(v487 == nil)) goto v431;
    v487 = stack[-4];
    v417 = qcar(v487);
    v487 = elt(env, 4); /* "operator" */
    fn = elt(env, 27); /* redmsg */
    v487 = (*qfn2(fn))(qenv(fn), v417, v487);
    nil = C_nil;
    if (exception_pending()) goto v515;
    env = stack[-9];
    v487 = stack[-4];
    v487 = qcar(v487);
    fn = elt(env, 28); /* mkop */
    v487 = (*qfn1(fn))(qenv(fn), v487);
    nil = C_nil;
    if (exception_pending()) goto v515;
    env = stack[-9];
    v549 = stack[-7];
    v518 = stack[-6];
    v488 = stack[-5];
    v417 = stack[-3];
    v487 = stack[-2];
    {
        popv(10);
        fn = elt(env, 29); /* let3 */
        return (*qfnn(fn))(qenv(fn), 5, v549, v518, v488, v417, v487);
    }

v431:
    v417 = stack[-4];
    v487 = elt(env, 17); /* expt */
    if (!consp(v417)) goto v159;
    v417 = qcar(v417);
    if (!(v417 == v487)) goto v159;
    v487 = stack[-4];
    v487 = qcdr(v487);
    v487 = qcdr(v487);
    v417 = qcar(v487);
    v487 = qvalue(elt(env, 18)); /* frlis!* */
    v487 = Lmemq(nil, v417, v487);
    if (v487 == nil) goto v159;
    stack[-8] = stack[-7];
    stack[-1] = stack[-6];
    stack[0] = stack[-5];
    v417 = stack[-4];
    v487 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 30); /* to */
    v417 = (*qfn2(fn))(qenv(fn), v417, v487);
    nil = C_nil;
    if (exception_pending()) goto v515;
    env = stack[-9];
    v487 = (Lisp_Object)17; /* 1 */
    v487 = cons(v417, v487);
    nil = C_nil;
    if (exception_pending()) goto v515;
    env = stack[-9];
    v417 = ncons(v487);
    nil = C_nil;
    if (exception_pending()) goto v515;
    env = stack[-9];
    v487 = (Lisp_Object)17; /* 1 */
    v488 = cons(v417, v487);
    nil = C_nil;
    if (exception_pending()) goto v515;
    env = stack[-9];
    v417 = stack[-3];
    v487 = stack[-2];
    fn = elt(env, 31); /* letexprn */
    v487 = (*qfnn(fn))(qenv(fn), 6, stack[-8], stack[-1], stack[0], v488, v417, v487);
    nil = C_nil;
    if (exception_pending()) goto v515;
    env = stack[-9];
    goto v455;

v455:
    v487 = lisp_true;
    stack[0] = qvalue(elt(env, 22)); /* !*precise */
    qvalue(elt(env, 22)) = v487; /* !*precise */
    v487 = stack[-4];
    fn = elt(env, 32); /* simp0 */
    v487 = (*qfn1(fn))(qenv(fn), v487);
    nil = C_nil;
    if (exception_pending()) goto v332;
    env = stack[-9];
    stack[-4] = v487;
    qvalue(elt(env, 22)) = stack[0]; /* !*precise */
    v487 = stack[-4];
    v487 = qcar(v487);
    if (!consp(v487)) goto v480;
    v487 = stack[-4];
    v487 = qcar(v487);
    v487 = qcar(v487);
    if (!consp(v487)) goto v480;
    v440 = stack[-7];
    v549 = stack[-6];
    v518 = stack[-5];
    v488 = stack[-4];
    v417 = stack[-3];
    v487 = stack[-2];
    {
        popv(10);
        fn = elt(env, 31); /* letexprn */
        return (*qfnn(fn))(qenv(fn), 6, v440, v549, v518, v488, v417, v487);
    }

v480:
    v487 = stack[-7];
    {
        popv(10);
        fn = elt(env, 33); /* errpri1 */
        return (*qfn1(fn))(qenv(fn), v487);
    }

v159:
    v417 = stack[-4];
    v487 = elt(env, 19); /* sqrt */
    if (!consp(v417)) goto v455;
    v417 = qcar(v417);
    if (!(v417 == v487)) goto v455;
    v487 = lisp_true;
    qvalue(elt(env, 20)) = v487; /* !*sqrtrulep */
    v488 = elt(env, 17); /* expt */
    v487 = stack[-4];
    v487 = qcdr(v487);
    v417 = qcar(v487);
    v487 = elt(env, 21); /* (quotient 1 2) */
    v518 = list3(v488, v417, v487);
    nil = C_nil;
    if (exception_pending()) goto v515;
    env = stack[-9];
    v488 = stack[-6];
    v417 = stack[-5];
    v487 = stack[-3];
    fn = elt(env, 26); /* let2 */
    v487 = (*qfnn(fn))(qenv(fn), 4, v518, v488, v417, v487);
    nil = C_nil;
    if (exception_pending()) goto v515;
    env = stack[-9];
    goto v455;

v48:
    v549 = stack[-7];
    v518 = stack[-6];
    v488 = stack[-5];
    v417 = stack[-4];
    v487 = stack[-3];
    fn = elt(env, 34); /* letdf */
    v487 = (*qfnn(fn))(qenv(fn), 5, v549, v518, v488, v417, v487);
    nil = C_nil;
    if (exception_pending()) goto v515;
    env = stack[-9];
    if (v487 == nil) goto v431;
    v487 = nil;
    { popv(10); return onevalue(v487); }

v1:
    v487 = stack[-3];
    if (!(v487 == nil)) goto v431;
    v487 = stack[-5];
    if (!(v487 == nil)) goto v431;
    v417 = stack[-4];
    v487 = elt(env, 5); /* avalue */
    v487 = Lremprop(nil, v417, v487);
    env = stack[-9];
    v417 = stack[-4];
    v487 = elt(env, 6); /* rtype */
    v487 = Lremprop(nil, v417, v487);
    env = stack[-9];
    v487 = stack[-4];
    v417 = ncons(v487);
    nil = C_nil;
    if (exception_pending()) goto v515;
    env = stack[-9];
    v487 = elt(env, 7); /* antisymmetric */
    v487 = Lremflag(nil, v417, v487);
    env = stack[-9];
    v417 = stack[-4];
    v487 = elt(env, 8); /* infix */
    v487 = Lremprop(nil, v417, v487);
    env = stack[-9];
    v417 = stack[-4];
    v487 = elt(env, 9); /* kvalue */
    v487 = Lremprop(nil, v417, v487);
    env = stack[-9];
    v487 = stack[-4];
    v417 = ncons(v487);
    nil = C_nil;
    if (exception_pending()) goto v515;
    env = stack[-9];
    v487 = elt(env, 10); /* linear */
    v487 = Lremflag(nil, v417, v487);
    env = stack[-9];
    v487 = stack[-4];
    v417 = ncons(v487);
    nil = C_nil;
    if (exception_pending()) goto v515;
    env = stack[-9];
    v487 = elt(env, 11); /* noncom */
    v487 = Lremflag(nil, v417, v487);
    env = stack[-9];
    v417 = stack[-4];
    v487 = elt(env, 12); /* op */
    v487 = Lremprop(nil, v417, v487);
    env = stack[-9];
    v417 = stack[-4];
    v487 = elt(env, 13); /* opmtch */
    v487 = Lremprop(nil, v417, v487);
    env = stack[-9];
    v417 = stack[-4];
    v487 = elt(env, 3); /* simpfn */
    v487 = Lremprop(nil, v417, v487);
    env = stack[-9];
    v487 = stack[-4];
    v417 = ncons(v487);
    nil = C_nil;
    if (exception_pending()) goto v515;
    env = stack[-9];
    v487 = elt(env, 14); /* symmetric */
    v487 = Lremflag(nil, v417, v487);
    env = stack[-9];
    v417 = stack[-4];
    v487 = qvalue(elt(env, 15)); /* wtl!* */
    fn = elt(env, 35); /* delasc */
    v487 = (*qfn2(fn))(qenv(fn), v417, v487);
    nil = C_nil;
    if (exception_pending()) goto v515;
    env = stack[-9];
    qvalue(elt(env, 15)) = v487; /* wtl!* */
    v417 = stack[-4];
    v487 = elt(env, 16); /* opfn */
    v487 = Lflagp(nil, v417, v487);
    env = stack[-9];
    if (v487 == nil) goto v432;
    v487 = stack[-4];
    v417 = ncons(v487);
    nil = C_nil;
    if (exception_pending()) goto v515;
    env = stack[-9];
    v487 = elt(env, 16); /* opfn */
    v487 = Lremflag(nil, v417, v487);
    env = stack[-9];
    v487 = stack[-4];
    v487 = Lremd(nil, v487);
    nil = C_nil;
    if (exception_pending()) goto v515;
    env = stack[-9];
    goto v432;

v432:
    fn = elt(env, 36); /* rmsubs */
    v487 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v515;
    v487 = nil;
    { popv(10); return onevalue(v487); }
/* error exit handlers */
v332:
    env = stack[-9];
    qvalue(elt(env, 22)) = stack[0]; /* !*precise */
    popv(10);
    return nil;
v515:
    popv(10);
    return nil;
}



/* Code for mkprec */

static Lisp_Object MS_CDECL CC_mkprec(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v135, v119, v98;
    argcheck(nargs, 0, "mkprec");
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
    v119 = qvalue(elt(env, 1)); /* fixedpreclis!* */
    v135 = qvalue(elt(env, 2)); /* preclis!* */
    v135 = Lappend(nil, v119, v135);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-4];
    stack[-3] = v135;
    v135 = (Lisp_Object)17; /* 1 */
    stack[-2] = v135;
    goto v12;

v12:
    v135 = stack[-3];
    if (v135 == nil) goto v27;
    v135 = stack[-3];
    v98 = qcar(v135);
    v119 = elt(env, 3); /* infix */
    v135 = stack[-2];
    v135 = Lputprop(nil, 3, v98, v119, v135);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-4];
    v135 = stack[-3];
    stack[-1] = qcar(v135);
    stack[0] = elt(env, 4); /* op */
    v119 = stack[-2];
    v135 = stack[-2];
    v135 = list2(v119, v135);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-4];
    v135 = ncons(v135);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-4];
    v135 = Lputprop(nil, 3, stack[-1], stack[0], v135);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-4];
    v135 = stack[-3];
    v119 = qcar(v135);
    v135 = elt(env, 5); /* unary */
    v135 = get(v119, v135);
    env = stack[-4];
    stack[0] = v135;
    if (v135 == nil) goto v206;
    v98 = stack[0];
    v119 = elt(env, 3); /* infix */
    v135 = stack[-2];
    v135 = Lputprop(nil, 3, v98, v119, v135);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-4];
    goto v206;

v206:
    v135 = stack[0];
    if (v135 == nil) goto v59;
    v119 = stack[0];
    v135 = elt(env, 6); /* nary */
    v135 = Lflagp(nil, v119, v135);
    env = stack[-4];
    if (!(v135 == nil)) goto v59;
    stack[-1] = stack[0];
    stack[0] = elt(env, 4); /* op */
    v119 = nil;
    v135 = stack[-2];
    v135 = list2(v119, v135);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-4];
    v135 = Lputprop(nil, 3, stack[-1], stack[0], v135);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-4];
    goto v59;

v59:
    v135 = stack[-3];
    v135 = qcdr(v135);
    stack[-3] = v135;
    v135 = stack[-2];
    v135 = add1(v135);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-4];
    stack[-2] = v135;
    goto v12;

v27:
    v135 = nil;
    { popv(5); return onevalue(v135); }
/* error exit handlers */
v139:
    popv(5);
    return nil;
}



/* Code for fluid */

static Lisp_Object CC_fluid(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v23, v30;
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
    v23 = stack[0];
    if (v23 == nil) goto v45;
    v23 = stack[0];
    v23 = qcar(v23);
    v23 = Lmake_special(nil, v23);
    nil = C_nil;
    if (exception_pending()) goto v10;
    env = stack[-1];
    v23 = stack[0];
    v23 = qcar(v23);
    v23 = Lboundp(nil, v23);
    nil = C_nil;
    if (exception_pending()) goto v10;
    env = stack[-1];
    if (!(v23 == nil)) goto v13;
    v23 = stack[0];
    v30 = qcar(v23);
    v23 = nil;
    v23 = Lset(nil, v30, v23);
    nil = C_nil;
    if (exception_pending()) goto v10;
    env = stack[-1];
    goto v13;

v13:
    v23 = stack[0];
    v23 = qcdr(v23);
    stack[0] = v23;
    goto v3;

v45:
    v23 = nil;
    { popv(2); return onevalue(v23); }
/* error exit handlers */
v10:
    popv(2);
    return nil;
}



setup_type const u08_setup[] =
{
    {"token-number",            CC_tokenKnumber,too_many_1,    wrong_no_1},
    {"assgnpri",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_assgnpri},
    {"getsetvars",              CC_getsetvars,  too_many_1,    wrong_no_1},
    {"add2resultbuf",           too_few_2,      CC_add2resultbuf,wrong_no_2},
    {"listp",                   CC_listp,       too_many_1,    wrong_no_1},
    {"form",                    CC_form,        too_many_1,    wrong_no_1},
    {"mchkminus",               too_few_2,      CC_mchkminus,  wrong_no_2},
    {"let3",                    wrong_no_na,    wrong_no_nb,   (n_args *)CC_let3},
    {"rlis",                    wrong_no_na,    wrong_no_nb,   (n_args *)CC_rlis},
    {"sprgen",                  CC_sprgen,      too_many_1,    wrong_no_1},
    {"forstat",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_forstat},
    {"sfp",                     CC_sfp,         too_many_1,    wrong_no_1},
    {"powers0",                 too_few_2,      CC_powers0,    wrong_no_2},
    {"brace",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_brace},
    {"evload",                  CC_evload,      too_many_1,    wrong_no_1},
    {"module",                  CC_module,      too_many_1,    wrong_no_1},
    {"mkstrng",                 CC_mkstrng,     too_many_1,    wrong_no_1},
    {"eqexpr",                  CC_eqexpr,      too_many_1,    wrong_no_1},
    {"diffp",                   too_few_2,      CC_diffp,      wrong_no_2},
    {"put-avalue",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_putKavalue},
    {"spur0i",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_spur0i},
    {"extmult",                 too_few_2,      CC_extmult,    wrong_no_2},
    {"setk",                    too_few_2,      CC_setk,       wrong_no_2},
    {"domainvalchk",            too_few_2,      CC_domainvalchk,wrong_no_2},
    {"stable-sortip",           too_few_2,      CC_stableKsortip,wrong_no_2},
    {"letscalar",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_letscalar},
    {"mkprec",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_mkprec},
    {"fluid",                   CC_fluid,       too_many_1,    wrong_no_1},
    {NULL, (one_args *)"u08", (two_args *)"14691 6602699 1444407", 0}
};

/* end of generated code */
