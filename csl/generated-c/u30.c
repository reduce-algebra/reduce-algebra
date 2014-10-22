
/* $destdir\u30.c        Machine generated C code */

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
    
#define CHAR_EOF pack_char(0, 0x001fffff)
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
#ifdef DEBUG
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
extern Lisp_Object gchook, resources, callstack, procstack, procmem, trap_time;
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
extern void CSL_MD5_Update(unsigned char *data, int len);
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


/* Code for !*!*a2i */

static Lisp_Object CC_HHa2i(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0006, v0007;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for **a2i");
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
    v0006 = v0001;
    stack[0] = v0000;
/* end of prologue */
    v0007 = stack[0];
    fn = elt(env, 2); /* intexprnp */
    v0006 = (*qfn2(fn))(qenv(fn), v0007, v0006);
    nil = C_nil;
    if (exception_pending()) goto v0008;
    env = stack[-1];
    if (!(v0006 == nil)) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v0007 = elt(env, 1); /* ieval */
    v0006 = stack[0];
    popv(2);
    return list2(v0007, v0006);
/* error exit handlers */
v0008:
    popv(2);
    return nil;
}



/* Code for mv!-pow!-mv!-!+ */

static Lisp_Object CC_mvKpowKmvKL(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0014, v0015;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mv-pow-mv-+");
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
    goto v0016;

v0016:
    v0014 = stack[0];
    if (v0014 == nil) goto v0017;
    v0015 = stack[-1];
    v0014 = stack[0];
    v0014 = qcar(v0014);
    fn = elt(env, 1); /* mv!-pow!-mv!-term!-!+ */
    v0015 = (*qfn2(fn))(qenv(fn), v0015, v0014);
    nil = C_nil;
    if (exception_pending()) goto v0018;
    env = stack[-3];
    v0014 = stack[-2];
    v0014 = cons(v0015, v0014);
    nil = C_nil;
    if (exception_pending()) goto v0018;
    env = stack[-3];
    stack[-2] = v0014;
    v0014 = stack[0];
    v0014 = qcdr(v0014);
    stack[0] = v0014;
    goto v0016;

v0017:
    v0014 = stack[-2];
    {
        popv(4);
        fn = elt(env, 2); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v0014);
    }
/* error exit handlers */
v0018:
    popv(4);
    return nil;
}



/* Code for add!-degrees */

static Lisp_Object CC_addKdegrees(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0027, v0028;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for add-degrees");
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
    push(nil);
/* copy arguments values to proper place */
    stack[-3] = v0001;
    stack[-4] = v0000;
/* end of prologue */
    stack[-5] = nil;
    goto v0029;

v0029:
    v0027 = stack[-4];
    if (v0027 == nil) goto v0030;
    v0027 = stack[-4];
    v0027 = qcar(v0027);
    stack[-2] = v0027;
    v0027 = stack[-3];
    v0027 = qcar(v0027);
    stack[-1] = v0027;
    v0027 = qvalue(elt(env, 1)); /* nil */
    stack[0] = v0027;
    goto v0002;

v0002:
    v0027 = stack[-2];
    if (v0027 == nil) goto v0031;
    v0027 = stack[-2];
    v0028 = qcar(v0027);
    v0027 = stack[-1];
    v0027 = qcar(v0027);
    fn = elt(env, 2); /* tayexp!-plus2 */
    v0028 = (*qfn2(fn))(qenv(fn), v0028, v0027);
    nil = C_nil;
    if (exception_pending()) goto v0032;
    env = stack[-6];
    v0027 = stack[0];
    v0027 = cons(v0028, v0027);
    nil = C_nil;
    if (exception_pending()) goto v0032;
    env = stack[-6];
    stack[0] = v0027;
    v0027 = stack[-2];
    v0027 = qcdr(v0027);
    stack[-2] = v0027;
    v0027 = stack[-1];
    v0027 = qcdr(v0027);
    stack[-1] = v0027;
    goto v0002;

v0031:
    v0027 = stack[0];
    v0028 = Lnreverse(nil, v0027);
    env = stack[-6];
    v0027 = stack[-5];
    v0027 = cons(v0028, v0027);
    nil = C_nil;
    if (exception_pending()) goto v0032;
    env = stack[-6];
    stack[-5] = v0027;
    v0027 = stack[-4];
    v0027 = qcdr(v0027);
    stack[-4] = v0027;
    v0027 = stack[-3];
    v0027 = qcdr(v0027);
    stack[-3] = v0027;
    goto v0029;

v0030:
    v0027 = stack[-5];
        popv(7);
        return Lnreverse(nil, v0027);
/* error exit handlers */
v0032:
    popv(7);
    return nil;
}



/* Code for mri_prepat */

static Lisp_Object CC_mri_prepat(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0025;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mri_prepat");
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
    v0025 = v0000;
/* end of prologue */
    fn = elt(env, 1); /* mri_2pasfat */
    v0025 = (*qfn1(fn))(qenv(fn), v0025);
    nil = C_nil;
    if (exception_pending()) goto v0016;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* pasf_prepat */
        return (*qfn1(fn))(qenv(fn), v0025);
    }
/* error exit handlers */
v0016:
    popv(1);
    return nil;
}



/* Code for ofsf_sippsignchkf */

static Lisp_Object MS_CDECL CC_ofsf_sippsignchkf(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0070, v0071, v0072, v0073, v0074, v0075, v0076;
    Lisp_Object fn;
    Lisp_Object v0016, v0025, v0026, v0011, v0051, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 7, "ofsf_sippsignchkf");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0001 = va_arg(aa, Lisp_Object);
    v0051 = va_arg(aa, Lisp_Object);
    v0011 = va_arg(aa, Lisp_Object);
    v0026 = va_arg(aa, Lisp_Object);
    v0025 = va_arg(aa, Lisp_Object);
    v0016 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ofsf_sippsignchkf");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push6(v0016,v0025,v0026,v0011,v0051,v0001);
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop6(v0000,v0001,v0051,v0011,v0026,v0025);
        pop(v0016);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0016;
    stack[-2] = v0025;
    stack[-3] = v0026;
    stack[-4] = v0011;
    stack[-5] = v0051;
    stack[-6] = v0001;
    stack[-7] = v0000;
/* end of prologue */
    v0070 = stack[-7];
    if (!consp(v0070)) goto v0077;
    v0070 = stack[-7];
    v0070 = qcar(v0070);
    v0070 = (consp(v0070) ? nil : lisp_true);
    goto v0078;

v0078:
    if (v0070 == nil) goto v0079;
    v0070 = stack[-7];
    {
        popv(10);
        fn = elt(env, 3); /* ofsf_updsigndom */
        return (*qfn1(fn))(qenv(fn), v0070);
    }

v0079:
    v0070 = stack[-7];
    v0070 = qcar(v0070);
    v0070 = qcar(v0070);
    v0076 = qcar(v0070);
    v0075 = stack[-6];
    v0074 = stack[-5];
    v0073 = stack[-4];
    v0072 = stack[-3];
    v0071 = stack[-2];
    v0070 = stack[-1];
    fn = elt(env, 4); /* ofsf_updsignvar */
    v0070 = (*qfnn(fn))(qenv(fn), 7, v0076, v0075, v0074, v0073, v0072, v0071, v0070);
    nil = C_nil;
    if (exception_pending()) goto v0080;
    env = stack[-9];
    stack[0] = v0070;
    v0071 = stack[0];
    v0070 = elt(env, 2); /* unknown */
    if (v0071 == v0070) goto v0019;
    v0070 = stack[-7];
    v0070 = qcar(v0070);
    v0076 = qcdr(v0070);
    v0075 = stack[-6];
    v0074 = stack[-5];
    v0073 = stack[-4];
    v0072 = stack[-3];
    v0071 = stack[-2];
    v0070 = stack[-1];
    v0070 = CC_ofsf_sippsignchkf(env, 7, v0076, v0075, v0074, v0073, v0072, v0071, v0070);
    nil = C_nil;
    if (exception_pending()) goto v0080;
    env = stack[-9];
    stack[-8] = v0070;
    v0071 = stack[-8];
    v0070 = elt(env, 2); /* unknown */
    if (v0071 == v0070) goto v0081;
    v0070 = stack[-7];
    v0076 = qcdr(v0070);
    v0075 = stack[-6];
    v0074 = stack[-5];
    v0073 = stack[-4];
    v0072 = stack[-3];
    v0071 = stack[-2];
    v0070 = stack[-1];
    v0070 = CC_ofsf_sippsignchkf(env, 7, v0076, v0075, v0074, v0073, v0072, v0071, v0070);
    nil = C_nil;
    if (exception_pending()) goto v0080;
    env = stack[-9];
    stack[-1] = v0070;
    v0071 = stack[-1];
    v0070 = elt(env, 2); /* unknown */
    if (v0071 == v0070) goto v0082;
    v0071 = stack[0];
    v0070 = stack[-7];
    v0070 = qcar(v0070);
    v0070 = qcar(v0070);
    v0070 = qcdr(v0070);
    fn = elt(env, 5); /* ofsf_updsignpow */
    v0070 = (*qfn2(fn))(qenv(fn), v0071, v0070);
    nil = C_nil;
    if (exception_pending()) goto v0080;
    env = stack[-9];
    stack[0] = v0070;
    v0071 = stack[-8];
    v0070 = stack[0];
    fn = elt(env, 6); /* ofsf_updsignmult */
    v0070 = (*qfn2(fn))(qenv(fn), v0071, v0070);
    nil = C_nil;
    if (exception_pending()) goto v0080;
    env = stack[-9];
    v0072 = v0070;
    v0071 = v0072;
    v0070 = elt(env, 2); /* unknown */
    if (v0071 == v0070) goto v0083;
    v0071 = v0072;
    v0070 = stack[-1];
    {
        popv(10);
        fn = elt(env, 7); /* ofsf_updsignadd */
        return (*qfn2(fn))(qenv(fn), v0071, v0070);
    }

v0083:
    v0070 = elt(env, 2); /* unknown */
    { popv(10); return onevalue(v0070); }

v0082:
    v0070 = elt(env, 2); /* unknown */
    { popv(10); return onevalue(v0070); }

v0081:
    v0070 = elt(env, 2); /* unknown */
    { popv(10); return onevalue(v0070); }

v0019:
    v0070 = elt(env, 2); /* unknown */
    { popv(10); return onevalue(v0070); }

v0077:
    v0070 = qvalue(elt(env, 1)); /* t */
    goto v0078;
/* error exit handlers */
v0080:
    popv(10);
    return nil;
}



/* Code for omatpir */

static Lisp_Object MS_CDECL CC_omatpir(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0006, v0007, v0012;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "omatpir");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for omatpir");
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
    fn = elt(env, 3); /* lex */
    v0006 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0010;
    env = stack[-2];
    fn = elt(env, 4); /* omsir */
    v0006 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0010;
    env = stack[-2];
    v0006 = qcar(v0006);
    stack[-1] = v0006;
    fn = elt(env, 3); /* lex */
    v0006 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0010;
    env = stack[-2];
    fn = elt(env, 5); /* omobj */
    v0006 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0010;
    env = stack[-2];
    v0006 = qcar(v0006);
    stack[0] = v0006;
    fn = elt(env, 3); /* lex */
    v0006 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0010;
    env = stack[-2];
    v0006 = elt(env, 1); /* (!/ o m a t p) */
    fn = elt(env, 6); /* checktag */
    v0006 = (*qfn1(fn))(qenv(fn), v0006);
    nil = C_nil;
    if (exception_pending()) goto v0010;
    env = stack[-2];
    v0012 = stack[-1];
    v0007 = stack[0];
    v0006 = qvalue(elt(env, 2)); /* nil */
    v0006 = list2star(v0012, v0007, v0006);
    nil = C_nil;
    if (exception_pending()) goto v0010;
    popv(3);
    return ncons(v0006);
/* error exit handlers */
v0010:
    popv(3);
    return nil;
}



/* Code for cos!* */

static Lisp_Object CC_cosH(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0030, v0029;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for cos*");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0030 = v0000;
/* end of prologue */
    v0029 = v0030;
    v0030 = qvalue(elt(env, 1)); /* !:bprec!: */
    {
        fn = elt(env, 2); /* cos!: */
        return (*qfn2(fn))(qenv(fn), v0029, v0030);
    }
}



/* Code for red!=hide */

static Lisp_Object CC_redMhide(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0032, v0088;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for red=hide");
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
    v0032 = v0000;
/* end of prologue */
    stack[-5] = v0032;
    v0032 = stack[-5];
    if (v0032 == nil) goto v0029;
    v0032 = stack[-5];
    v0032 = qcar(v0032);
    stack[-1] = v0032;
    stack[0] = (Lisp_Object)-15; /* -1 */
    v0032 = stack[-1];
    v0032 = qcar(v0032);
    fn = elt(env, 2); /* mo_neg */
    v0032 = (*qfn1(fn))(qenv(fn), v0032);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-6];
    fn = elt(env, 3); /* mo_times_ei */
    v0088 = (*qfn2(fn))(qenv(fn), stack[0], v0032);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-6];
    v0032 = stack[-1];
    v0032 = qcdr(v0032);
    v0032 = cons(v0088, v0032);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-6];
    v0032 = ncons(v0032);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-6];
    stack[-3] = v0032;
    stack[-4] = v0032;
    goto v0090;

v0090:
    v0032 = stack[-5];
    v0032 = qcdr(v0032);
    stack[-5] = v0032;
    v0032 = stack[-5];
    if (v0032 == nil) { Lisp_Object res = stack[-4]; popv(7); return onevalue(res); }
    stack[-2] = stack[-3];
    v0032 = stack[-5];
    v0032 = qcar(v0032);
    stack[-1] = v0032;
    stack[0] = (Lisp_Object)-15; /* -1 */
    v0032 = stack[-1];
    v0032 = qcar(v0032);
    fn = elt(env, 2); /* mo_neg */
    v0032 = (*qfn1(fn))(qenv(fn), v0032);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-6];
    fn = elt(env, 3); /* mo_times_ei */
    v0088 = (*qfn2(fn))(qenv(fn), stack[0], v0032);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-6];
    v0032 = stack[-1];
    v0032 = qcdr(v0032);
    v0032 = cons(v0088, v0032);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-6];
    v0032 = ncons(v0032);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-6];
    v0032 = Lrplacd(nil, stack[-2], v0032);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-6];
    v0032 = stack[-3];
    v0032 = qcdr(v0032);
    stack[-3] = v0032;
    goto v0090;

v0029:
    v0032 = qvalue(elt(env, 1)); /* nil */
    { popv(7); return onevalue(v0032); }
/* error exit handlers */
v0089:
    popv(7);
    return nil;
}



/* Code for atom_compare */

static Lisp_Object CC_atom_compare(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0091, v0092, v0093;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for atom_compare");
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
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0092 = v0001;
    v0093 = v0000;
/* end of prologue */
    v0091 = v0093;
    if (is_number(v0091)) goto v0025;
    v0091 = v0092;
    if (symbolp(v0091)) goto v0008;
    v0091 = v0092;
    v0091 = (is_number(v0091) ? lisp_true : nil);
    return onevalue(v0091);

v0008:
    v0091 = v0093;
        return Lorderp(nil, v0091, v0092);

v0025:
    v0091 = v0092;
    if (is_number(v0091)) goto v0094;
    v0091 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v0091);

v0094:
    v0091 = v0093;
    v0091 = (Lisp_Object)lessp2(v0091, v0092);
    errexit();
    v0091 = v0091 ? lisp_true : nil;
    v0091 = (v0091 == nil ? lisp_true : nil);
    return onevalue(v0091);
}



/* Code for sfto_lessq */

static Lisp_Object CC_sfto_lessq(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0005, v0095;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sfto_lessq");
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
    v0005 = v0001;
    v0095 = v0000;
/* end of prologue */
    stack[0] = v0095;
    fn = elt(env, 1); /* negsq */
    v0005 = (*qfn1(fn))(qenv(fn), v0005);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    env = stack[-1];
    fn = elt(env, 2); /* addsq */
    v0005 = (*qfn2(fn))(qenv(fn), stack[0], v0005);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    env = stack[-1];
    v0005 = qcar(v0005);
    {
        popv(2);
        fn = elt(env, 3); /* minusf */
        return (*qfn1(fn))(qenv(fn), v0005);
    }
/* error exit handlers */
v0094:
    popv(2);
    return nil;
}



/* Code for ofsf_smordtable */

static Lisp_Object CC_ofsf_smordtable(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0084, v0003, v0002;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ofsf_smordtable");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0084 = v0001;
    v0003 = v0000;
/* end of prologue */
    v0002 = elt(env, 1); /* ((equal (equal . false) (neq equal . t) (geq equal . t) (leq . false) (greaterp equal . t) (lessp . false)) (neq (equal equal) (neq) (geq) (leq leq) (greaterp) (lessp lessp
)) (geq (equal . false) (neq geq . t) (geq geq . t) (leq . false) (greaterp geq . t) (lessp . false)) (leq (equal equal) (neq) (geq) (leq leq) (greaterp) (lessp lessp)) (greaterp (equal . false) (neq 
greaterp . t) (geq greaterp . t) (leq . false) (greaterp greaterp . t) (lessp . false)) (lessp (equal equal) (neq) (geq) (leq leq) (greaterp) (lessp lessp))) 
*/
    v0003 = Latsoc(nil, v0003, v0002);
    v0084 = Latsoc(nil, v0084, v0003);
    v0084 = qcdr(v0084);
    return onevalue(v0084);
}



/* Code for aex_subrat1 */

static Lisp_Object MS_CDECL CC_aex_subrat1(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0091, v0092, v0093;
    Lisp_Object fn;
    Lisp_Object v0051, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "aex_subrat1");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0001 = va_arg(aa, Lisp_Object);
    v0051 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for aex_subrat1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0051,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0051);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0051;
    stack[-1] = v0001;
    stack[-2] = v0000;
