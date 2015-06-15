
/* $destdir/u01.c        Machine generated C code */

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


/* Code for reval */

static Lisp_Object CC_reval(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0003, v0004;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for reval");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0003 = v0000;
/* end of prologue */
    v0004 = v0003;
    v0003 = qvalue(elt(env, 1)); /* t */
    {
        fn = elt(env, 2); /* reval1 */
        return (*qfn2(fn))(qenv(fn), v0004, v0003);
    }
}



/* Code for simpcar */

static Lisp_Object CC_simpcar(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0005;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for simpcar");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0005 = v0000;
/* end of prologue */
    v0005 = qcar(v0005);
    {
        fn = elt(env, 1); /* simp */
        return (*qfn1(fn))(qenv(fn), v0005);
    }
}



/* Code for noncomp */

static Lisp_Object CC_noncomp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0006, v0007;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for noncomp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0007 = v0000;
/* end of prologue */
    v0006 = qvalue(elt(env, 1)); /* !*ncmp */
    if (v0006 == nil) goto v0008;
    v0006 = v0007;
    {
        fn = elt(env, 3); /* noncomp1 */
        return (*qfn1(fn))(qenv(fn), v0006);
    }

v0008:
    v0006 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v0006);
}



/* Code for num!-exponents */

static Lisp_Object CC_numKexponents(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0010;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for num-exponents");
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

v0011:
    v0010 = stack[0];
    if (!consp(v0010)) goto v0001;
    v0010 = stack[0];
    v0010 = qcar(v0010);
    v0010 = (consp(v0010) ? nil : lisp_true);
    goto v0012;

v0012:
    if (v0010 == nil) goto v0013;
    v0010 = qvalue(elt(env, 1)); /* t */
    { popv(2); return onevalue(v0010); }

v0013:
    v0010 = stack[0];
    v0010 = qcar(v0010);
    v0010 = qcar(v0010);
    v0010 = qcdr(v0010);
    v0010 = integerp(v0010);
    if (v0010 == nil) goto v0014;
    v0010 = stack[0];
    v0010 = qcar(v0010);
    v0010 = qcdr(v0010);
    v0010 = CC_numKexponents(env, v0010);
    nil = C_nil;
    if (exception_pending()) goto v0015;
    env = stack[-1];
    if (v0010 == nil) goto v0016;
    v0010 = stack[0];
    v0010 = qcdr(v0010);
    stack[0] = v0010;
    goto v0011;

v0016:
    v0010 = qvalue(elt(env, 2)); /* nil */
    { popv(2); return onevalue(v0010); }

v0014:
    v0010 = qvalue(elt(env, 2)); /* nil */
    { popv(2); return onevalue(v0010); }

v0001:
    v0010 = qvalue(elt(env, 1)); /* t */
    goto v0012;
/* error exit handlers */
v0015:
    popv(2);
    return nil;
}



/* Code for argsofopr */

static Lisp_Object CC_argsofopr(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0008;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for argsofopr");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0008 = v0000;
/* end of prologue */
    if (!symbolp(v0008)) v0008 = nil;
    else { v0008 = qfastgets(v0008);
           if (v0008 != nil) { v0008 = elt(v0008, 42); /* number!-of!-args 
*/
#ifdef RECORD_GET
             if (v0008 != SPID_NOPROP)
                record_get(elt(fastget_names, 42), 1);
             else record_get(elt(fastget_names, 42), 0),
                v0008 = nil; }
           else record_get(elt(fastget_names, 42), 0); }
#else
             if (v0008 == SPID_NOPROP) v0008 = nil; }}
#endif
    return onevalue(v0008);
}



/* Code for smember */

static Lisp_Object CC_smember(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0017)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0022, v0023;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for smember");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0017,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0017);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0017;
    stack[-1] = v0000;
/* end of prologue */

v0012:
    v0023 = stack[-1];
    v0022 = stack[0];
    if (equal(v0023, v0022)) goto v0005;
    v0022 = stack[0];
    if (!consp(v0022)) goto v0024;
    v0023 = stack[-1];
    v0022 = stack[0];
    v0022 = qcar(v0022);
    v0022 = CC_smember(env, v0023, v0022);
    nil = C_nil;
    if (exception_pending()) goto v0010;
    env = stack[-2];
    if (!(v0022 == nil)) { popv(3); return onevalue(v0022); }
    v0023 = stack[-1];
    v0022 = stack[0];
    v0022 = qcdr(v0022);
    stack[-1] = v0023;
    stack[0] = v0022;
    goto v0012;

v0024:
    v0022 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v0022); }

v0005:
    v0022 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v0022); }
/* error exit handlers */
v0010:
    popv(3);
    return nil;
}



/* Code for !*n2f */

static Lisp_Object CC_Hn2f(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0006, v0007;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for *n2f");
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
    v0006 = v0000;
/* end of prologue */
    v0007 = v0006;
    v0007 = (Lisp_Object)zerop(v0007);
    v0007 = v0007 ? lisp_true : nil;
    env = stack[0];
    if (v0007 == nil) { popv(1); return onevalue(v0006); }
    v0006 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v0006); }
}



/* Code for lalr_move_dot */

static Lisp_Object CC_lalr_move_dot(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0017)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0035, v0036, v0037;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for lalr_move_dot");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0017,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0017);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0017;
    stack[-1] = v0000;
/* end of prologue */
    stack[-2] = nil;
    goto v0007;

v0007:
    v0035 = stack[-1];
    v0036 = qcar(v0035);
    v0035 = elt(env, 1); /* !. */
    if (v0036 == v0035) goto v0012;
    v0035 = stack[-1];
    v0036 = qcar(v0035);
    v0035 = stack[-2];
    v0035 = cons(v0036, v0035);
    nil = C_nil;
    if (exception_pending()) goto v0038;
    env = stack[-3];
    stack[-2] = v0035;
    v0035 = stack[-1];
    v0035 = qcdr(v0035);
    stack[-1] = v0035;
    goto v0007;

v0012:
    v0035 = stack[-1];
    v0035 = qcdr(v0035);
    stack[-1] = v0035;
    v0035 = stack[-1];
    if (v0035 == nil) goto v0039;
    v0035 = stack[-1];
    v0036 = qcar(v0035);
    v0035 = stack[0];
    if (!(equal(v0036, v0035))) goto v0039;
    v0035 = stack[-1];
    v0037 = qcar(v0035);
    v0036 = elt(env, 1); /* !. */
    v0035 = stack[-1];
    v0035 = qcdr(v0035);
    v0035 = list2star(v0037, v0036, v0035);
    nil = C_nil;
    if (exception_pending()) goto v0038;
    env = stack[-3];
    stack[-1] = v0035;
    goto v0040;

v0040:
    v0035 = stack[-2];
    if (v0035 == nil) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v0035 = stack[-2];
    v0036 = qcar(v0035);
    v0035 = stack[-1];
    v0035 = cons(v0036, v0035);
    nil = C_nil;
    if (exception_pending()) goto v0038;
    env = stack[-3];
    stack[-1] = v0035;
    v0035 = stack[-2];
    v0035 = qcdr(v0035);
    stack[-2] = v0035;
    goto v0040;

v0039:
    v0035 = qvalue(elt(env, 2)); /* nil */
    { popv(4); return onevalue(v0035); }
/* error exit handlers */
v0038:
    popv(4);
    return nil;
}



/* Code for mkvar */

static Lisp_Object CC_mkvar(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0017)
{
    Lisp_Object v0008, v0005;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mkvar");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0008 = v0017;
    v0005 = v0000;
/* end of prologue */
    return onevalue(v0005);
}



/* Code for multf */

static Lisp_Object CC_multf(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0017)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0044, v0045, v0046;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for multf");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0045 = v0017;
    v0046 = v0000;
/* end of prologue */
    v0044 = qvalue(elt(env, 1)); /* !*physop!-loaded */
    if (v0044 == nil) goto v0033;
    v0044 = v0046;
    {
        fn = elt(env, 2); /* physop!-multf */
        return (*qfn2(fn))(qenv(fn), v0044, v0045);
    }

v0033:
    v0044 = v0046;
    {
        fn = elt(env, 3); /* poly!-multf */
        return (*qfn2(fn))(qenv(fn), v0044, v0045);
    }
}



/* Code for monomgetvariabledegree */

static Lisp_Object CC_monomgetvariabledegree(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0017)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0030, v0028;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for monomgetvariabledegree");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0017,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0017);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0017;
    v0030 = v0000;
/* end of prologue */
    v0028 = v0030;
    v0030 = (Lisp_Object)17; /* 1 */
    v0030 = *(Lisp_Object *)((char *)v0028 + (CELL-TAG_VECTOR) + ((int32_t)v0030/(16/CELL)));
    stack[-1] = v0030;
    goto v0050;

v0050:
    v0030 = stack[-1];
    v0030 = qcar(v0030);
    if (v0030 == nil) goto v0024;
    v0030 = stack[-1];
    v0028 = qcar(v0030);
    v0030 = stack[0];
    v0030 = (Lisp_Object)greaterp2(v0028, v0030);
    nil = C_nil;
    if (exception_pending()) goto v0051;
    v0030 = v0030 ? lisp_true : nil;
    env = stack[-2];
    if (v0030 == nil) goto v0024;
    v0030 = stack[-1];
    v0030 = qcdr(v0030);
    stack[-1] = v0030;
    goto v0050;

v0024:
    v0030 = stack[-1];
    v0030 = qcar(v0030);
    if (v0030 == nil) goto v0052;
    v0030 = stack[-1];
    v0028 = qcar(v0030);
    v0030 = stack[0];
    if (!(equal(v0028, v0030))) goto v0052;
    v0030 = (Lisp_Object)17; /* 1 */
    { popv(3); return onevalue(v0030); }

v0052:
    v0030 = (Lisp_Object)1; /* 0 */
    { popv(3); return onevalue(v0030); }
/* error exit handlers */
v0051:
    popv(3);
    return nil;
}



/* Code for quotelist */

static Lisp_Object CC_quotelist(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object v0027;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for quotelist");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0027 = v0000;
/* end of prologue */
    v0027 = elt(env, 1); /* list */
    return onevalue(v0027);
}



/* Code for wuconstantp */

static Lisp_Object CC_wuconstantp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0019, v0049;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for wuconstantp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0049 = v0000;
/* end of prologue */
    v0019 = v0049;
    if (!consp(v0019)) goto v0001;
    v0019 = v0049;
    v0019 = qcar(v0019);
    v0019 = (consp(v0019) ? nil : lisp_true);
    goto v0012;

v0012:
    if (v0019 == nil) goto v0034;
    v0019 = qvalue(elt(env, 1)); /* t */
    return onevalue(v0019);

v0034:
    v0019 = v0049;
    v0019 = qcar(v0019);
    v0019 = qcar(v0019);
    v0019 = qcar(v0019);
    v0049 = qvalue(elt(env, 2)); /* wuvarlist!* */
    v0019 = Lmemq(nil, v0019, v0049);
    v0019 = (v0019 == nil ? lisp_true : nil);
    return onevalue(v0019);

v0001:
    v0019 = qvalue(elt(env, 1)); /* t */
    goto v0012;
}



/* Code for mchkopt */

static Lisp_Object CC_mchkopt(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0017)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0054, v0041, v0042, v0044;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mchkopt");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0042 = v0017;
    v0044 = v0000;
/* end of prologue */
    v0054 = v0042;
    v0054 = qcar(v0054);
    if (!symbolp(v0054)) v0054 = nil;
    else { v0054 = qfastgets(v0054);
           if (v0054 != nil) { v0054 = elt(v0054, 6); /* optional */
#ifdef RECORD_GET
             if (v0054 != SPID_NOPROP)
                record_get(elt(fastget_names, 6), 1);
             else record_get(elt(fastget_names, 6), 0),
                v0054 = nil; }
           else record_get(elt(fastget_names, 6), 0); }
#else
             if (v0054 == SPID_NOPROP) v0054 = nil; }}
#endif
    v0041 = v0054;
    v0054 = v0041;
    if (v0054 == nil) goto v0003;
    v0054 = v0044;
    {
        fn = elt(env, 1); /* mchkopt1 */
        return (*qfnn(fn))(qenv(fn), 3, v0054, v0042, v0041);
    }

v0003:
    v0054 = nil;
    return onevalue(v0054);
}



/* Code for nth */

static Lisp_Object CC_nth(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0017)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0006, v0007;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for nth");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0017,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0017);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0006 = v0017;
    v0007 = v0000;
/* end of prologue */
    fn = elt(env, 1); /* pnth */
    v0006 = (*qfn2(fn))(qenv(fn), v0007, v0006);
    errexit();
    v0006 = qcar(v0006);
    return onevalue(v0006);
}



/* Code for qqe_rqopp */

static Lisp_Object CC_qqe_rqopp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0003, v0004;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for qqe_rqopp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0003 = v0000;
/* end of prologue */
    v0004 = elt(env, 1); /* (qequal qneq) */
    v0003 = Lmemq(nil, v0003, v0004);
    return onevalue(v0003);
}



/* Code for kernels */

static Lisp_Object CC_kernels(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0003, v0004;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for kernels");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0003 = v0000;
/* end of prologue */
    v0004 = v0003;
    v0003 = qvalue(elt(env, 1)); /* nil */
    {
        fn = elt(env, 2); /* kernels1 */
        return (*qfn2(fn))(qenv(fn), v0004, v0003);
    }
}



/* Code for ibalp_clmember */

static Lisp_Object CC_ibalp_clmember(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0017)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0019, v0049;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ibalp_clmember");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0017,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0017);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0017;
    stack[-1] = v0000;
/* end of prologue */

v0011:
    v0019 = stack[0];
    if (v0019 == nil) goto v0005;
    v0049 = stack[-1];
    v0019 = stack[0];
    v0019 = qcar(v0019);
    fn = elt(env, 2); /* ibalp_cequal */
    v0019 = (*qfn2(fn))(qenv(fn), v0049, v0019);
    nil = C_nil;
    if (exception_pending()) goto v0056;
    env = stack[-2];
    if (!(v0019 == nil)) { popv(3); return onevalue(v0019); }
    v0049 = stack[-1];
    v0019 = stack[0];
    v0019 = qcdr(v0019);
    stack[-1] = v0049;
    stack[0] = v0019;
    goto v0011;

v0005:
    v0019 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v0019); }
/* error exit handlers */
v0056:
    popv(3);
    return nil;
}



/* Code for noncomfp */

static Lisp_Object CC_noncomfp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0006, v0007;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for noncomfp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0007 = v0000;
/* end of prologue */
    v0006 = qvalue(elt(env, 1)); /* !*ncmp */
    if (v0006 == nil) goto v0008;
    v0006 = v0007;
    {
        fn = elt(env, 3); /* noncomfp1 */
        return (*qfn1(fn))(qenv(fn), v0006);
    }

v0008:
    v0006 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v0006);
}



/* Code for delall */

static Lisp_Object CC_delall(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0017)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0058, v0059;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for delall");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0017,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0017);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0017;
    stack[-1] = v0000;
/* end of prologue */

v0005:
    v0058 = stack[0];
    if (v0058 == nil) goto v0001;
    v0059 = stack[-1];
    v0058 = stack[0];
    v0058 = qcar(v0058);
    if (equal(v0059, v0058)) goto v0006;
    v0058 = stack[0];
    v0058 = qcar(v0058);
    stack[-2] = ncons(v0058);
    nil = C_nil;
    if (exception_pending()) goto v0031;
    env = stack[-3];
    v0059 = stack[-1];
    v0058 = stack[0];
    v0058 = qcdr(v0058);
    v0058 = CC_delall(env, v0059, v0058);
    nil = C_nil;
    if (exception_pending()) goto v0031;
    {
        Lisp_Object v0060 = stack[-2];
        popv(4);
        return Lappend(nil, v0060, v0058);
    }

v0006:
    v0058 = stack[0];
    v0058 = qcdr(v0058);
    stack[0] = v0058;
    goto v0005;

v0001:
    v0058 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v0058); }
/* error exit handlers */
v0031:
    popv(4);
    return nil;
}



/* Code for terminalp */

static Lisp_Object MS_CDECL CC_terminalp(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0004;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "terminalp");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for terminalp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* end of prologue */
    v0004 = qvalue(elt(env, 1)); /* !*int */
    if (v0004 == nil) goto v0027;
    v0004 = qvalue(elt(env, 3)); /* ifl!* */
    v0004 = (v0004 == nil ? lisp_true : nil);
    return onevalue(v0004);

v0027:
    v0004 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v0004);
}



/* Code for ordop */

static Lisp_Object CC_ordop(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0017)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0030, v0028, v0062, v0029, v0051;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ordop");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0029 = v0017;
    v0051 = v0000;
/* end of prologue */
    v0030 = qvalue(elt(env, 1)); /* !*physop!-loaded */
    if (v0030 == nil) goto v0050;
    v0030 = v0051;
    v0028 = v0029;
    {
        fn = elt(env, 5); /* physop!-ordop */
        return (*qfn2(fn))(qenv(fn), v0030, v0028);
    }

v0050:
    v0030 = qvalue(elt(env, 2)); /* kord!* */
    v0062 = v0030;
    goto v0053;

v0053:
    v0030 = v0062;
    if (v0030 == nil) goto v0032;
    v0028 = v0051;
    v0030 = v0062;
    v0030 = qcar(v0030);
    if (v0028 == v0030) goto v0056;
    v0028 = v0029;
    v0030 = v0062;
    v0030 = qcar(v0030);
    if (v0028 == v0030) goto v0063;
    v0030 = v0062;
    v0030 = qcdr(v0030);
    v0062 = v0030;
    goto v0053;

v0063:
    v0030 = qvalue(elt(env, 4)); /* nil */
    return onevalue(v0030);

v0056:
    v0030 = qvalue(elt(env, 3)); /* t */
    return onevalue(v0030);

v0032:
    v0030 = v0051;
    v0028 = v0029;
    {
        fn = elt(env, 6); /* ordp */
        return (*qfn2(fn))(qenv(fn), v0030, v0028);
    }
}



/* Code for prepf */

