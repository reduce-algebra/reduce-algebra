
/* $destdir/generated-c\u09.c Machine generated C code */

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


/* Code for prepsq!*1 */

static Lisp_Object MS_CDECL CC_prepsqH1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v16,
                         Lisp_Object v63, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v821, v374, v623;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "prepsq*1");
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
    stack[-4] = v63;
    stack[-5] = v16;
    stack[-6] = v0;
/* end of prologue */
    v821 = stack[-6];
    if (!consp(v821)) goto v7;
    v821 = stack[-6];
    v821 = qcar(v821);
    if (!consp(v821)) goto v7;
    v821 = stack[-6];
    v821 = qcar(v821);
    v821 = qcar(v821);
    v374 = qcar(v821);
    v821 = qvalue(elt(env, 1)); /* factors!* */
    v821 = Lmember(nil, v374, v821);
    if (!(v821 == nil)) goto v105;
    v821 = stack[-6];
    v821 = qcar(v821);
    v821 = qcar(v821);
    v821 = qcar(v821);
    if (!consp(v821)) goto v7;
    v821 = stack[-6];
    v821 = qcar(v821);
    v821 = qcar(v821);
    v821 = qcar(v821);
    v374 = qcar(v821);
    v821 = qvalue(elt(env, 1)); /* factors!* */
    v821 = Lmember(nil, v374, v821);
    if (!(v821 == nil)) goto v105;

v7:
    v821 = stack[-5];
    if (!consp(v821)) goto v221;
    v821 = stack[-5];
    v821 = qcar(v821);
    if (!consp(v821)) goto v221;
    v821 = qvalue(elt(env, 3)); /* kord!* */
    stack[-3] = v821;
    goto v202;

v202:
    v821 = stack[-3];
    if (v821 == nil) goto v221;
    v821 = stack[-3];
    v821 = qcar(v821);
    stack[-2] = v821;
    v821 = (Lisp_Object)1; /* 0 */
    stack[-1] = v821;
    v374 = stack[-2];
    v821 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 10); /* to */
    v374 = (*qfn2(fn))(qenv(fn), v374, v821);
    nil = C_nil;
    if (exception_pending()) goto v621;
    env = stack[-8];
    v821 = (Lisp_Object)17; /* 1 */
    v821 = cons(v374, v821);
    nil = C_nil;
    if (exception_pending()) goto v621;
    env = stack[-8];
    v821 = ncons(v821);
    nil = C_nil;
    if (exception_pending()) goto v621;
    env = stack[-8];
    stack[0] = v821;
    goto v344;

v344:
    v374 = stack[-5];
    v821 = stack[0];
    fn = elt(env, 11); /* quotfm */
    v821 = (*qfn2(fn))(qenv(fn), v374, v821);
    nil = C_nil;
    if (exception_pending()) goto v621;
    env = stack[-8];
    stack[-7] = v821;
    if (v821 == nil) goto v262;
    v821 = stack[-1];
    v821 = sub1(v821);
    nil = C_nil;
    if (exception_pending()) goto v621;
    env = stack[-8];
    stack[-1] = v821;
    v821 = stack[-7];
    stack[-5] = v821;
    goto v344;

v262:
    v374 = stack[-1];
    v821 = (Lisp_Object)1; /* 0 */
    v821 = (Lisp_Object)lessp2(v374, v821);
    nil = C_nil;
    if (exception_pending()) goto v621;
    v821 = v821 ? lisp_true : nil;
    env = stack[-8];
    if (v821 == nil) goto v300;
    v623 = elt(env, 2); /* expt */
    v374 = stack[-2];
    v821 = stack[-1];
    v374 = list3(v623, v374, v821);
    nil = C_nil;
    if (exception_pending()) goto v621;
    env = stack[-8];
    v821 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 12); /* mksp */
    v374 = (*qfn2(fn))(qenv(fn), v374, v821);
    nil = C_nil;
    if (exception_pending()) goto v621;
    env = stack[-8];
    v821 = stack[-4];
    v821 = cons(v374, v821);
    nil = C_nil;
    if (exception_pending()) goto v621;
    env = stack[-8];
    stack[-4] = v821;
    goto v300;

v300:
    v821 = stack[-3];
    v821 = qcdr(v821);
    stack[-3] = v821;
    goto v202;

v221:
    v821 = stack[-6];
    fn = elt(env, 13); /* kernlp */
    v821 = (*qfn1(fn))(qenv(fn), v821);
    nil = C_nil;
    if (exception_pending()) goto v621;
    env = stack[-8];
    if (v821 == nil) goto v426;
    v374 = stack[-4];
    v821 = stack[-6];
    fn = elt(env, 14); /* mkkl */
    v821 = (*qfn2(fn))(qenv(fn), v374, v821);
    nil = C_nil;
    if (exception_pending()) goto v621;
    env = stack[-8];
    stack[-6] = v821;
    v821 = nil;
    stack[-4] = v821;
    goto v426;

v426:
    v821 = qvalue(elt(env, 4)); /* dnl!* */
    if (v821 == nil) goto v339;
    v821 = qvalue(elt(env, 5)); /* !*allfac */
    if (v821 == nil) goto v196;
    v821 = stack[-6];
    fn = elt(env, 15); /* ckrn */
    v821 = (*qfn1(fn))(qenv(fn), v821);
    nil = C_nil;
    if (exception_pending()) goto v621;
    env = stack[-8];
    goto v195;

v195:
    stack[-1] = v821;
    v374 = stack[-1];
    v821 = qvalue(elt(env, 4)); /* dnl!* */
    fn = elt(env, 16); /* ckrn!* */
    v821 = (*qfn2(fn))(qenv(fn), v374, v821);
    nil = C_nil;
    if (exception_pending()) goto v621;
    env = stack[-8];
    stack[-7] = v821;
    v374 = stack[-1];
    v821 = stack[-7];
    fn = elt(env, 17); /* quotof */
    v821 = (*qfn2(fn))(qenv(fn), v374, v821);
    nil = C_nil;
    if (exception_pending()) goto v621;
    env = stack[-8];
    v374 = stack[-6];
    v821 = stack[-7];
    fn = elt(env, 17); /* quotof */
    v821 = (*qfn2(fn))(qenv(fn), v374, v821);
    nil = C_nil;
    if (exception_pending()) goto v621;
    env = stack[-8];
    stack[-6] = v821;
    v374 = stack[-5];
    v821 = stack[-7];
    fn = elt(env, 17); /* quotof */
    v821 = (*qfn2(fn))(qenv(fn), v374, v821);
    nil = C_nil;
    if (exception_pending()) goto v621;
    env = stack[-8];
    stack[-5] = v821;
    goto v339;

v339:
    v821 = qvalue(elt(env, 6)); /* upl!* */
    if (v821 == nil) goto v515;
    v821 = stack[-5];
    fn = elt(env, 15); /* ckrn */
    v821 = (*qfn1(fn))(qenv(fn), v821);
    nil = C_nil;
    if (exception_pending()) goto v621;
    env = stack[-8];
    stack[0] = v821;
    v374 = stack[0];
    v821 = qvalue(elt(env, 6)); /* upl!* */
    fn = elt(env, 16); /* ckrn!* */
    v821 = (*qfn2(fn))(qenv(fn), v374, v821);
    nil = C_nil;
    if (exception_pending()) goto v621;
    env = stack[-8];
    stack[-7] = v821;
    v374 = stack[0];
    v821 = stack[-7];
    fn = elt(env, 17); /* quotof */
    v821 = (*qfn2(fn))(qenv(fn), v374, v821);
    nil = C_nil;
    if (exception_pending()) goto v621;
    env = stack[-8];
    stack[0] = v821;
    v374 = stack[-6];
    v821 = stack[-7];
    fn = elt(env, 17); /* quotof */
    v821 = (*qfn2(fn))(qenv(fn), v374, v821);
    nil = C_nil;
    if (exception_pending()) goto v621;
    env = stack[-8];
    stack[-6] = v821;
    v374 = stack[-5];
    v821 = stack[-7];
    fn = elt(env, 17); /* quotof */
    v821 = (*qfn2(fn))(qenv(fn), v374, v821);
    nil = C_nil;
    if (exception_pending()) goto v621;
    env = stack[-8];
    stack[-5] = v821;
    goto v822;

v822:
    stack[-1] = stack[-6];
    v374 = stack[-5];
    v821 = stack[0];
    fn = elt(env, 17); /* quotof */
    v821 = (*qfn2(fn))(qenv(fn), v374, v821);
    nil = C_nil;
    if (exception_pending()) goto v621;
    env = stack[-8];
    v821 = cons(stack[-1], v821);
    nil = C_nil;
    if (exception_pending()) goto v621;
    env = stack[-8];
    fn = elt(env, 18); /* canonsq */
    v821 = (*qfn1(fn))(qenv(fn), v821);
    nil = C_nil;
    if (exception_pending()) goto v621;
    env = stack[-8];
    stack[-6] = v821;
    v821 = stack[-6];
    v374 = qcar(v821);
    v821 = stack[0];
    fn = elt(env, 17); /* quotof */
    v374 = (*qfn2(fn))(qenv(fn), v374, v821);
    nil = C_nil;
    if (exception_pending()) goto v621;
    env = stack[-8];
    v821 = stack[-6];
    v821 = qcdr(v821);
    v821 = cons(v374, v821);
    nil = C_nil;
    if (exception_pending()) goto v621;
    env = stack[-8];
    stack[-6] = v821;
    v821 = qvalue(elt(env, 5)); /* !*allfac */
    if (v821 == nil) goto v500;
    v821 = stack[-6];
    v821 = qcar(v821);
    fn = elt(env, 15); /* ckrn */
    v821 = (*qfn1(fn))(qenv(fn), v821);
    nil = C_nil;
    if (exception_pending()) goto v621;
    env = stack[-8];
    stack[-1] = v821;
    v821 = stack[-6];
    v821 = qcdr(v821);
    fn = elt(env, 15); /* ckrn */
    v821 = (*qfn1(fn))(qenv(fn), v821);
    nil = C_nil;
    if (exception_pending()) goto v621;
    env = stack[-8];
    stack[0] = v821;
    v374 = stack[-1];
    v821 = (Lisp_Object)17; /* 1 */
    v821 = Lneq(nil, v374, v821);
    nil = C_nil;
    if (exception_pending()) goto v621;
    env = stack[-8];
    if (!(v821 == nil)) goto v823;
    v374 = stack[0];
    v821 = (Lisp_Object)17; /* 1 */
    v821 = Lneq(nil, v374, v821);
    nil = C_nil;
    if (exception_pending()) goto v621;
    env = stack[-8];
    if (!(v821 == nil)) goto v823;

v500:
    v821 = stack[-4];
    if (v821 == nil) goto v824;
    v821 = stack[-4];
    fn = elt(env, 19); /* exchk */
    stack[0] = (*qfn1(fn))(qenv(fn), v821);
    nil = C_nil;
    if (exception_pending()) goto v621;
    env = stack[-8];
    v821 = stack[-6];
    fn = elt(env, 20); /* prepsq */
    v821 = (*qfn1(fn))(qenv(fn), v821);
    nil = C_nil;
    if (exception_pending()) goto v621;
    env = stack[-8];
    fn = elt(env, 21); /* aconc!* */
    v821 = (*qfn2(fn))(qenv(fn), stack[0], v821);
    nil = C_nil;
    if (exception_pending()) goto v621;
    env = stack[-8];
    fn = elt(env, 22); /* retimes */
    v821 = (*qfn1(fn))(qenv(fn), v821);
    nil = C_nil;
    if (exception_pending()) goto v621;
    popv(9);
    return ncons(v821);

v824:
    v821 = stack[-6];
    fn = elt(env, 20); /* prepsq */
    v821 = (*qfn1(fn))(qenv(fn), v821);
    nil = C_nil;
    if (exception_pending()) goto v621;
    env = stack[-8];
    {
        popv(9);
        fn = elt(env, 23); /* rmplus */
        return (*qfn1(fn))(qenv(fn), v821);
    }

v823:
    v374 = stack[-1];
    v821 = stack[-6];
    v821 = qcar(v821);
    v821 = Lneq(nil, v374, v821);
    nil = C_nil;
    if (exception_pending()) goto v621;
    env = stack[-8];
    if (!(v821 == nil)) goto v639;
    v374 = stack[0];
    v821 = stack[-6];
    v821 = qcdr(v821);
    v821 = Lneq(nil, v374, v821);
    nil = C_nil;
    if (exception_pending()) goto v621;
    env = stack[-8];
    if (v821 == nil) goto v500;
    else goto v639;

v639:
    v821 = stack[-6];
    v374 = qcdr(v821);
    v821 = stack[0];
    fn = elt(env, 17); /* quotof */
    v821 = (*qfn2(fn))(qenv(fn), v374, v821);
    nil = C_nil;
    if (exception_pending()) goto v621;
    env = stack[-8];
    stack[-5] = v821;
    v821 = stack[-6];
    v374 = qcar(v821);
    v821 = stack[-1];
    fn = elt(env, 17); /* quotof */
    v821 = (*qfn2(fn))(qenv(fn), v374, v821);
    nil = C_nil;
    if (exception_pending()) goto v621;
    env = stack[-8];
    stack[-6] = v821;
    v374 = stack[-4];
    v821 = stack[-1];
    fn = elt(env, 14); /* mkkl */
    v821 = (*qfn2(fn))(qenv(fn), v374, v821);
    nil = C_nil;
    if (exception_pending()) goto v621;
    env = stack[-8];
    fn = elt(env, 24); /* prepf */
    v821 = (*qfn1(fn))(qenv(fn), v821);
    nil = C_nil;
    if (exception_pending()) goto v621;
    env = stack[-8];
    stack[-4] = v821;
    v821 = stack[0];
    fn = elt(env, 24); /* prepf */
    v821 = (*qfn1(fn))(qenv(fn), v821);
    nil = C_nil;
    if (exception_pending()) goto v621;
    env = stack[-8];
    stack[-1] = v821;
    v374 = stack[-4];
    v821 = stack[-6];
    fn = elt(env, 25); /* addfactors */
    v821 = (*qfn2(fn))(qenv(fn), v374, v821);
    nil = C_nil;
    if (exception_pending()) goto v621;
    env = stack[-8];
    stack[-6] = v821;
    v374 = stack[-1];
    v821 = stack[-5];
    fn = elt(env, 25); /* addfactors */
    v821 = (*qfn2(fn))(qenv(fn), v374, v821);
    nil = C_nil;
    if (exception_pending()) goto v621;
    env = stack[-8];
    stack[-5] = v821;
    v374 = stack[-5];
    v821 = (Lisp_Object)17; /* 1 */
    if (v374 == v821) goto v390;
    v374 = stack[-6];
    v821 = elt(env, 8); /* minus */
    if (!consp(v374)) goto v694;
    v374 = qcar(v374);
    if (!(v374 == v821)) goto v694;
    stack[0] = elt(env, 8); /* minus */
    v623 = elt(env, 9); /* quotient */
    v821 = stack[-6];
    v821 = qcdr(v821);
    v374 = qcar(v821);
    v821 = stack[-5];
    v821 = list3(v623, v374, v821);
    nil = C_nil;
    if (exception_pending()) goto v621;
    env = stack[-8];
    v821 = list2(stack[0], v821);
    nil = C_nil;
    if (exception_pending()) goto v621;
    goto v388;

v388:
    popv(9);
    return ncons(v821);

v694:
    v623 = elt(env, 9); /* quotient */
    v374 = stack[-6];
    v821 = stack[-5];
    v821 = list3(v623, v374, v821);
    nil = C_nil;
    if (exception_pending()) goto v621;
    goto v388;

v390:
    v821 = stack[-6];
    {
        popv(9);
        fn = elt(env, 23); /* rmplus */
        return (*qfn1(fn))(qenv(fn), v821);
    }

v515:
    v821 = qvalue(elt(env, 7)); /* !*div */
    if (v821 == nil) goto v685;
    v821 = stack[-5];
    fn = elt(env, 15); /* ckrn */
    v821 = (*qfn1(fn))(qenv(fn), v821);
    nil = C_nil;
    if (exception_pending()) goto v621;
    env = stack[-8];
    stack[0] = v821;
    goto v822;