/* end of prologue */
    v0091 = stack[-2];
    fn = elt(env, 1); /* aex_ex */
    v0091 = (*qfn1(fn))(qenv(fn), v0091);
    nil = C_nil;
    if (exception_pending()) goto v0098;
    env = stack[-3];
    v0093 = qcar(v0091);
    v0092 = stack[-1];
    v0091 = stack[0];
    fn = elt(env, 2); /* sfto_qsubhor1 */
    v0091 = (*qfnn(fn))(qenv(fn), 3, v0093, v0092, v0091);
    nil = C_nil;
    if (exception_pending()) goto v0098;
    env = stack[-3];
    stack[-1] = v0091;
    v0091 = qcar(v0091);
    fn = elt(env, 3); /* kernels */
    stack[0] = (*qfn1(fn))(qenv(fn), v0091);
    nil = C_nil;
    if (exception_pending()) goto v0098;
    env = stack[-3];
    v0091 = stack[-2];
    fn = elt(env, 4); /* aex_ctx */
    v0091 = (*qfn1(fn))(qenv(fn), v0091);
    nil = C_nil;
    if (exception_pending()) goto v0098;
    env = stack[-3];
    fn = elt(env, 5); /* ctx_filter */
    v0091 = (*qfn2(fn))(qenv(fn), stack[0], v0091);
    nil = C_nil;
    if (exception_pending()) goto v0098;
    env = stack[-3];
    {
        Lisp_Object v0024 = stack[-1];
        popv(4);
        fn = elt(env, 6); /* aex_mk */
        return (*qfn2(fn))(qenv(fn), v0024, v0091);
    }
/* error exit handlers */
v0098:
    popv(4);
    return nil;
}



/* Code for semanticml */

static Lisp_Object CC_semanticml(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0089, v0101;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for semanticml");
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
    v0089 = stack[0];
    v0101 = Llength(nil, v0089);
    nil = C_nil;
    if (exception_pending()) goto v0060;
    env = stack[-1];
    v0089 = (Lisp_Object)17; /* 1 */
    v0089 = (Lisp_Object)greaterp2(v0101, v0089);
    nil = C_nil;
    if (exception_pending()) goto v0060;
    v0089 = v0089 ? lisp_true : nil;
    env = stack[-1];
    if (v0089 == nil) goto v0025;
    v0089 = elt(env, 1); /* "<apply>" */
    fn = elt(env, 15); /* printout */
    v0089 = (*qfn1(fn))(qenv(fn), v0089);
    nil = C_nil;
    if (exception_pending()) goto v0060;
    env = stack[-1];
    v0089 = qvalue(elt(env, 2)); /* t */
    fn = elt(env, 16); /* indent!* */
    v0089 = (*qfn1(fn))(qenv(fn), v0089);
    nil = C_nil;
    if (exception_pending()) goto v0060;
    env = stack[-1];
    v0089 = elt(env, 3); /* "<fn>" */
    fn = elt(env, 15); /* printout */
    v0089 = (*qfn1(fn))(qenv(fn), v0089);
    nil = C_nil;
    if (exception_pending()) goto v0060;
    env = stack[-1];
    v0089 = qvalue(elt(env, 2)); /* t */
    fn = elt(env, 16); /* indent!* */
    v0089 = (*qfn1(fn))(qenv(fn), v0089);
    nil = C_nil;
    if (exception_pending()) goto v0060;
    env = stack[-1];
    goto v0025;

v0025:
    v0089 = elt(env, 5); /* "<semantic>" */
    fn = elt(env, 15); /* printout */
    v0089 = (*qfn1(fn))(qenv(fn), v0089);
    nil = C_nil;
    if (exception_pending()) goto v0060;
    env = stack[-1];
    v0089 = qvalue(elt(env, 2)); /* t */
    fn = elt(env, 16); /* indent!* */
    v0089 = (*qfn1(fn))(qenv(fn), v0089);
    nil = C_nil;
    if (exception_pending()) goto v0060;
    env = stack[-1];
    v0089 = elt(env, 6); /* "<ci><mo>" */
    fn = elt(env, 15); /* printout */
    v0089 = (*qfn1(fn))(qenv(fn), v0089);
    nil = C_nil;
    if (exception_pending()) goto v0060;
    env = stack[-1];
    v0089 = stack[0];
    v0089 = qcar(v0089);
    v0089 = qcar(v0089);
    v0089 = Lprinc(nil, v0089);
    nil = C_nil;
    if (exception_pending()) goto v0060;
    env = stack[-1];
    v0089 = elt(env, 7); /* "</mo></ci>" */
    v0089 = Lprinc(nil, v0089);
    nil = C_nil;
    if (exception_pending()) goto v0060;
    env = stack[-1];
    v0089 = elt(env, 8); /* "<annotation-xml encoding=""OpenMath"">" */
    fn = elt(env, 15); /* printout */
    v0089 = (*qfn1(fn))(qenv(fn), v0089);
    nil = C_nil;
    if (exception_pending()) goto v0060;
    env = stack[-1];
    v0089 = qvalue(elt(env, 2)); /* t */
    fn = elt(env, 16); /* indent!* */
    v0089 = (*qfn1(fn))(qenv(fn), v0089);
    nil = C_nil;
    if (exception_pending()) goto v0060;
    env = stack[-1];
    v0089 = elt(env, 9); /* "<" */
    fn = elt(env, 15); /* printout */
    v0089 = (*qfn1(fn))(qenv(fn), v0089);
    nil = C_nil;
    if (exception_pending()) goto v0060;
    env = stack[-1];
    v0089 = stack[0];
    v0089 = qcar(v0089);
    v0089 = qcdr(v0089);
    v0089 = qcar(v0089);
    fn = elt(env, 17); /* mathml_list2string */
    v0089 = (*qfn1(fn))(qenv(fn), v0089);
    nil = C_nil;
    if (exception_pending()) goto v0060;
    env = stack[-1];
    v0089 = elt(env, 10); /* ">" */
    v0089 = Lprinc(nil, v0089);
    nil = C_nil;
    if (exception_pending()) goto v0060;
    env = stack[-1];
    v0089 = qvalue(elt(env, 4)); /* nil */
    fn = elt(env, 16); /* indent!* */
    v0089 = (*qfn1(fn))(qenv(fn), v0089);
    nil = C_nil;
    if (exception_pending()) goto v0060;
    env = stack[-1];
    v0089 = elt(env, 11); /* "</annotation-xml>" */
    fn = elt(env, 15); /* printout */
    v0089 = (*qfn1(fn))(qenv(fn), v0089);
    nil = C_nil;
    if (exception_pending()) goto v0060;
    env = stack[-1];
    v0089 = qvalue(elt(env, 4)); /* nil */
    fn = elt(env, 16); /* indent!* */
    v0089 = (*qfn1(fn))(qenv(fn), v0089);
    nil = C_nil;
    if (exception_pending()) goto v0060;
    env = stack[-1];
    v0089 = elt(env, 12); /* "</semantic>" */
    fn = elt(env, 15); /* printout */
    v0089 = (*qfn1(fn))(qenv(fn), v0089);
    nil = C_nil;
    if (exception_pending()) goto v0060;
    env = stack[-1];
    v0089 = stack[0];
    v0101 = Llength(nil, v0089);
    nil = C_nil;
    if (exception_pending()) goto v0060;
    env = stack[-1];
    v0089 = (Lisp_Object)17; /* 1 */
    v0089 = (Lisp_Object)greaterp2(v0101, v0089);
    nil = C_nil;
    if (exception_pending()) goto v0060;
    v0089 = v0089 ? lisp_true : nil;
    env = stack[-1];
    if (v0089 == nil) goto v0102;
    v0089 = qvalue(elt(env, 4)); /* nil */
    fn = elt(env, 16); /* indent!* */
    v0089 = (*qfn1(fn))(qenv(fn), v0089);
    nil = C_nil;
    if (exception_pending()) goto v0060;
    env = stack[-1];
    v0089 = elt(env, 13); /* "</fn>" */
    fn = elt(env, 15); /* printout */
    v0089 = (*qfn1(fn))(qenv(fn), v0089);
    nil = C_nil;
    if (exception_pending()) goto v0060;
    env = stack[-1];
    v0089 = stack[0];
    v0089 = qcdr(v0089);
    fn = elt(env, 18); /* multi_elem */
    v0089 = (*qfn1(fn))(qenv(fn), v0089);
    nil = C_nil;
    if (exception_pending()) goto v0060;
    env = stack[-1];
    v0089 = qvalue(elt(env, 4)); /* nil */
    fn = elt(env, 16); /* indent!* */
    v0089 = (*qfn1(fn))(qenv(fn), v0089);
    nil = C_nil;
    if (exception_pending()) goto v0060;
    env = stack[-1];
    v0089 = elt(env, 14); /* "</apply>" */
    fn = elt(env, 15); /* printout */
    v0089 = (*qfn1(fn))(qenv(fn), v0089);
    nil = C_nil;
    if (exception_pending()) goto v0060;
    goto v0102;

v0102:
    v0089 = nil;
    { popv(2); return onevalue(v0089); }
/* error exit handlers */
v0060:
    popv(2);
    return nil;
}



/* Code for vp2 */

static Lisp_Object CC_vp2(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0002, v0006;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for vp2");
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
    v0006 = nil;
    goto v0025;

v0025:
    v0002 = stack[0];
    if (v0002 == nil) goto v0039;
    v0002 = (Lisp_Object)1; /* 0 */
    v0002 = cons(v0002, v0006);
    nil = C_nil;
    if (exception_pending()) goto v0012;
    env = stack[-1];
    v0006 = v0002;
    v0002 = stack[0];
    v0002 = qcdr(v0002);
    stack[0] = v0002;
    goto v0025;

v0039:
    v0002 = v0006;
    {
        popv(2);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v0002);
    }
/* error exit handlers */
v0012:
    popv(2);
    return nil;
}



/* Code for dm!-min */

static Lisp_Object CC_dmKmin(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0078, v0077;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dm-min");
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
    CSL_IGNORE(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0001;
    stack[-1] = v0000;
/* end of prologue */
    v0077 = stack[-1];
    v0078 = stack[0];
    fn = elt(env, 1); /* dm!-gt */
    v0078 = (*qfn2(fn))(qenv(fn), v0077, v0078);
    nil = C_nil;
    if (exception_pending()) goto v0084;
    if (v0078 == nil) { Lisp_Object res = stack[-1]; popv(2); return onevalue(res); }
    else { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
/* error exit handlers */
v0084:
    popv(2);
    return nil;
}



/* Code for s!-nextarg */

static Lisp_Object CC_sKnextarg(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0125, v0126, v0127;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for s-nextarg");
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
    v0125 = qvalue(elt(env, 1)); /* !*udebug */
    if (v0125 == nil) goto v0090;
    v0125 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 13); /* uprint */
    v0125 = (*qfn1(fn))(qenv(fn), v0125);
    nil = C_nil;
    if (exception_pending()) goto v0128;
    env = stack[-2];
    goto v0090;

v0090:
    v0125 = qvalue(elt(env, 3)); /* comb */
    if (!(v0125 == nil)) goto v0007;
    v0125 = qvalue(elt(env, 4)); /* i */
    v0125 = add1(v0125);
    nil = C_nil;
    if (exception_pending()) goto v0128;
    env = stack[-2];
    qvalue(elt(env, 4)) = v0125; /* i */
    v0125 = stack[0];
    fn = elt(env, 14); /* initcomb */
    v0125 = (*qfn1(fn))(qenv(fn), v0125);
    nil = C_nil;
    if (exception_pending()) goto v0128;
    env = stack[-2];
    qvalue(elt(env, 3)) = v0125; /* comb */
    goto v0007;

v0007:
    v0126 = stack[0];
    v0125 = qvalue(elt(env, 3)); /* comb */
    fn = elt(env, 15); /* getcomb */
    v0125 = (*qfn2(fn))(qenv(fn), v0126, v0125);
    nil = C_nil;
    if (exception_pending()) goto v0128;
    env = stack[-2];
    stack[-1] = v0125;
    if (v0125 == nil) goto v0129;
    v0126 = qvalue(elt(env, 4)); /* i */
    v0125 = (Lisp_Object)17; /* 1 */
    if (v0126 == v0125) goto v0067;
    v0125 = qvalue(elt(env, 2)); /* nil */
    goto v0018;

v0018:
    if (v0125 == nil) goto v0088;
    v0125 = stack[-1];
    v0125 = qcar(v0125);
    v0126 = qcar(v0125);
    v0125 = stack[-1];
    v0125 = qcdr(v0125);
    popv(3);
    return cons(v0126, v0125);

v0088:
    v0126 = qvalue(elt(env, 4)); /* i */
    v0125 = (Lisp_Object)1; /* 0 */
    if (v0126 == v0125) goto v0101;
    v0125 = qvalue(elt(env, 2)); /* nil */
    goto v0130;

v0130:
    if (v0125 == nil) goto v0131;
    v0126 = elt(env, 6); /* (null!-fn) */
    v0125 = stack[0];
    popv(3);
    return cons(v0126, v0125);

v0131:
    v0125 = qvalue(elt(env, 7)); /* acontract */
    if (v0125 == nil) goto v0053;
    v0126 = qvalue(elt(env, 4)); /* i */
    v0125 = qvalue(elt(env, 5)); /* upb */
    v0125 = (Lisp_Object)lesseq2(v0126, v0125);
    nil = C_nil;
    if (exception_pending()) goto v0128;
    v0125 = v0125 ? lisp_true : nil;
    env = stack[-2];
    if (v0125 == nil) goto v0053;
    v0127 = qvalue(elt(env, 8)); /* op */
    v0125 = stack[-1];
    v0126 = qcar(v0125);
    v0125 = stack[-1];
    v0125 = qcdr(v0125);
    v0125 = acons(v0127, v0126, v0125);
    nil = C_nil;
    if (exception_pending()) goto v0128;
    env = stack[-2];
    {
        popv(3);
        fn = elt(env, 16); /* mval */
        return (*qfn1(fn))(qenv(fn), v0125);
    }

v0053:
    v0125 = qvalue(elt(env, 9)); /* mcontract */
    if (v0125 == nil) goto v0132;
    v0126 = qvalue(elt(env, 4)); /* i */
    v0125 = qvalue(elt(env, 5)); /* upb */
    v0125 = (Lisp_Object)lesseq2(v0126, v0125);
    nil = C_nil;
    if (exception_pending()) goto v0128;
    v0125 = v0125 ? lisp_true : nil;
    env = stack[-2];
    if (v0125 == nil) goto v0132;
    v0127 = elt(env, 10); /* null!-fn */
    v0125 = stack[-1];
    v0126 = qcar(v0125);
    v0125 = stack[-1];
    v0125 = qcdr(v0125);
    popv(3);
    return acons(v0127, v0126, v0125);

v0132:
    v0125 = qvalue(elt(env, 11)); /* expand */
    if (v0125 == nil) goto v0133;
    v0125 = qvalue(elt(env, 2)); /* nil */
    qvalue(elt(env, 11)) = v0125; /* expand */
    v0126 = qvalue(elt(env, 12)); /* identity */
    v0125 = stack[0];
    popv(3);
    return cons(v0126, v0125);

v0133:
    v0125 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v0125); }

v0101:
    v0126 = qvalue(elt(env, 4)); /* i */
    v0125 = qvalue(elt(env, 5)); /* upb */
    v0125 = (Lisp_Object)lesseq2(v0126, v0125);
    nil = C_nil;
    if (exception_pending()) goto v0128;
    v0125 = v0125 ? lisp_true : nil;
    env = stack[-2];
    goto v0130;

v0067:
    v0126 = qvalue(elt(env, 4)); /* i */
    v0125 = qvalue(elt(env, 5)); /* upb */
    v0125 = (Lisp_Object)lesseq2(v0126, v0125);
    nil = C_nil;
    if (exception_pending()) goto v0128;
    v0125 = v0125 ? lisp_true : nil;
    env = stack[-2];
    goto v0018;

v0129:
    v0126 = qvalue(elt(env, 4)); /* i */
    v0125 = (Lisp_Object)1; /* 0 */
    if (v0126 == v0125) goto v0074;
    v0125 = qvalue(elt(env, 2)); /* nil */
    goto v0134;

v0134:
    if (v0125 == nil) goto v0135;
    v0126 = elt(env, 6); /* (null!-fn) */
    v0125 = stack[0];
    popv(3);
    return cons(v0126, v0125);

v0135:
    v0125 = qvalue(elt(env, 11)); /* expand */
    if (v0125 == nil) goto v0136;
    v0125 = qvalue(elt(env, 2)); /* nil */
    qvalue(elt(env, 11)) = v0125; /* expand */
    v0126 = qvalue(elt(env, 12)); /* identity */
    v0125 = stack[0];
    popv(3);
    return cons(v0126, v0125);

v0136:
    v0125 = nil;
    { popv(3); return onevalue(v0125); }

v0074:
    v0126 = qvalue(elt(env, 4)); /* i */
    v0125 = qvalue(elt(env, 5)); /* upb */
    v0125 = (Lisp_Object)lesseq2(v0126, v0125);
    nil = C_nil;
    if (exception_pending()) goto v0128;
    v0125 = v0125 ? lisp_true : nil;
    env = stack[-2];
    goto v0134;
/* error exit handlers */
v0128:
    popv(3);
    return nil;
}



/* Code for dipsum */

static Lisp_Object CC_dipsum(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0033, v0034, v0070;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dipsum");
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
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-5] = v0001;
    stack[-6] = v0000;
/* end of prologue */
    v0033 = stack[-6];
    if (v0033 == nil) { Lisp_Object res = stack[-5]; popv(9); return onevalue(res); }
    v0033 = stack[-5];
    if (v0033 == nil) { Lisp_Object res = stack[-6]; popv(9); return onevalue(res); }
    stack[-7] = nil;
    stack[-2] = nil;
    stack[0] = nil;
    goto v0007;

