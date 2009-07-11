
/* $destdir/generated-c\u12.c Machine generated C code */

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


/* Code for pappl_pv */

static Lisp_Object CC_pappl_pv(Lisp_Object env,
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
    CSL_IGNORE(nil);
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
    if (!(((int32_t)(v432)) > ((int32_t)(v470)))) goto v125;

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



/* Code for free!-powerp */

static Lisp_Object CC_freeKpowerp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v22;
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



/* Code for retattributes */

static Lisp_Object CC_retattributes(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v101, v57;
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
    v101 = stack[0];
    if (v101 == nil) goto v45;
    v57 = stack[-1];
    v101 = stack[0];
    v101 = qcar(v101);
    fn = elt(env, 1); /* find */
    v101 = (*qfn2(fn))(qenv(fn), v57, v101);
    nil = C_nil;
    if (exception_pending()) goto v55;
    env = stack[-3];
    stack[-2] = v101;
    v57 = stack[-2];
    v101 = nil;
    v101 = Lneq(nil, v57, v101);
    nil = C_nil;
    if (exception_pending()) goto v55;
    env = stack[-3];
    if (v101 == nil) goto v69;
    v101 = stack[0];
    v57 = qcar(v101);
    v101 = stack[-2];
    stack[-2] = list2(v57, v101);
    nil = C_nil;
    if (exception_pending()) goto v55;
    env = stack[-3];
    v57 = stack[-1];
    v101 = stack[0];
    v101 = qcdr(v101);
    v101 = CC_retattributes(env, v57, v101);
    nil = C_nil;
    if (exception_pending()) goto v55;
    {
        Lisp_Object v65 = stack[-2];
        popv(4);
        return cons(v65, v101);
    }

v69:
    v57 = stack[-1];
    v101 = stack[0];
    v101 = qcdr(v101);
    stack[-1] = v57;
    stack[0] = v101;
    goto v11;

v45:
    v101 = nil;
    { popv(4); return onevalue(v101); }
/* error exit handlers */
v55:
    popv(4);
    return nil;
}



/* Code for bcsum */

static Lisp_Object CC_bcsum(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v36, v48, v33;
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



/* Code for gsetsugar */

static Lisp_Object CC_gsetsugar(Lisp_Object env,
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



/* Code for vecopp */

static Lisp_Object CC_vecopp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v150, v134, v105;
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
    CSL_IGNORE(nil);
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
    CSL_IGNORE(nil);
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
    CSL_IGNORE(nil);
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
    if (((int32_t)(v186)) < ((int32_t)(v127))) goto v2;
    v186 = v123;
    v127 = (Lisp_Object)1; /* 0 */
    if (((int32_t)(v186)) < ((int32_t)(v127))) goto v2;
    v186 = v125;
    v127 = v123;
    v127 = (Lisp_Object)(int32_t)((int32_t)v186 + (int32_t)v127 - TAG_FIXNUM);
    v474 = v127;
    v127 = (Lisp_Object)1; /* 0 */
    v88 = v127;
    goto v52;

v52:
    v186 = v474;
    v127 = v88;
    v127 = (Lisp_Object)(int32_t)((int32_t)v186 - (int32_t)v127 + TAG_FIXNUM);
    v127 = ((intptr_t)(v127) < 0 ? lisp_true : nil);
    if (v127 == nil) goto v150;
    v127 = (Lisp_Object)1; /* 0 */
    v94 = v127;
    goto v60;

v60:
    v186 = v125;
    v127 = v94;
    v127 = (Lisp_Object)(int32_t)((int32_t)v186 - (int32_t)v127 + TAG_FIXNUM);
    v127 = ((intptr_t)(v127) < 0 ? lisp_true : nil);
    if (!(v127 == nil)) { popv(1); return onevalue(v474); }
    v186 = v473;
    v127 = v94;
    v127 = *(Lisp_Object *)((char *)v186 + (CELL-TAG_VECTOR) + ((int32_t)v127/(16/CELL)));
    v212 = v127;
    v127 = (Lisp_Object)1; /* 0 */
    v108 = v127;
    goto v143;

v143:
    v186 = v123;
    v127 = v108;
    v127 = (Lisp_Object)(int32_t)((int32_t)v186 - (int32_t)v127 + TAG_FIXNUM);
    v127 = ((intptr_t)(v127) < 0 ? lisp_true : nil);
    if (v127 == nil) goto v98;
    v127 = v94;
    v127 = (Lisp_Object)((int32_t)(v127) + 0x10);
    v94 = v127;
    goto v60;

v98:
    v186 = v94;
    v127 = v108;
    v127 = (Lisp_Object)(int32_t)((int32_t)v186 + (int32_t)v127 - TAG_FIXNUM);
    v90 = v462;
    v89 = v127;
    v186 = v462;
    v88 = *(Lisp_Object *)((char *)v186 + (CELL-TAG_VECTOR) + ((int32_t)v127/(16/CELL)));
    v187 = v212;
    v186 = v124;
    v127 = v108;
    v127 = *(Lisp_Object *)((char *)v186 + (CELL-TAG_VECTOR) + ((int32_t)v127/(16/CELL)));
    v127 = Lmodular_times(nil, v187, v127);
    env = stack[0];
    {   int32_t w = int_of_fixnum(v88) + int_of_fixnum(v127);
        if (w >= current_modulus) w -= current_modulus;
        v127 = fixnum_of_int(w);
    }
    *(Lisp_Object *)((char *)v90 + (CELL-TAG_VECTOR) + ((int32_t)v89/(16/CELL))) = v127;
    v127 = v108;
    v127 = (Lisp_Object)((int32_t)(v127) + 0x10);
    v108 = v127;
    goto v143;

v150:
    v187 = v462;
    v186 = v88;
    v127 = (Lisp_Object)1; /* 0 */
    *(Lisp_Object *)((char *)v187 + (CELL-TAG_VECTOR) + ((int32_t)v186/(16/CELL))) = v127;
    v127 = v88;
    v127 = (Lisp_Object)((int32_t)(v127) + 0x10);
    v88 = v127;
    goto v52;

v2:
    v127 = (Lisp_Object)-15; /* -1 */
    { popv(1); return onevalue(v127); }
}



/* Code for treesizep1 */

static Lisp_Object CC_treesizep1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v53, v14;
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



/* Code for ps!:get!-term */

static Lisp_Object CC_psTgetKterm(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v233, v231, v218;
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
    v233 = stack[-2];
    fn = elt(env, 3); /* ps!:order */
    stack[0] = (*qfn1(fn))(qenv(fn), v233);
    nil = C_nil;
    if (exception_pending()) goto v138;
    env = stack[-4];
    v233 = stack[-2];
    fn = elt(env, 4); /* ps!:last!-term */
    v233 = (*qfn1(fn))(qenv(fn), v233);
    nil = C_nil;
    if (exception_pending()) goto v138;
    env = stack[-4];
    stack[-3] = stack[0];
    stack[0] = v233;
    v231 = stack[-1];
    v233 = stack[-3];
    v233 = (Lisp_Object)lessp2(v231, v233);
    nil = C_nil;
    if (exception_pending()) goto v138;
    v233 = v233 ? lisp_true : nil;
    env = stack[-4];
    if (v233 == nil) goto v23;
    v231 = nil;
    v233 = (Lisp_Object)17; /* 1 */
    popv(5);
    return cons(v231, v233);

v23:
    v231 = stack[-1];
    v233 = stack[0];
    v233 = (Lisp_Object)greaterp2(v231, v233);
    nil = C_nil;
    if (exception_pending()) goto v138;
    v233 = v233 ? lisp_true : nil;
    env = stack[-4];
    if (v233 == nil) goto v35;
    v233 = nil;
    { popv(5); return onevalue(v233); }

v35:
    v231 = stack[-1];
    v233 = stack[-3];
    stack[0] = difference2(v231, v233);
    nil = C_nil;
    if (exception_pending()) goto v138;
    env = stack[-4];
    v233 = stack[-2];
    if (!consp(v233)) goto v85;
    v233 = stack[-2];
    v231 = qcar(v233);
    v233 = elt(env, 1); /* !:ps!: */
    v233 = Lneq(nil, v231, v233);
    nil = C_nil;
    if (exception_pending()) goto v138;
    env = stack[-4];
    if (v233 == nil) goto v142;
    v233 = stack[-2];
    v231 = qcar(v233);
    v233 = elt(env, 2); /* dname */
    v233 = get(v231, v233);
    env = stack[-4];
    if (!(v233 == nil)) goto v85;

v142:
    v231 = stack[-2];
    v233 = (Lisp_Object)81; /* 5 */
    fn = elt(env, 5); /* ps!:getv */
    v233 = (*qfn2(fn))(qenv(fn), v231, v233);
    nil = C_nil;
    if (exception_pending()) goto v138;
    goto v50;

v50:
    v233 = Lassoc(nil, stack[0], v233);
    v231 = v233;
    v233 = v231;
    if (v233 == nil) goto v117;
    v233 = v231;
    v233 = qcdr(v233);
    { popv(5); return onevalue(v233); }

v117:
    v231 = nil;
    v233 = (Lisp_Object)17; /* 1 */
    popv(5);
    return cons(v231, v233);

v85:
    v218 = (Lisp_Object)1; /* 0 */
    v231 = stack[-2];
    v233 = (Lisp_Object)17; /* 1 */
    v233 = list2star(v218, v231, v233);
    nil = C_nil;
    if (exception_pending()) goto v138;
    env = stack[-4];
    v233 = ncons(v233);
    nil = C_nil;
    if (exception_pending()) goto v138;
    goto v50;
/* error exit handlers */
v138:
    popv(5);
    return nil;
}



/* Code for vdpgetprop */

static Lisp_Object CC_vdpgetprop(Lisp_Object env,
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



/* Code for !:difference */

static Lisp_Object CC_Tdifference(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v35, v34, v39, v40;
    Lisp_Object fn;
    CSL_IGNORE(nil);
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



/* Code for areallindices */

static Lisp_Object CC_areallindices(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v44;
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
    CSL_IGNORE(nil);
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
    v261 = (Lisp_Object)(int32_t)((int32_t)v180 + (int32_t)v261 - TAG_FIXNUM);
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
    v261 = (Lisp_Object)(int32_t)((int32_t)v180 + (int32_t)v261 - TAG_FIXNUM);
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
    v261 = (Lisp_Object)(int32_t)((int32_t)v180 + (int32_t)v261 - TAG_FIXNUM);
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
    v261 = (Lisp_Object)(int32_t)((int32_t)v180 + (int32_t)v261 - TAG_FIXNUM);
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
    CSL_IGNORE(nil);
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
    CSL_IGNORE(nil);
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
    v441 = *(Lisp_Object *)((char *)v441 + (CELL-TAG_VECTOR) + ((int32_t)v340/(16/CELL)));
    v340 = stack[-4];
    v441 = *(Lisp_Object *)((char *)v441 + (CELL-TAG_VECTOR) + ((int32_t)v340/(16/CELL)));
    v340 = (Lisp_Object)1; /* 0 */
    if (v441 == v340) goto v57;
    v441 = v260;
    v340 = stack[-4];
    if (!(((int32_t)(v441)) < ((int32_t)(v340)))) goto v107;
    v441 = stack[-2];
    v340 = v260;
    v441 = *(Lisp_Object *)((char *)v441 + (CELL-TAG_VECTOR) + ((int32_t)v340/(16/CELL)));
    v340 = v260;
    v441 = *(Lisp_Object *)((char *)v441 + (CELL-TAG_VECTOR) + ((int32_t)v340/(16/CELL)));
    v340 = (Lisp_Object)1; /* 0 */
    if (!(v441 == v340)) goto v57;

v107:
    v441 = stack[-2];
    v340 = v260;
    v340 = *(Lisp_Object *)((char *)v441 + (CELL-TAG_VECTOR) + ((int32_t)v340/(16/CELL)));
    stack[-5] = v340;
    v491 = stack[-2];
    v441 = v260;
    v260 = stack[-2];
    v340 = stack[-4];
    v340 = *(Lisp_Object *)((char *)v260 + (CELL-TAG_VECTOR) + ((int32_t)v340/(16/CELL)));
    *(Lisp_Object *)((char *)v491 + (CELL-TAG_VECTOR) + ((int32_t)v441/(16/CELL))) = v340;
    v441 = stack[-2];
    v260 = stack[-4];
    v340 = stack[-5];
    *(Lisp_Object *)((char *)v441 + (CELL-TAG_VECTOR) + ((int32_t)v260/(16/CELL))) = v340;
    v260 = stack[-2];
    v340 = stack[-4];
    v260 = *(Lisp_Object *)((char *)v260 + (CELL-TAG_VECTOR) + ((int32_t)v340/(16/CELL)));
    v340 = stack[-4];
    v340 = *(Lisp_Object *)((char *)v260 + (CELL-TAG_VECTOR) + ((int32_t)v340/(16/CELL)));
    v340 = Lmodular_reciprocal(nil, v340);
    nil = C_nil;
    if (exception_pending()) goto v339;
    env = stack[-6];
    {   int32_t w = int_of_fixnum(v340);
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
    v340 = (Lisp_Object)(int32_t)((int32_t)v260 - (int32_t)v340 + TAG_FIXNUM);
    v340 = ((intptr_t)(v340) < 0 ? lisp_true : nil);
    if (v340 == nil) goto v461;
    v340 = stack[-4];
    v320 = v340;
    goto v302;

v302:
    v260 = stack[-1];
    v340 = v320;
    v340 = (Lisp_Object)(int32_t)((int32_t)v260 - (int32_t)v340 + TAG_FIXNUM);
    v340 = ((intptr_t)(v340) < 0 ? lisp_true : nil);
    if (!(v340 == nil)) { Lisp_Object res = stack[-3]; popv(7); return onevalue(res); }
    v260 = stack[-2];
    v340 = stack[-4];
    v491 = *(Lisp_Object *)((char *)v260 + (CELL-TAG_VECTOR) + ((int32_t)v340/(16/CELL)));
    v441 = v320;
    v260 = stack[-2];
    v340 = stack[-4];
    v260 = *(Lisp_Object *)((char *)v260 + (CELL-TAG_VECTOR) + ((int32_t)v340/(16/CELL)));
    v340 = v320;
    v260 = *(Lisp_Object *)((char *)v260 + (CELL-TAG_VECTOR) + ((int32_t)v340/(16/CELL)));
    v340 = stack[-5];
    v340 = Lmodular_times(nil, v260, v340);
    env = stack[-6];
    *(Lisp_Object *)((char *)v491 + (CELL-TAG_VECTOR) + ((int32_t)v441/(16/CELL))) = v340;
    v340 = v320;
    v340 = (Lisp_Object)((int32_t)(v340) + 0x10);
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
    v260 = *(Lisp_Object *)((char *)v260 + (CELL-TAG_VECTOR) + ((int32_t)v340/(16/CELL)));
    v340 = stack[-4];
    v340 = *(Lisp_Object *)((char *)v260 + (CELL-TAG_VECTOR) + ((int32_t)v340/(16/CELL)));
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
    v340 = (Lisp_Object)(int32_t)((int32_t)v260 - (int32_t)v340 + TAG_FIXNUM);
    v340 = ((intptr_t)(v340) < 0 ? lisp_true : nil);
    if (!(v340 == nil)) goto v110;
    v260 = stack[-2];
    v340 = stack[0];
    v495 = *(Lisp_Object *)((char *)v260 + (CELL-TAG_VECTOR) + ((int32_t)v340/(16/CELL)));
    v320 = v496;
    v260 = stack[-2];
    v340 = stack[0];
    v260 = *(Lisp_Object *)((char *)v260 + (CELL-TAG_VECTOR) + ((int32_t)v340/(16/CELL)));
    v340 = v496;
    v491 = *(Lisp_Object *)((char *)v260 + (CELL-TAG_VECTOR) + ((int32_t)v340/(16/CELL)));
    v441 = v424;
    v260 = stack[-2];
    v340 = stack[-4];
    v260 = *(Lisp_Object *)((char *)v260 + (CELL-TAG_VECTOR) + ((int32_t)v340/(16/CELL)));
    v340 = v496;
    v340 = *(Lisp_Object *)((char *)v260 + (CELL-TAG_VECTOR) + ((int32_t)v340/(16/CELL)));
    v340 = Lmodular_times(nil, v441, v340);
    env = stack[-6];
    {   int32_t w = int_of_fixnum(v491) + int_of_fixnum(v340);
        if (w >= current_modulus) w -= current_modulus;
        v340 = fixnum_of_int(w);
    }
    *(Lisp_Object *)((char *)v495 + (CELL-TAG_VECTOR) + ((int32_t)v320/(16/CELL))) = v340;
    v340 = v496;
    v340 = (Lisp_Object)((int32_t)(v340) + 0x10);
    v496 = v340;
    goto v316;

v110:
    v340 = stack[0];
    v340 = (Lisp_Object)((int32_t)(v340) + 0x10);
    stack[0] = v340;
    goto v216;

v57:
    v340 = v260;
    v441 = (Lisp_Object)((int32_t)(v340) + 0x10);
    v260 = v441;
    v340 = stack[-1];
    if (!(((int32_t)(v441)) > ((int32_t)(v340)))) goto v17;
    v260 = stack[-4];
    v340 = stack[-3];
    popv(7);
    return cons(v260, v340);
/* error exit handlers */
v339:
    popv(7);
    return nil;
}



/* Code for omobjs */

static Lisp_Object MS_CDECL CC_omobjs(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v33, v51;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "omobjs");
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
    v51 = qvalue(elt(env, 1)); /* char */
    v33 = elt(env, 2); /* (!/ o m a) */
    v33 = Lneq(nil, v51, v33);
    nil = C_nil;
    if (exception_pending()) goto v49;
    env = stack[-1];
    if (v33 == nil) goto v12;
    fn = elt(env, 3); /* omobj */
    v33 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v49;
    env = stack[-1];
    stack[0] = v33;
    fn = elt(env, 4); /* lex */
    v33 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v49;
    env = stack[-1];
    v33 = CC_omobjs(env, 0);
    nil = C_nil;
    if (exception_pending()) goto v49;
    v51 = stack[0];
    if (v51 == nil) goto v17;
    v51 = stack[0];
    popv(2);
    return cons(v51, v33);

v17:
    v51 = stack[0];
        popv(2);
        return Lappend(nil, v51, v33);

v12:
    v33 = nil;
    { popv(2); return onevalue(v33); }
/* error exit handlers */
v49:
    popv(2);
    return nil;
}



/* Code for letmtr3 */

static Lisp_Object MS_CDECL CC_letmtr3(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v16,
                         Lisp_Object v63, Lisp_Object v9, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v495, v496, v424, v359;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "letmtr3");
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
    stack[-6] = nil;
    v495 = stack[-5];
    v495 = qcdr(v495);
    v495 = qcdr(v495);
    if (v495 == nil) goto v19;
    v496 = stack[-3];
    v495 = elt(env, 1); /* sparsemat */
    if (!consp(v496)) goto v81;
    v496 = qcar(v496);
    if (!(v496 == v495)) goto v81;
    v495 = stack[-5];
    v495 = qcdr(v495);
    fn = elt(env, 7); /* revlis */
    v495 = (*qfn1(fn))(qenv(fn), v495);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-7];
    stack[-6] = v495;
    fn = elt(env, 8); /* numlis */
    v495 = (*qfn1(fn))(qenv(fn), v495);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-7];
    if (v495 == nil) goto v216;
    v495 = stack[-6];
    v496 = Llength(nil, v495);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-7];
    v495 = (Lisp_Object)33; /* 2 */
    v495 = Lneq(nil, v496, v495);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-7];
    if (!(v495 == nil)) goto v216;

