
/* $destdir\u44.c        Machine generated C code */

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


/* Code for cl_smsimpl!-junct2 */

static Lisp_Object MS_CDECL CC_cl_smsimplKjunct2(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0023, v0024, v0025, v0026;
    Lisp_Object fn;
    Lisp_Object v0000, v0019, v0020, v0021, v0003, v0022;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 6, "cl_smsimpl-junct2");
    va_start(aa, nargs);
    v0022 = va_arg(aa, Lisp_Object);
    v0003 = va_arg(aa, Lisp_Object);
    v0021 = va_arg(aa, Lisp_Object);
    v0020 = va_arg(aa, Lisp_Object);
    v0019 = va_arg(aa, Lisp_Object);
    v0000 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for cl_smsimpl-junct2");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push6(v0000,v0019,v0020,v0021,v0003,v0022);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop6(v0022,v0003,v0021,v0020,v0019,v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0000;
    v0023 = v0019;
    v0024 = v0020;
    v0025 = v0021;
    stack[-2] = v0003;
    v0026 = v0022;
/* end of prologue */
    fn = elt(env, 7); /* rl_smmkatl */
    v0023 = (*qfnn(fn))(qenv(fn), 4, v0026, v0025, v0024, v0023);
    nil = C_nil;
    if (exception_pending()) goto v0027;
    env = stack[-4];
    stack[-3] = v0023;
    v0024 = stack[-3];
    v0023 = stack[-1];
    if (v0024 == v0023) goto v0028;
    v0023 = qvalue(elt(env, 1)); /* !*rlsichk */
    if (v0023 == nil) goto v0029;
    v0023 = stack[-2];
    v0024 = v0023;
    v0023 = qvalue(elt(env, 2)); /* nil */
    stack[-2] = v0023;
    v0023 = v0024;
    stack[0] = v0023;
    goto v0030;

v0030:
    v0023 = stack[0];
    if (v0023 == nil) goto v0031;
    v0023 = stack[0];
    v0023 = qcar(v0023);
    v0024 = v0023;
    v0023 = stack[-2];
    fn = elt(env, 8); /* lto_insert */
    v0023 = (*qfn2(fn))(qenv(fn), v0024, v0023);
    nil = C_nil;
    if (exception_pending()) goto v0027;
    env = stack[-4];
    stack[-2] = v0023;
    v0023 = stack[0];
    v0023 = qcdr(v0023);
    stack[0] = v0023;
    goto v0030;

v0031:
    v0023 = qvalue(elt(env, 3)); /* !*rlsiso */
    if (v0023 == nil) goto v0032;
    v0024 = stack[-3];
    v0023 = elt(env, 4); /* rl_ordatp */
    fn = elt(env, 9); /* sort */
    v0023 = (*qfn2(fn))(qenv(fn), v0024, v0023);
    nil = C_nil;
    if (exception_pending()) goto v0027;
    env = stack[-4];
    stack[-3] = v0023;
    v0023 = qvalue(elt(env, 5)); /* !*rlsisocx */
    if (v0023 == nil) goto v0032;
    v0024 = stack[-2];
    v0023 = elt(env, 6); /* cl_sordp */
    fn = elt(env, 9); /* sort */
    v0023 = (*qfn2(fn))(qenv(fn), v0024, v0023);
    nil = C_nil;
    if (exception_pending()) goto v0027;
    env = stack[-4];
    stack[-2] = v0023;
    goto v0032;

v0032:
    v0024 = stack[-3];
    v0023 = stack[-2];
    v0023 = Lnconc(nil, v0024, v0023);
    nil = C_nil;
    if (exception_pending()) goto v0027;
    env = stack[-4];
    v0024 = v0023;
    v0023 = v0024;
    if (!(v0023 == nil)) { popv(5); return onevalue(v0024); }
    v0023 = stack[-1];
    fn = elt(env, 10); /* cl_flip */
    v0023 = (*qfn1(fn))(qenv(fn), v0023);
    nil = C_nil;
    if (exception_pending()) goto v0027;
    popv(5);
    return ncons(v0023);

v0029:
    v0023 = stack[-2];
    v0023 = Lnreverse(nil, v0023);
    env = stack[-4];
    stack[-2] = v0023;
    goto v0031;

v0028:
    v0023 = stack[-1];
    popv(5);
    return ncons(v0023);
/* error exit handlers */
v0027:
    popv(5);
    return nil;
}



/* Code for !*rn2rd */

static Lisp_Object CC_Hrn2rd(Lisp_Object env,
                         Lisp_Object v0022)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0004;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for *rn2rd");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0022);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0022);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v0004 = v0022;
/* end of prologue */
    v0004 = qcdr(v0004);
    fn = elt(env, 1); /* r2bf */
    v0004 = (*qfn1(fn))(qenv(fn), v0004);
    nil = C_nil;
    if (exception_pending()) goto v0033;
    env = stack[0];
    fn = elt(env, 2); /* chkrn!* */
    v0004 = (*qfn1(fn))(qenv(fn), v0004);
    nil = C_nil;
    if (exception_pending()) goto v0033;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 3); /* mkround */
        return (*qfn1(fn))(qenv(fn), v0004);
    }
/* error exit handlers */
v0033:
    popv(1);
    return nil;
}



/* Code for ldf!-sep!-var */

static Lisp_Object CC_ldfKsepKvar(Lisp_Object env,
                         Lisp_Object v0022)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0037;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ldf-sep-var");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0022);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0022);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0022;
/* end of prologue */
    v0037 = stack[0];
    fn = elt(env, 1); /* ldf!-pow!-var */
    stack[-1] = (*qfn1(fn))(qenv(fn), v0037);
    nil = C_nil;
    if (exception_pending()) goto v0015;
    env = stack[-2];
    v0037 = stack[0];
    fn = elt(env, 2); /* ldf!-dep!-var */
    v0037 = (*qfn1(fn))(qenv(fn), v0037);
    nil = C_nil;
    if (exception_pending()) goto v0015;
    env = stack[-2];
    fn = elt(env, 3); /* compl */
    stack[-1] = (*qfn2(fn))(qenv(fn), stack[-1], v0037);
    nil = C_nil;
    if (exception_pending()) goto v0015;
    env = stack[-2];
    v0037 = stack[0];
    fn = elt(env, 4); /* ldf!-spf!-var */
    v0037 = (*qfn1(fn))(qenv(fn), v0037);
    nil = C_nil;
    if (exception_pending()) goto v0015;
    env = stack[-2];
    {
        Lisp_Object v0016 = stack[-1];
        popv(3);
        fn = elt(env, 3); /* compl */
        return (*qfn2(fn))(qenv(fn), v0016, v0037);
    }
/* error exit handlers */
v0015:
    popv(3);
    return nil;
}



/* Code for transferrow1 */

static Lisp_Object CC_transferrow1(Lisp_Object env,
                         Lisp_Object v0022)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0044, v0045;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for transferrow1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0022);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0022);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0022;
/* end of prologue */
    stack[-1] = qvalue(elt(env, 1)); /* codmat */
    v0045 = qvalue(elt(env, 2)); /* maxvar */
    v0044 = stack[0];
    v0044 = plus2(v0045, v0044);
    nil = C_nil;
    if (exception_pending()) goto v0011;
    env = stack[-2];
    v0045 = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v0044/(16/CELL)));
    v0044 = (Lisp_Object)81; /* 5 */
    v0044 = *(Lisp_Object *)((char *)v0045 + (CELL-TAG_VECTOR) + ((int32_t)v0044/(16/CELL)));
    if (v0044 == nil) goto v0046;
    v0044 = qvalue(elt(env, 3)); /* nil */
    { popv(3); return onevalue(v0044); }

v0046:
    stack[-1] = qvalue(elt(env, 1)); /* codmat */
    v0045 = qvalue(elt(env, 2)); /* maxvar */
    v0044 = stack[0];
    v0044 = plus2(v0045, v0044);
    nil = C_nil;
    if (exception_pending()) goto v0011;
    v0045 = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v0044/(16/CELL)));
    v0044 = (Lisp_Object)49; /* 3 */
    v0044 = *(Lisp_Object *)((char *)v0045 + (CELL-TAG_VECTOR) + ((int32_t)v0044/(16/CELL)));
    v0044 = (is_number(v0044) ? lisp_true : nil);
    { popv(3); return onevalue(v0044); }
/* error exit handlers */
v0011:
    popv(3);
    return nil;
}



/* Code for fortassign */

static Lisp_Object CC_fortassign(Lisp_Object env,
                         Lisp_Object v0022)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0048, v0036;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for fortassign");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0048 = v0022;
/* end of prologue */
    v0036 = v0048;
    v0036 = qcdr(v0036);
    v0036 = qcar(v0036);
    v0048 = qcdr(v0048);
    v0048 = qcdr(v0048);
    v0048 = qcar(v0048);
    {
        fn = elt(env, 1); /* mkffortassign */
        return (*qfn2(fn))(qenv(fn), v0036, v0048);
    }
}



/* Code for cali_bc_from_a */

static Lisp_Object CC_cali_bc_from_a(Lisp_Object env,
                         Lisp_Object v0022)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0049;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for cali_bc_from_a");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0022);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0022);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v0049 = v0022;
/* end of prologue */
    fn = elt(env, 1); /* simp!* */
    v0049 = (*qfn1(fn))(qenv(fn), v0049);
    nil = C_nil;
    if (exception_pending()) goto v0004;
    env = stack[0];
    v0049 = qcar(v0049);
    {
        popv(1);
        fn = elt(env, 2); /* bc!=simp */
        return (*qfn1(fn))(qenv(fn), v0049);
    }
/* error exit handlers */
v0004:
    popv(1);
    return nil;
}



/* Code for mkindxlist */

static Lisp_Object CC_mkindxlist(Lisp_Object env,
                         Lisp_Object v0022)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0056, v0001;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mkindxlist");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0022);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0022);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    v0056 = v0022;
/* end of prologue */
    stack[-4] = v0056;
    v0056 = stack[-4];
    if (v0056 == nil) goto v0057;
    v0056 = stack[-4];
    v0056 = qcar(v0056);
    v0001 = v0056;
    v0056 = v0001;
    v0056 = integerp(v0056);
    if (v0056 == nil) goto v0017;
    v0056 = v0001;
    fn = elt(env, 3); /* !*num2id */
    v0056 = (*qfn1(fn))(qenv(fn), v0056);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-5];
    goto v0037;

v0037:
    v0056 = ncons(v0056);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-5];
    stack[-2] = v0056;
    stack[-3] = v0056;
    goto v0004;

v0004:
    v0056 = stack[-4];
    v0056 = qcdr(v0056);
    stack[-4] = v0056;
    v0056 = stack[-4];
    if (v0056 == nil) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    stack[-1] = stack[-2];
    v0056 = stack[-4];
    v0056 = qcar(v0056);
    v0001 = v0056;
    v0056 = v0001;
    v0056 = integerp(v0056);
    if (v0056 == nil) goto v0059;
    v0056 = v0001;
    fn = elt(env, 3); /* !*num2id */
    v0056 = (*qfn1(fn))(qenv(fn), v0056);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-5];
    goto v0060;

v0060:
    v0056 = ncons(v0056);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-5];
    v0056 = Lrplacd(nil, stack[-1], v0056);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-5];
    v0056 = stack[-2];
    v0056 = qcdr(v0056);
    stack[-2] = v0056;
    goto v0004;

v0059:
    v0056 = v0001;
    v0056 = Lconsp(nil, v0056);
    env = stack[-5];
    if (v0056 == nil) goto v0061;
    v0056 = v0001;
    v0056 = qcdr(v0056);
    v0056 = qcar(v0056);
    v0056 = integerp(v0056);
    if (v0056 == nil) goto v0061;
    stack[0] = elt(env, 2); /* minus */
    v0056 = v0001;
    v0056 = qcdr(v0056);
    v0056 = qcar(v0056);
    fn = elt(env, 3); /* !*num2id */
    v0056 = (*qfn1(fn))(qenv(fn), v0056);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-5];
    v0056 = list2(stack[0], v0056);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-5];
    goto v0060;

v0061:
    v0056 = v0001;
    goto v0060;

v0017:
    v0056 = v0001;
    v0056 = Lconsp(nil, v0056);
    env = stack[-5];
    if (v0056 == nil) goto v0030;
    v0056 = v0001;
    v0056 = qcdr(v0056);
    v0056 = qcar(v0056);
    v0056 = integerp(v0056);
    if (v0056 == nil) goto v0030;
    stack[0] = elt(env, 2); /* minus */
    v0056 = v0001;
    v0056 = qcdr(v0056);
    v0056 = qcar(v0056);
    fn = elt(env, 3); /* !*num2id */
    v0056 = (*qfn1(fn))(qenv(fn), v0056);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-5];
    v0056 = list2(stack[0], v0056);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-5];
    goto v0037;

v0030:
    v0056 = v0001;
    goto v0037;

v0057:
    v0056 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v0056); }
/* error exit handlers */
v0058:
    popv(6);
    return nil;
}



/* Code for zfactor1 */

static Lisp_Object CC_zfactor1(Lisp_Object env,
                         Lisp_Object v0022, Lisp_Object v0003)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0092, v0093, v0094;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for zfactor1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0003,v0022);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0022,v0003);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-3] = v0003;
    stack[-4] = v0022;
/* end of prologue */
    stack[0] = nil;
    goto v0095;

v0095:
    v0093 = stack[-4];
    v0092 = (Lisp_Object)1; /* 0 */
    v0092 = (Lisp_Object)lessp2(v0093, v0092);
    nil = C_nil;
    if (exception_pending()) goto v0096;
    v0092 = v0092 ? lisp_true : nil;
    env = stack[-6];
    if (v0092 == nil) goto v0014;
    v0094 = (Lisp_Object)-15; /* -1 */
    v0093 = (Lisp_Object)17; /* 1 */
    v0092 = stack[0];
    v0092 = acons(v0094, v0093, v0092);
    nil = C_nil;
    if (exception_pending()) goto v0096;
    env = stack[-6];
    stack[0] = v0092;
    v0092 = stack[-4];
    v0092 = negate(v0092);
    nil = C_nil;
    if (exception_pending()) goto v0096;
    env = stack[-6];
    stack[-4] = v0092;
    goto v0095;

v0014:
    v0093 = stack[-4];
    v0092 = (Lisp_Object)65; /* 4 */
    v0092 = (Lisp_Object)lessp2(v0093, v0092);
    nil = C_nil;
    if (exception_pending()) goto v0096;
    v0092 = v0092 ? lisp_true : nil;
    env = stack[-6];
    if (v0092 == nil) goto v0097;
    v0093 = stack[-4];
    v0092 = (Lisp_Object)17; /* 1 */
    v0092 = cons(v0093, v0092);
    nil = C_nil;
    if (exception_pending()) goto v0096;
    env = stack[-6];
    v0092 = ncons(v0092);
    nil = C_nil;
    if (exception_pending()) goto v0096;
    env = stack[-6];
    {
        Lisp_Object v0098 = stack[0];
        popv(7);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0098, v0092);
    }

v0097:
    stack[-5] = stack[0];
    v0092 = qvalue(elt(env, 1)); /* !*primelist!* */
    stack[-2] = v0092;
    v0092 = qvalue(elt(env, 2)); /* nil */
    stack[-1] = v0092;
    goto v0099;

v0099:
    v0092 = stack[-2];
    if (v0092 == nil) goto v0100;
    v0092 = stack[-2];
    v0092 = qcar(v0092);
    stack[0] = v0092;
    v0092 = stack[-2];
    v0092 = qcdr(v0092);
    stack[-2] = v0092;
    goto v0101;

v0101:
    v0093 = stack[-4];
    v0092 = stack[0];
    v0092 = Ldivide(nil, v0093, v0092);
    nil = C_nil;
    if (exception_pending()) goto v0096;
    env = stack[-6];
    v0094 = v0092;
    v0093 = qcdr(v0092);
    v0092 = (Lisp_Object)1; /* 0 */
    if (v0093 == v0092) goto v0102;
    v0093 = stack[-4];
    v0092 = (Lisp_Object)17; /* 1 */
    if (v0093 == v0092) goto v0103;
    v0093 = stack[0];
    v0092 = stack[0];
    v0093 = times2(v0093, v0092);
    nil = C_nil;
    if (exception_pending()) goto v0096;
    env = stack[-6];
    v0092 = stack[-4];
    v0092 = (Lisp_Object)greaterp2(v0093, v0092);
    nil = C_nil;
    if (exception_pending()) goto v0096;
    v0092 = v0092 ? lisp_true : nil;
    env = stack[-6];
    goto v0104;

v0104:
    if (v0092 == nil) goto v0099;
    v0092 = qvalue(elt(env, 2)); /* nil */
    stack[-2] = v0092;
    v0093 = stack[-4];
    v0092 = stack[-1];
    fn = elt(env, 4); /* add!-factor */
    v0092 = (*qfn2(fn))(qenv(fn), v0093, v0092);
    nil = C_nil;
    if (exception_pending()) goto v0096;
    env = stack[-6];
    stack[-1] = v0092;
    v0092 = (Lisp_Object)17; /* 1 */
    stack[-4] = v0092;
    goto v0099;

v0103:
    v0092 = qvalue(elt(env, 2)); /* nil */
    goto v0104;

v0102:
    v0092 = v0094;
    v0092 = qcar(v0092);
    stack[-4] = v0092;
    v0093 = stack[0];
    v0092 = stack[-1];
    fn = elt(env, 4); /* add!-factor */
    v0092 = (*qfn2(fn))(qenv(fn), v0093, v0092);
    nil = C_nil;
    if (exception_pending()) goto v0096;
    env = stack[-6];
    stack[-1] = v0092;
    goto v0101;

v0100:
    v0093 = stack[-4];
    v0092 = (Lisp_Object)17; /* 1 */
    if (v0093 == v0092) goto v0105;
    v0092 = stack[-3];
    if (v0092 == nil) goto v0106;
    v0093 = stack[-4];
    v0092 = stack[-1];
    fn = elt(env, 5); /* mcfactor!* */
    v0092 = (*qfn2(fn))(qenv(fn), v0093, v0092);
    nil = C_nil;
    if (exception_pending()) goto v0096;
    env = stack[-6];
    goto v0107;

v0107:
    {
        Lisp_Object v0108 = stack[-5];
        popv(7);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0108, v0092);
    }

v0106:
    v0094 = stack[-4];
    v0093 = (Lisp_Object)17; /* 1 */
    v0092 = stack[-1];
    v0092 = acons(v0094, v0093, v0092);
    nil = C_nil;
    if (exception_pending()) goto v0096;
    env = stack[-6];
    goto v0107;

v0105:
    v0092 = stack[-1];
    goto v0107;
/* error exit handlers */
v0096:
    popv(7);
    return nil;
}



/* Code for rd!:prin */

static Lisp_Object CC_rdTprin(Lisp_Object env,
                         Lisp_Object v0022)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0036, v0043;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rd:prin");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0022);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0022);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v0043 = v0022;
