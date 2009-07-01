
/* $destdir/generated-c\u03.c Machine generated C code */

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


/* Code for simptimes */

static Lisp_Object CC_simptimes(Lisp_Object env,
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
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0;
/* end of prologue */
    stack[-2] = nil;
    v143 = stack[-1];
    if (v143 == nil) goto v24;
    v144 = qvalue(elt(env, 1)); /* tstack!* */
    v143 = (Lisp_Object)1; /* 0 */
    v143 = Lneq(nil, v144, v143);
    nil = C_nil;
    if (exception_pending()) goto v81;
    env = stack[-3];
    if (!(v143 == nil)) goto v12;
    v143 = qvalue(elt(env, 2)); /* mul!* */
    if (v143 == nil) goto v12;
    v143 = qvalue(elt(env, 2)); /* mul!* */
    stack[-2] = v143;
    v143 = nil;
    qvalue(elt(env, 2)) = v143; /* mul!* */
    goto v12;

v12:
    v143 = qvalue(elt(env, 1)); /* tstack!* */
    v143 = add1(v143);
    nil = C_nil;
    if (exception_pending()) goto v81;
    env = stack[-3];
    qvalue(elt(env, 1)) = v143; /* tstack!* */
    v143 = stack[-1];
    fn = elt(env, 4); /* simpcar */
    v143 = (*qfn1(fn))(qenv(fn), v143);
    nil = C_nil;
    if (exception_pending()) goto v81;
    env = stack[-3];
    stack[0] = v143;
    goto v45;

v45:
    v143 = stack[-1];
    v143 = qcdr(v143);
    stack[-1] = v143;
    v143 = stack[0];
    v143 = qcar(v143);
    if (v143 == nil) goto v6;
    v143 = stack[-1];
    if (v143 == nil) goto v5;
    v143 = stack[-1];
    fn = elt(env, 4); /* simpcar */
    v143 = (*qfn1(fn))(qenv(fn), v143);
    nil = C_nil;
    if (exception_pending()) goto v81;
    env = stack[-3];
    fn = elt(env, 5); /* multsq */
    v143 = (*qfn2(fn))(qenv(fn), stack[0], v143);
    nil = C_nil;
    if (exception_pending()) goto v81;
    env = stack[-3];
    stack[0] = v143;
    goto v45;

v5:
    v143 = qvalue(elt(env, 2)); /* mul!* */
    if (v143 == nil) goto v6;
    v144 = qvalue(elt(env, 1)); /* tstack!* */
    v143 = (Lisp_Object)17; /* 1 */
    v143 = (Lisp_Object)greaterp2(v144, v143);
    nil = C_nil;
    if (exception_pending()) goto v81;
    v143 = v143 ? lisp_true : nil;
    env = stack[-3];
    if (!(v143 == nil)) goto v6;
    v143 = qvalue(elt(env, 2)); /* mul!* */
    v144 = qcar(v143);
    v143 = stack[0];
    v143 = Lapply1(nil, v144, v143);
    nil = C_nil;
    if (exception_pending()) goto v81;
    env = stack[-3];
    stack[0] = v143;
    v143 = nil;
    v143 = ncons(v143);
    nil = C_nil;
    if (exception_pending()) goto v81;
    env = stack[-3];
    qvalue(elt(env, 3)) = v143; /* alglist!* */
    v143 = qvalue(elt(env, 2)); /* mul!* */
    v143 = qcdr(v143);
    qvalue(elt(env, 2)) = v143; /* mul!* */
    goto v5;

v6:
    v143 = qvalue(elt(env, 1)); /* tstack!* */
    v143 = sub1(v143);
    nil = C_nil;
    if (exception_pending()) goto v81;
    env = stack[-3];
    qvalue(elt(env, 1)) = v143; /* tstack!* */
    v144 = qvalue(elt(env, 1)); /* tstack!* */
    v143 = (Lisp_Object)1; /* 0 */
    if (!(v144 == v143)) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v143 = stack[-2];
    qvalue(elt(env, 2)) = v143; /* mul!* */
    { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }

v24:
    v144 = (Lisp_Object)17; /* 1 */
    v143 = (Lisp_Object)17; /* 1 */
    popv(4);
    return cons(v144, v143);
/* error exit handlers */
v81:
    popv(4);
    return nil;
}



/* Code for exchk2 */

static Lisp_Object CC_exchk2(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v97, v118, v135;
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
    v97 = stack[-1];
    if (v97 == nil) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v97 = stack[-1];
    v97 = qcdr(v97);
    stack[-2] = v97;
    v97 = stack[-1];
    v97 = qcar(v97);
    v97 = qcdr(v97);
    fn = elt(env, 6); /* prepsqx */
    v97 = (*qfn1(fn))(qenv(fn), v97);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-3];
    v135 = v97;
    v118 = (Lisp_Object)17; /* 1 */
    if (v135 == v118) goto v21;
    v118 = qvalue(elt(env, 1)); /* !*nosqrts */
    if (v118 == nil) goto v134;
    v135 = elt(env, 2); /* expt */
    v118 = stack[-1];
    v118 = qcar(v118);
    v118 = qcar(v118);
    v97 = list3(v135, v118, v97);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-3];
    v118 = v97;
    goto v38;

v38:
    v97 = stack[0];
    v97 = cons(v118, v97);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-3];
    stack[0] = v97;
    v97 = stack[-2];
    stack[-1] = v97;
    goto v12;

v134:
    v135 = v97;
    v118 = elt(env, 3); /* (quotient 1 2) */
    if (equal(v135, v118)) goto v66;
    v135 = v97;
    v118 = elt(env, 5); /* 0.5 */
    if (equal(v135, v118)) goto v85;
    v135 = elt(env, 2); /* expt */
    v118 = stack[-1];
    v118 = qcar(v118);
    v118 = qcar(v118);
    v97 = list3(v135, v118, v97);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-3];
    v118 = v97;
    goto v38;

v85:
    v118 = elt(env, 4); /* sqrt */
    v97 = stack[-1];
    v97 = qcar(v97);
    v97 = qcar(v97);
    v97 = list2(v118, v97);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-3];
    v118 = v97;
    goto v38;

v66:
    v118 = elt(env, 4); /* sqrt */
    v97 = stack[-1];
    v97 = qcar(v97);
    v97 = qcar(v97);
    v97 = list2(v118, v97);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-3];
    v118 = v97;
    goto v38;

v21:
    v97 = stack[-1];
    v97 = qcar(v97);
    v97 = qcar(v97);
    v118 = v97;
    goto v38;
/* error exit handlers */
v113:
    popv(4);
    return nil;
}



/* Code for eolcheck */

static Lisp_Object MS_CDECL CC_eolcheck(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v46, v31;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "eolcheck");
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* end of prologue */
    v46 = qvalue(elt(env, 1)); /* !*eoldelimp */
    if (!(v46 == nil)) goto v24;
    v46 = nil;
    { popv(1); return onevalue(v46); }

v24:
    v31 = qvalue(elt(env, 2)); /* nxtsym!* */
    v46 = qvalue(elt(env, 3)); /* !$eol!$ */
    if (v31 == v46) goto v18;
    v46 = nil;
    { popv(1); return onevalue(v46); }

v18:
    v31 = qvalue(elt(env, 4)); /* cursym!* */
    v46 = elt(env, 5); /* end */
    if (v31 == v46) goto v29;
    fn = elt(env, 7); /* token */
    v46 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[0];
    goto v43;

v43:
    qvalue(elt(env, 2)) = v46; /* nxtsym!* */
    goto v24;

v29:
    v46 = elt(env, 6); /* !; */
    goto v43;
/* error exit handlers */
v32:
    popv(1);
    return nil;
}



/* Code for quotf1 */

static Lisp_Object CC_quotf1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v242, v243;
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
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-6] = v16;
    stack[-7] = v0;
/* end of prologue */
    v242 = stack[-7];
    if (v242 == nil) goto v4;
    v243 = stack[-7];
    v242 = stack[-6];
    if (equal(v243, v242)) goto v6;
    v243 = stack[-6];
    v242 = (Lisp_Object)17; /* 1 */
    if (v243 == v242) { Lisp_Object res = stack[-7]; popv(10); return onevalue(res); }
    v242 = stack[-6];
    if (!consp(v242)) goto v14;
    v242 = stack[-6];
    v242 = qcar(v242);
    if (!consp(v242)) goto v14;
    v242 = stack[-7];
    if (!consp(v242)) goto v33;
    v242 = stack[-7];
    v242 = qcar(v242);
    if (!consp(v242)) goto v33;
    v242 = stack[-7];
    v242 = qcar(v242);
    v242 = qcar(v242);
    v243 = qcar(v242);
    v242 = stack[-6];
    v242 = qcar(v242);
    v242 = qcar(v242);
    v242 = qcar(v242);
    if (v243 == v242) goto v34;
    v242 = stack[-7];
    v242 = qcar(v242);
    v242 = qcar(v242);
    v243 = qcar(v242);
    v242 = stack[-6];
    v242 = qcar(v242);
    v242 = qcar(v242);
    v242 = qcar(v242);
    fn = elt(env, 2); /* ordop */
    v242 = (*qfn2(fn))(qenv(fn), v243, v242);
    nil = C_nil;
    if (exception_pending()) goto v241;
    env = stack[-9];
    if (v242 == nil) goto v469;
    v243 = stack[-7];
    v242 = stack[-6];
    {
        popv(10);
        fn = elt(env, 3); /* quotk */
        return (*qfn2(fn))(qenv(fn), v243, v242);
    }

v469:
    v242 = nil;
    { popv(10); return onevalue(v242); }

v34:
    stack[-3] = nil;
    stack[-2] = nil;
    stack[-1] = nil;
    goto v103;

v103:
    v242 = stack[-7];
    fn = elt(env, 4); /* rank */
    v242 = (*qfn1(fn))(qenv(fn), v242);
    nil = C_nil;
    if (exception_pending()) goto v241;
    env = stack[-9];
    stack[-4] = v242;
    if (symbolp(v242)) goto v220;
    v242 = stack[-6];
    fn = elt(env, 4); /* rank */
    v242 = (*qfn1(fn))(qenv(fn), v242);
    nil = C_nil;
    if (exception_pending()) goto v241;
    env = stack[-9];
    stack[0] = v242;
    if (symbolp(v242)) goto v220;
    v243 = stack[-4];
    v242 = stack[0];
    v242 = (Lisp_Object)lessp2(v243, v242);
    nil = C_nil;
    if (exception_pending()) goto v241;
    v242 = v242 ? lisp_true : nil;
    env = stack[-9];
    if (!(v242 == nil)) goto v220;
    v242 = stack[-7];
    fn = elt(env, 5); /* lt!* */
    v242 = (*qfn1(fn))(qenv(fn), v242);
    nil = C_nil;
    if (exception_pending()) goto v241;
    env = stack[-9];
    stack[-4] = v242;
    v242 = stack[-6];
    fn = elt(env, 5); /* lt!* */
    v242 = (*qfn1(fn))(qenv(fn), v242);
    nil = C_nil;
    if (exception_pending()) goto v241;
    env = stack[-9];
    stack[0] = v242;
    v242 = stack[-6];
    v242 = qcar(v242);
    v242 = qcar(v242);
    v242 = qcar(v242);
    stack[-8] = v242;
    v242 = stack[-4];
    v243 = qcdr(v242);
    v242 = stack[0];
    v242 = qcdr(v242);
    v242 = CC_quotf1(env, v243, v242);
    nil = C_nil;
    if (exception_pending()) goto v241;
    env = stack[-9];
    stack[-5] = v242;
    v242 = stack[-5];
    if (v242 == nil) goto v223;
    v242 = stack[-4];
    v242 = qcar(v242);
    v243 = qcdr(v242);
    v242 = stack[0];
    v242 = qcar(v242);
    v242 = qcdr(v242);
    v242 = difference2(v243, v242);
    nil = C_nil;
    if (exception_pending()) goto v241;
    env = stack[-9];
    stack[0] = v242;
    v243 = stack[0];
    v242 = (Lisp_Object)1; /* 0 */
    v242 = Lneq(nil, v243, v242);
    nil = C_nil;
    if (exception_pending()) goto v241;
    env = stack[-9];
    if (v242 == nil) goto v92;
    v243 = stack[-8];
    v242 = stack[0];
    fn = elt(env, 6); /* to */
    v242 = (*qfn2(fn))(qenv(fn), v243, v242);
    nil = C_nil;
    if (exception_pending()) goto v241;
    env = stack[-9];
    stack[-3] = v242;
    goto v92;

v92:
    v242 = stack[-5];
    fn = elt(env, 7); /* negf */
    v243 = (*qfn1(fn))(qenv(fn), v242);
    nil = C_nil;
    if (exception_pending()) goto v241;
    env = stack[-9];
    v242 = stack[-6];
    v242 = qcdr(v242);
    fn = elt(env, 8); /* multf */
    v242 = (*qfn2(fn))(qenv(fn), v243, v242);
    nil = C_nil;
    if (exception_pending()) goto v241;
    env = stack[-9];
    stack[-4] = v242;
    v242 = stack[-7];
    stack[-7] = qcdr(v242);
    v243 = stack[0];
    v242 = (Lisp_Object)1; /* 0 */
    if (v243 == v242) goto v462;
    v243 = stack[-3];
    v242 = (Lisp_Object)17; /* 1 */
    v242 = cons(v243, v242);
    nil = C_nil;
    if (exception_pending()) goto v241;
    env = stack[-9];
    v243 = ncons(v242);
    nil = C_nil;
    if (exception_pending()) goto v241;
    env = stack[-9];
    v242 = stack[-4];
    fn = elt(env, 8); /* multf */
    v242 = (*qfn2(fn))(qenv(fn), v243, v242);
    nil = C_nil;
    if (exception_pending()) goto v241;
    env = stack[-9];
    goto v88;

v88:
    fn = elt(env, 9); /* addf */
    v242 = (*qfn2(fn))(qenv(fn), stack[-7], v242);
    nil = C_nil;
    if (exception_pending()) goto v241;
    env = stack[-9];
    stack[-7] = v242;
    v242 = stack[-7];
    if (v242 == nil) goto v470;
    v242 = stack[-7];
    if (!consp(v242)) goto v471;
    v242 = stack[-7];
    v242 = qcar(v242);
    if (!consp(v242)) goto v471;
    v242 = stack[-7];
    v242 = qcar(v242);
    v242 = qcar(v242);
    v243 = qcar(v242);
    v242 = stack[-8];
    if (!(v243 == v242)) goto v471;

v470:
    v243 = stack[0];
    v242 = (Lisp_Object)1; /* 0 */
    if (v243 == v242) goto v59;
    stack[0] = stack[-2];
    v243 = stack[-3];
    v242 = stack[-5];
    v242 = cons(v243, v242);
    nil = C_nil;
    if (exception_pending()) goto v241;
    env = stack[-9];
    fn = elt(env, 10); /* aconc!* */
    v242 = (*qfn2(fn))(qenv(fn), stack[0], v242);
    nil = C_nil;
    if (exception_pending()) goto v241;
    env = stack[-9];
    stack[-2] = v242;
    v242 = stack[-7];
    if (!(v242 == nil)) goto v103;
    v242 = stack[-1];
    if (v242 == nil) { Lisp_Object res = stack[-2]; popv(10); return onevalue(res); }
    v243 = stack[-2];
    v242 = stack[-1];
    {
        popv(10);
        fn = elt(env, 11); /* rnconc */
        return (*qfn2(fn))(qenv(fn), v243, v242);
    }