v685:
    v821 = (Lisp_Object)17; /* 1 */
    stack[0] = v821;
    goto v822;

v196:
    v821 = (Lisp_Object)17; /* 1 */
    goto v195;

v105:
    v374 = stack[-5];
    v821 = (Lisp_Object)17; /* 1 */
    if (v374 == v821) goto v58;
    v821 = stack[-6];
    v821 = qcar(v821);
    v821 = qcar(v821);
    v821 = qcdr(v821);
    stack[-2] = v821;
    v821 = stack[-5];
    stack[-1] = v821;
    v821 = stack[-6];
    v821 = qcar(v821);
    v821 = qcar(v821);
    v374 = qcar(v821);
    v821 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 10); /* to */
    v374 = (*qfn2(fn))(qenv(fn), v374, v821);
    nil = C_nil;
    if (exception_pending()) goto v621;
    env = stack[-8];
    v821 = (Lisp_Object)17; /* 1 */
    v821 = cons(v374, v821);
    nil = C_nil;
    if (exception_pending()) goto v621;
    env = stack[-8];
    v821 = ncons(v821);
    nil = C_nil;
    if (exception_pending()) goto v621;
    env = stack[-8];
    stack[0] = v821;
    goto v326;

v326:
    v374 = stack[-1];
    v821 = stack[0];
    fn = elt(env, 11); /* quotfm */
    v821 = (*qfn2(fn))(qenv(fn), v374, v821);
    nil = C_nil;
    if (exception_pending()) goto v621;
    env = stack[-8];
    stack[-7] = v821;
    if (v821 == nil) goto v216;
    v821 = stack[-7];
    stack[-1] = v821;
    v821 = stack[-2];
    v821 = sub1(v821);
    nil = C_nil;
    if (exception_pending()) goto v621;
    env = stack[-8];
    stack[-2] = v821;
    goto v326;

v216:
    v821 = stack[-6];
    v821 = qcar(v821);
    v374 = qcdr(v821);
    v821 = stack[-1];
    stack[0] = cons(v374, v821);
    nil = C_nil;
    if (exception_pending()) goto v621;
    env = stack[-8];
    v374 = stack[-2];
    v821 = (Lisp_Object)1; /* 0 */
    v821 = (Lisp_Object)greaterp2(v374, v821);
    nil = C_nil;
    if (exception_pending()) goto v621;
    v821 = v821 ? lisp_true : nil;
    env = stack[-8];
    if (v821 == nil) goto v228;
    v821 = stack[-6];
    v821 = qcar(v821);
    v821 = qcar(v821);
    v374 = qcar(v821);
    v821 = stack[-2];
    fn = elt(env, 10); /* to */
    v374 = (*qfn2(fn))(qenv(fn), v374, v821);
    nil = C_nil;
    if (exception_pending()) goto v621;
    env = stack[-8];
    v821 = stack[-4];
    v821 = cons(v374, v821);
    nil = C_nil;
    if (exception_pending()) goto v621;
    env = stack[-8];
    goto v468;

v468:
    fn = elt(env, 26); /* prepsq!*0 */
    v821 = (*qfn2(fn))(qenv(fn), stack[0], v821);
    nil = C_nil;
    if (exception_pending()) goto v621;
    env = stack[-8];
    stack[0] = v821;
    goto v176;

v176:
    v821 = stack[-6];
    v374 = qcdr(v821);
    v821 = stack[-5];
    v374 = cons(v374, v821);
    nil = C_nil;
    if (exception_pending()) goto v621;
    env = stack[-8];
    v821 = stack[-4];
    fn = elt(env, 26); /* prepsq!*0 */
    v821 = (*qfn2(fn))(qenv(fn), v374, v821);
    nil = C_nil;
    if (exception_pending()) goto v621;
    env = stack[-8];
    {
        Lisp_Object v622 = stack[0];
        popv(9);
        fn = elt(env, 27); /* nconc!* */
        return (*qfn2(fn))(qenv(fn), v622, v821);
    }

v228:
    v374 = stack[-2];
    v821 = (Lisp_Object)1; /* 0 */
    v821 = (Lisp_Object)lessp2(v374, v821);
    nil = C_nil;
    if (exception_pending()) goto v621;
    v821 = v821 ? lisp_true : nil;
    env = stack[-8];
    if (v821 == nil) goto v179;
    v623 = elt(env, 2); /* expt */
    v821 = stack[-6];
    v821 = qcar(v821);
    v821 = qcar(v821);
    v374 = qcar(v821);
    v821 = stack[-2];
    v374 = list3(v623, v374, v821);
    nil = C_nil;
    if (exception_pending()) goto v621;
    env = stack[-8];
    v821 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 12); /* mksp */
    v374 = (*qfn2(fn))(qenv(fn), v374, v821);
    nil = C_nil;
    if (exception_pending()) goto v621;
    env = stack[-8];
    v821 = stack[-4];
    v821 = cons(v374, v821);
    nil = C_nil;
    if (exception_pending()) goto v621;
    env = stack[-8];
    goto v468;

v179:
    v821 = stack[-4];
    goto v468;

v58:
    v821 = stack[-6];
    v821 = qcar(v821);
    v374 = qcdr(v821);
    v821 = stack[-5];
    stack[0] = cons(v374, v821);
    nil = C_nil;
    if (exception_pending()) goto v621;
    env = stack[-8];
    v821 = stack[-6];
    v821 = qcar(v821);
    v374 = qcar(v821);
    v821 = stack[-4];
    v821 = cons(v374, v821);
    nil = C_nil;
    if (exception_pending()) goto v621;
    env = stack[-8];
    fn = elt(env, 26); /* prepsq!*0 */
    v821 = (*qfn2(fn))(qenv(fn), stack[0], v821);
    nil = C_nil;
    if (exception_pending()) goto v621;
    env = stack[-8];
    stack[0] = v821;
    goto v176;
/* error exit handlers */
v621:
    popv(9);
    return nil;
}



/* Code for mkdmoderr */

static Lisp_Object CC_mkdmoderr(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v17;
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
    stack[-3] = v16;
    v17 = v0;
/* end of prologue */
    stack[-4] = elt(env, 1); /* lambda */
    stack[-2] = elt(env, 2); /* (!*x!*) */
    stack[-1] = elt(env, 3); /* dmoderr */
    stack[0] = Lmkquote(nil, v17);
    nil = C_nil;
    if (exception_pending()) goto v23;
    env = stack[-5];
    v17 = stack[-3];
    v17 = Lmkquote(nil, v17);
    nil = C_nil;
    if (exception_pending()) goto v23;
    env = stack[-5];
    v17 = list3(stack[-1], stack[0], v17);
    nil = C_nil;
    if (exception_pending()) goto v23;
    {
        Lisp_Object v30 = stack[-4];
        Lisp_Object v99 = stack[-2];
        popv(6);
        return list3(v30, v99, v17);
    }
/* error exit handlers */
v23:
    popv(6);
    return nil;
}



/* Code for ratfunpri1 */

static Lisp_Object CC_ratfunpri1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v287, v641, v540;
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
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0;
/* end of prologue */
    v641 = qvalue(elt(env, 1)); /* spare!* */
    v287 = (Lisp_Object)33; /* 2 */
    v287 = plus2(v641, v287);
    nil = C_nil;
    if (exception_pending()) goto v413;
    env = stack[-8];
    qvalue(elt(env, 1)) = v287; /* spare!* */
    v287 = stack[0];
    v287 = qcdr(v287);
    v540 = qcar(v287);
    v641 = (Lisp_Object)1; /* 0 */
    v287 = nil;
    fn = elt(env, 14); /* layout!-formula */
    v287 = (*qfnn(fn))(qenv(fn), 3, v540, v641, v287);
    nil = C_nil;
    if (exception_pending()) goto v413;
    env = stack[-8];
    stack[-7] = v287;
    if (v287 == nil) goto v441;
    v287 = stack[0];
    v287 = qcdr(v287);
    v287 = qcdr(v287);
    v540 = qcar(v287);
    v641 = (Lisp_Object)1; /* 0 */
    v287 = nil;
    fn = elt(env, 14); /* layout!-formula */
    v287 = (*qfnn(fn))(qenv(fn), 3, v540, v641, v287);
    nil = C_nil;
    if (exception_pending()) goto v413;
    env = stack[-8];
    stack[-6] = v287;
    if (v287 == nil) goto v441;
    v641 = qvalue(elt(env, 1)); /* spare!* */
    v287 = (Lisp_Object)33; /* 2 */
    v287 = difference2(v641, v287);
    nil = C_nil;
    if (exception_pending()) goto v413;
    env = stack[-8];
    qvalue(elt(env, 1)) = v287; /* spare!* */
    stack[0] = (Lisp_Object)33; /* 2 */
    v287 = stack[-7];
    v287 = qcar(v287);
    v641 = qcdr(v287);
    v287 = stack[-6];
    v287 = qcar(v287);
    v287 = qcdr(v287);
    fn = elt(env, 15); /* max */
    v287 = (*qfn2(fn))(qenv(fn), v641, v287);
    nil = C_nil;
    if (exception_pending()) goto v413;
    env = stack[-8];
    v287 = plus2(stack[0], v287);
    nil = C_nil;
    if (exception_pending()) goto v413;
    env = stack[-8];
    stack[-2] = v287;
    stack[0] = stack[-2];
    v287 = nil;
    v641 = Llinelength(nil, v287);
    nil = C_nil;
    if (exception_pending()) goto v413;
    env = stack[-8];
    v287 = qvalue(elt(env, 1)); /* spare!* */
    v641 = difference2(v641, v287);
    nil = C_nil;
    if (exception_pending()) goto v413;
    env = stack[-8];
    v287 = qvalue(elt(env, 2)); /* posn!* */
    v287 = difference2(v641, v287);
    nil = C_nil;
    if (exception_pending()) goto v413;
    env = stack[-8];
    v287 = (Lisp_Object)greaterp2(stack[0], v287);
    nil = C_nil;
    if (exception_pending()) goto v413;
    v287 = v287 ? lisp_true : nil;
    env = stack[-8];
    if (v287 == nil) goto v113;
    v287 = lisp_true;
    fn = elt(env, 16); /* terpri!* */
    v287 = (*qfn1(fn))(qenv(fn), v287);
    nil = C_nil;
    if (exception_pending()) goto v413;
    env = stack[-8];
    goto v113;

v113:
    v287 = stack[-7];
    v287 = qcar(v287);
    v641 = qcdr(v287);
    v287 = stack[-6];
    v287 = qcar(v287);
    v287 = qcdr(v287);
    v287 = difference2(v641, v287);
    nil = C_nil;
    if (exception_pending()) goto v413;
    env = stack[-8];
    stack[-1] = v287;
    v641 = stack[-1];
    v287 = (Lisp_Object)1; /* 0 */
    v287 = (Lisp_Object)greaterp2(v641, v287);
    nil = C_nil;
    if (exception_pending()) goto v413;
    v287 = v287 ? lisp_true : nil;
    env = stack[-8];
    if (v287 == nil) goto v214;
    v287 = (Lisp_Object)1; /* 0 */
    stack[0] = v287;
    v641 = stack[-1];
    v287 = (Lisp_Object)33; /* 2 */
    v287 = quot2(v641, v287);
    nil = C_nil;
    if (exception_pending()) goto v413;
    env = stack[-8];
    stack[-3] = v287;
    goto v73;

v73:
    v287 = stack[-7];
    v287 = qcdr(v287);
    v641 = qcdr(v287);
    v287 = stack[-7];
    v287 = qcdr(v287);
    v287 = qcar(v287);
    v287 = difference2(v641, v287);
    nil = C_nil;
    if (exception_pending()) goto v413;
    env = stack[-8];
    v287 = add1(v287);
    nil = C_nil;
    if (exception_pending()) goto v413;
    env = stack[-8];
    stack[-5] = v287;
    v287 = stack[-6];
    v287 = qcdr(v287);
    v641 = qcdr(v287);
    v287 = stack[-6];
    v287 = qcdr(v287);
    v287 = qcar(v287);
    v287 = difference2(v641, v287);
    nil = C_nil;
    if (exception_pending()) goto v413;
    env = stack[-8];
    v287 = add1(v287);
    nil = C_nil;
    if (exception_pending()) goto v413;
    env = stack[-8];
    stack[-4] = v287;
    stack[-1] = stack[0];
    stack[0] = qvalue(elt(env, 2)); /* posn!* */
    v641 = (Lisp_Object)17; /* 1 */
    v287 = qvalue(elt(env, 3)); /* orig!* */
    v287 = difference2(v641, v287);
    nil = C_nil;
    if (exception_pending()) goto v413;
    env = stack[-8];
    v287 = plus2(stack[0], v287);
    nil = C_nil;
    if (exception_pending()) goto v413;
    env = stack[-8];
    stack[0] = plus2(stack[-1], v287);
    nil = C_nil;
    if (exception_pending()) goto v413;
    env = stack[-8];
    v641 = (Lisp_Object)17; /* 1 */
    v287 = stack[-7];
    v287 = qcdr(v287);
    v287 = qcar(v287);
    v641 = difference2(v641, v287);
    nil = C_nil;
    if (exception_pending()) goto v413;
    env = stack[-8];
    v287 = qvalue(elt(env, 4)); /* ycoord!* */
    v641 = plus2(v641, v287);
    nil = C_nil;
    if (exception_pending()) goto v413;
    env = stack[-8];
    v287 = stack[-7];
    v287 = qcar(v287);
    v287 = qcar(v287);
    fn = elt(env, 17); /* update!-pline */
    stack[-1] = (*qfnn(fn))(qenv(fn), 3, stack[0], v641, v287);
    nil = C_nil;
    if (exception_pending()) goto v413;
    env = stack[-8];
    stack[0] = qvalue(elt(env, 2)); /* posn!* */
    v641 = (Lisp_Object)17; /* 1 */
    v287 = qvalue(elt(env, 3)); /* orig!* */
    v287 = difference2(v641, v287);
    nil = C_nil;
    if (exception_pending()) goto v413;
    env = stack[-8];
    v287 = plus2(stack[0], v287);
    nil = C_nil;
    if (exception_pending()) goto v413;
    env = stack[-8];
    stack[0] = plus2(stack[-3], v287);
    nil = C_nil;
    if (exception_pending()) goto v413;
    env = stack[-8];
    v641 = qvalue(elt(env, 4)); /* ycoord!* */
    v287 = stack[-6];
    v287 = qcdr(v287);
    v287 = qcdr(v287);
    v287 = difference2(v641, v287);
    nil = C_nil;
    if (exception_pending()) goto v413;
    env = stack[-8];
    v641 = sub1(v287);
    nil = C_nil;
    if (exception_pending()) goto v413;
    env = stack[-8];
    v287 = stack[-6];
    v287 = qcar(v287);
    v287 = qcar(v287);
    fn = elt(env, 17); /* update!-pline */
    v641 = (*qfnn(fn))(qenv(fn), 3, stack[0], v641, v287);
    nil = C_nil;
    if (exception_pending()) goto v413;
    env = stack[-8];
    v287 = qvalue(elt(env, 5)); /* pline!* */
    v287 = Lappend(nil, v641, v287);
    nil = C_nil;
    if (exception_pending()) goto v413;
    env = stack[-8];
    v287 = Lappend(nil, stack[-1], v287);
    nil = C_nil;
    if (exception_pending()) goto v413;
    env = stack[-8];
    qvalue(elt(env, 5)) = v287; /* pline!* */
    stack[0] = qvalue(elt(env, 6)); /* ymin!* */
    v641 = qvalue(elt(env, 4)); /* ycoord!* */
    v287 = stack[-4];
    v287 = difference2(v641, v287);
    nil = C_nil;
    if (exception_pending()) goto v413;
    env = stack[-8];
    fn = elt(env, 18); /* min */
    v287 = (*qfn2(fn))(qenv(fn), stack[0], v287);
    nil = C_nil;
    if (exception_pending()) goto v413;
    env = stack[-8];
    qvalue(elt(env, 6)) = v287; /* ymin!* */
    stack[0] = qvalue(elt(env, 7)); /* ymax!* */
    v641 = qvalue(elt(env, 4)); /* ycoord!* */
    v287 = stack[-5];
    v287 = plus2(v641, v287);
    nil = C_nil;
    if (exception_pending()) goto v413;
    env = stack[-8];
    fn = elt(env, 15); /* max */
    v287 = (*qfn2(fn))(qenv(fn), stack[0], v287);
    nil = C_nil;
    if (exception_pending()) goto v413;
    env = stack[-8];
    qvalue(elt(env, 7)) = v287; /* ymax!* */
    v287 = elt(env, 8); /* bar */
    fn = elt(env, 19); /* symbol */
    v287 = (*qfn1(fn))(qenv(fn), v287);
    nil = C_nil;
    if (exception_pending()) goto v413;
    env = stack[-8];
    stack[-1] = v287;
    v287 = (Lisp_Object)17; /* 1 */
    stack[0] = v287;
    goto v157;