/* end of prologue */
    v0036 = v0043;
    v0036 = qcdr(v0036);
    if (!consp(v0036)) goto v0049;
    v0036 = v0043;
    goto v0000;

v0000:
    fn = elt(env, 1); /* bftrim!: */
    v0036 = (*qfn1(fn))(qenv(fn), v0036);
    nil = C_nil;
    if (exception_pending()) goto v0034;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* bfprin!: */
        return (*qfn1(fn))(qenv(fn), v0036);
    }

v0049:
    v0036 = v0043;
    v0036 = qcdr(v0036);
    fn = elt(env, 3); /* fl2bf */
    v0036 = (*qfn1(fn))(qenv(fn), v0036);
    nil = C_nil;
    if (exception_pending()) goto v0034;
    env = stack[0];
    goto v0000;
/* error exit handlers */
v0034:
    popv(1);
    return nil;
}



/* Code for coeffs!-to!-form1 */

static Lisp_Object MS_CDECL CC_coeffsKtoKform1(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0112, v0113, v0107;
    Lisp_Object fn;
    Lisp_Object v0021, v0003, v0022;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "coeffs-to-form1");
    va_start(aa, nargs);
    v0022 = va_arg(aa, Lisp_Object);
    v0003 = va_arg(aa, Lisp_Object);
    v0021 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for coeffs-to-form1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0021,v0003,v0022);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0022,v0003,v0021);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0021;
    stack[-2] = v0003;
    stack[-3] = v0022;
/* end of prologue */
    v0113 = stack[-1];
    v0112 = (Lisp_Object)1; /* 0 */
    v0112 = (Lisp_Object)greaterp2(v0113, v0112);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    v0112 = v0112 ? lisp_true : nil;
    env = stack[-5];
    if (v0112 == nil) goto v0011;
    v0112 = stack[-3];
    stack[-4] = qcdr(v0112);
    stack[0] = stack[-2];
    v0112 = stack[-1];
    v0112 = sub1(v0112);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    env = stack[-5];
    v0112 = CC_coeffsKtoKform1(env, 3, stack[-4], stack[0], v0112);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    env = stack[-5];
    stack[0] = v0112;
    v0112 = stack[-3];
    v0112 = qcar(v0112);
    if (v0112 == nil) { Lisp_Object res = stack[0]; popv(6); return onevalue(res); }
    v0113 = stack[-2];
    v0112 = stack[-1];
    fn = elt(env, 1); /* to */
    v0107 = (*qfn2(fn))(qenv(fn), v0113, v0112);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    v0112 = stack[-3];
    v0113 = qcar(v0112);
    v0112 = stack[0];
    popv(6);
    return acons(v0107, v0113, v0112);

v0011:
    v0112 = stack[-3];
    v0112 = qcar(v0112);
    { popv(6); return onevalue(v0112); }
/* error exit handlers */
v0050:
    popv(6);
    return nil;
}



/* Code for settreset */

static Lisp_Object MS_CDECL CC_settreset(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0049;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "settreset");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for settreset");
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
    v0049 = qvalue(elt(env, 1)); /* nil */
    qvalue(elt(env, 2)) = v0049; /* fluidbibasisjanettreerootnode */
    v0049 = qvalue(elt(env, 1)); /* nil */
    v0049 = ncons(v0049);
    nil = C_nil;
    if (exception_pending()) goto v0004;
    env = stack[0];
    qvalue(elt(env, 3)) = v0049; /* fluidbibasissett */
    v0049 = nil;
    { popv(1); return onevalue(v0049); }
/* error exit handlers */
v0004:
    popv(1);
    return nil;
}



/* Code for repartf */

static Lisp_Object CC_repartf(Lisp_Object env,
                         Lisp_Object v0022)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0121, v0122;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for repartf");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0022);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0022);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0022;
/* end of prologue */
    v0122 = elt(env, 1); /* i */
    v0121 = qvalue(elt(env, 2)); /* kord!* */
    v0121 = cons(v0122, v0121);
    nil = C_nil;
    if (exception_pending()) goto v0123;
    env = stack[-4];
    stack[-3] = qvalue(elt(env, 2)); /* kord!* */
    qvalue(elt(env, 2)) = v0121; /* kord!* */
    v0121 = stack[0];
    fn = elt(env, 5); /* reorder */
    v0121 = (*qfn1(fn))(qenv(fn), v0121);
    nil = C_nil;
    if (exception_pending()) goto v0124;
    env = stack[-4];
    stack[-2] = v0121;
    v0121 = stack[-2];
    if (!consp(v0121)) goto v0037;
    v0121 = stack[-2];
    v0121 = qcar(v0121);
    v0121 = (consp(v0121) ? nil : lisp_true);
    goto v0053;

v0053:
    if (v0121 == nil) goto v0099;
    v0121 = stack[-2];
    if (!consp(v0121)) goto v0125;
    v0121 = stack[-2];
    v0122 = qcar(v0121);
    v0121 = elt(env, 4); /* cmpxfn */
    v0121 = get(v0122, v0121);
    env = stack[-4];
    if (v0121 == nil) goto v0126;
    v0121 = stack[-2];
    stack[-1] = qcar(v0121);
    v0121 = stack[-2];
    v0121 = qcdr(v0121);
    stack[0] = qcar(v0121);
    v0121 = stack[-2];
    v0121 = qcar(v0121);
    if (!symbolp(v0121)) v0122 = nil;
    else { v0122 = qfastgets(v0121);
           if (v0122 != nil) { v0122 = elt(v0122, 34); /* i2d */
#ifdef RECORD_GET
             if (v0122 != SPID_NOPROP)
                record_get(elt(fastget_names, 34), 1);
             else record_get(elt(fastget_names, 34), 0),
                v0122 = nil; }
           else record_get(elt(fastget_names, 34), 0); }
#else
             if (v0122 == SPID_NOPROP) v0122 = nil; }}
#endif
    v0121 = (Lisp_Object)1; /* 0 */
    v0121 = Lapply1(nil, v0122, v0121);
    nil = C_nil;
    if (exception_pending()) goto v0124;
    env = stack[-4];
    v0121 = qcdr(v0121);
    v0121 = qcar(v0121);
    v0121 = list2star(stack[-1], stack[0], v0121);
    nil = C_nil;
    if (exception_pending()) goto v0124;
    env = stack[-4];
    fn = elt(env, 6); /* int!-equiv!-chk */
    v0121 = (*qfn1(fn))(qenv(fn), v0121);
    nil = C_nil;
    if (exception_pending()) goto v0124;
    env = stack[-4];
    goto v0048;

v0048:
    qvalue(elt(env, 2)) = stack[-3]; /* kord!* */
    { popv(5); return onevalue(v0121); }

v0126:
    v0121 = stack[-2];
    goto v0048;

v0125:
    v0121 = stack[-2];
    goto v0048;

v0099:
    v0121 = stack[-2];
    v0121 = qcar(v0121);
    v0121 = qcar(v0121);
    v0122 = qcar(v0121);
    v0121 = elt(env, 1); /* i */
    if (v0122 == v0121) goto v0127;
    v0121 = stack[-2];
    v0121 = qcar(v0121);
    v0122 = qcar(v0121);
    v0121 = (Lisp_Object)17; /* 1 */
    v0121 = cons(v0122, v0121);
    nil = C_nil;
    if (exception_pending()) goto v0124;
    env = stack[-4];
    stack[0] = ncons(v0121);
    nil = C_nil;
    if (exception_pending()) goto v0124;
    env = stack[-4];
    v0121 = stack[-2];
    v0121 = qcar(v0121);
    v0121 = qcdr(v0121);
    v0121 = CC_repartf(env, v0121);
    nil = C_nil;
    if (exception_pending()) goto v0124;
    env = stack[-4];
    fn = elt(env, 7); /* multf */
    stack[0] = (*qfn2(fn))(qenv(fn), stack[0], v0121);
    nil = C_nil;
    if (exception_pending()) goto v0124;
    env = stack[-4];
    v0121 = stack[-2];
    v0121 = qcdr(v0121);
    v0121 = CC_repartf(env, v0121);
    nil = C_nil;
    if (exception_pending()) goto v0124;
    env = stack[-4];
    fn = elt(env, 8); /* addf */
    v0121 = (*qfn2(fn))(qenv(fn), stack[0], v0121);
    nil = C_nil;
    if (exception_pending()) goto v0124;
    env = stack[-4];
    goto v0048;

v0127:
    v0121 = stack[-2];
    v0121 = qcdr(v0121);
    v0121 = CC_repartf(env, v0121);
    nil = C_nil;
    if (exception_pending()) goto v0124;
    env = stack[-4];
    goto v0048;

v0037:
    v0121 = qvalue(elt(env, 3)); /* t */
    goto v0053;
/* error exit handlers */
v0124:
    env = stack[-4];
    qvalue(elt(env, 2)) = stack[-3]; /* kord!* */
    popv(5);
    return nil;
v0123:
    popv(5);
    return nil;
}



/* Code for rl_sacat */

static Lisp_Object MS_CDECL CC_rl_sacat(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0017, v0015, v0016;
    Lisp_Object fn;
    Lisp_Object v0021, v0003, v0022;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "rl_sacat");
    va_start(aa, nargs);
    v0022 = va_arg(aa, Lisp_Object);
    v0003 = va_arg(aa, Lisp_Object);
    v0021 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rl_sacat");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0021,v0003,v0022);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0022,v0003,v0021);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0017 = v0021;
    v0015 = v0003;
    v0016 = v0022;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* rl_sacat!* */
    v0017 = list3(v0016, v0015, v0017);
    nil = C_nil;
    if (exception_pending()) goto v0042;
    env = stack[-1];
    {
        Lisp_Object v0028 = stack[0];
        popv(2);
        fn = elt(env, 2); /* apply */
        return (*qfn2(fn))(qenv(fn), v0028, v0017);
    }
/* error exit handlers */
v0042:
    popv(2);
    return nil;
}



/* Code for cgp_greenp */

static Lisp_Object CC_cgp_greenp(Lisp_Object env,
                         Lisp_Object v0022)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0000;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for cgp_greenp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0022);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0022);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0000 = v0022;
/* end of prologue */
    fn = elt(env, 1); /* cgp_rp */
    v0000 = (*qfn1(fn))(qenv(fn), v0000);
    errexit();
    v0000 = (v0000 == nil ? lisp_true : nil);
    return onevalue(v0000);
}



/* Code for addexptsdf */

static Lisp_Object CC_addexptsdf(Lisp_Object env,
                         Lisp_Object v0022, Lisp_Object v0003)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0009, v0010;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for addexptsdf");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0003,v0022);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0022,v0003);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0003;
    stack[-1] = v0022;
/* end of prologue */
    stack[-2] = nil;
    goto v0049;

v0049:
    v0009 = stack[-1];
    if (v0009 == nil) goto v0120;
    v0009 = stack[0];
    if (v0009 == nil) goto v0013;
    v0009 = stack[-1];
    v0010 = qcar(v0009);
    v0009 = stack[0];
    v0009 = qcar(v0009);
    fn = elt(env, 3); /* exptplus */
    v0010 = (*qfn2(fn))(qenv(fn), v0010, v0009);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    env = stack[-3];
    v0009 = stack[-2];
    v0009 = cons(v0010, v0009);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    env = stack[-3];
    stack[-2] = v0009;
    v0009 = stack[-1];
    v0009 = qcdr(v0009);
    stack[-1] = v0009;
    v0009 = stack[0];
    v0009 = qcdr(v0009);
    stack[0] = v0009;
    goto v0049;

v0013:
    stack[0] = stack[-2];
    v0009 = elt(env, 2); /* "Y too long" */
    fn = elt(env, 4); /* interr */
    v0009 = (*qfn1(fn))(qenv(fn), v0009);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    env = stack[-3];
    {
        Lisp_Object v0060 = stack[0];
        popv(4);
        fn = elt(env, 5); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0060, v0009);
    }

v0120:
    v0009 = stack[0];
    if (v0009 == nil) goto v0035;
    stack[0] = stack[-2];
    v0009 = elt(env, 1); /* "X too long" */
    fn = elt(env, 4); /* interr */
    v0009 = (*qfn1(fn))(qenv(fn), v0009);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    env = stack[-3];
    {
        Lisp_Object v0126 = stack[0];
        popv(4);
        fn = elt(env, 5); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0126, v0009);
    }

v0035:
    v0009 = stack[-2];
    {
        popv(4);
        fn = elt(env, 5); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v0009);
    }
/* error exit handlers */
v0050:
    popv(4);
    return nil;
}



/* Code for crn!:zerop */

static Lisp_Object CC_crnTzerop(Lisp_Object env,
                         Lisp_Object v0022)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0129, v0125, v0130;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for crn:zerop");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0130 = v0022;
/* end of prologue */
    v0129 = v0130;
    v0129 = qcdr(v0129);
    v0129 = qcar(v0129);
    v0125 = qcar(v0129);
    v0129 = (Lisp_Object)1; /* 0 */
    if (v0125 == v0129) goto v0036;
    v0129 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v0129);

v0036:
    v0129 = v0130;
    v0129 = qcdr(v0129);
    v0129 = qcdr(v0129);
    v0125 = qcar(v0129);
    v0129 = (Lisp_Object)1; /* 0 */
    v0129 = (v0125 == v0129 ? lisp_true : nil);
    return onevalue(v0129);
}



/* Code for sprow_dim */

static Lisp_Object CC_sprow_dim(Lisp_Object env,
                         Lisp_Object v0022)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0028;
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
        push(v0022);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0022);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v0022;
/* end of prologue */
    v0028 = qvalue(elt(env, 1)); /* !*fast_la */
    if (v0028 == nil) goto v0057;
    v0028 = qvalue(elt(env, 2)); /* nil */
    goto v0047;

v0047:
    if (v0028 == nil) goto v0049;
    v0028 = elt(env, 3); /* "Error in sprow_dim: input should be a matrix." 
*/
    fn = elt(env, 4); /* rederr */
    v0028 = (*qfn1(fn))(qenv(fn), v0028);
    nil = C_nil;
    if (exception_pending()) goto v0091;
    env = stack[-1];
    goto v0049;

v0049:
    v0028 = stack[0];
    fn = elt(env, 5); /* spmatlength */
    v0028 = (*qfn1(fn))(qenv(fn), v0028);
    nil = C_nil;
    if (exception_pending()) goto v0091;
    v0028 = qcdr(v0028);
    v0028 = qcar(v0028);
    { popv(2); return onevalue(v0028); }

v0057:
    v0028 = stack[0];
    fn = elt(env, 6); /* matrixp */
    v0028 = (*qfn1(fn))(qenv(fn), v0028);
    nil = C_nil;
    if (exception_pending()) goto v0091;
    env = stack[-1];
    v0028 = (v0028 == nil ? lisp_true : nil);
    goto v0047;
/* error exit handlers */
v0091:
    popv(2);
    return nil;
}



/* Code for extbrsea */

static Lisp_Object MS_CDECL CC_extbrsea(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0171, v0172, v0173;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "extbrsea");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for extbrsea");
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
    v0171 = qvalue(elt(env, 1)); /* rowmin */
    stack[-1] = v0171;
    goto v0048;

v0048:
    v0172 = qvalue(elt(env, 2)); /* rowmax */
    v0171 = stack[-1];
    v0171 = difference2(v0172, v0171);
    nil = C_nil;
    if (exception_pending()) goto v0174;
    env = stack[-2];
    v0171 = Lminusp(nil, v0171);
    env = stack[-2];
    if (v0171 == nil) goto v0089;
    fn = elt(env, 8); /* initbrsea */
    v0171 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0174;
    env = stack[-2];
    fn = elt(env, 9); /* extbrsea1 */
    v0171 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0174;
    env = stack[-2];
    goto v0175;

v0175:
    fn = elt(env, 10); /* expandprod */
    v0171 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0174;
    env = stack[-2];
    v0171 = qvalue(elt(env, 1)); /* rowmin */
    stack[-1] = v0171;
    goto v0176;

v0176:
    v0172 = qvalue(elt(env, 2)); /* rowmax */
    v0171 = stack[-1];
    v0171 = difference2(v0172, v0171);
    nil = C_nil;
    if (exception_pending()) goto v0174;
    env = stack[-2];
    v0171 = Lminusp(nil, v0171);
    env = stack[-2];
    if (v0171 == nil) goto v0177;
    fn = elt(env, 8); /* initbrsea */
    v0171 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0174;
    env = stack[-2];
    fn = elt(env, 9); /* extbrsea1 */
    v0171 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0174;
    env = stack[-2];
    fn = elt(env, 11); /* shrinkprod */
    v0171 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0174;
    env = stack[-2];
    if (!(v0171 == nil)) goto v0175;
    v0171 = nil;
    { popv(3); return onevalue(v0171); }

v0177:
    stack[0] = qvalue(elt(env, 4)); /* codmat */
    v0172 = qvalue(elt(env, 5)); /* maxvar */
    v0171 = stack[-1];
    v0171 = plus2(v0172, v0171);
    nil = C_nil;
    if (exception_pending()) goto v0174;
    env = stack[-2];
    v0172 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v0171/(16/CELL)));
    v0171 = (Lisp_Object)49; /* 3 */
    v0172 = *(Lisp_Object *)((char *)v0172 + (CELL-TAG_VECTOR) + ((int32_t)v0171/(16/CELL)));
    v0171 = (Lisp_Object)-15; /* -1 */
    if (v0172 == v0171) goto v0178;
    stack[0] = qvalue(elt(env, 4)); /* codmat */
    v0172 = qvalue(elt(env, 5)); /* maxvar */
    v0171 = stack[-1];
    v0171 = plus2(v0172, v0171);
    nil = C_nil;
    if (exception_pending()) goto v0174;
    env = stack[-2];
    v0172 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v0171/(16/CELL)));
    v0171 = (Lisp_Object)33; /* 2 */
    v0172 = *(Lisp_Object *)((char *)v0172 + (CELL-TAG_VECTOR) + ((int32_t)v0171/(16/CELL)));
    v0171 = elt(env, 7); /* times */
    v0171 = (v0172 == v0171 ? lisp_true : nil);
    goto v0070;

v0070:
    if (v0171 == nil) goto v0179;
    stack[0] = qvalue(elt(env, 4)); /* codmat */
    v0172 = qvalue(elt(env, 5)); /* maxvar */
    v0171 = stack[-1];
    v0171 = plus2(v0172, v0171);
    nil = C_nil;
    if (exception_pending()) goto v0174;
    env = stack[-2];
    v0173 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v0171/(16/CELL)));
    v0172 = (Lisp_Object)1; /* 0 */
    v0171 = qvalue(elt(env, 6)); /* t */
    *(Lisp_Object *)((char *)v0173 + (CELL-TAG_VECTOR) + ((int32_t)v0172/(16/CELL))) = v0171;
    goto v0180;

