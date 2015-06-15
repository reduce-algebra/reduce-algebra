
/* $destdir/u10.c        Machine generated C code */

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


/* Code for totalcompare */

static Lisp_Object CC_totalcompare(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0017, v0018, v0019;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for totalcompare");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0001;
    stack[-1] = v0000;
/* end of prologue */

v0020:
    v0018 = stack[-1];
    v0017 = stack[0];
    if (equal(v0018, v0017)) goto v0021;
    v0018 = stack[-1];
    v0017 = stack[0];
    fn = elt(env, 4); /* wulessp */
    v0017 = (*qfn2(fn))(qenv(fn), v0018, v0017);
    nil = C_nil;
    if (exception_pending()) goto v0022;
    env = stack[-2];
    if (v0017 == nil) goto v0023;
    v0017 = elt(env, 2); /* less */
    { popv(3); return onevalue(v0017); }

v0023:
    v0018 = stack[0];
    v0017 = stack[-1];
    fn = elt(env, 4); /* wulessp */
    v0017 = (*qfn2(fn))(qenv(fn), v0018, v0017);
    nil = C_nil;
    if (exception_pending()) goto v0022;
    env = stack[-2];
    if (v0017 == nil) goto v0024;
    v0017 = elt(env, 3); /* greater */
    { popv(3); return onevalue(v0017); }

v0024:
    v0017 = stack[-1];
    fn = elt(env, 5); /* wuconstantp */
    v0017 = (*qfn1(fn))(qenv(fn), v0017);
    nil = C_nil;
    if (exception_pending()) goto v0022;
    env = stack[-2];
    if (v0017 == nil) goto v0025;
    v0018 = stack[-1];
    v0017 = stack[0];
    {
        popv(3);
        fn = elt(env, 6); /* totalcompareconstants */
        return (*qfn2(fn))(qenv(fn), v0018, v0017);
    }

v0025:
    v0017 = stack[-1];
    v0017 = qcar(v0017);
    v0018 = qcdr(v0017);
    v0017 = stack[0];
    v0017 = qcar(v0017);
    v0017 = qcdr(v0017);
    v0017 = CC_totalcompare(env, v0018, v0017);
    nil = C_nil;
    if (exception_pending()) goto v0022;
    env = stack[-2];
    v0019 = v0017;
    v0018 = v0019;
    v0017 = elt(env, 1); /* equal */
    if (!(v0018 == v0017)) { popv(3); return onevalue(v0019); }
    v0017 = stack[-1];
    v0018 = qcdr(v0017);
    v0017 = stack[0];
    v0017 = qcdr(v0017);
    stack[-1] = v0018;
    stack[0] = v0017;
    goto v0020;

v0021:
    v0017 = elt(env, 1); /* equal */
    { popv(3); return onevalue(v0017); }
/* error exit handlers */
v0022:
    popv(3);
    return nil;
}



/* Code for searchpl */

static Lisp_Object CC_searchpl(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0031, v0025;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for searchpl");
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
    goto v0032;

v0032:
    v0031 = stack[0];
    if (!consp(v0031)) goto v0033;
    v0031 = stack[0];
    v0031 = qcar(v0031);
    v0031 = (consp(v0031) ? nil : lisp_true);
    goto v0034;

v0034:
    if (v0031 == nil) goto v0035;
    v0031 = qvalue(elt(env, 2)); /* nil */
    v0025 = v0031;
    goto v0036;

v0036:
    v0031 = stack[-1];
    if (v0031 == nil) { popv(3); return onevalue(v0025); }
    v0031 = stack[-1];
    v0031 = qcar(v0031);
    fn = elt(env, 3); /* setunion */
    v0031 = (*qfn2(fn))(qenv(fn), v0031, v0025);
    nil = C_nil;
    if (exception_pending()) goto v0037;
    env = stack[-2];
    v0025 = v0031;
    v0031 = stack[-1];
    v0031 = qcdr(v0031);
    stack[-1] = v0031;
    goto v0036;

v0035:
    v0031 = stack[0];
    v0031 = qcar(v0031);
    fn = elt(env, 4); /* searchtm */
    v0025 = (*qfn1(fn))(qenv(fn), v0031);
    nil = C_nil;
    if (exception_pending()) goto v0037;
    env = stack[-2];
    v0031 = stack[-1];
    v0031 = cons(v0025, v0031);
    nil = C_nil;
    if (exception_pending()) goto v0037;
    env = stack[-2];
    stack[-1] = v0031;
    v0031 = stack[0];
    v0031 = qcdr(v0031);
    stack[0] = v0031;
    goto v0032;

v0033:
    v0031 = qvalue(elt(env, 1)); /* t */
    goto v0034;
/* error exit handlers */
v0037:
    popv(3);
    return nil;
}



/* Code for rl_gettype */

static Lisp_Object CC_rl_gettype(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0038, v0039, v0040;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rl_gettype");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0039 = v0000;
/* end of prologue */
    v0038 = v0039;
    if (!symbolp(v0038)) v0038 = nil;
    else { v0038 = qfastgets(v0038);
           if (v0038 != nil) { v0038 = elt(v0038, 4); /* avalue */
#ifdef RECORD_GET
             if (v0038 != SPID_NOPROP)
                record_get(elt(fastget_names, 4), 1);
             else record_get(elt(fastget_names, 4), 0),
                v0038 = nil; }
           else record_get(elt(fastget_names, 4), 0); }
#else
             if (v0038 == SPID_NOPROP) v0038 = nil; }}
#endif
    v0040 = v0038;
    v0038 = v0040;
    if (v0038 == nil) goto v0013;
    v0038 = v0040;
    v0038 = qcar(v0038);
    return onevalue(v0038);

v0013:
    v0038 = v0039;
    if (!symbolp(v0038)) v0038 = nil;
    else { v0038 = qfastgets(v0038);
           if (v0038 != nil) { v0038 = elt(v0038, 2); /* rtype */
#ifdef RECORD_GET
             if (v0038 != SPID_NOPROP)
                record_get(elt(fastget_names, 2), 1);
             else record_get(elt(fastget_names, 2), 0),
                v0038 = nil; }
           else record_get(elt(fastget_names, 2), 0); }
#else
             if (v0038 == SPID_NOPROP) v0038 = nil; }}
#endif
    return onevalue(v0038);
}



/* Code for omair */

static Lisp_Object MS_CDECL CC_omair(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0042, v0030;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "omair");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for omair");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
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
    stack[0] = nil;
    fn = elt(env, 4); /* lex */
    v0042 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0043;
    env = stack[-2];
    fn = elt(env, 5); /* omobj */
    v0042 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0043;
    env = stack[-2];
    stack[-1] = v0042;
    v0042 = stack[-1];
    v0030 = qcar(v0042);
    v0042 = elt(env, 1); /* matrix */
    if (v0030 == v0042) goto v0035;
    fn = elt(env, 4); /* lex */
    v0042 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0043;
    env = stack[-2];
    fn = elt(env, 6); /* omobjs */
    v0042 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0043;
    env = stack[-2];
    stack[0] = v0042;
    v0042 = elt(env, 2); /* (!/ o m a) */
    fn = elt(env, 7); /* checktag */
    v0042 = (*qfn1(fn))(qenv(fn), v0042);
    nil = C_nil;
    if (exception_pending()) goto v0043;
    goto v0035;

v0035:
    v0030 = stack[-1];
    v0042 = stack[0];
        popv(3);
        return Lappend(nil, v0030, v0042);
/* error exit handlers */
v0043:
    popv(3);
    return nil;
}



/* Code for off_mod_reval */

static Lisp_Object CC_off_mod_reval(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0011;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for off_mod_reval");
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
    v0011 = qvalue(elt(env, 1)); /* !*modular */
    if (v0011 == nil) goto v0040;
    v0011 = elt(env, 2); /* modular */
    v0011 = ncons(v0011);
    nil = C_nil;
    if (exception_pending()) goto v0035;
    env = stack[-1];
    fn = elt(env, 4); /* off */
    v0011 = (*qfn1(fn))(qenv(fn), v0011);
    nil = C_nil;
    if (exception_pending()) goto v0035;
    env = stack[-1];
    v0011 = stack[0];
    fn = elt(env, 5); /* reval */
    v0011 = (*qfn1(fn))(qenv(fn), v0011);
    nil = C_nil;
    if (exception_pending()) goto v0035;
    env = stack[-1];
    stack[0] = v0011;
    v0011 = elt(env, 2); /* modular */
    v0011 = ncons(v0011);
    nil = C_nil;
    if (exception_pending()) goto v0035;
    env = stack[-1];
    fn = elt(env, 6); /* on */
    v0011 = (*qfn1(fn))(qenv(fn), v0011);
    nil = C_nil;
    if (exception_pending()) goto v0035;
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }

v0040:
    v0011 = stack[0];
    fn = elt(env, 5); /* reval */
    v0011 = (*qfn1(fn))(qenv(fn), v0011);
    nil = C_nil;
    if (exception_pending()) goto v0035;
    stack[0] = v0011;
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
/* error exit handlers */
v0035:
    popv(2);
    return nil;
}



/* Code for mkuwedge */

static Lisp_Object CC_mkuwedge(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0044, v0011;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mkuwedge");
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
    v0044 = v0000;
/* end of prologue */
    v0011 = v0044;
    v0011 = qcdr(v0011);
    if (v0011 == nil) goto v0040;
    v0011 = elt(env, 1); /* wedge */
    v0044 = cons(v0011, v0044);
    nil = C_nil;
    if (exception_pending()) goto v0012;
    env = stack[0];
    fn = elt(env, 2); /* fkern */
    v0044 = (*qfn1(fn))(qenv(fn), v0044);
    nil = C_nil;
    if (exception_pending()) goto v0012;
    v0044 = qcar(v0044);
    { popv(1); return onevalue(v0044); }

v0040:
    v0044 = qcar(v0044);
    { popv(1); return onevalue(v0044); }
/* error exit handlers */
v0012:
    popv(1);
    return nil;
}



/* Code for carx */

static Lisp_Object CC_carx(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0041, v0042, v0030;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for carx");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    v0042 = v0001;
    v0030 = v0000;
/* end of prologue */
    v0041 = v0030;
    v0041 = qcdr(v0041);
    if (v0041 == nil) goto v0021;
    stack[-1] = elt(env, 1); /* alg */
    stack[0] = (Lisp_Object)81; /* 5 */
    v0041 = elt(env, 2); /* "Wrong number of arguments to" */
    v0041 = list2(v0041, v0042);
    nil = C_nil;
    if (exception_pending()) goto v0043;
    env = stack[-2];
    {
        Lisp_Object v0046 = stack[-1];
        Lisp_Object v0047 = stack[0];
        popv(3);
        fn = elt(env, 3); /* rerror */
        return (*qfnn(fn))(qenv(fn), 3, v0046, v0047, v0041);
    }

v0021:
    v0041 = v0030;
    v0041 = qcar(v0041);
    { popv(3); return onevalue(v0041); }
/* error exit handlers */
v0043:
    popv(3);
    return nil;
}



/* Code for has_parents */

static Lisp_Object CC_has_parents(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0029, v0041, v0042;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for has_parents");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0029 = v0000;
/* end of prologue */
    v0029 = qcdr(v0029);
    v0029 = qcar(v0029);
    v0042 = v0029;
    v0029 = v0042;
    v0041 = qcar(v0029);
    v0029 = elt(env, 1); /* !? */
    if (v0041 == v0029) goto v0024;
    v0029 = v0042;
    v0029 = qcdr(v0029);
    v0041 = elt(env, 1); /* !? */
        return Lneq(nil, v0029, v0041);

v0024:
    v0029 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v0029);
}



/* Code for take!-impart */

static Lisp_Object CC_takeKimpart(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0024, v0049;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for take-impart");
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
    v0024 = stack[0];
    v0024 = qcar(v0024);
    fn = elt(env, 1); /* impartf */
    v0049 = (*qfn1(fn))(qenv(fn), v0024);
    nil = C_nil;
    if (exception_pending()) goto v0041;
    env = stack[-2];
    v0024 = (Lisp_Object)17; /* 1 */
    stack[-1] = cons(v0049, v0024);
    nil = C_nil;
    if (exception_pending()) goto v0041;
    env = stack[-2];
    v0049 = (Lisp_Object)17; /* 1 */
    v0024 = stack[0];
    v0024 = qcdr(v0024);
    v0024 = cons(v0049, v0024);
    nil = C_nil;
    if (exception_pending()) goto v0041;
    env = stack[-2];
    {
        Lisp_Object v0042 = stack[-1];
        popv(3);
        fn = elt(env, 2); /* multsq */
        return (*qfn2(fn))(qenv(fn), v0042, v0024);
    }
/* error exit handlers */
v0041:
    popv(3);
    return nil;
}



/* Code for lprim */

static Lisp_Object CC_lprim(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0040, v0050;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for lprim");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0040 = v0000;
/* end of prologue */
    v0050 = qvalue(elt(env, 1)); /* !*msg */
    if (v0050 == nil) goto v0051;
    v0050 = elt(env, 3); /* "***" */
    {
        fn = elt(env, 4); /* lpriw */
        return (*qfn2(fn))(qenv(fn), v0050, v0040);
    }

v0051:
    v0040 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v0040);
}



/* Code for red_better */

static Lisp_Object CC_red_better(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0014;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for red_better");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0001;
    v0014 = v0000;
/* end of prologue */
    fn = elt(env, 1); /* bas_dplen */
    stack[-1] = (*qfn1(fn))(qenv(fn), v0014);
    nil = C_nil;
    if (exception_pending()) goto v0038;
    env = stack[-2];
    v0014 = stack[0];
    fn = elt(env, 1); /* bas_dplen */
    v0014 = (*qfn1(fn))(qenv(fn), v0014);
    nil = C_nil;
    if (exception_pending()) goto v0038;
    {
        Lisp_Object v0039 = stack[-1];
        popv(3);
        return Llessp(nil, v0039, v0014);
    }
/* error exit handlers */
v0038:
    popv(3);
    return nil;
}



/* Code for ord */

static Lisp_Object CC_ord(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0048, v0024, v0049;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ord");
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
    v0049 = v0000;
/* end of prologue */
    v0024 = qvalue(elt(env, 1)); /* ordering */
    v0048 = elt(env, 2); /* lex */
    if (v0024 == v0048) goto v0033;
    v0048 = v0049;
    v0048 = qcar(v0048);
    { popv(1); return onevalue(v0048); }

v0033:
    v0048 = elt(env, 3); /* plus */
    v0024 = v0049;
    v0048 = cons(v0048, v0024);
    nil = C_nil;
    if (exception_pending()) goto v0023;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 4); /* eval */
        return (*qfn1(fn))(qenv(fn), v0048);
    }
/* error exit handlers */
v0023:
    popv(1);
    return nil;
}



/* Code for reduce!-mod!-p */

static Lisp_Object CC_reduceKmodKp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0057, v0058, v0037;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for reduce-mod-p");
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
    v0057 = stack[0];
    if (v0057 == nil) goto v0051;
    v0057 = stack[0];
    if (!consp(v0057)) goto v0013;
    v0057 = stack[0];
    v0057 = qcar(v0057);
    v0057 = (consp(v0057) ? nil : lisp_true);
    goto v0052;

v0052:
    if (v0057 == nil) goto v0012;
    v0057 = stack[0];
    v0057 = Lmodular_number(nil, v0057);
    env = stack[-2];
    {
        popv(3);
        fn = elt(env, 3); /* !*n2f */
        return (*qfn1(fn))(qenv(fn), v0057);
    }

v0012:
    v0057 = stack[0];
    v0057 = qcar(v0057);
    v0057 = qcdr(v0057);
    stack[-1] = CC_reduceKmodKp(env, v0057);
    nil = C_nil;
    if (exception_pending()) goto v0059;
    env = stack[-2];
    v0057 = stack[0];
    v0057 = qcdr(v0057);
    v0057 = CC_reduceKmodKp(env, v0057);
    nil = C_nil;
    if (exception_pending()) goto v0059;
    v0058 = stack[-1];
    v0037 = v0058;
    if (v0037 == nil) { popv(3); return onevalue(v0057); }
    v0037 = stack[0];
    v0037 = qcar(v0037);
    v0037 = qcar(v0037);
    popv(3);
    return acons(v0037, v0058, v0057);

v0013:
    v0057 = qvalue(elt(env, 2)); /* t */
    goto v0052;

v0051:
    v0057 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v0057); }
/* error exit handlers */
v0059:
    popv(3);
    return nil;
}



/* Code for scan */

static Lisp_Object MS_CDECL CC_scan(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0190, v0191, v0192;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "scan");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for scan");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
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
    v0191 = qvalue(elt(env, 1)); /* cursym!* */
    v0190 = elt(env, 2); /* !*semicol!* */
    if (!(v0191 == v0190)) goto v0020;

v0032:
    v0190 = qvalue(elt(env, 3)); /* nil */
    qvalue(elt(env, 4)) = v0190; /* escaped!* */
    fn = elt(env, 43); /* token */
    v0190 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-3];
    qvalue(elt(env, 5)) = v0190; /* nxtsym!* */
    goto v0020;

v0020:
    v0190 = qvalue(elt(env, 5)); /* nxtsym!* */
    if (!consp(v0190)) goto v0194;
    v0190 = qvalue(elt(env, 5)); /* nxtsym!* */
    fn = elt(env, 44); /* toknump */
    v0190 = (*qfn1(fn))(qenv(fn), v0190);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-3];
    v0190 = (v0190 == nil ? lisp_true : nil);
    goto v0195;

v0195:
    if (v0190 == nil) goto v0025;
    v0190 = qvalue(elt(env, 5)); /* nxtsym!* */
    v0191 = qcar(v0190);
    v0190 = elt(env, 41); /* string */
    if (!(v0191 == v0190)) goto v0050;
    v0190 = elt(env, 42); /* " " */
    fn = elt(env, 45); /* prin2x */
    v0190 = (*qfn1(fn))(qenv(fn), v0190);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-3];
    v0190 = qvalue(elt(env, 5)); /* nxtsym!* */
    v0190 = qcdr(v0190);
    v0190 = qcar(v0190);
    v0190 = Lmkquote(nil, v0190);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-3];
    qvalue(elt(env, 5)) = v0190; /* nxtsym!* */
    v0190 = qcdr(v0190);
    v0190 = qcar(v0190);
    fn = elt(env, 45); /* prin2x */
    v0190 = (*qfn1(fn))(qenv(fn), v0190);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-3];
    goto v0050;