v59:
    v242 = stack[-7];
    if (v242 == nil) goto v303;
    v242 = qvalue(elt(env, 1)); /* !*mcd */
    if (v242 == nil) goto v472;
    v242 = nil;
    { popv(10); return onevalue(v242); }

v472:
    v242 = stack[-5];
    stack[-1] = v242;
    goto v103;

v303:
    v243 = stack[-2];
    v242 = stack[-5];
    {
        popv(10);
        fn = elt(env, 11); /* rnconc */
        return (*qfn2(fn))(qenv(fn), v243, v242);
    }

v471:
    v242 = nil;
    { popv(10); return onevalue(v242); }

v462:
    v242 = stack[-4];
    goto v88;

v223:
    v242 = nil;
    { popv(10); return onevalue(v242); }

v220:
    v242 = nil;
    { popv(10); return onevalue(v242); }

v33:
    v242 = nil;
    { popv(10); return onevalue(v242); }

v14:
    v243 = stack[-7];
    v242 = stack[-6];
    {
        popv(10);
        fn = elt(env, 12); /* quotfd */
        return (*qfn2(fn))(qenv(fn), v243, v242);
    }

v6:
    v242 = (Lisp_Object)17; /* 1 */
    { popv(10); return onevalue(v242); }

v4:
    v242 = nil;
    { popv(10); return onevalue(v242); }
/* error exit handlers */
v241:
    popv(10);
    return nil;
}



/* Code for layout!-formula */

static Lisp_Object MS_CDECL CC_layoutKformula(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v16,
                         Lisp_Object v63, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v234, v112;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "layout-formula");
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
    stack[-9] = qvalue(elt(env, 1)); /* ycoord!* */
    qvalue(elt(env, 1)) = nil; /* ycoord!* */
    stack[-5] = qvalue(elt(env, 2)); /* ymin!* */
    qvalue(elt(env, 2)) = nil; /* ymin!* */
    stack[-4] = qvalue(elt(env, 3)); /* ymax!* */
    qvalue(elt(env, 3)) = nil; /* ymax!* */
    stack[-3] = qvalue(elt(env, 4)); /* posn!* */
    qvalue(elt(env, 4)) = nil; /* posn!* */
    stack[-2] = qvalue(elt(env, 5)); /* pline!* */
    qvalue(elt(env, 5)) = nil; /* pline!* */
    stack[-1] = qvalue(elt(env, 6)); /* testing!-width!* */
    qvalue(elt(env, 6)) = nil; /* testing!-width!* */
    stack[0] = qvalue(elt(env, 7)); /* overflowed!* */
    qvalue(elt(env, 7)) = nil; /* overflowed!* */
    v234 = nil;
    qvalue(elt(env, 7)) = v234; /* overflowed!* */
    qvalue(elt(env, 5)) = v234; /* pline!* */
    v234 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 3)) = v234; /* ymax!* */
    qvalue(elt(env, 2)) = v234; /* ymin!* */
    qvalue(elt(env, 1)) = v234; /* ycoord!* */
    v234 = qvalue(elt(env, 8)); /* orig!* */
    qvalue(elt(env, 4)) = v234; /* posn!* */
    v234 = lisp_true;
    qvalue(elt(env, 6)) = v234; /* testing!-width!* */
    v234 = stack[-6];
    if (v234 == nil) goto v32;
    v112 = stack[-6];
    v234 = elt(env, 9); /* inbrackets */
    if (v112 == v234) goto v43;
    v234 = stack[-6];
    fn = elt(env, 12); /* oprin */
    v234 = (*qfn1(fn))(qenv(fn), v234);
    nil = C_nil;
    if (exception_pending()) goto v237;
    env = stack[-10];
    goto v32;

v32:
    v112 = stack[-8];
    v234 = stack[-7];
    fn = elt(env, 13); /* maprint */
    v234 = (*qfn2(fn))(qenv(fn), v112, v234);
    nil = C_nil;
    if (exception_pending()) goto v237;
    env = stack[-10];
    v112 = stack[-6];
    v234 = elt(env, 9); /* inbrackets */
    if (!(v112 == v234)) goto v50;
    v234 = elt(env, 11); /* ")" */
    fn = elt(env, 14); /* prin2!* */
    v234 = (*qfn1(fn))(qenv(fn), v234);
    nil = C_nil;
    if (exception_pending()) goto v237;
    env = stack[-10];
    goto v50;

v50:
    v234 = qvalue(elt(env, 7)); /* overflowed!* */
    if (v234 == nil) goto v70;
    v234 = nil;
    goto v1;

v1:
    qvalue(elt(env, 7)) = stack[0]; /* overflowed!* */
    qvalue(elt(env, 6)) = stack[-1]; /* testing!-width!* */
    qvalue(elt(env, 5)) = stack[-2]; /* pline!* */
    qvalue(elt(env, 4)) = stack[-3]; /* posn!* */
    qvalue(elt(env, 3)) = stack[-4]; /* ymax!* */
    qvalue(elt(env, 2)) = stack[-5]; /* ymin!* */
    qvalue(elt(env, 1)) = stack[-9]; /* ycoord!* */
    { popv(11); return onevalue(v234); }

v70:
    stack[-7] = qvalue(elt(env, 5)); /* pline!* */
    v112 = qvalue(elt(env, 4)); /* posn!* */
    v234 = qvalue(elt(env, 8)); /* orig!* */
    stack[-6] = difference2(v112, v234);
    nil = C_nil;
    if (exception_pending()) goto v237;
    env = stack[-10];
    v112 = qvalue(elt(env, 2)); /* ymin!* */
    v234 = qvalue(elt(env, 3)); /* ymax!* */
    v234 = cons(v112, v234);
    nil = C_nil;
    if (exception_pending()) goto v237;
    env = stack[-10];
    v234 = acons(stack[-7], stack[-6], v234);
    nil = C_nil;
    if (exception_pending()) goto v237;
    env = stack[-10];
    goto v1;

v43:
    v234 = elt(env, 10); /* "(" */
    fn = elt(env, 14); /* prin2!* */
    v234 = (*qfn1(fn))(qenv(fn), v234);
    nil = C_nil;
    if (exception_pending()) goto v237;
    env = stack[-10];
    goto v32;
/* error exit handlers */
v237:
    env = stack[-10];
    qvalue(elt(env, 7)) = stack[0]; /* overflowed!* */
    qvalue(elt(env, 6)) = stack[-1]; /* testing!-width!* */
    qvalue(elt(env, 5)) = stack[-2]; /* pline!* */
    qvalue(elt(env, 4)) = stack[-3]; /* posn!* */
    qvalue(elt(env, 3)) = stack[-4]; /* ymax!* */
    qvalue(elt(env, 2)) = stack[-5]; /* ymin!* */
    qvalue(elt(env, 1)) = stack[-9]; /* ycoord!* */
    popv(11);
    return nil;
}



/* Code for isimp1 */

static Lisp_Object MS_CDECL CC_isimp1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v16,
                         Lisp_Object v63, Lisp_Object v9,
                         Lisp_Object v3, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v230, v468, v149, v111, v216;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 5, "isimp1");
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
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v3;
    stack[-1] = v9;
    stack[-2] = v63;
    stack[-3] = v16;
    stack[-4] = v0;
/* end of prologue */
    v230 = stack[-4];
    if (v230 == nil) goto v5;
    v230 = stack[-4];
    if (!consp(v230)) goto v1;
    v230 = stack[-4];
    v230 = qcar(v230);
    if (!consp(v230)) goto v1;
    v230 = stack[-4];
    v216 = qcar(v230);
    v111 = stack[-3];
    v149 = stack[-2];
    v468 = stack[-1];
    v230 = stack[0];
    fn = elt(env, 3); /* isimp2 */
    stack[-5] = (*qfnn(fn))(qenv(fn), 5, v216, v111, v149, v468, v230);
    nil = C_nil;
    if (exception_pending()) goto v92;
    env = stack[-6];
    v230 = stack[-4];
    v216 = qcdr(v230);
    v111 = stack[-3];
    v149 = stack[-2];
    v468 = stack[-1];
    v230 = stack[0];
    v230 = CC_isimp1(env, 5, v216, v111, v149, v468, v230);
    nil = C_nil;
    if (exception_pending()) goto v92;
    env = stack[-6];
    {
        Lisp_Object v225 = stack[-5];
        popv(7);
        fn = elt(env, 4); /* addf */
        return (*qfn2(fn))(qenv(fn), v225, v230);
    }

v1:
    v230 = stack[0];
    if (v230 == nil) goto v47;
    v230 = stack[0];
    v216 = qcar(v230);
    v111 = stack[-3];
    v149 = stack[-2];
    v468 = stack[-1];
    v230 = stack[0];
    v230 = qcdr(v230);
    fn = elt(env, 5); /* spur0 */
    v230 = (*qfnn(fn))(qenv(fn), 5, v216, v111, v149, v468, v230);
    nil = C_nil;
    if (exception_pending()) goto v92;
    env = stack[-6];
    {
        Lisp_Object v189 = stack[-4];
        popv(7);
        fn = elt(env, 6); /* multd */
        return (*qfn2(fn))(qenv(fn), v189, v230);
    }

v47:
    v230 = stack[-2];
    if (v230 == nil) goto v35;
    stack[-3] = elt(env, 1); /* hephys */
    stack[-1] = (Lisp_Object)97; /* 6 */
    stack[0] = elt(env, 2); /* "Unmatched index" */
    v230 = stack[-2];
    fn = elt(env, 7); /* mapovercar */
    v230 = (*qfn1(fn))(qenv(fn), v230);
    nil = C_nil;
    if (exception_pending()) goto v92;
    env = stack[-6];
    v230 = cons(stack[0], v230);
    nil = C_nil;
    if (exception_pending()) goto v92;
    env = stack[-6];
    {
        Lisp_Object v109 = stack[-3];
        Lisp_Object v110 = stack[-1];
        popv(7);
        fn = elt(env, 8); /* rerror */
        return (*qfnn(fn))(qenv(fn), 3, v109, v110, v230);
    }

v35:
    v230 = stack[-1];
    if (v230 == nil) { Lisp_Object res = stack[-4]; popv(7); return onevalue(res); }
    v230 = stack[-1];
    fn = elt(env, 9); /* emult */
    stack[-1] = (*qfn1(fn))(qenv(fn), v230);
    nil = C_nil;
    if (exception_pending()) goto v92;
    env = stack[-6];
    v216 = stack[-4];
    v111 = stack[-3];
    v149 = stack[-2];
    v468 = nil;
    v230 = stack[0];
    v230 = CC_isimp1(env, 5, v216, v111, v149, v468, v230);
    nil = C_nil;
    if (exception_pending()) goto v92;
    env = stack[-6];
    {
        Lisp_Object v215 = stack[-1];
        popv(7);
        fn = elt(env, 10); /* multf */
        return (*qfn2(fn))(qenv(fn), v215, v230);
    }

v5:
    v230 = nil;
    { popv(7); return onevalue(v230); }
/* error exit handlers */
v92:
    popv(7);
    return nil;
}



/* Code for quotk */

static Lisp_Object CC_quotk(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v57, v72, v122;
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
    v57 = stack[-1];
    v57 = qcar(v57);
    v72 = qcdr(v57);
    v57 = stack[0];
    fn = elt(env, 1); /* quotf1 */
    v57 = (*qfn2(fn))(qenv(fn), v72, v57);
    nil = C_nil;
    if (exception_pending()) goto v103;
    env = stack[-3];
    stack[-2] = v57;
    v57 = stack[-2];
    if (v57 == nil) goto v70;
    v57 = stack[-1];
    v57 = qcdr(v57);
    if (v57 == nil) goto v18;
    v57 = stack[-1];
    v72 = qcdr(v57);
    v57 = stack[0];
    fn = elt(env, 1); /* quotf1 */
    v57 = (*qfn2(fn))(qenv(fn), v72, v57);
    nil = C_nil;
    if (exception_pending()) goto v103;
    v72 = v57;
    if (v72 == nil) goto v54;
    v72 = stack[-1];
    v72 = qcar(v72);
    v122 = qcar(v72);
    v72 = stack[-2];
    popv(4);
    return acons(v122, v72, v57);

v54:
    v57 = nil;
    { popv(4); return onevalue(v57); }

v18:
    v57 = stack[-1];
    v57 = qcar(v57);
    v72 = qcar(v57);
    v57 = stack[-2];
    v57 = cons(v72, v57);
    nil = C_nil;
    if (exception_pending()) goto v103;
    popv(4);
    return ncons(v57);

v70:
    v57 = nil;
    { popv(4); return onevalue(v57); }
/* error exit handlers */
v103:
    popv(4);
    return nil;
}



/* Code for mcharg1 */

static Lisp_Object MS_CDECL CC_mcharg1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v16,
                         Lisp_Object v63, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v232, v127, v186;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "mcharg1");
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
    v232 = stack[-3];
    if (!(v232 == nil)) goto v25;
    v232 = stack[-2];
    if (!(v232 == nil)) goto v25;
    v232 = nil;
    popv(6);
    return ncons(v232);

v25:
    v232 = stack[-3];
    v232 = Llength(nil, v232);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-5];
    stack[-4] = v232;
    v232 = stack[-2];
    v232 = Llength(nil, v232);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-5];
    stack[0] = v232;
    v127 = stack[-1];
    v232 = elt(env, 1); /* nary */
    v232 = Lflagp(nil, v127, v232);
    env = stack[-5];
    if (v232 == nil) goto v144;
    v127 = stack[-4];
    v232 = (Lisp_Object)33; /* 2 */
    v232 = (Lisp_Object)greaterp2(v127, v232);
    nil = C_nil;
    if (exception_pending()) goto v94;
    v232 = v232 ? lisp_true : nil;
    env = stack[-5];
    if (v232 == nil) goto v144;
    v127 = stack[-4];
    v232 = qvalue(elt(env, 2)); /* matchlength!* */
    v232 = (Lisp_Object)lesseq2(v127, v232);
    nil = C_nil;
    if (exception_pending()) goto v94;
    v232 = v232 ? lisp_true : nil;
    env = stack[-5];
    if (v232 == nil) goto v220;
    v127 = stack[-1];
    v232 = elt(env, 3); /* symmetric */
    v232 = Lflagp(nil, v127, v232);
    env = stack[-5];
    if (v232 == nil) goto v220;
    v186 = stack[-3];
    v127 = stack[-2];
    v232 = stack[-1];
    {
        popv(6);
        fn = elt(env, 4); /* mchcomb */
        return (*qfnn(fn))(qenv(fn), 3, v186, v127, v232);
    }

v220:
    v127 = stack[0];
    v232 = (Lisp_Object)33; /* 2 */
    if (v127 == v232) goto v141;
    v232 = nil;
    { popv(6); return onevalue(v232); }

v141:
    v127 = stack[-1];
    v232 = stack[-3];
    fn = elt(env, 5); /* mkbin */
    v232 = (*qfn2(fn))(qenv(fn), v127, v232);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-5];
    v232 = qcdr(v232);
    stack[-3] = v232;
    v232 = (Lisp_Object)33; /* 2 */
    stack[-4] = v232;
    goto v144;

