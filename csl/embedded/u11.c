
/* $destdir/generated-c\u11.c Machine generated C code */

/* Signature: 00000000 21-Jun-2009 */

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
#ifdef HAVE_STDINT_H
#include <stdint.h>
#endif
#ifndef HAVE_UINT32_T
#ifdef  HAVE_U_INT32_T
typedef u_int32_t uint32_t;
#define HAVE_UINT32_T 1
#endif
#endif
#ifndef HAVE_UINT64_T
#ifdef  HAVE_U_INT64_T
typedef u_int64_t uint64_t;
#define HAVE_UINT64_T 1
#endif
#endif
#ifndef HAVE_UINTPTR_T
#ifdef  HAVE_U_INTPTR_T
typedef u_intptr_t uintptr_t;
#define HAVE_UINTPTR_T 1
#endif
#endif
#if !defined HAVE_INT32_T && defined SIZEOF_INT && (SIZEOF_INT == 4)
typedef int int32_t;
#define HAVE_INT32_T 1
#endif
#if !defined HAVE_UINT32_T && defined SIZEOF_INT && (SIZEOF_INT == 4)
typedef unsigned int uint32_t;
#define HAVE_UINT32_T 1
#endif
#if !defined HAVE_INT32_T && defined SIZEOF_SHORT_INT && (SIZEOF_SHORT_INT == 4)
typedef short int int32_t;
#define HAVE_INT32_T 1
#endif
#if !defined HAVE_UINT32_T && defined SIZEOF_SHORT_INT && (SIZEOF_SHORT_INT == 4)
typedef unsigned short int uint32_t;
#define HAVE_UINT32_T 1
#endif
#if !defined HAVE_INT64_T && defined SIZEOF_LONG && (SIZEOF_LONG == 8)
typedef long int64_t;
#define HAVE_INT64_T 1
#endif
#if !defined HAVE_UINT64_T && defined SIZEOF_LONG && (SIZEOF_LONG == 8)
typedef unsigned long uint64_t;
#define HAVE_UINT64_T 1
#endif
#if !defined HAVE_INT64_T && defined SIZEOF_LONG_LONG && (SIZEOF_LONG_LONG == 8)
typedef long long int64_t;
#define HAVE_INT64_T 1
#endif
#if !defined HAVE_UINT64_T && defined SIZEOF_LONG_LONG && (SIZEOF_LONG_LONG == 8)
typedef unsigned long long uint64_t;
#define HAVE_UINT64_T 1
#endif
#if !defined HAVE_INTPTR_T && defined SIZEOF_VOID_P && (SIZEOF_VOID_P == 4) && defined HAVE_INT32_T
typedef int32_t intptr_t;
#define HAVE_INTPTR_T 1
#endif
#if !defined HAVE_INTPTR_T && defined SIZEOF_VOID_P && (SIZEOF_VOID_P == 8) && defined HAVE_INT64_T
typedef int64_t intptr_t;
#define HAVE_INTPTR_T 1
#endif
#if !defined HAVE_UINTPTR_T && defined SIZEOF_VOID_P && (SIZEOF_VOID_P == 4) && defined HAVE_UINT32_T
typedef uint32_t uintptr_t;
#define HAVE_UINTPTR_T 1
#endif
#if !defined HAVE_UINTPTR_T && defined SIZEOF_VOID_P && (SIZEOF_VOID_P == 8) && defined HAVE_UINT64_T
typedef uint64_t uintptr_t;
#define HAVE_UINTPTR_T 1
#endif
#endif 
#ifndef header_tags_h
#define header_tags_h 1
#ifndef HAVE_INT32_T
#error This system needs a 32-bit integer type.
#endif
#define SIXTY_FOUR_BIT (sizeof(intptr_t) == 8)
typedef int                 CSLbool;
#define YES                 1
#define NO                  0
#ifndef PAGE_BITS
#  define PAGE_BITS             22
#endif 
#define PAGE_POWER_OF_TWO       (((uint32_t)1) << PAGE_BITS)
#define CSL_PAGE_SIZE           (PAGE_POWER_OF_TWO - 256U)
#ifndef MAX_HEAPSIZE
#  define MAX_HEAPSIZE       (SIXTY_FOUR_BIT ? 20480 : 2048)
#endif 
#ifndef MAX_BPSSIZE
#  define MAX_BPSSIZE           64
#endif 
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
#define LONGEST_LEGAL_FILENAME 1024
#define FP_WORD_ORDER 0x01
#define FP_BYTE_ORDER 0x02
#define FP_MASK       0xff
typedef intptr_t Lisp_Object;
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
#define fixnum_of_int(x)    ((Lisp_Object)(TAG_FIXNUM + (((int32_t)(x)) << 4)))
#ifdef SIGNED_SHIFTS_ARE_LOGICAL
#define int_of_fixnum(x)    ((int32_t)(((int32_t)(x)) < 0 ?           \
                             (((int32_t)(x))>>4) | (-0x10000000) :  \
                             (((int32_t)(x))>>4)))
#else 
#define int_of_fixnum(x)    ((int32_t)(((int32_t)(x)) >> 4))
#endif 
#define GC_BIT_I        8               
#define GC_BIT_H        8               
#define GC_BIT_P        ((intptr_t)~((~(uintptr_t)0) >> 1))
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
extern Cons_Cell *memory_reference(intptr_t p);
extern char *cmemory_reference(intptr_t p);
extern void identify_page_types();
extern long int car_counter;
extern unsigned long int car_low, car_high;
#define qcar(p) (memory_reference((intptr_t)p)->car)
#define qcdr(p) (memory_reference((intptr_t)p)->cdr)
#else 
#define qcar(p) (((Cons_Cell *) (p))->car)
#define qcdr(p) (((Cons_Cell *) (p))->cdr)
#endif 
#define car32(p) (*(int32_t *)(p))
typedef Lisp_Object Special_Form(Lisp_Object, Lisp_Object);
typedef Lisp_Object one_args(Lisp_Object, Lisp_Object);
typedef Lisp_Object two_args(Lisp_Object, Lisp_Object, Lisp_Object);
typedef Lisp_Object MS_CDECL n_args(Lisp_Object, int, ...);
typedef uintptr_t Header;
#define header_mask          0x3f0
#define type_of_header(h)    (((unsigned int)(h)) & header_mask)
#define length_of_header(h)  (((uint32_t)(h)) >> 10)
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
#define is_ratio(n) \
    (type_of_header(numhdr(n)) == TYPE_RATNUM)
#define is_complex(n) \
    (type_of_header(numhdr(n)) == TYPE_COMPLEX_NUM)
#endif 
#define is_bignum_header(h) (type_of_header(h) == TYPE_BIGNUM)
#define is_bignum(n) is_bignum_header(numhdr(n))
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
#else 
#define vechdr(v)  (*(Header *)((char *)(v) - TAG_VECTOR))
#define elt(v, n)  (*(Lisp_Object *)((char *)(v) + \
                               (CELL-TAG_VECTOR) + \
                               (((intptr_t)(n))<<ADDRESS_SHIFT)))
#define celt(v, n) (*((char *)(v) + (CELL-TAG_VECTOR)+((intptr_t)(n))))
#define ucelt(v, n) (*((unsigned char *)(v) + (CELL-TAG_VECTOR)+((intptr_t)(n))))
#define scelt(v, n) (*((signed char *)(v) + (CELL-TAG_VECTOR)+((intptr_t)(n))))
#endif 
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
#define ielt32(v, n)  (*(int32_t *)((char *)(v) + \
                           (CELL-TAG_VECTOR)+(((intptr_t)(n))<<2)))
#define felt(v, n)  (*(float *)((char *)(v) + \
                           (CELL-TAG_VECTOR)+(((intptr_t)(n))<<2)))
#define delt(v, n)  (*(double *)((char *)(v) + \
                           (2*CELL-TAG_VECTOR)+(((intptr_t)(n))<<3)))
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
#define font_of_char(n)  (((int32_t)(n) >> 24) & 0xff)
#define bits_of_char(n)  (((int32_t)(n) >> 16) & 0xff)
#ifdef Kanji
#define code_of_char(n)  (((int32_t)(n) >>  8) & 0xffff)
#else
#define code_of_char(n)  ((char)(((int32_t)(n) >>  8) & 0xff))
#endif
#define pack_char(bits, font, code)                                \
    ((Lisp_Object)((((uint32_t)(font)) << 24) |                  \
    (((uint32_t)(bits)) << 16) | (((uint32_t)(code)) << 8) | TAG_CHAR))
    
#define CHAR_EOF pack_char(0, 0xff, 4)
 
#define data_of_bps(v) \
  ((char *)(doubleword_align_up((intptr_t) \
             bps_pages[((uint32_t)(v))>>(PAGE_BITS+6)]) + \
            (((v) >> 6) & (PAGE_POWER_OF_TWO-4))))
typedef int32_t junk;      
typedef intptr_t junkxx;    
typedef struct Symbol_Head
{
    Header header;      
    Lisp_Object value;  
    Lisp_Object env;    
    intptr_t function1;     
    intptr_t function2;     
    intptr_t functionn;     
    Lisp_Object pname;   
    Lisp_Object plist;   
    Lisp_Object fastgets;
    uintptr_t count;     
#ifdef COMMON
    Lisp_Object package;
#endif 
} Symbol_Head;
#define MAX_FASTGET_SIZE  63
#ifdef COMMON
#define symalign(n) (SIXTY_FOUR_BIT ? \
     ((char *)((intptr_t)(n) & ~(intptr_t)TAG_SYMBOL)) : \
     (n)
#else
#define symalign(n) (n)
#endif
#ifndef MEMORY_TRACE
#define qheader(p)     (*(Header *)     symalign((char *)(p) - TAG_SYMBOL))
#define qvalue(p)      (*(Lisp_Object *)symalign((char *)(p) + (CELL - TAG_SYMBOL)))
#define qenv(p)        (*(Lisp_Object *)symalign((char *)(p) + (2*CELL - TAG_SYMBOL)))
#define qfn1(p)        ((one_args *) *((intptr_t *)symalign((char *)(p) + \
                                         (3*CELL - TAG_SYMBOL))))
#define qfn2(p)        ((two_args *) *((intptr_t *)symalign((char *)(p) + \
                                         (4*CELL - TAG_SYMBOL))))
#define qfnn(p)        ((n_args *)   *((intptr_t *)symalign((char *)(p) + \
                                         (5*CELL - TAG_SYMBOL))))
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
#else 
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
#endif 
#ifdef COMMON
typedef union Float_union
{
    float f;
    int32_t i;
} Float_union;
#endif
typedef struct Big_Number
{
    Header h;
    uint32_t d[1];  
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
#endif 
#define SIZEOF_DOUBLE_FLOAT     16
#define double_float_addr(v)    ((double *)((char *)(v) + \
                                   (8-TAG_BOXFLOAT)))
#define double_float_val(v)     (*(double *)((char *)(v) + \
                                   (8-TAG_BOXFLOAT)))
#ifdef COMMON
#define SIZEOF_LONG_FLOAT       16
#define long_float_addr(v)      ((double *)((char *)(v) + \
                                   (8-TAG_BOXFLOAT)))
#define long_float_val(v)       (*(double *)((char *)(v) + \
                                   (8-TAG_BOXFLOAT)))
#endif
#define doubleword_align_up(n) ((Lisp_Object)(((intptr_t)(n) + 7) & (-8)))
#define doubleword_align_down(n) ((Lisp_Object)((intptr_t)(n) & (-8)))
#define quadword_align_up(n) ((Lisp_Object)(((intptr_t)(n) + 15) & (-16)))
#define quadword_align_down(n) ((Lisp_Object)((intptr_t)(n) & (-16)))
#define UNWIND_NULL       0x0         
#define UNWIND_GO         0x1         
#define UNWIND_RETURN     0x2         
#define UNWIND_THROW      0x3         
#define UNWIND_RESTART    0x4         
#define UNWIND_RESOURCE   0x5         
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
extern int32_t mpi_rank,mpi_size;
#endif
#define D do { \
          char *fffff = strrchr(__FILE__, '/'); \
          if (fffff == NULL) fffff = strrchr(__FILE__, '\\'); \
          if (fffff == NULL) fffff = __FILE__; else fffff++; \
          fprintf(stderr, "Line %d File %s\n", __LINE__, fffff); \
          fflush(stderr); \
          } while (0)
#define DS(s) do { \
          char *fffff = strrchr(__FILE__, '/'); \
          if (fffff == NULL) fffff = strrchr(__FILE__, '\\'); \
          if (fffff == NULL) fffff = __FILE__; else fffff++; \
          fprintf(stderr, "Line %d File %s: %s\n", __LINE__, fffff, (s)); \
          fflush(stderr); \
          } while (0)
#define DX(s) do { \
          char *fffff = strrchr(__FILE__, '/'); \
          if (fffff == NULL) fffff = strrchr(__FILE__, '\\'); \
          if (fffff == NULL) fffff = __FILE__; else fffff++; \
          fprintf(stderr, "Line %d File %s: %llx\n", __LINE__, fffff, \
                          (long long unsigned)(s)); \
          fflush(stderr); \
          } while (0)
extern void **pages,
            **heap_pages, **vheap_pages,
            **bps_pages, **native_pages;
extern void **new_heap_pages, **new_vheap_pages,
            **new_bps_pages, **new_native_pages;
#ifdef CONSERVATIVE
#define PAGE_TYPE_CONS   0
#define PAGE_TYPE_VECTOR 1
#define PAGE_TYPE_BPS    2
#define PAGE_TYPE_NATIVE 3
typedef struct page_map_t
{
    void *start;
    void *end;
    int type;
} page_map_t;
#endif
extern int pages_count,
           heap_pages_count, vheap_pages_count,
           bps_pages_count, native_pages_count;
extern int new_heap_pages_count, new_vheap_pages_count,
           new_bps_pages_count, new_native_pages_count;
extern int native_pages_changed;
extern int32_t native_fringe;
extern Lisp_Object *nilsegment, *stacksegment;
extern Lisp_Object *stackbase;
extern int32_t stack_segsize;  
extern Lisp_Object *C_stack;
#define stack C_stack
#ifdef CONSERVATIVE
extern Lisp_Object *C_stackbase, *C_stacktop;
#endif
#ifdef MEMORY_TRACE
#define push(a)         do { \
                          *++stack = (a); \
                          memory_reference((intptr_t)stack); } while (0)
#define push2(a,b)      do { \
                          *++stack = (a); \
                          memory_reference((intptr_t)stack); \
                          *++stack = (b); \
                          memory_reference((intptr_t)stack); } while (0)
#define push3(a,b,c)    do { \
                          *++stack = (a); \
                          memory_reference((intptr_t)stack); \
                          *++stack = (b); \
                          memory_reference((intptr_t)stack); \
                          *++stack = (c); \
                          memory_reference((intptr_t)stack); } while (0)
#define push4(a,b,c,d)  do { \
                          *++stack = (a); \
                          memory_reference((intptr_t)stack); \
                          *++stack = (b); \
                          memory_reference((intptr_t)stack); \
                          *++stack = (c); \
                          memory_reference((intptr_t)stack); \
                          *++stack = (d); \
                          memory_reference((intptr_t)stack); } while (0)