v0050:
    v0190 = qvalue(elt(env, 5)); /* nxtsym!* */
    qvalue(elt(env, 1)) = v0190; /* cursym!* */
    v0190 = qvalue(elt(env, 4)); /* escaped!* */
    qvalue(elt(env, 22)) = v0190; /* curescaped!* */
    v0190 = qvalue(elt(env, 3)); /* nil */
    qvalue(elt(env, 4)) = v0190; /* escaped!* */
    fn = elt(env, 43); /* token */
    v0190 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-3];
    qvalue(elt(env, 5)) = v0190; /* nxtsym!* */
    v0191 = qvalue(elt(env, 5)); /* nxtsym!* */
    v0190 = qvalue(elt(env, 25)); /* !$eof!$ */
    if (v0191 == v0190) goto v0196;
    v0190 = qvalue(elt(env, 3)); /* nil */
    goto v0197;

v0197:
    if (v0190 == nil) goto v0054;
    {
        popv(4);
        fn = elt(env, 46); /* filenderr */
        return (*qfnn(fn))(qenv(fn), 0);
    }

v0054:
    v0190 = qvalue(elt(env, 5)); /* nxtsym!* */
    if (is_number(v0190)) goto v0198;
    v0190 = qvalue(elt(env, 5)); /* nxtsym!* */
    if (!consp(v0190)) goto v0199;
    v0190 = qvalue(elt(env, 3)); /* nil */
    goto v0200;

v0200:
    if (!(v0190 == nil)) goto v0198;

v0201:
    v0190 = qvalue(elt(env, 1)); /* cursym!* */
    {
        popv(4);
        fn = elt(env, 47); /* addcomment */
        return (*qfn1(fn))(qenv(fn), v0190);
    }

v0198:
    v0190 = elt(env, 42); /* " " */
    fn = elt(env, 45); /* prin2x */
    v0190 = (*qfn1(fn))(qenv(fn), v0190);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-3];
    goto v0201;

v0199:
    v0190 = qvalue(elt(env, 5)); /* nxtsym!* */
    if (!symbolp(v0190)) v0190 = nil;
    else { v0190 = qfastgets(v0190);
           if (v0190 != nil) { v0190 = elt(v0190, 11); /* switch!* */
#ifdef RECORD_GET
             if (v0190 != SPID_NOPROP)
                record_get(elt(fastget_names, 11), 1);
             else record_get(elt(fastget_names, 11), 0),
                v0190 = nil; }
           else record_get(elt(fastget_names, 11), 0); }
#else
             if (v0190 == SPID_NOPROP) v0190 = nil; }}
#endif
    v0190 = (v0190 == nil ? lisp_true : nil);
    goto v0200;

v0196:
    v0191 = qvalue(elt(env, 14)); /* ttype!* */
    v0190 = (Lisp_Object)49; /* 3 */
    v0190 = (v0191 == v0190 ? lisp_true : nil);
    goto v0197;

v0025:
    v0191 = qvalue(elt(env, 5)); /* nxtsym!* */
    v0190 = elt(env, 6); /* else */
    if (v0191 == v0190) goto v0055;
    v0191 = qvalue(elt(env, 1)); /* cursym!* */
    v0190 = elt(env, 2); /* !*semicol!* */
    v0190 = (v0191 == v0190 ? lisp_true : nil);
    goto v0202;

v0202:
    if (v0190 == nil) goto v0010;
    v0190 = qvalue(elt(env, 3)); /* nil */
    qvalue(elt(env, 8)) = v0190; /* outl!* */
    goto v0010;

v0010:
    v0190 = qvalue(elt(env, 5)); /* nxtsym!* */
    fn = elt(env, 45); /* prin2x */
    v0190 = (*qfn1(fn))(qenv(fn), v0190);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-3];
    goto v0036;

v0036:
    v0190 = qvalue(elt(env, 5)); /* nxtsym!* */
    if (!(symbolp(v0190))) goto v0050;
    v0190 = qvalue(elt(env, 5)); /* nxtsym!* */
    if (!symbolp(v0190)) v0190 = nil;
    else { v0190 = qfastgets(v0190);
           if (v0190 != nil) { v0190 = elt(v0190, 28); /* newnam */
#ifdef RECORD_GET
             if (v0190 != SPID_NOPROP)
                record_get(elt(fastget_names, 28), 1);
             else record_get(elt(fastget_names, 28), 0),
                v0190 = nil; }
           else record_get(elt(fastget_names, 28), 0); }
#else
             if (v0190 == SPID_NOPROP) v0190 = nil; }}
#endif
    stack[-1] = v0190;
    if (v0190 == nil) goto v0203;
    v0191 = stack[-1];
    v0190 = qvalue(elt(env, 5)); /* nxtsym!* */
    if (equal(v0191, v0190)) goto v0203;
    v0190 = stack[-1];
    qvalue(elt(env, 5)) = v0190; /* nxtsym!* */
    v0190 = stack[-1];
    v0190 = Lstringp(nil, v0190);
    env = stack[-3];
    if (!(v0190 == nil)) goto v0050;
    v0190 = stack[-1];
    if (!consp(v0190)) goto v0036;
    else goto v0050;

v0203:
    v0191 = qvalue(elt(env, 5)); /* nxtsym!* */
    v0190 = elt(env, 9); /* comment */
    if (v0191 == v0190) goto v0204;
    v0191 = qvalue(elt(env, 5)); /* nxtsym!* */
    v0190 = elt(env, 10); /* !C!O!M!M!E!N!T */
    if (v0191 == v0190) goto v0205;
    v0191 = qvalue(elt(env, 5)); /* nxtsym!* */
    v0190 = elt(env, 11); /* !Comment */
    v0190 = (v0191 == v0190 ? lisp_true : nil);
    goto v0206;

v0206:
    if (v0190 == nil) goto v0207;
    v0190 = elt(env, 9); /* comment */
    fn = elt(env, 48); /* read!-comment1 */
    v0190 = (*qfn1(fn))(qenv(fn), v0190);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-3];
    stack[-1] = v0190;
    v0190 = qvalue(elt(env, 12)); /* !*comment */
    if (v0190 == nil) goto v0032;
    else { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }

v0207:
    v0191 = qvalue(elt(env, 5)); /* nxtsym!* */
    v0190 = elt(env, 13); /* !% */
    if (v0191 == v0190) goto v0208;
    v0190 = qvalue(elt(env, 3)); /* nil */
    goto v0209;

v0209:
    if (v0190 == nil) goto v0210;
    v0190 = elt(env, 15); /* percent_comment */
    fn = elt(env, 48); /* read!-comment1 */
    v0190 = (*qfn1(fn))(qenv(fn), v0190);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-3];
    stack[-1] = v0190;
    v0190 = qvalue(elt(env, 12)); /* !*comment */
    if (v0190 == nil) goto v0032;
    else { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }

v0210:
    v0191 = qvalue(elt(env, 5)); /* nxtsym!* */
    v0190 = elt(env, 16); /* !#if */
    if (v0191 == v0190) goto v0211;
    v0191 = qvalue(elt(env, 5)); /* nxtsym!* */
    v0190 = elt(env, 17); /* !#else */
    if (v0191 == v0190) goto v0212;
    v0191 = qvalue(elt(env, 5)); /* nxtsym!* */
    v0190 = elt(env, 18); /* !#elif */
    v0190 = (v0191 == v0190 ? lisp_true : nil);
    goto v0213;

v0213:
    if (v0190 == nil) goto v0214;
    v0190 = qvalue(elt(env, 3)); /* nil */
    stack[-2] = v0190;
    stack[-1] = v0190;
    qvalue(elt(env, 5)) = v0190; /* nxtsym!* */
    goto v0215;

v0215:
    v0191 = qvalue(elt(env, 5)); /* nxtsym!* */
    v0190 = elt(env, 30); /* !# */
    if (v0191 == v0190) goto v0216;
    v0190 = qvalue(elt(env, 3)); /* nil */
    goto v0217;

v0217:
    if (v0190 == nil) goto v0218;
    fn = elt(env, 43); /* token */
    v0190 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-3];
    qvalue(elt(env, 5)) = v0190; /* nxtsym!* */
    v0191 = qvalue(elt(env, 14)); /* ttype!* */
    v0190 = (Lisp_Object)1; /* 0 */
    if (!(v0191 == v0190)) goto v0218;
    stack[0] = elt(env, 30); /* !# */
    v0190 = qvalue(elt(env, 5)); /* nxtsym!* */
    v0190 = Lexplodec(nil, v0190);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-3];
    v0190 = cons(stack[0], v0190);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-3];
    fn = elt(env, 49); /* list2string */
    v0190 = (*qfn1(fn))(qenv(fn), v0190);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-3];
    v0190 = Lintern(nil, v0190);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-3];
    qvalue(elt(env, 5)) = v0190; /* nxtsym!* */
    goto v0218;

v0218:
    v0191 = qvalue(elt(env, 5)); /* nxtsym!* */
    v0190 = elt(env, 19); /* !#endif */
    if (v0191 == v0190) goto v0219;
    v0191 = qvalue(elt(env, 5)); /* nxtsym!* */
    v0190 = elt(env, 16); /* !#if */
    if (v0191 == v0190) goto v0220;
    v0191 = qvalue(elt(env, 5)); /* nxtsym!* */
    v0190 = elt(env, 17); /* !#else */
    if (v0191 == v0190) goto v0221;
    v0190 = qvalue(elt(env, 3)); /* nil */
    goto v0222;

v0222:
    if (!(v0190 == nil)) goto v0032;
    v0191 = qvalue(elt(env, 5)); /* nxtsym!* */
    v0190 = elt(env, 18); /* !#elif */
    if (v0191 == v0190) goto v0223;
    v0190 = qvalue(elt(env, 3)); /* nil */
    goto v0224;

v0224:
    if (!(v0190 == nil)) goto v0211;

v0225:
    fn = elt(env, 43); /* token */
    v0190 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-3];
    qvalue(elt(env, 5)) = v0190; /* nxtsym!* */
    v0191 = qvalue(elt(env, 14)); /* ttype!* */
    v0190 = (Lisp_Object)49; /* 3 */
    if (v0191 == v0190) goto v0226;
    v0190 = qvalue(elt(env, 3)); /* nil */
    goto v0227;

v0227:
    if (v0190 == nil) goto v0215;
    {
        popv(4);
        fn = elt(env, 46); /* filenderr */
        return (*qfnn(fn))(qenv(fn), 0);
    }

v0226:
    v0191 = qvalue(elt(env, 5)); /* nxtsym!* */
    v0190 = qvalue(elt(env, 25)); /* !$eof!$ */
    v0190 = (v0191 == v0190 ? lisp_true : nil);
    goto v0227;

v0211:
    fn = elt(env, 50); /* rread */
    v0192 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-3];
    v0191 = qvalue(elt(env, 21)); /* !*backtrace */
    v0190 = qvalue(elt(env, 3)); /* nil */
    fn = elt(env, 51); /* errorset */
    v0190 = (*qfnn(fn))(qenv(fn), 3, v0192, v0191, v0190);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-3];
    stack[-1] = v0190;
    v0190 = qvalue(elt(env, 3)); /* nil */
    qvalue(elt(env, 4)) = v0190; /* escaped!* */
    qvalue(elt(env, 22)) = v0190; /* curescaped!* */
    v0190 = stack[-1];
    fn = elt(env, 52); /* errorp */
    v0190 = (*qfn1(fn))(qenv(fn), v0190);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-3];
    if (v0190 == nil) goto v0228;
    v0190 = qvalue(elt(env, 3)); /* nil */
    goto v0229;

v0229:
    if (!(v0190 == nil)) goto v0032;
    v0190 = qvalue(elt(env, 3)); /* nil */
    stack[-1] = v0190;
    v0190 = qvalue(elt(env, 7)); /* t */
    stack[-2] = v0190;
    goto v0215;

v0228:
    v0190 = stack[-1];
    v0190 = qcar(v0190);
    goto v0229;

v0223:
    v0190 = stack[-1];
    if (v0190 == nil) goto v0230;
    v0190 = qvalue(elt(env, 3)); /* nil */
    goto v0224;

v0230:
    v0190 = stack[-2];
    goto v0224;

v0221:
    v0190 = stack[-1];
    if (v0190 == nil) goto v0231;
    v0190 = qvalue(elt(env, 3)); /* nil */
    goto v0222;

v0231:
    v0190 = stack[-2];
    goto v0222;

v0220:
    v0191 = qvalue(elt(env, 3)); /* nil */
    v0190 = stack[-1];
    v0190 = cons(v0191, v0190);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-3];
    stack[-1] = v0190;
    goto v0225;

v0219:
    v0190 = stack[-1];
    if (v0190 == nil) goto v0032;
    v0190 = stack[-1];
    v0190 = qcdr(v0190);
    stack[-1] = v0190;
    goto v0225;

v0216:
    v0191 = qvalue(elt(env, 14)); /* ttype!* */
    v0190 = (Lisp_Object)49; /* 3 */
    if (v0191 == v0190) goto v0232;
    v0190 = qvalue(elt(env, 3)); /* nil */
    goto v0217;

v0232:
    v0190 = qvalue(elt(env, 31)); /* crchar!* */
    v0190 = Lwhitespace_char_p(nil, v0190);
    env = stack[-3];
    v0190 = (v0190 == nil ? lisp_true : nil);
    goto v0217;

v0214:
    v0191 = qvalue(elt(env, 5)); /* nxtsym!* */
    v0190 = elt(env, 19); /* !#endif */
    if (v0191 == v0190) goto v0032;
    v0191 = qvalue(elt(env, 5)); /* nxtsym!* */
    v0190 = elt(env, 20); /* !#eval */
    if (v0191 == v0190) goto v0233;
    v0191 = qvalue(elt(env, 5)); /* nxtsym!* */
    v0190 = elt(env, 23); /* !#define */
    if (v0191 == v0190) goto v0234;
    v0191 = qvalue(elt(env, 14)); /* ttype!* */
    v0190 = (Lisp_Object)49; /* 3 */
    if (!(v0191 == v0190)) goto v0050;
    v0191 = qvalue(elt(env, 5)); /* nxtsym!* */
    v0190 = qvalue(elt(env, 25)); /* !$eof!$ */
    if (v0191 == v0190) goto v0235;
    v0191 = qvalue(elt(env, 5)); /* nxtsym!* */
    v0190 = elt(env, 26); /* !' */
    if (v0191 == v0190) goto v0236;
    v0190 = qvalue(elt(env, 28)); /* !*eoldelimp */
    if (v0190 == nil) goto v0237;
    v0191 = qvalue(elt(env, 5)); /* nxtsym!* */
    v0190 = qvalue(elt(env, 29)); /* !$eol!$ */
    if (!(v0191 == v0190)) goto v0237;

v0038:
    v0190 = qvalue(elt(env, 5)); /* nxtsym!* */
    qvalue(elt(env, 40)) = v0190; /* semic!* */
    v0190 = qvalue(elt(env, 3)); /* nil */
    qvalue(elt(env, 22)) = v0190; /* curescaped!* */
    v0190 = elt(env, 2); /* !*semicol!* */
    {
        popv(4);
        fn = elt(env, 47); /* addcomment */
        return (*qfn1(fn))(qenv(fn), v0190);
    }

v0237:
    v0191 = qvalue(elt(env, 5)); /* nxtsym!* */
    v0190 = elt(env, 30); /* !# */
    if (v0191 == v0190) goto v0238;
    v0190 = qvalue(elt(env, 3)); /* nil */
    goto v0239;

v0239:
    if (v0190 == nil) goto v0240;
    v0190 = qvalue(elt(env, 3)); /* nil */
    stack[-2] = v0190;
    v0190 = qvalue(elt(env, 5)); /* nxtsym!* */
    if (!symbolp(v0190)) v0190 = nil;
    else { v0190 = qfastgets(v0190);
           if (v0190 != nil) { v0190 = elt(v0190, 11); /* switch!* */
#ifdef RECORD_GET
             if (v0190 != SPID_NOPROP)
                record_get(elt(fastget_names, 11), 1);
             else record_get(elt(fastget_names, 11), 0),
                v0190 = nil; }
           else record_get(elt(fastget_names, 11), 0); }
#else
             if (v0190 == SPID_NOPROP) v0190 = nil; }}
#endif
    stack[-1] = v0190;
    fn = elt(env, 43); /* token */
    v0190 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-3];
    qvalue(elt(env, 5)) = v0190; /* nxtsym!* */
    v0191 = qvalue(elt(env, 5)); /* nxtsym!* */
    v0190 = elt(env, 35); /* if */
    if (v0191 == v0190) goto v0241;
    v0191 = qvalue(elt(env, 5)); /* nxtsym!* */
    v0190 = elt(env, 6); /* else */
    if (v0191 == v0190) goto v0242;
    v0191 = qvalue(elt(env, 5)); /* nxtsym!* */
    v0190 = elt(env, 36); /* elif */
    if (v0191 == v0190) goto v0243;
    v0191 = qvalue(elt(env, 5)); /* nxtsym!* */
    v0190 = elt(env, 37); /* endif */
    if (v0191 == v0190) goto v0244;
    v0191 = qvalue(elt(env, 5)); /* nxtsym!* */
    v0190 = elt(env, 38); /* eval */
    if (v0191 == v0190) goto v0245;
    v0191 = qvalue(elt(env, 5)); /* nxtsym!* */
    v0190 = elt(env, 39); /* define */
    v0190 = (v0191 == v0190 ? lisp_true : nil);
    goto v0246;

v0246:
    if (v0190 == nil) goto v0247;
    v0190 = qvalue(elt(env, 5)); /* nxtsym!* */
    fn = elt(env, 45); /* prin2x */
    v0190 = (*qfn1(fn))(qenv(fn), v0190);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-3];
    stack[0] = elt(env, 30); /* !# */
    v0190 = qvalue(elt(env, 5)); /* nxtsym!* */
    v0190 = Lexplodec(nil, v0190);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-3];
    v0190 = cons(stack[0], v0190);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-3];
    fn = elt(env, 49); /* list2string */
    v0190 = (*qfn1(fn))(qenv(fn), v0190);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-3];
    v0190 = Lintern(nil, v0190);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-3];
    qvalue(elt(env, 5)) = v0190; /* nxtsym!* */
    goto v0036;

