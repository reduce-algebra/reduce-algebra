
/* $destdir/u05.c        Machine generated C code */

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


/* Code for prin2!* */

static Lisp_Object CC_prin2H(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0030, v0031, v0032;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for prin2*");
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
    v0030 = qvalue(elt(env, 1)); /* !*utf8 */
    if (v0030 == nil) goto v0033;
    v0030 = stack[-2];
    {
        popv(5);
        fn = elt(env, 16); /* utf8_prin2!* */
        return (*qfn1(fn))(qenv(fn), v0030);
    }

v0033:
    v0030 = qvalue(elt(env, 2)); /* outputhandler!* */
    if (v0030 == nil) goto v0034;
    v0031 = qvalue(elt(env, 2)); /* outputhandler!* */
    v0032 = elt(env, 0); /* prin2!* */
    v0030 = stack[-2];
        popv(5);
        return Lapply2(nil, 3, v0031, v0032, v0030);

v0034:
    v0030 = stack[-2];
    if (!symbolp(v0030)) v0030 = nil;
    else { v0030 = qfastgets(v0030);
           if (v0030 != nil) { v0030 = elt(v0030, 12); /* oldnam */
#ifdef RECORD_GET
             if (v0030 != SPID_NOPROP)
                record_get(elt(fastget_names, 12), 1);
             else record_get(elt(fastget_names, 12), 0),
                v0030 = nil; }
           else record_get(elt(fastget_names, 12), 0); }
#else
             if (v0030 == SPID_NOPROP) v0030 = nil; }}
#endif
    v0031 = v0030;
    if (v0030 == nil) goto v0035;
    v0030 = v0031;
    stack[-2] = v0030;
    goto v0035;

v0035:
    v0030 = qvalue(elt(env, 3)); /* overflowed!* */
    if (v0030 == nil) goto v0036;
    v0030 = elt(env, 4); /* overflowed */
    { popv(5); return onevalue(v0030); }

v0036:
    v0030 = qvalue(elt(env, 5)); /* !*fort */
    if (v0030 == nil) goto v0037;
    v0030 = stack[-2];
    {
        popv(5);
        fn = elt(env, 17); /* fprin2!* */
        return (*qfn1(fn))(qenv(fn), v0030);
    }

v0037:
    v0030 = qvalue(elt(env, 6)); /* !*nat */
    if (v0030 == nil) goto v0038;
    v0031 = stack[-2];
    v0030 = elt(env, 7); /* pi */
    if (v0031 == v0030) goto v0039;
    v0031 = stack[-2];
    v0030 = elt(env, 9); /* infinity */
    if (!(v0031 == v0030)) goto v0038;
    v0030 = elt(env, 9); /* infinity */
    fn = elt(env, 18); /* symbol */
    v0030 = (*qfn1(fn))(qenv(fn), v0030);
    nil = C_nil;
    if (exception_pending()) goto v0040;
    env = stack[-4];
    stack[-2] = v0030;
    goto v0038;

v0038:
    v0030 = stack[-2];
    fn = elt(env, 19); /* widelengthc */
    v0030 = (*qfn1(fn))(qenv(fn), v0030);
    nil = C_nil;
    if (exception_pending()) goto v0040;
    env = stack[-4];
    stack[-1] = v0030;
    v0030 = stack[-2];
    v0030 = integerp(v0030);
    if (v0030 == nil) goto v0041;
    v0031 = stack[-1];
    v0030 = (Lisp_Object)801; /* 50 */
    v0030 = (Lisp_Object)greaterp2(v0031, v0030);
    nil = C_nil;
    if (exception_pending()) goto v0040;
    v0030 = v0030 ? lisp_true : nil;
    env = stack[-4];
    if (v0030 == nil) goto v0041;
    v0030 = qvalue(elt(env, 10)); /* !*rounded */
    if (v0030 == nil) goto v0041;
    v0030 = stack[-2];
    fn = elt(env, 20); /* i2rd!* */
    v0030 = (*qfn1(fn))(qenv(fn), v0030);
    nil = C_nil;
    if (exception_pending()) goto v0040;
    env = stack[-4];
    {
        popv(5);
        fn = elt(env, 21); /* rd!:prin */
        return (*qfn1(fn))(qenv(fn), v0030);
    }

v0041:
    v0031 = qvalue(elt(env, 11)); /* posn!* */
    v0030 = stack[-1];
    v0030 = (Lisp_Object)(int32_t)((int32_t)v0031 + (int32_t)v0030 - TAG_FIXNUM);
    stack[-3] = v0030;
    v0030 = qvalue(elt(env, 12)); /* nil */
    v0031 = Llinelength(nil, v0030);
    nil = C_nil;
    if (exception_pending()) goto v0040;
    env = stack[-4];
    v0030 = qvalue(elt(env, 13)); /* spare!* */
    v0030 = difference2(v0031, v0030);
    nil = C_nil;
    if (exception_pending()) goto v0040;
    env = stack[-4];
    stack[0] = v0030;
    v0031 = stack[-3];
    v0030 = stack[0];
    v0030 = (Lisp_Object)lesseq2(v0031, v0030);
    nil = C_nil;
    if (exception_pending()) goto v0040;
    v0030 = v0030 ? lisp_true : nil;
    env = stack[-4];
    if (!(v0030 == nil)) goto v0042;
    v0030 = qvalue(elt(env, 14)); /* testing!-width!* */
    if (v0030 == nil) goto v0043;
    v0030 = qvalue(elt(env, 12)); /* nil */
    goto v0044;

v0044:
    if (!(v0030 == nil)) goto v0042;
    v0030 = qvalue(elt(env, 14)); /* testing!-width!* */
    if (v0030 == nil) goto v0045;
    v0030 = qvalue(elt(env, 15)); /* t */
    qvalue(elt(env, 3)) = v0030; /* overflowed!* */
    v0030 = elt(env, 4); /* overflowed */
    { popv(5); return onevalue(v0030); }

v0045:
    v0032 = stack[-2];
    v0030 = qvalue(elt(env, 11)); /* posn!* */
    v0031 = (Lisp_Object)((int32_t)(v0030) + 0x10);
    v0030 = stack[0];
    v0030 = (Lisp_Object)((int32_t)(v0030) - 0x10);
    {
        popv(5);
        fn = elt(env, 22); /* prin2lint */
        return (*qfnn(fn))(qenv(fn), 3, v0032, v0031, v0030);
    }

v0042:
    v0031 = stack[-2];
    v0030 = stack[-3];
    {
        popv(5);
        fn = elt(env, 23); /* add_prin_char */
        return (*qfn2(fn))(qenv(fn), v0031, v0030);
    }

v0043:
    v0030 = stack[-2];
    v0030 = integerp(v0030);
    if (!(v0030 == nil)) goto v0046;
    v0030 = qvalue(elt(env, 15)); /* t */
    fn = elt(env, 24); /* terpri!* */
    v0030 = (*qfn1(fn))(qenv(fn), v0030);
    nil = C_nil;
    if (exception_pending()) goto v0040;
    env = stack[-4];
    goto v0046;

v0046:
    v0031 = qvalue(elt(env, 11)); /* posn!* */
    v0030 = stack[-1];
    v0031 = (Lisp_Object)(int32_t)((int32_t)v0031 + (int32_t)v0030 - TAG_FIXNUM);
    stack[-3] = v0031;
    v0030 = stack[0];
    v0030 = (Lisp_Object)lesseq2(v0031, v0030);
    nil = C_nil;
    if (exception_pending()) goto v0040;
    v0030 = v0030 ? lisp_true : nil;
    env = stack[-4];
    goto v0044;

v0039:
    v0030 = elt(env, 8); /* !.pi */
    fn = elt(env, 18); /* symbol */
    v0030 = (*qfn1(fn))(qenv(fn), v0030);
    nil = C_nil;
    if (exception_pending()) goto v0040;
    env = stack[-4];
    stack[-2] = v0030;
    goto v0038;
/* error exit handlers */
v0040:
    popv(5);
    return nil;
}



/* Code for insert_pv */

static Lisp_Object CC_insert_pv(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0047)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0053, v0054, v0055;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for insert_pv");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0047,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0047);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v0047;
    v0053 = v0000;
/* end of prologue */
    v0054 = v0053;
    v0053 = stack[0];
    fn = elt(env, 2); /* sieve_pv */
    v0053 = (*qfn2(fn))(qenv(fn), v0054, v0053);
    nil = C_nil;
    if (exception_pending()) goto v0056;
    env = stack[-1];
    v0054 = v0053;
    v0053 = v0054;
    if (v0053 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v0053 = v0054;
    fn = elt(env, 3); /* pv_renorm */
    v0055 = (*qfn1(fn))(qenv(fn), v0053);
    nil = C_nil;
    if (exception_pending()) goto v0056;
    env = stack[-1];
    v0054 = stack[0];
    v0053 = qvalue(elt(env, 1)); /* nil */
    {
        popv(2);
        fn = elt(env, 4); /* insert_pv1 */
        return (*qfnn(fn))(qenv(fn), 3, v0055, v0054, v0053);
    }
/* error exit handlers */
v0056:
    popv(2);
    return nil;
}



/* Code for rntimes!: */

static Lisp_Object CC_rntimesT(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0047)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0054, v0055;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rntimes:");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0047,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0047);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0047;
    stack[-1] = v0000;
/* end of prologue */
    v0054 = stack[-1];
    v0054 = qcdr(v0054);
    v0055 = qcar(v0054);
    v0054 = stack[0];
    v0054 = qcdr(v0054);
    v0054 = qcar(v0054);
    stack[-2] = times2(v0055, v0054);
    nil = C_nil;
    if (exception_pending()) goto v0059;
    env = stack[-3];
    v0054 = stack[-1];
    v0054 = qcdr(v0054);
    v0055 = qcdr(v0054);
    v0054 = stack[0];
    v0054 = qcdr(v0054);
    v0054 = qcdr(v0054);
    v0054 = times2(v0055, v0054);
    nil = C_nil;
    if (exception_pending()) goto v0059;
    env = stack[-3];
    {
        Lisp_Object v0060 = stack[-2];
        popv(4);
        fn = elt(env, 1); /* mkrn */
        return (*qfn2(fn))(qenv(fn), v0060, v0054);
    }
/* error exit handlers */
v0059:
    popv(4);
    return nil;
}



/* Code for modplus!: */

static Lisp_Object CC_modplusT(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0047)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0062, v0063;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for modplus:");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0047,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0047);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v0062 = v0047;
    v0063 = v0000;
/* end of prologue */
    v0063 = qcdr(v0063);
    v0062 = qcdr(v0062);
    fn = elt(env, 1); /* general!-modular!-plus */
    v0062 = (*qfn2(fn))(qenv(fn), v0063, v0062);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* !*modular2f */
        return (*qfn1(fn))(qenv(fn), v0062);
    }
/* error exit handlers */
v0064:
    popv(1);
    return nil;
}



/* Code for noncomdel */

static Lisp_Object CC_noncomdel(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0047)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0004, v0026;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for noncomdel");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0047,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0047);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0047;
    stack[-1] = v0000;
/* end of prologue */
    v0004 = stack[-1];
    fn = elt(env, 1); /* noncomp!* */
    v0004 = (*qfn1(fn))(qenv(fn), v0004);
    nil = C_nil;
    if (exception_pending()) goto v0049;
    env = stack[-2];
    if (v0004 == nil) goto v0052;
    v0026 = stack[-1];
    v0004 = stack[0];
    {
        popv(3);
        fn = elt(env, 2); /* noncomdel1 */
        return (*qfn2(fn))(qenv(fn), v0026, v0004);
    }

v0052:
    v0026 = stack[-1];
    v0004 = stack[0];
        popv(3);
        return Ldelete(nil, v0026, v0004);
/* error exit handlers */
v0049:
    popv(3);
    return nil;
}



/* Code for times!-mod!-p */

static Lisp_Object CC_timesKmodKp(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0047)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0098, v0099, v0100;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for times-mod-p");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0047,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0047);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0047;
    stack[-1] = v0000;
/* end of prologue */
    v0098 = stack[-1];
    if (v0098 == nil) goto v0051;
    v0098 = stack[0];
    v0098 = (v0098 == nil ? lisp_true : nil);
    goto v0101;

v0101:
    if (v0098 == nil) goto v0102;
    v0098 = qvalue(elt(env, 2)); /* nil */
    { popv(4); return onevalue(v0098); }

v0102:
    v0098 = stack[-1];
    if (!consp(v0098)) goto v0029;
    v0098 = stack[-1];
    v0098 = qcar(v0098);
    v0098 = (consp(v0098) ? nil : lisp_true);
    goto v0027;

v0027:
    if (v0098 == nil) goto v0103;
    v0099 = stack[0];
    v0098 = stack[-1];
    {
        popv(4);
        fn = elt(env, 3); /* multiply!-by!-constant!-mod!-p */
        return (*qfn2(fn))(qenv(fn), v0099, v0098);
    }

v0103:
    v0098 = stack[0];
    if (!consp(v0098)) goto v0104;
    v0098 = stack[0];
    v0098 = qcar(v0098);
    v0098 = (consp(v0098) ? nil : lisp_true);
    goto v0038;

v0038:
    if (v0098 == nil) goto v0105;
    v0099 = stack[-1];
    v0098 = stack[0];
    {
        popv(4);
        fn = elt(env, 3); /* multiply!-by!-constant!-mod!-p */
        return (*qfn2(fn))(qenv(fn), v0099, v0098);
    }

v0105:
    v0098 = stack[-1];
    v0098 = qcar(v0098);
    v0098 = qcar(v0098);
    v0099 = qcar(v0098);
    v0098 = stack[0];
    v0098 = qcar(v0098);
    v0098 = qcar(v0098);
    v0098 = qcar(v0098);
    if (equal(v0099, v0098)) goto v0106;
    v0098 = stack[-1];
    v0098 = qcar(v0098);
    v0098 = qcar(v0098);
    v0099 = qcar(v0098);
    v0098 = stack[0];
    v0098 = qcar(v0098);
    v0098 = qcar(v0098);
    v0098 = qcar(v0098);
    fn = elt(env, 4); /* ordop */
    v0098 = (*qfn2(fn))(qenv(fn), v0099, v0098);
    nil = C_nil;
    if (exception_pending()) goto v0107;
    env = stack[-3];
    if (v0098 == nil) goto v0108;
    v0098 = stack[-1];
    v0098 = qcar(v0098);
    v0099 = qcdr(v0098);
    v0098 = stack[0];
    stack[-2] = CC_timesKmodKp(env, v0099, v0098);
    nil = C_nil;
    if (exception_pending()) goto v0107;
    env = stack[-3];
    v0098 = stack[-1];
    v0099 = qcdr(v0098);
    v0098 = stack[0];
    v0098 = CC_timesKmodKp(env, v0099, v0098);
    nil = C_nil;
    if (exception_pending()) goto v0107;
    v0099 = stack[-2];
    v0100 = v0099;
    if (v0100 == nil) { popv(4); return onevalue(v0098); }
    v0100 = stack[-1];
    v0100 = qcar(v0100);
    v0100 = qcar(v0100);
    popv(4);
    return acons(v0100, v0099, v0098);

v0108:
    v0099 = stack[-1];
    v0098 = stack[0];
    v0098 = qcar(v0098);
    v0098 = qcdr(v0098);
    stack[-2] = CC_timesKmodKp(env, v0099, v0098);
    nil = C_nil;
    if (exception_pending()) goto v0107;
    env = stack[-3];
    v0099 = stack[-1];
    v0098 = stack[0];
    v0098 = qcdr(v0098);
    v0098 = CC_timesKmodKp(env, v0099, v0098);
    nil = C_nil;
    if (exception_pending()) goto v0107;
    v0099 = stack[-2];
    v0100 = v0099;
    if (v0100 == nil) { popv(4); return onevalue(v0098); }
    v0100 = stack[0];
    v0100 = qcar(v0100);
    v0100 = qcar(v0100);
    popv(4);
    return acons(v0100, v0099, v0098);

v0106:
    v0098 = stack[-1];
    v0099 = qcar(v0098);
    v0098 = stack[0];
    fn = elt(env, 5); /* times!-term!-mod!-p */
    stack[-2] = (*qfn2(fn))(qenv(fn), v0099, v0098);
    nil = C_nil;
    if (exception_pending()) goto v0107;
    env = stack[-3];
    v0098 = stack[0];
    v0099 = qcar(v0098);
    v0098 = stack[-1];
    v0098 = qcdr(v0098);
    fn = elt(env, 5); /* times!-term!-mod!-p */
    v0098 = (*qfn2(fn))(qenv(fn), v0099, v0098);
    nil = C_nil;
    if (exception_pending()) goto v0107;
    env = stack[-3];
    fn = elt(env, 6); /* plus!-mod!-p */
    stack[-2] = (*qfn2(fn))(qenv(fn), stack[-2], v0098);
    nil = C_nil;
    if (exception_pending()) goto v0107;
    env = stack[-3];
    v0098 = stack[-1];
    v0099 = qcdr(v0098);
    v0098 = stack[0];
    v0098 = qcdr(v0098);
    v0098 = CC_timesKmodKp(env, v0099, v0098);
    nil = C_nil;
    if (exception_pending()) goto v0107;
    env = stack[-3];
    {
        Lisp_Object v0109 = stack[-2];
        popv(4);
        fn = elt(env, 6); /* plus!-mod!-p */
        return (*qfn2(fn))(qenv(fn), v0109, v0098);
    }

v0104:
    v0098 = qvalue(elt(env, 1)); /* t */
    goto v0038;

v0029:
    v0098 = qvalue(elt(env, 1)); /* t */
    goto v0027;

v0051:
    v0098 = qvalue(elt(env, 1)); /* t */
    goto v0101;
/* error exit handlers */
v0107:
    popv(4);
    return nil;
}



/* Code for mkgi */

static Lisp_Object CC_mkgi(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0047)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0062, v0063, v0064;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mkgi");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0062 = v0047;
    v0063 = v0000;
/* end of prologue */
    v0064 = elt(env, 1); /* !:gi!: */
    return list2star(v0064, v0063, v0062);
}



/* Code for add2calls */

static Lisp_Object CC_add2calls(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0114, v0039;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for add2calls");
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
    v0039 = stack[0];
    v0114 = elt(env, 1); /* cinthis */
    v0114 = Lflagp(nil, v0039, v0114);
    env = stack[-1];
    if (v0114 == nil) goto v0103;
    v0114 = qvalue(elt(env, 5)); /* nil */
    { popv(2); return onevalue(v0114); }

v0103:
    v0039 = stack[0];
    v0114 = elt(env, 2); /* nolist */
    v0114 = Lflagp(nil, v0039, v0114);
    env = stack[-1];
    if (v0114 == nil) goto v0096;
    v0039 = stack[0];
    v0114 = qvalue(elt(env, 3)); /* xseen!* */
    v0114 = cons(v0039, v0114);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    env = stack[-1];
    qvalue(elt(env, 3)) = v0114; /* xseen!* */
    goto v0115;

v0115:
    v0114 = stack[0];
    v0114 = ncons(v0114);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    env = stack[-1];
    v0039 = elt(env, 1); /* cinthis */
        popv(2);
        return Lflag(nil, v0114, v0039);

v0096:
    v0039 = stack[0];
    v0114 = qvalue(elt(env, 4)); /* calls!* */
    v0114 = cons(v0039, v0114);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    env = stack[-1];
    qvalue(elt(env, 4)) = v0114; /* calls!* */
    goto v0115;
/* error exit handlers */
v0094:
    popv(2);
    return nil;
}



/* Code for tayexp!-min2 */

static Lisp_Object CC_tayexpKmin2(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0047)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0103, v0028;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for tayexp-min2");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0047,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0047);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0047;
    stack[-1] = v0000;