v144:
    v127 = stack[-4];
    v232 = stack[0];
    v232 = Lneq(nil, v127, v232);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-5];
    if (v232 == nil) goto v113;
    v232 = nil;
    { popv(6); return onevalue(v232); }

v113:
    v127 = stack[-1];
    v232 = elt(env, 3); /* symmetric */
    v232 = Lflagp(nil, v127, v232);
    env = stack[-5];
    if (v232 == nil) goto v98;
    v186 = stack[-3];
    v127 = stack[-2];
    v232 = stack[-1];
    {
        popv(6);
        fn = elt(env, 6); /* mchsarg */
        return (*qfnn(fn))(qenv(fn), 3, v186, v127, v232);
    }

v98:
    v232 = stack[-2];
    fn = elt(env, 7); /* mtp */
    v232 = (*qfn1(fn))(qenv(fn), v232);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-5];
    if (v232 == nil) goto v76;
    v127 = stack[-2];
    v232 = stack[-3];
    fn = elt(env, 8); /* pair */
    v232 = (*qfn2(fn))(qenv(fn), v127, v232);
    nil = C_nil;
    if (exception_pending()) goto v94;
    popv(6);
    return ncons(v232);

v76:
    stack[0] = stack[-3];
    v232 = nil;
    v127 = ncons(v232);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-5];
    v232 = stack[-1];
    {
        Lisp_Object v212 = stack[0];
        Lisp_Object v462 = stack[-2];
        popv(6);
        fn = elt(env, 9); /* mcharg2 */
        return (*qfnn(fn))(qenv(fn), 4, v212, v462, v127, v232);
    }
/* error exit handlers */
v94:
    popv(6);
    return nil;
}



/* Code for setel */

static Lisp_Object CC_setel(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v54, v87, v66, v70;
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
    v54 = stack[-2];
    v87 = qcar(v54);
    v54 = elt(env, 1); /* dimension */
    v54 = get(v87, v54);
    env = stack[-4];
    stack[-3] = v54;
    v54 = stack[-3];
    stack[0] = Llength(nil, v54);
    nil = C_nil;
    if (exception_pending()) goto v122;
    env = stack[-4];
    v54 = stack[-2];
    v54 = qcdr(v54);
    v54 = Llength(nil, v54);
    nil = C_nil;
    if (exception_pending()) goto v122;
    env = stack[-4];
    v54 = Lneq(nil, stack[0], v54);
    nil = C_nil;
    if (exception_pending()) goto v122;
    env = stack[-4];
    if (v54 == nil) goto v34;
    v66 = elt(env, 2); /* rlisp */
    v87 = (Lisp_Object)353; /* 22 */
    v54 = elt(env, 3); /* "Incorrect array reference" */
    {
        popv(5);
        fn = elt(env, 5); /* rerror */
        return (*qfnn(fn))(qenv(fn), 3, v66, v87, v54);
    }

v34:
    v54 = stack[-2];
    v87 = qcar(v54);
    v54 = elt(env, 4); /* avalue */
    v54 = get(v87, v54);
    env = stack[-4];
    v54 = qcdr(v54);
    v70 = qcar(v54);
    v54 = stack[-2];
    v66 = qcdr(v54);
    v87 = stack[-1];
    v54 = stack[-3];
    {
        popv(5);
        fn = elt(env, 6); /* setel1 */
        return (*qfnn(fn))(qenv(fn), 4, v70, v66, v87, v54);
    }
/* error exit handlers */
v122:
    popv(5);
    return nil;
}



/* Code for sub2chk */

static Lisp_Object CC_sub2chk(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v23, v30, v99;
    CSL_IGNORE(nil);
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v99 = v0;
/* end of prologue */
    v23 = qvalue(elt(env, 1)); /* subfg!* */
    if (v23 == nil) goto v4;
    v30 = v99;
    v23 = qvalue(elt(env, 2)); /* powlis!* */
    v23 = Latsoc(nil, v30, v23);
    if (!(v23 == nil)) goto v3;
    v23 = v99;
    if (!consp(v23)) goto v4;
    v23 = v99;
    v30 = qcar(v23);
    v23 = elt(env, 3); /* (expt sqrt) */
    v23 = Lmemq(nil, v30, v23);
    if (!(v23 == nil)) goto v3;

v4:
    v23 = nil;
    return onevalue(v23);

v3:
    v23 = lisp_true;
    qvalue(elt(env, 4)) = v23; /* !*sub2 */
    return onevalue(v23);
}



/* Code for appn */

static Lisp_Object CC_appn(Lisp_Object env,
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
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v16;
    stack[-1] = v0;
/* end of prologue */
    stack[-2] = nil;
    goto v25;

v25:
    v193 = stack[0];
    v52 = (Lisp_Object)17; /* 1 */
    if (v193 == v52) goto v5;
    v193 = stack[-1];
    v52 = stack[-2];
    v52 = cons(v193, v52);
    nil = C_nil;
    if (exception_pending()) goto v40;
    env = stack[-3];
    stack[-2] = v52;
    v52 = stack[0];
    v52 = sub1(v52);
    nil = C_nil;
    if (exception_pending()) goto v40;
    env = stack[-3];
    stack[0] = v52;
    goto v25;

v5:
    v52 = stack[-1];
    v193 = v52;
    goto v6;

v6:
    v52 = stack[-2];
    if (v52 == nil) { popv(4); return onevalue(v193); }
    v52 = stack[-2];
    v52 = qcar(v52);
    v52 = Lappend(nil, v52, v193);
    nil = C_nil;
    if (exception_pending()) goto v40;
    env = stack[-3];
    v193 = v52;
    v52 = stack[-2];
    v52 = qcdr(v52);
    stack[-2] = v52;
    goto v6;
/* error exit handlers */
v40:
    popv(4);
    return nil;
}



/* Code for lt!* */

static Lisp_Object CC_ltH(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v71, v101, v57;
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
    v71 = qvalue(elt(env, 1)); /* !*mcd */
    if (!(v71 == nil)) goto v3;
    v71 = stack[-1];
    v71 = qcar(v71);
    v71 = qcar(v71);
    v101 = qcdr(v71);
    v71 = (Lisp_Object)1; /* 0 */
    v71 = (Lisp_Object)greaterp2(v101, v71);
    nil = C_nil;
    if (exception_pending()) goto v55;
    v71 = v71 ? lisp_true : nil;
    env = stack[-3];
    if (!(v71 == nil)) goto v3;
    v71 = stack[-1];
    v71 = qcar(v71);
    stack[-2] = v71;
    v71 = stack[-1];
    v71 = qcar(v71);
    v71 = qcar(v71);
    v71 = qcar(v71);
    stack[0] = v71;
    goto v19;

v19:
    v71 = stack[-1];
    v71 = qcdr(v71);
    stack[-1] = v71;
    v71 = stack[-1];
    if (v71 == nil) { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
    v101 = stack[-1];
    v71 = stack[0];
    fn = elt(env, 2); /* degr */
    v101 = (*qfn2(fn))(qenv(fn), v101, v71);
    nil = C_nil;
    if (exception_pending()) goto v55;
    env = stack[-3];
    v71 = (Lisp_Object)1; /* 0 */
    if (!(v101 == v71)) goto v19;
    v57 = stack[0];
    v101 = (Lisp_Object)1; /* 0 */
    v71 = stack[-1];
    popv(4);
    return acons(v57, v101, v71);

v3:
    v71 = stack[-1];
    v71 = qcar(v71);
    { popv(4); return onevalue(v71); }
/* error exit handlers */
v55:
    popv(4);
    return nil;
}



/* Code for gadd */

static Lisp_Object MS_CDECL CC_gadd(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v16,
                         Lisp_Object v63, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v136, v233, v231;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "gadd");
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
    stack[-2] = v63;
    stack[-3] = v16;
    stack[-4] = v0;
/* end of prologue */
    stack[-5] = nil;
    v136 = (Lisp_Object)1; /* 0 */
    stack[0] = v136;
    v233 = stack[-2];
    v136 = stack[-3];
    v136 = Latsoc(nil, v233, v136);
    stack[-1] = v136;
    if (v136 == nil) goto v6;
    v233 = stack[-1];
    v136 = stack[-3];
    v136 = Ldelete(nil, v233, v136);
    nil = C_nil;
    if (exception_pending()) goto v326;
    env = stack[-6];
    stack[-3] = v136;
    v136 = stack[-1];
    v136 = qcdr(v136);
    v136 = qcdr(v136);
    stack[-5] = v136;
    v136 = stack[-1];
    v136 = qcdr(v136);
    v136 = qcar(v136);
    stack[-1] = v136;
    goto v6;

v6:
    v136 = stack[-4];
    if (v136 == nil) goto v42;
    v136 = stack[-4];
    v233 = qcar(v136);
    v136 = elt(env, 1); /* a */
    if (v233 == v136) goto v120;
    v136 = stack[-4];
    v233 = qcar(v136);
    v136 = stack[-5];
    v136 = cons(v233, v136);
    nil = C_nil;
    if (exception_pending()) goto v326;
    env = stack[-6];
    stack[-5] = v136;
    goto v7;

v7:
    v136 = stack[-4];
    v136 = qcdr(v136);
    stack[-4] = v136;
    goto v6;

v120:
    v233 = qvalue(elt(env, 2)); /* ndims!* */
    v136 = (Lisp_Object)65; /* 4 */
    v136 = Lneq(nil, v233, v136);
    nil = C_nil;
    if (exception_pending()) goto v326;
    env = stack[-6];
    if (v136 == nil) goto v141;
    v231 = elt(env, 3); /* hephys */
    v233 = (Lisp_Object)129; /* 8 */
    v136 = elt(env, 4); /* "Gamma5 not allowed unless vecdim is 4" */
    fn = elt(env, 5); /* rerror */
    v136 = (*qfnn(fn))(qenv(fn), 3, v231, v233, v136);
    nil = C_nil;
    if (exception_pending()) goto v326;
    env = stack[-6];
    goto v141;

v141:
    v136 = stack[-1];
    v136 = (v136 == nil ? lisp_true : nil);
    stack[-1] = v136;
    v136 = stack[-5];
    v233 = Llength(nil, v136);
    nil = C_nil;
    if (exception_pending()) goto v326;
    env = stack[-6];
    v136 = stack[0];
    v136 = plus2(v233, v136);
    nil = C_nil;
    if (exception_pending()) goto v326;
    env = stack[-6];
    stack[0] = v136;
    goto v7;

v42:
    v136 = stack[0];
    stack[0] = Levenp(nil, v136);
    env = stack[-6];
    v231 = stack[-2];
    v233 = stack[-1];
    v136 = stack[-5];
    v233 = list2star(v231, v233, v136);
    nil = C_nil;
    if (exception_pending()) goto v326;
    v136 = stack[-3];
    {
        Lisp_Object v327 = stack[0];
        popv(7);
        return list2star(v327, v233, v136);
    }
/* error exit handlers */
v326:
    popv(7);
    return nil;
}



/* Code for multdm */

static Lisp_Object CC_multdm(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v54, v87, v66;
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
    v87 = v16;
    v66 = v0;
/* end of prologue */
    v54 = v66;
    if (!(!consp(v54))) goto v134;
    v54 = v87;
    if (!(!consp(v54))) goto v134;
    v54 = v66;
    v54 = times2(v54, v87);
    nil = C_nil;
    if (exception_pending()) goto v70;
    env = stack[0];
    v66 = v54;
    v54 = qvalue(elt(env, 1)); /* dmode!* */
    if (v54 == nil) { popv(1); return onevalue(v66); }
    v87 = qvalue(elt(env, 1)); /* dmode!* */
    v54 = elt(env, 2); /* convert */
    v54 = Lflagp(nil, v87, v54);
    env = stack[0];
    if (v54 == nil) { popv(1); return onevalue(v66); }
    v87 = qvalue(elt(env, 1)); /* dmode!* */
    v54 = elt(env, 3); /* i2d */
    v54 = get(v87, v54);
    v87 = v66;
        popv(1);
        return Lapply1(nil, v54, v87);

v134:
    v54 = elt(env, 4); /* times */
    {
        popv(1);
        fn = elt(env, 5); /* dcombine */
        return (*qfnn(fn))(qenv(fn), 3, v66, v87, v54);
    }
/* error exit handlers */
v70:
    popv(1);
    return nil;
}



/* Code for !:minus */

static Lisp_Object CC_Tminus(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v35, v34, v39;
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
    v34 = v0;
/* end of prologue */
    v35 = v34;
    if (v35 == nil) goto v3;
    v35 = v34;
    if (!consp(v35)) goto v5;
    v35 = v34;
    v39 = qcar(v35);
    v35 = elt(env, 1); /* minus */
    v35 = get(v39, v35);
    env = stack[0];
    v39 = v35;
    v35 = v39;
    if (v35 == nil) goto v37;
    v35 = v39;
        popv(1);
        return Lapply1(nil, v35, v34);

v37:
    v39 = v34;
    v34 = (Lisp_Object)-15; /* -1 */
    v35 = elt(env, 2); /* times */
    {
        popv(1);
        fn = elt(env, 3); /* dcombine */
        return (*qfnn(fn))(qenv(fn), 3, v39, v34, v35);
    }

v5:
    v35 = v34;
    popv(1);
    return negate(v35);

v3:
    v35 = nil;
    { popv(1); return onevalue(v35); }
}



/* Code for isimp2 */

static Lisp_Object MS_CDECL CC_isimp2(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v16,
                         Lisp_Object v63, Lisp_Object v9,
                         Lisp_Object v3, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v124, v125, v473, v474, v188;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 5, "isimp2");
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
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v3;
    stack[-1] = v9;
    stack[-2] = v63;
    stack[-3] = v16;
    stack[-4] = v0;
/* end of prologue */
    v124 = stack[-4];
    v124 = qcar(v124);
    v124 = qcar(v124);
    stack[-5] = v124;
    if (!consp(v124)) goto v236;
    v124 = stack[-5];
    v125 = qcar(v124);
    v124 = elt(env, 1); /* cons */
    if (!(v125 == v124)) goto v100;
    v124 = stack[-5];
    v125 = qcdr(v124);
    v124 = stack[-3];
    fn = elt(env, 4); /* xnp */
    v124 = (*qfn2(fn))(qenv(fn), v125, v124);
    nil = C_nil;
    if (exception_pending()) goto v180;
    env = stack[-6];
    if (v124 == nil) goto v100;
    v188 = stack[-4];
    v474 = stack[-3];
    v473 = stack[-2];
    v125 = stack[-1];
    v124 = stack[0];
    {
        popv(7);
        fn = elt(env, 5); /* dotsum */
        return (*qfnn(fn))(qenv(fn), 5, v188, v474, v473, v125, v124);
    }

v100:
    v124 = stack[-5];
    v125 = qcar(v124);
    v124 = elt(env, 2); /* g */
    if (v125 == v124) goto v80;
    v124 = stack[-5];
    v125 = qcar(v124);
    v124 = elt(env, 3); /* eps */
    if (!(v125 == v124)) goto v236;
    v188 = stack[-4];
    v474 = stack[-3];
    v473 = stack[-2];
    v125 = stack[-1];
    v124 = stack[0];
    {
        popv(7);
        fn = elt(env, 6); /* esum */
        return (*qfnn(fn))(qenv(fn), 5, v188, v474, v473, v125, v124);
    }

