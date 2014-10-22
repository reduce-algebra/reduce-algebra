
/* $destdir\u41.c        Machine generated C code */

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


/* Code for diffp */

static Lisp_Object CC_diffp(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0281, v0282, v0283, v0284, v0285;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for diffp");
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
/* copy arguments values to proper place */
    stack[-7] = v0001;
    stack[-8] = v0000;
/* end of prologue */
    stack[0] = nil;
    v0281 = stack[-8];
    v0281 = qcdr(v0281);
    stack[-9] = v0281;
    v0281 = stack[-8];
    v0281 = qcar(v0281);
    stack[-8] = v0281;
    v0282 = stack[-9];
    v0281 = (Lisp_Object)17; /* 1 */
    v0281 = (Lisp_Object)greaterp2(v0282, v0281);
    nil = C_nil;
    if (exception_pending()) goto v0286;
    v0281 = v0281 ? lisp_true : nil;
    env = stack[-10];
    if (v0281 == nil) goto v0287;
    v0281 = stack[-8];
    fn = elt(env, 24); /* noncomp */
    v0281 = (*qfn1(fn))(qenv(fn), v0281);
    nil = C_nil;
    if (exception_pending()) goto v0286;
    env = stack[-10];
    if (v0281 == nil) goto v0287;
    v0282 = stack[-8];
    v0281 = stack[-7];
    v0281 = list2(v0282, v0281);
    nil = C_nil;
    if (exception_pending()) goto v0286;
    env = stack[-10];
    fn = elt(env, 25); /* simpdf */
    stack[-1] = (*qfn1(fn))(qenv(fn), v0281);
    nil = C_nil;
    if (exception_pending()) goto v0286;
    env = stack[-10];
    stack[0] = stack[-8];
    v0281 = stack[-9];
    v0281 = sub1(v0281);
    nil = C_nil;
    if (exception_pending()) goto v0286;
    env = stack[-10];
    v0281 = list2(stack[0], v0281);
    nil = C_nil;
    if (exception_pending()) goto v0286;
    env = stack[-10];
    fn = elt(env, 26); /* simpexpt */
    v0281 = (*qfn1(fn))(qenv(fn), v0281);
    nil = C_nil;
    if (exception_pending()) goto v0286;
    env = stack[-10];
    fn = elt(env, 27); /* multsq */
    stack[-1] = (*qfn2(fn))(qenv(fn), stack[-1], v0281);
    nil = C_nil;
    if (exception_pending()) goto v0286;
    env = stack[-10];
    v0282 = stack[-8];
    v0281 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 28); /* to */
    v0282 = (*qfn2(fn))(qenv(fn), v0282, v0281);
    nil = C_nil;
    if (exception_pending()) goto v0286;
    env = stack[-10];
    v0281 = (Lisp_Object)17; /* 1 */
    v0281 = cons(v0282, v0281);
    nil = C_nil;
    if (exception_pending()) goto v0286;
    env = stack[-10];
    v0282 = ncons(v0281);
    nil = C_nil;
    if (exception_pending()) goto v0286;
    env = stack[-10];
    v0281 = (Lisp_Object)17; /* 1 */
    stack[0] = cons(v0282, v0281);
    nil = C_nil;
    if (exception_pending()) goto v0286;
    env = stack[-10];
    stack[-2] = stack[-8];
    v0281 = stack[-9];
    v0281 = sub1(v0281);
    nil = C_nil;
    if (exception_pending()) goto v0286;
    env = stack[-10];
    v0282 = cons(stack[-2], v0281);
    nil = C_nil;
    if (exception_pending()) goto v0286;
    env = stack[-10];
    v0281 = stack[-7];
    v0281 = CC_diffp(env, v0282, v0281);
    nil = C_nil;
    if (exception_pending()) goto v0286;
    env = stack[-10];
    fn = elt(env, 27); /* multsq */
    v0281 = (*qfn2(fn))(qenv(fn), stack[0], v0281);
    nil = C_nil;
    if (exception_pending()) goto v0286;
    env = stack[-10];
    {
        Lisp_Object v0288 = stack[-1];
        popv(11);
        fn = elt(env, 29); /* addsq */
        return (*qfn2(fn))(qenv(fn), v0288, v0281);
    }

v0287:
    v0282 = stack[-8];
    v0281 = stack[-7];
    if (v0282 == v0281) goto v0289;
    v0281 = qvalue(elt(env, 1)); /* nil */
    goto v0290;

v0290:
    if (!(v0281 == nil)) goto v0291;
    v0281 = stack[-8];
    if (!consp(v0281)) goto v0292;
    v0281 = stack[-8];
    v0281 = qcar(v0281);
    if (!consp(v0281)) goto v0293;
    v0282 = stack[-8];
    v0281 = stack[-7];
    fn = elt(env, 30); /* difff */
    v0281 = (*qfn2(fn))(qenv(fn), v0282, v0281);
    nil = C_nil;
    if (exception_pending()) goto v0286;
    env = stack[-10];
    stack[0] = v0281;
    goto v0294;

v0294:
    if (!(v0281 == nil)) goto v0291;
    v0281 = stack[-8];
    v0282 = qcar(v0281);
    v0281 = elt(env, 2); /* !*sq */
    if (v0282 == v0281) goto v0295;
    v0281 = qvalue(elt(env, 1)); /* nil */
    goto v0296;

v0296:
    if (!(v0281 == nil)) goto v0291;
    v0281 = stack[-8];
    v0282 = qcar(v0281);
    v0281 = elt(env, 3); /* dfform */
    v0281 = get(v0282, v0281);
    env = stack[-10];
    stack[-6] = v0281;
    if (v0281 == nil) goto v0297;
    v0284 = stack[-6];
    v0283 = stack[-8];
    v0282 = stack[-7];
    v0281 = stack[-9];
        popv(11);
        return Lapply3(nil, 4, v0284, v0283, v0282, v0281);

v0297:
    v0281 = stack[-8];
    stack[-1] = qcar(v0281);
    v0281 = stack[-8];
    fn = elt(env, 31); /* dfn_prop */
    v0281 = (*qfn1(fn))(qenv(fn), v0281);
    nil = C_nil;
    if (exception_pending()) goto v0286;
    env = stack[-10];
    v0281 = get(stack[-1], v0281);
    env = stack[-10];
    stack[-6] = v0281;
    if (v0281 == nil) goto v0298;
    v0281 = stack[-6];
    stack[-5] = v0281;
    v0281 = stack[-8];
    v0281 = qcdr(v0281);
    stack[-4] = v0281;
    goto v0299;

v0299:
    v0281 = stack[-4];
    v0281 = qcar(v0281);
    fn = elt(env, 32); /* simp */
    v0282 = (*qfn1(fn))(qenv(fn), v0281);
    nil = C_nil;
    if (exception_pending()) goto v0286;
    env = stack[-10];
    v0281 = stack[-7];
    fn = elt(env, 33); /* diffsq */
    v0282 = (*qfn2(fn))(qenv(fn), v0282, v0281);
    nil = C_nil;
    if (exception_pending()) goto v0286;
    env = stack[-10];
    v0281 = stack[0];
    v0281 = cons(v0282, v0281);
    nil = C_nil;
    if (exception_pending()) goto v0286;
    env = stack[-10];
    stack[0] = v0281;
    v0281 = stack[0];
    v0281 = qcar(v0281);
    v0281 = qcar(v0281);
    if (v0281 == nil) goto v0300;
    v0281 = stack[-5];
    v0281 = qcar(v0281);
    if (!(v0281 == nil)) goto v0300;

v0301:
    v0281 = stack[-8];
    v0282 = qcar(v0281);
    v0281 = elt(env, 13); /* df */
    if (v0282 == v0281) goto v0302;
    v0281 = qvalue(elt(env, 18)); /* !*df_partial */
    if (v0281 == nil) goto v0303;
    v0281 = qvalue(elt(env, 11)); /* !*expanddf */
    if (v0281 == nil) goto v0303;
    v0281 = stack[-8];
    v0281 = qcdr(v0281);
    v0281 = qcar(v0281);
    if (!consp(v0281)) goto v0303;
    v0281 = stack[-8];
    v0281 = qcar(v0281);
    v0282 = Lexplode(nil, v0281);
    nil = C_nil;
    if (exception_pending()) goto v0286;
    env = stack[-10];
    v0281 = elt(env, 19); /* (!! !! !_) */
    v0281 = Lnconc(nil, v0282, v0281);
    nil = C_nil;
    if (exception_pending()) goto v0286;
    env = stack[-10];
    v0281 = Lcompress(nil, v0281);
    nil = C_nil;
    if (exception_pending()) goto v0286;
    env = stack[-10];
    v0281 = Lintern(nil, v0281);
    nil = C_nil;
    if (exception_pending()) goto v0286;
    env = stack[-10];
    stack[-6] = v0281;
    v0281 = stack[-8];
    v0281 = qcdr(v0281);
    stack[-5] = v0281;
    v0282 = qvalue(elt(env, 1)); /* nil */
    v0281 = (Lisp_Object)17; /* 1 */
    v0281 = cons(v0282, v0281);
    nil = C_nil;
    if (exception_pending()) goto v0286;
    env = stack[-10];
    stack[0] = v0281;
    v0281 = (Lisp_Object)1; /* 0 */
    stack[-3] = v0281;
    v0281 = stack[-5];
    stack[-2] = v0281;
    goto v0304;

v0304:
    v0281 = stack[-2];
    if (v0281 == nil) goto v0291;
    v0281 = stack[-2];
    v0281 = qcar(v0281);
    stack[-1] = v0281;
    v0281 = stack[-3];
    v0281 = add1(v0281);
    nil = C_nil;
    if (exception_pending()) goto v0286;
    env = stack[-10];
    stack[-3] = v0281;
    v0283 = elt(env, 13); /* df */
    v0282 = stack[-1];
    v0281 = stack[-7];
    v0281 = list3(v0283, v0282, v0281);
    nil = C_nil;
    if (exception_pending()) goto v0286;
    env = stack[-10];
    fn = elt(env, 32); /* simp */
    v0281 = (*qfn1(fn))(qenv(fn), v0281);
    nil = C_nil;
    if (exception_pending()) goto v0286;
    env = stack[-10];
    stack[-1] = v0281;
    v0281 = qcar(v0281);
    if (v0281 == nil) goto v0305;
    v0282 = stack[-6];
    v0281 = stack[-3];
    fn = elt(env, 34); /* mkid */
    v0281 = (*qfn2(fn))(qenv(fn), v0282, v0281);
    nil = C_nil;
    if (exception_pending()) goto v0286;
    env = stack[-10];
    stack[-4] = v0281;
    v0283 = stack[-4];
    v0282 = elt(env, 20); /* simpfn */
    v0281 = elt(env, 21); /* simpiden */
    v0281 = Lputprop(nil, 3, v0283, v0282, v0281);
    nil = C_nil;
    if (exception_pending()) goto v0286;
    env = stack[-10];
    v0282 = stack[-4];
    v0281 = stack[-5];
    v0281 = cons(v0282, v0281);
    nil = C_nil;
    if (exception_pending()) goto v0286;
    env = stack[-10];
    fn = elt(env, 32); /* simp */
    v0282 = (*qfn1(fn))(qenv(fn), v0281);
    nil = C_nil;
    if (exception_pending()) goto v0286;
    env = stack[-10];
    v0281 = stack[-1];
    fn = elt(env, 27); /* multsq */
    v0281 = (*qfn2(fn))(qenv(fn), v0282, v0281);
    nil = C_nil;
    if (exception_pending()) goto v0286;
    env = stack[-10];
    fn = elt(env, 29); /* addsq */
    v0281 = (*qfn2(fn))(qenv(fn), stack[0], v0281);
    nil = C_nil;
    if (exception_pending()) goto v0286;
    env = stack[-10];
    stack[0] = v0281;
    goto v0305;

v0305:
    v0281 = stack[-2];
    v0281 = qcdr(v0281);
    stack[-2] = v0281;
    goto v0304;

v0291:
    v0282 = stack[-8];
    v0281 = qvalue(elt(env, 5)); /* wtl!* */
    v0281 = Latsoc(nil, v0282, v0281);
    stack[-6] = v0281;
    if (v0281 == nil) goto v0306;
    stack[-1] = elt(env, 6); /* k!* */
    v0281 = stack[-6];
    v0281 = qcdr(v0281);
    v0281 = negate(v0281);
    nil = C_nil;
    if (exception_pending()) goto v0286;
    env = stack[-10];
    fn = elt(env, 28); /* to */
    v0282 = (*qfn2(fn))(qenv(fn), stack[-1], v0281);
    nil = C_nil;
    if (exception_pending()) goto v0286;
    env = stack[-10];
    v0281 = (Lisp_Object)17; /* 1 */
    v0281 = cons(v0282, v0281);
    nil = C_nil;
    if (exception_pending()) goto v0286;
    env = stack[-10];
    v0282 = ncons(v0281);
    nil = C_nil;
    if (exception_pending()) goto v0286;
    env = stack[-10];
    v0281 = (Lisp_Object)17; /* 1 */
    v0282 = cons(v0282, v0281);
    nil = C_nil;
    if (exception_pending()) goto v0286;
    env = stack[-10];
    v0281 = stack[0];
    fn = elt(env, 27); /* multsq */
    v0281 = (*qfn2(fn))(qenv(fn), v0282, v0281);
    nil = C_nil;
    if (exception_pending()) goto v0286;
    env = stack[-10];
    stack[0] = v0281;
    goto v0306;

v0306:
    v0281 = stack[-9];
    v0281 = sub1(v0281);
    nil = C_nil;
    if (exception_pending()) goto v0286;
    env = stack[-10];
    stack[-3] = v0281;
    v0282 = stack[-9];
    v0281 = (Lisp_Object)17; /* 1 */
    if (v0282 == v0281) goto v0307;
    v0281 = qvalue(elt(env, 7)); /* dmode!* */
    if (!symbolp(v0281)) v0281 = nil;
    else { v0281 = qfastgets(v0281);
           if (v0281 != nil) { v0281 = elt(v0281, 5); /* convert */
#ifdef RECORD_GET
             if (v0281 == SPID_NOPROP)
                record_get(elt(fastget_names, 5), 0),
                v0281 = nil;
             else record_get(elt(fastget_names, 5), 1),
                v0281 = lisp_true; }
           else record_get(elt(fastget_names, 5), 0); }
#else
             if (v0281 == SPID_NOPROP) v0281 = nil; else v0281 = lisp_true; }}
#endif
    if (v0281 == nil) goto v0308;
    v0281 = qvalue(elt(env, 7)); /* dmode!* */
    if (!symbolp(v0281)) v0282 = nil;
    else { v0282 = qfastgets(v0281);
           if (v0282 != nil) { v0282 = elt(v0282, 34); /* i2d */
#ifdef RECORD_GET
             if (v0282 != SPID_NOPROP)
                record_get(elt(fastget_names, 34), 1);
             else record_get(elt(fastget_names, 34), 0),
                v0282 = nil; }
           else record_get(elt(fastget_names, 34), 0); }
#else
             if (v0282 == SPID_NOPROP) v0282 = nil; }}
#endif
    v0281 = stack[-9];
    v0281 = Lapply1(nil, v0282, v0281);
    nil = C_nil;
    if (exception_pending()) goto v0286;
    env = stack[-10];
    fn = elt(env, 35); /* int!-equiv!-chk */
    v0281 = (*qfn1(fn))(qenv(fn), v0281);
    nil = C_nil;
    if (exception_pending()) goto v0286;
    env = stack[-10];
    stack[-9] = v0281;
    v0281 = (v0281 == nil ? lisp_true : nil);
    goto v0309;

v0309:
    if (v0281 == nil) goto v0310;
    v0282 = qvalue(elt(env, 1)); /* nil */
    v0281 = (Lisp_Object)17; /* 1 */
    v0281 = cons(v0282, v0281);
    nil = C_nil;
    if (exception_pending()) goto v0286;
    env = stack[-10];
    goto v0311;

v0311:
    {
        popv(11);
        fn = elt(env, 36); /* rationalizesq */
        return (*qfn1(fn))(qenv(fn), v0281);
    }

v0310:
    v0282 = stack[-8];
    v0281 = stack[-3];
    fn = elt(env, 28); /* to */
    v0282 = (*qfn2(fn))(qenv(fn), v0282, v0281);
    nil = C_nil;
    if (exception_pending()) goto v0286;
    env = stack[-10];
    v0281 = stack[-9];
    v0281 = cons(v0282, v0281);
    nil = C_nil;
    if (exception_pending()) goto v0286;
    env = stack[-10];
    v0282 = ncons(v0281);
    nil = C_nil;
    if (exception_pending()) goto v0286;
    env = stack[-10];
    v0281 = (Lisp_Object)17; /* 1 */
    v0282 = cons(v0282, v0281);
    nil = C_nil;
    if (exception_pending()) goto v0286;
    env = stack[-10];
    v0281 = stack[0];
    fn = elt(env, 27); /* multsq */
    v0281 = (*qfn2(fn))(qenv(fn), v0282, v0281);
    nil = C_nil;
    if (exception_pending()) goto v0286;
    env = stack[-10];
    goto v0311;

v0308:
    v0281 = qvalue(elt(env, 1)); /* nil */
    goto v0309;

v0307:
    v0281 = stack[0];
    goto v0311;

v0303:
    v0283 = elt(env, 13); /* df */
    v0282 = stack[-8];
    v0281 = stack[-7];
    v0281 = list3(v0283, v0282, v0281);
    nil = C_nil;
    if (exception_pending()) goto v0286;
    env = stack[-10];
    stack[0] = v0281;
    goto v0312;

v0312:
    v0281 = stack[0];
    fn = elt(env, 37); /* opmtch */
    v0281 = (*qfn1(fn))(qenv(fn), v0281);
    nil = C_nil;
    if (exception_pending()) goto v0286;
    env = stack[-10];
    stack[-6] = v0281;
    if (v0281 == nil) goto v0313;
    v0281 = stack[-6];
    fn = elt(env, 32); /* simp */
    v0281 = (*qfn1(fn))(qenv(fn), v0281);
    nil = C_nil;
    if (exception_pending()) goto v0286;
    env = stack[-10];
    stack[0] = v0281;
    goto v0291;

v0313:
    v0282 = stack[-8];
    v0281 = stack[-7];
    fn = elt(env, 38); /* depends */
    v0281 = (*qfn2(fn))(qenv(fn), v0282, v0281);
    nil = C_nil;
    if (exception_pending()) goto v0286;
    env = stack[-10];
    if (v0281 == nil) goto v0314;
    v0281 = qvalue(elt(env, 1)); /* nil */
    goto v0315;

v0315:
    if (v0281 == nil) goto v0316;
    v0282 = qvalue(elt(env, 1)); /* nil */
    v0281 = (Lisp_Object)17; /* 1 */
    popv(11);
    return cons(v0282, v0281);

v0316:
    v0281 = qvalue(elt(env, 11)); /* !*expanddf */
    if (v0281 == nil) goto v0317;
    v0281 = stack[-8];
    if (!consp(v0281)) goto v0318;
    v0281 = stack[0];
    v0281 = qcdr(v0281);
    v0281 = qcdr(v0281);
    v0281 = qcdr(v0281);
    if (v0281 == nil) goto v0319;
    v0281 = qvalue(elt(env, 1)); /* nil */
    goto v0320;

v0320:
    if (v0281 == nil) goto v0317;
    v0282 = stack[-8];
    v0281 = qvalue(elt(env, 12)); /* depl!* */
    v0281 = Lassoc(nil, v0282, v0281);
    stack[-6] = v0281;
    v0281 = stack[-8];
    v0281 = qcdr(v0281);
    if (v0281 == nil) goto v0321;
    v0281 = stack[-8];
    v0281 = qcdr(v0281);
    fn = elt(env, 39); /* get!-all!-kernels */
    v0281 = (*qfn1(fn))(qenv(fn), v0281);
    nil = C_nil;
    if (exception_pending()) goto v0286;
    env = stack[-10];
    goto v0322;

