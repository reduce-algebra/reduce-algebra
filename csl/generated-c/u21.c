
/* $destdir/u21.c        Machine generated C code */

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


/* Code for qqe_eta!-in!-term */

static Lisp_Object CC_qqe_etaKinKterm(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0007, v0008;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for qqe_eta-in-term");
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
    v0007 = qvalue(elt(env, 1)); /* nil */
    stack[-1] = v0007;
    v0007 = stack[0];
    if (!consp(v0007)) goto v0009;
    v0007 = stack[0];
    fn = elt(env, 3); /* qqe_op */
    v0008 = (*qfn1(fn))(qenv(fn), v0007);
    nil = C_nil;
    if (exception_pending()) goto v0010;
    env = stack[-2];
    v0007 = elt(env, 2); /* (lhead rhead) */
    v0007 = Lmemq(nil, v0008, v0007);
    if (v0007 == nil) goto v0011;
    v0007 = stack[0];
    {
        popv(3);
        fn = elt(env, 4); /* qqe_eta!-in!-term1 */
        return (*qfn1(fn))(qenv(fn), v0007);
    }

v0011:
    v0007 = stack[0];
    v0007 = qcdr(v0007);
    stack[0] = v0007;
    goto v0012;

v0012:
    v0007 = stack[0];
    if (v0007 == nil) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v0007 = stack[-1];
    if (!(v0007 == nil)) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v0007 = stack[0];
    v0007 = qcar(v0007);
    if (!consp(v0007)) goto v0013;
    v0007 = stack[0];
    v0007 = qcar(v0007);
    fn = elt(env, 3); /* qqe_op */
    v0008 = (*qfn1(fn))(qenv(fn), v0007);
    nil = C_nil;
    if (exception_pending()) goto v0010;
    env = stack[-2];
    v0007 = elt(env, 2); /* (lhead rhead) */
    v0007 = Lmemq(nil, v0008, v0007);
    if (v0007 == nil) goto v0014;
    v0007 = stack[0];
    v0007 = qcar(v0007);
    fn = elt(env, 4); /* qqe_eta!-in!-term1 */
    v0007 = (*qfn1(fn))(qenv(fn), v0007);
    nil = C_nil;
    if (exception_pending()) goto v0010;
    env = stack[-2];
    stack[-1] = v0007;
    goto v0013;

v0013:
    v0007 = stack[0];
    v0007 = qcdr(v0007);
    stack[0] = v0007;
    goto v0012;

v0014:
    v0007 = stack[0];
    v0007 = qcar(v0007);
    v0007 = CC_qqe_etaKinKterm(env, v0007);
    nil = C_nil;
    if (exception_pending()) goto v0010;
    env = stack[-2];
    stack[-1] = v0007;
    goto v0013;

v0009:
    v0007 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v0007); }
/* error exit handlers */
v0010:
    popv(3);
    return nil;
}



/* Code for ibalp_negatet */

static Lisp_Object CC_ibalp_negatet(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0019, v0020, v0021;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ibalp_negatet");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0021 = v0000;
/* end of prologue */
    v0020 = v0021;
    v0019 = (Lisp_Object)1; /* 0 */
    if (v0020 == v0019) goto v0022;
    v0020 = v0021;
    v0019 = (Lisp_Object)17; /* 1 */
    if (v0020 == v0019) goto v0023;
    v0019 = elt(env, 1); /* bnot */
    v0020 = v0021;
    return list2(v0019, v0020);

v0023:
    v0019 = (Lisp_Object)1; /* 0 */
    return onevalue(v0019);

v0022:
    v0019 = (Lisp_Object)17; /* 1 */
    return onevalue(v0019);
}



/* Code for sfto_dprpartksf */

static Lisp_Object CC_sfto_dprpartksf(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0018;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sfto_dprpartksf");
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
    v0018 = v0000;
/* end of prologue */
    stack[0] = v0018;
    fn = elt(env, 1); /* sfto_dcontentf */
    v0018 = (*qfn1(fn))(qenv(fn), v0018);
    nil = C_nil;
    if (exception_pending()) goto v0025;
    env = stack[-1];
    {
        Lisp_Object v0023 = stack[0];
        popv(2);
        fn = elt(env, 2); /* quotf */
        return (*qfn2(fn))(qenv(fn), v0023, v0018);
    }
/* error exit handlers */
v0025:
    popv(2);
    return nil;
}



/* Code for !*!*a2s */

static Lisp_Object CC_HHa2s(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0026)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0042, v0043;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for **a2s");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0026,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0026);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    v0042 = v0026;
    stack[-3] = v0000;
/* end of prologue */
    v0042 = stack[-3];
    if (v0042 == nil) goto v0044;
    v0043 = stack[-3];
    v0042 = elt(env, 2); /* nochange */
    v0042 = Lflagpcar(nil, v0043, v0042);
    env = stack[-5];
    if (v0042 == nil) goto v0019;
    v0042 = stack[-3];
    v0043 = qcar(v0042);
    v0042 = elt(env, 3); /* getel */
    if (!(v0043 == v0042)) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }

v0019:
    v0043 = elt(env, 4); /* random */
    v0042 = stack[-3];
    fn = elt(env, 11); /* smember */
    v0042 = (*qfn2(fn))(qenv(fn), v0043, v0042);
    nil = C_nil;
    if (exception_pending()) goto v0045;
    env = stack[-5];
    if (v0042 == nil) goto v0046;
    stack[-4] = elt(env, 5); /* lambda */
    stack[-2] = elt(env, 6); /* (!*uncached) */
    stack[-1] = elt(env, 7); /* progn */
    stack[0] = elt(env, 8); /* (declare (special !*uncached)) */
    v0043 = qvalue(elt(env, 9)); /* !*!*a2sfn */
    v0042 = stack[-3];
    v0042 = list2(v0043, v0042);
    nil = C_nil;
    if (exception_pending()) goto v0045;
    env = stack[-5];
    v0042 = list3(stack[-1], stack[0], v0042);
    nil = C_nil;
    if (exception_pending()) goto v0045;
    env = stack[-5];
    v0042 = list3(stack[-4], stack[-2], v0042);
    nil = C_nil;
    if (exception_pending()) goto v0045;
    env = stack[-5];
    v0043 = qvalue(elt(env, 10)); /* t */
    popv(6);
    return list2(v0042, v0043);

v0046:
    v0043 = qvalue(elt(env, 9)); /* !*!*a2sfn */
    v0042 = stack[-3];
    popv(6);
    return list2(v0043, v0042);

v0044:
    v0042 = elt(env, 1); /* "tell Hearn!!" */
    {
        popv(6);
        fn = elt(env, 12); /* rederr */
        return (*qfn1(fn))(qenv(fn), v0042);
    }
/* error exit handlers */
v0045:
    popv(6);
    return nil;
}



/* Code for diffsq */

static Lisp_Object CC_diffsq(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0026)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0053, v0054;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for diffsq");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0026,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0026);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0026;
    stack[-2] = v0000;
/* end of prologue */
    v0053 = stack[-2];
    v0054 = qcar(v0053);
    v0053 = stack[-1];
    fn = elt(env, 1); /* difff */
    stack[-3] = (*qfn2(fn))(qenv(fn), v0054, v0053);
    nil = C_nil;
    if (exception_pending()) goto v0031;
    env = stack[-4];
    stack[0] = stack[-2];
    v0053 = stack[-2];
    v0054 = qcdr(v0053);
    v0053 = stack[-1];
    fn = elt(env, 1); /* difff */
    v0053 = (*qfn2(fn))(qenv(fn), v0054, v0053);
    nil = C_nil;
    if (exception_pending()) goto v0031;
    env = stack[-4];
    fn = elt(env, 2); /* multsq */
    v0053 = (*qfn2(fn))(qenv(fn), stack[0], v0053);
    nil = C_nil;
    if (exception_pending()) goto v0031;
    env = stack[-4];
    fn = elt(env, 3); /* negsq */
    v0053 = (*qfn1(fn))(qenv(fn), v0053);
    nil = C_nil;
    if (exception_pending()) goto v0031;
    env = stack[-4];
    fn = elt(env, 4); /* addsq */
    stack[0] = (*qfn2(fn))(qenv(fn), stack[-3], v0053);
    nil = C_nil;
    if (exception_pending()) goto v0031;
    env = stack[-4];
    v0054 = (Lisp_Object)17; /* 1 */
    v0053 = stack[-2];
    v0053 = qcdr(v0053);
    v0053 = cons(v0054, v0053);
    nil = C_nil;
    if (exception_pending()) goto v0031;
    env = stack[-4];
    {
        Lisp_Object v0002 = stack[0];
        popv(5);
        fn = elt(env, 2); /* multsq */
        return (*qfn2(fn))(qenv(fn), v0002, v0053);
    }
/* error exit handlers */
v0031:
    popv(5);
    return nil;
}



/* Code for evdif */

static Lisp_Object CC_evdif(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0026)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0054, v0057, v0058;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for evdif");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0026,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0026);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0026;
    stack[-1] = v0000;
/* end of prologue */
    v0058 = nil;
    goto v0024;

v0024:
    v0054 = stack[0];
    if (v0054 == nil) goto v0013;
    v0054 = stack[-1];
    if (!(v0054 == nil)) goto v0059;
    v0054 = elt(env, 2); /* (0) */
    stack[-1] = v0054;
    goto v0059;

v0059:
    v0054 = stack[-1];
    v0057 = qcar(v0054);
    v0054 = stack[0];
    v0054 = qcar(v0054);
    v0054 = (Lisp_Object)(int32_t)((int32_t)v0057 - (int32_t)v0054 + TAG_FIXNUM);
    v0057 = v0058;
    v0054 = cons(v0054, v0057);
    nil = C_nil;
    if (exception_pending()) goto v0031;
    env = stack[-2];
    v0058 = v0054;
    v0054 = stack[-1];
    v0054 = qcdr(v0054);
    stack[-1] = v0054;
    v0054 = stack[0];
    v0054 = qcdr(v0054);
    stack[0] = v0054;
    goto v0024;

v0013:
    v0054 = v0058;
    v0057 = Lnreverse(nil, v0054);
    v0054 = stack[-1];
        popv(3);
        return Lnconc(nil, v0057, v0054);
/* error exit handlers */
v0031:
    popv(3);
    return nil;
}



/* Code for arg2of2 */

static Lisp_Object CC_arg2of2(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0026)
{
    Lisp_Object v0022, v0044;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for arg2of2");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0022 = v0026;
    v0044 = v0000;
/* end of prologue */
    return onevalue(v0022);
}



/* Code for wedgek2 */

static Lisp_Object MS_CDECL CC_wedgek2(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0100, v0101, v0102;
    Lisp_Object fn;
    Lisp_Object v0004, v0026, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "wedgek2");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0026 = va_arg(aa, Lisp_Object);
    v0004 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for wedgek2");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0004,v0026,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0026,v0004);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-2] = v0004;
    stack[-3] = v0026;
    stack[-4] = v0000;
/* end of prologue */

v0049:
    v0101 = stack[-4];
    v0100 = stack[-3];
    v0100 = qcar(v0100);
    if (v0101 == v0100) goto v0050;
    v0100 = qvalue(elt(env, 2)); /* nil */
    goto v0017;

v0017:
    if (v0100 == nil) goto v0007;
    v0100 = stack[-4];
    fn = elt(env, 3); /* deg!*form */
    v0100 = (*qfn1(fn))(qenv(fn), v0100);
    nil = C_nil;
    if (exception_pending()) goto v0103;
    env = stack[-6];
    v0101 = v0100;
    v0100 = v0101;
    v0100 = integerp(v0100);
    if (v0100 == nil) goto v0104;
    v0100 = v0101;
    v0100 = Loddp(nil, v0100);
    nil = C_nil;
    if (exception_pending()) goto v0103;
    env = stack[-6];
    goto v0013;

v0013:
    if (v0100 == nil) goto v0105;
    v0100 = qvalue(elt(env, 2)); /* nil */
    { popv(7); return onevalue(v0100); }

v0105:
    v0101 = stack[-4];
    v0100 = stack[-3];
    v0100 = cons(v0101, v0100);
    nil = C_nil;
    if (exception_pending()) goto v0103;
    env = stack[-6];
    fn = elt(env, 4); /* wedgef */
    stack[0] = (*qfn1(fn))(qenv(fn), v0100);
    nil = C_nil;
    if (exception_pending()) goto v0103;
    env = stack[-6];
    v0100 = stack[-2];
    fn = elt(env, 5); /* mksgnsq */
    v0100 = (*qfn1(fn))(qenv(fn), v0100);
    nil = C_nil;
    if (exception_pending()) goto v0103;
    env = stack[-6];
    {
        Lisp_Object v0106 = stack[0];
        popv(7);
        fn = elt(env, 6); /* multpfsq */
        return (*qfn2(fn))(qenv(fn), v0106, v0100);
    }

v0104:
    v0100 = qvalue(elt(env, 2)); /* nil */
    goto v0013;

v0007:
    v0100 = stack[-3];
    v0101 = qcar(v0100);
    v0100 = elt(env, 1); /* wedge */
    if (!consp(v0101)) goto v0107;
    v0101 = qcar(v0101);
    if (!(v0101 == v0100)) goto v0107;
    v0100 = stack[-3];
    v0100 = qcar(v0100);
    v0100 = qcdr(v0100);
    stack[-3] = v0100;
    goto v0049;

v0107:
    v0101 = stack[-4];
    v0100 = elt(env, 1); /* wedge */
    if (!consp(v0101)) goto v0108;
    v0101 = qcar(v0101);
    if (!(v0101 == v0100)) goto v0108;
    v0100 = stack[-4];
    v0101 = qcdr(v0100);
    v0100 = stack[-3];
    fn = elt(env, 7); /* wedgewedge */
    stack[0] = (*qfn2(fn))(qenv(fn), v0101, v0100);
    nil = C_nil;
    if (exception_pending()) goto v0103;
    env = stack[-6];
    v0100 = stack[-2];
    fn = elt(env, 5); /* mksgnsq */
    v0100 = (*qfn1(fn))(qenv(fn), v0100);
    nil = C_nil;
    if (exception_pending()) goto v0103;
    env = stack[-6];
    {
        Lisp_Object v0109 = stack[0];
        popv(7);
        fn = elt(env, 6); /* multpfsq */
        return (*qfn2(fn))(qenv(fn), v0109, v0100);
    }

v0108:
    v0101 = stack[-4];
    v0100 = stack[-3];
    v0100 = qcar(v0100);
    fn = elt(env, 8); /* worderp */
    v0100 = (*qfn2(fn))(qenv(fn), v0101, v0100);
    nil = C_nil;
    if (exception_pending()) goto v0103;
    env = stack[-6];
    if (v0100 == nil) goto v0110;
    v0101 = stack[-4];
    v0100 = stack[-3];
    v0100 = cons(v0101, v0100);
    nil = C_nil;
    if (exception_pending()) goto v0103;
    env = stack[-6];
    fn = elt(env, 4); /* wedgef */
    stack[0] = (*qfn1(fn))(qenv(fn), v0100);
    nil = C_nil;
    if (exception_pending()) goto v0103;
    env = stack[-6];
    v0100 = stack[-2];
    fn = elt(env, 5); /* mksgnsq */
    v0100 = (*qfn1(fn))(qenv(fn), v0100);
    nil = C_nil;
    if (exception_pending()) goto v0103;
    env = stack[-6];
    {
        Lisp_Object v0111 = stack[0];
        popv(7);
        fn = elt(env, 6); /* multpfsq */
        return (*qfn2(fn))(qenv(fn), v0111, v0100);
    }

v0110:
    v0100 = stack[-3];
    v0100 = qcdr(v0100);
    if (v0100 == nil) goto v0112;
    v0100 = stack[-3];
    v0102 = qcar(v0100);
    v0101 = (Lisp_Object)17; /* 1 */
    v0100 = (Lisp_Object)17; /* 1 */
    v0100 = list2star(v0102, v0101, v0100);
    nil = C_nil;
    if (exception_pending()) goto v0103;
    env = stack[-6];
    stack[-5] = ncons(v0100);
    nil = C_nil;
    if (exception_pending()) goto v0103;
    env = stack[-6];
    stack[-1] = stack[-4];
    v0100 = stack[-3];
    stack[0] = qcdr(v0100);
    v0100 = stack[-4];
    fn = elt(env, 3); /* deg!*form */
    stack[-4] = (*qfn1(fn))(qenv(fn), v0100);
    nil = C_nil;
    if (exception_pending()) goto v0103;
    env = stack[-6];
    v0100 = stack[-3];
    v0100 = qcar(v0100);
    fn = elt(env, 3); /* deg!*form */
    v0100 = (*qfn1(fn))(qenv(fn), v0100);
    nil = C_nil;
    if (exception_pending()) goto v0103;
    env = stack[-6];
    fn = elt(env, 9); /* multf */
    v0100 = (*qfn2(fn))(qenv(fn), stack[-4], v0100);
    nil = C_nil;
    if (exception_pending()) goto v0103;
    env = stack[-6];
    fn = elt(env, 10); /* addf */
    v0100 = (*qfn2(fn))(qenv(fn), stack[-2], v0100);
    nil = C_nil;
    if (exception_pending()) goto v0103;
    env = stack[-6];
    v0100 = CC_wedgek2(env, 3, stack[-1], stack[0], v0100);
    nil = C_nil;
    if (exception_pending()) goto v0103;
    env = stack[-6];
    {
        Lisp_Object v0113 = stack[-5];
        popv(7);
        fn = elt(env, 11); /* wedgepf2 */
        return (*qfn2(fn))(qenv(fn), v0113, v0100);
    }

v0112:
    v0100 = stack[-3];
    v0101 = qcar(v0100);
    v0100 = stack[-4];
    v0100 = list2(v0101, v0100);
    nil = C_nil;
    if (exception_pending()) goto v0103;
    env = stack[-6];
    fn = elt(env, 4); /* wedgef */
    stack[0] = (*qfn1(fn))(qenv(fn), v0100);
    nil = C_nil;
    if (exception_pending()) goto v0103;
    env = stack[-6];
    stack[-1] = stack[-2];
    v0100 = stack[-4];
    fn = elt(env, 3); /* deg!*form */
    stack[-2] = (*qfn1(fn))(qenv(fn), v0100);
    nil = C_nil;
    if (exception_pending()) goto v0103;
    env = stack[-6];
    v0100 = stack[-3];
    v0100 = qcar(v0100);
    fn = elt(env, 3); /* deg!*form */
    v0100 = (*qfn1(fn))(qenv(fn), v0100);
    nil = C_nil;
    if (exception_pending()) goto v0103;
    env = stack[-6];
    fn = elt(env, 9); /* multf */
    v0100 = (*qfn2(fn))(qenv(fn), stack[-2], v0100);
    nil = C_nil;
    if (exception_pending()) goto v0103;
    env = stack[-6];
    fn = elt(env, 10); /* addf */
    v0100 = (*qfn2(fn))(qenv(fn), stack[-1], v0100);
    nil = C_nil;
    if (exception_pending()) goto v0103;
    env = stack[-6];
    fn = elt(env, 5); /* mksgnsq */
    v0100 = (*qfn1(fn))(qenv(fn), v0100);
    nil = C_nil;
    if (exception_pending()) goto v0103;
    env = stack[-6];
    {
        Lisp_Object v0114 = stack[0];
        popv(7);
        fn = elt(env, 6); /* multpfsq */
        return (*qfn2(fn))(qenv(fn), v0114, v0100);
    }