/* end of prologue */
    v0028 = stack[-1];
    v0103 = stack[0];
    fn = elt(env, 1); /* tayexp!-lessp */
    v0103 = (*qfn2(fn))(qenv(fn), v0028, v0103);
    nil = C_nil;
    if (exception_pending()) goto v0034;
    if (v0103 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    else { Lisp_Object res = stack[-1]; popv(2); return onevalue(res); }
/* error exit handlers */
v0034:
    popv(2);
    return nil;
}



/* Code for addsq */

static Lisp_Object CC_addsq(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0047)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0159, v0160;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for addsq");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0047,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0047);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v0047;
    stack[-3] = v0000;
/* end of prologue */
    v0159 = stack[-3];
    v0159 = qcar(v0159);
    if (v0159 == nil) { Lisp_Object res = stack[-2]; popv(6); return onevalue(res); }
    v0159 = stack[-2];
    v0159 = qcar(v0159);
    if (v0159 == nil) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v0159 = stack[-3];
    v0160 = qcdr(v0159);
    v0159 = (Lisp_Object)17; /* 1 */
    if (v0160 == v0159) goto v0057;
    v0159 = qvalue(elt(env, 1)); /* nil */
    goto v0161;

v0161:
    if (v0159 == nil) goto v0093;
    v0159 = stack[-3];
    v0160 = qcar(v0159);
    v0159 = stack[-2];
    v0159 = qcar(v0159);
    fn = elt(env, 5); /* addf */
    v0160 = (*qfn2(fn))(qenv(fn), v0160, v0159);
    nil = C_nil;
    if (exception_pending()) goto v0162;
    v0159 = (Lisp_Object)17; /* 1 */
    popv(6);
    return cons(v0160, v0159);

v0093:
    v0159 = qvalue(elt(env, 2)); /* !*exp */
    if (!(v0159 == nil)) goto v0163;
    v0159 = stack[-3];
    stack[0] = qcar(v0159);
    v0159 = stack[-3];
    v0159 = qcdr(v0159);
    fn = elt(env, 6); /* mkprod */
    v0159 = (*qfn1(fn))(qenv(fn), v0159);
    nil = C_nil;
    if (exception_pending()) goto v0162;
    env = stack[-5];
    v0159 = cons(stack[0], v0159);
    nil = C_nil;
    if (exception_pending()) goto v0162;
    env = stack[-5];
    stack[-3] = v0159;
    v0159 = stack[-2];
    stack[0] = qcar(v0159);
    v0159 = stack[-2];
    v0159 = qcdr(v0159);
    fn = elt(env, 6); /* mkprod */
    v0159 = (*qfn1(fn))(qenv(fn), v0159);
    nil = C_nil;
    if (exception_pending()) goto v0162;
    env = stack[-5];
    v0159 = cons(stack[0], v0159);
    nil = C_nil;
    if (exception_pending()) goto v0162;
    env = stack[-5];
    stack[-2] = v0159;
    goto v0163;

v0163:
    v0159 = qvalue(elt(env, 3)); /* !*lcm */
    if (v0159 == nil) goto v0164;
    v0159 = stack[-3];
    v0160 = qcdr(v0159);
    v0159 = stack[-2];
    v0159 = qcdr(v0159);
    fn = elt(env, 7); /* gcdf!* */
    v0159 = (*qfn2(fn))(qenv(fn), v0160, v0159);
    nil = C_nil;
    if (exception_pending()) goto v0162;
    env = stack[-5];
    stack[-4] = v0159;
    goto v0082;

v0082:
    v0159 = stack[-3];
    v0160 = qcdr(v0159);
    v0159 = stack[-4];
    fn = elt(env, 8); /* quotf!-fail */
    stack[0] = (*qfn2(fn))(qenv(fn), v0160, v0159);
    nil = C_nil;
    if (exception_pending()) goto v0162;
    env = stack[-5];
    v0159 = stack[-2];
    v0160 = qcdr(v0159);
    v0159 = stack[-4];
    fn = elt(env, 8); /* quotf!-fail */
    v0159 = (*qfn2(fn))(qenv(fn), v0160, v0159);
    nil = C_nil;
    if (exception_pending()) goto v0162;
    env = stack[-5];
    v0159 = cons(stack[0], v0159);
    nil = C_nil;
    if (exception_pending()) goto v0162;
    env = stack[-5];
    fn = elt(env, 9); /* canonsq */
    v0159 = (*qfn1(fn))(qenv(fn), v0159);
    nil = C_nil;
    if (exception_pending()) goto v0162;
    env = stack[-5];
    stack[-1] = v0159;
    v0159 = stack[-1];
    v0160 = qcdr(v0159);
    v0159 = stack[-3];
    v0159 = qcar(v0159);
    fn = elt(env, 10); /* multf */
    stack[0] = (*qfn2(fn))(qenv(fn), v0160, v0159);
    nil = C_nil;
    if (exception_pending()) goto v0162;
    env = stack[-5];
    v0159 = stack[-1];
    v0160 = qcar(v0159);
    v0159 = stack[-2];
    v0159 = qcar(v0159);
    fn = elt(env, 10); /* multf */
    v0159 = (*qfn2(fn))(qenv(fn), v0160, v0159);
    nil = C_nil;
    if (exception_pending()) goto v0162;
    env = stack[-5];
    fn = elt(env, 5); /* addf */
    v0159 = (*qfn2(fn))(qenv(fn), stack[0], v0159);
    nil = C_nil;
    if (exception_pending()) goto v0162;
    env = stack[-5];
    stack[0] = v0159;
    v0159 = stack[0];
    if (v0159 == nil) goto v0070;
    v0159 = stack[-3];
    v0160 = qcdr(v0159);
    v0159 = stack[-1];
    v0159 = qcdr(v0159);
    fn = elt(env, 10); /* multf */
    v0159 = (*qfn2(fn))(qenv(fn), v0160, v0159);
    nil = C_nil;
    if (exception_pending()) goto v0162;
    env = stack[-5];
    stack[-1] = v0159;
    v0160 = stack[0];
    v0159 = stack[-4];
    fn = elt(env, 11); /* gcdf */
    v0160 = (*qfn2(fn))(qenv(fn), v0160, v0159);
    nil = C_nil;
    if (exception_pending()) goto v0162;
    env = stack[-5];
    stack[-4] = v0160;
    v0159 = (Lisp_Object)17; /* 1 */
    if (v0160 == v0159) goto v0069;
    v0160 = stack[0];
    v0159 = stack[-4];
    fn = elt(env, 8); /* quotf!-fail */
    v0159 = (*qfn2(fn))(qenv(fn), v0160, v0159);
    nil = C_nil;
    if (exception_pending()) goto v0162;
    env = stack[-5];
    stack[0] = v0159;
    v0160 = stack[-1];
    v0159 = stack[-4];
    fn = elt(env, 8); /* quotf!-fail */
    v0159 = (*qfn2(fn))(qenv(fn), v0160, v0159);
    nil = C_nil;
    if (exception_pending()) goto v0162;
    env = stack[-5];
    stack[-1] = v0159;
    goto v0069;

v0069:
    v0159 = qvalue(elt(env, 4)); /* !*gcd */
    if (v0159 == nil) goto v0165;
    v0160 = stack[-4];
    v0159 = (Lisp_Object)17; /* 1 */
    if (v0160 == v0159) goto v0166;
    v0160 = stack[0];
    v0159 = stack[-1];
    v0159 = cons(v0160, v0159);
    nil = C_nil;
    if (exception_pending()) goto v0162;
    env = stack[-5];
    {
        popv(6);
        fn = elt(env, 9); /* canonsq */
        return (*qfn1(fn))(qenv(fn), v0159);
    }

v0166:
    v0160 = stack[0];
    v0159 = stack[-1];
    popv(6);
    return cons(v0160, v0159);

v0165:
    v0160 = stack[0];
    v0159 = stack[-1];
    fn = elt(env, 11); /* gcdf */
    v0160 = (*qfn2(fn))(qenv(fn), v0160, v0159);
    nil = C_nil;
    if (exception_pending()) goto v0162;
    env = stack[-5];
    stack[-4] = v0160;
    v0159 = (Lisp_Object)17; /* 1 */
    if (v0160 == v0159) goto v0167;
    v0160 = stack[0];
    v0159 = stack[-4];
    fn = elt(env, 8); /* quotf!-fail */
    stack[0] = (*qfn2(fn))(qenv(fn), v0160, v0159);
    nil = C_nil;
    if (exception_pending()) goto v0162;
    env = stack[-5];
    v0160 = stack[-1];
    v0159 = stack[-4];
    fn = elt(env, 8); /* quotf!-fail */
    v0159 = (*qfn2(fn))(qenv(fn), v0160, v0159);
    nil = C_nil;
    if (exception_pending()) goto v0162;
    env = stack[-5];
    v0159 = cons(stack[0], v0159);
    nil = C_nil;
    if (exception_pending()) goto v0162;
    env = stack[-5];
    {
        popv(6);
        fn = elt(env, 9); /* canonsq */
        return (*qfn1(fn))(qenv(fn), v0159);
    }

v0167:
    v0160 = stack[0];
    v0159 = stack[-1];
    v0159 = cons(v0160, v0159);
    nil = C_nil;
    if (exception_pending()) goto v0162;
    env = stack[-5];
    {
        popv(6);
        fn = elt(env, 9); /* canonsq */
        return (*qfn1(fn))(qenv(fn), v0159);
    }

v0070:
    v0160 = qvalue(elt(env, 1)); /* nil */
    v0159 = (Lisp_Object)17; /* 1 */
    popv(6);
    return cons(v0160, v0159);

v0164:
    v0159 = stack[-3];
    v0160 = qcdr(v0159);
    v0159 = stack[-2];
    v0159 = qcdr(v0159);
    fn = elt(env, 11); /* gcdf */
    v0159 = (*qfn2(fn))(qenv(fn), v0160, v0159);
    nil = C_nil;
    if (exception_pending()) goto v0162;
    env = stack[-5];
    stack[-4] = v0159;
    goto v0082;

v0057:
    v0159 = stack[-2];
    v0160 = qcdr(v0159);
    v0159 = (Lisp_Object)17; /* 1 */
    v0159 = (v0160 == v0159 ? lisp_true : nil);
    goto v0161;
/* error exit handlers */
v0162:
    popv(6);
    return nil;
}



/* Code for ckrn1 */

static Lisp_Object CC_ckrn1(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0171, v0085;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ckrn1");
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
    v0171 = stack[0];
    if (!consp(v0171)) goto v0110;
    v0171 = stack[0];
    v0171 = qcar(v0171);
    v0171 = (consp(v0171) ? nil : lisp_true);
    goto v0050;

v0050:
    if (!(v0171 == nil)) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }

v0034:
    v0171 = stack[0];
    v0171 = qcar(v0171);
    v0171 = qcdr(v0171);
    v0085 = CC_ckrn1(env, v0171);
    nil = C_nil;
    if (exception_pending()) goto v0151;
    env = stack[-2];
    v0171 = stack[-1];
    fn = elt(env, 2); /* gck2 */
    v0171 = (*qfn2(fn))(qenv(fn), v0085, v0171);
    nil = C_nil;
    if (exception_pending()) goto v0151;
    env = stack[-2];
    stack[-1] = v0171;
    v0171 = stack[0];
    v0171 = qcdr(v0171);
    if (v0171 == nil) goto v0035;
    v0171 = stack[0];
    v0171 = qcdr(v0171);
    if (!consp(v0171)) goto v0091;
    v0171 = stack[0];
    v0171 = qcdr(v0171);
    v0171 = qcar(v0171);
    v0171 = (consp(v0171) ? nil : lisp_true);
    goto v0172;

v0172:
    if (v0171 == nil) goto v0173;
    v0171 = qvalue(elt(env, 1)); /* t */
    goto v0024;

v0024:
    if (v0171 == nil) goto v0055;
    v0171 = stack[0];
    v0171 = qcdr(v0171);
    v0085 = CC_ckrn1(env, v0171);
    nil = C_nil;
    if (exception_pending()) goto v0151;
    env = stack[-2];
    v0171 = stack[-1];
    {
        popv(3);
        fn = elt(env, 2); /* gck2 */
        return (*qfn2(fn))(qenv(fn), v0085, v0171);
    }

v0055:
    v0171 = stack[0];
    v0171 = qcdr(v0171);
    stack[0] = v0171;
    goto v0034;

v0173:
    v0171 = stack[0];
    v0171 = qcar(v0171);
    v0171 = qcar(v0171);
    v0085 = qcar(v0171);
    v0171 = stack[0];
    v0171 = qcdr(v0171);
    v0171 = qcar(v0171);
    v0171 = qcar(v0171);
    v0171 = qcar(v0171);
    v0171 = (v0085 == v0171 ? lisp_true : nil);
    v0171 = (v0171 == nil ? lisp_true : nil);
    goto v0024;

v0091:
    v0171 = qvalue(elt(env, 1)); /* t */
    goto v0172;

v0035:
    v0171 = stack[0];
    v0171 = qcar(v0171);
    v0171 = qcar(v0171);
    v0171 = qcar(v0171);
    fn = elt(env, 3); /* noncomp */
    v0171 = (*qfn1(fn))(qenv(fn), v0171);
    nil = C_nil;
    if (exception_pending()) goto v0151;
    env = stack[-2];
    if (!(v0171 == nil)) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v0171 = stack[0];
    v0171 = qcar(v0171);
    v0085 = qcar(v0171);
    v0171 = stack[-1];
    v0171 = cons(v0085, v0171);
    nil = C_nil;
    if (exception_pending()) goto v0151;
    popv(3);
    return ncons(v0171);

v0110:
    v0171 = qvalue(elt(env, 1)); /* t */
    goto v0050;
/* error exit handlers */
v0151:
    popv(3);
    return nil;
}



/* Code for mri_simplfloor */

static Lisp_Object CC_mri_simplfloor(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0061;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mri_simplfloor");
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
    v0061 = stack[0];
    fn = elt(env, 1); /* mri_floorkernelp */
    v0061 = (*qfn1(fn))(qenv(fn), v0061);
    nil = C_nil;
    if (exception_pending()) goto v0063;
    env = stack[-1];
    if (v0061 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v0061 = stack[0];
    {
        popv(2);
        fn = elt(env, 2); /* mri_simplfloor1 */
        return (*qfn1(fn))(qenv(fn), v0061);
    }
/* error exit handlers */
v0063:
    popv(2);
    return nil;
}



/* Code for ibalp_minclnr */

static Lisp_Object CC_ibalp_minclnr(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0092, v0023;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ibalp_minclnr");
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
    v0023 = v0000;
/* end of prologue */
    v0092 = (Lisp_Object)1600001; /* 100000 */
    stack[-2] = v0092;
    v0092 = v0023;
    stack[-1] = v0092;
    goto v0051;

v0051:
    v0092 = stack[-1];
    if (v0092 == nil) { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
    v0092 = stack[-1];
    v0092 = qcar(v0092);
    stack[0] = v0092;
    v0092 = stack[0];
    v0092 = qcdr(v0092);
    v0092 = qcdr(v0092);
    v0092 = qcdr(v0092);
    v0092 = qcdr(v0092);
    v0092 = qcar(v0092);
    if (!(v0092 == nil)) goto v0027;
    v0092 = stack[0];
    v0092 = qcdr(v0092);
    v0092 = qcdr(v0092);
    v0023 = qcar(v0092);
    v0092 = stack[0];
    v0092 = qcdr(v0092);
    v0092 = qcdr(v0092);
    v0092 = qcdr(v0092);
    v0092 = qcar(v0092);
    v0023 = plus2(v0023, v0092);
    nil = C_nil;
    if (exception_pending()) goto v0177;
    env = stack[-3];
    v0092 = stack[-2];
    v0092 = (Lisp_Object)lessp2(v0023, v0092);
    nil = C_nil;
    if (exception_pending()) goto v0177;
    v0092 = v0092 ? lisp_true : nil;
    env = stack[-3];
    if (v0092 == nil) goto v0027;
    v0092 = stack[0];
    v0092 = qcdr(v0092);
    v0092 = qcdr(v0092);
    v0023 = qcar(v0092);
    v0092 = stack[0];
    v0092 = qcdr(v0092);
    v0092 = qcdr(v0092);
    v0092 = qcdr(v0092);
    v0092 = qcar(v0092);
    v0092 = plus2(v0023, v0092);
    nil = C_nil;
    if (exception_pending()) goto v0177;
    env = stack[-3];
    stack[-2] = v0092;
    goto v0027;

v0027:
    v0092 = stack[-1];
    v0092 = qcdr(v0092);
    stack[-1] = v0092;
    goto v0051;
/* error exit handlers */
v0177:
    popv(4);
    return nil;
}



/* Code for mathml_list2string */

static Lisp_Object CC_mathml_list2string(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0063;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mathml_list2string");
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
    v0063 = stack[0];
    if (v0063 == nil) goto v0033;
    v0063 = stack[0];
    v0063 = qcar(v0063);
    v0063 = Lprinc(nil, v0063);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-1];
    v0063 = stack[0];
    v0063 = qcdr(v0063);
    v0063 = CC_mathml_list2string(env, v0063);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    goto v0033;

v0033:
    v0063 = nil;
    { popv(2); return onevalue(v0063); }
/* error exit handlers */
v0058:
    popv(2);
    return nil;
}



/* Code for findrow */

static Lisp_Object CC_findrow(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0047)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0059, v0060, v0174, v0095;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for findrow");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0047,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0047);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v0059 = v0047;
    v0060 = v0000;
/* end of prologue */
    v0174 = v0060;
    v0174 = Lconsp(nil, v0174);
    env = stack[0];
    if (v0174 == nil) goto v0053;
    v0174 = v0060;
    v0174 = qcar(v0174);
    v0095 = elt(env, 1); /* sparsemat */
    if (!(v0174 == v0095)) goto v0053;
    v0060 = qcdr(v0060);
    v0060 = qcar(v0060);
    goto v0053;

v0053:
    v0059 = *(Lisp_Object *)((char *)v0060 + (CELL-TAG_VECTOR) + ((int32_t)v0059/(16/CELL)));
    { popv(1); return onevalue(v0059); }
}



/* Code for dm!-times */

static Lisp_Object CC_dmKtimes(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0047)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0034, v0113;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dm-times");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0047,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0047);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0047;
    v0034 = v0000;
/* end of prologue */
    fn = elt(env, 1); /* zero2nil */
    stack[-1] = (*qfn1(fn))(qenv(fn), v0034);
    nil = C_nil;
    if (exception_pending()) goto v0004;
    env = stack[-2];
    v0034 = stack[0];
    fn = elt(env, 1); /* zero2nil */
    v0034 = (*qfn1(fn))(qenv(fn), v0034);
    nil = C_nil;
    if (exception_pending()) goto v0004;
    env = stack[-2];
    fn = elt(env, 2); /* !:times */
    v0034 = (*qfn2(fn))(qenv(fn), stack[-1], v0034);
    nil = C_nil;
    if (exception_pending()) goto v0004;
    v0113 = v0034;
    v0034 = v0113;
    if (!(v0034 == nil)) { popv(3); return onevalue(v0113); }
    v0034 = (Lisp_Object)1; /* 0 */
    { popv(3); return onevalue(v0034); }
/* error exit handlers */
v0004:
    popv(3);
    return nil;
}



/* Code for rmsubs */

