
/* $destdir/u45.c        Machine generated C code */

/* $Id: $ */

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
#if !defined UNDER_CE && !defined EMBEDDED
#if ((defined HAVE_SOCKET && defined HAVE_SYS_SOCKET_H) || defined WIN32)
#define SOCKETS                  1
#endif
#endif
#ifndef MS_CDECL
#ifdef _MSC_VER
#  define MS_CDECL __cdecl
#else
#  define MS_CDECL
#endif
#endif
#ifdef WIN32
#  if defined WIN64 || defined __WIN64__
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
#ifdef __cplusplus
#define __STDC_CONSTANT_MACROS 1
#endif
#include <stdint.h>
#else 
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
#endif 
#ifndef header_tags_h
#define header_tags_h 1
#if !defined HAVE_STDINT_H || !defined HAVE_INT32_T
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
#  define MAX_HEAPSIZE       (SIXTY_FOUR_BIT ? (512*1024) : 2048)
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
#define cdr32(p) (*(int32_t *)(p))[1])
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
#define TYPE_FOREIGN        TYPE_SPARE 
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
#define is_spid(x)   (((int)(x) & ODDS_MASK) == TAG_SPID)
#define is_library(x)(((int)(x) & 0xffff)    == SPID_LIBRARY)
#define library_number(x) (((x) >> 20) & 0xfff)
#define font_of_char(n)  (((int32_t)(n) >> 29) & 0x03)
#define bits_of_char(n)  (0)
#define code_of_char(n)  (((int32_t)(n) >>  8) & 0x001fffff)
#define pack_char(font, code)                                      \
    ((Lisp_Object)((((uint32_t)(font)) << 29) |                    \
                   (((uint32_t)(code)) << 8) | TAG_CHAR))
    
#define CHAR_EOF pack_char(0, 0x0010ffff)
#define data_of_bps(v)                                        \
  ((char *)(doubleword_align_up((intptr_t)                    \
               bps_pages[((uint32_t)(v))>>(PAGE_BITS+6)]) +   \
            (SIXTY_FOUR_BIT ?                                 \
               (intptr_t)((((uint64_t)(v))>>(32-PAGE_BITS)) & \
                          PAGE_POWER_OF_TWO) :                \
               0) +                                           \
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
#define word_align_up(n) ((Lisp_Object)(((intptr_t)(n) + 3) & (-4)))
#define doubleword_align_up(n) ((Lisp_Object)(((intptr_t)(n) + 7) & (-8)))
#define doubleword_align_down(n) ((Lisp_Object)((intptr_t)(n) & (-8)))
#define object_align_up(n) ((Lisp_Object)(((intptr_t)(n) + \
                            sizeof(Lisp_Object) - 1) & (-sizeof(Lisp_Object))))
#define quadword_align_up(n) ((Lisp_Object)(((intptr_t)(n) + 15) & (-16)))
#define quadword_align_down(n) ((Lisp_Object)((intptr_t)(n) & (-16)))
#define UNWIND_NULL       0x0         
#define UNWIND_GO         0x1         
#define UNWIND_RETURN     0x2         
#define UNWIND_THROW      0x3         
#define UNWIND_RESTART    0x4         
#define UNWIND_RESOURCE   0x5         
#define UNWIND_FNAME      0x100       
#define UNWIND_ARGS       0x200       
#define UNWIND_ERROR      (UNWIND_FNAME|UNWIND_ARGS)
#define UNWIND_UNWIND     0x400       
#if 0 && defined DEBUG
#define SHOW_FNAME  (exit_reason == UNWIND_THROW || \
                     (exit_reason & UNWIND_FNAME) != 0)
#define SHOW_ARGS   (exit_reason == UNWIND_THROW || \
                     (exit_reason & UNWIND_ARGS) != 0)
#else
#define SHOW_FNAME  ((exit_reason & UNWIND_FNAME) != 0)
#define SHOW_ARGS   ((exit_reason & UNWIND_ARGS) != 0)
#endif
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
#define verbos_flag (miscflags & GC_MSG_BITS)
#define HEADLINE_FLAG 0x08
#define FNAME_FLAG    0x10
#define ARGS_FLAG     0x20
#define BACKTRACE_MSG_BITS 0x38
 
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
#define err_no_longer_used       34      
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
    "this error code available for re-use",
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
extern int32_t pages_count,
               heap_pages_count, vheap_pages_count,
               bps_pages_count, native_pages_count;
extern int32_t new_heap_pages_count, new_vheap_pages_count,
               new_bps_pages_count, new_native_pages_count;
extern int32_t native_pages_changed;
extern int32_t native_fringe;
extern Lisp_Object *nilsegment, *stacksegment;
extern Lisp_Object *stackbase;
extern int32_t stack_segsize;  
extern Lisp_Object *C_stack;
#define stack C_stack
extern char *C_stack_base, *C_stack_limit;
extern double max_store_size;
extern CSLbool restartp;
extern char *big_chunk_start, *big_chunk_end;
#ifdef CONSERVATIVE
extern Lisp_Object *C_stackbase, *C_stacktop;
#endif
extern Lisp_Object multiplication_buffer;
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
extern volatile char stack_contents_temp;
#ifdef CHECK_STACK
extern int check_stack(char *file, int line);
extern void show_stack();
#define if_check_stack \
   if (check_stack("@" __FILE__,__LINE__)) \
   {   show_stack(); return aerror("stack overflow"); }
#else
#define if_check_stack \
   {   char *p = (char *)&p; \
       if (p < C_stack_limit) return aerror("stack overflow"); \
   }
#endif
extern int32_t software_ticks, countdown;
#ifdef DEBUG
extern char debug_trail[32][32];
extern char debug_trail_file[32][32];
extern int debug_trail_line[32];
extern int debug_trailp;
extern void debug_record_raw(const char *data, const char *file, int line);
extern void debug_record_int_raw(const char *s, int n, const char *file, int line);
extern void debug_show_trail_raw(const char *msg, const char *file, int line);
#define debug_record(data) debug_record_raw(data, __FILE__, __LINE__)
#define debug_record_int(s, n) debug_record_int_raw(s, n, __FILE__, __LINE__)
#define debug_record_string(s) debug_record(&celt(s, 0))
#define debug_record_symbol(x) debug_record_string(qpname(x))
#define debug_show_trail(data) debug_show_trail_raw(data, __FILE__, __LINE__)
#define debug_assert(x) \
  if (!(x)) { debug_show_trail("Assertion failed"); exit(7); }
#else
#define debug_record(data)
#define debug_record_int(s, n)
#define debug_record_string(s)
#define debug_record_symbol(x)
#define debug_show_trail(x)
#define debug_assert(x)
#endif
extern volatile int blipflag;
extern int64_t blipcount, startblip;
#if defined __linux__ && defined DEBUG
#define HANDLE_BLIP                                                       \
    if (blipflag)                                                         \
    {   blipflag = 0;                                                     \
        if (startblip >= 0 && ++blipcount > startblip)                    \
        {   fprintf(stderr, "Line %d of file %s\n", __LINE__, __FILE__);  \
            fflush(stderr);                                               \
        }                                                                 \
    }
#else
#define HANDLE_BLIP
#endif
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
extern intptr_t byteflip;
extern Lisp_Object codefringe;
extern Lisp_Object volatile codelimit;
extern Lisp_Object * volatile stacklimit;
extern Lisp_Object fringe;
extern Lisp_Object volatile heaplimit;
extern Lisp_Object volatile vheaplimit;
extern Lisp_Object vfringe;
extern intptr_t nwork;
extern intptr_t exit_count;
extern intptr_t gensym_ser, print_precision, miscflags;
extern intptr_t current_modulus, fastget_size, package_bits;
extern intptr_t modulus_is_large;
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
extern Lisp_Object gchook, resources, callstack, procstack, procmem;
extern Lisp_Object trap_time, count_high;
#ifdef COMMON
extern Lisp_Object keyword_package;
extern Lisp_Object all_packages, package_symbol, internal_symbol;
extern Lisp_Object external_symbol, inherited_symbol;
extern Lisp_Object key_key, allow_other_keys, aux_key;
extern Lisp_Object format_symbol;
extern Lisp_Object expand_def_symbol, allow_key_key;
#endif
extern Lisp_Object declare_symbol, special_symbol, large_modulus;
extern Lisp_Object used_space, avail_space, eof_symbol, call_stack;
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
#define byteflip              BASE[12]
#define codefringe            BASE[13]
#define codelimit             (*(Lisp_Object volatile *)&BASE[14])
extern Lisp_Object * volatile stacklimit;
#define fringe                BASE[18]
#define heaplimit             (*(Lisp_Object volatile *)&BASE[19])
#define vheaplimit            (*(Lisp_Object volatile *)&BASE[20])
#define vfringe               BASE[21]
#define miscflags             BASE[22]
#define nwork                 BASE[24]
#define exit_count            BASE[26]
#define gensym_ser            BASE[27]
#define print_precision       BASE[28]
#define current_modulus       BASE[29]
#define fastget_size          BASE[30]
#define package_bits          BASE[31]
#define modulus_is_large      BASE[32]
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
#define procstack             BASE[156]
#define procmem               BASE[157]
#define trap_time             BASE[158]
#define count_high            BASE[159]
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
#endif
#define declare_symbol        BASE[182]
#define special_symbol        BASE[183]
#define large_modulus         BASE[184]
#define used_space            BASE[185]
#define avail_space           BASE[186]
#define eof_symbol            BASE[187]
#define call_stack            BASE[188]
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
extern intptr_t exit_reason;
extern int procstackp;
#ifdef DEBUG
extern int trace_all;
#endif
#ifndef NO_BYTECOUNT
extern const char *name_of_caller;
#endif
extern int garbage_collection_permitted;
#define MAX_INPUT_FILES         40  
#define MAX_SYMBOLS_TO_DEFINE   40
#define MAX_FASL_PATHS          20
extern char *files_to_read[MAX_INPUT_FILES],
     *symbols_to_define[MAX_SYMBOLS_TO_DEFINE],
     *fasl_paths[MAX_FASL_PATHS];
extern int csl_argc;
extern char **csl_argv;
extern int fasl_output_file, output_directory;
#ifdef BUILTIN_IMAGE
const unsigned char *binary_read_filep;
#else
extern FILE *binary_read_file;
#endif
extern int boffop;
extern void packbyte(int c);
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
extern int errorset_min, errorset_max;
extern int number_of_input_files,
    number_of_symbols_to_define,
    number_of_fasl_paths,
    init_flags;
extern int native_code_tag;
extern char *standard_directory;
extern int gc_number;
extern CSLbool gc_method_is_copying;
extern int force_reclaim_method, reclaim_trap_count, reclaim_stack_limit;
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
extern void *extract_pointer(Lisp_Object a);
extern Lisp_Object Lencapsulatedp(Lisp_Object nil, Lisp_Object a);
typedef void initfn(Lisp_Object *, Lisp_Object **, Lisp_Object * volatile *);
extern int load_dynamic(char *objname, char *modname,
                        Lisp_Object name, Lisp_Object fns);
extern Lisp_Object Linstate_c_code(Lisp_Object nil,
                                   Lisp_Object name, Lisp_Object fns);
extern Lisp_Object characterify(Lisp_Object a);
extern Lisp_Object char_to_id(int ch);
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
extern const char *CSLtmpdir();
extern const char *CSLtmpnam(char *suffix, int32_t suffixlen);
extern int Cmkdir(char *s);
extern char *look_in_lisp_variable(char *o, int prefix);
extern void CSL_MD5_Init(void);
extern void CSL_MD5_Update(const unsigned char *data, int len);
extern void CSL_MD5_Final(unsigned char *md);
extern CSLbool CSL_MD5_busy;
extern unsigned char *CSL_MD5(unsigned char *data, int n, unsigned char *md);
extern void checksum(Lisp_Object a);
extern unsigned char unpredictable[256];
extern void inject_randomness(int n);
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
#ifdef USE_SIGALTSTACK
extern sigjmp_buf *errorset_buffer;
extern sigjmp_buf my_exit_buffer;
#else
extern jmp_buf *errorset_buffer;
extern jmp_buf my_exit_buffer;
#endif
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
extern Lisp_Object noisy_Ceval(Lisp_Object u, Lisp_Object env);
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
                         Lisp_Object env, Lisp_Object fname, int noisy);
extern Lisp_Object apply_lambda(Lisp_Object def, int nargs,
                         Lisp_Object env, Lisp_Object name, int noisy);
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
                              size_t n, const char *dirn, FILE *old_file);
extern Lisp_Object plus2(Lisp_Object a, Lisp_Object b);
extern void        preserve(char *msg, int len);
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
#ifdef DEBUG
extern void validate_all(char *why, int line, char *file);
extern int check_env(Lisp_Object env);
#endif
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
#ifdef DEBUG
extern void validate_string_fn(Lisp_Object a, char *f, int l);
#define validate_string(a) validate_string_fn(a, __FILE__, __LINE__)
#else
#define validate_string(a) 
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
#define noisy_eval(a, b) noisy_Ceval(a, b)
#define noisy_voideval(a, b) noisy_Ceval(a, b)
#else
#define eval(a, b) \
    (is_cons(a) ? Ceval(a, b) : \
     is_symbol(a) ? (qvalue(a) == unset_var ? error(1, err_unset_var, a) : \
                     onevalue(qvalue(a))) : \
     onevalue(a))
#define voideval(a, b) \
    if (is_cons(a)) Ceval(a, b) 
#define noisy_eval(a, b) \
    (is_cons(a) ? noisy_Ceval(a, b) : \
     is_symbol(a) ? (qvalue(a) == unset_var ? error(1, err_unset_var, a) : \
                     onevalue(qvalue(a))) : \
     onevalue(a))
#define noisy_voideval(a, b) \
    if (is_cons(a)) noisy_Ceval(a, b) 
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
       u05_setup[], u06_setup[], u07_setup[], u08_setup[], u09_setup[],
       u10_setup[], u11_setup[], u12_setup[], u13_setup[], u14_setup[],
       u15_setup[], u16_setup[], u17_setup[], u18_setup[], u19_setup[],
       u20_setup[], u21_setup[], u22_setup[], u23_setup[], u24_setup[],
       u25_setup[], u26_setup[], u27_setup[], u28_setup[], u29_setup[],
       u30_setup[], u31_setup[], u32_setup[], u33_setup[], u34_setup[],
       u35_setup[], u36_setup[], u37_setup[], u38_setup[], u39_setup[],
       u40_setup[], u41_setup[], u42_setup[], u43_setup[], u44_setup[],
       u45_setup[], u46_setup[], u47_setup[], u48_setup[], u49_setup[],
       u50_setup[], u51_setup[], u52_setup[], u53_setup[], u54_setup[],
       u55_setup[], u56_setup[], u57_setup[], u58_setup[], u59_setup[],
       u60_setup[];
extern setup_type const *setup_tables[];
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
                            Lisp_Object env, int compilerp, int noisy);
extern Lisp_Object mv_call_fn(Lisp_Object args, Lisp_Object env);
extern Lisp_Object noisy_mv_call_fn(Lisp_Object args, Lisp_Object env);
extern Lisp_Object progn_fn(Lisp_Object args, Lisp_Object env);
extern Lisp_Object noisy_progn_fn(Lisp_Object args, Lisp_Object env);
extern Lisp_Object quote_fn(Lisp_Object args, Lisp_Object env);
extern Lisp_Object tagbody_fn(Lisp_Object args, Lisp_Object env);
extern Lisp_Object noisy_tagbody_fn(Lisp_Object args, Lisp_Object env);
extern Lisp_Object resource_exceeded();
extern int64_t time_base,  space_base,  io_base,  errors_base;
extern int64_t time_now,   space_now,   io_now,   errors_now;
extern int64_t time_limit, space_limit, io_limit, errors_limit;
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
#define _pi       ((12868.0 - 0.036490896206895257)/4096.0)
#define _half_pi  ((12868.0 - 0.036490896206895257)/8192.0)
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
extern Lisp_Object make_three_word_bignum(int32_t a, uint32_t b, uint32_t c);
extern Lisp_Object make_n_word_bignum(int32_t a1, uint32_t a2,
                                      uint32_t a3, int32_t n);
extern Lisp_Object make_lisp_integer32(int32_t n);
extern Lisp_Object make_lisp_integer64(int64_t n);
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
#if defined HAVE_LIBPTHREAD || defined WIN32
#include <semaphore.h>
#ifdef WIN32
#include <windows.h>
extern HANDLE kara_thread1, kara_thread2;
#define KARARESULT DWORD
#define KARAARG    LPVOID
extern KARARESULT WINAPI kara_worker1(KARAARG p);
extern KARARESULT WINAPI kara_worker2(KARAARG p);
#else
#include <pthread.h>
extern pthread_t kara_thread1, kara_thread2;
#define KARARESULT void *
#define KARAARG    void *
#define WINAPI
extern KARARESULT kara_worker1(KARAARG p);
extern KARARESULT kara_worker2(KARAARG p);
#endif
#ifdef MACINTOSH
extern sem_t *kara_sem1a, *kara_sem1b, *kara_sem1c,
             *kara_sem2a, *kara_sem2b, *kara_sem2c;
#else
extern sem_t kara_sem1a, kara_sem1b, kara_sem1c,
             kara_sem2a, kara_sem2b, kara_sem2c;