#define push5(a,b,c,d,e)do { \
                          *++stack = (a); \
                          memory_reference((intptr_t)stack); \
                          *++stack = (b); \
                          memory_reference((intptr_t)stack); \
                          *++stack = (c); \
                          memory_reference((intptr_t)stack); \
                          *++stack = (d); \
                          memory_reference((intptr_t)stack); \
                          *++stack = (e); \
                          memory_reference((intptr_t)stack); } while (0)
#define push6(a,b,c,d,e,f) do {push3(a,b,c); push3(d,e,f); } while (0)
#define my_pop()        (memory_reference((int32_t)stack), (*stack--))
#define pop(a)          { memory_reference((intptr_t)stack); (a) = *stack--; }
#define pop2(a,b)       { memory_reference((intptr_t)stack); (a) = *stack--; memory_reference((intptr_t)stack); (b) = *stack--; }
#define pop3(a,b,c)     { memory_reference((intptr_t)stack); (a) = *stack--; memory_reference((intptr_t)stack); (b) = *stack--; memory_reference((intptr_t)stack); (c) = *stack--; }
#define pop4(a,b,c,d)   { memory_reference((intptr_t)stack); (a) = *stack--; memory_reference((intptr_t)stack); (b) = *stack--; memory_reference((intptr_t)stack); (c) = *stack--; \
                          memory_reference((intptr_t)stack); (d) = *stack--; }
#define pop5(a,b,c,d,e) { memory_reference((intptr_t)stack); (a) = *stack--; memory_reference((intptr_t)stack); (b) = *stack--; memory_reference((intptr_t)stack); (c) = *stack--; \
                          memory_reference((intptr_t)stack); (d) = *stack--; memory_reference((intptr_t)stack); (e) = *stack--; }
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
extern int32_t software_ticks, countdown;
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
#ifdef COMMON
#define BASE ((Lisp_Object *)nil)
#else
#define BASE (SIXTY_FOUR_BIT ? ((Lisp_Object *)(nil+4)): ((Lisp_Object *)nil))
#endif
#ifdef NILSEG_EXTERNS
#define nil_as_base
extern uint32_t byteflip;
extern Lisp_Object codefringe;
extern Lisp_Object volatile codelimit;
extern Lisp_Object * volatile stacklimit;
extern Lisp_Object fringe;
extern Lisp_Object volatile heaplimit;
extern Lisp_Object volatile vheaplimit;
extern Lisp_Object vfringe;
extern int32_t nwork;
extern int32_t exit_reason;
extern int32_t exit_count;
extern uint32_t gensym_ser, print_precision, miscflags;
extern int32_t current_modulus, fastget_size, package_bits;
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
extern Lisp_Object gchook, resources, callstack;
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
#define byteflip              (*(uint32_t *)&BASE[12])
#define codefringe            BASE[13]
#define codelimit             (*(Lisp_Object volatile *)&BASE[14])
extern Lisp_Object * volatile stacklimit;
#define fringe                BASE[18]
#define heaplimit             (*(Lisp_Object volatile *)&BASE[19])
#define vheaplimit            (*(Lisp_Object volatile *)&BASE[20])
#define vfringe               BASE[21]
#define miscflags             (*(uint32_t *)&BASE[22])
#define nwork                 (*(int32_t *)&BASE[24])
#define exit_reason           (*(int32_t *)&BASE[25])
#define exit_count            (*(int32_t *)&BASE[26])
#define gensym_ser            (*(uint32_t *)&BASE[27])
#define print_precision       (*(uint32_t *)&BASE[28])
#define current_modulus       (*(int32_t *)&BASE[29])
#define fastget_size          (*(int32_t *)&BASE[30])
#define package_bits          (*(int32_t *)&BASE[31])
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
#define gchook                BASE[153]
#define resources             BASE[154]
#define callstack             BASE[155]
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
extern void report_file(const char *s);
extern CSLbool undefine_this_one[MAX_SYMBOLS_TO_DEFINE];
extern CSLbool always_noisy;
extern int number_of_input_files,
    number_of_symbols_to_define,
    number_of_fasl_paths,
    init_flags;
extern int native_code_tag;
extern char *standard_directory;
extern int gc_number;
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
    uint32_t chk;   
    int status;     
    int nativedir;  
} Ihandle;
extern int32_t compression_worth_while;
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
extern int32_t code_up_fn1(one_args *e);
extern int32_t code_up_fn2(two_args *e);
extern int32_t code_up_fnn(n_args *e);
extern int32_t code_up_io(void *e);
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
extern intptr_t memory_base, memory_size;
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
#define IOPEN_OUT       0
#define IOPEN_UNCHECKED 1
#define IOPEN_CHECKED   2
extern CSLbool Iopen(char *name, int len, int dirn, char *expanded_name);
extern CSLbool Iopen_from_stdin(void), Iopen_to_stdout(void);
extern CSLbool IopenRoot(char *expanded_name, int hard, int sixtyfour);
extern CSLbool Iwriterootp(char *expanded);
extern CSLbool Iopen_help(int32_t offset);
extern CSLbool Iopen_banner(int code);
extern CSLbool Imodulep(char *name, int len, char *datestamp, int32_t *size,
                                 char *expanded_name);
extern CSLbool Icopy(char *name, int len);
extern CSLbool Idelete(char *name, int len);
extern CSLbool IcloseInput(int check_checksum);
extern CSLbool IcloseOutput(int write_checksum);
extern CSLbool Ifinished(void);
extern int  Igetc(void);
extern int32_t Iread(void *buff, int32_t size);
extern CSLbool Iputc(int ch);
extern CSLbool Iwrite(void *buff, int32_t size);
extern long int Ioutsize(void);
extern char *CSLtmpnam(char *suffix, int32_t suffixlen);
extern int Cmkdir(char *s);
extern char *look_in_lisp_variable(char *o, int prefix);
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
extern int         primep(int32_t);
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
extern uint32_t  Crand(void);
extern Lisp_Object Cremainder(Lisp_Object a, Lisp_Object b);
extern void        Csrand(uint32_t a, uint32_t b);
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
extern Lisp_Object getvector(int tag, int type, int32_t length);
extern Lisp_Object getvector_init(int32_t n, Lisp_Object v);
extern Lisp_Object getcodevector(int type, int32_t size);
extern uint32_t  hash_lisp_string(Lisp_Object s);
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
extern Lisp_Object make_one_word_bignum(int32_t n);
extern Lisp_Object make_package(Lisp_Object name);
extern Lisp_Object make_string(const char *b);
extern Lisp_Object make_nstring(char *b, int32_t n);
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
extern char *get_string_data(Lisp_Object a, char *why, int32_t *len);
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
                           int stg_class, intptr_t size);
extern CSLbool do_not_kill_native_code;
extern void        set_fns(Lisp_Object sym, one_args *f1,
                                            two_args *f2, n_args *fn);
extern void        setup(int restartp, double storesize);
extern Lisp_Object simplify_string(Lisp_Object s);
extern CSLbool        stringp(Lisp_Object a);
extern Lisp_Object times2(Lisp_Object a, Lisp_Object b);
extern int32_t       thirty_two_bits(Lisp_Object a);
#ifdef HAVE_INT64_T
extern int64_t       sixty_four_bits(Lisp_Object a);
#endif
#if defined DEMO_MODE || defined DEMO_BUILD
extern void give_up();
#endif
#ifdef DEMO_BUILD
extern int32_t demo_key1, demo_key2;
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
extern uint32_t Imultiply(uint32_t *rlow, uint32_t a,
                            uint32_t b, uint32_t c);
#endif
#ifndef IDIVIDE
extern uint32_t Idivide(uint32_t *qp, uint32_t a,
                          uint32_t b, uint32_t c);
extern uint32_t Idiv10_9(uint32_t *qp, uint32_t a, uint32_t b);
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
    uint32_t c1;
    uint32_t c2;
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
extern Lisp_Object resource_exceeded();
extern int time_base,  space_base,  io_base,  errors_base;
extern int time_now,   space_now,   io_now,   errors_now;
extern int time_limit, space_limit, io_limit, errors_limit;
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
#define top_bit_set(n)     (((int32_t)(n)) < 0)
#define top_bit(n)         (((uint32_t)(n)) >> 31)
#define set_top_bit(n)     ((n) | (uint32_t)0x80000000)
#define clear_top_bit(n)   ((n) & 0x7fffffff)
#define signed_overflow(n) top_bit_set((n) ^ (((int32_t)(n))<<1))
#ifdef HAVE_UINT64_T
#define IMULTIPLY 1      
#define Dmultiply(hi, lo, a, b, c)                          \
 do { uint64_t r64 = (uint64_t)(a) * (uint64_t)(b) +  \
                     (uint32_t)(c);                       \
      (lo) = 0x7fffffffu & (uint32_t)r64;                 \
      (hi) = (uint32_t)(r64 >> 31); } while (0)
#define IDIVIDE   1
#define Ddivide(r, q, a, b, c)                                      \
 do { uint64_t r64 = (((uint64_t)(a)) << 31) | (uint64_t)(b); \
      uint64_t c64 = (uint64_t)(uint32_t)(c);                 \
      q = (uint32_t)(r64 / c64);                                  \
      r = (uint32_t)(r64 % c64); } while (0)
#define Ddiv10_9(r, q, a, b) Ddivide(r, q, a, b, 1000000000u)
#else
#define Dmultiply(hi, lo, a, b, c) ((hi) = Imultiply(&(lo), (a), (b), (c)))
#define Ddivide(r, q, a, b, c) ((r) = Idivide(&(q), (a), (b), (c)))
#define Ddiv10_9(r, q, a, b)   ((r) = Idiv10_9(&(q), (a), (b)))
#endif
#define fix_mask (-0x08000000)
#define fixnum_minusp(a) ((int32_t)(a) < 0)
#define bignum_minusp(a) \
    ((int32_t)bignum_digits(a)[((bignum_length(a)-CELL)/4)-1]<0)
extern Lisp_Object negateb(Lisp_Object);
extern Lisp_Object copyb(Lisp_Object);
extern Lisp_Object negate(Lisp_Object);
extern Lisp_Object plus2(Lisp_Object a, Lisp_Object b);
extern Lisp_Object difference2(Lisp_Object a, Lisp_Object b);
extern Lisp_Object times2(Lisp_Object a, Lisp_Object b);
extern Lisp_Object quot2(Lisp_Object a, Lisp_Object b);
extern Lisp_Object CLquot2(Lisp_Object a, Lisp_Object b);
extern Lisp_Object quotbn(Lisp_Object a, int32_t n);
extern Lisp_Object quotbn1(Lisp_Object a, int32_t n);
extern Lisp_Object quotbb(Lisp_Object a, Lisp_Object b);
extern Lisp_Object Cremainder(Lisp_Object a, Lisp_Object b);
extern Lisp_Object rembi(Lisp_Object a, Lisp_Object b);
extern Lisp_Object rembb(Lisp_Object a, Lisp_Object b);
extern Lisp_Object shrink_bignum(Lisp_Object a, int32_t lena);
extern Lisp_Object modulus(Lisp_Object a, Lisp_Object b);
extern Lisp_Object rational(Lisp_Object a);
extern Lisp_Object rationalize(Lisp_Object a);
extern Lisp_Object lcm(Lisp_Object a, Lisp_Object b);
extern Lisp_Object lengthen_by_one_bit(Lisp_Object a, int32_t msd);
extern CSLbool numeq2(Lisp_Object a, Lisp_Object b);
extern CSLbool zerop(Lisp_Object a);
extern CSLbool onep(Lisp_Object a);
extern CSLbool minusp(Lisp_Object a);
extern CSLbool plusp(Lisp_Object a);
extern CSLbool lesspbd(Lisp_Object a, double b);
extern CSLbool lessprd(Lisp_Object a, double b);
extern CSLbool lesspdb(double a, Lisp_Object b);
extern CSLbool lesspdr(double a, Lisp_Object b);
extern Lisp_Object make_one_word_bignum(int32_t n);
extern Lisp_Object make_two_word_bignum(int32_t a, uint32_t b);
extern Lisp_Object make_n_word_bignum(int32_t a1, uint32_t a2,
                                      uint32_t a3, int32_t n);
extern Lisp_Object make_sfloat(double d);
extern double float_of_integer(Lisp_Object a);
extern Lisp_Object add1(Lisp_Object p);
extern Lisp_Object sub1(Lisp_Object p);
extern Lisp_Object integerp(Lisp_Object p);
extern double float_of_number(Lisp_Object a);
extern Lisp_Object make_boxfloat(double a, int32_t type);
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
extern Lisp_Object Lresource_limit2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
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
extern Lisp_Object MS_CDECL Lresource_limitn(Lisp_Object env, int nargs, ...);
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


/* Code for evaluate!-in!-order */

static Lisp_Object CC_evaluateKinKorder(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v67, v68, v56, v54;
    Lisp_Object fn;
    CSL_IGNORE(nil);
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
    v67 = stack[-1];
    if (!consp(v67)) goto v5;
    v67 = stack[-1];
    v67 = qcar(v67);
    if (!consp(v67)) goto v5;
    v67 = stack[-1];
    v67 = qcar(v67);
    v67 = qcar(v67);
    v68 = qcar(v67);
    v67 = stack[0];
    v67 = qcar(v67);
    v67 = qcar(v67);
    if (equal(v68, v67)) goto v36;
    v67 = stack[0];
    v67 = qcdr(v67);
    stack[0] = v67;
    goto v4;

v36:
    v67 = stack[-1];
    v67 = qcar(v67);
    v68 = qcdr(v67);
    v67 = stack[0];
    v67 = qcdr(v67);
    v54 = CC_evaluateKinKorder(env, v68, v67);
    nil = C_nil;
    if (exception_pending()) goto v70;
    env = stack[-2];
    v67 = stack[-1];
    v67 = qcar(v67);
    v67 = qcar(v67);
    v56 = qcdr(v67);
    v67 = stack[-1];
    v68 = qcdr(v67);
    v67 = stack[0];
    {
        popv(3);
        fn = elt(env, 1); /* horner!-rule */
        return (*qfnn(fn))(qenv(fn), 4, v54, v56, v68, v67);
    }

v5:
    v67 = stack[-1];
    {
        popv(3);
        fn = elt(env, 2); /* !*d2n */
        return (*qfn1(fn))(qenv(fn), v67);
    }
/* error exit handlers */
v70:
    popv(3);
    return nil;
}



/* Code for rdprep1 */

static Lisp_Object CC_rdprep1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v28, v38;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v38 = v0;
/* end of prologue */
    v28 = v38;
    v28 = qcdr(v28);
    if (!consp(v28)) return onevalue(v38);
    v28 = qvalue(elt(env, 1)); /* !:bprec!: */
    {
        fn = elt(env, 2); /* round!:mt */
        return (*qfn2(fn))(qenv(fn), v38, v28);
    }
}



/* Code for fullcopy */

