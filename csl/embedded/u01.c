
/* $destdir/generated-c\u01.c Machine generated C code */

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


/* Code for noncomp */

static Lisp_Object CC_noncomp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v1, v2;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v2 = v0;
/* end of prologue */
    v1 = qvalue(elt(env, 1)); /* !*ncmp */
    if (v1 == nil) goto v3;
    v1 = v2;
    {
        fn = elt(env, 2); /* noncomp1 */
        return (*qfn1(fn))(qenv(fn), v1);
    }

v3:
    v1 = nil;
    return onevalue(v1);
}



/* Code for simpcar */

static Lisp_Object CC_simpcar(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v4;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v4 = v0;
/* end of prologue */
    v4 = qcar(v4);
    {
        fn = elt(env, 1); /* simp */
        return (*qfn1(fn))(qenv(fn), v4);
    }
}



/* Code for reval */

static Lisp_Object CC_reval(Lisp_Object env,
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
        fn = elt(env, 1); /* reval1 */
        return (*qfn2(fn))(qenv(fn), v8, v7);
    }
}



/* Code for terminalp */

static Lisp_Object MS_CDECL CC_terminalp(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v8;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "terminalp");
    CSL_IGNORE(env);
/* end of prologue */
    v8 = qvalue(elt(env, 1)); /* !*int */
    if (v8 == nil) goto v9;
    v8 = qvalue(elt(env, 2)); /* ifl!* */
    v8 = (v8 == nil ? lisp_true : nil);
    return onevalue(v8);

v9:
    v8 = nil;
    return onevalue(v8);
}



/* Code for delcp */

static Lisp_Object CC_delcp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v7, v8;
    CSL_IGNORE(nil);
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v7 = v0;
/* end of prologue */
    v8 = elt(env, 1); /* delchar */
        return Lflagp(nil, v7, v8);
}



/* Code for argsofopr */

static Lisp_Object CC_argsofopr(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v7, v8;
    CSL_IGNORE(nil);
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v7 = v0;
/* end of prologue */
    v8 = elt(env, 1); /* number!-of!-args */
    return get(v7, v8);
}



/* Code for num!-exponents */

static Lisp_Object CC_numKexponents(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v10;
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
    v10 = stack[0];
    v10 = (consp(v10) ? nil : lisp_true);
    if (!(v10 == nil)) goto v12;
    v10 = stack[0];
    v10 = qcar(v10);
    v10 = (consp(v10) ? nil : lisp_true);
    goto v12;

v12:
    if (!(v10 == nil)) { popv(2); return onevalue(v10); }
    v10 = stack[0];
    v10 = qcar(v10);
    v10 = qcar(v10);
    v10 = qcdr(v10);
    v10 = integerp(v10);
    if (v10 == nil) goto v13;
    v10 = stack[0];
    v10 = qcar(v10);
    v10 = qcdr(v10);
    v10 = CC_numKexponents(env, v10);
    nil = C_nil;
    if (exception_pending()) goto v14;
    env = stack[-1];
    if (v10 == nil) goto v15;
    v10 = stack[0];
    v10 = qcdr(v10);
    stack[0] = v10;
    goto v11;

v15:
    v10 = nil;
    { popv(2); return onevalue(v10); }

v13:
    v10 = nil;
    { popv(2); return onevalue(v10); }
/* error exit handlers */
v14:
    popv(2);
    return nil;
}



/* Code for mchkopt */

static Lisp_Object CC_mchkopt(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v20, v21, v22, v23;
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
    v21 = v16;
    v22 = v0;
/* end of prologue */
    v20 = v21;
    v23 = qcar(v20);
    v20 = elt(env, 1); /* optional */
    v20 = get(v23, v20);
    env = stack[0];
    v23 = v20;
    v20 = v23;
    if (v20 == nil) goto v24;
    v20 = v22;
    v22 = v23;
    {
        popv(1);
        fn = elt(env, 2); /* mchkopt1 */
        return (*qfnn(fn))(qenv(fn), 3, v20, v21, v22);
    }

v24:
    v20 = nil;
    { popv(1); return onevalue(v20); }
}



/* Code for exchk */

static Lisp_Object CC_exchk(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v24, v26, v27, v28;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v24 = v0;
/* end of prologue */
    v28 = v24;
    v27 = nil;
    v26 = nil;
    v24 = nil;
    {
        fn = elt(env, 1); /* exchk1 */
        return (*qfnn(fn))(qenv(fn), 4, v28, v27, v26, v24);
    }
}



/* Code for !*ssave */

static Lisp_Object CC_Hssave(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v31, v32;
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
    v32 = v16;
    stack[-1] = v0;
/* end of prologue */
    v31 = qvalue(elt(env, 1)); /* !*uncached */
    if (!(v31 == nil)) goto v12;
    stack[-2] = qvalue(elt(env, 2)); /* alglist!* */
    stack[0] = v32;
    v32 = qvalue(elt(env, 3)); /* !*sub2 */
    v31 = stack[-1];
    v32 = cons(v32, v31);
    nil = C_nil;
    if (exception_pending()) goto v33;
    env = stack[-3];
    v31 = qvalue(elt(env, 2)); /* alglist!* */
    v31 = qcar(v31);
    v31 = acons(stack[0], v32, v31);
    nil = C_nil;
    if (exception_pending()) goto v33;
    env = stack[-3];
    v31 = Lrplaca(nil, stack[-2], v31);
    nil = C_nil;
    if (exception_pending()) goto v33;
    env = stack[-3];
    goto v12;

v12:
    v31 = qvalue(elt(env, 4)); /* simpcount!* */
    v31 = sub1(v31);
    nil = C_nil;
    if (exception_pending()) goto v33;
    env = stack[-3];
    qvalue(elt(env, 4)) = v31; /* simpcount!* */
    { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
/* error exit handlers */
v33:
    popv(4);
    return nil;
}



/* Code for noncomfp */

static Lisp_Object CC_noncomfp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v1, v2;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v2 = v0;
/* end of prologue */
    v1 = qvalue(elt(env, 1)); /* !*ncmp */
    if (v1 == nil) goto v3;
    v1 = v2;
    {
        fn = elt(env, 2); /* noncomfp1 */
        return (*qfn1(fn))(qenv(fn), v1);
    }

v3:
    v1 = nil;
    return onevalue(v1);
}



/* Code for !*d2q */

static Lisp_Object CC_Hd2q(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v39, v40;
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
    v39 = stack[0];
    if (is_number(v39)) goto v3;
    v39 = stack[0];
    fn = elt(env, 1); /* !:zerop */
    v39 = (*qfn1(fn))(qenv(fn), v39);
    nil = C_nil;
    if (exception_pending()) goto v41;
    if (v39 == nil) goto v42;
    v40 = nil;
    v39 = (Lisp_Object)17; /* 1 */
    popv(1);
    return cons(v40, v39);

v42:
    v40 = stack[0];
    v39 = (Lisp_Object)17; /* 1 */
    popv(1);
    return cons(v40, v39);

v3:
    v39 = stack[0];
    v39 = (Lisp_Object)zerop(v39);
    v39 = v39 ? lisp_true : nil;
    if (v39 == nil) goto v43;
    v40 = nil;
    v39 = (Lisp_Object)17; /* 1 */
    popv(1);
    return cons(v40, v39);

v43:
    v40 = stack[0];
    v39 = (Lisp_Object)17; /* 1 */
    popv(1);
    return cons(v40, v39);
/* error exit handlers */
v41:
    popv(1);
    return nil;
}



/* Code for getrtypeor */

static Lisp_Object CC_getrtypeor(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v28;
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
    v28 = stack[0];
    if (v28 == nil) goto v3;
    v28 = stack[0];
    v28 = qcar(v28);
    fn = elt(env, 1); /* getrtype */
    v28 = (*qfn1(fn))(qenv(fn), v28);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-1];
    if (!(v28 == nil)) { popv(2); return onevalue(v28); }
    v28 = stack[0];
    v28 = qcdr(v28);
    stack[0] = v28;
    goto v11;

v3:
    v28 = nil;
    { popv(2); return onevalue(v28); }
/* error exit handlers */
v44:
    popv(2);
    return nil;
}



/* Code for arraychk */

static Lisp_Object CC_arraychk(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v8;
    CSL_IGNORE(nil);
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v8 = v0;
/* end of prologue */
    if (v8 == nil) goto v3;
    v8 = nil;
    return onevalue(v8);

v3:
    v8 = elt(env, 1); /* array */
    return onevalue(v8);
}



/* Code for arrayp */

static Lisp_Object CC_arrayp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v26, v27;
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
    v26 = v0;
/* end of prologue */
    v27 = v26;
    v26 = elt(env, 1); /* rtype */
    v26 = get(v27, v26);
    env = stack[0];
    v27 = elt(env, 2); /* array */
    v26 = (v26 == v27 ? lisp_true : nil);
    { popv(1); return onevalue(v26); }
}



/* Code for noncomfp1 */

static Lisp_Object CC_noncomfp1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v21;
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
    v21 = stack[0];
    if (!consp(v21)) goto v3;
    v21 = stack[0];
    v21 = qcar(v21);
    if (!consp(v21)) goto v3;
    v21 = stack[0];
    v21 = qcar(v21);
    v21 = qcar(v21);
    v21 = qcar(v21);
    fn = elt(env, 1); /* noncomp */
    v21 = (*qfn1(fn))(qenv(fn), v21);
    nil = C_nil;
    if (exception_pending()) goto v23;
    env = stack[-1];
    if (!(v21 == nil)) { popv(2); return onevalue(v21); }
    v21 = stack[0];
    v21 = qcar(v21);
    v21 = qcdr(v21);
    v21 = CC_noncomfp1(env, v21);
    nil = C_nil;
    if (exception_pending()) goto v23;
    env = stack[-1];
    if (!(v21 == nil)) { popv(2); return onevalue(v21); }
    v21 = stack[0];
    v21 = qcdr(v21);
    stack[0] = v21;
    goto v11;

v3:
    v21 = nil;
    { popv(2); return onevalue(v21); }
/* error exit handlers */
v23:
    popv(2);
    return nil;
}



/* Code for noncomp1 */

static Lisp_Object CC_noncomp1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v46, v31, v32;
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
    v31 = v0;
/* end of prologue */
    v46 = v31;
    v46 = Lconsp(nil, v46);
    env = stack[0];
    if (v46 == nil) goto v3;
    v46 = v31;
    v46 = qcar(v46);
    v46 = Lconsp(nil, v46);
    env = stack[0];
    if (v46 == nil) goto v27;
    v46 = v31;
    {
        popv(1);
        fn = elt(env, 2); /* noncomfp */
        return (*qfn1(fn))(qenv(fn), v46);
    }

v27:
    v46 = v31;
    v32 = qcar(v46);
    v46 = elt(env, 1); /* taylor!* */
    if (v32 == v46) goto v24;
    v46 = v31;
    v46 = qcar(v46);
    if (!symbolp(v46)) v46 = nil;
    else { v46 = qfastgets(v46);
           if (v46 != nil) { v46 = elt(v46, 0); /* noncom */
#ifdef RECORD_GET
             if (v46 == SPID_NOPROP)
                record_get(elt(fastget_names, 0), 0),
                v46 = nil;
             else record_get(elt(fastget_names, 0), 1),
                v46 = lisp_true; }
           else record_get(elt(fastget_names, 0), 0); }
#else
             if (v46 == SPID_NOPROP) v46 = nil; else v46 = lisp_true; }}
#endif
    if (!(v46 == nil)) { popv(1); return onevalue(v46); }
    v46 = v31;
    v46 = qcdr(v46);
    {
        popv(1);
        fn = elt(env, 3); /* noncomlistp */
        return (*qfn1(fn))(qenv(fn), v46);
    }

v24:
    v46 = nil;
    { popv(1); return onevalue(v46); }

v3:
    v46 = nil;
    { popv(1); return onevalue(v46); }
}



/* Code for reval_without_mod */

static Lisp_Object CC_reval_without_mod(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v44, v47, v15;
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
    v15 = v0;
/* end of prologue */
    v47 = qvalue(elt(env, 1)); /* dmode!* */
    v44 = elt(env, 2); /* !:mod!: */
    if (v47 == v44) goto v3;
    v44 = v15;
    {
        popv(2);
        fn = elt(env, 3); /* reval */
        return (*qfn1(fn))(qenv(fn), v44);
    }

v3:
    v44 = nil;
    stack[0] = qvalue(elt(env, 1)); /* dmode!* */
    qvalue(elt(env, 1)) = v44; /* dmode!* */
    v44 = v15;
    fn = elt(env, 3); /* reval */
    v44 = (*qfn1(fn))(qenv(fn), v44);
    nil = C_nil;
    if (exception_pending()) goto v29;
    env = stack[-1];
    qvalue(elt(env, 1)) = stack[0]; /* dmode!* */
    { popv(2); return onevalue(v44); }
/* error exit handlers */
v29:
    env = stack[-1];
    qvalue(elt(env, 1)) = stack[0]; /* dmode!* */
    popv(2);
    return nil;
}



/* Code for getrtypecar */

static Lisp_Object CC_getrtypecar(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v4;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v4 = v0;
/* end of prologue */
    v4 = qcar(v4);
    {
        fn = elt(env, 1); /* getrtype */
        return (*qfn1(fn))(qenv(fn), v4);
    }
}



/* Code for addcomment */

static Lisp_Object CC_addcomment(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object v9;
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v9 = v0;
/* end of prologue */
    qvalue(elt(env, 1)) = v9; /* cursym!* */
    return onevalue(v9);
}



/* Code for prin2x */

static Lisp_Object CC_prin2x(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v7, v8;
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
    v7 = v0;
/* end of prologue */
    v8 = v7;
    v7 = qvalue(elt(env, 1)); /* outl!* */
    v7 = cons(v8, v7);
    nil = C_nil;
    if (exception_pending()) goto v1;
    env = stack[0];
    qvalue(elt(env, 1)) = v7; /* outl!* */
    { popv(1); return onevalue(v7); }
/* error exit handlers */
v1:
    popv(1);
    return nil;
}



/* Code for degr */

static Lisp_Object CC_degr(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v22, v23, v30;
    CSL_IGNORE(nil);
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v22 = v16;
    v23 = v0;
/* end of prologue */
    v30 = v23;
    if (!consp(v30)) goto v4;
    v30 = v23;
    v30 = qcar(v30);
    if (!consp(v30)) goto v4;
    v30 = v23;
    v30 = qcar(v30);
    v30 = qcar(v30);
    v30 = qcar(v30);
    if (!(v30 == v22)) goto v4;
    v22 = v23;
    v22 = qcar(v22);
    v22 = qcar(v22);
    v22 = qcdr(v22);
    return onevalue(v22);

v4:
    v22 = (Lisp_Object)1; /* 0 */
    return onevalue(v22);
}



/* Code for noncomlistp */

static Lisp_Object CC_noncomlistp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v38;
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
    v38 = stack[0];
    v38 = Lconsp(nil, v38);
    env = stack[-1];
    if (v38 == nil) goto v3;
    v38 = stack[0];
    v38 = qcar(v38);
    fn = elt(env, 1); /* noncomp1 */
    v38 = (*qfn1(fn))(qenv(fn), v38);
    nil = C_nil;
    if (exception_pending()) goto v47;
    env = stack[-1];
    if (!(v38 == nil)) { popv(2); return onevalue(v38); }
    v38 = stack[0];
    v38 = qcdr(v38);
    stack[0] = v38;
    goto v11;

v3:
    v38 = nil;
    { popv(2); return onevalue(v38); }
/* error exit handlers */
v47:
    popv(2);
    return nil;
}



/* Code for mchk!* */