v236:
    v124 = stack[-4];
    v125 = qcar(v124);
    v124 = (Lisp_Object)17; /* 1 */
    v124 = cons(v125, v124);
    nil = C_nil;
    if (exception_pending()) goto v180;
    env = stack[-6];
    stack[-5] = ncons(v124);
    nil = C_nil;
    if (exception_pending()) goto v180;
    env = stack[-6];
    v124 = stack[-4];
    v188 = qcdr(v124);
    v474 = stack[-3];
    v473 = stack[-2];
    v125 = stack[-1];
    v124 = stack[0];
    fn = elt(env, 7); /* isimp1 */
    v124 = (*qfnn(fn))(qenv(fn), 5, v188, v474, v473, v125, v124);
    nil = C_nil;
    if (exception_pending()) goto v180;
    env = stack[-6];
    {
        Lisp_Object v199 = stack[-5];
        popv(7);
        fn = elt(env, 8); /* multf */
        return (*qfn2(fn))(qenv(fn), v199, v124);
    }

v80:
    v124 = stack[-5];
    v124 = qcdr(v124);
    v125 = qcdr(v124);
    v124 = stack[-4];
    v124 = qcar(v124);
    v124 = qcdr(v124);
    fn = elt(env, 9); /* appn */
    v473 = (*qfn2(fn))(qenv(fn), v125, v124);
    nil = C_nil;
    if (exception_pending()) goto v180;
    env = stack[-6];
    v125 = stack[0];
    v124 = stack[-5];
    v124 = qcdr(v124);
    v124 = qcar(v124);
    fn = elt(env, 10); /* gadd */
    v124 = (*qfnn(fn))(qenv(fn), 3, v473, v125, v124);
    nil = C_nil;
    if (exception_pending()) goto v180;
    env = stack[-6];
    stack[-5] = v124;
    v124 = stack[-5];
    v124 = qcar(v124);
    fn = elt(env, 11); /* nb */
    v125 = (*qfn1(fn))(qenv(fn), v124);
    nil = C_nil;
    if (exception_pending()) goto v180;
    env = stack[-6];
    v124 = stack[-4];
    v124 = qcdr(v124);
    fn = elt(env, 12); /* multd!* */
    v188 = (*qfn2(fn))(qenv(fn), v125, v124);
    nil = C_nil;
    if (exception_pending()) goto v180;
    env = stack[-6];
    v474 = stack[-3];
    v473 = stack[-2];
    v125 = stack[-1];
    v124 = stack[-5];
    v124 = qcdr(v124);
    {
        popv(7);
        fn = elt(env, 7); /* isimp1 */
        return (*qfnn(fn))(qenv(fn), 5, v188, v474, v473, v125, v124);
    }
/* error exit handlers */
v180:
    popv(7);
    return nil;
}



/* Code for exchk1 */

static Lisp_Object MS_CDECL CC_exchk1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v16,
                         Lisp_Object v63, Lisp_Object v9, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v347, v476, v204, v174;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "exchk1");
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

v5:
    v347 = stack[-4];
    if (v347 == nil) goto v44;
    v347 = stack[-4];
    v347 = qcar(v347);
    v476 = qcar(v347);
    v347 = elt(env, 1); /* expt */
    if (!consp(v476)) goto v227;
    v476 = qcar(v476);
    if (!(v476 == v347)) goto v227;
    v204 = elt(env, 2); /* times */
    v347 = stack[-4];
    v347 = qcar(v347);
    v476 = qcdr(v347);
    v347 = stack[-4];
    v347 = qcar(v347);
    v347 = qcar(v347);
    v347 = qcdr(v347);
    v347 = qcdr(v347);
    v347 = qcar(v347);
    v347 = list3(v204, v476, v347);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-6];
    fn = elt(env, 3); /* simpexpon */
    v347 = (*qfn1(fn))(qenv(fn), v347);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-6];
    stack[-5] = v347;
    v347 = stack[-4];
    v347 = qcar(v347);
    v347 = qcar(v347);
    v347 = qcdr(v347);
    v347 = qcar(v347);
    if (is_number(v347)) goto v122;
    v347 = stack[-4];
    v347 = qcar(v347);
    v347 = qcar(v347);
    v347 = qcdr(v347);
    v476 = qcar(v347);
    v347 = stack[-2];
    v347 = Lassoc(nil, v476, v347);
    v476 = v347;
    if (v476 == nil) goto v109;
    stack[0] = v347;
    v476 = stack[-5];
    v347 = qcdr(v347);
    fn = elt(env, 4); /* addsq */
    v347 = (*qfn2(fn))(qenv(fn), v476, v347);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-6];
    v347 = Lrplacd(nil, stack[0], v347);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-6];
    goto v212;

v212:
    v347 = stack[-4];
    v174 = qcdr(v347);
    v204 = stack[-3];
    v476 = stack[-2];
    v347 = stack[-1];
    stack[-4] = v174;
    stack[-3] = v204;
    stack[-2] = v476;
    stack[-1] = v347;
    goto v5;

v109:
    v347 = stack[-4];
    v347 = qcar(v347);
    v347 = qcar(v347);
    v347 = qcdr(v347);
    v204 = qcar(v347);
    v476 = stack[-5];
    v347 = stack[-2];
    v347 = acons(v204, v476, v347);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-6];
    stack[-2] = v347;
    goto v212;

v122:
    v476 = stack[-5];
    v347 = stack[-1];
    fn = elt(env, 5); /* assoc2 */
    v347 = (*qfn2(fn))(qenv(fn), v476, v347);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-6];
    v476 = v347;
    if (v476 == nil) goto v191;
    stack[0] = v347;
    v476 = qcar(v347);
    v347 = stack[-4];
    v347 = qcar(v347);
    v347 = qcar(v347);
    v347 = qcdr(v347);
    v347 = qcar(v347);
    v347 = times2(v476, v347);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-6];
    v347 = Lrplaca(nil, stack[0], v347);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-6];
    goto v212;

v191:
    v347 = stack[-4];
    v347 = qcar(v347);
    v347 = qcar(v347);
    v347 = qcdr(v347);
    v204 = qcar(v347);
    v476 = stack[-5];
    v347 = stack[-1];
    v347 = acons(v204, v476, v347);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-6];
    stack[-1] = v347;
    goto v212;

v227:
    v347 = stack[-4];
    v347 = qcar(v347);
    v476 = qcdr(v347);
    v347 = (Lisp_Object)17; /* 1 */
    if (v476 == v347) goto v180;
    v347 = stack[-4];
    v347 = qcdr(v347);
    stack[-5] = v347;
    stack[0] = elt(env, 1); /* expt */
    v347 = stack[-4];
    v347 = qcar(v347);
    v347 = qcar(v347);
    fn = elt(env, 6); /* sqchk */
    v476 = (*qfn1(fn))(qenv(fn), v347);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-6];
    v347 = stack[-4];
    v347 = qcar(v347);
    v347 = qcdr(v347);
    v476 = list3(stack[0], v476, v347);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-6];
    v347 = stack[-3];
    v347 = cons(v476, v347);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-6];
    stack[-3] = v347;
    v347 = stack[-5];
    stack[-4] = v347;
    goto v5;

v180:
    v347 = stack[-4];
    v347 = qcdr(v347);
    stack[-5] = v347;
    v347 = stack[-4];
    v347 = qcar(v347);
    v347 = qcar(v347);
    fn = elt(env, 6); /* sqchk */
    v476 = (*qfn1(fn))(qenv(fn), v347);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-6];
    v347 = stack[-3];
    v347 = cons(v476, v347);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-6];
    stack[-3] = v347;
    v347 = stack[-5];
    stack[-4] = v347;
    goto v5;

v44:
    v476 = stack[-1];
    v347 = stack[-2];
    v476 = Lappend(nil, v476, v347);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-6];
    v347 = stack[-3];
    {
        popv(7);
        fn = elt(env, 7); /* exchk2 */
        return (*qfn2(fn))(qenv(fn), v476, v347);
    }
/* error exit handlers */
v305:
    popv(7);
    return nil;
}



/* Code for xcomment */

static Lisp_Object CC_xcomment(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v29, v17, v18;
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
    v18 = v16;
    v17 = v0;
/* end of prologue */
    v29 = v18;
    if (v29 == nil) { popv(2); return onevalue(v17); }
    stack[0] = elt(env, 1); /* comment */
    v29 = v18;
    v29 = Lnreverse(nil, v29);
    env = stack[-1];
    fn = elt(env, 2); /* aconc */
    v29 = (*qfn2(fn))(qenv(fn), v29, v17);
    nil = C_nil;
    if (exception_pending()) goto v20;
    env = stack[-1];
    v29 = cons(stack[0], v29);
    nil = C_nil;
    if (exception_pending()) goto v20;
    v17 = v29;
    { popv(2); return onevalue(v17); }
/* error exit handlers */
v20:
    popv(2);
    return nil;
}



/* Code for lnc */

static Lisp_Object CC_lnc(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v43, v29;
    CSL_IGNORE(nil);
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v43 = v0;
/* end of prologue */

v3:
    v29 = v43;
    if (v29 == nil) goto v45;
    v29 = v43;
    if (!consp(v29)) return onevalue(v43);
    v29 = v43;
    v29 = qcar(v29);
    if (!consp(v29)) return onevalue(v43);
    v43 = qcar(v43);
    v43 = qcdr(v43);
    goto v3;

v45:
    v43 = (Lisp_Object)1; /* 0 */
    return onevalue(v43);
}



/* Code for gcdf */

static Lisp_Object CC_gcdf(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v67, v68;
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
    stack[-3] = qvalue(elt(env, 1)); /* !*exp */
    qvalue(elt(env, 1)) = nil; /* !*exp */
    stack[0] = qvalue(elt(env, 2)); /* !*rounded */
    qvalue(elt(env, 2)) = nil; /* !*rounded */
    v67 = lisp_true;
    qvalue(elt(env, 1)) = v67; /* !*exp */
    v67 = stack[-2];
    if (!consp(v67)) goto v10;
    v67 = stack[-2];
    v67 = qcar(v67);
    if (!consp(v67)) goto v10;
    v67 = stack[-1];
    if (!consp(v67)) goto v10;
    v67 = stack[-1];
    v67 = qcar(v67);
    if (!consp(v67)) goto v10;
    v67 = qvalue(elt(env, 3)); /* !*ezgcd */
    if (v67 == nil) goto v10;
    v67 = qvalue(elt(env, 4)); /* dmode!* */
    if (!(v67 == nil)) goto v10;
    v67 = stack[-2];
    fn = elt(env, 5); /* free!-powerp */
    v67 = (*qfn1(fn))(qenv(fn), v67);
    nil = C_nil;
    if (exception_pending()) goto v70;
    env = stack[-4];
    if (!(v67 == nil)) goto v10;
    v67 = stack[-1];
    fn = elt(env, 5); /* free!-powerp */
    v67 = (*qfn1(fn))(qenv(fn), v67);
    nil = C_nil;
    if (exception_pending()) goto v70;
    env = stack[-4];
    if (!(v67 == nil)) goto v10;
    v68 = stack[-2];
    v67 = stack[-1];
    fn = elt(env, 6); /* ezgcdf */
    v67 = (*qfn2(fn))(qenv(fn), v68, v67);
    nil = C_nil;
    if (exception_pending()) goto v70;
    env = stack[-4];
    goto v6;

v6:
    stack[-2] = v67;
    v67 = stack[-2];
    fn = elt(env, 7); /* minusf */
    v67 = (*qfn1(fn))(qenv(fn), v67);
    nil = C_nil;
    if (exception_pending()) goto v70;
    env = stack[-4];
    if (v67 == nil) goto v134;
    v67 = stack[-2];
    fn = elt(env, 8); /* negf */
    v67 = (*qfn1(fn))(qenv(fn), v67);
    nil = C_nil;
    if (exception_pending()) goto v70;
    env = stack[-4];
    goto v12;

v12:
    qvalue(elt(env, 2)) = stack[0]; /* !*rounded */
    qvalue(elt(env, 1)) = stack[-3]; /* !*exp */
    { popv(5); return onevalue(v67); }

v134:
    v67 = stack[-2];
    goto v12;

v10:
    v68 = stack[-2];
    v67 = stack[-1];
    fn = elt(env, 9); /* gcdf1 */
    v67 = (*qfn2(fn))(qenv(fn), v68, v67);
    nil = C_nil;
    if (exception_pending()) goto v70;
    env = stack[-4];
    goto v6;
/* error exit handlers */
v70:
    env = stack[-4];
    qvalue(elt(env, 2)) = stack[0]; /* !*rounded */
    qvalue(elt(env, 1)) = stack[-3]; /* !*exp */
    popv(5);
    return nil;
}



/* Code for mkarray1 */

static Lisp_Object CC_mkarray1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v58, v55;
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
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-4] = v16;
    stack[-5] = v0;
/* end of prologue */
    v58 = stack[-5];
    if (v58 == nil) goto v1;
    v58 = stack[-5];
    v58 = qcar(v58);
    v58 = sub1(v58);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-7];
    stack[-6] = v58;
    v58 = stack[-6];
    v58 = Lmkvect(nil, v58);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-7];
    stack[-3] = v58;
    v58 = (Lisp_Object)1; /* 0 */
    stack[-2] = v58;
    goto v42;

v42:
    v55 = stack[-6];
    v58 = stack[-2];
    v58 = difference2(v55, v58);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-7];
    v58 = Lminusp(nil, v58);
    env = stack[-7];
    if (!(v58 == nil)) { Lisp_Object res = stack[-3]; popv(8); return onevalue(res); }
    stack[-1] = stack[-3];
    stack[0] = stack[-2];
    v58 = stack[-5];
    v55 = qcdr(v58);
    v58 = stack[-4];
    v58 = CC_mkarray1(env, v55, v58);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-7];
    *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)stack[0]/(16/CELL))) = v58;
    v58 = stack[-2];
    v58 = add1(v58);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-7];
    stack[-2] = v58;
    goto v42;

v1:
    v58 = stack[-4];
    v55 = elt(env, 1); /* symbolic */
    if (v58 == v55) goto v7;
    v58 = (Lisp_Object)1; /* 0 */
    { popv(8); return onevalue(v58); }

v7:
    v58 = nil;
    { popv(8); return onevalue(v58); }
/* error exit handlers */
v106:
    popv(8);
    return nil;
}



/* Code for smemqlp */

static Lisp_Object CC_smemqlp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v64, v100;
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
    v64 = stack[0];
    if (v64 == nil) goto v4;
    v64 = stack[0];
    if (is_number(v64)) goto v4;
    v64 = stack[0];
    if (!consp(v64)) goto v13;
    v64 = stack[0];
    v100 = qcar(v64);
    v64 = elt(env, 1); /* quote */
    if (v100 == v64) goto v15;
    v100 = stack[-1];
    v64 = stack[0];
    v64 = qcar(v64);
    v64 = CC_smemqlp(env, v100, v64);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-2];
    if (!(v64 == nil)) { popv(3); return onevalue(v64); }
    v100 = stack[-1];
    v64 = stack[0];
    v64 = qcdr(v64);
    stack[-1] = v100;
    stack[0] = v64;
    goto v11;

v15:
    v64 = nil;
    { popv(3); return onevalue(v64); }