#endif
extern int karatsuba_parallel;
#ifndef KARATSUBA_PARALLEL_CUTOFF
#  define KARATSUBA_PARALLEL_CUTOFF 120
#endif
#endif 
#ifndef KARATSUBA_CUTOFF
#define KARATSUBA_CUTOFF 12
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
extern Lisp_Object bytecounts1(Lisp_Object env, Lisp_Object a);
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
extern Lisp_Object tracesetfunarged1(Lisp_Object env, Lisp_Object a1);
extern Lisp_Object hardopt1(Lisp_Object def, Lisp_Object a);
extern Lisp_Object hardoptrest1(Lisp_Object def, Lisp_Object a);
extern Lisp_Object interpreted1(Lisp_Object env, Lisp_Object a1);
extern Lisp_Object tracebytecoded1(Lisp_Object env, Lisp_Object a);
extern Lisp_Object tracesetbytecoded1(Lisp_Object env, Lisp_Object a);
extern Lisp_Object jitcompileme1(Lisp_Object env, Lisp_Object a);
extern Lisp_Object tracebyteopt1(Lisp_Object def, Lisp_Object a);
extern Lisp_Object tracesetbyteopt1(Lisp_Object def, Lisp_Object a);
extern Lisp_Object tracebyteoptrest1(Lisp_Object def, Lisp_Object a);
extern Lisp_Object tracesetbyteoptrest1(Lisp_Object def, Lisp_Object a);
extern Lisp_Object tracebytecoded1(Lisp_Object env, Lisp_Object a);
extern Lisp_Object tracesetbytecoded1(Lisp_Object env, Lisp_Object a);
extern Lisp_Object traceinterpreted1(Lisp_Object env, Lisp_Object a1);
extern Lisp_Object tracesetinterpreted1(Lisp_Object env, Lisp_Object a1);
extern Lisp_Object tracehardopt1(Lisp_Object def, Lisp_Object a);
extern Lisp_Object tracesethardopt1(Lisp_Object def, Lisp_Object a);
extern Lisp_Object tracehardoptrest1(Lisp_Object def, Lisp_Object a);
extern Lisp_Object tracesethardoptrest1(Lisp_Object def, Lisp_Object a);
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
extern Lisp_Object Lthrow_nil(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Ltrace(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Ltraceset(Lisp_Object env, Lisp_Object a);
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
extern Lisp_Object tracesetfunarged2(Lisp_Object env, Lisp_Object a1, Lisp_Object a2);
extern Lisp_Object hardopt2(Lisp_Object def, Lisp_Object a, Lisp_Object b);
extern Lisp_Object hardoptrest2(Lisp_Object def, Lisp_Object a, Lisp_Object b);
extern Lisp_Object interpreted2(Lisp_Object env, Lisp_Object a1, Lisp_Object a2);
extern Lisp_Object tracebyteopt2(Lisp_Object def, Lisp_Object a, Lisp_Object b);
extern Lisp_Object tracesetbyteopt2(Lisp_Object def, Lisp_Object a, Lisp_Object b);
extern Lisp_Object tracebyteoptrest2(Lisp_Object def, Lisp_Object a, Lisp_Object b);
extern Lisp_Object tracesetbyteoptrest2(Lisp_Object def, Lisp_Object a, Lisp_Object b);
extern Lisp_Object tracebytecoded2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object tracesetbytecoded2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object jitcompileme2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object traceinterpreted2(Lisp_Object env, Lisp_Object a1, Lisp_Object a2);
extern Lisp_Object tracesetinterpreted2(Lisp_Object env, Lisp_Object a1, Lisp_Object a2);
extern Lisp_Object tracehardopt2(Lisp_Object def, Lisp_Object a, Lisp_Object b);
extern Lisp_Object tracesethardopt2(Lisp_Object def, Lisp_Object a, Lisp_Object b);
extern Lisp_Object tracehardoptrest2(Lisp_Object def, Lisp_Object a, Lisp_Object b);
extern Lisp_Object tracesethardoptrest2(Lisp_Object def, Lisp_Object a, Lisp_Object b);
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
extern Lisp_Object Lthrow_one_value(Lisp_Object env, Lisp_Object a, Lisp_Object b);
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
extern Lisp_Object MS_CDECL tracesetfunargedn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL hardoptn(Lisp_Object def, int nargs, ...);
extern Lisp_Object MS_CDECL hardoptrestn(Lisp_Object def, int nargs, ...);
extern Lisp_Object MS_CDECL interpretedn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL tracebyteoptn(Lisp_Object def, int nargs, ...);
extern Lisp_Object MS_CDECL tracesetbyteoptn(Lisp_Object def, int nargs, ...);
extern Lisp_Object MS_CDECL tracebyteoptrestn(Lisp_Object def, int nargs, ...);
extern Lisp_Object MS_CDECL tracesetbyteoptrestn(Lisp_Object def, int nargs, ...);
extern Lisp_Object MS_CDECL tracebytecoded0(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL tracesetbytecoded0(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL tracebytecoded3(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL tracesetbytecoded3(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL tracebytecodedn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL tracesetbytecodedn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL jitcompileme0(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL jitcompileme3(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL jitcompilemen(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL traceinterpretedn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL tracesetinterpretedn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL tracehardoptn(Lisp_Object def, int nargs, ...);
extern Lisp_Object MS_CDECL tracesethardoptn(Lisp_Object def, int nargs, ...);
extern Lisp_Object MS_CDECL tracehardoptrestn(Lisp_Object def, int nargs, ...);
extern Lisp_Object MS_CDECL tracesethardoptrestn(Lisp_Object def, int nargs, ...);
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


/* Code for sqfrf */

static Lisp_Object CC_sqfrf(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0097, v0098, v0099, v0100;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sqfrf");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-9] = v0000;
/* end of prologue */
    stack[-8] = qvalue(elt(env, 1)); /* !*gcd */
    qvalue(elt(env, 1)) = nil; /* !*gcd */
    stack[-7] = nil;
    stack[-3] = nil;
    stack[-2] = nil;
    stack[-5] = qvalue(elt(env, 2)); /* !*msg */
    qvalue(elt(env, 2)) = nil; /* !*msg */
    v0097 = qvalue(elt(env, 3)); /* t */
    qvalue(elt(env, 1)) = v0097; /* !*gcd */
    v0097 = qvalue(elt(env, 4)); /* !*rounded */
    stack[-1] = v0097;
    if (v0097 == nil) goto v0101;
    v0097 = elt(env, 5); /* rational */
    v0097 = ncons(v0097);
    nil = C_nil;
    if (exception_pending()) goto v0102;
    env = stack[-11];
    fn = elt(env, 12); /* on */
    v0097 = (*qfn1(fn))(qenv(fn), v0097);
    nil = C_nil;
    if (exception_pending()) goto v0102;
    env = stack[-11];
    v0098 = stack[-9];
    v0097 = (Lisp_Object)17; /* 1 */
    v0097 = cons(v0098, v0097);
    nil = C_nil;
    if (exception_pending()) goto v0102;
    env = stack[-11];
    fn = elt(env, 13); /* resimp */
    v0097 = (*qfn1(fn))(qenv(fn), v0097);
    nil = C_nil;
    if (exception_pending()) goto v0102;
    env = stack[-11];
    v0097 = qcar(v0097);
    stack[-9] = v0097;
    goto v0101;

v0101:
    v0097 = (Lisp_Object)17; /* 1 */
    stack[-10] = v0097;
    v0097 = stack[-9];
    v0097 = qcar(v0097);
    v0097 = qcar(v0097);
    v0097 = qcar(v0097);
    stack[-4] = v0097;
    v0097 = qvalue(elt(env, 3)); /* t */
    stack[0] = qvalue(elt(env, 6)); /* !*ezgcd */
    qvalue(elt(env, 6)) = v0097; /* !*ezgcd */
    stack[-6] = stack[-9];
    v0098 = stack[-9];
    v0097 = stack[-4];
    fn = elt(env, 14); /* diff */
    v0097 = (*qfn2(fn))(qenv(fn), v0098, v0097);
    nil = C_nil;
    if (exception_pending()) goto v0103;
    env = stack[-11];
    fn = elt(env, 15); /* gcdf */
    v0097 = (*qfn2(fn))(qenv(fn), stack[-6], v0097);
    nil = C_nil;
    if (exception_pending()) goto v0103;
    env = stack[-11];
    stack[-6] = v0097;
    qvalue(elt(env, 6)) = stack[0]; /* !*ezgcd */
    v0098 = stack[-9];
    v0097 = stack[-6];
    fn = elt(env, 16); /* quotf!-fail */
    v0097 = (*qfn2(fn))(qenv(fn), v0098, v0097);
    nil = C_nil;
    if (exception_pending()) goto v0102;
    env = stack[-11];
    stack[-9] = v0097;
    v0097 = qvalue(elt(env, 7)); /* dmode!* */
    if (!symbolp(v0097)) v0097 = nil;
    else { v0097 = qfastgets(v0097);
           if (v0097 != nil) { v0097 = elt(v0097, 3); /* field */
#ifdef RECORD_GET
             if (v0097 == SPID_NOPROP)
                record_get(elt(fastget_names, 3), 0),
                v0097 = nil;
             else record_get(elt(fastget_names, 3), 1),
                v0097 = lisp_true; }
           else record_get(elt(fastget_names, 3), 0); }
#else
             if (v0097 == SPID_NOPROP) v0097 = nil; else v0097 = lisp_true; }}
#endif
    if (v0097 == nil) goto v0104;
    v0097 = stack[-9];
    fn = elt(env, 17); /* lnc */
    v0098 = (*qfn1(fn))(qenv(fn), v0097);
    nil = C_nil;
    if (exception_pending()) goto v0102;
    env = stack[-11];
    stack[-3] = v0098;
    v0097 = (Lisp_Object)17; /* 1 */
    v0097 = Lneq(nil, v0098, v0097);
    nil = C_nil;
    if (exception_pending()) goto v0102;
    env = stack[-11];
    goto v0105;

v0105:
    if (v0097 == nil) goto v0106;
    v0097 = stack[-3];
    fn = elt(env, 18); /* !:recip */
    v0098 = (*qfn1(fn))(qenv(fn), v0097);
    nil = C_nil;
    if (exception_pending()) goto v0102;
    env = stack[-11];
    v0097 = stack[-9];
    fn = elt(env, 19); /* multd */
    v0097 = (*qfn2(fn))(qenv(fn), v0098, v0097);
    nil = C_nil;
    if (exception_pending()) goto v0102;
    env = stack[-11];
    stack[-9] = v0097;
    v0098 = stack[-3];
    v0097 = stack[-6];
    fn = elt(env, 19); /* multd */
    v0097 = (*qfn2(fn))(qenv(fn), v0098, v0097);
    nil = C_nil;
    if (exception_pending()) goto v0102;
    env = stack[-11];
    stack[-6] = v0097;
    goto v0106;

v0106:
    v0098 = stack[-6];
    v0097 = stack[-4];
    fn = elt(env, 20); /* degr */
    v0098 = (*qfn2(fn))(qenv(fn), v0098, v0097);
    nil = C_nil;
    if (exception_pending()) goto v0102;
    env = stack[-11];
    v0097 = (Lisp_Object)1; /* 0 */
    v0097 = (Lisp_Object)greaterp2(v0098, v0097);
    nil = C_nil;
    if (exception_pending()) goto v0102;
    v0097 = v0097 ? lisp_true : nil;
    env = stack[-11];
    if (v0097 == nil) goto v0107;
    v0098 = stack[-6];
    v0097 = stack[-9];
    fn = elt(env, 15); /* gcdf */
    v0097 = (*qfn2(fn))(qenv(fn), v0098, v0097);
    nil = C_nil;
    if (exception_pending()) goto v0102;
    env = stack[-11];
    stack[0] = v0097;
    v0098 = stack[-9];
    v0097 = stack[0];
    if (equal(v0098, v0097)) goto v0108;
    v0098 = stack[-9];
    v0097 = stack[0];
    fn = elt(env, 21); /* quotf */
    v0099 = (*qfn2(fn))(qenv(fn), v0098, v0097);
    nil = C_nil;
    if (exception_pending()) goto v0102;
    env = stack[-11];
    v0098 = stack[-10];
    v0097 = stack[-2];
    v0097 = acons(v0099, v0098, v0097);
    nil = C_nil;
    if (exception_pending()) goto v0102;
    env = stack[-11];
    stack[-2] = v0097;
    goto v0108;

v0108:
    v0098 = stack[-6];
    v0097 = stack[0];
    fn = elt(env, 21); /* quotf */
    v0097 = (*qfn2(fn))(qenv(fn), v0098, v0097);
    nil = C_nil;
    if (exception_pending()) goto v0102;
    env = stack[-11];
    stack[-6] = v0097;
    v0097 = stack[0];
    stack[-9] = v0097;
    v0097 = stack[-10];
    v0097 = add1(v0097);
    nil = C_nil;
    if (exception_pending()) goto v0102;
    env = stack[-11];
    stack[-10] = v0097;
    goto v0106;

v0107:
    v0097 = stack[-1];
    if (v0097 == nil) goto v0109;
    v0097 = elt(env, 9); /* rounded */
    v0097 = ncons(v0097);
    nil = C_nil;
    if (exception_pending()) goto v0102;
    env = stack[-11];
    fn = elt(env, 12); /* on */
    v0097 = (*qfn1(fn))(qenv(fn), v0097);
    nil = C_nil;
    if (exception_pending()) goto v0102;
    env = stack[-11];
    v0098 = stack[-9];
    v0097 = (Lisp_Object)17; /* 1 */
    v0097 = cons(v0098, v0097);
    nil = C_nil;
    if (exception_pending()) goto v0102;
    env = stack[-11];
    fn = elt(env, 13); /* resimp */
    v0097 = (*qfn1(fn))(qenv(fn), v0097);
    nil = C_nil;
    if (exception_pending()) goto v0102;
    env = stack[-11];
    v0097 = qcar(v0097);
    stack[-9] = v0097;
    v0097 = stack[-2];
    stack[-4] = v0097;
    v0097 = stack[-4];
    if (v0097 == nil) goto v0110;
    v0097 = stack[-4];
    v0097 = qcar(v0097);
    stack[0] = v0097;
    v0097 = stack[0];
    v0098 = qcar(v0097);
    v0097 = (Lisp_Object)17; /* 1 */
    v0097 = cons(v0098, v0097);
    nil = C_nil;
    if (exception_pending()) goto v0102;
    env = stack[-11];
    fn = elt(env, 13); /* resimp */
    v0097 = (*qfn1(fn))(qenv(fn), v0097);
    nil = C_nil;
    if (exception_pending()) goto v0102;
    env = stack[-11];
    v0098 = qcar(v0097);
    v0097 = stack[0];
    v0097 = qcdr(v0097);
    v0097 = cons(v0098, v0097);
    nil = C_nil;
    if (exception_pending()) goto v0102;
    env = stack[-11];
    v0097 = ncons(v0097);
    nil = C_nil;
    if (exception_pending()) goto v0102;
    env = stack[-11];
    stack[-2] = v0097;
    stack[-3] = v0097;
    goto v0111;

v0111:
    v0097 = stack[-4];
    v0097 = qcdr(v0097);
    stack[-4] = v0097;
    v0097 = stack[-4];
    if (v0097 == nil) goto v0112;
    stack[-1] = stack[-2];
    v0097 = stack[-4];
    v0097 = qcar(v0097);
    stack[0] = v0097;
    v0097 = stack[0];
    v0098 = qcar(v0097);
    v0097 = (Lisp_Object)17; /* 1 */
    v0097 = cons(v0098, v0097);
    nil = C_nil;
    if (exception_pending()) goto v0102;
    env = stack[-11];
    fn = elt(env, 13); /* resimp */
    v0097 = (*qfn1(fn))(qenv(fn), v0097);
    nil = C_nil;
    if (exception_pending()) goto v0102;
    env = stack[-11];
    v0098 = qcar(v0097);
    v0097 = stack[0];
    v0097 = qcdr(v0097);
    v0097 = cons(v0098, v0097);
    nil = C_nil;
    if (exception_pending()) goto v0102;
    env = stack[-11];
    v0097 = ncons(v0097);
    nil = C_nil;
    if (exception_pending()) goto v0102;
    env = stack[-11];
    v0097 = Lrplacd(nil, stack[-1], v0097);
    nil = C_nil;
    if (exception_pending()) goto v0102;
    env = stack[-11];
    v0097 = stack[-2];
    v0097 = qcdr(v0097);
    stack[-2] = v0097;
    goto v0111;

v0112:
    v0097 = stack[-3];
    goto v0113;

v0113:
    stack[-2] = v0097;
    goto v0109;

v0109:
    v0098 = stack[-6];
    v0097 = (Lisp_Object)17; /* 1 */
    if (v0098 == v0097) goto v0114;
    v0098 = stack[-6];
    v0097 = stack[-7];
    v0097 = Lassoc(nil, v0098, v0097);
    goto v0115;

v0115:
    if (v0097 == nil) goto v0116;
    v0097 = (Lisp_Object)17; /* 1 */
    stack[-6] = v0097;
    goto v0116;

v0116:
    v0098 = stack[-6];
    v0097 = (Lisp_Object)17; /* 1 */
    if (v0098 == v0097) goto v0117;
    v0098 = stack[-10];
    v0097 = (Lisp_Object)17; /* 1 */
    if (v0098 == v0097) goto v0118;
    v0098 = (Lisp_Object)17; /* 1 */
    v0097 = stack[-2];
    fn = elt(env, 22); /* rassoc */
    v0097 = (*qfn2(fn))(qenv(fn), v0098, v0097);
    nil = C_nil;
    if (exception_pending()) goto v0102;
    env = stack[-11];
    stack[0] = v0097;
    if (v0097 == nil) goto v0119;
    stack[-1] = stack[0];
    v0098 = stack[-6];
    v0097 = stack[0];
    v0097 = qcar(v0097);
    fn = elt(env, 23); /* multf */
    v0097 = (*qfn2(fn))(qenv(fn), v0098, v0097);
    nil = C_nil;
    if (exception_pending()) goto v0102;
    env = stack[-11];
    v0097 = Lrplaca(nil, stack[-1], v0097);
    nil = C_nil;
    if (exception_pending()) goto v0102;
    env = stack[-11];
    goto v0117;

v0117:
    v0099 = stack[-9];
    v0098 = stack[-10];
    v0097 = stack[-2];
    v0097 = acons(v0099, v0098, v0097);
    nil = C_nil;
    if (exception_pending()) goto v0102;
    env = stack[-11];
    qvalue(elt(env, 2)) = stack[-5]; /* !*msg */
    qvalue(elt(env, 1)) = stack[-8]; /* !*gcd */
    { popv(12); return onevalue(v0097); }

v0119:
    v0097 = stack[-2];
    if (v0097 == nil) goto v0120;
    v0097 = qvalue(elt(env, 8)); /* nil */
    goto v0121;

v0121:
    if (v0097 == nil) goto v0122;
    v0098 = stack[0];
    v0097 = stack[-9];
    fn = elt(env, 23); /* multf */
    v0097 = (*qfn2(fn))(qenv(fn), v0098, v0097);
    nil = C_nil;
    if (exception_pending()) goto v0102;
    env = stack[-11];
    stack[-9] = v0097;
    goto v0117;

v0122:
    v0097 = stack[-6];
    if (!consp(v0097)) goto v0123;
    v0097 = stack[-6];
    v0097 = qcar(v0097);
    v0097 = (consp(v0097) ? nil : lisp_true);
    goto v0124;

v0124:
    if (v0097 == nil) goto v0125;
    v0100 = elt(env, 11); /* "sqfrf failure" */
    v0099 = stack[-9];
    v0098 = stack[-10];
    v0097 = stack[-2];
    v0097 = list4(v0100, v0099, v0098, v0097);
    nil = C_nil;
    if (exception_pending()) goto v0102;
    env = stack[-11];
    fn = elt(env, 24); /* errach */
    v0097 = (*qfn1(fn))(qenv(fn), v0097);
    nil = C_nil;
    if (exception_pending()) goto v0102;
    env = stack[-11];
    goto v0117;

v0125:
    stack[0] = stack[-2];
    v0098 = stack[-6];
    v0097 = (Lisp_Object)17; /* 1 */
    v0097 = cons(v0098, v0097);
    nil = C_nil;
    if (exception_pending()) goto v0102;
    env = stack[-11];
    fn = elt(env, 25); /* aconc */
    v0097 = (*qfn2(fn))(qenv(fn), stack[0], v0097);
    nil = C_nil;
    if (exception_pending()) goto v0102;
    env = stack[-11];
    stack[-2] = v0097;
    goto v0117;

v0123:
    v0097 = qvalue(elt(env, 3)); /* t */
    goto v0124;

v0120:
    v0098 = stack[-6];
    v0097 = stack[-10];
    fn = elt(env, 26); /* rootxf */
    v0098 = (*qfn2(fn))(qenv(fn), v0098, v0097);
    nil = C_nil;
    if (exception_pending()) goto v0102;
    env = stack[-11];
    stack[0] = v0098;
    v0097 = elt(env, 10); /* failed */
    v0097 = Lneq(nil, v0098, v0097);
    nil = C_nil;
    if (exception_pending()) goto v0102;
    env = stack[-11];
    goto v0121;

v0118:
    v0098 = stack[-6];
    v0097 = stack[-9];
    fn = elt(env, 23); /* multf */
    v0097 = (*qfn2(fn))(qenv(fn), v0098, v0097);
    nil = C_nil;
    if (exception_pending()) goto v0102;
    env = stack[-11];
    stack[-9] = v0097;
    goto v0117;

v0114:
    v0097 = qvalue(elt(env, 8)); /* nil */
    goto v0115;

v0110:
    v0097 = qvalue(elt(env, 8)); /* nil */
    goto v0113;

v0104:
    v0097 = qvalue(elt(env, 8)); /* nil */
    goto v0105;
/* error exit handlers */
v0103:
    env = stack[-11];
    qvalue(elt(env, 6)) = stack[0]; /* !*ezgcd */
    qvalue(elt(env, 2)) = stack[-5]; /* !*msg */
    qvalue(elt(env, 1)) = stack[-8]; /* !*gcd */
    popv(12);
    return nil;
v0102:
    env = stack[-11];
    qvalue(elt(env, 2)) = stack[-5]; /* !*msg */
    qvalue(elt(env, 1)) = stack[-8]; /* !*gcd */
    popv(12);
    return nil;
}



/* Code for !*invsq */

static Lisp_Object CC_Hinvsq(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0126, v0127;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for *invsq");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v0127 = v0000;
/* end of prologue */
    v0126 = qvalue(elt(env, 1)); /* sqrtflag */
    if (v0126 == nil) goto v0002;
    v0126 = v0127;
    fn = elt(env, 2); /* invsq */
    v0126 = (*qfn1(fn))(qenv(fn), v0126);
    nil = C_nil;
    if (exception_pending()) goto v0128;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 3); /* sqrt2top */
        return (*qfn1(fn))(qenv(fn), v0126);
    }

v0002:
    v0126 = v0127;
    {
        popv(1);
        fn = elt(env, 2); /* invsq */
        return (*qfn1(fn))(qenv(fn), v0126);
    }
/* error exit handlers */
v0128:
    popv(1);
    return nil;
}



/* Code for parfool */

static Lisp_Object CC_parfool(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0133, v0092;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for parfool");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v0000;
/* end of prologue */
    v0133 = stack[0];
    v0133 = qcar(v0133);
    if (v0133 == nil) goto v0042;
    v0133 = stack[0];
    v0133 = qcar(v0133);
    if (!(is_number(v0133))) goto v0134;
    v0133 = stack[0];
    v0092 = qcdr(v0133);
    v0133 = (Lisp_Object)17; /* 1 */
    v0133 = Leqn(nil, v0092, v0133);
    nil = C_nil;
    if (exception_pending()) goto v0135;
    env = stack[-1];
    if (v0133 == nil) goto v0134;
    v0133 = stack[0];
    v0092 = qcdr(v0133);
    v0133 = (Lisp_Object)1; /* 0 */
    v0133 = (Lisp_Object)lessp2(v0092, v0133);
    nil = C_nil;
    if (exception_pending()) goto v0135;
    v0133 = v0133 ? lisp_true : nil;
    env = stack[-1];
    if (v0133 == nil) goto v0134;
    v0133 = qvalue(elt(env, 1)); /* t */
    { popv(2); return onevalue(v0133); }

v0134:
    v0133 = qvalue(elt(env, 2)); /* nil */
    { popv(2); return onevalue(v0133); }

v0042:
    v0133 = qvalue(elt(env, 1)); /* t */
    { popv(2); return onevalue(v0133); }
/* error exit handlers */
v0135:
    popv(2);
    return nil;
}



/* Code for dim!<!=deg */

static Lisp_Object CC_dimRMdeg(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0137, v0133;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dim<=deg");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0137 = v0000;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* dimex!* */
    fn = elt(env, 4); /* deg!*form */
    v0137 = (*qfn1(fn))(qenv(fn), v0137);
    nil = C_nil;
    if (exception_pending()) goto v0138;
    env = stack[-1];
    fn = elt(env, 5); /* negf */
    v0137 = (*qfn1(fn))(qenv(fn), v0137);
    nil = C_nil;
    if (exception_pending()) goto v0138;
    env = stack[-1];
    fn = elt(env, 6); /* addf */
    v0137 = (*qfn2(fn))(qenv(fn), stack[0], v0137);
    nil = C_nil;
    if (exception_pending()) goto v0138;
    env = stack[-1];
    v0133 = v0137;
    v0137 = v0133;
    if (v0137 == nil) goto v0127;
    v0137 = v0133;
    v0137 = integerp(v0137);
    if (v0137 == nil) goto v0131;
    v0137 = (Lisp_Object)1; /* 0 */
        popv(2);
        return Lleq(nil, v0133, v0137);

v0131:
    v0137 = qvalue(elt(env, 3)); /* nil */
    { popv(2); return onevalue(v0137); }

v0127:
    v0137 = qvalue(elt(env, 2)); /* t */
    { popv(2); return onevalue(v0137); }
/* error exit handlers */
v0138:
    popv(2);
    return nil;
}



/* Code for ratmean */

static Lisp_Object CC_ratmean(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0139)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0126, v0127, v0128;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ratmean");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0126 = v0139;
    v0127 = v0000;
/* end of prologue */
    v0128 = v0127;
    v0127 = v0126;
    v0126 = qvalue(elt(env, 1)); /* t */
    {
        fn = elt(env, 2); /* ratplusm */
        return (*qfnn(fn))(qenv(fn), 3, v0128, v0127, v0126);
    }
}



/* Code for endofstmtp */

static Lisp_Object MS_CDECL CC_endofstmtp(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0126, v0127;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "endofstmtp");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for endofstmtp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* end of prologue */
    v0127 = qvalue(elt(env, 1)); /* cursym!* */
    v0126 = elt(env, 2); /* (!*semicol!* !*rsqbkt!* end) */
    v0126 = Lmember(nil, v0127, v0126);
    if (v0126 == nil) goto v0042;
    v0126 = qvalue(elt(env, 3)); /* t */
    return onevalue(v0126);

v0042:
    v0126 = nil;
    return onevalue(v0126);
}



/* Code for reddom_zeros */

static Lisp_Object CC_reddom_zeros(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0143, v0144, v0095;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for reddom_zeros");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0144 = v0000;
/* end of prologue */

v0042:
    v0143 = v0144;
    if (v0143 == nil) goto v0079;
    v0143 = v0144;
    v0095 = qcar(v0143);
    v0143 = (Lisp_Object)1; /* 0 */
    if (v0095 == v0143) goto v0063;
    v0143 = v0144;
    v0143 = qcdr(v0143);
    v0144 = v0143;
    goto v0042;

v0063:
    v0143 = v0144;
    v0143 = qcdr(v0143);
    v0143 = CC_reddom_zeros(env, v0143);
    errexit();
    return add1(v0143);

v0079:
    v0143 = (Lisp_Object)1; /* 0 */
    return onevalue(v0143);
}



/* Code for fs!:zerop!: */

static Lisp_Object CC_fsTzeropT(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0145, v0146, v0147;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for fs:zerop:");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0147 = v0000;
/* end of prologue */
    v0145 = v0147;
    if (v0145 == nil) goto v0042;
    v0145 = v0147;
    if (is_number(v0145)) goto v0148;
    v0145 = v0147;
    v0145 = qcdr(v0145);
    v0145 = (v0145 == nil ? lisp_true : nil);
    goto v0127;

v0127:
    if (v0145 == nil) goto v0096;
    v0145 = qvalue(elt(env, 1)); /* t */
    return onevalue(v0145);

v0096:
    v0145 = v0147;
    v0146 = qcdr(v0145);
    v0145 = (Lisp_Object)49; /* 3 */
    v0145 = *(Lisp_Object *)((char *)v0146 + (CELL-TAG_VECTOR) + ((int32_t)v0145/(16/CELL)));
    if (v0145 == nil) goto v0138;
    v0145 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v0145);

v0138:
    v0145 = v0147;
    v0146 = qcdr(v0145);
    v0145 = (Lisp_Object)1; /* 0 */
    v0145 = *(Lisp_Object *)((char *)v0146 + (CELL-TAG_VECTOR) + ((int32_t)v0145/(16/CELL)));
    v0146 = v0145;
    v0145 = v0146;
    if (is_number(v0145)) goto v0149;
    v0145 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v0145);

v0149:
    v0145 = v0146;
        return Lzerop(nil, v0145);

v0148:
    v0145 = qvalue(elt(env, 2)); /* nil */
    goto v0127;

v0042:
    v0145 = qvalue(elt(env, 1)); /* t */
    return onevalue(v0145);
}



/* Code for red_prepare */

static Lisp_Object CC_red_prepare(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0132;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for red_prepare");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0000;
/* end of prologue */
    v0132 = stack[-1];
    fn = elt(env, 1); /* bas_nr */
    stack[-2] = (*qfn1(fn))(qenv(fn), v0132);
    nil = C_nil;
    if (exception_pending()) goto v0150;
    env = stack[-3];
    v0132 = stack[-1];
    fn = elt(env, 2); /* bas_dpoly */
    stack[0] = (*qfn1(fn))(qenv(fn), v0132);
    nil = C_nil;
    if (exception_pending()) goto v0150;
    env = stack[-3];
    v0132 = stack[-1];
    fn = elt(env, 3); /* bas_rep */
    stack[-1] = (*qfn1(fn))(qenv(fn), v0132);
    nil = C_nil;
    if (exception_pending()) goto v0150;
    env = stack[-3];
    v0132 = (Lisp_Object)1; /* 0 */
    fn = elt(env, 4); /* dp_from_ei */
    v0132 = (*qfn1(fn))(qenv(fn), v0132);
    nil = C_nil;
    if (exception_pending()) goto v0150;
    env = stack[-3];
    fn = elt(env, 5); /* dp_sum */
    v0132 = (*qfn2(fn))(qenv(fn), stack[-1], v0132);
    nil = C_nil;
    if (exception_pending()) goto v0150;
    env = stack[-3];
    {
        Lisp_Object v0143 = stack[-2];
        Lisp_Object v0144 = stack[0];
        popv(4);
        fn = elt(env, 6); /* bas_make1 */
        return (*qfnn(fn))(qenv(fn), 3, v0143, v0144, v0132);
    }
/* error exit handlers */
v0150:
    popv(4);
    return nil;
}



/* Code for gd_simpl */

static Lisp_Object CC_gd_simpl(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0151, v0148, v0131, v0132;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for gd_simpl");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    v0132 = v0000;
/* end of prologue */
    v0131 = qvalue(elt(env, 1)); /* nil */
    v0148 = qvalue(elt(env, 2)); /* t */
    v0151 = qvalue(elt(env, 1)); /* nil */
    stack[-2] = qvalue(elt(env, 3)); /* !*guardian */
    qvalue(elt(env, 3)) = v0131; /* !*guardian */
    stack[-1] = qvalue(elt(env, 4)); /* !*rlnzden */
    qvalue(elt(env, 4)) = v0148; /* !*rlnzden */
    stack[0] = qvalue(elt(env, 5)); /* !*rladdcond */
    qvalue(elt(env, 5)) = v0151; /* !*rladdcond */
    v0151 = v0132;
    fn = elt(env, 6); /* rl_simp */
    v0131 = (*qfn1(fn))(qenv(fn), v0151);
    nil = C_nil;
    if (exception_pending()) goto v0150;
    env = stack[-3];
    v0148 = qvalue(elt(env, 1)); /* nil */
    v0151 = (Lisp_Object)-15; /* -1 */
    fn = elt(env, 7); /* rl_simpl */
    v0151 = (*qfnn(fn))(qenv(fn), 3, v0131, v0148, v0151);
    nil = C_nil;
    if (exception_pending()) goto v0150;
    env = stack[-3];
    fn = elt(env, 8); /* rl_prepfof */
    v0151 = (*qfn1(fn))(qenv(fn), v0151);
    nil = C_nil;
    if (exception_pending()) goto v0150;
    env = stack[-3];
    qvalue(elt(env, 5)) = stack[0]; /* !*rladdcond */
    qvalue(elt(env, 4)) = stack[-1]; /* !*rlnzden */
    qvalue(elt(env, 3)) = stack[-2]; /* !*guardian */
    { popv(4); return onevalue(v0151); }
/* error exit handlers */
v0150:
    env = stack[-3];
    qvalue(elt(env, 5)) = stack[0]; /* !*rladdcond */
    qvalue(elt(env, 4)) = stack[-1]; /* !*rlnzden */
    qvalue(elt(env, 3)) = stack[-2]; /* !*guardian */
    popv(4);
    return nil;
}



/* Code for ofsf_sippatl */

static Lisp_Object MS_CDECL CC_ofsf_sippatl(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0180, v0046, v0047, v0181, v0182, v0050, v0183;
    Lisp_Object fn;
    Lisp_Object v0008, v0139, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "ofsf_sippatl");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0139 = va_arg(aa, Lisp_Object);
    v0008 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ofsf_sippatl");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0008,v0139,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0139,v0008);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0008;
    stack[-12] = v0139;
    stack[-13] = v0000;
/* end of prologue */
    stack[-1] = nil;
    v0047 = elt(env, 1); /* true */
    v0046 = stack[-13];
    v0180 = elt(env, 2); /* and */
    v0180 = (v0046 == v0180 ? lisp_true : nil);
    fn = elt(env, 10); /* cl_cflip */
    v0180 = (*qfn2(fn))(qenv(fn), v0047, v0180);
    nil = C_nil;
    if (exception_pending()) goto v0048;
    env = stack[-15];
    stack[-14] = v0180;
    v0047 = elt(env, 3); /* false */
    v0046 = stack[-13];
    v0180 = elt(env, 2); /* and */
    v0180 = (v0046 == v0180 ? lisp_true : nil);
    fn = elt(env, 10); /* cl_cflip */
    v0180 = (*qfn2(fn))(qenv(fn), v0047, v0180);
    nil = C_nil;
    if (exception_pending()) goto v0048;
    env = stack[-15];
    stack[-11] = v0180;
    v0047 = elt(env, 4); /* equal */
    v0046 = stack[-13];
    v0180 = elt(env, 2); /* and */
    v0180 = (v0046 == v0180 ? lisp_true : nil);
    fn = elt(env, 11); /* ofsf_clnegrel */
    v0180 = (*qfn2(fn))(qenv(fn), v0047, v0180);
    nil = C_nil;
    if (exception_pending()) goto v0048;
    env = stack[-15];
    stack[-10] = v0180;
    v0180 = stack[0];
    fn = elt(env, 12); /* ofsf_exploitknowl */
    v0180 = (*qfn1(fn))(qenv(fn), v0180);
    nil = C_nil;
    if (exception_pending()) goto v0048;
    env = stack[-15];
    v0046 = v0180;
    v0180 = v0046;
    v0180 = qcar(v0180);
    stack[-9] = v0180;
    v0180 = v0046;
    v0180 = qcdr(v0180);
    v0046 = v0180;
    v0180 = v0046;
    v0180 = qcar(v0180);
    stack[-8] = v0180;
    v0180 = v0046;
    v0180 = qcdr(v0180);
    v0046 = v0180;
    v0180 = v0046;
    v0180 = qcar(v0180);
    stack[-7] = v0180;
    v0180 = v0046;
    v0180 = qcdr(v0180);
    v0046 = v0180;
    v0180 = v0046;
    v0180 = qcar(v0180);
    stack[-6] = v0180;
    v0180 = v0046;
    v0180 = qcdr(v0180);
    v0046 = v0180;
    v0180 = v0046;
    v0180 = qcar(v0180);
    stack[-5] = v0180;
    v0180 = v0046;
    v0180 = qcdr(v0180);
    v0046 = v0180;
    v0180 = v0046;
    v0180 = qcar(v0180);
    stack[-4] = v0180;
    v0180 = v0046;
    v0180 = qcdr(v0180);
    v0046 = v0180;
    v0180 = v0046;
    v0180 = qcar(v0180);
    stack[-3] = v0180;
    goto v0080;

v0080:
    v0180 = stack[-12];
    if (v0180 == nil) { Lisp_Object res = stack[-1]; popv(16); return onevalue(res); }
    v0180 = stack[-12];
    v0180 = qcar(v0180);
    v0046 = v0180;
    v0180 = stack[-12];
    v0180 = qcdr(v0180);
    stack[-12] = v0180;
    v0180 = v0046;
    stack[-2] = v0180;
    v0180 = qvalue(elt(env, 6)); /* !*rlsippsubst */
    if (v0180 == nil) goto v0184;
    v0046 = stack[-10];
    v0180 = stack[-2];
    fn = elt(env, 13); /* ofsf_vareqnp */
    v0180 = (*qfn2(fn))(qenv(fn), v0046, v0180);
    nil = C_nil;
    if (exception_pending()) goto v0048;
    env = stack[-15];
    if (!(v0180 == nil)) goto v0184;
    v0046 = stack[-2];
    v0180 = stack[-9];
    fn = elt(env, 14); /* ofsf_sippsubst */
    v0180 = (*qfn2(fn))(qenv(fn), v0046, v0180);
    nil = C_nil;
    if (exception_pending()) goto v0048;
    env = stack[-15];
    stack[-2] = v0180;
    v0180 = qvalue(elt(env, 5)); /* nil */
    stack[0] = qvalue(elt(env, 7)); /* !*rlsiatadv */
    qvalue(elt(env, 7)) = v0180; /* !*rlsiatadv */
    v0046 = stack[-2];
    v0180 = stack[-13];
    fn = elt(env, 15); /* ofsf_simplat1 */
    v0180 = (*qfn2(fn))(qenv(fn), v0046, v0180);
    nil = C_nil;
    if (exception_pending()) goto v0185;
    env = stack[-15];
    stack[-2] = v0180;
    qvalue(elt(env, 7)) = stack[0]; /* !*rlsiatadv */
    goto v0184;

v0184:
    v0046 = stack[-2];
    v0180 = elt(env, 1); /* true */
    if (v0046 == v0180) goto v0186;
    v0046 = stack[-2];
    v0180 = elt(env, 3); /* false */
    v0180 = (v0046 == v0180 ? lisp_true : nil);
    goto v0187;

v0187:
    if (!(v0180 == nil)) goto v0188;
    v0180 = qvalue(elt(env, 9)); /* !*rlsippsignchk */
    if (v0180 == nil) goto v0188;
    v0180 = stack[-2];
    v0180 = qcdr(v0180);
    v0180 = qcar(v0180);
    fn = elt(env, 16); /* sfto_varisnump */
    v0180 = (*qfn1(fn))(qenv(fn), v0180);
    nil = C_nil;
    if (exception_pending()) goto v0048;
    env = stack[-15];
    if (!(v0180 == nil)) goto v0188;
    v0183 = stack[-2];
    v0050 = stack[-8];
    v0182 = stack[-7];
    v0181 = stack[-6];
    v0047 = stack[-5];
    v0046 = stack[-4];
    v0180 = stack[-3];
    fn = elt(env, 17); /* ofsf_sippsignchk */
    v0180 = (*qfnn(fn))(qenv(fn), 7, v0183, v0050, v0182, v0181, v0047, v0046, v0180);
    nil = C_nil;
    if (exception_pending()) goto v0048;
    env = stack[-15];
    stack[-2] = v0180;
    goto v0188;

v0188:
    v0046 = stack[-2];
    v0180 = stack[-11];
    if (v0046 == v0180) goto v0189;
    v0046 = stack[-2];
    v0180 = stack[-14];
    if (equal(v0046, v0180)) goto v0080;
    v0046 = stack[-2];
    v0180 = stack[-1];
    fn = elt(env, 18); /* lto_insert */
    v0180 = (*qfn2(fn))(qenv(fn), v0046, v0180);
    nil = C_nil;
    if (exception_pending()) goto v0048;
    env = stack[-15];
    stack[-1] = v0180;
    goto v0080;

v0189:
    v0180 = stack[-11];
    stack[-1] = v0180;
    v0180 = qvalue(elt(env, 5)); /* nil */
    stack[-12] = v0180;
    goto v0080;

v0186:
    v0180 = qvalue(elt(env, 8)); /* t */
    goto v0187;
/* error exit handlers */
v0185:
    env = stack[-15];
    qvalue(elt(env, 7)) = stack[0]; /* !*rlsiatadv */
    popv(16);
    return nil;
v0048:
    popv(16);
    return nil;
}