v157:
    v641 = stack[-2];
    v287 = stack[0];
    v287 = difference2(v641, v287);
    nil = C_nil;
    if (exception_pending()) goto v413;
    env = stack[-8];
    v287 = Lminusp(nil, v287);
    env = stack[-8];
    if (!(v287 == nil)) goto v21;
    v287 = stack[-1];
    fn = elt(env, 20); /* prin2!* */
    v287 = (*qfn1(fn))(qenv(fn), v287);
    nil = C_nil;
    if (exception_pending()) goto v413;
    env = stack[-8];
    v287 = stack[0];
    v287 = add1(v287);
    nil = C_nil;
    if (exception_pending()) goto v413;
    env = stack[-8];
    stack[0] = v287;
    goto v157;

v21:
    v287 = nil;
    { popv(9); return onevalue(v287); }

v214:
    v287 = stack[-1];
    v641 = negate(v287);
    nil = C_nil;
    if (exception_pending()) goto v413;
    env = stack[-8];
    v287 = (Lisp_Object)33; /* 2 */
    v287 = quot2(v641, v287);
    nil = C_nil;
    if (exception_pending()) goto v413;
    env = stack[-8];
    stack[0] = v287;
    v287 = (Lisp_Object)1; /* 0 */
    stack[-3] = v287;
    goto v73;

v441:
    v641 = qvalue(elt(env, 1)); /* spare!* */
    v287 = (Lisp_Object)33; /* 2 */
    v287 = difference2(v641, v287);
    nil = C_nil;
    if (exception_pending()) goto v413;
    env = stack[-8];
    qvalue(elt(env, 1)) = v287; /* spare!* */
    v287 = stack[0];
    v287 = qcdr(v287);
    stack[0] = v287;
    v641 = elt(env, 9); /* quotient */
    v287 = elt(env, 10); /* infix */
    v287 = get(v641, v287);
    env = stack[-8];
    stack[-2] = v287;
    v287 = qvalue(elt(env, 11)); /* p!*!* */
    if (v287 == nil) goto v335;
    v641 = qvalue(elt(env, 11)); /* p!*!* */
    v287 = stack[-2];
    v287 = (Lisp_Object)greaterp2(v641, v287);
    nil = C_nil;
    if (exception_pending()) goto v413;
    v287 = v287 ? lisp_true : nil;
    env = stack[-8];
    stack[-1] = v287;
    goto v196;

v196:
    v287 = stack[-1];
    if (v287 == nil) goto v289;
    v287 = elt(env, 12); /* "(" */
    fn = elt(env, 20); /* prin2!* */
    v287 = (*qfn1(fn))(qenv(fn), v287);
    nil = C_nil;
    if (exception_pending()) goto v413;
    env = stack[-8];
    goto v289;

v289:
    v287 = stack[0];
    v641 = qcar(v287);
    v287 = stack[-2];
    fn = elt(env, 21); /* maprint */
    v287 = (*qfn2(fn))(qenv(fn), v641, v287);
    nil = C_nil;
    if (exception_pending()) goto v413;
    env = stack[-8];
    v287 = elt(env, 9); /* quotient */
    fn = elt(env, 22); /* oprin */
    v287 = (*qfn1(fn))(qenv(fn), v287);
    nil = C_nil;
    if (exception_pending()) goto v413;
    env = stack[-8];
    v287 = stack[0];
    v287 = qcdr(v287);
    v287 = qcar(v287);
    fn = elt(env, 23); /* negnumberchk */
    v641 = (*qfn1(fn))(qenv(fn), v287);
    nil = C_nil;
    if (exception_pending()) goto v413;
    env = stack[-8];
    v287 = stack[-2];
    fn = elt(env, 21); /* maprint */
    v287 = (*qfn2(fn))(qenv(fn), v641, v287);
    nil = C_nil;
    if (exception_pending()) goto v413;
    env = stack[-8];
    v287 = stack[-1];
    if (v287 == nil) goto v21;
    v287 = elt(env, 13); /* ")" */
    fn = elt(env, 20); /* prin2!* */
    v287 = (*qfn1(fn))(qenv(fn), v287);
    nil = C_nil;
    if (exception_pending()) goto v413;
    goto v21;

v335:
    v287 = nil;
    stack[-1] = v287;
    goto v196;
/* error exit handlers */
v413:
    popv(9);
    return nil;
}



/* Code for quotpri */

static Lisp_Object CC_quotpri(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v37, v36, v48;
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
    v36 = v0;
/* end of prologue */
    stack[0] = nil;
    v37 = qvalue(elt(env, 1)); /* !*ratpri */
    if (v37 == nil) goto v45;
    v37 = qvalue(elt(env, 2)); /* !*nat */
    if (v37 == nil) goto v45;
    v37 = qvalue(elt(env, 3)); /* !*fort */
    if (!(v37 == nil)) goto v45;
    v37 = qvalue(elt(env, 4)); /* !*list */
    if (!(v37 == nil)) goto v45;
    v37 = qvalue(elt(env, 5)); /* !*mcd */
    if (v37 == nil) goto v45;
    v48 = qvalue(elt(env, 7)); /* dmode!* */
    v37 = elt(env, 8); /* ratmode */
    v37 = Lflagp(nil, v48, v37);
    env = stack[-1];
    if (v37 == nil) goto v12;
    v37 = qvalue(elt(env, 7)); /* dmode!* */
    stack[0] = v37;
    v37 = nil;
    qvalue(elt(env, 7)) = v37; /* dmode!* */
    goto v12;

v12:
    v37 = v36;
    fn = elt(env, 9); /* ratfunpri1 */
    v37 = (*qfn1(fn))(qenv(fn), v37);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[-1];
    v36 = v37;
    v37 = stack[0];
    if (v37 == nil) { popv(2); return onevalue(v36); }
    v37 = stack[0];
    qvalue(elt(env, 7)) = v37; /* dmode!* */
    { popv(2); return onevalue(v36); }

v45:
    v37 = elt(env, 6); /* failed */
    { popv(2); return onevalue(v37); }
/* error exit handlers */
v51:
    popv(2);
    return nil;
}



/* Code for kernord!-sort */

static Lisp_Object CC_kernordKsort(Lisp_Object env,
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
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0;
/* end of prologue */
    stack[0] = nil;
    goto v5;

v5:
    v33 = stack[-1];
    if (v33 == nil) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v33 = stack[-1];
    v51 = qcdr(v33);
    v33 = stack[-1];
    v33 = qcar(v33);
    fn = elt(env, 1); /* maxdeg */
    v33 = (*qfn2(fn))(qenv(fn), v51, v33);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-3];
    stack[-2] = v33;
    v33 = stack[-2];
    v51 = qcar(v33);
    v33 = stack[-1];
    fn = elt(env, 2); /* delallasc */
    v33 = (*qfn2(fn))(qenv(fn), v51, v33);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-3];
    stack[-1] = v33;
    v33 = stack[-2];
    v51 = qcar(v33);
    v33 = stack[0];
    v33 = cons(v51, v33);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-3];
    stack[0] = v33;
    goto v5;
/* error exit handlers */
v52:
    popv(4);
    return nil;
}



/* Code for put!-kvalue */

static Lisp_Object MS_CDECL CC_putKkvalue(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v16,
                         Lisp_Object v63, Lisp_Object v9, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v71, v101;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "put-kvalue");
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
/* copy arguments values to proper place */
    stack[-1] = v9;
    stack[-2] = v63;
    stack[-3] = v16;
    stack[0] = v0;
/* end of prologue */
    v101 = stack[-1];
    v71 = elt(env, 1); /* !*sq */
    if (!consp(v101)) goto v99;
    v101 = qcar(v101);
    if (!(v101 == v71)) goto v99;
    v101 = stack[-2];
    v71 = stack[-1];
    v71 = qcdr(v71);
    v71 = qcar(v71);
    fn = elt(env, 3); /* sq_member */
    v71 = (*qfn2(fn))(qenv(fn), v101, v71);
    nil = C_nil;
    if (exception_pending()) goto v65;
    env = stack[-5];
    goto v7;

v7:
    if (v71 == nil) goto v42;
    v71 = stack[-2];
    {
        popv(6);
        fn = elt(env, 4); /* recursiveerror */
        return (*qfn1(fn))(qenv(fn), v71);
    }

v42:
    stack[-4] = stack[0];
    stack[0] = elt(env, 2); /* kvalue */
    v101 = stack[-2];
    v71 = stack[-1];
    v71 = list2(v101, v71);
    nil = C_nil;
    if (exception_pending()) goto v65;
    env = stack[-5];
    fn = elt(env, 5); /* aconc */
    v71 = (*qfn2(fn))(qenv(fn), stack[-3], v71);
    nil = C_nil;
    if (exception_pending()) goto v65;
    {
        Lisp_Object v103 = stack[-4];
        Lisp_Object v59 = stack[0];
        popv(6);
        return Lputprop(nil, 3, v103, v59, v71);
    }

v99:
    v101 = stack[-2];
    v71 = stack[-1];
    fn = elt(env, 6); /* smember */
    v71 = (*qfn2(fn))(qenv(fn), v101, v71);
    nil = C_nil;
    if (exception_pending()) goto v65;
    env = stack[-5];
    goto v7;
/* error exit handlers */
v65:
    popv(6);
    return nil;
}



/* Code for revlis_without_mode */

static Lisp_Object CC_revlis_without_mode(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v50, v52;
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
    v50 = v0;
/* end of prologue */
    stack[-4] = v50;
    v50 = stack[-4];
    if (v50 == nil) goto v8;
    v50 = stack[-4];
    v50 = qcar(v50);
    v52 = v50;
    v50 = nil;
    stack[0] = qvalue(elt(env, 1)); /* dmode!* */
    qvalue(elt(env, 1)) = v50; /* dmode!* */
    v50 = v52;
    fn = elt(env, 2); /* reval */
    v50 = (*qfn1(fn))(qenv(fn), v50);
    nil = C_nil;
    if (exception_pending()) goto v206;
    env = stack[-5];
    qvalue(elt(env, 1)) = stack[0]; /* dmode!* */
    v50 = ncons(v50);
    nil = C_nil;
    if (exception_pending()) goto v41;
    env = stack[-5];
    stack[-2] = v50;
    stack[-3] = v50;
    goto v45;

v45:
    v50 = stack[-4];
    v50 = qcdr(v50);
    stack[-4] = v50;
    v50 = stack[-4];
    if (v50 == nil) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    stack[-1] = stack[-2];
    v50 = stack[-4];
    v50 = qcar(v50);
    v52 = v50;
    v50 = nil;
    stack[0] = qvalue(elt(env, 1)); /* dmode!* */
    qvalue(elt(env, 1)) = v50; /* dmode!* */
    v50 = v52;
    fn = elt(env, 2); /* reval */
    v50 = (*qfn1(fn))(qenv(fn), v50);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-5];
    qvalue(elt(env, 1)) = stack[0]; /* dmode!* */
    v50 = ncons(v50);
    nil = C_nil;
    if (exception_pending()) goto v41;
    env = stack[-5];
    v50 = Lrplacd(nil, stack[-1], v50);
    nil = C_nil;
    if (exception_pending()) goto v41;
    env = stack[-5];
    v50 = stack[-2];
    v50 = qcdr(v50);
    stack[-2] = v50;
    goto v45;

v8:
    v50 = nil;
    { popv(6); return onevalue(v50); }
/* error exit handlers */
v64:
    env = stack[-5];
    qvalue(elt(env, 1)) = stack[0]; /* dmode!* */
    popv(6);
    return nil;
v41:
    popv(6);
    return nil;
v206:
    env = stack[-5];
    qvalue(elt(env, 1)) = stack[0]; /* dmode!* */
    popv(6);
    return nil;
}



/* Code for subs2!* */

static Lisp_Object CC_subs2H(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v12, v45;
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
    v45 = v0;
/* end of prologue */
    v12 = qvalue(elt(env, 1)); /* !*sub2 */
    stack[0] = qvalue(elt(env, 1)); /* !*sub2 */
    qvalue(elt(env, 1)) = v12; /* !*sub2 */
    v12 = v45;
    fn = elt(env, 2); /* subs2 */
    v12 = (*qfn1(fn))(qenv(fn), v12);
    nil = C_nil;
    if (exception_pending()) goto v6;
    env = stack[-1];
    qvalue(elt(env, 1)) = stack[0]; /* !*sub2 */
    { popv(2); return onevalue(v12); }
/* error exit handlers */
v6:
    env = stack[-1];
    qvalue(elt(env, 1)) = stack[0]; /* !*sub2 */
    popv(2);
    return nil;
}



/* Code for command */

static Lisp_Object MS_CDECL CC_command(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v522, v300, v429, v430;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "command");
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
    stack[-2] = qvalue(elt(env, 1)); /* errmsg!* */
    qvalue(elt(env, 1)) = nil; /* errmsg!* */
    stack[-1] = qvalue(elt(env, 2)); /* loopdelimslist!* */
    qvalue(elt(env, 2)) = nil; /* loopdelimslist!* */
    v522 = qvalue(elt(env, 3)); /* !*demo */
    if (v522 == nil) goto v25;
    v522 = qvalue(elt(env, 4)); /* ifl!* */
    if (v522 == nil) goto v25;
    fn = elt(env, 28); /* commdemo */
    v522 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v169;
    env = stack[-3];
    goto v45;

v45:
    qvalue(elt(env, 2)) = stack[-1]; /* loopdelimslist!* */
    qvalue(elt(env, 1)) = stack[-2]; /* errmsg!* */
    { popv(4); return onevalue(v522); }

v25:
    v522 = qvalue(elt(env, 5)); /* !*slin */
    if (v522 == nil) goto v5;
    v522 = qvalue(elt(env, 6)); /* !*reduce4 */
    if (!(v522 == nil)) goto v5;
    fn = elt(env, 29); /* setcloc!* */
    v522 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v169;
    env = stack[-3];
    v522 = qvalue(elt(env, 7)); /* lreadfn!* */
    if (v522 == nil) goto v32;
    v300 = qvalue(elt(env, 7)); /* lreadfn!* */
    v522 = nil;
    fn = elt(env, 30); /* lispapply */
    v522 = (*qfn2(fn))(qenv(fn), v300, v522);
    nil = C_nil;
    if (exception_pending()) goto v169;
    env = stack[-3];
    goto v19;

v19:
    stack[0] = v522;
    goto v6;

v6:
    v522 = qvalue(elt(env, 6)); /* !*reduce4 */
    if (v522 == nil) goto v150;
    v522 = qvalue(elt(env, 24)); /* !*debug */
    if (v522 == nil) goto v347;
    v522 = elt(env, 25); /* "Parse: " */
    v522 = Lprinc(nil, v522);
    nil = C_nil;
    if (exception_pending()) goto v169;
    env = stack[-3];
    v522 = stack[0];
    fn = elt(env, 31); /* prettyprint */
    v522 = (*qfn1(fn))(qenv(fn), v522);
    nil = C_nil;
    if (exception_pending()) goto v169;
    env = stack[-3];
    goto v347;