v0007:
    v0033 = stack[-7];
    if (!(v0033 == nil)) { Lisp_Object res = stack[0]; popv(9); return onevalue(res); }
    v0033 = stack[-6];
    if (v0033 == nil) goto v0087;
    v0033 = stack[-5];
    if (v0033 == nil) goto v0092;
    v0033 = stack[-6];
    v0033 = qcar(v0033);
    stack[-4] = v0033;
    v0033 = stack[-5];
    v0033 = qcar(v0033);
    stack[-3] = v0033;
    v0034 = stack[-4];
    v0033 = stack[-3];
    fn = elt(env, 3); /* evcomp */
    v0033 = (*qfn2(fn))(qenv(fn), v0034, v0033);
    nil = C_nil;
    if (exception_pending()) goto v0108;
    env = stack[-8];
    stack[-1] = v0033;
    v0034 = stack[-1];
    v0033 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 4); /* iequal */
    v0033 = (*qfn2(fn))(qenv(fn), v0034, v0033);
    nil = C_nil;
    if (exception_pending()) goto v0108;
    env = stack[-8];
    if (v0033 == nil) goto v0057;
    v0070 = stack[-4];
    v0033 = stack[-6];
    v0033 = qcdr(v0033);
    v0034 = qcar(v0033);
    v0033 = qvalue(elt(env, 1)); /* nil */
    v0033 = list2star(v0070, v0034, v0033);
    nil = C_nil;
    if (exception_pending()) goto v0108;
    env = stack[-8];
    stack[-1] = v0033;
    v0033 = stack[-6];
    v0033 = qcdr(v0033);
    v0033 = qcdr(v0033);
    stack[-6] = v0033;
    goto v0015;

v0015:
    v0033 = stack[-1];
    if (v0033 == nil) goto v0007;
    v0033 = stack[0];
    if (v0033 == nil) goto v0146;
    v0033 = stack[-2];
    v0034 = qcdr(v0033);
    v0033 = stack[-1];
    fn = elt(env, 5); /* setcdr */
    v0033 = (*qfn2(fn))(qenv(fn), v0034, v0033);
    nil = C_nil;
    if (exception_pending()) goto v0108;
    env = stack[-8];
    v0033 = stack[-1];
    stack[-2] = v0033;
    goto v0007;

v0146:
    v0033 = stack[-1];
    stack[-2] = v0033;
    stack[0] = v0033;
    goto v0007;

v0057:
    v0034 = stack[-1];
    v0033 = (Lisp_Object)-15; /* -1 */
    fn = elt(env, 4); /* iequal */
    v0033 = (*qfn2(fn))(qenv(fn), v0034, v0033);
    nil = C_nil;
    if (exception_pending()) goto v0108;
    env = stack[-8];
    if (v0033 == nil) goto v0147;
    v0070 = stack[-3];
    v0033 = stack[-5];
    v0033 = qcdr(v0033);
    v0034 = qcar(v0033);
    v0033 = qvalue(elt(env, 1)); /* nil */
    v0033 = list2star(v0070, v0034, v0033);
    nil = C_nil;
    if (exception_pending()) goto v0108;
    env = stack[-8];
    stack[-1] = v0033;
    v0033 = stack[-5];
    v0033 = qcdr(v0033);
    v0033 = qcdr(v0033);
    stack[-5] = v0033;
    goto v0015;

v0147:
    v0033 = stack[-6];
    v0033 = qcdr(v0033);
    v0034 = qcar(v0033);
    v0033 = stack[-5];
    v0033 = qcdr(v0033);
    v0033 = qcar(v0033);
    fn = elt(env, 6); /* bcsum */
    v0033 = (*qfn2(fn))(qenv(fn), v0034, v0033);
    nil = C_nil;
    if (exception_pending()) goto v0108;
    env = stack[-8];
    stack[-1] = v0033;
    v0033 = stack[-1];
    fn = elt(env, 7); /* bczero!? */
    v0033 = (*qfn1(fn))(qenv(fn), v0033);
    nil = C_nil;
    if (exception_pending()) goto v0108;
    env = stack[-8];
    if (v0033 == nil) goto v0148;
    v0033 = qvalue(elt(env, 1)); /* nil */
    goto v0045;

v0045:
    stack[-1] = v0033;
    v0033 = stack[-6];
    v0033 = qcdr(v0033);
    v0033 = qcdr(v0033);
    stack[-6] = v0033;
    v0033 = stack[-5];
    v0033 = qcdr(v0033);
    v0033 = qcdr(v0033);
    stack[-5] = v0033;
    goto v0015;

v0148:
    v0070 = stack[-4];
    v0034 = stack[-1];
    v0033 = qvalue(elt(env, 1)); /* nil */
    v0033 = list2star(v0070, v0034, v0033);
    nil = C_nil;
    if (exception_pending()) goto v0108;
    env = stack[-8];
    goto v0045;

v0092:
    v0033 = stack[-6];
    stack[-1] = v0033;
    v0033 = qvalue(elt(env, 2)); /* t */
    stack[-7] = v0033;
    goto v0015;

v0087:
    v0033 = stack[-5];
    stack[-1] = v0033;
    v0033 = qvalue(elt(env, 2)); /* t */
    stack[-7] = v0033;
    goto v0015;
/* error exit handlers */
v0108:
    popv(9);
    return nil;
}



/* Code for a2bc */

static Lisp_Object CC_a2bc(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0018, v0091;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for a2bc");
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
    v0018 = v0000;
/* end of prologue */
    v0091 = qvalue(elt(env, 1)); /* !*grmod!* */
    if (v0091 == nil) goto v0015;
    v0091 = v0018;
    if (!consp(v0091)) goto v0004;
    v0091 = v0018;
    v0091 = qcar(v0091);
    v0091 = (consp(v0091) ? nil : lisp_true);
    goto v0096;

v0096:
    if (v0091 == nil) goto v0003;
    {
        popv(1);
        fn = elt(env, 4); /* bcfd */
        return (*qfn1(fn))(qenv(fn), v0018);
    }

v0003:
    v0091 = elt(env, 3); /* " Invalid coefficient " */
    v0018 = list2(v0091, v0018);
    nil = C_nil;
    if (exception_pending()) goto v0092;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 5); /* rederr */
        return (*qfn1(fn))(qenv(fn), v0018);
    }

v0004:
    v0091 = qvalue(elt(env, 2)); /* t */
    goto v0096;

v0015:
    {
        popv(1);
        fn = elt(env, 6); /* simp!* */
        return (*qfn1(fn))(qenv(fn), v0018);
    }
/* error exit handlers */
v0092:
    popv(1);
    return nil;
}



/* Code for indordl2 */

static Lisp_Object CC_indordl2(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0124, v0014;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for indordl2");
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
    CSL_IGNORE(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0001;
    stack[-1] = v0000;
/* end of prologue */
    v0014 = stack[-1];
    v0124 = stack[0];
    fn = elt(env, 1); /* indordlp */
    v0124 = (*qfn2(fn))(qenv(fn), v0014, v0124);
    nil = C_nil;
    if (exception_pending()) goto v0149;
    if (v0124 == nil) goto v0006;
    v0014 = stack[-1];
    v0124 = stack[0];
    popv(2);
    return list2(v0014, v0124);

v0006:
    v0014 = stack[0];
    v0124 = stack[-1];
    popv(2);
    return list2(v0014, v0124);
/* error exit handlers */
v0149:
    popv(2);
    return nil;
}



/* Code for po!:statep */

static Lisp_Object CC_poTstatep(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0151, v0067, v0068;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for po:statep");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0068 = v0000;
/* end of prologue */
    v0151 = v0068;
    if (symbolp(v0151)) goto v0004;
    v0151 = qvalue(elt(env, 1)); /* nil */
    goto v0016;

v0016:
    if (!(v0151 == nil)) return onevalue(v0151);
    v0151 = v0068;
    if (!consp(v0151)) goto v0098;
    v0151 = v0068;
    v0151 = qcar(v0151);
    if (symbolp(v0151)) goto v0087;
    v0151 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v0151);

v0087:
    v0151 = v0068;
    v0151 = qcar(v0151);
    if (!symbolp(v0151)) v0151 = nil;
    else { v0151 = qfastgets(v0151);
           if (v0151 != nil) { v0151 = elt(v0151, 18); /* phystype */
#ifdef RECORD_GET
             if (v0151 != SPID_NOPROP)
                record_get(elt(fastget_names, 18), 1);
             else record_get(elt(fastget_names, 18), 0),
                v0151 = nil; }
           else record_get(elt(fastget_names, 18), 0); }
#else
             if (v0151 == SPID_NOPROP) v0151 = nil; }}
#endif
    v0067 = elt(env, 2); /* state */
    v0151 = (v0151 == v0067 ? lisp_true : nil);
    return onevalue(v0151);

v0098:
    v0151 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v0151);

v0004:
    v0151 = v0068;
    if (!symbolp(v0151)) v0067 = nil;
    else { v0067 = qfastgets(v0151);
           if (v0067 != nil) { v0067 = elt(v0067, 18); /* phystype */
#ifdef RECORD_GET
             if (v0067 != SPID_NOPROP)
                record_get(elt(fastget_names, 18), 1);
             else record_get(elt(fastget_names, 18), 0),
                v0067 = nil; }
           else record_get(elt(fastget_names, 18), 0); }
#else
             if (v0067 == SPID_NOPROP) v0067 = nil; }}
#endif
    v0151 = elt(env, 2); /* state */
    v0151 = (v0067 == v0151 ? lisp_true : nil);
    goto v0016;
}



/* Code for prop!-simp2 */

static Lisp_Object CC_propKsimp2(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0102, v0020;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for prop-simp2");
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
    stack[-2] = v0001;
    stack[-3] = v0000;
/* end of prologue */
    v0102 = stack[-2];
    if (!consp(v0102)) goto v0096;
    v0020 = stack[-2];
    v0102 = stack[-3];
    v0102 = Lmember(nil, v0020, v0102);
    goto v0029;

v0029:
    stack[-4] = v0102;
    if (v0102 == nil) goto v0152;
    stack[-1] = (Lisp_Object)-15; /* -1 */
    v0102 = stack[-3];
    stack[0] = Llength(nil, v0102);
    nil = C_nil;
    if (exception_pending()) goto v0062;
    env = stack[-5];
    v0102 = stack[-4];
    v0102 = Llength(nil, v0102);
    nil = C_nil;
    if (exception_pending()) goto v0062;
    env = stack[-5];
    v0102 = difference2(stack[0], v0102);
    nil = C_nil;
    if (exception_pending()) goto v0062;
    env = stack[-5];
    stack[0] = Lexpt(nil, stack[-1], v0102);
    nil = C_nil;
    if (exception_pending()) goto v0062;
    env = stack[-5];
    v0020 = stack[-2];
    v0102 = stack[-3];
    v0102 = Ldelete(nil, v0020, v0102);
    nil = C_nil;
    if (exception_pending()) goto v0062;
    {
        Lisp_Object v0027 = stack[0];
        popv(6);
        return cons(v0027, v0102);
    }

v0152:
    v0102 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v0102); }

v0096:
    v0102 = qvalue(elt(env, 1)); /* nil */
    goto v0029;
/* error exit handlers */
v0062:
    popv(6);
    return nil;
}



/* Code for assert_kernelp */

static Lisp_Object CC_assert_kernelp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0098, v0024;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for assert_kernelp");
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
    v0024 = v0098;
    if (symbolp(v0024)) goto v0090;
    v0024 = v0098;
    v0024 = Lconsp(nil, v0024);
    env = stack[0];
    if (v0024 == nil) goto v0004;
    v0024 = v0098;
    v0024 = qcar(v0024);
    if (!symbolp(v0024)) v0024 = nil;
    else { v0024 = qfastgets(v0024);
           if (v0024 != nil) { v0024 = elt(v0024, 38); /* fkernfn */
#ifdef RECORD_GET
             if (v0024 != SPID_NOPROP)
                record_get(elt(fastget_names, 38), 1);
             else record_get(elt(fastget_names, 38), 0),
                v0024 = nil; }
           else record_get(elt(fastget_names, 38), 0); }
#else
             if (v0024 == SPID_NOPROP) v0024 = nil; }}
#endif
    if (v0024 == nil) goto v0078;
    v0098 = qvalue(elt(env, 1)); /* t */
    { popv(1); return onevalue(v0098); }

v0078:
    v0024 = v0098;
    v0024 = qcar(v0024);
    if (!consp(v0024)) goto v0012;
    v0024 = qvalue(elt(env, 3)); /* exlist!* */
    goto v0092;

v0092:
    v0098 = Latsoc(nil, v0098, v0024);
    { popv(1); return onevalue(v0098); }

v0012:
    v0024 = v0098;
    v0024 = qcar(v0024);
    if (!symbolp(v0024)) v0024 = nil;
    else { v0024 = qfastgets(v0024);
           if (v0024 != nil) { v0024 = elt(v0024, 24); /* klist */
#ifdef RECORD_GET
             if (v0024 != SPID_NOPROP)
                record_get(elt(fastget_names, 24), 1);
             else record_get(elt(fastget_names, 24), 0),
                v0024 = nil; }
           else record_get(elt(fastget_names, 24), 0); }
#else
             if (v0024 == SPID_NOPROP) v0024 = nil; }}
#endif
    goto v0092;

v0004:
    v0098 = qvalue(elt(env, 2)); /* nil */
    { popv(1); return onevalue(v0098); }

v0090:
    v0098 = qvalue(elt(env, 1)); /* t */
    { popv(1); return onevalue(v0098); }
}



/* Code for innprodpex */

static Lisp_Object CC_innprodpex(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0131, v0086;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for innprodpex");
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

v0154:
    v0131 = stack[-1];
    if (v0131 == nil) goto v0025;
    v0086 = stack[-2];
    v0131 = stack[-1];
    v0131 = qcar(v0131);
    v0131 = qcar(v0131);
    fn = elt(env, 2); /* innprodp2 */
    v0131 = (*qfn2(fn))(qenv(fn), v0086, v0131);
    nil = C_nil;
    if (exception_pending()) goto v0155;
    env = stack[-4];
    v0086 = v0131;
    v0131 = v0086;
    if (v0131 == nil) goto v0156;
    v0131 = v0086;
    stack[-3] = qcdr(v0131);
    v0131 = v0086;
    v0131 = qcar(v0131);
    if (v0131 == nil) goto v0024;
    v0131 = stack[-1];
    v0131 = qcar(v0131);
    v0131 = qcdr(v0131);
    fn = elt(env, 3); /* negf */
    v0131 = (*qfn1(fn))(qenv(fn), v0131);
    nil = C_nil;
    if (exception_pending()) goto v0155;
    env = stack[-4];
    stack[0] = v0131;
    goto v0066;

v0066:
    v0086 = stack[-2];
    v0131 = stack[-1];
    v0131 = qcdr(v0131);
    v0131 = CC_innprodpex(env, v0086, v0131);
    nil = C_nil;
    if (exception_pending()) goto v0155;
    {
        Lisp_Object v0157 = stack[-3];
        Lisp_Object v0144 = stack[0];
        popv(5);
        return acons(v0157, v0144, v0131);
    }

v0024:
    v0131 = stack[-1];
    v0131 = qcar(v0131);
    v0131 = qcdr(v0131);
    stack[0] = v0131;
    goto v0066;

v0156:
    v0086 = stack[-2];
    v0131 = stack[-1];
    v0131 = qcdr(v0131);
    stack[-2] = v0086;
    stack[-1] = v0131;
    goto v0154;

v0025:
    v0131 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v0131); }
/* error exit handlers */
v0155:
    popv(5);
    return nil;
}



/* Code for mv!-pow!-!> */

static Lisp_Object CC_mvKpowKS(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0018, v0091, v0092, v0093;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mv-pow->");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0091 = v0001;
    v0092 = v0000;
/* end of prologue */

v0025:
    v0018 = v0092;
    if (v0018 == nil) goto v0039;
    v0018 = v0092;
    v0093 = qcar(v0018);
    v0018 = v0091;
    v0018 = qcar(v0018);
    if (equal(v0093, v0018)) goto v0096;
    v0018 = v0092;
    v0018 = qcar(v0018);
    v0091 = qcar(v0091);
        return Lgreaterp(nil, v0018, v0091);

v0096:
    v0018 = v0092;
    v0018 = qcdr(v0018);
    v0092 = v0018;
    v0018 = v0091;
    v0018 = qcdr(v0018);
    v0091 = v0018;
    goto v0025;

v0039:
    v0018 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v0018);
}



/* Code for proper!-simpsqrt */

static Lisp_Object CC_properKsimpsqrt(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0029, v0096;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for proper-simpsqrt");
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
    v0029 = v0000;
/* end of prologue */
    v0096 = v0029;
    v0029 = elt(env, 0); /* proper!-simpsqrt */
    fn = elt(env, 1); /* carx */
    v0029 = (*qfn2(fn))(qenv(fn), v0096, v0029);
    nil = C_nil;
    if (exception_pending()) goto v0004;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* simpsqrti */
        return (*qfn1(fn))(qenv(fn), v0029);
    }
/* error exit handlers */
v0004:
    popv(1);
    return nil;
}



/* Code for ofsf_smcpknowl */