/* Code for pasf_leqp */

static Lisp_Object CC_pasf_leqp(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0139)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0198, v0199, v0200, v0201;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pasf_leqp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0139,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0139);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v0199 = v0139;
    v0200 = v0000;
/* end of prologue */
    v0198 = v0200;
    if (!(v0198 == nil)) goto v0021;
    v0198 = (Lisp_Object)1; /* 0 */
    v0200 = v0198;
    goto v0021;

v0021:
    v0198 = v0199;
    if (!(v0198 == nil)) goto v0202;
    v0198 = (Lisp_Object)1; /* 0 */
    v0199 = v0198;
    goto v0202;

v0202:
    v0201 = v0200;
    v0198 = elt(env, 1); /* minf */
    if (v0201 == v0198) goto v0131;
    v0201 = v0199;
    v0198 = elt(env, 3); /* pinf */
    if (v0201 == v0198) goto v0136;
    v0201 = v0200;
    v0198 = elt(env, 3); /* pinf */
    if (v0201 == v0198) goto v0087;
    v0201 = v0199;
    v0198 = elt(env, 1); /* minf */
    if (v0201 == v0198) goto v0203;
    v0198 = v0200;
    v0198 = (Lisp_Object)lesseq2(v0198, v0199);
    nil = C_nil;
    if (exception_pending()) goto v0204;
    v0198 = v0198 ? lisp_true : nil;
    env = stack[0];
    goto v0148;

v0148:
    if (v0198 == nil) goto v0142;
    v0198 = qvalue(elt(env, 2)); /* t */
    { popv(1); return onevalue(v0198); }

v0142:
    v0198 = nil;
    { popv(1); return onevalue(v0198); }

v0203:
    v0198 = qvalue(elt(env, 4)); /* nil */
    goto v0148;

v0087:
    v0198 = qvalue(elt(env, 4)); /* nil */
    goto v0148;

v0136:
    v0198 = qvalue(elt(env, 2)); /* t */
    goto v0148;

v0131:
    v0198 = qvalue(elt(env, 2)); /* t */
    goto v0148;
/* error exit handlers */
v0204:
    popv(1);
    return nil;
}



/* Code for vsl_boundtype1 */

static Lisp_Object CC_vsl_boundtype1(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0139)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0205, v0206, v0207, v0208;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for vsl_boundtype1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0139,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0139);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v0208 = v0139;
    v0207 = v0000;
/* end of prologue */

v0017:
    v0205 = v0207;
    if (!consp(v0205)) goto v0003;
    v0205 = v0207;
    v0205 = qcar(v0205);
    v0205 = (consp(v0205) ? nil : lisp_true);
    goto v0063;

v0063:
    if (v0205 == nil) goto v0132;
    v0205 = qvalue(elt(env, 2)); /* nil */
    { popv(1); return onevalue(v0205); }

v0132:
    v0205 = v0207;
    v0205 = qcar(v0205);
    v0205 = qcar(v0205);
    v0206 = qcar(v0205);
    v0205 = v0208;
    if (v0206 == v0205) goto v0148;
    v0205 = v0207;
    v0205 = qcdr(v0205);
    v0207 = v0205;
    goto v0017;

v0148:
    v0205 = v0207;
    v0205 = qcar(v0205);
    v0205 = qcdr(v0205);
    fn = elt(env, 5); /* minusf */
    v0205 = (*qfn1(fn))(qenv(fn), v0205);
    nil = C_nil;
    if (exception_pending()) goto v0093;
    env = stack[0];
    if (v0205 == nil) goto v0209;
    v0205 = elt(env, 3); /* ub */
    { popv(1); return onevalue(v0205); }

v0209:
    v0205 = elt(env, 4); /* lb */
    { popv(1); return onevalue(v0205); }

v0003:
    v0205 = qvalue(elt(env, 1)); /* t */
    goto v0063;
/* error exit handlers */
v0093:
    popv(1);
    return nil;
}



/* Code for intconv */

static Lisp_Object CC_intconv(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0130, v0190, v0134;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for intconv");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0134 = v0000;
/* end of prologue */
    v0130 = qvalue(elt(env, 1)); /* dmode!* */
    if (v0130 == nil) goto v0082;
    v0190 = qvalue(elt(env, 1)); /* dmode!* */
    v0130 = elt(env, 3); /* (!:rd!: !:cr!:) */
    v0130 = Lmemq(nil, v0190, v0130);
    goto v0079;

v0079:
    if (!(v0130 == nil)) return onevalue(v0134);
    v0130 = qvalue(elt(env, 1)); /* dmode!* */
    if (!symbolp(v0130)) v0130 = nil;
    else { v0130 = qfastgets(v0130);
           if (v0130 != nil) { v0130 = elt(v0130, 34); /* i2d */
#ifdef RECORD_GET
             if (v0130 != SPID_NOPROP)
                record_get(elt(fastget_names, 34), 1);
             else record_get(elt(fastget_names, 34), 0),
                v0130 = nil; }
           else record_get(elt(fastget_names, 34), 0); }
#else
             if (v0130 == SPID_NOPROP) v0130 = nil; }}
#endif
    v0190 = v0134;
        return Lapply1(nil, v0130, v0190);

v0082:
    v0130 = qvalue(elt(env, 2)); /* t */
    goto v0079;
}



/* Code for sprow_dim */

static Lisp_Object CC_sprow_dim(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0210;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sprow_dim");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v0000;
/* end of prologue */
    v0210 = qvalue(elt(env, 1)); /* !*fast_la */
    if (v0210 == nil) goto v0063;
    v0210 = qvalue(elt(env, 2)); /* nil */
    goto v0002;

v0002:
    if (v0210 == nil) goto v0021;
    v0210 = elt(env, 3); /* "Error in sprow_dim: input should be a matrix." 
*/
    fn = elt(env, 4); /* rederr */
    v0210 = (*qfn1(fn))(qenv(fn), v0210);
    nil = C_nil;
    if (exception_pending()) goto v0143;
    env = stack[-1];
    goto v0021;

v0021:
    v0210 = stack[0];
    fn = elt(env, 5); /* spmatlength */
    v0210 = (*qfn1(fn))(qenv(fn), v0210);
    nil = C_nil;
    if (exception_pending()) goto v0143;
    v0210 = qcdr(v0210);
    v0210 = qcar(v0210);
    { popv(2); return onevalue(v0210); }

v0063:
    v0210 = stack[0];
    fn = elt(env, 6); /* matrixp */
    v0210 = (*qfn1(fn))(qenv(fn), v0210);
    nil = C_nil;
    if (exception_pending()) goto v0143;
    env = stack[-1];
    v0210 = (v0210 == nil ? lisp_true : nil);
    goto v0002;
/* error exit handlers */
v0143:
    popv(2);
    return nil;
}



/* Code for vdpsimpcont */