v0322:
    stack[-5] = v0281;
    v0281 = stack[-6];
    if (v0281 == nil) goto v0323;
    v0281 = stack[-5];
    if (v0281 == nil) goto v0323;
    v0282 = stack[-7];
    v0281 = stack[-5];
    v0282 = Ldelete(nil, v0282, v0281);
    nil = C_nil;
    if (exception_pending()) goto v0286;
    env = stack[-10];
    v0281 = stack[-7];
    fn = elt(env, 40); /* ldepends */
    v0281 = (*qfn2(fn))(qenv(fn), v0282, v0281);
    nil = C_nil;
    if (exception_pending()) goto v0286;
    env = stack[-10];
    if (v0281 == nil) goto v0323;
    v0285 = elt(env, 23); /* "Possible inconsistent dependencies in" */
    v0284 = stack[-8];
    v0283 = qvalue(elt(env, 1)); /* nil */
    v0282 = qvalue(elt(env, 1)); /* nil */
    v0281 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 41); /* msgpri */
    v0281 = (*qfnn(fn))(qenv(fn), 5, v0285, v0284, v0283, v0282, v0281);
    nil = C_nil;
    if (exception_pending()) goto v0286;
    env = stack[-10];
    v0282 = stack[0];
    v0281 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 42); /* mksq */
    v0281 = (*qfn2(fn))(qenv(fn), v0282, v0281);
    nil = C_nil;
    if (exception_pending()) goto v0286;
    env = stack[-10];
    stack[0] = v0281;
    goto v0291;

v0323:
    v0281 = stack[-6];
    if (v0281 == nil) goto v0324;
    v0282 = stack[-7];
    v0281 = stack[-6];
    v0281 = qcdr(v0281);
    stack[-6] = v0281;
    v0281 = Lmemq(nil, v0282, v0281);
    if (v0281 == nil) goto v0325;
    v0282 = stack[0];
    v0281 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 42); /* mksq */
    v0281 = (*qfn2(fn))(qenv(fn), v0282, v0281);
    nil = C_nil;
    if (exception_pending()) goto v0286;
    env = stack[-10];
    stack[0] = v0281;
    goto v0291;

v0325:
    v0283 = stack[-8];
    v0282 = stack[-7];
    v0281 = stack[-6];
    fn = elt(env, 43); /* df!-chain!-rule */
    v0281 = (*qfnn(fn))(qenv(fn), 3, v0283, v0282, v0281);
    nil = C_nil;
    if (exception_pending()) goto v0286;
    env = stack[-10];
    stack[0] = v0281;
    goto v0291;

v0324:
    v0281 = stack[-5];
    if (v0281 == nil) goto v0326;
    v0282 = stack[-7];
    v0281 = stack[-5];
    fn = elt(env, 44); /* smember */
    v0281 = (*qfn2(fn))(qenv(fn), v0282, v0281);
    nil = C_nil;
    if (exception_pending()) goto v0286;
    env = stack[-10];
    if (v0281 == nil) goto v0327;
    v0282 = stack[0];
    v0281 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 42); /* mksq */
    v0281 = (*qfn2(fn))(qenv(fn), v0282, v0281);
    nil = C_nil;
    if (exception_pending()) goto v0286;
    env = stack[-10];
    goto v0328;

v0328:
    stack[0] = v0281;
    goto v0291;

v0327:
    v0283 = stack[-8];
    v0282 = stack[-7];
    v0281 = stack[-5];
    fn = elt(env, 43); /* df!-chain!-rule */
    v0281 = (*qfnn(fn))(qenv(fn), 3, v0283, v0282, v0281);
    nil = C_nil;
    if (exception_pending()) goto v0286;
    env = stack[-10];
    goto v0328;

v0326:
    v0282 = stack[0];
    v0281 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 42); /* mksq */
    v0281 = (*qfn2(fn))(qenv(fn), v0282, v0281);
    nil = C_nil;
    if (exception_pending()) goto v0286;
    env = stack[-10];
    stack[0] = v0281;
    goto v0291;

v0321:
    v0281 = qvalue(elt(env, 1)); /* nil */
    goto v0322;

v0317:
    v0282 = stack[0];
    v0281 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 42); /* mksq */
    v0281 = (*qfn2(fn))(qenv(fn), v0282, v0281);
    nil = C_nil;
    if (exception_pending()) goto v0286;
    env = stack[-10];
    stack[0] = v0281;
    goto v0291;

v0319:
    v0281 = stack[-8];
    v0282 = qcar(v0281);
    v0281 = elt(env, 22); /* (df int) */
    v0281 = Lmemq(nil, v0282, v0281);
    if (v0281 == nil) goto v0329;
    v0281 = qvalue(elt(env, 1)); /* nil */
    goto v0320;

v0329:
    v0282 = stack[-7];
    v0281 = stack[-8];
    fn = elt(env, 44); /* smember */
    v0281 = (*qfn2(fn))(qenv(fn), v0282, v0281);
    nil = C_nil;
    if (exception_pending()) goto v0286;
    env = stack[-10];
    if (v0281 == nil) goto v0330;
    v0281 = qvalue(elt(env, 1)); /* nil */
    goto v0320;

v0330:
    v0282 = stack[-8];
    v0281 = qvalue(elt(env, 8)); /* powlis!* */
    v0281 = Latsoc(nil, v0282, v0281);
    stack[-6] = v0281;
    if (v0281 == nil) goto v0331;
    v0281 = stack[-6];
    v0281 = qcdr(v0281);
    v0281 = qcdr(v0281);
    v0281 = qcdr(v0281);
    v0282 = qcar(v0281);
    v0281 = stack[-7];
    fn = elt(env, 38); /* depends */
    v0281 = (*qfn2(fn))(qenv(fn), v0282, v0281);
    nil = C_nil;
    if (exception_pending()) goto v0286;
    env = stack[-10];
    v0281 = (v0281 == nil ? lisp_true : nil);
    goto v0320;

v0331:
    v0281 = qvalue(elt(env, 9)); /* t */
    goto v0320;

v0318:
    v0281 = qvalue(elt(env, 1)); /* nil */
    goto v0320;

v0314:
    v0281 = stack[0];
    v0281 = qcdr(v0281);
    v0282 = qcar(v0281);
    stack[-8] = v0282;
    v0281 = qvalue(elt(env, 8)); /* powlis!* */
    v0281 = Latsoc(nil, v0282, v0281);
    stack[-6] = v0281;
    if (v0281 == nil) goto v0332;
    v0281 = stack[-6];
    v0281 = qcdr(v0281);
    v0281 = qcdr(v0281);
    v0281 = qcdr(v0281);
    v0282 = qcar(v0281);
    v0281 = stack[0];
    v0281 = qcdr(v0281);
    v0281 = qcdr(v0281);
    fn = elt(env, 45); /* dependsl */
    v0281 = (*qfn2(fn))(qenv(fn), v0282, v0281);
    nil = C_nil;
    if (exception_pending()) goto v0286;
    env = stack[-10];
    v0281 = (v0281 == nil ? lisp_true : nil);
    goto v0333;

v0333:
    if (v0281 == nil) goto v0334;
    v0281 = qvalue(elt(env, 10)); /* !*depend */
    v0281 = (v0281 == nil ? lisp_true : nil);
    goto v0315;

v0334:
    v0281 = qvalue(elt(env, 1)); /* nil */
    goto v0315;

v0332:
    v0281 = qvalue(elt(env, 9)); /* t */
    goto v0333;

v0302:
    v0281 = stack[-8];
    v0281 = qcdr(v0281);
    v0282 = qcar(v0281);
    v0281 = stack[-7];
    if (v0282 == v0281) goto v0335;
    v0281 = stack[-8];
    v0281 = qcdr(v0281);
    v0282 = qcar(v0281);
    v0281 = elt(env, 16); /* int */
    if (!consp(v0282)) goto v0336;
    v0282 = qcar(v0282);
    if (!(v0282 == v0281)) goto v0336;
    v0281 = stack[-8];
    v0281 = qcdr(v0281);
    v0281 = qcar(v0281);
    v0281 = qcdr(v0281);
    v0281 = qcdr(v0281);
    v0282 = qcar(v0281);
    v0281 = stack[-7];
    if (v0282 == v0281) goto v0337;
    v0281 = qvalue(elt(env, 17)); /* !*allowdfint */
    if (v0281 == nil) goto v0336;
    v0281 = stack[-8];
    v0281 = qcdr(v0281);
    v0281 = qcar(v0281);
    v0281 = qcdr(v0281);
    v0281 = qcar(v0281);
    fn = elt(env, 46); /* simp!* */
    v0282 = (*qfn1(fn))(qenv(fn), v0281);
    nil = C_nil;
    if (exception_pending()) goto v0286;
    env = stack[-10];
    v0281 = stack[-7];
    fn = elt(env, 33); /* diffsq */
    v0281 = (*qfn2(fn))(qenv(fn), v0282, v0281);
    nil = C_nil;
    if (exception_pending()) goto v0286;
    env = stack[-10];
    stack[0] = v0281;
    fn = elt(env, 47); /* not_df_p */
    v0281 = (*qfn1(fn))(qenv(fn), v0281);
    nil = C_nil;
    if (exception_pending()) goto v0286;
    env = stack[-10];
    if (v0281 == nil) goto v0336;
    stack[-2] = elt(env, 13); /* df */
    stack[-1] = elt(env, 16); /* int */
    v0281 = stack[0];
    fn = elt(env, 48); /* mk!*sq */
    v0282 = (*qfn1(fn))(qenv(fn), v0281);
    nil = C_nil;
    if (exception_pending()) goto v0286;
    env = stack[-10];
    v0281 = stack[-8];
    v0281 = qcdr(v0281);
    v0281 = qcar(v0281);
    v0281 = qcdr(v0281);
    v0281 = qcdr(v0281);
    v0281 = qcar(v0281);
    v0281 = list3(stack[-1], v0282, v0281);
    nil = C_nil;
    if (exception_pending()) goto v0286;
    env = stack[-10];
    fn = elt(env, 49); /* reval */
    v0282 = (*qfn1(fn))(qenv(fn), v0281);
    nil = C_nil;
    if (exception_pending()) goto v0286;
    env = stack[-10];
    v0281 = stack[-8];
    v0281 = qcdr(v0281);
    v0281 = qcdr(v0281);
    v0281 = list2star(stack[-2], v0282, v0281);
    nil = C_nil;
    if (exception_pending()) goto v0286;
    env = stack[-10];
    stack[0] = v0281;
    goto v0312;

v0336:
    v0281 = qvalue(elt(env, 11)); /* !*expanddf */
    if (v0281 == nil) goto v0338;
    v0281 = stack[-8];
    v0281 = qcdr(v0281);
    v0282 = qcar(v0281);
    v0281 = stack[-7];
    fn = elt(env, 38); /* depends */
    v0281 = (*qfn2(fn))(qenv(fn), v0282, v0281);
    nil = C_nil;
    if (exception_pending()) goto v0286;
    env = stack[-10];
    if (v0281 == nil) goto v0338;
    v0281 = stack[-8];
    v0281 = qcdr(v0281);
    v0282 = qcar(v0281);
    v0281 = qvalue(elt(env, 8)); /* powlis!* */
    v0281 = Latsoc(nil, v0282, v0281);
    stack[-6] = v0281;
    if (v0281 == nil) goto v0339;
    v0281 = stack[-6];
    v0281 = qcdr(v0281);
    v0281 = qcdr(v0281);
    v0281 = qcdr(v0281);
    v0282 = qcar(v0281);
    v0281 = stack[-7];
    fn = elt(env, 38); /* depends */
    v0281 = (*qfn2(fn))(qenv(fn), v0282, v0281);
    nil = C_nil;
    if (exception_pending()) goto v0286;
    env = stack[-10];
    v0281 = (v0281 == nil ? lisp_true : nil);
    goto v0340;

v0340:
    if (v0281 == nil) goto v0338;
    v0282 = stack[-7];
    v0281 = stack[-8];
    v0281 = qcdr(v0281);
    v0281 = qcar(v0281);
    fn = elt(env, 44); /* smember */
    v0281 = (*qfn2(fn))(qenv(fn), v0282, v0281);
    nil = C_nil;
    if (exception_pending()) goto v0286;
    env = stack[-10];
    if (!(v0281 == nil)) goto v0338;
    v0281 = stack[-8];
    v0281 = qcdr(v0281);
    v0282 = qcar(v0281);
    v0281 = qvalue(elt(env, 12)); /* depl!* */
    v0281 = Lassoc(nil, v0282, v0281);
    stack[-6] = v0281;
    v0281 = stack[-8];
    v0281 = qcdr(v0281);
    v0281 = qcar(v0281);
    if (!consp(v0281)) goto v0341;
    v0281 = stack[-8];
    v0281 = qcdr(v0281);
    v0281 = qcar(v0281);
    v0281 = qcdr(v0281);
    if (v0281 == nil) goto v0342;
    v0281 = stack[-8];
    v0281 = qcdr(v0281);
    v0281 = qcar(v0281);
    v0281 = qcdr(v0281);
    fn = elt(env, 39); /* get!-all!-kernels */
    v0281 = (*qfn1(fn))(qenv(fn), v0281);
    nil = C_nil;
    if (exception_pending()) goto v0286;
    env = stack[-10];
    goto v0343;

v0343:
    stack[-5] = v0281;
    v0281 = stack[-6];
    if (v0281 == nil) goto v0344;
    v0281 = stack[-5];
    if (v0281 == nil) goto v0344;
    v0282 = stack[-7];
    v0281 = stack[-5];
    v0282 = Ldelete(nil, v0282, v0281);
    nil = C_nil;
    if (exception_pending()) goto v0286;
    env = stack[-10];
    v0281 = stack[-7];
    fn = elt(env, 40); /* ldepends */
    v0281 = (*qfn2(fn))(qenv(fn), v0282, v0281);
    nil = C_nil;
    if (exception_pending()) goto v0286;
    env = stack[-10];
    if (!(v0281 == nil)) goto v0338;

v0344:
    v0281 = stack[-6];
    if (v0281 == nil) goto v0345;
    v0282 = stack[-7];
    v0281 = stack[-6];
    v0281 = qcdr(v0281);
    stack[-6] = v0281;
    v0281 = Lmemq(nil, v0282, v0281);
    if (!(v0281 == nil)) goto v0345;
    v0283 = stack[-8];
    v0282 = stack[-7];
    v0281 = stack[-6];
    fn = elt(env, 43); /* df!-chain!-rule */
    v0281 = (*qfnn(fn))(qenv(fn), 3, v0283, v0282, v0281);
    nil = C_nil;
    if (exception_pending()) goto v0286;
    env = stack[-10];
    stack[0] = v0281;
    goto v0291;

v0345:
    v0281 = stack[-5];
    if (v0281 == nil) goto v0338;
    v0282 = stack[-7];
    v0281 = stack[-5];
    fn = elt(env, 44); /* smember */
    v0281 = (*qfn2(fn))(qenv(fn), v0282, v0281);
    nil = C_nil;
    if (exception_pending()) goto v0286;
    env = stack[-10];
    if (!(v0281 == nil)) goto v0338;
    v0283 = stack[-8];
    v0282 = stack[-7];
    v0281 = stack[-5];
    fn = elt(env, 43); /* df!-chain!-rule */
    v0281 = (*qfnn(fn))(qenv(fn), 3, v0283, v0282, v0281);
    nil = C_nil;
    if (exception_pending()) goto v0286;
    env = stack[-10];
    stack[0] = v0281;
    goto v0291;

v0338:
    v0281 = stack[-8];
    v0281 = qcdr(v0281);
    stack[0] = qcar(v0281);
    v0282 = stack[-8];
    v0281 = stack[-7];
    fn = elt(env, 50); /* merge!-ind!-vars */
    v0281 = (*qfn2(fn))(qenv(fn), v0282, v0281);
    nil = C_nil;
    if (exception_pending()) goto v0286;
    env = stack[-10];
    v0282 = cons(stack[0], v0281);
    nil = C_nil;
    if (exception_pending()) goto v0286;
    env = stack[-10];
    stack[0] = v0282;
    v0281 = elt(env, 13); /* df */
    if (!symbolp(v0281)) v0281 = nil;
    else { v0281 = qfastgets(v0281);
           if (v0281 != nil) { v0281 = elt(v0281, 50); /* kvalue */
#ifdef RECORD_GET
             if (v0281 != SPID_NOPROP)
                record_get(elt(fastget_names, 50), 1);
             else record_get(elt(fastget_names, 50), 0),
                v0281 = nil; }
           else record_get(elt(fastget_names, 50), 0); }
#else
             if (v0281 == SPID_NOPROP) v0281 = nil; }}
#endif
    fn = elt(env, 51); /* find_sub_df */
    v0281 = (*qfn2(fn))(qenv(fn), v0282, v0281);
    nil = C_nil;
    if (exception_pending()) goto v0286;
    env = stack[-10];
    stack[-6] = v0281;
    if (v0281 == nil) goto v0346;
    v0281 = stack[-6];
    v0281 = qcar(v0281);
    fn = elt(env, 32); /* simp */
    v0281 = (*qfn1(fn))(qenv(fn), v0281);
    nil = C_nil;
    if (exception_pending()) goto v0286;
    env = stack[-10];
    stack[0] = v0281;
    v0281 = stack[-6];
    v0281 = qcdr(v0281);
    stack[-3] = v0281;
    goto v0347;

v0347:
    v0281 = stack[-3];
    if (v0281 == nil) goto v0291;
    v0281 = stack[-3];
    v0281 = qcar(v0281);
    stack[-2] = v0281;
    v0281 = (Lisp_Object)17; /* 1 */
    stack[-1] = v0281;
    goto v0348;

v0348:
    v0281 = stack[-2];
    v0282 = qcdr(v0281);
    v0281 = stack[-1];
    v0281 = difference2(v0282, v0281);
    nil = C_nil;
    if (exception_pending()) goto v0286;
    env = stack[-10];
    v0281 = Lminusp(nil, v0281);
    env = stack[-10];
    if (v0281 == nil) goto v0349;
    v0281 = stack[-3];
    v0281 = qcdr(v0281);
    stack[-3] = v0281;
    goto v0347;

v0349:
    v0282 = stack[0];
    v0281 = stack[-2];
    v0281 = qcar(v0281);
    fn = elt(env, 33); /* diffsq */
    v0281 = (*qfn2(fn))(qenv(fn), v0282, v0281);
    nil = C_nil;
    if (exception_pending()) goto v0286;
    env = stack[-10];
    stack[0] = v0281;
    v0281 = stack[-1];
    v0281 = add1(v0281);
    nil = C_nil;
    if (exception_pending()) goto v0286;
    env = stack[-10];
    stack[-1] = v0281;
    goto v0348;

v0346:
    v0282 = elt(env, 13); /* df */
    v0281 = stack[0];
    v0281 = cons(v0282, v0281);
    nil = C_nil;
    if (exception_pending()) goto v0286;
    env = stack[-10];
    stack[0] = v0281;
    goto v0312;

v0342:
    v0281 = qvalue(elt(env, 1)); /* nil */
    goto v0343;

v0341:
    v0281 = qvalue(elt(env, 1)); /* nil */
    goto v0343;

v0339:
    v0281 = qvalue(elt(env, 9)); /* t */
    goto v0340;

