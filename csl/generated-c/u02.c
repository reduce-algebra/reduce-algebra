
/* $destdir/u02.c        Machine generated C code */

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


/* Code for lalr_core */

static Lisp_Object CC_lalr_core(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0007;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for lalr_core");
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
    v0007 = v0000;
/* end of prologue */
    v0007 = qcar(v0007);
    stack[-3] = v0007;
    v0007 = stack[-3];
    if (v0007 == nil) goto v0008;
    v0007 = stack[-3];
    v0007 = qcar(v0007);
    v0007 = qcar(v0007);
    v0007 = ncons(v0007);
    nil = C_nil;
    if (exception_pending()) goto v0009;
    env = stack[-4];
    stack[-1] = v0007;
    stack[-2] = v0007;
    goto v0010;

v0010:
    v0007 = stack[-3];
    v0007 = qcdr(v0007);
    stack[-3] = v0007;
    v0007 = stack[-3];
    if (v0007 == nil) goto v0011;
    stack[0] = stack[-1];
    v0007 = stack[-3];
    v0007 = qcar(v0007);
    v0007 = qcar(v0007);
    v0007 = ncons(v0007);
    nil = C_nil;
    if (exception_pending()) goto v0009;
    env = stack[-4];
    v0007 = Lrplacd(nil, stack[0], v0007);
    nil = C_nil;
    if (exception_pending()) goto v0009;
    env = stack[-4];
    v0007 = stack[-1];
    v0007 = qcdr(v0007);
    stack[-1] = v0007;
    goto v0010;

v0011:
    v0007 = stack[-2];
    goto v0012;

v0012:
    {
        popv(5);
        fn = elt(env, 2); /* lalr_remove_duplicates */
        return (*qfn1(fn))(qenv(fn), v0007);
    }

v0008:
    v0007 = qvalue(elt(env, 1)); /* nil */
    goto v0012;
/* error exit handlers */
v0009:
    popv(5);
    return nil;
}



/* Code for prin2x */

static Lisp_Object CC_prin2x(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0014, v0015;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for prin2x");
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
    v0014 = v0000;
/* end of prologue */
    v0015 = v0014;
    v0014 = qvalue(elt(env, 1)); /* outl!* */
    v0014 = cons(v0015, v0014);
    nil = C_nil;
    if (exception_pending()) goto v0016;
    env = stack[0];
    qvalue(elt(env, 1)) = v0014; /* outl!* */
    { popv(1); return onevalue(v0014); }
/* error exit handlers */
v0016:
    popv(1);
    return nil;
}



/* Code for rl_varlat */

static Lisp_Object CC_rl_varlat(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0015;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rl_varlat");
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
    v0015 = v0000;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* rl_varlat!* */
    v0015 = ncons(v0015);
    nil = C_nil;
    if (exception_pending()) goto v0008;
    env = stack[-1];
    {
        Lisp_Object v0017 = stack[0];
        popv(2);
        fn = elt(env, 2); /* apply */
        return (*qfn2(fn))(qenv(fn), v0017, v0015);
    }
/* error exit handlers */
v0008:
    popv(2);
    return nil;
}



/* Code for minusf */

static Lisp_Object CC_minusf(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0022, v0023;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for minusf");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0022 = v0000;
/* end of prologue */

v0006:
    v0023 = v0022;
    if (v0023 == nil) goto v0012;
    v0023 = v0022;
    if (!consp(v0023)) goto v0024;
    v0023 = v0022;
    v0023 = qcar(v0023);
    v0023 = (consp(v0023) ? nil : lisp_true);
    goto v0017;

v0017:
    if (v0023 == nil) goto v0025;
    v0023 = v0022;
    if (!consp(v0023)) goto v0026;
    v0023 = v0022;
    v0023 = qcar(v0023);
    if (!symbolp(v0023)) v0023 = nil;
    else { v0023 = qfastgets(v0023);
           if (v0023 != nil) { v0023 = elt(v0023, 30); /* minusp */
#ifdef RECORD_GET
             if (v0023 != SPID_NOPROP)
                record_get(elt(fastget_names, 30), 1);
             else record_get(elt(fastget_names, 30), 0),
                v0023 = nil; }
           else record_get(elt(fastget_names, 30), 0); }
#else
             if (v0023 == SPID_NOPROP) v0023 = nil; }}
#endif
        return Lapply1(nil, v0023, v0022);

v0026:
    v0023 = v0022;
    v0022 = (Lisp_Object)1; /* 0 */
        return Llessp(nil, v0023, v0022);

v0025:
    v0022 = qcar(v0022);
    v0022 = qcdr(v0022);
    goto v0006;

v0024:
    v0023 = qvalue(elt(env, 2)); /* t */
    goto v0017;

v0012:
    v0022 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v0022);
}



/* Code for reorder */

static Lisp_Object CC_reorder(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0032, v0033;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for reorder");
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
    goto v0001;

v0001:
    v0032 = stack[-1];
    if (!consp(v0032)) goto v0024;
    v0032 = stack[-1];
    v0032 = qcar(v0032);
    v0032 = (consp(v0032) ? nil : lisp_true);
    goto v0017;

v0017:
    if (v0032 == nil) goto v0034;
    v0032 = stack[-1];
    v0033 = v0032;
    goto v0010;

v0010:
    v0032 = stack[-2];
    if (v0032 == nil) { popv(4); return onevalue(v0033); }
    v0032 = stack[-2];
    v0032 = qcar(v0032);
    fn = elt(env, 2); /* raddf */
    v0032 = (*qfn2(fn))(qenv(fn), v0032, v0033);
    nil = C_nil;
    if (exception_pending()) goto v0035;
    env = stack[-3];
    v0033 = v0032;
    v0032 = stack[-2];
    v0032 = qcdr(v0032);
    stack[-2] = v0032;
    goto v0010;

v0034:
    v0032 = stack[-1];
    v0032 = qcar(v0032);
    stack[0] = qcar(v0032);
    v0032 = stack[-1];
    v0032 = qcar(v0032);
    v0032 = qcdr(v0032);
    v0032 = CC_reorder(env, v0032);
    nil = C_nil;
    if (exception_pending()) goto v0035;
    env = stack[-3];
    fn = elt(env, 3); /* rmultpf */
    v0033 = (*qfn2(fn))(qenv(fn), stack[0], v0032);
    nil = C_nil;
    if (exception_pending()) goto v0035;
    env = stack[-3];
    v0032 = stack[-2];
    v0032 = cons(v0033, v0032);
    nil = C_nil;
    if (exception_pending()) goto v0035;
    env = stack[-3];
    stack[-2] = v0032;
    v0032 = stack[-1];
    v0032 = qcdr(v0032);
    stack[-1] = v0032;
    goto v0001;

v0024:
    v0032 = qvalue(elt(env, 1)); /* t */
    goto v0017;
/* error exit handlers */
v0035:
    popv(4);
    return nil;
}



/* Code for aconc!* */

static Lisp_Object CC_aconcH(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0036)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0016, v0008;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for aconc*");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0036,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0036);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0016 = v0036;
    v0008 = v0000;
/* end of prologue */
    stack[0] = v0008;
    v0016 = ncons(v0016);
    nil = C_nil;
    if (exception_pending()) goto v0024;
    {
        Lisp_Object v0037 = stack[0];
        popv(1);
        return Lnconc(nil, v0037, v0016);
    }
/* error exit handlers */
v0024:
    popv(1);
    return nil;
}



/* Code for tayexp!-lessp */

static Lisp_Object CC_tayexpKlessp(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0036)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0020, v0002, v0003;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for tayexp-lessp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0036,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0036);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v0002 = v0036;
    v0003 = v0000;
/* end of prologue */
    v0020 = v0003;
    if (!consp(v0020)) goto v0013;
    v0020 = qvalue(elt(env, 1)); /* nil */
    goto v0010;

v0010:
    if (v0020 == nil) goto v0041;
    v0020 = v0003;
        popv(1);
        return Llessp(nil, v0020, v0002);

v0041:
    v0020 = v0003;
    fn = elt(env, 2); /* tayexp!-difference */
    v0020 = (*qfn2(fn))(qenv(fn), v0020, v0002);
    nil = C_nil;
    if (exception_pending()) goto v0031;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 3); /* !:minusp */
        return (*qfn1(fn))(qenv(fn), v0020);
    }

v0013:
    v0020 = v0002;
    v0020 = (consp(v0020) ? nil : lisp_true);
    goto v0010;
/* error exit handlers */
v0031:
    popv(1);
    return nil;
}



/* Code for get!+row!+nr */

static Lisp_Object CC_getLrowLnr(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0001;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for get+row+nr");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0001 = v0000;
/* end of prologue */
        return Llength(nil, v0001);
}



/* Code for sfp */

static Lisp_Object CC_sfp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0017, v0024;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sfp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0024 = v0000;
/* end of prologue */
    v0017 = v0024;
    if (!consp(v0017)) goto v0015;
    v0017 = v0024;
    v0017 = qcar(v0017);
    v0017 = (consp(v0017) ? nil : lisp_true);
    v0017 = (v0017 == nil ? lisp_true : nil);
    return onevalue(v0017);

v0015:
    v0017 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v0017);
}



/* Code for ibalp_cequal */

static Lisp_Object CC_ibalp_cequal(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0036)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0063, v0064;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ibalp_cequal");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0036,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0036);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-4] = v0036;
    stack[-5] = v0000;
/* end of prologue */
    v0063 = stack[-5];
    v0063 = qcar(v0063);
    stack[-3] = v0063;
    v0063 = stack[-3];
    if (v0063 == nil) goto v0065;
    v0063 = stack[-3];
    v0063 = qcar(v0063);
    v0063 = qcar(v0063);
    v0063 = ncons(v0063);
    nil = C_nil;
    if (exception_pending()) goto v0066;
    env = stack[-7];
    stack[-1] = v0063;
    stack[-2] = v0063;
    goto v0017;

v0017:
    v0063 = stack[-3];
    v0063 = qcdr(v0063);
    stack[-3] = v0063;
    v0063 = stack[-3];
    if (v0063 == nil) goto v0067;
    stack[0] = stack[-1];
    v0063 = stack[-3];
    v0063 = qcar(v0063);
    v0063 = qcar(v0063);
    v0063 = ncons(v0063);
    nil = C_nil;
    if (exception_pending()) goto v0066;
    env = stack[-7];
    v0063 = Lrplacd(nil, stack[0], v0063);
    nil = C_nil;
    if (exception_pending()) goto v0066;
    env = stack[-7];
    v0063 = stack[-1];
    v0063 = qcdr(v0063);
    stack[-1] = v0063;
    goto v0017;

v0067:
    v0063 = stack[-2];
    goto v0008;

v0008:
    stack[-6] = v0063;
    v0063 = stack[-4];
    v0063 = qcar(v0063);
    stack[-3] = v0063;
    v0063 = stack[-3];
    if (v0063 == nil) goto v0068;
    v0063 = stack[-3];
    v0063 = qcar(v0063);
    v0063 = qcar(v0063);
    v0063 = ncons(v0063);
    nil = C_nil;
    if (exception_pending()) goto v0066;
    env = stack[-7];
    stack[-1] = v0063;
    stack[-2] = v0063;
    goto v0069;

v0069:
    v0063 = stack[-3];
    v0063 = qcdr(v0063);
    stack[-3] = v0063;
    v0063 = stack[-3];
    if (v0063 == nil) goto v0070;
    stack[0] = stack[-1];
    v0063 = stack[-3];
    v0063 = qcar(v0063);
    v0063 = qcar(v0063);
    v0063 = ncons(v0063);
    nil = C_nil;
    if (exception_pending()) goto v0066;
    env = stack[-7];
    v0063 = Lrplacd(nil, stack[0], v0063);
    nil = C_nil;
    if (exception_pending()) goto v0066;
    env = stack[-7];
    v0063 = stack[-1];
    v0063 = qcdr(v0063);
    stack[-1] = v0063;
    goto v0069;

v0070:
    v0063 = stack[-2];
    goto v0071;

v0071:
    v0064 = stack[-6];
    fn = elt(env, 2); /* lto_setequalq */
    v0063 = (*qfn2(fn))(qenv(fn), v0064, v0063);
    nil = C_nil;
    if (exception_pending()) goto v0066;
    env = stack[-7];
    if (v0063 == nil) goto v0072;
    v0063 = stack[-5];
    v0063 = qcdr(v0063);
    v0063 = qcar(v0063);
    stack[-3] = v0063;
    v0063 = stack[-3];
    if (v0063 == nil) goto v0073;
    v0063 = stack[-3];
    v0063 = qcar(v0063);
    v0063 = qcar(v0063);
    v0063 = ncons(v0063);
    nil = C_nil;
    if (exception_pending()) goto v0066;
    env = stack[-7];
    stack[-1] = v0063;
    stack[-2] = v0063;
    goto v0074;

v0074:
    v0063 = stack[-3];
    v0063 = qcdr(v0063);
    stack[-3] = v0063;
    v0063 = stack[-3];
    if (v0063 == nil) goto v0075;
    stack[0] = stack[-1];
    v0063 = stack[-3];
    v0063 = qcar(v0063);
    v0063 = qcar(v0063);
    v0063 = ncons(v0063);
    nil = C_nil;
    if (exception_pending()) goto v0066;
    env = stack[-7];
    v0063 = Lrplacd(nil, stack[0], v0063);
    nil = C_nil;
    if (exception_pending()) goto v0066;
    env = stack[-7];
    v0063 = stack[-1];
    v0063 = qcdr(v0063);
    stack[-1] = v0063;
    goto v0074;

v0075:
    v0063 = stack[-2];
    goto v0076;

v0076:
    stack[-3] = v0063;
    v0063 = stack[-4];
    v0063 = qcdr(v0063);
    v0063 = qcar(v0063);
    stack[-4] = v0063;
    v0063 = stack[-4];
    if (v0063 == nil) goto v0077;
    v0063 = stack[-4];
    v0063 = qcar(v0063);
    v0063 = qcar(v0063);
    v0063 = ncons(v0063);
    nil = C_nil;
    if (exception_pending()) goto v0066;
    env = stack[-7];
    stack[-1] = v0063;
    stack[-2] = v0063;
    goto v0078;

v0078:
    v0063 = stack[-4];
    v0063 = qcdr(v0063);
    stack[-4] = v0063;
    v0063 = stack[-4];
    if (v0063 == nil) goto v0079;
    stack[0] = stack[-1];
    v0063 = stack[-4];
    v0063 = qcar(v0063);
    v0063 = qcar(v0063);
    v0063 = ncons(v0063);
    nil = C_nil;
    if (exception_pending()) goto v0066;
    env = stack[-7];
    v0063 = Lrplacd(nil, stack[0], v0063);
    nil = C_nil;
    if (exception_pending()) goto v0066;
    env = stack[-7];
    v0063 = stack[-1];
    v0063 = qcdr(v0063);
    stack[-1] = v0063;
    goto v0078;

v0079:
    v0063 = stack[-2];
    goto v0080;

v0080:
    v0064 = stack[-3];
    {
        popv(8);
        fn = elt(env, 2); /* lto_setequalq */
        return (*qfn2(fn))(qenv(fn), v0064, v0063);
    }

v0077:
    v0063 = qvalue(elt(env, 1)); /* nil */
    goto v0080;

v0073:
    v0063 = qvalue(elt(env, 1)); /* nil */
    goto v0076;

v0072:
    v0063 = qvalue(elt(env, 1)); /* nil */
    { popv(8); return onevalue(v0063); }

v0068:
    v0063 = qvalue(elt(env, 1)); /* nil */
    goto v0071;

v0065:
    v0063 = qvalue(elt(env, 1)); /* nil */
    goto v0008;
/* error exit handlers */
v0066:
    popv(8);
    return nil;
}



/* Code for !*q2a */

static Lisp_Object CC_Hq2a(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0014, v0015;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for *q2a");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0014 = v0000;
/* end of prologue */
    v0015 = v0014;
    v0014 = qvalue(elt(env, 1)); /* !*nosq */
    {
        fn = elt(env, 2); /* !*q2a1 */
        return (*qfn2(fn))(qenv(fn), v0015, v0014);
    }
}



/* Code for !:onep */

static Lisp_Object CC_Tonep(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0083, v0084;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for :onep");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0083 = v0000;
/* end of prologue */
    v0084 = v0083;
    if (!consp(v0084)) goto v0006;
    v0084 = v0083;
    v0084 = qcar(v0084);
    if (!symbolp(v0084)) v0084 = nil;
    else { v0084 = qfastgets(v0084);
           if (v0084 != nil) { v0084 = elt(v0084, 26); /* onep */
#ifdef RECORD_GET
             if (v0084 != SPID_NOPROP)
                record_get(elt(fastget_names, 26), 1);
             else record_get(elt(fastget_names, 26), 0),
                v0084 = nil; }
           else record_get(elt(fastget_names, 26), 0); }
#else
             if (v0084 == SPID_NOPROP) v0084 = nil; }}
#endif
        return Lapply1(nil, v0084, v0083);

v0006:
        return Lonep(nil, v0083);
}



/* Code for buchvevdivides!? */

static Lisp_Object CC_buchvevdividesW(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0036)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0002, v0003, v0031;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for buchvevdivides?");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0036,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0036);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0036;
    stack[-1] = v0000;