static Lisp_Object CC_vdpsimpcont(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0145, v0146, v0147;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for vdpsimpcont");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0000;
/* end of prologue */
    v0145 = stack[-1];
    v0145 = qcdr(v0145);
    v0145 = qcdr(v0145);
    v0145 = qcdr(v0145);
    v0145 = qcar(v0145);
    stack[0] = v0145;
    v0145 = stack[0];
    if (v0145 == nil) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v0145 = stack[0];
    fn = elt(env, 3); /* dipsimpcont */
    v0145 = (*qfn1(fn))(qenv(fn), v0145);
    nil = C_nil;
    if (exception_pending()) goto v0194;
    env = stack[-3];
    stack[-2] = v0145;
    v0145 = stack[-2];
    v0145 = qcdr(v0145);
    fn = elt(env, 4); /* dip2vdp */
    v0145 = (*qfn1(fn))(qenv(fn), v0145);
    nil = C_nil;
    if (exception_pending()) goto v0194;
    env = stack[-3];
    stack[-1] = v0145;
    v0145 = stack[-2];
    v0145 = qcar(v0145);
    stack[-2] = v0145;
    v0145 = stack[-2];
    fn = elt(env, 5); /* evzero!? */
    v0145 = (*qfn1(fn))(qenv(fn), v0145);
    nil = C_nil;
    if (exception_pending()) goto v0194;
    env = stack[-3];
    if (v0145 == nil) goto v0144;
    v0145 = qvalue(elt(env, 1)); /* nil */
    goto v0143;

v0143:
    if (v0145 == nil) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v0147 = stack[-1];
    v0146 = elt(env, 2); /* monfac */
    v0145 = stack[-2];
    fn = elt(env, 6); /* vdpputprop */
    v0145 = (*qfnn(fn))(qenv(fn), 3, v0147, v0146, v0145);
    nil = C_nil;
    if (exception_pending()) goto v0194;
    { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }

v0144:
    v0145 = stack[0];
    v0145 = qcdr(v0145);
    v0145 = qcdr(v0145);
    if (!(v0145 == nil)) goto v0143;
    v0145 = stack[-2];
    fn = elt(env, 7); /* evtdeg */
    v0146 = (*qfn1(fn))(qenv(fn), v0145);
    nil = C_nil;
    if (exception_pending()) goto v0194;
    env = stack[-3];
    v0145 = (Lisp_Object)17; /* 1 */
    v0145 = (Lisp_Object)greaterp2(v0146, v0145);
    nil = C_nil;
    if (exception_pending()) goto v0194;
    v0145 = v0145 ? lisp_true : nil;
    env = stack[-3];
    goto v0143;
/* error exit handlers */
v0194:
    popv(4);
    return nil;
}



/* Code for mk_parents_prim */

static Lisp_Object CC_mk_parents_prim(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0137, v0133;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mk_parents_prim");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v0000;
/* end of prologue */
    v0137 = stack[0];
    v0133 = Llength(nil, v0137);
    nil = C_nil;
    if (exception_pending()) goto v0138;
    env = stack[-1];
    v0137 = (Lisp_Object)49; /* 3 */
    if (!(v0133 == v0137)) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v0137 = stack[0];
    fn = elt(env, 1); /* s_noparents */
    v0137 = (*qfn1(fn))(qenv(fn), v0137);
    nil = C_nil;
    if (exception_pending()) goto v0138;
    env = stack[-1];
    v0133 = v0137;
    if (v0133 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v0133 = stack[0];
    v0137 = qcar(v0137);
    fn = elt(env, 2); /* mk_edge_parents */
    v0137 = (*qfn2(fn))(qenv(fn), v0133, v0137);
    nil = C_nil;
    if (exception_pending()) goto v0138;
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
/* error exit handlers */
v0138:
    popv(2);
    return nil;
}



/* Code for get!-all!-kernels */

static Lisp_Object CC_getKallKkernels(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0149, v0195;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for get-all-kernels");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v0000;
/* end of prologue */
    stack[-3] = nil;
    goto v0021;

v0021:
    v0149 = stack[-2];
    if (!consp(v0149)) goto v0079;
    v0149 = stack[-2];
    v0149 = qcar(v0149);
    fn = elt(env, 2); /* simp */
    v0149 = (*qfn1(fn))(qenv(fn), v0149);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-4];
    stack[-1] = v0149;
    v0149 = stack[-1];
    v0149 = qcar(v0149);
    fn = elt(env, 3); /* kernels */
    stack[0] = (*qfn1(fn))(qenv(fn), v0149);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-4];
    v0149 = stack[-1];
    v0149 = qcdr(v0149);
    fn = elt(env, 3); /* kernels */
    v0149 = (*qfn1(fn))(qenv(fn), v0149);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-4];
    fn = elt(env, 4); /* union */
    v0195 = (*qfn2(fn))(qenv(fn), stack[0], v0149);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-4];
    v0149 = stack[-3];
    v0149 = cons(v0195, v0149);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-4];
    stack[-3] = v0149;
    v0149 = stack[-2];
    v0149 = qcdr(v0149);
    stack[-2] = v0149;
    goto v0021;

v0079:
    v0149 = qvalue(elt(env, 1)); /* nil */
    v0195 = v0149;
    goto v0082;

v0082:
    v0149 = stack[-3];
    if (v0149 == nil) { popv(5); return onevalue(v0195); }
    v0149 = stack[-3];
    v0149 = qcar(v0149);
    fn = elt(env, 4); /* union */
    v0149 = (*qfn2(fn))(qenv(fn), v0149, v0195);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-4];
    v0195 = v0149;
    v0149 = stack[-3];
    v0149 = qcdr(v0149);
    stack[-3] = v0149;
    goto v0082;
/* error exit handlers */
v0089:
    popv(5);
    return nil;
}



/* Code for bagp */

static Lisp_Object CC_bagp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0141, v0142;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for bagp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0142 = v0000;
/* end of prologue */
    v0141 = v0142;
    if (!consp(v0141)) goto v0128;
    v0141 = v0142;
    v0141 = qcar(v0141);
    v0142 = elt(env, 1); /* bag */
        return Lflagp(nil, v0141, v0142);

v0128:
    v0141 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v0141);
}



/* Code for dfdeg */

static Lisp_Object CC_dfdeg(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0139)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0137, v0133;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dfdeg");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0133 = v0139;
    v0137 = v0000;
/* end of prologue */
    v0133 = Lmember(nil, v0133, v0137);
    v0137 = v0133;
    if (v0133 == nil) goto v0017;
    v0133 = v0137;
    v0133 = qcdr(v0133);
    if (v0133 == nil) goto v0142;
    v0133 = v0137;
    v0133 = qcdr(v0133);
    v0133 = qcar(v0133);
    v0133 = integerp(v0133);
    v0133 = (v0133 == nil ? lisp_true : nil);
    goto v0141;

v0141:
    if (v0133 == nil) goto v0129;
    v0137 = (Lisp_Object)17; /* 1 */
    return onevalue(v0137);

v0129:
    v0137 = qcdr(v0137);
    v0137 = qcar(v0137);
    return onevalue(v0137);

v0142:
    v0133 = qvalue(elt(env, 1)); /* t */
    goto v0141;

v0017:
    v0137 = (Lisp_Object)1; /* 0 */
    return onevalue(v0137);
}



/* Code for xadd!* */

static Lisp_Object MS_CDECL CC_xaddH(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0229, v0230, v0152;
    Lisp_Object fn;
    Lisp_Object v0008, v0139, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "xadd*");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0139 = va_arg(aa, Lisp_Object);
    v0008 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for xadd*");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0008,v0139,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0139,v0008);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-9] = v0008;
    stack[-10] = v0139;
    stack[-11] = v0000;
/* end of prologue */
    v0229 = stack[-10];
    stack[-12] = v0229;
    goto v0063;

v0063:
    v0229 = stack[-12];
    if (v0229 == nil) goto v0002;
    v0229 = stack[-11];
    v0230 = qcar(v0229);
    v0229 = stack[-12];
    v0229 = qcar(v0229);
    v0229 = qcar(v0229);
    if (equal(v0230, v0229)) goto v0129;
    v0229 = qvalue(elt(env, 1)); /* nil */
    goto v0142;

v0142:
    if (!(v0229 == nil)) goto v0002;
    v0229 = stack[-12];
    v0229 = qcdr(v0229);
    stack[-12] = v0229;
    goto v0063;

v0002:
    v0229 = stack[-12];
    if (v0229 == nil) goto v0208;
    v0229 = stack[-12];
    v0230 = qcar(v0229);
    v0229 = stack[-10];
    v0229 = Ldelete(nil, v0230, v0229);
    nil = C_nil;
    if (exception_pending()) goto v0231;
    env = stack[-13];
    stack[-10] = v0229;
    v0229 = stack[-12];
    v0229 = qcar(v0229);
    stack[-12] = v0229;
    v0229 = stack[-9];
    if (v0229 == nil) goto v0208;
    v0229 = qvalue(elt(env, 2)); /* newrule!* */
    if (v0229 == nil) goto v0208;
    v0229 = stack[-12];
    v0230 = qcar(v0229);
    v0229 = qvalue(elt(env, 2)); /* newrule!* */
    v0229 = qcar(v0229);
    stack[0] = v0229;
    if (equal(v0230, v0229)) goto v0232;
    v0229 = stack[-12];
    v0229 = qcar(v0229);
    fn = elt(env, 7); /* powlisp */
    v0229 = (*qfn1(fn))(qenv(fn), v0229);
    nil = C_nil;
    if (exception_pending()) goto v0231;
    env = stack[-13];
    goto v0233;

v0233:
    if (v0229 == nil) goto v0158;
    stack[-8] = elt(env, 3); /* plus */
    stack[-7] = stack[0];
    stack[-6] = elt(env, 4); /* difference */
    v0229 = stack[-12];
    v0229 = qcdr(v0229);
    v0229 = qcdr(v0229);
    stack[-5] = qcar(v0229);
    stack[-4] = elt(env, 5); /* times */
    v0229 = stack[-12];
    v0229 = qcar(v0229);
    stack[-3] = v0229;
    v0229 = stack[-3];
    if (v0229 == nil) goto v0234;
    v0229 = stack[-3];
    v0229 = qcar(v0229);
    v0152 = elt(env, 6); /* expt */
    v0230 = v0229;
    v0230 = qcar(v0230);
    v0229 = qcdr(v0229);
    v0229 = list3(v0152, v0230, v0229);
    nil = C_nil;
    if (exception_pending()) goto v0231;
    env = stack[-13];
    v0229 = ncons(v0229);
    nil = C_nil;
    if (exception_pending()) goto v0231;
    env = stack[-13];
    stack[-1] = v0229;
    stack[-2] = v0229;
    goto v0235;

v0235:
    v0229 = stack[-3];
    v0229 = qcdr(v0229);
    stack[-3] = v0229;
    v0229 = stack[-3];
    if (v0229 == nil) goto v0236;
    stack[0] = stack[-1];
    v0229 = stack[-3];
    v0229 = qcar(v0229);
    v0152 = elt(env, 6); /* expt */
    v0230 = v0229;
    v0230 = qcar(v0230);
    v0229 = qcdr(v0229);
    v0229 = list3(v0152, v0230, v0229);
    nil = C_nil;
    if (exception_pending()) goto v0231;
    env = stack[-13];
    v0229 = ncons(v0229);
    nil = C_nil;
    if (exception_pending()) goto v0231;
    env = stack[-13];
    v0229 = Lrplacd(nil, stack[0], v0229);
    nil = C_nil;
    if (exception_pending()) goto v0231;
    env = stack[-13];
    v0229 = stack[-1];
    v0229 = qcdr(v0229);
    stack[-1] = v0229;
    goto v0235;

v0236:
    v0229 = stack[-2];
    goto v0237;

v0237:
    v0229 = cons(stack[-4], v0229);
    nil = C_nil;
    if (exception_pending()) goto v0231;
    env = stack[-13];
    v0229 = list3(stack[-6], stack[-5], v0229);
    nil = C_nil;
    if (exception_pending()) goto v0231;
    env = stack[-13];
    v0229 = list3(stack[-8], stack[-7], v0229);
    nil = C_nil;
    if (exception_pending()) goto v0231;
    env = stack[-13];
    fn = elt(env, 8); /* simp */
    v0229 = (*qfn1(fn))(qenv(fn), v0229);
    nil = C_nil;
    if (exception_pending()) goto v0231;
    env = stack[-13];
    fn = elt(env, 9); /* prepsq */
    v0230 = (*qfn1(fn))(qenv(fn), v0229);
    nil = C_nil;
    if (exception_pending()) goto v0231;
    env = stack[-13];
    v0229 = stack[-12];
    v0229 = qcdr(v0229);
    v0229 = qcar(v0229);
    v0229 = qcdr(v0229);
    fn = elt(env, 10); /* updoldrules */
    v0229 = (*qfn2(fn))(qenv(fn), v0230, v0229);
    nil = C_nil;
    if (exception_pending()) goto v0231;
    env = stack[-13];
    goto v0208;

v0208:
    v0229 = stack[-9];
    if (v0229 == nil) { Lisp_Object res = stack[-10]; popv(14); return onevalue(res); }
    v0230 = stack[-11];
    v0229 = stack[-10];
    v0229 = cons(v0230, v0229);
    nil = C_nil;
    if (exception_pending()) goto v0231;
    stack[-10] = v0229;
    { Lisp_Object res = stack[-10]; popv(14); return onevalue(res); }

v0234:
    v0229 = qvalue(elt(env, 1)); /* nil */
    goto v0237;

v0158:
    v0229 = stack[-12];
    v0229 = qcdr(v0229);
    v0229 = qcdr(v0229);
    v0230 = qcar(v0229);
    v0229 = stack[-12];
    v0229 = qcdr(v0229);
    v0229 = qcar(v0229);
    v0229 = qcdr(v0229);
    fn = elt(env, 10); /* updoldrules */
    v0229 = (*qfn2(fn))(qenv(fn), v0230, v0229);
    nil = C_nil;
    if (exception_pending()) goto v0231;
    env = stack[-13];
    goto v0208;

v0232:
    v0229 = qvalue(elt(env, 1)); /* nil */
    goto v0233;

v0129:
    v0229 = stack[-11];
    v0229 = qcdr(v0229);
    v0230 = qcar(v0229);
    v0229 = stack[-12];
    v0229 = qcar(v0229);
    v0229 = qcdr(v0229);
    v0229 = qcar(v0229);
    v0229 = (equal(v0230, v0229) ? lisp_true : nil);
    goto v0142;
/* error exit handlers */
v0231:
    popv(14);
    return nil;
}



/* Code for cl_simpl1 */

static Lisp_Object MS_CDECL CC_cl_simpl1(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0328, v0329, v0330, v0331;
    Lisp_Object fn;
    Lisp_Object v0001, v0008, v0139, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "cl_simpl1");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0139 = va_arg(aa, Lisp_Object);
    v0008 = va_arg(aa, Lisp_Object);
    v0001 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for cl_simpl1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v0001,v0008,v0139,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0000,v0139,v0008,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0001;
    stack[-1] = v0008;
    stack[-2] = v0139;
    stack[-3] = v0000;
/* end of prologue */
    v0329 = stack[-1];
    v0328 = (Lisp_Object)1; /* 0 */
    v0328 = Leqn(nil, v0329, v0328);
    nil = C_nil;
    if (exception_pending()) goto v0332;
    env = stack[-5];
    if (!(v0328 == nil)) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v0328 = stack[-3];
    if (!consp(v0328)) goto v0333;
    v0328 = stack[-3];
    v0328 = qcar(v0328);
    goto v0202;

v0202:
    stack[-4] = v0328;
    v0329 = stack[-4];
    v0328 = elt(env, 1); /* true */
    if (v0329 == v0328) goto v0092;
    v0329 = stack[-4];
    v0328 = elt(env, 3); /* false */
    v0328 = (v0329 == v0328 ? lisp_true : nil);
    goto v0133;

v0133:
    if (!(v0328 == nil)) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v0329 = stack[-4];
    v0328 = elt(env, 4); /* or */
    if (v0329 == v0328) goto v0334;
    v0329 = stack[-4];
    v0328 = elt(env, 5); /* and */
    v0328 = (v0329 == v0328 ? lisp_true : nil);
    goto v0147;

v0147:
    if (v0328 == nil) goto v0335;
    v0331 = stack[-4];
    v0328 = stack[-3];
    v0330 = qcdr(v0328);
    v0329 = stack[-2];
    v0328 = stack[-1];
    fn = elt(env, 17); /* cl_smsimpl!-junct */
    v0328 = (*qfnn(fn))(qenv(fn), 4, v0331, v0330, v0329, v0328);
    nil = C_nil;
    if (exception_pending()) goto v0332;
    env = stack[-5];
    v0329 = v0328;
    v0328 = v0329;
    if (v0328 == nil) goto v0336;
    v0328 = v0329;
    v0328 = qcdr(v0328);
    if (v0328 == nil) goto v0336;
    v0328 = stack[-4];
    popv(6);
    return cons(v0328, v0329);

v0336:
    v0328 = v0329;
    if (v0328 == nil) goto v0337;
    v0328 = v0329;
    v0328 = qcar(v0328);
    { popv(6); return onevalue(v0328); }

v0337:
    v0329 = stack[-4];
    v0328 = elt(env, 5); /* and */
    if (v0329 == v0328) goto v0219;
    v0328 = elt(env, 3); /* false */
    { popv(6); return onevalue(v0328); }

v0219:
    v0328 = elt(env, 1); /* true */
    { popv(6); return onevalue(v0328); }

v0335:
    v0329 = stack[-4];
    v0328 = elt(env, 6); /* not */
    if (v0329 == v0328) goto v0164;
    v0329 = stack[-4];
    v0328 = elt(env, 7); /* ex */
    if (v0329 == v0328) goto v0188;
    v0329 = stack[-4];
    v0328 = elt(env, 8); /* all */
    v0328 = (v0329 == v0328 ? lisp_true : nil);
    goto v0338;

v0338:
    if (v0328 == nil) goto v0339;
    v0328 = qvalue(elt(env, 9)); /* !*rlsism */
    if (v0328 == nil) goto v0340;
    v0329 = stack[-2];
    v0328 = stack[-3];
    v0328 = qcdr(v0328);
    v0328 = qcar(v0328);
    fn = elt(env, 18); /* rl_smrmknowl */
    v0328 = (*qfn2(fn))(qenv(fn), v0329, v0328);
    nil = C_nil;
    if (exception_pending()) goto v0332;
    env = stack[-5];
    stack[-2] = v0328;
    goto v0340;

v0340:
    v0328 = stack[-3];
    v0328 = qcdr(v0328);
    v0328 = qcdr(v0328);
    stack[0] = qcar(v0328);
    v0328 = stack[-1];
    v0329 = sub1(v0328);
    nil = C_nil;
    if (exception_pending()) goto v0332;
    env = stack[-5];
    v0328 = stack[-4];
    v0328 = CC_cl_simpl1(env, 4, stack[0], stack[-2], v0329, v0328);
    nil = C_nil;
    if (exception_pending()) goto v0332;
    env = stack[-5];
    stack[-1] = v0328;
    v0329 = stack[-1];
    v0328 = elt(env, 1); /* true */
    if (v0329 == v0328) goto v0115;
    v0329 = stack[-1];
    v0328 = elt(env, 3); /* false */
    v0328 = (v0329 == v0328 ? lisp_true : nil);
    goto v0039;

v0039:
    if (!(v0328 == nil)) { Lisp_Object res = stack[-1]; popv(6); return onevalue(res); }
    v0328 = stack[-3];
    v0328 = qcdr(v0328);
    stack[0] = qcar(v0328);
    v0328 = stack[-1];
    fn = elt(env, 19); /* cl_fvarl */
    v0328 = (*qfn1(fn))(qenv(fn), v0328);
    nil = C_nil;
    if (exception_pending()) goto v0332;
    v0328 = Lmemq(nil, stack[0], v0328);
    if (v0328 == nil) { Lisp_Object res = stack[-1]; popv(6); return onevalue(res); }
    v0330 = stack[-4];
    v0328 = stack[-3];
    v0328 = qcdr(v0328);
    v0329 = qcar(v0328);
    v0328 = stack[-1];
    popv(6);
    return list3(v0330, v0329, v0328);

v0115:
    v0328 = qvalue(elt(env, 2)); /* t */
    goto v0039;

v0339:
    v0329 = stack[-4];
    v0328 = elt(env, 10); /* bex */
    if (v0329 == v0328) goto v0341;
    v0329 = stack[-4];
    v0328 = elt(env, 11); /* ball */
    v0328 = (v0329 == v0328 ? lisp_true : nil);
    goto v0342;

v0342:
    if (v0328 == nil) goto v0343;
    v0328 = qvalue(elt(env, 9)); /* !*rlsism */
    if (v0328 == nil) goto v0120;
    v0329 = stack[-2];
    v0328 = stack[-3];
    v0328 = qcdr(v0328);
    v0328 = qcar(v0328);
    fn = elt(env, 18); /* rl_smrmknowl */
    v0328 = (*qfn2(fn))(qenv(fn), v0329, v0328);
    nil = C_nil;
    if (exception_pending()) goto v0332;
    env = stack[-5];
    stack[-2] = v0328;
    goto v0120;

v0120:
    v0330 = stack[-3];
    v0329 = stack[-2];
    v0328 = stack[-1];
    {
        popv(6);
        fn = elt(env, 20); /* cl_simplbq */
        return (*qfnn(fn))(qenv(fn), 3, v0330, v0329, v0328);
    }

v0343:
    v0329 = stack[-4];
    v0328 = elt(env, 12); /* impl */
    if (v0329 == v0328) goto v0124;
    v0329 = stack[-4];
    v0328 = elt(env, 13); /* repl */
    if (v0329 == v0328) goto v0344;
    v0329 = stack[-4];
    v0328 = elt(env, 14); /* equiv */
    if (v0329 == v0328) goto v0345;
    v0329 = stack[-4];
    v0328 = elt(env, 15); /* cl_simpl */
    fn = elt(env, 21); /* rl_external */
    v0328 = (*qfn2(fn))(qenv(fn), v0329, v0328);
    nil = C_nil;
    if (exception_pending()) goto v0332;
    env = stack[-5];
    v0329 = v0328;
    if (v0328 == nil) goto v0346;
    stack[0] = v0329;
    v0328 = stack[-3];
    v0328 = ncons(v0328);
    nil = C_nil;
    if (exception_pending()) goto v0332;
    env = stack[-5];
    {
        Lisp_Object v0347 = stack[0];
        popv(6);
        fn = elt(env, 22); /* apply */
        return (*qfn2(fn))(qenv(fn), v0347, v0328);
    }