static Lisp_Object CC_mchkH(Lisp_Object env,
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
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v16;
    stack[-1] = v0;
/* end of prologue */
    v33 = stack[-1];
    v48 = stack[0];
    fn = elt(env, 2); /* mchk */
    v48 = (*qfn2(fn))(qenv(fn), v33, v48);
    nil = C_nil;
    if (exception_pending()) goto v49;
    env = stack[-2];
    v33 = v48;
    if (!(v48 == nil)) { popv(3); return onevalue(v33); }
    v48 = qvalue(elt(env, 1)); /* !*mcd */
    if (!(v48 == nil)) goto v28;
    v48 = stack[-1];
    fn = elt(env, 3); /* sfp */
    v48 = (*qfn1(fn))(qenv(fn), v48);
    nil = C_nil;
    if (exception_pending()) goto v49;
    env = stack[-2];
    if (v48 == nil) goto v28;
    v48 = stack[0];
    fn = elt(env, 3); /* sfp */
    v48 = (*qfn1(fn))(qenv(fn), v48);
    nil = C_nil;
    if (exception_pending()) goto v49;
    env = stack[-2];
    if (v48 == nil) goto v28;
    v48 = stack[-1];
    fn = elt(env, 4); /* prepf */
    stack[-1] = (*qfn1(fn))(qenv(fn), v48);
    nil = C_nil;
    if (exception_pending()) goto v49;
    env = stack[-2];
    v48 = stack[0];
    fn = elt(env, 4); /* prepf */
    v48 = (*qfn1(fn))(qenv(fn), v48);
    nil = C_nil;
    if (exception_pending()) goto v49;
    env = stack[-2];
    {
        Lisp_Object v50 = stack[-1];
        popv(3);
        fn = elt(env, 2); /* mchk */
        return (*qfn2(fn))(qenv(fn), v50, v48);
    }

v28:
    v48 = nil;
    { popv(3); return onevalue(v48); }
/* error exit handlers */
v49:
    popv(3);
    return nil;
}



/* Code for ordop */

static Lisp_Object CC_ordop(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v51, v42, v49, v50, v52;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v50 = v16;
    v52 = v0;
/* end of prologue */
    v51 = qvalue(elt(env, 1)); /* kord!* */
    v49 = v51;
    goto v12;

v12:
    v51 = v49;
    if (v51 == nil) goto v25;
    v42 = v52;
    v51 = v49;
    v51 = qcar(v51);
    if (v42 == v51) goto v44;
    v42 = v50;
    v51 = v49;
    v51 = qcar(v51);
    if (v42 == v51) goto v23;
    v51 = v49;
    v51 = qcdr(v51);
    v49 = v51;
    goto v12;

v23:
    v51 = nil;
    return onevalue(v51);

v44:
    v51 = lisp_true;
    return onevalue(v51);

v25:
    v51 = v52;
    v42 = v50;
    {
        fn = elt(env, 2); /* ordp */
        return (*qfn2(fn))(qenv(fn), v51, v42);
    }
}



/* Code for smember */

static Lisp_Object CC_smember(Lisp_Object env,
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
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v16;
    stack[-1] = v0;
/* end of prologue */

v45:
    v48 = stack[-1];
    v36 = stack[0];
    if (equal(v48, v36)) goto v4;
    v36 = stack[0];
    if (!consp(v36)) goto v13;
    v48 = stack[-1];
    v36 = stack[0];
    v36 = qcar(v36);
    v36 = CC_smember(env, v48, v36);
    nil = C_nil;
    if (exception_pending()) goto v42;
    env = stack[-2];
    if (!(v36 == nil)) { popv(3); return onevalue(v36); }
    v48 = stack[-1];
    v36 = stack[0];
    v36 = qcdr(v36);
    stack[-1] = v48;
    stack[0] = v36;
    goto v45;

v13:
    v36 = nil;
    { popv(3); return onevalue(v36); }

v4:
    v36 = lisp_true;
    { popv(3); return onevalue(v36); }
/* error exit handlers */
v42:
    popv(3);
    return nil;
}



/* Code for timesip */

static Lisp_Object CC_timesip(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v17, v18, v19;
    CSL_IGNORE(nil);
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v19 = v0;
/* end of prologue */
    v18 = v19;
    v17 = elt(env, 1); /* times */
    if (!consp(v18)) goto v3;
    v18 = qcar(v18);
    if (!(v18 == v17)) goto v3;
    v17 = elt(env, 2); /* i */
    v18 = v19;
    v18 = qcdr(v18);
    v17 = Lmemq(nil, v17, v18);
    return onevalue(v17);

v3:
    v17 = nil;
    return onevalue(v17);
}



/* Code for expchk */

static Lisp_Object CC_expchk(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v1, v2;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v2 = v0;
/* end of prologue */
    v1 = qvalue(elt(env, 1)); /* !*exp */
    if (!(v1 == nil)) return onevalue(v2);
    v1 = v2;
    {
        fn = elt(env, 2); /* offexpchk */
        return (*qfn1(fn))(qenv(fn), v1);
    }
}



/* Code for readch1 */

static Lisp_Object MS_CDECL CC_readch1(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v50, v52;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "readch1");
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
    fn = elt(env, 5); /* terminalp */
    v50 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-1];
    if (v50 == nil) goto v12;
    v50 = qvalue(elt(env, 3)); /* crbuf1!* */
    if (v50 == nil) goto v53;
    v50 = qvalue(elt(env, 3)); /* crbuf1!* */
    v50 = qcar(v50);
    stack[0] = v50;
    v50 = qvalue(elt(env, 3)); /* crbuf1!* */
    v50 = qcdr(v50);
    qvalue(elt(env, 3)) = v50; /* crbuf1!* */
    goto v32;

v32:
    v52 = stack[0];
    v50 = qvalue(elt(env, 4)); /* crbuf!* */
    v50 = cons(v52, v50);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-1];
    qvalue(elt(env, 4)) = v50; /* crbuf!* */
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }

v53:
    v50 = Lreadch(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-1];
    stack[0] = v50;
    goto v32;

v12:
    v50 = Lreadch(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-1];
    stack[0] = v50;
    v52 = stack[0];
    v50 = qvalue(elt(env, 1)); /* !$eol!$ */
    if (!(v52 == v50)) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v50 = qvalue(elt(env, 2)); /* curline!* */
    v50 = add1(v50);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-1];
    qvalue(elt(env, 2)) = v50; /* curline!* */
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
/* error exit handlers */
v35:
    popv(2);
    return nil;
}



/* Code for !:zerop */

static Lisp_Object CC_Tzerop(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v31, v32, v37;
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
    v37 = v0;
/* end of prologue */
    v31 = v37;
    if (v31 == nil) goto v3;
    v32 = v37;
    v31 = (Lisp_Object)1; /* 0 */
    if (v32 == v31) goto v3;
    v31 = v37;
    if (!consp(v31)) goto v26;
    v31 = v37;
    v32 = qcar(v31);
    v31 = elt(env, 1); /* zerop */
    v31 = get(v32, v31);
    v32 = v37;
        return Lapply1(nil, v31, v32);

v26:
    v31 = nil;
    return onevalue(v31);

v3:
    v31 = lisp_true;
    return onevalue(v31);
}



/* Code for !*q2a1 */

static Lisp_Object CC_Hq2a1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v25, v13;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v25 = v16;
    v13 = v0;
/* end of prologue */
    if (v25 == nil) goto v4;
    v25 = v13;
    {
        fn = elt(env, 1); /* prepsqxx */
        return (*qfn1(fn))(qenv(fn), v25);
    }

v4:
    v25 = v13;
    {
        fn = elt(env, 2); /* mk!*sq */
        return (*qfn1(fn))(qenv(fn), v25);
    }
}



/* Code for multd */

static Lisp_Object CC_multd(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v59, v60;
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
    v59 = stack[-1];
    if (v59 == nil) goto v6;
    v60 = stack[-1];
    v59 = (Lisp_Object)17; /* 1 */
    if (v60 == v59) goto v43;
    v59 = stack[-1];
    if (!consp(v59)) goto v31;
    v59 = stack[-1];
    v59 = qcar(v59);
    if (!consp(v59)) goto v31;
    v59 = stack[-1];
    v59 = qcar(v59);
    stack[0] = qcar(v59);
    v60 = stack[-2];
    v59 = stack[-1];
    v59 = qcar(v59);
    v59 = qcdr(v59);
    v60 = CC_multd(env, v60, v59);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[-4];
    v59 = stack[-3];
    v59 = acons(stack[0], v60, v59);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[-4];
    stack[-3] = v59;
    v59 = stack[-1];
    v59 = qcdr(v59);
    stack[-1] = v59;
    goto v12;

v31:
    stack[0] = stack[-3];
    v60 = stack[-2];
    v59 = stack[-1];
    fn = elt(env, 1); /* multdm */
    v59 = (*qfn2(fn))(qenv(fn), v60, v59);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[-4];
    {
        Lisp_Object v62 = stack[0];
        popv(5);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v62, v59);
    }

v43:
    v60 = stack[-3];
    v59 = stack[-2];
    {
        popv(5);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v60, v59);
    }

v6:
    v59 = stack[-3];
    {
        popv(5);
        fn = elt(env, 2); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v59);
    }
/* error exit handlers */
v61:
    popv(5);
    return nil;
}



/* Code for subs2f */

static Lisp_Object CC_subs2f(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v58, v55, v65;
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
    v55 = qvalue(elt(env, 1)); /* simpcount!* */
    v58 = qvalue(elt(env, 2)); /* simplimit!* */
    v58 = (Lisp_Object)greaterp2(v55, v58);
    nil = C_nil;
    if (exception_pending()) goto v60;
    v58 = v58 ? lisp_true : nil;
    env = stack[-2];
    if (v58 == nil) goto v12;
    v58 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 1)) = v58; /* simpcount!* */
    v65 = elt(env, 3); /* poly */
    v55 = (Lisp_Object)337; /* 21 */
    v58 = elt(env, 4); /* "Simplification recursion too deep" */
    fn = elt(env, 8); /* rerror */
    v58 = (*qfnn(fn))(qenv(fn), 3, v65, v55, v58);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-2];
    goto v12;

v12:
    v58 = qvalue(elt(env, 1)); /* simpcount!* */
    v58 = add1(v58);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-2];
    qvalue(elt(env, 1)) = v58; /* simpcount!* */
    v58 = nil;
    qvalue(elt(env, 5)) = v58; /* !*sub2 */
    v58 = stack[0];
    fn = elt(env, 9); /* subs2f1 */
    v58 = (*qfn1(fn))(qenv(fn), v58);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-2];
    stack[-1] = v58;
    v58 = qvalue(elt(env, 5)); /* !*sub2 */
    if (!(v58 == nil)) goto v46;
    v58 = qvalue(elt(env, 6)); /* powlis1!* */
    if (!(v58 == nil)) goto v46;

v10:
    v58 = qvalue(elt(env, 1)); /* simpcount!* */
    v58 = sub1(v58);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-2];
    qvalue(elt(env, 1)) = v58; /* simpcount!* */
    { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }

v46:
    v58 = qvalue(elt(env, 7)); /* !*resubs */
    if (v58 == nil) goto v10;
    v58 = stack[-1];
    v55 = qcar(v58);
    v58 = stack[0];
    if (!(equal(v55, v58))) goto v66;
    v58 = stack[-1];
    v55 = qcdr(v58);
    v58 = (Lisp_Object)17; /* 1 */
    if (!(v55 == v58)) goto v66;
    v58 = nil;
    qvalue(elt(env, 5)) = v58; /* !*sub2 */
    goto v10;

v66:
    v58 = stack[-1];
    fn = elt(env, 10); /* subs2q */
    v58 = (*qfn1(fn))(qenv(fn), v58);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-2];
    stack[-1] = v58;
    goto v10;
/* error exit handlers */
v60:
    popv(3);
    return nil;
}



/* Code for aeval!* */

static Lisp_Object CC_aevalH(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v13, v24;
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
    stack[-1] = qvalue(elt(env, 1)); /* alglist!* */
    qvalue(elt(env, 1)) = nil; /* alglist!* */
    v13 = nil;
    v13 = ncons(v13);
    nil = C_nil;
    if (exception_pending()) goto v28;
    env = stack[-2];
    qvalue(elt(env, 1)) = v13; /* alglist!* */
    v24 = stack[0];
    v13 = nil;
    fn = elt(env, 2); /* reval1 */
    v13 = (*qfn2(fn))(qenv(fn), v24, v13);
    nil = C_nil;
    if (exception_pending()) goto v28;
    env = stack[-2];
    qvalue(elt(env, 1)) = stack[-1]; /* alglist!* */
    { popv(3); return onevalue(v13); }
/* error exit handlers */
v28:
    env = stack[-2];
    qvalue(elt(env, 1)) = stack[-1]; /* alglist!* */
    popv(3);
    return nil;
}



/* Code for hevenp */

static Lisp_Object CC_hevenp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v8, v1;
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
    v1 = v0;
/* end of prologue */
    v8 = v1;
    v8 = (v8 == nil ? lisp_true : nil);
    if (!(v8 == nil)) return onevalue(v8);
    v8 = v1;
    v8 = qcdr(v8);
    v8 = CC_hevenp(env, v8);
    errexit();
    v8 = (v8 == nil ? lisp_true : nil);
    return onevalue(v8);
}



/* Code for aconc */

static Lisp_Object CC_aconc(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v1, v2;
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
    v1 = v16;
    v2 = v0;
/* end of prologue */
    stack[0] = v2;
    v1 = ncons(v1);
    nil = C_nil;
    if (exception_pending()) goto v13;
    {
        Lisp_Object v24 = stack[0];
        popv(1);
        return Lnconc(nil, v24, v1);
    }
/* error exit handlers */
v13:
    popv(1);
    return nil;
}



/* Code for add_prin_char */

static Lisp_Object CC_add_prin_char(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v66, v70, v71;
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
    v66 = qvalue(elt(env, 1)); /* !*nat */
    if (v66 == nil) goto v4;
    v71 = qvalue(elt(env, 3)); /* posn!* */
    v70 = stack[0];
    v66 = qvalue(elt(env, 4)); /* ycoord!* */
    v71 = acons(v71, v70, v66);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-2];
    v70 = stack[-1];
    v66 = qvalue(elt(env, 5)); /* pline!* */
    v66 = acons(v71, v70, v66);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-2];
    qvalue(elt(env, 5)) = v66; /* pline!* */
    v66 = stack[0];
    qvalue(elt(env, 3)) = v66; /* posn!* */
    { popv(3); return onevalue(v66); }

v4:
    v66 = stack[-1];
    v66 = Lstringp(nil, v66);
    env = stack[-2];
    if (!(v66 == nil)) goto v7;
    v70 = stack[-1];
    v66 = elt(env, 2); /* switch!* */
    v66 = get(v70, v66);
    env = stack[-2];
    if (!(v66 == nil)) goto v7;
    v66 = stack[-1];
    v66 = Ldigitp(nil, v66);
    env = stack[-2];
    if (!(v66 == nil)) goto v7;
    v66 = stack[-1];
    v66 = Lexplodec(nil, v66);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-2];
    v70 = qcar(v66);
    v66 = elt(env, 2); /* switch!* */
    v66 = get(v70, v66);
    if (!(v66 == nil)) goto v7;
    v66 = stack[-1];
        popv(3);
        return Lprin(nil, v66);

v7:
    v66 = stack[-1];
        popv(3);
        return Lprinc(nil, v66);
/* error exit handlers */
v72:
    popv(3);
    return nil;
}



/* Code for mkvar */

static Lisp_Object CC_mkvar(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object v3, v4;
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v3 = v16;
    v4 = v0;
/* end of prologue */
    return onevalue(v4);
}



/* Code for getrtype */