v13:
    v100 = stack[0];
    v64 = stack[-1];
    v64 = Lmemq(nil, v100, v64);
    { popv(3); return onevalue(v64); }

v4:
    v64 = nil;
    { popv(3); return onevalue(v64); }
/* error exit handlers */
v105:
    popv(3);
    return nil;
}



/* Code for formlis */

static Lisp_Object MS_CDECL CC_formlis(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v16,
                         Lisp_Object v63, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v53, v14, v46;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "formlis");
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
    stack[-3] = nil;
    goto v45;

v45:
    v53 = stack[-2];
    if (v53 == nil) goto v7;
    v53 = stack[-2];
    v46 = qcar(v53);
    v14 = stack[-1];
    v53 = stack[0];
    fn = elt(env, 1); /* form1 */
    v14 = (*qfnn(fn))(qenv(fn), 3, v46, v14, v53);
    nil = C_nil;
    if (exception_pending()) goto v48;
    env = stack[-4];
    v53 = stack[-3];
    v53 = cons(v14, v53);
    nil = C_nil;
    if (exception_pending()) goto v48;
    env = stack[-4];
    stack[-3] = v53;
    v53 = stack[-2];
    v53 = qcdr(v53);
    stack[-2] = v53;
    goto v45;

v7:
    v53 = stack[-3];
    {
        popv(5);
        fn = elt(env, 2); /* reversip!* */
        return (*qfn1(fn))(qenv(fn), v53);
    }
/* error exit handlers */
v48:
    popv(5);
    return nil;
}



/* Code for rank */

static Lisp_Object CC_rank(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v121, v143;
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
    stack[-2] = v0;
/* end of prologue */
    v121 = qvalue(elt(env, 1)); /* !*mcd */
    if (v121 == nil) goto v8;
    v121 = stack[-2];
    v121 = qcar(v121);
    v121 = qcar(v121);
    v121 = qcdr(v121);
    { popv(5); return onevalue(v121); }

v8:
    v121 = stack[-2];
    v121 = qcar(v121);
    v121 = qcar(v121);
    v121 = qcdr(v121);
    stack[-1] = v121;
    v121 = stack[-2];
    v121 = qcar(v121);
    v121 = qcar(v121);
    v121 = qcar(v121);
    stack[0] = v121;
    goto v27;

v27:
    v121 = stack[-2];
    v121 = qcar(v121);
    v121 = qcar(v121);
    v121 = qcdr(v121);
    stack[-3] = v121;
    v121 = stack[-2];
    v121 = qcdr(v121);
    if (v121 == nil) goto v32;
    v121 = stack[-2];
    v121 = qcdr(v121);
    stack[-2] = v121;
    v143 = stack[-2];
    v121 = stack[0];
    fn = elt(env, 2); /* degr */
    v143 = (*qfn2(fn))(qenv(fn), v143, v121);
    nil = C_nil;
    if (exception_pending()) goto v81;
    env = stack[-4];
    v121 = (Lisp_Object)1; /* 0 */
    if (!(v143 == v121)) goto v27;
    v143 = stack[-3];
    v121 = (Lisp_Object)1; /* 0 */
    v121 = (Lisp_Object)lessp2(v143, v121);
    nil = C_nil;
    if (exception_pending()) goto v81;
    v121 = v121 ? lisp_true : nil;
    env = stack[-4];
    if (v121 == nil) { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }
    v143 = stack[-1];
    v121 = (Lisp_Object)1; /* 0 */
    v121 = (Lisp_Object)lessp2(v143, v121);
    nil = C_nil;
    if (exception_pending()) goto v81;
    v121 = v121 ? lisp_true : nil;
    if (v121 == nil) goto v226;
    v121 = stack[-3];
    popv(5);
    return negate(v121);

v226:
    v143 = stack[-1];
    v121 = stack[-3];
    popv(5);
    return difference2(v143, v121);

v32:
    v143 = stack[-1];
    v121 = stack[-3];
    popv(5);
    return difference2(v143, v121);
/* error exit handlers */
v81:
    popv(5);
    return nil;
}



/* Code for subs3f */

static Lisp_Object CC_subs3f(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v2, v25, v13;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v2 = v0;
/* end of prologue */
    v13 = v2;
    v25 = qvalue(elt(env, 1)); /* !*match */
    v2 = lisp_true;
    {
        fn = elt(env, 2); /* subs3f1 */
        return (*qfnn(fn))(qenv(fn), 3, v13, v25, v2);
    }
}



/* Code for convertmode */

static Lisp_Object MS_CDECL CC_convertmode(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v16,
                         Lisp_Object v63, Lisp_Object v9, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v20, v21, v22, v23;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "convertmode");
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
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v9;
    stack[-1] = v63;
    stack[-2] = v16;
    v20 = v0;
/* end of prologue */
    v22 = v20;
    v21 = stack[-2];
    v20 = stack[0];
    fn = elt(env, 1); /* form1 */
    v23 = (*qfnn(fn))(qenv(fn), 3, v22, v21, v20);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-3];
    v22 = stack[-2];
    v21 = stack[-1];
    v20 = stack[0];
    {
        popv(4);
        fn = elt(env, 2); /* convertmode1 */
        return (*qfnn(fn))(qenv(fn), 4, v23, v22, v21, v20);
    }
/* error exit handlers */
v53:
    popv(4);
    return nil;
}



/* Code for mtchk */

static Lisp_Object CC_mtchk(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v467, v352, v184, v185;
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
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-7] = v16;
    stack[-8] = v0;
/* end of prologue */
    stack[-3] = nil;
    v467 = stack[-8];
    v467 = qcar(v467);
    fn = elt(env, 1); /* noncomp */
    v467 = (*qfn1(fn))(qenv(fn), v467);
    nil = C_nil;
    if (exception_pending()) goto v183;
    env = stack[-10];
    stack[-9] = v467;
    goto v8;

v8:
    v467 = stack[-7];
    if (v467 == nil) { Lisp_Object res = stack[-3]; popv(11); return onevalue(res); }
    v467 = stack[-7];
    v467 = qcar(v467);
    stack[-6] = v467;
    v467 = stack[-6];
    v467 = qcar(v467);
    stack[-5] = v467;
    goto v1;

v1:
    v467 = stack[-5];
    if (v467 == nil) goto v129;
    v185 = stack[-8];
    v467 = stack[-5];
    v184 = qcar(v467);
    v467 = stack[-6];
    v467 = qcdr(v467);
    v467 = qcar(v467);
    v352 = qcar(v467);
    v467 = stack[-6];
    v467 = qcdr(v467);
    v467 = qcar(v467);
    v467 = qcdr(v467);
    fn = elt(env, 2); /* mtchp1 */
    v467 = (*qfnn(fn))(qenv(fn), 4, v185, v184, v352, v467);
    nil = C_nil;
    if (exception_pending()) goto v183;
    env = stack[-10];
    stack[-4] = v467;
    goto v2;

v2:
    v467 = stack[-4];
    if (v467 == nil) goto v25;
    v467 = stack[-4];
    stack[0] = qcar(v467);
    v467 = stack[-5];
    v352 = qcar(v467);
    v467 = stack[-6];
    v467 = qcar(v467);
    v467 = Ldelete(nil, v352, v467);
    nil = C_nil;
    if (exception_pending()) goto v183;
    env = stack[-10];
    stack[-2] = Lsubla(nil, stack[0], v467);
    nil = C_nil;
    if (exception_pending()) goto v183;
    env = stack[-10];
    v467 = stack[-4];
    v352 = qcar(v467);
    v467 = stack[-6];
    v467 = qcdr(v467);
    v467 = qcar(v467);
    stack[-1] = Lsubla(nil, v352, v467);
    nil = C_nil;
    if (exception_pending()) goto v183;
    env = stack[-10];
    v467 = stack[-4];
    v352 = qcar(v467);
    v467 = stack[-6];
    v467 = qcdr(v467);
    v467 = qcdr(v467);
    v467 = qcar(v467);
    stack[0] = Lsubla(nil, v352, v467);
    nil = C_nil;
    if (exception_pending()) goto v183;
    env = stack[-10];
    v467 = stack[-4];
    v352 = qcar(v467);
    v467 = stack[-5];
    v467 = qcar(v467);
    v352 = Lsubla(nil, v352, v467);
    nil = C_nil;
    if (exception_pending()) goto v183;
    env = stack[-10];
    v467 = stack[-6];
    v467 = qcdr(v467);
    v467 = qcdr(v467);
    v467 = qcdr(v467);
    v467 = qcar(v467);
    v467 = cons(v352, v467);
    nil = C_nil;
    if (exception_pending()) goto v183;
    env = stack[-10];
    v467 = list2(stack[0], v467);
    nil = C_nil;
    if (exception_pending()) goto v183;
    env = stack[-10];
    v467 = list2star(stack[-2], stack[-1], v467);
    nil = C_nil;
    if (exception_pending()) goto v183;
    env = stack[-10];
    stack[0] = v467;
    v467 = qcar(v467);
    if (v467 == nil) goto v190;
    v352 = stack[0];
    v467 = stack[-3];
    v467 = cons(v352, v467);
    nil = C_nil;
    if (exception_pending()) goto v183;
    env = stack[-10];
    stack[-3] = v467;
    goto v64;

v64:
    v467 = stack[-4];
    v467 = qcdr(v467);
    stack[-4] = v467;
    goto v2;

v190:
    v467 = stack[-4];
    v352 = qcar(v467);
    v467 = stack[-6];
    v467 = qcdr(v467);
    v467 = qcar(v467);
    v467 = qcdr(v467);
    v467 = Lsubla(nil, v352, v467);
    nil = C_nil;
    if (exception_pending()) goto v183;
    env = stack[-10];
    fn = elt(env, 3); /* lispeval */
    v467 = (*qfn1(fn))(qenv(fn), v467);
    nil = C_nil;
    if (exception_pending()) goto v183;
    env = stack[-10];
    if (v467 == nil) goto v64;
    v467 = stack[0];
    popv(11);
    return ncons(v467);

v25:
    v467 = stack[-9];
    if (v467 == nil) goto v186;
    v467 = stack[-6];
    v467 = qcdr(v467);
    v467 = qcdr(v467);
    v467 = qcdr(v467);
    v467 = qcar(v467);
    if (v467 == nil) goto v129;
    v467 = stack[-5];
    fn = elt(env, 4); /* nocp */
    v467 = (*qfn1(fn))(qenv(fn), v467);
    nil = C_nil;
    if (exception_pending()) goto v183;
    env = stack[-10];
    if (!(v467 == nil)) goto v24;

v129:
    v352 = stack[-3];
    v467 = stack[-6];
    fn = elt(env, 5); /* aconc */
    v467 = (*qfn2(fn))(qenv(fn), v352, v467);
    nil = C_nil;
    if (exception_pending()) goto v183;
    env = stack[-10];
    stack[-3] = v467;
    goto v24;

v24:
    v467 = stack[-7];
    v467 = qcdr(v467);
    stack[-7] = v467;
    goto v8;

v186:
    v467 = stack[-5];
    v467 = qcdr(v467);
    stack[-5] = v467;
    goto v1;
/* error exit handlers */
v183:
    popv(11);
    return nil;
}



/* Code for mksq */