v0346:
    v0329 = stack[-3];
    v0328 = stack[0];
    fn = elt(env, 23); /* cl_simplat */
    v0328 = (*qfn2(fn))(qenv(fn), v0329, v0328);
    nil = C_nil;
    if (exception_pending()) goto v0332;
    env = stack[-5];
    v0329 = v0328;
    v0328 = qvalue(elt(env, 9)); /* !*rlsism */
    if (v0328 == nil) goto v0348;
    v0328 = v0329;
    if (!consp(v0328)) goto v0349;
    v0328 = v0329;
    v0328 = qcar(v0328);
    goto v0350;

v0350:
    stack[-4] = v0328;
    v0330 = stack[-4];
    v0328 = elt(env, 4); /* or */
    if (v0330 == v0328) goto v0351;
    v0330 = stack[-4];
    v0328 = elt(env, 5); /* and */
    v0328 = (v0330 == v0328 ? lisp_true : nil);
    goto v0352;

v0352:
    if (v0328 == nil) goto v0353;
    v0331 = stack[-4];
    v0328 = v0329;
    v0330 = qcdr(v0328);
    v0329 = stack[-2];
    v0328 = stack[-1];
    fn = elt(env, 17); /* cl_smsimpl!-junct */
    v0328 = (*qfnn(fn))(qenv(fn), 4, v0331, v0330, v0329, v0328);
    nil = C_nil;
    if (exception_pending()) goto v0332;
    env = stack[-5];
    v0329 = v0328;
    v0328 = v0329;
    if (v0328 == nil) goto v0354;
    v0328 = v0329;
    v0328 = qcdr(v0328);
    if (v0328 == nil) goto v0354;
    v0328 = stack[-4];
    popv(6);
    return cons(v0328, v0329);

v0354:
    v0328 = v0329;
    if (v0328 == nil) goto v0355;
    v0328 = v0329;
    v0328 = qcar(v0328);
    { popv(6); return onevalue(v0328); }

v0355:
    v0329 = stack[-4];
    v0328 = elt(env, 5); /* and */
    if (v0329 == v0328) goto v0356;
    v0328 = elt(env, 3); /* false */
    { popv(6); return onevalue(v0328); }

v0356:
    v0328 = elt(env, 1); /* true */
    { popv(6); return onevalue(v0328); }

v0353:
    v0330 = stack[-4];
    v0328 = elt(env, 1); /* true */
    if (v0330 == v0328) goto v0357;
    v0330 = stack[-4];
    v0328 = elt(env, 3); /* false */
    v0328 = (v0330 == v0328 ? lisp_true : nil);
    goto v0358;

v0358:
    if (!(v0328 == nil)) { popv(6); return onevalue(v0329); }
    stack[-3] = elt(env, 5); /* and */
    v0328 = v0329;
    stack[0] = ncons(v0328);
    nil = C_nil;
    if (exception_pending()) goto v0332;
    env = stack[-5];
    v0328 = stack[-2];
    fn = elt(env, 24); /* rl_smcpknowl */
    v0329 = (*qfn1(fn))(qenv(fn), v0328);
    nil = C_nil;
    if (exception_pending()) goto v0332;
    env = stack[-5];
    v0328 = stack[-1];
    fn = elt(env, 25); /* rl_smupdknowl */
    v0328 = (*qfnn(fn))(qenv(fn), 4, stack[-3], stack[0], v0329, v0328);
    nil = C_nil;
    if (exception_pending()) goto v0332;
    env = stack[-5];
    v0330 = v0328;
    v0329 = elt(env, 3); /* false */
    if (v0330 == v0329) goto v0359;
    v0331 = elt(env, 5); /* and */
    v0330 = stack[-2];
    v0329 = v0328;
    v0328 = stack[-1];
    fn = elt(env, 26); /* rl_smmkatl */
    v0328 = (*qfnn(fn))(qenv(fn), 4, v0331, v0330, v0329, v0328);
    nil = C_nil;
    if (exception_pending()) goto v0332;
    env = stack[-5];
    v0329 = v0328;
    v0330 = v0329;
    v0328 = elt(env, 3); /* false */
    if (v0330 == v0328) goto v0360;
    v0328 = v0329;
    if (v0328 == nil) goto v0361;
    v0328 = v0329;
    v0328 = qcdr(v0328);
    if (v0328 == nil) goto v0361;
    v0328 = elt(env, 5); /* and */
    popv(6);
    return cons(v0328, v0329);

v0361:
    v0328 = v0329;
    if (v0328 == nil) goto v0362;
    v0328 = v0329;
    v0328 = qcar(v0328);
    { popv(6); return onevalue(v0328); }

v0362:
    v0329 = elt(env, 5); /* and */
    v0328 = elt(env, 5); /* and */
    if (v0329 == v0328) goto v0363;
    v0328 = elt(env, 3); /* false */
    { popv(6); return onevalue(v0328); }

v0363:
    v0328 = elt(env, 1); /* true */
    { popv(6); return onevalue(v0328); }

v0360:
    v0328 = elt(env, 3); /* false */
    { popv(6); return onevalue(v0328); }

v0359:
    v0328 = elt(env, 3); /* false */
    { popv(6); return onevalue(v0328); }

v0357:
    v0328 = qvalue(elt(env, 2)); /* t */
    goto v0358;

v0351:
    v0328 = qvalue(elt(env, 2)); /* t */
    goto v0352;

v0349:
    v0328 = v0329;
    goto v0350;

v0348:
    v0328 = v0329;
    if (!(v0328 == nil)) { popv(6); return onevalue(v0329); }
    v0329 = elt(env, 16); /* "cl_simpl1(): unknown operator" */
    v0328 = stack[-4];
    v0328 = list2(v0329, v0328);
    nil = C_nil;
    if (exception_pending()) goto v0332;
    env = stack[-5];
    fn = elt(env, 27); /* rederr */
    v0328 = (*qfn1(fn))(qenv(fn), v0328);
    nil = C_nil;
    if (exception_pending()) goto v0332;
    v0328 = nil;
    { popv(6); return onevalue(v0328); }

v0345:
    v0328 = stack[-3];
    v0328 = qcdr(v0328);
    v0331 = qcar(v0328);
    v0328 = stack[-3];
    v0328 = qcdr(v0328);
    v0328 = qcdr(v0328);
    v0330 = qcar(v0328);
    v0329 = stack[-2];
    v0328 = stack[-1];
    {
        popv(6);
        fn = elt(env, 28); /* cl_smsimpl!-equiv */
        return (*qfnn(fn))(qenv(fn), 4, v0331, v0330, v0329, v0328);
    }

v0344:
    v0328 = stack[-3];
    v0328 = qcdr(v0328);
    v0328 = qcdr(v0328);
    v0331 = qcar(v0328);
    v0328 = stack[-3];
    v0328 = qcdr(v0328);
    v0330 = qcar(v0328);
    v0329 = stack[-2];
    v0328 = stack[-1];
    {
        popv(6);
        fn = elt(env, 29); /* cl_smsimpl!-imprep */
        return (*qfnn(fn))(qenv(fn), 4, v0331, v0330, v0329, v0328);
    }

v0124:
    v0328 = stack[-3];
    v0328 = qcdr(v0328);
    v0331 = qcar(v0328);
    v0328 = stack[-3];
    v0328 = qcdr(v0328);
    v0328 = qcdr(v0328);
    v0330 = qcar(v0328);
    v0329 = stack[-2];
    v0328 = stack[-1];
    {
        popv(6);
        fn = elt(env, 29); /* cl_smsimpl!-imprep */
        return (*qfnn(fn))(qenv(fn), 4, v0331, v0330, v0329, v0328);
    }

v0341:
    v0328 = qvalue(elt(env, 2)); /* t */
    goto v0342;

v0188:
    v0328 = qvalue(elt(env, 2)); /* t */
    goto v0338;

v0164:
    v0328 = stack[-3];
    v0328 = qcdr(v0328);
    stack[0] = qcar(v0328);
    v0328 = stack[-1];
    v0329 = sub1(v0328);
    nil = C_nil;
    if (exception_pending()) goto v0332;
    env = stack[-5];
    v0328 = elt(env, 6); /* not */
    v0328 = CC_cl_simpl1(env, 4, stack[0], stack[-2], v0329, v0328);
    nil = C_nil;
    if (exception_pending()) goto v0332;
    env = stack[-5];
    stack[-1] = v0328;
    v0329 = stack[-1];
    v0328 = elt(env, 1); /* true */
    if (v0329 == v0328) goto v0364;
    v0329 = stack[-1];
    v0328 = elt(env, 3); /* false */
    v0328 = (v0329 == v0328 ? lisp_true : nil);
    goto v0365;

v0365:
    if (v0328 == nil) goto v0366;
    v0328 = stack[-1];
    {
        popv(6);
        fn = elt(env, 30); /* cl_flip */
        return (*qfn1(fn))(qenv(fn), v0328);
    }

v0366:
    v0328 = stack[-1];
    fn = elt(env, 31); /* cl_atfp */
    v0328 = (*qfn1(fn))(qenv(fn), v0328);
    nil = C_nil;
    if (exception_pending()) goto v0332;
    env = stack[-5];
    if (v0328 == nil) goto v0224;
    v0328 = stack[-1];
    {
        popv(6);
        fn = elt(env, 32); /* rl_negateat */
        return (*qfn1(fn))(qenv(fn), v0328);
    }

v0224:
    v0328 = stack[-1];
    {
        popv(6);
        fn = elt(env, 33); /* cl_negate!-invol */
        return (*qfn1(fn))(qenv(fn), v0328);
    }

v0364:
    v0328 = qvalue(elt(env, 2)); /* t */
    goto v0365;

v0334:
    v0328 = qvalue(elt(env, 2)); /* t */
    goto v0147;

v0092:
    v0328 = qvalue(elt(env, 2)); /* t */
    goto v0133;

v0333:
    v0328 = stack[-3];
    goto v0202;
/* error exit handlers */
v0332:
    popv(6);
    return nil;
}



/* Code for pasf_subfof */

static Lisp_Object MS_CDECL CC_pasf_subfof(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0148, v0131, v0132;
    Lisp_Object fn;
    Lisp_Object v0008, v0139, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "pasf_subfof");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0139 = va_arg(aa, Lisp_Object);
    v0008 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pasf_subfof");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0008,v0139,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0139,v0008);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    v0148 = v0008;
    v0131 = v0139;
    v0132 = v0000;
/* end of prologue */
    stack[-1] = v0148;
    stack[0] = elt(env, 1); /* pasf_subfof1 */
    v0148 = v0132;
    v0148 = list2(v0148, v0131);
    nil = C_nil;
    if (exception_pending()) goto v0210;
    env = stack[-2];
    {
        Lisp_Object v0150 = stack[-1];
        Lisp_Object v0143 = stack[0];
        popv(3);
        fn = elt(env, 2); /* cl_apply2ats1 */
        return (*qfnn(fn))(qenv(fn), 3, v0150, v0143, v0148);
    }
/* error exit handlers */
v0210:
    popv(3);
    return nil;
}



/* Code for ofsf_boundchk */

static Lisp_Object CC_ofsf_boundchk(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0139)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0227, v0316, v0228;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ofsf_boundchk");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0139,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0139);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0139;
    stack[-2] = v0000;
/* end of prologue */
    v0227 = stack[-1];
    v0227 = ncons(v0227);
    nil = C_nil;
    if (exception_pending()) goto v0236;
    env = stack[-4];
    fn = elt(env, 9); /* setkorder */
    v0227 = (*qfn1(fn))(qenv(fn), v0227);
    nil = C_nil;
    if (exception_pending()) goto v0236;
    env = stack[-4];
    stack[0] = v0227;
    v0227 = stack[-2];
    v0227 = qcdr(v0227);
    v0227 = qcar(v0227);
    fn = elt(env, 10); /* reorder */
    v0227 = (*qfn1(fn))(qenv(fn), v0227);
    nil = C_nil;
    if (exception_pending()) goto v0236;
    env = stack[-4];
    stack[-3] = v0227;
    v0227 = stack[0];
    fn = elt(env, 9); /* setkorder */
    v0227 = (*qfn1(fn))(qenv(fn), v0227);
    nil = C_nil;
    if (exception_pending()) goto v0236;
    env = stack[-4];
    v0227 = stack[-3];
    if (!consp(v0227)) goto v0150;
    v0227 = stack[-3];
    v0227 = qcar(v0227);
    v0227 = (consp(v0227) ? nil : lisp_true);
    goto v0210;

v0210:
    if (v0227 == nil) goto v0138;
    v0227 = qvalue(elt(env, 1)); /* t */
    goto v0131;

v0131:
    if (v0227 == nil) goto v0371;
    v0227 = qvalue(elt(env, 2)); /* nil */
    { popv(5); return onevalue(v0227); }

v0371:
    v0227 = stack[-3];
    v0227 = qcar(v0227);
    v0227 = qcar(v0227);
    v0316 = qcdr(v0227);
    v0227 = (Lisp_Object)17; /* 1 */
    if (v0316 == v0227) goto v0325;
    v0228 = elt(env, 3); /* "ofsf_boundchk:" */
    v0316 = stack[-1];
    v0227 = elt(env, 4); /* "not linear" */
    v0227 = list3(v0228, v0316, v0227);
    nil = C_nil;
    if (exception_pending()) goto v0236;
    env = stack[-4];
    fn = elt(env, 11); /* rederr */
    v0227 = (*qfn1(fn))(qenv(fn), v0227);
    nil = C_nil;
    if (exception_pending()) goto v0236;
    env = stack[-4];
    goto v0325;

v0325:
    v0227 = stack[-3];
    v0227 = qcdr(v0227);
    fn = elt(env, 10); /* reorder */
    v0227 = (*qfn1(fn))(qenv(fn), v0227);
    nil = C_nil;
    if (exception_pending()) goto v0236;
    env = stack[-4];
    fn = elt(env, 12); /* negf */
    v0316 = (*qfn1(fn))(qenv(fn), v0227);
    nil = C_nil;
    if (exception_pending()) goto v0236;
    env = stack[-4];
    v0227 = (Lisp_Object)17; /* 1 */
    stack[0] = cons(v0316, v0227);
    nil = C_nil;
    if (exception_pending()) goto v0236;
    env = stack[-4];
    v0227 = stack[-3];
    v0227 = qcar(v0227);
    v0227 = qcdr(v0227);
    fn = elt(env, 10); /* reorder */
    v0316 = (*qfn1(fn))(qenv(fn), v0227);
    nil = C_nil;
    if (exception_pending()) goto v0236;
    env = stack[-4];
    v0227 = (Lisp_Object)17; /* 1 */
    v0227 = cons(v0316, v0227);
    nil = C_nil;
    if (exception_pending()) goto v0236;
    env = stack[-4];
    fn = elt(env, 13); /* quotsq */
    v0227 = (*qfn2(fn))(qenv(fn), stack[0], v0227);
    nil = C_nil;
    if (exception_pending()) goto v0236;
    env = stack[-4];
    stack[0] = v0227;
    v0227 = stack[-2];
    v0227 = qcar(v0227);
    v0228 = v0227;
    v0316 = v0228;
    v0227 = elt(env, 5); /* equal */
    if (v0316 == v0227) goto v0372;
    v0316 = v0228;
    v0227 = elt(env, 6); /* geq */
    stack[-1] = (v0316 == v0227 ? lisp_true : nil);
    v0227 = stack[-3];
    v0227 = qcar(v0227);
    v0227 = qcdr(v0227);
    fn = elt(env, 14); /* minusf */
    v0227 = (*qfn1(fn))(qenv(fn), v0227);
    nil = C_nil;
    if (exception_pending()) goto v0236;
    env = stack[-4];
    fn = elt(env, 15); /* ofsf_xor */
    v0227 = (*qfn2(fn))(qenv(fn), stack[-1], v0227);
    nil = C_nil;
    if (exception_pending()) goto v0236;
    env = stack[-4];
    if (v0227 == nil) goto v0184;
    v0316 = elt(env, 7); /* lb */
    v0227 = stack[0];
    popv(5);
    return cons(v0316, v0227);

v0184:
    v0316 = elt(env, 8); /* ub */
    v0227 = stack[0];
    popv(5);
    return cons(v0316, v0227);

v0372:
    v0316 = elt(env, 5); /* equal */
    v0227 = stack[0];
    popv(5);
    return cons(v0316, v0227);

v0138:
    v0227 = stack[-3];
    v0227 = qcar(v0227);
    v0227 = qcar(v0227);
    v0316 = qcar(v0227);
    v0227 = stack[-1];
    v0227 = Lneq(nil, v0316, v0227);
    nil = C_nil;
    if (exception_pending()) goto v0236;
    env = stack[-4];
    goto v0131;

v0150:
    v0227 = qvalue(elt(env, 1)); /* t */
    goto v0210;
/* error exit handlers */
v0236:
    popv(5);
    return nil;
}



/* Code for mkunarywedge */

static Lisp_Object CC_mkunarywedge(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0129, v0130, v0190;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mkunarywedge");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0000;
/* end of prologue */
    stack[-1] = nil;
    goto v0017;

v0017:
    v0129 = stack[0];
    if (v0129 == nil) goto v0082;
    v0129 = stack[0];
    v0129 = qcar(v0129);
    v0129 = qcar(v0129);
    v0190 = ncons(v0129);
    nil = C_nil;
    if (exception_pending()) goto v0137;
    env = stack[-2];
    v0129 = stack[0];
    v0129 = qcar(v0129);
    v0130 = qcdr(v0129);
    v0129 = stack[-1];
    v0129 = acons(v0190, v0130, v0129);
    nil = C_nil;
    if (exception_pending()) goto v0137;
    env = stack[-2];
    stack[-1] = v0129;
    v0129 = stack[0];
    v0129 = qcdr(v0129);
    stack[0] = v0129;
    goto v0017;

v0082:
    v0129 = stack[-1];
    {
        popv(3);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v0129);
    }
/* error exit handlers */
v0137:
    popv(3);
    return nil;
}



/* Code for mo!=expvec2a1 */

static Lisp_Object CC_moMexpvec2a1(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0139)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0192, v0193, v0203;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mo=expvec2a1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0139,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0139);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0139;
    stack[-1] = v0000;
/* end of prologue */
    stack[-2] = nil;
    goto v0021;

v0021:
    v0192 = stack[-1];
    if (v0192 == nil) goto v0007;
    v0192 = stack[-1];
    v0193 = qcar(v0192);
    v0192 = (Lisp_Object)1; /* 0 */
    if (v0193 == v0192) goto v0126;
    v0192 = stack[-1];
    v0193 = qcar(v0192);
    v0192 = (Lisp_Object)17; /* 1 */
    if (v0193 == v0192) goto v0133;
    v0203 = elt(env, 1); /* expt */
    v0192 = stack[0];
    v0193 = qcar(v0192);
    v0192 = stack[-1];
    v0192 = qcar(v0192);
    v0193 = list3(v0203, v0193, v0192);
    nil = C_nil;
    if (exception_pending()) goto v0104;
    env = stack[-3];
    v0192 = stack[-2];
    v0192 = cons(v0193, v0192);
    nil = C_nil;
    if (exception_pending()) goto v0104;
    env = stack[-3];
    stack[-2] = v0192;
    v0192 = stack[-1];
    v0192 = qcdr(v0192);
    stack[-1] = v0192;
    v0192 = stack[0];
    v0192 = qcdr(v0192);
    stack[0] = v0192;
    goto v0021;

v0133:
    v0192 = stack[0];
    v0193 = qcar(v0192);
    v0192 = stack[-2];
    v0192 = cons(v0193, v0192);
    nil = C_nil;
    if (exception_pending()) goto v0104;
    env = stack[-3];
    stack[-2] = v0192;
    v0192 = stack[-1];
    v0192 = qcdr(v0192);
    stack[-1] = v0192;
    v0192 = stack[0];
    v0192 = qcdr(v0192);
    stack[0] = v0192;
    goto v0021;

v0126:
    v0192 = stack[-1];
    v0192 = qcdr(v0192);
    stack[-1] = v0192;
    v0192 = stack[0];
    v0192 = qcdr(v0192);
    stack[0] = v0192;
    goto v0021;

v0007:
    v0192 = stack[-2];
    {
        popv(4);
        fn = elt(env, 2); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v0192);
    }
/* error exit handlers */
v0104:
    popv(4);
    return nil;
}



/* Code for test!-bool */

static Lisp_Object CC_testKbool(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0082;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for test-bool");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v0082 = v0000;
/* end of prologue */
    v0082 = qcar(v0082);
    fn = elt(env, 1); /* boolean!-eval1 */
    v0082 = (*qfn1(fn))(qenv(fn), v0082);
    nil = C_nil;
    if (exception_pending()) goto v0007;
    env = stack[0];
    v0082 = ncons(v0082);
    nil = C_nil;
    if (exception_pending()) goto v0007;
    env = stack[0];
    fn = elt(env, 2); /* simp!-prop */
    v0082 = (*qfn1(fn))(qenv(fn), v0082);
    nil = C_nil;
    if (exception_pending()) goto v0007;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 3); /* mk!*sq */
        return (*qfn1(fn))(qenv(fn), v0082);
    }
/* error exit handlers */
v0007:
    popv(1);
    return nil;
}



/* Code for ofsf_smdbgetrel */

static Lisp_Object CC_ofsf_smdbgetrel(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0139)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0129, v0130, v0190, v0134;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ofsf_smdbgetrel");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0190 = v0139;
    v0134 = v0000;
/* end of prologue */

v0002:
    v0130 = v0134;
    v0129 = v0190;
    v0129 = qcar(v0129);
    v0129 = qcdr(v0129);
    v0129 = qcdr(v0129);
    if (equal(v0130, v0129)) goto v0082;
    v0129 = v0190;
    v0129 = qcdr(v0129);
    if (v0129 == nil) goto v0144;
    v0129 = v0190;
    v0129 = qcdr(v0129);
    v0190 = v0129;
    goto v0002;