static Lisp_Object CC_getrtype(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v88, v89, v90;
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
    v88 = stack[0];
    if (v88 == nil) goto v5;
    v88 = stack[0];
    if (!consp(v88)) goto v1;
    v88 = stack[0];
    v88 = qcar(v88);
    if (symbolp(v88)) goto v91;
    v88 = nil;
    { popv(2); return onevalue(v88); }

v91:
    v88 = stack[0];
    v89 = qcar(v88);
    v88 = elt(env, 2); /* avalue */
    v88 = get(v89, v88);
    env = stack[-1];
    v90 = v88;
    if (v88 == nil) goto v92;
    v88 = v90;
    v89 = qcar(v88);
    v88 = elt(env, 5); /* rtypefn */
    v88 = get(v89, v88);
    env = stack[-1];
    v90 = v88;
    if (v88 == nil) goto v92;
    v89 = v90;
    v88 = stack[0];
    v88 = qcdr(v88);
        popv(2);
        return Lapply1(nil, v89, v88);

v92:
    v88 = stack[0];
    v89 = qcar(v88);
    v88 = elt(env, 6); /* sub */
    if (v89 == v88) goto v93;
    v88 = stack[0];
    {
        popv(2);
        fn = elt(env, 8); /* getrtype2 */
        return (*qfn1(fn))(qenv(fn), v88);
    }

v93:
    v88 = elt(env, 7); /* yetunknowntype */
    { popv(2); return onevalue(v88); }

v1:
    v88 = stack[0];
    if (symbolp(v88)) goto v30;
    v88 = stack[0];
    if (is_number(v88)) goto v47;
    v88 = stack[0];
    {
        popv(2);
        fn = elt(env, 9); /* getrtype1 */
        return (*qfn1(fn))(qenv(fn), v88);
    }

v47:
    v88 = nil;
    { popv(2); return onevalue(v88); }

v30:
    v89 = stack[0];
    v88 = elt(env, 1); /* share */
    v88 = Lflagp(nil, v89, v88);
    env = stack[-1];
    if (v88 == nil) goto v69;
    v88 = stack[0];
    fn = elt(env, 10); /* eval */
    v89 = (*qfn1(fn))(qenv(fn), v88);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-1];
    v90 = v89;
    v88 = stack[0];
    if (v89 == v88) goto v36;
    v88 = v90;
    stack[0] = v88;
    goto v11;

v36:
    v88 = nil;
    { popv(2); return onevalue(v88); }

v69:
    v89 = stack[0];
    v88 = elt(env, 2); /* avalue */
    v88 = get(v89, v88);
    env = stack[-1];
    v90 = v88;
    if (v88 == nil) goto v95;
    v88 = v90;
    v89 = qcar(v88);
    v88 = elt(env, 3); /* (scalar generic) */
    v88 = Lmemq(nil, v89, v88);
    if (!(v88 == nil)) goto v95;

v96:
    v88 = v90;
    v89 = qcar(v88);
    v88 = elt(env, 5); /* rtypefn */
    v88 = get(v89, v88);
    v89 = v88;
    if (v88 == nil) goto v97;
    v88 = nil;
        popv(2);
        return Lapply1(nil, v89, v88);

v97:
    v88 = v90;
    v88 = qcar(v88);
    { popv(2); return onevalue(v88); }

v95:
    v89 = stack[0];
    v88 = elt(env, 4); /* rtype */
    v88 = get(v89, v88);
    env = stack[-1];
    v90 = v88;
    if (v88 == nil) goto v98;
    v88 = v90;
    v88 = ncons(v88);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-1];
    v90 = v88;
    if (!(v88 == nil)) goto v96;

v98:
    v88 = nil;
    { popv(2); return onevalue(v88); }

v5:
    v88 = nil;
    { popv(2); return onevalue(v88); }
/* error exit handlers */
v94:
    popv(2);
    return nil;
}



/* Code for noncomdel */

static Lisp_Object CC_noncomdel(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v18, v19;
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
    v18 = stack[-1];
    fn = elt(env, 1); /* noncomp!* */
    v18 = (*qfn1(fn))(qenv(fn), v18);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-2];
    if (v18 == nil) goto v7;
    v19 = stack[-1];
    v18 = stack[0];
    {
        popv(3);
        fn = elt(env, 2); /* noncomdel1 */
        return (*qfn2(fn))(qenv(fn), v19, v18);
    }

v7:
    v19 = stack[-1];
    v18 = stack[0];
        popv(3);
        return Ldelete(nil, v19, v18);
/* error exit handlers */
v22:
    popv(3);
    return nil;
}



/* Code for subs2q */

static Lisp_Object CC_subs2q(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v56, v54, v87, v66;
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
    v56 = stack[-2];
    v54 = qcar(v56);
    v56 = stack[-2];
    v56 = qcdr(v56);
    stack[-3] = v54;
    stack[-1] = v56;
    v56 = stack[-3];
    fn = elt(env, 1); /* subs2f */
    stack[0] = (*qfn1(fn))(qenv(fn), v56);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-4];
    v56 = stack[-1];
    fn = elt(env, 1); /* subs2f */
    v56 = (*qfn1(fn))(qenv(fn), v56);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-4];
    v66 = stack[0];
    v87 = v56;
    v56 = v66;
    v54 = qcdr(v56);
    v56 = (Lisp_Object)17; /* 1 */
    if (!(v54 == v56)) goto v100;
    v56 = v87;
    v54 = qcdr(v56);
    v56 = (Lisp_Object)17; /* 1 */
    if (!(v54 == v56)) goto v100;
    v56 = v66;
    v54 = qcar(v56);
    v56 = stack[-3];
    if (!(equal(v54, v56))) goto v100;
    v56 = v87;
    v54 = qcar(v56);
    v56 = stack[-1];
    if (equal(v54, v56)) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    else goto v100;

v100:
    v56 = v66;
    v54 = v87;
    {
        popv(5);
        fn = elt(env, 2); /* quotsq */
        return (*qfn2(fn))(qenv(fn), v56, v54);
    }
/* error exit handlers */
v72:
    popv(5);
    return nil;
}



/* Code for prepf1 */

static Lisp_Object CC_prepf1(Lisp_Object env,
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
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v16;
    stack[-1] = v0;
/* end of prologue */
    v102 = stack[-1];
    if (v102 == nil) goto v4;
    v102 = stack[-1];
    if (!consp(v102)) goto v28;
    v102 = stack[-1];
    v102 = qcar(v102);
    if (!consp(v102)) goto v28;
    v102 = stack[-1];
    v102 = qcar(v102);
    stack[-2] = qcdr(v102);
    v102 = stack[-1];
    v102 = qcar(v102);
    v102 = qcar(v102);
    v95 = qcar(v102);
    v102 = elt(env, 1); /* k!* */
    if (v95 == v102) goto v49;
    v102 = stack[-1];
    v102 = qcar(v102);
    v95 = qcar(v102);
    v102 = stack[0];
    v102 = cons(v95, v102);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-3];
    goto v32;

v32:
    stack[-2] = CC_prepf1(env, stack[-2], v102);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-3];
    v102 = stack[-1];
    v95 = qcdr(v102);
    v102 = stack[0];
    v102 = CC_prepf1(env, v95, v102);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-3];
    {
        Lisp_Object v85 = stack[-2];
        popv(4);
        fn = elt(env, 2); /* nconc!* */
        return (*qfn2(fn))(qenv(fn), v85, v102);
    }

v49:
    v102 = stack[0];
    goto v32;

v28:
    v102 = stack[-1];
    fn = elt(env, 3); /* prepd */
    stack[-1] = (*qfn1(fn))(qenv(fn), v102);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-3];
    v102 = stack[0];
    fn = elt(env, 4); /* exchk */
    v102 = (*qfn1(fn))(qenv(fn), v102);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-3];
    v102 = cons(stack[-1], v102);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-3];
    fn = elt(env, 5); /* retimes */
    v102 = (*qfn1(fn))(qenv(fn), v102);
    nil = C_nil;
    if (exception_pending()) goto v62;
    popv(4);
    return ncons(v102);

v4:
    v102 = nil;
    { popv(4); return onevalue(v102); }
/* error exit handlers */
v62:
    popv(4);
    return nil;
}



/* Code for negnumberchk */

static Lisp_Object CC_negnumberchk(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v17, v18, v19;
    CSL_IGNORE(nil);
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v18 = v0;
/* end of prologue */
    v17 = v18;
    v19 = elt(env, 1); /* minus */
    if (!consp(v17)) return onevalue(v18);
    v17 = qcar(v17);
    if (!(v17 == v19)) return onevalue(v18);
    v17 = v18;
    v17 = qcdr(v17);
    v17 = qcar(v17);
    if (!(is_number(v17))) return onevalue(v18);
    v17 = v18;
    v17 = qcdr(v17);
    v17 = qcar(v17);
    return negate(v17);
}



/* Code for prepf */

static Lisp_Object CC_prepf(Lisp_Object env,
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
    v47 = v44;
    v44 = nil;
    fn = elt(env, 1); /* prepf1 */
    v44 = (*qfn2(fn))(qenv(fn), v47, v44);
    nil = C_nil;
    if (exception_pending()) goto v15;
    env = stack[0];
    v47 = v44;
    v44 = v47;
    if (v44 == nil) goto v2;
    v44 = v47;
    {
        popv(1);
        fn = elt(env, 2); /* replus */
        return (*qfn1(fn))(qenv(fn), v44);
    }

v2:
    v44 = (Lisp_Object)1; /* 0 */
    { popv(1); return onevalue(v44); }
/* error exit handlers */
v15:
    popv(1);
    return nil;
}



/* Code for noncomp!* */

static Lisp_Object CC_noncompH(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v17, v18;
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
    v17 = stack[0];
    fn = elt(env, 2); /* noncomp */
    v17 = (*qfn1(fn))(qenv(fn), v17);
    nil = C_nil;
    if (exception_pending()) goto v20;
    env = stack[-1];
    if (!(v17 == nil)) { popv(2); return onevalue(v17); }
    v18 = stack[0];
    v17 = elt(env, 1); /* expt */
    if (!consp(v18)) goto v6;
    v18 = qcar(v18);
    if (!(v18 == v17)) goto v6;
    v17 = stack[0];
    v17 = qcdr(v17);
    v17 = qcar(v17);
    {
        popv(2);
        fn = elt(env, 2); /* noncomp */
        return (*qfn1(fn))(qenv(fn), v17);
    }

v6:
    v17 = nil;
    { popv(2); return onevalue(v17); }
/* error exit handlers */
v20:
    popv(2);
    return nil;
}



/* Code for getrtype2 */

static Lisp_Object CC_getrtype2(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v85, v86, v104;
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
    v86 = v0;
/* end of prologue */
    v85 = v86;
    v104 = qcar(v85);
    v85 = elt(env, 1); /* rtype */
    v85 = get(v104, v85);
    env = stack[0];
    v104 = v85;
    if (v85 == nil) goto v32;
    v85 = elt(env, 2); /* rtypefn */
    v85 = get(v104, v85);
    env = stack[0];
    v104 = v85;
    if (v85 == nil) goto v32;
    v85 = v104;
    v86 = qcdr(v86);
        popv(1);
        return Lapply1(nil, v85, v86);

v32:
    v85 = v86;
    v104 = qcar(v85);
    v85 = elt(env, 2); /* rtypefn */
    v85 = get(v104, v85);
    env = stack[0];
    v104 = v85;
    if (v85 == nil) goto v105;
    v85 = v104;
    v86 = qcdr(v86);
        popv(1);
        return Lapply1(nil, v85, v86);

v105:
    v85 = v86;
    v104 = qcar(v85);
    v85 = elt(env, 3); /* matmapfn */
    v85 = Lflagp(nil, v104, v85);
    env = stack[0];
    if (v85 == nil) goto v106;
    v85 = v86;
    v85 = qcdr(v85);
    if (v85 == nil) goto v106;
    v85 = v86;
    v85 = qcdr(v85);
    v85 = qcar(v85);
    fn = elt(env, 5); /* getrtype */
    v86 = (*qfn1(fn))(qenv(fn), v85);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[0];
    v85 = elt(env, 4); /* matrix */
    if (!(v86 == v85)) goto v106;
    v85 = elt(env, 4); /* matrix */
    { popv(1); return onevalue(v85); }

v106:
    v85 = nil;
    { popv(1); return onevalue(v85); }
/* error exit handlers */
v107:
    popv(1);
    return nil;
}



/* Code for addf */

static Lisp_Object CC_addf(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v123, v124, v125;
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
    v123 = stack[-2];
    if (v123 == nil) goto v2;
    v123 = stack[-1];
    if (v123 == nil) goto v43;
    v123 = stack[-2];
    if (!consp(v123)) goto v42;
    v123 = stack[-2];
    v123 = qcar(v123);
    if (!consp(v123)) goto v42;
    v123 = stack[-1];
    if (!consp(v123)) goto v66;
    v123 = stack[-1];
    v123 = qcar(v123);
    if (!consp(v123)) goto v66;
    v123 = stack[-2];
    v123 = qcar(v123);
    v124 = qcar(v123);
    v123 = stack[-1];
    v123 = qcar(v123);
    v123 = qcar(v123);
    if (equal(v124, v123)) goto v104;
    v123 = stack[-2];
    v123 = qcar(v123);
    v124 = qcar(v123);
    v123 = stack[-1];
    v123 = qcar(v123);
    v123 = qcar(v123);
    fn = elt(env, 1); /* ordpp */
    v123 = (*qfn2(fn))(qenv(fn), v124, v123);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-4];
    if (v123 == nil) goto v127;
    v123 = stack[-2];
    v124 = qcar(v123);
    v123 = stack[0];
    v123 = cons(v124, v123);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-4];
    stack[0] = v123;
    v123 = stack[-2];
    v123 = qcdr(v123);
    stack[-2] = v123;
    goto v12;

v127:
    v123 = stack[-1];
    v124 = qcar(v123);
    v123 = stack[0];
    v123 = cons(v124, v123);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-4];
    stack[0] = v123;
    v123 = stack[-1];
    v123 = qcdr(v123);
    stack[-1] = v123;
    goto v12;

v104:
    stack[-3] = stack[0];
    v123 = stack[-2];
    v123 = qcar(v123);
    v124 = qcdr(v123);
    v123 = stack[-1];
    v123 = qcar(v123);
    v123 = qcdr(v123);
    stack[0] = CC_addf(env, v124, v123);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-4];
    v123 = stack[-2];
    v124 = qcdr(v123);
    v123 = stack[-1];
    v123 = qcdr(v123);
    v123 = CC_addf(env, v124, v123);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-4];
    v124 = stack[0];
    v125 = v124;
    if (v125 == nil) goto v128;
    v125 = stack[-2];
    v125 = qcar(v125);
    v125 = qcar(v125);
    v123 = acons(v125, v124, v123);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-4];
    goto v128;

v128:
    {
        Lisp_Object v129 = stack[-3];
        popv(5);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v129, v123);
    }

v66:
    v124 = stack[-1];
    v123 = stack[-2];
    fn = elt(env, 3); /* addd */
    v123 = (*qfn2(fn))(qenv(fn), v124, v123);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-4];
    {
        Lisp_Object v130 = stack[0];
        popv(5);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v130, v123);
    }

v42:
    v124 = stack[-2];
    v123 = stack[-1];
    fn = elt(env, 3); /* addd */
    v123 = (*qfn2(fn))(qenv(fn), v124, v123);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-4];
    {
        Lisp_Object v131 = stack[0];
        popv(5);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v131, v123);
    }

v43:
    v124 = stack[0];
    v123 = stack[-2];
    {
        popv(5);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v124, v123);
    }

v2:
    v124 = stack[0];
    v123 = stack[-1];
    {
        popv(5);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v124, v123);
    }