static Lisp_Object CC_fullcopy(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v112, v120;
    Lisp_Object fn;
    CSL_IGNORE(nil);
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
    stack[0] = nil;
    goto v4;

v4:
    v112 = stack[-5];
    v112 = Lconsp(nil, v112);
    env = stack[-7];
    if (v112 == nil) goto v6;
    v112 = stack[-5];
    v112 = qcar(v112);
    v120 = CC_fullcopy(env, v112);
    nil = C_nil;
    if (exception_pending()) goto v83;
    env = stack[-7];
    v112 = stack[0];
    v112 = cons(v120, v112);
    nil = C_nil;
    if (exception_pending()) goto v83;
    env = stack[-7];
    stack[0] = v112;
    v112 = stack[-5];
    v112 = qcdr(v112);
    stack[-5] = v112;
    goto v4;

v6:
    v112 = stack[-5];
    v112 = Lsimple_vectorp(nil, v112);
    env = stack[-7];
    if (v112 == nil) goto v85;
    stack[-6] = stack[0];
    v112 = stack[-5];
    v112 = Lupbv(nil, v112);
    nil = C_nil;
    if (exception_pending()) goto v83;
    env = stack[-7];
    stack[-3] = v112;
    v112 = stack[-3];
    v112 = Lmkvect(nil, v112);
    nil = C_nil;
    if (exception_pending()) goto v83;
    env = stack[-7];
    stack[-4] = v112;
    v112 = (Lisp_Object)1; /* 0 */
    stack[-2] = v112;
    goto v206;

v206:
    v120 = stack[-3];
    v112 = stack[-2];
    v112 = difference2(v120, v112);
    nil = C_nil;
    if (exception_pending()) goto v83;
    env = stack[-7];
    v112 = Lminusp(nil, v112);
    env = stack[-7];
    if (v112 == nil) goto v67;
    v112 = stack[-4];
    {
        Lisp_Object v84 = stack[-6];
        popv(8);
        fn = elt(env, 1); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v84, v112);
    }

v67:
    stack[-1] = stack[-4];
    stack[0] = stack[-2];
    v120 = stack[-5];
    v112 = stack[-2];
    v112 = *(Lisp_Object *)((char *)v120 + (CELL-TAG_VECTOR) + ((int32_t)v112/(16/CELL)));
    v112 = CC_fullcopy(env, v112);
    nil = C_nil;
    if (exception_pending()) goto v83;
    env = stack[-7];
    *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)stack[0]/(16/CELL))) = v112;
    v112 = stack[-2];
    v112 = add1(v112);
    nil = C_nil;
    if (exception_pending()) goto v83;
    env = stack[-7];
    stack[-2] = v112;
    goto v206;

v85:
    v120 = stack[0];
    v112 = stack[-5];
    {
        popv(8);
        fn = elt(env, 1); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v120, v112);
    }
/* error exit handlers */
v83:
    popv(8);
    return nil;
}



/* Code for dm!-difference */

static Lisp_Object CC_dmKdifference(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v2, v25;
    Lisp_Object fn;
    CSL_IGNORE(nil);
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
    v2 = v0;
/* end of prologue */
    fn = elt(env, 1); /* zero2nil */
    v25 = (*qfn1(fn))(qenv(fn), v2);
    nil = C_nil;
    if (exception_pending()) goto v24;
    env = stack[-1];
    v2 = stack[0];
    fn = elt(env, 2); /* !:difference */
    v2 = (*qfn2(fn))(qenv(fn), v25, v2);
    nil = C_nil;
    if (exception_pending()) goto v24;
    env = stack[-1];
    {
        popv(2);
        fn = elt(env, 3); /* nil2zero */
        return (*qfn1(fn))(qenv(fn), v2);
    }
/* error exit handlers */
v24:
    popv(2);
    return nil;
}



/* Code for copy_mat */

static Lisp_Object CC_copy_mat(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v99, v10;
    Lisp_Object fn;
    CSL_IGNORE(nil);
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
    v99 = Lconsp(nil, v99);
    env = stack[-2];
    if (v99 == nil) goto v18;
    v99 = stack[0];
    v99 = qcar(v99);
    v10 = CC_copy_mat(env, v99);
    nil = C_nil;
    if (exception_pending()) goto v46;
    env = stack[-2];
    v99 = stack[-1];
    v99 = cons(v10, v99);
    nil = C_nil;
    if (exception_pending()) goto v46;
    env = stack[-2];
    stack[-1] = v99;
    v99 = stack[0];
    v99 = qcdr(v99);
    stack[0] = v99;
    goto v4;

v18:
    v10 = stack[-1];
    v99 = stack[0];
    {
        popv(3);
        fn = elt(env, 1); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v10, v99);
    }
/* error exit handlers */
v46:
    popv(3);
    return nil;
}



/* Code for vevtdeg */

static Lisp_Object CC_vevtdeg(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v48, v33, v51;
    CSL_IGNORE(nil);
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
    v33 = nil;
    goto v12;

v12:
    v48 = stack[0];
    if (v48 == nil) goto v45;
    v48 = stack[0];
    v48 = qcar(v48);
    v48 = cons(v48, v33);
    nil = C_nil;
    if (exception_pending()) goto v49;
    env = stack[-1];
    v33 = v48;
    v48 = stack[0];
    v48 = qcdr(v48);
    stack[0] = v48;
    goto v12;

v45:
    v48 = (Lisp_Object)1; /* 0 */
    goto v5;

v5:
    v51 = v33;
    if (v51 == nil) { popv(2); return onevalue(v48); }
    v51 = v33;
    v51 = qcar(v51);
    v48 = (Lisp_Object)(int32_t)((int32_t)v51 + (int32_t)v48 - TAG_FIXNUM);
    v33 = qcdr(v33);
    goto v5;
/* error exit handlers */
v49:
    popv(2);
    return nil;
}



/* Code for xdiv */

static Lisp_Object CC_xdiv(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v48, v33;
    Lisp_Object fn;
    CSL_IGNORE(nil);
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
    stack[-2] = stack[-1];
    v48 = (Lisp_Object)17; /* 1 */
    v48 = ncons(v48);
    nil = C_nil;
    if (exception_pending()) goto v50;
    env = stack[-3];
    if (equal(stack[-2], v48)) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v33 = stack[-1];
    v48 = stack[0];
    fn = elt(env, 1); /* sublistp */
    v48 = (*qfn2(fn))(qenv(fn), v33, v48);
    nil = C_nil;
    if (exception_pending()) goto v50;
    env = stack[-3];
    if (v48 == nil) goto v26;
    v33 = stack[0];
    v48 = stack[-1];
    fn = elt(env, 2); /* listdiff */
    v48 = (*qfn2(fn))(qenv(fn), v33, v48);
    nil = C_nil;
    if (exception_pending()) goto v50;
    stack[0] = v48;
    if (!(v48 == nil)) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v48 = (Lisp_Object)17; /* 1 */
    popv(4);
    return ncons(v48);

v26:
    v48 = nil;
    { popv(4); return onevalue(v48); }
/* error exit handlers */
v50:
    popv(4);
    return nil;
}



/* Code for !:times */

static Lisp_Object CC_Ttimes(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v31, v32, v37;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v32 = v16;
    v37 = v0;
/* end of prologue */
    v31 = v37;
    if (v31 == nil) goto v4;
    v31 = v32;
    if (v31 == nil) goto v4;
    v31 = v37;
    if (!(!consp(v31))) goto v30;
    v31 = v32;
    if (!(!consp(v31))) goto v30;
    v31 = v37;
    return times2(v31, v32);

v30:
    v31 = elt(env, 1); /* times */
    {
        fn = elt(env, 2); /* dcombine */
        return (*qfnn(fn))(qenv(fn), 3, v37, v32, v31);
    }

v4:
    v31 = nil;
    return onevalue(v31);
}



/* Code for physopsim!* */

static Lisp_Object CC_physopsimH(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v2;
    Lisp_Object fn;
    CSL_IGNORE(nil);
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
    v2 = stack[0];
    fn = elt(env, 1); /* !*physopp!* */
    v2 = (*qfn1(fn))(qenv(fn), v2);
    nil = C_nil;
    if (exception_pending()) goto v13;
    env = stack[-1];
    if (v2 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v2 = stack[0];
    {
        popv(2);
        fn = elt(env, 2); /* physopsm!* */
        return (*qfn1(fn))(qenv(fn), v2);
    }
/* error exit handlers */
v13:
    popv(2);
    return nil;
}



/* Code for mo_sum */

static Lisp_Object CC_mo_sum(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v43, v29;
    Lisp_Object fn;
    CSL_IGNORE(nil);
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
    v43 = v16;
    v29 = v0;
/* end of prologue */
    v29 = qcar(v29);
    v43 = qcar(v43);
    fn = elt(env, 1); /* mo!=sum */
    v43 = (*qfn2(fn))(qenv(fn), v29, v43);
    nil = C_nil;
    if (exception_pending()) goto v19;
    env = stack[-2];
    stack[-1] = v43;
    v43 = stack[-1];
    fn = elt(env, 2); /* mo!=shorten */
    stack[0] = (*qfn1(fn))(qenv(fn), v43);
    nil = C_nil;
    if (exception_pending()) goto v19;
    env = stack[-2];
    v43 = stack[-1];
    fn = elt(env, 3); /* mo!=deglist */
    v43 = (*qfn1(fn))(qenv(fn), v43);
    nil = C_nil;
    if (exception_pending()) goto v19;
    {
        Lisp_Object v20 = stack[0];
        popv(3);
        return cons(v20, v43);
    }
/* error exit handlers */
v19:
    popv(3);
    return nil;
}



/* Code for pv_add */

static Lisp_Object CC_pv_add(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v148, v213, v77;
    CSL_IGNORE(nil);
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
    v148 = stack[-1];
    if (v148 == nil) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v148 = stack[0];
    if (v148 == nil) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    stack[-2] = nil;
    goto v44;

v44:
    v148 = stack[-1];
    if (!(v148 == nil)) goto v15;
    v148 = stack[0];
    if (!(v148 == nil)) goto v15;
    v148 = stack[-2];
        popv(4);
        return Lnreverse(nil, v148);

v15:
    v148 = stack[-1];
    if (v148 == nil) goto v99;
    v148 = stack[0];
    if (v148 == nil) goto v99;
    v148 = stack[-1];
    v148 = qcar(v148);
    v213 = qcdr(v148);
    v148 = stack[0];
    v148 = qcar(v148);
    v148 = qcdr(v148);
    if (!(equal(v213, v148))) goto v99;
    v148 = stack[-1];
    v148 = qcar(v148);
    v213 = qcar(v148);
    v148 = stack[0];
    v148 = qcar(v148);
    v148 = qcar(v148);
    v148 = plus2(v213, v148);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-3];
    v77 = v148;
    v213 = v77;
    v148 = (Lisp_Object)1; /* 0 */
    if (v213 == v148) goto v68;
    v148 = stack[-1];
    v148 = qcar(v148);
    v213 = qcdr(v148);
    v148 = stack[-2];
    v148 = acons(v77, v213, v148);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-3];
    stack[-2] = v148;
    goto v68;

v68:
    v148 = stack[-1];
    v148 = qcdr(v148);
    stack[-1] = v148;
    v148 = stack[0];
    v148 = qcdr(v148);
    stack[0] = v148;
    goto v44;

v99:
    v148 = stack[-1];
    if (v148 == nil) goto v112;
    v148 = stack[0];
    if (!(v148 == nil)) goto v112;

v117:
    v148 = stack[-1];
    v213 = qcar(v148);
    v148 = stack[-2];
    v148 = cons(v213, v148);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-3];
    stack[-2] = v148;
    v148 = stack[-1];
    v148 = qcdr(v148);
    stack[-1] = v148;
    goto v44;

v112:
    v148 = stack[-1];
    if (v148 == nil) goto v137;
    v148 = stack[0];
    if (v148 == nil) goto v137;
    v148 = stack[-1];
    v148 = qcar(v148);
    v213 = qcdr(v148);
    v148 = stack[0];
    v148 = qcar(v148);
    v148 = qcdr(v148);
    v148 = (Lisp_Object)greaterp2(v213, v148);
    nil = C_nil;
    if (exception_pending()) goto v149;
    v148 = v148 ? lisp_true : nil;
    env = stack[-3];
    if (!(v148 == nil)) goto v117;

v137:
    v148 = stack[0];
    v213 = qcar(v148);
    v148 = stack[-2];
    v148 = cons(v213, v148);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-3];
    stack[-2] = v148;
    v148 = stack[0];
    v148 = qcdr(v148);
    stack[0] = v148;
    goto v44;
/* error exit handlers */
v149:
    popv(4);
    return nil;
}



/* Code for copy */

static Lisp_Object CC_copy(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v30, v99;
    Lisp_Object fn;
    CSL_IGNORE(nil);
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
    v30 = stack[0];
    if (!consp(v30)) goto v1;
    v30 = stack[0];
    v30 = qcar(v30);
    v99 = CC_copy(env, v30);
    nil = C_nil;
    if (exception_pending()) goto v14;
    env = stack[-2];
    v30 = stack[-1];
    v30 = cons(v99, v30);
    nil = C_nil;
    if (exception_pending()) goto v14;
    env = stack[-2];
    stack[-1] = v30;
    v30 = stack[0];
    v30 = qcdr(v30);
    stack[0] = v30;
    goto v4;

v1:
    v99 = stack[-1];
    v30 = stack[0];
    {
        popv(3);
        fn = elt(env, 1); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v99, v30);
    }
/* error exit handlers */
v14:
    popv(3);
    return nil;
}



/* Code for indent!* */

static Lisp_Object CC_indentH(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v53, v14;
    CSL_IGNORE(nil);
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
    v14 = stack[0];
    v53 = lisp_true;
    if (!(equal(v14, v53))) goto v4;
    v14 = qvalue(elt(env, 1)); /* indent */
    v53 = qvalue(elt(env, 2)); /* ind */
    v53 = plus2(v14, v53);
    nil = C_nil;
    if (exception_pending()) goto v31;
    env = stack[-1];
    qvalue(elt(env, 1)) = v53; /* indent */
    goto v4;

v4:
    v53 = stack[0];
    if (!(v53 == nil)) goto v43;
    v14 = qvalue(elt(env, 1)); /* indent */
    v53 = qvalue(elt(env, 2)); /* ind */
    v53 = difference2(v14, v53);
    nil = C_nil;
    if (exception_pending()) goto v31;
    env = stack[-1];
    qvalue(elt(env, 1)) = v53; /* indent */
    goto v43;

v43:
    v53 = nil;
    { popv(2); return onevalue(v53); }
/* error exit handlers */
v31:
    popv(2);
    return nil;
}



/* Code for multi_isarb_compl */

static Lisp_Object CC_multi_isarb_compl(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v29;
    Lisp_Object fn;
    CSL_IGNORE(nil);
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
    v29 = stack[0];
    v29 = Lconsp(nil, v29);
    env = stack[-1];
    if (v29 == nil) goto v4;
    v29 = stack[0];
    if (v29 == nil) goto v4;
    v29 = stack[0];
    v29 = qcar(v29);
    fn = elt(env, 1); /* isarb_compl */
    v29 = (*qfn1(fn))(qenv(fn), v29);
    nil = C_nil;
    if (exception_pending()) goto v18;
    env = stack[-1];
    v29 = stack[0];
    v29 = qcdr(v29);
    v29 = CC_multi_isarb_compl(env, v29);
    nil = C_nil;
    if (exception_pending()) goto v18;
    goto v4;

v4:
    v29 = nil;
    { popv(2); return onevalue(v29); }
/* error exit handlers */
v18:
    popv(2);
    return nil;
}