static Lisp_Object MS_CDECL CC_rmsubs(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0063, v0064;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "rmsubs");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rmsubs");
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
/* end of prologue */
    v0064 = qvalue(elt(env, 1)); /* !*sqvar!* */
    v0063 = qvalue(elt(env, 2)); /* nil */
    v0063 = Lrplaca(nil, v0064, v0063);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[0];
    v0063 = qvalue(elt(env, 3)); /* t */
    v0063 = ncons(v0063);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[0];
    qvalue(elt(env, 1)) = v0063; /* !*sqvar!* */
    v0063 = qvalue(elt(env, 2)); /* nil */
    v0063 = ncons(v0063);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[0];
    qvalue(elt(env, 4)) = v0063; /* alglist!* */
    v0063 = nil;
    { popv(1); return onevalue(v0063); }
/* error exit handlers */
v0058:
    popv(1);
    return nil;
}



/* Code for prin2la */

static Lisp_Object CC_prin2la(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0114, v0039;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for prin2la");
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
    v0114 = stack[0];
    fn = elt(env, 4); /* chundexp */
    v0114 = (*qfn1(fn))(qenv(fn), v0114);
    nil = C_nil;
    if (exception_pending()) goto v0120;
    env = stack[-2];
    stack[0] = v0114;
    v0114 = stack[0];
    v0114 = Llength(nil, v0114);
    nil = C_nil;
    if (exception_pending()) goto v0120;
    env = stack[-2];
    stack[-1] = v0114;
    v0039 = qvalue(elt(env, 1)); /* ncharspr!* */
    v0114 = stack[-1];
    v0039 = plus2(v0039, v0114);
    nil = C_nil;
    if (exception_pending()) goto v0120;
    env = stack[-2];
    v0114 = qvalue(elt(env, 2)); /* laline!* */
    v0114 = (Lisp_Object)greaterp2(v0039, v0114);
    nil = C_nil;
    if (exception_pending()) goto v0120;
    v0114 = v0114 ? lisp_true : nil;
    env = stack[-2];
    if (v0114 == nil) goto v0052;
    v0114 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0120;
    env = stack[-2];
    v0114 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 1)) = v0114; /* ncharspr!* */
    goto v0052;

v0052:
    v0114 = stack[0];
    stack[0] = v0114;
    goto v0054;

v0054:
    v0114 = stack[0];
    if (v0114 == nil) goto v0176;
    v0114 = stack[0];
    v0114 = qcar(v0114);
    v0114 = Lprinc(nil, v0114);
    nil = C_nil;
    if (exception_pending()) goto v0120;
    env = stack[-2];
    v0114 = stack[0];
    v0114 = qcdr(v0114);
    stack[0] = v0114;
    goto v0054;

v0176:
    v0039 = qvalue(elt(env, 1)); /* ncharspr!* */
    v0114 = stack[-1];
    v0114 = plus2(v0039, v0114);
    nil = C_nil;
    if (exception_pending()) goto v0120;
    env = stack[-2];
    qvalue(elt(env, 1)) = v0114; /* ncharspr!* */
    v0114 = nil;
    { popv(3); return onevalue(v0114); }
/* error exit handlers */
v0120:
    popv(3);
    return nil;
}



/* Code for command1 */

static Lisp_Object MS_CDECL CC_command1(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0101;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "command1");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for command1");
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
/* end of prologue */
    fn = elt(env, 4); /* scan */
    v0101 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0051;
    env = stack[0];
    fn = elt(env, 5); /* setcloc!* */
    v0101 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0051;
    env = stack[0];
    v0101 = qvalue(elt(env, 1)); /* cursym!* */
    qvalue(elt(env, 2)) = v0101; /* key!* */
    v0101 = qvalue(elt(env, 3)); /* nil */
    {
        popv(1);
        fn = elt(env, 6); /* xread1 */
        return (*qfn1(fn))(qenv(fn), v0101);
    }
/* error exit handlers */
v0051:
    popv(1);
    return nil;
}



/* Code for getel1 */

static Lisp_Object MS_CDECL CC_getel1(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0022, v0155, v0156;
    Lisp_Object fn;
    Lisp_Object v0168, v0047, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "getel1");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0047 = va_arg(aa, Lisp_Object);
    v0168 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for getel1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0168,v0047,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0047,v0168);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0168;
    stack[-1] = v0047;
    stack[-2] = v0000;
/* end of prologue */

v0102:
    v0022 = stack[-1];
    if (v0022 == nil) { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
    v0022 = stack[-1];
    v0022 = qcar(v0022);
    v0022 = integerp(v0022);
    if (v0022 == nil) goto v0103;
    v0022 = stack[-1];
    v0155 = qcar(v0022);
    v0022 = stack[0];
    v0022 = qcar(v0022);
    v0022 = (Lisp_Object)geq2(v0155, v0022);
    nil = C_nil;
    if (exception_pending()) goto v0179;
    v0022 = v0022 ? lisp_true : nil;
    env = stack[-3];
    if (!(v0022 == nil)) goto v0180;
    v0022 = stack[-1];
    v0155 = qcar(v0022);
    v0022 = (Lisp_Object)1; /* 0 */
    v0022 = (Lisp_Object)lessp2(v0155, v0022);
    nil = C_nil;
    if (exception_pending()) goto v0179;
    v0022 = v0022 ? lisp_true : nil;
    env = stack[-3];
    if (!(v0022 == nil)) goto v0180;
    v0155 = stack[-2];
    v0022 = stack[-1];
    v0022 = qcar(v0022);
    v0022 = *(Lisp_Object *)((char *)v0155 + (CELL-TAG_VECTOR) + ((int32_t)v0022/(16/CELL)));
    stack[-2] = v0022;
    v0022 = stack[-1];
    v0022 = qcdr(v0022);
    stack[-1] = v0022;
    v0022 = stack[0];
    v0022 = qcdr(v0022);
    stack[0] = v0022;
    goto v0102;

v0180:
    v0156 = elt(env, 2); /* rlisp */
    v0155 = (Lisp_Object)337; /* 21 */
    v0022 = elt(env, 3); /* "Array out of bounds" */
    {
        popv(4);
        fn = elt(env, 4); /* rerror */
        return (*qfnn(fn))(qenv(fn), 3, v0156, v0155, v0022);
    }

v0103:
    v0022 = stack[-1];
    v0155 = qcar(v0022);
    v0022 = elt(env, 1); /* "array index" */
    {
        popv(4);
        fn = elt(env, 5); /* typerr */
        return (*qfn2(fn))(qenv(fn), v0155, v0022);
    }
/* error exit handlers */
v0179:
    popv(4);
    return nil;
}



/* Code for mo!=shorten */

static Lisp_Object CC_moMshorten(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0049, v0053;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mo=shorten");
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
    v0049 = v0000;
/* end of prologue */
    v0049 = Lreverse(nil, v0049);
    nil = C_nil;
    if (exception_pending()) goto v0055;
    env = stack[-1];
    stack[0] = v0049;
    goto v0051;

v0051:
    v0049 = stack[0];
    if (v0049 == nil) goto v0101;
    v0049 = stack[0];
    v0053 = qcar(v0049);
    v0049 = (Lisp_Object)1; /* 0 */
    v0049 = Leqn(nil, v0053, v0049);
    nil = C_nil;
    if (exception_pending()) goto v0055;
    env = stack[-1];
    if (v0049 == nil) goto v0101;
    v0049 = stack[0];
    v0049 = qcdr(v0049);
    stack[0] = v0049;
    goto v0051;

v0101:
    v0049 = stack[0];
        popv(2);
        return Lnreverse(nil, v0049);
/* error exit handlers */
v0055:
    popv(2);
    return nil;
}



/* Code for resimp */

static Lisp_Object CC_resimp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0102, v0097;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for resimp");
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
    v0097 = v0000;
/* end of prologue */
    v0102 = qvalue(elt(env, 1)); /* nil */
    stack[0] = qvalue(elt(env, 2)); /* varstack!* */
    qvalue(elt(env, 2)) = v0102; /* varstack!* */
    v0102 = v0097;
    fn = elt(env, 3); /* resimp1 */
    v0102 = (*qfn1(fn))(qenv(fn), v0102);
    nil = C_nil;
    if (exception_pending()) goto v0051;
    env = stack[-1];
    qvalue(elt(env, 2)) = stack[0]; /* varstack!* */
    { popv(2); return onevalue(v0102); }
/* error exit handlers */
v0051:
    env = stack[-1];
    qvalue(elt(env, 2)) = stack[0]; /* varstack!* */
    popv(2);
    return nil;
}



/* Code for pv_sort1 */

static Lisp_Object CC_pv_sort1(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0047)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0158, v0175;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pv_sort1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0047,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0047);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0047;
    stack[-1] = v0000;
/* end of prologue */

v0102:
    v0158 = stack[-1];
    if (v0158 == nil) goto v0051;
    v0158 = stack[-1];
    v0158 = qcar(v0158);
    v0175 = qcdr(v0158);
    v0158 = stack[0];
    v0158 = qcar(v0158);
    v0158 = qcdr(v0158);
    v0158 = (Lisp_Object)lessp2(v0175, v0158);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    v0158 = v0158 ? lisp_true : nil;
    env = stack[-3];
    if (v0158 == nil) goto v0174;
    v0158 = stack[-1];
    v0158 = qcdr(v0158);
    stack[-2] = v0158;
    v0158 = stack[-1];
    v0175 = qcar(v0158);
    v0158 = stack[0];
    v0158 = cons(v0175, v0158);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    env = stack[-3];
    stack[0] = v0158;
    v0158 = stack[-2];
    stack[-1] = v0158;
    goto v0102;

v0174:
    v0158 = stack[-1];
    v0158 = qcdr(v0158);
    stack[-2] = v0158;
    v0158 = stack[-1];
    v0175 = qcar(v0158);
    v0158 = stack[0];
    fn = elt(env, 1); /* pv_sort2 */
    v0158 = (*qfn2(fn))(qenv(fn), v0175, v0158);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    env = stack[-3];
    stack[0] = v0158;
    v0158 = stack[-2];
    stack[-1] = v0158;
    goto v0102;

v0051:
    v0158 = stack[0];
        popv(4);
        return Lnreverse(nil, v0158);
/* error exit handlers */
v0094:
    popv(4);
    return nil;
}



/* Code for lalr_items */

static Lisp_Object MS_CDECL CC_lalr_items(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0205, v0128, v0129;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "lalr_items");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for lalr_items");
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
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
/* end of prologue */
    v0205 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 1)) = v0205; /* item_count */
    v0128 = elt(env, 2); /* !S!' */
    v0205 = elt(env, 3); /* produces */
    v0205 = get(v0128, v0205);
    env = stack[-10];
    stack[0] = v0205;
    v0205 = stack[0];
    v0205 = qcdr(v0205);
    if (v0205 == nil) goto v0055;
    v0128 = (Lisp_Object)1; /* 0 */
    v0205 = elt(env, 4); /* "Starting state must only reduce to one thing" 
*/
    fn = elt(env, 13); /* error */
    v0205 = (*qfn2(fn))(qenv(fn), v0128, v0205);
    nil = C_nil;
    if (exception_pending()) goto v0206;
    env = stack[-10];
    goto v0027;

v0027:
    v0205 = (Lisp_Object)1; /* 0 */
    stack[-8] = v0205;
    stack[-1] = elt(env, 2); /* !S!' */
    v0128 = elt(env, 5); /* !. */
    v0205 = stack[0];
    stack[0] = cons(v0128, v0205);
    nil = C_nil;
    if (exception_pending()) goto v0206;
    env = stack[-10];
    v0205 = (Lisp_Object)1; /* 0 */
    v0205 = ncons(v0205);
    nil = C_nil;
    if (exception_pending()) goto v0206;
    env = stack[-10];
    v0205 = acons(stack[-1], stack[0], v0205);
    nil = C_nil;
    if (exception_pending()) goto v0206;
    env = stack[-10];
    v0205 = ncons(v0205);
    nil = C_nil;
    if (exception_pending()) goto v0206;
    env = stack[-10];
    fn = elt(env, 14); /* lalr_closure */
    v0128 = (*qfn1(fn))(qenv(fn), v0205);
    nil = C_nil;
    if (exception_pending()) goto v0206;
    env = stack[-10];
    v0205 = stack[-8];
    v0205 = cons(v0128, v0205);
    nil = C_nil;
    if (exception_pending()) goto v0206;
    env = stack[-10];
    v0205 = ncons(v0205);
    nil = C_nil;
    if (exception_pending()) goto v0206;
    env = stack[-10];
    stack[-9] = v0205;
    goto v0207;

v0207:
    v0205 = qvalue(elt(env, 6)); /* nil */
    stack[-2] = v0205;
    v0205 = stack[-9];
    stack[-6] = v0205;
    goto v0022;

v0022:
    v0205 = stack[-6];
    if (v0205 == nil) goto v0023;
    v0205 = stack[-6];
    v0205 = qcar(v0205);
    stack[-5] = v0205;
    v0205 = qvalue(elt(env, 7)); /* symbols */
    stack[-4] = v0205;
    goto v0208;

v0208:
    v0205 = stack[-4];
    if (v0205 == nil) goto v0154;
    v0205 = stack[-4];
    v0205 = qcar(v0205);
    stack[0] = v0205;
    v0205 = stack[0];
    v0205 = Lstringp(nil, v0205);
    env = stack[-10];
    if (v0205 == nil) goto v0084;
    v0205 = stack[0];
    v0128 = Lintern(nil, v0205);
    nil = C_nil;
    if (exception_pending()) goto v0206;
    env = stack[-10];
    v0205 = elt(env, 8); /* lex_code */
    v0205 = get(v0128, v0205);
    env = stack[-10];
    goto v0088;

v0088:
    if (!(v0205 == nil)) goto v0209;
    v0205 = stack[0];
    if (symbolp(v0205)) goto v0014;
    v0205 = qvalue(elt(env, 6)); /* nil */
    goto v0209;

v0209:
    stack[-7] = v0205;
    v0205 = stack[-7];
    if (!(v0205 == nil)) goto v0078;
    v0205 = stack[0];
    stack[-7] = v0205;
    goto v0078;

v0078:
    v0205 = stack[-5];
    v0128 = qcar(v0205);
    v0205 = stack[-7];
    fn = elt(env, 15); /* lalr_goto */
    v0205 = (*qfn2(fn))(qenv(fn), v0128, v0205);
    nil = C_nil;
    if (exception_pending()) goto v0206;
    env = stack[-10];
    stack[0] = v0205;
    if (v0205 == nil) goto v0210;
    v0128 = stack[0];
    v0205 = stack[-9];
    v0205 = Lassoc(nil, v0128, v0205);
    stack[-1] = v0205;
    v0205 = stack[-1];
    if (v0205 == nil) goto v0211;
    v0128 = stack[-7];
    v0205 = qvalue(elt(env, 10)); /* goto_cache */
    fn = elt(env, 16); /* gethash */
    v0205 = (*qfn2(fn))(qenv(fn), v0128, v0205);
    nil = C_nil;
    if (exception_pending()) goto v0206;
    env = stack[-10];
    v0128 = stack[-5];
    v0129 = qcdr(v0128);
    v0128 = v0205;
    v0128 = Lassoc(nil, v0129, v0128);
    if (!(v0128 == nil)) goto v0210;
    stack[-3] = stack[-7];
    stack[0] = qvalue(elt(env, 10)); /* goto_cache */
    v0128 = stack[-5];
    v0129 = qcdr(v0128);
    v0128 = stack[-1];
    v0128 = qcdr(v0128);
    v0205 = acons(v0129, v0128, v0205);
    nil = C_nil;
    if (exception_pending()) goto v0206;
    env = stack[-10];
    fn = elt(env, 17); /* puthash */
    v0205 = (*qfnn(fn))(qenv(fn), 3, stack[-3], stack[0], v0205);
    nil = C_nil;
    if (exception_pending()) goto v0206;
    env = stack[-10];
    goto v0210;

v0210:
    v0205 = stack[-4];
    v0205 = qcdr(v0205);
    stack[-4] = v0205;
    goto v0208;

v0211:
    v0205 = qvalue(elt(env, 1)); /* item_count */
    v0205 = add1(v0205);
    nil = C_nil;
    if (exception_pending()) goto v0206;
    env = stack[-10];
    qvalue(elt(env, 1)) = v0205; /* item_count */
    v0205 = stack[-8];
    v0128 = add1(v0205);
    nil = C_nil;
    if (exception_pending()) goto v0206;
    env = stack[-10];
    stack[-8] = v0128;
    v0205 = stack[-9];
    v0205 = acons(stack[0], v0128, v0205);
    nil = C_nil;
    if (exception_pending()) goto v0206;
    env = stack[-10];
    stack[-9] = v0205;
    stack[-3] = stack[-7];
    stack[-2] = qvalue(elt(env, 10)); /* goto_cache */
    v0205 = stack[-5];
    stack[-1] = qcdr(v0205);
    stack[0] = stack[-8];
    v0128 = stack[-7];
    v0205 = qvalue(elt(env, 10)); /* goto_cache */
    fn = elt(env, 16); /* gethash */
    v0205 = (*qfn2(fn))(qenv(fn), v0128, v0205);
    nil = C_nil;
    if (exception_pending()) goto v0206;
    env = stack[-10];
    v0205 = acons(stack[-1], stack[0], v0205);
    nil = C_nil;
    if (exception_pending()) goto v0206;
    env = stack[-10];
    fn = elt(env, 17); /* puthash */
    v0205 = (*qfnn(fn))(qenv(fn), 3, stack[-3], stack[-2], v0205);
    nil = C_nil;
    if (exception_pending()) goto v0206;
    env = stack[-10];
    v0205 = qvalue(elt(env, 11)); /* t */
    stack[-2] = v0205;
    goto v0210;

v0014:
    v0128 = stack[0];
    v0205 = elt(env, 9); /* lex_fixed_code */
    v0205 = get(v0128, v0205);
    env = stack[-10];
    goto v0209;

v0084:
    v0205 = qvalue(elt(env, 6)); /* nil */
    goto v0088;

v0154:
    v0205 = stack[-6];
    v0205 = qcdr(v0205);
    stack[-6] = v0205;
    goto v0022;

v0023:
    v0205 = stack[-2];
    if (!(v0205 == nil)) goto v0207;
    v0205 = stack[-9];
    v0205 = Lnreverse(nil, v0205);
    env = stack[-10];
    stack[-9] = v0205;
    v0205 = elt(env, 12); /* "Number of items put into goto cache = " */
    v0205 = Lprinc(nil, v0205);
    nil = C_nil;
    if (exception_pending()) goto v0206;
    env = stack[-10];
    v0205 = qvalue(elt(env, 1)); /* item_count */
    v0205 = Lprint(nil, v0205);
    nil = C_nil;
    if (exception_pending()) goto v0206;
    { Lisp_Object res = stack[-9]; popv(11); return onevalue(res); }

v0055:
    v0205 = stack[0];
    v0205 = qcar(v0205);
    v0205 = qcar(v0205);
    stack[0] = v0205;
    goto v0027;
/* error exit handlers */
v0206:
    popv(11);
    return nil;
}



/* Code for ofsf_vareqnp */

static Lisp_Object CC_ofsf_vareqnp(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0047)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0097, v0101;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ofsf_vareqnp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0097 = v0047;
    v0101 = v0000;
/* end of prologue */
    v0097 = qcdr(v0097);
    v0097 = qcar(v0097);
    {
        fn = elt(env, 1); /* sfto_varisnump */
        return (*qfn1(fn))(qenv(fn), v0097);
    }
}



/* Code for rl_prepat */

static Lisp_Object CC_rl_prepat(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0050;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rl_prepat");
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
    v0050 = v0000;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* rl_prepat!* */
    v0050 = ncons(v0050);
    nil = C_nil;
    if (exception_pending()) goto v0061;
    env = stack[-1];
    {
        Lisp_Object v0062 = stack[0];
        popv(2);
        fn = elt(env, 2); /* apply */
        return (*qfn2(fn))(qenv(fn), v0062, v0050);
    }
/* error exit handlers */
v0061:
    popv(2);
    return nil;
}