v0247:
    v0191 = qvalue(elt(env, 14)); /* ttype!* */
    v0190 = (Lisp_Object)49; /* 3 */
    if (!(v0191 == v0190)) goto v0056;
    v0191 = qvalue(elt(env, 5)); /* nxtsym!* */
    v0190 = qvalue(elt(env, 25)); /* !$eof!$ */
    if (v0191 == v0190) goto v0248;
    v0190 = stack[-1];
    v0190 = qcar(v0190);
    if (!(v0190 == nil)) goto v0052;

v0056:
    v0190 = stack[-1];
    v0190 = qcdr(v0190);
    v0190 = qcar(v0190);
    qvalue(elt(env, 1)) = v0190; /* cursym!* */
    v0190 = qvalue(elt(env, 3)); /* nil */
    qvalue(elt(env, 22)) = v0190; /* curescaped!* */
    v0191 = qvalue(elt(env, 1)); /* cursym!* */
    v0190 = elt(env, 32); /* !*rpar!* */
    if (v0191 == v0190) goto v0054;
    v0190 = qvalue(elt(env, 1)); /* cursym!* */
    {
        popv(4);
        fn = elt(env, 47); /* addcomment */
        return (*qfn1(fn))(qenv(fn), v0190);
    }

v0052:
    v0190 = stack[-2];
    if (!(v0190 == nil)) goto v0056;
    v0191 = qvalue(elt(env, 5)); /* nxtsym!* */
    v0190 = stack[-1];
    v0190 = qcar(v0190);
    v0190 = Latsoc(nil, v0191, v0190);
    stack[0] = v0190;
    if (v0190 == nil) goto v0056;
    v0190 = qvalue(elt(env, 5)); /* nxtsym!* */
    fn = elt(env, 45); /* prin2x */
    v0190 = (*qfn1(fn))(qenv(fn), v0190);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-3];
    v0190 = stack[0];
    v0190 = qcdr(v0190);
    stack[-1] = v0190;
    v0190 = stack[-1];
    v0190 = qcar(v0190);
    if (v0190 == nil) goto v0249;
    v0190 = qvalue(elt(env, 3)); /* nil */
    goto v0250;

v0250:
    if (v0190 == nil) goto v0053;
    fn = elt(env, 53); /* read!-comment */
    v0190 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-3];
    qvalue(elt(env, 34)) = v0190; /* comment!* */
    goto v0032;

v0053:
    fn = elt(env, 43); /* token */
    v0190 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-3];
    qvalue(elt(env, 5)) = v0190; /* nxtsym!* */
    v0191 = qvalue(elt(env, 14)); /* ttype!* */
    v0190 = (Lisp_Object)49; /* 3 */
    if (!(v0191 == v0190)) goto v0056;
    v0191 = qvalue(elt(env, 5)); /* nxtsym!* */
    v0190 = qvalue(elt(env, 25)); /* !$eof!$ */
    if (v0191 == v0190) goto v0251;
    v0190 = stack[-1];
    v0190 = qcar(v0190);
    if (v0190 == nil) goto v0056;
    else goto v0052;

v0251:
    {
        popv(4);
        fn = elt(env, 46); /* filenderr */
        return (*qfnn(fn))(qenv(fn), 0);
    }

v0249:
    v0190 = stack[-1];
    v0190 = qcdr(v0190);
    v0191 = qcar(v0190);
    v0190 = elt(env, 33); /* !*comment!* */
    v0190 = (v0191 == v0190 ? lisp_true : nil);
    goto v0250;

v0248:
    {
        popv(4);
        fn = elt(env, 46); /* filenderr */
        return (*qfnn(fn))(qenv(fn), 0);
    }

v0245:
    v0190 = qvalue(elt(env, 7)); /* t */
    goto v0246;

v0244:
    v0190 = qvalue(elt(env, 7)); /* t */
    goto v0246;

v0243:
    v0190 = qvalue(elt(env, 7)); /* t */
    goto v0246;

v0242:
    v0190 = qvalue(elt(env, 7)); /* t */
    goto v0246;

v0241:
    v0190 = qvalue(elt(env, 7)); /* t */
    goto v0246;

v0240:
    v0190 = qvalue(elt(env, 5)); /* nxtsym!* */
    if (!symbolp(v0190)) v0190 = nil;
    else { v0190 = qfastgets(v0190);
           if (v0190 != nil) { v0190 = elt(v0190, 11); /* switch!* */
#ifdef RECORD_GET
             if (v0190 != SPID_NOPROP)
                record_get(elt(fastget_names, 11), 1);
             else record_get(elt(fastget_names, 11), 0),
                v0190 = nil; }
           else record_get(elt(fastget_names, 11), 0); }
#else
             if (v0190 == SPID_NOPROP) v0190 = nil; }}
#endif
    stack[-1] = v0190;
    if (v0190 == nil) goto v0050;
    v0190 = stack[-1];
    v0191 = qcdr(v0190);
    v0190 = elt(env, 2); /* !*semicol!* */
    if (!consp(v0191)) goto v0252;
    v0191 = qcar(v0191);
    if (v0191 == v0190) goto v0038;
    else goto v0252;

v0252:
    v0190 = qvalue(elt(env, 31)); /* crchar!* */
    v0190 = Lwhitespace_char_p(nil, v0190);
    env = stack[-3];
    stack[-2] = v0190;
    goto v0053;

v0238:
    v0190 = qvalue(elt(env, 31)); /* crchar!* */
    v0190 = Lwhitespace_char_p(nil, v0190);
    env = stack[-3];
    v0190 = (v0190 == nil ? lisp_true : nil);
    goto v0239;

v0236:
    v0190 = elt(env, 27); /* "Invalid QUOTE" */
    fn = elt(env, 54); /* rederr */
    v0190 = (*qfn1(fn))(qenv(fn), v0190);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-3];
    goto v0252;

v0235:
    {
        popv(4);
        fn = elt(env, 46); /* filenderr */
        return (*qfnn(fn))(qenv(fn), 0);
    }

v0234:
    fn = elt(env, 50); /* rread */
    v0192 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-3];
    v0191 = qvalue(elt(env, 21)); /* !*backtrace */
    v0190 = qvalue(elt(env, 3)); /* nil */
    fn = elt(env, 51); /* errorset */
    v0190 = (*qfnn(fn))(qenv(fn), 3, v0192, v0191, v0190);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-3];
    stack[-1] = v0190;
    v0190 = qvalue(elt(env, 3)); /* nil */
    qvalue(elt(env, 4)) = v0190; /* escaped!* */
    qvalue(elt(env, 22)) = v0190; /* curescaped!* */
    v0190 = stack[-1];
    fn = elt(env, 52); /* errorp */
    v0190 = (*qfn1(fn))(qenv(fn), v0190);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-3];
    if (!(v0190 == nil)) goto v0032;
    fn = elt(env, 50); /* rread */
    v0192 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-3];
    v0191 = qvalue(elt(env, 21)); /* !*backtrace */
    v0190 = qvalue(elt(env, 3)); /* nil */
    fn = elt(env, 51); /* errorset */
    v0190 = (*qfnn(fn))(qenv(fn), 3, v0192, v0191, v0190);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-3];
    stack[0] = v0190;
    v0190 = qvalue(elt(env, 3)); /* nil */
    qvalue(elt(env, 4)) = v0190; /* escaped!* */
    qvalue(elt(env, 22)) = v0190; /* curescaped!* */
    v0190 = stack[0];
    fn = elt(env, 52); /* errorp */
    v0190 = (*qfn1(fn))(qenv(fn), v0190);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-3];
    if (!(v0190 == nil)) goto v0032;
    v0192 = stack[-1];
    v0191 = elt(env, 24); /* newnam */
    v0190 = stack[0];
    v0190 = Lputprop(nil, 3, v0192, v0191, v0190);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-3];
    goto v0032;

v0233:
    fn = elt(env, 50); /* rread */
    v0192 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-3];
    v0191 = qvalue(elt(env, 21)); /* !*backtrace */
    v0190 = qvalue(elt(env, 3)); /* nil */
    fn = elt(env, 51); /* errorset */
    v0190 = (*qfnn(fn))(qenv(fn), 3, v0192, v0191, v0190);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-3];
    v0190 = qvalue(elt(env, 3)); /* nil */
    qvalue(elt(env, 4)) = v0190; /* escaped!* */
    qvalue(elt(env, 22)) = v0190; /* curescaped!* */
    goto v0032;

v0212:
    v0190 = qvalue(elt(env, 7)); /* t */
    goto v0213;

v0208:
    v0191 = qvalue(elt(env, 14)); /* ttype!* */
    v0190 = (Lisp_Object)49; /* 3 */
    v0190 = (v0191 == v0190 ? lisp_true : nil);
    goto v0209;

v0205:
    v0190 = qvalue(elt(env, 7)); /* t */
    goto v0206;

v0204:
    v0190 = qvalue(elt(env, 7)); /* t */
    goto v0206;

v0055:
    v0190 = qvalue(elt(env, 7)); /* t */
    goto v0202;

v0194:
    v0190 = qvalue(elt(env, 3)); /* nil */
    goto v0195;
/* error exit handlers */
v0193:
    popv(4);
    return nil;
}



/* Code for mri_2pasfat */

static Lisp_Object CC_mri_2pasfat(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0033, v0038;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mri_2pasfat");
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
    v0033 = stack[0];
    fn = elt(env, 2); /* mri_op */
    stack[-1] = (*qfn1(fn))(qenv(fn), v0033);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    env = stack[-2];
    v0033 = stack[0];
    fn = elt(env, 3); /* mri_arg2l */
    v0033 = (*qfn1(fn))(qenv(fn), v0033);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    env = stack[-2];
    v0038 = qvalue(elt(env, 1)); /* nil */
    {
        Lisp_Object v0054 = stack[-1];
        popv(3);
        return list3(v0054, v0033, v0038);
    }
/* error exit handlers */
v0050:
    popv(3);
    return nil;
}



/* Code for vdp_poly */

static Lisp_Object CC_vdp_poly(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object v0020;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for vdp_poly");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0020 = v0000;
/* end of prologue */
    v0020 = qcdr(v0020);
    v0020 = qcdr(v0020);
    v0020 = qcdr(v0020);
    v0020 = qcar(v0020);
    return onevalue(v0020);
}



/* Code for expression */

static Lisp_Object CC_expression(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0256, v0257, v0258;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for expression");
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
    v0258 = v0000;
/* end of prologue */
    v0256 = v0258;
    if (!consp(v0256)) goto v0020;
    v0256 = v0258;
    v0257 = qcar(v0256);
    v0256 = elt(env, 1); /* !:rd!: */
    if (v0257 == v0256) goto v0013;
    v0256 = v0258;
    v0257 = qcar(v0256);
    v0256 = qvalue(elt(env, 2)); /* unary!* */
    v0256 = Lassoc(nil, v0257, v0256);
    v0257 = v0256;
    if (v0256 == nil) goto v0259;
    v0256 = v0257;
    v0256 = qcdr(v0256);
    v0256 = qcdr(v0256);
    v0256 = qcar(v0256);
    if (v0256 == nil) goto v0008;
    v0256 = v0257;
    v0256 = qcdr(v0256);
    stack[0] = qcar(v0256);
    v0256 = v0258;
    v0256 = qcdr(v0256);
    v0257 = qcdr(v0257);
    v0257 = qcdr(v0257);
    v0257 = qcar(v0257);
    v0256 = list2(v0256, v0257);
    nil = C_nil;
    if (exception_pending()) goto v0184;
    env = stack[-1];
    fn = elt(env, 5); /* apply */
    v0256 = (*qfn2(fn))(qenv(fn), stack[0], v0256);
    nil = C_nil;
    if (exception_pending()) goto v0184;
    goto v0032;

v0032:
    v0256 = nil;
    { popv(2); return onevalue(v0256); }

v0008:
    v0256 = v0257;
    v0256 = qcdr(v0256);
    stack[0] = qcar(v0256);
    v0256 = v0258;
    v0256 = qcdr(v0256);
    v0256 = ncons(v0256);
    nil = C_nil;
    if (exception_pending()) goto v0184;
    env = stack[-1];
    fn = elt(env, 5); /* apply */
    v0256 = (*qfn2(fn))(qenv(fn), stack[0], v0256);
    nil = C_nil;
    if (exception_pending()) goto v0184;
    goto v0032;

v0259:
    v0256 = v0258;
    v0257 = qcar(v0256);
    v0256 = elt(env, 3); /* !*sq */
    if (v0257 == v0256) goto v0260;
    v0256 = v0258;
    fn = elt(env, 6); /* operator_fn */
    v0256 = (*qfn1(fn))(qenv(fn), v0256);
    nil = C_nil;
    if (exception_pending()) goto v0184;
    goto v0032;

v0260:
    v0256 = v0258;
    v0256 = qcdr(v0256);
    v0256 = qcar(v0256);
    fn = elt(env, 7); /* prepsq */
    v0256 = (*qfn1(fn))(qenv(fn), v0256);
    nil = C_nil;
    if (exception_pending()) goto v0184;
    env = stack[-1];
    v0256 = CC_expression(env, v0256);
    nil = C_nil;
    if (exception_pending()) goto v0184;
    goto v0032;

v0013:
    v0256 = v0258;
    fn = elt(env, 8); /* printout */
    v0256 = (*qfn1(fn))(qenv(fn), v0256);
    nil = C_nil;
    if (exception_pending()) goto v0184;
    goto v0032;

v0020:
    v0256 = v0258;
    fn = elt(env, 9); /* f4 */
    v0256 = (*qfn1(fn))(qenv(fn), v0256);
    nil = C_nil;
    if (exception_pending()) goto v0184;
    goto v0032;
/* error exit handlers */
v0184:
    popv(2);
    return nil;
}



/* Code for spmultm2 */

static Lisp_Object MS_CDECL CC_spmultm2(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0155, v0281, v0282, v0283;
    Lisp_Object fn;
    Lisp_Object v0028, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "spmultm2");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0001 = va_arg(aa, Lisp_Object);
    v0028 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for spmultm2");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0028,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0028);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    v0155 = v0028;
    stack[-10] = v0001;
    stack[-11] = v0000;
/* end of prologue */
    v0281 = v0155;
    v0281 = qcdr(v0281);
    v0281 = qcar(v0281);
    fn = elt(env, 3); /* mkempspmat */
    v0155 = (*qfn2(fn))(qenv(fn), v0281, v0155);
    nil = C_nil;
    if (exception_pending()) goto v0151;
    env = stack[-13];
    stack[-12] = v0155;
    v0155 = stack[-11];
    v0155 = qcdr(v0155);
    v0281 = qcar(v0155);
    v0155 = stack[-11];
    v0155 = qcdr(v0155);
    v0155 = qcdr(v0155);
    v0155 = qcar(v0155);
    v0155 = qcdr(v0155);
    v0155 = qcar(v0155);
    fn = elt(env, 4); /* empty */
    v0155 = (*qfn2(fn))(qenv(fn), v0281, v0155);
    nil = C_nil;
    if (exception_pending()) goto v0151;
    env = stack[-13];
    if (v0155 == nil) goto v0042;
    v0155 = stack[-10];
    v0155 = qcdr(v0155);
    v0281 = qcar(v0155);
    v0155 = stack[-10];
    v0155 = qcdr(v0155);
    v0155 = qcdr(v0155);
    v0155 = qcar(v0155);
    v0155 = qcdr(v0155);
    v0155 = qcar(v0155);
    fn = elt(env, 4); /* empty */
    v0155 = (*qfn2(fn))(qenv(fn), v0281, v0155);
    nil = C_nil;
    if (exception_pending()) goto v0151;
    env = stack[-13];
    v0155 = (v0155 == nil ? lisp_true : nil);
    goto v0041;

v0041:
    if (!(v0155 == nil)) { Lisp_Object res = stack[-12]; popv(14); return onevalue(res); }
    v0155 = stack[-11];
    v0155 = qcdr(v0155);
    v0155 = qcar(v0155);
    stack[-9] = v0155;
    v0155 = stack[-10];
    v0155 = qcdr(v0155);
    v0155 = qcar(v0155);
    stack[-8] = v0155;
    v0155 = (Lisp_Object)17; /* 1 */
    stack[-3] = v0155;
    goto v0017;

v0017:
    v0155 = stack[-11];
    v0155 = qcdr(v0155);
    v0155 = qcdr(v0155);
    v0155 = qcar(v0155);
    v0155 = qcdr(v0155);
    v0281 = qcar(v0155);
    v0155 = stack[-3];
    v0155 = difference2(v0281, v0155);
    nil = C_nil;
    if (exception_pending()) goto v0151;
    env = stack[-13];
    v0155 = Lminusp(nil, v0155);
    env = stack[-13];
    if (!(v0155 == nil)) { Lisp_Object res = stack[-12]; popv(14); return onevalue(res); }
    v0281 = stack[-9];
    v0155 = stack[-3];
    fn = elt(env, 5); /* findrow */
    v0155 = (*qfn2(fn))(qenv(fn), v0281, v0155);
    nil = C_nil;
    if (exception_pending()) goto v0151;
    env = stack[-13];
    stack[-7] = v0155;
    v0155 = stack[-7];
    if (v0155 == nil) goto v0179;
    v0155 = (Lisp_Object)17; /* 1 */
    stack[-2] = v0155;
    goto v0284;

v0284:
    v0155 = stack[-10];
    v0155 = qcdr(v0155);
    v0155 = qcdr(v0155);
    v0155 = qcar(v0155);
    v0155 = qcdr(v0155);
    v0281 = qcar(v0155);
    v0155 = stack[-2];
    v0155 = difference2(v0281, v0155);
    nil = C_nil;
    if (exception_pending()) goto v0151;
    env = stack[-13];
    v0155 = Lminusp(nil, v0155);
    env = stack[-13];
    if (!(v0155 == nil)) goto v0179;
    v0281 = stack[-8];
    v0155 = stack[-2];
    fn = elt(env, 5); /* findrow */
    v0155 = (*qfn2(fn))(qenv(fn), v0281, v0155);
    nil = C_nil;
    if (exception_pending()) goto v0151;
    env = stack[-13];
    stack[-6] = v0155;
    v0155 = stack[-6];
    if (v0155 == nil) goto v0285;
    v0155 = (Lisp_Object)1; /* 0 */
    fn = elt(env, 6); /* simp */
    v0155 = (*qfn1(fn))(qenv(fn), v0155);
    nil = C_nil;
    if (exception_pending()) goto v0151;
    env = stack[-13];
    stack[-4] = v0155;
    v0155 = stack[-7];
    v0155 = qcdr(v0155);
    stack[-1] = v0155;
    goto v0286;