v92:
    v495 = stack[-3];
    v495 = qcdr(v495);
    v496 = qcar(v495);
    v495 = stack[-6];
    v495 = qcar(v495);
    v495 = *(Lisp_Object *)((char *)v496 + (CELL-TAG_VECTOR) + ((int32_t)v495/(16/CELL)));
    v359 = v495;
    v495 = v359;
    if (v495 == nil) goto v124;
    v495 = stack[-6];
    v495 = qcdr(v495);
    v496 = qcar(v495);
    v495 = v359;
    v495 = Latsoc(nil, v496, v495);
    v424 = v495;
    v495 = v424;
    if (v495 == nil) goto v253;
    v496 = stack[-4];
    v495 = (Lisp_Object)1; /* 0 */
    if (!(v496 == v495)) goto v296;
    v496 = stack[-2];
    v495 = elt(env, 6); /* cx */
    if (v496 == v495) goto v296;
    v495 = v359;
    v495 = qcdr(v495);
    v495 = qcdr(v495);
    if (v495 == nil) goto v247;
    stack[0] = v359;
    v495 = v424;
    v496 = v359;
    v495 = Ldelete(nil, v495, v496);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-7];
    v495 = qcdr(v495);
    v495 = Lrplacd(nil, stack[0], v495);
    nil = C_nil;
    if (exception_pending()) goto v151;
    goto v26;