v0050:
    v0101 = stack[-4];
    v0100 = elt(env, 1); /* wedge */
    v0100 = Leqcar(nil, v0101, v0100);
    env = stack[-6];
    v0100 = (v0100 == nil ? lisp_true : nil);
    goto v0017;
/* error exit handlers */
v0103:
    popv(7);
    return nil;
}



/* Code for one!-entry!-listp */

static Lisp_Object CC_oneKentryKlistp(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0026)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0021, v0056;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for one-entry-listp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0026,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0026);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0026;
    stack[-1] = v0000;
/* end of prologue */

v0115:
    v0021 = stack[-1];
    if (v0021 == nil) goto v0044;
    v0021 = stack[-1];
    v0056 = qcar(v0021);
    v0021 = stack[0];
    fn = elt(env, 3); /* one!-entryp */
    v0021 = (*qfn2(fn))(qenv(fn), v0056, v0021);
    nil = C_nil;
    if (exception_pending()) goto v0038;
    env = stack[-2];
    if (v0021 == nil) goto v0025;
    v0021 = stack[-1];
    v0056 = qcdr(v0021);
    v0021 = stack[0];
    stack[-1] = v0056;
    stack[0] = v0021;
    goto v0115;

v0025:
    v0021 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v0021); }

v0044:
    v0021 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v0021); }
/* error exit handlers */
v0038:
    popv(3);
    return nil;
}



/* Code for prepd1 */

static Lisp_Object CC_prepd1(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0011, v0059, v0040;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for prepd1");
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
    v0040 = v0000;
/* end of prologue */
    v0011 = v0040;
    if (!consp(v0011)) return onevalue(v0040);
    v0011 = v0040;
    v0059 = qcar(v0011);
    v0011 = elt(env, 1); /* prepfn */
    v0011 = get(v0059, v0011);
    v0059 = v0040;
        return Lapply1(nil, v0011, v0059);
}



/* Code for gcref_mkgraph!-tgf */

static Lisp_Object CC_gcref_mkgraphKtgf(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0118, v0032;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for gcref_mkgraph-tgf");
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
    v0118 = stack[0];
    stack[-1] = v0118;
    goto v0044;

v0044:
    v0118 = stack[-1];
    if (v0118 == nil) goto v0022;
    v0118 = stack[-1];
    v0118 = qcar(v0118);
    fn = elt(env, 4); /* gcref_mknode!-tgf */
    v0118 = (*qfn1(fn))(qenv(fn), v0118);
    nil = C_nil;
    if (exception_pending()) goto v0119;
    env = stack[-2];
    v0118 = stack[-1];
    v0118 = qcdr(v0118);
    stack[-1] = v0118;
    goto v0044;

v0022:
    v0118 = elt(env, 2); /* "#" */
    fn = elt(env, 5); /* prin2t */
    v0118 = (*qfn1(fn))(qenv(fn), v0118);
    nil = C_nil;
    if (exception_pending()) goto v0119;
    env = stack[-2];
    v0118 = stack[0];
    stack[-1] = v0118;
    goto v0116;

v0116:
    v0118 = stack[-1];
    if (v0118 == nil) goto v0039;
    v0118 = stack[-1];
    v0118 = qcar(v0118);
    stack[0] = v0118;
    v0032 = v0118;
    v0118 = elt(env, 3); /* calls */
    v0118 = get(v0032, v0118);
    env = stack[-2];
    fn = elt(env, 6); /* gcref_select */
    v0118 = (*qfn1(fn))(qenv(fn), v0118);
    nil = C_nil;
    if (exception_pending()) goto v0119;
    env = stack[-2];
    fn = elt(env, 7); /* gcref_mkedges!-tgf */
    v0118 = (*qfn2(fn))(qenv(fn), stack[0], v0118);
    nil = C_nil;
    if (exception_pending()) goto v0119;
    env = stack[-2];
    v0118 = stack[-1];
    v0118 = qcdr(v0118);
    stack[-1] = v0118;
    goto v0116;

v0039:
    v0118 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v0118); }
/* error exit handlers */
v0119:
    popv(3);
    return nil;
}



/* Code for mkpartitions1 */

static Lisp_Object MS_CDECL CC_mkpartitions1(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0130, v0131, v0132, v0080;
    Lisp_Object v0044, v0022, v0001, v0004, v0026, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 6, "mkpartitions1");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0026 = va_arg(aa, Lisp_Object);
    v0004 = va_arg(aa, Lisp_Object);
    v0001 = va_arg(aa, Lisp_Object);
    v0022 = va_arg(aa, Lisp_Object);
    v0044 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mkpartitions1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push6(v0044,v0022,v0001,v0004,v0026,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop6(v0000,v0026,v0004,v0001,v0022,v0044);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-3] = v0044;
    stack[-4] = v0022;
    stack[-5] = v0001;
    stack[-6] = v0004;
    stack[-7] = v0026;
    stack[-8] = v0000;
/* end of prologue */

v0133:
    v0131 = stack[-7];
    v0130 = (Lisp_Object)17; /* 1 */
    if (v0131 == v0130) goto v0099;
    v0131 = stack[-6];
    v0130 = stack[-5];
    v0130 = (Lisp_Object)greaterp2(v0131, v0130);
    nil = C_nil;
    if (exception_pending()) goto v0134;
    v0130 = v0130 ? lisp_true : nil;
    env = stack[-10];
    if (!(v0130 == nil)) { Lisp_Object res = stack[-3]; popv(11); return onevalue(res); }
    v0131 = stack[-8];
    v0130 = stack[-6];
    v0130 = difference2(v0131, v0130);
    nil = C_nil;
    if (exception_pending()) goto v0134;
    env = stack[-10];
    stack[-9] = v0130;
    v0130 = stack[-7];
    v0130 = sub1(v0130);
    nil = C_nil;
    if (exception_pending()) goto v0134;
    env = stack[-10];
    stack[-2] = v0130;
    v0131 = stack[-8];
    v0130 = stack[-6];
    stack[0] = difference2(v0131, v0130);
    nil = C_nil;
    if (exception_pending()) goto v0134;
    env = stack[-10];
    v0130 = stack[-7];
    v0130 = sub1(v0130);
    nil = C_nil;
    if (exception_pending()) goto v0134;
    env = stack[-10];
    v0130 = quot2(stack[0], v0130);
    nil = C_nil;
    if (exception_pending()) goto v0134;
    env = stack[-10];
    stack[-1] = v0130;
    v0131 = stack[-6];
    v0130 = stack[-4];
    v0130 = cons(v0131, v0130);
    nil = C_nil;
    if (exception_pending()) goto v0134;
    env = stack[-10];
    stack[0] = v0130;
    v0130 = stack[-6];
    v0080 = add1(v0130);
    nil = C_nil;
    if (exception_pending()) goto v0134;
    env = stack[-10];
    v0132 = stack[-5];
    v0131 = stack[-4];
    v0130 = stack[-3];
    v0130 = CC_mkpartitions1(env, 6, stack[-8], stack[-7], v0080, v0132, v0131, v0130);
    nil = C_nil;
    if (exception_pending()) goto v0134;
    env = stack[-10];
    stack[-3] = v0130;
    v0130 = stack[0];
    stack[-4] = v0130;
    v0130 = stack[-1];
    stack[-5] = v0130;
    v0130 = stack[-2];
    stack[-7] = v0130;
    v0130 = stack[-9];
    stack[-8] = v0130;
    goto v0133;

v0099:
    v0131 = stack[-8];
    v0130 = stack[-6];
    v0130 = (Lisp_Object)geq2(v0131, v0130);
    nil = C_nil;
    if (exception_pending()) goto v0134;
    v0130 = v0130 ? lisp_true : nil;
    env = stack[-10];
    if (v0130 == nil) { Lisp_Object res = stack[-3]; popv(11); return onevalue(res); }
    v0131 = stack[-8];
    v0130 = stack[-4];
    v0130 = cons(v0131, v0130);
    nil = C_nil;
    if (exception_pending()) goto v0134;
    env = stack[-10];
    v0131 = Lreverse(nil, v0130);
    nil = C_nil;
    if (exception_pending()) goto v0134;
    v0130 = stack[-3];
    popv(11);
    return cons(v0131, v0130);
/* error exit handlers */
v0134:
    popv(11);
    return nil;
}



/* Code for ofsf_subf */

static Lisp_Object MS_CDECL CC_ofsf_subf(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0132, v0080, v0141;
    Lisp_Object fn;
    Lisp_Object v0004, v0026, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "ofsf_subf");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0026 = va_arg(aa, Lisp_Object);
    v0004 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ofsf_subf");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0004,v0026,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0026,v0004);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0004;
    stack[-1] = v0026;
    stack[-2] = v0000;
/* end of prologue */
    v0132 = stack[-2];
    if (!consp(v0132)) goto v0025;
    v0132 = stack[-2];
    v0132 = qcar(v0132);
    v0132 = (consp(v0132) ? nil : lisp_true);
    goto v0017;

v0017:
    if (v0132 == nil) goto v0051;
    v0080 = stack[-2];
    v0132 = (Lisp_Object)17; /* 1 */
    popv(5);
    return cons(v0080, v0132);

v0051:
    v0132 = stack[-2];
    v0141 = qcdr(v0132);
    v0080 = stack[-1];
    v0132 = stack[0];
    v0132 = CC_ofsf_subf(env, 3, v0141, v0080, v0132);
    nil = C_nil;
    if (exception_pending()) goto v0142;
    env = stack[-4];
    stack[-3] = v0132;
    v0132 = stack[-2];
    v0132 = qcar(v0132);
    v0132 = qcar(v0132);
    v0080 = qcar(v0132);
    v0132 = stack[-1];
    if (v0080 == v0132) goto v0096;
    v0132 = stack[-2];
    v0132 = qcar(v0132);
    v0141 = qcdr(v0132);
    v0080 = stack[-1];
    v0132 = stack[0];
    stack[0] = CC_ofsf_subf(env, 3, v0141, v0080, v0132);
    nil = C_nil;
    if (exception_pending()) goto v0142;
    env = stack[-4];
    v0132 = stack[-2];
    v0132 = qcar(v0132);
    v0132 = qcar(v0132);
    v0080 = qcar(v0132);
    v0132 = stack[-2];
    v0132 = qcar(v0132);
    v0132 = qcar(v0132);
    v0132 = qcdr(v0132);
    fn = elt(env, 2); /* ofsf_pow2q */
    v0132 = (*qfn2(fn))(qenv(fn), v0080, v0132);
    nil = C_nil;
    if (exception_pending()) goto v0142;
    env = stack[-4];
    fn = elt(env, 3); /* multsq */
    v0080 = (*qfn2(fn))(qenv(fn), stack[0], v0132);
    nil = C_nil;
    if (exception_pending()) goto v0142;
    env = stack[-4];
    v0132 = stack[-3];
    {
        popv(5);
        fn = elt(env, 4); /* addsq */
        return (*qfn2(fn))(qenv(fn), v0080, v0132);
    }

v0096:
    v0132 = stack[-2];
    v0132 = qcar(v0132);
    v0080 = qcdr(v0132);
    v0132 = (Lisp_Object)17; /* 1 */
    stack[-1] = cons(v0080, v0132);
    nil = C_nil;
    if (exception_pending()) goto v0142;
    env = stack[-4];
    v0080 = stack[0];
    v0132 = stack[-2];
    v0132 = qcar(v0132);
    v0132 = qcar(v0132);
    v0132 = qcdr(v0132);
    fn = elt(env, 5); /* exptsq */
    v0132 = (*qfn2(fn))(qenv(fn), v0080, v0132);
    nil = C_nil;
    if (exception_pending()) goto v0142;
    env = stack[-4];
    fn = elt(env, 3); /* multsq */
    v0080 = (*qfn2(fn))(qenv(fn), stack[-1], v0132);
    nil = C_nil;
    if (exception_pending()) goto v0142;
    env = stack[-4];
    v0132 = stack[-3];
    {
        popv(5);
        fn = elt(env, 4); /* addsq */
        return (*qfn2(fn))(qenv(fn), v0080, v0132);
    }

v0025:
    v0132 = qvalue(elt(env, 1)); /* t */
    goto v0017;
/* error exit handlers */
v0142:
    popv(5);
    return nil;
}



/* Code for simpexpt */

static Lisp_Object CC_simpexpt(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0056, v0144, v0037;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for simpexpt");
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
    v0056 = qvalue(elt(env, 1)); /* nil */
    stack[-1] = qvalue(elt(env, 2)); /* kord!* */
    qvalue(elt(env, 2)) = v0056; /* kord!* */
    v0056 = stack[0];
    v0144 = qcdr(v0056);
    v0056 = elt(env, 3); /* expt */
    fn = elt(env, 5); /* carx */
    v0056 = (*qfn2(fn))(qenv(fn), v0144, v0056);
    nil = C_nil;
    if (exception_pending()) goto v0098;
    env = stack[-2];
    fn = elt(env, 6); /* simpexpon */
    v0056 = (*qfn1(fn))(qenv(fn), v0056);
    nil = C_nil;
    if (exception_pending()) goto v0098;
    env = stack[-2];
    qvalue(elt(env, 2)) = stack[-1]; /* kord!* */
    v0144 = v0056;
    v0056 = elt(env, 4); /* resimp */
    fn = elt(env, 7); /* simpexpon1 */
    v0056 = (*qfn2(fn))(qenv(fn), v0144, v0056);
    nil = C_nil;
    if (exception_pending()) goto v0013;
    env = stack[-2];
    v0144 = stack[0];
    v0037 = qcar(v0144);
    v0144 = v0056;
    v0056 = qvalue(elt(env, 1)); /* nil */
    {
        popv(3);
        fn = elt(env, 8); /* simpexpt1 */
        return (*qfnn(fn))(qenv(fn), 3, v0037, v0144, v0056);
    }
/* error exit handlers */
v0013:
    popv(3);
    return nil;
v0098:
    env = stack[-2];
    qvalue(elt(env, 2)) = stack[-1]; /* kord!* */
    popv(3);
    return nil;
}



/* Code for pasf_smwcpknowl */

static Lisp_Object CC_pasf_smwcpknowl(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0025, v0023;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pasf_smwcpknowl");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0023 = v0000;
/* end of prologue */
    v0025 = qvalue(elt(env, 1)); /* !*rlsusi */
    if (v0025 == nil) goto v0009;
    v0025 = v0023;
    {
        fn = elt(env, 2); /* cl_susicpknowl */
        return (*qfn1(fn))(qenv(fn), v0025);
    }

v0009:
    v0025 = v0023;
    {
        fn = elt(env, 3); /* cl_smcpknowl */
        return (*qfn1(fn))(qenv(fn), v0025);
    }
}



/* Code for ibalp_isinminclause */

static Lisp_Object CC_ibalp_isinminclause(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0026)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0147, v0148;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ibalp_isinminclause");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0026,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0026);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0026;
    stack[-2] = v0000;
/* end of prologue */
    stack[0] = nil;
    v0147 = stack[-2];
    v0147 = qcdr(v0147);
    v0147 = qcdr(v0147);
    v0147 = qcar(v0147);
    stack[-3] = v0147;
    goto v0025;

v0025:
    v0147 = stack[-3];
    if (v0147 == nil) goto v0017;
    v0147 = stack[0];
    if (!(v0147 == nil)) goto v0017;
    v0147 = stack[-3];
    v0147 = qcar(v0147);
    v0147 = qcdr(v0147);
    v0147 = qcdr(v0147);
    v0147 = qcdr(v0147);
    v0147 = qcdr(v0147);
    v0147 = qcar(v0147);
    if (v0147 == nil) goto v0149;
    v0147 = qvalue(elt(env, 1)); /* nil */
    goto v0040;

v0040:
    if (v0147 == nil) goto v0050;
    v0147 = qvalue(elt(env, 2)); /* t */
    stack[0] = v0147;
    goto v0050;

v0050:
    v0147 = stack[-3];
    v0147 = qcdr(v0147);
    stack[-3] = v0147;
    goto v0025;

v0149:
    v0147 = stack[-3];
    v0147 = qcar(v0147);
    v0147 = qcdr(v0147);
    v0147 = qcdr(v0147);
    v0147 = qcdr(v0147);
    v0148 = qcar(v0147);
    v0147 = stack[-3];
    v0147 = qcar(v0147);
    v0147 = qcdr(v0147);
    v0147 = qcdr(v0147);
    v0147 = qcar(v0147);
    v0148 = plus2(v0148, v0147);
    nil = C_nil;
    if (exception_pending()) goto v0083;
    env = stack[-4];
    v0147 = stack[-1];
    v0147 = Leqn(nil, v0148, v0147);
    nil = C_nil;
    if (exception_pending()) goto v0083;
    env = stack[-4];
    goto v0040;

v0017:
    v0147 = stack[-2];
    v0147 = qcdr(v0147);
    v0147 = qcdr(v0147);
    v0147 = qcdr(v0147);
    v0147 = qcar(v0147);
    stack[-3] = v0147;
    goto v0007;

v0007:
    v0147 = stack[-3];
    if (v0147 == nil) { Lisp_Object res = stack[0]; popv(5); return onevalue(res); }
    v0147 = stack[0];
    if (!(v0147 == nil)) { Lisp_Object res = stack[0]; popv(5); return onevalue(res); }
    v0147 = stack[-3];
    v0147 = qcar(v0147);
    v0147 = qcdr(v0147);
    v0147 = qcdr(v0147);
    v0147 = qcdr(v0147);
    v0147 = qcdr(v0147);
    v0147 = qcar(v0147);
    if (v0147 == nil) goto v0150;
    v0147 = qvalue(elt(env, 1)); /* nil */
    goto v0126;

v0126:
    if (v0147 == nil) goto v0043;
    v0147 = qvalue(elt(env, 2)); /* t */
    stack[0] = v0147;
    goto v0043;

v0043:
    v0147 = stack[-3];
    v0147 = qcdr(v0147);
    stack[-3] = v0147;
    goto v0007;

v0150:
    v0147 = stack[-3];
    v0147 = qcar(v0147);
    v0147 = qcdr(v0147);
    v0147 = qcdr(v0147);
    v0147 = qcdr(v0147);
    v0148 = qcar(v0147);
    v0147 = stack[-3];
    v0147 = qcar(v0147);
    v0147 = qcdr(v0147);
    v0147 = qcdr(v0147);
    v0147 = qcar(v0147);
    v0148 = plus2(v0148, v0147);
    nil = C_nil;
    if (exception_pending()) goto v0083;
    env = stack[-4];
    v0147 = stack[-1];
    v0147 = Leqn(nil, v0148, v0147);
    nil = C_nil;
    if (exception_pending()) goto v0083;
    env = stack[-4];
    goto v0126;