v0144:
    v0129 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v0129);

v0082:
    v0129 = v0190;
    v0129 = qcar(v0129);
    v0129 = qcdr(v0129);
    v0129 = qcar(v0129);
    return onevalue(v0129);
}



/* Code for my_freeof */

static Lisp_Object CC_my_freeof(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0139)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0143, v0144, v0095;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for my_freeof");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0139,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0139);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0139;
    stack[-1] = v0000;
/* end of prologue */
    v0144 = stack[0];
    v0143 = stack[-1];
    fn = elt(env, 3); /* smember */
    v0143 = (*qfn2(fn))(qenv(fn), v0144, v0143);
    nil = C_nil;
    if (exception_pending()) goto v0130;
    env = stack[-2];
    if (v0143 == nil) goto v0128;
    v0143 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v0143); }

v0128:
    v0095 = qvalue(elt(env, 1)); /* depl!* */
    v0144 = stack[-1];
    v0143 = stack[0];
    {
        popv(3);
        fn = elt(env, 4); /* freeofdepl */
        return (*qfnn(fn))(qenv(fn), 3, v0095, v0144, v0143);
    }
/* error exit handlers */
v0130:
    popv(3);
    return nil;
}



/* Code for get!*nr!*real!*irred!*reps */

static Lisp_Object CC_getHnrHrealHirredHreps(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0003, v0140;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for get*nr*real*irred*reps");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0003 = v0000;
/* end of prologue */
    v0140 = elt(env, 1); /* realrepnumber */
    return get(v0003, v0140);
}



/* Code for qqe_length!-graph!-neighbors */

static Lisp_Object CC_qqe_lengthKgraphKneighbors(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0002, v0063;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for qqe_length-graph-neighbors");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0002 = v0000;
/* end of prologue */
    v0063 = elt(env, 1); /* neighbors */
    return get(v0002, v0063);
}



/* Code for delqip */

static Lisp_Object CC_delqip(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0139)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0096, v0129, v0130;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for delqip");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0139,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0139);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v0139;
    v0130 = v0000;
/* end of prologue */
    v0096 = stack[0];
    if (!consp(v0096)) { Lisp_Object res = stack[0]; popv(1); return onevalue(res); }
    v0129 = v0130;
    v0096 = stack[0];
    v0096 = qcar(v0096);
    if (v0129 == v0096) goto v0007;
    v0129 = v0130;
    v0096 = stack[0];
    fn = elt(env, 1); /* delqip1 */
    v0096 = (*qfn2(fn))(qenv(fn), v0129, v0096);
    nil = C_nil;
    if (exception_pending()) goto v0134;
    { Lisp_Object res = stack[0]; popv(1); return onevalue(res); }

v0007:
    v0096 = stack[0];
    v0096 = qcdr(v0096);
    { popv(1); return onevalue(v0096); }
/* error exit handlers */
v0134:
    popv(1);
    return nil;
}



/* Code for acfsf_0mk2 */

static Lisp_Object CC_acfsf_0mk2(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0139)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0126, v0127, v0128;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for acfsf_0mk2");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0126 = v0139;
    v0127 = v0000;
/* end of prologue */
    v0128 = qvalue(elt(env, 1)); /* nil */
    return list3(v0127, v0126, v0128);
}



/* Code for prload */

static Lisp_Object MS_CDECL CC_prload(Lisp_Object env, int nargs, ...)
{
    Lisp_Object v0008;
    argcheck(nargs, 0, "prload");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for prload");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* end of prologue */
    v0008 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v0008);
}



/* Code for qsimpcomb_standard_integer_part_sf */

static Lisp_Object CC_qsimpcomb_standard_integer_part_sf(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0104, v0324, v0325;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for qsimpcomb_standard_integer_part_sf");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v0000;
/* end of prologue */
    v0104 = qvalue(elt(env, 1)); /* nil */
    stack[-3] = v0104;
    goto v0002;

v0002:
    v0104 = stack[-2];
    v0104 = Lconsp(nil, v0104);
    env = stack[-4];
    if (v0104 == nil) goto v0007;
    v0104 = stack[-2];
    v0104 = qcar(v0104);
    v0104 = qcdr(v0104);
    v0104 = CC_qsimpcomb_standard_integer_part_sf(env, v0104);
    nil = C_nil;
    if (exception_pending()) goto v0204;
    env = stack[-4];
    stack[-1] = v0104;
    v0104 = stack[-2];
    v0104 = qcar(v0104);
    v0104 = qcar(v0104);
    v0324 = qcar(v0104);
    v0104 = stack[-2];
    v0104 = qcar(v0104);
    v0104 = qcar(v0104);
    v0104 = qcdr(v0104);
    v0104 = cons(v0324, v0104);
    nil = C_nil;
    if (exception_pending()) goto v0204;
    env = stack[-4];
    stack[0] = v0104;
    goto v0091;

v0091:
    v0324 = stack[0];
    v0104 = stack[-1];
    v0104 = qcar(v0104);
    v0325 = cons(v0324, v0104);
    nil = C_nil;
    if (exception_pending()) goto v0204;
    env = stack[-4];
    v0324 = qvalue(elt(env, 1)); /* nil */
    v0104 = stack[-3];
    v0104 = acons(v0325, v0324, v0104);
    nil = C_nil;
    if (exception_pending()) goto v0204;
    env = stack[-4];
    stack[-3] = v0104;
    v0104 = stack[-1];
    v0104 = qcdr(v0104);
    stack[-1] = v0104;
    v0104 = stack[-1];
    if (!(v0104 == nil)) goto v0091;
    v0104 = stack[-2];
    v0104 = qcdr(v0104);
    stack[-2] = v0104;
    goto v0002;

v0007:
    v0104 = stack[-2];
    if (v0104 == nil) { Lisp_Object res = stack[-3]; popv(5); return onevalue(res); }
    v0324 = stack[-2];
    v0104 = stack[-3];
    v0104 = cons(v0324, v0104);
    nil = C_nil;
    if (exception_pending()) goto v0204;
    stack[-3] = v0104;
    { Lisp_Object res = stack[-3]; popv(5); return onevalue(res); }
/* error exit handlers */
v0204:
    popv(5);
    return nil;
}



/* Code for groebreduceonestepint */

static Lisp_Object MS_CDECL CC_groebreduceonestepint(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0228, v0378, v0064;
    Lisp_Object fn;
    Lisp_Object v0042, v0001, v0008, v0139, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 5, "groebreduceonestepint");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0139 = va_arg(aa, Lisp_Object);
    v0008 = va_arg(aa, Lisp_Object);
    v0001 = va_arg(aa, Lisp_Object);
    v0042 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for groebreduceonestepint");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push5(v0042,v0001,v0008,v0139,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v0000,v0139,v0008,v0001,v0042);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0042;
    stack[-4] = v0001;
    stack[-3] = v0008;
    stack[-6] = v0139;
    stack[-2] = v0000;
/* end of prologue */
    v0228 = stack[-1];
    fn = elt(env, 8); /* vdpred */
    v0228 = (*qfn1(fn))(qenv(fn), v0228);
    nil = C_nil;
    if (exception_pending()) goto v0379;
    env = stack[-8];
    stack[0] = v0228;
    v0378 = v0228;
    v0228 = v0378;
    if (v0228 == nil) goto v0131;
    v0228 = v0378;
    v0228 = qcdr(v0228);
    v0228 = qcdr(v0228);
    v0228 = qcdr(v0228);
    v0228 = qcar(v0228);
    v0228 = (v0228 == nil ? lisp_true : nil);
    goto v0148;

v0148:
    if (v0228 == nil) goto v0092;
    v0228 = stack[-2];
    fn = elt(env, 8); /* vdpred */
    v0228 = (*qfn1(fn))(qenv(fn), v0228);
    nil = C_nil;
    if (exception_pending()) goto v0379;
    env = stack[-8];
    stack[-2] = v0228;
    v0228 = stack[-6];
    qvalue(elt(env, 2)) = v0228; /* secondvalue!* */
    { Lisp_Object res = stack[-2]; popv(9); return onevalue(res); }

v0092:
    v0378 = stack[-4];
    v0228 = stack[-1];
    v0228 = qcdr(v0228);
    v0228 = qcar(v0228);
    fn = elt(env, 9); /* vevdif */
    v0228 = (*qfn2(fn))(qenv(fn), v0378, v0228);
    nil = C_nil;
    if (exception_pending()) goto v0379;
    env = stack[-8];
    stack[-7] = v0228;
    v0228 = stack[-1];
    v0228 = qcdr(v0228);
    v0228 = qcdr(v0228);
    v0228 = qcar(v0228);
    stack[-5] = v0228;
    v0228 = qvalue(elt(env, 3)); /* !*groebdivide */
    if (v0228 == nil) goto v0094;
    v0378 = stack[-3];
    v0228 = stack[-5];
    fn = elt(env, 10); /* vbcgcd */
    v0228 = (*qfn2(fn))(qenv(fn), v0378, v0228);
    nil = C_nil;
    if (exception_pending()) goto v0379;
    env = stack[-8];
    goto v0093;

v0093:
    stack[-4] = v0228;
    v0378 = stack[-5];
    v0228 = stack[-4];
    fn = elt(env, 11); /* vbcquot */
    v0228 = (*qfn2(fn))(qenv(fn), v0378, v0228);
    nil = C_nil;
    if (exception_pending()) goto v0379;
    env = stack[-8];
    stack[-5] = v0228;
    v0378 = stack[-3];
    v0228 = stack[-4];
    fn = elt(env, 11); /* vbcquot */
    v0228 = (*qfn2(fn))(qenv(fn), v0378, v0228);
    nil = C_nil;
    if (exception_pending()) goto v0379;
    env = stack[-8];
    stack[-4] = v0228;
    v0228 = stack[-6];
    if (v0228 == nil) goto v0199;
    v0228 = stack[-6];
    if (v0228 == nil) goto v0369;
    v0228 = stack[-6];
    v0228 = qcdr(v0228);
    v0228 = qcdr(v0228);
    v0228 = qcdr(v0228);
    v0228 = qcar(v0228);
    v0228 = (v0228 == nil ? lisp_true : nil);
    goto v0084;

v0084:
    if (!(v0228 == nil)) goto v0199;
    v0378 = stack[-6];
    v0228 = stack[-5];
    fn = elt(env, 12); /* vdpvbcprod */
    v0228 = (*qfn2(fn))(qenv(fn), v0378, v0228);
    nil = C_nil;
    if (exception_pending()) goto v0379;
    env = stack[-8];
    stack[-6] = v0228;
    goto v0199;

v0199:
    v0228 = qvalue(elt(env, 4)); /* !*groebprot */
    if (v0228 == nil) goto v0220;
    stack[-3] = stack[-5];
    v0228 = stack[-4];
    fn = elt(env, 13); /* vbcneg */
    v0064 = (*qfn1(fn))(qenv(fn), v0228);
    nil = C_nil;
    if (exception_pending()) goto v0379;
    env = stack[-8];
    v0378 = stack[-7];
    v0228 = stack[-1];
    fn = elt(env, 14); /* groebreductionprotocol */
    v0228 = (*qfnn(fn))(qenv(fn), 4, stack[-3], v0064, v0378, v0228);
    nil = C_nil;
    if (exception_pending()) goto v0379;
    env = stack[-8];
    goto v0220;

v0220:
    v0228 = stack[-2];
    fn = elt(env, 8); /* vdpred */
    stack[-3] = (*qfn1(fn))(qenv(fn), v0228);
    nil = C_nil;
    if (exception_pending()) goto v0379;
    env = stack[-8];
    stack[-2] = stack[-5];
    v0378 = qvalue(elt(env, 5)); /* vdpvars!* */
    v0228 = qvalue(elt(env, 6)); /* nil */
    fn = elt(env, 15); /* vevmaptozero1 */
    stack[-1] = (*qfn2(fn))(qenv(fn), v0378, v0228);
    nil = C_nil;
    if (exception_pending()) goto v0379;
    env = stack[-8];
    v0228 = stack[-4];
    fn = elt(env, 13); /* vbcneg */
    v0378 = (*qfn1(fn))(qenv(fn), v0228);
    nil = C_nil;
    if (exception_pending()) goto v0379;
    env = stack[-8];
    v0228 = stack[-7];
    fn = elt(env, 16); /* vdpilcomb1 */
    v0228 = (*qfnn(fn))(qenv(fn), 6, stack[-3], stack[-2], stack[-1], stack[0], v0378, v0228);
    nil = C_nil;
    if (exception_pending()) goto v0379;
    env = stack[-8];
    stack[-2] = v0228;
    v0228 = stack[-6];
    qvalue(elt(env, 2)) = v0228; /* secondvalue!* */
    v0228 = stack[-5];
    qvalue(elt(env, 7)) = v0228; /* thirdvalue!* */
    { Lisp_Object res = stack[-2]; popv(9); return onevalue(res); }

v0369:
    v0228 = qvalue(elt(env, 1)); /* t */
    goto v0084;

v0094:
    v0228 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 17); /* vbcfi */
    v0228 = (*qfn1(fn))(qenv(fn), v0228);
    nil = C_nil;
    if (exception_pending()) goto v0379;
    env = stack[-8];
    goto v0093;

v0131:
    v0228 = qvalue(elt(env, 1)); /* t */
    goto v0148;
/* error exit handlers */
v0379:
    popv(9);
    return nil;
}



/* Code for groebmakepair */

static Lisp_Object CC_groebmakepair(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0139)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0323, v0381, v0322;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for groebmakepair");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0139,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0139);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v0139;
    stack[-3] = v0000;
/* end of prologue */
    v0323 = stack[-3];
    v0323 = qcdr(v0323);
    v0381 = qcar(v0323);
    v0323 = stack[-2];
    v0323 = qcdr(v0323);
    v0323 = qcar(v0323);
    fn = elt(env, 2); /* vevlcm */
    v0323 = (*qfn2(fn))(qenv(fn), v0381, v0323);
    nil = C_nil;
    if (exception_pending()) goto v0216;
    env = stack[-5];
    stack[-4] = v0323;
    v0323 = qvalue(elt(env, 1)); /* !*gsugar */
    if (v0323 == nil) goto v0199;
    v0323 = stack[-3];
    fn = elt(env, 3); /* gsugar */
    stack[0] = (*qfn1(fn))(qenv(fn), v0323);
    nil = C_nil;
    if (exception_pending()) goto v0216;
    env = stack[-5];
    v0381 = stack[-4];
    v0323 = stack[-3];
    v0323 = qcdr(v0323);
    v0323 = qcar(v0323);
    fn = elt(env, 4); /* vevdif */
    v0323 = (*qfn2(fn))(qenv(fn), v0381, v0323);
    nil = C_nil;
    if (exception_pending()) goto v0216;
    env = stack[-5];
    fn = elt(env, 5); /* vevtdeg */
    v0323 = (*qfn1(fn))(qenv(fn), v0323);
    nil = C_nil;
    if (exception_pending()) goto v0216;
    env = stack[-5];
    v0323 = (Lisp_Object)(int32_t)((int32_t)stack[0] + (int32_t)v0323 - TAG_FIXNUM);
    stack[-1] = v0323;
    v0323 = stack[-2];
    fn = elt(env, 3); /* gsugar */
    stack[0] = (*qfn1(fn))(qenv(fn), v0323);
    nil = C_nil;
    if (exception_pending()) goto v0216;
    env = stack[-5];
    v0381 = stack[-4];
    v0323 = stack[-2];
    v0323 = qcdr(v0323);
    v0323 = qcar(v0323);
    fn = elt(env, 4); /* vevdif */
    v0323 = (*qfn2(fn))(qenv(fn), v0381, v0323);
    nil = C_nil;
    if (exception_pending()) goto v0216;
    env = stack[-5];
    fn = elt(env, 5); /* vevtdeg */
    v0323 = (*qfn1(fn))(qenv(fn), v0323);
    nil = C_nil;
    if (exception_pending()) goto v0216;
    env = stack[-5];
    v0323 = (Lisp_Object)(int32_t)((int32_t)stack[0] + (int32_t)v0323 - TAG_FIXNUM);
    stack[0] = stack[-4];
    v0381 = stack[-1];
    fn = elt(env, 6); /* max */
    v0323 = (*qfn2(fn))(qenv(fn), v0381, v0323);
    nil = C_nil;
    if (exception_pending()) goto v0216;
    {
        Lisp_Object v0336 = stack[0];
        Lisp_Object v0382 = stack[-3];
        Lisp_Object v0383 = stack[-2];
        popv(6);
        return list4(v0336, v0382, v0383, v0323);
    }

v0199:
    v0322 = stack[-4];
    v0381 = stack[-3];
    v0323 = stack[-2];
    popv(6);
    return list3(v0322, v0381, v0323);
/* error exit handlers */
v0216:
    popv(6);
    return nil;
}



/* Code for make_wedge_pair */

static Lisp_Object CC_make_wedge_pair(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0139)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0083, v0377, v0084;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for make_wedge_pair");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0139,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0139);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0139;
    stack[-2] = v0000;
/* end of prologue */
    v0377 = stack[-2];
    v0083 = stack[-2];
    stack[0] = list2(v0377, v0083);
    nil = C_nil;
    if (exception_pending()) goto v0322;
    env = stack[-4];
    v0083 = stack[-1];
    fn = elt(env, 5); /* xval */
    v0083 = (*qfn1(fn))(qenv(fn), v0083);
    nil = C_nil;
    if (exception_pending()) goto v0322;
    env = stack[-4];
    fn = elt(env, 6); /* xlcm */
    v0083 = (*qfn2(fn))(qenv(fn), stack[0], v0083);
    nil = C_nil;
    if (exception_pending()) goto v0322;
    env = stack[-4];
    stack[-3] = v0083;
    v0083 = qvalue(elt(env, 1)); /* !*twosided */
    if (v0083 == nil) goto v0144;
    v0083 = qvalue(elt(env, 2)); /* xtruncate!* */
    if (!(v0083 == nil)) goto v0144;

v0090:
    v0377 = stack[-2];
    v0083 = stack[-1];
    fn = elt(env, 7); /* overall_factor */
    v0083 = (*qfn2(fn))(qenv(fn), v0377, v0083);
    nil = C_nil;
    if (exception_pending()) goto v0322;
    env = stack[-4];
    if (v0083 == nil) goto v0197;
    v0083 = qvalue(elt(env, 3)); /* nil */
    { popv(5); return onevalue(v0083); }

v0197:
    v0083 = stack[-3];
    fn = elt(env, 8); /* mknwedge */
    v0083 = (*qfn1(fn))(qenv(fn), v0083);
    nil = C_nil;
    if (exception_pending()) goto v0322;
    env = stack[-4];
    fn = elt(env, 9); /* xdegreecheck */
    v0083 = (*qfn1(fn))(qenv(fn), v0083);
    nil = C_nil;
    if (exception_pending()) goto v0322;
    env = stack[-4];
    if (v0083 == nil) goto v0145;
    v0083 = qvalue(elt(env, 3)); /* nil */
    { popv(5); return onevalue(v0083); }

v0145:
    stack[0] = elt(env, 4); /* wedge_pair */
    v0084 = stack[-2];
    v0377 = (Lisp_Object)17; /* 1 */
    v0083 = (Lisp_Object)17; /* 1 */
    v0083 = list2star(v0084, v0377, v0083);
    nil = C_nil;
    if (exception_pending()) goto v0322;
    env = stack[-4];
    v0377 = ncons(v0083);
    nil = C_nil;
    if (exception_pending()) goto v0322;
    v0083 = stack[-1];
    {
        Lisp_Object v0321 = stack[-3];
        Lisp_Object v0080 = stack[0];
        popv(5);
        return list4(v0321, v0080, v0377, v0083);
    }

v0144:
    stack[0] = stack[-2];
    v0083 = stack[-1];
    fn = elt(env, 5); /* xval */
    v0083 = (*qfn1(fn))(qenv(fn), v0083);
    nil = C_nil;
    if (exception_pending()) goto v0322;
    env = stack[-4];
    v0083 = Lmemq(nil, stack[0], v0083);
    if (!(v0083 == nil)) goto v0090;
    v0083 = qvalue(elt(env, 3)); /* nil */
    { popv(5); return onevalue(v0083); }
/* error exit handlers */
v0322:
    popv(5);
    return nil;
}



/* Code for coeff_sortl */

static Lisp_Object MS_CDECL CC_coeff_sortl(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0148, v0131, v0132;
    Lisp_Object fn;
    Lisp_Object v0008, v0139, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "coeff_sortl");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0139 = va_arg(aa, Lisp_Object);
    v0008 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for coeff_sortl");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0008,v0139,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0139,v0008);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0008;
    stack[-1] = v0139;
    v0148 = v0000;
/* end of prologue */
    v0131 = v0148;
    v0148 = stack[0];
    fn = elt(env, 1); /* coeff_ordn */
    v0132 = (*qfn2(fn))(qenv(fn), v0131, v0148);
    nil = C_nil;
    if (exception_pending()) goto v0210;
    env = stack[-2];
    v0131 = stack[-1];
    v0148 = stack[0];
    {
        popv(3);
        fn = elt(env, 2); /* coeff_sortl1 */
        return (*qfnn(fn))(qenv(fn), 3, v0132, v0131, v0148);
    }
/* error exit handlers */
v0210:
    popv(3);
    return nil;
}



/* Code for df!-chain!-rule */

static Lisp_Object MS_CDECL CC_dfKchainKrule(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0105, v0194, v0374;
    Lisp_Object fn;
    Lisp_Object v0008, v0139, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "df-chain-rule");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0139 = va_arg(aa, Lisp_Object);
    v0008 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for df-chain-rule");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0008,v0139,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0139,v0008);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v0008;
    stack[-3] = v0139;
    stack[-4] = v0000;