v26:
    v495 = nil;
    { popv(8); return onevalue(v495); }

v247:
    v495 = stack[-3];
    v495 = qcdr(v495);
    v424 = qcar(v495);
    v495 = stack[-6];
    v496 = qcar(v495);
    v495 = nil;
    *(Lisp_Object *)((char *)v424 + (CELL-TAG_VECTOR) + ((int32_t)v496/(16/CELL))) = v495;
    goto v26;

v296:
    v496 = v424;
    v495 = stack[-4];
    v495 = Lrplacd(nil, v496, v495);
    nil = C_nil;
    if (exception_pending()) goto v151;
    goto v26;

v253:
    v496 = stack[-4];
    v495 = (Lisp_Object)1; /* 0 */
    if (!(v496 == v495)) goto v507;
    v496 = stack[-2];
    v495 = elt(env, 6); /* cx */
    if (!(v496 == v495)) goto v26;

v507:
    v495 = stack[-6];
    v495 = qcdr(v495);
    v496 = qcar(v495);
    v424 = v359;
    v495 = stack[-4];
    fn = elt(env, 9); /* sortcolelem */
    v495 = (*qfnn(fn))(qenv(fn), 3, v496, v424, v495);
    nil = C_nil;
    if (exception_pending()) goto v151;
    goto v26;