static Lisp_Object CC_prepf(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0004, v0006;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for prepf");
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
    v0004 = v0000;
/* end of prologue */
    v0006 = v0004;
    v0004 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 2); /* prepf1a */
    v0004 = (*qfn2(fn))(qenv(fn), v0006, v0004);
    nil = C_nil;
    if (exception_pending()) goto v0007;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 3); /* replus1 */
        return (*qfn1(fn))(qenv(fn), v0004);
    }
/* error exit handlers */
v0007:
    popv(1);
    return nil;
}



/* Code for c!:ordxp */

static Lisp_Object CC_cTordxp(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0017)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0023, v0058, v0059;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for c:ordxp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0017,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0017);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v0023 = v0017;
    v0058 = v0000;
/* end of prologue */
    v0059 = v0058;
    v0059 = Lconsp(nil, v0059);
    env = stack[0];
    if (v0059 == nil) goto v0009;
    v0059 = v0023;
    v0059 = Lconsp(nil, v0059);
    env = stack[0];
    if (v0059 == nil) goto v0042;
    v0058 = qcdr(v0058);
    v0023 = qcdr(v0023);
        popv(1);
        return Llessp(nil, v0058, v0023);

v0042:
    v0023 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v0023); }

v0009:
    v0059 = v0023;
    v0059 = Lconsp(nil, v0059);
    env = stack[0];
    if (v0059 == nil) goto v0021;
    v0023 = qvalue(elt(env, 2)); /* t */
    { popv(1); return onevalue(v0023); }

v0021:
        popv(1);
        return Llessp(nil, v0058, v0023);
}



/* Code for zero2nil */

static Lisp_Object CC_zero2nil(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0006;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for zero2nil");
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
    v0006 = stack[0];
    fn = elt(env, 2); /* !:zerop */
    v0006 = (*qfn1(fn))(qenv(fn), v0006);
    nil = C_nil;
    if (exception_pending()) goto v0043;
    env = stack[-1];
    if (v0006 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v0006 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v0006); }
/* error exit handlers */
v0043:
    popv(2);
    return nil;
}



/* Code for ordad */

static Lisp_Object CC_ordad(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0017)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0064, v0065;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ordad");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0017,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0017);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0017;
    stack[-1] = v0000;
/* end of prologue */
    stack[-2] = nil;
    goto v0001;

v0001:
    v0064 = stack[0];
    if (v0064 == nil) goto v0066;
    v0065 = stack[-1];
    v0064 = stack[0];
    v0064 = qcar(v0064);
    fn = elt(env, 2); /* ordp */
    v0064 = (*qfn2(fn))(qenv(fn), v0065, v0064);
    nil = C_nil;
    if (exception_pending()) goto v0067;
    env = stack[-3];
    if (!(v0064 == nil)) goto v0066;
    v0064 = stack[0];
    v0065 = qcar(v0064);
    v0064 = stack[-2];
    v0064 = cons(v0065, v0064);
    nil = C_nil;
    if (exception_pending()) goto v0067;
    env = stack[-3];
    stack[-2] = v0064;
    v0064 = stack[0];
    v0064 = qcdr(v0064);
    stack[0] = v0064;
    goto v0001;

v0066:
    v0065 = stack[-1];
    v0064 = stack[0];
    v0064 = cons(v0065, v0064);
    nil = C_nil;
    if (exception_pending()) goto v0067;
    env = stack[-3];
    stack[0] = v0064;
    goto v0063;

v0063:
    v0064 = stack[-2];
    if (v0064 == nil) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v0064 = stack[-2];
    v0064 = qcdr(v0064);
    stack[-1] = v0064;
    v0065 = stack[-2];
    v0064 = stack[0];
    v0064 = Lrplacd(nil, v0065, v0064);
    nil = C_nil;
    if (exception_pending()) goto v0067;
    env = stack[-3];
    v0064 = stack[-2];
    stack[0] = v0064;
    v0064 = stack[-1];
    stack[-2] = v0064;
    goto v0063;
/* error exit handlers */
v0067:
    popv(4);
    return nil;
}



/* Code for mval */

static Lisp_Object CC_mval(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object v0027;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mval");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0027 = v0000;
/* end of prologue */
    return onevalue(v0027);
}



/* Code for evcomp */

static Lisp_Object CC_evcomp(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0017)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0013, v0033;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for evcomp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0017,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0017);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0013 = v0017;
    v0033 = v0000;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* dipsortevcomp!* */
    v0013 = list2(v0033, v0013);
    nil = C_nil;
    if (exception_pending()) goto v0053;
    env = stack[-1];
    {
        Lisp_Object v0014 = stack[0];
        popv(2);
        fn = elt(env, 2); /* apply */
        return (*qfn2(fn))(qenv(fn), v0014, v0013);
    }
/* error exit handlers */
v0053:
    popv(2);
    return nil;
}



/* Code for evmatrixcomp2 */

static Lisp_Object MS_CDECL CC_evmatrixcomp2(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0080, v0081, v0082, v0083;
    Lisp_Object fn;
    Lisp_Object v0073, v0017, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "evmatrixcomp2");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0017 = va_arg(aa, Lisp_Object);
    v0073 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for evmatrixcomp2");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0073,v0017,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0017,v0073);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0073;
    stack[-1] = v0017;
    stack[-2] = v0000;
/* end of prologue */

v0011:
    v0080 = stack[-2];
    if (v0080 == nil) goto v0003;
    v0080 = stack[-1];
    v0080 = (v0080 == nil ? lisp_true : nil);
    goto v0002;

v0002:
    if (!(v0080 == nil)) { Lisp_Object res = stack[0]; popv(5); return onevalue(res); }
    v0080 = stack[-1];
    v0080 = qcar(v0080);
    stack[-3] = v0080;
    v0081 = stack[-3];
    v0080 = (Lisp_Object)1; /* 0 */
    fn = elt(env, 2); /* iequal */
    v0080 = (*qfn2(fn))(qenv(fn), v0081, v0080);
    nil = C_nil;
    if (exception_pending()) goto v0084;
    env = stack[-4];
    if (v0080 == nil) goto v0048;
    v0080 = stack[-2];
    v0082 = qcdr(v0080);
    v0080 = stack[-1];
    v0081 = qcdr(v0080);
    v0080 = stack[0];
    stack[-2] = v0082;
    stack[-1] = v0081;
    stack[0] = v0080;
    goto v0011;

v0048:
    v0081 = stack[-3];
    v0080 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 2); /* iequal */
    v0080 = (*qfn2(fn))(qenv(fn), v0081, v0080);
    nil = C_nil;
    if (exception_pending()) goto v0084;
    env = stack[-4];
    if (v0080 == nil) goto v0085;
    v0080 = stack[-2];
    v0083 = qcdr(v0080);
    v0080 = stack[-1];
    v0082 = qcdr(v0080);
    v0081 = stack[0];
    v0080 = stack[-2];
    v0080 = qcar(v0080);
    v0080 = (Lisp_Object)(int32_t)((int32_t)v0081 + (int32_t)v0080 - TAG_FIXNUM);
    stack[-2] = v0083;
    stack[-1] = v0082;
    stack[0] = v0080;
    goto v0011;

v0085:
    v0083 = stack[-2];
    v0082 = stack[-3];
    v0081 = stack[-1];
    v0080 = stack[0];
    {
        popv(5);
        fn = elt(env, 3); /* evmatrixcomp3 */
        return (*qfnn(fn))(qenv(fn), 4, v0083, v0082, v0081, v0080);
    }

v0003:
    v0080 = qvalue(elt(env, 1)); /* t */
    goto v0002;
/* error exit handlers */
v0084:
    popv(5);
    return nil;
}



/* Code for xval */

static Lisp_Object CC_xval(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0009;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for xval");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0009 = v0000;
/* end of prologue */
    v0009 = qcar(v0009);
    v0009 = qcar(v0009);
    {
        fn = elt(env, 1); /* wedgefax */
        return (*qfn1(fn))(qenv(fn), v0009);
    }
}



/* Code for times!: */

static Lisp_Object CC_timesT(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0017)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0056, v0039;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for times:");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0017,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0017);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0017;
    stack[-2] = v0000;
/* end of prologue */
    stack[-3] = elt(env, 1); /* !:rd!: */
    v0056 = stack[-2];
    v0056 = qcdr(v0056);
    v0039 = qcar(v0056);
    v0056 = stack[-1];
    v0056 = qcdr(v0056);
    v0056 = qcar(v0056);
    stack[0] = times2(v0039, v0056);
    nil = C_nil;
    if (exception_pending()) goto v0022;
    env = stack[-4];
    v0056 = stack[-2];
    v0056 = qcdr(v0056);
    v0039 = qcdr(v0056);
    v0056 = stack[-1];
    v0056 = qcdr(v0056);
    v0056 = qcdr(v0056);
    v0056 = plus2(v0039, v0056);
    nil = C_nil;
    if (exception_pending()) goto v0022;
    {
        Lisp_Object v0023 = stack[-3];
        Lisp_Object v0058 = stack[0];
        popv(5);
        return list2star(v0023, v0058, v0056);
    }
/* error exit handlers */
v0022:
    popv(5);
    return nil;
}



/* Code for convprec */

static Lisp_Object CC_convprec(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0005;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for convprec");
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
    v0005 = v0000;
/* end of prologue */
    fn = elt(env, 1); /* round!* */
    v0005 = (*qfn1(fn))(qenv(fn), v0005);
    nil = C_nil;
    if (exception_pending()) goto v0009;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* convchk */
        return (*qfn1(fn))(qenv(fn), v0005);
    }
/* error exit handlers */
v0009:
    popv(1);
    return nil;
}



/* Code for physopp */

static Lisp_Object CC_physopp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0059, v0010;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for physopp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0010 = v0000;
/* end of prologue */
    v0059 = v0010;
    if (!consp(v0059)) goto v0008;
    v0059 = v0010;
    v0059 = qcar(v0059);
    if (symbolp(v0059)) goto v0057;
    v0059 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v0059);

v0057:
    v0059 = v0010;
    v0059 = qcar(v0059);
    if (!symbolp(v0059)) v0059 = nil;
    else { v0059 = qfastgets(v0059);
           if (v0059 != nil) { v0059 = elt(v0059, 2); /* rtype */
#ifdef RECORD_GET
             if (v0059 != SPID_NOPROP)
                record_get(elt(fastget_names, 2), 1);
             else record_get(elt(fastget_names, 2), 0),
                v0059 = nil; }
           else record_get(elt(fastget_names, 2), 0); }
#else
             if (v0059 == SPID_NOPROP) v0059 = nil; }}
#endif
    v0010 = elt(env, 2); /* physop */
    v0059 = (v0059 == v0010 ? lisp_true : nil);
    return onevalue(v0059);

v0008:
    v0059 = v0010;
    if (symbolp(v0059)) goto v0024;
    v0059 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v0059);

v0024:
    v0059 = v0010;
    if (!symbolp(v0059)) v0059 = nil;
    else { v0059 = qfastgets(v0059);
           if (v0059 != nil) { v0059 = elt(v0059, 2); /* rtype */
#ifdef RECORD_GET
             if (v0059 != SPID_NOPROP)
                record_get(elt(fastget_names, 2), 1);
             else record_get(elt(fastget_names, 2), 0),
                v0059 = nil; }
           else record_get(elt(fastget_names, 2), 0); }
#else
             if (v0059 == SPID_NOPROP) v0059 = nil; }}
#endif
    v0010 = elt(env, 2); /* physop */
    v0059 = (v0059 == v0010 ? lisp_true : nil);
    return onevalue(v0059);
}



/* Code for memq_edgelist */

static Lisp_Object CC_memq_edgelist(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0017)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0006, v0007;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for memq_edgelist");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0006 = v0017;
    v0007 = v0000;
/* end of prologue */
    v0007 = qcar(v0007);
    v0006 = Lassoc(nil, v0007, v0006);
    return onevalue(v0006);
}



/* Code for wideid2list */

static Lisp_Object CC_wideid2list(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0005;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for wideid2list");
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
    v0005 = v0000;
/* end of prologue */
    fn = elt(env, 1); /* id2string */
    v0005 = (*qfn1(fn))(qenv(fn), v0005);
    nil = C_nil;
    if (exception_pending()) goto v0009;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* widestring2list */
        return (*qfn1(fn))(qenv(fn), v0005);
    }
/* error exit handlers */
v0009:
    popv(1);
    return nil;
}



/* Code for mo_comp */

static Lisp_Object CC_mo_comp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0043, v0024;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mo_comp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0043 = v0000;
/* end of prologue */
    v0024 = v0043;
    v0024 = qcar(v0024);
    if (v0024 == nil) goto v0008;
    v0043 = qcar(v0043);
    v0043 = qcar(v0043);
    return onevalue(v0043);

v0008:
    v0043 = (Lisp_Object)1; /* 0 */
    return onevalue(v0043);
}



/* Code for c_zero */

static Lisp_Object MS_CDECL CC_c_zero(Lisp_Object env, int nargs, ...)
{
    Lisp_Object v0073;
    argcheck(nargs, 0, "c_zero");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for c_zero");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* end of prologue */
    v0073 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v0073);
}



/* Code for sieve_pv0 */

static Lisp_Object MS_CDECL CC_sieve_pv0(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0040, v0064, v0065;
    Lisp_Object fn;
    Lisp_Object v0073, v0017, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "sieve_pv0");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0017 = va_arg(aa, Lisp_Object);
    v0073 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sieve_pv0");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0073,v0017,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0017,v0073);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0073;
    stack[-1] = v0017;
    stack[-2] = v0000;
/* end of prologue */
    v0040 = stack[-2];
    if (!(v0040 == nil)) goto v0043;
    v0040 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v0040); }

v0043:
    v0040 = stack[-1];
    if (v0040 == nil) goto v0086;
    v0040 = stack[-1];
    v0040 = qcar(v0040);
    v0040 = qcar(v0040);
    v0064 = qcdr(v0040);
    v0040 = stack[-2];
    v0040 = qcar(v0040);
    v0040 = qcdr(v0040);
    v0040 = (Lisp_Object)greaterp2(v0064, v0040);
    nil = C_nil;
    if (exception_pending()) goto v0067;
    v0040 = v0040 ? lisp_true : nil;
    env = stack[-3];
    if (v0040 == nil) goto v0086;
    v0040 = stack[-1];
    v0040 = qcdr(v0040);
    stack[-1] = v0040;
    goto v0043;

v0086:
    v0040 = stack[-2];
    if (v0040 == nil) { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
    v0040 = stack[-1];
    if (v0040 == nil) { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
    v0065 = stack[-2];
    v0040 = stack[-1];
    v0064 = qcar(v0040);
    v0040 = stack[0];
    fn = elt(env, 2); /* reduce_pv0 */
    v0040 = (*qfnn(fn))(qenv(fn), 3, v0065, v0064, v0040);
    nil = C_nil;
    if (exception_pending()) goto v0067;
    env = stack[-3];
    stack[-2] = v0040;
    v0040 = stack[-1];
    v0040 = qcdr(v0040);
    stack[-1] = v0040;
    goto v0086;
/* error exit handlers */
v0067:
    popv(4);
    return nil;
}



/* Code for listp */

static Lisp_Object CC_listp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0053, v0014;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for listp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0053 = v0000;
/* end of prologue */

v0011:
    v0014 = v0053;
    if (v0014 == nil) goto v0008;
    v0014 = v0053;
    if (!consp(v0014)) goto v0013;
    v0053 = qcdr(v0053);
    goto v0011;

v0013:
    v0053 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v0053);

v0008:
    v0053 = qvalue(elt(env, 1)); /* t */
    return onevalue(v0053);
}



/* Code for modzerop!: */

static Lisp_Object CC_modzeropT(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0004, v0006;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for modzerop:");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0004 = v0000;
/* end of prologue */
    v0006 = qcdr(v0004);
    v0004 = (Lisp_Object)1; /* 0 */
    v0004 = (v0006 == v0004 ? lisp_true : nil);
    return onevalue(v0004);
}



/* Code for lalr_closure */

static Lisp_Object CC_lalr_closure(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0099, v0100, v0101;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for lalr_closure");
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
/* copy arguments values to proper place */
    stack[-8] = v0000;
/* end of prologue */
    v0099 = stack[-8];
    stack[-9] = v0099;
    goto v0007;

v0007:
    v0099 = stack[-9];
    if (v0099 == nil) { Lisp_Object res = stack[-8]; popv(11); return onevalue(res); }
    v0099 = stack[-9];
    v0099 = qcar(v0099);
    stack[-6] = v0099;
    v0099 = stack[-9];
    v0099 = qcdr(v0099);
    stack[-9] = v0099;
    v0099 = stack[-6];
    v0099 = qcar(v0099);
    v0100 = stack[-6];
    v0100 = qcdr(v0100);
    v0100 = qcar(v0100);
    v0101 = v0100;
    v0100 = elt(env, 2); /* !. */
    v0099 = Lmember(nil, v0100, v0099);
    v0099 = qcdr(v0099);
    stack[-7] = v0099;
    v0099 = stack[-7];
    if (v0099 == nil) goto v0007;
    v0099 = stack[-7];
    v0099 = qcar(v0099);
    if (is_number(v0099)) goto v0007;
    v0099 = stack[-7];
    stack[0] = qcdr(v0099);
    v0099 = v0101;
    v0099 = ncons(v0099);
    nil = C_nil;
    if (exception_pending()) goto v0102;
    env = stack[-10];
    v0099 = Lappend(nil, stack[0], v0099);
    nil = C_nil;
    if (exception_pending()) goto v0102;
    env = stack[-10];
    fn = elt(env, 4); /* lalr_first */
    v0099 = (*qfn1(fn))(qenv(fn), v0099);
    nil = C_nil;
    if (exception_pending()) goto v0102;
    env = stack[-10];
    stack[-6] = v0099;
    v0099 = stack[-7];
    v0100 = qcar(v0099);
    v0099 = elt(env, 3); /* produces */
    v0099 = get(v0100, v0099);
    env = stack[-10];
    stack[-5] = v0099;
    goto v0028;

v0028:
    v0099 = stack[-5];
    if (v0099 == nil) goto v0007;
    v0099 = stack[-5];
    v0099 = qcar(v0099);
    stack[-4] = v0099;
    v0099 = stack[-6];
    stack[-3] = v0099;
    goto v0085;

v0085:
    v0099 = stack[-3];
    if (v0099 == nil) goto v0103;
    v0099 = stack[-3];
    v0099 = qcar(v0099);
    stack[-2] = v0099;
    v0099 = stack[-7];
    stack[-1] = qcar(v0099);
    v0100 = elt(env, 2); /* !. */
    v0099 = stack[-4];
    v0099 = qcar(v0099);
    stack[0] = cons(v0100, v0099);
    nil = C_nil;
    if (exception_pending()) goto v0102;
    env = stack[-10];
    v0099 = stack[-2];
    v0099 = ncons(v0099);
    nil = C_nil;
    if (exception_pending()) goto v0102;
    env = stack[-10];
    v0099 = acons(stack[-1], stack[0], v0099);
    nil = C_nil;
    if (exception_pending()) goto v0102;
    env = stack[-10];
    stack[0] = v0099;
    v0100 = stack[0];
    v0099 = stack[-8];
    v0099 = Lmember(nil, v0100, v0099);
    if (!(v0099 == nil)) goto v0104;
    v0100 = stack[0];
    v0099 = stack[-8];
    v0099 = cons(v0100, v0099);
    nil = C_nil;
    if (exception_pending()) goto v0102;
    env = stack[-10];
    stack[-8] = v0099;
    v0100 = stack[0];
    v0099 = stack[-9];
    v0099 = cons(v0100, v0099);
    nil = C_nil;
    if (exception_pending()) goto v0102;
    env = stack[-10];
    stack[-9] = v0099;
    goto v0104;

v0104:
    v0099 = stack[-3];
    v0099 = qcdr(v0099);
    stack[-3] = v0099;
    goto v0085;

v0103:
    v0099 = stack[-5];
    v0099 = qcdr(v0099);
    stack[-5] = v0099;
    goto v0028;
/* error exit handlers */
v0102:
    popv(11);
    return nil;
}