v0286:
    v0155 = stack[-1];
    if (v0155 == nil) goto v0208;
    v0155 = stack[-1];
    v0155 = qcar(v0155);
    v0281 = v0155;
    v0155 = v0281;
    v0155 = qcar(v0155);
    v0281 = qcdr(v0281);
    v0282 = v0281;
    v0281 = v0155;
    v0155 = stack[-6];
    v0155 = Latsoc(nil, v0281, v0155);
    stack[-5] = v0155;
    v0155 = stack[-5];
    if (v0155 == nil) goto v0167;
    v0155 = stack[-5];
    v0155 = qcdr(v0155);
    stack[-5] = v0155;
    v0155 = v0282;
    fn = elt(env, 6); /* simp */
    stack[0] = (*qfn1(fn))(qenv(fn), v0155);
    nil = C_nil;
    if (exception_pending()) goto v0151;
    env = stack[-13];
    v0155 = stack[-5];
    fn = elt(env, 6); /* simp */
    v0155 = (*qfn1(fn))(qenv(fn), v0155);
    nil = C_nil;
    if (exception_pending()) goto v0151;
    env = stack[-13];
    fn = elt(env, 7); /* multsq */
    v0155 = (*qfn2(fn))(qenv(fn), stack[0], v0155);
    nil = C_nil;
    if (exception_pending()) goto v0151;
    env = stack[-13];
    stack[0] = v0155;
    v0281 = stack[-4];
    v0155 = stack[0];
    fn = elt(env, 8); /* addsq */
    v0155 = (*qfn2(fn))(qenv(fn), v0281, v0155);
    nil = C_nil;
    if (exception_pending()) goto v0151;
    env = stack[-13];
    stack[-4] = v0155;
    goto v0287;

v0287:
    v0155 = stack[-1];
    v0155 = qcdr(v0155);
    stack[-1] = v0155;
    goto v0286;

v0167:
    v0155 = stack[-4];
    stack[-4] = v0155;
    goto v0287;

v0208:
    v0155 = stack[-4];
    fn = elt(env, 9); /* mk!*sq */
    v0155 = (*qfn1(fn))(qenv(fn), v0155);
    nil = C_nil;
    if (exception_pending()) goto v0151;
    env = stack[-13];
    stack[0] = v0155;
    v0281 = stack[0];
    v0155 = (Lisp_Object)1; /* 0 */
    if (v0281 == v0155) goto v0285;
    v0282 = stack[-12];
    v0281 = stack[-3];
    v0155 = stack[-2];
    v0283 = list3(v0282, v0281, v0155);
    nil = C_nil;
    if (exception_pending()) goto v0151;
    env = stack[-13];
    v0282 = stack[0];
    v0281 = stack[-12];
    v0155 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 10); /* letmtr3 */
    v0155 = (*qfnn(fn))(qenv(fn), 4, v0283, v0282, v0281, v0155);
    nil = C_nil;
    if (exception_pending()) goto v0151;
    env = stack[-13];
    goto v0285;

v0285:
    v0155 = stack[-2];
    v0155 = add1(v0155);
    nil = C_nil;
    if (exception_pending()) goto v0151;
    env = stack[-13];
    stack[-2] = v0155;
    goto v0284;

v0179:
    v0155 = stack[-3];
    v0155 = add1(v0155);
    nil = C_nil;
    if (exception_pending()) goto v0151;
    env = stack[-13];
    stack[-3] = v0155;
    goto v0017;

v0042:
    v0155 = qvalue(elt(env, 1)); /* t */
    goto v0041;
/* error exit handlers */
v0151:
    popv(14);
    return nil;
}



/* Code for exchk2 */

static Lisp_Object CC_exchk2(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0292, v0261, v0293;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for exchk2");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0001;
    stack[-1] = v0000;
/* end of prologue */

v0032:
    v0292 = stack[-1];
    if (v0292 == nil) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v0292 = stack[-1];
    v0292 = qcdr(v0292);
    stack[-2] = v0292;
    v0292 = stack[-1];
    v0292 = qcar(v0292);
    v0292 = qcdr(v0292);
    fn = elt(env, 6); /* prepsqx */
    v0292 = (*qfn1(fn))(qenv(fn), v0292);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    env = stack[-3];
    v0293 = v0292;
    v0261 = (Lisp_Object)17; /* 1 */
    if (v0293 == v0261) goto v0029;
    v0261 = qvalue(elt(env, 1)); /* !*nosqrts */
    if (v0261 == nil) goto v0189;
    v0293 = elt(env, 2); /* expt */
    v0261 = stack[-1];
    v0261 = qcar(v0261);
    v0261 = qcar(v0261);
    v0292 = list3(v0293, v0261, v0292);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    env = stack[-3];
    v0261 = v0292;
    goto v0054;

v0054:
    v0292 = stack[0];
    v0292 = cons(v0261, v0292);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    env = stack[-3];
    stack[0] = v0292;
    v0292 = stack[-2];
    stack[-1] = v0292;
    goto v0032;

v0189:
    v0293 = v0292;
    v0261 = elt(env, 3); /* (quotient 1 2) */
    if (equal(v0293, v0261)) goto v0294;
    v0293 = v0292;
    v0261 = elt(env, 5); /* 0.5 */
    if (equal(v0293, v0261)) goto v0015;
    v0293 = elt(env, 2); /* expt */
    v0261 = stack[-1];
    v0261 = qcar(v0261);
    v0261 = qcar(v0261);
    v0292 = list3(v0293, v0261, v0292);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    env = stack[-3];
    v0261 = v0292;
    goto v0054;

v0015:
    v0261 = elt(env, 4); /* sqrt */
    v0292 = stack[-1];
    v0292 = qcar(v0292);
    v0292 = qcar(v0292);
    v0292 = list2(v0261, v0292);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    env = stack[-3];
    v0261 = v0292;
    goto v0054;

v0294:
    v0261 = elt(env, 4); /* sqrt */
    v0292 = stack[-1];
    v0292 = qcar(v0292);
    v0292 = qcar(v0292);
    v0292 = list2(v0261, v0292);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    env = stack[-3];
    v0261 = v0292;
    goto v0054;

v0029:
    v0292 = stack[-1];
    v0292 = qcar(v0292);
    v0292 = qcar(v0292);
    v0261 = v0292;
    goto v0054;
/* error exit handlers */
v0183:
    popv(4);
    return nil;
}



/* Code for covposp */

static Lisp_Object CC_covposp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0044, v0011;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for covposp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0044 = v0000;
/* end of prologue */

v0295:
    v0011 = v0044;
    if (v0011 == nil) goto v0051;
    v0011 = v0044;
    v0011 = qcar(v0011);
    if (!consp(v0011)) goto v0050;
    v0044 = qcdr(v0044);
    goto v0295;

v0050:
    v0044 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v0044);

v0051:
    v0044 = qvalue(elt(env, 1)); /* t */
    return onevalue(v0044);
}



/* Code for statep!* */

static Lisp_Object CC_statepH(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0052, v0013;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for statep*");
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
    v0052 = v0000;
/* end of prologue */
    fn = elt(env, 2); /* getphystype */
    v0052 = (*qfn1(fn))(qenv(fn), v0052);
    nil = C_nil;
    if (exception_pending()) goto v0014;
    env = stack[0];
    v0013 = elt(env, 1); /* state */
    v0052 = (v0052 == v0013 ? lisp_true : nil);
    { popv(1); return onevalue(v0052); }
/* error exit handlers */
v0014:
    popv(1);
    return nil;
}



/* Code for form1 */

static Lisp_Object MS_CDECL CC_form1(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0359, v0104, v0103, v0360;
    Lisp_Object fn;
    Lisp_Object v0028, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "form1");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0001 = va_arg(aa, Lisp_Object);
    v0028 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for form1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0028,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0028);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0028;
    stack[-2] = v0001;
    stack[-3] = v0000;
/* end of prologue */

v0295:
    v0359 = stack[-3];
    if (!consp(v0359)) goto v0056;
    v0359 = stack[-3];
    v0359 = qcar(v0359);
    if (!consp(v0359)) goto v0059;
    v0103 = stack[-3];
    v0104 = stack[-2];
    v0359 = stack[-1];
    {
        popv(6);
        fn = elt(env, 25); /* form2 */
        return (*qfnn(fn))(qenv(fn), 3, v0103, v0104, v0359);
    }

v0059:
    v0359 = stack[-3];
    v0359 = qcar(v0359);
    if (symbolp(v0359)) goto v0019;
    v0359 = stack[-3];
    v0104 = qcar(v0359);
    v0359 = elt(env, 3); /* "operator" */
    fn = elt(env, 26); /* typerr */
    v0359 = (*qfn2(fn))(qenv(fn), v0104, v0359);
    nil = C_nil;
    if (exception_pending()) goto v0361;
    env = stack[-5];
    goto v0362;

v0362:
    v0104 = stack[-1];
    v0359 = elt(env, 6); /* symbolic */
    if (v0104 == v0359) goto v0363;
    v0359 = stack[-3];
    v0359 = qcar(v0359);
    if (!symbolp(v0359)) v0359 = nil;
    else { v0359 = qfastgets(v0359);
           if (v0359 != nil) { v0359 = elt(v0359, 59); /* opfn */
#ifdef RECORD_GET
             if (v0359 == SPID_NOPROP)
                record_get(elt(fastget_names, 59), 0),
                v0359 = nil;
             else record_get(elt(fastget_names, 59), 1),
                v0359 = lisp_true; }
           else record_get(elt(fastget_names, 59), 0); }
#else
             if (v0359 == SPID_NOPROP) v0359 = nil; else v0359 = lisp_true; }}
#endif
    goto v0364;

v0364:
    if (v0359 == nil) goto v0134;
    v0359 = stack[-3];
    fn = elt(env, 27); /* argnochk */
    v0359 = (*qfn1(fn))(qenv(fn), v0359);
    nil = C_nil;
    if (exception_pending()) goto v0361;
    env = stack[-5];
    goto v0134;

v0134:
    v0359 = stack[-3];
    v0103 = qcdr(v0359);
    v0104 = stack[-2];
    v0359 = stack[-1];
    fn = elt(env, 28); /* formlis */
    v0359 = (*qfnn(fn))(qenv(fn), 3, v0103, v0104, v0359);
    nil = C_nil;
    if (exception_pending()) goto v0361;
    env = stack[-5];
    stack[-4] = v0359;
    v0104 = stack[-4];
    v0359 = stack[-3];
    v0359 = qcdr(v0359);
    if (equal(v0104, v0359)) goto v0365;
    v0359 = stack[-3];
    v0104 = qcar(v0359);
    v0359 = stack[-4];
    v0359 = cons(v0104, v0359);
    nil = C_nil;
    if (exception_pending()) goto v0361;
    env = stack[-5];
    goto v0366;

v0366:
    stack[0] = v0359;
    v0104 = stack[-1];
    v0359 = elt(env, 6); /* symbolic */
    if (v0104 == v0359) goto v0367;
    v0359 = stack[-3];
    v0359 = qcar(v0359);
    if (!symbolp(v0359)) v0359 = nil;
    else { v0359 = qfastgets(v0359);
           if (v0359 != nil) { v0359 = elt(v0359, 36); /* stat */
#ifdef RECORD_GET
             if (v0359 != SPID_NOPROP)
                record_get(elt(fastget_names, 36), 1);
             else record_get(elt(fastget_names, 36), 0),
                v0359 = nil; }
           else record_get(elt(fastget_names, 36), 0); }
#else
             if (v0359 == SPID_NOPROP) v0359 = nil; }}
#endif
    if (!(v0359 == nil)) goto v0368;
    v0359 = stack[-3];
    v0359 = qcdr(v0359);
    if (v0359 == nil) goto v0369;
    v0359 = stack[-3];
    v0359 = qcdr(v0359);
    v0104 = qcar(v0359);
    v0359 = elt(env, 18); /* quote */
    if (!consp(v0104)) goto v0123;
    v0104 = qcar(v0104);
    if (!(v0104 == v0359)) goto v0123;
    v0359 = qvalue(elt(env, 19)); /* !*micro!-version */
    if (v0359 == nil) goto v0107;
    v0359 = qvalue(elt(env, 20)); /* !*defn */
    v0359 = (v0359 == nil ? lisp_true : nil);
    goto v0370;

v0370:
    v0359 = (v0359 == nil ? lisp_true : nil);
    goto v0371;

v0371:
    if (!(v0359 == nil)) goto v0368;
    v0104 = stack[0];
    v0359 = stack[-2];
    fn = elt(env, 29); /* intexprnp */
    v0359 = (*qfn2(fn))(qenv(fn), v0104, v0359);
    nil = C_nil;
    if (exception_pending()) goto v0361;
    env = stack[-5];
    if (v0359 == nil) goto v0108;
    v0359 = qvalue(elt(env, 21)); /* !*composites */
    if (v0359 == nil) goto v0372;
    v0359 = qvalue(elt(env, 15)); /* nil */
    goto v0368;

v0368:
    if (v0359 == nil) goto v0373;
    v0104 = stack[0];
    v0359 = stack[-1];
    {
        popv(6);
        fn = elt(env, 30); /* macrochk */
        return (*qfn2(fn))(qenv(fn), v0104, v0359);
    }

v0373:
    v0104 = stack[-1];
    v0359 = elt(env, 23); /* algebraic */
    if (v0104 == v0359) goto v0374;
    v0360 = stack[0];
    v0103 = stack[-2];
    v0104 = stack[-1];
    v0359 = elt(env, 23); /* algebraic */
    {
        popv(6);
        fn = elt(env, 31); /* convertmode */
        return (*qfnn(fn))(qenv(fn), 4, v0360, v0103, v0104, v0359);
    }

v0374:
    stack[0] = elt(env, 24); /* list */
    v0359 = stack[-3];
    v0104 = qcar(v0359);
    v0359 = stack[-2];
    fn = elt(env, 32); /* algid */
    v0104 = (*qfn2(fn))(qenv(fn), v0104, v0359);
    nil = C_nil;
    if (exception_pending()) goto v0361;
    v0359 = stack[-4];
    {
        Lisp_Object v0375 = stack[0];
        popv(6);
        return list2star(v0375, v0104, v0359);
    }

v0372:
    v0104 = qvalue(elt(env, 22)); /* current!-modulus */
    v0359 = (Lisp_Object)17; /* 1 */
    v0359 = (v0104 == v0359 ? lisp_true : nil);
    goto v0368;

v0108:
    v0359 = qvalue(elt(env, 15)); /* nil */
    goto v0368;

v0107:
    v0359 = qvalue(elt(env, 15)); /* nil */
    goto v0370;

v0123:
    v0359 = qvalue(elt(env, 15)); /* nil */
    goto v0371;

v0369:
    v0359 = qvalue(elt(env, 15)); /* nil */
    goto v0371;

v0367:
    v0359 = qvalue(elt(env, 9)); /* t */
    goto v0368;

v0365:
    v0359 = stack[-3];
    goto v0366;

v0363:
    v0359 = qvalue(elt(env, 9)); /* t */
    goto v0364;

v0019:
    v0359 = stack[-3];
    v0104 = qcar(v0359);
    v0359 = elt(env, 4); /* comment */
    if (v0104 == v0359) goto v0278;
    v0359 = stack[-3];
    v0104 = qcar(v0359);
    v0359 = elt(env, 5); /* noform */
    v0359 = Lflagp(nil, v0104, v0359);
    env = stack[-5];
    if (!(v0359 == nil)) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v0359 = stack[-3];
    v0359 = qcar(v0359);
    fn = elt(env, 33); /* arrayp */
    v0359 = (*qfn1(fn))(qenv(fn), v0359);
    nil = C_nil;
    if (exception_pending()) goto v0361;
    env = stack[-5];
    if (v0359 == nil) goto v0376;
    v0104 = stack[-1];
    v0359 = elt(env, 6); /* symbolic */
    if (!(v0104 == v0359)) goto v0376;
    stack[0] = elt(env, 7); /* getel */
    v0103 = stack[-3];
    v0104 = stack[-2];
    v0359 = stack[-1];
    fn = elt(env, 34); /* intargfn */
    v0359 = (*qfnn(fn))(qenv(fn), 3, v0103, v0104, v0359);
    nil = C_nil;
    if (exception_pending()) goto v0361;
    {
        Lisp_Object v0377 = stack[0];
        popv(6);
        return list2(v0377, v0359);
    }

v0376:
    v0359 = stack[-3];
    v0359 = qcdr(v0359);
    if (v0359 == nil) goto v0286;
    v0359 = stack[-3];
    v0359 = qcar(v0359);
    if (!symbolp(v0359)) v0104 = nil;
    else { v0104 = qfastgets(v0359);
           if (v0104 != nil) { v0104 = elt(v0104, 2); /* rtype */
#ifdef RECORD_GET
             if (v0104 != SPID_NOPROP)
                record_get(elt(fastget_names, 2), 1);
             else record_get(elt(fastget_names, 2), 0),
                v0104 = nil; }
           else record_get(elt(fastget_names, 2), 0); }
#else
             if (v0104 == SPID_NOPROP) v0104 = nil; }}
#endif
    v0359 = elt(env, 8); /* vector */
    if (v0104 == v0359) goto v0378;
    v0359 = stack[-3];
    v0359 = qcdr(v0359);
    v0359 = qcar(v0359);
    v0359 = Lsimple_vectorp(nil, v0359);
    env = stack[-5];
    if (!(v0359 == nil)) goto v0379;
    v0359 = stack[-3];
    v0359 = qcdr(v0359);
    v0104 = qcar(v0359);
    v0359 = elt(env, 10); /* vecfn */
    v0359 = Lflagpcar(nil, v0104, v0359);
    env = stack[-5];
    goto v0379;

v0379:
    if (v0359 == nil) goto v0286;
    v0103 = stack[-3];
    v0104 = stack[-2];
    v0359 = stack[-1];
    {
        popv(6);
        fn = elt(env, 35); /* getvect */
        return (*qfnn(fn))(qenv(fn), 3, v0103, v0104, v0359);
    }