v124:
    v496 = stack[-4];
    v495 = (Lisp_Object)1; /* 0 */
    if (!(v496 == v495)) goto v184;
    v496 = stack[-2];
    v495 = elt(env, 6); /* cx */
    if (!(v496 == v495)) goto v26;

v184:
    v495 = stack[-3];
    v495 = qcdr(v495);
    stack[-2] = qcar(v495);
    v495 = stack[-6];
    stack[-1] = qcar(v495);
    v495 = nil;
    stack[0] = ncons(v495);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-7];
    v495 = stack[-6];
    v495 = qcdr(v495);
    v496 = qcar(v495);
    v495 = stack[-4];
    v495 = cons(v496, v495);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-7];
    v495 = list2(stack[0], v495);
    nil = C_nil;
    if (exception_pending()) goto v151;
    *(Lisp_Object *)((char *)stack[-2] + (CELL-TAG_VECTOR) + ((int32_t)stack[-1]/(16/CELL))) = v495;
    goto v26;

v216:
    v496 = stack[-5];
    v495 = elt(env, 5); /* hold */
    {
        popv(8);
        fn = elt(env, 10); /* errpri2 */
        return (*qfn2(fn))(qenv(fn), v496, v495);
    }

v81:
    stack[-1] = elt(env, 2); /* matrix */
    stack[0] = (Lisp_Object)161; /* 10 */
    v424 = elt(env, 3); /* "Matrix" */
    v495 = stack[-5];
    v496 = qcar(v495);
    v495 = elt(env, 4); /* "not set" */
    v495 = list3(v424, v496, v495);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-7];
    fn = elt(env, 11); /* rerror */
    v495 = (*qfnn(fn))(qenv(fn), 3, stack[-1], stack[0], v495);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-7];
    goto v92;

v19:
    v496 = stack[-3];
    v495 = elt(env, 1); /* sparsemat */
    if (!consp(v496)) goto v53;
    v496 = qcar(v496);
    if (!(v496 == v495)) goto v53;
    v495 = stack[-5];
    v495 = qcdr(v495);
    fn = elt(env, 7); /* revlis */
    v495 = (*qfn1(fn))(qenv(fn), v495);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-7];
    stack[-6] = v495;
    fn = elt(env, 8); /* numlis */
    v495 = (*qfn1(fn))(qenv(fn), v495);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-7];
    if (v495 == nil) goto v58;
    v495 = stack[-6];
    v496 = Llength(nil, v495);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-7];
    v495 = (Lisp_Object)17; /* 1 */
    v495 = Lneq(nil, v496, v495);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-7];
    if (!(v495 == nil)) goto v58;