/* Code for monomcompare */

static Lisp_Object CC_monomcompare(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0017)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0061, v0098, v0052, v0074;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for monomcompare");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0052 = v0017;
    v0074 = v0000;
/* end of prologue */
    v0098 = qvalue(elt(env, 1)); /* fluidbibasismonomialorder */
    v0061 = elt(env, 2); /* lex */
    if (v0098 == v0061) goto v0068;
    v0098 = qvalue(elt(env, 1)); /* fluidbibasismonomialorder */
    v0061 = elt(env, 4); /* deglex */
    if (v0098 == v0061) goto v0057;
    v0061 = v0074;
    v0098 = v0052;
    {
        fn = elt(env, 5); /* monomcomparedegrevlex */
        return (*qfn2(fn))(qenv(fn), v0061, v0098);
    }

v0057:
    v0061 = v0074;
    v0098 = v0052;
    {
        fn = elt(env, 6); /* monomcomparedeglex */
        return (*qfn2(fn))(qenv(fn), v0061, v0098);
    }

v0068:
    v0061 = v0074;
    v0098 = v0052;
    {
        fn = elt(env, 7); /* monomcomparelex */
        return (*qfn2(fn))(qenv(fn), v0061, v0098);
    }
}



/* Code for aeval */

static Lisp_Object CC_aeval(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0003, v0004;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for aeval");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0003 = v0000;
/* end of prologue */
    v0004 = v0003;
    v0003 = qvalue(elt(env, 1)); /* nil */
    {
        fn = elt(env, 2); /* reval1 */
        return (*qfn2(fn))(qenv(fn), v0004, v0003);
    }
}



/* Code for quotf */

static Lisp_Object CC_quotf(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0017)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0007, v0043, v0024;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for quotf");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0017,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0017);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0043 = v0017;
    v0024 = v0000;
/* end of prologue */
    v0007 = qvalue(elt(env, 1)); /* t */
    stack[0] = qvalue(elt(env, 2)); /* !*exp */
    qvalue(elt(env, 2)) = v0007; /* !*exp */
    v0007 = v0024;
    fn = elt(env, 3); /* quotf1 */
    v0007 = (*qfn2(fn))(qenv(fn), v0007, v0043);
    nil = C_nil;
    if (exception_pending()) goto v0068;
    env = stack[-1];
    qvalue(elt(env, 2)) = stack[0]; /* !*exp */
    { popv(2); return onevalue(v0007); }
/* error exit handlers */
v0068:
    env = stack[-1];
    qvalue(elt(env, 2)) = stack[0]; /* !*exp */
    popv(2);
    return nil;
}



/* Code for mkcopy */

static Lisp_Object CC_mkcopy(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0049, v0016;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mkcopy");
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
    goto v0005;

v0005:
    v0049 = stack[0];
    if (!consp(v0049)) goto v0006;
    v0049 = stack[0];
    v0049 = qcar(v0049);
    v0016 = CC_mkcopy(env, v0049);
    nil = C_nil;
    if (exception_pending()) goto v0039;
    env = stack[-2];
    v0049 = stack[-1];
    v0049 = cons(v0016, v0049);
    nil = C_nil;
    if (exception_pending()) goto v0039;
    env = stack[-2];
    stack[-1] = v0049;
    v0049 = stack[0];
    v0049 = qcdr(v0049);
    stack[0] = v0049;
    goto v0005;

v0006:
    v0016 = stack[-1];
    v0049 = stack[0];
    {
        popv(3);
        fn = elt(env, 1); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0016, v0049);
    }
/* error exit handlers */
v0039:
    popv(3);
    return nil;
}



/* Code for mchk!* */

static Lisp_Object CC_mchkH(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0017)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0023, v0058;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mchk*");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0017,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0017);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0017;
    stack[-1] = v0000;
/* end of prologue */
    v0058 = stack[-1];
    v0023 = stack[0];
    fn = elt(env, 3); /* mchk */
    v0023 = (*qfn2(fn))(qenv(fn), v0058, v0023);
    nil = C_nil;
    if (exception_pending()) goto v0063;
    env = stack[-2];
    v0058 = v0023;
    if (!(v0023 == nil)) { popv(3); return onevalue(v0058); }
    v0023 = qvalue(elt(env, 1)); /* !*mcd */
    if (!(v0023 == nil)) goto v0033;
    v0023 = stack[-1];
    fn = elt(env, 4); /* sfp */
    v0023 = (*qfn1(fn))(qenv(fn), v0023);
    nil = C_nil;
    if (exception_pending()) goto v0063;
    env = stack[-2];
    if (v0023 == nil) goto v0033;
    v0023 = stack[0];
    fn = elt(env, 4); /* sfp */
    v0023 = (*qfn1(fn))(qenv(fn), v0023);
    nil = C_nil;
    if (exception_pending()) goto v0063;
    env = stack[-2];
    if (v0023 == nil) goto v0033;
    v0023 = stack[-1];
    fn = elt(env, 5); /* prepf */
    stack[-1] = (*qfn1(fn))(qenv(fn), v0023);
    nil = C_nil;
    if (exception_pending()) goto v0063;
    env = stack[-2];
    v0023 = stack[0];
    fn = elt(env, 5); /* prepf */
    v0023 = (*qfn1(fn))(qenv(fn), v0023);
    nil = C_nil;
    if (exception_pending()) goto v0063;
    env = stack[-2];
    {
        Lisp_Object v0015 = stack[-1];
        popv(3);
        fn = elt(env, 3); /* mchk */
        return (*qfn2(fn))(qenv(fn), v0015, v0023);
    }

v0033:
    v0023 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v0023); }
/* error exit handlers */
v0063:
    popv(3);
    return nil;
}



/* Code for revpr */

static Lisp_Object CC_revpr(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0006, v0007;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for revpr");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0006 = v0000;
/* end of prologue */
    v0007 = v0006;
    v0007 = qcdr(v0007);
    v0006 = qcar(v0006);
    return cons(v0007, v0006);
}



/* Code for get!+mat!+entry */

static Lisp_Object MS_CDECL CC_getLmatLentry(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0053, v0014;
    Lisp_Object fn;
    Lisp_Object v0073, v0017, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "get+mat+entry");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0017 = va_arg(aa, Lisp_Object);
    v0073 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for get+mat+entry");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0073,v0017,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0017,v0073);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v0073;
    v0053 = v0017;
    v0014 = v0000;
/* end of prologue */
    fn = elt(env, 1); /* nth */
    v0014 = (*qfn2(fn))(qenv(fn), v0014, v0053);
    nil = C_nil;
    if (exception_pending()) goto v0041;
    env = stack[-1];
    v0053 = stack[0];
    {
        popv(2);
        fn = elt(env, 1); /* nth */
        return (*qfn2(fn))(qenv(fn), v0014, v0053);
    }
/* error exit handlers */
v0041:
    popv(2);
    return nil;
}



/* Code for powers */

static Lisp_Object CC_powers(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0003, v0004;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for powers");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0003 = v0000;
/* end of prologue */
    v0004 = v0003;
    v0003 = qvalue(elt(env, 1)); /* nil */
    {
        fn = elt(env, 2); /* powers0 */
        return (*qfn2(fn))(qenv(fn), v0004, v0003);
    }
}



/* Code for lto_hashequalq */

static Lisp_Object CC_lto_hashequalq(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0017)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0107, v0108;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for lto_hashequalq");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0017,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0017);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v0017;
    stack[-3] = v0000;
/* end of prologue */
    v0107 = (Lisp_Object)1; /* 0 */
    stack[-1] = v0107;
    v0107 = (Lisp_Object)1; /* 0 */
    stack[0] = v0107;
    goto v0007;

v0007:
    v0107 = stack[-3];
    if (v0107 == nil) goto v0006;
    v0107 = stack[-2];
    if (v0107 == nil) goto v0006;
    v0107 = stack[-3];
    v0107 = qcar(v0107);
    v0108 = v0107;
    v0107 = stack[-2];
    v0107 = qcar(v0107);
    stack[-4] = v0107;
    v0107 = stack[-3];
    v0107 = qcdr(v0107);
    stack[-3] = v0107;
    v0107 = stack[-2];
    v0107 = qcdr(v0107);
    stack[-2] = v0107;
    v0107 = v0108;
    fn = elt(env, 2); /* lto_hashid */
    v0107 = (*qfn1(fn))(qenv(fn), v0107);
    nil = C_nil;
    if (exception_pending()) goto v0025;
    env = stack[-5];
    v0107 = (Lisp_Object)(int32_t)((int32_t)stack[-1] + (int32_t)v0107 - TAG_FIXNUM);
    stack[-1] = v0107;
    v0107 = stack[-4];
    fn = elt(env, 2); /* lto_hashid */
    v0107 = (*qfn1(fn))(qenv(fn), v0107);
    nil = C_nil;
    if (exception_pending()) goto v0025;
    env = stack[-5];
    v0107 = (Lisp_Object)(int32_t)((int32_t)stack[0] + (int32_t)v0107 - TAG_FIXNUM);
    stack[0] = v0107;
    goto v0007;

v0006:
    v0107 = stack[-3];
    if (v0107 == nil) goto v0105;
    v0107 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v0107); }

v0105:
    v0107 = stack[-2];
    if (v0107 == nil) goto v0030;
    v0107 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v0107); }

v0030:
    v0108 = stack[-1];
    v0107 = stack[0];
    {
        popv(6);
        fn = elt(env, 3); /* iequal */
        return (*qfn2(fn))(qenv(fn), v0108, v0107);
    }
/* error exit handlers */
v0025:
    popv(6);
    return nil;
}



/* Code for find2 */

static Lisp_Object CC_find2(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0017)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0059, v0010, v0063, v0015;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for find2");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0010 = v0017;
    v0063 = v0000;
/* end of prologue */

v0002:
    v0015 = v0010;
    v0059 = nil;
    if (v0015 == v0059) goto v0012;
    v0059 = v0010;
    v0059 = qcar(v0059);
    v0063 = Lmember(nil, v0059, v0063);
    v0059 = v0010;
    v0059 = qcdr(v0059);
    v0010 = v0059;
    goto v0002;

v0012:
    v0059 = v0063;
    if (v0059 == nil) goto v0054;
    v0059 = v0063;
    v0059 = qcdr(v0059);
    return onevalue(v0059);

v0054:
    v0059 = elt(env, 1); /* (stop) */
    return onevalue(v0059);
}



/* Code for exchk */

static Lisp_Object CC_exchk(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0050, v0068, v0013, v0033;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for exchk");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0050 = v0000;
/* end of prologue */
    v0033 = v0050;
    v0013 = qvalue(elt(env, 1)); /* nil */
    v0068 = qvalue(elt(env, 1)); /* nil */
    v0050 = qvalue(elt(env, 1)); /* nil */
    {
        fn = elt(env, 2); /* exchk1 */
        return (*qfnn(fn))(qenv(fn), 4, v0033, v0013, v0068, v0050);
    }
}



/* Code for dm!-abs */

static Lisp_Object CC_dmKabs(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0007;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dm-abs");
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
    fn = elt(env, 1); /* !:minusp */
    v0007 = (*qfn1(fn))(qenv(fn), v0007);
    nil = C_nil;
    if (exception_pending()) goto v0024;
    env = stack[-1];
    if (v0007 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v0007 = stack[0];
    {
        popv(2);
        fn = elt(env, 2); /* dm!-minus */
        return (*qfn1(fn))(qenv(fn), v0007);
    }
/* error exit handlers */
v0024:
    popv(2);
    return nil;
}



/* Code for pm!:free */

static Lisp_Object CC_pmTfree(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0004, v0006;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pm:free");
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
    v0004 = v0000;
/* end of prologue */
    fn = elt(env, 2); /* binding */
    v0004 = (*qfn1(fn))(qenv(fn), v0004);
    nil = C_nil;
    if (exception_pending()) goto v0007;
    env = stack[0];
    v0006 = elt(env, 1); /* unbound */
    v0004 = (v0004 == v0006 ? lisp_true : nil);
    { popv(1); return onevalue(v0004); }
/* error exit handlers */
v0007:
    popv(1);
    return nil;
}



/* Code for vbcsize */

static Lisp_Object CC_vbcsize(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0017)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0015, v0031, v0060;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for vbcsize");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0017,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0017);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0031 = v0017;
    stack[0] = v0000;
/* end of prologue */

v0012:
    v0060 = v0031;
    v0015 = (Lisp_Object)-15; /* -1 */
    if (((int32_t)(v0060)) > ((int32_t)(v0015))) goto v0005;
    v0015 = stack[0];
    if (!consp(v0015)) { popv(2); return onevalue(v0031); }
    v0015 = stack[0];
    v0015 = qcar(v0015);
    v0031 = (Lisp_Object)((int32_t)(v0031) + 0x10);
    v0015 = CC_vbcsize(env, v0015, v0031);
    nil = C_nil;
    if (exception_pending()) goto v0048;
    env = stack[-1];
    v0031 = v0015;
    v0015 = v0031;
    if (v0015 == nil) goto v0057;
    v0015 = stack[0];
    v0015 = qcdr(v0015);
    stack[0] = v0015;
    goto v0012;

v0057:
    v0015 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v0015); }

v0005:
    v0015 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v0015); }
/* error exit handlers */
v0048:
    popv(2);
    return nil;
}



/* Code for pnth */

static Lisp_Object CC_pnth(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0017)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0066, v0021, v0086;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pnth");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0017,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0017);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0021 = v0017;
    stack[0] = v0000;
/* end of prologue */

v0005:
    v0066 = stack[0];
    if (v0066 == nil) goto v0006;
    v0086 = v0021;
    v0066 = (Lisp_Object)17; /* 1 */
    if (v0086 == v0066) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v0066 = stack[0];
    v0066 = qcdr(v0066);
    stack[0] = v0066;
    v0066 = v0021;
    v0066 = sub1(v0066);
    nil = C_nil;
    if (exception_pending()) goto v0022;
    env = stack[-1];
    v0021 = v0066;
    goto v0005;

v0006:
    v0086 = elt(env, 1); /* alg */
    v0021 = (Lisp_Object)97; /* 6 */
    v0066 = elt(env, 2); /* "Index out of range" */
    {
        popv(2);
        fn = elt(env, 3); /* rerror */
        return (*qfnn(fn))(qenv(fn), 3, v0086, v0021, v0066);
    }
/* error exit handlers */
v0022:
    popv(2);
    return nil;
}



/* Code for wedgefax */

static Lisp_Object CC_wedgefax(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0034, v0053, v0014;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for wedgefax");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0053 = v0000;
/* end of prologue */
    v0034 = v0053;
    v0014 = elt(env, 1); /* wedge */
    if (!consp(v0034)) goto v0050;
    v0034 = qcar(v0034);
    if (!(v0034 == v0014)) goto v0050;
    v0034 = v0053;
    v0034 = qcdr(v0034);
    return onevalue(v0034);

v0050:
    v0034 = v0053;
    return ncons(v0034);
}



/* Code for !*physopp */

static Lisp_Object CC_Hphysopp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0055, v0019;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for *physopp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0019 = v0000;
/* end of prologue */
    v0055 = v0019;
    if (!consp(v0055)) goto v0008;
    v0055 = v0019;
    v0055 = qcar(v0055);
    if (symbolp(v0055)) goto v0044;
    v0055 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v0055);

v0044:
    v0055 = v0019;
    v0055 = qcar(v0055);
    if (!symbolp(v0055)) v0055 = nil;
    else { v0055 = qfastgets(v0055);
           if (v0055 != nil) { v0055 = elt(v0055, 18); /* phystype */
#ifdef RECORD_GET
             if (v0055 != SPID_NOPROP)
                record_get(elt(fastget_names, 18), 1);
             else record_get(elt(fastget_names, 18), 0),
                v0055 = nil; }
           else record_get(elt(fastget_names, 18), 0); }
#else
             if (v0055 == SPID_NOPROP) v0055 = nil; }}
#endif
    return onevalue(v0055);

v0008:
    v0055 = v0019;
    if (symbolp(v0055)) goto v0007;
    v0055 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v0055);

v0007:
    v0055 = v0019;
    if (!symbolp(v0055)) v0055 = nil;
    else { v0055 = qfastgets(v0055);
           if (v0055 != nil) { v0055 = elt(v0055, 18); /* phystype */
#ifdef RECORD_GET
             if (v0055 != SPID_NOPROP)
                record_get(elt(fastget_names, 18), 1);
             else record_get(elt(fastget_names, 18), 0),
                v0055 = nil; }
           else record_get(elt(fastget_names, 18), 0); }