/* end of prologue */
    v0003 = stack[0];
    v0002 = stack[-1];
    fn = elt(env, 4); /* vevmtest!? */
    v0002 = (*qfn2(fn))(qenv(fn), v0003, v0002);
    nil = C_nil;
    if (exception_pending()) goto v0085;
    env = stack[-2];
    if (v0002 == nil) goto v0005;
    v0002 = qvalue(elt(env, 2)); /* gmodule!* */
    if (v0002 == nil) goto v0081;
    v0031 = stack[-1];
    v0003 = stack[0];
    v0002 = qvalue(elt(env, 2)); /* gmodule!* */
    {
        popv(3);
        fn = elt(env, 5); /* gevcompatible1 */
        return (*qfnn(fn))(qenv(fn), 3, v0031, v0003, v0002);
    }

v0081:
    v0002 = qvalue(elt(env, 3)); /* t */
    { popv(3); return onevalue(v0002); }

v0005:
    v0002 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v0002); }
/* error exit handlers */
v0085:
    popv(3);
    return nil;
}



/* Code for prepsqxx */

static Lisp_Object CC_prepsqxx(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0005;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for prepsqxx");
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
    fn = elt(env, 1); /* prepsqx */
    v0005 = (*qfn1(fn))(qenv(fn), v0005);
    nil = C_nil;
    if (exception_pending()) goto v0001;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* negnumberchk */
        return (*qfn1(fn))(qenv(fn), v0005);
    }
/* error exit handlers */
v0001:
    popv(1);
    return nil;
}



/* Code for vevmtest!? */

static Lisp_Object CC_vevmtestW(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0036)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0087, v0088, v0089, v0090;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for vevmtest?");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0036,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0036);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v0088 = v0036;
    v0089 = v0000;
/* end of prologue */

v0005:
    v0087 = v0088;
    if (v0087 == nil) goto v0010;
    v0087 = v0089;
    if (v0087 == nil) goto v0016;
    v0087 = v0089;
    v0090 = qcar(v0087);
    v0087 = v0088;
    v0087 = qcar(v0087);
    if (((int32_t)(v0090)) < ((int32_t)(v0087))) goto v0091;
    v0087 = v0089;
    v0087 = qcdr(v0087);
    v0089 = v0087;
    v0087 = v0088;
    v0087 = qcdr(v0087);
    v0088 = v0087;
    goto v0005;

v0091:
    v0087 = qvalue(elt(env, 2)); /* nil */
    { popv(1); return onevalue(v0087); }

v0016:
    v0087 = v0088;
    if (v0087 == nil) goto v0083;
    v0087 = v0088;
    v0089 = qcar(v0087);
    v0087 = (Lisp_Object)1; /* 0 */
    if (v0089 == v0087) goto v0041;
    v0087 = qvalue(elt(env, 2)); /* nil */
    goto v0081;

v0081:
    if (v0087 == nil) goto v0007;
    v0087 = qvalue(elt(env, 1)); /* t */
    { popv(1); return onevalue(v0087); }

v0007:
    v0087 = qvalue(elt(env, 2)); /* nil */
    { popv(1); return onevalue(v0087); }

v0041:
    v0087 = v0088;
    v0087 = qcdr(v0087);
    fn = elt(env, 3); /* vevzero!?1 */
    v0087 = (*qfn1(fn))(qenv(fn), v0087);
    nil = C_nil;
    if (exception_pending()) goto v0092;
    env = stack[0];
    goto v0081;

v0083:
    v0087 = qvalue(elt(env, 1)); /* t */
    goto v0081;

v0010:
    v0087 = qvalue(elt(env, 1)); /* t */
    { popv(1); return onevalue(v0087); }
/* error exit handlers */
v0092:
    popv(1);
    return nil;
}



/* Code for ordpp */

static Lisp_Object CC_ordpp(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0036)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0088, v0089, v0090, v0092, v0070;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ordpp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0090 = v0036;
    v0092 = v0000;
/* end of prologue */
    v0088 = v0092;
    v0089 = qcar(v0088);
    v0088 = v0090;
    v0088 = qcar(v0088);
    if (v0089 == v0088) goto v0083;
    v0088 = qvalue(elt(env, 1)); /* kord!* */
    v0070 = v0088;
    v0088 = v0092;
    v0088 = qcar(v0088);
    v0092 = v0088;
    v0088 = v0090;
    v0088 = qcar(v0088);
    v0090 = v0088;
    goto v0001;

v0001:
    v0088 = v0070;
    if (v0088 == nil) goto v0095;
    v0089 = v0092;
    v0088 = v0070;
    v0088 = qcar(v0088);
    if (v0089 == v0088) goto v0018;
    v0089 = v0090;
    v0088 = v0070;
    v0088 = qcar(v0088);
    if (v0089 == v0088) goto v0096;
    v0088 = v0070;
    v0088 = qcdr(v0088);
    v0070 = v0088;
    goto v0001;

v0096:
    v0088 = qvalue(elt(env, 3)); /* nil */
    return onevalue(v0088);

v0018:
    v0088 = qvalue(elt(env, 2)); /* t */
    return onevalue(v0088);

v0095:
    v0088 = v0092;
    v0089 = v0090;
    {
        fn = elt(env, 4); /* ordpa */
        return (*qfn2(fn))(qenv(fn), v0088, v0089);
    }

v0083:
    v0088 = v0092;
    v0088 = qcdr(v0088);
    v0089 = v0090;
    v0089 = qcdr(v0089);
        return Lgreaterp(nil, v0088, v0089);
}



/* Code for sublistp */

static Lisp_Object CC_sublistp(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0036)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0062, v0019, v0007, v0094;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sublistp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0036,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0036);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0019 = v0036;
    v0007 = v0000;
/* end of prologue */

v0097:
    v0062 = v0007;
    if (v0062 == nil) goto v0005;
    v0062 = v0007;
    v0094 = qcar(v0062);
    v0062 = v0019;
    v0062 = Lmember(nil, v0094, v0062);
    if (v0062 == nil) goto v0008;
    v0062 = v0007;
    stack[0] = qcdr(v0062);
    v0062 = v0007;
    v0062 = qcar(v0062);
    v0062 = Ldelete(nil, v0062, v0019);
    nil = C_nil;
    if (exception_pending()) goto v0025;
    env = stack[-1];
    v0007 = stack[0];
    v0019 = v0062;
    goto v0097;

v0008:
    v0062 = qvalue(elt(env, 2)); /* nil */
    { popv(2); return onevalue(v0062); }

v0005:
    v0062 = qvalue(elt(env, 1)); /* t */
    { popv(2); return onevalue(v0062); }
/* error exit handlers */
v0025:
    popv(2);
    return nil;
}



/* Code for collectindices_reversed */

static Lisp_Object CC_collectindices_reversed(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0036)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0018, v0025;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for collectindices_reversed");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0036,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0036);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0036;
    stack[-1] = v0000;
/* end of prologue */
    v0018 = stack[-1];
    if (!(!consp(v0018))) goto v0041;
    v0018 = stack[-1];
    fn = elt(env, 2); /* isanindex */
    v0018 = (*qfn1(fn))(qenv(fn), v0018);
    nil = C_nil;
    if (exception_pending()) goto v0060;
    if (v0018 == nil) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v0025 = stack[-1];
    v0018 = stack[0];
    popv(3);
    return cons(v0025, v0018);

v0041:
    v0018 = stack[-1];
    if (v0018 == nil) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v0018 = stack[-1];
    v0025 = qcar(v0018);
    v0018 = stack[0];
    v0018 = CC_collectindices_reversed(env, v0025, v0018);
    nil = C_nil;
    if (exception_pending()) goto v0060;
    env = stack[-2];
    stack[0] = v0018;
    v0018 = stack[-1];
    v0018 = qcdr(v0018);
    stack[-1] = v0018;
    goto v0041;
/* error exit handlers */
v0060:
    popv(3);
    return nil;
}



/* Code for reval_without_mod */

static Lisp_Object CC_reval_without_mod(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0083, v0084, v0040;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for reval_without_mod");
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
    v0040 = v0000;
/* end of prologue */
    v0084 = qvalue(elt(env, 1)); /* dmode!* */
    v0083 = elt(env, 2); /* !:mod!: */
    if (v0084 == v0083) goto v0006;
    v0083 = v0040;
    {
        popv(2);
        fn = elt(env, 4); /* reval */
        return (*qfn1(fn))(qenv(fn), v0083);
    }

v0006:
    v0083 = qvalue(elt(env, 3)); /* nil */
    stack[0] = qvalue(elt(env, 1)); /* dmode!* */
    qvalue(elt(env, 1)) = v0083; /* dmode!* */
    v0083 = v0040;
    fn = elt(env, 4); /* reval */
    v0083 = (*qfn1(fn))(qenv(fn), v0083);
    nil = C_nil;
    if (exception_pending()) goto v0098;
    env = stack[-1];
    qvalue(elt(env, 1)) = stack[0]; /* dmode!* */
    { popv(2); return onevalue(v0083); }
/* error exit handlers */
v0098:
    env = stack[-1];
    qvalue(elt(env, 1)) = stack[0]; /* dmode!* */
    popv(2);
    return nil;
}



/* Code for ring_ecart */

static Lisp_Object CC_ring_ecart(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0014, v0015;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ring_ecart");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0014 = v0000;
/* end of prologue */
    v0015 = v0014;
    v0014 = (Lisp_Object)81; /* 5 */
    {
        fn = elt(env, 1); /* nth */
        return (*qfn2(fn))(qenv(fn), v0015, v0014);
    }
}



/* Code for reduce_pv */

static Lisp_Object CC_reduce_pv(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0036)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0017, v0024, v0037;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for reduce_pv");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0017 = v0036;
    v0024 = v0000;
/* end of prologue */
    v0037 = v0024;
    v0024 = v0017;
    v0017 = qvalue(elt(env, 1)); /* t */
    {
        fn = elt(env, 2); /* reduce_pv0 */
        return (*qfnn(fn))(qenv(fn), 3, v0037, v0024, v0017);
    }
}



/* Code for delcp */

static Lisp_Object CC_delcp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0006;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for delcp");
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
           if (v0006 != nil) { v0006 = elt(v0006, 40); /* delchar */
#ifdef RECORD_GET
             if (v0006 == SPID_NOPROP)
                record_get(elt(fastget_names, 40), 0),
                v0006 = nil;
             else record_get(elt(fastget_names, 40), 1),
                v0006 = lisp_true; }
           else record_get(elt(fastget_names, 40), 0); }
#else
             if (v0006 == SPID_NOPROP) v0006 = nil; else v0006 = lisp_true; }}
#endif
    return onevalue(v0006);
}



/* Code for lalr_first */

static Lisp_Object CC_lalr_first(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0072, v0106, v0107;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for lalr_first");
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
    stack[0] = nil;
    goto v0010;

v0010:
    v0072 = stack[-1];
    if (v0072 == nil) goto v0012;
    v0072 = stack[-1];
    v0072 = qcar(v0072);
    if (is_number(v0072)) goto v0003;
    v0107 = qvalue(elt(env, 1)); /* nil */
    v0072 = stack[-1];
    v0106 = qcar(v0072);
    v0072 = elt(env, 0); /* lalr_first */
    v0072 = get(v0106, v0072);
    env = stack[-3];
    stack[0] = v0072;
    v0072 = Lmember(nil, v0107, v0072);
    goto v0082;

v0082:
    if (v0072 == nil) goto v0012;
    v0106 = qvalue(elt(env, 1)); /* nil */
    v0072 = stack[0];
    v0106 = Ldeleq(nil, v0106, v0072);
    env = stack[-3];
    v0072 = stack[-2];
    fn = elt(env, 2); /* union */
    v0072 = (*qfn2(fn))(qenv(fn), v0106, v0072);
    nil = C_nil;
    if (exception_pending()) goto v0108;
    env = stack[-3];
    stack[-2] = v0072;
    v0072 = stack[-1];
    v0072 = qcdr(v0072);
    stack[-1] = v0072;
    goto v0010;

v0012:
    v0072 = stack[-1];
    if (v0072 == nil) goto v0033;
    v0072 = stack[-1];
    v0072 = qcar(v0072);
    if (is_number(v0072)) goto v0109;
    v0106 = stack[0];
    v0072 = stack[-2];
    fn = elt(env, 2); /* union */
    v0072 = (*qfn2(fn))(qenv(fn), v0106, v0072);
    nil = C_nil;
    if (exception_pending()) goto v0108;
    stack[-2] = v0072;
    { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }

v0109:
    v0072 = stack[-1];
    v0072 = qcar(v0072);
    v0106 = ncons(v0072);
    nil = C_nil;
    if (exception_pending()) goto v0108;
    env = stack[-3];
    v0072 = stack[-2];
    fn = elt(env, 2); /* union */
    v0072 = (*qfn2(fn))(qenv(fn), v0106, v0072);
    nil = C_nil;
    if (exception_pending()) goto v0108;
    stack[-2] = v0072;
    { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }

v0033:
    v0106 = qvalue(elt(env, 1)); /* nil */
    v0072 = stack[-2];
    v0072 = cons(v0106, v0072);
    nil = C_nil;
    if (exception_pending()) goto v0108;
    stack[-2] = v0072;
    { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }

v0003:
    v0072 = qvalue(elt(env, 1)); /* nil */
    goto v0082;
/* error exit handlers */
v0108:
    popv(4);
    return nil;
}



/* Code for sfto_dcontentf */

static Lisp_Object CC_sfto_dcontentf(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0014, v0015;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sfto_dcontentf");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0014 = v0000;
/* end of prologue */
    v0015 = v0014;
    v0014 = qvalue(elt(env, 1)); /* nil */
    {
        fn = elt(env, 2); /* sfto_dcontentf1 */
        return (*qfn2(fn))(qenv(fn), v0015, v0014);
    }
}



/* Code for finde */

static Lisp_Object CC_finde(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0036)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0041, v0026, v0034, v0110;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for finde");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0110 = v0036;
    v0034 = v0000;
/* end of prologue */

v0005:
    v0041 = v0034;
    if (v0041 == nil) goto v0010;
    v0026 = v0110;
    v0041 = v0034;
    v0041 = qcar(v0041);
    v0041 = qcdr(v0041);
    v0041 = Lmemq(nil, v0026, v0041);
    if (!(v0041 == nil)) return onevalue(v0034);
    v0041 = v0034;
    v0041 = qcdr(v0041);
    v0034 = v0041;
    goto v0005;

v0010:
    v0041 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v0041);
}



/* Code for mchk */

static Lisp_Object CC_mchk(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0036)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0152, v0153, v0154;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mchk");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0036,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0036);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-3] = v0036;
    stack[-4] = v0000;
/* end of prologue */

v0014:
    v0153 = stack[-4];
    v0152 = stack[-3];
    if (equal(v0153, v0152)) goto v0010;
    v0153 = stack[-4];
    v0152 = elt(env, 2); /* !*sq */
    if (!consp(v0153)) goto v0020;
    v0153 = qcar(v0153);
    if (!(v0153 == v0152)) goto v0020;
    v0152 = stack[-4];
    v0152 = qcdr(v0152);
    v0152 = qcar(v0152);
    fn = elt(env, 7); /* prepsqxx */
    v0152 = (*qfn1(fn))(qenv(fn), v0152);
    nil = C_nil;
    if (exception_pending()) goto v0155;
    env = stack[-6];
    stack[-4] = v0152;
    goto v0014;

v0020:
    v0153 = stack[-3];
    v0152 = elt(env, 2); /* !*sq */
    if (!consp(v0153)) goto v0038;
    v0153 = qcar(v0153);
    if (!(v0153 == v0152)) goto v0038;
    v0152 = stack[-3];
    v0152 = qcdr(v0152);
    v0152 = qcar(v0152);
    fn = elt(env, 7); /* prepsqxx */
    v0152 = (*qfn1(fn))(qenv(fn), v0152);
    nil = C_nil;
    if (exception_pending()) goto v0155;
    env = stack[-6];
    stack[-3] = v0152;
    goto v0014;

v0038:
    v0152 = stack[-3];
    if (!consp(v0152)) goto v0022;
    v0152 = stack[-4];
    if (!consp(v0152)) goto v0092;
    v0152 = stack[-3];
    v0153 = qcar(v0152);
    v0152 = elt(env, 5); /* difference */
    if (v0153 == v0152) goto v0075;
    v0152 = stack[-4];
    v0152 = qcar(v0152);
    if (!symbolp(v0152)) v0152 = nil;
    else { v0152 = qfastgets(v0152);
           if (v0152 != nil) { v0152 = elt(v0152, 8); /* dname */
#ifdef RECORD_GET
             if (v0152 != SPID_NOPROP)
                record_get(elt(fastget_names, 8), 1);
             else record_get(elt(fastget_names, 8), 0),
                v0152 = nil; }
           else record_get(elt(fastget_names, 8), 0); }
#else
             if (v0152 == SPID_NOPROP) v0152 = nil; }}
#endif
    if (!(v0152 == nil)) goto v0044;
    v0152 = stack[-3];
    v0152 = qcar(v0152);
    if (!symbolp(v0152)) v0152 = nil;
    else { v0152 = qfastgets(v0152);
           if (v0152 != nil) { v0152 = elt(v0152, 8); /* dname */
#ifdef RECORD_GET
             if (v0152 != SPID_NOPROP)
                record_get(elt(fastget_names, 8), 1);
             else record_get(elt(fastget_names, 8), 0),
                v0152 = nil; }
           else record_get(elt(fastget_names, 8), 0); }
#else
             if (v0152 == SPID_NOPROP) v0152 = nil; }}