v0286:
    v0359 = stack[-3];
    v0359 = qcar(v0359);
    if (!symbolp(v0359)) v0359 = nil;
    else { v0359 = qfastgets(v0359);
           if (v0359 != nil) { v0359 = elt(v0359, 48); /* modefn */
#ifdef RECORD_GET
             if (v0359 == SPID_NOPROP)
                record_get(elt(fastget_names, 48), 0),
                v0359 = nil;
             else record_get(elt(fastget_names, 48), 1),
                v0359 = lisp_true; }
           else record_get(elt(fastget_names, 48), 0); }
#else
             if (v0359 == SPID_NOPROP) v0359 = nil; else v0359 = lisp_true; }}
#endif
    if (v0359 == nil) goto v0380;
    v0359 = stack[-3];
    v0359 = qcdr(v0359);
    v0360 = qcar(v0359);
    v0103 = stack[-2];
    v0104 = stack[-1];
    v0359 = stack[-3];
    v0359 = qcar(v0359);
    {
        popv(6);
        fn = elt(env, 31); /* convertmode */
        return (*qfnn(fn))(qenv(fn), 4, v0360, v0103, v0104, v0359);
    }

v0380:
    v0359 = stack[-3];
    v0104 = qcar(v0359);
    v0359 = elt(env, 11); /* formfn */
    v0359 = get(v0104, v0359);
    env = stack[-5];
    stack[-4] = v0359;
    if (v0359 == nil) goto v0282;
    v0360 = stack[-4];
    v0103 = stack[-3];
    v0104 = stack[-2];
    v0359 = stack[-1];
    v0104 = Lapply3(nil, 4, v0360, v0103, v0104, v0359);
    nil = C_nil;
    if (exception_pending()) goto v0361;
    env = stack[-5];
    v0359 = stack[-1];
    {
        popv(6);
        fn = elt(env, 30); /* macrochk */
        return (*qfn2(fn))(qenv(fn), v0104, v0359);
    }

v0282:
    v0359 = stack[-3];
    v0359 = qcar(v0359);
    if (!symbolp(v0359)) v0104 = nil;
    else { v0104 = qfastgets(v0359);
           if (v0104 != nil) { v0104 = elt(v0104, 36); /* stat */
#ifdef RECORD_GET
             if (v0104 != SPID_NOPROP)
                record_get(elt(fastget_names, 36), 1);
             else record_get(elt(fastget_names, 36), 0),
                v0104 = nil; }
           else record_get(elt(fastget_names, 36), 0); }
#else
             if (v0104 == SPID_NOPROP) v0104 = nil; }}
#endif
    v0359 = elt(env, 12); /* rlis */
    if (v0104 == v0359) goto v0152;
    v0359 = stack[-3];
    v0104 = qcar(v0359);
    v0359 = elt(env, 13); /* !*comma!* */
    if (!(v0104 == v0359)) goto v0362;
    v0359 = stack[-3];
    v0359 = qcdr(v0359);
    v0359 = qcar(v0359);
    if (!consp(v0359)) goto v0381;
    v0359 = stack[-3];
    v0359 = qcdr(v0359);
    v0359 = qcdr(v0359);
    v0359 = qcar(v0359);
    if (!consp(v0359)) goto v0382;
    v0359 = qvalue(elt(env, 15)); /* nil */
    goto v0146;

v0146:
    if (v0359 == nil) goto v0238;
    v0359 = stack[-3];
    v0359 = qcdr(v0359);
    v0359 = qcar(v0359);
    v0359 = qcar(v0359);
    fn = elt(env, 36); /* blocktyperr */
    v0359 = (*qfn1(fn))(qenv(fn), v0359);
    nil = C_nil;
    if (exception_pending()) goto v0361;
    env = stack[-5];
    goto v0362;

v0238:
    stack[-4] = elt(env, 16); /* rlisp */
    stack[0] = (Lisp_Object)161; /* 10 */
    v0104 = elt(env, 17); /* "Syntax error: , invalid after" */
    v0359 = stack[-3];
    v0359 = qcdr(v0359);
    v0359 = qcar(v0359);
    v0359 = list2(v0104, v0359);
    nil = C_nil;
    if (exception_pending()) goto v0361;
    env = stack[-5];
    fn = elt(env, 37); /* rerror */
    v0359 = (*qfnn(fn))(qenv(fn), 3, stack[-4], stack[0], v0359);
    nil = C_nil;
    if (exception_pending()) goto v0361;
    env = stack[-5];
    goto v0362;

v0382:
    v0359 = stack[-3];
    v0359 = qcdr(v0359);
    v0359 = qcar(v0359);
    v0104 = qcar(v0359);
    v0359 = elt(env, 14); /* type */
    v0359 = Lflagp(nil, v0104, v0359);
    env = stack[-5];
    goto v0146;

v0381:
    v0359 = qvalue(elt(env, 15)); /* nil */
    goto v0146;

v0152:
    v0103 = stack[-3];
    v0104 = stack[-2];
    v0359 = stack[-1];
    fn = elt(env, 38); /* formrlis */
    v0104 = (*qfnn(fn))(qenv(fn), 3, v0103, v0104, v0359);
    nil = C_nil;
    if (exception_pending()) goto v0361;
    env = stack[-5];
    v0359 = stack[-1];
    {
        popv(6);
        fn = elt(env, 30); /* macrochk */
        return (*qfn2(fn))(qenv(fn), v0104, v0359);
    }

v0378:
    v0359 = qvalue(elt(env, 9)); /* t */
    goto v0379;

v0278:
    v0359 = stack[-3];
    fn = elt(env, 39); /* lastpair */
    v0359 = (*qfn1(fn))(qenv(fn), v0359);
    nil = C_nil;
    if (exception_pending()) goto v0361;
    env = stack[-5];
    v0103 = qcar(v0359);
    v0104 = stack[-2];
    v0359 = stack[-1];
    stack[-3] = v0103;
    stack[-2] = v0104;
    stack[-1] = v0359;
    goto v0295;

v0056:
    v0359 = stack[-3];
    if (!(symbolp(v0359))) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v0104 = stack[-3];
    v0359 = elt(env, 1); /* ed */
    if (v0104 == v0359) goto v0050;
    v0359 = stack[-3];
    if (!symbolp(v0359)) v0359 = nil;
    else { v0359 = qfastgets(v0359);
           if (v0359 != nil) { v0359 = elt(v0359, 48); /* modefn */
#ifdef RECORD_GET
             if (v0359 == SPID_NOPROP)
                record_get(elt(fastget_names, 48), 0),
                v0359 = nil;
             else record_get(elt(fastget_names, 48), 1),
                v0359 = lisp_true; }
           else record_get(elt(fastget_names, 48), 0); }
#else
             if (v0359 == SPID_NOPROP) v0359 = nil; else v0359 = lisp_true; }}
#endif
    if (v0359 == nil) goto v0195;
    v0359 = stack[-3];
    {
        popv(6);
        fn = elt(env, 40); /* set!-global!-mode */
        return (*qfn1(fn))(qenv(fn), v0359);
    }

v0195:
    v0104 = stack[-1];
    v0359 = elt(env, 2); /* idfn */
    v0359 = get(v0104, v0359);
    stack[-4] = v0359;
    if (v0359 == nil) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v0103 = stack[-4];
    v0104 = stack[-3];
    v0359 = stack[-2];
        popv(6);
        return Lapply2(nil, 3, v0103, v0104, v0359);

v0050:
    v0359 = stack[-3];
    popv(6);
    return ncons(v0359);
/* error exit handlers */
v0361:
    popv(6);
    return nil;
}



/* Code for mv!-domainlist!-!- */

static Lisp_Object CC_mvKdomainlistKK(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0046, v0047;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mv-domainlist--");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0001;
    stack[-1] = v0000;
/* end of prologue */
    stack[-2] = nil;
    goto v0032;

v0032:
    v0046 = stack[-1];
    if (v0046 == nil) goto v0053;
    v0046 = stack[-1];
    v0047 = qcar(v0046);
    v0046 = stack[0];
    v0046 = qcar(v0046);
    v0047 = difference2(v0047, v0046);
    nil = C_nil;
    if (exception_pending()) goto v0280;
    env = stack[-3];
    v0046 = stack[-2];
    v0046 = cons(v0047, v0046);
    nil = C_nil;
    if (exception_pending()) goto v0280;
    env = stack[-3];
    stack[-2] = v0046;
    v0046 = stack[-1];
    v0046 = qcdr(v0046);
    stack[-1] = v0046;
    v0046 = stack[0];
    v0046 = qcdr(v0046);
    stack[0] = v0046;
    goto v0032;

v0053:
    v0046 = stack[-2];
    {
        popv(4);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v0046);
    }
/* error exit handlers */
v0280:
    popv(4);
    return nil;
}



/* Code for sc_kern */

static Lisp_Object CC_sc_kern(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0034;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sc_kern");
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
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0034 = v0000;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* g_sc_ve */
    v0034 = sub1(v0034);
    nil = C_nil;
    if (exception_pending()) goto v0038;
    v0034 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v0034/(16/CELL)));
    v0034 = qcdr(v0034);
    v0034 = qcdr(v0034);
    v0034 = qcar(v0034);
    { popv(1); return onevalue(v0034); }
/* error exit handlers */
v0038:
    popv(1);
    return nil;
}



/* Code for primep */

static Lisp_Object CC_primep(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0183, v0182;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for primep");
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

v0051:
    v0183 = stack[0];
    v0183 = integerp(v0183);
    if (v0183 == nil) goto v0013;
    v0182 = stack[0];
    v0183 = (Lisp_Object)1; /* 0 */
    v0183 = (Lisp_Object)lessp2(v0182, v0183);
    nil = C_nil;
    if (exception_pending()) goto v0386;
    v0183 = v0183 ? lisp_true : nil;
    env = stack[-2];
    if (v0183 == nil) goto v0030;
    v0183 = stack[0];
    v0183 = negate(v0183);
    nil = C_nil;
    if (exception_pending()) goto v0386;
    env = stack[-2];
    stack[0] = v0183;
    goto v0051;

v0030:
    v0182 = stack[0];
    v0183 = (Lisp_Object)17; /* 1 */
    if (v0182 == v0183) goto v0041;
    v0182 = stack[0];
    v0183 = qvalue(elt(env, 3)); /* !*last!-prime!-in!-list!* */
    v0183 = (Lisp_Object)lesseq2(v0182, v0183);
    nil = C_nil;
    if (exception_pending()) goto v0386;
    v0183 = v0183 ? lisp_true : nil;
    env = stack[-2];
    if (v0183 == nil) goto v0005;
    v0183 = stack[0];
    v0182 = qvalue(elt(env, 4)); /* !*primelist!* */
    v0183 = Lmember(nil, v0183, v0182);
    { popv(3); return onevalue(v0183); }

v0005:
    v0182 = stack[0];
    v0183 = qvalue(elt(env, 5)); /* !*last!-prime!-squared!* */
    v0183 = (Lisp_Object)lesseq2(v0182, v0183);
    nil = C_nil;
    if (exception_pending()) goto v0386;
    v0183 = v0183 ? lisp_true : nil;
    env = stack[-2];
    if (v0183 == nil) goto v0184;
    v0183 = qvalue(elt(env, 4)); /* !*primelist!* */
    stack[-1] = v0183;
    goto v0002;

v0002:
    v0183 = stack[-1];
    if (v0183 == nil) goto v0356;
    v0182 = stack[0];
    v0183 = stack[-1];
    v0183 = qcar(v0183);
    v0182 = Cremainder(v0182, v0183);
    nil = C_nil;
    if (exception_pending()) goto v0386;
    env = stack[-2];
    v0183 = (Lisp_Object)1; /* 0 */
    if (v0182 == v0183) goto v0356;
    v0183 = stack[-1];
    v0183 = qcdr(v0183);
    stack[-1] = v0183;
    goto v0002;

v0356:
    v0183 = stack[-1];
    v0183 = (v0183 == nil ? lisp_true : nil);
    { popv(3); return onevalue(v0183); }

v0184:
    v0182 = stack[0];
    v0183 = qvalue(elt(env, 6)); /* largest!-small!-modulus */
    v0183 = (Lisp_Object)greaterp2(v0182, v0183);
    nil = C_nil;
    if (exception_pending()) goto v0386;
    v0183 = v0183 ? lisp_true : nil;
    env = stack[-2];
    if (v0183 == nil) goto v0293;
    v0183 = stack[0];
    {
        popv(3);
        fn = elt(env, 7); /* general!-primep */
        return (*qfn1(fn))(qenv(fn), v0183);
    }

v0293:
    v0183 = stack[0];
    {
        popv(3);
        fn = elt(env, 8); /* small!-primep */
        return (*qfn1(fn))(qenv(fn), v0183);
    }

v0041:
    v0183 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v0183); }

v0013:
    v0182 = stack[0];
    v0183 = elt(env, 1); /* "integer" */
    {
        popv(3);
        fn = elt(env, 9); /* typerr */
        return (*qfn2(fn))(qenv(fn), v0182, v0183);
    }
/* error exit handlers */
v0386:
    popv(3);
    return nil;
}



/* Code for mapcons */

static Lisp_Object CC_mapcons(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0058, v0037;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mapcons");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-3] = v0001;
    v0058 = v0000;
/* end of prologue */
    stack[-4] = v0058;
    v0058 = stack[-4];
    if (v0058 == nil) goto v0013;
    v0058 = stack[-4];
    v0058 = qcar(v0058);
    v0037 = stack[-3];
    v0058 = cons(v0037, v0058);
    nil = C_nil;
    if (exception_pending()) goto v0388;
    env = stack[-5];
    v0058 = ncons(v0058);
    nil = C_nil;
    if (exception_pending()) goto v0388;
    env = stack[-5];
    stack[-1] = v0058;
    stack[-2] = v0058;
    goto v0036;

v0036:
    v0058 = stack[-4];
    v0058 = qcdr(v0058);
    stack[-4] = v0058;
    v0058 = stack[-4];
    if (v0058 == nil) { Lisp_Object res = stack[-2]; popv(6); return onevalue(res); }
    stack[0] = stack[-1];
    v0058 = stack[-4];
    v0058 = qcar(v0058);
    v0037 = stack[-3];
    v0058 = cons(v0037, v0058);
    nil = C_nil;
    if (exception_pending()) goto v0388;
    env = stack[-5];
    v0058 = ncons(v0058);
    nil = C_nil;
    if (exception_pending()) goto v0388;
    env = stack[-5];
    v0058 = Lrplacd(nil, stack[0], v0058);
    nil = C_nil;
    if (exception_pending()) goto v0388;
    env = stack[-5];
    v0058 = stack[-1];
    v0058 = qcdr(v0058);
    stack[-1] = v0058;
    goto v0036;

v0013:
    v0058 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v0058); }
/* error exit handlers */
v0388:
    popv(6);
    return nil;
}



/* Code for gcref_mknode!-tgf */

static Lisp_Object CC_gcref_mknodeKtgf(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0053;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for gcref_mknode-tgf");
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
    v0053 = stack[0];
    v0053 = Lprinc(nil, v0053);
    nil = C_nil;
    if (exception_pending()) goto v0052;
    env = stack[-1];
    v0053 = elt(env, 1); /* " " */
    v0053 = Lprinc(nil, v0053);
    nil = C_nil;
    if (exception_pending()) goto v0052;
    env = stack[-1];
    v0053 = stack[0];
    fn = elt(env, 3); /* prin2t */
    v0053 = (*qfn1(fn))(qenv(fn), v0053);
    nil = C_nil;
    if (exception_pending()) goto v0052;
    env = stack[-1];
    v0053 = qvalue(elt(env, 2)); /* nil */
    { popv(2); return onevalue(v0053); }
/* error exit handlers */
v0052:
    popv(2);
    return nil;
}



/* Code for polynomlistfinddivisor */

static Lisp_Object MS_CDECL CC_polynomlistfinddivisor(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0253, v0186, v0022;
    Lisp_Object fn;
    Lisp_Object v0028, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "polynomlistfinddivisor");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0001 = va_arg(aa, Lisp_Object);
    v0028 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for polynomlistfinddivisor");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0028,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0028);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v0028;
    v0186 = v0001;
    v0022 = v0000;
/* end of prologue */
    v0253 = v0186;
    v0253 = qcar(v0253);
    if (v0253 == nil) goto v0056;
    v0253 = v0022;
    v0253 = qcar(v0253);
    v0253 = (v0253 == nil ? lisp_true : nil);
    goto v0053;

v0053:
    if (v0253 == nil) goto v0045;
    v0253 = qvalue(elt(env, 2)); /* nil */
    { popv(5); return onevalue(v0253); }

v0045:
    stack[0] = nil;
    v0253 = v0186;
    v0253 = qcar(v0253);
    stack[-3] = v0253;
    v0253 = v0022;
    stack[-1] = v0253;
    goto v0030;

v0030:
    v0253 = stack[-1];
    v0253 = qcar(v0253);
    if (v0253 == nil) goto v0042;
    v0253 = stack[0];
    if (!(v0253 == nil)) goto v0042;
    v0253 = stack[-2];
    if (v0253 == nil) goto v0008;
    v0186 = stack[-3];
    v0253 = stack[-1];
    v0253 = qcar(v0253);
    v0253 = qcar(v0253);
    fn = elt(env, 3); /* monomisdivisibleby */
    v0253 = (*qfn2(fn))(qenv(fn), v0186, v0253);
    nil = C_nil;
    if (exception_pending()) goto v0204;
    env = stack[-4];
    if (!(v0253 == nil)) goto v0194;

v0008:
    v0253 = stack[-2];
    if (v0253 == nil) goto v0254;
    v0253 = qvalue(elt(env, 2)); /* nil */
    goto v0388;

v0388:
    if (!(v0253 == nil)) goto v0194;
    v0253 = stack[-1];
    v0253 = qcdr(v0253);
    stack[-1] = v0253;
    goto v0030;

v0194:
    v0253 = qvalue(elt(env, 1)); /* t */
    stack[0] = v0253;
    goto v0030;

v0254:
    v0186 = stack[-3];
    v0253 = stack[-1];
    v0253 = qcar(v0253);
    v0253 = qcar(v0253);
    fn = elt(env, 4); /* monomispommaretdivisibleby */
    v0253 = (*qfn2(fn))(qenv(fn), v0186, v0253);
    nil = C_nil;
    if (exception_pending()) goto v0204;
    env = stack[-4];
    goto v0388;