v0180:
    v0171 = stack[-1];
    v0171 = add1(v0171);
    nil = C_nil;
    if (exception_pending()) goto v0174;
    env = stack[-2];
    stack[-1] = v0171;
    goto v0176;

v0179:
    stack[0] = qvalue(elt(env, 4)); /* codmat */
    v0172 = qvalue(elt(env, 5)); /* maxvar */
    v0171 = stack[-1];
    v0171 = plus2(v0172, v0171);
    nil = C_nil;
    if (exception_pending()) goto v0174;
    env = stack[-2];
    v0173 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v0171/(16/CELL)));
    v0172 = (Lisp_Object)1; /* 0 */
    v0171 = qvalue(elt(env, 3)); /* nil */
    *(Lisp_Object *)((char *)v0173 + (CELL-TAG_VECTOR) + ((int32_t)v0172/(16/CELL))) = v0171;
    goto v0180;

v0178:
    v0171 = qvalue(elt(env, 3)); /* nil */
    goto v0070;

v0089:
    stack[0] = qvalue(elt(env, 4)); /* codmat */
    v0172 = qvalue(elt(env, 5)); /* maxvar */
    v0171 = stack[-1];
    v0171 = plus2(v0172, v0171);
    nil = C_nil;
    if (exception_pending()) goto v0174;
    env = stack[-2];
    v0172 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v0171/(16/CELL)));
    v0171 = (Lisp_Object)49; /* 3 */
    v0172 = *(Lisp_Object *)((char *)v0172 + (CELL-TAG_VECTOR) + ((int32_t)v0171/(16/CELL)));
    v0171 = (Lisp_Object)-15; /* -1 */
    if (v0172 == v0171) goto v0091;
    stack[0] = qvalue(elt(env, 4)); /* codmat */
    v0172 = qvalue(elt(env, 5)); /* maxvar */
    v0171 = stack[-1];
    v0171 = plus2(v0172, v0171);
    nil = C_nil;
    if (exception_pending()) goto v0174;
    env = stack[-2];
    v0172 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v0171/(16/CELL)));
    v0171 = (Lisp_Object)49; /* 3 */
    v0172 = *(Lisp_Object *)((char *)v0172 + (CELL-TAG_VECTOR) + ((int32_t)v0171/(16/CELL)));
    v0171 = (Lisp_Object)-31; /* -2 */
    v0171 = (v0172 == v0171 ? lisp_true : nil);
    goto v0090;

v0090:
    if (v0171 == nil) goto v0027;
    stack[0] = qvalue(elt(env, 4)); /* codmat */
    v0172 = qvalue(elt(env, 5)); /* maxvar */
    v0171 = stack[-1];
    v0171 = plus2(v0172, v0171);
    nil = C_nil;
    if (exception_pending()) goto v0174;
    env = stack[-2];
    v0173 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v0171/(16/CELL)));
    v0172 = (Lisp_Object)1; /* 0 */
    v0171 = qvalue(elt(env, 3)); /* nil */
    *(Lisp_Object *)((char *)v0173 + (CELL-TAG_VECTOR) + ((int32_t)v0172/(16/CELL))) = v0171;
    goto v0016;

v0016:
    v0171 = stack[-1];
    v0171 = add1(v0171);
    nil = C_nil;
    if (exception_pending()) goto v0174;
    env = stack[-2];
    stack[-1] = v0171;
    goto v0048;

v0027:
    stack[0] = qvalue(elt(env, 4)); /* codmat */
    v0172 = qvalue(elt(env, 5)); /* maxvar */
    v0171 = stack[-1];
    v0171 = plus2(v0172, v0171);
    nil = C_nil;
    if (exception_pending()) goto v0174;
    env = stack[-2];
    v0173 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v0171/(16/CELL)));
    v0172 = (Lisp_Object)1; /* 0 */
    v0171 = qvalue(elt(env, 6)); /* t */
    *(Lisp_Object *)((char *)v0173 + (CELL-TAG_VECTOR) + ((int32_t)v0172/(16/CELL))) = v0171;
    goto v0016;

v0091:
    v0171 = qvalue(elt(env, 6)); /* t */
    goto v0090;
/* error exit handlers */
v0174:
    popv(3);
    return nil;
}



/* Code for f2dip2 */

static Lisp_Object MS_CDECL CC_f2dip2(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0169, v0167, v0168, v0182;
    Lisp_Object fn;
    Lisp_Object v0019, v0020, v0021, v0003, v0022;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 5, "f2dip2");
    va_start(aa, nargs);
    v0022 = va_arg(aa, Lisp_Object);
    v0003 = va_arg(aa, Lisp_Object);
    v0021 = va_arg(aa, Lisp_Object);
    v0020 = va_arg(aa, Lisp_Object);
    v0019 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for f2dip2");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push5(v0019,v0020,v0021,v0003,v0022);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v0022,v0003,v0021,v0020,v0019);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0019;
    stack[-1] = v0020;
    stack[-2] = v0021;
    stack[-3] = v0003;
    stack[-4] = v0022;
/* end of prologue */
    v0167 = stack[-4];
    v0169 = qvalue(elt(env, 1)); /* dipvars!* */
    v0169 = Lmemq(nil, v0167, v0169);
    if (v0169 == nil) goto v0130;
    v0182 = stack[-1];
    v0168 = stack[-4];
    v0167 = stack[-3];
    v0169 = qvalue(elt(env, 1)); /* dipvars!* */
    fn = elt(env, 3); /* evinsert */
    v0169 = (*qfnn(fn))(qenv(fn), 4, v0182, v0168, v0167, v0169);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    env = stack[-5];
    goto v0004;

v0004:
    v0167 = v0169;
    v0169 = v0167;
    if (v0169 == nil) goto v0010;
    v0169 = v0167;
    stack[-1] = v0169;
    goto v0099;

v0099:
    v0168 = stack[-2];
    v0167 = stack[-1];
    v0169 = stack[0];
    {
        popv(6);
        fn = elt(env, 4); /* f2dip1 */
        return (*qfnn(fn))(qenv(fn), 3, v0168, v0167, v0169);
    }

v0010:
    v0167 = stack[-4];
    v0169 = stack[-3];
    fn = elt(env, 5); /* to */
    v0167 = (*qfn2(fn))(qenv(fn), v0167, v0169);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    env = stack[-5];
    v0169 = (Lisp_Object)17; /* 1 */
    v0168 = cons(v0167, v0169);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    env = stack[-5];
    v0167 = qvalue(elt(env, 2)); /* nil */
    v0169 = (Lisp_Object)17; /* 1 */
    v0169 = acons(v0168, v0167, v0169);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    env = stack[-5];
    fn = elt(env, 6); /* multsq */
    v0169 = (*qfn2(fn))(qenv(fn), stack[0], v0169);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    env = stack[-5];
    stack[0] = v0169;
    goto v0099;

v0130:
    v0169 = qvalue(elt(env, 2)); /* nil */
    goto v0004;
/* error exit handlers */
v0183:
    popv(6);
    return nil;
}



/* Code for evweightedcomp1 */

static Lisp_Object CC_evweightedcomp1(Lisp_Object env,
                         Lisp_Object v0022, Lisp_Object v0003)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0035, v0048, v0036;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for evweightedcomp1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0035 = v0003;
    v0048 = v0022;
/* end of prologue */
    v0036 = (Lisp_Object)1; /* 0 */
    {
        fn = elt(env, 1); /* evweightedcomp2 */
        return (*qfnn(fn))(qenv(fn), 3, v0036, v0048, v0035);
    }
}



/* Code for redassignp */

static Lisp_Object CC_redassignp(Lisp_Object env,
                         Lisp_Object v0022)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0017, v0015, v0016;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for redassignp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0016 = v0022;
/* end of prologue */
    v0015 = v0016;
    v0017 = elt(env, 1); /* setq */
    if (!consp(v0015)) goto v0053;
    v0015 = qcar(v0015);
    if (!(v0015 == v0017)) goto v0053;
    v0017 = v0016;
    v0017 = qcdr(v0017);
    v0017 = qcdr(v0017);
    v0017 = qcar(v0017);
    {
        fn = elt(env, 3); /* redassign1p */
        return (*qfn1(fn))(qenv(fn), v0017);
    }

v0053:
    v0017 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v0017);
}



/* Code for s_actual_world1 */

static Lisp_Object CC_s_actual_world1(Lisp_Object env,
                         Lisp_Object v0022)
{
    Lisp_Object v0049;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for s_actual_world1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0049 = v0022;
/* end of prologue */
    v0049 = qcar(v0049);
    v0049 = qcar(v0049);
    v0049 = qcar(v0049);
    return onevalue(v0049);
}



/* Code for dp!=comp */

static Lisp_Object CC_dpMcomp(Lisp_Object env,
                         Lisp_Object v0022, Lisp_Object v0003)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0089, v0184;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dp=comp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0003,v0022);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0022,v0003);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0003;
    stack[-1] = v0022;
/* end of prologue */
    stack[-2] = nil;
    goto v0049;

v0049:
    v0089 = stack[0];
    if (v0089 == nil) goto v0120;
    v0089 = stack[0];
    fn = elt(env, 1); /* dp_lmon */
    v0089 = (*qfn1(fn))(qenv(fn), v0089);
    nil = C_nil;
    if (exception_pending()) goto v0040;
    env = stack[-3];
    fn = elt(env, 2); /* mo_comp */
    v0184 = (*qfn1(fn))(qenv(fn), v0089);
    nil = C_nil;
    if (exception_pending()) goto v0040;
    env = stack[-3];
    v0089 = stack[-1];
    v0089 = Leqn(nil, v0184, v0089);
    nil = C_nil;
    if (exception_pending()) goto v0040;
    env = stack[-3];
    if (v0089 == nil) goto v0185;
    v0089 = stack[0];
    v0184 = qcar(v0089);
    v0089 = stack[-2];
    v0089 = cons(v0184, v0089);
    nil = C_nil;
    if (exception_pending()) goto v0040;
    env = stack[-3];
    stack[-2] = v0089;
    v0089 = stack[0];
    v0089 = qcdr(v0089);
    stack[0] = v0089;
    goto v0049;

v0185:
    v0089 = stack[0];
    v0089 = qcdr(v0089);
    stack[0] = v0089;
    goto v0049;

v0120:
    v0089 = stack[-2];
    {
        popv(4);
        fn = elt(env, 3); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v0089);
    }
/* error exit handlers */
v0040:
    popv(4);
    return nil;
}



/* Code for algebnp */

static Lisp_Object CC_algebnp(Lisp_Object env,
                         Lisp_Object v0022)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0012, v0040;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for algebnp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0022);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0022);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v0022;
/* end of prologue */

v0186:
    v0012 = stack[0];
    if (!consp(v0012)) goto v0019;
    v0012 = stack[0];
    v0040 = qcar(v0012);
    v0012 = elt(env, 2); /* !:ar!: */
    if (v0040 == v0012) goto v0033;
    v0012 = stack[0];
    if (!consp(v0012)) goto v0015;
    v0012 = stack[0];
    v0012 = qcar(v0012);
    v0012 = (consp(v0012) ? nil : lisp_true);
    goto v0017;

v0017:
    if (v0012 == nil) goto v0046;
    v0012 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v0012); }

v0046:
    v0012 = stack[0];
    v0012 = qcar(v0012);
    v0012 = qcdr(v0012);
    v0012 = CC_algebnp(env, v0012);
    nil = C_nil;
    if (exception_pending()) goto v0030;
    env = stack[-1];
    if (!(v0012 == nil)) { popv(2); return onevalue(v0012); }
    v0012 = stack[0];
    v0012 = qcdr(v0012);
    stack[0] = v0012;
    goto v0186;

v0015:
    v0012 = qvalue(elt(env, 3)); /* t */
    goto v0017;

v0033:
    v0012 = qvalue(elt(env, 3)); /* t */
    { popv(2); return onevalue(v0012); }

v0019:
    v0012 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v0012); }
/* error exit handlers */
v0030:
    popv(2);
    return nil;
}



/* Code for rl_qe */

static Lisp_Object CC_rl_qe(Lisp_Object env,
                         Lisp_Object v0022, Lisp_Object v0003)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0034, v0053;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rl_qe");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0003,v0022);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0022,v0003);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0034 = v0003;
    v0053 = v0022;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* rl_qe!* */
    v0034 = list2(v0053, v0034);
    nil = C_nil;
    if (exception_pending()) goto v0018;
    env = stack[-1];
    {
        Lisp_Object v0017 = stack[0];
        popv(2);
        fn = elt(env, 2); /* apply */
        return (*qfn2(fn))(qenv(fn), v0017, v0034);
    }
/* error exit handlers */
v0018:
    popv(2);
    return nil;
}



/* Code for ofsf_smdbgetrel */

static Lisp_Object CC_ofsf_smdbgetrel(Lisp_Object env,
                         Lisp_Object v0022, Lisp_Object v0003)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0046, v0013, v0014, v0187;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ofsf_smdbgetrel");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0014 = v0003;
    v0187 = v0022;
/* end of prologue */

v0047:
    v0013 = v0187;
    v0046 = v0014;
    v0046 = qcar(v0046);
    v0046 = qcdr(v0046);
    v0046 = qcdr(v0046);
    if (equal(v0013, v0046)) goto v0033;
    v0046 = v0014;
    v0046 = qcdr(v0046);
    if (v0046 == nil) goto v0129;
    v0046 = v0014;
    v0046 = qcdr(v0046);
    v0014 = v0046;
    goto v0047;

v0129:
    v0046 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v0046);

v0033:
    v0046 = v0014;
    v0046 = qcar(v0046);
    v0046 = qcdr(v0046);
    v0046 = qcar(v0046);
    return onevalue(v0046);
}



/* Code for !*multsq */

static Lisp_Object CC_Hmultsq(Lisp_Object env,
                         Lisp_Object v0022, Lisp_Object v0003)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0197, v0198;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for *multsq");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0003,v0022);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0022,v0003);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v0003;
    stack[-3] = v0022;
/* end of prologue */
    v0197 = stack[-3];
    v0197 = qcar(v0197);
    if (v0197 == nil) goto v0120;
    v0197 = stack[-2];
    v0197 = qcar(v0197);
    v0197 = (v0197 == nil ? lisp_true : nil);
    goto v0033;

v0033:
    if (v0197 == nil) goto v0046;
    v0198 = qvalue(elt(env, 2)); /* nil */
    v0197 = (Lisp_Object)17; /* 1 */
    popv(6);
    return cons(v0198, v0197);

v0046:
    v0197 = stack[-3];
    v0198 = qcdr(v0197);
    v0197 = (Lisp_Object)17; /* 1 */
    if (v0198 == v0197) goto v0089;
    v0197 = qvalue(elt(env, 2)); /* nil */
    goto v0129;

v0129:
    if (v0197 == nil) goto v0170;
    v0197 = stack[-3];
    v0198 = qcar(v0197);
    v0197 = stack[-2];
    v0197 = qcar(v0197);
    fn = elt(env, 3); /* !*multf */
    v0198 = (*qfn2(fn))(qenv(fn), v0198, v0197);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    v0197 = (Lisp_Object)17; /* 1 */
    popv(6);
    return cons(v0198, v0197);

v0170:
    v0197 = stack[-3];
    v0198 = qcar(v0197);
    v0197 = stack[-2];
    v0197 = qcdr(v0197);
    fn = elt(env, 4); /* gcdf */
    v0197 = (*qfn2(fn))(qenv(fn), v0198, v0197);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    env = stack[-5];
    stack[-4] = v0197;
    v0197 = stack[-2];
    v0198 = qcar(v0197);
    v0197 = stack[-3];
    v0197 = qcdr(v0197);
    fn = elt(env, 4); /* gcdf */
    v0197 = (*qfn2(fn))(qenv(fn), v0198, v0197);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    env = stack[-5];
    stack[-1] = v0197;
    v0197 = stack[-3];
    v0198 = qcar(v0197);
    v0197 = stack[-4];
    fn = elt(env, 5); /* quotf */
    stack[0] = (*qfn2(fn))(qenv(fn), v0198, v0197);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    env = stack[-5];
    v0197 = stack[-2];
    v0198 = qcar(v0197);
    v0197 = stack[-1];
    fn = elt(env, 5); /* quotf */
    v0197 = (*qfn2(fn))(qenv(fn), v0198, v0197);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    env = stack[-5];
    fn = elt(env, 3); /* !*multf */
    v0197 = (*qfn2(fn))(qenv(fn), stack[0], v0197);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    env = stack[-5];
    stack[0] = v0197;
    v0197 = stack[-3];
    v0198 = qcdr(v0197);
    v0197 = stack[-1];
    fn = elt(env, 5); /* quotf */
    stack[-1] = (*qfn2(fn))(qenv(fn), v0198, v0197);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    env = stack[-5];
    v0197 = stack[-2];
    v0198 = qcdr(v0197);
    v0197 = stack[-4];
    fn = elt(env, 5); /* quotf */
    v0197 = (*qfn2(fn))(qenv(fn), v0198, v0197);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    env = stack[-5];
    fn = elt(env, 3); /* !*multf */
    v0197 = (*qfn2(fn))(qenv(fn), stack[-1], v0197);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    env = stack[-5];
    stack[-4] = v0197;
    v0197 = stack[-4];
    fn = elt(env, 6); /* minusf */
    v0197 = (*qfn1(fn))(qenv(fn), v0197);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    env = stack[-5];
    if (v0197 == nil) goto v0200;
    v0197 = stack[0];
    fn = elt(env, 7); /* negf */
    v0197 = (*qfn1(fn))(qenv(fn), v0197);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    env = stack[-5];
    stack[0] = v0197;
    v0197 = stack[-4];
    fn = elt(env, 7); /* negf */
    v0197 = (*qfn1(fn))(qenv(fn), v0197);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    env = stack[-5];
    stack[-4] = v0197;
    goto v0200;

v0200:
    v0198 = stack[0];
    v0197 = stack[-4];
    fn = elt(env, 4); /* gcdf */
    v0197 = (*qfn2(fn))(qenv(fn), v0198, v0197);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    env = stack[-5];
    stack[-1] = v0197;
    v0198 = stack[-1];
    v0197 = (Lisp_Object)17; /* 1 */
    if (v0198 == v0197) goto v0201;
    v0198 = stack[0];
    v0197 = stack[-1];
    fn = elt(env, 5); /* quotf */
    stack[0] = (*qfn2(fn))(qenv(fn), v0198, v0197);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    env = stack[-5];
    v0198 = stack[-4];
    v0197 = stack[-1];
    fn = elt(env, 5); /* quotf */
    v0197 = (*qfn2(fn))(qenv(fn), v0198, v0197);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    {
        Lisp_Object v0202 = stack[0];
        popv(6);
        return cons(v0202, v0197);
    }

v0201:
    v0198 = stack[0];
    v0197 = stack[-4];
    popv(6);
    return cons(v0198, v0197);