#endif
    if (!(v0152 == nil)) goto v0044;
    v0152 = stack[-4];
    v0153 = qcar(v0152);
    v0152 = stack[-3];
    v0152 = qcar(v0152);
    if (v0153 == v0152) goto v0156;
    v0152 = stack[-3];
    v0153 = qcar(v0152);
    v0152 = qvalue(elt(env, 3)); /* frlis!* */
    v0152 = Lmemq(nil, v0153, v0152);
    if (v0152 == nil) goto v0157;
    v0152 = stack[-4];
    v0154 = qcar(v0152);
    v0152 = stack[-3];
    v0153 = qcar(v0152);
    v0152 = stack[-4];
    v0152 = qcdr(v0152);
    stack[0] = Lsubst(nil, 3, v0154, v0153, v0152);
    nil = C_nil;
    if (exception_pending()) goto v0155;
    env = stack[-6];
    v0152 = stack[-4];
    v0154 = qcar(v0152);
    v0152 = stack[-3];
    v0153 = qcar(v0152);
    v0152 = stack[-3];
    v0152 = qcdr(v0152);
    v0153 = Lsubst(nil, 3, v0154, v0153, v0152);
    nil = C_nil;
    if (exception_pending()) goto v0155;
    env = stack[-6];
    v0152 = stack[-4];
    v0152 = qcar(v0152);
    fn = elt(env, 8); /* mcharg */
    v0152 = (*qfnn(fn))(qenv(fn), 3, stack[0], v0153, v0152);
    nil = C_nil;
    if (exception_pending()) goto v0155;
    env = stack[-6];
    stack[-5] = v0152;
    v0152 = stack[-5];
    if (v0152 == nil) goto v0158;
    v0152 = stack[-5];
    v0152 = qcar(v0152);
    v0153 = stack[-3];
    v0154 = qcar(v0153);
    v0153 = stack[-4];
    v0153 = qcar(v0153);
    v0152 = acons(v0154, v0153, v0152);
    nil = C_nil;
    if (exception_pending()) goto v0155;
    env = stack[-6];
    v0152 = ncons(v0152);
    nil = C_nil;
    if (exception_pending()) goto v0155;
    env = stack[-6];
    stack[-1] = v0152;
    stack[-2] = v0152;
    goto v0159;

v0159:
    v0152 = stack[-5];
    v0152 = qcdr(v0152);
    stack[-5] = v0152;
    v0152 = stack[-5];
    if (v0152 == nil) { Lisp_Object res = stack[-2]; popv(7); return onevalue(res); }
    stack[0] = stack[-1];
    v0152 = stack[-5];
    v0152 = qcar(v0152);
    v0153 = stack[-3];
    v0154 = qcar(v0153);
    v0153 = stack[-4];
    v0153 = qcar(v0153);
    v0152 = acons(v0154, v0153, v0152);
    nil = C_nil;
    if (exception_pending()) goto v0155;
    env = stack[-6];
    v0152 = ncons(v0152);
    nil = C_nil;
    if (exception_pending()) goto v0155;
    env = stack[-6];
    v0152 = Lrplacd(nil, stack[0], v0152);
    nil = C_nil;
    if (exception_pending()) goto v0155;
    env = stack[-6];
    v0152 = stack[-1];
    v0152 = qcdr(v0152);
    stack[-1] = v0152;
    goto v0159;

v0158:
    v0152 = qvalue(elt(env, 1)); /* nil */
    { popv(7); return onevalue(v0152); }

v0157:
    v0152 = stack[-4];
    v0153 = qcar(v0152);
    v0152 = elt(env, 4); /* minus */
    if (v0153 == v0152) goto v0160;
    v0153 = stack[-4];
    v0152 = stack[-3];
    {
        popv(7);
        fn = elt(env, 9); /* mchkopt */
        return (*qfn2(fn))(qenv(fn), v0153, v0152);
    }

v0160:
    v0152 = stack[-4];
    v0152 = qcdr(v0152);
    v0153 = qcar(v0152);
    v0152 = stack[-3];
    {
        popv(7);
        fn = elt(env, 10); /* mchkminus */
        return (*qfn2(fn))(qenv(fn), v0153, v0152);
    }

v0156:
    v0152 = stack[-4];
    v0154 = qcdr(v0152);
    v0152 = stack[-3];
    v0153 = qcdr(v0152);
    v0152 = stack[-4];
    v0152 = qcar(v0152);
    {
        popv(7);
        fn = elt(env, 8); /* mcharg */
        return (*qfnn(fn))(qenv(fn), 3, v0154, v0153, v0152);
    }

v0044:
    v0152 = qvalue(elt(env, 1)); /* nil */
    { popv(7); return onevalue(v0152); }

v0075:
    stack[-1] = elt(env, 6); /* plus */
    v0152 = stack[-3];
    v0152 = qcdr(v0152);
    stack[0] = qcar(v0152);
    v0153 = elt(env, 4); /* minus */
    v0152 = stack[-3];
    v0152 = qcdr(v0152);
    v0152 = qcdr(v0152);
    v0152 = qcar(v0152);
    v0152 = list2(v0153, v0152);
    nil = C_nil;
    if (exception_pending()) goto v0155;
    env = stack[-6];
    v0152 = list3(stack[-1], stack[0], v0152);
    nil = C_nil;
    if (exception_pending()) goto v0155;
    env = stack[-6];
    stack[-3] = v0152;
    goto v0014;

v0092:
    v0152 = stack[-4];
    if (!(is_number(v0152))) goto v0161;
    v0153 = stack[-4];
    v0152 = (Lisp_Object)1; /* 0 */
    v0152 = (Lisp_Object)lessp2(v0153, v0152);
    nil = C_nil;
    if (exception_pending()) goto v0155;
    v0152 = v0152 ? lisp_true : nil;
    env = stack[-6];
    if (v0152 == nil) goto v0161;
    v0153 = stack[-3];
    v0152 = elt(env, 4); /* minus */
    if (!consp(v0153)) goto v0161;
    v0153 = qcar(v0153);
    if (!(v0153 == v0152)) goto v0161;
    stack[0] = elt(env, 4); /* minus */
    v0152 = stack[-4];
    v0152 = negate(v0152);
    nil = C_nil;
    if (exception_pending()) goto v0155;
    env = stack[-6];
    v0152 = list2(stack[0], v0152);
    nil = C_nil;
    if (exception_pending()) goto v0155;
    env = stack[-6];
    stack[-4] = v0152;
    goto v0014;

v0161:
    v0153 = stack[-4];
    v0152 = stack[-3];
    {
        popv(7);
        fn = elt(env, 9); /* mchkopt */
        return (*qfn2(fn))(qenv(fn), v0153, v0152);
    }

v0022:
    v0153 = stack[-3];
    v0152 = qvalue(elt(env, 3)); /* frlis!* */
    v0152 = Lmemq(nil, v0153, v0152);
    if (v0152 == nil) goto v0088;
    v0153 = stack[-3];
    v0152 = stack[-4];
    v0152 = cons(v0153, v0152);
    nil = C_nil;
    if (exception_pending()) goto v0155;
    env = stack[-6];
    v0152 = ncons(v0152);
    nil = C_nil;
    if (exception_pending()) goto v0155;
    popv(7);
    return ncons(v0152);

v0088:
    v0152 = qvalue(elt(env, 1)); /* nil */
    { popv(7); return onevalue(v0152); }

v0010:
    v0152 = qvalue(elt(env, 1)); /* nil */
    popv(7);
    return ncons(v0152);
/* error exit handlers */
v0155:
    popv(7);
    return nil;
}



/* Code for get!+vec!+entry */

static Lisp_Object CC_getLvecLentry(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0036)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0008, v0017;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for get+vec+entry");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0008 = v0036;
    v0017 = v0000;
/* end of prologue */
    {
        fn = elt(env, 1); /* nth */
        return (*qfn2(fn))(qenv(fn), v0017, v0008);
    }
}



/* Code for qqe_qoptailp */

static Lisp_Object CC_qqe_qoptailp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0024, v0037;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for qqe_qoptailp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0024 = v0000;
/* end of prologue */
    v0037 = v0024;
    v0024 = elt(env, 1); /* (rtail ltail) */
    v0024 = Lmemq(nil, v0037, v0024);
    if (v0024 == nil) goto v0005;
    v0024 = qvalue(elt(env, 2)); /* t */
    return onevalue(v0024);

v0005:
    v0024 = nil;
    return onevalue(v0024);
}



/* Code for ibalp_cec */

static Lisp_Object CC_ibalp_cec(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0084;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ibalp_cec");
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

v0006:
    v0084 = stack[0];
    if (v0084 == nil) goto v0012;
    v0084 = stack[0];
    v0084 = qcar(v0084);
    fn = elt(env, 2); /* ibalp_emptyclausep */
    v0084 = (*qfn1(fn))(qenv(fn), v0084);
    nil = C_nil;
    if (exception_pending()) goto v0039;
    env = stack[-1];
    if (v0084 == nil) goto v0162;
    v0084 = stack[0];
    v0084 = qcar(v0084);
    { popv(2); return onevalue(v0084); }

v0162:
    v0084 = stack[0];
    v0084 = qcdr(v0084);
    stack[0] = v0084;
    goto v0006;

v0012:
    v0084 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v0084); }
/* error exit handlers */
v0039:
    popv(2);
    return nil;
}



/* Code for get_token */

static Lisp_Object MS_CDECL CC_get_token(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0020, v0002;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "get_token");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for get_token");
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
    push(nil);
/* end of prologue */
    v0020 = qvalue(elt(env, 1)); /* nil */
    stack[0] = v0020;
    goto v0016;

v0016:
    v0002 = Lreadch(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0031;
    env = stack[-1];
    qvalue(elt(env, 2)) = v0002; /* ch */
    v0020 = elt(env, 3); /* !> */
    if (v0002 == v0020) goto v0041;
    v0002 = qvalue(elt(env, 2)); /* ch */
    v0020 = stack[0];
    v0020 = cons(v0002, v0020);
    nil = C_nil;
    if (exception_pending()) goto v0031;
    env = stack[-1];
    stack[0] = v0020;
    goto v0016;

v0041:
    v0002 = elt(env, 4); /* !$ */
    v0020 = stack[0];
    popv(2);
    return cons(v0002, v0020);
/* error exit handlers */
v0031:
    popv(2);
    return nil;
}



/* Code for csl_normbf */

static Lisp_Object CC_csl_normbf(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0070, v0109, v0164;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for csl_normbf");
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
    v0070 = stack[-2];
    v0070 = qcdr(v0070);
    v0109 = qcar(v0070);
    stack[0] = v0109;
    v0070 = (Lisp_Object)1; /* 0 */
    if (v0109 == v0070) goto v0014;
    v0109 = stack[0];
    v0070 = (Lisp_Object)1; /* 0 */
    v0070 = (Lisp_Object)lessp2(v0109, v0070);
    nil = C_nil;
    if (exception_pending()) goto v0165;
    v0070 = v0070 ? lisp_true : nil;
    env = stack[-4];
    if (v0070 == nil) goto v0040;
    v0070 = stack[0];
    v0070 = negate(v0070);
    nil = C_nil;
    if (exception_pending()) goto v0165;
    env = stack[-4];
    stack[0] = v0070;
    v0070 = qvalue(elt(env, 2)); /* t */
    stack[-3] = v0070;
    goto v0040;

v0040:
    v0070 = stack[0];
    fn = elt(env, 4); /* lsd */
    v0070 = (*qfn1(fn))(qenv(fn), v0070);
    nil = C_nil;
    if (exception_pending()) goto v0165;
    env = stack[-4];
    stack[-1] = v0070;
    v0070 = stack[-1];
    v0070 = negate(v0070);
    nil = C_nil;
    if (exception_pending()) goto v0165;
    env = stack[-4];
    fn = elt(env, 5); /* lshift */
    v0070 = (*qfn2(fn))(qenv(fn), stack[0], v0070);
    nil = C_nil;
    if (exception_pending()) goto v0165;
    env = stack[-4];
    stack[0] = v0070;
    v0070 = stack[-3];
    if (v0070 == nil) goto v0104;
    v0070 = stack[0];
    v0070 = negate(v0070);
    nil = C_nil;
    if (exception_pending()) goto v0165;
    env = stack[-4];
    stack[0] = v0070;
    goto v0104;

v0104:
    v0109 = stack[-1];
    v0070 = stack[-2];
    v0070 = qcdr(v0070);
    v0070 = qcdr(v0070);
    v0070 = plus2(v0109, v0070);
    nil = C_nil;
    if (exception_pending()) goto v0165;
    env = stack[-4];
    stack[-1] = v0070;
    v0164 = elt(env, 3); /* !:rd!: */
    v0109 = stack[0];
    v0070 = stack[-1];
    popv(5);
    return list2star(v0164, v0109, v0070);

v0014:
    v0070 = elt(env, 1); /* (!:rd!: 0 . 0) */
    { popv(5); return onevalue(v0070); }
/* error exit handlers */
v0165:
    popv(5);
    return nil;
}



/* Code for xsimp */

static Lisp_Object CC_xsimp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0005;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for xsimp");
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
    fn = elt(env, 1); /* simp!* */
    v0005 = (*qfn1(fn))(qenv(fn), v0005);
    nil = C_nil;
    if (exception_pending()) goto v0001;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* expchk */
        return (*qfn1(fn))(qenv(fn), v0005);
    }
/* error exit handlers */
v0001:
    popv(1);
    return nil;
}



/* Code for i2rd!* */

static Lisp_Object CC_i2rdH(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0005;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for i2rd*");
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
    fn = elt(env, 1); /* chkint!* */
    v0005 = (*qfn1(fn))(qenv(fn), v0005);
    nil = C_nil;
    if (exception_pending()) goto v0001;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* mkround */
        return (*qfn1(fn))(qenv(fn), v0005);
    }
/* error exit handlers */
v0001:
    popv(1);
    return nil;
}



/* Code for addf */

static Lisp_Object CC_addf(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0036)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0170, v0171, v0172;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for addf");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0036,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0036);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0036;
    stack[-1] = v0000;
/* end of prologue */
    stack[-2] = nil;
    goto v0012;

v0012:
    v0170 = stack[-1];
    if (v0170 == nil) goto v0015;
    v0170 = stack[0];
    if (v0170 == nil) goto v0024;
    v0170 = stack[-1];
    if (!consp(v0170)) goto v0040;
    v0170 = stack[-1];
    v0170 = qcar(v0170);
    v0170 = (consp(v0170) ? nil : lisp_true);
    goto v0084;

v0084:
    if (v0170 == nil) goto v0081;
    v0171 = stack[-1];
    v0170 = stack[0];
    fn = elt(env, 3); /* addd */
    v0170 = (*qfn2(fn))(qenv(fn), v0171, v0170);
    nil = C_nil;
    if (exception_pending()) goto v0140;
    env = stack[-3];
    goto v0173;

v0173:
    v0171 = stack[-2];
    if (v0171 == nil) { popv(4); return onevalue(v0170); }
    v0171 = stack[-2];
    v0171 = qcdr(v0171);
    stack[-1] = v0171;
    v0171 = stack[-2];
    v0170 = Lrplacd(nil, v0171, v0170);
    nil = C_nil;
    if (exception_pending()) goto v0140;
    env = stack[-3];
    v0170 = stack[-2];
    v0171 = stack[-1];
    stack[-2] = v0171;
    goto v0173;

v0081:
    v0170 = stack[0];
    if (!consp(v0170)) goto v0062;
    v0170 = stack[0];
    v0170 = qcar(v0170);
    v0170 = (consp(v0170) ? nil : lisp_true);
    goto v0030;

v0030:
    if (v0170 == nil) goto v0086;
    v0171 = stack[0];
    v0170 = stack[-1];
    fn = elt(env, 3); /* addd */
    v0170 = (*qfn2(fn))(qenv(fn), v0171, v0170);
    nil = C_nil;
    if (exception_pending()) goto v0140;
    env = stack[-3];
    goto v0173;

v0086:
    v0170 = stack[-1];
    v0170 = qcar(v0170);
    v0171 = qcar(v0170);
    v0170 = stack[0];
    v0170 = qcar(v0170);
    v0170 = qcar(v0170);
    if (equal(v0171, v0170)) goto v0092;
    v0170 = stack[-1];
    v0170 = qcar(v0170);
    v0171 = qcar(v0170);
    v0170 = stack[0];
    v0170 = qcar(v0170);
    v0170 = qcar(v0170);
    fn = elt(env, 4); /* ordpp */
    v0170 = (*qfn2(fn))(qenv(fn), v0171, v0170);
    nil = C_nil;
    if (exception_pending()) goto v0140;
    env = stack[-3];
    if (v0170 == nil) goto v0174;
    v0170 = stack[-1];
    v0171 = qcar(v0170);
    v0170 = stack[-2];
    v0170 = cons(v0171, v0170);
    nil = C_nil;
    if (exception_pending()) goto v0140;
    env = stack[-3];
    stack[-2] = v0170;
    v0170 = stack[-1];
    v0170 = qcdr(v0170);
    stack[-1] = v0170;
    goto v0012;

v0174:
    v0170 = stack[0];
    v0171 = qcar(v0170);
    v0170 = stack[-2];
    v0170 = cons(v0171, v0170);
    nil = C_nil;
    if (exception_pending()) goto v0140;
    env = stack[-3];
    stack[-2] = v0170;
    v0170 = stack[0];
    v0170 = qcdr(v0170);
    stack[0] = v0170;
    goto v0012;