v347:
    v300 = qvalue(elt(env, 16)); /* key!* */
    v522 = elt(env, 26); /* !*semicol!* */
    if (v300 == v522) goto v5;
    v522 = qvalue(elt(env, 6)); /* !*reduce4 */
    if (v522 == nil) goto v252;
    v522 = stack[0];
    fn = elt(env, 32); /* n_form */
    v522 = (*qfn1(fn))(qenv(fn), v522);
    nil = C_nil;
    if (exception_pending()) goto v169;
    env = stack[-3];
    stack[0] = v522;
    goto v459;

v459:
    v522 = qvalue(elt(env, 24)); /* !*debug */
    if (v522 == nil) goto v490;
    v522 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v169;
    env = stack[-3];
    v522 = elt(env, 27); /* "Form: " */
    v522 = Lprinc(nil, v522);
    nil = C_nil;
    if (exception_pending()) goto v169;
    env = stack[-3];
    v522 = stack[0];
    fn = elt(env, 31); /* prettyprint */
    v522 = (*qfn1(fn))(qenv(fn), v522);
    nil = C_nil;
    if (exception_pending()) goto v169;
    env = stack[-3];
    goto v490;

v490:
    v522 = stack[0];
    goto v45;

v252:
    v522 = stack[0];
    fn = elt(env, 33); /* form */
    v522 = (*qfn1(fn))(qenv(fn), v522);
    nil = C_nil;
    if (exception_pending()) goto v169;
    env = stack[-3];
    stack[0] = v522;
    goto v459;

v5:
    fn = elt(env, 34); /* readch1 */
    v522 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v169;
    env = stack[-3];
    qvalue(elt(env, 8)) = v522; /* crchar!* */
    v300 = qvalue(elt(env, 8)); /* crchar!* */
    v522 = qvalue(elt(env, 9)); /* !$eol!$ */
    if (equal(v300, v522)) goto v5;
    fn = elt(env, 35); /* command1 */
    v522 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v169;
    env = stack[-3];
    stack[0] = v522;
    goto v6;

v150:
    v522 = qvalue(elt(env, 10)); /* !*struct */
    if (v522 == nil) goto v64;
    v522 = stack[0];
    fn = elt(env, 36); /* structchk */
    v522 = (*qfn1(fn))(qenv(fn), v522);
    nil = C_nil;
    if (exception_pending()) goto v169;
    env = stack[-3];
    stack[0] = v522;
    goto v64;

v64:
    v522 = qvalue(elt(env, 11)); /* !*pret */
    if (v522 == nil) goto v87;
    v522 = stack[0];
    if (!consp(v522)) goto v66;
    v522 = stack[0];
    v300 = qcar(v522);
    v522 = elt(env, 12); /* (in out shut) */
    v522 = Lmemq(nil, v300, v522);
    if (!(v522 == nil)) goto v87;

v66:
    v522 = stack[0];
    if (!(v522 == nil)) goto v236;
    v300 = qvalue(elt(env, 13)); /* cursym!* */
    v522 = elt(env, 14); /* end */
    if (!(v300 == v522)) goto v236;
    v522 = elt(env, 14); /* end */
    fn = elt(env, 37); /* rprint */
    v522 = (*qfn1(fn))(qenv(fn), v522);
    nil = C_nil;
    if (exception_pending()) goto v169;
    env = stack[-3];
    goto v87;

v87:
    v522 = qvalue(elt(env, 5)); /* !*slin */
    if (v522 == nil) goto v143;
    v300 = elt(env, 15); /* symbolic */
    v522 = stack[0];
    v522 = list2(v300, v522);
    nil = C_nil;
    if (exception_pending()) goto v169;
    env = stack[-3];
    goto v45;

v143:
    v522 = stack[0];
    fn = elt(env, 33); /* form */
    v522 = (*qfn1(fn))(qenv(fn), v522);
    nil = C_nil;
    if (exception_pending()) goto v169;
    env = stack[-3];
    v300 = v522;
    v429 = qvalue(elt(env, 16)); /* key!* */
    v522 = elt(env, 17); /* modefn */
    v522 = Lflagp(nil, v429, v522);
    env = stack[-3];
    if (v522 == nil) goto v136;
    v522 = qvalue(elt(env, 16)); /* key!* */
    goto v256;

v256:
    stack[0] = v522;
    v430 = v300;
    v429 = nil;
    v300 = elt(env, 15); /* symbolic */
    fn = elt(env, 38); /* convertmode1 */
    v522 = (*qfnn(fn))(qenv(fn), 4, v430, v429, v300, v522);
    nil = C_nil;
    if (exception_pending()) goto v169;
    env = stack[-3];
    v522 = list2(stack[0], v522);
    nil = C_nil;
    if (exception_pending()) goto v169;
    env = stack[-3];
    goto v45;

v136:
    v522 = v300;
    if (!consp(v522)) goto v509;
    v522 = v300;
    v429 = qcar(v522);
    v522 = elt(env, 18); /* quote */
    if (v429 == v522) goto v509;
    v522 = v300;
    v522 = qcar(v522);
    if (!(symbolp(v522))) goto v327;
    v522 = v300;
    v429 = qcar(v522);
    v522 = elt(env, 19); /* nochange */
    v522 = Lflagp(nil, v429, v522);
    env = stack[-3];
    if (!(v522 == nil)) goto v211;
    v522 = v300;
    v429 = qcar(v522);
    v522 = elt(env, 20); /* intfn */
    v522 = Lflagp(nil, v429, v522);
    env = stack[-3];
    if (!(v522 == nil)) goto v211;
    v522 = v300;
    v429 = qcar(v522);
    v522 = elt(env, 21); /* list */
    if (!(v429 == v522)) goto v327;

v211:
    v522 = v300;
    v429 = qcar(v522);
    v522 = elt(env, 22); /* (setq setel setf) */
    v522 = Lmemq(nil, v429, v522);
    if (v522 == nil) goto v509;
    v522 = v300;
    v522 = qcdr(v522);
    v522 = qcdr(v522);
    v429 = qcar(v522);
    v522 = elt(env, 18); /* quote */
    if (!consp(v429)) goto v509;
    v429 = qcar(v429);
    if (!(v429 == v522)) goto v509;

v327:
    v522 = elt(env, 15); /* symbolic */
    goto v256;

v509:
    v522 = qvalue(elt(env, 23)); /* !*mode */
    goto v256;

v236:
    v522 = stack[0];
    fn = elt(env, 37); /* rprint */
    v522 = (*qfn1(fn))(qenv(fn), v522);
    nil = C_nil;
    if (exception_pending()) goto v169;
    env = stack[-3];
    v522 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v169;
    env = stack[-3];
    goto v87;

v32:
    v522 = Lread(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v169;
    env = stack[-3];
    goto v19;
/* error exit handlers */
v169:
    env = stack[-3];
    qvalue(elt(env, 2)) = stack[-1]; /* loopdelimslist!* */
    qvalue(elt(env, 1)) = stack[-2]; /* errmsg!* */
    popv(4);
    return nil;
}



/* Code for subs2chk */

static Lisp_Object CC_subs2chk(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v43, v29, v17;
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
    stack[0] = v0;
/* end of prologue */
    v43 = qvalue(elt(env, 1)); /* subfg!* */
    if (v43 == nil) { Lisp_Object res = stack[0]; popv(1); return onevalue(res); }
    v43 = stack[0];
    fn = elt(env, 2); /* subs2f */
    v43 = (*qfn1(fn))(qenv(fn), v43);
    nil = C_nil;
    if (exception_pending()) goto v19;
    v17 = v43;
    v29 = qcdr(v43);
    v43 = (Lisp_Object)17; /* 1 */
    if (!(v29 == v43)) { Lisp_Object res = stack[0]; popv(1); return onevalue(res); }
    v43 = v17;
    v43 = qcar(v43);
    stack[0] = v43;
    { Lisp_Object res = stack[0]; popv(1); return onevalue(res); }
/* error exit handlers */
v19:
    popv(1);
    return nil;
}



/* Code for dsimptimes */

static Lisp_Object CC_dsimptimes(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v237, v121;
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
    stack[0] = v16;
    stack[-1] = v0;
/* end of prologue */
    v237 = stack[-1];
    if (v237 == nil) goto v4;
    v237 = stack[-1];
    v237 = qcdr(v237);
    if (v237 == nil) goto v13;
    v237 = stack[-1];
    v121 = qcar(v237);
    v237 = stack[0];
    fn = elt(env, 1); /* dsimp */
    v237 = (*qfn2(fn))(qenv(fn), v121, v237);
    nil = C_nil;
    if (exception_pending()) goto v81;
    env = stack[-5];
    stack[-4] = v237;
    v237 = stack[-1];
    v121 = qcdr(v237);
    v237 = stack[0];
    v237 = CC_dsimptimes(env, v121, v237);
    nil = C_nil;
    if (exception_pending()) goto v81;
    env = stack[-5];
    stack[-3] = v237;
    goto v32;

v32:
    v237 = stack[-3];
    if (v237 == nil) goto v39;
    v237 = stack[-3];
    v237 = qcar(v237);
    v121 = stack[-4];
    fn = elt(env, 2); /* mappend */
    v237 = (*qfn2(fn))(qenv(fn), v121, v237);
    nil = C_nil;
    if (exception_pending()) goto v81;
    env = stack[-5];
    stack[-2] = v237;
    v237 = stack[-2];
    fn = elt(env, 3); /* lastpair */
    v237 = (*qfn1(fn))(qenv(fn), v237);
    nil = C_nil;
    if (exception_pending()) goto v81;
    env = stack[-5];
    stack[-1] = v237;
    v237 = stack[-3];
    v237 = qcdr(v237);
    stack[-3] = v237;
    v237 = stack[-1];
    if (!consp(v237)) goto v32;
    else goto v37;

v37:
    v237 = stack[-3];
    if (v237 == nil) { Lisp_Object res = stack[-2]; popv(6); return onevalue(res); }
    stack[0] = stack[-1];
    v237 = stack[-3];
    v237 = qcar(v237);
    v121 = stack[-4];
    fn = elt(env, 2); /* mappend */
    v237 = (*qfn2(fn))(qenv(fn), v121, v237);
    nil = C_nil;
    if (exception_pending()) goto v81;
    env = stack[-5];
    v237 = Lrplacd(nil, stack[0], v237);
    nil = C_nil;
    if (exception_pending()) goto v81;
    env = stack[-5];
    v237 = stack[-1];
    fn = elt(env, 3); /* lastpair */
    v237 = (*qfn1(fn))(qenv(fn), v237);
    nil = C_nil;
    if (exception_pending()) goto v81;
    env = stack[-5];
    stack[-1] = v237;
    v237 = stack[-3];
    v237 = qcdr(v237);
    stack[-3] = v237;
    goto v37;

v39:
    v237 = nil;
    { popv(6); return onevalue(v237); }

v13:
    v237 = stack[-1];
    v121 = qcar(v237);
    v237 = stack[0];
    {
        popv(6);
        fn = elt(env, 1); /* dsimp */
        return (*qfn2(fn))(qenv(fn), v121, v237);
    }

v4:
    v237 = elt(env, 0); /* dsimptimes */
    {
        popv(6);
        fn = elt(env, 4); /* errach */
        return (*qfn1(fn))(qenv(fn), v237);
    }
/* error exit handlers */
v81:
    popv(6);
    return nil;
}



/* Code for remove!-free!-vars!* */

static Lisp_Object CC_removeKfreeKvarsH(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v12, v45;
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
    v45 = v0;
/* end of prologue */
    v12 = lisp_true;
    stack[0] = qvalue(elt(env, 1)); /* !*!*noremove!*!* */
    qvalue(elt(env, 1)) = v12; /* !*!*noremove!*!* */
    v12 = v45;
    fn = elt(env, 2); /* remove!-free!-vars */
    v12 = (*qfn1(fn))(qenv(fn), v12);
    nil = C_nil;
    if (exception_pending()) goto v6;
    env = stack[-1];
    qvalue(elt(env, 1)) = stack[0]; /* !*!*noremove!*!* */
    { popv(2); return onevalue(v12); }
/* error exit handlers */
v6:
    env = stack[-1];
    qvalue(elt(env, 1)) = stack[0]; /* !*!*noremove!*!* */
    popv(2);
    return nil;
}



/* Code for innprodp2 */

static Lisp_Object CC_innprodp2(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v51, v42, v49, v50;
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
    v49 = v16;
    stack[0] = v0;
/* end of prologue */
    v51 = nil;
    v42 = v49;
    v51 = cons(v51, v42);
    nil = C_nil;
    if (exception_pending()) goto v193;
    env = stack[-1];
    v49 = v51;
    goto v13;

v13:
    v51 = stack[0];
    if (v51 == nil) { popv(2); return onevalue(v49); }
    v51 = v49;
    if (v51 == nil) { popv(2); return onevalue(v49); }
    v50 = nil;
    v51 = stack[0];
    v42 = qcar(v51);
    v51 = v49;
    v51 = qcdr(v51);
    v49 = qcar(v49);
    fn = elt(env, 1); /* innprodkp */
    v51 = (*qfnn(fn))(qenv(fn), 4, v50, v42, v51, v49);
    nil = C_nil;
    if (exception_pending()) goto v193;
    env = stack[-1];
    v49 = v51;
    v51 = stack[0];
    v51 = qcdr(v51);
    stack[0] = v51;
    goto v13;
/* error exit handlers */
v193:
    popv(2);
    return nil;
}



/* Code for add1lis */

static Lisp_Object CC_add1lis(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v18, v19;
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
    v18 = stack[0];
    if (v18 == nil) goto v5;
    v18 = stack[0];
    v18 = qcar(v18);
    v19 = add1(v18);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-2];
    v18 = stack[-1];
    v18 = cons(v19, v18);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-2];
    stack[-1] = v18;
    v18 = stack[0];
    v18 = qcdr(v18);
    stack[0] = v18;
    goto v4;

v5:
    v18 = stack[-1];
    {
        popv(3);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v18);
    }
/* error exit handlers */
v22:
    popv(3);
    return nil;
}



/* Code for wuconstantp */

static Lisp_Object CC_wuconstantp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v29, v17;
    CSL_IGNORE(nil);
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v17 = v0;
/* end of prologue */
    v29 = v17;
    v29 = (consp(v29) ? nil : lisp_true);
    if (!(v29 == nil)) goto v12;
    v29 = v17;
    v29 = qcar(v29);
    v29 = (consp(v29) ? nil : lisp_true);
    goto v12;

v12:
    if (!(v29 == nil)) return onevalue(v29);
    v29 = v17;
    v29 = qcar(v29);
    v29 = qcar(v29);
    v29 = qcar(v29);
    v17 = qvalue(elt(env, 1)); /* wuvarlist!* */
    v29 = Lmemq(nil, v29, v17);
    v29 = (v29 == nil ? lisp_true : nil);
    return onevalue(v29);
}



/* Code for mkcopy */

static Lisp_Object CC_mkcopy(Lisp_Object env,
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
    v99 = CC_mkcopy(env, v30);
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



/* Code for nth */

static Lisp_Object CC_nth(Lisp_Object env,
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
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v1 = v16;
    v2 = v0;
/* end of prologue */
    fn = elt(env, 1); /* pnth */
    v1 = (*qfn2(fn))(qenv(fn), v2, v1);
    errexit();
    v1 = qcar(v1);
    return onevalue(v1);
}



/* Code for delall */

static Lisp_Object CC_delall(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v33, v51;
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
    v33 = stack[0];
    if (v33 == nil) goto v5;
    v51 = stack[-1];
    v33 = stack[0];
    v33 = qcar(v33);
    if (equal(v51, v33)) goto v1;
    v33 = stack[0];
    v33 = qcar(v33);
    stack[-2] = ncons(v33);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-3];
    v51 = stack[-1];
    v33 = stack[0];
    v33 = qcdr(v33);
    v33 = CC_delall(env, v51, v33);
    nil = C_nil;
    if (exception_pending()) goto v52;
    {
        Lisp_Object v193 = stack[-2];
        popv(4);
        return Lappend(nil, v193, v33);
    }

v1:
    v33 = stack[0];
    v33 = qcdr(v33);
    stack[0] = v33;
    goto v4;

v5:
    v33 = nil;
    { popv(4); return onevalue(v33); }
/* error exit handlers */
v52:
    popv(4);
    return nil;
}