/* Code for equal!: */

static Lisp_Object CC_equalT(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v39, v40;
    Lisp_Object fn;
    CSL_IGNORE(nil);
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
    v39 = stack[-1];
    v39 = qcdr(v39);
    v39 = qcar(v39);
    v39 = (Lisp_Object)zerop(v39);
    v39 = v39 ? lisp_true : nil;
    env = stack[-3];
    if (v39 == nil) goto v5;
    v39 = stack[0];
    v39 = qcdr(v39);
    v39 = qcar(v39);
    v39 = (Lisp_Object)zerop(v39);
    v39 = v39 ? lisp_true : nil;
    env = stack[-3];
    goto v45;

v45:
    if (!(v39 == nil)) { popv(4); return onevalue(v39); }
    v39 = stack[-1];
    fn = elt(env, 1); /* csl_normbf */
    v39 = (*qfn1(fn))(qenv(fn), v39);
    nil = C_nil;
    if (exception_pending()) goto v100;
    env = stack[-3];
    stack[-1] = v39;
    v39 = qcdr(v39);
    stack[-2] = qcdr(v39);
    v39 = stack[0];
    fn = elt(env, 1); /* csl_normbf */
    v39 = (*qfn1(fn))(qenv(fn), v39);
    nil = C_nil;
    if (exception_pending()) goto v100;
    stack[0] = v39;
    v39 = qcdr(v39);
    v39 = qcdr(v39);
    if (equal(stack[-2], v39)) goto v37;
    v39 = nil;
    { popv(4); return onevalue(v39); }

v37:
    v39 = stack[-1];
    v39 = qcdr(v39);
    v40 = qcar(v39);
    v39 = stack[0];
    v39 = qcdr(v39);
    v39 = qcar(v39);
    v39 = (equal(v40, v39) ? lisp_true : nil);
    { popv(4); return onevalue(v39); }

v5:
    v39 = nil;
    goto v45;
/* error exit handlers */
v100:
    popv(4);
    return nil;
}



/* Code for evlexcomp */

static Lisp_Object CC_evlexcomp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v49, v50;
    CSL_IGNORE(nil);
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
    v49 = stack[-1];
    if (v49 == nil) goto v5;
    v49 = stack[0];
    if (v49 == nil) goto v1;
    v49 = stack[-1];
    v50 = qcar(v49);
    v49 = stack[0];
    v49 = qcar(v49);
    v49 = Leqn(nil, v50, v49);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-2];
    if (v49 == nil) goto v99;
    v49 = stack[-1];
    v49 = qcdr(v49);
    stack[-1] = v49;
    v49 = stack[0];
    v49 = qcdr(v49);
    stack[0] = v49;
    goto v4;

v99:
    v49 = stack[-1];
    v50 = qcar(v49);
    v49 = stack[0];
    v49 = qcar(v49);
    if (((int32_t)(v50)) > ((int32_t)(v49))) goto v23;
    v49 = (Lisp_Object)-15; /* -1 */
    { popv(3); return onevalue(v49); }

v23:
    v49 = (Lisp_Object)17; /* 1 */
    { popv(3); return onevalue(v49); }

v1:
    v49 = elt(env, 1); /* (0) */
    stack[0] = v49;
    goto v4;

v5:
    v49 = (Lisp_Object)1; /* 0 */
    { popv(3); return onevalue(v49); }
/* error exit handlers */
v35:
    popv(3);
    return nil;
}



/* Code for chundexp */

static Lisp_Object CC_chundexp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v122, v58;
    CSL_IGNORE(nil);
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
    v122 = stack[-1];
    v122 = Lexplodec(nil, v122);
    nil = C_nil;
    if (exception_pending()) goto v59;
    env = stack[-3];
    stack[-1] = v122;
    v122 = stack[-1];
    stack[-2] = v122;
    v58 = stack[-1];
    v122 = elt(env, 1); /* !_ */
    if (!consp(v58)) goto v4;
    v58 = qcar(v58);
    if (!(v58 == v122)) goto v4;
    v122 = stack[-1];
    v122 = qcdr(v122);
    if (v122 == nil) goto v4;
    v58 = elt(env, 2); /* !\ */
    v122 = stack[-1];
    v122 = cons(v58, v122);
    nil = C_nil;
    if (exception_pending()) goto v59;
    env = stack[-3];
    stack[-1] = v122;
    goto v4;

v4:
    v122 = stack[-2];
    v122 = qcdr(v122);
    if (v122 == nil) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v122 = stack[-2];
    v122 = qcdr(v122);
    v58 = qcar(v122);
    v122 = elt(env, 1); /* !_ */
    if (!(v58 == v122)) goto v37;
    stack[0] = stack[-2];
    v58 = elt(env, 2); /* !\ */
    v122 = stack[-2];
    v122 = qcdr(v122);
    v122 = cons(v58, v122);
    nil = C_nil;
    if (exception_pending()) goto v59;
    env = stack[-3];
    v122 = Lrplacd(nil, stack[0], v122);
    nil = C_nil;
    if (exception_pending()) goto v59;
    env = stack[-3];
    v122 = stack[-2];
    v122 = qcdr(v122);
    stack[-2] = v122;
    goto v37;

v37:
    v122 = stack[-2];
    v122 = qcdr(v122);
    stack[-2] = v122;
    goto v4;
/* error exit handlers */
v59:
    popv(4);
    return nil;
}



/* Code for delallasc */

static Lisp_Object CC_delallasc(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v32, v37, v36;
    Lisp_Object fn;
    CSL_IGNORE(nil);
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
    v36 = nil;
    goto v12;

v12:
    v32 = stack[0];
    if (v32 == nil) goto v6;
    v37 = stack[-1];
    v32 = stack[0];
    v32 = qcar(v32);
    v32 = qcar(v32);
    if (v37 == v32) goto v25;
    v32 = stack[0];
    v32 = qcar(v32);
    v37 = v36;
    v32 = cons(v32, v37);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[-2];
    v36 = v32;
    v32 = stack[0];
    v32 = qcdr(v32);
    stack[0] = v32;
    goto v12;

v25:
    v32 = stack[0];
    v32 = qcdr(v32);
    stack[0] = v32;
    goto v12;

v6:
    v32 = v36;
    {
        popv(3);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v32);
    }
/* error exit handlers */
v51:
    popv(3);
    return nil;
}



/* Code for !*physopp!* */

static Lisp_Object CC_HphysoppH(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v6;
    Lisp_Object fn;
    CSL_IGNORE(nil);
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
    v6 = stack[0];
    fn = elt(env, 1); /* physopp!* */
    v6 = (*qfn1(fn))(qenv(fn), v6);
    nil = C_nil;
    if (exception_pending()) goto v8;
    env = stack[-1];
    if (!(v6 == nil)) { popv(2); return onevalue(v6); }
    v6 = stack[0];
    {
        popv(2);
        fn = elt(env, 2); /* getphystype */
        return (*qfn1(fn))(qenv(fn), v6);
    }
/* error exit handlers */
v8:
    popv(2);
    return nil;
}



/* Code for nonzero!-length */

static Lisp_Object CC_nonzeroKlength(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v20, v21, v22;
    CSL_IGNORE(nil);
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
    v21 = v0;
/* end of prologue */

v3:
    v20 = v21;
    if (v20 == nil) goto v45;
    v20 = v21;
    v22 = qcar(v20);
    v20 = (Lisp_Object)1; /* 0 */
    if (v22 == v20) goto v8;
    v20 = v21;
    v20 = qcdr(v20);
    v20 = CC_nonzeroKlength(env, v20);
    errexit();
    return add1(v20);

v8:
    v20 = v21;
    v20 = qcdr(v20);
    v21 = v20;
    goto v3;

v45:
    v20 = (Lisp_Object)1; /* 0 */
    return onevalue(v20);
}



/* Code for mo_compare */

static Lisp_Object CC_mo_compare(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v69, v67, v68;
    Lisp_Object fn;
    CSL_IGNORE(nil);
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
    v69 = stack[-1];
    v67 = qcdr(v69);
    v69 = stack[0];
    v69 = qcdr(v69);
    fn = elt(env, 3); /* mo!=degcomp */
    v69 = (*qfn2(fn))(qenv(fn), v67, v69);
    nil = C_nil;
    if (exception_pending()) goto v87;
    env = stack[-2];
    v68 = v69;
    v67 = v68;
    v69 = (Lisp_Object)1; /* 0 */
    if (!(v67 == v69)) { popv(3); return onevalue(v68); }
    v69 = qvalue(elt(env, 1)); /* cali!=basering */
    fn = elt(env, 4); /* ring_tag */
    v67 = (*qfn1(fn))(qenv(fn), v69);
    nil = C_nil;
    if (exception_pending()) goto v87;
    env = stack[-2];
    v69 = elt(env, 2); /* revlex */
    if (v67 == v69) goto v32;
    v69 = stack[-1];
    v67 = qcar(v69);
    v69 = stack[0];
    v69 = qcar(v69);
    fn = elt(env, 5); /* mo!=lexcomp */
    v69 = (*qfn2(fn))(qenv(fn), v67, v69);
    nil = C_nil;
    if (exception_pending()) goto v87;
    goto v19;

v19:
    v68 = v69;
    { popv(3); return onevalue(v68); }

v32:
    v69 = stack[-1];
    v67 = qcar(v69);
    v69 = stack[0];
    v69 = qcar(v69);
    fn = elt(env, 6); /* mo!=revlexcomp */
    v69 = (*qfn2(fn))(qenv(fn), v67, v69);
    nil = C_nil;
    if (exception_pending()) goto v87;
    goto v19;
/* error exit handlers */
v87:
    popv(3);
    return nil;
}



/* Code for cdiv */

static Lisp_Object CC_cdiv(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v2, v25;
    Lisp_Object fn;
    CSL_IGNORE(nil);
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
    v2 = cons(v25, v2);
    nil = C_nil;
    if (exception_pending()) goto v13;
    env = stack[0];
    fn = elt(env, 1); /* resimp */
    v2 = (*qfn1(fn))(qenv(fn), v2);
    nil = C_nil;
    if (exception_pending()) goto v13;
    v2 = qcar(v2);
    { popv(1); return onevalue(v2); }
/* error exit handlers */
v13:
    popv(1);
    return nil;
}



/* Code for insert_pv */

static Lisp_Object CC_insert_pv(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v23, v30, v99;
    Lisp_Object fn;
    CSL_IGNORE(nil);
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
    v23 = v0;
/* end of prologue */
    v30 = v23;
    v23 = stack[0];
    fn = elt(env, 1); /* sieve_pv */
    v23 = (*qfn2(fn))(qenv(fn), v30, v23);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-1];
    v30 = v23;
    v23 = v30;
    if (v23 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v23 = v30;
    fn = elt(env, 2); /* pv_renorm */
    v99 = (*qfn1(fn))(qenv(fn), v23);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-1];
    v30 = stack[0];
    v23 = nil;
    {
        popv(2);
        fn = elt(env, 3); /* insert_pv1 */
        return (*qfnn(fn))(qenv(fn), 3, v99, v30, v23);
    }
/* error exit handlers */
v53:
    popv(2);
    return nil;
}



/* Code for general!-modular!-number */

static Lisp_Object CC_generalKmodularKnumber(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v30, v99;
    CSL_IGNORE(nil);
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
    v99 = stack[0];
    v30 = qvalue(elt(env, 1)); /* current!-modulus */
    v30 = Cremainder(v99, v30);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-1];
    stack[0] = v30;
    v99 = stack[0];
    v30 = (Lisp_Object)1; /* 0 */
    v30 = (Lisp_Object)lessp2(v99, v30);
    nil = C_nil;
    if (exception_pending()) goto v53;
    v30 = v30 ? lisp_true : nil;
    env = stack[-1];
    if (v30 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v99 = stack[0];
    v30 = qvalue(elt(env, 1)); /* current!-modulus */
    v30 = plus2(v99, v30);
    nil = C_nil;
    if (exception_pending()) goto v53;
    stack[0] = v30;
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
/* error exit handlers */
v53:
    popv(2);
    return nil;
}



/* Code for tayexp!-minusp */

static Lisp_Object CC_tayexpKminusp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v2, v25;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v25 = v0;
/* end of prologue */
    v2 = v25;
    if (!consp(v2)) goto v3;
    v2 = v25;
    {
        fn = elt(env, 1); /* rnminusp!: */
        return (*qfn1(fn))(qenv(fn), v2);
    }

v3:
    v2 = v25;
        return Lminusp(nil, v2);
}



/* Code for multi_isarb_int */

static Lisp_Object CC_multi_isarb_int(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v29;
    Lisp_Object fn;
    CSL_IGNORE(nil);
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
    v29 = stack[0];
    v29 = Lconsp(nil, v29);
    env = stack[-1];
    if (v29 == nil) goto v4;
    v29 = stack[0];
    if (v29 == nil) goto v4;
    v29 = stack[0];
    v29 = qcar(v29);
    fn = elt(env, 1); /* isarb_int */
    v29 = (*qfn1(fn))(qenv(fn), v29);
    nil = C_nil;
    if (exception_pending()) goto v18;
    env = stack[-1];
    v29 = stack[0];
    v29 = qcdr(v29);
    v29 = CC_multi_isarb_int(env, v29);
    nil = C_nil;
    if (exception_pending()) goto v18;
    goto v4;

v4:
    v29 = nil;
    { popv(2); return onevalue(v29); }
/* error exit handlers */
v18:
    popv(2);
    return nil;
}



/* Code for rd!:minus */

static Lisp_Object CC_rdTminus(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v47, v15;
    Lisp_Object fn;
    CSL_IGNORE(nil);
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



/* Code for on1 */

static Lisp_Object CC_on1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v7, v8;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v7 = v0;
/* end of prologue */
    v8 = v7;
    v7 = lisp_true;
    {
        fn = elt(env, 1); /* onoff */
        return (*qfn2(fn))(qenv(fn), v8, v7);
    }
}



/* Code for evtdeg */

static Lisp_Object CC_evtdeg(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v29, v17, v18;
    CSL_IGNORE(nil);
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v17 = v0;
/* end of prologue */
    v29 = (Lisp_Object)1; /* 0 */
    goto v12;

v12:
    v18 = v17;
    if (v18 == nil) return onevalue(v29);
    v18 = v17;
    v18 = qcar(v18);
    v29 = (Lisp_Object)(int32_t)((int32_t)v18 + (int32_t)v29 - TAG_FIXNUM);
    v17 = qcdr(v17);
    goto v12;
}



/* Code for groebsearchinlist */

static Lisp_Object CC_groebsearchinlist(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v22, v23;
    Lisp_Object fn;
    CSL_IGNORE(nil);
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
    v22 = stack[0];
    if (v22 == nil) goto v5;
    v22 = stack[0];
    v22 = qcar(v22);
    v22 = qcdr(v22);
    v23 = qcar(v22);
    v22 = stack[-1];
    fn = elt(env, 1); /* buchvevdivides!? */
    v22 = (*qfn2(fn))(qenv(fn), v23, v22);
    nil = C_nil;
    if (exception_pending()) goto v10;
    env = stack[-2];
    if (v22 == nil) goto v18;
    v22 = stack[0];
    v22 = qcar(v22);
    { popv(3); return onevalue(v22); }

v18:
    v22 = stack[0];
    v22 = qcdr(v22);
    stack[0] = v22;
    goto v4;

v5:
    v22 = nil;
    { popv(3); return onevalue(v22); }
/* error exit handlers */
v10:
    popv(3);
    return nil;
}