v0092:
    v0170 = stack[-1];
    v0170 = qcar(v0170);
    v0171 = qcdr(v0170);
    v0170 = stack[0];
    v0170 = qcar(v0170);
    v0170 = qcdr(v0170);
    v0170 = CC_addf(env, v0171, v0170);
    nil = C_nil;
    if (exception_pending()) goto v0140;
    env = stack[-3];
    v0171 = v0170;
    if (v0171 == nil) goto v0059;
    v0171 = stack[-1];
    v0171 = qcar(v0171);
    v0172 = qcar(v0171);
    v0171 = v0170;
    v0170 = stack[-2];
    v0170 = acons(v0172, v0171, v0170);
    nil = C_nil;
    if (exception_pending()) goto v0140;
    env = stack[-3];
    stack[-2] = v0170;
    goto v0059;

v0059:
    v0170 = stack[-1];
    v0170 = qcdr(v0170);
    stack[-1] = v0170;
    v0170 = stack[0];
    v0170 = qcdr(v0170);
    stack[0] = v0170;
    goto v0012;

v0062:
    v0170 = qvalue(elt(env, 1)); /* t */
    goto v0030;

v0040:
    v0170 = qvalue(elt(env, 1)); /* t */
    goto v0084;

v0024:
    v0170 = stack[-1];
    goto v0173;

v0015:
    v0170 = stack[0];
    goto v0173;
/* error exit handlers */
v0140:
    popv(4);
    return nil;
}



/* Code for aeval!* */

static Lisp_Object CC_aevalH(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0017, v0024;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for aeval*");
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
    v0017 = qvalue(elt(env, 1)); /* nil */
    v0017 = ncons(v0017);
    nil = C_nil;
    if (exception_pending()) goto v0082;
    env = stack[-1];
    qvalue(elt(env, 2)) = v0017; /* alglist!* */
    v0024 = stack[0];
    v0017 = qvalue(elt(env, 1)); /* nil */
    {
        popv(2);
        fn = elt(env, 3); /* reval1 */
        return (*qfn2(fn))(qenv(fn), v0024, v0017);
    }
/* error exit handlers */
v0082:
    popv(2);
    return nil;
}



/* Code for adddm */

static Lisp_Object CC_adddm(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0036)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0091, v0035, v0103;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for adddm");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0036,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0036);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v0035 = v0036;
    v0103 = v0000;
/* end of prologue */
    v0091 = v0103;
    if (!consp(v0091)) goto v0013;
    v0091 = qvalue(elt(env, 1)); /* nil */
    goto v0010;

v0010:
    if (v0091 == nil) goto v0068;
    v0091 = v0103;
    v0091 = plus2(v0091, v0035);
    nil = C_nil;
    if (exception_pending()) goto v0087;
    env = stack[0];
    v0035 = qvalue(elt(env, 2)); /* dmode!* */
    if (v0035 == nil) goto v0110;
    v0035 = qvalue(elt(env, 2)); /* dmode!* */
    if (!symbolp(v0035)) v0035 = nil;
    else { v0035 = qfastgets(v0035);
           if (v0035 != nil) { v0035 = elt(v0035, 5); /* convert */
#ifdef RECORD_GET
             if (v0035 == SPID_NOPROP)
                record_get(elt(fastget_names, 5), 0),
                v0035 = nil;
             else record_get(elt(fastget_names, 5), 1),
                v0035 = lisp_true; }
           else record_get(elt(fastget_names, 5), 0); }
#else
             if (v0035 == SPID_NOPROP) v0035 = nil; else v0035 = lisp_true; }}
#endif
    v0035 = (v0035 == nil ? lisp_true : nil);
    goto v0034;

v0034:
    if (v0035 == nil) goto v0094;
    {
        popv(1);
        fn = elt(env, 5); /* !*n2f */
        return (*qfn1(fn))(qenv(fn), v0091);
    }

v0094:
    v0035 = qvalue(elt(env, 2)); /* dmode!* */
    if (!symbolp(v0035)) v0035 = nil;
    else { v0035 = qfastgets(v0035);
           if (v0035 != nil) { v0035 = elt(v0035, 34); /* i2d */
#ifdef RECORD_GET
             if (v0035 != SPID_NOPROP)
                record_get(elt(fastget_names, 34), 1);
             else record_get(elt(fastget_names, 34), 0),
                v0035 = nil; }
           else record_get(elt(fastget_names, 34), 0); }
#else
             if (v0035 == SPID_NOPROP) v0035 = nil; }}
#endif
    v0091 = Lapply1(nil, v0035, v0091);
    nil = C_nil;
    if (exception_pending()) goto v0087;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 6); /* int!-equiv!-chk */
        return (*qfn1(fn))(qenv(fn), v0091);
    }

v0110:
    v0035 = qvalue(elt(env, 3)); /* t */
    goto v0034;

v0068:
    v0091 = elt(env, 4); /* plus */
    {
        popv(1);
        fn = elt(env, 7); /* dcombine */
        return (*qfnn(fn))(qenv(fn), 3, v0103, v0035, v0091);
    }

v0013:
    v0091 = v0035;
    v0091 = (consp(v0091) ? nil : lisp_true);
    goto v0010;
/* error exit handlers */
v0087:
    popv(1);
    return nil;
}



/* Code for mo!=sprod */

static Lisp_Object CC_moMsprod(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0036)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0086, v0032, v0033;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mo=sprod");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0036,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0036);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0036;
    stack[-1] = v0000;
/* end of prologue */
    v0033 = nil;
    goto v0012;

v0012:
    v0086 = stack[-1];
    if (v0086 == nil) goto v0037;
    v0086 = stack[0];
    v0086 = (v0086 == nil ? lisp_true : nil);
    goto v0024;

v0024:
    if (v0086 == nil) goto v0026;
    v0086 = (Lisp_Object)1; /* 0 */
    goto v0013;

v0013:
    v0032 = v0033;
    if (v0032 == nil) { popv(3); return onevalue(v0086); }
    v0032 = v0033;
    v0032 = qcar(v0032);
    v0086 = (Lisp_Object)(int32_t)((int32_t)v0032 + (int32_t)v0086 - TAG_FIXNUM);
    v0032 = v0033;
    v0032 = qcdr(v0032);
    v0033 = v0032;
    goto v0013;

v0026:
    v0086 = stack[-1];
    v0032 = qcar(v0086);
    v0086 = stack[0];
    v0086 = qcar(v0086);
    v0086 = fixnum_of_int((int32_t)(int_of_fixnum(v0032) * int_of_fixnum(v0086)));
    v0032 = v0033;
    v0086 = cons(v0086, v0032);
    nil = C_nil;
    if (exception_pending()) goto v0091;
    env = stack[-2];
    v0033 = v0086;
    v0086 = stack[-1];
    v0086 = qcdr(v0086);
    stack[-1] = v0086;
    v0086 = stack[0];
    v0086 = qcdr(v0086);
    stack[0] = v0086;
    goto v0012;

v0037:
    v0086 = qvalue(elt(env, 1)); /* t */
    goto v0024;
/* error exit handlers */
v0091:
    popv(3);
    return nil;
}



/* Code for sieve_pv */

static Lisp_Object CC_sieve_pv(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0036)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0017, v0024, v0037;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sieve_pv");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0017 = v0036;
    v0024 = v0000;
/* end of prologue */
    v0037 = v0024;
    v0024 = v0017;
    v0017 = qvalue(elt(env, 1)); /* t */
    {
        fn = elt(env, 2); /* sieve_pv0 */
        return (*qfnn(fn))(qenv(fn), 3, v0037, v0024, v0017);
    }
}



/* Code for general!-modular!-plus */

static Lisp_Object CC_generalKmodularKplus(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0036)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0021, v0020;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for general-modular-plus");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0036,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0036);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0021 = v0036;
    v0020 = v0000;
/* end of prologue */
    v0021 = plus2(v0020, v0021);
    nil = C_nil;
    if (exception_pending()) goto v0003;
    env = stack[-1];
    stack[0] = v0021;
    v0020 = stack[0];
    v0021 = qvalue(elt(env, 1)); /* current!-modulus */
    v0021 = (Lisp_Object)geq2(v0020, v0021);
    nil = C_nil;
    if (exception_pending()) goto v0003;
    v0021 = v0021 ? lisp_true : nil;
    env = stack[-1];
    if (v0021 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v0020 = stack[0];
    v0021 = qvalue(elt(env, 1)); /* current!-modulus */
    v0021 = difference2(v0020, v0021);
    nil = C_nil;
    if (exception_pending()) goto v0003;
    stack[0] = v0021;
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
/* error exit handlers */
v0003:
    popv(2);
    return nil;
}



/* Code for multiply!-by!-constant!-mod!-p */

static Lisp_Object CC_multiplyKbyKconstantKmodKp(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0036)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0053, v0055, v0054;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for multiply-by-constant-mod-p");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0036,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0036);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0036;
    stack[-2] = v0000;
/* end of prologue */
    stack[-3] = nil;
    v0053 = stack[-2];
    if (v0053 == nil) goto v0013;
    v0055 = stack[-1];
    v0053 = (Lisp_Object)17; /* 1 */
    if (v0055 == v0053) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    else goto v0098;

v0098:
    v0053 = stack[-2];
    if (!consp(v0053)) goto v0110;
    v0053 = stack[-2];
    v0053 = qcar(v0053);
    v0053 = (consp(v0053) ? nil : lisp_true);
    goto v0034;

v0034:
    if (v0053 == nil) goto v0030;
    v0053 = stack[-2];
    if (v0053 == nil) goto v0181;
    v0055 = stack[-2];
    v0053 = stack[-1];
    v0053 = Lmodular_times(nil, v0055, v0053);
    env = stack[-4];
    fn = elt(env, 3); /* !*n2f */
    v0053 = (*qfn1(fn))(qenv(fn), v0053);
    nil = C_nil;
    if (exception_pending()) goto v0161;
    env = stack[-4];
    stack[-2] = v0053;
    goto v0181;

v0181:
    v0053 = stack[-3];
    if (v0053 == nil) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v0053 = stack[-3];
    v0053 = qcdr(v0053);
    stack[0] = v0053;
    v0055 = stack[-3];
    v0053 = stack[-2];
    v0053 = Lrplacd(nil, v0055, v0053);
    nil = C_nil;
    if (exception_pending()) goto v0161;
    env = stack[-4];
    v0053 = stack[-3];
    stack[-2] = v0053;
    v0053 = stack[0];
    stack[-3] = v0053;
    goto v0181;

v0030:
    v0053 = stack[-2];
    v0053 = qcar(v0053);
    v0055 = qcdr(v0053);
    v0053 = stack[-1];
    v0053 = CC_multiplyKbyKconstantKmodKp(env, v0055, v0053);
    nil = C_nil;
    if (exception_pending()) goto v0161;
    env = stack[-4];
    stack[0] = v0053;
    v0053 = stack[0];
    if (v0053 == nil) goto v0061;
    v0053 = stack[-2];
    v0053 = qcar(v0053);
    v0054 = qcar(v0053);
    v0055 = stack[0];
    v0053 = stack[-3];
    v0053 = acons(v0054, v0055, v0053);
    nil = C_nil;
    if (exception_pending()) goto v0161;
    env = stack[-4];
    stack[-3] = v0053;
    goto v0061;

v0061:
    v0053 = stack[-2];
    v0053 = qcdr(v0053);
    stack[-2] = v0053;
    goto v0098;

v0110:
    v0053 = qvalue(elt(env, 2)); /* t */
    goto v0034;

v0013:
    v0053 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v0053); }
/* error exit handlers */
v0161:
    popv(5);
    return nil;
}



/* Code for list2wideid */

static Lisp_Object CC_list2wideid(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0005;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for list2wideid");
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
    v0005 = v0000;
/* end of prologue */
    fn = elt(env, 1); /* list2widestring */
    v0005 = (*qfn1(fn))(qenv(fn), v0005);
    errexit();
        return Lintern(nil, v0005);
}



/* Code for setcdr */

static Lisp_Object CC_setcdr(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0036)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0016, v0008;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for setcdr");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0036,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0036);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v0036;
    v0016 = v0000;
/* end of prologue */
    v0008 = v0016;
    v0016 = stack[0];
    v0016 = Lrplacd(nil, v0008, v0016);
    nil = C_nil;
    if (exception_pending()) goto v0024;
    { Lisp_Object res = stack[0]; popv(1); return onevalue(res); }
/* error exit handlers */
v0024:
    popv(1);
    return nil;
}



/* Code for comfac!-to!-poly */

static Lisp_Object CC_comfacKtoKpoly(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0017, v0024;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for comfac-to-poly");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0017 = v0000;
/* end of prologue */
    v0024 = v0017;
    v0024 = qcar(v0024);
    if (v0024 == nil) goto v0006;
    return ncons(v0017);

v0006:
    v0017 = qcdr(v0017);
    return onevalue(v0017);
}



/* Code for mtchk */

static Lisp_Object CC_mtchk(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0036)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0195, v0196, v0129, v0197;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mtchk");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0036,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0036);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-8] = v0036;
    stack[-9] = v0000;
/* end of prologue */
    stack[-4] = nil;
    stack[-3] = nil;
    v0195 = stack[-9];
    v0195 = qcar(v0195);
    fn = elt(env, 1); /* noncomp */
    v0195 = (*qfn1(fn))(qenv(fn), v0195);
    nil = C_nil;
    if (exception_pending()) goto v0134;
    env = stack[-11];
    stack[-10] = v0195;
    goto v0016;

v0016:
    v0195 = stack[-8];
    if (v0195 == nil) { Lisp_Object res = stack[-4]; popv(12); return onevalue(res); }
    v0195 = stack[-8];
    v0195 = qcar(v0195);
    stack[-7] = v0195;
    v0195 = stack[-7];
    v0195 = qcar(v0195);
    stack[-6] = v0195;
    goto v0008;

v0008:
    v0195 = stack[-6];
    if (v0195 == nil) goto v0037;
    v0197 = stack[-9];
    v0195 = stack[-6];
    v0129 = qcar(v0195);
    v0195 = stack[-7];
    v0195 = qcdr(v0195);
    v0195 = qcar(v0195);
    v0196 = qcar(v0195);
    v0195 = stack[-7];
    v0195 = qcdr(v0195);
    v0195 = qcar(v0195);
    v0195 = qcdr(v0195);
    fn = elt(env, 2); /* mtchp1 */
    v0195 = (*qfnn(fn))(qenv(fn), 4, v0197, v0129, v0196, v0195);
    nil = C_nil;
    if (exception_pending()) goto v0134;
    env = stack[-11];
    stack[-5] = v0195;
    goto v0017;

v0017:
    v0195 = stack[-5];
    if (v0195 == nil) goto v0024;
    v0195 = stack[-5];
    stack[0] = qcar(v0195);
    v0195 = stack[-6];
    v0196 = qcar(v0195);
    v0195 = stack[-7];
    v0195 = qcar(v0195);
    v0195 = Ldelete(nil, v0196, v0195);
    nil = C_nil;
    if (exception_pending()) goto v0134;
    env = stack[-11];
    stack[-2] = Lsubla(nil, stack[0], v0195);
    nil = C_nil;
    if (exception_pending()) goto v0134;
    env = stack[-11];
    v0195 = stack[-5];
    v0196 = qcar(v0195);
    v0195 = stack[-7];
    v0195 = qcdr(v0195);
    v0195 = qcar(v0195);
    stack[-1] = Lsubla(nil, v0196, v0195);
    nil = C_nil;
    if (exception_pending()) goto v0134;
    env = stack[-11];
    v0195 = stack[-5];
    v0196 = qcar(v0195);
    v0195 = stack[-7];
    v0195 = qcdr(v0195);
    v0195 = qcdr(v0195);
    v0195 = qcar(v0195);
    stack[0] = Lsubla(nil, v0196, v0195);
    nil = C_nil;
    if (exception_pending()) goto v0134;
    env = stack[-11];
    v0195 = stack[-5];
    v0196 = qcar(v0195);
    v0195 = stack[-6];
    v0195 = qcar(v0195);
    v0196 = Lsubla(nil, v0196, v0195);
    nil = C_nil;
    if (exception_pending()) goto v0134;
    env = stack[-11];
    v0195 = stack[-7];
    v0195 = qcdr(v0195);
    v0195 = qcdr(v0195);
    v0195 = qcdr(v0195);
    v0195 = qcar(v0195);
    v0195 = cons(v0196, v0195);
    nil = C_nil;
    if (exception_pending()) goto v0134;
    env = stack[-11];
    v0195 = list2(stack[0], v0195);
    nil = C_nil;
    if (exception_pending()) goto v0134;
    env = stack[-11];
    v0195 = list2star(stack[-2], stack[-1], v0195);
    nil = C_nil;
    if (exception_pending()) goto v0134;
    env = stack[-11];
    stack[0] = v0195;
    v0195 = qcar(v0195);
    if (v0195 == nil) goto v0198;
    v0196 = stack[0];
    v0195 = stack[-4];
    v0195 = cons(v0196, v0195);
    nil = C_nil;
    if (exception_pending()) goto v0134;
    env = stack[-11];
    stack[-4] = v0195;
    v0195 = stack[-3];
    if (!(v0195 == nil)) goto v0177;
    v0195 = stack[-4];
    stack[-3] = v0195;
    goto v0177;

v0177:
    v0195 = stack[-5];
    v0195 = qcdr(v0195);
    stack[-5] = v0195;
    goto v0017;