static Lisp_Object CC_ofsf_smcpknowl(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0130, v0159;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ofsf_smcpknowl");
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
    v0130 = v0000;
/* end of prologue */
    stack[-4] = v0130;
    v0130 = stack[-4];
    if (v0130 == nil) goto v0029;
    v0130 = stack[-4];
    v0130 = qcar(v0130);
    v0159 = v0130;
    v0130 = v0159;
    stack[0] = qcar(v0130);
    v0130 = v0159;
    v0159 = qcdr(v0130);
    v0130 = qvalue(elt(env, 1)); /* nil */
    v0130 = Lappend(nil, v0159, v0130);
    nil = C_nil;
    if (exception_pending()) goto v0160;
    env = stack[-5];
    v0130 = cons(stack[0], v0130);
    nil = C_nil;
    if (exception_pending()) goto v0160;
    env = stack[-5];
    v0130 = ncons(v0130);
    nil = C_nil;
    if (exception_pending()) goto v0160;
    env = stack[-5];
    stack[-2] = v0130;
    stack[-3] = v0130;
    goto v0090;

v0090:
    v0130 = stack[-4];
    v0130 = qcdr(v0130);
    stack[-4] = v0130;
    v0130 = stack[-4];
    if (v0130 == nil) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    stack[-1] = stack[-2];
    v0130 = stack[-4];
    v0130 = qcar(v0130);
    v0159 = v0130;
    v0130 = v0159;
    stack[0] = qcar(v0130);
    v0130 = v0159;
    v0159 = qcdr(v0130);
    v0130 = qvalue(elt(env, 1)); /* nil */
    v0130 = Lappend(nil, v0159, v0130);
    nil = C_nil;
    if (exception_pending()) goto v0160;
    env = stack[-5];
    v0130 = cons(stack[0], v0130);
    nil = C_nil;
    if (exception_pending()) goto v0160;
    env = stack[-5];
    v0130 = ncons(v0130);
    nil = C_nil;
    if (exception_pending()) goto v0160;
    env = stack[-5];
    v0130 = Lrplacd(nil, stack[-1], v0130);
    nil = C_nil;
    if (exception_pending()) goto v0160;
    env = stack[-5];
    v0130 = stack[-2];
    v0130 = qcdr(v0130);
    stack[-2] = v0130;
    goto v0090;

v0029:
    v0130 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v0130); }
/* error exit handlers */
v0160:
    popv(6);
    return nil;
}



/* Code for pasf_dt */

static Lisp_Object CC_pasf_dt(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0200, v0201, v0202, v0203;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pasf_dt");
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
    v0201 = stack[0];
    v0200 = elt(env, 1); /* true */
    if (v0201 == v0200) goto v0096;
    v0201 = stack[0];
    v0200 = elt(env, 3); /* false */
    v0200 = (v0201 == v0200 ? lisp_true : nil);
    goto v0029;

v0029:
    if (!(v0200 == nil)) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v0200 = stack[0];
    v0200 = qcdr(v0200);
    v0200 = qcar(v0200);
    fn = elt(env, 18); /* pasf_pdp */
    v0200 = (*qfn1(fn))(qenv(fn), v0200);
    nil = C_nil;
    if (exception_pending()) goto v0204;
    env = stack[-1];
    v0203 = v0200;
    v0201 = stack[0];
    v0200 = elt(env, 1); /* true */
    if (v0201 == v0200) goto v0153;
    v0201 = stack[0];
    v0200 = elt(env, 3); /* false */
    v0200 = (v0201 == v0200 ? lisp_true : nil);
    goto v0093;

v0093:
    if (v0200 == nil) goto v0091;
    v0200 = stack[0];
    goto v0021;

v0021:
    v0202 = v0200;
    v0201 = v0203;
    v0200 = elt(env, 4); /* pdef */
    if (v0201 == v0200) goto v0057;
    v0200 = qvalue(elt(env, 6)); /* nil */
    goto v0160;

v0160:
    if (v0200 == nil) goto v0205;
    v0200 = elt(env, 3); /* false */
    { popv(2); return onevalue(v0200); }

v0205:
    v0201 = v0203;
    v0200 = elt(env, 7); /* ndef */
    if (v0201 == v0200) goto v0206;
    v0200 = qvalue(elt(env, 6)); /* nil */
    goto v0207;

v0207:
    if (v0200 == nil) goto v0208;
    v0200 = elt(env, 3); /* false */
    { popv(2); return onevalue(v0200); }

v0208:
    v0201 = v0203;
    v0200 = elt(env, 4); /* pdef */
    if (v0201 == v0200) goto v0209;
    v0200 = qvalue(elt(env, 6)); /* nil */
    goto v0148;

v0148:
    if (v0200 == nil) goto v0210;
    v0200 = elt(env, 1); /* true */
    { popv(2); return onevalue(v0200); }

v0210:
    v0201 = v0203;
    v0200 = elt(env, 7); /* ndef */
    if (v0201 == v0200) goto v0135;
    v0200 = qvalue(elt(env, 6)); /* nil */
    goto v0211;

v0211:
    if (v0200 == nil) goto v0212;
    v0200 = elt(env, 1); /* true */
    { popv(2); return onevalue(v0200); }

v0212:
    v0201 = v0203;
    v0200 = elt(env, 11); /* psdef */
    if (v0201 == v0200) goto v0213;
    v0200 = qvalue(elt(env, 6)); /* nil */
    goto v0214;

v0214:
    if (v0200 == nil) goto v0215;
    v0200 = elt(env, 3); /* false */
    { popv(2); return onevalue(v0200); }

v0215:
    v0201 = v0203;
    v0200 = elt(env, 13); /* nsdef */
    if (v0201 == v0200) goto v0216;
    v0200 = qvalue(elt(env, 6)); /* nil */
    goto v0125;

v0125:
    if (v0200 == nil) goto v0217;
    v0200 = elt(env, 3); /* false */
    { popv(2); return onevalue(v0200); }

v0217:
    v0201 = v0203;
    v0200 = elt(env, 11); /* psdef */
    if (v0201 == v0200) goto v0218;
    v0200 = qvalue(elt(env, 6)); /* nil */
    goto v0219;

v0219:
    if (v0200 == nil) goto v0220;
    v0200 = elt(env, 1); /* true */
    { popv(2); return onevalue(v0200); }

v0220:
    v0201 = v0203;
    v0200 = elt(env, 13); /* nsdef */
    if (v0201 == v0200) goto v0221;
    v0200 = qvalue(elt(env, 6)); /* nil */
    goto v0222;

v0222:
    if (v0200 == nil) goto v0223;
    v0200 = elt(env, 1); /* true */
    { popv(2); return onevalue(v0200); }

v0223:
    v0201 = v0203;
    v0200 = elt(env, 11); /* psdef */
    if (v0201 == v0200) goto v0224;
    v0200 = qvalue(elt(env, 6)); /* nil */
    goto v0225;

v0225:
    if (v0200 == nil) goto v0226;
    v0201 = elt(env, 14); /* greaterp */
    v0200 = stack[0];
    v0200 = qcdr(v0200);
    v0200 = qcar(v0200);
    v0202 = qvalue(elt(env, 6)); /* nil */
    popv(2);
    return list3(v0201, v0200, v0202);

v0226:
    v0201 = v0203;
    v0200 = elt(env, 13); /* nsdef */
    if (v0201 == v0200) goto v0227;
    v0200 = qvalue(elt(env, 6)); /* nil */
    goto v0228;

v0228:
    if (v0200 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v0201 = elt(env, 12); /* lessp */
    v0200 = stack[0];
    v0200 = qcdr(v0200);
    v0200 = qcar(v0200);
    v0202 = qvalue(elt(env, 6)); /* nil */
    popv(2);
    return list3(v0201, v0200, v0202);

v0227:
    v0201 = v0202;
    v0200 = elt(env, 17); /* neq */
    v0200 = (v0201 == v0200 ? lisp_true : nil);
    goto v0228;

v0224:
    v0201 = v0202;
    v0200 = elt(env, 17); /* neq */
    v0200 = (v0201 == v0200 ? lisp_true : nil);
    goto v0225;

v0221:
    v0201 = v0202;
    v0200 = elt(env, 16); /* leq */
    v0200 = (v0201 == v0200 ? lisp_true : nil);
    goto v0222;

v0218:
    v0201 = v0202;
    v0200 = elt(env, 15); /* geq */
    v0200 = (v0201 == v0200 ? lisp_true : nil);
    goto v0219;

v0216:
    v0201 = v0202;
    v0200 = elt(env, 14); /* greaterp */
    v0200 = (v0201 == v0200 ? lisp_true : nil);
    goto v0125;

v0213:
    v0201 = v0202;
    v0200 = elt(env, 12); /* lessp */
    v0200 = (v0201 == v0200 ? lisp_true : nil);
    goto v0214;

v0135:
    v0201 = v0202;
    v0200 = elt(env, 10); /* (neq lessp leq) */
    v0200 = Lmemq(nil, v0201, v0200);
    goto v0211;

v0209:
    v0201 = v0202;
    v0200 = elt(env, 9); /* (neq greaterp geq) */
    v0200 = Lmemq(nil, v0201, v0200);
    goto v0148;

v0206:
    v0201 = v0202;
    v0200 = elt(env, 8); /* (equal greaterp geq) */
    v0200 = Lmemq(nil, v0201, v0200);
    goto v0207;

v0057:
    v0201 = v0202;
    v0200 = elt(env, 5); /* (equal lessp leq) */
    v0200 = Lmemq(nil, v0201, v0200);
    goto v0160;

v0091:
    v0200 = stack[0];
    v0200 = qcar(v0200);
    v0200 = Lconsp(nil, v0200);
    env = stack[-1];
    if (v0200 == nil) goto v0131;
    v0200 = stack[0];
    v0200 = qcar(v0200);
    v0200 = qcar(v0200);
    goto v0021;

v0131:
    v0200 = stack[0];
    v0200 = qcar(v0200);
    goto v0021;

v0153:
    v0200 = qvalue(elt(env, 2)); /* t */
    goto v0093;

v0096:
    v0200 = qvalue(elt(env, 2)); /* t */
    goto v0029;
/* error exit handlers */
v0204:
    popv(2);
    return nil;
}



/* Code for vdp_plist */

static Lisp_Object CC_vdp_plist(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object v0039;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for vdp_plist");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0039 = v0000;
/* end of prologue */
    v0039 = qcdr(v0039);
    v0039 = qcdr(v0039);
    v0039 = qcdr(v0039);
    v0039 = qcdr(v0039);
    v0039 = qcar(v0039);
    return onevalue(v0039);
}



/* Code for sfto_b!:extadd */

static Lisp_Object CC_sfto_bTextadd(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0196, v0148, v0232;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sfto_b:extadd");
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
    goto v0016;

v0016:
    v0196 = stack[-2];
    if (v0196 == nil) goto v0004;
    v0196 = stack[-1];
    if (v0196 == nil) goto v0003;
    v0196 = stack[-2];
    v0196 = qcar(v0196);
    v0148 = qcar(v0196);
    v0196 = stack[-1];
    v0196 = qcar(v0196);
    v0196 = qcar(v0196);
    if (equal(v0148, v0196)) goto v0023;
    v0196 = stack[-2];
    v0196 = qcar(v0196);
    v0148 = qcar(v0196);
    v0196 = stack[-1];
    v0196 = qcar(v0196);
    v0196 = qcar(v0196);
    fn = elt(env, 1); /* sfto_b!:ordexp */
    v0196 = (*qfn2(fn))(qenv(fn), v0148, v0196);
    nil = C_nil;
    if (exception_pending()) goto v0115;
    env = stack[-4];
    if (v0196 == nil) goto v0050;
    v0196 = stack[-2];
    v0148 = qcar(v0196);
    v0196 = stack[0];
    v0196 = cons(v0148, v0196);
    nil = C_nil;
    if (exception_pending()) goto v0115;
    env = stack[-4];
    stack[0] = v0196;
    v0196 = stack[-2];
    v0196 = qcdr(v0196);
    stack[-2] = v0196;
    goto v0016;

v0050:
    v0196 = stack[-1];
    v0148 = qcar(v0196);
    v0196 = stack[0];
    v0196 = cons(v0148, v0196);
    nil = C_nil;
    if (exception_pending()) goto v0115;
    env = stack[-4];
    stack[0] = v0196;
    v0196 = stack[-1];
    v0196 = qcdr(v0196);
    stack[-1] = v0196;
    goto v0016;

v0023:
    stack[-3] = stack[0];
    v0196 = stack[-2];
    v0196 = qcar(v0196);
    v0148 = qcdr(v0196);
    v0196 = stack[-1];
    v0196 = qcar(v0196);
    v0196 = qcdr(v0196);
    fn = elt(env, 2); /* addf */
    stack[0] = (*qfn2(fn))(qenv(fn), v0148, v0196);
    nil = C_nil;
    if (exception_pending()) goto v0115;
    env = stack[-4];
    v0196 = stack[-2];
    v0148 = qcdr(v0196);
    v0196 = stack[-1];
    v0196 = qcdr(v0196);
    v0196 = CC_sfto_bTextadd(env, v0148, v0196);
    nil = C_nil;
    if (exception_pending()) goto v0115;
    env = stack[-4];
    v0148 = stack[0];
    v0232 = v0148;
    if (v0232 == nil) goto v0022;
    v0232 = stack[-2];
    v0232 = qcar(v0232);
    v0232 = qcar(v0232);
    v0196 = acons(v0232, v0148, v0196);
    nil = C_nil;
    if (exception_pending()) goto v0115;
    env = stack[-4];
    goto v0022;

v0022:
    {
        Lisp_Object v0116 = stack[-3];
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0116, v0196);
    }

v0003:
    v0148 = stack[0];
    v0196 = stack[-2];
    {
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0148, v0196);
    }

v0004:
    v0148 = stack[0];
    v0196 = stack[-1];
    {
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0148, v0196);
    }
/* error exit handlers */
v0115:
    popv(5);
    return nil;
}



/* Code for fnrd */

static Lisp_Object MS_CDECL CC_fnrd(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0018, v0091;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "fnrd");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for fnrd");
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
    stack[0] = nil;
    fn = elt(env, 3); /* lex */
    v0018 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0093;
    env = stack[-1];
    v0091 = qvalue(elt(env, 1)); /* char */
    v0018 = elt(env, 2); /* (c i) */
    if (equal(v0091, v0018)) goto v0002;
    v0018 = qvalue(elt(env, 1)); /* char */
    v0091 = Lcompress(nil, v0018);
    nil = C_nil;
    if (exception_pending()) goto v0093;
    env = stack[-1];
    v0018 = (Lisp_Object)321; /* 20 */
    fn = elt(env, 4); /* errorml */
    v0018 = (*qfn2(fn))(qenv(fn), v0091, v0018);
    nil = C_nil;
    if (exception_pending()) goto v0093;
    env = stack[-1];
    goto v0016;

v0016:
    v0018 = stack[0];
    if (!(!consp(v0018))) goto v0008;
    v0018 = stack[0];
    v0018 = ncons(v0018);
    nil = C_nil;
    if (exception_pending()) goto v0093;
    env = stack[-1];
    fn = elt(env, 5); /* operator */
    v0018 = (*qfn1(fn))(qenv(fn), v0018);
    nil = C_nil;
    if (exception_pending()) goto v0093;
    env = stack[-1];
    fn = elt(env, 6); /* aeval */
    v0018 = (*qfn1(fn))(qenv(fn), v0018);
    nil = C_nil;
    if (exception_pending()) goto v0093;
    env = stack[-1];
    goto v0008;

v0008:
    fn = elt(env, 3); /* lex */
    v0018 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0093;
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }

v0002:
    fn = elt(env, 7); /* mathml2 */
    v0018 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0093;
    env = stack[-1];
    stack[0] = v0018;
    goto v0016;
/* error exit handlers */
v0093:
    popv(2);
    return nil;
}



/* Code for gftimes */

static Lisp_Object CC_gftimes(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0007, v0012, v0008;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for gftimes");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0012 = v0001;
    v0008 = v0000;
/* end of prologue */
    v0007 = v0008;
    v0007 = qcar(v0007);
    if (!consp(v0007)) goto v0030;
    v0007 = v0008;
    {
        fn = elt(env, 1); /* gbftimes */
        return (*qfn2(fn))(qenv(fn), v0007, v0012);
    }

v0030:
    v0007 = v0008;
    {
        fn = elt(env, 2); /* gfftimes */
        return (*qfn2(fn))(qenv(fn), v0007, v0012);
    }
}



/* Code for !*pf2sq */

static Lisp_Object CC_Hpf2sq(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0143, v0234;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for *pf2sq");
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
    v0234 = qvalue(elt(env, 1)); /* nil */
    v0143 = (Lisp_Object)17; /* 1 */
    v0143 = cons(v0234, v0143);
    nil = C_nil;
    if (exception_pending()) goto v0120;
    env = stack[-2];
    stack[-1] = v0143;
    v0143 = stack[0];
    if (v0143 == nil) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v0143 = stack[0];
    stack[0] = v0143;
    goto v0009;

v0009:
    v0143 = stack[0];
    if (v0143 == nil) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v0143 = stack[0];
    v0143 = qcar(v0143);
    v0234 = qcar(v0143);
    v0143 = (Lisp_Object)17; /* 1 */
    if (v0234 == v0143) goto v0064;
    v0143 = stack[0];
    v0143 = qcar(v0143);
    v0234 = qcar(v0143);
    v0143 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 2); /* to */
    v0234 = (*qfn2(fn))(qenv(fn), v0234, v0143);
    nil = C_nil;
    if (exception_pending()) goto v0120;
    env = stack[-2];
    v0143 = (Lisp_Object)17; /* 1 */
    v0143 = cons(v0234, v0143);
    nil = C_nil;
    if (exception_pending()) goto v0120;
    env = stack[-2];
    v0234 = ncons(v0143);
    nil = C_nil;
    if (exception_pending()) goto v0120;
    env = stack[-2];
    v0143 = (Lisp_Object)17; /* 1 */
    v0143 = cons(v0234, v0143);
    nil = C_nil;
    if (exception_pending()) goto v0120;
    env = stack[-2];
    v0234 = v0143;
    goto v0018;

v0018:
    v0143 = stack[0];
    v0143 = qcar(v0143);
    v0143 = qcdr(v0143);
    fn = elt(env, 3); /* multsq */
    v0234 = (*qfn2(fn))(qenv(fn), v0234, v0143);
    nil = C_nil;
    if (exception_pending()) goto v0120;
    env = stack[-2];
    v0143 = stack[-1];
    fn = elt(env, 4); /* addsq */
    v0143 = (*qfn2(fn))(qenv(fn), v0234, v0143);
    nil = C_nil;
    if (exception_pending()) goto v0120;
    env = stack[-2];
    stack[-1] = v0143;
    v0143 = stack[0];
    v0143 = qcdr(v0143);
    stack[0] = v0143;
    goto v0009;