v95:
    v495 = stack[-3];
    v495 = qcdr(v495);
    v424 = qcar(v495);
    v495 = stack[-5];
    v495 = qcdr(v495);
    v496 = qcar(v495);
    v495 = stack[-4];
    *(Lisp_Object *)((char *)v424 + (CELL-TAG_VECTOR) + ((int32_t)v496/(16/CELL))) = v495;
    goto v26;

v58:
    v496 = stack[-5];
    v495 = elt(env, 5); /* hold */
    {
        popv(8);
        fn = elt(env, 10); /* errpri2 */
        return (*qfn2(fn))(qenv(fn), v496, v495);
    }

v53:
    stack[-1] = elt(env, 2); /* matrix */
    stack[0] = (Lisp_Object)161; /* 10 */
    v424 = elt(env, 3); /* "Matrix" */
    v495 = stack[-5];
    v496 = qcar(v495);
    v495 = elt(env, 4); /* "not set" */
    v495 = list3(v424, v496, v495);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-7];
    fn = elt(env, 11); /* rerror */
    v495 = (*qfnn(fn))(qenv(fn), 3, stack[-1], stack[0], v495);
    nil = C_nil;
    if (exception_pending()) goto v151;
    goto v95;
/* error exit handlers */
v151:
    popv(8);
    return nil;
}



/* Code for genp */

static Lisp_Object CC_genp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v15, v43, v29;
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
    v43 = v0;
/* end of prologue */
    v15 = v43;
    if (!consp(v15)) goto v25;
    v15 = nil;
    { popv(1); return onevalue(v15); }

v25:
    v29 = v43;
    v15 = elt(env, 1); /* gen */
    v15 = get(v29, v15);
    env = stack[0];
    if (!(v15 == nil)) { popv(1); return onevalue(v15); }
    v15 = v43;
    {
        popv(1);
        fn = elt(env, 2); /* mgenp */
        return (*qfn1(fn))(qenv(fn), v15);
    }
}



/* Code for termordp */

static Lisp_Object CC_termordp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v2;
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
    v25 = v0;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* g_sc_ve */
    v25 = sub1(v25);
    nil = C_nil;
    if (exception_pending()) goto v24;
    v25 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v25/(16/CELL)));
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
    v232 = (Lisp_Object)(int32_t)((int32_t)v127 + (int32_t)v232 - TAG_FIXNUM);
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



/* Code for matrix!+p */

static Lisp_Object CC_matrixLp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v41, v64;
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
    v41 = stack[0];
    v64 = Llength(nil, v41);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-4];
    v41 = (Lisp_Object)17; /* 1 */
    v41 = (Lisp_Object)lessp2(v64, v41);
    nil = C_nil;
    if (exception_pending()) goto v69;
    v41 = v41 ? lisp_true : nil;
    env = stack[-4];
    if (v41 == nil) goto v5;
    v41 = nil;
    { popv(5); return onevalue(v41); }

v5:
    v41 = stack[0];
    v41 = qcar(v41);
    v41 = Llength(nil, v41);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-4];
    stack[-3] = v41;
    v41 = lisp_true;
    stack[-2] = v41;
    v41 = stack[0];
    v41 = qcdr(v41);
    stack[-1] = v41;
    goto v19;

v19:
    v41 = stack[-1];
    if (v41 == nil) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v41 = stack[-1];
    v41 = qcar(v41);
    stack[0] = stack[-3];
    v41 = Llength(nil, v41);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-4];
    if (equal(stack[0], v41)) goto v37;
    v41 = nil;
    stack[-2] = v41;
    goto v37;

v37:
    v41 = stack[-1];
    v41 = qcdr(v41);
    stack[-1] = v41;
    goto v19;
/* error exit handlers */
v69:
    popv(5);
    return nil;
}



/* Code for sfto_dcontentf1 */

static Lisp_Object CC_sfto_dcontentf1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v193, v35, v34;
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
    v35 = v0;
/* end of prologue */

v8:
    v34 = stack[0];
    v193 = (Lisp_Object)17; /* 1 */
    if (v34 == v193) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v193 = v35;
    if (!consp(v193)) goto v18;
    v193 = v35;
    v193 = qcar(v193);
    if (!consp(v193)) goto v18;
    v193 = v35;
    v193 = qcdr(v193);
    stack[-1] = v193;
    v193 = v35;
    v193 = qcar(v193);
    v35 = qcdr(v193);
    v193 = stack[0];
    v193 = CC_sfto_dcontentf1(env, v35, v193);
    nil = C_nil;
    if (exception_pending()) goto v206;
    env = stack[-2];
    stack[0] = v193;
    v193 = stack[-1];
    v35 = v193;
    goto v8;

v18:
    v193 = v35;
    fn = elt(env, 1); /* absf */
    v35 = (*qfn1(fn))(qenv(fn), v193);
    nil = C_nil;
    if (exception_pending()) goto v206;
    env = stack[-2];
    v193 = stack[0];
    {
        popv(3);
        fn = elt(env, 2); /* sfto_gcdf */
        return (*qfn2(fn))(qenv(fn), v35, v193);
    }
/* error exit handlers */
v206:
    popv(3);
    return nil;
}



/* Code for isarb_int */

static Lisp_Object CC_isarb_int(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v20, v21, v22;
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
    v21 = v0;
/* end of prologue */
    v20 = v21;
    v20 = Lconsp(nil, v20);
    env = stack[0];
    if (v20 == nil) goto v4;
    v20 = v21;
    v22 = qcar(v20);
    v20 = elt(env, 1); /* arbint */
    if (v22 == v20) goto v1;
    v20 = v21;
    v20 = qcdr(v20);
    fn = elt(env, 3); /* multi_isarb_int */
    v20 = (*qfn1(fn))(qenv(fn), v20);
    nil = C_nil;
    if (exception_pending()) goto v23;
    goto v4;

v4:
    v20 = nil;
    { popv(1); return onevalue(v20); }

v1:
    v20 = (Lisp_Object)17; /* 1 */
    qvalue(elt(env, 2)) = v20; /* found_int */
    goto v4;
/* error exit handlers */
v23:
    popv(1);
    return nil;
}



/* Code for testred */