v0089:
    v0197 = stack[-2];
    v0198 = qcdr(v0197);
    v0197 = (Lisp_Object)17; /* 1 */
    v0197 = (v0198 == v0197 ? lisp_true : nil);
    goto v0129;

v0120:
    v0197 = qvalue(elt(env, 1)); /* t */
    goto v0033;
/* error exit handlers */
v0199:
    popv(6);
    return nil;
}



/* Code for get!-min!-degreelist */

static Lisp_Object CC_getKminKdegreelist(Lisp_Object env,
                         Lisp_Object v0022)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0026, v0080;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for get-min-degreelist");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0022);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0022);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    v0080 = v0022;
/* end of prologue */
    v0026 = v0080;
    if (v0026 == nil) goto v0019;
    v0026 = v0080;
    v0026 = qcdr(v0026);
    if (v0026 == nil) goto v0120;
    v0026 = v0080;
    v0026 = qcar(v0026);
    stack[0] = qcar(v0026);
    v0026 = v0080;
    v0026 = qcdr(v0026);
    v0026 = CC_getKminKdegreelist(env, v0026);
    nil = C_nil;
    if (exception_pending()) goto v0104;
    env = stack[-5];
    {
        Lisp_Object v0194 = stack[0];
        popv(6);
        fn = elt(env, 2); /* taymindegreel */
        return (*qfn2(fn))(qenv(fn), v0194, v0026);
    }

v0120:
    v0026 = v0080;
    v0026 = qcar(v0026);
    v0026 = qcar(v0026);
    stack[-4] = v0026;
    v0026 = stack[-4];
    if (v0026 == nil) goto v0016;
    v0026 = stack[-4];
    v0026 = qcar(v0026);
    stack[0] = v0026;
    v0026 = (Lisp_Object)1; /* 0 */
    v0080 = v0026;
    goto v0187;

v0187:
    v0026 = stack[0];
    if (v0026 == nil) goto v0089;
    v0026 = stack[0];
    v0026 = qcar(v0026);
    fn = elt(env, 3); /* tayexp!-plus2 */
    v0026 = (*qfn2(fn))(qenv(fn), v0026, v0080);
    nil = C_nil;
    if (exception_pending()) goto v0104;
    env = stack[-5];
    v0080 = v0026;
    v0026 = stack[0];
    v0026 = qcdr(v0026);
    stack[0] = v0026;
    goto v0187;

v0089:
    v0026 = v0080;
    v0026 = ncons(v0026);
    nil = C_nil;
    if (exception_pending()) goto v0104;
    env = stack[-5];
    stack[-2] = v0026;
    stack[-3] = v0026;
    goto v0034;

v0034:
    v0026 = stack[-4];
    v0026 = qcdr(v0026);
    stack[-4] = v0026;
    v0026 = stack[-4];
    if (v0026 == nil) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    stack[-1] = stack[-2];
    v0026 = stack[-4];
    v0026 = qcar(v0026);
    stack[0] = v0026;
    v0026 = (Lisp_Object)1; /* 0 */
    v0080 = v0026;
    goto v0204;

v0204:
    v0026 = stack[0];
    if (v0026 == nil) goto v0118;
    v0026 = stack[0];
    v0026 = qcar(v0026);
    fn = elt(env, 3); /* tayexp!-plus2 */
    v0026 = (*qfn2(fn))(qenv(fn), v0026, v0080);
    nil = C_nil;
    if (exception_pending()) goto v0104;
    env = stack[-5];
    v0080 = v0026;
    v0026 = stack[0];
    v0026 = qcdr(v0026);
    stack[0] = v0026;
    goto v0204;

v0118:
    v0026 = v0080;
    v0026 = ncons(v0026);
    nil = C_nil;
    if (exception_pending()) goto v0104;
    env = stack[-5];
    v0026 = Lrplacd(nil, stack[-1], v0026);
    nil = C_nil;
    if (exception_pending()) goto v0104;
    env = stack[-5];
    v0026 = stack[-2];
    v0026 = qcdr(v0026);
    stack[-2] = v0026;
    goto v0034;

v0016:
    v0026 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v0026); }

v0019:
    v0026 = elt(env, 0); /* get!-min!-degreelist */
    {
        popv(6);
        fn = elt(env, 4); /* confusion */
        return (*qfn1(fn))(qenv(fn), v0026);
    }
/* error exit handlers */
v0104:
    popv(6);
    return nil;
}



/* Code for cl_gand!-col */

static Lisp_Object MS_CDECL CC_cl_gandKcol(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0092, v0093, v0094;
    Lisp_Object fn;
    Lisp_Object v0020, v0021, v0003, v0022;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "cl_gand-col");
    va_start(aa, nargs);
    v0022 = va_arg(aa, Lisp_Object);
    v0003 = va_arg(aa, Lisp_Object);
    v0021 = va_arg(aa, Lisp_Object);
    v0020 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for cl_gand-col");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v0020,v0021,v0003,v0022);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0022,v0003,v0021,v0020);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-4] = v0020;
    stack[-5] = v0021;
    stack[-6] = v0003;
    stack[-7] = v0022;
/* end of prologue */
    stack[-8] = nil;
    v0094 = elt(env, 1); /* true */
    v0093 = stack[-5];
    v0092 = elt(env, 2); /* and */
    v0092 = (v0093 == v0092 ? lisp_true : nil);
    fn = elt(env, 5); /* cl_cflip */
    v0092 = (*qfn2(fn))(qenv(fn), v0094, v0092);
    nil = C_nil;
    if (exception_pending()) goto v0210;
    env = stack[-9];
    stack[-3] = v0092;
    v0092 = stack[-3];
    fn = elt(env, 6); /* cl_flip */
    v0092 = (*qfn1(fn))(qenv(fn), v0092);
    nil = C_nil;
    if (exception_pending()) goto v0210;
    env = stack[-9];
    stack[-2] = v0092;
    goto v0129;

v0129:
    v0092 = stack[-7];
    if (v0092 == nil) goto v0091;
    v0092 = stack[-7];
    stack[-1] = qcar(v0092);
    stack[0] = stack[-4];
    v0092 = stack[-6];
    v0093 = sub1(v0092);
    nil = C_nil;
    if (exception_pending()) goto v0210;
    env = stack[-9];
    v0092 = stack[-5];
    fn = elt(env, 7); /* cl_simpl1 */
    v0092 = (*qfnn(fn))(qenv(fn), 4, stack[-1], stack[0], v0093, v0092);
    nil = C_nil;
    if (exception_pending()) goto v0210;
    env = stack[-9];
    v0094 = v0092;
    v0092 = stack[-7];
    v0092 = qcdr(v0092);
    stack[-7] = v0092;
    v0093 = v0094;
    v0092 = stack[-2];
    if (v0093 == v0092) goto v0087;
    v0093 = v0094;
    v0092 = stack[-3];
    if (equal(v0093, v0092)) goto v0129;
    v0092 = v0094;
    if (!consp(v0092)) goto v0168;
    v0092 = v0094;
    v0092 = qcar(v0092);
    v0093 = v0092;
    goto v0007;

v0007:
    v0092 = stack[-5];
    if (v0093 == v0092) goto v0211;
    v0092 = qvalue(elt(env, 4)); /* !*rlsichk */
    if (v0092 == nil) goto v0193;
    v0093 = v0094;
    v0092 = stack[-8];
    v0092 = Lmember(nil, v0093, v0092);
    if (!(v0092 == nil)) goto v0129;

v0193:
    v0093 = v0094;
    v0092 = stack[-8];
    v0092 = cons(v0093, v0092);
    nil = C_nil;
    if (exception_pending()) goto v0210;
    env = stack[-9];
    stack[-8] = v0092;
    goto v0129;

v0211:
    v0092 = qvalue(elt(env, 4)); /* !*rlsichk */
    if (v0092 == nil) goto v0159;
    v0092 = v0094;
    v0092 = qcdr(v0092);
    stack[0] = v0092;
    goto v0002;

v0002:
    v0092 = stack[0];
    if (v0092 == nil) goto v0129;
    v0092 = stack[0];
    v0092 = qcar(v0092);
    v0094 = v0092;
    v0093 = v0094;
    v0092 = stack[-8];
    v0092 = Lmember(nil, v0093, v0092);
    if (!(v0092 == nil)) goto v0026;
    v0093 = v0094;
    v0092 = stack[-8];
    v0092 = cons(v0093, v0092);
    nil = C_nil;
    if (exception_pending()) goto v0210;
    env = stack[-9];
    stack[-8] = v0092;
    goto v0026;

v0026:
    v0092 = stack[0];
    v0092 = qcdr(v0092);
    stack[0] = v0092;
    goto v0002;

v0159:
    v0092 = v0094;
    v0092 = qcdr(v0092);
    stack[0] = v0092;
    goto v0212;

v0212:
    v0092 = stack[0];
    if (v0092 == nil) goto v0129;
    v0092 = stack[0];
    v0092 = qcar(v0092);
    v0093 = v0092;
    v0092 = stack[-8];
    v0092 = cons(v0093, v0092);
    nil = C_nil;
    if (exception_pending()) goto v0210;
    env = stack[-9];
    stack[-8] = v0092;
    v0092 = stack[0];
    v0092 = qcdr(v0092);
    stack[0] = v0092;
    goto v0212;

v0168:
    v0092 = v0094;
    v0093 = v0092;
    goto v0007;

v0087:
    v0092 = stack[-2];
    v0092 = ncons(v0092);
    nil = C_nil;
    if (exception_pending()) goto v0210;
    env = stack[-9];
    stack[-8] = v0092;
    v0092 = qvalue(elt(env, 3)); /* nil */
    stack[-7] = v0092;
    goto v0129;

v0091:
    v0092 = stack[-8];
    if (v0092 == nil) goto v0191;
    v0092 = stack[-8];
        popv(10);
        return Lnreverse(nil, v0092);

v0191:
    v0092 = stack[-3];
    popv(10);
    return ncons(v0092);
/* error exit handlers */
v0210:
    popv(10);
    return nil;
}



/* Code for pasf_negateat */

static Lisp_Object CC_pasf_negateat(Lisp_Object env,
                         Lisp_Object v0022)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0210, v0199, v0202;
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
        push(v0022);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0022);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v0022;
/* end of prologue */
    v0199 = stack[0];
    v0210 = elt(env, 1); /* true */
    if (v0199 == v0210) goto v0033;
    v0199 = stack[0];
    v0210 = elt(env, 3); /* false */
    v0210 = (v0199 == v0210 ? lisp_true : nil);
    goto v0004;

v0004:
    if (v0210 == nil) goto v0011;
    v0199 = stack[0];
    v0210 = elt(env, 3); /* false */
    if (v0199 == v0210) goto v0129;
    v0210 = elt(env, 3); /* false */
    { popv(2); return onevalue(v0210); }

v0129:
    v0210 = elt(env, 1); /* true */
    { popv(2); return onevalue(v0210); }

v0011:
    v0199 = stack[0];
    v0210 = elt(env, 1); /* true */
    if (v0199 == v0210) goto v0086;
    v0199 = stack[0];
    v0210 = elt(env, 3); /* false */
    v0210 = (v0199 == v0210 ? lisp_true : nil);
    goto v0045;

v0045:
    if (v0210 == nil) goto v0109;
    v0210 = stack[0];
    v0199 = v0210;
    goto v0038;

v0038:
    v0210 = elt(env, 4); /* (cong ncong) */
    v0210 = Lmemq(nil, v0199, v0210);
    if (v0210 == nil) goto v0069;
    v0199 = stack[0];
    v0210 = elt(env, 1); /* true */
    if (v0199 == v0210) goto v0164;
    v0199 = stack[0];
    v0210 = elt(env, 3); /* false */
    v0210 = (v0199 == v0210 ? lisp_true : nil);
    goto v0058;

v0058:
    if (v0210 == nil) goto v0082;
    v0210 = stack[0];
    goto v0083;

v0083:
    fn = elt(env, 5); /* pasf_lnegrel */
    v0199 = (*qfn1(fn))(qenv(fn), v0210);
    nil = C_nil;
    if (exception_pending()) goto v0216;
    env = stack[-1];
    v0210 = stack[0];
    v0210 = qcar(v0210);
    v0210 = qcdr(v0210);
    fn = elt(env, 6); /* pasf_mkop */
    v0202 = (*qfn2(fn))(qenv(fn), v0199, v0210);
    nil = C_nil;
    if (exception_pending()) goto v0216;
    v0210 = stack[0];
    v0210 = qcdr(v0210);
    v0199 = qcar(v0210);
    v0210 = stack[0];
    v0210 = qcdr(v0210);
    v0210 = qcdr(v0210);
    v0210 = qcar(v0210);
    popv(2);
    return list3(v0202, v0199, v0210);

v0082:
    v0210 = stack[0];
    v0210 = qcar(v0210);
    v0210 = Lconsp(nil, v0210);
    env = stack[-1];
    if (v0210 == nil) goto v0217;
    v0210 = stack[0];
    v0210 = qcar(v0210);
    v0210 = qcar(v0210);
    goto v0083;

v0217:
    v0210 = stack[0];
    v0210 = qcar(v0210);
    goto v0083;

v0164:
    v0210 = qvalue(elt(env, 2)); /* t */
    goto v0058;

v0069:
    v0199 = stack[0];
    v0210 = elt(env, 1); /* true */
    if (v0199 == v0210) goto v0145;
    v0199 = stack[0];
    v0210 = elt(env, 3); /* false */
    v0210 = (v0199 == v0210 ? lisp_true : nil);
    goto v0218;

v0218:
    if (v0210 == nil) goto v0180;
    v0210 = stack[0];
    goto v0219;

v0219:
    fn = elt(env, 5); /* pasf_lnegrel */
    v0202 = (*qfn1(fn))(qenv(fn), v0210);
    nil = C_nil;
    if (exception_pending()) goto v0216;
    v0210 = stack[0];
    v0210 = qcdr(v0210);
    v0199 = qcar(v0210);
    v0210 = stack[0];
    v0210 = qcdr(v0210);
    v0210 = qcdr(v0210);
    v0210 = qcar(v0210);
    popv(2);
    return list3(v0202, v0199, v0210);

v0180:
    v0210 = stack[0];
    v0210 = qcar(v0210);
    v0210 = Lconsp(nil, v0210);
    env = stack[-1];
    if (v0210 == nil) goto v0093;
    v0210 = stack[0];
    v0210 = qcar(v0210);
    v0210 = qcar(v0210);
    goto v0219;

v0093:
    v0210 = stack[0];
    v0210 = qcar(v0210);
    goto v0219;

v0145:
    v0210 = qvalue(elt(env, 2)); /* t */
    goto v0218;

v0109:
    v0210 = stack[0];
    v0210 = qcar(v0210);
    v0210 = Lconsp(nil, v0210);
    env = stack[-1];
    if (v0210 == nil) goto v0008;
    v0210 = stack[0];
    v0210 = qcar(v0210);
    v0210 = qcar(v0210);
    v0199 = v0210;
    goto v0038;

v0008:
    v0210 = stack[0];
    v0210 = qcar(v0210);
    v0199 = v0210;
    goto v0038;

v0086:
    v0210 = qvalue(elt(env, 2)); /* t */
    goto v0045;

v0033:
    v0210 = qvalue(elt(env, 2)); /* t */
    goto v0004;
/* error exit handlers */
v0216:
    popv(2);
    return nil;
}



/* Code for vdelete */

static Lisp_Object CC_vdelete(Lisp_Object env,
                         Lisp_Object v0022, Lisp_Object v0003)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0030, v0085, v0110;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for vdelete");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0003,v0022);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0022,v0003);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0003;
    stack[-1] = v0022;
/* end of prologue */
    v0110 = nil;
    goto v0049;

v0049:
    v0030 = stack[0];
    if (v0030 == nil) goto v0120;
    v0030 = stack[-1];
    v0085 = qcar(v0030);
    v0030 = stack[0];
    v0030 = qcar(v0030);
    v0030 = qcar(v0030);
    if (equal(v0085, v0030)) goto v0028;
    v0030 = stack[0];
    v0030 = qcar(v0030);
    v0085 = v0110;
    v0030 = cons(v0030, v0085);
    nil = C_nil;
    if (exception_pending()) goto v0109;
    env = stack[-2];
    v0110 = v0030;
    v0030 = stack[0];
    v0030 = qcdr(v0030);
    stack[0] = v0030;
    goto v0049;

v0028:
    v0085 = v0110;
    v0030 = stack[0];
    v0030 = qcdr(v0030);
    {
        popv(3);
        fn = elt(env, 1); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0085, v0030);
    }

v0120:
    v0030 = v0110;
    {
        popv(3);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v0030);
    }
/* error exit handlers */
v0109:
    popv(3);
    return nil;
}



/* Code for groebmakepair */

static Lisp_Object CC_groebmakepair(Lisp_Object env,
                         Lisp_Object v0022, Lisp_Object v0003)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0005, v0006, v0061;
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
        push2(v0003,v0022);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0022,v0003);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v0003;
    stack[-3] = v0022;
/* end of prologue */
    v0005 = stack[-3];
    v0005 = qcdr(v0005);
    v0006 = qcar(v0005);
    v0005 = stack[-2];
    v0005 = qcdr(v0005);
    v0005 = qcar(v0005);
    fn = elt(env, 2); /* vevlcm */
    v0005 = (*qfn2(fn))(qenv(fn), v0006, v0005);
    nil = C_nil;
    if (exception_pending()) goto v0001;
    env = stack[-5];
    stack[-4] = v0005;
    v0005 = qvalue(elt(env, 1)); /* !*gsugar */
    if (v0005 == nil) goto v0169;
    v0005 = stack[-3];
    fn = elt(env, 3); /* gsugar */
    stack[0] = (*qfn1(fn))(qenv(fn), v0005);
    nil = C_nil;
    if (exception_pending()) goto v0001;
    env = stack[-5];
    v0006 = stack[-4];
    v0005 = stack[-3];
    v0005 = qcdr(v0005);
    v0005 = qcar(v0005);
    fn = elt(env, 4); /* vevdif */
    v0005 = (*qfn2(fn))(qenv(fn), v0006, v0005);
    nil = C_nil;
    if (exception_pending()) goto v0001;
    env = stack[-5];
    fn = elt(env, 5); /* vevtdeg */
    v0005 = (*qfn1(fn))(qenv(fn), v0005);
    nil = C_nil;
    if (exception_pending()) goto v0001;
    env = stack[-5];
    v0005 = (Lisp_Object)(int32_t)((int32_t)stack[0] + (int32_t)v0005 - TAG_FIXNUM);
    stack[-1] = v0005;
    v0005 = stack[-2];
    fn = elt(env, 3); /* gsugar */
    stack[0] = (*qfn1(fn))(qenv(fn), v0005);
    nil = C_nil;
    if (exception_pending()) goto v0001;
    env = stack[-5];
    v0006 = stack[-4];
    v0005 = stack[-2];
    v0005 = qcdr(v0005);
    v0005 = qcar(v0005);
    fn = elt(env, 4); /* vevdif */
    v0005 = (*qfn2(fn))(qenv(fn), v0006, v0005);
    nil = C_nil;
    if (exception_pending()) goto v0001;
    env = stack[-5];
    fn = elt(env, 5); /* vevtdeg */
    v0005 = (*qfn1(fn))(qenv(fn), v0005);
    nil = C_nil;
    if (exception_pending()) goto v0001;
    env = stack[-5];
    v0005 = (Lisp_Object)(int32_t)((int32_t)stack[0] + (int32_t)v0005 - TAG_FIXNUM);
    stack[0] = stack[-4];
    v0006 = stack[-1];
    fn = elt(env, 6); /* max */
    v0005 = (*qfn2(fn))(qenv(fn), v0006, v0005);
    nil = C_nil;
    if (exception_pending()) goto v0001;
    {
        Lisp_Object v0002 = stack[0];
        Lisp_Object v0083 = stack[-3];
        Lisp_Object v0081 = stack[-2];
        popv(6);
        return list4(v0002, v0083, v0081, v0005);
    }