/* Code for ps!:getv */

static Lisp_Object CC_psTgetv(Lisp_Object env,
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
    v68 = v0;
/* end of prologue */
    v67 = v68;
    v69 = elt(env, 1); /* !:ps!: */
    if (!consp(v67)) goto v51;
    v67 = qcar(v67);
    if (!(v67 == v69)) goto v51;
    v69 = v68;
    v69 = qcdr(v69);
    if (symbolp(v69)) goto v44;
    v69 = v68;
    v67 = qcdr(v69);
    v69 = stack[0];
    v69 = *(Lisp_Object *)((char *)v67 + (CELL-TAG_VECTOR) + ((int32_t)v69/(16/CELL)));
    { popv(3); return onevalue(v69); }

v44:
    v69 = v68;
    v69 = qcdr(v69);
    fn = elt(env, 4); /* eval */
    v67 = (*qfn1(fn))(qenv(fn), v69);
    nil = C_nil;
    if (exception_pending()) goto v87;
    v69 = stack[0];
    v69 = *(Lisp_Object *)((char *)v67 + (CELL-TAG_VECTOR) + ((int32_t)v69/(16/CELL)));
    { popv(3); return onevalue(v69); }

v51:
    stack[-1] = elt(env, 2); /* tps */
    stack[0] = (Lisp_Object)17; /* 1 */
    v69 = elt(env, 3); /* "PS:GETV: not a ps" */
    v67 = v68;
    v69 = list2(v69, v67);
    nil = C_nil;
    if (exception_pending()) goto v87;
    env = stack[-2];
    {
        Lisp_Object v66 = stack[-1];
        Lisp_Object v70 = stack[0];
        popv(3);
        fn = elt(env, 5); /* rerror */
        return (*qfnn(fn))(qenv(fn), 3, v66, v70, v69);
    }
/* error exit handlers */
v87:
    popv(3);
    return nil;
}



/* Code for c!:ordxp */

static Lisp_Object CC_cTordxp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v48, v33, v51;
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
    v48 = v16;
    v33 = v0;
/* end of prologue */
    v51 = v33;
    v51 = Lconsp(nil, v51);
    env = stack[0];
    if (v51 == nil) goto v12;
    v51 = v48;
    v51 = Lconsp(nil, v51);
    if (v51 == nil) goto v29;
    v33 = qcdr(v33);
    v48 = qcdr(v48);
        popv(1);
        return Llessp(nil, v33, v48);

v29:
    v48 = nil;
    { popv(1); return onevalue(v48); }

v12:
    v51 = v48;
    v51 = Lconsp(nil, v51);
    if (v51 == nil) goto v31;
    v48 = lisp_true;
    { popv(1); return onevalue(v48); }

v31:
        popv(1);
        return Llessp(nil, v33, v48);
}



/* Code for dm!-abs */

static Lisp_Object CC_dmKabs(Lisp_Object env,
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
    fn = elt(env, 1); /* !:minusp */
    v2 = (*qfn1(fn))(qenv(fn), v2);
    nil = C_nil;
    if (exception_pending()) goto v13;
    env = stack[-1];
    if (v2 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v2 = stack[0];
    {
        popv(2);
        fn = elt(env, 2); /* dm!-minus */
        return (*qfn1(fn))(qenv(fn), v2);
    }
/* error exit handlers */
v13:
    popv(2);
    return nil;
}



/* Code for evcomp */

static Lisp_Object CC_evcomp(Lisp_Object env,
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
    stack[0] = qvalue(elt(env, 1)); /* dipsortevcomp!* */
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



/* Code for evmatrixcomp2 */

static Lisp_Object MS_CDECL CC_evmatrixcomp2(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v16,
                         Lisp_Object v63, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v107, v141, v128, v234;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "evmatrixcomp2");
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

v11:
    v107 = stack[-2];
    if (v107 == nil) { Lisp_Object res = stack[0]; popv(5); return onevalue(res); }
    v107 = stack[-1];
    if (v107 == nil) { Lisp_Object res = stack[0]; popv(5); return onevalue(res); }
    v107 = stack[-1];
    v107 = qcar(v107);
    stack[-3] = v107;
    v141 = stack[-3];
    v107 = (Lisp_Object)1; /* 0 */
    v107 = Leqn(nil, v141, v107);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-4];
    if (v107 == nil) goto v42;
    v107 = stack[-2];
    v128 = qcdr(v107);
    v107 = stack[-1];
    v141 = qcdr(v107);
    v107 = stack[0];
    stack[-2] = v128;
    stack[-1] = v141;
    stack[0] = v107;
    goto v11;

v42:
    v141 = stack[-3];
    v107 = (Lisp_Object)17; /* 1 */
    v107 = Leqn(nil, v141, v107);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-4];
    if (v107 == nil) goto v65;
    v107 = stack[-2];
    v234 = qcdr(v107);
    v107 = stack[-1];
    v128 = qcdr(v107);
    v141 = stack[0];
    v107 = stack[-2];
    v107 = qcar(v107);
    v107 = (Lisp_Object)(int32_t)((int32_t)v141 + (int32_t)v107 - TAG_FIXNUM);
    stack[-2] = v234;
    stack[-1] = v128;
    stack[0] = v107;
    goto v11;

v65:
    v234 = stack[-2];
    v128 = stack[-3];
    v141 = stack[-1];
    v107 = stack[0];
    {
        popv(5);
        fn = elt(env, 1); /* evmatrixcomp3 */
        return (*qfnn(fn))(qenv(fn), 4, v234, v128, v141, v107);
    }
/* error exit handlers */
v145:
    popv(5);
    return nil;
}



/* Code for xval */

static Lisp_Object CC_xval(Lisp_Object env,
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
        fn = elt(env, 1); /* wedgefax */
        return (*qfn1(fn))(qenv(fn), v12);
    }
}



/* Code for convprec */

static Lisp_Object CC_convprec(Lisp_Object env,
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
    fn = elt(env, 1); /* round!* */
    v4 = (*qfn1(fn))(qenv(fn), v4);
    nil = C_nil;
    if (exception_pending()) goto v12;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* convchk */
        return (*qfn1(fn))(qenv(fn), v4);
    }
/* error exit handlers */
v12:
    popv(1);
    return nil;
}



/* Code for physopp */

static Lisp_Object CC_physopp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v64, v100;
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
    v100 = v0;
/* end of prologue */
    v64 = v100;
    if (!consp(v64)) goto v3;
    v64 = v100;
    v64 = qcar(v64);
    if (symbolp(v64)) goto v49;
    v64 = nil;
    { popv(1); return onevalue(v64); }

v49:
    v64 = v100;
    v100 = qcar(v64);
    v64 = elt(env, 1); /* rtype */
    v64 = get(v100, v64);
    env = stack[0];
    v100 = elt(env, 2); /* physop */
    v64 = (v64 == v100 ? lisp_true : nil);
    { popv(1); return onevalue(v64); }

v3:
    v64 = v100;
    if (symbolp(v64)) goto v15;
    v64 = nil;
    { popv(1); return onevalue(v64); }

v15:
    v64 = elt(env, 1); /* rtype */
    v64 = get(v100, v64);
    env = stack[0];
    v100 = elt(env, 2); /* physop */
    v64 = (v64 == v100 ? lisp_true : nil);
    { popv(1); return onevalue(v64); }
}



/* Code for memq_edgelist */

static Lisp_Object CC_memq_edgelist(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v1, v2;
    CSL_IGNORE(nil);
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v1 = v16;
    v2 = v0;
/* end of prologue */
    v2 = qcar(v2);
    v1 = Lassoc(nil, v2, v1);
    return onevalue(v1);
}



/* Code for c_zero */

static Lisp_Object MS_CDECL CC_c_zero(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v63;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "c_zero");
    CSL_IGNORE(env);
/* end of prologue */
    v63 = nil;
    return onevalue(v63);
}



/* Code for sieve_pv0 */

static Lisp_Object MS_CDECL CC_sieve_pv0(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v16,
                         Lisp_Object v63, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v54, v87, v66;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "sieve_pv0");
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
    v54 = stack[-2];
    if (!(v54 == nil)) goto v25;
    v54 = nil;
    { popv(4); return onevalue(v54); }

v25:
    v54 = stack[-1];
    if (v54 == nil) goto v32;
    v54 = stack[-1];
    v54 = qcar(v54);
    v54 = qcar(v54);
    v87 = qcdr(v54);
    v54 = stack[-2];
    v54 = qcar(v54);
    v54 = qcdr(v54);
    v54 = (Lisp_Object)greaterp2(v87, v54);
    nil = C_nil;
    if (exception_pending()) goto v57;
    v54 = v54 ? lisp_true : nil;
    env = stack[-3];
    if (v54 == nil) goto v32;
    v54 = stack[-1];
    v54 = qcdr(v54);
    stack[-1] = v54;
    goto v25;

v32:
    v54 = stack[-2];
    if (v54 == nil) { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
    v54 = stack[-1];
    if (v54 == nil) { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
    v66 = stack[-2];
    v54 = stack[-1];
    v87 = qcar(v54);
    v54 = stack[0];
    fn = elt(env, 1); /* reduce_pv0 */
    v54 = (*qfnn(fn))(qenv(fn), 3, v66, v87, v54);
    nil = C_nil;
    if (exception_pending()) goto v57;
    env = stack[-3];
    stack[-2] = v54;
    v54 = stack[-1];
    v54 = qcdr(v54);
    stack[-1] = v54;
    goto v32;
/* error exit handlers */
v57:
    popv(4);
    return nil;
}



/* Code for quotelist */

static Lisp_Object CC_quotelist(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object v9;
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v9 = v0;
/* end of prologue */
    v9 = elt(env, 1); /* list */
    return onevalue(v9);
}



/* Code for pnth */

static Lisp_Object CC_pnth(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v46, v31, v32;
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
    v31 = v16;
    stack[0] = v0;
/* end of prologue */

v4:
    v46 = stack[0];
    if (v46 == nil) goto v1;
    v32 = v31;
    v46 = (Lisp_Object)17; /* 1 */
    if (v32 == v46) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v46 = stack[0];
    v46 = qcdr(v46);
    stack[0] = v46;
    v46 = v31;
    v46 = sub1(v46);
    nil = C_nil;
    if (exception_pending()) goto v36;
    env = stack[-1];
    v31 = v46;
    goto v4;

v1:
    v32 = elt(env, 1); /* alg */
    v31 = (Lisp_Object)97; /* 6 */
    v46 = elt(env, 2); /* "Index out of range" */
    {
        popv(2);
        fn = elt(env, 3); /* rerror */
        return (*qfnn(fn))(qenv(fn), 3, v32, v31, v46);
    }
/* error exit handlers */
v36:
    popv(2);
    return nil;
}



/* Code for find2 */

static Lisp_Object CC_find2(Lisp_Object env,
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



/* Code for csl_normbf */

static Lisp_Object CC_csl_normbf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v55, v65, v103;
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
    stack[-3] = nil;
    v55 = stack[-2];
    v55 = qcdr(v55);
    v65 = qcar(v55);
    stack[0] = v65;
    v55 = (Lisp_Object)1; /* 0 */
    if (v65 == v55) goto v7;
    v65 = stack[0];
    v55 = (Lisp_Object)1; /* 0 */
    v55 = (Lisp_Object)lessp2(v65, v55);
    nil = C_nil;
    if (exception_pending()) goto v220;
    v55 = v55 ? lisp_true : nil;
    env = stack[-4];
    if (v55 == nil) goto v15;
    v55 = stack[0];
    v55 = negate(v55);
    nil = C_nil;
    if (exception_pending()) goto v220;
    env = stack[-4];
    stack[0] = v55;
    v55 = lisp_true;
    stack[-3] = v55;
    goto v15;

v15:
    v55 = stack[0];
    fn = elt(env, 3); /* lsd */
    v55 = (*qfn1(fn))(qenv(fn), v55);
    nil = C_nil;
    if (exception_pending()) goto v220;
    env = stack[-4];
    stack[-1] = v55;
    v55 = stack[-1];
    v55 = negate(v55);
    nil = C_nil;
    if (exception_pending()) goto v220;
    env = stack[-4];
    v55 = ash(stack[0], v55);
    nil = C_nil;
    if (exception_pending()) goto v220;
    env = stack[-4];
    stack[0] = v55;
    v55 = stack[-3];
    if (v55 == nil) goto v41;
    v55 = stack[0];
    v55 = negate(v55);
    nil = C_nil;
    if (exception_pending()) goto v220;
    env = stack[-4];
    stack[0] = v55;
    goto v41;

v41:
    v65 = stack[-1];
    v55 = stack[-2];
    v55 = qcdr(v55);
    v55 = qcdr(v55);
    v55 = plus2(v65, v55);
    nil = C_nil;
    if (exception_pending()) goto v220;
    env = stack[-4];
    stack[-1] = v55;
    v103 = elt(env, 2); /* !:rd!: */
    v65 = stack[0];
    v55 = stack[-1];
    popv(5);
    return list2star(v103, v65, v55);

v7:
    v55 = elt(env, 1); /* (!:rd!: 0 . 0) */
    { popv(5); return onevalue(v55); }
/* error exit handlers */
v220:
    popv(5);
    return nil;
}



/* Code for zero2nil */

static Lisp_Object CC_zero2nil(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v1;
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
    stack[0] = v0;
/* end of prologue */
    v1 = stack[0];
    fn = elt(env, 1); /* !:zerop */
    v1 = (*qfn1(fn))(qenv(fn), v1);
    nil = C_nil;
    if (exception_pending()) goto v25;
    if (v1 == nil) { Lisp_Object res = stack[0]; popv(1); return onevalue(res); }
    v1 = nil;
    { popv(1); return onevalue(v1); }
/* error exit handlers */
v25:
    popv(1);
    return nil;
}



/* Code for binding */

static Lisp_Object CC_binding(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v27, v28;
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
    v27 = v0;
/* end of prologue */
    v28 = v27;
    v27 = elt(env, 0); /* binding */
    v27 = get(v28, v27);
    v28 = v27;
    v27 = v28;
    if (v27 == nil) goto v25;
    v27 = v28;
    v27 = qcar(v27);
    return onevalue(v27);

v25:
    v27 = nil;
    return onevalue(v27);
}



/* Code for vevmtest!? */

static Lisp_Object CC_vevmtestW(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v105, v69, v67, v68;
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
    v69 = v16;
    v67 = v0;
/* end of prologue */

v4:
    v105 = v69;
    if (v105 == nil) goto v5;
    v105 = v67;
    if (v105 == nil) goto v1;
    v105 = v67;
    v68 = qcar(v105);
    v105 = v69;
    v105 = qcar(v105);
    if (((int32_t)(v68)) < ((int32_t)(v105))) goto v100;
    v105 = v67;
    v105 = qcdr(v105);
    v67 = v105;
    v105 = v69;
    v105 = qcdr(v105);
    v69 = v105;
    goto v4;

v100:
    v105 = nil;
    return onevalue(v105);

v1:
    v105 = v69;
    if (v105 == nil) goto v26;
    v105 = v69;
    v67 = qcar(v105);
    v105 = (Lisp_Object)1; /* 0 */
    if (!(v67 == v105)) goto v53;
    v105 = v69;
    v105 = qcdr(v105);
    fn = elt(env, 1); /* vevzero!?1 */
    v105 = (*qfn1(fn))(qenv(fn), v105);
    errexit();
    if (!(v105 == nil)) goto v26;

v53:
    v105 = nil;
    return onevalue(v105);

v26:
    v105 = lisp_true;
    return onevalue(v105);

v5:
    v105 = lisp_true;
    return onevalue(v105);
}



/* Code for vbcsize */

static Lisp_Object CC_vbcsize(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v50, v52, v193;
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
    v52 = v16;
    stack[0] = v0;
/* end of prologue */

v45:
    v193 = v52;
    v50 = (Lisp_Object)-15; /* -1 */
    if (((int32_t)(v193)) > ((int32_t)(v50))) goto v4;
    v50 = stack[0];
    if (!consp(v50)) { popv(2); return onevalue(v52); }
    v50 = stack[0];
    v50 = qcar(v50);
    v52 = (Lisp_Object)((int32_t)(v52) + 0x10);
    v50 = CC_vbcsize(env, v50, v52);
    nil = C_nil;
    if (exception_pending()) goto v34;
    env = stack[-1];
    v52 = v50;
    v50 = v52;
    if (v50 == nil) goto v10;
    v50 = stack[0];
    v50 = qcdr(v50);
    stack[0] = v50;
    goto v45;

v10:
    v50 = nil;
    { popv(2); return onevalue(v50); }

v4:
    v50 = nil;
    { popv(2); return onevalue(v50); }
/* error exit handlers */
v34:
    popv(2);
    return nil;
}



/* Code for wedgefax */

static Lisp_Object CC_wedgefax(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v38, v44, v47;
    CSL_IGNORE(nil);
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v44 = v0;
/* end of prologue */
    v38 = v44;
    v47 = elt(env, 1); /* wedge */
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



/* Code for times!: */

static Lisp_Object CC_timesT(Lisp_Object env,
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
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v16;
    stack[-2] = v0;
/* end of prologue */
    stack[-3] = elt(env, 1); /* !:rd!: */
    v53 = stack[-2];
    v53 = qcdr(v53);
    v14 = qcar(v53);
    v53 = stack[-1];
    v53 = qcdr(v53);
    v53 = qcar(v53);
    stack[0] = times2(v14, v53);
    nil = C_nil;
    if (exception_pending()) goto v36;
    env = stack[-4];
    v53 = stack[-2];
    v53 = qcdr(v53);
    v14 = qcdr(v53);
    v53 = stack[-1];
    v53 = qcdr(v53);
    v53 = qcdr(v53);
    v53 = plus2(v14, v53);
    nil = C_nil;
    if (exception_pending()) goto v36;
    {
        Lisp_Object v48 = stack[-3];
        Lisp_Object v33 = stack[0];
        popv(5);
        return list2star(v48, v33, v53);
    }
/* error exit handlers */
v36:
    popv(5);
    return nil;
}



/* Code for round!* */

static Lisp_Object CC_roundH(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v2, v25;
    CSL_IGNORE(nil);
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v2 = v0;
/* end of prologue */
    v25 = v2;
    v25 = qcdr(v25);
    if (!(!consp(v25))) return onevalue(v2);
    v2 = qcdr(v2);
    return onevalue(v2);
}



/* Code for noncomp2 */

static Lisp_Object CC_noncomp2(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v28, v38;
    CSL_IGNORE(nil);
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v38 = v0;
/* end of prologue */
    v28 = v38;
    if (!consp(v28)) goto v3;
    v28 = v38;
    v38 = elt(env, 1); /* noncom */
        return Lflagpcar(nil, v28, v38);

v3:
    v28 = v38;
    if (!symbolp(v28)) v28 = nil;
    else { v28 = qfastgets(v28);
           if (v28 != nil) { v28 = elt(v28, 0); /* noncom */
#ifdef RECORD_GET
             if (v28 == SPID_NOPROP)
                record_get(elt(fastget_names, 0), 0),
                v28 = nil;
             else record_get(elt(fastget_names, 0), 1),
                v28 = lisp_true; }
           else record_get(elt(fastget_names, 0), 0); }
#else
             if (v28 == SPID_NOPROP) v28 = nil; else v28 = lisp_true; }}
#endif
    return onevalue(v28);
}