/* error exit handlers */
v0083:
    popv(5);
    return nil;
}



/* Code for ev_lexcomp */

static Lisp_Object CC_ev_lexcomp(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0026)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0013, v0104;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ev_lexcomp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0026,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0026);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0026;
    stack[-1] = v0000;
/* end of prologue */

v0044:
    v0013 = stack[-1];
    if (v0013 == nil) goto v0024;
    v0013 = stack[-1];
    v0104 = qcar(v0013);
    v0013 = stack[0];
    v0013 = qcar(v0013);
    fn = elt(env, 1); /* iequal */
    v0013 = (*qfn2(fn))(qenv(fn), v0104, v0013);
    nil = C_nil;
    if (exception_pending()) goto v0030;
    env = stack[-2];
    if (v0013 == nil) goto v0099;
    v0013 = stack[-1];
    v0013 = qcdr(v0013);
    stack[-1] = v0013;
    v0013 = stack[0];
    v0013 = qcdr(v0013);
    stack[0] = v0013;
    goto v0044;

v0099:
    v0013 = stack[-1];
    v0104 = qcar(v0013);
    v0013 = stack[0];
    v0013 = qcar(v0013);
    if (((int32_t)(v0104)) > ((int32_t)(v0013))) goto v0040;
    v0013 = (Lisp_Object)-15; /* -1 */
    { popv(3); return onevalue(v0013); }

v0040:
    v0013 = (Lisp_Object)17; /* 1 */
    { popv(3); return onevalue(v0013); }

v0024:
    v0013 = (Lisp_Object)1; /* 0 */
    { popv(3); return onevalue(v0013); }
/* error exit handlers */
v0030:
    popv(3);
    return nil;
}



/* Code for mchkopt1 */

static Lisp_Object MS_CDECL CC_mchkopt1(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0166, v0167, v0075;
    Lisp_Object fn;
    Lisp_Object v0004, v0026, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "mchkopt1");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0026 = va_arg(aa, Lisp_Object);
    v0004 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mchkopt1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0004,v0026,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0026,v0004);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-4] = v0004;
    v0166 = v0026;
    v0075 = v0000;
/* end of prologue */
    v0166 = qcdr(v0166);
    v0167 = v0166;
    if (v0166 == nil) goto v0018;
    v0166 = v0167;
    v0166 = qcar(v0166);
    stack[-3] = v0166;
    v0166 = v0167;
    v0166 = qcdr(v0166);
    v0167 = v0166;
    if (v0166 == nil) goto v0005;
    v0166 = v0167;
    v0166 = qcar(v0166);
    stack[-5] = v0166;
    v0166 = v0167;
    v0166 = qcdr(v0166);
    if (v0166 == nil) goto v0040;
    v0166 = qvalue(elt(env, 1)); /* nil */
    { popv(7); return onevalue(v0166); }

v0040:
    v0166 = stack[-3];
    if (!symbolp(v0166)) v0166 = nil;
    else { v0166 = qfastgets(v0166);
           if (v0166 != nil) { v0166 = elt(v0166, 6); /* optional */
#ifdef RECORD_GET
             if (v0166 == SPID_NOPROP)
                record_get(elt(fastget_names, 6), 0),
                v0166 = nil;
             else record_get(elt(fastget_names, 6), 1),
                v0166 = lisp_true; }
           else record_get(elt(fastget_names, 6), 0); }
#else
             if (v0166 == SPID_NOPROP) v0166 = nil; else v0166 = lisp_true; }}
#endif
    if (v0166 == nil) goto v0056;
    v0167 = v0075;
    v0166 = stack[-5];
    fn = elt(env, 2); /* mchk */
    v0166 = (*qfn2(fn))(qenv(fn), v0167, v0166);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-6];
    stack[-5] = v0166;
    v0166 = stack[-5];
    if (v0166 == nil) goto v0031;
    v0166 = stack[-5];
    v0166 = qcar(v0166);
    v0075 = stack[-3];
    v0167 = stack[-4];
    v0167 = qcar(v0167);
    v0166 = acons(v0075, v0167, v0166);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-6];
    v0166 = ncons(v0166);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-6];
    stack[-1] = v0166;
    stack[-2] = v0166;
    goto v0149;

v0149:
    v0166 = stack[-5];
    v0166 = qcdr(v0166);
    stack[-5] = v0166;
    v0166 = stack[-5];
    if (v0166 == nil) { Lisp_Object res = stack[-2]; popv(7); return onevalue(res); }
    stack[0] = stack[-1];
    v0166 = stack[-5];
    v0166 = qcar(v0166);
    v0075 = stack[-3];
    v0167 = stack[-4];
    v0167 = qcar(v0167);
    v0166 = acons(v0075, v0167, v0166);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-6];
    v0166 = ncons(v0166);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-6];
    v0166 = Lrplacd(nil, stack[0], v0166);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-6];
    v0166 = stack[-1];
    v0166 = qcdr(v0166);
    stack[-1] = v0166;
    goto v0149;

v0031:
    v0166 = qvalue(elt(env, 1)); /* nil */
    { popv(7); return onevalue(v0166); }

v0056:
    v0166 = stack[-5];
    if (!symbolp(v0166)) v0166 = nil;
    else { v0166 = qfastgets(v0166);
           if (v0166 != nil) { v0166 = elt(v0166, 6); /* optional */
#ifdef RECORD_GET
             if (v0166 == SPID_NOPROP)
                record_get(elt(fastget_names, 6), 0),
                v0166 = nil;
             else record_get(elt(fastget_names, 6), 1),
                v0166 = lisp_true; }
           else record_get(elt(fastget_names, 6), 0); }
#else
             if (v0166 == SPID_NOPROP) v0166 = nil; else v0166 = lisp_true; }}
#endif
    if (v0166 == nil) goto v0169;
    v0167 = v0075;
    v0166 = stack[-3];
    fn = elt(env, 2); /* mchk */
    v0166 = (*qfn2(fn))(qenv(fn), v0167, v0166);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-6];
    stack[-3] = v0166;
    v0166 = stack[-3];
    if (v0166 == nil) goto v0131;
    v0166 = stack[-3];
    v0166 = qcar(v0166);
    v0075 = stack[-5];
    v0167 = stack[-4];
    v0167 = qcdr(v0167);
    v0167 = qcar(v0167);
    v0166 = acons(v0075, v0167, v0166);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-6];
    v0166 = ncons(v0166);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-6];
    stack[-1] = v0166;
    stack[-2] = v0166;
    goto v0122;

v0122:
    v0166 = stack[-3];
    v0166 = qcdr(v0166);
    stack[-3] = v0166;
    v0166 = stack[-3];
    if (v0166 == nil) { Lisp_Object res = stack[-2]; popv(7); return onevalue(res); }
    stack[0] = stack[-1];
    v0166 = stack[-3];
    v0166 = qcar(v0166);
    v0075 = stack[-5];
    v0167 = stack[-4];
    v0167 = qcdr(v0167);
    v0167 = qcar(v0167);
    v0166 = acons(v0075, v0167, v0166);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-6];
    v0166 = ncons(v0166);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-6];
    v0166 = Lrplacd(nil, stack[0], v0166);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-6];
    v0166 = stack[-1];
    v0166 = qcdr(v0166);
    stack[-1] = v0166;
    goto v0122;

v0131:
    v0166 = qvalue(elt(env, 1)); /* nil */
    { popv(7); return onevalue(v0166); }

v0169:
    v0166 = qvalue(elt(env, 1)); /* nil */
    { popv(7); return onevalue(v0166); }

v0005:
    v0166 = qvalue(elt(env, 1)); /* nil */
    { popv(7); return onevalue(v0166); }

v0018:
    v0166 = qvalue(elt(env, 1)); /* nil */
    { popv(7); return onevalue(v0166); }
/* error exit handlers */
v0168:
    popv(7);
    return nil;
}



/* Code for inttovec1 */

static Lisp_Object CC_inttovec1(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0026)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0032, v0031;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for inttovec1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0026,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0026);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0026;
    stack[-1] = v0000;
/* end of prologue */
    v0031 = stack[-1];
    v0032 = (Lisp_Object)17; /* 1 */
    if (v0031 == v0032) goto v0044;
    v0032 = stack[-1];
    v0031 = sub1(v0032);
    nil = C_nil;
    if (exception_pending()) goto v0003;
    env = stack[-3];
    v0032 = stack[0];
    v0032 = qcdr(v0032);
    fn = elt(env, 1); /* inttovec!-solve */
    v0032 = (*qfn2(fn))(qenv(fn), v0031, v0032);
    nil = C_nil;
    if (exception_pending()) goto v0003;
    env = stack[-3];
    stack[-2] = v0032;
    v0032 = stack[0];
    v0031 = qcar(v0032);
    v0032 = stack[-2];
    v0032 = qcar(v0032);
    stack[0] = difference2(v0031, v0032);
    nil = C_nil;
    if (exception_pending()) goto v0003;
    env = stack[-3];
    v0032 = stack[-1];
    v0031 = sub1(v0032);
    nil = C_nil;
    if (exception_pending()) goto v0003;
    env = stack[-3];
    v0032 = stack[-2];
    v0032 = CC_inttovec1(env, v0031, v0032);
    nil = C_nil;
    if (exception_pending()) goto v0003;
    {
        Lisp_Object v0146 = stack[0];
        popv(4);
        return cons(v0146, v0032);
    }

v0044:
    v0032 = stack[0];
    v0032 = qcar(v0032);
    popv(4);
    return ncons(v0032);
/* error exit handlers */
v0003:
    popv(4);
    return nil;
}



/* Code for mkfortterpri */

static Lisp_Object MS_CDECL CC_mkfortterpri(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0001;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "mkfortterpri");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mkfortterpri");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* end of prologue */
    v0001 = elt(env, 1); /* fortterpri */
    return ncons(v0001);
}



/* Code for trwrite */

static Lisp_Object CC_trwrite(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0047;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for trwrite");
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
    v0047 = qcar(v0047);
    if (!symbolp(v0047)) v0047 = nil;
    else { v0047 = qfastgets(v0047);
           if (v0047 != nil) { v0047 = elt(v0047, 53); /* tracing */
#ifdef RECORD_GET
             if (v0047 == SPID_NOPROP)
                record_get(elt(fastget_names, 53), 0),
                v0047 = nil;
             else record_get(elt(fastget_names, 53), 1),
                v0047 = lisp_true; }
           else record_get(elt(fastget_names, 53), 0); }
#else
             if (v0047 == SPID_NOPROP) v0047 = nil; else v0047 = lisp_true; }}
#endif
    if (v0047 == nil) goto v0129;
    v0047 = elt(env, 2); /* "**in procedure: " */
    v0047 = Lprinc(nil, v0047);
    nil = C_nil;
    if (exception_pending()) goto v0013;
    env = stack[-1];
    v0047 = stack[0];
    v0047 = qcar(v0047);
    v0047 = Lprinc(nil, v0047);
    nil = C_nil;
    if (exception_pending()) goto v0013;
    env = stack[-1];
    v0047 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0013;
    env = stack[-1];
    v0047 = stack[0];
    v0047 = qcdr(v0047);
    stack[0] = v0047;
    goto v0052;

v0052:
    v0047 = stack[0];
    if (v0047 == nil) goto v0006;
    v0047 = stack[0];
    v0047 = qcar(v0047);
    v0047 = Lprinc(nil, v0047);
    nil = C_nil;
    if (exception_pending()) goto v0013;
    env = stack[-1];
    v0047 = stack[0];
    v0047 = qcdr(v0047);
    stack[0] = v0047;
    goto v0052;

v0006:
    v0047 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0013;
    v0047 = nil;
    { popv(2); return onevalue(v0047); }

v0129:
    v0047 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v0047); }
/* error exit handlers */
v0013:
    popv(2);
    return nil;
}



/* Code for setelv */

static Lisp_Object CC_setelv(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0026)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0146, v0094;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for setelv");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0026,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0026);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-4] = v0026;
    v0094 = v0000;
/* end of prologue */
    v0146 = v0094;
    stack[-5] = qcar(v0146);
    v0146 = v0094;
    v0146 = qcdr(v0146);
    stack[-3] = v0146;
    v0146 = stack[-3];
    if (v0146 == nil) goto v0059;
    v0146 = stack[-3];
    v0146 = qcar(v0146);
    fn = elt(env, 2); /* reval_without_mod */
    v0146 = (*qfn1(fn))(qenv(fn), v0146);
    nil = C_nil;
    if (exception_pending()) goto v0096;
    env = stack[-6];
    v0146 = ncons(v0146);
    nil = C_nil;
    if (exception_pending()) goto v0096;
    env = stack[-6];
    stack[-1] = v0146;
    stack[-2] = v0146;
    goto v0006;

v0006:
    v0146 = stack[-3];
    v0146 = qcdr(v0146);
    stack[-3] = v0146;
    v0146 = stack[-3];
    if (v0146 == nil) goto v0047;
    stack[0] = stack[-1];
    v0146 = stack[-3];
    v0146 = qcar(v0146);
    fn = elt(env, 2); /* reval_without_mod */
    v0146 = (*qfn1(fn))(qenv(fn), v0146);
    nil = C_nil;
    if (exception_pending()) goto v0096;
    env = stack[-6];
    v0146 = ncons(v0146);
    nil = C_nil;
    if (exception_pending()) goto v0096;
    env = stack[-6];
    v0146 = Lrplacd(nil, stack[0], v0146);
    nil = C_nil;
    if (exception_pending()) goto v0096;
    env = stack[-6];
    v0146 = stack[-1];
    v0146 = qcdr(v0146);
    stack[-1] = v0146;
    goto v0006;

v0047:
    v0146 = stack[-2];
    goto v0025;

v0025:
    v0094 = cons(stack[-5], v0146);
    nil = C_nil;
    if (exception_pending()) goto v0096;
    env = stack[-6];
    v0146 = stack[-4];
    {
        popv(7);
        fn = elt(env, 3); /* setel */
        return (*qfn2(fn))(qenv(fn), v0094, v0146);
    }

v0059:
    v0146 = qvalue(elt(env, 1)); /* nil */
    goto v0025;
/* error exit handlers */
v0096:
    popv(7);
    return nil;
}



/* Code for moid_member */

static Lisp_Object CC_moid_member(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0026)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0012, v0015;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for moid_member");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0026,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0026);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0026;
    stack[-1] = v0000;
/* end of prologue */

v0115:
    v0012 = stack[0];
    if (v0012 == nil) goto v0044;
    v0012 = stack[0];
    v0015 = qcar(v0012);
    v0012 = stack[-1];
    fn = elt(env, 2); /* mo_vdivides!? */
    v0012 = (*qfn2(fn))(qenv(fn), v0015, v0012);
    nil = C_nil;
    if (exception_pending()) goto v0021;
    env = stack[-2];
    if (!(v0012 == nil)) { popv(3); return onevalue(v0012); }
    v0015 = stack[-1];
    v0012 = stack[0];
    v0012 = qcdr(v0012);
    stack[-1] = v0015;
    stack[0] = v0012;
    goto v0115;

v0044:
    v0012 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v0012); }
/* error exit handlers */
v0021:
    popv(3);
    return nil;
}



/* Code for pst_termnodep */

static Lisp_Object CC_pst_termnodep(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0025, v0023;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pst_termnodep");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0025 = v0000;
/* end of prologue */
    v0023 = qcdr(v0025);
    v0025 = (Lisp_Object)1; /* 0 */
    v0025 = *(Lisp_Object *)((char *)v0023 + (CELL-TAG_VECTOR) + ((int32_t)v0025/(16/CELL)));
    v0025 = qcdr(v0025);
    v0025 = (v0025 == nil ? lisp_true : nil);
    return onevalue(v0025);
}



/* Code for ratn */

static Lisp_Object CC_ratn(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0054, v0057, v0058;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ratn");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0058 = v0000;
/* end of prologue */
    v0054 = v0058;
    if (v0054 == nil) goto v0024;
    v0054 = v0058;
    if (!consp(v0054)) goto v0041;
    v0054 = v0058;
    v0057 = qcar(v0054);
    v0054 = elt(env, 1); /* !:rn!: */
    if (v0057 == v0054) goto v0011;
    v0058 = elt(env, 2); /* arnum */
    v0057 = (Lisp_Object)97; /* 6 */
    v0054 = elt(env, 3); /* "Illegal domain in :ar:" */
    {
        fn = elt(env, 4); /* rerror */
        return (*qfnn(fn))(qenv(fn), 3, v0058, v0057, v0054);
    }

v0011:
    v0054 = v0058;
    v0054 = qcdr(v0054);
    return onevalue(v0054);

v0041:
    v0057 = v0058;
    v0054 = (Lisp_Object)17; /* 1 */
    return cons(v0057, v0054);

v0024:
    v0057 = (Lisp_Object)1; /* 0 */
    v0054 = (Lisp_Object)17; /* 1 */
    return cons(v0057, v0054);
}



/* Code for monomwrite */

static Lisp_Object CC_monomwrite(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0172, v0124, v0125;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for monomwrite");
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
    v0124 = v0000;
/* end of prologue */
    stack[-5] = nil;
    v0172 = qvalue(elt(env, 1)); /* fluidbibasisnumberofvariables */
    stack[-2] = v0172;
    v0172 = qvalue(elt(env, 2)); /* fluidbibasisreversedvariables */
    stack[-4] = v0172;
    v0172 = (Lisp_Object)17; /* 1 */
    v0172 = *(Lisp_Object *)((char *)v0124 + (CELL-TAG_VECTOR) + ((int32_t)v0172/(16/CELL)));
    stack[-3] = v0172;
    goto v0016;

v0016:
    v0172 = stack[-3];
    v0172 = qcar(v0172);
    if (v0172 == nil) { Lisp_Object res = stack[-5]; popv(7); return onevalue(res); }
    v0172 = (Lisp_Object)17; /* 1 */
    stack[0] = v0172;
    goto v0170;

v0170:
    v0124 = stack[-2];
    v0172 = stack[-3];
    v0172 = qcar(v0172);
    v0124 = difference2(v0124, v0172);
    nil = C_nil;
    if (exception_pending()) goto v0173;
    env = stack[-6];
    v0172 = stack[0];
    v0172 = difference2(v0124, v0172);
    nil = C_nil;
    if (exception_pending()) goto v0173;
    env = stack[-6];
    v0172 = Lminusp(nil, v0172);
    env = stack[-6];
    if (v0172 == nil) goto v0020;
    v0172 = stack[-3];
    v0172 = qcar(v0172);
    stack[-2] = v0172;
    v0172 = stack[-5];
    if (v0172 == nil) goto v0028;
    v0172 = stack[-4];
    stack[-1] = qcar(v0172);
    stack[0] = (Lisp_Object)17; /* 1 */
    v0172 = stack[-5];
    v0172 = ncons(v0172);
    nil = C_nil;
    if (exception_pending()) goto v0173;
    env = stack[-6];
    v0172 = acons(stack[-1], stack[0], v0172);
    nil = C_nil;
    if (exception_pending()) goto v0173;
    env = stack[-6];
    stack[-5] = v0172;
    goto v0105;

v0105:
    v0172 = stack[-3];
    v0172 = qcdr(v0172);
    stack[-3] = v0172;
    goto v0016;

v0028:
    v0172 = stack[-4];
    v0125 = qcar(v0172);
    v0124 = (Lisp_Object)17; /* 1 */
    v0172 = (Lisp_Object)17; /* 1 */
    v0172 = acons(v0125, v0124, v0172);
    nil = C_nil;
    if (exception_pending()) goto v0173;
    env = stack[-6];
    stack[-5] = v0172;
    goto v0105;

v0020:
    v0172 = stack[-4];
    v0172 = qcdr(v0172);
    stack[-4] = v0172;
    v0172 = stack[0];
    v0172 = add1(v0172);
    nil = C_nil;
    if (exception_pending()) goto v0173;
    env = stack[-6];
    stack[0] = v0172;
    goto v0170;
/* error exit handlers */
v0173:
    popv(7);
    return nil;
}