#else
             if (v0055 == SPID_NOPROP) v0055 = nil; }}
#endif
    return onevalue(v0055);
}



/* Code for termsf */

static Lisp_Object CC_termsf(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0015, v0031;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for termsf");
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
    v0015 = (Lisp_Object)1; /* 0 */
    v0031 = v0015;
    goto v0001;

v0001:
    v0015 = stack[0];
    if (!consp(v0015)) goto v0024;
    v0015 = stack[0];
    v0015 = qcar(v0015);
    v0015 = (consp(v0015) ? nil : lisp_true);
    goto v0043;

v0043:
    if (v0015 == nil) goto v0044;
    v0015 = stack[0];
    if (v0015 == nil) { popv(3); return onevalue(v0031); }
    v0015 = v0031;
    popv(3);
    return add1(v0015);

v0044:
    stack[-1] = v0031;
    v0015 = stack[0];
    v0015 = qcar(v0015);
    v0015 = qcdr(v0015);
    v0015 = CC_termsf(env, v0015);
    nil = C_nil;
    if (exception_pending()) goto v0048;
    env = stack[-2];
    v0015 = plus2(stack[-1], v0015);
    nil = C_nil;
    if (exception_pending()) goto v0048;
    env = stack[-2];
    v0031 = v0015;
    v0015 = stack[0];
    v0015 = qcdr(v0015);
    stack[0] = v0015;
    goto v0001;

v0024:
    v0015 = qvalue(elt(env, 1)); /* t */
    goto v0043;
/* error exit handlers */
v0048:
    popv(3);
    return nil;
}



/* Code for mkspm */

static Lisp_Object CC_mkspm(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0017)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0074, v0075;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mkspm");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0017,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0017);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0017;
    stack[-1] = v0000;
/* end of prologue */
    v0075 = stack[0];
    v0074 = (Lisp_Object)1; /* 0 */
    if (v0075 == v0074) goto v0005;
    v0074 = qvalue(elt(env, 1)); /* subfg!* */
    if (v0074 == nil) goto v0053;
    v0075 = stack[-1];
    v0074 = qvalue(elt(env, 2)); /* asymplis!* */
    v0074 = Latsoc(nil, v0075, v0074);
    v0075 = v0074;
    if (v0074 == nil) goto v0053;
    v0074 = v0075;
    v0075 = qcdr(v0074);
    v0074 = stack[0];
    v0074 = (Lisp_Object)lesseq2(v0075, v0074);
    nil = C_nil;
    if (exception_pending()) goto v0028;
    v0074 = v0074 ? lisp_true : nil;
    env = stack[-2];
    if (v0074 == nil) goto v0053;
    v0074 = qvalue(elt(env, 3)); /* nil */
    { popv(3); return onevalue(v0074); }

v0053:
    v0074 = stack[-1];
    fn = elt(env, 4); /* sub2chk */
    v0074 = (*qfn1(fn))(qenv(fn), v0074);
    nil = C_nil;
    if (exception_pending()) goto v0028;
    env = stack[-2];
    v0075 = stack[-1];
    v0074 = stack[0];
    {
        popv(3);
        fn = elt(env, 5); /* to */
        return (*qfn2(fn))(qenv(fn), v0075, v0074);
    }

v0005:
    v0074 = (Lisp_Object)17; /* 1 */
    { popv(3); return onevalue(v0074); }
/* error exit handlers */
v0028:
    popv(3);
    return nil;
}



/* Code for dssoc */

static Lisp_Object CC_dssoc(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0017)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0032, v0018, v0055, v0019;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dssoc");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0055 = v0017;
    v0019 = v0000;
/* end of prologue */

v0005:
    v0032 = v0055;
    if (v0032 == nil) goto v0001;
    v0018 = v0019;
    v0032 = v0055;
    v0032 = qcar(v0032);
    v0032 = qcdr(v0032);
    if (equal(v0018, v0032)) goto v0006;
    v0032 = v0055;
    v0032 = qcdr(v0032);
    v0055 = v0032;
    goto v0005;

v0006:
    v0032 = v0055;
    v0032 = qcar(v0032);
    return onevalue(v0032);

v0001:
    v0032 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v0032);
}



/* Code for noncomlistp */

static Lisp_Object CC_noncomlistp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0034;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for noncomlistp");
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

v0011:
    v0034 = stack[0];
    v0034 = Lconsp(nil, v0034);
    env = stack[-1];
    if (v0034 == nil) goto v0008;
    v0034 = stack[0];
    v0034 = qcar(v0034);
    fn = elt(env, 2); /* noncomp1 */
    v0034 = (*qfn1(fn))(qenv(fn), v0034);
    nil = C_nil;
    if (exception_pending()) goto v0014;
    env = stack[-1];
    if (!(v0034 == nil)) { popv(2); return onevalue(v0034); }
    v0034 = stack[0];
    v0034 = qcdr(v0034);
    stack[0] = v0034;
    goto v0011;

v0008:
    v0034 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v0034); }
/* error exit handlers */
v0014:
    popv(2);
    return nil;
}



/* Code for rnzerop!: */

static Lisp_Object CC_rnzeropT(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0006, v0007;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rnzerop:");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0006 = v0000;
/* end of prologue */
    v0006 = qcdr(v0006);
    v0007 = qcar(v0006);
    v0006 = (Lisp_Object)1; /* 0 */
    v0006 = (v0007 == v0006 ? lisp_true : nil);
    return onevalue(v0006);
}



/* Code for mksp */

static Lisp_Object CC_mksp(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0017)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0006, v0007;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mksp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0017,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0017);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v0017;
    v0006 = v0000;
/* end of prologue */
    fn = elt(env, 1); /* fkern */
    v0007 = (*qfn1(fn))(qenv(fn), v0006);
    nil = C_nil;
    if (exception_pending()) goto v0024;
    env = stack[-1];
    v0006 = stack[0];
    {
        popv(2);
        fn = elt(env, 2); /* getpower */
        return (*qfn2(fn))(qenv(fn), v0007, v0006);
    }
/* error exit handlers */
v0024:
    popv(2);
    return nil;
}



/* Code for getrtypeor */

static Lisp_Object CC_getrtypeor(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0033;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for getrtypeor");
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

v0011:
    v0033 = stack[0];
    if (v0033 == nil) goto v0008;
    v0033 = stack[0];
    v0033 = qcar(v0033);
    fn = elt(env, 2); /* getrtype */
    v0033 = (*qfn1(fn))(qenv(fn), v0033);
    nil = C_nil;
    if (exception_pending()) goto v0053;
    env = stack[-1];
    if (!(v0033 == nil)) { popv(2); return onevalue(v0033); }
    v0033 = stack[0];
    v0033 = qcdr(v0033);
    stack[0] = v0033;
    goto v0011;

v0008:
    v0033 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v0033); }
/* error exit handlers */
v0053:
    popv(2);
    return nil;
}



/* Code for lalr_goto */

static Lisp_Object CC_lalr_goto(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0017)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0052, v0074;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for lalr_goto");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0017,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0017);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v0017;
    v0052 = v0000;
/* end of prologue */
    stack[-3] = nil;
    stack[-1] = v0052;
    goto v0003;

v0003:
    v0052 = stack[-1];
    if (v0052 == nil) goto v0002;
    v0052 = stack[-1];
    v0052 = qcar(v0052);
    stack[0] = v0052;
    v0052 = stack[0];
    v0074 = qcar(v0052);
    v0052 = stack[-2];
    fn = elt(env, 2); /* lalr_move_dot */
    v0052 = (*qfn2(fn))(qenv(fn), v0074, v0052);
    nil = C_nil;
    if (exception_pending()) goto v0062;
    env = stack[-4];
    v0074 = v0052;
    v0052 = v0074;
    if (v0052 == nil) goto v0055;
    v0052 = stack[0];
    v0052 = qcdr(v0052);
    v0052 = qcar(v0052);
    v0074 = list2(v0074, v0052);
    nil = C_nil;
    if (exception_pending()) goto v0062;
    env = stack[-4];
    v0052 = stack[-3];
    v0052 = cons(v0074, v0052);
    nil = C_nil;
    if (exception_pending()) goto v0062;
    env = stack[-4];
    stack[-3] = v0052;
    goto v0055;

v0055:
    v0052 = stack[-1];
    v0052 = qcdr(v0052);
    stack[-1] = v0052;
    goto v0003;

v0002:
    v0052 = stack[-3];
    {
        popv(5);
        fn = elt(env, 3); /* lalr_closure */
        return (*qfn1(fn))(qenv(fn), v0052);
    }
/* error exit handlers */
v0062:
    popv(5);
    return nil;
}



/* Code for setkorder */

static Lisp_Object CC_setkorder(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0014, v0054, v0041;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for setkorder");
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
    v0041 = v0000;
/* end of prologue */
    v0014 = qvalue(elt(env, 1)); /* kord!* */
    stack[0] = v0014;
    v0054 = v0041;
    v0014 = stack[0];
    if (equal(v0054, v0014)) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v0014 = v0041;
    qvalue(elt(env, 1)) = v0014; /* kord!* */
    v0014 = qvalue(elt(env, 2)); /* nil */
    v0014 = ncons(v0014);
    nil = C_nil;
    if (exception_pending()) goto v0044;
    env = stack[-1];
    qvalue(elt(env, 3)) = v0014; /* alglist!* */
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
/* error exit handlers */
v0044:
    popv(2);
    return nil;
}



/* Code for cl_cflip */

static Lisp_Object CC_cl_cflip(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0017)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0007, v0043;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for cl_cflip");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0007 = v0017;
    v0043 = v0000;
/* end of prologue */
    if (!(v0007 == nil)) return onevalue(v0043);
    v0007 = v0043;
    {
        fn = elt(env, 1); /* cl_flip */
        return (*qfn1(fn))(qenv(fn), v0007);
    }
}



/* Code for subs3f */

static Lisp_Object CC_subs3f(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0007, v0043, v0024;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for subs3f");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0007 = v0000;
/* end of prologue */
    v0024 = v0007;
    v0043 = qvalue(elt(env, 1)); /* !*match */
    v0007 = qvalue(elt(env, 2)); /* t */
    {
        fn = elt(env, 3); /* subs3f1 */
        return (*qfnn(fn))(qenv(fn), 3, v0024, v0043, v0007);
    }
}



/* Code for kernlp */

static Lisp_Object CC_kernlp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0055, v0019;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for kernlp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0055 = v0000;
/* end of prologue */

v0008:
    v0019 = v0055;
    if (!consp(v0019)) goto v0004;
    v0019 = v0055;
    v0019 = qcar(v0019);
    v0019 = (consp(v0019) ? nil : lisp_true);
    goto v0003;

v0003:
    if (!(v0019 == nil)) return onevalue(v0055);
    v0019 = v0055;
    v0019 = qcdr(v0019);
    if (v0019 == nil) goto v0053;
    v0055 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v0055);

v0053:
    v0055 = qcar(v0055);
    v0055 = qcdr(v0055);
    goto v0008;

v0004:
    v0019 = qvalue(elt(env, 1)); /* t */
    goto v0003;
}



/* Code for ibalp_emptyclausep */

static Lisp_Object CC_ibalp_emptyclausep(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0059, v0010;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ibalp_emptyclausep");
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
    v0059 = stack[0];
    v0059 = qcdr(v0059);
    v0059 = qcdr(v0059);
    v0059 = qcdr(v0059);
    v0059 = qcdr(v0059);
    v0059 = qcar(v0059);
    if (v0059 == nil) goto v0068;
    v0059 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v0059); }

v0068:
    v0059 = stack[0];
    v0059 = qcdr(v0059);
    v0059 = qcdr(v0059);
    v0010 = qcar(v0059);
    v0059 = (Lisp_Object)1; /* 0 */
    v0059 = Leqn(nil, v0010, v0059);
    nil = C_nil;
    if (exception_pending()) goto v0015;
    env = stack[-1];
    if (v0059 == nil) goto v0043;
    v0059 = stack[0];
    v0059 = qcdr(v0059);
    v0059 = qcdr(v0059);
    v0059 = qcdr(v0059);
    v0010 = qcar(v0059);
    v0059 = (Lisp_Object)1; /* 0 */
        popv(2);
        return Leqn(nil, v0010, v0059);

v0043:
    v0059 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v0059); }
/* error exit handlers */
v0015:
    popv(2);
    return nil;
}



/* Code for sub2chk */

static Lisp_Object CC_sub2chk(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0039, v0066, v0021;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sub2chk");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0021 = v0000;
/* end of prologue */
    v0039 = qvalue(elt(env, 1)); /* subfg!* */
    if (v0039 == nil) goto v0005;
    v0066 = v0021;
    v0039 = qvalue(elt(env, 2)); /* powlis!* */
    v0039 = Latsoc(nil, v0066, v0039);
    if (!(v0039 == nil)) goto v0008;
    v0039 = v0021;
    if (!consp(v0039)) goto v0049;
    v0039 = v0021;
    v0066 = qcar(v0039);
    v0039 = elt(env, 3); /* (expt sqrt) */
    v0039 = Lmemq(nil, v0066, v0039);
    goto v0034;

v0034:
    if (!(v0039 == nil)) goto v0008;

v0005:
    v0039 = nil;
    return onevalue(v0039);

v0008:
    v0039 = qvalue(elt(env, 5)); /* t */
    qvalue(elt(env, 6)) = v0039; /* !*sub2 */
    return onevalue(v0039);

v0049:
    v0039 = qvalue(elt(env, 4)); /* nil */
    goto v0034;
}



/* Code for butes */

static Lisp_Object CC_butes(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0015, v0031, v0060;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for butes");
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
    v0060 = v0000;
/* end of prologue */
    v0015 = v0060;
    v0015 = qcar(v0015);
    qvalue(elt(env, 1)) = v0015; /* cha */
    v0031 = qvalue(elt(env, 1)); /* cha */
    v0015 = elt(env, 2); /* !  */
    if (v0031 == v0015) goto v0007;
    v0031 = qvalue(elt(env, 1)); /* cha */
    v0015 = elt(env, 4); /* !$ */
    v0015 = (v0031 == v0015 ? lisp_true : nil);
    goto v0006;

v0006:
    if (v0015 == nil) goto v0066;
    v0015 = qvalue(elt(env, 5)); /* nil */
    { popv(1); return onevalue(v0015); }

v0066:
    v0015 = v0060;
    stack[0] = qcar(v0015);
    v0015 = v0060;
    v0015 = qcdr(v0015);
    v0015 = CC_butes(env, v0015);
    nil = C_nil;
    if (exception_pending()) goto v0048;
    {
        Lisp_Object v0047 = stack[0];
        popv(1);
        return cons(v0047, v0015);
    }

v0007:
    v0015 = qvalue(elt(env, 3)); /* t */
    goto v0006;
/* error exit handlers */
v0048:
    popv(1);
    return nil;
}



/* Code for noncomfp1 */

static Lisp_Object CC_noncomfp1(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0066;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for noncomfp1");
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

v0011:
    v0066 = stack[0];
    if (!consp(v0066)) goto v0001;
    v0066 = stack[0];
    v0066 = qcar(v0066);
    v0066 = (consp(v0066) ? nil : lisp_true);
    goto v0012;

v0012:
    if (v0066 == nil) goto v0008;
    v0066 = qvalue(elt(env, 2)); /* nil */
    { popv(2); return onevalue(v0066); }

v0008:
    v0066 = stack[0];
    v0066 = qcar(v0066);
    v0066 = qcar(v0066);
    v0066 = qcar(v0066);
    fn = elt(env, 3); /* noncomp */
    v0066 = (*qfn1(fn))(qenv(fn), v0066);
    nil = C_nil;
    if (exception_pending()) goto v0086;
    env = stack[-1];
    if (!(v0066 == nil)) { popv(2); return onevalue(v0066); }
    v0066 = stack[0];
    v0066 = qcar(v0066);
    v0066 = qcdr(v0066);
    v0066 = CC_noncomfp1(env, v0066);
    nil = C_nil;
    if (exception_pending()) goto v0086;
    env = stack[-1];
    if (!(v0066 == nil)) { popv(2); return onevalue(v0066); }
    v0066 = stack[0];
    v0066 = qcdr(v0066);
    stack[0] = v0066;
    goto v0011;

v0001:
    v0066 = qvalue(elt(env, 1)); /* t */
    goto v0012;
/* error exit handlers */
v0086:
    popv(2);
    return nil;
}



/* Code for ps!:getv */

static Lisp_Object CC_psTgetv(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0017)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0062, v0029, v0051;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ps:getv");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0017,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0017);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0017;
    v0051 = v0000;
/* end of prologue */
    v0029 = v0051;
    v0062 = elt(env, 1); /* !:ps!: */
    if (!consp(v0029)) goto v0059;
    v0029 = qcar(v0029);
    if (!(v0029 == v0062)) goto v0059;
    v0062 = v0051;
    v0062 = qcdr(v0062);
    if (symbolp(v0062)) goto v0053;
    v0062 = v0051;
    v0029 = qcdr(v0062);
    v0062 = stack[0];
    v0062 = *(Lisp_Object *)((char *)v0029 + (CELL-TAG_VECTOR) + ((int32_t)v0062/(16/CELL)));
    { popv(3); return onevalue(v0062); }

v0053:
    v0062 = v0051;
    v0062 = qcdr(v0062);
    fn = elt(env, 4); /* eval */
    v0029 = (*qfn1(fn))(qenv(fn), v0062);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    v0062 = stack[0];
    v0062 = *(Lisp_Object *)((char *)v0029 + (CELL-TAG_VECTOR) + ((int32_t)v0062/(16/CELL)));
    { popv(3); return onevalue(v0062); }

v0059:
    stack[-1] = elt(env, 2); /* tps */
    stack[0] = (Lisp_Object)17; /* 1 */
    v0062 = elt(env, 3); /* "PS:GETV: not a ps" */
    v0029 = v0051;
    v0062 = list2(v0062, v0029);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-2];
    {
        Lisp_Object v0065 = stack[-1];
        Lisp_Object v0097 = stack[0];
        popv(3);
        fn = elt(env, 5); /* rerror */
        return (*qfnn(fn))(qenv(fn), 3, v0065, v0097, v0062);
    }