/* error exit handlers */
v126:
    popv(5);
    return nil;
}



/* Code for multsq */

static Lisp_Object CC_multsq(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v147, v148;
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
    v147 = stack[-3];
    v147 = qcar(v147);
    if (v147 == nil) goto v25;
    v147 = stack[-2];
    v147 = qcar(v147);
    if (v147 == nil) goto v25;
    v147 = stack[-3];
    v148 = qcdr(v147);
    v147 = (Lisp_Object)17; /* 1 */
    if (!(v148 == v147)) goto v54;
    v147 = stack[-2];
    v148 = qcdr(v147);
    v147 = (Lisp_Object)17; /* 1 */
    if (!(v148 == v147)) goto v54;
    v147 = stack[-3];
    v148 = qcar(v147);
    v147 = stack[-2];
    v147 = qcar(v147);
    fn = elt(env, 1); /* multf */
    v148 = (*qfn2(fn))(qenv(fn), v148, v147);
    nil = C_nil;
    if (exception_pending()) goto v149;
    v147 = (Lisp_Object)17; /* 1 */
    popv(6);
    return cons(v148, v147);

v54:
    v147 = stack[-3];
    v148 = qcar(v147);
    v147 = stack[-2];
    v147 = qcdr(v147);
    fn = elt(env, 2); /* gcdf */
    v147 = (*qfn2(fn))(qenv(fn), v148, v147);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-5];
    stack[-4] = v147;
    v147 = stack[-2];
    v148 = qcar(v147);
    v147 = stack[-3];
    v147 = qcdr(v147);
    fn = elt(env, 2); /* gcdf */
    v147 = (*qfn2(fn))(qenv(fn), v148, v147);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-5];
    stack[-1] = v147;
    v147 = stack[-3];
    v148 = qcar(v147);
    v147 = stack[-4];
    fn = elt(env, 3); /* quotf */
    stack[0] = (*qfn2(fn))(qenv(fn), v148, v147);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-5];
    v147 = stack[-2];
    v148 = qcar(v147);
    v147 = stack[-1];
    fn = elt(env, 3); /* quotf */
    v147 = (*qfn2(fn))(qenv(fn), v148, v147);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-5];
    fn = elt(env, 1); /* multf */
    v147 = (*qfn2(fn))(qenv(fn), stack[0], v147);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-5];
    stack[0] = v147;
    v147 = stack[-3];
    v148 = qcdr(v147);
    v147 = stack[-1];
    fn = elt(env, 3); /* quotf */
    stack[-1] = (*qfn2(fn))(qenv(fn), v148, v147);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-5];
    v147 = stack[-2];
    v148 = qcdr(v147);
    v147 = stack[-4];
    fn = elt(env, 3); /* quotf */
    v147 = (*qfn2(fn))(qenv(fn), v148, v147);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-5];
    fn = elt(env, 1); /* multf */
    v147 = (*qfn2(fn))(qenv(fn), stack[-1], v147);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-5];
    stack[-4] = v147;
    v148 = stack[0];
    v147 = stack[-4];
    v147 = cons(v148, v147);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-5];
    {
        popv(6);
        fn = elt(env, 4); /* canonsq */
        return (*qfn1(fn))(qenv(fn), v147);
    }

v25:
    v148 = nil;
    v147 = (Lisp_Object)17; /* 1 */
    popv(6);
    return cons(v148, v147);
/* error exit handlers */
v149:
    popv(6);
    return nil;
}



/* Code for getel1 */

static Lisp_Object MS_CDECL CC_getel1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v16,
                         Lisp_Object v63, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v55, v65, v103;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "getel1");
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
    v55 = stack[-1];
    if (v55 == nil) { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
    v55 = stack[-1];
    v55 = qcar(v55);
    v55 = integerp(v55);
    if (v55 == nil) goto v28;
    v55 = stack[-1];
    v65 = qcar(v55);
    v55 = stack[0];
    v55 = qcar(v55);
    v55 = (Lisp_Object)geq2(v65, v55);
    nil = C_nil;
    if (exception_pending()) goto v95;
    v55 = v55 ? lisp_true : nil;
    env = stack[-3];
    if (!(v55 == nil)) goto v35;
    v55 = stack[-1];
    v65 = qcar(v55);
    v55 = (Lisp_Object)1; /* 0 */
    v55 = (Lisp_Object)lessp2(v65, v55);
    nil = C_nil;
    if (exception_pending()) goto v95;
    v55 = v55 ? lisp_true : nil;
    env = stack[-3];
    if (!(v55 == nil)) goto v35;
    v65 = stack[-2];
    v55 = stack[-1];
    v55 = qcar(v55);
    v55 = *(Lisp_Object *)((char *)v65 + (CELL-TAG_VECTOR) + ((int32_t)v55/(16/CELL)));
    stack[-2] = v55;
    v55 = stack[-1];
    v55 = qcdr(v55);
    stack[-1] = v55;
    v55 = stack[0];
    v55 = qcdr(v55);
    stack[0] = v55;
    goto v12;

v35:
    v103 = elt(env, 2); /* rlisp */
    v65 = (Lisp_Object)337; /* 21 */
    v55 = elt(env, 3); /* "Array out of bounds" */
    {
        popv(4);
        fn = elt(env, 4); /* rerror */
        return (*qfnn(fn))(qenv(fn), 3, v103, v65, v55);
    }

v28:
    v55 = stack[-1];
    v65 = qcar(v55);
    v55 = elt(env, 1); /* "array index" */
    {
        popv(4);
        fn = elt(env, 5); /* typerr */
        return (*qfn2(fn))(qenv(fn), v65, v55);
    }
/* error exit handlers */
v95:
    popv(4);
    return nil;
}



/* Code for multf */

static Lisp_Object CC_multf(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v194, v195, v196;
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
    goto v45;

v45:
    v194 = stack[-2];
    if (v194 == nil) goto v7;
    v194 = stack[-1];
    if (v194 == nil) goto v7;
    v195 = stack[-2];
    v194 = (Lisp_Object)17; /* 1 */
    if (v195 == v194) { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }
    v195 = stack[-1];
    v194 = (Lisp_Object)17; /* 1 */
    if (v195 == v194) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v194 = stack[-2];
    if (!consp(v194)) goto v51;
    v194 = stack[-2];
    v194 = qcar(v194);
    if (!consp(v194)) goto v51;
    v194 = stack[-1];
    if (!consp(v194)) goto v134;
    v194 = stack[-1];
    v194 = qcar(v194);
    if (!consp(v194)) goto v134;
    v194 = qvalue(elt(env, 1)); /* !*exp */
    if (!(v194 == nil)) goto v6;
    v194 = qvalue(elt(env, 2)); /* ncmp!* */
    if (!(v194 == nil)) goto v6;
    v194 = qvalue(elt(env, 3)); /* wtl!* */
    if (!(v194 == nil)) goto v6;
    v194 = stack[-3];
    if (!(v194 == nil)) goto v6;
    v194 = stack[-2];
    fn = elt(env, 8); /* mkprod */
    v194 = (*qfn1(fn))(qenv(fn), v194);
    nil = C_nil;
    if (exception_pending()) goto v197;
    env = stack[-4];
    stack[-2] = v194;
    v194 = stack[-1];
    fn = elt(env, 8); /* mkprod */
    v194 = (*qfn1(fn))(qenv(fn), v194);
    nil = C_nil;
    if (exception_pending()) goto v197;
    env = stack[-4];
    stack[-1] = v194;
    v194 = lisp_true;
    stack[-3] = v194;
    goto v45;

v6:
    v194 = stack[-2];
    v194 = qcar(v194);
    v194 = qcar(v194);
    v194 = qcar(v194);
    stack[-3] = v194;
    v194 = stack[-1];
    v194 = qcar(v194);
    v194 = qcar(v194);
    v194 = qcar(v194);
    stack[0] = v194;
    v194 = stack[-1];
    fn = elt(env, 9); /* noncomfp */
    v194 = (*qfn1(fn))(qenv(fn), v194);
    nil = C_nil;
    if (exception_pending()) goto v197;
    env = stack[-4];
    if (v194 == nil) goto v97;
    v194 = stack[-3];
    fn = elt(env, 10); /* noncomp */
    v194 = (*qfn1(fn))(qenv(fn), v194);
    nil = C_nil;
    if (exception_pending()) goto v197;
    env = stack[-4];
    if (!(v194 == nil)) goto v84;
    v194 = qvalue(elt(env, 4)); /* !*!*processed */
    if (!(v194 == nil)) goto v97;

v84:
    v195 = stack[-2];
    v194 = stack[-1];
    {
        popv(5);
        fn = elt(env, 11); /* multfnc */
        return (*qfn2(fn))(qenv(fn), v195, v194);
    }

v97:
    v195 = stack[-3];
    v194 = stack[0];
    if (v195 == v194) goto v82;
    v195 = stack[-3];
    v194 = stack[0];
    fn = elt(env, 12); /* ordop */
    v194 = (*qfn2(fn))(qenv(fn), v195, v194);
    nil = C_nil;
    if (exception_pending()) goto v197;
    env = stack[-4];
    if (v194 == nil) goto v198;
    v194 = stack[-2];
    v194 = qcar(v194);
    v195 = qcdr(v194);
    v194 = stack[-1];
    v194 = CC_multf(env, v195, v194);
    nil = C_nil;
    if (exception_pending()) goto v197;
    env = stack[-4];
    stack[-3] = v194;
    v194 = stack[-2];
    v195 = qcdr(v194);
    v194 = stack[-1];
    v194 = CC_multf(env, v195, v194);
    nil = C_nil;
    if (exception_pending()) goto v197;
    stack[0] = v194;
    v194 = stack[-3];
    if (v194 == nil) { Lisp_Object res = stack[0]; popv(5); return onevalue(res); }
    v194 = stack[-2];
    v194 = qcar(v194);
    v196 = qcar(v194);
    v195 = stack[-3];
    v194 = stack[0];
    popv(5);
    return acons(v196, v195, v194);

v198:
    v195 = stack[-2];
    v194 = stack[-1];
    v194 = qcar(v194);
    v194 = qcdr(v194);
    v194 = CC_multf(env, v195, v194);
    nil = C_nil;
    if (exception_pending()) goto v197;
    env = stack[-4];
    stack[-3] = v194;
    v195 = stack[-2];
    v194 = stack[-1];
    v194 = qcdr(v194);
    v194 = CC_multf(env, v195, v194);
    nil = C_nil;
    if (exception_pending()) goto v197;
    stack[0] = v194;
    v194 = stack[-3];
    if (v194 == nil) { Lisp_Object res = stack[0]; popv(5); return onevalue(res); }
    v194 = stack[-1];
    v194 = qcar(v194);
    v196 = qcar(v194);
    v195 = stack[-3];
    v194 = stack[0];
    popv(5);
    return acons(v196, v195, v194);

v82:
    v194 = stack[-2];
    v194 = qcar(v194);
    v194 = qcar(v194);
    v194 = qcdr(v194);
    v194 = integerp(v194);
    if (v194 == nil) goto v116;
    v194 = stack[-1];
    v194 = qcar(v194);
    v194 = qcar(v194);
    v194 = qcdr(v194);
    v194 = integerp(v194);
    if (v194 == nil) goto v116;
    stack[0] = stack[-3];
    v194 = stack[-2];
    v194 = qcar(v194);
    v194 = qcar(v194);
    v195 = qcdr(v194);
    v194 = stack[-1];
    v194 = qcar(v194);
    v194 = qcar(v194);
    v194 = qcdr(v194);
    v194 = plus2(v195, v194);
    nil = C_nil;
    if (exception_pending()) goto v197;
    env = stack[-4];
    fn = elt(env, 13); /* mkspm */
    v194 = (*qfn2(fn))(qenv(fn), stack[0], v194);
    nil = C_nil;
    if (exception_pending()) goto v197;
    env = stack[-4];
    stack[-3] = v194;
    goto v199;

v199:
    v194 = stack[-2];
    v195 = qcdr(v194);
    v194 = stack[-1];
    stack[0] = CC_multf(env, v195, v194);
    nil = C_nil;
    if (exception_pending()) goto v197;
    env = stack[-4];
    v194 = stack[-2];
    v194 = qcar(v194);
    v195 = ncons(v194);
    nil = C_nil;
    if (exception_pending()) goto v197;
    env = stack[-4];
    v194 = stack[-1];
    v194 = qcdr(v194);
    v194 = CC_multf(env, v195, v194);
    nil = C_nil;
    if (exception_pending()) goto v197;
    env = stack[-4];
    fn = elt(env, 14); /* addf */
    v194 = (*qfn2(fn))(qenv(fn), stack[0], v194);
    nil = C_nil;
    if (exception_pending()) goto v197;
    env = stack[-4];
    stack[0] = v194;
    v194 = stack[-3];
    if (v194 == nil) goto v200;
    v194 = stack[-2];
    v194 = qcar(v194);
    v195 = qcdr(v194);
    v194 = stack[-1];
    v194 = qcar(v194);
    v194 = qcdr(v194);
    v194 = CC_multf(env, v195, v194);
    nil = C_nil;
    if (exception_pending()) goto v197;
    env = stack[-4];
    stack[-2] = v194;
    if (v194 == nil) goto v200;
    v195 = stack[-3];
    v194 = (Lisp_Object)17; /* 1 */
    if (v195 == v194) goto v201;
    v194 = qvalue(elt(env, 7)); /* !*mcd */
    if (v194 == nil) goto v202;
    v196 = stack[-3];
    v195 = stack[-2];
    v194 = stack[0];
    popv(5);
    return acons(v196, v195, v194);

v202:
    v195 = stack[-3];
    v194 = stack[-2];
    v194 = cons(v195, v194);
    nil = C_nil;
    if (exception_pending()) goto v197;
    env = stack[-4];
    v195 = ncons(v194);
    nil = C_nil;
    if (exception_pending()) goto v197;
    env = stack[-4];
    v194 = stack[0];
    {
        popv(5);
        fn = elt(env, 14); /* addf */
        return (*qfn2(fn))(qenv(fn), v195, v194);
    }

v201:
    v195 = stack[-2];
    v194 = stack[0];
    {
        popv(5);
        fn = elt(env, 14); /* addf */
        return (*qfn2(fn))(qenv(fn), v195, v194);
    }

v200:
    v194 = lisp_true;
    qvalue(elt(env, 6)) = v194; /* !*asymp!* */
    { Lisp_Object res = stack[0]; popv(5); return onevalue(res); }

v116:
    stack[0] = stack[-3];
    v196 = elt(env, 5); /* plus */
    v194 = stack[-2];
    v194 = qcar(v194);
    v194 = qcar(v194);
    v195 = qcdr(v194);
    v194 = stack[-1];
    v194 = qcar(v194);
    v194 = qcar(v194);
    v194 = qcdr(v194);
    v194 = list3(v196, v195, v194);
    nil = C_nil;
    if (exception_pending()) goto v197;
    env = stack[-4];
    fn = elt(env, 15); /* reval */
    v194 = (*qfn1(fn))(qenv(fn), v194);
    nil = C_nil;
    if (exception_pending()) goto v197;
    env = stack[-4];
    fn = elt(env, 16); /* to */
    v194 = (*qfn2(fn))(qenv(fn), stack[0], v194);
    nil = C_nil;
    if (exception_pending()) goto v197;
    env = stack[-4];
    stack[-3] = v194;
    goto v199;

v134:
    v195 = stack[-1];
    v194 = stack[-2];
    {
        popv(5);
        fn = elt(env, 17); /* multd */
        return (*qfn2(fn))(qenv(fn), v195, v194);
    }

v51:
    v195 = stack[-2];
    v194 = stack[-1];
    {
        popv(5);
        fn = elt(env, 17); /* multd */
        return (*qfn2(fn))(qenv(fn), v195, v194);
    }

v7:
    v194 = nil;
    { popv(5); return onevalue(v194); }
/* error exit handlers */
v197:
    popv(5);
    return nil;
}