static Lisp_Object CC_mksq(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v162, v479, v246;
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
    stack[-4] = nil;
    stack[-1] = nil;
    v162 = qvalue(elt(env, 1)); /* subfg!* */
    if (v162 == nil) goto v6;
    v479 = stack[-3];
    v162 = qvalue(elt(env, 2)); /* wtl!* */
    v162 = Lassoc(nil, v479, v162);
    stack[-1] = v162;
    if (v162 == nil) goto v27;
    stack[0] = elt(env, 3); /* k!* */
    v479 = stack[-2];
    v162 = stack[-1];
    v162 = qcdr(v162);
    v162 = times2(v479, v162);
    nil = C_nil;
    if (exception_pending()) goto v262;
    env = stack[-5];
    v162 = CC_mksq(env, stack[0], v162);
    nil = C_nil;
    if (exception_pending()) goto v262;
    env = stack[-5];
    stack[-1] = v162;
    v162 = qcar(v162);
    if (v162 == nil) { Lisp_Object res = stack[-1]; popv(6); return onevalue(res); }
    else goto v27;

v27:
    v162 = stack[-3];
    if (!consp(v162)) goto v50;
    v162 = qvalue(elt(env, 4)); /* !*nosubs */
    if (!(v162 == nil)) goto v457;
    v162 = stack[-3];
    v162 = qcar(v162);
    if (!(!consp(v162))) goto v457;
    v162 = stack[-3];
    v479 = qcar(v162);
    v162 = elt(env, 11); /* mksqsubfn */
    v162 = get(v479, v162);
    env = stack[-5];
    v479 = v162;
    if (v162 == nil) goto v252;
    v162 = stack[-3];
    v162 = Lapply1(nil, v479, v162);
    nil = C_nil;
    if (exception_pending()) goto v262;
    env = stack[-5];
    v479 = v162;
    if (!(v162 == nil)) goto v8;

v252:
    v246 = stack[-3];
    v162 = stack[-3];
    v479 = qcar(v162);
    v162 = elt(env, 12); /* kvalue */
    v162 = get(v479, v162);
    env = stack[-5];
    v162 = Lassoc(nil, v246, v162);
    v479 = v162;
    if (!(v162 == nil)) goto v8;

v457:
    stack[0] = elt(env, 6); /* used!* */
    v162 = stack[-3];
    fn = elt(env, 14); /* fkern */
    v162 = (*qfn1(fn))(qenv(fn), v162);
    nil = C_nil;
    if (exception_pending()) goto v262;
    env = stack[-5];
    stack[-4] = v162;
    v162 = qcdr(v162);
    v162 = qcdr(v162);
    v162 = Lmemq(nil, stack[0], v162);
    if (!(v162 == nil)) goto v5;
    v479 = stack[-4];
    v162 = elt(env, 6); /* used!* */
    fn = elt(env, 15); /* aconc */
    v162 = (*qfn2(fn))(qenv(fn), v479, v162);
    nil = C_nil;
    if (exception_pending()) goto v262;
    env = stack[-5];
    goto v5;

v5:
    v162 = qvalue(elt(env, 4)); /* !*nosubs */
    if (!(v162 == nil)) goto v6;
    v479 = stack[-2];
    v162 = (Lisp_Object)17; /* 1 */
    if (v479 == v162) goto v6;
    v479 = stack[-3];
    v162 = qvalue(elt(env, 7)); /* asymplis!* */
    v162 = Lassoc(nil, v479, v162);
    v479 = v162;
    if (v162 == nil) goto v136;
    v162 = v479;
    v479 = qcdr(v162);
    v162 = stack[-2];
    v162 = (Lisp_Object)lesseq2(v479, v162);
    nil = C_nil;
    if (exception_pending()) goto v262;
    v162 = v162 ? lisp_true : nil;
    env = stack[-5];
    if (v162 == nil) goto v136;
    v479 = nil;
    v162 = (Lisp_Object)17; /* 1 */
    popv(6);
    return cons(v479, v162);

v136:
    v479 = stack[-3];
    v162 = qvalue(elt(env, 8)); /* powlis!* */
    v162 = Lassoc(nil, v479, v162);
    v479 = v162;
    if (!(v162 == nil)) goto v74;
    v162 = stack[-3];
    if (!consp(v162)) goto v6;
    v162 = stack[-3];
    v479 = qcar(v162);
    v162 = elt(env, 9); /* (expt sqrt) */
    v162 = Lmemq(nil, v479, v162);
    if (v162 == nil) goto v6;
    v162 = stack[-3];
    v162 = qcdr(v162);
    v479 = qcar(v162);
    v162 = qvalue(elt(env, 8)); /* powlis!* */
    v162 = Lassoc(nil, v479, v162);
    v479 = v162;
    if (!(v162 == nil)) goto v74;

v6:
    v162 = stack[-4];
    if (!(v162 == nil)) goto v352;
    v162 = stack[-3];
    fn = elt(env, 14); /* fkern */
    v162 = (*qfn1(fn))(qenv(fn), v162);
    nil = C_nil;
    if (exception_pending()) goto v262;
    env = stack[-5];
    stack[-4] = v162;
    goto v352;

v352:
    v479 = stack[-4];
    v162 = stack[-2];
    fn = elt(env, 16); /* getpower */
    v479 = (*qfn2(fn))(qenv(fn), v479, v162);
    nil = C_nil;
    if (exception_pending()) goto v262;
    env = stack[-5];
    v162 = (Lisp_Object)17; /* 1 */
    v162 = cons(v479, v162);
    nil = C_nil;
    if (exception_pending()) goto v262;
    env = stack[-5];
    v479 = ncons(v162);
    nil = C_nil;
    if (exception_pending()) goto v262;
    env = stack[-5];
    v162 = (Lisp_Object)17; /* 1 */
    v162 = cons(v479, v162);
    nil = C_nil;
    if (exception_pending()) goto v262;
    env = stack[-5];
    stack[-4] = v162;
    v162 = stack[-1];
    if (v162 == nil) { Lisp_Object res = stack[-4]; popv(6); return onevalue(res); }
    v479 = stack[-1];
    v162 = stack[-4];
    {
        popv(6);
        fn = elt(env, 17); /* multsq */
        return (*qfn2(fn))(qenv(fn), v479, v162);
    }

v74:
    v162 = stack[-2];
    v479 = qcdr(v479);
    v479 = qcar(v479);
    v479 = times2(v162, v479);
    nil = C_nil;
    if (exception_pending()) goto v262;
    env = stack[-5];
    v162 = (Lisp_Object)1; /* 0 */
    v162 = (Lisp_Object)lessp2(v479, v162);
    nil = C_nil;
    if (exception_pending()) goto v262;
    v162 = v162 ? lisp_true : nil;
    env = stack[-5];
    if (!(v162 == nil)) goto v6;
    v162 = lisp_true;
    qvalue(elt(env, 10)) = v162; /* !*sub2 */
    goto v6;

v8:
    v162 = v479;
    v162 = qcdr(v162);
    v479 = v162;
    v162 = qvalue(elt(env, 13)); /* !*resubs */
    if (!(v162 == nil)) goto v472;
    v162 = lisp_true;
    qvalue(elt(env, 4)) = v162; /* !*nosubs */
    goto v472;

v472:
    v162 = v479;
    fn = elt(env, 18); /* simpcar */
    v162 = (*qfn1(fn))(qenv(fn), v162);
    nil = C_nil;
    if (exception_pending()) goto v262;
    env = stack[-5];
    stack[-4] = v162;
    v162 = nil;
    qvalue(elt(env, 4)) = v162; /* !*nosubs */
    v479 = stack[-4];
    v162 = stack[-2];
    {
        popv(6);
        fn = elt(env, 19); /* exptsq */
        return (*qfn2(fn))(qenv(fn), v479, v162);
    }

v50:
    v162 = qvalue(elt(env, 4)); /* !*nosubs */
    if (!(v162 == nil)) goto v2;
    v479 = stack[-3];
    v162 = elt(env, 5); /* avalue */
    v162 = get(v479, v162);
    env = stack[-5];
    v479 = v162;
    if (!(v162 == nil)) goto v8;

v2:
    v162 = stack[-3];
    if (!(symbolp(v162))) goto v5;
    v162 = stack[-3];
    v479 = ncons(v162);
    nil = C_nil;
    if (exception_pending()) goto v262;
    env = stack[-5];
    v162 = elt(env, 6); /* used!* */
    v162 = Lflag(nil, v479, v162);
    nil = C_nil;
    if (exception_pending()) goto v262;
    env = stack[-5];
    goto v5;
/* error exit handlers */
v262:
    popv(6);
    return nil;
}



/* Code for intexprnp */

static Lisp_Object CC_intexprnp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v70, v71, v101, v57;
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
    v71 = v16;
    v101 = v0;
/* end of prologue */
    v70 = v101;
    if (!consp(v70)) goto v4;
    v70 = v101;
    v70 = qcar(v70);
    if (symbolp(v70)) goto v52;
    v70 = nil;
    { popv(1); return onevalue(v70); }

v52:
    v70 = v101;
    v57 = qcar(v70);
    v70 = elt(env, 2); /* intfn */
    v70 = Lflagp(nil, v57, v70);
    env = stack[0];
    if (v70 == nil) goto v42;
    v70 = v101;
    v70 = qcdr(v70);
    {
        popv(1);
        fn = elt(env, 3); /* intexprlisp */
        return (*qfn2(fn))(qenv(fn), v70, v71);
    }

v42:
    v70 = nil;
    { popv(1); return onevalue(v70); }

v4:
    v70 = v101;
    if (is_number(v70)) goto v7;
    v70 = v101;
    v70 = Latsoc(nil, v70, v71);
    v101 = v70;
    if (v70 == nil) goto v99;
    v70 = v101;
    v70 = qcdr(v70);
    v71 = elt(env, 1); /* integer */
    v70 = (v70 == v71 ? lisp_true : nil);
    { popv(1); return onevalue(v70); }

v99:
    v70 = nil;
    { popv(1); return onevalue(v70); }

v7:
    v70 = v101;
    v70 = integerp(v70);
    { popv(1); return onevalue(v70); }
}



/* Code for kernp */

static Lisp_Object CC_kernp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v150, v134, v105;
    CSL_IGNORE(nil);
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v134 = v0;
/* end of prologue */
    v150 = v134;
    v105 = qcdr(v150);
    v150 = (Lisp_Object)17; /* 1 */
    if (v105 == v150) goto v4;
    v150 = nil;
    return onevalue(v150);

v4:
    v150 = v134;
    v150 = qcar(v150);
    v134 = v150;
    v105 = v150;
    v150 = v105;
    v150 = (consp(v150) ? nil : lisp_true);
    if (!(v150 == nil)) goto v44;
    v150 = v105;
    v150 = qcar(v150);
    v150 = (consp(v150) ? nil : lisp_true);
    goto v44;

v44:
    if (v150 == nil) goto v24;
    v150 = nil;
    return onevalue(v150);

v24:
    v150 = v134;
    v150 = qcdr(v150);
    if (v150 == nil) goto v53;
    v150 = nil;
    return onevalue(v150);

v53:
    v150 = v134;
    v150 = qcar(v150);
    v105 = qcdr(v150);
    v150 = (Lisp_Object)17; /* 1 */
    if (v105 == v150) goto v50;
    v150 = nil;
    return onevalue(v150);

v50:
    v150 = v134;
    v150 = qcar(v150);
    v150 = qcar(v150);
    v134 = qcdr(v150);
    v150 = (Lisp_Object)17; /* 1 */
    v150 = (v134 == v150 ? lisp_true : nil);
    return onevalue(v150);
}



/* Code for msappend */

static Lisp_Object CC_msappend(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v101, v57;
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
    v101 = v0;
/* end of prologue */
    stack[-5] = v101;
    v101 = stack[-5];
    if (v101 == nil) goto v1;
    v101 = stack[-5];
    v101 = qcar(v101);
    stack[0] = stack[-4];
    v57 = stack[-4];
    v101 = Lsublis(nil, v57, v101);
    nil = C_nil;
    if (exception_pending()) goto v59;
    env = stack[-6];
    v101 = Lappend(nil, stack[0], v101);
    nil = C_nil;
    if (exception_pending()) goto v59;
    env = stack[-6];
    v101 = ncons(v101);
    nil = C_nil;
    if (exception_pending()) goto v59;
    env = stack[-6];
    stack[-2] = v101;
    stack[-3] = v101;
    goto v5;

v5:
    v101 = stack[-5];
    v101 = qcdr(v101);
    stack[-5] = v101;
    v101 = stack[-5];
    if (v101 == nil) { Lisp_Object res = stack[-3]; popv(7); return onevalue(res); }
    stack[-1] = stack[-2];
    v101 = stack[-5];
    v101 = qcar(v101);
    stack[0] = stack[-4];
    v57 = stack[-4];
    v101 = Lsublis(nil, v57, v101);
    nil = C_nil;
    if (exception_pending()) goto v59;
    env = stack[-6];
    v101 = Lappend(nil, stack[0], v101);
    nil = C_nil;
    if (exception_pending()) goto v59;
    env = stack[-6];
    v101 = ncons(v101);
    nil = C_nil;
    if (exception_pending()) goto v59;
    env = stack[-6];
    v101 = Lrplacd(nil, stack[-1], v101);
    nil = C_nil;
    if (exception_pending()) goto v59;
    env = stack[-6];
    v101 = stack[-2];
    v101 = qcdr(v101);
    stack[-2] = v101;
    goto v5;

v1:
    v101 = nil;
    { popv(7); return onevalue(v101); }
/* error exit handlers */
v59:
    popv(7);
    return nil;
}



/* Code for xnp */

static Lisp_Object CC_xnp(Lisp_Object env,
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

v11:
    v23 = v99;
    if (v23 == nil) goto v4;
    v23 = v99;
    v10 = qcar(v23);
    v23 = v30;
    v23 = Lmemq(nil, v10, v23);
    if (!(v23 == nil)) return onevalue(v23);
    v23 = v99;
    v99 = qcdr(v23);
    v23 = v30;
    v30 = v23;
    goto v11;

v4:
    v23 = nil;
    return onevalue(v23);
}



/* Code for errorp */

static Lisp_Object CC_errorp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v6, v7;
    CSL_IGNORE(nil);
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v6 = v0;
/* end of prologue */
    v7 = v6;
    v7 = (consp(v7) ? nil : lisp_true);
    if (!(v7 == nil)) return onevalue(v7);
    v6 = qcdr(v6);
    return onevalue(v6);
}



/* Code for ckrn1 */

static Lisp_Object CC_ckrn1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v234, v112;
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
    v234 = stack[0];
    if (!consp(v234)) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v234 = stack[0];
    v234 = qcar(v234);
    if (!consp(v234)) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    else goto v26;

v26:
    v234 = stack[0];
    v234 = qcar(v234);
    v234 = qcdr(v234);
    v112 = CC_ckrn1(env, v234);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-2];
    v234 = stack[-1];
    fn = elt(env, 1); /* gck2 */
    v234 = (*qfn2(fn))(qenv(fn), v112, v234);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-2];
    stack[-1] = v234;
    v234 = stack[0];
    v234 = qcdr(v234);
    if (v234 == nil) goto v20;
    v234 = stack[0];
    v234 = qcdr(v234);
    if (!consp(v234)) goto v95;
    v234 = stack[0];
    v234 = qcdr(v234);
    v234 = qcar(v234);
    if (!consp(v234)) goto v95;
    v234 = stack[0];
    v234 = qcar(v234);
    v234 = qcar(v234);
    v112 = qcar(v234);
    v234 = stack[0];
    v234 = qcdr(v234);
    v234 = qcar(v234);
    v234 = qcar(v234);
    v234 = qcar(v234);
    if (!(v112 == v234)) goto v95;
    v234 = stack[0];
    v234 = qcdr(v234);
    stack[0] = v234;
    goto v26;

v95:
    v234 = stack[0];
    v234 = qcdr(v234);
    v112 = CC_ckrn1(env, v234);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-2];
    v234 = stack[-1];
    {
        popv(3);
        fn = elt(env, 1); /* gck2 */
        return (*qfn2(fn))(qenv(fn), v112, v234);
    }

v20:
    v234 = stack[0];
    v234 = qcar(v234);
    v234 = qcar(v234);
    v234 = qcar(v234);
    fn = elt(env, 2); /* noncomp */
    v234 = (*qfn1(fn))(qenv(fn), v234);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-2];
    if (!(v234 == nil)) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v234 = stack[0];
    v234 = qcar(v234);
    v112 = qcar(v234);
    v234 = stack[-1];
    v234 = cons(v112, v234);
    nil = C_nil;
    if (exception_pending()) goto v96;
    popv(3);
    return ncons(v234);
/* error exit handlers */
v96:
    popv(3);
    return nil;
}



/* Code for mkspm */

static Lisp_Object CC_mkspm(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v41, v64;
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
    v64 = stack[0];
    v41 = (Lisp_Object)1; /* 0 */
    if (v64 == v41) goto v4;
    v41 = qvalue(elt(env, 1)); /* subfg!* */
    if (v41 == nil) goto v44;
    v64 = stack[-1];
    v41 = qvalue(elt(env, 2)); /* asymplis!* */
    v41 = Latsoc(nil, v64, v41);
    v64 = v41;
    if (v41 == nil) goto v44;
    v41 = v64;
    v64 = qcdr(v41);
    v41 = stack[0];
    v41 = (Lisp_Object)lesseq2(v64, v41);
    nil = C_nil;
    if (exception_pending()) goto v134;
    v41 = v41 ? lisp_true : nil;
    env = stack[-2];
    if (v41 == nil) goto v44;
    v41 = nil;
    { popv(3); return onevalue(v41); }

v44:
    v41 = stack[-1];
    fn = elt(env, 3); /* sub2chk */
    v41 = (*qfn1(fn))(qenv(fn), v41);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-2];
    v64 = stack[-1];
    v41 = stack[0];
    {
        popv(3);
        fn = elt(env, 4); /* to */
        return (*qfn2(fn))(qenv(fn), v64, v41);
    }

v4:
    v41 = (Lisp_Object)17; /* 1 */
    { popv(3); return onevalue(v41); }
/* error exit handlers */
v134:
    popv(3);
    return nil;
}



/* Code for setel1 */

static Lisp_Object MS_CDECL CC_setel1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v16,
                         Lisp_Object v63, Lisp_Object v9, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v86, v104, v107;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "setel1");
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
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v9;
    stack[-1] = v63;
    stack[-2] = v16;
    stack[-3] = v0;
/* end of prologue */

v45:
    v86 = stack[-2];
    v86 = qcar(v86);
    v86 = integerp(v86);
    if (v86 == nil) goto v24;
    v86 = stack[-2];
    v104 = qcar(v86);
    v86 = stack[0];
    v86 = qcar(v86);
    v86 = (Lisp_Object)geq2(v104, v86);
    nil = C_nil;
    if (exception_pending()) goto v120;
    v86 = v86 ? lisp_true : nil;
    env = stack[-4];
    if (!(v86 == nil)) goto v50;
    v86 = stack[-2];
    v104 = qcar(v86);
    v86 = (Lisp_Object)1; /* 0 */
    v86 = (Lisp_Object)lessp2(v104, v86);
    nil = C_nil;
    if (exception_pending()) goto v120;
    v86 = v86 ? lisp_true : nil;
    env = stack[-4];
    if (!(v86 == nil)) goto v50;
    v86 = stack[-2];
    v86 = qcdr(v86);
    if (v86 == nil) goto v69;
    v104 = stack[-3];
    v86 = stack[-2];
    v86 = qcar(v86);
    v86 = *(Lisp_Object *)((char *)v104 + (CELL-TAG_VECTOR) + ((int32_t)v86/(16/CELL)));
    stack[-3] = v86;
    v86 = stack[-2];
    v86 = qcdr(v86);
    stack[-2] = v86;
    v86 = stack[0];
    v86 = qcdr(v86);
    stack[0] = v86;
    goto v45;