/* error exit handlers */
v0064:
    popv(3);
    return nil;
}



/* Code for expchk */

static Lisp_Object CC_expchk(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0006, v0007;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for expchk");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0007 = v0000;
/* end of prologue */
    v0006 = qvalue(elt(env, 1)); /* !*exp */
    if (!(v0006 == nil)) return onevalue(v0007);
    v0006 = v0007;
    {
        fn = elt(env, 2); /* offexpchk */
        return (*qfn1(fn))(qenv(fn), v0006);
    }
}



/* Code for binding */

static Lisp_Object CC_binding(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0006, v0007;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for binding");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0006 = v0000;
/* end of prologue */
    if (!symbolp(v0006)) v0006 = nil;
    else { v0006 = qfastgets(v0006);
           if (v0006 != nil) { v0006 = elt(v0006, 13); /* binding */
#ifdef RECORD_GET
             if (v0006 != SPID_NOPROP)
                record_get(elt(fastget_names, 13), 1);
             else record_get(elt(fastget_names, 13), 0),
                v0006 = nil; }
           else record_get(elt(fastget_names, 13), 0); }
#else
             if (v0006 == SPID_NOPROP) v0006 = nil; }}
#endif
    v0007 = v0006;
    v0006 = v0007;
    if (v0006 == nil) goto v0001;
    v0006 = v0007;
    v0006 = qcar(v0006);
    return onevalue(v0006);

v0001:
    v0006 = nil;
    return onevalue(v0006);
}



/* Code for evlexcomp */

static Lisp_Object CC_evlexcomp(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0017)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0063, v0015;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for evlexcomp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0017,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0017);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0017;
    stack[-1] = v0000;
/* end of prologue */

v0005:
    v0063 = stack[-1];
    if (v0063 == nil) goto v0001;
    v0063 = stack[0];
    if (v0063 == nil) goto v0006;
    v0063 = stack[-1];
    v0015 = qcar(v0063);
    v0063 = stack[0];
    v0063 = qcar(v0063);
    fn = elt(env, 2); /* iequal */
    v0063 = (*qfn2(fn))(qenv(fn), v0015, v0063);
    nil = C_nil;
    if (exception_pending()) goto v0105;
    env = stack[-2];
    if (v0063 == nil) goto v0016;
    v0063 = stack[-1];
    v0063 = qcdr(v0063);
    stack[-1] = v0063;
    v0063 = stack[0];
    v0063 = qcdr(v0063);
    stack[0] = v0063;
    goto v0005;

v0016:
    v0063 = stack[-1];
    v0015 = qcar(v0063);
    v0063 = stack[0];
    v0063 = qcar(v0063);
    if (((int32_t)(v0015)) > ((int32_t)(v0063))) goto v0019;
    v0063 = (Lisp_Object)-15; /* -1 */
    { popv(3); return onevalue(v0063); }

v0019:
    v0063 = (Lisp_Object)17; /* 1 */
    { popv(3); return onevalue(v0063); }

v0006:
    v0063 = elt(env, 1); /* (0) */
    stack[0] = v0063;
    goto v0005;

v0001:
    v0063 = (Lisp_Object)1; /* 0 */
    { popv(3); return onevalue(v0063); }
/* error exit handlers */
v0105:
    popv(3);
    return nil;
}



/* Code for sc_getmat */

static Lisp_Object MS_CDECL CC_sc_getmat(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0053, v0014;
    Lisp_Object v0073, v0017, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "sc_getmat");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0017 = va_arg(aa, Lisp_Object);
    v0073 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sc_getmat");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0073,v0017,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0017,v0073);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0073;
    v0053 = v0017;
    v0014 = v0000;
/* end of prologue */
    stack[-1] = v0014;
    v0053 = sub1(v0053);
    nil = C_nil;
    if (exception_pending()) goto v0042;
    env = stack[-2];
    stack[-1] = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v0053/(16/CELL)));
    v0053 = stack[0];
    v0053 = sub1(v0053);
    nil = C_nil;
    if (exception_pending()) goto v0042;
    v0053 = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v0053/(16/CELL)));
    { popv(3); return onevalue(v0053); }
/* error exit handlers */
v0042:
    popv(3);
    return nil;
}



/* Code for prepf1a */

static Lisp_Object CC_prepf1a(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0017)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0024, v0050, v0068;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for prepf1a");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0017,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0017);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0024 = v0017;
    v0050 = v0000;
/* end of prologue */
    v0068 = v0050;
    v0050 = v0024;
    v0024 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 2); /* prepf1a_reversed */
    v0024 = (*qfnn(fn))(qenv(fn), 3, v0068, v0050, v0024);
    errexit();
        return Lnreverse(nil, v0024);
}



/* Code for addcomment */

static Lisp_Object CC_addcomment(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object v0027;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for addcomment");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0027 = v0000;
/* end of prologue */
    qvalue(elt(env, 1)) = v0027; /* cursym!* */
    return onevalue(v0027);
}



/* Code for round!* */

static Lisp_Object CC_roundH(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0007, v0043;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for round*");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0007 = v0000;
/* end of prologue */
    v0043 = v0007;
    v0043 = qcdr(v0043);
    if (!(!consp(v0043))) return onevalue(v0007);
    v0007 = qcdr(v0007);
    return onevalue(v0007);
}



/* Code for isanindex */

static Lisp_Object CC_isanindex(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0062, v0029, v0051;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for isanindex");
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
    v0051 = v0000;
/* end of prologue */
    v0062 = v0051;
    if (symbolp(v0062)) goto v0007;
    v0062 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v0062); }

v0007:
    v0029 = v0051;
    v0062 = qvalue(elt(env, 2)); /* physopindices!* */
    v0062 = Lmemq(nil, v0029, v0062);
    if (!(v0062 == nil)) { popv(1); return onevalue(v0062); }
    v0029 = v0051;
    v0062 = qvalue(elt(env, 3)); /* physopvarind!* */
    v0062 = Lmember(nil, v0029, v0062);
    if (!(v0062 == nil)) { popv(1); return onevalue(v0062); }
    v0029 = v0051;
    v0062 = qvalue(elt(env, 4)); /* frlis!* */
    v0062 = Lmemq(nil, v0029, v0062);
    if (v0062 == nil) goto v0016;
    v0029 = v0051;
    v0062 = qvalue(elt(env, 5)); /* frasc!* */
    fn = elt(env, 6); /* revassoc */
    v0062 = (*qfn2(fn))(qenv(fn), v0029, v0062);
    nil = C_nil;
    if (exception_pending()) goto v0106;
    env = stack[0];
    v0029 = qvalue(elt(env, 2)); /* physopindices!* */
    v0062 = Lmember(nil, v0062, v0029);
    { popv(1); return onevalue(v0062); }

v0016:
    v0062 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v0062); }
/* error exit handlers */
v0106:
    popv(1);
    return nil;
}



/* Code for union_edge */

static Lisp_Object CC_union_edge(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0017)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0044, v0045;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for union_edge");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0017,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0017);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0017;
    stack[-1] = v0000;
/* end of prologue */
    v0045 = stack[-1];
    v0044 = stack[0];
    fn = elt(env, 1); /* memq_edgelist */
    v0044 = (*qfn2(fn))(qenv(fn), v0045, v0044);
    nil = C_nil;
    if (exception_pending()) goto v0018;
    if (!(v0044 == nil)) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v0045 = stack[-1];
    v0044 = stack[0];
    popv(2);
    return cons(v0045, v0044);
/* error exit handlers */
v0018:
    popv(2);
    return nil;
}



/* Code for mo_divides!? */

static Lisp_Object CC_mo_dividesW(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0017)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0007, v0043;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mo_divides?");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0007 = v0017;
    v0043 = v0000;
/* end of prologue */
    v0043 = qcar(v0043);
    v0007 = qcar(v0007);
    {
        fn = elt(env, 1); /* mo!=modiv1 */
        return (*qfn2(fn))(qenv(fn), v0043, v0007);
    }
}



/* Code for dlesslex */

static Lisp_Object CC_dlesslex(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0017)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0022, v0023, v0058, v0059;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dlesslex");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0023 = v0017;
    v0058 = v0000;
/* end of prologue */

v0005:
    v0022 = v0058;
    if (v0022 == nil) goto v0001;
    v0022 = v0058;
    v0059 = qcar(v0022);
    v0022 = v0023;
    v0022 = qcar(v0022);
    if (((int32_t)(v0059)) > ((int32_t)(v0022))) goto v0006;
    v0022 = v0058;
    v0059 = qcar(v0022);
    v0022 = v0023;
    v0022 = qcar(v0022);
    if (((int32_t)(v0059)) < ((int32_t)(v0022))) goto v0041;
    v0022 = v0058;
    v0022 = qcdr(v0022);
    v0058 = v0022;
    v0022 = v0023;
    v0022 = qcdr(v0022);
    v0023 = v0022;
    goto v0005;

v0041:
    v0022 = qvalue(elt(env, 2)); /* t */
    return onevalue(v0022);

v0006:
    v0022 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v0022);

v0001:
    v0022 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v0022);
}



/* Code for hasonevector */

static Lisp_Object CC_hasonevector(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0033;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for hasonevector");
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

v0011:
    v0033 = stack[0];
    if (v0033 == nil) goto v0008;
    v0033 = stack[0];
    v0033 = qcar(v0033);
    fn = elt(env, 2); /* vecp */
    v0033 = (*qfn1(fn))(qenv(fn), v0033);
    nil = C_nil;
    if (exception_pending()) goto v0053;
    env = stack[-1];
    if (!(v0033 == nil)) { popv(2); return onevalue(v0033); }
    v0033 = stack[0];
    v0033 = qcdr(v0033);
    stack[0] = v0033;
    goto v0011;

v0008:
    v0033 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v0033); }
/* error exit handlers */
v0053:
    popv(2);
    return nil;
}



/* Code for reduce_pv0 */

static Lisp_Object MS_CDECL CC_reduce_pv0(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0101, v0118;
    Lisp_Object fn;
    Lisp_Object v0073, v0017, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "reduce_pv0");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0017 = va_arg(aa, Lisp_Object);
    v0073 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for reduce_pv0");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0073,v0017,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0017,v0073);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-3] = v0073;
    stack[-4] = v0017;
    stack[0] = v0000;
/* end of prologue */
    v0101 = stack[-4];
    if (v0101 == nil) { Lisp_Object res = stack[0]; popv(7); return onevalue(res); }
    v0101 = stack[0];
    if (v0101 == nil) goto v0003;
    v0101 = stack[0];
    stack[-5] = v0101;
    goto v0054;

v0054:
    v0101 = stack[-5];
    if (v0101 == nil) goto v0014;
    v0101 = stack[-4];
    if (v0101 == nil) goto v0014;
    v0101 = stack[-5];
    v0101 = qcar(v0101);
    v0118 = qcdr(v0101);
    v0101 = stack[-4];
    v0101 = qcar(v0101);
    v0101 = qcdr(v0101);
    v0101 = (Lisp_Object)greaterp2(v0118, v0101);
    nil = C_nil;
    if (exception_pending()) goto v0119;
    v0101 = v0101 ? lisp_true : nil;
    env = stack[-6];
    if (v0101 == nil) goto v0014;
    v0101 = stack[-5];
    v0101 = qcdr(v0101);
    stack[-5] = v0101;
    goto v0054;

v0014:
    v0101 = stack[-5];
    if (v0101 == nil) { Lisp_Object res = stack[0]; popv(7); return onevalue(res); }
    v0101 = stack[-4];
    if (v0101 == nil) { Lisp_Object res = stack[0]; popv(7); return onevalue(res); }
    v0101 = stack[-4];
    v0101 = qcar(v0101);
    v0118 = qcdr(v0101);
    v0101 = stack[-5];
    v0101 = qcar(v0101);
    v0101 = qcdr(v0101);
    if (!(equal(v0118, v0101))) { Lisp_Object res = stack[0]; popv(7); return onevalue(res); }
    v0101 = stack[-5];
    v0101 = qcar(v0101);
    v0118 = qcar(v0101);
    v0101 = stack[-4];
    v0101 = qcar(v0101);
    v0101 = qcar(v0101);
    fn = elt(env, 3); /* lcm */
    v0101 = (*qfn2(fn))(qenv(fn), v0118, v0101);
    nil = C_nil;
    if (exception_pending()) goto v0119;
    env = stack[-6];
    stack[-2] = v0101;
    v0118 = stack[-2];
    v0101 = stack[-5];
    v0101 = qcar(v0101);
    v0101 = qcar(v0101);
    v0101 = quot2(v0118, v0101);
    nil = C_nil;
    if (exception_pending()) goto v0119;
    env = stack[-6];
    fn = elt(env, 4); /* pv_multc */
    stack[-1] = (*qfn2(fn))(qenv(fn), stack[0], v0101);
    nil = C_nil;
    if (exception_pending()) goto v0119;
    env = stack[-6];
    stack[0] = stack[-4];
    v0118 = stack[-2];
    v0101 = stack[-4];
    v0101 = qcar(v0101);
    v0101 = qcar(v0101);
    v0101 = quot2(v0118, v0101);
    nil = C_nil;
    if (exception_pending()) goto v0119;
    env = stack[-6];
    v0101 = negate(v0101);
    nil = C_nil;
    if (exception_pending()) goto v0119;
    env = stack[-6];
    fn = elt(env, 4); /* pv_multc */
    v0101 = (*qfn2(fn))(qenv(fn), stack[0], v0101);
    nil = C_nil;
    if (exception_pending()) goto v0119;
    env = stack[-6];
    fn = elt(env, 5); /* pv_add */
    v0101 = (*qfn2(fn))(qenv(fn), stack[-1], v0101);
    nil = C_nil;
    if (exception_pending()) goto v0119;
    env = stack[-6];
    stack[0] = v0101;
    v0101 = stack[-3];
    if (v0101 == nil) goto v0120;
    v0101 = (Lisp_Object)17; /* 1 */
    qvalue(elt(env, 2)) = v0101; /* pv_den */
    { Lisp_Object res = stack[0]; popv(7); return onevalue(res); }

v0120:
    stack[-1] = qvalue(elt(env, 2)); /* pv_den */
    v0118 = stack[-2];
    v0101 = stack[-5];
    v0101 = qcar(v0101);
    v0101 = qcar(v0101);
    v0101 = quot2(v0118, v0101);
    nil = C_nil;
    if (exception_pending()) goto v0119;
    env = stack[-6];
    v0101 = times2(stack[-1], v0101);
    nil = C_nil;
    if (exception_pending()) goto v0119;
    env = stack[-6];
    qvalue(elt(env, 2)) = v0101; /* pv_den */
    { Lisp_Object res = stack[0]; popv(7); return onevalue(res); }

v0003:
    v0101 = qvalue(elt(env, 1)); /* nil */
    { popv(7); return onevalue(v0101); }
/* error exit handlers */
v0119:
    popv(7);
    return nil;
}



/* Code for modonep!: */

static Lisp_Object CC_modonepT(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0004, v0006;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for modonep:");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0004 = v0000;
/* end of prologue */
    v0006 = qcdr(v0004);
    v0004 = (Lisp_Object)17; /* 1 */
    v0004 = (v0006 == v0004 ? lisp_true : nil);
    return onevalue(v0004);
}



/* Code for getpower */

static Lisp_Object CC_getpower(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0017)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0020, v0022;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for getpower");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0017,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0017);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0017;
    stack[-1] = v0000;
/* end of prologue */
    v0020 = stack[-1];
    v0022 = qcar(v0020);
    v0020 = elt(env, 1); /* expt */
    if (!consp(v0022)) goto v0046;
    v0022 = qcar(v0022);
    if (!(v0022 == v0020)) goto v0046;
    v0022 = stack[0];
    v0020 = (Lisp_Object)17; /* 1 */
    v0020 = (Lisp_Object)greaterp2(v0022, v0020);
    nil = C_nil;
    if (exception_pending()) goto v0059;
    v0020 = v0020 ? lisp_true : nil;
    env = stack[-2];
    goto v0001;

v0001:
    if (v0020 == nil) goto v0049;
    v0020 = qvalue(elt(env, 3)); /* t */
    qvalue(elt(env, 4)) = v0020; /* !*sub2 */
    goto v0049;

v0049:
    v0020 = stack[-1];
    v0022 = qcar(v0020);
    v0020 = stack[0];
    popv(3);
    return cons(v0022, v0020);

v0046:
    v0020 = qvalue(elt(env, 2)); /* nil */
    goto v0001;
/* error exit handlers */
v0059:
    popv(3);
    return nil;
}



/* Code for multd */

static Lisp_Object CC_multd(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0017)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0035, v0036;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for multd");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0017,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0017);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0017;
    stack[-2] = v0000;
/* end of prologue */
    stack[-3] = nil;
    goto v0009;

v0009:
    v0035 = stack[-1];
    if (v0035 == nil) goto v0002;
    v0036 = stack[-1];
    v0035 = (Lisp_Object)17; /* 1 */
    if (v0036 == v0035) goto v0041;
    v0035 = stack[-1];
    if (!consp(v0035)) goto v0057;
    v0035 = stack[-1];
    v0035 = qcar(v0035);
    v0035 = (consp(v0035) ? nil : lisp_true);
    goto v0016;

v0016:
    if (v0035 == nil) goto v0062;
    stack[0] = stack[-3];
    v0036 = stack[-2];
    v0035 = stack[-1];
    fn = elt(env, 2); /* multdm */
    v0035 = (*qfn2(fn))(qenv(fn), v0036, v0035);
    nil = C_nil;
    if (exception_pending()) goto v0038;
    env = stack[-4];
    {
        Lisp_Object v0069 = stack[0];
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0069, v0035);
    }

v0062:
    v0035 = stack[-1];
    v0035 = qcar(v0035);
    stack[0] = qcar(v0035);
    v0036 = stack[-2];
    v0035 = stack[-1];
    v0035 = qcar(v0035);
    v0035 = qcdr(v0035);
    v0036 = CC_multd(env, v0036, v0035);
    nil = C_nil;
    if (exception_pending()) goto v0038;
    env = stack[-4];
    v0035 = stack[-3];
    v0035 = acons(stack[0], v0036, v0035);
    nil = C_nil;
    if (exception_pending()) goto v0038;
    env = stack[-4];
    stack[-3] = v0035;
    v0035 = stack[-1];
    v0035 = qcdr(v0035);
    stack[-1] = v0035;
    goto v0009;