v0337:
    v0283 = elt(env, 13); /* df */
    v0281 = stack[-8];
    v0281 = qcdr(v0281);
    v0281 = qcar(v0281);
    v0281 = qcdr(v0281);
    v0282 = qcar(v0281);
    v0281 = stack[-8];
    v0281 = qcdr(v0281);
    v0281 = qcdr(v0281);
    v0281 = list2star(v0283, v0282, v0281);
    nil = C_nil;
    if (exception_pending()) goto v0286;
    env = stack[-10];
    stack[0] = v0281;
    goto v0312;

v0335:
    v0281 = qvalue(elt(env, 14)); /* !*commutedf */
    if (v0281 == nil) goto v0350;
    v0281 = qvalue(elt(env, 10)); /* !*depend */
    if (!(v0281 == nil)) goto v0350;
    v0282 = qvalue(elt(env, 1)); /* nil */
    v0281 = (Lisp_Object)17; /* 1 */
    popv(11);
    return cons(v0282, v0281);

v0350:
    v0281 = qvalue(elt(env, 15)); /* !*simpnoncomdf */
    if (v0281 == nil) goto v0336;
    v0282 = stack[-7];
    v0281 = qvalue(elt(env, 12)); /* depl!* */
    v0281 = Latsoc(nil, v0282, v0281);
    stack[0] = v0281;
    if (v0281 == nil) goto v0336;
    v0281 = stack[0];
    v0281 = qcdr(v0281);
    v0281 = qcdr(v0281);
    if (!(v0281 == nil)) goto v0336;
    v0281 = stack[-8];
    v0281 = qcdr(v0281);
    v0281 = qcdr(v0281);
    v0281 = qcar(v0281);
    stack[-6] = v0281;
    v0283 = elt(env, 13); /* df */
    v0282 = stack[-8];
    v0281 = stack[-6];
    v0281 = list3(v0283, v0282, v0281);
    nil = C_nil;
    if (exception_pending()) goto v0286;
    env = stack[-10];
    fn = elt(env, 32); /* simp */
    stack[0] = (*qfn1(fn))(qenv(fn), v0281);
    nil = C_nil;
    if (exception_pending()) goto v0286;
    env = stack[-10];
    v0283 = elt(env, 13); /* df */
    v0282 = stack[-7];
    v0281 = stack[-6];
    v0281 = list3(v0283, v0282, v0281);
    nil = C_nil;
    if (exception_pending()) goto v0286;
    env = stack[-10];
    fn = elt(env, 32); /* simp */
    v0281 = (*qfn1(fn))(qenv(fn), v0281);
    nil = C_nil;
    if (exception_pending()) goto v0286;
    env = stack[-10];
    fn = elt(env, 52); /* quotsq */
    v0281 = (*qfn2(fn))(qenv(fn), stack[0], v0281);
    nil = C_nil;
    if (exception_pending()) goto v0286;
    env = stack[-10];
    stack[0] = v0281;
    goto v0291;

v0300:
    v0281 = stack[-5];
    v0281 = qcdr(v0281);
    stack[-5] = v0281;
    v0281 = stack[-4];
    v0281 = qcdr(v0281);
    stack[-4] = v0281;
    v0281 = stack[-4];
    if (v0281 == nil) goto v0351;
    v0281 = stack[-5];
    if (!(v0281 == nil)) goto v0299;

v0351:
    v0281 = stack[-4];
    if (!(v0281 == nil)) goto v0301;
    v0281 = stack[-5];
    if (!(v0281 == nil)) goto v0301;
    v0281 = stack[0];
    v0281 = Lreverse(nil, v0281);
    nil = C_nil;
    if (exception_pending()) goto v0286;
    env = stack[-10];
    stack[-5] = v0281;
    v0281 = stack[-8];
    v0281 = qcdr(v0281);
    stack[-4] = v0281;
    v0282 = qvalue(elt(env, 1)); /* nil */
    v0281 = (Lisp_Object)17; /* 1 */
    v0281 = cons(v0282, v0281);
    nil = C_nil;
    if (exception_pending()) goto v0286;
    env = stack[-10];
    stack[0] = v0281;
    goto v0352;

v0352:
    v0281 = stack[-5];
    v0281 = qcar(v0281);
    v0281 = qcar(v0281);
    if (v0281 == nil) goto v0353;
    v0281 = stack[-5];
    stack[-1] = qcar(v0281);
    v0281 = stack[-6];
    v0281 = qcar(v0281);
    v0282 = qcar(v0281);
    v0281 = stack[-4];
    fn = elt(env, 53); /* pair */
    v0282 = (*qfn2(fn))(qenv(fn), v0282, v0281);
    nil = C_nil;
    if (exception_pending()) goto v0286;
    env = stack[-10];
    v0281 = stack[-6];
    v0281 = qcar(v0281);
    v0281 = qcdr(v0281);
    v0281 = Lsubla(nil, v0282, v0281);
    nil = C_nil;
    if (exception_pending()) goto v0286;
    env = stack[-10];
    fn = elt(env, 32); /* simp */
    v0281 = (*qfn1(fn))(qenv(fn), v0281);
    nil = C_nil;
    if (exception_pending()) goto v0286;
    env = stack[-10];
    fn = elt(env, 27); /* multsq */
    v0282 = (*qfn2(fn))(qenv(fn), stack[-1], v0281);
    nil = C_nil;
    if (exception_pending()) goto v0286;
    env = stack[-10];
    v0281 = stack[0];
    fn = elt(env, 29); /* addsq */
    v0281 = (*qfn2(fn))(qenv(fn), v0282, v0281);
    nil = C_nil;
    if (exception_pending()) goto v0286;
    env = stack[-10];
    stack[0] = v0281;
    goto v0353;

v0353:
    v0281 = stack[-6];
    v0281 = qcdr(v0281);
    stack[-6] = v0281;
    v0281 = stack[-5];
    v0281 = qcdr(v0281);
    stack[-5] = v0281;
    v0281 = stack[-5];
    if (v0281 == nil) goto v0291;
    else goto v0352;

v0298:
    v0281 = stack[-8];
    v0282 = qcar(v0281);
    v0281 = elt(env, 4); /* plus */
    if (v0282 == v0281) goto v0354;
    v0281 = qvalue(elt(env, 1)); /* nil */
    goto v0355;

v0355:
    if (v0281 == nil) goto v0301;
    else goto v0291;

v0354:
    v0281 = stack[-8];
    fn = elt(env, 32); /* simp */
    v0282 = (*qfn1(fn))(qenv(fn), v0281);
    nil = C_nil;
    if (exception_pending()) goto v0286;
    env = stack[-10];
    v0281 = stack[-7];
    fn = elt(env, 33); /* diffsq */
    v0281 = (*qfn2(fn))(qenv(fn), v0282, v0281);
    nil = C_nil;
    if (exception_pending()) goto v0286;
    env = stack[-10];
    stack[0] = v0281;
    goto v0355;

v0295:
    v0281 = stack[-8];
    v0281 = qcdr(v0281);
    v0282 = qcar(v0281);
    v0281 = stack[-7];
    fn = elt(env, 33); /* diffsq */
    v0281 = (*qfn2(fn))(qenv(fn), v0282, v0281);
    nil = C_nil;
    if (exception_pending()) goto v0286;
    env = stack[-10];
    stack[0] = v0281;
    goto v0296;

v0293:
    v0281 = qvalue(elt(env, 1)); /* nil */
    goto v0294;

v0292:
    v0282 = stack[-8];
    v0281 = stack[-7];
    fn = elt(env, 38); /* depends */
    v0281 = (*qfn2(fn))(qenv(fn), v0282, v0281);
    nil = C_nil;
    if (exception_pending()) goto v0286;
    env = stack[-10];
    if (v0281 == nil) goto v0356;
    v0281 = qvalue(elt(env, 1)); /* nil */
    goto v0357;

v0357:
    if (v0281 == nil) goto v0358;
    v0282 = qvalue(elt(env, 1)); /* nil */
    v0281 = (Lisp_Object)17; /* 1 */
    popv(11);
    return cons(v0282, v0281);

v0358:
    v0281 = qvalue(elt(env, 11)); /* !*expanddf */
    if (v0281 == nil) goto v0359;
    v0282 = stack[-8];
    v0281 = qvalue(elt(env, 8)); /* powlis!* */
    v0281 = Latsoc(nil, v0282, v0281);
    stack[-6] = v0281;
    if (v0281 == nil) goto v0360;
    v0281 = stack[-6];
    v0281 = qcdr(v0281);
    v0281 = qcdr(v0281);
    v0281 = qcdr(v0281);
    v0282 = qcar(v0281);
    v0281 = stack[-7];
    fn = elt(env, 38); /* depends */
    v0281 = (*qfn2(fn))(qenv(fn), v0282, v0281);
    nil = C_nil;
    if (exception_pending()) goto v0286;
    env = stack[-10];
    v0281 = (v0281 == nil ? lisp_true : nil);
    goto v0361;

v0361:
    if (v0281 == nil) goto v0362;
    v0282 = stack[-8];
    v0281 = qvalue(elt(env, 12)); /* depl!* */
    v0281 = Latsoc(nil, v0282, v0281);
    stack[-6] = v0281;
    if (v0281 == nil) goto v0363;
    v0282 = stack[-7];
    v0281 = stack[-6];
    v0281 = qcdr(v0281);
    stack[-6] = v0281;
    v0281 = Lmemq(nil, v0282, v0281);
    v0281 = (v0281 == nil ? lisp_true : nil);
    goto v0364;

v0364:
    if (v0281 == nil) goto v0359;
    v0283 = stack[-8];
    v0282 = stack[-7];
    v0281 = stack[-6];
    fn = elt(env, 43); /* df!-chain!-rule */
    v0281 = (*qfnn(fn))(qenv(fn), 3, v0283, v0282, v0281);
    nil = C_nil;
    if (exception_pending()) goto v0286;
    env = stack[-10];
    stack[0] = v0281;
    goto v0291;

v0359:
    v0283 = elt(env, 13); /* df */
    v0282 = stack[-8];
    v0281 = stack[-7];
    v0281 = list3(v0283, v0282, v0281);
    nil = C_nil;
    if (exception_pending()) goto v0286;
    env = stack[-10];
    stack[0] = v0281;
    v0281 = stack[0];
    fn = elt(env, 37); /* opmtch */
    v0281 = (*qfn1(fn))(qenv(fn), v0281);
    nil = C_nil;
    if (exception_pending()) goto v0286;
    env = stack[-10];
    stack[-6] = v0281;
    if (v0281 == nil) goto v0365;
    v0281 = stack[-6];
    fn = elt(env, 32); /* simp */
    v0281 = (*qfn1(fn))(qenv(fn), v0281);
    nil = C_nil;
    if (exception_pending()) goto v0286;
    env = stack[-10];
    goto v0366;

v0366:
    stack[0] = v0281;
    goto v0291;

v0365:
    v0282 = stack[0];
    v0281 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 42); /* mksq */
    v0281 = (*qfn2(fn))(qenv(fn), v0282, v0281);
    nil = C_nil;
    if (exception_pending()) goto v0286;
    env = stack[-10];
    goto v0366;

v0363:
    v0281 = qvalue(elt(env, 1)); /* nil */
    goto v0364;

v0362:
    v0281 = qvalue(elt(env, 1)); /* nil */
    goto v0364;

v0360:
    v0281 = qvalue(elt(env, 9)); /* t */
    goto v0361;

v0356:
    v0282 = stack[-8];
    v0281 = qvalue(elt(env, 8)); /* powlis!* */
    v0281 = Latsoc(nil, v0282, v0281);
    stack[-6] = v0281;
    if (v0281 == nil) goto v0367;
    v0281 = stack[-6];
    v0281 = qcdr(v0281);
    v0281 = qcdr(v0281);
    v0281 = qcdr(v0281);
    v0282 = qcar(v0281);
    v0281 = stack[-7];
    fn = elt(env, 38); /* depends */
    v0281 = (*qfn2(fn))(qenv(fn), v0282, v0281);
    nil = C_nil;
    if (exception_pending()) goto v0286;
    env = stack[-10];
    v0281 = (v0281 == nil ? lisp_true : nil);
    goto v0368;

v0368:
    if (v0281 == nil) goto v0369;
    v0281 = qvalue(elt(env, 10)); /* !*depend */
    v0281 = (v0281 == nil ? lisp_true : nil);
    goto v0357;

v0369:
    v0281 = qvalue(elt(env, 1)); /* nil */
    goto v0357;

v0367:
    v0281 = qvalue(elt(env, 9)); /* t */
    goto v0368;

v0289:
    v0282 = (Lisp_Object)17; /* 1 */
    v0281 = (Lisp_Object)17; /* 1 */
    v0281 = cons(v0282, v0281);
    nil = C_nil;
    if (exception_pending()) goto v0286;
    env = stack[-10];
    stack[0] = v0281;
    goto v0290;
/* error exit handlers */
v0286:
    popv(11);
    return nil;
}



/* Code for dfdeg */

static Lisp_Object CC_dfdeg(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0373, v0374;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dfdeg");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0374 = v0001;
    v0373 = v0000;
/* end of prologue */
    v0374 = Lmember(nil, v0374, v0373);
    v0373 = v0374;
    if (v0374 == nil) goto v0018;
    v0374 = v0373;
    v0374 = qcdr(v0374);
    if (v0374 == nil) goto v0375;
    v0374 = v0373;
    v0374 = qcdr(v0374);
    v0374 = qcar(v0374);
    v0374 = integerp(v0374);
    v0374 = (v0374 == nil ? lisp_true : nil);
    goto v0376;

v0376:
    if (v0374 == nil) goto v0277;
    v0373 = (Lisp_Object)17; /* 1 */
    return onevalue(v0373);

v0277:
    v0373 = qcdr(v0373);
    v0373 = qcar(v0373);
    return onevalue(v0373);

v0375:
    v0374 = qvalue(elt(env, 1)); /* t */
    goto v0376;

v0018:
    v0373 = (Lisp_Object)1; /* 0 */
    return onevalue(v0373);
}



/* Code for pasf_premf */

static Lisp_Object CC_pasf_premf(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0370, v0376;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pasf_premf");
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
    v0370 = v0000;
/* end of prologue */
    v0376 = v0370;
    v0370 = stack[0];
    fn = elt(env, 1); /* remf */
    v0376 = (*qfn2(fn))(qenv(fn), v0376, v0370);
    nil = C_nil;
    if (exception_pending()) goto v0380;
    env = stack[-1];
    v0370 = stack[0];
    {
        popv(2);
        fn = elt(env, 2); /* pasf_premf1 */
        return (*qfn2(fn))(qenv(fn), v0376, v0370);
    }
/* error exit handlers */
v0380:
    popv(2);
    return nil;
}



/* Code for fctrf */