/* end of prologue */
    v0194 = qvalue(elt(env, 1)); /* nil */
    v0105 = (Lisp_Object)17; /* 1 */
    v0105 = cons(v0194, v0105);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-6];
    v0194 = v0105;
    v0105 = stack[0];
    stack[-5] = v0105;
    goto v0211;

v0211:
    v0105 = stack[-5];
    if (v0105 == nil) { popv(7); return onevalue(v0194); }
    v0105 = stack[-5];
    v0105 = qcar(v0105);
    stack[-2] = v0105;
    stack[-1] = v0194;
    v0374 = elt(env, 2); /* df */
    v0194 = stack[-4];
    v0105 = stack[-2];
    v0105 = list3(v0374, v0194, v0105);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-6];
    fn = elt(env, 3); /* simp */
    stack[0] = (*qfn1(fn))(qenv(fn), v0105);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-6];
    v0374 = elt(env, 2); /* df */
    v0194 = stack[-2];
    v0105 = stack[-3];
    v0105 = list3(v0374, v0194, v0105);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-6];
    fn = elt(env, 3); /* simp */
    v0105 = (*qfn1(fn))(qenv(fn), v0105);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-6];
    fn = elt(env, 4); /* multsq */
    v0105 = (*qfn2(fn))(qenv(fn), stack[0], v0105);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-6];
    fn = elt(env, 5); /* addsq */
    v0105 = (*qfn2(fn))(qenv(fn), stack[-1], v0105);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-6];
    v0194 = v0105;
    v0105 = stack[-5];
    v0105 = qcdr(v0105);
    stack[-5] = v0105;
    goto v0211;
/* error exit handlers */
v0193:
    popv(7);
    return nil;
}



/* Code for dp!=retimes */

static Lisp_Object CC_dpMretimes(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0197, v0178, v0179;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dp=retimes");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0178 = v0000;
/* end of prologue */

v0007:
    v0197 = v0178;
    v0179 = qcar(v0197);
    v0197 = (Lisp_Object)17; /* 1 */
    if (v0179 == v0197) goto v0079;
    v0197 = v0178;
    v0197 = qcdr(v0197);
    if (v0197 == nil) goto v0150;
    v0197 = elt(env, 1); /* times */
    return cons(v0197, v0178);

v0150:
    v0197 = v0178;
    v0197 = qcar(v0197);
    return onevalue(v0197);

v0079:
    v0197 = v0178;
    v0197 = qcdr(v0197);
    if (v0197 == nil) goto v0202;
    v0197 = v0178;
    v0197 = qcdr(v0197);
    v0178 = v0197;
    goto v0007;

v0202:
    v0197 = (Lisp_Object)17; /* 1 */
    return onevalue(v0197);
}



/* Code for general!-difference!-mod!-p */

static Lisp_Object CC_generalKdifferenceKmodKp(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0139)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0003, v0140;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for general-difference-mod-p");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0139,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0139);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0003 = v0139;
    v0140 = v0000;
/* end of prologue */
    stack[0] = v0140;
    fn = elt(env, 1); /* general!-minus!-mod!-p */
    v0003 = (*qfn1(fn))(qenv(fn), v0003);
    nil = C_nil;
    if (exception_pending()) goto v0127;
    env = stack[-1];
    {
        Lisp_Object v0128 = stack[0];
        popv(2);
        fn = elt(env, 2); /* general!-plus!-mod!-p */
        return (*qfn2(fn))(qenv(fn), v0128, v0003);
    }
/* error exit handlers */
v0127:
    popv(2);
    return nil;
}



/* Code for null!+vec!+p */

static Lisp_Object CC_nullLvecLp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0003;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for null+vec+p");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v0003 = v0000;
/* end of prologue */
    fn = elt(env, 2); /* mk!+squared!+norm */
    v0003 = (*qfn1(fn))(qenv(fn), v0003);
    nil = C_nil;
    if (exception_pending()) goto v0140;
    env = stack[0];
    fn = elt(env, 3); /* my!+nullsq!+p */
    v0003 = (*qfn1(fn))(qenv(fn), v0003);
    nil = C_nil;
    if (exception_pending()) goto v0140;
    env = stack[0];
    if (v0003 == nil) goto v0017;
    v0003 = qvalue(elt(env, 1)); /* t */
    { popv(1); return onevalue(v0003); }

v0017:
    v0003 = nil;
    { popv(1); return onevalue(v0003); }
/* error exit handlers */
v0140:
    popv(1);
    return nil;
}



/* Code for qqe_length!-graph!-marked */

static Lisp_Object CC_qqe_lengthKgraphKmarked(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0002, v0063;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for qqe_length-graph-marked");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0002 = v0000;
/* end of prologue */
    v0063 = elt(env, 1); /* blockmark */
    return get(v0002, v0063);
}



/* Code for pasf_negateat */

static Lisp_Object CC_pasf_negateat(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0189, v0338, v0188;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pasf_negateat");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v0000;
/* end of prologue */
    v0338 = stack[0];
    v0189 = elt(env, 1); /* true */
    if (v0338 == v0189) goto v0082;
    v0338 = stack[0];
    v0189 = elt(env, 3); /* false */
    v0189 = (v0338 == v0189 ? lisp_true : nil);
    goto v0079;

v0079:
    if (v0189 == nil) goto v0195;
    v0338 = stack[0];
    v0189 = elt(env, 3); /* false */
    if (v0338 == v0189) goto v0144;
    v0189 = elt(env, 3); /* false */
    { popv(2); return onevalue(v0189); }

v0144:
    v0189 = elt(env, 1); /* true */
    { popv(2); return onevalue(v0189); }

v0195:
    v0338 = stack[0];
    v0189 = elt(env, 1); /* true */
    if (v0338 == v0189) goto v0371;
    v0338 = stack[0];
    v0189 = elt(env, 3); /* false */
    v0189 = (v0338 == v0189 ? lisp_true : nil);
    goto v0094;

v0094:
    if (v0189 == nil) goto v0208;
    v0189 = stack[0];
    v0338 = v0189;
    goto v0090;

v0090:
    v0189 = elt(env, 4); /* (cong ncong) */
    v0189 = Lmemq(nil, v0338, v0189);
    if (v0189 == nil) goto v0166;
    v0338 = stack[0];
    v0189 = elt(env, 1); /* true */
    if (v0338 == v0189) goto v0388;
    v0338 = stack[0];
    v0189 = elt(env, 3); /* false */
    v0189 = (v0338 == v0189 ? lisp_true : nil);
    goto v0389;

v0389:
    if (v0189 == nil) goto v0390;
    v0189 = stack[0];
    goto v0382;

v0382:
    fn = elt(env, 5); /* pasf_lnegrel */
    v0338 = (*qfn1(fn))(qenv(fn), v0189);
    nil = C_nil;
    if (exception_pending()) goto v0391;
    env = stack[-1];
    v0189 = stack[0];
    v0189 = qcar(v0189);
    v0189 = qcdr(v0189);
    fn = elt(env, 6); /* pasf_mkop */
    v0188 = (*qfn2(fn))(qenv(fn), v0338, v0189);
    nil = C_nil;
    if (exception_pending()) goto v0391;
    v0189 = stack[0];
    v0189 = qcdr(v0189);
    v0338 = qcar(v0189);
    v0189 = stack[0];
    v0189 = qcdr(v0189);
    v0189 = qcdr(v0189);
    v0189 = qcar(v0189);
    popv(2);
    return list3(v0188, v0338, v0189);

v0390:
    v0189 = stack[0];
    v0189 = qcar(v0189);
    v0189 = Lconsp(nil, v0189);
    env = stack[-1];
    if (v0189 == nil) goto v0170;
    v0189 = stack[0];
    v0189 = qcar(v0189);
    v0189 = qcar(v0189);
    goto v0382;

v0170:
    v0189 = stack[0];
    v0189 = qcar(v0189);
    goto v0382;

v0388:
    v0189 = qvalue(elt(env, 2)); /* t */
    goto v0389;

v0166:
    v0338 = stack[0];
    v0189 = elt(env, 1); /* true */
    if (v0338 == v0189) goto v0236;
    v0338 = stack[0];
    v0189 = elt(env, 3); /* false */
    v0189 = (v0338 == v0189 ? lisp_true : nil);
    goto v0366;

v0366:
    if (v0189 == nil) goto v0064;
    v0189 = stack[0];
    goto v0228;

v0228:
    fn = elt(env, 5); /* pasf_lnegrel */
    v0188 = (*qfn1(fn))(qenv(fn), v0189);
    nil = C_nil;
    if (exception_pending()) goto v0391;
    v0189 = stack[0];
    v0189 = qcdr(v0189);
    v0338 = qcar(v0189);
    v0189 = stack[0];
    v0189 = qcdr(v0189);
    v0189 = qcdr(v0189);
    v0189 = qcar(v0189);
    popv(2);
    return list3(v0188, v0338, v0189);

v0064:
    v0189 = stack[0];
    v0189 = qcar(v0189);
    v0189 = Lconsp(nil, v0189);
    env = stack[-1];
    if (v0189 == nil) goto v0110;
    v0189 = stack[0];
    v0189 = qcar(v0189);
    v0189 = qcar(v0189);
    goto v0228;

v0110:
    v0189 = stack[0];
    v0189 = qcar(v0189);
    goto v0228;

v0236:
    v0189 = qvalue(elt(env, 2)); /* t */
    goto v0366;

v0208:
    v0189 = stack[0];
    v0189 = qcar(v0189);
    v0189 = Lconsp(nil, v0189);
    env = stack[-1];
    if (v0189 == nil) goto v0325;
    v0189 = stack[0];
    v0189 = qcar(v0189);
    v0189 = qcar(v0189);
    v0338 = v0189;
    goto v0090;

v0325:
    v0189 = stack[0];
    v0189 = qcar(v0189);
    v0338 = v0189;
    goto v0090;

v0371:
    v0189 = qvalue(elt(env, 2)); /* t */
    goto v0094;

v0082:
    v0189 = qvalue(elt(env, 2)); /* t */
    goto v0079;
/* error exit handlers */
v0391:
    popv(2);
    return nil;
}



/* Code for sfto_kexp */

static Lisp_Object CC_sfto_kexp(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0139)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0133, v0092;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sfto_kexp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0139,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0139);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0139;
    stack[-1] = v0000;
/* end of prologue */
    v0092 = stack[0];
    v0133 = (Lisp_Object)1; /* 0 */
    v0133 = Leqn(nil, v0092, v0133);
    nil = C_nil;
    if (exception_pending()) goto v0209;
    env = stack[-2];
    if (v0133 == nil) goto v0095;
    v0133 = (Lisp_Object)17; /* 1 */
    { popv(3); return onevalue(v0133); }

v0095:
    v0092 = stack[-1];
    v0133 = stack[0];
    fn = elt(env, 2); /* to */
    v0092 = (*qfn2(fn))(qenv(fn), v0092, v0133);
    nil = C_nil;
    if (exception_pending()) goto v0209;
    env = stack[-2];
    v0133 = (Lisp_Object)17; /* 1 */
    v0133 = cons(v0092, v0133);
    nil = C_nil;
    if (exception_pending()) goto v0209;
    popv(3);
    return ncons(v0133);
/* error exit handlers */
v0209:
    popv(3);
    return nil;
}



/* Code for make!-image!-mod!-p */

static Lisp_Object CC_makeKimageKmodKp(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0139)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0135, v0209;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for make-image-mod-p");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0139,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0139);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0139;
    stack[-1] = v0000;
/* end of prologue */
    v0209 = stack[-1];
    v0135 = stack[0];
    fn = elt(env, 3); /* degree!-in!-variable */
    v0135 = (*qfn2(fn))(qenv(fn), v0209, v0135);
    nil = C_nil;
    if (exception_pending()) goto v0090;
    env = stack[-3];
    stack[-2] = v0135;
    v0209 = stack[-1];
    v0135 = stack[0];
    fn = elt(env, 4); /* make!-univariate!-image!-mod!-p */
    v0135 = (*qfn2(fn))(qenv(fn), v0209, v0135);
    nil = C_nil;
    if (exception_pending()) goto v0090;
    env = stack[-3];
    stack[-1] = v0135;
    v0209 = stack[-1];
    v0135 = stack[0];
    fn = elt(env, 3); /* degree!-in!-variable */
    v0209 = (*qfn2(fn))(qenv(fn), v0209, v0135);
    nil = C_nil;
    if (exception_pending()) goto v0090;
    env = stack[-3];
    v0135 = stack[-2];
    if (equal(v0209, v0135)) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v0135 = qvalue(elt(env, 1)); /* t */
    qvalue(elt(env, 2)) = v0135; /* unlucky!-case */
    { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
/* error exit handlers */
v0090:
    popv(4);
    return nil;
}



/* Code for ps!:set!-term */

static Lisp_Object MS_CDECL CC_psTsetKterm(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0229, v0230, v0152;
    Lisp_Object fn;
    Lisp_Object v0008, v0139, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "ps:set-term");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0139 = va_arg(aa, Lisp_Object);
    v0008 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ps:set-term");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0008,v0139,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0139,v0008);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-2] = v0008;
    stack[-3] = v0139;
    stack[-4] = v0000;
/* end of prologue */
    v0229 = stack[-4];
    fn = elt(env, 7); /* ps!:order */
    v0229 = (*qfn1(fn))(qenv(fn), v0229);
    nil = C_nil;
    if (exception_pending()) goto v0182;
    env = stack[-6];
    stack[-5] = v0229;
    v0230 = stack[-3];
    v0229 = stack[-5];
    v0229 = (Lisp_Object)lessp2(v0230, v0229);
    nil = C_nil;
    if (exception_pending()) goto v0182;
    v0229 = v0229 ? lisp_true : nil;
    env = stack[-6];
    if (v0229 == nil) goto v0179;
    stack[-1] = elt(env, 1); /* tps */
    stack[0] = (Lisp_Object)49; /* 3 */
    v0152 = stack[-3];
    v0230 = elt(env, 2); /* "less than the order of " */
    v0229 = stack[-4];
    v0229 = list3(v0152, v0230, v0229);
    nil = C_nil;
    if (exception_pending()) goto v0182;
    env = stack[-6];
    fn = elt(env, 8); /* rerror */
    v0229 = (*qfnn(fn))(qenv(fn), 3, stack[-1], stack[0], v0229);
    nil = C_nil;
    if (exception_pending()) goto v0182;
    env = stack[-6];
    goto v0063;

v0063:
    v0229 = stack[-4];
    if (!consp(v0229)) goto v0233;
    v0229 = stack[-4];
    v0230 = qcar(v0229);
    v0229 = elt(env, 5); /* !:ps!: */
    if (v0230 == v0229) goto v0081;
    v0229 = stack[-4];
    v0229 = qcar(v0229);
    if (!symbolp(v0229)) v0229 = nil;
    else { v0229 = qfastgets(v0229);
           if (v0229 != nil) { v0229 = elt(v0229, 8); /* dname */
#ifdef RECORD_GET
             if (v0229 != SPID_NOPROP)
                record_get(elt(fastget_names, 8), 1);
             else record_get(elt(fastget_names, 8), 0),
                v0229 = nil; }
           else record_get(elt(fastget_names, 8), 0); }
#else
             if (v0229 == SPID_NOPROP) v0229 = nil; }}
#endif
    goto v0086;

v0086:
    if (v0229 == nil) goto v0372;
    v0152 = (Lisp_Object)1; /* 0 */
    v0230 = stack[-4];
    v0229 = (Lisp_Object)17; /* 1 */
    v0229 = list2star(v0152, v0230, v0229);
    nil = C_nil;
    if (exception_pending()) goto v0182;
    env = stack[-6];
    v0229 = ncons(v0229);
    nil = C_nil;
    if (exception_pending()) goto v0182;
    env = stack[-6];
    goto v0370;

v0370:
    stack[0] = v0229;
    v0229 = stack[-2];
    if (!consp(v0229)) goto v0074;
    v0229 = stack[-2];
    v0230 = qcar(v0229);
    v0229 = qvalue(elt(env, 6)); /* nil */
    v0229 = Lneq(nil, v0230, v0229);
    nil = C_nil;
    if (exception_pending()) goto v0182;
    env = stack[-6];
    goto v0073;

v0073:
    if (v0229 == nil) goto v0159;
    v0229 = stack[0];
    if (v0229 == nil) goto v0386;
    v0230 = stack[-3];
    v0229 = stack[-5];
    v0230 = difference2(v0230, v0229);
    nil = C_nil;
    if (exception_pending()) goto v0182;
    env = stack[-6];
    v0229 = stack[-2];
    v0229 = cons(v0230, v0229);
    nil = C_nil;
    if (exception_pending()) goto v0182;
    env = stack[-6];
    v0229 = ncons(v0229);
    nil = C_nil;
    if (exception_pending()) goto v0182;
    env = stack[-6];
    v0229 = Lnconc(nil, stack[0], v0229);
    nil = C_nil;
    if (exception_pending()) goto v0182;
    env = stack[-6];
    goto v0396;

v0396:
    v0152 = stack[-4];
    v0230 = (Lisp_Object)17; /* 1 */
    v0229 = stack[-3];
    fn = elt(env, 9); /* ps!:putv */
    v0229 = (*qfnn(fn))(qenv(fn), 3, v0152, v0230, v0229);
    nil = C_nil;
    if (exception_pending()) goto v0182;
    v0229 = nil;
    { popv(7); return onevalue(v0229); }

v0386:
    stack[-1] = stack[-4];
    stack[0] = (Lisp_Object)81; /* 5 */
    v0230 = stack[-3];
    v0229 = stack[-5];
    v0230 = difference2(v0230, v0229);
    nil = C_nil;
    if (exception_pending()) goto v0182;
    env = stack[-6];
    v0229 = stack[-2];
    v0229 = cons(v0230, v0229);
    nil = C_nil;
    if (exception_pending()) goto v0182;
    env = stack[-6];
    v0229 = ncons(v0229);
    nil = C_nil;
    if (exception_pending()) goto v0182;
    env = stack[-6];
    fn = elt(env, 9); /* ps!:putv */
    v0229 = (*qfnn(fn))(qenv(fn), 3, stack[-1], stack[0], v0229);
    nil = C_nil;
    if (exception_pending()) goto v0182;
    env = stack[-6];
    goto v0396;

v0159:
    v0230 = stack[-3];
    v0229 = stack[-5];
    if (!(equal(v0230, v0229))) goto v0396;
    stack[-1] = stack[-4];
    stack[0] = (Lisp_Object)1; /* 0 */
    v0229 = stack[-3];
    v0229 = add1(v0229);
    nil = C_nil;
    if (exception_pending()) goto v0182;
    env = stack[-6];
    fn = elt(env, 9); /* ps!:putv */
    v0229 = (*qfnn(fn))(qenv(fn), 3, stack[-1], stack[0], v0229);
    nil = C_nil;
    if (exception_pending()) goto v0182;
    env = stack[-6];
    goto v0396;

v0074:
    v0229 = qvalue(elt(env, 4)); /* t */
    goto v0073;

v0372:
    v0230 = stack[-4];
    v0229 = (Lisp_Object)81; /* 5 */
    fn = elt(env, 10); /* ps!:getv */
    v0229 = (*qfn2(fn))(qenv(fn), v0230, v0229);
    nil = C_nil;
    if (exception_pending()) goto v0182;
    env = stack[-6];
    goto v0370;

v0081:
    v0229 = qvalue(elt(env, 6)); /* nil */
    goto v0086;

v0233:
    v0229 = qvalue(elt(env, 4)); /* t */
    goto v0086;

v0179:
    stack[0] = stack[-3];
    v0229 = stack[-4];
    fn = elt(env, 11); /* ps!:last!-term */
    v0229 = (*qfn1(fn))(qenv(fn), v0229);
    nil = C_nil;
    if (exception_pending()) goto v0182;
    env = stack[-6];
    v0229 = (Lisp_Object)lesseq2(stack[0], v0229);
    nil = C_nil;
    if (exception_pending()) goto v0182;
    v0229 = v0229 ? lisp_true : nil;
    env = stack[-6];
    if (v0229 == nil) goto v0063;
    stack[-1] = elt(env, 1); /* tps */
    stack[0] = (Lisp_Object)65; /* 4 */
    v0152 = stack[-3];
    v0230 = elt(env, 3); /* "less than power of last term of " */
    v0229 = stack[-4];
    v0229 = list3(v0152, v0230, v0229);
    nil = C_nil;
    if (exception_pending()) goto v0182;
    env = stack[-6];
    fn = elt(env, 8); /* rerror */
    v0229 = (*qfnn(fn))(qenv(fn), 3, stack[-1], stack[0], v0229);
    nil = C_nil;
    if (exception_pending()) goto v0182;
    env = stack[-6];
    goto v0063;
/* error exit handlers */
v0182:
    popv(7);
    return nil;
}



/* Code for solvealgtrig01 */

static Lisp_Object CC_solvealgtrig01(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0139)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0176, v0177;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for solvealgtrig01");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0139,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0139);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0139;
    stack[-1] = v0000;
/* end of prologue */

v0021:
    v0176 = stack[-1];
    if (!consp(v0176)) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v0176 = stack[-1];
    v0177 = qcar(v0176);
    v0176 = elt(env, 1); /* (sin cos tan cot sinh cosh tanh coth) */
    v0176 = Lmemq(nil, v0177, v0176);
    if (v0176 == nil) goto v0179;
    v0176 = stack[-1];
    v0176 = qcdr(v0176);
    v0176 = qcar(v0176);
    fn = elt(env, 2); /* constant_exprp */
    v0176 = (*qfn1(fn))(qenv(fn), v0176);
    nil = C_nil;
    if (exception_pending()) goto v0146;
    env = stack[-3];
    if (!(v0176 == nil)) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v0176 = stack[-1];
    v0176 = qcdr(v0176);
    v0176 = qcar(v0176);
    v0177 = ncons(v0176);
    nil = C_nil;
    if (exception_pending()) goto v0146;
    env = stack[-3];
    v0176 = stack[0];
    {
        popv(4);
        fn = elt(env, 3); /* union */
        return (*qfn2(fn))(qenv(fn), v0177, v0176);
    }