/* Code for fac!-merge */

static Lisp_Object CC_facKmerge(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0047)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0057, v0048;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for fac-merge");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0047,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0047);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0047;
    stack[-1] = v0000;
/* end of prologue */
    v0057 = stack[-1];
    v0048 = qcar(v0057);
    v0057 = stack[0];
    v0057 = qcar(v0057);
    fn = elt(env, 1); /* multf */
    stack[-2] = (*qfn2(fn))(qenv(fn), v0048, v0057);
    nil = C_nil;
    if (exception_pending()) goto v0055;
    env = stack[-3];
    v0057 = stack[-1];
    v0048 = qcdr(v0057);
    v0057 = stack[0];
    v0057 = qcdr(v0057);
    v0057 = Lappend(nil, v0048, v0057);
    nil = C_nil;
    if (exception_pending()) goto v0055;
    {
        Lisp_Object v0035 = stack[-2];
        popv(4);
        return cons(v0035, v0057);
    }
/* error exit handlers */
v0055:
    popv(4);
    return nil;
}



/* Code for ibalp_csat */

static Lisp_Object CC_ibalp_csat(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0004, v0026;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ibalp_csat");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0004 = v0000;
/* end of prologue */

v0212:
    v0026 = v0004;
    if (v0026 == nil) goto v0190;
    v0026 = v0004;
    v0026 = qcar(v0026);
    v0026 = qcdr(v0026);
    v0026 = qcdr(v0026);
    v0026 = qcdr(v0026);
    v0026 = qcdr(v0026);
    v0026 = qcar(v0026);
    if (v0026 == nil) goto v0110;
    v0004 = qcdr(v0004);
    goto v0212;

v0110:
    v0004 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v0004);

v0190:
    v0004 = qvalue(elt(env, 1)); /* t */
    return onevalue(v0004);
}



/* Code for listsum */

static Lisp_Object CC_listsum(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0104, v0036;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for listsum");
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
    goto v0102;

v0102:
    v0104 = stack[0];
    if (v0104 == nil) goto v0097;
    v0104 = stack[0];
    v0036 = qcar(v0104);
    v0104 = stack[-1];
    v0104 = cons(v0036, v0104);
    nil = C_nil;
    if (exception_pending()) goto v0157;
    env = stack[-2];
    stack[-1] = v0104;
    v0104 = stack[0];
    v0104 = qcdr(v0104);
    stack[0] = v0104;
    goto v0102;

v0097:
    v0104 = (Lisp_Object)1; /* 0 */
    v0036 = v0104;
    goto v0101;

v0101:
    v0104 = stack[-1];
    if (v0104 == nil) { popv(3); return onevalue(v0036); }
    v0104 = stack[-1];
    v0104 = qcar(v0104);
    v0104 = plus2(v0104, v0036);
    nil = C_nil;
    if (exception_pending()) goto v0157;
    env = stack[-2];
    v0036 = v0104;
    v0104 = stack[-1];
    v0104 = qcdr(v0104);
    stack[-1] = v0104;
    goto v0101;
/* error exit handlers */
v0157:
    popv(3);
    return nil;
}



/* Code for indent!* */

static Lisp_Object CC_indentH(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0056, v0096;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for indent*");
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
    v0096 = stack[0];
    v0056 = qvalue(elt(env, 1)); /* t */
    if (!(equal(v0096, v0056))) goto v0033;
    v0096 = qvalue(elt(env, 2)); /* indent */
    v0056 = qvalue(elt(env, 3)); /* ind */
    v0056 = plus2(v0096, v0056);
    nil = C_nil;
    if (exception_pending()) goto v0060;
    env = stack[-1];
    qvalue(elt(env, 2)) = v0056; /* indent */
    goto v0033;

v0033:
    v0056 = stack[0];
    if (!(v0056 == nil)) goto v0113;
    v0096 = qvalue(elt(env, 2)); /* indent */
    v0056 = qvalue(elt(env, 3)); /* ind */
    v0056 = difference2(v0096, v0056);
    nil = C_nil;
    if (exception_pending()) goto v0060;
    env = stack[-1];
    qvalue(elt(env, 2)) = v0056; /* indent */
    goto v0113;

v0113:
    v0056 = nil;
    { popv(2); return onevalue(v0056); }
/* error exit handlers */
v0060:
    popv(2);
    return nil;
}



/* Code for c!:ordexp */

static Lisp_Object CC_cTordexp(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0047)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0060, v0174, v0095, v0038;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for c:ordexp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0174 = v0047;
    v0095 = v0000;
/* end of prologue */

v0033:
    v0060 = v0095;
    if (v0060 == nil) goto v0101;
    v0060 = v0095;
    v0038 = qcar(v0060);
    v0060 = v0174;
    v0060 = qcar(v0060);
    if (equal(v0038, v0060)) goto v0110;
    v0060 = v0095;
    v0060 = qcar(v0060);
    v0174 = qcar(v0174);
    {
        fn = elt(env, 2); /* c!:ordxp */
        return (*qfn2(fn))(qenv(fn), v0060, v0174);
    }

v0110:
    v0060 = v0095;
    v0060 = qcdr(v0060);
    v0095 = v0060;
    v0060 = v0174;
    v0060 = qcdr(v0060);
    v0174 = v0060;
    goto v0033;

v0101:
    v0060 = qvalue(elt(env, 1)); /* t */
    return onevalue(v0060);
}



/* Code for downwght */

static Lisp_Object CC_downwght(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0047)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0063, v0064;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for downwght");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0047,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0047);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0047;
    stack[-1] = v0000;
/* end of prologue */
    v0063 = stack[-1];
    fn = elt(env, 1); /* delhisto */
    v0063 = (*qfn1(fn))(qenv(fn), v0063);
    nil = C_nil;
    if (exception_pending()) goto v0103;
    env = stack[-2];
    v0064 = stack[-1];
    v0063 = stack[0];
    fn = elt(env, 2); /* downwght1 */
    v0063 = (*qfn2(fn))(qenv(fn), v0064, v0063);
    nil = C_nil;
    if (exception_pending()) goto v0103;
    env = stack[-2];
    v0063 = stack[-1];
    {
        popv(3);
        fn = elt(env, 3); /* inshisto */
        return (*qfn1(fn))(qenv(fn), v0063);
    }
/* error exit handlers */
v0103:
    popv(3);
    return nil;
}



/* Code for vevtdeg */

static Lisp_Object CC_vevtdeg(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0104, v0036, v0115;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for vevtdeg");
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
    v0036 = nil;
    goto v0102;

v0102:
    v0104 = stack[0];
    if (v0104 == nil) goto v0097;
    v0104 = stack[0];
    v0104 = qcar(v0104);
    v0104 = cons(v0104, v0036);
    nil = C_nil;
    if (exception_pending()) goto v0157;
    env = stack[-1];
    v0036 = v0104;
    v0104 = stack[0];
    v0104 = qcdr(v0104);
    stack[0] = v0104;
    goto v0102;

v0097:
    v0104 = (Lisp_Object)1; /* 0 */
    goto v0101;

v0101:
    v0115 = v0036;
    if (v0115 == nil) { popv(2); return onevalue(v0104); }
    v0115 = v0036;
    v0115 = qcar(v0115);
    v0104 = (Lisp_Object)(int32_t)((int32_t)v0115 + (int32_t)v0104 - TAG_FIXNUM);
    v0036 = qcdr(v0036);
    goto v0101;
/* error exit handlers */
v0157:
    popv(2);
    return nil;
}



/* Code for find_item */

static Lisp_Object CC_find_item(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0047)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0180, v0111;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for find_item");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0047,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0047);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0047;
    stack[-1] = v0000;
/* end of prologue */

v0212:
    v0180 = stack[0];
    v0180 = qcdr(v0180);
    if (v0180 == nil) goto v0033;
    v0111 = stack[-1];
    v0180 = stack[0];
    v0180 = qcdr(v0180);
    v0180 = qcar(v0180);
    v0180 = CC_find_item(env, v0111, v0180);
    nil = C_nil;
    if (exception_pending()) goto v0175;
    env = stack[-2];
    if (!(v0180 == nil)) { popv(3); return onevalue(v0180); }
    v0180 = stack[0];
    v0111 = qcar(v0180);
    v0180 = stack[-1];
    if (equal(v0111, v0180)) goto v0048;
    v0180 = nil;
    goto v0057;

v0057:
    if (!(v0180 == nil)) { popv(3); return onevalue(v0180); }
    v0111 = stack[-1];
    v0180 = stack[0];
    v0180 = qcdr(v0180);
    v0180 = qcdr(v0180);
    stack[-1] = v0111;
    stack[0] = v0180;
    goto v0212;

v0048:
    v0180 = stack[0];
    goto v0057;

v0033:
    v0180 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v0180); }
/* error exit handlers */
v0175:
    popv(3);
    return nil;
}



/* Code for round!:last */

static Lisp_Object CC_roundTlast(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0207, v0213, v0204;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for round:last");
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
    v0213 = v0000;
/* end of prologue */
    v0207 = v0213;
    v0207 = qcdr(v0207);
    stack[0] = qcar(v0207);
    v0207 = v0213;
    v0207 = qcdr(v0207);
    v0207 = qcdr(v0207);
    v0213 = add1(v0207);
    nil = C_nil;
    if (exception_pending()) goto v0155;
    env = stack[-3];
    v0207 = qvalue(elt(env, 1)); /* nil */
    stack[-2] = stack[0];
    stack[-1] = v0213;
    stack[0] = v0207;
    v0213 = stack[-2];
    v0207 = (Lisp_Object)1; /* 0 */
    v0207 = (Lisp_Object)lessp2(v0213, v0207);
    nil = C_nil;
    if (exception_pending()) goto v0155;
    v0207 = v0207 ? lisp_true : nil;
    env = stack[-3];
    if (v0207 == nil) goto v0062;
    v0207 = stack[-2];
    v0207 = negate(v0207);
    nil = C_nil;
    if (exception_pending()) goto v0155;
    env = stack[-3];
    stack[-2] = v0207;
    v0207 = qvalue(elt(env, 2)); /* t */
    stack[0] = v0207;
    goto v0062;

v0062:
    v0207 = stack[-2];
    v0207 = Levenp(nil, v0207);
    env = stack[-3];
    if (v0207 == nil) goto v0056;
    v0213 = stack[-2];
    v0207 = (Lisp_Object)-15; /* -1 */
    fn = elt(env, 4); /* lshift */
    v0207 = (*qfn2(fn))(qenv(fn), v0213, v0207);
    nil = C_nil;
    if (exception_pending()) goto v0155;
    env = stack[-3];
    goto v0057;

v0057:
    stack[-2] = v0207;
    v0207 = stack[0];
    if (v0207 == nil) goto v0123;
    v0207 = stack[-2];
    v0207 = negate(v0207);
    nil = C_nil;
    if (exception_pending()) goto v0155;
    env = stack[-3];
    stack[-2] = v0207;
    goto v0123;

v0123:
    v0204 = elt(env, 3); /* !:rd!: */
    v0213 = stack[-2];
    v0207 = stack[-1];
    popv(4);
    return list2star(v0204, v0213, v0207);

v0056:
    v0213 = stack[-2];
    v0207 = (Lisp_Object)-15; /* -1 */
    fn = elt(env, 4); /* lshift */
    v0207 = (*qfn2(fn))(qenv(fn), v0213, v0207);
    nil = C_nil;
    if (exception_pending()) goto v0155;
    env = stack[-3];
    v0207 = add1(v0207);
    nil = C_nil;
    if (exception_pending()) goto v0155;
    env = stack[-3];
    goto v0057;
/* error exit handlers */
v0155:
    popv(4);
    return nil;
}



/* Code for lessp!: */

static Lisp_Object CC_lesspT(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0047)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0050, v0110;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for lessp:");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0110 = v0047;
    v0050 = v0000;
/* end of prologue */
    {
        fn = elt(env, 1); /* greaterp!: */
        return (*qfn2(fn))(qenv(fn), v0110, v0050);
    }
}



/* Code for !*collectphysops */

static Lisp_Object CC_Hcollectphysops(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0050, v0110;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for *collectphysops");
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
    v0050 = v0000;
/* end of prologue */
    v0110 = v0050;
    v0050 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 2); /* !*collectphysops_reversed */
    v0050 = (*qfn2(fn))(qenv(fn), v0110, v0050);
    errexit();
        return Lnreverse(nil, v0050);
}



/* Code for mo_compare */

static Lisp_Object CC_mo_compare(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0047)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0105, v0215, v0025;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mo_compare");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0047,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0047);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0047;
    stack[-1] = v0000;
/* end of prologue */
    v0105 = stack[-1];
    v0215 = qcdr(v0105);
    v0105 = stack[0];
    v0105 = qcdr(v0105);
    fn = elt(env, 3); /* mo!=degcomp */
    v0105 = (*qfn2(fn))(qenv(fn), v0215, v0105);
    nil = C_nil;
    if (exception_pending()) goto v0216;
    env = stack[-2];
    v0025 = v0105;
    v0215 = v0025;
    v0105 = (Lisp_Object)1; /* 0 */
    if (!(v0215 == v0105)) { popv(3); return onevalue(v0025); }
    v0105 = qvalue(elt(env, 1)); /* cali!=basering */
    fn = elt(env, 4); /* ring_tag */
    v0215 = (*qfn1(fn))(qenv(fn), v0105);
    nil = C_nil;
    if (exception_pending()) goto v0216;
    env = stack[-2];
    v0105 = elt(env, 2); /* revlex */
    if (v0215 == v0105) goto v0174;
    v0105 = stack[-1];
    v0215 = qcar(v0105);
    v0105 = stack[0];
    v0105 = qcar(v0105);
    fn = elt(env, 5); /* mo!=lexcomp */
    v0105 = (*qfn2(fn))(qenv(fn), v0215, v0105);
    nil = C_nil;
    if (exception_pending()) goto v0216;
    goto v0026;

v0026:
    v0025 = v0105;
    { popv(3); return onevalue(v0025); }

v0174:
    v0105 = stack[-1];
    v0215 = qcar(v0105);
    v0105 = stack[0];
    v0105 = qcar(v0105);
    fn = elt(env, 6); /* mo!=revlexcomp */
    v0105 = (*qfn2(fn))(qenv(fn), v0215, v0105);
    nil = C_nil;
    if (exception_pending()) goto v0216;
    goto v0026;
/* error exit handlers */
v0216:
    popv(3);
    return nil;
}



/* Code for insert_pv1 */

static Lisp_Object MS_CDECL CC_insert_pv1(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0089, v0090;
    Lisp_Object fn;
    Lisp_Object v0168, v0047, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "insert_pv1");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0047 = va_arg(aa, Lisp_Object);
    v0168 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for insert_pv1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0168,v0047,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0047,v0168);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0168;
    stack[-1] = v0047;
    stack[-2] = v0000;
/* end of prologue */

v0097:
    v0089 = stack[-1];
    if (v0089 == nil) goto v0052;
    v0089 = stack[-2];
    if (v0089 == nil) goto v0049;
    v0089 = stack[-1];
    v0089 = qcar(v0089);
    v0089 = qcar(v0089);
    v0090 = qcdr(v0089);
    v0089 = stack[-2];
    v0089 = qcar(v0089);
    v0089 = qcdr(v0089);
    v0089 = (Lisp_Object)greaterp2(v0090, v0089);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    v0089 = v0089 ? lisp_true : nil;
    env = stack[-4];
    if (v0089 == nil) goto v0179;
    v0089 = stack[-1];
    v0089 = qcdr(v0089);
    stack[-3] = v0089;
    v0089 = stack[-1];
    v0090 = qcar(v0089);
    v0089 = stack[-2];
    fn = elt(env, 2); /* reduce_pv */
    v0089 = (*qfn2(fn))(qenv(fn), v0090, v0089);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    env = stack[-4];
    fn = elt(env, 3); /* pv_renorm */
    v0090 = (*qfn1(fn))(qenv(fn), v0089);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    env = stack[-4];
    v0089 = stack[0];
    v0089 = cons(v0090, v0089);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    env = stack[-4];
    stack[0] = v0089;
    v0089 = stack[-3];
    stack[-1] = v0089;
    goto v0097;

v0179:
    v0089 = qvalue(elt(env, 1)); /* nil */
    stack[-3] = v0089;
    v0090 = stack[-2];
    v0089 = stack[0];
    v0089 = cons(v0090, v0089);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    env = stack[-4];
    stack[0] = v0089;
    v0089 = stack[-3];
    stack[-2] = v0089;
    goto v0097;

v0049:
    v0089 = qvalue(elt(env, 1)); /* nil */
    stack[-2] = v0089;
    v0089 = stack[-1];
    v0089 = qcdr(v0089);
    stack[-3] = v0089;
    v0089 = stack[-1];
    v0090 = qcar(v0089);
    v0089 = stack[0];
    v0089 = cons(v0090, v0089);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    env = stack[-4];
    stack[0] = v0089;
    v0089 = stack[-3];
    stack[-1] = v0089;
    goto v0097;

v0052:
    v0089 = stack[-2];
    if (v0089 == nil) goto v0063;
    v0090 = stack[-2];
    v0089 = stack[0];
    v0089 = cons(v0090, v0089);
    nil = C_nil;
    if (exception_pending()) goto v0199;
        popv(5);
        return Lnreverse(nil, v0089);

v0063:
    v0089 = stack[0];
        popv(5);
        return Lnreverse(nil, v0089);
/* error exit handlers */
v0199:
    popv(5);
    return nil;
}



/* Code for aronep!: */

static Lisp_Object CC_aronepT(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0050, v0110;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for aronep:");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0050 = v0000;
/* end of prologue */
    v0110 = qcdr(v0050);
    v0050 = (Lisp_Object)17; /* 1 */
    v0050 = (v0110 == v0050 ? lisp_true : nil);
    return onevalue(v0050);
}



/* Code for evaluate!-in!-order */

static Lisp_Object CC_evaluateKinKorder(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0047)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0172, v0091, v0207, v0213;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for evaluate-in-order");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0047,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0047);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0047;
    stack[-1] = v0000;
/* end of prologue */

v0033:
    v0172 = stack[-1];
    if (!consp(v0172)) goto v0110;
    v0172 = stack[-1];
    v0172 = qcar(v0172);
    v0172 = (consp(v0172) ? nil : lisp_true);
    goto v0050;

v0050:
    if (v0172 == nil) goto v0007;
    v0172 = stack[-1];
    {
        popv(3);
        fn = elt(env, 2); /* !*d2n */
        return (*qfn1(fn))(qenv(fn), v0172);
    }

v0007:
    v0172 = stack[-1];
    v0172 = qcar(v0172);
    v0172 = qcar(v0172);
    v0091 = qcar(v0172);
    v0172 = stack[0];
    v0172 = qcar(v0172);
    v0172 = qcar(v0172);
    if (equal(v0091, v0172)) goto v0037;
    v0172 = stack[0];
    v0172 = qcdr(v0172);
    stack[0] = v0172;
    goto v0033;

v0037:
    v0172 = stack[-1];
    v0172 = qcar(v0172);
    v0091 = qcdr(v0172);
    v0172 = stack[0];
    v0172 = qcdr(v0172);
    v0213 = CC_evaluateKinKorder(env, v0091, v0172);
    nil = C_nil;
    if (exception_pending()) goto v0023;
    env = stack[-2];
    v0172 = stack[-1];
    v0172 = qcar(v0172);
    v0172 = qcar(v0172);
    v0207 = qcdr(v0172);
    v0172 = stack[-1];
    v0091 = qcdr(v0172);
    v0172 = stack[0];
    {
        popv(3);
        fn = elt(env, 3); /* horner!-rule */
        return (*qfnn(fn))(qenv(fn), 4, v0213, v0207, v0091, v0172);
    }