/* Code for replus */

static Lisp_Object CC_replus(Lisp_Object env,
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
    CSL_IGNORE(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v21 = v0;
/* end of prologue */
    v20 = v21;
    if (v20 == nil) goto v3;
    v20 = v21;
    if (!consp(v20)) { popv(1); return onevalue(v21); }
    v20 = v21;
    v20 = qcdr(v20);
    if (v20 == nil) goto v1;
    stack[0] = elt(env, 1); /* plus */
    v20 = v21;
    fn = elt(env, 2); /* unplus */
    v20 = (*qfn1(fn))(qenv(fn), v20);
    nil = C_nil;
    if (exception_pending()) goto v23;
    {
        Lisp_Object v30 = stack[0];
        popv(1);
        return cons(v30, v20);
    }

v1:
    v20 = v21;
    v20 = qcar(v20);
    { popv(1); return onevalue(v20); }

v3:
    v20 = (Lisp_Object)1; /* 0 */
    { popv(1); return onevalue(v20); }
/* error exit handlers */
v23:
    popv(1);
    return nil;
}



/* Code for quotf */

static Lisp_Object CC_quotf(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v2, v25, v13;
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
    v25 = v16;
    v13 = v0;
/* end of prologue */
    v2 = lisp_true;
    stack[0] = qvalue(elt(env, 1)); /* !*exp */
    qvalue(elt(env, 1)) = v2; /* !*exp */
    v2 = v13;
    fn = elt(env, 2); /* quotf1 */
    v2 = (*qfn2(fn))(qenv(fn), v2, v25);
    nil = C_nil;
    if (exception_pending()) goto v26;
    env = stack[-1];
    qvalue(elt(env, 1)) = stack[0]; /* !*exp */
    { popv(2); return onevalue(v2); }
/* error exit handlers */
v26:
    env = stack[-1];
    qvalue(elt(env, 1)) = stack[0]; /* !*exp */
    popv(2);
    return nil;
}



/* Code for addsq */

static Lisp_Object CC_addsq(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v175, v221;
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
    v175 = stack[-3];
    v175 = qcar(v175);
    if (v175 == nil) { Lisp_Object res = stack[-2]; popv(6); return onevalue(res); }
    v175 = stack[-2];
    v175 = qcar(v175);
    if (v175 == nil) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v175 = stack[-3];
    v221 = qcdr(v175);
    v175 = (Lisp_Object)17; /* 1 */
    if (!(v221 == v175)) goto v34;
    v175 = stack[-2];
    v221 = qcdr(v175);
    v175 = (Lisp_Object)17; /* 1 */
    if (!(v221 == v175)) goto v34;
    v175 = stack[-3];
    v221 = qcar(v175);
    v175 = stack[-2];
    v175 = qcar(v175);
    fn = elt(env, 3); /* addf */
    v221 = (*qfn2(fn))(qenv(fn), v221, v175);
    nil = C_nil;
    if (exception_pending()) goto v222;
    v175 = (Lisp_Object)17; /* 1 */
    popv(6);
    return cons(v221, v175);

v34:
    v175 = qvalue(elt(env, 1)); /* !*exp */
    if (!(v175 == nil)) goto v134;
    v175 = stack[-3];
    stack[0] = qcar(v175);
    v175 = stack[-3];
    v175 = qcdr(v175);
    fn = elt(env, 4); /* mkprod */
    v175 = (*qfn1(fn))(qenv(fn), v175);
    nil = C_nil;
    if (exception_pending()) goto v222;
    env = stack[-5];
    v175 = cons(stack[0], v175);
    nil = C_nil;
    if (exception_pending()) goto v222;
    env = stack[-5];
    stack[-3] = v175;
    v175 = stack[-2];
    stack[0] = qcar(v175);
    v175 = stack[-2];
    v175 = qcdr(v175);
    fn = elt(env, 4); /* mkprod */
    v175 = (*qfn1(fn))(qenv(fn), v175);
    nil = C_nil;
    if (exception_pending()) goto v222;
    env = stack[-5];
    v175 = cons(stack[0], v175);
    nil = C_nil;
    if (exception_pending()) goto v222;
    env = stack[-5];
    stack[-2] = v175;
    goto v134;

v134:
    v175 = qvalue(elt(env, 2)); /* !*lcm */
    if (v175 == nil) goto v84;
    v175 = stack[-3];
    v221 = qcdr(v175);
    v175 = stack[-2];
    v175 = qcdr(v175);
    fn = elt(env, 5); /* gcdf!* */
    v175 = (*qfn2(fn))(qenv(fn), v221, v175);
    nil = C_nil;
    if (exception_pending()) goto v222;
    env = stack[-5];
    stack[-4] = v175;
    goto v223;

v223:
    v175 = stack[-3];
    v221 = qcdr(v175);
    v175 = stack[-4];
    fn = elt(env, 6); /* quotf */
    stack[0] = (*qfn2(fn))(qenv(fn), v221, v175);
    nil = C_nil;
    if (exception_pending()) goto v222;
    env = stack[-5];
    v175 = stack[-2];
    v221 = qcdr(v175);
    v175 = stack[-4];
    fn = elt(env, 6); /* quotf */
    v175 = (*qfn2(fn))(qenv(fn), v221, v175);
    nil = C_nil;
    if (exception_pending()) goto v222;
    env = stack[-5];
    v175 = cons(stack[0], v175);
    nil = C_nil;
    if (exception_pending()) goto v222;
    env = stack[-5];
    fn = elt(env, 7); /* canonsq */
    v175 = (*qfn1(fn))(qenv(fn), v175);
    nil = C_nil;
    if (exception_pending()) goto v222;
    env = stack[-5];
    stack[-1] = v175;
    v175 = stack[-1];
    v221 = qcdr(v175);
    v175 = stack[-3];
    v175 = qcar(v175);
    fn = elt(env, 8); /* multf */
    stack[0] = (*qfn2(fn))(qenv(fn), v221, v175);
    nil = C_nil;
    if (exception_pending()) goto v222;
    env = stack[-5];
    v175 = stack[-1];
    v221 = qcar(v175);
    v175 = stack[-2];
    v175 = qcar(v175);
    fn = elt(env, 8); /* multf */
    v175 = (*qfn2(fn))(qenv(fn), v221, v175);
    nil = C_nil;
    if (exception_pending()) goto v222;
    env = stack[-5];
    fn = elt(env, 3); /* addf */
    v175 = (*qfn2(fn))(qenv(fn), stack[0], v175);
    nil = C_nil;
    if (exception_pending()) goto v222;
    env = stack[-5];
    stack[0] = v175;
    v175 = stack[0];
    if (v175 == nil) goto v187;
    v175 = stack[-3];
    v221 = qcdr(v175);
    v175 = stack[-1];
    v175 = qcdr(v175);
    fn = elt(env, 8); /* multf */
    v175 = (*qfn2(fn))(qenv(fn), v221, v175);
    nil = C_nil;
    if (exception_pending()) goto v222;
    env = stack[-5];
    stack[-1] = v175;
    v221 = stack[-4];
    v175 = (Lisp_Object)17; /* 1 */
    if (v221 == v175) goto v224;
    v221 = stack[0];
    v175 = stack[-4];
    fn = elt(env, 9); /* gcdf */
    v221 = (*qfn2(fn))(qenv(fn), v221, v175);
    nil = C_nil;
    if (exception_pending()) goto v222;
    env = stack[-5];
    stack[-4] = v221;
    v175 = (Lisp_Object)17; /* 1 */
    if (v221 == v175) goto v224;
    v221 = stack[0];
    v175 = stack[-4];
    fn = elt(env, 6); /* quotf */
    stack[0] = (*qfn2(fn))(qenv(fn), v221, v175);
    nil = C_nil;
    if (exception_pending()) goto v222;
    env = stack[-5];
    v221 = stack[-1];
    v175 = stack[-4];
    fn = elt(env, 6); /* quotf */
    v175 = (*qfn2(fn))(qenv(fn), v221, v175);
    nil = C_nil;
    if (exception_pending()) goto v222;
    env = stack[-5];
    v175 = cons(stack[0], v175);
    nil = C_nil;
    if (exception_pending()) goto v222;
    env = stack[-5];
    {
        popv(6);
        fn = elt(env, 7); /* canonsq */
        return (*qfn1(fn))(qenv(fn), v175);
    }

v224:
    v221 = stack[0];
    v175 = stack[-1];
    popv(6);
    return cons(v221, v175);

v187:
    v221 = nil;
    v175 = (Lisp_Object)17; /* 1 */
    popv(6);
    return cons(v221, v175);

v84:
    v175 = stack[-3];
    v221 = qcdr(v175);
    v175 = stack[-2];
    v175 = qcdr(v175);
    fn = elt(env, 9); /* gcdf */
    v175 = (*qfn2(fn))(qenv(fn), v221, v175);
    nil = C_nil;
    if (exception_pending()) goto v222;
    env = stack[-5];
    stack[-4] = v175;
    goto v223;
/* error exit handlers */
v222:
    popv(6);
    return nil;
}



/* Code for getpower */

static Lisp_Object CC_getpower(Lisp_Object env,
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
    v53 = stack[-1];
    v14 = qcar(v53);
    v53 = elt(env, 1); /* expt */
    if (!consp(v14)) goto v19;
    v14 = qcar(v14);
    if (!(v14 == v53)) goto v19;
    v14 = stack[0];
    v53 = (Lisp_Object)17; /* 1 */
    v53 = (Lisp_Object)greaterp2(v14, v53);
    nil = C_nil;
    if (exception_pending()) goto v32;
    v53 = v53 ? lisp_true : nil;
    env = stack[-2];
    if (v53 == nil) goto v19;
    v53 = lisp_true;
    qvalue(elt(env, 2)) = v53; /* !*sub2 */
    goto v19;

v19:
    v53 = stack[-1];
    v14 = qcar(v53);
    v53 = stack[0];
    popv(3);
    return cons(v14, v53);
/* error exit handlers */
v32:
    popv(3);
    return nil;
}



/* Code for prin2!* */

static Lisp_Object CC_prin2H(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v199, v227, v228;
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
    v199 = qvalue(elt(env, 1)); /* outputhandler!* */
    if (v199 == nil) goto v99;
    v227 = qvalue(elt(env, 1)); /* outputhandler!* */
    v228 = elt(env, 0); /* prin2!* */
    v199 = stack[-2];
        popv(5);
        return Lapply2(nil, 3, v227, v228, v199);

v99:
    v227 = stack[-2];
    v199 = elt(env, 2); /* oldnam */
    v199 = get(v227, v199);
    env = stack[-4];
    v227 = v199;
    if (v199 == nil) goto v21;
    v199 = v227;
    stack[-2] = v199;
    goto v21;

v21:
    v199 = qvalue(elt(env, 3)); /* overflowed!* */
    if (v199 == nil) goto v51;
    v199 = elt(env, 4); /* overflowed */
    { popv(5); return onevalue(v199); }

v51:
    v199 = qvalue(elt(env, 5)); /* !*fort */
    if (v199 == nil) goto v52;
    v199 = stack[-2];
    {
        popv(5);
        fn = elt(env, 14); /* fprin2!* */
        return (*qfn1(fn))(qenv(fn), v199);
    }

v52:
    v199 = qvalue(elt(env, 6)); /* !*nat */
    if (v199 == nil) goto v48;
    v227 = stack[-2];
    v199 = elt(env, 7); /* pi */
    if (v227 == v199) goto v100;
    v227 = stack[-2];
    v199 = elt(env, 9); /* infinity */
    if (!(v227 == v199)) goto v48;
    v199 = elt(env, 9); /* infinity */
    fn = elt(env, 15); /* symbol */
    v199 = (*qfn1(fn))(qenv(fn), v199);
    nil = C_nil;
    if (exception_pending()) goto v185;
    env = stack[-4];
    stack[-2] = v199;
    goto v48;

v48:
    v199 = stack[-2];
    v199 = Llengthc(nil, v199);
    nil = C_nil;
    if (exception_pending()) goto v185;
    env = stack[-4];
    stack[-1] = v199;
    v199 = stack[-2];
    v199 = integerp(v199);
    if (v199 == nil) goto v83;
    v227 = stack[-1];
    v199 = (Lisp_Object)801; /* 50 */
    v199 = (Lisp_Object)greaterp2(v227, v199);
    nil = C_nil;
    if (exception_pending()) goto v185;
    v199 = v199 ? lisp_true : nil;
    env = stack[-4];
    if (v199 == nil) goto v83;
    v199 = qvalue(elt(env, 10)); /* !*rounded */
    if (v199 == nil) goto v83;
    v199 = stack[-2];
    fn = elt(env, 16); /* i2rd!* */
    v199 = (*qfn1(fn))(qenv(fn), v199);
    nil = C_nil;
    if (exception_pending()) goto v185;
    env = stack[-4];
    {
        popv(5);
        fn = elt(env, 17); /* rd!:prin */
        return (*qfn1(fn))(qenv(fn), v199);
    }

v83:
    v227 = qvalue(elt(env, 11)); /* posn!* */
    v199 = stack[-1];
    v199 = (Lisp_Object)(int32_t)((int32_t)v227 + (int32_t)v199 - TAG_FIXNUM);
    stack[-3] = v199;
    v199 = nil;
    v227 = Llinelength(nil, v199);
    nil = C_nil;
    if (exception_pending()) goto v185;
    env = stack[-4];
    v199 = qvalue(elt(env, 12)); /* spare!* */
    v199 = difference2(v227, v199);
    nil = C_nil;
    if (exception_pending()) goto v185;
    env = stack[-4];
    stack[0] = v199;
    v227 = stack[-3];
    v199 = stack[0];
    v199 = (Lisp_Object)lesseq2(v227, v199);
    nil = C_nil;
    if (exception_pending()) goto v185;
    v199 = v199 ? lisp_true : nil;
    env = stack[-4];
    if (!(v199 == nil)) goto v74;
    v199 = qvalue(elt(env, 13)); /* testing!-width!* */
    if (!(v199 == nil)) goto v140;
    v199 = stack[-2];
    v199 = integerp(v199);
    if (!(v199 == nil)) goto v214;
    v199 = lisp_true;
    fn = elt(env, 18); /* terpri!* */
    v199 = (*qfn1(fn))(qenv(fn), v199);
    nil = C_nil;
    if (exception_pending()) goto v185;
    env = stack[-4];
    goto v214;

v214:
    v227 = qvalue(elt(env, 11)); /* posn!* */
    v199 = stack[-1];
    v227 = (Lisp_Object)(int32_t)((int32_t)v227 + (int32_t)v199 - TAG_FIXNUM);
    stack[-3] = v227;
    v199 = stack[0];
    v199 = (Lisp_Object)lesseq2(v227, v199);
    nil = C_nil;
    if (exception_pending()) goto v185;
    v199 = v199 ? lisp_true : nil;
    env = stack[-4];
    if (!(v199 == nil)) goto v74;

v140:
    v199 = qvalue(elt(env, 13)); /* testing!-width!* */
    if (v199 == nil) goto v124;
    v199 = lisp_true;
    qvalue(elt(env, 3)) = v199; /* overflowed!* */
    v199 = elt(env, 4); /* overflowed */
    { popv(5); return onevalue(v199); }

v124:
    v228 = stack[-2];
    v199 = qvalue(elt(env, 11)); /* posn!* */
    v227 = (Lisp_Object)((int32_t)(v199) + 0x10);
    v199 = stack[0];
    v199 = (Lisp_Object)((int32_t)(v199) - 0x10);
    {
        popv(5);
        fn = elt(env, 19); /* prin2lint */
        return (*qfnn(fn))(qenv(fn), 3, v228, v227, v199);
    }

v74:
    v227 = stack[-2];
    v199 = stack[-3];
    {
        popv(5);
        fn = elt(env, 20); /* add_prin_char */
        return (*qfn2(fn))(qenv(fn), v227, v199);
    }

v100:
    v199 = elt(env, 8); /* !.pi */
    fn = elt(env, 15); /* symbol */
    v199 = (*qfn1(fn))(qenv(fn), v199);
    nil = C_nil;
    if (exception_pending()) goto v185;
    env = stack[-4];
    stack[-2] = v199;
    goto v48;
/* error exit handlers */
v185:
    popv(5);
    return nil;
}



/* Code for ordpp */

static Lisp_Object CC_ordpp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v57, v72, v122, v58, v55;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v122 = v16;
    v58 = v0;
/* end of prologue */
    v57 = v58;
    v72 = qcar(v57);
    v57 = v122;
    v57 = qcar(v57);
    if (v72 == v57) goto v44;
    v57 = qvalue(elt(env, 1)); /* kord!* */
    v55 = v57;
    v57 = v58;
    v57 = qcar(v57);
    v58 = v57;
    v57 = v122;
    v57 = qcar(v57);
    v122 = v57;
    goto v12;

v12:
    v57 = v55;
    if (v57 == nil) goto v37;
    v72 = v58;
    v57 = v55;
    v57 = qcar(v57);
    if (v72 == v57) goto v50;
    v72 = v122;
    v57 = v55;
    v57 = qcar(v57);
    if (v72 == v57) goto v150;
    v57 = v55;
    v57 = qcdr(v57);
    v55 = v57;
    goto v12;

v150:
    v57 = nil;
    return onevalue(v57);

v50:
    v57 = lisp_true;
    return onevalue(v57);

v37:
    v57 = v58;
    v72 = v122;
    {
        fn = elt(env, 2); /* ordpa */
        return (*qfn2(fn))(qenv(fn), v57, v72);
    }

v44:
    v57 = v58;
    v57 = qcdr(v57);
    v72 = v122;
    v72 = qcdr(v72);
        return Lgreaterp(nil, v57, v72);
}