static Lisp_Object CC_testred(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v80, v116, v114;
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
    stack[-1] = qvalue(elt(env, 1)); /* codmat */
    v116 = qvalue(elt(env, 2)); /* maxvar */
    v80 = stack[0];
    v80 = plus2(v116, v80);
    nil = C_nil;
    if (exception_pending()) goto v133;
    env = stack[-2];
    v116 = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v80/(16/CELL)));
    v80 = (Lisp_Object)1; /* 0 */
    v80 = *(Lisp_Object *)((char *)v116 + (CELL-TAG_VECTOR) + ((int32_t)v80/(16/CELL)));
    if (v80 == nil) goto v4;
    stack[-1] = qvalue(elt(env, 1)); /* codmat */
    v116 = qvalue(elt(env, 2)); /* maxvar */
    v80 = stack[0];
    v80 = plus2(v116, v80);
    nil = C_nil;
    if (exception_pending()) goto v133;
    env = stack[-2];
    v116 = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v80/(16/CELL)));
    v80 = (Lisp_Object)17; /* 1 */
    v80 = *(Lisp_Object *)((char *)v116 + (CELL-TAG_VECTOR) + ((int32_t)v80/(16/CELL)));
    v80 = qcar(v80);
    v116 = qcar(v80);
    v80 = (Lisp_Object)33; /* 2 */
    v80 = (Lisp_Object)lessp2(v116, v80);
    nil = C_nil;
    if (exception_pending()) goto v133;
    v80 = v80 ? lisp_true : nil;
    env = stack[-2];
    if (v80 == nil) goto v4;
    stack[-1] = qvalue(elt(env, 1)); /* codmat */
    v116 = qvalue(elt(env, 2)); /* maxvar */
    v80 = stack[0];
    v80 = plus2(v116, v80);
    nil = C_nil;
    if (exception_pending()) goto v133;
    env = stack[-2];
    v114 = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v80/(16/CELL)));
    v116 = (Lisp_Object)1; /* 0 */
    v80 = nil;
    *(Lisp_Object *)((char *)v114 + (CELL-TAG_VECTOR) + ((int32_t)v116/(16/CELL))) = v80;
    stack[-1] = qvalue(elt(env, 1)); /* codmat */
    v116 = qvalue(elt(env, 2)); /* maxvar */
    v80 = stack[0];
    v80 = plus2(v116, v80);
    nil = C_nil;
    if (exception_pending()) goto v133;
    env = stack[-2];
    v116 = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v80/(16/CELL)));
    v80 = (Lisp_Object)65; /* 4 */
    v80 = *(Lisp_Object *)((char *)v116 + (CELL-TAG_VECTOR) + ((int32_t)v80/(16/CELL)));
    stack[-1] = v80;
    goto v86;

v86:
    v80 = stack[-1];
    if (v80 == nil) goto v97;
    v80 = stack[-1];
    v80 = qcar(v80);
    stack[0] = v80;
    v80 = stack[0];
    v116 = qcar(v80);
    v80 = stack[0];
    v80 = qcdr(v80);
    v80 = qcar(v80);
    fn = elt(env, 3); /* downwght1 */
    v80 = (*qfn2(fn))(qenv(fn), v116, v80);
    nil = C_nil;
    if (exception_pending()) goto v133;
    env = stack[-2];
    v80 = stack[0];
    v80 = qcar(v80);
    v80 = CC_testred(env, v80);
    nil = C_nil;
    if (exception_pending()) goto v133;
    env = stack[-2];
    v80 = stack[-1];
    v80 = qcdr(v80);
    stack[-1] = v80;
    goto v86;

v97:
    v80 = nil;
    { popv(3); return onevalue(v80); }

v4:
    v80 = nil;
    { popv(3); return onevalue(v80); }
/* error exit handlers */
v133:
    popv(3);
    return nil;
}



/* Code for xdegreemon */

static Lisp_Object CC_xdegreemon(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v42, v49, v50;
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
    CSL_IGNORE(nil);
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
    CSL_IGNORE(nil);
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



/* Code for isarb_compl */

static Lisp_Object CC_isarb_compl(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v20, v21, v22;
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
    v21 = v0;
/* end of prologue */
    v20 = v21;
    v20 = Lconsp(nil, v20);
    env = stack[0];
    if (v20 == nil) goto v4;
    v20 = v21;
    v22 = qcar(v20);
    v20 = elt(env, 1); /* arbcomplex */
    if (v22 == v20) goto v1;
    v20 = v21;
    v20 = qcdr(v20);
    fn = elt(env, 3); /* multi_isarb_compl */
    v20 = (*qfn1(fn))(qenv(fn), v20);
    nil = C_nil;
    if (exception_pending()) goto v23;
    goto v4;

v4:
    v20 = nil;
    { popv(1); return onevalue(v20); }

v1:
    v20 = (Lisp_Object)17; /* 1 */
    qvalue(elt(env, 2)) = v20; /* found_compl */
    goto v4;
/* error exit handlers */
v23:
    popv(1);
    return nil;
}



/* Code for initbrsea */

static Lisp_Object MS_CDECL CC_initbrsea(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v113, v217, v223;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "initbrsea");
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
    v113 = (Lisp_Object)3201; /* 200 */
    stack[-2] = v113;
    v113 = qvalue(elt(env, 1)); /* rowmin */
    stack[-1] = v113;
    goto v24;

v24:
    v217 = qvalue(elt(env, 2)); /* rowmax */
    v113 = stack[-1];
    v113 = difference2(v217, v113);
    nil = C_nil;
    if (exception_pending()) goto v233;
    env = stack[-3];
    v113 = Lminusp(nil, v113);
    env = stack[-3];
    if (v113 == nil) goto v30;
    fn = elt(env, 7); /* redcodmat */
    v113 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v233;
    env = stack[-3];
    v113 = qvalue(elt(env, 5)); /* codhisto */
    if (v113 == nil) goto v141;
    v113 = (Lisp_Object)1; /* 0 */
    stack[0] = v113;
    goto v101;

v101:
    v217 = (Lisp_Object)3201; /* 200 */
    v113 = stack[0];
    v113 = difference2(v217, v113);
    nil = C_nil;
    if (exception_pending()) goto v233;
    env = stack[-3];
    v113 = Lminusp(nil, v113);
    env = stack[-3];
    if (!(v113 == nil)) goto v41;
    v223 = qvalue(elt(env, 5)); /* codhisto */
    v217 = stack[0];
    v113 = nil;
    *(Lisp_Object *)((char *)v223 + (CELL-TAG_VECTOR) + ((int32_t)v217/(16/CELL))) = v113;
    v113 = stack[0];
    v113 = add1(v113);
    nil = C_nil;
    if (exception_pending()) goto v233;
    env = stack[-3];
    stack[0] = v113;
    goto v101;

v41:
    v113 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 6)) = v113; /* headhisto */
    v113 = (Lisp_Object)1; /* 0 */
    stack[0] = v113;
    goto v143;