v0110:
    v0172 = qvalue(elt(env, 1)); /* t */
    goto v0050;
/* error exit handlers */
v0023:
    popv(3);
    return nil;
}



/* Code for times!-in!-vector */

static Lisp_Object MS_CDECL CC_timesKinKvector(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0226, v0042, v0227, v0074, v0073, v0075, v0005, v0006, v0070, v0108, v0228, v0229, v0230, v0142, v0071;
    Lisp_Object v0190, v0178, v0168, v0047, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 5, "times-in-vector");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0047 = va_arg(aa, Lisp_Object);
    v0168 = va_arg(aa, Lisp_Object);
    v0178 = va_arg(aa, Lisp_Object);
    v0190 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for times-in-vector");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push5(v0190,v0178,v0168,v0047,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v0000,v0047,v0168,v0178,v0190);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v0108 = v0190;
    v0228 = v0178;
    v0229 = v0168;
    v0230 = v0047;
    v0142 = v0000;
/* end of prologue */
    v0042 = v0230;
    v0226 = (Lisp_Object)1; /* 0 */
    if (((int32_t)(v0042)) < ((int32_t)(v0226))) goto v0061;
    v0042 = v0228;
    v0226 = (Lisp_Object)1; /* 0 */
    if (((int32_t)(v0042)) < ((int32_t)(v0226))) goto v0061;
    v0042 = v0230;
    v0226 = v0228;
    v0226 = (Lisp_Object)(int32_t)((int32_t)v0042 + (int32_t)v0226 - TAG_FIXNUM);
    v0071 = v0226;
    v0226 = (Lisp_Object)1; /* 0 */
    v0074 = v0226;
    goto v0176;

v0176:
    v0042 = v0071;
    v0226 = v0074;
    v0226 = (Lisp_Object)(int32_t)((int32_t)v0042 - (int32_t)v0226 + TAG_FIXNUM);
    v0226 = ((intptr_t)(v0226) < 0 ? lisp_true : nil);
    if (v0226 == nil) goto v0094;
    v0226 = (Lisp_Object)1; /* 0 */
    v0006 = v0226;
    goto v0218;

v0218:
    v0042 = v0230;
    v0226 = v0006;
    v0226 = (Lisp_Object)(int32_t)((int32_t)v0042 - (int32_t)v0226 + TAG_FIXNUM);
    v0226 = ((intptr_t)(v0226) < 0 ? lisp_true : nil);
    if (!(v0226 == nil)) { popv(1); return onevalue(v0071); }
    v0042 = v0142;
    v0226 = v0006;
    v0226 = *(Lisp_Object *)((char *)v0042 + (CELL-TAG_VECTOR) + ((int32_t)v0226/(16/CELL)));
    v0070 = v0226;
    v0226 = (Lisp_Object)1; /* 0 */
    v0005 = v0226;
    goto v0231;

v0231:
    v0042 = v0228;
    v0226 = v0005;
    v0226 = (Lisp_Object)(int32_t)((int32_t)v0042 - (int32_t)v0226 + TAG_FIXNUM);
    v0226 = ((intptr_t)(v0226) < 0 ? lisp_true : nil);
    if (v0226 == nil) goto v0016;
    v0226 = v0006;
    v0226 = (Lisp_Object)((int32_t)(v0226) + 0x10);
    v0006 = v0226;
    goto v0218;

v0016:
    v0042 = v0006;
    v0226 = v0005;
    v0226 = (Lisp_Object)(int32_t)((int32_t)v0042 + (int32_t)v0226 - TAG_FIXNUM);
    v0075 = v0108;
    v0073 = v0226;
    v0042 = v0108;
    v0074 = *(Lisp_Object *)((char *)v0042 + (CELL-TAG_VECTOR) + ((int32_t)v0226/(16/CELL)));
    v0227 = v0070;
    v0042 = v0229;
    v0226 = v0005;
    v0226 = *(Lisp_Object *)((char *)v0042 + (CELL-TAG_VECTOR) + ((int32_t)v0226/(16/CELL)));
    v0226 = Lmodular_times(nil, v0227, v0226);
    env = stack[0];
    {   int32_t w = int_of_fixnum(v0074) + int_of_fixnum(v0226);
        if (w >= current_modulus) w -= current_modulus;
        v0226 = fixnum_of_int(w);
    }
    *(Lisp_Object *)((char *)v0075 + (CELL-TAG_VECTOR) + ((int32_t)v0073/(16/CELL))) = v0226;
    v0226 = v0005;
    v0226 = (Lisp_Object)((int32_t)(v0226) + 0x10);
    v0005 = v0226;
    goto v0231;

v0094:
    v0227 = v0108;
    v0042 = v0074;
    v0226 = (Lisp_Object)1; /* 0 */
    *(Lisp_Object *)((char *)v0227 + (CELL-TAG_VECTOR) + ((int32_t)v0042/(16/CELL))) = v0226;
    v0226 = v0074;
    v0226 = (Lisp_Object)((int32_t)(v0226) + 0x10);
    v0074 = v0226;
    goto v0176;

v0061:
    v0226 = (Lisp_Object)-15; /* -1 */
    { popv(1); return onevalue(v0226); }
}



/* Code for lalr_action */

static Lisp_Object CC_lalr_action(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0047)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0103, v0028, v0027;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for lalr_action");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0047,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0047);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0028 = v0047;
    v0103 = v0000;
/* end of prologue */
    v0027 = v0028;
    v0028 = v0103;
    v0103 = elt(env, 1); /* produces */
    v0103 = get(v0028, v0103);
    v0103 = Lassoc(nil, v0027, v0103);
    v0103 = qcdr(v0103);
    return onevalue(v0103);
}



/* Code for anform */

static Lisp_Object CC_anform(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0083, v0179;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for anform");
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
    v0083 = stack[0];
    if (!consp(v0083)) goto v0190;
    v0083 = stack[0];
    {
        popv(2);
        fn = elt(env, 6); /* anform1 */
        return (*qfn1(fn))(qenv(fn), v0083);
    }

v0190:
    v0083 = qvalue(elt(env, 1)); /* !*globals */
    if (v0083 == nil) goto v0052;
    v0083 = stack[0];
    if (v0083 == nil) goto v0052;
    v0179 = stack[0];
    v0083 = lisp_true;
    if (v0179 == v0083) goto v0115;
    v0083 = stack[0];
    if (symbolp(v0083)) goto v0056;
    v0083 = qvalue(elt(env, 2)); /* nil */
    goto v0161;

v0161:
    if (v0083 == nil) goto v0052;
    v0179 = stack[0];
    v0083 = elt(env, 4); /* glb2rf */
    v0083 = Lflagp(nil, v0179, v0083);
    env = stack[-1];
    if (v0083 == nil) goto v0123;
    v0083 = nil;
    { popv(2); return onevalue(v0083); }

v0123:
    v0083 = stack[0];
    v0179 = ncons(v0083);
    nil = C_nil;
    if (exception_pending()) goto v0173;
    env = stack[-1];
    v0083 = elt(env, 4); /* glb2rf */
    v0083 = Lflag(nil, v0179, v0083);
    nil = C_nil;
    if (exception_pending()) goto v0173;
    env = stack[-1];
    v0179 = stack[0];
    v0083 = qvalue(elt(env, 5)); /* globs!* */
    v0083 = cons(v0179, v0083);
    nil = C_nil;
    if (exception_pending()) goto v0173;
    env = stack[-1];
    qvalue(elt(env, 5)) = v0083; /* globs!* */
    { popv(2); return onevalue(v0083); }

v0052:
    v0083 = nil;
    { popv(2); return onevalue(v0083); }

v0056:
    v0179 = stack[0];
    v0083 = qvalue(elt(env, 3)); /* locls!* */
    v0083 = Lassoc(nil, v0179, v0083);
    v0083 = (v0083 == nil ? lisp_true : nil);
    goto v0161;

v0115:
    v0083 = qvalue(elt(env, 2)); /* nil */
    goto v0161;
/* error exit handlers */
v0173:
    popv(2);
    return nil;
}



/* Code for sfto_dcontentf1 */

static Lisp_Object CC_sfto_dcontentf1(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0047)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0114, v0039, v0093;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sfto_dcontentf1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0047,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0047);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0047;
    v0039 = v0000;
/* end of prologue */

v0050:
    v0093 = stack[0];
    v0114 = (Lisp_Object)17; /* 1 */
    if (v0093 == v0114) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v0114 = v0039;
    if (!consp(v0114)) goto v0034;
    v0114 = v0039;
    v0114 = qcar(v0114);
    v0114 = (consp(v0114) ? nil : lisp_true);
    goto v0029;

v0029:
    if (v0114 == nil) goto v0095;
    v0114 = v0039;
    fn = elt(env, 2); /* absf */
    v0039 = (*qfn1(fn))(qenv(fn), v0114);
    nil = C_nil;
    if (exception_pending()) goto v0123;
    env = stack[-2];
    v0114 = stack[0];
    {
        popv(3);
        fn = elt(env, 3); /* sfto_gcdf */
        return (*qfn2(fn))(qenv(fn), v0039, v0114);
    }

v0095:
    v0114 = v0039;
    v0114 = qcdr(v0114);
    stack[-1] = v0114;
    v0114 = v0039;
    v0114 = qcar(v0114);
    v0039 = qcdr(v0114);
    v0114 = stack[0];
    v0114 = CC_sfto_dcontentf1(env, v0039, v0114);
    nil = C_nil;
    if (exception_pending()) goto v0123;
    env = stack[-2];
    stack[0] = v0114;
    v0114 = stack[-1];
    v0039 = v0114;
    goto v0050;

v0034:
    v0114 = qvalue(elt(env, 1)); /* t */
    goto v0029;
/* error exit handlers */
v0123:
    popv(3);
    return nil;
}



/* Code for polynomadd */

static Lisp_Object CC_polynomadd(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0047)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0078, v0079, v0077;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for polynomadd");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0047,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0047);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    v0079 = v0047;
    stack[-2] = v0000;
/* end of prologue */
    v0078 = stack[-2];
    stack[-3] = v0078;
    v0078 = v0079;
    stack[-1] = v0078;
    goto v0061;

v0061:
    v0078 = stack[-3];
    v0078 = qcar(v0078);
    if (v0078 == nil) goto v0110;
    v0078 = stack[-1];
    v0078 = qcar(v0078);
    if (v0078 == nil) goto v0110;
    v0078 = stack[-3];
    v0079 = qcar(v0078);
    v0078 = stack[-1];
    v0078 = qcar(v0078);
    fn = elt(env, 2); /* monomcompare */
    v0078 = (*qfn2(fn))(qenv(fn), v0079, v0078);
    nil = C_nil;
    if (exception_pending()) goto v0046;
    env = stack[-4];
    v0077 = v0078;
    v0079 = v0077;
    v0078 = (Lisp_Object)17; /* 1 */
    if (v0079 == v0078) goto v0096;
    v0079 = v0077;
    v0078 = (Lisp_Object)-15; /* -1 */
    if (v0079 == v0078) goto v0024;
    v0079 = stack[-3];
    v0078 = stack[-3];
    v0078 = qcdr(v0078);
    v0078 = qcar(v0078);
    v0079 = Lrplaca(nil, v0079, v0078);
    nil = C_nil;
    if (exception_pending()) goto v0046;
    env = stack[-4];
    v0078 = stack[-3];
    v0078 = qcdr(v0078);
    v0078 = qcdr(v0078);
    v0078 = Lrplacd(nil, v0079, v0078);
    nil = C_nil;
    if (exception_pending()) goto v0046;
    env = stack[-4];
    v0078 = stack[-1];
    v0078 = qcdr(v0078);
    stack[-1] = v0078;
    goto v0061;

v0024:
    stack[0] = stack[-3];
    v0078 = stack[-3];
    v0079 = qcar(v0078);
    v0078 = stack[-3];
    v0078 = qcdr(v0078);
    v0078 = cons(v0079, v0078);
    nil = C_nil;
    if (exception_pending()) goto v0046;
    env = stack[-4];
    v0079 = Lrplacd(nil, stack[0], v0078);
    nil = C_nil;
    if (exception_pending()) goto v0046;
    env = stack[-4];
    v0078 = stack[-1];
    v0078 = qcar(v0078);
    v0078 = Lrplaca(nil, v0079, v0078);
    nil = C_nil;
    if (exception_pending()) goto v0046;
    env = stack[-4];
    v0078 = stack[-3];
    v0078 = qcdr(v0078);
    stack[-3] = v0078;
    v0078 = stack[-1];
    v0078 = qcdr(v0078);
    stack[-1] = v0078;
    goto v0061;

v0096:
    v0078 = stack[-3];
    v0078 = qcdr(v0078);
    stack[-3] = v0078;
    goto v0061;

v0110:
    v0078 = stack[-1];
    v0078 = qcar(v0078);
    if (v0078 == nil) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v0079 = stack[-3];
    v0078 = stack[-1];
    v0078 = Lrplacd(nil, v0079, v0078);
    nil = C_nil;
    if (exception_pending()) goto v0046;
    env = stack[-4];
    stack[0] = v0078;
    v0079 = stack[0];
    v0078 = stack[0];
    v0078 = qcdr(v0078);
    v0078 = qcar(v0078);
    v0079 = Lrplaca(nil, v0079, v0078);
    nil = C_nil;
    if (exception_pending()) goto v0046;
    env = stack[-4];
    v0078 = stack[0];
    v0078 = qcdr(v0078);
    v0078 = qcdr(v0078);
    v0078 = Lrplacd(nil, v0079, v0078);
    nil = C_nil;
    if (exception_pending()) goto v0046;
    { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
/* error exit handlers */
v0046:
    popv(5);
    return nil;
}



/* Code for get!-print!-name */

static Lisp_Object CC_getKprintKname(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0064, v0058;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for get-print-name");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0058 = v0000;
/* end of prologue */
    v0064 = v0058;
    if (symbolp(v0064)) goto v0050;
    v0064 = qvalue(elt(env, 1)); /* nil */
    goto v0102;

v0102:
    if (v0064 == nil) return onevalue(v0058);
    else return onevalue(v0064);

v0050:
    v0064 = v0058;
    if (!symbolp(v0064)) v0064 = nil;
    else { v0064 = qfastgets(v0064);
           if (v0064 != nil) { v0064 = elt(v0064, 12); /* oldnam */
#ifdef RECORD_GET
             if (v0064 != SPID_NOPROP)
                record_get(elt(fastget_names, 12), 1);
             else record_get(elt(fastget_names, 12), 0),
                v0064 = nil; }
           else record_get(elt(fastget_names, 12), 0); }
#else
             if (v0064 == SPID_NOPROP) v0064 = nil; }}
#endif
    goto v0102;
}



/* Code for xxsort */

static Lisp_Object CC_xxsort(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0052, v0050;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for xxsort");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0052 = v0000;
/* end of prologue */
    v0050 = v0052;
    v0052 = elt(env, 1); /* lambda_idn438f46io4 */
    {
        fn = elt(env, 2); /* sort */
        return (*qfn2(fn))(qenv(fn), v0050, v0052);
    }
}



/* Code for lambda_idn438f46io4 */

static Lisp_Object CC_lambda_idn438f46io4(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0047)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0028, v0027;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for lambda_idn438f46io4");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0047,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0047);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0028 = v0047;
    v0027 = v0000;
/* end of prologue */
    v0027 = qcar(v0027);
    v0028 = qcar(v0028);
    fn = elt(env, 1); /* termorder */
    v0027 = (*qfn2(fn))(qenv(fn), v0027, v0028);
    errexit();
    v0028 = (Lisp_Object)1; /* 0 */
        return Llessp(nil, v0027, v0028);
}



/* Code for aex_mk */

static Lisp_Object CC_aex_mk(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0047)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0062, v0063, v0064;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for aex_mk");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0062 = v0047;
    v0063 = v0000;
/* end of prologue */
    v0064 = elt(env, 1); /* aex */
    return list3(v0064, v0063, v0062);
}



/* Code for multi_isarb_compl */

static Lisp_Object CC_multi_isarb_compl(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0007;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for multi_isarb_compl");
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
    v0007 = stack[0];
    v0007 = Lconsp(nil, v0007);
    env = stack[-1];
    if (v0007 == nil) goto v0033;
    v0007 = stack[0];
    if (v0007 == nil) goto v0033;
    v0007 = stack[0];
    v0007 = qcar(v0007);
    fn = elt(env, 2); /* isarb_compl */
    v0007 = (*qfn1(fn))(qenv(fn), v0007);
    nil = C_nil;
    if (exception_pending()) goto v0004;
    env = stack[-1];
    v0007 = stack[0];
    v0007 = qcdr(v0007);
    v0007 = CC_multi_isarb_compl(env, v0007);
    nil = C_nil;
    if (exception_pending()) goto v0004;
    goto v0033;

v0033:
    v0007 = nil;
    { popv(2); return onevalue(v0007); }
/* error exit handlers */
v0004:
    popv(2);
    return nil;
}



/* Code for minus!: */

static Lisp_Object CC_minusT(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0161, v0103;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for minus:");
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
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0000;
/* end of prologue */
    stack[-1] = elt(env, 1); /* !:rd!: */
    v0161 = stack[0];
    v0161 = qcdr(v0161);
    v0161 = qcar(v0161);
    v0103 = negate(v0161);
    nil = C_nil;
    if (exception_pending()) goto v0029;
    v0161 = stack[0];
    v0161 = qcdr(v0161);
    v0161 = qcdr(v0161);
    {
        Lisp_Object v0034 = stack[-1];
        popv(2);
        return list2star(v0034, v0103, v0161);
    }
/* error exit handlers */
v0029:
    popv(2);
    return nil;
}



/* Code for depends */

static Lisp_Object CC_depends(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0047)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0141, v0001, v0068;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for depends");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0047,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0047);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0047;
    stack[-1] = v0000;
/* end of prologue */
    v0141 = stack[-1];
    if (v0141 == nil) goto v0051;
    v0141 = stack[-1];
    v0141 = (is_number(v0141) ? lisp_true : nil);
    if (!(v0141 == nil)) goto v0101;
    v0141 = stack[0];
    v0141 = (is_number(v0141) ? lisp_true : nil);
    goto v0101;

v0101:
    if (v0141 == nil) goto v0007;
    v0141 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v0141); }

v0007:
    v0001 = stack[-1];
    v0141 = stack[0];
    if (equal(v0001, v0141)) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v0141 = stack[-1];
    if (!consp(v0141)) goto v0174;
    v0141 = qvalue(elt(env, 2)); /* nil */
    goto v0056;

v0056:
    if (v0141 == nil) goto v0158;
    v0141 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v0141); }

v0158:
    v0001 = stack[-1];
    v0141 = qvalue(elt(env, 4)); /* depl!* */
    v0141 = Lassoc(nil, v0001, v0141);
    v0001 = v0141;
    v0141 = v0001;
    if (v0141 == nil) goto v0024;
    v0141 = v0001;
    v0001 = qcdr(v0141);
    v0141 = stack[0];
    fn = elt(env, 6); /* ldepends */
    v0141 = (*qfn2(fn))(qenv(fn), v0001, v0141);
    nil = C_nil;
    if (exception_pending()) goto v0003;
    env = stack[-2];
    goto v0025;

v0025:
    if (v0141 == nil) goto v0232;
    v0141 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v0141); }

v0232:
    v0141 = stack[-1];
    if (!consp(v0141)) goto v0199;
    v0141 = stack[-1];
    v0141 = qcar(v0141);
    if (symbolp(v0141)) goto v0090;
    v0141 = qvalue(elt(env, 2)); /* nil */
    goto v0173;