v0198:
    v0195 = stack[-5];
    v0196 = qcar(v0195);
    v0195 = stack[-7];
    v0195 = qcdr(v0195);
    v0195 = qcar(v0195);
    v0195 = qcdr(v0195);
    v0195 = Lsubla(nil, v0196, v0195);
    nil = C_nil;
    if (exception_pending()) goto v0134;
    env = stack[-11];
    fn = elt(env, 3); /* lispeval */
    v0195 = (*qfn1(fn))(qenv(fn), v0195);
    nil = C_nil;
    if (exception_pending()) goto v0134;
    env = stack[-11];
    if (v0195 == nil) goto v0177;
    v0195 = stack[0];
    popv(12);
    return ncons(v0195);

v0024:
    v0195 = stack[-10];
    if (v0195 == nil) goto v0141;
    v0195 = stack[-7];
    v0195 = qcdr(v0195);
    v0195 = qcdr(v0195);
    v0195 = qcdr(v0195);
    v0195 = qcar(v0195);
    if (v0195 == nil) goto v0037;
    v0195 = stack[-6];
    fn = elt(env, 4); /* nocp */
    v0195 = (*qfn1(fn))(qenv(fn), v0195);
    nil = C_nil;
    if (exception_pending()) goto v0134;
    env = stack[-11];
    if (!(v0195 == nil)) goto v0082;

v0037:
    v0195 = stack[-4];
    if (v0195 == nil) goto v0199;
    stack[0] = stack[-3];
    v0195 = stack[-7];
    v0195 = ncons(v0195);
    nil = C_nil;
    if (exception_pending()) goto v0134;
    env = stack[-11];
    v0195 = Lrplacd(nil, stack[0], v0195);
    nil = C_nil;
    if (exception_pending()) goto v0134;
    env = stack[-11];
    v0195 = stack[-3];
    v0195 = qcdr(v0195);
    stack[-3] = v0195;
    goto v0082;

v0082:
    v0195 = stack[-8];
    v0195 = qcdr(v0195);
    stack[-8] = v0195;
    goto v0016;

v0199:
    v0195 = stack[-7];
    v0195 = ncons(v0195);
    nil = C_nil;
    if (exception_pending()) goto v0134;
    env = stack[-11];
    stack[-3] = v0195;
    stack[-4] = v0195;
    goto v0082;

v0141:
    v0195 = stack[-6];
    v0195 = qcdr(v0195);
    stack[-6] = v0195;
    goto v0008;
/* error exit handlers */
v0134:
    popv(12);
    return nil;
}



/* Code for quotsq */

static Lisp_Object CC_quotsq(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0036)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0016, v0008;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for quotsq");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0036,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0036);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0016 = v0036;
    v0008 = v0000;
/* end of prologue */
    stack[0] = v0008;
    fn = elt(env, 1); /* invsq */
    v0016 = (*qfn1(fn))(qenv(fn), v0016);
    nil = C_nil;
    if (exception_pending()) goto v0024;
    env = stack[-1];
    {
        Lisp_Object v0037 = stack[0];
        popv(2);
        fn = elt(env, 2); /* multsq */
        return (*qfn2(fn))(qenv(fn), v0037, v0016);
    }
/* error exit handlers */
v0024:
    popv(2);
    return nil;
}



/* Code for exptchksq */

static Lisp_Object CC_exptchksq(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0040;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for exptchksq");
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
    v0040 = qvalue(elt(env, 1)); /* !*combineexpt */
    if (v0040 == nil) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v0040 = stack[0];
    v0040 = qcar(v0040);
    fn = elt(env, 2); /* exptchk */
    stack[-1] = (*qfn1(fn))(qenv(fn), v0040);
    nil = C_nil;
    if (exception_pending()) goto v0163;
    env = stack[-2];
    v0040 = stack[0];
    v0040 = qcdr(v0040);
    fn = elt(env, 2); /* exptchk */
    v0040 = (*qfn1(fn))(qenv(fn), v0040);
    nil = C_nil;
    if (exception_pending()) goto v0163;
    env = stack[-2];
    fn = elt(env, 3); /* invsq */
    v0040 = (*qfn1(fn))(qenv(fn), v0040);
    nil = C_nil;
    if (exception_pending()) goto v0163;
    env = stack[-2];
    {
        Lisp_Object v0011 = stack[-1];
        popv(3);
        fn = elt(env, 4); /* multsq */
        return (*qfn2(fn))(qenv(fn), v0011, v0040);
    }
/* error exit handlers */
v0163:
    popv(3);
    return nil;
}



/* Code for setcar */

static Lisp_Object CC_setcar(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0036)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0016, v0008;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for setcar");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0036,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0036);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v0036;
    v0016 = v0000;
/* end of prologue */
    v0008 = v0016;
    v0016 = stack[0];
    v0016 = Lrplaca(nil, v0008, v0016);
    nil = C_nil;
    if (exception_pending()) goto v0024;
    { Lisp_Object res = stack[0]; popv(1); return onevalue(res); }
/* error exit handlers */
v0024:
    popv(1);
    return nil;
}



/* Code for aex_ctx */

static Lisp_Object CC_aex_ctx(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0014, v0015;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for aex_ctx");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0014 = v0000;
/* end of prologue */
    v0015 = v0014;
    v0014 = (Lisp_Object)49; /* 3 */
    {
        fn = elt(env, 1); /* nth */
        return (*qfn2(fn))(qenv(fn), v0015, v0014);
    }
}



/* Code for notstring */

static Lisp_Object CC_notstring(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0007, v0094, v0018;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for notstring");
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
    v0007 = v0000;
/* end of prologue */
    v0094 = elt(env, 1); /* !  */
    fn = elt(env, 5); /* delall */
    v0007 = (*qfn2(fn))(qenv(fn), v0094, v0007);
    nil = C_nil;
    if (exception_pending()) goto v0025;
    env = stack[0];
    v0018 = v0007;
    v0007 = v0018;
    v0094 = qcar(v0007);
    v0007 = elt(env, 2); /* !" */
    if (v0094 == v0007) goto v0031;
    v0007 = v0018;
    v0007 = Lreverse(nil, v0007);
    nil = C_nil;
    if (exception_pending()) goto v0025;
    env = stack[0];
    v0094 = qcar(v0007);
    v0007 = elt(env, 2); /* !" */
    v0007 = Lneq(nil, v0094, v0007);
    nil = C_nil;
    if (exception_pending()) goto v0025;
    env = stack[0];
    goto v0162;

v0162:
    if (v0007 == nil) goto v0030;
    v0007 = qvalue(elt(env, 4)); /* t */
    { popv(1); return onevalue(v0007); }

v0030:
    v0007 = qvalue(elt(env, 3)); /* nil */
    { popv(1); return onevalue(v0007); }

v0031:
    v0007 = qvalue(elt(env, 3)); /* nil */
    goto v0162;
/* error exit handlers */
v0025:
    popv(1);
    return nil;
}



/* Code for constp */

static Lisp_Object CC_constp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0098, v0163;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for constp");
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
    v0098 = v0000;
/* end of prologue */
    v0163 = v0098;
    v0163 = (is_number(v0163) ? lisp_true : nil);
    if (!(v0163 == nil)) { popv(1); return onevalue(v0163); }
    v0163 = v0098;
    v0163 = Lconsp(nil, v0163);
    env = stack[0];
    if (v0163 == nil) goto v0013;
    v0098 = qcar(v0098);
    v0163 = qvalue(elt(env, 2)); /* domainlist!* */
    v0098 = Lmemq(nil, v0098, v0163);
    { popv(1); return onevalue(v0098); }

v0013:
    v0098 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v0098); }
}



/* Code for bczero!? */

static Lisp_Object CC_bczeroW(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0081, v0083;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for bczero?");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0081 = v0000;
/* end of prologue */
    v0083 = qvalue(elt(env, 1)); /* !*grmod!* */
    if (v0083 == nil) goto v0024;
    v0083 = v0081;
    v0081 = (Lisp_Object)1; /* 0 */
        return Leqn(nil, v0083, v0081);

v0024:
    v0081 = qcar(v0081);
    v0081 = (v0081 == nil ? lisp_true : nil);
    return onevalue(v0081);
}



/* Code for fast!-row!-dim */

static Lisp_Object CC_fastKrowKdim(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0005;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for fast-row-dim");
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
    v0005 = v0000;
/* end of prologue */
    v0005 = Lupbv(nil, v0005);
    errexit();
    return add1(v0005);
}



/* Code for makelist */

static Lisp_Object CC_makelist(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0014, v0015;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for makelist");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0014 = v0000;
/* end of prologue */
    v0015 = elt(env, 1); /* list */
    return cons(v0015, v0014);
}



/* Code for sinitl */

static Lisp_Object CC_sinitl(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0016;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sinitl");
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
    v0016 = v0000;
/* end of prologue */
    stack[0] = v0016;
    if (!symbolp(v0016)) v0016 = nil;
    else { v0016 = qfastgets(v0016);
           if (v0016 != nil) { v0016 = elt(v0016, 47); /* initl */
#ifdef RECORD_GET
             if (v0016 != SPID_NOPROP)
                record_get(elt(fastget_names, 47), 1);
             else record_get(elt(fastget_names, 47), 0),
                v0016 = nil; }
           else record_get(elt(fastget_names, 47), 0); }
#else
             if (v0016 == SPID_NOPROP) v0016 = nil; }}
#endif
    fn = elt(env, 1); /* eval */
    v0016 = (*qfn1(fn))(qenv(fn), v0016);
    nil = C_nil;
    if (exception_pending()) goto v0017;
    {
        Lisp_Object v0024 = stack[0];
        popv(1);
        return Lset(nil, v0024, v0016);
    }
/* error exit handlers */
v0017:
    popv(1);
    return nil;
}



/* Code for smemqlp */

static Lisp_Object CC_smemqlp(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0036)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0086, v0032;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for smemqlp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0036,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0036);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0036;
    stack[-1] = v0000;
/* end of prologue */

v0097:
    v0086 = stack[0];
    if (v0086 == nil) goto v0013;
    v0086 = stack[0];
    v0086 = (is_number(v0086) ? lisp_true : nil);
    goto v0010;

v0010:
    if (v0086 == nil) goto v0001;
    v0086 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v0086); }

v0001:
    v0086 = stack[0];
    if (!consp(v0086)) goto v0083;
    v0086 = stack[0];
    v0032 = qcar(v0086);
    v0086 = elt(env, 3); /* quote */
    if (v0032 == v0086) goto v0041;
    v0032 = stack[-1];
    v0086 = stack[0];
    v0086 = qcar(v0086);
    v0086 = CC_smemqlp(env, v0032, v0086);
    nil = C_nil;
    if (exception_pending()) goto v0175;
    env = stack[-2];
    if (!(v0086 == nil)) { popv(3); return onevalue(v0086); }
    v0032 = stack[-1];
    v0086 = stack[0];
    v0086 = qcdr(v0086);
    stack[-1] = v0032;
    stack[0] = v0086;
    goto v0097;

v0041:
    v0086 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v0086); }

v0083:
    v0032 = stack[0];
    v0086 = stack[-1];
    v0086 = Lmemq(nil, v0032, v0086);
    { popv(3); return onevalue(v0086); }

v0013:
    v0086 = qvalue(elt(env, 1)); /* t */
    goto v0010;
/* error exit handlers */
v0175:
    popv(3);
    return nil;
}



/* Code for angles!-equal */

static Lisp_Object CC_anglesKequal(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0036)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0025, v0180, v0009;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for angles-equal");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0036,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0036);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0036;
    stack[-1] = v0000;
/* end of prologue */
    v0025 = (Lisp_Object)1; /* 0 */
    stack[-2] = v0025;
    goto v0082;

v0082:
    v0180 = stack[-1];
    v0025 = stack[-2];
    v0009 = *(Lisp_Object *)((char *)v0180 + (CELL-TAG_VECTOR) + ((int32_t)v0025/(16/CELL)));
    v0180 = stack[0];
    v0025 = stack[-2];
    v0025 = *(Lisp_Object *)((char *)v0180 + (CELL-TAG_VECTOR) + ((int32_t)v0025/(16/CELL)));
    if (equal(v0009, v0025)) goto v0013;
    v0025 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v0025); }

v0013:
    v0025 = stack[-2];
    v0025 = add1(v0025);
    nil = C_nil;
    if (exception_pending()) goto v0023;
    env = stack[-3];
    stack[-2] = v0025;
    v0180 = stack[-2];
    v0025 = (Lisp_Object)129; /* 8 */
    v0025 = (Lisp_Object)lessp2(v0180, v0025);
    nil = C_nil;
    if (exception_pending()) goto v0023;
    v0025 = v0025 ? lisp_true : nil;
    env = stack[-3];
    if (!(v0025 == nil)) goto v0082;
    v0025 = qvalue(elt(env, 2)); /* t */
    { popv(4); return onevalue(v0025); }
/* error exit handlers */
v0023:
    popv(4);
    return nil;
}



/* Code for negnumberchk */

static Lisp_Object CC_negnumberchk(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0110, v0067, v0038;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for negnumberchk");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0038 = v0000;
/* end of prologue */
    v0067 = v0038;
    v0110 = elt(env, 1); /* minus */
    if (!consp(v0067)) goto v0084;
    v0067 = qcar(v0067);
    if (!(v0067 == v0110)) goto v0084;
    v0110 = v0038;
    v0110 = qcdr(v0110);
    v0110 = qcar(v0110);
    v0110 = (is_number(v0110) ? lisp_true : nil);
    goto v0012;

v0012:
    if (v0110 == nil) return onevalue(v0038);
    v0110 = v0038;
    v0110 = qcdr(v0110);
    v0110 = qcar(v0110);
    return negate(v0110);

v0084:
    v0110 = qvalue(elt(env, 2)); /* nil */
    goto v0012;
}



/* Code for pappl0 */

static Lisp_Object CC_pappl0(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0036)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0008, v0017;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pappl0");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0036,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0036);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0008 = v0036;
    v0017 = v0000;
/* end of prologue */
    stack[0] = v0017;
    fn = elt(env, 1); /* unpkp */
    v0008 = (*qfn1(fn))(qenv(fn), v0008);
    nil = C_nil;
    if (exception_pending()) goto v0037;
    env = stack[-1];
    fn = elt(env, 2); /* pappl */
    v0008 = (*qfn2(fn))(qenv(fn), stack[0], v0008);
    nil = C_nil;
    if (exception_pending()) goto v0037;
    env = stack[-1];
    {
        popv(2);
        fn = elt(env, 3); /* pkp */
        return (*qfn1(fn))(qenv(fn), v0008);
    }
/* error exit handlers */
v0037:
    popv(2);
    return nil;
}



/* Code for rnonep!: */

static Lisp_Object CC_rnonepT(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0105, v0041, v0026;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rnonep:");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0026 = v0000;
/* end of prologue */
    v0105 = v0026;
    v0105 = qcdr(v0105);
    v0041 = qcar(v0105);
    v0105 = (Lisp_Object)17; /* 1 */
    if (v0041 == v0105) goto v0024;
    v0105 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v0105);

v0024:
    v0105 = v0026;
    v0105 = qcdr(v0105);
    v0041 = qcdr(v0105);
    v0105 = (Lisp_Object)17; /* 1 */
    v0105 = (v0041 == v0105 ? lisp_true : nil);
    return onevalue(v0105);
}



/* Code for modtimes!: */

static Lisp_Object CC_modtimesT(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0036)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0017, v0024;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for modtimes:");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0036,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0036);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v0017 = v0036;
    v0024 = v0000;
/* end of prologue */
    v0024 = qcdr(v0024);
    v0017 = qcdr(v0017);
    fn = elt(env, 1); /* general!-modular!-times */
    v0017 = (*qfn2(fn))(qenv(fn), v0024, v0017);
    nil = C_nil;
    if (exception_pending()) goto v0037;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* !*modular2f */
        return (*qfn1(fn))(qenv(fn), v0017);
    }
/* error exit handlers */
v0037:
    popv(1);
    return nil;
}



/* Code for remainder!-in!-vector */

static Lisp_Object MS_CDECL CC_remainderKinKvector(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0211, v0136, v0137, v0212, v0042, v0043, v0063, v0064, v0213, v0159;
    Lisp_Object fn;
    Lisp_Object v0004, v0029, v0036, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "remainder-in-vector");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0036 = va_arg(aa, Lisp_Object);
    v0029 = va_arg(aa, Lisp_Object);
    v0004 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for remainder-in-vector");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v0004,v0029,v0036,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0000,v0036,v0029,v0004);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0004;
    stack[-1] = v0029;
    stack[-2] = v0036;
    stack[-3] = v0000;
/* end of prologue */
    v0136 = stack[0];
    v0211 = (Lisp_Object)1; /* 0 */
    if (v0136 == v0211) goto v0008;
    v0136 = stack[0];
    v0211 = (Lisp_Object)-15; /* -1 */
    if (!(v0136 == v0211)) goto v0021;
    v0211 = elt(env, 1); /* "Attempt to divide by zero" */
    fn = elt(env, 3); /* errorf */
    v0211 = (*qfn1(fn))(qenv(fn), v0211);
    nil = C_nil;
    if (exception_pending()) goto v0214;
    env = stack[-4];
    goto v0021;