static Lisp_Object CC_fctrf(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0397, v0398, v0399;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for fctrf");
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
    stack[-5] = v0000;
/* end of prologue */
    v0398 = qvalue(elt(env, 1)); /* !*exp */
    v0397 = qvalue(elt(env, 2)); /* ncmp!* */
    stack[-6] = qvalue(elt(env, 1)); /* !*exp */
    qvalue(elt(env, 1)) = v0398; /* !*exp */
    stack[-4] = qvalue(elt(env, 2)); /* ncmp!* */
    qvalue(elt(env, 2)) = v0397; /* ncmp!* */
    stack[-3] = qvalue(elt(env, 3)); /* !*ezgcd */
    qvalue(elt(env, 3)) = nil; /* !*ezgcd */
    stack[-2] = qvalue(elt(env, 4)); /* !*gcd */
    qvalue(elt(env, 4)) = nil; /* !*gcd */
    stack[-1] = nil;
    v0397 = stack[-5];
    if (!consp(v0397)) goto v0376;
    v0397 = stack[-5];
    v0397 = qcar(v0397);
    v0397 = (consp(v0397) ? nil : lisp_true);
    goto v0370;

v0370:
    if (v0397 == nil) goto v0312;
    v0397 = stack[-5];
    v0397 = ncons(v0397);
    nil = C_nil;
    if (exception_pending()) goto v0400;
    env = stack[-7];
    goto v0371;

v0371:
    qvalue(elt(env, 4)) = stack[-2]; /* !*gcd */
    qvalue(elt(env, 3)) = stack[-3]; /* !*ezgcd */
    qvalue(elt(env, 2)) = stack[-4]; /* ncmp!* */
    qvalue(elt(env, 1)) = stack[-6]; /* !*exp */
    { popv(8); return onevalue(v0397); }

v0312:
    v0397 = qvalue(elt(env, 2)); /* ncmp!* */
    if (v0397 == nil) goto v0401;
    v0397 = stack[-5];
    fn = elt(env, 16); /* noncomfp */
    v0397 = (*qfn1(fn))(qenv(fn), v0397);
    nil = C_nil;
    if (exception_pending()) goto v0400;
    env = stack[-7];
    if (!(v0397 == nil)) goto v0401;
    v0397 = qvalue(elt(env, 6)); /* nil */
    qvalue(elt(env, 2)) = v0397; /* ncmp!* */
    goto v0401;

v0401:
    v0397 = qvalue(elt(env, 5)); /* t */
    qvalue(elt(env, 4)) = v0397; /* !*gcd */
    v0397 = qvalue(elt(env, 7)); /* !*limitedfactors */
    if (v0397 == nil) goto v0402;
    v0397 = qvalue(elt(env, 6)); /* nil */
    goto v0257;

v0257:
    if (v0397 == nil) goto v0403;
    v0397 = qvalue(elt(env, 5)); /* t */
    qvalue(elt(env, 3)) = v0397; /* !*ezgcd */
    goto v0403;

v0403:
    v0397 = qvalue(elt(env, 9)); /* !*mcd */
    if (v0397 == nil) goto v0404;
    v0397 = qvalue(elt(env, 1)); /* !*exp */
    if (!(v0397 == nil)) goto v0267;
    v0397 = qvalue(elt(env, 5)); /* t */
    qvalue(elt(env, 1)) = v0397; /* !*exp */
    v0398 = stack[-5];
    v0397 = (Lisp_Object)17; /* 1 */
    v0397 = cons(v0398, v0397);
    nil = C_nil;
    if (exception_pending()) goto v0400;
    env = stack[-7];
    fn = elt(env, 17); /* resimp */
    v0397 = (*qfn1(fn))(qenv(fn), v0397);
    nil = C_nil;
    if (exception_pending()) goto v0400;
    env = stack[-7];
    fn = elt(env, 18); /* !*q2f */
    v0397 = (*qfn1(fn))(qenv(fn), v0397);
    nil = C_nil;
    if (exception_pending()) goto v0400;
    env = stack[-7];
    stack[-5] = v0397;
    goto v0267;

v0267:
    v0398 = qvalue(elt(env, 8)); /* dmode!* */
    v0397 = elt(env, 12); /* !:rn!: */
    if (!(v0398 == v0397)) goto v0405;
    v0397 = qvalue(elt(env, 6)); /* nil */
    qvalue(elt(env, 8)) = v0397; /* dmode!* */
    v0397 = qvalue(elt(env, 6)); /* nil */
    v0397 = ncons(v0397);
    nil = C_nil;
    if (exception_pending()) goto v0400;
    env = stack[-7];
    qvalue(elt(env, 13)) = v0397; /* alglist!* */
    v0397 = stack[-5];
    fn = elt(env, 19); /* prepf */
    v0397 = (*qfn1(fn))(qenv(fn), v0397);
    nil = C_nil;
    if (exception_pending()) goto v0400;
    env = stack[-7];
    fn = elt(env, 20); /* simp */
    v0397 = (*qfn1(fn))(qenv(fn), v0397);
    nil = C_nil;
    if (exception_pending()) goto v0400;
    env = stack[-7];
    stack[0] = v0397;
    v0397 = stack[0];
    v0397 = qcdr(v0397);
    if (!consp(v0397)) goto v0406;
    v0397 = (Lisp_Object)17; /* 1 */
    stack[-1] = v0397;
    goto v0405;

v0405:
    v0397 = qvalue(elt(env, 2)); /* ncmp!* */
    if (!(v0397 == nil)) goto v0407;
    v0397 = stack[-5];
    fn = elt(env, 21); /* sf2ss */
    v0397 = (*qfn1(fn))(qenv(fn), v0397);
    nil = C_nil;
    if (exception_pending()) goto v0400;
    env = stack[-7];
    stack[0] = v0397;
    v0397 = stack[0];
    fn = elt(env, 22); /* homogp */
    v0397 = (*qfn1(fn))(qenv(fn), v0397);
    nil = C_nil;
    if (exception_pending()) goto v0400;
    env = stack[-7];
    if (v0397 == nil) goto v0407;
    v0397 = qvalue(elt(env, 14)); /* !*trfac */
    if (v0397 == nil) goto v0408;
    v0397 = elt(env, 15); /* "This polynomial is homogeneous - variables scaled" 
*/
    fn = elt(env, 23); /* prin2t */
    v0397 = (*qfn1(fn))(qenv(fn), v0397);
    nil = C_nil;
    if (exception_pending()) goto v0400;
    env = stack[-7];
    goto v0408;

v0408:
    v0397 = stack[0];
    v0397 = qcar(v0397);
    v0397 = qcar(v0397);
    stack[-1] = qcar(v0397);
    v0397 = stack[0];
    v0397 = qcdr(v0397);
    v0397 = qcar(v0397);
    v0397 = qcar(v0397);
    v0397 = qcar(v0397);
    fn = elt(env, 24); /* listsum */
    v0397 = (*qfn1(fn))(qenv(fn), v0397);
    nil = C_nil;
    if (exception_pending()) goto v0400;
    env = stack[-7];
    v0397 = cons(stack[-1], v0397);
    nil = C_nil;
    if (exception_pending()) goto v0400;
    env = stack[-7];
    stack[-5] = v0397;
    v0397 = stack[0];
    stack[-1] = qcar(v0397);
    v0397 = stack[0];
    v0397 = qcdr(v0397);
    v0397 = qcar(v0397);
    fn = elt(env, 25); /* subs0 */
    v0397 = (*qfn1(fn))(qenv(fn), v0397);
    nil = C_nil;
    if (exception_pending()) goto v0400;
    env = stack[-7];
    v0398 = Lreverse(nil, v0397);
    nil = C_nil;
    if (exception_pending()) goto v0400;
    env = stack[-7];
    v0397 = (Lisp_Object)17; /* 1 */
    v0397 = list2star(stack[-1], v0398, v0397);
    nil = C_nil;
    if (exception_pending()) goto v0400;
    env = stack[-7];
    fn = elt(env, 26); /* ss2sf */
    v0397 = (*qfn1(fn))(qenv(fn), v0397);
    nil = C_nil;
    if (exception_pending()) goto v0400;
    env = stack[-7];
    fn = elt(env, 27); /* fctrf1 */
    v0397 = (*qfn1(fn))(qenv(fn), v0397);
    nil = C_nil;
    if (exception_pending()) goto v0400;
    env = stack[-7];
    stack[0] = v0397;
    v0398 = stack[-5];
    v0397 = stack[0];
    fn = elt(env, 28); /* rconst */
    v0397 = (*qfn2(fn))(qenv(fn), v0398, v0397);
    nil = C_nil;
    if (exception_pending()) goto v0400;
    env = stack[-7];
    stack[0] = v0397;
    v0397 = stack[0];
    stack[-1] = qcar(v0397);
    v0397 = stack[0];
    v0397 = qcdr(v0397);
    fn = elt(env, 29); /* sort!-factors */
    v0397 = (*qfn1(fn))(qenv(fn), v0397);
    nil = C_nil;
    if (exception_pending()) goto v0400;
    env = stack[-7];
    v0397 = cons(stack[-1], v0397);
    nil = C_nil;
    if (exception_pending()) goto v0400;
    env = stack[-7];
    goto v0371;

v0407:
    v0397 = stack[-5];
    fn = elt(env, 27); /* fctrf1 */
    v0397 = (*qfn1(fn))(qenv(fn), v0397);
    nil = C_nil;
    if (exception_pending()) goto v0400;
    env = stack[-7];
    stack[-5] = v0397;
    v0397 = stack[-1];
    if (v0397 == nil) goto v0409;
    v0397 = qvalue(elt(env, 6)); /* nil */
    v0397 = ncons(v0397);
    nil = C_nil;
    if (exception_pending()) goto v0400;
    env = stack[-7];
    qvalue(elt(env, 13)) = v0397; /* alglist!* */
    v0397 = elt(env, 12); /* !:rn!: */
    qvalue(elt(env, 8)) = v0397; /* dmode!* */
    stack[0] = stack[-5];
    v0397 = stack[-5];
    v0398 = qcar(v0397);
    v0397 = stack[-1];
    fn = elt(env, 30); /* quotf!* */
    v0397 = (*qfn2(fn))(qenv(fn), v0398, v0397);
    nil = C_nil;
    if (exception_pending()) goto v0400;
    env = stack[-7];
    fn = elt(env, 31); /* setcar */
    v0397 = (*qfn2(fn))(qenv(fn), stack[0], v0397);
    nil = C_nil;
    if (exception_pending()) goto v0400;
    env = stack[-7];
    goto v0409;

v0409:
    v0397 = stack[-5];
    stack[0] = qcar(v0397);
    v0397 = stack[-5];
    v0397 = qcdr(v0397);
    fn = elt(env, 29); /* sort!-factors */
    v0397 = (*qfn1(fn))(qenv(fn), v0397);
    nil = C_nil;
    if (exception_pending()) goto v0400;
    env = stack[-7];
    v0397 = cons(stack[0], v0397);
    nil = C_nil;
    if (exception_pending()) goto v0400;
    env = stack[-7];
    goto v0371;

v0406:
    v0397 = stack[0];
    v0397 = qcdr(v0397);
    stack[-1] = v0397;
    v0397 = stack[0];
    v0397 = qcar(v0397);
    stack[-5] = v0397;
    goto v0405;

v0404:
    v0399 = elt(env, 10); /* poly */
    v0398 = (Lisp_Object)241; /* 15 */
    v0397 = elt(env, 11); /* "Factorization invalid with MCD off" */
    fn = elt(env, 32); /* rerror */
    v0397 = (*qfnn(fn))(qenv(fn), 3, v0399, v0398, v0397);
    nil = C_nil;
    if (exception_pending()) goto v0400;
    env = stack[-7];
    goto v0267;

v0402:
    v0397 = qvalue(elt(env, 8)); /* dmode!* */
    v0397 = (v0397 == nil ? lisp_true : nil);
    goto v0257;

v0376:
    v0397 = qvalue(elt(env, 5)); /* t */
    goto v0370;
/* error exit handlers */
v0400:
    env = stack[-7];
    qvalue(elt(env, 4)) = stack[-2]; /* !*gcd */
    qvalue(elt(env, 3)) = stack[-3]; /* !*ezgcd */
    qvalue(elt(env, 2)) = stack[-4]; /* ncmp!* */
    qvalue(elt(env, 1)) = stack[-6]; /* !*exp */
    popv(8);
    return nil;
}



/* Code for vsl_boundtype1 */

static Lisp_Object CC_vsl_boundtype1(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0271, v0411, v0412, v0413;
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
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v0413 = v0001;
    v0412 = v0000;
/* end of prologue */

v0018:
    v0271 = v0412;
    if (!consp(v0271)) goto v0371;
    v0271 = v0412;
    v0271 = qcar(v0271);
    v0271 = (consp(v0271) ? nil : lisp_true);
    goto v0381;

v0381:
    if (v0271 == nil) goto v0414;
    v0271 = qvalue(elt(env, 2)); /* nil */
    { popv(1); return onevalue(v0271); }

v0414:
    v0271 = v0412;
    v0271 = qcar(v0271);
    v0271 = qcar(v0271);
    v0411 = qcar(v0271);
    v0271 = v0413;
    if (v0411 == v0271) goto v0415;
    v0271 = v0412;
    v0271 = qcdr(v0271);
    v0412 = v0271;
    goto v0018;

v0415:
    v0271 = v0412;
    v0271 = qcar(v0271);
    v0271 = qcdr(v0271);
    fn = elt(env, 5); /* minusf */
    v0271 = (*qfn1(fn))(qenv(fn), v0271);
    nil = C_nil;
    if (exception_pending()) goto v0416;
    env = stack[0];
    if (v0271 == nil) goto v0396;
    v0271 = elt(env, 3); /* ub */
    { popv(1); return onevalue(v0271); }

v0396:
    v0271 = elt(env, 4); /* lb */
    { popv(1); return onevalue(v0271); }

v0371:
    v0271 = qvalue(elt(env, 1)); /* t */
    goto v0381;
/* error exit handlers */
v0416:
    popv(1);
    return nil;
}



/* Code for gcdld */

static Lisp_Object CC_gcdld(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0272, v0404, v0420, v0421;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for gcdld");
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
    v0404 = v0001;
    v0420 = v0000;
/* end of prologue */

v0379:
    v0421 = v0404;
    v0272 = (Lisp_Object)17; /* 1 */
    if (v0421 == v0272) goto v0372;
    v0421 = v0404;
    v0272 = (Lisp_Object)-15; /* -1 */
    v0272 = (v0421 == v0272 ? lisp_true : nil);
    goto v0371;

v0371:
    if (v0272 == nil) goto v0388;
    v0272 = (Lisp_Object)17; /* 1 */
    { popv(2); return onevalue(v0272); }

v0388:
    v0272 = v0420;
    if (v0272 == nil) goto v0278;
    v0272 = v0420;
    v0272 = qcar(v0272);
    if (v0272 == nil) goto v0374;
    v0272 = v0420;
    v0272 = qcdr(v0272);
    stack[0] = v0272;
    v0272 = v0404;
    v0404 = v0420;
    v0404 = qcar(v0404);
    fn = elt(env, 2); /* gcd!-with!-number */
    v0272 = (*qfn2(fn))(qenv(fn), v0272, v0404);
    nil = C_nil;
    if (exception_pending()) goto v0422;
    env = stack[-1];
    v0404 = v0272;
    v0272 = stack[0];
    v0420 = v0272;
    goto v0379;

v0374:
    v0272 = v0420;
    v0272 = qcdr(v0272);
    v0420 = v0272;
    goto v0379;

v0278:
    v0272 = v0404;
        popv(2);
        return Labsval(nil, v0272);

v0372:
    v0272 = qvalue(elt(env, 1)); /* t */
    goto v0371;
/* error exit handlers */
v0422:
    popv(2);
    return nil;
}



/* Code for diford */

static Lisp_Object CC_diford(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0010;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for diford");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0010 = v0000;
/* end of prologue */
    v0010 = qcdr(v0010);
    v0010 = qcdr(v0010);
    {
        fn = elt(env, 1); /* lengthn */
        return (*qfn1(fn))(qenv(fn), v0010);
    }
}



/* Code for copy_vect */

static Lisp_Object CC_copy_vect(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0427, v0271, v0411, v0412;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for copy_vect");
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
    v0427 = stack[-1];
    v0427 = Lupbv(nil, v0427);
    nil = C_nil;
    if (exception_pending()) goto v0275;
    env = stack[-4];
    stack[-3] = v0427;
    v0427 = (Lisp_Object)1; /* 0 */
    stack[0] = v0427;
    goto v0415;

v0415:
    v0271 = stack[-3];
    v0427 = stack[0];
    v0427 = difference2(v0271, v0427);
    nil = C_nil;
    if (exception_pending()) goto v0275;
    env = stack[-4];
    v0427 = Lminusp(nil, v0427);
    env = stack[-4];
    if (v0427 == nil) goto v0418;
    v0427 = nil;
    { popv(5); return onevalue(v0427); }

v0418:
    v0412 = stack[-2];
    v0411 = stack[0];
    v0271 = stack[-1];
    v0427 = stack[0];
    v0427 = *(Lisp_Object *)((char *)v0271 + (CELL-TAG_VECTOR) + ((int32_t)v0427/(16/CELL)));
    *(Lisp_Object *)((char *)v0412 + (CELL-TAG_VECTOR) + ((int32_t)v0411/(16/CELL))) = v0427;
    v0427 = stack[0];
    v0427 = add1(v0427);
    nil = C_nil;
    if (exception_pending()) goto v0275;
    env = stack[-4];
    stack[0] = v0427;
    goto v0415;
/* error exit handlers */
v0275:
    popv(5);
    return nil;
}



/* Code for vdpcleanup */

static Lisp_Object MS_CDECL CC_vdpcleanup(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0197;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "vdpcleanup");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for vdpcleanup");
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
    v0197 = qvalue(elt(env, 1)); /* nil */
    v0197 = ncons(v0197);
    nil = C_nil;
    if (exception_pending()) goto v0004;
    env = stack[0];
    qvalue(elt(env, 2)) = v0197; /* dipevlist!* */
    { popv(1); return onevalue(v0197); }
/* error exit handlers */
v0004:
    popv(1);
    return nil;
}



/* Code for simpwedge */

static Lisp_Object CC_simpwedge(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0018;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for simpwedge");
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
    fn = elt(env, 1); /* partitwedge */
    v0018 = (*qfn1(fn))(qenv(fn), v0018);
    nil = C_nil;
    if (exception_pending()) goto v0010;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* !*pf2sq */
        return (*qfn1(fn))(qenv(fn), v0018);
    }
/* error exit handlers */
v0010:
    popv(1);
    return nil;
}



/* Code for evalmember */

static Lisp_Object CC_evalmember(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0371, v0372;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for evalmember");
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
    push(nil);
/* copy arguments values to proper place */
    v0371 = v0001;
    v0372 = v0000;
/* end of prologue */
    stack[0] = v0372;
    fn = elt(env, 1); /* getrlist */
    v0371 = (*qfn1(fn))(qenv(fn), v0371);
    nil = C_nil;
    if (exception_pending()) goto v0379;
    v0371 = Lmember(nil, stack[0], v0371);
    { popv(1); return onevalue(v0371); }
/* error exit handlers */
v0379:
    popv(1);
    return nil;
}



/* Code for coeff_calc */

static Lisp_Object MS_CDECL CC_coeff_calc(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0429, v0414, v0430;
    Lisp_Object fn;
    Lisp_Object v0428, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "coeff_calc");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0001 = va_arg(aa, Lisp_Object);
    v0428 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for coeff_calc");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0428,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0428);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0429 = v0428;
    v0414 = v0001;
    v0430 = v0000;
/* end of prologue */
    stack[0] = elt(env, 1); /* plus */
    fn = elt(env, 2); /* coeff1_calc */
    v0429 = (*qfnn(fn))(qenv(fn), 3, v0430, v0414, v0429);
    nil = C_nil;
    if (exception_pending()) goto v0425;
    env = stack[-1];
    v0429 = cons(stack[0], v0429);
    nil = C_nil;
    if (exception_pending()) goto v0425;
    env = stack[-1];
    {
        popv(2);
        fn = elt(env, 3); /* reval */
        return (*qfn1(fn))(qenv(fn), v0429);
    }
/* error exit handlers */
v0425:
    popv(2);
    return nil;
}



/* Code for lesspcar */

static Lisp_Object CC_lesspcar(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0372, v0401;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for lesspcar");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0372 = v0001;
    v0401 = v0000;
/* end of prologue */
    v0401 = qcar(v0401);
    v0372 = qcar(v0372);
        return Llessp(nil, v0401, v0372);
}



/* Code for mkrootsq */

static Lisp_Object CC_mkrootsq(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0454, v0455, v0400;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mkrootsq");
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
    v0455 = stack[-1];
    v0454 = (Lisp_Object)17; /* 1 */
    if (v0455 == v0454) goto v0018;
    v0455 = stack[0];
    v0454 = (Lisp_Object)33; /* 2 */
    if (v0455 == v0454) goto v0277;
    v0454 = qvalue(elt(env, 3)); /* nil */
    goto v0376;

v0376:
    if (v0454 == nil) goto v0456;
    v0454 = elt(env, 4); /* i */
    {
        popv(4);
        fn = elt(env, 10); /* simp */
        return (*qfn1(fn))(qenv(fn), v0454);
    }

v0456:
    v0455 = stack[-1];
    v0454 = elt(env, 5); /* expt */
    if (!consp(v0455)) goto v0457;
    v0455 = qcar(v0455);
    if (!(v0455 == v0454)) goto v0457;
    v0454 = stack[-1];
    v0454 = qcdr(v0454);
    v0454 = qcdr(v0454);
    v0454 = qcar(v0454);
    v0454 = integerp(v0454);
    if (v0454 == nil) goto v0458;
    v0454 = qvalue(elt(env, 6)); /* !*precise_complex */
    v0454 = (v0454 == nil ? lisp_true : nil);
    goto v0272;

v0272:
    if (v0454 == nil) goto v0459;
    v0454 = stack[-1];
    v0454 = qcdr(v0454);
    v0455 = qcar(v0454);
    v0454 = stack[0];
    v0455 = CC_mkrootsq(env, v0455, v0454);
    nil = C_nil;
    if (exception_pending()) goto v0234;
    env = stack[-3];
    v0454 = stack[-1];
    v0454 = qcdr(v0454);
    v0454 = qcdr(v0454);
    v0454 = qcar(v0454);
    {
        popv(4);
        fn = elt(env, 11); /* exptsq */
        return (*qfn2(fn))(qenv(fn), v0455, v0454);
    }

v0459:
    stack[-2] = nil;
    v0454 = stack[-1];
    v0454 = integerp(v0454);
    if (v0454 == nil) goto v0245;
    v0454 = stack[-1];
    v0454 = Lminusp(nil, v0454);
    env = stack[-3];
    if (v0454 == nil) goto v0460;
    v0454 = qvalue(elt(env, 3)); /* nil */
    goto v0461;

v0461:
    if (v0454 == nil) goto v0245;
    v0455 = stack[-2];
    v0454 = stack[0];
    {
        popv(4);
        fn = elt(env, 12); /* mkrootsql */
        return (*qfn2(fn))(qenv(fn), v0455, v0454);
    }

v0245:
    v0455 = stack[0];
    v0454 = (Lisp_Object)33; /* 2 */
    if (v0455 == v0454) goto v0462;
    stack[-2] = elt(env, 5); /* expt */
    v0400 = elt(env, 9); /* quotient */
    v0455 = (Lisp_Object)17; /* 1 */
    v0454 = stack[0];
    v0454 = list3(v0400, v0455, v0454);
    nil = C_nil;
    if (exception_pending()) goto v0234;
    env = stack[-3];
    v0454 = list3(stack[-2], stack[-1], v0454);
    nil = C_nil;
    if (exception_pending()) goto v0234;
    env = stack[-3];
    goto v0463;

v0463:
    stack[-2] = v0454;
    v0454 = stack[-2];
    fn = elt(env, 13); /* opmtch */
    v0454 = (*qfn1(fn))(qenv(fn), v0454);
    nil = C_nil;
    if (exception_pending()) goto v0234;
    env = stack[-3];
    v0455 = v0454;
    if (v0454 == nil) goto v0398;
    v0454 = v0455;
    {
        popv(4);
        fn = elt(env, 10); /* simp */
        return (*qfn1(fn))(qenv(fn), v0454);
    }

v0398:
    v0455 = stack[-2];
    v0454 = (Lisp_Object)17; /* 1 */
    {
        popv(4);
        fn = elt(env, 14); /* mksq */
        return (*qfn2(fn))(qenv(fn), v0455, v0454);
    }

v0462:
    v0454 = stack[-1];
    fn = elt(env, 15); /* mksqrt */
    v0454 = (*qfn1(fn))(qenv(fn), v0454);
    nil = C_nil;
    if (exception_pending()) goto v0234;
    env = stack[-3];
    goto v0463;

v0460:
    stack[-2] = stack[-1];
    v0455 = stack[-1];
    v0454 = qvalue(elt(env, 7)); /* factorbound!* */
    v0454 = (Lisp_Object)lessp2(v0455, v0454);
    nil = C_nil;
    if (exception_pending()) goto v0234;
    v0454 = v0454 ? lisp_true : nil;
    env = stack[-3];
    if (!(v0454 == nil)) goto v0464;
    v0454 = qvalue(elt(env, 8)); /* !*ifactor */
    goto v0464;

v0464:
    fn = elt(env, 16); /* zfactor1 */
    v0454 = (*qfn2(fn))(qenv(fn), stack[-2], v0454);
    nil = C_nil;
    if (exception_pending()) goto v0234;
    env = stack[-3];
    stack[-2] = v0454;
    v0455 = Llength(nil, v0454);
    nil = C_nil;
    if (exception_pending()) goto v0234;
    env = stack[-3];
    v0454 = (Lisp_Object)17; /* 1 */
    v0454 = (Lisp_Object)greaterp2(v0455, v0454);
    nil = C_nil;
    if (exception_pending()) goto v0234;
    v0454 = v0454 ? lisp_true : nil;
    env = stack[-3];
    if (!(v0454 == nil)) goto v0461;
    v0454 = stack[-2];
    v0454 = qcar(v0454);
    v0455 = qcdr(v0454);
    v0454 = (Lisp_Object)17; /* 1 */
    v0454 = (Lisp_Object)greaterp2(v0455, v0454);
    nil = C_nil;
    if (exception_pending()) goto v0234;
    v0454 = v0454 ? lisp_true : nil;
    env = stack[-3];
    goto v0461;

v0458:
    v0454 = qvalue(elt(env, 3)); /* nil */
    goto v0272;

v0457:
    v0454 = qvalue(elt(env, 3)); /* nil */
    goto v0272;

v0277:
    v0455 = stack[-1];
    v0454 = (Lisp_Object)-15; /* -1 */
    if (v0455 == v0454) goto v0419;
    v0455 = stack[-1];
    v0454 = elt(env, 2); /* (minus 1) */
    v0454 = (equal(v0455, v0454) ? lisp_true : nil);
    goto v0376;

v0419:
    v0454 = qvalue(elt(env, 1)); /* t */
    goto v0376;

v0018:
    v0454 = (Lisp_Object)17; /* 1 */
    {
        popv(4);
        fn = elt(env, 17); /* !*d2q */
        return (*qfn1(fn))(qenv(fn), v0454);
    }
/* error exit handlers */
v0234:
    popv(4);
    return nil;
}