v0042:
    v0253 = stack[-1];
    v0253 = qcar(v0253);
    { popv(5); return onevalue(v0253); }

v0056:
    v0253 = qvalue(elt(env, 1)); /* t */
    goto v0053;
/* error exit handlers */
v0204:
    popv(5);
    return nil;
}



/* Code for diffp1 */

static Lisp_Object CC_diffp1(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0057, v0058, v0037;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for diffp1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    v0057 = v0001;
    v0037 = v0000;
/* end of prologue */
    v0058 = v0037;
    v0058 = qcar(v0058);
    if (v0058 == v0057) goto v0040;
    v0057 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v0057); }

v0040:
    v0057 = v0037;
    v0058 = qcdr(v0057);
    v0057 = (Lisp_Object)17; /* 1 */
    if (v0058 == v0057) goto v0038;
    v0057 = v0037;
    stack[-1] = qcdr(v0057);
    v0057 = v0037;
    stack[0] = qcar(v0057);
    v0057 = v0037;
    v0057 = qcdr(v0057);
    v0057 = sub1(v0057);
    nil = C_nil;
    if (exception_pending()) goto v0059;
    env = stack[-2];
    fn = elt(env, 2); /* to */
    v0058 = (*qfn2(fn))(qenv(fn), stack[0], v0057);
    nil = C_nil;
    if (exception_pending()) goto v0059;
    env = stack[-2];
    v0057 = (Lisp_Object)17; /* 1 */
    v0057 = cons(v0058, v0057);
    nil = C_nil;
    if (exception_pending()) goto v0059;
    env = stack[-2];
    v0057 = ncons(v0057);
    nil = C_nil;
    if (exception_pending()) goto v0059;
    env = stack[-2];
    {
        Lisp_Object v0005 = stack[-1];
        popv(3);
        fn = elt(env, 3); /* multd */
        return (*qfn2(fn))(qenv(fn), v0005, v0057);
    }

v0038:
    v0057 = (Lisp_Object)17; /* 1 */
    { popv(3); return onevalue(v0057); }
/* error exit handlers */
v0059:
    popv(3);
    return nil;
}



/* Code for revv0 */

static Lisp_Object CC_revv0(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0187, v0188;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for revv0");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0001;
    stack[-1] = v0000;
/* end of prologue */

v0020:
    v0187 = stack[-1];
    v0187 = qcdr(v0187);
    v0188 = qcar(v0187);
    v0187 = stack[0];
    if (v0188 == v0187) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v0187 = stack[-1];
    v0187 = qcdr(v0187);
    v0187 = qcar(v0187);
    stack[-2] = v0187;
    v0187 = stack[-1];
    v0188 = qcdr(v0187);
    v0187 = stack[-1];
    v0187 = qcdr(v0187);
    v0187 = qcdr(v0187);
    v0187 = qcar(v0187);
    v0187 = Lrplaca(nil, v0188, v0187);
    nil = C_nil;
    if (exception_pending()) goto v0002;
    env = stack[-3];
    v0187 = stack[-1];
    v0187 = qcdr(v0187);
    v0188 = qcdr(v0187);
    v0187 = stack[-1];
    v0187 = qcdr(v0187);
    v0187 = qcdr(v0187);
    v0187 = qcdr(v0187);
    v0187 = qcar(v0187);
    v0187 = Lrplaca(nil, v0188, v0187);
    nil = C_nil;
    if (exception_pending()) goto v0002;
    env = stack[-3];
    v0187 = stack[-1];
    v0187 = qcdr(v0187);
    v0187 = qcdr(v0187);
    v0188 = qcdr(v0187);
    v0187 = stack[-2];
    v0187 = Lrplaca(nil, v0188, v0187);
    nil = C_nil;
    if (exception_pending()) goto v0002;
    env = stack[-3];
    v0188 = stack[-1];
    v0187 = stack[0];
    stack[-1] = v0188;
    stack[0] = v0187;
    goto v0020;
/* error exit handlers */
v0002:
    popv(4);
    return nil;
}



/* Code for ibalp_litp */

static Lisp_Object CC_ibalp_litp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0009, v0010;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ibalp_litp");
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
    v0009 = stack[0];
    fn = elt(env, 3); /* ibalp_atomp */
    v0009 = (*qfn1(fn))(qenv(fn), v0009);
    nil = C_nil;
    if (exception_pending()) goto v0046;
    env = stack[-1];
    if (!(v0009 == nil)) { popv(2); return onevalue(v0009); }
    v0009 = stack[0];
    if (!consp(v0009)) goto v0040;
    v0009 = stack[0];
    v0009 = qcar(v0009);
    v0010 = v0009;
    goto v0014;

v0014:
    v0009 = elt(env, 1); /* not */
    if (v0010 == v0009) goto v0053;
    v0009 = qvalue(elt(env, 2)); /* nil */
    { popv(2); return onevalue(v0009); }

v0053:
    v0009 = stack[0];
    v0009 = qcdr(v0009);
    v0009 = qcar(v0009);
    {
        popv(2);
        fn = elt(env, 3); /* ibalp_atomp */
        return (*qfn1(fn))(qenv(fn), v0009);
    }

v0040:
    v0009 = stack[0];
    v0010 = v0009;
    goto v0014;
/* error exit handlers */
v0046:
    popv(2);
    return nil;
}



/* Code for on */

static Lisp_Object CC_on(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0054;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for on");
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
    v0054 = v0000;
/* end of prologue */
    stack[0] = v0054;
    goto v0021;

v0021:
    v0054 = stack[0];
    if (v0054 == nil) goto v0053;
    v0054 = stack[0];
    v0054 = qcar(v0054);
    fn = elt(env, 2); /* on1 */
    v0054 = (*qfn1(fn))(qenv(fn), v0054);
    nil = C_nil;
    if (exception_pending()) goto v0044;
    env = stack[-1];
    v0054 = stack[0];
    v0054 = qcdr(v0054);
    stack[0] = v0054;
    goto v0021;

v0053:
    v0054 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v0054); }
/* error exit handlers */
v0044:
    popv(2);
    return nil;
}



/* Code for vdpgetprop */

static Lisp_Object CC_vdpgetprop(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0279, v0384, v0294, v0254;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for vdpgetprop");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    v0294 = v0001;
    v0254 = v0000;
/* end of prologue */
    v0279 = v0254;
    if (v0279 == nil) goto v0021;
    v0384 = v0254;
    v0279 = elt(env, 2); /* vdp */
    if (!consp(v0384)) goto v0054;
    v0384 = qcar(v0384);
    if (!(v0384 == v0279)) goto v0054;
    v0279 = v0294;
    v0384 = v0254;
    v0384 = qcdr(v0384);
    v0384 = qcdr(v0384);
    v0384 = qcdr(v0384);
    v0384 = qcdr(v0384);
    v0384 = qcar(v0384);
    v0279 = Lassoc(nil, v0279, v0384);
    v0384 = v0279;
    v0279 = v0384;
    if (v0279 == nil) goto v0389;
    v0279 = v0384;
    v0279 = qcdr(v0279);
    { popv(3); return onevalue(v0279); }

v0389:
    v0279 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v0279); }

v0054:
    stack[-1] = elt(env, 3); /* dipoly */
    stack[0] = (Lisp_Object)113; /* 7 */
    v0279 = elt(env, 4); /* "vdpgetprop given a non-vdp as 1st parameter" 
*/
    v0384 = v0254;
    v0279 = list3(v0279, v0384, v0294);
    nil = C_nil;
    if (exception_pending()) goto v0355;
    env = stack[-2];
    {
        Lisp_Object v0291 = stack[-1];
        Lisp_Object v0356 = stack[0];
        popv(3);
        fn = elt(env, 5); /* rerror */
        return (*qfnn(fn))(qenv(fn), 3, v0291, v0356, v0279);
    }

v0021:
    v0279 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v0279); }
/* error exit handlers */
v0355:
    popv(3);
    return nil;
}



/* Code for xord_lex */

static Lisp_Object CC_xord_lex(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0002, v0004, v0252, v0390;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for xord_lex");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0004 = v0001;
    v0252 = v0000;
/* end of prologue */

v0021:
    v0002 = v0252;
    if (v0002 == nil) goto v0013;
    v0002 = v0252;
    v0390 = qcar(v0002);
    v0002 = (Lisp_Object)17; /* 1 */
    v0002 = (v0390 == v0002 ? lisp_true : nil);
    goto v0052;

v0052:
    if (v0002 == nil) goto v0053;
    v0002 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v0002);

v0053:
    v0002 = v0004;
    if (v0002 == nil) goto v0042;
    v0002 = v0004;
    v0390 = qcar(v0002);
    v0002 = (Lisp_Object)17; /* 1 */
    v0002 = (v0390 == v0002 ? lisp_true : nil);
    goto v0041;

v0041:
    if (v0002 == nil) goto v0026;
    v0002 = qvalue(elt(env, 1)); /* t */
    return onevalue(v0002);

v0026:
    v0002 = v0252;
    v0390 = qcar(v0002);
    v0002 = v0004;
    v0002 = qcar(v0002);
    if (v0390 == v0002) goto v0008;
    v0002 = v0252;
    v0002 = qcar(v0002);
    v0004 = qcar(v0004);
    {
        fn = elt(env, 3); /* factorordp */
        return (*qfn2(fn))(qenv(fn), v0002, v0004);
    }

v0008:
    v0002 = v0252;
    v0002 = qcdr(v0002);
    v0252 = v0002;
    v0002 = v0004;
    v0002 = qcdr(v0002);
    v0004 = v0002;
    goto v0021;

v0042:
    v0002 = qvalue(elt(env, 1)); /* t */
    goto v0041;

v0013:
    v0002 = qvalue(elt(env, 1)); /* t */
    goto v0052;
}



/* Code for convertmode1 */

static Lisp_Object MS_CDECL CC_convertmode1(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0397, v0398, v0399, v0400, v0274, v0275, v0401;
    Lisp_Object fn;
    Lisp_Object v0027, v0028, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "convertmode1");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0001 = va_arg(aa, Lisp_Object);
    v0028 = va_arg(aa, Lisp_Object);
    v0027 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for convertmode1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v0027,v0028,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0000,v0001,v0028,v0027);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v0399 = v0027;
    v0400 = v0028;
    v0274 = v0001;
    v0275 = v0000;
/* end of prologue */
    v0398 = v0399;
    v0397 = elt(env, 1); /* real */
    if (!(v0398 == v0397)) goto v0012;
    v0397 = elt(env, 2); /* algebraic */
    v0399 = v0397;
    goto v0012;

v0012:
    v0398 = v0400;
    v0397 = elt(env, 1); /* real */
    if (!(v0398 == v0397)) goto v0043;
    v0397 = elt(env, 2); /* algebraic */
    v0400 = v0397;
    goto v0043;

v0043:
    v0398 = v0400;
    v0397 = v0399;
    if (v0398 == v0397) { popv(1); return onevalue(v0275); }
    v0397 = v0275;
    if (!(symbolp(v0397))) goto v0257;
    v0398 = v0275;
    v0397 = v0274;
    v0397 = Latsoc(nil, v0398, v0397);
    v0401 = v0397;
    if (v0397 == nil) goto v0257;
    v0397 = v0401;
    v0398 = qcdr(v0397);
    v0397 = elt(env, 3); /* (integer scalar real) */
    v0397 = Lmemq(nil, v0398, v0397);
    if (v0397 == nil) goto v0355;
    v0397 = qvalue(elt(env, 4)); /* nil */
    goto v0189;

v0189:
    if (v0397 == nil) goto v0257;
    v0397 = v0275;
    v0398 = v0274;
    v0399 = v0400;
    v0400 = v0401;
    v0400 = qcdr(v0400);
    {
        popv(1);
        fn = elt(env, 5); /* convertmode */
        return (*qfnn(fn))(qenv(fn), 4, v0397, v0398, v0399, v0400);
    }

v0257:
    v0398 = v0399;
    v0397 = v0400;
    v0397 = get(v0398, v0397);
    env = stack[0];
    v0401 = v0397;
    if (v0397 == nil) goto v0288;
    v0397 = v0401;
    v0398 = v0275;
    v0399 = v0274;
        popv(1);
        return Lapply2(nil, 3, v0397, v0398, v0399);

v0288:
    v0397 = v0399;
    v0398 = v0400;
    fn = elt(env, 6); /* typerr */
    v0397 = (*qfn2(fn))(qenv(fn), v0397, v0398);
    nil = C_nil;
    if (exception_pending()) goto v0402;
    v0397 = nil;
    { popv(1); return onevalue(v0397); }

v0355:
    v0397 = v0401;
    v0398 = qcdr(v0397);
    v0397 = v0399;
    v0397 = (v0398 == v0397 ? lisp_true : nil);
    v0397 = (v0397 == nil ? lisp_true : nil);
    goto v0189;
/* error exit handlers */
v0402:
    popv(1);
    return nil;
}



/* Code for formop */

static Lisp_Object CC_formop(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0388, v0006;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for formop");
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
    stack[-2] = nil;
    goto v0032;

v0032:
    v0388 = stack[-1];
    if (!consp(v0388)) goto v0033;
    v0388 = stack[-1];
    v0388 = qcar(v0388);
    v0388 = (consp(v0388) ? nil : lisp_true);
    goto v0034;

v0034:
    if (v0388 == nil) goto v0041;
    v0388 = stack[-1];
    v0006 = v0388;
    goto v0036;

v0036:
    v0388 = stack[-2];
    if (v0388 == nil) { popv(4); return onevalue(v0006); }
    v0388 = stack[-2];
    v0388 = qcar(v0388);
    fn = elt(env, 2); /* raddf */
    v0388 = (*qfn2(fn))(qenv(fn), v0388, v0006);
    nil = C_nil;
    if (exception_pending()) goto v0254;
    env = stack[-3];
    v0006 = v0388;
    v0388 = stack[-2];
    v0388 = qcdr(v0388);
    stack[-2] = v0388;
    goto v0036;

v0041:
    v0388 = stack[-1];
    v0388 = qcar(v0388);
    stack[0] = qcar(v0388);
    v0388 = stack[-1];
    v0388 = qcar(v0388);
    v0388 = qcdr(v0388);
    v0388 = CC_formop(env, v0388);
    nil = C_nil;
    if (exception_pending()) goto v0254;
    env = stack[-3];
    fn = elt(env, 3); /* multop */
    v0006 = (*qfn2(fn))(qenv(fn), stack[0], v0388);
    nil = C_nil;
    if (exception_pending()) goto v0254;
    env = stack[-3];
    v0388 = stack[-2];
    v0388 = cons(v0006, v0388);
    nil = C_nil;
    if (exception_pending()) goto v0254;
    env = stack[-3];
    stack[-2] = v0388;
    v0388 = stack[-1];
    v0388 = qcdr(v0388);
    stack[-1] = v0388;
    goto v0032;

v0033:
    v0388 = qvalue(elt(env, 1)); /* t */
    goto v0034;
/* error exit handlers */
v0254:
    popv(4);
    return nil;
}



/* Code for leftzeros */

static Lisp_Object CC_leftzeros(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0037, v0394;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for leftzeros");
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
    goto v0032;

v0032:
    v0037 = stack[0];
    if (v0037 == nil) goto v0033;
    v0037 = stack[0];
    v0394 = qcar(v0037);
    v0037 = (Lisp_Object)1; /* 0 */
    v0037 = Lneq(nil, v0394, v0037);
    nil = C_nil;
    if (exception_pending()) goto v0005;
    env = stack[-2];
    goto v0034;

v0034:
    if (v0037 == nil) goto v0041;
    v0037 = (Lisp_Object)1; /* 0 */
    v0394 = v0037;
    goto v0036;

v0036:
    v0037 = stack[-1];
    if (v0037 == nil) { popv(3); return onevalue(v0394); }
    v0037 = stack[-1];
    v0037 = qcar(v0037);
    v0037 = (Lisp_Object)(int32_t)((int32_t)v0037 + (int32_t)v0394 - TAG_FIXNUM);
    v0394 = v0037;
    v0037 = stack[-1];
    v0037 = qcdr(v0037);
    stack[-1] = v0037;
    goto v0036;

v0041:
    v0394 = (Lisp_Object)17; /* 1 */
    v0037 = stack[-1];
    v0037 = cons(v0394, v0037);
    nil = C_nil;
    if (exception_pending()) goto v0005;
    env = stack[-2];
    stack[-1] = v0037;
    v0037 = stack[0];
    v0037 = qcdr(v0037);
    stack[0] = v0037;
    goto v0032;

v0033:
    v0037 = qvalue(elt(env, 1)); /* t */
    goto v0034;
/* error exit handlers */
v0005:
    popv(3);
    return nil;
}



/* Code for !*id2num */

static Lisp_Object CC_Hid2num(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0050, v0054;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for *id2num");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0050 = v0000;
/* end of prologue */
    v0054 = qvalue(elt(env, 1)); /* pair_id_num!* */
    v0050 = Lassoc(nil, v0050, v0054);
    v0054 = v0050;
    if (v0050 == nil) goto v0032;
    v0050 = v0054;
    v0050 = qcdr(v0050);
    return onevalue(v0050);

v0032:
    v0050 = nil;
    return onevalue(v0050);
}



/* Code for arintequiv!: */

static Lisp_Object CC_arintequivT(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0194, v0007, v0008;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for arintequiv:");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0008 = v0000;
/* end of prologue */
    v0194 = v0008;
    v0194 = qcdr(v0194);
    if (is_number(v0194)) goto v0051;
    v0194 = v0008;
    v0194 = qcdr(v0194);
    v0007 = qcar(v0194);
    v0194 = elt(env, 1); /* !:rn!: */
    if (v0007 == v0194) goto v0035;
    v0194 = qvalue(elt(env, 2)); /* nil */
    goto v0014;

v0014:
    if (v0194 == nil) goto v0387;
    v0194 = v0008;
    v0194 = qcdr(v0194);
    v0194 = qcdr(v0194);
    v0194 = qcar(v0194);
    return onevalue(v0194);

v0387:
    v0194 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v0194);

v0035:
    v0194 = v0008;
    v0194 = qcdr(v0194);
    v0194 = qcdr(v0194);
    v0007 = qcdr(v0194);
    v0194 = (Lisp_Object)17; /* 1 */
    v0194 = (v0007 == v0194 ? lisp_true : nil);
    goto v0014;

v0051:
    v0194 = v0008;
    v0194 = qcdr(v0194);
    return onevalue(v0194);
}