v0173:
    if (v0141 == nil) goto v0179;
    v0141 = stack[-1];
    v0001 = qcar(v0141);
    v0141 = elt(env, 5); /* domain!-depends!-fn */
    v0141 = get(v0001, v0141);
    env = stack[-2];
    v0001 = v0141;
    v0141 = v0001;
    if (v0141 == nil) goto v0240;
    v0068 = v0001;
    v0001 = stack[-1];
    v0141 = stack[0];
        popv(3);
        return Lapply2(nil, 3, v0068, v0001, v0141);

v0240:
    v0141 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v0141); }

v0179:
    v0141 = stack[-1];
    if (!consp(v0141)) goto v0143;
    v0141 = stack[-1];
    v0001 = qcdr(v0141);
    v0141 = stack[0];
    fn = elt(env, 6); /* ldepends */
    v0141 = (*qfn2(fn))(qenv(fn), v0001, v0141);
    nil = C_nil;
    if (exception_pending()) goto v0003;
    env = stack[-2];
    if (!(v0141 == nil)) goto v0044;
    v0141 = stack[-1];
    v0001 = qcar(v0141);
    v0141 = stack[0];
    v0141 = CC_depends(env, v0001, v0141);
    nil = C_nil;
    if (exception_pending()) goto v0003;
    env = stack[-2];
    goto v0044;

v0044:
    if (v0141 == nil) goto v0150;
    v0141 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v0141); }

v0150:
    v0141 = stack[0];
    if (!consp(v0141)) goto v0226;
    v0141 = stack[0];
    v0141 = qcar(v0141);
    if (symbolp(v0141)) goto v0142;
    v0141 = qvalue(elt(env, 2)); /* nil */
    goto v0144;

v0144:
    if (v0141 == nil) goto v0241;
    v0141 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v0141); }

v0241:
    v0141 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v0141); }

v0142:
    v0141 = stack[0];
    v0141 = qcar(v0141);
    if (!symbolp(v0141)) v0141 = nil;
    else { v0141 = qfastgets(v0141);
           if (v0141 != nil) { v0141 = elt(v0141, 8); /* dname */
#ifdef RECORD_GET
             if (v0141 != SPID_NOPROP)
                record_get(elt(fastget_names, 8), 1);
             else record_get(elt(fastget_names, 8), 0),
                v0141 = nil; }
           else record_get(elt(fastget_names, 8), 0); }
#else
             if (v0141 == SPID_NOPROP) v0141 = nil; }}
#endif
    goto v0144;

v0226:
    v0141 = qvalue(elt(env, 1)); /* t */
    goto v0144;

v0143:
    v0141 = qvalue(elt(env, 2)); /* nil */
    goto v0044;

v0090:
    v0141 = stack[-1];
    v0141 = qcar(v0141);
    if (!symbolp(v0141)) v0141 = nil;
    else { v0141 = qfastgets(v0141);
           if (v0141 != nil) { v0141 = elt(v0141, 8); /* dname */
#ifdef RECORD_GET
             if (v0141 != SPID_NOPROP)
                record_get(elt(fastget_names, 8), 1);
             else record_get(elt(fastget_names, 8), 0),
                v0141 = nil; }
           else record_get(elt(fastget_names, 8), 0); }
#else
             if (v0141 == SPID_NOPROP) v0141 = nil; }}
#endif
    goto v0173;

v0199:
    v0141 = qvalue(elt(env, 2)); /* nil */
    goto v0173;

v0024:
    v0141 = qvalue(elt(env, 2)); /* nil */
    goto v0025;

v0174:
    v0001 = stack[-1];
    v0141 = qvalue(elt(env, 3)); /* frlis!* */
    v0141 = Lmemq(nil, v0001, v0141);
    goto v0056;

v0051:
    v0141 = qvalue(elt(env, 1)); /* t */
    goto v0101;
/* error exit handlers */
v0003:
    popv(3);
    return nil;
}



/* Code for prepf1a_reversed */

static Lisp_Object MS_CDECL CC_prepf1a_reversed(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0240, v0244, v0014;
    Lisp_Object fn;
    Lisp_Object v0168, v0047, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "prepf1a_reversed");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0047 = va_arg(aa, Lisp_Object);
    v0168 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for prepf1a_reversed");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0168,v0047,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0047,v0168);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0168;
    stack[-1] = v0047;
    stack[-2] = v0000;
/* end of prologue */

v0102:
    v0240 = stack[-2];
    if (v0240 == nil) { Lisp_Object res = stack[0]; popv(5); return onevalue(res); }
    v0240 = stack[-2];
    if (!consp(v0240)) goto v0058;
    v0240 = stack[-2];
    v0240 = qcar(v0240);
    v0240 = (consp(v0240) ? nil : lisp_true);
    goto v0064;

v0064:
    if (v0240 == nil) goto v0154;
    v0240 = stack[-2];
    fn = elt(env, 5); /* prepd */
    stack[-2] = (*qfn1(fn))(qenv(fn), v0240);
    nil = C_nil;
    if (exception_pending()) goto v0043;
    env = stack[-4];
    v0240 = stack[-1];
    fn = elt(env, 6); /* exchk */
    v0240 = (*qfn1(fn))(qenv(fn), v0240);
    nil = C_nil;
    if (exception_pending()) goto v0043;
    env = stack[-4];
    v0240 = cons(stack[-2], v0240);
    nil = C_nil;
    if (exception_pending()) goto v0043;
    env = stack[-4];
    fn = elt(env, 7); /* retimes */
    v0240 = (*qfn1(fn))(qenv(fn), v0240);
    nil = C_nil;
    if (exception_pending()) goto v0043;
    env = stack[-4];
    v0014 = v0240;
    v0244 = v0014;
    v0240 = elt(env, 2); /* plus */
    if (!consp(v0244)) goto v0218;
    v0244 = qcar(v0244);
    if (!(v0244 == v0240)) goto v0218;
    v0240 = v0014;
    v0240 = qcdr(v0240);
    stack[-1] = v0240;
    goto v0175;

v0175:
    v0240 = stack[-1];
    if (v0240 == nil) { Lisp_Object res = stack[0]; popv(5); return onevalue(res); }
    v0240 = stack[-1];
    v0240 = qcar(v0240);
    v0244 = v0240;
    v0240 = stack[0];
    v0240 = cons(v0244, v0240);
    nil = C_nil;
    if (exception_pending()) goto v0043;
    env = stack[-4];
    stack[0] = v0240;
    v0240 = stack[-1];
    v0240 = qcdr(v0240);
    stack[-1] = v0240;
    goto v0175;

v0218:
    v0244 = v0014;
    v0240 = stack[0];
    v0240 = cons(v0244, v0240);
    nil = C_nil;
    if (exception_pending()) goto v0043;
    stack[0] = v0240;
    { Lisp_Object res = stack[0]; popv(5); return onevalue(res); }

v0154:
    v0240 = stack[-2];
    v0240 = qcar(v0240);
    stack[-3] = qcdr(v0240);
    v0240 = stack[-2];
    v0240 = qcar(v0240);
    v0240 = qcar(v0240);
    v0244 = qcar(v0240);
    v0240 = elt(env, 4); /* k!* */
    if (v0244 == v0240) goto v0200;
    v0240 = stack[-2];
    v0240 = qcar(v0240);
    v0244 = qcar(v0240);
    v0240 = stack[-1];
    v0240 = cons(v0244, v0240);
    nil = C_nil;
    if (exception_pending()) goto v0043;
    env = stack[-4];
    v0244 = v0240;
    goto v0245;

v0245:
    v0240 = stack[0];
    v0240 = CC_prepf1a_reversed(env, 3, stack[-3], v0244, v0240);
    nil = C_nil;
    if (exception_pending()) goto v0043;
    env = stack[-4];
    stack[0] = v0240;
    v0240 = stack[-2];
    v0240 = qcdr(v0240);
    stack[-2] = v0240;
    goto v0102;

v0200:
    v0240 = stack[-1];
    v0244 = v0240;
    goto v0245;

v0058:
    v0240 = qvalue(elt(env, 1)); /* t */
    goto v0064;
/* error exit handlers */
v0043:
    popv(5);
    return nil;
}



/* Code for rd!:onep */

static Lisp_Object CC_rdTonep(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0056, v0096;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rd:onep");
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
    v0056 = v0000;
/* end of prologue */
    v0096 = v0056;
    v0096 = qcdr(v0096);
    if (!consp(v0096)) goto v0064;
    stack[0] = qvalue(elt(env, 3)); /* bfone!* */
    fn = elt(env, 4); /* bftrim!: */
    v0056 = (*qfn1(fn))(qenv(fn), v0056);
    nil = C_nil;
    if (exception_pending()) goto v0060;
    env = stack[-1];
    {
        Lisp_Object v0174 = stack[0];
        popv(2);
        fn = elt(env, 5); /* equal!: */
        return (*qfn2(fn))(qenv(fn), v0174, v0056);
    }

v0064:
    v0096 = elt(env, 1); /* 1.0 */
    v0056 = qcdr(v0056);
    v0056 = difference2(v0096, v0056);
    nil = C_nil;
    if (exception_pending()) goto v0060;
    env = stack[-1];
    v0056 = Labsval(nil, v0056);
    nil = C_nil;
    if (exception_pending()) goto v0060;
    env = stack[-1];
    v0096 = qvalue(elt(env, 2)); /* !!fleps1 */
        popv(2);
        return Llessp(nil, v0056, v0096);
/* error exit handlers */
v0060:
    popv(2);
    return nil;
}



/* Code for groebsearchinlist */

static Lisp_Object CC_groebsearchinlist(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0047)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0049, v0053;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for groebsearchinlist");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0047,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0047);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0047;
    stack[-1] = v0000;
/* end of prologue */

v0033:
    v0049 = stack[0];
    if (v0049 == nil) goto v0101;
    v0049 = stack[0];
    v0049 = qcar(v0049);
    v0049 = qcdr(v0049);
    v0053 = qcar(v0049);
    v0049 = stack[-1];
    fn = elt(env, 2); /* buchvevdivides!? */
    v0049 = (*qfn2(fn))(qenv(fn), v0053, v0049);
    nil = C_nil;
    if (exception_pending()) goto v0035;
    env = stack[-2];
    if (v0049 == nil) goto v0004;
    v0049 = stack[0];
    v0049 = qcar(v0049);
    { popv(3); return onevalue(v0049); }

v0004:
    v0049 = stack[0];
    v0049 = qcdr(v0049);
    stack[0] = v0049;
    goto v0033;

v0101:
    v0049 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v0049); }
/* error exit handlers */
v0035:
    popv(3);
    return nil;
}



/* Code for int!-equiv!-chk */

static Lisp_Object CC_intKequivKchk(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0169, v0245, v0089;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for int-equiv-chk");
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
    v0169 = qvalue(elt(env, 1)); /* !*noequiv */
    if (!(v0169 == nil)) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v0169 = stack[0];
    if (!consp(v0169)) goto v0029;
    v0169 = stack[0];
    v0169 = qcar(v0169);
    if (!symbolp(v0169)) v0245 = nil;
    else { v0245 = qfastgets(v0169);
           if (v0245 != nil) { v0245 = elt(v0245, 15); /* zerop */
#ifdef RECORD_GET
             if (v0245 != SPID_NOPROP)
                record_get(elt(fastget_names, 15), 1);
             else record_get(elt(fastget_names, 15), 0),
                v0245 = nil; }
           else record_get(elt(fastget_names, 15), 0); }
#else
             if (v0245 == SPID_NOPROP) v0245 = nil; }}
#endif
    v0169 = stack[0];
    v0169 = Lapply1(nil, v0245, v0169);
    nil = C_nil;
    if (exception_pending()) goto v0020;
    env = stack[-1];
    if (v0169 == nil) goto v0176;
    v0169 = qvalue(elt(env, 2)); /* nil */
    { popv(2); return onevalue(v0169); }

v0176:
    v0169 = stack[0];
    v0169 = qcar(v0169);
    if (!symbolp(v0169)) v0245 = nil;
    else { v0245 = qfastgets(v0169);
           if (v0245 != nil) { v0245 = elt(v0245, 26); /* onep */
#ifdef RECORD_GET
             if (v0245 != SPID_NOPROP)
                record_get(elt(fastget_names, 26), 1);
             else record_get(elt(fastget_names, 26), 0),
                v0245 = nil; }
           else record_get(elt(fastget_names, 26), 0); }
#else
             if (v0245 == SPID_NOPROP) v0245 = nil; }}
#endif
    v0169 = stack[0];
    v0169 = Lapply1(nil, v0245, v0169);
    nil = C_nil;
    if (exception_pending()) goto v0020;
    env = stack[-1];
    if (v0169 == nil) goto v0157;
    v0169 = (Lisp_Object)17; /* 1 */
    { popv(2); return onevalue(v0169); }

v0157:
    v0169 = stack[0];
    v0169 = qcar(v0169);
    if (!symbolp(v0169)) v0169 = nil;
    else { v0169 = qfastgets(v0169);
           if (v0169 != nil) { v0169 = elt(v0169, 33); /* intequivfn */
#ifdef RECORD_GET
             if (v0169 != SPID_NOPROP)
                record_get(elt(fastget_names, 33), 1);
             else record_get(elt(fastget_names, 33), 0),
                v0169 = nil; }
           else record_get(elt(fastget_names, 33), 0); }
#else
             if (v0169 == SPID_NOPROP) v0169 = nil; }}
#endif
    v0089 = v0169;
    if (v0169 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v0245 = v0089;
    v0169 = stack[0];
    v0169 = Lapply1(nil, v0245, v0169);
    nil = C_nil;
    if (exception_pending()) goto v0020;
    env = stack[-1];
    v0089 = v0169;
    if (v0169 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v0245 = v0089;
    v0169 = (Lisp_Object)1; /* 0 */
    if (!(v0245 == v0169)) { popv(2); return onevalue(v0089); }
    v0169 = qvalue(elt(env, 2)); /* nil */
    { popv(2); return onevalue(v0169); }

v0029:
    v0245 = stack[0];
    v0169 = (Lisp_Object)1; /* 0 */
    if (!(v0245 == v0169)) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v0169 = qvalue(elt(env, 2)); /* nil */
    { popv(2); return onevalue(v0169); }
/* error exit handlers */
v0020:
    popv(2);
    return nil;
}



/* Code for getrmacro */

static Lisp_Object CC_getrmacro(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0024, v0163, v0216;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for getrmacro");
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
    v0024 = stack[0];
    if (symbolp(v0024)) goto v0101;
    v0024 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v0024); }

v0101:
    v0024 = stack[0];
    fn = elt(env, 5); /* getd */
    v0024 = (*qfn1(fn))(qenv(fn), v0024);
    nil = C_nil;
    if (exception_pending()) goto v0172;
    env = stack[-1];
    v0216 = v0024;
    if (v0024 == nil) goto v0057;
    v0024 = v0216;
    v0163 = qcar(v0024);
    v0024 = elt(env, 2); /* macro */
    if (v0163 == v0024) { popv(2); return onevalue(v0216); }
    else goto v0057;

v0057:
    v0163 = stack[0];
    v0024 = elt(env, 3); /* inline */
    v0024 = get(v0163, v0024);
    env = stack[-1];
    v0216 = v0024;
    if (v0024 == nil) goto v0157;
    v0024 = elt(env, 3); /* inline */
    v0163 = v0216;
    popv(2);
    return cons(v0024, v0163);

v0157:
    v0163 = stack[0];
    v0024 = elt(env, 4); /* smacro */
    v0024 = get(v0163, v0024);
    env = stack[-1];
    v0216 = v0024;
    if (v0024 == nil) goto v0105;
    v0024 = elt(env, 4); /* smacro */
    v0163 = v0216;
    popv(2);
    return cons(v0024, v0163);

v0105:
    v0024 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v0024); }
/* error exit handlers */
v0172:
    popv(2);
    return nil;
}



/* Code for dp_term */

static Lisp_Object CC_dp_term(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0047)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0050, v0110;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dp_term");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0050 = v0047;
    v0110 = v0000;
/* end of prologue */
    return cons(v0050, v0110);
}



/* Code for pv_applp */

static Lisp_Object CC_pv_applp(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0047)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0022, v0155;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pv_applp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0047,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0047);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-4] = v0047;
    v0022 = v0000;
/* end of prologue */
    stack[-5] = v0022;
    v0022 = stack[-5];
    if (v0022 == nil) goto v0061;
    v0022 = stack[-5];
    v0022 = qcar(v0022);
    v0155 = v0022;
    v0022 = v0155;
    stack[0] = qcar(v0022);
    v0022 = v0155;
    v0155 = qcdr(v0022);
    v0022 = stack[-4];
    fn = elt(env, 2); /* pappl0 */
    v0022 = (*qfn2(fn))(qenv(fn), v0155, v0022);
    nil = C_nil;
    if (exception_pending()) goto v0173;
    env = stack[-6];
    v0022 = cons(stack[0], v0022);
    nil = C_nil;
    if (exception_pending()) goto v0173;
    env = stack[-6];
    v0022 = ncons(v0022);
    nil = C_nil;
    if (exception_pending()) goto v0173;
    env = stack[-6];
    stack[-2] = v0022;
    stack[-3] = v0022;
    goto v0051;

v0051:
    v0022 = stack[-5];
    v0022 = qcdr(v0022);
    stack[-5] = v0022;
    v0022 = stack[-5];
    if (v0022 == nil) goto v0038;
    stack[-1] = stack[-2];
    v0022 = stack[-5];
    v0022 = qcar(v0022);
    v0155 = v0022;
    v0022 = v0155;
    stack[0] = qcar(v0022);
    v0022 = v0155;
    v0155 = qcdr(v0022);
    v0022 = stack[-4];
    fn = elt(env, 2); /* pappl0 */
    v0022 = (*qfn2(fn))(qenv(fn), v0155, v0022);
    nil = C_nil;
    if (exception_pending()) goto v0173;
    env = stack[-6];
    v0022 = cons(stack[0], v0022);
    nil = C_nil;
    if (exception_pending()) goto v0173;
    env = stack[-6];
    v0022 = ncons(v0022);
    nil = C_nil;
    if (exception_pending()) goto v0173;
    env = stack[-6];
    v0022 = Lrplacd(nil, stack[-1], v0022);
    nil = C_nil;
    if (exception_pending()) goto v0173;
    env = stack[-6];
    v0022 = stack[-2];
    v0022 = qcdr(v0022);
    stack[-2] = v0022;
    goto v0051;

v0038:
    v0022 = stack[-3];
    goto v0101;

v0101:
    {
        popv(7);
        fn = elt(env, 3); /* pv_sort */
        return (*qfn1(fn))(qenv(fn), v0022);
    }

v0061:
    v0022 = qvalue(elt(env, 1)); /* nil */
    goto v0101;
/* error exit handlers */
v0173:
    popv(7);
    return nil;
}



/* Code for mkrn */

static Lisp_Object CC_mkrn(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0047)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0093, v0094;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mkrn");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0047,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0047);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0047;
    stack[-2] = v0000;
/* end of prologue */

v0050:
    v0094 = stack[-1];
    v0093 = (Lisp_Object)1; /* 0 */
    v0093 = (Lisp_Object)lessp2(v0094, v0093);
    nil = C_nil;
    if (exception_pending()) goto v0025;
    v0093 = v0093 ? lisp_true : nil;
    env = stack[-4];
    if (v0093 == nil) goto v0007;
    v0093 = stack[-2];
    v0093 = negate(v0093);
    nil = C_nil;
    if (exception_pending()) goto v0025;
    env = stack[-4];
    stack[-2] = v0093;
    v0093 = stack[-1];
    v0093 = negate(v0093);
    nil = C_nil;
    if (exception_pending()) goto v0025;
    env = stack[-4];
    stack[-1] = v0093;
    goto v0050;