v0021:
    v0136 = stack[-1];
    v0211 = stack[0];
    v0211 = *(Lisp_Object *)((char *)v0136 + (CELL-TAG_VECTOR) + ((int32_t)v0211/(16/CELL)));
    v0211 = Lmodular_reciprocal(nil, v0211);
    nil = C_nil;
    if (exception_pending()) goto v0214;
    env = stack[-4];
    {   int32_t w = int_of_fixnum(v0211);
        if (w != 0) w = current_modulus - w;
        v0211 = fixnum_of_int(w);
    }
    v0064 = v0211;
    v0211 = stack[0];
    v0211 = (Lisp_Object)((int32_t)(v0211) - 0x10);
    v0213 = v0211;
    goto v0177;

v0177:
    v0136 = stack[-2];
    v0211 = stack[0];
    v0136 = (Lisp_Object)(int32_t)((int32_t)v0136 - (int32_t)v0211 + TAG_FIXNUM);
    v0159 = v0136;
    v0211 = (Lisp_Object)1; /* 0 */
    if (((int32_t)(v0136)) < ((int32_t)(v0211))) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v0137 = v0064;
    v0136 = stack[-3];
    v0211 = stack[-2];
    v0211 = *(Lisp_Object *)((char *)v0136 + (CELL-TAG_VECTOR) + ((int32_t)v0211/(16/CELL)));
    v0211 = Lmodular_times(nil, v0137, v0211);
    env = stack[-4];
    v0063 = v0211;
    v0211 = (Lisp_Object)1; /* 0 */
    v0043 = v0211;
    goto v0150;

v0150:
    v0136 = v0213;
    v0211 = v0043;
    v0211 = (Lisp_Object)(int32_t)((int32_t)v0136 - (int32_t)v0211 + TAG_FIXNUM);
    v0211 = ((intptr_t)(v0211) < 0 ? lisp_true : nil);
    if (v0211 == nil) goto v0148;
    v0211 = stack[-2];
    v0211 = (Lisp_Object)((int32_t)(v0211) - 0x10);
    stack[-2] = v0211;
    goto v0171;

v0171:
    v0136 = stack[-2];
    v0211 = (Lisp_Object)1; /* 0 */
    if (((int32_t)(v0136)) < ((int32_t)(v0211))) goto v0215;
    v0136 = stack[-3];
    v0211 = stack[-2];
    v0136 = *(Lisp_Object *)((char *)v0136 + (CELL-TAG_VECTOR) + ((int32_t)v0211/(16/CELL)));
    v0211 = (Lisp_Object)1; /* 0 */
    v0211 = (v0136 == v0211 ? lisp_true : nil);
    goto v0216;

v0216:
    if (v0211 == nil) goto v0177;
    v0211 = stack[-2];
    v0211 = (Lisp_Object)((int32_t)(v0211) - 0x10);
    stack[-2] = v0211;
    goto v0171;

v0215:
    v0211 = qvalue(elt(env, 2)); /* nil */
    goto v0216;

v0148:
    v0042 = stack[-3];
    v0136 = v0043;
    v0211 = v0159;
    v0212 = (Lisp_Object)(int32_t)((int32_t)v0136 + (int32_t)v0211 - TAG_FIXNUM);
    v0137 = stack[-3];
    v0136 = v0043;
    v0211 = v0159;
    v0211 = (Lisp_Object)(int32_t)((int32_t)v0136 + (int32_t)v0211 - TAG_FIXNUM);
    v0137 = *(Lisp_Object *)((char *)v0137 + (CELL-TAG_VECTOR) + ((int32_t)v0211/(16/CELL)));
    v0136 = stack[-1];
    v0211 = v0043;
    v0136 = *(Lisp_Object *)((char *)v0136 + (CELL-TAG_VECTOR) + ((int32_t)v0211/(16/CELL)));
    v0211 = v0063;
    v0211 = Lmodular_times(nil, v0136, v0211);
    env = stack[-4];
    {   int32_t w = int_of_fixnum(v0137) + int_of_fixnum(v0211);
        if (w >= current_modulus) w -= current_modulus;
        v0211 = fixnum_of_int(w);
    }
    *(Lisp_Object *)((char *)v0042 + (CELL-TAG_VECTOR) + ((int32_t)v0212/(16/CELL))) = v0211;
    v0211 = v0043;
    v0211 = (Lisp_Object)((int32_t)(v0211) + 0x10);
    v0043 = v0211;
    goto v0150;

v0008:
    v0211 = (Lisp_Object)-15; /* -1 */
    { popv(5); return onevalue(v0211); }
/* error exit handlers */
v0214:
    popv(5);
    return nil;
}



/* Code for lesspcar */

static Lisp_Object CC_lesspcar(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0036)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0008, v0017;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for lesspcar");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0008 = v0036;
    v0017 = v0000;
/* end of prologue */
    v0017 = qcar(v0017);
    v0008 = qcar(v0008);
        return Llessp(nil, v0017, v0008);
}



/* Code for cl_atmlc */

static Lisp_Object CC_cl_atmlc(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0015, v0016;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for cl_atmlc");
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
    v0015 = v0000;
/* end of prologue */
    v0016 = v0015;
    v0015 = (Lisp_Object)17; /* 1 */
    v0015 = cons(v0016, v0015);
    errexit();
    return ncons(v0015);
}



/* Code for monomclone */

static Lisp_Object CC_monomclone(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0092, v0070, v0109, v0164;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for monomclone");
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
    stack[0] = v0000;
/* end of prologue */
    v0092 = stack[0];
    if (v0092 == nil) goto v0006;
    stack[-2] = nil;
    v0092 = (Lisp_Object)17; /* 1 */
    v0092 = Lmkvect(nil, v0092);
    nil = C_nil;
    if (exception_pending()) goto v0165;
    env = stack[-4];
    stack[-3] = v0092;
    v0164 = stack[-3];
    v0109 = (Lisp_Object)1; /* 0 */
    v0070 = stack[0];
    v0092 = (Lisp_Object)1; /* 0 */
    v0092 = *(Lisp_Object *)((char *)v0070 + (CELL-TAG_VECTOR) + ((int32_t)v0092/(16/CELL)));
    *(Lisp_Object *)((char *)v0164 + (CELL-TAG_VECTOR) + ((int32_t)v0109/(16/CELL))) = v0092;
    v0070 = stack[0];
    v0092 = (Lisp_Object)17; /* 1 */
    v0092 = *(Lisp_Object *)((char *)v0070 + (CELL-TAG_VECTOR) + ((int32_t)v0092/(16/CELL)));
    stack[0] = v0092;
    goto v0062;

v0062:
    v0092 = stack[0];
    if (v0092 == nil) goto v0086;
    v0092 = stack[0];
    v0070 = qcar(v0092);
    v0092 = stack[-2];
    v0092 = cons(v0070, v0092);
    nil = C_nil;
    if (exception_pending()) goto v0165;
    env = stack[-4];
    stack[-2] = v0092;
    v0092 = stack[0];
    v0092 = qcdr(v0092);
    stack[0] = v0092;
    goto v0062;

v0086:
    stack[-1] = stack[-3];
    stack[0] = (Lisp_Object)17; /* 1 */
    v0092 = stack[-2];
    v0092 = Lreverse(nil, v0092);
    nil = C_nil;
    if (exception_pending()) goto v0165;
    *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)stack[0]/(16/CELL))) = v0092;
    { Lisp_Object res = stack[-3]; popv(5); return onevalue(res); }

v0006:
    v0092 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v0092); }
/* error exit handlers */
v0165:
    popv(5);
    return nil;
}



/* Code for powers0 */

static Lisp_Object CC_powers0(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0036)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0202, v0169, v0073;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for powers0");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0036,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0036);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0036;
    stack[-1] = v0000;
/* end of prologue */

v0097:
    v0202 = stack[-1];
    if (v0202 == nil) goto v0013;
    v0202 = stack[-1];
    if (!consp(v0202)) goto v0082;
    v0202 = stack[-1];
    v0202 = qcar(v0202);
    v0202 = (consp(v0202) ? nil : lisp_true);
    goto v0010;

v0010:
    if (!(v0202 == nil)) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v0202 = stack[-1];
    v0202 = qcar(v0202);
    v0202 = qcar(v0202);
    v0169 = qcar(v0202);
    v0202 = stack[0];
    v0169 = Latsoc(nil, v0169, v0202);
    v0202 = v0169;
    if (v0169 == nil) goto v0165;
    v0169 = stack[-1];
    v0169 = qcar(v0169);
    v0169 = qcar(v0169);
    v0169 = qcdr(v0169);
    v0202 = qcdr(v0202);
    v0202 = (Lisp_Object)greaterp2(v0169, v0202);
    nil = C_nil;
    if (exception_pending()) goto v0217;
    v0202 = v0202 ? lisp_true : nil;
    env = stack[-3];
    if (v0202 == nil) goto v0071;
    v0202 = stack[-1];
    v0202 = qcar(v0202);
    v0202 = qcar(v0202);
    v0073 = qcar(v0202);
    v0202 = stack[-1];
    v0202 = qcar(v0202);
    v0202 = qcar(v0202);
    v0169 = qcdr(v0202);
    v0202 = stack[0];
    fn = elt(env, 2); /* repasc */
    v0202 = (*qfnn(fn))(qenv(fn), 3, v0073, v0169, v0202);
    nil = C_nil;
    if (exception_pending()) goto v0217;
    env = stack[-3];
    stack[0] = v0202;
    goto v0071;

v0071:
    v0202 = stack[-1];
    stack[-2] = qcdr(v0202);
    v0202 = stack[-1];
    v0202 = qcar(v0202);
    v0169 = qcdr(v0202);
    v0202 = stack[0];
    v0202 = CC_powers0(env, v0169, v0202);
    nil = C_nil;
    if (exception_pending()) goto v0217;
    env = stack[-3];
    stack[-1] = stack[-2];
    stack[0] = v0202;
    goto v0097;

v0165:
    v0202 = stack[-1];
    v0202 = qcar(v0202);
    v0202 = qcar(v0202);
    v0073 = qcar(v0202);
    v0202 = stack[-1];
    v0202 = qcar(v0202);
    v0202 = qcar(v0202);
    v0169 = qcdr(v0202);
    v0202 = stack[0];
    v0202 = acons(v0073, v0169, v0202);
    nil = C_nil;
    if (exception_pending()) goto v0217;
    env = stack[-3];
    stack[0] = v0202;
    goto v0071;

v0082:
    v0202 = qvalue(elt(env, 1)); /* t */
    goto v0010;

v0013:
    v0202 = qvalue(elt(env, 1)); /* t */
    goto v0010;
/* error exit handlers */
v0217:
    popv(4);
    return nil;
}



/* Code for arrayp */

static Lisp_Object CC_arrayp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0015, v0016;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for arrayp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0015 = v0000;
/* end of prologue */
    if (!symbolp(v0015)) v0015 = nil;
    else { v0015 = qfastgets(v0015);
           if (v0015 != nil) { v0015 = elt(v0015, 2); /* rtype */
#ifdef RECORD_GET
             if (v0015 != SPID_NOPROP)
                record_get(elt(fastget_names, 2), 1);
             else record_get(elt(fastget_names, 2), 0),
                v0015 = nil; }
           else record_get(elt(fastget_names, 2), 0); }
#else
             if (v0015 == SPID_NOPROP) v0015 = nil; }}
#endif
    v0016 = elt(env, 1); /* array */
    v0015 = (v0015 == v0016 ? lisp_true : nil);
    return onevalue(v0015);
}



/* Code for remove!-free!-vars!-l */

static Lisp_Object CC_removeKfreeKvarsKl(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0057, v0186;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for remove-free-vars-l");
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
    stack[-1] = nil;
    stack[0] = nil;
    goto v0012;

v0012:
    v0057 = stack[-2];
    if (!consp(v0057)) goto v0024;
    v0057 = stack[-2];
    v0186 = qcar(v0057);
    v0057 = elt(env, 3); /* !*sq */
    if (v0186 == v0057) goto v0087;
    v0186 = stack[-2];
    v0057 = stack[-1];
    v0057 = cons(v0186, v0057);
    nil = C_nil;
    if (exception_pending()) goto v0076;
    env = stack[-4];
    stack[-1] = v0057;
    v0057 = stack[-2];
    v0057 = qcar(v0057);
    fn = elt(env, 4); /* remove!-free!-vars */
    v0186 = (*qfn1(fn))(qenv(fn), v0057);
    nil = C_nil;
    if (exception_pending()) goto v0076;
    env = stack[-4];
    v0057 = stack[-3];
    v0057 = cons(v0186, v0057);
    nil = C_nil;
    if (exception_pending()) goto v0076;
    env = stack[-4];
    stack[-3] = v0057;
    v0057 = stack[-2];
    v0057 = qcdr(v0057);
    stack[-2] = v0057;
    goto v0012;

v0087:
    v0057 = stack[-2];
    v0057 = qcdr(v0057);
    v0057 = qcar(v0057);
    fn = elt(env, 5); /* prepsq!* */
    v0057 = (*qfn1(fn))(qenv(fn), v0057);
    nil = C_nil;
    if (exception_pending()) goto v0076;
    env = stack[-4];
    stack[-2] = v0057;
    v0057 = qvalue(elt(env, 2)); /* t */
    stack[0] = v0057;
    goto v0012;

v0024:
    v0057 = stack[-3];
    if (v0057 == nil) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v0057 = stack[0];
    if (v0057 == nil) goto v0034;
    v0057 = stack[-3];
    v0186 = qcar(v0057);
    v0057 = stack[-2];
    v0057 = cons(v0186, v0057);
    nil = C_nil;
    if (exception_pending()) goto v0076;
    env = stack[-4];
    stack[-2] = v0057;
    goto v0040;

v0040:
    v0057 = stack[-1];
    v0057 = qcdr(v0057);
    stack[-1] = v0057;
    v0057 = stack[-3];
    v0057 = qcdr(v0057);
    stack[-3] = v0057;
    goto v0024;

v0034:
    v0057 = stack[-1];
    v0057 = qcar(v0057);
    v0186 = qcar(v0057);
    v0057 = stack[-3];
    v0057 = qcar(v0057);
    if (equal(v0186, v0057)) goto v0041;
    v0057 = stack[-3];
    v0186 = qcar(v0057);
    v0057 = stack[-2];
    v0057 = cons(v0186, v0057);
    nil = C_nil;
    if (exception_pending()) goto v0076;
    env = stack[-4];
    stack[-2] = v0057;
    v0057 = qvalue(elt(env, 2)); /* t */
    stack[0] = v0057;
    goto v0040;

v0041:
    v0057 = stack[-1];
    v0057 = qcar(v0057);
    stack[-2] = v0057;
    goto v0040;
/* error exit handlers */
v0076:
    popv(5);
    return nil;
}



/* Code for get!+vec!+dim */

static Lisp_Object CC_getLvecLdim(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0001;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for get+vec+dim");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0001 = v0000;
/* end of prologue */
        return Llength(nil, v0001);
}



/* Code for qqe_qopaddp */

static Lisp_Object CC_qqe_qopaddp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0024, v0037;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for qqe_qopaddp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0024 = v0000;
/* end of prologue */
    v0037 = v0024;
    v0024 = elt(env, 1); /* (ladd radd) */
    v0024 = Lmemq(nil, v0037, v0024);
    if (v0024 == nil) goto v0005;
    v0024 = qvalue(elt(env, 2)); /* t */
    return onevalue(v0024);

v0005:
    v0024 = nil;
    return onevalue(v0024);
}



/* Code for pasf_susitf */

static Lisp_Object CC_pasf_susitf(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0036)
{
    Lisp_Object v0006, v0005;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pasf_susitf");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0006 = v0036;
    v0005 = v0000;
/* end of prologue */
    return onevalue(v0005);
}



/* Code for delq */

static Lisp_Object CC_delq(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0036)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0180, v0009, v0060;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for delq");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0036,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0036);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0036;
    stack[-1] = v0000;
/* end of prologue */
    v0060 = nil;
    goto v0001;

v0001:
    v0180 = stack[0];
    if (v0180 == nil) goto v0007;
    v0180 = stack[0];
    v0009 = qcar(v0180);
    v0180 = stack[-1];
    if (v0009 == v0180) goto v0098;
    v0180 = stack[0];
    v0180 = qcar(v0180);
    v0009 = v0060;
    v0180 = cons(v0180, v0009);
    nil = C_nil;
    if (exception_pending()) goto v0023;
    env = stack[-2];
    v0060 = v0180;
    v0180 = stack[0];
    v0180 = qcdr(v0180);
    stack[0] = v0180;
    goto v0001;

v0098:
    v0009 = v0060;
    v0180 = stack[0];
    v0180 = qcdr(v0180);
    {
        popv(3);
        fn = elt(env, 1); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0009, v0180);
    }

v0007:
    v0180 = v0060;
    {
        popv(3);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v0180);
    }
/* error exit handlers */
v0023:
    popv(3);
    return nil;
}



/* Code for attributes */

static Lisp_Object CC_attributes(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0036)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0028, v0068;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for attributes");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0036,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0036);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0036;
    v0028 = v0000;
/* end of prologue */
    v0028 = Llength(nil, v0028);
    nil = C_nil;
    if (exception_pending()) goto v0093;
    env = stack[-3];
    stack[-2] = v0028;
    v0028 = (Lisp_Object)17; /* 1 */
    stack[0] = v0028;
    goto v0065;