v0064:
    v0234 = (Lisp_Object)17; /* 1 */
    v0143 = (Lisp_Object)17; /* 1 */
    v0143 = cons(v0234, v0143);
    nil = C_nil;
    if (exception_pending()) goto v0120;
    env = stack[-2];
    v0234 = v0143;
    goto v0018;
/* error exit handlers */
v0120:
    popv(3);
    return nil;
}



/* Code for contract!-strand */

static Lisp_Object CC_contractKstrand(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0096, v0004;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for contract-strand");
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
    v0096 = v0001;
    v0004 = v0000;
/* end of prologue */
    stack[0] = v0004;
    fn = elt(env, 1); /* zero!-roads */
    v0096 = (*qfn1(fn))(qenv(fn), v0096);
    nil = C_nil;
    if (exception_pending()) goto v0095;
    env = stack[-1];
    {
        Lisp_Object v0100 = stack[0];
        popv(2);
        fn = elt(env, 2); /* contr!-strand */
        return (*qfn2(fn))(qenv(fn), v0100, v0096);
    }
/* error exit handlers */
v0095:
    popv(2);
    return nil;
}



/* Code for no!-side!-effectp */

static Lisp_Object CC_noKsideKeffectp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0064, v0152;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for no-side-effectp");
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
    v0064 = stack[0];
    if (!consp(v0064)) goto v0026;
    v0064 = stack[0];
    v0152 = qcar(v0064);
    v0064 = elt(env, 2); /* quote */
    if (v0152 == v0064) goto v0012;
    v0064 = stack[0];
    v0152 = qcar(v0064);
    v0064 = elt(env, 4); /* nosideeffects */
    v0064 = Lflagp(nil, v0152, v0064);
    env = stack[-1];
    if (v0064 == nil) goto v0066;
    v0064 = stack[0];
    v0064 = qcdr(v0064);
    {
        popv(2);
        fn = elt(env, 5); /* no!-side!-effect!-listp */
        return (*qfn1(fn))(qenv(fn), v0064);
    }

v0066:
    v0064 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v0064); }

v0012:
    v0064 = qvalue(elt(env, 3)); /* t */
    { popv(2); return onevalue(v0064); }

v0026:
    v0064 = stack[0];
    v0064 = (is_number(v0064) ? lisp_true : nil);
    if (!(v0064 == nil)) { popv(2); return onevalue(v0064); }
    v0064 = stack[0];
    if (symbolp(v0064)) goto v0069;
    v0064 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v0064); }

v0069:
    v0064 = stack[0];
    v0064 = Lsymbol_specialp(nil, v0064);
    nil = C_nil;
    if (exception_pending()) goto v0019;
    env = stack[-1];
    if (!(v0064 == nil)) goto v0097;
    v0064 = stack[0];
    v0064 = Lsymbol_globalp(nil, v0064);
    goto v0097;

v0097:
    v0064 = (v0064 == nil ? lisp_true : nil);
    { popv(2); return onevalue(v0064); }
/* error exit handlers */
v0019:
    popv(2);
    return nil;
}



/* Code for matop_pseudomod */

static Lisp_Object CC_matop_pseudomod(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0096, v0004;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for matop_pseudomod");
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
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0096 = v0001;
    v0004 = v0000;
/* end of prologue */
    fn = elt(env, 1); /* mod!* */
    v0096 = (*qfn2(fn))(qenv(fn), v0004, v0096);
    errexit();
    v0096 = qcar(v0096);
    return onevalue(v0096);
}



/* Code for simp!-prop1 */

static Lisp_Object CC_simpKprop1(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0286, v0287, v0288;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for simp-prop1");
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
    push(nil);
/* copy arguments values to proper place */
    stack[-3] = v0001;
    stack[-4] = v0000;
/* end of prologue */

v0154:
    v0286 = stack[-4];
    if (!consp(v0286)) goto v0228;
    v0286 = stack[-4];
    v0287 = qcar(v0286);
    v0286 = qvalue(elt(env, 1)); /* !'and */
    if (equal(v0287, v0286)) goto v0077;
    v0286 = qvalue(elt(env, 2)); /* nil */
    goto v0078;

v0078:
    if (!(v0286 == nil)) goto v0095;
    v0286 = stack[-4];
    v0287 = qcar(v0286);
    v0286 = qvalue(elt(env, 3)); /* !'or */
    if (equal(v0287, v0286)) goto v0149;
    v0286 = qvalue(elt(env, 2)); /* nil */
    goto v0087;

v0087:
    if (!(v0286 == nil)) goto v0095;
    v0286 = stack[-4];
    v0287 = qcar(v0286);
    v0286 = qvalue(elt(env, 3)); /* !'or */
    if (equal(v0287, v0286)) goto v0056;
    v0286 = qvalue(elt(env, 2)); /* nil */
    goto v0059;

v0059:
    if (!(v0286 == nil)) goto v0101;
    v0286 = stack[-4];
    v0287 = qcar(v0286);
    v0286 = qvalue(elt(env, 1)); /* !'and */
    if (equal(v0287, v0286)) goto v0198;
    v0286 = qvalue(elt(env, 2)); /* nil */
    goto v0142;

v0142:
    if (!(v0286 == nil)) goto v0101;
    v0286 = stack[-4];
    v0287 = qcar(v0286);
    v0286 = elt(env, 4); /* not */
    if (v0287 == v0286) goto v0111;
    v0286 = stack[-4];
    v0287 = qcar(v0286);
    v0286 = elt(env, 5); /* implies */
    if (v0287 == v0286) goto v0289;
    v0286 = stack[-4];
    v0287 = qcar(v0286);
    v0286 = elt(env, 8); /* equiv */
    if (!(v0287 == v0286)) goto v0090;
    stack[-5] = elt(env, 6); /* or */
    v0288 = elt(env, 9); /* and */
    v0286 = stack[-4];
    v0286 = qcdr(v0286);
    v0287 = qcar(v0286);
    v0286 = stack[-4];
    v0286 = qcdr(v0286);
    v0286 = qcdr(v0286);
    v0286 = qcar(v0286);
    stack[-2] = list3(v0288, v0287, v0286);
    nil = C_nil;
    if (exception_pending()) goto v0290;
    env = stack[-6];
    stack[-1] = elt(env, 9); /* and */
    v0287 = elt(env, 4); /* not */
    v0286 = stack[-4];
    v0286 = qcdr(v0286);
    v0286 = qcar(v0286);
    stack[0] = list2(v0287, v0286);
    nil = C_nil;
    if (exception_pending()) goto v0290;
    env = stack[-6];
    v0287 = elt(env, 4); /* not */
    v0286 = stack[-4];
    v0286 = qcdr(v0286);
    v0286 = qcdr(v0286);
    v0286 = qcar(v0286);
    v0286 = list2(v0287, v0286);
    nil = C_nil;
    if (exception_pending()) goto v0290;
    env = stack[-6];
    v0286 = list3(stack[-1], stack[0], v0286);
    nil = C_nil;
    if (exception_pending()) goto v0290;
    env = stack[-6];
    v0287 = list3(stack[-5], stack[-2], v0286);
    nil = C_nil;
    if (exception_pending()) goto v0290;
    env = stack[-6];
    v0286 = stack[-3];
    v0286 = CC_simpKprop1(env, v0287, v0286);
    nil = C_nil;
    if (exception_pending()) goto v0290;
    stack[0] = v0286;
    { Lisp_Object res = stack[0]; popv(7); return onevalue(res); }

v0090:
    v0286 = stack[-4];
    fn = elt(env, 18); /* reval */
    v0286 = (*qfn1(fn))(qenv(fn), v0286);
    nil = C_nil;
    if (exception_pending()) goto v0290;
    env = stack[-6];
    stack[-4] = v0286;
    v0287 = stack[-4];
    v0286 = elt(env, 14); /* boolean */
    if (!consp(v0287)) goto v0291;
    v0287 = qcar(v0287);
    if (!(v0287 == v0286)) goto v0291;
    v0286 = stack[-4];
    v0286 = qcdr(v0286);
    v0287 = qcar(v0286);
    v0286 = stack[-3];
    stack[-4] = v0287;
    stack[-3] = v0286;
    goto v0154;

v0291:
    v0286 = stack[-3];
    if (v0286 == nil) goto v0292;
    v0286 = elt(env, 15); /* prop!* */
    v0287 = v0286;
    goto v0293;

v0293:
    v0286 = stack[-4];
    v0286 = list2(v0287, v0286);
    nil = C_nil;
    if (exception_pending()) goto v0290;
    env = stack[-6];
    fn = elt(env, 19); /* simp */
    v0286 = (*qfn1(fn))(qenv(fn), v0286);
    nil = C_nil;
    if (exception_pending()) goto v0290;
    env = stack[-6];
    v0286 = qcar(v0286);
    stack[0] = v0286;
    v0287 = stack[-4];
    v0286 = qvalue(elt(env, 17)); /* propvars!* */
    v0286 = Lmember(nil, v0287, v0286);
    if (!(v0286 == nil)) { Lisp_Object res = stack[0]; popv(7); return onevalue(res); }
    v0287 = stack[-4];
    v0286 = qvalue(elt(env, 17)); /* propvars!* */
    v0286 = cons(v0287, v0286);
    nil = C_nil;
    if (exception_pending()) goto v0290;
    env = stack[-6];
    qvalue(elt(env, 17)) = v0286; /* propvars!* */
    { Lisp_Object res = stack[0]; popv(7); return onevalue(res); }

v0292:
    v0286 = elt(env, 16); /* not_prop!* */
    v0287 = v0286;
    goto v0293;

v0289:
    v0286 = stack[-3];
    if (v0286 == nil) goto v0294;
    stack[0] = elt(env, 6); /* or */
    v0287 = elt(env, 4); /* not */
    v0286 = stack[-4];
    v0286 = qcdr(v0286);
    v0286 = qcar(v0286);
    v0287 = list2(v0287, v0286);
    nil = C_nil;
    if (exception_pending()) goto v0290;
    env = stack[-6];
    v0286 = stack[-4];
    v0286 = qcdr(v0286);
    v0286 = qcdr(v0286);
    v0286 = qcar(v0286);
    v0287 = list3(stack[0], v0287, v0286);
    nil = C_nil;
    if (exception_pending()) goto v0290;
    env = stack[-6];
    v0286 = qvalue(elt(env, 7)); /* t */
    v0286 = CC_simpKprop1(env, v0287, v0286);
    nil = C_nil;
    if (exception_pending()) goto v0290;
    stack[0] = v0286;
    { Lisp_Object res = stack[0]; popv(7); return onevalue(res); }

v0294:
    stack[0] = elt(env, 6); /* or */
    v0287 = elt(env, 4); /* not */
    v0286 = stack[-4];
    v0286 = qcdr(v0286);
    v0286 = qcdr(v0286);
    v0286 = qcar(v0286);
    v0287 = list2(v0287, v0286);
    nil = C_nil;
    if (exception_pending()) goto v0290;
    env = stack[-6];
    v0286 = stack[-4];
    v0286 = qcdr(v0286);
    v0286 = qcar(v0286);
    v0287 = list3(stack[0], v0287, v0286);
    nil = C_nil;
    if (exception_pending()) goto v0290;
    env = stack[-6];
    v0286 = qvalue(elt(env, 7)); /* t */
    v0286 = CC_simpKprop1(env, v0287, v0286);
    nil = C_nil;
    if (exception_pending()) goto v0290;
    stack[0] = v0286;
    { Lisp_Object res = stack[0]; popv(7); return onevalue(res); }

v0111:
    v0286 = stack[-4];
    v0286 = qcdr(v0286);
    v0287 = qcar(v0286);
    v0286 = stack[-3];
    v0286 = (v0286 == nil ? lisp_true : nil);
    v0286 = CC_simpKprop1(env, v0287, v0286);
    nil = C_nil;
    if (exception_pending()) goto v0290;
    stack[0] = v0286;
    { Lisp_Object res = stack[0]; popv(7); return onevalue(res); }

v0101:
    v0286 = qvalue(elt(env, 2)); /* nil */
    stack[0] = v0286;
    v0286 = stack[-4];
    v0286 = qcdr(v0286);
    stack[-1] = v0286;
    goto v0046;

v0046:
    v0286 = stack[-1];
    if (v0286 == nil) { Lisp_Object res = stack[0]; popv(7); return onevalue(res); }
    v0286 = stack[-1];
    v0286 = qcar(v0286);
    v0287 = v0286;
    v0286 = stack[-3];
    v0286 = CC_simpKprop1(env, v0287, v0286);
    nil = C_nil;
    if (exception_pending()) goto v0290;
    env = stack[-6];
    fn = elt(env, 20); /* addf */
    v0286 = (*qfn2(fn))(qenv(fn), stack[0], v0286);
    nil = C_nil;
    if (exception_pending()) goto v0290;
    env = stack[-6];
    stack[0] = v0286;
    v0286 = stack[-1];
    v0286 = qcdr(v0286);
    stack[-1] = v0286;
    goto v0046;

v0198:
    v0286 = stack[-3];
    v0286 = (v0286 == nil ? lisp_true : nil);
    goto v0142;

v0056:
    v0286 = stack[-3];
    goto v0059;

v0095:
    v0286 = (Lisp_Object)17; /* 1 */
    stack[0] = v0286;
    v0286 = stack[-4];
    v0286 = qcdr(v0286);
    stack[-1] = v0286;
    goto v0064;

v0064:
    v0286 = stack[-1];
    if (v0286 == nil) { Lisp_Object res = stack[0]; popv(7); return onevalue(res); }
    v0286 = stack[-1];
    v0286 = qcar(v0286);
    v0287 = v0286;
    v0286 = stack[-3];
    v0286 = CC_simpKprop1(env, v0287, v0286);
    nil = C_nil;
    if (exception_pending()) goto v0290;
    env = stack[-6];
    fn = elt(env, 21); /* multf */
    v0286 = (*qfn2(fn))(qenv(fn), stack[0], v0286);
    nil = C_nil;
    if (exception_pending()) goto v0290;
    env = stack[-6];
    stack[0] = v0286;
    v0286 = stack[-1];
    v0286 = qcdr(v0286);
    stack[-1] = v0286;
    goto v0064;

v0149:
    v0286 = stack[-3];
    v0286 = (v0286 == nil ? lisp_true : nil);
    goto v0087;

v0077:
    v0286 = stack[-3];
    goto v0078;

v0228:
    v0287 = stack[-4];
    v0286 = (Lisp_Object)17; /* 1 */
    if (v0287 == v0286) goto v0295;
    v0287 = stack[-4];
    v0286 = qvalue(elt(env, 7)); /* t */
    if (equal(v0287, v0286)) goto v0296;
    v0287 = stack[-4];
    v0286 = elt(env, 10); /* true */
    v0286 = (v0287 == v0286 ? lisp_true : nil);
    goto v0297;

v0297:
    if (v0286 == nil) goto v0298;
    v0286 = stack[-3];
    stack[-4] = v0286;
    goto v0299;

v0299:
    v0287 = stack[-4];
    v0286 = qvalue(elt(env, 7)); /* t */
    if (equal(v0287, v0286)) goto v0300;
    v0286 = stack[-4];
    if (!(v0286 == nil)) goto v0090;
    v0287 = elt(env, 13); /* (and !*true (not !*true)) */
    v0286 = qvalue(elt(env, 7)); /* t */
    stack[-4] = v0287;
    stack[-3] = v0286;
    goto v0154;

v0300:
    v0287 = elt(env, 12); /* (or !*true (not !*true)) */
    v0286 = qvalue(elt(env, 7)); /* t */
    stack[-4] = v0287;
    stack[-3] = v0286;
    goto v0154;

v0298:
    v0287 = stack[-4];
    v0286 = (Lisp_Object)1; /* 0 */
    if (v0287 == v0286) goto v0202;
    v0286 = stack[-4];
    if (v0286 == nil) goto v0301;
    v0287 = stack[-4];
    v0286 = elt(env, 11); /* false */
    v0286 = (v0287 == v0286 ? lisp_true : nil);
    goto v0201;

v0201:
    if (v0286 == nil) goto v0299;
    v0286 = stack[-3];
    v0286 = (v0286 == nil ? lisp_true : nil);
    stack[-4] = v0286;
    goto v0299;

v0301:
    v0286 = qvalue(elt(env, 7)); /* t */
    goto v0201;

v0202:
    v0286 = qvalue(elt(env, 7)); /* t */
    goto v0201;

v0296:
    v0286 = qvalue(elt(env, 7)); /* t */
    goto v0297;

v0295:
    v0286 = qvalue(elt(env, 7)); /* t */
    goto v0297;
/* error exit handlers */
v0290:
    popv(7);
    return nil;
}



/* Code for !*multf */