/* Code for subtractinds */

static Lisp_Object MS_CDECL CC_subtractinds(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0456, v0422;
    Lisp_Object v0428, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "subtractinds");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0001 = va_arg(aa, Lisp_Object);
    v0428 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for subtractinds");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0428,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0428);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0428;
    stack[-2] = v0001;
    stack[-3] = v0000;
/* end of prologue */

v0077:
    v0456 = stack[-2];
    if (v0456 == nil) goto v0381;
    v0456 = stack[-3];
    v0422 = qcar(v0456);
    v0456 = stack[-2];
    v0456 = qcar(v0456);
    v0456 = qcar(v0456);
    v0422 = difference2(v0422, v0456);
    nil = C_nil;
    if (exception_pending()) goto v0451;
    env = stack[-5];
    v0456 = (Lisp_Object)1; /* 0 */
    v0456 = (Lisp_Object)lessp2(v0422, v0456);
    nil = C_nil;
    if (exception_pending()) goto v0451;
    v0456 = v0456 ? lisp_true : nil;
    env = stack[-5];
    if (v0456 == nil) goto v0423;
    v0456 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v0456); }

v0423:
    v0456 = stack[-3];
    v0456 = qcdr(v0456);
    stack[-4] = v0456;
    v0456 = stack[-2];
    v0456 = qcdr(v0456);
    stack[0] = v0456;
    v0456 = stack[-3];
    v0422 = qcar(v0456);
    v0456 = stack[-2];
    v0456 = qcar(v0456);
    v0456 = qcar(v0456);
    v0422 = difference2(v0422, v0456);
    nil = C_nil;
    if (exception_pending()) goto v0451;
    env = stack[-5];
    v0456 = stack[-1];
    v0456 = cons(v0422, v0456);
    nil = C_nil;
    if (exception_pending()) goto v0451;
    env = stack[-5];
    stack[-1] = v0456;
    v0456 = stack[0];
    stack[-2] = v0456;
    v0456 = stack[-4];
    stack[-3] = v0456;
    goto v0077;

v0381:
    v0456 = stack[-1];
        popv(6);
        return Lnreverse(nil, v0456);
/* error exit handlers */
v0451:
    popv(6);
    return nil;
}



/* Code for qqe_simplqneq */

static Lisp_Object CC_qqe_simplqneq(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0468, v0259, v0469;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for qqe_simplqneq");
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
    v0259 = v0001;
    v0468 = v0000;
/* end of prologue */
    v0259 = v0468;
    v0259 = qcdr(v0259);
    v0259 = qcar(v0259);
    v0468 = qcdr(v0468);
    v0468 = qcdr(v0468);
    v0468 = qcar(v0468);
    v0469 = elt(env, 1); /* qequal */
    fn = elt(env, 6); /* qqe_mk2 */
    v0259 = (*qfnn(fn))(qenv(fn), 3, v0469, v0259, v0468);
    nil = C_nil;
    if (exception_pending()) goto v0470;
    env = stack[-3];
    v0468 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 7); /* qqe_simplqequal */
    v0468 = (*qfn2(fn))(qenv(fn), v0259, v0468);
    nil = C_nil;
    if (exception_pending()) goto v0470;
    env = stack[-3];
    stack[-2] = v0468;
    v0259 = stack[-2];
    v0468 = elt(env, 3); /* true */
    if (v0259 == v0468) goto v0373;
    v0259 = stack[-2];
    v0468 = elt(env, 4); /* false */
    if (v0259 == v0468) goto v0453;
    stack[-1] = elt(env, 5); /* qneq */
    v0468 = stack[-2];
    fn = elt(env, 8); /* qqe_arg2l */
    stack[0] = (*qfn1(fn))(qenv(fn), v0468);
    nil = C_nil;
    if (exception_pending()) goto v0470;
    env = stack[-3];
    v0468 = stack[-2];
    fn = elt(env, 9); /* qqe_arg2r */
    v0468 = (*qfn1(fn))(qenv(fn), v0468);
    nil = C_nil;
    if (exception_pending()) goto v0470;
    env = stack[-3];
    fn = elt(env, 6); /* qqe_mk2 */
    v0468 = (*qfnn(fn))(qenv(fn), 3, stack[-1], stack[0], v0468);
    nil = C_nil;
    if (exception_pending()) goto v0470;
    { popv(4); return onevalue(v0468); }

v0453:
    v0468 = elt(env, 3); /* true */
    { popv(4); return onevalue(v0468); }

v0373:
    v0468 = elt(env, 4); /* false */
    { popv(4); return onevalue(v0468); }
/* error exit handlers */
v0470:
    popv(4);
    return nil;
}



/* Code for pasf_sacat */

static Lisp_Object MS_CDECL CC_pasf_sacat(Lisp_Object env, int nargs, ...)
{
    Lisp_Object v0018, v0010, v0071;
    Lisp_Object v0428, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "pasf_sacat");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0001 = va_arg(aa, Lisp_Object);
    v0428 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pasf_sacat");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0018 = v0428;
    v0010 = v0001;
    v0071 = v0000;
/* end of prologue */
    v0018 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v0018);
}



/* Code for sfto_qsubhor1 */

static Lisp_Object MS_CDECL CC_sfto_qsubhor1(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0476, v0477;
    Lisp_Object fn;
    Lisp_Object v0428, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "sfto_qsubhor1");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0001 = va_arg(aa, Lisp_Object);
    v0428 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sfto_qsubhor1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0428,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0428);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-1] = v0428;
    v0476 = v0001;
    stack[0] = v0000;
/* end of prologue */
    v0477 = stack[0];
    fn = elt(env, 2); /* sfto_mvartest */
    v0476 = (*qfn2(fn))(qenv(fn), v0477, v0476);
    nil = C_nil;
    if (exception_pending()) goto v0459;
    env = stack[-6];
    if (v0476 == nil) goto v0425;
    v0476 = stack[-1];
    v0476 = qcar(v0476);
    stack[-4] = v0476;
    v0476 = stack[-1];
    v0476 = qcdr(v0476);
    stack[-3] = v0476;
    v0476 = (Lisp_Object)17; /* 1 */
    stack[-2] = v0476;
    v0476 = stack[0];
    fn = elt(env, 3); /* coeffs */
    v0476 = (*qfn1(fn))(qenv(fn), v0476);
    nil = C_nil;
    if (exception_pending()) goto v0459;
    env = stack[-6];
    v0477 = v0476;
    v0476 = v0477;
    v0476 = qcar(v0476);
    stack[-5] = v0476;
    v0476 = v0477;
    v0476 = qcdr(v0476);
    stack[-1] = v0476;
    goto v0424;

v0424:
    v0476 = stack[-1];
    if (v0476 == nil) goto v0478;
    v0476 = stack[-1];
    v0476 = qcar(v0476);
    stack[0] = v0476;
    v0477 = stack[-2];
    v0476 = stack[-3];
    v0476 = times2(v0477, v0476);
    nil = C_nil;
    if (exception_pending()) goto v0459;
    env = stack[-6];
    stack[-2] = v0476;
    v0477 = stack[0];
    v0476 = stack[-2];
    fn = elt(env, 4); /* multf */
    stack[0] = (*qfn2(fn))(qenv(fn), v0477, v0476);
    nil = C_nil;
    if (exception_pending()) goto v0459;
    env = stack[-6];
    v0477 = stack[-5];
    v0476 = stack[-4];
    fn = elt(env, 4); /* multf */
    v0476 = (*qfn2(fn))(qenv(fn), v0477, v0476);
    nil = C_nil;
    if (exception_pending()) goto v0459;
    env = stack[-6];
    fn = elt(env, 5); /* addf */
    v0476 = (*qfn2(fn))(qenv(fn), stack[0], v0476);
    nil = C_nil;
    if (exception_pending()) goto v0459;
    env = stack[-6];
    stack[-5] = v0476;
    v0476 = stack[-1];
    v0476 = qcdr(v0476);
    stack[-1] = v0476;
    goto v0424;

v0478:
    v0476 = stack[-5];
    fn = elt(env, 6); /* sfto_dprpartksf */
    v0477 = (*qfn1(fn))(qenv(fn), v0476);
    nil = C_nil;
    if (exception_pending()) goto v0459;
    v0476 = (Lisp_Object)17; /* 1 */
    popv(7);
    return cons(v0477, v0476);

v0425:
    v0477 = stack[0];
    v0476 = (Lisp_Object)17; /* 1 */
    popv(7);
    return cons(v0477, v0476);
/* error exit handlers */
v0459:
    popv(7);
    return nil;
}



/* Code for ps!:times!-erule */

static Lisp_Object CC_psTtimesKerule(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0485, v0460;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ps:times-erule");
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
/* copy arguments values to proper place */
    stack[-8] = v0001;
    v0460 = v0000;
/* end of prologue */
    v0485 = v0460;
    v0485 = qcdr(v0485);
    v0485 = qcar(v0485);
    stack[-9] = v0485;
    v0485 = v0460;
    v0485 = qcdr(v0485);
    v0485 = qcdr(v0485);
    v0485 = qcar(v0485);
    stack[-7] = v0485;
    v0460 = qvalue(elt(env, 1)); /* nil */
    v0485 = (Lisp_Object)17; /* 1 */
    v0485 = cons(v0460, v0485);
    nil = C_nil;
    if (exception_pending()) goto v0486;
    env = stack[-10];
    stack[0] = v0485;
    v0485 = stack[-9];
    fn = elt(env, 3); /* ps!:order */
    v0485 = (*qfn1(fn))(qenv(fn), v0485);
    nil = C_nil;
    if (exception_pending()) goto v0486;
    env = stack[-10];
    stack[-6] = v0485;
    v0485 = qvalue(elt(env, 2)); /* ps */
    fn = elt(env, 3); /* ps!:order */
    v0485 = (*qfn1(fn))(qenv(fn), v0485);
    nil = C_nil;
    if (exception_pending()) goto v0486;
    env = stack[-10];
    stack[-5] = v0485;
    v0485 = stack[-7];
    fn = elt(env, 3); /* ps!:order */
    v0485 = (*qfn1(fn))(qenv(fn), v0485);
    nil = C_nil;
    if (exception_pending()) goto v0486;
    env = stack[-10];
    stack[-4] = v0485;
    v0485 = (Lisp_Object)1; /* 0 */
    stack[-3] = v0485;
    goto v0427;

v0427:
    v0460 = stack[-8];
    v0485 = stack[-5];
    v0460 = difference2(v0460, v0485);
    nil = C_nil;
    if (exception_pending()) goto v0486;
    env = stack[-10];
    v0485 = stack[-3];
    v0485 = difference2(v0460, v0485);
    nil = C_nil;
    if (exception_pending()) goto v0486;
    env = stack[-10];
    v0485 = Lminusp(nil, v0485);
    env = stack[-10];
    if (!(v0485 == nil)) { Lisp_Object res = stack[0]; popv(11); return onevalue(res); }
    v0460 = stack[-8];
    v0485 = stack[-6];
    v0460 = difference2(v0460, v0485);
    nil = C_nil;
    if (exception_pending()) goto v0486;
    env = stack[-10];
    v0485 = stack[-3];
    v0460 = difference2(v0460, v0485);
    nil = C_nil;
    if (exception_pending()) goto v0486;
    env = stack[-10];
    v0485 = stack[-4];
    v0485 = (Lisp_Object)geq2(v0460, v0485);
    nil = C_nil;
    if (exception_pending()) goto v0486;
    v0485 = v0485 ? lisp_true : nil;
    env = stack[-10];
    if (v0485 == nil) goto v0272;
    stack[-2] = stack[0];
    stack[0] = stack[-9];
    v0460 = stack[-3];
    v0485 = stack[-6];
    v0485 = plus2(v0460, v0485);
    nil = C_nil;
    if (exception_pending()) goto v0486;
    env = stack[-10];
    fn = elt(env, 4); /* ps!:evaluate */
    stack[-1] = (*qfn2(fn))(qenv(fn), stack[0], v0485);
    nil = C_nil;
    if (exception_pending()) goto v0486;
    env = stack[-10];
    stack[0] = stack[-7];
    v0460 = stack[-8];
    v0485 = stack[-6];
    v0460 = difference2(v0460, v0485);
    nil = C_nil;
    if (exception_pending()) goto v0486;
    env = stack[-10];
    v0485 = stack[-3];
    v0485 = difference2(v0460, v0485);
    nil = C_nil;
    if (exception_pending()) goto v0486;
    env = stack[-10];
    fn = elt(env, 4); /* ps!:evaluate */
    v0485 = (*qfn2(fn))(qenv(fn), stack[0], v0485);
    nil = C_nil;
    if (exception_pending()) goto v0486;
    env = stack[-10];
    fn = elt(env, 5); /* multsq */
    v0485 = (*qfn2(fn))(qenv(fn), stack[-1], v0485);
    nil = C_nil;
    if (exception_pending()) goto v0486;
    env = stack[-10];
    fn = elt(env, 6); /* addsq */
    v0485 = (*qfn2(fn))(qenv(fn), stack[-2], v0485);
    nil = C_nil;
    if (exception_pending()) goto v0486;
    env = stack[-10];
    stack[0] = v0485;
    goto v0272;

v0272:
    v0485 = stack[-3];
    v0485 = add1(v0485);
    nil = C_nil;
    if (exception_pending()) goto v0486;
    env = stack[-10];
    stack[-3] = v0485;
    goto v0427;
/* error exit handlers */
v0486:
    popv(11);
    return nil;
}



/* Code for dipretimes */

static Lisp_Object CC_dipretimes(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0257, v0402, v0424;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dipretimes");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0402 = v0000;
/* end of prologue */

v0377:
    v0257 = v0402;
    v0424 = qcar(v0257);
    v0257 = (Lisp_Object)17; /* 1 */
    if (v0424 == v0257) goto v0071;
    v0257 = v0402;
    v0257 = qcdr(v0257);
    if (v0257 == nil) goto v0426;
    v0257 = elt(env, 1); /* times */
    return cons(v0257, v0402);

v0426:
    v0257 = v0402;
    v0257 = qcar(v0257);
    return onevalue(v0257);

v0071:
    v0257 = v0402;
    v0257 = qcdr(v0257);
    if (v0257 == nil) goto v0430;
    v0257 = v0402;
    v0257 = qcdr(v0257);
    v0402 = v0257;
    goto v0377;

v0430:
    v0257 = (Lisp_Object)17; /* 1 */
    return onevalue(v0257);
}



/* Code for remove_least_item */

static Lisp_Object CC_remove_least_item(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0488, v0425;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for remove_least_item");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0488 = v0000;
/* end of prologue */

v0004:
    v0425 = v0488;
    v0425 = qcdr(v0425);
    if (v0425 == nil) goto v0071;
    v0425 = v0488;
    v0425 = qcdr(v0425);
    v0425 = qcar(v0425);
    v0425 = qcdr(v0425);
    if (v0425 == nil) goto v0372;
    v0488 = qcdr(v0488);
    v0488 = qcar(v0488);
    goto v0004;

v0372:
    {
        fn = elt(env, 2); /* remove_root_item */
        return (*qfn1(fn))(qenv(fn), v0488);
    }

v0071:
    v0488 = elt(env, 1); /* "How did we get here?" */
    {
        fn = elt(env, 3); /* rederr */
        return (*qfn1(fn))(qenv(fn), v0488);
    }
}



/* Code for gfstorval */

static Lisp_Object CC_gfstorval(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0401, v0379, v0312;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for gfstorval");
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
/* copy arguments values to proper place */
    v0401 = v0001;
    v0379 = v0000;
/* end of prologue */
    v0312 = v0379;
    v0379 = v0401;
    v0401 = qvalue(elt(env, 1)); /* !*xnlist */
    v0401 = acons(v0312, v0379, v0401);
    nil = C_nil;
    if (exception_pending()) goto v0378;
    env = stack[0];
    qvalue(elt(env, 1)) = v0401; /* !*xnlist */
    { popv(1); return onevalue(v0401); }
/* error exit handlers */
v0378:
    popv(1);
    return nil;
}



/* Code for mkdmoderr */

static Lisp_Object CC_mkdmoderr(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0488;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mkdmoderr");
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
    v0488 = v0000;
/* end of prologue */
    stack[-4] = elt(env, 1); /* lambda */
    stack[-2] = elt(env, 2); /* (!*x!*) */
    stack[-1] = elt(env, 3); /* dmoderr */
    stack[0] = Lmkquote(nil, v0488);
    nil = C_nil;
    if (exception_pending()) goto v0410;
    env = stack[-5];
    v0488 = stack[-3];
    v0488 = Lmkquote(nil, v0488);
    nil = C_nil;
    if (exception_pending()) goto v0410;
    env = stack[-5];
    v0488 = list3(stack[-1], stack[0], v0488);
    nil = C_nil;
    if (exception_pending()) goto v0410;
    {
        Lisp_Object v0277 = stack[-4];
        Lisp_Object v0278 = stack[-2];
        popv(6);
        return list3(v0277, v0278, v0488);
    }
/* error exit handlers */
v0410:
    popv(6);
    return nil;
}



/* Code for adjp */