v0065:
    v0068 = stack[-2];
    v0028 = stack[0];
    v0028 = difference2(v0068, v0028);
    nil = C_nil;
    if (exception_pending()) goto v0093;
    env = stack[-3];
    v0028 = Lminusp(nil, v0028);
    env = stack[-3];
    if (!(v0028 == nil)) goto v0003;
    v0028 = stack[-1];
    v0028 = qcdr(v0028);
    stack[-1] = v0028;
    v0028 = stack[0];
    v0028 = add1(v0028);
    nil = C_nil;
    if (exception_pending()) goto v0093;
    env = stack[-3];
    stack[0] = v0028;
    goto v0065;

v0003:
    v0028 = stack[-1];
    v0068 = qcar(v0028);
    v0028 = elt(env, 2); /* !  */
    if (v0068 == v0028) goto v0021;
    v0068 = stack[-1];
    v0028 = elt(env, 3); /* (!$) */
    if (equal(v0068, v0028)) goto v0180;
    v0028 = stack[-1];
    qvalue(elt(env, 4)) = v0028; /* atts */
    goto v0180;

v0180:
    v0028 = nil;
    { popv(4); return onevalue(v0028); }

v0021:
    v0028 = stack[-1];
    v0028 = qcdr(v0028);
    stack[-1] = v0028;
    goto v0003;
/* error exit handlers */
v0093:
    popv(4);
    return nil;
}



/* Code for c!:ordexn */

static Lisp_Object CC_cTordexn(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0036)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0053, v0055;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for c:ordexn");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0036,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0036);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0036;
    stack[-2] = v0000;
/* end of prologue */
    stack[0] = nil;
    stack[-3] = nil;
    goto v0012;

v0012:
    v0053 = stack[-1];
    if (v0053 == nil) goto v0084;
    v0055 = stack[-2];
    v0053 = stack[-1];
    v0053 = qcar(v0053);
    if (equal(v0055, v0053)) goto v0067;
    v0053 = stack[-2];
    v0053 = Lconsp(nil, v0053);
    env = stack[-4];
    if (v0053 == nil) goto v0018;
    v0053 = stack[-1];
    v0053 = qcar(v0053);
    v0053 = Lconsp(nil, v0053);
    env = stack[-4];
    goto v0110;

v0110:
    if (v0053 == nil) goto v0068;
    v0053 = qvalue(elt(env, 2)); /* nil */
    { popv(5); return onevalue(v0053); }

v0068:
    v0055 = stack[-2];
    v0053 = stack[-1];
    v0053 = qcar(v0053);
    fn = elt(env, 3); /* c!:ordxp */
    v0053 = (*qfn2(fn))(qenv(fn), v0055, v0053);
    nil = C_nil;
    if (exception_pending()) goto v0191;
    env = stack[-4];
    if (v0053 == nil) goto v0219;
    v0055 = stack[-2];
    v0053 = stack[-3];
    v0053 = cons(v0055, v0053);
    nil = C_nil;
    if (exception_pending()) goto v0191;
    env = stack[-4];
    v0055 = Lreverse(nil, v0053);
    nil = C_nil;
    if (exception_pending()) goto v0191;
    env = stack[-4];
    v0053 = stack[-1];
    v0053 = Lappend(nil, v0055, v0053);
    nil = C_nil;
    if (exception_pending()) goto v0191;
    {
        Lisp_Object v0161 = stack[0];
        popv(5);
        return cons(v0161, v0053);
    }

v0219:
    v0053 = stack[-1];
    v0055 = qcar(v0053);
    v0053 = stack[-3];
    v0053 = cons(v0055, v0053);
    nil = C_nil;
    if (exception_pending()) goto v0191;
    env = stack[-4];
    stack[-3] = v0053;
    v0053 = stack[-1];
    v0053 = qcdr(v0053);
    stack[-1] = v0053;
    v0053 = stack[0];
    v0053 = (v0053 == nil ? lisp_true : nil);
    stack[0] = v0053;
    goto v0012;

v0018:
    v0053 = qvalue(elt(env, 2)); /* nil */
    goto v0110;

v0067:
    v0053 = qvalue(elt(env, 1)); /* t */
    goto v0110;

v0084:
    v0055 = stack[-2];
    v0053 = stack[-3];
    v0053 = cons(v0055, v0053);
    nil = C_nil;
    if (exception_pending()) goto v0191;
    env = stack[-4];
    v0053 = Lreverse(nil, v0053);
    nil = C_nil;
    if (exception_pending()) goto v0191;
    {
        Lisp_Object v0209 = stack[0];
        popv(5);
        return cons(v0209, v0053);
    }
/* error exit handlers */
v0191:
    popv(5);
    return nil;
}



/* Code for bcprod */

static Lisp_Object CC_bcprod(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0036)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0085, v0030, v0062;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for bcprod");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0036,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0036);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0036;
    stack[-1] = v0000;
/* end of prologue */
    v0085 = qvalue(elt(env, 1)); /* !*grmod!* */
    if (v0085 == nil) goto v0040;
    v0030 = stack[-1];
    v0085 = stack[0];
    v0085 = times2(v0030, v0085);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    env = stack[-2];
    {
        popv(3);
        fn = elt(env, 3); /* bcfi */
        return (*qfn1(fn))(qenv(fn), v0085);
    }

v0040:
    v0062 = stack[-1];
    v0030 = stack[0];
    v0085 = elt(env, 2); /* times */
    fn = elt(env, 4); /* bcint2op */
    v0085 = (*qfnn(fn))(qenv(fn), 3, v0062, v0030, v0085);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    env = stack[-2];
    if (!(v0085 == nil)) { popv(3); return onevalue(v0085); }
    v0030 = stack[-1];
    v0085 = stack[0];
    fn = elt(env, 5); /* multsq */
    v0085 = (*qfn2(fn))(qenv(fn), v0030, v0085);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    env = stack[-2];
    {
        popv(3);
        fn = elt(env, 6); /* bccheckz */
        return (*qfn1(fn))(qenv(fn), v0085);
    }
/* error exit handlers */
v0094:
    popv(3);
    return nil;
}



/* Code for evmatrixcomp1 */

static Lisp_Object MS_CDECL CC_evmatrixcomp1(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0092, v0070, v0109;
    Lisp_Object fn;
    Lisp_Object v0029, v0036, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "evmatrixcomp1");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0036 = va_arg(aa, Lisp_Object);
    v0029 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for evmatrixcomp1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0029,v0036,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0036,v0029);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0029;
    stack[-2] = v0036;
    stack[-3] = v0000;
/* end of prologue */

v0097:
    v0092 = stack[-1];
    if (v0092 == nil) goto v0001;
    v0109 = stack[-3];
    v0092 = stack[-1];
    v0070 = qcar(v0092);
    v0092 = (Lisp_Object)1; /* 0 */
    fn = elt(env, 1); /* evmatrixcomp2 */
    stack[0] = (*qfnn(fn))(qenv(fn), 3, v0109, v0070, v0092);
    nil = C_nil;
    if (exception_pending()) goto v0165;
    env = stack[-5];
    v0109 = stack[-2];
    v0092 = stack[-1];
    v0070 = qcar(v0092);
    v0092 = (Lisp_Object)1; /* 0 */
    fn = elt(env, 1); /* evmatrixcomp2 */
    v0092 = (*qfnn(fn))(qenv(fn), 3, v0109, v0070, v0092);
    nil = C_nil;
    if (exception_pending()) goto v0165;
    env = stack[-5];
    stack[-4] = stack[0];
    stack[0] = v0092;
    v0070 = stack[-4];
    v0092 = stack[0];
    fn = elt(env, 2); /* iequal */
    v0092 = (*qfn2(fn))(qenv(fn), v0070, v0092);
    nil = C_nil;
    if (exception_pending()) goto v0165;
    env = stack[-5];
    if (v0092 == nil) goto v0032;
    v0109 = stack[-3];
    v0070 = stack[-2];
    v0092 = stack[-1];
    v0092 = qcdr(v0092);
    stack[-3] = v0109;
    stack[-2] = v0070;
    stack[-1] = v0092;
    goto v0097;

v0032:
    v0070 = stack[-4];
    v0092 = stack[0];
    if (((int32_t)(v0070)) > ((int32_t)(v0092))) goto v0068;
    v0092 = (Lisp_Object)-15; /* -1 */
    { popv(6); return onevalue(v0092); }

v0068:
    v0092 = (Lisp_Object)17; /* 1 */
    { popv(6); return onevalue(v0092); }

v0001:
    v0092 = (Lisp_Object)1; /* 0 */
    { popv(6); return onevalue(v0092); }
/* error exit handlers */
v0165:
    popv(6);
    return nil;
}



/* Code for multpfsq */

static Lisp_Object CC_multpfsq(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0036)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0180, v0009;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for multpfsq");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0036,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0036);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0036;
    stack[-2] = v0000;
/* end of prologue */
    stack[-3] = nil;
    goto v0001;

v0001:
    v0180 = stack[-2];
    if (v0180 == nil) goto v0008;
    v0180 = stack[-1];
    v0180 = qcar(v0180);
    v0180 = (v0180 == nil ? lisp_true : nil);
    goto v0016;

v0016:
    if (v0180 == nil) goto v0011;
    v0180 = stack[-3];
    {
        popv(5);
        fn = elt(env, 2); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v0180);
    }

v0011:
    v0180 = stack[-2];
    v0180 = qcar(v0180);
    stack[0] = qcar(v0180);
    v0180 = stack[-2];
    v0180 = qcar(v0180);
    v0009 = qcdr(v0180);
    v0180 = stack[-1];
    fn = elt(env, 3); /* multsq */
    v0009 = (*qfn2(fn))(qenv(fn), v0009, v0180);
    nil = C_nil;
    if (exception_pending()) goto v0104;
    env = stack[-4];
    v0180 = stack[-3];
    v0180 = acons(stack[0], v0009, v0180);
    nil = C_nil;
    if (exception_pending()) goto v0104;
    env = stack[-4];
    stack[-3] = v0180;
    v0180 = stack[-2];
    v0180 = qcdr(v0180);
    stack[-2] = v0180;
    goto v0001;

v0008:
    v0180 = qvalue(elt(env, 1)); /* t */
    goto v0016;
/* error exit handlers */
v0104:
    popv(5);
    return nil;
}



/* Code for order!: */

static Lisp_Object CC_orderT(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0067, v0038;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for order:");
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
    v0067 = stack[0];
    v0067 = qcdr(v0067);
    v0038 = qcar(v0067);
    v0067 = (Lisp_Object)1; /* 0 */
    if (v0038 == v0067) goto v0006;
    v0067 = stack[0];
    v0067 = qcdr(v0067);
    v0067 = qcar(v0067);
    v0067 = Labsval(nil, v0067);
    nil = C_nil;
    if (exception_pending()) goto v0002;
    env = stack[-2];
    fn = elt(env, 1); /* msd */
    stack[-1] = (*qfn1(fn))(qenv(fn), v0067);
    nil = C_nil;
    if (exception_pending()) goto v0002;
    env = stack[-2];
    v0067 = stack[0];
    v0067 = qcdr(v0067);
    v0067 = qcdr(v0067);
    v0067 = sub1(v0067);
    nil = C_nil;
    if (exception_pending()) goto v0002;
    {
        Lisp_Object v0003 = stack[-1];
        popv(3);
        return plus2(v0003, v0067);
    }

v0006:
    v0067 = (Lisp_Object)1; /* 0 */
    { popv(3); return onevalue(v0067); }
/* error exit handlers */
v0002:
    popv(3);
    return nil;
}



/* Code for !*collectphysops_reversed */

static Lisp_Object CC_Hcollectphysops_reversed(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0036)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0176, v0095;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for *collectphysops_reversed");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0036,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0036);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0036;
    stack[-1] = v0000;
/* end of prologue */
    v0176 = stack[-1];
    fn = elt(env, 2); /* physopp */
    v0176 = (*qfn1(fn))(qenv(fn), v0176);
    nil = C_nil;
    if (exception_pending()) goto v0062;
    env = stack[-2];
    if (v0176 == nil) goto v0083;
    v0095 = stack[-1];
    v0176 = stack[0];
    popv(3);
    return cons(v0095, v0176);

v0083:
    v0176 = stack[-1];
    if (!consp(v0176)) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v0176 = stack[-1];
    v0095 = qcar(v0176);
    v0176 = stack[0];
    v0176 = CC_Hcollectphysops_reversed(env, v0095, v0176);
    nil = C_nil;
    if (exception_pending()) goto v0062;
    env = stack[-2];
    stack[0] = v0176;
    v0176 = stack[-1];
    v0176 = qcdr(v0176);
    stack[-1] = v0176;
    goto v0083;
/* error exit handlers */
v0062:
    popv(3);
    return nil;
}



/* Code for mo!=modiv1 */

static Lisp_Object CC_moMmodiv1(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0036)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0031, v0176;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mo=modiv1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0036,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0036);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0036;
    stack[-1] = v0000;
/* end of prologue */

v0005:
    v0031 = stack[-1];
    if (v0031 == nil) goto v0010;
    v0031 = stack[0];
    if (v0031 == nil) goto v0016;
    v0031 = stack[-1];
    v0176 = qcar(v0031);
    v0031 = stack[0];
    v0031 = qcar(v0031);
    v0031 = (Lisp_Object)lesseq2(v0176, v0031);
    nil = C_nil;
    if (exception_pending()) goto v0030;
    v0031 = v0031 ? lisp_true : nil;
    env = stack[-2];
    if (v0031 == nil) goto v0020;
    v0031 = stack[-1];
    v0031 = qcdr(v0031);
    stack[-1] = v0031;
    v0031 = stack[0];
    v0031 = qcdr(v0031);
    stack[0] = v0031;
    goto v0005;

v0020:
    v0031 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v0031); }

v0016:
    v0031 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v0031); }

v0010:
    v0031 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v0031); }
/* error exit handlers */
v0030:
    popv(3);
    return nil;
}



/* Code for unpkp */

static Lisp_Object CC_unpkp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0220, v0187, v0221;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for unpkp");
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
    v0220 = stack[-1];
    if (!(!consp(v0220))) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v0220 = stack[-1];
    v0220 = Lexplode(nil, v0220);
    nil = C_nil;
    if (exception_pending()) goto v0144;
    env = stack[-3];
    stack[-1] = v0220;
    v0220 = stack[-1];
    v0187 = Llength(nil, v0220);
    nil = C_nil;
    if (exception_pending()) goto v0144;
    env = stack[-3];
    v0220 = (Lisp_Object)161; /* 10 */
    v0220 = (Lisp_Object)geq2(v0187, v0220);
    nil = C_nil;
    if (exception_pending()) goto v0144;
    v0220 = v0220 ? lisp_true : nil;
    env = stack[-3];
    stack[0] = v0220;
    v0220 = stack[0];
    if (v0220 == nil) goto v0062;
    v0220 = stack[-1];
    v0220 = Llength(nil, v0220);
    nil = C_nil;
    if (exception_pending()) goto v0144;
    env = stack[-3];
    v0220 = Levenp(nil, v0220);
    env = stack[-3];
    if (!(v0220 == nil)) goto v0062;
    v0187 = elt(env, 1); /* !0 */
    v0220 = stack[-1];
    v0220 = cons(v0187, v0220);
    nil = C_nil;
    if (exception_pending()) goto v0144;
    env = stack[-3];
    stack[-1] = v0220;
    goto v0062;

v0062:
    v0220 = stack[-1];
    if (v0220 == nil) goto v0030;
    v0220 = stack[0];
    if (v0220 == nil) goto v0053;
    v0220 = stack[-1];
    v0187 = qcar(v0220);
    v0220 = qvalue(elt(env, 3)); /* diglist!* */
    v0220 = Lassoc(nil, v0187, v0220);
    v0220 = qcdr(v0220);
    v0187 = v0220;
    v0220 = stack[-1];
    v0220 = qcdr(v0220);
    stack[-1] = v0220;
    v0220 = (Lisp_Object)161; /* 10 */
    v0221 = times2(v0187, v0220);
    nil = C_nil;
    if (exception_pending()) goto v0144;
    env = stack[-3];
    v0220 = stack[-1];
    v0187 = qcar(v0220);
    v0220 = qvalue(elt(env, 3)); /* diglist!* */
    v0220 = Lassoc(nil, v0187, v0220);
    v0220 = qcdr(v0220);
    v0187 = plus2(v0221, v0220);
    nil = C_nil;
    if (exception_pending()) goto v0144;
    env = stack[-3];
    v0220 = stack[-2];
    v0220 = cons(v0187, v0220);
    nil = C_nil;
    if (exception_pending()) goto v0144;
    env = stack[-3];
    stack[-2] = v0220;
    goto v0060;

v0060:
    v0220 = stack[-1];
    v0220 = qcdr(v0220);
    stack[-1] = v0220;
    goto v0062;

v0053:
    v0220 = stack[-1];
    v0187 = qcar(v0220);
    v0220 = qvalue(elt(env, 3)); /* diglist!* */
    v0220 = Lassoc(nil, v0187, v0220);
    v0187 = qcdr(v0220);
    v0220 = stack[-2];
    v0220 = cons(v0187, v0220);
    nil = C_nil;
    if (exception_pending()) goto v0144;
    env = stack[-3];
    stack[-2] = v0220;
    goto v0060;

v0030:
    v0220 = stack[-2];
        popv(4);
        return Lnreverse(nil, v0220);
/* error exit handlers */
v0144:
    popv(4);
    return nil;
}



/* Code for noncomp1 */