/* Code for scprint */

static Lisp_Object CC_scprint(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v87, v66;
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
    stack[-2] = v16;
    v66 = v0;
/* end of prologue */
    v87 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 1)) = v87; /* posn!* */
    v87 = v66;
    stack[-1] = v87;
    goto v7;

v7:
    v87 = stack[-1];
    if (v87 == nil) goto v6;
    v87 = stack[-1];
    v87 = qcar(v87);
    stack[0] = v87;
    v87 = stack[0];
    v87 = qcar(v87);
    v66 = qcdr(v87);
    v87 = stack[-2];
    if (!(equal(v66, v87))) goto v47;
    v87 = stack[0];
    v87 = qcar(v87);
    v87 = qcar(v87);
    v66 = qcar(v87);
    v87 = qvalue(elt(env, 1)); /* posn!* */
    v66 = difference2(v66, v87);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-4];
    stack[-3] = v66;
    v87 = (Lisp_Object)1; /* 0 */
    v87 = (Lisp_Object)lessp2(v66, v87);
    nil = C_nil;
    if (exception_pending()) goto v72;
    v87 = v87 ? lisp_true : nil;
    env = stack[-4];
    if (!(v87 == nil)) goto v10;
    v87 = stack[-3];
    v87 = Lxtab(nil, v87);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-4];
    goto v10;

v10:
    v87 = stack[0];
    v87 = qcdr(v87);
    v87 = Lprinc(nil, v87);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-4];
    v87 = stack[0];
    v87 = qcar(v87);
    v87 = qcar(v87);
    v87 = qcdr(v87);
    qvalue(elt(env, 1)) = v87; /* posn!* */
    goto v47;

v47:
    v87 = stack[-1];
    v87 = qcdr(v87);
    stack[-1] = v87;
    goto v7;

v6:
    v87 = nil;
    { popv(5); return onevalue(v87); }
/* error exit handlers */
v72:
    popv(5);
    return nil;
}



/* Code for mtp */

static Lisp_Object CC_mtp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v31, v32, v37;
    CSL_IGNORE(nil);
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v32 = v0;
/* end of prologue */

v11:
    v31 = v32;
    v31 = (v31 == nil ? lisp_true : nil);
    if (!(v31 == nil)) return onevalue(v31);
    v31 = v32;
    v37 = qcar(v31);
    v31 = qvalue(elt(env, 1)); /* frlis!* */
    v31 = Lmemq(nil, v37, v31);
    if (v31 == nil) goto v6;
    v31 = v32;
    v37 = qcar(v31);
    v31 = v32;
    v31 = qcdr(v31);
    v31 = Lmember(nil, v37, v31);
    if (v31 == nil) goto v99;
    v31 = nil;
    return onevalue(v31);

v99:
    v31 = v32;
    v31 = qcdr(v31);
    v32 = v31;
    goto v11;

v6:
    v31 = nil;
    return onevalue(v31);
}



/* Code for getelv */

static Lisp_Object CC_getelv(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v40, v206;
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
    v206 = v0;
/* end of prologue */
    v40 = v206;
    stack[-4] = qcar(v40);
    v40 = v206;
    v40 = qcdr(v40);
    stack[-3] = v40;
    v40 = stack[-3];
    if (v40 == nil) goto v44;
    v40 = stack[-3];
    v40 = qcar(v40);
    fn = elt(env, 1); /* reval_without_mod */
    v40 = (*qfn1(fn))(qenv(fn), v40);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-5];
    v40 = ncons(v40);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-5];
    stack[-1] = v40;
    stack[-2] = v40;
    goto v24;

v24:
    v40 = stack[-3];
    v40 = qcdr(v40);
    stack[-3] = v40;
    v40 = stack[-3];
    if (v40 == nil) goto v10;
    stack[0] = stack[-1];
    v40 = stack[-3];
    v40 = qcar(v40);
    fn = elt(env, 1); /* reval_without_mod */
    v40 = (*qfn1(fn))(qenv(fn), v40);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-5];
    v40 = ncons(v40);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-5];
    v40 = Lrplacd(nil, stack[0], v40);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-5];
    v40 = stack[-1];
    v40 = qcdr(v40);
    stack[-1] = v40;
    goto v24;

v10:
    v40 = stack[-2];
    goto v45;

v45:
    v40 = cons(stack[-4], v40);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-5];
    {
        popv(6);
        fn = elt(env, 2); /* getel */
        return (*qfn1(fn))(qenv(fn), v40);
    }

v44:
    v40 = nil;
    goto v45;
/* error exit handlers */
v105:
    popv(6);
    return nil;
}



/* Code for reval2 */

static Lisp_Object CC_reval2(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v10, v53;
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
    v53 = v0;
/* end of prologue */
    v10 = stack[0];
    if (!(v10 == nil)) goto v25;
    v10 = qvalue(elt(env, 1)); /* !*combineexpt */
    if (v10 == nil) goto v25;
    v10 = qvalue(elt(env, 2)); /* dmode!* */
    if (!(v10 == nil)) goto v25;
    v10 = nil;
    stack[-1] = qvalue(elt(env, 3)); /* !*mcd */
    qvalue(elt(env, 3)) = v10; /* !*mcd */
    v10 = v53;
    fn = elt(env, 4); /* simp!* */
    v53 = (*qfn1(fn))(qenv(fn), v10);
    nil = C_nil;
    if (exception_pending()) goto v31;
    env = stack[-2];
    qvalue(elt(env, 3)) = stack[-1]; /* !*mcd */
    v10 = stack[0];
    {
        popv(3);
        fn = elt(env, 5); /* !*q2a1 */
        return (*qfn2(fn))(qenv(fn), v53, v10);
    }

v25:
    v10 = v53;
    fn = elt(env, 4); /* simp!* */
    v53 = (*qfn1(fn))(qenv(fn), v10);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-2];
    v10 = stack[0];
    {
        popv(3);
        fn = elt(env, 5); /* !*q2a1 */
        return (*qfn2(fn))(qenv(fn), v53, v10);
    }
/* error exit handlers */
v32:
    popv(3);
    return nil;
v31:
    env = stack[-2];
    qvalue(elt(env, 3)) = stack[-1]; /* !*mcd */
    popv(3);
    return nil;
}



/* Code for retimes */

static Lisp_Object CC_retimes(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v51, v42;
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
    v51 = v0;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* !*bool */
    qvalue(elt(env, 1)) = nil; /* !*bool */
    fn = elt(env, 4); /* retimes1 */
    v51 = (*qfn1(fn))(qenv(fn), v51);
    nil = C_nil;
    if (exception_pending()) goto v50;
    env = stack[-1];
    v42 = v51;
    if (v42 == nil) goto v6;
    v42 = v51;
    v42 = qcdr(v42);
    if (v42 == nil) goto v29;
    v42 = elt(env, 2); /* times */
    v51 = cons(v42, v51);
    nil = C_nil;
    if (exception_pending()) goto v50;
    env = stack[-1];
    goto v5;

v5:
    v42 = qvalue(elt(env, 1)); /* !*bool */
    if (v42 == nil) goto v3;
    v42 = elt(env, 3); /* minus */
    v51 = list2(v42, v51);
    nil = C_nil;
    if (exception_pending()) goto v50;
    env = stack[-1];
    goto v3;

v3:
    qvalue(elt(env, 1)) = stack[0]; /* !*bool */
    { popv(2); return onevalue(v51); }

v29:
    v51 = qcar(v51);
    goto v5;

v6:
    v51 = (Lisp_Object)17; /* 1 */
    goto v5;
/* error exit handlers */
v50:
    env = stack[-1];
    qvalue(elt(env, 1)) = stack[0]; /* !*bool */
    popv(2);
    return nil;
}



/* Code for mtchp1 */

static Lisp_Object MS_CDECL CC_mtchp1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v16,
                         Lisp_Object v63, Lisp_Object v9, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v232, v127, v186;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "mtchp1");
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
    v232 = v9;
    stack[0] = v63;
    stack[-1] = v16;
    stack[-2] = v0;
/* end of prologue */
    v127 = stack[-2];
    v232 = stack[-1];
    if (equal(v127, v232)) goto v7;
    v232 = stack[-2];
    v127 = qcar(v232);
    v232 = stack[-1];
    v232 = qcar(v232);
    fn = elt(env, 3); /* mchk!* */
    v232 = (*qfn2(fn))(qenv(fn), v127, v232);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-4];
    stack[-3] = v232;
    if (v232 == nil) goto v44;
    v232 = stack[-1];
    v127 = qcdr(v232);
    v232 = qvalue(elt(env, 1)); /* frlis!* */
    v232 = Lmemq(nil, v127, v232);
    if (v232 == nil) goto v10;
    v232 = stack[-2];
    v127 = qcdr(v232);
    v232 = (Lisp_Object)17; /* 1 */
    if (v127 == v232) goto v49;
    v232 = stack[-1];
    v186 = qcdr(v232);
    v127 = stack[-3];
    v232 = stack[-2];
    v232 = qcdr(v232);
    fn = elt(env, 4); /* powmtch */
    v232 = (*qfnn(fn))(qenv(fn), 3, v186, v127, v232);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-4];
    stack[-3] = v232;
    if (v232 == nil) goto v49;
    stack[0] = stack[-3];
    v232 = stack[-1];
    v127 = qcdr(v232);
    v232 = stack[-2];
    v232 = qcdr(v232);
    v232 = cons(v127, v232);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-4];
    {
        Lisp_Object v94 = stack[0];
        popv(5);
        fn = elt(env, 5); /* mapcons */
        return (*qfn2(fn))(qenv(fn), v94, v232);
    }

v49:
    v232 = nil;
    { popv(5); return onevalue(v232); }

v10:
    v232 = stack[0];
    if (v232 == nil) goto v112;
    v232 = stack[-2];
    v127 = qcdr(v232);
    v232 = stack[-1];
    v232 = qcdr(v232);
    if (!(equal(v127, v232))) goto v128;

v112:
    v232 = stack[-1];
    v232 = qcdr(v232);
    if (!(is_number(v232))) goto v128;
    v232 = stack[-2];
    v232 = qcdr(v232);
    if (!(is_number(v232))) goto v128;
    v232 = qvalue(elt(env, 2)); /* !*mcd */
    if (v232 == nil) goto v133;
    v232 = stack[-2];
    v127 = qcdr(v232);
    v232 = stack[-1];
    v232 = qcdr(v232);
    v232 = (Lisp_Object)lessp2(v127, v232);
    nil = C_nil;
    if (exception_pending()) goto v108;
    v232 = v232 ? lisp_true : nil;
    goto v135;

v135:
    if (v232 == nil) { Lisp_Object res = stack[-3]; popv(5); return onevalue(res); }
    else goto v128;

v128:
    v232 = nil;
    { popv(5); return onevalue(v232); }

v133:
    v232 = stack[-2];
    v127 = qcdr(v232);
    v232 = stack[-1];
    v232 = qcdr(v232);
    v127 = times2(v127, v232);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-4];
    v232 = (Lisp_Object)1; /* 0 */
    v232 = (Lisp_Object)lessp2(v127, v232);
    nil = C_nil;
    if (exception_pending()) goto v108;
    v232 = v232 ? lisp_true : nil;
    env = stack[-4];
    if (!(v232 == nil)) goto v135;
    v232 = stack[-2];
    v232 = qcdr(v232);
    stack[0] = Labsval(nil, v232);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-4];
    v232 = stack[-1];
    v232 = qcdr(v232);
    v232 = Labsval(nil, v232);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-4];
    v232 = (Lisp_Object)lessp2(stack[0], v232);
    nil = C_nil;
    if (exception_pending()) goto v108;
    v232 = v232 ? lisp_true : nil;
    goto v135;

v44:
    v232 = nil;
    { popv(5); return onevalue(v232); }

v7:
    v232 = nil;
    popv(5);
    return ncons(v232);
/* error exit handlers */
v108:
    popv(5);
    return nil;
}



/* Code for mapcons */

static Lisp_Object CC_mapcons(Lisp_Object env,
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
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-3] = v16;
    v64 = v0;
/* end of prologue */
    stack[-4] = v64;
    v64 = stack[-4];
    if (v64 == nil) goto v1;
    v64 = stack[-4];
    v64 = qcar(v64);
    v100 = stack[-3];
    v64 = cons(v100, v64);
    nil = C_nil;
    if (exception_pending()) goto v68;
    env = stack[-5];
    v64 = ncons(v64);
    nil = C_nil;
    if (exception_pending()) goto v68;
    env = stack[-5];
    stack[-1] = v64;
    stack[-2] = v64;
    goto v5;

v5:
    v64 = stack[-4];
    v64 = qcdr(v64);
    stack[-4] = v64;
    v64 = stack[-4];
    if (v64 == nil) { Lisp_Object res = stack[-2]; popv(6); return onevalue(res); }
    stack[0] = stack[-1];
    v64 = stack[-4];
    v64 = qcar(v64);
    v100 = stack[-3];
    v64 = cons(v100, v64);
    nil = C_nil;
    if (exception_pending()) goto v68;
    env = stack[-5];
    v64 = ncons(v64);
    nil = C_nil;
    if (exception_pending()) goto v68;
    env = stack[-5];
    v64 = Lrplacd(nil, stack[0], v64);
    nil = C_nil;
    if (exception_pending()) goto v68;
    env = stack[-5];
    v64 = stack[-1];
    v64 = qcdr(v64);
    stack[-1] = v64;
    goto v5;

v1:
    v64 = nil;
    { popv(6); return onevalue(v64); }
/* error exit handlers */
v68:
    popv(6);
    return nil;
}