static Lisp_Object CC_adjp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0477, v0449;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for adjp");
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
    v0449 = stack[-1];
    v0477 = elt(env, 1); /* unit */
    if (v0449 == v0477) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v0477 = stack[-1];
    if (!consp(v0477)) goto v0370;
    v0477 = stack[-1];
    v0449 = qcar(v0477);
    v0477 = elt(env, 3); /* comm */
    if (v0449 == v0477) goto v0490;
    v0477 = stack[-1];
    v0449 = qcar(v0477);
    v0477 = elt(env, 4); /* anticomm */
    if (v0449 == v0477) goto v0422;
    v0477 = stack[-1];
    v0449 = qcar(v0477);
    v0477 = elt(env, 2); /* adjoint */
    v0449 = get(v0449, v0477);
    v0477 = stack[-1];
    v0477 = qcdr(v0477);
    popv(4);
    return cons(v0449, v0477);

v0422:
    stack[-2] = elt(env, 4); /* anticomm */
    v0477 = stack[-1];
    v0477 = qcdr(v0477);
    v0477 = qcar(v0477);
    stack[0] = CC_adjp(env, v0477);
    nil = C_nil;
    if (exception_pending()) goto v0491;
    env = stack[-3];
    v0477 = stack[-1];
    v0477 = qcdr(v0477);
    v0477 = qcdr(v0477);
    v0477 = qcar(v0477);
    v0477 = CC_adjp(env, v0477);
    nil = C_nil;
    if (exception_pending()) goto v0491;
    {
        Lisp_Object v0448 = stack[-2];
        Lisp_Object v0459 = stack[0];
        popv(4);
        return list3(v0448, v0459, v0477);
    }

v0490:
    stack[-2] = elt(env, 3); /* comm */
    v0477 = stack[-1];
    v0477 = qcdr(v0477);
    v0477 = qcdr(v0477);
    v0477 = qcar(v0477);
    stack[0] = CC_adjp(env, v0477);
    nil = C_nil;
    if (exception_pending()) goto v0491;
    env = stack[-3];
    v0477 = stack[-1];
    v0477 = qcdr(v0477);
    v0477 = qcar(v0477);
    v0477 = CC_adjp(env, v0477);
    nil = C_nil;
    if (exception_pending()) goto v0491;
    {
        Lisp_Object v0492 = stack[-2];
        Lisp_Object v0432 = stack[0];
        popv(4);
        return list3(v0492, v0432, v0477);
    }

v0370:
    v0477 = stack[-1];
    v0449 = elt(env, 2); /* adjoint */
    popv(4);
    return get(v0477, v0449);
/* error exit handlers */
v0491:
    popv(4);
    return nil;
}



/* Code for is_buble */

static Lisp_Object CC_is_buble(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0493, v0453;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for is_buble");
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
    v0453 = stack[-1];
    v0493 = stack[0];
    fn = elt(env, 2); /* diff_vertex */
    v0493 = (*qfn2(fn))(qenv(fn), v0453, v0493);
    nil = C_nil;
    if (exception_pending()) goto v0412;
    env = stack[-3];
    v0493 = Llength(nil, v0493);
    nil = C_nil;
    if (exception_pending()) goto v0412;
    env = stack[-3];
    stack[-2] = v0493;
    v0453 = stack[-2];
    v0493 = (Lisp_Object)33; /* 2 */
    v0493 = (Lisp_Object)geq2(v0453, v0493);
    nil = C_nil;
    if (exception_pending()) goto v0412;
    v0493 = v0493 ? lisp_true : nil;
    env = stack[-3];
    if (v0493 == nil) goto v0423;
    v0493 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v0493); }

v0423:
    v0453 = (Lisp_Object)33; /* 2 */
    v0493 = stack[-2];
    stack[-2] = times2(v0453, v0493);
    nil = C_nil;
    if (exception_pending()) goto v0412;
    env = stack[-3];
    v0493 = stack[0];
    v0493 = ncons(v0493);
    nil = C_nil;
    if (exception_pending()) goto v0412;
    {
        Lisp_Object v0413 = stack[-2];
        Lisp_Object v0416 = stack[-1];
        popv(4);
        return list2star(v0413, v0416, v0493);
    }
/* error exit handlers */
v0412:
    popv(4);
    return nil;
}



/* Code for rfirst */

static Lisp_Object CC_rfirst(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0475, v0273;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rfirst");
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
    v0475 = stack[0];
    v0475 = qcar(v0475);
    stack[0] = v0475;
    v0475 = stack[0];
    fn = elt(env, 4); /* listeval0 */
    v0273 = (*qfn1(fn))(qenv(fn), v0475);
    nil = C_nil;
    if (exception_pending()) goto v0258;
    env = stack[-2];
    stack[-1] = v0273;
    v0475 = elt(env, 1); /* list */
    if (!consp(v0273)) goto v0430;
    v0273 = qcar(v0273);
    if (!(v0273 == v0475)) goto v0430;
    v0475 = qvalue(elt(env, 2)); /* nil */
    goto v0371;

v0371:
    if (v0475 == nil) goto v0077;
    v0273 = stack[0];
    v0475 = elt(env, 3); /* "list" */
    fn = elt(env, 5); /* typerr */
    v0475 = (*qfn2(fn))(qenv(fn), v0273, v0475);
    nil = C_nil;
    if (exception_pending()) goto v0258;
    env = stack[-2];
    goto v0077;

v0077:
    v0475 = stack[-1];
    v0475 = qcdr(v0475);
    if (v0475 == nil) goto v0412;
    v0475 = stack[-1];
    v0475 = qcdr(v0475);
    v0475 = qcar(v0475);
    {
        popv(3);
        fn = elt(env, 6); /* reval */
        return (*qfn1(fn))(qenv(fn), v0475);
    }

v0412:
    v0273 = stack[0];
    v0475 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 7); /* parterr */
    v0475 = (*qfn2(fn))(qenv(fn), v0273, v0475);
    nil = C_nil;
    if (exception_pending()) goto v0258;
    v0475 = nil;
    { popv(3); return onevalue(v0475); }

v0430:
    v0475 = stack[0];
    fn = elt(env, 8); /* aeval */
    v0273 = (*qfn1(fn))(qenv(fn), v0475);
    nil = C_nil;
    if (exception_pending()) goto v0258;
    env = stack[-2];
    stack[-1] = v0273;
    v0475 = elt(env, 1); /* list */
    v0475 = Leqcar(nil, v0273, v0475);
    env = stack[-2];
    v0475 = (v0475 == nil ? lisp_true : nil);
    goto v0371;
/* error exit handlers */
v0258:
    popv(3);
    return nil;
}



/* Code for set!-weights */

static Lisp_Object CC_setKweights(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0417;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for set-weights");
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
    v0417 = v0000;
/* end of prologue */
    stack[-4] = (Lisp_Object)1; /* 0 */
    v0417 = qcdr(v0417);
    stack[-3] = v0417;
    v0417 = stack[-3];
    if (v0417 == nil) goto v0414;
    v0417 = (Lisp_Object)17; /* 1 */
    v0417 = ncons(v0417);
    nil = C_nil;
    if (exception_pending()) goto v0420;
    env = stack[-5];
    stack[-1] = v0417;
    stack[-2] = v0417;
    goto v0376;

v0376:
    v0417 = stack[-3];
    v0417 = qcdr(v0417);
    stack[-3] = v0417;
    v0417 = stack[-3];
    if (v0417 == nil) goto v0423;
    stack[0] = stack[-1];
    v0417 = (Lisp_Object)17; /* 1 */
    v0417 = ncons(v0417);
    nil = C_nil;
    if (exception_pending()) goto v0420;
    env = stack[-5];
    v0417 = Lrplacd(nil, stack[0], v0417);
    nil = C_nil;
    if (exception_pending()) goto v0420;
    env = stack[-5];
    v0417 = stack[-1];
    v0417 = qcdr(v0417);
    stack[-1] = v0417;
    goto v0376;

v0423:
    v0417 = stack[-2];
    goto v0381;

v0381:
    v0417 = cons(stack[-4], v0417);
    nil = C_nil;
    if (exception_pending()) goto v0420;
        popv(6);
        return Lnreverse(nil, v0417);

v0414:
    v0417 = qvalue(elt(env, 1)); /* nil */
    goto v0381;
/* error exit handlers */
v0420:
    popv(6);
    return nil;
}



/* Code for mo_zero!? */

static Lisp_Object CC_mo_zeroW(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0018;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mo_zero?");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0018 = v0000;
/* end of prologue */
    v0018 = qcar(v0018);
    {
        fn = elt(env, 1); /* mo!=zero */
        return (*qfn1(fn))(qenv(fn), v0018);
    }
}



/* Code for tidysqrtf */

static Lisp_Object CC_tidysqrtf(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0503, v0504, v0505;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for tidysqrtf");
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
    v0503 = stack[-1];
    if (!consp(v0503)) goto v0077;
    v0503 = stack[-1];
    v0503 = qcar(v0503);
    v0503 = (consp(v0503) ? nil : lisp_true);
    goto v0071;

v0071:
    if (v0503 == nil) goto v0430;
    v0504 = stack[-1];
    v0503 = (Lisp_Object)17; /* 1 */
    popv(4);
    return cons(v0504, v0503);

v0430:
    v0503 = stack[-1];
    v0503 = qcar(v0503);
    v0503 = qcar(v0503);
    stack[-2] = v0503;
    v0503 = stack[-2];
    v0504 = qcar(v0503);
    v0503 = elt(env, 2); /* i */
    if (!(v0504 == v0503)) goto v0422;
    v0504 = elt(env, 3); /* (sqrt -1) */
    v0503 = stack[-2];
    v0503 = qcdr(v0503);
    fn = elt(env, 6); /* mksp */
    v0503 = (*qfn2(fn))(qenv(fn), v0504, v0503);
    nil = C_nil;
    if (exception_pending()) goto v0506;
    env = stack[-3];
    stack[-2] = v0503;
    goto v0422;

v0422:
    v0503 = stack[-2];
    v0504 = qcar(v0503);
    v0503 = elt(env, 4); /* sqrt */
    if (!consp(v0504)) goto v0469;
    v0504 = qcar(v0504);
    if (!(v0504 == v0503)) goto v0469;
    v0503 = stack[-2];
    v0503 = qcdr(v0503);
    v0503 = Lonep(nil, v0503);
    env = stack[-3];
    v0503 = (v0503 == nil ? lisp_true : nil);
    goto v0404;

v0404:
    if (v0503 == nil) goto v0244;
    v0503 = stack[-2];
    v0504 = qcdr(v0503);
    v0503 = (Lisp_Object)33; /* 2 */
    v0503 = Ldivide(nil, v0504, v0503);
    nil = C_nil;
    if (exception_pending()) goto v0506;
    env = stack[-3];
    stack[0] = v0503;
    v0503 = stack[-2];
    v0503 = qcar(v0503);
    v0503 = qcdr(v0503);
    v0503 = qcar(v0503);
    fn = elt(env, 7); /* simp */
    v0504 = (*qfn1(fn))(qenv(fn), v0503);
    nil = C_nil;
    if (exception_pending()) goto v0506;
    env = stack[-3];
    v0503 = stack[0];
    v0503 = qcar(v0503);
    fn = elt(env, 8); /* exptsq */
    v0503 = (*qfn2(fn))(qenv(fn), v0504, v0503);
    nil = C_nil;
    if (exception_pending()) goto v0506;
    env = stack[-3];
    v0505 = v0503;
    v0503 = stack[0];
    v0504 = qcdr(v0503);
    v0503 = (Lisp_Object)1; /* 0 */
    if (v0504 == v0503) goto v0491;
    stack[0] = v0505;
    v0503 = stack[-2];
    v0504 = qcar(v0503);
    v0503 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 6); /* mksp */
    v0504 = (*qfn2(fn))(qenv(fn), v0504, v0503);
    nil = C_nil;
    if (exception_pending()) goto v0506;
    env = stack[-3];
    v0503 = (Lisp_Object)17; /* 1 */
    v0505 = cons(v0504, v0503);
    nil = C_nil;
    if (exception_pending()) goto v0506;
    env = stack[-3];
    v0504 = qvalue(elt(env, 5)); /* nil */
    v0503 = (Lisp_Object)17; /* 1 */
    v0503 = acons(v0505, v0504, v0503);
    nil = C_nil;
    if (exception_pending()) goto v0506;
    env = stack[-3];
    fn = elt(env, 9); /* multsq */
    v0503 = (*qfn2(fn))(qenv(fn), stack[0], v0503);
    nil = C_nil;
    if (exception_pending()) goto v0506;
    env = stack[-3];
    v0505 = v0503;
    goto v0491;

v0491:
    v0503 = v0505;
    fn = elt(env, 10); /* tidysqrt */
    v0503 = (*qfn1(fn))(qenv(fn), v0503);
    nil = C_nil;
    if (exception_pending()) goto v0506;
    env = stack[-3];
    v0505 = v0503;
    goto v0248;

v0248:
    stack[0] = v0505;
    v0503 = stack[-1];
    v0503 = qcar(v0503);
    v0503 = qcdr(v0503);
    v0503 = CC_tidysqrtf(env, v0503);
    nil = C_nil;
    if (exception_pending()) goto v0506;
    env = stack[-3];
    fn = elt(env, 9); /* multsq */
    v0503 = (*qfn2(fn))(qenv(fn), stack[0], v0503);
    nil = C_nil;
    if (exception_pending()) goto v0506;
    env = stack[-3];
    stack[-2] = v0503;
    stack[0] = stack[-2];
    v0503 = stack[-1];
    v0503 = qcdr(v0503);
    v0503 = CC_tidysqrtf(env, v0503);
    nil = C_nil;
    if (exception_pending()) goto v0506;
    env = stack[-3];
    {
        Lisp_Object v0507 = stack[0];
        popv(4);
        fn = elt(env, 11); /* addsq */
        return (*qfn2(fn))(qenv(fn), v0507, v0503);
    }

v0244:
    v0504 = stack[-2];
    v0503 = (Lisp_Object)17; /* 1 */
    v0505 = cons(v0504, v0503);
    nil = C_nil;
    if (exception_pending()) goto v0506;
    env = stack[-3];
    v0504 = qvalue(elt(env, 5)); /* nil */
    v0503 = (Lisp_Object)17; /* 1 */
    v0503 = acons(v0505, v0504, v0503);
    nil = C_nil;
    if (exception_pending()) goto v0506;
    env = stack[-3];
    v0505 = v0503;
    goto v0248;

v0469:
    v0503 = qvalue(elt(env, 5)); /* nil */
    goto v0404;

v0077:
    v0503 = qvalue(elt(env, 1)); /* t */
    goto v0071;
/* error exit handlers */
v0506:
    popv(4);
    return nil;
}



/* Code for ra_u */

static Lisp_Object CC_ra_u(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0018;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ra_u");
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
    fn = elt(env, 1); /* ra_iv */
    v0018 = (*qfn1(fn))(qenv(fn), v0018);
    nil = C_nil;
    if (exception_pending()) goto v0010;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* iv_u */
        return (*qfn1(fn))(qenv(fn), v0018);
    }
/* error exit handlers */
v0010:
    popv(1);
    return nil;
}



/* Code for gd_newtype */

static Lisp_Object CC_gd_newtype(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0421, v0456, v0422, v0475;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for gd_newtype");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0422 = v0001;
    v0475 = v0000;
/* end of prologue */
    v0456 = v0475;
    v0421 = v0422;
    if (v0456 == v0421) return onevalue(v0475);
    v0456 = v0475;
    v0421 = elt(env, 1); /* gec */
    if (v0456 == v0421) goto v0426;
    v0456 = v0475;
    v0421 = elt(env, 2); /* geg */
    if (v0456 == v0421) return onevalue(v0422);
    v0456 = v0422;
    v0421 = elt(env, 1); /* gec */
    if (v0456 == v0421) goto v0427;
    v0421 = elt(env, 4); /* ger */
    return onevalue(v0421);

v0427:
    v0421 = qvalue(elt(env, 3)); /* nil */
    return onevalue(v0421);

v0426:
    v0456 = v0422;
    v0421 = elt(env, 2); /* geg */
    if (v0456 == v0421) goto v0488;
    v0421 = qvalue(elt(env, 3)); /* nil */
    return onevalue(v0421);

v0488:
    v0421 = elt(env, 1); /* gec */
    return onevalue(v0421);
}



/* Code for change!+int!+to!+sq */

static Lisp_Object CC_changeLintLtoLsq(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0371, v0372;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for change+int+to+sq");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0371 = v0000;
/* end of prologue */
    v0372 = v0371;
    v0371 = (Lisp_Object)17; /* 1 */
    return cons(v0372, v0371);
}



/* Code for mri_ofsf2mri */

static Lisp_Object CC_mri_ofsf2mri(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0379, v0312;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mri_ofsf2mri");
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
    v0379 = v0001;
    v0312 = v0000;
/* end of prologue */
    stack[-1] = v0312;
    stack[0] = elt(env, 1); /* mri_ofsf2mriat */
    v0379 = ncons(v0379);
    nil = C_nil;
    if (exception_pending()) goto v0376;
    env = stack[-2];
    {
        Lisp_Object v0375 = stack[-1];
        Lisp_Object v0380 = stack[0];
        popv(3);
        fn = elt(env, 2); /* cl_apply2ats1 */
        return (*qfnn(fn))(qenv(fn), 3, v0375, v0380, v0379);
    }
/* error exit handlers */
v0376:
    popv(3);
    return nil;
}



/* Code for rnfix!* */

static Lisp_Object CC_rnfixH(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0401, v0379;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rnfix*");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0401 = v0000;
/* end of prologue */
    v0379 = v0401;
    v0379 = qcdr(v0379);
    v0379 = qcar(v0379);
    v0401 = qcdr(v0401);
    v0401 = qcdr(v0401);
    return quot2(v0379, v0401);
}



/* Code for simpdf */