/* Code for find_item */

static Lisp_Object CC_find_item(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v52, v193;
    CSL_IGNORE(nil);
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
    v52 = stack[0];
    v52 = qcdr(v52);
    if (v52 == nil) goto v4;
    v193 = stack[-1];
    v52 = stack[0];
    v52 = qcdr(v52);
    v52 = qcar(v52);
    v52 = CC_find_item(env, v193, v52);
    nil = C_nil;
    if (exception_pending()) goto v39;
    env = stack[-2];
    if (!(v52 == nil)) { popv(3); return onevalue(v52); }
    v52 = stack[0];
    v193 = qcar(v52);
    v52 = stack[-1];
    if (equal(v193, v52)) goto v19;
    v52 = nil;
    goto v18;

v18:
    if (!(v52 == nil)) { popv(3); return onevalue(v52); }
    v193 = stack[-1];
    v52 = stack[0];
    v52 = qcdr(v52);
    v52 = qcdr(v52);
    stack[-1] = v193;
    stack[0] = v52;
    goto v11;

v19:
    v52 = stack[0];
    goto v18;

v4:
    v52 = nil;
    { popv(3); return onevalue(v52); }
/* error exit handlers */
v39:
    popv(3);
    return nil;
}



/* Code for csl_timbf */

static Lisp_Object CC_csl_timbf(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v70, v71, v101;
    Lisp_Object fn;
    CSL_IGNORE(nil);
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
    v70 = stack[-3];
    v70 = qcdr(v70);
    v71 = qcar(v70);
    v70 = stack[-2];
    v70 = qcdr(v70);
    v70 = qcar(v70);
    v70 = times2(v71, v70);
    nil = C_nil;
    if (exception_pending()) goto v65;
    env = stack[-5];
    v101 = v70;
    v71 = v101;
    v70 = (Lisp_Object)1; /* 0 */
    if (v71 == v70) goto v38;
    v71 = v101;
    v70 = qvalue(elt(env, 2)); /* !:bprec!: */
    fn = elt(env, 4); /* inorm */
    v70 = (*qfn2(fn))(qenv(fn), v71, v70);
    nil = C_nil;
    if (exception_pending()) goto v65;
    env = stack[-5];
    v101 = v70;
    stack[-4] = elt(env, 3); /* !:rd!: */
    v70 = v101;
    stack[-1] = qcar(v70);
    v70 = v101;
    stack[0] = qcdr(v70);
    v70 = stack[-3];
    v70 = qcdr(v70);
    v71 = qcdr(v70);
    v70 = stack[-2];
    v70 = qcdr(v70);
    v70 = qcdr(v70);
    v70 = plus2(v71, v70);
    nil = C_nil;
    if (exception_pending()) goto v65;
    env = stack[-5];
    v70 = plus2(stack[0], v70);
    nil = C_nil;
    if (exception_pending()) goto v65;
    {
        Lisp_Object v103 = stack[-4];
        Lisp_Object v59 = stack[-1];
        popv(6);
        return list2star(v103, v59, v70);
    }

v38:
    v70 = elt(env, 1); /* (!:rd!: 0 . 0) */
    { popv(6); return onevalue(v70); }
/* error exit handlers */
v65:
    popv(6);
    return nil;
}



/* Code for !:plus */

static Lisp_Object CC_Tplus(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v41, v64, v100;
    Lisp_Object fn;
    CSL_IGNORE(nil);
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
    v64 = v16;
    v100 = v0;
/* end of prologue */
    v41 = v100;
    if (v41 == nil) return onevalue(v64);
    v41 = v64;
    if (v41 == nil) return onevalue(v100);
    v41 = v100;
    if (!(!consp(v41))) goto v193;
    v41 = v64;
    if (!(!consp(v41))) goto v193;
    v41 = v100;
    v41 = plus2(v41, v64);
    errexit();
    v100 = v41;
    v64 = v100;
    v41 = (Lisp_Object)1; /* 0 */
    if (!(v64 == v41)) return onevalue(v100);
    v41 = nil;
    return onevalue(v41);

v193:
    v41 = elt(env, 1); /* plus */
    {
        fn = elt(env, 2); /* dcombine */
        return (*qfnn(fn))(qenv(fn), 3, v100, v64, v41);
    }
}



/* Code for freeofdepl */

static Lisp_Object MS_CDECL CC_freeofdepl(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v16,
                         Lisp_Object v63, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v36, v48;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "freeofdepl");
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
    v48 = stack[0];
    v36 = stack[-2];
    v36 = qcar(v36);
    v36 = qcdr(v36);
    fn = elt(env, 1); /* smember */
    v36 = (*qfn2(fn))(qenv(fn), v48, v36);
    nil = C_nil;
    if (exception_pending()) goto v49;
    env = stack[-3];
    if (v36 == nil) goto v46;
    v36 = stack[-2];
    v36 = qcar(v36);
    v48 = qcar(v36);
    v36 = stack[-1];
    fn = elt(env, 1); /* smember */
    v36 = (*qfn2(fn))(qenv(fn), v48, v36);
    nil = C_nil;
    if (exception_pending()) goto v49;
    env = stack[-3];
    if (v36 == nil) goto v46;
    v36 = nil;
    { popv(4); return onevalue(v36); }

v46:
    v36 = stack[-2];
    v36 = qcdr(v36);
    stack[-2] = v36;
    goto v12;

v6:
    v36 = lisp_true;
    { popv(4); return onevalue(v36); }
/* error exit handlers */
v49:
    popv(4);
    return nil;
}



/* Code for idlistp */

static Lisp_Object CC_idlistp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v15, v43;
    CSL_IGNORE(nil);
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v15 = v0;
/* end of prologue */

v11:
    v43 = v15;
    v43 = (v43 == nil ? lisp_true : nil);
    if (!(v43 == nil)) return onevalue(v43);
    v43 = v15;
    if (!consp(v43)) goto v6;
    v43 = v15;
    v43 = qcar(v43);
    if (symbolp(v43)) goto v27;
    v15 = nil;
    return onevalue(v15);

v27:
    v15 = qcdr(v15);
    goto v11;

v6:
    v15 = nil;
    return onevalue(v15);
}



/* Code for sroad */

static Lisp_Object MS_CDECL CC_sroad(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v16,
                         Lisp_Object v63, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v40, v206, v41;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "sroad");
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
    v41 = nil;
    goto v45;

v45:
    v40 = stack[0];
    if (v40 == nil) goto v7;
    v206 = stack[-2];
    v40 = stack[0];
    v40 = qcar(v40);
    if (equal(v206, v40)) goto v17;
    v40 = stack[0];
    v40 = qcar(v40);
    v206 = v41;
    v40 = cons(v40, v206);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-3];
    v41 = v40;
    v40 = stack[0];
    v40 = qcdr(v40);
    stack[0] = v40;
    goto v45;

v17:
    stack[-2] = v41;
    v206 = stack[-1];
    v40 = stack[0];
    v40 = qcdr(v40);
    v40 = Lappend(nil, v206, v40);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-3];
    {
        Lisp_Object v105 = stack[-2];
        popv(4);
        fn = elt(env, 1); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v105, v40);
    }

v7:
    v40 = v41;
    {
        popv(4);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v40);
    }
/* error exit handlers */
v134:
    popv(4);
    return nil;
}



/* Code for dp!=ecart */

static Lisp_Object CC_dpMecart(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v33, v51;
    Lisp_Object fn;
    CSL_IGNORE(nil);
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
    v33 = stack[0];
    if (v33 == nil) goto v45;
    v33 = stack[0];
    fn = elt(env, 1); /* dp_lmon */
    v33 = (*qfn1(fn))(qenv(fn), v33);
    nil = C_nil;
    if (exception_pending()) goto v50;
    env = stack[-2];
    fn = elt(env, 2); /* mo_ecart */
    v51 = (*qfn1(fn))(qenv(fn), v33);
    nil = C_nil;
    if (exception_pending()) goto v50;
    env = stack[-2];
    v33 = stack[-1];
    v33 = cons(v51, v33);
    nil = C_nil;
    if (exception_pending()) goto v50;
    env = stack[-2];
    stack[-1] = v33;
    v33 = stack[0];
    v33 = qcdr(v33);
    stack[0] = v33;
    goto v12;

v45:
    v33 = (Lisp_Object)1; /* 0 */
    v51 = v33;
    goto v5;

v5:
    v33 = stack[-1];
    if (v33 == nil) { popv(3); return onevalue(v51); }
    v33 = stack[-1];
    v33 = qcar(v33);
    v33 = Lmax2(nil, v33, v51);
    nil = C_nil;
    if (exception_pending()) goto v50;
    env = stack[-2];
    v51 = v33;
    v33 = stack[-1];
    v33 = qcdr(v33);
    stack[-1] = v33;
    goto v5;
/* error exit handlers */
v50:
    popv(3);
    return nil;
}



/* Code for pv_sort1 */

static Lisp_Object CC_pv_sort1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v40, v206;
    Lisp_Object fn;
    CSL_IGNORE(nil);
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

v12:
    v40 = stack[-1];
    if (v40 == nil) goto v6;
    v40 = stack[-1];
    v40 = qcar(v40);
    v206 = qcdr(v40);
    v40 = stack[0];
    v40 = qcar(v40);
    v40 = qcdr(v40);
    v40 = (Lisp_Object)lessp2(v206, v40);
    nil = C_nil;
    if (exception_pending()) goto v150;
    v40 = v40 ? lisp_true : nil;
    env = stack[-3];
    if (v40 == nil) goto v32;
    v40 = stack[-1];
    v40 = qcdr(v40);
    stack[-2] = v40;
    v40 = stack[-1];
    v206 = qcar(v40);
    v40 = stack[0];
    v40 = cons(v206, v40);
    nil = C_nil;
    if (exception_pending()) goto v150;
    env = stack[-3];
    stack[0] = v40;
    v40 = stack[-2];
    stack[-1] = v40;
    goto v12;

v32:
    v40 = stack[-1];
    v40 = qcdr(v40);
    stack[-2] = v40;
    v40 = stack[-1];
    v206 = qcar(v40);
    v40 = stack[0];
    fn = elt(env, 1); /* pv_sort2 */
    v40 = (*qfn2(fn))(qenv(fn), v206, v40);
    nil = C_nil;
    if (exception_pending()) goto v150;
    env = stack[-3];
    stack[0] = v40;
    v40 = stack[-2];
    stack[-1] = v40;
    goto v12;

v6:
    v40 = stack[0];
        popv(4);
        return Lnreverse(nil, v40);
/* error exit handlers */
v150:
    popv(4);
    return nil;
}



/* Code for gen!-mult!-by!-const!-mod!-p */

static Lisp_Object CC_genKmultKbyKconstKmodKp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v87, v66;
    Lisp_Object fn;
    CSL_IGNORE(nil);
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
    v87 = stack[-2];
    if (v87 == nil) goto v4;
    v66 = stack[-1];
    v87 = (Lisp_Object)17; /* 1 */
    if (v66 == v87) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v87 = stack[-2];
    if (!consp(v87)) goto v19;
    v87 = stack[-2];
    v87 = qcar(v87);
    if (!consp(v87)) goto v19;
    v87 = stack[-2];
    v87 = qcar(v87);
    stack[-3] = qcar(v87);
    v87 = stack[-2];
    v87 = qcar(v87);
    v66 = qcdr(v87);
    v87 = stack[-1];
    stack[0] = CC_genKmultKbyKconstKmodKp(env, v66, v87);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-4];
    v87 = stack[-2];
    v66 = qcdr(v87);
    v87 = stack[-1];
    v87 = CC_genKmultKbyKconstKmodKp(env, v66, v87);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-4];
    {
        Lisp_Object v122 = stack[-3];
        Lisp_Object v58 = stack[0];
        popv(5);
        fn = elt(env, 1); /* adjoin!-term */
        return (*qfnn(fn))(qenv(fn), 3, v122, v58, v87);
    }

v19:
    v66 = stack[-2];
    v87 = stack[-1];
    fn = elt(env, 2); /* general!-modular!-times */
    v87 = (*qfn2(fn))(qenv(fn), v66, v87);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-4];
    {
        popv(5);
        fn = elt(env, 3); /* !*n2f */
        return (*qfn1(fn))(qenv(fn), v87);
    }

v4:
    v87 = nil;
    { popv(5); return onevalue(v87); }
/* error exit handlers */
v72:
    popv(5);
    return nil;
}



/* Code for c!:ordexp */

static Lisp_Object CC_cTordexp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v31, v32, v37, v36;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v32 = v16;
    v37 = v0;
/* end of prologue */

v4:
    v31 = v37;
    if (v31 == nil) goto v5;
    v31 = v37;
    v36 = qcar(v31);
    v31 = v32;
    v31 = qcar(v31);
    if (equal(v36, v31)) goto v1;
    v31 = v37;
    v31 = qcar(v31);
    v32 = qcar(v32);
    {
        fn = elt(env, 1); /* c!:ordxp */
        return (*qfn2(fn))(qenv(fn), v31, v32);
    }

v1:
    v31 = v37;
    v31 = qcdr(v31);
    v37 = v31;
    v31 = v32;
    v31 = qcdr(v31);
    v32 = v31;
    goto v4;

v5:
    v31 = lisp_true;
    return onevalue(v31);
}



/* Code for times!-mod!-p */

static Lisp_Object CC_timesKmodKp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v212, v462;
    Lisp_Object fn;
    CSL_IGNORE(nil);
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
    v212 = stack[-2];
    if (v212 == nil) goto v4;
    v212 = stack[-1];
    if (v212 == nil) goto v4;
    v212 = stack[-2];
    if (!consp(v212)) goto v38;
    v212 = stack[-2];
    v212 = qcar(v212);
    if (!consp(v212)) goto v38;
    v212 = stack[-1];
    if (!consp(v212)) goto v10;
    v212 = stack[-1];
    v212 = qcar(v212);
    if (!consp(v212)) goto v10;
    v212 = stack[-2];
    v212 = qcar(v212);
    v212 = qcar(v212);
    v462 = qcar(v212);
    v212 = stack[-1];
    v212 = qcar(v212);
    v212 = qcar(v212);
    v212 = qcar(v212);
    if (equal(v462, v212)) goto v71;
    v212 = stack[-2];
    v212 = qcar(v212);
    v212 = qcar(v212);
    v462 = qcar(v212);
    v212 = stack[-1];
    v212 = qcar(v212);
    v212 = qcar(v212);
    v212 = qcar(v212);
    fn = elt(env, 1); /* ordop */
    v212 = (*qfn2(fn))(qenv(fn), v462, v212);
    nil = C_nil;
    if (exception_pending()) goto v474;
    env = stack[-4];
    if (v212 == nil) goto v230;
    v212 = stack[-2];
    v212 = qcar(v212);
    stack[-3] = qcar(v212);
    v212 = stack[-2];
    v212 = qcar(v212);
    v462 = qcdr(v212);
    v212 = stack[-1];
    stack[0] = CC_timesKmodKp(env, v462, v212);
    nil = C_nil;
    if (exception_pending()) goto v474;
    env = stack[-4];
    v212 = stack[-2];
    v462 = qcdr(v212);
    v212 = stack[-1];
    v212 = CC_timesKmodKp(env, v462, v212);
    nil = C_nil;
    if (exception_pending()) goto v474;
    env = stack[-4];
    {
        Lisp_Object v188 = stack[-3];
        Lisp_Object v211 = stack[0];
        popv(5);
        fn = elt(env, 2); /* adjoin!-term */
        return (*qfnn(fn))(qenv(fn), 3, v188, v211, v212);
    }