v0007:
    v0094 = stack[-2];
    v0093 = stack[-1];
    v0093 = Lgcd(nil, v0094, v0093);
    nil = C_nil;
    if (exception_pending()) goto v0025;
    env = stack[-4];
    stack[-3] = v0093;
    stack[0] = elt(env, 1); /* !:rn!: */
    v0094 = stack[-2];
    v0093 = stack[-3];
    stack[-2] = quot2(v0094, v0093);
    nil = C_nil;
    if (exception_pending()) goto v0025;
    env = stack[-4];
    v0094 = stack[-1];
    v0093 = stack[-3];
    v0093 = quot2(v0094, v0093);
    nil = C_nil;
    if (exception_pending()) goto v0025;
    {
        Lisp_Object v0024 = stack[0];
        Lisp_Object v0163 = stack[-2];
        popv(5);
        return list2star(v0024, v0163, v0093);
    }
/* error exit handlers */
v0025:
    popv(5);
    return nil;
}



/* Code for gen!-mult!-by!-const!-mod!-p */

static Lisp_Object CC_genKmultKbyKconstKmodKp(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0047)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0225, v0187, v0087;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for gen-mult-by-const-mod-p");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0047,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0047);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0047;
    stack[-1] = v0000;
/* end of prologue */
    v0225 = stack[-1];
    if (v0225 == nil) goto v0033;
    v0187 = stack[0];
    v0225 = (Lisp_Object)17; /* 1 */
    if (v0187 == v0225) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v0225 = stack[-1];
    if (!consp(v0225)) goto v0034;
    v0225 = stack[-1];
    v0225 = qcar(v0225);
    v0225 = (consp(v0225) ? nil : lisp_true);
    goto v0029;

v0029:
    if (v0225 == nil) goto v0036;
    v0187 = stack[-1];
    v0225 = stack[0];
    fn = elt(env, 3); /* general!-modular!-times */
    v0225 = (*qfn2(fn))(qenv(fn), v0187, v0225);
    nil = C_nil;
    if (exception_pending()) goto v0217;
    env = stack[-3];
    {
        popv(4);
        fn = elt(env, 4); /* !*n2f */
        return (*qfn1(fn))(qenv(fn), v0225);
    }

v0036:
    v0225 = stack[-1];
    v0225 = qcar(v0225);
    v0187 = qcdr(v0225);
    v0225 = stack[0];
    stack[-2] = CC_genKmultKbyKconstKmodKp(env, v0187, v0225);
    nil = C_nil;
    if (exception_pending()) goto v0217;
    env = stack[-3];
    v0225 = stack[-1];
    v0187 = qcdr(v0225);
    v0225 = stack[0];
    v0225 = CC_genKmultKbyKconstKmodKp(env, v0187, v0225);
    nil = C_nil;
    if (exception_pending()) goto v0217;
    v0187 = stack[-2];
    v0087 = v0187;
    if (v0087 == nil) { popv(4); return onevalue(v0225); }
    v0087 = stack[-1];
    v0087 = qcar(v0087);
    v0087 = qcar(v0087);
    popv(4);
    return acons(v0087, v0187, v0225);

v0034:
    v0225 = qvalue(elt(env, 2)); /* t */
    goto v0029;

v0033:
    v0225 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v0225); }
/* error exit handlers */
v0217:
    popv(4);
    return nil;
}



/* Code for noncomp!* */

static Lisp_Object CC_noncompH(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0013, v0004;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for noncomp*");
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
    v0013 = stack[0];
    fn = elt(env, 3); /* noncomp */
    v0013 = (*qfn1(fn))(qenv(fn), v0013);
    nil = C_nil;
    if (exception_pending()) goto v0057;
    env = stack[-1];
    if (!(v0013 == nil)) { popv(2); return onevalue(v0013); }
    v0004 = stack[0];
    v0013 = elt(env, 1); /* expt */
    if (!consp(v0004)) goto v0034;
    v0004 = qcar(v0004);
    if (!(v0004 == v0013)) goto v0034;
    v0013 = stack[0];
    v0013 = qcdr(v0013);
    v0013 = qcar(v0013);
    {
        popv(2);
        fn = elt(env, 3); /* noncomp */
        return (*qfn1(fn))(qenv(fn), v0013);
    }

v0034:
    v0013 = qvalue(elt(env, 2)); /* nil */
    { popv(2); return onevalue(v0013); }
/* error exit handlers */
v0057:
    popv(2);
    return nil;
}



/* Code for convprec!* */

static Lisp_Object CC_convprecH(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0103, v0028;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for convprec*");
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
    v0103 = v0000;
/* end of prologue */
    v0028 = v0103;
    if (!consp(v0028)) goto v0190;
    v0028 = elt(env, 1); /* !:rd!: */
    v0103 = cons(v0028, v0103);
    nil = C_nil;
    if (exception_pending()) goto v0027;
    env = stack[0];
    goto v0190;

v0190:
    {
        popv(1);
        fn = elt(env, 2); /* convchk */
        return (*qfn1(fn))(qenv(fn), v0103);
    }
/* error exit handlers */
v0027:
    popv(1);
    return nil;
}



/* Code for gcdf!* */

static Lisp_Object CC_gcdfH(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0047)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0063, v0064, v0058;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for gcdf*");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0047,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0047);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0064 = v0047;
    v0058 = v0000;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* !*gcd */
    qvalue(elt(env, 1)) = nil; /* !*gcd */
    v0063 = qvalue(elt(env, 2)); /* t */
    qvalue(elt(env, 1)) = v0063; /* !*gcd */
    v0063 = v0058;
    fn = elt(env, 3); /* gcdf */
    v0063 = (*qfn2(fn))(qenv(fn), v0063, v0064);
    nil = C_nil;
    if (exception_pending()) goto v0103;
    env = stack[-1];
    qvalue(elt(env, 1)) = stack[0]; /* !*gcd */
    { popv(2); return onevalue(v0063); }
/* error exit handlers */
v0103:
    env = stack[-1];
    qvalue(elt(env, 1)) = stack[0]; /* !*gcd */
    popv(2);
    return nil;
}



/* Code for lalr_insert_core */

static Lisp_Object CC_lalr_insert_core(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0047)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0208, v0217, v0169;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for lalr_insert_core");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0047,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0047);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0047;
    stack[-1] = v0000;
/* end of prologue */
    stack[-2] = nil;
    goto v0102;

v0102:
    v0208 = stack[0];
    if (v0208 == nil) goto v0061;
    v0217 = stack[-1];
    v0208 = stack[0];
    v0208 = qcar(v0208);
    fn = elt(env, 2); /* lalr_same_core */
    v0208 = (*qfn2(fn))(qenv(fn), v0217, v0208);
    nil = C_nil;
    if (exception_pending()) goto v0020;
    env = stack[-3];
    if (v0208 == nil) goto v0218;
    v0208 = stack[-1];
    v0169 = qcdr(v0208);
    v0208 = stack[0];
    v0208 = qcar(v0208);
    v0217 = qcdr(v0208);
    v0208 = qvalue(elt(env, 1)); /* renamings */
    v0208 = acons(v0169, v0217, v0208);
    nil = C_nil;
    if (exception_pending()) goto v0020;
    env = stack[-3];
    qvalue(elt(env, 1)) = v0208; /* renamings */
    v0208 = stack[-1];
    v0217 = qcar(v0208);
    v0208 = stack[0];
    v0208 = qcar(v0208);
    v0208 = qcar(v0208);
    fn = elt(env, 3); /* union */
    v0169 = (*qfn2(fn))(qenv(fn), v0217, v0208);
    nil = C_nil;
    if (exception_pending()) goto v0020;
    env = stack[-3];
    v0208 = stack[0];
    v0208 = qcar(v0208);
    v0217 = qcdr(v0208);
    v0208 = stack[0];
    v0208 = qcdr(v0208);
    v0208 = acons(v0169, v0217, v0208);
    nil = C_nil;
    if (exception_pending()) goto v0020;
    env = stack[-3];
    {
        Lisp_Object v0021 = stack[-2];
        popv(4);
        fn = elt(env, 4); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0021, v0208);
    }

v0218:
    v0208 = stack[0];
    v0217 = qcar(v0208);
    v0208 = stack[-2];
    v0208 = cons(v0217, v0208);
    nil = C_nil;
    if (exception_pending()) goto v0020;
    env = stack[-3];
    stack[-2] = v0208;
    v0208 = stack[0];
    v0208 = qcdr(v0208);
    stack[0] = v0208;
    goto v0102;

v0061:
    stack[0] = stack[-2];
    v0208 = stack[-1];
    v0208 = ncons(v0208);
    nil = C_nil;
    if (exception_pending()) goto v0020;
    env = stack[-3];
    {
        Lisp_Object v0222 = stack[0];
        popv(4);
        fn = elt(env, 4); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0222, v0208);
    }
/* error exit handlers */
v0020:
    popv(4);
    return nil;
}



/* Code for sqchk */

static Lisp_Object CC_sqchk(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0056, v0096, v0059;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sqchk");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0059 = v0000;
/* end of prologue */
    v0056 = v0059;
    if (!consp(v0056)) return onevalue(v0059);
    v0056 = v0059;
    v0056 = qcar(v0056);
    if (!symbolp(v0056)) v0056 = nil;
    else { v0056 = qfastgets(v0056);
           if (v0056 != nil) { v0056 = elt(v0056, 44); /* prepfn2 */
#ifdef RECORD_GET
             if (v0056 != SPID_NOPROP)
                record_get(elt(fastget_names, 44), 1);
             else record_get(elt(fastget_names, 44), 0),
                v0056 = nil; }
           else record_get(elt(fastget_names, 44), 0); }
#else
             if (v0056 == SPID_NOPROP) v0056 = nil; }}
#endif
    v0096 = v0056;
    v0056 = v0096;
    if (v0056 == nil) goto v0058;
    v0056 = v0096;
    v0096 = v0059;
        return Lapply1(nil, v0056, v0096);

v0058:
    v0056 = v0059;
    v0056 = qcar(v0056);
    if (!consp(v0056)) return onevalue(v0059);
    v0056 = v0059;
    {
        fn = elt(env, 1); /* prepf */
        return (*qfn1(fn))(qenv(fn), v0056);
    }
}



/* Code for subs3q */

static Lisp_Object CC_subs3q(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0027;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for subs3q");
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
    v0027 = qvalue(elt(env, 1)); /* mchfg!* */
    stack[-2] = v0027;
    v0027 = qvalue(elt(env, 2)); /* nil */
    qvalue(elt(env, 1)) = v0027; /* mchfg!* */
    v0027 = stack[-1];
    v0027 = qcar(v0027);
    fn = elt(env, 3); /* subs3f */
    stack[0] = (*qfn1(fn))(qenv(fn), v0027);
    nil = C_nil;
    if (exception_pending()) goto v0007;
    env = stack[-3];
    v0027 = stack[-1];
    v0027 = qcdr(v0027);
    fn = elt(env, 3); /* subs3f */
    v0027 = (*qfn1(fn))(qenv(fn), v0027);
    nil = C_nil;
    if (exception_pending()) goto v0007;
    env = stack[-3];
    fn = elt(env, 4); /* quotsq */
    v0027 = (*qfn2(fn))(qenv(fn), stack[0], v0027);
    nil = C_nil;
    if (exception_pending()) goto v0007;
    env = stack[-3];
    stack[-1] = v0027;
    v0027 = stack[-2];
    qvalue(elt(env, 1)) = v0027; /* mchfg!* */
    { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
/* error exit handlers */
v0007:
    popv(4);
    return nil;
}



/* Code for sort!-factors */

static Lisp_Object CC_sortKfactors(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0052, v0050;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sort-factors");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0052 = v0000;
/* end of prologue */
    v0050 = v0052;
    v0052 = elt(env, 1); /* orderfactors */
    {
        fn = elt(env, 2); /* sort */
        return (*qfn2(fn))(qenv(fn), v0050, v0052);
    }
}



/* Code for mathml */

static Lisp_Object MS_CDECL CC_mathml(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0097;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "mathml");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mathml");
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
/* end of prologue */
    fn = elt(env, 2); /* lex */
    v0097 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0101;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 3); /* sub_math */
        return (*qfnn(fn))(qenv(fn), 0);
    }
/* error exit handlers */
v0101:
    popv(1);
    return nil;
}



/* Code for multi_isarb_int */

static Lisp_Object CC_multi_isarb_int(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0007;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for multi_isarb_int");
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
    v0007 = stack[0];
    v0007 = Lconsp(nil, v0007);
    env = stack[-1];
    if (v0007 == nil) goto v0033;
    v0007 = stack[0];
    if (v0007 == nil) goto v0033;
    v0007 = stack[0];
    v0007 = qcar(v0007);
    fn = elt(env, 2); /* isarb_int */
    v0007 = (*qfn1(fn))(qenv(fn), v0007);
    nil = C_nil;
    if (exception_pending()) goto v0004;
    env = stack[-1];
    v0007 = stack[0];
    v0007 = qcdr(v0007);
    v0007 = CC_multi_isarb_int(env, v0007);
    nil = C_nil;
    if (exception_pending()) goto v0004;
    goto v0033;

v0033:
    v0007 = nil;
    { popv(2); return onevalue(v0007); }
/* error exit handlers */
v0004:
    popv(2);
    return nil;
}



/* Code for sqform */

static Lisp_Object CC_sqform(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0047)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0037, v0176, v0112, v0180;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sqform");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0047,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0047);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0047;
    stack[-1] = v0000;
/* end of prologue */
    v0176 = stack[0];
    v0037 = stack[-1];
    v0037 = qcar(v0037);
    stack[-2] = Lapply1(nil, v0176, v0037);
    nil = C_nil;
    if (exception_pending()) goto v0175;
    env = stack[-3];
    v0176 = stack[0];
    v0037 = stack[-1];
    v0037 = qcdr(v0037);
    v0037 = Lapply1(nil, v0176, v0037);
    nil = C_nil;
    if (exception_pending()) goto v0175;
    env = stack[-3];
    v0180 = stack[-2];
    v0112 = v0037;
    v0176 = v0112;
    v0037 = (Lisp_Object)17; /* 1 */
    if (v0176 == v0037) { popv(4); return onevalue(v0180); }
    v0037 = elt(env, 1); /* quotient */
    v0176 = v0180;
    popv(4);
    return list3(v0037, v0176, v0112);
/* error exit handlers */
v0175:
    popv(4);
    return nil;
}



/* Code for dm!-difference */

static Lisp_Object CC_dmKdifference(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0047)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0029, v0034;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dm-difference");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0047,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0047);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v0047;
    v0029 = v0000;
/* end of prologue */
    fn = elt(env, 1); /* zero2nil */
    v0034 = (*qfn1(fn))(qenv(fn), v0029);
    nil = C_nil;
    if (exception_pending()) goto v0007;
    env = stack[-1];
    v0029 = stack[0];
    fn = elt(env, 2); /* !:difference */
    v0029 = (*qfn2(fn))(qenv(fn), v0034, v0029);
    nil = C_nil;
    if (exception_pending()) goto v0007;
    v0034 = v0029;
    v0029 = v0034;
    if (!(v0029 == nil)) { popv(2); return onevalue(v0034); }
    v0029 = (Lisp_Object)1; /* 0 */
    { popv(2); return onevalue(v0029); }
/* error exit handlers */
v0007:
    popv(2);
    return nil;
}



/* Code for freeindexchk */

static Lisp_Object CC_freeindexchk(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0161, v0103;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for freeindexchk");
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
    v0103 = v0000;
/* end of prologue */
    v0161 = v0103;
    if (v0161 == nil) goto v0063;
    v0161 = qvalue(elt(env, 1)); /* indxl!* */
    if (v0161 == nil) goto v0063;
    v0161 = v0103;
    fn = elt(env, 4); /* indxchk */
    v0161 = (*qfn1(fn))(qenv(fn), v0161);
    nil = C_nil;
    if (exception_pending()) goto v0028;
    env = stack[0];
    if (v0161 == nil) goto v0063;
    v0161 = elt(env, 2); /* form!-with!-free!-indices */
    { popv(1); return onevalue(v0161); }

v0063:
    v0161 = qvalue(elt(env, 3)); /* nil */
    { popv(1); return onevalue(v0161); }
/* error exit handlers */
v0028:
    popv(1);
    return nil;
}



/* Code for putpline */

static Lisp_Object CC_putpline(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0084, v0231, v0018;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for putpline");
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
    v0231 = qvalue(elt(env, 1)); /* posn!* */
    v0084 = stack[0];
    v0084 = qcar(v0084);
    v0084 = qcdr(v0084);
    stack[-1] = (Lisp_Object)(int32_t)((int32_t)v0231 + (int32_t)v0084 - TAG_FIXNUM);
    v0084 = qvalue(elt(env, 2)); /* nil */
    v0231 = Llinelength(nil, v0084);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    env = stack[-2];
    v0084 = qvalue(elt(env, 3)); /* spare!* */
    v0084 = (Lisp_Object)(int32_t)((int32_t)v0231 - (int32_t)v0084 + TAG_FIXNUM);
    v0084 = (Lisp_Object)greaterp2(stack[-1], v0084);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    v0084 = v0084 ? lisp_true : nil;
    env = stack[-2];
    if (v0084 == nil) goto v0176;
    v0084 = qvalue(elt(env, 4)); /* t */
    fn = elt(env, 10); /* terpri!* */
    v0084 = (*qfn1(fn))(qenv(fn), v0084);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    env = stack[-2];
    goto v0176;

v0176:
    v0231 = qvalue(elt(env, 1)); /* posn!* */
    v0084 = qvalue(elt(env, 5)); /* orig!* */
    v0018 = (Lisp_Object)(int32_t)((int32_t)v0231 - (int32_t)v0084 + TAG_FIXNUM);
    v0231 = qvalue(elt(env, 6)); /* ycoord!* */
    v0084 = stack[0];
    v0084 = qcar(v0084);
    v0084 = qcar(v0084);
    fn = elt(env, 11); /* update!-pline */
    v0231 = (*qfnn(fn))(qenv(fn), 3, v0018, v0231, v0084);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    env = stack[-2];
    v0084 = qvalue(elt(env, 7)); /* pline!* */
    v0084 = Lappend(nil, v0231, v0084);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    env = stack[-2];
    qvalue(elt(env, 7)) = v0084; /* pline!* */
    v0231 = qvalue(elt(env, 1)); /* posn!* */
    v0084 = stack[0];
    v0084 = qcar(v0084);
    v0084 = qcdr(v0084);
    v0084 = (Lisp_Object)(int32_t)((int32_t)v0231 + (int32_t)v0084 - TAG_FIXNUM);
    qvalue(elt(env, 1)) = v0084; /* posn!* */
    v0018 = qvalue(elt(env, 8)); /* ymin!* */
    v0084 = stack[0];
    v0084 = qcdr(v0084);
    v0231 = qcar(v0084);
    v0084 = qvalue(elt(env, 6)); /* ycoord!* */
    v0084 = (Lisp_Object)(int32_t)((int32_t)v0231 + (int32_t)v0084 - TAG_FIXNUM);
    fn = elt(env, 12); /* min */
    v0084 = (*qfn2(fn))(qenv(fn), v0018, v0084);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    env = stack[-2];
    qvalue(elt(env, 8)) = v0084; /* ymin!* */
    v0018 = qvalue(elt(env, 9)); /* ymax!* */
    v0084 = stack[0];
    v0084 = qcdr(v0084);
    v0231 = qcdr(v0084);
    v0084 = qvalue(elt(env, 6)); /* ycoord!* */
    v0084 = (Lisp_Object)(int32_t)((int32_t)v0231 + (int32_t)v0084 - TAG_FIXNUM);
    fn = elt(env, 13); /* max */
    v0084 = (*qfn2(fn))(qenv(fn), v0018, v0084);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    env = stack[-2];
    qvalue(elt(env, 9)) = v0084; /* ymax!* */
    v0084 = nil;
    { popv(3); return onevalue(v0084); }
/* error exit handlers */
v0238:
    popv(3);
    return nil;
}