/* Code for vintersection */

static Lisp_Object CC_vintersection(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0026)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0085, v0159;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for vintersection");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0026,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0026);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0026;
    stack[-1] = v0000;
/* end of prologue */

v0115:
    v0085 = stack[-1];
    if (v0085 == nil) goto v0024;
    v0085 = stack[-1];
    v0085 = qcar(v0085);
    v0159 = qcar(v0085);
    v0085 = stack[0];
    v0085 = Lassoc(nil, v0159, v0085);
    stack[-2] = v0085;
    if (v0085 == nil) goto v0116;
    v0085 = stack[-1];
    v0085 = qcar(v0085);
    v0159 = qcdr(v0085);
    v0085 = stack[-2];
    v0085 = qcdr(v0085);
    v0085 = (Lisp_Object)greaterp2(v0159, v0085);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    v0085 = v0085 ? lisp_true : nil;
    env = stack[-3];
    if (v0085 == nil) goto v0043;
    v0085 = stack[-2];
    v0159 = qcdr(v0085);
    v0085 = (Lisp_Object)1; /* 0 */
    if (v0159 == v0085) goto v0175;
    v0085 = stack[-1];
    v0159 = qcdr(v0085);
    v0085 = stack[0];
    v0085 = CC_vintersection(env, v0159, v0085);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    {
        Lisp_Object v0132 = stack[-2];
        popv(4);
        return cons(v0132, v0085);
    }

v0175:
    v0085 = stack[-1];
    v0159 = qcdr(v0085);
    v0085 = stack[0];
    stack[-1] = v0159;
    stack[0] = v0085;
    goto v0115;

v0043:
    v0085 = stack[-1];
    v0085 = qcar(v0085);
    v0159 = qcdr(v0085);
    v0085 = (Lisp_Object)1; /* 0 */
    if (v0159 == v0085) goto v0176;
    v0085 = stack[-1];
    stack[-2] = qcar(v0085);
    v0085 = stack[-1];
    v0159 = qcdr(v0085);
    v0085 = stack[0];
    v0085 = CC_vintersection(env, v0159, v0085);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    {
        Lisp_Object v0080 = stack[-2];
        popv(4);
        return cons(v0080, v0085);
    }

v0176:
    v0085 = stack[-1];
    v0159 = qcdr(v0085);
    v0085 = stack[0];
    stack[-1] = v0159;
    stack[0] = v0085;
    goto v0115;

v0116:
    v0085 = stack[-1];
    v0159 = qcdr(v0085);
    v0085 = stack[0];
    stack[-1] = v0159;
    stack[0] = v0085;
    goto v0115;

v0024:
    v0085 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v0085); }
/* error exit handlers */
v0131:
    popv(4);
    return nil;
}



/* Code for ezgcdf1 */

static Lisp_Object CC_ezgcdf1(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0026)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0049, v0117, v0171;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ezgcdf1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0026,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0026);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0117 = v0026;
    v0171 = v0000;
/* end of prologue */
    v0049 = (Lisp_Object)1; /* 0 */
    stack[0] = qvalue(elt(env, 1)); /* factor!-level */
    qvalue(elt(env, 1)) = v0049; /* factor!-level */
    v0049 = v0171;
    v0049 = list2(v0049, v0117);
    nil = C_nil;
    if (exception_pending()) goto v0041;
    env = stack[-1];
    fn = elt(env, 2); /* gcdlist */
    v0049 = (*qfn1(fn))(qenv(fn), v0049);
    nil = C_nil;
    if (exception_pending()) goto v0041;
    env = stack[-1];
    fn = elt(env, 3); /* poly!-abs */
    v0049 = (*qfn1(fn))(qenv(fn), v0049);
    nil = C_nil;
    if (exception_pending()) goto v0041;
    env = stack[-1];
    qvalue(elt(env, 1)) = stack[0]; /* factor!-level */
    { popv(2); return onevalue(v0049); }
/* error exit handlers */
v0041:
    env = stack[-1];
    qvalue(elt(env, 1)) = stack[0]; /* factor!-level */
    popv(2);
    return nil;
}



/* Code for ibalp_var!-set */

static Lisp_Object MS_CDECL CC_ibalp_varKset(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0178, v0158;
    Lisp_Object fn;
    Lisp_Object v0001, v0004, v0026, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "ibalp_var-set");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0026 = va_arg(aa, Lisp_Object);
    v0004 = va_arg(aa, Lisp_Object);
    v0001 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ibalp_var-set");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v0001,v0004,v0026,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0000,v0026,v0004,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0001;
    stack[-1] = v0004;
    stack[-2] = v0026;
    stack[-3] = v0000;
/* end of prologue */
    v0178 = stack[-3];
    v0158 = qcdr(v0178);
    v0178 = stack[-2];
    fn = elt(env, 1); /* setcar */
    v0178 = (*qfn2(fn))(qenv(fn), v0158, v0178);
    nil = C_nil;
    if (exception_pending()) goto v0179;
    env = stack[-4];
    v0178 = stack[-3];
    v0178 = qcdr(v0178);
    v0178 = qcdr(v0178);
    v0178 = qcdr(v0178);
    v0178 = qcdr(v0178);
    v0178 = qcdr(v0178);
    v0158 = qcdr(v0178);
    v0178 = stack[-1];
    fn = elt(env, 1); /* setcar */
    v0178 = (*qfn2(fn))(qenv(fn), v0158, v0178);
    nil = C_nil;
    if (exception_pending()) goto v0179;
    env = stack[-4];
    v0178 = stack[-3];
    v0178 = qcdr(v0178);
    v0178 = qcdr(v0178);
    v0178 = qcdr(v0178);
    v0178 = qcdr(v0178);
    v0178 = qcdr(v0178);
    v0178 = qcdr(v0178);
    v0158 = qcdr(v0178);
    v0178 = stack[0];
    fn = elt(env, 1); /* setcar */
    v0178 = (*qfn2(fn))(qenv(fn), v0158, v0178);
    nil = C_nil;
    if (exception_pending()) goto v0179;
    env = stack[-4];
    v0178 = stack[-3];
    v0178 = qcar(v0178);
    stack[0] = v0178;
    v0158 = stack[-2];
    v0178 = (Lisp_Object)1; /* 0 */
    v0178 = Leqn(nil, v0158, v0178);
    nil = C_nil;
    if (exception_pending()) goto v0179;
    env = stack[-4];
    if (v0178 == nil) goto v0034;
    v0178 = stack[-3];
    v0178 = qcdr(v0178);
    v0178 = qcdr(v0178);
    v0178 = qcdr(v0178);
    v0178 = qcar(v0178);
    goto v0036;

v0036:
    v0158 = v0178;
    v0178 = stack[0];
    fn = elt(env, 2); /* ibalp_var!-satlist */
    v0178 = (*qfn2(fn))(qenv(fn), v0158, v0178);
    nil = C_nil;
    if (exception_pending()) goto v0179;
    env = stack[-4];
    v0158 = stack[-2];
    v0178 = (Lisp_Object)17; /* 1 */
    v0178 = Leqn(nil, v0158, v0178);
    nil = C_nil;
    if (exception_pending()) goto v0179;
    env = stack[-4];
    if (v0178 == nil) goto v0180;
    v0178 = stack[-3];
    v0178 = qcdr(v0178);
    v0178 = qcdr(v0178);
    v0178 = qcdr(v0178);
    v0178 = qcar(v0178);
    goto v0161;

v0161:
    v0158 = v0178;
    v0178 = stack[-2];
    fn = elt(env, 3); /* ibalp_var!-unsatlist */
    v0178 = (*qfn2(fn))(qenv(fn), v0158, v0178);
    nil = C_nil;
    if (exception_pending()) goto v0179;
    env = stack[-4];
    v0178 = stack[-3];
    fn = elt(env, 4); /* ibalp_var!-wclist */
    v0178 = (*qfn1(fn))(qenv(fn), v0178);
    nil = C_nil;
    if (exception_pending()) goto v0179;
    env = stack[-4];
    stack[-1] = v0178;
    v0178 = stack[-3];
    v0178 = qcdr(v0178);
    v0178 = qcdr(v0178);
    v0178 = qcdr(v0178);
    v0178 = qcdr(v0178);
    v0178 = qcdr(v0178);
    v0178 = qcdr(v0178);
    v0178 = qcdr(v0178);
    v0178 = qcdr(v0178);
    v0178 = qcdr(v0178);
    v0178 = qcdr(v0178);
    stack[0] = qcdr(v0178);
    v0178 = stack[-3];
    fn = elt(env, 5); /* ibalp_calcmom */
    v0178 = (*qfn1(fn))(qenv(fn), v0178);
    nil = C_nil;
    if (exception_pending()) goto v0179;
    env = stack[-4];
    fn = elt(env, 1); /* setcar */
    v0178 = (*qfn2(fn))(qenv(fn), stack[0], v0178);
    nil = C_nil;
    if (exception_pending()) goto v0179;
    { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }

v0180:
    v0178 = stack[-3];
    v0178 = qcdr(v0178);
    v0178 = qcdr(v0178);
    v0178 = qcar(v0178);
    goto v0161;

v0034:
    v0178 = stack[-3];
    v0178 = qcdr(v0178);
    v0178 = qcdr(v0178);
    v0178 = qcar(v0178);
    goto v0036;
/* error exit handlers */
v0179:
    popv(5);
    return nil;
}



/* Code for unaryrd */

static Lisp_Object MS_CDECL CC_unaryrd(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0024;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "unaryrd");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for unaryrd");
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
    fn = elt(env, 1); /* mathml */
    v0024 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0128;
    env = stack[-1];
    stack[0] = v0024;
    fn = elt(env, 2); /* lex */
    v0024 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0128;
    v0024 = stack[0];
    popv(2);
    return ncons(v0024);
/* error exit handlers */
v0128:
    popv(2);
    return nil;
}



/* Code for dm!-minus */

static Lisp_Object CC_dmKminus(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0023, v0049;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dm-minus");
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
    v0023 = v0000;
/* end of prologue */
    fn = elt(env, 1); /* !:minus */
    v0023 = (*qfn1(fn))(qenv(fn), v0023);
    errexit();
    v0049 = v0023;
    v0023 = v0049;
    if (!(v0023 == nil)) return onevalue(v0049);
    v0023 = (Lisp_Object)1; /* 0 */
    return onevalue(v0023);
}



/* Code for quoteequation */

static Lisp_Object CC_quoteequation(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object v0001;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for quoteequation");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0001 = v0000;
/* end of prologue */
    v0001 = elt(env, 1); /* equation */
    return onevalue(v0001);
}



/* Code for evgradlexcomp */

static Lisp_Object CC_evgradlexcomp(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0026)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0093, v0092;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for evgradlexcomp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0026,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0026);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0026;
    stack[-2] = v0000;
/* end of prologue */

v0044:
    v0093 = stack[-2];
    if (v0093 == nil) goto v0024;
    v0093 = stack[-1];
    if (v0093 == nil) goto v0017;
    v0093 = stack[-2];
    v0092 = qcar(v0093);
    v0093 = stack[-1];
    v0093 = qcar(v0093);
    fn = elt(env, 2); /* iequal */
    v0093 = (*qfn2(fn))(qenv(fn), v0092, v0093);
    nil = C_nil;
    if (exception_pending()) goto v0140;
    env = stack[-4];
    if (v0093 == nil) goto v0012;
    v0093 = stack[-2];
    v0093 = qcdr(v0093);
    stack[-2] = v0093;
    v0093 = stack[-1];
    v0093 = qcdr(v0093);
    stack[-1] = v0093;
    goto v0044;

v0012:
    v0093 = stack[-2];
    fn = elt(env, 3); /* evtdeg */
    stack[0] = (*qfn1(fn))(qenv(fn), v0093);
    nil = C_nil;
    if (exception_pending()) goto v0140;
    env = stack[-4];
    v0093 = stack[-1];
    fn = elt(env, 3); /* evtdeg */
    v0093 = (*qfn1(fn))(qenv(fn), v0093);
    nil = C_nil;
    if (exception_pending()) goto v0140;
    env = stack[-4];
    stack[-3] = stack[0];
    stack[0] = v0093;
    v0092 = stack[-3];
    v0093 = stack[0];
    fn = elt(env, 2); /* iequal */
    v0093 = (*qfn2(fn))(qenv(fn), v0092, v0093);
    nil = C_nil;
    if (exception_pending()) goto v0140;
    if (v0093 == nil) goto v0095;
    v0093 = stack[-2];
    v0092 = qcar(v0093);
    v0093 = stack[-1];
    v0093 = qcar(v0093);
    if (((int32_t)(v0092)) > ((int32_t)(v0093))) goto v0118;
    v0093 = (Lisp_Object)-15; /* -1 */
    { popv(5); return onevalue(v0093); }

v0118:
    v0093 = (Lisp_Object)17; /* 1 */
    { popv(5); return onevalue(v0093); }

v0095:
    v0092 = stack[-3];
    v0093 = stack[0];
    if (((int32_t)(v0092)) > ((int32_t)(v0093))) goto v0096;
    v0093 = (Lisp_Object)-15; /* -1 */
    { popv(5); return onevalue(v0093); }

v0096:
    v0093 = (Lisp_Object)17; /* 1 */
    { popv(5); return onevalue(v0093); }

v0017:
    v0093 = elt(env, 1); /* (0) */
    stack[-1] = v0093;
    goto v0044;

v0024:
    v0093 = (Lisp_Object)1; /* 0 */
    { popv(5); return onevalue(v0093); }
/* error exit handlers */
v0140:
    popv(5);
    return nil;
}



/* Code for physopsm!* */

static Lisp_Object CC_physopsmH(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0204, v0205, v0206, v0207;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for physopsm*");
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
/* copy arguments values to proper place */
    stack[-3] = v0000;
/* end of prologue */
    stack[0] = nil;
    v0204 = stack[-3];
    if (v0204 == nil) goto v0049;
    v0204 = stack[-3];
    v0204 = (is_number(v0204) ? lisp_true : nil);
    goto v0023;

v0023:
    if (v0204 == nil) goto v0017;
    v0204 = stack[-3];
    stack[0] = v0204;
    { Lisp_Object res = stack[0]; popv(6); return onevalue(res); }

v0017:
    v0204 = stack[-3];
    fn = elt(env, 13); /* physopp */
    v0204 = (*qfn1(fn))(qenv(fn), v0204);
    nil = C_nil;
    if (exception_pending()) goto v0208;
    env = stack[-5];
    if (v0204 == nil) goto v0116;
    v0204 = stack[-3];
    if (!symbolp(v0204)) v0204 = nil;
    else { v0204 = qfastgets(v0204);
           if (v0204 != nil) { v0204 = elt(v0204, 46); /* rvalue */
#ifdef RECORD_GET
             if (v0204 != SPID_NOPROP)
                record_get(elt(fastget_names, 46), 1);
             else record_get(elt(fastget_names, 46), 0),
                v0204 = nil; }
           else record_get(elt(fastget_names, 46), 0); }
#else
             if (v0204 == SPID_NOPROP) v0204 = nil; }}
#endif
    stack[-1] = v0204;
    if (v0204 == nil) goto v0051;
    v0204 = stack[-1];
    fn = elt(env, 14); /* physopaeval */
    v0204 = (*qfn1(fn))(qenv(fn), v0204);
    nil = C_nil;
    if (exception_pending()) goto v0208;
    goto v0039;

v0039:
    stack[0] = v0204;
    { Lisp_Object res = stack[0]; popv(6); return onevalue(res); }

v0051:
    v0204 = stack[-3];
    if (symbolp(v0204)) goto v0021;
    v0204 = stack[-3];
    v0205 = qcar(v0204);
    v0204 = elt(env, 2); /* psimpfn */
    v0204 = get(v0205, v0204);
    env = stack[-5];
    stack[-1] = v0204;
    if (v0204 == nil) goto v0047;
    v0205 = stack[-1];
    v0204 = stack[-3];
    v0204 = Lapply1(nil, v0205, v0204);
    nil = C_nil;
    if (exception_pending()) goto v0208;
    goto v0039;

v0047:
    v0204 = stack[-3];
    v0204 = qcar(v0204);
    if (!symbolp(v0204)) v0204 = nil;
    else { v0204 = qfastgets(v0204);
           if (v0204 != nil) { v0204 = elt(v0204, 9); /* opmtch */
#ifdef RECORD_GET
             if (v0204 != SPID_NOPROP)
                record_get(elt(fastget_names, 9), 1);
             else record_get(elt(fastget_names, 9), 0),
                v0204 = nil; }
           else record_get(elt(fastget_names, 9), 0); }
#else
             if (v0204 == SPID_NOPROP) v0204 = nil; }}
#endif
    if (v0204 == nil) goto v0096;
    v0204 = stack[-3];
    fn = elt(env, 15); /* opmtch!* */
    v0204 = (*qfn1(fn))(qenv(fn), v0204);
    nil = C_nil;
    if (exception_pending()) goto v0208;
    stack[-1] = v0204;
    if (v0204 == nil) goto v0096;
    v0204 = stack[-1];
    goto v0039;

v0096:
    v0204 = stack[-3];
    goto v0039;

v0021:
    v0204 = stack[-3];
    goto v0039;

v0116:
    v0204 = stack[-3];
    if (!consp(v0204)) goto v0164;
    v0204 = stack[-3];
    v0204 = qcar(v0204);
    stack[-4] = v0204;
    v0204 = stack[-3];
    v0204 = qcdr(v0204);
    stack[-2] = v0204;
    v0205 = stack[-4];
    v0204 = elt(env, 3); /* physopfunction */
    v0204 = get(v0205, v0204);
    env = stack[-5];
    stack[-1] = v0204;
    if (v0204 == nil) goto v0209;
    v0205 = stack[-4];
    v0204 = elt(env, 4); /* physoparith */
    v0204 = Lflagp(nil, v0205, v0204);
    env = stack[-5];
    if (v0204 == nil) goto v0158;
    v0204 = stack[-2];
    fn = elt(env, 16); /* hasonephysop */
    v0204 = (*qfn1(fn))(qenv(fn), v0204);
    nil = C_nil;
    if (exception_pending()) goto v0208;
    env = stack[-5];
    if (v0204 == nil) goto v0160;
    stack[0] = stack[-1];
    v0204 = stack[-2];
    v0204 = ncons(v0204);
    nil = C_nil;
    if (exception_pending()) goto v0208;
    env = stack[-5];
    fn = elt(env, 17); /* apply */
    v0204 = (*qfn2(fn))(qenv(fn), stack[0], v0204);
    nil = C_nil;
    if (exception_pending()) goto v0208;
    stack[0] = v0204;
    { Lisp_Object res = stack[0]; popv(6); return onevalue(res); }