v0057:
    v0035 = qvalue(elt(env, 1)); /* t */
    goto v0016;

v0041:
    v0036 = stack[-3];
    v0035 = stack[-2];
    {
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0036, v0035);
    }

v0002:
    v0035 = stack[-3];
    {
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v0035);
    }
/* error exit handlers */
v0038:
    popv(5);
    return nil;
}



/* Code for lalr_remove_duplicates */

static Lisp_Object CC_lalr_remove_duplicates(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0023, v0058, v0059, v0010;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for lalr_remove_duplicates");
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
    v0023 = v0000;
/* end of prologue */
    v0010 = nil;
    stack[0] = v0023;
    goto v0001;

v0001:
    v0023 = stack[0];
    if (v0023 == nil) goto v0012;
    v0023 = stack[0];
    v0023 = qcar(v0023);
    v0059 = v0023;
    v0058 = v0059;
    v0023 = v0010;
    v0023 = Lmember(nil, v0058, v0023);
    if (!(v0023 == nil)) goto v0034;
    v0023 = v0059;
    v0058 = v0010;
    v0023 = cons(v0023, v0058);
    nil = C_nil;
    if (exception_pending()) goto v0015;
    env = stack[-1];
    v0010 = v0023;
    goto v0034;

v0034:
    v0023 = stack[0];
    v0023 = qcdr(v0023);
    stack[0] = v0023;
    goto v0001;

v0012:
    v0023 = v0010;
        popv(2);
        return Lnreverse(nil, v0023);
/* error exit handlers */
v0015:
    popv(2);
    return nil;
}



/* Code for mtchp1 */

static Lisp_Object MS_CDECL CC_mtchp1(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0131, v0132, v0133;
    Lisp_Object fn;
    Lisp_Object v0027, v0073, v0017, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "mtchp1");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0017 = va_arg(aa, Lisp_Object);
    v0073 = va_arg(aa, Lisp_Object);
    v0027 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mtchp1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v0027,v0073,v0017,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0000,v0017,v0073,v0027);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    v0131 = v0027;
    stack[0] = v0073;
    stack[-1] = v0017;
    stack[-2] = v0000;
/* end of prologue */
    v0132 = stack[-2];
    v0131 = stack[-1];
    if (equal(v0132, v0131)) goto v0003;
    v0131 = stack[-2];
    v0132 = qcar(v0131);
    v0131 = stack[-1];
    v0131 = qcar(v0131);
    fn = elt(env, 5); /* mchk!* */
    v0131 = (*qfn2(fn))(qenv(fn), v0132, v0131);
    nil = C_nil;
    if (exception_pending()) goto v0134;
    env = stack[-4];
    stack[-3] = v0131;
    if (v0131 == nil) goto v0053;
    v0131 = stack[-1];
    v0132 = qcdr(v0131);
    v0131 = qvalue(elt(env, 2)); /* frlis!* */
    v0131 = Lmemq(nil, v0132, v0131);
    if (v0131 == nil) goto v0057;
    v0131 = stack[-2];
    v0132 = qcdr(v0131);
    v0131 = (Lisp_Object)17; /* 1 */
    if (v0132 == v0131) goto v0105;
    v0131 = stack[-1];
    v0133 = qcdr(v0131);
    v0132 = stack[-3];
    v0131 = stack[-2];
    v0131 = qcdr(v0131);
    fn = elt(env, 6); /* powmtch */
    v0131 = (*qfnn(fn))(qenv(fn), 3, v0133, v0132, v0131);
    nil = C_nil;
    if (exception_pending()) goto v0134;
    env = stack[-4];
    stack[-3] = v0131;
    v0131 = (v0131 == nil ? lisp_true : nil);
    goto v0060;

v0060:
    if (v0131 == nil) goto v0103;
    v0131 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v0131); }

v0103:
    stack[0] = stack[-3];
    v0131 = stack[-1];
    v0132 = qcdr(v0131);
    v0131 = stack[-2];
    v0131 = qcdr(v0131);
    v0131 = cons(v0132, v0131);
    nil = C_nil;
    if (exception_pending()) goto v0134;
    env = stack[-4];
    {
        Lisp_Object v0135 = stack[0];
        popv(5);
        fn = elt(env, 7); /* mapcons */
        return (*qfn2(fn))(qenv(fn), v0135, v0131);
    }

v0105:
    v0131 = qvalue(elt(env, 3)); /* t */
    goto v0060;

v0057:
    v0131 = stack[0];
    if (v0131 == nil) goto v0136;
    v0131 = stack[-2];
    v0132 = qcdr(v0131);
    v0131 = stack[-1];
    v0131 = qcdr(v0131);
    if (!(equal(v0132, v0131))) goto v0082;

v0136:
    v0131 = stack[-1];
    v0131 = qcdr(v0131);
    if (is_number(v0131)) goto v0137;
    v0131 = qvalue(elt(env, 3)); /* t */
    goto v0138;

v0138:
    if (v0131 == nil) { Lisp_Object res = stack[-3]; popv(5); return onevalue(res); }
    else goto v0082;

v0082:
    v0131 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v0131); }

v0137:
    v0131 = stack[-2];
    v0131 = qcdr(v0131);
    if (is_number(v0131)) goto v0139;
    v0131 = qvalue(elt(env, 3)); /* t */
    goto v0138;

v0139:
    v0131 = qvalue(elt(env, 4)); /* !*mcd */
    if (v0131 == nil) goto v0140;
    v0131 = stack[-2];
    v0132 = qcdr(v0131);
    v0131 = stack[-1];
    v0131 = qcdr(v0131);
    v0131 = (Lisp_Object)lessp2(v0132, v0131);
    nil = C_nil;
    if (exception_pending()) goto v0134;
    v0131 = v0131 ? lisp_true : nil;
    env = stack[-4];
    goto v0138;

v0140:
    v0131 = stack[-2];
    v0132 = qcdr(v0131);
    v0131 = stack[-1];
    v0131 = qcdr(v0131);
    v0132 = times2(v0132, v0131);
    nil = C_nil;
    if (exception_pending()) goto v0134;
    env = stack[-4];
    v0131 = (Lisp_Object)1; /* 0 */
    v0131 = (Lisp_Object)lessp2(v0132, v0131);
    nil = C_nil;
    if (exception_pending()) goto v0134;
    v0131 = v0131 ? lisp_true : nil;
    env = stack[-4];
    if (!(v0131 == nil)) goto v0138;
    v0131 = stack[-2];
    v0131 = qcdr(v0131);
    stack[0] = Labsval(nil, v0131);
    nil = C_nil;
    if (exception_pending()) goto v0134;
    env = stack[-4];
    v0131 = stack[-1];
    v0131 = qcdr(v0131);
    v0131 = Labsval(nil, v0131);
    nil = C_nil;
    if (exception_pending()) goto v0134;
    env = stack[-4];
    v0131 = (Lisp_Object)lessp2(stack[0], v0131);
    nil = C_nil;
    if (exception_pending()) goto v0134;
    v0131 = v0131 ? lisp_true : nil;
    env = stack[-4];
    goto v0138;

v0053:
    v0131 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v0131); }

v0003:
    v0131 = qvalue(elt(env, 1)); /* nil */
    popv(5);
    return ncons(v0131);
/* error exit handlers */
v0134:
    popv(5);
    return nil;
}



/* Code for tayexp!-greaterp */

static Lisp_Object CC_tayexpKgreaterp(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0017)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0004, v0006;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for tayexp-greaterp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0006 = v0017;
    v0004 = v0000;
/* end of prologue */
    {
        fn = elt(env, 1); /* tayexp!-lessp */
        return (*qfn2(fn))(qenv(fn), v0006, v0004);
    }
}



/* Code for !*d2q */

static Lisp_Object CC_Hd2q(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0047, v0061;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for *d2q");
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
    v0047 = stack[0];
    if (is_number(v0047)) goto v0008;
    v0047 = stack[0];
    fn = elt(env, 2); /* !:zerop */
    v0047 = (*qfn1(fn))(qenv(fn), v0047);
    nil = C_nil;
    if (exception_pending()) goto v0052;
    env = stack[-1];
    if (v0047 == nil) goto v0010;
    v0061 = qvalue(elt(env, 1)); /* nil */
    v0047 = (Lisp_Object)17; /* 1 */
    popv(2);
    return cons(v0061, v0047);

v0010:
    v0061 = stack[0];
    v0047 = (Lisp_Object)17; /* 1 */
    popv(2);
    return cons(v0061, v0047);

v0008:
    v0047 = stack[0];
    v0047 = (Lisp_Object)zerop(v0047);
    v0047 = v0047 ? lisp_true : nil;
    env = stack[-1];
    if (v0047 == nil) goto v0041;
    v0061 = qvalue(elt(env, 1)); /* nil */
    v0047 = (Lisp_Object)17; /* 1 */
    popv(2);
    return cons(v0061, v0047);

v0041:
    v0061 = stack[0];
    v0047 = (Lisp_Object)17; /* 1 */
    popv(2);
    return cons(v0061, v0047);
/* error exit handlers */
v0052:
    popv(2);
    return nil;
}



/* Code for mri_floorkernelp */

static Lisp_Object CC_mri_floorkernelp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0005;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mri_floorkernelp");
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
    v0005 = v0000;
/* end of prologue */
    fn = elt(env, 1); /* kernels */
    v0005 = (*qfn1(fn))(qenv(fn), v0005);
    nil = C_nil;
    if (exception_pending()) goto v0009;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* mri_floorp */
        return (*qfn1(fn))(qenv(fn), v0005);
    }
/* error exit handlers */
v0009:
    popv(1);
    return nil;
}



/* Code for qqe_rbopp */

static Lisp_Object CC_qqe_rbopp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0003, v0004;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for qqe_rbopp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0003 = v0000;
/* end of prologue */
    v0004 = elt(env, 1); /* (equal neq lessp leq geq greaterp) */
    v0003 = Lmemq(nil, v0003, v0004);
    return onevalue(v0003);
}



/* Code for kernels1 */

static Lisp_Object CC_kernels1(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0017)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0064, v0065, v0097, v0076;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for kernels1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0017,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0017);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    v0097 = v0017;
    v0064 = v0000;
/* end of prologue */

v0011:
    v0065 = v0064;
    if (!consp(v0065)) goto v0002;
    v0065 = v0064;
    v0065 = qcar(v0065);
    v0065 = (consp(v0065) ? nil : lisp_true);
    goto v0001;

v0001:
    if (!(v0065 == nil)) { popv(4); return onevalue(v0097); }
    v0065 = v0064;
    v0065 = qcar(v0065);
    v0065 = qcar(v0065);
    v0065 = qcar(v0065);
    v0076 = v0065;
    v0065 = v0064;
    v0065 = qcar(v0065);
    stack[-2] = qcdr(v0065);
    stack[-1] = qcdr(v0064);
    v0065 = v0076;
    v0064 = v0097;
    v0064 = Lmemq(nil, v0065, v0064);
    if (v0064 == nil) goto v0109;
    v0064 = v0097;
    goto v0021;

v0021:
    v0065 = CC_kernels1(env, stack[-1], v0064);
    nil = C_nil;
    if (exception_pending()) goto v0108;
    env = stack[-3];
    v0064 = stack[-2];
    v0097 = v0065;
    goto v0011;

v0109:
    stack[0] = v0097;
    v0064 = v0076;
    v0064 = ncons(v0064);
    nil = C_nil;
    if (exception_pending()) goto v0108;
    env = stack[-3];
    v0064 = Lappend(nil, stack[0], v0064);
    nil = C_nil;
    if (exception_pending()) goto v0108;
    env = stack[-3];
    goto v0021;

v0002:
    v0065 = qvalue(elt(env, 1)); /* t */
    goto v0001;
/* error exit handlers */
v0108:
    popv(4);
    return nil;
}



/* Code for lto_setequalq */

static Lisp_Object CC_lto_setequalq(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0017)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0141, v0079, v0077;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for lto_setequalq");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0017,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0017);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0017;
    stack[-1] = v0000;
/* end of prologue */
    v0141 = qvalue(elt(env, 1)); /* !*rlsetequalqhash */
    if (v0141 == nil) goto v0055;
    v0079 = stack[-1];
    v0141 = stack[0];
    fn = elt(env, 4); /* lto_hashequalq */
    v0141 = (*qfn2(fn))(qenv(fn), v0079, v0141);
    nil = C_nil;
    if (exception_pending()) goto v0103;
    env = stack[-2];
    goto v0050;

v0050:
    if (v0141 == nil) goto v0086;
    v0141 = qvalue(elt(env, 3)); /* t */
    v0077 = v0141;
    goto v0063;

v0063:
    v0141 = v0077;
    if (v0141 == nil) { popv(3); return onevalue(v0077); }
    v0141 = stack[-1];
    if (v0141 == nil) { popv(3); return onevalue(v0077); }
    v0141 = stack[-1];
    v0141 = qcar(v0141);
    v0079 = v0141;
    v0141 = stack[0];
    v0141 = Lmemq(nil, v0079, v0141);
    if (v0141 == nil) goto v0107;
    v0141 = stack[-1];
    v0141 = qcdr(v0141);
    stack[-1] = v0141;
    goto v0063;

v0107:
    v0141 = qvalue(elt(env, 2)); /* nil */
    v0077 = v0141;
    goto v0063;

v0086:
    v0141 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v0141); }

v0055:
    v0079 = stack[-1];
    v0141 = stack[0];
    fn = elt(env, 5); /* lto_equallengthp */
    v0141 = (*qfn2(fn))(qenv(fn), v0079, v0141);
    nil = C_nil;
    if (exception_pending()) goto v0103;
    env = stack[-2];
    goto v0050;
/* error exit handlers */
v0103:
    popv(3);
    return nil;
}



/* Code for aex_ex */

static Lisp_Object CC_aex_ex(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0003, v0004;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for aex_ex");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0003 = v0000;
/* end of prologue */
    v0004 = v0003;
    v0003 = (Lisp_Object)33; /* 2 */
    {
        fn = elt(env, 1); /* nth */
        return (*qfn2(fn))(qenv(fn), v0004, v0003);
    }
}



/* Code for addd */

static Lisp_Object CC_addd(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0017)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0028, v0062;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for addd");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0017,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0017);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0017;
    stack[-1] = v0000;
/* end of prologue */
    v0062 = nil;
    goto v0009;

v0009:
    v0028 = stack[0];
    if (v0028 == nil) goto v0024;
    v0028 = stack[0];
    if (!consp(v0028)) goto v0041;
    v0028 = stack[0];
    v0028 = qcar(v0028);
    v0028 = (consp(v0028) ? nil : lisp_true);
    goto v0054;

v0054:
    if (v0028 == nil) goto v0105;
    stack[-2] = v0062;
    v0062 = stack[-1];
    v0028 = stack[0];
    fn = elt(env, 2); /* adddm */
    v0028 = (*qfn2(fn))(qenv(fn), v0062, v0028);
    nil = C_nil;
    if (exception_pending()) goto v0040;
    env = stack[-3];
    {
        Lisp_Object v0064 = stack[-2];
        popv(4);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0064, v0028);
    }

v0105:
    v0028 = stack[0];
    v0028 = qcar(v0028);
    v0028 = cons(v0028, v0062);
    nil = C_nil;
    if (exception_pending()) goto v0040;
    env = stack[-3];
    v0062 = v0028;
    v0028 = stack[0];
    v0028 = qcdr(v0028);
    stack[0] = v0028;
    goto v0009;

v0041:
    v0028 = qvalue(elt(env, 1)); /* t */
    goto v0054;

v0024:
    v0028 = stack[-1];
    {
        popv(4);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0062, v0028);
    }
/* error exit handlers */
v0040:
    popv(4);
    return nil;
}



/* Code for compress!* */

static Lisp_Object CC_compressH(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0144, v0095, v0114, v0096;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for compress*");
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
    v0144 = v0000;
/* end of prologue */
    v0096 = nil;
    v0095 = v0144;
    v0095 = qcar(v0095);
    v0095 = Ldigitp(nil, v0095);
    env = stack[-1];
    if (v0095 == nil) goto v0009;
        popv(2);
        return Lcompress(nil, v0144);

v0009:
    stack[0] = v0144;
    goto v0068;

v0068:
    v0144 = stack[0];
    if (v0144 == nil) goto v0050;
    v0144 = stack[0];
    v0144 = qcar(v0144);
    v0114 = v0144;
    v0095 = v0114;
    v0144 = elt(env, 2); /* !/ */
    if (v0095 == v0144) goto v0016;
    v0095 = v0114;
    v0144 = elt(env, 4); /* !- */
    if (v0095 == v0144) goto v0015;
    v0095 = v0114;
    v0144 = elt(env, 5); /* !; */
    if (v0095 == v0144) goto v0062;
    v0095 = v0114;
    v0144 = elt(env, 6); /* !. */
    v0144 = (v0095 == v0144 ? lisp_true : nil);
    goto v0049;

v0049:
    if (v0144 == nil) goto v0080;
    v0095 = v0114;
    v0144 = elt(env, 7); /* !! */
    v0114 = v0096;
    v0144 = list2star(v0095, v0144, v0114);
    nil = C_nil;
    if (exception_pending()) goto v0122;
    env = stack[-1];
    v0096 = v0144;
    goto v0032;

v0032:
    v0144 = stack[0];
    v0144 = qcdr(v0144);
    stack[0] = v0144;
    goto v0068;

v0080:
    v0144 = v0114;
    v0095 = v0096;
    v0144 = cons(v0144, v0095);
    nil = C_nil;
    if (exception_pending()) goto v0122;
    env = stack[-1];
    v0096 = v0144;
    goto v0032;

v0062:
    v0144 = qvalue(elt(env, 3)); /* t */
    goto v0049;

v0015:
    v0144 = qvalue(elt(env, 3)); /* t */
    goto v0049;

v0016:
    v0144 = qvalue(elt(env, 3)); /* t */
    goto v0049;

v0050:
    v0144 = v0096;
    v0144 = Lnreverse(nil, v0144);
    env = stack[-1];
    v0144 = Lcompress(nil, v0144);
    nil = C_nil;
    if (exception_pending()) goto v0122;
        popv(2);
        return Lintern(nil, v0144);
/* error exit handlers */
v0122:
    popv(2);
    return nil;
}