/* Code for exptchksq */

static Lisp_Object CC_exptchksq(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v101, v57;
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
    v101 = qvalue(elt(env, 1)); /* !*combineexpt */
    if (v101 == nil) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v101 = stack[0];
    v101 = qcar(v101);
    fn = elt(env, 2); /* exptchk */
    stack[-1] = (*qfn1(fn))(qenv(fn), v101);
    nil = C_nil;
    if (exception_pending()) goto v58;
    env = stack[-2];
    v101 = stack[0];
    v101 = qcdr(v101);
    fn = elt(env, 2); /* exptchk */
    v101 = (*qfn1(fn))(qenv(fn), v101);
    nil = C_nil;
    if (exception_pending()) goto v58;
    env = stack[-2];
    v101 = cons(stack[-1], v101);
    nil = C_nil;
    if (exception_pending()) goto v58;
    env = stack[-2];
    stack[-1] = v101;
    v57 = stack[0];
    v101 = stack[-1];
    if (equal(v57, v101)) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v101 = stack[-1];
    v57 = qcdr(v101);
    v101 = (Lisp_Object)17; /* 1 */
    if (v57 == v101) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v101 = stack[-1];
    v57 = qcar(v101);
    v101 = (Lisp_Object)17; /* 1 */
    stack[0] = cons(v57, v101);
    nil = C_nil;
    if (exception_pending()) goto v58;
    env = stack[-2];
    v57 = (Lisp_Object)17; /* 1 */
    v101 = stack[-1];
    v101 = qcdr(v101);
    v101 = cons(v57, v101);
    nil = C_nil;
    if (exception_pending()) goto v58;
    env = stack[-2];
    {
        Lisp_Object v55 = stack[0];
        popv(3);
        fn = elt(env, 3); /* multsq */
        return (*qfn2(fn))(qenv(fn), v55, v101);
    }
/* error exit handlers */
v58:
    popv(3);
    return nil;
}



/* Code for gcdfd1 */

static Lisp_Object CC_gcdfd1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v37, v36;
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
    v37 = v0;
/* end of prologue */

v4:
    v36 = stack[0];
    if (v36 == nil) { popv(2); return onevalue(v37); }
    v36 = stack[0];
    if (!consp(v36)) goto v38;
    v36 = stack[0];
    v36 = qcar(v36);
    if (!consp(v36)) goto v38;
    v36 = v37;
    v37 = stack[0];
    v37 = qcar(v37);
    v37 = qcdr(v37);
    v37 = CC_gcdfd1(env, v36, v37);
    nil = C_nil;
    if (exception_pending()) goto v33;
    env = stack[-1];
    v36 = stack[0];
    v36 = qcdr(v36);
    stack[0] = v36;
    goto v4;

v38:
    v36 = v37;
    v37 = stack[0];
    {
        popv(2);
        fn = elt(env, 1); /* gcddd */
        return (*qfn2(fn))(qenv(fn), v36, v37);
    }
/* error exit handlers */
v33:
    popv(2);
    return nil;
}



/* Code for getel */

static Lisp_Object CC_getel(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v69, v67, v68;
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
    v69 = stack[-1];
    v67 = qcar(v69);
    v69 = elt(env, 1); /* dimension */
    v69 = get(v67, v69);
    env = stack[-3];
    stack[-2] = v69;
    v69 = stack[-2];
    stack[0] = Llength(nil, v69);
    nil = C_nil;
    if (exception_pending()) goto v66;
    env = stack[-3];
    v69 = stack[-1];
    v69 = qcdr(v69);
    v69 = Llength(nil, v69);
    nil = C_nil;
    if (exception_pending()) goto v66;
    env = stack[-3];
    v69 = Lneq(nil, stack[0], v69);
    nil = C_nil;
    if (exception_pending()) goto v66;
    env = stack[-3];
    if (v69 == nil) goto v52;
    v68 = elt(env, 2); /* rlisp */
    v67 = (Lisp_Object)337; /* 21 */
    v69 = elt(env, 3); /* "Incorrect array reference" */
    {
        popv(4);
        fn = elt(env, 5); /* rerror */
        return (*qfnn(fn))(qenv(fn), 3, v68, v67, v69);
    }

v52:
    v69 = stack[-1];
    v67 = qcar(v69);
    v69 = elt(env, 4); /* avalue */
    v69 = get(v67, v69);
    env = stack[-3];
    v69 = qcdr(v69);
    v68 = qcar(v69);
    v69 = stack[-1];
    v67 = qcdr(v69);
    v69 = stack[-2];
    {
        popv(4);
        fn = elt(env, 6); /* getel1 */
        return (*qfnn(fn))(qenv(fn), 3, v68, v67, v69);
    }
/* error exit handlers */
v66:
    popv(4);
    return nil;
}



/* Code for multd!* */

static Lisp_Object CC_multdH(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v29, v17, v18, v19;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v18 = v16;
    v19 = v0;
/* end of prologue */
    v17 = v19;
    v29 = (Lisp_Object)17; /* 1 */
    if (v17 == v29) return onevalue(v18);
    v29 = v19;
    v17 = v18;
    {
        fn = elt(env, 1); /* multd */
        return (*qfn2(fn))(qenv(fn), v29, v17);
    }
}



/* Code for negsq */

static Lisp_Object CC_negsq(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v2, v25;
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
    v2 = stack[0];
    v2 = qcar(v2);
    fn = elt(env, 1); /* negf */
    v25 = (*qfn1(fn))(qenv(fn), v2);
    nil = C_nil;
    if (exception_pending()) goto v24;
    v2 = stack[0];
    v2 = qcdr(v2);
    popv(1);
    return cons(v25, v2);
/* error exit handlers */
v24:
    popv(1);
    return nil;
}



/* Code for aconc!* */

static Lisp_Object CC_aconcH(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v1, v2;
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
    v1 = v16;
    v2 = v0;
/* end of prologue */
    stack[0] = v2;
    v1 = ncons(v1);
    nil = C_nil;
    if (exception_pending()) goto v13;
    {
        Lisp_Object v24 = stack[0];
        popv(1);
        return Lnconc(nil, v24, v1);
    }
/* error exit handlers */
v13:
    popv(1);
    return nil;
}



/* Code for carx */

static Lisp_Object CC_carx(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v22, v23, v30;
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
    v23 = v16;
    v30 = v0;
/* end of prologue */
    v22 = v30;
    v22 = qcdr(v22);
    if (v22 == nil) goto v4;
    stack[-1] = elt(env, 1); /* alg */
    stack[0] = (Lisp_Object)81; /* 5 */
    v22 = elt(env, 2); /* "Wrong number of arguments to" */
    v22 = list2(v22, v23);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-2];
    {
        Lisp_Object v14 = stack[-1];
        Lisp_Object v46 = stack[0];
        popv(3);
        fn = elt(env, 3); /* rerror */
        return (*qfnn(fn))(qenv(fn), 3, v14, v46, v22);
    }

v4:
    v22 = v30;
    v22 = qcar(v22);
    { popv(3); return onevalue(v22); }
/* error exit handlers */
v53:
    popv(3);
    return nil;
}



/* Code for mtchp */

static Lisp_Object MS_CDECL CC_mtchp(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v16,
                         Lisp_Object v63, Lisp_Object v9,
                         Lisp_Object v3, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v218, v219, v91, v235;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 5, "mtchp");
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
/* copy arguments values to proper place */
    stack[0] = v3;
    v218 = v9;
    stack[-1] = v63;
    stack[-2] = v16;
    stack[-3] = v0;
/* end of prologue */
    v235 = stack[-3];
    v91 = stack[-2];
    v219 = v218;
    v218 = stack[0];
    fn = elt(env, 1); /* mtchp1 */
    v218 = (*qfnn(fn))(qenv(fn), 4, v235, v91, v219, v218);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-5];
    stack[-4] = v218;
    goto v6;

v6:
    v218 = stack[-4];
    if (v218 == nil) goto v18;
    v218 = stack[-4];
    v219 = qcar(v218);
    v218 = stack[0];
    v218 = Lsubla(nil, v219, v218);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-5];
    fn = elt(env, 2); /* lispeval */
    v218 = (*qfn1(fn))(qenv(fn), v218);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-5];
    if (v218 == nil) goto v17;
    v218 = stack[-3];
    stack[0] = qcdr(v218);
    v218 = stack[-4];
    v219 = qcar(v218);
    v218 = stack[-2];
    v218 = qcdr(v218);
    v218 = Lsubla(nil, v219, v218);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-5];
    v218 = Ldivide(nil, stack[0], v218);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-5];
    stack[-2] = v218;
    v218 = stack[-4];
    v219 = qcar(v218);
    v218 = stack[-1];
    v218 = Lsubla(nil, v219, v218);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-5];
    fn = elt(env, 3); /* simp */
    v219 = (*qfn1(fn))(qenv(fn), v218);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-5];
    v218 = stack[-2];
    v218 = qcar(v218);
    fn = elt(env, 4); /* exptsq */
    v218 = (*qfn2(fn))(qenv(fn), v219, v218);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-5];
    stack[-1] = v218;
    v218 = stack[-2];
    v219 = qcdr(v218);
    v218 = (Lisp_Object)1; /* 0 */
    v218 = Lneq(nil, v219, v218);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-5];
    if (v218 == nil) { Lisp_Object res = stack[-1]; popv(6); return onevalue(res); }
    v218 = stack[-3];
    v219 = qcar(v218);
    v218 = stack[-2];
    v218 = qcdr(v218);
    fn = elt(env, 5); /* to */
    v219 = (*qfn2(fn))(qenv(fn), v219, v218);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-5];
    v218 = (Lisp_Object)17; /* 1 */
    v218 = cons(v219, v218);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-5];
    v219 = ncons(v218);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-5];
    v218 = (Lisp_Object)17; /* 1 */
    v219 = cons(v219, v218);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-5];
    v218 = stack[-1];
    fn = elt(env, 6); /* multsq */
    v218 = (*qfn2(fn))(qenv(fn), v219, v218);
    nil = C_nil;
    if (exception_pending()) goto v80;
    stack[-1] = v218;
    { Lisp_Object res = stack[-1]; popv(6); return onevalue(res); }

v17:
    v218 = stack[-4];
    v218 = qcdr(v218);
    stack[-4] = v218;
    goto v6;

v18:
    v218 = nil;
    { popv(6); return onevalue(v218); }
/* error exit handlers */
v80:
    popv(6);
    return nil;
}



/* Code for nb */

static Lisp_Object CC_nb(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v8;
    CSL_IGNORE(nil);
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v8 = v0;
/* end of prologue */
    if (v8 == nil) goto v5;
    v8 = (Lisp_Object)17; /* 1 */
    return onevalue(v8);

v5:
    v8 = (Lisp_Object)-15; /* -1 */
    return onevalue(v8);
}



/* Code for toknump */

static Lisp_Object CC_toknump(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v43, v29, v17;
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
    v43 = v29;
    v43 = (is_number(v43) ? lisp_true : nil);
    if (!(v43 == nil)) { popv(1); return onevalue(v43); }
    v17 = v29;
    v43 = elt(env, 1); /* !:dn!: */
    v43 = Leqcar(nil, v17, v43);
    env = stack[0];
    if (!(v43 == nil)) { popv(1); return onevalue(v43); }
    v43 = v29;
    v29 = elt(env, 2); /* !:int!: */
        popv(1);
        return Leqcar(nil, v43, v29);
}



/* Code for simpplus */

static Lisp_Object CC_simpplus(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v51, v42;
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
    v51 = stack[0];
    v42 = Llength(nil, v51);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-2];
    v51 = (Lisp_Object)33; /* 2 */
    if (!(v42 == v51)) goto v44;
    v51 = stack[0];
    fn = elt(env, 1); /* ckpreci!# */
    v51 = (*qfn1(fn))(qenv(fn), v51);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-2];
    goto v44;

v44:
    v42 = nil;
    v51 = (Lisp_Object)17; /* 1 */
    v51 = cons(v42, v51);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-2];
    stack[-1] = v51;
    goto v4;

v4:
    v51 = stack[0];
    if (v51 == nil) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v51 = stack[0];
    fn = elt(env, 2); /* simpcar */
    v42 = (*qfn1(fn))(qenv(fn), v51);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-2];
    v51 = stack[-1];
    fn = elt(env, 3); /* addsq */
    v51 = (*qfn2(fn))(qenv(fn), v42, v51);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-2];
    stack[-1] = v51;
    v51 = stack[0];
    v51 = qcdr(v51);
    stack[0] = v51;
    goto v4;
/* error exit handlers */
v52:
    popv(3);
    return nil;
}



/* Code for argnochk */

static Lisp_Object CC_argnochk(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v237, v121, v143;
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
    v237 = qvalue(elt(env, 1)); /* !*argnochk */
    if (v237 == nil) { Lisp_Object res = stack[-5]; popv(8); return onevalue(res); }
    v237 = stack[-5];
    v237 = qcar(v237);
    fn = elt(env, 9); /* argsofopr */
    v237 = (*qfn1(fn))(qenv(fn), v237);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-7];
    stack[-6] = v237;
    if (v237 == nil) { Lisp_Object res = stack[-5]; popv(8); return onevalue(res); }
    stack[0] = stack[-6];
    v237 = stack[-5];
    v237 = qcdr(v237);
    v237 = Llength(nil, v237);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-7];
    v237 = Lneq(nil, stack[0], v237);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-7];
    if (v237 == nil) { Lisp_Object res = stack[-5]; popv(8); return onevalue(res); }
    v237 = stack[-5];
    v121 = qcar(v237);
    v237 = elt(env, 2); /* simpfn */
    v237 = get(v121, v237);
    env = stack[-7];
    if (!(v237 == nil)) { Lisp_Object res = stack[-5]; popv(8); return onevalue(res); }
    v237 = stack[-5];
    v121 = qcar(v237);
    v237 = elt(env, 3); /* psopfn */
    v237 = get(v121, v237);
    env = stack[-7];
    if (!(v237 == nil)) { Lisp_Object res = stack[-5]; popv(8); return onevalue(res); }
    stack[-4] = elt(env, 4); /* rlisp */
    stack[-3] = (Lisp_Object)177; /* 11 */
    v237 = stack[-5];
    stack[-2] = qcar(v237);
    stack[-1] = elt(env, 5); /* "called with" */
    v237 = stack[-5];
    v237 = qcdr(v237);
    stack[0] = Llength(nil, v237);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-7];
    v237 = stack[-5];
    v237 = qcdr(v237);
    v121 = Llength(nil, v237);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-7];
    v237 = (Lisp_Object)17; /* 1 */
    if (v121 == v237) goto v61;
    v237 = elt(env, 7); /* "arguments" */
    v143 = v237;
    goto v103;

v103:
    v121 = elt(env, 8); /* "instead of" */
    v237 = stack[-6];
    v237 = list3(v143, v121, v237);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-7];
    v237 = list3star(stack[-2], stack[-1], stack[0], v237);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-7];
    fn = elt(env, 10); /* rerror */
    v237 = (*qfnn(fn))(qenv(fn), 3, stack[-4], stack[-3], v237);
    nil = C_nil;
    if (exception_pending()) goto v135;
    v237 = nil;
    { popv(8); return onevalue(v237); }

v61:
    v237 = elt(env, 6); /* "argument" */
    v143 = v237;
    goto v103;
/* error exit handlers */
v135:
    popv(8);
    return nil;
}



/* Code for mchk */

static Lisp_Object CC_mchk(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v16)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v258, v259, v154;
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
    stack[-3] = v16;
    stack[-4] = v0;
/* end of prologue */