v0160:
    v0205 = stack[-4];
    v0204 = stack[-2];
    v0204 = cons(v0205, v0204);
    nil = C_nil;
    if (exception_pending()) goto v0208;
    env = stack[-5];
    fn = elt(env, 18); /* reval3 */
    v0204 = (*qfn1(fn))(qenv(fn), v0204);
    nil = C_nil;
    if (exception_pending()) goto v0208;
    stack[0] = v0204;
    { Lisp_Object res = stack[0]; popv(6); return onevalue(res); }

v0158:
    v0205 = stack[-4];
    v0204 = elt(env, 5); /* physopfn */
    v0204 = Lflagp(nil, v0205, v0204);
    env = stack[-5];
    if (v0204 == nil) goto v0169;
    v0204 = stack[-2];
    fn = elt(env, 19); /* areallphysops */
    v0204 = (*qfn1(fn))(qenv(fn), v0204);
    nil = C_nil;
    if (exception_pending()) goto v0208;
    env = stack[-5];
    if (v0204 == nil) goto v0210;
    stack[0] = stack[-1];
    v0204 = stack[-2];
    v0204 = ncons(v0204);
    nil = C_nil;
    if (exception_pending()) goto v0208;
    env = stack[-5];
    fn = elt(env, 17); /* apply */
    v0204 = (*qfn2(fn))(qenv(fn), stack[0], v0204);
    nil = C_nil;
    if (exception_pending()) goto v0208;
    stack[0] = v0204;
    { Lisp_Object res = stack[0]; popv(6); return onevalue(res); }

v0210:
    stack[-1] = elt(env, 0); /* physopsm!* */
    v0207 = elt(env, 6); /* "invalid call of " */
    v0206 = stack[-4];
    v0205 = elt(env, 7); /* " with args: " */
    v0204 = stack[-2];
    v0204 = list4(v0207, v0206, v0205, v0204);
    nil = C_nil;
    if (exception_pending()) goto v0208;
    env = stack[-5];
    fn = elt(env, 20); /* rederr2 */
    v0204 = (*qfn2(fn))(qenv(fn), stack[-1], v0204);
    nil = C_nil;
    if (exception_pending()) goto v0208;
    { Lisp_Object res = stack[0]; popv(6); return onevalue(res); }

v0169:
    stack[-1] = elt(env, 0); /* physopsm!* */
    v0206 = stack[-4];
    v0205 = elt(env, 8); /* " has been flagged Physopfunction" */
    v0204 = elt(env, 9); /* " but is not defined" */
    v0204 = list3(v0206, v0205, v0204);
    nil = C_nil;
    if (exception_pending()) goto v0208;
    env = stack[-5];
    fn = elt(env, 20); /* rederr2 */
    v0204 = (*qfn2(fn))(qenv(fn), stack[-1], v0204);
    nil = C_nil;
    if (exception_pending()) goto v0208;
    { Lisp_Object res = stack[0]; popv(6); return onevalue(res); }

v0209:
    v0205 = stack[-4];
    v0204 = elt(env, 10); /* physopmapping */
    v0204 = Lflagp(nil, v0205, v0204);
    env = stack[-5];
    if (v0204 == nil) goto v0211;
    v0204 = stack[-2];
    fn = elt(env, 21); /* !*physopp!* */
    v0204 = (*qfn1(fn))(qenv(fn), v0204);
    nil = C_nil;
    if (exception_pending()) goto v0208;
    env = stack[-5];
    goto v0112;

v0112:
    if (v0204 == nil) goto v0212;
    v0205 = stack[-4];
    v0204 = stack[-2];
    v0205 = cons(v0205, v0204);
    nil = C_nil;
    if (exception_pending()) goto v0208;
    env = stack[-5];
    v0204 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 22); /* to */
    v0205 = (*qfn2(fn))(qenv(fn), v0205, v0204);
    nil = C_nil;
    if (exception_pending()) goto v0208;
    env = stack[-5];
    v0204 = (Lisp_Object)17; /* 1 */
    v0204 = cons(v0205, v0204);
    nil = C_nil;
    if (exception_pending()) goto v0208;
    env = stack[-5];
    v0205 = ncons(v0204);
    nil = C_nil;
    if (exception_pending()) goto v0208;
    env = stack[-5];
    v0204 = (Lisp_Object)17; /* 1 */
    v0204 = cons(v0205, v0204);
    nil = C_nil;
    if (exception_pending()) goto v0208;
    env = stack[-5];
    fn = elt(env, 23); /* mk!*sq */
    v0204 = (*qfn1(fn))(qenv(fn), v0204);
    nil = C_nil;
    if (exception_pending()) goto v0208;
    stack[0] = v0204;
    { Lisp_Object res = stack[0]; popv(6); return onevalue(res); }

v0212:
    v0205 = stack[-4];
    v0204 = elt(env, 12); /* prog */
    if (v0205 == v0204) goto v0213;
    v0204 = stack[-3];
    fn = elt(env, 24); /* aeval */
    v0204 = (*qfn1(fn))(qenv(fn), v0204);
    nil = C_nil;
    if (exception_pending()) goto v0208;
    stack[0] = v0204;
    { Lisp_Object res = stack[0]; popv(6); return onevalue(res); }

v0213:
    v0204 = stack[-2];
    fn = elt(env, 25); /* physopprog */
    v0204 = (*qfn1(fn))(qenv(fn), v0204);
    nil = C_nil;
    if (exception_pending()) goto v0208;
    stack[0] = v0204;
    { Lisp_Object res = stack[0]; popv(6); return onevalue(res); }

v0211:
    v0204 = qvalue(elt(env, 11)); /* nil */
    goto v0112;

v0164:
    v0204 = stack[-3];
    fn = elt(env, 24); /* aeval */
    v0204 = (*qfn1(fn))(qenv(fn), v0204);
    nil = C_nil;
    if (exception_pending()) goto v0208;
    stack[0] = v0204;
    { Lisp_Object res = stack[0]; popv(6); return onevalue(res); }

v0049:
    v0204 = qvalue(elt(env, 1)); /* t */
    goto v0023;
/* error exit handlers */
v0208:
    popv(6);
    return nil;
}



/* Code for mktails1 */

static Lisp_Object MS_CDECL CC_mktails1(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0082, v0083, v0081;
    Lisp_Object fn;
    Lisp_Object v0004, v0026, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "mktails1");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0026 = va_arg(aa, Lisp_Object);
    v0004 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mktails1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0004,v0026,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0026,v0004);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0004;
    v0082 = v0026;
    stack[-1] = v0000;
/* end of prologue */
    v0083 = stack[-1];
    fn = elt(env, 3); /* getroad */
    v0082 = (*qfn2(fn))(qenv(fn), v0083, v0082);
    nil = C_nil;
    if (exception_pending()) goto v0214;
    env = stack[-3];
    v0083 = v0082;
    v0081 = (Lisp_Object)1; /* 0 */
    v0082 = v0083;
    if (v0081 == v0082) goto v0039;
    v0081 = (Lisp_Object)1; /* 0 */
    v0082 = stack[-1];
    v0082 = qcdr(v0082);
    if (v0081 == v0082) goto v0175;
    v0081 = stack[-1];
    v0082 = stack[0];
    v0082 = Lassoc(nil, v0081, v0082);
    v0081 = v0082;
    v0082 = v0081;
    if (v0082 == nil) goto v0046;
    v0082 = v0081;
    v0082 = qcdr(v0082);
    v0082 = qcdr(v0082);
    if (v0082 == nil) goto v0126;
    v0082 = v0081;
    v0082 = qcdr(v0082);
    v0083 = Lreverse(nil, v0082);
    nil = C_nil;
    if (exception_pending()) goto v0214;
    v0082 = stack[0];
    popv(4);
    return cons(v0083, v0082);

v0126:
    v0082 = v0081;
    v0083 = qcdr(v0082);
    v0082 = stack[0];
    popv(4);
    return cons(v0083, v0082);

v0046:
    v0082 = stack[-1];
    fn = elt(env, 4); /* mkinds */
    v0082 = (*qfn2(fn))(qenv(fn), v0082, v0083);
    nil = C_nil;
    if (exception_pending()) goto v0214;
    env = stack[-3];
    v0081 = v0082;
    stack[-2] = v0081;
    v0082 = stack[-1];
    v0083 = v0081;
    v0083 = cons(v0082, v0083);
    nil = C_nil;
    if (exception_pending()) goto v0214;
    v0082 = stack[0];
    {
        Lisp_Object v0157 = stack[-2];
        popv(4);
        return list2star(v0157, v0083, v0082);
    }

v0175:
    v0082 = stack[-1];
    v0083 = qcar(v0082);
    v0082 = elt(env, 2); /* replace_by_vector */
    v0082 = get(v0083, v0082);
    env = stack[-3];
    if (!(v0082 == nil)) goto v0031;
    v0082 = stack[-1];
    v0082 = qcar(v0082);
    goto v0031;

v0031:
    v0083 = ncons(v0082);
    nil = C_nil;
    if (exception_pending()) goto v0214;
    v0082 = stack[0];
    popv(4);
    return cons(v0083, v0082);

v0039:
    v0083 = qvalue(elt(env, 1)); /* nil */
    v0082 = stack[0];
    popv(4);
    return cons(v0083, v0082);
/* error exit handlers */
v0214:
    popv(4);
    return nil;
}



/* Code for pairxvars */

static Lisp_Object MS_CDECL CC_pairxvars(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0179, v0134, v0215;
    Lisp_Object fn;
    Lisp_Object v0001, v0004, v0026, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "pairxvars");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0026 = va_arg(aa, Lisp_Object);
    v0004 = va_arg(aa, Lisp_Object);
    v0001 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pairxvars");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v0001,v0004,v0026,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0000,v0026,v0004,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-1] = v0001;
    stack[-2] = v0004;
    stack[-3] = v0026;
    stack[-4] = v0000;
/* end of prologue */
    stack[-5] = nil;
    goto v0009;

v0009:
    v0179 = stack[-4];
    if (v0179 == nil) goto v0006;
    v0179 = stack[-4];
    v0134 = qcar(v0179);
    v0179 = stack[-3];
    v0179 = Latsoc(nil, v0134, v0179);
    stack[0] = v0179;
    if (v0179 == nil) goto v0012;
    v0134 = stack[0];
    v0179 = stack[-3];
    v0179 = Ldelete(nil, v0134, v0179);
    nil = C_nil;
    if (exception_pending()) goto v0216;
    env = stack[-6];
    stack[-3] = v0179;
    v0179 = stack[0];
    v0134 = qcdr(v0179);
    v0179 = elt(env, 1); /* scalar */
    if (v0134 == v0179) goto v0139;
    v0179 = stack[-4];
    v0215 = qcar(v0179);
    v0179 = stack[0];
    v0134 = qcdr(v0179);
    v0179 = stack[-5];
    v0179 = acons(v0215, v0134, v0179);
    nil = C_nil;
    if (exception_pending()) goto v0216;
    env = stack[-6];
    stack[-5] = v0179;
    goto v0018;

v0018:
    v0179 = stack[-4];
    v0179 = qcdr(v0179);
    stack[-4] = v0179;
    goto v0009;

v0139:
    v0179 = stack[-4];
    v0215 = qcar(v0179);
    v0134 = stack[-1];
    v0179 = stack[-5];
    v0179 = acons(v0215, v0134, v0179);
    nil = C_nil;
    if (exception_pending()) goto v0216;
    env = stack[-6];
    stack[-5] = v0179;
    goto v0018;

v0012:
    v0179 = stack[-4];
    v0179 = qcar(v0179);
    if (symbolp(v0179)) goto v0180;
    v0179 = qvalue(elt(env, 2)); /* t */
    goto v0127;

v0127:
    if (v0179 == nil) goto v0130;
    v0134 = elt(env, 3); /* "Invalid parameter:" */
    v0179 = stack[-4];
    v0179 = qcar(v0179);
    v0134 = list2(v0134, v0179);
    nil = C_nil;
    if (exception_pending()) goto v0216;
    env = stack[-6];
    v0179 = qvalue(elt(env, 4)); /* nil */
    fn = elt(env, 5); /* symerr */
    v0179 = (*qfn2(fn))(qenv(fn), v0134, v0179);
    nil = C_nil;
    if (exception_pending()) goto v0216;
    env = stack[-6];
    goto v0018;

v0130:
    v0179 = stack[-4];
    v0215 = qcar(v0179);
    v0134 = stack[-1];
    v0179 = stack[-5];
    v0179 = acons(v0215, v0134, v0179);
    nil = C_nil;
    if (exception_pending()) goto v0216;
    env = stack[-6];
    stack[-5] = v0179;
    goto v0018;

v0180:
    v0179 = stack[-4];
    v0179 = qcar(v0179);
    if (!symbolp(v0179)) v0179 = nil;
    else { v0179 = qfastgets(v0179);
           if (v0179 != nil) { v0179 = elt(v0179, 23); /* infix */
#ifdef RECORD_GET
             if (v0179 != SPID_NOPROP)
                record_get(elt(fastget_names, 23), 1);
             else record_get(elt(fastget_names, 23), 0),
                v0179 = nil; }
           else record_get(elt(fastget_names, 23), 0); }
#else
             if (v0179 == SPID_NOPROP) v0179 = nil; }}
#endif
    if (!(v0179 == nil)) goto v0127;
    v0179 = stack[-4];
    v0179 = qcar(v0179);
    if (!symbolp(v0179)) v0179 = nil;
    else { v0179 = qfastgets(v0179);
           if (v0179 != nil) { v0179 = elt(v0179, 36); /* stat */
#ifdef RECORD_GET
             if (v0179 != SPID_NOPROP)
                record_get(elt(fastget_names, 36), 1);
             else record_get(elt(fastget_names, 36), 0),
                v0179 = nil; }
           else record_get(elt(fastget_names, 36), 0); }
#else
             if (v0179 == SPID_NOPROP) v0179 = nil; }}
#endif
    goto v0127;

v0006:
    v0179 = stack[-5];
    fn = elt(env, 6); /* reversip!* */
    v0134 = (*qfn1(fn))(qenv(fn), v0179);
    nil = C_nil;
    if (exception_pending()) goto v0216;
    env = stack[-6];
    v0179 = stack[-2];
    v0134 = Lappend(nil, v0134, v0179);
    nil = C_nil;
    if (exception_pending()) goto v0216;
    v0179 = stack[-3];
    popv(7);
    return cons(v0134, v0179);
/* error exit handlers */
v0216:
    popv(7);
    return nil;
}



/* Code for setel1 */

static Lisp_Object MS_CDECL CC_setel1(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0140, v0137, v0107;
    Lisp_Object fn;
    Lisp_Object v0001, v0004, v0026, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "setel1");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0026 = va_arg(aa, Lisp_Object);
    v0004 = va_arg(aa, Lisp_Object);
    v0001 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for setel1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v0001,v0004,v0026,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0000,v0026,v0004,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0001;
    stack[-1] = v0004;
    stack[-2] = v0026;
    stack[-3] = v0000;
/* end of prologue */

v0129:
    v0140 = stack[-2];
    v0140 = qcar(v0140);
    v0140 = integerp(v0140);
    if (v0140 == nil) goto v0117;
    v0140 = stack[-2];
    v0137 = qcar(v0140);
    v0140 = stack[0];
    v0140 = qcar(v0140);
    v0140 = (Lisp_Object)geq2(v0137, v0140);
    nil = C_nil;
    if (exception_pending()) goto v0091;
    v0140 = v0140 ? lisp_true : nil;
    env = stack[-4];
    if (!(v0140 == nil)) goto v0055;
    v0140 = stack[-2];
    v0137 = qcar(v0140);
    v0140 = (Lisp_Object)1; /* 0 */
    v0140 = (Lisp_Object)lessp2(v0137, v0140);
    nil = C_nil;
    if (exception_pending()) goto v0091;
    v0140 = v0140 ? lisp_true : nil;
    env = stack[-4];
    if (!(v0140 == nil)) goto v0055;
    v0140 = stack[-2];
    v0140 = qcdr(v0140);
    if (v0140 == nil) goto v0094;
    v0137 = stack[-3];
    v0140 = stack[-2];
    v0140 = qcar(v0140);
    v0140 = *(Lisp_Object *)((char *)v0137 + (CELL-TAG_VECTOR) + ((int32_t)v0140/(16/CELL)));
    stack[-3] = v0140;
    v0140 = stack[-2];
    v0140 = qcdr(v0140);
    stack[-2] = v0140;
    v0140 = stack[0];
    v0140 = qcdr(v0140);
    stack[0] = v0140;
    goto v0129;

v0094:
    v0107 = stack[-3];
    v0140 = stack[-2];
    v0137 = qcar(v0140);
    v0140 = stack[-1];
    *(Lisp_Object *)((char *)v0107 + (CELL-TAG_VECTOR) + ((int32_t)v0137/(16/CELL))) = v0140;
    { popv(5); return onevalue(v0140); }

v0055:
    v0107 = elt(env, 2); /* rlisp */
    v0137 = (Lisp_Object)369; /* 23 */
    v0140 = elt(env, 3); /* "Array out of bounds" */
    {
        popv(5);
        fn = elt(env, 4); /* rerror */
        return (*qfnn(fn))(qenv(fn), 3, v0107, v0137, v0140);
    }

v0117:
    v0140 = stack[-2];
    v0137 = qcar(v0140);
    v0140 = elt(env, 1); /* "array index" */
    {
        popv(5);
        fn = elt(env, 5); /* typerr */
        return (*qfn2(fn))(qenv(fn), v0137, v0140);
    }
/* error exit handlers */
v0091:
    popv(5);
    return nil;
}



/* Code for red!=cancelsimp */

static Lisp_Object CC_redMcancelsimp(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0026)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0099, v0051;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for red=cancelsimp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0026,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0026);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0026;
    stack[-1] = v0000;
/* end of prologue */
    v0051 = stack[-1];
    v0099 = stack[0];
    fn = elt(env, 2); /* red_better */
    v0099 = (*qfn2(fn))(qenv(fn), v0051, v0099);
    nil = C_nil;
    if (exception_pending()) goto v0019;
    env = stack[-2];
    if (v0099 == nil) goto v0044;
    v0099 = stack[-1];
    fn = elt(env, 3); /* bas_dpoly */
    v0099 = (*qfn1(fn))(qenv(fn), v0099);
    nil = C_nil;
    if (exception_pending()) goto v0019;
    env = stack[-2];
    fn = elt(env, 4); /* dp_lmon */
    stack[-1] = (*qfn1(fn))(qenv(fn), v0099);
    nil = C_nil;
    if (exception_pending()) goto v0019;
    env = stack[-2];
    v0099 = stack[0];
    fn = elt(env, 3); /* bas_dpoly */
    v0099 = (*qfn1(fn))(qenv(fn), v0099);
    nil = C_nil;
    if (exception_pending()) goto v0019;
    env = stack[-2];
    fn = elt(env, 4); /* dp_lmon */
    v0099 = (*qfn1(fn))(qenv(fn), v0099);
    nil = C_nil;
    if (exception_pending()) goto v0019;
    env = stack[-2];
    {
        Lisp_Object v0020 = stack[-1];
        popv(3);
        fn = elt(env, 5); /* mo_vdivides!? */
        return (*qfn2(fn))(qenv(fn), v0020, v0099);
    }