/* Code for resetparser */

static Lisp_Object MS_CDECL CC_resetparser(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0036;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "resetparser");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for resetparser");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* end of prologue */
    v0036 = qvalue(elt(env, 1)); /* !*slin */
    if (v0036 == nil) goto v0027;
    v0036 = nil;
    return onevalue(v0036);

v0027:
    v0036 = qvalue(elt(env, 2)); /* t */
    {
        fn = elt(env, 3); /* comm1 */
        return (*qfn1(fn))(qenv(fn), v0036);
    }
}



/* Code for janettreefind */

static Lisp_Object CC_janettreefind(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0400, v0274;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for janettreefind");
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
    push(nil);
/* copy arguments values to proper place */
    stack[-4] = v0000;
/* end of prologue */
    v0400 = qvalue(elt(env, 1)); /* fluidbibasisjanettreerootnode */
    if (v0400 == nil) goto v0051;
    stack[-5] = nil;
    v0400 = qvalue(elt(env, 1)); /* fluidbibasisjanettreerootnode */
    stack[-3] = v0400;
    v0274 = stack[-4];
    v0400 = (Lisp_Object)1; /* 0 */
    v0400 = *(Lisp_Object *)((char *)v0274 + (CELL-TAG_VECTOR) + ((int32_t)v0400/(16/CELL)));
    stack[-2] = v0400;
    v0400 = (Lisp_Object)17; /* 1 */
    stack[-1] = v0400;
    goto v0010;

v0010:
    v0274 = stack[-2];
    v0400 = (Lisp_Object)1; /* 0 */
    if (!(((int32_t)(v0274)) > ((int32_t)(v0400)))) { Lisp_Object res = stack[-5]; popv(7); return onevalue(res); }

v0202:
    v0400 = stack[-3];
    v0400 = qcar(v0400);
    stack[0] = qcar(v0400);
    v0274 = stack[-4];
    v0400 = stack[-1];
    fn = elt(env, 3); /* monomgetvariabledegree */
    v0400 = (*qfn2(fn))(qenv(fn), v0274, v0400);
    nil = C_nil;
    if (exception_pending()) goto v0404;
    env = stack[-6];
    v0400 = (Lisp_Object)lessp2(stack[0], v0400);
    nil = C_nil;
    if (exception_pending()) goto v0404;
    v0400 = v0400 ? lisp_true : nil;
    env = stack[-6];
    if (v0400 == nil) goto v0255;
    v0400 = stack[-3];
    v0400 = qcdr(v0400);
    v0400 = qcar(v0400);
    if (v0400 == nil) goto v0255;
    v0400 = stack[-3];
    v0400 = qcdr(v0400);
    v0400 = qcar(v0400);
    stack[-3] = v0400;
    goto v0202;

v0255:
    v0400 = stack[-3];
    v0400 = qcar(v0400);
    stack[0] = qcar(v0400);
    v0274 = stack[-4];
    v0400 = stack[-1];
    fn = elt(env, 3); /* monomgetvariabledegree */
    v0400 = (*qfn2(fn))(qenv(fn), v0274, v0400);
    nil = C_nil;
    if (exception_pending()) goto v0404;
    env = stack[-6];
    if (equal(stack[0], v0400)) goto v0405;
    v0400 = (Lisp_Object)1; /* 0 */
    stack[-2] = v0400;
    goto v0010;

v0405:
    v0400 = stack[-3];
    v0400 = qcdr(v0400);
    v0400 = qcdr(v0400);
    if (v0400 == nil) goto v0284;
    stack[0] = stack[-2];
    v0274 = stack[-4];
    v0400 = stack[-1];
    fn = elt(env, 3); /* monomgetvariabledegree */
    v0400 = (*qfn2(fn))(qenv(fn), v0274, v0400);
    nil = C_nil;
    if (exception_pending()) goto v0404;
    env = stack[-6];
    v0400 = (Lisp_Object)(int32_t)((int32_t)stack[0] - (int32_t)v0400 + TAG_FIXNUM);
    stack[-2] = v0400;
    v0400 = stack[-1];
    v0400 = (Lisp_Object)((int32_t)(v0400) + 0x10);
    stack[-1] = v0400;
    v0400 = stack[-3];
    v0400 = qcdr(v0400);
    v0400 = qcdr(v0400);
    stack[-3] = v0400;
    goto v0010;

v0284:
    v0400 = (Lisp_Object)1; /* 0 */
    stack[-2] = v0400;
    v0400 = stack[-3];
    v0400 = qcar(v0400);
    v0400 = qcdr(v0400);
    stack[-5] = v0400;
    goto v0010;

v0051:
    v0400 = qvalue(elt(env, 2)); /* nil */
    { popv(7); return onevalue(v0400); }
/* error exit handlers */
v0404:
    popv(7);
    return nil;
}



/* Code for ibalp_atomp */

static Lisp_Object CC_ibalp_atomp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0279, v0384;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ibalp_atomp");
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
    v0384 = stack[0];
    v0279 = elt(env, 1); /* true */
    if (v0384 == v0279) goto v0036;
    v0384 = stack[0];
    v0279 = elt(env, 3); /* false */
    v0279 = (v0384 == v0279 ? lisp_true : nil);
    goto v0020;

v0020:
    if (v0279 == nil) goto v0010;
    v0279 = qvalue(elt(env, 2)); /* t */
    { popv(2); return onevalue(v0279); }

v0010:
    v0279 = stack[0];
    if (!consp(v0279)) goto v0280;
    v0279 = stack[0];
    v0279 = qcar(v0279);
    v0384 = v0279;
    goto v0046;

v0046:
    v0279 = elt(env, 4); /* equal */
    if (v0384 == v0279) goto v0030;
    v0279 = qvalue(elt(env, 5)); /* nil */
    { popv(2); return onevalue(v0279); }

v0030:
    v0279 = stack[0];
    fn = elt(env, 6); /* ibalp_arg2l */
    v0279 = (*qfn1(fn))(qenv(fn), v0279);
    nil = C_nil;
    if (exception_pending()) goto v0254;
    env = stack[-1];
    if (symbolp(v0279)) goto v0037;
    v0279 = qvalue(elt(env, 5)); /* nil */
    { popv(2); return onevalue(v0279); }

v0037:
    v0279 = stack[0];
    fn = elt(env, 7); /* ibalp_arg2r */
    v0279 = (*qfn1(fn))(qenv(fn), v0279);
    nil = C_nil;
    if (exception_pending()) goto v0254;
    v0279 = (is_number(v0279) ? lisp_true : nil);
    { popv(2); return onevalue(v0279); }

v0280:
    v0279 = stack[0];
    v0384 = v0279;
    goto v0046;

v0036:
    v0279 = qvalue(elt(env, 2)); /* t */
    goto v0020;
/* error exit handlers */
v0254:
    popv(2);
    return nil;
}



/* Code for ps!:minusp!: */

static Lisp_Object CC_psTminuspT(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object v0027;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ps:minusp:");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0027 = v0000;
/* end of prologue */
    v0027 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v0027);
}



/* Code for off */

static Lisp_Object CC_off(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0054;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for off");
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
    v0054 = v0000;
/* end of prologue */
    stack[0] = v0054;
    goto v0021;

v0021:
    v0054 = stack[0];
    if (v0054 == nil) goto v0053;
    v0054 = stack[0];
    v0054 = qcar(v0054);
    fn = elt(env, 2); /* off1 */
    v0054 = (*qfn1(fn))(qenv(fn), v0054);
    nil = C_nil;
    if (exception_pending()) goto v0044;
    env = stack[-1];
    v0054 = stack[0];
    v0054 = qcdr(v0054);
    stack[0] = v0054;
    goto v0021;

v0053:
    v0054 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v0054); }
/* error exit handlers */
v0044:
    popv(2);
    return nil;
}



/* Code for addpf */

static Lisp_Object CC_addpf(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0166, v0213, v0212;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for addpf");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0001;
    stack[-2] = v0000;
/* end of prologue */
    stack[0] = nil;
    goto v0032;

v0032:
    v0166 = stack[-2];
    if (v0166 == nil) goto v0014;
    v0166 = stack[-1];
    if (v0166 == nil) goto v0012;
    v0166 = stack[-2];
    v0166 = qcar(v0166);
    v0213 = qcar(v0166);
    v0166 = (Lisp_Object)17; /* 1 */
    if (v0213 == v0166) goto v0026;
    v0166 = stack[-1];
    v0166 = qcar(v0166);
    v0213 = qcar(v0166);
    v0166 = (Lisp_Object)17; /* 1 */
    if (v0213 == v0166) goto v0004;
    v0166 = stack[-2];
    v0166 = qcar(v0166);
    v0213 = qcar(v0166);
    v0166 = stack[-1];
    v0166 = qcar(v0166);
    v0166 = qcar(v0166);
    if (equal(v0213, v0166)) goto v0206;
    v0166 = stack[-2];
    v0166 = qcar(v0166);
    v0213 = qcar(v0166);
    v0166 = stack[-1];
    v0166 = qcar(v0166);
    v0166 = qcar(v0166);
    fn = elt(env, 1); /* ordop */
    v0166 = (*qfn2(fn))(qenv(fn), v0213, v0166);
    nil = C_nil;
    if (exception_pending()) goto v0412;
    env = stack[-4];
    if (v0166 == nil) goto v0273;
    v0166 = stack[-2];
    v0213 = qcar(v0166);
    v0166 = stack[0];
    v0166 = cons(v0213, v0166);
    nil = C_nil;
    if (exception_pending()) goto v0412;
    env = stack[-4];
    stack[0] = v0166;
    v0166 = stack[-2];
    v0166 = qcdr(v0166);
    stack[-2] = v0166;
    goto v0032;

v0273:
    v0166 = stack[-1];
    v0213 = qcar(v0166);
    v0166 = stack[0];
    v0166 = cons(v0213, v0166);
    nil = C_nil;
    if (exception_pending()) goto v0412;
    env = stack[-4];
    stack[0] = v0166;
    v0166 = stack[-1];
    v0166 = qcdr(v0166);
    stack[-1] = v0166;
    goto v0032;

v0206:
    stack[-3] = stack[0];
    v0166 = stack[-2];
    v0166 = qcar(v0166);
    v0213 = qcdr(v0166);
    v0166 = stack[-1];
    v0166 = qcar(v0166);
    v0166 = qcdr(v0166);
    fn = elt(env, 2); /* addsq */
    stack[0] = (*qfn2(fn))(qenv(fn), v0213, v0166);
    nil = C_nil;
    if (exception_pending()) goto v0412;
    env = stack[-4];
    v0166 = stack[-2];
    v0213 = qcdr(v0166);
    v0166 = stack[-1];
    v0166 = qcdr(v0166);
    v0166 = CC_addpf(env, v0213, v0166);
    nil = C_nil;
    if (exception_pending()) goto v0412;
    env = stack[-4];
    v0213 = stack[0];
    v0212 = v0213;
    v0212 = qcar(v0212);
    if (v0212 == nil) goto v0203;
    v0212 = stack[-2];
    v0212 = qcar(v0212);
    v0212 = qcar(v0212);
    v0166 = acons(v0212, v0213, v0166);
    nil = C_nil;
    if (exception_pending()) goto v0412;
    env = stack[-4];
    goto v0203;

v0203:
    {
        Lisp_Object v0272 = stack[-3];
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0272, v0166);
    }

v0004:
    v0213 = stack[-1];
    v0166 = stack[-2];
    fn = elt(env, 4); /* addmpf */
    v0166 = (*qfn2(fn))(qenv(fn), v0213, v0166);
    nil = C_nil;
    if (exception_pending()) goto v0412;
    env = stack[-4];
    {
        Lisp_Object v0170 = stack[0];
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0170, v0166);
    }

v0026:
    v0213 = stack[-2];
    v0166 = stack[-1];
    fn = elt(env, 4); /* addmpf */
    v0166 = (*qfn2(fn))(qenv(fn), v0213, v0166);
    nil = C_nil;
    if (exception_pending()) goto v0412;
    env = stack[-4];
    {
        Lisp_Object v0169 = stack[0];
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0169, v0166);
    }

v0012:
    v0213 = stack[0];
    v0166 = stack[-2];
    {
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0213, v0166);
    }

v0014:
    v0213 = stack[0];
    v0166 = stack[-1];
    {
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0213, v0166);
    }
/* error exit handlers */
v0412:
    popv(5);
    return nil;
}



/* Code for cut!:ep */

static Lisp_Object CC_cutTep(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0022, v0383;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for cut:ep");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0001;
    stack[-2] = v0000;
/* end of prologue */
    v0383 = stack[-2];
    v0022 = elt(env, 1); /* !:rd!: */
    if (!consp(v0383)) goto v0024;
    v0383 = qcar(v0383);
    if (!(v0383 == v0022)) goto v0024;
    v0022 = stack[-2];
    v0022 = qcdr(v0022);
    v0022 = (consp(v0022) ? nil : lisp_true);
    v0022 = (v0022 == nil ? lisp_true : nil);
    goto v0013;

v0013:
    if (v0022 == nil) goto v0042;
    v0022 = stack[-1];
    v0022 = integerp(v0022);
    goto v0036;

v0036:
    if (v0022 == nil) goto v0018;
    v0383 = stack[-1];
    v0022 = stack[-2];
    v0022 = qcdr(v0022);
    v0022 = qcdr(v0022);
    v0383 = difference2(v0383, v0022);
    nil = C_nil;
    if (exception_pending()) goto v0278;
    env = stack[-4];
    stack[-1] = v0383;
    v0022 = (Lisp_Object)1; /* 0 */
    v0022 = (Lisp_Object)lesseq2(v0383, v0022);
    nil = C_nil;
    if (exception_pending()) goto v0278;
    v0022 = v0022 ? lisp_true : nil;
    env = stack[-4];
    if (!(v0022 == nil)) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    stack[-3] = elt(env, 1); /* !:rd!: */
    v0022 = stack[-2];
    v0022 = qcdr(v0022);
    stack[0] = qcar(v0022);
    v0022 = stack[-1];
    v0022 = negate(v0022);
    nil = C_nil;
    if (exception_pending()) goto v0278;
    env = stack[-4];
    fn = elt(env, 3); /* ashift */
    stack[0] = (*qfn2(fn))(qenv(fn), stack[0], v0022);
    nil = C_nil;
    if (exception_pending()) goto v0278;
    env = stack[-4];
    v0022 = stack[-2];
    v0022 = qcdr(v0022);
    v0383 = qcdr(v0022);
    v0022 = stack[-1];
    v0022 = plus2(v0383, v0022);
    nil = C_nil;
    if (exception_pending()) goto v0278;
    {
        Lisp_Object v0203 = stack[-3];
        Lisp_Object v0413 = stack[0];
        popv(5);
        return list2star(v0203, v0413, v0022);
    }

v0018:
    v0022 = elt(env, 0); /* cut!:ep */
    {
        popv(5);
        fn = elt(env, 4); /* bflerrmsg */
        return (*qfn1(fn))(qenv(fn), v0022);
    }

v0042:
    v0022 = qvalue(elt(env, 2)); /* nil */
    goto v0036;

v0024:
    v0022 = qvalue(elt(env, 2)); /* nil */
    goto v0013;
/* error exit handlers */
v0278:
    popv(5);
    return nil;
}



/* Code for contr1!-strand */

static Lisp_Object CC_contr1Kstrand(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0039, v0040, v0050, v0054;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for contr1-strand");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0039 = v0001;
    v0040 = v0000;
/* end of prologue */
    v0054 = v0040;
    v0050 = v0039;
    v0040 = qvalue(elt(env, 1)); /* nil */
    v0039 = qvalue(elt(env, 1)); /* nil */
    {
        fn = elt(env, 2); /* contr2!-strand */
        return (*qfnn(fn))(qenv(fn), 4, v0054, v0050, v0040, v0039);
    }
}



/* Code for multop */

static Lisp_Object CC_multop(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0358, v0194, v0007;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for multop");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v0001;
    v0007 = v0000;
/* end of prologue */
    v0358 = qvalue(elt(env, 1)); /* kord!* */
    if (v0358 == nil) goto v0038;
    v0358 = v0007;
    v0194 = qcar(v0358);
    v0358 = elt(env, 2); /* k!* */
    if (v0194 == v0358) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v0194 = v0007;
    v0358 = stack[0];
    {
        popv(2);
        fn = elt(env, 3); /* rmultpf */
        return (*qfn2(fn))(qenv(fn), v0194, v0358);
    }

v0038:
    v0194 = v0007;
    v0358 = (Lisp_Object)17; /* 1 */
    v0358 = cons(v0194, v0358);
    nil = C_nil;
    if (exception_pending()) goto v0385;
    env = stack[-1];
    v0194 = ncons(v0358);
    nil = C_nil;
    if (exception_pending()) goto v0385;
    env = stack[-1];
    v0358 = stack[0];
    {
        popv(2);
        fn = elt(env, 4); /* multf */
        return (*qfn2(fn))(qenv(fn), v0194, v0358);
    }
/* error exit handlers */
v0385:
    popv(2);
    return nil;
}



/* Code for red_divtest */

static Lisp_Object CC_red_divtest(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0041, v0042;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for red_divtest");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0001;
    stack[-1] = v0000;
/* end of prologue */

v0021:
    v0041 = stack[-1];
    if (v0041 == nil) goto v0036;
    v0041 = stack[-1];
    v0041 = qcar(v0041);
    fn = elt(env, 2); /* bas_dpoly */
    v0041 = (*qfn1(fn))(qenv(fn), v0041);
    nil = C_nil;
    if (exception_pending()) goto v0010;
    env = stack[-2];
    fn = elt(env, 3); /* dp_lmon */
    v0042 = (*qfn1(fn))(qenv(fn), v0041);
    nil = C_nil;
    if (exception_pending()) goto v0010;
    env = stack[-2];
    v0041 = stack[0];
    fn = elt(env, 4); /* mo_vdivides!? */
    v0041 = (*qfn2(fn))(qenv(fn), v0042, v0041);
    nil = C_nil;
    if (exception_pending()) goto v0010;
    env = stack[-2];
    if (v0041 == nil) goto v0024;
    v0041 = stack[-1];
    v0041 = qcar(v0041);
    { popv(3); return onevalue(v0041); }

v0024:
    v0041 = stack[-1];
    v0041 = qcdr(v0041);
    stack[-1] = v0041;
    goto v0021;

v0036:
    v0041 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v0041); }