/* Code for !:times */

static Lisp_Object CC_Ttimes(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0047)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0180, v0111, v0232;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for :times");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0111 = v0047;
    v0232 = v0000;
/* end of prologue */
    v0180 = v0232;
    if (v0180 == nil) goto v0051;
    v0180 = v0111;
    v0180 = (v0180 == nil ? lisp_true : nil);
    goto v0101;

v0101:
    if (v0180 == nil) goto v0102;
    v0180 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v0180);

v0102:
    v0180 = v0232;
    if (!consp(v0180)) goto v0029;
    v0180 = qvalue(elt(env, 2)); /* nil */
    goto v0027;

v0027:
    if (v0180 == nil) goto v0115;
    v0180 = v0232;
    return times2(v0180, v0111);

v0115:
    v0180 = elt(env, 3); /* times */
    {
        fn = elt(env, 4); /* dcombine */
        return (*qfnn(fn))(qenv(fn), 3, v0232, v0111, v0180);
    }

v0029:
    v0180 = v0111;
    v0180 = (consp(v0180) ? nil : lisp_true);
    goto v0027;

v0051:
    v0180 = qvalue(elt(env, 1)); /* t */
    goto v0101;
}



/* Code for dp!=ecart */

static Lisp_Object CC_dpMecart(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0036, v0115;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dp=ecart");
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
    goto v0102;

v0102:
    v0036 = stack[0];
    if (v0036 == nil) goto v0097;
    v0036 = stack[0];
    fn = elt(env, 1); /* dp_lmon */
    v0036 = (*qfn1(fn))(qenv(fn), v0036);
    nil = C_nil;
    if (exception_pending()) goto v0037;
    env = stack[-2];
    fn = elt(env, 2); /* mo_ecart */
    v0115 = (*qfn1(fn))(qenv(fn), v0036);
    nil = C_nil;
    if (exception_pending()) goto v0037;
    env = stack[-2];
    v0036 = stack[-1];
    v0036 = cons(v0115, v0036);
    nil = C_nil;
    if (exception_pending()) goto v0037;
    env = stack[-2];
    stack[-1] = v0036;
    v0036 = stack[0];
    v0036 = qcdr(v0036);
    stack[0] = v0036;
    goto v0102;

v0097:
    v0036 = (Lisp_Object)1; /* 0 */
    v0115 = v0036;
    goto v0101;

v0101:
    v0036 = stack[-1];
    if (v0036 == nil) { popv(3); return onevalue(v0115); }
    v0036 = stack[-1];
    v0036 = qcar(v0036);
    v0036 = Lmax2(nil, v0036, v0115);
    nil = C_nil;
    if (exception_pending()) goto v0037;
    env = stack[-2];
    v0115 = v0036;
    v0036 = stack[-1];
    v0036 = qcdr(v0036);
    stack[-1] = v0036;
    goto v0101;
/* error exit handlers */
v0037:
    popv(3);
    return nil;
}



/* Code for gperm1 */

static Lisp_Object MS_CDECL CC_gperm1(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0215, v0025, v0024;
    Lisp_Object fn;
    Lisp_Object v0178, v0168, v0047, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "gperm1");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0047 = va_arg(aa, Lisp_Object);
    v0168 = va_arg(aa, Lisp_Object);
    v0178 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for gperm1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v0178,v0168,v0047,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0000,v0047,v0168,v0178);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-1] = v0178;
    stack[-2] = v0168;
    stack[-3] = v0047;
    stack[-4] = v0000;
/* end of prologue */

v0051:
    v0215 = stack[-4];
    if (v0215 == nil) goto v0064;
    v0215 = stack[-4];
    v0215 = qcdr(v0215);
    stack[-5] = v0215;
    v0215 = stack[-4];
    v0025 = qcar(v0215);
    v0215 = stack[-2];
    v0215 = cons(v0025, v0215);
    nil = C_nil;
    if (exception_pending()) goto v0213;
    env = stack[-6];
    stack[0] = v0215;
    v0025 = stack[-3];
    v0215 = stack[-2];
    v0215 = cons(v0025, v0215);
    nil = C_nil;
    if (exception_pending()) goto v0213;
    env = stack[-6];
    fn = elt(env, 1); /* rev */
    v0025 = (*qfn2(fn))(qenv(fn), stack[-4], v0215);
    nil = C_nil;
    if (exception_pending()) goto v0213;
    env = stack[-6];
    v0215 = stack[-1];
    v0215 = cons(v0025, v0215);
    nil = C_nil;
    if (exception_pending()) goto v0213;
    env = stack[-6];
    stack[-1] = v0215;
    v0215 = stack[0];
    stack[-2] = v0215;
    v0215 = stack[-5];
    stack[-4] = v0215;
    goto v0051;

v0064:
    v0024 = stack[-3];
    v0025 = stack[-2];
    v0215 = stack[-1];
    popv(7);
    return acons(v0024, v0025, v0215);
/* error exit handlers */
v0213:
    popv(7);
    return nil;
}



/* Code for mod!# */

static Lisp_Object CC_modC(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0055, v0035;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mod#");
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
    v0055 = v0000;
/* end of prologue */
    v0035 = v0055;
    v0055 = qvalue(elt(env, 1)); /* current!-modulus */
    v0055 = Cremainder(v0035, v0055);
    nil = C_nil;
    if (exception_pending()) goto v0096;
    env = stack[-1];
    stack[0] = v0055;
    v0035 = stack[0];
    v0055 = (Lisp_Object)1; /* 0 */
    v0055 = (Lisp_Object)lessp2(v0035, v0055);
    nil = C_nil;
    if (exception_pending()) goto v0096;
    v0055 = v0055 ? lisp_true : nil;
    env = stack[-1];
    if (v0055 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v0055 = stack[0];
    v0035 = qvalue(elt(env, 1)); /* current!-modulus */
    popv(2);
    return plus2(v0055, v0035);
/* error exit handlers */
v0096:
    popv(2);
    return nil;
}



/* Code for xread */

static Lisp_Object CC_xread(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0029, v0034;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for xread");
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

v0190:
    fn = elt(env, 4); /* scan */
    v0029 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0007;
    env = stack[-1];
    v0029 = qvalue(elt(env, 1)); /* !*eoldelimp */
    if (v0029 == nil) goto v0097;
    v0034 = qvalue(elt(env, 2)); /* cursym!* */
    v0029 = elt(env, 3); /* !*semicol!* */
    if (v0034 == v0029) goto v0190;
    else goto v0097;

v0097:
    v0029 = stack[0];
    {
        popv(2);
        fn = elt(env, 5); /* xread1 */
        return (*qfn1(fn))(qenv(fn), v0029);
    }
/* error exit handlers */
v0007:
    popv(2);
    return nil;
}



/* Code for split_form */

static Lisp_Object CC_split_form(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0047)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0161, v0103;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for split_form");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0047,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0047);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    v0161 = v0047;
    v0103 = v0000;
/* end of prologue */
    stack[-2] = v0103;
    stack[-1] = v0161;
    stack[0] = (Lisp_Object)17; /* 1 */
    v0161 = qvalue(elt(env, 1)); /* nil */
    v0161 = ncons(v0161);
    nil = C_nil;
    if (exception_pending()) goto v0034;
    env = stack[-3];
    {
        Lisp_Object v0113 = stack[-2];
        Lisp_Object v0007 = stack[-1];
        Lisp_Object v0013 = stack[0];
        popv(4);
        fn = elt(env, 2); /* split_f */
        return (*qfnn(fn))(qenv(fn), 4, v0113, v0007, v0013, v0161);
    }
/* error exit handlers */
v0034:
    popv(4);
    return nil;
}



/* Code for removev */

static Lisp_Object CC_removev(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0047)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0037, v0176, v0112, v0180;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for removev");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0047,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0047);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v0180 = v0047;
    v0112 = v0000;
/* end of prologue */

v0033:
    v0037 = v0112;
    if (v0037 == nil) goto v0061;
    v0037 = v0112;
    v0037 = qcdr(v0037);
    v0176 = qcar(v0037);
    v0037 = v0180;
    if (v0176 == v0037) goto v0035;
    v0037 = v0112;
    v0037 = qcdr(v0037);
    v0112 = v0037;
    goto v0033;

v0035:
    v0037 = v0112;
    v0176 = v0112;
    v0176 = qcdr(v0176);
    v0176 = qcdr(v0176);
        popv(1);
        return Lrplacd(nil, v0037, v0176);

v0061:
    v0176 = elt(env, 1); /* "Vertex" */
    v0112 = v0180;
    v0037 = elt(env, 2); /* "is absent." */
    v0037 = list3(v0176, v0112, v0037);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 3); /* cerror */
        return (*qfn1(fn))(qenv(fn), v0037);
    }
/* error exit handlers */
v0111:
    popv(1);
    return nil;
}



/* Code for qqe_qtidp */

static Lisp_Object CC_qqe_qtidp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0050, v0110;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for qqe_qtidp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0050 = v0000;
/* end of prologue */
    if (!symbolp(v0050)) v0050 = nil;
    else { v0050 = qfastgets(v0050);
           if (v0050 != nil) { v0050 = elt(v0050, 10); /* idtype */
#ifdef RECORD_GET
             if (v0050 != SPID_NOPROP)
                record_get(elt(fastget_names, 10), 1);
             else record_get(elt(fastget_names, 10), 0),
                v0050 = nil; }
           else record_get(elt(fastget_names, 10), 0); }
#else
             if (v0050 == SPID_NOPROP) v0050 = nil; }}
#endif
    v0110 = elt(env, 1); /* qt */
    v0050 = (v0050 == v0110 ? lisp_true : nil);
    return onevalue(v0050);
}



/* Code for pasf_susipost */

static Lisp_Object CC_pasf_susipost(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0047)
{
    Lisp_Object v0190, v0033;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pasf_susipost");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0190 = v0047;
    v0033 = v0000;
/* end of prologue */
    return onevalue(v0033);
}



/* Code for omobj */

static Lisp_Object MS_CDECL CC_omobj(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0026, v0057;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "omobj");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for omobj");
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
/* end of prologue */
    v0026 = qvalue(elt(env, 1)); /* char */
    fn = elt(env, 4); /* compress!* */
    v0057 = (*qfn1(fn))(qenv(fn), v0026);
    nil = C_nil;
    if (exception_pending()) goto v0048;
    env = stack[0];
    v0026 = qvalue(elt(env, 2)); /* omfuncs!* */
    v0026 = Lassoc(nil, v0057, v0026);
    v0057 = v0026;
    if (v0026 == nil) goto v0102;
    v0026 = v0057;
    v0026 = qcdr(v0026);
    v0057 = qcar(v0026);
    v0026 = qvalue(elt(env, 3)); /* nil */
    {
        popv(1);
        fn = elt(env, 5); /* apply */
        return (*qfn2(fn))(qenv(fn), v0057, v0026);
    }

v0102:
    v0026 = nil;
    { popv(1); return onevalue(v0026); }
/* error exit handlers */
v0048:
    popv(1);
    return nil;
}



/* Code for emtch */

static Lisp_Object CC_emtch(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0029, v0034;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for emtch");
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
    stack[0] = v0000;
/* end of prologue */
    v0029 = stack[0];
    if (!consp(v0029)) { Lisp_Object res = stack[0]; popv(1); return onevalue(res); }
    v0029 = stack[0];
    fn = elt(env, 1); /* opmtch */
    v0029 = (*qfn1(fn))(qenv(fn), v0029);
    nil = C_nil;
    if (exception_pending()) goto v0007;
    v0034 = v0029;
    v0029 = v0034;
    if (v0029 == nil) { Lisp_Object res = stack[0]; popv(1); return onevalue(res); }
    else { popv(1); return onevalue(v0034); }
/* error exit handlers */
v0007:
    popv(1);
    return nil;
}



setup_type const u05_setup[] =
{
    {"prin2*",                  CC_prin2H,      too_many_1,    wrong_no_1},
    {"insert_pv",               too_few_2,      CC_insert_pv,  wrong_no_2},
    {"rntimes:",                too_few_2,      CC_rntimesT,   wrong_no_2},
    {"modplus:",                too_few_2,      CC_modplusT,   wrong_no_2},
    {"noncomdel",               too_few_2,      CC_noncomdel,  wrong_no_2},
    {"times-mod-p",             too_few_2,      CC_timesKmodKp,wrong_no_2},
    {"mkgi",                    too_few_2,      CC_mkgi,       wrong_no_2},
    {"add2calls",               CC_add2calls,   too_many_1,    wrong_no_1},
    {"tayexp-min2",             too_few_2,      CC_tayexpKmin2,wrong_no_2},
    {"addsq",                   too_few_2,      CC_addsq,      wrong_no_2},
    {"ckrn1",                   CC_ckrn1,       too_many_1,    wrong_no_1},
    {"mri_simplfloor",          CC_mri_simplfloor,too_many_1,  wrong_no_1},
    {"ibalp_minclnr",           CC_ibalp_minclnr,too_many_1,   wrong_no_1},
    {"mathml_list2string",      CC_mathml_list2string,too_many_1,wrong_no_1},
    {"findrow",                 too_few_2,      CC_findrow,    wrong_no_2},
    {"dm-times",                too_few_2,      CC_dmKtimes,   wrong_no_2},
    {"rmsubs",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_rmsubs},
    {"prin2la",                 CC_prin2la,     too_many_1,    wrong_no_1},
    {"command1",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_command1},
    {"getel1",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_getel1},
    {"mo=shorten",              CC_moMshorten,  too_many_1,    wrong_no_1},
    {"resimp",                  CC_resimp,      too_many_1,    wrong_no_1},
    {"pv_sort1",                too_few_2,      CC_pv_sort1,   wrong_no_2},
    {"lalr_items",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_lalr_items},
    {"ofsf_vareqnp",            too_few_2,      CC_ofsf_vareqnp,wrong_no_2},
    {"rl_prepat",               CC_rl_prepat,   too_many_1,    wrong_no_1},
    {"fac-merge",               too_few_2,      CC_facKmerge,  wrong_no_2},
    {"ibalp_csat",              CC_ibalp_csat,  too_many_1,    wrong_no_1},
    {"listsum",                 CC_listsum,     too_many_1,    wrong_no_1},
    {"indent*",                 CC_indentH,     too_many_1,    wrong_no_1},
    {"c:ordexp",                too_few_2,      CC_cTordexp,   wrong_no_2},
    {"downwght",                too_few_2,      CC_downwght,   wrong_no_2},
    {"vevtdeg",                 CC_vevtdeg,     too_many_1,    wrong_no_1},
    {"find_item",               too_few_2,      CC_find_item,  wrong_no_2},
    {"round:last",              CC_roundTlast,  too_many_1,    wrong_no_1},
    {"lessp:",                  too_few_2,      CC_lesspT,     wrong_no_2},
    {"*collectphysops",         CC_Hcollectphysops,too_many_1, wrong_no_1},
    {"mo_compare",              too_few_2,      CC_mo_compare, wrong_no_2},
    {"insert_pv1",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_insert_pv1},
    {"aronep:",                 CC_aronepT,     too_many_1,    wrong_no_1},
    {"evaluate-in-order",       too_few_2,      CC_evaluateKinKorder,wrong_no_2},
    {"times-in-vector",         wrong_no_na,    wrong_no_nb,   (n_args *)CC_timesKinKvector},
    {"lalr_action",             too_few_2,      CC_lalr_action,wrong_no_2},
    {"anform",                  CC_anform,      too_many_1,    wrong_no_1},
    {"sfto_dcontentf1",         too_few_2,      CC_sfto_dcontentf1,wrong_no_2},
    {"polynomadd",              too_few_2,      CC_polynomadd, wrong_no_2},
    {"get-print-name",          CC_getKprintKname,too_many_1,  wrong_no_1},
    {"xxsort",                  CC_xxsort,      too_many_1,    wrong_no_1},
    {"lambda_idn438f46io4",     too_few_2,      CC_lambda_idn438f46io4,wrong_no_2},
    {"aex_mk",                  too_few_2,      CC_aex_mk,     wrong_no_2},
    {"multi_isarb_compl",       CC_multi_isarb_compl,too_many_1,wrong_no_1},
    {"minus:",                  CC_minusT,      too_many_1,    wrong_no_1},
    {"depends",                 too_few_2,      CC_depends,    wrong_no_2},
    {"prepf1a_reversed",        wrong_no_na,    wrong_no_nb,   (n_args *)CC_prepf1a_reversed},
    {"rd:onep",                 CC_rdTonep,     too_many_1,    wrong_no_1},
    {"groebsearchinlist",       too_few_2,      CC_groebsearchinlist,wrong_no_2},
    {"int-equiv-chk",           CC_intKequivKchk,too_many_1,   wrong_no_1},
    {"getrmacro",               CC_getrmacro,   too_many_1,    wrong_no_1},
    {"dp_term",                 too_few_2,      CC_dp_term,    wrong_no_2},
    {"pv_applp",                too_few_2,      CC_pv_applp,   wrong_no_2},
    {"mkrn",                    too_few_2,      CC_mkrn,       wrong_no_2},
    {"gen-mult-by-const-mod-p", too_few_2,      CC_genKmultKbyKconstKmodKp,wrong_no_2},
    {"noncomp*",                CC_noncompH,    too_many_1,    wrong_no_1},
    {"convprec*",               CC_convprecH,   too_many_1,    wrong_no_1},
    {"gcdf*",                   too_few_2,      CC_gcdfH,      wrong_no_2},
    {"lalr_insert_core",        too_few_2,      CC_lalr_insert_core,wrong_no_2},
    {"sqchk",                   CC_sqchk,       too_many_1,    wrong_no_1},
    {"subs3q",                  CC_subs3q,      too_many_1,    wrong_no_1},
    {"sort-factors",            CC_sortKfactors,too_many_1,    wrong_no_1},
    {"mathml",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_mathml},
    {"multi_isarb_int",         CC_multi_isarb_int,too_many_1, wrong_no_1},
    {"sqform",                  too_few_2,      CC_sqform,     wrong_no_2},
    {"dm-difference",           too_few_2,      CC_dmKdifference,wrong_no_2},
    {"freeindexchk",            CC_freeindexchk,too_many_1,    wrong_no_1},
    {"putpline",                CC_putpline,    too_many_1,    wrong_no_1},
    {":times",                  too_few_2,      CC_Ttimes,     wrong_no_2},
    {"dp=ecart",                CC_dpMecart,    too_many_1,    wrong_no_1},
    {"gperm1",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_gperm1},
    {"mod#",                    CC_modC,        too_many_1,    wrong_no_1},
    {"xread",                   CC_xread,       too_many_1,    wrong_no_1},
    {"split_form",              too_few_2,      CC_split_form, wrong_no_2},
    {"removev",                 too_few_2,      CC_removev,    wrong_no_2},
    {"qqe_qtidp",               CC_qqe_qtidp,   too_many_1,    wrong_no_1},
    {"pasf_susipost",           too_few_2,      CC_pasf_susipost,wrong_no_2},
    {"omobj",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_omobj},
    {"emtch",                   CC_emtch,       too_many_1,    wrong_no_1},
    {NULL, (one_args *)"u05", (two_args *)"11866 8071639 9650489", 0}
};

/* end of generated code */