v230:
    v212 = stack[-1];
    v212 = qcar(v212);
    stack[-3] = qcar(v212);
    v462 = stack[-2];
    v212 = stack[-1];
    v212 = qcar(v212);
    v212 = qcdr(v212);
    stack[0] = CC_timesKmodKp(env, v462, v212);
    nil = C_nil;
    if (exception_pending()) goto v474;
    env = stack[-4];
    v462 = stack[-2];
    v212 = stack[-1];
    v212 = qcdr(v212);
    v212 = CC_timesKmodKp(env, v462, v212);
    nil = C_nil;
    if (exception_pending()) goto v474;
    env = stack[-4];
    {
        Lisp_Object v126 = stack[-3];
        Lisp_Object v129 = stack[0];
        popv(5);
        fn = elt(env, 2); /* adjoin!-term */
        return (*qfnn(fn))(qenv(fn), 3, v126, v129, v212);
    }

v71:
    v212 = stack[-2];
    v462 = qcar(v212);
    v212 = stack[-1];
    fn = elt(env, 3); /* times!-term!-mod!-p */
    stack[0] = (*qfn2(fn))(qenv(fn), v462, v212);
    nil = C_nil;
    if (exception_pending()) goto v474;
    env = stack[-4];
    v212 = stack[-1];
    v462 = qcar(v212);
    v212 = stack[-2];
    v212 = qcdr(v212);
    fn = elt(env, 3); /* times!-term!-mod!-p */
    v212 = (*qfn2(fn))(qenv(fn), v462, v212);
    nil = C_nil;
    if (exception_pending()) goto v474;
    env = stack[-4];
    fn = elt(env, 4); /* plus!-mod!-p */
    stack[0] = (*qfn2(fn))(qenv(fn), stack[0], v212);
    nil = C_nil;
    if (exception_pending()) goto v474;
    env = stack[-4];
    v212 = stack[-2];
    v462 = qcdr(v212);
    v212 = stack[-1];
    v212 = qcdr(v212);
    v212 = CC_timesKmodKp(env, v462, v212);
    nil = C_nil;
    if (exception_pending()) goto v474;
    env = stack[-4];
    {
        Lisp_Object v130 = stack[0];
        popv(5);
        fn = elt(env, 4); /* plus!-mod!-p */
        return (*qfn2(fn))(qenv(fn), v130, v212);
    }

v10:
    v462 = stack[-2];
    v212 = stack[-1];
    {
        popv(5);
        fn = elt(env, 5); /* multiply!-by!-constant!-mod!-p */
        return (*qfn2(fn))(qenv(fn), v462, v212);
    }

v38:
    v462 = stack[-1];
    v212 = stack[-2];
    {
        popv(5);
        fn = elt(env, 5); /* multiply!-by!-constant!-mod!-p */
        return (*qfn2(fn))(qenv(fn), v462, v212);
    }

v4:
    v212 = nil;
    { popv(5); return onevalue(v212); }
/* error exit handlers */
v474:
    popv(5);
    return nil;
}



/* Code for tayexp!-difference */

static Lisp_Object CC_tayexpKdifference(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v65, v103, v59;
    Lisp_Object fn;
    CSL_IGNORE(nil);
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
    v103 = v0;
/* end of prologue */
    v65 = v103;
    if (!(!consp(v65))) goto v28;
    v65 = stack[0];
    if (!(!consp(v65))) goto v28;
    v65 = stack[0];
    popv(3);
    return difference2(v103, v65);

v28:
    v65 = v103;
    if (!consp(v65)) goto v18;
    v65 = stack[0];
    if (!consp(v65)) goto v31;
    v65 = stack[0];
    fn = elt(env, 1); /* rndifference!: */
    v65 = (*qfn2(fn))(qenv(fn), v103, v65);
    nil = C_nil;
    if (exception_pending()) goto v95;
    goto v47;

v47:
    v59 = v65;
    v65 = v59;
    v65 = qcdr(v65);
    v103 = qcdr(v65);
    v65 = (Lisp_Object)17; /* 1 */
    if (!(v103 == v65)) { popv(3); return onevalue(v59); }
    v65 = v59;
    v65 = qcdr(v65);
    v65 = qcar(v65);
    { popv(3); return onevalue(v65); }

v31:
    stack[-1] = v103;
    v65 = stack[0];
    fn = elt(env, 2); /* !*i2rn */
    v65 = (*qfn1(fn))(qenv(fn), v65);
    nil = C_nil;
    if (exception_pending()) goto v95;
    env = stack[-2];
    fn = elt(env, 1); /* rndifference!: */
    v65 = (*qfn2(fn))(qenv(fn), stack[-1], v65);
    nil = C_nil;
    if (exception_pending()) goto v95;
    goto v47;

v18:
    v65 = v103;
    fn = elt(env, 2); /* !*i2rn */
    v103 = (*qfn1(fn))(qenv(fn), v65);
    nil = C_nil;
    if (exception_pending()) goto v95;
    env = stack[-2];
    v65 = stack[0];
    fn = elt(env, 1); /* rndifference!: */
    v65 = (*qfn2(fn))(qenv(fn), v103, v65);
    nil = C_nil;
    if (exception_pending()) goto v95;
    goto v47;
/* error exit handlers */
v95:
    popv(3);
    return nil;
}



/* Code for get!+col!+nr */

static Lisp_Object CC_getLcolLnr(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v45;
    CSL_IGNORE(nil);
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v45 = v0;
/* end of prologue */
    v45 = qcar(v45);
        return Llength(nil, v45);
}



/* Code for list2string */

static Lisp_Object CC_list2string(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v47, v15;
    CSL_IGNORE(nil);
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
    v15 = stack[0];
    v47 = nil;
    v47 = Lneq(nil, v15, v47);
    nil = C_nil;
    if (exception_pending()) goto v29;
    env = stack[-1];
    if (v47 == nil) goto v4;
    v47 = stack[0];
    v47 = qcar(v47);
    v47 = Lprinc(nil, v47);
    nil = C_nil;
    if (exception_pending()) goto v29;
    env = stack[-1];
    v47 = stack[0];
    v47 = qcdr(v47);
    v47 = CC_list2string(env, v47);
    nil = C_nil;
    if (exception_pending()) goto v29;
    goto v4;

v4:
    v47 = nil;
    { popv(2); return onevalue(v47); }
/* error exit handlers */
v29:
    popv(2);
    return nil;
}



/* Code for findrow */

static Lisp_Object CC_findrow(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v46, v31, v32, v37;
    CSL_IGNORE(nil);
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
    v46 = v16;
    v31 = v0;
/* end of prologue */
    v32 = v31;
    v32 = Lconsp(nil, v32);
    env = stack[0];
    if (v32 == nil) goto v23;
    v32 = v31;
    v32 = qcar(v32);
    v37 = elt(env, 1); /* sparsemat */
    if (!(v32 == v37)) goto v23;
    v31 = qcdr(v31);
    v31 = qcar(v31);
    goto v23;

v23:
    v46 = *(Lisp_Object *)((char *)v31 + (CELL-TAG_VECTOR) + ((int32_t)v46/(16/CELL)));
    { popv(1); return onevalue(v46); }
}



/* Code for nextarg */

static Lisp_Object CC_nextarg(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v2, v25;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v25 = v0;
/* end of prologue */
    v2 = qvalue(elt(env, 1)); /* symm */
    if (v2 == nil) goto v6;
    v2 = v25;
    {
        fn = elt(env, 2); /* s!-nextarg */
        return (*qfn1(fn))(qenv(fn), v2);
    }

v6:
    v2 = v25;
    {
        fn = elt(env, 3); /* o!-nextarg */
        return (*qfn1(fn))(qenv(fn), v2);
    }
}



/* Code for off1 */

static Lisp_Object CC_off1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v7, v8;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v7 = v0;
/* end of prologue */
    v8 = v7;
    v7 = nil;
    {
        fn = elt(env, 1); /* onoff */
        return (*qfn2(fn))(qenv(fn), v8, v7);
    }
}



/* Code for atomf */

static Lisp_Object CC_atomf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v24, v26;
    CSL_IGNORE(nil);
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v26 = v0;
/* end of prologue */
    v24 = v26;
    v24 = (consp(v24) ? nil : lisp_true);
    if (!(v24 == nil)) return onevalue(v24);
    v24 = v26;
    v24 = qcar(v24);
    v26 = elt(env, 1); /* indexvar */
        return Lflagp(nil, v24, v26);
}



/* Code for maxdeg */

static Lisp_Object CC_maxdeg(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v10, v53;
    CSL_IGNORE(nil);
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

v12:
    v10 = stack[-1];
    if (v10 == nil) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v10 = stack[-1];
    v10 = qcar(v10);
    v53 = qcdr(v10);
    v10 = stack[0];
    v10 = qcdr(v10);
    v10 = (Lisp_Object)greaterp2(v53, v10);
    nil = C_nil;
    if (exception_pending()) goto v31;
    v10 = v10 ? lisp_true : nil;
    env = stack[-2];
    if (v10 == nil) goto v22;
    v10 = stack[-1];
    v10 = qcdr(v10);
    v53 = v10;
    v10 = stack[-1];
    v10 = qcar(v10);
    stack[0] = v10;
    v10 = v53;
    stack[-1] = v10;
    goto v12;

v22:
    v10 = stack[-1];
    v10 = qcdr(v10);
    stack[-1] = v10;
    goto v12;
/* error exit handlers */
v31:
    popv(3);
    return nil;
}



/* Code for noncommuting */

static Lisp_Object CC_noncommuting(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v100, v150;
    Lisp_Object fn;
    CSL_IGNORE(nil);
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
    v100 = stack[-1];
    if (!consp(v100)) goto v6;
    v100 = stack[-1];
    v100 = qcar(v100);
    goto v5;

v5:
    stack[-1] = v100;
    v100 = stack[0];
    if (!consp(v100)) goto v28;
    v100 = stack[0];
    v100 = qcar(v100);
    goto v27;

v27:
    stack[0] = v100;
    v100 = stack[-1];
    fn = elt(env, 2); /* noncomp2 */
    v100 = (*qfn1(fn))(qenv(fn), v100);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[-3];
    if (v100 == nil) { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
    v100 = stack[0];
    fn = elt(env, 2); /* noncomp2 */
    v100 = (*qfn1(fn))(qenv(fn), v100);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[-3];
    if (v100 == nil) { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
    v150 = stack[-1];
    v100 = elt(env, 1); /* noncommutes */
    v100 = get(v150, v100);
    v150 = stack[0];
    v100 = Lmember(nil, v150, v100);
    stack[-2] = v100;
    { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }

v28:
    v100 = stack[0];
    goto v27;

v6:
    v100 = stack[-1];
    goto v5;
/* error exit handlers */
v67:
    popv(4);
    return nil;
}



/* Code for repeatsp */

static Lisp_Object CC_repeatsp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v17, v18, v19;
    CSL_IGNORE(nil);
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v18 = v0;
/* end of prologue */

v11:
    v17 = v18;
    if (v17 == nil) goto v3;
    v17 = v18;
    v19 = qcar(v17);
    v17 = v18;
    v17 = qcdr(v17);
    v17 = Lmember(nil, v19, v17);
    if (!(v17 == nil)) return onevalue(v17);
    v17 = v18;
    v17 = qcdr(v17);
    v18 = v17;
    goto v11;

v3:
    v17 = nil;
    return onevalue(v17);
}



/* Code for bc!=simp */

static Lisp_Object CC_bcMsimp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v143, v144;
    Lisp_Object fn;
    CSL_IGNORE(nil);
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
    v144 = elt(env, 1); /* cali */
    v143 = elt(env, 2); /* rules */
    v143 = get(v144, v143);
    env = stack[-5];
    stack[-4] = v143;
    v143 = stack[-4];
    if (v143 == nil) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v143 = (Lisp_Object)1; /* 0 */
    stack[0] = v143;
    v143 = stack[-4];
    stack[-2] = v143;
    goto v17;

v17:
    v143 = stack[-2];
    if (v143 == nil) goto v128;
    v144 = stack[0];
    v143 = (Lisp_Object)16001; /* 1000 */
    v143 = (Lisp_Object)lessp2(v144, v143);
    nil = C_nil;
    if (exception_pending()) goto v118;
    v143 = v143 ? lisp_true : nil;
    env = stack[-5];
    if (v143 == nil) goto v128;
    v144 = stack[-3];
    v143 = stack[-2];
    v143 = qcar(v143);
    v143 = qcar(v143);
    fn = elt(env, 4); /* qremf */
    v143 = (*qfn2(fn))(qenv(fn), v144, v143);
    nil = C_nil;
    if (exception_pending()) goto v118;
    env = stack[-5];
    stack[-1] = v143;
    v143 = stack[-1];
    v143 = qcar(v143);
    if (v143 == nil) goto v206;
    v143 = stack[-1];
    v144 = qcar(v143);
    v143 = stack[-2];
    v143 = qcar(v143);
    v143 = qcdr(v143);
    fn = elt(env, 5); /* multf */
    v144 = (*qfn2(fn))(qenv(fn), v144, v143);
    nil = C_nil;
    if (exception_pending()) goto v118;
    env = stack[-5];
    v143 = stack[-1];
    v143 = qcdr(v143);
    fn = elt(env, 6); /* addf */
    v143 = (*qfn2(fn))(qenv(fn), v144, v143);
    nil = C_nil;
    if (exception_pending()) goto v118;
    env = stack[-5];
    stack[-3] = v143;
    v143 = stack[0];
    v143 = add1(v143);
    nil = C_nil;
    if (exception_pending()) goto v118;
    env = stack[-5];
    stack[0] = v143;
    v143 = stack[-4];
    stack[-2] = v143;
    goto v17;

v206:
    v143 = stack[-2];
    v143 = qcdr(v143);
    stack[-2] = v143;
    goto v17;

v128:
    v144 = stack[0];
    v143 = (Lisp_Object)16001; /* 1000 */
    v143 = (Lisp_Object)lessp2(v144, v143);
    nil = C_nil;
    if (exception_pending()) goto v118;
    v143 = v143 ? lisp_true : nil;
    env = stack[-5];
    if (!(v143 == nil)) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v143 = elt(env, 3); /* "recursion depth of bc!=simp too high" */
    fn = elt(env, 7); /* rederr */
    v143 = (*qfn1(fn))(qenv(fn), v143);
    nil = C_nil;
    if (exception_pending()) goto v118;
    v143 = nil;
    { popv(6); return onevalue(v143); }
/* error exit handlers */
v118:
    popv(6);
    return nil;
}



/* Code for pv_applp */

static Lisp_Object CC_pv_applp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v55, v65;
    Lisp_Object fn;
    CSL_IGNORE(nil);
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
    CSL_IGNORE(nil);
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
    CSL_IGNORE(nil);
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
    CSL_IGNORE(nil);
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