/* Code for ldepends */

static Lisp_Object CC_ldepends(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0017)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0023, v0058;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ldepends");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0017,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0017);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0017;
    stack[-1] = v0000;
/* end of prologue */

v0011:
    v0023 = stack[-1];
    if (v0023 == nil) goto v0005;
    v0023 = stack[-1];
    if (!consp(v0023)) goto v0007;
    v0023 = stack[-1];
    v0058 = qcar(v0023);
    v0023 = stack[0];
    fn = elt(env, 2); /* depends */
    v0023 = (*qfn2(fn))(qenv(fn), v0058, v0023);
    nil = C_nil;
    if (exception_pending()) goto v0063;
    env = stack[-2];
    if (!(v0023 == nil)) { popv(3); return onevalue(v0023); }
    v0023 = stack[-1];
    v0058 = qcdr(v0023);
    v0023 = stack[0];
    stack[-1] = v0058;
    stack[0] = v0023;
    goto v0011;

v0007:
    v0058 = stack[-1];
    v0023 = stack[0];
    {
        popv(3);
        fn = elt(env, 2); /* depends */
        return (*qfn2(fn))(qenv(fn), v0058, v0023);
    }

v0005:
    v0023 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v0023); }
/* error exit handlers */
v0063:
    popv(3);
    return nil;
}



/* Code for numlis */

static Lisp_Object CC_numlis(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0014, v0054;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for numlis");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0014 = v0000;
/* end of prologue */

v0011:
    v0054 = v0014;
    if (v0054 == nil) goto v0008;
    v0054 = v0014;
    v0054 = qcar(v0054);
    if (is_number(v0054)) goto v0068;
    v0014 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v0014);

v0068:
    v0014 = qcdr(v0014);
    goto v0011;

v0008:
    v0014 = qvalue(elt(env, 1)); /* t */
    return onevalue(v0014);
}



/* Code for !:minusp */

static Lisp_Object CC_Tminusp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0053, v0014;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for :minusp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0053 = v0000;
/* end of prologue */
    v0014 = v0053;
    if (!consp(v0014)) goto v0008;
    v0014 = v0053;
    v0014 = qcar(v0014);
    if (!symbolp(v0014)) v0014 = nil;
    else { v0014 = qfastgets(v0014);
           if (v0014 != nil) { v0014 = elt(v0014, 30); /* minusp */
#ifdef RECORD_GET
             if (v0014 != SPID_NOPROP)
                record_get(elt(fastget_names, 30), 1);
             else record_get(elt(fastget_names, 30), 0),
                v0014 = nil; }
           else record_get(elt(fastget_names, 30), 0); }
#else
             if (v0014 == SPID_NOPROP) v0014 = nil; }}
#endif
        return Lapply1(nil, v0014, v0053);

v0008:
        return Lminusp(nil, v0053);
}



/* Code for evzero!? */

static Lisp_Object CC_evzeroW(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0046, v0032, v0018;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for evzero?");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0032 = v0000;
/* end of prologue */

v0011:
    v0046 = v0032;
    if (v0046 == nil) goto v0008;
    v0046 = v0032;
    v0018 = qcar(v0046);
    v0046 = (Lisp_Object)1; /* 0 */
    if (v0018 == v0046) goto v0006;
    v0046 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v0046);

v0006:
    v0046 = v0032;
    v0046 = qcdr(v0046);
    v0032 = v0046;
    goto v0011;

v0008:
    v0046 = qvalue(elt(env, 1)); /* t */
    return onevalue(v0046);
}



/* Code for factorordp */

static Lisp_Object CC_factorordp(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0017)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0042, v0044, v0045, v0046;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for factorordp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0045 = v0017;
    v0046 = v0000;
/* end of prologue */
    v0044 = v0046;
    v0042 = v0045;
    if (v0044 == v0042) goto v0005;
    v0042 = v0046;
    v0044 = v0045;
    {
        fn = elt(env, 2); /* worderp */
        return (*qfn2(fn))(qenv(fn), v0042, v0044);
    }

v0005:
    v0042 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v0042);
}



/* Code for degr */

static Lisp_Object CC_degr(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0017)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0058, v0059, v0010;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for degr");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0059 = v0017;
    v0010 = v0000;
/* end of prologue */
    v0058 = v0010;
    if (!consp(v0058)) goto v0007;
    v0058 = v0010;
    v0058 = qcar(v0058);
    v0058 = (consp(v0058) ? nil : lisp_true);
    goto v0006;

v0006:
    if (v0058 == nil) goto v0042;
    v0058 = qvalue(elt(env, 1)); /* t */
    goto v0001;

v0001:
    if (v0058 == nil) goto v0066;
    v0058 = (Lisp_Object)1; /* 0 */
    return onevalue(v0058);

v0066:
    v0058 = v0010;
    v0058 = qcar(v0058);
    v0058 = qcar(v0058);
    v0058 = qcdr(v0058);
    return onevalue(v0058);

v0042:
    v0058 = v0010;
    v0058 = qcar(v0058);
    v0058 = qcar(v0058);
    v0058 = qcar(v0058);
    v0058 = (v0058 == v0059 ? lisp_true : nil);
    v0058 = (v0058 == nil ? lisp_true : nil);
    goto v0001;

v0007:
    v0058 = qvalue(elt(env, 1)); /* t */
    goto v0006;
}



/* Code for mkround */

static Lisp_Object CC_mkround(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0013, v0033;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mkround");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0033 = v0000;
/* end of prologue */
    v0013 = v0033;
    if (!(!consp(v0013))) return onevalue(v0033);
    v0013 = elt(env, 1); /* !:rd!: */
    return cons(v0013, v0033);
}



/* Code for collectindices */

static Lisp_Object CC_collectindices(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0004, v0006;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for collectindices");
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
    v0004 = v0000;
/* end of prologue */
    v0006 = v0004;
    v0004 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 2); /* collectindices_reversed */
    v0004 = (*qfn2(fn))(qenv(fn), v0006, v0004);
    errexit();
        return Lnreverse(nil, v0004);
}



/* Code for getrtypecar */

static Lisp_Object CC_getrtypecar(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0005;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for getrtypecar");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0005 = v0000;
/* end of prologue */
    v0005 = qcar(v0005);
    {
        fn = elt(env, 1); /* getrtype */
        return (*qfn1(fn))(qenv(fn), v0005);
    }
}



/* Code for poly!-multf */

static Lisp_Object CC_polyKmultf(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0017)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0190, v0191, v0192;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for poly-multf");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0017,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0017);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0017;
    stack[-2] = v0000;
/* end of prologue */
    stack[-3] = nil;
    goto v0012;

v0012:
    v0190 = stack[-2];
    if (v0190 == nil) goto v0043;
    v0190 = stack[-1];
    v0190 = (v0190 == nil ? lisp_true : nil);
    goto v0007;

v0007:
    if (v0190 == nil) goto v0042;
    v0190 = qvalue(elt(env, 2)); /* nil */
    { popv(5); return onevalue(v0190); }

v0042:
    v0191 = stack[-2];
    v0190 = (Lisp_Object)17; /* 1 */
    if (v0191 == v0190) { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }
    v0191 = stack[-1];
    v0190 = (Lisp_Object)17; /* 1 */
    if (v0191 == v0190) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v0190 = stack[-2];
    if (!consp(v0190)) goto v0063;
    v0190 = stack[-2];
    v0190 = qcar(v0190);
    v0190 = (consp(v0190) ? nil : lisp_true);
    goto v0010;

v0010:
    if (v0190 == nil) goto v0058;
    v0191 = stack[-2];
    v0190 = stack[-1];
    {
        popv(5);
        fn = elt(env, 10); /* multd */
        return (*qfn2(fn))(qenv(fn), v0191, v0190);
    }

v0058:
    v0190 = stack[-1];
    if (!consp(v0190)) goto v0065;
    v0190 = stack[-1];
    v0190 = qcar(v0190);
    v0190 = (consp(v0190) ? nil : lisp_true);
    goto v0064;

v0064:
    if (v0190 == nil) goto v0106;
    v0191 = stack[-1];
    v0190 = stack[-2];
    {
        popv(5);
        fn = elt(env, 10); /* multd */
        return (*qfn2(fn))(qenv(fn), v0191, v0190);
    }

v0106:
    v0190 = qvalue(elt(env, 3)); /* !*exp */
    if (!(v0190 == nil)) goto v0002;
    v0190 = qvalue(elt(env, 4)); /* ncmp!* */
    if (!(v0190 == nil)) goto v0002;
    v0190 = qvalue(elt(env, 5)); /* wtl!* */
    if (!(v0190 == nil)) goto v0002;
    v0190 = stack[-3];
    if (!(v0190 == nil)) goto v0002;
    v0190 = stack[-2];
    fn = elt(env, 11); /* mkprod */
    v0190 = (*qfn1(fn))(qenv(fn), v0190);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-4];
    stack[-2] = v0190;
    v0190 = stack[-1];
    fn = elt(env, 11); /* mkprod */
    v0190 = (*qfn1(fn))(qenv(fn), v0190);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-4];
    stack[-1] = v0190;
    v0190 = qvalue(elt(env, 1)); /* t */
    stack[-3] = v0190;
    goto v0012;

v0002:
    v0190 = stack[-2];
    v0190 = qcar(v0190);
    v0190 = qcar(v0190);
    v0190 = qcar(v0190);
    stack[-3] = v0190;
    v0190 = stack[-1];
    v0190 = qcar(v0190);
    v0190 = qcar(v0190);
    v0190 = qcar(v0190);
    stack[0] = v0190;
    v0190 = stack[-1];
    fn = elt(env, 12); /* noncomfp */
    v0190 = (*qfn1(fn))(qenv(fn), v0190);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-4];
    if (v0190 == nil) goto v0089;
    v0190 = stack[-3];
    fn = elt(env, 13); /* noncomp */
    v0190 = (*qfn1(fn))(qenv(fn), v0190);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-4];
    if (!(v0190 == nil)) goto v0091;
    v0190 = qvalue(elt(env, 6)); /* !*!*processed */
    if (!(v0190 == nil)) goto v0089;

v0091:
    v0191 = stack[-2];
    v0190 = stack[-1];
    {
        popv(5);
        fn = elt(env, 14); /* poly!-multfnc */
        return (*qfn2(fn))(qenv(fn), v0191, v0190);
    }

v0089:
    v0191 = stack[-3];
    v0190 = stack[0];
    if (v0191 == v0190) goto v0194;
    v0191 = stack[-3];
    v0190 = stack[0];
    fn = elt(env, 15); /* ordop */
    v0190 = (*qfn2(fn))(qenv(fn), v0191, v0190);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-4];
    if (v0190 == nil) goto v0195;
    v0190 = stack[-2];
    v0190 = qcar(v0190);
    v0191 = qcdr(v0190);
    v0190 = stack[-1];
    v0190 = CC_polyKmultf(env, v0191, v0190);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-4];
    stack[-3] = v0190;
    v0190 = stack[-2];
    v0191 = qcdr(v0190);
    v0190 = stack[-1];
    v0190 = CC_polyKmultf(env, v0191, v0190);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    stack[0] = v0190;
    v0190 = stack[-3];
    if (v0190 == nil) { Lisp_Object res = stack[0]; popv(5); return onevalue(res); }
    v0190 = stack[-2];
    v0190 = qcar(v0190);
    v0192 = qcar(v0190);
    v0191 = stack[-3];
    v0190 = stack[0];
    popv(5);
    return acons(v0192, v0191, v0190);

v0195:
    v0191 = stack[-2];
    v0190 = stack[-1];
    v0190 = qcar(v0190);
    v0190 = qcdr(v0190);
    v0190 = CC_polyKmultf(env, v0191, v0190);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-4];
    stack[-3] = v0190;
    v0191 = stack[-2];
    v0190 = stack[-1];
    v0190 = qcdr(v0190);
    v0190 = CC_polyKmultf(env, v0191, v0190);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    stack[0] = v0190;
    v0190 = stack[-3];
    if (v0190 == nil) { Lisp_Object res = stack[0]; popv(5); return onevalue(res); }
    v0190 = stack[-1];
    v0190 = qcar(v0190);
    v0192 = qcar(v0190);
    v0191 = stack[-3];
    v0190 = stack[0];
    popv(5);
    return acons(v0192, v0191, v0190);

v0194:
    v0190 = stack[-2];
    v0190 = qcar(v0190);
    v0190 = qcar(v0190);
    v0190 = qcdr(v0190);
    v0190 = integerp(v0190);
    if (v0190 == nil) goto v0130;
    v0190 = stack[-1];
    v0190 = qcar(v0190);
    v0190 = qcar(v0190);
    v0190 = qcdr(v0190);
    v0190 = integerp(v0190);
    v0190 = (v0190 == nil ? lisp_true : nil);
    goto v0196;

v0196:
    if (v0190 == nil) goto v0197;
    stack[0] = stack[-3];
    v0192 = elt(env, 7); /* plus */
    v0190 = stack[-2];
    v0190 = qcar(v0190);
    v0190 = qcar(v0190);
    v0191 = qcdr(v0190);
    v0190 = stack[-1];
    v0190 = qcar(v0190);
    v0190 = qcar(v0190);
    v0190 = qcdr(v0190);
    v0190 = list3(v0192, v0191, v0190);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-4];
    fn = elt(env, 16); /* reval */
    v0190 = (*qfn1(fn))(qenv(fn), v0190);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-4];
    fn = elt(env, 17); /* to */
    v0190 = (*qfn2(fn))(qenv(fn), stack[0], v0190);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-4];
    stack[-3] = v0190;
    goto v0198;

v0198:
    v0190 = stack[-2];
    v0191 = qcdr(v0190);
    v0190 = stack[-1];
    stack[0] = CC_polyKmultf(env, v0191, v0190);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-4];
    v0190 = stack[-2];
    v0190 = qcar(v0190);
    v0191 = ncons(v0190);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-4];
    v0190 = stack[-1];
    v0190 = qcdr(v0190);
    v0190 = CC_polyKmultf(env, v0191, v0190);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-4];
    fn = elt(env, 18); /* addf */
    v0190 = (*qfn2(fn))(qenv(fn), stack[0], v0190);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-4];
    stack[0] = v0190;
    v0190 = stack[-3];
    if (v0190 == nil) goto v0199;
    v0190 = stack[-2];
    v0190 = qcar(v0190);
    v0191 = qcdr(v0190);
    v0190 = stack[-1];
    v0190 = qcar(v0190);
    v0190 = qcdr(v0190);
    v0190 = CC_polyKmultf(env, v0191, v0190);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-4];
    stack[-2] = v0190;
    v0190 = (v0190 == nil ? lisp_true : nil);
    goto v0200;

v0200:
    if (v0190 == nil) goto v0201;
    v0190 = qvalue(elt(env, 1)); /* t */
    qvalue(elt(env, 8)) = v0190; /* !*asymp!* */
    { Lisp_Object res = stack[0]; popv(5); return onevalue(res); }

v0201:
    v0191 = stack[-3];
    v0190 = (Lisp_Object)17; /* 1 */
    if (v0191 == v0190) goto v0202;
    v0190 = qvalue(elt(env, 9)); /* !*mcd */
    if (v0190 == nil) goto v0203;
    v0192 = stack[-3];
    v0191 = stack[-2];
    v0190 = stack[0];
    popv(5);
    return acons(v0192, v0191, v0190);

v0203:
    v0191 = stack[-3];
    v0190 = stack[-2];
    v0190 = cons(v0191, v0190);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-4];
    v0191 = ncons(v0190);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-4];
    v0190 = stack[0];
    {
        popv(5);
        fn = elt(env, 18); /* addf */
        return (*qfn2(fn))(qenv(fn), v0191, v0190);
    }

v0202:
    v0191 = stack[-2];
    v0190 = stack[0];
    {
        popv(5);
        fn = elt(env, 18); /* addf */
        return (*qfn2(fn))(qenv(fn), v0191, v0190);
    }

v0199:
    v0190 = qvalue(elt(env, 1)); /* t */
    goto v0200;

v0197:
    stack[0] = stack[-3];
    v0190 = stack[-2];
    v0190 = qcar(v0190);
    v0190 = qcar(v0190);
    v0191 = qcdr(v0190);
    v0190 = stack[-1];
    v0190 = qcar(v0190);
    v0190 = qcar(v0190);
    v0190 = qcdr(v0190);
    v0190 = plus2(v0191, v0190);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-4];
    fn = elt(env, 19); /* mkspm */
    v0190 = (*qfn2(fn))(qenv(fn), stack[0], v0190);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-4];
    stack[-3] = v0190;
    goto v0198;

v0130:
    v0190 = qvalue(elt(env, 1)); /* t */
    goto v0196;

v0065:
    v0190 = qvalue(elt(env, 1)); /* t */
    goto v0064;

v0063:
    v0190 = qvalue(elt(env, 1)); /* t */
    goto v0010;

v0043:
    v0190 = qvalue(elt(env, 1)); /* t */
    goto v0007;
/* error exit handlers */
v0193:
    popv(5);
    return nil;
}



/* Code for cali_bc_prod */

static Lisp_Object CC_cali_bc_prod(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0017)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0006, v0007;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for cali_bc_prod");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0017,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0017);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v0006 = v0017;
    v0007 = v0000;
/* end of prologue */
    fn = elt(env, 1); /* multf */
    v0006 = (*qfn2(fn))(qenv(fn), v0007, v0006);
    nil = C_nil;
    if (exception_pending()) goto v0043;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* bc!=simp */
        return (*qfn1(fn))(qenv(fn), v0006);
    }
/* error exit handlers */
v0043:
    popv(1);
    return nil;
}



/* Code for mtp */

static Lisp_Object CC_mtp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0010, v0063, v0015;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mtp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0063 = v0000;
/* end of prologue */