static Lisp_Object CC_Hmultf(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0365, v0366, v0367;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for *multf");
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
    stack[-2] = v0001;
    stack[-3] = v0000;
/* end of prologue */
    v0365 = stack[-3];
    if (v0365 == nil) goto v0095;
    v0365 = stack[-2];
    v0365 = (v0365 == nil ? lisp_true : nil);
    goto v0005;

v0005:
    if (v0365 == nil) goto v0006;
    v0365 = qvalue(elt(env, 2)); /* nil */
    { popv(6); return onevalue(v0365); }

v0006:
    v0366 = stack[-3];
    v0365 = (Lisp_Object)17; /* 1 */
    if (v0366 == v0365) goto v0003;
    v0366 = stack[-2];
    v0365 = (Lisp_Object)17; /* 1 */
    if (v0366 == v0365) goto v0015;
    v0365 = stack[-3];
    if (!consp(v0365)) goto v0067;
    v0365 = stack[-3];
    v0365 = qcar(v0365);
    v0365 = (consp(v0365) ? nil : lisp_true);
    goto v0151;

v0151:
    if (v0365 == nil) goto v0024;
    stack[0] = stack[-3];
    v0365 = stack[-2];
    fn = elt(env, 7); /* squashsqrt */
    v0365 = (*qfn1(fn))(qenv(fn), v0365);
    nil = C_nil;
    if (exception_pending()) goto v0368;
    env = stack[-5];
    {
        Lisp_Object v0369 = stack[0];
        popv(6);
        fn = elt(env, 8); /* multd */
        return (*qfn2(fn))(qenv(fn), v0369, v0365);
    }

v0024:
    v0365 = stack[-2];
    if (!consp(v0365)) goto v0131;
    v0365 = stack[-2];
    v0365 = qcar(v0365);
    v0365 = (consp(v0365) ? nil : lisp_true);
    goto v0099;

v0099:
    if (v0365 == nil) goto v0028;
    stack[0] = stack[-2];
    v0365 = stack[-3];
    fn = elt(env, 7); /* squashsqrt */
    v0365 = (*qfn1(fn))(qenv(fn), v0365);
    nil = C_nil;
    if (exception_pending()) goto v0368;
    env = stack[-5];
    {
        Lisp_Object v0370 = stack[0];
        popv(6);
        fn = elt(env, 8); /* multd */
        return (*qfn2(fn))(qenv(fn), v0370, v0365);
    }

v0028:
    v0365 = qvalue(elt(env, 3)); /* !*noncomp */
    if (v0365 == nil) goto v0030;
    v0366 = stack[-3];
    v0365 = stack[-2];
    {
        popv(6);
        fn = elt(env, 9); /* multf */
        return (*qfn2(fn))(qenv(fn), v0366, v0365);
    }

v0030:
    v0365 = stack[-3];
    v0365 = qcar(v0365);
    v0365 = qcar(v0365);
    v0365 = qcar(v0365);
    stack[0] = v0365;
    v0365 = stack[-2];
    v0365 = qcar(v0365);
    v0365 = qcar(v0365);
    v0365 = qcar(v0365);
    stack[-1] = v0365;
    v0366 = stack[0];
    v0365 = stack[-1];
    if (v0366 == v0365) goto v0371;
    v0366 = stack[0];
    v0365 = stack[-1];
    fn = elt(env, 10); /* ordop */
    v0365 = (*qfn2(fn))(qenv(fn), v0366, v0365);
    nil = C_nil;
    if (exception_pending()) goto v0368;
    env = stack[-5];
    if (v0365 == nil) goto v0132;
    v0365 = stack[-3];
    v0365 = qcar(v0365);
    v0366 = qcdr(v0365);
    v0365 = stack[-2];
    v0365 = CC_Hmultf(env, v0366, v0365);
    nil = C_nil;
    if (exception_pending()) goto v0368;
    env = stack[-5];
    stack[0] = v0365;
    v0365 = stack[-3];
    v0366 = qcdr(v0365);
    v0365 = stack[-2];
    v0365 = CC_Hmultf(env, v0366, v0365);
    nil = C_nil;
    if (exception_pending()) goto v0368;
    env = stack[-5];
    stack[-1] = v0365;
    v0365 = stack[0];
    if (v0365 == nil) { Lisp_Object res = stack[-1]; popv(6); return onevalue(res); }
    v0365 = stack[-3];
    v0365 = qcar(v0365);
    v0365 = qcdr(v0365);
    if (!consp(v0365)) goto v0225;
    v0365 = stack[-3];
    v0365 = qcar(v0365);
    v0365 = qcdr(v0365);
    v0365 = qcar(v0365);
    v0365 = (consp(v0365) ? nil : lisp_true);
    goto v0172;

v0172:
    if (v0365 == nil) goto v0372;
    v0365 = qvalue(elt(env, 2)); /* nil */
    goto v0373;

v0373:
    if (v0365 == nil) goto v0374;
    v0365 = stack[-3];
    v0365 = qcar(v0365);
    v0366 = qcar(v0365);
    v0365 = (Lisp_Object)17; /* 1 */
    v0365 = cons(v0366, v0365);
    nil = C_nil;
    if (exception_pending()) goto v0368;
    env = stack[-5];
    v0366 = ncons(v0365);
    nil = C_nil;
    if (exception_pending()) goto v0368;
    env = stack[-5];
    v0365 = stack[0];
    v0366 = CC_Hmultf(env, v0366, v0365);
    nil = C_nil;
    if (exception_pending()) goto v0368;
    env = stack[-5];
    v0365 = stack[-1];
    {
        popv(6);
        fn = elt(env, 11); /* addf */
        return (*qfn2(fn))(qenv(fn), v0366, v0365);
    }

v0374:
    v0365 = stack[-3];
    v0365 = qcar(v0365);
    v0367 = qcar(v0365);
    v0366 = stack[0];
    v0365 = stack[-1];
    {
        popv(6);
        fn = elt(env, 12); /* makeupsf */
        return (*qfnn(fn))(qenv(fn), 3, v0367, v0366, v0365);
    }

v0372:
    v0365 = stack[-3];
    v0365 = qcar(v0365);
    v0365 = qcdr(v0365);
    v0365 = qcar(v0365);
    v0365 = qcar(v0365);
    v0366 = qcar(v0365);
    v0365 = stack[-2];
    v0365 = qcar(v0365);
    v0365 = qcar(v0365);
    v0365 = qcar(v0365);
    if (v0366 == v0365) goto v0173;
    v0365 = qvalue(elt(env, 2)); /* nil */
    goto v0373;

v0173:
    v0365 = stack[-2];
    v0365 = qcar(v0365);
    v0365 = qcar(v0365);
    v0365 = qcar(v0365);
    if (!consp(v0365)) goto v0375;
    v0365 = stack[-2];
    v0365 = qcar(v0365);
    v0365 = qcar(v0365);
    v0365 = qcar(v0365);
    v0366 = qcar(v0365);
    v0365 = elt(env, 4); /* (expt sqrt) */
    v0365 = Lmemq(nil, v0366, v0365);
    goto v0373;

v0375:
    v0365 = qvalue(elt(env, 2)); /* nil */
    goto v0373;

v0225:
    v0365 = qvalue(elt(env, 1)); /* t */
    goto v0172;

v0132:
    v0366 = stack[-3];
    v0365 = stack[-2];
    v0365 = qcar(v0365);
    v0365 = qcdr(v0365);
    v0365 = CC_Hmultf(env, v0366, v0365);
    nil = C_nil;
    if (exception_pending()) goto v0368;
    env = stack[-5];
    stack[0] = v0365;
    v0366 = stack[-3];
    v0365 = stack[-2];
    v0365 = qcdr(v0365);
    v0365 = CC_Hmultf(env, v0366, v0365);
    nil = C_nil;
    if (exception_pending()) goto v0368;
    env = stack[-5];
    stack[-1] = v0365;
    v0365 = stack[0];
    if (v0365 == nil) { Lisp_Object res = stack[-1]; popv(6); return onevalue(res); }
    v0365 = stack[-2];
    v0365 = qcar(v0365);
    v0365 = qcdr(v0365);
    if (!consp(v0365)) goto v0083;
    v0365 = stack[-2];
    v0365 = qcar(v0365);
    v0365 = qcdr(v0365);
    v0365 = qcar(v0365);
    v0365 = (consp(v0365) ? nil : lisp_true);
    goto v0211;

v0211:
    if (v0365 == nil) goto v0034;
    v0365 = qvalue(elt(env, 2)); /* nil */
    goto v0376;

v0376:
    if (v0365 == nil) goto v0186;
    v0365 = stack[-2];
    v0365 = qcar(v0365);
    v0366 = qcar(v0365);
    v0365 = (Lisp_Object)17; /* 1 */
    v0365 = cons(v0366, v0365);
    nil = C_nil;
    if (exception_pending()) goto v0368;
    env = stack[-5];
    v0365 = ncons(v0365);
    nil = C_nil;
    if (exception_pending()) goto v0368;
    env = stack[-5];
    v0366 = CC_Hmultf(env, stack[0], v0365);
    nil = C_nil;
    if (exception_pending()) goto v0368;
    env = stack[-5];
    v0365 = stack[-1];
    {
        popv(6);
        fn = elt(env, 11); /* addf */
        return (*qfn2(fn))(qenv(fn), v0366, v0365);
    }

v0186:
    v0365 = stack[-2];
    v0365 = qcar(v0365);
    v0367 = qcar(v0365);
    v0366 = stack[0];
    v0365 = stack[-1];
    {
        popv(6);
        fn = elt(env, 12); /* makeupsf */
        return (*qfnn(fn))(qenv(fn), 3, v0367, v0366, v0365);
    }

v0034:
    v0365 = stack[-3];
    v0365 = qcar(v0365);
    v0365 = qcar(v0365);
    v0366 = qcar(v0365);
    v0365 = stack[-2];
    v0365 = qcar(v0365);
    v0365 = qcdr(v0365);
    v0365 = qcar(v0365);
    v0365 = qcar(v0365);
    v0365 = qcar(v0365);
    if (v0366 == v0365) goto v0195;
    v0365 = qvalue(elt(env, 2)); /* nil */
    goto v0376;

v0195:
    v0365 = stack[-3];
    v0365 = qcar(v0365);
    v0365 = qcar(v0365);
    v0365 = qcar(v0365);
    if (!consp(v0365)) goto v0187;
    v0365 = stack[-3];
    v0365 = qcar(v0365);
    v0365 = qcar(v0365);
    v0365 = qcar(v0365);
    v0366 = qcar(v0365);
    v0365 = elt(env, 4); /* (expt sqrt) */
    v0365 = Lmemq(nil, v0366, v0365);
    goto v0376;

v0187:
    v0365 = qvalue(elt(env, 2)); /* nil */
    goto v0376;

v0083:
    v0365 = qvalue(elt(env, 1)); /* t */
    goto v0211;

v0371:
    v0365 = stack[-3];
    v0365 = qcar(v0365);
    v0366 = ncons(v0365);
    nil = C_nil;
    if (exception_pending()) goto v0368;
    env = stack[-5];
    v0365 = stack[-2];
    v0365 = qcdr(v0365);
    stack[-1] = CC_Hmultf(env, v0366, v0365);
    nil = C_nil;
    if (exception_pending()) goto v0368;
    env = stack[-5];
    v0365 = stack[-3];
    v0366 = qcdr(v0365);
    v0365 = stack[-2];
    v0365 = CC_Hmultf(env, v0366, v0365);
    nil = C_nil;
    if (exception_pending()) goto v0368;
    env = stack[-5];
    fn = elt(env, 11); /* addf */
    v0365 = (*qfn2(fn))(qenv(fn), stack[-1], v0365);
    nil = C_nil;
    if (exception_pending()) goto v0368;
    env = stack[-5];
    stack[-1] = v0365;
    v0366 = stack[0];
    v0365 = elt(env, 5); /* sqrt */
    if (!consp(v0366)) goto v0237;
    v0366 = qcar(v0366);
    if (!(v0366 == v0365)) goto v0237;
    v0365 = stack[-1];
    fn = elt(env, 7); /* squashsqrt */
    stack[-4] = (*qfn1(fn))(qenv(fn), v0365);
    nil = C_nil;
    if (exception_pending()) goto v0368;
    env = stack[-5];
    stack[-1] = stack[0];
    v0365 = stack[-3];
    v0365 = qcar(v0365);
    v0366 = qcdr(v0365);
    v0365 = stack[-2];
    v0365 = qcar(v0365);
    v0365 = qcdr(v0365);
    stack[0] = CC_Hmultf(env, v0366, v0365);
    nil = C_nil;
    if (exception_pending()) goto v0368;
    env = stack[-5];
    v0365 = stack[-3];
    v0365 = qcar(v0365);
    v0365 = qcar(v0365);
    v0366 = qcdr(v0365);
    v0365 = stack[-2];
    v0365 = qcar(v0365);
    v0365 = qcar(v0365);
    v0365 = qcdr(v0365);
    v0365 = plus2(v0366, v0365);
    nil = C_nil;
    if (exception_pending()) goto v0368;
    env = stack[-5];
    fn = elt(env, 13); /* !*multfsqrt */
    v0365 = (*qfnn(fn))(qenv(fn), 3, stack[-1], stack[0], v0365);
    nil = C_nil;
    if (exception_pending()) goto v0368;
    env = stack[-5];
    {
        Lisp_Object v0377 = stack[-4];
        popv(6);
        fn = elt(env, 11); /* addf */
        return (*qfn2(fn))(qenv(fn), v0377, v0365);
    }

v0237:
    v0366 = stack[0];
    v0365 = elt(env, 6); /* expt */
    if (!consp(v0366)) goto v0286;
    v0366 = qcar(v0366);
    if (!(v0366 == v0365)) goto v0286;
    v0365 = stack[0];
    v0365 = qcdr(v0365);
    v0365 = qcdr(v0365);
    v0365 = qcar(v0365);
    fn = elt(env, 14); /* prefix!-rational!-numberp */
    v0365 = (*qfn1(fn))(qenv(fn), v0365);
    nil = C_nil;
    if (exception_pending()) goto v0368;
    env = stack[-5];
    goto v0378;

v0378:
    if (v0365 == nil) goto v0379;
    v0365 = stack[-1];
    fn = elt(env, 7); /* squashsqrt */
    stack[-4] = (*qfn1(fn))(qenv(fn), v0365);
    nil = C_nil;
    if (exception_pending()) goto v0368;
    env = stack[-5];
    stack[-1] = stack[0];
    v0365 = stack[-3];
    v0365 = qcar(v0365);
    v0366 = qcdr(v0365);
    v0365 = stack[-2];
    v0365 = qcar(v0365);
    v0365 = qcdr(v0365);
    stack[0] = CC_Hmultf(env, v0366, v0365);
    nil = C_nil;
    if (exception_pending()) goto v0368;
    env = stack[-5];
    v0365 = stack[-3];
    v0365 = qcar(v0365);
    v0365 = qcar(v0365);
    v0366 = qcdr(v0365);
    v0365 = stack[-2];
    v0365 = qcar(v0365);
    v0365 = qcar(v0365);
    v0365 = qcdr(v0365);
    v0365 = plus2(v0366, v0365);
    nil = C_nil;
    if (exception_pending()) goto v0368;
    env = stack[-5];
    fn = elt(env, 15); /* !*multfexpt */
    v0365 = (*qfnn(fn))(qenv(fn), 3, stack[-1], stack[0], v0365);
    nil = C_nil;
    if (exception_pending()) goto v0368;
    env = stack[-5];
    {
        Lisp_Object v0380 = stack[-4];
        popv(6);
        fn = elt(env, 11); /* addf */
        return (*qfn2(fn))(qenv(fn), v0380, v0365);
    }

v0379:
    v0365 = stack[-3];
    v0365 = qcar(v0365);
    v0365 = qcar(v0365);
    v0366 = qcdr(v0365);
    v0365 = stack[-2];
    v0365 = qcar(v0365);
    v0365 = qcar(v0365);
    v0365 = qcdr(v0365);
    v0365 = plus2(v0366, v0365);
    nil = C_nil;
    if (exception_pending()) goto v0368;
    env = stack[-5];
    fn = elt(env, 16); /* mkspm */
    v0365 = (*qfn2(fn))(qenv(fn), stack[0], v0365);
    nil = C_nil;
    if (exception_pending()) goto v0368;
    env = stack[-5];
    stack[0] = v0365;
    v0365 = stack[0];
    if (v0365 == nil) goto v0381;
    v0365 = stack[-3];
    v0365 = qcar(v0365);
    v0366 = qcdr(v0365);
    v0365 = stack[-2];
    v0365 = qcar(v0365);
    v0365 = qcdr(v0365);
    v0365 = CC_Hmultf(env, v0366, v0365);
    nil = C_nil;
    if (exception_pending()) goto v0368;
    env = stack[-5];
    stack[-3] = v0365;
    v0365 = (v0365 == nil ? lisp_true : nil);
    goto v0382;

v0382:
    if (!(v0365 == nil)) { Lisp_Object res = stack[-1]; popv(6); return onevalue(res); }
    v0366 = stack[0];
    v0365 = (Lisp_Object)17; /* 1 */
    v0365 = cons(v0366, v0365);
    nil = C_nil;
    if (exception_pending()) goto v0368;
    env = stack[-5];
    v0366 = ncons(v0365);
    nil = C_nil;
    if (exception_pending()) goto v0368;
    env = stack[-5];
    v0365 = stack[-3];
    fn = elt(env, 9); /* multf */
    v0366 = (*qfn2(fn))(qenv(fn), v0366, v0365);
    nil = C_nil;
    if (exception_pending()) goto v0368;
    env = stack[-5];
    v0365 = stack[-1];
    {
        popv(6);
        fn = elt(env, 11); /* addf */
        return (*qfn2(fn))(qenv(fn), v0366, v0365);
    }

v0381:
    v0365 = qvalue(elt(env, 1)); /* t */
    goto v0382;

v0286:
    v0365 = qvalue(elt(env, 2)); /* nil */
    goto v0378;

v0131:
    v0365 = qvalue(elt(env, 1)); /* t */
    goto v0099;

v0067:
    v0365 = qvalue(elt(env, 1)); /* t */
    goto v0151;

v0015:
    v0365 = stack[-3];
    {
        popv(6);
        fn = elt(env, 7); /* squashsqrt */
        return (*qfn1(fn))(qenv(fn), v0365);
    }

v0003:
    v0365 = stack[-2];
    {
        popv(6);
        fn = elt(env, 7); /* squashsqrt */
        return (*qfn1(fn))(qenv(fn), v0365);
    }

v0095:
    v0365 = qvalue(elt(env, 1)); /* t */
    goto v0005;
/* error exit handlers */
v0368:
    popv(6);
    return nil;
}



/* Code for ratminus */

static Lisp_Object CC_ratminus(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0004, v0005;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ratminus");
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
    v0004 = stack[0];
    v0004 = qcar(v0004);
    v0005 = negate(v0004);
    nil = C_nil;
    if (exception_pending()) goto v0100;
    v0004 = stack[0];
    v0004 = qcdr(v0004);
    popv(1);
    return cons(v0005, v0004);
/* error exit handlers */
v0100:
    popv(1);
    return nil;
}