v0169:
    v0061 = stack[-4];
    v0006 = stack[-3];
    v0005 = stack[-2];
    popv(6);
    return list3(v0061, v0006, v0005);
/* error exit handlers */
v0001:
    popv(6);
    return nil;
}



/* Code for make_wedge_pair */

static Lisp_Object CC_make_wedge_pair(Lisp_Object env,
                         Lisp_Object v0022, Lisp_Object v0003)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0102, v0222, v0051;
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
        push2(v0003,v0022);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0022,v0003);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0003;
    stack[-2] = v0022;
/* end of prologue */
    v0222 = stack[-2];
    v0102 = stack[-2];
    stack[0] = list2(v0222, v0102);
    nil = C_nil;
    if (exception_pending()) goto v0061;
    env = stack[-4];
    v0102 = stack[-1];
    fn = elt(env, 5); /* xval */
    v0102 = (*qfn1(fn))(qenv(fn), v0102);
    nil = C_nil;
    if (exception_pending()) goto v0061;
    env = stack[-4];
    fn = elt(env, 6); /* xlcm */
    v0102 = (*qfn2(fn))(qenv(fn), stack[0], v0102);
    nil = C_nil;
    if (exception_pending()) goto v0061;
    env = stack[-4];
    stack[-3] = v0102;
    v0102 = qvalue(elt(env, 1)); /* !*twosided */
    if (v0102 == nil) goto v0129;
    v0102 = qvalue(elt(env, 2)); /* xtruncate!* */
    if (!(v0102 == nil)) goto v0129;

v0038:
    v0222 = stack[-2];
    v0102 = stack[-1];
    fn = elt(env, 7); /* overall_factor */
    v0102 = (*qfn2(fn))(qenv(fn), v0222, v0102);
    nil = C_nil;
    if (exception_pending()) goto v0061;
    env = stack[-4];
    if (v0102 == nil) goto v0055;
    v0102 = qvalue(elt(env, 3)); /* nil */
    { popv(5); return onevalue(v0102); }

v0055:
    v0102 = stack[-3];
    fn = elt(env, 8); /* mknwedge */
    v0102 = (*qfn1(fn))(qenv(fn), v0102);
    nil = C_nil;
    if (exception_pending()) goto v0061;
    env = stack[-4];
    fn = elt(env, 9); /* xdegreecheck */
    v0102 = (*qfn1(fn))(qenv(fn), v0102);
    nil = C_nil;
    if (exception_pending()) goto v0061;
    env = stack[-4];
    if (v0102 == nil) goto v0107;
    v0102 = qvalue(elt(env, 3)); /* nil */
    { popv(5); return onevalue(v0102); }

v0107:
    stack[0] = elt(env, 4); /* wedge_pair */
    v0051 = stack[-2];
    v0222 = (Lisp_Object)17; /* 1 */
    v0102 = (Lisp_Object)17; /* 1 */
    v0102 = list2star(v0051, v0222, v0102);
    nil = C_nil;
    if (exception_pending()) goto v0061;
    env = stack[-4];
    v0222 = ncons(v0102);
    nil = C_nil;
    if (exception_pending()) goto v0061;
    v0102 = stack[-1];
    {
        Lisp_Object v0032 = stack[-3];
        Lisp_Object v0101 = stack[0];
        popv(5);
        return list4(v0032, v0101, v0222, v0102);
    }

v0129:
    stack[0] = stack[-2];
    v0102 = stack[-1];
    fn = elt(env, 5); /* xval */
    v0102 = (*qfn1(fn))(qenv(fn), v0102);
    nil = C_nil;
    if (exception_pending()) goto v0061;
    env = stack[-4];
    v0102 = Lmemq(nil, stack[0], v0102);
    if (!(v0102 == nil)) goto v0038;
    v0102 = qvalue(elt(env, 3)); /* nil */
    { popv(5); return onevalue(v0102); }
/* error exit handlers */
v0061:
    popv(5);
    return nil;
}



/* Code for add!-to!-sorted!-tree */

static Lisp_Object CC_addKtoKsortedKtree(Lisp_Object env,
                         Lisp_Object v0022, Lisp_Object v0003)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0082, v0166, v0058;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for add-to-sorted-tree");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0003,v0022);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0022,v0003);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0003;
    stack[-1] = v0022;
/* end of prologue */
    stack[-2] = nil;
    goto v0049;

v0049:
    v0082 = stack[0];
    if (v0082 == nil) goto v0114;
    v0166 = stack[-1];
    v0082 = stack[0];
    v0082 = qcdr(v0082);
    v0082 = qcar(v0082);
    if (equal(v0166, v0082)) goto v0184;
    v0166 = stack[-1];
    v0082 = stack[0];
    v0082 = qcdr(v0082);
    v0082 = qcar(v0082);
    v0082 = Lorderp(nil, v0166, v0082);
    nil = C_nil;
    if (exception_pending()) goto v0115;
    env = stack[-3];
    if (v0082 == nil) goto v0167;
    v0166 = stack[-1];
    v0082 = stack[0];
    v0082 = qcar(v0082);
    v0166 = CC_addKtoKsortedKtree(env, v0166, v0082);
    nil = C_nil;
    if (exception_pending()) goto v0115;
    env = stack[-3];
    v0082 = stack[0];
    v0082 = qcdr(v0082);
    v0082 = cons(v0166, v0082);
    nil = C_nil;
    if (exception_pending()) goto v0115;
    env = stack[-3];
    {
        Lisp_Object v0023 = stack[-2];
        popv(4);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0023, v0082);
    }

v0167:
    v0082 = stack[0];
    v0166 = qcar(v0082);
    v0082 = stack[-2];
    v0082 = cons(v0166, v0082);
    nil = C_nil;
    if (exception_pending()) goto v0115;
    env = stack[-3];
    stack[-2] = v0082;
    v0082 = stack[0];
    v0082 = qcdr(v0082);
    v0166 = qcar(v0082);
    v0082 = stack[-2];
    v0082 = cons(v0166, v0082);
    nil = C_nil;
    if (exception_pending()) goto v0115;
    env = stack[-3];
    stack[-2] = v0082;
    v0082 = stack[0];
    v0082 = qcdr(v0082);
    v0082 = qcdr(v0082);
    stack[0] = v0082;
    goto v0049;

v0184:
    v0166 = stack[-2];
    v0082 = stack[0];
    {
        popv(4);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0166, v0082);
    }

v0114:
    stack[0] = stack[-2];
    v0058 = qvalue(elt(env, 1)); /* nil */
    v0166 = stack[-1];
    v0082 = qvalue(elt(env, 1)); /* nil */
    v0082 = list2star(v0058, v0166, v0082);
    nil = C_nil;
    if (exception_pending()) goto v0115;
    env = stack[-3];
    {
        Lisp_Object v0024 = stack[0];
        popv(4);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0024, v0082);
    }
/* error exit handlers */
v0115:
    popv(4);
    return nil;
}



/* Code for markedvarp */

static Lisp_Object CC_markedvarp(Lisp_Object env,
                         Lisp_Object v0022)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0047, v0057;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for markedvarp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0047 = v0022;
/* end of prologue */
    v0057 = elt(env, 1); /* !*marked!* */
        return Lflagp(nil, v0047, v0057);
}



/* Code for ev!-tades */

static Lisp_Object CC_evKtades(Lisp_Object env,
                         Lisp_Object v0022, Lisp_Object v0003)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0085, v0110, v0111;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ev-tades");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0003,v0022);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0022,v0003);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0003;
    stack[-1] = v0022;
/* end of prologue */
    stack[-2] = nil;
    goto v0049;

v0049:
    v0085 = stack[-1];
    if (v0085 == nil) goto v0114;
    v0111 = qvalue(elt(env, 1)); /* ndim!* */
    v0085 = stack[-1];
    v0110 = qcar(v0085);
    v0085 = stack[0];
    v0085 = Lassoc(nil, v0110, v0085);
    v0085 = qcdr(v0085);
    fn = elt(env, 2); /* binc */
    v0110 = (*qfn2(fn))(qenv(fn), v0111, v0085);
    nil = C_nil;
    if (exception_pending()) goto v0045;
    env = stack[-3];
    v0085 = stack[-2];
    v0085 = cons(v0110, v0085);
    nil = C_nil;
    if (exception_pending()) goto v0045;
    env = stack[-3];
    stack[-2] = v0085;
    v0085 = stack[-1];
    v0085 = qcdr(v0085);
    stack[-1] = v0085;
    goto v0049;

v0114:
    stack[0] = stack[-2];
    v0085 = (Lisp_Object)17; /* 1 */
    v0085 = ncons(v0085);
    nil = C_nil;
    if (exception_pending()) goto v0045;
    env = stack[-3];
    {
        Lisp_Object v0086 = stack[0];
        popv(4);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0086, v0085);
    }
/* error exit handlers */
v0045:
    popv(4);
    return nil;
}



/* Code for reddom_zeros */

static Lisp_Object CC_reddom_zeros(Lisp_Object env,
                         Lisp_Object v0022)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0091, v0129, v0125;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for reddom_zeros");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0022);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0022);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0129 = v0022;
/* end of prologue */

v0019:
    v0091 = v0129;
    if (v0091 == nil) goto v0004;
    v0091 = v0129;
    v0125 = qcar(v0091);
    v0091 = (Lisp_Object)1; /* 0 */
    if (v0125 == v0091) goto v0057;
    v0091 = v0129;
    v0091 = qcdr(v0091);
    v0129 = v0091;
    goto v0019;

v0057:
    v0091 = v0129;
    v0091 = qcdr(v0091);
    v0091 = CC_reddom_zeros(env, v0091);
    errexit();
    return add1(v0091);

v0004:
    v0091 = (Lisp_Object)1; /* 0 */
    return onevalue(v0091);
}



/* Code for dp_2a */

static Lisp_Object CC_dp_2a(Lisp_Object env,
                         Lisp_Object v0022)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0114, v0035;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dp_2a");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0022);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0022);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v0035 = v0022;
/* end of prologue */
    v0114 = v0035;
    if (v0114 == nil) goto v0019;
    v0114 = v0035;
    fn = elt(env, 1); /* dp!=2a */
    v0114 = (*qfn1(fn))(qenv(fn), v0114);
    nil = C_nil;
    if (exception_pending()) goto v0048;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* dp!=replus */
        return (*qfn1(fn))(qenv(fn), v0114);
    }

v0019:
    v0114 = (Lisp_Object)1; /* 0 */
    { popv(1); return onevalue(v0114); }
/* error exit handlers */
v0048:
    popv(1);
    return nil;
}



/* Code for random!-teeny!-prime */

static Lisp_Object CC_randomKteenyKprime(Lisp_Object env,
                         Lisp_Object v0022)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0010, v0084, v0065;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for random-teeny-prime");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0022);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0022);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0022;
/* end of prologue */
    v0084 = stack[0];
    v0010 = elt(env, 1); /* all */
    if (v0084 == v0010) goto v0033;
    v0010 = stack[0];
    v0084 = Llength(nil, v0010);
    nil = C_nil;
    if (exception_pending()) goto v0060;
    env = stack[-2];
    v0010 = (Lisp_Object)161; /* 10 */
    v0010 = (v0084 == v0010 ? lisp_true : nil);
    goto v0004;

v0004:
    if (v0010 == nil) goto v0039;
    v0010 = qvalue(elt(env, 3)); /* nil */
    { popv(3); return onevalue(v0010); }

v0039:
    stack[-1] = qvalue(elt(env, 4)); /* teeny!-primes */
    fn = elt(env, 5); /* next!-random!-number */
    v0084 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0060;
    env = stack[-2];
    v0010 = (Lisp_Object)161; /* 10 */
    v0010 = Cremainder(v0084, v0010);
    nil = C_nil;
    if (exception_pending()) goto v0060;
    env = stack[-2];
    v0010 = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v0010/(16/CELL)));
    v0065 = v0010;
    v0084 = v0065;
    v0010 = stack[0];
    v0010 = Lmember(nil, v0084, v0010);
    if (v0010 == nil) { popv(3); return onevalue(v0065); }
    else goto v0039;

v0033:
    v0010 = qvalue(elt(env, 2)); /* t */
    goto v0004;
/* error exit handlers */
v0060:
    popv(3);
    return nil;
}



/* Code for opfchk!! */

static Lisp_Object CC_opfchkB(Lisp_Object env,
                         Lisp_Object v0022)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0229, v0134;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for opfchk!");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0022);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0022);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-6] = v0022;
/* end of prologue */
    stack[-3] = nil;
    stack[-2] = nil;
    v0229 = stack[-6];
    v0229 = qcar(v0229);
    stack[-7] = v0229;
    stack[-5] = v0229;
    v0229 = stack[-6];
    v0229 = qcdr(v0229);
    stack[-6] = v0229;
    v0134 = stack[-7];
    v0229 = elt(env, 1); /* integer */
    v0229 = Lflagp(nil, v0134, v0229);
    env = stack[-8];
    if (v0229 == nil) goto v0018;
    v0229 = qvalue(elt(env, 2)); /* t */
    stack[-3] = v0229;
    v0134 = stack[-7];
    v0229 = elt(env, 3); /* !:rn!: */
    v0229 = get(v0134, v0229);
    env = stack[-8];
    goto v0053;

v0053:
    stack[-7] = v0229;
    v0229 = stack[-7];
    if (v0229 == nil) goto v0112;
    v0229 = stack[-3];
    if (v0229 == nil) goto v0127;
    v0229 = elt(env, 9); /* simprn */
    goto v0084;

v0084:
    stack[-4] = v0229;
    v0229 = stack[-3];
    if (!(v0229 == nil)) goto v0202;
    v0229 = qvalue(elt(env, 12)); /* !*complex */
    if (v0229 == nil) goto v0202;
    v0229 = stack[-6];
    v0134 = qcar(v0229);
    v0229 = elt(env, 13); /* list */
    if (!consp(v0134)) goto v0052;
    v0134 = qcar(v0134);
    if (!(v0134 == v0229)) goto v0052;
    v0229 = stack[-6];
    v0229 = qcar(v0229);
    v0229 = qcdr(v0229);
    fn = elt(env, 19); /* revlis */
    v0229 = (*qfn1(fn))(qenv(fn), v0229);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    env = stack[-8];
    fn = elt(env, 20); /* simpcr */
    v0229 = (*qfn1(fn))(qenv(fn), v0229);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    env = stack[-8];
    v0134 = v0229;
    if (v0229 == nil) goto v0202;
    v0229 = qvalue(elt(env, 8)); /* nil */
    if (!consp(v0134)) goto v0202;
    v0134 = qcar(v0134);
    if (!(v0134 == v0229)) goto v0202;

v0156:
    stack[-1] = elt(env, 16); /* alg */
    stack[0] = (Lisp_Object)289; /* 18 */
    v0134 = stack[-5];
    v0229 = elt(env, 17); /* "is not defined as complex function" */
    v0229 = list2(v0134, v0229);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    env = stack[-8];
    fn = elt(env, 21); /* rerror */
    v0229 = (*qfnn(fn))(qenv(fn), 3, stack[-1], stack[0], v0229);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    env = stack[-8];
    goto v0202;

v0202:
    stack[0] = stack[-4];
    v0229 = stack[-6];
    fn = elt(env, 19); /* revlis */
    v0229 = (*qfn1(fn))(qenv(fn), v0229);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    env = stack[-8];
    v0229 = Lapply1(nil, stack[0], v0229);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    env = stack[-8];
    stack[-6] = v0229;
    if (!(v0229 == nil)) goto v0146;
    v0229 = qvalue(elt(env, 8)); /* nil */
    { popv(9); return onevalue(v0229); }

v0146:
    stack[0] = elt(env, 18); /* apply */
    v0229 = stack[-7];
    stack[-1] = Lmkquote(nil, v0229);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    env = stack[-8];
    v0229 = stack[-6];
    v0229 = Lmkquote(nil, v0229);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    env = stack[-8];
    v0134 = list3(stack[0], stack[-1], v0229);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    env = stack[-8];
    v0229 = qvalue(elt(env, 8)); /* nil */
    fn = elt(env, 22); /* errorset!* */
    v0229 = (*qfn2(fn))(qenv(fn), v0134, v0229);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    env = stack[-8];
    stack[-6] = v0229;
    v0229 = stack[-6];
    fn = elt(env, 23); /* errorp */
    v0229 = (*qfn1(fn))(qenv(fn), v0229);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    env = stack[-8];
    if (v0229 == nil) goto v0139;
    v0229 = stack[-2];
    if (v0229 == nil) goto v0144;
    v0229 = stack[-2];
    stack[-6] = v0229;
    v0229 = qvalue(elt(env, 8)); /* nil */
    stack[-2] = v0229;
    goto v0230;

v0230:
    v0134 = stack[-5];
    v0229 = elt(env, 15); /* !:cr!: */
    v0229 = get(v0134, v0229);
    env = stack[-8];
    stack[-7] = v0229;
    if (v0229 == nil) goto v0156;
    else goto v0146;

v0144:
    v0229 = qvalue(elt(env, 8)); /* nil */
    { popv(9); return onevalue(v0229); }

v0139:
    v0229 = stack[-3];
    if (v0229 == nil) goto v0179;
    v0229 = stack[-6];
    v0229 = qcar(v0229);
    {
        popv(9);
        fn = elt(env, 24); /* intconv */
        return (*qfn1(fn))(qenv(fn), v0229);
    }

v0179:
    v0229 = stack[-6];
    v0229 = qcar(v0229);
    { popv(9); return onevalue(v0229); }

v0052:
    v0229 = stack[-6];
    fn = elt(env, 19); /* revlis */
    v0229 = (*qfn1(fn))(qenv(fn), v0229);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    env = stack[-8];
    fn = elt(env, 20); /* simpcr */
    v0229 = (*qfn1(fn))(qenv(fn), v0229);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    env = stack[-8];
    stack[-6] = v0229;
    if (v0229 == nil) goto v0161;
    v0134 = stack[-6];
    v0229 = qvalue(elt(env, 8)); /* nil */
    if (!consp(v0134)) goto v0231;
    v0134 = qcar(v0134);
    if (!(v0134 == v0229)) goto v0231;
    v0229 = qvalue(elt(env, 2)); /* t */
    goto v0160;