/* Code for praddf */

static Lisp_Object CC_praddf(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v20, v21;
    Lisp_Object fn;
    CSL_IGNORE(nil);
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
    v20 = stack[-1];
    v21 = qcar(v20);
    v20 = stack[0];
    v20 = qcar(v20);
    fn = elt(env, 1); /* addf */
    stack[-2] = (*qfn2(fn))(qenv(fn), v21, v20);
    nil = C_nil;
    if (exception_pending()) goto v99;
    env = stack[-3];
    v20 = stack[-1];
    v21 = qcdr(v20);
    v20 = stack[0];
    v20 = qcdr(v20);
    fn = elt(env, 1); /* addf */
    v20 = (*qfn2(fn))(qenv(fn), v21, v20);
    nil = C_nil;
    if (exception_pending()) goto v99;
    {
        Lisp_Object v10 = stack[-2];
        popv(4);
        return cons(v10, v20);
    }
/* error exit handlers */
v99:
    popv(4);
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
    CSL_IGNORE(nil);
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



/* Code for find */

static Lisp_Object CC_find(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v34, v39, v40;
    CSL_IGNORE(nil);
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
    v39 = v16;
    stack[0] = v0;
/* end of prologue */

v6:
    v40 = v39;
    v34 = nil;
    if (v40 == v34) goto v44;
    v34 = v39;
    v40 = qcar(v34);
    v34 = stack[0];
    v34 = Lmember(nil, v40, v34);
    v39 = qcdr(v39);
    stack[0] = v34;
    goto v6;

v44:
    v39 = stack[0];
    v34 = nil;
    v34 = Lneq(nil, v39, v34);
    nil = C_nil;
    if (exception_pending()) goto v41;
    env = stack[-1];
    if (v34 == nil) goto v21;
    v34 = stack[0];
    v34 = qcdr(v34);
    { popv(2); return onevalue(v34); }

v21:
    v34 = elt(env, 1); /* (stop) */
    { popv(2); return onevalue(v34); }
/* error exit handlers */
v41:
    popv(2);
    return nil;
}



/* Code for mkwedge */

static Lisp_Object CC_mkwedge(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v25, v13, v24;
    CSL_IGNORE(nil);
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
    CSL_IGNORE(nil);
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
    CSL_IGNORE(nil);
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
    if (((int32_t)(v40)) > ((int32_t)(v206))) goto v31;
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
    CSL_IGNORE(nil);
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
    CSL_IGNORE(nil);
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
    CSL_IGNORE(nil);
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



/* Code for tayexp!-min2 */

static Lisp_Object CC_tayexpKmin2(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v28, v38;
    Lisp_Object fn;
    CSL_IGNORE(nil);
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
    v38 = stack[-1];
    v28 = stack[0];
    fn = elt(env, 1); /* tayexp!-lessp */
    v28 = (*qfn2(fn))(qenv(fn), v38, v28);
    nil = C_nil;
    if (exception_pending()) goto v15;
    if (v28 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    else { Lisp_Object res = stack[-1]; popv(2); return onevalue(res); }
/* error exit handlers */
v15:
    popv(2);
    return nil;
}



/* Code for pnthxzz */

static Lisp_Object CC_pnthxzz(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v18, v19, v20, v21;
    CSL_IGNORE(nil);
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v19 = v16;
    v20 = v0;
/* end of prologue */

v4:
    v18 = v19;
    if (v18 == nil) return onevalue(v19);
    v18 = v19;
    v18 = qcar(v18);
    v21 = qcar(v18);
    v18 = v20;
    if (equal(v21, v18)) return onevalue(v19);
    v18 = v19;
    v18 = qcdr(v18);
    v19 = v18;
    goto v4;
}



/* Code for fast_unchecked_getmatelem */

static Lisp_Object CC_fast_unchecked_getmatelem(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v43, v29;
    Lisp_Object fn;
    CSL_IGNORE(nil);
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
    v43 = stack[0];
    v43 = qcar(v43);
    v29 = qcdr(v43);
    v43 = stack[0];
    v43 = qcdr(v43);
    v43 = qcar(v43);
    fn = elt(env, 1); /* nth */
    v29 = (*qfn2(fn))(qenv(fn), v29, v43);
    nil = C_nil;
    if (exception_pending()) goto v18;
    env = stack[-1];
    v43 = stack[0];
    v43 = qcdr(v43);
    v43 = qcdr(v43);
    v43 = qcar(v43);
    {
        popv(2);
        fn = elt(env, 1); /* nth */
        return (*qfn2(fn))(qenv(fn), v29, v43);
    }
/* error exit handlers */
v18:
    popv(2);
    return nil;
}



/* Code for physopp!* */

static Lisp_Object CC_physoppH(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v54, v87;
    Lisp_Object fn;
    CSL_IGNORE(nil);
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
    CSL_IGNORE(nil);
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
    CSL_IGNORE(nil);
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



/* Code for removev */

static Lisp_Object CC_removev(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v50, v52, v193, v35;
    Lisp_Object fn;
    CSL_IGNORE(nil);
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
    v35 = v16;
    v193 = v0;
/* end of prologue */

v4:
    v50 = v193;
    if (v50 == nil) goto v2;
    v50 = v193;
    v50 = qcdr(v50);
    v52 = qcar(v50);
    v50 = v35;
    if (v52 == v50) goto v10;
    v50 = v193;
    v50 = qcdr(v50);
    v193 = v50;
    goto v4;

v10:
    v50 = v193;
    v52 = v193;
    v52 = qcdr(v52);
    v52 = qcdr(v52);
        popv(1);
        return Lrplacd(nil, v50, v52);

v2:
    v52 = elt(env, 1); /* "Vertex" */
    v193 = v35;
    v50 = elt(env, 2); /* "is absent." */
    v50 = list3(v52, v193, v50);
    nil = C_nil;
    if (exception_pending()) goto v34;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 3); /* cerror */
        return (*qfn1(fn))(qenv(fn), v50);
    }
/* error exit handlers */
v34:
    popv(1);
    return nil;
}



/* Code for ps!:evaluate */

static Lisp_Object CC_psTevaluate(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v34, v39;
    Lisp_Object fn;
    CSL_IGNORE(nil);
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
    v39 = stack[-2];
    v34 = stack[-1];
    fn = elt(env, 1); /* ps!:get!-term */
    v34 = (*qfn2(fn))(qenv(fn), v39, v34);
    nil = C_nil;
    if (exception_pending()) goto v100;
    env = stack[-4];
    stack[-3] = v34;
    v34 = stack[-3];
    if (!(v34 == nil)) { Lisp_Object res = stack[-3]; popv(5); return onevalue(res); }
    v34 = stack[-2];
    fn = elt(env, 2); /* ps!:last!-term */
    v34 = (*qfn1(fn))(qenv(fn), v34);
    nil = C_nil;
    if (exception_pending()) goto v100;
    env = stack[-4];
    v34 = add1(v34);
    nil = C_nil;
    if (exception_pending()) goto v100;
    env = stack[-4];
    stack[0] = v34;
    goto v30;

v30:
    v39 = stack[-1];
    v34 = stack[0];
    v34 = difference2(v39, v34);
    nil = C_nil;
    if (exception_pending()) goto v100;
    env = stack[-4];
    v34 = Lminusp(nil, v34);
    env = stack[-4];
    if (!(v34 == nil)) { Lisp_Object res = stack[-3]; popv(5); return onevalue(res); }
    v39 = stack[-2];
    v34 = stack[0];
    fn = elt(env, 3); /* ps!:evaluate!-next */
    v34 = (*qfn2(fn))(qenv(fn), v39, v34);
    nil = C_nil;
    if (exception_pending()) goto v100;
    env = stack[-4];
    stack[-3] = v34;
    v34 = stack[0];
    v34 = add1(v34);
    nil = C_nil;
    if (exception_pending()) goto v100;
    env = stack[-4];
    stack[0] = v34;
    goto v30;
/* error exit handlers */
v100:
    popv(5);
    return nil;
}



/* Code for subscriptedvarp */

static Lisp_Object CC_subscriptedvarp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v20, v21;
    Lisp_Object fn;
    CSL_IGNORE(nil);
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
    v21 = nil;
    v20 = stack[0];
    fn = elt(env, 2); /* symtabget */
    v20 = (*qfn2(fn))(qenv(fn), v21, v20);
    nil = C_nil;
    if (exception_pending()) goto v23;
    env = stack[-1];
    v21 = Llength(nil, v20);
    nil = C_nil;
    if (exception_pending()) goto v23;
    env = stack[-1];
    v20 = (Lisp_Object)33; /* 2 */
    v20 = (Lisp_Object)greaterp2(v21, v20);
    nil = C_nil;
    if (exception_pending()) goto v23;
    v20 = v20 ? lisp_true : nil;
    env = stack[-1];
    if (!(v20 == nil)) { popv(2); return onevalue(v20); }
    v20 = stack[0];
    v21 = elt(env, 1); /* subscripted */
        popv(2);
        return Lflagp(nil, v20, v21);
/* error exit handlers */
v23:
    popv(2);
    return nil;
}



/* Code for bound */

static Lisp_Object CC_bound(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v44, v47;
    Lisp_Object fn;
    CSL_IGNORE(nil);
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
    v44 = v0;
/* end of prologue */
    fn = elt(env, 2); /* binding */
    v44 = (*qfn1(fn))(qenv(fn), v44);
    nil = C_nil;
    if (exception_pending()) goto v15;
    env = stack[0];
    v47 = v44;
    v44 = v47;
    if (v44 == nil) goto v45;
    v44 = v47;
    v47 = elt(env, 1); /* unbound */
        popv(1);
        return Lneq(nil, v44, v47);

v45:
    v44 = nil;
    { popv(1); return onevalue(v44); }
/* error exit handlers */
v15:
    popv(1);
    return nil;
}



/* Code for deg!*farg */

static Lisp_Object CC_degHfarg(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v36, v48;
    Lisp_Object fn;
    CSL_IGNORE(nil);
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
    CSL_IGNORE(nil);
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
    CSL_IGNORE(nil);
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
    CSL_IGNORE(nil);
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
    CSL_IGNORE(nil);
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
    CSL_IGNORE(nil);
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v25 = v16;
    v13 = v0;
/* end of prologue */
    v24 = elt(env, 1); /* !:gi!: */
    return list2star(v24, v13, v25);
}



/* Code for omobj */

static Lisp_Object MS_CDECL CC_omobj(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v19, v20;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "omobj");
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* end of prologue */
    v19 = qvalue(elt(env, 1)); /* char */
    fn = elt(env, 3); /* compress!* */
    v20 = (*qfn1(fn))(qenv(fn), v19);
    nil = C_nil;
    if (exception_pending()) goto v21;
    env = stack[0];
    v19 = qvalue(elt(env, 2)); /* omfuncs!* */
    v19 = Lassoc(nil, v20, v19);
    v20 = v19;
    if (v19 == nil) goto v12;
    v19 = v20;
    v19 = qcdr(v19);
    v20 = qcar(v19);
    v19 = nil;
    {
        popv(1);
        fn = elt(env, 4); /* apply */
        return (*qfn2(fn))(qenv(fn), v20, v19);
    }

v12:
    v19 = nil;
    { popv(1); return onevalue(v19); }
/* error exit handlers */
v21:
    popv(1);
    return nil;
}



/* Code for red!-char!-downcase */

static Lisp_Object CC_redKcharKdowncase(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v44, v47, v15;
    CSL_IGNORE(nil);
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
    CSL_IGNORE(nil);
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
    CSL_IGNORE(nil);
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



/* Code for wulessp */

static Lisp_Object CC_wulessp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v144;
    Lisp_Object fn;
    CSL_IGNORE(nil);
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
    v144 = stack[-1];
    fn = elt(env, 1); /* wuconstantp */
    v144 = (*qfn1(fn))(qenv(fn), v144);
    nil = C_nil;
    if (exception_pending()) goto v81;
    env = stack[-3];
    if (v144 == nil) goto v28;
    v144 = nil;
    stack[-2] = v144;
    goto v6;

v6:
    v144 = stack[0];
    fn = elt(env, 1); /* wuconstantp */
    v144 = (*qfn1(fn))(qenv(fn), v144);
    nil = C_nil;
    if (exception_pending()) goto v81;
    env = stack[-3];
    if (v144 == nil) goto v23;
    v144 = nil;
    goto v7;

v7:
    fn = elt(env, 2); /* symbollessp */
    v144 = (*qfn2(fn))(qenv(fn), stack[-2], v144);
    nil = C_nil;
    if (exception_pending()) goto v81;
    env = stack[-3];
    if (!(v144 == nil)) { popv(4); return onevalue(v144); }
    v144 = stack[-1];
    fn = elt(env, 1); /* wuconstantp */
    v144 = (*qfn1(fn))(qenv(fn), v144);
    nil = C_nil;
    if (exception_pending()) goto v81;
    env = stack[-3];
    if (v144 == nil) goto v40;
    v144 = nil;
    stack[-2] = v144;
    goto v33;

v33:
    v144 = stack[0];
    fn = elt(env, 1); /* wuconstantp */
    v144 = (*qfn1(fn))(qenv(fn), v144);
    nil = C_nil;
    if (exception_pending()) goto v81;
    env = stack[-3];
    if (v144 == nil) goto v87;
    v144 = nil;
    goto v51;

v51:
    if (equal(stack[-2], v144)) goto v65;
    v144 = nil;
    { popv(4); return onevalue(v144); }

v65:
    v144 = stack[-1];
    fn = elt(env, 1); /* wuconstantp */
    v144 = (*qfn1(fn))(qenv(fn), v144);
    nil = C_nil;
    if (exception_pending()) goto v81;
    env = stack[-3];
    if (v144 == nil) goto v104;
    v144 = (Lisp_Object)1; /* 0 */
    stack[-1] = v144;
    goto v59;

v59:
    v144 = stack[0];
    fn = elt(env, 1); /* wuconstantp */
    v144 = (*qfn1(fn))(qenv(fn), v144);
    nil = C_nil;
    if (exception_pending()) goto v81;
    if (v144 == nil) goto v456;
    v144 = (Lisp_Object)1; /* 0 */
    goto v60;

v60:
    {
        Lisp_Object v97 = stack[-1];
        popv(4);
        return Llessp(nil, v97, v144);
    }

v456:
    v144 = stack[0];
    v144 = qcar(v144);
    v144 = qcar(v144);
    v144 = qcdr(v144);
    goto v60;

v104:
    v144 = stack[-1];
    v144 = qcar(v144);
    v144 = qcar(v144);
    v144 = qcdr(v144);
    stack[-1] = v144;
    goto v59;

v87:
    v144 = stack[0];
    v144 = qcar(v144);
    v144 = qcar(v144);
    v144 = qcar(v144);
    goto v51;

v40:
    v144 = stack[-1];
    v144 = qcar(v144);
    v144 = qcar(v144);
    v144 = qcar(v144);
    stack[-2] = v144;
    goto v33;

v23:
    v144 = stack[0];
    v144 = qcar(v144);
    v144 = qcar(v144);
    v144 = qcar(v144);
    goto v7;

v28:
    v144 = stack[-1];
    v144 = qcar(v144);
    v144 = qcar(v144);
    v144 = qcar(v144);
    stack[-2] = v144;
    goto v6;
/* error exit handlers */
v81:
    popv(4);
    return nil;
}