v69:
    v107 = stack[-3];
    v86 = stack[-2];
    v104 = qcar(v86);
    v86 = stack[-1];
    *(Lisp_Object *)((char *)v107 + (CELL-TAG_VECTOR) + ((int32_t)v104/(16/CELL))) = v86;
    { popv(5); return onevalue(v86); }

v50:
    v107 = elt(env, 2); /* rlisp */
    v104 = (Lisp_Object)369; /* 23 */
    v86 = elt(env, 3); /* "Array out of bounds" */
    {
        popv(5);
        fn = elt(env, 4); /* rerror */
        return (*qfnn(fn))(qenv(fn), 3, v107, v104, v86);
    }

v24:
    v86 = stack[-2];
    v104 = qcar(v86);
    v86 = elt(env, 1); /* "array index" */
    {
        popv(5);
        fn = elt(env, 5); /* typerr */
        return (*qfn2(fn))(qenv(fn), v104, v86);
    }
/* error exit handlers */
v120:
    popv(5);
    return nil;
}



/* Code for appr */

static Lisp_Object CC_appr(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v18, v19, v20;
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
    v18 = v16;
    v19 = v0;
/* end of prologue */

v12:
    v20 = v19;
    if (v20 == nil) { popv(2); return onevalue(v18); }
    v20 = v19;
    v20 = qcdr(v20);
    stack[0] = v20;
    v19 = qcar(v19);
    v18 = cons(v19, v18);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-1];
    v19 = stack[0];
    goto v12;
/* error exit handlers */
v22:
    popv(2);
    return nil;
}



/* Code for mcharg */

static Lisp_Object MS_CDECL CC_mcharg(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v16,
                         Lisp_Object v63, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v132, v133, v147;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "mcharg");
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
    stack[-3] = v63;
    stack[0] = v16;
    v147 = v0;
/* end of prologue */
    v133 = elt(env, 1); /* minus */
    v132 = stack[0];
    v132 = Latsoc(nil, v133, v132);
    if (v132 == nil) goto v45;
    v133 = v147;
    v132 = stack[0];
    fn = elt(env, 3); /* reform!-minus */
    v147 = (*qfn2(fn))(qenv(fn), v133, v132);
    nil = C_nil;
    if (exception_pending()) goto v468;
    env = stack[-5];
    v133 = stack[0];
    v132 = stack[-3];
    {
        popv(6);
        fn = elt(env, 4); /* mcharg1 */
        return (*qfnn(fn))(qenv(fn), 3, v147, v133, v132);
    }

v45:
    v132 = stack[0];
    if (v132 == nil) goto v138;
    v132 = stack[0];
    v133 = qcar(v132);
    v132 = elt(env, 2); /* slash */
    if (!consp(v133)) goto v138;
    v133 = qcar(v133);
    if (!(v133 == v132)) goto v138;
    v133 = v147;
    v132 = stack[0];
    fn = elt(env, 5); /* reform!-minus2 */
    v132 = (*qfn2(fn))(qenv(fn), v133, v132);
    nil = C_nil;
    if (exception_pending()) goto v468;
    env = stack[-5];
    stack[-4] = v132;
    goto v39;

v39:
    v132 = stack[-4];
    if (v132 == nil) goto v56;
    v132 = stack[-4];
    v132 = qcar(v132);
    v133 = v132;
    v147 = qcar(v133);
    v133 = qcdr(v132);
    v132 = stack[-3];
    fn = elt(env, 4); /* mcharg1 */
    v132 = (*qfnn(fn))(qenv(fn), 3, v147, v133, v132);
    nil = C_nil;
    if (exception_pending()) goto v468;
    env = stack[-5];
    stack[-2] = v132;
    v132 = stack[-2];
    fn = elt(env, 6); /* lastpair */
    v132 = (*qfn1(fn))(qenv(fn), v132);
    nil = C_nil;
    if (exception_pending()) goto v468;
    env = stack[-5];
    stack[-1] = v132;
    v132 = stack[-4];
    v132 = qcdr(v132);
    stack[-4] = v132;
    v132 = stack[-1];
    if (!consp(v132)) goto v39;
    else goto v40;

v40:
    v132 = stack[-4];
    if (v132 == nil) { Lisp_Object res = stack[-2]; popv(6); return onevalue(res); }
    stack[0] = stack[-1];
    v132 = stack[-4];
    v132 = qcar(v132);
    v133 = v132;
    v147 = qcar(v133);
    v133 = qcdr(v132);
    v132 = stack[-3];
    fn = elt(env, 4); /* mcharg1 */
    v132 = (*qfnn(fn))(qenv(fn), 3, v147, v133, v132);
    nil = C_nil;
    if (exception_pending()) goto v468;
    env = stack[-5];
    v132 = Lrplacd(nil, stack[0], v132);
    nil = C_nil;
    if (exception_pending()) goto v468;
    env = stack[-5];
    v132 = stack[-1];
    fn = elt(env, 6); /* lastpair */
    v132 = (*qfn1(fn))(qenv(fn), v132);
    nil = C_nil;
    if (exception_pending()) goto v468;
    env = stack[-5];
    stack[-1] = v132;
    v132 = stack[-4];
    v132 = qcdr(v132);
    stack[-4] = v132;
    goto v40;

v56:
    v132 = nil;
    { popv(6); return onevalue(v132); }

v138:
    v133 = stack[0];
    v132 = stack[-3];
    {
        popv(6);
        fn = elt(env, 4); /* mcharg1 */
        return (*qfnn(fn))(qenv(fn), 3, v147, v133, v132);
    }
/* error exit handlers */
v468:
    popv(6);
    return nil;
}



/* Code for sf_member */

static Lisp_Object CC_sf_member(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v52, v193;
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
    v52 = stack[0];
    if (!consp(v52)) goto v4;
    v52 = stack[0];
    v52 = qcar(v52);
    if (!consp(v52)) goto v4;
    v193 = stack[-1];
    v52 = stack[0];
    v52 = qcar(v52);
    v52 = qcar(v52);
    v52 = qcar(v52);
    fn = elt(env, 1); /* mvar_member */
    v52 = (*qfn2(fn))(qenv(fn), v193, v52);
    nil = C_nil;
    if (exception_pending()) goto v39;
    env = stack[-2];
    if (!(v52 == nil)) { popv(3); return onevalue(v52); }
    v193 = stack[-1];
    v52 = stack[0];
    v52 = qcar(v52);
    v52 = qcdr(v52);
    v52 = CC_sf_member(env, v193, v52);
    nil = C_nil;
    if (exception_pending()) goto v39;
    env = stack[-2];
    if (!(v52 == nil)) { popv(3); return onevalue(v52); }
    v193 = stack[-1];
    v52 = stack[0];
    v52 = qcdr(v52);
    stack[-1] = v193;
    stack[0] = v52;
    goto v11;

v4:
    v52 = nil;
    { popv(3); return onevalue(v52); }
/* error exit handlers */
v39:
    popv(3);
    return nil;
}



/* Code for reorder */

static Lisp_Object CC_reorder(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v100, v150;
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
    v100 = CC_reorder(env, v100);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[-3];
    fn = elt(env, 1); /* rmultpf */
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



/* Code for inprint */

static Lisp_Object MS_CDECL CC_inprint(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v16,
                         Lisp_Object v63, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v288, v487, v417, v488;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "inprint");
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
    v487 = stack[-2];
    v288 = elt(env, 1); /* times */
    if (!(v487 == v288)) goto v134;
    v288 = qvalue(elt(env, 2)); /* !*nat */
    if (v288 == nil) goto v134;
    v288 = qvalue(elt(env, 3)); /* !*asterisk */
    if (!(v288 == nil)) goto v134;
    v288 = elt(env, 4); /* times2 */
    stack[-2] = v288;
    v488 = elt(env, 4); /* times2 */
    v417 = elt(env, 5); /* infix */
    v487 = elt(env, 1); /* times */
    v288 = elt(env, 5); /* infix */
    v288 = get(v487, v288);
    env = stack[-4];
    v288 = Lputprop(nil, 3, v488, v417, v288);
    nil = C_nil;
    if (exception_pending()) goto v334;
    env = stack[-4];
    v417 = elt(env, 4); /* times2 */
    v487 = elt(env, 6); /* prtch */
    v288 = elt(env, 7); /* " " */
    v288 = Lputprop(nil, 3, v417, v487, v288);
    nil = C_nil;
    if (exception_pending()) goto v334;
    env = stack[-4];
    goto v134;

v134:
    v487 = stack[-2];
    v288 = elt(env, 8); /* plus */
    if (!(v487 == v288)) goto v55;
    v288 = qvalue(elt(env, 9)); /* !*revpri */
    if (v288 == nil) goto v55;
    v288 = stack[0];
    v288 = Lreverse(nil, v288);
    nil = C_nil;
    if (exception_pending()) goto v334;
    env = stack[-4];
    stack[0] = v288;
    goto v55;

v55:
    v487 = stack[-2];
    v288 = elt(env, 10); /* alt */
    v288 = get(v487, v288);
    env = stack[-4];
    if (!(v288 == nil)) goto v57;
    v487 = stack[-2];
    v288 = elt(env, 11); /* not */
    if (v487 == v288) goto v61;
    v487 = stack[-2];
    v288 = elt(env, 12); /* setq */
    if (!(v487 == v288)) goto v106;
    v288 = stack[0];
    v288 = Lreverse(nil, v288);
    nil = C_nil;
    if (exception_pending()) goto v334;
    env = stack[-4];
    v288 = qcar(v288);
    stack[-3] = v288;
    if (!consp(v288)) goto v106;
    v288 = stack[-3];
    v288 = qcar(v288);
    if (!(symbolp(v288))) goto v106;
    v288 = stack[-3];
    fn = elt(env, 23); /* getrtype */
    v288 = (*qfn1(fn))(qenv(fn), v288);
    nil = C_nil;
    if (exception_pending()) goto v334;
    env = stack[-4];
    v487 = v288;
    if (v288 == nil) goto v106;
    v288 = elt(env, 13); /* tag */
    v487 = get(v487, v288);
    env = stack[-4];
    v288 = elt(env, 14); /* setprifn */
    v288 = get(v487, v288);
    env = stack[-4];
    v487 = v288;
    if (v288 == nil) goto v106;
    v417 = v487;
    v288 = stack[0];
    v487 = qcar(v288);
    v288 = stack[-3];
        popv(5);
        return Lapply2(nil, 3, v417, v487, v288);

v106:
    v288 = stack[0];
    v288 = qcar(v288);
    if (!consp(v288)) goto v230;
    v288 = stack[0];
    v288 = qcar(v288);
    v288 = qcar(v288);
    if (!(symbolp(v288))) goto v230;
    v288 = qvalue(elt(env, 2)); /* !*nat */
    if (v288 == nil) goto v230;
    v288 = stack[0];
    v288 = qcar(v288);
    v487 = qcar(v288);
    v288 = elt(env, 15); /* prifn */
    v288 = get(v487, v288);
    env = stack[-4];
    stack[-3] = v288;
    if (!(v288 == nil)) goto v130;
    v288 = stack[0];
    v288 = qcar(v288);
    v487 = qcar(v288);
    v288 = elt(env, 16); /* pprifn */
    v288 = get(v487, v288);
    env = stack[-4];
    stack[-3] = v288;
    if (!(v288 == nil)) goto v130;

v230:
    v288 = qvalue(elt(env, 20)); /* !*nosplit */
    if (v288 == nil) goto v361;
    v288 = qvalue(elt(env, 21)); /* testing!-width!* */
    if (!(v288 == nil)) goto v361;
    v288 = stack[0];
    v417 = qcar(v288);
    v487 = stack[-1];
    v288 = nil;
    fn = elt(env, 24); /* prinfit */
    v288 = (*qfnn(fn))(qenv(fn), 3, v417, v487, v288);
    nil = C_nil;
    if (exception_pending()) goto v334;
    env = stack[-4];
    goto v77;

v77:
    v288 = stack[0];
    v288 = qcdr(v288);
    stack[0] = v288;
    goto v57;

v57:
    v288 = qvalue(elt(env, 20)); /* !*nosplit */
    if (v288 == nil) goto v489;
    v288 = qvalue(elt(env, 21)); /* testing!-width!* */
    if (!(v288 == nil)) goto v489;
    v288 = stack[0];
    stack[-3] = v288;
    goto v253;

v253:
    v288 = stack[-3];
    if (v288 == nil) goto v254;
    v288 = stack[-3];
    v288 = qcar(v288);
    stack[0] = v288;
    v288 = stack[0];
    if (!consp(v288)) goto v357;
    v417 = stack[-2];
    v288 = stack[0];
    v487 = qcar(v288);
    v288 = elt(env, 10); /* alt */
    v288 = get(v487, v288);
    env = stack[-4];
    if (!(v417 == v288)) goto v357;
    v417 = stack[0];
    v487 = stack[-1];
    v288 = nil;
    fn = elt(env, 24); /* prinfit */
    v288 = (*qfnn(fn))(qenv(fn), 3, v417, v487, v288);
    nil = C_nil;
    if (exception_pending()) goto v334;
    env = stack[-4];
    goto v490;

v490:
    v288 = stack[-3];
    v288 = qcdr(v288);
    stack[-3] = v288;
    goto v253;

v357:
    v487 = stack[-2];
    v288 = elt(env, 22); /* (setq !*comma!*) */
    v288 = Lmemq(nil, v487, v288);
    if (v288 == nil) goto v343;
    v288 = stack[-2];
    fn = elt(env, 25); /* oprin */
    v288 = (*qfn1(fn))(qenv(fn), v288);
    nil = C_nil;
    if (exception_pending()) goto v334;
    env = stack[-4];
    v288 = stack[0];
    fn = elt(env, 26); /* negnumberchk */
    v417 = (*qfn1(fn))(qenv(fn), v288);
    nil = C_nil;
    if (exception_pending()) goto v334;
    env = stack[-4];
    v487 = stack[-1];
    v288 = nil;
    fn = elt(env, 24); /* prinfit */
    v288 = (*qfnn(fn))(qenv(fn), 3, v417, v487, v288);
    nil = C_nil;
    if (exception_pending()) goto v334;
    env = stack[-4];
    goto v490;

v343:
    v288 = stack[0];
    fn = elt(env, 26); /* negnumberchk */
    v417 = (*qfn1(fn))(qenv(fn), v288);
    nil = C_nil;
    if (exception_pending()) goto v334;
    env = stack[-4];
    v487 = stack[-1];
    v288 = stack[-2];
    fn = elt(env, 24); /* prinfit */
    v288 = (*qfnn(fn))(qenv(fn), 3, v417, v487, v288);
    nil = C_nil;
    if (exception_pending()) goto v334;
    env = stack[-4];
    goto v490;

v254:
    v288 = nil;
    { popv(5); return onevalue(v288); }

v489:
    v288 = stack[0];
    stack[-3] = v288;
    goto v239;

v239:
    v288 = stack[-3];
    if (v288 == nil) goto v254;
    v288 = stack[-3];
    v288 = qcar(v288);
    stack[0] = v288;
    v288 = stack[0];
    if (!consp(v288)) goto v320;
    v417 = stack[-2];
    v288 = stack[0];
    v487 = qcar(v288);
    v288 = elt(env, 10); /* alt */
    v288 = get(v487, v288);
    env = stack[-4];
    if (!(v417 == v288)) goto v320;
    v487 = stack[0];
    v288 = stack[-1];
    fn = elt(env, 27); /* maprint */
    v288 = (*qfn2(fn))(qenv(fn), v487, v288);
    nil = C_nil;
    if (exception_pending()) goto v334;
    env = stack[-4];
    goto v491;

v491:
    v288 = stack[-3];
    v288 = qcdr(v288);
    stack[-3] = v288;
    goto v239;

v320:
    v288 = stack[-2];
    fn = elt(env, 25); /* oprin */
    v288 = (*qfn1(fn))(qenv(fn), v288);
    nil = C_nil;
    if (exception_pending()) goto v334;
    env = stack[-4];
    v288 = stack[0];
    fn = elt(env, 26); /* negnumberchk */
    v487 = (*qfn1(fn))(qenv(fn), v288);
    nil = C_nil;
    if (exception_pending()) goto v334;
    env = stack[-4];
    v288 = stack[-1];
    fn = elt(env, 27); /* maprint */
    v288 = (*qfn2(fn))(qenv(fn), v487, v288);
    nil = C_nil;
    if (exception_pending()) goto v334;
    env = stack[-4];
    goto v491;

v361:
    v288 = stack[0];
    v487 = qcar(v288);
    v288 = stack[-1];
    fn = elt(env, 27); /* maprint */
    v288 = (*qfn2(fn))(qenv(fn), v487, v288);
    nil = C_nil;
    if (exception_pending()) goto v334;
    env = stack[-4];
    goto v77;

v130:
    v487 = stack[-3];
    v288 = stack[-2];
    v487 = get(v487, v288);
    env = stack[-4];
    v288 = elt(env, 17); /* inbrackets */
    if (!(v487 == v288)) goto v230;
    v288 = elt(env, 18); /* "(" */
    fn = elt(env, 28); /* prin2!* */
    v288 = (*qfn1(fn))(qenv(fn), v288);
    nil = C_nil;
    if (exception_pending()) goto v334;
    env = stack[-4];
    v288 = stack[0];
    v487 = qcar(v288);
    v288 = stack[-1];
    fn = elt(env, 27); /* maprint */
    v288 = (*qfn2(fn))(qenv(fn), v487, v288);
    nil = C_nil;
    if (exception_pending()) goto v334;
    env = stack[-4];
    v288 = elt(env, 19); /* ")" */
    fn = elt(env, 28); /* prin2!* */
    v288 = (*qfn1(fn))(qenv(fn), v288);
    nil = C_nil;
    if (exception_pending()) goto v334;
    env = stack[-4];
    goto v77;

v61:
    v288 = stack[-2];
    fn = elt(env, 25); /* oprin */
    v288 = (*qfn1(fn))(qenv(fn), v288);
    nil = C_nil;
    if (exception_pending()) goto v334;
    env = stack[-4];
    goto v106;
/* error exit handlers */
v334:
    popv(5);
    return nil;
}