v0160:
    if (v0229 == nil) goto v0070;
    v0229 = stack[-6];
    v0229 = qcdr(v0229);
    stack[-6] = v0229;
    goto v0230;

v0070:
    v0229 = stack[-6];
    v0229 = qcdr(v0229);
    stack[-2] = v0229;
    v0229 = stack[-6];
    v0229 = qcar(v0229);
    stack[-6] = v0229;
    goto v0202;

v0231:
    v0134 = stack[-5];
    v0229 = elt(env, 14); /* expt */
    if (v0134 == v0229) goto v0232;
    v0229 = qvalue(elt(env, 8)); /* nil */
    goto v0160;

v0232:
    v0229 = stack[-6];
    v0229 = qcar(v0229);
    v0229 = qcar(v0229);
    fn = elt(env, 25); /* rd!:minusp */
    v0229 = (*qfn1(fn))(qenv(fn), v0229);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    env = stack[-8];
    goto v0160;

v0161:
    v0229 = qvalue(elt(env, 8)); /* nil */
    { popv(9); return onevalue(v0229); }

v0127:
    v0134 = stack[-7];
    v0229 = elt(env, 10); /* simparg */
    v0229 = get(v0134, v0229);
    env = stack[-8];
    stack[-4] = v0229;
    if (v0229 == nil) goto v0221;
    v0229 = stack[-4];
    goto v0084;

v0221:
    v0229 = elt(env, 11); /* simprd */
    goto v0084;

v0112:
    v0229 = qvalue(elt(env, 8)); /* nil */
    { popv(9); return onevalue(v0229); }

v0018:
    v0229 = qvalue(elt(env, 4)); /* !*numval */
    if (v0229 == nil) goto v0088;
    v0134 = qvalue(elt(env, 5)); /* dmode!* */
    v0229 = elt(env, 6); /* (!:rd!: !:cr!:) */
    v0229 = Lmemq(nil, v0134, v0229);
    if (v0229 == nil) goto v0088;
    v0134 = stack[-7];
    v0229 = elt(env, 7); /* !:rd!: */
    v0229 = get(v0134, v0229);
    env = stack[-8];
    goto v0053;

v0088:
    v0229 = nil;
    goto v0053;
/* error exit handlers */
v0131:
    popv(9);
    return nil;
}



/* Code for texexplode */

static Lisp_Object CC_texexplode(Lisp_Object env,
                         Lisp_Object v0022)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0181, v0127, v0208;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for texexplode");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0022);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0022);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v0127 = v0022;
/* end of prologue */
    v0181 = v0127;
    if (v0181 == nil) goto v0033;
    v0181 = v0127;
    if (!(!consp(v0181))) goto v0033;
    v0208 = v0127;
    v0181 = elt(env, 1); /* texname */
    v0181 = get(v0208, v0181);
    env = stack[0];
    if (!(v0181 == nil)) goto v0043;
    v0181 = v0127;
    if (!symbolp(v0181)) v0181 = nil;
    else { v0181 = qfastgets(v0181);
           if (v0181 != nil) { v0181 = elt(v0181, 7); /* class */
#ifdef RECORD_GET
             if (v0181 != SPID_NOPROP)
                record_get(elt(fastget_names, 7), 1);
             else record_get(elt(fastget_names, 7), 0),
                v0181 = nil; }
           else record_get(elt(fastget_names, 7), 0); }
#else
             if (v0181 == SPID_NOPROP) v0181 = nil; }}
#endif
    if (v0181 == nil) goto v0091;
    v0181 = v0127;
    goto v0043;

v0043:
    if (!(v0181 == nil)) goto v0049;
    v0181 = v0127;
    if (is_number(v0181)) goto v0031;
    v0181 = v0127;
    v0181 = Lstringp(nil, v0181);
    env = stack[0];
    if (v0181 == nil) goto v0209;
    v0181 = v0127;
    v0181 = Lexplodec(nil, v0181);
    nil = C_nil;
    if (exception_pending()) goto v0099;
    env = stack[0];
    fn = elt(env, 4); /* strcollect */
    v0181 = (*qfn1(fn))(qenv(fn), v0181);
    nil = C_nil;
    if (exception_pending()) goto v0099;
    env = stack[0];
    goto v0049;

v0049:
    v0127 = v0181;
    v0181 = v0127;
    if (v0181 == nil) goto v0128;
    v0181 = v0127;
    if (!(!consp(v0181))) { popv(1); return onevalue(v0127); }
    v0181 = v0127;
    popv(1);
    return ncons(v0181);

v0128:
    v0181 = elt(env, 3); /* !  */
    popv(1);
    return ncons(v0181);

v0209:
    v0181 = v0127;
    v0181 = Lexplodec(nil, v0181);
    nil = C_nil;
    if (exception_pending()) goto v0099;
    env = stack[0];
    fn = elt(env, 5); /* texcollect */
    v0181 = (*qfn1(fn))(qenv(fn), v0181);
    nil = C_nil;
    if (exception_pending()) goto v0099;
    env = stack[0];
    fn = elt(env, 6); /* texexplist */
    v0181 = (*qfn1(fn))(qenv(fn), v0181);
    nil = C_nil;
    if (exception_pending()) goto v0099;
    env = stack[0];
    goto v0049;

v0031:
    v0181 = v0127;
    v0181 = Lexplode(nil, v0181);
    nil = C_nil;
    if (exception_pending()) goto v0099;
    env = stack[0];
    fn = elt(env, 5); /* texcollect */
    v0181 = (*qfn1(fn))(qenv(fn), v0181);
    nil = C_nil;
    if (exception_pending()) goto v0099;
    env = stack[0];
    goto v0049;

v0091:
    v0181 = qvalue(elt(env, 2)); /* nil */
    goto v0043;

v0033:
    v0181 = nil;
    goto v0049;
/* error exit handlers */
v0099:
    popv(1);
    return nil;
}



/* Code for bc_minus!? */

static Lisp_Object CC_bc_minusW(Lisp_Object env,
                         Lisp_Object v0022)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0015, v0016;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for bc_minus?");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0016 = v0022;
/* end of prologue */
    v0015 = v0016;
    v0015 = qcar(v0015);
    v0015 = integerp(v0015);
    if (v0015 == nil) goto v0034;
    v0015 = v0016;
    v0016 = qcar(v0015);
    v0015 = (Lisp_Object)1; /* 0 */
        return Llessp(nil, v0016, v0015);

v0034:
    v0015 = v0016;
    v0015 = qcar(v0015);
    {
        fn = elt(env, 1); /* minusf */
        return (*qfn1(fn))(qenv(fn), v0015);
    }
}



/* Code for init */

static Lisp_Object CC_init(Lisp_Object env,
                         Lisp_Object v0022)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0252, v0253, v0254, v0255;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for init");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0022);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0022);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0022;
/* end of prologue */
    v0252 = qvalue(elt(env, 1)); /* rowmin */
    stack[-2] = v0252;
    goto v0036;

v0036:
    v0253 = qvalue(elt(env, 2)); /* rowmax */
    v0252 = stack[-2];
    v0252 = difference2(v0253, v0252);
    nil = C_nil;
    if (exception_pending()) goto v0256;
    env = stack[-3];
    v0252 = Lminusp(nil, v0252);
    env = stack[-3];
    if (v0252 == nil) goto v0091;
    v0253 = qvalue(elt(env, 5)); /* maxvar */
    v0252 = stack[-1];
    if (equal(v0253, v0252)) goto v0257;
    v0253 = (Lisp_Object)33; /* 2 */
    v0252 = stack[-1];
    v0252 = times2(v0253, v0252);
    nil = C_nil;
    if (exception_pending()) goto v0256;
    env = stack[-3];
    v0252 = Lmkvect(nil, v0252);
    nil = C_nil;
    if (exception_pending()) goto v0256;
    env = stack[-3];
    qvalue(elt(env, 4)) = v0252; /* codmat */
    goto v0201;

v0201:
    v0252 = qvalue(elt(env, 14)); /* kvarlst */
    if (v0252 == nil) goto v0258;
    v0252 = qvalue(elt(env, 14)); /* kvarlst */
    v0255 = v0252;
    goto v0223;

v0223:
    v0252 = v0255;
    if (v0252 == nil) goto v0258;
    v0252 = v0255;
    v0252 = qcar(v0252);
    v0254 = v0252;
    v0252 = v0254;
    v0252 = qcdr(v0252);
    v0253 = qcar(v0252);
    v0252 = elt(env, 14); /* kvarlst */
    v0252 = Lremprop(nil, v0253, v0252);
    env = stack[-3];
    v0252 = v0254;
    v0252 = qcdr(v0252);
    v0253 = qcar(v0252);
    v0252 = elt(env, 11); /* nex */
    v0252 = Lremprop(nil, v0253, v0252);
    env = stack[-3];
    v0252 = v0255;
    v0252 = qcdr(v0252);
    v0255 = v0252;
    goto v0223;

v0258:
    v0252 = elt(env, 19); /* (plus minus difference times expt sqrt) */
    v0254 = v0252;
    goto v0259;

v0259:
    v0252 = v0254;
    if (v0252 == nil) goto v0260;
    v0252 = v0254;
    v0252 = qcar(v0252);
    v0253 = v0252;
    v0252 = elt(env, 14); /* kvarlst */
    v0252 = Lremprop(nil, v0253, v0252);
    env = stack[-3];
    v0252 = v0254;
    v0252 = qcdr(v0252);
    v0254 = v0252;
    goto v0259;

v0260:
    v0252 = qvalue(elt(env, 3)); /* nil */
    qvalue(elt(env, 20)) = v0252; /* avarlst */
    qvalue(elt(env, 21)) = v0252; /* codbexl!* */
    qvalue(elt(env, 14)) = v0252; /* kvarlst */
    qvalue(elt(env, 22)) = v0252; /* prevlst */
    qvalue(elt(env, 8)) = v0252; /* varlst!+ */
    qvalue(elt(env, 9)) = v0252; /* varlst!* */
    v0252 = qvalue(elt(env, 3)); /* nil */
    qvalue(elt(env, 23)) = v0252; /* preprefixlist */
    qvalue(elt(env, 24)) = v0252; /* malst */
    v0252 = qvalue(elt(env, 3)); /* nil */
    qvalue(elt(env, 25)) = v0252; /* prefixlist */
    v0252 = (Lisp_Object)-15; /* -1 */
    qvalue(elt(env, 2)) = v0252; /* rowmax */
    v0252 = stack[-1];
    qvalue(elt(env, 5)) = v0252; /* maxvar */
    v0252 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 1)) = v0252; /* rowmin */
    v0255 = (Lisp_Object)1; /* 0 */
    v0254 = (Lisp_Object)1; /* 0 */
    v0253 = (Lisp_Object)1; /* 0 */
    v0252 = (Lisp_Object)1; /* 0 */
    v0252 = list4(v0255, v0254, v0253, v0252);
    nil = C_nil;
    if (exception_pending()) goto v0256;
    env = stack[-3];
    qvalue(elt(env, 26)) = v0252; /* ops */
    v0252 = nil;
    { popv(4); return onevalue(v0252); }

v0257:
    v0252 = (Lisp_Object)1; /* 0 */
    stack[0] = v0252;
    goto v0094;

v0094:
    v0253 = (Lisp_Object)33; /* 2 */
    v0252 = stack[-1];
    v0253 = times2(v0253, v0252);
    nil = C_nil;
    if (exception_pending()) goto v0256;
    env = stack[-3];
    v0252 = stack[0];
    v0252 = difference2(v0253, v0252);
    nil = C_nil;
    if (exception_pending()) goto v0256;
    env = stack[-3];
    v0252 = Lminusp(nil, v0252);
    env = stack[-3];
    if (!(v0252 == nil)) goto v0201;
    v0254 = qvalue(elt(env, 4)); /* codmat */
    v0253 = stack[0];
    v0252 = qvalue(elt(env, 3)); /* nil */
    *(Lisp_Object *)((char *)v0254 + (CELL-TAG_VECTOR) + ((int32_t)v0253/(16/CELL))) = v0252;
    v0252 = stack[0];
    v0252 = add1(v0252);
    nil = C_nil;
    if (exception_pending()) goto v0256;
    env = stack[-3];
    stack[0] = v0252;
    goto v0094;

v0091:
    stack[0] = qvalue(elt(env, 4)); /* codmat */
    v0253 = qvalue(elt(env, 5)); /* maxvar */
    v0252 = stack[-2];
    v0252 = plus2(v0253, v0252);
    nil = C_nil;
    if (exception_pending()) goto v0256;
    env = stack[-3];
    v0252 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v0252/(16/CELL)));
    if (v0252 == nil) goto v0041;
    stack[0] = qvalue(elt(env, 4)); /* codmat */
    v0253 = qvalue(elt(env, 5)); /* maxvar */
    v0252 = stack[-2];
    v0252 = plus2(v0253, v0252);
    nil = C_nil;
    if (exception_pending()) goto v0256;
    env = stack[-3];
    v0253 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v0252/(16/CELL)));
    v0252 = (Lisp_Object)49; /* 3 */
    v0252 = *(Lisp_Object *)((char *)v0253 + (CELL-TAG_VECTOR) + ((int32_t)v0252/(16/CELL)));
    v0254 = v0252;
    if (is_number(v0252)) goto v0041;
    v0253 = v0254;
    v0252 = elt(env, 6); /* npcdvar */
    v0252 = Lremprop(nil, v0253, v0252);
    env = stack[-3];
    v0253 = v0254;
    v0252 = elt(env, 7); /* nvarlst */
    v0252 = Lremprop(nil, v0253, v0252);
    env = stack[-3];
    v0253 = v0254;
    v0252 = elt(env, 8); /* varlst!+ */
    v0252 = Lremprop(nil, v0253, v0252);
    env = stack[-3];
    v0253 = v0254;
    v0252 = elt(env, 9); /* varlst!* */
    v0252 = Lremprop(nil, v0253, v0252);
    env = stack[-3];
    v0253 = v0254;
    v0252 = elt(env, 10); /* rowindex */
    v0252 = Lremprop(nil, v0253, v0252);
    env = stack[-3];
    v0253 = v0254;
    v0252 = elt(env, 11); /* nex */
    v0252 = Lremprop(nil, v0253, v0252);
    env = stack[-3];
    v0253 = v0254;
    v0252 = elt(env, 12); /* inlhs */
    v0252 = Lremprop(nil, v0253, v0252);
    env = stack[-3];
    v0253 = v0254;
    v0252 = elt(env, 13); /* rowocc */
    v0252 = Lremprop(nil, v0253, v0252);
    env = stack[-3];
    v0253 = v0254;
    v0252 = elt(env, 14); /* kvarlst */
    v0252 = Lremprop(nil, v0253, v0252);
    env = stack[-3];
    v0253 = v0254;
    v0252 = elt(env, 15); /* alias */
    v0252 = Lremprop(nil, v0253, v0252);
    env = stack[-3];
    v0253 = v0254;
    v0252 = elt(env, 16); /* finalalias */
    v0252 = Lremprop(nil, v0253, v0252);
    env = stack[-3];
    v0253 = v0254;
    v0252 = elt(env, 17); /* aliaslist */
    v0252 = Lremprop(nil, v0253, v0252);
    env = stack[-3];
    v0253 = v0254;
    v0252 = elt(env, 18); /* inalias */
    v0252 = Lremprop(nil, v0253, v0252);
    env = stack[-3];
    goto v0041;

v0041:
    v0252 = stack[-2];
    v0252 = add1(v0252);
    nil = C_nil;
    if (exception_pending()) goto v0256;
    env = stack[-3];
    stack[-2] = v0252;
    goto v0036;
/* error exit handlers */
v0256:
    popv(4);
    return nil;
}



/* Code for delete_edge */

static Lisp_Object CC_delete_edge(Lisp_Object env,
                         Lisp_Object v0022, Lisp_Object v0003)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0030, v0085, v0110;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for delete_edge");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0003,v0022);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0022,v0003);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0003;
    stack[-1] = v0022;
/* end of prologue */
    v0110 = nil;
    goto v0049;

v0049:
    v0030 = stack[0];
    if (v0030 == nil) goto v0120;
    v0030 = stack[-1];
    v0085 = qcar(v0030);
    v0030 = stack[0];
    v0030 = qcar(v0030);
    v0030 = qcar(v0030);
    if (v0085 == v0030) goto v0028;
    v0030 = stack[0];
    v0030 = qcar(v0030);
    v0085 = v0110;
    v0030 = cons(v0030, v0085);
    nil = C_nil;
    if (exception_pending()) goto v0109;
    env = stack[-2];
    v0110 = v0030;
    v0030 = stack[0];
    v0030 = qcdr(v0030);
    stack[0] = v0030;
    goto v0049;

v0028:
    v0085 = v0110;
    v0030 = stack[0];
    v0030 = qcdr(v0030);
    {
        popv(3);
        fn = elt(env, 1); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0085, v0030);
    }

v0120:
    v0030 = v0110;
    {
        popv(3);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v0030);
    }
/* error exit handlers */
v0109:
    popv(3);
    return nil;
}



/* Code for hdiff */

static Lisp_Object CC_hdiff(Lisp_Object env,
                         Lisp_Object v0022, Lisp_Object v0003)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0088, v0089;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for hdiff");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0003,v0022);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0022,v0003);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0003;
    stack[-1] = v0022;
/* end of prologue */
    v0088 = stack[-1];
    if (v0088 == nil) goto v0000;
    v0089 = stack[-1];
    v0088 = (Lisp_Object)49; /* 3 */
    v0089 = *(Lisp_Object *)((char *)v0089 + (CELL-TAG_VECTOR) + ((int32_t)v0088/(16/CELL)));
    v0088 = stack[0];
    stack[-2] = CC_hdiff(env, v0089, v0088);
    nil = C_nil;
    if (exception_pending()) goto v0012;
    env = stack[-3];
    v0089 = stack[-1];
    v0088 = stack[0];
    fn = elt(env, 2); /* hdiffterm */
    v0088 = (*qfn2(fn))(qenv(fn), v0089, v0088);
    nil = C_nil;
    if (exception_pending()) goto v0012;
    env = stack[-3];
    {
        Lisp_Object v0040 = stack[-2];
        popv(4);
        fn = elt(env, 3); /* fs!:plus */
        return (*qfn2(fn))(qenv(fn), v0040, v0088);
    }

v0000:
    v0088 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v0088); }
/* error exit handlers */
v0012:
    popv(4);
    return nil;
}



/* Code for difbf */