/* Code for sfto_dcontentf */

static Lisp_Object CC_sfto_dcontentf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v7, v8;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v7 = v0;
/* end of prologue */
    v8 = v7;
    v7 = nil;
    {
        fn = elt(env, 1); /* sfto_dcontentf1 */
        return (*qfn2(fn))(qenv(fn), v8, v7);
    }
}



/* Code for sortcolelem */

static Lisp_Object MS_CDECL CC_sortcolelem(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v16,
                         Lisp_Object v63, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v120, v226;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "sortcolelem");
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
    stack[0] = nil;
    v120 = stack[-2];
    v120 = qcdr(v120);
    stack[-4] = v120;
    goto v1;

v1:
    v120 = stack[0];
    if (v120 == nil) goto v25;
    v120 = nil;
    { popv(6); return onevalue(v120); }

v25:
    v120 = stack[-4];
    if (v120 == nil) goto v29;
    v226 = stack[-3];
    v120 = stack[-4];
    v120 = qcar(v120);
    v120 = qcar(v120);
    v120 = (Lisp_Object)lessp2(v226, v120);
    nil = C_nil;
    if (exception_pending()) goto v456;
    v120 = v120 ? lisp_true : nil;
    env = stack[-5];
    if (v120 == nil) goto v60;
    stack[0] = stack[-2];
    v226 = stack[-3];
    v120 = stack[-1];
    v120 = cons(v226, v120);
    nil = C_nil;
    if (exception_pending()) goto v456;
    env = stack[-5];
    v226 = ncons(v120);
    nil = C_nil;
    if (exception_pending()) goto v456;
    env = stack[-5];
    v120 = stack[-4];
    v120 = Lrplacd(nil, v226, v120);
    nil = C_nil;
    if (exception_pending()) goto v456;
    env = stack[-5];
    v120 = Lrplacd(nil, stack[0], v120);
    nil = C_nil;
    if (exception_pending()) goto v456;
    env = stack[-5];
    v120 = lisp_true;
    stack[0] = v120;
    goto v1;

v60:
    v226 = stack[-3];
    v120 = stack[-4];
    v120 = qcar(v120);
    v120 = qcar(v120);
    v120 = (Lisp_Object)greaterp2(v226, v120);
    nil = C_nil;
    if (exception_pending()) goto v456;
    v120 = v120 ? lisp_true : nil;
    env = stack[-5];
    if (v120 == nil) goto v1;
    v120 = nil;
    stack[0] = v120;
    v120 = stack[-2];
    v120 = qcdr(v120);
    stack[-2] = v120;
    v120 = stack[-2];
    v120 = qcdr(v120);
    stack[-4] = v120;
    goto v1;

v29:
    stack[0] = stack[-2];
    v226 = stack[-3];
    v120 = stack[-1];
    v120 = cons(v226, v120);
    nil = C_nil;
    if (exception_pending()) goto v456;
    env = stack[-5];
    v120 = ncons(v120);
    nil = C_nil;
    if (exception_pending()) goto v456;
    env = stack[-5];
    v120 = Lrplacd(nil, stack[0], v120);
    nil = C_nil;
    if (exception_pending()) goto v456;
    env = stack[-5];
    v120 = lisp_true;
    stack[0] = v120;
    goto v1;
/* error exit handlers */
v456:
    popv(6);
    return nil;
}



/* Code for downwght */

static Lisp_Object CC_downwght(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v13, v24;
    Lisp_Object fn;
    CSL_IGNORE(nil);
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
    v13 = stack[-1];
    fn = elt(env, 1); /* delhisto */
    v13 = (*qfn1(fn))(qenv(fn), v13);
    nil = C_nil;
    if (exception_pending()) goto v28;
    env = stack[-2];
    v24 = stack[-1];
    v13 = stack[0];
    fn = elt(env, 2); /* downwght1 */
    v13 = (*qfn2(fn))(qenv(fn), v24, v13);
    nil = C_nil;
    if (exception_pending()) goto v28;
    env = stack[-2];
    v13 = stack[-1];
    {
        popv(3);
        fn = elt(env, 3); /* inshisto */
        return (*qfn1(fn))(qenv(fn), v13);
    }
/* error exit handlers */
v28:
    popv(3);
    return nil;
}



/* Code for diplength */

static Lisp_Object CC_diplength(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v48, v33;
    CSL_IGNORE(nil);
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
    CSL_IGNORE(nil);
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
    CSL_IGNORE(nil);
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



/* Code for getphystype!*sq */

static Lisp_Object CC_getphystypeHsq(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v12;
    Lisp_Object fn;
    CSL_IGNORE(nil);
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
    CSL_IGNORE(nil);
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
    CSL_IGNORE(nil);
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
    CSL_IGNORE(nil);
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
    {   int32_t w = int_of_fixnum(v52);
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



/* Code for mathml */

static Lisp_Object MS_CDECL CC_mathml(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v45;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "mathml");
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* end of prologue */
    fn = elt(env, 1); /* lex */
    v45 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v5;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* sub_math */
        return (*qfnn(fn))(qenv(fn), 0);
    }
/* error exit handlers */
v5:
    popv(1);
    return nil;
}



/* Code for multi_elem */

static Lisp_Object CC_multi_elem(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v19, v20;
    Lisp_Object fn;
    CSL_IGNORE(nil);
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
    v19 = stack[0];
    v20 = Llength(nil, v19);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-1];
    v19 = (Lisp_Object)17; /* 1 */
    if (v20 == v19) goto v12;
    v19 = stack[0];
    v19 = qcar(v19);
    fn = elt(env, 1); /* expression */
    v19 = (*qfn1(fn))(qenv(fn), v19);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-1];
    v19 = stack[0];
    v19 = qcdr(v19);
    v19 = CC_multi_elem(env, v19);
    nil = C_nil;
    if (exception_pending()) goto v22;
    goto v4;

v4:
    v19 = nil;
    { popv(2); return onevalue(v19); }

v12:
    v19 = stack[0];
    v19 = qcar(v19);
    fn = elt(env, 1); /* expression */
    v19 = (*qfn1(fn))(qenv(fn), v19);
    nil = C_nil;
    if (exception_pending()) goto v22;
    goto v4;
/* error exit handlers */
v22:
    popv(2);
    return nil;
}



/* Code for xdegree */

static Lisp_Object CC_xdegree(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v25, v13;
    Lisp_Object fn;
    CSL_IGNORE(nil);
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
    CSL_IGNORE(nil);
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
    CSL_IGNORE(nil);
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



setup_type const u11_setup[] =
{
    {"evaluate-in-order",       too_few_2,      CC_evaluateKinKorder,wrong_no_2},
    {"rdprep1",                 CC_rdprep1,     too_many_1,    wrong_no_1},
    {"fullcopy",                CC_fullcopy,    too_many_1,    wrong_no_1},
    {"dm-difference",           too_few_2,      CC_dmKdifference,wrong_no_2},
    {"copy_mat",                CC_copy_mat,    too_many_1,    wrong_no_1},
    {"vevtdeg",                 CC_vevtdeg,     too_many_1,    wrong_no_1},
    {"xdiv",                    too_few_2,      CC_xdiv,       wrong_no_2},
    {":times",                  too_few_2,      CC_Ttimes,     wrong_no_2},
    {"physopsim*",              CC_physopsimH,  too_many_1,    wrong_no_1},
    {"mo_sum",                  too_few_2,      CC_mo_sum,     wrong_no_2},
    {"pv_add",                  too_few_2,      CC_pv_add,     wrong_no_2},
    {"copy",                    CC_copy,        too_many_1,    wrong_no_1},
    {"indent*",                 CC_indentH,     too_many_1,    wrong_no_1},
    {"multi_isarb_compl",       CC_multi_isarb_compl,too_many_1,wrong_no_1},
    {"equal:",                  too_few_2,      CC_equalT,     wrong_no_2},
    {"evlexcomp",               too_few_2,      CC_evlexcomp,  wrong_no_2},
    {"chundexp",                CC_chundexp,    too_many_1,    wrong_no_1},
    {"delallasc",               too_few_2,      CC_delallasc,  wrong_no_2},
    {"*physopp*",               CC_HphysoppH,   too_many_1,    wrong_no_1},
    {"nonzero-length",          CC_nonzeroKlength,too_many_1,  wrong_no_1},
    {"mo_compare",              too_few_2,      CC_mo_compare, wrong_no_2},
    {"cdiv",                    too_few_2,      CC_cdiv,       wrong_no_2},
    {"insert_pv",               too_few_2,      CC_insert_pv,  wrong_no_2},
    {"general-modular-number",  CC_generalKmodularKnumber,too_many_1,wrong_no_1},
    {"tayexp-minusp",           CC_tayexpKminusp,too_many_1,   wrong_no_1},
    {"multi_isarb_int",         CC_multi_isarb_int,too_many_1, wrong_no_1},
    {"rd:minus",                CC_rdTminus,    too_many_1,    wrong_no_1},
    {"on1",                     CC_on1,         too_many_1,    wrong_no_1},
    {"evtdeg",                  CC_evtdeg,      too_many_1,    wrong_no_1},
    {"groebsearchinlist",       too_few_2,      CC_groebsearchinlist,wrong_no_2},
    {"find_item",               too_few_2,      CC_find_item,  wrong_no_2},
    {"csl_timbf",               too_few_2,      CC_csl_timbf,  wrong_no_2},
    {":plus",                   too_few_2,      CC_Tplus,      wrong_no_2},
    {"freeofdepl",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_freeofdepl},
    {"idlistp",                 CC_idlistp,     too_many_1,    wrong_no_1},
    {"sroad",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_sroad},
    {"dp=ecart",                CC_dpMecart,    too_many_1,    wrong_no_1},
    {"pv_sort1",                too_few_2,      CC_pv_sort1,   wrong_no_2},
    {"gen-mult-by-const-mod-p", too_few_2,      CC_genKmultKbyKconstKmodKp,wrong_no_2},
    {"c:ordexp",                too_few_2,      CC_cTordexp,   wrong_no_2},
    {"times-mod-p",             too_few_2,      CC_timesKmodKp,wrong_no_2},
    {"tayexp-difference",       too_few_2,      CC_tayexpKdifference,wrong_no_2},
    {"get+col+nr",              CC_getLcolLnr,  too_many_1,    wrong_no_1},
    {"list2string",             CC_list2string, too_many_1,    wrong_no_1},
    {"findrow",                 too_few_2,      CC_findrow,    wrong_no_2},
    {"nextarg",                 CC_nextarg,     too_many_1,    wrong_no_1},
    {"off1",                    CC_off1,        too_many_1,    wrong_no_1},
    {"atomf",                   CC_atomf,       too_many_1,    wrong_no_1},
    {"maxdeg",                  too_few_2,      CC_maxdeg,     wrong_no_2},
    {"noncommuting",            too_few_2,      CC_noncommuting,wrong_no_2},
    {"repeatsp",                CC_repeatsp,    too_many_1,    wrong_no_1},
    {"bc=simp",                 CC_bcMsimp,     too_many_1,    wrong_no_1},
    {"pv_applp",                too_few_2,      CC_pv_applp,   wrong_no_2},
    {"rntimes:",                too_few_2,      CC_rntimesT,   wrong_no_2},
    {"*modular2f",              CC_Hmodular2f,  too_many_1,    wrong_no_1},
    {"divide:",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_divideT},
    {"praddf",                  too_few_2,      CC_praddf,     wrong_no_2},
    {"powers2",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_powers2},
    {"find",                    too_few_2,      CC_find,       wrong_no_2},
    {"mkwedge",                 CC_mkwedge,     too_many_1,    wrong_no_1},
    {"noncommutingf",           too_few_2,      CC_noncommutingf,wrong_no_2},
    {"mo=lexcomp",              too_few_2,      CC_moMlexcomp, wrong_no_2},
    {"insert_pv1",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_insert_pv1},
    {"mod#",                    CC_modC,        too_many_1,    wrong_no_1},
    {"convprec*",               CC_convprecH,   too_many_1,    wrong_no_1},
    {"tayexp-min2",             too_few_2,      CC_tayexpKmin2,wrong_no_2},
    {"pnthxzz",                 too_few_2,      CC_pnthxzz,    wrong_no_2},
    {"fast_unchecked_getmatelem",CC_fast_unchecked_getmatelem,too_many_1,wrong_no_1},
    {"physopp*",                CC_physoppH,    too_many_1,    wrong_no_1},
    {"red_divtestbe",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_red_divtestbe},
    {"gperm1",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_gperm1},
    {"removev",                 too_few_2,      CC_removev,    wrong_no_2},
    {"ps:evaluate",             too_few_2,      CC_psTevaluate,wrong_no_2},
    {"subscriptedvarp",         CC_subscriptedvarp,too_many_1, wrong_no_1},
    {"bound",                   CC_bound,       too_many_1,    wrong_no_1},
    {"deg*farg",                CC_degHfarg,    too_many_1,    wrong_no_1},
    {"abs:",                    CC_absT,        too_many_1,    wrong_no_1},
    {"dp_diff",                 too_few_2,      CC_dp_diff,    wrong_no_2},
    {"pv_sort2a",               too_few_2,      CC_pv_sort2a,  wrong_no_2},
    {"modplus:",                too_few_2,      CC_modplusT,   wrong_no_2},
    {"mkgi",                    too_few_2,      CC_mkgi,       wrong_no_2},
    {"omobj",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_omobj},
    {"red-char-downcase",       CC_redKcharKdowncase,too_many_1,wrong_no_1},
    {"dp_times_bc",             too_few_2,      CC_dp_times_bc,wrong_no_2},
    {"tsym4",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_tsym4},
    {"wulessp",                 too_few_2,      CC_wulessp,    wrong_no_2},
    {"sfto_dcontentf",          CC_sfto_dcontentf,too_many_1,  wrong_no_1},
    {"sortcolelem",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_sortcolelem},
    {"downwght",                too_few_2,      CC_downwght,   wrong_no_2},
    {"diplength",               CC_diplength,   too_many_1,    wrong_no_1},
    {"mknwedge",                CC_mknwedge,    too_many_1,    wrong_no_1},
    {"worderp",                 too_few_2,      CC_worderp,    wrong_no_2},
    {"getphystype*sq",          CC_getphystypeHsq,too_many_1,  wrong_no_1},
    {"groeb=testa",             too_few_2,      CC_groebMtesta,wrong_no_2},
    {"gperm",                   CC_gperm,       too_many_1,    wrong_no_1},
    {"minus-mod-p",             CC_minusKmodKp, too_many_1,    wrong_no_1},
    {"mathml",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_mathml},
    {"multi_elem",              CC_multi_elem,  too_many_1,    wrong_no_1},
    {"xdegree",                 CC_xdegree,     too_many_1,    wrong_no_1},
    {"boundindp",               too_few_2,      CC_boundindp,  wrong_no_2},
    {"dp_sum",                  too_few_2,      CC_dp_sum,     wrong_no_2},
    {NULL, (one_args *)"u11", (two_args *)"17958 9565357 861877", 0}
};

/* end of generated code */