/* Code for addd */

static Lisp_Object CC_addd(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v206, v41;
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
    v41 = nil;
    goto v12;

v12:
    v206 = stack[0];
    if (v206 == nil) goto v13;
    v206 = stack[0];
    if (!consp(v206)) goto v19;
    v206 = stack[0];
    v206 = qcar(v206);
    if (!consp(v206)) goto v19;
    v206 = stack[0];
    v206 = qcar(v206);
    v206 = cons(v206, v41);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-3];
    v41 = v206;
    v206 = stack[0];
    v206 = qcdr(v206);
    stack[0] = v206;
    goto v12;

v19:
    stack[-2] = v41;
    v41 = stack[-1];
    v206 = stack[0];
    fn = elt(env, 1); /* adddm */
    v206 = (*qfn2(fn))(qenv(fn), v41, v206);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-3];
    {
        Lisp_Object v105 = stack[-2];
        popv(4);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v105, v206);
    }

v13:
    v206 = stack[-1];
    {
        popv(4);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v41, v206);
    }
/* error exit handlers */
v134:
    popv(4);
    return nil;
}



/* Code for sizchk */

static Lisp_Object CC_sizchk(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v36, v48;
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
    goto v12;

v12:
    v36 = stack[-1];
    if (v36 == nil) goto v6;
    v36 = stack[-1];
    v36 = qcar(v36);
    v36 = qcar(v36);
    v48 = Llength(nil, v36);
    nil = C_nil;
    if (exception_pending()) goto v49;
    env = stack[-3];
    v36 = stack[0];
    v36 = (Lisp_Object)greaterp2(v48, v36);
    nil = C_nil;
    if (exception_pending()) goto v49;
    v36 = v36 ? lisp_true : nil;
    env = stack[-3];
    if (v36 == nil) goto v23;
    v36 = stack[-1];
    v36 = qcdr(v36);
    stack[-1] = v36;
    goto v12;

v23:
    v36 = stack[-1];
    v48 = qcar(v36);
    v36 = stack[-2];
    v36 = cons(v48, v36);
    nil = C_nil;
    if (exception_pending()) goto v49;
    env = stack[-3];
    stack[-2] = v36;
    v36 = stack[-1];
    v36 = qcdr(v36);
    stack[-1] = v36;
    goto v12;

v6:
    v36 = stack[-2];
    {
        popv(4);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v36);
    }
/* error exit handlers */
v49:
    popv(4);
    return nil;
}



/* Code for gcdfd */

static Lisp_Object CC_gcdfd(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v17, v18, v19, v20;
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
    v18 = v16;
    v19 = v0;
/* end of prologue */
    v20 = qvalue(elt(env, 1)); /* dmode!* */
    v17 = elt(env, 2); /* field */
    v17 = Lflagp(nil, v20, v17);
    env = stack[0];
    if (v17 == nil) goto v28;
    v17 = (Lisp_Object)17; /* 1 */
    { popv(1); return onevalue(v17); }

v28:
    v17 = v19;
    {
        popv(1);
        fn = elt(env, 3); /* gcdfd1 */
        return (*qfn2(fn))(qenv(fn), v17, v18);
    }
}



/* Code for quotfd */

static Lisp_Object CC_quotfd(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v100, v150, v134, v105;
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
    v150 = v16;
    v134 = v0;
/* end of prologue */
    v105 = v134;
    v100 = v150;
    if (equal(v105, v100)) goto v4;
    v105 = qvalue(elt(env, 1)); /* dmode!* */
    v100 = elt(env, 2); /* field */
    v100 = Lflagp(nil, v105, v100);
    env = stack[0];
    if (v100 == nil) goto v24;
    v100 = v134;
    {
        popv(1);
        fn = elt(env, 3); /* divd */
        return (*qfn2(fn))(qenv(fn), v100, v150);
    }

v24:
    v100 = v134;
    if (!consp(v100)) goto v37;
    v100 = v134;
    v100 = qcar(v100);
    if (!consp(v100)) goto v37;
    v100 = v134;
    {
        popv(1);
        fn = elt(env, 4); /* quotk */
        return (*qfn2(fn))(qenv(fn), v100, v150);
    }

v37:
    v100 = v134;
    {
        popv(1);
        fn = elt(env, 5); /* quotdd */
        return (*qfn2(fn))(qenv(fn), v100, v150);
    }

v4:
    v100 = (Lisp_Object)17; /* 1 */
    { popv(1); return onevalue(v100); }
}



/* Code for difff */

static Lisp_Object CC_difff(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v115, v132, v133;
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
    v115 = stack[-2];
    if (!consp(v115)) goto v6;
    v115 = stack[-2];
    v115 = qcar(v115);
    if (!consp(v115)) goto v44;
    v115 = stack[-2];
    v115 = qcar(v115);
    v132 = qcar(v115);
    v115 = (Lisp_Object)17; /* 1 */
    v115 = cons(v132, v115);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-4];
    v132 = ncons(v115);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-4];
    v115 = (Lisp_Object)17; /* 1 */
    stack[0] = cons(v132, v115);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-4];
    v115 = stack[-2];
    v115 = qcar(v115);
    v132 = qcdr(v115);
    v115 = stack[-1];
    v115 = CC_difff(env, v132, v115);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-4];
    fn = elt(env, 2); /* multsq */
    stack[-3] = (*qfn2(fn))(qenv(fn), stack[0], v115);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-4];
    v115 = stack[-2];
    v115 = qcar(v115);
    v132 = qcar(v115);
    v115 = stack[-1];
    fn = elt(env, 3); /* diffp */
    stack[0] = (*qfn2(fn))(qenv(fn), v132, v115);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-4];
    v115 = stack[-2];
    v115 = qcar(v115);
    v132 = qcdr(v115);
    v115 = (Lisp_Object)17; /* 1 */
    v115 = cons(v132, v115);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-4];
    fn = elt(env, 2); /* multsq */
    v115 = (*qfn2(fn))(qenv(fn), stack[0], v115);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-4];
    fn = elt(env, 4); /* addsq */
    stack[0] = (*qfn2(fn))(qenv(fn), stack[-3], v115);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-4];
    v115 = stack[-2];
    v132 = qcdr(v115);
    v115 = stack[-1];
    v115 = CC_difff(env, v132, v115);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-4];
    {
        Lisp_Object v230 = stack[0];
        popv(5);
        fn = elt(env, 4); /* addsq */
        return (*qfn2(fn))(qenv(fn), v230, v115);
    }

v44:
    v115 = stack[-2];
    v132 = qcar(v115);
    v115 = elt(env, 1); /* domain!-diff!-fn */
    v115 = get(v132, v115);
    v132 = v115;
    v115 = v132;
    if (v115 == nil) goto v52;
    v133 = v132;
    v132 = stack[-2];
    v115 = stack[-1];
        popv(5);
        return Lapply2(nil, 3, v133, v132, v115);

v52:
    v132 = nil;
    v115 = (Lisp_Object)17; /* 1 */
    popv(5);
    return cons(v132, v115);

v6:
    v132 = nil;
    v115 = (Lisp_Object)17; /* 1 */
    popv(5);
    return cons(v132, v115);
/* error exit handlers */
v78:
    popv(5);
    return nil;
}



/* Code for quotsq */

static Lisp_Object CC_quotsq(Lisp_Object env,
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
    fn = elt(env, 1); /* invsq */
    v1 = (*qfn1(fn))(qenv(fn), v1);
    nil = C_nil;
    if (exception_pending()) goto v13;
    env = stack[-1];
    {
        Lisp_Object v24 = stack[0];
        popv(2);
        fn = elt(env, 2); /* multsq */
        return (*qfn2(fn))(qenv(fn), v24, v1);
    }
/* error exit handlers */
v13:
    popv(2);
    return nil;
}



/* Code for errorset!* */

static Lisp_Object CC_errorsetH(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v25, v13, v24;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v25 = v16;
    v13 = v0;
/* end of prologue */
    v24 = v13;
    v13 = v25;
    v25 = qvalue(elt(env, 1)); /* !*backtrace */
    {
        fn = elt(env, 2); /* errorset */
        return (*qfnn(fn))(qenv(fn), 3, v24, v13, v25);
    }
}



setup_type const u03_setup[] =
{
    {"simptimes",               CC_simptimes,   too_many_1,    wrong_no_1},
    {"exchk2",                  too_few_2,      CC_exchk2,     wrong_no_2},
    {"eolcheck",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_eolcheck},
    {"quotf1",                  too_few_2,      CC_quotf1,     wrong_no_2},
    {"layout-formula",          wrong_no_na,    wrong_no_nb,   (n_args *)CC_layoutKformula},
    {"isimp1",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_isimp1},
    {"quotk",                   too_few_2,      CC_quotk,      wrong_no_2},
    {"mcharg1",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_mcharg1},
    {"setel",                   too_few_2,      CC_setel,      wrong_no_2},
    {"sub2chk",                 CC_sub2chk,     too_many_1,    wrong_no_1},
    {"appn",                    too_few_2,      CC_appn,       wrong_no_2},
    {"lt*",                     CC_ltH,         too_many_1,    wrong_no_1},
    {"gadd",                    wrong_no_na,    wrong_no_nb,   (n_args *)CC_gadd},
    {"multdm",                  too_few_2,      CC_multdm,     wrong_no_2},
    {":minus",                  CC_Tminus,      too_many_1,    wrong_no_1},
    {"isimp2",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_isimp2},
    {"exchk1",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_exchk1},
    {"xcomment",                too_few_2,      CC_xcomment,   wrong_no_2},
    {"lnc",                     CC_lnc,         too_many_1,    wrong_no_1},
    {"gcdf",                    too_few_2,      CC_gcdf,       wrong_no_2},
    {"mkarray1",                too_few_2,      CC_mkarray1,   wrong_no_2},
    {"smemqlp",                 too_few_2,      CC_smemqlp,    wrong_no_2},
    {"formlis",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_formlis},
    {"rank",                    CC_rank,        too_many_1,    wrong_no_1},
    {"subs3f",                  CC_subs3f,      too_many_1,    wrong_no_1},
    {"convertmode",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_convertmode},
    {"mtchk",                   too_few_2,      CC_mtchk,      wrong_no_2},
    {"mksq",                    too_few_2,      CC_mksq,       wrong_no_2},
    {"intexprnp",               too_few_2,      CC_intexprnp,  wrong_no_2},
    {"kernp",                   CC_kernp,       too_many_1,    wrong_no_1},
    {"msappend",                too_few_2,      CC_msappend,   wrong_no_2},
    {"xnp",                     too_few_2,      CC_xnp,        wrong_no_2},
    {"errorp",                  CC_errorp,      too_many_1,    wrong_no_1},
    {"ckrn1",                   CC_ckrn1,       too_many_1,    wrong_no_1},
    {"mkspm",                   too_few_2,      CC_mkspm,      wrong_no_2},
    {"setel1",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_setel1},
    {"appr",                    too_few_2,      CC_appr,       wrong_no_2},
    {"mcharg",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_mcharg},
    {"sf_member",               too_few_2,      CC_sf_member,  wrong_no_2},
    {"reorder",                 CC_reorder,     too_many_1,    wrong_no_1},
    {"inprint",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_inprint},
    {"addd",                    too_few_2,      CC_addd,       wrong_no_2},
    {"sizchk",                  too_few_2,      CC_sizchk,     wrong_no_2},
    {"gcdfd",                   too_few_2,      CC_gcdfd,      wrong_no_2},
    {"quotfd",                  too_few_2,      CC_quotfd,     wrong_no_2},
    {"difff",                   too_few_2,      CC_difff,      wrong_no_2},
    {"quotsq",                  too_few_2,      CC_quotsq,     wrong_no_2},
    {"errorset*",               too_few_2,      CC_errorsetH,  wrong_no_2},
    {NULL, (one_args *)"u03", (two_args *)"13507 9457472 6911821", 0}
};

/* end of generated code */