static Lisp_Object CC_difbf(Lisp_Object env,
                         Lisp_Object v0022, Lisp_Object v0003)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0269, v0143, v0144;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for difbf");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0003,v0022);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0022,v0003);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-6] = v0003;
    stack[-7] = v0022;
/* end of prologue */
    v0269 = stack[-7];
    v0269 = qcdr(v0269);
    v0143 = qcar(v0269);
    stack[-8] = v0143;
    v0269 = (Lisp_Object)1; /* 0 */
    if (v0143 == v0269) goto v0035;
    v0269 = stack[-6];
    v0269 = qcdr(v0269);
    v0143 = qcar(v0269);
    stack[-5] = v0143;
    v0269 = (Lisp_Object)1; /* 0 */
    if (v0143 == v0269) goto v0091;
    v0269 = stack[-7];
    v0269 = qcdr(v0269);
    v0143 = qcdr(v0269);
    stack[-4] = v0143;
    v0269 = stack[-6];
    v0269 = qcdr(v0269);
    v0269 = qcdr(v0269);
    stack[-3] = v0269;
    v0143 = difference2(v0143, v0269);
    nil = C_nil;
    if (exception_pending()) goto v0270;
    env = stack[-9];
    stack[-2] = v0143;
    v0269 = (Lisp_Object)1; /* 0 */
    if (v0143 == v0269) goto v0107;
    stack[-1] = stack[-2];
    v0269 = stack[-8];
    v0269 = Labsval(nil, v0269);
    nil = C_nil;
    if (exception_pending()) goto v0270;
    env = stack[-9];
    fn = elt(env, 3); /* msd */
    stack[0] = (*qfn1(fn))(qenv(fn), v0269);
    nil = C_nil;
    if (exception_pending()) goto v0270;
    env = stack[-9];
    v0269 = stack[-5];
    v0269 = Labsval(nil, v0269);
    nil = C_nil;
    if (exception_pending()) goto v0270;
    env = stack[-9];
    fn = elt(env, 3); /* msd */
    v0269 = (*qfn1(fn))(qenv(fn), v0269);
    nil = C_nil;
    if (exception_pending()) goto v0270;
    env = stack[-9];
    v0269 = difference2(stack[0], v0269);
    nil = C_nil;
    if (exception_pending()) goto v0270;
    env = stack[-9];
    v0269 = plus2(stack[-1], v0269);
    nil = C_nil;
    if (exception_pending()) goto v0270;
    env = stack[-9];
    stack[-1] = v0269;
    v0269 = qvalue(elt(env, 2)); /* !:bprec!: */
    v0269 = add1(v0269);
    nil = C_nil;
    if (exception_pending()) goto v0270;
    env = stack[-9];
    stack[0] = v0269;
    v0143 = stack[-1];
    v0269 = stack[0];
    v0269 = (Lisp_Object)greaterp2(v0143, v0269);
    nil = C_nil;
    if (exception_pending()) goto v0270;
    v0269 = v0269 ? lisp_true : nil;
    env = stack[-9];
    if (v0269 == nil) goto v0121;
    v0269 = stack[-7];
    goto v0057;

v0057:
    stack[-2] = v0269;
    v0269 = stack[-2];
    v0269 = qcdr(v0269);
    v0269 = qcar(v0269);
    v0144 = v0269;
    v0143 = v0144;
    v0269 = (Lisp_Object)1; /* 0 */
    if (v0143 == v0269) goto v0202;
    v0143 = v0144;
    v0269 = qvalue(elt(env, 2)); /* !:bprec!: */
    fn = elt(env, 4); /* inorm */
    v0269 = (*qfn2(fn))(qenv(fn), v0143, v0269);
    nil = C_nil;
    if (exception_pending()) goto v0270;
    env = stack[-9];
    v0144 = v0269;
    stack[-1] = elt(env, 1); /* !:rd!: */
    v0269 = v0144;
    stack[0] = qcar(v0269);
    v0269 = v0144;
    v0143 = qcdr(v0269);
    v0269 = stack[-2];
    v0269 = qcdr(v0269);
    v0269 = qcdr(v0269);
    v0269 = plus2(v0143, v0269);
    nil = C_nil;
    if (exception_pending()) goto v0270;
    {
        Lisp_Object v0271 = stack[-1];
        Lisp_Object v0272 = stack[0];
        popv(10);
        return list2star(v0271, v0272, v0269);
    }

v0202:
    v0144 = elt(env, 1); /* !:rd!: */
    v0143 = (Lisp_Object)1; /* 0 */
    v0269 = (Lisp_Object)1; /* 0 */
    popv(10);
    return list2star(v0144, v0143, v0269);

v0121:
    v0269 = stack[0];
    v0269 = negate(v0269);
    nil = C_nil;
    if (exception_pending()) goto v0270;
    env = stack[-9];
    v0269 = (Lisp_Object)lessp2(stack[-1], v0269);
    nil = C_nil;
    if (exception_pending()) goto v0270;
    v0269 = v0269 ? lisp_true : nil;
    env = stack[-9];
    if (v0269 == nil) goto v0079;
    v0269 = stack[-6];
    fn = elt(env, 5); /* minus!: */
    v0269 = (*qfn1(fn))(qenv(fn), v0269);
    nil = C_nil;
    if (exception_pending()) goto v0270;
    env = stack[-9];
    goto v0057;

v0079:
    v0143 = stack[-2];
    v0269 = (Lisp_Object)1; /* 0 */
    v0269 = (Lisp_Object)greaterp2(v0143, v0269);
    nil = C_nil;
    if (exception_pending()) goto v0270;
    v0269 = v0269 ? lisp_true : nil;
    env = stack[-9];
    if (v0269 == nil) goto v0213;
    stack[0] = elt(env, 1); /* !:rd!: */
    v0143 = stack[-8];
    v0269 = stack[-2];
    fn = elt(env, 6); /* ashift */
    v0143 = (*qfn2(fn))(qenv(fn), v0143, v0269);
    nil = C_nil;
    if (exception_pending()) goto v0270;
    env = stack[-9];
    v0269 = stack[-5];
    v0143 = difference2(v0143, v0269);
    nil = C_nil;
    if (exception_pending()) goto v0270;
    env = stack[-9];
    v0269 = stack[-3];
    v0269 = list2star(stack[0], v0143, v0269);
    nil = C_nil;
    if (exception_pending()) goto v0270;
    env = stack[-9];
    goto v0057;

v0213:
    stack[0] = elt(env, 1); /* !:rd!: */
    stack[-1] = stack[-8];
    stack[-3] = stack[-5];
    v0269 = stack[-2];
    v0269 = negate(v0269);
    nil = C_nil;
    if (exception_pending()) goto v0270;
    env = stack[-9];
    fn = elt(env, 6); /* ashift */
    v0269 = (*qfn2(fn))(qenv(fn), stack[-3], v0269);
    nil = C_nil;
    if (exception_pending()) goto v0270;
    env = stack[-9];
    v0143 = difference2(stack[-1], v0269);
    nil = C_nil;
    if (exception_pending()) goto v0270;
    env = stack[-9];
    v0269 = stack[-4];
    v0269 = list2star(stack[0], v0143, v0269);
    nil = C_nil;
    if (exception_pending()) goto v0270;
    env = stack[-9];
    goto v0057;

v0107:
    stack[0] = elt(env, 1); /* !:rd!: */
    v0143 = stack[-8];
    v0269 = stack[-5];
    v0143 = difference2(v0143, v0269);
    nil = C_nil;
    if (exception_pending()) goto v0270;
    env = stack[-9];
    v0269 = stack[-4];
    v0269 = list2star(stack[0], v0143, v0269);
    nil = C_nil;
    if (exception_pending()) goto v0270;
    env = stack[-9];
    goto v0057;

v0091:
    v0269 = stack[-7];
    goto v0057;

v0035:
    v0269 = stack[-6];
    fn = elt(env, 5); /* minus!: */
    v0269 = (*qfn1(fn))(qenv(fn), v0269);
    nil = C_nil;
    if (exception_pending()) goto v0270;
    env = stack[-9];
    goto v0057;
/* error exit handlers */
v0270:
    popv(10);
    return nil;
}



/* Code for even_action_pow */

static Lisp_Object MS_CDECL CC_even_action_pow(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0157, v0105, v0219, v0100;
    Lisp_Object fn;
    Lisp_Object v0020, v0021, v0003, v0022;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "even_action_pow");
    va_start(aa, nargs);
    v0022 = va_arg(aa, Lisp_Object);
    v0003 = va_arg(aa, Lisp_Object);
    v0021 = va_arg(aa, Lisp_Object);
    v0020 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for even_action_pow");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v0020,v0021,v0003,v0022);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0022,v0003,v0021,v0020);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-2] = v0020;
    stack[-3] = v0021;
    stack[-4] = v0003;
    v0100 = v0022;
/* end of prologue */
    v0157 = stack[-4];
    v0157 = qcar(v0157);
    v0219 = v0157;
    v0157 = stack[-4];
    v0157 = qcdr(v0157);
    stack[-1] = v0157;
    v0105 = v0219;
    v0157 = v0100;
    v0157 = Lassoc(nil, v0105, v0157);
    stack[0] = v0157;
    if (v0157 == nil) goto v0183;
    v0105 = stack[-1];
    v0157 = (Lisp_Object)17; /* 1 */
    if (v0105 == v0157) goto v0089;
    stack[-4] = v0219;
    v0157 = stack[-1];
    v0157 = sub1(v0157);
    nil = C_nil;
    if (exception_pending()) goto v0201;
    env = stack[-6];
    fn = elt(env, 2); /* to */
    v0105 = (*qfn2(fn))(qenv(fn), stack[-4], v0157);
    nil = C_nil;
    if (exception_pending()) goto v0201;
    env = stack[-6];
    v0157 = stack[-1];
    v0219 = cons(v0105, v0157);
    nil = C_nil;
    if (exception_pending()) goto v0201;
    env = stack[-6];
    v0105 = qvalue(elt(env, 1)); /* nil */
    v0157 = (Lisp_Object)17; /* 1 */
    v0157 = acons(v0219, v0105, v0157);
    nil = C_nil;
    if (exception_pending()) goto v0201;
    env = stack[-6];
    goto v0099;

v0099:
    v0219 = stack[0];
    v0105 = stack[-3];
    fn = elt(env, 3); /* component_action */
    v0157 = (*qfnn(fn))(qenv(fn), 3, v0219, v0105, v0157);
    nil = C_nil;
    if (exception_pending()) goto v0201;
    env = stack[-6];
    stack[0] = v0157;
    v0105 = stack[0];
    v0157 = stack[-2];
    {
        popv(7);
        fn = elt(env, 4); /* multsq */
        return (*qfn2(fn))(qenv(fn), v0105, v0157);
    }

v0089:
    v0105 = (Lisp_Object)17; /* 1 */
    v0157 = (Lisp_Object)17; /* 1 */
    v0157 = cons(v0105, v0157);
    nil = C_nil;
    if (exception_pending()) goto v0201;
    env = stack[-6];
    goto v0099;

v0183:
    v0105 = v0219;
    v0219 = v0100;
    v0157 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 5); /* find_active_components */
    v0157 = (*qfnn(fn))(qenv(fn), 3, v0105, v0219, v0157);
    nil = C_nil;
    if (exception_pending()) goto v0201;
    env = stack[-6];
    stack[-1] = v0157;
    v0105 = qvalue(elt(env, 1)); /* nil */
    v0157 = (Lisp_Object)17; /* 1 */
    v0157 = cons(v0105, v0157);
    nil = C_nil;
    if (exception_pending()) goto v0201;
    env = stack[-6];
    stack[0] = v0157;
    v0157 = stack[-1];
    stack[-5] = v0157;
    goto v0024;

v0024:
    v0157 = stack[-5];
    if (v0157 == nil) goto v0274;
    v0157 = stack[-5];
    v0157 = qcar(v0157);
    stack[-1] = v0157;
    v0105 = stack[-4];
    v0157 = stack[-1];
    v0157 = qcar(v0157);
    fn = elt(env, 6); /* diffp */
    v0157 = (*qfn2(fn))(qenv(fn), v0105, v0157);
    nil = C_nil;
    if (exception_pending()) goto v0201;
    env = stack[-6];
    v0219 = stack[-1];
    v0105 = stack[-3];
    fn = elt(env, 3); /* component_action */
    v0157 = (*qfnn(fn))(qenv(fn), 3, v0219, v0105, v0157);
    nil = C_nil;
    if (exception_pending()) goto v0201;
    env = stack[-6];
    fn = elt(env, 7); /* addsq */
    v0157 = (*qfn2(fn))(qenv(fn), stack[0], v0157);
    nil = C_nil;
    if (exception_pending()) goto v0201;
    env = stack[-6];
    stack[0] = v0157;
    v0157 = stack[-5];
    v0157 = qcdr(v0157);
    stack[-5] = v0157;
    goto v0024;

v0274:
    v0105 = stack[0];
    v0157 = stack[-2];
    {
        popv(7);
        fn = elt(env, 4); /* multsq */
        return (*qfn2(fn))(qenv(fn), v0105, v0157);
    }
/* error exit handlers */
v0201:
    popv(7);
    return nil;
}



/* Code for !*invsq */

static Lisp_Object CC_Hinvsq(Lisp_Object env,
                         Lisp_Object v0022)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0035, v0048;
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
        push(v0022);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0022);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v0048 = v0022;
/* end of prologue */
    v0035 = qvalue(elt(env, 1)); /* sqrtflag */
    if (v0035 == nil) goto v0047;
    v0035 = v0048;
    fn = elt(env, 2); /* invsq */
    v0035 = (*qfn1(fn))(qenv(fn), v0035);
    nil = C_nil;
    if (exception_pending()) goto v0036;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 3); /* sqrt2top */
        return (*qfn1(fn))(qenv(fn), v0035);
    }

v0047:
    v0035 = v0048;
    {
        popv(1);
        fn = elt(env, 2); /* invsq */
        return (*qfn1(fn))(qenv(fn), v0035);
    }
/* error exit handlers */
v0036:
    popv(1);
    return nil;
}



/* Code for mk!+inner!+product */

static Lisp_Object CC_mkLinnerLproduct(Lisp_Object env,
                         Lisp_Object v0022, Lisp_Object v0003)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0005, v0006;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mk+inner+product");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0003,v0022);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0022,v0003);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0003;
    stack[-3] = v0022;
/* end of prologue */
    v0005 = stack[-3];
    fn = elt(env, 6); /* get!+vec!+dim */
    stack[0] = (*qfn1(fn))(qenv(fn), v0005);
    nil = C_nil;
    if (exception_pending()) goto v0056;
    env = stack[-5];
    v0005 = stack[-1];
    fn = elt(env, 6); /* get!+vec!+dim */
    v0005 = (*qfn1(fn))(qenv(fn), v0005);
    nil = C_nil;
    if (exception_pending()) goto v0056;
    env = stack[-5];
    if (equal(stack[0], v0005)) goto v0016;
    v0005 = elt(env, 1); /* "Error in Gram_schmidt: each list in input must be the same length." 
*/
    fn = elt(env, 7); /* rederr */
    v0005 = (*qfn1(fn))(qenv(fn), v0005);
    nil = C_nil;
    if (exception_pending()) goto v0056;
    env = stack[-5];
    goto v0016;

v0016:
    v0006 = qvalue(elt(env, 2)); /* nil */
    v0005 = (Lisp_Object)17; /* 1 */
    v0005 = cons(v0006, v0005);
    nil = C_nil;
    if (exception_pending()) goto v0056;
    env = stack[-5];
    stack[0] = v0005;
    v0005 = qvalue(elt(env, 3)); /* !*complex */
    if (v0005 == nil) goto v0039;
    v0005 = stack[-1];
    fn = elt(env, 8); /* mk!+conjugate!+vec */
    v0005 = (*qfn1(fn))(qenv(fn), v0005);
    nil = C_nil;
    if (exception_pending()) goto v0056;
    env = stack[-5];
    stack[-4] = v0005;
    goto v0130;

v0130:
    v0005 = (Lisp_Object)17; /* 1 */
    stack[-2] = v0005;
    goto v0209;

v0209:
    v0005 = stack[-3];
    fn = elt(env, 6); /* get!+vec!+dim */
    v0006 = (*qfn1(fn))(qenv(fn), v0005);
    nil = C_nil;
    if (exception_pending()) goto v0056;
    env = stack[-5];
    v0005 = stack[-2];
    v0005 = difference2(v0006, v0005);
    nil = C_nil;
    if (exception_pending()) goto v0056;
    env = stack[-5];
    v0005 = Lminusp(nil, v0005);
    env = stack[-5];
    if (v0005 == nil) goto v0112;
    v0005 = qvalue(elt(env, 4)); /* t */
    stack[-1] = qvalue(elt(env, 5)); /* !*sub2 */
    qvalue(elt(env, 5)) = v0005; /* !*sub2 */
    v0005 = stack[0];
    fn = elt(env, 9); /* subs2 */
    v0005 = (*qfn1(fn))(qenv(fn), v0005);
    nil = C_nil;
    if (exception_pending()) goto v0001;
    env = stack[-5];
    stack[0] = v0005;
    qvalue(elt(env, 5)) = stack[-1]; /* !*sub2 */
    { Lisp_Object res = stack[0]; popv(6); return onevalue(res); }

v0112:
    stack[-1] = stack[0];
    v0006 = stack[-3];
    v0005 = stack[-2];
    fn = elt(env, 10); /* get!+vec!+entry */
    stack[0] = (*qfn2(fn))(qenv(fn), v0006, v0005);
    nil = C_nil;
    if (exception_pending()) goto v0056;
    env = stack[-5];
    v0006 = stack[-4];
    v0005 = stack[-2];
    fn = elt(env, 10); /* get!+vec!+entry */
    v0005 = (*qfn2(fn))(qenv(fn), v0006, v0005);
    nil = C_nil;
    if (exception_pending()) goto v0056;
    env = stack[-5];
    fn = elt(env, 11); /* multsq */
    v0005 = (*qfn2(fn))(qenv(fn), stack[0], v0005);
    nil = C_nil;
    if (exception_pending()) goto v0056;
    env = stack[-5];
    fn = elt(env, 12); /* addsq */
    v0005 = (*qfn2(fn))(qenv(fn), stack[-1], v0005);
    nil = C_nil;
    if (exception_pending()) goto v0056;
    env = stack[-5];
    stack[0] = v0005;
    v0005 = stack[-2];
    v0005 = add1(v0005);
    nil = C_nil;
    if (exception_pending()) goto v0056;
    env = stack[-5];
    stack[-2] = v0005;
    goto v0209;

v0039:
    v0005 = stack[-1];
    stack[-4] = v0005;
    goto v0130;
/* error exit handlers */
v0001:
    env = stack[-5];
    qvalue(elt(env, 5)) = stack[-1]; /* !*sub2 */
    popv(6);
    return nil;
v0056:
    popv(6);
    return nil;
}



/* Code for pasf_subfof */