v0011:
    v0010 = v0063;
    if (v0010 == nil) goto v0008;
    v0010 = v0063;
    v0015 = qcar(v0010);
    v0010 = qvalue(elt(env, 2)); /* frlis!* */
    v0010 = Lmemq(nil, v0015, v0010);
    if (v0010 == nil) goto v0006;
    v0010 = v0063;
    v0015 = qcar(v0010);
    v0010 = v0063;
    v0010 = qcdr(v0010);
    v0010 = Lmember(nil, v0015, v0010);
    if (v0010 == nil) goto v0046;
    v0010 = qvalue(elt(env, 3)); /* nil */
    return onevalue(v0010);

v0046:
    v0010 = v0063;
    v0010 = qcdr(v0010);
    v0063 = v0010;
    goto v0011;

v0006:
    v0010 = qvalue(elt(env, 3)); /* nil */
    return onevalue(v0010);

v0008:
    v0010 = qvalue(elt(env, 1)); /* t */
    return onevalue(v0010);
}



/* Code for pappl */

static Lisp_Object CC_pappl(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0017)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0030, v0028;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pappl");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0017,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0017);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v0017;
    stack[-3] = v0000;
/* end of prologue */
    stack[-4] = nil;
    v0030 = stack[-3];
    fn = elt(env, 2); /* unpkp */
    v0030 = (*qfn1(fn))(qenv(fn), v0030);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-5];
    stack[-3] = v0030;
    goto v0007;

v0007:
    v0030 = stack[-3];
    if (v0030 == nil) goto v0006;
    v0030 = stack[-2];
    stack[-1] = v0030;
    v0030 = (Lisp_Object)17; /* 1 */
    stack[0] = v0030;
    goto v0019;

v0019:
    v0030 = stack[-3];
    v0030 = qcar(v0030);
    v0028 = sub1(v0030);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-5];
    v0030 = stack[0];
    v0030 = difference2(v0028, v0030);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-5];
    v0030 = Lminusp(nil, v0030);
    env = stack[-5];
    if (v0030 == nil) goto v0045;
    v0030 = stack[-1];
    v0028 = qcar(v0030);
    v0030 = stack[-4];
    v0030 = cons(v0028, v0030);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-5];
    stack[-4] = v0030;
    v0030 = stack[-3];
    v0030 = qcdr(v0030);
    stack[-3] = v0030;
    goto v0007;

v0045:
    v0030 = stack[-1];
    v0030 = qcdr(v0030);
    stack[-1] = v0030;
    v0030 = stack[0];
    v0030 = add1(v0030);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-5];
    stack[0] = v0030;
    goto v0019;

v0006:
    v0030 = stack[-4];
        popv(6);
        return Lnreverse(nil, v0030);
/* error exit handlers */
v0064:
    popv(6);
    return nil;
}



/* Code for rnequiv */

static Lisp_Object CC_rnequiv(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0034, v0053, v0014;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rnequiv");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0053 = v0000;
/* end of prologue */
    v0034 = v0053;
    v0034 = qcdr(v0034);
    v0053 = v0034;
    v0014 = qcdr(v0034);
    v0034 = (Lisp_Object)17; /* 1 */
    if (v0014 == v0034) goto v0008;
    v0034 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v0034);

v0008:
    v0034 = v0053;
    v0034 = qcar(v0034);
    return onevalue(v0034);
}



/* Code for !*i2mod */

static Lisp_Object CC_Hi2mod(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0005;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for *i2mod");
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
    v0005 = v0000;
/* end of prologue */
    fn = elt(env, 1); /* general!-modular!-number */
    v0005 = (*qfn1(fn))(qenv(fn), v0005);
    nil = C_nil;
    if (exception_pending()) goto v0009;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* !*modular2f */
        return (*qfn1(fn))(qenv(fn), v0005);
    }
/* error exit handlers */
v0009:
    popv(1);
    return nil;
}



/* Code for general!-modular!-times */

static Lisp_Object CC_generalKmodularKtimes(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0017)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0022, v0023;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for general-modular-times");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0017,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0017);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0022 = v0017;
    v0023 = v0000;
/* end of prologue */
    v0023 = times2(v0023, v0022);
    nil = C_nil;
    if (exception_pending()) goto v0059;
    env = stack[-1];
    v0022 = qvalue(elt(env, 1)); /* current!-modulus */
    v0022 = Cremainder(v0023, v0022);
    nil = C_nil;
    if (exception_pending()) goto v0059;
    env = stack[-1];
    stack[0] = v0022;
    v0023 = stack[0];
    v0022 = (Lisp_Object)1; /* 0 */
    v0022 = (Lisp_Object)lessp2(v0023, v0022);
    nil = C_nil;
    if (exception_pending()) goto v0059;
    v0022 = v0022 ? lisp_true : nil;
    env = stack[-1];
    if (v0022 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v0023 = stack[0];
    v0022 = qvalue(elt(env, 1)); /* current!-modulus */
    v0022 = plus2(v0023, v0022);
    nil = C_nil;
    if (exception_pending()) goto v0059;
    stack[0] = v0022;
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
/* error exit handlers */
v0059:
    popv(2);
    return nil;
}



/* Code for !*d2n */

static Lisp_Object CC_Hd2n(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0004, v0006;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for *d2n");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0004 = v0000;
/* end of prologue */
    v0006 = v0004;
    if (!(v0006 == nil)) return onevalue(v0004);
    v0004 = (Lisp_Object)1; /* 0 */
    return onevalue(v0004);
}



/* Code for multdm */

static Lisp_Object CC_multdm(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0017)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0040, v0064, v0065;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for multdm");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0017,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0017);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v0064 = v0017;
    v0065 = v0000;
/* end of prologue */
    v0040 = v0065;
    if (!consp(v0040)) goto v0002;
    v0040 = qvalue(elt(env, 1)); /* nil */
    goto v0001;

v0001:
    if (v0040 == nil) goto v0030;
    v0040 = v0065;
    v0040 = times2(v0040, v0064);
    nil = C_nil;
    if (exception_pending()) goto v0097;
    env = stack[0];
    v0064 = v0040;
    v0040 = qvalue(elt(env, 2)); /* dmode!* */
    if (v0040 == nil) goto v0019;
    v0040 = qvalue(elt(env, 2)); /* dmode!* */
    if (!symbolp(v0040)) v0040 = nil;
    else { v0040 = qfastgets(v0040);
           if (v0040 != nil) { v0040 = elt(v0040, 5); /* convert */
#ifdef RECORD_GET
             if (v0040 == SPID_NOPROP)
                record_get(elt(fastget_names, 5), 0),
                v0040 = nil;
             else record_get(elt(fastget_names, 5), 1),
                v0040 = lisp_true; }
           else record_get(elt(fastget_names, 5), 0); }
#else
             if (v0040 == SPID_NOPROP) v0040 = nil; else v0040 = lisp_true; }}
#endif
    v0040 = (v0040 == nil ? lisp_true : nil);
    goto v0055;

v0055:
    if (!(v0040 == nil)) { popv(1); return onevalue(v0064); }
    v0040 = qvalue(elt(env, 2)); /* dmode!* */
    if (!symbolp(v0040)) v0040 = nil;
    else { v0040 = qfastgets(v0040);
           if (v0040 != nil) { v0040 = elt(v0040, 34); /* i2d */
#ifdef RECORD_GET
             if (v0040 != SPID_NOPROP)
                record_get(elt(fastget_names, 34), 1);
             else record_get(elt(fastget_names, 34), 0),
                v0040 = nil; }
           else record_get(elt(fastget_names, 34), 0); }
#else
             if (v0040 == SPID_NOPROP) v0040 = nil; }}
#endif
        popv(1);
        return Lapply1(nil, v0040, v0064);

v0019:
    v0040 = qvalue(elt(env, 3)); /* t */
    goto v0055;

v0030:
    v0040 = elt(env, 4); /* times */
    {
        popv(1);
        fn = elt(env, 5); /* dcombine */
        return (*qfnn(fn))(qenv(fn), 3, v0065, v0064, v0040);
    }

v0002:
    v0040 = v0064;
    v0040 = (consp(v0040) ? nil : lisp_true);
    goto v0001;
/* error exit handlers */
v0097:
    popv(1);
    return nil;
}



setup_type const u01_setup[] =
{
    {"reval",                   CC_reval,       too_many_1,    wrong_no_1},
    {"simpcar",                 CC_simpcar,     too_many_1,    wrong_no_1},
    {"noncomp",                 CC_noncomp,     too_many_1,    wrong_no_1},
    {"num-exponents",           CC_numKexponents,too_many_1,   wrong_no_1},
    {"argsofopr",               CC_argsofopr,   too_many_1,    wrong_no_1},
    {"smember",                 too_few_2,      CC_smember,    wrong_no_2},
    {"*n2f",                    CC_Hn2f,        too_many_1,    wrong_no_1},
    {"lalr_move_dot",           too_few_2,      CC_lalr_move_dot,wrong_no_2},
    {"mkvar",                   too_few_2,      CC_mkvar,      wrong_no_2},
    {"multf",                   too_few_2,      CC_multf,      wrong_no_2},
    {"monomgetvariabledegree",  too_few_2,      CC_monomgetvariabledegree,wrong_no_2},
    {"quotelist",               CC_quotelist,   too_many_1,    wrong_no_1},
    {"wuconstantp",             CC_wuconstantp, too_many_1,    wrong_no_1},
    {"mchkopt",                 too_few_2,      CC_mchkopt,    wrong_no_2},
    {"nth",                     too_few_2,      CC_nth,        wrong_no_2},
    {"qqe_rqopp",               CC_qqe_rqopp,   too_many_1,    wrong_no_1},
    {"kernels",                 CC_kernels,     too_many_1,    wrong_no_1},
    {"ibalp_clmember",          too_few_2,      CC_ibalp_clmember,wrong_no_2},
    {"noncomfp",                CC_noncomfp,    too_many_1,    wrong_no_1},
    {"delall",                  too_few_2,      CC_delall,     wrong_no_2},
    {"terminalp",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_terminalp},
    {"ordop",                   too_few_2,      CC_ordop,      wrong_no_2},
    {"prepf",                   CC_prepf,       too_many_1,    wrong_no_1},
    {"c:ordxp",                 too_few_2,      CC_cTordxp,    wrong_no_2},
    {"zero2nil",                CC_zero2nil,    too_many_1,    wrong_no_1},
    {"ordad",                   too_few_2,      CC_ordad,      wrong_no_2},
    {"mval",                    CC_mval,        too_many_1,    wrong_no_1},
    {"evcomp",                  too_few_2,      CC_evcomp,     wrong_no_2},
    {"evmatrixcomp2",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_evmatrixcomp2},
    {"xval",                    CC_xval,        too_many_1,    wrong_no_1},
    {"times:",                  too_few_2,      CC_timesT,     wrong_no_2},
    {"convprec",                CC_convprec,    too_many_1,    wrong_no_1},
    {"physopp",                 CC_physopp,     too_many_1,    wrong_no_1},
    {"memq_edgelist",           too_few_2,      CC_memq_edgelist,wrong_no_2},
    {"wideid2list",             CC_wideid2list, too_many_1,    wrong_no_1},
    {"mo_comp",                 CC_mo_comp,     too_many_1,    wrong_no_1},
    {"c_zero",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_c_zero},
    {"sieve_pv0",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_sieve_pv0},
    {"listp",                   CC_listp,       too_many_1,    wrong_no_1},
    {"modzerop:",               CC_modzeropT,   too_many_1,    wrong_no_1},
    {"lalr_closure",            CC_lalr_closure,too_many_1,    wrong_no_1},
    {"monomcompare",            too_few_2,      CC_monomcompare,wrong_no_2},
    {"aeval",                   CC_aeval,       too_many_1,    wrong_no_1},
    {"quotf",                   too_few_2,      CC_quotf,      wrong_no_2},
    {"mkcopy",                  CC_mkcopy,      too_many_1,    wrong_no_1},
    {"mchk*",                   too_few_2,      CC_mchkH,      wrong_no_2},
    {"revpr",                   CC_revpr,       too_many_1,    wrong_no_1},
    {"get+mat+entry",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_getLmatLentry},
    {"powers",                  CC_powers,      too_many_1,    wrong_no_1},
    {"lto_hashequalq",          too_few_2,      CC_lto_hashequalq,wrong_no_2},
    {"find2",                   too_few_2,      CC_find2,      wrong_no_2},
    {"exchk",                   CC_exchk,       too_many_1,    wrong_no_1},
    {"dm-abs",                  CC_dmKabs,      too_many_1,    wrong_no_1},
    {"pm:free",                 CC_pmTfree,     too_many_1,    wrong_no_1},
    {"vbcsize",                 too_few_2,      CC_vbcsize,    wrong_no_2},
    {"pnth",                    too_few_2,      CC_pnth,       wrong_no_2},
    {"wedgefax",                CC_wedgefax,    too_many_1,    wrong_no_1},
    {"*physopp",                CC_Hphysopp,    too_many_1,    wrong_no_1},
    {"termsf",                  CC_termsf,      too_many_1,    wrong_no_1},
    {"mkspm",                   too_few_2,      CC_mkspm,      wrong_no_2},
    {"dssoc",                   too_few_2,      CC_dssoc,      wrong_no_2},
    {"noncomlistp",             CC_noncomlistp, too_many_1,    wrong_no_1},
    {"rnzerop:",                CC_rnzeropT,    too_many_1,    wrong_no_1},
    {"mksp",                    too_few_2,      CC_mksp,       wrong_no_2},
    {"getrtypeor",              CC_getrtypeor,  too_many_1,    wrong_no_1},
    {"lalr_goto",               too_few_2,      CC_lalr_goto,  wrong_no_2},
    {"setkorder",               CC_setkorder,   too_many_1,    wrong_no_1},
    {"cl_cflip",                too_few_2,      CC_cl_cflip,   wrong_no_2},
    {"subs3f",                  CC_subs3f,      too_many_1,    wrong_no_1},
    {"kernlp",                  CC_kernlp,      too_many_1,    wrong_no_1},
    {"ibalp_emptyclausep",      CC_ibalp_emptyclausep,too_many_1,wrong_no_1},
    {"sub2chk",                 CC_sub2chk,     too_many_1,    wrong_no_1},
    {"butes",                   CC_butes,       too_many_1,    wrong_no_1},
    {"noncomfp1",               CC_noncomfp1,   too_many_1,    wrong_no_1},
    {"ps:getv",                 too_few_2,      CC_psTgetv,    wrong_no_2},
    {"expchk",                  CC_expchk,      too_many_1,    wrong_no_1},
    {"binding",                 CC_binding,     too_many_1,    wrong_no_1},
    {"evlexcomp",               too_few_2,      CC_evlexcomp,  wrong_no_2},
    {"sc_getmat",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_sc_getmat},
    {"prepf1a",                 too_few_2,      CC_prepf1a,    wrong_no_2},
    {"addcomment",              CC_addcomment,  too_many_1,    wrong_no_1},
    {"round*",                  CC_roundH,      too_many_1,    wrong_no_1},
    {"isanindex",               CC_isanindex,   too_many_1,    wrong_no_1},
    {"union_edge",              too_few_2,      CC_union_edge, wrong_no_2},
    {"mo_divides?",             too_few_2,      CC_mo_dividesW,wrong_no_2},
    {"dlesslex",                too_few_2,      CC_dlesslex,   wrong_no_2},
    {"hasonevector",            CC_hasonevector,too_many_1,    wrong_no_1},
    {"reduce_pv0",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_reduce_pv0},
    {"modonep:",                CC_modonepT,    too_many_1,    wrong_no_1},
    {"getpower",                too_few_2,      CC_getpower,   wrong_no_2},
    {"multd",                   too_few_2,      CC_multd,      wrong_no_2},
    {"lalr_remove_duplicates",  CC_lalr_remove_duplicates,too_many_1,wrong_no_1},
    {"mtchp1",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_mtchp1},
    {"tayexp-greaterp",         too_few_2,      CC_tayexpKgreaterp,wrong_no_2},
    {"*d2q",                    CC_Hd2q,        too_many_1,    wrong_no_1},
    {"mri_floorkernelp",        CC_mri_floorkernelp,too_many_1,wrong_no_1},
    {"qqe_rbopp",               CC_qqe_rbopp,   too_many_1,    wrong_no_1},
    {"kernels1",                too_few_2,      CC_kernels1,   wrong_no_2},
    {"lto_setequalq",           too_few_2,      CC_lto_setequalq,wrong_no_2},
    {"aex_ex",                  CC_aex_ex,      too_many_1,    wrong_no_1},
    {"addd",                    too_few_2,      CC_addd,       wrong_no_2},
    {"compress*",               CC_compressH,   too_many_1,    wrong_no_1},
    {"ldepends",                too_few_2,      CC_ldepends,   wrong_no_2},
    {"numlis",                  CC_numlis,      too_many_1,    wrong_no_1},
    {":minusp",                 CC_Tminusp,     too_many_1,    wrong_no_1},
    {"evzero?",                 CC_evzeroW,     too_many_1,    wrong_no_1},
    {"factorordp",              too_few_2,      CC_factorordp, wrong_no_2},
    {"degr",                    too_few_2,      CC_degr,       wrong_no_2},
    {"mkround",                 CC_mkround,     too_many_1,    wrong_no_1},
    {"collectindices",          CC_collectindices,too_many_1,  wrong_no_1},
    {"getrtypecar",             CC_getrtypecar, too_many_1,    wrong_no_1},
    {"poly-multf",              too_few_2,      CC_polyKmultf, wrong_no_2},
    {"cali_bc_prod",            too_few_2,      CC_cali_bc_prod,wrong_no_2},
    {"mtp",                     CC_mtp,         too_many_1,    wrong_no_1},
    {"pappl",                   too_few_2,      CC_pappl,      wrong_no_2},
    {"rnequiv",                 CC_rnequiv,     too_many_1,    wrong_no_1},
    {"*i2mod",                  CC_Hi2mod,      too_many_1,    wrong_no_1},
    {"general-modular-times",   too_few_2,      CC_generalKmodularKtimes,wrong_no_2},
    {"*d2n",                    CC_Hd2n,        too_many_1,    wrong_no_1},
    {"multdm",                  too_few_2,      CC_multdm,     wrong_no_2},
    {NULL, (one_args *)"u01", (two_args *)"10428 8738079 689550", 0}
};

/* end of generated code */