v143:
    v217 = qvalue(elt(env, 2)); /* rowmax */
    v113 = stack[0];
    v113 = difference2(v217, v113);
    nil = C_nil;
    if (exception_pending()) goto v233;
    env = stack[-3];
    v113 = Lminusp(nil, v113);
    env = stack[-3];
    if (v113 == nil) goto v456;
    v113 = nil;
    { popv(4); return onevalue(v113); }

v456:
    v113 = stack[0];
    fn = elt(env, 8); /* inshisto */
    v113 = (*qfn1(fn))(qenv(fn), v113);
    nil = C_nil;
    if (exception_pending()) goto v233;
    env = stack[-3];
    v113 = stack[0];
    v113 = add1(v113);
    nil = C_nil;
    if (exception_pending()) goto v233;
    env = stack[-3];
    stack[0] = v113;
    goto v143;

v141:
    v113 = stack[-2];
    v113 = Lmkvect(nil, v113);
    nil = C_nil;
    if (exception_pending()) goto v233;
    env = stack[-3];
    qvalue(elt(env, 5)) = v113; /* codhisto */
    goto v41;

v30:
    stack[0] = qvalue(elt(env, 3)); /* codmat */
    v217 = qvalue(elt(env, 4)); /* maxvar */
    v113 = stack[-1];
    v113 = plus2(v217, v113);
    nil = C_nil;
    if (exception_pending()) goto v233;
    env = stack[-3];
    v217 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v113/(16/CELL)));
    v113 = (Lisp_Object)1; /* 0 */
    v113 = *(Lisp_Object *)((char *)v217 + (CELL-TAG_VECTOR) + ((int32_t)v113/(16/CELL)));
    if (v113 == nil) goto v29;
    v113 = stack[-1];
    fn = elt(env, 9); /* initwght */
    v113 = (*qfn1(fn))(qenv(fn), v113);
    nil = C_nil;
    if (exception_pending()) goto v233;
    env = stack[-3];
    goto v29;

v29:
    v113 = stack[-1];
    v113 = add1(v113);
    nil = C_nil;
    if (exception_pending()) goto v233;
    env = stack[-3];
    stack[-1] = v113;
    goto v24;
/* error exit handlers */
v233:
    popv(4);
    return nil;
}



/* Code for convchk */

static Lisp_Object CC_convchk(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v150, v134, v105;
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
    CSL_IGNORE(nil);
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v7 = v0;
/* end of prologue */
    v8 = elt(env, 1); /* !*optype!* */
    return get(v7, v8);
}



/* Code for mv!-pow!-mv!-term!-!+ */

static Lisp_Object CC_mvKpowKmvKtermKL(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v38, v44;
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



/* Code for psum */

static Lisp_Object CC_psum(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v90, v108, v94;
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
    CSL_IGNORE(nil);
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
    CSL_IGNORE(nil);
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



/* Code for ev_comp */

static Lisp_Object CC_ev_comp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v27, v28;
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
    v27 = v16;
    v28 = v0;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* dip_sortevcomp!* */
    v27 = list2(v28, v27);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-1];
    {
        Lisp_Object v47 = stack[0];
        popv(2);
        fn = elt(env, 2); /* apply */
        return (*qfn2(fn))(qenv(fn), v47, v27);
    }
/* error exit handlers */
v44:
    popv(2);
    return nil;
}



/* Code for symtabget */

static Lisp_Object CC_symtabget(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v206, v41, v64, v100;
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
    v100 = v16;
    v64 = v0;
/* end of prologue */
    v206 = v100;
    if (v206 == nil) goto v3;
    v206 = v64;
    if (!(v206 == nil)) goto v6;
    v206 = qvalue(elt(env, 1)); /* !*symboltable!* */
    v206 = qcar(v206);
    goto v6;

v6:
    v64 = v206;
    goto v3;

v3:
    v206 = v64;
    if (v206 == nil) goto v24;
    v41 = v100;
    v206 = elt(env, 2); /* (!*type!* !*params!* !*decs!*) */
    v206 = Lmemq(nil, v41, v206);
    if (v206 == nil) goto v32;
    v206 = v64;
    v41 = v100;
    return get(v206, v41);

v32:
    v41 = v100;
    v206 = elt(env, 3); /* !*decs!* */
    v206 = get(v64, v206);
    v206 = Lassoc(nil, v41, v206);
    return onevalue(v206);

v24:
    v206 = qvalue(elt(env, 1)); /* !*symboltable!* */
    return onevalue(v206);
}



/* Code for dim!<deg */

static Lisp_Object CC_dimRdeg(Lisp_Object env,
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
    CSL_IGNORE(nil);
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



/* Code for cgp_evlmon */

static Lisp_Object CC_cgp_evlmon(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v4;
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
    v4 = v0;
/* end of prologue */
    fn = elt(env, 1); /* cgp_rp */
    v4 = (*qfn1(fn))(qenv(fn), v4);
    nil = C_nil;
    if (exception_pending()) goto v12;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* dip_evlmon */
        return (*qfn1(fn))(qenv(fn), v4);
    }
/* error exit handlers */
v12:
    popv(1);
    return nil;
}



/* Code for checktag */

static Lisp_Object CC_checktag(Lisp_Object env,
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
/* copy arguments values to proper place */
    v43 = v0;
/* end of prologue */
    v29 = qvalue(elt(env, 1)); /* char */
    v43 = Lneq(nil, v29, v43);
    nil = C_nil;
    if (exception_pending()) goto v17;
    env = stack[0];
    if (v43 == nil) goto v4;
    v29 = elt(env, 2); /* "Problem" */
    v43 = elt(env, 3); /* "problem" */
    fn = elt(env, 4); /* errorml */
    v43 = (*qfn2(fn))(qenv(fn), v29, v43);
    nil = C_nil;
    if (exception_pending()) goto v17;
    goto v4;

v4:
    v43 = nil;
    { popv(1); return onevalue(v43); }
/* error exit handlers */
v17:
    popv(1);
    return nil;
}