v0044:
    v0099 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v0099); }
/* error exit handlers */
v0019:
    popv(3);
    return nil;
}



/* Code for simp!-prop!-order */

static Lisp_Object CC_simpKpropKorder(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0026)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0104, v0149, v0170, v0030;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for simp-prop-order");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0149 = v0026;
    v0170 = v0000;
/* end of prologue */

v0044:
    v0104 = v0170;
    if (v0104 == nil) goto v0024;
    v0104 = v0170;
    v0104 = qcar(v0104);
    v0030 = qcar(v0104);
    v0104 = v0149;
    v0104 = qcar(v0104);
    v0104 = qcar(v0104);
    if (equal(v0030, v0104)) goto v0017;
    v0104 = v0170;
    v0104 = qcar(v0104);
    v0149 = qcar(v0104);
    v0104 = elt(env, 2); /* prop!* */
    if (v0149 == v0104) goto v0039;
    v0104 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v0104);

v0039:
    v0104 = qvalue(elt(env, 3)); /* t */
    return onevalue(v0104);

v0017:
    v0104 = v0170;
    v0104 = qcdr(v0104);
    v0170 = v0104;
    v0104 = v0149;
    v0104 = qcdr(v0104);
    v0149 = v0104;
    goto v0044;

v0024:
    v0104 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v0104);
}



/* Code for splitlist!: */

static Lisp_Object CC_splitlistT(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0026)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0038, v0047, v0098;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for splitlist:");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0026,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0026);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0026;
    stack[-1] = v0000;
/* end of prologue */
    v0098 = nil;
    goto v0143;

v0143:
    v0038 = stack[-1];
    if (v0038 == nil) goto v0009;
    v0038 = stack[-1];
    v0047 = qcar(v0038);
    v0038 = stack[0];
    if (!consp(v0047)) goto v0021;
    v0047 = qcar(v0047);
    if (!(v0047 == v0038)) goto v0021;
    v0038 = stack[-1];
    v0038 = qcar(v0038);
    v0047 = v0098;
    v0038 = cons(v0038, v0047);
    nil = C_nil;
    if (exception_pending()) goto v0149;
    env = stack[-2];
    v0098 = v0038;
    v0038 = stack[-1];
    v0038 = qcdr(v0038);
    stack[-1] = v0038;
    goto v0143;

v0021:
    v0038 = stack[-1];
    v0038 = qcdr(v0038);
    stack[-1] = v0038;
    goto v0143;

v0009:
    v0038 = v0098;
    {
        popv(3);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v0038);
    }
/* error exit handlers */
v0149:
    popv(3);
    return nil;
}



/* Code for innprodkp */

static Lisp_Object MS_CDECL CC_innprodkp(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0032, v0031, v0002;
    Lisp_Object fn;
    Lisp_Object v0001, v0004, v0026, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "innprodkp");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0026 = va_arg(aa, Lisp_Object);
    v0004 = va_arg(aa, Lisp_Object);
    v0001 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for innprodkp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v0001,v0004,v0026,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0000,v0026,v0004,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0001;
    stack[-1] = v0004;
    stack[-2] = v0026;
    v0031 = v0000;
/* end of prologue */

v0129:
    v0032 = stack[-1];
    if (v0032 == nil) goto v0128;
    v0002 = stack[-2];
    v0032 = stack[-1];
    v0032 = qcar(v0032);
    if (equal(v0002, v0032)) goto v0019;
    v0032 = stack[-1];
    v0032 = qcar(v0032);
    v0032 = cons(v0032, v0031);
    nil = C_nil;
    if (exception_pending()) goto v0146;
    env = stack[-3];
    v0031 = v0032;
    v0032 = stack[-1];
    v0032 = qcdr(v0032);
    stack[-1] = v0032;
    v0032 = stack[0];
    v0032 = (v0032 == nil ? lisp_true : nil);
    stack[0] = v0032;
    goto v0129;

v0019:
    v0032 = stack[-1];
    v0032 = qcdr(v0032);
    fn = elt(env, 2); /* reversip2 */
    v0032 = (*qfn2(fn))(qenv(fn), v0031, v0032);
    nil = C_nil;
    if (exception_pending()) goto v0146;
    {
        Lisp_Object v0094 = stack[0];
        popv(4);
        return cons(v0094, v0032);
    }

v0128:
    v0032 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v0032); }
/* error exit handlers */
v0146:
    popv(4);
    return nil;
}



/* Code for ibalp_readform */

static Lisp_Object CC_ibalp_readform(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0202, v0220;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ibalp_readform");
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
    push2(nil, nil);
/* copy arguments values to proper place */
    v0202 = v0000;
/* end of prologue */
    stack[-5] = nil;
    stack[-4] = nil;
    stack[-3] = nil;
    v0220 = (Lisp_Object)1; /* 0 */
    stack[0] = v0220;
    v0220 = v0202;
    v0202 = elt(env, 1); /* and */
    fn = elt(env, 9); /* cl_mkstrict */
    v0202 = (*qfn2(fn))(qenv(fn), v0220, v0202);
    nil = C_nil;
    if (exception_pending()) goto v0069;
    env = stack[-7];
    v0202 = qcdr(v0202);
    stack[-2] = v0202;
    v0202 = qvalue(elt(env, 2)); /* t */
    stack[-1] = v0202;
    goto v0011;

v0011:
    v0202 = stack[-1];
    if (v0202 == nil) goto v0116;
    v0202 = stack[-2];
    if (v0202 == nil) goto v0116;
    v0202 = stack[-2];
    v0202 = qcar(v0202);
    v0220 = v0202;
    v0202 = stack[-2];
    v0202 = qcdr(v0202);
    stack[-2] = v0202;
    v0202 = stack[-4];
    fn = elt(env, 10); /* ibalp_readclause */
    v0202 = (*qfn2(fn))(qenv(fn), v0220, v0202);
    nil = C_nil;
    if (exception_pending()) goto v0069;
    env = stack[-7];
    stack[-6] = v0202;
    v0202 = stack[-6];
    v0202 = qcar(v0202);
    stack[-3] = v0202;
    v0202 = stack[-6];
    v0202 = qcdr(v0202);
    stack[-4] = v0202;
    v0220 = stack[-3];
    v0202 = elt(env, 4); /* true */
    if (v0220 == v0202) goto v0011;
    v0202 = stack[-3];
    fn = elt(env, 11); /* ibalp_emptyclausep */
    v0202 = (*qfn1(fn))(qenv(fn), v0202);
    nil = C_nil;
    if (exception_pending()) goto v0069;
    env = stack[-7];
    if (v0202 == nil) goto v0139;
    v0202 = qvalue(elt(env, 3)); /* nil */
    stack[-1] = v0202;
    goto v0011;

v0139:
    v0220 = stack[-3];
    v0202 = stack[-5];
    fn = elt(env, 12); /* ibalp_clmember */
    v0202 = (*qfn2(fn))(qenv(fn), v0220, v0202);
    nil = C_nil;
    if (exception_pending()) goto v0069;
    env = stack[-7];
    if (!(v0202 == nil)) goto v0036;
    v0202 = stack[-3];
    fn = elt(env, 13); /* ibalp_redclause */
    v0202 = (*qfn1(fn))(qenv(fn), v0202);
    nil = C_nil;
    if (exception_pending()) goto v0069;
    env = stack[-7];
    if (!(v0202 == nil)) goto v0036;
    v0202 = stack[-6];
    v0220 = qcar(v0202);
    v0202 = stack[-5];
    v0202 = cons(v0220, v0202);
    nil = C_nil;
    if (exception_pending()) goto v0069;
    env = stack[-7];
    stack[-5] = v0202;
    goto v0011;

v0036:
    v0202 = stack[-3];
    fn = elt(env, 14); /* ibalp_undoclause */
    v0202 = (*qfn1(fn))(qenv(fn), v0202);
    nil = C_nil;
    if (exception_pending()) goto v0069;
    env = stack[-7];
    v0202 = stack[0];
    v0202 = add1(v0202);
    nil = C_nil;
    if (exception_pending()) goto v0069;
    env = stack[-7];
    stack[0] = v0202;
    goto v0011;

v0116:
    v0202 = stack[-1];
    if (v0202 == nil) goto v0161;
    v0202 = stack[-5];
    if (v0202 == nil) goto v0121;
    v0202 = qvalue(elt(env, 5)); /* !*rlverbose */
    if (v0202 == nil) goto v0156;
    v0220 = elt(env, 8); /* "Deleted redundant clauses: " */
    v0202 = stack[0];
    v0202 = list2(v0220, v0202);
    nil = C_nil;
    if (exception_pending()) goto v0069;
    env = stack[-7];
    fn = elt(env, 15); /* ioto_tprin2t */
    v0202 = (*qfn1(fn))(qenv(fn), v0202);
    nil = C_nil;
    if (exception_pending()) goto v0069;
    goto v0156;

v0156:
    v0220 = stack[-5];
    v0202 = stack[-4];
    popv(8);
    return cons(v0220, v0202);

v0121:
    v0202 = qvalue(elt(env, 5)); /* !*rlverbose */
    if (v0202 == nil) goto v0159;
    v0202 = elt(env, 7); /* "Tautology detected" */
    v0202 = ncons(v0202);
    nil = C_nil;
    if (exception_pending()) goto v0069;
    env = stack[-7];
    fn = elt(env, 15); /* ioto_tprin2t */
    v0202 = (*qfn1(fn))(qenv(fn), v0202);
    nil = C_nil;
    if (exception_pending()) goto v0069;
    env = stack[-7];
    goto v0159;

v0159:
    v0202 = qvalue(elt(env, 3)); /* nil */
    popv(8);
    return ncons(v0202);

v0161:
    v0202 = qvalue(elt(env, 5)); /* !*rlverbose */
    if (v0202 == nil) goto v0173;
    v0202 = elt(env, 6); /* "Detected empty clause" */
    v0202 = ncons(v0202);
    nil = C_nil;
    if (exception_pending()) goto v0069;
    env = stack[-7];
    fn = elt(env, 15); /* ioto_tprin2t */
    v0202 = (*qfn1(fn))(qenv(fn), v0202);
    nil = C_nil;
    if (exception_pending()) goto v0069;
    env = stack[-7];
    goto v0173;

v0173:
    v0202 = stack[-3];
    v0202 = ncons(v0202);
    nil = C_nil;
    if (exception_pending()) goto v0069;
    popv(8);
    return ncons(v0202);
/* error exit handlers */
v0069:
    popv(8);
    return nil;
}



/* Code for naryom */

static Lisp_Object CC_naryom(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0163, v0091;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for naryom");
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
    v0163 = stack[-1];
    v0163 = qcar(v0163);
    stack[0] = v0163;
    v0091 = stack[0];
    v0163 = elt(env, 1); /* var */
    if (!(v0091 == v0163)) goto v0005;
    v0163 = elt(env, 2); /* variance */
    stack[0] = v0163;
    goto v0005;

v0005:
    v0091 = stack[0];
    v0163 = qvalue(elt(env, 3)); /* valid_om!* */
    v0163 = Lassoc(nil, v0091, v0163);
    stack[-2] = v0163;
    v0163 = stack[-2];
    if (v0163 == nil) goto v0039;
    v0163 = stack[-2];
    v0163 = qcdr(v0163);
    v0163 = qcar(v0163);
    stack[-2] = v0163;
    goto v0039;

v0039:
    v0163 = stack[-1];
    v0163 = qcdr(v0163);
    v0163 = qcar(v0163);
    if (v0163 == nil) goto v0056;
    v0163 = stack[-1];
    v0163 = qcdr(v0163);
    v0091 = qcar(v0163);
    v0163 = elt(env, 4); /* multiset */
    if (!(v0091 == v0163)) goto v0056;
    v0163 = stack[-1];
    v0163 = qcdr(v0163);
    v0163 = qcar(v0163);
    stack[-2] = v0163;
    goto v0056;

v0056:
    v0163 = elt(env, 6); /* "<OMA>" */
    fn = elt(env, 12); /* printout */
    v0163 = (*qfn1(fn))(qenv(fn), v0163);
    nil = C_nil;
    if (exception_pending()) goto v0221;
    env = stack[-3];
    v0091 = qvalue(elt(env, 7)); /* indent */
    v0163 = (Lisp_Object)33; /* 2 */
    v0163 = plus2(v0091, v0163);
    nil = C_nil;
    if (exception_pending()) goto v0221;
    env = stack[-3];
    qvalue(elt(env, 7)) = v0163; /* indent */
    v0163 = elt(env, 8); /* "<OMS cd=""" */
    fn = elt(env, 12); /* printout */
    v0163 = (*qfn1(fn))(qenv(fn), v0163);
    nil = C_nil;
    if (exception_pending()) goto v0221;
    env = stack[-3];
    v0163 = stack[-2];
    v0163 = Lprinc(nil, v0163);
    nil = C_nil;
    if (exception_pending()) goto v0221;
    env = stack[-3];
    v0163 = elt(env, 9); /* """ name=""" */
    v0163 = Lprinc(nil, v0163);
    nil = C_nil;
    if (exception_pending()) goto v0221;
    env = stack[-3];
    v0163 = stack[0];
    v0163 = Lprinc(nil, v0163);
    nil = C_nil;
    if (exception_pending()) goto v0221;
    env = stack[-3];
    v0163 = elt(env, 10); /* """>" */
    v0163 = Lprinc(nil, v0163);
    nil = C_nil;
    if (exception_pending()) goto v0221;
    env = stack[-3];
    v0163 = stack[-1];
    v0163 = qcdr(v0163);
    v0163 = qcdr(v0163);
    fn = elt(env, 13); /* multiom */
    v0163 = (*qfn1(fn))(qenv(fn), v0163);
    nil = C_nil;
    if (exception_pending()) goto v0221;
    env = stack[-3];
    v0091 = qvalue(elt(env, 7)); /* indent */
    v0163 = (Lisp_Object)33; /* 2 */
    v0163 = difference2(v0091, v0163);
    nil = C_nil;
    if (exception_pending()) goto v0221;
    env = stack[-3];
    qvalue(elt(env, 7)) = v0163; /* indent */
    v0163 = elt(env, 11); /* "</OMA>" */
    fn = elt(env, 12); /* printout */
    v0163 = (*qfn1(fn))(qenv(fn), v0163);
    nil = C_nil;
    if (exception_pending()) goto v0221;
    v0163 = nil;
    { popv(4); return onevalue(v0163); }
/* error exit handlers */
v0221:
    popv(4);
    return nil;
}



/* Code for makeset */

static Lisp_Object CC_makeset(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0038, v0047, v0098;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for makeset");
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
    v0098 = nil;
    goto v0044;

v0044:
    v0038 = stack[0];
    if (v0038 == nil) goto v0024;
    v0038 = stack[0];
    v0047 = qcar(v0038);
    v0038 = stack[0];
    v0038 = qcdr(v0038);
    v0038 = Lmember(nil, v0047, v0038);
    if (v0038 == nil) goto v0099;
    v0038 = stack[0];
    v0038 = qcdr(v0038);
    stack[0] = v0038;
    goto v0044;

v0099:
    v0038 = stack[0];
    v0038 = qcar(v0038);
    v0047 = v0098;
    v0038 = cons(v0038, v0047);
    nil = C_nil;
    if (exception_pending()) goto v0104;
    env = stack[-1];
    v0098 = v0038;
    v0038 = stack[0];
    v0038 = qcdr(v0038);
    stack[0] = v0038;
    goto v0044;

v0024:
    v0038 = v0098;
    {
        popv(2);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v0038);
    }
/* error exit handlers */
v0104:
    popv(2);
    return nil;
}



/* Code for groedeletip */

static Lisp_Object CC_groedeletip(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0026)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0164, v0035;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for groedeletip");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0026,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0026);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0026;
    stack[-1] = v0000;
/* end of prologue */

v0024:
    v0164 = stack[0];
    if (v0164 == nil) goto v0129;
    v0035 = stack[-1];
    v0164 = stack[0];
    v0164 = qcar(v0164);
    if (!(equal(v0035, v0164))) goto v0129;
    v0164 = stack[0];
    v0164 = qcdr(v0164);
    stack[0] = v0164;
    goto v0024;

v0129:
    v0164 = stack[0];
    if (v0164 == nil) goto v0039;
    v0164 = stack[0];
    stack[-2] = v0164;
    goto v0021;

v0021:
    v0164 = stack[0];
    v0164 = qcdr(v0164);
    if (v0164 == nil) { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
    v0035 = stack[-1];
    v0164 = stack[0];
    v0164 = qcdr(v0164);
    v0164 = qcar(v0164);
    if (equal(v0035, v0164)) goto v0119;
    v0164 = stack[0];
    v0164 = qcdr(v0164);
    stack[0] = v0164;
    goto v0021;

v0119:
    v0035 = stack[0];
    v0164 = stack[0];
    v0164 = qcdr(v0164);
    v0164 = qcdr(v0164);
    fn = elt(env, 2); /* setcdr */
    v0164 = (*qfn2(fn))(qenv(fn), v0035, v0164);
    nil = C_nil;
    if (exception_pending()) goto v0008;
    env = stack[-3];
    goto v0021;

v0039:
    v0164 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v0164); }
/* error exit handlers */
v0008:
    popv(4);
    return nil;
}



/* Code for physopordchk */

static Lisp_Object CC_physopordchk(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0026)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0002, v0119, v0175;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for physopordchk");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0026,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0026);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0026;
    v0002 = v0000;
/* end of prologue */
    fn = elt(env, 4); /* !*collectphysops */
    v0002 = (*qfn1(fn))(qenv(fn), v0002);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    env = stack[-2];
    fn = elt(env, 5); /* deletemult!* */
    v0002 = (*qfn1(fn))(qenv(fn), v0002);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    env = stack[-2];
    stack[-1] = v0002;
    v0002 = stack[0];
    fn = elt(env, 4); /* !*collectphysops */
    v0002 = (*qfn1(fn))(qenv(fn), v0002);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    env = stack[-2];
    fn = elt(env, 5); /* deletemult!* */
    v0002 = (*qfn1(fn))(qenv(fn), v0002);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    env = stack[-2];
    v0175 = v0002;
    v0002 = stack[-1];
    if (v0002 == nil) goto v0133;
    v0002 = v0175;
    if (v0002 == nil) goto v0006;
    v0119 = elt(env, 3); /* unit */
    v0002 = stack[-1];
    v0002 = Lmember(nil, v0119, v0002);
    if (!(v0002 == nil)) goto v0011;
    v0119 = elt(env, 3); /* unit */
    v0002 = v0175;
    v0002 = Lmember(nil, v0119, v0002);
    if (!(v0002 == nil)) goto v0011;
    v0002 = stack[-1];
    v0119 = v0175;
    {
        popv(3);
        fn = elt(env, 6); /* physopordchk!* */
        return (*qfn2(fn))(qenv(fn), v0002, v0119);
    }