/* Code for union_edge */

static Lisp_Object CC_union_edge(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v17, v18;
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
    v18 = stack[-1];
    v17 = stack[0];
    fn = elt(env, 1); /* memq_edgelist */
    v17 = (*qfn2(fn))(qenv(fn), v18, v17);
    nil = C_nil;
    if (exception_pending()) goto v21;
    if (!(v17 == nil)) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v18 = stack[-1];
    v17 = stack[0];
    popv(2);
    return cons(v18, v17);
/* error exit handlers */
v21:
    popv(2);
    return nil;
}



/* Code for termsf */

static Lisp_Object CC_termsf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v36, v48;
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
    v36 = (Lisp_Object)1; /* 0 */
    v48 = v36;
    goto v5;

v5:
    v36 = stack[0];
    if (!consp(v36)) goto v45;
    v36 = stack[0];
    v36 = qcar(v36);
    if (!consp(v36)) goto v45;
    stack[-1] = v48;
    v36 = stack[0];
    v36 = qcar(v36);
    v36 = qcdr(v36);
    v36 = CC_termsf(env, v36);
    nil = C_nil;
    if (exception_pending()) goto v42;
    env = stack[-2];
    v36 = plus2(stack[-1], v36);
    nil = C_nil;
    if (exception_pending()) goto v42;
    env = stack[-2];
    v48 = v36;
    v36 = stack[0];
    v36 = qcdr(v36);
    stack[0] = v36;
    goto v5;

v45:
    v36 = stack[0];
    if (v36 == nil) { popv(3); return onevalue(v48); }
    v36 = v48;
    popv(3);
    return add1(v36);
/* error exit handlers */
v42:
    popv(3);
    return nil;
}



/* Code for mo_divides!? */

static Lisp_Object CC_mo_dividesW(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v2, v25;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v2 = v16;
    v25 = v0;
/* end of prologue */
    v25 = qcar(v25);
    v2 = qcar(v2);
    {
        fn = elt(env, 1); /* mo!=modiv1 */
        return (*qfn2(fn))(qenv(fn), v25, v2);
    }
}



/* Code for dlesslex */

static Lisp_Object CC_dlesslex(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v36, v48, v33, v51;
    CSL_IGNORE(nil);
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v48 = v16;
    v33 = v0;
/* end of prologue */

v4:
    v36 = v33;
    if (v36 == nil) goto v5;
    v36 = v33;
    v51 = qcar(v36);
    v36 = v48;
    v36 = qcar(v36);
    if (((int32_t)(v51)) > ((int32_t)(v36))) goto v1;
    v36 = v33;
    v51 = qcar(v36);
    v36 = v48;
    v36 = qcar(v36);
    if (((int32_t)(v51)) < ((int32_t)(v36))) goto v43;
    v36 = v33;
    v36 = qcdr(v36);
    v33 = v36;
    v36 = v48;
    v36 = qcdr(v36);
    v48 = v36;
    goto v4;

v43:
    v36 = lisp_true;
    return onevalue(v36);

v1:
    v36 = nil;
    return onevalue(v36);

v5:
    v36 = nil;
    return onevalue(v36);
}



/* Code for pappl */

static Lisp_Object CC_pappl(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v134, v105;
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
    v134 = stack[-3];
    fn = elt(env, 1); /* unpkp */
    v134 = (*qfn1(fn))(qenv(fn), v134);
    nil = C_nil;
    if (exception_pending()) goto v87;
    env = stack[-5];
    stack[-3] = v134;
    goto v2;

v2:
    v134 = stack[-3];
    if (v134 == nil) goto v1;
    v134 = stack[-2];
    stack[-1] = v134;
    v134 = (Lisp_Object)17; /* 1 */
    stack[0] = v134;
    goto v23;

v23:
    v134 = stack[-3];
    v134 = qcar(v134);
    v105 = sub1(v134);
    nil = C_nil;
    if (exception_pending()) goto v87;
    env = stack[-5];
    v134 = stack[0];
    v134 = difference2(v105, v134);
    nil = C_nil;
    if (exception_pending()) goto v87;
    env = stack[-5];
    v134 = Lminusp(nil, v134);
    env = stack[-5];
    if (v134 == nil) goto v18;
    v134 = stack[-1];
    v105 = qcar(v134);
    v134 = stack[-4];
    v134 = cons(v105, v134);
    nil = C_nil;
    if (exception_pending()) goto v87;
    env = stack[-5];
    stack[-4] = v134;
    v134 = stack[-3];
    v134 = qcdr(v134);
    stack[-3] = v134;
    goto v2;

v18:
    v134 = stack[-1];
    v134 = qcdr(v134);
    stack[-1] = v134;
    v134 = stack[0];
    v134 = add1(v134);
    nil = C_nil;
    if (exception_pending()) goto v87;
    env = stack[-5];
    stack[0] = v134;
    goto v23;

v1:
    v134 = stack[-4];
        popv(6);
        return Lnreverse(nil, v134);
/* error exit handlers */
v87:
    popv(6);
    return nil;
}



/* Code for adjoin!-term */

static Lisp_Object MS_CDECL CC_adjoinKterm(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v16,
                         Lisp_Object v63, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v15, v43, v29, v17;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "adjoin-term");
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v15 = v63;
    v43 = v16;
    v29 = v0;
/* end of prologue */
    v17 = v43;
    if (v17 == nil) return onevalue(v15);
    return acons(v29, v43, v15);
}



/* Code for modzerop!: */

static Lisp_Object CC_modzeropT(Lisp_Object env,
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
    v8 = (Lisp_Object)1; /* 0 */
    v8 = (v1 == v8 ? lisp_true : nil);
    return onevalue(v8);
}



/* Code for tayexp!-lessp */

static Lisp_Object CC_tayexpKlessp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v21, v22, v23;
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
    v22 = v16;
    v23 = v0;
/* end of prologue */
    v21 = v23;
    if (!(!consp(v21))) goto v15;
    v21 = v22;
    if (!(!consp(v21))) goto v15;
    v21 = v23;
        popv(1);
        return Llessp(nil, v21, v22);

v15:
    v21 = v23;
    fn = elt(env, 1); /* tayexp!-difference */
    v21 = (*qfn2(fn))(qenv(fn), v21, v22);
    nil = C_nil;
    if (exception_pending()) goto v30;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* !:minusp */
        return (*qfn1(fn))(qenv(fn), v21);
    }
/* error exit handlers */
v30:
    popv(1);
    return nil;
}



/* Code for get!+mat!+entry */

static Lisp_Object MS_CDECL CC_getLmatLentry(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v16,
                         Lisp_Object v63, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v44, v47;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "get+mat+entry");
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
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v63;
    v44 = v16;
    v47 = v0;
/* end of prologue */
    fn = elt(env, 1); /* nth */
    v47 = (*qfn2(fn))(qenv(fn), v47, v44);
    nil = C_nil;
    if (exception_pending()) goto v43;
    env = stack[-1];
    v44 = stack[0];
    {
        popv(2);
        fn = elt(env, 1); /* nth */
        return (*qfn2(fn))(qenv(fn), v47, v44);
    }
/* error exit handlers */
v43:
    popv(2);
    return nil;
}



/* Code for butes */

static Lisp_Object CC_butes(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v36, v48, v33;
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
    v33 = v0;
/* end of prologue */
    v36 = v33;
    v36 = qcar(v36);
    qvalue(elt(env, 1)) = v36; /* cha */
    v48 = qvalue(elt(env, 1)); /* cha */
    v36 = elt(env, 2); /* !  */
    if (v48 == v36) goto v6;
    v48 = qvalue(elt(env, 1)); /* cha */
    v36 = elt(env, 3); /* !$ */
    if (v48 == v36) goto v6;
    v36 = v33;
    stack[0] = qcar(v36);
    v36 = v33;
    v36 = qcdr(v36);
    v36 = CC_butes(env, v36);
    nil = C_nil;
    if (exception_pending()) goto v42;
    {
        Lisp_Object v49 = stack[0];
        popv(1);
        return cons(v49, v36);
    }

v6:
    v36 = nil;
    { popv(1); return onevalue(v36); }
/* error exit handlers */
v42:
    popv(1);
    return nil;
}



/* Code for bftrim!: */

static Lisp_Object CC_bftrimT(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v27, v28;
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
    v27 = v0;
/* end of prologue */
    stack[0] = v27;
    v28 = qvalue(elt(env, 1)); /* !:bprec!: */
    v27 = (Lisp_Object)49; /* 3 */
    v27 = difference2(v28, v27);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-1];
    fn = elt(env, 2); /* round!:mt */
    v27 = (*qfn2(fn))(qenv(fn), stack[0], v27);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-1];
    {
        popv(2);
        fn = elt(env, 3); /* csl_normbf */
        return (*qfn1(fn))(qenv(fn), v27);
    }
/* error exit handlers */
v44:
    popv(2);
    return nil;
}



/* Code for numlis */

static Lisp_Object CC_numlis(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v28, v38;
    CSL_IGNORE(nil);
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v28 = v0;
/* end of prologue */

v11:
    v38 = v28;
    v38 = (v38 == nil ? lisp_true : nil);
    if (!(v38 == nil)) return onevalue(v38);
    v38 = v28;
    v38 = qcar(v38);
    if (is_number(v38)) goto v25;
    v28 = nil;
    return onevalue(v28);

v25:
    v28 = qcdr(v28);
    goto v11;
}



/* Code for !:minusp */

static Lisp_Object CC_Tminusp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v18, v19, v20;
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
    v20 = v0;
/* end of prologue */
    v18 = v20;
    if (!consp(v18)) goto v3;
    v18 = v20;
    v19 = qcar(v18);
    v18 = elt(env, 1); /* minusp */
    v18 = get(v19, v18);
    v19 = v20;
        return Lapply1(nil, v18, v19);

v3:
    v18 = v20;
        return Lminusp(nil, v18);
}



/* Code for pm!:free */

static Lisp_Object CC_pmTfree(Lisp_Object env,
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
    fn = elt(env, 2); /* binding */
    v8 = (*qfn1(fn))(qenv(fn), v8);
    nil = C_nil;
    if (exception_pending()) goto v2;
    env = stack[0];
    v1 = elt(env, 1); /* unbound */
    v8 = (v8 == v1 ? lisp_true : nil);
    { popv(1); return onevalue(v8); }
/* error exit handlers */
v2:
    popv(1);
    return nil;
}



/* Code for buchvevdivides!? */

static Lisp_Object CC_buchvevdividesW(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v99, v10, v53;
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
    v10 = stack[0];
    v99 = stack[-1];
    fn = elt(env, 2); /* vevmtest!? */
    v99 = (*qfn2(fn))(qenv(fn), v10, v99);
    nil = C_nil;
    if (exception_pending()) goto v31;
    env = stack[-2];
    if (v99 == nil) goto v4;
    v99 = qvalue(elt(env, 1)); /* gmodule!* */
    v99 = (v99 == nil ? lisp_true : nil);
    if (!(v99 == nil)) { popv(3); return onevalue(v99); }
    v53 = stack[-1];
    v10 = stack[0];
    v99 = qvalue(elt(env, 1)); /* gmodule!* */
    {
        popv(3);
        fn = elt(env, 3); /* gevcompatible1 */
        return (*qfnn(fn))(qenv(fn), 3, v53, v10, v99);
    }

v4:
    v99 = nil;
    { popv(3); return onevalue(v99); }
/* error exit handlers */
v31:
    popv(3);
    return nil;
}



/* Code for mkround */

static Lisp_Object CC_mkround(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v27, v28;
    CSL_IGNORE(nil);
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v28 = v0;
/* end of prologue */
    v27 = v28;
    if (!(!consp(v27))) return onevalue(v28);
    v27 = elt(env, 1); /* !:rd!: */
    return cons(v27, v28);
}



/* Code for bc_prod */

static Lisp_Object CC_bc_prod(Lisp_Object env,
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
/* copy arguments values to proper place */
    v1 = v16;
    v2 = v0;
/* end of prologue */
    fn = elt(env, 1); /* multf */
    v1 = (*qfn2(fn))(qenv(fn), v2, v1);
    nil = C_nil;
    if (exception_pending()) goto v25;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* bc!=simp */
        return (*qfn1(fn))(qenv(fn), v1);
    }
/* error exit handlers */
v25:
    popv(1);
    return nil;
}



/* Code for reduce_pv */

static Lisp_Object CC_reduce_pv(Lisp_Object env,
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
    v25 = lisp_true;
    {
        fn = elt(env, 1); /* reduce_pv0 */
        return (*qfnn(fn))(qenv(fn), 3, v24, v13, v25);
    }
}



/* Code for modonep!: */