static Lisp_Object CC_noncomp1(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0085, v0030, v0062;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for noncomp1");
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
    v0030 = v0000;
/* end of prologue */
    v0085 = v0030;
    v0085 = Lconsp(nil, v0085);
    env = stack[0];
    if (v0085 == nil) goto v0006;
    v0085 = v0030;
    v0085 = qcar(v0085);
    v0085 = Lconsp(nil, v0085);
    env = stack[0];
    if (v0085 == nil) goto v0162;
    v0085 = v0030;
    {
        popv(1);
        fn = elt(env, 4); /* noncomfp */
        return (*qfn1(fn))(qenv(fn), v0085);
    }

v0162:
    v0085 = v0030;
    v0062 = qcar(v0085);
    v0085 = elt(env, 2); /* taylor!* */
    if (v0062 == v0085) goto v0037;
    v0085 = v0030;
    v0085 = qcar(v0085);
    if (!symbolp(v0085)) v0085 = nil;
    else { v0085 = qfastgets(v0085);
           if (v0085 != nil) { v0085 = elt(v0085, 0); /* noncom */
#ifdef RECORD_GET
             if (v0085 == SPID_NOPROP)
                record_get(elt(fastget_names, 0), 0),
                v0085 = nil;
             else record_get(elt(fastget_names, 0), 1),
                v0085 = lisp_true; }
           else record_get(elt(fastget_names, 0), 0); }
#else
             if (v0085 == SPID_NOPROP) v0085 = nil; else v0085 = lisp_true; }}
#endif
    if (v0085 == nil) goto v0002;
    v0085 = qvalue(elt(env, 3)); /* t */
    { popv(1); return onevalue(v0085); }

v0002:
    v0085 = v0030;
    v0085 = qcdr(v0085);
    {
        popv(1);
        fn = elt(env, 5); /* noncomlistp */
        return (*qfn1(fn))(qenv(fn), v0085);
    }

v0037:
    v0085 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v0085); }

v0006:
    v0085 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v0085); }
}



/* Code for lalr_same_core */

static Lisp_Object CC_lalr_same_core(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0036)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0008;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for lalr_same_core");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0036,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0036);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0036;
    v0008 = v0000;
/* end of prologue */
    fn = elt(env, 1); /* lalr_core */
    stack[-1] = (*qfn1(fn))(qenv(fn), v0008);
    nil = C_nil;
    if (exception_pending()) goto v0037;
    env = stack[-2];
    v0008 = stack[0];
    fn = elt(env, 1); /* lalr_core */
    v0008 = (*qfn1(fn))(qenv(fn), v0008);
    nil = C_nil;
    if (exception_pending()) goto v0037;
    v0008 = (equal(stack[-1], v0008) ? lisp_true : nil);
    { popv(3); return onevalue(v0008); }
/* error exit handlers */
v0037:
    popv(3);
    return nil;
}



/* Code for rl_smcpknowl */

static Lisp_Object CC_rl_smcpknowl(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0015;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rl_smcpknowl");
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
    v0015 = v0000;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* rl_smcpknowl!* */
    v0015 = ncons(v0015);
    nil = C_nil;
    if (exception_pending()) goto v0008;
    env = stack[-1];
    {
        Lisp_Object v0017 = stack[0];
        popv(2);
        fn = elt(env, 2); /* apply */
        return (*qfn2(fn))(qenv(fn), v0017, v0015);
    }
/* error exit handlers */
v0008:
    popv(2);
    return nil;
}



/* Code for symbollessp */

static Lisp_Object CC_symbollessp(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0036)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0021, v0020, v0002;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for symbollessp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0036,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0036);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0020 = v0036;
    v0002 = v0000;
/* end of prologue */
    v0021 = v0020;
    if (v0021 == nil) goto v0005;
    v0021 = v0002;
    if (v0021 == nil) goto v0013;
    v0021 = qvalue(elt(env, 3)); /* wukord!* */
    if (v0021 == nil) goto v0011;
    v0021 = v0002;
    {
        fn = elt(env, 4); /* wuorderp */
        return (*qfn2(fn))(qenv(fn), v0021, v0020);
    }

v0011:
    v0021 = v0002;
    v0021 = Lorderp(nil, v0021, v0020);
    errexit();
    v0021 = (v0021 == nil ? lisp_true : nil);
    return onevalue(v0021);

v0013:
    v0021 = qvalue(elt(env, 2)); /* t */
    return onevalue(v0021);

v0005:
    v0021 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v0021);
}



/* Code for rank */

static Lisp_Object CC_rank(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0057, v0186;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rank");
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
    v0057 = qvalue(elt(env, 1)); /* !*mcd */
    if (v0057 == nil) goto v0015;
    v0057 = stack[-2];
    v0057 = qcar(v0057);
    v0057 = qcar(v0057);
    v0057 = qcdr(v0057);
    { popv(5); return onevalue(v0057); }

v0015:
    v0057 = stack[-2];
    v0057 = qcar(v0057);
    v0057 = qcar(v0057);
    v0057 = qcdr(v0057);
    stack[-1] = v0057;
    v0057 = stack[-2];
    v0057 = qcar(v0057);
    v0057 = qcar(v0057);
    v0057 = qcar(v0057);
    stack[0] = v0057;
    goto v0162;

v0162:
    v0057 = stack[-2];
    v0057 = qcar(v0057);
    v0057 = qcar(v0057);
    v0057 = qcdr(v0057);
    stack[-3] = v0057;
    v0057 = stack[-2];
    v0057 = qcdr(v0057);
    if (v0057 == nil) goto v0176;
    v0057 = stack[-2];
    v0057 = qcdr(v0057);
    stack[-2] = v0057;
    v0186 = stack[-2];
    v0057 = stack[0];
    fn = elt(env, 2); /* degr */
    v0186 = (*qfn2(fn))(qenv(fn), v0186, v0057);
    nil = C_nil;
    if (exception_pending()) goto v0076;
    env = stack[-4];
    v0057 = (Lisp_Object)1; /* 0 */
    if (!(v0186 == v0057)) goto v0162;
    v0186 = stack[-3];
    v0057 = (Lisp_Object)1; /* 0 */
    v0057 = (Lisp_Object)lessp2(v0186, v0057);
    nil = C_nil;
    if (exception_pending()) goto v0076;
    v0057 = v0057 ? lisp_true : nil;
    env = stack[-4];
    if (v0057 == nil) { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }
    v0186 = stack[-1];
    v0057 = (Lisp_Object)1; /* 0 */
    v0057 = (Lisp_Object)lessp2(v0186, v0057);
    nil = C_nil;
    if (exception_pending()) goto v0076;
    v0057 = v0057 ? lisp_true : nil;
    if (v0057 == nil) goto v0219;
    v0057 = stack[-3];
    popv(5);
    return negate(v0057);

v0219:
    v0186 = stack[-1];
    v0057 = stack[-3];
    popv(5);
    return difference2(v0186, v0057);

v0176:
    v0186 = stack[-1];
    v0057 = stack[-3];
    popv(5);
    return difference2(v0186, v0057);
/* error exit handlers */
v0076:
    popv(5);
    return nil;
}



/* Code for sizchk */

static Lisp_Object CC_sizchk(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0036)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0085, v0030;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sizchk");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0036,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0036);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0036;
    stack[-1] = v0000;
/* end of prologue */
    stack[-2] = nil;
    goto v0001;

v0001:
    v0085 = stack[-1];
    if (v0085 == nil) goto v0013;
    v0085 = stack[-1];
    v0085 = qcar(v0085);
    v0085 = qcar(v0085);
    v0030 = Llength(nil, v0085);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    env = stack[-3];
    v0085 = stack[0];
    v0085 = (Lisp_Object)greaterp2(v0030, v0085);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    v0085 = v0085 ? lisp_true : nil;
    env = stack[-3];
    if (v0085 == nil) goto v0110;
    v0085 = stack[-1];
    v0085 = qcdr(v0085);
    stack[-1] = v0085;
    goto v0001;

v0110:
    v0085 = stack[-1];
    v0030 = qcar(v0085);
    v0085 = stack[-2];
    v0085 = cons(v0030, v0085);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    env = stack[-3];
    stack[-2] = v0085;
    v0085 = stack[-1];
    v0085 = qcdr(v0085);
    stack[-1] = v0085;
    goto v0001;

v0013:
    v0085 = stack[-2];
    {
        popv(4);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v0085);
    }
/* error exit handlers */
v0094:
    popv(4);
    return nil;
}



/* Code for gcdfd1 */

static Lisp_Object CC_gcdfd1(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0036)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0094, v0018;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for gcdfd1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0036,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0036);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v0036;
    v0094 = v0000;
/* end of prologue */

v0005:
    v0018 = stack[0];
    if (v0018 == nil) { popv(2); return onevalue(v0094); }
    v0018 = stack[0];
    if (!consp(v0018)) goto v0037;
    v0018 = stack[0];
    v0018 = qcar(v0018);
    v0018 = (consp(v0018) ? nil : lisp_true);
    goto v0024;

v0024:
    if (v0018 == nil) goto v0020;
    v0018 = v0094;
    v0094 = stack[0];
    {
        popv(2);
        fn = elt(env, 2); /* gcddd */
        return (*qfn2(fn))(qenv(fn), v0018, v0094);
    }

v0020:
    v0018 = v0094;
    v0094 = stack[0];
    v0094 = qcar(v0094);
    v0094 = qcdr(v0094);
    v0094 = CC_gcdfd1(env, v0018, v0094);
    nil = C_nil;
    if (exception_pending()) goto v0180;
    env = stack[-1];
    v0018 = stack[0];
    v0018 = qcdr(v0018);
    stack[0] = v0018;
    goto v0005;

v0037:
    v0018 = qvalue(elt(env, 1)); /* t */
    goto v0024;
/* error exit handlers */
v0180:
    popv(2);
    return nil;
}



setup_type const u02_setup[] =
{
    {"lalr_core",               CC_lalr_core,   too_many_1,    wrong_no_1},
    {"prin2x",                  CC_prin2x,      too_many_1,    wrong_no_1},
    {"rl_varlat",               CC_rl_varlat,   too_many_1,    wrong_no_1},
    {"minusf",                  CC_minusf,      too_many_1,    wrong_no_1},
    {"reorder",                 CC_reorder,     too_many_1,    wrong_no_1},
    {"aconc*",                  too_few_2,      CC_aconcH,     wrong_no_2},
    {"tayexp-lessp",            too_few_2,      CC_tayexpKlessp,wrong_no_2},
    {"get+row+nr",              CC_getLrowLnr,  too_many_1,    wrong_no_1},
    {"sfp",                     CC_sfp,         too_many_1,    wrong_no_1},
    {"ibalp_cequal",            too_few_2,      CC_ibalp_cequal,wrong_no_2},
    {"*q2a",                    CC_Hq2a,        too_many_1,    wrong_no_1},
    {":onep",                   CC_Tonep,       too_many_1,    wrong_no_1},
    {"buchvevdivides?",         too_few_2,      CC_buchvevdividesW,wrong_no_2},
    {"prepsqxx",                CC_prepsqxx,    too_many_1,    wrong_no_1},
    {"vevmtest?",               too_few_2,      CC_vevmtestW,  wrong_no_2},
    {"ordpp",                   too_few_2,      CC_ordpp,      wrong_no_2},
    {"sublistp",                too_few_2,      CC_sublistp,   wrong_no_2},
    {"collectindices_reversed", too_few_2,      CC_collectindices_reversed,wrong_no_2},
    {"reval_without_mod",       CC_reval_without_mod,too_many_1,wrong_no_1},
    {"ring_ecart",              CC_ring_ecart,  too_many_1,    wrong_no_1},
    {"reduce_pv",               too_few_2,      CC_reduce_pv,  wrong_no_2},
    {"delcp",                   CC_delcp,       too_many_1,    wrong_no_1},
    {"lalr_first",              CC_lalr_first,  too_many_1,    wrong_no_1},
    {"sfto_dcontentf",          CC_sfto_dcontentf,too_many_1,  wrong_no_1},
    {"finde",                   too_few_2,      CC_finde,      wrong_no_2},
    {"mchk",                    too_few_2,      CC_mchk,       wrong_no_2},
    {"get+vec+entry",           too_few_2,      CC_getLvecLentry,wrong_no_2},
    {"qqe_qoptailp",            CC_qqe_qoptailp,too_many_1,    wrong_no_1},
    {"ibalp_cec",               CC_ibalp_cec,   too_many_1,    wrong_no_1},
    {"get_token",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_get_token},
    {"csl_normbf",              CC_csl_normbf,  too_many_1,    wrong_no_1},
    {"xsimp",                   CC_xsimp,       too_many_1,    wrong_no_1},
    {"i2rd*",                   CC_i2rdH,       too_many_1,    wrong_no_1},
    {"addf",                    too_few_2,      CC_addf,       wrong_no_2},
    {"aeval*",                  CC_aevalH,      too_many_1,    wrong_no_1},
    {"adddm",                   too_few_2,      CC_adddm,      wrong_no_2},
    {"mo=sprod",                too_few_2,      CC_moMsprod,   wrong_no_2},
    {"sieve_pv",                too_few_2,      CC_sieve_pv,   wrong_no_2},
    {"general-modular-plus",    too_few_2,      CC_generalKmodularKplus,wrong_no_2},
    {"multiply-by-constant-mod-p",too_few_2,    CC_multiplyKbyKconstantKmodKp,wrong_no_2},
    {"list2wideid",             CC_list2wideid, too_many_1,    wrong_no_1},
    {"setcdr",                  too_few_2,      CC_setcdr,     wrong_no_2},
    {"comfac-to-poly",          CC_comfacKtoKpoly,too_many_1,  wrong_no_1},
    {"mtchk",                   too_few_2,      CC_mtchk,      wrong_no_2},
    {"quotsq",                  too_few_2,      CC_quotsq,     wrong_no_2},
    {"exptchksq",               CC_exptchksq,   too_many_1,    wrong_no_1},
    {"setcar",                  too_few_2,      CC_setcar,     wrong_no_2},
    {"aex_ctx",                 CC_aex_ctx,     too_many_1,    wrong_no_1},
    {"notstring",               CC_notstring,   too_many_1,    wrong_no_1},
    {"constp",                  CC_constp,      too_many_1,    wrong_no_1},
    {"bczero?",                 CC_bczeroW,     too_many_1,    wrong_no_1},
    {"fast-row-dim",            CC_fastKrowKdim,too_many_1,    wrong_no_1},
    {"makelist",                CC_makelist,    too_many_1,    wrong_no_1},
    {"sinitl",                  CC_sinitl,      too_many_1,    wrong_no_1},
    {"smemqlp",                 too_few_2,      CC_smemqlp,    wrong_no_2},
    {"angles-equal",            too_few_2,      CC_anglesKequal,wrong_no_2},
    {"negnumberchk",            CC_negnumberchk,too_many_1,    wrong_no_1},
    {"pappl0",                  too_few_2,      CC_pappl0,     wrong_no_2},
    {"rnonep:",                 CC_rnonepT,     too_many_1,    wrong_no_1},
    {"modtimes:",               too_few_2,      CC_modtimesT,  wrong_no_2},
    {"remainder-in-vector",     wrong_no_na,    wrong_no_nb,   (n_args *)CC_remainderKinKvector},
    {"lesspcar",                too_few_2,      CC_lesspcar,   wrong_no_2},
    {"cl_atmlc",                CC_cl_atmlc,    too_many_1,    wrong_no_1},
    {"monomclone",              CC_monomclone,  too_many_1,    wrong_no_1},
    {"powers0",                 too_few_2,      CC_powers0,    wrong_no_2},
    {"arrayp",                  CC_arrayp,      too_many_1,    wrong_no_1},
    {"remove-free-vars-l",      CC_removeKfreeKvarsKl,too_many_1,wrong_no_1},
    {"get+vec+dim",             CC_getLvecLdim, too_many_1,    wrong_no_1},
    {"qqe_qopaddp",             CC_qqe_qopaddp, too_many_1,    wrong_no_1},
    {"pasf_susitf",             too_few_2,      CC_pasf_susitf,wrong_no_2},
    {"delq",                    too_few_2,      CC_delq,       wrong_no_2},
    {"attributes",              too_few_2,      CC_attributes, wrong_no_2},
    {"c:ordexn",                too_few_2,      CC_cTordexn,   wrong_no_2},
    {"bcprod",                  too_few_2,      CC_bcprod,     wrong_no_2},
    {"evmatrixcomp1",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_evmatrixcomp1},
    {"multpfsq",                too_few_2,      CC_multpfsq,   wrong_no_2},
    {"order:",                  CC_orderT,      too_many_1,    wrong_no_1},
    {"*collectphysops_reversed",too_few_2,      CC_Hcollectphysops_reversed,wrong_no_2},
    {"mo=modiv1",               too_few_2,      CC_moMmodiv1,  wrong_no_2},
    {"unpkp",                   CC_unpkp,       too_many_1,    wrong_no_1},
    {"noncomp1",                CC_noncomp1,    too_many_1,    wrong_no_1},
    {"lalr_same_core",          too_few_2,      CC_lalr_same_core,wrong_no_2},
    {"rl_smcpknowl",            CC_rl_smcpknowl,too_many_1,    wrong_no_1},
    {"symbollessp",             too_few_2,      CC_symbollessp,wrong_no_2},
    {"rank",                    CC_rank,        too_many_1,    wrong_no_1},
    {"sizchk",                  too_few_2,      CC_sizchk,     wrong_no_2},
    {"gcdfd1",                  too_few_2,      CC_gcdfd1,     wrong_no_2},
    {NULL, (one_args *)"u02", (two_args *)"21842 8518287 4284156", 0}
};

/* end of generated code */