v0179:
    v0176 = stack[-1];
    v0176 = qcdr(v0176);
    stack[-2] = v0176;
    v0176 = stack[-1];
    v0177 = qcar(v0176);
    v0176 = stack[0];
    v0176 = CC_solvealgtrig01(env, v0177, v0176);
    nil = C_nil;
    if (exception_pending()) goto v0146;
    env = stack[-3];
    stack[0] = v0176;
    v0176 = stack[-2];
    stack[-1] = v0176;
    goto v0021;
/* error exit handlers */
v0146:
    popv(4);
    return nil;
}



/* Code for chksymmetries!&sub1 */

static Lisp_Object MS_CDECL CC_chksymmetriesGsub1(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0138, v0135, v0209;
    Lisp_Object fn;
    Lisp_Object v0001, v0008, v0139, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "chksymmetries&sub1");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0139 = va_arg(aa, Lisp_Object);
    v0008 = va_arg(aa, Lisp_Object);
    v0001 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for chksymmetries&sub1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v0001,v0008,v0139,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0000,v0139,v0008,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0001;
    v0138 = v0008;
    v0135 = v0139;
    v0209 = v0000;
/* end of prologue */
    v0138 = Lsubst(nil, 3, v0209, v0135, v0138);
    nil = C_nil;
    if (exception_pending()) goto v0179;
    env = stack[-2];
    stack[-1] = v0138;
    v0138 = stack[0];
    if (v0138 == nil) goto v0131;
    v0135 = stack[-1];
    v0138 = stack[0];
    fn = elt(env, 3); /* indxsymp */
    v0138 = (*qfn2(fn))(qenv(fn), v0135, v0138);
    nil = C_nil;
    if (exception_pending()) goto v0179;
    env = stack[-2];
    goto v0148;

v0148:
    if (!(v0138 == nil)) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v0138 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v0138); }

v0131:
    v0138 = qvalue(elt(env, 1)); /* t */
    goto v0148;
/* error exit handlers */
v0179:
    popv(3);
    return nil;
}



/* Code for mk_world1 */

static Lisp_Object MS_CDECL CC_mk_world1(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0128, v0101, v0211;
    Lisp_Object fn;
    Lisp_Object v0008, v0139, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "mk_world1");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0139 = va_arg(aa, Lisp_Object);
    v0008 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mk_world1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0008,v0139,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0139,v0008);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0008;
    stack[-1] = v0139;
    v0128 = v0000;
/* end of prologue */
    fn = elt(env, 1); /* map_2_from_map_1 */
    v0211 = (*qfn1(fn))(qenv(fn), v0128);
    nil = C_nil;
    if (exception_pending()) goto v0151;
    v0101 = stack[-1];
    v0128 = stack[0];
    popv(2);
    return list3(v0211, v0101, v0128);
/* error exit handlers */
v0151:
    popv(2);
    return nil;
}



/* Code for coeffs!-to!-form1 */

static Lisp_Object MS_CDECL CC_coeffsKtoKform1(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0088, v0089, v0145;
    Lisp_Object fn;
    Lisp_Object v0008, v0139, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "coeffs-to-form1");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0139 = va_arg(aa, Lisp_Object);
    v0008 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for coeffs-to-form1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0008,v0139,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0139,v0008);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0008;
    stack[-2] = v0139;
    stack[-3] = v0000;
/* end of prologue */
    v0089 = stack[-1];
    v0088 = (Lisp_Object)1; /* 0 */
    v0088 = (Lisp_Object)greaterp2(v0089, v0088);
    nil = C_nil;
    if (exception_pending()) goto v0194;
    v0088 = v0088 ? lisp_true : nil;
    env = stack[-5];
    if (v0088 == nil) goto v0195;
    v0088 = stack[-3];
    stack[-4] = qcdr(v0088);
    stack[0] = stack[-2];
    v0088 = stack[-1];
    v0088 = sub1(v0088);
    nil = C_nil;
    if (exception_pending()) goto v0194;
    env = stack[-5];
    v0088 = CC_coeffsKtoKform1(env, 3, stack[-4], stack[0], v0088);
    nil = C_nil;
    if (exception_pending()) goto v0194;
    env = stack[-5];
    stack[0] = v0088;
    v0088 = stack[-3];
    v0088 = qcar(v0088);
    if (v0088 == nil) { Lisp_Object res = stack[0]; popv(6); return onevalue(res); }
    v0089 = stack[-2];
    v0088 = stack[-1];
    fn = elt(env, 1); /* to */
    v0145 = (*qfn2(fn))(qenv(fn), v0089, v0088);
    nil = C_nil;
    if (exception_pending()) goto v0194;
    v0088 = stack[-3];
    v0089 = qcar(v0088);
    v0088 = stack[0];
    popv(6);
    return acons(v0145, v0089, v0088);

v0195:
    v0088 = stack[-3];
    v0088 = qcar(v0088);
    { popv(6); return onevalue(v0088); }
/* error exit handlers */
v0194:
    popv(6);
    return nil;
}



/* Code for ofsf_smmkatl!-and */

static Lisp_Object MS_CDECL CC_ofsf_smmkatlKand(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0068, v0164, v0187;
    Lisp_Object fn;
    Lisp_Object v0008, v0139, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "ofsf_smmkatl-and");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0139 = va_arg(aa, Lisp_Object);
    v0008 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ofsf_smmkatl-and");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0008,v0139,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0139,v0008);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-3] = v0008;
    v0068 = v0139;
    stack[-4] = v0000;
/* end of prologue */
    v0164 = qvalue(elt(env, 1)); /* !*rlsipw */
    if (v0164 == nil) goto v0140;
    v0164 = qvalue(elt(env, 3)); /* nil */
    goto v0003;

v0003:
    if (v0164 == nil) goto v0082;
    v0187 = elt(env, 4); /* and */
    v0164 = v0068;
    v0068 = stack[-3];
    {
        popv(7);
        fn = elt(env, 5); /* ofsf_irl2atl */
        return (*qfnn(fn))(qenv(fn), 3, v0187, v0164, v0068);
    }

v0082:
    stack[-5] = v0068;
    goto v0134;

v0134:
    v0068 = stack[-5];
    if (v0068 == nil) goto v0138;
    v0068 = stack[-5];
    v0068 = qcar(v0068);
    v0164 = v0068;
    v0187 = qcar(v0164);
    v0164 = stack[-4];
    v0164 = Latsoc(nil, v0187, v0164);
    v0187 = v0164;
    v0164 = v0187;
    if (v0164 == nil) goto v0089;
    v0164 = v0068;
    v0068 = stack[-3];
    fn = elt(env, 6); /* ofsf_smmkatl!-and1 */
    v0068 = (*qfnn(fn))(qenv(fn), 3, v0187, v0164, v0068);
    nil = C_nil;
    if (exception_pending()) goto v0067;
    env = stack[-6];
    goto v0195;

v0195:
    stack[-2] = v0068;
    v0068 = stack[-2];
    fn = elt(env, 7); /* lastpair */
    v0068 = (*qfn1(fn))(qenv(fn), v0068);
    nil = C_nil;
    if (exception_pending()) goto v0067;
    env = stack[-6];
    stack[-1] = v0068;
    v0068 = stack[-5];
    v0068 = qcdr(v0068);
    stack[-5] = v0068;
    v0068 = stack[-1];
    if (!consp(v0068)) goto v0134;
    else goto v0136;

v0136:
    v0068 = stack[-5];
    if (v0068 == nil) { Lisp_Object res = stack[-2]; popv(7); return onevalue(res); }
    stack[0] = stack[-1];
    v0068 = stack[-5];
    v0068 = qcar(v0068);
    v0164 = v0068;
    v0187 = qcar(v0164);
    v0164 = stack[-4];
    v0164 = Latsoc(nil, v0187, v0164);
    v0187 = v0164;
    v0164 = v0187;
    if (v0164 == nil) goto v0368;
    v0164 = v0068;
    v0068 = stack[-3];
    fn = elt(env, 6); /* ofsf_smmkatl!-and1 */
    v0068 = (*qfnn(fn))(qenv(fn), 3, v0187, v0164, v0068);
    nil = C_nil;
    if (exception_pending()) goto v0067;
    env = stack[-6];
    goto v0216;

v0216:
    v0068 = Lrplacd(nil, stack[0], v0068);
    nil = C_nil;
    if (exception_pending()) goto v0067;
    env = stack[-6];
    v0068 = stack[-1];
    fn = elt(env, 7); /* lastpair */
    v0068 = (*qfn1(fn))(qenv(fn), v0068);
    nil = C_nil;
    if (exception_pending()) goto v0067;
    env = stack[-6];
    stack[-1] = v0068;
    v0068 = stack[-5];
    v0068 = qcdr(v0068);
    stack[-5] = v0068;
    goto v0136;

v0368:
    v0187 = elt(env, 4); /* and */
    v0164 = v0068;
    v0068 = stack[-3];
    fn = elt(env, 8); /* ofsf_ir2atl */
    v0068 = (*qfnn(fn))(qenv(fn), 3, v0187, v0164, v0068);
    nil = C_nil;
    if (exception_pending()) goto v0067;
    env = stack[-6];
    goto v0216;

v0089:
    v0164 = elt(env, 4); /* and */
    v0187 = v0068;
    v0068 = stack[-3];
    fn = elt(env, 8); /* ofsf_ir2atl */
    v0068 = (*qfnn(fn))(qenv(fn), 3, v0164, v0187, v0068);
    nil = C_nil;
    if (exception_pending()) goto v0067;
    env = stack[-6];
    goto v0195;

v0138:
    v0068 = qvalue(elt(env, 3)); /* nil */
    { popv(7); return onevalue(v0068); }

v0140:
    v0164 = qvalue(elt(env, 2)); /* !*rlsipo */
    goto v0003;
/* error exit handlers */
v0067:
    popv(7);
    return nil;
}



/* Code for !*ff2a */

static Lisp_Object CC_Hff2a(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0139)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0132, v0202;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for *ff2a");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0139,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0139);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v0132 = v0139;
    v0202 = v0000;
/* end of prologue */
    v0132 = cons(v0202, v0132);
    nil = C_nil;
    if (exception_pending()) goto v0333;
    env = stack[0];
    fn = elt(env, 2); /* cancel */
    v0132 = (*qfn1(fn))(qenv(fn), v0132);
    nil = C_nil;
    if (exception_pending()) goto v0333;
    env = stack[0];
    v0202 = v0132;
    v0132 = qvalue(elt(env, 1)); /* wtl!* */
    if (v0132 == nil) goto v0142;
    v0132 = v0202;
    {
        popv(1);
        fn = elt(env, 3); /* prepsq */
        return (*qfn1(fn))(qenv(fn), v0132);
    }

v0142:
    v0132 = v0202;
    {
        popv(1);
        fn = elt(env, 4); /* mk!*sq */
        return (*qfn1(fn))(qenv(fn), v0132);
    }
/* error exit handlers */
v0333:
    popv(1);
    return nil;
}



/* Code for eval!-yetunknowntypeexpr */

static Lisp_Object CC_evalKyetunknowntypeexpr(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0139)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0400, v0184;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for eval-yetunknowntypeexpr");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0139,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0139);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-4] = v0139;
    stack[0] = v0000;
/* end of prologue */

v0401:
    v0400 = stack[0];
    if (!consp(v0400)) goto v0017;
    v0400 = stack[0];
    v0184 = qcar(v0400);
    v0400 = elt(env, 1); /* !*sq */
    if (v0184 == v0400) goto v0129;
    v0400 = stack[0];
    v0400 = qcar(v0400);
    if (!symbolp(v0400)) v0400 = nil;
    else { v0400 = qfastgets(v0400);
           if (v0400 != nil) { v0400 = elt(v0400, 8); /* dname */
#ifdef RECORD_GET
             if (v0400 != SPID_NOPROP)
                record_get(elt(fastget_names, 8), 1);
             else record_get(elt(fastget_names, 8), 0),
                v0400 = nil; }
           else record_get(elt(fastget_names, 8), 0); }
#else
             if (v0400 == SPID_NOPROP) v0400 = nil; }}
#endif
    if (!(v0400 == nil)) goto v0096;
    v0400 = stack[0];
    v0184 = qcar(v0400);
    v0400 = elt(env, 3); /* !:dn!: */
    v0400 = (v0184 == v0400 ? lisp_true : nil);
    goto v0096;

v0096:
    if (!(v0400 == nil)) { Lisp_Object res = stack[0]; popv(7); return onevalue(res); }
    v0400 = stack[0];
    v0400 = qcar(v0400);
    if (!symbolp(v0400)) v0400 = nil;
    else { v0400 = qfastgets(v0400);
           if (v0400 != nil) { v0400 = elt(v0400, 45); /* psopfn */
#ifdef RECORD_GET
             if (v0400 != SPID_NOPROP)
                record_get(elt(fastget_names, 45), 1);
             else record_get(elt(fastget_names, 45), 0),
                v0400 = nil; }
           else record_get(elt(fastget_names, 45), 0); }
#else
             if (v0400 == SPID_NOPROP) v0400 = nil; }}
#endif
    stack[-1] = v0400;
    v0400 = stack[-1];
    if (v0400 == nil) goto v0369;
    v0400 = stack[0];
    fn = elt(env, 6); /* getrtype */
    v0184 = (*qfn1(fn))(qenv(fn), v0400);
    nil = C_nil;
    if (exception_pending()) goto v0227;
    env = stack[-6];
    v0400 = elt(env, 4); /* yetunknowntype */
    if (!(v0184 == v0400)) goto v0369;
    v0184 = stack[-1];
    v0400 = stack[0];
    v0400 = qcdr(v0400);
        popv(7);
        return Lapply1(nil, v0184, v0400);

v0369:
    v0400 = stack[0];
    stack[-5] = qcar(v0400);
    v0400 = stack[0];
    v0400 = qcdr(v0400);
    stack[-3] = v0400;
    v0400 = stack[-3];
    if (v0400 == nil) goto v0388;
    v0400 = stack[-3];
    v0400 = qcar(v0400);
    v0184 = v0400;
    v0400 = stack[-4];
    v0400 = CC_evalKyetunknowntypeexpr(env, v0184, v0400);
    nil = C_nil;
    if (exception_pending()) goto v0227;
    env = stack[-6];
    v0400 = ncons(v0400);
    nil = C_nil;
    if (exception_pending()) goto v0227;
    env = stack[-6];
    stack[-1] = v0400;
    stack[-2] = v0400;
    goto v0382;

v0382:
    v0400 = stack[-3];
    v0400 = qcdr(v0400);
    stack[-3] = v0400;
    v0400 = stack[-3];
    if (v0400 == nil) goto v0073;
    stack[0] = stack[-1];
    v0400 = stack[-3];
    v0400 = qcar(v0400);
    v0184 = v0400;
    v0400 = stack[-4];
    v0400 = CC_evalKyetunknowntypeexpr(env, v0184, v0400);
    nil = C_nil;
    if (exception_pending()) goto v0227;
    env = stack[-6];
    v0400 = ncons(v0400);
    nil = C_nil;
    if (exception_pending()) goto v0227;
    env = stack[-6];
    v0400 = Lrplacd(nil, stack[0], v0400);
    nil = C_nil;
    if (exception_pending()) goto v0227;
    env = stack[-6];
    v0400 = stack[-1];
    v0400 = qcdr(v0400);
    stack[-1] = v0400;
    goto v0382;

v0073:
    v0400 = stack[-2];
    goto v0381;

v0381:
    {
        Lisp_Object v0316 = stack[-5];
        popv(7);
        return cons(v0316, v0400);
    }

v0388:
    v0400 = qvalue(elt(env, 5)); /* nil */
    goto v0381;

v0129:
    v0400 = qvalue(elt(env, 2)); /* t */
    goto v0096;

v0017:
    v0400 = stack[0];
    if (!symbolp(v0400)) v0400 = nil;
    else { v0400 = qfastgets(v0400);
           if (v0400 != nil) { v0400 = elt(v0400, 4); /* avalue */
#ifdef RECORD_GET
             if (v0400 != SPID_NOPROP)
                record_get(elt(fastget_names, 4), 1);
             else record_get(elt(fastget_names, 4), 0),
                v0400 = nil; }
           else record_get(elt(fastget_names, 4), 0); }
#else
             if (v0400 == SPID_NOPROP) v0400 = nil; }}
#endif
    v0184 = v0400;
    v0400 = v0184;
    if (v0400 == nil) { Lisp_Object res = stack[0]; popv(7); return onevalue(res); }
    v0400 = v0184;
    v0400 = qcdr(v0400);
    v0184 = qcar(v0400);
    v0400 = stack[-4];
    stack[0] = v0184;
    stack[-4] = v0400;
    goto v0401;
/* error exit handlers */
v0227:
    popv(7);
    return nil;
}



setup_type const u45_setup[] =
{
    {"sqfrf",                   CC_sqfrf,       too_many_1,    wrong_no_1},
    {"*invsq",                  CC_Hinvsq,      too_many_1,    wrong_no_1},
    {"parfool",                 CC_parfool,     too_many_1,    wrong_no_1},
    {"dim<=deg",                CC_dimRMdeg,    too_many_1,    wrong_no_1},
    {"ratmean",                 too_few_2,      CC_ratmean,    wrong_no_2},
    {"endofstmtp",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_endofstmtp},
    {"reddom_zeros",            CC_reddom_zeros,too_many_1,    wrong_no_1},
    {"fs:zerop:",               CC_fsTzeropT,   too_many_1,    wrong_no_1},
    {"red_prepare",             CC_red_prepare, too_many_1,    wrong_no_1},
    {"gd_simpl",                CC_gd_simpl,    too_many_1,    wrong_no_1},
    {"ofsf_sippatl",            wrong_no_na,    wrong_no_nb,   (n_args *)CC_ofsf_sippatl},
    {"pasf_leqp",               too_few_2,      CC_pasf_leqp,  wrong_no_2},
    {"vsl_boundtype1",          too_few_2,      CC_vsl_boundtype1,wrong_no_2},
    {"intconv",                 CC_intconv,     too_many_1,    wrong_no_1},
    {"sprow_dim",               CC_sprow_dim,   too_many_1,    wrong_no_1},
    {"vdpsimpcont",             CC_vdpsimpcont, too_many_1,    wrong_no_1},
    {"mk_parents_prim",         CC_mk_parents_prim,too_many_1, wrong_no_1},
    {"get-all-kernels",         CC_getKallKkernels,too_many_1, wrong_no_1},
    {"bagp",                    CC_bagp,        too_many_1,    wrong_no_1},
    {"dfdeg",                   too_few_2,      CC_dfdeg,      wrong_no_2},
    {"xadd*",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_xaddH},
    {"cl_simpl1",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_cl_simpl1},
    {"pasf_subfof",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_pasf_subfof},
    {"ofsf_boundchk",           too_few_2,      CC_ofsf_boundchk,wrong_no_2},
    {"mkunarywedge",            CC_mkunarywedge,too_many_1,    wrong_no_1},
    {"mo=expvec2a1",            too_few_2,      CC_moMexpvec2a1,wrong_no_2},
    {"test-bool",               CC_testKbool,   too_many_1,    wrong_no_1},
    {"ofsf_smdbgetrel",         too_few_2,      CC_ofsf_smdbgetrel,wrong_no_2},
    {"my_freeof",               too_few_2,      CC_my_freeof,  wrong_no_2},
    {"get*nr*real*irred*reps",  CC_getHnrHrealHirredHreps,too_many_1,wrong_no_1},
    {"qqe_length-graph-neighbors",CC_qqe_lengthKgraphKneighbors,too_many_1,wrong_no_1},
    {"delqip",                  too_few_2,      CC_delqip,     wrong_no_2},
    {"acfsf_0mk2",              too_few_2,      CC_acfsf_0mk2, wrong_no_2},
    {"prload",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_prload},
    {"qsimpcomb_standard_integer_part_sf",CC_qsimpcomb_standard_integer_part_sf,too_many_1,wrong_no_1},
    {"groebreduceonestepint",   wrong_no_na,    wrong_no_nb,   (n_args *)CC_groebreduceonestepint},
    {"groebmakepair",           too_few_2,      CC_groebmakepair,wrong_no_2},
    {"make_wedge_pair",         too_few_2,      CC_make_wedge_pair,wrong_no_2},
    {"coeff_sortl",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_coeff_sortl},
    {"df-chain-rule",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_dfKchainKrule},
    {"dp=retimes",              CC_dpMretimes,  too_many_1,    wrong_no_1},
    {"general-difference-mod-p",too_few_2,      CC_generalKdifferenceKmodKp,wrong_no_2},
    {"null+vec+p",              CC_nullLvecLp,  too_many_1,    wrong_no_1},
    {"qqe_length-graph-marked", CC_qqe_lengthKgraphKmarked,too_many_1,wrong_no_1},
    {"pasf_negateat",           CC_pasf_negateat,too_many_1,   wrong_no_1},
    {"sfto_kexp",               too_few_2,      CC_sfto_kexp,  wrong_no_2},
    {"make-image-mod-p",        too_few_2,      CC_makeKimageKmodKp,wrong_no_2},
    {"ps:set-term",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_psTsetKterm},
    {"solvealgtrig01",          too_few_2,      CC_solvealgtrig01,wrong_no_2},
    {"chksymmetries&sub1",      wrong_no_na,    wrong_no_nb,   (n_args *)CC_chksymmetriesGsub1},
    {"mk_world1",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_mk_world1},
    {"coeffs-to-form1",         wrong_no_na,    wrong_no_nb,   (n_args *)CC_coeffsKtoKform1},
    {"ofsf_smmkatl-and",        wrong_no_na,    wrong_no_nb,   (n_args *)CC_ofsf_smmkatlKand},
    {"*ff2a",                   too_few_2,      CC_Hff2a,      wrong_no_2},
    {"eval-yetunknowntypeexpr", too_few_2,      CC_evalKyetunknowntypeexpr,wrong_no_2},
    {NULL, (one_args *)"u45", (two_args *)"21037 729307 1062624", 0}
};

/* end of generated code */