static Lisp_Object CC_modonepT(Lisp_Object env,
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



/* Code for finde */

static Lisp_Object CC_finde(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v20, v21, v22, v23;
    CSL_IGNORE(nil);
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v21 = v16;
    v22 = v0;
/* end of prologue */

v4:
    v20 = v22;
    if (v20 == nil) goto v5;
    v23 = v21;
    v20 = v22;
    v20 = qcar(v20);
    v20 = qcdr(v20);
    v20 = Lmemq(nil, v23, v20);
    if (!(v20 == nil)) return onevalue(v22);
    v20 = v22;
    v20 = qcdr(v20);
    v22 = v20;
    goto v4;

v5:
    v20 = nil;
    return onevalue(v20);
}



/* Code for nocp */

static Lisp_Object CC_nocp(Lisp_Object env,
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
    v44 = (v44 == nil ? lisp_true : nil);
    if (!(v44 == nil)) { popv(2); return onevalue(v44); }
    v44 = stack[0];
    v44 = qcar(v44);
    v44 = qcar(v44);
    fn = elt(env, 1); /* noncomp */
    v44 = (*qfn1(fn))(qenv(fn), v44);
    nil = C_nil;
    if (exception_pending()) goto v15;
    env = stack[-1];
    if (v44 == nil) goto v6;
    v44 = stack[0];
    v44 = qcdr(v44);
    stack[0] = v44;
    goto v11;

v6:
    v44 = nil;
    { popv(2); return onevalue(v44); }
/* error exit handlers */
v15:
    popv(2);
    return nil;
}



/* Code for compress!* */

static Lisp_Object CC_compressH(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v141, v128, v234, v112;
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
    v141 = v0;
/* end of prologue */
    v112 = nil;
    v128 = v141;
    v128 = qcar(v128);
    v128 = Ldigitp(nil, v128);
    env = stack[-1];
    if (v128 == nil) goto v12;
        popv(2);
        return Lcompress(nil, v141);

v12:
    stack[0] = v141;
    goto v26;

v26:
    v141 = stack[0];
    if (v141 == nil) goto v24;
    v141 = stack[0];
    v141 = qcar(v141);
    v234 = v141;
    v128 = v234;
    v141 = elt(env, 1); /* !/ */
    if (v128 == v141) goto v56;
    v128 = v234;
    v141 = elt(env, 2); /* !- */
    if (v128 == v141) goto v56;
    v128 = v234;
    v141 = elt(env, 3); /* !; */
    if (v128 == v141) goto v56;
    v128 = v234;
    v141 = elt(env, 4); /* !. */
    if (v128 == v141) goto v56;
    v141 = v234;
    v128 = v112;
    v141 = cons(v141, v128);
    nil = C_nil;
    if (exception_pending()) goto v226;
    env = stack[-1];
    v112 = v141;
    goto v20;

v20:
    v141 = stack[0];
    v141 = qcdr(v141);
    stack[0] = v141;
    goto v26;

v56:
    v128 = v234;
    v141 = elt(env, 5); /* !! */
    v234 = v112;
    v141 = list2star(v128, v141, v234);
    nil = C_nil;
    if (exception_pending()) goto v226;
    env = stack[-1];
    v112 = v141;
    goto v20;

v24:
    v141 = v112;
    v141 = Lnreverse(nil, v141);
    env = stack[-1];
    v141 = Lcompress(nil, v141);
    nil = C_nil;
    if (exception_pending()) goto v226;
        popv(2);
        return Lintern(nil, v141);
/* error exit handlers */
v226:
    popv(2);
    return nil;
}



/* Code for ps!:order */

static Lisp_Object CC_psTorder(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v32, v37;
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
    v32 = stack[0];
    if (!consp(v32)) goto v3;
    v32 = stack[0];
    v37 = qcar(v32);
    v32 = elt(env, 1); /* !:ps!: */
    v32 = Lneq(nil, v37, v32);
    nil = C_nil;
    if (exception_pending()) goto v48;
    env = stack[-1];
    if (v32 == nil) goto v30;
    v32 = stack[0];
    v37 = qcar(v32);
    v32 = elt(env, 2); /* dname */
    v32 = get(v37, v32);
    env = stack[-1];
    if (!(v32 == nil)) goto v3;

v30:
    v37 = stack[0];
    v32 = (Lisp_Object)1; /* 0 */
    {
        popv(2);
        fn = elt(env, 3); /* ps!:getv */
        return (*qfn2(fn))(qenv(fn), v37, v32);
    }

v3:
    v32 = (Lisp_Object)1; /* 0 */
    { popv(2); return onevalue(v32); }
/* error exit handlers */
v48:
    popv(2);
    return nil;
}



/* Code for !:onep */

static Lisp_Object CC_Tonep(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v18, v19, v20;
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
    v20 = v0;
/* end of prologue */
    v18 = v20;
    if (!consp(v18)) goto v3;
    v18 = v20;
    v19 = qcar(v18);
    v18 = elt(env, 1); /* onep */
    v18 = get(v19, v18);
    v19 = v20;
        return Lapply1(nil, v18, v19);

v3:
    v18 = v20;
        return Lonep(nil, v18);
}



/* Code for bcprod */

static Lisp_Object CC_bcprod(Lisp_Object env,
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
    v36 = times2(v48, v36);
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
    v36 = elt(env, 2); /* times */
    fn = elt(env, 4); /* bcint2op */
    v36 = (*qfnn(fn))(qenv(fn), 3, v33, v48, v36);
    nil = C_nil;
    if (exception_pending()) goto v49;
    env = stack[-2];
    if (!(v36 == nil)) { popv(3); return onevalue(v36); }
    v48 = stack[-1];
    v36 = stack[0];
    fn = elt(env, 5); /* multsq */
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



/* Code for sublistp */

static Lisp_Object CC_sublistp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v37, v36, v48, v33;
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
    v36 = v16;
    v48 = v0;
/* end of prologue */

v11:
    v37 = v48;
    v37 = (v37 == nil ? lisp_true : nil);
    if (!(v37 == nil)) { popv(2); return onevalue(v37); }
    v37 = v48;
    v33 = qcar(v37);
    v37 = v36;
    v37 = Lmember(nil, v33, v37);
    if (v37 == nil) goto v7;
    v37 = v48;
    stack[0] = qcdr(v37);
    v37 = v48;
    v37 = qcar(v37);
    v37 = Ldelete(nil, v37, v36);
    nil = C_nil;
    if (exception_pending()) goto v42;
    env = stack[-1];
    v48 = stack[0];
    v36 = v37;
    goto v11;

v7:
    v37 = nil;
    { popv(2); return onevalue(v37); }
/* error exit handlers */
v42:
    popv(2);
    return nil;
}



/* Code for order!: */

static Lisp_Object CC_orderT(Lisp_Object env,
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
    v30 = stack[0];
    v30 = qcdr(v30);
    v99 = qcar(v30);
    v30 = (Lisp_Object)1; /* 0 */
    if (v99 == v30) goto v3;
    v30 = stack[0];
    v30 = qcdr(v30);
    v30 = qcar(v30);
    v30 = Labsval(nil, v30);
    nil = C_nil;
    if (exception_pending()) goto v14;
    env = stack[-2];
    fn = elt(env, 1); /* msd */
    stack[-1] = (*qfn1(fn))(qenv(fn), v30);
    nil = C_nil;
    if (exception_pending()) goto v14;
    env = stack[-2];
    v30 = stack[0];
    v30 = qcdr(v30);
    v30 = qcdr(v30);
    v30 = sub1(v30);
    nil = C_nil;
    if (exception_pending()) goto v14;
    {
        Lisp_Object v46 = stack[-1];
        popv(3);
        return plus2(v46, v30);
    }

v3:
    v30 = (Lisp_Object)1; /* 0 */
    { popv(3); return onevalue(v30); }
/* error exit handlers */
v14:
    popv(3);
    return nil;
}



/* Code for pprin2 */

static Lisp_Object CC_pprin2(Lisp_Object env,
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
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0;
/* end of prologue */
    v15 = stack[0];
    v47 = qvalue(elt(env, 1)); /* !*pprinbuf!* */
    v47 = cons(v15, v47);
    nil = C_nil;
    if (exception_pending()) goto v17;
    env = stack[-2];
    qvalue(elt(env, 1)) = v47; /* !*pprinbuf!* */
    stack[-1] = qvalue(elt(env, 2)); /* !*posn!* */
    v47 = stack[0];
    v47 = Lexplodec(nil, v47);
    nil = C_nil;
    if (exception_pending()) goto v17;
    env = stack[-2];
    v47 = Llength(nil, v47);
    nil = C_nil;
    if (exception_pending()) goto v17;
    env = stack[-2];
    v47 = plus2(stack[-1], v47);
    nil = C_nil;
    if (exception_pending()) goto v17;
    env = stack[-2];
    qvalue(elt(env, 2)) = v47; /* !*posn!* */
    v47 = nil;
    { popv(3); return onevalue(v47); }
/* error exit handlers */
v17:
    popv(3);
    return nil;
}



/* Code for isanindex */

static Lisp_Object CC_isanindex(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v134, v105, v69;
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
    v69 = v0;
/* end of prologue */
    v134 = v69;
    if (symbolp(v134)) goto v2;
    v134 = nil;
    { popv(1); return onevalue(v134); }

v2:
    v105 = v69;
    v134 = qvalue(elt(env, 1)); /* physopindices!* */
    v134 = Lmemq(nil, v105, v134);
    if (!(v134 == nil)) { popv(1); return onevalue(v134); }
    v105 = v69;
    v134 = qvalue(elt(env, 2)); /* physopvarind!* */
    v134 = Lmember(nil, v105, v134);
    if (!(v134 == nil)) { popv(1); return onevalue(v134); }
    v105 = v69;
    v134 = qvalue(elt(env, 3)); /* frlis!* */
    v134 = Lmemq(nil, v105, v134);
    if (v134 == nil) goto v23;
    v105 = v69;
    v134 = qvalue(elt(env, 4)); /* frasc!* */
    fn = elt(env, 5); /* revassoc */
    v134 = (*qfn2(fn))(qenv(fn), v105, v134);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[0];
    v105 = qvalue(elt(env, 1)); /* physopindices!* */
    v134 = Lmember(nil, v134, v105);
    { popv(1); return onevalue(v134); }

v23:
    v134 = nil;
    { popv(1); return onevalue(v134); }
/* error exit handlers */
v67:
    popv(1);
    return nil;
}



/* Code for ring_ecart */

static Lisp_Object CC_ring_ecart(Lisp_Object env,
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
    v7 = (Lisp_Object)81; /* 5 */
    {
        fn = elt(env, 1); /* nth */
        return (*qfn2(fn))(qenv(fn), v8, v7);
    }
}



/* Code for unpkp */

static Lisp_Object CC_unpkp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v136, v233, v231;
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
    v136 = stack[-1];
    if (!(!consp(v136))) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v136 = stack[-1];
    v136 = Lexplode(nil, v136);
    nil = C_nil;
    if (exception_pending()) goto v235;
    env = stack[-3];
    stack[-1] = v136;
    v136 = stack[-1];
    v233 = Llength(nil, v136);
    nil = C_nil;
    if (exception_pending()) goto v235;
    env = stack[-3];
    v136 = (Lisp_Object)161; /* 10 */
    v136 = (Lisp_Object)geq2(v233, v136);
    nil = C_nil;
    if (exception_pending()) goto v235;
    v136 = v136 ? lisp_true : nil;
    env = stack[-3];
    stack[0] = v136;
    v136 = stack[0];
    if (v136 == nil) goto v33;
    v136 = stack[-1];
    v136 = Llength(nil, v136);
    nil = C_nil;
    if (exception_pending()) goto v235;
    env = stack[-3];
    v136 = Levenp(nil, v136);
    env = stack[-3];
    if (!(v136 == nil)) goto v33;
    v233 = elt(env, 1); /* !0 */
    v136 = stack[-1];
    v136 = cons(v233, v136);
    nil = C_nil;
    if (exception_pending()) goto v235;
    env = stack[-3];
    stack[-1] = v136;
    goto v33;

v33:
    v136 = stack[-1];
    if (v136 == nil) goto v48;
    v136 = stack[0];
    if (v136 == nil) goto v144;
    v136 = stack[-1];
    v233 = qcar(v136);
    v136 = qvalue(elt(env, 2)); /* diglist!* */
    v136 = Lassoc(nil, v233, v136);
    v136 = qcdr(v136);
    v233 = v136;
    v136 = stack[-1];
    v136 = qcdr(v136);
    stack[-1] = v136;
    v136 = (Lisp_Object)161; /* 10 */
    v231 = times2(v233, v136);
    nil = C_nil;
    if (exception_pending()) goto v235;
    env = stack[-3];
    v136 = stack[-1];
    v233 = qcar(v136);
    v136 = qvalue(elt(env, 2)); /* diglist!* */
    v136 = Lassoc(nil, v233, v136);
    v136 = qcdr(v136);
    v233 = plus2(v231, v136);
    nil = C_nil;
    if (exception_pending()) goto v235;
    env = stack[-3];
    v136 = stack[-2];
    v136 = cons(v233, v136);
    nil = C_nil;
    if (exception_pending()) goto v235;
    env = stack[-3];
    stack[-2] = v136;
    goto v34;

v34:
    v136 = stack[-1];
    v136 = qcdr(v136);
    stack[-1] = v136;
    goto v33;

v144:
    v136 = stack[-1];
    v233 = qcar(v136);
    v136 = qvalue(elt(env, 2)); /* diglist!* */
    v136 = Lassoc(nil, v233, v136);
    v233 = qcdr(v136);
    v136 = stack[-2];
    v136 = cons(v233, v136);
    nil = C_nil;
    if (exception_pending()) goto v235;
    env = stack[-3];
    stack[-2] = v136;
    goto v34;

v48:
    v136 = stack[-2];
        popv(4);
        return Lnreverse(nil, v136);
/* error exit handlers */
v235:
    popv(4);
    return nil;
}



/* Code for multiply!-by!-constant!-mod!-p */

static Lisp_Object CC_multiplyKbyKconstantKmodKp(Lisp_Object env,
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
    stack[0] = CC_multiplyKbyKconstantKmodKp(env, v66, v87);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-4];
    v87 = stack[-2];
    v66 = qcdr(v87);
    v87 = stack[-1];
    v87 = CC_multiplyKbyKconstantKmodKp(env, v66, v87);
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
    v87 = Lmodular_times(nil, v66, v87);
    env = stack[-4];
    {
        popv(5);
        fn = elt(env, 2); /* !*n2f */
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



/* Code for get_token */

static Lisp_Object MS_CDECL CC_get_token(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v14, v46;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "get_token");
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
    v14 = nil;
    stack[0] = v14;
    goto v2;

v2:
    v46 = Lreadch(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-1];
    qvalue(elt(env, 1)) = v46; /* ch */
    v14 = elt(env, 2); /* !> */
    v14 = Lneq(nil, v46, v14);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-1];
    if (v14 == nil) goto v21;
    v46 = qvalue(elt(env, 1)); /* ch */
    v14 = stack[0];
    v14 = cons(v46, v14);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-1];
    stack[0] = v14;
    goto v2;

v21:
    v46 = elt(env, 3); /* !$ */
    v14 = stack[0];
    popv(2);
    return cons(v46, v14);
/* error exit handlers */
v32:
    popv(2);
    return nil;
}



/* Code for ps!:last!-term */

static Lisp_Object CC_psTlastKterm(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v32, v37;
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
    v32 = stack[0];
    if (!consp(v32)) goto v3;
    v32 = stack[0];
    v37 = qcar(v32);
    v32 = elt(env, 1); /* !:ps!: */
    v32 = Lneq(nil, v37, v32);
    nil = C_nil;
    if (exception_pending()) goto v48;
    env = stack[-1];
    if (v32 == nil) goto v30;
    v32 = stack[0];
    v37 = qcar(v32);
    v32 = elt(env, 2); /* dname */
    v32 = get(v37, v32);
    env = stack[-1];
    if (!(v32 == nil)) goto v3;

v30:
    v37 = stack[0];
    v32 = (Lisp_Object)17; /* 1 */
    {
        popv(2);
        fn = elt(env, 4); /* ps!:getv */
        return (*qfn2(fn))(qenv(fn), v37, v32);
    }

v3:
    v32 = qvalue(elt(env, 3)); /* ps!:max!-order */
    { popv(2); return onevalue(v32); }
/* error exit handlers */
v48:
    popv(2);
    return nil;
}