/* Code for ra_wrapper1 */

static Lisp_Object MS_CDECL CC_ra_wrapper1(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0013, v0010;
    Lisp_Object fn;
    Lisp_Object v0051, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "ra_wrapper1");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0001 = va_arg(aa, Lisp_Object);
    v0051 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ra_wrapper1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0051,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0051);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0051;
    stack[-1] = v0001;
    stack[-2] = v0000;
/* end of prologue */
    v0013 = stack[0];
    if (v0013 == nil) goto v0095;
    v0013 = stack[0];
    fn = elt(env, 1); /* off1 */
    v0013 = (*qfn1(fn))(qenv(fn), v0013);
    nil = C_nil;
    if (exception_pending()) goto v0015;
    env = stack[-3];
    goto v0095;

v0095:
    v0010 = stack[-2];
    v0013 = stack[-1];
    fn = elt(env, 2); /* apply */
    v0013 = (*qfn2(fn))(qenv(fn), v0010, v0013);
    nil = C_nil;
    if (exception_pending()) goto v0015;
    env = stack[-3];
    stack[-1] = v0013;
    v0013 = stack[0];
    if (v0013 == nil) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v0013 = stack[0];
    fn = elt(env, 3); /* on1 */
    v0013 = (*qfn1(fn))(qenv(fn), v0013);
    nil = C_nil;
    if (exception_pending()) goto v0015;
    { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
/* error exit handlers */
v0015:
    popv(4);
    return nil;
}



/* Code for sfto_lmultf */

static Lisp_Object CC_sfto_lmultf(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0153, v0150;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sfto_lmultf");
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
    goto v0016;

v0016:
    v0153 = stack[0];
    if (v0153 == nil) goto v0090;
    v0153 = stack[0];
    v0150 = qcar(v0153);
    v0153 = stack[-1];
    v0153 = cons(v0150, v0153);
    nil = C_nil;
    if (exception_pending()) goto v0024;
    env = stack[-2];
    stack[-1] = v0153;
    v0153 = stack[0];
    v0153 = qcdr(v0153);
    stack[0] = v0153;
    goto v0016;

v0090:
    v0153 = (Lisp_Object)17; /* 1 */
    v0150 = v0153;
    goto v0039;

v0039:
    v0153 = stack[-1];
    if (v0153 == nil) { popv(3); return onevalue(v0150); }
    v0153 = stack[-1];
    v0153 = qcar(v0153);
    fn = elt(env, 1); /* multf */
    v0153 = (*qfn2(fn))(qenv(fn), v0153, v0150);
    nil = C_nil;
    if (exception_pending()) goto v0024;
    env = stack[-2];
    v0150 = v0153;
    v0153 = stack[-1];
    v0153 = qcdr(v0153);
    stack[-1] = v0153;
    goto v0039;
/* error exit handlers */
v0024:
    popv(3);
    return nil;
}



/* Code for evallessp */

static Lisp_Object CC_evallessp(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0029, v0096;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for evallessp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0096 = v0001;
    v0029 = v0000;
/* end of prologue */
    {
        fn = elt(env, 1); /* evalgreaterp */
        return (*qfn2(fn))(qenv(fn), v0096, v0029);
    }
}



/* Code for cgp_mk */

static Lisp_Object MS_CDECL CC_cgp_mk(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0013, v0010, v0079, v0124, v0014;
    Lisp_Object v0026, v0011, v0051, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 5, "cgp_mk");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0001 = va_arg(aa, Lisp_Object);
    v0051 = va_arg(aa, Lisp_Object);
    v0011 = va_arg(aa, Lisp_Object);
    v0026 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for cgp_mk");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push5(v0026,v0011,v0051,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v0000,v0001,v0051,v0011,v0026);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    v0013 = v0026;
    v0010 = v0011;
    v0079 = v0051;
    v0124 = v0001;
    v0014 = v0000;
/* end of prologue */
    stack[-2] = elt(env, 1); /* cgp */
    stack[-1] = v0014;
    stack[0] = v0124;
    v0013 = list3(v0079, v0010, v0013);
    nil = C_nil;
    if (exception_pending()) goto v0021;
    {
        Lisp_Object v0018 = stack[-2];
        Lisp_Object v0091 = stack[-1];
        Lisp_Object v0092 = stack[0];
        popv(3);
        return list3star(v0018, v0091, v0092, v0013);
    }
/* error exit handlers */
v0021:
    popv(3);
    return nil;
}



/* Code for getargsrd */

static Lisp_Object MS_CDECL CC_getargsrd(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0002, v0006;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "getargsrd");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for getargsrd");
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
    v0006 = qvalue(elt(env, 1)); /* char */
    v0002 = elt(env, 2); /* (b v a r) */
    if (equal(v0006, v0002)) goto v0016;
    v0002 = nil;
    { popv(2); return onevalue(v0002); }

v0016:
    fn = elt(env, 3); /* bvarrd */
    v0002 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0012;
    env = stack[-1];
    stack[0] = v0002;
    fn = elt(env, 4); /* lex */
    v0002 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0012;
    env = stack[-1];
    v0002 = CC_getargsrd(env, 0);
    nil = C_nil;
    if (exception_pending()) goto v0012;
    {
        Lisp_Object v0008 = stack[0];
        popv(2);
        return cons(v0008, v0002);
    }
/* error exit handlers */
v0012:
    popv(2);
    return nil;
}



/* Code for mkmatrix */

static Lisp_Object CC_mkmatrix(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0376, v0037;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mkmatrix");
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
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-8] = v0001;
    stack[-9] = v0000;
/* end of prologue */
    stack[-10] = elt(env, 1); /* mat */
    v0376 = (Lisp_Object)17; /* 1 */
    stack[-7] = v0376;
    v0037 = stack[-9];
    v0376 = stack[-7];
    v0376 = difference2(v0037, v0376);
    nil = C_nil;
    if (exception_pending()) goto v0036;
    env = stack[-11];
    v0376 = Lminusp(nil, v0376);
    env = stack[-11];
    if (v0376 == nil) goto v0069;
    v0376 = qvalue(elt(env, 2)); /* nil */
    goto v0090;

v0090:
    {
        Lisp_Object v0135 = stack[-10];
        popv(12);
        return cons(v0135, v0376);
    }

v0069:
    v0376 = (Lisp_Object)17; /* 1 */
    stack[-3] = v0376;
    v0037 = stack[-8];
    v0376 = stack[-3];
    v0376 = difference2(v0037, v0376);
    nil = C_nil;
    if (exception_pending()) goto v0036;
    env = stack[-11];
    v0376 = Lminusp(nil, v0376);
    env = stack[-11];
    if (v0376 == nil) goto v0091;
    v0376 = qvalue(elt(env, 2)); /* nil */
    goto v0087;

v0087:
    v0376 = ncons(v0376);
    nil = C_nil;
    if (exception_pending()) goto v0036;
    env = stack[-11];
    stack[-5] = v0376;
    stack[-6] = v0376;
    goto v0095;

v0095:
    v0376 = stack[-7];
    v0376 = add1(v0376);
    nil = C_nil;
    if (exception_pending()) goto v0036;
    env = stack[-11];
    stack[-7] = v0376;
    v0037 = stack[-9];
    v0376 = stack[-7];
    v0376 = difference2(v0037, v0376);
    nil = C_nil;
    if (exception_pending()) goto v0036;
    env = stack[-11];
    v0376 = Lminusp(nil, v0376);
    env = stack[-11];
    if (v0376 == nil) goto v0279;
    v0376 = stack[-6];
    goto v0090;

v0279:
    stack[-4] = stack[-5];
    v0376 = (Lisp_Object)17; /* 1 */
    stack[-3] = v0376;
    v0037 = stack[-8];
    v0376 = stack[-3];
    v0376 = difference2(v0037, v0376);
    nil = C_nil;
    if (exception_pending()) goto v0036;
    env = stack[-11];
    v0376 = Lminusp(nil, v0376);
    env = stack[-11];
    if (v0376 == nil) goto v0117;
    v0376 = qvalue(elt(env, 2)); /* nil */
    goto v0141;

v0141:
    v0376 = ncons(v0376);
    nil = C_nil;
    if (exception_pending()) goto v0036;
    env = stack[-11];
    v0376 = Lrplacd(nil, stack[-4], v0376);
    nil = C_nil;
    if (exception_pending()) goto v0036;
    env = stack[-11];
    v0376 = stack[-5];
    v0376 = qcdr(v0376);
    stack[-5] = v0376;
    goto v0095;

v0117:
    v0376 = (Lisp_Object)1; /* 0 */
    v0376 = ncons(v0376);
    nil = C_nil;
    if (exception_pending()) goto v0036;
    env = stack[-11];
    stack[-1] = v0376;
    stack[-2] = v0376;
    goto v0205;

v0205:
    v0376 = stack[-3];
    v0376 = add1(v0376);
    nil = C_nil;
    if (exception_pending()) goto v0036;
    env = stack[-11];
    stack[-3] = v0376;
    v0037 = stack[-8];
    v0376 = stack[-3];
    v0376 = difference2(v0037, v0376);
    nil = C_nil;
    if (exception_pending()) goto v0036;
    env = stack[-11];
    v0376 = Lminusp(nil, v0376);
    env = stack[-11];
    if (v0376 == nil) goto v0361;
    v0376 = stack[-2];
    goto v0141;

v0361:
    stack[0] = stack[-1];
    v0376 = (Lisp_Object)1; /* 0 */
    v0376 = ncons(v0376);
    nil = C_nil;
    if (exception_pending()) goto v0036;
    env = stack[-11];
    v0376 = Lrplacd(nil, stack[0], v0376);
    nil = C_nil;
    if (exception_pending()) goto v0036;
    env = stack[-11];
    v0376 = stack[-1];
    v0376 = qcdr(v0376);
    stack[-1] = v0376;
    goto v0205;

v0091:
    v0376 = (Lisp_Object)1; /* 0 */
    v0376 = ncons(v0376);
    nil = C_nil;
    if (exception_pending()) goto v0036;
    env = stack[-11];
    stack[-1] = v0376;
    stack[-2] = v0376;
    goto v0149;

v0149:
    v0376 = stack[-3];
    v0376 = add1(v0376);
    nil = C_nil;
    if (exception_pending()) goto v0036;
    env = stack[-11];
    stack[-3] = v0376;
    v0037 = stack[-8];
    v0376 = stack[-3];
    v0376 = difference2(v0037, v0376);
    nil = C_nil;
    if (exception_pending()) goto v0036;
    env = stack[-11];
    v0376 = Lminusp(nil, v0376);
    env = stack[-11];
    if (v0376 == nil) goto v0131;
    v0376 = stack[-2];
    goto v0087;

v0131:
    stack[0] = stack[-1];
    v0376 = (Lisp_Object)1; /* 0 */
    v0376 = ncons(v0376);
    nil = C_nil;
    if (exception_pending()) goto v0036;
    env = stack[-11];
    v0376 = Lrplacd(nil, stack[0], v0376);
    nil = C_nil;
    if (exception_pending()) goto v0036;
    env = stack[-11];
    v0376 = stack[-1];
    v0376 = qcdr(v0376);
    stack[-1] = v0376;
    goto v0149;
/* error exit handlers */
v0036:
    popv(12);
    return nil;
}



/* Code for embed!-null!-fn */

static Lisp_Object CC_embedKnullKfn(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0142, v0198, v0207;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for embed-null-fn");
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
    v0198 = v0000;
/* end of prologue */
    v0142 = v0198;
    if (!consp(v0142)) { popv(5); return onevalue(v0198); }
    v0142 = v0198;
    stack[-3] = v0142;
    goto v0095;

v0095:
    v0142 = stack[-3];
    if (v0142 == nil) goto v0077;
    v0142 = stack[-3];
    v0142 = qcar(v0142);
    v0207 = v0142;
    v0142 = v0207;
    if (!consp(v0142)) goto v0008;
    v0142 = v0207;
    v0198 = qcar(v0142);
    v0142 = elt(env, 2); /* null!-fn */
    if (v0198 == v0142) goto v0014;
    v0142 = v0207;
    v0142 = CC_embedKnullKfn(env, v0142);
    nil = C_nil;
    if (exception_pending()) goto v0383;
    env = stack[-4];
    v0142 = ncons(v0142);
    nil = C_nil;
    if (exception_pending()) goto v0383;
    env = stack[-4];
    goto v0012;

v0012:
    stack[-2] = v0142;
    v0142 = stack[-2];
    fn = elt(env, 3); /* lastpair */
    v0142 = (*qfn1(fn))(qenv(fn), v0142);
    nil = C_nil;
    if (exception_pending()) goto v0383;
    env = stack[-4];
    stack[-1] = v0142;
    v0142 = stack[-3];
    v0142 = qcdr(v0142);
    stack[-3] = v0142;
    v0142 = stack[-1];
    if (!consp(v0142)) goto v0095;
    else goto v0100;

v0100:
    v0142 = stack[-3];
    if (v0142 == nil) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    stack[0] = stack[-1];
    v0142 = stack[-3];
    v0142 = qcar(v0142);
    v0207 = v0142;
    v0142 = v0207;
    if (!consp(v0142)) goto v0157;
    v0142 = v0207;
    v0198 = qcar(v0142);
    v0142 = elt(env, 2); /* null!-fn */
    if (v0198 == v0142) goto v0089;
    v0142 = v0207;
    v0142 = CC_embedKnullKfn(env, v0142);
    nil = C_nil;
    if (exception_pending()) goto v0383;
    env = stack[-4];
    v0142 = ncons(v0142);
    nil = C_nil;
    if (exception_pending()) goto v0383;
    env = stack[-4];
    goto v0099;

v0099:
    v0142 = Lrplacd(nil, stack[0], v0142);
    nil = C_nil;
    if (exception_pending()) goto v0383;
    env = stack[-4];
    v0142 = stack[-1];
    fn = elt(env, 3); /* lastpair */
    v0142 = (*qfn1(fn))(qenv(fn), v0142);
    nil = C_nil;
    if (exception_pending()) goto v0383;
    env = stack[-4];
    stack[-1] = v0142;
    v0142 = stack[-3];
    v0142 = qcdr(v0142);
    stack[-3] = v0142;
    goto v0100;

v0089:
    v0142 = v0207;
    v0142 = qcdr(v0142);
    v0142 = CC_embedKnullKfn(env, v0142);
    nil = C_nil;
    if (exception_pending()) goto v0383;
    env = stack[-4];
    goto v0099;

v0157:
    v0142 = v0207;
    v0142 = ncons(v0142);
    nil = C_nil;
    if (exception_pending()) goto v0383;
    env = stack[-4];
    goto v0099;

v0014:
    v0142 = v0207;
    v0142 = qcdr(v0142);
    v0142 = CC_embedKnullKfn(env, v0142);
    nil = C_nil;
    if (exception_pending()) goto v0383;
    env = stack[-4];
    goto v0012;

v0008:
    v0142 = v0207;
    v0142 = ncons(v0142);
    nil = C_nil;
    if (exception_pending()) goto v0383;
    env = stack[-4];
    goto v0012;

v0077:
    v0142 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v0142); }
/* error exit handlers */
v0383:
    popv(5);
    return nil;
}



/* Code for groedeletip */

static Lisp_Object CC_groedeletip(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0131, v0086;
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

v0039:
    v0131 = stack[0];
    if (v0131 == nil) goto v0090;
    v0086 = stack[-1];
    v0131 = stack[0];
    v0131 = qcar(v0131);
    if (!(equal(v0086, v0131))) goto v0090;
    v0131 = stack[0];
    v0131 = qcdr(v0131);
    stack[0] = v0131;
    goto v0039;

v0090:
    v0131 = stack[0];
    if (v0131 == nil) goto v0008;
    v0131 = stack[0];
    stack[-2] = v0131;
    goto v0087;

v0087:
    v0131 = stack[0];
    v0131 = qcdr(v0131);
    if (v0131 == nil) { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
    v0086 = stack[-1];
    v0131 = stack[0];
    v0131 = qcdr(v0131);
    v0131 = qcar(v0131);
    if (equal(v0086, v0131)) goto v0145;
    v0131 = stack[0];
    v0131 = qcdr(v0131);
    stack[0] = v0131;
    goto v0087;

v0145:
    v0086 = stack[0];
    v0131 = stack[0];
    v0131 = qcdr(v0131);
    v0131 = qcdr(v0131);
    fn = elt(env, 2); /* setcdr */
    v0131 = (*qfn2(fn))(qenv(fn), v0086, v0131);
    nil = C_nil;
    if (exception_pending()) goto v0088;
    env = stack[-3];
    goto v0087;

v0008:
    v0131 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v0131); }
/* error exit handlers */
v0088:
    popv(4);
    return nil;
}



/* Code for bcminus!? */

static Lisp_Object CC_bcminusW(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0004, v0005;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for bcminus?");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0005 = v0000;
/* end of prologue */
    v0004 = qvalue(elt(env, 1)); /* !*grmod!* */
    if (v0004 == nil) goto v0026;
    v0004 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v0004);

v0026:
    v0004 = v0005;
    v0004 = qcar(v0004);
    {
        fn = elt(env, 3); /* minusf */
        return (*qfn1(fn))(qenv(fn), v0004);
    }
}



/* Code for indxsymp */

static Lisp_Object CC_indxsymp(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0087, v0149;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for indxsymp");
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

v0154:
    v0087 = stack[0];
    if (v0087 == nil) goto v0025;
    v0087 = stack[0];
    v0149 = qcar(v0087);
    v0087 = stack[-1];
    v0087 = Lapply1(nil, v0149, v0087);
    nil = C_nil;
    if (exception_pending()) goto v0091;
    env = stack[-2];
    if (v0087 == nil) goto v0004;
    v0149 = stack[-1];
    v0087 = stack[0];
    v0087 = qcdr(v0087);
    stack[-1] = v0149;
    stack[0] = v0087;
    goto v0154;

v0004:
    v0087 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v0087); }