static Lisp_Object MS_CDECL CC_pasf_subfof(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0017, v0015, v0016;
    Lisp_Object fn;
    Lisp_Object v0021, v0003, v0022;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "pasf_subfof");
    va_start(aa, nargs);
    v0022 = va_arg(aa, Lisp_Object);
    v0003 = va_arg(aa, Lisp_Object);
    v0021 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pasf_subfof");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0021,v0003,v0022);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0022,v0003,v0021);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    v0017 = v0021;
    v0015 = v0003;
    v0016 = v0022;
/* end of prologue */
    stack[-1] = v0017;
    stack[0] = elt(env, 1); /* pasf_subfof1 */
    v0017 = v0016;
    v0017 = list2(v0017, v0015);
    nil = C_nil;
    if (exception_pending()) goto v0028;
    env = stack[-2];
    {
        Lisp_Object v0090 = stack[-1];
        Lisp_Object v0091 = stack[0];
        popv(3);
        fn = elt(env, 2); /* cl_apply2ats1 */
        return (*qfnn(fn))(qenv(fn), 3, v0090, v0091, v0017);
    }
/* error exit handlers */
v0028:
    popv(3);
    return nil;
}



/* Code for ofsf_boundchk */

static Lisp_Object CC_ofsf_boundchk(Lisp_Object env,
                         Lisp_Object v0022, Lisp_Object v0003)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0157, v0105, v0219;
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
        push2(v0003,v0022);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0022,v0003);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0003;
    stack[-2] = v0022;
/* end of prologue */
    v0157 = stack[-1];
    v0157 = ncons(v0157);
    nil = C_nil;
    if (exception_pending()) goto v0145;
    env = stack[-4];
    fn = elt(env, 9); /* setkorder */
    v0157 = (*qfn1(fn))(qenv(fn), v0157);
    nil = C_nil;
    if (exception_pending()) goto v0145;
    env = stack[-4];
    stack[0] = v0157;
    v0157 = stack[-2];
    v0157 = qcdr(v0157);
    v0157 = qcar(v0157);
    fn = elt(env, 10); /* reorder */
    v0157 = (*qfn1(fn))(qenv(fn), v0157);
    nil = C_nil;
    if (exception_pending()) goto v0145;
    env = stack[-4];
    stack[-3] = v0157;
    v0157 = stack[0];
    fn = elt(env, 9); /* setkorder */
    v0157 = (*qfn1(fn))(qenv(fn), v0157);
    nil = C_nil;
    if (exception_pending()) goto v0145;
    env = stack[-4];
    v0157 = stack[-3];
    if (!consp(v0157)) goto v0090;
    v0157 = stack[-3];
    v0157 = qcar(v0157);
    v0157 = (consp(v0157) ? nil : lisp_true);
    goto v0028;

v0028:
    if (v0157 == nil) goto v0089;
    v0157 = qvalue(elt(env, 1)); /* t */
    goto v0015;

v0015:
    if (v0157 == nil) goto v0086;
    v0157 = qvalue(elt(env, 2)); /* nil */
    { popv(5); return onevalue(v0157); }

v0086:
    v0157 = stack[-3];
    v0157 = qcar(v0157);
    v0157 = qcar(v0157);
    v0105 = qcdr(v0157);
    v0157 = (Lisp_Object)17; /* 1 */
    if (v0105 == v0157) goto v0008;
    v0219 = elt(env, 3); /* "ofsf_boundchk:" */
    v0105 = stack[-1];
    v0157 = elt(env, 4); /* "not linear" */
    v0157 = list3(v0219, v0105, v0157);
    nil = C_nil;
    if (exception_pending()) goto v0145;
    env = stack[-4];
    fn = elt(env, 11); /* rederr */
    v0157 = (*qfn1(fn))(qenv(fn), v0157);
    nil = C_nil;
    if (exception_pending()) goto v0145;
    env = stack[-4];
    goto v0008;

v0008:
    v0157 = stack[-3];
    v0157 = qcdr(v0157);
    fn = elt(env, 10); /* reorder */
    v0157 = (*qfn1(fn))(qenv(fn), v0157);
    nil = C_nil;
    if (exception_pending()) goto v0145;
    env = stack[-4];
    fn = elt(env, 12); /* negf */
    v0105 = (*qfn1(fn))(qenv(fn), v0157);
    nil = C_nil;
    if (exception_pending()) goto v0145;
    env = stack[-4];
    v0157 = (Lisp_Object)17; /* 1 */
    stack[0] = cons(v0105, v0157);
    nil = C_nil;
    if (exception_pending()) goto v0145;
    env = stack[-4];
    v0157 = stack[-3];
    v0157 = qcar(v0157);
    v0157 = qcdr(v0157);
    fn = elt(env, 10); /* reorder */
    v0105 = (*qfn1(fn))(qenv(fn), v0157);
    nil = C_nil;
    if (exception_pending()) goto v0145;
    env = stack[-4];
    v0157 = (Lisp_Object)17; /* 1 */
    v0157 = cons(v0105, v0157);
    nil = C_nil;
    if (exception_pending()) goto v0145;
    env = stack[-4];
    fn = elt(env, 13); /* quotsq */
    v0157 = (*qfn2(fn))(qenv(fn), stack[0], v0157);
    nil = C_nil;
    if (exception_pending()) goto v0145;
    env = stack[-4];
    stack[0] = v0157;
    v0157 = stack[-2];
    v0157 = qcar(v0157);
    v0219 = v0157;
    v0105 = v0219;
    v0157 = elt(env, 5); /* equal */
    if (v0105 == v0157) goto v0080;
    v0105 = v0219;
    v0157 = elt(env, 6); /* geq */
    stack[-1] = (v0105 == v0157 ? lisp_true : nil);
    v0157 = stack[-3];
    v0157 = qcar(v0157);
    v0157 = qcdr(v0157);
    fn = elt(env, 14); /* minusf */
    v0157 = (*qfn1(fn))(qenv(fn), v0157);
    nil = C_nil;
    if (exception_pending()) goto v0145;
    env = stack[-4];
    fn = elt(env, 15); /* ofsf_xor */
    v0157 = (*qfn2(fn))(qenv(fn), stack[-1], v0157);
    nil = C_nil;
    if (exception_pending()) goto v0145;
    env = stack[-4];
    if (v0157 == nil) goto v0274;
    v0105 = elt(env, 7); /* lb */
    v0157 = stack[0];
    popv(5);
    return cons(v0105, v0157);

v0274:
    v0105 = elt(env, 8); /* ub */
    v0157 = stack[0];
    popv(5);
    return cons(v0105, v0157);

v0080:
    v0105 = elt(env, 5); /* equal */
    v0157 = stack[0];
    popv(5);
    return cons(v0105, v0157);

v0089:
    v0157 = stack[-3];
    v0157 = qcar(v0157);
    v0157 = qcar(v0157);
    v0105 = qcar(v0157);
    v0157 = stack[-1];
    v0157 = Lneq(nil, v0105, v0157);
    nil = C_nil;
    if (exception_pending()) goto v0145;
    env = stack[-4];
    goto v0015;

v0090:
    v0157 = qvalue(elt(env, 1)); /* t */
    goto v0028;
/* error exit handlers */
v0145:
    popv(5);
    return nil;
}



/* Code for splitrec */

static Lisp_Object MS_CDECL CC_splitrec(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0230, v0247, v0177, v0068;
    Lisp_Object fn;
    Lisp_Object v0020, v0021, v0003, v0022;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "splitrec");
    va_start(aa, nargs);
    v0022 = va_arg(aa, Lisp_Object);
    v0003 = va_arg(aa, Lisp_Object);
    v0021 = va_arg(aa, Lisp_Object);
    v0020 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for splitrec");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v0020,v0021,v0003,v0022);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0022,v0003,v0021,v0020);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v0020;
    stack[-3] = v0021;
    stack[-4] = v0003;
    stack[-5] = v0022;
/* end of prologue */
    v0230 = stack[-5];
    if (!consp(v0230)) goto v0057;
    v0230 = stack[-5];
    v0230 = qcar(v0230);
    v0230 = (consp(v0230) ? nil : lisp_true);
    goto v0047;

v0047:
    if (v0230 == nil) goto v0008;
    v0247 = stack[-5];
    v0230 = stack[-3];
    fn = elt(env, 4); /* multf */
    v0230 = (*qfn2(fn))(qenv(fn), v0247, v0230);
    nil = C_nil;
    if (exception_pending()) goto v0264;
    env = stack[-7];
    stack[-3] = v0230;
    v0247 = stack[-2];
    v0230 = qvalue(elt(env, 2)); /* list!-pq */
    v0230 = Lassoc(nil, v0247, v0230);
    v0247 = v0230;
    if (v0230 == nil) goto v0112;
    stack[0] = v0247;
    v0230 = v0247;
    v0247 = qcdr(v0230);
    v0230 = stack[-3];
    fn = elt(env, 5); /* addf */
    v0230 = (*qfn2(fn))(qenv(fn), v0247, v0230);
    nil = C_nil;
    if (exception_pending()) goto v0264;
    env = stack[-7];
    v0230 = Lrplacd(nil, stack[0], v0230);
    nil = C_nil;
    if (exception_pending()) goto v0264;
    goto v0130;

v0130:
    v0230 = nil;
    { popv(8); return onevalue(v0230); }

v0112:
    v0177 = stack[-2];
    v0247 = stack[-3];
    v0230 = qvalue(elt(env, 2)); /* list!-pq */
    v0230 = acons(v0177, v0247, v0230);
    nil = C_nil;
    if (exception_pending()) goto v0264;
    env = stack[-7];
    qvalue(elt(env, 2)) = v0230; /* list!-pq */
    goto v0130;

v0008:
    v0230 = stack[-5];
    v0230 = qcar(v0230);
    v0230 = qcar(v0230);
    v0247 = qcar(v0230);
    v0230 = stack[-4];
    if (!consp(v0247)) goto v0083;
    v0247 = qcar(v0247);
    if (!(v0247 == v0230)) goto v0083;
    v0230 = stack[-5];
    v0230 = qcar(v0230);
    v0230 = qcar(v0230);
    v0230 = qcar(v0230);
    v0247 = Llength(nil, v0230);
    nil = C_nil;
    if (exception_pending()) goto v0264;
    env = stack[-7];
    v0230 = (Lisp_Object)33; /* 2 */
    v0230 = (Lisp_Object)greaterp2(v0247, v0230);
    nil = C_nil;
    if (exception_pending()) goto v0264;
    v0230 = v0230 ? lisp_true : nil;
    env = stack[-7];
    goto v0204;

v0204:
    if (v0230 == nil) goto v0158;
    v0230 = stack[-5];
    v0230 = qcar(v0230);
    stack[-6] = qcdr(v0230);
    stack[-1] = stack[-4];
    stack[0] = stack[-3];
    v0230 = stack[-5];
    v0230 = qcar(v0230);
    v0247 = qcar(v0230);
    v0230 = stack[-2];
    v0230 = cons(v0247, v0230);
    nil = C_nil;
    if (exception_pending()) goto v0264;
    env = stack[-7];
    v0230 = CC_splitrec(env, 4, stack[-6], stack[-1], stack[0], v0230);
    nil = C_nil;
    if (exception_pending()) goto v0264;
    env = stack[-7];
    goto v0099;

v0099:
    v0230 = stack[-5];
    v0230 = qcdr(v0230);
    if (v0230 == nil) goto v0062;
    v0230 = stack[-5];
    v0068 = qcdr(v0230);
    v0177 = stack[-4];
    v0247 = stack[-3];
    v0230 = stack[-2];
    v0230 = CC_splitrec(env, 4, v0068, v0177, v0247, v0230);
    nil = C_nil;
    if (exception_pending()) goto v0264;
    goto v0062;

v0062:
    v0230 = nil;
    { popv(8); return onevalue(v0230); }

v0158:
    v0230 = stack[-5];
    v0230 = qcar(v0230);
    stack[-1] = qcdr(v0230);
    stack[0] = stack[-4];
    v0230 = stack[-5];
    v0230 = qcar(v0230);
    v0247 = qcar(v0230);
    v0230 = stack[-3];
    v0230 = cons(v0247, v0230);
    nil = C_nil;
    if (exception_pending()) goto v0264;
    env = stack[-7];
    v0247 = ncons(v0230);
    nil = C_nil;
    if (exception_pending()) goto v0264;
    env = stack[-7];
    v0230 = stack[-2];
    v0230 = CC_splitrec(env, 4, stack[-1], stack[0], v0247, v0230);
    nil = C_nil;
    if (exception_pending()) goto v0264;
    env = stack[-7];
    goto v0099;

v0083:
    v0230 = qvalue(elt(env, 3)); /* nil */
    goto v0204;

v0057:
    v0230 = qvalue(elt(env, 1)); /* t */
    goto v0047;
/* error exit handlers */
v0264:
    popv(8);
    return nil;
}



/* Code for listeq */

static Lisp_Object CC_listeq(Lisp_Object env,
                         Lisp_Object v0022, Lisp_Object v0003)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0040, v0038;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for listeq");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0003,v0022);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0022,v0003);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0003;
    stack[-1] = v0022;
/* end of prologue */

v0000:
    v0040 = stack[-1];
    if (!consp(v0040)) goto v0057;
    v0040 = stack[0];
    if (!consp(v0040)) goto v0053;
    v0040 = stack[-1];
    v0038 = qcar(v0040);
    v0040 = stack[0];
    v0040 = qcar(v0040);
    v0040 = CC_listeq(env, v0038, v0040);
    nil = C_nil;
    if (exception_pending()) goto v0110;
    env = stack[-2];
    if (v0040 == nil) goto v0054;
    v0040 = stack[-1];
    v0040 = qcdr(v0040);
    stack[-1] = v0040;
    v0040 = stack[0];
    v0040 = qcdr(v0040);
    stack[0] = v0040;
    goto v0000;

v0054:
    v0040 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v0040); }

v0053:
    v0040 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v0040); }

v0057:
    v0038 = stack[-1];
    v0040 = stack[0];
    v0040 = (v0038 == v0040 ? lisp_true : nil);
    { popv(3); return onevalue(v0040); }
/* error exit handlers */
v0110:
    popv(3);
    return nil;
}



setup_type const u44_setup[] =
{
    {"cl_smsimpl-junct2",       wrong_no_na,    wrong_no_nb,   (n_args *)CC_cl_smsimplKjunct2},
    {"*rn2rd",                  CC_Hrn2rd,      too_many_1,    wrong_no_1},
    {"ldf-sep-var",             CC_ldfKsepKvar, too_many_1,    wrong_no_1},
    {"transferrow1",            CC_transferrow1,too_many_1,    wrong_no_1},
    {"fortassign",              CC_fortassign,  too_many_1,    wrong_no_1},
    {"cali_bc_from_a",          CC_cali_bc_from_a,too_many_1,  wrong_no_1},
    {"mkindxlist",              CC_mkindxlist,  too_many_1,    wrong_no_1},
    {"zfactor1",                too_few_2,      CC_zfactor1,   wrong_no_2},
    {"rd:prin",                 CC_rdTprin,     too_many_1,    wrong_no_1},
    {"coeffs-to-form1",         wrong_no_na,    wrong_no_nb,   (n_args *)CC_coeffsKtoKform1},
    {"settreset",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_settreset},
    {"repartf",                 CC_repartf,     too_many_1,    wrong_no_1},
    {"rl_sacat",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_rl_sacat},
    {"cgp_greenp",              CC_cgp_greenp,  too_many_1,    wrong_no_1},
    {"addexptsdf",              too_few_2,      CC_addexptsdf, wrong_no_2},
    {"crn:zerop",               CC_crnTzerop,   too_many_1,    wrong_no_1},
    {"sprow_dim",               CC_sprow_dim,   too_many_1,    wrong_no_1},
    {"extbrsea",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_extbrsea},
    {"f2dip2",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_f2dip2},
    {"evweightedcomp1",         too_few_2,      CC_evweightedcomp1,wrong_no_2},
    {"redassignp",              CC_redassignp,  too_many_1,    wrong_no_1},
    {"s_actual_world1",         CC_s_actual_world1,too_many_1, wrong_no_1},
    {"dp=comp",                 too_few_2,      CC_dpMcomp,    wrong_no_2},
    {"algebnp",                 CC_algebnp,     too_many_1,    wrong_no_1},
    {"rl_qe",                   too_few_2,      CC_rl_qe,      wrong_no_2},
    {"ofsf_smdbgetrel",         too_few_2,      CC_ofsf_smdbgetrel,wrong_no_2},
    {"*multsq",                 too_few_2,      CC_Hmultsq,    wrong_no_2},
    {"get-min-degreelist",      CC_getKminKdegreelist,too_many_1,wrong_no_1},
    {"cl_gand-col",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_cl_gandKcol},
    {"pasf_negateat",           CC_pasf_negateat,too_many_1,   wrong_no_1},
    {"vdelete",                 too_few_2,      CC_vdelete,    wrong_no_2},
    {"groebmakepair",           too_few_2,      CC_groebmakepair,wrong_no_2},
    {"make_wedge_pair",         too_few_2,      CC_make_wedge_pair,wrong_no_2},
    {"add-to-sorted-tree",      too_few_2,      CC_addKtoKsortedKtree,wrong_no_2},
    {"markedvarp",              CC_markedvarp,  too_many_1,    wrong_no_1},
    {"ev-tades",                too_few_2,      CC_evKtades,   wrong_no_2},
    {"reddom_zeros",            CC_reddom_zeros,too_many_1,    wrong_no_1},
    {"dp_2a",                   CC_dp_2a,       too_many_1,    wrong_no_1},
    {"random-teeny-prime",      CC_randomKteenyKprime,too_many_1,wrong_no_1},
    {"opfchk!",                 CC_opfchkB,     too_many_1,    wrong_no_1},
    {"texexplode",              CC_texexplode,  too_many_1,    wrong_no_1},
    {"bc_minus?",               CC_bc_minusW,   too_many_1,    wrong_no_1},
    {"init",                    CC_init,        too_many_1,    wrong_no_1},
    {"delete_edge",             too_few_2,      CC_delete_edge,wrong_no_2},
    {"hdiff",                   too_few_2,      CC_hdiff,      wrong_no_2},
    {"difbf",                   too_few_2,      CC_difbf,      wrong_no_2},
    {"even_action_pow",         wrong_no_na,    wrong_no_nb,   (n_args *)CC_even_action_pow},
    {"*invsq",                  CC_Hinvsq,      too_many_1,    wrong_no_1},
    {"mk+inner+product",        too_few_2,      CC_mkLinnerLproduct,wrong_no_2},
    {"pasf_subfof",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_pasf_subfof},
    {"ofsf_boundchk",           too_few_2,      CC_ofsf_boundchk,wrong_no_2},
    {"splitrec",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_splitrec},
    {"listeq",                  too_few_2,      CC_listeq,     wrong_no_2},
    {NULL, (one_args *)"u44", (two_args *)"4437 7855670 2500067", 0}
};

/* end of generated code */