/* Code for vevmaptozero1 */

static Lisp_Object CC_vevmaptozero1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v43, v29;
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



/* Code for pneg */

static Lisp_Object CC_pneg(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v69, v67;
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



setup_type const u12_setup[] =
{
    {"pappl_pv",                too_few_2,      CC_pappl_pv,   wrong_no_2},
    {"arzerop:",                CC_arzeropT,    too_many_1,    wrong_no_1},
    {"general-plus-mod-p",      too_few_2,      CC_generalKplusKmodKp,wrong_no_2},
    {"free-powerp",             CC_freeKpowerp, too_many_1,    wrong_no_1},
    {"retattributes",           too_few_2,      CC_retattributes,wrong_no_2},
    {"bcsum",                   too_few_2,      CC_bcsum,      wrong_no_2},
    {"gsetsugar",               too_few_2,      CC_gsetsugar,  wrong_no_2},
    {"deg*form",                CC_degHform,    too_many_1,    wrong_no_1},
    {"vecopp",                  CC_vecopp,      too_many_1,    wrong_no_1},
    {"red-weight",              too_few_2,      CC_redKweight, wrong_no_2},
    {"divd",                    too_few_2,      CC_divd,       wrong_no_2},
    {"dp_term",                 too_few_2,      CC_dp_term,    wrong_no_2},
    {"gperm2",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_gperm2},
    {"times-in-vector",         wrong_no_na,    wrong_no_nb,   (n_args *)CC_timesKinKvector},
    {"treesizep1",              too_few_2,      CC_treesizep1, wrong_no_2},
    {"ps:get-term",             too_few_2,      CC_psTgetKterm,wrong_no_2},
    {"vdpgetprop",              too_few_2,      CC_vdpgetprop, wrong_no_2},
    {":difference",             too_few_2,      CC_Tdifference,wrong_no_2},
    {"areallindices",           CC_areallindices,too_many_1,   wrong_no_1},
    {"contrsp2",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_contrsp2},
    {"mo=deglist",              CC_moMdeglist,  too_many_1,    wrong_no_1},
    {"pdmult",                  too_few_2,      CC_pdmult,     wrong_no_2},
    {"aronep:",                 CC_aronepT,     too_many_1,    wrong_no_1},
    {"clear-column",            wrong_no_na,    wrong_no_nb,   (n_args *)CC_clearKcolumn},
    {"omobjs",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_omobjs},
    {"letmtr3",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_letmtr3},
    {"genp",                    CC_genp,        too_many_1,    wrong_no_1},
    {"termordp",                too_few_2,      CC_termordp,   wrong_no_2},
    {"cut:ep",                  too_few_2,      CC_cutTep,     wrong_no_2},
    {"getphystype",             CC_getphystype, too_many_1,    wrong_no_1},
    {"red-weight1",             too_few_2,      CC_redKweight1,wrong_no_2},
    {"sc_kern",                 CC_sc_kern,     too_many_1,    wrong_no_1},
    {"rnplus:",                 too_few_2,      CC_rnplusT,    wrong_no_2},
    {"general-times-term-mod-p",too_few_2,      CC_generalKtimesKtermKmodKp,wrong_no_2},
    {"matrix+p",                CC_matrixLp,    too_many_1,    wrong_no_1},
    {"sfto_dcontentf1",         too_few_2,      CC_sfto_dcontentf1,wrong_no_2},
    {"isarb_int",               CC_isarb_int,   too_many_1,    wrong_no_1},
    {"testred",                 CC_testred,     too_many_1,    wrong_no_1},
    {"xdegreemon",              CC_xdegreemon,  too_many_1,    wrong_no_1},
    {"make-set",                CC_makeKset,    too_many_1,    wrong_no_1},
    {"contr1-strand",           too_few_2,      CC_contr1Kstrand,wrong_no_2},
    {"mv-pow-minusp",           CC_mvKpowKminusp,too_many_1,   wrong_no_1},
    {"bas_make1",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_bas_make1},
    {"general-modular-quotient",too_few_2,      CC_generalKmodularKquotient,wrong_no_2},
    {"isarb_compl",             CC_isarb_compl, too_many_1,    wrong_no_1},
    {"initbrsea",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_initbrsea},
    {"convchk",                 CC_convchk,     too_many_1,    wrong_no_1},
    {"optype",                  CC_optype,      too_many_1,    wrong_no_1},
    {"mv-pow-mv-term-+",        too_few_2,      CC_mvKpowKmvKtermKL,wrong_no_2},
    {"dp_ecart",                CC_dp_ecart,    too_many_1,    wrong_no_1},
    {"psum",                    too_few_2,      CC_psum,       wrong_no_2},
    {"adddummy1a",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_adddummy1a},
    {"gizerop:",                CC_gizeropT,    too_many_1,    wrong_no_1},
    {"ev_comp",                 too_few_2,      CC_ev_comp,    wrong_no_2},
    {"symtabget",               too_few_2,      CC_symtabget,  wrong_no_2},
    {"dim<deg",                 CC_dimRdeg,     too_many_1,    wrong_no_1},
    {"lessp:",                  too_few_2,      CC_lesspT,     wrong_no_2},
    {"mv-pow-+",                too_few_2,      CC_mvKpowKL,   wrong_no_2},
    {"rnquotient:",             too_few_2,      CC_rnquotientT,wrong_no_2},
    {"general-modular-reciprocal",CC_generalKmodularKreciprocal,too_many_1,wrong_no_1},
    {"cgp_evlmon",              CC_cgp_evlmon,  too_many_1,    wrong_no_1},
    {"checktag",                CC_checktag,    too_many_1,    wrong_no_1},
    {"vevmaptozero1",           too_few_2,      CC_vevmaptozero1,wrong_no_2},
    {"addpf",                   too_few_2,      CC_addpf,      wrong_no_2},
    {"pneg",                    CC_pneg,        too_many_1,    wrong_no_1},
    {NULL, (one_args *)"u12", (two_args *)"3335 5811584 103971", 0}
};

/* end of generated code */