/* error exit handlers */
v0010:
    popv(3);
    return nil;
}



/* Code for ra_budancount */

static Lisp_Object MS_CDECL CC_ra_budancount(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0038, v0039, v0040;
    Lisp_Object fn;
    Lisp_Object v0028, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "ra_budancount");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0001 = va_arg(aa, Lisp_Object);
    v0028 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ra_budancount");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0028,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0028);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v0038 = v0028;
    v0039 = v0001;
    v0040 = v0000;
/* end of prologue */
    fn = elt(env, 1); /* ra_transform */
    v0038 = (*qfnn(fn))(qenv(fn), 3, v0040, v0039, v0038);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* ra_budan!-0!-1 */
        return (*qfn1(fn))(qenv(fn), v0038);
    }
/* error exit handlers */
v0050:
    popv(1);
    return nil;
}



/* Code for lalr_prin_symbol */

static Lisp_Object CC_lalr_prin_symbol(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0255, v0260, v0414;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for lalr_prin_symbol");
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
    v0260 = v0000;
/* end of prologue */
    v0414 = v0260;
    v0255 = (Lisp_Object)1; /* 0 */
    if (v0414 == v0255) goto v0020;
    v0255 = v0260;
    if (v0255 == nil) goto v0040;
    v0414 = v0260;
    v0255 = elt(env, 3); /* !. */
    if (v0414 == v0255) goto v0011;
    v0255 = v0260;
    if (!(is_number(v0255))) goto v0010;
    v0414 = v0260;
    v0255 = qvalue(elt(env, 5)); /* lex_codename */
    v0255 = Lassoc(nil, v0414, v0255);
    stack[0] = v0255;
    if (v0255 == nil) goto v0010;
    v0255 = elt(env, 6); /* !" */
    v0255 = Lprinc(nil, v0255);
    nil = C_nil;
    if (exception_pending()) goto v0016;
    env = stack[-1];
    v0255 = stack[0];
    v0255 = qcdr(v0255);
    v0255 = Lprinc(nil, v0255);
    nil = C_nil;
    if (exception_pending()) goto v0016;
    env = stack[-1];
    v0255 = elt(env, 6); /* !" */
    v0255 = Lprinc(nil, v0255);
    nil = C_nil;
    if (exception_pending()) goto v0016;
    goto v0032;

v0032:
    v0255 = nil;
    { popv(2); return onevalue(v0255); }

v0010:
    v0255 = v0260;
    v0255 = Lstringp(nil, v0255);
    env = stack[-1];
    if (v0255 == nil) goto v0189;
    v0255 = v0260;
    v0255 = Lprin(nil, v0255);
    nil = C_nil;
    if (exception_pending()) goto v0016;
    goto v0032;

v0189:
    v0255 = v0260;
    fn = elt(env, 8); /* explode2uc */
    v0255 = (*qfn1(fn))(qenv(fn), v0255);
    nil = C_nil;
    if (exception_pending()) goto v0016;
    env = stack[-1];
    stack[0] = v0255;
    goto v0006;

v0006:
    v0255 = stack[0];
    if (v0255 == nil) goto v0032;
    v0255 = stack[0];
    v0255 = qcar(v0255);
    v0255 = Lprinc(nil, v0255);
    nil = C_nil;
    if (exception_pending()) goto v0016;
    env = stack[-1];
    v0255 = stack[0];
    v0255 = qcdr(v0255);
    stack[0] = v0255;
    goto v0006;

v0011:
    v0255 = elt(env, 4); /* "." */
    v0255 = Lprinc(nil, v0255);
    nil = C_nil;
    if (exception_pending()) goto v0016;
    goto v0032;

v0040:
    v0255 = elt(env, 2); /* "<empty>" */
    v0255 = Lprinc(nil, v0255);
    nil = C_nil;
    if (exception_pending()) goto v0016;
    goto v0032;

v0020:
    v0255 = elt(env, 1); /* "$" */
    v0255 = Lprinc(nil, v0255);
    nil = C_nil;
    if (exception_pending()) goto v0016;
    goto v0032;
/* error exit handlers */
v0016:
    popv(2);
    return nil;
}



/* Code for undefdchk */

static Lisp_Object CC_undefdchk(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0044, v0011, v0012;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for undefdchk");
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
    v0011 = v0000;
/* end of prologue */
    v0012 = v0011;
    v0044 = elt(env, 1); /* defd */
    v0044 = Lflagp(nil, v0012, v0044);
    env = stack[0];
    if (v0044 == nil) goto v0039;
    v0044 = nil;
    { popv(1); return onevalue(v0044); }

v0039:
    v0044 = qvalue(elt(env, 2)); /* undefns!* */
    v0044 = cons(v0011, v0044);
    nil = C_nil;
    if (exception_pending()) goto v0035;
    env = stack[0];
    qvalue(elt(env, 2)) = v0044; /* undefns!* */
    { popv(1); return onevalue(v0044); }
/* error exit handlers */
v0035:
    popv(1);
    return nil;
}



/* Code for monommultiplybyvariable */

static Lisp_Object CC_monommultiplybyvariable(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0206, v0204;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for monommultiplybyvariable");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0001;
    stack[-2] = v0000;
/* end of prologue */
    v0204 = stack[-2];
    v0206 = (Lisp_Object)17; /* 1 */
    v0206 = *(Lisp_Object *)((char *)v0204 + (CELL-TAG_VECTOR) + ((int32_t)v0206/(16/CELL)));
    stack[-3] = v0206;
    goto v0038;

v0038:
    v0206 = stack[-3];
    v0206 = qcar(v0206);
    if (v0206 == nil) goto v0033;
    v0206 = stack[-3];
    v0204 = qcar(v0206);
    v0206 = stack[-1];
    v0206 = (Lisp_Object)greaterp2(v0204, v0206);
    nil = C_nil;
    if (exception_pending()) goto v0257;
    v0206 = v0206 ? lisp_true : nil;
    env = stack[-4];
    if (v0206 == nil) goto v0033;
    v0206 = stack[-3];
    v0206 = qcdr(v0206);
    stack[-3] = v0206;
    goto v0038;

v0033:
    v0206 = stack[-3];
    v0206 = qcar(v0206);
    if (v0206 == nil) goto v0059;
    v0206 = stack[-3];
    v0204 = qcar(v0206);
    v0206 = stack[-1];
    if (!(equal(v0204, v0206))) goto v0059;

v0195:
    v0206 = nil;
    { popv(5); return onevalue(v0206); }

v0059:
    stack[0] = stack[-3];
    v0206 = stack[-3];
    v0204 = qcar(v0206);
    v0206 = stack[-3];
    v0206 = qcdr(v0206);
    v0206 = cons(v0204, v0206);
    nil = C_nil;
    if (exception_pending()) goto v0257;
    env = stack[-4];
    v0204 = Lrplacd(nil, stack[0], v0206);
    nil = C_nil;
    if (exception_pending()) goto v0257;
    env = stack[-4];
    v0206 = stack[-1];
    v0206 = Lrplaca(nil, v0204, v0206);
    nil = C_nil;
    if (exception_pending()) goto v0257;
    env = stack[-4];
    stack[-1] = stack[-2];
    stack[0] = (Lisp_Object)1; /* 0 */
    v0204 = stack[-2];
    v0206 = (Lisp_Object)1; /* 0 */
    v0206 = *(Lisp_Object *)((char *)v0204 + (CELL-TAG_VECTOR) + ((int32_t)v0206/(16/CELL)));
    v0206 = add1(v0206);
    nil = C_nil;
    if (exception_pending()) goto v0257;
    *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)stack[0]/(16/CELL))) = v0206;
    goto v0195;
/* error exit handlers */
v0257:
    popv(5);
    return nil;
}



/* Code for cl_varl1 */

static Lisp_Object CC_cl_varl1(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0038, v0039, v0040, v0050;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for cl_varl1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0038 = v0000;
/* end of prologue */
    v0050 = v0038;
    v0040 = qvalue(elt(env, 1)); /* nil */
    v0039 = qvalue(elt(env, 1)); /* nil */
    v0038 = qvalue(elt(env, 1)); /* nil */
    {
        fn = elt(env, 2); /* cl_varl2 */
        return (*qfnn(fn))(qenv(fn), 4, v0050, v0040, v0039, v0038);
    }
}



/* Code for qqe_number!-of!-tails!-in!-qterm */

static Lisp_Object CC_qqe_numberKofKtailsKinKqterm(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0029, v0041;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for qqe_number-of-tails-in-qterm");
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

v0051:
    v0029 = stack[0];
    if (!consp(v0029)) goto v0020;
    v0029 = stack[0];
    fn = elt(env, 2); /* qqe_op */
    v0041 = (*qfn1(fn))(qenv(fn), v0029);
    nil = C_nil;
    if (exception_pending()) goto v0030;
    env = stack[-1];
    v0029 = elt(env, 1); /* (ladd radd) */
    v0029 = Lmemq(nil, v0041, v0029);
    if (v0029 == nil) goto v0012;
    v0029 = stack[0];
    fn = elt(env, 3); /* qqe_arg2r */
    v0029 = (*qfn1(fn))(qenv(fn), v0029);
    nil = C_nil;
    if (exception_pending()) goto v0030;
    env = stack[-1];
    stack[0] = v0029;
    goto v0051;

v0012:
    v0029 = stack[0];
    fn = elt(env, 4); /* qqe_arg2l */
    v0029 = (*qfn1(fn))(qenv(fn), v0029);
    nil = C_nil;
    if (exception_pending()) goto v0030;
    env = stack[-1];
    v0029 = CC_qqe_numberKofKtailsKinKqterm(env, v0029);
    nil = C_nil;
    if (exception_pending()) goto v0030;
    popv(2);
    return add1(v0029);

v0020:
    v0029 = (Lisp_Object)1; /* 0 */
    { popv(2); return onevalue(v0029); }
/* error exit handlers */
v0030:
    popv(2);
    return nil;
}



/* Code for quotfx */

static Lisp_Object CC_quotfx(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0010, v0043, v0046;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for quotfx");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0043 = v0001;
    v0046 = v0000;
/* end of prologue */
    v0010 = qvalue(elt(env, 1)); /* !*exp */
    if (v0010 == nil) goto v0053;
    v0010 = qvalue(elt(env, 3)); /* !*mcd */
    v0010 = (v0010 == nil ? lisp_true : nil);
    goto v0036;

v0036:
    if (v0010 == nil) goto v0049;
    v0010 = v0046;
    {
        fn = elt(env, 4); /* quotf */
        return (*qfn2(fn))(qenv(fn), v0010, v0043);
    }

v0049:
    v0010 = v0046;
    {
        fn = elt(env, 5); /* quotfx1 */
        return (*qfn2(fn))(qenv(fn), v0010, v0043);
    }

v0053:
    v0010 = qvalue(elt(env, 2)); /* t */
    goto v0036;
}



/* Code for ibalp_vmember */

static Lisp_Object CC_ibalp_vmember(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0042, v0030;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ibalp_vmember");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0001;
    stack[-1] = v0000;
/* end of prologue */

v0295:
    v0042 = stack[0];
    if (v0042 == nil) goto v0021;
    v0030 = stack[-1];
    v0042 = stack[0];
    v0042 = qcar(v0042);
    fn = elt(env, 2); /* ibalp_vequal */
    v0042 = (*qfn2(fn))(qenv(fn), v0030, v0042);
    nil = C_nil;
    if (exception_pending()) goto v0043;
    env = stack[-2];
    if (!(v0042 == nil)) { popv(3); return onevalue(v0042); }
    v0030 = stack[-1];
    v0042 = stack[0];
    v0042 = qcdr(v0042);
    stack[-1] = v0030;
    stack[0] = v0042;
    goto v0295;

v0021:
    v0042 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v0042); }
/* error exit handlers */
v0043:
    popv(3);
    return nil;
}



/* Code for basicom */

static Lisp_Object CC_basicom(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0029;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for basicom");
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
    v0029 = stack[0];
    if (is_number(v0029)) goto v0032;
    v0029 = stack[0];
    if (!(symbolp(v0029))) goto v0021;
    v0029 = stack[0];
    fn = elt(env, 1); /* variableom */
    v0029 = (*qfn1(fn))(qenv(fn), v0029);
    nil = C_nil;
    if (exception_pending()) goto v0042;
    goto v0021;

v0021:
    v0029 = nil;
    { popv(2); return onevalue(v0029); }

v0032:
    v0029 = stack[0];
    v0029 = integerp(v0029);
    if (v0029 == nil) goto v0056;
    v0029 = stack[0];
    fn = elt(env, 2); /* integerom */
    v0029 = (*qfn1(fn))(qenv(fn), v0029);
    nil = C_nil;
    if (exception_pending()) goto v0042;
    env = stack[-1];
    goto v0056;

v0056:
    v0029 = stack[0];
    v0029 = Lfloatp(nil, v0029);
    env = stack[-1];
    if (v0029 == nil) goto v0021;
    v0029 = stack[0];
    fn = elt(env, 3); /* floatom */
    v0029 = (*qfn1(fn))(qenv(fn), v0029);
    nil = C_nil;
    if (exception_pending()) goto v0042;
    goto v0021;
/* error exit handlers */
v0042:
    popv(2);
    return nil;
}



setup_type const u10_setup[] =
{
    {"totalcompare",            too_few_2,      CC_totalcompare,wrong_no_2},
    {"searchpl",                CC_searchpl,    too_many_1,    wrong_no_1},
    {"rl_gettype",              CC_rl_gettype,  too_many_1,    wrong_no_1},
    {"omair",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_omair},
    {"off_mod_reval",           CC_off_mod_reval,too_many_1,   wrong_no_1},
    {"mkuwedge",                CC_mkuwedge,    too_many_1,    wrong_no_1},
    {"carx",                    too_few_2,      CC_carx,       wrong_no_2},
    {"has_parents",             CC_has_parents, too_many_1,    wrong_no_1},
    {"take-impart",             CC_takeKimpart, too_many_1,    wrong_no_1},
    {"lprim",                   CC_lprim,       too_many_1,    wrong_no_1},
    {"red_better",              too_few_2,      CC_red_better, wrong_no_2},
    {"ord",                     CC_ord,         too_many_1,    wrong_no_1},
    {"reduce-mod-p",            CC_reduceKmodKp,too_many_1,    wrong_no_1},
    {"scan",                    wrong_no_na,    wrong_no_nb,   (n_args *)CC_scan},
    {"mri_2pasfat",             CC_mri_2pasfat, too_many_1,    wrong_no_1},
    {"vdp_poly",                CC_vdp_poly,    too_many_1,    wrong_no_1},
    {"expression",              CC_expression,  too_many_1,    wrong_no_1},
    {"spmultm2",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_spmultm2},
    {"exchk2",                  too_few_2,      CC_exchk2,     wrong_no_2},
    {"covposp",                 CC_covposp,     too_many_1,    wrong_no_1},
    {"statep*",                 CC_statepH,     too_many_1,    wrong_no_1},
    {"form1",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_form1},
    {"mv-domainlist--",         too_few_2,      CC_mvKdomainlistKK,wrong_no_2},
    {"sc_kern",                 CC_sc_kern,     too_many_1,    wrong_no_1},
    {"primep",                  CC_primep,      too_many_1,    wrong_no_1},
    {"mapcons",                 too_few_2,      CC_mapcons,    wrong_no_2},
    {"gcref_mknode-tgf",        CC_gcref_mknodeKtgf,too_many_1,wrong_no_1},
    {"polynomlistfinddivisor",  wrong_no_na,    wrong_no_nb,   (n_args *)CC_polynomlistfinddivisor},
    {"diffp1",                  too_few_2,      CC_diffp1,     wrong_no_2},
    {"revv0",                   too_few_2,      CC_revv0,      wrong_no_2},
    {"ibalp_litp",              CC_ibalp_litp,  too_many_1,    wrong_no_1},
    {"on",                      CC_on,          too_many_1,    wrong_no_1},
    {"vdpgetprop",              too_few_2,      CC_vdpgetprop, wrong_no_2},
    {"xord_lex",                too_few_2,      CC_xord_lex,   wrong_no_2},
    {"convertmode1",            wrong_no_na,    wrong_no_nb,   (n_args *)CC_convertmode1},
    {"formop",                  CC_formop,      too_many_1,    wrong_no_1},
    {"leftzeros",               CC_leftzeros,   too_many_1,    wrong_no_1},
    {"*id2num",                 CC_Hid2num,     too_many_1,    wrong_no_1},
    {"arintequiv:",             CC_arintequivT, too_many_1,    wrong_no_1},
    {"resetparser",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_resetparser},
    {"janettreefind",           CC_janettreefind,too_many_1,   wrong_no_1},
    {"ibalp_atomp",             CC_ibalp_atomp, too_many_1,    wrong_no_1},
    {"ps:minusp:",              CC_psTminuspT,  too_many_1,    wrong_no_1},
    {"off",                     CC_off,         too_many_1,    wrong_no_1},
    {"addpf",                   too_few_2,      CC_addpf,      wrong_no_2},
    {"cut:ep",                  too_few_2,      CC_cutTep,     wrong_no_2},
    {"contr1-strand",           too_few_2,      CC_contr1Kstrand,wrong_no_2},
    {"multop",                  too_few_2,      CC_multop,     wrong_no_2},
    {"red_divtest",             too_few_2,      CC_red_divtest,wrong_no_2},
    {"ra_budancount",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_ra_budancount},
    {"lalr_prin_symbol",        CC_lalr_prin_symbol,too_many_1,wrong_no_1},
    {"undefdchk",               CC_undefdchk,   too_many_1,    wrong_no_1},
    {"monommultiplybyvariable", too_few_2,      CC_monommultiplybyvariable,wrong_no_2},
    {"cl_varl1",                CC_cl_varl1,    too_many_1,    wrong_no_1},
    {"qqe_number-of-tails-in-qterm",CC_qqe_numberKofKtailsKinKqterm,too_many_1,wrong_no_1},
    {"quotfx",                  too_few_2,      CC_quotfx,     wrong_no_2},
    {"ibalp_vmember",           too_few_2,      CC_ibalp_vmember,wrong_no_2},
    {"basicom",                 CC_basicom,     too_many_1,    wrong_no_1},
    {NULL, (one_args *)"u10", (two_args *)"17096 5186644 2002911", 0}
};

/* end of generated code */