v0011:
    v0002 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v0002); }

v0006:
    v0002 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v0002); }

v0133:
    v0002 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v0002); }
/* error exit handlers */
v0094:
    popv(3);
    return nil;
}



/* Code for set!-global!-mode */

static Lisp_Object CC_setKglobalKmode(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0011;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for set-global-mode");
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
    v0011 = qvalue(elt(env, 1)); /* nil */
    v0011 = ncons(v0011);
    nil = C_nil;
    if (exception_pending()) goto v0051;
    env = stack[-4];
    qvalue(elt(env, 2)) = v0011; /* alglist!* */
    v0011 = stack[-2];
    qvalue(elt(env, 3)) = v0011; /* !*mode */
    stack[-3] = elt(env, 4); /* null */
    stack[-1] = elt(env, 5); /* setq */
    stack[0] = elt(env, 3); /* !*mode */
    v0011 = stack[-2];
    v0011 = Lmkquote(nil, v0011);
    nil = C_nil;
    if (exception_pending()) goto v0051;
    env = stack[-4];
    v0011 = list3(stack[-1], stack[0], v0011);
    nil = C_nil;
    if (exception_pending()) goto v0051;
    {
        Lisp_Object v0012 = stack[-3];
        popv(5);
        return list2(v0012, v0011);
    }
/* error exit handlers */
v0051:
    popv(5);
    return nil;
}



/* Code for scalprod */

static Lisp_Object CC_scalprod(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0026)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0007, v0008, v0139;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for scalprod");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0026,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0026);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0026;
    stack[-1] = v0000;
/* end of prologue */
    v0007 = stack[-1];
    if (v0007 == nil) goto v0009;
    v0007 = qvalue(elt(env, 1)); /* nil */
    goto v0024;

v0024:
    if (v0007 == nil) goto v0143;
    v0008 = qvalue(elt(env, 1)); /* nil */
    v0007 = (Lisp_Object)17; /* 1 */
    popv(4);
    return cons(v0008, v0007);

v0143:
    v0007 = stack[-1];
    if (v0007 == nil) goto v0039;
    v0007 = stack[0];
    v0007 = (v0007 == nil ? lisp_true : nil);
    goto v0040;

v0040:
    if (v0007 == nil) goto v0002;
    v0139 = elt(env, 3); /* matrix */
    v0008 = (Lisp_Object)145; /* 9 */
    v0007 = elt(env, 4); /* "Matrix mismatch" */
    {
        popv(4);
        fn = elt(env, 5); /* rerror */
        return (*qfnn(fn))(qenv(fn), 3, v0139, v0008, v0007);
    }

v0002:
    v0007 = stack[-1];
    v0008 = qcar(v0007);
    v0007 = stack[0];
    v0007 = qcar(v0007);
    fn = elt(env, 6); /* multsq */
    stack[-2] = (*qfn2(fn))(qenv(fn), v0008, v0007);
    nil = C_nil;
    if (exception_pending()) goto v0093;
    env = stack[-3];
    v0007 = stack[-1];
    v0008 = qcdr(v0007);
    v0007 = stack[0];
    v0007 = qcdr(v0007);
    v0007 = CC_scalprod(env, v0008, v0007);
    nil = C_nil;
    if (exception_pending()) goto v0093;
    env = stack[-3];
    {
        Lisp_Object v0092 = stack[-2];
        popv(4);
        fn = elt(env, 7); /* addsq */
        return (*qfn2(fn))(qenv(fn), v0092, v0007);
    }

v0039:
    v0007 = qvalue(elt(env, 2)); /* t */
    goto v0040;

v0009:
    v0007 = stack[0];
    v0007 = (v0007 == nil ? lisp_true : nil);
    goto v0024;
/* error exit handlers */
v0093:
    popv(4);
    return nil;
}



/* Code for mo_equal!? */

static Lisp_Object CC_mo_equalW(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0026)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0049;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mo_equal?");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0026,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0026);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0026;
    v0049 = v0000;
/* end of prologue */
    v0049 = qcar(v0049);
    fn = elt(env, 1); /* mo!=shorten */
    stack[-1] = (*qfn1(fn))(qenv(fn), v0049);
    nil = C_nil;
    if (exception_pending()) goto v0133;
    env = stack[-2];
    v0049 = stack[0];
    v0049 = qcar(v0049);
    fn = elt(env, 1); /* mo!=shorten */
    v0049 = (*qfn1(fn))(qenv(fn), v0049);
    nil = C_nil;
    if (exception_pending()) goto v0133;
    v0049 = (equal(stack[-1], v0049) ? lisp_true : nil);
    { popv(3); return onevalue(v0049); }
/* error exit handlers */
v0133:
    popv(3);
    return nil;
}



/* Code for resimpf */

static Lisp_Object CC_resimpf(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0025, v0023;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for resimpf");
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
    v0025 = qvalue(elt(env, 1)); /* nil */
    stack[0] = qvalue(elt(env, 2)); /* varstack!* */
    qvalue(elt(env, 2)) = v0025; /* varstack!* */
    v0025 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 3); /* subf1 */
    v0025 = (*qfn2(fn))(qenv(fn), v0023, v0025);
    nil = C_nil;
    if (exception_pending()) goto v0117;
    env = stack[-1];
    v0025 = qcar(v0025);
    qvalue(elt(env, 2)) = stack[0]; /* varstack!* */
    { popv(2); return onevalue(v0025); }
/* error exit handlers */
v0117:
    env = stack[-1];
    qvalue(elt(env, 2)) = stack[0]; /* varstack!* */
    popv(2);
    return nil;
}



/* Code for general!-modular!-expt */

static Lisp_Object CC_generalKmodularKexpt(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0026)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0154, v0224, v0225;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for general-modular-expt");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0026,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0026);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0026;
    stack[-1] = v0000;
/* end of prologue */

v0128:
    v0224 = stack[-1];
    v0154 = (Lisp_Object)1; /* 0 */
    if (v0224 == v0154) goto v0016;
    v0224 = stack[0];
    v0154 = (Lisp_Object)1; /* 0 */
    if (v0224 == v0154) goto v0098;
    v0224 = stack[0];
    v0154 = (Lisp_Object)17; /* 1 */
    if (v0224 == v0154) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    stack[-2] = stack[0];
    v0154 = qvalue(elt(env, 3)); /* current!-modulus */
    v0154 = sub1(v0154);
    nil = C_nil;
    if (exception_pending()) goto v0226;
    env = stack[-3];
    v0154 = (Lisp_Object)geq2(stack[-2], v0154);
    nil = C_nil;
    if (exception_pending()) goto v0226;
    v0154 = v0154 ? lisp_true : nil;
    env = stack[-3];
    if (v0154 == nil) goto v0163;
    v0154 = qvalue(elt(env, 3)); /* current!-modulus */
    fn = elt(env, 5); /* primep */
    v0154 = (*qfn1(fn))(qenv(fn), v0154);
    nil = C_nil;
    if (exception_pending()) goto v0226;
    env = stack[-3];
    if (v0154 == nil) goto v0163;
    v0154 = qvalue(elt(env, 3)); /* current!-modulus */
    v0154 = sub1(v0154);
    nil = C_nil;
    if (exception_pending()) goto v0226;
    env = stack[-3];
    v0154 = Cremainder(stack[0], v0154);
    nil = C_nil;
    if (exception_pending()) goto v0226;
    env = stack[-3];
    stack[0] = v0154;
    goto v0128;

v0163:
    v0154 = stack[0];
    v0154 = Levenp(nil, v0154);
    env = stack[-3];
    if (v0154 == nil) goto v0045;
    v0224 = stack[0];
    v0154 = (Lisp_Object)33; /* 2 */
    v0154 = quot2(v0224, v0154);
    nil = C_nil;
    if (exception_pending()) goto v0226;
    env = stack[-3];
    stack[0] = v0154;
    v0224 = stack[-1];
    v0154 = stack[-1];
    fn = elt(env, 6); /* general!-modular!-times */
    v0154 = (*qfn2(fn))(qenv(fn), v0224, v0154);
    nil = C_nil;
    if (exception_pending()) goto v0226;
    env = stack[-3];
    stack[-1] = v0154;
    goto v0163;

v0045:
    v0154 = stack[0];
    fn = elt(env, 7); /* reverse!-num */
    v0154 = (*qfn1(fn))(qenv(fn), v0154);
    nil = C_nil;
    if (exception_pending()) goto v0226;
    env = stack[-3];
    stack[0] = v0154;
    v0154 = (Lisp_Object)17; /* 1 */
    stack[-2] = v0154;
    goto v0131;

v0131:
    v0224 = stack[0];
    v0154 = (Lisp_Object)1; /* 0 */
    v0154 = (Lisp_Object)greaterp2(v0224, v0154);
    nil = C_nil;
    if (exception_pending()) goto v0226;
    v0154 = v0154 ? lisp_true : nil;
    env = stack[-3];
    if (v0154 == nil) { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
    v0224 = stack[-2];
    v0154 = stack[-2];
    fn = elt(env, 6); /* general!-modular!-times */
    v0154 = (*qfn2(fn))(qenv(fn), v0224, v0154);
    nil = C_nil;
    if (exception_pending()) goto v0226;
    env = stack[-3];
    stack[-2] = v0154;
    v0154 = stack[0];
    v0154 = Levenp(nil, v0154);
    env = stack[-3];
    if (!(v0154 == nil)) goto v0227;
    v0224 = stack[-2];
    v0154 = stack[-1];
    fn = elt(env, 6); /* general!-modular!-times */
    v0154 = (*qfn2(fn))(qenv(fn), v0224, v0154);
    nil = C_nil;
    if (exception_pending()) goto v0226;
    env = stack[-3];
    stack[-2] = v0154;
    goto v0227;

v0227:
    v0224 = stack[0];
    v0154 = (Lisp_Object)33; /* 2 */
    v0154 = quot2(v0224, v0154);
    nil = C_nil;
    if (exception_pending()) goto v0226;
    env = stack[-3];
    stack[0] = v0154;
    goto v0131;

v0098:
    v0154 = (Lisp_Object)17; /* 1 */
    { popv(4); return onevalue(v0154); }

v0016:
    v0224 = stack[0];
    v0154 = (Lisp_Object)1; /* 0 */
    if (v0224 == v0154) goto v0039;
    v0154 = (Lisp_Object)1; /* 0 */
    { popv(4); return onevalue(v0154); }

v0039:
    v0225 = elt(env, 1); /* alg */
    v0224 = (Lisp_Object)1617; /* 101 */
    v0154 = elt(env, 2); /* "0^0 formed" */
    {
        popv(4);
        fn = elt(env, 8); /* rerror */
        return (*qfnn(fn))(qenv(fn), 3, v0225, v0224, v0154);
    }
/* error exit handlers */
v0226:
    popv(4);
    return nil;
}



/* Code for gf2cr!: */

static Lisp_Object CC_gf2crT(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0171;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for gf2cr:");
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
    stack[-2] = elt(env, 1); /* !:cr!: */
    v0171 = stack[-1];
    v0171 = qcar(v0171);
    fn = elt(env, 2); /* striptag */
    stack[0] = (*qfn1(fn))(qenv(fn), v0171);
    nil = C_nil;
    if (exception_pending()) goto v0016;
    env = stack[-3];
    v0171 = stack[-1];
    v0171 = qcdr(v0171);
    fn = elt(env, 2); /* striptag */
    v0171 = (*qfn1(fn))(qenv(fn), v0171);
    nil = C_nil;
    if (exception_pending()) goto v0016;
    {
        Lisp_Object v0006 = stack[-2];
        Lisp_Object v0052 = stack[0];
        popv(4);
        return list2star(v0006, v0052, v0171);
    }
/* error exit handlers */
v0016:
    popv(4);
    return nil;
}



/* Code for build!-null!-vector */

static Lisp_Object MS_CDECL CC_buildKnullKvector(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0097, v0095, v0164, v0035, v0036, v0029, v0007, v0008;
    Lisp_Object v0004, v0026, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "build-null-vector");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0026 = va_arg(aa, Lisp_Object);
    v0004 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for build-null-vector");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0036 = v0004;
    v0029 = v0026;
    v0007 = v0000;
/* end of prologue */
    v0097 = (Lisp_Object)17; /* 1 */
    v0008 = v0097;
    goto v0049;

v0049:
    v0097 = v0007;
    v0095 = (Lisp_Object)((int32_t)(v0097) - 0x10);
    v0097 = v0008;
    v0097 = (Lisp_Object)(int32_t)((int32_t)v0095 - (int32_t)v0097 + TAG_FIXNUM);
    v0097 = ((intptr_t)(v0097) < 0 ? lisp_true : nil);
    if (v0097 == nil) goto v0011;
    v0164 = v0029;
    v0095 = v0007;
    v0097 = (Lisp_Object)17; /* 1 */
    *(Lisp_Object *)((char *)v0164 + (CELL-TAG_VECTOR) + ((int32_t)v0095/(16/CELL))) = v0097;
    v0097 = v0029;
    v0095 = v0007;
    return cons(v0097, v0095);

v0011:
    v0035 = v0029;
    v0164 = v0008;
    v0095 = v0036;
    v0097 = v0008;
    v0095 = *(Lisp_Object *)((char *)v0095 + (CELL-TAG_VECTOR) + ((int32_t)v0097/(16/CELL)));
    v0097 = v0007;
    v0097 = *(Lisp_Object *)((char *)v0095 + (CELL-TAG_VECTOR) + ((int32_t)v0097/(16/CELL)));
    *(Lisp_Object *)((char *)v0035 + (CELL-TAG_VECTOR) + ((int32_t)v0164/(16/CELL))) = v0097;
    v0097 = v0008;
    v0097 = (Lisp_Object)((int32_t)(v0097) + 0x10);
    v0008 = v0097;
    goto v0049;
}



/* Code for ofsf_sippsubst */

static Lisp_Object CC_ofsf_sippsubst(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0026)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0041, v0005, v0016;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ofsf_sippsubst");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0005 = v0026;
    v0016 = v0000;
/* end of prologue */
    v0041 = v0005;
    if (v0041 == nil) return onevalue(v0016);
    v0041 = v0016;
    {
        fn = elt(env, 1); /* ofsf_sippsubst1 */
        return (*qfn2(fn))(qenv(fn), v0041, v0005);
    }
}



/* Code for cl_susiupdknowl1 */

static Lisp_Object MS_CDECL CC_cl_susiupdknowl1(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0032, v0031, v0002;
    Lisp_Object fn;
    Lisp_Object v0001, v0004, v0026, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "cl_susiupdknowl1");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0026 = va_arg(aa, Lisp_Object);
    v0004 = va_arg(aa, Lisp_Object);
    v0001 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for cl_susiupdknowl1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v0001,v0004,v0026,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0000,v0026,v0004,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0001;
    stack[-1] = v0004;
    v0002 = v0026;
    v0032 = v0000;
/* end of prologue */
    v0031 = v0032;
    v0032 = elt(env, 1); /* and */
    if (v0031 == v0032) goto v0116;
    v0032 = v0002;
    fn = elt(env, 2); /* rl_negateat */
    v0031 = (*qfn1(fn))(qenv(fn), v0032);
    nil = C_nil;
    if (exception_pending()) goto v0003;
    env = stack[-2];
    v0032 = stack[0];
    v0002 = cons(v0031, v0032);
    nil = C_nil;
    if (exception_pending()) goto v0003;
    env = stack[-2];
    v0031 = stack[-1];
    v0032 = stack[0];
    {
        popv(3);
        fn = elt(env, 3); /* cl_susiupdknowl2 */
        return (*qfnn(fn))(qenv(fn), 3, v0002, v0031, v0032);
    }

v0116:
    v0031 = v0002;
    v0032 = stack[0];
    v0002 = cons(v0031, v0032);
    nil = C_nil;
    if (exception_pending()) goto v0003;
    env = stack[-2];
    v0031 = stack[-1];
    v0032 = stack[0];
    {
        popv(3);
        fn = elt(env, 3); /* cl_susiupdknowl2 */
        return (*qfnn(fn))(qenv(fn), 3, v0002, v0031, v0032);
    }
/* error exit handlers */
v0003:
    popv(3);
    return nil;
}



/* Code for ibalp_var!-unset */

static Lisp_Object CC_ibalp_varKunset(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0026)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0073, v0074;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ibalp_var-unset");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0026,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0026);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-3] = v0026;
    stack[-4] = v0000;
/* end of prologue */
    v0073 = stack[-4];
    v0074 = qcdr(v0073);
    v0073 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 2); /* setcar */
    v0073 = (*qfn2(fn))(qenv(fn), v0074, v0073);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-6];
    v0073 = stack[-4];
    v0073 = qcdr(v0073);
    v0073 = qcdr(v0073);
    v0073 = qcdr(v0073);
    v0073 = qcdr(v0073);
    v0073 = qcdr(v0073);
    v0074 = qcdr(v0073);
    v0073 = (Lisp_Object)-15; /* -1 */
    fn = elt(env, 2); /* setcar */
    v0073 = (*qfn2(fn))(qenv(fn), v0074, v0073);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-6];
    v0073 = stack[-4];
    v0073 = qcdr(v0073);
    v0073 = qcdr(v0073);
    v0073 = qcdr(v0073);
    v0073 = qcdr(v0073);
    v0073 = qcdr(v0073);
    v0073 = qcdr(v0073);
    v0074 = qcdr(v0073);
    v0073 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 2); /* setcar */
    v0073 = (*qfn2(fn))(qenv(fn), v0074, v0073);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-6];
    v0073 = stack[-4];
    v0073 = qcar(v0073);
    stack[-5] = v0073;
    v0074 = stack[-3];
    v0073 = (Lisp_Object)17; /* 1 */
    v0073 = Leqn(nil, v0074, v0073);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-6];
    if (v0073 == nil) goto v0014;
    v0073 = stack[-4];
    v0073 = qcdr(v0073);
    v0073 = qcdr(v0073);
    v0073 = qcdr(v0073);
    v0073 = qcar(v0073);
    goto v0048;

v0048:
    stack[-2] = v0073;
    goto v0036;

v0036:
    v0073 = stack[-2];
    if (v0073 == nil) goto v0158;
    v0073 = stack[-2];
    v0073 = qcar(v0073);
    stack[-1] = v0073;
    v0074 = stack[-3];
    v0073 = (Lisp_Object)17; /* 1 */
    v0073 = Leqn(nil, v0074, v0073);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-6];
    if (v0073 == nil) goto v0223;
    v0073 = stack[-1];
    v0073 = qcdr(v0073);
    v0073 = qcdr(v0073);
    stack[0] = qcdr(v0073);
    v0073 = stack[-1];
    v0073 = qcdr(v0073);
    v0073 = qcdr(v0073);
    v0073 = qcdr(v0073);
    v0073 = qcar(v0073);
    v0073 = add1(v0073);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-6];
    fn = elt(env, 2); /* setcar */
    v0073 = (*qfn2(fn))(qenv(fn), stack[0], v0073);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-6];
    goto v0042;