v7:
    v259 = stack[-4];
    v258 = stack[-3];
    if (equal(v259, v258)) goto v5;
    v259 = stack[-4];
    v258 = elt(env, 1); /* !*sq */
    if (!consp(v259)) goto v53;
    v259 = qcar(v259);
    if (!(v259 == v258)) goto v53;
    v258 = stack[-4];
    v258 = qcdr(v258);
    v258 = qcar(v258);
    fn = elt(env, 7); /* prepsqxx */
    v258 = (*qfn1(fn))(qenv(fn), v258);
    nil = C_nil;
    if (exception_pending()) goto v260;
    env = stack[-6];
    stack[-4] = v258;
    goto v7;

v53:
    v259 = stack[-3];
    v258 = elt(env, 1); /* !*sq */
    if (!consp(v259)) goto v99;
    v259 = qcar(v259);
    if (!(v259 == v258)) goto v99;
    v258 = stack[-3];
    v258 = qcdr(v258);
    v258 = qcar(v258);
    fn = elt(env, 7); /* prepsqxx */
    v258 = (*qfn1(fn))(qenv(fn), v258);
    nil = C_nil;
    if (exception_pending()) goto v260;
    env = stack[-6];
    stack[-3] = v258;
    goto v7;

v99:
    v258 = stack[-3];
    if (!consp(v258)) goto v40;
    v258 = stack[-4];
    if (!consp(v258)) goto v58;
    v258 = stack[-3];
    v259 = qcar(v258);
    v258 = elt(env, 4); /* difference */
    if (v259 == v258) goto v138;
    v258 = stack[-4];
    v259 = qcar(v258);
    v258 = elt(env, 6); /* dname */
    v258 = get(v259, v258);
    env = stack[-6];
    if (!(v258 == nil)) goto v214;
    v258 = stack[-3];
    v259 = qcar(v258);
    v258 = elt(env, 6); /* dname */
    v258 = get(v259, v258);
    env = stack[-6];
    if (!(v258 == nil)) goto v214;
    v258 = stack[-4];
    v259 = qcar(v258);
    v258 = stack[-3];
    v258 = qcar(v258);
    if (v259 == v258) goto v261;
    v258 = stack[-3];
    v259 = qcar(v258);
    v258 = qvalue(elt(env, 2)); /* frlis!* */
    v258 = Lmemq(nil, v259, v258);
    if (v258 == nil) goto v262;
    v258 = stack[-4];
    v154 = qcar(v258);
    v258 = stack[-3];
    v259 = qcar(v258);
    v258 = stack[-4];
    v258 = qcdr(v258);
    stack[0] = Lsubst(nil, 3, v154, v259, v258);
    nil = C_nil;
    if (exception_pending()) goto v260;
    env = stack[-6];
    v258 = stack[-4];
    v154 = qcar(v258);
    v258 = stack[-3];
    v259 = qcar(v258);
    v258 = stack[-3];
    v258 = qcdr(v258);
    v259 = Lsubst(nil, 3, v154, v259, v258);
    nil = C_nil;
    if (exception_pending()) goto v260;
    env = stack[-6];
    v258 = stack[-4];
    v258 = qcar(v258);
    fn = elt(env, 8); /* mcharg */
    v258 = (*qfnn(fn))(qenv(fn), 3, stack[0], v259, v258);
    nil = C_nil;
    if (exception_pending()) goto v260;
    env = stack[-6];
    stack[-5] = v258;
    v258 = stack[-5];
    if (v258 == nil) goto v202;
    v258 = stack[-5];
    v258 = qcar(v258);
    v259 = stack[-3];
    v154 = qcar(v259);
    v259 = stack[-4];
    v259 = qcar(v259);
    v258 = acons(v154, v259, v258);
    nil = C_nil;
    if (exception_pending()) goto v260;
    env = stack[-6];
    v258 = ncons(v258);
    nil = C_nil;
    if (exception_pending()) goto v260;
    env = stack[-6];
    stack[-1] = v258;
    stack[-2] = v258;
    goto v263;

v263:
    v258 = stack[-5];
    v258 = qcdr(v258);
    stack[-5] = v258;
    v258 = stack[-5];
    if (v258 == nil) { Lisp_Object res = stack[-2]; popv(7); return onevalue(res); }
    stack[0] = stack[-1];
    v258 = stack[-5];
    v258 = qcar(v258);
    v259 = stack[-3];
    v154 = qcar(v259);
    v259 = stack[-4];
    v259 = qcar(v259);
    v258 = acons(v154, v259, v258);
    nil = C_nil;
    if (exception_pending()) goto v260;
    env = stack[-6];
    v258 = ncons(v258);
    nil = C_nil;
    if (exception_pending()) goto v260;
    env = stack[-6];
    v258 = Lrplacd(nil, stack[0], v258);
    nil = C_nil;
    if (exception_pending()) goto v260;
    env = stack[-6];
    v258 = stack[-1];
    v258 = qcdr(v258);
    stack[-1] = v258;
    goto v263;

v202:
    v258 = nil;
    { popv(7); return onevalue(v258); }

v262:
    v258 = stack[-4];
    v259 = qcar(v258);
    v258 = elt(env, 3); /* minus */
    if (v259 == v258) goto v264;
    v259 = stack[-4];
    v258 = stack[-3];
    {
        popv(7);
        fn = elt(env, 9); /* mchkopt */
        return (*qfn2(fn))(qenv(fn), v259, v258);
    }

v264:
    v258 = stack[-4];
    v258 = qcdr(v258);
    v259 = qcar(v258);
    v258 = stack[-3];
    {
        popv(7);
        fn = elt(env, 10); /* mchkminus */
        return (*qfn2(fn))(qenv(fn), v259, v258);
    }

v261:
    v258 = stack[-4];
    v154 = qcdr(v258);
    v258 = stack[-3];
    v259 = qcdr(v258);
    v258 = stack[-4];
    v258 = qcar(v258);
    {
        popv(7);
        fn = elt(env, 8); /* mcharg */
        return (*qfnn(fn))(qenv(fn), 3, v154, v259, v258);
    }

v214:
    v258 = nil;
    { popv(7); return onevalue(v258); }

v138:
    stack[-1] = elt(env, 5); /* plus */
    v258 = stack[-3];
    v258 = qcdr(v258);
    stack[0] = qcar(v258);
    v259 = elt(env, 3); /* minus */
    v258 = stack[-3];
    v258 = qcdr(v258);
    v258 = qcdr(v258);
    v258 = qcar(v258);
    v258 = list2(v259, v258);
    nil = C_nil;
    if (exception_pending()) goto v260;
    env = stack[-6];
    v258 = list3(stack[-1], stack[0], v258);
    nil = C_nil;
    if (exception_pending()) goto v260;
    env = stack[-6];
    stack[-3] = v258;
    goto v7;

v58:
    v258 = stack[-4];
    if (!(is_number(v258))) goto v118;
    v259 = stack[-4];
    v258 = (Lisp_Object)1; /* 0 */
    v258 = (Lisp_Object)lessp2(v259, v258);
    nil = C_nil;
    if (exception_pending()) goto v260;
    v258 = v258 ? lisp_true : nil;
    env = stack[-6];
    if (v258 == nil) goto v118;
    v259 = stack[-3];
    v258 = elt(env, 3); /* minus */
    if (!consp(v259)) goto v118;
    v259 = qcar(v259);
    if (!(v259 == v258)) goto v118;
    stack[0] = elt(env, 3); /* minus */
    v258 = stack[-4];
    v258 = negate(v258);
    nil = C_nil;
    if (exception_pending()) goto v260;
    env = stack[-6];
    v258 = list2(stack[0], v258);
    nil = C_nil;
    if (exception_pending()) goto v260;
    env = stack[-6];
    stack[-4] = v258;
    goto v7;

v118:
    v259 = stack[-4];
    v258 = stack[-3];
    {
        popv(7);
        fn = elt(env, 9); /* mchkopt */
        return (*qfn2(fn))(qenv(fn), v259, v258);
    }

v40:
    v259 = stack[-3];
    v258 = qvalue(elt(env, 2)); /* frlis!* */
    v258 = Lmemq(nil, v259, v258);
    if (v258 == nil) goto v57;
    v259 = stack[-3];
    v258 = stack[-4];
    v258 = cons(v259, v258);
    nil = C_nil;
    if (exception_pending()) goto v260;
    env = stack[-6];
    v258 = ncons(v258);
    nil = C_nil;
    if (exception_pending()) goto v260;
    popv(7);
    return ncons(v258);

v57:
    v258 = nil;
    { popv(7); return onevalue(v258); }

v5:
    v258 = nil;
    popv(7);
    return ncons(v258);
/* error exit handlers */
v260:
    popv(7);
    return nil;
}



/* Code for sqchk */

static Lisp_Object CC_sqchk(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v36, v48, v33;
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
    v48 = v0;
/* end of prologue */
    v36 = v48;
    if (!consp(v36)) { popv(1); return onevalue(v48); }
    v36 = v48;
    v33 = qcar(v36);
    v36 = elt(env, 1); /* prepfn2 */
    v36 = get(v33, v36);
    env = stack[0];
    v33 = v36;
    v36 = v33;
    if (v36 == nil) goto v15;
    v36 = v33;
        popv(1);
        return Lapply1(nil, v36, v48);

v15:
    v36 = v48;
    v36 = qcar(v36);
    if (!consp(v36)) { popv(1); return onevalue(v48); }
    v36 = v48;
    {
        popv(1);
        fn = elt(env, 2); /* prepf */
        return (*qfn1(fn))(qenv(fn), v36);
    }
}



setup_type const u01_setup[] =
{
    {"noncomp",                 CC_noncomp,     too_many_1,    wrong_no_1},
    {"simpcar",                 CC_simpcar,     too_many_1,    wrong_no_1},
    {"reval",                   CC_reval,       too_many_1,    wrong_no_1},
    {"terminalp",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_terminalp},
    {"delcp",                   CC_delcp,       too_many_1,    wrong_no_1},
    {"argsofopr",               CC_argsofopr,   too_many_1,    wrong_no_1},
    {"num-exponents",           CC_numKexponents,too_many_1,   wrong_no_1},
    {"mchkopt",                 too_few_2,      CC_mchkopt,    wrong_no_2},
    {"exchk",                   CC_exchk,       too_many_1,    wrong_no_1},
    {"*ssave",                  too_few_2,      CC_Hssave,     wrong_no_2},
    {"noncomfp",                CC_noncomfp,    too_many_1,    wrong_no_1},
    {"*d2q",                    CC_Hd2q,        too_many_1,    wrong_no_1},
    {"getrtypeor",              CC_getrtypeor,  too_many_1,    wrong_no_1},
    {"arraychk",                CC_arraychk,    too_many_1,    wrong_no_1},
    {"arrayp",                  CC_arrayp,      too_many_1,    wrong_no_1},
    {"noncomfp1",               CC_noncomfp1,   too_many_1,    wrong_no_1},
    {"noncomp1",                CC_noncomp1,    too_many_1,    wrong_no_1},
    {"reval_without_mod",       CC_reval_without_mod,too_many_1,wrong_no_1},
    {"getrtypecar",             CC_getrtypecar, too_many_1,    wrong_no_1},
    {"addcomment",              CC_addcomment,  too_many_1,    wrong_no_1},
    {"prin2x",                  CC_prin2x,      too_many_1,    wrong_no_1},
    {"degr",                    too_few_2,      CC_degr,       wrong_no_2},
    {"noncomlistp",             CC_noncomlistp, too_many_1,    wrong_no_1},
    {"mchk*",                   too_few_2,      CC_mchkH,      wrong_no_2},
    {"ordop",                   too_few_2,      CC_ordop,      wrong_no_2},
    {"smember",                 too_few_2,      CC_smember,    wrong_no_2},
    {"timesip",                 CC_timesip,     too_many_1,    wrong_no_1},
    {"expchk",                  CC_expchk,      too_many_1,    wrong_no_1},
    {"readch1",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_readch1},
    {":zerop",                  CC_Tzerop,      too_many_1,    wrong_no_1},
    {"*q2a1",                   too_few_2,      CC_Hq2a1,      wrong_no_2},
    {"multd",                   too_few_2,      CC_multd,      wrong_no_2},
    {"subs2f",                  CC_subs2f,      too_many_1,    wrong_no_1},
    {"aeval*",                  CC_aevalH,      too_many_1,    wrong_no_1},
    {"hevenp",                  CC_hevenp,      too_many_1,    wrong_no_1},
    {"aconc",                   too_few_2,      CC_aconc,      wrong_no_2},
    {"add_prin_char",           too_few_2,      CC_add_prin_char,wrong_no_2},
    {"mkvar",                   too_few_2,      CC_mkvar,      wrong_no_2},
    {"getrtype",                CC_getrtype,    too_many_1,    wrong_no_1},
    {"noncomdel",               too_few_2,      CC_noncomdel,  wrong_no_2},
    {"subs2q",                  CC_subs2q,      too_many_1,    wrong_no_1},
    {"prepf1",                  too_few_2,      CC_prepf1,     wrong_no_2},
    {"negnumberchk",            CC_negnumberchk,too_many_1,    wrong_no_1},
    {"prepf",                   CC_prepf,       too_many_1,    wrong_no_1},
    {"noncomp*",                CC_noncompH,    too_many_1,    wrong_no_1},
    {"getrtype2",               CC_getrtype2,   too_many_1,    wrong_no_1},
    {"addf",                    too_few_2,      CC_addf,       wrong_no_2},
    {"multsq",                  too_few_2,      CC_multsq,     wrong_no_2},
    {"getel1",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_getel1},
    {"multf",                   too_few_2,      CC_multf,      wrong_no_2},
    {"replus",                  CC_replus,      too_many_1,    wrong_no_1},
    {"quotf",                   too_few_2,      CC_quotf,      wrong_no_2},
    {"addsq",                   too_few_2,      CC_addsq,      wrong_no_2},
    {"getpower",                too_few_2,      CC_getpower,   wrong_no_2},
    {"prin2*",                  CC_prin2H,      too_many_1,    wrong_no_1},
    {"ordpp",                   too_few_2,      CC_ordpp,      wrong_no_2},
    {"scprint",                 too_few_2,      CC_scprint,    wrong_no_2},
    {"mtp",                     CC_mtp,         too_many_1,    wrong_no_1},
    {"getelv",                  CC_getelv,      too_many_1,    wrong_no_1},
    {"reval2",                  too_few_2,      CC_reval2,     wrong_no_2},
    {"retimes",                 CC_retimes,     too_many_1,    wrong_no_1},
    {"mtchp1",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_mtchp1},
    {"mapcons",                 too_few_2,      CC_mapcons,    wrong_no_2},
    {"exptchksq",               CC_exptchksq,   too_many_1,    wrong_no_1},
    {"gcdfd1",                  too_few_2,      CC_gcdfd1,     wrong_no_2},
    {"getel",                   CC_getel,       too_many_1,    wrong_no_1},
    {"multd*",                  too_few_2,      CC_multdH,     wrong_no_2},
    {"negsq",                   CC_negsq,       too_many_1,    wrong_no_1},
    {"aconc*",                  too_few_2,      CC_aconcH,     wrong_no_2},
    {"carx",                    too_few_2,      CC_carx,       wrong_no_2},
    {"mtchp",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_mtchp},
    {"nb",                      CC_nb,          too_many_1,    wrong_no_1},
    {"toknump",                 CC_toknump,     too_many_1,    wrong_no_1},
    {"simpplus",                CC_simpplus,    too_many_1,    wrong_no_1},
    {"argnochk",                CC_argnochk,    too_many_1,    wrong_no_1},
    {"mchk",                    too_few_2,      CC_mchk,       wrong_no_2},
    {"sqchk",                   CC_sqchk,       too_many_1,    wrong_no_1},
    {NULL, (one_args *)"u01", (two_args *)"11795 1957612 497023", 0}
};

/* end of generated code */