static Lisp_Object CC_simpdf(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0520, v0521;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for simpdf");
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
    stack[-5] = v0000;
/* end of prologue */
    stack[-3] = nil;
    v0520 = qvalue(elt(env, 1)); /* subfg!* */
    if (v0520 == nil) goto v0380;
    v0520 = stack[-5];
    v0520 = qcdr(v0520);
    stack[-6] = v0520;
    v0520 = stack[-5];
    v0520 = qcar(v0520);
    fn = elt(env, 10); /* simp!* */
    v0520 = (*qfn1(fn))(qenv(fn), v0520);
    nil = C_nil;
    if (exception_pending()) goto v0522;
    env = stack[-7];
    stack[-5] = v0520;
    goto v0077;

v0077:
    v0520 = stack[-6];
    if (v0520 == nil) goto v0403;
    v0520 = stack[-5];
    v0520 = qcar(v0520);
    v0520 = (v0520 == nil ? lisp_true : nil);
    goto v0374;

v0374:
    if (!(v0520 == nil)) { Lisp_Object res = stack[-5]; popv(8); return onevalue(res); }
    v0520 = stack[-3];
    if (v0520 == nil) goto v0465;
    v0521 = stack[-3];
    v0520 = (Lisp_Object)1; /* 0 */
    v0520 = (v0521 == v0520 ? lisp_true : nil);
    goto v0417;

v0417:
    if (v0520 == nil) goto v0523;
    v0520 = stack[-6];
    v0520 = qcar(v0520);
    fn = elt(env, 10); /* simp!* */
    v0520 = (*qfn1(fn))(qenv(fn), v0520);
    nil = C_nil;
    if (exception_pending()) goto v0522;
    env = stack[-7];
    goto v0411;

v0411:
    stack[-4] = v0520;
    v0520 = stack[-4];
    v0521 = qcdr(v0520);
    v0520 = (Lisp_Object)17; /* 1 */
    if (v0521 == v0520) goto v0392;
    v0520 = qvalue(elt(env, 3)); /* t */
    goto v0265;

v0265:
    if (v0520 == nil) goto v0459;
    v0520 = stack[-4];
    fn = elt(env, 11); /* prepsq */
    v0521 = (*qfn1(fn))(qenv(fn), v0520);
    nil = C_nil;
    if (exception_pending()) goto v0522;
    env = stack[-7];
    v0520 = elt(env, 4); /* "kernel or integer" */
    fn = elt(env, 12); /* typerr */
    v0520 = (*qfn2(fn))(qenv(fn), v0521, v0520);
    nil = C_nil;
    if (exception_pending()) goto v0522;
    env = stack[-7];
    goto v0524;

v0524:
    v0520 = stack[-6];
    v0520 = qcdr(v0520);
    stack[-6] = v0520;
    v0520 = stack[-6];
    if (v0520 == nil) goto v0400;
    v0520 = stack[-6];
    v0520 = qcar(v0520);
    fn = elt(env, 10); /* simp!* */
    v0520 = (*qfn1(fn))(qenv(fn), v0520);
    nil = C_nil;
    if (exception_pending()) goto v0522;
    env = stack[-7];
    stack[-3] = v0520;
    v0520 = stack[-3];
    v0520 = qcar(v0520);
    if (v0520 == nil) goto v0525;
    v0520 = stack[-3];
    fn = elt(env, 13); /* d2int */
    v0520 = (*qfn1(fn))(qenv(fn), v0520);
    nil = C_nil;
    if (exception_pending()) goto v0522;
    env = stack[-7];
    stack[0] = v0520;
    if (v0520 == nil) goto v0526;
    v0520 = stack[-6];
    v0520 = qcdr(v0520);
    stack[-6] = v0520;
    v0520 = (Lisp_Object)17; /* 1 */
    stack[-1] = v0520;
    goto v0527;

v0527:
    v0521 = stack[0];
    v0520 = stack[-1];
    v0520 = difference2(v0521, v0520);
    nil = C_nil;
    if (exception_pending()) goto v0522;
    env = stack[-7];
    v0520 = Lminusp(nil, v0520);
    env = stack[-7];
    if (v0520 == nil) goto v0528;
    v0520 = qvalue(elt(env, 8)); /* nil */
    stack[-3] = v0520;
    goto v0077;

v0528:
    v0521 = stack[-5];
    v0520 = stack[-4];
    fn = elt(env, 14); /* diffsq */
    v0520 = (*qfn2(fn))(qenv(fn), v0521, v0520);
    nil = C_nil;
    if (exception_pending()) goto v0522;
    env = stack[-7];
    stack[-5] = v0520;
    v0520 = stack[-1];
    v0520 = add1(v0520);
    nil = C_nil;
    if (exception_pending()) goto v0522;
    env = stack[-7];
    stack[-1] = v0520;
    goto v0527;

v0526:
    v0521 = stack[-5];
    v0520 = stack[-4];
    fn = elt(env, 14); /* diffsq */
    v0520 = (*qfn2(fn))(qenv(fn), v0521, v0520);
    nil = C_nil;
    if (exception_pending()) goto v0522;
    env = stack[-7];
    stack[-5] = v0520;
    goto v0077;

v0525:
    v0520 = stack[-6];
    v0520 = qcdr(v0520);
    stack[-6] = v0520;
    v0520 = qvalue(elt(env, 8)); /* nil */
    stack[-3] = v0520;
    goto v0077;

v0400:
    v0521 = stack[-5];
    v0520 = stack[-4];
    fn = elt(env, 14); /* diffsq */
    v0520 = (*qfn2(fn))(qenv(fn), v0521, v0520);
    nil = C_nil;
    if (exception_pending()) goto v0522;
    env = stack[-7];
    stack[-5] = v0520;
    goto v0077;

v0459:
    v0520 = stack[-4];
    v0520 = qcar(v0520);
    stack[-2] = v0520;
    v0520 = stack[-2];
    if (!consp(v0520)) goto v0481;
    v0520 = stack[-2];
    v0520 = qcar(v0520);
    v0520 = (consp(v0520) ? nil : lisp_true);
    goto v0290;

v0290:
    if (v0520 == nil) goto v0407;
    v0520 = stack[-2];
    v0521 = qcar(v0520);
    v0520 = elt(env, 5); /* domain!-diff!-fn */
    v0520 = get(v0521, v0520);
    env = stack[-7];
    if (v0520 == nil) goto v0443;
    stack[-1] = qvalue(elt(env, 6)); /* dmode!* */
    qvalue(elt(env, 6)) = nil; /* dmode!* */
    stack[0] = qvalue(elt(env, 7)); /* alglist!* */
    qvalue(elt(env, 7)) = nil; /* alglist!* */
    v0520 = qvalue(elt(env, 8)); /* nil */
    v0520 = ncons(v0520);
    nil = C_nil;
    if (exception_pending()) goto v0529;
    env = stack[-7];
    qvalue(elt(env, 7)) = v0520; /* alglist!* */
    v0520 = stack[-2];
    fn = elt(env, 15); /* prepf */
    v0520 = (*qfn1(fn))(qenv(fn), v0520);
    nil = C_nil;
    if (exception_pending()) goto v0529;
    env = stack[-7];
    stack[-4] = v0520;
    v0520 = stack[-4];
    fn = elt(env, 16); /* prekernp */
    v0520 = (*qfn1(fn))(qenv(fn), v0520);
    nil = C_nil;
    if (exception_pending()) goto v0529;
    env = stack[-7];
    if (!(v0520 == nil)) goto v0391;
    v0521 = stack[-4];
    v0520 = elt(env, 9); /* "kernel" */
    fn = elt(env, 12); /* typerr */
    v0520 = (*qfn2(fn))(qenv(fn), v0521, v0520);
    nil = C_nil;
    if (exception_pending()) goto v0529;
    env = stack[-7];
    goto v0391;

v0391:
    qvalue(elt(env, 7)) = stack[0]; /* alglist!* */
    qvalue(elt(env, 6)) = stack[-1]; /* dmode!* */
    goto v0524;

v0443:
    v0520 = stack[-2];
    fn = elt(env, 15); /* prepf */
    v0521 = (*qfn1(fn))(qenv(fn), v0520);
    nil = C_nil;
    if (exception_pending()) goto v0522;
    env = stack[-7];
    v0520 = elt(env, 9); /* "kernel" */
    fn = elt(env, 12); /* typerr */
    v0520 = (*qfn2(fn))(qenv(fn), v0521, v0520);
    nil = C_nil;
    if (exception_pending()) goto v0522;
    env = stack[-7];
    goto v0524;

v0407:
    v0520 = stack[-2];
    v0520 = qcdr(v0520);
    if (v0520 == nil) goto v0530;
    v0520 = qvalue(elt(env, 8)); /* nil */
    goto v0439;

v0439:
    if (v0520 == nil) goto v0531;
    v0520 = stack[-2];
    v0520 = qcar(v0520);
    v0520 = qcar(v0520);
    v0520 = qcar(v0520);
    stack[-4] = v0520;
    goto v0524;

v0531:
    v0520 = stack[-2];
    fn = elt(env, 15); /* prepf */
    v0521 = (*qfn1(fn))(qenv(fn), v0520);
    nil = C_nil;
    if (exception_pending()) goto v0522;
    env = stack[-7];
    v0520 = elt(env, 9); /* "kernel" */
    fn = elt(env, 12); /* typerr */
    v0520 = (*qfn2(fn))(qenv(fn), v0521, v0520);
    nil = C_nil;
    if (exception_pending()) goto v0522;
    env = stack[-7];
    goto v0524;

v0530:
    v0520 = stack[-2];
    v0520 = qcar(v0520);
    v0521 = qcdr(v0520);
    v0520 = (Lisp_Object)17; /* 1 */
    if (v0521 == v0520) goto v0505;
    v0520 = qvalue(elt(env, 8)); /* nil */
    goto v0439;

v0505:
    v0520 = stack[-2];
    v0520 = qcar(v0520);
    v0520 = qcar(v0520);
    v0521 = qcdr(v0520);
    v0520 = (Lisp_Object)17; /* 1 */
    v0520 = (v0521 == v0520 ? lisp_true : nil);
    goto v0439;

v0481:
    v0520 = qvalue(elt(env, 3)); /* t */
    goto v0290;

v0392:
    v0520 = stack[-4];
    v0520 = qcar(v0520);
    v0520 = (consp(v0520) ? nil : lisp_true);
    goto v0265;

v0523:
    v0520 = stack[-3];
    goto v0411;

v0465:
    v0520 = qvalue(elt(env, 3)); /* t */
    goto v0417;

v0403:
    v0520 = qvalue(elt(env, 3)); /* t */
    goto v0374;

v0380:
    v0521 = elt(env, 2); /* df */
    v0520 = stack[-5];
    v0521 = cons(v0521, v0520);
    nil = C_nil;
    if (exception_pending()) goto v0522;
    env = stack[-7];
    v0520 = (Lisp_Object)17; /* 1 */
    {
        popv(8);
        fn = elt(env, 17); /* mksq */
        return (*qfn2(fn))(qenv(fn), v0521, v0520);
    }
/* error exit handlers */
v0529:
    env = stack[-7];
    qvalue(elt(env, 7)) = stack[0]; /* alglist!* */
    qvalue(elt(env, 6)) = stack[-1]; /* dmode!* */
    popv(8);
    return nil;
v0522:
    popv(8);
    return nil;
}



/* Code for den */

static Lisp_Object CC_den(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0372, v0401;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for den");
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
    v0372 = v0000;
/* end of prologue */
    fn = elt(env, 1); /* simp!* */
    v0372 = (*qfn1(fn))(qenv(fn), v0372);
    nil = C_nil;
    if (exception_pending()) goto v0379;
    env = stack[0];
    v0401 = qcdr(v0372);
    v0372 = (Lisp_Object)17; /* 1 */
    v0372 = cons(v0401, v0372);
    nil = C_nil;
    if (exception_pending()) goto v0379;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* mk!*sq */
        return (*qfn1(fn))(qenv(fn), v0372);
    }
/* error exit handlers */
v0379:
    popv(1);
    return nil;
}



/* Code for !*q2f */

static Lisp_Object CC_Hq2f(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0425, v0426, v0452;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for *q2f");
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
    v0452 = v0000;
/* end of prologue */
    v0425 = v0452;
    v0426 = qcdr(v0425);
    v0425 = (Lisp_Object)17; /* 1 */
    if (v0426 == v0425) goto v0004;
    v0425 = v0452;
    fn = elt(env, 2); /* prepsq */
    v0426 = (*qfn1(fn))(qenv(fn), v0425);
    nil = C_nil;
    if (exception_pending()) goto v0418;
    env = stack[0];
    v0425 = elt(env, 1); /* polynomial */
    {
        popv(1);
        fn = elt(env, 3); /* typerr */
        return (*qfn2(fn))(qenv(fn), v0426, v0425);
    }

v0004:
    v0425 = v0452;
    v0425 = qcar(v0425);
    { popv(1); return onevalue(v0425); }
/* error exit handlers */
v0418:
    popv(1);
    return nil;
}



/* Code for groebinvokecritm */

static Lisp_Object CC_groebinvokecritm(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0257, v0402;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for groebinvokecritm");
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
    v0257 = stack[-1];
    stack[-3] = v0257;
    goto v0010;

v0010:
    v0257 = stack[-3];
    if (v0257 == nil) { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }
    v0257 = stack[-3];
    v0257 = qcar(v0257);
    stack[0] = v0257;
    v0257 = stack[-2];
    v0402 = qcar(v0257);
    v0257 = stack[0];
    v0257 = qcar(v0257);
    fn = elt(env, 3); /* buchvevdivides!? */
    v0257 = (*qfn2(fn))(qenv(fn), v0402, v0257);
    nil = C_nil;
    if (exception_pending()) goto v0271;
    env = stack[-4];
    if (v0257 == nil) goto v0370;
    v0257 = qvalue(elt(env, 2)); /* mcount!* */
    v0257 = add1(v0257);
    nil = C_nil;
    if (exception_pending()) goto v0271;
    env = stack[-4];
    qvalue(elt(env, 2)) = v0257; /* mcount!* */
    v0402 = stack[0];
    v0257 = stack[-1];
    fn = elt(env, 4); /* groedeletip */
    v0257 = (*qfn2(fn))(qenv(fn), v0402, v0257);
    nil = C_nil;
    if (exception_pending()) goto v0271;
    env = stack[-4];
    stack[-1] = v0257;
    goto v0370;

v0370:
    v0257 = stack[-3];
    v0257 = qcdr(v0257);
    stack[-3] = v0257;
    goto v0010;
/* error exit handlers */
v0271:
    popv(5);
    return nil;
}



/* Code for weak_xreduce1 */

static Lisp_Object MS_CDECL CC_weak_xreduce1(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0439, v0440, v0433;
    Lisp_Object fn;
    Lisp_Object v0428, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "weak_xreduce1");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0001 = va_arg(aa, Lisp_Object);
    v0428 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for weak_xreduce1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0428,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0428);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-3] = v0428;
    stack[-4] = v0001;
    stack[-5] = v0000;
/* end of prologue */
    v0439 = stack[-4];
    stack[0] = v0439;
    goto v0401;

v0401:
    v0439 = stack[-5];
    if (v0439 == nil) { Lisp_Object res = stack[-5]; popv(8); return onevalue(res); }
    v0439 = stack[0];
    if (v0439 == nil) { Lisp_Object res = stack[-5]; popv(8); return onevalue(res); }
    v0439 = stack[0];
    v0439 = qcar(v0439);
    stack[-6] = v0439;
    v0439 = stack[0];
    v0439 = qcdr(v0439);
    stack[0] = v0439;
    v0439 = stack[-6];
    fn = elt(env, 8); /* xval */
    stack[-1] = (*qfn1(fn))(qenv(fn), v0439);
    nil = C_nil;
    if (exception_pending()) goto v0535;
    env = stack[-7];
    v0439 = stack[-5];
    fn = elt(env, 8); /* xval */
    v0439 = (*qfn1(fn))(qenv(fn), v0439);
    nil = C_nil;
    if (exception_pending()) goto v0535;
    env = stack[-7];
    fn = elt(env, 9); /* xdiv */
    v0439 = (*qfn2(fn))(qenv(fn), stack[-1], v0439);
    nil = C_nil;
    if (exception_pending()) goto v0535;
    env = stack[-7];
    stack[-1] = v0439;
    if (v0439 == nil) goto v0401;
    v0439 = stack[-1];
    fn = elt(env, 10); /* mknwedge */
    v0433 = (*qfn1(fn))(qenv(fn), v0439);
    nil = C_nil;
    if (exception_pending()) goto v0535;
    env = stack[-7];
    v0440 = (Lisp_Object)17; /* 1 */
    v0439 = (Lisp_Object)17; /* 1 */
    v0439 = list2star(v0433, v0440, v0439);
    nil = C_nil;
    if (exception_pending()) goto v0535;
    env = stack[-7];
    v0439 = ncons(v0439);
    nil = C_nil;
    if (exception_pending()) goto v0535;
    env = stack[-7];
    stack[-1] = v0439;
    v0440 = stack[-1];
    v0439 = stack[-6];
    fn = elt(env, 11); /* wedgepf */
    v0439 = (*qfn2(fn))(qenv(fn), v0440, v0439);
    nil = C_nil;
    if (exception_pending()) goto v0535;
    env = stack[-7];
    stack[0] = v0439;
    v0439 = stack[-5];
    v0439 = qcar(v0439);
    v0440 = qcdr(v0439);
    v0439 = stack[0];
    v0439 = qcar(v0439);
    v0439 = qcdr(v0439);
    fn = elt(env, 12); /* quotsq */
    v0439 = (*qfn2(fn))(qenv(fn), v0440, v0439);
    nil = C_nil;
    if (exception_pending()) goto v0535;
    env = stack[-7];
    stack[-2] = v0439;
    v0439 = stack[-2];
    fn = elt(env, 13); /* negsq */
    v0439 = (*qfn1(fn))(qenv(fn), v0439);
    nil = C_nil;
    if (exception_pending()) goto v0535;
    env = stack[-7];
    fn = elt(env, 14); /* multpfsq */
    v0439 = (*qfn2(fn))(qenv(fn), stack[0], v0439);
    nil = C_nil;
    if (exception_pending()) goto v0535;
    env = stack[-7];
    fn = elt(env, 15); /* addpf */
    v0439 = (*qfn2(fn))(qenv(fn), stack[-5], v0439);
    nil = C_nil;
    if (exception_pending()) goto v0535;
    env = stack[-7];
    fn = elt(env, 16); /* subs2pf */
    v0439 = (*qfn1(fn))(qenv(fn), v0439);
    nil = C_nil;
    if (exception_pending()) goto v0535;
    env = stack[-7];
    stack[-5] = v0439;
    v0439 = qvalue(elt(env, 2)); /* !*trxmod */
    if (v0439 == nil) goto v0266;
    stack[0] = stack[-3];
    v0440 = stack[-1];
    v0439 = stack[-2];
    fn = elt(env, 14); /* multpfsq */
    v0440 = (*qfn2(fn))(qenv(fn), v0440, v0439);
    nil = C_nil;
    if (exception_pending()) goto v0535;
    env = stack[-7];
    v0439 = stack[-6];
    v0439 = list2(v0440, v0439);
    nil = C_nil;
    if (exception_pending()) goto v0535;
    env = stack[-7];
    v0439 = ncons(v0439);
    nil = C_nil;
    if (exception_pending()) goto v0535;
    env = stack[-7];
    v0439 = Lnconc(nil, stack[0], v0439);
    nil = C_nil;
    if (exception_pending()) goto v0535;
    env = stack[-7];
    stack[-3] = v0439;
    goto v0266;

v0266:
    v0439 = qvalue(elt(env, 2)); /* !*trxmod */
    if (v0439 == nil) goto v0256;
    v0440 = elt(env, 3); /* "   " */
    v0439 = elt(env, 4); /* first */
    fn = elt(env, 17); /* writepri */
    v0439 = (*qfn2(fn))(qenv(fn), v0440, v0439);
    nil = C_nil;
    if (exception_pending()) goto v0535;
    env = stack[-7];
    stack[0] = elt(env, 5); /* wedge */
    v0440 = stack[-1];
    v0439 = stack[-2];
    fn = elt(env, 14); /* multpfsq */
    v0439 = (*qfn2(fn))(qenv(fn), v0440, v0439);
    nil = C_nil;
    if (exception_pending()) goto v0535;
    env = stack[-7];
    fn = elt(env, 18); /* preppf */
    stack[-1] = (*qfn1(fn))(qenv(fn), v0439);
    nil = C_nil;
    if (exception_pending()) goto v0535;
    env = stack[-7];
    v0439 = stack[-6];
    fn = elt(env, 18); /* preppf */
    v0439 = (*qfn1(fn))(qenv(fn), v0439);
    nil = C_nil;
    if (exception_pending()) goto v0535;
    env = stack[-7];
    v0439 = list3(stack[0], stack[-1], v0439);
    nil = C_nil;
    if (exception_pending()) goto v0535;
    env = stack[-7];
    v0440 = Lmkquote(nil, v0439);
    nil = C_nil;
    if (exception_pending()) goto v0535;
    env = stack[-7];
    v0439 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 17); /* writepri */
    v0439 = (*qfn2(fn))(qenv(fn), v0440, v0439);
    nil = C_nil;
    if (exception_pending()) goto v0535;
    env = stack[-7];
    v0440 = elt(env, 6); /* " +" */
    v0439 = elt(env, 7); /* last */
    fn = elt(env, 17); /* writepri */
    v0439 = (*qfn2(fn))(qenv(fn), v0440, v0439);
    nil = C_nil;
    if (exception_pending()) goto v0535;
    env = stack[-7];
    goto v0256;