v0042:
    v0073 = stack[-2];
    v0073 = qcdr(v0073);
    stack[-2] = v0073;
    goto v0036;

v0223:
    v0073 = stack[-1];
    v0073 = qcdr(v0073);
    stack[0] = qcdr(v0073);
    v0073 = stack[-1];
    v0073 = qcdr(v0073);
    v0073 = qcdr(v0073);
    v0073 = qcar(v0073);
    v0073 = add1(v0073);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-6];
    fn = elt(env, 2); /* setcar */
    v0073 = (*qfn2(fn))(qenv(fn), stack[0], v0073);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-6];
    goto v0042;

v0158:
    v0074 = stack[-3];
    v0073 = (Lisp_Object)1; /* 0 */
    v0073 = Leqn(nil, v0074, v0073);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-6];
    if (v0073 == nil) goto v0155;
    v0073 = stack[-4];
    v0073 = qcdr(v0073);
    v0073 = qcdr(v0073);
    v0073 = qcdr(v0073);
    v0073 = qcar(v0073);
    goto v0201;

v0201:
    v0074 = v0073;
    v0073 = stack[-5];
    fn = elt(env, 3); /* ibalp_unvar!-unsatlist */
    v0073 = (*qfn2(fn))(qenv(fn), v0074, v0073);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-6];
    v0073 = stack[-4];
    v0073 = qcdr(v0073);
    v0073 = qcdr(v0073);
    v0073 = qcdr(v0073);
    v0073 = qcdr(v0073);
    v0073 = qcdr(v0073);
    v0073 = qcdr(v0073);
    v0073 = qcdr(v0073);
    v0073 = qcdr(v0073);
    v0073 = qcdr(v0073);
    v0073 = qcdr(v0073);
    stack[0] = qcdr(v0073);
    v0073 = stack[-4];
    fn = elt(env, 4); /* ibalp_calcmom */
    v0073 = (*qfn1(fn))(qenv(fn), v0073);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-6];
    fn = elt(env, 2); /* setcar */
    v0073 = (*qfn2(fn))(qenv(fn), stack[0], v0073);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    v0073 = nil;
    { popv(7); return onevalue(v0073); }

v0155:
    v0073 = stack[-4];
    v0073 = qcdr(v0073);
    v0073 = qcdr(v0073);
    v0073 = qcar(v0073);
    goto v0201;

v0014:
    v0073 = stack[-4];
    v0073 = qcdr(v0073);
    v0073 = qcdr(v0073);
    v0073 = qcar(v0073);
    goto v0048;
/* error exit handlers */
v0193:
    popv(7);
    return nil;
}



/* Code for vsl_boundtype */

static Lisp_Object CC_vsl_boundtype(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0026)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0025, v0023;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for vsl_boundtype");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0025 = v0026;
    v0023 = v0000;
/* end of prologue */
    v0023 = qcdr(v0023);
    v0023 = qcar(v0023);
    {
        fn = elt(env, 1); /* vsl_boundtype1 */
        return (*qfn2(fn))(qenv(fn), v0023, v0025);
    }
}



/* Code for my_letmtr */

static Lisp_Object MS_CDECL CC_my_letmtr(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0201, v0202, v0220;
    Lisp_Object fn;
    Lisp_Object v0004, v0026, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "my_letmtr");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0026 = va_arg(aa, Lisp_Object);
    v0004 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for my_letmtr");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0004,v0026,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0026,v0004);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-3] = v0004;
    stack[-4] = v0026;
    stack[-5] = v0000;
/* end of prologue */
    stack[-2] = nil;
    v0202 = stack[-3];
    v0201 = elt(env, 1); /* mat */
    if (!consp(v0202)) goto v0005;
    v0202 = qcar(v0202);
    if (!(v0202 == v0201)) goto v0005;
    v0201 = stack[-5];
    v0201 = qcdr(v0201);
    stack[-6] = v0201;
    v0201 = stack[-6];
    if (v0201 == nil) goto v0119;
    v0201 = stack[-6];
    v0201 = qcar(v0201);
    v0202 = v0201;
    v0201 = v0202;
    v0201 = integerp(v0201);
    if (v0201 == nil) goto v0035;
    v0201 = v0202;
    goto v0034;

v0034:
    v0201 = ncons(v0201);
    nil = C_nil;
    if (exception_pending()) goto v0069;
    env = stack[-7];
    stack[-1] = v0201;
    stack[-2] = v0201;
    goto v0058;

v0058:
    v0201 = stack[-6];
    v0201 = qcdr(v0201);
    stack[-6] = v0201;
    v0201 = stack[-6];
    if (v0201 == nil) goto v0177;
    stack[0] = stack[-1];
    v0201 = stack[-6];
    v0201 = qcar(v0201);
    v0202 = v0201;
    v0201 = v0202;
    v0201 = integerp(v0201);
    if (v0201 == nil) goto v0086;
    v0201 = v0202;
    goto v0176;

v0176:
    v0201 = ncons(v0201);
    nil = C_nil;
    if (exception_pending()) goto v0069;
    env = stack[-7];
    v0201 = Lrplacd(nil, stack[0], v0201);
    nil = C_nil;
    if (exception_pending()) goto v0069;
    env = stack[-7];
    v0201 = stack[-1];
    v0201 = qcdr(v0201);
    stack[-1] = v0201;
    goto v0058;

v0086:
    v0201 = v0202;
    fn = elt(env, 8); /* reval */
    v0201 = (*qfn1(fn))(qenv(fn), v0201);
    nil = C_nil;
    if (exception_pending()) goto v0069;
    env = stack[-7];
    goto v0176;

v0177:
    v0201 = stack[-2];
    goto v0057;

v0057:
    stack[-2] = v0201;
    fn = elt(env, 9); /* numlis */
    v0201 = (*qfn1(fn))(qenv(fn), v0201);
    nil = C_nil;
    if (exception_pending()) goto v0069;
    env = stack[-7];
    if (v0201 == nil) goto v0149;
    v0201 = stack[-2];
    v0202 = Llength(nil, v0201);
    nil = C_nil;
    if (exception_pending()) goto v0069;
    env = stack[-7];
    v0201 = (Lisp_Object)33; /* 2 */
    v0201 = Lneq(nil, v0202, v0201);
    nil = C_nil;
    if (exception_pending()) goto v0069;
    env = stack[-7];
    goto v0104;

v0104:
    if (v0201 == nil) goto v0134;
    v0202 = stack[-5];
    v0201 = elt(env, 7); /* hold */
    {
        popv(8);
        fn = elt(env, 10); /* errpri2 */
        return (*qfn2(fn))(qenv(fn), v0202, v0201);
    }

v0134:
    v0201 = stack[-3];
    v0202 = qcdr(v0201);
    v0201 = stack[-2];
    v0201 = qcar(v0201);
    fn = elt(env, 11); /* nth */
    v0202 = (*qfn2(fn))(qenv(fn), v0202, v0201);
    nil = C_nil;
    if (exception_pending()) goto v0069;
    env = stack[-7];
    v0201 = stack[-2];
    v0201 = qcdr(v0201);
    v0201 = qcar(v0201);
    fn = elt(env, 12); /* pnth */
    v0202 = (*qfn2(fn))(qenv(fn), v0202, v0201);
    nil = C_nil;
    if (exception_pending()) goto v0069;
    env = stack[-7];
    v0201 = stack[-4];
    v0201 = Lrplaca(nil, v0202, v0201);
    nil = C_nil;
    if (exception_pending()) goto v0069;
    v0201 = nil;
    { popv(8); return onevalue(v0201); }

v0149:
    v0201 = qvalue(elt(env, 6)); /* t */
    goto v0104;

v0035:
    v0201 = v0202;
    fn = elt(env, 8); /* reval */
    v0201 = (*qfn1(fn))(qenv(fn), v0201);
    nil = C_nil;
    if (exception_pending()) goto v0069;
    env = stack[-7];
    goto v0034;

v0119:
    v0201 = qvalue(elt(env, 5)); /* nil */
    goto v0057;

v0005:
    stack[-1] = elt(env, 2); /* matrix */
    stack[0] = (Lisp_Object)161; /* 10 */
    v0220 = elt(env, 3); /* "Matrix" */
    v0201 = stack[-5];
    v0202 = qcar(v0201);
    v0201 = elt(env, 4); /* "not set" */
    v0201 = list3(v0220, v0202, v0201);
    nil = C_nil;
    if (exception_pending()) goto v0069;
    env = stack[-7];
    fn = elt(env, 13); /* rerror */
    v0201 = (*qfnn(fn))(qenv(fn), 3, stack[-1], stack[0], v0201);
    nil = C_nil;
    if (exception_pending()) goto v0069;
    env = stack[-7];
    goto v0134;
/* error exit handlers */
v0069:
    popv(8);
    return nil;
}



/* Code for xlcm */

static Lisp_Object CC_xlcm(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0026)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0120, v0085;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for xlcm");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0026,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0026);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0026;
    stack[-1] = v0000;
/* end of prologue */
    stack[-2] = nil;
    goto v0143;

v0143:
    v0120 = stack[-1];
    if (v0120 == nil) goto v0025;
    v0120 = stack[-1];
    v0085 = qcar(v0120);
    v0120 = (Lisp_Object)17; /* 1 */
    v0120 = (v0085 == v0120 ? lisp_true : nil);
    goto v0017;

v0017:
    if (v0120 == nil) goto v0128;
    v0085 = stack[-2];
    v0120 = stack[0];
    {
        popv(4);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0085, v0120);
    }

v0128:
    v0120 = stack[0];
    if (v0120 == nil) goto v0038;
    v0120 = stack[0];
    v0085 = qcar(v0120);
    v0120 = (Lisp_Object)17; /* 1 */
    v0120 = (v0085 == v0120 ? lisp_true : nil);
    goto v0037;

v0037:
    if (v0120 == nil) goto v0014;
    v0085 = stack[-2];
    v0120 = stack[-1];
    {
        popv(4);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0085, v0120);
    }

v0014:
    v0120 = stack[-1];
    v0085 = qcar(v0120);
    v0120 = stack[0];
    v0120 = qcar(v0120);
    if (v0085 == v0120) goto v0029;
    v0120 = stack[-1];
    v0085 = qcar(v0120);
    v0120 = stack[0];
    v0120 = qcar(v0120);
    fn = elt(env, 3); /* factorordp */
    v0120 = (*qfn2(fn))(qenv(fn), v0085, v0120);
    nil = C_nil;
    if (exception_pending()) goto v0130;
    env = stack[-3];
    if (v0120 == nil) goto v0135;
    v0120 = stack[-1];
    v0085 = qcar(v0120);
    v0120 = stack[-2];
    v0120 = cons(v0085, v0120);
    nil = C_nil;
    if (exception_pending()) goto v0130;
    env = stack[-3];
    stack[-2] = v0120;
    v0120 = stack[-1];
    v0120 = qcdr(v0120);
    stack[-1] = v0120;
    goto v0143;

v0135:
    v0120 = stack[0];
    v0085 = qcar(v0120);
    v0120 = stack[-2];
    v0120 = cons(v0085, v0120);
    nil = C_nil;
    if (exception_pending()) goto v0130;
    env = stack[-3];
    stack[-2] = v0120;
    v0120 = stack[0];
    v0120 = qcdr(v0120);
    stack[0] = v0120;
    goto v0143;

v0029:
    v0120 = stack[-1];
    v0085 = qcar(v0120);
    v0120 = stack[-2];
    v0120 = cons(v0085, v0120);
    nil = C_nil;
    if (exception_pending()) goto v0130;
    env = stack[-3];
    stack[-2] = v0120;
    v0120 = stack[-1];
    v0120 = qcdr(v0120);
    stack[-1] = v0120;
    v0120 = stack[0];
    v0120 = qcdr(v0120);
    stack[0] = v0120;
    goto v0143;

v0038:
    v0120 = qvalue(elt(env, 1)); /* t */
    goto v0037;

v0025:
    v0120 = qvalue(elt(env, 1)); /* t */
    goto v0017;
/* error exit handlers */
v0130:
    popv(4);
    return nil;
}



/* Code for replace1_parents */

static Lisp_Object MS_CDECL CC_replace1_parents(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0041, v0005, v0016;
    Lisp_Object fn;
    Lisp_Object v0004, v0026, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "replace1_parents");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0026 = va_arg(aa, Lisp_Object);
    v0004 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for replace1_parents");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0041 = v0004;
    v0005 = v0026;
    v0016 = v0000;
/* end of prologue */
    v0016 = qcar(v0016);
    v0005 = qcar(v0005);
    v0041 = qcdr(v0041);
    v0041 = qcar(v0041);
    {
        fn = elt(env, 1); /* replace2_parents */
        return (*qfnn(fn))(qenv(fn), 3, v0016, v0005, v0041);
    }
}



/* Code for endstat */

static Lisp_Object MS_CDECL CC_endstat(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0009;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "endstat");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for endstat");
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
    CSL_IGNORE(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* end of prologue */
    v0009 = qvalue(elt(env, 1)); /* cursym!* */
    stack[0] = v0009;
    v0009 = elt(env, 2); /* end */
    fn = elt(env, 3); /* comm1 */
    v0009 = (*qfn1(fn))(qenv(fn), v0009);
    nil = C_nil;
    if (exception_pending()) goto v0018;
    v0009 = stack[0];
    popv(1);
    return ncons(v0009);
/* error exit handlers */
v0018:
    popv(1);
    return nil;
}



setup_type const u21_setup[] =
{
    {"qqe_eta-in-term",         CC_qqe_etaKinKterm,too_many_1, wrong_no_1},
    {"ibalp_negatet",           CC_ibalp_negatet,too_many_1,   wrong_no_1},
    {"sfto_dprpartksf",         CC_sfto_dprpartksf,too_many_1, wrong_no_1},
    {"**a2s",                   too_few_2,      CC_HHa2s,      wrong_no_2},
    {"diffsq",                  too_few_2,      CC_diffsq,     wrong_no_2},
    {"evdif",                   too_few_2,      CC_evdif,      wrong_no_2},
    {"arg2of2",                 too_few_2,      CC_arg2of2,    wrong_no_2},
    {"wedgek2",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_wedgek2},
    {"one-entry-listp",         too_few_2,      CC_oneKentryKlistp,wrong_no_2},
    {"prepd1",                  CC_prepd1,      too_many_1,    wrong_no_1},
    {"gcref_mkgraph-tgf",       CC_gcref_mkgraphKtgf,too_many_1,wrong_no_1},
    {"mkpartitions1",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_mkpartitions1},
    {"ofsf_subf",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_ofsf_subf},
    {"simpexpt",                CC_simpexpt,    too_many_1,    wrong_no_1},
    {"pasf_smwcpknowl",         CC_pasf_smwcpknowl,too_many_1, wrong_no_1},
    {"ibalp_isinminclause",     too_few_2,      CC_ibalp_isinminclause,wrong_no_2},
    {"ev_lexcomp",              too_few_2,      CC_ev_lexcomp, wrong_no_2},
    {"mchkopt1",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_mchkopt1},
    {"inttovec1",               too_few_2,      CC_inttovec1,  wrong_no_2},
    {"mkfortterpri",            wrong_no_na,    wrong_no_nb,   (n_args *)CC_mkfortterpri},
    {"trwrite",                 CC_trwrite,     too_many_1,    wrong_no_1},
    {"setelv",                  too_few_2,      CC_setelv,     wrong_no_2},
    {"moid_member",             too_few_2,      CC_moid_member,wrong_no_2},
    {"pst_termnodep",           CC_pst_termnodep,too_many_1,   wrong_no_1},
    {"ratn",                    CC_ratn,        too_many_1,    wrong_no_1},
    {"monomwrite",              CC_monomwrite,  too_many_1,    wrong_no_1},
    {"vintersection",           too_few_2,      CC_vintersection,wrong_no_2},
    {"ezgcdf1",                 too_few_2,      CC_ezgcdf1,    wrong_no_2},
    {"ibalp_var-set",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_ibalp_varKset},
    {"unaryrd",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_unaryrd},
    {"dm-minus",                CC_dmKminus,    too_many_1,    wrong_no_1},
    {"quoteequation",           CC_quoteequation,too_many_1,   wrong_no_1},
    {"evgradlexcomp",           too_few_2,      CC_evgradlexcomp,wrong_no_2},
    {"physopsm*",               CC_physopsmH,   too_many_1,    wrong_no_1},
    {"mktails1",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_mktails1},
    {"pairxvars",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_pairxvars},
    {"setel1",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_setel1},
    {"red=cancelsimp",          too_few_2,      CC_redMcancelsimp,wrong_no_2},
    {"simp-prop-order",         too_few_2,      CC_simpKpropKorder,wrong_no_2},
    {"splitlist:",              too_few_2,      CC_splitlistT, wrong_no_2},
    {"innprodkp",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_innprodkp},
    {"ibalp_readform",          CC_ibalp_readform,too_many_1,  wrong_no_1},
    {"naryom",                  CC_naryom,      too_many_1,    wrong_no_1},
    {"makeset",                 CC_makeset,     too_many_1,    wrong_no_1},
    {"groedeletip",             too_few_2,      CC_groedeletip,wrong_no_2},
    {"physopordchk",            too_few_2,      CC_physopordchk,wrong_no_2},
    {"set-global-mode",         CC_setKglobalKmode,too_many_1, wrong_no_1},
    {"scalprod",                too_few_2,      CC_scalprod,   wrong_no_2},
    {"mo_equal?",               too_few_2,      CC_mo_equalW,  wrong_no_2},
    {"resimpf",                 CC_resimpf,     too_many_1,    wrong_no_1},
    {"general-modular-expt",    too_few_2,      CC_generalKmodularKexpt,wrong_no_2},
    {"gf2cr:",                  CC_gf2crT,      too_many_1,    wrong_no_1},
    {"build-null-vector",       wrong_no_na,    wrong_no_nb,   (n_args *)CC_buildKnullKvector},
    {"ofsf_sippsubst",          too_few_2,      CC_ofsf_sippsubst,wrong_no_2},
    {"cl_susiupdknowl1",        wrong_no_na,    wrong_no_nb,   (n_args *)CC_cl_susiupdknowl1},
    {"ibalp_var-unset",         too_few_2,      CC_ibalp_varKunset,wrong_no_2},
    {"vsl_boundtype",           too_few_2,      CC_vsl_boundtype,wrong_no_2},
    {"my_letmtr",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_my_letmtr},
    {"xlcm",                    too_few_2,      CC_xlcm,       wrong_no_2},
    {"replace1_parents",        wrong_no_na,    wrong_no_nb,   (n_args *)CC_replace1_parents},
    {"endstat",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_endstat},
    {NULL, (one_args *)"u21", (two_args *)"10645 3385690 9103278", 0}
};

/* end of generated code */