v0025:
    v0087 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v0087); }
/* error exit handlers */
v0091:
    popv(3);
    return nil;
}



/* Code for red_tailreddriver */

static Lisp_Object MS_CDECL CC_red_tailreddriver(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0145;
    Lisp_Object fn;
    Lisp_Object v0051, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "red_tailreddriver");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0001 = va_arg(aa, Lisp_Object);
    v0051 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for red_tailreddriver");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0051,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0051);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0051;
    stack[-2] = v0001;
    stack[-3] = v0000;
/* end of prologue */
    v0145 = stack[-2];
    fn = elt(env, 3); /* bas_dpoly */
    v0145 = (*qfn1(fn))(qenv(fn), v0145);
    nil = C_nil;
    if (exception_pending()) goto v0156;
    env = stack[-5];
    if (v0145 == nil) goto v0030;
    v0145 = stack[-2];
    fn = elt(env, 3); /* bas_dpoly */
    v0145 = (*qfn1(fn))(qenv(fn), v0145);
    nil = C_nil;
    if (exception_pending()) goto v0156;
    env = stack[-5];
    v0145 = qcdr(v0145);
    if (v0145 == nil) goto v0078;
    v0145 = stack[-3];
    v0145 = (v0145 == nil ? lisp_true : nil);
    goto v0017;

v0017:
    if (!(v0145 == nil)) { Lisp_Object res = stack[-2]; popv(6); return onevalue(res); }

v0087:
    v0145 = stack[-2];
    fn = elt(env, 3); /* bas_dpoly */
    v0145 = (*qfn1(fn))(qenv(fn), v0145);
    nil = C_nil;
    if (exception_pending()) goto v0156;
    env = stack[-5];
    if (v0145 == nil) goto v0015;
    stack[-4] = stack[-1];
    stack[0] = stack[-3];
    v0145 = stack[-2];
    fn = elt(env, 4); /* red!=hidelt */
    v0145 = (*qfn1(fn))(qenv(fn), v0145);
    nil = C_nil;
    if (exception_pending()) goto v0156;
    env = stack[-5];
    v0145 = Lapply2(nil, 3, stack[-4], stack[0], v0145);
    nil = C_nil;
    if (exception_pending()) goto v0156;
    env = stack[-5];
    stack[-2] = v0145;
    goto v0087;

v0015:
    v0145 = stack[-2];
    {
        popv(6);
        fn = elt(env, 5); /* red!=recover */
        return (*qfn1(fn))(qenv(fn), v0145);
    }

v0078:
    v0145 = qvalue(elt(env, 1)); /* t */
    goto v0017;

v0030:
    v0145 = qvalue(elt(env, 1)); /* t */
    goto v0017;
/* error exit handlers */
v0156:
    popv(6);
    return nil;
}



/* Code for !*di2q */

static Lisp_Object CC_Hdi2q(Lisp_Object env,
                         Lisp_Object v0001, Lisp_Object v0051)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0157, v0144, v0160;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for *di2q");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0051,v0001);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0001,v0051);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    v0157 = v0051;
    v0144 = v0001;
/* end of prologue */
    stack[-4] = qvalue(elt(env, 1)); /* varlist!* */
    qvalue(elt(env, 1)) = nil; /* varlist!* */
    qvalue(elt(env, 1)) = v0157; /* varlist!* */
    v0157 = v0144;
    stack[-3] = v0157;
    v0157 = stack[-3];
    if (v0157 == nil) goto v0084;
    v0157 = stack[-3];
    v0157 = qcar(v0157);
    v0144 = v0157;
    v0160 = qcar(v0144);
    v0144 = qcdr(v0157);
    v0157 = (Lisp_Object)17; /* 1 */
    v0157 = list2star(v0160, v0144, v0157);
    nil = C_nil;
    if (exception_pending()) goto v0060;
    env = stack[-5];
    v0157 = ncons(v0157);
    nil = C_nil;
    if (exception_pending()) goto v0060;
    env = stack[-5];
    stack[-1] = v0157;
    stack[-2] = v0157;
    goto v0078;

v0078:
    v0157 = stack[-3];
    v0157 = qcdr(v0157);
    stack[-3] = v0157;
    v0157 = stack[-3];
    if (v0157 == nil) goto v0022;
    stack[0] = stack[-1];
    v0157 = stack[-3];
    v0157 = qcar(v0157);
    v0144 = v0157;
    v0160 = qcar(v0144);
    v0144 = qcdr(v0157);
    v0157 = (Lisp_Object)17; /* 1 */
    v0157 = list2star(v0160, v0144, v0157);
    nil = C_nil;
    if (exception_pending()) goto v0060;
    env = stack[-5];
    v0157 = ncons(v0157);
    nil = C_nil;
    if (exception_pending()) goto v0060;
    env = stack[-5];
    v0157 = Lrplacd(nil, stack[0], v0157);
    nil = C_nil;
    if (exception_pending()) goto v0060;
    env = stack[-5];
    v0157 = stack[-1];
    v0157 = qcdr(v0157);
    stack[-1] = v0157;
    goto v0078;

v0022:
    v0157 = stack[-2];
    v0144 = v0157;
    goto v0029;

v0029:
    v0157 = qvalue(elt(env, 1)); /* varlist!* */
    fn = elt(env, 3); /* !*di2q0 */
    v0157 = (*qfn2(fn))(qenv(fn), v0144, v0157);
    nil = C_nil;
    if (exception_pending()) goto v0060;
    env = stack[-5];
    qvalue(elt(env, 1)) = stack[-4]; /* varlist!* */
    { popv(6); return onevalue(v0157); }

v0084:
    v0157 = qvalue(elt(env, 2)); /* nil */
    v0144 = v0157;
    goto v0029;
/* error exit handlers */
v0060:
    env = stack[-5];
    qvalue(elt(env, 1)) = stack[-4]; /* varlist!* */
    popv(6);
    return nil;
}



/* Code for solvealgdepends */

static Lisp_Object CC_solvealgdepends(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0089, v0101;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for solvealgdepends");
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

v0029:
    v0101 = stack[-1];
    v0089 = stack[0];
    if (equal(v0101, v0089)) goto v0017;
    v0089 = stack[-1];
    if (!consp(v0089)) goto v0078;
    v0101 = stack[-1];
    v0089 = elt(env, 3); /* root_of */
    if (!consp(v0101)) goto v0102;
    v0101 = qcar(v0101);
    if (!(v0101 == v0089)) goto v0102;
    v0101 = stack[0];
    v0089 = stack[-1];
    v0089 = qcdr(v0089);
    v0089 = qcdr(v0089);
    v0089 = qcar(v0089);
    if (equal(v0101, v0089)) goto v0015;
    v0089 = stack[-1];
    v0089 = qcdr(v0089);
    v0089 = qcar(v0089);
    stack[-1] = v0089;
    goto v0029;

v0015:
    v0089 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v0089); }

v0102:
    v0089 = stack[-1];
    v0101 = qcar(v0089);
    v0089 = stack[0];
    v0089 = CC_solvealgdepends(env, v0101, v0089);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-2];
    v0101 = v0089;
    if (!(v0089 == nil)) { popv(3); return onevalue(v0101); }
    v0089 = stack[-1];
    v0101 = qcdr(v0089);
    v0089 = stack[0];
    v0089 = CC_solvealgdepends(env, v0101, v0089);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-2];
    v0101 = v0089;
    if (!(v0089 == nil)) { popv(3); return onevalue(v0101); }
    v0089 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v0089); }

v0078:
    v0089 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v0089); }

v0017:
    v0089 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v0089); }
/* error exit handlers */
v0058:
    popv(3);
    return nil;
}



/* Code for iv_cutcongs1 */

static Lisp_Object CC_iv_cutcongs1(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0079, v0124;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for iv_cutcongs1");
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

v0025:
    v0079 = stack[0];
    if (v0079 == nil) goto v0008;
    v0124 = stack[-1];
    v0079 = stack[0];
    v0079 = qcar(v0079);
    fn = elt(env, 3); /* iv_cutcongs2 */
    v0079 = (*qfn2(fn))(qenv(fn), v0124, v0079);
    nil = C_nil;
    if (exception_pending()) goto v0087;
    env = stack[-2];
    if (v0079 == nil) goto v0006;
    v0079 = stack[0];
    v0079 = qcdr(v0079);
    stack[0] = v0079;
    goto v0025;

v0006:
    v0079 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v0079); }

v0008:
    v0079 = qvalue(elt(env, 2)); /* t */
    { popv(3); return onevalue(v0079); }
/* error exit handlers */
v0087:
    popv(3);
    return nil;
}



/* Code for innprodp2 */

static Lisp_Object CC_innprodp2(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0023, v0098, v0024, v0022;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for innprodp2");
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
    v0024 = v0001;
    stack[0] = v0000;
/* end of prologue */
    v0023 = qvalue(elt(env, 1)); /* nil */
    v0098 = v0024;
    v0023 = cons(v0023, v0098);
    nil = C_nil;
    if (exception_pending()) goto v0067;
    env = stack[-1];
    v0024 = v0023;
    goto v0095;

v0095:
    v0023 = stack[0];
    if (v0023 == nil) { popv(2); return onevalue(v0024); }
    v0023 = v0024;
    if (v0023 == nil) { popv(2); return onevalue(v0024); }
    v0022 = qvalue(elt(env, 1)); /* nil */
    v0023 = stack[0];
    v0098 = qcar(v0023);
    v0023 = v0024;
    v0023 = qcdr(v0023);
    v0024 = qcar(v0024);
    fn = elt(env, 2); /* innprodkp */
    v0023 = (*qfnn(fn))(qenv(fn), 4, v0022, v0098, v0023, v0024);
    nil = C_nil;
    if (exception_pending()) goto v0067;
    env = stack[-1];
    v0024 = v0023;
    v0023 = stack[0];
    v0023 = qcdr(v0023);
    stack[0] = v0023;
    goto v0095;
/* error exit handlers */
v0067:
    popv(2);
    return nil;
}



/* Code for dvfsf_smcpknowl */

static Lisp_Object CC_dvfsf_smcpknowl(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0004, v0005;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dvfsf_smcpknowl");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0005 = v0000;
/* end of prologue */
    v0004 = qvalue(elt(env, 1)); /* !*rlsusi */
    if (v0004 == nil) goto v0017;
    v0004 = v0005;
    {
        fn = elt(env, 2); /* cl_susicpknowl */
        return (*qfn1(fn))(qenv(fn), v0004);
    }

v0017:
    v0004 = v0005;
    {
        fn = elt(env, 3); /* cl_smcpknowl */
        return (*qfn1(fn))(qenv(fn), v0004);
    }
}



/* Code for sets */

static Lisp_Object CC_sets(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0124, v0014;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sets");
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
    v0124 = elt(env, 1); /* "<apply>" */
    fn = elt(env, 6); /* printout */
    v0124 = (*qfn1(fn))(qenv(fn), v0124);
    nil = C_nil;
    if (exception_pending()) goto v0149;
    env = stack[-2];
    v0124 = elt(env, 2); /* "<" */
    v0124 = Lprinc(nil, v0124);
    nil = C_nil;
    if (exception_pending()) goto v0149;
    env = stack[-2];
    v0124 = stack[0];
    v0124 = Lprinc(nil, v0124);
    nil = C_nil;
    if (exception_pending()) goto v0149;
    env = stack[-2];
    v0124 = elt(env, 3); /* "/>" */
    v0124 = Lprinc(nil, v0124);
    nil = C_nil;
    if (exception_pending()) goto v0149;
    env = stack[-2];
    v0014 = qvalue(elt(env, 4)); /* indent */
    v0124 = (Lisp_Object)49; /* 3 */
    v0124 = plus2(v0014, v0124);
    nil = C_nil;
    if (exception_pending()) goto v0149;
    env = stack[-2];
    qvalue(elt(env, 4)) = v0124; /* indent */
    v0124 = stack[-1];
    fn = elt(env, 7); /* multi_elem */
    v0124 = (*qfn1(fn))(qenv(fn), v0124);
    nil = C_nil;
    if (exception_pending()) goto v0149;
    env = stack[-2];
    v0014 = qvalue(elt(env, 4)); /* indent */
    v0124 = (Lisp_Object)49; /* 3 */
    v0124 = difference2(v0014, v0124);
    nil = C_nil;
    if (exception_pending()) goto v0149;
    env = stack[-2];
    qvalue(elt(env, 4)) = v0124; /* indent */
    v0124 = elt(env, 5); /* "</apply>" */
    fn = elt(env, 6); /* printout */
    v0124 = (*qfn1(fn))(qenv(fn), v0124);
    nil = C_nil;
    if (exception_pending()) goto v0149;
    v0124 = nil;
    { popv(3); return onevalue(v0124); }
/* error exit handlers */
v0149:
    popv(3);
    return nil;
}



setup_type const u30_setup[] =
{
    {"**a2i",                   too_few_2,      CC_HHa2i,      wrong_no_2},
    {"mv-pow-mv-+",             too_few_2,      CC_mvKpowKmvKL,wrong_no_2},
    {"add-degrees",             too_few_2,      CC_addKdegrees,wrong_no_2},
    {"mri_prepat",              CC_mri_prepat,  too_many_1,    wrong_no_1},
    {"ofsf_sippsignchkf",       wrong_no_na,    wrong_no_nb,   (n_args *)CC_ofsf_sippsignchkf},
    {"omatpir",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_omatpir},
    {"cos*",                    CC_cosH,        too_many_1,    wrong_no_1},
    {"red=hide",                CC_redMhide,    too_many_1,    wrong_no_1},
    {"atom_compare",            too_few_2,      CC_atom_compare,wrong_no_2},
    {"sfto_lessq",              too_few_2,      CC_sfto_lessq, wrong_no_2},
    {"ofsf_smordtable",         too_few_2,      CC_ofsf_smordtable,wrong_no_2},
    {"aex_subrat1",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_aex_subrat1},
    {"semanticml",              CC_semanticml,  too_many_1,    wrong_no_1},
    {"vp2",                     CC_vp2,         too_many_1,    wrong_no_1},
    {"dm-min",                  too_few_2,      CC_dmKmin,     wrong_no_2},
    {"s-nextarg",               CC_sKnextarg,   too_many_1,    wrong_no_1},
    {"dipsum",                  too_few_2,      CC_dipsum,     wrong_no_2},
    {"a2bc",                    CC_a2bc,        too_many_1,    wrong_no_1},
    {"indordl2",                too_few_2,      CC_indordl2,   wrong_no_2},
    {"po:statep",               CC_poTstatep,   too_many_1,    wrong_no_1},
    {"prop-simp2",              too_few_2,      CC_propKsimp2, wrong_no_2},
    {"assert_kernelp",          CC_assert_kernelp,too_many_1,  wrong_no_1},
    {"innprodpex",              too_few_2,      CC_innprodpex, wrong_no_2},
    {"mv-pow->",                too_few_2,      CC_mvKpowKS,   wrong_no_2},
    {"proper-simpsqrt",         CC_properKsimpsqrt,too_many_1, wrong_no_1},
    {"ofsf_smcpknowl",          CC_ofsf_smcpknowl,too_many_1,  wrong_no_1},
    {"pasf_dt",                 CC_pasf_dt,     too_many_1,    wrong_no_1},
    {"vdp_plist",               CC_vdp_plist,   too_many_1,    wrong_no_1},
    {"sfto_b:extadd",           too_few_2,      CC_sfto_bTextadd,wrong_no_2},
    {"fnrd",                    wrong_no_na,    wrong_no_nb,   (n_args *)CC_fnrd},
    {"gftimes",                 too_few_2,      CC_gftimes,    wrong_no_2},
    {"*pf2sq",                  CC_Hpf2sq,      too_many_1,    wrong_no_1},
    {"contract-strand",         too_few_2,      CC_contractKstrand,wrong_no_2},
    {"no-side-effectp",         CC_noKsideKeffectp,too_many_1, wrong_no_1},
    {"matop_pseudomod",         too_few_2,      CC_matop_pseudomod,wrong_no_2},
    {"simp-prop1",              too_few_2,      CC_simpKprop1, wrong_no_2},
    {"*multf",                  too_few_2,      CC_Hmultf,     wrong_no_2},
    {"ratminus",                CC_ratminus,    too_many_1,    wrong_no_1},
    {"ra_wrapper1",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_ra_wrapper1},
    {"sfto_lmultf",             CC_sfto_lmultf, too_many_1,    wrong_no_1},
    {"evallessp",               too_few_2,      CC_evallessp,  wrong_no_2},
    {"cgp_mk",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_cgp_mk},
    {"getargsrd",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_getargsrd},
    {"mkmatrix",                too_few_2,      CC_mkmatrix,   wrong_no_2},
    {"embed-null-fn",           CC_embedKnullKfn,too_many_1,   wrong_no_1},
    {"groedeletip",             too_few_2,      CC_groedeletip,wrong_no_2},
    {"bcminus?",                CC_bcminusW,    too_many_1,    wrong_no_1},
    {"indxsymp",                too_few_2,      CC_indxsymp,   wrong_no_2},
    {"red_tailreddriver",       wrong_no_na,    wrong_no_nb,   (n_args *)CC_red_tailreddriver},
    {"*di2q",                   too_few_2,      CC_Hdi2q,      wrong_no_2},
    {"solvealgdepends",         too_few_2,      CC_solvealgdepends,wrong_no_2},
    {"iv_cutcongs1",            too_few_2,      CC_iv_cutcongs1,wrong_no_2},
    {"innprodp2",               too_few_2,      CC_innprodp2,  wrong_no_2},
    {"dvfsf_smcpknowl",         CC_dvfsf_smcpknowl,too_many_1, wrong_no_1},
    {"sets",                    too_few_2,      CC_sets,       wrong_no_2},
    {NULL, (one_args *)"u30", (two_args *)"22730 2290125 309600", 0}
};

/* end of generated code */