v0256:
    v0439 = stack[-4];
    stack[0] = v0439;
    goto v0401;
/* error exit handlers */
v0535:
    popv(8);
    return nil;
}



/* Code for mkforttab */

static Lisp_Object MS_CDECL CC_mkforttab(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0312, v0378;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "mkforttab");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mkforttab");
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
    stack[0] = elt(env, 1); /* forttab */
    v0378 = qvalue(elt(env, 2)); /* fortcurrind!* */
    v0312 = (Lisp_Object)97; /* 6 */
    v0312 = plus2(v0378, v0312);
    nil = C_nil;
    if (exception_pending()) goto v0376;
    {
        Lisp_Object v0375 = stack[0];
        popv(1);
        return list2(v0375, v0312);
    }
/* error exit handlers */
v0376:
    popv(1);
    return nil;
}



/* Code for physoppri */

static Lisp_Object CC_physoppri(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0225, v0226, v0549, v0550;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for physoppri");
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
    stack[-6] = nil;
    v0225 = stack[-8];
    if (symbolp(v0225)) goto v0381;
    v0225 = stack[-8];
    v0225 = qcar(v0225);
    goto v0388;

v0388:
    stack[-9] = v0225;
    v0225 = stack[-8];
    if (symbolp(v0225)) goto v0380;
    v0225 = stack[-8];
    v0225 = qcdr(v0225);
    goto v0375;

v0375:
    stack[-7] = v0225;
    stack[-5] = elt(env, 0); /* physoppri */
    stack[-4] = elt(env, 2); /* "x= " */
    stack[-3] = stack[-9];
    stack[-2] = elt(env, 3); /* " y= " */
    stack[-1] = stack[-7];
    stack[0] = elt(env, 4); /* "nat= " */
    v0549 = elt(env, 5); /* !*nat */
    v0226 = elt(env, 6); /* " contract= " */
    v0225 = elt(env, 7); /* !*contract */
    v0225 = list3(v0549, v0226, v0225);
    nil = C_nil;
    if (exception_pending()) goto v0551;
    env = stack[-10];
    v0225 = list3star(stack[-2], stack[-1], stack[0], v0225);
    nil = C_nil;
    if (exception_pending()) goto v0551;
    env = stack[-10];
    v0225 = list3star(stack[-5], stack[-4], stack[-3], v0225);
    nil = C_nil;
    if (exception_pending()) goto v0551;
    env = stack[-10];
    fn = elt(env, 20); /* trwrite */
    v0225 = (*qfn1(fn))(qenv(fn), v0225);
    nil = C_nil;
    if (exception_pending()) goto v0551;
    env = stack[-10];
    v0225 = qvalue(elt(env, 5)); /* !*nat */
    if (v0225 == nil) goto v0394;
    v0225 = qvalue(elt(env, 7)); /* !*contract */
    if (!(v0225 == nil)) goto v0394;
    v0225 = stack[-9];
    v0225 = Lexplode(nil, v0225);
    nil = C_nil;
    if (exception_pending()) goto v0551;
    env = stack[-10];
    v0225 = Lreverse(nil, v0225);
    nil = C_nil;
    if (exception_pending()) goto v0551;
    env = stack[-10];
    stack[-9] = v0225;
    v0225 = stack[-9];
    v0226 = Llength(nil, v0225);
    nil = C_nil;
    if (exception_pending()) goto v0551;
    env = stack[-10];
    v0225 = (Lisp_Object)33; /* 2 */
    v0225 = (Lisp_Object)greaterp2(v0226, v0225);
    nil = C_nil;
    if (exception_pending()) goto v0551;
    v0225 = v0225 ? lisp_true : nil;
    env = stack[-10];
    if (v0225 == nil) goto v0505;
    v0225 = stack[-9];
    v0225 = qcdr(v0225);
    v0226 = qcar(v0225);
    v0225 = elt(env, 14); /* !- */
    if (v0226 == v0225) goto v0486;
    v0225 = stack[-9];
    v0226 = qcar(v0225);
    v0225 = elt(env, 16); /* !+ */
    if (v0226 == v0225) goto v0389;
    v0225 = stack[-9];
    v0225 = Lreverse(nil, v0225);
    nil = C_nil;
    if (exception_pending()) goto v0551;
    env = stack[-10];
    v0225 = Lcompress(nil, v0225);
    nil = C_nil;
    if (exception_pending()) goto v0551;
    env = stack[-10];
    stack[-9] = v0225;
    goto v0552;

v0552:
    stack[0] = elt(env, 8); /* !" */
    v0225 = stack[-9];
    v0225 = Lexplode(nil, v0225);
    nil = C_nil;
    if (exception_pending()) goto v0551;
    env = stack[-10];
    stack[0] = cons(stack[0], v0225);
    nil = C_nil;
    if (exception_pending()) goto v0551;
    env = stack[-10];
    v0225 = elt(env, 8); /* !" */
    v0225 = ncons(v0225);
    nil = C_nil;
    if (exception_pending()) goto v0551;
    env = stack[-10];
    v0225 = Lappend(nil, stack[0], v0225);
    nil = C_nil;
    if (exception_pending()) goto v0551;
    env = stack[-10];
    v0225 = Lcompress(nil, v0225);
    nil = C_nil;
    if (exception_pending()) goto v0551;
    env = stack[-10];
    stack[-9] = v0225;
    v0225 = stack[-7];
    if (v0225 == nil) goto v0431;
    v0226 = stack[-9];
    v0225 = stack[-7];
    v0225 = cons(v0226, v0225);
    nil = C_nil;
    if (exception_pending()) goto v0551;
    env = stack[-10];
    goto v0531;

v0531:
    stack[-3] = v0225;
    stack[-2] = elt(env, 0); /* physoppri */
    stack[-1] = elt(env, 2); /* "x= " */
    stack[0] = stack[-9];
    v0550 = elt(env, 17); /* " z= " */
    v0549 = stack[-6];
    v0226 = elt(env, 18); /* " x1= " */
    v0225 = stack[-3];
    v0225 = list4(v0550, v0549, v0226, v0225);
    nil = C_nil;
    if (exception_pending()) goto v0551;
    env = stack[-10];
    v0225 = list3star(stack[-2], stack[-1], stack[0], v0225);
    nil = C_nil;
    if (exception_pending()) goto v0551;
    env = stack[-10];
    fn = elt(env, 20); /* trwrite */
    v0225 = (*qfn1(fn))(qenv(fn), v0225);
    nil = C_nil;
    if (exception_pending()) goto v0551;
    env = stack[-10];
    v0225 = stack[-6];
    if (v0225 == nil) goto v0553;
    v0549 = elt(env, 19); /* expt */
    v0226 = stack[-3];
    v0225 = stack[-6];
    v0226 = list3(v0549, v0226, v0225);
    nil = C_nil;
    if (exception_pending()) goto v0551;
    env = stack[-10];
    v0225 = elt(env, 19); /* expt */
    if (!symbolp(v0225)) v0225 = nil;
    else { v0225 = qfastgets(v0225);
           if (v0225 != nil) { v0225 = elt(v0225, 23); /* infix */
#ifdef RECORD_GET
             if (v0225 != SPID_NOPROP)
                record_get(elt(fastget_names, 23), 1);
             else record_get(elt(fastget_names, 23), 0),
                v0225 = nil; }
           else record_get(elt(fastget_names, 23), 0); }
#else
             if (v0225 == SPID_NOPROP) v0225 = nil; }}
#endif
    fn = elt(env, 21); /* exptpri */
    v0225 = (*qfn2(fn))(qenv(fn), v0226, v0225);
    nil = C_nil;
    if (exception_pending()) goto v0551;
    { Lisp_Object res = stack[-8]; popv(11); return onevalue(res); }

v0553:
    v0225 = stack[-9];
    fn = elt(env, 22); /* prin2!* */
    v0225 = (*qfn1(fn))(qenv(fn), v0225);
    nil = C_nil;
    if (exception_pending()) goto v0551;
    env = stack[-10];
    v0225 = stack[-7];
    if (v0225 == nil) { Lisp_Object res = stack[-8]; popv(11); return onevalue(res); }
    v0225 = elt(env, 9); /* "(" */
    fn = elt(env, 22); /* prin2!* */
    v0225 = (*qfn1(fn))(qenv(fn), v0225);
    nil = C_nil;
    if (exception_pending()) goto v0551;
    env = stack[-10];
    v0225 = qvalue(elt(env, 1)); /* nil */
    qvalue(elt(env, 10)) = v0225; /* obrkp!* */
    v0549 = elt(env, 11); /* !*comma!* */
    v0226 = (Lisp_Object)1; /* 0 */
    v0225 = stack[-7];
    fn = elt(env, 23); /* inprint */
    v0225 = (*qfnn(fn))(qenv(fn), 3, v0549, v0226, v0225);
    nil = C_nil;
    if (exception_pending()) goto v0551;
    env = stack[-10];
    v0225 = qvalue(elt(env, 12)); /* t */
    qvalue(elt(env, 10)) = v0225; /* obrkp!* */
    v0225 = elt(env, 13); /* ")" */
    fn = elt(env, 22); /* prin2!* */
    v0225 = (*qfn1(fn))(qenv(fn), v0225);
    nil = C_nil;
    if (exception_pending()) goto v0551;
    { Lisp_Object res = stack[-8]; popv(11); return onevalue(res); }

v0431:
    v0225 = stack[-9];
    goto v0531;

v0389:
    v0225 = elt(env, 16); /* !+ */
    stack[-6] = v0225;
    v0226 = stack[-9];
    v0225 = (Lisp_Object)49; /* 3 */
    fn = elt(env, 24); /* pnth */
    v0225 = (*qfn2(fn))(qenv(fn), v0226, v0225);
    nil = C_nil;
    if (exception_pending()) goto v0551;
    env = stack[-10];
    v0225 = Lreverse(nil, v0225);
    nil = C_nil;
    if (exception_pending()) goto v0551;
    env = stack[-10];
    v0225 = Lcompress(nil, v0225);
    nil = C_nil;
    if (exception_pending()) goto v0551;
    env = stack[-10];
    stack[-9] = v0225;
    goto v0552;

v0486:
    v0226 = elt(env, 14); /* !- */
    v0225 = elt(env, 15); /* !1 */
    v0225 = list2(v0226, v0225);
    nil = C_nil;
    if (exception_pending()) goto v0551;
    env = stack[-10];
    v0225 = Lcompress(nil, v0225);
    nil = C_nil;
    if (exception_pending()) goto v0551;
    env = stack[-10];
    stack[-6] = v0225;
    v0226 = stack[-9];
    v0225 = (Lisp_Object)65; /* 4 */
    fn = elt(env, 24); /* pnth */
    v0225 = (*qfn2(fn))(qenv(fn), v0226, v0225);
    nil = C_nil;
    if (exception_pending()) goto v0551;
    env = stack[-10];
    v0225 = Lreverse(nil, v0225);
    nil = C_nil;
    if (exception_pending()) goto v0551;
    env = stack[-10];
    v0225 = Lcompress(nil, v0225);
    nil = C_nil;
    if (exception_pending()) goto v0551;
    env = stack[-10];
    stack[-9] = v0225;
    goto v0552;

v0505:
    v0225 = stack[-9];
    v0225 = Lreverse(nil, v0225);
    nil = C_nil;
    if (exception_pending()) goto v0551;
    env = stack[-10];
    v0225 = Lcompress(nil, v0225);
    nil = C_nil;
    if (exception_pending()) goto v0551;
    env = stack[-10];
    stack[-9] = v0225;
    goto v0552;

v0394:
    stack[0] = elt(env, 8); /* !" */
    v0225 = stack[-9];
    v0225 = Lexplode(nil, v0225);
    nil = C_nil;
    if (exception_pending()) goto v0551;
    env = stack[-10];
    stack[0] = cons(stack[0], v0225);
    nil = C_nil;
    if (exception_pending()) goto v0551;
    env = stack[-10];
    v0225 = elt(env, 8); /* !" */
    v0225 = ncons(v0225);
    nil = C_nil;
    if (exception_pending()) goto v0551;
    env = stack[-10];
    v0225 = Lappend(nil, stack[0], v0225);
    nil = C_nil;
    if (exception_pending()) goto v0551;
    env = stack[-10];
    v0225 = Lcompress(nil, v0225);
    nil = C_nil;
    if (exception_pending()) goto v0551;
    env = stack[-10];
    stack[-9] = v0225;
    v0225 = stack[-9];
    fn = elt(env, 22); /* prin2!* */
    v0225 = (*qfn1(fn))(qenv(fn), v0225);
    nil = C_nil;
    if (exception_pending()) goto v0551;
    env = stack[-10];
    v0225 = stack[-7];
    if (v0225 == nil) { Lisp_Object res = stack[-8]; popv(11); return onevalue(res); }
    v0225 = elt(env, 9); /* "(" */
    fn = elt(env, 22); /* prin2!* */
    v0225 = (*qfn1(fn))(qenv(fn), v0225);
    nil = C_nil;
    if (exception_pending()) goto v0551;
    env = stack[-10];
    v0225 = qvalue(elt(env, 1)); /* nil */
    qvalue(elt(env, 10)) = v0225; /* obrkp!* */
    v0549 = elt(env, 11); /* !*comma!* */
    v0226 = (Lisp_Object)1; /* 0 */
    v0225 = stack[-7];
    fn = elt(env, 23); /* inprint */
    v0225 = (*qfnn(fn))(qenv(fn), 3, v0549, v0226, v0225);
    nil = C_nil;
    if (exception_pending()) goto v0551;
    env = stack[-10];
    v0225 = qvalue(elt(env, 12)); /* t */
    qvalue(elt(env, 10)) = v0225; /* obrkp!* */
    v0225 = elt(env, 13); /* ")" */
    fn = elt(env, 22); /* prin2!* */
    v0225 = (*qfn1(fn))(qenv(fn), v0225);
    nil = C_nil;
    if (exception_pending()) goto v0551;
    { Lisp_Object res = stack[-8]; popv(11); return onevalue(res); }

v0380:
    v0225 = qvalue(elt(env, 1)); /* nil */
    goto v0375;

v0381:
    v0225 = stack[-8];
    goto v0388;
/* error exit handlers */
v0551:
    popv(11);
    return nil;
}



/* Code for mk_parents_prim */

static Lisp_Object CC_mk_parents_prim(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0373, v0374;
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
    v0373 = stack[0];
    v0374 = Llength(nil, v0373);
    nil = C_nil;
    if (exception_pending()) goto v0548;
    env = stack[-1];
    v0373 = (Lisp_Object)49; /* 3 */
    if (!(v0374 == v0373)) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v0373 = stack[0];
    fn = elt(env, 1); /* s_noparents */
    v0373 = (*qfn1(fn))(qenv(fn), v0373);
    nil = C_nil;
    if (exception_pending()) goto v0548;
    env = stack[-1];
    v0374 = v0373;
    if (v0374 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v0374 = stack[0];
    v0373 = qcar(v0373);
    fn = elt(env, 2); /* mk_edge_parents */
    v0373 = (*qfn2(fn))(qenv(fn), v0374, v0373);
    nil = C_nil;
    if (exception_pending()) goto v0548;
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
/* error exit handlers */
v0548:
    popv(2);
    return nil;
}



/* Code for actual_arguments */

static Lisp_Object CC_actual_arguments(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0429, v0414, v0430;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for actual_arguments");
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
    v0414 = v0000;
/* end of prologue */
    v0430 = elt(env, 1); /* list */
    v0429 = v0414;
    v0429 = qcdr(v0429);
    if (!(v0429 == nil)) goto v0010;
    v0429 = v0414;
    v0414 = qcar(v0429);
    v0429 = elt(env, 2); /* generic_function */
    v0429 = get(v0414, v0429);
    goto v0010;

v0010:
    return cons(v0430, v0429);
}



setup_type const u41_setup[] =
{
    {"diffp",                   too_few_2,      CC_diffp,      wrong_no_2},
    {"dfdeg",                   too_few_2,      CC_dfdeg,      wrong_no_2},
    {"pasf_premf",              too_few_2,      CC_pasf_premf, wrong_no_2},
    {"fctrf",                   CC_fctrf,       too_many_1,    wrong_no_1},
    {"vsl_boundtype1",          too_few_2,      CC_vsl_boundtype1,wrong_no_2},
    {"gcdld",                   too_few_2,      CC_gcdld,      wrong_no_2},
    {"diford",                  CC_diford,      too_many_1,    wrong_no_1},
    {"copy_vect",               too_few_2,      CC_copy_vect,  wrong_no_2},
    {"vdpcleanup",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_vdpcleanup},
    {"simpwedge",               CC_simpwedge,   too_many_1,    wrong_no_1},
    {"evalmember",              too_few_2,      CC_evalmember, wrong_no_2},
    {"coeff_calc",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_coeff_calc},
    {"lesspcar",                too_few_2,      CC_lesspcar,   wrong_no_2},
    {"mkrootsq",                too_few_2,      CC_mkrootsq,   wrong_no_2},
    {"subtractinds",            wrong_no_na,    wrong_no_nb,   (n_args *)CC_subtractinds},
    {"qqe_simplqneq",           too_few_2,      CC_qqe_simplqneq,wrong_no_2},
    {"pasf_sacat",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_pasf_sacat},
    {"sfto_qsubhor1",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_sfto_qsubhor1},
    {"ps:times-erule",          too_few_2,      CC_psTtimesKerule,wrong_no_2},
    {"dipretimes",              CC_dipretimes,  too_many_1,    wrong_no_1},
    {"remove_least_item",       CC_remove_least_item,too_many_1,wrong_no_1},
    {"gfstorval",               too_few_2,      CC_gfstorval,  wrong_no_2},
    {"mkdmoderr",               too_few_2,      CC_mkdmoderr,  wrong_no_2},
    {"adjp",                    CC_adjp,        too_many_1,    wrong_no_1},
    {"is_buble",                too_few_2,      CC_is_buble,   wrong_no_2},
    {"rfirst",                  CC_rfirst,      too_many_1,    wrong_no_1},
    {"set-weights",             CC_setKweights, too_many_1,    wrong_no_1},
    {"mo_zero?",                CC_mo_zeroW,    too_many_1,    wrong_no_1},
    {"tidysqrtf",               CC_tidysqrtf,   too_many_1,    wrong_no_1},
    {"ra_u",                    CC_ra_u,        too_many_1,    wrong_no_1},
    {"gd_newtype",              too_few_2,      CC_gd_newtype, wrong_no_2},
    {"change+int+to+sq",        CC_changeLintLtoLsq,too_many_1,wrong_no_1},
    {"mri_ofsf2mri",            too_few_2,      CC_mri_ofsf2mri,wrong_no_2},
    {"rnfix*",                  CC_rnfixH,      too_many_1,    wrong_no_1},
    {"simpdf",                  CC_simpdf,      too_many_1,    wrong_no_1},
    {"den",                     CC_den,         too_many_1,    wrong_no_1},
    {"*q2f",                    CC_Hq2f,        too_many_1,    wrong_no_1},
    {"groebinvokecritm",        too_few_2,      CC_groebinvokecritm,wrong_no_2},
    {"weak_xreduce1",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_weak_xreduce1},
    {"mkforttab",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_mkforttab},
    {"physoppri",               CC_physoppri,   too_many_1,    wrong_no_1},
    {"mk_parents_prim",         CC_mk_parents_prim,too_many_1, wrong_no_1},
    {"actual_arguments",        CC_actual_arguments,too_many_1,wrong_no_1},
    {NULL, (one_args *)"u41", (two_args *)"701 5188009 4868516", 0}
};

/* end of generated code */