/* Code for c!:ordexn */

static Lisp_Object CC_cTordexn(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v145, v146;
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



/* Code for nil2zero */

static Lisp_Object CC_nil2zero(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v8, v1;
    CSL_IGNORE(nil);
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v8 = v0;
/* end of prologue */
    v1 = v8;
    if (!(v1 == nil)) return onevalue(v8);
    v8 = (Lisp_Object)1; /* 0 */
    return onevalue(v8);
}



/* Code for bczero!? */

static Lisp_Object CC_bczeroW(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v38, v44;
    CSL_IGNORE(nil);
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v38 = v0;
/* end of prologue */
    v44 = qvalue(elt(env, 1)); /* !*grmod!* */
    if (v44 == nil) goto v13;
    v44 = v38;
    v38 = (Lisp_Object)1; /* 0 */
        return Leqn(nil, v44, v38);

v13:
    v38 = qcar(v38);
    v38 = (v38 == nil ? lisp_true : nil);
    return onevalue(v38);
}



/* Code for evzero!? */

static Lisp_Object CC_evzeroW(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v29, v17, v18;
    CSL_IGNORE(nil);
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v17 = v0;
/* end of prologue */

v11:
    v29 = v17;
    v29 = (v29 == nil ? lisp_true : nil);
    if (!(v29 == nil)) return onevalue(v29);
    v29 = v17;
    v18 = qcar(v29);
    v29 = (Lisp_Object)1; /* 0 */
    if (v18 == v29) goto v38;
    v29 = nil;
    return onevalue(v29);

v38:
    v29 = v17;
    v29 = qcdr(v29);
    v17 = v29;
    goto v11;
}



/* Code for wedgepf2 */

static Lisp_Object CC_wedgepf2(Lisp_Object env,
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
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v16;
    stack[-2] = v0;
/* end of prologue */
    v41 = stack[-2];
    if (v41 == nil) goto v4;
    v41 = stack[-1];
    if (v41 == nil) goto v4;
    v41 = stack[-2];
    v64 = qcar(v41);
    v41 = stack[-1];
    v41 = qcar(v41);
    fn = elt(env, 1); /* wedget2 */
    stack[-3] = (*qfn2(fn))(qenv(fn), v64, v41);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-4];
    v41 = stack[-2];
    v41 = qcar(v41);
    v64 = ncons(v41);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-4];
    v41 = stack[-1];
    v41 = qcdr(v41);
    stack[0] = CC_wedgepf2(env, v64, v41);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-4];
    v41 = stack[-2];
    v64 = qcdr(v41);
    v41 = stack[-1];
    v41 = CC_wedgepf2(env, v64, v41);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-4];
    fn = elt(env, 2); /* addpf */
    v41 = (*qfn2(fn))(qenv(fn), stack[0], v41);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-4];
    {
        Lisp_Object v67 = stack[-3];
        popv(5);
        fn = elt(env, 2); /* addpf */
        return (*qfn2(fn))(qenv(fn), v67, v41);
    }

v4:
    v41 = nil;
    { popv(5); return onevalue(v41); }
/* error exit handlers */
v69:
    popv(5);
    return nil;
}



/* Code for makelist */

static Lisp_Object CC_makelist(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v7, v8;
    CSL_IGNORE(nil);
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v7 = v0;
/* end of prologue */
    v8 = elt(env, 1); /* list */
    return cons(v8, v7);
}



/* Code for !*physopp */

static Lisp_Object CC_Hphysopp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v48, v33;
    CSL_IGNORE(nil);
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v33 = v0;
/* end of prologue */
    v48 = v33;
    if (!consp(v48)) goto v3;
    v48 = v33;
    v48 = qcar(v48);
    if (symbolp(v48)) goto v10;
    v48 = nil;
    return onevalue(v48);

v10:
    v48 = v33;
    v48 = qcar(v48);
    v33 = elt(env, 1); /* phystype */
    return get(v48, v33);

v3:
    v48 = v33;
    if (symbolp(v48)) goto v24;
    v48 = nil;
    return onevalue(v48);

v24:
    v48 = v33;
    v33 = elt(env, 1); /* phystype */
    return get(v48, v33);
}



/* Code for mo_vdivides!? */

static Lisp_Object CC_mo_vdividesW(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v19, v20;
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
    v19 = stack[-1];
    fn = elt(env, 1); /* mo_comp */
    stack[-2] = (*qfn1(fn))(qenv(fn), v19);
    nil = C_nil;
    if (exception_pending()) goto v30;
    env = stack[-3];
    v19 = stack[0];
    fn = elt(env, 1); /* mo_comp */
    v19 = (*qfn1(fn))(qenv(fn), v19);
    nil = C_nil;
    if (exception_pending()) goto v30;
    env = stack[-3];
    v19 = Leqn(nil, stack[-2], v19);
    nil = C_nil;
    if (exception_pending()) goto v30;
    env = stack[-3];
    if (v19 == nil) goto v4;
    v20 = stack[-1];
    v19 = stack[0];
    {
        popv(4);
        fn = elt(env, 2); /* mo_divides!? */
        return (*qfn2(fn))(qenv(fn), v20, v19);
    }

v4:
    v19 = nil;
    { popv(4); return onevalue(v19); }
/* error exit handlers */
v30:
    popv(4);
    return nil;
}



/* Code for pappl0 */

static Lisp_Object CC_pappl0(Lisp_Object env,
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
    v2 = v16;
    v25 = v0;
/* end of prologue */
    stack[0] = v25;
    fn = elt(env, 1); /* unpkp */
    v2 = (*qfn1(fn))(qenv(fn), v2);
    nil = C_nil;
    if (exception_pending()) goto v24;
    env = stack[-1];
    fn = elt(env, 2); /* pappl */
    v2 = (*qfn2(fn))(qenv(fn), stack[0], v2);
    nil = C_nil;
    if (exception_pending()) goto v24;
    env = stack[-1];
    {
        popv(2);
        fn = elt(env, 3); /* pkp */
        return (*qfn1(fn))(qenv(fn), v2);
    }
/* error exit handlers */
v24:
    popv(2);
    return nil;
}



/* Code for !*i2mod */

static Lisp_Object CC_Hi2mod(Lisp_Object env,
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
    fn = elt(env, 1); /* general!-modular!-number */
    v4 = (*qfn1(fn))(qenv(fn), v4);
    nil = C_nil;
    if (exception_pending()) goto v12;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* !*modular2f */
        return (*qfn1(fn))(qenv(fn), v4);
    }
/* error exit handlers */
v12:
    popv(1);
    return nil;
}



/* Code for general!-modular!-times */

static Lisp_Object CC_generalKmodularKtimes(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v36, v48;
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
    v36 = v16;
    v48 = v0;
/* end of prologue */
    v48 = times2(v48, v36);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[-1];
    v36 = qvalue(elt(env, 1)); /* current!-modulus */
    v36 = Cremainder(v48, v36);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[-1];
    stack[0] = v36;
    v48 = stack[0];
    v36 = (Lisp_Object)1; /* 0 */
    v36 = (Lisp_Object)lessp2(v48, v36);
    nil = C_nil;
    if (exception_pending()) goto v51;
    v36 = v36 ? lisp_true : nil;
    env = stack[-1];
    if (v36 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v48 = stack[0];
    v36 = qvalue(elt(env, 1)); /* current!-modulus */
    v36 = plus2(v48, v36);
    nil = C_nil;
    if (exception_pending()) goto v51;
    stack[0] = v36;
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
/* error exit handlers */
v51:
    popv(2);
    return nil;
}



/* Code for minus!: */

static Lisp_Object CC_minusT(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v27, v28;
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



/* Code for constp */

static Lisp_Object CC_constp(Lisp_Object env,
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
/* copy arguments values to proper place */
    v29 = v0;
/* end of prologue */
    v17 = v29;
    v17 = (is_number(v17) ? lisp_true : nil);
    if (!(v17 == nil)) { popv(1); return onevalue(v17); }
    v17 = v29;
    v17 = Lconsp(nil, v17);
    env = stack[0];
    if (v17 == nil) goto v6;
    v29 = qcar(v29);
    v17 = qvalue(elt(env, 1)); /* domainlist!* */
    v29 = Lmemq(nil, v29, v17);
    { popv(1); return onevalue(v29); }

v6:
    v29 = nil;
    { popv(1); return onevalue(v29); }
}



/* Code for mval */

static Lisp_Object CC_mval(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object v9;
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v9 = v0;
/* end of prologue */
    return onevalue(v9);
}



setup_type const u09_setup[] =
{
    {"prepsq*1",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_prepsqH1},
    {"mkdmoderr",               too_few_2,      CC_mkdmoderr,  wrong_no_2},
    {"ratfunpri1",              CC_ratfunpri1,  too_many_1,    wrong_no_1},
    {"quotpri",                 CC_quotpri,     too_many_1,    wrong_no_1},
    {"kernord-sort",            CC_kernordKsort,too_many_1,    wrong_no_1},
    {"put-kvalue",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_putKkvalue},
    {"revlis_without_mode",     CC_revlis_without_mode,too_many_1,wrong_no_1},
    {"subs2*",                  CC_subs2H,      too_many_1,    wrong_no_1},
    {"command",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_command},
    {"subs2chk",                CC_subs2chk,    too_many_1,    wrong_no_1},
    {"dsimptimes",              too_few_2,      CC_dsimptimes, wrong_no_2},
    {"remove-free-vars*",       CC_removeKfreeKvarsH,too_many_1,wrong_no_1},
    {"innprodp2",               too_few_2,      CC_innprodp2,  wrong_no_2},
    {"add1lis",                 CC_add1lis,     too_many_1,    wrong_no_1},
    {"wuconstantp",             CC_wuconstantp, too_many_1,    wrong_no_1},
    {"mkcopy",                  CC_mkcopy,      too_many_1,    wrong_no_1},
    {"nth",                     too_few_2,      CC_nth,        wrong_no_2},
    {"delall",                  too_few_2,      CC_delall,     wrong_no_2},
    {"ps:getv",                 too_few_2,      CC_psTgetv,    wrong_no_2},
    {"c:ordxp",                 too_few_2,      CC_cTordxp,    wrong_no_2},
    {"dm-abs",                  CC_dmKabs,      too_many_1,    wrong_no_1},
    {"evcomp",                  too_few_2,      CC_evcomp,     wrong_no_2},
    {"evmatrixcomp2",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_evmatrixcomp2},
    {"xval",                    CC_xval,        too_many_1,    wrong_no_1},
    {"convprec",                CC_convprec,    too_many_1,    wrong_no_1},
    {"physopp",                 CC_physopp,     too_many_1,    wrong_no_1},
    {"memq_edgelist",           too_few_2,      CC_memq_edgelist,wrong_no_2},
    {"c_zero",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_c_zero},
    {"sieve_pv0",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_sieve_pv0},
    {"quotelist",               CC_quotelist,   too_many_1,    wrong_no_1},
    {"pnth",                    too_few_2,      CC_pnth,       wrong_no_2},
    {"find2",                   too_few_2,      CC_find2,      wrong_no_2},
    {"csl_normbf",              CC_csl_normbf,  too_many_1,    wrong_no_1},
    {"zero2nil",                CC_zero2nil,    too_many_1,    wrong_no_1},
    {"binding",                 CC_binding,     too_many_1,    wrong_no_1},
    {"vevmtest?",               too_few_2,      CC_vevmtestW,  wrong_no_2},
    {"vbcsize",                 too_few_2,      CC_vbcsize,    wrong_no_2},
    {"wedgefax",                CC_wedgefax,    too_many_1,    wrong_no_1},
    {"times:",                  too_few_2,      CC_timesT,     wrong_no_2},
    {"round*",                  CC_roundH,      too_many_1,    wrong_no_1},
    {"noncomp2",                CC_noncomp2,    too_many_1,    wrong_no_1},
    {"union_edge",              too_few_2,      CC_union_edge, wrong_no_2},
    {"termsf",                  CC_termsf,      too_many_1,    wrong_no_1},
    {"mo_divides?",             too_few_2,      CC_mo_dividesW,wrong_no_2},
    {"dlesslex",                too_few_2,      CC_dlesslex,   wrong_no_2},
    {"pappl",                   too_few_2,      CC_pappl,      wrong_no_2},
    {"adjoin-term",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_adjoinKterm},
    {"modzerop:",               CC_modzeropT,   too_many_1,    wrong_no_1},
    {"tayexp-lessp",            too_few_2,      CC_tayexpKlessp,wrong_no_2},
    {"get+mat+entry",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_getLmatLentry},
    {"butes",                   CC_butes,       too_many_1,    wrong_no_1},
    {"bftrim:",                 CC_bftrimT,     too_many_1,    wrong_no_1},
    {"numlis",                  CC_numlis,      too_many_1,    wrong_no_1},
    {":minusp",                 CC_Tminusp,     too_many_1,    wrong_no_1},
    {"pm:free",                 CC_pmTfree,     too_many_1,    wrong_no_1},
    {"buchvevdivides?",         too_few_2,      CC_buchvevdividesW,wrong_no_2},
    {"mkround",                 CC_mkround,     too_many_1,    wrong_no_1},
    {"bc_prod",                 too_few_2,      CC_bc_prod,    wrong_no_2},
    {"reduce_pv",               too_few_2,      CC_reduce_pv,  wrong_no_2},
    {"modonep:",                CC_modonepT,    too_many_1,    wrong_no_1},
    {"finde",                   too_few_2,      CC_finde,      wrong_no_2},
    {"nocp",                    CC_nocp,        too_many_1,    wrong_no_1},
    {"compress*",               CC_compressH,   too_many_1,    wrong_no_1},
    {"ps:order",                CC_psTorder,    too_many_1,    wrong_no_1},
    {":onep",                   CC_Tonep,       too_many_1,    wrong_no_1},
    {"bcprod",                  too_few_2,      CC_bcprod,     wrong_no_2},
    {"sublistp",                too_few_2,      CC_sublistp,   wrong_no_2},
    {"order:",                  CC_orderT,      too_many_1,    wrong_no_1},
    {"pprin2",                  CC_pprin2,      too_many_1,    wrong_no_1},
    {"isanindex",               CC_isanindex,   too_many_1,    wrong_no_1},
    {"ring_ecart",              CC_ring_ecart,  too_many_1,    wrong_no_1},
    {"unpkp",                   CC_unpkp,       too_many_1,    wrong_no_1},
    {"multiply-by-constant-mod-p",too_few_2,    CC_multiplyKbyKconstantKmodKp,wrong_no_2},
    {"get_token",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_get_token},
    {"ps:last-term",            CC_psTlastKterm,too_many_1,    wrong_no_1},
    {"c:ordexn",                too_few_2,      CC_cTordexn,   wrong_no_2},
    {"nil2zero",                CC_nil2zero,    too_many_1,    wrong_no_1},
    {"bczero?",                 CC_bczeroW,     too_many_1,    wrong_no_1},
    {"evzero?",                 CC_evzeroW,     too_many_1,    wrong_no_1},
    {"wedgepf2",                too_few_2,      CC_wedgepf2,   wrong_no_2},
    {"makelist",                CC_makelist,    too_many_1,    wrong_no_1},
    {"*physopp",                CC_Hphysopp,    too_many_1,    wrong_no_1},
    {"mo_vdivides?",            too_few_2,      CC_mo_vdividesW,wrong_no_2},
    {"pappl0",                  too_few_2,      CC_pappl0,     wrong_no_2},
    {"*i2mod",                  CC_Hi2mod,      too_many_1,    wrong_no_1},
    {"general-modular-times",   too_few_2,      CC_generalKmodularKtimes,wrong_no_2},
    {"minus:",                  CC_minusT,      too_many_1,    wrong_no_1},
    {"constp",                  CC_constp,      too_many_1,    wrong_no_1},
    {"mval",                    CC_mval,        too_many_1,    wrong_no_1},
    {NULL, (one_args *)"u09", (two_args *)"11498 9352065 7046689", 0}
};

/* end of generated code */
